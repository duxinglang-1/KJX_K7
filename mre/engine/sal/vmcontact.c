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
 * Vmcontact.c
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
#ifdef __MRE_SAL_PHONEBOOK__

//#include "PhoneBookGprot.h"
//#include "MMI_include.h"
#include "MMIDataType.h"
#include "DevConfigGprot.h"
#include "Customer_email_num.h"
#include "l4c2phb_enums.h"
#include "l4c_common_enum.h"
#include "mcd_l4_common.h"
#include "l4c_aux_struct.h"
#include "ps2sim_struct.h"
#include "ps2sat_struct.h"
#include "l4c2smu_struct.h"
#include "PhbSrvGprot.h"

#include "vmmod.h"
#include "vmsys.h"
#include "vmlog.h"
#include "vmopt.h"
#include "vmstdlib.h"
#include "vmchset.h"
#include "vmsim.h"
#include "vmcontact.h"

#include "vmresmng.h"
#include "vmpromng.h"
#include "vmpromnginner.h"
#include "vmtimer.h"

#include "vmsalcontact.h"
#include "vmmacrostub.h"


/* ------------------------------------------------------------------------ */
/* global variable                                                      */
/* ------------------------------------------------------------------------ */
extern mmi_devconfig_system_config_struct sysconf;
extern VMINT vm_is_card2Absent(void);
extern VMINT vm_is_card1Absent(void);
//extern void  vm_phb_build_contact_ptr(vm_phb_contact_struct* contact, srv_phb_sdk_contact_struct * contact_ptr);	

/* ------------------------------------------------------------------------ */
/* declare                                                          */
/* ------------------------------------------------------------------------ */
void vm_phb_callback_manager(S32 result, srv_phb_sdk_contact_struct* contact_ptr);

/* ------------------------------------------------------------------------ */
/* internal declare                                                       */
/* ------------------------------------------------------------------------ */
static VMINT vm_phb_storage_is_valid(vm_phb_storage_loc_enum storage);
static void  vm_phb_queue_manager(VMINT tid);

static VMINT phb_busy_flag = 0;

static VMINT phb_process_handle = -1;

extern VMINT mre_running;

typedef enum
{
	VM_PHB_ADD,
  	VM_PHB_DELETE,
  	VM_PHB_UPDATE,
  	VM_PHB_SEARCH,
  	VM_PHB_GET_CONTACT
    
}phb_operation_type;

typedef struct
{
 	VMINT  operation_type;
 	void*  req_info;
 	void*  cb;
}phb_common_t;

typedef struct
{
 	VMINT  operation_type;
 	vm_phb_add_req_struct* req_info;
 	vm_phb_callback_type cb;
 
 }phb_add_t;

typedef struct
{
	VMINT  operation_type;
 	vm_phb_delete_req_struct* req_info;
 	vm_phb_callback_type cb;
 
 }phb_delete_t;

typedef struct
{
	VMINT  operation_type;
	vm_phb_update_req_struct* req_info;
	vm_phb_callback_type cb;
 
 }phb_update_t;


typedef struct
{
	VMINT  operation_type;
	vm_phb_search_req_struct* req_info;
	vm_phb_callback_type cb;
 
 }phb_search_t;

typedef struct
{
	VMINT  operation_type;
	vm_phb_get_req_struct* req_info;
	vm_phb_callback_type cb;
 
 }phb_get_contact_t;



static void  vm_phb_process_status_callback(VM_P_HANDLE process_handle, VMINT sys_state);


static void vm_finialize_phb_module(void)
{
	phb_busy_flag=0;
	phb_process_handle = -1;
 
	vm_res_type_set_notify_callback(VM_RES_TYPE_PHONE_BOOK,  NULL);  
}


static void vm_intial_phb_module(void)
{ 
	phb_busy_flag=0;
	phb_process_handle = -1;

	vm_res_type_set_notify_callback(VM_RES_TYPE_PHONE_BOOK,  vm_phb_process_status_callback);
}

static VMINT phb_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
  
	switch(event)
	{
		case EVT_MOD_INIT:
			vm_intial_phb_module();	
			break;
		case EVT_MOD_RELEASE:
			vm_finialize_phb_module();
			break;
		default:
			vm_log_error("{PHB MODULE}Receive unkown [%d] event.", event);
			return -2;
	}

	return 0;
}

