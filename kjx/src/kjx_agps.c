/**********************************************************************************
*Filename:     kjx_agps.c
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2013/04/04
*
***********************************************************************************/
#if defined(__KJX_FUN_AGPS__)

/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "kjx_include.h"
#include "EventsGprot_Int.h"

/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
#define KJX_GPS_ZKW_AGPS_DATA_VALID_TIME	4	//单位小时

/*****************************************************************************
*Enum					枚举类型定义
*****************************************************************************/

/*****************************************************************************
 *Struct					数据结构定义
 *****************************************************************************/

/*****************************************************************************
*Local variable				局部变量
*****************************************************************************/
kjx_ublox_agps_request_pack_struct g_kjx_ublox_agps_request=
{ 
	"full\0",	//"eph\0",
	"redye_1983@163.com\0",
	"Lmsosv\0",
	"30.45\0",
	"114.17\0",
	1500e3
};

kjxNetInfo g_kjxAgpsInfo =
{
   {"cmnet", "", ""},
   KJX_UBLOX_AGPS_DOMAIN_NAME,
   KJX_UBLOX_AGPS_PORT
};

/****************************************************************************
*Global Variable - Extern          全局变量
*****************************************************************************/
U8 g_kjx_agps_used = 0;
BOOL g_kjx_agps_recving = 0;	//0:接收完成或者空闲状态 1:正在接收
U32 g_kjx_agps_date_len = 0;
U32 g_kjx_agps_data_recvd= 0;
U8 g_kjx_agps_valid_time[50] = {0};
U8 g_kjx_agps_buffer[KJX_AGPS_DATA_MAX_LEN] = {0};
kjx_agps_socket_context g_kjx_agps_socket_context;
#ifdef __KJX_FUN_GPS_HD__
U8 g_kjx_HD_agps_retry_count = 0;
U8 g_kjx_HD_agps_step = STEP_AID_READY;
U8 g_kjx_HD_agps_send_buf[HD_AGPS_ONE_BAG_DATA_MAX_LEN] = {0};
U32 g_kjx_HD_agps_send_count = 0;

double g_kjx_HD_agps_lon = 0;//经度
double g_kjx_HD_agps_lat = 0;//纬度
#endif
/****************************************************************************
*Global Variable - Extern          引用全局变量
*****************************************************************************/
extern BOOL g_kjx_time_sync;
extern BOOL socketConnet;
extern U8 g_kjx_gps_category;
extern kjx_socket_event_func g_kjx_socket_event_func;

/*****************************************************************************
*Global Functions	- Extern		引用外部函数
*****************************************************************************/
extern U16 kjx_gps_uart_write(U8 *buffer,U16 len);

/*****************************************************************************
 *Local Functions			本地函数
*****************************************************************************/
static U32 kjx_agps_read_data_from_file(U8 *databuf, U32 buflen);

#ifdef __KJX_FUN_GPS_HD__
void kjx_agps_hd_cmd_wait_timerout(void)
{
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("星历注入华大模块无响应,AGPS流程终止!");
#endif
							
	g_kjx_HD_agps_retry_count = 0;
	g_kjx_agps_used = 0;

	g_kjx_HD_agps_send_count = 0;
	memset(g_kjx_HD_agps_send_buf, 0x00, sizeof(g_kjx_HD_agps_send_buf));
}

void kjx_agps_hd_send_agps_data(U8 *data, U32 datalen)
{
	U32 i=0,len=0;

	StopTimer(KJX_TIMER_ID_AGPS_HD_CMD_WAIT_TIMEROUT);

	for(i=g_kjx_HD_agps_send_count;i<datalen;i+=2)
	{
		if((data[i] == 0xF1) && (data[i+1] == 0xD9))
		{
			len = 8+data[i+4]+data[i+5]*256;
			g_kjx_HD_agps_send_count += len;
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("len:%d, g_kjx_HD_agps_send_count:%d, g_kjx_agps_date_len:%d", len, g_kjx_HD_agps_send_count, g_kjx_agps_date_len);
		#endif

			memset(g_kjx_HD_agps_send_buf, 0x00, sizeof(g_kjx_HD_agps_send_buf));
			memcpy(g_kjx_HD_agps_send_buf, &data[i], len);
			kjx_gps_uart_write(g_kjx_HD_agps_send_buf, len);

			StartTimer(KJX_TIMER_ID_AGPS_HD_CMD_WAIT_TIMEROUT, 2000, kjx_agps_hd_cmd_wait_timerout);
			return;
		}
	}

	if(i == datalen)
	{
		kjx_agps_hd_cmd_wait_timerout();
	}

}

