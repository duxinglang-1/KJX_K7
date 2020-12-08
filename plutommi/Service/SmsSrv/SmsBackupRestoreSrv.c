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
 *  SmsBackupRestoreSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Backup and Restore 
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *****************************************************************************/

 #include "MMI_features.h"
//#ifdef __MOD_SMSAL__
#ifdef __SMS_CLOUD_SUPPORT__
/**************************************************************
* Header Files Include
**************************************************************/
#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "app_ltlcom.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "Unicodexdcl.h"
#include "mmi_frm_mem_gprot.h"
#include "string.h"
#include "custom_mmi_default_value.h"
#include "MMI_common_app_trc.h"
#include "mmi_frm_queue_gprot.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "stack_config.h"
#include "app_datetime.h"
#include "DateTimeType.h"
#include "mmi_cb_mgr_gprot.h"
#include "kal_trace.h"

#include "mmi_msg_context.h"
#include "sim_common_enums.h"
#include "smu_common_enums.h"
#include "Csmcc_enums.h"
#include "nvram_common_defs.h"
#include "ProtocolEvents.h"
#include "SmsSrvGProt.h"
#include "SmsProtSrv.h"
#include "SmsUtilSrv.h"
#include "SmsSettingSrv.h"
#include "SmsEmsSrv.h"
#include "SmsStorageSrv.h"
#include "SmsStorageCoreSrv.h"
#include "gui_data_types.h"
#include "ps_public_enum.h"
#include "SimCtrlSrvGProt.h"
#include "App_usedetails.h"

//#include "BackRestoreSrvGprot.h"
#include "CloudSrvGprot.h"
#include "SmsBackupRestoreSrv.h"
#include "mmi_rp_srv_backup_restore_def.h"
#include "SmsProtSrv.h"

/****************************************************/
/*                                                  */
/*               Enum                               */
/*                                                  */
/****************************************************/

/* SMS bearer Type */


/**************************************************************
* Structure Declaration
**************************************************************/


typedef struct
{
    SRV_SMS_HANDLE_HEADER
    U16 msg_id;
    U16 total_index;
    srv_sms_msg_data_struct *msg_data;
} srv_sms_backup_to_cloud_cntx_struct;





/**************************************************************
* Static Variables Defination
**************************************************************/

srv_sms_backup_cntx_struct backup_cntx;
srv_sms_restore_cntx_struct restore_cntx;
srv_sms_cloud_action_enum in_cloud_action;
static U16 uid_index[SRV_SMS_MAX_ME_SMS_ENTRY];
static U16 msg_index[SRV_SMS_MAX_ME_SMS_ENTRY];
static CHAR number[(SRV_SMS_MAX_ADDR_LEN+1)*SRV_SMS_MAX_CLOUD_RECIPIENTS_NUM];
static CHAR content[3060];
static S8 sms_data[512];
static MMI_BOOL have_data_sync;
static MMI_BOOL is_abort;





/**************************************************************
* Static Function Declaration
**************************************************************/

static void srv_sms_begin_restore_sms(void);

static void srv_sms_begin_to_set_operate(void);

static void srv_sms_begin_restore_sms_callback(srv_sms_callback_struct* callback_data);
static void srv_sms_copy_to_cloud_service(srv_sms_backup_cntx_struct *temp_backup_cntx);
static void  srv_sms_copy_to_cloud_service_callback(srv_sms_callback_struct* callback_data);

static U16 srv_sms_get_backup_restore_index_list(U16 *list_ptr);

static U16 srv_sms_get_backup_restore_msg_list(U16 *list_ptr);

/**************************************************************
* Function Defination
**************************************************************/




extern srv_sms_restore_cntx_struct *srv_sms_get_restore_ctnx(void)
{
    return &restore_cntx;
}
extern srv_sms_backup_cntx_struct *srv_sms_get_backup_ctnx(void)
{
    return &backup_cntx;
}
extern srv_sms_cloud_action_enum srv_sms_get_cloud_action_ctnx(void)
{
    return in_cloud_action;
}


MMI_BOOL srv_sms_is_need_to_backup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_num;
	U16 temp_uid_index[SRV_SMS_MAX_ME_SMS_ENTRY];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(temp_uid_index, 0XFF,SRV_SMS_MAX_ME_SMS_ENTRY*2);
    msg_num = srv_sms_get_backup_restore_msg_list(temp_uid_index);
	if (msg_num > 0)
	{
	    return MMI_TRUE;
	}
	else
	{
	    return MMI_FALSE;
	}
	
}

static void srv_sms_begin_to_set_operate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 operate_result = SRV_CLD_ERROR;
    srv_cloud_op_struct op;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_cloud_action == SRV_SMS_CLOUD_ACTION_RESTORE)
    {
        op.op_type = SRV_CLD_OP_RESTORE;
        operate_result = srv_cloud_operate(restore_cntx.handle, &op);
    }
    else
    {
        if(in_cloud_action == SRV_SMS_CLOUD_ACTION_BACKUP)
        {
            op.op_type = SRV_CLD_OP_BACKUP;
		    operate_result = srv_cloud_operate(backup_cntx.handle, &op);
        }
        
    }
    
    if (operate_result != SRV_CLD_SUCCESS &&
        operate_result != SRV_CLD_WOULDBLOCK)
    {
        if (in_cloud_action == SRV_SMS_CLOUD_ACTION_RESTORE)
        {
            restore_cntx.result = MMI_FALSE;
            restore_cntx.error_cause = operate_result;
            srv_cloud_close(restore_cntx.handle);
        }
        else
        {
            if(in_cloud_action == SRV_SMS_CLOUD_ACTION_BACKUP)
            {
                backup_cntx.result = MMI_FALSE;
                backup_cntx.error_cause = operate_result;
                srv_cloud_close(backup_cntx.handle);
            }
            
        }
        
    }
}


