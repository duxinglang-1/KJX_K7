/**********************************************************************************
*Filename:     kjx_gps_main.c
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2013/12/19
*
***********************************************************************************/
#if defined(__KJX_FUN__)
#include "kjx_include.h"
#include <math.h>
#if defined(__KJX_FUN_GPS__)
S8 old_lat[9]={0};
S8 old_lng[10]={0};
#define PI                      3.1415926
const double EARTH_RADIUS = 6378.137;//地球半径

U16 g_gps_is_on = 0;

#ifdef __KJX_RFID__
extern U16 g_rfid_is_on ;
#endif
extern kal_uint8 g_SleepMode;
extern kjx_gps_data g_kjx_gps_data;
extern BOOL g_kjx_time_sync;

void kjx_gps_disable_sleep(void)
{
	if(g_SleepMode == 0xff)
		g_SleepMode = L1SM_GetHandle();

	g_gps_is_on = 1;
	L1SM_SleepDisable(g_SleepMode);
}

void kjx_gps_enable_sleep(void)
{
	//baiwenlin 20200726
	//return;

	if(g_SleepMode == 0xff)
		g_SleepMode = L1SM_GetHandle();

	g_gps_is_on = 0;

#ifdef __KJX_RFID__
	if(g_rfid_is_on == 0)
#endif
	L1SM_SleepEnable(g_SleepMode);
}

void kjx_gps_extern_do_somthing(U8 *data,U16 data_len)
{
#if defined(__KJX_DOG__)
#if defined(__KJX_INFRARED__)
	if(kjx_dog_flag)
#endif
	{
		kjx_dog_gps_data_decode(data,data_len);	  
		kjx_dog_get_data_start();
	}
#endif	 

}

void kjx_gps_time_sync(kjx_gps_data g_kjx_gps_data)
{
    applib_time_struct utc_time;
    applib_time_struct rtc_time;

	if((g_kjx_time_sync == FALSE) && (g_kjx_gps_data.data_status == 'A'))
	{
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("gps_date:%04d-%02d-%02d, gps_time:%02d:%02d:%02d", 
				g_kjx_gps_data.date.nYear,
				g_kjx_gps_data.date.nMonth,
				g_kjx_gps_data.date.nDay,
				g_kjx_gps_data.date.nHour,
				g_kjx_gps_data.date.nMin,
				g_kjx_gps_data.date.nSec
				);
	#endif

		g_kjx_time_sync = TRUE;

	    utc_time.nYear = (U16)(2000 + g_kjx_gps_data.date.nYear);
	    utc_time.nMonth = (U8)g_kjx_gps_data.date.nMonth;
	    utc_time.nDay = (U8)g_kjx_gps_data.date.nDay;
	    utc_time.nHour = (U8)g_kjx_gps_data.date.nHour;
	    utc_time.nMin = (U8)g_kjx_gps_data.date.nMin;
	    utc_time.nSec = (U8)g_kjx_gps_data.date.nSec;
		
	    applib_dt_utc_to_rtc_with_default_tz(&utc_time, &rtc_time);
	    mmi_dt_set_rtc_dt((MYTIME *)&rtc_time);
	}
}

void kjx_gps_do_something_with_data(kjx_gps_func* g_kjx_gps_func,kjx_gps_data g_kjx_gps_data)
{
     g_kjx_gps_func->gps_time_sync(g_kjx_gps_data);
     g_kjx_gps_func->gps_do_something_with_custom(g_kjx_gps_data);
}

void kjx_gps_get_data_with_decode(char* gps_data,int len,kjx_gps_func* g_kjx_gps_func)
{
     g_kjx_gps_func->gps_data_decode(gps_data,len);
     g_kjx_gps_func->gps_do_something_with_data(g_kjx_gps_func,g_kjx_gps_data);
}

static double kjx_move_rad(double d)
{ 
	return d * PI / 180.0;   //角度1? = π / 180
} 

double kjx_get_lbs_distance(U8 signal_leve)
{
	double zhishu = 0;
	double n = 2.0;//功率损耗系数
	double a = 24.5;//经验常数，由环境决定，暂定
	double dist = 0.0;

	if(signal_leve>=64||signal_leve == 0)
		return dist;

	zhishu = (108-signal_leve-a)/(10*n);
	dist = pow(10,zhishu);
	return dist;
}

