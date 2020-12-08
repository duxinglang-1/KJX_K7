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
 *  SmsBtMapCCoreSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service For BT File
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#include "MMI_features.h"
#ifdef __MOD_SMSAL__


// TODO:ADD Compile Option
#include "MapSrvGprot.h"
#include "SmsBtMapCSrvParser.h"
#include "SmsBtMapCSrvStorage.h"
#include "SmsBtMapCSrvGProt.h"
#include "SmsSrvGProt.h"
#include "SmsBtMapCSrvUtil.h"
#include "SmsBtMapCSrvConverter.h"
#include "MapObjSrv.h"
#include "FileMgrSrvGProt.h"
#include "SmsBtMapCSrvCore.h"
#include "Unicodexdcl.h"
#include "mmi_rp_srv_sms_btmapc_def.h"
#include "MMI_trc_Int.h"
#include "MMI_common_app_trc.h"
#include "App_str.h"
#include "tst_sap.h"
#include "tst_def.h"
#include "Conversions.h"
#ifdef __SRV_SMS_BTMAPC__

const CHAR MSG_ROOT_PATH[] = "telecom/msg/";
const CHAR INBOX_PATH[] = "inbox";
const CHAR OUTBOX_PATH[] = "outbox";
const CHAR SENT_PATH[] = "sent";
const CHAR DRAFT_PATH[] = "draft";
const CHAR OPER_VERSION[] = "VERSION:2.1";
const CHAR OPER_NAME[] = "N:";
const CHAR OPER_TEL[] = "TEL:";
const CHAR OPER_BVCARD[] = "BEGIN:VCARD";
const CHAR OPER_EVCARD[] = "END:VCARD";
const CHAR OPER_END[] = "\r\n";

extern void srv_sms_btmapc_send_evt_rsp(srv_sms_btmapc_ind_enum type);
void srv_sms_btmapc_handle_evt(S32 srv_hd, srv_bt_mapc_cbevent_enum evt, void* para);
static void srv_sms_btmapc_connect_rsp(S32 srv_hd, void* para);
static void srv_sms_btmapc_disconnect_rsp(S32 srv_hd, void* para);
static void srv_sms_btmapc_disconnect_ind(S32 srv_hd, void* para);
static void srv_sms_btmapc_set_folder_rsp(S32 srv_hd, void* para);
static void srv_sms_btmapc_get_msg_list_rsp(S32 srv_hd, void* para);
static void srv_sms_btmapc_get_msg_req(U16 msg_id, void *userData);
static void srv_sms_btmapc_get_msg_rsp(S32 srv_hd, void* para);
static void srv_sms_btmapc_set_msg_status_req(U16 msg_id, srv_bt_mapc_msg_status_enum status, void *userData);
static void srv_sms_btmapc_set_msg_status_rsp(S32 srv_hd, void* para);
static void srv_sms_btmapc_send_msg_req(srv_bt_mapc_push_message_req_struct *req, void *userData);
static void srv_sms_btmapc_send_msg_rsp(S32 srv_hd, void* para);
static void srv_sms_btmapc_new_message_ind(S32 srv_hd, void* para);
static MMI_BOOL srv_sms_btmapc_build_bmessage(srv_sms_btmapc_send_handle_struct *hd_data, srv_bt_mapc_push_message_req_struct *req);
static void srv_sms_btmapc_set_list_property(srv_bt_mapc_set_msg_listing_prop_struct *msg);
static void srv_sms_btmapc_save_sms_callback(srv_sms_callback_struct* data);
static void srv_sms_btmapc_change_folder(SrvSmsCallbackFunc callback_func, void *user_data);
#ifdef __SRV_SMS_BTMAPC_TEST__
U8 srv_sms_btmapc_ut_handle(U8 index, kal_uint8* string);
#endif


#ifdef __SRV_SMS_BTMAPC_TEST__
void get_content_callback(srv_sms_callback_struct* callback_data)
{
    srv_sms_msg_data_struct *msg_data = NULL;
    srv_sms_read_msg_cb_struct *cb = (srv_sms_read_msg_cb_struct *)callback_data->action_data;

    msg_data = cb->msg_data;
    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_WRITE_CONTENT, 11 ,callback_data->result, callback_data->cause);
    if(callback_data->result)
    {
        srv_sms_btmapc_write_file(OUTPUT_MSG_DETAIL, (void *)msg_data);
    }
    OslMfree(msg_data->content_buff);
    OslMfree(msg_data);
}

U16 srv_sms_get_msg_id_by_index(U8 index)
{
    U32 i;
    U16 msg_id = 0;

    for(i = 0; i < SRV_SMS_BTMAPC_MAX_SMS_ENTRY; i++)
    {
        if(srv_sms_btmapc_is_msg_exist(msg_id) == MMI_TRUE)
        {
            if(index > 0)
            {
                msg_id++;
            }
            
            if(index == 0)
            {
                break;
            }
            else
            {
                index--;
            }
        }
        else
        {
            msg_id++;
        }
    }
    return msg_id;
}


