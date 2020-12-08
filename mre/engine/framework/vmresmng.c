#include "vmswitch.h"
#ifdef __MRE_CORE_RESOURCE_MANAGE__
#include <string.h>
#include "vmsys.h"
#include "vmmem.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmlog.h"
#include "MMI_trc.h"
#include "fs_func.h"

extern VMINT mre_running;

typedef struct vm_mi_res_node_t {
VM_P_HANDLE   phandle;
VMINT    res_id;
VMINT    mtk_res_id;
void*    res_callback;
void*    data_content;
VMINT  data_size;
VMINT  data_state;
struct vm_mi_res_node_t *  next;
//VMINT  scan_token;
}  vm_mi_res_node_t ;

typedef struct vm_mi_res_list_node_t {
VMINT type;
VMINT attr;
VMINT total;
VMINT used;
VMINT total_per_proc;
VMINT sys_reserve;
VMINT sys_reserve_used;
vm_res_release_callback_t release_callback;
vm_mi_res_node_t * res_list_ptr;
VMINT find_stack[5];
struct vm_mi_res_list_node_t * next;
} vm_mi_res_type_node_t;

/*资源类型序号产生数组*/
static VMINT res_gen_handle_array[VM_RES_TYPE_TOTAL];

/*系统资源初始化标记，TRUE=已经初始化，FALSE=未初始化*/
VMINT vm_mi_res_init_flag = FALSE;

 /*系统资源首地址指针*/
static vm_mi_res_type_node_t * vm_res_ptr = NULL;

/*初始化资源类型节点*/
 static void vm_res_init_data_type(VMINT type, vm_mi_res_type_node_t * restype_ptr);

/**
 * 检索资源类型队列
 */
static vm_mi_res_type_node_t * vm_scan_res_type_table(VMINT data_type)
{
	vm_mi_res_type_node_t * res_type_ptr = NULL;  /*遍历资源类型指针*/

	if (data_type <= VM_RES_TYPE_START || data_type >= VM_RES_TYPE_TOTAL)
		return NULL;

	res_type_ptr = vm_res_ptr;
	while (res_type_ptr != NULL)
	{
		if (res_type_ptr->type == data_type)
		{
			return res_type_ptr;
		}
		res_type_ptr = res_type_ptr->next;
	}

	return NULL;
}

/**
 * 检索指定类型中的资源队列
 */
static vm_mi_res_node_t * vm_scan_res_table(VMINT data_type, VMINT data_handle)
{
	vm_mi_res_type_node_t * res_type_ptr = NULL;  /*遍历资源类型指针*/	
	vm_mi_res_node_t * res_ptr = NULL;  /*遍历资源指针*/

	if (data_type <= VM_RES_TYPE_START || data_type >= VM_RES_TYPE_TOTAL)
		return NULL;
	//vm_log_debug("data_type=%d, data_handle=%d", data_type, data_handle);
	res_type_ptr = vm_res_ptr;
	while (res_type_ptr != NULL)
	{
		//vm_log_debug("vm_scan_res_table : res_type_ptr=%d", res_type_ptr->type);
		if (res_type_ptr->type == data_type)
		{
			//vm_log_debug("vm_scan_res_table : will scan res_type_ptr=%d", res_type_ptr->type);
			res_ptr = res_type_ptr->res_list_ptr;
			while(res_ptr != NULL)
			{
				//vm_log_debug("vm_scan_res_table : will scan res_ptr=%d", res_ptr->res_id);
				if((res_ptr->res_id) == data_handle)
				{
					//vm_log_debug("vm_scan_res_table : find res_node");
					return res_ptr;
				}
				res_ptr = res_ptr->next;
			}
			return NULL;
		}
		res_type_ptr = res_type_ptr->next;
	}

	return NULL;
}

/**
 * 产生资源序号
 */
static VMINT vm_res_gen_data_handle(VMINT type)
{
	do 
	{
	if (res_gen_handle_array[type] >= 32767)
		res_gen_handle_array[type] = 0;
	else
		res_gen_handle_array[type]++;
	}while (vm_scan_res_table(type, res_gen_handle_array[type]) != NULL);
	return res_gen_handle_array[type];
}

VMINT vm_res_initialize( void )
{
	int type_i = 0;	
	vm_mi_res_type_node_t * restype_ptr = NULL;  /*遍历指针*/	
	vm_mi_res_type_node_t * restype_node_ptr = NULL; /*新资源类型指针*/

	//vm_log_debug("vm_res_init : start ");
	
	restype_ptr = vm_res_ptr;  /*指向系统资源首地址*/
	
	if (vm_res_ptr == NULL)
	{
		//vm_log_debug("vm_res_init : will init");
		for(type_i = (VM_RES_TYPE_START + 1); type_i  < VM_RES_TYPE_TOTAL; type_i++)
		{
			//vm_log_debug("vm_res_init : init type=%d", type_i);
			/*需要切换到内核内存模式*/			
			restype_node_ptr = (vm_mi_res_type_node_t *)_vm_kernel_malloc(sizeof(vm_mi_res_type_node_t));
			memset(restype_node_ptr, 0x00, sizeof(vm_mi_res_type_node_t));
			
			if (restype_node_ptr != NULL)
			{				
				/*设置数据*/
				vm_res_init_data_type(type_i, restype_node_ptr);		

				/*初始化序号发生数组*/
				res_gen_handle_array[type_i] = 0;

				/*插入队列*/
				if (vm_res_ptr == NULL)
				{
					vm_res_ptr =  restype_node_ptr;
					restype_ptr = vm_res_ptr;
				}
				else
				{
					restype_ptr = vm_res_ptr;
					while(restype_ptr->next != NULL)
					{
						restype_ptr = restype_ptr->next;
					}
					restype_ptr->next = restype_node_ptr;
				}
			}
			else
			{
				/*释放已经创建类型节点的内存申请*/
				while(vm_res_ptr != NULL)
				{
					restype_ptr = vm_res_ptr;
					vm_res_ptr = vm_res_ptr->next;
					_vm_kernel_free(restype_ptr);					
				}
				vm_mi_res_init_flag = FALSE;
				/*返回内存错误*/
				return VM_RES_INIT_FAIL;
			}
			
		}
		vm_mi_res_init_flag = TRUE;
		return VM_RES_OK;
	}
	return VM_RES_INIT_FAIL;
}


