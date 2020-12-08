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
 *  FtpcSrv.c
 * 
 * Project:
 * --------
 *  MMI
 * 
 * Description:
 * ------------
 *  This file is for MMI FTP client srvice
 * 
 * Author:
 * -------
 * -------
 * 
 *=============================================================================
 *            HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *-----------------------------------------------------------------------------
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
 * removed!
 *-----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *=============================================================================
 ******************************************************************************/
// RHR: add
#include "MMI_features.h"
// RHR: add

#ifdef __MMI_FTC_SUPPORT__
/* Include: MMI header file */
//#include "MMI_include.h"
//#include "Fmt_struct.h"
//#include "ExtDeviceDefs.h"
#include "BtcmSrvGprot.h"
#include "Bluetooth_struct.h"
//#include "BTMMIObexGprots.h"
#include "Conversions.h"
// RHR: add
#include "FtpSrv.h"
#include "MMIDataType.h"
#include "MMI_conn_app_trc.h"
#include "FtpSrvGprots.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "string.h"
#include "stack_msgs.h"
#include "fs_func.h"
#include "fs_type.h"
#include "xml_def.h"
#include "mmi_frm_events_gprot.h"
#include "stdlib.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "custom_mmi_default_value.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "fs_errcode.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "wgui_categories_popup.h"
#include "stack_config.h"
#include "stack_common.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
// RHR: add

//#include "BTMMIFtpGprots.h"
#include "FtpcSrv.h"
//#include "FtpSrv.h"
//#include "xml_def.h"
#include "mmi_rp_srv_btcm_def.h"

/***************************************************************************** 
* External Variable & Functions
*****************************************************************************/
/* for file name buffer */


/***************************************************************************** 
* CONTEXT
*****************************************************************************/
srv_ftpc_cntx_struct g_mmi_ftpc_cntx;
srv_ftpc_cntx_struct *const ftpc_cntx_p = &g_mmi_ftpc_cntx;
srv_ftpc_conn_cntx_struct *act_client_cntx_p;
srv_ftp_hdlr_struct ftpc_handle[SRV_FTP_MAX_CLIENT_NUM];
//static U16 ftpc_recv_obj_tmp_name[MMI_BT_OBJ_NAME_LEN];


/***************************************************************************** 
* INTERNAL STATIC FUNCTION
*****************************************************************************/
static void srv_ftpc_get_folder(goep_pull_rsp_struct *rsp);
static void srv_ftpc_parse_folder_content(void);
static S32 srv_ftpc_write_obj_entity(void);
static void srv_ftpc_folder_listing_startelement(void *data, const char *el, const char **attr, S32 error);
static void srv_ftpc_folder_listing_endelement(void *data, const char *el, S32 error);
static S32 srv_ftpc_folder_listing_startelement_name(const U8 *src_name);
static void srv_ftpc_folder_listing_startelement_time(U16 *dest_time, const U8 *src_time);
//static void srv_ftpc_folder_listing_startElement_size(U16 *dest_data, const U8 *src_data);
static void srv_ftpc_get_file_complete(S32 error_cause);
static void srv_ftpc_browse_files_failed_timer_expire_handle(void);
static void srv_ftpc_set_fs_flag(S32 ret);
static S32 srv_ftpc_write_lname2file(const U16 *long_name_p, U32 name_len);
static S32 srv_ftpc_get_folder_cntx_init(void);
static void srv_ftpc_send_get_folder_continue(void);
static void srv_ftpc_get_folder_error_handle(goep_pkt_type_enum pkt_type);
static S32 srv_ftpc_parse_folder_init(void);
static void srv_ftpc_parse_folder_content_continue(void);
static void srv_ftpc_parse_folder_content_complete(void);
static void srv_ftpc_send_parse_continue_msg(void);
static void srv_ftpc_parse_folder_content_error_handle(U8 status);
static S32 srv_ftpc_write_buf2file(void);
static void srv_ftpc_record_written_count(U32 written);
static void srv_ftpc_record_file_index(void);
static void srv_ftpc_flush_obj_entity(void);
static MMI_BOOL srv_ftpc_get_folder_content(void);
static void srv_ftpc_receiving_aborted_handle(void);
static void srv_ftpc_send_abort(U8 goep_conn_id);
static void srv_ftpc_set_abort_req_sent_flag(void);
static MMI_BOOL srv_ftpc_change_folder_internal(PU16 name);
static void srv_ftpc_send_tpdisconnect(void);
static void srv_ftpc_reset_abort_req_sent_flag(void);
//static void srv_ftpc_delete_pulling_file(void);
static void srv_ftpc_send_disconnect(void);
#ifdef __MMI_BT_RX_ENHANCE__
static void srv_ftpc_intbuf_write_obj_continue(void);
#endif
static MMI_BOOL srv_ftpc_permit_show_pair_scr(srv_bt_cm_bt_addr bt_addr);


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_connect_server
 * DESCRIPTION
 *  This function is to connect server for ftp service
 * PARAMETERS
 *  srv_hd :     [IN]
 *  bd_addr:     [IN]        
 * RETURNS
 *  SRV_FTP_RESULT_OK: success
 *  SRV_FTP_RESULT_FAIL: fail
 *****************************************************************************/
S32 srv_ftpc_connect_server(S32 srv_hd, srv_bt_cm_bt_addr bd_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_connect_req_struct *req;
    S32 result = SRV_FTP_RESULT_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ftpc_is_valid_handle(srv_hd))
    {
        if (act_client_cntx_p->ftpc_state == SRV_FTPC_STATE_IDLE)
        {
            /* update context */
            act_client_cntx_p->ftpc_bt_device.lap = bd_addr.lap;
            act_client_cntx_p->ftpc_bt_device.uap = bd_addr.uap;
            act_client_cntx_p->ftpc_bt_device.nap = bd_addr.nap;
            act_client_cntx_p->abort_type = SRV_FTPC_ABORT_NONE;
            srv_ftpc_reset_abort_req_sent_flag();
            //act_client_cntx_p->client_write_file_error = 0;

            ftpc_cntx_p->conn_id = srv_bt_cm_start_conn(
                MMI_FALSE,
                SRV_BT_CM_OBEX_FILE_TRANSFER_CLIENT_UUID,
                &bd_addr,
                NULL);
            if (ftpc_cntx_p->conn_id > 0)
            {
                req = (goep_connect_req_struct*)OslConstructDataPtr(sizeof(goep_connect_req_struct));
                FTP_MEMSET(req);
                req->bd_addr.lap = bd_addr.lap;
                req->bd_addr.uap = bd_addr.uap;
                req->bd_addr.nap = bd_addr.nap;
                req->buf_ptr = act_client_cntx_p->ftpc_obj_buff;
                req->buf_size = FTPC_MEM_BUFF_SIZE;
                req->req_id = ftpc_cntx_p->conn_id;
                req->tp_type = GOEP_TP_BT;
                memcpy(req->uuid, OBEX_FTP_UUID, 16);
                req->uuid_len = 16;
                srv_ftp_send_msg(MSG_ID_GOEP_CONNECT_REQ, req);

                SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_CONNECTING);
                result = SRV_FTP_RESULT_OK;
            }
        }
    }

    MMI_TRACE(
        MMI_FTP_TRC_CLASS,
        SRV_FTPC_CONNECT_SERVER,
        act_client_cntx_p->ftpc_state,
        ftpc_cntx_p->conn_id,
        bd_addr.lap,
        bd_addr.uap,
        bd_addr.nap);           // ZHY: modify the trace

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_is_running
 * DESCRIPTION
 *  This function is to get current action.
 *  PARAMETERS: void
 *   void
 *  RETURNS: received file counter.(?)(?)
 *   MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_ftpc_is_running(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_IS_RUNNING, act_client_cntx_p->ftpc_state);
    if ((act_client_cntx_p->ftpc_state >= SRV_FTPC_STATE_CONNECTING)
        && (act_client_cntx_p->ftpc_state < SRV_FTPC_STATE_DISCONNECTING))
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_is_canceling
 * DESCRIPTION
 *  This function is to get current action.
 *  PARAMETERS: void
 *   void
 *  RETURNS: received file counter.(?)(?)
 *   BOOL
 *****************************************************************************/
/* BOOL srv_ftpc_is_canceling(void) */
/* { */
/*     /\*----------------------------------------------------------------*\/ */
/*     /\* Local Variables                                                *\/ */
/*     /\*----------------------------------------------------------------*\/ */

/*     /\*----------------------------------------------------------------*\/ */
/*     /\* Code Body                                                      *\/ */
/*     /\*----------------------------------------------------------------*\/ */
/*     MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_BT_FTP_FTPC_IS_CANCELING, act_client_cntx_p->ftpc_state); */
/*     if (act_client_cntx_p->ftpc_state == SRV_FTPC_STATE_DISCONNECTING) */
/*     { */
/*         return MMI_TRUE; */
/*     } */
/*     else */
/*     { */
/*         return MMI_FALSE; */
/*     } */
/* } */


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_is_aborting
 * DESCRIPTION
 *  This function is to get current action.
 *  PARAMETERS: void
 *   void
 *  RETURNS: received file counter.(?)(?)
 *   MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_ftpc_is_aborting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_IS_ABORTING, act_client_cntx_p->ftpc_state);
    if (act_client_cntx_p->ftpc_state == SRV_FTPC_STATE_ABORTING)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftp_client_is_receiving
 * DESCRIPTION
 *  This function is to get current status of ftp client.
 * PARAMETERS: void
 *  void
 * RETURNS: received file counter.(?)(?)
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_ftpc_is_receiving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (act_client_cntx_p->ftpc_state == SRV_FTPC_STATE_GETTING_OBJ)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_send_disconnect
 * DESCRIPTION
 *  This is common function to disconnect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftpc_send_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_disconnect_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_SEND_DISCONNECT, act_client_cntx_p->ftpc_state);
    req = (goep_disconnect_req_struct*)OslConstructDataPtr(sizeof(goep_disconnect_req_struct));
    FTP_MEMSET(req);
    req->goep_conn_id = ftpc_cntx_p->goep_conn_id;
    srv_ftp_send_msg(MSG_ID_GOEP_DISCONNECT_REQ, req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_change_folder
 * DESCRIPTION
 *  This function is to browse a new folder or refresh the current folder
 * PARAMETERS
 *  name        [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL srv_ftpc_change_folder_internal(U16* name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_CHANGE_FOLDER_INTERNAL, act_client_cntx_p->ftpc_state, ftpc_cntx_p->goep_conn_id);
    /* refresh current folder */
    if (!name)
    {
        MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_CHANGE_FOLDER_REFRESH);
        if (srv_ftpc_get_folder_content())
        {
            return MMI_TRUE;
        }
    }
    else
    {
        goep_set_folder_req_struct *req;

        MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_CHANGE_FOLDER_FORWARD);
        switch (act_client_cntx_p->ftpc_state)
        {
            case SRV_FTPC_STATE_CONNECTED:
                SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_SETTING_FOLDER);

                req = (goep_set_folder_req_struct*)OslConstructDataPtr(sizeof(goep_set_folder_req_struct));
                FTP_MEMSET(req);
                req->goep_conn_id = ftpc_cntx_p->goep_conn_id;
                req->setpath_flag = GOEP_FORWARD_FOLDER;
                srv_ftp_obj_name_swapcpy((CHAR*)req->folder_name, (CHAR*)name);

                srv_ftp_send_msg(MSG_ID_GOEP_SET_FOLDER_REQ, req);
                return MMI_TRUE;

            default: /* Incorrect state, callback and return error */
                SRV_FTPC_LOG_STATE_ERR();
                if (act_client_cntx_p->fh_ftpc_recv)
                {
                    FS_Close(act_client_cntx_p->fh_ftpc_recv);
                    act_client_cntx_p->fh_ftpc_recv = (FS_HANDLE)NULL;
                }

                return MMI_FALSE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_send_tpdisconnect
 * DESCRIPTION
 *  This is common function to disconnect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftpc_send_tpdisconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_disconnect_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_SEND_TPDISCONNECT, act_client_cntx_p->ftpc_state);
    req = (goep_disconnect_req_struct*)OslConstructDataPtr(sizeof(goep_disconnect_req_struct));
    FTP_MEMSET(req);
    req->req_id = ftpc_cntx_p->conn_id;
    req->goep_conn_id = ftpc_cntx_p->goep_conn_id;
    srv_ftp_send_msg(MSG_ID_GOEP_TPDISCONNECT_REQ, req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_cntx_init
 * DESCRIPTION
 *  This function is to initialize FTPC context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftpc_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_profile_struct ftpc_tbl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_CNTX_INIT);

    act_client_cntx_p = &(ftpc_cntx_p->conn_cntx);

    /* ftpc context init */
    ftpc_cntx_p->goep_conn_id = 0xFF;
    //ftpc_cntx_p->req_id = 0xFF;
    ftpc_cntx_p->conn_id = -1;
    ftpc_cntx_p->g_conn_id = 0xFF;

    //act_client_cntx_p->client_write_file_error = 0;
    act_client_cntx_p->entity_cnt_cur_folder = 0;
    act_client_cntx_p->xml_parser_p = NULL;
    act_client_cntx_p->fh_ftpc_recv = (FS_HANDLE)NULL;
    act_client_cntx_p->ftpc_state = SRV_FTPC_STATE_IDLE;

    SRV_FTPC_MAKE_FOLDER_OBJECT(act_client_cntx_p->folder_obj);
    SRV_FTPC_MAKE_FOLDER_PARSED(act_client_cntx_p->parsed_folder);
    SRV_FTPC_MAKE_FOLDER_PARSED_LONG_NAME(act_client_cntx_p->parsed_folder_lname);
    SRV_FTPC_MAKE_FOLDER_PARSED_FILEINDEX(act_client_cntx_p->parsed_folder_fileindex);

    memset(&(act_client_cntx_p->ftpc_bt_device), 0, sizeof(srv_bt_cm_bt_addr));
    memset(&(act_client_cntx_p->obj_entity), 0, sizeof(srv_ftp_entity_int_struct));
    memset(&act_client_cntx_p->folder_content, 0, sizeof(srv_ftp_file_writer_struct));

    //srv_ftpc_reset_abort_req_sent_flag();
    memset(act_client_cntx_p->ftpc_obj_buff, 0, FTPC_MEM_BUFF_SIZE);

