/**********************************************************************************
*Filename:     kjx_main_tour.c
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2014/01/13
*
***********************************************************************************/
#if defined(__KJX_FUN__)
#if defined(CUSTOMER_NAME_TOUR)

/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "kjx_include.h"
#include "kjx_main_tour.h"
#include "kjx_prin.h"
#include "yas.h"
#include "mmi_rp_app_worldclock_def.h"
#include "mmi_frm_nvram_gprot.h"
#include "gpiosrvgprot.h"
#include "CallLogSrvProt.h"
#ifdef __BLE_MODULE_SUPPORT__
#include "..\\custom\\drv\\Ble_mod\\ble_mod.h"
#endif
#ifdef __KJX_TOURIST_MAP_SUPPORT__
#include "mmi_rp_app_mainmenu_def.h"
#include "mmi_rp_app_profiles_def.h"
#endif
#include "common_nvram_editor_data_item.h"
#include "gui_data_types.h"

/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
#ifndef ABS
#define ABS(x) ((x) > 0 ? (x) : -(x))
#endif

#ifdef __KJX_TOURIST_MAP_SUPPORT__
#define TOURIST_MAP_MAX	20
#define TOURIST_MAP_FORMAT	".png"
#endif

#if defined(__KJX_FUN_SENSOR__)
#if defined(__MOTION_SENSOR_MMA8452Q_SUPPORT__)
#define YAS_MMA8452Q_ACC_REG                                                0x01
#endif/*__MOTION_SENSOR_MMA8452Q_SUPPORT__*/

//#define SENSOR_MAX_DATA            30
//#define SENSOR_STATIC_TIME        60*3   /*3MIN*/
#define SENSOR_STATIC_TIME        60*15   /*3MIN*///huzheng

#if defined(__KJX_FUN_STEPS__)
#define KJX_STEPS_TRACE
#endif/*__KJX_FUN_STEPS__*/
#endif/*__KJX_FUN_SENSOR__*/

//bwl 20200726
#if defined(__KJX_DJ_SUPPORT__)
#define DJ_CHECK_PIN 52
#define DJ_UART_SWITCH_PIN 56
#define DJ_POWER_PIN 59
#define DJ_EARPHOEN_CTRL_PIN 11
#endif/**/

#define RECOUNT_MXA_L1		5
#define RECOUNT_MXA_L2		10
#define RECOUNT_MXA_L3		15
#define RECOUNT_MXA_L4		20
#define RECOUNT_MXA_L5		25

#define KJX_GPRS_RECONECT_INTERVAL_L0	(30*1000)
#define KJX_GPRS_RECONECT_INTERVAL_L1	(1*60*1000)	//(3*60*1000)
#define KJX_GPRS_RECONECT_INTERVAL_L2	(2*60*1000)	//(5*60*1000)
#define KJX_GPRS_RECONECT_INTERVAL_L3	(3*60*1000)	//(10*60*1000)
#define KJX_GPRS_RECONECT_INTERVAL_L4	(4*60*1000)	//(15*60*1000)
#define KJX_GPRS_RECONECT_INTERVAL_L5	(5*60*1000)	//(30*60*1000)

/*****************************************************************************
*   Enum					枚举类型定义
*****************************************************************************/

/*****************************************************************************
 *  Struct					数据结构定义
 *****************************************************************************/

/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/
//static BOOL g_sensor_sign = FALSE;
static BOOL kjx_frist_power_on = TRUE;
#ifdef __KJX_TOURIST_MAP_SUPPORT__
static U8 kjx_image_id = 0;
static mmi_id g_kjx_image_group_id = GRP_ID_INVALID;
#endif

#if defined(__KJX_FUN_GPS_HD__)
U8 HD_GPS_agps_data[325] = {0x0b,0x01,0x3f,0x32,0x0d,0xa1,0x9f,0x66,0xdd,0x02,0xbd,0x5b,0x69,0xf9,0x20,0x2e,0xa6,0x59,0x58,0x54,
							  0x50,0x27,0xd7,0x02,0xae,0x74,0x91,0x93,0xee,0xa9,0xff,0xff,0x66,0x9a,0x73,0x13,0xa0,0xf8,0x0e,0x16,
							  0xba,0x16,0x5f,0xf7,0x21,0x00,0x16,0x00,0xa6,0x59,0xea,0xcd,0x00,0x00,0x0b,0x00,0x00,0x0b,0x6e,0x03,
							  0x56,0x00,0x56,0x02,0x00,0x0b,0x02,0xd9,0xb9,0x0c,0xa1,0xcb,0xb4,0x15,0x08,0x8e,0x00,0x92,0x08,0xc4,
							  0x33,0xa6,0x59,0xdb,0x31,0x73,0x26,0x1d,0x02,0x24,0xc5,0xb0,0x91,0x93,0xa5,0xff,0xff,0xab,0xc9,0x1d,
							  0xaa,0x4a,0xf7,0x1e,0x18,0x38,0x13,0x5e,0xf6,0x98,0xff,0x79,0x00,0xa6,0x59,0xc0,0x1e,0x13,0x00,0xe9,
							  0xff,0x00,0xd6,0x6e,0x03,0x36,0x00,0x36,0x02,0x00,0x0b,0x03,0xf8,0x62,0x0d,0xa1,0x93,0xc2,0x1c,0x00,
							  0x62,0x1f,0xc6,0x21,0x64,0x36,0xa6,0x59,0xd9,0x3d,0x11,0x27,0x9a,0x05,0x90,0x3d,0x00,0xbe,0xe5,0xa6,
							  0xff,0xff,0x30,0x4a,0xaf,0xbc,0x1b,0x03,0x54,0x0f,0xea,0x1d,0x82,0x03,0xed,0xff,0x10,0x00,0xa6,0x59,
							  0x3e,0xb7,0xfd,0xff,0xe3,0xff,0x00,0x03,0x6e,0x03,0x50,0x00,0x50,0x02,0x00,0x0b,0x04,0x83,0x3b,0x0d,
							  0xa1,0xae,0xb7,0x5b,0x04,0x5f,0x81,0x3e,0x7b,0xe3,0x38,0xa6,0x59,0xa8,0x73,0x0d,0x28,0x08,0x03,0x6e,
							  0xbe,0xef,0x3e,0x79,0xa9,0xff,0xff,0x60,0x62,0x9b,0x24,0x15,0x0a,0x08,0x08,0x90,0x27,0xa8,0x0b,0x09,
							  0x00,0xd6,0xff,0xa6,0x59,0x74,0x8a,0xf7,0xff,0xfd,0xff,0x00,0xd7,0x6e,0x03,0x4c,0x00,0x4c,0x02,0x3f,
							  0x0b,0x05,0xf2,0x7f,0x0e,0xa1,0x69,0xef,0x5f,0x02,0xb4,0xb2,0x7a,0x98,0xdc,0x38,0x68,0x5b,0x30,0x65,
							  0x8a,0x26,0x6f,0x06,0x22,0xb5,0x7f,0xbd,0x43,0xa6,0xff,0xff,0x68,0x0c,0x90,0x12,0x34,0x03,0x8c,0x0f,
							  0xfe,0x1c,0x3a,0x04,0xf6,0xff,0xda,0xff,0x68,0x5b,0x3f,0x5f,0xfc,0xff,0x19,0x00,0x00,0xe9,0x6e,0x03,
							  0x13,0x00,0x03,0x02,0x00};
#endif

/****************************************************************************
* Global Variable - Extern          全局变量
*****************************************************************************/
#if defined(__KJX_FUN_SENSOR__)
#if defined(__KJX_FUN_STEPS__)
S32 old_ax = 0;
S32 old_ay = 0;
S32 old_az = 0;
long double min_av = -1;
S32 g_steps_timer = 0;
#endif
#endif

#if defined(__KJX_FUN_GPS__)
int g_gps_status = 0;	//0:off 1:on 2:ok
#endif
int g_kjx_enter_factory_test = 0;
int g_enter_key_test = 0;
int g_start_screen = 0;
int g_start_gps = 0;
int g_start_earphone = 0;
int g_start_rfid = 0;
int g_start_charge = 0;
int g_test_start = 0;
int g_test_call112 = 0;
int g_test_led = 0;

#if defined(__KJX_POSITION_TRIGGER_PLAY__)||defined(__KJX_SERVER_CMD_PLAY__)
U8 g_play_cause = 0;	//0:RFID触发播放 1:位置触发播放 2:后台指令直接播放
#endif
#if defined(__KJX_SERVER_CMD_PLAY__)
U8 g_server_play_result = 0;	//0:初始值 1:设置成功 2:编号格式错误 3:编号音频未找到
#endif
U8 g_gps_init = 0;
U8 g_rfid_init = 0;
U8 g_rfid_field = 0;
U8 g_alarm_status = 0;
BOOL g_gps_send_interval = FALSE;
BOOL g_rfid_test_timer= FALSE;
//BOOL service_to_tracer = FALSE;//是否服务器主动下发
BOOL powerDataIsSync = TRUE;	//xb add 2017-03-14 不再需要同步数据
U8 parse_flag = 0;
U16 sms_gps_info[512];
kjx_tour_struct g_kjx_tour_struct =
{
	{"123456\0"},/*密码*/
	{"\0","\0","\0"}, /*SOS号码*/
	{"\0"}, /*监听号码*/
	{"\0"}, /* +8613800138000 */
	{"0086\0"}, /*语言*/
	{"\0"}, /*SOS报警短信内容*/
	{"\0"}, 	/*deviceNumber 设备号*/
	{"\0"}, /*写入的IMEI号*/
	10, /*interval 默认10秒*/
	0,		/* sleepStatus 休眠状态*/
	0,		/* listenStatus 监听状态 */
	0,		/* moveStatus 电子围栏状态*/
	0,		/* moveValue 电子围栏距离*/
	0,		/*电子围栏纬度*/
	0,		/*电子围栏经度*/
	'\0',		/*N/S*/
	'\0',		/*E/W*/
};

#ifdef __BLE_MODULE_SUPPORT__
int g_start_ble = 0;
S8 g_kjx_ble_rssi = 0;
U32 g_kjx_ble_id = 0;
BOOL g_kjx_ble_is_on = FALSE;
char ble_data[128] = {0};
#endif

#ifdef __BOSCH_BMP280_PRESSURE__
int g_start_pressure = 0;
#endif

#if defined(__KJX_POSITION_TRIGGER_IN_LOCAL__)
S8* posfileString = NULL;
kjxPositionPlayInfo g_kjxPositionPlayInfo = {0};
#endif

U32 g_ReconnetCount = 0;

#if defined(__KJX_DJ_SUPPORT__)
U8 tmp_mode = 4;	//4:2A;5:2B;6:2C
U8 tmp_chanle = 1;
U8 tmp_vol = 6;
U32 g_kjx_current_dj_or_rfid_mode = 0;
static mmi_id g_kjx_dj_group_id = GRP_ID_INVALID;
#endif

/****************************************************************************
* Global Variable - Extern          引用全局变量
*****************************************************************************/
extern U8 kjxImei[];
extern BOOL socketConnet;
extern int g_is_sms_send;
extern double old_latitude;
extern double old_longitude;
extern U16 sensor_status;
extern U16 TTsPlayRepeat;
extern U32 heartbeat_need_send;
extern U32 rfid_need_send;
extern U32 myID;

#ifdef __KJX_RFID__
extern U8 rfid_field_index;
extern U8 kjx_audio_status;//0: 停止,1: 播放,2:主动暂停,3:播放的时候被强行中断,255:未搜到RFID，从未播放过
extern U8 rfid_field_count[30];
extern U32 kjx_rfid_id;
extern S32 g_rfid_played_id;
extern U32 g_kjx_rfid_id;
extern S32 last_id;
extern BOOL kjx_audio_is_playing;
#endif

extern kal_bool g_gprs_is_retry;
extern S8 kjxTourInfor[512];
extern S8 TtsPlayString[1024];

#ifdef __KJX_FUN_GPS__
extern kal_bool g_force_open_gps;
extern kjx_gps_data g_kjx_gps_data;
extern kjx_gps_func g_kjx_gps_func;
extern U8 g_kjx_agps_valid_time[50];
#endif

#ifdef __KJX_WEATHER_SUPPORT__
extern kjx_weather_struct kjx_weather;
#endif

#ifdef __KJX_FENCE_SUPPORT__
extern kjx_fence_struct kjx_fence;
#endif

extern kjx_socket_context g_kjx_socket_context;
extern kjx_socket_notify_func g_socket_notify_func;
extern kjx_socket_event_func g_kjx_socket_event_func;
extern kjx_main_func g_kjx_main_func;
extern nvram_ef_kjx_nvram_struct g_kjx_nvram_struct;

#if defined(__KJX_FUN_SENSOR__)
extern int SENSOR_MAX_DATA;
extern int x_data;
extern int y_data;
extern int z_data;
extern int out_data[3];
extern kjx_sensor_func g_kjx_sensor_func;

#if defined(__KJX_FUN_STEPS__)
extern int steps_x_data;
extern int steps_y_data;
extern int steps_z_data;
extern S32 steps_count;
#endif

#endif

#if defined(__KJX_DJ_SUPPORT__)
extern WCHAR dj_chanle_show[128];
#endif

extern UI_string_type kjx_scrolling_show[512];
/*****************************************************************************
 *  Global Functions	- Extern		引用外部函数
 *****************************************************************************/
#if defined(__KJX_FUN_SENSOR__)
#if defined(__KJX_FUN_STEPS__)
extern BOOL kjx_is_use_steps(void);
extern BOOL kjx_is_use_heart(void);
#endif
#endif
#if defined(__KJX_POSITION_TRIGGER_PLAY__)
extern void kjx_handle_send_position_trigger_data();
#endif
extern void kjx_handle_send_rfid_data(void);
extern void kjx_system_init(void);
extern void mmi_show_scrolling_infor(void);
extern void mmi_redraw_idlescreen(void);
extern void power_off(void); 
extern void kjx_set_with_play_tts(void);
extern void kjx_handle_send_system_language(void);
#if defined(__MOTION_SENSOR_MC3451_SUPPORT__)
extern void acc_sensor_init(void);
#endif

/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/
int kjx_get_foctory_test_mode(void);
void kjx_factory_test_start(void);
void kjx_foctory_test_end(void);
void kjx_factory_enter_key_test(void);
void kjx_factory_key_test(U8 keycode, U8 keytype);
void kjx_factory_gps_end(void);
void kjx_factory_gps_test(void);
void kjx_factory_gprs_test(void);
void kjx_factory_charge_led_test(void);
void kjx_factory_gps_led_test(void);
void kjx_factory_gsm_led_test(void);
void kjx_factory_led_test(void);
void kjx_factory_vib_test(void);
void kjx_factory_mic_test_end(void);
extern void mmi_fm_set_loopback(kal_uint32 on, void* arg);
void kjx_factory_mic_test(void);
void kjx_factory_mic_test_start(void);
void kjx_factory_earphone_test_end(void);
void kjx_factory_earphone_plugout(void);
void kjx_factory_earphone_plugin(void);
void kjx_factory_earphone_test_start(void);
void kjx_factory_charge_test_end(void);
void kjx_factory_charge_test(void);
void kjx_factory_rfid_test(void);
void kjx_factory_call_test_start(void);
#if defined(__KJX_FUN_SENSOR__)
void kjx_factory_g_sensor_test(void);
void kjx_sensor_main(void);
#endif
#ifdef __BLE_MODULE_SUPPORT__
void kjx_factory_ble_test(void);
void kjx_start_ble_test(void);
void kjx_factory_ble_test_end(void);
#endif
#ifdef __KJX_TOURIST_MAP_SUPPORT__
void kjx_show_tour_image(void);
void kjx_exit_tour_image(void);
#endif
void kjx_dj_get_current_mode(void);
void kjx_dj_get_current_chanle(void);
void kjx_dj_get_vol(void);
void kjx_dj_show_tour_image(void);

#if defined(__KJX_DJ_SUPPORT__)
void kjx_dj_main_show_tour_image(void);
void kjx_dj_exit_tour_image(void);
extern U16 kjx_dj_uart_write(U8 *buffer,U16 len);
extern void kjx_dj_get_vol(void);
extern void kjx_dj_check_start(void);
#endif

/*****************************************************************************
 *  Local Functions			函数定义
 *****************************************************************************/
#if defined(__KJX_FUN_SENSOR__)
#if defined(__KJX_FUN_STEPS__)
void kjx_steps_gsensor_data(kal_int32 x,kal_int32 y,kal_int32 z)
{
	S32 ax=0;
	S32 ay=0;
	S32 az=0;
	long double av = 0;
	static S32 tem_count=0;

#ifdef MAIN_TOUR_SENSOR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("x=%d,y=%d,z=%d",  x, y, z);
#endif
#endif

	if(x&0x0800)
	{
		ax = (0xffff-x)*(-1);
	}
	else
	{
		ax = x;
	}
	
	if(y&0x0800)
	{
		ay = (0xffff-y)*(-1);
	}
	else
	{
		ay = y;
	}
	
	if(z&0x0800)
	{
		az = (0xffff-z)*(-1);
	}
	else
	{
		az = z;
	}
 
	if((ay>-300)&&(ay<-350)&&(az>500))
	{/*数据过滤*/
		return;
	}

	//第一次获取数据
	if(old_ax == 0&&old_ay == 0&&old_az == 0)
	{
		old_ax = ax;
		old_ay = ay;
		old_az = az;
	}

	//加速度
	av = (sqrt(pow((ax-old_ax),2)+pow((ay-old_ay),2)+pow((az-old_az),2)))*0.01;
#ifdef MAIN_TOUR_SENSOR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("av=%f", av);
#endif
#endif
	
	if(min_av == -1)
	{
		min_av = av;
	}

	if(min_av>av)
	{
		min_av = av;
	}
#ifdef MAIN_TOUR_SENSOR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_steps_timer=%d,min_av=%f,av=%f", g_steps_timer, min_av, av);
#endif
#endif
 	tem_count = steps_count;
#ifndef __KJX_FACTORY_TEST__
	if((g_steps_timer>4)&&(min_av<1.5)&&((av>4)/*&&(av<6.5)*/))
#endif	
	{
		steps_count++;
		min_av = -1;
		g_steps_timer = 0;
	}
	
#ifdef MAIN_TOUR_SENSOR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("av=%f,steps_count=%d", av, steps_count);
#endif
#endif
	if(g_steps_timer>100)
	{
		g_steps_timer = 100;
	}
	else
	{
		g_steps_timer++;
	}
	
	old_ax = ax;
	old_ay = ay;
	old_az = az;

#ifdef MAIN_TOUR_SENSOR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("end");
#endif
#endif	
}

#endif

#if defined(__MOTION_SENSOR_MMA8452Q_SUPPORT__)
void kjx_tour_sensor_cycle(void)
{
	StopTimer(KJX_TIMER_ID_SENSOR);
	memset(out_data, 0x00, sizeof(out_data));
	//yas_simple_measure() ;/*yas_mma8452q_measure*/
	g_kjx_sensor_func.yas_mma8452q_measure();

#ifdef MAIN_TOUR_SENSOR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("out_data: x:%d, y:%d, z:%d", out_data[0], out_data[1], out_data[2]);
#endif
#endif

#if defined(__KJX_FUN_STEPS__)
	if(kjx_is_use_steps())
	{
		kjx_steps_gsensor_data(steps_x_data,steps_y_data,steps_z_data);
		StartTimer(KJX_TIMER_ID_SENSOR, 50, g_kjx_sensor_func.acc_mag_sensor_cycle);
		return;
	}
#endif

	if((out_data[0]==1)||(out_data[1]==1)||(out_data[2]==1))
	{
		g_kjx_sensor_func.g_sensor_game_cb(TRUE);
	}
	else
	{
		g_kjx_sensor_func.g_sensor_game_cb(FALSE);
	}

	StartTimer(KJX_TIMER_ID_SENSOR, 1000, g_kjx_sensor_func.acc_mag_sensor_cycle);
}

