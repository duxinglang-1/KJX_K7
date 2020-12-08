
#ifndef _VM_RES_MNG_
#define	_VM_RES_MNG_
#include "vmswitch.h"
#ifdef __MRE_CORE_RESOURCE_MANAGE__

#include "vmsys.h"
#include "vmpromng.h"

typedef void (*vm_res_release_callback_t)(VM_P_HANDLE process_handle, VMINT sys_state);

typedef struct vm_res_node_t {
VM_P_HANDLE   phandle;	/*资源所处的进程句柄*/
VMINT    res_id;			/*资源句柄*/
void*     res_callback;		/*资源的回调函数指针*/
VMINT    mtk_res_id;		/*和资源对应的mtk资源句柄*/
void*    data_content;		/*资源相关数据块首地址指针*/
VMINT  data_size;		/*资源相关数据块大小*/
VMINT  state;				/*资源有关的一些状态。*/
						/*(此状态不是资源占用情况，只是方便用户自己记录资源的一些使用情况。由用户自己定义使用。)*/
}  vm_res_node_t ;

/**
 * 进程资源分为2种模式，一种是独占资源，另一种为非独占资源。
 * 每一种独占资源的包含1个handle，非独占式的handle的数量由系统决定
 * 每一个资源的handle有3个属性：状态，归属进程及设置的资源。
 */
typedef enum{	
		VM_RES_TYPE_START = 0,
		VM_RES_TYPE_FILE ,
		VM_RES_TYPE_FILE_FIND,
		VM_RES_TYPE_TIMER,
		VM_RES_TYPE_TIMER_EX,
		VM_RES_TYPE_SMS_HANDLE,
		VM_RES_TYPE_MMS_HANDLE,
		VM_RES_TYPE_MMS_INTERRUPT,
		VM_RES_TYPE_CAMERA,
		VM_RES_TYPE_CALLOUT,
		VM_RES_TYPE_IVR,
		VM_RES_TYPE_PHONE_BOOK,
		VM_RES_TYPE_INPUT_SYS,
		VM_RES_TYPE_INPUT_KEY,
		VM_RES_TYPE_INPUT_PEN,
		VM_RES_TYPE_IME,
		VM_RES_TYPE_TCP_HANDLE,
		VM_RES_TYPE_HTTP_HANDLE,
		VM_RES_TYPE_WPS_HANDLE,		
		VM_RES_TYPE_PROCESS_PARAM,
		VM_RES_TYPE_VIDEO_HANDLE,
		VM_RES_TYPE_AUDIO_HANDLE,
		VM_RES_TYPE_AUDIO_BIT_HANDLE,
		VM_RES_TYPE_MIDI_HANDLE,
		VM_RES_TYPE_RECORD_HANDLE,
		VM_RES_TYPE_GPS,
		VM_RES_TYPE_CELL,
		VM_RES_TYPE_LAYER_HANDLE,
		VM_RES_TYPE_GRAPHIC_CXT,
		VM_RES_TYPE_STATUS_BAR,
		VM_RES_TYPE_PAYMENT,
		VM_RES_TYPE_MD5,
		VM_RES_TYPE_SHA1,
		VM_RES_TYPE_SENSOR,
        VM_RES_TYPE_EBOOK,
		VM_RES_TYPE_SMS_INTERRUPT,
		VM_RES_TYPE_SMS_INTERRUPT_EX,
		VM_RES_TYPE_DAEMON,
		VM_RES_TYPE_DLA,
        VM_RES_TYPE_VRT,
        VM_RES_TYPE_FONT,
        VM_RES_TYPE_VENUS_IME,
		VM_RES_TYPE_VFX,
		VM_RES_TYPE_SELECTOR,
		VM_RES_TYPE_WLAN_LOC,
		VM_RES_TYPE_BTCM,
		VM_RES_TYPE_BTSPP,
		VM_RES_TYPE_PRELOAD,
		VM_RES_TYPE_UDP_HANDLE,
		VM_RES_TYPE_MULTI_TOUCH,
		VM_RES_TYPE_FS_ASYNC,
		VM_RES_TYPE_APPMGR,
		VM_RES_TYPE_DA,
		VM_RES_TYPE_GET_SERVICE,
		VM_RES_TYPE_ALARM,
		VM_RES_TYPE_AUDIO_INTERRUPT,
		VM_RES_TYPE_FOLDER_BROWSER,
        VM_RES_TYPE_TLS,
		VM_RES_TYPE_COMMON_UI,
		VM_RES_TYPE_FOLDER_SELECTOR,     
		VM_RES_TYPE_TOTAL
} vm_res_type_enum;