/*******************************************************************************************************
//Header:	0xF1 0xD9
//ID:		0x0B 0x11
//Length:	20
//Payload:	See below
//Checksum:	CK_1 CK_2

//Payload Contents:
//Byte Offset 	Data Type 	Scale 	Name 		Unit 	Description 
// 0 				U1 				 Type 	 	 - 		 Time type
//													 	 (1: TOW 0: UTC)
// 1 				U1 		   - 		    - 	 	 - 		 Reserved
//
-------------------------------------------------------------------------------------------------------
//Tow:
// 2 				U1 				Gnss_id 	 	 - 		 Source of time information
//													 	 0: GPS time
//													 	 1: BD time
//													 	 2: GLONASS time
// 3 				U2 				Week_no  	 - 		 GNSS Week number
// 5 				U4 				Tow_s 	 	 s 		 Integer part seconds of TOW(Time of week)
// 9 				U4 				Tow_ns 	 	 ns 		 Sub-millisecond time of TOW, from 0 to 999,999,999
// 13 				U2 				Tacc_s 	 	 s 		 Seconds part of injection time accuracy
// 15 				U4 				Tacc_ns 	 	 ns 		 Sub-millisecond part of injection time accuracy
// 19 				U1 				Reserved  	 - 		 Reserved
-------------------------------------------------------------------------------------------------------
//UTC
// 2 				U1 				Leap_sec 			 Number of leap seconds since 1980 
//														 (or <0 if unkown)
// 3 				U2 				Year
// 5 				U1 				Month
// 6 				U1 				Day
// 7 				U1 				Hour
// 8 				U1 				Minute
// 9 				U1 				Second
// 10 				U4 				Sec_ns 				Nanoseconds, from 0 to 999,999,999
// 14 				U2 				Tacc_s 				Seconds part of time accuracy
// 16 				U4 				Tacc_ns 				Sub-millisecond part of time accuracy

For example: 
Inject time (0x0B11), 2016-6-22 15:56:03.288393, tacc(注入时间的精度) = 
0.600796，此时 Tacc_s = 0,Tacc_ns = = 600796000，若所注入的时间精度未知，
Tacc_s, Tacc_ns 赋 0.该时刻 leapsecond = 17.
Command: F1 D9 0B 11 14 00 00 00 11 E0 07 06 16 0F 38 03 28 87 30 11 00 00 60 6B CF 23 3B A3
*******************************************************************************************************/
void Tracker_HD_AGPS_Put_AID_Time(applib_time_struct systime)
{
	U8 GPS_HD_head[] = {0xF1,0xD9,0x0B,0x11};
	U8 GPS_HD_buf[128] = {0};
	U8 i=0,len=0,chk1=0,chk2=0;

	if(kjx_gps_is_on())
	{
		//head
		memcpy(GPS_HD_buf, GPS_HD_head, 4);
		len += 4;
		
		//len
		GPS_HD_buf[len++] = 20;
		GPS_HD_buf[len++] = 0;

		//Time type & Reserved
		GPS_HD_buf[len++] = 0;
		GPS_HD_buf[len++] = 0;

		//UTC time
		//Leap_sec
		GPS_HD_buf[len++] = 0;//17;
		//Year
		GPS_HD_buf[len++] = systime.nYear&0x00FF;
		GPS_HD_buf[len++] = (systime.nYear&0xFF00)>>8;
		//Month
		GPS_HD_buf[len++] = systime.nMonth;
		//Day
		GPS_HD_buf[len++] = systime.nDay;
		//Hour
		GPS_HD_buf[len++] = systime.nHour;
		//Min
		GPS_HD_buf[len++] = systime.nMin;
		//Sec
		GPS_HD_buf[len++] = systime.nSec;
		//Sec_ns
		memset(&GPS_HD_buf[len], 0x00, 4);
		len += 4;
		//Tacc_s
		memset(&GPS_HD_buf[len], 0x00, 2);
		len += 2;
		//Tacc_ns
		memset(&GPS_HD_buf[len], 0x00, 4);
		len += 4;

		for(i=2;i<len;i++)
		{
			chk1 += GPS_HD_buf[i];
			chk2 += chk1;
		}
		//chksum
		GPS_HD_buf[len++] = chk1;
		GPS_HD_buf[len++] = chk2;

	#if 0	//defined(__KJX_LOG_OUTPUT__)
		LOGD("len:%d CMD:%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X", 
									len, 
									GPS_HD_buf[0],GPS_HD_buf[1],GPS_HD_buf[2],GPS_HD_buf[3],GPS_HD_buf[4],GPS_HD_buf[5],GPS_HD_buf[6],
									GPS_HD_buf[7],GPS_HD_buf[8],GPS_HD_buf[9],GPS_HD_buf[10],GPS_HD_buf[11],GPS_HD_buf[12],GPS_HD_buf[13],
									GPS_HD_buf[14],GPS_HD_buf[15],GPS_HD_buf[16],GPS_HD_buf[17],GPS_HD_buf[18],GPS_HD_buf[19],GPS_HD_buf[20],
									GPS_HD_buf[21],GPS_HD_buf[22],GPS_HD_buf[23],GPS_HD_buf[24],GPS_HD_buf[25],GPS_HD_buf[26],GPS_HD_buf[27]);
	#endif
	
		kjx_gps_uart_write(GPS_HD_buf, len);

		StartTimer(KJX_TIMER_ID_AGPS_HD_CMD_WAIT_TIMEROUT, 2000, kjx_agps_hd_cmd_wait_timerout);
	}
	else
	{
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("GPS已经关闭,AGPS流程终止!");
	#endif
							
		g_kjx_HD_agps_retry_count = 0;
		g_kjx_agps_used = 0;

		g_kjx_HD_agps_send_count = 0;
		memset(g_kjx_HD_agps_send_buf, 0x00, sizeof(g_kjx_HD_agps_send_buf));		
	}
}