void vm_res_finialize( void )
{
	vm_mi_res_type_node_t * res_type_del_ptr = NULL;  /*删除资源类型指针*/	
	vm_mi_res_node_t * res_del_ptr = NULL;  /*删除资源指针*/

	/*遍历删除所有类型的队列*/
	while(vm_res_ptr != NULL)
	{
		//vm_log_debug("vm_res_finialize will delete type=%d", vm_res_ptr->type);
		/*初始化序号发生数组*/
		res_gen_handle_array[vm_res_ptr->type] = 0;		
		
		/*遍历删除指定类型的所有资源*/
		while(vm_res_ptr->res_list_ptr != NULL)
		{
			res_del_ptr = vm_res_ptr->res_list_ptr;
			vm_res_ptr->res_list_ptr = vm_res_ptr->res_list_ptr->next;
			_vm_kernel_free(res_del_ptr);
		}	
		//vm_log_debug("vm_res_finialize deleting type=%d", vm_res_ptr->type);
		/*删除类型节点*/
		res_type_del_ptr = vm_res_ptr;		
		vm_res_ptr = vm_res_ptr->next;
		_vm_kernel_free(res_type_del_ptr);
		
	}
	/*置空资源首指针*/
	vm_res_ptr = NULL;
	/*设置标志位*/
	vm_mi_res_init_flag = FALSE;
}



VMINT vm_res_save_data( VMINT data_type, void * data_content, VMINT data_size, void* callback, VM_P_HANDLE process_handle )
{
	VMINT result = VM_RES_INTERNAL_ERROR;
	vm_mi_res_type_node_t* res_type_ptr = NULL;
	vm_mi_res_node_t * res_ptr = NULL;  /*遍历资源指针*/
	vm_mi_res_node_t * res_add_ptr = NULL;  /*遍历资源指针*/
	
	if ((process_handle > 0) && vm_pmng_state(process_handle) == VM_PMNG_UNLOAD)
	{
		MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RES_MAN_SAVE_DATA_PHANDLE_STATE_UNLOAD,process_handle, data_type);
		//vm_log_warn("vm_res_save_data : now phandle[%d]'s state is unload, get type[%d] resource failed", process_handle, data_type);
		return result;
	}

	//vm_log_debug("vm_res_save_data : start");
	if (vm_res_type_avaliable_handle( data_type,  process_handle) > 0)  /*有资源可以申请*/
	{
		//vm_log_debug("vm_res_save_data : have avaliable handle");
		res_type_ptr = vm_scan_res_type_table(data_type);  /*检索资源类型是否存在*/
		if (res_type_ptr != NULL)
		{
			/*需要切换到内核内存模式*/
			res_add_ptr = _vm_kernel_malloc(sizeof(vm_mi_res_node_t)); /*申请资源节点内存空间*/
			//vm_log_debug("vm_res_save_data : have malloced for res_node");
			if (res_add_ptr != NULL)
			{
				memset(res_add_ptr, 0x00, sizeof(vm_mi_res_node_t));
				/*设置资源节点数据*/
				res_add_ptr->data_content = data_content;
				res_add_ptr->data_size = data_size;
				res_add_ptr->mtk_res_id = -1;
				res_add_ptr->next = NULL;
				res_add_ptr->phandle = process_handle;
				res_add_ptr->res_callback = callback;
				res_add_ptr->data_state = VM_RES_STATE_IDLE;
				res_add_ptr->res_id = vm_res_gen_data_handle(res_type_ptr->type);
				/*设置scan令牌*/
				//res_add_ptr->scan_token = FALSE;
				
				//vm_log_debug("vm_res_save_data : have assigned for res_node type=%d, res_id=%d", 
				//	res_type_ptr->type, res_add_ptr->res_id);

				if ( res_type_ptr->res_list_ptr == NULL)  
				{
					/*首个节点插入*/
					res_type_ptr->res_list_ptr = res_add_ptr;	
					if (res_add_ptr->phandle == 0)
					{
						res_type_ptr->sys_reserve_used++;
					}
					else
					{
						res_type_ptr->used++;
					}
					result = res_add_ptr->res_id;
				}
				else
				{
					/*尾部节点插入*/
					res_ptr = res_type_ptr->res_list_ptr;
					while (res_ptr->next != NULL)
					{
						res_ptr = res_ptr->next;
					}
					res_ptr->next = res_add_ptr;
					if (res_add_ptr->phandle == 0)
					{
						res_type_ptr->sys_reserve_used++;
					}
					else
					{
						res_type_ptr->used++;
					}
					result = res_add_ptr->res_id;
				}
				vm_res_print_monitor_log(process_handle,data_type);
				//vm_log_debug("vm_res_save_data : have inserted into queue");
			}
			else
			{
				result = VM_RES_INTERNAL_ERROR;
			}
		}
		else
		{
			result = VM_RES_INTERNAL_ERROR;
		}
	}
	else
	{
		result = VM_RES_INSUFFICIENT_BUFFER;
	}
	//vm_log_debug("vm_res_save_data : end, result=%d", result);
	return result;
}

