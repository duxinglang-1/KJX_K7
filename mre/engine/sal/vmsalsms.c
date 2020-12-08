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

/*******************************************************************************
 * Filename:
 * ---------
 * Vmsalsms.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "vmswitch.h"
#ifdef __MRE_SAL_SMS__
#include "DevConfigGprot.h"
#include "string.h"
#include "vmmod.h"
#include "vmsys.h"
#include "vmlog.h"
#include "vmchset.h"
#include "vmmem.h"

#include "vmresmng.h"
#include "SmsSrvGprot.h"
#include "vmsms.h"
#include "ModeSwitchSrvGProt.h"

/* ------------------------------------------------------------------------ */
/* global variable                                                       */
/* ------------------------------------------------------------------------ */
extern mmi_devconfig_system_config_struct sysconf;

srv_sms_msg_data_struct *sms_data;
VMWSTR sms_content;

srv_sms_msg_data_struct  vm_read_data;
VMINT16  content_buffer[VM_SMS_MSG_CONTENT_LEN+1];

/* ------------------------------------------------------------------------ */
/* function declare                                                           */
/* ------------------------------------------------------------------------ */
extern void vm_sms_callback(srv_sms_callback_struct* callback_data);
extern void srv_sms_set_storage_type(SMS_HANDLE sms_handle, srv_sms_storage_enum storage_type);
extern S32 mmi_wcslen(const WCHAR *string);
/* ------------------------------------------------------------------------ */
/* internal variable                                                       */
/* ------------------------------------------------------------------------ */

static SMS_HANDLE smssend_handle = NULL;

/* ------------------------------------------------------------------------ */
/* internal function                                                     */
/* ------------------------------------------------------------------------ */

static VMINT vm_send_sms_request(S8*number, U16* content);
void vm_sal_cancel_send_sms(void);

static VMINT vm_sms_interrupt_event_callback(srv_sms_event_struct* event_data);
static VMINT vm_sms_sys_set_interrupt_event_handler(vm_sms_event_enum event_id);
static VMINT vm_sms_sys_clear_interrupt_event_handler(vm_sms_event_enum event_id);


VMINT vm_sal_initialize_sms_module(void)
{
    vm_sms_sys_set_interrupt_event_handler(VM_EVT_ID_SMS_NEW_MSG);

	vm_log_debug("static memory optimize: vm_sal_initialize_sms_module");
	sms_data = _vm_kernel_malloc(sizeof(srv_sms_msg_data_struct));
	if (NULL == sms_data)
	{
		vm_log_error("vm_sal_initialize_sms_module - vm_malloc fail.");
		return -1;
	}
	sms_content = _vm_kernel_malloc((VM_SMS_MSG_CONTENT_LEN + 1) * sizeof(VMINT16));
	if (NULL == sms_content)
	{
		vm_log_error("vm_sal_initialize_sms_module - vm_malloc fail.");
		vm_free(sms_data);
		sms_data = NULL;
		return -2;
	}

	return 0;
}

VMINT vm_sal_finialize_sms_module(void)
{
	smssend_handle = NULL;
	_vm_kernel_free(sms_content);
	_vm_kernel_free(sms_data);

	vm_sms_sys_clear_interrupt_event_handler(VM_EVT_ID_SMS_NEW_MSG);
	return 0;
}

VMINT vm_sal_send_sms(VMWSTR number, VMWSTR content, void (*callback)(VMINT result)) 
{
	VMINT retval = FALSE;

	if (!srv_mode_switch_is_network_service_available())
	{
		vm_log_debug("vm_send_sms: flight mode");
		return FALSE;
	}

	vm_log_debug("vm_send_sms phonenumber : %s", vm_gb2312_string(number));

	smssend_handle = srv_sms_get_send_handle();
	if (smssend_handle == NULL)
	{
		return -1;
	}

	if ((U16)srv_sms_is_bg_send_action_busy() == TRUE)
	{
		/* background sending is busy */
		return -1;
	}

	/* set address number */
	srv_sms_set_address(smssend_handle, (S8*)number);
	/* set content of DCS encoding */
	srv_sms_set_content_dcs(smssend_handle, SRV_SMS_DCS_7BIT);
	/* set content */
	srv_sms_set_content(smssend_handle, (S8*)content, (U16)((mmi_wcslen(content)+1)*2));

    srv_sms_set_sim_id(smssend_handle, (1<<(vm_sim_get_active_sim_card()-1))|MMI_GSM);

	/* send request */
	srv_sms_send_msg(smssend_handle, (SrvSmsCallbackFunc)vm_sms_callback, NULL);

	return TRUE;
}

