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
 *  SmsStorageManagerSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Storage Manager core codes
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *============================================================================
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "custom_mmi_default_value.h"
#include "ps_public_enum.h"
#include "stack_config.h"
#include "customer_ps_inc.h"
#include "nvram_common_defs.h"
#include "Fs_gprot.h"
#include "TcardSrvGprot.h"
#include "SmsProtSrv.h"
#include "SmsStorageSrv.h"
#include "SmsStorageTcardSrv.h"
#include "SmsStorageCoreSrv.h"
#include "SmsUtilSrv.h"









/**************************************************************
* MARCO
**************************************************************/



/**************************************************************
* Structure Declaration
**************************************************************/
typedef enum
{
    SRV_SMS_TCARD_INIT_OP_NONE = 0, /* none */
    SRV_SMS_TCARD_INIT_OP_READ_SMS_INFO, 
    SRV_SMS_TCARD_INIT_OP_READ_SMS_PDU_INDEX,
#ifdef __SRV_SMS_MULTI_ADDR__
    SRV_SMS_TCARD_INIT_OP_READ_SMS_ADDR_INFO,
#endif
    SRV_SMS_TCARD_INIT_OP_READ_SMS_PDU,

    /*Add the app index in the end*/
    SRV_SMS_TCARD_INIT_OP_READ_SMS 
} srv_sms_tcard_init_op_enum;


typedef struct
{
    U16 curr_index;
    U16 total;
    U16 remain;
    srv_sms_tcard_init_op_enum op_type;
} sms_init_card_struct;


/**************************************************************
* Global Variables Declaration
**************************************************************/ 


/**************************************************************
* Extern Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
static srv_sms_tcard_msg_node_struct srv_sms_tcard_msg_list[SRV_SMS_MAX_TCARD_ENTRY];  
srv_sms_tcard_pdu_node_struct srv_sms_tcard_pdu_list[SRV_SMS_MAX_TCARD_ENTRY];

#ifdef __SRV_SMS_MULTI_ADDR__
srv_sms_tcard_addr_node_struct srv_sms_tcard_addr_list[SRV_SMS_MAX_TCARD_ADDR_ENTRY];
#endif /* __SRV_SMS_MULTI_ADDR__ */

/**************************************************************
* Static Function Declaration
**************************************************************/
static MMI_BOOL srv_sms_tcard_init(void);
static MMI_BOOL srv_sms_tcard_deinit(void); 

static MMI_BOOL srv_sms_tcard_set_mem_status(void);
static void srv_sms_tcard_read_msg_list(sms_init_card_struct *msg_list_ctnx);
static void srv_sms_tcard_read_pdu_list(sms_init_card_struct *pdu_list_ctnx);
static void srv_sms_tcard_read_msg_list_callback(srv_tcard_callback_struct *callback_data);
static void srv_sms_tcard_sort_msg_list(MMI_BOOL sort_flag);
static U32 srv_sms_tcard_get_insert_index(
                    MMI_BOOL sort_flag, 
                    U16 size, 
                    U16 *sort_list,
                    U32 timestamp);
    
static void srv_sms_tcard_insert_list(
                    U16 index, 
                    U16 *sort_list, 
                    U32 size, 
                    U16 msg_id);

static void srv_sms_tcard_init_check_list(void);