VMINT vm_res_release_data( VMINT data_type, VMINT data_handle )
{
	VMINT result = VM_RES_INTERNAL_ERROR;
	vm_mi_res_type_node_t* res_type_ptr = NULL; /*遍历资源类型指针*/
	vm_mi_res_node_t * res_ptr = NULL;  /*遍历资源指针*/
	vm_mi_res_node_t * res_del_ptr = NULL;  /*删除资源指针*/

	//vm_log_debug("vm_res_release_data : start, data_type=%d, data_handle=%d", data_type, data_handle);
	res_type_ptr = vm_scan_res_type_table(data_type);

	if (res_type_ptr != NULL)
	{
		res_ptr = res_type_ptr->res_list_ptr;
		if (res_ptr != NULL)
		{
			if (res_ptr->res_id == data_handle) /*首节点操作*/
			{
				//vm_log_debug("vm_res_release_data : release first res node");
				res_type_ptr->res_list_ptr = res_ptr->next;
				res_ptr->next  = NULL;
				if (res_ptr->phandle == 0)
				{
					res_type_ptr->sys_reserve_used--;
				}
				else
				{
					res_type_ptr->used--;
				}
				/*需要切换到内核内存模式*/				
				vm_res_print_monitor_log(res_ptr->phandle,data_type);
				_vm_kernel_free(res_ptr);				
				result = VM_RES_OK;
			}
			else
			{
				//vm_log_debug("vm_res_release_data : release res node");
				result = VM_RES_INTERNAL_ERROR;
				while (res_ptr->next != NULL) /*非首节点操作*/
				{
					res_del_ptr = res_ptr->next;
					if(res_del_ptr->res_id == data_handle)
					{
						/*删除资源节点*/
						res_ptr->next = res_del_ptr->next;
						res_del_ptr->next = NULL;
						if (res_del_ptr->phandle == 0)
						{
							res_type_ptr->sys_reserve_used--;
						}
						else
						{
							res_type_ptr->used--;
						}
						vm_res_print_monitor_log(res_del_ptr->phandle,data_type);
						_vm_kernel_free(res_del_ptr);						
						result = VM_RES_OK;
						break;
					}				
					res_ptr = res_ptr->next;
				}
			}
		}
		else
		{
			result = VM_RES_INTERNAL_ERROR;
		}
	}
	else
	{
		result = VM_RES_INTERNAL_ERROR;
	}
	//vm_log_debug("vm_res_release_data : end, result=%d", result);
	return result;
}

VMINT vm_res_set_data( VMINT data_type, VMINT	data_handle, void * data_buffer, VMINT buffer_size )
{
	VMINT retval = VM_RES_INTERNAL_ERROR;
	vm_mi_res_node_t * res_ptr = NULL; 
	
	res_ptr = vm_scan_res_table(data_type, data_handle);
	if (res_ptr != NULL)
	{
		res_ptr->data_content = data_buffer;
		res_ptr->data_size = buffer_size;
		retval = VM_RES_OK;
	}
	else
	{
		retval = VM_RES_OUT_OF_RESOURCE;
	}
	return retval;
}

VMINT vm_res_get_data( VMINT data_type, VMINT	data_handle, void** data_buffer, VMINT * buffer_size )
{
	VMINT retval = VM_RES_INTERNAL_ERROR;
	vm_mi_res_node_t * res_ptr = NULL; 
	
	res_ptr = vm_scan_res_table(data_type, data_handle);
	if (res_ptr != NULL)
	{
		(*data_buffer) = res_ptr->data_content;
		*buffer_size = res_ptr->data_size;
		retval = VM_RES_OK;
	}
	else
	{
		*buffer_size = 0;
		retval = VM_RES_OUT_OF_RESOURCE;
	}
	return retval;
}

VMINT vm_res_set_callback( VMINT data_type, VMINT	data_handle, void* callback )
{
	VMINT retval = VM_RES_INTERNAL_ERROR;
	vm_mi_res_node_t * res_ptr = NULL; 
	
	res_ptr = vm_scan_res_table(data_type, data_handle);
	if (res_ptr != NULL)
	{
		res_ptr->res_callback = callback;
		retval = VM_RES_OK;
	}
	else
	{
		retval = VM_RES_OUT_OF_RESOURCE;
	}
	return retval;
}

VMINT vm_res_get_callback( VMINT data_type, VMINT	data_handle, void** callback )
{
	VMINT retval = VM_RES_INTERNAL_ERROR;
	vm_mi_res_node_t * res_ptr = NULL; 
	
	res_ptr = vm_scan_res_table(data_type, data_handle);
	if (res_ptr != NULL)
	{
		(*callback) = res_ptr->res_callback;
		retval = VM_RES_OK;
	}
	else
	{
		//callback = NULL;
		retval = VM_RES_OUT_OF_RESOURCE;
	}
	return retval;
}

VMINT vm_res_set_mtk_reshandle(VMINT data_type, VMINT data_handle, VMINT mtk_res_handle)
{
	VMINT retval = VM_RES_INTERNAL_ERROR;
	vm_mi_res_node_t * res_ptr = NULL; 
	
	res_ptr = vm_scan_res_table(data_type, data_handle);
	
	if (res_ptr != NULL)
	{
		res_ptr->mtk_res_id = mtk_res_handle;
		//vm_log_debug("vm_res_set_mtk_reshandle : have success to set mtkresid = %d, type=%d, handle=%d ", res_ptr->mtk_res_id, data_type, data_handle);
		retval = VM_RES_OK;
	}
	else
	{
		//vm_log_debug("vm_res_set_mtk_reshandle : fail to find res_node, type=%d, handle=%d, mtk_res_handle=%d ", data_type, data_handle, mtk_res_handle);
		retval = VM_RES_OUT_OF_RESOURCE;
	}
	return retval;
}