#ifdef __MMI_BT_RX_ENHANCE__
    act_client_cntx_p->inbuf_pkt_error = SRV_FTP_PRE_PKT_ERR_NONE;
    memset(act_client_cntx_p->ftpc_obj_int_buff, 0, FTPC_MEM_BUFF_SIZE);
    act_client_cntx_p->inbuf_len = 0;
#endif /* __MMI_BT_RX_ENHANCE__ */

    ftpc_tbl.profile_id = SRV_BT_CM_OBEX_FILE_TRANSFER_CLIENT_UUID;
    ftpc_tbl.activater = NULL;
    ftpc_tbl.deactivater = NULL;
    ftpc_tbl.disconnector = srv_ftpc_disconnect_conn;
    srv_bt_cm_profile_register((const srv_bt_cm_profile_struct*)&ftpc_tbl);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_write_obj
 * DESCRIPTION
 *  This Function is to write the first pkt of the file, and send the new  pull_req if needed. 
 * PARAMETERS
 *  rsp     [?]         
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 srv_ftpc_write_obj(goep_pull_rsp_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_pull_req_struct *req;
    S32 retval;
    U32 len_written;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_WRITE_OBJ, rsp->pkt_type);
    
    if (rsp->frag_len > 0)
    {
        retval = FS_Write(
            act_client_cntx_p->fh_ftpc_recv,
            rsp->frag_ptr,
            rsp->frag_len,
            (kal_uint32*)&len_written);
        MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_WRITE_OBJ_WRITE, retval);
        if (retval < 0)
        {
            srv_ftpc_set_fs_flag(retval);
            return retval;
        }
    }

    act_client_cntx_p->recved_obj_len += rsp->frag_len;
    if ((rsp->pkt_type == GOEP_FINAL_PKT) || (rsp->pkt_type == GOEP_SINGLE_PKT))
    {
        if (act_client_cntx_p->fh_ftpc_recv)
        {
            FS_Close(act_client_cntx_p->fh_ftpc_recv);
            act_client_cntx_p->fh_ftpc_recv = (FS_HANDLE)NULL;
        }

        srv_ftpc_get_file_complete(0);
    }
    else
    {
        req = (goep_pull_req_struct*)OslConstructDataPtr(sizeof(goep_pull_req_struct));
        FTP_MEMSET(req);
        req->goep_conn_id = ftpc_cntx_p->goep_conn_id;
        req->pkt_type = GOEP_NORMAL_PKT;
        srv_ftp_send_msg(MSG_ID_GOEP_PULL_REQ, req);
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_write_obj_continue
 * DESCRIPTION
 *  This function is to write the pkt from 2nd pkt, and send pull_req for next if needed.
 * PARAMETERS
 *  rsp     [?]         
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_ftpc_write_obj_continue(goep_pull_rsp_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_pull_req_struct *req;
    S32 retval;
    U32 len_written;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_WRITE_OBJ_CONTINUE, rsp->pkt_type);
    if (rsp->frag_len > 0)
    {
        ASSERT(act_client_cntx_p->fh_ftpc_recv);
        retval = FS_Write(act_client_cntx_p->fh_ftpc_recv, rsp->frag_ptr, rsp->frag_len, (kal_uint32*)&len_written);
        MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_WRITE_OBJ_CONTINUE_WRITE, retval);
        if (retval < 0)
        {
            srv_ftpc_set_fs_flag(retval);
            return retval;
        }
    }

    act_client_cntx_p->recved_obj_len += rsp->frag_len;
    if ((rsp->pkt_type == GOEP_FINAL_PKT) || (rsp->pkt_type == GOEP_SINGLE_PKT))
    {
        if (act_client_cntx_p->fh_ftpc_recv)
        {
            FS_Close(act_client_cntx_p->fh_ftpc_recv);
            act_client_cntx_p->fh_ftpc_recv = 0;
        }

        srv_ftpc_get_file_complete(0);
    }
    else
    {
        /* Get next object body */
        req = (goep_pull_req_struct*)OslConstructDataPtr(sizeof(goep_pull_req_struct));
        FTP_MEMSET(req);
        req->goep_conn_id = ftpc_cntx_p->goep_conn_id;
        req->pkt_type = GOEP_NORMAL_PKT;
        srv_ftp_send_msg(MSG_ID_GOEP_PULL_REQ, req);
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_get_folder
 * DESCRIPTION
 *  This function is to handel the getting folder operation
 * PARAMETERS
 *  rsp
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftpc_get_folder(goep_pull_rsp_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 len_written;
    srv_ftpc_get_folder_struct get_folder_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_GET_FOLDER, rsp->rsp_code, rsp->pkt_type);

    switch (rsp->rsp_code)
    {
        case GOEP_STATUS_SUCCESS:
            if ((rsp->pkt_type == GOEP_FIRST_PKT) || (rsp->pkt_type == GOEP_SINGLE_PKT))
            {
                if (srv_ftpc_get_folder_cntx_init() < 0)
                {
                    srv_ftpc_get_folder_error_handle(rsp->pkt_type);
                    return;
                }
            }
            
            if (rsp->frag_len > 0)
            {
                ret = FS_Write(act_client_cntx_p->fh_ftpc_recv, rsp->frag_ptr, rsp->frag_len, (kal_uint32*)&len_written);
                MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_GET_FOLDER_WRITE, ret);
                if (ret < 0)
                {
                    srv_ftpc_get_folder_error_handle(rsp->pkt_type);
                    return;
                }
            }

            if ((rsp->pkt_type == GOEP_FINAL_PKT) || (rsp->pkt_type == GOEP_SINGLE_PKT))
            {
                if (act_client_cntx_p->fh_ftpc_recv)
                {
                    FS_Close(act_client_cntx_p->fh_ftpc_recv);
                    act_client_cntx_p->fh_ftpc_recv = (FS_HANDLE)NULL;
                }

                SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_PARSING_FOLDER);
                srv_ftpc_parse_folder_content();
            }
            else
            {
                srv_ftpc_send_get_folder_continue();
            }
            break;

        default:
            if (act_client_cntx_p->fh_ftpc_recv)
            {
                FS_Close(act_client_cntx_p->fh_ftpc_recv);
                act_client_cntx_p->fh_ftpc_recv = (FS_HANDLE)NULL;
                FS_Delete((const WCHAR*)act_client_cntx_p->folder_obj);
            }

            SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_CONNECTED);

            get_folder_result.result = SRV_FTPC_GET_FOLDER_FAIL;
            get_folder_result.entity_cnt = 0;
            get_folder_result.file_cnt = 0;
            srv_ftpc_notify(SRV_FTPC_EVENT_GET_FOLDER_CONTENT, (void*)&get_folder_result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_get_obj
 * DESCRIPTION
 *  This function is to handel the getting obj operation
 * PARAMETERS
 *  rsp
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftpc_get_obj(goep_pull_rsp_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_GET_OBJ, rsp->rsp_code, rsp->pkt_type);
    switch (rsp->rsp_code)
    {
        case GOEP_STATUS_SUCCESS:
        {
            /* usb plugin, enter mass_storage_mode, ignore this packet */
            if (act_client_cntx_p->fh_ftpc_recv == (FS_HANDLE)NULL)
            {
                return;
            }

            if ((rsp->pkt_type == GOEP_FIRST_PKT) || (rsp->pkt_type == GOEP_SINGLE_PKT))
            {
                if (rsp->pkt_type == GOEP_FIRST_PKT)
                {
                    if (rsp->total_obj_len > 0)
                    {
                        act_client_cntx_p->total_recv_obj_len = rsp->total_obj_len;
                    }
                }
                else /* GOEP_SINGLE_PKT */
                {
                    act_client_cntx_p->total_recv_obj_len = rsp->frag_len;
                }
                
                ret = srv_ftpc_write_obj(rsp);
                if (ret < 0)
                {
                    goto FTPC_GET_OBJ_ERR;
                }
                return;
            }

#ifdef __MMI_BT_RX_ENHANCE__
            /* From the 2nd pkt, the pkt handle will speed up if has internal buf (not included final pkt) */
            if (act_client_cntx_p->inbuf_pkt_error == SRV_FTP_PRE_PKT_ERR_NONE)
            {
                if (rsp->pkt_type == GOEP_FINAL_PKT)
                {
                    ret = srv_ftpc_write_obj_continue(rsp);
                    if (ret < 0)
                    {
                        goto FTPC_GET_OBJ_ERR;
                    }
                }
                else
                {
                    /* 1. copy data to i buffer
                     * 2. send rsp with success
                     * 3. write from i buffer, and set the error flag
                     */
                    goep_pull_req_struct *req;

                    memcpy(act_client_cntx_p->ftpc_obj_int_buff, rsp->frag_ptr, rsp->frag_len);
                    act_client_cntx_p->inbuf_len = rsp->frag_len;
 
                    req = (goep_pull_req_struct*)OslConstructDataPtr(sizeof(goep_pull_req_struct));
                    FTP_MEMSET(req);
                    req->goep_conn_id = ftpc_cntx_p->goep_conn_id;
                    req->pkt_type = GOEP_NORMAL_PKT;
                    srv_ftp_send_msg(MSG_ID_GOEP_PULL_REQ, req);
                    srv_ftpc_intbuf_write_obj_continue();
                }
            }
            else
            {
                /* 1. omit this pkt, and do error handling
                 * 2. if not final, shall send abort_req
                 */
                goto FTPC_GET_OBJ_ERR;
            }
            return;
            
#else /* __MMI_BT_RX_ENHANCE__ */
            ret = srv_ftpc_write_obj_continue(rsp);
            if (ret < 0)
            {
                goto FTPC_GET_OBJ_ERR;
            }
            return;
#endif /* __MMI_BT_RX_ENHANCE__ */
        }

        default:
            if (act_client_cntx_p->fh_ftpc_recv)
            {
                FS_Close(act_client_cntx_p->fh_ftpc_recv);
                act_client_cntx_p->fh_ftpc_recv = (FS_HANDLE)NULL;
            }

/*             if (rsp->pkt_type == GOEP_NORMAL_PKT) */
/*             { */
/*                 srv_ftpc_delete_pulling_file(); */
/*             } */
            
            srv_ftpc_get_file_complete(-1); /* -1 means error from server */
    }
    return;

FTPC_GET_OBJ_ERR:
    srv_ftpc_receiving_aborted_handle();
    if ((rsp->pkt_type != GOEP_FINAL_PKT) && (rsp->pkt_type != GOEP_SINGLE_PKT))
    {
        srv_ftpc_send_abort(rsp->goep_conn_id);
        srv_ftpc_set_abort_req_sent_flag();
        act_client_cntx_p->abort_type = SRV_FTPC_ABORT_GETTING_FILE_FROM_SERVICE;
        SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_ABORTING);
    }
    else
    {
        srv_ftpc_get_file_complete(act_client_cntx_p->client_write_file_error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_send_abort
 * DESCRIPTION
 *  This function is to abort the getting obj operation
 * PARAMETERS
 *  goep_conn_id
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftpc_send_abort(U8 goep_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_abort_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (goep_abort_req_struct*)OslConstructDataPtr(sizeof(goep_abort_req_struct));
    FTP_MEMSET(req);
    req->goep_conn_id = goep_conn_id;

    srv_ftp_send_msg(MSG_ID_GOEP_ABORT_REQ, req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_parse_folder_content
 * DESCRIPTION
 *  This function is to parse the folder content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftpc_parse_folder_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_PARSE_FOLDER_CONTENT);
    if (srv_ftpc_parse_folder_init() > 0)
    {
        /* register element parser to write records to file when parsing */
        xml_register_element_handler(act_client_cntx_p->xml_parser_p,
                                     srv_ftpc_folder_listing_startelement,
                                     srv_ftpc_folder_listing_endelement);
        /* parse received folder content */
        result = xml_parse(act_client_cntx_p->xml_parser_p, (kal_wchar*)act_client_cntx_p->folder_obj);
        if (result == XML_RESULT_OK)
        {
            if (act_client_cntx_p->parsed_folder_item_cnt == SRV_FTPC_MAX_PARSE_THRESHOLD)
            {
                MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_PARSE_FOLDER_CONTENT_PAUSE, act_client_cntx_p->entity_cnt_cur_folder);
                act_client_cntx_p->parsed_folder_item_cnt = 0;
                SetProtocolEventHandler(srv_ftpc_parse_folder_content_continue, MSG_ID_MMI_BT_FTPC_PARSE_CONTINUE);
                srv_ftpc_send_parse_continue_msg();
            }
            else /* success */
            {
                srv_ftpc_flush_obj_entity();
                srv_ftpc_parse_folder_content_complete();
            }
        }
        else /* parse fail */
        {
            srv_ftpc_parse_folder_content_error_handle(SRV_FTPC_FOLDER_PARTIAL);
        }
    }
    else /* init fail */
    {
        srv_ftpc_parse_folder_content_error_handle(SRV_FTPC_FOLDER_EMPTY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_folder_listing_startElement
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]
 *  el          [IN]        
 *  attr        [IN]
 *  error
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftpc_folder_listing_startelement(void *data, const char *el, const char **attr, S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (error != XML_NO_ERROR)
    {
        MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_PARSE_EL_START_ERR);
        xml_stop_parse(act_client_cntx_p->xml_parser_p);
        return;
    }

    if ((!strcmp("folder", el)) || (!strcmp("file", el)))
    {
        memset(&(act_client_cntx_p->obj_entity), 0, sizeof(srv_ftp_entity_int_struct));
        if (!strcmp("folder", el))
        {
            act_client_cntx_p->obj_entity.type = SRV_FTP_OBJ_TYPE_FOLDER;
        }
        else
        {
            act_client_cntx_p->obj_entity.type = SRV_FTP_OBJ_TYPE_FILE;
        }

        if (attr != NULL)
        {
            act_client_cntx_p->obj_entity.size = SRV_FTP_UNKNOWN_SIZE; /* indicate the unknown size */
            while ((attr[i]) != 0)
            {
                if (!strcmp("name", attr[i]))
                {
                    S32 ret = srv_ftpc_folder_listing_startelement_name((const U8*)attr[i + 1]);
                    if (ret < 0)
                    {
                        xml_stop_parse(act_client_cntx_p->xml_parser_p);
                        return ;
                    }
                }
                else if ((!strcmp("created", attr[i])) || (!strcmp("modified", attr[i])))
                {
                    srv_ftpc_folder_listing_startelement_time(act_client_cntx_p->obj_entity.created_date, 
                        (U8*)attr[i + 1]);
                }
                else if (!strcmp("size", attr[i]))
                {
                    //srv_ftpc_folder_listing_startElement_size(act_client_cntx_p->obj_entity.size, (U8*)attr[i + 1]);
                    act_client_cntx_p->obj_entity.size = atoi((char*)attr[i + 1]);
                }
                i += 2;
            }
            if (mmi_ucs2strlen((CHAR*)(act_client_cntx_p->obj_entity.created_date)) == 0)
            {
                kal_wstrcpy((U16*)act_client_cntx_p->obj_entity.created_date,
                            (U16*)GetString(STR_GLOBAL_EMPTY));
            }
        }
        
        if (srv_ftpc_write_obj_entity() < 0)
        {
            xml_stop_parse(act_client_cntx_p->xml_parser_p);
            return;
        }

        /* threshold for release MMI control to other tasks */
        if (act_client_cntx_p->parsed_folder_item_cnt == SRV_FTPC_MAX_PARSE_THRESHOLD)
        {
            MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_FOLDER_LISTING_START_EL, act_client_cntx_p->entity_cnt_cur_folder);
            xml_pause_parse(act_client_cntx_p->xml_parser_p);
        }
    }
    else if ((!strcmp("parent-folder", el)) || (!strcmp("folder-listing", el)))
    {
        return;
    }
    else
    {
        xml_stop_parse(act_client_cntx_p->xml_parser_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_folder_listing_endElement
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data
 *  el  
 *  error
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftpc_folder_listing_endelement(void *data, const char *el, S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (error != XML_NO_ERROR)
    {
        MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_PARSE_EL_END_ERR);
        xml_stop_parse(act_client_cntx_p->xml_parser_p);
        return;
    }

    if ((!strcmp("folder", el)) || (!strcmp("folder-listing", el)) || (!strcmp("file", el)) || (!strcmp("parent-folder", el)))
    {
        return;
    }
    else
    {
        xml_stop_parse(act_client_cntx_p->xml_parser_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_folder_listing_startElement_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_name   [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 srv_ftpc_folder_listing_startelement_name(const U8* src_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 name_len;
    S32 ret = 0;
    U16* long_name_p = NULL;
    U16* long_name_ext_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    name_len = mmi_chset_utf8_strlen((U8*)src_name);
    act_client_cntx_p->obj_entity.actual_name_len = name_len;
    act_client_cntx_p->obj_entity.offset = 0xFFFFFFFF;
    if (name_len <= MAX_SUBMENU_CHARACTERS)
    {
        mmi_chset_utf8_to_ucs2_string((U8*)act_client_cntx_p->obj_entity.name,
                                      (MAX_SUBMENU_CHARACTERS + 1) * 2,
                                      (U8*)src_name);

    }
    else /* name_len > MAX_SUBMENU_CHARACTERS */
    {
        long_name_p = (U16*)OslMalloc((name_len + 1) * ENCODING_LENGTH);
        mmi_chset_utf8_to_ucs2_string((U8*)long_name_p,
                                      (name_len + 1) * ENCODING_LENGTH,
                                      (U8*)src_name);
        /* copy MAX_SUBMENU_CHARACTERS on purpose, so if there is no extention name, need not to copy continue */
        mmi_wcsncpy(act_client_cntx_p->obj_entity.name, (const U16*)long_name_p, MAX_SUBMENU_CHARACTERS);
        long_name_ext_p = mmi_wcsrchr((const U16*)long_name_p, L'.');
        if (long_name_ext_p)
        {
            mmi_wcsncpy(&act_client_cntx_p->obj_entity.name[MAX_SUBMENU_CHARACTERS - 3],
                        (const U16*)long_name_ext_p,
                        SRV_FTP_FILE_EXTENTION_LEN);
        }
        
        ret = srv_ftpc_write_lname2file(long_name_p, name_len);
        OslMfree(long_name_p);
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_folder_listing_startElement
 * DESCRIPTION
 *  Get the time info from element
 * PARAMETERS
 *  dest_time          [OUT]        
 *  src_time            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftpc_folder_listing_startelement_time(U16 *dest_time, const U8 *src_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME create_date;
    U8 tmp_string[5];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&create_date, 0, sizeof(MYTIME));

    tmp_string[0] = src_time[0];
    tmp_string[1] = src_time[1];
    tmp_string[2] = src_time[2];
    tmp_string[3] = src_time[3];
    tmp_string[4] = 0;
    create_date.nYear = atoi((const char*)tmp_string);

    tmp_string[0] = src_time[4];
    tmp_string[1] = src_time[5];
    tmp_string[2] = 0;
    tmp_string[3] = 0;
    tmp_string[4] = 0;
    create_date.nMonth = atoi((const char*)tmp_string);

    tmp_string[0] = src_time[6];
    tmp_string[1] = src_time[7];
    create_date.nDay = atoi((const char*)tmp_string);

    tmp_string[0] = src_time[9];
    tmp_string[1] = src_time[10];
    create_date.nHour = atoi((const char*)tmp_string);

    tmp_string[0] = src_time[11];
    tmp_string[1] = src_time[12];
    create_date.nMin = atoi((const char*)tmp_string);

    tmp_string[0] = src_time[13];
    tmp_string[1] = src_time[14];
    create_date.nSec = atoi((const char*)tmp_string);

    date_string(&create_date, (PU16)dest_time, DT_IDLE_SCREEN);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_folder_listing_startElement_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest_data    [out]        
 *  src_data      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
/* static void srv_ftpc_folder_listing_startElement_size(U16 *dest_data, const U8 *src_data) */
/* { */
/*     /\*----------------------------------------------------------------*\/ */
/*     /\* Local Variables                                                *\/ */
/*     /\*----------------------------------------------------------------*\/ */
/*     S32 file_size; */

/*     /\*----------------------------------------------------------------*\/ */
/*     /\* Code Body                                                      *\/ */
/*     /\*----------------------------------------------------------------*\/ */
/*     file_size = atoi((char*)src_data); */
/*     if (file_size >= 1024 * 1024) */
/*     { */
/*         file_size = file_size / 1024; */
/*         kal_wsprintf((WCHAR*)dest_data, */
/*                      "%d.%dM", */
/*                      (U16)(file_size / 1024), */
/*                      (U16)((file_size % 1024) / 103)); */
/*     } */
/*     else if (file_size >= 1024) */
/*     { */
/*         kal_wsprintf((WCHAR*)dest_data, */
/*                      "%d.%dK", */
/*                      (U16)(file_size / 1024), */
/*                      (U16)((file_size % 1024) / 103)); */
/*     } */
/*     else */
/*     { */
/*         kal_wsprintf((WCHAR*)dest_data, "%dB", (U16)(file_size)); */
/*     } */
/* } */


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_write_obj_entity
 * DESCRIPTION
 *  This function is to write the object entities in the listing folder
 * PARAMETERS
 *  void
 * RETURNS
 *  The result od write object entity
 *****************************************************************************/
static S32 srv_ftpc_write_obj_entity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    srv_ftp_file_writer_struct *writer = &(act_client_cntx_p->folder_content);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&(writer->buf[writer->buflen]), &(act_client_cntx_p->obj_entity), sizeof(srv_ftp_entity_int_struct));
    writer->buflen += sizeof(srv_ftp_entity_int_struct);
    result = srv_ftpc_write_buf2file();

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_get_folder_content
 * DESCRIPTION
 *  This function is to get the folder content
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL srv_ftpc_get_folder_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_pull_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_GET_FOLDER_CONTENT, act_client_cntx_p->ftpc_state, ftpc_cntx_p->goep_conn_id);
    switch (act_client_cntx_p->ftpc_state)
    {
        case SRV_FTPC_STATE_CONNECTED:
            SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_GETTING_FOLDER);
            req = (goep_pull_req_struct*)OslConstructDataPtr(sizeof(goep_pull_req_struct));
            FTP_MEMSET(req);
            req->goep_conn_id = ftpc_cntx_p->goep_conn_id;
            req->pkt_type = GOEP_FIRST_PKT;
            strcpy((CHAR*)req->obj_mime_type, "x-obex/folder-listing");
            srv_ftp_send_msg(MSG_ID_GOEP_PULL_REQ, req);
            return MMI_TRUE;

        default: /* Incorrect state */
            SRV_FTPC_LOG_STATE_ERR();
            SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_CONNECTED);
            return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_get_file_complete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftpc_get_file_complete(S32 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ftpc_get_file_struct get_file_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_GET_FILE_COMPLETE, error_cause);
    
    if (error_cause == 0)
    {
        get_file_result.result = SRV_FTPC_GET_FILE_SUCCESS;
    }
    else if (error_cause == FS_DISK_FULL)
    {
        get_file_result.result = SRV_FTPC_GET_FILE_DISK_FULL;
    }
    else if (error_cause == FS_APP_QUOTA_FULL)
    {
        get_file_result.result = SRV_FTPC_GET_FILE_WRITE_FILE_FAIL;
    }
    else if ((error_cause == FS_MEDIA_CHANGED) ||
             (error_cause <= FS_MSDC_MOUNT_ERROR && error_cause >= FS_MSDC_NOT_PRESENT))
    {
        get_file_result.result = SRV_FTPC_GET_FILE_NO_CARD;
    }
    else
    {
        get_file_result.result = SRV_FTPC_GET_FILE_FAIL;
    }

    /* When download the last packet of a file, user have aborted.*/
    if (act_client_cntx_p->ftpc_state == SRV_FTPC_STATE_ABORTING)
    {
        SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_CONNECTED);
        if (act_client_cntx_p->abort_type == SRV_FTPC_ABORT_GETTING_FILE_FROM_APP)
        {
            get_file_result.is_abort_from_client = MMI_TRUE;
        }
        else /* (act_client_cntx_p->abort_type == SRV_FTPC_ABORT_GETTING_FILE_FROM_SERVICE) */
        {
            get_file_result.is_abort_from_client = MMI_FALSE;
        }

        srv_ftpc_notify(SRV_FTPC_EVENT_GET_FILE, (void*)&get_file_result);
    }
    else if (act_client_cntx_p->ftpc_state == SRV_FTPC_STATE_GETTING_OBJ)
    {
        SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_CONNECTED);
        get_file_result.is_abort_from_client = MMI_FALSE;
        srv_ftpc_notify(SRV_FTPC_EVENT_GET_FILE, (void*)&get_file_result);
    }
    /* user pressed end-key */
    else if (act_client_cntx_p->ftpc_state == SRV_FTPC_STATE_DISCONNECTING)
    {
        srv_ftpc_send_disconnect();
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_receiving_aborted_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftpc_receiving_aborted_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_ABORTED_HANDLE);
    if (act_client_cntx_p->fh_ftpc_recv)
    {
        FS_Close(act_client_cntx_p->fh_ftpc_recv);
        act_client_cntx_p->fh_ftpc_recv = (FS_HANDLE)NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_set_abort_req_sent_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftpc_set_abort_req_sent_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_SET_FLAG_ABORT_REQ_SENT);
    act_client_cntx_p->flag_abort_req_sent = 1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_reset_abort_req_sent_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftpc_reset_abort_req_sent_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_RESET_FLAG_ABORT_REQ_SENT);
    act_client_cntx_p->flag_abort_req_sent = 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_browse_files_failed_timer_expire_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftpc_browse_files_failed_timer_expire_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_BROWSE_FILES_FAILED_TIMER);
    if (act_client_cntx_p->fh_ftpc_recv)
    {
        FS_Close(act_client_cntx_p->fh_ftpc_recv);
        act_client_cntx_p->fh_ftpc_recv = (FS_HANDLE)NULL;
    }

    if (act_client_cntx_p->ftpc_state != SRV_FTPC_STATE_IDLE)
    {
        srv_ftpc_send_disconnect();
        SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_DISCONNECTING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_set_fs_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret       [IN]        
 * RETURNS
 *  U32 index
 *****************************************************************************/
static void srv_ftpc_set_fs_flag(S32 ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_SET_FS_FLAG, ret);
    act_client_cntx_p->client_write_file_error = ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_stop_receiving
 * DESCRIPTION
 *  when usb mass plug in, this func will be called
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftpc_stop_receiving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_STOP_RECEIVING);
    switch (act_client_cntx_p->ftpc_state)
    {
        case SRV_FTPC_STATE_GETTING_OBJ:
            srv_ftpc_receiving_aborted_handle();
            act_client_cntx_p->abort_type = SRV_FTPC_ABORT_GETTING_FILE_FROM_APP;
            SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_ABORTING);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_permit_show_pair_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bt_addr       [IN]        
 * RETURNS
 *  U32 index
 *****************************************************************************/
static MMI_BOOL srv_ftpc_permit_show_pair_scr(srv_bt_cm_bt_addr bt_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (act_client_cntx_p->ftpc_bt_device.lap == bt_addr.lap
        && act_client_cntx_p->ftpc_bt_device.uap == bt_addr.uap
        && act_client_cntx_p->ftpc_bt_device.nap == bt_addr.nap
        && act_client_cntx_p->ftpc_state == SRV_FTPC_STATE_DISCONNECTING)
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_write_lname2file
 * DESCRIPTION
 * write the long name to a new file
 * PARAMETERS
 *  utf8_name       [IN]
 *  name_length
 * RETURNS
 *  MMI_TRUE: write file success 
 *  MMI_FALSE: write file failed
 *****************************************************************************/
static S32 srv_ftpc_write_lname2file(const U16* long_name_p, U32 name_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_error = 0;
    U32  len_written = 0;
    FS_HANDLE fh;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_WRITE_LNAME2FILE);
    /* Open, Seek, Write, Close */
    fh = FS_Open((const WCHAR*)act_client_cntx_p->parsed_folder_lname, FS_READ_WRITE);
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_WRITE_LNAME2FILE_FS_OPEN, fh);

    if (fh < FS_NO_ERROR)
    {
        return fh;
    }
    
    fs_error = FS_Seek(fh, 0, FS_FILE_END);
    if (fs_error < FS_NO_ERROR)
    {
        MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_WRITE_LNAME2FILE_FS_SEEK, fs_error);
        FS_Close(fh);
        return fs_error;
    }

    act_client_cntx_p->obj_entity.offset = fs_error;
    fs_error = FS_Write(fh, (U8*)long_name_p, (name_len + 1) * ENCODING_LENGTH, (kal_uint32*)&len_written);
    if (fs_error < FS_NO_ERROR || (len_written != (name_len + 1) * ENCODING_LENGTH))
    {
        MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_WRITE_LNAME2FILE_FS_WRITE, fs_error);
    }

    FS_Close(fh);
    return fs_error;
}