int kjx_tour_mma8452q_measure(void)
{
	unsigned char buf[6];
	int i,j;

	/* Check initialize */
	if (g_kjx_sensor_func.acc_data_initialize() == 0) 
	{
		return YAS_ERROR_NOT_INITIALIZED;
	}

#ifdef MAIN_TOUR_SENSOR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	/* Read acceleration data */
	if (yas_mma8452q_read_reg(YAS_MMA8452Q_ACC_REG, buf, 6) == 0)
	{
		out_data[0] = ((((char)buf[0])<<4)&0x0FF0) | ((((char)buf[1])>>4)&0x000F);
		if(out_data[0]&0x0800)
			out_data[0] |= 0xF000;
		
		out_data[1] = ((((char)buf[2])<<4)&0x0FF0) | ((((char)buf[3])>>4)&0x000F);
		if(out_data[1]&0x0800)
			out_data[1] |= 0xF000;
		
		out_data[2] = ((((char)buf[4])<<4)&0x0FF0) | ((((char)buf[5])>>4)&0x000F);
		if(out_data[2]&0x0800)
			out_data[2] |= 0xF000;
	}
	else
	{
		out_data[0]=0;
		out_data[1]=0;
		out_data[2]=0;
	}

	if(((out_data[0]>0xFFFF)||(out_data[1]>0xFFFF)||(out_data[2]>0xFFFF))
		||((out_data[0]==0)&&(out_data[1]==0)&&(out_data[2]==0)))
	{
		out_data[0]=0;
		out_data[1]=0;
		out_data[2]=0;

	#ifdef MAIN_TOUR_SENSOR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return YAS_NO_ERROR");
	#endif
	#endif
		return YAS_NO_ERROR;
	}

#if defined(__KJX_FUN_STEPS__)
	if(kjx_is_use_steps())
	{
		steps_x_data=out_data[0];
		steps_y_data=out_data[1];
		steps_z_data=out_data[2];
	}
#endif

	//ACC_X
	if(out_data[0]!=0xFFFF)
	{
	#ifdef MAIN_TOUR_SENSOR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("ABS(out_data[0] - x_data)=%d", ABS(out_data[0] - x_data));
	#endif
	#endif
		if(ABS(out_data[0] - x_data) > SENSOR_MAX_DATA)
		{
			x_data=out_data[0];
			out_data[0]=1;
		}
		else
			out_data[0]=0;//x_data;
	} 
	else
	{
		if(ABS(out_data[0] - x_data) > 0xFFFF/2)
		{
		#ifdef MAIN_TOUR_SENSOR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("ABS(out_data[0] + x_data-0xFFFF)=%d", ABS(out_data[0] + x_data-0xFFFF));
		#endif
		#endif
			if(ABS(out_data[0] + x_data-0xFFFF) > SENSOR_MAX_DATA)
			{
				x_data=out_data[0];
				out_data[0]=1;
			}
			else
				out_data[0]=0;//x_data;
		}
		else
		{
		#ifdef MAIN_TOUR_SENSOR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("ABS(out_data[0] - x_data)=%d", ABS(out_data[0] - x_data));
		#endif
		#endif
			if(ABS(out_data[0] - x_data) > SENSOR_MAX_DATA)
			{
				x_data=out_data[0];
				out_data[0]=1;
			}
			else
				out_data[0]=0;//x_data;
		}
	}

	//ACC_Y
	if(out_data[1]!=0xFFFF)
	{
	#ifdef MAIN_TOUR_SENSOR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("ABS(out_data[1] - y_data)=%d", ABS(out_data[1] - y_data));
	#endif
	#endif
		if(ABS(out_data[1] - y_data) > SENSOR_MAX_DATA)
		{
			y_data=out_data[1];
			out_data[1]=1;
		}
		else
			out_data[1]=0;//x_data;
	} 
	else
	{
		if(ABS(out_data[1] - y_data) > 0xFFFF/2)
		{
		#ifdef MAIN_TOUR_SENSOR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("ABS(out_data[1] + y_data-0xFFFF)=%d", ABS(out_data[1] + y_data-0xFFFF));
		#endif
		#endif
			if(ABS(out_data[1] + y_data-0xFFFF) > SENSOR_MAX_DATA)
			{
				y_data=out_data[1];
				out_data[1]=1;
			}
			else
				out_data[1]=0;//x_data;
		}
		else
		{
		#ifdef MAIN_TOUR_SENSOR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("ABS(out_data[1] - y_data)=%d", __func__, ABS(out_data[1] - y_data));
		#endif
		#endif
			if(ABS(out_data[1] - y_data) > SENSOR_MAX_DATA)
			{
				y_data=out_data[1];
				out_data[1]=1;
			}
			else
				out_data[1]=0;//x_data;
		}
	}

	//ACC_Z
	if(out_data[2]!=0xFFFF)
	{
	#ifdef MAIN_TOUR_SENSOR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("ABS(out_data[2] - z_data)=%d", __func__, ABS(out_data[2] - z_data));
	#endif
	#endif
		if(ABS(out_data[2] - z_data) > SENSOR_MAX_DATA)
		{
			z_data=out_data[2];
			out_data[2]=1;
		}
		else
			out_data[2]=0;//x_data;
	} 
	else
	{
		if(ABS(out_data[2] - z_data) > 0xFFFF/2)
		{
		#ifdef MAIN_TOUR_SENSOR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("ABS(out_data[2] + z_data-0xFFFF)=%d", ABS(out_data[2] + z_data-0xFFFF));
		#endif
		#endif
			if(ABS(out_data[2] + z_data-0xFFFF) > SENSOR_MAX_DATA)
			{
				z_data=out_data[2];
				out_data[2]=1;
			}
			else
				out_data[2]=0;//x_data;
		}
		else
		{
		#ifdef MAIN_TOUR_SENSOR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("ABS(out_data[2] - z_data)=%d", ABS(out_data[2] - z_data));
		#endif
		#endif
			if(ABS(out_data[2] - z_data) > SENSOR_MAX_DATA)
			{
				z_data=out_data[2];
				out_data[2]=1;
			}
			else
				out_data[2]=0;//x_data;
		}
	}

#ifdef MAIN_TOUR_SENSOR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("out_data:%d:%d, %d:%d, %d:%d", out_data[0], x_data, out_data[1], y_data, out_data[2], z_data);
#endif
#endif

	return YAS_NO_ERROR;
}
#endif

void kjx_tour_sensor_cb(BOOL result)
{
	static int moveCount = 0;
	static int moveStatus = 0;
	static int socketCheck = 0;
    static int test_mode = 0;

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	//LOGD("result=%d", result);
#endif
#endif

    if (kjx_get_foctory_test_mode() == 1)
    {
        if(test_mode == 0)
        {
            test_mode = 1;
            kjx_factory_g_sensor_test_end(result);
        }
        return;
    }
    
	if(!result)
	{
		if((moveStatus)&&(moveCount > SENSOR_STATIC_TIME))
		{
			moveCount = SENSOR_STATIC_TIME;
		}
		
		moveCount ++;
	}
	else
	{
		moveCount = 0;
		moveStatus = 0;
		if(sensor_status)
		{
			sensor_status = 0;
			kjx_tour_move_timeout(FALSE);
		}
	}
	
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	//LOGD("moveCount=%d", moveCount);
#endif
#endif
	
	if((moveCount == SENSOR_STATIC_TIME))
	{
		moveStatus = 1;
		sensor_status = 1;   //huzheng
		kjx_tour_move_timeout(TRUE);
	}
}
   
void kjx_sensor_func_init_tour(void)
{
#ifdef MAIN_TOUR_SENSOR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

#if defined(__MOTION_SENSOR_MMA8452Q_SUPPORT__)
	kal_sleep_task(1000);
	g_kjx_sensor_func.acc_mag_sensor_cycle = kjx_tour_sensor_cycle;
	g_kjx_sensor_func.yas_mma8452q_measure = kjx_tour_mma8452q_measure;
	g_kjx_sensor_func.g_sensor_game_cb = kjx_tour_sensor_cb;
	g_kjx_sensor_func.acc_data_initialize = kjx_acc_data_initialize;
#endif
}

#endif/*__KJX_FUN_SENSOR__*/

void kjx_tour_work_led(void)
{
#if defined(__KJX_BAT_STATUS_LED_SHOW__)
	if(srv_charbat_is_charging())
	{
		kjx_tour_battery_status_led(BATTERY_CHARGING_STATUS);
	}
	else
	{
		if(srv_charbat_get_battery_level() > BATTERY_LEVEL_0)
			kjx_tour_battery_status_led(BATTERY_NORMAL_STATUS);
		else
			kjx_tour_battery_status_led(BATTERY_LOW_STATUS);
	}
	
	return;
#endif

	kjx_led_red_on_only();
	kjx_led_green_off_only();
	kjx_led_yellow_off_only();
	kjx_led_blue_off_only();
}
 
void kjx_tour_gsm_led(U16 led_type)
{
	static U16 gsm_led_type = LED_NONE;

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("led_type:%d, gsm_led_type:%d", led_type, gsm_led_type);
#endif
#endif

#if defined(__KJX_BAT_STATUS_LED_SHOW__)
	return;
#endif

	if(gsm_led_type == led_type)
	{
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return");
	#endif
		return;
	}

	gsm_led_type = led_type;
	
	switch(led_type)
	{
	case LED_FAST:
	    kjx_led_red_off_only();
		kjx_led_red_blink(LED_BLINK_ALWAYS,DELAY_MS_500,DELAY_MS_500);
		break;
		
	case LED_SLOW:
	    kjx_led_red_off_only();
		kjx_led_red_blink(LED_BLINK_ALWAYS,DELAY_MS_1000,DELAY_MS_5000);
		break;
		
	case LED_ON:
	    kjx_led_red_on_only();
		break;
		
	case LED_OFF:
	    kjx_led_red_off_only();
		break;

	default:
		break;
	}
}

void kjx_tour_gps_led(U16 led_type)
{
	static U16 gps_led_type = LED_NONE;

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("led_type:%d, gps_led_type:%d", led_type, gps_led_type);
#endif
#endif

#if defined(__KJX_BAT_STATUS_LED_SHOW__)
	return;
#endif

	if(gps_led_type == led_type)
	{
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return");
	#endif
		return;
	}

	gps_led_type = led_type;
	
	switch(led_type)
	{
	case LED_FAST:
	    kjx_led_blue_off_only();
		kjx_led_blue_blink(LED_BLINK_ALWAYS,DELAY_MS_500,DELAY_MS_500);
		break;
		
	case LED_SLOW:
	    kjx_led_blue_off_only();
		kjx_led_blue_blink(LED_BLINK_ALWAYS,DELAY_MS_1000,DELAY_MS_5000);
		break;
		
	case LED_ON:
	    kjx_led_blue_on_only();
		break;
		
	case LED_OFF:
	    kjx_led_blue_off_only();
		break;

	default:
		break;
	}
}

void kjx_tour_charge_led(U16 led_type)
{
	static U16 charge_led_type = LED_NONE;
	
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("led_type:%d, charge_led_type:%d", led_type, charge_led_type);
#endif
#endif

	if(charge_led_type == led_type)
	{
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return");
	#endif
	#endif

		return;
	}

	charge_led_type = led_type;
	
	if(kjx_get_foctory_test_mode() == 0)	//xb add 2016-08-31 防止测试模式下充电灯被关闭
	{
		if(kjx_is_in_call())
	    {
	        led_type = LED_ON;
	    }
    
		if(!kjx_is_in_call()&&!kjx_is_charging())
	    {
	        led_type = LED_OFF;
	    }
	}

	switch(led_type)
	{
	case LED_FAST:
	    kjx_led_green_on_only();//红灯
	    kjx_led_yellow_off_only();//绿灯
		//kjx_led_green_blink(LED_BLINK_ALWAYS,DELAY_MS_500,DELAY_MS_500);
		break;
		
	case LED_SLOW:
	    kjx_led_green_off_only();
	    kjx_led_yellow_off_only();
		kjx_led_green_blink(LED_BLINK_ALWAYS,DELAY_MS_1000,DELAY_MS_5000);
		break;
		
	case LED_ON:
	    kjx_led_green_on_only();//红灯
	    kjx_led_yellow_on_only();//绿灯
		break;

	case LED_OFF:
	    kjx_led_green_off_only();
	    kjx_led_yellow_off_only();
		break;

	default:
		break;
	}
}

void kjx_tour_check_led(void)
{
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("sensor_status:%d", sensor_status);
#endif
#endif

#if defined(__KJX_BAT_STATUS_LED_SHOW__)
	return;
#endif

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("incall:%d, charging:%d", kjx_is_in_call(),kjx_is_charging());
#endif
#endif

#if !defined(__KJX_BAT_STATUS_LED_SHOW__)
	if(kjx_is_in_call())
		kjx_tour_charge_led(LED_ON);
	else if(kjx_is_charging())
		kjx_tour_charge_led(LED_FAST);
    else
		kjx_tour_charge_led(LED_OFF);
#endif

	//GSM
	if((!kjx_is_in_call())&&(!sensor_status))
	{
		if(socketConnet)
			kjx_set_gsm_led(LED_SLOW);
		else
			kjx_set_gsm_led(LED_FAST);
	}
	else if(kjx_is_in_call())
	{
		kjx_set_gsm_led(LED_ON);
	}
	else if(!sensor_status)
	{
		kjx_set_gsm_led(LED_OFF);
	}

#if defined(__KJX_FUN_GPS__)
	//GPS
	if(kjx_gps_is_on())
	{
		if(g_kjx_gps_data.data_status == 'A')
		{
			kjx_tour_gps_led(LED_SLOW);
		}
		else
		{	
			kjx_tour_gps_led(LED_FAST);
		}
	}
	else
	{
		kjx_tour_gps_led(LED_OFF);
	}
#endif
}

#if defined(__KJX_BAT_STATUS_LED_SHOW__)
/*****************************************************************************
* FUNCTION
*  	kjx_tour_battery_status_led
* DESCRIPTION
*   电量状态LED显示:
*      低电状态: 红灯快闪
*      正常状态: 绿灯慢闪
*      充电状态: 红灯常亮
*      充满状态: 绿灯常亮
*
* PARAMETERS
*
* RETURNS
*	none
* 
* Author
*   xiebiao 2016-08-25
*****************************************************************************/
void kjx_tour_battery_status_led(kjx_bat_status bat_status)
{
	static kjx_bat_status bat_status_led = BATTERY_MAX;
	
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("bat_status_led:%d, bat_status:%d", bat_status_led, bat_status);
#endif
#endif

	if(bat_status_led == bat_status)
		return;

	if(kjx_get_foctory_test_mode() == 1)
	{
		if((g_test_led == 0) && ((bat_status != BATTERY_ALL_OFF) && (bat_status != BATTERY_TURN_ON_GREEN) && (bat_status != BATTERY_TURN_ON_RED)))
		{
			return;//工厂模式下LED测试完成之前除了打开关闭，其他的指令暂不执行
		}
	}
	
	bat_status_led = bat_status;
	switch(bat_status)
	{
	case BATTERY_LOW_STATUS://red led fast blink
		kjx_led_red_off_only();//红灯
		kjx_led_green_off_only();//绿灯
		kjx_led_red_blink(LED_BLINK_ALWAYS,DELAY_MS_500,DELAY_MS_1000);
		break;
		
	case BATTERY_NORMAL_STATUS://green led slow blink
		kjx_led_red_off_only();//红灯
		kjx_led_green_off_only();//绿灯
		kjx_led_green_blink(LED_BLINK_ALWAYS,DELAY_MS_500,DELAY_MS_5000);
		break;

	case BATTERY_CHARGING_STATUS://red led light always
	case BATTERY_TURN_ON_RED://all led turn red
		kjx_led_red_off_only();//红灯
		kjx_led_green_off_only();//绿灯
		kjx_led_red_on_only();	
		break;

	case BATTERY_FULL_STATUS://green led light always
	case BATTERY_TURN_ON_GREEN://led turn green
		kjx_led_red_off_only();//红灯
		kjx_led_green_off_only();//绿灯
		kjx_led_green_on_only();	
		break;

	case BATTERY_ALL_OFF://all led turn off
		kjx_led_red_off_only();//红灯
		kjx_led_green_off_only();//绿灯
		break;

	case BATTERY_MAX:
		kjx_led_red_off_only();//红灯
		kjx_led_green_off_only();//绿灯
		kjx_led_green_blink(LED_BLINK_ALWAYS,DELAY_MS_500,DELAY_MS_5000);		
		break;
	}
}

#endif


/*关闭T-CARD功能*/
//kal_bool MSDC_Check_Card_Mount(void){}

/***********************************************************************************/

//事件处理

/***********************************************************************************/
#if defined(__KJX_POSITION_TRIGGER_PLAY__)
void kjx_handle_send_position_for_play(void)
{
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	StopTimer(KJX_TIMER_ID_SEND_POSITION_TRIGGER);

	if(kjx_gps_is_valid())
	    kjx_socket_send_data_with_type(SERVER_TYPE_71);
	
	StartTimer(KJX_TIMER_ID_SEND_POSITION_TRIGGER, 10*1000, kjx_handle_send_position_for_play);
}
#endif

#ifdef __KJX_FUN_GPS__
BOOL kjx_gps_is_valid(void)
{
	if(g_kjx_gps_func.gps_is_on() && (g_kjx_gps_data.data_status == 'A'))
		return TRUE;
	else
		return FALSE;
}

void kjx_open_gps(void)
{
	extern U16 g_gps_is_on;

	if(IsMyTimerExist(KJX_TIMER_ID_GPS_OPEN));
		StopTimer(KJX_TIMER_ID_GPS_OPEN);
	if(IsMyTimerExist(KJX_TIMER_ID_GPS_CLOSE))	//xb add 2016-09-27 防止其他情况下开启GPS没多久没定时器强制关闭了
		StopTimer(KJX_TIMER_ID_GPS_CLOSE);

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

#ifdef __KJX_FUN_GPS__
	if(g_gps_is_on == 0)
	{/*打开GPS*/
		kjx_gps_turn_on();
	}
#endif

	g_gps_status = 1;

	/*更新GPS状态图标*/
	wgui_status_icon_bar_reset_icon_display(STATUS_ICON_GPS_OFF);
	wgui_status_icon_bar_set_icon_display(STATUS_ICON_GPS_ON);
	wgui_status_icon_bar_update();
}

void kjx_close_gps(void)
{
#if defined(__KJX_POSITION_TRIGGER_PLAY__)	//xb add 2017-01-04 位置版GPS常开
	return;
#endif

	if(g_force_open_gps)
	{
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("g_force_open_gps, can't close gps!");
	#endif
	#endif
		return;
	}
	
	if(kjx_get_foctory_test_mode() == 1)
	{
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("is test mode, can't close gps!");
	#endif
	#endif
	
		return;
	}

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("gps closed!");
#endif
#endif

	if(g_kjx_gps_func.gps_is_on())
	{
		g_kjx_gps_func.gps_turn_off();
		memset(&g_kjx_gps_data, 0, sizeof(kjx_gps_data));
	}

	g_gps_status = 0;
	
	if(IsMyTimerExist(KJX_TIMER_ID_GPS_CHECK))
		StopTimer(KJX_TIMER_ID_GPS_CHECK);

	if(IsMyTimerExist(KJX_TIMER_ID_GPS_RESET))
		StopTimer(KJX_TIMER_ID_GPS_RESET);

#if defined(__KJX_FUN_AGPS__)
#if defined(__KJX_FUN_GPS_HD__)
	if(IsMyTimerExist(KJX_TIMER_ID_AGPS_HD_CMD_WAIT_TIMEROUT))
		StopTimer(KJX_TIMER_ID_AGPS_HD_CMD_WAIT_TIMEROUT);
	if(IsMyTimerExist(KJX_TIMER_ID_AGPS_HD_CMD_DELAY))
		StopTimer(KJX_TIMER_ID_AGPS_HD_CMD_DELAY);
#endif
#endif

#if defined(__KJX_POSITION_TRIGGER_PLAY__)
	if(IsMyTimerExist(KJX_TIMER_ID_SEND_POSITION_TRIGGER))
		StopTimer(KJX_TIMER_ID_SEND_POSITION_TRIGGER);
#endif

	/*更新GPS状态图标*/
	wgui_status_icon_bar_reset_icon_display(STATUS_ICON_GPS_ON);
	wgui_status_icon_bar_reset_icon_display(STATUS_ICON_GPS_OK);
	wgui_status_icon_bar_set_icon_display(STATUS_ICON_GPS_OFF);
	wgui_status_icon_bar_update();
}

