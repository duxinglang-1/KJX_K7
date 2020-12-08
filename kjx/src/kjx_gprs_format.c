/**********************************************************************************
*Filename:     kjx_net_format.c
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2014/01/07
*
***********************************************************************************/
#if defined(__KJX_FUN__)

/****************************************************************************
* Include Files 						包含头文件
*****************************************************************************/
#include "kjx_include.h"
#include "kjx_main.h"
#include "SSCStringTable.h"
#include "FontRes.h"
#include "FontDcl.h"
#include "mmi_rp_srv_general_setting_def.h"
#include "mmi_frm_nvram_gprot.h"
#include "ImeiSrvGprot.h"
#include "SmsSrvGprot.h"

/*****************************************************************************
 *	Define					宏定义
 *****************************************************************************/
#define KJX_IMEI_UP_LEN	  15
#ifdef __KJX_FENCE_SUPPORT__
#define FENCE_FUNC_SUPPORT	0x00000001
#endif
#ifdef __KJX_POSITION_TRIGGER_PLAY__
#define POSITION_TRIGGER_FUNC_SUPPORT	0x00000002
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
static BOOL kjx_first_gps = TRUE;
static U8 subString[15][128] = {0};
#if defined(__KJX_RESET_USED_COUNT__)
static BOOL ruc_send_confirm = FALSE;
#endif

/****************************************************************************
* Global Variable - Extern			全局变量
*****************************************************************************/
#if !defined(KJX_FORMAT_ACSSII)
kjx_pack_struct g_kjx_pack_struct;

U8 crcPack[1024*4];
U8 useData[512*4];
U8 unpack_data[1024*4];
kal_uint16 hex_buff[KJX_SOCKET_BUFF_SIZE];
U16 useDataLen = 0;
U8 packHex[512*2];
#endif

S8 pack[512*2];
S8 newPsw[10];/*新密码*/
S8 kjxAddress[512];
S8 kjxTourShow[512];
S8 kjxTourInfor[512];
S8 kjxPlayTts[512];

double old_latitude = 0;
double old_longitude = 0;
BOOL socketConnet = FALSE;
BOOL dataIsSync = FALSE;
int SENSOR_MAX_DATA = 0;
BOOL kjx_is_listen = FALSE;
U8 kjx_listen_callmode = 0;
U16 sensor_status = 0;

#ifdef __KJX_WEATHER_SUPPORT__
kjx_weather_struct kjx_weather = {0};
#endif
#ifdef __KJX_FENCE_SUPPORT__
kjx_fence_struct kjx_fence = {0};
#endif
kjx_gprs_data g_kjx_gprs_data;
nvram_ef_kjx_nvram_struct g_kjx_nvram_struct;

kjx_subTotal g_kjx_subTotal[SERVER_TYPE_MAX]=
{
	//SERVER_TYPE_01,心跳包
	{1,0},
	//SERVER_TYPE_02,域名更改
	{1,2},
	//SERVER_TYPE_03,GPS定位数据
	{1,0},
	//SERVER_TYPE_04,号码绑定
	{1,3},
	//SERVER_TYPE_05,监听号码
	{1,1},
	//SERVER_TYPE_06,电子围栏
	{0,2},
	//SERVER_TYPE_07,报警推送
	{0,1},
	//SERVER_TYPE_08,上传间隔
	{1,1},
	//SERVER_TYPE_09,密码修改
	{1,2},
	//SERVER_TYPE_10,APN设置
	{1,3},
	//SERVER_TYPE_11,语言设置
	{1,2},
	//SERVER_TYPE_12,语音设置
	{1,1},
	//SERVER_TYPE_13,语音推送
	{1,1},
	//SERVER_TYPE_14,震动报警
	{1,1},
	//SERVER_TYPE_15,灵敏度
	{1,1},
	//SERVER_TYPE_16,超速报警
	{1,1},
	//SERVER_TYPE_17,断油断电
	{1,1},
	//SERVER_TYPE_18,车型设置
	{1,2},
	//SERVER_TYPE_19,OBD数据
	{1,0},
	//SERVER_TYPE_20,非法开门
	{1,1},
	//SERVER_TYPE_21,非法启动
	{1,1},
	//SERVER_TYPE_22,电子狗
	{1,1},
	//SERVER_TYPE_23,云狗更新
	{1,1},
	//SERVER_TYPE_24,雷达开关
	{1,1},
	//SERVER_TYPE_25,工作模式
	{1,1},
	//SERVER_TYPE_26,通话模式
	{1,1},
	//SERVER_TYPE_27,超速报警预警
	{1,0},
	//SERVER_TYPE_28,非法启动预警
	{1,0},
	//SERVER_TYPE_29,非法开门预警
	{1,0},
	//SERVER_TYPE_30,同步
	{0,0},
	//SERVER_TYPE_31,获取地址数据
	{1,1},
	//SERVER_TYPE_32,闹钟
	{1,3},
	//SERVER_TYPE_33,心率开关
	{1,1},
	//SERVER_TYPE_34,心率数据
	{1,0},
	//SERVER_TYPE_35,计步开关
	{1,1},
	//SERVER_TYPE_36,计步数据
	{1,0},
	//SERVER_TYPE_37,正版验证
	{2,0},
	//SERVER_TYPE_38,来电铃声
	{1,1},
	//SERVER_TYPE_39,音量等级
	{1,1},
	//SERVER_TYPE_40,恢复出厂设置
	{1,1},
	//SERVER_TYPE_41,蓝牙开关
	{1,1},
	//SERVER_TYPE_42,蓝牙防丢报警
	{0,1},
	//SERVER_TYPE_43,防脱落报警
	{0,1},
	//SERVER_TYPE_44,手动定位
	{1,1},
	//SERVER_TYPE_45,防脱落开关
	{1,1},
	//SERVER_TYPE_46,查询参数
	{1,1},
	//SERVER_TYPE_47,号码昵称
	{1,3},	
	//SERVER_TYPE_48,远程关机
	{1,1},	
	//SERVER_TYPE_49,计步时间段
	{1,2},
	//SERVER_TYPE_50,上课时间段
	{1,2},
	//SERVER_TYPE_51,低电量报警
	{1,1},
	//SERVER_TYPE_52,表情灯闪烁
	{1,1},
	//SERVER_TYPE_53,设备号码
	{1,1},
	//SERVER_TYPE_54,小红花
	{1,1},
	//SERVER_TYPE_55,白名单
	{1,10},
	//SERVER_TYPE_56,语音对讲
	{1,1},
	//SERVER_TYPE_57,日期时间同步
	{2,2},
	//SERVER_TYPE_58,上课时间段开关
	{1,1},
	//SERVER_TYPE_59,白名单号码昵称
	{1,10},
	//SERVER_TYPE_60,短信显示
	{1,1},
	//SERVER_TYPE_61,RFID播报失效时间
	{1,4},
	//SERVER_TYPE_62,短信推送
	{1,1},
	//SERVER_TYPE_63,定位持续时间
	{1,1},
	//SERVER_TYPE_64,时钟显示模式
	{1,1},
	//SERVER_TYPE_65,心率上传间隔
	{1,1},
	//SERVER_TYPE_66,RFID播报结束时间
	{1,4},
	//SERVER_TYPE_67,SOS拨打方式
	{1,1},
    //SERVER_TYPE_68,上课时间段
    {1,10},
    //SERVER_TYPE_69,找设备
    {1,1},
    //SERVER_TYPE_70,RFID统计上行
	{2,2},
	//SERVER_TYPE_71,位置版定位数据
	{1,1},
	//SERVER_TYPE_72,位置播报统计上行
	{2,0},
	//SERVER_TYPE_73,指令播报
	{1,1},
	//SERVER_TYPE_74,复位计次统计上行
	{1,1},
	//SERVER_TYPE_75,设备语言同步上行
	{1,1},	
	//SERVER_TYPE_76,设置设备RFID开关(下行)
	{1,1},
	//SERVER_TYPE_77,设置设备蓝牙iBeacon开关(下行)
	{1,1},	
	//SERVER_TYPE_78,设备关机通知后台(上行)
	{1,1},	
	//SERVER_TYPE_79,设备开机通知后台(上行)
	{1,1},
	//SERVER_TYPE_80,设备向后台请求天气数据(双向)
	{2,7},	
	//SERVER_TYPE_81,设备向后台获取城市数据(双向)
	{2,1},
	//SERVER_TYPE_82,后台向设备下发围栏报警提示(下行)
	{3,1},
	//SERVER_TYPE_83,设备向后台获取AGPS星历数据(双向)
	{1,1},
	//SERVER_TYPE_84,基站定位数据
	{1,0},	
	//SERVER_TYPE_85,设备向后台获取华大AGPS星历数据(双向)
	{1,1},
};

/****************************************************************************
* Global Variable - Extern			引用全局变量
*****************************************************************************/
extern U16 sms_send_count;
extern U8 battery_percentage;
extern kjx_socket_context g_kjx_socket_context;
extern U8 kjxImei[SRV_MAX_IMSI_LEN];
extern kjxNetInfo g_kjxNetInfo;
extern BOOL g_rfid_low_bat;
#if defined(__KJX_RESET_USED_COUNT__)
extern BOOL g_rfid_has_playing;
#endif

extern U32 kjx_rfid_id;
extern U32 g_ReconnetCount;

#ifdef __KJX_FUN_GPS__
extern kjx_gps_data g_kjx_gps_data;
extern kjx_gps_func g_kjx_gps_func;
extern kjx_gps_info_string gps_info_string;
extern kjx_pos_gps_info_string g_kjx_gps_info_string;
#endif

extern kjx_socket_context g_kjx_socket_context;
extern kjx_socket_notify_func g_socket_notify_func;
extern kjx_socket_event_func g_kjx_socket_event_func;
extern kjx_main_func g_kjx_main_func;

/*****************************************************************************
*	Global Functions	- Extern		引用外部函数
*****************************************************************************/
extern void kjx_get_image_name_from_url(U8 *picname, U8 *picurl);
#ifdef __KJX_FENCE_SUPPORT__
extern void kjx_receive_fence_alarm_proc(void);
#endif

/*****************************************************************************
*	Local Functions 		本地函数
*****************************************************************************/

/*http://www.lammertbies.nl/comm/info/crc-calculation.html?crc=2424001113612345678fff5000&method=ascii*/
/*CRC-CCITT (Kermit)*/
int ComputeCRC(U8 * val, size_t len)
{
    long crc;
    long q;
    byte c;
    int i = 0;
	
    crc = 0;
    for (i = 0; i < len; i++)
    {
        c = val[i];
        q = (crc ^ c) & 0x0f;
        crc = (crc >> 4) ^ (q * 0x1081);
        q = (crc ^ (c >> 4)) & 0xf;
        crc = (crc >> 4) ^ (q * 0x1081);
    }
    return (byte)crc << 8 | (byte)(crc >> 8);
}

int atox(char *str)        
{
    int num = 0;   
    int neg = 0;     

    while (*str == '-') 
    {
        str++;
        neg = !neg;
    } 
 
    while (*str != '\0') 
    {
        if ( (*str < '0') && (*str > 'f') && ((*str >= 'a') && (*str <= '9')))                     
        {
            break;
        } 
                 
        if(*str <= '9')
        {
            num = (16 * num) + (*str - '0');
        }
        else if((*str >= 'A')&&(*str <= 'Z'))
        {
            num = (16 * num) + (*str - 55);
        }
        else
        {
            num = (16 * num) + (*str - 87);
        }
        str++;
    } 
 
    return (neg ? -num : num);
} 

kal_uint8* asci_to_16hex(kal_uint8* str) 
{
    kal_uint8 *p= str;
    char hex_p[1024];
    char tem_buf[6];

    memset(hex_p, 0x00, sizeof(hex_p));

    while(*p!=0)
    {
        memset(tem_buf, 0x00, sizeof(tem_buf));

        sprintf(tem_buf,"%x",*p++);
        strcat ((char*)hex_p, (const char*)tem_buf);
    }

    return (kal_uint8*)&hex_p;
} 

/***********************************************************************************/
void kjx_nvram_init(void)
{
	int i = 0;

#ifdef GPRS_FORMAT_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	kjx_nvram_read();
	
	if(!g_kjx_nvram_struct.nvram_init)
	{
		g_kjx_nvram_struct.nvram_init = 1;
		g_kjx_nvram_struct.dataIsSync = TRUE;
 
		/*域名、端口*/
		memcpy(g_kjx_nvram_struct.domain.domain, KJX_DOMAIN, strlen(KJX_DOMAIN));
		g_kjx_nvram_struct.domain.port = KJX_PORT;

	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("domain:%s, port:%d", g_kjx_nvram_struct.domain.domain, g_kjx_nvram_struct.domain.port);
	#endif
	#endif

		g_kjx_nvram_struct.alarmType = 3;/* 0:短信；1:APP；2:电话；3:短信及APP*/
		g_kjx_nvram_struct.sendTime = GPS_DATA_TIME;/* 秒*/

		/*休眠状态*/
		g_kjx_nvram_struct.sleepStatus = 1;
 		
		/*密码*/
		memcpy(g_kjx_nvram_struct.password, "123456\0", strlen("123456\0"));
		
		/*APN*/
		memcpy(g_kjx_nvram_struct.apn.apnMode, "cmnet", strlen("cmnet"));
		memcpy(g_kjx_nvram_struct.apn.userName, "", strlen(""));
		memcpy(g_kjx_nvram_struct.apn.passWord, "", strlen(""));

		/* 语言:中文*/
		g_kjx_nvram_struct.language = 0;
		
		/* 时区:东八区(中国)*/
		g_kjx_nvram_struct.timezome = 8;
		
		/* 喇叭*/
		g_kjx_nvram_struct.speech = 1;

		/*震动报警:关闭*/
		g_kjx_nvram_struct.sensorAlarm = 0;
		/*灵敏度*/
		#ifdef __KJX_FACTORY_TEST__
		g_kjx_nvram_struct.sensorValue = 1;
		#else
		g_kjx_nvram_struct.sensorValue = 30;
		#endif
		/*限速报警:关闭*/
		g_kjx_nvram_struct.speedValue = 0;
		/*断油断电:恢复油电*/
		g_kjx_nvram_struct.shutDown = 1;

    #if defined(__KJX_OBD__)	
		/*车系设置:默认*/
		g_kjx_nvram_struct.carInfo.carType = 0;
		g_kjx_nvram_struct.carInfo.KmValue = 0;
		g_kjx_nvram_struct.openAlarm = 0;
		g_kjx_nvram_struct.runAlarm = 0;
    #endif

    #if defined(__KJX_DOG__)	
		g_kjx_nvram_struct.dogPlay = 1;
    #endif

    #if defined(__KJX_RADAR__)	
		g_kjx_nvram_struct.radar = 1;
    #endif

	#if defined(__KJX_RFID__)
		g_kjx_nvram_struct.rfidflag = 1;
	#endif
	
	#if defined(__BLE_MODULE_SUPPORT__)
		g_kjx_nvram_struct.btflag = 0;
	#endif
	
		g_kjx_nvram_struct.workMode = 0;
		g_kjx_nvram_struct.callMode = 0;
		g_kjx_nvram_struct.toneId = 0;//1;
		g_kjx_nvram_struct.btStatus = 0;
	#if defined(CUSTOMER_NAME_S2) && defined( __US5182D__ )
		g_kjx_nvram_struct.antiLostStatus = us5182_get_power_mode();
	#else
		g_kjx_nvram_struct.antiLostStatus = 0;
	#endif

		for(i=0;i<SOS_NUM_MAX;i++)
		{
			memset(g_kjx_nvram_struct.sosName[i], 0x00, sizeof(g_kjx_nvram_struct.sosName[i]));
		}
		
		g_kjx_nvram_struct.remoteShutDown = 0;
		
		for(i=0;i<STEP_NUM_MAX;i++)
		{
			memset(g_kjx_nvram_struct.stepTime[i], 0x00, sizeof(g_kjx_nvram_struct.stepTime[i]));
		}

	#if defined(CUSTOMER_NAME_MEGE2)
		memcpy(g_kjx_nvram_struct.smsInfo.smsChannel,KJX_SMS_CHANNEL,strlen(KJX_SMS_CHANNEL));
		memcpy(g_kjx_nvram_struct.smsInfo.smsHead,"&#",strlen("&#"));
		memcpy(g_kjx_nvram_struct.smsInfo.smsEnd,"#",strlen("#"));
	#endif
	
		g_kjx_nvram_struct.studyMode = 0; //  专心学习开关

	#if defined(__KJX_RFID__)
		memset(&g_kjx_nvram_struct.rfidOverTime, 0x00, sizeof(over_time_struct));
	#endif

		g_kjx_nvram_struct.sosCallMode = 0;/*1: 循环拨打 0:不循环拨打*/

		for(i=0;i<10;i++)
		{
			memset((void*)&g_kjx_nvram_struct.tClassTime[i], 0x00, sizeof(class_time_struct));
		}

	#if defined(__KJX_RESET_USED_COUNT__)
		g_kjx_nvram_struct.useflag = 0;
		g_kjx_nvram_struct.usecount = 0;
	#endif

	#if defined(__KJX_DJ_SUPPORT__)
		g_kjx_nvram_struct.dj_infor.dj_mode = 0;
		g_kjx_nvram_struct.dj_infor.dj_chanle = 0;
		g_kjx_nvram_struct.dj_infor.dj_vol = 0;
	#endif
	
		kjx_nvram_write();
	}
#ifdef GPRS_FORMAT_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("sendTime:%d", g_kjx_nvram_struct.sendTime);
#endif
#endif

	for(i=0;i<SERVER_TYPE_MAX;i++)	//xb add 2017-08-01 防止关机前没处理完的指令开机后立刻上报，影响后台判断
	{
		g_kjx_nvram_struct.updateStatus[i] = 0;
	}
	
	SENSOR_MAX_DATA = 30;//g_kjx_nvram_struct.sensorValue;
	/*网络参数配置*/
	kjx_set_domain_infos();
	kjx_set_apn_infos();
}