VMINT vm_res_get_mtk_reshandle(VMINT data_type, VMINT data_handle, VMINT * mtk_res_handle)
{
	VMINT retval = VM_RES_INTERNAL_ERROR;
	vm_mi_res_node_t * res_ptr = NULL; 
	
	res_ptr = vm_scan_res_table(data_type, data_handle);
	if (res_ptr != NULL)
	{
		*mtk_res_handle = res_ptr->mtk_res_id;
		retval = VM_RES_OK;
	}
	else
	{
		*mtk_res_handle = -1;
		retval = VM_RES_OUT_OF_RESOURCE;
	}
	return retval;
}

VM_P_HANDLE vm_res_get_process_handle( VMINT data_type, VMINT data_handle )
{
	VM_P_HANDLE retval = -1;
	vm_mi_res_node_t * res_ptr = NULL; 
	
	res_ptr = vm_scan_res_table(data_type, data_handle);
	if (res_ptr != NULL)
	{
		retval = res_ptr->phandle;
	}
	else
	{
		retval = -1;
	}
	return retval;
}

VMINT vm_res_get_handle_state( VMINT data_type, VMINT data_handle )
{
	VMINT retval = VM_RES_INTERNAL_ERROR;
	vm_mi_res_node_t * res_ptr = NULL; 
	
	res_ptr = vm_scan_res_table(data_type, data_handle);
	if (res_ptr != NULL)
	{
		retval = res_ptr->data_state;
	}
	else
	{
		retval = VM_RES_INTERNAL_ERROR;
	}
	return retval;
}

VMINT vm_res_set_handle_state( VMINT data_type, VMINT data_handle, VMINT data_state )
{
	VMINT retval = VM_RES_INTERNAL_ERROR;
	vm_mi_res_node_t * res_ptr = NULL; 
	
	res_ptr = vm_scan_res_table(data_type, data_handle);
	if (res_ptr != NULL)
	{
		res_ptr->data_state = data_state;
		retval = VM_RES_OK;
	}
	else
	{
		retval = VM_RES_INTERNAL_ERROR;
	}
	return retval;
}

VMINT	vm_res_type_attribute( VMINT data_type )
{
	VMINT retval = VM_RES_INTERNAL_ERROR;
	vm_mi_res_type_node_t* res_type_ptr = NULL;
	res_type_ptr = vm_scan_res_type_table(data_type);
	if (res_type_ptr != NULL)
	{
		retval = res_type_ptr->attr;
	}
	else
	{
		retval = VM_RES_INTERNAL_ERROR;
	}
	return retval;
}


VMINT vm_res_type_max_handle( VMINT data_type )
{
	VMINT retval = 0;
	vm_mi_res_type_node_t* res_type_ptr = NULL;
	res_type_ptr = vm_scan_res_type_table(data_type);
	if (res_type_ptr != NULL)
	{
		retval = res_type_ptr->total;
	}
	else
	{
		retval = 0;
	}
	return retval;
}


VMINT vm_res_type_avaliable_handle( VMINT data_type,  VM_P_HANDLE process_handle)
{
#ifdef __MRE_CORE_SM__
/*FLOW:
if (process_handle is SM handle)
{
	if (SM is system module && SM can use $data_type$ resources)	//can use reserved resources
		count available resources;
	else 
}
*/
	extern VMINT vm_sm_get_app_handle(VMINT sm_hdl);
#endif
	VMINT process_used = 0;

	VMINT retval = 0;
	
	vm_mi_res_type_node_t* res_type_ptr = NULL;
	vm_mi_res_node_t * res_ptr = NULL; 

	res_type_ptr = vm_scan_res_type_table(data_type);

	if (res_type_ptr == NULL)
		return 0;

	if(process_handle > 0)  /*应用进程*/
	{
		/*去除系统保留资源数后，总的可利用资源数是否大于0*/
		if((res_type_ptr->total - res_type_ptr->sys_reserve) - res_type_ptr->used > 0)
		{
#ifdef __MRE_CORE_SM__
			/* Get APP handle by SM handle */
			VMINT app_handle = vm_sm_get_app_handle(process_handle);
#endif			
			/*获取进程已经占用的一类资源的数量*/
			res_ptr = res_type_ptr->res_list_ptr;
			while(res_ptr != NULL)
			{
#ifdef __MRE_CORE_SM__
				if(res_ptr->phandle == process_handle || 
					/* Count APP resources together, updated by daniel.lin */
					(app_handle && res_ptr->phandle == app_handle) )
#else
				if(res_ptr->phandle == process_handle)
#endif
					process_used++;
				res_ptr = res_ptr->next;
			}
			/*判断进程占用数是否超过上限*/
			if((res_type_ptr->total_per_proc - process_used) > 0)
			{
				retval = res_type_ptr->total_per_proc - process_used;
			}
			else
			{

				retval = 0;
			}
		}
		else
		{
			retval = 0;			
		}
	}
	else if(process_handle == 0) /*系统进程*/
	{
		/*返回进程容量和进程占用数的差值*/
		//retval = res_type_ptr->total - res_type_ptr->used;
		retval = res_type_ptr->sys_reserve - res_type_ptr->sys_reserve_used;
	}
	else
	{
		retval = 0;
	}
	//vm_log_debug("vm_res_type_avaliable_handle : end, result=%d", retval);
	return retval;	
}