void kjx_tour_do_something_with_custom(kjx_gps_data g_kjx_gps_data)
{/*使用GPS数据进行一些事件操作*/
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	//LOGD("latitude:%f, longitude:%f, data_status:%c, nyear:%d, nMonth:%d, nDay:%d, nHour:%d, nMin:%d, nSec:%d", 			
	//		g_kjx_gps_data.latitude, g_kjx_gps_data.longitude, g_kjx_gps_data.data_status, 
	//		g_kjx_gps_data.date.nYear, g_kjx_gps_data.date.nMonth, g_kjx_gps_data.date.nDay, 
	//		g_kjx_gps_data.date.nHour, g_kjx_gps_data.date.nMin, g_kjx_gps_data.date.nSec);
#endif
#endif

	if(g_kjx_gps_data.data_status == 'A')
	{
		if(IsMyTimerExist(KJX_TIMER_ID_GPS_RESET))
			StopTimer(KJX_TIMER_ID_GPS_RESET);
		
		if((kjx_get_foctory_test_mode() == 1) && (kjx_get_test_mode_gps_start()==1))
		{
		#ifdef MAIN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("001");
		#endif
		#endif

			kjx_factory_gps_end();
		}	

		if(g_gps_status != 2)
		{
			g_gps_status = 2;

			/*更新GPS状态图标*/
			wgui_status_icon_bar_reset_icon_display(STATUS_ICON_GPS_OFF);
			wgui_status_icon_bar_reset_icon_display(STATUS_ICON_GPS_ON);
			wgui_status_icon_bar_set_icon_display(STATUS_ICON_GPS_OK);
			wgui_status_icon_bar_update();
		}
		
	#if defined(__KJX_POSITION_TRIGGER_PLAY__)
	  #ifdef __KJX_POSITION_TRIGGER_IN_LOCAL__
		kjx_position_trigger_process_in_local(g_kjx_gps_data.longitude_dir, g_kjx_gps_data.longitude, g_kjx_gps_data.latitude_dir, g_kjx_gps_data.latitude);
	  #else
		if(!IsMyTimerExist(KJX_TIMER_ID_SEND_POSITION_TRIGGER))
			StartTimer(KJX_TIMER_ID_SEND_POSITION_TRIGGER, 5*1000, kjx_handle_send_position_for_play);
	  #endif
	#endif
	
	}
	else
	{
		//xb add 2017-07-24 防止GPS模块在紧急模式下长时间不定位
		if((g_kjx_nvram_struct.workMode == 0)&&(!IsMyTimerExist(KJX_TIMER_ID_GPS_RESET)))
		{
			StartTimer(KJX_TIMER_ID_GPS_RESET, 10*60*1000, kjx_gps_software_reset);
		}

		if(g_gps_status == 2)
		{
			g_gps_status = 1;

			/*更新GPS状态图标*/
			wgui_status_icon_bar_reset_icon_display(STATUS_ICON_GPS_OFF);
			wgui_status_icon_bar_reset_icon_display(STATUS_ICON_GPS_OK);
			wgui_status_icon_bar_set_icon_display(STATUS_ICON_GPS_ON);
			wgui_status_icon_bar_update();
		}
	}

	if((g_kjx_nvram_struct.workMode != 0) && (kjx_get_foctory_test_mode() == 0))	//xb add 2016-09-24 防止某系异常情况下GPS一直打开(紧急模式除外)
	{
		if(!IsMyTimerExist(KJX_TIMER_ID_GPS_CLOSE))
		{
			if(!mmi_bootup_is_sim_valid())
				StartTimer(KJX_TIMER_ID_GPS_CLOSE, 1000*60, kjx_close_gps);
			else
				StartTimer(KJX_TIMER_ID_GPS_CLOSE, 1000*60*5, kjx_close_gps);
		}
	}

#ifdef __KJX_WEATHER_SUPPORT__
	kjx_weather.latitude = g_kjx_gps_data.latitude;
	kjx_weather.longitude = g_kjx_gps_data.longitude;
#endif	
}
#endif

void kjx_tour_move_timeout(BOOL timeout)
{
#if 0	//xb add 2017-02-16  GPS不再根据是否休眠来关闭，因此退出休眠后不需要再补传GPS
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("timeout:%d", timeout);
#endif
#endif
	if(timeout)
	{
		/*停止读取基站数据*/
		StopTimer(KJX_TIMER_ID_CELL_REQ);
		StopTimer(KJX_TIMER_ID_NBR_CELL_REQ);
		/*停止上传定位数据*/
		StopTimer(KJX_TIMER_ID_GPS_DATA);
		
	#ifdef __KJX_FUN_GPS__
		kjx_close_gps();
	#endif	
	}
	else
	{
		if(g_kjx_nvram_struct.workMode==2)
		{/*休眠模式*/
		#if defined(__KJX_LOG_OUTPUT__)
			//LOGD("001");
		#endif
			//return;
		}
		
	#ifdef __KJX_FUN_GPS__
		kjx_open_gps();
	#endif
		
		/*上传定位数据*/
		if(socketConnet)
			StartTimer(KJX_TIMER_ID_GPS_DATA, 60*1000, kjx_tour_socket_send_gps_data);
		else
			StartTimer(KJX_TIMER_ID_LOGIN_AGAIN, 60*1000, g_kjx_socket_event_func.socket_login_again);

	}
#endif	
}

void kjx_tour_socket_timeout(void)
{
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_ReconnetCount:%d", g_ReconnetCount);
#endif
#endif

	if(IsMyTimerExist(KJX_TIMER_ID_IS_CONNET))
		StopTimer(KJX_TIMER_ID_IS_CONNET);
	if(IsMyTimerExist(KJX_TIMER_ID_HEART_BEAT))
		StopTimer(KJX_TIMER_ID_HEART_BEAT);
	if(IsMyTimerExist(KJX_TIMER_ID_SOCKET_NOTIFY_OVERTIME))
		StopTimer(KJX_TIMER_ID_SOCKET_NOTIFY_OVERTIME);
#ifdef __KJX_WEATHER_SUPPORT__
	if(IsMyTimerExist(KJX_TIMER_ID_GET_WEATHER))
		StopTimer(KJX_TIMER_ID_GET_WEATHER);
#endif

	if(socketConnet)
		socketConnet = FALSE;
	
	kjx_socket_session_free();

	g_ReconnetCount++;
	if(g_ReconnetCount > RECOUNT_MXA_L5)
	{
		StartTimer(KJX_TIMER_ID_LOGIN_AGAIN, KJX_GPRS_RECONECT_INTERVAL_L5, g_kjx_socket_event_func.socket_login_again);
	}
	else if(g_ReconnetCount > RECOUNT_MXA_L4)
	{
		StartTimer(KJX_TIMER_ID_LOGIN_AGAIN, KJX_GPRS_RECONECT_INTERVAL_L4, g_kjx_socket_event_func.socket_login_again);
	}
	else if(g_ReconnetCount > RECOUNT_MXA_L3)
	{
		StartTimer(KJX_TIMER_ID_LOGIN_AGAIN, KJX_GPRS_RECONECT_INTERVAL_L3, g_kjx_socket_event_func.socket_login_again);
	}
	else if(g_ReconnetCount > RECOUNT_MXA_L2)
	{
		StartTimer(KJX_TIMER_ID_LOGIN_AGAIN, KJX_GPRS_RECONECT_INTERVAL_L2, g_kjx_socket_event_func.socket_login_again);
	}
	else if(g_ReconnetCount > RECOUNT_MXA_L1)
	{
		StartTimer(KJX_TIMER_ID_LOGIN_AGAIN, KJX_GPRS_RECONECT_INTERVAL_L1, g_kjx_socket_event_func.socket_login_again);
	}
	else
	{
		StartTimer(KJX_TIMER_ID_LOGIN_AGAIN, KJX_GPRS_RECONECT_INTERVAL_L0, g_kjx_socket_event_func.socket_login_again);
	}

	/*更新GPRS状态图标*/
	wgui_status_icon_bar_reset_icon_display(STATUS_ICON_GPRS_LINK);
	wgui_status_icon_bar_set_icon_display(STATUS_ICON_GPRS_UNLINK);
	wgui_status_icon_bar_update();
}

void kjx_reset_gps_data_send_func(void)
{
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	if(IsMyTimerExist(KJX_TIMER_ID_GPS_DATA))
		StopTimer(KJX_TIMER_ID_GPS_DATA);
	if(IsMyTimerExist(KJX_TIMER_ID_GPS_OPEN));
		StopTimer(KJX_TIMER_ID_GPS_OPEN);
	if(IsMyTimerExist(KJX_TIMER_ID_GPS_CLOSE))
		StopTimer(KJX_TIMER_ID_GPS_CLOSE);

#if defined(__KJX_FUN_GPS__)
	if((mmi_get_gps_status())&&(kjx_gps_is_on()))
	{
		StartTimer(KJX_TIMER_ID_GPS_DATA, (1000*5), kjx_tour_socket_send_gps_data);
	}
	else
#endif
	{
		kjx_open_gps();
		StartTimer(KJX_TIMER_ID_GPS_DATA, (1000*60), kjx_tour_socket_send_gps_data);
	}
}

void kjx_tour_handle_gps_work_mode(S32 result)
{
	static U16 gps_work_time = 0;

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("workMode:%d", g_kjx_nvram_struct.workMode);
#endif
#endif

	gps_work_time++;
	if(gps_work_time<6)
	{
		StartTimer(KJX_TIMER_ID_GPS_DATA, 1000*10, kjx_handle_send_gps_data);
		return;
	}
	else
	{
		gps_work_time = 0;
	}

	switch(g_kjx_nvram_struct.workMode)
	{
	case 0:/*紧急模式（10秒一次上报GPS数据）*/
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("紧急模式 10S一次");
	#endif
	#endif

		if(!kjx_gps_is_on())
			kjx_open_gps();
	    StartTimer(KJX_TIMER_ID_GPS_DATA, 1000*10, kjx_tour_socket_send_gps_data);
		break;
			
	case 1:/*正常模式（10分钟一次上报GPS数据）*/
		/*省电考虑，不管发送成功与否，都关闭GPS*/
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("正常模式 %d分钟一次",   GPS_DATA_TIME/(60*1000));
	#endif
	#endif

		kjx_stop_get_cellid();
	#if defined(__KJX_FUN_GPS__)
		kjx_close_gps();
	#endif
	
		StartTimer(KJX_TIMER_ID_GPS_OPEN, GPS_DATA_TIME-(1000*60*1), kjx_open_gps);
		StartTimer(KJX_TIMER_ID_GPS_DATA, GPS_DATA_TIME, kjx_tour_socket_send_gps_data);
		break;
		
	case 2:/*自定义模式*/
		/*省电考虑，不管发送成功与否，都关闭GPS*/
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("自定义模式 %d分钟一次",    g_kjx_nvram_struct.sendTime/(60*1000));
	#endif
	#endif

		kjx_stop_get_cellid();
	#if defined(__KJX_FUN_GPS__)
		kjx_close_gps();
	#endif

		StartTimer(KJX_TIMER_ID_GPS_OPEN, g_kjx_nvram_struct.sendTime-(1000*60*1), kjx_open_gps);
		StartTimer(KJX_TIMER_ID_GPS_DATA, g_kjx_nvram_struct.sendTime, kjx_tour_socket_send_gps_data);
		break;
		
	default:
		/*省电考虑，不管发送成功与否，都关闭GPS*/
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("默认模式 %d分钟一次",   GPS_DATA_TIME/(60*1000));
	#endif
	#endif

		kjx_stop_get_cellid();
	#if defined(__KJX_FUN_GPS__)
		kjx_close_gps();
	#endif

		StartTimer(KJX_TIMER_ID_GPS_OPEN, GPS_DATA_TIME-(1000*60*1), kjx_open_gps);
		StartTimer(KJX_TIMER_ID_GPS_DATA, GPS_DATA_TIME, kjx_tour_socket_send_gps_data);
		break;
	}
}

void kjx_tour_socket_send_power_on(void)
{
	kjx_socket_send_data_with_type(SERVER_TYPE_79);
}

void kjx_tour_socket_send_heartbeat(void)
{/*心跳包*/
    S32 result = 0;
	static U16 timeCheck = 0;

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

    StopTimer(KJX_TIMER_ID_HEART_BEAT);
    kjx_socket_send_data_with_type(SERVER_TYPE_01);

 	if(!timeCheck)
	{
		timeCheck = 1;	
		g_kjx_nvram_struct.updateStatus[SERVER_TYPE_57]=1;
	}
	
    StartTimer(KJX_TIMER_ID_HEART_BEAT, HEART_BEAT_TIME, kjx_tour_socket_send_heartbeat);
    StartTimer(KJX_TIMER_ID_IS_CONNET, HEART_BEAT_WAIT_CB_TIME, kjx_tour_socket_timeout);
}

void kjx_tour_gps_work_mode(void)
{
	static U16 first_gps = 0;
	static U16 wait_gps = 0;
    static int i =0;    
	
#if defined(__KJX_FUN_GPS__)
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("data_status:%c", g_kjx_gps_data.data_status);
#endif
#endif
#endif

	if((!first_gps)&&(wait_gps<6))
	{
	#if defined(__KJX_FUN_GPS__)
		if(g_kjx_gps_data.data_status == 'A')
		{
			first_gps = 1;
			kjx_tour_socket_send_gps_data();
			return;
		}
		else
	#endif
		{
			if(wait_gps == 6)
			{//1分钟未搜索到GPS，走正常程序
				first_gps = 1;
				kjx_tour_socket_send_gps_data();
                return;
			}
			
			wait_gps++;
		#ifdef MAIN_TOUR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("first_gps = 0");
		#endif
		#endif
			StartTimer(KJX_TIMER_ID_GPS_DATA, 1000*10, kjx_tour_gps_work_mode);
			return;
		}
	}

	switch(g_kjx_nvram_struct.workMode)
	{
	case 0:/*紧急模式（10秒一次上报GPS数据）*/
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("紧急模式 10S一次");
	#endif
	#endif

		if(!kjx_gps_is_on())
			kjx_open_gps();
	    StartTimer(KJX_TIMER_ID_GPS_DATA, 1000*10, kjx_tour_socket_send_gps_data);
		break;
			
	case 1:/*工作模式（30分钟一次上报GPS数据）*/
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("正常模式 %d分钟一次",   GPS_DATA_TIME/(60*1000));
	#endif
	#endif
	
		/*省电考虑，不管发送成功与否，都关闭GPS*/
		kjx_stop_get_cellid();
	#if defined(__KJX_FUN_GPS__)
		kjx_close_gps();
	#endif
	       
		StartTimer(KJX_TIMER_ID_GPS_OPEN, GPS_DATA_TIME-(1000*60*1), kjx_open_gps);
		StartTimer(KJX_TIMER_ID_GPS_DATA, GPS_DATA_TIME, kjx_tour_socket_send_gps_data);
		break;
		
	case 2:/*自定义模式*/
		/*省电考虑，不管发送成功与否，都关闭GPS*/
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("自定义模式 %d分钟一次",  g_kjx_nvram_struct.sendTime/(60*1000));
	#endif
	#endif

		kjx_stop_get_cellid();
	#if defined(__KJX_FUN_GPS__)
		kjx_close_gps();
	#endif
	
		StartTimer(KJX_TIMER_ID_GPS_OPEN, g_kjx_nvram_struct.sendTime-(1000*60*1), kjx_open_gps);
		StartTimer(KJX_TIMER_ID_GPS_DATA, g_kjx_nvram_struct.sendTime, kjx_tour_socket_send_gps_data);
		break;
		
	default:
		/*省电考虑，不管发送成功与否，都关闭GPS*/
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("默认模式 %d分钟一次", __func__, GPS_DATA_TIME/(60*1000));
	#endif
	#endif

		kjx_stop_get_cellid();
	#if defined(__KJX_FUN_GPS__)
		kjx_close_gps();
	#endif
	       
		StartTimer(KJX_TIMER_ID_GPS_OPEN, GPS_DATA_TIME-(1000*60*1), kjx_open_gps);
		StartTimer(KJX_TIMER_ID_GPS_DATA, GPS_DATA_TIME, kjx_tour_socket_send_gps_data);
		break;
	}
	
}

void kjx_tour_socket_send_gps_data(void)
{/*位置数据包*/
    S32 result = 0;

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

    StopTimer(KJX_TIMER_ID_GPS_DATA);

	if(kjx_gps_is_valid())
	    result=kjx_socket_send_data_with_type(SERVER_TYPE_03);
	else
		result=kjx_socket_send_data_with_type(SERVER_TYPE_84);
	
    kjx_tour_gps_work_mode();
}

void kjx_tour_trace_to_service(kjx_socket_type socket_type)
{
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
    kjx_socket_send_data_with_type(socket_type);
}

/***********************************************************************************/
void kjx_tour_check_do_somthing(void)//xb add 2017-05-16 5秒检查一次
{
    U8 batteryStatus;
    applib_time_struct currTime;
    U8 gsm_status;
    static U16 checkNet = 0;

    kjx_set_status_icon();
    kjx_write_work_time();
    gsm_status = kjx_sys_get_cur_gsm_status();
#ifdef MAIN_TOUR_DEBUG	
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("gsm_status=%d", gsm_status);
#endif
#endif
    memset(&currTime, 0x00, sizeof(currTime));
    applib_dt_get_rtc_time(&currTime);	

#if 0	//xb add  20201203 去掉凌晨3点自动重启的功能
    if((currTime.nHour == 3)&&(currTime.nMin == 0)&&(currTime.nSec>0)&&(currTime.nSec<10))
    {/*每天3点钟重启设备*/
    #ifdef MAIN_TOUR_DEBUG	
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("restart!");
	#endif
	#endif
	
        g_kjx_socket_event_func.socket_restart();
        return;
    }
#endif

    //kjx_tour_check_led();

	if(mmi_bootup_is_sim_valid())	//xb add 2016-09-22 插卡的情况下才会去连接GPRS
    {
	    checkNet++;
	    if((!socketConnet)&&(checkNet>=(3*12)))//xb add 2016-05-16 3分钟监测一次，避免重连过程中被打断不停地重连
	    {
	    	checkNet = 0;
			if(!IsMyTimerExist(KJX_TIMER_ID_IS_CONNET)&&!IsMyTimerExist(KJX_TIMER_ID_LOGIN_AGAIN)&&!g_gprs_is_retry)
			{
			#ifdef MAIN_TOUR_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("001");
			#endif
			#endif
				kjx_tour_socket_timeout();
			}
	    }
	    else if(socketConnet)
	    {
	    	checkNet = 0;
	    }
	}
}

void kjx_tour_gprs_recvbuf_parse(kal_int32 len)
{
	kjx_gprs_recvbuf_parse(len);
}

#ifdef __KJX_WEATHER_SUPPORT__
void kjx_tour_socket_get_weather(void)
{
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

    kjx_socket_send_data_with_type(SERVER_TYPE_80);
}

void kjx_tour_socket_get_city(void)
{
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

    kjx_socket_send_data_with_type(SERVER_TYPE_81);
}

void kjx_updata_weather(void)
{
	if(strlen(kjx_weather.cityname) > 0)
	{
		kjx_tour_socket_get_weather();
		StartTimer(KJX_TIMER_ID_GET_WEATHER, 30*60*1000, kjx_updata_weather);
	}
	else
	{
		kjx_tour_socket_get_city();
		StartTimer(KJX_TIMER_ID_GET_WEATHER, 5*1000, kjx_updata_weather);
	}
}
#endif

/***********************************************************************************/
/***********************************************************************************/
void kjx_socket_send_connect(kal_int8 socket_id)
{
#if defined(__KJX_FUN_AGPS__)
	if(g_kjx_agps_socket_context.socket_id == socket_id)
	{	
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("AGPS");
	#endif
	#endif
		kjx_agps_socket_connect_ublox();
		return;
	}
#endif

	if(g_kjx_socket_context.socket_id == socket_id)
	{
		if(kjx_frist_power_on)
		{
			kjx_frist_power_on = FALSE;
			kjx_tour_socket_send_power_on();
		}

		if(!IsMyTimerExist(KJX_TIMER_ID_HEART_BEAT))
		{
		#ifdef MAIN_TOUR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("first heartbeat");
		#endif
		#endif

			StartTimer(KJX_TIMER_ID_HEART_BEAT, 3*1000, kjx_tour_socket_send_heartbeat);
		}
		else if(heartbeat_need_send > 0)
		{
		#ifdef MAIN_TOUR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("resend heartbeat");
		#endif
		#endif

			StartTimer(KJX_TIMER_ID_HEART_BEAT, 3*1000, kjx_tour_socket_send_heartbeat);
		}

		if(rfid_need_send == 1)
		{
		#ifdef MAIN_TOUR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("resend rfid");
		#endif
		#endif
		#if defined(__KJX_POSITION_TRIGGER_PLAY__)
			if(g_play_cause == 1)
			{
				kjx_handle_send_position_trigger_data();
			}
			else
		#endif
			{
			#if defined(__KJX_SERVER_CMD_PLAY__)
	           	if(g_play_cause != 2)
			#endif
					kjx_handle_send_rfid_data();
			}
		}

	#ifdef __KJX_MULTI_LANGUAGE__
		StartTimer(KJX_TIMER_ID_RESEND_LANGUAGE_SET, 5*1000, kjx_handle_send_system_language);
	#endif

	#ifdef __KJX_WEATHER_SUPPORT__
		if(!IsMyTimerExist(KJX_TIMER_ID_GET_WEATHER))
		{
			StartTimer(KJX_TIMER_ID_GET_WEATHER, 8*1000, kjx_updata_weather);
		}
	#endif
	}
	else
	{
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("socket_id is not used!");
	#endif
	#endif
	}
}

