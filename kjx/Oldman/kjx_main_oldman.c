/**********************************************************************************
*Filename:     kjx_main_oldman.c
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2014/01/13
*
***********************************************************************************/
#if defined(__KJX_FUN__)
#if defined(CUSTOMER_NAME_OLDMAN)
#include "kjx_include.h"
#include "kjx_main_oldman.h"
#include "yas.h"
#include "mmi_rp_app_worldclock_def.h"
#include "mmi_frm_nvram_gprot.h"
 
U8 g_alarm_status = 0;
extern double old_latitude;
extern double old_longitude;
extern U16 sensor_status;
extern BOOL socketConnet;
BOOL g_gps_send_interval = FALSE;
//static BOOL g_sensor_sign = FALSE;
//BOOL service_to_tracer = FALSE;//是否服务器主动下发
#ifndef ABS
#define ABS(x) ((x) > 0 ? (x) : -(x))
#endif


extern kjx_nvram_struct g_kjx_nvram_struct;

U8 parse_flag = 0;

U16 sms_gps_info[512];
extern int g_is_sms_send;

kjx_oldman_struct g_kjx_oldman_struct =
{
	{"123456\0"},/*密码*/
	{"\0","\0","\0"}, /*SOS号码*/
	{"\0"}, /*监听号码*/
	{"\0"}, /* +8613800138000 */
	{"0086\0"}, /*语言*/
	{"\0"}, /*SOS报警短信内容*/
	{"\0"},		/*deviceNumber 设备号*/
	{"\0"},	/*写入的IMEI号*/
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
/***********************************************************************************/


/***********************************************************************************/
//流程实现

/***********************************************************************************/
//g_sensor
#define SENSOR_STATIC_TIME 60*3   /*3MIN*/
#define KJX_VALUE_MAX	30 /*灵敏度*/

typedef struct
{
	int16 value_x;
	int16 value_y;
	int16 value_z;
}kjx_gsensor_value;

kjx_gsensor_value g_kjx_gsensor_value;
long double min_av = -1;
S32 g_steps_timer = 0;
S32 steps_count = 0;
S32 old_ax = 0;
S32 old_ay = 0;
S32 old_az = 0;

void kjx_oldman_sensor_cb(BOOL result)
{
	static int moveCount = 0;
	static int moveStatus = 0;
	static int socketCheck = 0;

	kjx_set_status_icon();

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
			kjx_oldman_move_timeout(FALSE);
		}
	}
	
	if((moveCount == SENSOR_STATIC_TIME))
	{
		moveStatus = 1;
		sensor_status = 1;
		kjx_oldman_move_timeout(TRUE);
	}

	if((!socketConnet)&&(socketCheck==0)&&(!sensor_status))
	{
		socketCheck++;
		StartTimer(KJX_TIMER_ID_LOGIN_AGAIN, 15*1000, g_kjx_socket_event_func.socket_login_again);
	}
	else
	{
		socketCheck++;
		if(socketCheck>=60)
		{//一分钟检测一次网络连接
			socketCheck = 0;
		}
	}
}

BOOL kjx_sensor_is_running(void)
{
	static int16  old_x_value = 0;
	static int16  old_y_value = 0;
	static int16  old_z_value = 0;
	BOOL isRunning = FALSE;

#ifdef MAIN_OLDMAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("x=%d,y=%d,z=%d,ABS(old_x_value-x)=%d,ABS(old_y_value-y)=%d,ABS(old_z_value-z)=%d", g_kjx_gsensor_value.value_x,g_kjx_gsensor_value.value_y,g_kjx_gsensor_value.value_z,ABS(old_x_value-g_kjx_gsensor_value.value_x),ABS(old_y_value-g_kjx_gsensor_value.value_y),ABS(old_z_value-g_kjx_gsensor_value.value_z));
#endif
#endif
	if((g_kjx_gsensor_value.value_x==0)&&(g_kjx_gsensor_value.value_y==0)&&(g_kjx_gsensor_value.value_z==0))
	{
		old_x_value = 0;
		old_y_value = 0;
		old_z_value = 0;
		return FALSE;
	}

	if((ABS(old_x_value-g_kjx_gsensor_value.value_x)>KJX_VALUE_MAX)||(ABS(old_y_value-g_kjx_gsensor_value.value_y)>KJX_VALUE_MAX)||(ABS(old_z_value-g_kjx_gsensor_value.value_z)>KJX_VALUE_MAX))
	{
		isRunning = TRUE;
	}
	else
	{
		isRunning = FALSE;
	}
	
	old_x_value = g_kjx_gsensor_value.value_x;
	old_y_value = g_kjx_gsensor_value.value_y;
	old_z_value = g_kjx_gsensor_value.value_z;

	if(isRunning)
		return TRUE;
	else
		return FALSE;

}