VMINT vm_sal_sms_read_msg(VMUINT16 msg_id, VMINT change_status,  vm_sms_msg_data_t* msg_data, 
	            VmSmsCallbackFunc  callback_func, void* user_data, VMINT * cause)
{
	VMINT res = 0;
  	  
	vm_log_debug("vm_sal_sms_read_msg: start");  

	memset(sms_data, 0, sizeof(srv_sms_msg_data_struct));
	memset(sms_content, 0, (VM_SMS_MSG_CONTENT_LEN + 1) * sizeof(VMINT16));
	vm_log_debug("sizeof(sms_content) = %d", (VM_SMS_MSG_CONTENT_LEN + 1) * sizeof(VMINT16));/*1002*/
	
	sms_data->folder_id = SRV_SMS_FOLDER_DEFAULT;
	sms_data->para_flag |= SRV_SMS_PARA_NUM;
	sms_data->para_flag |= SRV_SMS_PARA_SCA;
	sms_data->para_flag |= SRV_SMS_PARA_PID; 
	sms_data->para_flag |= SRV_SMS_PARA_DCS;
	sms_data->para_flag |= SRV_SMS_PARA_VP; 
	sms_data->para_flag |= SRV_SMS_PARA_STATUS_REPORT;
	sms_data->para_flag |= SRV_SMS_PARA_REPLY_PATH;
	sms_data->para_flag |= SRV_SMS_PARA_PORT; 
	sms_data->para_flag |= SRV_SMS_PARA_CLASS;
	sms_data->para_flag |= SRV_SMS_PARA_STATUS; 
	sms_data->para_flag |= SRV_SMS_PARA_SIM_ID;
	sms_data->para_flag |= SRV_SMS_PARA_STORAGE_TYPE;
	sms_data->para_flag |= SRV_SMS_PARA_TIMESTAMP; 
	sms_data->para_flag |= SRV_SMS_PARA_CONTENT_BUFF;
	
	sms_data->content_buff = (VMINT8*)sms_content;
	sms_data->content_buff_size = (VM_SMS_MSG_CONTENT_LEN + 1) * sizeof(VMINT16);
	
	srv_sms_read_msg(msg_id, (MMI_BOOL)change_status, sms_data, (SrvSmsCallbackFunc)vm_sms_callback, user_data);

	vm_log_debug("vm_sms_read_msg: end");
	return VM_SMS_REQ_NO_ERROR;
 
}