#ifdef __MMI_BT_RX_ENHANCE__
/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_intbuf_write_obj_continue
 * DESCRIPTION
 *  This function is to write the pkt from 2nd pkt, and set the error flag
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftpc_intbuf_write_obj_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_INTBUF_WRITE_OBJ_CONTINUE);
    if (act_client_cntx_p->inbuf_len > 0)
    {
        U32 len_written;
        S32 ret;

        ASSERT(act_client_cntx_p->fh_ftpc_recv);

        ret = FS_Write(act_client_cntx_p->fh_ftpc_recv,
                       act_client_cntx_p->ftpc_obj_int_buff,
                       act_client_cntx_p->inbuf_len,
                       (kal_uint32*)&len_written);
        MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_INTBUF_WRITE_OBJ_CONTINUE_WRITE, ret);

        if (ret < 0)
        {
            srv_ftpc_set_fs_flag(ret);
            act_client_cntx_p->inbuf_pkt_error = SRV_FTP_PRE_PKT_ERR_FS;
            return;
        }
    }

    act_client_cntx_p->recved_obj_len += act_client_cntx_p->inbuf_len;
    return;
}
#endif /* __MMI_BT_RX_ENHANCE__ */


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_connect_rsp_handle
 * DESCRIPTION
 *  This function is to handle server MSG_ID_GOEP_CONNECT_RSP msg
 * PARAMETERS
 *  msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftpc_connect_rsp_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_connect_rsp_struct *rsp = (goep_connect_rsp_struct*)msg;
    srv_ftpc_connect_struct result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_CONNECT_RSP_HANDLE, act_client_cntx_p->ftpc_state);
    result.bd_address = act_client_cntx_p->ftpc_bt_device;
    result.cm_conn_id = rsp->cm_conn_id;
    result.req_id = rsp->req_id;
    result.is_abort_from_client = MMI_FALSE;

    if (rsp->rsp_code == GOEP_STATUS_SUCCESS)
    {
        switch (act_client_cntx_p->ftpc_state)
        {
            /* when connect cancel, there is a conect_rsp successed in MMI queue. */
            case SRV_FTPC_STATE_DISCONNECTING:
            {
                goep_disconnect_req_struct *req;

                ftpc_cntx_p->goep_conn_id = rsp->goep_conn_id;

                /* connect success, send disconnect again */
                req = (goep_disconnect_req_struct*)OslConstructDataPtr(sizeof(goep_disconnect_req_struct));
                FTP_MEMSET(req);
                req->req_id = ftpc_cntx_p->conn_id;
                req->goep_conn_id = rsp->goep_conn_id;
                srv_ftp_send_msg(MSG_ID_GOEP_DISCONNECT_REQ, req);
                break;
            }
            
            case SRV_FTPC_STATE_IDLE:
                return;

            case SRV_FTPC_STATE_CONNECTING:
            {
                goep_pull_req_struct *req;

                /* The connection is established */
                SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_GETTING_FOLDER);

                /* set ftpc context */
                ftpc_cntx_p->goep_conn_id = rsp->goep_conn_id;
                ftpc_cntx_p->g_conn_id = rsp->cm_conn_id;

                if (ftpc_cntx_p->conn_id > 0)
                {
                    srv_bt_cm_connect_ind(ftpc_cntx_p->conn_id);
                }

                req = (goep_pull_req_struct*)OslConstructDataPtr(sizeof(goep_pull_req_struct));
                FTP_MEMSET(req);
                req->goep_conn_id = rsp->goep_conn_id;
                strcpy((CHAR*)req->obj_mime_type, "x-obex/folder-listing");
                req->pkt_type = GOEP_FIRST_PKT;
                srv_ftp_send_msg(MSG_ID_GOEP_PULL_REQ, req);

                result.connect_result = SRV_FTPC_CONNECT_SUCCESS;
                srv_ftpc_notify(SRV_FTPC_EVENT_CONNECT, (void*)&result);
                break;
            }
            
            default: /* Connection establish fail */
                SRV_FTPC_LOG_STATE_ERR();
                SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_IDLE);

                if (ftpc_cntx_p->conn_id > 0)
                {
                    srv_bt_cm_stop_conn(ftpc_cntx_p->conn_id);
                    ftpc_cntx_p->conn_id = -1;
                }

                result.connect_result = SRV_FTPC_CONNECT_REJECT_FROM_SERVER;
                srv_ftpc_notify(SRV_FTPC_EVENT_CONNECT, (void*)&result);
                break;
        }
    }
    else
    {
        switch (act_client_cntx_p->ftpc_state)
        {
            /*when connect_cancel, the conn_rsp failed already comes*/
            case SRV_FTPC_STATE_DISCONNECTING:
                SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_IDLE);

                if (ftpc_cntx_p->conn_id > 0)
                {
                    srv_bt_cm_stop_conn(ftpc_cntx_p->conn_id);
                    ftpc_cntx_p->conn_id = -1;
                }

                result.is_abort_from_client = MMI_TRUE;
                result.connect_result = SRV_FTPC_CONNECT_FAIL;
                srv_ftpc_notify(SRV_FTPC_EVENT_CONNECT, (void*)&result);

                act_client_cntx_p->abort_type = SRV_FTPC_ABORT_NONE;
                break;
    
            case SRV_FTPC_STATE_CONNECTING:
                /* passkey screen del callback */
                /* mmi_bt_reject_passkey_ind(act_client_cntx_p->ftpc_bt_device.lap,  */
                /*                           act_client_cntx_p->ftpc_bt_device.uap,  */
                /*                           act_client_cntx_p->ftpc_bt_device.nap); */
                SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_IDLE);
                if (ftpc_cntx_p->conn_id > 0)
                {
                    srv_bt_cm_stop_conn(ftpc_cntx_p->conn_id);
                    ftpc_cntx_p->conn_id = -1;
                }
                
                if (rsp->rsp_code == GOEP_STATUS_SCO_REJECT)
                {
                    /* sco link support for MT6601 */
                    result.connect_result = SRV_FTPC_CONNECT_SCO_REJECT;
                }
                /*else if (rsp->rsp_code == GOEP_STATUS_BUSY)
                {
                    mmi_ftpc_notify_recv_err(SRV_FTPC_NOTIFY_GOEP_STATUS_BUSY);
                }*/
                else
                {
                    result.connect_result = SRV_FTPC_CONNECT_REJECT_FROM_SERVER;
                }

                srv_ftpc_notify(SRV_FTPC_EVENT_CONNECT, (void*)&result);
                break;

            case SRV_FTPC_STATE_IDLE:
                return;

            default:
                SRV_FTPC_LOG_STATE_ERR();
                SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_IDLE);
                if (ftpc_cntx_p->conn_id > 0)
                {
                    srv_bt_cm_stop_conn(ftpc_cntx_p->conn_id);
                    ftpc_cntx_p->conn_id = -1;
                }

                result.connect_result = SRV_FTPC_CONNECT_REJECT_FROM_SERVER;
                srv_ftpc_notify(SRV_FTPC_EVENT_CONNECT, (void*)&result);
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_pull_rsp_handle
 * DESCRIPTION
 *  This function is to handle server MSG_ID_GOEP_PULL_RSP msg
 * PARAMETERS
 *  msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftpc_pull_rsp_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_pull_rsp_struct *rsp = (goep_pull_rsp_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_PULL_RSP_HANDLE, act_client_cntx_p->ftpc_state);

    switch (act_client_cntx_p->ftpc_state)
    {
        case SRV_FTPC_STATE_ABORTING:
            /* omit all the pull_rsp after send abort_req, and wait pull_rsp only*/
            if (act_client_cntx_p->flag_abort_req_sent == 0)
            {
                /* omit this pkt, and send abort req, and set the flag, and reset the vars */
                srv_ftpc_send_abort(rsp->goep_conn_id);
                srv_ftpc_set_abort_req_sent_flag();
                //srv_ftpc_receiving_aborted_handle();
            }
            return;

        case SRV_FTPC_STATE_GETTING_FOLDER:
            srv_ftpc_get_folder(rsp);
            return;

        /* case SRV_FTPC_STATE_PARSING_FOLDER: */
        /*     return; */

        case SRV_FTPC_STATE_GETTING_OBJ:
            srv_ftpc_get_obj(rsp);
            return;

        case SRV_FTPC_STATE_DISCONNECTING:
        {
            if ((rsp->pkt_type == GOEP_FINAL_PKT) || (rsp->pkt_type == GOEP_SINGLE_PKT))
            {
                goep_disconnect_req_struct *req;

                req = (goep_disconnect_req_struct*)OslConstructDataPtr(sizeof(goep_disconnect_req_struct));
                FTP_MEMSET(req);
                req->goep_conn_id = ftpc_cntx_p->goep_conn_id;
                /* send disconnect req and connect cnf fail to CM */
                srv_ftp_send_msg(MSG_ID_GOEP_DISCONNECT_REQ, req);
            }
            else
            {
                goep_abort_req_struct *req;
                req = (goep_abort_req_struct*)OslConstructDataPtr(sizeof(goep_abort_req_struct));
                FTP_MEMSET(req);
                req->goep_conn_id = ftpc_cntx_p->goep_conn_id;
                srv_ftp_send_msg(MSG_ID_GOEP_ABORT_REQ, req);
            }
            return;
        }

        case SRV_FTPC_STATE_IDLE:
        case SRV_FTPC_STATE_TPDISCONNECTING:
            /*Omit it, when setting_folder, tpdiscon may be sent*/
            return;
        
        default: /* wrong states */
            SRV_FTPC_LOG_STATE_ERR();
            if (act_client_cntx_p->fh_ftpc_recv)
            {
                FS_Close(act_client_cntx_p->fh_ftpc_recv);
                act_client_cntx_p->fh_ftpc_recv = (FS_HANDLE)NULL;
            }

            SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_CONNECTED);
            {
                srv_ftpc_set_folder_struct set_folder_result;
                set_folder_result.result = SRV_FTPC_SET_FOLDER_NOT_ALLOWED;
                srv_ftpc_notify(SRV_FTPC_EVENT_SET_FOLDER, (void*)&set_folder_result);
            }
            return;
    }
}


