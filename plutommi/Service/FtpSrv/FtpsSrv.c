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

/******************************************************************************
 * 
 * Filename
 * ---------
 *  FtpsSrv.c
 * 
 * Project:
 * --------
 *  
 * 
 * Description:
 * ------------
 *  This file is for MMI FTP server srvice
 * 
 * Author:
 * -------
 * -------
 * 
 *=============================================================================
 *            HISTORY
 * Below this line,  this part is controlled by PVCS VM. DO NOT MODIFY!!
 *-----------------------------------------------------------------------------
 * $Log$
 *
 * 11 02 2011 zhanying.liu
 * removed!
 * .adjust ftp notify event sequence
 *
 * 10 10 2011 zhanying.liu
 * removed!
 * .adjust notify MMI event sequence
 *
 * 09 25 2011 zhanying.liu
 * removed!
 * .feature set reduction code check in
 *
 * 09 20 2011 zhanying.liu
 * removed!
 * .remove S8 type
 *
 * 05 04 2011 zhanying.liu
 * removed!
 * . deal with the case:stop, then receive the authorize result, just neglect it
 *
 * 04 13 2011 zhanying.liu
 * removed!
 * .update trace
 *
 * 03 04 2011 zhanying.liu
 * removed!
 * . use srv_setting_get_encoding_type() to get encoding type on Cosmos load, language setting change API, but don't notify us
 *
 * 03 02 2011 zhanying.liu
 * removed!
 * .reduce ftp buffer size for slim load
 *
 * 01 06 2011 zhanying.liu
 * removed!
 * .[Slim] systematic memory reduction code check in
 *
 * 12 16 2010 zhanying.liu
 * removed!
 * .update RHR code check in.
 *
 * 12 14 2010 zhanying.liu
 * removed!
 * .update RHR add files
 *
 * 12 14 2010 zhanying.liu
 * removed!
 * .MAUI RHR code check in
 *
 * 12 10 2010 zhanying.liu
 * removed!
 * .move ftp client buffer to ftp client service
 *
 * 12 08 2010 zhanying.liu
 * removed!
 * .update FTP server trace
 *
 * 11 27 2010 zhanying.liu
 * removed!
 * .add srv_ftps_set_permission() in FTP service
 *
 * 11 24 2010 zhanying.liu
 * removed!
 * .remove receive disable judgement to MMI
 *
 * 11 23 2010 zhanying.liu
 * removed!
 * .BT CM revise code check in
 *
 * 10 27 2010 zhanying.liu
 * removed!
 * .Modify send primitive API for shrink ROM size
 *
 * 08 24 2010 zhanying.liu
 * removed!
 * . allow the folder length reaching maximum value 255
 *
 * 08 10 2010 zhanying.liu
 * removed!
 * .remove the assert
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 * 
 *-----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *=============================================================================
 ******************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_FTS_SUPPORT__
//#include "MMI_include.h"
//#include "Fmt_struct.h"
//#include "ExtDeviceDefs.h"
#include "Conversions.h"
#include "BtcmSrvGprot.h"
#include "Bluetooth_struct.h"
//#include "BTMMIObexGprots.h"
#include "drm_gprot.h"
#include "PhoneSetupGprots.h" /* for extern U8 PhnsetGetDefEncodingType(void); */
// RHR: add
#include "FtpSrv.h"
#include "MMIDataType.h"
#include "fs_type.h"
#include "MMI_conn_app_trc.h"
#include "FtpSrvGprots.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "string.h"
#include "stack_msgs.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "mmi_frm_events_gprot.h"
#include "bluetooth_bm_struct.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "FileMgrSrvGProt.h"
#include "Unicodexdcl.h"
#include "fmt_def.h"
#include "stdio.h"
#include "FileMgrType.h"
#include "stack_ltlcom.h"
#include "stack_config.h"
#include "stack_common.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "GeneralSettingSrvGprot.h"
// RHR: add

#include "BTMMIFtpGprots.h"
#include "FtpsSrv.h"
/* #include "xml_def.h" */

/***************************************************************************** 
* CONTEXT
*****************************************************************************/
srv_ftp_hdlr_struct ftps_handle[SRV_FTP_MAX_SERVER_NUM];

srv_ftps_cntx_struct g_mmi_ftps_cntx;
extern srv_ftps_cntx_struct *const ftps_cntx_p = &g_mmi_ftps_cntx;
srv_ftps_conn_cntx_struct *act_server_cntx_p;

/***************************************************************************** 
* MACROS
*****************************************************************************/
/* MMI usb context bit-wise flag operation */
#define MMI_FTPS_SET_FLAG(a)       ( (ftps_cntx_p->ftps_flag) |=  a )
#define MMI_FTPS_GET_FLAG(a)       ( ((ftps_cntx_p->ftps_flag) & a) == 0 ? MMI_FALSE : MMI_TRUE )
#define MMI_FTPS_RESET_FLAG(a)     ( (ftps_cntx_p->ftps_flag) &=  ~a )

/***************************************************************************** 
* INTERNAL STATIC FUNCTION
*****************************************************************************/
static void srv_ftps_set_parent_folder(void);
static void srv_ftps_set_folder(goep_set_folder_ind_struct *ind);
static void srv_ftps_create_folder(goep_set_folder_ind_struct *ind);
static void srv_ftps_push_delete(goep_push_ind_struct *ind);
//static void srv_ftps_push_delete_call_back(void *info);
static void srv_ftps_write_obj_continue(goep_push_ind_struct *ind);
static void srv_ftps_pull_continue(void);
static void srv_ftps_send_folder_content(void);
static void srv_ftps_send_obj(void);
static S32 srv_ftps_write_obj(goep_push_ind_struct *ind);
static void srv_ftps_gen_folder_content(PU8 folder_name);
static S32 srv_ftps_compose_folder_element(srv_ftp_file_writer_struct *composer,
                                           srv_ftp_obj_info_struct *file_info);
static S32 srv_ftps_compose_file_element(srv_ftp_file_writer_struct *composer, srv_ftp_obj_info_struct *file_info);
static S32 srv_ftps_compose_end_element(srv_ftp_file_writer_struct *composer);
static void srv_ftps_set_fs_flag(S32 ret);
static void srv_ftps_send_push_res(U8 goep_conn_id, U8 rsp_code);
static void srv_ftps_gen_root_content(void);
static S32 srv_ftps_writer_flush(srv_ftp_file_writer_struct *composer, U8 *data);
static void srv_ftps_gen_folder_content_error_handle(void);
static void srv_ftps_send_gen_folder_continue(void);
static void srv_ftps_send_pull_error(void);
static void srv_ftps_gen_folder_content_continue(void);
static S32 srv_ftps_write_folder_content(FS_DOSDirEntry *fs_file_info_p);
static void srv_ftps_connection_terminated(void);
static U8 srv_ftps_sdp_register_cnf_handle(void *msg);
static U8 srv_ftps_sdp_deregister_cnf_handle(void *msg);
static void srv_ftps_authorize_accept_internal(void);
#ifdef __MMI_BT_RX_ENHANCE__
static void srv_ftps_inbuf_write_obj_continue(void);
#endif /* __MMI_BT_RX_ENHANCE__ */


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_activate
 * DESCRIPTION
 *  This function is to activate the FTP application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftps_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_register_server_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_ACTIVATE);
    switch (act_server_cntx_p->ftps_state)
    {
        case SRV_FTPS_STATE_IDLE:
            req = (goep_register_server_req_struct*)OslConstructDataPtr(sizeof(goep_register_server_req_struct));
            FTP_MEMSET(req);
            memcpy(req->uuid, OBEX_FTP_UUID, 16);
            req->uuid_len = 16;
            req->req_id = (U8)0;
            req->tp_type = GOEP_TP_BT;
            req->buf_ptr = act_server_cntx_p->ftps_obj_buff;
            req->buf_size = SRV_FTPS_MEM_BUFF_SIZE;
            SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_REGISTERING);
            srv_ftp_send_msg(MSG_ID_GOEP_REGISTER_SERVER_REQ, req);
            break;

        case SRV_FTPS_STATE_REGISTERING:
            break;

        default: /* other states */
            SRV_FTPS_LOG_STATE_ERR();
            srv_bt_cm_activate_cnf_hdler(SRV_BT_CM_OBEX_FILE_TRANSFER_UUID);
            {
                srv_ftp_post_event_struct post_event;
                srv_ftps_start_indication_struct* ind_p =
                    (srv_ftps_start_indication_struct*)OslMalloc(sizeof(srv_ftps_start_indication_struct));

                ind_p->result = SRV_FTPS_START_OK;
                MMI_FRM_INIT_EVENT(&post_event, EVENT_ID_FTPS_START);
                post_event.ftp_role = SRV_FTP_ROLE_SERVER;
                post_event.event = SRV_FTPS_EVENT_START;
                post_event.data_p = (void*)ind_p;
                mmi_frm_post_event((mmi_event_struct*)&post_event, srv_ftp_post_event_proc, NULL);
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_deactivate
 * DESCRIPTION
 *  This function is to deactivate the FTP application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftps_deactivate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_sdpdb_deregister_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_DEACTIVATE, act_server_cntx_p->ftps_state);
    switch (act_server_cntx_p->ftps_state)
    {
        case SRV_FTPS_STATE_REGISTERING: /* activating -> deactivating */
        case SRV_FTPS_STATE_DEACTIVATING: /* deactivating -> deactivating */
            SRV_FTPS_LOG_STATE_ERR();
            //ASSERT(0);
            break;

        case SRV_FTPS_STATE_IDLE: /* unactivated */
        {
            srv_ftp_post_event_struct post_event;
            srv_bt_cm_deactivate_cnf_hdler(SRV_BT_CM_OBEX_FILE_TRANSFER_UUID);

            MMI_FRM_INIT_EVENT(&post_event, EVENT_ID_FTPS_STOP);
            post_event.ftp_role = SRV_FTP_ROLE_SERVER;
            post_event.event = SRV_FTPS_EVENT_STOP;
            post_event.data_p = NULL;
            mmi_frm_post_event((mmi_event_struct*)&post_event, srv_ftp_post_event_proc, NULL);
            break;
        }

        default: /* other activated states */
            req = (bt_sdpdb_deregister_req_struct*)OslConstructDataPtr(sizeof(bt_sdpdb_deregister_req_struct));
            FTP_MEMSET(req);
            req->uuid = SRV_BT_CM_OBEX_FILE_TRANSFER_UUID;
            srv_ftp_send_msg(MSG_ID_BT_SDPDB_DEREGISTER_REQ, req);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_disconnect_client
 * DESCRIPTION
 *  This function is to deactivate the FTP application
 * PARAMETERS
 *  bd_addr         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftps_disconnect_client(srv_bt_cm_bt_addr bd_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //goep_disconnect_req_struct *req;
    //srv_ftps_disconnect_indication_struct dis_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_FTP_TRC_CLASS,
        SRV_FTPS_DISCONNECT_CLIENT,
        act_server_cntx_p->ftps_state,
        ftps_cntx_p->g_conn_id,
        ftps_cntx_p->conn_id);
    if (ftps_cntx_p->conn_id > 0)
    {
        srv_ftps_disconnect_conn(ftps_cntx_p->conn_id);
//         switch (act_server_cntx_p->ftps_state)
//         {
//             case SRV_FTPS_STATE_DISCONNECTING: /* disconnecting -> disconnecting */
//                 SRV_FTPS_LOG_STATE_ERR();
//                 //act_server_cntx_p->dis_from_cm = MMI_TRUE;
//                 /* ASSERT(0); */ /* allow call this function more than one time before it notify CM */
//                 return;

//             /* connected states */
//             case SRV_FTPS_STATE_ACTIVE:
//                 //Connection sync to RFCOMM channel == Authorize
//                 //both accept and reject will send disconnect req to goep
//             case SRV_FTPS_STATE_ACCEPTED:
//             case SRV_FTPS_STATE_RECEIVING:
//             case SRV_FTPS_STATE_SENDING:
//                 SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_DISCONNECTING);
//                 /* then do the same thing as state deactivating */
//                 /* deactivate triggered disconnecting */
//             case SRV_FTPS_STATE_DEACTIVATING:
//                 req = (goep_disconnect_req_struct*)OslConstructDataPtr(sizeof(goep_disconnect_req_struct));
//                 FTP_MEMSET(req);
//                 req->goep_conn_id = ftps_cntx_p->goep_conn_id;
//                 srv_ftp_send_msg(MSG_ID_GOEP_DISCONNECT_REQ, req);
//                 return;
//         }
    }
    else
    {
        srv_ftp_post_event_struct post_event;
        srv_ftps_disconnect_indication_struct* ind_p =
            (srv_ftps_disconnect_indication_struct*)OslMalloc(sizeof(srv_ftps_disconnect_indication_struct));

        ind_p->bd_address = act_server_cntx_p->ftps_bt_device;
        ind_p->cm_conn_id = ftps_cntx_p->g_conn_id;
        MMI_FRM_INIT_EVENT(&post_event, EVENT_ID_FTPS_DISCONNECT_CLIENT);
        post_event.ftp_role = SRV_FTP_ROLE_SERVER;
        post_event.event = SRV_FTPS_EVENT_DISCONNECT;
        post_event.data_p = (void*)ind_p;
        mmi_frm_post_event((mmi_event_struct*)&post_event, srv_ftp_post_event_proc, NULL);
    }
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_disconnect_conn
 * DESCRIPTION
 *  this function is to disconnect ftp client with connection ID
 * PARAMETERS
 *  conn_id    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
extern void srv_ftps_disconnect_conn(U32 conn_id)
{
    goep_disconnect_req_struct *req;

    if (ftps_cntx_p->conn_id == conn_id)
    {
        switch (act_server_cntx_p->ftps_state)
        {
            case SRV_FTPS_STATE_DISCONNECTING: /* disconnecting -> disconnecting */
                SRV_FTPS_LOG_STATE_ERR();
                break;

            /* connected states */
            case SRV_FTPS_STATE_ACTIVE:
            case SRV_FTPS_STATE_ACCEPTED:
            case SRV_FTPS_STATE_RECEIVING:
            case SRV_FTPS_STATE_SENDING:
                SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_DISCONNECTING);
                /* then do the same thing as state deactivating */
                /* deactivate triggered disconnecting */
            case SRV_FTPS_STATE_DEACTIVATING:
                req = (goep_disconnect_req_struct*)OslConstructDataPtr(sizeof(goep_disconnect_req_struct));
                FTP_MEMSET(req);
                req->goep_conn_id = ftps_cntx_p->goep_conn_id;
                srv_ftp_send_msg(MSG_ID_GOEP_DISCONNECT_REQ, req);
                break;
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_ftps_authorize_accept_internal
 * DESCRIPTION
 *  This function is to accept rfcomm channel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftps_authorize_accept_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_authorize_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, 
              SRV_FTPS_AUTHORIZE_ACCEPT_INTERNAL,
              act_server_cntx_p->ftps_state,
              ftps_cntx_p->cur_goep_conn_id);

    if (act_server_cntx_p->ftps_state == SRV_FTPS_STATE_AUTHORIZING)
    {
        SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACTIVE);
        /* for other apps query FTP connection in state active */
        /* accept == 0xFE, reject, delete, not authorize == 0xFF */
        /* connected states == 0, 1, 2,.... */
        ftps_cntx_p->g_conn_id = 0xFE;

        res = (goep_authorize_res_struct*)OslConstructDataPtr(sizeof(goep_authorize_res_struct));
        FTP_MEMSET(res);
        res->goep_conn_id = ftps_cntx_p->goep_conn_id;
        res->rsp_code = GOEP_STATUS_SUCCESS;
        srv_ftp_send_msg(MSG_ID_GOEP_AUTHORIZE_RES, res);
    }
//     else
//     {
//         ASSERT(0);
//     }
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_authorize_accept
 * DESCRIPTION
 *  this function is to accept a connection
 * PARAMETERS
 *  hd    [IN]    service handle
 *  
 * RETURNS
 *  SRV_FTP_RESULT_OK: success
 *  SRV_FTP_INVALID_HANDLE: failed
 ******************************************************************************/
S32 srv_ftps_authorize_accept(S32 hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ftps_is_valid_handle(hd))
    {
        srv_ftps_authorize_accept_internal();
        return SRV_FTP_RESULT_OK;
    }

    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_INVALID_HDLR, hd);
    return SRV_FTP_INVALID_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_authorize_reject
 * DESCRIPTION
 *  This function is to reject rfcomm channel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_ftps_authorize_reject(S32 hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_authorize_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, 
              SRV_FTPS_AUTHORIZE_REJECT,
              act_server_cntx_p->ftps_state,
              ftps_cntx_p->cur_goep_conn_id);

    if (srv_ftps_is_valid_handle(hd))
    {
        if (act_server_cntx_p->ftps_state == SRV_FTPS_STATE_AUTHORIZING)
        {
            SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACTIVE);
/*             if (ftps_cntx_p->conn_id > 0) */
/*             { */
/*                 srv_bt_cm_stop_conn(ftps_cntx_p->conn_id); */
/*                 ftps_cntx_p->conn_id = -1; */
/*             } */

            res = (goep_authorize_res_struct*)OslConstructDataPtr(sizeof(goep_authorize_res_struct));
            FTP_MEMSET(res);
            res->goep_conn_id = ftps_cntx_p->goep_conn_id;
            res->rsp_code = GOEP_STATUS_FAILED;
            srv_ftp_send_msg(MSG_ID_GOEP_AUTHORIZE_RES, res);
            return SRV_FTP_RESULT_OK;
        }
        else
        {
            //ASSERT(0);
            return SRV_FTP_RESULT_FAIL;
        }
    }
    
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_INVALID_HDLR, hd);
    return SRV_FTP_INVALID_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftp_server_is_receiving
 * DESCRIPTION
 *  This function is to get current status of ftp server.
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)(?)
 *****************************************************************************/