VMINT vm_sal_sms_add_msg(vm_sms_add_msg_data_t * msg_data, VmSmsCallbackFunc callback_func, void* user_data, VMINT * cause)
{
	SMS_HANDLE  handle = NULL;
	MYTIME timestamp;
	 
	vm_log_debug("vm_sal_sms_add_msg:start");  

	  
    handle =  srv_sms_get_save_handle();
    vm_log_debug("vm_sal_sms_add_msg:handle=%d",handle);  
    if(handle == NULL)
    {
        vm_log_error("vm_sal_sms_add_msg:handle < 0");
        *cause = SRV_SMS_CAUSE_DATA_INVALID;
        return VM_SMS_REQ_ERROR;
    }
	  
  	vm_log_debug("vm_sal_sms_add_msg:timestamp");  
	timestamp.nYear = msg_data->timestamp.year;
	timestamp.nMonth= msg_data->timestamp.mon;
	timestamp.nDay= msg_data->timestamp.day;
	timestamp.nHour = msg_data->timestamp.hour;
	timestamp.nMin = msg_data->timestamp.min;
	timestamp.nSec = msg_data->timestamp.sec;
	
	vm_log_debug("vm_sal_sms_add_msg:msg_data->number=%s", vm_gb2312_string((VMWSTR)msg_data->number));  
	srv_sms_set_address(handle, msg_data->number);
	
	vm_log_debug("vm_sal_sms_add_msg:srv_sms_set_content_dcs");  
	srv_sms_set_content_dcs( handle, SRV_SMS_DCS_UCS2);  
	
	vm_log_debug("vm_sal_sms_add_msg:srv_sms_set_content"); 
    srv_sms_set_content( handle, msg_data->content , msg_data->content_size);  
	   
	vm_log_debug("vm_sal_sms_add_msg:msg_data->status=%x",msg_data->status); 
	srv_sms_set_status(handle, (srv_sms_status_enum)msg_data->status); 

	vm_log_debug("vm_sal_sms_add_msg:msg_data->storage_type=%d",msg_data->storage_type); 
	srv_sms_set_storage_type(handle, (srv_sms_storage_enum)msg_data->storage_type); 
	
	vm_log_debug("vm_sal_sms_add_msg: msg_data->sim_id=%d", msg_data->sim_id); 
	srv_sms_set_sim_id(handle, (srv_sms_sim_enum)msg_data->sim_id);

	vm_log_debug("vm_sal_sms_add_msg: srv_sms_set_save_timestamp"); 
	srv_sms_set_save_timestamp(handle, &timestamp);

	vm_log_debug("vm_sal_sms_add_msg: srv_sms_save_msg"); 
	srv_sms_save_msg(handle, (SrvSmsCallbackFunc)vm_sms_callback, user_data);
	       
    vm_log_debug("vm_sal_sms_add_msg:end");  
    return VM_SMS_REQ_NO_ERROR;
}


VMINT vm_sal_sms_delete_msg(VMUINT16 msg_id, VmSmsCallbackFunc callback_func,  void* user_data, VMINT * cause)
{
    vm_log_debug("vm_sms_delete_msg:start");  

    srv_sms_delete_msg(msg_id, (SrvSmsCallbackFunc)vm_sms_callback, user_data);

    vm_log_debug("vm_sms_delete_msg:end");  
    return VM_SMS_REQ_NO_ERROR;
}


VMINT vm_sal_sms_delete_msg_list(vm_sms_box_enum box_type,  vm_sms_sim_enum sim_id, VmSmsCallbackFunc callback_func,  void* user_data, VMINT * cause)
{
    vm_log_debug("vm_sms_delete_msg_list:start");  

    srv_sms_delete_msg_list((srv_sms_box_enum)box_type, (srv_sms_sim_enum)sim_id, (SrvSmsCallbackFunc)vm_sms_callback, user_data);

    vm_log_debug("vm_sms_delete_msg_list:end");  
    return VM_SMS_REQ_NO_ERROR;
}


VMINT vm_sal_sms_get_msg_id_list(vm_sms_query_t* query_data,  VmSmsCallbackFunc callback_func,  void* user_data, VMINT * cause)
{
    srv_sms_query_struct * sms_query = NULL;

    vm_log_debug("vm_sal_sms_get_msg_id_list:start");  
    
    sms_query = (srv_sms_query_struct *) _vm_kernel_calloc(sizeof(srv_sms_query_struct));
    if(sms_query == NULL)
    { 
        vm_log_error("vm_sal_sms_get_msg_id_list:sms_query ==NULL");
        *cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
        return VM_SMS_REQ_ERROR;
    } 

    sms_query->folder_id = SRV_SMS_FOLDER_DEFAULT;
    sms_query->query_flag = SRV_SMS_QUERY_STATUS;  
    sms_query->sort_flag = (srv_sms_sort_enum)query_data->sort_flag;  
    sms_query->order_flag = (srv_sms_order_enum)query_data->order_flag;  
    sms_query->status = (srv_sms_status_enum)query_data->status;  

    srv_sms_query_msg(sms_query, (SrvSmsCallbackFunc)vm_sms_callback, user_data);

    _vm_kernel_free(sms_query);
    vm_log_debug("vm_sal_sms_get_msg_id_list:end");  
    return VM_SMS_REQ_NO_ERROR;
}

