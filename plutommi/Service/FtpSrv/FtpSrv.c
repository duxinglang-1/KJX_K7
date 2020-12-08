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
 * FtpSrv.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for MMI FTP service.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
/* Include: MMI header file */
// #include "MMI_include.h"
// #include "BtcmSrvGprot.h"
#include "Bluetooth_struct.h"
// #include "BTMMIObexGprots.h"
// RHR: add
#include "FtpSrv.h"
#include "MMI_conn_app_trc.h"
#include "FtpSrvGprots.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "stack_msgs.h"
#include "MMIDataType.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "app_ltlcom.h"
#include "stack_config.h"
//#include "stack_ltlcom.h"
#include "stack_common.h"
#include "Unicodexdcl.h"
#include "FileMgrSrvGProt.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
// RHR: add

// #include "BTMMIFtpGprots.h"
#include "FtpsSrv.h"
#include "FtpcSrv.h"
//#include "Custom_events_notify.h"
//#include "ExtDeviceDefs.h"
//#include "xml_def.h"
//#include "BTMMIScrGprots.h"
//#include "BTMMICmGprots.h"


const kal_uint8 OBEX_FTP_UUID[] = {0xF9, 0xEC, 0x7B, 0xC4,
                                   0x95, 0x3C, 0x11, 0xD2,
                                   0x98, 0x4E, 0x52, 0x54,
                                   0x00, 0xDC, 0x9E, 0x09};

#ifdef __MMI_FTS_SUPPORT__
/* ftps_handle is the ftp server handle array infomation */
extern srv_ftp_hdlr_struct ftps_handle[SRV_FTP_MAX_SERVER_NUM];
#endif  /* __MMI_FTS_SUPPORT__ */

#ifdef __MMI_FTC_SUPPORT__
/* ftpc_hdlr is the ftp client handle array infomation */
extern srv_ftp_hdlr_struct ftpc_handle[SRV_FTP_MAX_CLIENT_NUM];
#endif /* __MMI_FTC_SUPPORT__ */


/***************************************************************************** 
* INTERNAL STATIC FUNCTION
*****************************************************************************/
static void srv_ftp_cntx_init(void);
static void srv_ftp_disconnect_ind_handle(void *msg);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_init
 * DESCRIPTION
 *  This function is to initialize FTP application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftp_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTP_INIT);
    srv_ftp_work_folder_init();
    srv_ftp_cntx_init();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_deinit
 * DESCRIPTION
 *  This function is to deinit ftp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftp_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTP_DEINIT);

#ifdef __MMI_FTC_SUPPORT__
    srv_ftpc_deinit();
#endif

#ifdef __MMI_FTS_SUPPORT__
    srv_ftps_deinit();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_event_handle
 * DESCRIPTION
 *  This function is to handle event from obex
 * PARAMETERS
 *  msg_id      [IN]        
 *  msg         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftp_event_handle(msg_type msg_id, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTP_EVENT_HANDLE);
    switch (msg_id)
    {
#ifdef __MMI_FTS_SUPPORT__
        case MSG_ID_GOEP_REGISTER_SERVER_RSP:
            srv_ftps_register_server_rsp_handle(msg);
            return;
        case MSG_ID_GOEP_DEREGISTER_SERVER_RSP:
            srv_ftps_deregister_server_rsp_handle(msg);
            return;
        case MSG_ID_GOEP_CONNECT_IND:
            srv_ftps_connect_ind_handle(msg);
            return;
        case MSG_ID_GOEP_PUSH_IND:
            srv_ftps_push_ind_handle(msg);
            return;
        case MSG_ID_GOEP_PULL_IND:
            srv_ftps_pull_ind_handle(msg);
            return;
        case MSG_ID_GOEP_SET_FOLDER_IND:
            srv_ftps_set_folder_ind_handle(msg);
            return;
        case MSG_ID_GOEP_ABORT_IND:
            srv_ftps_abort_ind_handle(msg);
            return;
        case MSG_ID_GOEP_AUTHORIZE_IND:
            srv_ftps_authorize_ind_handle(msg);
            return;
#endif /* __MMI_FTS_SUPPORT__ */

#ifdef __MMI_FTC_SUPPORT__
        case MSG_ID_GOEP_CONNECT_RSP:
            srv_ftpc_connect_rsp_handle(msg);
            return;
        case MSG_ID_GOEP_PULL_RSP:
            srv_ftpc_pull_rsp_handle(msg);
            return;
        case MSG_ID_GOEP_SET_FOLDER_RSP:
            srv_ftpc_set_folder_rsp_handle(msg);
            return;
        case MSG_ID_GOEP_ABORT_RSP:
            srv_ftpc_abort_rsp_handle(msg);
            return;
#endif /* __MMI_FTC_SUPPORT__ */
        case MSG_ID_GOEP_DISCONNECT_IND:
            srv_ftp_disconnect_ind_handle(msg);
            return;
        default:
            ASSERT(0);
            return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftp_cntx_init
 * DESCRIPTION
 *  This function is to initialize FTP application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftp_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTP_CNTX_INIT);