#define VM_RES_TYPE_MEMORY  200
#define VM_RES_TYPE_APP_NAME    2010

#define VM_RES_APP_ID_TOTAL 2011

#define VM_RES_VALUE_NOT_AVAILABLE  -1

#define VM_RES_MONITOR_LOG_INTERVAL 50

typedef struct vm_res_monitor_init_struct
{
    VM_P_HANDLE p_handle; //process handle needed to init in resource monitor
    VMINT res_type; //next resource type;
    struct vm_res_monitor_init_struct * next_app; //next process node
}vm_res_monitor_init_struct;

typedef enum{
		VM_RES_ATTRIBUTE_CONCURRENT = 0,
		VM_RES_ATTRIBUTE_EXCLUSIVE,
		VM_RES_ATTRIBUTE_TOTAL
} vm_res_attribute_enum;


typedef enum{
		VM_RES_STATE_USED = 0,
		VM_RES_STATE_IDLE,
		VM_RES_STATE_TOTAL
} vm_res_state_enum;

typedef enum{
		//vm_res_find
		VM_RES_NOT_FIND = -9,
		
		//vm_res_init
		VM_RES_INIT_FAIL,
		
		//vm_res_save_data & vm_res_get_data
		VM_RES_INVALID_TYPE,
		VM_RES_INVALID_DATA,
		VM_RES_OUT_OF_RESOURCE,
		VM_RES_INVALID_BUFFER,
		VM_RES_INSUFFICIENT_BUFFER,
		VM_RES_INVALID_HANDLE,
		
		VM_RES_INTERNAL_ERROR,
		VM_RES_OK
} vm_res_retcode_enum;


/**
 * 初始化内核资源管理模块。
 *
 * @param 
 *
 * @return	如果证书系统初始化成功，返回值为0，失败返回错误码。
 */
VMINT vm_res_initialize( void );


/**
 * 结束内核资源管理模块。
 *
 * @param 
 *
 * @return
 */
void vm_res_finialize( void );


/**
 * 保存资源。
 *
 * @param data_type		资源类型。
 * @param data_content	与资源类型对应的资源内容。
 * @param process_handle	归属进程ID，VM_PMNG_CUR_HANDLE 表示当前进程ID。。
 *
 * @return				存储资源的句柄（非负值），如果资源存储失败，返回错误码。
 */
VMINT vm_res_save_data( VMINT data_type, void * data_content, VMINT data_size, void* callback, VM_P_HANDLE process_handle );


/**
 * 向资源列表注册mtk资源句柄，形成mre资源句柄和mtk资源句柄映射关系。
 * 如果该资源没有mtk资源句柄，可不使用。
 *
 * @param data_type		资源类型。
 * @param data_handle		资源的存储句柄。
 * @param reshandle		mtk资源句柄。
 *
 * @return				获取资源成功返回0，否则返回负数的错误码。
 */
VMINT vm_res_set_mtk_reshandle(VMINT data_type, VMINT data_handle, VMINT mtk_res_handle);

/**
 * 获取对应的mtk资源句柄。
 *
 * @param data_type		资源类型。
 * @param data_handle		资源的存储句柄。
 * @param reshandle		mtk资源句柄。
 *
 * @return				获取资源成功返回0，否则返回负数的错误码。
 */
VMINT vm_res_get_mtk_reshandle(VMINT data_type, VMINT data_handle, VMINT * mtk_res_handle);