MMI_BOOL srv_ftps_is_receiving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (act_server_cntx_p->ftps_state)
    {
        case SRV_FTPS_STATE_RECEIVING:
            return MMI_TRUE;

        default:
            return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_cntx_init
 * DESCRIPTION
 *  This function is to initialize FTPS context
 *  This funciton is only to init the cntxt in ftps, if read shared path info from a hidden file, if read failed, 
 *  then default path will be set to variables.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftps_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_bt_cm_profile_struct ftps_tbl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_CNTX_INIT);

    act_server_cntx_p = &(ftps_cntx_p->conn_cntx);
    
    /* FTPS error flag Init */
    ftps_cntx_p->ftps_flag = 0;
    /* for get cur goep_conn_id in authorize process */
    ftps_cntx_p->cur_goep_conn_id = 0;

    act_server_cntx_p->ftps_browse_depth = 0;
    //memset(act_server_cntx_p->current_folder, 0, (SRV_FMGR_PATH_MAX_LEN+1) * ENCODING_LENGTH);
    act_server_cntx_p->current_folder[0] = 0;

    /* ID Init */
    ftps_cntx_p->goep_conn_id = 0xFE; /* avoid case: When Client Connecting, BT Reset. disconnect_ind_hdlr */
    ftps_cntx_p->g_conn_id = 0xFF;

    /* Send/Recv File Handle Init */
    if (act_server_cntx_p->fh_ftps_send)
    {
        FS_Close(act_server_cntx_p->fh_ftps_send);
        act_server_cntx_p->fh_ftps_send = (FS_HANDLE)NULL;
    }

    if (act_server_cntx_p->fh_ftps_recv)
    {
        FS_Close(act_server_cntx_p->fh_ftps_recv);
        act_server_cntx_p->fh_ftps_recv = (FS_HANDLE)NULL;
    }

    /* FTPS STATE Init */
    act_server_cntx_p->ftps_state = SRV_FTPS_STATE_IDLE;

    /* reset hd, solve: when the ftps is active , then CM init, call activate */
    for (i = 0; i < SRV_FTP_MAX_SERVER_NUM; ++i)
    {
        ftps_handle[i].srv_hd = 0;
    }

    /* Xml_composer Init */
    memset(&(act_server_cntx_p->xml_composer), 0, sizeof(srv_ftp_file_writer_struct));

    /* bt_device_addr init */
    memset(&(act_server_cntx_p->ftps_bt_device), 0, sizeof(srv_bt_cm_bt_addr));

    /* FTPS obj buffer init */
    memset(act_server_cntx_p->ftps_obj_buff, 0, SRV_FTPS_MEM_BUFF_SIZE);

    /* FTPS Obj Name Init */
    //memset(act_server_cntx_p->ftps_obj_name, 0, SRV_FTPS_MAX_OBJ_NAME_LEN);
    act_server_cntx_p->ftps_obj_name[0] = 0;

    /* FTPS Dev Name Init */
    //memset(act_server_cntx_p->dev_name, 0, GOEP_MAX_DEV_NAME);

    /* FTPS FOLDER CONTENT FILE Init */
    SRV_FTPS_MAKE_FOLDER_CONTENT(act_server_cntx_p->folder_content);

    /* Others Init */
    act_server_cntx_p->send_obj_type = SRV_FTP_OBJ_TYPE_NONE;
    act_server_cntx_p->total_send_obj_len = 0;
    act_server_cntx_p->send_obex_pkt_size = 0;
    act_server_cntx_p->remain_send_obj_len = 0;

#ifdef __MMI_BT_RX_ENHANCE__
    act_server_cntx_p->ftps_inbuf_pkt_error = SRV_FTP_PRE_PKT_ERR_NONE;
    act_server_cntx_p->ftps_inbuf_len = 0;
#endif /* __MMI_BT_RX_ENHANCE__ */

    mmi_frm_set_protocol_event_handler(MSG_ID_BT_SDPDB_REGISTER_CNF, srv_ftps_sdp_register_cnf_handle, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_SDPDB_DEREGISTER_CNF, srv_ftps_sdp_deregister_cnf_handle, MMI_TRUE);

    ftps_tbl.profile_id = SRV_BT_CM_OBEX_FILE_TRANSFER_UUID;
    ftps_tbl.activater = srv_ftps_activate;
    ftps_tbl.deactivater = srv_ftps_deactivate;
    ftps_tbl.disconnector = srv_ftps_disconnect_conn;
    srv_bt_cm_profile_register((const srv_bt_cm_profile_struct*)&ftps_tbl);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_write_obj
 * DESCRIPTION
 *  This function is to write obj to file
 * PARAMETERS
 *  ind     [?]         
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 srv_ftps_write_obj(goep_push_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_push_res_struct *res;
    S32 ret;
    U32 len_written;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_WRITE_OBJ, ind->pkt_type);

    if (ind->frag_len > 0)
    {
        ret = FS_Write(act_server_cntx_p->fh_ftps_recv, ind->frag_ptr, ind->frag_len, (kal_uint32*)&len_written);
        MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_WRITE_OBJ_WRITE, ret);
        if (ret < 0)
        {
            FS_Close(act_server_cntx_p->fh_ftps_recv);
            act_server_cntx_p->fh_ftps_recv = (FS_HANDLE)NULL;
            return  ret;
        }
    }

    if ((ind->pkt_type == GOEP_FINAL_PKT) || (ind->pkt_type == GOEP_SINGLE_PKT))
    {
        //if (act_server_cntx_p->fh_ftps_recv)
        FS_Close(act_server_cntx_p->fh_ftps_recv);
        act_server_cntx_p->fh_ftps_recv = (FS_HANDLE)NULL;

        SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
        {
            srv_ftps_operation_end_struct push_ind;

            push_ind.operation = SRV_FTPS_OPERATION_PUSH;
            push_ind.result = SRV_FTP_MASK_RESULT_OK;
            srv_ftps_notify(SRV_FTPS_EVENT_OPERATION_END, (void*)&push_ind);
        }
    }

    /* send res to goep with success no matter the last packet or not */
    res = (goep_push_res_struct*)OslConstructDataPtr(sizeof(goep_push_res_struct));
    FTP_MEMSET(res);
    res->goep_conn_id = ftps_cntx_p->goep_conn_id;
    res->rsp_code = GOEP_STATUS_SUCCESS;
    srv_ftp_send_msg(MSG_ID_GOEP_PUSH_RES, res);
    return 1;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_accept_push_obj
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hd           [IN]  service handle
 *  conn_id      [IN]  not used now
 *  save_path    [IN]  obj save path
 *  
 * RETURNS
 *  void
 ******************************************************************************/
void srv_ftps_accept_push_obj(S32 hd, U32 conn_id, U16* save_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    FS_HANDLE h;
    goep_push_ind_struct* ind = act_server_cntx_p->push_ind;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_ACCEPT_PUSH_OBJ);
    if (srv_ftps_is_valid_handle(hd))
    {
        h = FS_Open((const WCHAR*)save_path, (FS_READ_WRITE | FS_CREATE_ALWAYS));
        if (h >= FS_NO_ERROR)
        {
            act_server_cntx_p->fh_ftps_recv = h;
#ifdef __MMI_BT_RX_ENHANCE__
            act_server_cntx_p->ftps_inbuf_pkt_error = SRV_FTP_PRE_PKT_ERR_NONE;
#endif

            ret = srv_ftps_write_obj(ind);
        }
        else
        {
            ret = (S32)h;
        }
        
        if (ret < 0)
        {
            srv_ftps_operation_end_struct push_ind;

            srv_ftps_set_fs_flag((S32)ret);
            MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_PUSH_OBJ_ERR);

            SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
            srv_ftps_send_push_res(ftps_cntx_p->goep_conn_id, GOEP_INTERNAL_SERVER_ERR);

            push_ind.operation = SRV_FTPS_OPERATION_PUSH;
            push_ind.result = ftps_cntx_p->ftps_flag;
            srv_ftps_notify(SRV_FTPS_EVENT_OPERATION_END, (void*)&push_ind);

            ftps_cntx_p->ftps_flag = 0;
        }
    }

    /* invalid handle || FTPS_PUSH_OBJ_ERR */
    if (act_server_cntx_p->push_ind != NULL)
    {
        free_local_para((local_para_struct*)act_server_cntx_p->push_ind);
        act_server_cntx_p->push_ind = NULL;
    }
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_reject_push_obj
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hd         [IN]
 *  conn_id    [IN]    not used now
 * RETURNS
 *  
 ******************************************************************************/
void srv_ftps_reject_push_obj(S32 hd, U32 conn_id)
{
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_REJECT_PUSH_OBJ);
    if (srv_ftps_is_valid_handle(hd))
    {
        SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
        srv_ftps_send_push_res(ftps_cntx_p->goep_conn_id, GOEP_INTERNAL_SERVER_ERR);
    }

    if (act_server_cntx_p->push_ind != NULL)
    {
        free_local_para((local_para_struct*)act_server_cntx_p->push_ind);
        act_server_cntx_p->push_ind = NULL;
    }
}


static MMI_RET srv_ftps_push_delete_proc(mmi_event_struct *param)
{
    srv_fmgr_async_done_event_struct* event;
    goep_push_res_struct *res;

    MMI_TRACE(MMI_FTP_TRC_CLASS,
              SRV_FTPS_PUSH_DELETE_PROC,
              ((srv_fmgr_async_done_event_struct*)param)->job_id,
              ((srv_fmgr_async_done_event_struct*)param)->result);
    
    switch(param->evt_id)
    {
        case EVT_ID_SRV_FMGR_ASYNC_DONE:
            event = (srv_fmgr_async_done_event_struct*)param;
            ASSERT(act_server_cntx_p->ftps_fmgr_job_id == event->job_id);

            if (act_server_cntx_p->ftps_state == SRV_FTPS_STATE_RECEIVING)
            {
                res = (goep_push_res_struct*)OslConstructDataPtr(sizeof(goep_push_res_struct));
                FTP_MEMSET(res);
                res->goep_conn_id = ftps_cntx_p->goep_conn_id;

                if (event->result == 0)
                {
                    res->rsp_code = GOEP_STATUS_SUCCESS;
                }
                else
                {
                    res->rsp_code = GOEP_INTERNAL_SERVER_ERR;  
                }

                srv_ftp_send_msg(MSG_ID_GOEP_PUSH_RES, res);
                SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
            }

            act_server_cntx_p->ftps_fmgr_job_id = 0;
            
            break;
    }

    return MMI_RET_OK;
}
    

