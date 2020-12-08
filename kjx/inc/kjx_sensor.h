/**********************************************************************************
*Filename:     kjx_sensor.h
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2014/01/21
*
***********************************************************************************/
#if !defined(KJX_SENSOR_H)
#define KJX_SENSOR_H

#if defined(__KJX_FUN__)
//#define SENSOR_INIT_DEFAULT   /*默认初始化函数*/

typedef void (*sensor_void) (void);
#if defined(__MOTION_SENSOR_MMA8452Q_SUPPORT__)
typedef int (*mma8452q_measure) (void);
#endif
typedef void (*sensor_cb)(unsigned char);
/**************************************************************************/
typedef struct
{
    sensor_void acc_mag_sensor_cycle;//void acc_mag_sensor_cycle(void);
    sensor_void sensor_func_init;//void kjx_sensor_func_init_default(void);
#if defined(__MOTION_SENSOR_MMA8452Q_SUPPORT__)
    mma8452q_measure yas_mma8452q_measure;//int yas_mma8452q_measure(void);
    mma8452q_measure acc_data_initialize;//int yas_mma8452q_measure(void);
#endif
    sensor_cb g_sensor_game_cb;//void g_sensor_game_cb(BOOL result);
} kjx_sensor_func;
 
#endif/*__KJX_FUN__*/
#endif/*KJX_SENSOR_H*/