void kjx_sensor_entry_timer(void)
{
	static BOOL gSign = FALSE;
	
	StopTimer(KJX_TIMER_ID_SENSOR);
#ifdef MAIN_OLDMAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("gSign=%d,g_sensor_sign=%d", gSign, g_sensor_sign);
#endif
#endif
	
	if(kjx_sensor_is_running())
	{
	#ifdef MAIN_OLDMAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("kjx_oldman_sensor_cb=TRUE");
	#endif
	#endif
		kjx_oldman_sensor_cb(TRUE);
	}
	else
	{
	#ifdef MAIN_OLDMAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("kjx_oldman_sensor_cb=FALSE");
	#endif
	#endif
		kjx_oldman_sensor_cb(FALSE);
	}
	
	StartTimer(KJX_TIMER_ID_SENSOR, 1000, kjx_sensor_entry_timer);
}

void kjx_steps_gsensor_data(kal_int32 x,kal_int32 y,kal_int32 z)
{
	S32 ax=0;
	S32 ay=0;
	S32 az=0;
	long double av = 0;
	static S32 tem_count=0;

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
	
	//slc_trace_steps("%s (ax-old_ax)=%d,(ay-old_ay)=%d,(az-old_az)=%d",__func__,(ax-old_ax),(ay-old_ay),(az-old_az));
	//加速度
	av = (sqrt(pow((ax-old_ax),2)+pow((ay-old_ay),2)+pow((az-old_az),2)))*0.01;
	
	if(min_av == -1)
	{
		min_av = av;
	}

	if(min_av>av)
	{
		min_av = av;
	}

 	tem_count = steps_count;
	//if((g_steps_timer>4)&&(min_av>1.5)&&((av>2)&&(av<6.5)))
	if((g_steps_timer>4)&&(min_av<1.5)&&((av>2)&&(av<6.5)))
	{
		steps_count++;
		min_av = -1;
		g_steps_timer = 0;
	}
	
	if(tem_count!=steps_count)
	{
	}
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
}

int kjx_steps_teller_total(void)
{
	if(steps_count>999)
	{
		steps_count = 0;
	}
	return steps_count;
}

#if defined(__MOTION_SENSOR_MC3413_SUPPORT__)
void kjx_sensor_get_data_mc3413(int16 x,int16 y,int16 z)
{
	static int16  old_x_value = 0;
	static int16  old_y_value = 0;
	static int16  old_z_value = 0;
	
	if((ABS(old_x_value-x)>KJX_VALUE_MAX)||(ABS(old_y_value-y)>KJX_VALUE_MAX)||(ABS(old_z_value-z)>KJX_VALUE_MAX))
	{
		g_kjx_gsensor_value.value_x = x;
		g_kjx_gsensor_value.value_y = y;
		g_kjx_gsensor_value.value_z = z;
	}

	old_x_value = x;
	old_y_value = y;
	old_z_value = z;
}
#endif

/*关闭T-CARD功能*/
//kal_bool MSDC_Check_Card_Mount(void){}

/***********************************************************************************/

//事件处理

/***********************************************************************************/
#ifdef __KJX_FUN_GPS__
void kjx_oldman_do_something_with_custom(kjx_gps_data g_kjx_gps_data)
{/*使用GPS数据进行一些事件操作*/
#ifdef MAIN_OLDMAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("data_status:%c", g_kjx_gps_data.data_status);
#endif
#endif

	if(g_kjx_gps_data.data_status == 'A')
	{}
	else
	{}

}
#endif