/*****************************************************************************
 * FUNCTION
 *  srv_ftps_push_delete
 * DESCRIPTION
 *  This function is to delete a obj from server
 * PARAMETERS
 *  ind
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftps_push_delete(goep_push_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_push_res_struct *res;
    kal_uint8 ret = 0;
    S32 attr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_PUSH_DELETE);
    if (mmi_ucs2strlen((CHAR*)ind->obj_name) > 0)
    {
        if (mmi_ucs2strlen((CHAR*)act_server_cntx_p->current_folder) + 
            mmi_ucs2strlen((CHAR*)ind->obj_name) > SRV_FMGR_PATH_MAX_LEN)
        {
            MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_PUSH_DELETE_INVALID_NAME);
            ret = GOEP_INTERNAL_SERVER_ERR;
            goto FTPS_PUSH_DELETE_SEND;
        }
        srv_ftp_obj_name_swapcpy((CHAR*)ind->obj_name, (CHAR*)ind->obj_name);
        mmi_wcscpy(act_server_cntx_p->ftps_obj_name, act_server_cntx_p->current_folder);
        mmi_ucs2cat((CHAR*)act_server_cntx_p->ftps_obj_name, (CHAR*)ind->obj_name);
    }
    else
    {
        MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_PUSH_DELETE_WITHOUT_NAME);
        ret = GOEP_NOT_FOUND;
        goto FTPS_PUSH_DELETE_SEND;
    }
    
    attr = FS_GetAttributes((const WCHAR*)act_server_cntx_p->ftps_obj_name);
    if (attr < 0)
    {
        ret = GOEP_NOT_FOUND;
        goto FTPS_PUSH_DELETE_SEND;
    }

    if (attr & FS_ATTR_DIR)
    {
        /* mmi_fmgr_util_send_delete_req( */
        /*     (U8*)act_server_cntx_p->ftps_obj_name, */
        /*     FS_DIR_TYPE, */
        /*     srv_ftps_push_delete_call_back); */
        act_server_cntx_p->ftps_fmgr_job_id = srv_fmgr_async_delete(
            (WCHAR*)act_server_cntx_p->ftps_obj_name,
            FMT_DELETE_FOLDER,
            srv_ftps_push_delete_proc,            
            NULL);
        if (act_server_cntx_p->ftps_fmgr_job_id < 0)
        {
            goep_push_res_struct *res = (goep_push_res_struct*)OslConstructDataPtr(sizeof(goep_push_res_struct));
            FTP_MEMSET(res);
            res->goep_conn_id = ftps_cntx_p->goep_conn_id;
            res->rsp_code = GOEP_INTERNAL_SERVER_ERR;  

            srv_ftp_send_msg(MSG_ID_GOEP_PUSH_RES, res);
            SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);

            act_server_cntx_p->ftps_fmgr_job_id = 0;
        }
    }
    else
    {
        /* mmi_fmgr_util_send_delete_req( */
        /*     (U8*)act_server_cntx_p->ftps_obj_name, */
        /*     FS_FILE_TYPE, */
        /*     srv_ftps_push_delete_call_back); */
        act_server_cntx_p->ftps_fmgr_job_id = srv_fmgr_async_delete(
            (WCHAR*)act_server_cntx_p->ftps_obj_name,
            FMT_DELETE_SINGLE,
            srv_ftps_push_delete_proc,            
            NULL);
        if (act_server_cntx_p->ftps_fmgr_job_id < 0)
        {
            goep_push_res_struct *res = (goep_push_res_struct*)OslConstructDataPtr(sizeof(goep_push_res_struct));
            FTP_MEMSET(res);
            res->goep_conn_id = ftps_cntx_p->goep_conn_id;
            res->rsp_code = GOEP_INTERNAL_SERVER_ERR;

            srv_ftp_send_msg(MSG_ID_GOEP_PUSH_RES, res);
            SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);

            act_server_cntx_p->ftps_fmgr_job_id = 0;
        }
    }
    return;
        
FTPS_PUSH_DELETE_SEND:
    res = (goep_push_res_struct*)OslConstructDataPtr(sizeof(goep_push_res_struct));
    res->goep_conn_id = ftps_cntx_p->goep_conn_id;
    res->rsp_code = ret;
    srv_ftp_send_msg(MSG_ID_GOEP_PUSH_RES, res);
    SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_push_delete_call_back
 * DESCRIPTION
 *  Callback function to receive the delete results
 * PARAMETERS
 *  info
 * RETURNS
 *  void
 *****************************************************************************/
/* static void srv_ftps_push_delete_call_back(void *info) */
/* { */
/*     /\*----------------------------------------------------------------*\/ */
/*     /\* Local Variables                                                *\/ */
/*     /\*----------------------------------------------------------------*\/ */
/*     mmi_fmt_delete_rsp_strcut *msg_p = (mmi_fmt_delete_rsp_strcut*)info; */
/*     goep_push_res_struct *res; */
    
/*     /\*----------------------------------------------------------------*\/ */
/*     /\* Code Body                                                      *\/ */
/*     /\*----------------------------------------------------------------*\/ */
/*     MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_PUSH_DEL_CBK, act_server_cntx_p->ftps_state, msg_p->result); */
/*     if (act_server_cntx_p->ftps_state == SRV_FTPS_STATE_RECEIVING) */
/*     { */
/*         res = (goep_push_res_struct*)OslConstructDataPtr(sizeof(goep_push_res_struct)); */

/*         FTP_MEMSET(res); */
/*         res->goep_conn_id = ftps_cntx_p->goep_conn_id; */
/*         if (msg_p->result >= FS_NO_ERROR) */
/*         { */
/*             res->rsp_code = GOEP_STATUS_SUCCESS; */
/*         } */
/*         else */
/*         { */
/*             res->rsp_code = GOEP_INTERNAL_SERVER_ERR;   */
/*         } */

