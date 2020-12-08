#ifndef __VM_EXTERNAL_SENSOR__
#define __VM_EXTERNAL_SENSOR__

#include "vmsys.h"
//#include "vmopt.h"

/**
 * @name MRE核心管理的数据结构.
 * @{
 */
/**
 * 启动外部传感器, 0为启动成功否则为错误码.	
  */
typedef VMINT (*vm_start_ext_sensor_func)(void);
 /**
  * 关闭外部传感器, 0为启动成功否则为错误码.	
  */
typedef VMINT (*vm_stop_ext_sensor_func)(void);
/**
  * 设置数值类型的传感器的值, 0 为设置成功否则为错误码. 
  */
typedef VMINT (*vm_set_ext_numeric_option_func)(const VMSTR control_name, VMINT opt_value);
/**
  * 设置字符类型的传感器的值, 0 为设置成功否则返回错误码. 		
  */
typedef VMINT (*vm_set_ext_string_option_func)(const VMSTR control_name, VMSTR opt_value);
/**@} */

/**
 * MRE集成外部sensor接口的核心管理结构.
 */
typedef struct vm_core_scb_t {
	VMCHAR sensor_name[100];							/**<传感器的名称,各个物理传感器的名称必须不同.
														命名规范请参看vm_freescale_MMA7455L.h里的USE_SENSOR_NAME 
														宏定义.															*/
	vm_start_ext_sensor_func start_ext_sensor;			/**<启动传感器的函数指针.									*/
	vm_stop_ext_sensor_func stop_ext_sensor;				/**<停止传感器的函数指针.									*/
	vm_set_ext_numeric_option_func set_numeric_option;	/**<设置数值类型的传感器的值.								*/
	vm_set_ext_string_option_func set_string_option;		/**<设置字符类型的传感器的值.								*/
} vm_core_scb_t;

/**
 * @name vm_register_enternal_sensor函数的返回值.
 * @{
 */
 /**
  * 注册外部传感器成功.
  */
#define VM_EXT_SENSOR_SUCCESS				(0)
/**
 * 超出了注册外部传感器的限制.
 */
#define VM_EXT_SENSOR_NOLIMIT				(-1)
/**
 * 错误的参数.
 */
#define VM_EXT_SENSOR_BADPARAM			(-2)
/**@} */

/**
 * 注册外部传感器的核心管理结构.
 * 
 * @param[out]				ext_handle 如果本函数返回VM_EXT_SENSOR_SUCCESS, 那么将会
 *							想ext_handle参数所指的地址写入句柄.
 * @param[in] 				scb 外部传感器的核心管理结构.
 * @return					是否注册成功否则为错误码.
 * @retval					VM_EXT_SENSOR_SUCCESS 注册成功.
 * @retval					VM_EXT_SENSOR_NOLIMIT 超过MRE最多管理外部浏览器的限制.
 * @retval					VM_EXT_SENSOR_BADPARAM 错误的参数.如果本函数的实参为
 *							NULL,那么该错误码将会被返回.
 */
VMINT vm_register_ext_sensor(VMINT* ext_handle, vm_core_scb_t* scb);

/**
 * 外部传感器得到数据通知MRE.
 * 
 * @param[in]					ext_handle 传感器的句柄,该句柄由vm_register_ext_sensor
 *							函数得到.
 * @param[in]					data 外部传感器得到的数据.
 * @param[in]					data_size 数据的字节数.				
 */
void vm_notify_data_by_ext_sensor(VMINT ext_handle, void* data, VMUINT data_size);


#endif