BOOL kjx_gprs_is_connect(void)
{
	return socketConnet;
}

BOOL kjx_gprs_is_connect_check(void)
{
#if defined(__KJX_FUN_AGPS__)
	extern U8 g_kjx_agps_used;
	if(g_kjx_agps_used)
		return TRUE;
	else
		return FALSE;
#endif

	return FALSE;
}


U16 mmi_get_gps_status(void)
{
#if defined(__KJX_FUN_GPS__)
	if(g_kjx_gps_data.data_status == 'A')
		return 1;
	else
		return 0;
#else
	return 0;
#endif
}

U16 kjx_sensor_is_sleep(void)
{
#if 1	//xb add 2017-02-17 不再根据sensor休眠状态来区分程序流程
	return 0;
#else
	return sensor_status;
#endif
}

U8 kjx_get_workmode(void)
{
	return g_kjx_nvram_struct.workMode;
}

U8 kjx_get_tone_id(void)
{
	return g_kjx_nvram_struct.toneId;
}

BOOL kjx_get_antiLostStatus(void)
{
	return g_kjx_nvram_struct.antiLostStatus;
}


void kjx_steps_onoff(U16 flag)
{
	
}

void kjx_steps_teller_send_data(void)
{
	g_kjx_nvram_struct.updateStatus[SERVER_TYPE_36] = 1;
	kjx_socket_send_data_all();
	StartTimer(KJX_TIMER_ID_STEPS_START1, 1800*1000, kjx_steps_teller_send_data);
}


#if defined( __LIGHT_DROP_DETECT__ )//光感
extern void kjx_report_to_custmer_with_type(kjx_sms_send_type sms_type,kjx_socket_type socket_type);
void kjx_fun_light_anti_lost(void)
{
	kjx_report_to_custmer_with_type(SMS_LIGHT_FALL_OFF,SERVER_TYPE_43);
}

#endif  // __LIGHT_DROP_DETECT__


#if !defined(KJX_FORMAT_ACSSII)
void kjx_gprs_set_pack_struct(void)
{
   int i = 0;
   char imeiPart[6];
   
   memset(&g_kjx_pack_struct, 0x00, sizeof(kjx_pack_struct));
   
   g_kjx_pack_struct.header = 0x2424;
   g_kjx_pack_struct.packLen = sizeof(kjx_pack_struct)-1; 
#if defined(__MTK_TARGET__)
   for(i=0;i<4;i++)
   {
       memset(imeiPart, 0x00, sizeof(imeiPart));
       if(i<3)
       {
			memcpy(imeiPart,IMEIBuffer+(4*i), 4);
       }
       else
       {
			memcpy(imeiPart,IMEIBuffer+(4*i), 2);
		strncat ((char*)imeiPart,"00", 2);
       }
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("imeiPart[%d]:%s", i, imeiPart);
	#endif
	#endif
       g_kjx_pack_struct.imei[i]=atox((char *)imeiPart);
   }
#else
   g_kjx_pack_struct.imei[0]=0x8888;
   g_kjx_pack_struct.imei[1]=0x8888;
   g_kjx_pack_struct.imei[2]=0x8888;
   g_kjx_pack_struct.imei[3]=0x8800;
#endif

   g_kjx_pack_struct.project[0]=0x0057;
   g_kjx_pack_struct.project[1]=0x3830;

   g_kjx_pack_struct.version = KJX_VERSION; 

   g_kjx_pack_struct.checksum = 0xFFFF; 
   g_kjx_pack_struct.ender = 0x0D0A; 
}


S32 kjx_gprs_set_send_buffer(void)
{
    U8 tem_buf[16];
    U8 tem_buf1[16];
    U8 acsii_buf[16];
    int i=0,buffLen=0,num=0,unPackLen=0;
    kal_uint16 tem_data=0xffff;

    unPackLen = strlen(unpack_data);

    if(unPackLen==0)
    {
       return  0;
    }
	
    buffLen = unPackLen/2;
    memset(hex_buff, 0x00, sizeof(hex_buff));
    memset(g_kjx_socket_context.pSendBuff, 0x00, sizeof(g_kjx_socket_context.pSendBuff));

    if(unPackLen%4)
    {
       buffLen = buffLen/2 + 1;
    }
    else
    {
       buffLen = buffLen/2;
    }
	
    for(i=0;i<buffLen;i++)
    {
         memset(tem_buf, 0x00, sizeof(tem_buf));
         memcpy(tem_buf,unpack_data+i*4, 4);

         hex_buff[i]=atox(tem_buf);
    }
    memcpy(g_kjx_socket_context.pSendBuff,hex_buff, unPackLen);

   for(i=0;i<buffLen*2;)
   {/*高低位调换*/
      tem_data=g_kjx_socket_context.pSendBuff[i+1];
      g_kjx_socket_context.pSendBuff[i+1]=g_kjx_socket_context.pSendBuff[i];
      g_kjx_socket_context.pSendBuff[i]=tem_data;
      i += 2;
   }
   
   if((unPackLen/2)% 2)
   {
      g_kjx_socket_context.pSendBuff[unPackLen/2-1] = g_kjx_socket_context.pSendBuff[unPackLen/2];
      g_kjx_socket_context.pSendBuff[unPackLen/2] = '\0';
   }
   else
   {
      g_kjx_socket_context.pSendBuff[unPackLen/2] = '\0';
   }
#ifdef GPRS_FORMAT_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("pSendBuff(%d):%s", unPackLen/2, g_kjx_socket_context.pSendBuff);
#endif
#endif
   
   return unPackLen/2;
}

U16 kjx_gprs_get_user_data(void)
{
	U16 result = 1;
	kal_uint8	tatol=0;
	S8 tempack[512*2];
	S8 temsprintf[128];
	int i=0;

#ifdef GPRS_FORMAT_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
	memset(pack, 0x00,sizeof(pack));
	memset(packHex, 0x00,sizeof(packHex));

	strcat(pack,"{");

	/*心跳包*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_01]==1)
	{
		tatol++;
		strcat(pack,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"%02d|%02d\0",SERVER_TYPE_01+1,g_kjx_nvram_struct.sleepStatus);
		strcat(pack,temsprintf);
		strcat(pack,">");
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("SERVER_TYPE_01:%s", pack);
	#endif
    #endif
	}

	/*域名更改*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_02]==1)
	{
		tatol++;
		strcat(pack,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"%02d|%s,%d\0",SERVER_TYPE_02+1,g_kjx_nvram_struct.domain.domain,g_kjx_nvram_struct.domain.port);
		strcat(pack,temsprintf);
		strcat(pack,">");
	}
	
	/*定位数据*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_03]==1)
	{
		U8 Altitude =100;
		U8 HDOP =10;
		U8 batteryStatus;
		U8 gsm_status;
		double distance = 0,runDistance = 0;
		kjx_gps_data *gps_info=&g_kjx_gps_data;
		kjx_lbs_info_struct *lbs_info = &g_kjx_lbs_info_struct;
	
		tatol++;
		strcat(pack,"<");
		
		batteryStatus = battery_percentage;
		gsm_status = kjx_sys_get_cur_gsm_status();

		memset(tempack, 0x00,sizeof(tempack));
		if(gps_info->data_status == 'A')
		{
			sprintf(tempack,"%02d%02d%02d.000,%c,%s,%c,%s,%c,%.3f,%.2f,%02d%02d%02d,,|%d|%d|%d,%d,%s,%s|%03d|%03d\0",
			gps_info->time.nHour,gps_info->time.nMin,gps_info->time.nSec,gps_info->data_status,
			gps_info->latitude_gps,gps_info->latitude_dir,
			gps_info->longitude_gps,gps_info->longitude_dir,
			gps_info->speed_kh,gps_info->angle,gps_info->date.nDay,gps_info->date.nMonth,gps_info->date.nYear,
			HDOP,Altitude,lbs_info->cid,lbs_info->lac,lbs_info->mnc,lbs_info->mcc,batteryStatus,gsm_status);
        #ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("pack:%s", tempack);
        #endif
		#endif

			if((old_latitude != 0)&&(old_longitude!=0))
			{/*漂移处理*/
				distance = kjx_get_distance(old_latitude,old_longitude,gps_info->latitude,gps_info->longitude);
			#ifdef GPRS_FORMAT_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("distance:%0.3f", distance);
			#endif
			#endif

				runDistance = ((200*1000)/3600) * g_kjx_nvram_struct.sendTime;/*200km,计算结果为M*/
			#ifdef GPRS_FORMAT_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("distance:%0.3f, runDistance:%0.3f", distance, runDistance);
			#endif
			#endif

				old_latitude = gps_info->latitude;
				old_longitude = gps_info->longitude;

				if(distance>runDistance)
				{
				#ifdef GPRS_FORMAT_DEBUG
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("return 0;");
				#endif
				#endif
					return;
				}

			}
			else
			{
				old_latitude = gps_info->latitude;
				old_longitude = gps_info->longitude;
			}

		}
		else
		{
			sprintf(tempack,"|%d|%d|%d,%d,%s,%s|%03d|%03d\0",
			HDOP,Altitude,lbs_info->cid,lbs_info->lac,lbs_info->mnc,lbs_info->mcc,batteryStatus,gsm_status);
		}
		
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"%02d|\0",SERVER_TYPE_03+1);
		strcat(pack,temsprintf);
		
		strcat(pack,tempack);
		strcat(pack,">");
	}
	
	/*号码绑定*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_04]==1)
	{
		tatol++;
		strcat(pack,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"%02d|%s,%s,%s\0",SERVER_TYPE_04+1,g_kjx_nvram_struct.sosNum[0],g_kjx_nvram_struct.sosNum[1],g_kjx_nvram_struct.sosNum[2]);
		strcat(pack,temsprintf);
		strcat(pack,">");
	}

	/*监听号码*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_05]==1)
	{
		tatol++;
		strcat(pack,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"%02d|%s\0",SERVER_TYPE_05+1,g_kjx_nvram_struct.listenNum);
		strcat(pack,temsprintf);
		strcat(pack,">");
	}

	/*上传间隔*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_08]==1)
	{
		tatol++;
		strcat(pack,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"%02d|%02x\0",SERVER_TYPE_08+1,g_kjx_nvram_struct.sendTime);
		strcat(pack,temsprintf);
		strcat(pack,">");
	}

	/*密码修改*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_09]==1)
	{
		tatol++;
		strcat(pack,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"%02d|%s,%s\0",SERVER_TYPE_09+1,g_kjx_nvram_struct.password,newPsw);
		strcat(pack,temsprintf);
		strcat(pack,">");
	}

	/*APN设置*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_10]==1)
	{
		tatol++;
		strcat(pack,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"%02d|%s,%s,%s\0",SERVER_TYPE_09+1,g_kjx_nvram_struct.apn.apnMode,g_kjx_nvram_struct.apn.userName,g_kjx_nvram_struct.apn.passWord);
		strcat(pack,temsprintf);
		strcat(pack,">");
	}

	/*语言设置*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_11]==1)
	{
		tatol++;
		strcat(pack,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"%02d|%02d,%d\0",SERVER_TYPE_11+1,g_kjx_nvram_struct.language,g_kjx_nvram_struct.timezome);
		strcat(pack,temsprintf);
		strcat(pack,">");
	}

	/*语音设置*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_12]==1)
	{
		tatol++;
		strcat(pack,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"%02d|%02d\0",SERVER_TYPE_12+1,g_kjx_nvram_struct.speech);
		strcat(pack,temsprintf);
		strcat(pack,">");
	}

	/*震动报警*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_14]==1)
	{
		tatol++;
		strcat(pack,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"%02d|%02d\0",SERVER_TYPE_14+1,g_kjx_nvram_struct.sensorAlarm);
		strcat(pack,temsprintf);
		strcat(pack,">");
	}

	/*灵敏度*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_15]==1)
	{
		tatol++;
		strcat(pack,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"%02d|%02x\0",SERVER_TYPE_15+1,g_kjx_nvram_struct.sensorValue);
		strcat(pack,temsprintf);
		strcat(pack,">");
	}

	/*超速报警*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_16]==1)
	{
		tatol++;
		strcat(pack,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"%02d|%02x\0",SERVER_TYPE_16+1,g_kjx_nvram_struct.speedValue);
		strcat(pack,temsprintf);
		strcat(pack,">");
	}
	
#if defined(__KJX_OBD__)	
	/*非法开门*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_20]==1)
	{
		tatol++;
		strcat(pack,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"%02d|%02x\0",SERVER_TYPE_20+1,g_kjx_nvram_struct.openAlarm);
		strcat(pack,temsprintf);
		strcat(pack,">");
	}

	/*非法启动*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_21]==1)
	{
		tatol++;
		strcat(pack,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"%02d|%02x\0",SERVER_TYPE_21+1,g_kjx_nvram_struct.runAlarm);
		strcat(pack,temsprintf);
		strcat(pack,">");
	}
#endif

#if defined(__KJX_DOG__)
	/*电子狗*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_22]==1)
	{
		tatol++;
		strcat(pack,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"%02d|%02x\0",SERVER_TYPE_22+1,g_kjx_nvram_struct.dogPlay);
		strcat(pack,temsprintf);
		strcat(pack,">");
	}
#endif

#if defined(__KJX_RADAR__)
	/*雷达开关*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_24]==1)
	{
		tatol++;
		strcat(pack,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"%02d|%02x\0",SERVER_TYPE_24+1,g_kjx_nvram_struct.radar);
		strcat(pack,temsprintf);
		strcat(pack,">");
	}
#endif

#ifdef GPRS_FORMAT_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("pack:%s", pack);
#endif
#endif

	strcat ((char*)packHex, (const char*)asci_to_16hex(pack));

	useDataLen = (strlen(packHex)/2);

	for(i=0;i<useDataLen;i++)
	{
		memset(temsprintf, 0, sizeof(temsprintf));
		memcpy(temsprintf,packHex+i*2,2);
		useData[i]=atox(temsprintf);
	}

#if defined(__KJX_OBD__)
	/*OBD数据*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_19]==1)
	{
		tatol++;
		mmi_ucs2cat(useData,atox("<19|"));
		mmi_ucs2cat(useData,ObdUartBuffer);
		mmi_ucs2cat(useData,atox(">"));

		useDataLen += (obd_len+5);
	}
#endif
 
	useData[useDataLen]=atox((char*)asci_to_16hex("}"));
	useDataLen += 1;

	g_kjx_pack_struct.total = tatol;
	g_kjx_pack_struct.packLen += useDataLen;
	
	if(useDataLen<=2)
	{
		result = 0;
	}
	
	return result;
}

U16 kjx_gprs_get_unpack_data(void)
{
    int i = 0;
    U8  crc_data[19];
    U8  temData[6];
	
    memset(unpack_data, 0x00, sizeof(unpack_data));

     for(i=0;i<(sizeof(crc_data)-1)+useDataLen;i++)
     {
	     memset(temData, 0, sizeof(temData));
	     sprintf(temData,"%02x",crcPack[i]);
	     
	     strcat ((char*)unpack_data, (const char*)temData);
     }
#ifdef GPRS_FORMAT_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("unpack_data(%d):%s", strlen(unpack_data), unpack_data);
#endif
#endif
    return strlen(unpack_data);
}


U16 kjx_gprs_set_pack_data(void)
{
    int i = 0;
    U16 result = 0;
    kal_uint16 tem_data=0xffff;
    U16 crcCheckSum;
    U8  crc_data[19];
    U8  temData[6];

    kjx_gprs_set_pack_struct();
    if(!kjx_gprs_get_user_data())
    {
        return 0;
    }
	
    memset(crc_data, 0, sizeof(crc_data));
    memcpy(crc_data,&g_kjx_pack_struct, sizeof(kjx_pack_struct)-sizeof(g_kjx_pack_struct.checksum)-sizeof(g_kjx_pack_struct.ender));
    
    for(i=0;i<sizeof(kjx_pack_struct)-sizeof(g_kjx_pack_struct.total)-sizeof(g_kjx_pack_struct.checksum)-sizeof(g_kjx_pack_struct.ender)-1;)
    {/*高低位调换*/
	    tem_data=crc_data[i+1];
	    crc_data[i+1]=crc_data[i];
	    crc_data[i]=tem_data;
	    i += 2;
    }
   
    for(i=sizeof(g_kjx_pack_struct.header)+sizeof(g_kjx_pack_struct.packLen)+sizeof(g_kjx_pack_struct.imei);i<(sizeof(kjx_pack_struct)-sizeof(g_kjx_pack_struct.checksum)-sizeof(g_kjx_pack_struct.ender));i++)
    {//去掉多余的1位字节
	    crc_data[i-1]=crc_data[i];
    }

    memset(crcPack, 0, sizeof(crcPack));
    memcpy((char*)crcPack,(const char*)crc_data,sizeof(crc_data)-1);
    memcpy((char*)crcPack+(sizeof(crc_data)-1),(const char*)useData,useDataLen);
    crcCheckSum=ComputeCRC((U8 *)&crcPack, (sizeof(crc_data)-1)+useDataLen);// Chcek sum: 2Bytes 

    if(!kjx_gprs_get_unpack_data())
    {
        return 0;
    }
	
    memset(temData, 0, sizeof(temData));
    sprintf(temData,"%04x",crcCheckSum);
    
    /*checksum高低位调换*/
    strncat ((char*)unpack_data, (const char*)temData+2,2);
    strncat ((char*)unpack_data, (const char*)temData,2);
    
    memset(temData, 0, sizeof(temData));
    sprintf(temData,"%04x",g_kjx_pack_struct.ender);
    strncat ((char*)unpack_data, (const char*)temData,sizeof(g_kjx_pack_struct.ender)*2);
    
    unpack_data[strlen(unpack_data)]='\0';
#ifdef GPRS_FORMAT_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("unpack_data(%d):%s", strlen(unpack_data), unpack_data);
#endif
#endif

    return strlen(unpack_data);	
}

U16 kjx_gprs_set_send_data(void)
{
    U16 result = 0;
	
    if(kjx_gprs_set_pack_data())
    {
        result = kjx_gprs_set_send_buffer();
    }
#ifdef GPRS_FORMAT_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("result:%d", result);
#endif
#endif

    return result;
}
#else/*KJX_FORMAT_ACSSII*/
U16 kjx_gprs_set_pack_data(void)
{
	U16 result = 1,headLen=0;
	kal_uint8 tatol=0;
	S8 tempack[512*2];
	S8 temsprintf[128];
	int i=0;

#ifdef GPRS_FORMAT_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	headLen = strlen((char*)g_kjx_socket_context.pSendBuff);
	headLen += strlen("{");
	
	strcat(g_kjx_socket_context.pSendBuff,"{");

	/*心跳包*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_01]==1)
	{
		char strrfid[9] = {0};
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("心跳包sleepStatus:%d",  1-kjx_sensor_is_sleep());
	#endif	
	#endif
		
		tatol++;
		if((kjx_sensor_is_sleep()==1)/*||(g_kjx_nvram_struct.workMode==2)*/)
		{
			g_kjx_nvram_struct.sleepStatus = 0;
		}
		else
		{
			g_kjx_nvram_struct.sleepStatus = 1;
		}
		
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		kjx_rfid_get_rfid_str(strrfid, sizeof(strrfid));
		sprintf(temsprintf,"U%d#%d,%s,%d\0",SERVER_TYPE_01+1, g_kjx_nvram_struct.sleepStatus, strrfid, g_rfid_low_bat);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("SERVER_TYPE_01:%s", g_kjx_socket_context.pSendBuff);
	#endif	
	#endif
		g_rfid_low_bat = FALSE;//xb add 2016-09-18 防止离开发射源之后还在不停地报警
	}

	/*域名更改*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_02]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("域名更改domain:%s, port:%d",   g_kjx_nvram_struct.domain.domain, g_kjx_nvram_struct.domain.port);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_02])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_02+1);
		else
			sprintf(temsprintf,"U%d#%s,%d\0",SERVER_TYPE_02+1,g_kjx_nvram_struct.domain.domain,g_kjx_nvram_struct.domain.port);
		
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

#if defined(__KJX_FUN_GPS__)	
	/*GPS定位数据*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_03]==1)
	{
		U8 Altitude = 100;
		U8 HDOP = 10;
		S16 batteryStatus;
		U8 gsm_status;
		S16 sRSSI;
		double distance = 0, runDistance = 0;
	#if defined(__KJX_FUN_GPS__)
		kjx_gps_data *gps_info = &g_kjx_gps_data;
	#endif

	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("GPS定位数据");
	#endif	 
	#endif

		tatol++;
		strcat( g_kjx_socket_context.pSendBuff, "<" );
		batteryStatus = battery_percentage;
		gsm_status = kjx_sys_get_cur_gsm_status();

		memset(tempack, 0x00, sizeof(tempack));
		if(g_kjx_gps_func.gps_is_on() && (gps_info->data_status == 'A'))
		{
			sprintf(tempack,"%02d%02d%02d.000,%c,%s,%c,%s,%c,%.3f,%.2f,%02d%02d%02d,,|%d|%d|%03d|%03d\0",
			gps_info->date.nHour,gps_info->date.nMin,gps_info->date.nSec,gps_info->data_status,
			gps_info->latitude_gps,gps_info->latitude_dir,
			gps_info->longitude_gps,gps_info->longitude_dir,
			gps_info->speed_kh,gps_info->angle,gps_info->date.nDay,gps_info->date.nMonth,gps_info->date.nYear,
			HDOP,Altitude,batteryStatus,gsm_status);
		}
		
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"U%d#\0",SERVER_TYPE_03+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		
		strcat(g_kjx_socket_context.pSendBuff,tempack);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}
#endif

	/*号码绑定*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_04]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("号码绑定sosNum0:%s, sosNum1:%s, sosNum2:%s", g_kjx_nvram_struct.sosNum[0], g_kjx_nvram_struct.sosNum[1], g_kjx_nvram_struct.sosNum[2]);
	#endif
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_04])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_04+1);
		else
			sprintf(temsprintf,"U%d#%s,%s,%s\0",SERVER_TYPE_04+1,g_kjx_nvram_struct.sosNum[0],g_kjx_nvram_struct.sosNum[1],g_kjx_nvram_struct.sosNum[2]);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*监听号码*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_05]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("监听号码listenNum:%s",   g_kjx_nvram_struct.listenNum);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_05])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_05+1);
		else
			sprintf(temsprintf,"U%d#%s\0",SERVER_TYPE_05+1,g_kjx_nvram_struct.listenNum);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*电子围栏（下行）*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_06]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("电子围栏");
	#endif
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_06+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*报警推送（下行）*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_07]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("报警推送");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_07+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}


	/*上传间隔*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_08]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("上传间隔sendTime:%d",   g_kjx_nvram_struct.sendTime);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_08])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_08+1);
		else
			sprintf(temsprintf,"U%d#%d\0",SERVER_TYPE_08+1,g_kjx_nvram_struct.sendTime);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*密码修改*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_09]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("密码修改newPsw:%d",   newPsw);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_09])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_09+1);
		else
			sprintf(temsprintf,"U%d#%s,%s\0",SERVER_TYPE_09+1,g_kjx_nvram_struct.password,newPsw);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*APN设置*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_10]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("APN设置apnMode:%s, userName:%s, passWord:%s", g_kjx_nvram_struct.apn.apnMode, g_kjx_nvram_struct.apn.userName, g_kjx_nvram_struct.apn.passWord);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_10])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_10+1);
		else
			sprintf(temsprintf,"U%d#%s,%s,%s\0",SERVER_TYPE_10+1,g_kjx_nvram_struct.apn.apnMode,g_kjx_nvram_struct.apn.userName,g_kjx_nvram_struct.apn.passWord);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*语言设置*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_11]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("语言时区设置language:%d, timezome:%d",  g_kjx_nvram_struct.language, g_kjx_nvram_struct.timezome);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_11])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_11+1);
		else
			sprintf(temsprintf,"U%d#%d,%d\0",SERVER_TYPE_11+1,g_kjx_nvram_struct.language,g_kjx_nvram_struct.timezome);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*语音设置*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_12]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("语音设置speech:%d",  g_kjx_nvram_struct.speech);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_12])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_12+1);
		else
			sprintf(temsprintf,"U%d#%d\0",SERVER_TYPE_12+1,g_kjx_nvram_struct.speech);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*语音推送*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_13]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("语音推送");
	#endif	
	#endif
		
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_13+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*震动报警*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_14]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("震动报警sensorAlarm:%d",  g_kjx_nvram_struct.sensorAlarm);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_14])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_14+1);
		else
			sprintf(temsprintf,"U%d#%d\0",SERVER_TYPE_14+1,g_kjx_nvram_struct.sensorAlarm);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*灵敏度*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_15]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("灵敏度设置sensorValue:%d",  g_kjx_nvram_struct.sensorValue);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_15])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_15+1);
		else
			sprintf(temsprintf,"U%d#%d\0",SERVER_TYPE_15+1,g_kjx_nvram_struct.sensorValue);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*超速报警*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_16]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("超速报警speedValue:%d",  g_kjx_nvram_struct.speedValue);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_16])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_16+1);
		else
			sprintf(temsprintf,"U%d#%d\0",SERVER_TYPE_16+1,g_kjx_nvram_struct.speedValue);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*断油断电（下行）*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_17]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("断油断电");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_17+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}
	
#if defined(__KJX_OBD__)	
	/*车型设置（下行）*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_18]==1)
	{
		extern BOOL obd_get_car_info;

	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("车型设置");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(obd_get_car_info)/*获取车系*/
			sprintf(temsprintf,"U%d\0",SERVER_TYPE_18+1);
		else/*回复下行*/
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_18+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}
	
	/*OBD数据（上行）*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_19]==1)
	{
		extern kal_uint8 ObdUartBuffer[];

	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("OBD数据");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"U%d#\0",SERVER_TYPE_19+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,ObdUartBuffer);
		strcat(g_kjx_socket_context.pSendBuff,"\0");
		strcat(g_kjx_socket_context.pSendBuff,">");
	}
	
	/*非法开门*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_20]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("非法开门openAlarm:%d",  g_kjx_nvram_struct.openAlarm);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_20])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_20+1);
		else
			sprintf(temsprintf,"U%d#%d\0",SERVER_TYPE_20+1,g_kjx_nvram_struct.openAlarm);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*非法启动*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_21]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("非法启动runAlarm:%d",  g_kjx_nvram_struct.runAlarm);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_21])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_21+1);
		else
			sprintf(temsprintf,"U%d#%d\0",SERVER_TYPE_21+1,g_kjx_nvram_struct.runAlarm);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}
#endif

#if defined(__KJX_DOG__)
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_22]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("电子狗dogPlay:%d",  g_kjx_nvram_struct.dogPlay);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_22])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_22+1);
		else
			sprintf(temsprintf,"U%d#%d\0",SERVER_TYPE_22+1,g_kjx_nvram_struct.dogPlay);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_23]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("云狗更新");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_23])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_23+1);
		else
			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_23+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}	
#endif

#if defined(__KJX_RADAR__)
	/*雷达开关*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_24]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("雷达开关radar:%d",  g_kjx_nvram_struct.radar);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_24])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_24+1);
		else
			sprintf(temsprintf,"U%d#%d\0",SERVER_TYPE_24+1,g_kjx_nvram_struct.radar);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}
#endif

	/*工作模式*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_25]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("工作模式workMode:%d",   g_kjx_nvram_struct.workMode);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_25])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_25+1);
		else
			sprintf(temsprintf,"U%d#%d\0",SERVER_TYPE_25+1,g_kjx_nvram_struct.workMode);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*通话模式*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_26]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("通话模式callMode:%d",  g_kjx_nvram_struct.callMode);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_26])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_26+1);
		else
			sprintf(temsprintf,"U%d#%d\0",SERVER_TYPE_26+1,g_kjx_nvram_struct.callMode);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*超速报警预警（上行）*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_27]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("超速报警预警");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"U%d#1\0",SERVER_TYPE_27+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}
	
	/*非法启动预警（上行）*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_28]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("非法启动预警");
	#endif
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"U%d#1\0",SERVER_TYPE_28+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*非法开门预警（上行）*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_29]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("非法开门预警");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"U%d#1\0",SERVER_TYPE_29+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*数据同步*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_30]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("数据同步");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
	#ifdef __KJX_CUSTOMER_YDHD__
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_30])
		{
			//alm_nvram_struct *p;
			alm_nvram_struct *p = (srv_alm_node_type *)srv_alm_read(0);
			
			sprintf(temsprintf,"C%d#|%d:%s,%d|%d:%s,%s,%s|%d:%s|%d:%d|%d:%d|%d:%s|%d:%s,%s,%s|%d:%d,%f|%d:%d|%d:%d|%d:%d|%d:%d|%d:%d,%d:%d\0",
			SERVER_TYPE_30+1,
			SERVER_TYPE_02+1,// 域名端口
			g_kjx_nvram_struct.domain.domain,
			g_kjx_nvram_struct.domain.port,
			SERVER_TYPE_04+1, // SOS号码
			g_kjx_nvram_struct.sosNum[0],
			g_kjx_nvram_struct.sosNum[1],
			g_kjx_nvram_struct.sosNum[2],
			SERVER_TYPE_05+1, // 监听号码
			g_kjx_nvram_struct.listenNum,
			SERVER_TYPE_07+1, // 报警方式
			g_kjx_nvram_struct.alarmType,
			SERVER_TYPE_08+1, // GPS上传间隔
			g_kjx_nvram_struct.sendTime,
			SERVER_TYPE_09+1, // 密码修改
			g_kjx_nvram_struct.password,
			SERVER_TYPE_10+1, // APN设置
			g_kjx_nvram_struct.apn.apnMode,
			g_kjx_nvram_struct.apn.userName,
			g_kjx_nvram_struct.apn.passWord,
			SERVER_TYPE_11+1, //语言时区
			g_kjx_nvram_struct.language,
			g_kjx_nvram_struct.timezome,
			SERVER_TYPE_12+1, //语音设置
			g_kjx_nvram_struct.speech,
			SERVER_TYPE_15+1, // 灵敏度
			g_kjx_nvram_struct.sensorValue,
			SERVER_TYPE_25+1, // 工作模式
			g_kjx_nvram_struct.workMode,
			SERVER_TYPE_26+1,// 通话模式
			g_kjx_nvram_struct.callMode,
			SERVER_TYPE_32+1, // 闹钟
			p->State,
			p->Hour,
			p->Min
			);
		}
		else
	#endif
		sprintf(temsprintf,"U%d#\0",SERVER_TYPE_30+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*获取中文地址*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_31]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("获取中文地址");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_31])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_31+1);
		else
			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_31+1);	
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*闹钟*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_32]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("闹钟");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_32+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

#if defined(__KJX_HEART_SUPPORT__)
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_33]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("心率开关");
	#endif	
	#endif
		
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_33])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_33+1);
		else
			sprintf(temsprintf,"U%d#%d,%04d%02d%02d%02d%02d\0",SERVER_TYPE_33+1,heartTotal,currTime.nYear,currTime.nMonth,currTime.nDay,currTime.nHour,currTime.nMin);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_34]==1)
	{
		U16 heartTotal = 0;
		applib_time_struct currTime;
		extern U16 kjx_get_heart_rate_total(void);

	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("心率数据heartTotal:%d",  kjx_get_heart_rate_total());
	#endif
	#endif

		tatol++;
		memset(&currTime, 0x00, sizeof(currTime));
   		applib_dt_get_rtc_time(&currTime);
		heartTotal = kjx_get_heart_rate_total();
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_34+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}
#endif

#if defined(__KJX_FUN_STEPS__)||defined(__KJX_SENSOR_DA213__) || defined(__MOTION_SENSOR_MC3413_SUPPORT__)
	/*计步开关（下行）*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_35]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("计步开关stepStatus:%d",  g_kjx_nvram_struct.stepStatus);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_35])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_35+1);
		else
			sprintf(temsprintf,"U%d#%d\0",SERVER_TYPE_35+1,g_kjx_nvram_struct.stepStatus);	
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*计步数据(上行)*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_36]==1)
	{
		int stepsTotal = 0;
		applib_time_struct currTime;
		extern int kjx_steps_teller_total(void);

	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("计步数据stepsTotal:%d",   kjx_steps_teller_total());
	#endif	
	#endif
	
		tatol++;
		memset(&currTime, 0x00, sizeof(currTime));
    	applib_dt_get_rtc_time(&currTime);
		stepsTotal = kjx_steps_teller_total();
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"U%d#%d,%04d%02d%02d%02d%02d\0",SERVER_TYPE_36+1,stepsTotal,currTime.nYear,currTime.nMonth,currTime.nDay,currTime.nHour,currTime.nMin);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}
#endif

	/*正版验证(上行)*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_37]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("正版验证server:%s, port:%d",  g_kjx_nvram_struct.domain.domain, g_kjx_nvram_struct.domain.port);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_37])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_37+1);
		else
			sprintf(temsprintf,"U%d#%s,%d\0",SERVER_TYPE_37+1,g_kjx_nvram_struct.domain.domain, g_kjx_nvram_struct.domain.port);	
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*来电铃声*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_38]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("来电铃声下行toneId:%d",  g_kjx_nvram_struct.toneId);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_38])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_38+1);
		else
			sprintf(temsprintf,"U%d#%d\0",SERVER_TYPE_38+1,g_kjx_nvram_struct.toneId);	
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*音量等级*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_39]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("音量等级volumeLevel:%d",  g_kjx_nvram_struct.volumeLevel);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_39])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_39+1);
		else
			sprintf(temsprintf,"U%d#%d\0",SERVER_TYPE_39+1,g_kjx_nvram_struct.volumeLevel); 
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*恢复出厂设置*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_40]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("恢复出厂设置");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_40+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	/*蓝牙开关*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_41]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("蓝牙开关btStatus:%d",  g_kjx_nvram_struct.btStatus);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_41])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_41+1);
		else
			sprintf(temsprintf,"U%d#%d\0",SERVER_TYPE_41+1,g_kjx_nvram_struct.btStatus);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}
	
	/*蓝牙防丢报警*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_42]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("蓝牙防丢报警");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"U%d#\0",SERVER_TYPE_42+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");	
	}

	/*防脱落报警*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_43]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("防脱落报警");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"U%d#\0",SERVER_TYPE_43+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");	
	}

	/*手动定位*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_44]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("手动定位");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_44])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_44+1);
		else
			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_44+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");	
	}

	/*防脱落开关设置*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_45]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("防脱落开关设置antiLostStatus:%d",  g_kjx_nvram_struct.antiLostStatus);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_45])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_45+1);
		else
			sprintf(temsprintf,"U%d#%d\0",SERVER_TYPE_45+1,g_kjx_nvram_struct.antiLostStatus);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");	
	}

#if defined(CUSTOMER_NAME_S2)
	/*查询参数*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_46]==1)
	{
		alm_nvram_struct *p = (srv_alm_node_type *)srv_alm_read(0);

	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("查询参数");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"U%d#U%d_%s,%s,%s;U%d_%s,%s,%s,%s,%s,%s,%s,%s,%s,%s;U%d_%d;U%d_%d;U%d_%d;U%d_%d;U%d_%d;U%d_%d;U%d_%d,%d,%d\0",
			SERVER_TYPE_46+1,
			SERVER_TYPE_04+1,
			g_kjx_nvram_struct.sosNum[0],
			g_kjx_nvram_struct.sosNum[1],
			g_kjx_nvram_struct.sosNum[2],
			SERVER_TYPE_47+1,
			g_kjx_nvram_struct.whiteNum[0],
			g_kjx_nvram_struct.whiteNum[1],
			g_kjx_nvram_struct.whiteNum[2],
			g_kjx_nvram_struct.whiteNum[3],
			g_kjx_nvram_struct.whiteNum[4],
			g_kjx_nvram_struct.whiteNum[5],
			g_kjx_nvram_struct.whiteNum[6],
			g_kjx_nvram_struct.whiteNum[7],
			g_kjx_nvram_struct.whiteNum[8],
			g_kjx_nvram_struct.whiteNum[9],
			SERVER_TYPE_07+1,
			g_kjx_nvram_struct.alarmType,
			SERVER_TYPE_25+1,
			g_kjx_nvram_struct.workMode,
			SERVER_TYPE_26+1,
			g_kjx_nvram_struct.callMode,
			SERVER_TYPE_41+1,
			g_kjx_nvram_struct.btStatus,
			SERVER_TYPE_45+1,
			g_kjx_nvram_struct.antiLostStatus,
			SERVER_TYPE_38+1,
			g_kjx_nvram_struct.toneId,
			SERVER_TYPE_32+1, // 闹钟
			p->State,
			p->Hour,
			p->Min
			);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}	
#endif // CUSTOMER_NAME_S2

	/*号码昵称*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_47]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("号码昵称");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_47])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_47+1);
		else
			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_47+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");	
	}

	/*远程关机*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_48]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("远程关机");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_48])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_48+1);
		else
			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_48+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");	
	}

	/*计步时间段*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_49]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("计步时间段");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_49])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_49+1);
		else
			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_49+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");	
	}

	/*上课时间段*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_50]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("上课时间段");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_50])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_50+1);
		else
			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_50+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">"); 
	}

#if defined(CUSTOMER_NAME_MEGE2)
	/*低电量报警*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_51]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("低电量报警");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_51])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_51+1);
		else
			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_51+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">"); 
	}

	/*表情灯闪烁*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_52]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("表情灯闪烁");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_52])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_52+1);
		else
			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_52+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">"); 
	}	

	/*设备号码*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_53]==1)
	{
		extern U8 kjxPhoneNum[64];

	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("设备号码kjxPhoneNum:%s",  kjxPhoneNum);
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_53])
			sprintf(temsprintf,"C%d#%s\0",SERVER_TYPE_53+1,kjxPhoneNum);
		else
			sprintf(temsprintf,"U%d#%s\0",SERVER_TYPE_53+1,kjxPhoneNum);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">"); 
	}
#endif

	/*小红花*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_54]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("小红花");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_54])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_54+1);
		else
			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_54+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">"); 
	}

	/*白名单*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_55]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("白名单");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_55])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_55+1);
		else
			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_55+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">"); 
	}

	/*语音对讲*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_56]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("语音对讲");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_56])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_56+1);
		else
			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_56+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">"); 
	}

	/*日期时间同步*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_57]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("日期时间同步");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_57])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_57+1);
		else
			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_57+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">"); 
	}

	/*上课时间段开关*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_58]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("上课时间段开关");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_58])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_58+1);
		else
			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_58+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">"); 
	}

	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_59]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("白名单昵称");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_59+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">"); 
	}

	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_60]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("短信显示");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_60+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">"); 
	}

	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_61]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("RFID播报失效时间");
	#endif	
	#endif
		
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_61+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">"); 
	}

	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_62]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("短信推送");
	#endif
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_62])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_62+1);
		else
			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_62+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">"); 
	}

	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_63]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("定位持续时间");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_63])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_63+1);
		else
			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_63+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">"); 
	}

	/*时钟显示*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_64]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("时钟显示");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_64])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_64+1);
		else
			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_64+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">"); 
	}

	/*心率上传间隔*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_65]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("心率上传间隔");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_65])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_65+1);
		else
			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_65+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">"); 
	}

#if defined(__KJX_RFID__)
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_66]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("RFID播报结束时间回复");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_66+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");	
	}
#endif

	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_67]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("SOS呼叫模式回复");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_67])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_67+1);
		else
			sprintf(temsprintf,"U%d#%d\0",SERVER_TYPE_67+1, g_kjx_nvram_struct.sosCallMode);	
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">"); 
	}

	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_68]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("SOS呼叫模式回复");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_68])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_68+1);
		else
			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_68+1);	
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">"); 
	}

	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_69]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("找设备指令回复");
	#endif	
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_69])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_69+1);
		else
			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_69+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">"); 
	}

#if defined(__KJX_RFID__)
    /*RFID 统计*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_70]==1)  //xb add 2016-08-22     RFID统计
	{
		char strrfid[9] = {0};

	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("RFID 统计");
	#endif	
	#endif

		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_70])
		{
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_70+1);
		}
		else
		{
			kjx_rfid_get_rfid_str(strrfid, sizeof(strrfid));
		#if defined(__KJX_RESET_USED_COUNT__)	//xb add 2017-05-04 复位计次，需要标记是否触发播报
			sprintf(temsprintf,"U%d#%s,3,%d\0",SERVER_TYPE_70+1, strrfid, g_rfid_has_playing);
		#elif defined(__KJX_RFID_LOCATION__)	//xb add 2017-02-07 RFID辅助定位版本
			sprintf(temsprintf,"U%d#%s,2\0",SERVER_TYPE_70+1, strrfid);
		#else
			sprintf(temsprintf,"U%d#%s,1\0",SERVER_TYPE_70+1, strrfid);
		#endif
		}
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}    
#endif

#if defined(__KJX_POSITION_TRIGGER_PLAY__)
	/*位置版定位数据*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_71]==1)
	{
	#if defined(__KJX_FUN_GPS__)
		U8 Altitude = 100;
		U8 HDOP = 10;
		S16 batteryStatus;
		U8 gsm_status;
		S16 sRSSI;
		double distance = 0, runDistance = 0;
		kjx_gps_data *gps_info = &g_kjx_gps_data;
		kjx_lbs_info_struct *lbs_info = &g_kjx_lbs_info_struct;

		tatol++;
		strcat( g_kjx_socket_context.pSendBuff, "<" );
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_71])
		{
			memset(temsprintf, 0x00,sizeof(temsprintf));
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_71+1);
			strcat(g_kjx_socket_context.pSendBuff,temsprintf);
			strcat(g_kjx_socket_context.pSendBuff,">");
		}
		else
		{
			batteryStatus = battery_percentage;
			gsm_status = kjx_sys_get_cur_gsm_status();
			memset( tempack, 0x00, sizeof( tempack ) );
			sRSSI = srv_nw_info_get_signal_strength_in_qdBm(MMI_SIM1);
			sRSSI += 110;

			if(gps_info->data_status == 'A' ) 
			{
			#ifdef GPRS_FORMAT_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("position trigger:gps data");
			#endif
			#endif
			
				sprintf( tempack, "%02d%02d%02d.000,%c,%s,%c,%s,%c,%.3f,%.2f,%02d%02d%02d,,|%d|%d|%03d|%03d\0",
						 gps_info->date.nHour, gps_info->date.nMin, gps_info->date.nSec, gps_info->data_status,
						 gps_info->latitude_gps, gps_info->latitude_dir,
						 gps_info->longitude_gps, gps_info->longitude_dir,
						 gps_info->speed_kh, gps_info->angle, gps_info->date.nDay, gps_info->date.nMonth, gps_info->date.nYear,
						 HDOP, Altitude, batteryStatus, gsm_status );
				
	            memset(temsprintf, 0x00,sizeof(temsprintf));
	            sprintf(temsprintf,"U%d#\0",SERVER_TYPE_71+1);
	            strcat(g_kjx_socket_context.pSendBuff,temsprintf);
	            
	            strcat(g_kjx_socket_context.pSendBuff,tempack);
	            strcat(g_kjx_socket_context.pSendBuff,">");
			}
			else
			{
			#if defined(__KJX_NBR_CELL__)
				S8 lbs_string[32];
	            static int index = 0;
				extern int s_kjx_cell_nbr_num;
				extern kjx_nbr_cell_info_struct* s_kjx_nbr_cell_info[6];

			#ifdef GPRS_FORMAT_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("position trigger:lbs data");
			#endif
			#endif

				for( i = 0; i < s_kjx_cell_nbr_num; i++ ) 
				{
					memset(lbs_string, 0x00, sizeof( lbs_string ) );
					sprintf(lbs_string, "%d,%d,%d,%d,%d\0", s_kjx_nbr_cell_info[i]->ci, s_kjx_nbr_cell_info[i]->lac, s_kjx_nbr_cell_info[i]->mnc, s_kjx_nbr_cell_info[i]->mcc, s_kjx_nbr_cell_info[i]->rxlev);
					strcat( tempack, lbs_string );

					if( s_kjx_cell_nbr_num > i + 1 )
						strcat( tempack, ":" );
					else 
					{
						memset( lbs_string, 0x00, sizeof( lbs_string ) );
	                    if (index == 0)
	                    {
	                        index = 1;
					        sprintf( lbs_string, "::%d,%d,%s,%s,%d|%03d|%03d\0", lbs_info->cid, lbs_info->lac, lbs_info->mnc, lbs_info->mcc, sRSSI, batteryStatus, gsm_status );
	                    }
	                    else
	                    {
	                        index = 0;
					        sprintf( lbs_string, "::%d,%d,%s,%s,%d|%03d|%03d\0", lbs_info->cid, lbs_info->lac, lbs_info->mnc, lbs_info->mcc, sRSSI, batteryStatus, gsm_status );
	                    }
						strcat( tempack, lbs_string );
					}
				}
			#endif
			
				if( s_kjx_cell_nbr_num == 0 ) 
				{
					sprintf( tempack, "%d,%d,%s,%s,%d|%03d|%03d\0",lbs_info->cid, lbs_info->lac, lbs_info->mnc, lbs_info->mcc, sRSSI, batteryStatus, gsm_status );
				}

	            memset(temsprintf, 0x00,sizeof(temsprintf));
	            sprintf(temsprintf,"U%d#\0",SERVER_TYPE_71+1);
	            strcat(g_kjx_socket_context.pSendBuff,temsprintf);
	            
	            strcat(g_kjx_socket_context.pSendBuff,tempack);
	            strcat(g_kjx_socket_context.pSendBuff,">");
			}
		}
	#endif
	}

	/*位置播报统计*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_72]==1)
	{
		char strrfid[9] = {0};

	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("位置播报统计");
	#endif	
	#endif

		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_72])
		{
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_72+1);
		}
		else
		{
			kjx_rfid_get_rfid_str(strrfid, sizeof(strrfid));
			sprintf(temsprintf,"U%d#%s,1\0",SERVER_TYPE_72+1, strrfid);
		}
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");		
	}
#endif

#if defined(__KJX_SERVER_CMD_PLAY__)
	/*后台指令直接播放结果回复*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_73]==1)
	{
		extern U8 g_server_play_result;

	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("后台指令直接播放结果回复");
	#endif	
	#endif

		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"C%d#%d\0",SERVER_TYPE_73+1, g_server_play_result);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	} 	
#endif

#if defined(__KJX_RESET_USED_COUNT__)
	/*复位计次统计*/
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_74]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("复位计次统计");
	#endif	
	#endif

		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(ruc_send_confirm)
		{
			ruc_send_confirm = FALSE;
			sprintf(temsprintf,"U%d#0,1\0",SERVER_TYPE_74+1);
		}
		else
		{
			sprintf(temsprintf,"U%d#%d,1\0",SERVER_TYPE_74+1, g_kjx_nvram_struct.usecount);
		}

		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}