#ifdef __MMI_FTS_SUPPORT__ 
    srv_ftps_cntx_init();
#endif

#ifdef __MMI_FTC_SUPPORT__
    srv_ftpc_cntx_init();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftp_work_folder_init
 * DESCRIPTION
 *  This function is to initialize FTP work folder Z:\@ftp\
 *  When the folder is not existed, it will try to create, if create failed, it will set flag.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_ftp_work_folder_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h;
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTP_WORK_FOLDER_INIT);
#ifdef __NVRAM_IN_USB_MS__
    if (USBMS_BOOT == stack_query_boot_mode())
    {
        return MMI_FALSE;
    }
#endif /* __NVRAM_IN_USB_MS__ */ 

    h = FS_Open((kal_uint16*)SRV_FTP_FOLDER_PATH, FS_READ_ONLY | FS_OPEN_DIR);
    if (h >= FS_NO_ERROR)
    {
        FS_Close(h);
        MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTP_WORK_FOLDER_INIT_OPEN_NO_ERROR);
    }
    else /* Error handling */
    {
        ret = FS_CreateDir((kal_uint16*)SRV_FTP_FOLDER_PATH);
        if (ret < 0)
        {
            MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTP_WORK_FOLDER_INIT_OPEN_ERROR);
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftp_disconnect_ind_handle
 * DESCRIPTION
 *  This function is to to handle FTP_DISCONNECT_IND msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ftp_disconnect_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_disconnect_ind_struct *ind = (goep_disconnect_ind_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTS_SUPPORT__
    MMI_TRACE(MMI_FTP_TRC_CLASS,
              SRV_FTPS_DISCONNECT_IND_HANDLE,
              ind->goep_conn_id,
              ind->req_id,
              ftps_cntx_p->goep_conn_id,
              ftps_cntx_p->conn_cntx.ftps_state);
#endif

#ifdef __MMI_FTC_SUPPORT__
    MMI_TRACE(MMI_FTP_TRC_CLASS,
              SRV_FTPC_DISCONNECT_IND_HANDLE,
              ind->goep_conn_id,
              ind->req_id,
              ftpc_cntx_p->goep_conn_id,
              ftpc_cntx_p->conn_id,
              ftpc_cntx_p->conn_cntx.ftpc_state);
#endif

#ifdef __MMI_FTC_SUPPORT__
    if (ind->goep_conn_id == 0xFF) /* two case:  1. connecting, cancel 2. connecting, remove remote battery */
    {
        if (ftpc_cntx_p->conn_id == ind->req_id)
        {
            srv_ftpc_connect_struct result;

            //ftpc_cntx_p->req_id = 0xFF; /* reset context for later connect request */

                result.is_abort_from_client =
                    (act_client_cntx_p->ftpc_state == SRV_FTPC_STATE_DISCONNECTING) ?
                    MMI_TRUE :
                    MMI_FALSE;
                result.bd_address = act_client_cntx_p->ftpc_bt_device;
                result.cm_conn_id = 0;
                result.req_id = ind->req_id;
                result.connect_result = SRV_FTPC_CONNECT_FAIL;

            if (ftpc_cntx_p->conn_id > 0)
            {
                srv_bt_cm_stop_conn(ftpc_cntx_p->conn_id);
                ftpc_cntx_p->conn_id = -1;
            }
            SRV_FTPC_STATE_TRANS(SRV_FTPC_STATE_IDLE);
            srv_ftpc_connection_terminated();

            srv_ftpc_notify(SRV_FTPC_EVENT_CONNECT, (void*)&result);
        }
        else
        {
            MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_DISCONN_IND_HANDLE_FAILED);
        }

        return;
    }
    else if (ftpc_cntx_p->goep_conn_id == ind->goep_conn_id)
    {
        srv_ftpc_disconnect_ind_hdlr();
        return;
    }
#endif

#ifdef __MMI_FTS_SUPPORT__
    if (ftps_cntx_p->goep_conn_id == ind->goep_conn_id)
    {
        srv_ftps_disconnect_ind_handle();
        return;
    }
#endif  /* __MMI_FTS_SUPPORT__ */

    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTP_DISCONNECT_IND_HANDLE_FAILED);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftp_usb_plugin_check
 * DESCRIPTION
 *  the check func for callback when usb mass plug in
 *  True: execute; False: not execute
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_ftp_usb_plugin_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftp_send_msg
 * DESCRIPTION
 *  This function is to send msg to BT task
 * PARAMETERS
 *  msg_id              [IN]        
 *  p_local_para        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftp_send_msg(U32 msg_id, void *p_local_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_send5(
        MOD_MMI,
        MOD_BT,
        BT_APP_SAP,
        msg_id,
        (local_para_struct*)p_local_para);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftp_obj_name_swapcpy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_order_name        [IN]        
 *  n_order_name        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftp_obj_name_swapcpy(CHAR* h_order_name, CHAR* n_order_name)
{   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 bytes_len = mmi_ucs2strlen(n_order_name) * 2;
    CHAR t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < bytes_len; i += 2) /* includes null temination */
    {
        t = n_order_name[i];
        h_order_name[i] = n_order_name[i + 1];
        h_order_name[i + 1] = t;
    }

    h_order_name[bytes_len] = 0;
    h_order_name[bytes_len + 1] = 0;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftp_ucs2_cut_name_with_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest    [IN]
 *  dest_size    [IN]
 *  src    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
void srv_ftp_ucs2_cut_name_with_ext(CHAR* dest, U32  dest_size, const CHAR* src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR* src_no_space;
    char *p_ext_name;
    U32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    src_no_space = srv_fmgr_path_skip_leading_space((WCHAR*)src);
    len = mmi_ucs2strlen((CHAR*)src_no_space);

    /* need not to cut*/
    if (len <= (dest_size / ENCODING_LENGTH - 1))
    {
        mmi_ucs2cpy((CHAR*)dest, (CHAR*)src_no_space);
    }
    else
    {
        p_ext_name = mmi_ucs2rchr((CHAR*)src_no_space, (WCHAR)(L'.'));
        if (p_ext_name)
        {
            len = mmi_ucs2strlen((CHAR*)p_ext_name);
            if (len <= (dest_size / ENCODING_LENGTH - 2)) /* empty file name is invalid */
            {
                mmi_ucs2ncpy((CHAR*)dest, (CHAR*)src_no_space, ((dest_size / ENCODING_LENGTH - 1) - len));
                mmi_ucs2cat((CHAR*)dest, (CHAR*)p_ext_name);
                return;
            }
        }

        mmi_ucs2ncpy((CHAR*)dest, (CHAR*)src_no_space, dest_size / ENCODING_LENGTH - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftp_ucs2_cut_name_without_ext
 * DESCRIPTION
 *  This function  remove the space in the font, and cut the remain name to requsted size.
 * 
 *  All strings in this funcion must be Unicode encoded.
 *  dest_size: is the buffer size including the  end Zero 
 * PARAMETERS
 *  dest
 *  dest_size
 *  src
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ftp_ucs2_cut_name_without_ext(CHAR* dest, U32  dest_size, const CHAR* src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR* src_no_space;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    src_no_space = srv_fmgr_path_skip_leading_space((WCHAR*)src);
    if (src_no_space)
    {
        mmi_ucs2ncpy((CHAR*)dest, (CHAR*)src_no_space, (U32)(dest_size/2 - 1));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_check_folder_existed
 * DESCRIPTION
 *   
 * PARAMETERS
 *  absolute_path
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_ftp_check_folder_existed(U8 *absolute_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 deter = '\\';
    U8 parent_folder[(SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH]; 
    U16 start_pos;
    U16 path_len;
    FS_HANDLE fh_parent, fh_checked_folder;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTP_CHECK_FOLDER_EXISTED, absolute_path);
    path_len = mmi_ucs2strlen((CHAR*)absolute_path);
    if (path_len  > SRV_FMGR_PATH_MAX_LEN)
    {
        return -1;
    }
        
    if ((fh_checked_folder = FS_Open((WCHAR*)absolute_path, FS_READ_ONLY | FS_OPEN_DIR )) < FS_NO_ERROR)
    {
        for (start_pos = 0; start_pos < path_len * 2; start_pos += 2)
        {
            if (memcmp((absolute_path + start_pos), &deter, 2) == 0)
            {
                memcpy(parent_folder, absolute_path, start_pos + 2);
                memset(parent_folder + start_pos + 2, 0, 2);
                if ((fh_parent = FS_Open((WCHAR*)parent_folder, FS_READ_ONLY | FS_OPEN_DIR)) < FS_NO_ERROR)
                {
                    S32 ret;

                    /*from \\ to create*/
                    if (start_pos == 4)
                    {
                        return fh_parent;
                    }

                    /*create unexited driver shall return -36*/
                    ret = FS_CreateDir((WCHAR*)parent_folder);
                    if (ret < FS_NO_ERROR)
                    {
                        MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTP_CHECK_FOLDER_EXISTED_ERROR, ret);
                        return ret;
                    }
                }
                else
                {
                    FS_Close(fh_parent);                    
                }
            }
        }
        return 0;
    }
    else
    {
        FS_Close(fh_checked_folder);
        return 0;
    }
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftp_delete_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  absolute_path    [IN]
 *  file_name    [IN]
 * RETURNS
 *  void
 ******************************************************************************/
/* void srv_ftp_delete_file(const U8 *absolute_path, const U8 *file_name) */
/* { */
/*     /\*----------------------------------------------------------------*\/ */
/*     /\* Local Variables                                                *\/ */
/*     /\*----------------------------------------------------------------*\/ */
/*     U8 *all_path_name_ptr; */

/*     /\*----------------------------------------------------------------*\/ */
/*     /\* Code Body                                                      *\/ */
/*     /\*----------------------------------------------------------------*\/ */
/*     MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTP_DELETE_FILE); */
/*     all_path_name_ptr = OslMalloc((SRV_FMGR_PATH_MAX_LEN+1) * ENCODING_LENGTH); */
/*     mmi_ucs2cpy((PS8)all_path_name_ptr, (PS8)absolute_path); */
/*     mmi_ucs2cat((PS8)all_path_name_ptr, (PS8)file_name); */
/*     FS_Delete((WCHAR*)all_path_name_ptr); */
/*     OslMfree(all_path_name_ptr); */
/* } */

/******************************************************************************
 * FUNCTION
 *  srv_ftp_open
 * DESCRIPTION
 *  this function is get the handler of the service
 *  it should be called firstly before using ftp service
 * PARAMETERS
 *  role    [IN]    indentity of ftp server of client
 * RETURNS
 *  service hander:
 *  if hander > 0, means success
 *  or something is wrong
 ******************************************************************************/
S32 srv_ftp_open(U16 role)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTC_SUPPORT__
    if (role == SRV_FTP_ROLE_CLIENT)
    {
        for (i = 0; i < SRV_FTP_MAX_CLIENT_NUM; ++i)
        {
            if (act_client_cntx_p->ftpc_state == SRV_FTPC_STATE_IDLE)
            {
                if (ftpc_handle[i].srv_hd == 0)
                {
                    return (ftpc_handle[i].srv_hd = i + 1);
                }
            }
        }
    }
#endif /* __MMI_FTC_SUPPORT__ */

#ifdef __MMI_FTS_SUPPORT__
    if (role == SRV_FTP_ROLE_SERVER)
    {
        for (i = 0; i < SRV_FTP_MAX_SERVER_NUM; ++i)
        {
            //if (act_server_cntx_p->ftps_state <= SRV_FTPS_STATE_ACTIVE)
            {
                if (ftps_handle[i].srv_hd == 0)
                {
                    return (ftps_handle[i].srv_hd = SRV_FTP_SERVER_HANDLE_DOMAIN + i + 1);
                }
            }
        }
    }
#endif /* __MMI_FTS_SUPPORT__ */

    return SRV_FTP_RESULT_FAIL;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftp_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_hd    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
S32 srv_ftp_close(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTC_SUPPORT__
    if (srv_ftpc_is_valid_handle(srv_hd))
    {
        if (act_client_cntx_p->ftpc_state > SRV_FTPC_STATE_IDLE)
        {
            srv_ftpc_disconnect_server(srv_hd);
        }
        ftpc_handle[srv_hd - 1].srv_hd = 0;
        return SRV_FTP_RESULT_OK;
    }
#endif /* __MMI_FTC_SUPPORT__ */

#ifdef __MMI_FTS_SUPPORT__
    if (srv_ftps_is_valid_handle(srv_hd))
    {
        /* if (act_server_cntx_p->ftps_state > SRV_FTPS_STATE_IDLE) */
        /* { */
        /*     srv_ftps_deactivate(); */
        /* } */
        ftps_handle[srv_hd - SRV_FTP_SERVER_HANDLE_DOMAIN - 1].srv_hd =  0;
        return SRV_FTP_RESULT_OK;
    }
#endif /* __MMI_FTS_SUPPORT__ */

    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTP_INVALID_HDLR, srv_hd);
    return SRV_FTP_INVALID_HANDLE;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftp_set_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_hd    [IN]
 *  notifier    [IN]
 *  event_mask    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
S32 srv_ftp_set_notify(S32 srv_hd, ftp_notify notifier, U16 event_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTC_SUPPORT__
    if (srv_ftpc_is_valid_handle(srv_hd))
    {
        --srv_hd;
        ftpc_handle[srv_hd].notifier = notifier;
        ftpc_handle[srv_hd].event_mask = event_mask;
        return SRV_FTP_RESULT_OK;
    }
#endif /* __MMI_FTC_SUPPORT__ */

#ifdef __MMI_FTS_SUPPORT__
    if (srv_ftps_is_valid_handle(srv_hd))
    {
        srv_hd -= (SRV_FTP_SERVER_HANDLE_DOMAIN + 1);
        ftps_handle[srv_hd].notifier = notifier;
        ftps_handle[srv_hd].event_mask = event_mask;

        return SRV_FTP_RESULT_OK;
    }
#endif /* __MMI_FTS_SUPPORT__ */

    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTP_INVALID_HDLR, srv_hd);
    return SRV_FTP_INVALID_HANDLE;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftp_post_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para    [IN]
 *  
 * RETURNS
 *  mmi_ret
 ******************************************************************************/
mmi_ret srv_ftp_post_event_proc(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ftp_post_event_struct* ind_p = (srv_ftp_post_event_struct*)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTP_POST_EVENT_PROC, ind_p->ftp_role);
#ifdef __MMI_FTS_SUPPORT__
    if (ind_p->ftp_role == SRV_FTP_ROLE_SERVER)
    {
        srv_ftps_notify(ind_p->event, ind_p->data_p);
    }
#endif  /* __MMI_FTS_SUPPORT__ */

#ifdef __MMI_FTC_SUPPORT__
    if (ind_p->ftp_role == SRV_FTP_ROLE_CLIENT)
    {
        srv_ftpc_notify(ind_p->event, ind_p->data_p);
    }
#endif  /* __MMI_FTC_SUPPORT__ */

    if (ind_p->data_p != NULL)
    {
        OslMfree(ind_p->data_p);
    }

    return MMI_RET_OK;
}
#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */
