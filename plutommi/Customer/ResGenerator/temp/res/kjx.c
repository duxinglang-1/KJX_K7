#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_KJX">
    <!-----------------------------------------------------String Resource Area------------------------------------------------------>   
	<!--String Resource Area-->
		<STRING id="STR_KJX_OUTCALL_SOS1">"SOS 1"</STRING>
		<STRING id="STR_KJX_OUTCALL_SOS2">"SOS 2"</STRING>
		<STRING id="STR_KJX_OUTCALL_SOS3">"SOS 3"</STRING>
		<STRING id="STR_KJX_OUTCALL_WHITE_NUM">"WHITE NUMBER"</STRING>
		<STRING id="STR_KJX_OUTCALL_NONUMBER">"no number!"</STRING>
		<STRING id="STR_KJX_INCOMING_CALL">"incoming call"</STRING>
		<STRING id="STR_KJX_IN_CALLING">"calling"</STRING>
		<STRING id="STR_KJX_IDLE_SHOW_TOUR">"Beidou Tour Card"</STRING>
		<STRING id="STR_KJX_IDLE_INCOMING_CALL">"Incoming call"</STRING>
		<STRING id="STR_KJX_IDLE_OUTGOING_CALL">"Outgoing call"</STRING>
		<STRING id="STR_KJX_IDLE_IN_CALLING">"In calling"</STRING>
		<STRING id="STR_KJX_IDLE_TEMPERATURE">"Temperature"</STRING>	    
		<STRING id="STR_KJX_IDLE_ATMOSPHERE">"Atmosphere"</STRING>	
		<STRING id="STR_KJX_IDLE_ALTITUDE">"Altitude"</STRING>	
		<STRING id="STR_KJX_IDLE_STEP">"Step"</STRING>		
		<STRING id="STR_KJX_IDLE_CALORIE">"Calorie"</STRING>		
		<STRING id="STR_KJX_IDLE_WEEK_SUNDAY">"Sunday"</STRING>
		<STRING id="STR_KJX_IDLE_WEEK_MONDAY">"Monday"</STRING>
		<STRING id="STR_KJX_IDLE_WEEK_TUESDAY">"Tuesday"</STRING>
		<STRING id="STR_KJX_IDLE_WEEK_WEDNESDAY">"Wednesday"</STRING>
		<STRING id="STR_KJX_IDLE_WEEK_THURSDAY">"Thursday"</STRING>
		<STRING id="STR_KJX_IDLE_WEEK_FRIDAY">"Friday"</STRING>
		<STRING id="STR_KJX_IDLE_WEEK_SATURDAY">"Saturday"</STRING>
		<STRING id="STR_KJX_IDLE_RESET_SUCCESS_BY_RFID">"Reset Success!"</STRING>
		<STRING id="STR_KJX_IDLE_RESET_SUCCESS_BY_RUC">"Reset Success!"</STRING>		
		<STRING id="STR_KJX_NO_SOS_NUMBER">"The SOS number has not been set yet"</STRING>	    	    	    	    	    	    
		<STRING id="STR_KJX_SET_LANGUAGE_ASK">"Do you want to switch language?"</STRING>	
		<STRING id="STR_KJX_SWITCH_LANGUAGE_NOTIFY">"There is only one language!"</STRING>	
		<STRING id="STR_KJX_INCOMING_CALL_END_SMS_1">"It's not convenient to answer your call now,I'll contact you later."</STRING>	
		<STRING id="STR_KJX_INCOMING_CALL_END_SMS_2">"I have received your message,thank you."</STRING>			
	<!--End String Resource Area-->
	<!----------------------------------------------------End String Resource Area--------------------------------------------------->


	<!--------------------------------------------------------Image Resource Area---------------------------------------------------->
	<!--Image Resource Area-->
	#if defined(__KJX_OLED_64_48_UI__)
		<IMAGE id="IMG_GLOBAL_KJX_NUM_BIG_0">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_BIG\\\\0.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_BIG_1">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_BIG\\\\1.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_BIG_2">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_BIG\\\\2.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_BIG_3">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_BIG\\\\3.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_BIG_4">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_BIG\\\\4.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_BIG_5">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_BIG\\\\5.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_BIG_6">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_BIG\\\\6.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_BIG_7">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_BIG\\\\7.bmp"</IMAGE>	
		<IMAGE id="IMG_GLOBAL_KJX_NUM_BIG_8">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_BIG\\\\8.bmp"</IMAGE>	
		<IMAGE id="IMG_GLOBAL_KJX_NUM_BIG_9">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_BIG\\\\9.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_TWO_DOT">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_BIG\\\\two_dot.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_SMALL_0">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_SMALL\\\\0.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_SMALL_1">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_SMALL\\\\1.bmp"</IMAGE>	
		<IMAGE id="IMG_GLOBAL_KJX_NUM_SMALL_2">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_SMALL\\\\2.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_SMALL_3">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_SMALL\\\\3.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_SMALL_4">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_SMALL\\\\4.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_SMALL_5">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_SMALL\\\\5.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_SMALL_6">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_SMALL\\\\6.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_SMALL_7">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_SMALL\\\\7.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_SMALL_8">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_SMALL\\\\8.bmp"</IMAGE>	
		<IMAGE id="IMG_GLOBAL_KJX_NUM_SMALL_9">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_SMALL\\\\9.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_DOT">CUST_IMG_PATH"\\\\MainLCD\\\\NUM_SMALL\\\\dot.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_WEEK_1">CUST_IMG_PATH"\\\\MainLCD\\\\WEEK\\\\1.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_WEEK_2">CUST_IMG_PATH"\\\\MainLCD\\\\WEEK\\\\2.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_WEEK_3">CUST_IMG_PATH"\\\\MainLCD\\\\WEEK\\\\3.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_WEEK_4">CUST_IMG_PATH"\\\\MainLCD\\\\WEEK\\\\4.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_WEEK_5">CUST_IMG_PATH"\\\\MainLCD\\\\WEEK\\\\5.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_WEEK_6">CUST_IMG_PATH"\\\\MainLCD\\\\WEEK\\\\6.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NUM_WEEK_7">CUST_IMG_PATH"\\\\MainLCD\\\\WEEK\\\\7.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_BAT0">CUST_IMG_PATH"\\\\MainLCD\\\\BATTERY\\\\0.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_BAT1">CUST_IMG_PATH"\\\\MainLCD\\\\BATTERY\\\\1.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_BAT2">CUST_IMG_PATH"\\\\MainLCD\\\\BATTERY\\\\2.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_BAT3">CUST_IMG_PATH"\\\\MainLCD\\\\BATTERY\\\\3.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_BAT4">CUST_IMG_PATH"\\\\MainLCD\\\\BATTERY\\\\4.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_BAT_ON_CHARGIMG">CUST_IMG_PATH"\\\\MainLCD\\\\CHARGER\\\\charging.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_BAT_ON_FULL">CUST_IMG_PATH"\\\\MainLCD\\\\CHARGER\\\\charge_full.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NO_SIM">CUST_IMG_PATH"\\\\MainLCD\\\\SIGNAL\\\\0.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_SIGNAL1">CUST_IMG_PATH"\\\\MainLCD\\\\SIGNAL\\\\1.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_SIGNAL2">CUST_IMG_PATH"\\\\MainLCD\\\\SIGNAL\\\\2.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_SIGNAL3">CUST_IMG_PATH"\\\\MainLCD\\\\SIGNAL\\\\3.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_SIGNAL4">CUST_IMG_PATH"\\\\MainLCD\\\\SIGNAL\\\\4.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_SIGNAL5">CUST_IMG_PATH"\\\\MainLCD\\\\SIGNAL\\\\5.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_GPS_OFF">CUST_IMG_PATH"\\\\MainLCD\\\\GPS\\\\gps_off.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_GPS_ON">CUST_IMG_PATH"\\\\MainLCD\\\\GPS\\\\gps_on.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_GPS_OK">CUST_IMG_PATH"\\\\MainLCD\\\\GPS\\\\gps_ok.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_CONNECT">CUST_IMG_PATH"\\\\MainLCD\\\\GPRS\\\\gprs_on.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_UNCONNECT">CUST_IMG_PATH"\\\\MainLCD\\\\GPRS\\\\gprs_off.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_CONNECT_CHECK">CUST_IMG_PATH"\\\\MainLCD\\\\GPRS\\\\gprs_check.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_BT_TURN_ON">CUST_IMG_PATH"\\\\MainLCD\\\\BT\\\\bt_turn_on.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_BT_CONNECT">CUST_IMG_PATH"\\\\MainLCD\\\\BT\\\\bt_connect.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_SENDING">CUST_IMG_PATH"\\\\MainLCD\\\\CALL\\\\call_out.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_CALLING">CUST_IMG_PATH"\\\\MainLCD\\\\CALL\\\\calling.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_CALL_END">CUST_IMG_PATH"\\\\MainLCD\\\\CALL\\\\call_end.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_CALL_SMALL">CUST_IMG_PATH"\\\\MainLCD\\\\CALL\\\\call_small.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_NO_NUMBER">CUST_IMG_PATH"\\\\MainLCD\\\\CALL\\\\call_null.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_INCOMING_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\CALL\\\\call_in.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_STEPS">CUST_IMG_PATH"\\\\MainLCD\\\\STEPS\\\\steps.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_FLOWER_NUM_1">CUST_IMG_PATH"\\\\MainLCD\\\\FLOWER\\\\1.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_FLOWER_NUM_2">CUST_IMG_PATH"\\\\MainLCD\\\\FLOWER\\\\2.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_FLOWER_NUM_3">CUST_IMG_PATH"\\\\MainLCD\\\\FLOWER\\\\3.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_FLOWER_NUM_4">CUST_IMG_PATH"\\\\MainLCD\\\\FLOWER\\\\4.bmp"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_FLOWER_NUM_5">CUST_IMG_PATH"\\\\MainLCD\\\\FLOWER\\\\5.bmp"</IMAGE>
	#endif
	#ifdef __KJX_WEATHER_SUPPORT__
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_BAOXUE">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\baoxue.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_BAOYU">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\baoyu.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_BAOYUZHUANDABAOYU">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\baoyuzhuandabaoyu.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_DABAOYU">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\dabaoyu.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_DABAOYUZHUANTEDABAOYU">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\dabaoyuzhuantedabaoyu.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_DAXUE">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\daxue.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_DAXUEZHUANBAOXUE">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\daxuezhuanbaoxue.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_DAYU">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\dayu.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_DAYUZHUANBAOYU">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\dayuzhuanbaoyu.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_DONGYU">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\dongyu.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_DUOYUN">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\duoyun.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_FUCHEN">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\fuchen.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_LEIZHENYU">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\leizhenyu.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_LEIZHENYUBANYOUBINGBAO">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\leizhenyubanyoubingbao.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_MAI">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\mai.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_QIANGSHACHENBAO">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\qiangshachenbao.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_QING">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\qing.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_SHACHENBAO">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\shachenbao.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_TEDABAOYU">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\tedabaoyu.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_WU">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\wu.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_XIAOXUE">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\xiaoxue.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_XIAOXUEZHUANZHONGXUE">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\xiaoxuezhuanzhongxue.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_XIAOYU">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\xiaoyu.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_XIAOYUZHUANZHONGYU">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\xiaoyuzhuanzhongyu.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_YANGSHA">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\yangsha.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_YIN">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\yin.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_YUJIAXUE">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\yujiaxue.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_ZHENXUE">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\zhenxue.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_ZHENYU">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\zhenyu.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_ZHONGXUE">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\zhongxue.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_ZHONGXUEZHUANDAXUE">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\zhongxuezhuandaxue.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_ZHONGYU">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\zhongyu.png"</IMAGE>
		<IMAGE id="IMG_GLOBAL_KJX_WEATHER_ZHONGYUZHUANDAYU">CUST_IMG_PATH"\\\\MainLCD\\\\Weather\\\\zhongyuzhuandayu.png"</IMAGE>
	#endif
	<!--End Image Resource Area-->
	<!-------------------------------------------------------End Image Resource Area------------------------------------------------->



	<!------------------------------------------------------Screen Resource Area----------------------------------------------------->
	<!--Screen Resource Area-->
	#if defined(__KJX_FUN__)
		<SCREEN id="SCR_ID_PHONE_0"/>
		<SCREEN id="SCR_ID_PHONE_1"/>
		<SCREEN id="SCR_ID_PHONE_2"/>
		<SCREEN id="SCR_ID_KJX_SHOW_STRING"/>
		<SCREEN id="SCR_ID_KJX_SCREEN_TEST"/>
	#if defined(__KJX_TOURIST_MAP_SUPPORT__)
		<SCREEN id="SCR_ID_KJX_IMAGE"/>
	#endif
	#endif	
	<!--Screen Group Id-->


	<!--End Screen Resource Area-->
	<!----------------------------------------------------End Screen Resource Area--------------------------------------------------->



	<!----------------------------------------------------------Menu Item Area------------------------------------------------------->
	<!--Menu Item Area-->


	<!--End Menu Item Area-->
	<!---------------------------------------------------------End Menu Item Area---------------------------------------------------->
	

	<!----------------------------------------------------Event proc Area-------------------------------------------------->
	<!--Event proc Area-->


    <!--End Event proc Area-->
    <!--------------------------------------------------End Event proc Area------------------------------------------------>
</APP>