VMINT _vm_reg_phb_module(void)
{
	int res = 0;
	
	if ((res = _vm_reg_module("PHB MODULE", (MOD_EVT_PROCESS)phb_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
	{
		vm_log_error("Failed to regisiter phb module. Error Code : %d", res);
	}
	return res;
}

static void  vm_phb_process_status_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
	VMINT i = 0;
	VMINT res = -1;
	phb_add_t * phb_add = NULL;
	phb_delete_t * phb_delete = NULL;
	phb_update_t * phb_update = NULL;
	phb_search_t * phb_search = NULL;
	phb_get_contact_t * phb_get_contact = NULL;
	VMINT* data_buffer = NULL;  
	VMINT buffer_size = 0;

	VMINT cur_data_handle = -1;
    VMINT p_handle = -1; 
	
	cur_data_handle = vm_res_findfirst(-1, VM_RES_TYPE_PHONE_BOOK);
	if(cur_data_handle == VM_RES_NOT_FIND)
		return;
	vm_res_findclose(VM_RES_TYPE_PHONE_BOOK);
	
	p_handle = vm_res_get_process_handle( VM_RES_TYPE_PHONE_BOOK, cur_data_handle);

	if (VM_PMNG_UNLOAD == sys_state)
	{
		vm_log_debug("vm_phb_process_status_callback:start");  
		while ( (i = vm_res_findfirst(process_handle, VM_RES_TYPE_PHONE_BOOK)) != VM_RES_NOT_FIND)
		{
			res= vm_res_get_data( VM_RES_TYPE_PHONE_BOOK, i, (void**)&data_buffer, &buffer_size );
            vm_log_debug("vm_phb_process_status_callback:%d",data_buffer[0]);
            
			if(res == 0)
			{
                phb_common_t* phb_ptr = (phb_common_t*)data_buffer;
                vm_free(phb_ptr->req_info);	
				vm_free(phb_ptr);				
			}
			vm_res_release_data(VM_RES_TYPE_PHONE_BOOK,  i); 
			vm_log_debug("vm_phb_process_status_callback : data handle=%d", i);
			vm_res_findclose(VM_RES_TYPE_PHONE_BOOK);
		}
		
		if( (p_handle == process_handle) &&(phb_process_handle == -1))
		{
			cur_data_handle = vm_res_findfirst(-1, VM_RES_TYPE_PHONE_BOOK);
			if(cur_data_handle == VM_RES_NOT_FIND)
				return;
			vm_res_findclose(VM_RES_TYPE_PHONE_BOOK);
			
			p_handle = vm_res_get_process_handle( VM_RES_TYPE_PHONE_BOOK, cur_data_handle);
			if (vm_pmng_set_ctx(p_handle) == VM_PMNG_OP_OK)
			{
				if(vm_create_timer(100, (VM_TIMERPROC_T)vm_phb_queue_manager)<0)
				{
					vm_log_debug("vm_phb_process_status_callback timer fail");
				}
				phb_process_handle = -1;
				vm_pmng_reset_ctx();     
			}							       
		}		
		vm_log_debug("vm_phb_process_status_callback:end");  
	}
}



static void  vm_phb_queue_manager(VMINT tid)
{ 
  
	phb_add_t * phb_add = NULL;
	phb_delete_t * phb_delete = NULL;
	phb_update_t * phb_update = NULL;
	phb_search_t * phb_search = NULL;
	phb_get_contact_t * phb_get_contact = NULL;
	vm_res_node_t res_node;
	VMINT * data_buffer = NULL;
	VMINT res = -1;
	VMINT i = 0;
    phb_common_t* phb_ptr;
    typedef VMINT (*operate_func_type)(void* req_info,  void* cb);
    static const operate_func_type operate_func[]=
    {
        (operate_func_type)vm_sal_phb_add_contact,
        (operate_func_type)vm_sal_phb_delete_contact,
        (operate_func_type)vm_sal_phb_update_contact,
        (operate_func_type)vm_sal_phb_search_contact,
        (operate_func_type)vm_sal_phb_get_contact,
    };
    
	if(tid >=0)
	{
		vm_delete_timer(tid);
	}
	if(phb_busy_flag)
	{
		vm_log_debug("vm_phb_queue_manager:sms_busy_flag=1");
		return;
	}
	
	res = vm_res_get_data_list_by_type(VM_RES_TYPE_PHONE_BOOK, &res_node, 1);
	if(res <= 0)
	{
		vm_log_debug("vm_phb_queue_manager:vm_res_get_data fail");
		return;
	}
	vm_log_debug("vm_phb_queue_manager:res=%d",res);
	
	
	phb_busy_flag = 1;
	data_buffer = (VMINT * )res_node.data_content;
	
	vm_log_debug("vm_phb_queue_manager:type=%d",data_buffer[0]);  
	phb_process_handle = res_node.phandle;

    phb_ptr = (phb_common_t*)res_node.data_content;
	res = operate_func[data_buffer[0]](phb_ptr->req_info, phb_ptr->cb);
	if(res < 0)
	{
		vm_phb_callback_manager(res, NULL);
		vm_log_error("vm_phb_queue_manager:%d res=%d", data_buffer[0], res);   	
	}
	
	vm_log_debug("vm_phb_queue_manager:end"); 
}


void vm_phb_callback_manager(S32 result, srv_phb_sdk_contact_struct* contact_ptr)
{
	VMINT data_handle = -1;
	VMINT i = 0;
	VMINT res = -1;
	vm_res_node_t res_node;
	vm_phb_callback_type callback;
	 
	phb_add_t *    phb_add = NULL;
	phb_delete_t * phb_delete = NULL;
	phb_update_t * phb_update = NULL;
	phb_search_t * phb_search = NULL;
	phb_get_contact_t * phb_get_contact = NULL;
	 
	VMINT * data_buffer = NULL;
	VMINT phbresult = -1;
  
	vm_log_debug("vm_phb_callback_manager:reault =%d",result );
	switch(result)
	{
		case SRV_PHB_NAME_MODIFIED:
			phbresult = VM_PHB_NAME_MODIFIED;
			break;

		case SRV_PHB_NO_ERROR:
		 	phbresult = VM_PHB_NO_ERROR;
			break;

		case SRV_PHB_ERROR :
			phbresult = VM_PHB_ERROR;
			break;

		case SRV_PHB_NOT_READY:
			phbresult = VM_PHB_NOT_READY;
			break;

		case SRV_PHB_NUM_NOT_READY:
			phbresult = VM_PHB_NUM_NOT_READY;
			break;

		case SRV_PHB_NOT_SUPPORT:
			phbresult = VM_PHB_NOT_SUPPORT;
			break;
		
		case SRV_PHB_NOT_FOUND:
			phbresult = VM_PHB_NOT_FOUND;
			break;

		case SRV_PHB_DATAMGR_BUSY:
			phbresult = VM_PHB_DATAMGR_BUSY;
			break;

		case SRV_PHB_STORAGE_FULL:
			phbresult = VM_PHB_STORAGE_FULL;
			break;
		
		case SRV_PHB_NO_SIM_CARD:
			phbresult = VM_PHB_NO_SIM_CARD;
			break;

		case SRV_PHB_ADN_FORBID:
			phbresult = VM_PHB_ADN_FORBID;
			break;

		case SRV_PHB_OUT_OF_INDEX:
			phbresult = VM_PHB_OUT_OF_INDEX;
			break;

		case SRV_PHB_NUMBER_TOO_LONG:
			phbresult = VM_PHB_NUMBER_TOO_LONG;
			break;
		 
		case SRV_PHB_BIRTHDAY_ERROR:
			phbresult = VM_PHB_BIRTHDAY_ERROR;
			break;

		default:
			phbresult = VM_PHB_ERROR;
			break;

	}
	   
     	  
	res = vm_res_get_data_list_by_type(VM_RES_TYPE_PHONE_BOOK, &res_node, 1);
	  
	vm_log_debug("vm_phb_callback_manager:res=%d count = %d", res, vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK));
	 
	if(res <= 0)
	{
		vm_log_debug("vm_phb_callback_manager:res <= 0");
		return;
	}
	data_handle = res_node.res_id;
	  
	if(phb_process_handle == res_node.phandle)
	{
		if (vm_pmng_set_ctx(res_node.phandle) == VM_PMNG_OP_OK)
		{
			vm_log_debug("vm_phb_callback_manager:phandle=%d, result=%d", res_node.phandle, result);
			vm_res_get_callback(VM_RES_TYPE_PHONE_BOOK, data_handle, (void * * )&callback);
			//callback(phbresult, user_phb_contact);
	   
			data_buffer = (VMINT * )res_node.data_content;
	
			vm_log_debug("vm_phb_callback_manager:type=%d",data_buffer[0]);   
			switch(data_buffer[0])
			{
	          
				case VM_PHB_ADD:
					phb_add = (phb_add_t *)res_node.data_content;
					vm_phb_build_contact_ptr(phb_add->req_info->contact_ptr , contact_ptr);
					if(callback != NULL)
					callback(phbresult, phb_add->req_info->contact_ptr);
					vm_free(phb_add->req_info);
					vm_log_debug("vm_phb_callback_manager:VM_PHB_ADD");   	
					break;

				case VM_PHB_DELETE:
					phb_delete = (phb_delete_t *)res_node.data_content;
					if(callback != NULL)
					callback(phbresult, NULL);
					vm_free(phb_delete->req_info);
					vm_log_debug("vm_phb_callback_manager:VM_PHB_DELETE");   
					break;

				case VM_PHB_UPDATE:
					phb_update = (phb_update_t *)res_node.data_content;
					vm_phb_build_contact_ptr(phb_update->req_info->contact_ptr , contact_ptr);
					if(callback != NULL)

						callback(phbresult, phb_update->req_info->contact_ptr);
					vm_free(phb_update->req_info);
					vm_log_debug("vm_phb_callback_manager:VM_PHB_UPDATE");   
					break;

				case VM_PHB_SEARCH:
					phb_search = (phb_search_t *)res_node.data_content;
					vm_phb_build_contact_ptr(phb_search->req_info->contact_ptr , contact_ptr);
					if(callback != NULL)
						callback(phbresult, phb_search->req_info->contact_ptr);
					vm_free(phb_search->req_info);
					vm_log_debug("vm_phb_callback_manager:VM_PHB_SEARCH"); 
					break;

				case VM_PHB_GET_CONTACT:
					phb_get_contact = (phb_get_contact_t *)res_node.data_content;
					vm_phb_build_contact_ptr(phb_get_contact->req_info->contact_ptr , contact_ptr);
					if(callback != NULL)
						callback(phbresult, phb_get_contact->req_info->contact_ptr);
					vm_free(phb_get_contact->req_info);
					vm_log_debug("vm_phb_callback_manager:VM_PHB_GET_CONTACT"); 
					break;
	     
       
				default:
					vm_log_debug("vm_phb_callback_manager:type=%d error",data_buffer[0]);  
					break;
			}
		 
	       
			if(res_node.data_content)
				vm_free(res_node.data_content);

			vm_log_debug("vm_phb_callback_manager: vm_free(&res_node.data_content)");    
	   
			i= vm_res_release_data(VM_RES_TYPE_PHONE_BOOK,  data_handle); 
			if(i < 0)
			{
				vm_log_error("vm_phb_callback_manager:vm_res_release_data fail");
			}
         	 
			vm_log_debug("vm_phb_callback_manager:release_data i=%d",i); 
		
		   
			vm_pmng_reset_ctx();     
	   
		}
			  
	}

	vm_log_debug("vm_phb_callback_manager:count=%d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK) );
	if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK) > 0 )
	{
		vm_res_get_data_list_by_type(VM_RES_TYPE_PHONE_BOOK, &res_node, 1);
		if (vm_pmng_set_ctx(res_node.phandle) == VM_PMNG_OP_OK)
		{
			vm_create_timer(100, (VM_TIMERPROC_T)vm_phb_queue_manager);	
	       phb_process_handle = -1;				   
	       vm_pmng_reset_ctx();     
		}
	}
	   
    phb_busy_flag = 0;

    vm_log_debug("vm_phb_callback_manager:vm_phb_callback_manager end");   	
}