static U16 srv_sms_get_backup_restore_index_list(U16 *list_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 inbox_size = 0;
    U16 outbox_size = 0;
    S32 i;
    MMI_BOOL is_sim_msg = MMI_FALSE;
    U16 temp_pdu_id = SRV_SMS_INVALID_PDU_ID;
    srv_sms_msg_node_struct msg_node;
    U16 *inbox_list;
    U16 *outbox_list;
    U16 uid_num = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_get_list_and_size(&inbox_list, &inbox_size, SRV_SMS_BOX_INBOX);
    srv_sms_get_list_and_size(&outbox_list, &outbox_size, SRV_SMS_BOX_OUTBOX);
    /*get inbox msg*/
    for(i = 0; i < inbox_size; i++)
    {
        msg_node = srv_sms_msg_list[inbox_list[i]];
        
        temp_pdu_id = msg_node.start_pdu_id;
        while (temp_pdu_id != SRV_SMS_INVALID_PDU_ID)
        {
            if(temp_pdu_id >= SRV_SMS_MAX_ME_SMS_ENTRY)
            {
                is_sim_msg = MMI_TRUE;
                break;
            }
            temp_pdu_id = srv_sms_pdu_list[temp_pdu_id].next_pdu_id;
        }
        if(!is_sim_msg)
        {
            temp_pdu_id = msg_node.start_pdu_id;
            while(srv_sms_pdu_list[temp_pdu_id].next_pdu_id != SRV_SMS_INVALID_PDU_ID)
            {
                temp_pdu_id = srv_sms_pdu_list[temp_pdu_id].next_pdu_id;
            }
            list_ptr[i] = temp_pdu_id;
            uid_num ++;
        }
        
    }
     /*get outbox msg*/
    for(i = 0; i < outbox_size; i++)
    {
        msg_node = srv_sms_msg_list[outbox_list[i]];
        temp_pdu_id = msg_node.start_pdu_id;
        while (temp_pdu_id != SRV_SMS_INVALID_PDU_ID)
        {
            if(temp_pdu_id >= SRV_SMS_MAX_ME_SMS_ENTRY)
            {
                is_sim_msg = MMI_TRUE;
                break;
            }
            temp_pdu_id = srv_sms_pdu_list[temp_pdu_id].next_pdu_id;
        }
        if(!is_sim_msg)
        {
			temp_pdu_id = msg_node.start_pdu_id;
            while(srv_sms_pdu_list[temp_pdu_id].next_pdu_id != SRV_SMS_INVALID_PDU_ID)
            {
                temp_pdu_id = srv_sms_pdu_list[temp_pdu_id].next_pdu_id;
            }
            list_ptr[inbox_size + i] = temp_pdu_id; 
            uid_num ++;
        }
        
    }
    
    return uid_num;
}

static U16 srv_sms_get_backup_restore_msg_list(U16 *list_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 inbox_size = 0;
    U16 outbox_size = 0;
    U16 *inbox_list;
    U16 *outbox_list;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_get_list_and_size(&inbox_list, &inbox_size, SRV_SMS_BOX_INBOX);
    srv_sms_get_list_and_size(&outbox_list, &outbox_size, SRV_SMS_BOX_OUTBOX);

    /*get inbox msg*/
    for(i = 0; i < inbox_size; i++)
    {
        list_ptr[i] = inbox_list[i];       
    }
     /*get inbox msg*/
    for(i = 0; i < outbox_size; i++)
    {
       list_ptr[inbox_size + i] = outbox_list[i]; 
    }

    return (inbox_size + outbox_size);
}

static void srv_sms_begin_restore_sms_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    
    srv_sms_event_backup_restore_struct event_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BEGIN_RESTORE_SMS_CALLBACK_0 , callback_data->result);
    restore_cntx.more_data --;
    if(callback_data->result)
    {
    
        /*ind the app to show the process*/
        S32 result;
        U16 msg_id;
        U16 temp_pdu_id;
        event_info.action = SRV_SMS_ACTION_RESTORE;        
        index = restore_cntx.curr_num;
        event_info.cur_index = index;
        event_info.Total_number = SRV_SMS_MAX_ME_SMS_ENTRY;
        srv_sms_emit_event(EVT_ID_SRV_SMS_BACKUP_RESTORE, &event_info);
        restore_cntx.curr_num ++;
        /*sync the UID with backup/restore service*/
        msg_id = ((srv_sms_save_msg_cb_struct*)(callback_data->action_data))->msg_id;
        temp_pdu_id = srv_sms_msg_list[msg_id].start_pdu_id;
        while(srv_sms_pdu_list[temp_pdu_id].next_pdu_id != 0xFFFF)
        {
            temp_pdu_id = srv_sms_pdu_list[temp_pdu_id].next_pdu_id;
        }
        
        result = srv_cloud_sync_set_store_uid(temp_pdu_id, 
                                 NULL, 
                                 SRV_CLD_TYPE_SMS, 
                                 SRV_CLD_ACTION_ADD);
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BEGIN_RESTORE_SMS_CALLBACK_1 , result);
        

        if( restore_cntx.more_data > 0)
        {
            srv_sms_begin_restore_sms();
        }
    }
    else
    {
        /*check it, and mark down the result and the error cause*/
        restore_cntx.result = MMI_FALSE;
        restore_cntx.error_cause = callback_data->cause;
        srv_cloud_close(restore_cntx.handle);
        
    }

    
}