VMINT vm_res_type_set_notify_callback(VMINT data_type, vm_res_release_callback_t notify_function_ptr)
{
	VMINT retval = VM_RES_INTERNAL_ERROR;
	vm_mi_res_type_node_t* res_type_ptr = NULL;

	res_type_ptr = vm_scan_res_type_table(data_type);	

	if (res_type_ptr != NULL)
	{
		if (notify_function_ptr != NULL)
		{
			res_type_ptr->release_callback = notify_function_ptr;
			retval = VM_RES_OK;
		}
		else
		{
			res_type_ptr->release_callback = NULL;
			retval = VM_RES_INVALID_DATA;
		}
	}
	else
	{
		retval = VM_RES_INVALID_HANDLE;
	}
	return retval;
}


vm_res_release_callback_t vm_res_type_get_notify_callback(VMINT data_type)
{
	vm_mi_res_type_node_t* res_type_ptr = NULL;

	res_type_ptr = vm_scan_res_type_table(data_type);	

	if (res_type_ptr != NULL)
	{
		return res_type_ptr->release_callback;
	}
	else
	{
		return NULL;
	}
}


VMINT vm_res_get_data_list_count_by_proecss(VM_P_HANDLE process_handle, VMINT data_type)
{
	vm_mi_res_type_node_t* res_type_ptr = NULL;
	vm_mi_res_node_t* res_ptr = NULL;
	VMINT rescount = 0;

	//vm_log_debug("vm_res_get_data_list_count_by_proecss : start,p_handle=%d, data_type=%d", process_handle, data_type);

	if (data_type <= VM_RES_TYPE_START || data_type >= VM_RES_TYPE_TOTAL)
		return 0;
	
	res_type_ptr = vm_res_ptr;

	/*遍历删除所有类型的队列*/
	while (res_type_ptr != NULL)
	{	
		if ((data_type == VM_RES_TYPE_TOTAL) || (data_type == res_type_ptr->type))
		{
			res_ptr = res_type_ptr->res_list_ptr;
			/*遍历删除指定类型的所有资源*/
			while(res_ptr != NULL)
			{
				if(res_ptr->phandle == process_handle)
					rescount++;
				res_ptr = res_ptr->next;				
			}			
		}
		res_ptr = NULL;
		res_type_ptr = res_type_ptr->next;
	}
	//vm_log_debug("vm_res_get_data_list_count_by_proecss : end, rescount=%d", rescount);
	return rescount;
	
}

/*获取进程已经占用资源的数量*/
VMINT vm_res_get_data_list_by_proecss(VM_P_HANDLE process_handle, VMINT data_type, vm_res_node_t* data_list, VMINT data_list_count)
{
	vm_mi_res_type_node_t* res_type_ptr = NULL;
	vm_mi_res_node_t* res_ptr = NULL;
	vm_res_node_t* data_list_ptr = NULL;
	VMINT resindex = 0;

	//vm_log_debug("vm_res_get_data_list_by_proecss : start,p_handle=%d, data_type=%d", process_handle, data_type);
	
	res_type_ptr = vm_res_ptr;

	if (data_type <= VM_RES_TYPE_START || data_type >= VM_RES_TYPE_TOTAL)
		return 0;
	if (data_list == NULL || data_list_count <= 0)
		return 0;

	data_list_ptr = data_list;
	
	/*遍历删除所有类型的队列*/
	while(res_type_ptr != NULL)
	{
		if (data_type == VM_RES_TYPE_TOTAL || data_type == res_type_ptr->type)
		{
			res_ptr = res_type_ptr->res_list_ptr;
			/*遍历删除指定类型的所有资源*/
			while(res_ptr != NULL)
			{
				if(res_ptr->phandle == process_handle) /*资源属于参数进程句柄*/
				{
					/*复制数据*/
					data_list_ptr->res_id = res_ptr->res_id;
					data_list_ptr->res_callback = res_ptr->res_callback;
					data_list_ptr->phandle = res_ptr->phandle;
					data_list_ptr->mtk_res_id = res_ptr->mtk_res_id;
					data_list_ptr->data_content = res_ptr->data_content;
					data_list_ptr->data_size = res_ptr->data_size;
					data_list_ptr->state = res_ptr->data_state;
					data_list_ptr++;
					
					resindex++;
					if (resindex >= data_list_count)
					{
						//vm_log_debug("vm_res_get_data_list_by_proecss : end, rescount=%d", resindex);
						return resindex;
					}
				}
				res_ptr = res_ptr->next;				
			}	
		}		
		res_type_ptr = res_type_ptr->next;
	}
	//vm_log_debug("vm_res_get_data_list_by_proecss : end, rescount=%d", resindex);
	return resindex;
}


VMINT vm_res_get_data_list_count_by_type(VMINT data_type)
{
	vm_mi_res_type_node_t* res_type_ptr = NULL;
	vm_mi_res_node_t* res_ptr = NULL;
	VMINT rescount = 0;

	//vm_log_debug("vm_res_get_data_list_count_by_type : start, data_type=%d", data_type);
	
	if (data_type <= VM_RES_TYPE_START || data_type >= VM_RES_TYPE_TOTAL)
		return 0;
	
	res_type_ptr = vm_res_ptr;

	/*遍历删除所有类型的队列*/
	while (res_type_ptr != NULL)
	{	
		if (data_type == res_type_ptr->type)
		{
			res_ptr = res_type_ptr->res_list_ptr;
			/*遍历删除指定类型的所有资源*/
			while(res_ptr != NULL)
			{
				rescount++;
				res_ptr = res_ptr->next;				
			}			
		}
		res_ptr = NULL;
		res_type_ptr = res_type_ptr->next;
	}
	//vm_log_debug("vm_res_get_data_list_count_by_type : end, rescount=%d", rescount);
	return rescount;
}



