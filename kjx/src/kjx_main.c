/**********************************************************************************
*Filename:     kjx_main.c
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2013/12/17
*
***********************************************************************************/
#if defined(__KJX_FUN__)

/****************************************************************************
* Include Files 						包含头文件
*****************************************************************************/
#include "kjx_include.h"
#include "Kjx_prin.h"
#include "EventsGprot_Int.h"
#include "chr_parameter.h"
#include "Mmi_rp_app_kjx_def.h"
#include "ProfilesSrvGprot.h"
#include "Resource_audio.h"
#include "ImeiSrvGprot.h"
#include "custom_hw_default.h"
#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#if 1	//xb test
#include "..\\..\\custom\\drv\\Press_sensor\\MSP880_driver\\st_bas_msp880.h"
#endif
/*****************************************************************************
 *	Define					宏定义
*****************************************************************************/
#define BAT_VOL_COMPARE_MAX	Battery_Level_Info[6]
#define BAT_VOL_COMPARE_MIN	Battery_Level_Info[2]
#define DOG_WAVE_GPIO  	13
#define CHECK_BAT_MAX	6

#ifdef __BOSCH_BMP280_PRESSURE__
#define PA_TO_TORR		133.321995
#define SEALEVEL_PA	101325.0f
#endif

/*****************************************************************************
*	Enum					枚举类型定义
*****************************************************************************/
	
/*****************************************************************************
 *	Struct					数据结构定义
 *****************************************************************************/
	
/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/
#if defined(__KJX_MULTI_LANGUAGE__)
kjx_language_struct kjx_language[KJX_LANGUAGE_MAX] = 
			{
				{LANG_CHN,			"CHN\\"},			//中文普通话
				{LANG_ENGLISH,		"ENGLISH\\"},		//英
				{LANG_FRENCH,		"FRENCH\\"},		//法
				{LANG_GERMAN,		"GERMAN\\"},		//德
				{LANG_ITALIAN,		"ITALIAN\\"},		//意大利
				{LANG_SPANISH,		"SPANISH\\"},		//西班牙
				{LANG_PORTUGUESE,	"PORTUGUESE\\"},	//葡萄牙
				{LANG_POLISH,		"POLISH\\"},		//波兰
				{LANG_DANISH,		"DANISH\\"},		//丹麦
				{LANG_SWEDISH,		"SWEDISH\\"},		//瑞典
				{LANG_NORWEGIAN,	"NORWEGIAN\\"},		//挪威
				{LANG_FINNISH,		"FINNISH\\"},		//芬兰
				{LANG_DUTCH,		"DUTCH\\"},			//荷兰
				{LANG_UKRAINIAN,	"UKRAINIAN\\"},		//乌克兰
				{LANG_RUSSIAN,		"RUSSIAN\\"},		//俄罗斯
				{LANG_GREEK,		"GREEK\\"},			//希腊
				{LANG_TURKISH,		"TURKISH\\"},		//土耳其
				{LANG_ARABIC,		"ARABIC\\"},		//阿拉伯
				{LANG_HEBREW,		"HEBREW\\"},		//希伯来语(以色列)
				{LANG_PERSIAN,		"PERSIAN\\"},		//波斯语(伊朗)
				{LANG_URDU,			"URDU\\"},			//乌尔都语(巴基斯坦)
				{LANG_HINDI,		"HINDI\\"},			//印地语(印度)
				{LANG_BENGALI,		"BENGALI\\"},		//孟加拉
				{LANG_LAO,			"LAO\\"},			//老挝
				{LANG_KHMER,		"KHMER\\"},			//高棉语(柬埔寨)
				{LANG_MYANMAR,		"MYANMAR\\"},		//缅甸
				{LANG_VIETNAMESE,	"VIETNAMESE\\"},	//越南
				{LANG_INDONESIAN,	"INDONESIAN\\"},	//印度尼西亚
				{LANG_MALAY,		"MALAY\\"},			//马来语(马来西亚,文莱)
				{LANG_THAI,			"THAI\\"},			//泰国
				{LANG_FILIPINO,		"FILIPINO\\"},		//菲律宾语
				{LANG_CHN_SC,		"CHN_SC\\"},		//中文四川话
				{LANG_CHN_GD,		"CHN_GD\\"},		//中文广东话
				{LANG_CHN_MN,		"CHN_MN\\"},		//中文闽南话
				{LANG_CHN_XZ,		"CHN_XZ\\"},		//中文藏语
				{LANG_CHN_XZ_LASA,		"CHN_XZ_LASA\\"},		//中文藏语拉萨
				{LANG_CHN_XZ_ANDUO,		"CHN_XZ_ANDUO\\"},		//中文藏语安多
				{LANG_CHN_XZ_KANGBA,	"CHN_XZ_KANGBA\\"},		//中文藏语康巴
				{LANG_CHN_EXTRA,	"CHN_EXTRA\\"},		//中文其他方言
				{LANG_KOREAN,		"KOREAN\\"},		//朝鲜语(朝鲜,韩国)
				{LANG_JAPANESE,		"JAPANESE\\"},		//日本
			};
#endif

/****************************************************************************
* Global Variable           	全局变量
*****************************************************************************/
BOOL g_kjx_time_sync = FALSE;

#if defined(__KJX_MULTI_LANGUAGE__)
U8 g_kjx_language_index = 0;
U8 g_kjx_language_count = 0;
U8 g_kjx_language_sum[KJX_LANGUAGE_MAX] = {LANG_MAX};
U8 g_kjx_language = LANG_CHN;
#endif

#ifdef __BOSCH_BMP280_PRESSURE__
MSP880_Press_Typedef kjx_Press_Structure = {0};
MSP880_Temperature_Typedef kjx_Temperature_Structure = {0};

BOOL g_kjx_pressure_inited = FALSE;
float g_kjx_temp = 0;
float g_kjx_press = 0;
float g_kjx_mmHg = 0;
float g_kjx_altitude = 0;
#endif

#if defined(__KJX_FUN_STEPS__)
S32 steps_count = 0;
int steps_x_data=0;
int steps_y_data=0;
int steps_z_data=0;

#if defined(__MOTION_SENSOR_MC3451_SUPPORT__)
U32 g_kjx_sensor_shake = 0;
U32 g_kjx_sensro_step = 0;
#endif

typedef struct
{
	int16 value_x;
	int16 value_y;
	int16 value_z;
}kjx_gsensor_value;

kjx_gsensor_value g_kjx_gsensor_value;

#endif/*__KJX_FUN_STEPS__*/

U8 battery_percentage = 0;
U8 QueryCommandState = 0;    /*0:SMS  1:ONLINE 2:AT */   //CommandState   QueryCommandState
BOOL HaveGetIMSI = FALSE;
BOOL EntryTestModeReady = FALSE;  /*是否能进入测试模式*/

kjx_socket_context g_kjx_socket_context;
kjx_lbs_info_struct g_kjx_lbs_info_struct;
kjx_main_func g_kjx_main_func;

#ifdef WIN32
kal_uint8 IMEIBuffer[SRV_IMEI_MAX_LEN + 1] = "358626020147641";    //358626020147641  /*用于后台登陆*/
kal_uint8 IMSIBuffer[SRV_MAX_IMSI_LEN + 1] = "460000330936372";             /*用于判断防盗抢*/ 
#else
kal_uint8 IMEIBuffer[SRV_IMEI_MAX_LEN + 1] = {0};    //358626020147641  /*用于后台登陆*/
kal_uint8 IMSIBuffer[SRV_MAX_IMSI_LEN + 1] = {0};             /*用于判断防盗抢*/
#endif

U8 kjxImei[SRV_IMEI_MAX_LEN + 1] = {0};
U8 StartHour1=0,StartMin1=0,EndHour1=0,EndMin1=0,StartHour2=0,StartMin2=0,EndHour2=0,EndMin2=0;
#if defined(__KJX_NBR_CELL__)
kjx_nbr_cell_info_struct* kjx_nbr_cur_cell_info = NULL;
kjx_nbr_cell_info_struct* s_kjx_nbr_cell_info[KJX_CELL_NBR_MAX] = {NULL,NULL,NULL,NULL,NULL,NULL};
int s_kjx_cell_nbr_num = 0;
#endif

#if defined(__KJX_SOC_APP__) 
nvram_ef_tracker_apn_param_struct tracker_apn_param = {0}; 
nvram_ef_tracker_server_param_struct tracker_server_param = {0}; 
#endif

int g_kjx_find_device = 0;

WCHAR dj_chanle_show[128] = {0};

#if defined(__BOSCH_BMP280_PRESSURE__)
WCHAR Temp_show[128] = {0};
WCHAR Altitude_show[128] = {0};
#endif

#if defined(__KJX_FUN_STEPS__)
WCHAR Step_show[128] = {0};
WCHAR Calorie_show[128] = {0};
#endif

U8 g_kjx_titlestr[256] = {0};

/****************************************************************************
* Global Variable - Extern			引用全局变量
*****************************************************************************/
#ifdef __BLE_MODULE_SUPPORT__
extern S8 g_kjx_ble_rssi;
#endif

extern BOOL PhoneTestMode ; 		/*判断是否处于测试模式*/
extern BOOL hadRead;

#if defined(__KJX_AGAINST_THEFT__)
extern kal_bool g_rfid_against_theft;
#endif

#if defined(__KJX_FUN_STEPS__)
extern BOOL steps_is_use;
#endif

#ifdef __BOSCH_BMP280_PRESSURE__
extern int g_start_pressure;
#endif

#if defined(__KJX_POSITION_TRIGGER_PLAY__)
extern U8 g_play_cause;
#endif

#if defined(CUSTOMER_NAME_MEGE2)
extern U8 kjxIccid[64];
extern U8 kjxPhoneNum[64];
static int KJX_NUM_MAX = 5005;
extern kjx_numtotal g_kjx_numTotal[];
#endif

extern UI_string_type kjx_scrolling_show[512];

#ifdef __KJX_FUN_GPS__
extern kjx_gps_data g_kjx_gps_data;
extern kjx_gps_func g_kjx_gps_func;
extern kjx_gps_info_string gps_info_string;
extern kjx_pos_gps_info_string g_kjx_gps_info_string;
#endif

extern nvram_ef_kjx_nvram_struct g_kjx_nvram_struct;
extern class_time_struct tClassTime[];
extern charbat_context_struct g_charbat_context;
extern kjx_socket_event_func g_kjx_socket_event_func;

#ifdef __KJX_WEATHER_SUPPORT__
extern kjx_weather_struct kjx_weather;
#endif
/*****************************************************************************
*	Global Functions	- Extern		引用外部函数
*****************************************************************************/
extern void mmi_show_scrolling_infor(void);
#ifdef __BLE_MODULE_SUPPORT__
extern void ble_mod_power_on(void);
extern void ble_mod_power_off(void);
#endif
extern void Kjx_Redraw_Temperature_Pressure(void);
#ifdef __BOSCH_BMP280_PRESSURE__
extern void kjx_factory_pressure_test_end(void);
#endif

#ifdef __KJX_WEATHER_SUPPORT__
extern void kjx_redraw_weather_image(void);
extern void kjx_redraw_weather_temp(void);
#endif

#if defined(__KJX_FUN_STEPS__)
extern void Kjx_Show_Step_And_Calorie(void);
extern void Kjx_Show_Calorie(void);
#endif
extern void update_main_LCD_date_time(void);

/*****************************************************************************
*	Local Functions 		本地函数
******************************************************************************/
static void kjx_sensor_get_step(void);
void kjx_get_imei(void);
void kjx_get_imsi(void);

/*****************************************************************************
*	Local Functions 		全局函数
*****************************************************************************/
void kjx_func_null(void)
{
#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
	if((g_kjx_gps_data.data_status == 'A') && (kjx_get_foctory_test_mode() == 1) && (kjx_get_test_mode_gps_start()==1))
	{
	#ifdef MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("001");
	#endif
	#endif

		kjx_factory_gps_end();
	}
}

void kjx_restart(void)
{
	DCL_HANDLE dcl_wdt_handle; 

	dcl_wdt_handle=DclWDT_Open(DCL_WDT, 0);
	DclWDT_Control(dcl_wdt_handle, WDT_CMD_ABN_RESET, 0);    
	DclWDT_Close(dcl_wdt_handle);
}