void srv_ftpc_set_folder_rsp_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_set_folder_rsp_struct *rsp = (goep_set_folder_rsp_struct*)msg;
    srv_ftpc_set_folder_struct set_folder_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_SET_FOLDER_RSP_HANDLE, act_client_cntx_p->ftpc_state);

    if (rsp->rsp_code == GOEP_STATUS_SUCCESS)
    {
        /* Set the folder successfully, then start to get folder content */
        switch (act_client_cntx_p->ftpc_state)
        {
            case SRV_FTPC_STATE_SETTING_FOLDER:
                set_folder_result.result = SRV_FTPC_SET_FOLDER_SUCCESS;
                break;

            case SRV_FTPC_STATE_SETTING_BACK_FOLDER:
                set_folder_result.result = SRV_FTPC_SET_FOLDER_BACK_SUCCESS;
                break;

            case SRV_FTPC_STATE_SETTING_ROOT_FOLDER:
                set_folder_result.result = SRV_FTPC_SET_FOLDER_BACK_ROOT_SUCCESS;
                break;

            case SRV_FTPC_STATE_TPDISCONNECTING:
                /*omit it, tpdisconn_req have sent*/
                /* srv_ftpc_send_disconnect(); */
                return;

             default: /*error state*/
                SRV_FTPC_LOG_STATE_ERR();
                SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_CONNECTED);
                /* Notify MMI Screen */
                return;
        }

        /* delete the parsed file and the long name file*/
        FS_Delete((const WCHAR*)act_client_cntx_p->parsed_folder);
        FS_Delete((const WCHAR*)act_client_cntx_p->parsed_folder_lname);
        FS_Delete((const WCHAR*)act_client_cntx_p->parsed_folder_fileindex);

        SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_CONNECTED);
        srv_ftpc_get_folder_content(); /* must success, so need not to judge the return value */
    }
    else
    {
        switch (act_client_cntx_p->ftpc_state)
        {
            case SRV_FTPC_STATE_SETTING_FOLDER:
            {
                /* forward folder failed, not disconnect*/
                SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_CONNECTED);
                set_folder_result.result = SRV_FTPC_SET_FOLDER_REJECT_FROM_SERVER;
                
                if (act_client_cntx_p->fh_ftpc_recv)
                {
                    FS_Close(act_client_cntx_p->fh_ftpc_recv);
                    act_client_cntx_p->fh_ftpc_recv = (FS_HANDLE)NULL;
                }
            }
            break;
            
            case SRV_FTPC_STATE_SETTING_BACK_FOLDER:
            case SRV_FTPC_STATE_SETTING_ROOT_FOLDER:
            {
                /*when setting back/root  folder failed, popup and disconnect it*/
                SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_CONNECTED);

                StartTimer(BT_FTPC_BROWSE_FILES_FAILED_TIMER,
                           FTPC_BROWSE_FILES_FAILED_DELAY_DUR,
                           srv_ftpc_browse_files_failed_timer_expire_handle);

                set_folder_result.result = SRV_FTPC_SET_FOLDER_BACK_FAIL;
            }
            break;

            case SRV_FTPC_STATE_DISCONNECTING:
                srv_ftpc_send_disconnect();
                return;

            case SRV_FTPC_STATE_TPDISCONNECTING:
                /*Omit it, when setting_folder, tpdiscon may be sent*/
                return;

            default: /*error state*/
                return;
        }
    }

    srv_ftpc_notify(SRV_FTPC_EVENT_SET_FOLDER, (void*)&set_folder_result);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftpc_abort_rsp_handle
 * DESCRIPTION
 *  This function is to handle server MSG_ID_GOEP_ABORT_RSP msg
 * PARAMETERS
 *  msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftpc_abort_rsp_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_ABORT_RSP_HANDLE, act_client_cntx_p->ftpc_state);

    if (act_client_cntx_p->ftpc_state == SRV_FTPC_STATE_ABORTING)
    {
        if (act_client_cntx_p->abort_type == SRV_FTPC_ABORT_GETTING_FILE_FROM_SERVICE)
        {
            srv_ftpc_get_file_complete(act_client_cntx_p->client_write_file_error);
        }
        else if (act_client_cntx_p->abort_type == SRV_FTPC_ABORT_GETTING_FILE_FROM_APP)
        {
            srv_ftpc_get_file_complete(-1); /* -1 means get_file_fail */
        }
        else if (act_client_cntx_p->abort_type == SRT_FTPC_ABORT_GETTING_FOLDER_CONTENT_FROM_SERVICE)
        {
            srv_ftpc_get_folder_error_handle(GOEP_FINAL_PKT);
        }

        act_client_cntx_p->abort_type = SRV_FTPC_ABORT_NONE;
    }
    else if (act_client_cntx_p->ftpc_state == SRV_FTPC_STATE_DISCONNECTING)
    {
        goep_disconnect_req_struct *req;

        req = (goep_disconnect_req_struct*)OslConstructDataPtr(sizeof(goep_disconnect_req_struct));
        FTP_MEMSET(req);
        req->goep_conn_id = ftpc_cntx_p->goep_conn_id;
        srv_ftp_send_msg(MSG_ID_GOEP_DISCONNECT_REQ, req);
    }

    srv_ftpc_reset_abort_req_sent_flag();
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_disconnect_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
void srv_ftpc_disconnect_ind_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ftpc_disconnect_struct disconnect_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (act_client_cntx_p->ftpc_state)
    {
        case SRV_FTPC_STATE_IDLE:
            /* ASSERT(0); */
            return;

        /* should happen in cancel case not here */
        case SRV_FTPC_STATE_CONNECTING:
            /* SRV_FTPC_LOG_STATE_ERR(); */
            ASSERT(0);
            break;

        case SRV_FTPC_STATE_DISCONNECTING:
        case SRV_FTPC_STATE_TPDISCONNECTING:
            SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_IDLE);
            if (act_client_cntx_p->abort_type == SRV_FTPC_ABORT_CONNECTION_FROM_APP)
            {
                srv_ftpc_connect_struct result;

                if (ftpc_cntx_p->conn_id > 0)
                {
                    srv_bt_cm_stop_conn(ftpc_cntx_p->conn_id);
                    ftpc_cntx_p->conn_id = -1;
                }
                                      
                result.is_abort_from_client = MMI_TRUE;
                result.bd_address = act_client_cntx_p->ftpc_bt_device;
                result.cm_conn_id = 0;
                result.req_id = ftpc_cntx_p->conn_id;
                result.connect_result = SRV_FTPC_CONNECT_FAIL;
                srv_ftpc_notify(SRV_FTPC_EVENT_CONNECT, (void*)&result);
            }
            else
            {
                if (ftpc_cntx_p->conn_id > 0)
                {
                    srv_bt_cm_stop_conn(ftpc_cntx_p->conn_id);
                    ftpc_cntx_p->conn_id = -1;
                }

                disconnect_result.is_from_client = MMI_TRUE;
                disconnect_result.bd_address = act_client_cntx_p->ftpc_bt_device;
                disconnect_result.cm_conn_id = ftpc_cntx_p->g_conn_id;
                srv_ftpc_notify(SRV_FTPC_EVENT_DISCONNECT, (void*)&disconnect_result);
            }

            act_client_cntx_p->abort_type = SRV_FTPC_ABORT_NONE;
            srv_ftpc_connection_terminated();
            srv_bt_cm_unreg_pairing_permission(SRV_BT_CM_OBEX_FILE_TRANSFER_CLIENT_UUID);

            break;

        /* other connected states */
        default:
            SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_IDLE);
            if (ftpc_cntx_p->conn_id > 0)
            {
                srv_bt_cm_stop_conn(ftpc_cntx_p->conn_id);
                ftpc_cntx_p->conn_id = -1;
            }

            disconnect_result.is_from_client = MMI_FALSE;
            disconnect_result.bd_address = act_client_cntx_p->ftpc_bt_device;
            disconnect_result.cm_conn_id = ftpc_cntx_p->g_conn_id;
            srv_ftpc_notify(SRV_FTPC_EVENT_DISCONNECT, (void*)&disconnect_result);
            srv_ftpc_connection_terminated();
            srv_bt_cm_unreg_pairing_permission(SRV_BT_CM_OBEX_FILE_TRANSFER_CLIENT_UUID);
            break;
    }
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_parse_folder_content_continue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
static void srv_ftpc_parse_folder_content_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS,
              SRV_FTPC_GET_FOLDER_PARSE_RESUME,
              act_client_cntx_p->entity_cnt_cur_folder,
              act_client_cntx_p->parsed_folder_item_cnt);

    if (act_client_cntx_p->ftpc_state == SRV_FTPC_STATE_PARSING_FOLDER) /* else: such as end-key pressed! */
    {
        ret = xml_resume_parse(act_client_cntx_p->xml_parser_p);
        if (ret == XML_RESULT_OK)
        {
            /* threshold for release MMI control to other tasks */
            if (act_client_cntx_p->parsed_folder_item_cnt == SRV_FTPC_MAX_PARSE_THRESHOLD)
            {
                act_client_cntx_p->parsed_folder_item_cnt = 0;
                srv_ftpc_send_parse_continue_msg();
            }
            else /* success */
            {
                srv_ftpc_flush_obj_entity();
                srv_ftpc_parse_folder_content_complete();
            }
        }
        else /* parse fail */
        {
            srv_ftpc_parse_folder_content_error_handle(SRV_FTPC_FOLDER_PARTIAL);
        }
    }
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_parse_folder_content_complete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURN
 *  void
 ******************************************************************************/