void kjx_tour_func_init(void)
{
	g_socket_notify_func.socket_notify_connect = kjx_socket_send_connect;
	g_kjx_socket_event_func.recvbuf_hex_to_acsii = kjx_tour_gprs_recvbuf_parse;
	g_kjx_socket_event_func.socket_send_gps = kjx_tour_socket_send_gps_data;
	g_kjx_socket_event_func.handle_gps_work_mode = kjx_tour_handle_gps_work_mode;
#ifdef __KJX_FUN_GPS__
	g_kjx_gps_func.gps_do_something_with_custom = kjx_tour_do_something_with_custom;
#endif
#if defined(__KJX_FUN_SENSOR__)
	g_kjx_sensor_func.sensor_func_init = kjx_sensor_func_init_tour;
#endif
}

void kjx_func_custom_init(void)
{
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
	g_kjx_main_func.kjx_check_fun = kjx_tour_check_do_somthing;
	g_kjx_main_func.kjx_main_custom = kjx_func_main_tour;
	//g_kjx_main_func.kjx_set_move_status = kjx_tour_set_move_status;
	g_kjx_main_func.kjx_set_gsm_led = kjx_tour_gsm_led;
	
	g_kjx_main_func.sms_out_area_alarm = kjx_tour_send_sms_out_area_alarm;
	g_kjx_main_func.sms_in_area_alarm = kjx_tour_send_sms_in_area_alarm;
	g_kjx_main_func.call_area_alarm = kjx_tour_send_call_area_alarm;
}

#ifdef __KJX_MMI_SHOW_VER_IMEI__
char* kjx_tour_get_verno(void)
{
	char*verData = NULL;
#ifdef __KJX_CUSTOMER_WF__
	verData = strstr(KJX_VERSION,"V");
#else
	verData = strstr((const char*)(release_verno()),"V");
#endif
	if(verData != NULL)
	{
		return verData;
	}
}
char* kjx_tour_get_date(void)
{
	char*verDate = NULL;

	verDate = strstr((const char*)(build_date_time()),"/");
	verDate += strlen("/");
	
	if(verDate != NULL)
	{
		return verDate;
	}
}
#endif

void kjx_set_status_icon(void)
{ 
	
	#if 0//def __KJX_FUN_GPS__
	//GPS
	if(!kjx_gps_is_on())
	{
		wgui_status_icon_bar_show_icon(STATUS_ICON_NO_GPS);
		wgui_status_icon_bar_hide_icon(STATUS_ICON_GPS_ON);
		wgui_status_icon_bar_hide_icon(STATUS_ICON_GPS_OFF);
	}
	else
	{
		if(g_kjx_gps_data.data_status == 'A')
		{
			wgui_status_icon_bar_show_icon(STATUS_ICON_GPS_ON);
			wgui_status_icon_bar_hide_icon(STATUS_ICON_NO_GPS);
			wgui_status_icon_bar_hide_icon(STATUS_ICON_GPS_OFF);
		}
		else
		{
			wgui_status_icon_bar_show_icon(STATUS_ICON_GPS_OFF);
			wgui_status_icon_bar_hide_icon(STATUS_ICON_NO_GPS);
			wgui_status_icon_bar_hide_icon(STATUS_ICON_GPS_ON);
		}
	}
	#endif
	  
	//gprs
	/*if(kjx_gprs_is_connect_check()&&!kjx_gprs_is_connect())
	{
		wgui_status_icon_bar_show_icon(STATUS_ICON_GPRS_CHECK);
		wgui_status_icon_bar_hide_icon(STATUS_ICON_GPRS_CONNECT);
		wgui_status_icon_bar_hide_icon(STATUS_ICON_GPRS_DISCONNECT);
	}
	else if(!kjx_gprs_is_connect_check()&&!kjx_gprs_is_connect())
	{
		wgui_status_icon_bar_show_icon(STATUS_ICON_GPRS_DISCONNECT);
		wgui_status_icon_bar_hide_icon(STATUS_ICON_GPRS_CONNECT);
		wgui_status_icon_bar_hide_icon(STATUS_ICON_GPRS_CHECK);
	}
	else if(kjx_gprs_is_connect())
	{
		wgui_status_icon_bar_show_icon(STATUS_ICON_GPRS_CONNECT);
		wgui_status_icon_bar_hide_icon(STATUS_ICON_GPRS_DISCONNECT);
		wgui_status_icon_bar_hide_icon(STATUS_ICON_GPRS_CHECK);
	}
	*/
}

char* kjx_tour_get_kjx_ver(void)
{
	char verData[32];

	memset(verData,0x00,sizeof(verData));
	memcpy(verData,KJX_VERSION,strlen(KJX_VERSION));

	return verData;
}

#define KJX_IN_CALL() (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_STATE_ALL,NULL) > 0)

void kjx_report_to_custmer_with_type(kjx_sms_send_type sms_type,kjx_socket_type socket_type)
{
	static U16 socket_send = 0;

	if(sms_type == SMS_LIGHT_FALL_OFF)
	{
		if(g_kjx_nvram_struct.antiLostStatus == 0)
			return;
	}

	if(sms_type == SMS_BT_ANTI_LOST)
	{
		if(g_kjx_nvram_struct.btStatus == 0)
			return;
	}

	if(sensor_status)
		return;

	if(KJX_IN_CALL())
		return;
	
	// sms/call operation
	if((g_kjx_nvram_struct.alarmType==0)||(g_kjx_nvram_struct.alarmType==3))
	{//短信推送
		switch(sms_type)
		{
			case SMS_LIGHT_FALL_OFF:
				g_kjx_main_func.light_fall_off(sms_type);
				break;
			case SMS_BT_ANTI_LOST:
				g_kjx_main_func.bt_anti_lost(sms_type);
				break;
		}
	}
	else if(g_kjx_nvram_struct.alarmType==2)
	{//电话推送
		g_kjx_main_func.call_area_alarm();
	}
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("socketConnet:%d", socketConnet);
#endif
#endif
	if(!socketConnet)
		return;

	if((g_kjx_nvram_struct.alarmType==1)||(g_kjx_nvram_struct.alarmType==3))
	{
		// server operation
		switch(socket_type)
		{
			case SERVER_TYPE_43:
				socket_send = 1;
				g_kjx_nvram_struct.updateStatus[SERVER_TYPE_43]=1;
				break;
			case SERVER_TYPE_42:
				socket_send = 1;
				g_kjx_nvram_struct.updateStatus[SERVER_TYPE_42]=1;
				break;

			default :
				socket_send = 0;
				break;
		}
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("socket_send:%d", socket_send);
	#endif
	#endif
		if(socket_send != 0)
		{
			socket_send = 0;
			kjx_socket_send_data_all();
		}
	}

}

void kjx_bt_antilost_alert(void)
{
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
	kjx_report_to_custmer_with_type(SMS_BT_ANTI_LOST,SERVER_TYPE_42);
}

void kjx_shut_down(void)
{
	srv_shutdown_exit_system(0);
}

/*char teststring[]=
{
0x60,0x4e,0xd1,0x8f,0x73,0x5e,0x68,0x88,0x3a,0x79,0xc,0xff,0x73,0x59,0x8b,0x73,0x5b,0x96,0xb,0x4e,0xfe,0x66,0x8e,0x4e,0x31,0x0,0x39,0x0,0x37,0x0,0x39,0x0,0x74,0x5e,0xbf,0x8b,0x4e,0x53,0xc,0xff,0x2f,0x66,0x2d,0x4e,0xfd,0x56,0x39,0x65,0x69,0x97,0x0,0x5f,0x3e,0x65,0xe,0x54,0x96,0x99,0x4d,0x4f,0xbf,0x8b,0x4e,
0x53,0x84,0x76,0x7f,0x89,0xb9,0x65,0xfd,0x56,0xb6,0x5b,0x43,0x51,0x96,0x99,0x2,0x30,0xf6,0x65,0x94,0x96,0x33,0x0,0x35,0x0,0x74,0x5e,0xc,0xff,0x60,0x4f,0x8d,0x51,0x21,0x6b,0x65,0x67,0xbf,0x8b,0xc,0xff,0x2d,0x4e,0xfd,0x56,0xd1,0x53,0x55,0x5c,0xdb,0x8f,0x65,0x51,0xb0,0x65,0x36,0x96,0xb5,0x6b,0x2,
0x30,0x60,0x4f,0x84,0x76,0x24,0x4e,0x21,0x6b,0xbf,0x8b,0xee,0x95,0xc1,0x89,0xc1,0x8b,0x86,0x4e,0x2d,0x4e,0xfd,0x56,0x39,0x65,0x69,0x97,0x0,0x5f,0x3e,0x65,0xce,0x4e,0x77,0x8d,0x65,0x6b,0x70,0x8d,0x11,0x54,0x68,0x51,0x62,0x97,0xf1,0x6d,0x16,0x53,0x84,0x76,0x86,0x53,0xf2,0x53,0xdb,0x8f,0xb,0x7a,
0xc,0xff,0x5f,0x4e,0x9,0x67,0x9b,0x52,0xa8,0x63,0xa8,0x52,0x86,0x4e,0x2d,0x4e,0x39,0x4e,0x73,0x51,0xfb,0x7c,0xd1,0x53,0x55,0x5c,0x0,0x0
};*/

void kjx_send_sms_to_my_phone(void)
{
	char sendString[]={0xbe,0x8b,0x7,0x59,0xcd,0x91,0x2f,0x54,0xd0,0x63,0x3a,0x79,0x0,0x0};
	S8 imeiUcs[256];
	S8 sendUcs[256];
	S8 aDataTime[256];
	S8 uDataTime[256];
	applib_time_struct currTime;
	extern U8 kjxImei[];

	StopTimer(100);
	
	if((memcmp(kjxImei,"000000000000080",strlen("000000000000080"))!=0)
	&&(memcmp(kjxImei,"678833010000120",strlen("678833010000120"))!=0)
	&&(memcmp(kjxImei,"888888888888880",strlen("888888888888880"))!=0))
	{
		//return;
	}

	memset(imeiUcs, 0x00, sizeof(imeiUcs));
	memset(sendUcs, 0x00, sizeof(sendUcs));
	memset(aDataTime, 0x00, sizeof(aDataTime));
	applib_dt_get_rtc_time(&currTime);
	sprintf(aDataTime,"%04d/%02d/%02d,%02d:%02d.%02d",currTime.nYear,currTime.nMonth,currTime.nDay,currTime.nHour,currTime.nMin,currTime.nSec);
	mmi_asc_to_ucs2((CHAR *)uDataTime, (CHAR *)aDataTime);
	mmi_asc_to_ucs2((CHAR *)imeiUcs, (CHAR *)kjxImei);
	mmi_ucs2cat((CHAR *)sendUcs, (const CHAR *)uDataTime);
	mmi_ucs2cat((CHAR *)sendUcs, (const CHAR *)(L";"));
	mmi_ucs2cat((CHAR *)sendUcs, (const CHAR *)imeiUcs);
	mmi_ucs2cat((CHAR *)sendUcs, (const CHAR *)sendString);
	kjx_sms_send_sms("13480106089", (U16 *)sendUcs, 0x08, NULL);

}

BOOL kjx_imei_is_valid(void)
{
	//设备编码无效，设备将不能正常工作！
	if(strlen(kjxImei)<14)
	{
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return FALSE");
	#endif
	#endif
		return FALSE;
	}
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("return TRUE");
#endif
#endif
	return TRUE;
}

#include "accdet_hw.h"
//#define KJX_AUX_EINT_STATE		1  //0: LEVEL_LOW; 1: LEVEL_HIGH
extern const unsigned char AUX_EINT_NO;
extern kal_bool kjx_aux_eint_state;

extern void KJX_AUX_EINT_HISR(void);
void kjx_aux_eint_init(void)
{
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	/*EINT_Registration(RFID_EINT_NO, KAL_FALSE, RFID_EINT_STATUS_VALID,kjx_rfid_eint_hisr,KAL_TRUE);     
	EINT_Set_Sensitivity(RFID_EINT_NO, EDGE_SENSITIVE); 
	EINT_Set_Polarity(RFID_EINT_NO, KAL_TRUE);*/
	
	EINT_Registration(AUX_EINT_NO, KAL_TRUE, kjx_aux_eint_state, KJX_AUX_EINT_HISR, KAL_TRUE);
	EINT_SW_Debounce_Modify(AUX_EINT_NO, 10);
}

BOOL kjx_rfid_test_time(void)
{
	static int mytime = 0;

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	if(g_rfid_test_timer)
	{
		g_rfid_test_timer = FALSE;

		if(mytime==15)
		{
		#ifdef MAIN_TOUR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("FALSE g_rfid_test_timer:%d", g_rfid_test_timer);
		#endif
		#endif

			return FALSE;
		}
		else
		{
		#ifdef MAIN_TOUR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("TRUE, g_rfid_test_timer:%d", g_rfid_test_timer);
		#endif
		#endif
		
			return TRUE;
		}
	}
	
	StopTimer(KJX_TIMER_ID_RFID_TEST_TIME);

	if(mytime<11)
	{
		mytime++;
	}
	else
	{
		mytime = 15;
	}

	if(mytime==15)
	{//超时
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("FALSE, mytime:%d", mytime);
	#endif
	#endif

		
		return FALSE;
	}
	else
	{
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("FALSE, mytime:%d", mytime);
	#endif
	#endif
		
		StartTimer(KJX_TIMER_ID_RFID_TEST_TIME,1000*60, kjx_rfid_test_time);
		return TRUE;
	}


}

#if 1
BOOL kjx_rfid_will_stop_work(void)
{
    return FALSE;
}
#else
BOOL kjx_rfid_will_stop_work(void)
{
	applib_time_struct currTime;
	static U16 playTotal = 0;
	BOOL result = FALSE;

	//尊敬的游客，您好！您所持有的智游星旅游卡已失效！
	char playString[]={0xa,0x5c,0x6c,0x65,0x84,0x76,0x38,0x6e,0xa2,0x5b,0xc,0xff,0xa8,0x60,0x7d,0x59,0x1,0xff,0xa8,0x60,0x40,0x62,0x1,0x63,0x9,0x67,0x84,0x76,0x7a,0x66,0x38,0x6e,0x1f,0x66,0xc5,0x65,0x38,0x6e,0x61,0x53,0xf2,0x5d,0x31,0x59,0x48,0x65,0x1,0xff,0x0,0x0};

    if (kjx_get_foctory_test_mode()==1)
    {
        return FALSE;
    }
	
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("time:%d-%d-%d-%d",  g_kjx_nvram_struct.rfidOverTime.nYear,g_kjx_nvram_struct.rfidOverTime.nMonth,g_kjx_nvram_struct.rfidOverTime.nDay,g_kjx_nvram_struct.rfidOverTime.nHour);
#endif
#endif

	if((g_kjx_nvram_struct.rfidOverTime.nYear==0)
	||(g_kjx_nvram_struct.rfidOverTime.nMonth==0)
	||(g_kjx_nvram_struct.rfidOverTime.nDay==0))
	{/*开机默认不可用*/
		if(kjx_rfid_test_time())
		{//10分钟测试时间内可用
		#ifdef MAIN_TOUR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("return FALSE");
		#endif
		#endif

			return FALSE;
		}

	#if defined(__NPR_TTS__)
	 	if(!playTotal)
	 	{
	 		playTotal = 1;
		 	Npr_Tts_play_stop();
		 	Npr_Ttsplayer_playtextw(playString,NULL);  
	 	}
	#endif

	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return TRUE");
	#endif
	#endif
	
		return TRUE;
	}

	applib_dt_get_rtc_time(&currTime);

	if(currTime.nYear<=g_kjx_nvram_struct.rfidOverTime.nYear)
	{
		if(currTime.nYear==g_kjx_nvram_struct.rfidOverTime.nYear)
		{
			if(currTime.nMonth==g_kjx_nvram_struct.rfidOverTime.nMonth)
			{
				if(currTime.nDay==g_kjx_nvram_struct.rfidOverTime.nDay)
				{
					if(currTime.nHour<g_kjx_nvram_struct.rfidOverTime.nHour)
					{
					#ifdef MAIN_TOUR_DEBUG
					#if defined(__KJX_LOG_OUTPUT__)
						LOGD("001");
					#endif
					#endif
						result = FALSE;
					}
					else
					{
					#ifdef MAIN_TOUR_DEBUG
					#if defined(__KJX_LOG_OUTPUT__)
						LOGD("002");
					#endif
					#endif
						result = TRUE;
					}
				}
				else if(currTime.nDay>g_kjx_nvram_struct.rfidOverTime.nDay)
				{
				#ifdef MAIN_TOUR_DEBUG
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("003");
				#endif
				#endif
					
					result = TRUE;
				}
				else if(currTime.nDay<g_kjx_nvram_struct.rfidOverTime.nDay)
				{
				#ifdef MAIN_TOUR_DEBUG
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("004");
				#endif
				#endif
					
					result = FALSE;
				}
			}
			else if(currTime.nMonth>g_kjx_nvram_struct.rfidOverTime.nMonth)
			{
			#ifdef MAIN_TOUR_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("005");
			#endif
			#endif
				
				result = TRUE;
			}
			else if(currTime.nMonth<g_kjx_nvram_struct.rfidOverTime.nMonth)
			{
			#ifdef MAIN_TOUR_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("006");
			#endif
			#endif
				
				result = FALSE;
			}
		}
		else if(currTime.nYear<g_kjx_nvram_struct.rfidOverTime.nYear)
		{
		#ifdef MAIN_TOUR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("007");
		#endif
		#endif
			
			result = FALSE;
		}
	}
	else
	{
		if((ABS(currTime.nYear-g_kjx_nvram_struct.rfidOverTime.nYear))>1)
		{//时间尚未更新状态
		#ifdef MAIN_TOUR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("008");
		#endif
		#endif
			
			result = FALSE;
		}
		else if((ABS(currTime.nYear-g_kjx_nvram_struct.rfidOverTime.nYear))==1)
		{
		#ifdef MAIN_TOUR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("009");
		#endif
		#endif
			
			result = TRUE;
		}
	}

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("result:%d", result);
#endif
#endif

	if(result)
	{      
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("playTotal:%d", playTotal);
	#endif
	#endif

	#if defined(__NPR_TTS__)
		 if(!playTotal)
		 {
		 	playTotal = 1;
			Npr_Tts_play_stop();
			Npr_Ttsplayer_playtextw(playString,NULL);  
		 }
	#endif
	}

	return result;
	
}
#endif

#ifdef __BLE_MODULE_SUPPORT__
void kjx_bt_ibeacon_gpio_int(void)
{
	DCL_HANDLE gpio_handle;

	gpio_handle = DclGPIO_Open(DCL_GPIO,18);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_IN,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_LOW,NULL);
	DclGPIO_Close(gpio_handle);
}

void kjx_bt_ibeacon_init(void)
{
	DCL_HANDLE gpio_handle;

	if(g_kjx_ble_is_on == FALSE)
	{
		g_kjx_ble_is_on = TRUE;
		
		gpio_handle = DclGPIO_Open(DCL_GPIO,18);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_IN,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_HIGH,NULL);
		DclGPIO_Close(gpio_handle);
	
		ble_mod_power_on();
	
		/*显示BLE状态图标*/
		wgui_status_icon_bar_set_icon_display(STATUS_ICON_BLE_ON);
	    wgui_status_icon_bar_update();
	}
}