#endif

#if defined(__KJX_MULTI_LANGUAGE__)
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_75]==1)
	{
		U8 language = 1;
		extern U8 g_kjx_language;
		
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("设备语言同步上行");
	#endif	
	#endif

		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
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
			language = 0;
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
			language = 1;
			break;

		default:
			language = 1;
			break;
		}	
		sprintf(temsprintf,"U%d#%d\0",SERVER_TYPE_75+1, language);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}
#endif

#ifdef __KJX_RFID__
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_76]==1)
 	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("设置RFID开关指令回复" );
	#endif
	#endif

		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_76+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}
#endif
	
#ifdef __BLE_MODULE_SUPPORT__
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_77]==1)
 	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("设置蓝牙iBeacon开关指令回复" );
	#endif
	#endif

		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_77+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}
#endif

	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_78]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("设备关机通知后台" );
	#endif
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"U%d#1\0",SERVER_TYPE_78+1);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_79]==1)
	{
		U32 flag = 0;
		
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("设备开机通知后台");
	#endif
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
	#ifdef __KJX_FENCE_SUPPORT__
		flag |= FENCE_FUNC_SUPPORT;
	#endif
	#ifdef __KJX_POSITION_TRIGGER_PLAY__
		flag |= POSITION_TRIGGER_FUNC_SUPPORT;
	#endif
		sprintf(temsprintf,"U%d#1,%d\0",SERVER_TYPE_79+1, flag);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}