U16 kjx_is_in_call(void)
{
	if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
		return 1;
	else
		return 0;
}

U16 kjx_is_incoming_call(void)
{
	if(srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
		return 1;
	else
		return 0;
}

U16 kjx_is_outing_call(void)
{
	if(srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 )
		return 1;
	else
		return 0;
}
/******* Delay a lTime uSec ********/
void delay_uSec(uint16 delay)
{
   kal_uint32 curr_frc, latest_us;

   curr_frc = ust_get_current_time();//unit: micro second (us)
   do{
      latest_us = ust_get_current_time();;
   }while(delay > ust_get_duration(curr_frc, latest_us));
}

void kjx_set_gsm_led(U16 led_type)
{
	if(g_kjx_main_func.kjx_set_gsm_led != NULL)
	{
		g_kjx_main_func.kjx_set_gsm_led(led_type);
	}
}

#if defined(__KJX_FUN_SENSOR__)
void kjx_sensor_get_shake(void)
{
#if defined(__MOTION_SENSOR_MC3451_SUPPORT__)
	is_motion_sensor_shake();
#endif

	StartTimer(KJX_TIMER_ID_SENSOR_CHECK_SHAKE, 1000, kjx_sensor_get_shake); 
}


#if defined(__KJX_FUN_STEPS__)
int kjx_steps_teller_total(void)
{
	if(steps_count>999)
	{
		steps_count = 0;
	}
	return steps_count;
}

void kjx_sensor_get_step(void)
{
	char tmpbuf[128]= {0};
	char strbuf[128] = {0};

#if defined(__MOTION_SENSOR_MC3451_SUPPORT__)
	mmi_mc3451_get_pedometer_data();
#endif

#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	//LOGD("g_kjx_sensro_step:%d", g_kjx_sensro_step);
#endif
#endif

	if(mmi_idle_is_active()&&srv_bootup_is_launched())
	{
		//计步
		mmi_ucs2cpy((CHAR*)Step_show, (CHAR*)GetString(STR_KJX_IDLE_STEP));
		sprintf(tmpbuf, "%d STEP", g_kjx_sensro_step);
		mmi_asc_to_ucs2((S8*)strbuf, (S8*)tmpbuf);
		mmi_ucs2cat((CHAR*)Step_show, (CHAR*)strbuf);

		memset(tmpbuf, 0, sizeof(tmpbuf));
		memset(strbuf, 0, sizeof(strbuf));

		//卡路里(100大卡热量≈走2000步)
		mmi_ucs2cpy((CHAR*)Calorie_show, (CHAR*)GetString(STR_KJX_IDLE_CALORIE));
		sprintf(tmpbuf, "%d CAL", g_kjx_sensro_step/20);
		mmi_asc_to_ucs2((S8*)strbuf, (S8*)tmpbuf);
		mmi_ucs2cat((CHAR*)Calorie_show, (CHAR*)strbuf);
		
		Kjx_Show_Step_And_Calorie();
	}

	StartTimer(KJX_TIMER_ID_SENSOR_CHECK_STEP, 1000, kjx_sensor_get_step); 
}
#endif/*__KJX_FUN_STEPS__*/

void kjx_sensor_init(void)
{
	GPIO_ModeSetup(81,0);
	GPIO_InitIO(1,81);
	GPIO_WriteIO(0,81);
}

void kjx_sensor_main(void)
{
#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
    
#if defined(__MOTION_SENSOR_MMA8452Q_SUPPORT__)
	kjx_sensor_func_init();
	acc_mag_sensor_start();
#endif

#if defined(__MOTION_SENSOR_MC3413_SUPPORT__)
	kjx_sensor_mc3413();
	kjx_sensor_entry_timer();
#endif

#if defined(__MOTION_SENSOR_MC3451_SUPPORT__)
	acc_sensor_init();
	kjx_sensor_init();

	//StartTimer(KJX_TIMER_ID_SENSOR_CHECK_SHAKE, 500, kjx_sensor_get_shake);
#ifdef __KJX_FUN_STEPS__	
	StartTimer(KJX_TIMER_ID_SENSOR_CHECK_STEP, 1000, kjx_sensor_get_step); 
#endif
#endif
}

void kjx_sensor_reset(void)
{
	if(IsMyTimerExist(KJX_TIMER_ID_SENSOR_INIT))
		StopTimer(KJX_TIMER_ID_SENSOR_INIT);
	if(IsMyTimerExist(KJX_TIMER_ID_SENSOR_CHECK_SHAKE))
		StopTimer(KJX_TIMER_ID_SENSOR_CHECK_SHAKE);
	if(IsMyTimerExist(KJX_TIMER_ID_SENSOR_CHECK_STEP))
		StopTimer(KJX_TIMER_ID_SENSOR_CHECK_STEP);

#if defined(__MOTION_SENSOR_MC3451_SUPPORT__)	
	motion_acc_sensor_reset_pedometer();
#endif

	StartTimer(KJX_TIMER_ID_SENSOR_INIT, 2000, kjx_sensor_main);
}

#endif/*__KJX_FUN_SENSOR__*/

#ifdef __KJX_WEATHER_SUPPORT__
//http://api.map.baidu.com/images/weather/day/duoyun.png
void kjx_get_image_name_from_url(U8 *picname, U8 *picurl)
{
	U8 i;
	U8 *ptr,*p1,*p2;

	if(picname == NULL || picurl == NULL)
		return;

	p1 = NULL;
	ptr = picurl;
	while(1)
	{
		p1 = strstr(ptr+1, "/");
		if(p1 == NULL)
			break;
		ptr = p1;
	}
	
	ptr++;
	strcpy(picname,ptr);
#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("picname 001:%s", picname);
#endif
#endif

	for(i=0;i<strlen(picname);i++)
	{
		if(picname[i] >= 'a' && picname[i] <= 'z')
			picname[i] -= 32;
		if(picname[i] == '.')
		{
			picname[i]  = 0;
			picname[i+1] = 0;
		}
	}

#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("picname 002:%s", picname);
#endif
#endif
}

void Kjx_Redraw_Weather(void)
{
	char tmpbuf[128]= {0};
	char strbuf[128] = {0};

	if(mmi_idle_is_active()&&srv_bootup_is_launched())
	{
		SetIdleScreenSlaveNetworkName(NULL);

		mmi_ucs2cpy((CHAR*)Temp_show, (CHAR*)GetString(STR_KJX_IDLE_TEMPERATURE));
		mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char*)kjx_weather.temperatrue, (char*)strbuf, sizeof(strbuf));
		mmi_ucs2cat((CHAR*)Temp_show, (CHAR*)strbuf);
		SetIdleScreenSlaveNetworkStatus((U8*)Temp_show);

		kjx_redraw_weather_image();//天气图标
		kjx_redraw_weather_temp();//温度描述
	}
	else
	{
		StartTimer(KJX_TIMER_ID_BOSCH_GENSOR_READ, 1*1000, Kjx_Redraw_Weather);
	}
}
#endif

#ifdef __BOSCH_BMP280_PRESSURE__
void BOSCH_BMP280_get_data(void)
{
#if 0	//xb test
	MSP880_Press_Typedef *ptr_Press = NULL;
	MSP880_Temperature_Typedef *ptr_Temperature = NULL;

	kal_int32 v_actual_temp;
	kal_uint32 v_actual_press;
	double result;
	char tmpbuf[128]= {0};
	char strbuf[128] = {0};

	StopTimer(KJX_TIMER_ID_BOSCH_GENSOR_READ);

	ptr_Press = &kjx_Press_Structure;
	ptr_Temperature = &kjx_Temperature_Structure;
	ST_USER_GetTemperatureParam(ptr_Temperature);
	ST_USER_GetPressParam(ptr_Press);
	MSP880_Para_Calculate(ptr_Press, ptr_Temperature);

	g_kjx_temp = ptr_Temperature->Temperature[ptr_Temperature->Cnt];
	g_kjx_press = ptr_Press->Press[ptr_Press->Cnt];
	g_kjx_altitude = ptr_Press->Height[ptr_Press->Cnt];

#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("Temperature: %.2fC; Pressure:%.2fPa; altitude:%.2fM\n", g_kjx_temp, g_kjx_press, g_kjx_altitude);
#endif
#endif

	if(mmi_idle_is_active()&&srv_bootup_is_launched())
	{
		mmi_ucs2cpy((CHAR*)Temp_show, (CHAR*)GetString(STR_KJX_IDLE_TEMPERATURE));
		sprintf(tmpbuf, "%.2f C", g_kjx_temp);
		mmi_asc_to_ucs2((S8*)strbuf, (S8*)tmpbuf);
		mmi_ucs2cat((CHAR*)Temp_show, (CHAR*)strbuf);
		SetIdleScreenSlaveNetworkName((U8 *)Temp_show);
	
		mmi_ucs2cpy((CHAR*)Altitude_show, (CHAR*)GetString(STR_KJX_IDLE_ALTITUDE));
		sprintf(tmpbuf, "%.2f M", g_kjx_altitude);
		mmi_asc_to_ucs2((S8*)strbuf, (S8*)tmpbuf);
		mmi_ucs2cat((CHAR*)Altitude_show, (CHAR*)strbuf);
		SetIdleScreenSlaveNetworkStatus((U8 *)Altitude_show);
	
		Kjx_Redraw_Temperature_Pressure();
	}
#else
	kal_int32 v_actual_temp;
	kal_uint32 v_actual_press;
	double result;
	char tmpbuf[128]= {0};
	char strbuf[128] = {0};

	StopTimer(KJX_TIMER_ID_BOSCH_GENSOR_READ);

  #if 0
	v_actual_temp = FBM320_ReadTemperature(); //fbm320
	v_actual_press = FBM320_ReadPressure();   //fbm320
  #else
	v_actual_temp = BMP280_ReadTemperature();
	v_actual_press = BMP280_ReadPressure();
  #endif
  
	g_kjx_temp = (float)v_actual_temp;
	g_kjx_press = (float)v_actual_press;
	g_kjx_mmHg = g_kjx_press/PA_TO_TORR;
	g_kjx_altitude = 44330000*(1.0 - (double)pow(g_kjx_press/SEALEVEL_PA, (float)(1.0/5255.0)));

#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	//LOGD("Temperature: %d.%dC; Pressure:%dPa; altitude:%.2fM\n", v_actual_temp/100, abs(v_actual_temp)%100, v_actual_press, g_kjx_altitude);
#endif
#endif

	if(mmi_idle_is_active()&&srv_bootup_is_launched())
	{
		//温度
		mmi_ucs2cpy((CHAR*)Temp_show, (CHAR*)GetString(STR_KJX_IDLE_TEMPERATURE));
		sprintf(tmpbuf, "%d C", v_actual_temp/100);
		mmi_asc_to_ucs2((S8*)strbuf, (S8*)tmpbuf);
		mmi_ucs2cat((CHAR*)Temp_show, (CHAR*)strbuf);

		memset(tmpbuf, 0, sizeof(tmpbuf));
		memset(strbuf, 0, sizeof(strbuf));

		//海拔
		mmi_ucs2cpy((CHAR*)Altitude_show, (CHAR*)GetString(STR_KJX_IDLE_ALTITUDE));
		sprintf(tmpbuf, "%d M", (U32)g_kjx_altitude);
		mmi_asc_to_ucs2((S8*)strbuf, (S8*)tmpbuf);
		mmi_ucs2cat((CHAR*)Altitude_show, (CHAR*)strbuf);

		Kjx_Show_Temperature_And_Altitude();
	}
#endif

	if((g_start_pressure == 1)&&(kjx_get_foctory_test_mode() == 1))
	{
		g_start_pressure = 0;
		StartTimer(KJX_TIMER_ID_FACTORY_TEST, 1000*3, kjx_factory_pressure_test_end);
	}
	StartTimer(KJX_TIMER_ID_BOSCH_GENSOR_READ, 5*1000, BOSCH_BMP280_get_data);
}