U8 srv_sms_btmapc_ut_handle(U8 index, kal_uint8 *string)
{
    CHAR number[12] = {'1','3','4','0','2','8','0','6','5','7','1'};
    CHAR ucs2_addr[20*2] = {0};
    
    mmi_asc_n_to_ucs2((S8*)ucs2_addr, number, strlen(number));
    
    if (strcmp((char*)string, "smsconn") == 0)
    {
        srv_sms_btmapc_connect(SRV_SMS_BTMAPC, NULL, NULL);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsdisconn") == 0)
    {
        srv_sms_btmapc_disconnect(sms_btmapc_storage_cntx.hd, NULL, NULL);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsroot") == 0)
    {
        srv_sms_btmapc_change_folder(NULL, NULL);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsin") == 0)
    {
        srv_sms_btmapc_get_msg_list(MMI_TRUE, SRV_SMS_BTMAPC_BOX_INBOX, NULL, NULL);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsout") == 0)
    {
        srv_sms_btmapc_get_msg_list(MMI_TRUE, SRV_SMS_BTMAPC_BOX_UNSENT, NULL, NULL);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smssent") == 0)
    {
        srv_sms_btmapc_get_msg_list(MMI_TRUE, SRV_SMS_BTMAPC_BOX_OUTBOX, NULL, NULL);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsdraft") == 0)
    {
        srv_sms_btmapc_get_msg_list(MMI_TRUE, SRV_SMS_BTMAPC_BOX_DRAFTS, NULL, NULL);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsget") == 0)
    {
        U16 msg_id = 0;
        msg_id = srv_sms_get_msg_id_by_index(index);
        srv_sms_btmapc_get_msg(msg_id, NULL, NULL);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsread") == 0)
    {
        S8 *msg_content = (S8 *)OslMalloc(1024);
        srv_sms_msg_data_struct *msg_data = (srv_sms_msg_data_struct*)OslMalloc(sizeof(srv_sms_msg_data_struct));
        
        msg_data->para_flag = (srv_sms_para_enum)(SRV_SMS_PARA_CONTENT_BUFF | SRV_SMS_PARA_ORI_8BIT_DATA);
        msg_data->content_buff_size = 1024;
        msg_data->content_buff = msg_content;
        srv_sms_btmapc_read_msg((U16)index, MMI_TRUE, msg_data, get_content_callback, NULL);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsforward") == 0)
    {
        U16 msg_id = 0;
        SMS_HANDLE smsHdlr;
        WCHAR path_msg[200] = {0};
        WCHAR path_address[100] = {0};
        CHAR address[20];
        CHAR sms_content[500];
        S32 address_fhandle = -1;        
        S32 msg_fhandle = -1;
        U32 read_lenth = 0;

        kal_wsprintf(path_address, "%c:\\@SmsBtMapC\\phonenumber.txt", (CHAR)SRV_FMGR_CARD_DRV);
        msg_id = srv_sms_get_msg_id_by_index(index);
        srv_sms_btmapc_get_msg_name(msg_id, MMI_FALSE, path_msg);
        smsHdlr = srv_sms_btmapc_get_send_handle();
        if((msg_fhandle = FS_Open(path_msg, FS_READ_ONLY)) < 0)
        {
            return MMI_TRUE;
        }
        if ((address_fhandle = FS_Open(path_address, FS_READ_ONLY)) < 0)
        {
            return MMI_TRUE;
        }
        FS_Read(msg_fhandle, sms_content, 500, &read_lenth);
        sms_content[read_lenth] = 0;
        FS_Read(address_fhandle, address, 20, &read_lenth);
        address[read_lenth] = 0;
        
        srv_sms_btmapc_set_content(smsHdlr, sms_content, (U16)(strlen(sms_content)));
        mmi_asc_n_to_ucs2((S8*)ucs2_addr, address, strlen(address));
        srv_sms_btmapc_set_address(smsHdlr, (CHAR *)ucs2_addr);
        srv_sms_btmapc_set_send_type(smsHdlr, SRV_SMS_FG_SEND);
        srv_sms_btmapc_send_msg(smsHdlr, NULL, NULL);
        
        FS_Close(msg_fhandle);
        FS_Close(address_fhandle);
        return MMI_TRUE;
    }

    else if (strcmp((char*)string, "smssend") == 0)
    {
        SMS_HANDLE smsHdlr;
        S32 content_fhandle = -1;
        S32 address_fhandle = -1;
        CHAR sms_content[500];
        CHAR address[20];
        WCHAR path_content[100] = {0};
        WCHAR path_address[100] = {0};
        U32 read_lenth = 0;
        kal_wsprintf(path_content, "%c:\\@SmsBtMapC\\smssend.txt", (CHAR)SRV_FMGR_CARD_DRV);
        kal_wsprintf(path_address, "%c:\\@SmsBtMapC\\phonenumber.txt", (CHAR)SRV_FMGR_CARD_DRV);
        smsHdlr = srv_sms_btmapc_get_send_handle();
        
        if ((content_fhandle = FS_Open(path_content, FS_READ_ONLY)) < 0)
        {
            return MMI_TRUE;
        }
        if ((address_fhandle = FS_Open(path_address, FS_READ_ONLY)) < 0)
        {
            return MMI_TRUE;
        }
        FS_Read(content_fhandle, sms_content, 500, &read_lenth);
        sms_content[read_lenth] = 0;
        FS_Read(address_fhandle, address, 20, &read_lenth);
        address[read_lenth] = 0;

        
        srv_sms_btmapc_set_content(smsHdlr, sms_content, (U16)(strlen(sms_content)));
        mmi_asc_n_to_ucs2((S8*)ucs2_addr, address, strlen(address));
        srv_sms_btmapc_set_address(smsHdlr, (CHAR *)ucs2_addr);
        srv_sms_btmapc_set_send_type(smsHdlr, SRV_SMS_FG_SEND);
        srv_sms_btmapc_send_msg(smsHdlr, NULL, NULL);

        FS_Close(content_fhandle);
        FS_Close(address_fhandle);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsdelete") == 0)
    {
        U16 msg_id = 0;
        
        msg_id = srv_sms_get_msg_id_by_index(index);
        srv_sms_btmapc_delete_msg(msg_id, NULL, NULL);
        return MMI_TRUE;
    }

    else if (strcmp((char*)string, "smsfetchmessage") == 0)
    {
        srv_sms_btmapc_read_cntx_struct *read_cntx;
        srv_bt_mapc_message_cnf_struct res;
        S8 *msg_content = (S8 *)OslMalloc(1024);
        srv_sms_msg_data_struct *msg_data = (srv_sms_msg_data_struct*)OslMalloc(sizeof(srv_sms_msg_data_struct));
        char filename[] = "z:\\aa\\a.vcf";
        
        msg_data->para_flag = (srv_sms_para_enum)(SRV_SMS_PARA_CONTENT_BUFF | SRV_SMS_PARA_ORI_8BIT_DATA);
        msg_data->content_buff_size = 1024;
        msg_data->content_buff = msg_content;

        read_cntx = srv_sms_btmapc_alloc_cntx(
                        sizeof(srv_sms_btmapc_read_cntx_struct),
                        SRV_SMS_BTMAPC_OP_GET_MSG,
                        NULL,
                        NULL);
        srv_sms_btmapc_read_msg_init(
                    read_cntx,
                    0,
                    MMI_FALSE,
                    msg_data);
        res.Error = SRV_BT_MAPC_SUCCESS;
        memcpy(res.file, filename, strlen(filename));
        res.file[strlen(filename)] = 0;
        res.user_data = (void *)read_cntx;
        srv_sms_btmapc_get_msg_rsp(0, &res);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsparsemsglist") == 0)
    {
        WCHAR file_name[] = L"z:\\aa\\maps_message_list.xml";
        srv_sms_btmapc_xml_parse(file_name);
        srv_sms_btmapc_write_file(OUTPUT_MSG_LIST, (void *)srv_sms_btmapc_msg_list);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsparseevent") == 0)
    {
        WCHAR file_name[] = L"z:\\aa\\maps_event_report.xml";
        srv_sms_btmapc_xml_parse(file_name);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif

#ifdef __SRV_SMS_BTMAPC_TEST__
static void srv_sms_btmapc_itoa(kal_char *buf, kal_int32 i, kal_int32 base)
{
   kal_char *s;
#define LEN   20
   kal_int32 rem;
   static kal_char rev[LEN+1];

   rev[LEN] = 0;
   if (i == 0)
   {
      buf[0] = '0';
      ++buf;
      return;
   }
   s = &rev[LEN];
   while (i)
   {
      rem = i % base;
      if (rem < 10)
         *--s = rem + '0';
      else if (base == 16)
         *--s = "abcdef"[rem - 10];
      i /= base;
   }
   while (*s)
   {
      buf[0] = *s++;
      ++buf;
   }
}

void srv_sms_btmapc_write_file(srv_sms_btmapc_output_type output_type, void *data)
{
    switch (output_type)
    {
        case OUTPUT_MSG_LIST:
        {
            srv_sms_btmapc_msg_node_struct *msg_node = (srv_sms_btmapc_msg_node_struct *)data;
            WCHAR path[100] = {0};
            WCHAR root_path[100] = {0};
            S32 fhandle = 0;
            int i = 0;
            kal_char *index = OslMalloc(4);

            memset(index, 0, 4);
            kal_wsprintf(path, "%c:\\@SmsBtMapC\\output_msglist.txt", (CHAR)SRV_FMGR_CARD_DRV);
            kal_wsprintf(root_path, "%c:\\@SmsBtMapC", (CHAR)SRV_FMGR_CARD_DRV);
            FS_CreateDir(root_path);
            FS_Delete(path);
            if ((fhandle = FS_Open(path, FS_READ_WRITE|FS_CREATE)) < 0)
            {
                return;
            }
            for (i = 0; i < SRV_SMS_BTMAPC_MAX_SMS_ENTRY; i++)
            {
                FS_Write(fhandle, "msg_index :", 12, NULL);
                srv_sms_btmapc_itoa(index, i, 10);
                FS_Write(fhandle, index, 3, NULL);
                FS_Write(fhandle, "  number :", 11, NULL);;
                FS_Write(fhandle, msg_node[i].number, strlen(msg_node[i].number), NULL);
                FS_Write(fhandle, "\r\n", 2, NULL);
            }
            OslMfree(index);
            FS_Close(fhandle);
            break;
        }
        case OUTPUT_MSG_DETAIL:
        {
            srv_sms_msg_data_struct *msg_data = (srv_sms_msg_data_struct *)data;
            WCHAR path[200] = {0};
            WCHAR root_path[50] = {0};
            char msg_number[20] = {0};
            char msg_content[1024] = {0};
            S32 fhandle = 0;

            kal_wsprintf(path, "%c:\\@SmsBtMapC\\%d_output_smsrecv.txt", (CHAR)SRV_FMGR_CARD_DRV, msg_data->tp_st);
            kal_wsprintf(root_path, "%c:\\@SmsBtMapC", (CHAR)SRV_FMGR_CARD_DRV);
            FS_CreateDir(root_path);
            if ((fhandle = FS_Open(path, FS_READ_WRITE|FS_CREATE)) < 0)
            {
                return;
            }
            FS_Write(fhandle, "Number: ", 9, NULL);
            mmi_ucs2_to_asc(msg_number, msg_data->number);
            FS_Write(fhandle, msg_number, strlen(msg_number), NULL);
            FS_Write(fhandle, "\r\n", 2, NULL);
            FS_Write(fhandle, "Content: \r\n", 11, NULL);

            //mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_GB2312, msg_data->content_buff, msg_content, 1024);
            mmi_ucs2_to_asc(msg_content, msg_data->content_buff);
            FS_Write(fhandle, msg_content, strlen(msg_content), NULL);
            FS_Close(fhandle);
        }

        default:
            break;
    }
}
#endif


void srv_sms_btmapc_init()
{
    S32 hd = 0;
    WCHAR file_name[SRV_SMS_BTMAPC_MAX_PATH_LEN];
    
#ifdef __SRV_SMS_BTMAPC_TEST__
    //mmi_frm_set_protocol_event_handler(MSG_ID_TST_INJECT_STRING, (PsIntFuncPtr)srv_sms_btmapc_ut_handle, MMI_TRUE);
#endif
    if(!srv_sms_btmapc_file_exist(SMS_BT_BMESSAGE_ROOT_FOLDER))
    {
        FS_CreateDir(SMS_BT_BMESSAGE_ROOT_FOLDER);
    }
    if(!srv_sms_btmapc_file_exist(MAP_ADP_WORK_FOLDER))
    {
        FS_CreateDir(MAP_ADP_WORK_FOLDER);
    }
    
    srv_sms_btmapc_get_root_name(file_name);
    if(!srv_sms_btmapc_file_exist(file_name))
    {
        FS_CreateDir(file_name);
    }
    srv_sms_btmapc_storage_init_data();
    srv_sms_btmapc_list_init();
    hd = srv_mapc_open(SRV_SMS_BTMAPC);
    
    sms_btmapc_storage_cntx.hd = hd;
    srv_bt_mapc_register_callback(hd, srv_sms_btmapc_handle_evt);
}


S32 srv_sms_btmapc_connect(
          int app_id,
          SrvSmsCallbackFunc callback_func,
          void *user_data)
{
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    srv_sms_btmapc_action_struct *conn_cntx = NULL;

    S32 hd = srv_mapc_open(app_id);
    sms_btmapc_storage_cntx.hd = hd;
    srv_bt_mapc_register_callback(hd, srv_sms_btmapc_handle_evt);
    conn_cntx = srv_sms_btmapc_alloc_cntx(
                            sizeof(srv_sms_btmapc_action_struct),
                            SRV_SMS_BTMAPC_OP_CONN,
                            callback_func,
                            user_data);
    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_CONNECT_REQ, conn_cntx);
    if(conn_cntx != NULL)
    {
        //srv_bt_mapc_connect((void *)conn_cntx);
    }
    else
    {    
        error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
        srv_sms_btmapc_error_callback(SRV_SMS_BTMAPC_OP_CONN, error_cause, user_data, callback_func);
    }
    return hd;
}


void srv_sms_btmapc_disconnect(
          S32 hd,
          SrvSmsCallbackFunc callback_func,
          void *user_data)
{
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    srv_sms_btmapc_action_struct *disconn_cntx = NULL;
    
    disconn_cntx = srv_sms_btmapc_alloc_cntx(
                            sizeof(srv_sms_btmapc_action_struct),
                            SRV_SMS_BTMAPC_OP_DISCONN,
                            callback_func,
                            user_data);    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_DISCONNECT_REQ, disconn_cntx);
    if(disconn_cntx != NULL)
    {
        srv_mapc_disconnect((void *)disconn_cntx);
        srv_mapc_close(hd);
    }
    else
    {    
        error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
        srv_sms_btmapc_error_callback(SRV_SMS_BTMAPC_OP_DISCONN, error_cause, user_data, callback_func);
    }
}

void srv_sms_btmapc_change_folder(
          SrvSmsCallbackFunc callback_func,
          void *user_data)
{
    CHAR path[32] = {0};
    srv_sms_btmapc_change_folder_struct *change_folder_cntx = NULL;
    
    change_folder_cntx = srv_sms_btmapc_alloc_cntx(
                            sizeof(srv_sms_btmapc_change_folder_struct),
                            SRV_SMS_BTMAPC_OP_CHANGE_FOLDER,
                            callback_func,
                            user_data);
    change_folder_cntx->curr_box_type = SRV_SMS_BTMAPC_BOX_INBOX;
    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_GET_MSG_LIST, MMI_TRUE, 1, 100);
    if(change_folder_cntx != NULL)
    {
        mmi_asc_to_ucs2(path, (char *)INBOX_PATH);
        srv_mapc_change_folder((U8 *)path, SRV_BT_MAPC_FORWARD, SRV_BT_MAPC_NONE, (void *)change_folder_cntx);
    }
    else
    {    
        srv_sms_btmapc_error_callback(SRV_SMS_BTMAPC_OP_CHANGE_FOLDER, SRV_SMS_CAUSE_MEM_INSUFFICIENT, user_data, callback_func);
    }
}

void srv_sms_btmapc_get_msg_list(
                MMI_BOOL is_refresh,
                srv_sms_btmapc_box_enum box_type,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    CHAR path[32] = {0};
    srv_sms_btmapc_change_folder_struct *change_folder_cntx = NULL;
    srv_bt_mapc_set_msg_listing_prop_struct msg_property = {0};
     
    change_folder_cntx = srv_sms_btmapc_alloc_cntx(
                            sizeof(srv_sms_btmapc_change_folder_struct),
                            SRV_SMS_BTMAPC_OP_CHANGE_FOLDER,
                            callback_func,
                            user_data);
    change_folder_cntx->curr_box_type = box_type;
    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_GET_MSG_LIST, is_refresh, box_type, change_folder_cntx);
    if(change_folder_cntx != NULL)
    {
        switch(box_type)
        {
            case SRV_SMS_BTMAPC_BOX_INBOX:
            {
                mmi_asc_to_ucs2(path, (char *)INBOX_PATH);
                break;
            }
            case SRV_SMS_BTMAPC_BOX_OUTBOX:
            {
                mmi_asc_to_ucs2(path, (char *)SENT_PATH);
                break;
            }
            case SRV_SMS_BTMAPC_BOX_DRAFTS:
            {
                mmi_asc_to_ucs2(path, (char *)DRAFT_PATH);
                break;
            }
            case SRV_SMS_BTMAPC_BOX_UNSENT:
            {
                mmi_asc_to_ucs2(path, (char *)OUTBOX_PATH);
                break;
            }
            default:
            {
                srv_sms_btmapc_error_callback(SRV_SMS_BTMAPC_OP_CHANGE_FOLDER, SRV_SMS_BTMAPC_OP_FAIL, user_data, callback_func);
                return;
            }
        }
        if(is_refresh == MMI_TRUE)
        {   
            srv_sms_btmapc_set_list_property(&msg_property);
            srv_bt_mapc_set_msg_listing_prop(&msg_property);
            srv_mapc_change_folder((U8 *)path, SRV_BT_MAPC_NEXT, SRV_BT_MAPC_MESSAGE_LIST_ONLY, (void *)change_folder_cntx);
        }
        else
        {
            srv_sms_btmapc_succ_callback(SRV_SMS_BTMAPC_OP_CHANGE_FOLDER, (void *)change_folder_cntx, user_data, callback_func);
        }
    }
    else
    {    
        srv_sms_btmapc_error_callback(SRV_SMS_BTMAPC_OP_CHANGE_FOLDER, SRV_SMS_CAUSE_MEM_INSUFFICIENT, user_data, callback_func);
    }
}


SMS_HANDLE srv_sms_btmapc_change_msg_status(
          U16 msg_id,
          srv_sms_status_enum status,
          SrvSmsCallbackFunc callback_func,
          void *user_data)
{
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    srv_sms_btmapc_change_status_cntx_struct *change_cntx = NULL;
    
    change_cntx = srv_sms_btmapc_alloc_cntx(
                            sizeof(srv_sms_btmapc_change_status_cntx_struct),
                            SRV_SMS_BTMAPC_OP_CHANGE_STATUS,
                            callback_func,
                            user_data);
    if (change_cntx != NULL)
    {
        srv_sms_btmapc_change_msg_status_init(
                    change_cntx,
                    msg_id,
                    status);
        
        error_cause = srv_sms_btmapc_check_common_msg_error(msg_id, SRV_SMS_ACTION_CHANGE_STATUS);
        if(error_cause != SRV_SMS_CAUSE_NO_ERROR)
        {
            srv_sms_status_enum msg_status;
            srv_sms_mti_enum mti;
            srv_sms_mti_enum msg_mti;

            msg_status = srv_sms_btmapc_get_msg_status(msg_id);
            if (status == msg_status)
            {
                return change_cntx;
            }
            
            mti = srv_sms_btmapc_status_to_mti(status);
            msg_mti = srv_sms_btmapc_status_to_mti(msg_status);
            if (mti != msg_mti)
            {
                error_cause = SRV_SMS_CAUSE_OP_NOT_ALLOWED;
                return change_cntx;
            }
            if(msg_mti == SRV_SMS_MTI_DELIVER)
            {
                if(status == SRV_SMS_STATUS_READ)
                {
                    srv_sms_btmapc_set_msg_status_req(msg_id, SRV_BT_MAP_MSG_STATUS_READ, (void *)change_cntx);
                }
                else if(status == SRV_SMS_STATUS_UNREAD)
                {
                    srv_sms_btmapc_set_msg_status_req(msg_id, SRV_BT_MAP_MSG_STATUS_UNREAD, (void *)change_cntx);
                }
            }
        }
    }
    else
    {    
        error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
        srv_sms_btmapc_error_callback(SRV_SMS_BTMAPC_OP_CHANGE_STATUS, error_cause, user_data, callback_func);
    }
    return change_cntx;
}


SMS_HANDLE srv_sms_btmapc_delete_msg(
          U16 msg_id, 
          SrvSmsCallbackFunc callback_func, 
          void *user_data)
{
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    srv_sms_btmapc_delete_cntx_struct *delete_cntx = NULL;

    delete_cntx = srv_sms_btmapc_alloc_cntx(
                    sizeof(srv_sms_btmapc_delete_cntx_struct),
                    SRV_SMS_BTMAPC_OP_DELETE_MSG,
                    callback_func,
                    user_data);
    if(delete_cntx != NULL)
    {
        srv_sms_btmapc_delete_msg_init(
                delete_cntx,
                msg_id,
                MMI_FALSE);
        
        error_cause = srv_sms_btmapc_check_common_msg_error(msg_id, SRV_SMS_ACTION_DELETE);
        if(error_cause == SRV_SMS_CAUSE_NO_ERROR)
        {
            srv_sms_btmapc_set_msg_status_req(msg_id, SRV_BT_MAP_MSG_STATUS_DELETE, (void *)delete_cntx);
        }
    }
    else
    {    
        error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
        srv_sms_btmapc_error_callback(SRV_SMS_BTMAPC_OP_DELETE_MSG, error_cause, user_data, callback_func);
    }
    return delete_cntx;
}


void srv_sms_btmapc_send_msg(
          SMS_HANDLE sms_handle, 
          SrvSmsCallbackFunc callback_func, 
          void *user_data)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum cause = SRV_SMS_CAUSE_NO_ERROR;
    MMI_BOOL result = MMI_FALSE;
    S8* number = NULL;
    srv_sms_btmapc_handle_struct *sms_hd = (srv_sms_btmapc_handle_struct*) sms_handle;
    srv_sms_btmapc_send_handle_struct *hd_data = (srv_sms_btmapc_send_handle_struct*) sms_hd->hd_data;
    hd_data->callback_func = callback_func;
    hd_data->user_data = user_data;
    number = hd_data->msg_data.number;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((number[0] == '\0') && (number[1] == '\0'))
    {
        cause = SRV_SMS_CAUSE_NUMBER_EMPTY;
    }
    else if (srv_sms_check_ucs2_number(number) == MMI_FALSE)
    {
        cause = SRV_SMS_CAUSE_NUMBER_INVALID;
    }
    if (cause == SRV_SMS_CAUSE_NO_ERROR)
    {
        srv_bt_mapc_push_message_req_struct req;
        result = srv_sms_btmapc_build_bmessage(hd_data, &req);
        if (result)
        {
            srv_sms_btmapc_send_msg_req(&req, sms_handle);
        }
    }
    else
    {
        srv_sms_btmapc_send_msg_callback(sms_handle, MMI_FALSE, cause);
    }
}


SMS_HANDLE srv_sms_btmapc_read_msg(
                U16 msg_id,
                MMI_BOOL change_status,
                srv_sms_msg_data_struct* msg_data,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    srv_sms_btmapc_read_cntx_struct *read_cntx = NULL;
    
    if(srv_sms_btmapc_is_msg_download(msg_id) == MMI_TRUE)
    {
        read_cntx = srv_sms_btmapc_alloc_cntx(
                        sizeof(srv_sms_btmapc_read_cntx_struct),
                        SRV_SMS_BTMAPC_OP_READ_MSG,
                        callback_func,
                        user_data);
        if(read_cntx != NULL)
        {
            srv_sms_btmapc_read_msg_init(
                    read_cntx,
                    msg_id,
                    change_status,
                    msg_data);
            read_cntx = srv_sms_btmapc_read_msg_detail(
                              msg_id, 
                              change_status, 
                              msg_data, 
                              (void *)read_cntx);
        }
    }
    return read_cntx;
}


SMS_HANDLE srv_sms_btmapc_get_msg(
                U16 msg_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
    {
    srv_sms_btmapc_get_msg_cntx_struct *get_msg_cntx = NULL;

    get_msg_cntx = srv_sms_btmapc_alloc_cntx(
                    sizeof(srv_sms_btmapc_get_msg_cntx_struct),
                        SRV_SMS_BTMAPC_OP_GET_MSG,
                        callback_func,
                        user_data);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_GET_MSG, msg_id, get_msg_cntx);
    if(get_msg_cntx != NULL)
    {
        get_msg_cntx->msg_id = msg_id;
        srv_sms_btmapc_get_msg_req(msg_id, (void *)get_msg_cntx);
    }
    return get_msg_cntx;
}

void srv_sms_btmapc_handle_evt(S32 srv_hd, srv_bt_mapc_cbevent_enum evt, void* para)
{
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_HANDLE_EVT, evt);
    switch(evt)
    {
        case SRV_BT_MAPC_EVT_ID_CONNECT_RSP:
            srv_sms_btmapc_connect_rsp(srv_hd, para);
            break;
        case SRV_BT_MAPC_EVT_ID_DISCONNECT_RSP:
            srv_sms_btmapc_disconnect_rsp(srv_hd, para);
            break;
        case SRV_BT_MAPC_EVT_ID_DISCONNECT_IND:
            srv_sms_btmapc_disconnect_ind(srv_hd, para);
            break;
        case SRV_BT_MAPC_EVT_ID_SET_FOLDER_RSP:
            srv_sms_btmapc_set_folder_rsp(srv_hd, para);
            break;
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
        #endif
        case SRV_BT_MAPC_EVT_ID_GET_MSG_LISTING_RSP:
            //parse msg list, emit evt can refresh folder
            srv_sms_btmapc_get_msg_list_rsp(srv_hd, para);
            break;
        case SRV_BT_MAPC_EVT_ID_SET_MSG_STATUS_RSP:
            //emit evt
            srv_sms_btmapc_set_msg_status_rsp(srv_hd, para);
            break;
        case SRV_BT_MAPC_EVT_ID_GET_MSG_RSP:
            //Parse folder list
            srv_sms_btmapc_get_msg_rsp(srv_hd, para);
            break;
        case SRV_BT_MAPC_EVT_ID_PUSH_MSG_RSP:
            //emit evt
            srv_sms_btmapc_send_msg_rsp(srv_hd, para);
            break;
        case SRV_BT_MAPC_EVT_ID_MNS_IND:
            //emit evt, new msg incoming
            srv_sms_btmapc_new_message_ind(srv_hd, para);
            break;
        default:
            break;
    }
}


static void srv_sms_btmapc_connect_rsp(S32 srv_hd, void* para)
{
    srv_bt_mapc_connect_rsp *res = (srv_bt_mapc_connect_rsp *)para;
    srv_sms_btmapc_change_folder_struct *change_folder_cntx = NULL;
    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_CONNECT_RSP, res->Error, res->user_data);
    if(res->Error == SRV_BT_MAPC_SUCCESS)
    {
        if(srv_bt_mapc_is_new_connection() == MMI_TRUE)
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_NEW_CONN);
            srv_sms_btmapc_storage_reset_data();
        }
        change_folder_cntx = srv_sms_btmapc_alloc_cntx(
                            sizeof(srv_sms_btmapc_change_folder_struct),
                            SRV_SMS_BTMAPC_OP_CHANGE_FOLDER,
                            NULL,
                            NULL);
        change_folder_cntx->curr_box_type = SRV_SMS_BTMAPC_BOX_NONE;
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_GET_MSG_LIST, MMI_TRUE, 1, 100);
        
        if(change_folder_cntx != NULL)
        {
            srv_mapc_change_folder(NULL, SRV_BT_MAPC_ROOT, SRV_BT_MAPC_NONE, (void *)change_folder_cntx);
        }
    }
}


static void srv_sms_btmapc_disconnect_rsp(S32 srv_hd, void* para)
{
    srv_bt_mapc_disconnect_rsp *res = (srv_bt_mapc_disconnect_rsp *)para;
    MMI_BOOL result = MMI_FALSE;
    srv_sms_cause_enum error_cause = SRV_SMS_BTMAPC_OP_FAIL;
    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_DISCONNECT_RSP, res->Error, res->user_data);
    if(res->Error == SRV_BT_MAPC_SUCCESS)
    {
        srv_sms_btmapc_storage_save_data();
        result = MMI_TRUE;
        error_cause = SRV_SMS_BTMAPC_OP_SUCC;
    }

    srv_sms_btmapc_cntx_callback(
        res->user_data,
        result,
        error_cause,
        NULL);
}


static void srv_sms_btmapc_disconnect_ind(S32 srv_hd, void* para)
{
    srv_sms_btmapc_storage_save_data();
    //emit evt
}


static void srv_sms_btmapc_set_folder_rsp(S32 srv_hd, void* para)
{
    srv_bt_mapc_set_folder_res *res = (srv_bt_mapc_set_folder_res *)para;
    srv_sms_btmapc_change_folder_struct *change_folder_cntx = (srv_sms_btmapc_change_folder_struct *)res->user_data;
    MMI_BOOL result = MMI_FALSE;
    srv_sms_cause_enum error_cause = SRV_SMS_BTMAPC_OP_FAIL;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_CONNECT_RSP, res->Error, res->user_data);
    if(res->Error == SRV_BT_MAPC_SUCCESS)
    {        
        result = MMI_TRUE;
        error_cause = SRV_SMS_BTMAPC_OP_SUCC;
        if(change_folder_cntx->curr_box_type == SRV_SMS_BTMAPC_BOX_NONE)
        {
            srv_sms_btmapc_change_folder(NULL, NULL);
        }
    }
    srv_sms_btmapc_cntx_callback(
        res->user_data,
        result,
        error_cause,
        NULL);
}


static void srv_sms_btmapc_get_msg_list_rsp(S32 srv_hd, void* para)
{
    srv_bt_mapc_get_msg_listing_rsp *rsp = (srv_bt_mapc_get_msg_listing_rsp *)para;
    MMI_BOOL result = MMI_FALSE;
    srv_sms_cause_enum error_cause = SRV_SMS_BTMAPC_OP_FAIL;
    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_GET_MSG_LIST_RSP, rsp->Error, rsp->user_data);
    if(rsp->Error == SRV_BT_MAPC_SUCCESS && rsp->file != NULL)
    {
        result = MMI_TRUE;
        error_cause = SRV_SMS_BTMAPC_OP_SUCC;
        srv_sms_btmapc_xml_parse((WCHAR *)rsp->file);        
    }
#ifdef __SRV_SMS_BTMAPC_TEST__
    srv_sms_btmapc_write_file(OUTPUT_MSG_LIST, (void *)srv_sms_btmapc_msg_list);
#endif
    srv_sms_btmapc_cntx_callback(
        rsp->user_data,
        result,
        error_cause,
        NULL);
}


static void srv_sms_btmapc_get_msg_req(U16 msg_id, void *userData)
{
    U8 *msg_handle = NULL;
    
    if(srv_sms_btmapc_is_msg_exist(msg_id))

    {
        msg_handle = srv_sms_btmapc_get_msg_handle(msg_id);
    }
    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_GET_MSG, msg_id, userData);
    if(msg_handle != NULL)
    {
        srv_bt_mapc_get_msg_req(msg_handle, MMI_FALSE, SRV_BT_CHARSET_UTF8, userData);
    }
    else
    {
        srv_sms_btmapc_cntx_callback(
            userData,
            MMI_FALSE,
            SRV_SMS_BTMAPC_OP_FAIL,
            NULL);
    }
}