void kjx_bt_ibeacon_off(void)
{
	DCL_HANDLE gpio_handle;

	if(g_kjx_ble_is_on)
	{
		g_kjx_ble_is_on = FALSE;

		ble_mod_power_off();

		gpio_handle = DclGPIO_Open(DCL_GPIO,18);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_IN,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_LOW,NULL);
		DclGPIO_Close(gpio_handle);

	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("kjx_rfid_id:%d, g_kjx_ble_id:%d", kjx_rfid_id, g_kjx_ble_id);
	#endif
	#endif
		if(g_kjx_ble_id == kjx_rfid_id)
		{
			mdi_audio_stop_file();
			kjx_audio_is_playing = FALSE;
			kjx_audio_status = 0xff;

			g_kjx_ble_id = 0;
			kjx_rfid_id = 0;
			myID = 0;
			last_id = -1;

			memset(kjx_scrolling_show, 0, sizeof(kjx_scrolling_show));
			mmi_show_scrolling_infor();
		}
		
		/*隐藏BLE状态图标*/
		wgui_status_icon_bar_reset_icon_display(STATUS_ICON_BLE_ON);
	    wgui_status_icon_bar_update();
	}
}

void kjx_bt_lbeacon_get_data(void)
{
	U8 temBuf[128];
	U8 i,checktmp = 0;
	U32 mybleId = 0x00000000;
	static U8 ble_mode_data_error_count = 0;	
	extern U8 g_rfid_field;
	extern BOOL g_rfid_low_bat;
	extern U32 kjx_rfid_id;
#if defined(__KJX_POSITION_TRIGGER_PLAY__)||defined(__KJX_SERVER_CMD_PLAY__)
	extern U8 g_play_cause;
#endif

	for(i=0;i<BLE_MOD_DATA_LEN-2;i++)
	{
		checktmp = checktmp^ble_data[i];
	}

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	//LOGD("ble_data[0]:%x, ble_data[BLE_MOD_DATA_LEN-1]:%x", ble_data[0], ble_data[BLE_MOD_DATA_LEN-1]);
#endif
#endif

	if((ble_data[0] != 0xDD)||(ble_data[BLE_MOD_DATA_LEN-1] != 0x55))
	{
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		//LOGD("data begin or data end error");
	#endif
	#endif
		return;
	}
	else if(checktmp != ble_data[BLE_MOD_DATA_LEN-2])
	{
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		//LOGD("check error, checktmp:%d, rx_buff[BLE_MOD_DATA_LEN-2]:%d", checktmp, ble_data[BLE_MOD_DATA_LEN-2]);
	#endif
	#endif
	}
	else
	{
		//ID UUID开头4个字节共8位转换成"KEJIAXUN"
		memset(temBuf, 0x00, sizeof(temBuf));
		sprintf(temBuf,"%02X%02X%02X%02X",ble_data[1],ble_data[2],ble_data[3],ble_data[4]);
		if(strcmp(temBuf, BLE_UUID_HEAD) != 0)
		{
			#ifdef MAIN_TOUR_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				//LOGD("UUID head is error:%s", temBuf);
			#endif
			#endif
			
			ble_mode_data_error_count++;
			if(ble_mode_data_error_count > 10)
			{
				ble_mode_data_error_count = 0;
				ble_mod_reset();
			}
			return;
		}
		
		//ID UUID最后4个字节共8位转换成整数
		memset(temBuf, 0x00, sizeof(temBuf));
		sprintf(temBuf,"%02x%02x%02x%02x",ble_data[13],ble_data[14],ble_data[15],ble_data[16]);
		for(i=0;i<strlen(temBuf);i++)
		{
			if(temBuf[i] > '9' || temBuf[i] < '0')
			{
			#ifdef MAIN_TOUR_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				//LOGD("data error 001");
			#endif
			#endif

				ble_mode_data_error_count++;
		        if(ble_mode_data_error_count > 10)
		        {
		            ble_mode_data_error_count = 0;
		            ble_mod_reset();
		        }
				return;
			}
		}
		
		mybleId = atoi(temBuf);
		if(mybleId == 0)
		{
		#ifdef MAIN_TOUR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			//LOGD("data error 002");
		#endif
		#endif

			ble_mode_data_error_count++;
	        if(ble_mode_data_error_count > 10)
	        {
	            ble_mode_data_error_count = 0;
	            ble_mod_reset();
	        }
			return;
		}
		
	#if defined(__KJX_RESET_USED_COUNT__)
		if(mybleId == RESET_RFID)
		{
			kjx_handle_receive_reset_rfid(1);
		}
		else
	#endif
		{
    	#ifdef MAIN_TOUR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("temBuf:%s, mybleId:%d", temBuf, mybleId);
		#endif
	    #endif
		
			//bat status
			if(ble_data[BLE_MOD_DATA_LEN-3]&0x01)
			{
				g_rfid_low_bat = FALSE;
			}
			else
			{
				g_rfid_low_bat = TRUE;
			}

			g_kjx_ble_rssi = ~ble_data[BLE_MOD_DATA_LEN-4]+1;
			
		#ifdef MAIN_TOUR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("kjx_ble_low_bat:%d, ble_data[BLE_MOD_DATA_LEN-4]:%x, g_kjx_ble_rssi:-%d", g_rfid_low_bat, ble_data[BLE_MOD_DATA_LEN-4], g_kjx_ble_rssi);
		#endif
		#endif

		#if defined(__KJX_POSITION_TRIGGER_PLAY__)||defined(__KJX_SERVER_CMD_PLAY__)
			g_play_cause = 0;
		#endif

			if(IsMyTimerExist(KJX_TIMER_RESET_SHOW))
				return;
			
			g_kjx_ble_id = mybleId;
			kjx_rfid_id = mybleId;

			if(kjx_get_foctory_test_mode() == 0)	//xb add 2017-08-24 工厂测试模式下面只收数据不播放
			{
				kjx_rfid_check_id();				
			}
		}

		ble_mode_data_error_count = 0;
	}	
}
#endif

#if defined(__KJX_RFID__)
void kjx_rfid_gpio_init(void)
{
	kjx_rfid_close();
	kjx_rfid_turn_off();
}

void kjx_rfid_init(void)
{
	if(g_rfid_init == 0)
	{
		g_rfid_init = 1;
	
		kjx_rfid_eint_init();
		kjx_rfid_main();
		kjx_rfid_turn_on();

		/*显示RFID状态图标*/
		wgui_status_icon_bar_set_icon_display(STATUS_ICON_RFID_ON);
	    wgui_status_icon_bar_update();
	}
}

void kjx_rfid_off(void)
{
	if(g_rfid_init == 1)
	{
		g_rfid_init = 0;
		
		kjx_rfid_close();
		kjx_rfid_turn_off();

	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("kjx_rfid_id:%d, g_kjx_rfid_id:%d", kjx_rfid_id, g_kjx_rfid_id);
	#endif
	#endif
		if(g_kjx_rfid_id == kjx_rfid_id)
		{
			mdi_audio_stop_file();
			kjx_audio_is_playing = FALSE;
			kjx_audio_status = 0xff;

			g_kjx_rfid_id = 0;
			kjx_rfid_id = 0;
			myID = 0;
			last_id = -1;

			memset(kjx_scrolling_show, 0, sizeof(kjx_scrolling_show));
			mmi_show_scrolling_infor();
		}
		
		/*隐藏RFID状态图标*/
		wgui_status_icon_bar_reset_icon_display(STATUS_ICON_RFID_ON);
	    wgui_status_icon_bar_update();
	}
}
#endif

#if defined(__KJX_DJ_SUPPORT__)
U32 kjx_dj_get_mode_state(void)
{
	return g_kjx_current_dj_or_rfid_mode;
}

void kjx_dj_earphone_ctrl_to_dj(void)
{
	DCL_HANDLE gpio_handle;

	gpio_handle = DclGPIO_Open(DCL_GPIO,DJ_EARPHOEN_CTRL_PIN);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
	DclGPIO_Control(gpio_handle, GPIO_CMD_WRITE_HIGH, NULL);
	DclGPIO_Close(gpio_handle);
}

void kjx_dj_earphone_ctrl_to_rfid(void)
{
	DCL_HANDLE gpio_handle;

	gpio_handle = DclGPIO_Open(DCL_GPIO,DJ_EARPHOEN_CTRL_PIN);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
	DclGPIO_Control(gpio_handle, GPIO_CMD_WRITE_LOW, NULL);
	DclGPIO_Close(gpio_handle);

}


void kjx_dj_power_on(void)
{
	DCL_HANDLE gpio_handle;

	gpio_handle = DclGPIO_Open(DCL_GPIO,DJ_POWER_PIN);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
	DclGPIO_Control(gpio_handle, GPIO_CMD_WRITE_HIGH, NULL);
	DclGPIO_Close(gpio_handle);
}

void kjx_dj_power_off(void)
{
	DCL_HANDLE gpio_handle;

	gpio_handle = DclGPIO_Open(DCL_GPIO,DJ_POWER_PIN);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
	DclGPIO_Control(gpio_handle, GPIO_CMD_WRITE_LOW, NULL);
	DclGPIO_Close(gpio_handle);

}

void kjx_dj_uart_switch_rfid(void)
{
	DCL_HANDLE gpio_handle;

	gpio_handle = DclGPIO_Open(DCL_GPIO,DJ_UART_SWITCH_PIN);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
	DclGPIO_Control(gpio_handle, GPIO_CMD_WRITE_LOW, NULL);
	DclGPIO_Close(gpio_handle);
}

void kjx_dj_uart_swtich_dj(void)
{
	DCL_HANDLE gpio_handle;

	gpio_handle = DclGPIO_Open(DCL_GPIO,DJ_UART_SWITCH_PIN);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
	DclGPIO_Control(gpio_handle, GPIO_CMD_WRITE_HIGH, NULL);
	DclGPIO_Close(gpio_handle);
}

void kjx_dj_init(void)
{
	DCL_HANDLE gpio_handle;

	gpio_handle = DclGPIO_Open(DCL_GPIO,DJ_CHECK_PIN);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_IN,NULL);
	DclGPIO_Close(gpio_handle);
	
	kjx_dj_uart_switch_rfid();
	kjx_dj_earphone_ctrl_to_rfid();
	kjx_dj_power_on();
	kjx_dj_check_start();
}

void kjx_dj_entry_fun(void)
{
	g_kjx_nvram_struct.rfidflag = 0;
	LOGD("1111111111111");
	g_kjx_current_dj_or_rfid_mode = 1;

	kjx_rfid_stop_play_audio();
	kjx_rfid_off();
	kjx_nvram_write();
	kjx_dj_uart_swtich_dj();
	kjx_dj_earphone_ctrl_to_dj();
	kjx_dj_uart_init(); 		
	//kjx_rfid_turn_on();
	//kjx_dj_get_current_mode();
	kjx_dj_get_vol();
	kjx_dj_get_current_chanle();
	kjx_dj_get_current_mode();
}

void kjx_dj_check_work(void)
{
	GPIO_CTRL_READ_T d_read;
	DCL_HANDLE gpio_handle;
	static U8 dj_exit_count = 0;
	
	gpio_handle = DclGPIO_Open(DCL_GPIO,DJ_CHECK_PIN);
	
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_IN,NULL);
	
	DclGPIO_Control(gpio_handle,GPIO_CMD_READ,(DCL_CTRL_DATA_T *)&d_read);
	DclGPIO_Close(gpio_handle);
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("d_read:%d,rfidflag=%d", d_read.u1IOData,g_kjx_nvram_struct.rfidflag);
	//kjx_dj_get_vol_lv(0);
#endif
	if(!d_read.u1IOData)
	{
		dj_exit_count++;
		if(dj_exit_count > 2)
		{
			dj_exit_count = 0;
			if(g_kjx_nvram_struct.rfidflag == 0)
			{
				g_kjx_nvram_struct.rfidflag = 1;
				LOGD("000000000000000");
				
				g_kjx_current_dj_or_rfid_mode = 0;
				//kjx_rfid_close();
				//kjx_rfid_turn_off();			
				kjx_dj_uart_switch_rfid();
				kjx_dj_earphone_ctrl_to_rfid();
				kjx_rfid_init();
				kjx_nvram_write();
			}
		}
	}
	else
	{
		dj_exit_count = 0;
		
		if(g_kjx_nvram_struct.rfidflag == 1)
		{
		/*
			g_kjx_nvram_struct.rfidflag = 0;
			LOGD("1111111111111");
			g_kjx_current_dj_or_rfid_mode = 1;
			kjx_rfid_off();
			kjx_nvram_write();
			kjx_dj_uart_swtich_dj();
			kjx_dj_earphone_ctrl_to_dj();
			kjx_dj_uart_init();			
			kjx_rfid_turn_on();
			kjx_dj_get_current_mode();
		*/
		kjx_dj_entry_fun();
		}
	}
	StopTimer(KJX_TIMER_ID_OBD_SEND);
	StartTimer(KJX_TIMER_ID_OBD_SEND, 3*1000, kjx_dj_check_work);
		
}


void kjx_dj_check_start(void)
{
	LOGD("kjx_dj_check_start");
	StartTimer(KJX_TIMER_ID_OBD_SEND, 10*1000, kjx_dj_check_work);
}


U8 kjx_dj_cmd_set_checksum(U8 *cmd_buff)
{
	U8 cmd_data_len = 0;
	U8 i = 0;
	U8 cmd_check_sum = 0;
	//Checksum = head + cmd + data_len + data + tail + 0x55 
	if(cmd_buff == NULL)
	{
		return;
	}
	cmd_check_sum = cmd_buff[0]+cmd_buff[1]+cmd_buff[2];
	cmd_data_len = cmd_buff[2];
	if(cmd_data_len>0)
	{
		for(i=0;i<cmd_data_len;i++)
		{
			cmd_check_sum+= cmd_buff[3+i];
		}
	}
	cmd_check_sum += 0xbb;
	cmd_check_sum += 0x55;

	cmd_buff[3+cmd_data_len] = cmd_check_sum;
	cmd_buff[3+cmd_data_len+1]= 0xbb;
	
#if 0//defined(__KJX_LOG_OUTPUT__)
	for(i=0;i<cmd_data_len+5;i++)
	{
		LOGD("cmd_buff:0x%02x",cmd_buff[i]);	
	}
#endif

	return  cmd_data_len+5;
}


U8 dj_cmd_data[128]={0};
void kjx_dj_get_current_mode(void)
{
	U8 cmd_len = 0;
	U16 cmd_send_rst = 0;
	
	dj_cmd_data[0] = 0x2a;	
	dj_cmd_data[1] = 0x05;	
	dj_cmd_data[2] = 0x01;	
	dj_cmd_data[3] = 0x00;
	
	cmd_len = kjx_dj_cmd_set_checksum(dj_cmd_data);
	cmd_send_rst = kjx_dj_uart_write(dj_cmd_data,cmd_len);
	
	LOGD("cmd_send_rst:%d",cmd_send_rst);	
}

void kjx_dj_set_current_mode(U8 mode)
{
	U8 cmd_len = 0;
	U16 cmd_send_rst = 0;
	
	dj_cmd_data[0] = 0x2a;	
	dj_cmd_data[1] = 0x06;	
	dj_cmd_data[2] = 0x01;	
	dj_cmd_data[3] = mode;	
	
	cmd_len = kjx_dj_cmd_set_checksum(dj_cmd_data);
	cmd_send_rst = kjx_dj_uart_write(dj_cmd_data,cmd_len);

	LOGD("cmd_send_rst:%d",cmd_send_rst);	
}

void kjx_dj_get_current_chanle(void)
{
	U8 cmd_len = 0;
	U16 cmd_send_rst = 0;
	
	dj_cmd_data[0] = 0x2a;
	dj_cmd_data[1] = 0x03;
	dj_cmd_data[2] = 0x01;
	dj_cmd_data[3] = 0x00;

	cmd_len = kjx_dj_cmd_set_checksum(dj_cmd_data);
	cmd_send_rst = kjx_dj_uart_write(dj_cmd_data,cmd_len);

	LOGD("cmd_send_rst:%d",cmd_send_rst);	
}

void kjx_dj_set_current_chanle(U8 index)
{
	U8 cmd_len = 0;
	U16 cmd_send_rst = 0;
	
	dj_cmd_data[0] = 0x2a;	
	dj_cmd_data[1] = 0x04;	
	dj_cmd_data[2] = 0x01;	
	dj_cmd_data[3] = index;	

	cmd_len = kjx_dj_cmd_set_checksum(dj_cmd_data);
	cmd_send_rst = kjx_dj_uart_write(dj_cmd_data,cmd_len);
	LOGD("cmd_send_rst:%d",cmd_send_rst);	
}

void kjx_dj_get_vol(void)
{
	U8 cmd_len = 0;
	U16 cmd_send_rst = 0;
	
	dj_cmd_data[0] = 0x2a;	
	dj_cmd_data[1] = 0x01;	
	dj_cmd_data[2] = 0x01;
	dj_cmd_data[3] = 0x00;

	cmd_len = kjx_dj_cmd_set_checksum(dj_cmd_data);
	cmd_send_rst = kjx_dj_uart_write(dj_cmd_data,cmd_len);

	LOGD("cmd_send_rst:%d",cmd_send_rst);	
}


void kjx_dj_set_vol(U8 lv)
{
	U8 cmd_len = 0;
	U16 cmd_send_rst = 0;

	dj_cmd_data[0] = 0x2a;	
	dj_cmd_data[1] = 0x02;	
	dj_cmd_data[2] = 0x01;	
	dj_cmd_data[3] = lv;	

	cmd_len = kjx_dj_cmd_set_checksum(dj_cmd_data);
	cmd_send_rst = kjx_dj_uart_write(dj_cmd_data,cmd_len);

	LOGD("cmd_send_rst:%d",cmd_send_rst);	
}

void kjx_dj_get_req(U8 *buff,U16 buff_len)
{
	//2a,03,01,02,40,bb,
	U8 cmd_id  = 0;

	LOGD("buff_len:%d, buff:%02X,%02X,%02X,%02X,%02X,%02X",buff_len, buff[0],buff[1],buff[2],buff[3],buff[4],buff[5]);
	if(buff_len == 6)
	{
		if((buff[0] == 0x2a)&&(buff[2] == 0x1))
		{
			switch(buff[1])
			{
			case 0x01://get volume response
				g_kjx_nvram_struct.dj_infor.dj_vol = buff[3];
				tmp_vol = g_kjx_nvram_struct.dj_infor.dj_vol;
				kjx_dj_show_tour_image();
				break;
			case 0x03://get chanle response
				g_kjx_nvram_struct.dj_infor.dj_chanle = buff[3];
				tmp_chanle = g_kjx_nvram_struct.dj_infor.dj_chanle;
				kjx_dj_get_vol();
				break;
			case 0x05://get mode response
				switch(buff[3])
				{
				case 4:
				case 5:
				case 6:
					g_kjx_nvram_struct.dj_infor.dj_mode = buff[3];//4:2A;5:2B;6:2C
					break;
				default:
					g_kjx_nvram_struct.dj_infor.dj_mode = 4;
					break;
				}
				tmp_mode = g_kjx_nvram_struct.dj_infor.dj_mode;
				kjx_dj_get_current_chanle();
				break;

			case 0x02://set volume response
				g_kjx_nvram_struct.dj_infor.dj_vol = tmp_vol;
				kjx_dj_show_tour_image();
				break;
				
			case 0x04://set chanle response
				g_kjx_nvram_struct.dj_infor.dj_chanle = tmp_chanle;
				kjx_dj_show_tour_image();
				break;
				
			case 0x06://set mode response
				g_kjx_nvram_struct.dj_infor.dj_mode = tmp_mode;
				kjx_dj_show_tour_image();
				break;
			}

			kjx_nvram_write();

			if(g_kjx_nvram_struct.dj_infor.dj_chanle > 0)
			{
				char tmpbuf[128] = {0};
				
				sprintf(tmpbuf, "Chanle:%02d", g_kjx_nvram_struct.dj_infor.dj_chanle);
				mmi_asc_to_ucs2((S8*)dj_chanle_show, (S8*)tmpbuf);
			}
		}
	}

}
static mmi_ret kjx_dj_main_submenu_proc(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{
	case EVT_ID_GROUP_ENTER:
		tmp_vol = g_kjx_nvram_struct.dj_infor.dj_vol;
		tmp_chanle = g_kjx_nvram_struct.dj_infor.dj_chanle;
		tmp_mode = g_kjx_nvram_struct.dj_infor.dj_mode;
		break;
	case EVT_ID_GROUP_ACTIVE:
	case EVT_ID_GROUP_INACTIVE:
	case EVT_ID_GROUP_DEINIT:
		break;
		
	default:
		break;
	}
	
	return MMI_RET_OK;
}

static void kjx_dj_exit_kjx_image_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("exit");
#endif
#endif
	
	g_kjx_dj_group_id = GRP_ID_INVALID;
}