/**************************************************************
* Function Defination
**************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_sms_tcard_event_hdlr
 * DESCRIPTION
 *  handle the sms and tcard ready event
 * PARAMETERS
 *  evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/

static void srv_sms_tcard_init_check_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    MMI_BOOL is_valid;
    srv_sms_tcard_msg_node_struct *tcard_msg_list;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tcard_msg_list = srv_sms_get_tcard_msg_list();
    for (i = 0; i < SRV_SMS_MAX_TCARD_ENTRY; i++)
    {
        if(tcard_msg_list[i].status != SRV_SMS_STATUS_NONE)
        {
            is_valid = srv_sms_is_tcard_sms_valid(i);
            if(!is_valid)
            {
                
                tcard_msg_list[i].status = SRV_SMS_STATUS_NONE;
            }
        }              
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_tcard_event_hdlr
 * DESCRIPTION
 *  handle the sms and tcard ready event
 * PARAMETERS
 *  evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/

mmi_ret srv_sms_tcard_event_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_SMS_READY:
        {
            srv_sms_event_sms_ready_struct *event_info;
            event_info = (srv_sms_event_sms_ready_struct*)((srv_sms_event_struct*)evt)->event_info;
            if(event_info->is_sms_ready)
            {
                if(storage_cntx.is_tcard_ready)
                {
                    srv_sms_tcard_init();
                }
            }
            break;
        }

        case EVT_ID_SRV_TCARD_READY:
        {
            srv_tcard_event_tcard_ready_struct *event_info;
            event_info = (srv_tcard_event_tcard_ready_struct*)((srv_tcard_event_struct*)evt)->event_info;
            if(event_info->is_tcard_ready)
            {
                storage_cntx.is_tcard_ready = MMI_TRUE;
                storage_cntx.is_tsms_ready = MMI_TRUE;
            }
            else
            {
                storage_cntx.is_tcard_ready = MMI_FALSE;
                storage_cntx.is_tsms_ready = MMI_FALSE;
            }
            
            if(srv_sms_is_sms_ready())
            {
                if(storage_cntx.is_tcard_ready)
                {
                    srv_sms_tcard_init();
                } 
                else
                {
                   srv_sms_tcard_deinit(); 
                }
                
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
 *  srv_sms_tcard_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_tcard_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_init_card_struct *index_init_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index_init_cntx = OslMalloc(sizeof(sms_init_card_struct));
    index_init_cntx->op_type = SRV_SMS_TCARD_INIT_OP_READ_SMS_INFO;
    srv_sms_tcard_read_msg_list(index_init_cntx);
    return MMI_TRUE;
}


static MMI_BOOL srv_sms_tcard_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    MMI_BOOL result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_event_tsms_ready_struct ready_event_info;
    
    storage_cntx.is_tsms_ready = MMI_FALSE;
    ready_event_info.is_tsms_ready = MMI_FALSE;
    storage_cntx.memory_status.tcard_total = 0;
    storage_cntx.memory_status.tcard_used = 0;

    //modify the total list 
    for(i = 0; i < srv_sms_inbox_tcard_size ; i++)
    {
        
        result = srv_sms_delete_msg_from_list(
                        srv_sms_inbox_total_list,
                        srv_sms_inbox_total_size,
                        srv_sms_inbox_tcard_list[i]);
        if(result)
        {
            srv_sms_inbox_total_size --;
        }
        
    }

    for(i = 0; i < srv_sms_outbox_tcard_size ; i++)
    {
        result = srv_sms_delete_msg_from_list(
                        srv_sms_outbox_total_list,
                        srv_sms_outbox_total_size,
                        srv_sms_outbox_tcard_list[i]);
        if(result)
        {
            srv_sms_outbox_total_size --;
        }
        
    }

    for(i = 0; i < srv_sms_drafts_tcard_size ; i++)
    {
        result = srv_sms_delete_msg_from_list(
                        srv_sms_drafts_total_list,
                        srv_sms_drafts_total_size,
                        srv_sms_drafts_tcard_list[i]);
        if(result)
        {
            srv_sms_drafts_total_size --;
        }        
    }
#ifdef __SRV_SMS_UNSENT_LIST__
    for(i = 0; i < srv_sms_unsent_tcard_size ; i++)
    {
        result = srv_sms_delete_msg_from_list(
                        srv_sms_unsent_total_list,
                        srv_sms_unsent_total_size,
                        srv_sms_unsent_tcard_list[i]);
        if(result)
        {
            srv_sms_unsent_total_size --;
        }        
    }
#endif

    
    //clear the tcard list
    memset(srv_sms_inbox_tcard_list,0xff, SRV_SMS_MAX_TCARD_ENTRY * 2);
    srv_sms_inbox_tcard_size = 0;

    memset(srv_sms_outbox_tcard_list,0xff, SRV_SMS_MAX_TCARD_ENTRY * 2);
    srv_sms_outbox_tcard_size = 0;
    
    memset(srv_sms_drafts_tcard_list,0xff, SRV_SMS_MAX_TCARD_ENTRY * 2);
    srv_sms_drafts_tcard_size = 0;
    
#ifdef __SRV_SMS_UNSENT_LIST__
    memset(srv_sms_unsent_tcard_list,0xff, SRV_SMS_MAX_TCARD_ENTRY * 2);
    srv_sms_unsent_tcard_size = 0;
#endif


    srv_sms_set_show_list(SRV_SMS_BOX_INBOX);
    srv_sms_set_show_list(SRV_SMS_BOX_OUTBOX);
    srv_sms_set_show_list(SRV_SMS_BOX_DRAFTS);
#ifdef __SRV_SMS_UNSENT_LIST__
    srv_sms_set_show_list(SRV_SMS_BOX_UNSENT);
#endif
    srv_sms_emit_event(EVT_ID_SRV_TCARD_SMS_READY, &ready_event_info);
    srv_sms_handle_mem_change(MMI_TRUE);
    return MMI_TRUE;
}


static void srv_sms_tcard_read_msg_list(sms_init_card_struct *msg_list_ctnx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    CHAR *start_read_index = NULL;
    srv_tcard_op_struct read_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_MULTI_ADDR__
    if(msg_list_ctnx->op_type <= SRV_SMS_TCARD_INIT_OP_READ_SMS_ADDR_INFO)
#else
    if(msg_list_ctnx->op_type <= SRV_SMS_TCARD_INIT_OP_READ_SMS_PDU_INDEX)
#endif
    {  
        //read_cntx = OslMalloc(sizeof(sms_init_card_struct));//need to free
        switch(msg_list_ctnx->op_type)
        {
            case SRV_SMS_TCARD_INIT_OP_READ_SMS_INFO:
                start_read_index = (CHAR*)srv_sms_tcard_msg_list;
                read_cntx.record_num = SRV_SMS_MAX_TCARD_ENTRY;
                break;
            case SRV_SMS_TCARD_INIT_OP_READ_SMS_PDU_INDEX:
                start_read_index = (CHAR*)srv_sms_tcard_pdu_list;
                read_cntx.record_num = SRV_SMS_MAX_TCARD_ENTRY;
                break;
        #ifdef __SRV_SMS_MULTI_ADDR__
            case SRV_SMS_TCARD_INIT_OP_READ_SMS_ADDR_INFO:
                start_read_index = (CHAR*)srv_sms_tcard_addr_list;
                read_cntx.record_num = SRV_SMS_MAX_TCARD_ADDR_ENTRY;
                break;
        #endif
            default:
                ASSERT(0);
                break;
        }
        
        
        read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
        read_cntx.file_index = msg_list_ctnx->op_type;
        read_cntx.start_record_id = 0;       
        srv_tcard_read_record(
                &read_cntx, 
                start_read_index,
                srv_sms_tcard_read_msg_list_callback,
                msg_list_ctnx);
    }
}

static void srv_sms_tcard_read_msg_list_callback(srv_tcard_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    CHAR *start_read_index;

    sms_init_card_struct *list_ctnx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_ctnx = (sms_init_card_struct*)callback_data->user_data;
    
    if(callback_data->result >= 0)
    {
    #ifdef __SRV_SMS_MULTI_ADDR__
        if(list_ctnx->op_type == SRV_SMS_TCARD_INIT_OP_READ_SMS_ADDR_INFO)
    #else
        if(list_ctnx->op_type == SRV_SMS_TCARD_INIT_OP_READ_SMS_PDU_INDEX)
    #endif
        {
            srv_sms_event_tsms_ready_struct ready_event_info;
	    srv_sms_event_refresh_struct event_info;		
            S32 count =0;
	#ifdef __SRV_SMS_MULTI_ADDR__
	    for( i = 0; i < SRV_SMS_MAX_TCARD_ADDR_ENTRY; i++)
	    {
		 if(srv_sms_tcard_addr_list[i].status != SRV_SMS_STATUS_NONE)
		 {
		      count ++;
		 }
             }
			
             storage_cntx.unused_tcard_addr_num = SRV_SMS_MAX_TCARD_ADDR_ENTRY - count;
        #endif
	    /*check if the msg_list and pdu_list and addr list are valid*/
            srv_sms_tcard_init_check_list();
			
	    if(action_cntx.is_in_change)
            {
                srv_sms_tcard_msg_node_struct *tcard_msg_node;
                srv_tcard_op_struct read_cntx;
                tcard_msg_node = &srv_sms_tcard_msg_list[action_cntx.msg_id - SRV_SMS_MAX_MSG_NUM];
                if(tcard_msg_node->status != SRV_SMS_STATUS_NONE)
                {
                    tcard_msg_node->status = action_cntx.status;
                    
                    read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
                    read_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_INFO;
                    read_cntx.start_record_id = action_cntx.msg_id - SRV_SMS_MAX_MSG_NUM;
                    read_cntx.record_num = 1;
                    srv_tcard_sync_write_record(&read_cntx,(CHAR*)tcard_msg_node);
                }
            }
            for(i = 0; i < SRV_SMS_MAX_TCARD_ENTRY ; i ++)
            {
                if(srv_sms_tcard_msg_list[i].storage_type & SRV_SMS_HIDDEN_FLAG)
                {
                    srv_sms_tcard_msg_list[i].storage_type &= (~SRV_SMS_HIDDEN_FLAG);
                }
            #ifdef __SRV_SMS_MSG_EXT_STATUS__ 
                if(srv_sms_tcard_msg_list[i].status == SRV_SMS_STATUS_UNSENT)
                {                    
                    if(srv_sms_tcard_msg_list[i].ext_status != SRV_SMS_SEND_SUCCESS)
                    {
                        srv_sms_tcard_msg_list[i].ext_status = SRV_SMS_SEND_FAIL;
                    }
                }
            #endif
            }
            srv_sms_tcard_sort_msg_list(MMI_TRUE);
            storage_cntx.is_tsms_ready = MMI_TRUE;
            ready_event_info.is_tsms_ready = MMI_TRUE;
            srv_sms_tcard_set_mem_status();
            srv_sms_set_show_list(SRV_SMS_BOX_INBOX);
            srv_sms_set_show_list(SRV_SMS_BOX_OUTBOX);
            srv_sms_set_show_list(SRV_SMS_BOX_DRAFTS);
        #ifdef __SRV_SMS_UNSENT_LIST__
            srv_sms_set_show_list(SRV_SMS_BOX_UNSENT);
        #endif
            srv_sms_emit_event(EVT_ID_SRV_TCARD_SMS_READY, &ready_event_info);
            srv_sms_emit_event(EVT_ID_SRV_SMS_REFRESH_MSG, &event_info);
            srv_sms_handle_mem_change(MMI_TRUE);
        }
        else
        {
        #ifdef __SRV_SMS_MULTI_ADDR__
            if(list_ctnx->op_type < SRV_SMS_TCARD_INIT_OP_READ_SMS_ADDR_INFO)
        #else
            if(list_ctnx->op_type < SRV_SMS_TCARD_INIT_OP_READ_SMS_PDU_INDEX)
        #endif
            {
                list_ctnx->op_type ++;               
                srv_sms_tcard_read_msg_list(list_ctnx);
            }   
        }
    }
    else
    {
        
        srv_sms_event_tsms_ready_struct ready_event_info;
		OslMfree(list_ctnx);
        storage_cntx.is_tsms_ready = MMI_FALSE;
        ready_event_info.is_tsms_ready = MMI_FALSE;
        srv_sms_tcard_deinit();
		
        srv_sms_emit_event(EVT_ID_SRV_TCARD_SMS_READY, &ready_event_info);
        
    }
}
    