/*******************************************************************************************************
//Header:	0xF1 0xD9
//ID:		0x0B 0x10
//Length: 	17
//Payload:	See below
//Checksum:	CK_1 CK_2

//Payload Contents:
//Byte Offset 	Data Type 	Scale 	Name 		Unit 	Description 
// 0 				U1 		   - 		 type 		   - 		Position type
//														(1: LLA, 0: ECEF)

-------------------------------------------------------------------------------------------------------
//LLA:
// 1 				S4 		10-7	  Lat 		degree 	Latitude 
// 5 				S4 		10-7	  Lon 		degree 	Longitude 
// 9 				S4 				  Alt 		cm 		Altitude 
// 13 				U4 				Pos_acc 		 - 		Position accuracy

-------------------------------------------------------------------------------------------------------
//ECEF
// 1 				S4 				ECEF.x 		cm 		Position x
// 5 				S4 				ECEF.y 		cm 		Position y
// 9 				S4 				ECEF.z 		cm 		Position z
// 13 				U4 				Pos_acc 		 - 		Position accuracy

For example: 
Inject position (0x0B10), lat = 22.5006727, lon = 114.2424747, alt = -882.55
Command: F1 D9 0B 10 11 00 01 87 54 69 0D AB 04 18 44 41 A7 FE FF 00 00 00 00 6E 4A
*******************************************************************************************************/
void Tracker_HD_AGPS_Put_AID_Pos(double latitude, double longitude)
{
	U8 GPS_HD_head[] = {0xF1,0xD9,0x0B,0x10};
	U8 GPS_HD_buf[128] = {0};
	U8 i=0,len=0,chk1=0,chk2=0;
	S32 LAT,LON,ALT;
	
	if(kjx_gps_is_on())
	{
		//head
		memcpy(GPS_HD_buf, GPS_HD_head, 4);
		len += 4;
		
		//len
		GPS_HD_buf[len++] = 17;
		GPS_HD_buf[len++] = 0;

		//Position type
		GPS_HD_buf[len++] = 1;

		//LLA
		//Lat
		LAT = latitude*pow(10,7);
		GPS_HD_buf[len++] = LAT&0x000000FF;
		GPS_HD_buf[len++] = (LAT&0x0000FF00)>>8;
		GPS_HD_buf[len++] = (LAT&0x00FF0000)>>16;
		GPS_HD_buf[len++] = (LAT&0xFF000000)>>24;
		//Lon
		LON = longitude*pow(10,7);
		GPS_HD_buf[len++] = LON&0x000000FF;
		GPS_HD_buf[len++] = (LON&0x0000FF00)>>8;
		GPS_HD_buf[len++] = (LON&0x00FF0000)>>16;
		GPS_HD_buf[len++] = (LON&0xFF000000)>>24;
		//Alt
		ALT = -882.55*pow(10,2);
		GPS_HD_buf[len++] = ALT&0x000000FF;
		GPS_HD_buf[len++] = (ALT&0x0000FF00)>>8;
		GPS_HD_buf[len++] = (ALT&0x00FF0000)>>16;		
		GPS_HD_buf[len++] = (ALT&0xFF000000)>>24;		
		//Pos_acc
		memset(&GPS_HD_buf[len], 0x00, 4);
		len += 4;

		for(i=2;i<len;i++)
		{
			chk1 += GPS_HD_buf[i];
			chk2 += chk1;
		}
		//chksum
		GPS_HD_buf[len++] = chk1;
		GPS_HD_buf[len++] = chk2;

	#if 0	//defined(__KJX_LOG_OUTPUT__)
		LOGD("len:%d CMD:%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X", 
									len, 
									GPS_HD_buf[0],GPS_HD_buf[1],GPS_HD_buf[2],GPS_HD_buf[3],GPS_HD_buf[4],GPS_HD_buf[5],GPS_HD_buf[6],
									GPS_HD_buf[7],GPS_HD_buf[8],GPS_HD_buf[9],GPS_HD_buf[10],GPS_HD_buf[11],GPS_HD_buf[12],GPS_HD_buf[13],
									GPS_HD_buf[14],GPS_HD_buf[15],GPS_HD_buf[16],GPS_HD_buf[17],GPS_HD_buf[18],GPS_HD_buf[19],GPS_HD_buf[20],
									GPS_HD_buf[21],GPS_HD_buf[22],GPS_HD_buf[23],GPS_HD_buf[24]);
	#endif
	
		kjx_gps_uart_write(GPS_HD_buf, len);

		StartTimer(KJX_TIMER_ID_AGPS_HD_CMD_WAIT_TIMEROUT, 2000, kjx_agps_hd_cmd_wait_timerout);
	}
	else
	{
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("GPS已经关闭,AGPS流程终止!");
	#endif
							
		g_kjx_HD_agps_retry_count = 0;
		g_kjx_agps_used = 0;

		g_kjx_HD_agps_send_count = 0;
		memset(g_kjx_HD_agps_send_buf, 0x00, sizeof(g_kjx_HD_agps_send_buf));		
	}
}