void kjx_oldman_move_timeout(BOOL timeout)
{
#ifdef MAIN_OLDMAIN_DEBUG
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
		#ifdef MAIN_OLDMAIN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("休眠模式");
		#endif
		#endif
			return;
		}
		
	#ifdef __KJX_FUN_GPS__
		kjx_open_gps();
	#endif
		
		/*上传定位数据*/
		if(socketConnet)
			StartTimer(KJX_TIMER_ID_GPS_DATA, 60*1000, kjx_oldman_socket_send_gps_data);
		else
			StartTimer(KJX_TIMER_ID_LOGIN_AGAIN, 60*1000, g_kjx_socket_event_func.socket_login_again);

	}
}


void kjx_oldman_open_gps_timer(void)
{
	StopTimer(KJX_TIMER_ID_GPS_OPEN);
	
#ifdef __KJX_FUN_GPS__
	kjx_open_gps();
#endif
}

void kjx_oldman_socket_timeout(void)
{
#ifdef MAIN_OLDMAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	StopTimer(KJX_TIMER_ID_IS_CONNET);

	if(socketConnet)
		socketConnet = FALSE;

	kjx_socket_session_free();
	StartTimer(KJX_TIMER_ID_LOGIN_AGAIN, 15*1000, g_kjx_socket_event_func.socket_login_again);
}

void kjx_reset_gps_data_send_func(void)
{
	if(IsMyTimerExist(KJX_TIMER_ID_GPS_DATA))
		StopTimer(KJX_TIMER_ID_GPS_DATA);
	if(IsMyTimerExist(KJX_TIMER_ID_GPS_OPEN));
		StopTimer(KJX_TIMER_ID_GPS_OPEN);
	if(IsMyTimerExist(KJX_TIMER_ID_GPS_CLOSE))
		StopTimer(KJX_TIMER_ID_GPS_CLOSE);

	if(g_kjx_nvram_struct.workMode==2)
	{
		/*停止读取基站数据*/
		StopTimer(KJX_TIMER_ID_CELL_REQ);
		StopTimer(KJX_TIMER_ID_NBR_CELL_REQ);
	#if defined(__KJX_FUN_GPS__)
		kjx_close_gps();
	#endif

		/*关闭GPRS*/
	#ifdef MAIN_OLDMAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("001");
	#endif
	#endif
		//kjx_socket_session_free();

		return;
	}

#ifdef MAIN_OLDMAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("002");
#endif
#endif
	
#if defined(__KJX_FUN_GPS__)
	if((mmi_get_gps_status())&&(kjx_gps_is_on()))
	{
		StartTimer(KJX_TIMER_ID_GPS_DATA, (1000*5), kjx_oldman_socket_send_gps_data);
	}
	else
#endif
	{
		kjx_oldman_open_gps_timer();
		StartTimer(KJX_TIMER_ID_GPS_DATA, (1000*60), kjx_oldman_socket_send_gps_data);
	}
}