static void srv_sms_tcard_sort_msg_list(MMI_BOOL sort_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U16 *size;
    U16 msg_id;
    srv_sms_tcard_msg_node_struct *sort_list;
    U16 *total_sort_list;
    U16 *tcard_sort_list;
    U32 timestamp;
    U32 insert_index;
    srv_sms_box_enum msg_box_type = SRV_SMS_BOX_NONE;
    srv_sms_status_enum temp_status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sort_list = srv_sms_tcard_msg_list;
    for (i = 0; i < SRV_SMS_MAX_TCARD_ENTRY; i++)
    {
        temp_status = (srv_sms_status_enum)(sort_list[i].status & (~SRV_SMS_STATUS_UNSUPPORTED));
        if (temp_status != SRV_SMS_STATUS_NONE)
        {
            switch(temp_status)
            {
                case SRV_SMS_STATUS_UNREAD:
                case SRV_SMS_STATUS_READ:
                    msg_box_type = SRV_SMS_BOX_INBOX;
                    //size = srv_sms_inbox_total_size - 1;
                    //temp_sort_list = srv_sms_inbox_total_list;
                    break;
                case SRV_SMS_STATUS_SENT:
                    msg_box_type = SRV_SMS_BOX_OUTBOX;
                    //size = srv_sms_outbox_total_size - 1;
                    //temp_sort_list = srv_sms_outbox_total_list;
                    break;
                case SRV_SMS_STATUS_UNSENT:
                    msg_box_type = SRV_SMS_BOX_UNSENT;
                    //size = srv_sms_unsent_total_size - 1;
                    //temp_sort_list = srv_sms_unsent_total_list;
                    break;
                case SRV_SMS_STATUS_DRAFT:
                    //size = srv_sms_drafts_total_size - 1;
                    //temp_sort_list = srv_sms_drafts_total_list;
                    msg_box_type = SRV_SMS_BOX_DRAFTS;
                    break;
                default:
                    break;
                
                    
            }
            srv_sms_get_total_list_and_size(&total_sort_list, &size, msg_box_type);
            timestamp = sort_list[i].timestamp;
            msg_id = i + SRV_SMS_MAX_MSG_NUM;
            insert_index = srv_sms_tcard_get_insert_index(
                                sort_flag, 
                                *size, 
                                total_sort_list,
                                timestamp);
            srv_sms_tcard_insert_list(
                        insert_index,
                        total_sort_list,
                        *size,
                        msg_id);

            srv_sms_get_tcard_list_and_size(&tcard_sort_list, &size, msg_box_type);

            insert_index = srv_sms_tcard_get_insert_index(
                                sort_flag, 
                                *size, 
                                tcard_sort_list,
                                timestamp);
            srv_sms_tcard_insert_list(
                        insert_index,
                        tcard_sort_list,
                        *size,
                        msg_id);
            
            switch (msg_box_type)
            {
                case SRV_SMS_BOX_INBOX:
                    srv_sms_inbox_total_size++;
                    
                    srv_sms_inbox_tcard_size++;
     
                    break;

                case SRV_SMS_BOX_OUTBOX:
                    srv_sms_outbox_total_size++;
       
                    srv_sms_outbox_tcard_size++;

                    break;

                case SRV_SMS_BOX_DRAFTS:
                    srv_sms_drafts_total_size++;
             
                        srv_sms_drafts_tcard_size++;

                    break;

            #ifdef __SRV_SMS_UNSENT_LIST__
                case SRV_SMS_BOX_UNSENT:
                    srv_sms_unsent_total_size++;
    
                    srv_sms_unsent_tcard_size++;
   
                    break;
            #endif /* __SRV_SMS_UNSENT_LIST__ */


                default:
                    break;
            }
            
        }
    }
}


