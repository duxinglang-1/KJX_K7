/**********************************************************************************
*Filename:     kjx_sensor.c
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2013/01/21
*
***********************************************************************************/
#if defined(__KJX_FUN__)
#include "kjx_include.h"
#include "kjx_prin.h"
#include "TimerEvents.h"

kjx_sensor_func g_kjx_sensor_func;

#if defined(__MOTION_SENSOR_MC3451_SUPPORT__) 
kal_uint16 g_acc_x=0,g_acc_y=0,g_acc_z=0,g_acc_timer=0,g_acc_value=30;
kal_int32 g_mmi_pedometer_count = 0;

extern U32 g_kjx_sensor_shake;
extern U32 g_kjx_sensro_step;
void is_motion_sensor_shake(void);
void mmi_mc3451_get_pedometer_data(void);
extern kal_uint32 CTIRQ1_2_Mask_Status(void);
extern void acc_sensor_init(void);
extern void mc3451_sensor_get_data(kal_uint16 *x_adc, kal_uint16 *y_adc, kal_uint16 *z_adc);
extern void MS_I2C_write_bytes(kal_uint8 ucBufferIndex, kal_uint8 *pucData, kal_uint8 unDataLength);
#endif

#if defined(__MOTION_SENSOR_MMA8452Q_SUPPORT__)
extern int yas_mma8452q_measure(void);
extern void acc_mag_sensor_cycle(void);
extern void g_sensor_game_cb(BOOL result);
#endif

void kjx_sensor_func_init_default(void)
{
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif

#if defined(__MOTION_SENSOR_MMA8452Q_SUPPORT__)
	g_kjx_sensor_func.acc_mag_sensor_cycle = acc_mag_sensor_cycle;
	g_kjx_sensor_func.yas_mma8452q_measure = yas_mma8452q_measure;
	g_kjx_sensor_func.g_sensor_game_cb = g_sensor_game_cb;
#endif	
}

void kjx_sensor_func_init(void)
{
#if defined(SENSOR_INIT_DEFAULT)
	g_kjx_sensor_func.sensor_func_init = kjx_sensor_func_init_default;
#endif
	g_kjx_sensor_func.sensor_func_init();
}

#if defined(__MOTION_SENSOR_MC3451_SUPPORT__) 
void is_motion_sensor_shake(void)
{	
	kal_uint16 acc_x,acc_y,acc_z;

	mc3451_sensor_get_data(&acc_x,&acc_y,&acc_z);
	if((((acc_x-g_acc_x)<g_acc_value)&&((acc_x-g_acc_x)>-g_acc_value))&&(((acc_y-g_acc_y)<g_acc_value)&&((acc_y-g_acc_y)>-g_acc_value))&&(((acc_z-g_acc_z)<g_acc_value)&&((acc_z-g_acc_z)>-g_acc_value)))
	{
		g_acc_timer=0;		
	}
	else
	{
		g_acc_timer++;
		if(g_acc_timer>=3)     //   5
		{
			g_acc_timer=0;
			g_kjx_sensor_shake++;

		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("g_kjx_sensor_shake:%d", g_kjx_sensor_shake);
		#endif
		}
	}

	g_acc_x=acc_x;
	g_acc_y=acc_y;
	g_acc_z=acc_z;
}

void mmi_mc3451_get_pedometer_data(void)
{	
	kal_uint32 CTIRQ_status;
	
	CTIRQ_status = CTIRQ1_2_Mask_Status();

	if(CTIRQ_status) //all interrupt masked except CTIRQ_1/2
	{        
		StartTimer(KJX_TIMER_ID_SENSOR_CHECK_STEP, 100, mmi_mc3451_get_pedometer_data);   //wait 1 more tick to execute callback
		return;
	}

	acc_sensor_pwr_up();
	delay_ms(100);
	
	mc3451_read_pedometer(&g_mmi_pedometer_count);
	acc_sensor_pwr_down();

	if((g_mmi_pedometer_count >= 0) && (g_mmi_pedometer_count < 0x1000000))
		g_kjx_sensro_step = g_mmi_pedometer_count;

#if defined(__KJX_LOG_OUTPUT__)
	//LOGD("g_mmi_pedometer_count:%d, g_kjx_sensro_step:%d", g_mmi_pedometer_count, g_kjx_sensro_step);
#endif
}

void mmi_mc3451_pedometer_start_timer(void)
{
    StartTimer(KJX_TIMER_ID_SENSOR_CHECK_STEP, 2000, mmi_mc3451_get_pedometer_data); 
	kal_prompt_trace(MOD_WAP,"[mcube]mmi_mc3451_pedometer_start_timer");
}

void mmi_mc3451_pedometer_enable(void)
{	
	kal_prompt_trace(MOD_WAP,"[mcube]mmi_mc3451_pedometer_enable");

	acc_sensor_init();
	delay_ms(10);

	mmi_mc3451_pedometer_start_timer();
}
#endif/*__MOTION_SENSOR_MC3451_SUPPORT__*/

#endif