VMINT vm_sal_sms_get_sc_address(vm_sms_sim_enum sim_id, VmSmsCallbackFunc callback, void* user_data)
{	
	srv_sms_setting_struct * sms_setting = NULL;
	srv_sms_callback_struct  callback_data;
	vm_sms_get_sc_addr_cb_t  sc_addr_cb;
	  
	vm_log_debug("vm_sal_sms_get_sc_address_asyn:start");  
	
	memset(&sc_addr_cb, 0, sizeof(vm_sms_get_sc_addr_cb_t));	
	sms_setting = (srv_sms_setting_struct*)srv_sms_get_default_setting((srv_sms_sim_enum)sim_id);
		
	strncpy(sc_addr_cb.sc_addr, sms_setting->sc_addr, VM_SMS_MAX_ADDR_LEN); 

	vm_log_debug("vm_sal_sms_get_sc_address:sc_addr=%s",sc_addr_cb.sc_addr);
	callback_data.user_data = user_data;
	callback_data.action_data = &sc_addr_cb;
	callback_data.action = (srv_sms_action_enum)VM_SMS_ACTION_GET_SC_ADDR;
	if(sc_addr_cb.sc_addr[0] != 0)
	{		
		callback_data.result = (MMI_BOOL)1;
		callback_data.cause = (srv_sms_cause_enum)0;
		
	}
	else
	{
		callback_data.result = (MMI_BOOL)0;
		callback_data.cause = SRV_SMS_CAUSE_SC_EMPTY;
		vm_log_error("vm_sms_get_sc_address:strlen(sc_addr_cb.sc_addr) =%d",strlen(sc_addr_cb.sc_addr) );
	}
	
 	vm_sms_callback(&callback_data);
	vm_log_debug("vm_sal_sms_get_sc_address_asyn:end");  
	return VM_SMS_REQ_NO_ERROR;
}


#define vm_sms_event_registered_by_process(PHANDLE) \
    (vm_res_get_data_list_count_by_proecss((PHANDLE), VM_RES_TYPE_SMS_INTERRUPT) > 0 ||\
        vm_res_get_data_list_count_by_proecss((PHANDLE), VM_RES_TYPE_SMS_INTERRUPT_EX) > 0)

VMINT vm_sms_sys_set_interrupt_event_handler(vm_sms_event_enum event_id)
{
    VMINT id = -1;

    vm_log_debug("[SMS]-vm_sms_sys_set_interrupt_event_handler:start");
    
    id = EVT_ID_SRV_SMS_NEW_MSG;
    srv_sms_set_interrupt_event_handler(id, (SrvSmsEventFunc)vm_sms_interrupt_event_callback, NULL);
	vm_log_debug("[SMS]-vm_sms_set_interrupt_event_handler:end");	
	return VM_SMS_REQ_NO_ERROR;
}


static VMINT vm_sms_identify_interrupt_event_data(char * user_data)
{
    char identify_str[16] = "MRE PAYMENT";
    if (strncmp(identify_str,user_data,16))
        return FALSE;
    return TRUE;
}

VMINT vm_sms_set_interrupt_event_handler_forpay(vm_sms_event_enum event_id,  VmSmsEventFunc event_func,  void* user_data)
{   
    if (!(vm_sms_identify_interrupt_event_data((char *)user_data)))
        return VM_SMS_IDENTIFY_ERROR;
    
    return vm_sms_set_interrupt_event_handler(event_id,  event_func,  user_data);	
}



VMINT vm_sms_sys_clear_interrupt_event_handler(vm_sms_event_enum event_id)
{
    srv_sms_clear_interrupt_event_handler(EVT_ID_SRV_SMS_NEW_MSG, (SrvSmsEventFunc)vm_sms_interrupt_event_callback,  NULL);	
    return VM_SMS_REQ_NO_ERROR;
}

VMINT vm_sms_clear_interrupt_event_handler_forpay(vm_sms_event_enum event_id,  VmSmsEventFunc event_func,  void* user_data)
{
    return vm_sms_clear_interrupt_event_handler(event_id, event_func, user_data);
}