static void srv_ftpc_parse_folder_content_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ftp_file_writer_struct *writer = &(act_client_cntx_p->folder_content);
    srv_ftpc_get_folder_struct get_folder_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS,
              SRV_FTPC_GET_FOLDER_PARSE_DONE,
              act_client_cntx_p->entity_cnt_cur_folder,
              act_client_cntx_p->parsed_folder_item_cnt);

    FS_Close(writer->fd);
    writer->fd = (FS_HANDLE)NULL;
    FS_Close(act_client_cntx_p->fh_ftpc_fileindex);
    act_client_cntx_p->fh_ftpc_fileindex = (FS_HANDLE)NULL;

    xml_close_parser(act_client_cntx_p->xml_parser_p);
    free_ctrl_buffer(act_client_cntx_p->xml_parser_p);
    act_client_cntx_p->xml_parser_p = NULL;
    act_client_cntx_p->parsed_folder_item_cnt = 0;
    FS_Delete((const WCHAR*)act_client_cntx_p->folder_obj);
    SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_CONNECTED);

    get_folder_result.result = SRV_FTPC_GET_FOLDER_SUCCESS;
    get_folder_result.entity_cnt = act_client_cntx_p->entity_cnt_cur_folder;
    get_folder_result.file_cnt = act_client_cntx_p->file_cnt_cur_folder;
    srv_ftpc_notify(SRV_FTPC_EVENT_GET_FOLDER_CONTENT, (void*)&get_folder_result);
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_send_parse_continue_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURN
 *  void
 ******************************************************************************/