static void srv_sms_copy_to_cloud_service_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_backup_to_cloud_cntx_struct *cntx;
    S32 result;
    S32 hdlr;
    srv_sms_backup_restore_msg_data_struct backup_restore_msg_data;
    srv_sms_msg_data_struct *msg_data;
    U32 timestamp;
    srv_cloud_sms_struct cloud_sms_data;
    srv_sms_event_backup_restore_struct event_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (srv_sms_backup_to_cloud_cntx_struct*)callback_data->user_data;
    msg_data = cntx->msg_data;
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_TO_CLOUD_SERVICE_CALLBACK_0 , callback_data->result);
    if(callback_data->result)
    {
        if(msg_data->is_with_obj)
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_TO_CLOUD_SERVICE_CALLBACK_1);
            OslMfree(msg_data);
            srv_sms_free_cntx(cntx);
            return;    
        }
        memset(&backup_restore_msg_data, 0, sizeof(srv_sms_backup_restore_msg_data_struct*) );

        /*convert to sms_data for cloud service*/
        
        backup_restore_msg_data.sim_id= srv_sms_msg_list[backup_cntx.curr_index].sim_id;
        memcpy(backup_restore_msg_data.sc_address, msg_data->sc_address, (SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH);
        backup_restore_msg_data.status = msg_data->status;
        backup_restore_msg_data.dcs = msg_data->dcs;
        backup_restore_msg_data.msg_class = msg_data->msg_class;
        backup_restore_msg_data.dest_port = msg_data->dest_port;
        backup_restore_msg_data.pid = msg_data->pid;
        backup_restore_msg_data.vp = msg_data->vp;
        backup_restore_msg_data.status_report = msg_data->status_report;
        backup_restore_msg_data.reply_path = msg_data->reply_path;
    #if 0
/* under construction !*/
/* under construction !*/
    #endif
        /*convert msg_data to data that put to cloud server*/
       
        hdlr = backup_cntx.handle;
        
        
        cloud_sms_data.sms_data = (U8*)&backup_restore_msg_data;
        cloud_sms_data.sms_data_len = sizeof(srv_sms_backup_restore_msg_data_struct);
        /*the following is info for email to show*/
        cloud_sms_data.content = (WCHAR*)msg_data->content_buff;
        cloud_sms_data.content_buf_len = msg_data->content_size;
        timestamp = srv_sms_msg_list[backup_cntx.curr_index].timestamp;
        cloud_sms_data.date = timestamp;
        cloud_sms_data.number = backup_cntx.ext_number;
        cloud_sms_data.number_buf_len = strlen(backup_cntx.ext_number);
        backup_restore_msg_data.ext_number_num = backup_cntx.ext_number_num;

        OslMfree(msg_data);
        
        result = srv_cloud_put_data(
                        hdlr, 
                        (const U8 *)&cloud_sms_data, 
                        backup_cntx.uid_index, 
                        sizeof(srv_cloud_sms_struct));
        //add trace
        if (result == SRV_CLD_SUCCESS ||
            result == SRV_CLD_WOULDBLOCK)
        { 
            U16 index;
            event_info.action = SRV_SMS_ACTION_BACKUP;
            index = backup_cntx.curr_index;
            event_info.cur_index = index;
            event_info.Total_number = backup_cntx.total_index;
            srv_sms_emit_event(EVT_ID_SRV_SMS_BACKUP_RESTORE, (void*)&event_info);
            backup_cntx.curr_index++;
            
        }
        else if(result == SRV_CLD_ERROR)
        {
            backup_cntx.result = MMI_FALSE;
            backup_cntx.error_cause = callback_data->cause;
            srv_cloud_close(backup_cntx.handle); 
        } 
        srv_sms_free_cntx(cntx);
    }
}



/*****************************************************************************
* FUNCTION
*  srv_sms_backup_msg
* DESCRIPTION
*  to backup sms
* PARAMETERS
*  backup_restore_info: [in] the dest and the account info
*  callback: [in] callback
*  user_data: [in] user_data
* RETURNS
*  MMI_BOOL
*****************************************************************************/

static void srv_sms_copy_to_cloud_service(srv_sms_backup_cntx_struct *temp_backup_cntx)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                */
/*----------------------------------------------------------------*/
    U16 msg_id;
    srv_sms_status_enum status;
    U16 tmp_pdu_id;
    //SMS_HANDLE read_hd;
    srv_sms_msg_node_struct *msg_node;
    MMI_BOOL flag = MMI_TRUE;
    MMI_BOOL result = MMI_TRUE;
    //srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    srv_sms_backup_to_cloud_cntx_struct *cntx = NULL;
    