/*******************************************************************************************************
//Header:	0xF1 0xD9
//ID:		0x0B 0x32
//Length:
//Payload:	See below
//Checksum:	CK_1 CK_2

//Payload Contents:
// 在注入星历时，该长度信息可以随着星历的条数而变，最多五条星历；目前在
// AGNSS 服务器上的星历都是按最大 5 个星历信息进行打包，即其 Length=325，最后不足
// 5 个的则以实际卫星个数进行打包。如：若要一次注入五个卫星的星历：则该长度信息为
// 65*5=325
*******************************************************************************************************/
void Tracker_HD_AGPS_Put_AID_PEPH_GPS(U8 *data, U32 datalen)
{
	U8 GPS_HD_head[] = {0xF1,0xD9,0x0B,0x32};
	U8 GPS_HD_agps_buf[1024] = {0};
	U8 chk1=0,chk2=0;
	U32 i=0,len=0;

	if(kjx_gps_is_on())
	{
		//head
		memset(GPS_HD_agps_buf, 0x00, sizeof(GPS_HD_agps_buf));
		memcpy(GPS_HD_agps_buf, GPS_HD_head, 4);
		len += 4;
		
		//len
		GPS_HD_agps_buf[len++] = datalen&0x00FF;
		GPS_HD_agps_buf[len++] = (datalen&0xFF00)>>8;

		//GPS ephemeris data
		memcpy(&GPS_HD_agps_buf[len], data, datalen);
		len += datalen;

		for(i=2;i<len;i++)
		{
			chk1 += GPS_HD_agps_buf[i];
			chk2 += chk1;
		}
		//chksum
		GPS_HD_agps_buf[len++] = chk1;
		GPS_HD_agps_buf[len++] = chk2;

	#if 0	//defined(__KJX_LOG_OUTPUT__)
		LOGD("len:%d CMD:%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X", 
									len, 
									GPS_HD_agps_buf[0],GPS_HD_agps_buf[1],GPS_HD_agps_buf[2],GPS_HD_agps_buf[3],GPS_HD_agps_buf[4],GPS_HD_agps_buf[5],GPS_HD_agps_buf[6],
									GPS_HD_agps_buf[7],GPS_HD_agps_buf[8],GPS_HD_agps_buf[9],GPS_HD_agps_buf[10],GPS_HD_agps_buf[11],GPS_HD_agps_buf[12],GPS_HD_agps_buf[13],
									GPS_HD_agps_buf[14],GPS_HD_agps_buf[15],GPS_HD_agps_buf[16],GPS_HD_agps_buf[17],GPS_HD_agps_buf[18],GPS_HD_agps_buf[19],GPS_HD_agps_buf[20],
									GPS_HD_agps_buf[21],GPS_HD_agps_buf[22],GPS_HD_agps_buf[23],GPS_HD_agps_buf[24]);
	#endif

		kjx_gps_uart_write(GPS_HD_agps_buf, len);

		StartTimer(KJX_TIMER_ID_AGPS_HD_CMD_WAIT_TIMEROUT, 2000, kjx_agps_hd_cmd_wait_timerout);
	}
	else
	{
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("GPS已经关闭,AGPS流程终止!");
	#endif
							
		g_kjx_HD_agps_retry_count = 0;
		g_kjx_agps_used = 0;

		g_kjx_HD_agps_send_count = 0;
		memset(g_kjx_HD_agps_send_buf, 0x00, sizeof(g_kjx_HD_agps_send_buf));		
	}
}