static void srv_sms_btmapc_get_msg_rsp(S32 srv_hd, void* para)
{
    MMI_BOOL result = MMI_FALSE;
    srv_sms_cause_enum error_cause = SRV_SMS_BTMAPC_OP_FAIL;
    srv_bt_mapc_message_cnf_struct *res = (srv_bt_mapc_message_cnf_struct *)para;
    srv_sms_btmapc_get_msg_cntx_struct *get_msg_cntx = (srv_sms_btmapc_get_msg_cntx_struct *)res->user_data;
    U16 msg_id = get_msg_cntx->msg_id;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_GET_MSG_RSP, res->Error, res->user_data);
    if(res->Error == SRV_BT_MAPC_SUCCESS)
    {
        S32 fs_res = 0;
        MBT_MAP_MSG_OBJECT *msg = (MBT_MAP_MSG_OBJECT *)OslMalloc(sizeof(MBT_MAP_MSG_OBJECT));
        WCHAR *cont_filename = (WCHAR *)OslMalloc(SRV_FMGR_PATH_MAX_LEN + 1);
        WCHAR *orig_filename = (WCHAR *)OslMalloc(SRV_FMGR_PATH_MAX_LEN + 1);
        WCHAR file_name[SRV_SMS_BTMAPC_MAX_PATH_LEN];
        
        srv_sms_btmapc_get_msg_name(msg_id, MMI_FALSE, file_name);
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_GET_MSG_ID, msg_id);
        kal_wsprintf(cont_filename, SMS_BT_BMESSAGE_CONTENT_RECV, 0);
        kal_wsprintf(orig_filename, BT_MAP_RCV_MESSAGE_PUSH_FILE, 0);
        fs_res = FS_Move((WCHAR *)res->file, orig_filename, FS_MOVE_COPY | FS_MOVE_OVERWRITE, NULL, NULL, 0);
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_MOVE_FILE, fs_res);
        if(fs_res < 0)
        {
            result = MMI_FALSE;
            error_cause = SRV_SMS_CAUSE_FS_ERROR;
        }
        else
        {
            result = btmtk_map_vcard_parse_message_by_file(0, msg, NULL, file_name);
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_WRITE_CONTENT, 1, result, 0);
        }
        if (result)
        {
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
            #endif
            result = MMI_TRUE;
            error_cause = SRV_SMS_BTMAPC_OP_SUCC;
        }
        OslMfree(msg);
        OslMfree(cont_filename);
        OslMfree(orig_filename);
    }
    srv_sms_btmapc_callback(
        SRV_SMS_BTMAPC_OP_GET_MSG,
        result,
        error_cause,
        NULL,
        res->user_data,
        srv_sms_btmapc_save_sms_callback);
}