void kjx_dj_show_tour_image(void)
{
	GDI_RESULT result = GDI_FAILED;
	S32 x=0,y=0,w=UI_DEVICE_WIDTH,h=UI_DEVICE_HEIGHT;
	S32 img_w, img_h;
	char tmpbuf[128] = {0}, strbuf[128] = {0};
	CHAR filename[128] = {0};

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("chanle_data:%d", tmp_vol);
#endif
#endif

	if(g_kjx_dj_group_id != GRP_ID_INVALID)
	{
		gdi_layer_push_clip();
	    gdi_layer_set_clip(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT);
		gdi_draw_solid_rect(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT, GDI_COLOR_BLACK);

		gui_set_text_color(gui_color(255, 255, 255));
		//gui_move_text_cursor(2, UI_device_height/2);
	
		//mode
		sprintf((S8*)tmpbuf, "mode:%02X", (0x2a+(tmp_mode-4)));
		mmi_asc_to_ucs2((S8*) strbuf, tmpbuf);
		gui_move_text_cursor(2, 25);
		gui_print_text((UI_string_type)strbuf);
		//chanle
		sprintf((S8*)tmpbuf, "chanle:%02d", tmp_chanle);
		mmi_asc_to_ucs2((S8*) strbuf, tmpbuf);
		gui_move_text_cursor(2, 50);
		gui_print_text((UI_string_type)strbuf);
		//volume
		sprintf((S8*)tmpbuf, "vol:%02d", tmp_vol);
		mmi_asc_to_ucs2((S8*) strbuf, tmpbuf);
		gui_move_text_cursor(2, 75);
		gui_print_text((UI_string_type)strbuf);
		
		gdi_layer_pop_clip();

		gui_BLT_double_buffer(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT);
	}
}

void kjx_dj_mode_up(void)
{
	tmp_mode++;
	if(tmp_mode > 6)
		tmp_mode = 4;
	
	kjx_dj_set_current_mode((U8)tmp_mode);
}
void kjx_dj_mode_down(void)
{
	tmp_mode--;
	if(tmp_mode < 4)
		tmp_mode = 6;
	
	kjx_dj_set_current_mode((U8)tmp_mode);
}

void kjx_dj_chanle_up(void)
{
	tmp_chanle++;
	if(tmp_chanle > 36)
		tmp_chanle = 1;
	
	kjx_dj_set_current_chanle((U8)tmp_chanle);
}
void kjx_dj_chanle_down(void)
{
	tmp_chanle--;
	if(tmp_chanle <= 0)
		tmp_chanle = 36;
	
	kjx_dj_set_current_chanle((U8)tmp_chanle);
}

void kjx_dj_vol_up(void)
{
	tmp_vol++;
	if(tmp_vol > 9)
		tmp_vol = 9;
	
	kjx_dj_set_vol((U8)tmp_vol);
}
void kjx_dj_vol_down(void)
{
	tmp_vol--;
	if(tmp_vol <= 0)
		tmp_vol = 0;
	
	kjx_dj_set_vol((U8)tmp_vol);
}

void kjx_dj_entry_kjx_image_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[MAX_SUB_MENUS];
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_scrn_enter(
			g_kjx_dj_group_id, 
			SCR_ID_KJX_IMAGE, 
			kjx_dj_exit_kjx_image_screen, 
			kjx_dj_entry_kjx_image_screen, 
			MMI_FRM_FULL_SCRN
			);

	kjx_dj_show_tour_image();
	
	kjx_dj_entry_fun();//bwl202010111619
	StopTimer(KJX_TIMER_ID_OBD_SEND);//bwl202010111619
	
	SetDefaultVolumeKeyHandlers();
	SetKeyHandler(kjx_dj_vol_up, KEY_VOL_UP, KEY_EVENT_DOWN);
	SetKeyHandler(kjx_dj_vol_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);
	SetKeyHandler(kjx_dj_chanle_up, KEY_UP_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(kjx_dj_chanle_down, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(kjx_dj_mode_down, KEY_CAMERA, KEY_EVENT_DOWN);

    SetKeyHandler(kjx_dj_exit_tour_image, KEY_RSK, KEY_EVENT_UP);
}

void kjx_dj_exit_tour_image(void)
{
	MMI_ID group_id,scrn_id;

	
	mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_kjx_dj_group_id:%d, group_id:%d, SCR_KEY_TONE_VOLUME:%d, SCR_ID_KJX_IMAGE:%d,scrn_id:%d", g_kjx_dj_group_id, group_id, SCR_KEY_TONE_VOLUME, SCR_ID_KJX_IMAGE, scrn_id);
#endif
#endif
	mmi_frm_scrn_close_active_id();
	kjx_dj_check_work();
}

void kjx_dj_main_show_tour_image(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8 i;
	char tmpbuf[128] = {0}, strbuf[128] = {0};
	CHAR filename[128] = {0};
	FS_HANDLE handle;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
	g_kjx_dj_group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, kjx_dj_main_submenu_proc, NULL);
	mmi_frm_group_enter(g_kjx_dj_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	kjx_dj_entry_kjx_image_screen();

}
#endif/*__KJX_DJ_SUPPORT__*/

void kjx_func_main_tour(void)
{
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_gps_init:%d, g_rfid_init:%d", g_gps_init, g_rfid_init);
#endif
#endif

	kjx_get_imei();

	/*读取配置文件*/
	kjx_system_init();
	
#if defined(__KJX_FUN_GPS__)
	/*开启GPS*/
	if(g_gps_init == 0)
	{
		g_gps_init = 1;
		kjx_gps_main();

		/*更新GPS状态图标*/
		wgui_status_icon_bar_reset_icon_display(STATUS_ICON_GPS_OFF);
		wgui_status_icon_bar_set_icon_display(STATUS_ICON_GPS_ON);
		wgui_status_icon_bar_update();
	}
#endif

	/*SOCLET 联网*/
	kjx_socket_main();
 
	/*函数初始化*/
	kjx_tour_func_init();

	/*开启蓝牙*/
#ifdef __BLE_MODULE_SUPPORT__
	if(g_kjx_nvram_struct.btflag == 1)
	{
		StartTimer(KJX_TIMER_ID_OBD_SEND, 2*1000, kjx_bt_ibeacon_init);
	}
	else
	{
		StartTimer(KJX_TIMER_ID_OBD_SEND, 2*1000, kjx_bt_ibeacon_off);
	}
#endif

	kjx_dj_init();


	/*开启RFID*/
#if defined(__KJX_RFID__)
	if(g_kjx_nvram_struct.rfidflag == 1)
	{
		StartTimer(KJX_TIMER_ID_RFID_EINT_INIT, 5*1000, kjx_rfid_init);
	}
	else
	{
		StartTimer(KJX_TIMER_ID_RFID_EINT_INIT, 5*1000, kjx_rfid_off);
	}
#endif
}

void kjx_factory_auto_test_start(void)
{
	EntryFMMenuAutoTest();
}

void kjx_factory_test_start(void)
{
#if !defined(__KJX_FUN_SENSOR__)
    char playString[]={0x09,0x63,0x11,0x54,0x0a,0x4e,0x2e,0x95,0xdb,0x8f,0x65,0x51,0x4b,0x6d,0xd5,0x8b,0x21,0x6a,0x0f,0x5f,0x09,0x63,0x11,0x54,0x0b,0x4e,0x2e,0x95,0xe8,0x62,0x53,0x62,0x35,0x75,0xdd,0x8b,0x0,0x0};
#endif

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

#if 1
	g_kjx_enter_factory_test = 1;
	EntryFMMenu();
#else
    g_kjx_enter_factory_test = 1;

	g_start_rfid = 0;
	myID = 0;
	rfid_field_index = 0;
	memset(rfid_field_count, 0xff, sizeof(rfid_field_count));
	
	kjx_rfid_stop_play_audio();
	if(IsMyTimerExist(KJX_TIMER_ID_RFID_CHECK))
		StopTimer(KJX_TIMER_ID_RFID_CHECK);

#if defined(__KJX_FUN_SENSOR__)
    kjx_factory_g_sensor_test();
#else
  #if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
  #endif
    g_test_start = 1;
	g_test_led = 0;
#endif

	kjx_tour_battery_status_led(BATTERY_ALL_OFF);

	if(g_gps_init == 0)
	{
		g_gps_init = 1;
		kjx_gps_main();
	}

	if(IsMyTimerExist(KJX_TIMER_ID_GPS_CLOSE))
		StopTimer(KJX_TIMER_ID_GPS_CLOSE);
	
    kjx_open_gps();

	memset(kjx_scrolling_show, 0, sizeof(kjx_scrolling_show));
	mmi_show_scrolling_infor();	
#endif
}

int kjx_get_foctory_test_mode(void)
{
#if 0	//def MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_kjx_enter_factory_test:%d", g_kjx_enter_factory_test);
#endif
#endif

    return g_kjx_enter_factory_test;
}

void kjx_foctory_test_end(void)
{
    //测试完成
    char playString[]={0x4b,0x6d,0xd5,0x8b,0x8c,0x5b,0x10,0x62,0x0,0x0};

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

    g_kjx_enter_factory_test = 0;
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
	
    StartTimer(KJX_TIMER_ID_FACTORY_TEST, 5*1000, power_off);
}

int kjx_test_get_call_flag(void)
{
    return g_test_call112;
}

void kjx_test_mode_call_112(void)
{
	S8 mynuber[] = {"112"};
	U8 ucs_nuber[41];

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("mynuber:%s", mynuber); 
#endif
#endif

	memset(ucs_nuber,0,sizeof(ucs_nuber));
	mmi_asc_to_ucs2((S8*)ucs_nuber,(S8*)mynuber);
	MakeCall((S8*)ucs_nuber);
    g_test_start = 0;
    g_test_call112 = 1;
    kjx_tour_gsm_led(LED_OFF);
    kjx_tour_gps_led(LED_OFF);
}

int kjx_get_test_start(void)
{
    return g_test_start;
}

#if defined(__KJX_FUN_SENSOR__)
void kjx_factory_g_sensor_test_end(int result)
{
    char playString[]={0x09,0x63,0x11,0x54,0x0a,0x4e,0x2e,0x95,0xdb,0x8f,0x65,0x51,0x4b,0x6d,0xd5,0x8b,0x21,0x6a,0x0f,0x5f,0x09,0x63,0x11,0x54,0x0b,0x4e,0x2e,0x95,0xe8,0x62,0x53,0x62,0x35,0x75,0xdd,0x8b,0x0,0x0};
    //kjx_factory_enter_key_test();
#if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
#endif
    g_test_start = 1;
	g_test_led = 0;
}

void kjx_factory_g_sensor_test(void)
{
    //g-sensor 开始测试
    char playString[]={0x00,0x5f,0xcb,0x59,0x4b,0x6d,0xd5,0x8b,0x0,0x0};

#if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
#endif

    g_kjx_sensor_func.sensor_func_init = kjx_sensor_func_init_tour;
    StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*2, kjx_sensor_main);
}
#endif

#include "mmi_rp_app_mainmenu_def.h"

static U8 kjx_screen_test_count = 0;
static mmi_id kjx_screen_test_group_id = GRP_ID_INVALID;

void kjx_show_test_screen(void);

void kjx_factory_screen_test_end(void)
{
	//屏幕测试成功
	char playString[]={0x4F,0x5C,0x55,0x5E,0x4B,0x6D,0xD5,0x8B,0x10,0x62,0x9F,0x52,0x00,0x00};
	
#if defined(__NPR_TTS__)
	if(mmi_ucs2strlen((const CHAR *)playString)>0)
	{
		Npr_Tts_play_stop();
		Npr_Ttsplayer_playtextw(playString,NULL);  
	}
#endif

	g_start_screen = 0;

	StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*2, kjx_factory_led_test);
}

static mmi_ret mmi_main_test_screen_proc(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{
	case EVT_ID_GROUP_ACTIVE:
	case EVT_ID_GROUP_INACTIVE:
	case EVT_ID_GROUP_DEINIT:
		break;
		
	default:
		break;
	}
	
	return MMI_RET_OK;
}

static void mmi_exit_kjx_test_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kjx_screen_test_count = 0;
	kjx_screen_test_group_id = GRP_ID_INVALID;
}

void mmi_show_test_screen(void)
{
	GDI_RESULT result = GDI_FAILED;
	S32 x=0,y=0,w=UI_DEVICE_WIDTH,h=UI_DEVICE_HEIGHT;
	S32 img_w, img_h;
	char tmpbuf[128] = {0}, strbuf[128] = {0};
	CHAR filename[128] = {0};
	color red_color = {255, 0, 0, 0};
	color green_color = {0, 255, 0, 0};
	color blue_color = {0, 0, 255, 0};	

	kjx_screen_test_count++;
	if(kjx_screen_test_count > 3)
	{
		GoBackHistory();
		kjx_factory_screen_test_end();
	}
	else
	{
		switch(kjx_screen_test_count)
		{
		case 1:
			mmi_fm_set_show_color(255, 0, 0);
			break;
		case 2:
			mmi_fm_set_show_color(0, 255, 0);
			break;
		case 3:
			mmi_fm_set_show_color(0, 0, 255);
			break;
		}
	
		StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*2, kjx_show_test_screen);
	}
}

void mmi_entry_kjx_test_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[MAX_SUB_MENUS];
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_scrn_enter(kjx_screen_test_group_id, SCR_ID_KJX_SCREEN_TEST, mmi_exit_kjx_test_screen, mmi_entry_kjx_test_screen, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }

	mmi_show_test_screen();
}

void kjx_show_test_screen(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	char tmpbuf[128] = {0}, strbuf[128] = {0};
	CHAR filename[128] = {0};
	FS_HANDLE handle;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifdef RFID_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_kjx_image_group_id:%d", kjx_screen_test_group_id);
#endif
#endif

	if(kjx_screen_test_group_id == GRP_ID_INVALID)
	{
		kjx_screen_test_group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_main_test_screen_proc, NULL);
		mmi_frm_group_enter(kjx_screen_test_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
		mmi_entry_kjx_test_screen();
	}
	else
	{
		mmi_show_test_screen();
	}
}

void kjx_factory_enter_screen_test(void)
{
	//进入屏幕测试
	char playString[]={0xDB,0x8F,0x65,0x51,0x4F,0x5C,0x55,0x5E,0x4B,0x6D,0xD5,0x8B,0x00,0x00};
	
#if defined(__NPR_TTS__)
	if(mmi_ucs2strlen((const CHAR *)playString)>0)
	{
		Npr_Tts_play_stop();
		Npr_Ttsplayer_playtextw(playString,NULL);  
	}
#endif

	g_start_screen = 1;

#if defined(__KJX_OLED_64_48_UI__)
	memset(kjx_scrolling_show, 0, sizeof(kjx_scrolling_show));
	mmi_show_scrolling_infor();
	mmi_redraw_idlescreen();
#endif/*__KJX_OLED_64_48_UI__*/

	kjx_show_test_screen();
}

void kjx_factory_enter_key_test(void)
{
    //进入按键测试
    char playString[]={0xdb,0x8f,0x65,0x51,0x9,0x63,0x2e,0x95,0x4b,0x6d,0xd5,0x8b,0x0,0x0};
    kjx_tour_gsm_led(LED_OFF);
    kjx_tour_charge_led(LED_OFF);
    kjx_tour_gps_led(LED_OFF);
#if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
#endif
    g_enter_key_test = 1;
    g_test_start = 0;
}

void kjx_factory_key_test(U8 keycode, U8 keytype)
{
    static int i=0,j=0,k=0,l=0,m=0,n=0,o=0,p=0,q=0,r=0,t=0;

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_kjx_enter_factory_test:%d, keytype:%d, g_enter_key_test:%d", g_kjx_enter_factory_test, keytype, g_enter_key_test); 
#endif
#endif

    if (g_kjx_enter_factory_test == 1 && keytype == 1 && g_enter_key_test == 1)
    {
        if (keycode == KEY_CAMERA)
        {
        	//紧急拨号键
            char playString[]={0x27,0x7D,0x25,0x60,0xE8,0x62,0xF7,0x53,0x2E,0x95,0x0,0x0};
		#if defined(__NPR_TTS__)
            if(mmi_ucs2strlen((const CHAR *)playString)>0)
            {
                Npr_Tts_play_stop();
                Npr_Ttsplayer_playtextw(playString,NULL);  
            }
		#endif
            i=1;
        }
        else if (keycode == KEY_VOL_UP)
        {
        	//音量加键
            char playString[]={0xF3,0x97,0xCF,0x91,0xA0,0x52,0x2E,0x95,0x0,0x0};

		#if defined(__NPR_TTS__)
            if(mmi_ucs2strlen((const CHAR *)playString)>0)
            {
                Npr_Tts_play_stop();
                Npr_Ttsplayer_playtextw(playString,NULL);  
            }
		#endif
		
            j=1;
        }
        else if (keycode == KEY_VOL_DOWN)
        {
        	//音量减键
            char playString[]={0xF3,0x97,0xCF,0x91,0xCF,0x51,0x2E,0x95,0x0,0x0};

		#if defined(__NPR_TTS__)
            if(mmi_ucs2strlen((const CHAR *)playString)>0)
            {
                Npr_Tts_play_stop();
                Npr_Ttsplayer_playtextw(playString,NULL);  
            }
		#endif
            k=1;
        }
        else if (keycode == KEY_END)
        {
        	//开关机键
            char playString[]={0x00,0x5F,0x73,0x51,0x3A,0x67,0x2E,0x95,0x0,0x0};

		#if defined(__NPR_TTS__)
            if(mmi_ucs2strlen((const CHAR *)playString)>0)
            {
                Npr_Tts_play_stop();
                Npr_Ttsplayer_playtextw(playString,NULL);  
            }
		#endif
            l=1;
        }
		else if (keycode == KEY_STAR)
        {
        	//语言切换键
            char playString[]={0xED,0x8B,0x00,0x8A,0x07,0x52,0x62,0x63,0x2E,0x95,0x0,0x0};

		#if defined(__NPR_TTS__)
            if(mmi_ucs2strlen((const CHAR *)playString)>0)
            {
                Npr_Tts_play_stop();
                Npr_Ttsplayer_playtextw(playString,NULL);  
            }
		#endif
            m=1;
        }
		else if (keycode == KEY_UP_ARROW)
        {
        	//上方向键
            char playString[]={0x0A,0x4E,0xB9,0x65,0x11,0x54,0x2E,0x95,0x0,0x0};

		#if defined(__NPR_TTS__)
            if(mmi_ucs2strlen((const CHAR *)playString)>0)
            {
                Npr_Tts_play_stop();
                Npr_Ttsplayer_playtextw(playString,NULL);  
            }
		#endif
            n=1;
        }
		else if (keycode == KEY_DOWN_ARROW)
        {
        	//下方向键
            char playString[]={0x0B,0x4E,0xB9,0x65,0x11,0x54,0x2E,0x95,0x0,0x0};

		#if defined(__NPR_TTS__)
            if(mmi_ucs2strlen((const CHAR *)playString)>0)
            {
                Npr_Tts_play_stop();
                Npr_Ttsplayer_playtextw(playString,NULL);  
            }
		#endif
            o=1;
        }
		else if (keycode == KEY_LSK)
        {
        	//确认键
            char playString[]={0x6E,0x78,0xA4,0x8B,0x2E,0x95,0x0,0x0};

		#if defined(__NPR_TTS__)
            if(mmi_ucs2strlen((const CHAR *)playString)>0)
            {
                Npr_Tts_play_stop();
                Npr_Ttsplayer_playtextw(playString,NULL);  
            }
		#endif
            p=1;
        }
		else if (keycode == KEY_RSK)
        {
        	//返回键
            char playString[]={0xD4,0x8F,0xDE,0x56,0x2E,0x95,0x0,0x0};

		#if defined(__NPR_TTS__)
            if(mmi_ucs2strlen((const CHAR *)playString)>0)
            {
                Npr_Tts_play_stop();
                Npr_Ttsplayer_playtextw(playString,NULL);  
            }
		#endif
            q=1;
        }
		else if (keycode == KEY_CSK)
        {
        	//播放键
            char playString[]={0xAD,0x64,0x3E,0x65,0x2E,0x95,0x0,0x0};

		#if defined(__NPR_TTS__)
            if(mmi_ucs2strlen((const CHAR *)playString)>0)
            {
                Npr_Tts_play_stop();
                Npr_Ttsplayer_playtextw(playString,NULL);  
            }
		#endif
            r=1;
        }		
    }
    if (i==1&&j==1&&k==1&&l==1&&m==1&&n==1&&o==1&&p==1&&q==1&&r==1)
    {
        //按键测试成功
        char playString[]={0x9,0x63,0x2e,0x95,0x4b,0x6d,0xd5,0x8b,0x10,0x62,0x9f,0x52,0x0,0x0};
	#if defined(__NPR_TTS__)
        if(mmi_ucs2strlen((const CHAR *)playString)>0)
        {
            Npr_Tts_play_stop();
            Npr_Ttsplayer_playtextw(playString,NULL);  
        }
	#endif
		
        StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*2, kjx_factory_enter_screen_test);
        g_enter_key_test = 0;
        i = 0;
    }
}


