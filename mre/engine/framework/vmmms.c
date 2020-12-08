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
 * Vmmms.c
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
#ifdef __MRE_SAL_MMS__
#include "mmi_features.h"
#include "string.h"
#include "stdlib.h"
#include "vmlog.h"
#include "vmsys.h"
#include "vmtimer.h"
#include "vmsim.h"
#include "vmmod.h"
#include "vmresmng.h"
#include "vmpromng.h"
#include "vmsalmms.h"
#include "vmmms.h"
#include "vmchset.h"
#include "vmio.h"
#include "vmxml.h"
#include "vmpromnginner.h"

#include "globalresdef.h"
#include "mmi_frm_utility_gprot.h"
#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_uc_gprot.h"
#else
#include "UcAppGprot.h"
#endif
#include "mmssrvgprot.h"
#include "umsrvgprot.h"
#ifndef __MTK_TARGET__
#define _VM_MMS_XML_
#endif
#define REG_MMS_MODULE_FAILED  (-2)
#define VM_MMS_MILLISEC	(1000)
#define VM_MMS_XML_FILE_LEN (100)
/* ------------------------------------------------------------------------ */
/* 模块内部变量定义。                                                                             */
/* ------------------------------------------------------------------------ */
/**
 * 是否有彩信正在发送标志。
 */
static VMINT s_vm_mms_is_busy = FALSE;

/* ------------------------------------------------------------------------ */
/* 模块内部函数声明。                                                                             */
/* ------------------------------------------------------------------------ */
/**
 * MMS模块的回调函数。
 *
 * @param event	系统事件。
 *
 * @return	0表示成功，REG_MMS_MODULE_FAILED表示失败。
 */
static VMINT vm_mms_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event);

/**
 * 初始化MMS模块。
 */
static void vm_mms_modual_initialize(void);

/**
 * 停止MMS模块。
 */
static void vm_mms_modual_finialize(void);

/**
 * MMS进程状态处理函数。
 *
 * @param process_handle	进程ID。
 * @param sys_state	系统状态。
 */
static void  vm_mms_release_callback(VM_P_HANDLE process_handle, VMINT sys_state);

/**
 * MMS发送队列处理函数。
 * 
 * @param tid		定时器ID。
 */
static void vm_mms_queue_manager(VMINT tid);

/**
 * MMS发送的回调函数。
 *
 * @param	操作结果，参考vm_mms_result_enum。
 */
static void vm_mms_send_mms_callback(VMINT result);

/**
 * 删除进程使用的CELL资源。
 *
 * @param process_handle 进程ID号。
 */
static void vm_mms_delete_cur_process_res(VM_P_HANDLE process_handle);

#ifdef _VM_MMS_XML_
static VMINT vm_mms_string_is_number_value(const VMSTR string);
static VMINT vm_mms_string_is_color_value(const VMSTR string);
static VMINT vm_mms_xml_is_valid(VMSTR filepath);
static VMINT vm_mms_xml_parser(VMSTR filepath);
static void vm_mms_xml_elem_start_callback(void* data, const VMSTR el, const VMSTR* attr, VMINT error);
static void vm_mms_xml_elem_end_callback(void* data, const VMSTR el, VMINT error);
static void vm_mms_xml_data_callback(void* resv,const VMSTR el,const VMSTR data,VMINT len,VMINT error);
static VMINT _vm_mms_clear_interrupt_event_handler(VM_P_HANDLE handle);
static VMINT s_vm_mms_xml_is_valid = TRUE;
static VMCHAR s_vm_mms_xml_type_value[2];
static VMINT s_vm_mms_xml_slidenum = 0;
static VMINT s_vm_mms_xml_slidecount = 0;
static VMCHAR* s_vm_mms_xml_filepath = NULL;
static VMCHAR* s_vm_mms_xml_name = NULL;
static VMINT s_vm_mms_xml_objnum;
static VMINT s_vm_mms_xml_objcount;
static VMINT s_vm_mms_xml_parser_is_busy = FALSE;
#endif
/* ------------------------------------------------------------------------ */
/* 模块内部函数实现。                                                                              */
/* ------------------------------------------------------------------------ */
/**
 * MMS模块注册函数。
 *
 * @return 	返回0表示成功，否则返回错误码。
 */
VMINT _vm_reg_mms_modual(void)
{
	int res = 0;
	
	if ((res = _vm_reg_module("MMS MODUAL", (MOD_EVT_PROCESS)vm_mms_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
	{
		vm_log_error("Failed to regisiter mms modual. Error Code : %d", res);
	}
	return res;
}

static VMINT vm_mms_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
	switch(event)
	{
	case EVT_MOD_INIT:
		vm_mms_modual_initialize();
		break;
	case EVT_MOD_RELEASE:
		vm_mms_modual_finialize();
		break;
	default:
		vm_log_error("{MMS MODUAL}Receive unkown [%d] event.", event);
		return REG_MMS_MODULE_FAILED;
	}

	return REG_MRE_MODULE_SUCCESS;
}

static void vm_mms_modual_initialize(void)
{
	vm_sal_mms_modual_initialize();
	vm_res_type_set_notify_callback(VM_RES_TYPE_MMS_HANDLE,  vm_mms_release_callback);
}

static void vm_mms_modual_finialize(void)
{
	vm_sal_mms_modual_finialize();
	vm_res_type_set_notify_callback(VM_RES_TYPE_MMS_HANDLE,  NULL);
}

static void  vm_mms_release_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
	switch(sys_state)
	{
		case VM_PMNG_UNLOAD:
		    _vm_mms_clear_interrupt_event_handler(process_handle);
		case VM_PMNG_BACKGROUND:
			vm_sal_mms_cancel_send_mms();
			vm_mms_delete_cur_process_res(process_handle);
			s_vm_mms_is_busy = FALSE; 
			break;
		default:
			break;
	}
}


VMINT vm_mms_send_mms(vm_send_mms_req_t * req_ptr,  vm_mms_callback_type callback)
{
	VMFILE file;
	VMINT sim_card_result;
	vm_send_mms_req_t * mms_send_ptr = NULL;
#ifdef _VM_MMS_XML_	
	VMCHAR* filepath = NULL;
#endif	
	VMINT xml_result;

	if( req_ptr == NULL)
	{
		vm_log_error("vm_mms_send_mms: req_ptr is null");
		return FALSE;
	}

	file = vm_file_open((VMWSTR)(req_ptr->xml_filepath), MODE_READ, FALSE);
	if(file < 0)
	{
		vm_log_error("vm_mms_send_mms:file = %d",file);
		vm_file_close(file);
		return FALSE;
	}
	vm_file_close(file);

	sim_card_result = vm_get_sim_card_status(req_ptr->sim_id);
	vm_log_debug("vm_mms_send_mms:sim_card_result = %d",sim_card_result);
	if(sim_card_result != VM_SIM_STATE_WORKING)
	{
		vm_log_error("vm_mms_send_mms:vm_mms_sim_is_not_valid");
		return FALSE;
	}

	if((req_ptr->mms_type != VM_MMS_TYPE_SMIL_MMS) && (req_ptr->mms_type != VM_MMS_TYPE_MIXED_MMS))
	{
		vm_log_error("vm_mms_send_mms:req_ptr->mms_type = %d",req_ptr->mms_type);
		return FALSE;
	}

#ifdef _VM_MMS_XML_
	filepath = vm_calloc(VM_MMS_XML_FILE_LEN);
	if(filepath == NULL)
	{
		vm_log_error("vm_mms_send_mms:filepath calloc failed");
		return FALSE;
	}
	//vm_ucs2_to_gb2312((VMSTR)filepath, VM_MMS_XML_FILE_LEN, (VMWSTR)req_ptr->xml_filepath);
	vm_ucs2_to_ascii((VMSTR)filepath, VM_MMS_XML_FILE_LEN, (VMWSTR)req_ptr->xml_filepath);
	xml_result = vm_mms_xml_is_valid(filepath);
	vm_free(filepath);
	if(!xml_result)
	{
		vm_log_error("vm_mms_send_mms:xml is not valid");
		return FALSE;
	}
#endif	

	if(vm_res_type_avaliable_handle(VM_RES_TYPE_MMS_HANDLE, vm_pmng_get_current_handle()) <= 0)
	{
		vm_log_error("vm_mms_send_mms:res_avaliable <= 0");
		return FALSE;
	}

	mms_send_ptr = vm_calloc(sizeof(vm_send_mms_req_t));
	if(mms_send_ptr == NULL)
	{
	    vm_log_error("vm_mms_send_mms : calloc mem failed");
	    return FALSE;
	}

	memcpy(mms_send_ptr, req_ptr, sizeof(vm_send_mms_req_t));
	vm_log_debug("vm_mms_send_mms:mms_send_ptr->sim_id = %d",mms_send_ptr->sim_id);

	if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_MMS_HANDLE) == 0)
	{
	   
	     if(vm_create_timer(VM_MMS_MILLISEC, (VM_TIMERPROC_T)vm_mms_queue_manager) < 0)
            {
                vm_log_error("vm_mms_send_mms:create  timer fail!");
            }
	}
	
	if(vm_res_save_data(VM_RES_TYPE_MMS_HANDLE,mms_send_ptr, sizeof(vm_send_mms_req_t),(void *)callback, vm_pmng_get_current_handle()) < 0)
	{
		vm_log_error("vm_mms_send_mms: vm_res_save_data fail!");
		vm_free(mms_send_ptr);
		return FALSE;
	}
	vm_log_debug("vm_mms_send_mms:count = %d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_MMS_HANDLE));
	return TRUE;
}