static U32 srv_sms_tcard_get_insert_index(
                MMI_BOOL sort_flag, 
                U16 size, 
                U16 *sort_list,
                U32 timestamp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_sms_tcard_msg_node_struct *msg_sort_list;
    //U32 temp_timestamp;
    //U32 left;
    //U32 right;
    //U32 mid;
    //U16 *sort_list;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_sort_list = srv_sms_tcard_msg_list;
    if (size == 0)
    {
        return size;
    }
    for(i = 0; i < size ; i++)
    {
        if(timestamp >= msg_sort_list[sort_list[i]].timestamp )
        {
            break;
        }
    }
    
    return i;     

}


static void srv_sms_tcard_insert_list(U16 index, U16 *sort_list, U32 size, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(index == (size + 1))
    {
        sort_list[size] = msg_id;
    }
    else
    {
        for(i = size; i >= index; i--)
        {
            sort_list[i] = sort_list[i-1];
        }
        
        sort_list[index] = msg_id;
    }
    
}


MMI_BOOL srv_sms_tsms_is_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return storage_cntx.is_tsms_ready;
}


srv_sms_tcard_msg_node_struct * srv_sms_get_tcard_msg_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_sms_tcard_msg_list;
}

static MMI_BOOL srv_sms_tcard_set_mem_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 temp_count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    storage_cntx.memory_status.tcard_total = SRV_SMS_MAX_TCARD_ENTRY;
    for (i = 0; i < SRV_SMS_MAX_TCARD_ENTRY; i++)
    {
        if(srv_sms_tcard_pdu_list[i].status != SRV_SMS_STATUS_NONE)
        {
            temp_count++;
        }
    }
    storage_cntx.memory_status.tcard_used = temp_count;   
}