/*******************************************************************************************************
//Header:	0xF1 0xD9
//ID:		0x0B 0x33
//Length: 	
//Payload:	See below
//Checksum:	CK_1 CK_2

//Payload Contents:
// 在注入北斗星历时，该长度信息可以随着星历的条数而变，最多五条星历；目前在
// AGNSS 服务器上的星历都是按最大 5 个星历信息进行打包，即其 Length=460，最后不足
// 5 个的则以实际卫星个数进行打包。
*******************************************************************************************************/
void Tracker_HD_AGPS_Put_AID_PEPH_BDS(U8 *data, U32 datalen)
{
	U8 GPS_HD_head[] = {0xF1,0xD9,0x0B,0x33};
	U8 GPS_HD_agps_buf[1024] = {0};
	U8 chk1=0,chk2=0;
	U32 i=0,len=0;
			
	if(kjx_gps_is_on())
	{
		//head
		memcpy(GPS_HD_agps_buf, 0x00, sizeof(GPS_HD_agps_buf));
		memcpy(GPS_HD_agps_buf, GPS_HD_head, 4);
		len += 4;
		
		//len
		GPS_HD_agps_buf[len++] = datalen&0x00FF;
		GPS_HD_agps_buf[len++] = (datalen&0xFF00)>>8;

		//BDS ephemeris data
		memcpy(&GPS_HD_agps_buf[len], data, datalen);
		len += datalen;

		for(i=2;i<len;i++)
		{
			chk1 += GPS_HD_agps_buf[i];
			chk2 += chk1;
		}
		//chksum
		GPS_HD_agps_buf[len++] = chk1;
		GPS_HD_agps_buf[len++] = chk2;

	#if 0	//defined(__KJX_LOG_OUTPUT__)
		LOGD("len:%d CMD:%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X", 
									len, 
									GPS_HD_agps_buf[0],GPS_HD_agps_buf[1],GPS_HD_agps_buf[2],GPS_HD_agps_buf[3],GPS_HD_agps_buf[4],GPS_HD_agps_buf[5],GPS_HD_agps_buf[6],
									GPS_HD_agps_buf[7],GPS_HD_agps_buf[8],GPS_HD_agps_buf[9],GPS_HD_agps_buf[10],GPS_HD_agps_buf[11],GPS_HD_agps_buf[12],GPS_HD_agps_buf[13],
									GPS_HD_agps_buf[14],GPS_HD_agps_buf[15],GPS_HD_agps_buf[16],GPS_HD_agps_buf[17],GPS_HD_agps_buf[18],GPS_HD_agps_buf[19],GPS_HD_agps_buf[20],
									GPS_HD_agps_buf[21],GPS_HD_agps_buf[22],GPS_HD_agps_buf[23],GPS_HD_agps_buf[24]);
	#endif
	
		kjx_gps_uart_write(GPS_HD_agps_buf, len);

		StartTimer(KJX_TIMER_ID_AGPS_HD_CMD_WAIT_TIMEROUT, 2000, kjx_agps_hd_cmd_wait_timerout);
	}
	else
	{
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("GPS已经关闭,AGPS流程终止!");
	#endif
							
		g_kjx_HD_agps_retry_count = 0;
		g_kjx_agps_used = 0;

		g_kjx_HD_agps_send_count = 0;
		memset(g_kjx_HD_agps_send_buf, 0x00, sizeof(g_kjx_HD_agps_send_buf));		
	}
}

void kjx_agps_start_from_step(void)
{
	U32 datalen;
    applib_time_struct rtc_time,utc_time;

	switch(g_kjx_HD_agps_step)
	{
	case STEP_AID_READY:
		break;
		
	case STEP_AID_TIME:
		memset(&rtc_time, 0x00, sizeof(rtc_time));
	    applib_dt_get_rtc_time(&rtc_time);	
		applib_dt_rtc_to_utc_with_default_tz(&rtc_time, &utc_time);
	#if 0	//defined(__KJX_LOG_OUTPUT__)
		LOGD("utc_time:%04d-%02d-%02d %02d:%02d:%02d", utc_time.nYear, utc_time.nMonth, utc_time.nDay, utc_time.nHour, utc_time.nMin, utc_time.nSec);
	#endif
	
		Tracker_HD_AGPS_Put_AID_Time(utc_time);
		break;

	case STEP_AID_POS:
		Tracker_HD_AGPS_Put_AID_Pos(g_kjx_HD_agps_lat, g_kjx_HD_agps_lon);
		break;

	case STEP_AID_PEPH_GPS:
		kjx_agps_hd_send_agps_data(g_kjx_agps_buffer, g_kjx_agps_date_len);
		break;

	case STEP_AID_PEPH_BDS:
		kjx_agps_hd_send_agps_data(g_kjx_agps_buffer, g_kjx_agps_date_len);
		break;

	case STEP_AID_MAX:
		break;
	}
}

void kjx_hd_agps_begin(void)
{
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_kjx_time_sync:%d", g_kjx_time_sync);
#endif

	if(g_kjx_time_sync)
	{
		g_kjx_HD_agps_step = STEP_AID_TIME;
		kjx_agps_start_from_step();
	}
	else
	{
		StartTimer(KJX_TIMER_ID_GPS_AGPS_STATE, 500, kjx_hd_agps_begin);
	}
}
#endif

void kjx_agps_socket_session_free(void)
{
   ClearProtocolEventHandler(MSG_ID_APP_SOC_NOTIFY_IND);

   if(g_kjx_agps_socket_context.socket_id != SOC_ERROR)
       g_kjx_socket_event_func.socket_event_close(g_kjx_agps_socket_context.socket_id);

   kjx_agps_socket_init();
}