/*----------------------------------------------------------------*/
/* Code Body                                                      */
/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_TO_CLOUD_SERVICE_0);
    do
    {
        if(backup_cntx.curr_index == backup_cntx.total_index)
        {
            flag = MMI_FALSE;
            result = MMI_TRUE;
            backup_cntx.result = MMI_TRUE;
            /*check it,and mark down the MMI_TRUE,SRV_SMS_CAUSE_NO_ERROR*/
            srv_cloud_close(backup_cntx.handle);
            break;
            
        }
        msg_id = backup_cntx.msg_id_list[backup_cntx.curr_index];
        msg_node = &srv_sms_msg_list[msg_id];
        /*the pdu_id*/
        tmp_pdu_id = msg_node->start_pdu_id;
        while(srv_sms_pdu_list[tmp_pdu_id].next_pdu_id != 0xffff)
        {
            tmp_pdu_id = srv_sms_pdu_list[tmp_pdu_id].next_pdu_id;
        }
        backup_cntx.uid_index = tmp_pdu_id;
        
        /*if server has the same sms, it will try the next one immediately*/
        if(!srv_cloud_backup_uid_check( backup_cntx.uid_index, SRV_CLD_TYPE_SMS))
        {           
            backup_cntx.curr_index++;
            
            /*if there is still sms to backup,continue; if not,invoke callback to tell ap*/
            if(backup_cntx.curr_index < backup_cntx.total_index)
            {
                flag = MMI_TRUE;
            }
            else
            {
                flag = MMI_FALSE;
                result = MMI_TRUE;
                backup_cntx.result = MMI_TRUE;
                /*check it,and mark down the MMI_TRUE,SRV_SMS_CAUSE_NO_ERROR*/
                srv_cloud_close(backup_cntx.handle);
            }
        }
        else
        {
            flag = MMI_FALSE;
            have_data_sync = MMI_TRUE;
            if (backup_cntx.curr_index < backup_cntx.total_index)
            {
                /*if one of the sms is not exist, the whole operate will be stop*/
                if (!srv_sms_is_msg_exist_ext(msg_id))
                {
                    //error_cause = SRV_SMS_CAUSE_INVALID_MEM_INDEX;
                    result = MMI_FALSE;
                    break;
                }

                status = srv_sms_get_msg_status(msg_id);
                /*if one of sms is not supported, it will go to the next sms*/
                if (status & SRV_SMS_STATUS_UNSUPPORTED)
                {
                    //error_cause = SRV_SMS_CAUSE_OP_NOT_SUPPORTED;
                    result = MMI_FALSE;
                    break;
                }
                
                cntx = srv_sms_alloc_cntx(
                            sizeof(srv_sms_backup_to_cloud_cntx_struct),
                            SRV_SMS_ACTION_BACKUP,
                            NULL,
                            NULL);
                /*if the where is no cntx, stop the whole operate*/
                if (cntx == NULL)
                {
                    //error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
                    result = MMI_FALSE;
                    break;
                }
                else
                {
                    U8 *addr_list;
                    S32 i;
                #ifdef __SRV_SMS_MULTI_ADDR__
                    S32 j;
                    U16 next_addr_id;
                    next_addr_id = msg_node->start_addr_id;
                #endif
                    addr_list = (U8 *)backup_cntx.ext_number;
                    memset(addr_list, 0, (SRV_SMS_MAX_ADDR_LEN + 1) * SRV_SMS_MAX_CLOUD_RECIPIENTS_NUM); 
                    for(i = 0; i < SRV_SMS_MAX_ADDR_LEN ; i++)
                    {
                        if(msg_node->number[i] == 0)
                        {
                            break;
                        }
                    }
                    memcpy(backup_cntx.ext_number, msg_node->number, i);
                    backup_cntx.ext_number[i] = ';';
                    addr_list += (i + 1);
                #ifdef __SRV_SMS_MULTI_ADDR__
                    /*handle multi addr*/
                    if(msg_node->ext_addr_num >0)
                    {  
                        S32 temp_count;
                        j = 0;
                        if(msg_node->ext_addr_num >= SRV_SMS_MAX_CLOUD_RECIPIENTS_NUM - 1)
                        {
                            temp_count = SRV_SMS_MAX_CLOUD_RECIPIENTS_NUM - 1;
                        }
                        else
                        {
                            temp_count = msg_node->ext_addr_num;
                        }
                        while(next_addr_id != 0xFFFF && j < temp_count)
                        {
                            j ++;
                            for(i = 0; i < SRV_SMS_MAX_ADDR_LEN ; i++)
                            {
                                if(srv_sms_addr_list[next_addr_id].address[i] == 0)
                                {
                                    break;
                                }
                            }
                            memcpy(addr_list, srv_sms_addr_list[next_addr_id].address, i);
                            addr_list[i] = ';';
                            addr_list += i + 1;
                            next_addr_id = srv_sms_addr_list[next_addr_id].next_addr_id;
                        }
                        backup_cntx.ext_number_num = msg_node->ext_addr_num + 1;
                    }
                #else
                    backup_cntx.ext_number_num = 1;
                #endif 
                    cntx->msg_data = (srv_sms_msg_data_struct*)OslMalloc(sizeof(srv_sms_msg_data_struct));
                    cntx->msg_data->content_buff = content;
                    cntx->msg_data->content_buff_size = 3060;
                    cntx->msg_data->para_flag = (srv_sms_para_enum)(SRV_SMS_PARA_CONTENT_BUFF | SRV_SMS_PARA_SCA |
                                                SRV_SMS_PARA_PID | SRV_SMS_PARA_STATUS | 
                                                SRV_SMS_PARA_STORAGE_TYPE | SRV_SMS_PARA_TIMESTAMP |
                                                SRV_SMS_PARA_CLASS | SRV_SMS_PARA_DCS | SRV_SMS_PARA_VP |
                                                SRV_SMS_PARA_STATUS_REPORT | SRV_SMS_PARA_REPLY_PATH | SRV_SMS_PARA_PORT);    
                    srv_sms_read_msg(
                                msg_id,
                                MMI_FALSE,
                                cntx->msg_data,
                                srv_sms_copy_to_cloud_service_callback,
                                cntx);
                }
            }
        }
    }while(flag);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_TO_CLOUD_SERVICE_1,result);
    
    if(!result)
    {
        //the sms dose not be backup to server
        if(backup_cntx.curr_index < backup_cntx.total_index)
        {
            backup_cntx.curr_index++;
            srv_sms_copy_to_cloud_service(&backup_cntx);
        }
        else
        {
            flag = MMI_FALSE;
            result = MMI_TRUE;
            backup_cntx.result = MMI_TRUE;
            srv_cloud_close(backup_cntx.handle);
        }
    }
}