static VMINT vm_phb_common_check(vm_phb_storage_loc_enum storage)
{
    VMINT pid;
	  
	if(storage && vm_phb_storage_is_valid(storage) != VM_PHB_REQ_NO_ERROR)
	{
		vm_log_error("vm_phb_add_contact:vm_phb_storage_is_not_valid");
		return 0;
	}
	   
    if(!srv_phb_sdk_is_phb_ready())
    {
        vm_log_error("srv_phb_sdk_is_phb_not_ready");
        return 0;
    }
    
	pid = vm_pmng_get_current_handle();
	if(pid <=0)
		return 0;	
      	   
	if(vm_res_type_avaliable_handle(VM_RES_TYPE_PHONE_BOOK, pid) <= 0)
	{
		vm_log_error("vm_phb_add_contact : avaliable <= 0");
		return 0;	   
	}
	return 1;
}

vm_phb_req_error_enum vm_phb_add_contact(vm_phb_add_req_struct* req_info,  vm_phb_callback_type cb)
{
	phb_add_t * phb_add = NULL;
	vm_phb_add_req_struct *req_info_ptr = NULL;
	VMINT avaliable = -1;
	VMINT data_handle = -1;
  		 
    if(req_info == NULL || req_info->contact_ptr == NULL)
    {
        vm_log_error("vm_phb_add_contact:req_info == NULL");
        return VM_PHB_REQ_ERROR;
    }
    
	
	if(req_info->storage == VM_PHB_STORAGE_LOC_BOTH)
	{
		vm_log_error("vm_phb_add_contact:VM_PHB_STORAGE_LOC_BOTH");
		return VM_PHB_REQ_ERROR;
	}
	   
	if((vm_wstrlen((VMWSTR)req_info->contact_ptr->name) == 0) && (vm_wstrlen((VMWSTR)req_info->contact_ptr->number) == 0))
	{
		vm_log_error("vm_phb_add_contact:name or number is NULL");
		return VM_PHB_REQ_ERROR;
	}  	

	if (!vm_phb_common_check(req_info->storage))
	{
	    return VM_PHB_REQ_ERROR;
	}

	req_info_ptr = vm_calloc(sizeof(vm_phb_add_req_struct));
	if(req_info_ptr == NULL)
	{
		vm_log_error("vm_phb_add_contact:req_info_ptr == NULL");
		return VM_PHB_REQ_ERROR;
	}
	
	phb_add = vm_calloc(sizeof(phb_add_t));
	if(phb_add == NULL)
	{
		vm_free(req_info_ptr);
		vm_log_error("vm_phb_add_contact:phb_add == NULL");
		return VM_PHB_REQ_ERROR;
	}
	req_info_ptr->contact_ptr = req_info->contact_ptr;
	req_info_ptr->storage = req_info->storage;
	phb_add->operation_type = VM_PHB_ADD;
	phb_add->req_info = req_info_ptr;
	phb_add->cb = cb;
	
	if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK) == 0 )
	{
		vm_create_timer(100, (VM_TIMERPROC_T)vm_phb_queue_manager);	
	}
	
	data_handle = vm_res_save_data(VM_RES_TYPE_PHONE_BOOK, phb_add,  sizeof(phb_add_t), (void *)cb, vm_pmng_get_current_handle());
	if(data_handle < 0)
       {
		vm_log_error("vm_phb_add_contact data_handle < 0");
		vm_free(req_info_ptr);
		vm_free(phb_add);
		return VM_PHB_REQ_ERROR;
	}
	vm_log_debug("vm_phb_add_contact count = %d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK));
  	
	return VM_PHB_REQ_NO_ERROR;
	   
}