static void vm_mms_queue_manager(VMINT tid)
{
	VMINT res;
	VMINT sal_send_result;
	vm_res_node_t   res_node;
	vm_send_mms_req_t* mms_send_ptr;
	
	vm_log_debug("vm_mms_queue_manager: tid=%d", tid);
    if(tid >=0)
    {
        vm_delete_timer(tid);
        }

	if(s_vm_mms_is_busy)
	{
		vm_log_error("vm_mms_queue_manager:s_vm_mms_is_busy == TRUE");
		return;
	}

	res = vm_res_get_data_list_by_type(VM_RES_TYPE_MMS_HANDLE, &res_node, 1);
	if(res <= 0)
	 {
	        vm_log_error("vm_mms_queue_manager:vm_res_get_data fail!");
	        return;
	 }
	s_vm_mms_is_busy = TRUE;

	mms_send_ptr = (vm_send_mms_req_t *)res_node.data_content;

	vm_log_debug("vm_mms_queue_manager:vm_sal_mms_send_mms");

	if((sal_send_result = vm_sal_mms_send_mms(mms_send_ptr, vm_mms_send_mms_callback)) < 0)
	{
		vm_log_error("vm_mms_queue_manager:sal_send_result = %d",sal_send_result);
		vm_mms_send_mms_callback(VM_MMS_FAIL);
	}
}

static void vm_mms_send_mms_callback(VMINT result)
{
	VMINT res;
	VMINT data_handle;
	vm_res_node_t   res_node;
	vm_send_mms_req_t* mms_send_ptr;
	vm_mms_callback_type user_callback = NULL;
	VMINT res_count;

	res = vm_res_get_data_list_by_type(VM_RES_TYPE_MMS_HANDLE, &res_node, 1);
	vm_log_debug("vm_mms_send_mms_callback:res=%d count = %d", res, vm_res_get_data_list_count_by_type(VM_RES_TYPE_MMS_HANDLE));

	if(res <= 0)
	{
	       vm_log_error("vm_mms_send_mms_callback:get data list fail!");
	        return;
	}

	data_handle = res_node.res_id;
	vm_log_debug("vm_mms_send_mms_callback:data_handle = %d",data_handle);
	if (vm_pmng_set_ctx(res_node.phandle) == VM_PMNG_OP_OK)
     	{
     		vm_log_debug("vm_mms_send_mms_callback:res_node.phandle=%d", res_node.phandle);
          	mms_send_ptr = res_node.data_content;

		if(vm_res_get_callback( VM_RES_TYPE_MMS_HANDLE, data_handle, (void** )&user_callback ) == 0)
		{
			if(user_callback != NULL)
			{
				vm_log_debug("vm_mms_send_mms_callback:run user_callback result= %d",result);
				user_callback(result);					
			}
		}
		
		if(mms_send_ptr != NULL)
		{
     	   		vm_free(mms_send_ptr);
		}
	   	 
        vm_log_debug("vm_mms_send_mms_callback:res_node->res_id=%d",data_handle);

        vm_res_release_data(VM_RES_TYPE_MMS_HANDLE,  data_handle); 

		res_count = vm_res_get_data_list_count_by_type(VM_RES_TYPE_MMS_HANDLE);
		if(res_count > 0 )
         	{
              	if(vm_create_timer(VM_MMS_MILLISEC, (VM_TIMERPROC_T)vm_mms_queue_manager) <0)
              	{
                 		vm_log_error("vm_mms_send_mms_callback:vm_create_timer fail!");
              	}
	  	}	
	   	s_vm_mms_is_busy = FALSE; 
	 	vm_pmng_reset_ctx();
	}
}

void vm_mms_cancel_send_mms(void)
{
	vm_sal_mms_cancel_send_mms();
	vm_mms_delete_cur_process_res(vm_pmng_get_current_handle());
       
}


#ifdef _VM_MMS_XML_

static VMINT vm_mms_xml_is_valid(VMSTR filepath)
{
	VMINT xml_result;
	
	if(!s_vm_mms_xml_parser_is_busy)
	{
		s_vm_mms_xml_is_valid = TRUE;
		s_vm_mms_xml_slidecount = 0;
		s_vm_mms_xml_objcount = 0;
		s_vm_mms_xml_slidenum = 0;
		s_vm_mms_xml_objnum = 0;
		s_vm_mms_xml_name = vm_calloc(VM_MMS_XML_FILE_LEN);
		if(s_vm_mms_xml_name == NULL)
		{
			vm_log_error("vm_mms_xml_is_valid:s_vm_mms_xml_name calloc failed");
			return FALSE;
		}
		s_vm_mms_xml_filepath = vm_calloc(VM_MMS_XML_FILE_LEN);
		if(s_vm_mms_xml_filepath == NULL)
		{
			vm_free(s_vm_mms_xml_name);
			s_vm_mms_xml_name = NULL;
			vm_log_error("vm_mms_xml_is_valid:s_vm_mms_xml_filepath calloc failed");
			return FALSE;
		}
		xml_result = vm_mms_xml_parser(filepath);
		s_vm_mms_xml_parser_is_busy = FALSE;
		vm_free(s_vm_mms_xml_name);
		vm_free(s_vm_mms_xml_filepath);
		s_vm_mms_xml_name = NULL;
		s_vm_mms_xml_filepath = NULL;
		if(!xml_result)
		{
			vm_log_error("vm_mms_xml_is_valid:xml_result = %d",xml_result);
			return FALSE;
		}
		if(!s_vm_mms_xml_is_valid)
		{
			vm_log_error("vm_mms_xml_is_valid:s_vm_mms_xml_is_valid = %d",s_vm_mms_xml_is_valid);
			return FALSE;
		}
		if(s_vm_mms_xml_slidecount != s_vm_mms_xml_slidenum)
		{
			vm_log_error("vm_mms_xml_is_valid:s_vm_mms_xml_slidecount = %d,s_vm_mms_xml_slidenum = %d",s_vm_mms_xml_slidecount,s_vm_mms_xml_slidenum);
			return FALSE;
		}
		if(s_vm_mms_xml_objcount != s_vm_mms_xml_objnum)
		{
			vm_log_error("vm_mms_xml_is_valid:s_vm_mms_xml_objcount = %d,s_vm_mms_xml_objnum = %d",s_vm_mms_xml_objcount,s_vm_mms_xml_objnum);
			return FALSE;
		}
		return TRUE;
	}
	else
	{
		vm_log_error("vm_mms_xml_is_valid:s_vm_mms_xml_parser_is_busy=%d",s_vm_mms_xml_parser_is_busy);
		return FALSE;
	}
}
static VMINT vm_mms_xml_parser(VMSTR filepath)
{
	VMCHAR 	*ret = "OK";
	VMINT 	xml_ret;
	
	VM_XML_PARSER_STRUCT parser;

	
		xml_ret = vm_xml_new_parser(&parser);
		if (VM_XML_RESULT_OK != xml_ret)
		{
			ret = vm_xml_get_error();
			vm_log_error("vm_mms_xml_parser:(new parser fail)ret = %s",ret);
			return FALSE;
		}
		s_vm_mms_xml_parser_is_busy = TRUE;

		vm_xml_set_element_handlers(&parser, 
			(XML_start_elem_hdlr)vm_mms_xml_elem_start_callback, 
			(XML_end_elem_hdlr)vm_mms_xml_elem_end_callback);
		vm_xml_set_data_handler(&parser, (XML_data_hdlr)vm_mms_xml_data_callback);

		xml_ret = vm_xml_parse(&parser, filepath, 0);
		if (VM_XML_RESULT_OK != xml_ret)
		{
			ret = vm_xml_get_error();
			vm_log_error("vm_mms_xml_parser:(parser)ret = %s",ret);
			return FALSE;
		}
		return TRUE;
}