void kjx_factory_gps_end(void)
{
    //gps 测试成功
    char playString[]={0x47,0x0,0x50,0x0,0x53,0x0,0x4b,0x6d,0xd5,0x8b,0x10,0x62,0x9f,0x52,0x0,0x0};

#if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
#endif

#ifdef __KJX_FUN_GPS__
	kjx_close_gps();
#endif

    g_start_gps = 0;

	StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*2,kjx_factory_charge_test);
}

void kjx_factory_gps_test_start(void)
{
    g_start_gps = 1;  

	if(IsMyTimerExist(KJX_TIMER_ID_GPS_CLOSE))
		StopTimer(KJX_TIMER_ID_GPS_CLOSE);

	kjx_open_gps();	
}

void kjx_factory_gps_test(void)
{
    //gps 测试开始
    char playString[]={0x47,0x0,0x50,0x0,0x53,0x0,0x4b,0x6d,0xd5,0x8b,0x0,0x5f,0xcb,0x59,0x0,0x0};

	kjx_tour_gps_led(LED_FAST);
    srv_vibrator_off();
#if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
#endif
    StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*2,kjx_factory_gps_test_start);
}

int kjx_get_test_mode_gps_start(void)
{
    return g_start_gps;
}

void kjx_factory_gprs_test(void)
{
    //gps 测试成功
    char playString[]={0x51,0x7f,0xdc,0x7e,0xde,0x8f,0xa5,0x63,0x10,0x62,0x9f,0x52,0x0,0x0};
    srv_vibrator_off();
    kjx_tour_gps_led(LED_ON);
#if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
#endif
    
}

#if defined(__KJX_BAT_STATUS_LED_SHOW__)
void kjx_factory_gsm_led_test(void)
{
	//信号灯测试成功
	char playString[]={0xE1,0x4F,0xF7,0x53,0x6F,0x70,0x4B,0x6D,0xD5,0x8B,0x10,0x62,0x9F,0x52,0x00,0x00};

    static int i = 0;

	kjx_tour_battery_status_led(BATTERY_ALL_OFF);
	
    i++;
    if (i > 2)
    {
    	g_test_led = 1;//LED测试成功

	#if defined(__NPR_TTS__)
	    if(mmi_ucs2strlen((const CHAR *)playString)>0)
	    {
	        Npr_Tts_play_stop();
	        Npr_Ttsplayer_playtextw(playString,NULL);  
	    }
	#endif
	
        StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*2, kjx_factory_mic_test_start);
    }
    else
    {
		if(i == 1)
		{
			kjx_tour_battery_status_led(BATTERY_TURN_ON_RED);
		}
		else
		{
			kjx_tour_battery_status_led(BATTERY_TURN_ON_GREEN);
		}
		
        StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*2, kjx_factory_gsm_led_test);
    }
}

void kjx_factory_led_test(void)
{
    //信号灯测试开始
    char playString[]={0xE1,0x4F,0xF7,0x53,0x6F,0x70,0x4B,0x6D,0xD5,0x8B,0x00,0x5F,0xCB,0x59,0x00,0x00};
	
#if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
#endif

    kjx_factory_gsm_led_test();
}
#endif

void kjx_factory_vib_test(void)
{
    //马达测试开始
    char playString[]={0x6c,0x9a,0xbe,0x8f,0x4b,0x6d,0xd5,0x8b,0x0,0x5f,0xcb,0x59,0x0,0x0};

#if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
#endif

    srv_vibrator_on();

#ifdef __BLE_MODULE_SUPPORT__
	StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*2, kjx_factory_ble_test);
#elif __KJX_RFID__
    StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*2, kjx_factory_rfid_test);
#else
    StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*2,kjx_factory_call_test_start);
#endif	
}

void kjx_factory_mic_test_end(void)
{
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin"); 
#endif
#endif
	FM_SendSetAudioModeReq(AUD_MODE_LOUDSPK);
	/* open loopback */
	kal_sleep_task(kal_milli_secs_to_ticks(200));
	L1SP_SetOutputVolume(200,0);
	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

	aud_util_proc_in_med(MOD_MMI, mmi_fm_set_loopback, 0, NULL);
	StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*2,kjx_factory_earphone_test_start);
}


void kjx_factory_mic_test(void)
{
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin"); 
#endif
#endif
	FM_SendSetAudioModeReq(AUD_MODE_LOUDSPK);
	/* open loopback */
	kal_sleep_task(kal_milli_secs_to_ticks(200));
	L1SP_SetOutputVolume(200,0);
	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

	aud_util_proc_in_med(MOD_MMI, mmi_fm_set_loopback, 1, NULL);
	StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*5,kjx_factory_mic_test_end);
}

void kjx_factory_mic_test_start(void)
{
    //麦克风测试开始
    char playString[]={0xa6,0x9e,0x4b,0x51,0xce,0x98,0x4b,0x6d,0xd5,0x8b,0x0,0x5f,0xcb,0x59,0x0,0x0};
    kjx_tour_gsm_led(LED_OFF);
    kjx_tour_gps_led(LED_OFF);
    kjx_tour_charge_led(LED_OFF);
#if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
#endif
    StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*2,kjx_factory_mic_test);
}

void kjx_factory_earphone_test_end(void)
{
    //耳机测试成功
    char playString[]={0x33,0x80,0x3a,0x67,0x4b,0x6d,0xd5,0x8b,0x10,0x62,0x9f,0x52,0x0,0x0};
#if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
#endif

	StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*2,kjx_factory_gps_test);
}


void kjx_factory_earphone_plugout(void)
{
    //拔出耳机
    char playString[]={0xd4,0x62,0xfa,0x51,0x33,0x80,0x3a,0x67,0x0,0x0};
#if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
#endif
    StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*2,kjx_factory_earphone_test_end);
    g_start_earphone = 3;
}

void kjx_factory_earphone_plugin(void)
{
    //插入耳机
    char playString[]={0xd2,0x63,0x65,0x51,0x33,0x80,0x3a,0x67,0x0,0x0};
#if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
#endif
    g_start_earphone = 2;
}

int kjx_get_test_mode_charge(void)
{
    return g_start_charge;
}

int kjx_get_test_mode_earphone(void)
{
    return g_start_earphone;
}

void kjx_factory_earphone_test_start(void)
{
    //耳机 测试开始
    char playString[]={0x33,0x80,0x3a,0x67,0x4b,0x6d,0xd5,0x8b,0x0,0x5f,0xcb,0x59,0x0,0x0};
#if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
#endif
    g_start_earphone = 1;
}

void kjx_factory_charge_test_end(void)
{
    //充电测试成功
    char playString[]={0x45,0x51,0x35,0x75,0x4b,0x6d,0xd5,0x8b,0x10,0x62,0x9f,0x52,0x0,0x0};
#if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
#endif
    StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*2,kjx_factory_vib_test);
    g_start_charge = 0;
}

void kjx_factory_charge_test(void)
{
    //充电测试开始
    char playString[]={0x45,0x51,0x35,0x75,0x4b,0x6d,0xd5,0x8b,0x0,0x5f,0xcb,0x59,0xf7,0x8b,0xd2,0x63,0x65,0x51,0x45,0x51,0x35,0x75,0x68,0x56,0x0,0x0};
#if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
#endif
    g_start_charge = 1;
}

void kjx_factory_call_test(void)
{
    S8 mynuber[] = {"10086"};
    U8 ucs_nuber[41];
	static U8 i = 0;
	
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin"); 
#endif
#endif

    memset(ucs_nuber,0,sizeof(ucs_nuber));
    mmi_asc_to_ucs2((S8*)ucs_nuber,(S8*)mynuber);
    MakeCall((S8*)ucs_nuber);

	//xb add 2017-06-16 防止信号不好的时候只拨一次就断了
	i++;
	if(i < 3)
	{
		StartTimer(KJX_TIMER_ID_FACTORY_TEST, 10*1000, kjx_factory_call_test);
	}
}

void kjx_factory_call_test_end(void)
{
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin"); 
#endif
#endif

    mmi_ucm_in_call_endkey();
	srv_speech_disable_hand_free();

	g_kjx_enter_factory_test = 0;
	
#if 0	//xb add 2017-08-28 测试完之后不要关机
    StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*5, power_off);
#endif
}

void kjx_factory_call_test_start(void)
{
    //通话 测试开始
    char playString[]={0x1a,0x90,0xdd,0x8b,0x4b,0x6d,0xd5,0x8b,0x0,0x5f,0xcb,0x59,0x0,0x0};

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin"); 
#endif
#endif

	srv_vibrator_off();

	memset(kjx_scrolling_show, 0, sizeof(kjx_scrolling_show));
	mmi_show_scrolling_infor();

#if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
#endif

    StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*3, kjx_factory_call_test);
}

#ifdef __BOSCH_BMP280_PRESSURE__
void kjx_start_pressure_test(void)
{
	g_start_pressure = 1;

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	BOSCH_BMP280_sensor_init();
}

void kjx_factory_pressure_test(void)
{
    //气压传感器测试开始
    char playString[]={0x14,0x6C,0x8B,0x53,0x20,0x4F,0x1F,0x61,0x68,0x56,0x4B,0x6D,0xD5,0x8B,0x00,0x5F,0xCB,0x59,0x0,0x0};

	srv_vibrator_off();
	
#if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
#endif

    StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*3, kjx_start_pressure_test);
}

void kjx_factory_pressure_test_end(void)
{
	//气压传感器测试成功
    char playString[]={0x14,0x6C,0x8B,0x53,0x20,0x4F,0x1F,0x61,0x68,0x56,0x4B,0x6D,0xD5,0x8B,0x10,0x62,0x9F,0x52,0x00,0x00};

	g_start_pressure = 0;

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

#if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
#endif

#ifdef __KJX_RFID__
	StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*2, kjx_factory_rfid_test);
#else
	StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*2, kjx_factory_call_test_start);
#endif
}

#endif

#ifdef __BLE_MODULE_SUPPORT__
void kjx_start_ble_test(void)
{
	g_start_ble = 1;
	myID = 0;

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_start_ble:%d", g_start_ble);
#endif
#endif

	if(g_kjx_ble_is_on == 0)
	{
		g_kjx_ble_is_on = 1;
		
		kjx_bt_ibeacon_init();
	}
}

void kjx_factory_ble_test(void)
{
    //蓝牙测试开始
    char playString[]={0xDD,0x84,0x59,0x72,0x4B,0x6D,0xD5,0x8B,0x00,0x5F,0xCB,0x59,0x0,0x0};

	srv_vibrator_off();
	
#if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
#endif

    StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*1,kjx_start_ble_test);
}

void kjx_factory_ble_test_end(void)
{
	//蓝牙测试成功
    char playString[]={0xDD,0x84,0x59,0x72,0x4B,0x6D,0xD5,0x8B,0x10,0x62,0x9F,0x52,0x00,0x00};//rfid 测试成功
	char tmpbuf[10] = {0};
	char strbuf[10] = {0};
	U32 i,j=0,value=0,total = 0;

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	if(g_kjx_nvram_struct.btflag == 0)
	{
		StartTimer(KJX_TIMER_ID_OBD_SEND, 2*1000, kjx_bt_ibeacon_off);
	}
	
	g_start_ble = 0;
	mdi_audio_stop_file();

#if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
#endif

#ifdef __BOSCH_BMP280_PRESSURE__
	StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*2, kjx_factory_pressure_test);
#elif __KJX_RFID__
	StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*2, kjx_factory_rfid_test);
#else
	StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*2, kjx_factory_call_test_start);
#endif
}
#endif

#ifdef __KJX_RFID__
void kjx_start_rfid_test(void)
{
	g_start_rfid = 1;
	myID = 0;

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_start_rfid:%d", g_start_rfid);
#endif
#endif

#if defined(__KJX_RFID__)
	if(g_rfid_init == 0)
	{
		g_rfid_init = 1;
		
	    kjx_rfid_eint_init();
	    kjx_rfid_main();
		kjx_rfid_turn_on();
	}
#endif
}

void kjx_factory_rfid_test(void)
{
    //rfid 测试开始
    char playString[]={0x52,0x0,0x46,0x0,0x49,0x0,0x44,0x0,0x4b,0x6d,0xd5,0x8b,0x0,0x5f,0xcb,0x59,0x0,0x0};

	srv_vibrator_off();
#if defined(__NPR_TTS__)
    if(mmi_ucs2strlen((const CHAR *)playString)>0)
    {
        Npr_Tts_play_stop();
        Npr_Ttsplayer_playtextw(playString,NULL);  
    }
#endif
    StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*1, kjx_start_rfid_test);
}

void kjx_factory_rfid_test_end(void)
{
    char playString[]={0x52,0x00,0x46,0x00,0x49,0x00,0x44,0x00,0x4B,0x6D,0xD5,0x8B,0x10,0x62,0x9F,0x52,0x00,0x00};//rfid 测试成功
    char playokString[]={0x52,0x00,0x46,0x00,0x49,0x00,0x44,0x00,0x4B,0x6D,0xD5,0x8B,0x10,0x62,0x9F,0x52,0x0C,0xFF,0x3A,0x57,0x3A,0x5F,0xA6,0x5E,0x3C,0x50,0x2F,0x66,0x00,0x00};//rfid 测试成功，场强度值是
	char playfailString[]={0x52,0x00,0x46,0x00,0x49,0x00,0x44,0x00,0x4B,0x6D,0xD5,0x8B,0x00,0x4E,0xF4,0x81,0x27,0x60,0x31,0x59,0x25,0x8D,0x00,0x00};//RFID测试一致性失败
	U16 rfidnwString[] = {0x4FE1,0x53F7,0x503C,0x003A,0x0000};
	char tmpbuf[10] = {0};
	char strbuf[10] = {0};
	U32 i,j=0,value=0,total = 0;
	srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
	srv_clog_si_tbl_struct *si_tbl;

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	g_start_rfid = 0;
	mdi_audio_stop_file();

#if 0	//xb add 2017-10-30 已经加上载波测试，不再需要判断场强度值
	si_tbl = cntx->comp->si_tbl;
	if(srv_clog_si_total_num(si_tbl) == 0)	//xb add 2016-12-07 根据生产测试流程由是否有通话记录判断是否需要检测场信号值
	{
		for(i=0;i<sizeof(rfid_field_count);i++)
		{
			if(rfid_field_count[i] != 0xff)
			{
				total += rfid_field_count[i];
				j++;
			}
		}
		
		value = total/j;
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("total:%d, j:%d, value:%d", total, j, value);
	#endif
	#endif

		sprintf(tmpbuf, "%d", value);
		mmi_asc_to_wcs((WCHAR*)strbuf, (CHAR*)tmpbuf);

		memset(kjx_scrolling_show, 0, sizeof(kjx_scrolling_show));
		mmi_ucs2cpy((CHAR*)kjx_scrolling_show, (CHAR*)rfidnwString);
		mmi_ucs2cat((CHAR*)kjx_scrolling_show, (CHAR*)strbuf);
		mmi_show_scrolling_infor();
		
		if(value <= 3)
		{
			mmi_ucs2cat((CHAR*)playokString, (CHAR*)strbuf);
		#if defined(__NPR_TTS__)
		    if(mmi_ucs2strlen((const CHAR *)playokString)>0)
		    {
		        Npr_Tts_play_stop();
		        Npr_Ttsplayer_playtextw(playokString,NULL);  
		    }
		#endif
		    StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*6,kjx_factory_call_test_start);
		}
		else
		{
		#if defined(__NPR_TTS__)
		    if(mmi_ucs2strlen((const CHAR *)playfailString)>0)
		    {
		        Npr_Tts_play_stop();
		        Npr_Ttsplayer_playtextw(playfailString,NULL);  
		    }
		#endif		
		}	
	}
	else	//xb add 2016-11-28 组装测试，不需要验证灵敏度一致性
#endif		
	{
	#if defined(__NPR_TTS__)
	    if(mmi_ucs2strlen((const CHAR *)playString)>0)
	    {
	        Npr_Tts_play_stop();
	        Npr_Ttsplayer_playtextw(playString,NULL);  
	    }
	#endif
	    StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*6,kjx_factory_call_test_start);		
	}
}
#endif

#if defined(__KJX_TOURIST_MAP_SUPPORT__)
static mmi_ret mmi_main_submenu_proc(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{
	case EVT_ID_GROUP_ACTIVE:
	case EVT_ID_GROUP_INACTIVE:
	case EVT_ID_GROUP_DEINIT:
		break;
		
	default:
		break;
	}
	
	return MMI_RET_OK;
}

static void mmi_exit_kjx_image_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
	
	kjx_image_id = 0;
	g_kjx_image_group_id = GRP_ID_INVALID;
	StopTimer(KJX_TIMER_ID_SHOW_TOUR_IMG_TIMEROUT);
}

void mmi_show_tour_image(void)
{
	GDI_RESULT result = GDI_FAILED;
	S32 x=0,y=0,w=UI_DEVICE_WIDTH,h=UI_DEVICE_HEIGHT;
	S32 img_w, img_h;
	char tmpbuf[128] = {0}, strbuf[128] = {0};
	CHAR filename[128] = {0};

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("kjx_image_id:%d", kjx_image_id+1);
#endif
#endif

	gdi_layer_push_clip();
    gdi_layer_set_clip(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT);
	gdi_draw_solid_rect(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT, GDI_COLOR_BLACK);

	kal_wsprintf((WCHAR*)filename, "%c%w", SRV_FMGR_CARD_DRV, IMAGEDIR);
#ifdef __KJX_RFID_LOCATION__
	sprintf(strbuf, "%06d_%d", g_rfid_played_id, kjx_image_id+1);
#else
	sprintf(strbuf, "%08d_%d", g_rfid_played_id, kjx_image_id+1);
#endif
	strcat(strbuf, TOURIST_MAP_FORMAT);
	mmi_chset_convert(MMI_CHSET_GB18030, MMI_CHSET_UCS2, strbuf, tmpbuf, sizeof(tmpbuf));
	mmi_ucs2cat((CHAR*)filename, (CHAR*)tmpbuf);
	gdi_image_get_dimension_file((S8*)filename, &img_w, &img_h);
	x = img_w > UI_DEVICE_WIDTH ? 0 : (UI_DEVICE_WIDTH - img_w)/2;
	y = img_h > UI_DEVICE_HEIGHT ? 0 : (UI_DEVICE_HEIGHT- img_h)/2;
	w = img_w > UI_DEVICE_WIDTH ? UI_DEVICE_WIDTH : img_w;
	h = img_h > UI_DEVICE_HEIGHT ? UI_DEVICE_HEIGHT : img_h;
	
	result = gdi_image_draw_resized_file(x,y,w,h,filename);

	gdi_layer_pop_clip();

	gui_BLT_double_buffer(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT);
}

void mmi_entry_kjx_image_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[MAX_SUB_MENUS];
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_scrn_enter(
			g_kjx_image_group_id, 
			SCR_ID_KJX_IMAGE, 
			mmi_exit_kjx_image_screen, 
			mmi_entry_kjx_image_screen, 
			MMI_FRM_FULL_SCRN
			);

	mmi_show_tour_image();

	SetDefaultVolumeKeyHandlers();
	SetKeyHandler(kjx_show_tour_image, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(kjx_exit_tour_image, KEY_RSK, KEY_EVENT_UP);
}

void kjx_exit_tour_image(void)
{
	MMI_ID group_id,scrn_id;

	StopTimer(KJX_TIMER_ID_SHOW_TOUR_IMG_TIMEROUT);
	
	mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_kjx_image_group_id:%d, group_id:%d, SCR_KEY_TONE_VOLUME:%d, SCR_ID_KJX_IMAGE:%d,scrn_id:%d", g_kjx_image_group_id, group_id, SCR_KEY_TONE_VOLUME, SCR_ID_KJX_IMAGE, scrn_id);
#endif
#endif

	if(scrn_id == SCR_KEY_TONE_VOLUME)
	{
		mmi_frm_scrn_close_active_id();
		StartTimer(KJX_TIMER_ID_SHOW_TOUR_IMG_TIMEROUT, 200, kjx_exit_tour_image);
	}
	else if(scrn_id == SCR_ID_KJX_IMAGE)
	{
		mmi_frm_scrn_close_active_id();
	}
}