static void srv_ftpc_send_parse_continue_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    ilm_struct message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//     message.src_mod_id = MOD_MMI;
//     message.dest_mod_id = MOD_MMI;
//     message.msg_id = MSG_ID_MMI_BT_FTPC_PARSE_CONTINUE;
//     message.sap_id = MMI_MMI_SAP;
//     message.local_para_ptr = NULL;
//     message.peer_buff_ptr = NULL;
//     OslMsgSendExtQueue(&message);

    mmi_frm_send_ilm(
        MOD_MMI,
        MSG_ID_MMI_BT_FTPC_PARSE_CONTINUE,
        NULL,
        NULL);
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_SEND_PARSE_CONTINUE_MSG);
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_get_folder_error_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pkt_type    [IN]
 * RETURNS
 *  void
 ******************************************************************************/
static void srv_ftpc_get_folder_error_handle(goep_pkt_type_enum pkt_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ftpc_get_folder_struct get_folder_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (act_client_cntx_p->fh_ftpc_recv)
    {
        FS_Close(act_client_cntx_p->fh_ftpc_recv);
        act_client_cntx_p->fh_ftpc_recv = (FS_HANDLE)NULL;
    }
    FS_Delete((const WCHAR*)act_client_cntx_p->folder_obj);

    if ((pkt_type == GOEP_SINGLE_PKT) || (pkt_type == GOEP_FINAL_PKT))
    {
        SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_CONNECTED);

        get_folder_result.result = SRV_FTPC_GET_FOLDER_FAIL;
        get_folder_result.entity_cnt = 0;
        get_folder_result.file_cnt = 0;
        srv_ftpc_notify(SRV_FTPC_EVENT_GET_FOLDER_CONTENT, (void*)&get_folder_result);
    }
    else /* Not last packet or single packet, we have to send abort out */
    {
        srv_ftpc_send_abort(ftpc_cntx_p->goep_conn_id);
        srv_ftpc_set_abort_req_sent_flag();
        SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_ABORTING);
        act_client_cntx_p->abort_type = SRT_FTPC_ABORT_GETTING_FOLDER_CONTENT_FROM_SERVICE; /* notify mmi in abort response */
    }
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_parse_folder_content_error_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURN
 *  void
 ******************************************************************************/
static void srv_ftpc_parse_folder_content_error_handle(U8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ftp_file_writer_struct *writer = &(act_client_cntx_p->folder_content);
    srv_ftpc_get_folder_struct get_folder_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_PARSE_FOLDER_CONTENT_ERROR_HANDLE, status);
    if (writer->fd >= 0)
    {
        FS_Close(writer->fd);
    }
    writer->fd = (FS_HANDLE)NULL;

    if (act_client_cntx_p->fh_ftpc_fileindex >= 0)
    {
        FS_Close(act_client_cntx_p->fh_ftpc_fileindex);
    }
    act_client_cntx_p->fh_ftpc_fileindex = (FS_HANDLE)NULL;

    free_ctrl_buffer(act_client_cntx_p->xml_parser_p);
    act_client_cntx_p->xml_parser_p = NULL;
    FS_Delete((const WCHAR*)act_client_cntx_p->folder_obj);
    if (status == SRV_FTPC_FOLDER_EMPTY)
    {
        get_folder_result.result = SRV_FTPC_GET_FOLDER_FAIL;
        get_folder_result.entity_cnt = 0;
        get_folder_result.file_cnt = 0;
    }
    else
    {
        get_folder_result.result =
            act_client_cntx_p->entity_cnt_cur_folder > 0 ?
            SRV_FTPC_GET_FOLDER_PATIAL_CONTENT :
            SRV_FTPC_GET_FOLDER_FAIL;

        get_folder_result.entity_cnt = act_client_cntx_p->entity_cnt_cur_folder;
        get_folder_result.file_cnt = act_client_cntx_p->file_cnt_cur_folder;
    }

    srv_ftpc_notify(SRV_FTPC_EVENT_GET_FOLDER_CONTENT, (void*)&get_folder_result);

    if (act_client_cntx_p->fh_ftpc_recv)
    {
        FS_Close(act_client_cntx_p->fh_ftpc_recv);
        act_client_cntx_p->fh_ftpc_recv = (FS_HANDLE)NULL;
    }
    FS_Delete((const WCHAR*)act_client_cntx_p->folder_obj);
    SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_CONNECTED);
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_parse_folder_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 ******************************************************************************/
static S32 srv_ftpc_parse_folder_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    S32 result = 0;
    srv_ftp_file_writer_struct *writer = &(act_client_cntx_p->folder_content);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (act_client_cntx_p->xml_parser_p == NULL)
    {
        act_client_cntx_p->xml_parser_p = get_ctrl_buffer(sizeof(XML_PARSER_STRUCT));
    }

    memset(act_client_cntx_p->xml_parser_p, 0, sizeof(XML_PARSER_STRUCT));
    memset(writer, 0, sizeof(srv_ftp_file_writer_struct));
    /* create long name file first */
    fh = FS_Open((const WCHAR*)act_client_cntx_p->parsed_folder_lname, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (fh >= 0)
    {
        FS_Close(fh);
        writer->fd = FS_Open((const WCHAR*)act_client_cntx_p->parsed_folder, FS_READ_WRITE | FS_CREATE_ALWAYS);
        act_client_cntx_p->fh_ftpc_fileindex = 
            FS_Open((const WCHAR*)act_client_cntx_p->parsed_folder_fileindex, FS_READ_WRITE | FS_CREATE_ALWAYS);

        if ((writer->fd >= 0) && (act_client_cntx_p->fh_ftpc_fileindex >= 0))
        {
            result = xml_new_parser(act_client_cntx_p->xml_parser_p);
            if (result >= 0)
            {
                act_client_cntx_p->entity_cnt_cur_folder = 0;
                act_client_cntx_p->parsed_folder_item_cnt = 0;
                act_client_cntx_p->file_cnt_cur_folder = 0;
                act_client_cntx_p->fileindex_in_folder[SRV_FTPC_MAX_FILE_COUNT_PER_WRITER_BUF] = 0;
                return 1;
            }
        }
    }

    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_PARSE_FOLDER_INIT_ERR);
    return -1;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_get_folder_cntx_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
static S32 srv_ftpc_get_folder_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ftp_work_folder_init())
    {
        if (act_client_cntx_p->fh_ftpc_recv) /* close file first if necessary */
        {
            FS_Close(act_client_cntx_p->fh_ftpc_recv);
            act_client_cntx_p->fh_ftpc_recv = (FS_HANDLE)NULL;
        }
        /* Create folder listing object file */
        h = FS_Open((const WCHAR*)(act_client_cntx_p->folder_obj), (FS_READ_WRITE | FS_CREATE_ALWAYS));
        MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_GET_FOLDER_CNTX_INIT_OPEN, h);
        if (h >= 0)
        {
            act_client_cntx_p->fh_ftpc_recv = h;
            return 1;
        }
    }

    return -1;    
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_send_get_folder_continue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
static void srv_ftpc_send_get_folder_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_pull_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (goep_pull_req_struct*)OslConstructDataPtr(sizeof(goep_pull_req_struct));
    FTP_MEMSET(req);
    req->goep_conn_id = ftpc_cntx_p->goep_conn_id;
    strcpy((CHAR*)req->obj_mime_type, "x-obex/folder-listing");
    req->pkt_type = GOEP_NORMAL_PKT;
    srv_ftp_send_msg(MSG_ID_GOEP_PULL_REQ, req);
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_write_buf2file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURN
 *  
 ******************************************************************************/
static S32 srv_ftpc_write_buf2file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 written;
    srv_ftp_file_writer_struct *composer = &(act_client_cntx_p->folder_content);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((SRV_FTP_MAX_FILE_WRITER_BUF_SIZE - composer->buflen) < sizeof(srv_ftp_entity_int_struct))
    {
        srv_ftpc_record_file_index();
        ret = FS_Write(
            act_client_cntx_p->fh_ftpc_fileindex,
            act_client_cntx_p->fileindex_in_folder,
            act_client_cntx_p->fileindex_in_folder[SRV_FTPC_MAX_FILE_COUNT_PER_WRITER_BUF] * sizeof(U16),
            &written);
        if (written < (act_client_cntx_p->fileindex_in_folder[SRV_FTPC_MAX_FILE_COUNT_PER_WRITER_BUF] * sizeof(U16)))
        {
            MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_WRITE_BUF2FILE_FS_WRITE, ret);
            return ret;
        }

        ret = FS_Write(composer->fd, composer->buf, composer->buflen, &(composer->written));
        srv_ftpc_record_written_count(composer->written);
        if (composer->written < composer->buflen) /* if (ret < FS_NO_ERROR) */
        {
            MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_WRITE_BUF2FILE_FS_WRITE, ret);
            return ret;
        }

        composer->buflen = 0;
        composer->written = 0;
        act_client_cntx_p->fileindex_in_folder[SRV_FTPC_MAX_FILE_COUNT_PER_WRITER_BUF] = 0;
        
    }

    return 0;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_record_written_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  written    [IN]
 * RETURN
 *  void
 ******************************************************************************/
static void srv_ftpc_record_written_count(U32 written)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    kal_char const *buf;
    srv_ftp_entity_int_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    written /= sizeof(srv_ftp_entity_int_struct);
    act_client_cntx_p->entity_cnt_cur_folder += written;
    act_client_cntx_p->parsed_folder_item_cnt += written;

    for (i = 0, buf = (act_client_cntx_p->folder_content).buf; i < written; ++i)
    {
        obj = (srv_ftp_entity_int_struct*)buf;
        if (obj->type == SRV_FTP_OBJ_TYPE_FILE)
        {
            ++act_client_cntx_p->file_cnt_cur_folder;
        }
        buf += sizeof(srv_ftp_entity_int_struct);
    }
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_record_file_index
 * DESCRIPTION
 *  this function is to remember the file index in file browser screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