static void srv_sms_btmapc_set_msg_status_req(U16 msg_id, srv_bt_mapc_msg_status_enum status, void *userData)
{
    U8 *msg_handle = NULL;
    
    if(srv_sms_btmapc_is_msg_exist(msg_id))
    {
        msg_handle = srv_sms_btmapc_get_msg_handle(msg_id);
    }
    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_SET_MSG_STATUS_REQ, status, userData);
    if(msg_handle != NULL)
    {
        srv_bt_mapc_set_message_status_req(msg_handle, status, userData);
    }
    else
    {
        srv_sms_btmapc_cntx_callback(
            userData,
            MMI_FALSE,
            SRV_SMS_BTMAPC_OP_FAIL,
            NULL);
    }
}


static void srv_sms_btmapc_set_msg_status_rsp(S32 srv_hd, void* para)
{
    srv_bt_mapc_set_message_status_rsp *res = (srv_bt_mapc_set_message_status_rsp *)para;
    srv_sms_btmapc_handle_struct *sms_btmapc_cntx = (srv_sms_btmapc_handle_struct*)res->user_data;
    MMI_BOOL result = MMI_FALSE;
    srv_sms_cause_enum error_cause = SRV_SMS_BTMAPC_OP_FAIL;
    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_SET_MSG_STATUS_RSP, res->Error, res->user_data);
    if(res->Error == SRV_BT_MAPC_SUCCESS)
    {
        if(sms_btmapc_cntx->action == SRV_SMS_BTMAPC_OP_DELETE_MSG)
        {
            srv_sms_btmapc_delete_cntx_struct *delete_cntx = (srv_sms_btmapc_delete_cntx_struct *)res->user_data;
            srv_sms_btmapc_delete_msg_detail(
                delete_cntx->msg_id, 
                MMI_FALSE,
                delete_cntx);
        }
        else if(sms_btmapc_cntx->action == SRV_SMS_BTMAPC_OP_CHANGE_STATUS)
        {
            srv_sms_btmapc_change_status_cntx_struct *change_cntx = (srv_sms_btmapc_change_status_cntx_struct *)res->user_data;
            srv_sms_btmapc_change_msg_status_detail(
                change_cntx->msg_id,
                change_cntx->status,
                change_cntx);
        }
        result = MMI_TRUE;
        error_cause = SRV_SMS_BTMAPC_OP_SUCC;
    }
    srv_sms_btmapc_cntx_callback(
        res->user_data,
        result,
        error_cause,
        NULL);
}