/*         srv_ftp_send_msg(MSG_ID_GOEP_PUSH_RES, res); */
/*         SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED); */
/*     } */
/* } */


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_write_obj_continue
 * DESCRIPTION
 *  This function is to write the data to file, and send res.
 * PARAMETERS
 *  ind
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftps_write_obj_continue(goep_push_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ftps_operation_end_struct push_ind;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_PUSH_CONTINUE, ind->pkt_type);
    if (ind->frag_len > 0)
    {
        U32 len_written;

        ret = FS_Write(act_server_cntx_p->fh_ftps_recv, ind->frag_ptr, ind->frag_len, (kal_uint32*)&len_written);
        MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_PUSH_CONTINUE_WRITE, ret);
        if (ret < 0)
        {
            srv_ftps_set_fs_flag(ret);
            FS_Close(act_server_cntx_p->fh_ftps_recv);
            act_server_cntx_p->fh_ftps_recv = (FS_HANDLE)NULL;
            
            SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
            srv_ftps_send_push_res(ftps_cntx_p->goep_conn_id, GOEP_INTERNAL_SERVER_ERR);

            push_ind.operation = SRV_FTPS_OPERATION_PUSH;
            push_ind.result = ftps_cntx_p->ftps_flag;
            srv_ftps_notify(SRV_FTPS_EVENT_OPERATION_END, (void*)&push_ind);

            ftps_cntx_p->ftps_flag = 0;
            return;
        }
    }

    if ((ind->pkt_type == GOEP_FINAL_PKT) || (ind->pkt_type == GOEP_SINGLE_PKT))
    {
        SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);

        //if (act_server_cntx_p->fh_ftps_recv)
        FS_Close(act_server_cntx_p->fh_ftps_recv);
        act_server_cntx_p->fh_ftps_recv = (FS_HANDLE)NULL;

        push_ind.operation = SRV_FTPS_OPERATION_PUSH;
        push_ind.result = SRV_FTP_MASK_RESULT_OK;
        srv_ftps_notify(SRV_FTPS_EVENT_OPERATION_END, (void*)&push_ind);
    }

    srv_ftps_send_push_res(ftps_cntx_p->goep_conn_id, GOEP_STATUS_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_create_folder
 * DESCRIPTION
 *  This function is to create a new folder and set as the current folder
 * PARAMETERS
 *  ind
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftps_create_folder(goep_set_folder_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    goep_set_folder_res_struct *res;
    //S32 access_right = mmi_bt_get_setting_int(BTFF_ITEM_FTP_ACCESS);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_CREATE_FOLDER, ftps_cntx_p->goep_conn_id);
    res = (goep_set_folder_res_struct*)OslConstructDataPtr(sizeof(goep_set_folder_res_struct));
    FTP_MEMSET(res);
    res->goep_conn_id = ftps_cntx_p->goep_conn_id;

    /* Check the access right first. If the access right is read only, return failed directly */
    //if (access_right == FTP_PERMISSION_READ_ONLY || act_server_cntx_p->ftps_browse_depth == 0)
    if ((ftps_cntx_p->access_right == SRV_FTPS_PERMISSION_READ_ONLY) ||
        (act_server_cntx_p->ftps_browse_depth == 0))
    {
        res->rsp_code = GOEP_UNAUTHORIZED;
        if (act_server_cntx_p->ftps_browse_depth == 0)
        {
            res->rsp_code = GOEP_FORBIDDEN;
        }

        srv_ftp_send_msg(MSG_ID_GOEP_SET_FOLDER_RES, res);
        return;     
    }

    /* check the folder name */
    if (mmi_ucs2strlen((CHAR*)ind->folder_name) > 0)
    {
        srv_ftp_obj_name_swapcpy((CHAR*)ind->folder_name, (CHAR*)ind->folder_name);
        srv_ftp_ucs2_cut_name_without_ext((CHAR*)ind->folder_name, GOEP_MAX_FOLDER_NAME, (CHAR*)ind->folder_name);
    }
    /* maybe folder_name is '   ' */
    if (mmi_ucs2strlen((CHAR*)ind->folder_name) == 0)
    {
        kal_wsprintf((WCHAR*)ind->folder_name, "new_folder");
    }

    /* form folder path */    
    if (mmi_ucs2strlen((CHAR*)(act_server_cntx_p->current_folder)) +
        mmi_ucs2strlen((CHAR*)ind->folder_name) > (SRV_FMGR_PATH_MAX_LEN - 1))
    {
        res->rsp_code = GOEP_INTERNAL_SERVER_ERR;
        srv_ftp_send_msg(MSG_ID_GOEP_SET_FOLDER_RES, res);
        return;     
    }
    mmi_wcscpy(act_server_cntx_p->ftps_obj_name, (act_server_cntx_p->current_folder));
    mmi_ucs2cat((CHAR*)act_server_cntx_p->ftps_obj_name, (CHAR*)ind->folder_name);
    mmi_ucs2cat((CHAR*)act_server_cntx_p->ftps_obj_name, (CHAR*)L"\\");

    ret = FS_CreateDir((WCHAR*)act_server_cntx_p->ftps_obj_name);
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_CREATE_FOLDER_CREATE_DIR, ret);

    if ((ret < 0) && (ret != FS_FILE_EXISTS))
    {
        res->rsp_code = GOEP_INTERNAL_SERVER_ERR;
        srv_ftp_send_msg(MSG_ID_GOEP_SET_FOLDER_RES, res);
    }
    else
    {
        act_server_cntx_p->ftps_browse_depth++;
        mmi_wcscpy(act_server_cntx_p->current_folder, act_server_cntx_p->ftps_obj_name);
        res->rsp_code = GOEP_STATUS_SUCCESS;
        srv_ftp_send_msg(MSG_ID_GOEP_SET_FOLDER_RES, res);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_set_folder
 * DESCRIPTION
 *  This function is to set current folder to selected folder
 * PARAMETERS
 *  ind
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftps_set_folder(goep_set_folder_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 new_folder[(SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH];
    goep_set_folder_res_struct *res;
    FS_HANDLE h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_SET_FOLDER, ftps_cntx_p->goep_conn_id);
    res = (goep_set_folder_res_struct*)OslConstructDataPtr(sizeof(goep_set_folder_res_struct));
    FTP_MEMSET(res);
    res->goep_conn_id = ftps_cntx_p->goep_conn_id;

    memset(new_folder, 0, (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH);
    srv_ftp_obj_name_swapcpy((CHAR*)ind->folder_name, (CHAR*)ind->folder_name);
    
    if (act_server_cntx_p->ftps_browse_depth == 0)
    {
        res->rsp_code = GOEP_NOT_FOUND;
        mmi_ucs2cat((CHAR*)(ind->folder_name), (CHAR*)L"\\");

        h = FS_Open((kal_uint16*)ind->folder_name, FS_READ_ONLY | FS_OPEN_DIR);
        if (h >= FS_NO_ERROR)
        {
            FS_Close(h);
            act_server_cntx_p->ftps_browse_depth++;
            mmi_ucs2cpy((CHAR*)(act_server_cntx_p->current_folder), (CHAR*)ind->folder_name);

            res->rsp_code = GOEP_STATUS_SUCCESS;
        }

        srv_ftp_send_msg(MSG_ID_GOEP_SET_FOLDER_RES, res);
        return;
    }

    /* not parent or current folder */
    if ((mmi_ucs2cmp((CHAR*)ind->folder_name, (CHAR*)L".") != 0) &&
        (mmi_ucs2cmp((CHAR*)ind->folder_name, (CHAR*)L"..") != 0))
    {
        mmi_ucs2cpy((CHAR*)new_folder, (CHAR*)(act_server_cntx_p->current_folder));
        /* fail-safe for enough memory to store the folder_name + folder_path (2 = '\0','\') */
        if (mmi_ucs2strlen((CHAR*)new_folder) + mmi_ucs2strlen((CHAR*)ind->folder_name) > (SRV_FMGR_PATH_MAX_LEN - 1))
        {
            res->rsp_code = GOEP_NOT_FOUND; /* send res with error rsp_code not found */
            goto FTPS_SET_FOLDER_SEND;
        }

        /* form folder path */
        mmi_ucs2cat((CHAR*)new_folder, (CHAR*)ind->folder_name);
        mmi_ucs2cat((CHAR*)new_folder, (CHAR*)L"\\");

        h = FS_Open((kal_uint16*)new_folder, FS_READ_ONLY | FS_OPEN_DIR);
        /* if folder exist, set folder send res */
        if (h >= FS_NO_ERROR)
        {
            FS_Close(h);
            mmi_ucs2cpy((CHAR*)(act_server_cntx_p->current_folder), (CHAR*)new_folder);
            act_server_cntx_p->ftps_browse_depth++;            

            res->rsp_code = GOEP_STATUS_SUCCESS;
            goto FTPS_SET_FOLDER_SEND;
        }
        else /* FS_PATH_NOT_FOUND */
        {
            res->rsp_code = GOEP_NOT_FOUND;
            goto FTPS_SET_FOLDER_SEND;
        }
    }
    /* go to parent folder */
    else if (mmi_ucs2cmp((CHAR*)ind->folder_name, (CHAR*)L"..") == 0)
    {
        /* call set parent folder routine */
        ASSERT(res);
        OslFreeDataPtr(res);
        srv_ftps_set_parent_folder();
        return;
    }
    /* current folder */
    else
    {
        res->rsp_code = GOEP_STATUS_SUCCESS;
        goto FTPS_SET_FOLDER_SEND;
    }

FTPS_SET_FOLDER_SEND:
    srv_ftp_send_msg(MSG_ID_GOEP_SET_FOLDER_RES, res);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_set_parent_folder
 * DESCRIPTION
 *  This function is to set current folder to parent folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftps_set_parent_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_set_folder_res_struct *res;
    S32 NameLength;
    U16 *UniPathName = 0; 
    U16 deter = '\\';

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_SET_PARENT_FOLDER, ftps_cntx_p->goep_conn_id);

    res = (goep_set_folder_res_struct*)OslConstructDataPtr(sizeof(goep_set_folder_res_struct));
    FTP_MEMSET(res);
    res->goep_conn_id = ftps_cntx_p->goep_conn_id;

    NameLength = mmi_ucs2strlen((CHAR*)(act_server_cntx_p->current_folder));
    UniPathName = get_ctrl_buffer((NameLength + 1) * ENCODING_LENGTH);
    mmi_ucs2cpy((CHAR*)UniPathName, (CHAR*)(act_server_cntx_p->current_folder));

    /* UniPathName+i points to the (i+1)th ascii code in path --> minus one first */
    NameLength--;
    while (NameLength > 0)
    {
        /* search from tail by cutting the last ascii code step by step */
        NameLength--;
        if (memcmp((UniPathName + NameLength), &deter, 2) == 0)
        {
            /* Cut the current folder path to become parent folder path */
            memset((UniPathName + NameLength + 1), 0, 2);
            break;
        }
    }

    mmi_ucs2cpy((CHAR*)(act_server_cntx_p->current_folder), (CHAR*)UniPathName);
    act_server_cntx_p->ftps_browse_depth--;
    res->rsp_code = GOEP_STATUS_SUCCESS;
    
    if (UniPathName)
    {
        free_ctrl_buffer(UniPathName);
    }
    srv_ftp_send_msg(MSG_ID_GOEP_SET_FOLDER_RES, res);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_pull_continue
 * DESCRIPTION
 *  This function is to keeping sending the pending object requested from client
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftps_pull_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 len_read;
    goep_pull_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_PULL_CONTINUE, ftps_cntx_p->goep_conn_id);

    ret = FS_Read(act_server_cntx_p->fh_ftps_send,
                  act_server_cntx_p->ftps_obj_buff,
                  act_server_cntx_p->send_obex_pkt_size,
                  (kal_uint32*)&len_read);
    if (ret < 0)
    {
        SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
        
        FS_Close(act_server_cntx_p->fh_ftps_send);
        act_server_cntx_p->total_send_obj_len = 0;
        act_server_cntx_p->remain_send_obj_len = 0;
        act_server_cntx_p->fh_ftps_send = 0;

        if (act_server_cntx_p->send_obj_type == SRV_FTP_OBJ_TYPE_FOLDER)
        {
            FS_Delete((const WCHAR*)(act_server_cntx_p->folder_content));
        }
        act_server_cntx_p->send_obj_type = SRV_FTP_OBJ_TYPE_NONE;

        res = (goep_pull_res_struct*)OslConstructDataPtr(sizeof(goep_pull_res_struct));
        FTP_MEMSET(res);
        res->goep_conn_id = ftps_cntx_p->goep_conn_id;
        res->rsp_code = GOEP_INTERNAL_SERVER_ERR;
        srv_ftp_send_msg(MSG_ID_GOEP_PULL_RES, res);
        return;
    }

    /* Finished reading */
    if (len_read == act_server_cntx_p->remain_send_obj_len)
    {
        SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);

        FS_Close(act_server_cntx_p->fh_ftps_send);
        act_server_cntx_p->total_send_obj_len = 0;
        act_server_cntx_p->remain_send_obj_len = 0;
        act_server_cntx_p->fh_ftps_send = 0;

        if (act_server_cntx_p->send_obj_type == SRV_FTP_OBJ_TYPE_FOLDER)
        {
            FS_Delete((const WCHAR*)(act_server_cntx_p->folder_content));
        }
        act_server_cntx_p->send_obj_type = SRV_FTP_OBJ_TYPE_NONE;

        res = (goep_pull_res_struct*)OslConstructDataPtr(sizeof(goep_pull_res_struct));
        FTP_MEMSET(res);
        res->pkt_type = GOEP_FINAL_PKT;
    }
    else if (len_read < act_server_cntx_p->remain_send_obj_len) /* continue transferring */
    {
        act_server_cntx_p->remain_send_obj_len -= len_read;      

        res = (goep_pull_res_struct*)OslConstructDataPtr(sizeof(goep_pull_res_struct));
        FTP_MEMSET(res);
        res->pkt_type = GOEP_NORMAL_PKT;
    }
    else /* abnormal case */
    {
        ASSERT(0);
        return;
    }

    res->goep_conn_id = ftps_cntx_p->goep_conn_id;
    res->frag_len = len_read;
    res->frag_ptr = act_server_cntx_p->ftps_obj_buff;
    res->total_obj_len = 0;
    res->rsp_code = GOEP_STATUS_SUCCESS;

    srv_ftp_send_msg(MSG_ID_GOEP_PULL_RES, res);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_send_obj
 * DESCRIPTION
 *  This function is to send the obj requested from client
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftps_send_obj(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_pull_res_struct *res;
    S32 ret;
    kal_uint32 fileSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_SEND_OBJ, ftps_cntx_p->goep_conn_id);

    /* Reset the context first */
    act_server_cntx_p->total_send_obj_len = 0;
    act_server_cntx_p->remain_send_obj_len = 0;
    ret = FS_GetFileSize(act_server_cntx_p->fh_ftps_send, &fileSize);
    if (ret != FS_NO_ERROR)
    {
        res = (goep_pull_res_struct*)OslConstructDataPtr(sizeof(goep_pull_res_struct));
        FTP_MEMSET(res);
        res->goep_conn_id = ftps_cntx_p->goep_conn_id;
        res->rsp_code = GOEP_INTERNAL_SERVER_ERR;
        srv_ftp_send_msg(MSG_ID_GOEP_PULL_RES, res);

        SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
        return;
    }
    
    if (fileSize > 0) /* not empty obj */
    {
        /* goep can't handle first res pkt with data */
        act_server_cntx_p->total_send_obj_len   = fileSize;
        act_server_cntx_p->remain_send_obj_len = fileSize;
        act_server_cntx_p->send_obj_type = SRV_FTP_OBJ_TYPE_FILE;

        res = (goep_pull_res_struct*)OslConstructDataPtr(sizeof(goep_pull_res_struct));
        FTP_MEMSET(res);
        res->pkt_type = GOEP_FIRST_PKT;
        res->goep_conn_id = ftps_cntx_p->goep_conn_id;
        res->frag_len = 0;
        res->frag_ptr = act_server_cntx_p->ftps_obj_buff;
        res->total_obj_len = fileSize;
        res->rsp_code = GOEP_STATUS_SUCCESS;
    }
    else /* Empty body */
    {
        res = (goep_pull_res_struct*)OslConstructDataPtr(sizeof(goep_pull_res_struct));
        FTP_MEMSET(res);     
        res->pkt_type = GOEP_SINGLE_PKT;
        res->goep_conn_id = ftps_cntx_p->goep_conn_id;
        res->frag_len = 0;
        res->frag_ptr = act_server_cntx_p->ftps_obj_buff;
        res->total_obj_len = 0;
        res->rsp_code = GOEP_STATUS_SUCCESS;

        FS_Close(act_server_cntx_p->fh_ftps_send);
        act_server_cntx_p->fh_ftps_send = (FS_HANDLE)NULL;

        SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
    }
    srv_ftp_send_msg(MSG_ID_GOEP_PULL_RES, res);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_send_folder_content
 * DESCRIPTION
 *  This function is to send the folder content requested from client
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftps_send_folder_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h;
    goep_pull_res_struct *res;
    S32 ret;
    kal_uint32 fileSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_SEND_FOLDER_CONTENT, ftps_cntx_p->goep_conn_id);

    /* Reset the context first */
    act_server_cntx_p->total_send_obj_len = 0;
    act_server_cntx_p->remain_send_obj_len = 0;

    /* open the default folder content file */
    h = FS_Open((const WCHAR*)(act_server_cntx_p->folder_content), FS_READ_ONLY);
    if (h < 0)
    {
        MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_SEND_FOLDER_CONTENT_OPEN_ERROR);
        goto FTPS_SEND_FOLDER_CONTENT_ERR;
    }
    else
    {
        act_server_cntx_p->fh_ftps_send = h;
    }

    ret = FS_GetFileSize(h, &fileSize);
    if (fileSize > 0) /* not empty folder content */
    {
        /* goep can't handle first res pkt with data */
        act_server_cntx_p->total_send_obj_len = fileSize;
        act_server_cntx_p->remain_send_obj_len = fileSize;
        act_server_cntx_p->send_obj_type = SRV_FTP_OBJ_TYPE_FOLDER;

        res = (goep_pull_res_struct*)OslConstructDataPtr(sizeof(goep_pull_res_struct));
        FTP_MEMSET(res);
        res->pkt_type = GOEP_FIRST_PKT;
        res->total_obj_len = fileSize;
    }
    else /* Empty body */
    {
        res = (goep_pull_res_struct*)OslConstructDataPtr(sizeof(goep_pull_res_struct));
        FTP_MEMSET(res);
        res->pkt_type = GOEP_FINAL_PKT;
        res->total_obj_len = 0;
        SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
        if (act_server_cntx_p->fh_ftps_send)
        {
            FS_Close(act_server_cntx_p->fh_ftps_send);
            act_server_cntx_p->fh_ftps_send = (FS_HANDLE)NULL;
        }
        
        FS_Delete((const WCHAR*)(act_server_cntx_p->folder_content));
    }

    strcpy((CHAR*)res->obj_mime_type, "x-obex/folder-listing");
    res->goep_conn_id = ftps_cntx_p->goep_conn_id;
    res->frag_ptr = act_server_cntx_p->ftps_obj_buff;
    res->frag_len = 0;
    res->rsp_code = GOEP_STATUS_SUCCESS;
    srv_ftp_send_msg(MSG_ID_GOEP_PULL_RES, res);
    return;