#ifdef __KJX_WEATHER_SUPPORT__
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_80]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("设备向后台获取天气数据");
	#endif
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_80])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_80+1);
		else
			sprintf(temsprintf,"U%d#%s\0",SERVER_TYPE_80+1, kjx_weather.cityname);
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");	
	}

	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_81]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("设备向后台获取城市数据");
	#endif
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_81])
			sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_81+1);
		else
		{
			if(kjx_weather.longitude != 0 && kjx_weather.latitude != 0)
				sprintf(temsprintf,"U%d#%f,%f\0",SERVER_TYPE_81+1, kjx_weather.longitude, kjx_weather.latitude);
			else
				sprintf(temsprintf,"U%d#\0",SERVER_TYPE_81+1);//xb add 2017-09-07 没有GPS通过IP地址获取城市
		}
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}
#endif

#ifdef __KJX_FENCE_SUPPORT__
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_82]==1)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("收到围栏报警回复后台");
	#endif
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_82+1);
		
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}
#endif

#ifdef __KJX_FUN_AGPS__
#ifdef __KJX_FUN_GPS_ZKW__
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_83]==1)
	{
		extern U32 g_kjx_agps_date_len;
		
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("设备向后台获取中科微星历数据");
	#endif
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_83])
		{
			if(g_kjx_agps_date_len > 0)
				sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_83+1);
			else
				sprintf(temsprintf,"C%d#3\0",SERVER_TYPE_83+1);
		}
		else
		{
			S16 sRSSI;
			kjx_lbs_info_struct *lbs_info = &g_kjx_lbs_info_struct;
			S8 lbs_string[32];
		#ifdef __KJX_NBR_CELL__	
			extern int s_kjx_cell_nbr_num;
			extern kjx_nbr_cell_info_struct* s_kjx_nbr_cell_info[6];
		#endif
		
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("lbs data");
		#endif
		#endif

			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_83+1);
		
			sRSSI = srv_nw_info_get_signal_strength_in_qdBm(MMI_SIM1);
			sRSSI += 110;
			sprintf(tempack, "%d,%d,%s,%s,%d",lbs_info->cid, lbs_info->lac, lbs_info->mnc, lbs_info->mcc, sRSSI);
			strcat(temsprintf,tempack);
		}
		
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}
#endif	
#endif

	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_84]==1)
	{
		S16 batteryStatus;
		U8 gsm_status;
		S16 sRSSI;
		kjx_lbs_info_struct *lbs_info = &g_kjx_lbs_info_struct;
	#if defined(__KJX_NBR_CELL__)
		S8 lbs_string[32] = {0};
		static int index = 0;
		extern int s_kjx_cell_nbr_num;
		extern kjx_nbr_cell_info_struct* s_kjx_nbr_cell_info[6];
	#endif
	
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("基站定位数据");
	#endif	 
	#endif

		tatol++;
		strcat( g_kjx_socket_context.pSendBuff, "<" );
		batteryStatus = battery_percentage;
		gsm_status = kjx_sys_get_cur_gsm_status();
		memset(tempack, 0x00, sizeof(tempack));
		sRSSI = srv_nw_info_get_signal_strength_in_qdBm(MMI_SIM1);
		sRSSI += 110;

		sprintf(tempack, "%d,%d,%s,%s,%d", lbs_info->cid, lbs_info->lac, lbs_info->mnc, lbs_info->mcc, sRSSI);

	#if defined(__KJX_NBR_CELL__)
		for(i=0;i<s_kjx_cell_nbr_num;i++) 
		{
			memset(lbs_string, 0x00, sizeof(lbs_string));
			sprintf(lbs_string, ":%d,%d,%d,%d,%d", s_kjx_nbr_cell_info[i]->ci, s_kjx_nbr_cell_info[i]->lac, s_kjx_nbr_cell_info[i]->mnc, s_kjx_nbr_cell_info[i]->mcc, s_kjx_nbr_cell_info[i]->rxlev);
			strcat(tempack, lbs_string);
		}
	#endif
	
		memset(lbs_string, 0x00,sizeof(lbs_string));
		sprintf(lbs_string, "|%03d|%03d", batteryStatus, gsm_status);
		strcat(tempack, lbs_string);
		
		memset(temsprintf, 0x00, sizeof(temsprintf));
		sprintf(temsprintf,"U%d#\0", SERVER_TYPE_84+1);
		strcat(g_kjx_socket_context.pSendBuff, temsprintf);
		
		strcat(g_kjx_socket_context.pSendBuff, tempack);
		strcat(g_kjx_socket_context.pSendBuff, ">");
	}

#ifdef __KJX_FUN_GPS_HD__
	if(g_kjx_nvram_struct.updateStatus[SERVER_TYPE_85]==1)
	{
		extern U32 g_kjx_agps_date_len;
		
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("设备向后台获取华大星历数据");
	#endif
	#endif
	
		tatol++;
		strcat(g_kjx_socket_context.pSendBuff,"<");
		memset(temsprintf, 0x00,sizeof(temsprintf));
		
		if(g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_85])
		{
			if(g_kjx_agps_date_len > 0)
				sprintf(temsprintf,"C%d#1\0",SERVER_TYPE_85+1);
			else
				sprintf(temsprintf,"C%d#3\0",SERVER_TYPE_85+1);
		}
		else
		{
			S16 sRSSI;
			kjx_lbs_info_struct *lbs_info = &g_kjx_lbs_info_struct;
			S8 lbs_string[32];
		#ifdef __KJX_NBR_CELL__	
			extern int s_kjx_cell_nbr_num;
			extern kjx_nbr_cell_info_struct* s_kjx_nbr_cell_info[6];
		#endif
		
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("lbs data");
		#endif
		#endif

			sprintf(temsprintf,"U%d#\0",SERVER_TYPE_85+1);
		
			sRSSI = srv_nw_info_get_signal_strength_in_qdBm(MMI_SIM1);
			sRSSI += 110;
			sprintf(tempack, "%d,%d,%s,%s,%d",lbs_info->cid, lbs_info->lac, lbs_info->mnc, lbs_info->mcc, sRSSI);
			strcat(temsprintf,tempack);
		}
		
		strcat(g_kjx_socket_context.pSendBuff,temsprintf);
		strcat(g_kjx_socket_context.pSendBuff,">");
	}
#endif

	strcat(g_kjx_socket_context.pSendBuff,"}\r\n\0");
	headLen += strlen("}\r\n\0");

#ifdef GPRS_FORMAT_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_kjx_socket_context.pSendBuff(%d)=%s,headLen=%d", strlen((char*)g_kjx_socket_context.pSendBuff),g_kjx_socket_context.pSendBuff,headLen);
#endif
#endif

	if(tatol == 0)
	{
		return 0;
	}
	
	if(strlen((char*)g_kjx_socket_context.pSendBuff)<=headLen)
	{
		return 0;
	}
	
	return strlen((char*)g_kjx_socket_context.pSendBuff);
}

U16 kjx_gprs_set_send_data(void)
{
	U16 result=0;
 	
	memset(g_kjx_socket_context.pSendBuff, 0x00,sizeof(g_kjx_socket_context.pSendBuff));
	strcat(g_kjx_socket_context.pSendBuff,"KJX");
	if(KJX_IMEI_UP_LEN == 15)
		strncat(g_kjx_socket_context.pSendBuff,IMEIBuffer,15);
	else
		strncat(g_kjx_socket_context.pSendBuff,IMEIBuffer,14);
	strcat(g_kjx_socket_context.pSendBuff,"|");
	strcat(g_kjx_socket_context.pSendBuff,KJX_PROJECT);
	strcat(g_kjx_socket_context.pSendBuff,"|");
	strcat(g_kjx_socket_context.pSendBuff,KJX_VERSION);

	result=kjx_gprs_set_pack_data();

	return result;
}
#endif

#if defined(__KJX_OBD__)	
void kjx_obd_set_car_info(void)
{
	uint8 carInfos[16];
	uint8 temString[16];
	uint8 temStr[3];
	int i=0;

	memset(carInfos, 0x00, sizeof(carInfos));
	memset(temString, 0x00, sizeof(temString));
	sprintf(temString,"%04d",g_kjx_nvram_struct.carInfo.carType);

	//车系
	for(i=0;i<2;i++)
	{
		memset(temStr, 0x00, sizeof(temStr));
		memcpy(temStr,temString+(i*2), 2);
		carInfos[i]=atoi(temStr);
	}
	carInfos[2]=0x00;
	carInfos[3]=0x00;
	carInfos[4]=0x00;
	carInfos[5]=0x00;

	memset(temString, 0x00, sizeof(temString));
	sprintf(temString,"%06d",g_kjx_nvram_struct.carInfo.KmValue);

	//里程
	for(i=0;i<3;i++)
	{
		memset(temStr, 0x00, sizeof(temStr));
		memcpy(temStr,temString+(i*2), 2);
		carInfos[i+6]=atoi(temStr);
	}
	carInfos[9]=0x00;

	kjx_obd_write_car_infos((S8*)carInfos,10);
}
#endif

#ifdef __KJX_ALARM__
/* 设置闹钟 */
BOOL kjx_alarm_is_sound = FALSE;

void kjx_stop_alarm_sound(void)
{
	extern void AlmStopHandler(void);
	kjx_alarm_is_sound = FALSE;
	//srv_prof_stop_tone(SRV_PROF_TONE_ALARM);
	AlmStopHandler();
}

void kjx_set_alarm_clock( U8 i,alm_nvram_struct  *p  )
{
	srv_alm_write( i,p );
}

int kjx_alarm_pow(int base, int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, ret = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < index; i++)
    {
        ret = ret * base;
    }
    return ret;
}