static void srv_ftpc_record_file_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    kal_char const *buf;
    srv_ftp_entity_int_struct *obj;
    srv_ftp_file_writer_struct *writer = &(act_client_cntx_p->folder_content);
    U32 count, index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = writer->buflen / sizeof(srv_ftp_entity_int_struct);
    for (index = 0, i = 0, buf = (act_client_cntx_p->folder_content).buf; i < count; ++i)
    {
        obj = (srv_ftp_entity_int_struct*)buf;
        if (obj->type == SRV_FTP_OBJ_TYPE_FILE)
        {
            act_client_cntx_p->fileindex_in_folder[index++] = act_client_cntx_p->entity_cnt_cur_folder + i;
        }
        buf += sizeof(srv_ftp_entity_int_struct);
    }

    act_client_cntx_p->fileindex_in_folder[SRV_FTPC_MAX_FILE_COUNT_PER_WRITER_BUF] = index; /* remember file count in this time */
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_flush_obj_entity
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
static void srv_ftpc_flush_obj_entity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ftp_file_writer_struct *writer = &(act_client_cntx_p->folder_content);
    S32 result;
    U32 written;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (writer->written == 0 && writer->buflen > 0)
    {
        srv_ftpc_record_file_index();
        result = FS_Write(
            act_client_cntx_p->fh_ftpc_fileindex,
            act_client_cntx_p->fileindex_in_folder,
            act_client_cntx_p->fileindex_in_folder[SRV_FTPC_MAX_FILE_COUNT_PER_WRITER_BUF] * sizeof(U16),
            &written);
        if (written < (act_client_cntx_p->fileindex_in_folder[SRV_FTPC_MAX_FILE_COUNT_PER_WRITER_BUF] * sizeof(U16)))
        {
            MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_FLUSH_OBJ_ENTITY_ERR, result);
            return;
        }

        result = FS_Write(writer->fd, writer->buf, writer->buflen, &writer->written);
        srv_ftpc_record_written_count(writer->written);
        if (result < FS_NO_ERROR)
        {
            MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_FLUSH_OBJ_ENTITY_ERR, result);
        }
    }
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_connection_terminated
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURN VALUE LIST
 *  vodi
 ******************************************************************************/
void srv_ftpc_connection_terminated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_CONNECTION_TERMINATED);

    /* Getting folder:  open temp xhtml file;
     * Parsing: open parsed file, (temp xhtml file is opened by xml parser;  (parsing state)
     * Parsed achieved: temp xhtml file is deleted;
     * Getting file: open a temp file;
     */
 
    /* Parsing */
    if (act_client_cntx_p->xml_parser_p)
    {
        xml_close_parser(act_client_cntx_p->xml_parser_p);
        free_ctrl_buffer(act_client_cntx_p->xml_parser_p);
        act_client_cntx_p->xml_parser_p = NULL;

        /* delete the temp xhtml file */
        FS_Delete((const WCHAR*)act_client_cntx_p->folder_obj);

        /* delete the parsed file*/
        if (act_client_cntx_p->folder_content.fd)
        {
            FS_Close(act_client_cntx_p->folder_content.fd);
            FS_Delete((const WCHAR*)(act_client_cntx_p->parsed_folder));
            act_client_cntx_p->folder_content.fd = (FS_HANDLE)NULL; 
        }


        if (act_client_cntx_p->fh_ftpc_fileindex)
        {
            FS_Close(act_client_cntx_p->fh_ftpc_fileindex);
            FS_Delete((const WCHAR*)(act_client_cntx_p->parsed_folder_fileindex));
            act_client_cntx_p->fh_ftpc_fileindex = (FS_HANDLE)NULL;
        }
    }
    else
    {
        srv_ftpc_receiving_aborted_handle();

        /* delete the temp xhtml file */
        FS_Delete((const WCHAR*)act_client_cntx_p->folder_obj);

        /* delete the parsed file*/ 
        FS_Delete((const WCHAR*)act_client_cntx_p->parsed_folder);

        FS_Delete((const WCHAR*)(act_client_cntx_p->parsed_folder_fileindex));
    }

    /* delete the parsed long name file*/ 
    FS_Delete((const WCHAR*)act_client_cntx_p->parsed_folder_lname);

    ftpc_cntx_p->g_conn_id = 0xFF;

    /* Clear shared buffer */
    //memset(act_client_cntx_p->ftpc_obj_buff, 0, MMI_OBEX_PROFILE_SHARE_BUF_SIZE);
}


/********************************************************************************/
/*                                  INTERNAL API                                */
/********************************************************************************/
/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_get_total_obj_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
U32 srv_ftpc_get_total_obj_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return act_client_cntx_p->total_recv_obj_len;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_get_recved_obj_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ******************************************************************************/
U32 srv_ftpc_get_recved_obj_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return act_client_cntx_p->recved_obj_len;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_get_obj_info_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index    [IN]
 *  entity_p    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
S32 srv_ftpc_get_obj_info_internal(U16 index, srv_ftp_entity_int_struct* entity_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 offset, len;
    S32 result = -1;
    FS_HANDLE fh_parsed_file = (FS_HANDLE)NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fh_parsed_file = FS_Open((const WCHAR*)act_client_cntx_p->parsed_folder, FS_READ_ONLY);
    if (fh_parsed_file >= FS_NO_ERROR)
    {
        offset = (U32)index * (sizeof(srv_ftp_entity_int_struct));
        result = FS_Seek(fh_parsed_file, offset, FS_FILE_BEGIN);
        if (result >= FS_NO_ERROR)
        {
            result = FS_Read(fh_parsed_file, (void*)entity_p, sizeof(srv_ftp_entity_int_struct), &len);
        }
    }

    if (fh_parsed_file != (FS_HANDLE)NULL)
    {
        FS_Close(fh_parsed_file);
    }

    if (result < FS_NO_ERROR)
    {
        MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_GET_OBJ_INFO_INTERNAL_ERR, result);
    }

    return result;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_get_obj_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hd    [IN]
 *  index    [IN]
 *  entity_p    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
S32 srv_ftpc_get_obj_info(S32 hd, U16 index, srv_ftp_entity_struct* entity_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = -1;
    srv_ftp_entity_int_struct entity;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ftpc_is_valid_handle(hd))
    {
        result = srv_ftpc_get_obj_info_internal(index, &entity);
        if (result >= FS_NO_ERROR)
        {
            memcpy(entity_p, &entity, sizeof(srv_ftp_entity_struct));
        }
    }

    if (result < FS_NO_ERROR)
    {
        MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_GET_OBJ_INFO_ERR, result);
    }
        
    return result;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_get_obj_detail_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hd    [IN]
 *  index    [IN]
 *  actual_name_p    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
S32 srv_ftpc_get_obj_detail_info(S32 hd, U16 index, U16* actual_name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;
    S32 result = -1;
    srv_ftp_entity_int_struct entity;
    FS_HANDLE fh_parsed_file = (FS_HANDLE)NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ftpc_is_valid_handle(hd))
    {
        result = srv_ftpc_get_obj_info_internal(index, &entity);
        if (result >= 0)
        {
            if (entity.actual_name_len <= MAX_SUBMENU_CHARACTERS)
            {
                mmi_ucs2cpy((CHAR*)actual_name_p, (CHAR*)(entity.name));
            }
            else
            {
                fh_parsed_file = FS_Open((const WCHAR*)act_client_cntx_p->parsed_folder_lname, FS_READ_ONLY);
                if (fh_parsed_file >= FS_NO_ERROR)
                {
                    result = FS_Seek(fh_parsed_file, entity.offset, FS_FILE_BEGIN);
                    if (result >= FS_NO_ERROR)
                    {
                        result = FS_Read(fh_parsed_file, (void*)actual_name_p, (entity.actual_name_len + 1) * ENCODING_LENGTH, &len);
                    }
                }
            }
        }

        if (fh_parsed_file != (FS_HANDLE)NULL)
        {
            FS_Close(fh_parsed_file);
        }
    }
    if (result < FS_NO_ERROR)
    {
        MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_GET_OBJ_DETAIL_INFO_ERR, result);
    }
    
    return result;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_get_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hd    [IN]
 *  index    [IN]
 *  recv_path    [IN]
 *  
 * RETURNS
 *  S32
 ******************************************************************************/
S32 srv_ftpc_get_file(S32 hd, U16 index, const U16* recv_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_pull_req_struct *req;
    FS_HANDLE h;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_GET_FILE, act_client_cntx_p->ftpc_state);
    if (srv_ftpc_is_valid_handle(hd))
    {
        if (act_client_cntx_p->ftpc_state > SRV_FTPC_STATE_CONNECTED)
        {
            SRV_FTPC_LOG_STATE_ERR();
            return SRV_FTPC_GET_FILE_FAIL;
        }

        if (srv_ftpc_get_obj_detail_info(hd, index, act_client_cntx_p->actual_name) < FS_NO_ERROR)
        {
            //ASSERT(0);
            return SRV_FTPC_GET_FILE_FAIL;
        }

        act_client_cntx_p->total_recv_obj_len = SRV_FTP_UNKNOWN_SIZE;
        act_client_cntx_p->recved_obj_len = 0;
        act_client_cntx_p->client_write_file_error = 0;
        //act_client_cntx_p->storage_drive = (U8)recv_path[0];

        h = FS_Open((U16*)recv_path, (FS_READ_WRITE | FS_CREATE_ALWAYS));
        if (h >= FS_NO_ERROR)
        {
            switch (act_client_cntx_p->ftpc_state)
            {
                case SRV_FTPC_STATE_CONNECTED:
                    SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_GETTING_OBJ);
                    break;

               /*  case SRV_FTPC_STATE_ABORTING: */
               /*      return SRV_FTPC_GET_FILE_GOEP_STATUS_BUSY; */

                default: /* Incorrect state, callback and return error */
                    SRV_FTPC_LOG_STATE_ERR();
                    if (act_client_cntx_p->fh_ftpc_recv)
                    {
                        FS_Close(act_client_cntx_p->fh_ftpc_recv);
                        act_client_cntx_p->fh_ftpc_recv = (FS_HANDLE)NULL;
                    }
                    SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_CONNECTED);
                    return SRV_FTPC_GET_FILE_FAIL;
            }

            act_client_cntx_p->fh_ftpc_recv = h;
#ifdef __MMI_BT_RX_ENHANCE__
            act_client_cntx_p->inbuf_pkt_error = SRV_FTP_PRE_PKT_ERR_NONE;
#endif /* __MMI_BT_RX_ENHANCE__ */

            req = (goep_pull_req_struct*)OslConstructDataPtr(sizeof(goep_pull_req_struct));
            FTP_MEMSET(req);
            req->goep_conn_id = ftpc_cntx_p->goep_conn_id;
            req->pkt_type = GOEP_FIRST_PKT;
            srv_ftp_obj_name_swapcpy((CHAR*)req->obj_name, (CHAR*)act_client_cntx_p->actual_name);

            srv_ftp_send_msg(MSG_ID_GOEP_PULL_REQ, req);
            return SRV_FTPC_GET_FILE_SUCCESS;
        }
        else
        {
            srv_ftpc_set_fs_flag((S32)h);
        }
    }

    return SRV_FTPC_GET_FILE_FAIL;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_get_fileindex
 * DESCRIPTION
 *  this function is to get the n-th file index in the folder content
 * PARAMETERS
 *  hd       [IN]    service handle
 *  index    [IN]    nth file
 *  
 * RETURNS
 *  index    the file index in the folder content, note:0xFF means no such file index
 ******************************************************************************/