FTPS_SEND_FOLDER_CONTENT_ERR:
    FS_Delete((const WCHAR*)(act_server_cntx_p->folder_content));
    SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);

    res = (goep_pull_res_struct*)OslConstructDataPtr(sizeof(goep_pull_res_struct));
    FTP_MEMSET(res);
    res->goep_conn_id = ftps_cntx_p->goep_conn_id;
    res->rsp_code = GOEP_INTERNAL_SERVER_ERR;
    strcpy((CHAR*)res->obj_mime_type, "x-obex/folder-listing");
    srv_ftp_send_msg(MSG_ID_GOEP_PULL_RES, res);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_gen_folder_content
 * DESCRIPTION
 *  This function is to generate the folder content requested from client
 * PARAMETERS
 *  folder_name     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftps_gen_folder_content(PU8 folder_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ftp_file_writer_struct *composer = &(act_server_cntx_p->xml_composer);
    FS_DOSDirEntry fs_file_info;
    WCHAR *file_name = (WCHAR*)act_server_cntx_p->ftps_obj_name;
    S32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_GEN_FOLDER_CONTENT);
    memset(&fs_file_info, 0, sizeof(FS_DOSDirEntry));
    memset(composer, 0, sizeof(srv_ftp_file_writer_struct));
    composer->buflen += sprintf(composer->buf + composer->buflen, "<?xml version=\"1.0\"?>\n");
    composer->buflen += sprintf(composer->buf + composer->buflen, 
                                "<!DOCTYPE folder-listing SYSTEM \"obex-folder-listing.dtd\">\n");
    composer->buflen += sprintf(composer->buf + composer->buflen, "<folder-listing version=\"1.0\">\n");
    composer->buflen += sprintf(composer->buf + composer->buflen, "<parent-folder />\n");
    mmi_ucs2cat((CHAR*)folder_name, (CHAR*)L"*.*"); /* which means the files in folder "folder_path" */
    composer->fd = FS_Open((const WCHAR*)(act_server_cntx_p->folder_content), FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (composer->fd < 0)
    {
        srv_ftps_gen_folder_content_error_handle();
        return;
    }

    /* if there is the file info -> write content */
    if ((act_server_cntx_p->fh_ftps_generating = FS_FindFirst((WCHAR*)folder_name,
                                                              0,
                                                              0,
                                                              &fs_file_info,
                                                              file_name,
                                                              SRV_FTPS_MAX_OBJ_NAME_LEN)) >= 0)
    {
        result = srv_ftps_write_folder_content(&fs_file_info);
        if (result < 0)
        {
            srv_ftps_gen_folder_content_error_handle();
            return;
        }
        else if (result > SRV_FTPS_MAX_PARSE_FILE_INFO_NUMBER)
        {
            SetProtocolEventHandler( srv_ftps_gen_folder_content_continue, MSG_ID_MMI_BT_FTPS_GEN_FOLDER_CONTINUE);
            srv_ftps_send_gen_folder_continue();
            return;
        }

        FS_FindClose(act_server_cntx_p->fh_ftps_generating);
    }

    result = srv_ftps_compose_end_element(composer);
    if (result < 0)
    {
        srv_ftps_gen_folder_content_error_handle();
    }
    
    FS_Close(composer->fd);
    srv_ftps_send_folder_content();
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_gen_root_content
 * DESCRIPTION
 *  This function is to generate the default root content requested from client
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftps_gen_root_content(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ftp_file_writer_struct *composer = &(act_server_cntx_p->xml_composer);
    U8 drv_array[SRV_FMGR_DRV_TOTAL];
    U8 drv_num, i;
    SRV_FMGR_DRVLIST_HANDLE drvlist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_GEN_ROOT_CONTENT);
    memset(composer, 0, sizeof(srv_ftp_file_writer_struct));

    composer->buflen += sprintf(composer->buf + composer->buflen, "<?xml version=\"1.0\"?>\n");
    composer->buflen += sprintf(composer->buf + composer->buflen, "<!DOCTYPE folder-listing SYSTEM \"obex-folder-listing.dtd\">\n");
    composer->buflen += sprintf(composer->buf + composer->buflen, "<folder-listing version=\"1.0\">\n");

    composer->fd = FS_Open((const WCHAR*)(act_server_cntx_p->folder_content), FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (composer->fd >= 0)
    {
        drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY);
        drv_num = (U8)srv_fmgr_drivelist_count(drvlist);
        for (i = 0; i < drv_num; ++i)
        {
            drv_array[i] = srv_fmgr_drivelist_get_drv_letter(drvlist, i);
        }
        srv_fmgr_drivelist_destroy(drvlist);

        for (i = 0; i < drv_num; i++)
        {
            composer->buflen += sprintf(composer->buf + composer->buflen, "\t<folder name=\"%c:\"/>\n", drv_array[i]);
        }

        if (srv_ftps_compose_end_element(composer) >= 0)
        {
            FS_Close(composer->fd);
            srv_ftps_send_folder_content();
            return;
        }
    }

    srv_ftps_gen_folder_content_error_handle(); /* open file or write file wrong */
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_writer_put_data
 * DESCRIPTION
 *  This function is to compose 
 * PARAMETERS
 *  composer
 *  data
 *  len
 * RETURNS
 *  The result of composing the folder attributes
 *****************************************************************************/
static S32 srv_ftps_writer_put_data(srv_ftp_file_writer_struct *composer, U8* data, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len > SRV_FTP_MAX_FILE_WRITER_BUF_SIZE)
    {
        return srv_ftps_writer_flush(composer, data);
    }
    else if (len + composer->buflen > SRV_FTP_MAX_FILE_WRITER_BUF_SIZE)
    {
        ret = srv_ftps_writer_flush(composer, NULL);
        memcpy(composer->buf + composer->buflen, data, len);
        composer->buflen = len;
        return ret;
    }
    else
    {
        memcpy(composer->buf + composer->buflen, data, len);
        composer->buflen += len;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_writer_put_str
 * DESCRIPTION
 *  This function is to compose 
 * PARAMETERS
 *  composer        [?]     [?]
 *  data            [?]     [?]
 * RETURNS
 *  The result of composing the folder attributes
 *****************************************************************************/
static S32 srv_ftps_writer_put_str(srv_ftp_file_writer_struct *composer, U8* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len = strlen((char*)data);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_ftps_writer_put_data(composer, data, len);    
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_compose_write_ucs2_name
 * DESCRIPTION
 *  This function is to compose 
 * PARAMETERS
 *  composer        [?]     [?]
 *  name            [?]     [?]
 * RETURNS
 *  The result of composing the folder attributes
 *****************************************************************************/
static S32 srv_ftps_compose_write_ucs2_name(srv_ftp_file_writer_struct *composer, const U8 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0, i = 0;
    kal_int32 utf8_len;
    kal_uint8 utf8_buf[6];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (name[i] || name[i + 1])
    {
        utf8_len = mmi_chset_ucs2_to_utf8(utf8_buf, (kal_uint16)((name[i + 1] << 8) | name[i]));
        utf8_buf[utf8_len] = 0; /* utf8_len always be 1, 2, or 3 */

        if (utf8_len == 1)
        {
            switch (utf8_buf[0])
            {
                case '<':
                    ret = srv_ftps_writer_put_str(composer, (U8*)"&lt;");
                    break;

                case '>':
                    ret = srv_ftps_writer_put_str(composer, (U8*)"&gt;");
                    break;

                case '&':
                    ret = srv_ftps_writer_put_str(composer, (U8*)"&amp;");
                    break;

                case '\'':
                    ret = srv_ftps_writer_put_str(composer, (U8*)"&apos;");
                    break;

                case '\"':
                    ret = srv_ftps_writer_put_str(composer, (U8*)"&quot;");
                    break;

                default:
                    ret = srv_ftps_writer_put_str(composer, utf8_buf);
                    break;
            }
        }
        else
        {
            ret = srv_ftps_writer_put_str(composer, utf8_buf);
        }

        if (ret)
        {
            return ret;
        }
        i += 2;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_compose_folder_element
 * DESCRIPTION
 *  This function is to compose the folder attributes
 * PARAMETERS
 *  composer        [?]     [?]
 *  file_info       [?]     [?]
 * RETURNS
 *  The result of composing the folder attributes
 *****************************************************************************/
static S32 srv_ftps_compose_folder_element(srv_ftp_file_writer_struct *composer, srv_ftp_obj_info_struct *file_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    CHAR buf[100];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* not root folder and not parent folder */
    if ((mmi_ucs2cmp((CHAR*)file_info->file_name, (CHAR*)L".") == 0) ||
        (mmi_ucs2cmp((CHAR*)file_info->file_name, (CHAR*)L"..") == 0))
    {
        return 0;
    }

    ret = srv_ftps_writer_put_str(composer, (U8*)"\t<folder name=\"");
    if (ret == 0) /* success */
    {
        ret = srv_ftps_compose_write_ucs2_name(composer, file_info->file_name);
        if (ret == 0) /* success */
        {
            sprintf(buf,
                    "\" created=\"%04d%02d%02dT%02d%02d%02dZ\"/>\n",
                    file_info->year,
                    file_info->month,
                    file_info->day,
                    file_info->hour,
                    file_info->min,
                    file_info->sec);    
            ret = srv_ftps_writer_put_str(composer, (U8*)buf);    
        }
    }
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_compose_file_element
 * DESCRIPTION
 *  This function is to compose the file attributes
 * PARAMETERS
 *  composer        [?]     [?]
 *  file_info       [?]     [?]
 * RETURNS
 *  The result of composing the file attributes
 *****************************************************************************/
static S32 srv_ftps_compose_file_element(srv_ftp_file_writer_struct *composer,
                                            srv_ftp_obj_info_struct *file_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    CHAR buf[100];
    //U8 access_right = (U8)mmi_bt_get_setting_int(BTFF_ITEM_FTP_ACCESS);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_ftps_writer_put_str(composer, (U8*)"\t<file name=\"");
    if (ret == 0) /* success */
    {
        ret = srv_ftps_compose_write_ucs2_name(composer, file_info->file_name);
        if (ret == 0) /* success */
        {
            sprintf(buf,
                    "\" modified=\"%04d%02d%02dT%02d%02d%02dZ\" size=\"%d\" user-perm=\"%s\"/>\n",
                    file_info->year,
                    file_info->month,
                    file_info->day,
                    file_info->hour,
                    file_info->min,
                    file_info->sec,
                    file_info->file_size,
                    (ftps_cntx_p->access_right == SRV_FTPS_PERMISSION_READ_ONLY) ? "R" : "RWD");
                    //access_right ? "R" : "RWD");
            ret = srv_ftps_writer_put_str(composer, (U8*)buf);
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_compose_end_element
 * DESCRIPTION
 *  This function is to compose the end tag
 * PARAMETERS
 *  composer
 * RETURNS
 *  The result of composing the end tag
 *****************************************************************************/
static S32 srv_ftps_compose_end_element(srv_ftp_file_writer_struct *composer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_COMPOSE_END_ELEMENT);
    ret = srv_ftps_writer_put_str(composer, (U8*)"</folder-listing>");
    if (ret)
    {
        return ret;
    }
    
    return srv_ftps_writer_flush(composer, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_set_fs_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftps_set_fs_flag(S32 ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_SET_FS_FLAG, ret);
    ftps_cntx_p->ftps_flag = 0;
    if (ret == FS_ROOT_DIR_FULL)
    {
        MMI_FTPS_SET_FLAG(SRV_FTP_MASK_ROOT_DIR_FULL);
    }
    else if (ret == FS_DISK_FULL)
    {
        MMI_FTPS_SET_FLAG(SRV_FTP_MASK_DISK_FULL);
    }
    else if (ret == FS_DEVICE_EXPORTED_ERROR)
    {
        MMI_FTPS_SET_FLAG(SRV_FTP_MASK_DEVICE_EXPORTED);
    }
    else if (ret == FS_DEVICE_BUSY)
    {
        MMI_FTPS_SET_FLAG(SRV_FTP_MASK_FS_DEVICE_BUSY);
    }
    else if (ret == FS_LOCK_MUTEX_FAIL)
    {
        MMI_FTPS_SET_FLAG(SRV_FTP_MASK_FS_LOCK_MUTEX_FAIL);
    }
    else if (ret == FS_MEDIA_CHANGED
             ||ret == FS_MSDC_MOUNT_ERROR
             ||ret == FS_MSDC_PRESNET_NOT_READY
             ||ret == FS_MSDC_NOT_PRESENT
             ||ret == FS_MSDC_READ_SECTOR_ERROR
             ||ret == FS_MSDC_WRITE_SECTOR_ERROR
             ||ret == FS_MSDC_DISCARD_SECTOR_ERROR)

    {
        MMI_FTPS_SET_FLAG(SRV_FTP_MASK_FS_NO_CARD);
    }
    else if (ret == FS_WRITE_PROTECTION)
    {
        MMI_FTPS_SET_FLAG(SRV_FTP_MASK_FS_WRITE_PROTEC);
    }
    else
    {
        MMI_FTPS_SET_FLAG(SRV_FTP_MASK_WRITE_FILE_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_stop_receiving
 * DESCRIPTION
 *  when usb mass plug in, this func will be called
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftps_stop_receiving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_STOP_RECEIVING, act_server_cntx_p->ftps_state);
    switch (act_server_cntx_p->ftps_state)
    {
        case SRV_FTPS_STATE_RECEIVING:
            if (act_server_cntx_p->fh_ftps_recv)
            {
                FS_Close(act_server_cntx_p->fh_ftps_recv);
                act_server_cntx_p->fh_ftps_recv = (FS_HANDLE)NULL;
                MMI_FTPS_SET_FLAG(SRV_FTP_MASK_RESULT_FAIL);
            }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_send_push_res
 * DESCRIPTION
 *  This function is used to send a push_res to client
 * PARAMETERS
 *  goep_conn_id
 *  rsp_code
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftps_send_push_res(U8 goep_conn_id, U8 rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_push_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res = (goep_push_res_struct*)OslConstructDataPtr(sizeof(goep_push_res_struct));
    FTP_MEMSET(res);
    res->goep_conn_id = goep_conn_id;
    res->rsp_code = rsp_code;
    srv_ftp_send_msg(MSG_ID_GOEP_PUSH_RES, res);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_get_current_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16* srv_ftps_get_current_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U16 out_path[16];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (act_server_cntx_p->ftps_browse_depth == 0)
    {
        kal_wsprintf((WCHAR*)out_path, "%c:\\", SRV_FMGR_PUBLIC_DRV);
        mmi_wcscat(out_path, (const U16*)SRV_FTPC_RECV_OBJ_FILEPATH);
        return out_path;
    }
    
    return act_server_cntx_p->current_folder;
}


#ifdef __MMI_BT_RX_ENHANCE__
/*****************************************************************************
 * FUNCTION
 *  srv_ftps_inbuf_write_obj_continue
 * DESCRIPTION
 *  This function is to write the file and set the error
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftps_inbuf_write_obj_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 len_written;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_PUSH_INBUF_CONTINUE);
    if (act_server_cntx_p->ftps_inbuf_len > 0)
    {
        ret = FS_Write(act_server_cntx_p->fh_ftps_recv,
                       act_server_cntx_p->ftps_obj_int_buff,
                       act_server_cntx_p->ftps_inbuf_len,
                       (kal_uint32*)&len_written);
        MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_PUSH_INBUF_CONTINUE_WRITE, ret);

        if (ret < 0)
        {
            srv_ftps_set_fs_flag(ret);
            FS_Close(act_server_cntx_p->fh_ftps_recv);
            act_server_cntx_p->fh_ftps_recv = (FS_HANDLE)NULL;

            /* this error will be checked in the next packet */
            act_server_cntx_p->ftps_inbuf_pkt_error = SRV_FTP_PRE_PKT_ERR_FS;
        }
    }
}
#endif /* __MMI_BT_RX_ENHANCE__ */


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_sdp_register_cnf_handle
 * DESCRIPTION
 *  This function is to handle SDP REGISTER CNF msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_ftps_sdp_register_cnf_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_sdpdb_register_cnf_struct *cnf = (bt_sdpdb_register_cnf_struct*)msg;
    srv_ftps_start_indication_struct start_ind;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_SDP_REGISTER_CNF_HANDLE, cnf->result);
    if (cnf->uuid == SRV_BT_CM_OBEX_FILE_TRANSFER_UUID)
    {
        if (cnf->result == 0x00) /* SDP register success */
        {
            srv_bt_cm_activate_cnf_hdler(SRV_BT_CM_OBEX_FILE_TRANSFER_UUID);

            start_ind.result = SRV_FTPS_START_OK;
            srv_ftps_notify(SRV_FTPS_EVENT_START, (void*)&start_ind);
        }
        else /* SDP register failed */
        {
            ASSERT(0);
        }
        
        return 1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_sdp_deregister_cnf_handle
 * DESCRIPTION
 *  This function is to handle SDP REGISTER CNF msg
 * PARAMETERS
 *  msg
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_ftps_sdp_deregister_cnf_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_sdpdb_deregister_cnf_struct *cnf = (bt_sdpdb_deregister_cnf_struct*)msg;
    goep_deregister_server_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* deregister the goep connections */
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_SDP_DEREGISTER_CNF_HANDLE, act_server_cntx_p->ftps_state);
    if (cnf->uuid == SRV_BT_CM_OBEX_FILE_TRANSFER_UUID)
    {
        if (cnf->result != 0x00)
        {
            ASSERT(0);
        }

        switch (act_server_cntx_p->ftps_state)
        {
            /* can't deactivate twice */
        case SRV_FTPS_STATE_DEACTIVATING:
            SRV_FTPS_LOG_STATE_ERR();
            ASSERT(0);
            break;
            /* do nothing (handle this case in disconnecting rsp) */
        case SRV_FTPS_STATE_DISCONNECTING:
            SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_DEACTIVATING);
            break;
            /* states with active connection */
        case SRV_FTPS_STATE_ACTIVE:
            //Connection sync to RFCOMM channel == Authorize
            //both accept and reject will send disconnect req to goep
            if (ftps_cntx_p->g_conn_id == 0xFF)
            {
                SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_DEACTIVATING);
                req =(goep_deregister_server_req_struct*)OslConstructDataPtr(sizeof(goep_deregister_server_req_struct));
                FTP_MEMSET(req);
                req->goep_conn_id = ftps_cntx_p->goep_conn_id;
                srv_ftp_send_msg(MSG_ID_GOEP_DEREGISTER_SERVER_REQ, req);
                break;
            }

        case SRV_FTPS_STATE_ACCEPTED:
        case SRV_FTPS_STATE_RECEIVING:
        case SRV_FTPS_STATE_SENDING:
            SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_DEACTIVATING);
            srv_ftps_disconnect_conn(ftps_cntx_p->conn_id);
            break;

        case SRV_FTPS_STATE_IDLE:
            break;
            
        default: /* other states without connection */
            SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_DEACTIVATING);
            req =(goep_deregister_server_req_struct*)OslConstructDataPtr(sizeof(goep_deregister_server_req_struct));
            FTP_MEMSET(req);
            req->goep_conn_id = ftps_cntx_p->goep_conn_id;
            srv_ftp_send_msg(MSG_ID_GOEP_DEREGISTER_SERVER_REQ, req);
            break;
        }

        return 1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_register_server_rsp_handle
 * DESCRIPTION
 *  This function is to handle server REGISTER_RSP msg
 * PARAMETERS
 *  msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftps_register_server_rsp_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_register_server_rsp_struct *rsp = (goep_register_server_rsp_struct*)msg;
    bt_sdpdb_register_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_REGISTER_SERVER_RSP_HANDLE, act_server_cntx_p->ftps_state);
    switch (act_server_cntx_p->ftps_state)
    {
        case SRV_FTPS_STATE_REGISTERING:
            if (rsp->rsp_code == GOEP_STATUS_SUCCESS)
            {
                ftps_cntx_p->goep_conn_id = rsp->goep_conn_id;
                SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACTIVE);
            }
            else /* error handling */
            {
                SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_IDLE);
                ASSERT(0);
            }
            break;

        case SRV_FTPS_STATE_IDLE:
            return;

        default:
            SRV_FTPS_LOG_STATE_ERR();
            ASSERT(0);
            break;
    }

    /* if there is connection wating for register response don't register SDP */
    if (act_server_cntx_p->ftps_state == SRV_FTPS_STATE_REGISTERING)
    {
        return;
    }

    req = (bt_sdpdb_register_req_struct*)OslConstructDataPtr(sizeof(bt_sdpdb_register_req_struct));
    FTP_MEMSET(req);
    req->uuid = (U32)SRV_BT_CM_OBEX_FILE_TRANSFER_UUID;
    srv_ftp_send_msg(MSG_ID_BT_SDPDB_REGISTER_REQ, req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_deregister_server_rsp_handle
 * DESCRIPTION
 *  This function is to handle server DEREGISTER_RSP msg
 * PARAMETERS
 *  msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftps_deregister_server_rsp_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_deregister_server_rsp_struct *rsp = (goep_deregister_server_rsp_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_DEREGISTER_SERVER_RSP_HANDLE, act_server_cntx_p->ftps_state);
    switch (rsp->rsp_code)
    {
        case GOEP_STATUS_SUCCESS:
            break;

        default:
            //ASSERT(0);
            break;
    }

    switch (act_server_cntx_p->ftps_state)
    {
        case SRV_FTPS_STATE_DEACTIVATING:
            SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_IDLE); /* don't have to reset context */
            break;

        default:
            SRV_FTPS_LOG_STATE_ERR();
            //ASSERT(0);
            return;
    }

    srv_bt_cm_deactivate_cnf_hdler(SRV_BT_CM_OBEX_FILE_TRANSFER_UUID);

    /* if there is any connection wating for deregister response? */
    if (act_server_cntx_p->ftps_state == SRV_FTPS_STATE_DEACTIVATING)
    {
        return;
    }
    srv_ftps_notify(SRV_FTPS_EVENT_STOP, NULL);
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_connect_ind_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
void srv_ftps_connect_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_connect_ind_struct *ind = (goep_connect_ind_struct*)msg;
    goep_connect_res_struct *res;
    goep_disconnect_req_struct *req;
    srv_ftps_connect_indication_struct conn_ind;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check the bd_addr correctness (authorize one == connecting one) */
    if (memcmp(&((act_server_cntx_p->ftps_bt_device).lap), &(ind->bd_addr.lap), 4) ||
        memcmp(&((act_server_cntx_p->ftps_bt_device).uap), &(ind->bd_addr.uap), 1) ||
        memcmp(&((act_server_cntx_p->ftps_bt_device).nap), &(ind->bd_addr.nap), 2))
    {
        ASSERT(0);
    }

    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_CONNECT_IND_HANDLE, act_server_cntx_p->ftps_state);
    switch (act_server_cntx_p->ftps_state)
    {
        case SRV_FTPS_STATE_ACTIVE: /* correct state to accept the authorize ind */
            {
                SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
                act_server_cntx_p->ftps_browse_depth = 0;

                /* check the max transfer unit size */
                if (ind->peer_mru < SRV_FTPS_MEM_BUFF_SIZE)
                {
                    act_server_cntx_p->send_obex_pkt_size = ind->peer_mru;
                }
                else
                {
                    act_server_cntx_p->send_obex_pkt_size = SRV_FTPS_MEM_BUFF_SIZE;
                }

                res = (goep_connect_res_struct*)OslConstructDataPtr(sizeof(goep_connect_res_struct));
                FTP_MEMSET(res);
                res->rsp_code = GOEP_STATUS_SUCCESS;
                res->goep_conn_id = ftps_cntx_p->goep_conn_id;
                srv_ftp_send_msg(MSG_ID_GOEP_CONNECT_RES, res);

                /* update ftps context */
                ftps_cntx_p->g_conn_id = ind->cm_conn_id;

                if (ftps_cntx_p->conn_id > 0)
                {
                    srv_bt_cm_connect_ind(ftps_cntx_p->conn_id);
                }

                conn_ind.bd_address = act_server_cntx_p->ftps_bt_device;
                conn_ind.cm_conn_id = ind->cm_conn_id;
                srv_ftps_notify(SRV_FTPS_EVENT_CONNECT, (void*)&conn_ind);
                return;
            }

        case SRV_FTPS_STATE_ACCEPTED: /* IVT IOT Cover */
            res = (goep_connect_res_struct*)OslConstructDataPtr(sizeof(goep_connect_res_struct));
            FTP_MEMSET(res);
            res->rsp_code = GOEP_CONFLICT;
            res->goep_conn_id = ftps_cntx_p->goep_conn_id;
            srv_ftp_send_msg(MSG_ID_GOEP_CONNECT_RES, res);
            SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_DISCONNECTING);

            req = (goep_disconnect_req_struct*)OslConstructDataPtr(sizeof(goep_disconnect_req_struct));
            FTP_MEMSET(req);
            req->goep_conn_id = ftps_cntx_p->goep_conn_id;
            srv_ftp_send_msg(MSG_ID_GOEP_DISCONNECT_REQ, req);
            return;

        default: /* wrong state */
            SRV_FTPS_LOG_STATE_ERR();
            ASSERT(0);
            return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_push_ind_handle
 * DESCRIPTION
 *  This function is to handle server PUSH_IND msg
 * PARAMETERS
 *  msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftps_push_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_push_ind_struct *ind = (goep_push_ind_struct*)msg;
    //S32 access_right = mmi_bt_get_setting_int(BTFF_ITEM_FTP_ACCESS);
    srv_ftps_operation_end_struct push_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_PUSH_IND_HANDLE, act_server_cntx_p->ftps_state);
    /* Check the access right first. If the access right is read only, return failed directly */
    //if (access_right == FTP_PERMISSION_READ_ONLY)
    if (ftps_cntx_p->access_right == SRV_FTPS_PERMISSION_READ_ONLY)
    {
        if (act_server_cntx_p->ftps_state == SRV_FTPS_STATE_RECEIVING)
        {
            SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
            if (act_server_cntx_p->fh_ftps_recv != (FS_HANDLE)NULL)
            {
                FS_Close(act_server_cntx_p->fh_ftps_recv);
                act_server_cntx_p->fh_ftps_recv = (FS_HANDLE)NULL;

                push_ind.operation = SRV_FTPS_OPERATION_PUSH;
                push_ind.result = SRV_FTP_MASK_RESULT_FAIL;
                srv_ftps_notify(SRV_FTPS_EVENT_OPERATION_END, (void*)&push_ind);
            }
        }

        srv_ftps_send_push_res(ftps_cntx_p->goep_conn_id, GOEP_UNAUTHORIZED);

        return;
    }