static void vm_mms_xml_elem_start_callback(void* data, const VMSTR el, const VMSTR* attr, VMINT error)
{
	if (VM_XML_NO_ERROR != error)
    	{
    		s_vm_mms_xml_is_valid = FALSE;
		vm_log_error("vm_mms_xml_elem_start_callback:el=%s, error=%d,error_string=%s", el, error, vm_xml_get_error());
	}
	else
	{
		VMINT index = 0;

		if((!strcmp(el,"to")) || 
			(!strcmp(el,"cc")) || 
			(!strcmp(el,"bcc")) || 
			(!strcmp(el,"from")))
		{
			while ((NULL != attr[index]) && (NULL != attr[index + 1]))
			{
				if(!strcmp(attr[index],"type"))
				{
					if(strcmp(attr[index+1],"P") && strcmp(attr[index+1],"E"))
					{
						vm_log_error("vm_mms_xml_elem_start_callback:type=%s",attr[index+1]);
						s_vm_mms_xml_is_valid = FALSE;
						return;
					}
					else
					{
						strcpy(s_vm_mms_xml_type_value, attr[index + 1]);
					}
				}
				else
				{
					vm_log_error("vm_mms_xml_elem_start_callback:(to cc bcc from)no such attribute:%s",attr[index+1]);
					s_vm_mms_xml_is_valid = FALSE;
					return;
				}
				index += 2;
			}
			
		}
		else if(!strcmp(el,"meta"))
		{
			while ((NULL != attr[index]) && (NULL != attr[index + 1]))
			{
				if(!strcmp(attr[index],"name"))
				{
					vm_log_warn("vm_mms_xml_elem_start_callback:(meta)name=%s",attr[index + 1]);
				}
				else if(!strcmp(attr[index],"content"))
				{
					vm_log_warn("vm_mms_xml_elem_start_callback:(meta)content=%s",attr[index + 1]);
				}
				else
				{
					s_vm_mms_xml_is_valid = FALSE;
					vm_log_error("vm_mms_xml_elem_start_callback:(meta)no such attribute:%s",attr[index+1]);
					return;
				}
				index += 2;
			}
		}
		else if(!strcmp(el,"layout"))
		{
			while ((NULL != attr[index]) && (NULL != attr[index + 1]))
			{
				if(!strcmp(attr[index],"width"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(layout)width error:%s",attr[index + 1]);
						return;
					}
				}
				else if(!strcmp(attr[index],"height"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(layout)height error:%s",attr[index + 1]);
						return;
					}
				}
				else
				{
					s_vm_mms_xml_is_valid = FALSE;
					vm_log_error("vm_mms_xml_elem_start_callback:(layout)no such attribute:%s",attr[index+1]);
					return;
				}
				index += 2;
			}
		}
		else if(!strcmp(el,"region"))
		{
			while ((NULL != attr[index]) && (NULL != attr[index + 1]))
			{
				if(!strcmp(attr[index],"id"))
				{
					vm_log_warn("vm_mms_xml_elem_start_callback:(region)id=%s",attr[index + 1]);
				}
				else if(!strcmp(attr[index],"top"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(region)top error:%s",attr[index + 1]);
						return;
					}
				}
				else if(!strcmp(attr[index],"left"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(region)left error:%s",attr[index + 1]);
						return;
					}
				}
				else if(!strcmp(attr[index],"height"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(region)height error:%s",attr[index + 1]);
						return;
					}
				}
				else if(!strcmp(attr[index],"width"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(region)width error:%s",attr[index + 1]);
						return;
					}
				}
				else if(!strcmp(attr[index],"fit"))
				{
					if(strcmp(attr[index + 1],"0") &&
						strcmp(attr[index + 1],"1") &&
						strcmp(attr[index + 1],"2") &&
						strcmp(attr[index + 1],"3") &&
						strcmp(attr[index + 1],"4") &&
						strcmp(attr[index + 1],"5")
						)
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(region)fit error:%s",attr[index + 1]);
						return;
					}
				}
				else
				{
					s_vm_mms_xml_is_valid = FALSE;
					vm_log_error("vm_mms_xml_elem_start_callback:(region)no such attribute:%s",attr[index+1]);
					return;
				}
				index += 2;
			}
		}
		else if(!strcmp(el,"body"))
		{
			while ((NULL != attr[index]) && (NULL != attr[index + 1]))
			{
				if(!strcmp(attr[index],"bgColor"))
				{
					if(!vm_mms_string_is_color_value(attr[index + 1]))
					{
						vm_log_error("vm_mms_xml_elem_start_callback:(body)bgColor = %s",attr[index+1]);
						s_vm_mms_xml_is_valid = FALSE;
						return;
					}
				}
				else if(!strcmp(attr[index],"fgColor"))
				{
					if(!vm_mms_string_is_color_value(attr[index + 1]))
					{
						vm_log_error("vm_mms_xml_elem_start_callback:(body)fgColor = %s",attr[index+1]);
						s_vm_mms_xml_is_valid = FALSE;
						return;
					}
				}
				else if(!strcmp(attr[index],"slideNum"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(body)slideNum = %s",attr[index + 1]);
						return;
					}
					else
					{
						s_vm_mms_xml_slidenum = atoi(attr[index + 1]);
						if((s_vm_mms_xml_slidenum < 0) || (s_vm_mms_xml_slidenum > 20))
						{
							s_vm_mms_xml_is_valid = FALSE;
							vm_log_error("vm_mms_xml_elem_start_callback:(body)slideNum = %s",attr[index + 1]);
							return;
						}
					}
				}
				else if(!strcmp(attr[index],"objNum"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(body)objNum = %s",attr[index + 1]);
						return;
					}
					else
					{
						s_vm_mms_xml_objnum = atoi(attr[index + 1]);
					}
				}
				else if(!strcmp(attr[index],"layout"))
				{
					if(strcmp(attr[index + 1],"0") &&
						strcmp(attr[index + 1],"1") &&
						strcmp(attr[index + 1],"2") &&
						strcmp(attr[index + 1],"3") &&
						strcmp(attr[index + 1],"4")
						)
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(body)layout = %s",attr[index + 1]);
						return;
					}
				}
				else if(!strcmp(attr[index],"imgFit"))
				{
					if(strcmp(attr[index + 1],"0") &&
						strcmp(attr[index + 1],"1") &&
						strcmp(attr[index + 1],"2") &&
						strcmp(attr[index + 1],"3") &&
						strcmp(attr[index + 1],"4") &&
						strcmp(attr[index + 1],"5")
						)
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(body)imgFit = %s",attr[index + 1]);
						return;
					}
				}
				else if(!strcmp(attr[index],"txtFit"))
				{
					if(strcmp(attr[index + 1],"0") &&
						strcmp(attr[index + 1],"1") &&
						strcmp(attr[index + 1],"2") &&
						strcmp(attr[index + 1],"3") &&
						strcmp(attr[index + 1],"4") &&
						strcmp(attr[index + 1],"5")
						)
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(body)txtFit = %s",attr[index + 1]);
						return;
					}
				}
				else
				{
					vm_log_error("vm_mms_xml_elem_start_callback:(body)no such attribute:%s",attr[index+1]);
					s_vm_mms_xml_is_valid = FALSE;
					return;
				}
				index += 2;
			}
		}
		else if(!strcmp(el,"slide"))
		{
			s_vm_mms_xml_slidecount++;
			while ((NULL != attr[index]) && (NULL != attr[index + 1]))
			{
				if(!strcmp(attr[index],"index"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(slide)index = %s",attr[index+1]);
						return;
					}
					else
					{
						VMINT temp = atoi(attr[index + 1]);
						if((temp < 1) || (temp > 20))
						{
							s_vm_mms_xml_is_valid = FALSE;
							vm_log_error("vm_mms_xml_elem_start_callback:(slide)index = %s",attr[index+1]);
							return;
						}
					}
				}
				else if(!strcmp(attr[index],"dur"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(slide)dur = %s",attr[index+1]);
						return;
					}
					else
					{
						VMINT temp = atoi(attr[index + 1]);
						if((temp < 1) || (temp > 60))
						{
							s_vm_mms_xml_is_valid = FALSE;
							vm_log_error("vm_mms_xml_elem_start_callback:(slide)dur = %s",attr[index+1]);
							return;
						}
					}
				}
				else
				{
					vm_log_error("vm_mms_xml_elem_start_callback:(slide)no such attribute:%s",attr[index+1]);
					s_vm_mms_xml_is_valid = FALSE;
					return;
				}
				index += 2;
			}
		}
		else if(!strcmp(el,"obj"))
		{
			s_vm_mms_xml_objcount++;
			while ((NULL != attr[index]) && (NULL != attr[index + 1]))
			{
				if(!strcmp(attr[index],"id"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(obj)id = %s",attr[index+1]);
						return;
					}
					else
					{
						VMINT temp = atoi(attr[index + 1]);
						if(temp < 1)
						{
							s_vm_mms_xml_is_valid = FALSE;
							vm_log_error("vm_mms_xml_elem_start_callback:(obj)id = %s",attr[index+1]);
							return;
						}
					}
				}
				else if(!strcmp(attr[index],"attach"))
				{
					if( strcmp(attr[index + 1],"0") && strcmp(attr[index + 1],"1"))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(obj)attach = %s",attr[index+1]);
						return;
					}
				}
				else if(!strcmp(attr[index],"vf"))
				{
					if( strcmp(attr[index + 1],"0") && strcmp(attr[index + 1],"1"))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(obj)vf = %s",attr[index+1]);
						return;
					}
				}
				else if(!strcmp(attr[index],"drm"))
				{
					if( strcmp(attr[index + 1],"0") && 
						strcmp(attr[index + 1],"1") &&
						strcmp(attr[index + 1],"2") &&
						strcmp(attr[index + 1],"3") &&
						strcmp(attr[index + 1],"4") &&
						strcmp(attr[index + 1],"5") 
						)
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(obj)drm = %s",attr[index+1]);
						return;
					}
				}
				else if(!strcmp(attr[index],"size"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(obj)size = %s",attr[index+1]);
						return;
					}
					else
					{
						VMINT temp = atoi(attr[index + 1]);
						if(temp < 0)
						{
							s_vm_mms_xml_is_valid = FALSE;
							vm_log_error("vm_mms_xml_elem_start_callback:(obj)size = %s",attr[index+1]);
							return;
						}
					}
				}
				else if(!strcmp(attr[index],"offset"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(obj)offset = %s",attr[index+1]);
						return;
					}
					else
					{
						VMINT temp = atoi(attr[index + 1]);
						if(temp < 0)
						{
							s_vm_mms_xml_is_valid = FALSE;
							vm_log_error("vm_mms_xml_elem_start_callback:(obj)offset = %s",attr[index+1]);
							return;
						}
					}
				}
				else if(!strcmp(attr[index],"encoding"))
				{
					if(strcmp(attr[index + 1],"0") &&
						strcmp(attr[index + 1],"3") &&
						strcmp(attr[index + 1],"4") &&
						strcmp(attr[index + 1],"106") &&
						strcmp(attr[index + 1],"1000") &&
						strcmp(attr[index + 1],"1013") &&
						strcmp(attr[index + 1],"1014") &&
						strcmp(attr[index + 1],"1015") &&
						strcmp(attr[index + 1],"2025") &&
						strcmp(attr[index + 1],"2026")
						)
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(obj)encoding = %s",attr[index+1]);
						return;
					}
				}
				else
				{
					vm_log_error("vm_mms_xml_elem_start_callback:(obj)no such attribute:%s",attr[index+1]);
					s_vm_mms_xml_is_valid = FALSE;
					return;
				}
				index += 2;
			}
		}
		else if(!strcmp(el,"text"))
		{
			while ((NULL != attr[index]) && (NULL != attr[index + 1]))
			{
				if(!strcmp(attr[index],"id"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(text)id = %s",attr[index+1]);
						return;
					}
					else
					{
						VMINT temp = atoi(attr[index + 1]);
						if(temp < 1)
						{
							s_vm_mms_xml_is_valid = FALSE;
							vm_log_error("vm_mms_xml_elem_start_callback:(text)id = %s",attr[index+1]);
							return;
						}
					}
				}
				else if(!strcmp(attr[index],"bgColor"))
				{
					if(!vm_mms_string_is_color_value(attr[index + 1]))
					{
						vm_log_error("vm_mms_xml_elem_start_callback:(text)bgColor = %s",attr[index+1]);
						s_vm_mms_xml_is_valid = FALSE;
						return;
					}
				}
				else if(!strcmp(attr[index],"fgColor"))
				{
					if(!vm_mms_string_is_color_value(attr[index + 1]))
					{
						vm_log_error("vm_mms_xml_elem_start_callback:(text)fgColor = %s",attr[index+1]);
						s_vm_mms_xml_is_valid = FALSE;
						return;
					}
				}
				else if(!strcmp(attr[index],"txtStyle"))
				{
					if((strcmp(attr[index + 1],"0x01") != 0) && (strcmp(attr[index + 1],"0x02") != 0))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(text)txtStyle = %s",attr[index+1]);
						return;
					}
				}
				else if(!strcmp(attr[index],"txtSize"))
				{
					if(strcmp(attr[index + 1],"1") &&
						strcmp(attr[index + 1],"2") &&
						strcmp(attr[index + 1],"3")
						)
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(text)txtSize = %s",attr[index+1]);
						return;
					}
				}
				else if(!strcmp(attr[index],"begin"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(text)begin = %s",attr[index+1]);
						return;
					}
					else
					{
						VMINT temp = atoi(attr[index + 1]);
						if((temp < 0) || (temp > 59))
						{
							s_vm_mms_xml_is_valid = FALSE;
							vm_log_error("vm_mms_xml_elem_start_callback:(text)begin = %s",attr[index+1]);
							return;
						}
					}
				}
				else if(!strcmp(attr[index],"end"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(text)end = %s",attr[index+1]);
						return;
					}
					else
					{
						VMINT temp = atoi(attr[index + 1]);
						if((temp < 1) || (temp > 60) )
						{
							s_vm_mms_xml_is_valid = FALSE;
							vm_log_error("vm_mms_xml_elem_start_callback:(text)end = %s",attr[index+1]);
							return;
						}
					}
				}
				else if(!strcmp(attr[index],"alt"))
				{
					vm_log_warn("vm_mms_xml_elem_start_callback:(text)alt=%s",attr[index + 1]);
				}
				else if(!strcmp(attr[index],"region"))
				{
					vm_log_warn("vm_mms_xml_elem_start_callback:(text)region=%s",attr[index + 1]);
				}
				else
				{
					vm_log_error("vm_mms_xml_elem_start_callback:(text)no such attribute:%s",attr[index+1]);
					s_vm_mms_xml_is_valid = FALSE;
					return;
				}
				index += 2;
			}
		}
		else if(!strcmp(el,"img"))
		{
			while ((NULL != attr[index]) && (NULL != attr[index + 1]))
			{
				if(!strcmp(attr[index],"id"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(img)id = %s",attr[index+1]);
						return;
					}
					else
					{
						VMINT temp = atoi(attr[index + 1]);
						if(temp < 1)
						{
							s_vm_mms_xml_is_valid = FALSE;
							vm_log_error("vm_mms_xml_elem_start_callback:(img)id = %s",attr[index+1]);
							return;
						}
					}
				}
				else if(!strcmp(attr[index],"begin"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(img)begin = %s",attr[index+1]);
						return;
					}
					else
					{
						VMINT temp = atoi(attr[index + 1]);
						if((temp < 0) || (temp > 59) )
						{
							s_vm_mms_xml_is_valid = FALSE;
							vm_log_error("vm_mms_xml_elem_start_callback:(img)begin = %s",attr[index+1]);
							return;
						}
					}
				}
				else if(!strcmp(attr[index],"end"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(img)end = %s",attr[index+1]);
						return;
					}
					else
					{
						VMINT temp = atoi(attr[index + 1]);
						if((temp < 1) || (temp > 60) )
						{
							s_vm_mms_xml_is_valid = FALSE;
							vm_log_error("vm_mms_xml_elem_start_callback:(img)end = %s",attr[index+1]);
							return;
						}
					}
				}
				else if(!strcmp(attr[index],"alt"))
				{
					vm_log_warn("vm_mms_xml_elem_start_callback:(img)alt=%s",attr[index + 1]);
				}
				else if(!strcmp(attr[index],"region"))
				{
					vm_log_warn("vm_mms_xml_elem_start_callback:(img)region=%s",attr[index + 1]);
				}
				else
				{
					vm_log_error("vm_mms_xml_elem_start_callback:(text)no such attribute:%s",attr[index+1]);
					s_vm_mms_xml_is_valid = FALSE;
					return;
				}
				index += 2;
			}
		}
		else if(!strcmp(el,"audio"))
		{
			while ((NULL != attr[index]) && (NULL != attr[index + 1]))
			{
				if(!strcmp(attr[index],"id"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(audio)id = %s",attr[index+1]);
						return;
					}
					else
					{
						VMINT temp = atoi(attr[index + 1]);
						if(temp < 1)
						{
							s_vm_mms_xml_is_valid = FALSE;
							vm_log_error("vm_mms_xml_elem_start_callback:(audio)id = %s",attr[index+1]);
							return;
						}
					}
				}
				else if(!strcmp(attr[index],"begin"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(audio)begin = %s",attr[index+1]);
						return;
					}
					else
					{
						VMINT temp = atoi(attr[index + 1]);
						if((temp < 0) || (temp > 59) )
						{
							s_vm_mms_xml_is_valid = FALSE;
							vm_log_error("vm_mms_xml_elem_start_callback:(audio)begin = %s",attr[index+1]);
							return;
						}
					}
				}
				else if(!strcmp(attr[index],"end"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(audio)end = %s",attr[index+1]);
						return;
					}
					else
					{
						VMINT temp = atoi(attr[index + 1]);
						if((temp < 1) || (temp > 60) )
						{
							s_vm_mms_xml_is_valid = FALSE;
							vm_log_error("vm_mms_xml_elem_start_callback:(audio)end = %s",attr[index+1]);
							return;
						}
					}
				}
				else if(!strcmp(attr[index],"alt"))
				{
					vm_log_warn("vm_mms_xml_elem_start_callback:(audio)alt=%s",attr[index + 1]);
				}
				else
				{
					vm_log_error("vm_mms_xml_elem_start_callback:(audio)no such attribute:%s",attr[index+1]);
					s_vm_mms_xml_is_valid = FALSE;
					return;
				}
				index += 2;
			}
		}
		else if(!strcmp(el,"video"))
		{
			while ((NULL != attr[index]) && (NULL != attr[index + 1]))
			{
				if(!strcmp(attr[index],"id"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(video)id = %s",attr[index+1]);
						return;
					}
					else
					{
						VMINT temp = atoi(attr[index + 1]);
						if(temp < 1)
						{
							s_vm_mms_xml_is_valid = FALSE;
							vm_log_error("vm_mms_xml_elem_start_callback:(video)id = %s",attr[index+1]);
							return;
						}
					}
				}
				else if(!strcmp(attr[index],"begin"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(video)begin = %s",attr[index+1]);
						return;
					}
					else
					{
						VMINT temp = atoi(attr[index + 1]);
						if((temp < 0) || (temp > 59) )
						{
							s_vm_mms_xml_is_valid = FALSE;
							vm_log_error("vm_mms_xml_elem_start_callback:(video)begin = %s",attr[index+1]);
							return;
						}
					}
				}
				else if(!strcmp(attr[index],"end"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(video)end = %s",attr[index+1]);
						return;
					}
					else
					{
						VMINT temp = atoi(attr[index + 1]);
						if((temp < 1) || (temp > 60) )
						{
							s_vm_mms_xml_is_valid = FALSE;
							vm_log_error("vm_mms_xml_elem_start_callback:(video)end = %s",attr[index+1]);
							return;
						}
					}
				}
				else if(!strcmp(attr[index],"alt"))
				{
					vm_log_warn("vm_mms_xml_elem_start_callback:(video)alt=%s",attr[index + 1]);
				}
				else if(!strcmp(attr[index],"region"))
				{
					vm_log_warn("vm_mms_xml_elem_start_callback:(video)region=%s",attr[index + 1]);
				}
				else
				{
					vm_log_error("vm_mms_xml_elem_start_callback:(video)no such attribute:%s",attr[index+1]);
					s_vm_mms_xml_is_valid = FALSE;
					return;
				}
				index += 2;
			}
		}
		else if(!strcmp(el,"ref"))
		{
			while ((NULL != attr[index]) && (NULL != attr[index + 1]))
			{
				if(!strcmp(attr[index],"id"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(ref)id = %s",attr[index+1]);
						return;
					}
					else
					{
						VMINT temp = atoi(attr[index + 1]);
						if(temp < 1)
						{
							s_vm_mms_xml_is_valid = FALSE;
							vm_log_error("vm_mms_xml_elem_start_callback:(ref)id = %s",attr[index+1]);
							return;
						}
					}
				}
				else if(!strcmp(attr[index],"begin"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(ref)begin = %s",attr[index+1]);
						return;
					}
					else
					{
						VMINT temp = atoi(attr[index + 1]);
						if((temp < 0) || (temp > 59) )
						{
							s_vm_mms_xml_is_valid = FALSE;
							vm_log_error("vm_mms_xml_elem_start_callback:(ref)begin = %s",attr[index+1]);
							return;
						}
					}
				}
				else if(!strcmp(attr[index],"end"))
				{
					if(!vm_mms_string_is_number_value(attr[index + 1]))
					{
						s_vm_mms_xml_is_valid = FALSE;
						vm_log_error("vm_mms_xml_elem_start_callback:(ref)end = %s",attr[index+1]);
						return;
					}
					else
					{
						VMINT temp = atoi(attr[index + 1]);
						if((temp < 1) || (temp > 60) )
						{
							s_vm_mms_xml_is_valid = FALSE;
							vm_log_error("vm_mms_xml_elem_start_callback:(ref)end = %s",attr[index+1]);
							return;
						}
					}
				}
				else if(!strcmp(attr[index],"alt"))
				{
					vm_log_warn("vm_mms_xml_elem_start_callback:(ref)alt=%s",attr[index + 1]);
				}
				else if(!strcmp(attr[index],"region"))
				{
					vm_log_warn("vm_mms_xml_elem_start_callback:(ref)region=%s",attr[index + 1]);
				}
				else
				{
					vm_log_error("vm_mms_xml_elem_start_callback:(ref)no such attribute:%s",attr[index+1]);
					s_vm_mms_xml_is_valid = FALSE;
					return;
				}
				index += 2;
			}
		}
		else if(!strcmp(el,"name"))
		{
			if(s_vm_mms_xml_name == NULL)
			{
				s_vm_mms_xml_is_valid = FALSE;
				vm_log_error("vm_mms_xml_elem_start_callback:s_vm_mms_xml_name is null ");
				return;
			}
			else
			{
				memset(s_vm_mms_xml_name,0,VM_MMS_XML_FILE_LEN);
				strcpy(s_vm_mms_xml_name,el);
			}
		}
		else if(!strcmp(el,"filepath"))
		{
			if(s_vm_mms_xml_filepath == NULL)
			{
				s_vm_mms_xml_is_valid = FALSE;
				vm_log_error("vm_mms_xml_elem_start_callback:s_vm_mms_xml_filepath is null");
				return;
			}
			else
			{
				memset(s_vm_mms_xml_filepath,0,VM_MMS_XML_FILE_LEN);
				strcpy(s_vm_mms_xml_filepath,el);
			}
		}
	}
}
static void vm_mms_xml_elem_end_callback(void* data, const VMSTR el, VMINT error)
{
	if (VM_XML_NO_ERROR != error)
    	{
    		s_vm_mms_xml_is_valid = FALSE;
		vm_log_error("vm_mms_xml_elem_end_callback:el=%s, error=%d,error_string=%s", el, error, vm_xml_get_error());
	}
	else
	{
		if(!strcmp(el,"name"))
		{
			if(s_vm_mms_xml_name != NULL)
			{
				vm_log_debug("vm_mms_xml_elem_end_callback:s_vm_mms_xml_name = %s",s_vm_mms_xml_name);
				if(!strcmp(s_vm_mms_xml_name,"name"))
				{
					s_vm_mms_xml_is_valid = FALSE;
					vm_log_error("vm_mms_xml_elem_end_callback:name is null");
					return;
				}
			}
			else
			{
				vm_log_error("vm_mms_xml_elem_end_callback:s_vm_mms_xml_name=NULL");
				s_vm_mms_xml_is_valid = FALSE;
				return;
			}
		}
		else if(!strcmp(el,"filepath"))
		{
			if(s_vm_mms_xml_filepath != NULL)
			{
				vm_log_debug("vm_mms_xml_elem_end_callback:s_vm_mms_xml_filepath = %s",s_vm_mms_xml_filepath);
				if(!strcmp(s_vm_mms_xml_filepath,"filepath"))
				{
					s_vm_mms_xml_is_valid = FALSE;
					vm_log_error("vm_mms_xml_elem_end_callback:filepath is null");
					return;
				}
			}
			else
			{
				vm_log_error("vm_mms_xml_elem_end_callback:s_vm_mms_xml_filepath=NULL");
				s_vm_mms_xml_is_valid = FALSE;
				return;
			}
		}
	}
}
static void vm_mms_xml_data_callback(void* resv,const VMSTR el,const VMSTR data,VMINT len,VMINT error)
{
	if (VM_XML_NO_ERROR != error)
    	{
    		s_vm_mms_xml_is_valid = FALSE;
		vm_log_error("vm_mms_xml_data_callback:el=%s, error=%d,error_string=%s", el, error, vm_xml_get_error());
	}
	else
	{
		if((!strcmp(el,"to")) || 
			(!strcmp(el,"cc")) || 
			(!strcmp(el,"bcc")) || 
			(!strcmp(el,"from")))
		{
			if(strcmp(s_vm_mms_xml_type_value,"P") && strcmp(s_vm_mms_xml_type_value,"E"))
			{
				s_vm_mms_xml_is_valid = FALSE;
				vm_log_error("vm_mms_xml_data_callback:(to cc bcc from)no such value:%s",s_vm_mms_xml_type_value);
				return;
			}
		}
		else if(!strcmp(el,"subject"))
		{
			if(strlen(data) > 80)
			{
				s_vm_mms_xml_is_valid = FALSE;
				vm_log_error("vm_mms_xml_data_callback:(subject)data:%s",data);
				return;
			}
		}
		else if(!strcmp(el,"rr"))
		{
			if((strcmp(data,"0") != 0) && (strcmp(data,"1") != 0))
			{
				vm_log_error("vm_mms_xml_data_callback:rr = %s",data);
				s_vm_mms_xml_is_valid = FALSE;
				return;
			}
		}
		else if(!strcmp(el,"dr"))
		{
			if((strcmp(data,"0") != 0) && (strcmp(data,"1") != 0))
			{
				vm_log_error("vm_mms_xml_data_callback:dr = %s",data);
				s_vm_mms_xml_is_valid = FALSE;
				return;
			}
		}
		else if(!strcmp(el,"prio"))
		{
			if((strcmp(data,"0") != 0) &&
				(strcmp(data,"1") != 0) && 
				(strcmp(data,"2") != 0) && 
				(strcmp(data,"3") != 0))
			{
				vm_log_error("vm_mms_xml_data_callback:prio = %s",data);
				s_vm_mms_xml_is_valid = FALSE;
				return;
			}
		}
		else if(!strcmp(el,"expiry"))
		{
			if((strcmp(data,"0") != 0) && 
				(strcmp(data,"3600") != 0) && 
				(strcmp(data,"21600") != 0) && 
				(strcmp(data,"43200") != 0) && 
				(strcmp(data,"86400") != 0) && 
				(strcmp(data,"604800") != 0))
			{
				vm_log_error("vm_mms_xml_data_callback:expiry = %s",data);
				s_vm_mms_xml_is_valid = FALSE;
				return;
			}
		}
		else if(!strcmp(el,"delivery"))
		{
			if((strcmp(data,"0") != 0) && 
				(strcmp(data,"3600") != 0) && 
				(strcmp(data,"43200") != 0) && 
				(strcmp(data,"86400") != 0))
			{
				vm_log_error("vm_mms_xml_data_callback:delivery = %s",data);
				s_vm_mms_xml_is_valid = FALSE;
				return;
			}
		}
		else if(!strcmp(el,"visible"))
		{
			if((strcmp(data,"0") != 0) && (strcmp(data,"1") != 0))
			{
				vm_log_error("vm_mms_xml_data_callback:visible = %s",data);
				s_vm_mms_xml_is_valid = FALSE;
				return;
			}
		}
		else if(!strcmp(el,"version"))
		{
			if((strcmp(data,"16") != 0) && (strcmp(data,"17") != 0) && (strcmp(data,"18") != 0))
			{
				vm_log_error("vm_mms_xml_data_callback:version = %s",data);
				s_vm_mms_xml_is_valid = FALSE;
				return;
			}
		}
		else if(!strcmp(el,"date"))
		{
			if(!vm_mms_string_is_number_value(data))
			{
				s_vm_mms_xml_is_valid = FALSE;
				vm_log_error("vm_mms_xml_elem_start_callback:date = %s",data);
				return;
			}
		}
		else if(!strcmp(el,"class"))
		{
			if((strcmp(data,"0") != 0) && (strcmp(data,"1") != 0) && (strcmp(data,"2") != 0) && (strcmp(data,"3") != 0)) 
			{
				vm_log_error("vm_mms_xml_data_callback:class = %s",data);
				s_vm_mms_xml_is_valid = FALSE;
				return;
			}
		}
		else if(!strcmp(el,"status"))
		{
			if((strcmp(data,"128") != 0) && 
				(strcmp(data,"129") != 0) && 
				(strcmp(data,"130") != 0) && 
				(strcmp(data,"131") != 0) && 
				(strcmp(data,"132") != 0) && 
				(strcmp(data,"133") != 0) && 
				(strcmp(data,"134") != 0) && 
				(strcmp(data,"135") != 0)) 
			{
				vm_log_error("vm_mms_xml_data_callback:status = %s",data);
				s_vm_mms_xml_is_valid = FALSE;
				return;
			}
		}
		else if(!strcmp(el,"dl_size"))
		{
			if(!vm_mms_string_is_number_value(data))
			{
				s_vm_mms_xml_is_valid = FALSE;
				vm_log_error("vm_mms_xml_data_callback:dl_size = %s",data);
				return;
			}
		}
		else if(!strcmp(el,"dl_url"))
		{
			vm_log_warn("vm_mms_xml_data_callback:dl_url=%s",data);
		}
		else if(!strcmp(el,"reported_msg"))
		{
			if(!vm_mms_string_is_number_value(data))
			{
				s_vm_mms_xml_is_valid = FALSE;
				vm_log_error("vm_mms_xml_data_callback:reported_msg = %s",data);
				return;
			}
		}
		else if(!strcmp(el,"reported_msg_sub"))
		{
			vm_log_warn("vm_mms_xml_data_callback:reported_msg_sub=%s",data);
		}
		
		if(!strcmp(el,"name"))
		{
			if(s_vm_mms_xml_name != NULL)
			{
				strcat(s_vm_mms_xml_name,data);
			}
			else
			{
				s_vm_mms_xml_is_valid = FALSE;
				vm_log_error("vm_mms_xml_data_callback:xml get name error");
				return;
			}
		}
		if(!strcmp(el,"filepath"))
		{
			if(s_vm_mms_xml_filepath != NULL)
			{
				strcat(s_vm_mms_xml_filepath,data);
			}
			else
			{
				s_vm_mms_xml_is_valid = FALSE;
				vm_log_error("vm_mms_xml_data_callback:xml get filepath error");
				return;
			}
		}
	}
}