/*  根据服务器下发指令直接修改系统闹钟*/
void kjx_parse_alarm_data(U8 index,char *str)
{
	const int max = 13;
	int i = 6;
	int num;
	char state[6];
	char *temp_string;
	U16 string_id;
	alm_nvram_struct *p = (srv_alm_node_type *)srv_alm_read(index);

	memset(state,0x00,sizeof(state));

	srv_alm_init(NULL);
	AlmInitNvram();
	
	
	if (  NULL == str  )
		return;
	
	/*开关*/
	strncpy(state,str,1);
	p->State = atoi(state);

#ifdef GPRS_FORMAT_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("state:%d", p->State);
#endif
#endif
	
	if(p->State>1)/* 开关无效 */
		return;
	
	str += 2;
#ifdef GPRS_FORMAT_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("str:%s", str);
#endif
#endif
	
	/*时间*/
       p->Hour = 10 * ( str[ 0 ] - 48 ) + ( str[ 1 ] - 48 ) ;
       p->Min = 10 * ( str[ 3 ] - 48 ) + ( str[ 4 ] - 48 );

	if ( 24 <= p->Hour || 59 <  p->Min  )/* 时间无效 */
		return;
	
	p->Snooze = 0;
	p->SnoozeInterval = 0;
	
	/* 周期 */
	p->Freq = 4;
	p->Days = 0;
	
	while ( 0 != str[ i ] && max > i )
	{
		num = ( int )str[ i ] - 48;
		if ( 0 <= num && 7 >= num )
		{
			if ( 0 == num )
			{ 
				p->Days |= 0; 
			}
			else
			{
				if ( 7 == num )
				  num = 1;
				else
				  num += 1;
				
				  p->Days |= kjx_alarm_pow( 2,num - 1 );
			}
		}
		else
		{ /* 数据无效 */
			return;
		}
		i++;
	}
	
	if ( 0 ==  p->Days  )
		p->Freq = 1;
	
	p->AudioOption 	   = ALM_AUDIO_OPTIONS_TONE;

	string_id = srv_prof_get_string_id_from_srv_audio_id(ALARM_DEFAULT_RING_ID);
	
	if (string_id != NULL)
	{
		p->AudioOptionValue = ALARM_DEFAULT_RING_ID;
		temp_string = GetString(string_id);
	}
	else
	{
		p->AudioOptionValue = 0;
		temp_string = GetString(STR_GLOBAL_EMPTY);
	}

	mmi_ucs2cpy(p->tone_path,temp_string);

	p->AlertType = ALM_ALERT_RING;
		
	/* 保存生效 */
	kjx_set_alarm_clock( index,p );
	
}
#endif

void kjx_send_address_to_sos_callback(srv_sms_callback_struct *callback)
{
#ifdef GPRS_FORMAT_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("result:%d, sms_send_count:%d", callback->result, sms_send_count);
#endif
#endif

	if(callback->result)
	{
	}
	else
	{
	}
}

void kjx_send_address_to_sos(void)
{
	U16 i = 0;
	char smsString[512];
	char smsHeadTotal[256];
	char ucsString[512];
	//求救地址：
	char sosAddress[]={0x42,0x6c,0x51,0x65,0x30,0x57,0x40,0x57,0x1a,0xff,0x0,0x0};
	//（提示：设备工作模式将自动切换正常工作模式）
	char warnStr[]={0x8,0xff,0xd0,0x63,0x3a,0x79,0x1a,0xff,0xbe,0x8b,0x7,0x59,0xe5,0x5d,0x5c,0x4f,0x21,0x6a,0xf,0x5f,0x6,0x5c,0xea,0x81,0xa8,0x52,0x7,0x52,0x62,0x63,0x63,0x6b,0x38,0x5e,0xe5,0x5d,0x5c,0x4f,0x21,0x6a,0xf,0x5f,0x9,0xff,0x0,0x0};

#ifdef GPRS_FORMAT_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("alarmType:%d", g_kjx_nvram_struct.alarmType);
#endif
#endif

	StopTimer(KJX_TIMER_ID_SMS_SENDER_DELAY);

	if((g_kjx_nvram_struct.alarmType!=0)&&(g_kjx_nvram_struct.alarmType!=3))
	{
		//return;
	}

	memset(smsString, 0x00, sizeof(smsString));
	mmi_ucs2cat((CHAR *)smsString, (const CHAR *)sosAddress);
	mmi_ucs2cat((CHAR *)smsString, (const CHAR *)kjxAddress);
#if !defined(CUSTOMER_NAME_MEGE2)&&!defined(CUSTOMER_NAME_TOUR)
	mmi_ucs2cat((CHAR *)smsString, (const CHAR *)warnStr);
#endif

	for(;sms_send_count<3;sms_send_count++)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("sosNum[%d]:%s", sms_send_count, g_kjx_nvram_struct.sosNum[sms_send_count]);
	#endif	
	#endif
		if(strlen(g_kjx_nvram_struct.sosNum[sms_send_count])>0)
		{
		#if defined(CUSTOMER_NAME_MEGE2)
			memset(smsHeadTotal, 0x00, sizeof(smsHeadTotal));
			memset(ucsString, 0x00, sizeof(ucsString));
			strcat(smsHeadTotal,g_kjx_nvram_struct.smsInfo.smsHead);
			strcat(smsHeadTotal,g_kjx_nvram_struct.sosNum[sms_send_count]);
			strcat(smsHeadTotal,g_kjx_nvram_struct.smsInfo.smsEnd);
			mmi_asc_to_ucs2((CHAR *)ucsString, (CHAR *)smsHeadTotal);
			mmi_ucs2cat((CHAR *)ucsString, (const CHAR *)smsString);
			kjx_sms_send_sms(g_kjx_nvram_struct.smsInfo.smsChannel,(unsigned short *)ucsString, 0x08, kjx_send_address_to_sos_callback);
		#else
			kjx_sms_send_sms(g_kjx_nvram_struct.sosNum[sms_send_count],(unsigned short *)smsString, 0x08, kjx_send_address_to_sos_callback);
		#endif
			break;
		}
	}

	sms_send_count++;
	if(sms_send_count < 3)
	{
		StartTimer(KJX_TIMER_ID_SMS_SENDER_DELAY, 10*1000, kjx_send_address_to_sos);
	}
	else
	{
		sms_send_count = 0;
	}	
}


void kjx_cut_off_oil(U8 shutDown)
{
#if 0
	extern const char gpio_kjx_relay_pin;
	
	if(shutDown==0)
	{/*断油电*/
		GPIO_ModeSetup(gpio_kjx_relay_pin,0);
		GPIO_InitIO(1,gpio_kjx_relay_pin);
		GPIO_WriteIO(1,gpio_kjx_relay_pin);
	}
	else if(shutDown==1)
	{/*恢复油电*/
		GPIO_ModeSetup(gpio_kjx_relay_pin,0);
		GPIO_InitIO(1,gpio_kjx_relay_pin);
		GPIO_WriteIO(0,gpio_kjx_relay_pin);
	}
#endif
}

extern float kjxsettime;
void kjx_set_timezone(void)
{
#if defined(__KJX_FUN_GPS__)
	StopTimer(KJX_TIMER_ID_SET_TIMEZONE);
	if(g_kjx_gps_data.data_status == 'A')
	{
		kjxsettime = g_kjx_nvram_struct.timezome;
		
		PhnsetTzoneByIndex(kjxsettime);
		kjx_gps_time_sync(g_kjx_gps_data);
		
		/*停止读取基站数据*/
		StopTimer(KJX_TIMER_ID_CELL_REQ);
		StopTimer(KJX_TIMER_ID_NBR_CELL_REQ);

		kjx_close_gps();
	}
	StartTimer(KJX_TIMER_ID_SET_TIMEZONE,1000*30,kjx_set_timezone);
#endif
}

void kjx_set_language_and_timezone(void)
{
	U8 i = 0;
	S16 error;
	S8 tempLang[SSC_SIZE];
	extern sLanguageDetails gLanguageArray[];
	extern U16 gCurrLangIndex;

	memset(tempLang, 0, SSC_SIZE);
	switch (g_kjx_nvram_struct.language)
	{
		case 0:  //中文
			memcpy(tempLang, SSC_SCHINESE, SSC_SIZE);
			break;
		case 1:   //英文
			memcpy(tempLang, SSC_ENGLISH, SSC_SIZE);
			break;
	}

	for (i = 0; i < MAX_LANGUAGES; i++)
	{
		if (strcmp((PS8) gLanguageArray[i].aLangSSC, (S8*) tempLang) == 0)
		{
			if (gCurrLangIndex != i)
			{
				SetCurrentLanguage(i);
				WriteValue(NVRAM_SETTING_LANG, &i, DS_BYTE, &error);
				break;
			}
		}
	}
	
#if defined(__KJX_FUN_GPS__)
	if(g_kjx_gps_data.data_status == 'A')
	{
		kjx_set_timezone();
	}
	else
	{
		kjx_open_gps();
		StartTimer(KJX_TIMER_ID_SET_TIMEZONE,1000*30,kjx_set_timezone);
	}
#endif
}

void kjx_set_language(void)
{
	U8 i = 0;
	S16 error;
	S8 tempLang[SSC_SIZE];
	extern sLanguageDetails gLanguageArray[];
	extern U16 gCurrLangIndex;

	memset(tempLang, 0, SSC_SIZE);
	switch (g_kjx_nvram_struct.language)
	{
		case 0:  //中文
			memcpy(tempLang, SSC_SCHINESE, SSC_SIZE);
			break;
		case 1:   //英文
			memcpy(tempLang, SSC_ENGLISH, SSC_SIZE);
			break;
	}

	for (i = 0; i < MAX_LANGUAGES; i++)
	{
		if (strcmp((PS8) gLanguageArray[i].aLangSSC, (S8*) tempLang) == 0)
		{
			if (gCurrLangIndex != i)
			{
				SetCurrentLanguage(i);
				WriteValue(NVRAM_SETTING_LANG, &i, DS_BYTE, &error);
				break;
			}
		}
	}
}

void kjx_area_alarm_with_type(U8 alarmSign)
{
	if((g_kjx_nvram_struct.alarmType==0)||(g_kjx_nvram_struct.alarmType==3))
	{//短信推送
		if(alarmSign==0)
			g_kjx_main_func.sms_out_area_alarm();
		else if(alarmSign==1)
			g_kjx_main_func.sms_in_area_alarm();
	}
	else if(g_kjx_nvram_struct.alarmType==2)
	{//电话推送
		g_kjx_main_func.call_area_alarm();
	}
}

BOOL kjx_check_sos_number_is_empty(void)
{
	if((!strlen(g_kjx_nvram_struct.sosNum[0]))
	&&(!strlen(g_kjx_nvram_struct.sosNum[1]))
	&&(!strlen(g_kjx_nvram_struct.sosNum[2]))
	)
	{
		return TRUE;
	}

	return FALSE;
}

void kjx_restore_factory(void)
{
	RstStartRestore();
}

void kjx_bt_set_switch(U8 status)
{
#if (defined(__MMI_BT_SUPPORT__)&&(defined(CUSTOMER_NAME_MEGE2) || defined(CUSTOMER_NAME_BABY1)))
	extern void mmi_bt_switch(U8 status);
	mmi_bt_switch(status);
#endif
}

void kjx_do_with_service_data(char* dataString)
{
	char* typeString = NULL;
	char* temString = NULL;
	U8 inString[512];
	U16 typeIndex = 0,i=0,subTotal=0;
	U16 signIndex=0;/*1:C;2:D*/
	static BOOL isLfashConnet = FALSE;
	
	memset(inString, 0x00, sizeof(inString));
	memcpy(inString, dataString, strlen(dataString));

	typeString = NULL;
	typeString = kjx_get_parameter_string_only_in_buffer(inString,"#",1);
#ifdef GPRS_FORMAT_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("typeString:%s", typeString);
#endif
#endif
	
	if(strstr(typeString,"C"))
		signIndex = 1;
	else if(strstr(typeString,"D"))
		signIndex = 2;
	else
		return;

	typeString += strlen("C");
	typeIndex = atoi(typeString)-1;
#ifdef GPRS_FORMAT_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("typeIndex:%d", typeIndex);
#endif
#endif
	
#if defined(__KJX_DOG__)
	if(typeIndex==SERVER_TYPE_23)
	{
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("电子狗数据更新");
	#endif	
	#endif
		//电子狗数据更新
		return;
	}
#endif

	typeString = NULL;
	typeString = kjx_get_parameter_string_only_in_buffer(inString,"#",2);
#ifdef GPRS_FORMAT_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("typeString=%s", typeString);
#endif
#endif
 	
	if(typeIndex==SERVER_TYPE_31)
	{   
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("地址数据");
	#endif
	#endif	
		return;
	}

	memset(subString, 0x00, sizeof(subString));

	for(i=0;i<15;i++)
	{   
		temString = NULL;
		temString = kjx_get_parameter_string_only_in_buffer_extern(typeString,",",i+1);
		if(temString==NULL)
			break;

		subTotal++;
		memcpy(subString[i],temString, strlen(temString));
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("subString[%d]=%s", i, subString[i]);
	#endif	
	#endif
	}

#ifdef GPRS_FORMAT_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("typeIndex=%d,subTotal=%d,signIndex=%d", typeIndex,subTotal,signIndex);
#endif
#endif

	if(!kjx_get_service_data_total(typeIndex,subTotal,signIndex))
	{/*参数个数有误*/
		if((typeIndex != SERVER_TYPE_55)&&(typeIndex != SERVER_TYPE_04)&&(typeIndex != SERVER_TYPE_68))
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("return error");
		#endif
		#endif
			return;
		}
	}