VMINT vm_sms_set_interrupt_event_handler(vm_sms_event_enum event_id,  VmSmsEventFunc event_func,  void* user_data)
{   
    VM_P_HANDLE phandle = vm_pmng_get_current_handle(); 
    VMINT res_id;
    VMINT data_type;
    
    vm_log_debug("[SMS]-vm_sms_set_interrupt_event_handler:start");

    if (phandle == 0)
        return VM_SMS_MIBR_NOT_IN_PROCESS_SPACE;
		
    if(!event_func)
        return VM_SMS_REQ_ERROR;
    
    if (vm_sms_event_registered_by_process(phandle))
        return VM_SMS_REQ_CALLBACK_REGISTERED;

    if (VM_EVT_ID_SMS_NEW_MSG == event_id)
    {
        data_type = VM_RES_TYPE_SMS_INTERRUPT;
    }
    else if (VM_EVT_ID_SMS_NEW_MSG_EX == event_id)
    {
        data_type = VM_RES_TYPE_SMS_INTERRUPT_EX;
    }
    else
    {
        return VM_SMS_MIBR_ERROR;
    }

    
    if ((res_id = vm_res_save_data(data_type, (void*)event_func, 4, NULL, phandle)) < 0)
    {
       vm_log_debug("[SMS]-vm_sms_set_interrupt_event_handler:vm_res_save_data error%d",res_id);
       return VM_SMS_MIBR_ERROR;
    }
    vm_log_debug("[SMS]-vm_sms_set_interrupt_event_handler:vm_res_save_data = %d,%x,%x",res_id,event_func,&event_func);    
	vm_log_debug("[SMS]-vm_sms_set_interrupt_event_handler:end");	
	return VM_SMS_REQ_NO_ERROR;
}


VMINT vm_sms_clear_interrupt_event_handler(vm_sms_event_enum event_id,  VmSmsEventFunc event_func,  void* user_data)
{
    VM_P_HANDLE phandle = vm_pmng_get_current_handle(); 
    vm_res_node_t res_node;
    VMINT res_id;
    VMINT data_type;
    
    vm_log_debug("[SMS]-vm_sms_clear_interrupt_event_handler:start");   

    if (!vm_sms_event_registered_by_process(phandle))
        return VM_SMS_REQ_NO_ERROR;

    if (VM_EVT_ID_SMS_NEW_MSG == event_id)
    {
        data_type = VM_RES_TYPE_SMS_INTERRUPT;
    }
    else if (VM_EVT_ID_SMS_NEW_MSG_EX == event_id)
    {
        data_type = VM_RES_TYPE_SMS_INTERRUPT_EX;
    }
    else
    {
        return VM_SMS_MIBR_ERROR;
    }
    if (vm_res_get_data_list_by_proecss(phandle, data_type, &res_node, 1) < 0)
    {
       vm_log_debug("[SMS]-vm_sms_clear_interrupt_event_handler:vm_res_get_data_list_by_proecss error");
       return VM_SMS_MIBR_ERROR;        
    }

    res_id = res_node.res_id;
    vm_log_debug("[SMS]-vm_sms_clear_interrupt_event_handler:vm_res_release_data = %d",res_id); 
    if (vm_res_release_data(data_type, res_id) < 0)
    {
       vm_log_debug("[SMS]-vm_sms_clear_interrupt_event_handler:vm_res_release_data error");
       return VM_SMS_MIBR_ERROR;
    }    
    vm_log_debug("[SMS]-vm_sms_clear_interrupt_event_handler:end"); 
    return VM_SMS_REQ_NO_ERROR;


}