static VMINT vm_mms_string_is_number_value(const VMSTR string)
{
	VMCHAR* temp_pt = string;

	if(string == NULL)
	{
		return FALSE;
	}
	if(strlen(string) > 1)
	{
		if(((*temp_pt) > '0') && ((*temp_pt) <= '9'))
		{
			temp_pt++;
			while((temp_pt != NULL) && ((*temp_pt) != '\0'))
			{
				if(!(((*temp_pt) >= '0') && ((*temp_pt) <= '9')))
				{
					return FALSE;
				}
				temp_pt++;
			}
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		if(((*temp_pt) >= '0') && ((*temp_pt) <= '9'))
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
}

static VMINT vm_mms_string_is_color_value(const VMSTR string)
{
	VMCHAR* temp_pt = string;
	if(strlen(string) == strlen("0x000000"))
	{
		if(((*temp_pt) == '0') && (*(++temp_pt) == 'x') )
		{
			temp_pt++;
			while((temp_pt != NULL) && ((*temp_pt) != '\0'))
			{
				if(!((((*temp_pt) >= '0') && ((*temp_pt) <= '9')) ||( ((*temp_pt) >= 'a') && ((*temp_pt) <= 'f'))))
				{
					return FALSE;
				}
				temp_pt++;
			}
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}

#endif // _VM_MMS_XML_

static void vm_mms_delete_cur_process_res(VM_P_HANDLE process_handle)
{
	VMINT res_handle;
	VMINT buffer_size;
	VMINT res;
	vm_send_mms_req_t * mms_send_ptr = NULL;

	if (vm_res_type_avaliable_handle(VM_RES_TYPE_MMS_HANDLE, process_handle) > 0)
	{
		while ( (res_handle = vm_res_findfirst(process_handle, VM_RES_TYPE_MMS_HANDLE))  != VM_RES_NOT_FIND)
		{
			res = vm_res_get_data( VM_RES_TYPE_MMS_HANDLE, res_handle, (void**)&mms_send_ptr, &buffer_size );
			if(res == VM_RES_OK)
			{
				if(mms_send_ptr != NULL)
				{
					vm_free(mms_send_ptr);
				}
			}
			vm_res_release_data(VM_RES_TYPE_MMS_HANDLE,  res_handle); 
			vm_res_findclose(VM_RES_TYPE_MMS_HANDLE);
		}
	}
}


VMINT vm_mms_launch(vm_mms_launch_data* data, VMINT data_size)
{
#ifndef __COSMOS_MMI_PACKAGE__
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
    mmi_uc_entry_write_struct write_data;
    srv_uc_addr_struct addr_data;
    
    memset(&write_data,0,sizeof(write_data));
    memset(&addr_data,0,sizeof(addr_data));
    
    addr_data.addr = (kal_uint8 *)data->addr;
    addr_data.type = (srv_uc_address_type_enum)data->addr_type;
    addr_data.group = SRV_UC_ADDRESS_GROUP_TYPE_TO;
    
    write_data.addr_num = 1;
    if (data->content)
    {
        write_data.text_num = kal_wstrlen(data->content);
    }
    write_data.media_num = 1;
    write_data.addr = &addr_data;
    write_data.msg_type = SRV_UC_MSG_TYPE_MMS_ONLY;
    write_data.info_type = SRV_UC_INFO_TYPE_MMS;
    write_data.subject = (kal_uint8 *)data->subject;
    write_data.text_buffer = (kal_uint8 *)data->content;
    write_data.file_path= (kal_uint8 *)data->att_path;
    if (data->sim > 0 && data->sim <= vm_sim_max_card_count())
    {
        write_data.sim_id = 1<<(data->sim-1);
    }
    else
    {
        write_data.sim_id = 1<<(vm_sim_get_active_sim_card()-1);
    }
    cui_uc_write_msg_with_content_launch(GRP_ID_ROOT,SRV_UC_STATE_WRITE_NEW_MSG,&write_data);
    return 0;
#else
    return -2;
#endif 

#else //__COSMOS_MMI_PACKAGE__
#ifdef __MMI_MMS_2__
    VappUcEntryStruct entry_data;
    srv_uc_addr_struct addr_data;
    
    memset(&entry_data,0,sizeof(entry_data));
    memset(&addr_data,0,sizeof(addr_data));

    addr_data.addr = (kal_uint8 *)data->addr;
    addr_data.type = (srv_uc_address_type_enum)data->addr_type;
    addr_data.group = SRV_UC_ADDRESS_GROUP_TYPE_TO;
    
    entry_data.addr_num = 1;
    if (data->content)
    {
        entry_data.text_num = kal_wstrlen(data->content);
    }
    entry_data.media_num = 1;
    entry_data.addr = &addr_data;
    entry_data.msg_type = SRV_UC_MSG_TYPE_MMS_ONLY;
    entry_data.info_type = SRV_UC_INFO_TYPE_MMS;
    entry_data.subject = (kal_uint8 *)data->subject;
    entry_data.text_buffer = (kal_uint8 *)data->content;
    entry_data.file_path= (kal_uint8 *)data->att_path;
    if (data->sim > 0 && data->sim <= vm_sim_max_card_count())
    {
        entry_data.sim_id = (srv_uc_sim_id)(1<<(data->sim-1));
    }
    else
    {
        entry_data.sim_id = (srv_uc_sim_id)(1<<(vm_sim_get_active_sim_card()-1));
    }
    
    if (vappUcAppLauncher(&entry_data))
    {
        return 0;
    }
    return -3;
#endif
    return -99;
#endif //__COSMOS_MMI_PACKAGE__
}

#ifdef __MMI_MMS_2__
typedef struct
{
    VM_P_HANDLE                 pHandle;
    void*                       callback;
    void*                       user_data;
}vm_mms_data;


void vm_mms_trans_msg_info(vm_mms_msg_info* msg,srv_mms_mma_get_msg_info_rsp_struct* info)
{
    msg->msg_id = info->msg_id;
    msg->msg_size = info->msg_size;
    msg->user_elements_size = info->user_elements_size;
    msg->date = info->date;
    msg->expiry_date = info->expiry_date;
    msg->received_date = info->received_date;
    msg->need_read_report = info->need_read_report;
    msg->isRead = info->isRead;
    msg->isForwardLock = info->isForwardLock;
    msg->isDRM = info->isDRM;
    msg->isFollowPhoneMMSContentClass = info->isFollowPhoneMMSContentClass;
    msg->hasAttachment = info->hasAttachment;
    msg->result = info->result;
    msg->msg_media_type = info->msg_media_type;
    msg->from_address_type = info->from_address_type+1;
    msg->msg_type = info->msg_type;
    msg->storage_type = info->storage_type;
    msg->sim_id = info->sim_id;
    memcpy(msg->from_address,info->from_address,VM_MMS_MAX_ADDR_LEN);
    memcpy(msg->subject,info->subject,VM_MMS_MAX_SUBJECT_LEN);
}

mmi_ret mmi_mre_mms_interrupt_hdlr(mmi_event_struct *param)
{
    mmi_ret ret = MMI_RET_OK;
    vm_mms_data* data;
    srv_mms_mma_get_msg_info_rsp_struct* info = 
                    (srv_mms_mma_get_msg_info_rsp_struct*)((srv_mms_base_event_struct*)param)->sender_data;
    vm_mms_msg_info msg_info;
    vm_mms_interrupt_callback callback;
    VMINT res_handle;
    VMINT size;

    res_handle = vm_res_findfirst(-1, VM_RES_TYPE_MMS_INTERRUPT);
    while (res_handle  != VM_RES_NOT_FIND)
	{
		if(vm_res_get_data( VM_RES_TYPE_MMS_INTERRUPT, res_handle, (void**)&data, &size ) == VM_RES_OK)
		{
            callback = (vm_mms_interrupt_callback)(data->callback);
		    if (VM_PMNG_OP_OK == vm_pmng_set_ctx(data->pHandle) && callback)
            {
                VMBOOL result;
                vm_mms_trans_msg_info(&msg_info,info);
                result = callback(&msg_info,data->user_data);
                vm_pmng_reset_ctx(); 
                if (result)
                {
                    vm_res_findclose(VM_RES_TYPE_MMS_INTERRUPT);
                    return MMI_RET_DONT_CARE;
                }
            }
		}
		res_handle = vm_res_findnext(-1, VM_RES_TYPE_MMS_INTERRUPT);
	}
	vm_res_findclose(VM_RES_TYPE_MMS_INTERRUPT);
    return MMI_RET_OK;
}
#endif
VMINT vm_mms_set_interrupt_event_handler(vm_mms_event_enum event, vm_mms_interrupt_callback callback, void* user_data)
{
#ifdef __MMI_MMS_2__
    vm_mms_data* data;
    VM_P_HANDLE handle;
    
    if (event > VM_EVT_ID_MMS_MAX_ENUM || event < VM_EVT_ID_MMS_NEW_MSG || NULL == callback)
    {
        return -2;
    }

    handle = vm_pmng_get_current_handle();
    if (vm_res_get_data_list_count_by_proecss(handle, VM_RES_TYPE_MMS_INTERRUPT) > 0)
    {
        return -5;
    }
    
    data = (vm_mms_data*)vm_malloc(sizeof(vm_mms_data));
    if (NULL == data)
    {
        return -3;
    }

    
    data->pHandle = handle;
    data->callback = (void*)callback;
    data->user_data = user_data;

    if (vm_res_save_data(VM_RES_TYPE_MMS_INTERRUPT, (void*)data, 4, NULL, data->pHandle) < 0)
    {
       return -4;
    }
#endif    
    return 0;
}

static VMINT _vm_mms_clear_interrupt_event_handler(VM_P_HANDLE handle)
{
#ifdef __MMI_MMS_2__
    VMINT res_handle;
    vm_mms_data* data;
    VMINT size;
    
    while ((res_handle = vm_res_findfirst(handle, VM_RES_TYPE_MMS_INTERRUPT))  != VM_RES_NOT_FIND)
	{
		if(vm_res_get_data( VM_RES_TYPE_MMS_INTERRUPT, res_handle, (void**)&data, &size ) == VM_RES_OK)
		{
			if(data != NULL)
			{
				vm_free(data);
			}
		
    		vm_res_release_data(VM_RES_TYPE_MMS_INTERRUPT, res_handle);
		}
	}
	vm_res_findclose(VM_RES_TYPE_MMS_INTERRUPT);
#endif	
	return 0;
}

VMINT vm_mms_clear_interrupt_event_handler(vm_mms_event_enum event)
{
#ifdef __MMI_MMS_2__
    VM_P_HANDLE handle;
    
    handle = vm_pmng_get_current_handle();

    return _vm_mms_clear_interrupt_event_handler(handle);
#else
    return -1;
#endif    
}

VMINT vm_mms_download(VMUINT msg_id, vm_mms_sim_id_enum sim, vm_mms_msg_storage_type_enum storage_type)
{
#ifdef __MMI_MMS_2__
    srv_mms_download_req_struct req;

    req.msg_id = msg_id;
    req.sim_id = (U8)sim;
    req.storage_type = (U8)storage_type;
    
    srv_mms_download(&req);
#endif    
    return 0;
}

void vm_mms_cancel_download(VMINT msg_id)
{
#ifdef __MMI_MMS_2__
    srv_mms_cancel_download_req_struct req;
    
    req.msg_id = msg_id;
    
    srv_mms_cancel_download(&req);
#endif    
}
#ifdef __MMI_MMS_2__

static void _vm_mms_delete_callback(srv_mms_result_enum result, void *rsp_data, void *user_data)
{
    srv_mms_delete_rsp_struct* delete_rsp = (srv_mms_delete_rsp_struct*)rsp_data;
    vm_mms_data* data = (vm_mms_data*)user_data;
    vm_mms_delete_callback callback = (vm_mms_delete_callback)data->callback;
    
    if (VM_PMNG_OP_OK == vm_pmng_set_ctx(data->pHandle) && callback)
    {
        callback((VMINT)result,(VMUINT*)delete_rsp->msg_id,(VMINT*)delete_rsp->result,
                        delete_rsp->no_of_msg,data->user_data);
        vm_free(data);
        vm_pmng_reset_ctx(); 
    }    
}

#endif
VMINT vm_mms_delete(VMUINT* msg_id_list, VMUINT msg_num, vm_mms_folder_enum folder, vm_mms_delete_callback callback,void* user_data)
{
#ifdef __MMI_MMS_2__
    srv_mms_delete_req_struct req;
    vm_mms_data* data;
    
    if (NULL == msg_id_list || 0 == msg_num || msg_num > MMA_MAX_MSG_ARRAY_NUM)
    {
        return -2;
    }

    data = (vm_mms_data*)vm_malloc(sizeof(vm_mms_data));
    if (NULL == data)
    {
        return -3;
    }
    
    data->pHandle = vm_pmng_get_current_handle();
    data->callback = (void*)callback;
    data->user_data = user_data;
    
    req.box = (U16)folder;    
    req.no_of_msg = msg_num;
    req.call_back = _vm_mms_delete_callback;
    req.user_data = data;
    memcpy(req.msg_id,msg_id_list,MMA_MAX_MSG_ARRAY_NUM);
    
    return srv_mms_delete(&req);
#else
    return -1;
#endif    
}
#ifdef __MMI_MMS_2__
typedef struct
{
    srv_um_box_identity_struct um_box;
    void* user_data;
}vm_get_list_data;

static void vm_mms_notify_list_handler(S32 event, S32 list_cid, S32 user_data)
{
}

S32 vm_mms_get_list_cb(S32 pid, srv_um_get_list_result* rsp, S32 user_data)
{
    vm_mms_data* data = (vm_mms_data*)user_data;
    vm_get_list_data* box_data = data->user_data;
    srv_um_list_cntx_struct* list_cntx;
    vm_mms_get_msg_id_list_rsp list_rsp;
    vm_mms_get_msg_id_list_callback_type callback = (vm_mms_get_msg_id_list_callback_type)data->callback;
    srv_um_list_filter_struct filter;
    
    memset(&list_rsp, 0, sizeof(list_rsp));
    memset(&filter, 0, sizeof(filter));
    list_rsp.result = -1;
    list_rsp.msg_num = rsp->n.msg_number;

    MMI_PRINT(MOD_MRE,MMI_MRE_TRC_G9,"[MRE][MMS]vm_mms_get_list_cb1,error=%d,num=%d",rsp->error,list_rsp.msg_num);
    if (rsp->error == 0 && list_rsp.msg_num > 0)
    {        
        if (srv_um_check_list(SRV_UM_LIST_TYPE_MSG_NODE,box_data->um_box,&filter,vm_mms_notify_list_handler,NULL,&list_cntx)>0)
        {
            int i;
            srv_um_msg_node_struct* msg_node = list_cntx->list;

            MMI_PRINT(MOD_MRE,MMI_MRE_TRC_G9,"[MRE][MMS]vm_mms_get_list_cb2");
            list_rsp.result = 0;
            
            for (i=0; (i < rsp->n.msg_number)&&(i < VM_MMS_MSG_ID_LIST_LEN); i++)
            {
                list_rsp.msg_id_list[i] = msg_node[i].msg_id;
            }
            
        }        
    }
    
    if (VM_PMNG_OP_OK == vm_pmng_set_ctx(data->pHandle) && callback)
    {
        MMI_PRINT(MOD_MRE,MMI_MRE_TRC_G9,"[MRE][MMS]vm_mms_get_list_cb3");
        callback(&list_rsp,box_data->user_data);
        vm_free(box_data);
        vm_free(data);
        vm_pmng_reset_ctx(); 
    } 
}

static srv_um_msg_box_enum vm_mms_trans_folder(vm_mms_folder_enum folder)
{
    switch (folder)
    {
    case VM_MMS_FOLDER_TEMPLATE :
        return SRV_UM_MSG_BOX_PREDEF_TEMPLATES;
        
    case VM_MMS_FOLDER_USRDEF_TEMPLATE :
        return SRV_UM_MSG_BOX_USRDEF_TEMPLATES;
        
    case VM_MMS_FOLDER_ARCHIVE :
        return SRV_UM_MSG_BOX_ARCHIVE;
        
    case VM_MMS_FOLDER_HIDDEN :
        return SRV_UM_MSG_BOX_NONE;
        
    case VM_MMS_FOLDER_REPORT_BOX :
        return SRV_UM_MSG_BOX_REPORT;
//    case VM_MMS_FOLDER_ALL :
//        return SRV_UM_MSG_BOX_ALL;
    default:
        return (srv_um_msg_box_enum)folder;
    }
    
}

#endif
VMINT vm_mms_get_msg_id_list(vm_mms_folder_enum folder, vm_mms_get_msg_id_list_callback_type callback, void* user_data)
{
#ifdef __MMI_MMS_2__
    VMINT result = 0;
    vm_mms_data* data;
    vm_get_list_data* box_data;
    
    if (folder&(folder-1))
    {
        result = -99;
        goto error;
    }

    data = (vm_mms_data*)vm_malloc(sizeof(vm_mms_data));
    if (NULL == data)
    {
        result = -98;
        goto error;
    }
    box_data = (vm_get_list_data*)vm_malloc(sizeof(vm_get_list_data));
    if (NULL == box_data)
    {
        result = -97;
        goto error;
    }
    
    box_data->um_box.msg_type = SRV_UM_MSG_MMS;
    box_data->um_box.msg_box_type = vm_mms_trans_folder(folder);
    box_data->um_box.sim_id = SRV_UM_SIM_ALL;
    box_data->user_data = user_data;
    
    data->pHandle = vm_pmng_get_current_handle();
    data->callback = (void*)callback;
    data->user_data = box_data;
    
    result = srv_um_get_list(SRV_UM_LIST_TYPE_MSG_NODE,box_data->um_box,NULL,vm_mms_get_list_cb,(S32)data);
error:    
    MMI_PRINT(MOD_MRE,MMI_MRE_TRC_G9,"[MRE][MMS]vm_mms_get_msg_id_list result=%d", result);
    return result;
#else
    return -100;
#endif
}


#ifdef __MMI_MMS_2__

void vm_mms_get_content_callback(srv_mms_result_enum result,void *rsp_data, void *user_data)
{
    srv_mms_get_content_rsp_struct *msg = (srv_mms_get_content_rsp_struct*) rsp_data;
    vm_mms_data* data = (vm_mms_data*)user_data;
    vm_mms_get_content_callback_type callback = (vm_mms_get_content_callback_type)data->callback;

    MMI_PRINT(MOD_MRE,MMI_MRE_TRC_G9,"[MRE][MMS]vm_mms_get_content_callback1");
    if (VM_PMNG_OP_OK == vm_pmng_set_ctx(data->pHandle) && callback)
    {
        MMI_PRINT(MOD_MRE,MMI_MRE_TRC_G9,"[MRE][MMS]vm_mms_get_content_callback2");
        callback((vm_mms_get_content_rsp_struct*)msg,data->user_data);
        vm_free(data);
        vm_pmng_reset_ctx(); 
    } 
}
#endif
VMINT vm_mms_get_content(vm_mms_get_content_req_struct *req_data)
{
#ifdef __MMI_MMS_2__
    VMINT result = -10;
    srv_mms_get_content_req_struct srv_req_data;
    vm_mms_data* data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!req_data)
    {
       result = -99;
       goto error;
    }
    memcpy(&srv_req_data,req_data,sizeof(srv_req_data));
    
    data = (vm_mms_data*)vm_malloc(sizeof(vm_mms_data));
    if (NULL == data)
    {
        result = -98;
        goto error;
    }    
    data->pHandle = vm_pmng_get_current_handle();
    data->callback = (void*)req_data->callback;
    data->user_data = req_data->user_data;
    
    srv_req_data.call_back = vm_mms_get_content_callback;
    srv_req_data.user_data = (void*)data;
    
    srv_req_data.app_id = 0;
    result = srv_mms_get_content(&srv_req_data);
error:
    MMI_PRINT(MOD_MRE,MMI_MRE_TRC_G9,"[MRE][MMS]vm_mms_get_content result=%d", result);
    return result;
#else
    return -100;
#endif
}

#else
#include "MMIDataType.h"
mmi_ret mmi_mre_mms_interrupt_hdlr(mmi_event_struct *param)
{
    return MMI_RET_OK;
}

#endif