void srv_sms_tcard_add_msg_list(
                    MMI_BOOL sort_flag, 
                    U16 msg_id,
                    srv_sms_box_enum msg_box_type)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *total_sort_list;
    U16 *tcard_sort_list;
    U16 *show_sort_list;
    U32 timestamp;
    U32 insert_index;
    U16 *size;
    srv_sms_storage_enum storage_type;
    srv_sms_filter_enum storage_filter;
    MMI_BOOL need_add = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    storage_filter = srv_sms_get_storage_filter();
    if(storage_filter & SRV_SMS_STORAGE_TCARD && !storage_cntx.is_tcard_ready)
    {
        storage_filter = storage_filter & (~(SRV_SMS_FILTER_TCARD));
    }
    kal_prompt_trace(MOD_MMI,"[SMS][TCARD] srv_sms_tcard_add_msg_list,filter = %d",storage_filter);
    if (msg_id >= SRV_SMS_MAX_MSG_NUM)
    {
        srv_sms_tcard_msg_node_struct *tcard_msg_node;
        tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
        timestamp = tcard_msg_node->timestamp; 
        storage_type = tcard_msg_node->storage_type;
    }
    else
    {
        srv_sms_msg_node_struct *msg_node;
        msg_node = srv_sms_get_msg_node(msg_id);
        timestamp = msg_node->timestamp; 
        storage_type = msg_node->storage_type;
    }
    kal_prompt_trace(MOD_MMI,"srv_sms_tcard_add_msg_list storage_filter = %d",storage_filter);
    switch (storage_filter)
    {
        case SRV_SMS_FILTER_ME:
            if(storage_type == SRV_SMS_STORAGE_ME)
            {
                need_add = MMI_TRUE;
            }
            break;
        case SRV_SMS_FILTER_SIM:
            if(storage_type == SRV_SMS_STORAGE_SIM)
            {
            #ifndef __SRV_SMS_SIMBOX_SUPPORT__
                need_add = MMI_TRUE;
			#endif
            }

            break;
        case SRV_SMS_FILTER_TCARD:
            if(storage_type == SRV_SMS_STORAGE_TCARD)
            {
                need_add = MMI_TRUE;
            }
            break;
        case SRV_SMS_FILTER_ME | SRV_SMS_FILTER_SIM:
            if(storage_type == SRV_SMS_STORAGE_ME)
            {
                need_add = MMI_TRUE;
            }
			else
			{
		#ifndef __SRV_SMS_SIMBOX_SUPPORT__
		        if(storage_type == SRV_SMS_STORAGE_SIM)
		        {
		            need_add = MMI_TRUE;
		        }
		        
		#endif
			}

            break;
        case SRV_SMS_FILTER_ME | SRV_SMS_FILTER_TCARD:
            if((storage_type == SRV_SMS_STORAGE_ME)||(storage_type == SRV_SMS_STORAGE_TCARD))
            {
                need_add = MMI_TRUE;
            }                        
            break;
        case SRV_SMS_FILTER_SIM | SRV_SMS_FILTER_TCARD:
            if(storage_type == SRV_SMS_STORAGE_TCARD)
            {
                need_add = MMI_TRUE;
            }
			else
			{
			   if(storage_type == SRV_SMS_STORAGE_SIM)
			   {
			#ifndef __SRV_SMS_SIMBOX_SUPPORT__
			       need_add = MMI_TRUE;
			#endif
			   }
			}
            break;
        case SRV_SMS_FILTER_ALL:
			if(storage_type == SRV_SMS_STORAGE_SIM)
			{
		    #ifndef __SRV_SMS_SIMBOX_SUPPORT__
			       need_add = MMI_TRUE;
			#endif
			
			}
			else
			{
				need_add = MMI_TRUE;
			}
            
            break;
        default:
            ASSERT(0);
            break;
            
    }
#ifdef __SRV_SMS_SIMBOX_SUPPORT__
    if (storage_type != SRV_SMS_STORAGE_SIM)
    {
        srv_sms_get_total_list_and_size(&total_sort_list, &size, msg_box_type);
    
        insert_index = srv_sms_tcard_get_insert_index(
                            sort_flag, 
                            *size, 
                            total_sort_list,
                            timestamp);
        srv_sms_tcard_insert_list(
                    insert_index,
                    total_sort_list,
                    *size,
                    msg_id);
    }
#else
    srv_sms_get_total_list_and_size(&total_sort_list, &size, msg_box_type);
    
    insert_index = srv_sms_tcard_get_insert_index(
                        sort_flag, 
                        *size, 
                        total_sort_list,
                        timestamp);
    srv_sms_tcard_insert_list(
                insert_index,
                total_sort_list,
                *size,
                msg_id);
#endif
    
    
    
    if(msg_id >= SRV_SMS_MAX_MSG_NUM && storage_cntx.is_tsms_ready)
    {
        srv_sms_get_tcard_list_and_size(&tcard_sort_list, &size, msg_box_type);

        insert_index = srv_sms_tcard_get_insert_index(
                            sort_flag, 
                            *size, 
                            tcard_sort_list,
                            timestamp);
        srv_sms_tcard_insert_list(
                    insert_index,
                    tcard_sort_list,
                    *size,
                    msg_id);
    }
    
    if(need_add)
    {
        srv_sms_get_show_list_and_size(&show_sort_list, &size, msg_box_type);
        insert_index = srv_sms_tcard_get_insert_index(
                    sort_flag, 
                    *size, 
                    show_sort_list,
                    timestamp);
        srv_sms_tcard_insert_list(
                insert_index,
                show_sort_list,
                *size,
                msg_id);
    }
    switch (msg_box_type)
    {
        case SRV_SMS_BOX_INBOX:
            srv_sms_inbox_total_size++;
            if(msg_id >= SRV_SMS_MAX_MSG_NUM)
            {
                srv_sms_inbox_tcard_size++;
            }
            if(need_add)
            {
                srv_sms_inbox_show_size ++;
            }
            break;

        case SRV_SMS_BOX_OUTBOX:
            srv_sms_outbox_total_size++;
            if(msg_id >= SRV_SMS_MAX_MSG_NUM)
            {
                srv_sms_outbox_tcard_size++;
            }
            if(need_add)
            {
                srv_sms_outbox_show_size ++;
            }
            break;

        case SRV_SMS_BOX_DRAFTS:
            srv_sms_drafts_total_size++;
            if(msg_id >= SRV_SMS_MAX_MSG_NUM)
            {
                srv_sms_drafts_tcard_size++;
            }
            if(need_add)
            {
                srv_sms_drafts_show_size ++;
            }
            break;

    #ifdef __SRV_SMS_UNSENT_LIST__
        case SRV_SMS_BOX_UNSENT:
            srv_sms_unsent_total_size++;
            if(msg_id >= SRV_SMS_MAX_MSG_NUM)
            {
                srv_sms_unsent_tcard_size++;
            }
            if(need_add)
            {
                srv_sms_unsent_show_size ++;
            }
            break;
    #endif /* __SRV_SMS_UNSENT_LIST__ */
#if 0
    #ifdef __SRV_SMS_SIMBOX_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __SRV_SMS_SIMBOX_SUPPORT__ */
/* under construction !*/
    #ifdef __SRV_SMS_ARCHIVE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __SRV_SMS_ARCHIVE__ */
/* under construction !*/
#endif
        default:
            break;
    }
    
    if (msg_id >= SRV_SMS_MAX_MSG_NUM)
    {
         #ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
            if (msg_box_type == SRV_SMS_BOX_UNSENT)
            {                
                srv_sms_set_unsent_msg_status(msg_id, SRV_SMS_SEND_FAIL);
            }
        #endif /* __SRV_SMS_BACKGROUND_SEND_SUPPORT__ */
    }
}