vm_phb_req_error_enum vm_phb_delete_contact(vm_phb_delete_req_struct* req_info,   vm_phb_callback_type cb)
{
    phb_delete_t * phb_delete = NULL;
    vm_phb_delete_req_struct * req_info_ptr = NULL;
    VMINT avaliable = -1;
    VMINT data_handle = -1;
   
	if(req_info == NULL)
    {
		vm_log_error("vm_phb_delete_contact:req_info == NULL");
		return VM_PHB_REQ_ERROR;
	}

	if(req_info->pos.storage == VM_PHB_STORAGE_LOC_BOTH)
	{
		vm_log_error("vm_phb_delete_contact:VM_PHB_STORAGE_LOC_BOTH");
		return VM_PHB_REQ_ERROR;
	}
	
	if (!vm_phb_common_check(req_info->pos.storage))
	{
	    return VM_PHB_REQ_ERROR;
	}
	
	req_info_ptr = vm_calloc(sizeof(vm_phb_delete_req_struct));
	if(req_info_ptr == NULL)
	{
		vm_log_error("vm_phb_delete_contact:req_info_ptr == NULL");
		return VM_PHB_REQ_ERROR;
	}
	phb_delete = vm_calloc(sizeof(phb_delete_t));
	if( phb_delete == NULL)
	{
		vm_free(req_info_ptr);
		vm_log_error("vm_phb_delete_contact:phb_delete == NULL");
		return VM_PHB_REQ_ERROR;
    }
	
	req_info_ptr->pos = req_info->pos;
	phb_delete->operation_type = VM_PHB_DELETE;
	phb_delete->req_info = req_info_ptr;
	phb_delete->cb = cb;

	if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK) == 0 )
	{
		vm_create_timer(100, (VM_TIMERPROC_T)vm_phb_queue_manager);
	}
	 
	data_handle = vm_res_save_data(VM_RES_TYPE_PHONE_BOOK, phb_delete,  sizeof(phb_delete_t), (void *)cb, vm_pmng_get_current_handle());
	if(data_handle < 0)
	{
		vm_log_error("vm_phb_delete_contact data_handle < 0");
		vm_free(req_info_ptr);
		vm_free(phb_delete);
		return VM_PHB_REQ_ERROR;
	}
	vm_log_debug("vm_phb_delete_contact count = %d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK));
	
	return VM_PHB_REQ_NO_ERROR;
	   

}