VMINT vm_res_get_data_list_by_type(VMINT data_type, vm_res_node_t* data_list, VMINT data_list_count)
{
	vm_mi_res_type_node_t* res_type_ptr = NULL;
	vm_mi_res_node_t* res_ptr = NULL;
	vm_res_node_t* data_list_ptr = NULL;
	VMINT resindex = 0;

	//vm_log_debug("vm_res_get_data_list_by_type : start, data_type=%d", data_type);
	
	if (data_type <= VM_RES_TYPE_START || data_type >= VM_RES_TYPE_TOTAL)
		return 0;
	if (data_list == NULL || data_list_count <= 0)
		return 0;
	
	res_type_ptr = vm_res_ptr;
	data_list_ptr = data_list;
	

	/*遍历删除所有类型的队列*/
	while(res_type_ptr != NULL)
	{
		res_ptr = NULL;
		if (data_type == res_type_ptr->type)
		{
			res_ptr = res_type_ptr->res_list_ptr;
			/*遍历删除指定类型的所有资源*/
			while(res_ptr != NULL)
			{
				/*复制数据*/
				data_list_ptr->res_id = res_ptr->res_id;
				data_list_ptr->res_callback = res_ptr->res_callback;
				data_list_ptr->phandle = res_ptr->phandle;
				data_list_ptr->mtk_res_id = res_ptr->mtk_res_id;
				data_list_ptr->data_content = res_ptr->data_content;
				data_list_ptr->data_size = res_ptr->data_size;
				data_list_ptr->state = res_ptr->data_state;
				data_list_ptr++;
				
				resindex++;
				if (resindex >= data_list_count)
				{
					//vm_log_debug("vm_res_get_data_list_by_type : end, rescount=%d", resindex);
					return resindex;
				}
				
				res_ptr = res_ptr->next;				
			}			
		}		
		res_type_ptr = res_type_ptr->next;
	}
	
	//vm_log_debug("vm_res_get_data_list_by_type : end, rescount=%d", resindex);
	return resindex;
}


VMINT vm_res_notify_data_by_process(VM_P_HANDLE process_handle, VMINT process_state)
{
	vm_mi_res_type_node_t* res_type_ptr = NULL;
	VMINT count = 0;

	res_type_ptr = vm_res_ptr;	

	/*遍历删除所有类型的队列*/
	while (res_type_ptr != NULL)
	{
		if (res_type_ptr->release_callback != NULL)
		{
			res_type_ptr->release_callback(process_handle, process_state);
			count++;
		}
		res_type_ptr = res_type_ptr->next;
	}
	//vm_log_debug("vm_res_notify_data_by_process, end. Have notify all module");
	MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RES_MAN_HAVE_NOTIFY_ALL_MODULE);
	return count;	
}

#define VMRES_STACK_OK 1
#define VMRES_STACK_FAIL -1
#define VMRES_STACK_FREE -1
static VMINT vm_res_get_stacktop(VMINT data_type)
{
	VMINT result = VMRES_STACK_FREE;
	VMINT i = 0;
	vm_mi_res_type_node_t * res_type_p = NULL;
	res_type_p = vm_scan_res_type_table(data_type);

	if (res_type_p != NULL)
	{
		for(i = 4; i >= 0; i--)
		{			
			if (res_type_p->find_stack[i] != VMRES_STACK_FREE)
			{
				result = res_type_p->find_stack[i];
				//vm_log_debug("vm_res_get_stacktop : res_type_p->find_stack[%d]=%d", i , res_type_p->find_stack[i]);
				break;
			}
		}
	}
	return result;
}

static VMINT vm_res_modi_stacktop(VMINT data_type, VMINT res_id)
{
	VMINT result = VMRES_STACK_FREE;
	VMINT i = 0;
	vm_mi_res_type_node_t * res_type_p = NULL;
	res_type_p = vm_scan_res_type_table(data_type);
	

	if (res_type_p != NULL)
	{
		for(i = 4; i >= 0; i--)
		{
			if (res_type_p->find_stack[i] != VMRES_STACK_FREE)
			{
				res_type_p->find_stack[i] = res_id;
				result = res_type_p->find_stack[i];
				//vm_log_debug("vm_res_modi_stacktop i=%d, stacktop=%d", i, res_type_p->find_stack[i]);
				break;
			}
		}
	}
	//vm_log_debug("vm_res_modi_stacktop : end datatype=%d, res_id=%d, stack[%d]=%d", data_type, i, res_type_p->find_stack[i]);
	return result;
}

static VMINT vm_res_pop(VMINT data_type)
{
	VMINT result = VMRES_STACK_FREE;
	VMINT i = 0;
	vm_mi_res_type_node_t * res_type_p = NULL;
	res_type_p = vm_scan_res_type_table(data_type);
	

	if (res_type_p != NULL)
	{
		for(i = 4; i >= 0; i--)
		{
			if (res_type_p->find_stack[i] != VMRES_STACK_FREE)
			{
				result = res_type_p->find_stack[i];
				res_type_p->find_stack[i] = VMRES_STACK_FREE;
				break;
			}
		}
	}
	return result;
}

static VMINT vm_res_push(VMINT data_type, VMINT res_id)
{
	VMINT i = 0;
	vm_mi_res_type_node_t * res_type_p = NULL;
	res_type_p = vm_scan_res_type_table(data_type);

	if (res_type_p != NULL)
	{
		for (i = 0 ; i < 5; i++)
		{
			if (res_type_p->find_stack[i] == VMRES_STACK_FREE)
			{
				res_type_p->find_stack[i] = res_id;				
				break;
			}
		}
		//vm_log_debug("vm_res_push : res_type_p->find_stack[%d]=%d", i , res_type_p->find_stack[i]);
		if (i == 5)
			return VMRES_STACK_FAIL;
		else
			return VMRES_STACK_OK;
	}
	return VMRES_STACK_FAIL;
}