void srv_sms_tcard_delete_msg_list(U16 msg_id ,srv_sms_box_enum msg_box_type)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *total_sort_list = NULL;
    U16 *tcard_sort_list = NULL;
    U32 timestamp;
    U32 insert_index;
    U16 *size;
    srv_sms_filter_enum storage_filter;
    MMI_BOOL need_delete = MMI_FALSE;
    MMI_BOOL total_ret = MMI_FALSE;
    MMI_BOOL tcard_ret = MMI_FALSE;
    MMI_BOOL show_ret = MMI_FALSE;
    srv_sms_storage_enum storage_type;
    srv_sms_tcard_msg_node_struct *tcard_msg_node;
    srv_sms_msg_node_struct *msg_node;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(msg_id >= SRV_SMS_MAX_MSG_NUM)
    {
        tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
        storage_type = tcard_msg_node->storage_type;
    }
    else
    {
        msg_node = srv_sms_get_msg_node(msg_id);
        storage_type = msg_node->storage_type;
    }
    storage_filter = srv_sms_get_storage_filter();
    if(storage_filter & SRV_SMS_STORAGE_TCARD && !storage_cntx.is_tcard_ready)
    {
        storage_filter = storage_filter & (~(SRV_SMS_FILTER_TCARD));
    }
    kal_prompt_trace(MOD_MMI,"[SMS][TCARD] srv_sms_tcard_delete_msg_list,filter = %d",storage_filter);
    srv_sms_get_total_list_and_size(&total_sort_list, &size, msg_box_type);
    total_ret = srv_sms_delete_msg_from_list(
                        total_sort_list,
                        *size,
                        msg_id);
    switch (storage_filter)
    {
        case SRV_SMS_FILTER_ME:
            if(storage_type == SRV_SMS_STORAGE_ME)
            {
                need_delete = MMI_TRUE;
            }
            break;
        case SRV_SMS_FILTER_SIM:
            if(storage_type == SRV_SMS_STORAGE_SIM)
            {
                need_delete = MMI_TRUE;
            }
            
            break;
        case SRV_SMS_FILTER_TCARD:
            if(storage_type == SRV_SMS_STORAGE_TCARD)
            {
                need_delete = MMI_TRUE;
            }
            break;
        case SRV_SMS_FILTER_ME | SRV_SMS_FILTER_SIM:
            if((storage_type == SRV_SMS_STORAGE_ME)||(storage_type == SRV_SMS_STORAGE_SIM))
            {
                need_delete = MMI_TRUE;
            }
            
            break;
        case SRV_SMS_FILTER_ME | SRV_SMS_FILTER_TCARD:
            if((storage_type == SRV_SMS_STORAGE_ME)||(storage_type == SRV_SMS_STORAGE_TCARD))
            {
                need_delete = MMI_TRUE;
            }                        
            break;
        case SRV_SMS_FILTER_SIM | SRV_SMS_FILTER_TCARD:
            if((storage_type == SRV_SMS_STORAGE_SIM)||(storage_type == SRV_SMS_STORAGE_TCARD))
            {
                need_delete = MMI_TRUE;
            }                                 
            break;
        case SRV_SMS_FILTER_ALL:
            need_delete = MMI_TRUE;
            break;
        default:
            ASSERT(0);
            break;
            
    }
    
    if(msg_id >= SRV_SMS_MAX_MSG_NUM)
    {
        srv_sms_get_tcard_list_and_size(&tcard_sort_list, &size, msg_box_type);
        tcard_ret = srv_sms_delete_msg_from_list(
                        tcard_sort_list,
                        *size,
                        msg_id);
    }

    if(need_delete)
    {
        srv_sms_get_show_list_and_size(&tcard_sort_list, &size, msg_box_type);
        show_ret = srv_sms_delete_msg_from_list(
                        tcard_sort_list,
                        *size,
                        msg_id);
        
    }
    switch (msg_box_type)
    {
        case SRV_SMS_BOX_INBOX:
            if(total_ret)
            {
                srv_sms_inbox_total_size--;
            }
            
            if(msg_id >= SRV_SMS_MAX_MSG_NUM && tcard_ret)
            {
                srv_sms_inbox_tcard_size--;
            }
            if(need_delete && show_ret)
            {
                srv_sms_inbox_show_size--;
            }
            break;

        case SRV_SMS_BOX_OUTBOX:
            if(total_ret)
            {
               srv_sms_outbox_total_size--;
            }
            
            if(msg_id >= SRV_SMS_MAX_MSG_NUM && tcard_ret)
            {
                srv_sms_outbox_tcard_size--;
            }
            if(need_delete && show_ret)
            {
                srv_sms_outbox_show_size--;
            }
            break;

        case SRV_SMS_BOX_DRAFTS:
            if(total_ret)
            {
                srv_sms_drafts_total_size--;
            }
            
            if(msg_id >= SRV_SMS_MAX_MSG_NUM && tcard_ret)
            {
                srv_sms_drafts_tcard_size--;
            }
            if(need_delete && show_ret)
            {
                srv_sms_drafts_show_size--;
            }
            break;

    #ifdef __SRV_SMS_UNSENT_LIST__
        case SRV_SMS_BOX_UNSENT:
            if(total_ret)
            {
                srv_sms_unsent_total_size--;
            }
            
            if(msg_id >= SRV_SMS_MAX_MSG_NUM && tcard_ret)
            {
                srv_sms_unsent_tcard_size--;
            }
            if(need_delete && show_ret)
            {
                srv_sms_unsent_show_size--;
            }
            break;
    #endif /* __SRV_SMS_UNSENT_LIST__ */
    #if 0
    #ifdef __SRV_SMS_SIMBOX_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __SRV_SMS_SIMBOX_SUPPORT__ */
/* under construction !*/
    #ifdef __SRV_SMS_ARCHIVE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __SRV_SMS_ARCHIVE__ */
    #endif
        default:
            break;
    }
}