/**
 * 设置资源数据。
 *
 * @param data_type		资源类型。
 * @param data_handle		资源的存储句柄。
 * @param data_buffer		接受资源数据的缓存。 
 * @param data_size		资源缓存数据的大小。
 *
 * @return				获取资源成功返回0，否则返回负数的错误码。
 */
VMINT vm_res_set_data( VMINT data_type, VMINT	data_handle, void * data_buffer, VMINT buffer_size );

/**
 * 获取资源数据。
 *
 * @param data_type		资源类型。
 * @param data_handle		资源的存储句柄。
 * @param data_buffer		接受资源数据的缓存。 
 * @param data_size		资源缓存数据的大小()。
 *
 * @return				获取资源成功返回0，否则返回负数的错误码。
 */
VMINT vm_res_get_data( VMINT data_type, VMINT	data_handle, void ** data_buffer, VMINT * buffer_size );

/**
 * 设置回调。
 *
 * @param data_type		资源类型。
 * @param data_handle		资源的存储句柄。
 * @param callback		资源回调函数(此资源回调为app调用某接口所注册的回调)，可为空。
 *
 * @return				获取资源成功返回0，否则返回负数的错误码。
 */
VMINT vm_res_set_callback( VMINT data_type, VMINT	data_handle, void* callback );

/**
 * 获取回调。
 *
 * @param data_type		资源类型。
 * @param data_handle		资源的存储句柄。
 * @param callback		资源回调函数(此资源回调为app调用某接口所注册的回调)，可为空。
 *
 * @return				获取资源成功返回0，否则返回负数的错误码。
 */
VMINT vm_res_get_callback( VMINT data_type, VMINT	data_handle, void** callback );


/**
 * 获取资源对应的进程句柄。
 *
 * @param data_type		资源类型。
 * @param data_handle		资源资源句柄。
 *
 * @return				成功返回进程句柄，否则返回负数。
 */
VM_P_HANDLE vm_res_get_process_handle( VMINT data_type, VMINT data_handle );



/**
 * 释放资源。
 *
 * @param data_type		资源类型。
 * @param data_handle		资源的存储句柄。
 *
 * @return				释放资源时，同时释放资源handle
 */
VMINT vm_res_release_data( VMINT data_type, VMINT	data_handle );


/**
 * 查询资源类型的属性。
 *
 * @param data_type			资源类型。
 *
 * @return					获取资源类型的属性，独占式或非独占式。
 */
VMINT	vm_res_type_attribute( VMINT data_type );


/**
 * 查询资源类型的容量。
 *
 * @param data_type			资源类型。
 *
 * @return					获取资源类型的容量。
 */
VMINT vm_res_type_max_handle( VMINT data_type );


/**
 * 注册通知关闭资源回调函数指针。
 * 
 * 
 * @param data_type			资源类型。
 * @param release_function_ptr	关闭资源回调函数指针。
 *
 *  @return					成功返回0，否则返回负数的错误码。
 *
 */
VMINT vm_res_type_set_notify_callback(VMINT data_type, vm_res_release_callback_t notify_function_ptr);


/**
 * 获取关闭资源回调函数指针
 * 
 * @param data_type			资源类型。
 *
 *  @return					成功返回资源回调函数指针，否则返回NULL。
 */
vm_res_release_callback_t vm_res_type_get_notify_callback(VMINT data_type);

/**
 * 查询资源类型的可用数量（还未使用）。
 *
 * @param data_type			资源类型。
 *
 * @return							获取资源类型的可用数量（还未使用）。
 */
VMINT vm_res_type_avaliable_handle( VMINT data_type, VM_P_HANDLE process_handle);


/**
 * 查询资源的状态，此状态由用户自己定义和使用。和资源本身占用情况无关。
 * 
 *
 * @param data_type		资源类型。
 * @param data_handle		资源句柄。
 *
 * @return				资源的状态。
 */
VMINT vm_res_get_handle_state( VMINT data_type, VMINT data_handle );