#ifdef GPRS_FORMAT_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("SERVER_TYPE_%02d", typeIndex+1);
#endif
#endif
	
	switch(typeIndex)
	{
	case SERVER_TYPE_01:
		if(atoi(subString[0])==1)
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("心跳包回复");
		#endif
		#endif
		
			//xb add 2016-12-08	第一个定位点联网就传
			if(kjx_first_gps == TRUE)
			{
				kjx_first_gps = FALSE;					
				g_kjx_socket_event_func.socket_send_gps();
			}

			if(IsMyTimerExist(KJX_TIMER_ID_IS_CONNET))
				StopTimer(KJX_TIMER_ID_IS_CONNET);
			if(IsMyTimerExist(KJX_TIMER_ID_LOGIN_AGAIN))
				StopTimer(KJX_TIMER_ID_LOGIN_AGAIN);			
		}
		break;
		
	case SERVER_TYPE_02:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("域名更改domain:%s, port:%d",   subString[0], subString[1]);
		#endif
		#endif
		
			memset(g_kjx_nvram_struct.domain.domain, 0x00, sizeof(g_kjx_nvram_struct.domain.domain));
			memcpy(g_kjx_nvram_struct.domain.domain, subString[0], strlen(subString[0]));
			g_kjx_nvram_struct.domain.port = atoi((char*)subString[1]);
			kjx_set_domain_infos();
			StartTimer(KJX_TIMER_ID_MISC, 5*1000, kjx_restart);
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_03:
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("定位数据");
	#endif
	#endif
	
		break;
		
	case SERVER_TYPE_04:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SOS号码设置sosNum0:%s, sosNum1:%s, sosNum2:%s",   subString[0], subString[1], subString[2]);
		#endif
		#endif
		
			for(i=0;i<SOS_NUM_MAX;i++)
			{
				memset(g_kjx_nvram_struct.sosNum[i], 0x00, sizeof(g_kjx_nvram_struct.sosNum[i]));
			}
			
			for(i=0;i<subTotal;i++)
			{
				memset(g_kjx_nvram_struct.sosNum[i], 0x00, sizeof(g_kjx_nvram_struct.sosNum[i]));
				memcpy(g_kjx_nvram_struct.sosNum[i], subString[i], strlen(subString[i]));
			}
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_05:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("监听号码设置listenNum:%s",   subString[0]);
		#endif
		#endif
		
			memset(g_kjx_nvram_struct.listenNum, 0x00, sizeof(g_kjx_nvram_struct.listenNum));
			memcpy(g_kjx_nvram_struct.listenNum, subString[0], strlen(subString[0]));
			//监听回拨
		#ifdef __KJX_CUSTOMER_YDHD__
			kjx_listen_call_the_number_other();
		#else
			kjx_listen_call_the_number();
		#endif

			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_06:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("电子围栏报警alarmSign:%d",   atoi((char*)subString[0]));
		#endif
		#endif
		
			//电子围栏报警
			if(atoi((char*)subString[0])==1)
				kjx_area_alarm_with_type(atoi((char*)subString[1]));

			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_07:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("报警推送alarmType:%d",   atoi((char*)subString[0]));
		#endif
		#endif
		
			g_kjx_nvram_struct.alarmType = atoi((char*)subString[0]);
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_08:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{/*上报时间间隔不得低于3分钟*/
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("上传间隔sendTime:%d",   atoi((char*)subString[0]));
		#endif
		#endif
		
			if(atoi((char*)subString[0])<180)
				g_kjx_nvram_struct.sendTime = 1000*180;
			else
				g_kjx_nvram_struct.sendTime = 1000*(atoi((char*)subString[0]));
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("sendTime:%d", g_kjx_nvram_struct.sendTime);
		#endif
		#endif
			kjx_reset_gps_data_send_func();
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_09:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("密码修改password:%s, newpw:%s",   g_kjx_nvram_struct.password, atoi((char*)subString[0]));
		#endif
		#endif
			if(!strcmp(g_kjx_nvram_struct.password,subString[0]))
			{
				memset(g_kjx_nvram_struct.password, 0x00, sizeof(g_kjx_nvram_struct.password));
				memcpy(g_kjx_nvram_struct.password, subString[1], strlen(subString[1]));
			}
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_10:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("APN设置apnMode:%s, userName:%s, passWord:%s",   subString[0], subString[1], subString[2]);
		#endif
		#endif
			memset(g_kjx_nvram_struct.apn.apnMode, 0x00, sizeof(g_kjx_nvram_struct.apn.apnMode));
			memset(g_kjx_nvram_struct.apn.userName, 0x00, sizeof(g_kjx_nvram_struct.apn.userName));
			memset(g_kjx_nvram_struct.apn.passWord, 0x00, sizeof(g_kjx_nvram_struct.apn.passWord));

			memcpy(g_kjx_nvram_struct.apn.apnMode, subString[0], strlen(subString[0]));
			memcpy(g_kjx_nvram_struct.apn.userName, subString[1], strlen(subString[1]));
			memcpy(g_kjx_nvram_struct.apn.passWord, subString[2], strlen(subString[2]));

			kjx_set_apn_infos();
			StartTimer(KJX_TIMER_ID_MISC, 5*1000, kjx_restart);
			
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_11:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("时区语言设置language:%d, timezome:%f",   atoi((char*)subString[0]), atof((char*)subString[1]));
		#endif
		#endif
			g_kjx_nvram_struct.language = atoi((char*)subString[0]);
			g_kjx_nvram_struct.timezome = atof((char*)subString[1]);
			//时区语言设置
			kjx_set_language_and_timezone();
			
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_12:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("语音设置speech:%d",   atoi((char*)subString[0]));
		#endif
		#endif
			g_kjx_nvram_struct.speech = atoi((char*)subString[0]);
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_13:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("语音推送");
		#endif
		#endif		
			//语音推送
			
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_14:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("震动报警sensorAlarm:%d",   atoi((char*)subString[0]));
		#endif
		#endif
		
			g_kjx_nvram_struct.sensorAlarm = atoi((char*)subString[0]);
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_15:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("灵敏度sensorValue:%d",   atoi((char*)subString[0]));
		#endif
		#endif
		
			g_kjx_nvram_struct.sensorValue = atoi((char*)subString[0]);
			//灵敏度设置
			kjx_set_sensor_value();

			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_16:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("超速报警speedValue:%d",  atoi((char*)subString[0]));
		#endif
		#endif
			g_kjx_nvram_struct.speedValue = atoi((char*)subString[0]);
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_17:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("断油断电shutDown:%d",  atoi((char*)subString[0]));
		#endif
		#endif
			g_kjx_nvram_struct.shutDown = atoi((char*)subString[0]);
			//断油断电
			kjx_cut_off_oil(g_kjx_nvram_struct.shutDown);

			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_18:
	#if defined(__KJX_OBD__)	
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("车型设定carType:%d, KmValue:%d",  atoi((char*)subString[0]), atoi((char*)subString[1]));
		#endif
		#endif
			g_kjx_nvram_struct.carInfo.carType= atoi((char*)subString[0]);
			g_kjx_nvram_struct.carInfo.KmValue= atoi((char*)subString[1]);
			
			//OBD车系标定
			kjx_obd_set_car_info();

			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
	#endif
		break;
		
	case SERVER_TYPE_19:
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("OBD数据(上行)");
	#endif
	#endif		
		break;
		
	case SERVER_TYPE_20:
	#if defined(__KJX_OBD__)	
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("非法开门openAlarm:%d",  atoi((char*)subString[0]));
		#endif
		#endif
			g_kjx_nvram_struct.openAlarm= atoi((char*)subString[0]);
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
	#endif
		break;
		
	case SERVER_TYPE_21:
	#if defined(__KJX_OBD__)	
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("非法启动runAlarm:%d",  atoi((char*)subString[0]));
		#endif
		#endif
			g_kjx_nvram_struct.runAlarm= atoi((char*)subString[0]);
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
	#endif
		break;
		
	case SERVER_TYPE_22:
	#if defined(__KJX_DOG__)	
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("电子狗dogPlay:%d",  atoi((char*)subString[0]));
		#endif
		#endif
			g_kjx_nvram_struct.dogPlay= atoi((char*)subString[0]);
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
	#endif
		break;
		
	case SERVER_TYPE_23:
	#if defined(__KJX_DOG__)	
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("云狗数据更新");
		#endif
		#endif
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
	#endif
		break;
		
	case SERVER_TYPE_24:
	#if defined(__KJX_RADAR__)	
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("雷达开关radar:%d",  atoi((char*)subString[0]));
		#endif
		#endif
			g_kjx_nvram_struct.radar= atoi((char*)subString[0]);
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
	#endif
		break;
		
	case SERVER_TYPE_25:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("工作模式设置workMode:%d",  atoi((char*)subString[0]));
		#endif
		#endif
			g_kjx_nvram_struct.workMode= atoi((char*)subString[0]);
			kjx_reset_gps_data_send_func();
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_26:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("通话模式设置callMode:%d",  atoi((char*)subString[0]));
		#endif
		#endif
			g_kjx_nvram_struct.callMode= atoi((char*)subString[0]);
			//通话模式设置
		#if defined(CUSTOMER_NAME_MEGE2)
			g_kjx_nvram_struct.callMode = 1; //监听通话
		#endif
		
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;

	case SERVER_TYPE_27:
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("超速报警(上行)");
	#endif
	#endif
		break;

	case SERVER_TYPE_28:
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("非法启动(上行)");
	#endif
	#endif
		break;

	case SERVER_TYPE_29:
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("非法开门(上行)");
	#endif
	#endif
		break;
	
	#ifdef __KJX_CUSTOMER_YDHD__
	case SERVER_TYPE_30:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("数据同步");
		#endif
		#endif
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
	#endif
	
	case SERVER_TYPE_31:
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("获取地址数据(前面已经处理)");
	#endif
	#endif
		break;
		
	case SERVER_TYPE_32:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
			S8 alarmStr[32];

		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("闹钟设置alarmStr:%s,%s,%s",   subString[0], subString[1], subString[2]);
		#endif
		#endif
			memset(alarmStr, 0x00, sizeof(alarmStr));
			sprintf(alarmStr,"%s,%s,%s\0",subString[0],subString[1],subString[2]);
		#ifdef __KJX_ALARM__
			kjx_parse_alarm_data(0,(char*)alarmStr);
		#endif

			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;

	case SERVER_TYPE_33:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("心率开关onoff:%d",  atoi((char*)subString[0]));
		#endif
		#endif
		#if defined(CUSTOMER_NAME_009A)
			extern void kjx_heart_rate_onoff(U16 flag);
			kjx_heart_rate_onoff(atoi((char*)subString[0]));
		#endif
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_34:
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("心率数据上行");
	#endif
	#endif
		break;

	case SERVER_TYPE_35:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("计步开关onoff:%d",  atoi((char*)subString[0]));
		#endif
		#endif
			kjx_steps_onoff(atoi((char*)subString[0]));
			g_kjx_nvram_struct.stepStatus = atoi((char*)subString[0]);
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_36:
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("计步数据上行");
	#endif
	#endif
		break;
		
	case SERVER_TYPE_37:
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("正版验证");
	#endif
	#endif		
		break;
		
	case SERVER_TYPE_38:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("来电铃声toneId:%d",  atoi((char*)subString[0]));
		#endif
		#endif
			g_kjx_nvram_struct.toneId= atoi((char*)subString[0]);
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
	
	case SERVER_TYPE_39:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("音量等级volumeLevel:%d",  atoi((char*)subString[0]));
		#endif
		#endif
			g_kjx_nvram_struct.volumeLevel= atoi((char*)subString[0]);
			if(g_kjx_nvram_struct.volumeLevel >7)
				g_kjx_nvram_struct.volumeLevel = 6;

		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("volumeLevel:%d", g_kjx_nvram_struct.volumeLevel);
		#endif
		#endif
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}			
		break;

	case SERVER_TYPE_40:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("恢复出厂设置");
		#endif
		#endif

			StartTimer(KJX_TIMER_ID_MISC, 10*1000, kjx_restore_factory);
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}			
		break;
	
	case SERVER_TYPE_41:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("蓝牙开关btStatus:%d", atoi((char*)subString[0]));
		#endif
		#endif
			g_kjx_nvram_struct.btStatus= atoi((char*)subString[0]);
			kjx_bt_set_switch(g_kjx_nvram_struct.btStatus);
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;

	case SERVER_TYPE_42:
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("蓝牙防丢报警(上行)");
	#endif
	#endif
		break;

	case SERVER_TYPE_43:
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("防脱落报警(上行)");
	#endif
	#endif
		break;

	case SERVER_TYPE_44:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("手动定位");
		#endif
		#endif
		
			kjx_handle_position();
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
	
	case SERVER_TYPE_45:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
			g_kjx_nvram_struct.antiLostStatus= atoi((char*)subString[0]);
			{
			#if defined(__LIGHT_DROP_DETECT__)
				extern int ap3426_ps_enable(int enable);
			#ifdef GPRS_FORMAT_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("防脱落开关antiLostStatus:%d", g_kjx_nvram_struct.antiLostStatus);
			#endif
			#endif
				//us5182_set_power_mode(g_kjx_nvram_struct.antiLostStatus);
				//ap3426_ps_enable(g_kjx_nvram_struct.antiLostStatus);
			#endif
				
			}
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}			
		break;
	
	case SERVER_TYPE_46:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("查询参数");
		#endif
		#endif
		
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}			
		break;

	case SERVER_TYPE_47:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("号码昵称");
		#endif
		#endif

			for(i=0;i<SOS_NUM_MAX;i++)
			{
				memset(g_kjx_nvram_struct.sosName[i], 0x00, sizeof(g_kjx_nvram_struct.sosName[i]));
			}
			
			for(i=0;i<subTotal;i++)
			{
				memset(g_kjx_nvram_struct.sosName[i], 0x00, sizeof(g_kjx_nvram_struct.sosName[i]));
				memcpy(g_kjx_nvram_struct.sosName[i], subString[i], strlen(subString[i]));
			}
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
	
	case SERVER_TYPE_48:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
			extern void power_off(void);
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("远程关机remoteShutDown:%d", atoi((char*)subString[0]));
		#endif
		#endif
		
			g_kjx_nvram_struct.remoteShutDown= atoi((char*)subString[0]);
			if(g_kjx_nvram_struct.remoteShutDown == 1)
				StartTimer(KJX_TIMER_ID_MISC, 2*1000, power_off);
			
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}			
		break;
	
	case SERVER_TYPE_49:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("计步时间段");
		#endif
		#endif
		
			// 计步时间段
			for(i=0;i<STEP_NUM_MAX;i++)
			{
				memset(g_kjx_nvram_struct.stepTime[i], 0x00, sizeof(g_kjx_nvram_struct.stepTime[i]));
			}
			
			for(i=0;i<subTotal;i++)
			{
				memset(g_kjx_nvram_struct.stepTime[i], 0x00, sizeof(g_kjx_nvram_struct.stepTime[i]));
				memcpy(g_kjx_nvram_struct.stepTime[i], subString[i], strlen(subString[i]));
			}
		#if defined(CUSTOMER_NAME_SPIRIT)
			kjx_step_set_work_time();
		#endif

			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;

	case SERVER_TYPE_50:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("休眠时间段");
		#endif
		#endif
		
			for(i=0;i<2;i++)
			{
				memset(g_kjx_nvram_struct.studyTime[i], 0x00, sizeof(g_kjx_nvram_struct.studyTime[i]));
			}
			
			for(i=0;i<subTotal;i++)
			{
				memset(g_kjx_nvram_struct.studyTime[i], 0x00, sizeof(g_kjx_nvram_struct.studyTime[i]));
				memcpy(g_kjx_nvram_struct.studyTime[i], subString[i], strlen(subString[i]));
			}
			
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;

	
#if defined(CUSTOMER_NAME_MEGE2)
	case SERVER_TYPE_51:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("低电量报警:  跑马灯操作");
		#endif
		#endif

			LED_foolish_light();
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_52:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("表情灯闪烁");
		#endif
		#endif
		
			LED_light_flash_select((char*)subString[0]);
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}			
		break;

	case SERVER_TYPE_53:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("设备号码");
		#endif
		#endif
		
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}			
		break;