//     if (mmi_bt_receiving_disabled())
//     {
//         srv_ftps_send_push_res(ftps_cntx_p->goep_conn_id, GOEP_FORBIDDEN);
//         return;
//     }

    switch (act_server_cntx_p->ftps_state)
    {
        case SRV_FTPS_STATE_ACCEPTED:
            if ((ind->pkt_type == GOEP_FIRST_PKT) || (ind->pkt_type == GOEP_SINGLE_PKT))
            {
                if (ind->put_type == GOEP_PUT_DELETE)
                {
                    SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_RECEIVING);
                    /* call ftps push delete routine and send res to client */
                    srv_ftps_push_delete(ind);
                }
                else
                {
                    /*forbbiden 0 size normal file push for IVT IOT*/
                    if ((ind->frag_len == 0) && (ind->total_obj_len == 0)
                        && (ind->put_type == GOEP_PUT_NORMAL) && (ind->pkt_type == GOEP_SINGLE_PKT))
                    {
                        srv_ftps_send_push_res(ftps_cntx_p->goep_conn_id, GOEP_FORBIDDEN);
                        return;
                    }

                    hold_local_para((local_para_struct*)ind);
                    act_server_cntx_p->push_ind = ind;
                    SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_RECEIVING);
                    {
                        srv_ftps_operation_begin_struct push_begin_ind;

                        if (mmi_ucs2strlen((CHAR*)ind->obj_name) > 0)
                        {
                            srv_ftp_obj_name_swapcpy((CHAR*)ind->obj_name, (CHAR*)ind->obj_name);
                            srv_ftp_ucs2_cut_name_with_ext(
                                (CHAR*)act_server_cntx_p->ftps_obj_name,
                                SRV_FTPS_MAX_OBJ_NAME_LEN,
                                (CHAR*)ind->obj_name);
                        }
                        else /* put obj without carring name */
                        {
                            kal_wsprintf((WCHAR*)act_server_cntx_p->ftps_obj_name, "new.tmp");
                        }

                        push_begin_ind.operation = SRV_FTPS_OPERATION_PUSH;
                        push_begin_ind.result = SRV_FTP_MASK_RESULT_OK;
                        push_begin_ind.name_p = act_server_cntx_p->ftps_obj_name;
                        push_begin_ind.obj_total_size =
                            (ind->total_obj_len > 0 || (ind->total_obj_len == 0 && ind->frag_len == 0)) ?
                            ind->total_obj_len : /* total_size >= 0 */
                            0xFFFFFFFF;          /* no total_size */
                        srv_ftps_notify(SRV_FTPS_EVENT_OPERATION_BEGIN, (void*)&push_begin_ind);
                    }
                }
            }
            else
            {
                srv_ftps_send_push_res(ftps_cntx_p->goep_conn_id, GOEP_INTERNAL_SERVER_ERR);
            }
            return;

        case SRV_FTPS_STATE_RECEIVING: /* continue */
            /* can't support simultaneously receiving */
            if ((ind->pkt_type == GOEP_FIRST_PKT) || (ind->pkt_type == GOEP_SINGLE_PKT))
            {
                SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
                srv_ftps_send_push_res(ftps_cntx_p->goep_conn_id, GOEP_INTERNAL_SERVER_ERR);

                push_ind.operation = SRV_FTPS_OPERATION_PUSH;
                push_ind.result = SRV_FTP_MASK_RESULT_FAIL;
                srv_ftps_notify(SRV_FTPS_EVENT_OPERATION_END, (void*)&push_ind);
            }
            else
            {
                if (act_server_cntx_p->fh_ftps_recv == (FS_HANDLE)NULL)
                {
                    SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
                    srv_ftps_send_push_res(ftps_cntx_p->goep_conn_id, GOEP_FORBIDDEN);

                    push_ind.operation = SRV_FTPS_OPERATION_PUSH;
                    //push_ind.result = SRV_FTP_MASK_RESULT_FAIL;
                    push_ind.result = ftps_cntx_p->ftps_flag;
                    srv_ftps_notify(SRV_FTPS_EVENT_OPERATION_END, (void*)&push_ind);

                    ftps_cntx_p->ftps_flag = 0;
                    return;
                }

#ifdef __MMI_BT_RX_ENHANCE__
                /* From the 2nd pkt, the pkt handle will speed up if has internal buf (not included final pkt)*/
                if (act_server_cntx_p->ftps_inbuf_pkt_error == SRV_FTP_PRE_PKT_ERR_NONE)
                {
                    if (ind->pkt_type == GOEP_FINAL_PKT)
                    {
                        srv_ftps_write_obj_continue(ind);
                    }
                    else
                    {
                        /* 1. copy data to i buffer
                         * 2. send rsp with success
                         * 3. write from i buffer, and set the error flag
                         */
                        memcpy(act_server_cntx_p->ftps_obj_int_buff, ind->frag_ptr, ind->frag_len);
                        act_server_cntx_p->ftps_inbuf_len = ind->frag_len;
                        srv_ftps_send_push_res(ftps_cntx_p->goep_conn_id, GOEP_STATUS_SUCCESS);
                        srv_ftps_inbuf_write_obj_continue();
                    }
                }
                else /* error in the last packet */
                {
                    srv_ftps_operation_progess_struct push_ind;
                    
                    /* Omit this pkt, and do error handling */
                    SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
                    srv_ftps_send_push_res(ftps_cntx_p->goep_conn_id, GOEP_INTERNAL_SERVER_ERR);

                    push_ind.operation = SRV_FTPS_OPERATION_PUSH;
                    push_ind.result = ftps_cntx_p->ftps_flag;
                    srv_ftps_notify(SRV_FTPS_EVENT_OPERATION_END, (void*)&push_ind);

                    ftps_cntx_p->ftps_flag = 0;
                }
#else /* __MMI_BT_RX_ENHANCE__ */
                srv_ftps_write_obj_continue(ind);
#endif /* __MMI_BT_RX_ENHANCE__ */
                return;
            }
            return;

        case SRV_FTPS_STATE_SENDING:
            SRV_FTPS_LOG_STATE_ERR();
            SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
            srv_ftps_send_push_res(ftps_cntx_p->goep_conn_id, GOEP_INTERNAL_SERVER_ERR);
            return;
            
        /* discard this message */
        case SRV_FTPS_STATE_DEACTIVATING:
        case SRV_FTPS_STATE_DISCONNECTING:
            return;

        default: /* abnormal state */
            SRV_FTPS_LOG_STATE_ERR();
            ASSERT(0);
            return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_pull_ind_handle
 * DESCRIPTION
 *  This function is to handle server PULL_IND msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftps_pull_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h;
    U8 folder_listing_obj[GOEP_MAX_MIME_TYPE];
    U8 path_buf[(SRV_FMGR_PATH_MAX_LEN + 1 + 3) * ENCODING_LENGTH];
    goep_pull_ind_struct *ind = (goep_pull_ind_struct*)msg;
    goep_pull_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_PULL_IND_HANDLE, act_server_cntx_p->ftps_state, ind->pkt_type);
    strcpy((CHAR*)folder_listing_obj, "x-obex/folder-listing");
    switch (act_server_cntx_p->ftps_state)
    {
        case SRV_FTPS_STATE_ACCEPTED:
            if (mmi_ucs2strlen((CHAR*)ind->obj_name) > 0)
            {
                srv_ftp_obj_name_swapcpy((CHAR*)ind->obj_name, (CHAR*)ind->obj_name);
            }

            /* pull a file */
            if (strcmp((CHAR*)ind->obj_mime_type, (CHAR*)folder_listing_obj))
            {
                S32 j, len;

                mmi_ucs2cpy((CHAR*)path_buf, (CHAR*)act_server_cntx_p->current_folder);
                /* fail-safe for enough memory to store the obj_name + obj_path (1 = '\0') */
                if (mmi_ucs2strlen((CHAR*)path_buf) + mmi_ucs2strlen((CHAR*)ind->obj_name) > SRV_FMGR_PATH_MAX_LEN)
                {
                    srv_ftps_send_pull_error();
                    return;
                }

                len = mmi_ucs2strlen((CHAR*)ind->obj_name) * 2;
                for (j = 0; j < len; j += 2) /* switch '/' to '\' if necessary */
                {
                    /* '/' */
                    if (ind->obj_name[j] == 0x2F && ind->obj_name[j+1] == 0)
                    {
                        ind->obj_name[j] = 0x5C;
                    }
                    /* '\' */
                    else if (ind->obj_name[j] == 0x5C && ind->obj_name[j+1] == 0)
                    {
                        break;
                    }
                }
                mmi_ucs2cat((CHAR*)path_buf, (CHAR*)ind->obj_name);

#if defined(__DRM_SUPPORT__)
                /* drm check: if not allow to forward out */
                if (!DRM_interdev_movable(0, (kal_wchar*)path_buf))
                {
                    res = (goep_pull_res_struct*)OslConstructDataPtr(sizeof(goep_pull_res_struct));
                    FTP_MEMSET(res);
                    res->goep_conn_id = ftps_cntx_p->goep_conn_id;
                    res->rsp_code = GOEP_FORBIDDEN;

                    srv_ftp_send_msg(MSG_ID_GOEP_PULL_RES, res);
                    SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
                    return;
                }
#endif
                /* check does the obj exist? */
                h = FS_Open((kal_uint16*)path_buf, FS_READ_ONLY);
                if (h < 0)
                {
                    srv_ftps_send_pull_error();
                    return;
                }
                else
                {
                    act_server_cntx_p->fh_ftps_send = h;
                }

                SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_SENDING);
                srv_ftps_send_obj();
            }
            else /* pull a folder content */
            {
                if (act_server_cntx_p->ftps_browse_depth == 0) /* root folder */
                {
                    SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_SENDING);
                    srv_ftps_gen_root_content();
                }
                else /* non-root folder */
                {
                    mmi_ucs2cpy((CHAR*)path_buf, (CHAR*)act_server_cntx_p->current_folder);
                    /* fail-safe for enough memory to store the obj_name + obj_path (2 = '\','\0') */
                    if (mmi_ucs2strlen((CHAR*)path_buf) + mmi_ucs2strlen((CHAR*)ind->obj_name) > SRV_FMGR_PATH_MAX_LEN)
                    {
                        srv_ftps_send_pull_error();
                        return;
                    }

                    /* check if there is obj name carried by pull ind */
                    if (mmi_ucs2strlen((CHAR*)ind->obj_name) > 0)
                    {
                        mmi_ucs2cat((CHAR*)path_buf, (CHAR*)ind->obj_name);
                        mmi_ucs2cat((CHAR*)path_buf, (CHAR*)L"\\");
                    }

                    /* without carring folder name -> get current folder */
                    h = FS_Open((kal_uint16*)path_buf, FS_OPEN_DIR | FS_READ_ONLY);
                    if (h < 0)
                    {
                        FS_Delete((const WCHAR*)(act_server_cntx_p->folder_content));
                        srv_ftps_send_pull_error();
                        return;
                    }
                    FS_Close(h);

                    SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_SENDING);
                    srv_ftps_gen_folder_content(path_buf);
                }
            }
            return;

        case SRV_FTPS_STATE_SENDING: /* continue */
            if ((ind->pkt_type == GOEP_FIRST_PKT) || (ind->pkt_type == GOEP_SINGLE_PKT)) /* can't support simultaneously sending */
            {
                SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
                srv_ftps_send_pull_error();
            }
            else /* not another first req */
            {
                srv_ftps_pull_continue();
            }
            return;

        case SRV_FTPS_STATE_RECEIVING: /* wrong sequence msg incoming (error handling) */
            SRV_FTPS_LOG_STATE_ERR();
            SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
            srv_ftps_send_pull_error();
            return;

            /* discard this message */
        case SRV_FTPS_STATE_DEACTIVATING:
        case SRV_FTPS_STATE_DISCONNECTING:
            return;

        default: /* abnormal state */
            SRV_FTPS_LOG_STATE_ERR();
            /* ASSERT(0); */
            return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_set_folder_ind_handle
 * DESCRIPTION
 *  This function is to handle server SET_FOLDER_IND msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftps_set_folder_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_set_folder_ind_struct *ind = (goep_set_folder_ind_struct*)msg;
    goep_set_folder_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_SET_FOLDER_IND_HANDLE, act_server_cntx_p->ftps_state, ind->setpath_flag);
    /* check state for different resetting */
    switch (act_server_cntx_p->ftps_state)
    {
        /* normal case */
        case SRV_FTPS_STATE_ACCEPTED:
            /* name, back, root, create */
            if (ind->setpath_flag == GOEP_ROOT_FOLDER)
            {
                act_server_cntx_p->ftps_browse_depth = 0;
                //memset(act_server_cntx_p->current_folder, 0, (SRV_FMGR_PATH_MAX_LEN+1) * ENCODING_LENGTH);
                act_server_cntx_p->current_folder[0] = 0;
                goto FTPS_SET_FOLDER_SUCCESS;
            }
            else if (ind->setpath_flag == GOEP_BACK_FOLDER)
            {
                /* call set parent folder routine */
                srv_ftps_set_parent_folder();
                return;
            }
            else if (ind->setpath_flag == GOEP_FORWARD_FOLDER)
            {
                /* call set folder routine */
                srv_ftps_set_folder(ind);
                return;
            }
            else /* GOEP_CREATE_FOLDER */
            {
                /* call create folder routine */
                /* create folder and set current to new folder (should send res) */
                srv_ftps_create_folder(ind);
                return;
            }
        /* ignore conditions */
        case SRV_FTPS_STATE_DEACTIVATING:
        case SRV_FTPS_STATE_DISCONNECTING:
            /* do nothing */
            return;

        /* error recovery */
        case SRV_FTPS_STATE_SENDING:
            if (act_server_cntx_p->fh_ftps_send)
            {
                FS_Close(act_server_cntx_p->fh_ftps_send);
                act_server_cntx_p->total_send_obj_len = 0;
                act_server_cntx_p->remain_send_obj_len = 0;
                act_server_cntx_p->fh_ftps_send = 0;
            }
            if (act_server_cntx_p->send_obj_type == SRV_FTP_OBJ_TYPE_FOLDER)
            {
                FS_Delete((const WCHAR*)(act_server_cntx_p->folder_content));
            }
            act_server_cntx_p->send_obj_type = SRV_FTP_OBJ_TYPE_NONE;
            /* send res with error rsp_code and go back to accepted state */
            goto FTPS_SET_FOLDER_ERR;
            break;

        case SRV_FTPS_STATE_RECEIVING:
            if (act_server_cntx_p->fh_ftps_recv)
            {
                FS_Close(act_server_cntx_p->fh_ftps_recv);
                act_server_cntx_p->fh_ftps_recv = 0;
            }
            /* send res with error rsp_code and go back to accepted state */
            goto FTPS_SET_FOLDER_ERR;
            break;
            /* abnormal case (no connection yet -- wrong state) */
        default:
            SRV_FTPS_LOG_STATE_ERR();
            ASSERT(0);
            return;
    }