vm_phb_req_error_enum vm_phb_update_contact(vm_phb_update_req_struct* req_info,  vm_phb_callback_type cb)
{
	phb_update_t * phb_update = NULL;
	vm_phb_update_req_struct * req_info_ptr =NULL;
	VMINT avaliable = -1;
	VMINT data_handle = -1;
	
	if(req_info == NULL || req_info->contact_ptr == NULL)
	{
		vm_log_error("vm_phb_update_contact :req_info == NULL,req_info->contact_ptr == NULL");
		return VM_PHB_REQ_ERROR;
	}

	if(req_info->pos.storage == VM_PHB_STORAGE_LOC_BOTH)
	{
		vm_log_error("vm_phb_update_contact:VM_PHB_STORAGE_LOC_BOTH");
		return VM_PHB_REQ_ERROR;
    } 

	if((vm_wstrlen((VMWSTR)req_info->contact_ptr->name) == 0) && (vm_wstrlen((VMWSTR)req_info->contact_ptr->number) == 0))
	{
		vm_log_error("vm_phb_update_contact:name or number is NULL");
		return VM_PHB_REQ_ERROR;
    }  	

	if (!vm_phb_common_check(req_info->pos.storage))
	{
	    return VM_PHB_REQ_ERROR;
	}
	
    req_info_ptr = vm_calloc(sizeof(vm_phb_update_req_struct));
	if(req_info_ptr == NULL)
	{
		vm_log_error("vm_phb_update_contact:req_info_ptr == NULL");
		return VM_PHB_REQ_ERROR;
    }

    phb_update = vm_calloc(sizeof(phb_update_t));
	if(phb_update == NULL)
	{
		vm_free(req_info_ptr);
		vm_log_error("vm_phb_update_contact:phb_update == NULL");
		return VM_PHB_REQ_ERROR;
    }
	
	req_info_ptr->contact_ptr = req_info->contact_ptr;
	req_info_ptr->pos = req_info->pos;
    phb_update->operation_type = VM_PHB_UPDATE;
	phb_update->req_info = req_info_ptr;
	phb_update->cb = cb;

	if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK) == 0 )
	{
		vm_create_timer(100, (VM_TIMERPROC_T)vm_phb_queue_manager);	
	}
	 
	data_handle = vm_res_save_data(VM_RES_TYPE_PHONE_BOOK, phb_update,  sizeof(phb_update_t), (void *)cb, vm_pmng_get_current_handle());
	if(data_handle < 0)
	{
		vm_log_error("vm_phb_update_contact data_handle < 0");
		vm_free(req_info_ptr);
		vm_free(phb_update);
		return VM_PHB_REQ_ERROR;
	}
	vm_log_debug("vm_phb_update_contact count = %d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK));
	
	return VM_PHB_REQ_NO_ERROR;

}