static void srv_sms_begin_restore_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    S32 result;
    S32 hdl;
    S32 i;
    U32 num;
    MMI_BOOL is_full;
    srv_cloud_sms_struct *cloud_sms_data;
    //srv_sms_int_msg_data_struct *msg_data;
    srv_sms_backup_restore_msg_data_struct *backup_restore_msg_data;
    char ucs2_addr[(SRV_SMS_MAX_ADDR_LEN +1) *ENCODING_LENGTH];
    U32 buf_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    hdl = restore_cntx.handle;
    
    cloud_sms_data = OslMalloc(sizeof(srv_cloud_sms_struct));
    buf_size = sizeof(srv_cloud_sms_struct);
    cloud_sms_data->content = content;
    cloud_sms_data->content_buf_len = sizeof(content);
    memset(cloud_sms_data->content, 0, cloud_sms_data->content_buf_len);
    cloud_sms_data->number= number;
    cloud_sms_data->number_buf_len= sizeof(number);
    memset(cloud_sms_data->number, 0, cloud_sms_data->number_buf_len);
    cloud_sms_data->sms_data = sms_data;
    cloud_sms_data->sms_data_len = sizeof(sms_data);
    memset(cloud_sms_data->sms_data, 0, cloud_sms_data->sms_data_len);
    result = srv_cloud_get_data(hdl, cloud_sms_data, &num, &buf_size);
    
    //restore_cntx.more_data --;
    is_full = srv_sms_is_memory_full(SRV_SMS_STORAGE_ME, SRV_SMS_SIM_1);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BEGIN_RESTORE_SMS_0, result, is_full);
    if(is_full)
    {
        
        /*check it, it need to mark down the the result and error in the restore_cntx*/
        restore_cntx.result = MMI_FALSE;
        restore_cntx.error_cause = SRV_SMS_CAUSE_MEM_FULL;
        srv_cloud_close(hdl);
    }
    else
    {  
        if(result == SRV_CLD_SUCCESS)
        { 
            MYTIME timestamp;
            SMS_HANDLE sms_handle;
            U8 ext_addr_start;
            CHAR *number_buf;
            WCHAR append_ucs2_addr[SRV_SMS_MAX_ADDR_LEN+1];
            
           

            sms_handle = srv_sms_get_save_handle();
            backup_restore_msg_data = cloud_sms_data->sms_data;

            srv_sms_set_status(sms_handle, (srv_sms_status_enum)backup_restore_msg_data->status);   
            srv_sms_set_sim_id(sms_handle, (srv_sms_sim_enum)backup_restore_msg_data->sim_id);
            //srv_sms_set_data_port(sms_handle, backup_restore_msg_data->src_port, backup_restore_msg_data->dest_port);
            srv_sms_set_vp(sms_handle, (srv_sms_vp_enum)backup_restore_msg_data->vp);
            srv_sms_set_pid(sms_handle, (srv_sms_pid_enum)backup_restore_msg_data->pid);
            srv_sms_set_sc_address(sms_handle, backup_restore_msg_data->sc_address);


            
            srv_sms_set_storage_type(sms_handle,SRV_SMS_STORAGE_ME);
            srv_sms_set_content(sms_handle, cloud_sms_data->content, cloud_sms_data->content_buf_len);//check this buff size
            srv_sms_set_content_dcs(sms_handle, (srv_sms_dcs_enum)backup_restore_msg_data->dcs);
            
            srv_sms_set_reply_path(sms_handle, (MMI_BOOL)backup_restore_msg_data->reply_path);
            number_buf = (char*)cloud_sms_data->number;
			for(i = 0; i < SRV_SMS_MAX_ADDR_LEN; i++)
			{
				if(number_buf[i] == ';')
				{
					break;
				}
			}
            memset(ucs2_addr, 0,SRV_SMS_MAX_ADDR_LEN+1);
            mmi_asc_n_to_ucs2((S8*)ucs2_addr, (S8*)cloud_sms_data->number, i);
            srv_sms_set_address(sms_handle, ucs2_addr);//check the number dcs
            ext_addr_start = i + 1;
            mmi_dt_utc_sec_2_mytime(cloud_sms_data->date,&timestamp,MMI_FALSE);
            srv_sms_set_save_timestamp(sms_handle, &timestamp);
        #ifdef __SRV_SMS_MULTI_ADDR__
        
            if( backup_restore_msg_data->ext_number_num > 1) 
            {
                CHAR *temp_addr_list;
                S32 j;
                //memset(append_ucs2_addr, 0x00, (SRV_SMS_MAX_ADDR_LEN+1)*ENCODING_LENGTH);
            
                if (backup_restore_msg_data->ext_number_num > SRV_SMS_MAX_CLOUD_RECIPIENTS_NUM)
                {
                    backup_restore_msg_data->ext_number_num = SRV_SMS_MAX_CLOUD_RECIPIENTS_NUM;
                }
                temp_addr_list = ((CHAR*)cloud_sms_data->number)+ ext_addr_start;
                
                for (i = 0; i < backup_restore_msg_data->ext_number_num - 1; i++)
                {
                    //U16 addr_len;
                    
                    for (j = 0; j < SRV_SMS_MAX_ADDR_LEN; j++)
                    {
                        if (temp_addr_list[j] == ';')
                        {
                            break;
                        }
                    }
                    mmi_asc_n_to_ucs2((S8*)append_ucs2_addr, (S8*)temp_addr_list, j);
                    append_ucs2_addr[j] = 0;
                    srv_sms_append_address(sms_handle, append_ucs2_addr, SRV_SMS_STATUS_SENT);//need to check
                    temp_addr_list += (j + 1);
                    //memset(append_ucs2_addr, 0x00, (SRV_SMS_MAX_ADDR_LEN+1)*ENCODING_LENGTH);
                }
            }
            
        #endif
                               
            srv_sms_save_msg(
                sms_handle, 
                srv_sms_begin_restore_sms_callback,
                NULL);

        }
    }
    OslMfree(cloud_sms_data); 
}