#endif

	case SERVER_TYPE_54:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("小红花flowerNumber:%d", atoi((char*)subString[0]));
		#endif
		#endif
		
			g_kjx_nvram_struct.flowerNumber= atoi((char*)subString[0]);
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}			
		break;
	
	case SERVER_TYPE_55:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("白名单");
		#endif
		#endif
		
			for(i=0;i<10;i++)
			{
				memset(g_kjx_nvram_struct.whiteNum[i], 0x00, sizeof(g_kjx_nvram_struct.whiteNum[i]));
			}
			
			for(i=0;i<subTotal;i++)
			{
				memset(g_kjx_nvram_struct.whiteNum[i], 0x00, sizeof(g_kjx_nvram_struct.whiteNum[i]));
				memcpy(g_kjx_nvram_struct.whiteNum[i], subString[i], strlen(subString[i]));
			}
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}			
		break;
		
	case SERVER_TYPE_56:
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("语音对讲");
	#endif
	#endif
		break;
		
	case SERVER_TYPE_57:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("日期时间同步");
		#endif
		#endif
			for(i=0;i<2;i++)
			{
				memset(g_kjx_nvram_struct.dateTime[i], 0x00, sizeof(g_kjx_nvram_struct.dateTime[i]));
			}

			for(i=0;i<subTotal;i++)
			{
				memcpy(g_kjx_nvram_struct.dateTime[i], subString[i], strlen(subString[i]));
			}

			kjx_set_sys_date_time(FALSE);
		
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;

	case SERVER_TYPE_58:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("上课时间段开关studyMode:%d", atoi((char*)subString[0]));
		#endif
		#endif
		
			g_kjx_nvram_struct.studyMode = atoi((char*)subString[0]);
			
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;

	case SERVER_TYPE_59:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("白名单昵称");
		#endif
		#endif
		
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;

	case SERVER_TYPE_60:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("短信显示");
		#endif
		#endif
		
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
			
	case SERVER_TYPE_61:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("RFID播报失效时间");
		#endif
		#endif
		
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_62:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("短信推送");
		#endif
		#endif
		
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_63:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("定位持续时间");
		#endif
		#endif
		
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_64:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("时钟显示模式");
		#endif
		#endif
		
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_65:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("心率上传间隔");
		#endif
		#endif
		
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;

	case SERVER_TYPE_66:
	#if defined(__KJX_RFID__)
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("RFID播报结束时间nYear:%d,nMonth:%d,nDay:%d,nHour:%d", atoi((char*)subString[0]),atoi((char*)subString[1]),atoi((char*)subString[2]),atoi((char*)subString[3]));
		#endif
		#endif
		
			g_kjx_nvram_struct.rfidOverTime.nYear = atoi((char*)subString[0]);
			g_kjx_nvram_struct.rfidOverTime.nMonth = atoi((char*)subString[1]);
			g_kjx_nvram_struct.rfidOverTime.nDay = atoi((char*)subString[2]);
			g_kjx_nvram_struct.rfidOverTime.nHour = atoi((char*)subString[3]);

			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
	#endif
		break;
	
	case SERVER_TYPE_67:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SOS呼叫模式sosCallMode:%d", atoi((char*)subString[0]));
		#endif
		#endif
			g_kjx_nvram_struct.sosCallMode = atoi((char*)subString[0]);
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;

    case SERVER_TYPE_68:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("上课时间段");
		#endif
		#endif
		
			for(i=0;i<10;i++)
			{
				memset((void*)&g_kjx_nvram_struct.tClassTime[i], 0x00, sizeof(class_time_struct));
			}
			
			for(i=0;i<subTotal;i++)
			{
                char dateStr[2] = {0};
                memset(dateStr,0,2);
				memcpy(dateStr, subString[i], 2);
                g_kjx_nvram_struct.tClassTime[i].startHour = atoi(dateStr);
                memset(dateStr,0,2);
				memcpy(dateStr, (void*)&subString[i][2], 2);
                g_kjx_nvram_struct.tClassTime[i].startMin= atoi(dateStr);
                memset(dateStr,0,2);
				memcpy(dateStr, (void*)&subString[i][5], 2);
                g_kjx_nvram_struct.tClassTime[i].endHour = atoi(dateStr);
                memset(dateStr,0,2);
				memcpy(dateStr, (void*)&subString[i][7], 2);
                g_kjx_nvram_struct.tClassTime[i].endMin= atoi(dateStr);
			}
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}			
        break;
		
    case SERVER_TYPE_69:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("找设备");
		#endif	
		#endif
		
	        kjx_find_device();
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
        break;

	case SERVER_TYPE_70:
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("RFID统计上行");
	#endif
	#endif
		break;

#if defined(__KJX_POSITION_TRIGGER_PLAY__)	//xb add 2017-01-03 位置版后台下发数据
	case SERVER_TYPE_71:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
			U32 kjx_position_rfid_id;
			KJXRFIDINFO *playinfo = NULL;
			extern U8 g_play_cause;
			extern void kjx_rfid_check_id(void);
		
			kjx_position_rfid_id = atoi((char*)subString[0]);
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("位置版后台下发数据kjx_position_rfid_id:%d, kjx_rfid_id:%d", kjx_position_rfid_id, kjx_rfid_id);
		#endif
		#endif

		#if defined(__KJX_RESET_USED_COUNT__)
			if(kjx_position_rfid_id == RESET_RFID)
			{
				kjx_handle_receive_reset_rfid(0);
			}
			else
		#endif
			{
				if(IsMyTimerExist(KJX_TIMER_RESET_SHOW))
					break;
				
				playinfo = kjx_rfid_playinfo_find(kjx_position_rfid_id);
				if(playinfo && (kjx_rfid_id != kjx_position_rfid_id))
				{
					g_play_cause = 1;
					kjx_rfid_id = kjx_position_rfid_id;
					kjx_rfid_check_id();
				}
			}
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
		
	case SERVER_TYPE_72:
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("位置播报统计上行");
	#endif
	#endif
		break;
#endif

#if defined(__KJX_SERVER_CMD_PLAY__)
	case SERVER_TYPE_73:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
			extern U8 g_play_cause;
			extern U8 g_server_play_result;
			extern void kjx_rfid_check_id(void);

		#ifdef GPRS_FORMAT_DEBUG
			LOGD("后台直接下发播报kjx_rfid_id:%s", subString[0]);
		#endif

			if(strlen(subString[0]) < 0 || strlen(subString[0]) > MAX_RFID_LEN)
			{
				g_server_play_result = 2;
			}
			else
			{
				if(IsMyTimerExist(KJX_TIMER_RESET_SHOW))
					break;
				
				g_play_cause = 2;
				kjx_rfid_id = atoi((char*)subString[0]);
			#ifdef GPRS_FORMAT_DEBUG
				LOGD("%s>>kjx_rfid_id:%d", kjx_rfid_id);
			#endif
				kjx_rfid_check_id();
			}

			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}		
		break;
#endif

#if defined(__KJX_RESET_USED_COUNT__)
	case SERVER_TYPE_74:
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("复位计次统计回复");
	#endif
	#endif
	
		if(atoi(subString[0]) == 1)
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("统计上传成功，记录清零");
		#endif
		#endif
			g_kjx_nvram_struct.usecount = 0;
			kjx_nvram_write();

			ruc_send_confirm = TRUE;
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
#endif

#if defined(__KJX_MULTI_LANGUAGE__)
	case SERVER_TYPE_75:
	#ifdef GPRS_FORMAT_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("语言同步回复");
	#endif
	#endif
	
		if(atoi(subString[0]) !=1 )
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("同步失败,重新同步");
		#endif
		#endif

		}
		else
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("同步成功,不再补发");
		#endif
		#endif

			StopTimer(KJX_TIMER_ID_RESEND_LANGUAGE_SET);
		
		#ifdef __KJX_RFID__	//语言同步成功之后，强行要求后台再补发一次
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
		#endif
		}
		break;
#endif

#ifdef __KJX_RFID__
	case SERVER_TYPE_76:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("RFID开关rfidflag:%d", atoi((char*)subString[0]));
		#endif
		#endif
			g_kjx_nvram_struct.rfidflag = atoi((char*)subString[0]);
			if(g_kjx_nvram_struct.rfidflag == 1)
				kjx_rfid_init();
			else
				kjx_rfid_off();
			
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
#endif

#ifdef __BLE_MODULE_SUPPORT__
	case SERVER_TYPE_77:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("蓝牙iBeacon开关btflag:%d", atoi((char*)subString[0]));
		#endif
		#endif
			g_kjx_nvram_struct.btflag = atoi((char*)subString[0]);
			if(g_kjx_nvram_struct.btflag == 1)
				kjx_bt_ibeacon_init();
			else
				kjx_bt_ibeacon_off();

			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}
		break;
#endif

	case SERVER_TYPE_78:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("设备关机后台收到回复");
		#endif
		#endif
		}		
		break;

	case SERVER_TYPE_79:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("设备开机后台收到回复");
		#endif
		#endif
		}		
		break;

#ifdef __KJX_WEATHER_SUPPORT__
	case SERVER_TYPE_80:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
			U32 len = 0;
			U8 tmpbuf[256] = {0};
			
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("后台回复天气数据");
		#endif
		#endif

			//CurrentCity	城市以GB2312编码存储，获取天气的时候指定城市要这个格式
			mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_GB18030, (char*)subString[0], (char*)tmpbuf, sizeof(tmpbuf));
			len = strlen((char*)tmpbuf)>(sizeof(kjx_weather.cityname)-2) ? (sizeof(kjx_weather.cityname)-2) : strlen((char*)tmpbuf);
			memset((char*)kjx_weather.cityname, 0, sizeof(kjx_weather.cityname));
			memcpy((char*)kjx_weather.cityname, (char*)tmpbuf, len);
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("城市:%s", kjx_weather.cityname);
		#endif
		#endif		

			//Date
			len = strlen((char*)subString[1])>(sizeof(kjx_weather.date)-2) ? (sizeof(kjx_weather.date)-2) : strlen((char*)subString[1]);
			memset((char*)kjx_weather.date, 0, sizeof(kjx_weather.date));
			memcpy((char*)kjx_weather.date, (char*)subString[1], len);
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_GB18030, (char*)kjx_weather.date, (char*)tmpbuf, sizeof(tmpbuf));
			LOGD("日期:%s", tmpbuf);
		#endif
		#endif

			//天气
			len = strlen((char*)subString[2])>(sizeof(kjx_weather.weather)-2) ? (sizeof(kjx_weather.weather)-2) : strlen((char*)subString[2]);
			memset((char*)kjx_weather.weather, 0, sizeof(kjx_weather.weather));
			memcpy((char*)kjx_weather.weather, (char*)subString[2], len);
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_GB18030, (char*)kjx_weather.weather, (char*)tmpbuf, sizeof(tmpbuf));
			LOGD("天气:%s", tmpbuf);
		#endif
		#endif

			//风力
			len = strlen((char*)subString[3])>(sizeof(kjx_weather.wind)-2) ? (sizeof(kjx_weather.wind)-2) : strlen((char*)subString[3]);
			memset((char*)kjx_weather.wind, 0, sizeof(kjx_weather.wind));
			memcpy((char*)kjx_weather.wind, (char*)subString[3], len);
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_GB18030, (char*)kjx_weather.wind, (char*)tmpbuf, sizeof(tmpbuf));
			LOGD("风力:%s", tmpbuf);
		#endif
		#endif

			//温度
			len = strlen((char*)subString[4])>(sizeof(kjx_weather.temperatrue)-2) ? (sizeof(kjx_weather.temperatrue)-2) : strlen((char*)subString[4]);
			memset((char*)kjx_weather.temperatrue, 0, sizeof(kjx_weather.temperatrue));
			memcpy((char*)kjx_weather.temperatrue, (char*)subString[4], len);
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_GB18030, (char*)kjx_weather.temperatrue, (char*)tmpbuf, sizeof(tmpbuf));
			LOGD("温度:%s", tmpbuf);
		#endif
		#endif

			//白天图标
			len = strlen((char*)subString[5])>(sizeof(kjx_weather.DayPictureUrl)-2) ? (sizeof(kjx_weather.DayPictureUrl)-2) : strlen((char*)subString[5]);
			memset((char*)kjx_weather.DayPictureUrl, 0, sizeof(kjx_weather.DayPictureUrl));
			memcpy((char*)kjx_weather.DayPictureUrl, (char*)subString[5], len);

			//图标名称
			kjx_get_image_name_from_url(kjx_weather.DayPicName, kjx_weather.DayPictureUrl);
			
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_GB18030, (char*)kjx_weather.DayPictureUrl, (char*)tmpbuf, sizeof(tmpbuf));
			LOGD("白天图标链接:%s", tmpbuf);
		#endif
		#endif

			//夜晚图标
			len = strlen((char*)subString[6])>(sizeof(kjx_weather.NightPictureUrl)-2) ? (sizeof(kjx_weather.NightPictureUrl)-2) : strlen((char*)subString[6]);
			memset((char*)kjx_weather.NightPictureUrl, 0, sizeof(kjx_weather.NightPictureUrl));
			memcpy((char*)kjx_weather.NightPictureUrl, (char*)subString[6], len);

			//图标名称
			kjx_get_image_name_from_url(kjx_weather.NightPicName, kjx_weather.NightPictureUrl);
			
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_GB18030, (char*)kjx_weather.NightPictureUrl, (char*)tmpbuf, sizeof(tmpbuf));
			LOGD("夜晚图标链接:%s", tmpbuf);
		#endif
		#endif

			Kjx_Redraw_Weather();
		
			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}	
		break;

	case SERVER_TYPE_81:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
			U32 len = 0;
			U8 citybuf[256] = {0};
			
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("后台回复城市数据");
		#endif
		#endif

			mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_GB18030, (char*)subString[0], (char*)citybuf, sizeof(citybuf));
			len = strlen((char*)citybuf)>(sizeof(kjx_weather.cityname)-2) ? (sizeof(kjx_weather.cityname)-2) : strlen((char*)citybuf);
			memset((char*)kjx_weather.cityname, 0, sizeof(kjx_weather.cityname));
			memcpy((char*)kjx_weather.cityname, (char*)citybuf, len);

		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("城市:%s", kjx_weather.cityname);
		#endif
		#endif

			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;
		}	
		break;
#endif

#ifdef __KJX_FENCE_SUPPORT__
	case SERVER_TYPE_82:
		if(g_kjx_nvram_struct.service_to_tracer[typeIndex])
		{
			U32 len = 0;
			U8 tmpbuf[256] = {0};
			
		#ifdef GPRS_FORMAT_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("后台围栏报警下发设备提醒");
		#endif
		#endif

			//报警状态
			kjx_fence.alarm_status = atoi((char*)subString[0]);

			//提醒方式
			kjx_fence.alarm_mode = atoi((char*)subString[1]);

			//提醒字符串
			mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char*)subString[2], (char*)tmpbuf, sizeof(tmpbuf));
			len = (2*mmi_ucs2strlen((CHAR*)tmpbuf))>(sizeof(kjx_fence.alarm_str)-2) ? (sizeof(kjx_fence.alarm_str)-2) : (2*mmi_ucs2strlen((CHAR*)tmpbuf));
			memset((char*)kjx_fence.alarm_str, 0, sizeof(kjx_fence.alarm_str));
			memcpy((char*)kjx_fence.alarm_str, (char*)tmpbuf, len);

			g_kjx_nvram_struct.updateStatus[typeIndex] = 1;

			kjx_receive_fence_alarm_proc();
		}	
		break;
#endif

#ifdef __KJX_FUN_AGPS__
#ifdef __KJX_FUN_GPS_ZKW__
	case SERVER_TYPE_83:
		break;
#endif
#endif

	case SERVER_TYPE_84:
		break;

#ifdef __KJX_FUN_AGPS__
#ifdef __KJX_FUN_GPS_HD__
	case SERVER_TYPE_85:
		break;
#endif
#endif

	default:
		break;
	}
}

#endif/*__KJX_FUN__*/