vm_phb_req_error_enum vm_phb_search_contact(vm_phb_search_req_struct* req_info,   vm_phb_callback_type cb)
{
	phb_search_t * phb_search = NULL;
	vm_phb_search_req_struct * req_info_ptr = NULL;
	VMINT avaliable = -1;
	VMINT data_handle = -1;
	
	if(req_info == NULL || req_info->contact_ptr == NULL)
	{
		vm_log_error("vm_phb_search_contact:req_info == NULL");
		return VM_PHB_REQ_ERROR;
    }

	if (!vm_phb_common_check(0))
	{
	    return VM_PHB_REQ_ERROR;
	}
	
	req_info_ptr = vm_calloc(sizeof(vm_phb_search_req_struct));
	if(req_info_ptr == NULL)
	{
		vm_log_error("vm_phb_search_contact:req_info_ptr == NULL");
		return VM_PHB_REQ_ERROR;
    }
    
	phb_search = vm_calloc(sizeof(phb_search_t));
	if(!phb_search)
	{
		vm_free(req_info_ptr);
		vm_log_error("vm_phb_search_contact:phb_search == NULL");
		return VM_PHB_REQ_ERROR;
	}
	
	req_info_ptr->contact_ptr = req_info->contact_ptr;
	req_info_ptr->search_type = req_info->search_type;
	vm_wstrncpy(req_info_ptr->pattern_ucs2, req_info->pattern_ucs2, VM_PHB_MAX_SEARCH_LENGTH-1);
	phb_search->operation_type = VM_PHB_SEARCH;
	phb_search->req_info = req_info_ptr;
	phb_search->cb = cb;

	if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK) == 0 )
	{
		vm_create_timer(100, (VM_TIMERPROC_T)vm_phb_queue_manager);	
	}
	 
	data_handle = vm_res_save_data(VM_RES_TYPE_PHONE_BOOK, phb_search,  sizeof(phb_search_t), (void *)cb, vm_pmng_get_current_handle());
	if(data_handle < 0)
	{
		vm_log_error("vm_phb_search_contact data_handle < 0");
		vm_free(req_info_ptr);
		vm_free(phb_search);
		return VM_PHB_REQ_ERROR;
	}
	vm_log_debug("vm_phb_search_contact count = %d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK));
		
	return VM_PHB_REQ_NO_ERROR;
}