void kjx_agps_socket_connect_ublox(void)
{
	S32 result = 0;
	S32 pkgSize = 0;
	kjx_ublox_agps_request_pack_struct *agps = &g_kjx_ublox_agps_request;
	
	memset(g_kjx_agps_socket_context.pSendBuff, 0x00, sizeof(g_kjx_agps_socket_context.pSendBuff));
	sprintf(g_kjx_agps_socket_context.pSendBuff,"cmd=%s;user=%s;pwd=%s;lat=%s;lon=%s;pacc=%d",agps->cmd,agps->user,agps->pwd,agps->lat,
						agps->lon,agps->pacc);
	pkgSize = strlen(g_kjx_agps_socket_context.pSendBuff);
	result = kjx_socket_send(g_kjx_agps_socket_context.socket_id, g_kjx_agps_socket_context.pSendBuff, pkgSize);
    
	if(pkgSize != result)
	{
		kjx_agps_socket_session_free();
	}
}

S32 kjx_agps_check_read_data_len(S8 *r_buffer)
{
	S32 len = 0;
	S8 *start_p = NULL;

	start_p = strstr(r_buffer,"Content-Length: ");
	start_p +=strlen("Content-Length: ");
	len = atoi(start_p);
	return len;
}

void kjx_agps_socket_read_handle(void)
{
	S32 result = 0;
	static S32 read_len=0;
	S8 *agps_ptr =  NULL;
	U8 *buffer_ptr =  NULL;
	U16 agps_len = 0;
	static U8 read_cnt=0;
	S32 body_len = 0;
	S32 head_len = 0;
	S32 tcp_data_len = 0;
	kal_uint16 len=0,write_len=0,send_len=0;

#if defined(__KJX_FUN__)&&defined(__KJX_FUN_STEPS__)
	extern BOOL kjx_is_use_steps(void);
	extern BOOL kjx_is_use_heart(void);
	extern U16 kjx_is_in_call(void);
	if(kjx_is_use_steps()||kjx_is_use_heart()||kjx_is_in_call())
	{     
		return;
	}
#endif

	if(read_len==0)
	{
		memset(g_kjx_agps_socket_context.pRecvBuff,0x00,sizeof(g_kjx_agps_socket_context.pRecvBuff));
	}
	
	result = kjx_socket_recv(g_kjx_agps_socket_context.socket_id, g_kjx_agps_socket_context.pRecvBuff+read_len, g_kjx_agps_socket_context.recvBuffsize-read_len);
	read_len += result;
	body_len = kjx_agps_check_read_data_len(g_kjx_agps_socket_context.pRecvBuff);

	agps_ptr = strstr((const char*)g_kjx_agps_socket_context.pRecvBuff,"\r\n\r\n");
	agps_ptr += strlen("\r\n\r\n");

	head_len = agps_ptr - g_kjx_agps_socket_context.pRecvBuff;

	tcp_data_len = head_len + body_len;
	
	//如果AGPS数据过大，接收不下，则接收多少写多少
	if(tcp_data_len == read_len ||(tcp_data_len > sizeof(g_kjx_agps_buffer)))
	{
		memset(g_kjx_agps_buffer,0,sizeof(g_kjx_agps_buffer));
		memcpy(g_kjx_agps_buffer,agps_ptr,body_len);
		read_len = 0;

		if(body_len>0)
		{ 
			while(write_len<body_len)
			{             
				buffer_ptr = g_kjx_agps_buffer;
				
				send_len = kjx_gps_uart_write(buffer_ptr+write_len,body_len - write_len);
				write_len += send_len;
				buffer_ptr += write_len;
				
			#if defined(mmi_include_use_header)
			#if defined(CUSTOMER_NAME_W80)
				if(memcmp((char *)release_verno(),"W80.V4.0\0", strlen("W80.V4.0\0"))!=0)
			#elif defined(CUSTOMER_NAME_A3)
				if(memcmp((char *)release_verno(),"A3.V4.0", strlen("A3.V4.0"))!=0)
			#endif
				{
					write_len -= send_len;
				}
			#endif
				kal_sleep_task(1000);
			}

		}

		g_kjx_agps_used = 1;
		kjx_agps_socket_session_free();
		
		// 开机就打开AGPS，会影响到登陆，所以AGPS完成后，重新发送登陆包
		//city_easy_socket_login_again();
	}		 
}

void kjx_agps_set_data_acc_rsp(kjx_socket_event_func *socket_func,kal_uint32 *msg,kjxNetInfo *kjxNet,kjx_access_id access_id)
{
   kal_uint32 accountId = *msg;

   if(g_kjx_agps_socket_context.socket_id>=0)
   {
       socket_func->socket_event_close(g_kjx_agps_socket_context.socket_id);
   }
   
   g_kjx_agps_socket_context.socket_id = socket_func->socket_event_create(accountId);
   g_kjx_agps_socket_context.access_id = access_id;
   
   socket_func->get_host_by_name_req(socket_func,accountId, g_kjx_agps_socket_context.socket_id, (const S8 *)kjxNet->domain, kjxNet->port, g_kjx_agps_socket_context.access_id);
}