FTPS_SET_FOLDER_SUCCESS:
    res = (goep_set_folder_res_struct*)OslConstructDataPtr(sizeof(goep_set_folder_res_struct));
    FTP_MEMSET(res);
    res->goep_conn_id = ftps_cntx_p->goep_conn_id;
    res->rsp_code = GOEP_STATUS_SUCCESS;
    srv_ftp_send_msg(MSG_ID_GOEP_SET_FOLDER_RES, res);
    return;

FTPS_SET_FOLDER_ERR:
    res = (goep_set_folder_res_struct*)OslConstructDataPtr(sizeof(goep_set_folder_res_struct));
    FTP_MEMSET(res);
    res->goep_conn_id = ftps_cntx_p->goep_conn_id;
    res->rsp_code = GOEP_INTERNAL_SERVER_ERR;
    srv_ftp_send_msg(MSG_ID_GOEP_SET_FOLDER_RES, res);
    SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftps_abort_ind_handle
 * DESCRIPTION
 *  This function is to handle server ABORT_IND msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftps_abort_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_abort_ind_struct *ind = (goep_abort_ind_struct*)msg;
    goep_abort_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_ABORT_IND_HANDLE, act_server_cntx_p->ftps_state);
    /* check state for different resetting */
    switch (act_server_cntx_p->ftps_state)
    {
        case SRV_FTPS_STATE_SENDING:
            if (act_server_cntx_p->fh_ftps_send)
            {
                FS_Close(act_server_cntx_p->fh_ftps_send);
                act_server_cntx_p->total_send_obj_len = 0;
                act_server_cntx_p->remain_send_obj_len = 0;
                act_server_cntx_p->fh_ftps_send = 0;
            }
            if (act_server_cntx_p->send_obj_type == SRV_FTP_OBJ_TYPE_FOLDER)
            {
                FS_Delete((const WCHAR*)(act_server_cntx_p->folder_content));
            }
            act_server_cntx_p->send_obj_type = SRV_FTP_OBJ_TYPE_NONE;
            break;

        case SRV_FTPS_STATE_RECEIVING:
            if (act_server_cntx_p->fh_ftps_recv)
            {
                srv_ftps_operation_end_struct push_ind;

                FS_Close(act_server_cntx_p->fh_ftps_recv);
                act_server_cntx_p->fh_ftps_recv = (FS_HANDLE)NULL;

                push_ind.operation = SRV_FTPS_OPERATION_PUSH;
                push_ind.result = SRV_FTP_MASK_RESULT_FAIL;
                srv_ftps_notify(SRV_FTPS_EVENT_OPERATION_END, (void*)&push_ind);
            }
            break;

        /* ignore conditions (for race condition) */
        case SRV_FTPS_STATE_ACCEPTED:
            break;

        case SRV_FTPS_STATE_DEACTIVATING:
        case SRV_FTPS_STATE_DISCONNECTING:
            return;
 
        default: /* error recovery */
            SRV_FTPS_LOG_STATE_ERR();
            ASSERT(0);
            break;
    }

    SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
    res = (goep_abort_res_struct*)OslConstructDataPtr(sizeof(goep_abort_res_struct));
    FTP_MEMSET(res);
    res->goep_conn_id = ind->goep_conn_id;
    res->rsp_code = GOEP_STATUS_SUCCESS;
    srv_ftp_send_msg(MSG_ID_GOEP_ABORT_RES, res);
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_authorize_ind_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
void srv_ftps_authorize_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_authorize_ind_struct *ind = (goep_authorize_ind_struct*)msg;
    srv_ftps_authorize_indication_struct authorize_ind;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_AUTHORIZE_IND_HANDLE, act_server_cntx_p->ftps_state);

    /* for MMI knows the authorizing one */
    ftps_cntx_p->cur_goep_conn_id = ind->goep_conn_id;

    switch (act_server_cntx_p->ftps_state)
    {
        case SRV_FTPS_STATE_ACTIVE: /* correct state to accept the authorize ind */
            SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_AUTHORIZING);

            act_server_cntx_p->ftps_bt_device.lap = ind->bd_addr.lap;
            act_server_cntx_p->ftps_bt_device.uap = ind->bd_addr.uap;
            act_server_cntx_p->ftps_bt_device.nap = ind->bd_addr.nap;
            ftps_cntx_p->conn_id = srv_bt_cm_start_conn(
                MMI_TRUE,
                SRV_BT_CM_OBEX_FILE_TRANSFER_UUID,
                (srv_bt_cm_bt_addr *)&ind->bd_addr,
                (CHAR*)&ind->dev_name);
            if (ftps_cntx_p->conn_id > 0)
            {
                authorize_ind.bd_address.lap = ind->bd_addr.lap;
                authorize_ind.bd_address.uap = ind->bd_addr.uap;
                authorize_ind.bd_address.nap = ind->bd_addr.nap;
                authorize_ind.dev_name_p = ind->dev_name;
                authorize_ind.conn_id = (U32)(ind->goep_conn_id);
                srv_ftps_notify(SRV_FTPS_EVENT_AUTHORIZE, (void*)&authorize_ind);
            }
            else
            {
                //srv_ftps_authorize_reject()
            }
            break;

        default: /* wrong state */
            SRV_FTPS_LOG_STATE_ERR();
            ASSERT(0);
            break;
    }
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_writer_flush
 * DESCRIPTION
 *  
 * PARAMETERS
 *  composer    [IN]
 *  data    [IN]
 * RETURNS
 *  S32
 ******************************************************************************/