vm_phb_req_error_enum vm_phb_get_contact(vm_phb_get_req_struct* req_info,    vm_phb_callback_type cb)
{
	phb_get_contact_t * phb_get_contact = NULL;
	vm_phb_get_req_struct * req_info_ptr = NULL;
	VMINT avaliable = -1;
	VMINT data_handle = -1;
	
	if(req_info == NULL || req_info->contact_ptr == NULL)
	{
		vm_log_error("vm_phb_get_contact:req_info == NULL");
		return VM_PHB_REQ_ERROR;
	}
    
	if(req_info->pos.storage == VM_PHB_STORAGE_LOC_BOTH)
	{
		vm_log_error("vm_phb_get_contact:VM_PHB_STORAGE_LOC_BOTH");
		return VM_PHB_REQ_ERROR;
      	}
	   
	if (!vm_phb_common_check(0))
	{
	    return VM_PHB_REQ_ERROR;
	}
	
	req_info_ptr = vm_calloc(sizeof(vm_phb_get_req_struct));
	if(req_info_ptr == NULL)
	{
		vm_log_error("vm_phb_get_contact:req_info_ptr == NULL");
		return VM_PHB_REQ_ERROR;
    }
    
    phb_get_contact = vm_calloc(sizeof(phb_get_contact_t));
	if(phb_get_contact == NULL)
	{
		vm_free(req_info_ptr);
		vm_log_error("vm_phb_get_contact:phb_get_contact == NULL");
		return VM_PHB_REQ_ERROR;
    }
	
	req_info_ptr->contact_ptr = req_info->contact_ptr;
	req_info_ptr->pos = req_info->pos;
	phb_get_contact->operation_type = VM_PHB_GET_CONTACT;
	phb_get_contact->req_info = req_info_ptr;
	phb_get_contact->cb = cb;

	if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK) == 0 )
	{
		vm_create_timer(100, (VM_TIMERPROC_T)vm_phb_queue_manager);		
	}
	
	data_handle = vm_res_save_data(VM_RES_TYPE_PHONE_BOOK, phb_get_contact,  sizeof(phb_get_contact_t), (void *)cb, vm_pmng_get_current_handle());
	if(data_handle < 0)
    {
		vm_log_error("vm_phb_get_contact data_handle < 0");
		vm_free(req_info_ptr);
		vm_free(phb_get_contact);
		return VM_PHB_REQ_ERROR;
	}
	vm_log_debug("vm_phb_get_contact count = %d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK));	

	return VM_PHB_REQ_NO_ERROR;
}

vm_phb_req_error_enum vm_phb_search_contact_syn(vm_phb_search_req_struct* req_info)
{
	vm_phb_req_error_enum res = VM_PHB_REQ_ERROR;
	
	if(req_info == NULL || req_info->contact_ptr == NULL)
	{
		vm_log_error("vm_phb_search_contact_syn:req_info == NULL");
		return VM_PHB_REQ_ERROR;
    }
	
	res = vm_sal_phb_search_contact_syn(req_info);
	
	vm_log_debug("vm_phb_search_contact_syn:end");	
    return res;
}

vm_phb_req_error_enum vm_phb_get_contact_syn(vm_phb_get_req_struct* req_info)
{
	vm_phb_req_error_enum res = VM_PHB_REQ_ERROR;
	
	
	if(req_info == NULL || req_info->contact_ptr == NULL)
	{
		vm_log_error("vm_phb_get_contact_syn:req_info == NULL");
		return VM_PHB_REQ_ERROR;
	}

    if(vm_phb_storage_is_valid(req_info->pos.storage) != VM_PHB_REQ_NO_ERROR)
	{
		return VM_PHB_REQ_ERROR;
	}
    
	if(req_info->pos.storage == VM_PHB_STORAGE_LOC_BOTH)
	{
		vm_log_error("vm_phb_get_contact_syn:VM_PHB_STORAGE_LOC_BOTH");
		return VM_PHB_REQ_ERROR;
    }
    
	res = vm_sal_phb_get_contact_syn(req_info);

	vm_log_debug("vm_phb_get_contact_syn:end");  
	
       return res;

}