/*****************************************************************************
* FUNCTION
*  srv_sms_backup_msg
* DESCRIPTION
*  to backup sms
* PARAMETERS
*  backup_restore_info: [in] the dest and the account info
*  callback: [in] callback
*  user_data: [in] user_data
* RETURNS
*  MMI_BOOL
*****************************************************************************/

mmi_ret srv_sms_backup_restore_event_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //srv_cloud_status_struct *ev_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BACKUP_RESTORE_EVENT_HDLR, evt->evt_id, in_cloud_action);
    switch (evt->evt_id)
    {
         /*TO put data*/
        case EVT_ID_SRV_CLD_PUT_DATA_RES_IND:
        {
             srv_cloud_put_data_result_evt_struct *put_data_evt;
             put_data_evt = (srv_cloud_put_data_result_evt_struct*)evt;
             if(put_data_evt->type == SRV_CLD_TYPE_SMS)
             {
                 srv_sms_copy_to_cloud_service(&backup_cntx);
             }
             break;
        }
           
        case EVT_ID_SRV_CLD_BACKUP_BEGIN_IND:
        {
            srv_cloud_post_backup_begin_evt_struct *begin_evt;
            begin_evt = (srv_cloud_post_backup_begin_evt_struct*)evt;
            if(begin_evt->type == SRV_CLD_TYPE_SMS)
            {
                srv_sms_copy_to_cloud_service(&backup_cntx);
            }
            break;
        }
        case EVT_ID_SRV_CLD_ASYNC_UID_DONE_IND:
        {
            srv_cloud_post_async_done_evt_struct *event;
            event = (srv_cloud_post_async_done_evt_struct*)evt;
            if (event->type == SRV_CLD_TYPE_SMS)
            {
                srv_sms_begin_to_set_operate();
            }
            break;
        }
        case EVT_ID_SRV_CLD_GET_DATA_IND:
        {
            srv_cloud_get_data_ind_evt_struct *get_data_ind =
                (srv_cloud_get_data_ind_evt_struct*)evt;
            if (get_data_ind->type == SRV_CLD_TYPE_SMS)
            {
                
                if (!get_data_ind->over_flag)
                {
                    have_data_sync = MMI_TRUE;
                    restore_cntx.more_data ++;
                }
    
                /*if handle one sms, the cloud have another sms,just continue handle the curr one*/
                if (!get_data_ind->over_flag &&
                    restore_cntx.more_data >= 1)
                {
                    have_data_sync = MMI_TRUE;
                    srv_sms_begin_restore_sms();
                }
                else if (restore_cntx.more_data == 0)
                {
                    restore_cntx.result = MMI_TRUE;
                    srv_cloud_close(restore_cntx.handle);
                }
            }
            
            break;
        }
        case EVT_ID_SRV_CLD_ERROR_IND:
        {
            srv_cloud_error_evt_struct *error_ind;

            error_ind = (srv_cloud_error_evt_struct*)evt;
            if(error_ind->type == SRV_CLD_TYPE_SMS)
            {
                if(in_cloud_action == SRV_SMS_CLOUD_ACTION_BACKUP)
                {
                    backup_cntx.result = MMI_FALSE;
                    backup_cntx.error_cause = error_ind->error_type;
                    srv_cloud_close(backup_cntx.handle);
                }
                else
                {
                    if(in_cloud_action == SRV_SMS_CLOUD_ACTION_RESTORE)
                    {
                        restore_cntx.result = MMI_FALSE;
                        restore_cntx.error_cause = error_ind->error_type;
                        srv_cloud_close(restore_cntx.handle);
                    }
                    
                }
            }
            
            break;
        }   
        case EVT_ID_SRV_CLD_CLOSE_DONE_IND:
        {
            //add trace
            srv_cloud_post_close_done_struct *close_evt;
            close_evt = (srv_cloud_post_close_done_struct*)evt;
            if(close_evt->type == SRV_CLD_TYPE_SMS)
            {
                if(in_cloud_action == SRV_SMS_CLOUD_ACTION_BACKUP)
                {
                    if(!have_data_sync && backup_cntx.result && !is_abort)
                    {
                        backup_cntx.result = MMI_FALSE;
                        backup_cntx.error_cause = SRV_SMS_CAUSE_CLOUD_NO_NEED_SYNC;
                    }
                    srv_sms_cntx_callback(              
                                &backup_cntx,
                                backup_cntx.result,
                                (srv_sms_cause_enum)backup_cntx.error_cause,
                                NULL);
                }
                else
                {
                    if(in_cloud_action == SRV_SMS_CLOUD_ACTION_RESTORE)
                    {
                        srv_sms_event_refresh_struct event_info;
                        if(!have_data_sync && restore_cntx.result)
                        {
                            restore_cntx.result = MMI_FALSE;
                            restore_cntx.error_cause = SRV_SMS_CAUSE_CLOUD_NO_NEED_SYNC;
                        }
                        srv_sms_cntx_callback(              
                                    &restore_cntx,
                                    restore_cntx.result,
                                    (srv_sms_cause_enum)restore_cntx.error_cause,
                                    NULL);
                        
                        srv_sms_emit_event(EVT_ID_SRV_SMS_REFRESH_MSG,&event_info);
                    }                 
                }
                in_cloud_action = SRV_SMS_CLOUD_ACTION_NONE;
				is_abort = MMI_FALSE;
            }
            
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_backup_msg
 * DESCRIPTION
 *  to backup sms
 * PARAMETERS
 *  backup_restore_info: [in] the dest and the account info
 *  callback: [in] callback
 *  user_data: [in] user_data
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
SMS_HANDLE srv_sms_backup_msg (
                srv_sms_backup_restore_info_struct backup_restore_info,
                SrvSmsCallbackFunc callback_func,
                void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 handle;
    S32 setopt_result;
    S32 operate_result = SRV_CLD_ERROR;

    srv_cloud_opt_struct opt;
    U16 local_msg_list_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	is_abort = MMI_FALSE;
    memset(&backup_cntx, 0, sizeof(srv_sms_backup_cntx_struct));
    have_data_sync = MMI_FALSE;
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BACKUP_MSG_0, in_cloud_action);
    if(in_cloud_action != SRV_SMS_CLOUD_ACTION_NONE)
    {
        srv_sms_async_callback(
                SRV_SMS_ACTION_BACKUP,
                MMI_FALSE,
                SRV_SMS_CAUSE_CLOUD_BUSY,   /*it shoud be cloud busy*/
                NULL,
                0,
                user_data,
                callback_func);
        
        return &backup_cntx;
    }
    else
    {
        S32 result;
        U16 inbox_size;
        U16 outbox_size;
        U16 *temp_list;
        srv_sms_get_list_and_size(&temp_list, &inbox_size, SRV_SMS_BOX_INBOX);
        srv_sms_get_list_and_size(&temp_list, &outbox_size, SRV_SMS_BOX_OUTBOX);
        memset(uid_index, 0XFF,SRV_SMS_MAX_ME_SMS_ENTRY*2);
        local_msg_list_size = srv_sms_get_backup_restore_index_list(uid_index);
        in_cloud_action = SRV_SMS_CLOUD_ACTION_BACKUP;
        backup_cntx.action = SRV_SMS_ACTION_BACKUP;
        if(local_msg_list_size == 0)
        {
            in_cloud_action = SRV_SMS_CLOUD_ACTION_NONE;
            srv_sms_async_callback(
                SRV_SMS_ACTION_BACKUP,
                MMI_FALSE,
                SRV_SMS_CAUSE_CLOUD_NO_NEED_SYNC,   /*it shoud be cloud busy*/
                NULL,
                0,
                user_data,
                callback_func);
            return &backup_cntx;
        }
        
        
        handle = srv_cloud_create(SRV_CLD_TYPE_SMS);
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BACKUP_MSG_1, handle);
        if(handle > 0)
        {
            backup_cntx.handle = handle;
            backup_cntx.callback_func = callback_func;
            backup_cntx.user_data = user_data;
            opt.data_type = SRV_CLD_DT_RECORD;
            opt.acct = *(backup_restore_info.account_info);
            setopt_result = srv_cloud_setopt(handle, &opt);
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BACKUP_MSG_2, setopt_result);
            if(setopt_result == SRV_CLD_SUCCESS)
            {
                result = srv_cloud_async_set_store_uid(
                                     uid_index, 
                                     local_msg_list_size, 
                                     SRV_CLD_TYPE_SMS,
                                     SRV_CLD_ACTION_ADD);
                
     
                if(result == SRV_CLD_ERROR)
                {
                    backup_cntx.result = MMI_FALSE;
                    backup_cntx.error_cause = operate_result;
                    srv_cloud_close(backup_cntx.handle);
                }
                else
                {
                    memset(msg_index, 0xFFFF, SRV_SMS_MAX_ME_SMS_ENTRY);
                    backup_cntx.msg_list_size = srv_sms_get_backup_restore_msg_list(msg_index);
                    backup_cntx.msg_id_list = msg_index;
                    //backup_cntx.msg_list_size = srv_sms_get_backup_restore_msg_list(backup_cntx.msg_id_list);
                    backup_cntx.curr_index = 0;
                    backup_cntx.total_index = backup_cntx.msg_list_size;
                }
               
            }
            else
            {
                //add trace
                backup_cntx.result = MMI_FALSE;
                backup_cntx.error_cause = setopt_result;
                srv_cloud_close(backup_cntx.handle);
            }
        }
        else
        {
            in_cloud_action = SRV_SMS_CLOUD_ACTION_NONE;
            srv_sms_async_callback(
                SRV_SMS_ACTION_BACKUP,
                MMI_FALSE,
                SRV_SMS_CAUSE_CLOUD_BUSY,   /*it shoud be cloud busy*/
                NULL,
                0,
                user_data,
                callback_func);
        }
        return &backup_cntx;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_restore_msg
 * DESCRIPTION
 *  to backup sms
 * PARAMETERS
 *  backup_restore_info: [in] the dest and the account info
 *  callback: [in] callback
 *  user_data: [in] user_data
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern SMS_HANDLE srv_sms_restore_msg (
                         srv_sms_backup_restore_info_struct backup_restore_info,
                         SrvSmsCallbackFunc callback,
                         void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 handle;
    S32 setopt_result;
    S32 operate_result = SRV_CLD_ERROR;
    srv_cloud_opt_struct opt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_RESTORE_MSG_0, in_cloud_action);
    have_data_sync = MMI_FALSE;
	is_abort = MMI_FALSE;
    memset(&restore_cntx, 0, sizeof(srv_sms_backup_cntx_struct));
    if(in_cloud_action != SRV_SMS_CLOUD_ACTION_NONE)
    {
        srv_sms_async_callback(
                SRV_SMS_ACTION_BACKUP,
                MMI_FALSE,
                SRV_SMS_CAUSE_CLOUD_BUSY,   /*it shoud be cloud busy*/
                NULL,
                0,
                user_data,
                callback);
        return &restore_cntx;
    }
    else
    {

        S32 set_uid_ret;
        /*provide msg index to backup/restore service*/
        
        U16 uid_num = 0;
        memset(uid_index, 0, SRV_SMS_MAX_ME_SMS_ENTRY);
        uid_num = srv_sms_get_backup_restore_index_list(uid_index);

        in_cloud_action = SRV_SMS_CLOUD_ACTION_RESTORE;
        restore_cntx.action = SRV_SMS_ACTION_RESTORE;
        handle = srv_cloud_create(SRV_CLD_TYPE_SMS);    
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_RESTORE_MSG_1, handle);
        if(handle > 0)
        {
            restore_cntx.handle = handle;
            restore_cntx.callback_func = callback;
            restore_cntx.user_data = user_data;
            
            opt.data_type = SRV_CLD_DT_RECORD;
            opt.acct = *(backup_restore_info.account_info);
            setopt_result = srv_cloud_setopt(handle, &opt);
            
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_RESTORE_MSG_2, setopt_result);
            if(setopt_result == SRV_CLD_SUCCESS)
            {
                set_uid_ret = srv_cloud_async_set_store_uid(
                                 uid_index, 
                                 uid_num, 
                                 SRV_CLD_TYPE_SMS,
                                 SRV_CLD_ACTION_ADD);

                
                if(set_uid_ret == SRV_CLD_ERROR)
                {
                    restore_cntx.result = MMI_FALSE;
                    restore_cntx.error_cause = operate_result;
                    srv_cloud_close(restore_cntx.handle);
                }
            }
            else
            {
                restore_cntx.result = MMI_FALSE;
                restore_cntx.error_cause = setopt_result;
                srv_cloud_close(restore_cntx.handle);
            }
        }
        else
        {
            in_cloud_action = SRV_SMS_CLOUD_ACTION_NONE;
            srv_sms_async_callback(
                SRV_SMS_ACTION_RESTORE,
                MMI_FALSE,
                SRV_SMS_CAUSE_CLOUD_BUSY,
                NULL,
                0,
                user_data,
                callback);
        }

        return &restore_cntx;
    }
}