void kjx_handle_gps_work_mode(S32 result)
{
	switch(g_kjx_nvram_struct.workMode)
	{
	case 0:/*紧急模式（10秒一次上报GPS数据）*/
	#ifdef MAIN_OLDMAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("紧急模式 10秒上传一次");
	#endif
	#endif
	
	    StartTimer(KJX_TIMER_ID_GPS_DATA, 1000*10, kjx_oldman_socket_send_gps_data);
		break;
			
	case 1:/*正常模式（10分钟一次上报GPS数据）*/
		/*省电考虑，不管发送成功与否，都关闭GPS*/
	#if defined(MAIN_OLDMAIN_DEBUG)
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("正常模式 %d分钟上传一次", g_kjx_nvram_struct.sendTime/(1000*60));
	#endif
	#endif
	
		kjx_stop_get_cellid();
	#if defined(__KJX_FUN_GPS__)
		kjx_close_gps();
	#endif
	
		StartTimer(KJX_TIMER_ID_GPS_OPEN, g_kjx_nvram_struct.sendTime-(1000*60*2), kjx_oldman_open_gps_timer);
		StartTimer(KJX_TIMER_ID_GPS_DATA, g_kjx_nvram_struct.sendTime, kjx_oldman_socket_send_gps_data);
		break;
		
	case 2:/*关闭模式*/
	#ifdef MAIN_OLDMAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("关闭模式");
	#endif	
	#endif
		StopTimer(KJX_TIMER_ID_GPS_DATA);
		StopTimer(KJX_TIMER_ID_GPS_OPEN);
		kjx_stop_get_cellid();

	#if defined(__KJX_FUN_GPS__)
		kjx_close_gps();
	#endif

		/*关闭GPRS*/
		//kjx_socket_session_free();
		break;
		
	default:
	#ifdef MAIN_OLDMAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("默认模式%d分钟上传一次", g_kjx_nvram_struct.sendTime);
	#endif
	#endif
		/*省电考虑，不管发送成功与否，都关闭GPS*/
		kjx_stop_get_cellid();
	#if defined(__KJX_FUN_GPS__)
		kjx_close_gps();
	#endif

		StartTimer(KJX_TIMER_ID_GPS_OPEN, g_kjx_nvram_struct.sendTime-(1000*60*2), kjx_oldman_open_gps_timer);
		StartTimer(KJX_TIMER_ID_GPS_DATA, g_kjx_nvram_struct.sendTime, kjx_oldman_socket_send_gps_data);
		break;
	}
}

void kjx_oldman_socket_send_heartbeat(void)
{/*心跳包*/
    S32 result = 0;

#ifdef MAIN_OLDMAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

    StopTimer(KJX_TIMER_ID_HEART_BEAT);
    kjx_socket_send_data_with_type(SERVER_TYPE_01);
 
    StartTimer(KJX_TIMER_ID_HEART_BEAT, HEART_BEAT_TIME, kjx_oldman_socket_send_heartbeat);
    StartTimer(KJX_TIMER_ID_IS_CONNET, HEART_BEAT_TIME-(1000*60), kjx_oldman_socket_timeout);
}

void kjx_oldman_gps_work_mode(S32 result)
{
	static U16 first_gps = 0;
	static U16 wait_gps = 0;
	
#ifdef MAIN_OLDMAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("data_status:%c", g_kjx_gps_data.data_status);
#endif
#endif

	if(!kjx_is_on_work_time())
	{
		StartTimer(KJX_TIMER_ID_GPS_DATA, 1000*10, kjx_oldman_socket_send_gps_data);
		return;
	}

	if((!first_gps)&&(wait_gps<30))
	{//5分钟未搜索到GPS，走正常程序
	#if defined(__KJX_FUN_GPS__)
		if(g_kjx_gps_data.data_status == 'A')
		{
			first_gps = 1;
		}
		else
	#endif
		{
			if(g_kjx_nvram_struct.workMode==0)
			{/*正常模式*/
				first_gps = 1;
				wait_gps=60;
			}
			
			wait_gps++;
		#ifdef MAIN_OLDMAIN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("first_gps = 0");
		#endif
		#endif
			StartTimer(KJX_TIMER_ID_GPS_DATA, 1000*10, kjx_oldman_socket_send_gps_data);
			return;
		}
	}
#ifdef MAIN_OLDMAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("workMode=%d,sendTime=%d",  g_kjx_nvram_struct.workMode, g_kjx_nvram_struct.sendTime);
#endif
#endif
 	
	switch(g_kjx_nvram_struct.workMode)
	{
	case 0:/*紧急模式（10秒一次上报GPS数据）*/
	#ifdef MAIN_OLDMAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("紧急模式10秒钟上传一次");
	#endif
	#endif
	
	    StartTimer(KJX_TIMER_ID_GPS_DATA, 1000*10, kjx_oldman_socket_send_gps_data);
		break;
			
	case 1:/*正常模式（10分钟一次上报GPS数据）*/
		/*省电考虑，不管发送成功与否，都关闭GPS*/
		kjx_stop_get_cellid();
	#if defined(__KJX_FUN_GPS__)
		kjx_close_gps();
	#endif

	#ifdef MAIN_OLDMAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("正常模式%d分钟上传一次", g_kjx_nvram_struct.sendTime/(1000*60));
	#endif
	#endif
		StartTimer(KJX_TIMER_ID_GPS_OPEN, g_kjx_nvram_struct.sendTime-(1000*60*2), kjx_oldman_open_gps_timer);
		StartTimer(KJX_TIMER_ID_GPS_DATA, g_kjx_nvram_struct.sendTime, kjx_oldman_socket_send_gps_data);
		break;
		
	case 2:/*关闭模式*/
	#ifdef MAIN_OLDMAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("关闭模式");
	#endif
	#endif
	
		StopTimer(KJX_TIMER_ID_GPS_DATA);
		StopTimer(KJX_TIMER_ID_GPS_OPEN);
		kjx_stop_get_cellid();

	#if defined(__KJX_FUN_GPS__)
		kjx_close_gps();
	#endif
	
		/*关闭GPRS*/
		//kjx_socket_session_free();
		break;
		
	default:
	#ifdef MAIN_OLDMAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("默认模式%d分钟上传一次", g_kjx_nvram_struct.sendTime/(1000*60));
	#endif
	#endif
	
		/*省电考虑，不管发送成功与否，都关闭GPS*/
		kjx_stop_get_cellid();
	#if defined(__KJX_FUN_GPS__)
		kjx_close_gps();
	#endif
	
		StartTimer(KJX_TIMER_ID_GPS_OPEN, g_kjx_nvram_struct.sendTime-(1000*60*2), kjx_oldman_open_gps_timer);
		StartTimer(KJX_TIMER_ID_GPS_DATA, g_kjx_nvram_struct.sendTime, kjx_oldman_socket_send_gps_data);
		break;
	}
}