U16 srv_ftpc_get_fileindex(S32 hd, U16 index)
{
    U16 fidx_in_folder = 0xFF;
    U32 offset, len;
    S32 result = -1;
    FS_HANDLE fh_fidx = (FS_HANDLE)NULL;

    if (srv_ftpc_is_valid_handle(hd) && (index < act_client_cntx_p->file_cnt_cur_folder))
    {
        fh_fidx = FS_Open((const WCHAR*)act_client_cntx_p->parsed_folder_fileindex, FS_READ_ONLY);
        if (fh_fidx >= FS_NO_ERROR)
        {
            offset = (U32)index * (sizeof(U16));
            result = FS_Seek(fh_fidx, offset, FS_FILE_BEGIN);
            if (result >= FS_NO_ERROR)
            {
                result = FS_Read(fh_fidx, (void*)&fidx_in_folder, sizeof(U16), &len);
            }
        }
    }

    if (fh_fidx != (FS_HANDLE)NULL)
    {
        FS_Close(fh_fidx);
    }
    
    if (result < FS_NO_ERROR)
    {
        //MMI_TRACE();
    }

    return fidx_in_folder;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_change_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hd    [IN]
 *  index    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
S32 srv_ftpc_change_folder(S32 hd, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_CHANGE_FOLDER, act_client_cntx_p->ftpc_state);
    if (srv_ftpc_is_valid_handle(hd))
    {
        if (srv_ftpc_get_obj_detail_info(hd, index, act_client_cntx_p->actual_name) >= FS_NO_ERROR)
        {
            if (mmi_wcslen(act_client_cntx_p->actual_name) < GOEP_MAX_OBJ_NAME)
            {
                if (srv_ftpc_change_folder_internal(act_client_cntx_p->actual_name))
                {
                    return SRV_FTP_RESULT_OK;
                }
            }
        }
    }

    return SRV_FTP_RESULT_FAIL;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_refresh_folder
 * DESCRIPTION
 *  this function is to refresh the current folder content
 * PARAMETERS
 *  hd    [IN]    srvice handle
 *  
 * RETURNS
 *  SRV_FTP_RESULT_OK: success
 *  SRV_FTP_RESULT_FAIL: failed
 ******************************************************************************/
S32 srv_ftpc_refresh_folder(S32 hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_REFRESH_FOLDER, act_client_cntx_p->ftpc_state);
    if (srv_ftpc_is_valid_handle(hd))
    {
        if (srv_ftpc_change_folder_internal(NULL))
        {
            return SRV_FTP_RESULT_OK;
        }
    }

    return SRV_FTP_RESULT_FAIL;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_back_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hd    [IN]
 *  
 * RETURNS
 *  S32
 ******************************************************************************/
S32 srv_ftpc_back_folder(S32 hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_BACK_FOLDER, act_client_cntx_p->ftpc_state, ftpc_cntx_p->goep_conn_id);

    if (srv_ftpc_is_valid_handle(hd))
    {
        switch (act_client_cntx_p->ftpc_state)
        {
            case SRV_FTPC_STATE_CONNECTED:
            {
                goep_set_folder_req_struct *req;

                SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_SETTING_BACK_FOLDER);
                req = (goep_set_folder_req_struct*)OslConstructDataPtr(sizeof(goep_set_folder_req_struct));
                FTP_MEMSET(req);
                req->goep_conn_id = ftpc_cntx_p->goep_conn_id;
                req->setpath_flag = GOEP_BACK_FOLDER;
                srv_ftp_send_msg(MSG_ID_GOEP_SET_FOLDER_REQ, req);
                return SRV_FTP_RESULT_OK;
            }

            default: /* Incorrect state */
                SRV_FTPC_LOG_STATE_ERR();
                if (act_client_cntx_p->fh_ftpc_recv)
                {
                    FS_Close(act_client_cntx_p->fh_ftpc_recv);
                    act_client_cntx_p->fh_ftpc_recv = (FS_HANDLE)NULL;
                }

                return SRV_FTP_RESULT_FAIL;
        }
    }

    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_INVALID_HDLR, hd);
    return SRV_FTP_INVALID_HANDLE;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_back_root_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hd    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
S32 srv_ftpc_back_root_folder(S32 hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_BACK_ROOT_FOLDER, act_client_cntx_p->ftpc_state, ftpc_cntx_p->goep_conn_id);

    if (srv_ftpc_is_valid_handle(hd))
    {
        switch (act_client_cntx_p->ftpc_state)
        {
            case SRV_FTPC_STATE_CONNECTED:
            {
                goep_set_folder_req_struct *req;

                SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_SETTING_ROOT_FOLDER);
                req = (goep_set_folder_req_struct*)OslConstructDataPtr(sizeof(goep_set_folder_req_struct));
                FTP_MEMSET(req);
                req->goep_conn_id = ftpc_cntx_p->goep_conn_id;
                req->setpath_flag = GOEP_ROOT_FOLDER;
                srv_ftp_send_msg(MSG_ID_GOEP_SET_FOLDER_REQ, req);
                return SRV_FTP_RESULT_OK;
            }

            default: /* Incorrect state */
                SRV_FTPC_LOG_STATE_ERR();
                if (act_client_cntx_p->fh_ftpc_recv)
                {
                    FS_Close(act_client_cntx_p->fh_ftpc_recv);
                    act_client_cntx_p->fh_ftpc_recv = (FS_HANDLE)NULL;
                }

                return SRV_FTP_RESULT_FAIL;
        }
    }

    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_INVALID_HDLR, hd);
    return SRV_FTP_INVALID_HANDLE;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_abort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hd    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
S32 srv_ftpc_abort(S32 hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*reset variables after send abort_req*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_ABORT, act_client_cntx_p->ftpc_state);
    if (srv_ftpc_is_valid_handle(hd))
    {
        switch(act_client_cntx_p->ftpc_state)
        {
            case SRV_FTPC_STATE_GETTING_FOLDER:
            case SRV_FTPC_STATE_PARSING_FOLDER:
                srv_ftpc_send_tpdisconnect();
                SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_TPDISCONNECTING);
                return SRV_FTP_RESULT_OK;

            case SRV_FTPC_STATE_CONNECTING:
            {
                goep_disconnect_req_struct *req;

                srv_bt_cm_reg_pairing_permission(SRV_BT_CM_OBEX_FILE_TRANSFER_CLIENT_UUID, (void*)srv_ftpc_permit_show_pair_scr);
                act_client_cntx_p->abort_type = SRV_FTPC_ABORT_CONNECTION_FROM_APP;

                req = (goep_disconnect_req_struct*)OslConstructDataPtr(sizeof(goep_disconnect_req_struct));
                FTP_MEMSET(req);
                req->req_id = ftpc_cntx_p->conn_id;
                req->goep_conn_id = 0xFF;

                srv_ftp_send_msg(MSG_ID_GOEP_DISCONNECT_REQ, req);
                SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_DISCONNECTING);
                return SRV_FTP_RESULT_OK;
            }
            

            case SRV_FTPC_STATE_GETTING_OBJ:
                srv_ftpc_receiving_aborted_handle();
                act_client_cntx_p->abort_type = SRV_FTPC_ABORT_GETTING_FILE_FROM_APP;
                SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_ABORTING);
                return SRV_FTP_RESULT_OK;

        }
    }

    return SRV_FTP_RESULT_FAIL;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_is_valid_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_hd    [IN]
 *  
 * RETURNS
 *  MMI_BOOL
 ******************************************************************************/
MMI_BOOL srv_ftpc_is_valid_handle(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_IS_VALID_HANDLE, srv_hd);
    
    return ((srv_hd > 0) && (srv_hd <= SRV_FTP_MAX_CLIENT_NUM)) ? MMI_TRUE : MMI_FALSE;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event    [IN]
 *  para    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
void srv_ftpc_notify(U16 event, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_NOTIFY, event);
    for (i = 0; i < SRV_FTP_MAX_CLIENT_NUM; ++i)
    {
        if (srv_ftpc_is_valid_handle(ftpc_handle[i].srv_hd))
        {
            if ((event & ftpc_handle[i].event_mask) != 0)
            {
                ftpc_handle[i].notifier(ftpc_handle[i].srv_hd, event, para);
            }
        }
    }
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_disconnect_server
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hd    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
void srv_ftpc_disconnect_server(S32 hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_DISCONNECT_SERVER);
    if (srv_ftpc_is_valid_handle(hd))
    {
        switch (act_client_cntx_p->ftpc_state)
        {
            case SRV_FTPC_STATE_CONNECTING:
                srv_ftpc_abort(hd);
                break;
    
            case SRV_FTPC_STATE_ABORTING:
                SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_DISCONNECTING);
                break;
    
            case SRV_FTPC_STATE_CONNECTED:
            case SRV_FTPC_STATE_SETTING_FOLDER:
            case SRV_FTPC_STATE_SETTING_BACK_FOLDER:
            case SRV_FTPC_STATE_SETTING_ROOT_FOLDER:
            case SRV_FTPC_STATE_GETTING_FOLDER:
            case SRV_FTPC_STATE_PARSING_FOLDER:
            case SRV_FTPC_STATE_GETTING_OBJ:
                srv_ftpc_send_tpdisconnect();
                SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_TPDISCONNECTING);
                break;
        }
    }
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_disconnect_conn
 * DESCRIPTION
 *  this function is to disconnect ftp server with connection ID
 * PARAMETERS
 *  conn_id:    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
extern void srv_ftpc_disconnect_conn(U32 conn_id)
{
    if ((ftpc_cntx_p->conn_id > 0) &&
        (ftpc_cntx_p->conn_id == conn_id))
    {
        srv_ftpc_disconnect_server(ftpc_handle[0].srv_hd);
        
//         switch (act_client_cntx_p->ftpc_state)
//         {
//             case SRV_FTPC_STATE_CONNECTING:
//                 srv_ftpc_abort(ftpc_handle[0].srv_hd);
//                 break;
//             case SRV_FTPC_STATE_ABORTING:
//                 SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_DISCONNECTING);
//                 break;
//             case SRV_FTPC_STATE_CONNECTED:
//             case SRV_FTPC_STATE_SETTING_FOLDER:
//             case SRV_FTPC_STATE_SETTING_BACK_FOLDER:
//             case SRV_FTPC_STATE_SETTING_ROOT_FOLDER:
//             case SRV_FTPC_STATE_GETTING_FOLDER:
//             case SRV_FTPC_STATE_PARSING_FOLDER:
//             case SRV_FTPC_STATE_GETTING_OBJ:
//                 srv_ftpc_send_tpdisconnect();
//                 SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_TPDISCONNECTING);
//                 break;
//         }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_deinit
 * DESCRIPTION
 *  This function is to deinit ftp client
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftpc_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_FTP_MAX_CLIENT_NUM; ++i)
    {
        if (ftpc_handle[i].srv_hd > 0)
        {
            if (act_client_cntx_p->ftpc_state != SRV_FTPC_STATE_IDLE)
            {
                /* srv_ftp_post_event_struct post_event; */

                SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_IDLE);
                srv_ftpc_connection_terminated();

                /* if (act_client_cntx_p->abort_type == SRV_FTPC_ABORT_CONNECTION_FROM_APP) */
                /* { */
                /*     srv_ftpc_connect_struct* ind_p = */
                /*         (srv_ftpc_connect_struct*)OslMalloc(sizeof(srv_ftpc_connect_struct)); */
                /*     ind_p->is_abort_from_client = MMI_TRUE; */
                /*     ind_p->bd_address = act_client_cntx_p->ftpc_bt_device; */
                /*     ind_p->cm_conn_id = 0; */
                /*     ind_p->req_id = ftpc_cntx_p->req_id; */
                /*     ind_p->connect_result = SRV_FTPC_CONNECT_FAIL; */
                /*     MMI_FRM_INIT_EVENT(&post_event, EVENT_ID_FTPC_CONNECT_SERVER); */
                /*     post_event.ftp_role = SRV_FTP_ROLE_CLIENT; */
                /*     post_event.event = SRV_FTPC_EVENT_CONNECT; */
                /*     post_event.data_p = (void*)ind_p; */
                /*     mmi_frm_post_event((mmi_event_struct*)&post_event, srv_ftp_post_event_proc, NULL); */
                /* } */
                /* else */
                /* { */
                /*     srv_ftpc_disconnect_struct* ind_p = */
                /*         (srv_ftpc_disconnect_struct*)OslMalloc(sizeof(srv_ftpc_disconnect_struct)); */
                /*     ind_p->is_from_client = MMI_TRUE; */
                /*     ind_p->bd_address = act_client_cntx_p->ftpc_bt_device; */
                /*     ind_p->cm_conn_id = ftpc_cntx_p->g_conn_id; */
                /*     MMI_FRM_INIT_EVENT(&post_event, EVENT_ID_FTPC_DISCONNECT_SERVER); */
                /*     post_event.ftp_role = SRV_FTP_ROLE_CLIENT; */
                /*     post_event.event = SRV_FTPC_EVENT_DISCONNECT; */
                /*     post_event.data_p = (void*)ind_p; */
                /*     mmi_frm_post_event((mmi_event_struct*)&post_event, srv_ftp_post_event_proc, NULL); */
                /* } */
            }
        }
    }
}
#endif /* __MMI_FTC_SUPPORT__ */