void BOSCH_BMP280_sensor_init(void)
{
	kal_int8 com_rslt;
	unsigned int temp,press;

	if(g_kjx_pressure_inited == FALSE)
	{
	#if 0	//xb test
		MSP880_Configuration();
		g_kjx_pressure_inited = TRUE;
		StartTimer(KJX_TIMER_ID_BOSCH_GENSOR_READ, 2*1000, BOSCH_BMP280_get_data);
	#else
	  #if 0
		fbm320_i2c_udelay(50); //fbm320
		com_rslt = FBM320_Begin(); //fbm320
	  #else
		bmp280_set_soft_rst();
		bmp280_i2c_udelay(50);
		com_rslt = BMP280_Begin();
	  #endif
		if(com_rslt >= 0)
		{
			g_kjx_pressure_inited = TRUE;
			StartTimer(KJX_TIMER_ID_BOSCH_GENSOR_READ, 2*1000, BOSCH_BMP280_get_data);
		}
		else
		{
			StartTimer(KJX_TIMER_ID_BOSCH_GENSOR_READ, 2*1000, BOSCH_BMP280_sensor_init);
		}
	#endif
	}

#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("com_rslt:%d", com_rslt);
#endif
#endif
}
#endif

void kjx_func_init(void)
{
#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

#ifdef __KJX_WEATHER_SUPPORT__

#elif defined(__BOSCH_BMP280_PRESSURE__)
	BOSCH_BMP280_sensor_init();
#endif

	kjx_socket_init();
#if defined(__KJX_FUN_AGPS__)	//xb add 2018-08-27 防止联网notify消息被agps的socket错误接收处理
	kjx_agps_socket_init();
#endif

	kjx_socket_ipaddr_init();
	kjx_socket_func_init();
	
	kjx_func_custom_init();

#ifdef __KJX_FAST_KEY_HANDLER__
	kjx_fast_key_handler_init();
#endif
}

void kjx_stop_ring_tone(void)
{
#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
    StopTimer(KJX_TIMER_ID_FIND_DEVICE);

    srv_prof_stop_tone(SRV_PROF_TONE_INCOMING_CALL);
    g_kjx_find_device = 0;

#if defined(__KJX_RFID_PLAY_CONTINUE_AGAIN__)	//xb add 2016-08-24	寻设备结束后恢复前面被中断的RFID播放
	{
		extern U8 kjx_audio_status;
		extern BOOL kjx_rfid_is_in_play(void);
		extern void kjx_rfid_continue_play_audio(void);

	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("kjx_audio_status:%d", kjx_audio_status);
	#endif		
		if(kjx_rfid_is_in_play() && (kjx_audio_status == 3))
		{
			kjx_rfid_continue_play_audio();
		}
	}
#endif	
}

void kjx_find_device(void)
{
#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

#if defined(__KJX_AGAINST_THEFT__)
	if(g_rfid_against_theft)
	{
	#ifdef MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("报警状态，不接受设备查找");
	#endif
	#endif
	
		return;
	}
#endif

    srv_prof_play_tone_with_id(
            SRV_PROF_TONE_INCOMING_CALL,
            7804,
            SRV_PROF_RING_TYPE_REPEAT,
            NULL);

    g_kjx_find_device = 1;
	
    StartTimer(KJX_TIMER_ID_FIND_DEVICE, 60*1000, kjx_stop_ring_tone);
}

void kjx_set_sys_date_time(BOOL is_gps_time)
{
    applib_time_struct utc_time;
    applib_time_struct rtc_time;
	applib_time_struct inc_time;
    kal_int16 tYear;
    kal_int8 tMonth;
    kal_int8 tDay;
    kal_int8 tHour;
    kal_int8 tMin;
    kal_int8 tSec;
	int i = 0;
	char dateStr[20];
	char tYearStr[8];
	char tMonthStr[8];
	char tDayStr[8];
	char tHourStr[8];
	char tMinStr[8];	
	char tSecStr[8];	
	char timeStr[20];
	static U16 dateTimeSave = 0;

	if(dateTimeSave == 1)
		return;

	for(i=0;i<2;i++)
	{
		switch(i)
		{
		case 0:  //  日期
			memset(dateStr,0x00,sizeof(dateStr));	
			memset(tYearStr,0x00,sizeof(tYearStr));
			memset(tMonthStr,0x00,sizeof(tMonthStr));
			memset(tDayStr,0x00,sizeof(tDayStr));

			memcpy(dateStr,g_kjx_nvram_struct.dateTime[i],strlen(g_kjx_nvram_struct.dateTime[i]));

			memcpy(tYearStr,dateStr,4);  // 年
			tYear = ((kal_int16)atoi(tYearStr));
			
			memcpy(tMonthStr,dateStr+strlen(tYearStr),2);	 // 月
			tMonth = ((kal_int8)atoi(tMonthStr));
			
			memcpy(tDayStr,dateStr+strlen(tYearStr)+strlen(tMonthStr),2);	 // 日
			tDay = ((kal_int8)atoi(tDayStr));
			break;

		case 1:  //  时间
			memset(timeStr,0x00,sizeof(timeStr));
			memset(tHourStr,0x00,sizeof(tHourStr));
			memset(tMinStr,0x00,sizeof(tMinStr));
			
			memcpy(timeStr,g_kjx_nvram_struct.dateTime[i],strlen(g_kjx_nvram_struct.dateTime[i]));

			memcpy(tHourStr,timeStr,2);  // 小时
			tHour = ((kal_int8)atoi(tHourStr));
			
			memcpy(tMinStr,timeStr+strlen(tHourStr),2);	 // 分钟
			tMin = ((kal_int8)atoi(tMinStr));
            
			memcpy(tSecStr,timeStr+strlen(tHourStr)+strlen(tMinStr),2);	 // 秒
			tSec= ((kal_int8)atoi(tSecStr));
			break;

		default:
			break;
		}
	}
	
	utc_time.nYear = tYear;
	utc_time.nMonth = tMonth;
	utc_time.nDay = tDay;
	utc_time.nHour = tHour;
	utc_time.nMin = tMin;
	utc_time.nSec = tSec;

	if(applib_dt_is_valid(&utc_time))
	{
		memset(&inc_time, 0, sizeof(applib_time_struct));
		inc_time.nHour = 8;//xb add 2018-09-06 后台下发的是北京时间(东八区)
		applib_dt_decrease_time(&utc_time, &inc_time, &utc_time);

	    applib_dt_utc_to_rtc_with_default_tz(&utc_time, &rtc_time);
	    mmi_dt_set_rtc_dt((MYTIME *)&rtc_time);

		dateTimeSave = 1;

		if(g_kjx_time_sync == FALSE)
			g_kjx_time_sync = TRUE;
	}
}

void kjx_agps_request(void)
{
#if defined(__KJX_FUN_AGPS__)
     kjx_ublox_agps_request();
#endif
}

/*以整数表示的百分比*/
U8 kjx_sys_get_cur_gsm_status(void)
{
    U8 temp = 0;
    temp = srv_nw_info_get_signal_strength_in_percentage(MMI_SIM1);
    return temp;
}

int KJX_FUNC_COUNTRY_ID=0;