void srv_sms_tcard_update_msg_list(U16 msg_id ,srv_sms_box_enum src_box_type,srv_sms_box_enum dest_box_type)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *dest_sort_list;
    U16 *src_sort_list;
    U32 timestamp;
    U32 insert_index;
    U16 *dest_size;
    U16 *src_size;
    MMI_BOOL flag = MMI_FALSE;
    MMI_BOOL total_del_ret = MMI_FALSE;
    MMI_BOOL tcard_del_ret = MMI_FALSE;
    MMI_BOOL show_del_ret = MMI_FALSE;
    MMI_BOOL total_add_ret = MMI_FALSE;
    
    srv_sms_filter_enum storage_filter;
    MMI_BOOL need_update = MMI_FALSE;
    srv_sms_storage_enum storage_type = SRV_SMS_STORAGE_UNSPECIFIC;
    srv_sms_tcard_msg_node_struct *tcard_msg_node;
    srv_sms_msg_node_struct *msg_node;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    storage_filter = srv_sms_get_storage_filter();
    //insert tcard
    if (src_box_type != dest_box_type)
    {
        if(msg_id >= SRV_SMS_MAX_MSG_NUM)
        {
            tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);

            timestamp = tcard_msg_node->timestamp;
            storage_type = tcard_msg_node->storage_type;
        }
        else
        {
            msg_node = srv_sms_get_msg_node(msg_id);
            timestamp = msg_node->timestamp; 
            storage_type = msg_node->storage_type;
        }

        /*edit the tcard list*/
        if(msg_id >= SRV_SMS_MAX_MSG_NUM && storage_cntx.is_tcard_ready)
        {
            srv_sms_get_tcard_list_and_size(&src_sort_list, &src_size, src_box_type);
            tcard_del_ret = srv_sms_delete_msg_from_list(
                                    src_sort_list,
                                    *src_size,
                                    msg_id);


            srv_sms_get_tcard_list_and_size(&dest_sort_list, &dest_size, dest_box_type);
    
            insert_index = srv_sms_tcard_get_insert_index(
                                MMI_FALSE, 
                                *dest_size, 
                                dest_sort_list,
                                timestamp);
            srv_sms_tcard_insert_list(
                        insert_index,
                        dest_sort_list,
                        *dest_size,
                        msg_id);
           
        }
        /*edit the total list*/
        srv_sms_get_total_list_and_size(&src_sort_list, &src_size, src_box_type);
        total_del_ret = srv_sms_delete_msg_from_list(
                                    src_sort_list,
                                    *src_size,
                                    msg_id);

        if((storage_type != SRV_SMS_STORAGE_TCARD) || ((storage_type == SRV_SMS_STORAGE_TCARD) && storage_cntx.is_tcard_ready) )
        {
            srv_sms_get_total_list_and_size(&dest_sort_list, &dest_size, dest_box_type);

            insert_index = srv_sms_tcard_get_insert_index(
                                MMI_FALSE, 
                                *dest_size, 
                                dest_sort_list,
                                timestamp);
            srv_sms_tcard_insert_list(
                        insert_index,
                        dest_sort_list,
                        *dest_size,
                        msg_id);
            total_add_ret = MMI_TRUE;
        }
        
      
        

        switch (storage_filter)
        {
            case SRV_SMS_FILTER_ME:
                if(storage_type == SRV_SMS_STORAGE_ME)
                {
                    flag = MMI_TRUE;
                }
                break;
            case SRV_SMS_FILTER_SIM:
                if(storage_type == SRV_SMS_STORAGE_SIM)
                {
                    flag = MMI_TRUE;
                }
                
                break;
            case SRV_SMS_FILTER_TCARD:
                if(storage_type == SRV_SMS_STORAGE_TCARD && storage_cntx.is_tcard_ready)
                {
                    flag = MMI_TRUE;
                }
                break;
            case SRV_SMS_FILTER_ME | SRV_SMS_FILTER_SIM:
                if((storage_type == SRV_SMS_STORAGE_ME)||(storage_type == SRV_SMS_STORAGE_SIM))
                {
                    flag = MMI_TRUE;
                }
                
                break;
            case SRV_SMS_FILTER_ME | SRV_SMS_FILTER_TCARD:
                if((storage_type == SRV_SMS_STORAGE_ME)||((storage_type == SRV_SMS_STORAGE_TCARD) && storage_cntx.is_tcard_ready))
                {
                    flag = MMI_TRUE;
                }                        
                break;
            case SRV_SMS_FILTER_SIM | SRV_SMS_FILTER_TCARD:
                if((storage_type == SRV_SMS_STORAGE_SIM)||((storage_type == SRV_SMS_STORAGE_TCARD) && storage_cntx.is_tcard_ready))
                {
                    flag = MMI_TRUE;
                }                                 
                break;
            case SRV_SMS_FILTER_ALL:
                if(storage_type == SRV_SMS_STORAGE_TCARD)
                {
                    if(storage_cntx.is_tcard_ready)
                    {
                        flag = MMI_TRUE;
                    }
                }
                else
                {
                    flag = MMI_TRUE;
                }
                
                break;
            default:
                ASSERT(0);
                break;
                
        }
        /*edit the show file*/
        if(flag)
        {
            srv_sms_get_show_list_and_size(&src_sort_list, &src_size, src_box_type);
            show_del_ret = srv_sms_delete_msg_from_list(
                                    src_sort_list,
                                    *src_size,
                                    msg_id);


            srv_sms_get_show_list_and_size(&dest_sort_list, &dest_size, dest_box_type);

            insert_index = srv_sms_tcard_get_insert_index(
                                MMI_FALSE, 
                                *dest_size, 
                                dest_sort_list,
                                timestamp);
            srv_sms_tcard_insert_list(
                        insert_index,
                        dest_sort_list,
                        *dest_size,
                        msg_id);
        }