static S32 srv_ftps_writer_flush(srv_ftp_file_writer_struct *composer, U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_WRITER_FLUSH);
    if (composer->buflen)
    {
        ret = FS_Write(composer->fd, composer->buf, composer->buflen, &(composer->written));
        if (ret < FS_NO_ERROR)
        {
            MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_WRITER_FLUSH_FS_WRITE, ret);
            return ret;
        }
        
        kal_mem_set(composer->buf, 0, SRV_FTP_MAX_FILE_WRITER_BUF_SIZE);
        composer->buflen = 0;
        composer->written = 0;
    }

    if (data)
    {
        ret = FS_Write(composer->fd, data, strlen((const char*)data), &(composer->written));
        if (ret < FS_NO_ERROR)
        {
            MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_WRITER_FLUSH_FS_WRITE, ret);
        }
    }

    return ret;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_disconnect_ind_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 ******************************************************************************/
void srv_ftps_disconnect_ind_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_deregister_server_req_struct *req;
    srv_ftps_disconnect_indication_struct dis_ind;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch (act_server_cntx_p->ftps_state)
    {
        case SRV_FTPS_STATE_AUTHORIZING:
            SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACTIVE);
            if (ftps_cntx_p->conn_id > 0)
            {
                srv_bt_cm_stop_conn(ftps_cntx_p->conn_id);
                ftps_cntx_p->conn_id = -1;
            }
            

            dis_ind.cm_conn_id = ftps_cntx_p->g_conn_id;
            dis_ind.bd_address = act_server_cntx_p->ftps_bt_device;
            srv_ftps_connection_terminated();
            srv_ftps_notify(SRV_FTPS_EVENT_DISCONNECT, (void*)&dis_ind);
            return;

        case SRV_FTPS_STATE_DISCONNECTING:
            SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACTIVE);
            if (ftps_cntx_p->conn_id > 0)
            {
                srv_bt_cm_stop_conn(ftps_cntx_p->conn_id);
                ftps_cntx_p->conn_id = -1;
            }
            
            dis_ind.bd_address = act_server_cntx_p->ftps_bt_device;
            dis_ind.cm_conn_id = ftps_cntx_p->g_conn_id;
            srv_ftps_connection_terminated();
            srv_ftps_notify(SRV_FTPS_EVENT_DISCONNECT, (void*)&dis_ind);
            return;

        case SRV_FTPS_STATE_DEACTIVATING:
            req = (goep_deregister_server_req_struct*)OslConstructDataPtr(sizeof(goep_deregister_server_req_struct));
            FTP_MEMSET(req);
            req->goep_conn_id = ftps_cntx_p->goep_conn_id;

            if (ftps_cntx_p->conn_id > 0)
            {
                srv_bt_cm_stop_conn(ftps_cntx_p->conn_id);
                ftps_cntx_p->conn_id = -1;
            }

            srv_ftp_send_msg(MSG_ID_GOEP_DEREGISTER_SERVER_REQ, req);
            dis_ind.cm_conn_id = ftps_cntx_p->g_conn_id;
            dis_ind.bd_address = act_server_cntx_p->ftps_bt_device;
            srv_ftps_connection_terminated();
            srv_ftps_notify(SRV_FTPS_EVENT_DISCONNECT, (void*)&dis_ind);
            return;

        /* connected states */
        case SRV_FTPS_STATE_ACTIVE:
        case SRV_FTPS_STATE_ACCEPTED:
        case SRV_FTPS_STATE_SENDING:
        case SRV_FTPS_STATE_RECEIVING:
            SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACTIVE);
            if (ftps_cntx_p->conn_id > 0)
            {
                srv_bt_cm_stop_conn(ftps_cntx_p->conn_id);
                ftps_cntx_p->conn_id = -1;
            }

            dis_ind.cm_conn_id = ftps_cntx_p->g_conn_id;
            dis_ind.bd_address = act_server_cntx_p->ftps_bt_device;
            srv_ftps_connection_terminated();
            if (dis_ind.cm_conn_id != 0xFF)
            {
                srv_ftps_notify(SRV_FTPS_EVENT_DISCONNECT, (void*)&dis_ind);
            }
            return;
        
        default: /* not connected yet */
            //SRV_FTPS_LOG_STATE_ERR();
            ASSERT(0);
            return;
    }
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_write_folder_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fs_file_info_p    [IN]
 * RETURNS
 *  S32
 ******************************************************************************/
static S32 srv_ftps_write_folder_content(FS_DOSDirEntry *fs_file_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    //U8 tmp_path_buf[(SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH];
    U8* tmp_path_buf = NULL;
    srv_ftp_file_writer_struct *composer = &(act_server_cntx_p->xml_composer);
    srv_ftp_obj_info_struct ftp_file_info;
    WCHAR *file_name = (WCHAR*)act_server_cntx_p->ftps_obj_name;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_WRITE_FOLDER_CONTENT);
    
    i = 0;
    do
    {
        /* this file should be included in folder content */
        if ((fs_file_info_p->Attributes & (FS_ATTR_VOLUME | FS_ATTR_HIDDEN | FS_ATTR_SYSTEM)) == 0)
        {
            i++;
            /* save obj name and info */
            /* FS file attribut for different encodeed file */
            if (fs_file_info_p->NTReserved == FS_SFN_MATCH)
            {
                tmp_path_buf = (U8*)OslMalloc((SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH);
                mmi_chset_mixed_text_to_ucs2_str(tmp_path_buf,
                                                 (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                                 (U8*)file_name,
                                                 srv_setting_get_encoding_type());
                ftp_file_info.file_name = (U8*)tmp_path_buf;
            }
            else
            {
                ftp_file_info.file_name = (U8*)file_name;
            }

            ftp_file_info.year = fs_file_info_p->DateTime.Year1980 + 1980;
            ftp_file_info.month = fs_file_info_p->DateTime.Month;
            ftp_file_info.day = fs_file_info_p->DateTime.Day;
            ftp_file_info.hour = fs_file_info_p->DateTime.Hour;
            ftp_file_info.min = fs_file_info_p->DateTime.Minute;
            ftp_file_info.sec = fs_file_info_p->DateTime.Second2;
            ftp_file_info.file_size = fs_file_info_p->FileSize;

            if (fs_file_info_p->Attributes & FS_ATTR_DIR) /* If the file_info is a folder */
            {
                result = srv_ftps_compose_folder_element(composer, &ftp_file_info);
            }
            else /* the file info is a file */
            {
                result = srv_ftps_compose_file_element(composer, &ftp_file_info);
            }

            if (tmp_path_buf)
            {
                OslMfree(tmp_path_buf);
                tmp_path_buf = NULL;
            }
            
            if (result < 0)
            {
                return result;
            }

            if (i > SRV_FTPS_MAX_PARSE_FILE_INFO_NUMBER)
            {
                if (composer->buflen > 0)
                {
                    result = FS_Write(composer->fd, composer->buf, composer->buflen, &(composer->written));
                    if (result < 0)
                    { 
                        return result;
                    }
                }
                kal_mem_set(composer->buf, 0, SRV_FTP_MAX_FILE_WRITER_BUF_SIZE);
                composer->buflen = 0;
                composer->written = 0;
                return i;
            }
        }

        memset(fs_file_info_p, 0, sizeof(FS_DOSDirEntry));
    } while (FS_FindNext(act_server_cntx_p->fh_ftps_generating,
                         fs_file_info_p,
                         file_name,
                         SRV_FTPS_MAX_OBJ_NAME_LEN)
             == FS_NO_ERROR);

    return 0;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_gen_folder_content_continue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
static void srv_ftps_gen_folder_content_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 res;
    FS_DOSDirEntry fs_file_info;
    srv_ftp_file_writer_struct *composer = &(act_server_cntx_p->xml_composer);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_GEN_FOLDER_CONTENT_CONTINUE);
    if (act_server_cntx_p->ftps_state == SRV_FTPS_STATE_SENDING)
    {
        /* set FS_ATTR_SYSTEM to let the code goto the FS_FindNext() while running the do{}while()
         *  in srv_ftps_write_folder_content() */
        fs_file_info.Attributes = FS_ATTR_SYSTEM;
        res = srv_ftps_write_folder_content(&fs_file_info);
        if (res < 0)
        {
            srv_ftps_gen_folder_content_error_handle();
        }
        else if (res > SRV_FTPS_MAX_PARSE_FILE_INFO_NUMBER)
        {
            srv_ftps_send_gen_folder_continue();
            return;
        }

        FS_FindClose(act_server_cntx_p->fh_ftps_generating);
        res = srv_ftps_compose_end_element(composer);
        if (res < 0)
        {
            srv_ftps_gen_folder_content_error_handle();
        }
        
        FS_Close(composer->fd);
        srv_ftps_send_folder_content();
    }
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_send_pull_error
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
static void srv_ftps_send_pull_error(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_pull_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_SEND_PULL_ERROR);
    res = (goep_pull_res_struct*)OslConstructDataPtr(sizeof(goep_pull_res_struct));
    FTP_MEMSET(res);
    res->goep_conn_id = ftps_cntx_p->goep_conn_id;
    res->rsp_code = GOEP_INTERNAL_SERVER_ERR;
    srv_ftp_send_msg(MSG_ID_GOEP_PULL_RES, res);
    SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_send_gen_folder_continue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
static void srv_ftps_send_gen_folder_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    ilm_struct message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_SEND_GEN_FOLDER_CONTINUE);
    
//     message.src_mod_id = MOD_MMI;
//     message.dest_mod_id = MOD_MMI;
//     message.msg_id = MSG_ID_MMI_BT_FTPS_GEN_FOLDER_CONTINUE;
//     message.sap_id = MMI_MMI_SAP;
//     message.local_para_ptr = NULL;
//     message.peer_buff_ptr = NULL;
//     OslMsgSendExtQueue(&message);

    mmi_frm_send_ilm(
        MOD_MMI,
        MSG_ID_MMI_BT_FTPS_GEN_FOLDER_CONTINUE,
        NULL,
        NULL);
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_gen_folder_content_error_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
static void srv_ftps_gen_folder_content_error_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_GEN_FOLDER_CONTENT_ERROR_HANDLE); 
    if (act_server_cntx_p->ftps_browse_depth > 0)
    {
        FS_FindClose(act_server_cntx_p->fh_ftps_generating);
    }

    if (act_server_cntx_p->xml_composer.fd > 0)
    {
        FS_Close(act_server_cntx_p->xml_composer.fd);
        act_server_cntx_p->xml_composer.fd = (FS_HANDLE)NULL;
    }

    FS_Delete((const WCHAR*)(act_server_cntx_p->folder_content));
    SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_ACCEPTED);
    srv_ftps_send_pull_error();
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_connection_terminated
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURN VALUE LIST
 *  vodi
 ******************************************************************************/
static void srv_ftps_connection_terminated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_CONNECTION_TERMINATED);

    if (act_server_cntx_p->fh_ftps_send)
    {
        FS_Close(act_server_cntx_p->fh_ftps_send);
        act_server_cntx_p->fh_ftps_send = (FS_HANDLE)NULL;
    }

    if (act_server_cntx_p->xml_composer.fd > 0)
    {
        FS_Close(act_server_cntx_p->xml_composer.fd);
        act_server_cntx_p->xml_composer.fd = (FS_HANDLE)NULL;
    }

    FS_Delete((const WCHAR*)(act_server_cntx_p->folder_content));
    act_server_cntx_p->send_obj_type = SRV_FTP_OBJ_TYPE_NONE;

    if (act_server_cntx_p->fh_ftps_recv)
    {
        srv_ftps_operation_end_struct push_ind;

        FS_Close(act_server_cntx_p->fh_ftps_recv);
        act_server_cntx_p->fh_ftps_recv = (FS_HANDLE)NULL;

        push_ind.operation = SRV_FTPS_OPERATION_PUSH;
        push_ind.result = SRV_FTP_MASK_RESULT_FAIL;
        srv_ftps_notify(SRV_FTPS_EVENT_OPERATION_END, (void*)&push_ind);
    }

    /* clear the released g_conn_id */
    ftps_cntx_p->g_conn_id = 0xFF;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_deinit
 * DESCRIPTION
 *  this function is to deinit ftp server
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
void srv_ftps_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_ftps_connection_terminated();
    SRV_FTPS_STATE_TRANS(SRV_FTPS_STATE_IDLE);

    for (i = 0; i < SRV_FTP_MAX_SERVER_NUM; ++i)
    {
        ftps_handle[i].srv_hd = 0;
    }
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_is_valid_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_hd    [IN]
 *  
 * RETURNS
 *  MMI_BOOL
 ******************************************************************************/
MMI_BOOL srv_ftps_is_valid_handle(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_IS_VALID_HANDLE, srv_hd);
    return ((srv_hd > SRV_FTP_SERVER_HANDLE_DOMAIN) && (srv_hd <= SRV_FTP_SERVER_HANDLE_DOMAIN + SRV_FTP_MAX_SERVER_NUM)) ?
        MMI_TRUE : MMI_FALSE;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event    [IN]
 *  para    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
void srv_ftps_notify(U16 event, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_NOTIFY, event);
    for (i = 0; i < SRV_FTP_MAX_SERVER_NUM; ++i)
    {
        if (srv_ftps_is_valid_handle(ftps_handle[i].srv_hd))
        {
            if ((event & ftps_handle[i].event_mask) != 0)
            {
                ftps_handle[i].notifier(ftps_handle[i].srv_hd, event, para);
            }
        }
    }
}


S32 srv_ftps_set_permission(S32 right)
{
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPS_SET_PERMISSION, right);
    if ((right >= 0) && (right < SRV_FTPS_PERMISSION_TOTAL))
    {
        ftps_cntx_p->access_right = right;
        return SRV_FTP_RESULT_OK;
    }

    return SRV_FTP_MASK_RESULT_FAIL;
}

#endif /* __MMI_FTS_SUPPORT__ */ 