void srv_sms_abort_cloud(
                SMS_HANDLE handle,
                SrvSmsCallbackFunc callback_func,
                void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ABORT_CLODE, handle);
    if ((handle != SRV_SMS_INVALID_HANDLE) && 
        (handle != SRV_SMS_RESERVED_HANDLE))
    {

        //srv_sms_handle_struct *cntx;
        if(in_cloud_action != SRV_SMS_CLOUD_ACTION_NONE)
        {
            is_abort = MMI_TRUE;
            if(in_cloud_action == SRV_SMS_CLOUD_ACTION_BACKUP)
            {
                backup_cntx.result = MMI_TRUE;
                backup_cntx.error_cause = SRV_SMS_CAUSE_ABORT;
                srv_cloud_close(backup_cntx.handle);
                //cntx = backup_cntx.sms_hdlr;
            }
            else
            {
                if(in_cloud_action == SRV_SMS_CLOUD_ACTION_RESTORE)
                {
                    restore_cntx.result = MMI_TRUE;
                    restore_cntx.error_cause = SRV_SMS_CAUSE_ABORT;
                    srv_cloud_close(restore_cntx.handle);
                }
                //cntx = restore_cntx.sms_hdlr;
            }
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
        #endif
        }
        else
        {
            srv_sms_async_callback(
                SRV_SMS_ACTION_NONE,
                MMI_TRUE,
                SRV_SMS_CAUSE_NO_ERROR,
                NULL,
                0,
                user_data,
                callback_func);
        }  
    }
    else
    {
        srv_sms_async_callback(
            SRV_SMS_ACTION_NONE,
            MMI_TRUE,
            SRV_SMS_CAUSE_NO_ERROR,
            NULL,
            0,
            user_data,
            callback_func);
    }
}




#endif
//#endif/*__MOD_SMSAL__*/