//count the number
        switch (src_box_type)
        {
            case SRV_SMS_BOX_INBOX:
                if(total_del_ret)
                {
                    srv_sms_inbox_total_size--;
                }
                
                if(msg_id >= SRV_SMS_MAX_MSG_NUM && tcard_del_ret)
                {
                    srv_sms_inbox_tcard_size--;
                }
                if(flag && show_del_ret)
                {
                    srv_sms_inbox_show_size--;
                }
                break;

            case SRV_SMS_BOX_OUTBOX:
                if(total_del_ret)
                {
                    srv_sms_outbox_total_size--;
                }
                
                if(msg_id >= SRV_SMS_MAX_MSG_NUM && tcard_del_ret)
                {
                    srv_sms_outbox_tcard_size--;
                }
                if(flag && show_del_ret)
                {
                    srv_sms_outbox_show_size--;
                }
                break;

            case SRV_SMS_BOX_DRAFTS:
                if(total_del_ret)
                {
                    srv_sms_drafts_total_size--;
                }
                
                if(msg_id >= SRV_SMS_MAX_MSG_NUM && tcard_del_ret)
                {
                    srv_sms_drafts_tcard_size--;
                }
                if(flag && show_del_ret)
                {
                    srv_sms_drafts_show_size--;
                }
                break;

        #ifdef __SRV_SMS_UNSENT_LIST__
            case SRV_SMS_BOX_UNSENT:
                if(total_del_ret)
                {
                    srv_sms_unsent_total_size--;
                }
                
                if(msg_id >= SRV_SMS_MAX_MSG_NUM && tcard_del_ret)
                {
                    srv_sms_unsent_tcard_size--;
                }
                if(flag && show_del_ret)
                {
                    srv_sms_unsent_show_size--;
                }
                break;
        #endif /* __SRV_SMS_UNSENT_LIST__ */

            default:
                break;
        }


        switch (dest_box_type)
        {
            case SRV_SMS_BOX_INBOX:
                if(total_add_ret)
                {
                    srv_sms_inbox_total_size++;
                }
                
                if(msg_id >= SRV_SMS_MAX_MSG_NUM)
                {
                    srv_sms_inbox_tcard_size++;
                }
                if(flag)
                {
                    srv_sms_inbox_show_size++;
                }
                break;

            case SRV_SMS_BOX_OUTBOX:
                if(total_add_ret)
                {
                    srv_sms_outbox_total_size++;
                }
                
                if(msg_id >= SRV_SMS_MAX_MSG_NUM)
                {
                    srv_sms_outbox_tcard_size++;
                }
                if(flag)
                {
                    srv_sms_outbox_show_size++;
                }
                break;

            case SRV_SMS_BOX_DRAFTS:
                if(total_add_ret)
                {
                    srv_sms_drafts_total_size++;
                }
                if(msg_id >= SRV_SMS_MAX_MSG_NUM)
                {
                    srv_sms_drafts_tcard_size++;
                }
                if(flag)
                {
                    srv_sms_drafts_show_size++;
                }
                break;

        #ifdef __SRV_SMS_UNSENT_LIST__
            case SRV_SMS_BOX_UNSENT:
                if(total_add_ret)
                {
                    srv_sms_unsent_total_size++;
                }
                if(msg_id >= SRV_SMS_MAX_MSG_NUM)
                {
                    srv_sms_unsent_tcard_size++;
                }
                if(flag)
                {
                    srv_sms_unsent_show_size++;
                }
                break;
        #endif /* __SRV_SMS_UNSENT_LIST__ */

            default:
                break;
        }
        
    }
}


#endif