void kjx_show_tour_image(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8 i;
	char tmpbuf[128] = {0}, strbuf[128] = {0};
	CHAR filename[128] = {0};
	FS_HANDLE handle;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	if(kjx_rfid_get_rfid_id() == 0)
	{
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("rfid = 0 return");
	#endif
	#endif
	
		return;
	}

	if(g_kjx_image_group_id == GRP_ID_INVALID)
	{
		for(i=0;i<TOURIST_MAP_MAX;i++)
		{
			kal_wsprintf((WCHAR*)filename, "%c%w", SRV_FMGR_CARD_DRV, IMAGEDIR);
			
		#ifdef __KJX_RFID_LOCATION__
			sprintf(strbuf, "%06d_%d", g_rfid_played_id, kjx_image_id+1);
		#else
			sprintf(strbuf, "%08d_%d", g_rfid_played_id, kjx_image_id+1);
		#endif
			strcat(strbuf, TOURIST_MAP_FORMAT);
		
		#if defined(__KJX_LOG_OUTPUT__)
			//LOGD("001_i:%d, kjx_image_id:%d, file:%s", i, kjx_image_id+1, strbuf);
		#endif
			mmi_chset_convert(MMI_CHSET_GB18030, MMI_CHSET_UCS2, strbuf, tmpbuf, sizeof(tmpbuf));
			mmi_ucs2cat((CHAR*)filename, (CHAR*)tmpbuf);
			handle = FS_Open((WCHAR*)filename, FS_READ_ONLY);
			if(handle >= FS_NO_ERROR)
			{
				FS_Close(handle);
				g_kjx_image_group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_main_submenu_proc, NULL);
				mmi_frm_group_enter(g_kjx_image_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
				mmi_entry_kjx_image_screen();
				break;
			}
			else
			{
				kjx_image_id++;
				if(kjx_image_id >= TOURIST_MAP_MAX)
					kjx_image_id = 0;
			}			
		}
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("001 i:%d, rfid:%d, kjx_image_id:%d", i, g_rfid_played_id, kjx_image_id+1);
	#endif
	#endif
		
	}
	else
	{
		kjx_image_id++;
		if(kjx_image_id >= TOURIST_MAP_MAX)
			kjx_image_id = 0;

		for(i=0;i<TOURIST_MAP_MAX;i++)
		{
			kal_wsprintf((WCHAR*)filename, "%c%w", SRV_FMGR_CARD_DRV, IMAGEDIR);

		#ifdef __KJX_RFID_LOCATION__
			sprintf(strbuf, "%06d_%d", g_rfid_played_id, kjx_image_id+1);
		#else
			sprintf(strbuf, "%08d_%d", g_rfid_played_id, kjx_image_id+1);
		#endif
			strcat(strbuf, TOURIST_MAP_FORMAT);

		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("002_i:%d, kjx_image_id:%d, file:%s", i, kjx_image_id+1, strbuf);
		#endif
		
			mmi_chset_convert(MMI_CHSET_GB18030, MMI_CHSET_UCS2, strbuf, tmpbuf, sizeof(tmpbuf));
			mmi_ucs2cat((CHAR*)filename, (CHAR*)tmpbuf);
			handle = FS_Open((WCHAR*)filename, FS_READ_ONLY);
			if(handle >= FS_NO_ERROR)
			{
				FS_Close(handle);
				mmi_show_tour_image();
				break;
			}
			else
			{
				kjx_image_id++;
				if(kjx_image_id >= TOURIST_MAP_MAX)
					kjx_image_id = 0;
			}			
		}
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("002 i:%d, rfid:%d, kjx_image_id:%d", i, g_rfid_played_id, kjx_image_id+1);
	#endif
	#endif
	}

	StartTimer(KJX_TIMER_ID_SHOW_TOUR_IMG_TIMEROUT, 5*1000, kjx_show_tour_image);
}
#endif/*__KJX_TOURIST_MAP_SUPPORT__*/

void kjx_handle_send_poweroff_notify(void)
{
#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

    kjx_socket_send_data_with_type(SERVER_TYPE_78);	
}

#ifdef __KJX_FENCE_SUPPORT__
void kjx_fence_alarm_notify_callback(void)
{
	srv_vibrator_off();
}

void kjx_receive_fence_alarm_proc(void)
{
	switch(kjx_fence.alarm_mode)
	{
	case 0://不提示
		break;
		
	case 1://震动提示
		srv_vibrator_on();
		StartTimer(KJX_TIMER_ID_FENCE_ALARM_TIMEROUT, 2000, kjx_fence_alarm_notify_callback);
		break;
		
	case 2://语音提示
		TTsPlayRepeat = 1;
		memset(TtsPlayString,0,sizeof(TtsPlayString));
		mmi_ucs2cpy((CHAR*)TtsPlayString, (const CHAR*)kjx_fence.alarm_str);
		if(mmi_ucs2strlen((const CHAR *)TtsPlayString)>0)
		{
			if(kjx_rfid_is_in_play())
			{
				mdi_audio_stop_file();//xb add 2016-09-25 暂时中断RFID播放，后面还要继续播放
			}

			StartTimer(KJX_TIMER_ID_FENCE_ALARM_TIMEROUT, 2000, kjx_set_with_play_tts);
		}
		break;
		
	case 3://震动+ 语音提示
		TTsPlayRepeat = 1;
		memset(TtsPlayString,0,sizeof(TtsPlayString));
		mmi_ucs2cpy((CHAR*)TtsPlayString, (const CHAR*)kjx_fence.alarm_str);
		if(mmi_ucs2strlen((const CHAR *)TtsPlayString)>0)
		{
			if(kjx_rfid_is_in_play())
			{
				mdi_audio_stop_file();//xb add 2016-09-25 暂时中断RFID播放，后面还要继续播放
			}

			srv_vibrator_on();
			StartTimer(KJX_TIMER_ID_FENCE_ALARM_TIMEROUT, 2000,kjx_set_with_play_tts);
		}
		break;
	}
}
#endif

#if defined(__KJX_POSITION_TRIGGER_IN_LOCAL__)
/*---------------------------------------------------------------------------
 * FUNCTION			RadRound
 *
 * DESCRIPTION		将角度转换为弧度
 *
 * Input:
 * Output:
 * Returns:
 *
 * modification history
 * --------------------
 * v1.0  ,
 * --------------------
 *---------------------------------------------------------------------------*/ 
static double RadRound(double d) 
{ 
	return d * PIAD / 180.0; 
} 

/*---------------------------------------------------------------------------
 * FUNCTION			GPS_Get_Two_Points_Distance
 *
 * DESCRIPTION		按国际标准求两经纬度间距离
 *
 * Input:           		double lat1,double lon1 第一个点的纬度,经度 double lat2,double lon2 第二个点的纬度,经度
 * Output:                    两点之间距离单位:M
 * Returns:
 *
 * modification history
 * --------------------
 * v1.0  , 2012-7-13,  guojie arrange
 * --------------------
 *---------------------------------------------------------------------------*/
static double GPS_Get_Two_Points_Distance(double lon1, double lat1,  double lon2, double lat2) 
{ 
	double radLat1, radLat2, aLat, aLon, s ;
	double earth_rad = 6378.1370 ;//取WGS84标准参考椭球中的地球长半径(单位:km)

	radLat1 = RadRound(lat1);
	radLat2 = RadRound(lat2);
	aLat =	radLat1 - radLat2;		 //纬度之差
	aLon = RadRound(lon1)  - RadRound(lon2);//经度之差
	s = 2 * asin(sqrt(pow(sin(aLat / 2), 2) + cos(radLat1) * cos(radLat2) * pow(sin(aLon / 2), 2))); 
	s = s * earth_rad;
	s = s * 1000;
	
#if 0	//def RFID_DEBUG	
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("lon1:%f, lat1:%f, lon2:%f, lat2:%f, s:%f", lon1, lat1, lon2, lat2, s);
#endif
#endif

	return s; 
}

double kjx_position_string_to_double(U8* buffer)
{
	U8 i=0,flag=1,len;
	double j=1.0,k=1.0;
	double position = 0.0;

	len = strlen(buffer);
	if(len > 0)
	{
		if(buffer[i] == 'N' || buffer[i] == 'n' || buffer[i] == 'E' || buffer[i] == 'e' || buffer[i] == '+')
		{
			i = 1;
			j = 1.0;
		}
		else if(buffer[i] == 'S' || buffer[i] == 's' || buffer[i] == 'W' || buffer[i] == 'w' || buffer[i] == '-')
		{
			i = 1;
			j = -1.0;
		}

		for(;i<len;i++)
		{
			int tmp;
			
			if(buffer[i] == '.')
			{
				flag = 0;
				k = 0.1;
				continue;
			}

			if(buffer[i] < '0' || buffer[i] > '9')
			{
			#ifdef RFID_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("数据超出0~9,直接退出");
			#endif
			#endif
				return 0.0;
			}
			
			tmp = buffer[i] - '0';

			if(flag)
			{
				position = j*(k*abs(position) + tmp);//整数部分
				k = 10;
			}
			else
			{
				position = position + j*k*tmp;//小数部分
				k = 0.1*k;
			}
		}
	}

	return position;
}

BOOL kjx_postion_playinfo_add(U8* lon, U8* lat, U8* distance, U8* rfid_id)
{
	U32 i=1;
	KJXPOSITIONINFO *pnew;
	static KJXPOSITIONINFO *head = NULL;

	if(g_kjxPositionPlayInfo.positioninfo == NULL)
	{
		g_kjxPositionPlayInfo.maxID = 0;
		g_kjxPositionPlayInfo.positioninfo = NULL;

		media_get_ext_buffer(MOD_MMI, (void **)&head, sizeof(KJXPOSITIONINFO));
		if (head == NULL) 
		{
		#ifdef RFID_DEBUG	
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("内存申请失败001，无法添加!");
		#endif
		#endif
		
			return FALSE;
		}

		head->lon = 0;
		head->lat = 0;
		head->distance = 0;
		memset(head->rfid_id, 0x00, sizeof(head->rfid_id));
		head->next = NULL;

		head->lon = kjx_position_string_to_double(lon);
		head->lat = kjx_position_string_to_double(lat);
		head->distance = atoi(distance);
		memcpy(head->rfid_id, rfid_id, strlen(rfid_id));
		
		g_kjxPositionPlayInfo.positioninfo = head;
		g_kjxPositionPlayInfo.maxID = 1;

	#ifdef RFID_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("添加成功! num:%d", g_kjxPositionPlayInfo.maxID);
	#endif
	#endif
		
		return TRUE;
	}
	else
	{
		if(head == NULL)
		{
		#ifdef RFID_DEBUG	
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("测试");
		#endif
		#endif
		
			head = g_kjxPositionPlayInfo.positioninfo;
			while(1)
			{
				if(head->next == NULL)
					break;
				else
					head = head->next;
			}
		}
		
		media_get_ext_buffer(MOD_MMI, (void **)&pnew, sizeof(KJXPOSITIONINFO));
		if (pnew == NULL) 
		{
		#ifdef RFID_DEBUG	
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("内存申请失败002，无法添加!");
		#endif
		#endif
		
			return FALSE;
		}
		else
		{
			pnew->lon = 0;
			pnew->lat = 0;
			pnew->distance = 0;
			memset(pnew->rfid_id, 0x00, sizeof(pnew->rfid_id));
			pnew->next = NULL;

			pnew->lon = kjx_position_string_to_double(lon);
			pnew->lat = kjx_position_string_to_double(lat);
			pnew->distance = atoi(distance);
			strcpy(pnew->rfid_id, rfid_id);
			head->next = pnew;
			
			head = pnew;//xb add 2017-05-08 记录链表链尾

			g_kjxPositionPlayInfo.maxID++;

		#ifdef RFID_DEBUG	
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("添加成功! sum:%d", g_kjxPositionPlayInfo.maxID);
		#endif
		#endif

			return TRUE;
		}
	}
}

KJXPOSITIONINFO *kjx_postion_playinfo_find(double lon, double lat)
{
	U32 i=1;
	BOOL ret;
	double distance = 0;
	KJXPOSITIONINFO *head,*tail,*pnew;

	if(g_kjxPositionPlayInfo.positioninfo == NULL)
	{
	#ifdef RFID_DEBUG	
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("链表没有创建，无法查找!");
	#endif
	#endif

		return NULL;
	}

	head = g_kjxPositionPlayInfo.positioninfo;
	while(head != NULL)
	{
		distance = GPS_Get_Two_Points_Distance(lon, lat, head->lon, head->lat);
	#ifdef RFID_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("位置序号:%d,设置距离:%d,实际距离:%f", i, head->distance, distance);
	#endif
	#endif
		
		if(head->distance >= distance)
		{
		#ifdef RFID_DEBUG	
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("查找成功! %d", i);
		#endif
		#endif
			return head;
		}
		else
		{
			i++;
			head = head->next;
		}
	}

#ifdef RFID_DEBUG	
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("查找无结果!");
#endif
#endif	
	return NULL;
}

void kjx_position_set_playinfos(char* infor)
{
	char* temString = NULL;
	char* temString1 = NULL;
	char* myString = NULL;
	int i = 0, j=0, k=0;
	U16 file_path_name[64] = {0};
	U16 tmpbuf[128] = {0};
	U32 time = 0;
	U32 filenum = 0;
	mdi_result result;

	g_kjxPositionPlayInfo.maxID = 0;
	
	temString = NULL;
	temString = kjx_get_parameter_string_only_in_buffer(infor,"|",1);
#ifdef MAIN_TOUR_DEBUG	
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("temString:%s", temString);
#endif
#endif
	if(atoi(temString)>0)
	{
		filenum = atoi(temString);
	#ifdef MAIN_TOUR_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("filenum:%d", filenum);
	#endif
	#endif
		myString = strstr(infor,"|");
		myString += strlen("|");

		for(i=0;i<filenum;i++)
		{
			char playString[128] = {0};
			char lon[GPS_LON_MAX_LEN+1]= {0};
			char lat[GPS_LAT_MAX_LEN+1] = {0};
			char distance[GPS_DISTANCE_MAX_LEN+1] = 0;
			char rfid_id[MAX_RFID_LEN+1] = {0};				
			U32 len = 0;
		
			temString = NULL;
			temString = kjx_get_parameter_string_only_in_buffer(myString+k,";",1);
			memcpy(playString,temString,strlen(temString));
			k += strlen(temString)+1;
		#ifdef MAIN_TOUR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("i:%d, j:%d, playString=%s", i, j, playString);
		#endif
		#endif

			temString1 = NULL;
			temString1 = kjx_get_parameter_string_only_in_buffer(playString,",",1);
			len = (GPS_LON_MAX_LEN > strlen(temString1)) ? strlen(temString1) : GPS_LON_MAX_LEN;
			memcpy(lon, temString1, len);
		#ifdef MAIN_TOUR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("i:%d, lon:%s", i, temString1);
		#endif
		#endif

			temString1 = NULL;
			temString1 = kjx_get_parameter_string_only_in_buffer(playString,",",2);
			len = (GPS_LAT_MAX_LEN > strlen(temString1)) ? strlen(temString1) : GPS_LAT_MAX_LEN;
			memcpy(lat, temString1, len);
		#ifdef MAIN_TOUR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("i:%d, lat:%s", i, temString1);
		#endif
		#endif

			temString1 = NULL;
			temString1 = kjx_get_parameter_string_only_in_buffer(playString,",",3);
			len = (GPS_DISTANCE_MAX_LEN > strlen(temString1)) ? strlen(temString1) : GPS_DISTANCE_MAX_LEN;
			memcpy(distance, temString1, len);
		#ifdef MAIN_TOUR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("i:%d, distance:%s", i, temString1);
		#endif
		#endif
		
			temString1 = NULL;
			temString1 = kjx_get_parameter_string_only_in_buffer(playString,",",4);
			len = (MAX_RFID_LEN > strlen(temString1)) ? strlen(temString1) : MAX_RFID_LEN;
			memcpy(rfid_id, temString1, len);
		#ifdef MAIN_TOUR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("i:%d, rfid_id:%s", i, temString1);
		#endif
		#endif

			if(!kjx_postion_playinfo_add(lon, lat, distance, rfid_id))
			{
				break;
			}
		}

		if(i == filenum)
			g_kjxPositionPlayInfo.maxID = filenum;
		else
			g_kjxPositionPlayInfo.maxID = i+1;
	}
}

void kjx_position_play_infos_read(void)
{
	kal_uint32 fs_len;
	FS_HANDLE handle;
	S8 usc2Path[128];
	UINT filesize;

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	memset(usc2Path, 0x00, sizeof(usc2Path));	
	kal_wsprintf((WCHAR*) usc2Path, "%c%w", SRV_FMGR_CARD_DRV, AUDIODIR);
	handle = FS_SetCurrentDir((WCHAR*)usc2Path);
	if(handle>=FS_NO_ERROR)
	{
		FS_SetAttributes(POSITIONPLAYINFO, FS_ATTR_ARCHIVE);
		handle = FS_Open(POSITIONPLAYINFO, FS_READ_ONLY | FS_ATTR_ARCHIVE);
		if(handle>=FS_NO_ERROR)
		{
			FS_GetFileSize(handle, &filesize);
		#ifdef MAIN_TOUR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("filesize:%d", filesize);
		#endif
		#endif

			if(filesize == 0)
			{
			#ifdef MAIN_TOUR_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("文件内容为空!");
			#endif
			#endif
				FS_Close(handle);
				return;
			}
			
			if(posfileString == NULL)
			{
				media_get_ext_buffer(MOD_MMI, (void **)&posfileString, filesize);
				if(posfileString == NULL)
				{
				#ifdef MAIN_TOUR_DEBUG
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("申请内存失败!");
				#endif
				#endif
					FS_Close(handle);
					return;
				}
			}
			memset(posfileString, 0x00, filesize);
			FS_Read(handle, (void *)posfileString, filesize, &fs_len);
		#ifdef MAIN_TOUR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("001, fs_len:%d", fs_len);
		#endif
		#endif
			FS_Close(handle);
		
		#if defined(__KJX_AUDIO_FILE_DECODE__)
			kjx_encode_string(posfileString, fs_len);
		#endif

			if(strlen(posfileString)>0)
			{
				kjx_position_set_playinfos(posfileString);
			}

			if(posfileString != NULL)
			{
				media_free_ext_buffer(MOD_MMI, (void**)&posfileString);
				posfileString = NULL;
			}		
		}
		else
		{
		#ifdef MAIN_TOUR_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("文件不存在");
		#endif
		#endif
		}
	}
}

static void kjx_position_trigger_process_in_local(S8 longitude_dir, double longitude, S8 latitude_dir, double latitude)
{
	double lon,lat;
	KJXPOSITIONINFO *positioninfo = NULL;
	KJXRFIDINFO *playinfo = NULL;

#ifdef MAIN_TOUR_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("longitude_dir:%c, longitude:%f, latitude_dir:%c, latitude:%f", longitude_dir, longitude, latitude_dir, latitude);
#endif
#endif

	if((latitude > 0 && latitude <= 90)&&(longitude > 0 && longitude <= 180))
	{
		//正常逻辑 北纬东经是正值
		if(latitude_dir == 'S')
			lat = -latitude;
		else
			lat = latitude;
		
		if(longitude_dir == 'W')
			lon = -longitude;
		else
			lon = longitude;

		positioninfo = kjx_postion_playinfo_find(lon, lat);
		if(positioninfo)
		{
			U32 myID = 0;
			
			myID = atoi(positioninfo->rfid_id);
		#if defined(__KJX_RESET_USED_COUNT__)
			if(myID == RESET_RFID)
			{
				kjx_handle_receive_reset_rfid(0);
			}
			else
		#endif
			{
				if(IsMyTimerExist(KJX_TIMER_RESET_SHOW))
					return;
				
				g_play_cause = 1;
				kjx_rfid_id = myID;
				
			#ifdef MAIN_TOUR_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("kjx_rfid_id:%d", kjx_rfid_id);
			#endif
			#endif
				
				kjx_rfid_check_id();
			}
		}
	}
}

#endif/*__KJX_POSITION_TRIGGER_IN_LOCAL__*/

#endif/*CUSTOMER_NAME_TOUR*/
#endif/*__KJX_FUN__*/