double kjx_get_distance(double lat1, double lng1, double lat2, double lng2)
{
   double radLat1 = kjx_move_rad(lat1);
   double radLat2 = kjx_move_rad(lat2);
   double a = radLat1 - radLat2;
   double b = kjx_move_rad(lng1) - kjx_move_rad(lng2);
   double dst = 2 * asin((sqrt(pow(sin(a / 2), 2) + cos(radLat1) * cos(radLat2) * pow(sin(b / 2), 2) )));
   
   dst = dst * EARTH_RADIUS;
   dst = dst * 1000;/*1km=1000m*/
   
#ifdef __MTK_TARGET__
   dst = (lround(dst * 10000)) / 10000;
#endif

   return dst;
}

double kjx_set_lat_and_lng_data(S8* lat1, S8* lng1, S8* lat2, S8* lng2)
{
   double relat1 = 0,relat2 =0,relng1 = 0,relng2 = 0,reDistance=0;
   S8 dataBuf1[16];
   S8 dataBuf2[16];
   char* pos=NULL;

   pos=strstr(lat1,".");
   if(pos)
   {
      memset(dataBuf1, 0x00, sizeof(dataBuf1));
      memcpy(dataBuf1,lat1, strlen(lat1)-strlen(pos));
	  
      memset(dataBuf2, 0x00, sizeof(dataBuf2));
      memcpy(dataBuf2,dataBuf1, strlen(dataBuf1)-2);

      relat1=atoi(dataBuf2);
	  
      memset(dataBuf2, 0x00, sizeof(dataBuf2));
      memcpy(dataBuf2,lat1+(strlen(dataBuf1)-2), strlen(lat1)-(strlen(dataBuf1)-2));

      relat1 += (atof(dataBuf2)/60);
   }

   pos=strstr(lat2,".");
   if(pos)
   {
      memset(dataBuf1, 0x00, sizeof(dataBuf1));
      memcpy(dataBuf1,lat2, strlen(lat2)-strlen(pos));
	  
      memset(dataBuf2, 0x00, sizeof(dataBuf2));
      memcpy(dataBuf2,dataBuf1, strlen(dataBuf1)-2);

      relat2=atoi(dataBuf2);
	  
      memset(dataBuf2, 0x00, sizeof(dataBuf2));
      memcpy(dataBuf2,lat2+(strlen(dataBuf1)-2), strlen(lat2)-(strlen(dataBuf1)-2));

      relat2 += (atof(dataBuf2)/60);
   }


   pos=strstr(lng1,".");
   if(pos)
   {
      memset(dataBuf1, 0x00, sizeof(dataBuf1));
      memcpy(dataBuf1,lng1, strlen(lng1)-strlen(pos));
	  
      memset(dataBuf2, 0x00, sizeof(dataBuf2));
      memcpy(dataBuf2,dataBuf1, strlen(dataBuf1)-2);

      relng1=atoi(dataBuf2);
	  
      memset(dataBuf2, 0x00, sizeof(dataBuf2));
      memcpy(dataBuf2,lng1+(strlen(dataBuf1)-2), strlen(lng1)-(strlen(dataBuf1)-2));

      relng1 += (atof(dataBuf2)/60);
   }


   pos=strstr(lng2,".");
   if(pos)
   {
      memset(dataBuf1, 0x00, sizeof(dataBuf1));
      memcpy(dataBuf1,lng2, strlen(lng2)-strlen(pos));
	  
      memset(dataBuf2, 0x00, sizeof(dataBuf2));
      memcpy(dataBuf2,dataBuf1, strlen(dataBuf1)-2);

      relng2=atoi(dataBuf2);
	  
      memset(dataBuf2, 0x00, sizeof(dataBuf2));
      memcpy(dataBuf2,lng2+(strlen(dataBuf1)-2), strlen(lng2)-(strlen(dataBuf1)-2));

      relng2 += (atof(dataBuf2)/60);
   }

   reDistance = kjx_get_distance(relat1,relng1,relat2,relng2);

   return reDistance;

}
#else
double kjx_get_lbs_distance(U8 signal_leve)
{
	double zhishu = 0;
	double n = 2.0;//功率损耗系数
	double a = 24.5;//经验常数，由环境决定，暂定
	double dist = 0.0;

	if(signal_leve>=64||signal_leve == 0)
		return dist;

	zhishu = (108-signal_leve-a)/(10*n);
	dist = pow(10,zhishu);
	return dist;
}
#endif/*__KJX_FUN_GPS__*/

void kjx_gps_main(void)
{    
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif

#if defined(__KJX_FUN_GPS__)
    kjx_gps_func_init();
    kjx_gps_tack_gps_init();
#endif
}

#endif/*__KJX_FUN__*/