VMINT vm_res_findfirst(VM_P_HANDLE process_handle, VMINT data_type)
{
	VMINT result = VM_RES_NOT_FIND;
	vm_mi_res_node_t * res_node_p = NULL;
	vm_mi_res_type_node_t * res_type_p = NULL;
	res_type_p = vm_scan_res_type_table(data_type);

	if (res_type_p != NULL)
	{
		/*
		res_node_p = res_type_p->res_list_ptr;
		while(res_node_p != NULL)
		{
			res_node_p->scan_token = FALSE;
			res_node_p = res_node_p->next;
		}
		*/
		res_node_p = res_type_p->res_list_ptr;
		while(res_node_p != NULL)
		{
			if ((process_handle == res_node_p->phandle) || (process_handle == -1))
			{				
				break;
			}
			res_node_p = res_node_p->next;
		}
		if (res_node_p != NULL)
		{
			//vm_log_debug("vm_res_findfirst : have scan res_id=%d", res_node_p->res_id);
			/*压栈*/
			if (vm_res_push(data_type, res_node_p->res_id) == VMRES_STACK_OK)
			{
				result = res_node_p->res_id;
				//vm_log_debug("vm_res_findfirst : have scan res_id=%d", res_node_p->res_id);
				//res_node_p->scan_token = TRUE;
			}
			else
			{
				result = VM_RES_NOT_FIND;
			}
		}
		else
		{
			result = VM_RES_NOT_FIND;
		}
	}
	else
	{
		result = VM_RES_NOT_FIND;
	}
	return result;
}

VMINT vm_res_findnext(VM_P_HANDLE process_handle, VMINT data_type)
{
	VMINT resid = VMRES_STACK_FREE;
	VMINT result = VM_RES_NOT_FIND;
	vm_mi_res_node_t * res_node_p = NULL;
	vm_mi_res_type_node_t * res_type_p = NULL;
	res_type_p = vm_scan_res_type_table(data_type);

	//vm_log_debug("vm_res_findnext : start p=%d, type=%d", process_handle, data_type);

	if (res_type_p != NULL)
	{
		resid = vm_res_get_stacktop(data_type);
		//vm_log_debug("vm_res_findnext : vm_res_get_stacktop resid=%d", resid);
		if (resid == VMRES_STACK_FREE)
			return VM_RES_NOT_FIND;
		
		res_node_p = res_type_p->res_list_ptr;
		while((res_node_p != NULL) )
		{			
			//if (res_node_p->scan_token == TRUE)
			if (res_node_p->res_id == resid)
			{	
				break;
			}
			res_node_p = res_node_p->next;
		}
		//vm_log_debug("vm_res_findnext : loop get resid=%d", res_node_p->res_id);
		if (res_node_p != NULL)
		{
			res_node_p = res_node_p->next;
		}
		/*
		if (res_node_p != NULL)
		{
			res_node_p->scan_token = FALSE;
			res_node_p = res_node_p->next;
		}
		*/
	
		while(res_node_p != NULL)
		{
			//vm_log_debug("vm_res_findnext :will scan res_id=%d, p=%d", res_node_p->res_id, res_node_p->phandle);
			if ((process_handle == res_node_p->phandle) || (process_handle == -1))
			{				
				break;
			}
			res_node_p = res_node_p->next;
		}
		if (res_node_p != NULL)
		{
			if (vm_res_modi_stacktop(data_type, res_node_p->res_id) > VMRES_STACK_FREE)
			{
				//res_node_p->scan_token = TRUE;				
				result = res_node_p->res_id;
				//vm_log_debug("vm_res_findnext :scan res_id=%d", res_node_p->res_id);
			}
			else
			{
				result = VM_RES_NOT_FIND;
			}
		}
		else
		{
			result = VM_RES_NOT_FIND;
		}
	}
	else
	{
		result = VM_RES_NOT_FIND;
	}
	return result;
}

void vm_res_findclose(VMINT data_type)
{
	//vm_mi_res_node_t * res_node_p = NULL;
	vm_mi_res_type_node_t * res_type_p = NULL;
	res_type_p = vm_scan_res_type_table(data_type);

	if (res_type_p != NULL)
	{
		/*
		res_node_p = res_type_p->res_list_ptr;
		while(res_node_p != NULL)
		{
			res_node_p->scan_token = FALSE;
			res_node_p = res_node_p->next;
		}
		*/
		vm_res_pop(data_type);
		//vm_log_debug("vm_res_findclose");
	}
	
}

static void vm_res_init_data_type_node(vm_mi_res_type_node_t * restype_ptr, VMINT type, VMINT attr, VMINT total, VMINT sysreserve, VMINT max_pro)
{
	VMINT i = 0;

	if (restype_ptr == NULL)
		return;
	
	restype_ptr->attr = attr;
	restype_ptr->next = NULL;
	restype_ptr->release_callback = NULL;
	restype_ptr->res_list_ptr = NULL;
	restype_ptr->total = total;
	restype_ptr->sys_reserve = sysreserve;
	restype_ptr->sys_reserve_used = 0;
	if (restype_ptr->attr == VM_RES_ATTRIBUTE_EXCLUSIVE)
	{
		restype_ptr->total_per_proc = total - sysreserve;
	}
	else
	{
		if (type == VM_RES_TYPE_FILE)
		{
			restype_ptr->total_per_proc = total - sysreserve;
		}
		else
		{
			restype_ptr->total_per_proc = ((total - sysreserve)/max_pro + 1);
		}
	}
	vm_app_res_info(VM_RES_APP_ID_TOTAL, type, total , sysreserve, 0);
	restype_ptr->type = type;
	restype_ptr->used = 0;
	for (i = 0; i < 5; i++)
		restype_ptr->find_stack[i] = VMRES_STACK_FREE;
}