void kjx_set_country_tag_sim1(char* imsi_mcc)
{
#ifdef __KJX_BRAZIL__
	if(!memcmp(imsi_mcc,"724", 3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_Brazil;
	}
	else 
#endif
#ifdef __KJX_MALAYSIA__
	if(!memcmp(imsi_mcc,"502", 3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_Malaysia;
	}
	else
#endif
#ifdef __KJX_THAI__
	if(!memcmp(imsi_mcc,"520", 3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_Thai;
	}
	else
#endif
#ifdef __KJX_INDONESIA__
	if(!memcmp(imsi_mcc,"510", 3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_Indonesia;
	}
	else
#endif
#ifdef __KJX_VIETNAME__
	if(!memcmp(imsi_mcc,"452", 3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_Vietnamese;
	}
	else
#endif

#ifdef __KJX_TURKEY__   //土耳其
	if(!memcmp(imsi_mcc,"286", 3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_Turkey;
	}
	else
#endif

#ifdef __KJX_ARGENTINA__     //阿根廷
	if(!memcmp(imsi_mcc,"722", 3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_Argentina;
	}
	else
#endif

#ifdef __KJX_EGYPT__   //埃及
	if(!memcmp(imsi_mcc,"602",3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_Egypt;
	}
	else
#endif

#ifdef __KJX_RUSSIA__  //俄罗斯
	if(!memcmp(imsi_mcc,"250",3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_Russia;
	}
	else
#endif

#ifdef __KJX_COLOMBIA__     //哥伦比亚
	if(!memcmp(imsi_mcc,"732",3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_Colombia;
	}
	else
#endif

#ifdef __KJX_KAZAKHSTAN__    //哈萨克斯坦
	if(!memcmp(imsi_mcc,"401",3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_Kazakhstan;
	}
	else
#endif

#ifdef __KJX_PERU__    // 秘鲁
	if(!memcmp(imsi_mcc,"716",3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_Peru;
	}
	else
#endif

#ifdef __KJX_MEXICO__     //墨西哥
	if(!memcmp(imsi_mcc,"334",3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_MexicoMiu;
	}
	else
#endif

#ifdef __KJX_SOUTHAFRICA__    //南非
	if(!memcmp(imsi_mcc,"655",3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_Southafrica;
	}
	else
#endif

#ifdef __KJX_NIGERIA__ 	   //尼日利亚
	if(!memcmp(imsi_mcc,"621",3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_Nigeria;
	}
	else
#endif

#ifdef __KJX_SAUDIARABIA__   //沙特阿拉伯
	if(!memcmp(imsi_mcc,"420",3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_SaudiarabiaMob;
	}
	else
#endif

#ifdef __KJX_VENEZUELA__      //委内瑞拉
	if(!memcmp(imsi_mcc,"734",3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_Venezuela;
	}
	else
#endif

#ifdef __KJX_UKRAINE__        //乌克兰
	if(!memcmp(imsi_mcc,"255",3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_Ukraine;
	}
	else
#endif

#ifdef __KJX_IRAQ__ 		  //伊拉克
	if(!memcmp(imsi_mcc,"418",3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_IraqAsia;
	}
	else
#endif

#ifdef __KJX_INDIA__ 		 //印度
	if(!memcmp(imsi_mcc,"404",3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_India;
	}
	else
	if(!memcmp(imsi_mcc,"405",3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_India2;
	}
	else
#endif

#ifdef __KJX_CHILE__ 		  //智利
	if(!memcmp(imsi_mcc,"730",3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_chile;
	}
	else
#endif

#ifdef __KJX_CHINA__
	if(!memcmp(imsi_mcc,"460", 3))
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_China;
	}
	else
#endif
	{
		KJX_FUNC_COUNTRY_ID=kjx_country_id_none;
	}
}

KJX_COUNTRY_ID_ENUM KjxGetCurLang(char* mcc)
{
	kjx_set_country_tag_sim1(mcc);
	return (KJX_COUNTRY_ID_ENUM)KJX_FUNC_COUNTRY_ID;
}

void KjxSetTemplateLanguage(KJX_COUNTRY_ID_ENUM langtype)
{
    extern sLanguageDetails *gLanguageArray;
    extern U16 gCurrLangIndex;
    U8 i = 0;
    S16 error;
    S8 tempLang[SSC_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tempLang, 0, SSC_SIZE);

#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("langtype:%d", langtype);
#endif
#endif	
    switch (langtype)
	{
	case kjx_country_id_none:
		memcpy(tempLang, SSC_ENGLISH, SSC_SIZE);
		break;

	case kjx_country_id_Brazil:
		memcpy(tempLang, SSC_PORTUGUESE, SSC_SIZE);
		break;

	case kjx_country_id_Malaysia:
		memcpy(tempLang, SSC_MALAY, SSC_SIZE);
		break;

	case kjx_country_id_Thai:
		memcpy(tempLang, SSC_THAI, SSC_SIZE);
		break;

	case kjx_country_id_Indonesia:
		memcpy(tempLang, SSC_INDONESIAN, SSC_SIZE);
		break;

	case kjx_country_id_Indonesia_xl:
		memcpy(tempLang, SSC_INDONESIAN, SSC_SIZE);
		break;

	case kjx_country_id_Vietnamese:
		memcpy(tempLang, SSC_VIETNAMESE, SSC_SIZE);
		break;

	case kjx_country_id_Turkey:           						 //土耳其
		memcpy(tempLang, SSC_TURKISH, SSC_SIZE);
		break;

	case kjx_country_id_Argentina:          					//阿根廷
		memcpy(tempLang, SSC_SPANISH, SSC_SIZE);
		break;

	case kjx_country_id_Egypt:                					//埃及
		memcpy(tempLang, SSC_ARABIC, SSC_SIZE);
		break;

	case kjx_country_id_Russia:            						 //俄罗斯
		memcpy(tempLang, SSC_RUSSIAN, SSC_SIZE);
		break;

	case kjx_country_id_Colombia:        					 //哥伦比亚
		memcpy(tempLang, SSC_SPANISH, SSC_SIZE);
		break;

	case kjx_country_id_Kazakhstan:     					 //哈萨克斯坦
		memcpy(tempLang, SSC_RUSSIAN, SSC_SIZE);
		break;

	case kjx_country_id_Peru:                					 //秘鲁
		memcpy(tempLang, SSC_SPANISH, SSC_SIZE);
		break;

	case kjx_country_id_MexicoMiu:      						  //墨西哥Movistar&Iusacell&Unefon
		memcpy(tempLang, SSC_SPANISH, SSC_SIZE);
		break;

	case kjx_country_id_MexicoTel:        					//墨西哥Telcel 		
		memcpy(tempLang, SSC_SPANISH, SSC_SIZE);
		break;

	case kjx_country_id_Southafrica:    						 //南非
		memcpy(tempLang, SSC_ENGLISH, SSC_SIZE);
		break;

	case kjx_country_id_Nigeria:           						 //尼日利亚
		memcpy(tempLang, SSC_ENGLISH, SSC_SIZE);
		break;

	case kjx_country_id_SaudiarabiaMob:    					 //沙特阿拉伯Mobily
		memcpy(tempLang, SSC_ARABIC, SSC_SIZE);
		break;

	case kjx_country_id_SaudiarabiaStc:      					//沙特阿拉伯 Stc
		memcpy(tempLang, SSC_ARABIC, SSC_SIZE);
		break;

	case kjx_country_id_SaudiarabiaZain:   					 //沙特阿拉伯Zain
		memcpy(tempLang, SSC_ARABIC, SSC_SIZE);
		break;

	case kjx_country_id_Venezuela:           					  //委内瑞拉
		memcpy(tempLang, SSC_SPANISH, SSC_SIZE);
		break;

	case kjx_country_id_Ukraine:               					 //乌克兰
		memcpy(tempLang, SSC_RUSSIAN, SSC_SIZE);
		break;

	case kjx_country_id_IraqAsia:           					   //伊拉克Asia
		memcpy(tempLang, SSC_ARABIC, SSC_SIZE);
		break;

	case kjx_country_id_IraqZain:              					 //伊拉克Zain
		memcpy(tempLang, SSC_ARABIC, SSC_SIZE);
		break;

	case kjx_country_id_India:                 					    //印度
		memcpy(tempLang, SSC_HINDI, SSC_SIZE);
		break;

	case kjx_country_id_India2:								//印度2
		memcpy(tempLang, SSC_HINDI, SSC_SIZE);
		break;

	case kjx_country_id_chile:                     						 //  智利
		memcpy(tempLang, SSC_SPANISH, SSC_SIZE);
		break;

	case kjx_country_id_China:
		memcpy(tempLang, SSC_SCHINESE, SSC_SIZE);
		break;

	default:
		memcpy(tempLang, SSC_ENGLISH, SSC_SIZE);
		break;
	}
	
#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("tempLang=%s", tempLang);
#endif
#endif
	
    for (i = 0; i < MAX_LANGUAGES; i++)
    {
        if (strcmp((PS8) gLanguageArray[i].aLangSSC, (S8*) tempLang) == 0)
        {
            if (gCurrLangIndex != i)
            {
                SetCurrentLanguage(i);
                /*WriteValue(NVRAM_SETTING_LANG, &i, DS_BYTE, &error);*/
                break;
            }
        }
    }
}


void kjx_set_phone_language(char* mcc)
{
	KJX_COUNTRY_ID_ENUM currLang;
	static BOOL is_setted = FALSE;

#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("is_setted:%d", is_setted);
#endif
#endif

	if(is_setted)
	{
		return;
	}

	if(!is_setted)
	{
		is_setted = TRUE;
	}
	
	currLang=KjxGetCurLang(mcc);
#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("currLang:%d", currLang);
#endif
#endif

	KjxSetTemplateLanguage(currLang);
}

void kjx_step_set_sleep_time(void)
{
	int i = 0;
	U8 startTime[16];
	U8 endTime[16];
	U8 startHour[16];
	U8 startMin[16];
	U8 endHour[16];
	U8 endMin[16];

	for(i=0;i<2;i++)
	{
		memset(startHour,0x00,sizeof(startHour));
		memset(startMin,0x00,sizeof(startMin));
		memset(endHour,0x00,sizeof(endHour));
		memset(endMin,0x00,sizeof(endMin));
		memset(startTime,0x00,sizeof(startTime));
		memset(endTime,0x00,sizeof(endTime));

		if(i==0)
		{
			if(strstr(g_kjx_nvram_struct.studyTime[i],"-"))
			{
				memcpy(startTime,g_kjx_nvram_struct.studyTime[i],4);
				memcpy(endTime,g_kjx_nvram_struct.studyTime[i]+strlen(startTime)+strlen("-"),4);

				memcpy(startHour,startTime,2);
				memcpy(startMin,startTime+strlen(startHour),2);
				memcpy(endHour,endTime,2);
				memcpy(endMin,endTime+strlen(endHour),2);

				StartHour1 = atoi(startHour);
				StartMin1= atoi(startMin);
				EndHour1= atoi(endHour);
				EndMin1= atoi(endMin);				
			}
		}

		if(i==1)
		{
			if(strstr(g_kjx_nvram_struct.studyTime[i],"-"))
			{
				memcpy(startTime,g_kjx_nvram_struct.studyTime[i],4);
				memcpy(endTime,g_kjx_nvram_struct.studyTime[i]+strlen(startTime)+strlen("-"),4);

				memcpy(startHour,startTime,2);
				memcpy(startMin,startTime+strlen(startHour),2);

				memcpy(endHour,endTime,2);
				memcpy(endMin,endTime+strlen(endHour),2);
				
				StartHour2 = atoi(startHour);
				StartMin2= atoi(startMin);
				EndHour2= atoi(endHour);
				EndMin2= atoi(endMin);				
			}
		}
	}

}

BOOL kjx_default_work_time_project(void)
{
	#if defined(CUSTOMER_NAME_BABY1)||defined(CUSTOMER_NAME_MEGE1)||defined(CUSTOMER_NAME_BDTS)
		return TRUE;
	#endif

	return FALSE;
}

//huzheng add
BOOL kjx_is_on_class_time(void)
{
    int i = 0;
    int t1,t2,tc;
    applib_time_struct currTime;

    memset(&currTime, 0x00, sizeof(currTime));
    applib_dt_get_rtc_time(&currTime);
    tc = currTime.nHour*60+currTime.nMin;
#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("studyMode=%d %d,%d",  g_kjx_nvram_struct.studyMode, currTime.nHour,currTime.nMin);
#endif
#endif
    if (g_kjx_nvram_struct.studyMode == 1)//免打扰模式开
    {
        for (i = 0; i<10; i++)
        {
        #ifdef MAIN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("%d,%d,%d,%d",  g_kjx_nvram_struct.tClassTime[i].startHour, g_kjx_nvram_struct.tClassTime[i].startMin, g_kjx_nvram_struct.tClassTime[i].endHour, g_kjx_nvram_struct.tClassTime[i].endMin);
		#endif
		#endif
            if (g_kjx_nvram_struct.tClassTime[i].startHour!=0&&g_kjx_nvram_struct.tClassTime[i].startMin!=0
                &&g_kjx_nvram_struct.tClassTime[i].endHour!=0&&g_kjx_nvram_struct.tClassTime[i].endMin!=0)
            {
                t1 = g_kjx_nvram_struct.tClassTime[i].startHour*60+g_kjx_nvram_struct.tClassTime[i].startMin;
                t2 = g_kjx_nvram_struct.tClassTime[i].endHour*60+g_kjx_nvram_struct.tClassTime[i].endMin;
                if (tc>=t1&&tc<=t2)
                {
                #ifdef MAIN_DEBUG
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("return TRUE");
				#endif
				#endif
                    return TRUE;
                }
            }
        }
    }
#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("return FALSE");
#endif
#endif
    return FALSE;
}

BOOL kjx_is_on_work_time(void)
{
	applib_time_struct currTime;

#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
	kjx_step_set_sleep_time();

	memset(&currTime, 0x00, sizeof(currTime));
    applib_dt_get_rtc_time(&currTime);	

	if((currTime.nHour==0)&&(currTime.nMin<5))
	{/*5分钟搜GPS*/
	#ifdef MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return TRUE1");
	#endif
	#endif
		return TRUE;
	}
#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("currTime=%02d:%02d,time1=%02d:%02d,time2=%02d:%02d", currTime.nHour,currTime.nMin,StartHour1,EndHour1,StartMin1,EndMin1);
#endif
#endif
	if(((currTime.nHour>=StartHour1)&&(currTime.nHour<=EndHour1)&&(currTime.nMin>=StartMin1)&&(currTime.nMin<=EndMin1))
		||((currTime.nHour>=StartHour2)&&(currTime.nHour<=EndHour2)&&(currTime.nMin>=StartMin2)&&(currTime.nMin<=EndMin2)))
	{/*不工作时段*/
	#ifdef MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return FALSE1");
	#endif
	#endif
		return FALSE;
	}

#if !defined(__KJX_FUN_SENSOR__)
	if(kjx_default_work_time_project())
	{
		if((StartHour1==0)&&(EndHour1==0)&&(StartMin1==0)&&(EndMin1==0)
		&&(StartHour2==0)&&(EndHour2==0)&&(StartMin2==0)&&(EndMin2==0))
		{
			if(((currTime.nHour>=0)&&(currTime.nHour<7))||((currTime.nHour>=19)&&(currTime.nHour<=23)))
			{/*不工作时段*/
				//kjx_stop_get_cellid();
			#ifdef MAIN_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("return FALSE2");
			#endif
			#endif
				return FALSE;
			}
		}
	}
#endif
#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("return TRUE2");
#endif
#endif
	return  TRUE;
}

void kjx_handle_send_gps_data(void)
{/*位置数据包*/
    S32 result = 0;
 
    StopTimer(KJX_TIMER_ID_GPS_DATA);
#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	if(kjx_gps_is_valid())
	    result=kjx_socket_send_data_with_type(SERVER_TYPE_03);
	else
		result=kjx_socket_send_data_with_type(SERVER_TYPE_84);

    g_kjx_socket_event_func.handle_gps_work_mode(result);
}

void kjx_handle_position(void)
{
#ifdef MAIN_DEBUG
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
		StartTimer(KJX_TIMER_ID_GPS_DATA, (1000*5), kjx_handle_send_gps_data);
	}
	else
#endif
	{
	#ifdef __KJX_FUN_GPS__
		kjx_open_gps();
	#endif

		StartTimer(KJX_TIMER_ID_GPS_DATA, (1000*5), kjx_handle_send_gps_data);
	}
}

U8 kjx_call_num[16];
U16 kjx_get_sos_index(void)
{
	int i = 0;
	U16 sos_index=0,string_id=0;
	//extern U8 kjx_call_num[];
	extern U16 kjx_call_index;

	if(!strlen(kjx_call_num))
		return 0;

	for(i=0;i<13;i++)
	{
		if(i<3)
		{
			if(memcmp(kjx_call_num,g_kjx_nvram_struct.sosNum[i],strlen(kjx_call_num))==0)
			{
				break;
			}
		}
		else
		{
			if(memcmp(kjx_call_num,g_kjx_nvram_struct.whiteNum[i],strlen(kjx_call_num))==0)
			{
				break;
			}
		}
	}

	sos_index = i+1;
	
	switch(sos_index)
	{
		case 1:
			string_id = STR_KJX_OUTCALL_SOS1;
			break;
			
		case 2:
			string_id = STR_KJX_OUTCALL_SOS2;
			break;
			
		case 3:
			string_id = STR_KJX_OUTCALL_SOS3;
			break;
			
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
			string_id = STR_KJX_OUTCALL_WHITE_NUM;
			break;

		default:
			string_id = STR_KJX_OUTCALL_NONUMBER;
			break;
	}

	if(kjx_call_index==2)
	{
		string_id = STR_KJX_IN_CALLING;
	}
	
	return string_id;
}

/************************************************************************************/
U16 wave_total = 0;
void kjx_wave_for_dog_stop(void);

void kjx_wave_for_dog_start(void)
{
    StopTimer(KJX_TIMER_ID_DOG);
	
    wave_total++;
    StartTimer(KJX_TIMER_ID_DOG, 7, kjx_wave_for_dog_stop);
}
 
void kjx_wave_for_dog_stop(void)
{
    StopTimer(KJX_TIMER_ID_DOG);

   	g_kjx_main_func.kjx_check_fun();

	StartTimer(KJX_TIMER_ID_DOG, 1000*5, kjx_wave_for_dog_start);
}
/************************************************************************************/
//电池电量:以整数表示的百分比
void kjx_get_cur_battery_status(void)
{
	U16 temp=0,i =0,percentage = 0;
	U32 voltage=0,voltValue = 0;
	static U32 tempPercentage[CHECK_BAT_MAX+1]={0};
	static U16 total = 0;
	static U16 firstCheck = 1;

	StopTimer(KJX_TIMER_ID_BATTERY);
	bmt_get_adc_channel_voltage(DCL_VBAT_ADC_CHANNEL, &voltage);
#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("voltage:%d.%02d", voltage/1000000, (voltage-(voltage/1000000)*1000000)/10000);
#endif
#endif

	if(voltage<BAT_VOL_COMPARE_MIN)
	{
		StartTimer(KJX_TIMER_ID_BATTERY,1000*5,kjx_get_cur_battery_status);
		return;
	}

	percentage = (BAT_VOL_COMPARE_MAX-BAT_VOL_COMPARE_MIN)/100;

	if(firstCheck == 1)
	{
		firstCheck = 0;
		temp = (voltage-BAT_VOL_COMPARE_MIN)/percentage;
	#ifdef MAIN_DEBUG		
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("firstCheck voltValue:%d, temp:%d", voltage, temp);
	#endif
	#endif
	
		if((temp<=100)&&(temp>=0))
		{
			battery_percentage = temp;
		}
		else if(temp>100)
		{
			battery_percentage = 100;
		}

		StartTimer(KJX_TIMER_ID_BATTERY,1000*10,kjx_get_cur_battery_status);
		return;
	}
	
	if(total < CHECK_BAT_MAX)
	{
		tempPercentage[total] = voltage;
		total++;
	}
#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("total:%d", total);
#endif
#endif
	
	if(total==CHECK_BAT_MAX)
	{
		voltValue = 0;

		for(i=0;i<total;i++) 
		{ 
			voltValue += tempPercentage[i]; 
		} 
		
		voltValue = voltValue/CHECK_BAT_MAX;
		temp = (voltValue-BAT_VOL_COMPARE_MIN)/percentage;
	#ifdef MAIN_DEBUG		
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("voltValue:%d, temp:%d", voltValue, temp);
	#endif
	#endif
	
		if((temp<=100)&&(temp>=0))
		{
			battery_percentage = temp;
		}
		else if(temp>100)
		{
			battery_percentage = 100;
		}
		
		memset(tempPercentage, 0, sizeof(tempPercentage));
		total=0;
	}

	StartTimer(KJX_TIMER_ID_BATTERY,1000*10,kjx_get_cur_battery_status);
}

/************************************************************************************/
//基站数据
#if defined(__KJX_NBR_CELL__)
void kjx_nbr_cell_reg_rsp(l4c_nbr_cell_info_ind_struct *msg_ptr)
{
	gas_nbr_cell_info_struct cell_info;
	int i;
	kal_uint8 mcc[4]={0};
	kal_uint8 mnc[4]={0};
	kal_uint16 lac = 0;
	double lbs_distance = 0.0;
	kjx_lbs_info_struct lbs_info;

#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
 
	ClearProtocolEventHandler(MSG_ID_L4C_NBR_CELL_INFO_IND);
	ClearProtocolEventHandler(MSG_ID_L4C_NBR_CELL_INFO_REG_CNF);

	if((kjx_sensor_is_sleep()==0)||(kjx_is_on_work_time()))
	{
		if(srv_nw_info_get_service_availability(MMI_SIM1) != SRV_NW_INFO_SA_FULL_SERVICE)
		{
			StartTimer(KJX_TIMER_ID_NBR_CELL_REQ, 60*1000, kjx_get_nbr_cellid_req);
			return;
		}
	}
	
	if(kjx_nbr_cur_cell_info==NULL)
	{
		kjx_nbr_cur_cell_info = (kjx_nbr_cell_info_struct*) OslMalloc(sizeof(kjx_nbr_cell_info_struct));
	}

	for(i = 0; i < KJX_CELL_NBR_MAX; i++)
	{
		if(s_kjx_nbr_cell_info[i]==NULL)
			s_kjx_nbr_cell_info[i] = (kjx_nbr_cell_info_struct*) OslMalloc(sizeof(kjx_nbr_cell_info_struct));
	}

	memset(kjx_nbr_cur_cell_info,0,sizeof(kjx_nbr_cell_info_struct));
	for(i = 0; i < KJX_CELL_NBR_MAX; i++)
	{
		memset(s_kjx_nbr_cell_info[i],0, sizeof(kjx_nbr_cell_info_struct));
	}

	if(msg_ptr)
	{
		if (KAL_TRUE == msg_ptr->is_nbr_info_valid)
		{
			memcpy((void *)&cell_info, (void *)(&(msg_ptr->ps_nbr_cell_info_union.gas_nbr_cell_info)), sizeof(gas_nbr_cell_info_struct));
		}
		else
		{
			memset((void *)&cell_info, 0, sizeof(gas_nbr_cell_info_struct));    
		}
		
		kjx_nbr_cur_cell_info->arfcn = cell_info.nbr_meas_rslt.nbr_cells[cell_info.serv_info.nbr_meas_rslt_index].arfcn;
		kjx_nbr_cur_cell_info->bsic = cell_info.nbr_meas_rslt.nbr_cells[cell_info.serv_info.nbr_meas_rslt_index].bsic;
		kjx_nbr_cur_cell_info->rxlev = cell_info.nbr_meas_rslt.nbr_cells[cell_info.serv_info.nbr_meas_rslt_index].rxlev;
		kjx_nbr_cur_cell_info->mcc = cell_info.serv_info.gci.mcc;
		kjx_nbr_cur_cell_info->mnc = cell_info.serv_info.gci.mnc;
		kjx_nbr_cur_cell_info->lac = cell_info.serv_info.gci.lac;
		kjx_nbr_cur_cell_info->ci = cell_info.serv_info.gci.ci;
		s_kjx_cell_nbr_num = cell_info.nbr_cell_num;
	#ifdef MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("s_kjx_cell_nbr_num = %d", s_kjx_cell_nbr_num);
	#endif
	#endif

		if(s_kjx_cell_nbr_num>KJX_CELL_NBR_MAX)
			s_kjx_cell_nbr_num = KJX_CELL_NBR_MAX;
		
		for(i = 0; i < s_kjx_cell_nbr_num; i++)
		{
			s_kjx_nbr_cell_info[i]->arfcn = cell_info.nbr_meas_rslt.nbr_cells[cell_info.nbr_cell_info[i].nbr_meas_rslt_index].arfcn;
			s_kjx_nbr_cell_info[i]->bsic = cell_info.nbr_meas_rslt.nbr_cells[cell_info.nbr_cell_info[i].nbr_meas_rslt_index].bsic;
			s_kjx_nbr_cell_info[i]->rxlev = cell_info.nbr_meas_rslt.nbr_cells[cell_info.nbr_cell_info[i].nbr_meas_rslt_index].rxlev;
			s_kjx_nbr_cell_info[i]->mcc = cell_info.nbr_cell_info[i].gci.mcc;
			s_kjx_nbr_cell_info[i]->mnc = cell_info.nbr_cell_info[i].gci.mnc;
			s_kjx_nbr_cell_info[i]->lac = cell_info.nbr_cell_info[i].gci.lac;
			s_kjx_nbr_cell_info[i]->ci = cell_info.nbr_cell_info[i].gci.ci;

		#if defined(__KJX_FUN_GPS__)
			lbs_distance=kjx_get_lbs_distance(s_kjx_nbr_cell_info[i]->rxlev);
		#endif
		}
	}

	StartTimer(KJX_TIMER_ID_NBR_CELL_REQ, 30*1000, kjx_get_nbr_cellid_req); /* 30秒一次 */
}

void kjx_get_nbr_cellid_req(void)  
{
	srv_nw_info_service_availability_enum ret;

	StopTimer(KJX_TIMER_ID_NBR_CELL_REQ);

	ret = srv_nw_info_get_service_availability(MMI_SIM1);
	if(ret != SRV_NW_INFO_SA_FULL_SERVICE)
	{
		StartTimer(KJX_TIMER_ID_NBR_CELL_REQ, 10*1000, kjx_get_nbr_cellid_req);
		return;
	}
	
	SetProtocolEventHandler(kjx_nbr_cell_reg_rsp, MSG_ID_L4C_NBR_CELL_INFO_REG_CNF);
	SetProtocolEventHandler(kjx_nbr_cell_reg_rsp, MSG_ID_L4C_NBR_CELL_INFO_IND);

	mmi_frm_send_ilm(MOD_L4C, MSG_ID_L4C_NBR_CELL_INFO_REG_REQ, NULL, NULL);
}
#endif

void kjx_cellId_rsp(void *inMsg)
{
	ClearProtocolEventHandler(MSG_ID_MMI_EM_UPDATE_RSP);
}

void kjx_get_cellId_rsp(void *info)
{
	kal_uint8 mcc[4]={0};
	kal_uint8 mnc[4]={0};
	kal_uint16 lac = 0;
	kal_uint8 buff[256] = {0};
	mmi_em_status_ind_struct *msg = (mmi_em_status_ind_struct *) info;
	kjx_lbs_info_struct lbs_info = {0};
	 
	ClearProtocolEventHandler(MSG_ID_MMI_EM_STATUS_IND);
#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
	
	if(kjx_sensor_is_sleep()==0)
	{
		if(srv_nw_info_get_service_availability(MMI_SIM1) != SRV_NW_INFO_SA_FULL_SERVICE)
		{
			StartTimer(KJX_TIMER_ID_CELL_REQ, 60*1000, kjx_get_cellid_req);
			return;
		}
	}
	
	if(msg->em_info == RR_EM_LAI_INFO)
	{  
		kal_uint16 mm_pdu_len;
		rr_em_lai_info_struct *data_ptr;
		
		data_ptr = (rr_em_lai_info_struct *)get_pdu_ptr(msg->info, &mm_pdu_len);
		lac = (data_ptr->lac[0]<<8)|data_ptr->lac[1];

		sprintf((char*)mcc, "%d%d%d", data_ptr->mcc[0], data_ptr->mcc[1], data_ptr->mcc[2]);
		sprintf((char*)mnc, "%d%d", data_ptr->mnc[0], data_ptr->mnc[1]);

		memcpy(lbs_info.mcc, mcc,3);
		memcpy(lbs_info.mnc, mnc,2);
		lbs_info.lac = lac;
		lbs_info.cid = data_ptr->cell_id;

	#if defined(__KJX_FOREIGN__)
		kjx_set_phone_language((char*)lbs_info.mcc);
	#endif
	
		free_peer_buff(msg->info);
		memcpy(&g_kjx_lbs_info_struct,&lbs_info,sizeof(kjx_lbs_info_struct));		
	}

	StartTimer(KJX_TIMER_ID_CELL_REQ, 30*1000, kjx_get_cellid_req); /* 30秒一次 */
} 
 
void kjx_get_cellid_req(void)  
{
    U8 i = 0;
    MYQUEUE Message;
    extern BOOL is_entry_sleep;
    mmi_em_update_req_struct *em_start_req = NULL;
	srv_nw_info_service_availability_enum ret;

    StopTimer(KJX_TIMER_ID_CELL_REQ);

	ret = srv_nw_info_get_service_availability(MMI_SIM1);
    if(ret != SRV_NW_INFO_SA_FULL_SERVICE)
    {
	    StartTimer(KJX_TIMER_ID_CELL_REQ, 10*1000, kjx_get_cellid_req);
	    return;
    }

    em_start_req = OslConstructDataPtr(sizeof(mmi_em_update_req_struct));
    
    ClearProtocolEventHandler(MSG_ID_MMI_EM_UPDATE_REQ);
    SetProtocolEventHandler(kjx_cellId_rsp, MSG_ID_MMI_EM_UPDATE_RSP);
    SetProtocolEventHandler(kjx_get_cellId_rsp, MSG_ID_MMI_EM_STATUS_IND);
	
    for (i=0;i<EM_INFO_REQ_NUM;i++)
    {
          em_start_req->info_request[i] = EM_NC;
    }
    em_start_req->info_request[RR_EM_LAI_INFO]=EM_ON;
    Message.oslMsgId = MSG_ID_MMI_EM_UPDATE_REQ;  
    Message.oslDataPtr = (oslParaType *)em_start_req;  
    Message.oslPeerBuffPtr = NULL;  
    Message.oslSrcId = MOD_MMI;  
    if(kjx_get_active_card()==KJX_ACTIVE_CARD_SIM1)
    {
        Message.oslDestId = MOD_L4C;
    }
#if (MMI_MAX_SIM_NUM >= 2)
   else if(kjx_get_active_card()==KJX_ACTIVE_CARD_SIM2)
    {
        Message.oslDestId = MOD_L4C_2;
    }
 #endif
    OslMsgSendExtQueue(&Message);  
}

void kjx_stop_get_cellid(void)
{}

void kjx_get_cellid(void)
{
	if(srv_nw_info_get_service_availability(MMI_SIM1) != SRV_NW_INFO_SA_NO_SERVICE)
	{
	#ifdef MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("FULL_SERVICE");
	#endif
	#endif
	
	#if defined(__KJX_NBR_CELL__)
		kjx_get_nbr_cellid_req();
	#endif
		kjx_get_cellid_req();
	}
	else
	{
	#ifdef MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("NO_SERVICE");
	#endif
	#endif

		StartTimer(KJX_TIMER_ID_CELL_REQ, 10*1000, kjx_get_cellid);
	}
}

U8 kjx_get_IMSI_rsp(void *inMsg)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 											   */
	/*----------------------------------------------------------------*/
	mmi_smu_get_imsi_rsp_struct *imsi_rsp = NULL;

	/*----------------------------------------------------------------*/
	/* Code Body													   */
	/*----------------------------------------------------------------*/
	mmi_frm_clear_protocol_event_handler(MSG_ID_MMI_SMU_GET_IMSI_RSP, kjx_get_IMSI_rsp);

	imsi_rsp = (mmi_smu_get_imsi_rsp_struct *)inMsg;
#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("result:%d", imsi_rsp->result);
#endif
#endif

	if(KAL_TRUE == imsi_rsp->result)
	{
    	HaveGetIMSI = TRUE;
        memset(IMSIBuffer, 0, sizeof(IMSIBuffer));
        memcpy(IMSIBuffer, imsi_rsp->imsi + 1, 15);

	#ifdef MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)	
        LOGD("IMSIBuffer:%s", IMSIBuffer);
	#endif
	#endif
		
        //白卡自动接听
        if(!strncmp(IMSIBuffer, "00101", 5))
        {
        	//g_is_incoming_auto_answer = KAL_TRUE;
			//g_is_blank_card = TRUE;
		}
        else
        {
        	//g_is_incoming_auto_answer = KAL_FALSE;
			//g_is_blank_card = FALSE;
		}
	    //限制国内SIM卡才可使用 
	#if defined(__LIMITED_OPERATOR__)
		Check_Sim_Area(IMSIBuffer);
		if (!is_used_in_valid_area())
		{
		#ifdef __TTS_ON__
			tts_play_unvalid_area();
		#endif
			LOGD("---1_国内专用版本,不支持其他地区网络---");
		}
	#endif	
	//APN自适应
	#if defined(__APN_ADAPT__)
		if(tracker_apn_param.AutoSetAPN)
        {
        	memset(gPLMN, 0, sizeof(gPLMN));
            memcpy(gPLMN, IMSIBuffer, 5);
            CountryCode = String_To_U32(gPLMN, 5);
            if(Tracker_Outo_Apn_Adaption(CountryCode))
            {
            	WriteRecord(NVRAM_EF_TRACKER_APN_LID, 1, (void *)&tracker_apn_param, NVRAM_EF_TRACKER_APN_SIZE, &error);
				Tracker_socket_APN_Set();
			}
		}
        else
	#endif
		{
			//Tracker_socket_APN_Set();
		}
		//时区自适应
	#if defined(__TIMEZONE_ADAPT__)
		if(tracker_time_zone.AutoSetGMT)
        {
        	memset(gTIMEZONE, 0, sizeof(gTIMEZONE));
            memcpy(gTIMEZONE, IMSIBuffer, 3);
            CountryCode = String_To_U32(gTIMEZONE, 3);
            if(Tracker_Outo_TimeZone_Adaption(CountryCode))
            {
            	WriteRecord(NVRAM_EF_TRACKER_TIME_ZONE_LID, 1, (void *)&tracker_time_zone, NVRAM_EF_TRACKER_TIME_ZONE_SIZE, &error);
			}
		}
	#endif
	}
	else
	{
		
	}
	
	return 0;
}

void kjx_get_imsi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_GET_IMSI_RSP, kjx_get_IMSI_rsp, MMI_TRUE);

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_MMI_SMU_GET_IMSI_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct *) NULL;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct *) NULL;
    
    SEND_ILM(MOD_MMI, MOD_L4C, MMI_L4C_SAP, ilm_ptr);
}

void kjx_set_imei(char* strimei, U8 len)
{
	U8 i, j, Char_Imei_L, Char_Imei_H;
	char Str_Imei[17] = {0};
	char IMEI_to_NVRAM[10] = {0};
	S16 Error;

	memcpy(Str_Imei, strimei, len);
	for(i = 0, j = 0; i < 16;)
	{
		Char_Imei_L = Str_Imei[i] - 0x30;
		i++;
		Char_Imei_H = Str_Imei[i] - 0x30;
		i++;
		IMEI_to_NVRAM[j] = ((Char_Imei_H << 4) & 0xF0) | (Char_Imei_L & 0x0F);
		j++;
	}

	IMEI_to_NVRAM[8] = 0x00;
	IMEI_to_NVRAM[9] = 0x01;
	WriteRecord(NVRAM_EF_IMEI_IMEISV_LID, 1, &IMEI_to_NVRAM, NVRAM_EF_IMEI_IMEISV_SIZE, &Error);
}

void kjx_get_imei_rsp(void *Msg)
{           
	mmi_nw_get_imei_rsp_struct *pMsg = (mmi_nw_get_imei_rsp_struct *)Msg;
	kal_uint8 def_imei[10][SRV_MAX_IMSI_LEN]= // 测试账号
					{   
						{"956680610000015"},	// 0
						{"956680610000027"},	// 1
						{"956680610000033"},	// 2
						{"956680610000045"},	// 3
						{"956680610000054"},	// 4
						{"956680610000060"},	// 5
						{"956680610000075"},	// 6
						{"956680610000085"},	// 7
						{"956680610000091"},	// 8
						{"956680610000103"},	// 9
					};

    ClearProtocolEventHandler(MSG_ID_MMI_NW_GET_IMEI_RSP);
#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("result:%d", pMsg->result);
#endif
#endif
 	
    if (pMsg->result == 1)
    { 
		memset(IMEIBuffer, 0x00, sizeof(IMEIBuffer));
		memset(kjxImei, 0x00, sizeof(kjxImei));
		if(strlen(pMsg->imei)>0)
		{
			memcpy(IMEIBuffer, pMsg->imei, SRV_IMEI_MAX_LEN);
			memcpy(kjxImei, IMEIBuffer, SRV_IMEI_MAX_LEN);
		}
		else
		{
			memcpy(IMEIBuffer, def_imei[0], SRV_IMEI_MAX_LEN);
			memcpy(kjxImei, IMEIBuffer, SRV_IMEI_MAX_LEN);
			kjx_set_imei(def_imei[0], SRV_IMEI_MAX_LEN);
		}

	#ifdef MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("IMEIBuffer:%s", IMEIBuffer);
	#endif
	#endif

		/*获取IMSI*/
		kjx_get_imsi();
    }
    else
    {
		memcpy(IMEIBuffer, def_imei[2], SRV_IMEI_MAX_LEN);
		memcpy(kjxImei, IMEIBuffer, SRV_IMEI_MAX_LEN);
		kjx_set_imei(def_imei[2], SRV_IMEI_MAX_LEN);

		/*获取IMSI*/
		kjx_get_imsi();
    }
}

void kjx_get_imei(void)
{
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_NW_GET_IMEI_RSP, kjx_get_imei_rsp, MMI_FALSE);
    mmi_frm_send_ilm(MOD_L4C,MSG_ID_MMI_NW_GET_IMEI_REQ,NULL,NULL);
}

#if defined(CUSTOMER_NAME_MEGE2)
void kjx_get_iccid_rsp(void *info)
{
	/*----------------------------------------------------------------*/
	/* Local Variables */
	/*----------------------------------------------------------------*/
	mmi_smu_read_sim_rsp_struct *iccid_data;
	kal_uint8 iccid[21]={0};
	int i;
	U8 iccIdTemp[6]={0};
	/*----------------------------------------------------------------*/
	/* Code Body */
	/*----------------------------------------------------------------*/
	iccid_data = (mmi_smu_read_sim_rsp_struct*) info;

	ClearProtocolEventHandler(MSG_ID_MMI_SMU_READ_SIM_RSP);
#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
	
	if (iccid_data->result.flag == L4C_SUCCESS && strlen(iccid_data->data)>0)
	{
	#ifdef MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("Read iccid success!");
	#endif
	#endif

		for(i=0;i<iccid_data->length;i++)
		{
		#ifdef MAIN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("ICCID[%d]:%02x", i, iccid_data->data[i]);
		#endif
		#endif
		}
		
		for (i = 0; i<iccid_data->length; i++)
		{
			iccid[i * 2] = 0x30 + (*(iccid_data->data + i) & 0x0F);
			iccid[i * 2 + 1] = 0x30 + ((*(iccid_data->data  + i) & 0xF0) >> 4);

			if(iccid[i] == 0x3d)
				iccid[i] = 0x64;
		}

		iccid[20] = 0;

		memset(kjxIccid,0x00,sizeof(kjxIccid));
		memcpy(kjxIccid,iccid,strlen(iccid));
	#ifdef MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("ICCID:%s", kjxIccid);
	#endif
	#endif

		if(!strlen(kjxIccid))
			return;
		
		memcpy(iccIdTemp,kjxIccid+15,5);
	#ifdef MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("iccIdTemp:%s", iccIdTemp);
	#endif
	#endif
		for(i=0;i<KJX_NUM_MAX;i++)
		{
			if(memcmp(g_kjx_numTotal[i].numIccid,iccIdTemp,strlen(iccIdTemp)) == 0)
			{
				memset(kjxPhoneNum,0x00,sizeof(kjxPhoneNum));

				memcpy(kjxPhoneNum,"1476550",strlen("1476550"));
				strcat(kjxPhoneNum,g_kjx_numTotal[i].numStr);
			#ifdef MAIN_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("kjxPhoneNum=%s", kjxPhoneNum);
			#endif
			#endif
				
				break;
			}
			else
			{
				if(i == KJX_NUM_MAX-1)  //  假如在最后一次iccid都不在列表中则退出
				{
					break;
				}
			}
		}	
		
	}
	else
	{
		kjx_get_iccid_req();
	#ifdef MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("read iccid fail!");
	#endif
	#endif
	}


}

void kjx_get_iccid_req(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables */
	/*----------------------------------------------------------------*/
	MYQUEUE Message;
	mmi_smu_read_sim_req_struct *dataPtr;

	/*----------------------------------------------------------------*/
	/* Code Body */
	/*----------------------------------------------------------------*/
	SetProtocolEventHandler(kjx_get_iccid_rsp, MSG_ID_MMI_SMU_READ_SIM_RSP);

	Message.oslSrcId = MOD_MMI;
	Message.oslDestId = MOD_L4C;
	Message.oslMsgId = MSG_ID_MMI_SMU_READ_SIM_REQ;
	dataPtr = (mmi_smu_read_sim_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_sim_req_struct));
	dataPtr->file_idx = (U8) FILE_ICCID_IDX;
	dataPtr->para = 0;
	dataPtr->length = 0x0a;
	Message.oslDataPtr = (oslParaType*) dataPtr;
	Message.oslPeerBuffPtr = NULL;
	OslMsgSendExtQueue(&Message);
}

void kjx_get_iccid(void)
{
	StopTimer(KJX_TIMER_ID_GET_ICCID);
	
	if(srv_nw_info_get_service_availability(MMI_SIM1) == SRV_NW_INFO_SA_FULL_SERVICE)
	{
	#ifdef MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("FULL_SERVICE");
	#endif
	#endif

		kjx_get_iccid_req();
	}
	else
	{
	#ifdef MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("NO_SERVICE");
	#endif	
	#endif
	
		StartTimer(KJX_TIMER_ID_GET_ICCID,1000*5,kjx_get_iccid);
	}
}
#endif
/************************************************************************************/
/************************************************************************************/

/************************************************************************************/
/************************************************************************************/
nvram_ef_kjx_work_time_fun g_nvram_work_time;
BOOL kjx_check_shut_down(void)
{
	S16 error;
	applib_time_struct currTime;
	char lastTime[16];
	char myTime[16];
	static U32 chckTotal = 0;

	if(chckTotal==10)
		return TRUE;
	else if(chckTotal==1)
		return FALSE;

	memset(&currTime, 0x00, sizeof(currTime));
	memset(&g_nvram_work_time, 0x00, sizeof(g_nvram_work_time));
	applib_dt_get_rtc_time(&currTime);	

	ReadRecord(NVRAM_EF_KJX_WORK_TIME_LID, 1, &g_nvram_work_time,NVRAM_EF_KJX_WORK_TIME_SIZE,&error);

    memset(lastTime, 0x00, sizeof(lastTime));
    memset(myTime, 0x00, sizeof(myTime));
	sprintf(lastTime,"%02d%02d%02d",g_nvram_work_time.nHour,g_nvram_work_time.nMin,g_nvram_work_time.nSec);
	sprintf(myTime,"%02d%02d%02d",currTime.nHour,currTime.nMin,currTime.nSec);

	if(((atoi((char*)myTime)-atoi((char*)lastTime))>0)&&((atoi((char*)myTime)-atoi((char*)lastTime))<30)&&(atoi((char*)lastTime)>0))
	{
		chckTotal=10;
		return TRUE;
	}
	else
	{
		if((currTime.nMin>g_nvram_work_time.nMin))
		{
			chckTotal=10;
			return TRUE;
		}
		
		chckTotal=1;
	}

	return FALSE;
}

void kjx_write_work_time(void)
{
	S16 error;
	applib_time_struct currTime;
	extern kal_uint8 IMEIBuffer[SRV_IMEI_MAX_LEN + 1];

	if((memcmp(IMEIBuffer,"350800000000060",strlen("350800000000060"))!=0)
	&&(memcmp(IMEIBuffer,"678833010000120",strlen("678833010000120"))!=0))
	{
		return;
	}
	
	memset(&currTime, 0x00, sizeof(currTime));
	applib_dt_get_rtc_time(&currTime);	
	memcpy(&g_nvram_work_time,&currTime,sizeof(currTime));

#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("%04d-%02d-%02d   %02d:%02d:%02d (CUR)%04d-%02d-%02d   %02d:%02d:%02d",
			g_nvram_work_time.nYear,g_nvram_work_time.nMonth,g_nvram_work_time.nDay,
			g_nvram_work_time.nHour,g_nvram_work_time.nMin,g_nvram_work_time.nSec,
			currTime.nYear,currTime.nMonth,currTime.nDay,
			currTime.nHour,currTime.nMin,currTime.nSec);
#endif
#endif

	WriteRecord(NVRAM_EF_KJX_WORK_TIME_LID,1,&g_nvram_work_time,NVRAM_EF_KJX_WORK_TIME_SIZE,&error);
}
/************************************************************************************/
/************************************************************************************/

extern void kjx_play_mp3(void);
/************************************************************************************/
/************************************************************************************/
void kjx_func_main(void)
{
#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

#if defined(__KJX_FUN_SENSOR__)
	StartTimer(KJX_TIMER_ID_SENSOR_INIT, 1000, kjx_sensor_main);
#endif

    kjx_wave_for_dog_start();
    kjx_get_cur_battery_status();
	
    if(mmi_bootup_is_sim_valid())
    {
    	/*读取基站数据*/
    	kjx_get_cellid();
		
		kjx_func_init();
		g_kjx_main_func.kjx_main_custom();
    }
    else
    {     
		kjx_func_init();
		g_kjx_main_func.kjx_main_custom();
            
	#ifdef MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("SIM Card empty!!!");
	#endif
	#endif
    }
	kjx_play_mp3();
}

BOOL kjx_is_in_confirm_display(void)
{
	MMI_ID scr_id;
	
	scr_id == mmi_frm_scrn_get_active_id();

#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("SCR_ID_ALERT_0:%d, SCR_ID_ALERT_9:%d,scr_id:%d", SCR_ID_ALERT_0, SCR_ID_ALERT_9,scr_id);
#endif
#endif

	if((scr_id >= SCR_ID_ALERT_0) && (scr_id <= SCR_ID_ALERT_9))
		return TRUE;
	else
		return FALSE;
}

#if defined(__KJX_DJ_SUPPORT__)
void kjx_dj_infor_init(void)
{
	char tmpbuf[128] = {0};

	if(g_kjx_nvram_struct.dj_infor.dj_chanle > 0)
	{
		sprintf(tmpbuf, "Chanle:%02d", g_kjx_nvram_struct.dj_infor.dj_chanle);
		mmi_asc_to_ucs2((S8*)dj_chanle_show, (S8*)tmpbuf);
	}
}
#endif

#ifdef __KJX_MULTI_LANGUAGE__
void kjx_language_init(void)
{
	U8 i,data;
	kal_uint32 fs_len;
	FS_HANDLE handle;
	U8 tmpbuf[128] = {0};
	S8 usc2Path[128] = {0};
	UINT filesize;

#ifdef RFID_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	kal_wsprintf((WCHAR*) usc2Path, "%c%w", SRV_FMGR_CARD_DRV, AUDIODIR);
	for(i=0;i<KJX_LANGUAGE_MAX;i++)
	{
		S8 dirPath[128] = {0};

		mmi_ucs2cpy((CHAR*)dirPath, (CHAR*)usc2Path);
		mmi_asc_to_ucs2((CHAR*)tmpbuf, (CHAR*)kjx_language[i].name);
		mmi_ucs2cat((CHAR*)dirPath, (CHAR*)tmpbuf);
		handle = FS_SetCurrentDir((WCHAR*)dirPath);
		if(handle>=FS_NO_ERROR)
		{
		#ifdef RFID_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("添加语言 ID:%d", kjx_language[i].id);
		#endif
		#endif
		
			g_kjx_language_sum[g_kjx_language_count++] = kjx_language[i].id;
		}
		else
		{
		#ifdef RFID_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("文件夹不存在");
		#endif
		#endif
		}		
	}

#ifdef RFID_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_kjx_language_count:%d", g_kjx_language_count);
#endif
#endif

	for(i=0;i<g_kjx_language_count;i++)
	{
	#ifdef RFID_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("i:%d, language_ID:%d", i, kjx_language[i].id);
	#endif
	#endif
	}

	g_kjx_language = g_kjx_language_sum[0];
	if(g_kjx_language == LANG_MAX)
		g_kjx_language = LANG_CHN;

#ifdef RFID_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_kjx_language:%d", g_kjx_language);
#endif
#endif

	switch(g_kjx_language)
	{
	case LANG_ENGLISH:				//英
	case LANG_FRENCH:				//法
	case LANG_GERMAN:				//德
	case LANG_ITALIAN:				//意大利
	case LANG_SPANISH:				//西班牙
	case LANG_PORTUGUESE:			//葡萄牙
	case LANG_POLISH:				//波兰
	case LANG_DANISH:				//丹麦
	case LANG_SWEDISH:				//瑞典
	case LANG_NORWEGIAN: 			//挪威
	case LANG_FINNISH:				//芬兰
	case LANG_DUTCH: 				//荷兰
	case LANG_UKRAINIAN: 			//乌克兰
	case LANG_RUSSIAN:				//俄罗斯
	case LANG_GREEK: 				//希腊
	case LANG_TURKISH:				//土耳其
	case LANG_ARABIC:				//阿拉伯
	case LANG_HEBREW:				//希伯来语(以色列)
	case LANG_PERSIAN:				//波斯语(伊朗)
	case LANG_URDU:					//乌尔都语(巴基斯坦)
	case LANG_HINDI: 				//印地语(印度)
	case LANG_BENGALI:				//孟加拉
	case LANG_LAO:					//老挝
	case LANG_KHMER:				//高棉语(柬埔寨)
	case LANG_MYANMAR:				//缅甸
	case LANG_VIETNAMESE:			//越南
	case LANG_INDONESIAN:			//印度尼西亚
	case LANG_MALAY: 				//马来语(马来西亚,文莱)
	case LANG_THAI:					//泰国
	case LANG_FILIPINO:				//菲律宾语
	case LANG_KOREAN:				//朝鲜语(朝鲜,韩国)
	case LANG_JAPANESE:				//日本
		data = 0;
		break;

	case LANG_CHN:					//中文普通话
	case LANG_CHN_SC:				//中文四川话
	case LANG_CHN_GD:				//中文广东话
	case LANG_CHN_MN:				//中文闽南话
	case LANG_CHN_XZ:				//中文藏语
	case LANG_CHN_XZ_LASA:				//中文藏语拉萨
	case LANG_CHN_XZ_ANDUO:				//中文藏语安多
	case LANG_CHN_XZ_KANGBA:			//中文藏语康巴
	case LANG_CHN_EXTRA:			//中文其他方言
		data = 1;
		break;

	default:
		data = 1;
		break;
	}

	srv_setting_set_language_ext(data);

	memset(tmpbuf, 0, sizeof(tmpbuf));
	switch(g_kjx_language)
	{
	case LANG_CHN:					//中文普通话
		mmi_chset_convert(MMI_CHSET_GB18030, MMI_CHSET_UCS2, "普通话", (char*)tmpbuf, sizeof(tmpbuf));
		mmi_ucs2cpy((CHAR*)g_kjx_titlestr, (const CHAR*)tmpbuf);
		break;
	case LANG_CHN_SC:				//中文四川话
		mmi_chset_convert(MMI_CHSET_GB18030, MMI_CHSET_UCS2, "四川话", (char*)tmpbuf, sizeof(tmpbuf));
		mmi_ucs2cpy((CHAR*)g_kjx_titlestr, (const CHAR*)tmpbuf);
		break;
	case LANG_CHN_GD:				//中文广东话
		mmi_chset_convert(MMI_CHSET_GB18030, MMI_CHSET_UCS2, "白话", (char*)tmpbuf, sizeof(tmpbuf));
		mmi_ucs2cpy((CHAR*)g_kjx_titlestr, (const CHAR*)tmpbuf);
		break;
	case LANG_CHN_MN:				//中文闽南话
		mmi_chset_convert(MMI_CHSET_GB18030, MMI_CHSET_UCS2, "闽南话", (char*)tmpbuf, sizeof(tmpbuf));
		mmi_ucs2cpy((CHAR*)g_kjx_titlestr, (const CHAR*)tmpbuf);
		break;
	case LANG_CHN_XZ:				//中文藏语
		mmi_chset_convert(MMI_CHSET_GB18030, MMI_CHSET_UCS2, "藏语", (char*)tmpbuf, sizeof(tmpbuf));
		mmi_ucs2cpy((CHAR*)g_kjx_titlestr, (const CHAR*)tmpbuf);
		break;
	case LANG_CHN_XZ_LASA:				//中文藏语拉萨
		mmi_chset_convert(MMI_CHSET_GB18030, MMI_CHSET_UCS2, "拉萨", (char*)tmpbuf, sizeof(tmpbuf));
		mmi_ucs2cpy((CHAR*)g_kjx_titlestr, (const CHAR*)tmpbuf);
		break;
	case LANG_CHN_XZ_ANDUO:				//中文藏语安多
		mmi_chset_convert(MMI_CHSET_GB18030, MMI_CHSET_UCS2, "安多", (char*)tmpbuf, sizeof(tmpbuf));
		mmi_ucs2cpy((CHAR*)g_kjx_titlestr, (const CHAR*)tmpbuf);
		break;
	case LANG_CHN_XZ_KANGBA:				//中文藏语康巴
		mmi_chset_convert(MMI_CHSET_GB18030, MMI_CHSET_UCS2, "康巴", (char*)tmpbuf, sizeof(tmpbuf));
		mmi_ucs2cpy((CHAR*)g_kjx_titlestr, (const CHAR*)tmpbuf);
		break;		
	case LANG_CHN_EXTRA:			//中文其他方言
		mmi_chset_convert(MMI_CHSET_GB18030, MMI_CHSET_UCS2, "其他方言", (char*)tmpbuf, sizeof(tmpbuf));
		mmi_ucs2cpy((CHAR*)g_kjx_titlestr, (const CHAR*)tmpbuf);
		break;
	default:
		mmi_asc_to_ucs2((CHAR*)tmpbuf, (CHAR*)kjx_language[g_kjx_language].name);
		mmi_ucs2cpy((CHAR*)g_kjx_titlestr, (CHAR*)tmpbuf);
		break;
	}
	SetIdleScreenNetworkStatus((U8 *)g_kjx_titlestr);
}


/*****************************************************************************
* FUNCTION
*  	kjx_handle_send_system_language
* DESCRIPTION
*   将设备当前语言同步到后台
* PARAMETERS
*
* RETURNS
*	none
*****************************************************************************/
void kjx_handle_send_system_language(void)
{
#ifdef RFID_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

    kjx_socket_send_data_with_type(SERVER_TYPE_75);

	StartTimer(KJX_TIMER_ID_RESEND_LANGUAGE_SET, 30*1000, kjx_handle_send_system_language);
}

void kjx_entry_alternate_language(void)
{
	U8 data;

#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_kjx_language_index:%d, g_kjx_language_count:%d, g_kjx_language:%d", g_kjx_language_index, g_kjx_language_count, g_kjx_language);
#endif
#endif

	g_kjx_language_index++;
	if(g_kjx_language_index >= g_kjx_language_count)
		g_kjx_language_index = 0;
	
	if(g_kjx_language_sum[g_kjx_language_index] == LANG_MAX)
		g_kjx_language_index = 0;

	g_kjx_language = g_kjx_language_sum[g_kjx_language_index];
	switch(g_kjx_language)
	{
	case LANG_ENGLISH:				//英
	case LANG_FRENCH:				//法
	case LANG_GERMAN:				//德
	case LANG_ITALIAN:				//意大利
	case LANG_SPANISH:				//西班牙
	case LANG_PORTUGUESE:			//葡萄牙
	case LANG_POLISH:				//波兰
	case LANG_DANISH:				//丹麦
	case LANG_SWEDISH:				//瑞典
	case LANG_NORWEGIAN: 			//挪威
	case LANG_FINNISH:				//芬兰
	case LANG_DUTCH: 				//荷兰
	case LANG_UKRAINIAN: 			//乌克兰
	case LANG_RUSSIAN:				//俄罗斯
	case LANG_GREEK: 				//希腊
	case LANG_TURKISH:				//土耳其
	case LANG_ARABIC:				//阿拉伯
	case LANG_HEBREW:				//希伯来语(以色列)
	case LANG_PERSIAN:				//波斯语(伊朗)
	case LANG_URDU:					//乌尔都语(巴基斯坦)
	case LANG_HINDI: 				//印地语(印度)
	case LANG_BENGALI:				//孟加拉
	case LANG_LAO:					//老挝
	case LANG_KHMER:				//高棉语(柬埔寨)
	case LANG_MYANMAR:				//缅甸
	case LANG_VIETNAMESE:			//越南
	case LANG_INDONESIAN:			//印度尼西亚
	case LANG_MALAY: 				//马来语(马来西亚,文莱)
	case LANG_THAI:					//泰国
	case LANG_FILIPINO:				//菲律宾语
	case LANG_KOREAN:				//朝鲜语(朝鲜,韩国)
	case LANG_JAPANESE:				//日本
		data = 0;
		break;

	case LANG_CHN:					//中文普通话
	case LANG_CHN_SC:				//中文四川话
	case LANG_CHN_GD:				//中文广东话
	case LANG_CHN_MN:				//中文闽南话
	case LANG_CHN_XZ:				//中文藏语
	case LANG_CHN_XZ_LASA:				//中文藏语拉萨
	case LANG_CHN_XZ_ANDUO:				//中文藏语安多
	case LANG_CHN_XZ_KANGBA:			//中文藏语康巴
	case LANG_CHN_EXTRA:			//中文其他方言
		data = 1;
		break;

	default:
		data = 1;
		break;
	}	

	srv_setting_set_language_ext(data);

	kjx_handle_send_system_language();

#ifdef MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_kjx_language_index:%d, g_kjx_language:%d", g_kjx_language_index, g_kjx_language);
#endif
#endif

	if(mmi_idle_is_active())
	{
		U8 tmpbuf[128] = {0};
		
		switch(g_kjx_language)
		{
		case LANG_CHN:					//中文普通话
			mmi_chset_convert(MMI_CHSET_GB18030, MMI_CHSET_UCS2, "普通话", (char*)tmpbuf, sizeof(tmpbuf));
			mmi_ucs2cpy((CHAR*)g_kjx_titlestr, (const CHAR*)tmpbuf);
			break;
		case LANG_CHN_SC:				//中文四川话
			mmi_chset_convert(MMI_CHSET_GB18030, MMI_CHSET_UCS2, "四川话", (char*)tmpbuf, sizeof(tmpbuf));
			mmi_ucs2cpy((CHAR*)g_kjx_titlestr, (const CHAR*)tmpbuf);
			break;
		case LANG_CHN_GD:				//中文广东话
			mmi_chset_convert(MMI_CHSET_GB18030, MMI_CHSET_UCS2, "白话", (char*)tmpbuf, sizeof(tmpbuf));
			mmi_ucs2cpy((CHAR*)g_kjx_titlestr, (const CHAR*)tmpbuf);
			break;
		case LANG_CHN_MN:				//中文闽南话
			mmi_chset_convert(MMI_CHSET_GB18030, MMI_CHSET_UCS2, "闽南话", (char*)tmpbuf, sizeof(tmpbuf));
			mmi_ucs2cpy((CHAR*)g_kjx_titlestr, (const CHAR*)tmpbuf);
			break;
		case LANG_CHN_XZ:				//中文藏语
			mmi_chset_convert(MMI_CHSET_GB18030, MMI_CHSET_UCS2, "藏语", (char*)tmpbuf, sizeof(tmpbuf));
			mmi_ucs2cpy((CHAR*)g_kjx_titlestr, (const CHAR*)tmpbuf);
			break;
		case LANG_CHN_XZ_LASA:				//中文藏语拉萨
			mmi_chset_convert(MMI_CHSET_GB18030, MMI_CHSET_UCS2, "拉萨", (char*)tmpbuf, sizeof(tmpbuf));
			mmi_ucs2cpy((CHAR*)g_kjx_titlestr, (const CHAR*)tmpbuf);
			break;
		case LANG_CHN_XZ_ANDUO:				//中文藏语安多
			mmi_chset_convert(MMI_CHSET_GB18030, MMI_CHSET_UCS2, "安多", (char*)tmpbuf, sizeof(tmpbuf));
			mmi_ucs2cpy((CHAR*)g_kjx_titlestr, (const CHAR*)tmpbuf);
			break;
		case LANG_CHN_XZ_KANGBA:				//中文藏语康巴
			mmi_chset_convert(MMI_CHSET_GB18030, MMI_CHSET_UCS2, "康巴", (char*)tmpbuf, sizeof(tmpbuf));
			mmi_ucs2cpy((CHAR*)g_kjx_titlestr, (const CHAR*)tmpbuf);
			break;
		case LANG_CHN_EXTRA:			//中文其他方言
			mmi_chset_convert(MMI_CHSET_GB18030, MMI_CHSET_UCS2, "其他方言", (char*)tmpbuf, sizeof(tmpbuf));
			mmi_ucs2cpy((CHAR*)g_kjx_titlestr, (const CHAR*)tmpbuf);
			break;
		default:
			mmi_asc_to_ucs2((CHAR*)tmpbuf, (CHAR*)kjx_language[g_kjx_language].name);
			mmi_ucs2cpy((CHAR*)g_kjx_titlestr, (CHAR*)tmpbuf);
			break;
		}
		SetIdleScreenNetworkStatus((U8*)g_kjx_titlestr);
		
	#ifdef __BOSCH_BMP280_PRESSURE__
		BOSCH_BMP280_get_data();
	#endif
	#ifdef __KJX_FUN_STEPS__
		kjx_sensor_get_step();
	#endif
	
		idle_screen_show_network_details();

		update_main_LCD_date_time();
	}

	//语言变更后配置文件重新初始化
	hadRead = FALSE;

	kjx_rfid_stop_play_audio();
	kjx_rfid_play_audio_again();

	if(kjx_get_foctory_test_mode() == 0)
	{
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
}

mmi_ret kjx_language_setting_confirm_cb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 driveletter = 0;
    S32 drv_list = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
		case MMI_ALERT_CNFM_YES:
			mmi_idle_display();
			kjx_entry_alternate_language();
			break;
		case MMI_ALERT_CNFM_NO:
			break;
        }
    }
    return MMI_RET_OK;
}

void kjx_system_language_alternate(void)
{
    mmi_confirm_property_struct arg;

	if(g_kjx_language_count < 2)
	{
		mmi_popup_display((WCHAR*)GetString(STR_KJX_SWITCH_LANGUAGE_NOTIFY), MMI_EVENT_INFO, NULL);
		return;
	}

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.f_enter_history = MMI_TRUE;
	arg.f_auto_map_empty_softkey = 0;
    arg.callback = (mmi_proc_func) kjx_language_setting_confirm_cb;
    mmi_confirm_display((WCHAR*)(get_string(STR_KJX_SET_LANGUAGE_ASK)), MMI_EVENT_QUERY, &arg);
}
#endif

void kjx_initialize_demo(void)
{       
#if defined(CUSTOMER_NAME_TOUR)
	extern void kjx_tour_work_led(void);

	kjx_tour_work_led();
#endif

	/*获取NVRAM*/
	kjx_nvram_init();

#if defined(__KJX_DJ_SUPPORT__)
	kjx_dj_infor_init();
#endif

#if defined(__KJX_LOG_OUTPUT__)
	Tracker_Log_Init();
#endif

#ifdef __KJX_MULTI_LANGUAGE__
	kjx_language_init();
#endif

	EntryTestModeReady = TRUE;

	if(kjx_get_earphone_plugged())
		srv_speech_disable_hand_free();
	else
		srv_speech_enable_hand_free();

	/*显示GPS以及GPRS状态图标*/
	wgui_status_icon_bar_set_icon_display(STATUS_ICON_GPS_OFF);
	wgui_status_icon_bar_set_icon_display(STATUS_ICON_GPRS_UNLINK);
    wgui_status_icon_bar_update();

	kjx_func_main();
}

#endif