static void srv_sms_btmapc_send_msg_req(srv_bt_mapc_push_message_req_struct *req, void *userData)
{
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_SEND_MSG_REQ, userData);
    srv_bt_mapc_push_message_req(req, userData);
}


static void srv_sms_btmapc_send_msg_rsp(S32 srv_hd, void* para)
{
    srv_bt_mapc_push_message_status_res *res = (srv_bt_mapc_push_message_status_res *)para;
    srv_sms_cause_enum cause = SRV_SMS_BTMAPC_OP_FAIL;
    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_SEND_MSG_RSP, res->Error, res->user_data);
    if(res->Error == SRV_BT_MAPC_SUCCESS)
    {
        cause = SRV_SMS_BTMAPC_OP_SUCC;
    }
    if(res->user_data != NULL)
    {
        srv_sms_btmapc_send_msg_callback(res->user_data, MMI_FALSE, cause);
    }
}

static void srv_sms_btmapc_new_message_ind(S32 srv_hd, void* para)
{
    //may be can notify number, and
    srv_bt_mapc_mns_send_event_ind_struct* newMsgInd = (srv_bt_mapc_mns_send_event_ind_struct *)para;
    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_NEW_MSG_IND, newMsgInd->data_size);
    if(newMsgInd->data_size > 0 && newMsgInd->file != NULL)
    {
        kal_int32 count = 0;
        count = srv_sms_btmapc_xml_parse((WCHAR *)newMsgInd->file);
        if (count == 0)
        {
            srv_sms_btmapc_send_evt_rsp(SRV_SMS_BTMAPC_FILE_ERROR);
        }
        else
        {
            srv_sms_btmapc_send_evt_rsp(SRV_SMS_BTMAPC_NEW_MSG);
        }
    }
    else
    {
        srv_sms_btmapc_send_evt_rsp(SRV_SMS_BTMAPC_FILE_ERROR);
    }
}