void kjx_oldman_socket_send_gps_data(void)
{/*位置数据包*/
    S32 result = 0;
 
#ifdef MAIN_OLDMAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	 LOGD("begin");
#endif
#endif

    StopTimer(KJX_TIMER_ID_GPS_DATA);
    if((g_kjx_nvram_struct.workMode==2)&&(g_kjx_nvram_struct.dataIsSync))
    {
    	/*关闭模式*/
    	/*关闭GPRS*/
		kjx_stop_get_cellid();
	#ifdef MAIN_OLDMAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		 LOGD("002");
	#endif
	#endif
		//kjx_socket_session_free();
		return;
    }

	if(kjx_gps_is_valid())
	    result=kjx_socket_send_data_with_type(SERVER_TYPE_03);
	else
		result=kjx_socket_send_data_with_type(SERVER_TYPE_84);

    kjx_oldman_gps_work_mode(result);
}

void kjx_oldman_trace_to_service(kjx_socket_type socket_type)
{
#ifdef MAIN_OLDMAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	 LOGD("begin");
#endif
#endif

    kjx_socket_send_data_with_type(socket_type);
}


/***********************************************************************************/
void kjx_oldman_check_do_somthing(void)
{
    U8 batteryStatus;
    applib_time_struct currTime;
    U8 gsm_status;
    static U16 checkNet = 0;

    kjx_set_status_icon();
    kjx_write_work_time();
    gsm_status = kjx_sys_get_cur_gsm_status();
#ifdef MAIN_OLDMAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("gsm_status:%d", gsm_status);
#endif
#endif
	
    memset(&currTime, 0x00, sizeof(currTime));
    applib_dt_get_rtc_time(&currTime);	

    if((currTime.nHour == 3)&&(currTime.nMin == 0)&&(currTime.nSec>0)&&(currTime.nSec<10))
    {/*每天3点钟重启设备*/
        g_kjx_socket_event_func.socket_restart();
	#ifdef MAIN_OLDMAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("001");
	#endif
	#endif		
        return;
    }

    checkNet++;
	
    if((!socketConnet)&&(checkNet>=12))
    {
    	checkNet = 0;
	#ifdef MAIN_OLDMAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("002");
	#endif
	#endif
		kjx_socket_session_free();
		StartTimer(KJX_TIMER_ID_LOGIN_AGAIN, 15*1000, g_kjx_socket_event_func.socket_login_again);
    }
    else if(socketConnet)
    {
    	checkNet = 0;
    }
}

void kjx_oldman_gprs_recvbuf_parse(kal_int32 len)
{
	kjx_gprs_recvbuf_parse(len);
}

