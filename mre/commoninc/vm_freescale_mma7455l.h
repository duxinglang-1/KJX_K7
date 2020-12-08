#ifndef __VM_GSENSOR
#define __VM_GSENSOR
#include "vmswitch.h"
#include "vmsys.h"
#ifdef __MRE_SAL_CAMERA__
#ifdef __cplusplus
extern "C" {
#endif

/**
 * 加速度传感觉器的名称。
 */
#define USE_SENSOR_NAME			"sensor:quality=acceleration;device=mobile;model=MMA7455L_MOBILE;location=inside"

/**
 * 加速度传感器的采样率的敏感度。
 */
#define MOTION_SENSITIVE 			"MOTION_SENSITIVE"

/**
 * 加速度传感器在一个重力加速度的时候的值。
 */
#define ONE_G_VALUE		(64)

/**
 * 加速度传感器当前所能感应的最大的重力加速度。
 */
#define SELECTED_G_LEVEL	(SENSOR_2G_LEVEL)

/**
 * MOTION_SENSITIVE相关的值。
 */
typedef enum 
{
	MOTION_SENSITIVE_LOW, 
	MOTION_SENSITIVE_NORMAL, 
	MOTION_SENSITIVE_HIGH
} VM_MOTION_SENSITIVE_ENUM;

/**
 * 加速度传感器所能感应的范围的类型。
 */
typedef enum
{
	SENSOR_1G_LEVEL,
	SENSOR_2G_LEVEL,
	SENSOR_4G_LEVEL,
	SENSOR_8G_LEVEL
} VM_SELECTED_G_LEVEL;

/**
 * 加速度传感觉器所传的数据类型。
 */
typedef struct g_sensor_data_t 
{
	VMINT x;		/**<在X轴上的加速度分量。  */
	VMINT y;		/**<在Y轴上的加速度分量。  */
	VMINT z;		/**<在Z轴上的加速度分量。  */
}g_sensor_data_t;

#ifdef __cplusplus
}
#endif

#endif

#endif