void srv_sms_btmapc_send_evt_rsp(srv_sms_btmapc_ind_enum type)
{
    srv_bt_mapc_mns_send_event_rsp_struct rsp;
    srv_bt_mapc_result_enum result = SRV_BT_MAPC_FAIL;
    
    switch(type)
    {
        case SRV_SMS_BTMAPC_NEW_MSG:
        case SRV_SMS_BTMAPC_DELI_SUCC:
        case SRV_SMS_BTMAPC_SEND_SUCC:
            result = SRV_BT_MAPC_SUCCESS;
            break;
        case SRV_SMS_BTMAPC_MEM_FULL:
            result = SRV_BT_MAPC_FAIL_STORAGE_FULL;
            break;
        case SRV_SMS_BTMAPC_FILE_ERROR:
            result = SRV_BT_MAPC_FAIL_NO_RESOURCE;
            break;
        default:
            break;
    }
    rsp.result = result;
    srv_bt_mapc_mns_send_event_rsp(rsp);
}

static MMI_BOOL srv_sms_btmapc_build_bmessage(srv_sms_btmapc_send_handle_struct *hd_data, srv_bt_mapc_push_message_req_struct *req)
{
    MBT_MAP_MSG_OBJECT *msg = (MBT_MAP_MSG_OBJECT *)OslMalloc(sizeof(MBT_MAP_MSG_OBJECT));
    MMI_BOOL result;
    WCHAR *cont_filename;
    S32 fhandle;
    U32 bytes_written =0;
    char number[SRV_SMS_MAX_ADDR_LEN +1];


    cont_filename = (WCHAR *)OslMalloc(SRV_FMGR_PATH_MAX_LEN + 1);
    kal_wsprintf(cont_filename, SMS_BT_BMESSAGE_CONTENT_SEND, 0);
    if ((fhandle = FS_Open(cont_filename, FS_READ_WRITE | FS_CREATE)) < 0)
    {
        OslMfree(msg);
        OslMfree(cont_filename);
        return MMI_FALSE;
    }
    FS_Write(fhandle, (hd_data->msg_data).content_buff, (hd_data->msg_data).content_buff_size, &bytes_written);
    FS_Close(fhandle);
        
    memset(msg, 0x00, sizeof(MBT_MAP_MSG_OBJECT));
    msg->MsgVer = MBT_MAP_MSG_VER_10;
    msg->ReadStatus = MBT_MAP_MSG_STATUS_UNREAD;
    msg->MsgType = MBT_MAP_MSG_TYPE_SMS_GSM;
    
    memcpy(msg->FolderPath, MSG_ROOT_PATH, strlen(MSG_ROOT_PATH));
    strcat(msg->FolderPath, OUTBOX_PATH);

    msg->Originator = (char *)OslMalloc(SMS_BT_MAX_FOLDER_LENGTH);
    sprintf(msg->Originator, "%s%s", OPER_BVCARD, OPER_END);
    strcat(msg->Originator, OPER_VERSION);
    strcat(msg->Originator, OPER_END);
    strcat(msg->Originator, OPER_NAME);
    strcat(msg->Originator, OPER_END);
    strcat(msg->Originator, OPER_TEL);
    strcat(msg->Originator, OPER_END);
    strcat(msg->Originator, OPER_EVCARD);
    msg->OriginatorSize = strlen(msg->Originator);

    msg->Envelope[0].Recipient = (char *)OslMalloc(SMS_BT_MAX_FOLDER_LENGTH);
    sprintf(msg->Envelope[0].Recipient, "%s%s", OPER_BVCARD, OPER_END);
    strcat(msg->Envelope[0].Recipient, OPER_VERSION);
    strcat(msg->Envelope[0].Recipient, OPER_END);
    strcat(msg->Envelope[0].Recipient, OPER_NAME);
    strcat(msg->Envelope[0].Recipient, OPER_END);
    strcat(msg->Envelope[0].Recipient, OPER_TEL);
    mmi_ucs2_to_asc(number, (hd_data->msg_data).number);
    strcat(msg->Envelope[0].Recipient, number);
    strcat(msg->Envelope[0].Recipient, OPER_END);
    strcat(msg->Envelope[0].Recipient, OPER_EVCARD);
    msg->Envelope[0].RecipientSize = strlen(msg->Envelope[0].Recipient);   
    
    msg->Charset = MBT_MAP_MSG_CHARSET_UTF8;

    msg->FragmentNum = 1;
    msg->FragmentSize[0] = (hd_data->msg_data).content_buff_size;

    msg->ContentSize = (hd_data->msg_data).content_buff_size;
    result = btmtk_map_vcard_create_message_by_file(0,
                                                    MBT_MAP_FRAC_REQ_NO,
                                                    MBT_MAP_FRAC_DELIVER_NO,
                                                    msg,
                                                    0,
                                                    cont_filename);
    if (result)
    {
        S32 fileHandle;
        U32 size = 0;
        req->charset = MBT_MAP_MSG_CHARSET_UTF8;
        mmi_asc_to_ucs2((CHAR *)req->child_folder, (CHAR *)OUTBOX_PATH);
        kal_wsprintf((WCHAR *)req->file, BT_MAP_MESSAGE_GET_FILE, 0);
        if ((fileHandle = FS_Open((WCHAR *)req->file, FS_READ_ONLY)) < 0)
        {
            req->data_size = 0;
        }
        else
        {
            FS_GetFileSize(fileHandle, &size);
            req->data_size = (U16)size;
            FS_Close(fileHandle);
        }        
    }
    
    FS_Delete(cont_filename);
    OslMfree(msg->Originator);
    OslMfree(msg->Envelope[0].Recipient);
    OslMfree(msg);
    OslMfree(cont_filename);
    return result;
}