/**
 * 设置资源的状态，此状态由用户自己定义和使用。和资源本身占用情况无关。
 *
 * @param data_type		资源类型。
 * @param data_handle		资源句柄。
 * @param data_state		资源的状态。
 *
 * @return							设置成功返回0，失败返回负数的错误码。
 */
VMINT vm_res_set_handle_state( VMINT data_type, VMINT data_handle, VMINT data_state );

/**
 * 获取进程已经占用资源的数量。
 *
 * @param process_handle	进程句柄。
 * @param data_type		资源类型。类型说明请参照vm_res_type_enum。
 *						如果需要获取所有类型资源，请输入VM_RES_TYPE_TOTAL。
 *
 * @return				进程已经占用资源的数量
 */
VMINT vm_res_get_data_list_count_by_proecss(VM_P_HANDLE process_handle, VMINT data_type);


/**
 * 获取进程已经占用资源列表
 *
 * @param process_handle	进程句柄。
 * @param data_type		资源类型。类型说明请参照vm_res_type_enum。
 *						如果需要获取所有类型资源，请输入VM_RES_TYPE_TOTAL。
 * @param data_list		资源列表数组首地址。(该列表空间由用户申请)
 * @param data_list_count	资源列表数组的长度。
 *
 * @return				进程已经占用资源的数量 
 */
VMINT vm_res_get_data_list_by_proecss(VM_P_HANDLE process_handle, VMINT data_type, vm_res_node_t* data_list, VMINT data_list_count);

/**
 * 获取指定资源类型已经占用资源的数量。
 *
 * @param data_type		资源类型。类型说明请参照vm_res_type_enum。
 *						取值范围小于VM_RES_TYPE_TOTAL。
 *
 * @return				进程已经占用资源的数量
 */
VMINT vm_res_get_data_list_count_by_type(VMINT data_type);

/**
 * 获取指定资源类型已经占用资源列表
 *
 * @param data_type		资源类型。类型说明请参照vm_res_type_enum。
 *						取值范围小于VM_RES_TYPE_TOTAL。
 * @param data_list		资源列表数组首地址。(该列表空间由用户申请)
 * @param data_list_count	资源列表数组的长度。
 *
 * @return				进程已经占用资源的数量 
 */
VMINT vm_res_get_data_list_by_type(VMINT data_type, vm_res_node_t* data_list, VMINT data_list_count);
	

/**
 * 系统通知资源管理做退出保护
 */
VMINT vm_res_notify_data_by_process(VM_P_HANDLE process_handle, VMINT process_state);

/**
  *	vm_res_findfirst, vm_res_findnext, vm_res_close三个函数提供一组资源查找的方法。
  *	@param process_handle	检索和该进程相关的资源(如果为-1,说明检索该类所有资源)。
  *	@param data_type			资源类型。
  *
  *	@return		检索成功返回资源的句柄，失败返回VM_RES_NOT_FIND。
  *
  *	注如果该资源发生变化，例如增加删减，请重新findfirst。
  *
  *	vm_res_findfirst使用例程
  *	VMINT i;
  *	i = vm_res_findfirst(phandle, VM_RES_TYPE_TIMER);
  *	vm_log_debug("vm_timer_proc : vm_res_findfirst timerid=%d", i);
  *	while ( i != VM_RES_NOT_FIND)
  *	{
  *		i = vm_res_findnext(phandle, VM_RES_TYPE_TIMER);
  *		vm_log_debug("vm_timer_proc : vm_res_findnext timerid=%d", i);
  *	}
  *	vm_res_findclose(VM_RES_TYPE_TIMER);
  *
  */
VMINT vm_res_findfirst(VM_P_HANDLE process_handle, VMINT data_type);
VMINT vm_res_findnext(VM_P_HANDLE process_handle, VMINT data_type);
void vm_res_findclose(VMINT data_type);

void vm_print_res_table(VMINT type);
void vm_res_print_monitor_log(VM_P_HANDLE p, VMINT res_type);
#endif
#endif