void kjx_ublox_agps_request(void)
{
	StopTimer(KJX_TIMER_ID_AGPS_START);

	if(g_kjx_agps_used == 1)
	{
		return;
	}
   
	if(srv_nw_info_get_service_availability(MMI_SIM1) == SRV_NW_INFO_SA_FULL_SERVICE)
	{
		kjx_agps_socket_init();
		kjx_set_gprs_data_acount(&g_kjx_socket_event_func,&g_kjxAgpsInfo,KJX_SOC_AGPS, kjx_agps_set_data_acc_rsp);
	}
	else
	{
		StartTimer(KJX_TIMER_ID_AGPS_START, 1000*2, kjx_ublox_agps_request);
	}
}


void kjx_agps_socket_init(void)
{
    memset(g_kjx_agps_socket_context.pRecvBuff, 0x00,sizeof(g_kjx_agps_socket_context.pRecvBuff));
    memset(g_kjx_agps_socket_context.pSendBuff, 0x00,sizeof(g_kjx_agps_socket_context.pSendBuff));
    g_kjx_agps_socket_context.totalSize = 0;
    g_kjx_agps_socket_context.recvBuffsize = KJX_AGPS_SOCKET_BUFF_SIZE;
    g_kjx_agps_socket_context.socket_id = -1;
    g_kjx_agps_socket_context.access_id = 0;
}

U32 kjx_agps_read_data_from_file(U8 *databuf, U32 buflen)
{
	kal_uint32 fs_len;
	FS_HANDLE handle;
	S8 usc2Path[128] = {0};
	U8 tmpbuf[50] = {0};
	FS_FileInfo fileInfor;
	applib_time_struct sysdatetime,filedatetime;
	
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif

	kal_wsprintf((WCHAR*)usc2Path, "%c%w", SRV_FMGR_PUBLIC_DRV, L":\\");
	mmi_ucs2cat((CHAR*)usc2Path, (const CHAR*)KJX_AGPS_DATA_FILE_NAME);
	
	FS_SetAttributes((WCHAR*)usc2Path, FS_ATTR_ARCHIVE);
	handle = FS_Open((WCHAR*)usc2Path, FS_READ_ONLY | FS_ATTR_ARCHIVE);
	if(handle>=FS_NO_ERROR)
	{
		FS_GetFileInfo(handle, &fileInfor);

	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("size:%d", fileInfor.DirEntry->FileSize);
	#endif

		if(fileInfor.DirEntry->FileSize == 0)
		{
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("文件内容为空!");
		#endif
			FS_Close(handle);
			return 0;
		}

		memset(g_kjx_agps_valid_time, 0, sizeof(g_kjx_agps_valid_time));
		FS_Read(handle, (void*)g_kjx_agps_valid_time, 14, &fs_len);//20180308121314
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("valid_time:%s", g_kjx_agps_valid_time);
	#endif
		memset(&filedatetime, 0, sizeof(applib_time_struct));
		//Year
		memset(tmpbuf, 0, sizeof(tmpbuf));
		memcpy(tmpbuf, g_kjx_agps_valid_time, 4);
		filedatetime.nYear = atoi(tmpbuf);
		//Month
		memset(tmpbuf, 0, sizeof(tmpbuf));
		memcpy(tmpbuf, g_kjx_agps_valid_time+4, 2);
		filedatetime.nMonth = atoi(tmpbuf);
		//Day
		memset(tmpbuf, 0, sizeof(tmpbuf));
		memcpy(tmpbuf, g_kjx_agps_valid_time+6, 2);
		filedatetime.nDay = atoi(tmpbuf);
		//Hour
		memset(tmpbuf, 0, sizeof(tmpbuf));
		memcpy(tmpbuf, g_kjx_agps_valid_time+8, 2);
		filedatetime.nHour = atoi(tmpbuf);
		//Minute
		memset(tmpbuf, 0, sizeof(tmpbuf));
		memcpy(tmpbuf, g_kjx_agps_valid_time+10, 2);
		filedatetime.nMin = atoi(tmpbuf);
		//Second
		memset(tmpbuf, 0, sizeof(tmpbuf));
		memcpy(tmpbuf, g_kjx_agps_valid_time+12, 2);
		filedatetime.nSec = atoi(tmpbuf);
		
		applib_dt_get_date_time(&sysdatetime);
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("system:%04d-%02d-%02d %02d:%02d:%02d, filevalid:%04d-%02d-%02d %02d:%02d:%02d", 
									sysdatetime.nYear,
									sysdatetime.nMonth,
									sysdatetime.nDay,
									sysdatetime.nHour,
									sysdatetime.nMin,
									sysdatetime.nSec, 
									filedatetime.nYear,
									filedatetime.nMonth,
									filedatetime.nDay,
									filedatetime.nHour,
									filedatetime.nMin,
									filedatetime.nSec);
	#endif
		
		if(applib_dt_compare_time(&filedatetime, &sysdatetime, NULL) == DT_TIME_LESS)
		{
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("星历数据已失效，需要重新下载更新!");
		#endif
			FS_Close(handle);
			return 0;
		}
		
		memset(databuf, 0x00, buflen);
		FS_Read(handle, (void*)databuf, fileInfor.DirEntry->FileSize - 14, &fs_len);
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("data_len:%d", fs_len);
	#endif
		FS_Close(handle);

		return fs_len;
	}
	else
	{
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("文件不存在");
	#endif
		return 0;
	}	
}