static void srv_sms_btmapc_set_list_property(srv_bt_mapc_set_msg_listing_prop_struct *msg)
{
    msg->FilterMessageType = SRV_BT_MAPC_FILTER_MSG_TYPE_SMS_CDMA | SRV_BT_MAPC_FILTER_MSG_TYPE_EMAIL | SRV_BT_MAPC_FILTER_MSG_TYPE_MMS;
    msg->FilterPriority = SRV_BT_MAPC_NO_PRIORITY;
    msg->Maxlistcount = SRV_SMS_BTMAPC_MAX_SMS_ENTRY;
    msg->ListStartOffset = 0;
    msg->SubjectLength = SRV_SMS_MSG_INFO_CONTENT_LEN;
    msg->ParameterMask = 0;
    msg->FilterReadStatus = SRV_BT_MAPC_NO_READ_FILTER;
}

static void srv_sms_btmapc_save_sms_callback(srv_sms_callback_struct* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_get_msg_cntx_struct* get_msg_cntx = (srv_sms_btmapc_get_msg_cntx_struct*)user_data->user_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (user_data->result == MMI_FALSE)
    {
        if (user_data->cause == SRV_SMS_CAUSE_MEM_FULL)    
        {
            srv_sms_event_mem_exceed_struct *event_data;

            event_data = (srv_sms_event_mem_exceed_struct *)OslMalloc(sizeof(srv_sms_event_mem_exceed_struct));
            //error_cause = SRV_SMS_FCS_MEM_EXCEED;                
            event_data->mem_type = SRV_SMS_MEM_ME_ONLY;            
            srv_sms_btmapc_emit_event(EVT_ID_SRV_SMS_BTMAPC_MEM_EXCEED, event_data);
            OslMfree(event_data);
        }
    }
    else
    {    
        U16 msg_id = get_msg_cntx->msg_id;
        srv_sms_event_new_sms_struct *event_data;
        
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_DOWNLOAD_DONE);
        srv_sms_btmapc_set_msg_download(msg_id);
        event_data = (srv_sms_event_new_sms_struct *)OslMalloc(sizeof(srv_sms_event_new_sms_struct));
        event_data->msg_id = msg_id;
        srv_sms_btmapc_emit_event(EVT_ID_SRV_SMS_BTMAPC_NEW_MSG, event_data);
        OslMfree(event_data);
    }

    srv_sms_btmapc_cntx_callback(
        get_msg_cntx,
        user_data->result,
        user_data->cause,
        NULL);
}

#endif /* __SRV_SMS_BTMAPC__ */
#endif /* __MOD_SMSAL__ */