VMINT vm_phb_get_total_contacts(vm_phb_storage_loc_enum storage)
{
	VMINT res = VM_PHB_REQ_ERROR;
       
	if(vm_phb_storage_is_valid(storage) != VM_PHB_REQ_NO_ERROR)
	{
		vm_log_error("vm_phb_get_total_contacts:vm_phb_storage_is_not_valid");
		return VM_PHB_REQ_ERROR;
	}

	res = vm_sal_phb_get_total_contacts(storage);
	    
	vm_log_debug("vm_phb_get_total_contacts:res=%d", res);
	return res;

}


VMINT vm_phb_get_used_contacts_count(vm_phb_storage_loc_enum storage)
{

	VMINT res = VM_PHB_REQ_ERROR;
    
	if(vm_phb_storage_is_valid(storage) != VM_PHB_REQ_NO_ERROR)
	{
		vm_log_error("vm_phb_get_used_contacts_count:vm_phb_storage_is_not_valid");
		return VM_PHB_REQ_ERROR;
	}
	res = vm_sal_phb_get_used_contacts_count(storage);
	vm_log_debug("vm_phb_get_used_contacts_count:res = %d", res);
	  
	return res;
        
}


VMINT vm_phb_get_used_contacts(vm_phb_contact_pos_struct* pos_array,  vm_phb_storage_loc_enum storage)
{
	VMINT res = VM_PHB_REQ_ERROR;

	if(vm_phb_storage_is_valid(storage) != VM_PHB_REQ_NO_ERROR)
    {
        vm_log_error("vm_phb_get_used_contacts:vm_phb_storage_is_not_valid");
        return VM_PHB_REQ_ERROR;
    }
 	  
	res = vm_sal_phb_get_used_contacts(pos_array, storage);

	vm_log_debug("vm_phb_get_used_contacts:res = %d", res);
	return res;        
}


VMINT vm_phb_search_contact_list(vm_phb_search_list_req_struct* req_info, vm_phb_contact_pos_struct* pos_array, VMINT post_array_len)
{
	VMINT search_num = 0;

	if(req_info == NULL ||pos_array ==NULL||post_array_len<0)
	{
		vm_log_error("vm_phb_search_contact_list:req_info == NULL");
		return VM_PHB_REQ_ERROR;
	}
	 
	vm_log_debug("req_info->search_type=%d",req_info->search_type);
	search_num = vm_sal_phb_search_contact_list(req_info, pos_array, post_array_len); 
		 
	vm_log_debug("vm_phb_search_contact_list:search_num= %d",search_num);
	
	return search_num;     
}


VMINT vm_phb_get_group_list_count(void)
{
	VMINT group_count = 0;
		 
	group_count = vm_sal_phb_get_group_list_count(); 
 
	vm_log_debug("vm_phb_get_group_list_count:group_count = %d", group_count);
		
	return group_count;	 
}

VMINT vm_phb_get_group_list(vm_phb_group_struct* group_array, VMINT  group_array_len)
{  
    VMINT len = 0;
    	
    len = vm_sal_phb_get_group_list(group_array, group_array_len);

    vm_log_debug("vm_phb_get_group_list:len = %d", len);

    return len;
}


VMINT vm_phb_get_group_name_by_id(VMUINT group_id, VMWCHAR*  group_name, VMINT len)
{   
    VMINT res = FALSE;

    if(group_name==NULL || len <= 0)
    {
        vm_log_error("vm_phb_get_group_name_by_id:group_name==NULL || len <= 0");
        return FALSE;	
    }

    res = vm_sal_phb_get_group_name_by_id(group_id, group_name, len);

    vm_log_debug("vm_phb_get_group_name_by_id:res= %d", res);

    return res;  
}



static VMINT vm_phb_storage_is_valid(vm_phb_storage_loc_enum storage)
{
    VMINT count = vm_sim_max_card_count();

	if(storage < VM_PHB_STORAGE_LOC_SIM ||storage >VM_PHB_STORAGE_LOC_BOTH)
	{
		vm_log_error("vm_phb_storage_is_valid:storage is not valid");
		return VM_PHB_REQ_ERROR;
	}
    
    switch (storage)
    {
    case  VM_PHB_STORAGE_LOC_SIM2:
        if (count < 2)
        {
            return VM_PHB_REQ_ERROR;
        }
        break;
    case  VM_PHB_STORAGE_LOC_SIM3:
        if (count < 3)
        {
            return VM_PHB_REQ_ERROR;
        }
        break;
    case  VM_PHB_STORAGE_LOC_SIM4:
        if (count < 4)
        {
            return VM_PHB_REQ_ERROR;
        }
        break;
    default:
        break;
    }
	return VM_PHB_REQ_NO_ERROR;
}


#endif //__MRE_SAL_PHONEBOOK__