/***********************************************************************************/
/***********************************************************************************/
void kjx_socket_send_connect(kal_int8 socket_id)
{

	//if(g_kjx_nvram_struct.workMode == 2)
	//return;
	
#if defined(__KJX_FUN_AGPS__)
	if(g_kjx_agps_socket_context.socket_id == socket_id)
	{	
	#ifdef MAIN_OLDMAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("001");
	#endif
	#endif
		kjx_agps_socket_connect_ublox();
		return;
	}
#endif

	if(g_kjx_socket_context.socket_id == socket_id)
	{
	#ifdef MAIN_OLDMAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("002");
	#endif
	#endif
		kjx_oldman_socket_send_heartbeat();
	}
	else
	{
	#ifdef MAIN_OLDMAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("003");
	#endif
	#endif
	}
}

void kjx_oldman_func_init(void)
{
	g_socket_notify_func.socket_notify_connect = kjx_socket_send_connect;
	g_kjx_socket_event_func.recvbuf_hex_to_acsii = kjx_oldman_gprs_recvbuf_parse;
   	g_kjx_socket_event_func.socket_send_gps = kjx_oldman_socket_send_gps_data;
   #ifdef __KJX_FUN_GPS__
	g_kjx_gps_func.gps_do_something_with_custom = kjx_oldman_do_something_with_custom;
   #endif

}

void kjx_func_custom_init(void)
{
#ifdef MAIN_OLDMAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	g_kjx_main_func.kjx_check_fun = kjx_oldman_check_do_somthing;
	g_kjx_main_func.kjx_main_custom = kjx_func_main_oldman;
	//g_kjx_main_func.kjx_set_move_status = kjx_oldman_set_move_status;
	g_kjx_main_func.sms_out_area_alarm = kjx_oldman_send_sms_out_area_alarm;
	g_kjx_main_func.sms_in_area_alarm = kjx_oldman_send_sms_in_area_alarm;
	g_kjx_main_func.call_area_alarm = kjx_oldman_send_call_area_alarm;
}

#ifdef __KJX_MMI_SHOW_VER_IMEI__
char* kjx_oldman_get_verno(void)
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
char* kjx_oldman_get_date(void)
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
	
	/*#ifdef __KJX_FUN_GPS__
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
	if(kjx_gprs_is_connect_check()&&!kjx_gprs_is_connect())
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
	}*/
}

char* kjx_oldman_get_kjx_ver(void)
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
#ifdef MAIN_OLDMAIN_DEBUG
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
	#ifdef MAIN_OLDMAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("socket_send=%d", socket_send);
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
#ifdef MAIN_OLDMAIN_DEBUG
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
		return;
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
	kjx_sms_send_sms("15099939090", (U16 *)sendUcs, 0x08, NULL);

}

BOOL kjx_imei_is_valid(void)
{
	//设备编码无效，设备将不能正常工作！
	if(strlen(kjxImei)<14)
	{
	#ifdef MAIN_OLDMAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return false");
	#endif
	#endif
		return FALSE;
	}
#ifdef MAIN_OLDMAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("return true");
#endif
#endif
	return TRUE;
}

void kjx_func_main_oldman(void)
{
	g_kjx_nvram_struct.callMode = 1;//监听通话
    
#if defined(__KJX_FUN_GPS__)
	/*开启GPS*/
	if(g_gps_init == 0)
	{
		g_gps_init = 1;
		kjx_gps_main();
	}
#endif
  
	/*获取IMEI*/
	kjx_get_imei();

	/*SOCLET 联网*/
	kjx_socket_main();

	/*函数初始化*/
	kjx_oldman_func_init();

#if defined(__KJX_FUN_SENSOR__)
	/*开启SENSOR*/
	//kjx_sensor_main();
#endif

	StartTimer(KJX_TIMER_ID_SET_MAINLCD, 1000*15,kjx_main_lcd_set_level_0);

	if(kjx_check_shut_down())
	{/*重启*/
		//StartTimer(KJX_TIMER_ID_END, 1000*60,kjx_send_sms_to_my_phone);
	}

}
#endif
#endif/*__KJX_FUN__*/