static VMINT vm_sms_interrupt_event_callback(srv_sms_event_struct* event_data)
{
    vm_sms_event_t  vm_sms_event_ptr;
	  
    vm_sms_event_new_sms_t  vm_event_new_msg;
    srv_sms_event_new_sms_struct  *srv_event_new_msg = NULL;
	  
    vm_sms_new_msg_t * vm_new_msg = NULL;
    srv_sms_new_msg_struct * srv_new_msg = NULL;

    VMINT user_res = FALSE;
    VM_P_HANDLE *phandle_lst = NULL;


    VMCHAR * vm_event_new_msg_content;

	 
    if(!event_data)
    {
        vm_log_error("[SMS]-vm_sms_interrupt_event_callback:event_data == NULL");
        return FALSE;
    }
	  
    if(event_data->evt_id != EVT_ID_SRV_SMS_NEW_MSG || (!event_data->event_info))
    {
        vm_log_debug("[SMS]-vm_sms_interrupt_event_callback:not EVT_ID_SRV_SMS_NEW_MSG or event_info is NULL");
        return FALSE;
    }        

    vm_new_msg = _vm_kernel_calloc(sizeof(vm_sms_new_msg_t));
    if(!vm_new_msg)
    {
        vm_log_error("[SMS]-vm_sms_interrupt_event_callback:new_msg == NULL");
        return FALSE;
    }

    memset(&vm_sms_event_ptr,0,sizeof(vm_sms_event_t));
    memset(&vm_event_new_msg,0,sizeof(vm_sms_event_new_sms_t));    
    
    srv_event_new_msg = (srv_sms_event_new_sms_struct*)event_data->event_info;
    srv_new_msg = (srv_sms_new_msg_struct *)srv_event_new_msg->msg_data;  

    
    vm_sms_event_ptr.event_id = VM_EVT_ID_SMS_NEW_MSG;
    vm_sms_event_ptr.size = event_data->size;
    vm_sms_event_ptr.user_data= NULL;
    vm_sms_event_ptr.event_info = (vm_sms_event_new_sms_t*)&vm_event_new_msg;  
    vm_log_debug("[SMS]-vm_sms_event_ptr size=%d,%d",vm_sms_event_ptr.size,event_data->size);

    
    
    vm_event_new_msg.msg_data = (vm_sms_new_msg_t *)vm_new_msg;
    vm_event_new_msg.msg_id = srv_event_new_msg->msg_id;
    
    vm_event_new_msg_content = _vm_kernel_calloc(srv_new_msg->message_len+2);
    if(!vm_event_new_msg_content)
    {
        if(vm_new_msg)
            _vm_kernel_free(vm_new_msg);
        vm_log_error("[SMS]-vm_sms_interrupt_event_callback:vm_event_new_msg_content == NULL");
        return FALSE;
    }
    
    memcpy(vm_event_new_msg_content , srv_event_new_msg->content , srv_new_msg->message_len);
    memset(vm_event_new_msg_content + srv_new_msg->message_len, 0, 2);
       
    vm_event_new_msg.content = (VMUINT8 *)vm_event_new_msg_content;   
			   
    vm_new_msg->msg_id = srv_new_msg->msg_id;
    vm_new_msg->dest_port = srv_new_msg->dest_port;
    vm_new_msg->src_port = srv_new_msg->src_port;
    vm_new_msg->message_len = srv_new_msg->message_len;
    vm_new_msg->ref = srv_new_msg->ref;
    strncpy((char*)vm_new_msg->number, (char*)srv_new_msg->number, VM_SMS_MAX_ADDR_LEN);
    strncpy((char*)vm_new_msg->sc_number, (char*)srv_new_msg->sc_number, VM_SMS_MAX_ADDR_LEN);
    vm_new_msg->timestamp.year = srv_new_msg->timestamp.nYear;
    vm_new_msg->timestamp.mon = srv_new_msg->timestamp.nMonth;
    vm_new_msg->timestamp.day = srv_new_msg->timestamp.nDay;
    vm_new_msg->timestamp.hour = srv_new_msg->timestamp.nHour;
    vm_new_msg->timestamp.min = srv_new_msg->timestamp.nMin;
    vm_new_msg->timestamp.sec = srv_new_msg->timestamp.nSec;
    vm_new_msg->total_seg = srv_new_msg->total_seg;
    vm_new_msg->seg = srv_new_msg->seg;
    vm_new_msg->dcs = srv_new_msg->dcs;
    vm_new_msg->mti = srv_new_msg->mti;
    vm_new_msg->pid = srv_new_msg->pid;
    vm_new_msg->fo = srv_new_msg->fo;
    strncpy((char*)vm_new_msg->data, (char*)srv_new_msg->data, 1);
    vm_new_msg->sim_id = (vm_sms_sim_enum)srv_new_msg->sim_id;
    vm_new_msg->storage_type = (vm_sms_storage_enum)srv_new_msg->storage_type;


    vm_log_debug("[SMS]- vm_sms_interrupt_action - begin");
	{
		VMINT p_state;
		for (p_state=VM_PMNG_FOREGROUND; p_state<=VM_PMNG_BACKGROUND; p_state++)
		{
			VMINT res_size;
			VMINT res_handle = vm_res_findfirst(-1, VM_RES_TYPE_SMS_INTERRUPT_EX);

			while ( VM_RES_NOT_FIND != res_handle )
			{
				VmSmsEventFunc cb = NULL;

				if (VM_RES_OK == vm_res_get_data(VM_RES_TYPE_SMS_INTERRUPT_EX, res_handle, (void **)&cb, &res_size) )
				{
					VMINT p_handle = vm_res_get_process_handle(VM_RES_TYPE_SMS_INTERRUPT_EX, res_handle);
	            	
					if (vm_pmng_state(p_handle) == p_state)
					{
	            		
				        if (cb && vm_pmng_set_ctx(p_handle) == VM_PMNG_OP_OK)
				        {
				            
			                ((VmSmsEventFunc)cb)(&vm_sms_event_ptr);
				            vm_pmng_reset_ctx();
				        }
					}
				}
				res_handle = vm_res_findnext(-1, VM_RES_TYPE_SMS_INTERRUPT_EX);
			}
			vm_res_findclose(VM_RES_TYPE_SMS_INTERRUPT_EX);
		}
	}
	{
		VMINT p_state;
		for (p_state=VM_PMNG_FOREGROUND; p_state<=VM_PMNG_BACKGROUND; p_state++)
		{
			VMINT res_size;
			VMINT res_handle = vm_res_findfirst(-1, VM_RES_TYPE_SMS_INTERRUPT);
            vm_log_debug("[SMS]- vm_sms_interrupt_action - p_state:%d, res_handle=%d", p_state, res_handle);
			while ( VM_RES_NOT_FIND != res_handle )
			{
				VmSmsEventFunc cb = NULL;
	            vm_log_debug("[SMS]- vm_sms_interrupt_action - 2 p_state:%d, res_handle=%d", p_state, res_handle);
				if (VM_RES_OK == vm_res_get_data(VM_RES_TYPE_SMS_INTERRUPT, res_handle, (void **)&cb, &res_size) )
				{
					VMINT p_handle = vm_res_get_process_handle(VM_RES_TYPE_SMS_INTERRUPT, res_handle);
	            	vm_log_debug("[SMS]- vm_sms_interrupt_action - 2 p_state:%d, res_handle=%d, p_handle:%d", p_state, res_handle, p_handle);
					if (vm_pmng_state(p_handle) == p_state)
					{
	            		vm_log_debug("[SMS]- vm_sms_interrupt_action - 3 p_state:%d, res_handle=%d, p_handle:%d", p_state, res_handle, p_handle);
				        if (cb && vm_pmng_set_ctx(p_handle) == VM_PMNG_OP_OK)
				        {
				            vm_log_debug("[SMS]- vm_sms_interrupt_action - p_state=%d, cb=%x", p_state, cb);
			                user_res = ((VmSmsEventFunc)cb)(&vm_sms_event_ptr);
				            vm_pmng_reset_ctx();
				        }  
						
				        if (user_res)
				        {
				            if(vm_new_msg)
				                _vm_kernel_free(vm_new_msg);
				            if(vm_event_new_msg_content)
				                _vm_kernel_free(vm_event_new_msg_content);            
				            vm_log_debug("[SMS]- interupted: cb=%x", cb);
							vm_res_findclose(VM_RES_TYPE_SMS_INTERRUPT);
				            return TRUE;                
				        }
					}
				}
				res_handle = vm_res_findnext(-1, VM_RES_TYPE_SMS_INTERRUPT);
			}
			vm_res_findclose(VM_RES_TYPE_SMS_INTERRUPT);
		}
	}
    vm_log_debug("[SMS]- vm_sms_interrupt_action - end");   
    if(vm_new_msg)
        _vm_kernel_free(vm_new_msg);
    if (phandle_lst)
        _vm_kernel_free(phandle_lst);
    if(vm_event_new_msg_content)
        _vm_kernel_free(vm_event_new_msg_content);            
    return FALSE;
    
}

#endif //__MRE_SAL_SMS__