void kjx_agps_data_write_to_file(U8 *databuf, U32 datalen, BOOL delflag)
{
	kal_uint32 fs_len;
	FS_HANDLE handle;
	int result;
	S8 usc2Path[128] = {0};
	UINT filesize;

#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif

	kal_wsprintf((WCHAR*)usc2Path, "%c%w", SRV_FMGR_PUBLIC_DRV, L":\\");
	mmi_ucs2cat((CHAR*)usc2Path, (const CHAR*)KJX_AGPS_DATA_FILE_NAME);
	if(delflag)
	{
		handle = FS_Open((WCHAR*)usc2Path, FS_READ_WRITE); 
		if(!(handle < FS_NO_ERROR))
	    { 
	    	FS_Close(handle);
        	result = FS_Delete((WCHAR*)usc2Path); 
		#if defined(__KJX_LOG_OUTPUT__) 
			LOGD("删除以前的星历文件1 result:%d", result); 
		#endif
		}
		else
		{
			FS_Close(handle);
			result = FS_Delete((WCHAR*)usc2Path); 
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("删除以前的星历文件2 result:%d", result);
		#endif
		}
	}

	FS_SetAttributes((WCHAR*)usc2Path, FS_ATTR_ARCHIVE);
	handle = FS_Open((WCHAR*)usc2Path, FS_READ_WRITE | FS_ATTR_ARCHIVE);
	if(handle >= FS_NO_ERROR)
	{
		FS_Seek(handle, 0, FS_FILE_END);
		FS_Write(handle, (void*)databuf, datalen, &fs_len);
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("星历文件存在,数据添加到末尾 fs_len:%d", fs_len);
	#endif
		FS_Close(handle);
	}
	else
	{
		handle = FS_Open((WCHAR*)usc2Path, FS_READ_WRITE | FS_CREATE | FS_ATTR_ARCHIVE);
		if(handle>=FS_NO_ERROR)
		{
			FS_Write(handle, (void*)g_kjx_agps_valid_time, 14, &fs_len);//20180308121314
			FS_Write(handle, (void*)databuf, datalen, &fs_len);
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("星历文件不存在,重新创建添加 fs_len:%d", fs_len);
		#endif
			FS_Close(handle);
		}
		else
		{
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("文件创建失败!");
		#endif
		}
	}	
}

void kjx_handle_get_agps_data(void)
{
#ifdef RFID_DEBUG	
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	if(mmi_bootup_is_sim_valid())
	{
		switch(g_kjx_gps_category)
		{
		case GPS_ZKW_MODE:
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("中科微模块");
		#endif
		
			kjx_socket_send_data_with_type(SERVER_TYPE_83);
			break;

		#ifdef __KJX_FUN_GPS_HD__
		case GPS_HD_MODE:
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("华大模块");
		#endif

			kjx_socket_send_data_with_type(SERVER_TYPE_85);
			break;
		#endif
		}
	}
}

void kjx_agps_start(void)
{
	U32 datalen;

	return;//baiwenlin 20200726
	StopTimer(KJX_TIMER_ID_GPS_AGPS_STATE);
	
	if(g_kjx_agps_used == 1)
	{
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("AGPS流程已经启动!");
	#endif
		return;
	}

	datalen = kjx_agps_read_data_from_file(g_kjx_agps_buffer, KJX_AGPS_DATA_MAX_LEN);
	if(datalen > 0)
	{
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("AGPS文件存在!GPS模块类型:%d",	g_kjx_gps_category);
	#endif

		g_kjx_agps_used = 1;
		g_kjx_agps_date_len = datalen;

		switch(g_kjx_gps_category)
		{
		case GPS_ZKW_MODE:
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("中科微模块，直接灌星!");
		#endif
		
			kjx_agps_start_push_data_to_mode(g_kjx_agps_buffer, datalen);
			g_kjx_agps_used = 0;
			break;

	#ifdef __KJX_FUN_GPS_HD__
		case GPS_HD_MODE:
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("华大模块，启动指令!");
		#endif

			if((g_kjx_HD_agps_lon != 0)&&(g_kjx_HD_agps_lat != 0))
			{
				kjx_hd_agps_begin();
			}
			else
			{
				kjx_handle_get_agps_data();
			}
			break;
	#endif
		}
	}
	else
	{
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("AGPS文件不存在，从后台获取!GPS模块类型:%d", g_kjx_gps_category);
	#endif

		if(g_kjx_gps_category == GPS_MAX_MODE)
		{
			StartTimer(KJX_TIMER_ID_GPS_AGPS_STATE, 500, kjx_agps_start);
		}
		else
		{
			g_kjx_agps_used = 1;
			kjx_handle_get_agps_data();
		}
	}
}
#endif/*__KJX_FUN_AGPS__*/