static void vm_res_init_data_type(VMINT type, vm_mi_res_type_node_t * restype_ptr)
{
	VMINT max_pro_num = vm_pmng_max_counter();
	VMINT total = 1;
	VMINT sysreserve = 0;
	vm_res_attribute_enum attribute = VM_RES_ATTRIBUTE_EXCLUSIVE;
	
	if (restype_ptr == NULL)
		return;
	
	switch(type) 
	{
    case VM_RES_TYPE_FILE:
    case VM_RES_TYPE_FILE_FIND:
        total = (VMINT)FS_CountUsedFH(FS_FH_COUNT_AVAILABLE);
        sysreserve = 3;                             
        break;
	case VM_RES_TYPE_TIMER:
	case VM_RES_TYPE_TIMER_EX:
	    total = 50;
	    sysreserve = 10;
	    break;
	case VM_RES_TYPE_SMS_HANDLE:
	case VM_RES_TYPE_MMS_HANDLE:
	case VM_RES_TYPE_PHONE_BOOK:
	    total = 20;
		break;
		
	case VM_RES_TYPE_INPUT_KEY:
	case VM_RES_TYPE_ALARM:
    case VM_RES_TYPE_GPS:
	case VM_RES_TYPE_CELL:	
		total = 10;
		break;
	case VM_RES_TYPE_TCP_HANDLE:
	    total = 12;
	    sysreserve = 5;
		break;
	case VM_RES_TYPE_HTTP_HANDLE:
#ifdef __MRE_SAL_SOCKET__
    case VM_RES_TYPE_UDP_HANDLE:
#endif		
		total = 12;
	    sysreserve = 3;    
		break;
	case VM_RES_TYPE_WPS_HANDLE:
	case VM_RES_TYPE_DA:
	case VM_RES_TYPE_COMMON_UI:
		total = 4;
		break;            
		
	case VM_RES_TYPE_MIDI_HANDLE:
	    total = max_pro_num;			
		break;

	case VM_RES_TYPE_LAYER_HANDLE:
		total = 16;
		break;

	case VM_RES_TYPE_GRAPHIC_CXT:
	    total = max_pro_num * 16;
	    attribute = VM_RES_ATTRIBUTE_CONCURRENT;
		break;
#ifdef __MRE_SAL_SOCKET__
    case VM_RES_TYPE_PRELOAD:
        total = max_pro_num > 5?max_pro_num:5;
        sysreserve = 5;
	    attribute = VM_RES_ATTRIBUTE_CONCURRENT;
        break;
#endif
        
    case VM_RES_TYPE_FS_ASYNC:
    case VM_RES_TYPE_TLS:
        total = 100;
        break;
        
	//exlusive only one
	case VM_RES_TYPE_CAMERA:
	case VM_RES_TYPE_CALLOUT:
    case VM_RES_TYPE_IVR:	
	case VM_RES_TYPE_INPUT_SYS:
	case VM_RES_TYPE_INPUT_PEN:
	case VM_RES_TYPE_VIDEO_HANDLE:
	case VM_RES_TYPE_AUDIO_HANDLE:
	case VM_RES_TYPE_AUDIO_BIT_HANDLE:
	case VM_RES_TYPE_RECORD_HANDLE:
	case VM_RES_TYPE_IME:
	case VM_RES_TYPE_SELECTOR:
	case VM_RES_TYPE_BTCM:
	case VM_RES_TYPE_BTSPP:
	case VM_RES_TYPE_MULTI_TOUCH:
	case VM_RES_TYPE_FOLDER_BROWSER:
	case VM_RES_TYPE_FOLDER_SELECTOR:
		break;	
		
    //concurrent only one
	case VM_RES_TYPE_STATUS_BAR:

	case VM_RES_TYPE_SENSOR:
	case VM_RES_TYPE_SMS_INTERRUPT:
	case VM_RES_TYPE_MMS_INTERRUPT:
	case VM_RES_TYPE_SMS_INTERRUPT_EX:
	case VM_RES_TYPE_WLAN_LOC:
	case VM_RES_TYPE_APPMGR:
	case VM_RES_TYPE_AUDIO_INTERRUPT:
#ifdef __MMI_QUERY_SRV__		
	case VM_RES_TYPE_GET_SERVICE:
#endif	
	    attribute = VM_RES_ATTRIBUTE_CONCURRENT;
		break;		
	case VM_RES_TYPE_MD5:
	case VM_RES_TYPE_SHA1:
		total = max_pro_num;
		sysreserve = 1;
		break;
		
    default:
        break;
	}
    vm_res_init_data_type_node(
        restype_ptr,  					/*type node ptr*/
        type, 							/*type*/
        attribute, 	                    /*type attr*/ 
        total, 							/*totoal*/
        sysreserve, 					/*sysreserve*/
        max_pro_num);	
}

void vm_res_print_monitor_log(VM_P_HANDLE p, VMINT res_type)
{
	vm_mi_res_type_node_t* res_type_ptr = NULL;
	res_type_ptr = vm_scan_res_type_table(res_type);
	if(NULL == res_type_ptr)
		return;
	if(p == 0)  //sys process
	{
		vm_app_res_info(VM_RES_APP_ID_TOTAL,
			res_type,
			res_type_ptr->total - res_type_ptr->sys_reserve,//total
			res_type_ptr->used,//used
			0);//peak
	}
	else
	{
		vm_app_res_info(p,
			res_type,
			res_type_ptr->total_per_proc,//total
			vm_res_get_data_list_count_by_proecss(p, res_type),//used
			0);//peak
	}
}
#endif
