/**********************************************************************************
*Filename:     kjx_main.h
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2013/12/17
*
***********************************************************************************/
#ifndef __KJX_MAIN_H__
#define __KJX_MAIN_H__

#if defined(__KJX_FUN__)
/****************************************************************************
* Include Files 						包含头文件
*****************************************************************************/
#include "kjx_type_define.h"
#include "kjx_socket.h"

/*****************************************************************************
 *	Define					宏定义
 *****************************************************************************/
#if !defined(MAX_LANGUAGES)
#define MAX_LANGUAGES 30
#endif

#if defined(__KJX_NBR_CELL__)
#define KJX_CELL_NBR_MAX	6
#endif

#define __FAST_TEST_FACTORY__

#ifdef __BLE_MODULE_SUPPORT__
extern const char gpio_bt_power_pin;
#define FUN_BT_PWR_PIN		gpio_bt_power_pin
#endif

#define MAIN_DEBUG

#ifdef __KJX_MULTI_LANGUAGE__
#define KJX_LANGUAGE_MAX	41

#define AUDIODIR_LANG_ENGLISH		L"ENGLISH\\"	//英
#define AUDIODIR_LANG_FRENCH		L"FRENCH\\"		//法
#define AUDIODIR_LANG_GERMAN		L"GERMAN\\"		//德
#define	AUDIODIR_LANG_ITALIAN		L"ITALIAN\\"	//意大利
#define AUDIODIR_LANG_SPANISH		L"SPANISH\\"	//西班牙
#define AUDIODIR_LANG_PORTUGUESE	L"PORTUGUESE\\"	//葡萄牙
#define AUDIODIR_LANG_POLISH		L"POLISH\\"		//波兰
#define	AUDIODIR_LANG_DANISH		L"DANISH\\"		//丹麦
#define AUDIODIR_LANG_SWEDISH		L"SWEDISH\\"	//瑞典
#define AUDIODIR_LANG_NORWEGIAN		L"NORWEGIAN\\" 	//挪威
#define AUDIODIR_LANG_FINNISH		L"FINNISH\\"	//芬兰
#define AUDIODIR_LANG_DUTCH			L"DUTCH\\" 		//荷兰
#define AUDIODIR_LANG_UKRAINIAN		L"UKRAINIAN\\"	//乌克兰
#define AUDIODIR_LANG_RUSSIAN		L"RUSSIAN\\"	//俄罗斯
#define	AUDIODIR_LANG_GREEK			L"GREEK\\" 		//希腊
#define AUDIODIR_LANG_TURKISH		L"TURKISH\\"	//土耳其
#define AUDIODIR_LANG_ARABIC		L"ARABIC\\"		//阿拉伯
#define AUDIODIR_LANG_HEBREW		L"HEBREW\\"		//希伯来语(以色列)
#define AUDIODIR_LANG_PERSIAN		L"PERSIAN\\"	//波斯语(伊朗)
#define AUDIODIR_LANG_URDU			L"URDU\\"		//乌尔都语(巴基斯坦)
#define AUDIODIR_LANG_HINDI			L"HINDI\\" 		//印地语(印度)
#define AUDIODIR_LANG_BENGALI		L"BENGALI\\"	//孟加拉
#define AUDIODIR_LANG_LAO			L"LAO\\"		//老挝
#define AUDIODIR_LANG_KHMER			L"KHMER\\"		//高棉语(柬埔寨)
#define AUDIODIR_LANG_MYANMAR		L"MYANMAR\\"	//缅甸
#define	AUDIODIR_LANG_VIETNAMESE	L"VIETNAMESE\\"	//越南
#define AUDIODIR_LANG_INDONESIAN	L"INDONESIAN\\"	//印度尼西亚
#define AUDIODIR_LANG_MALAY			L"MALAY\\" 		//马来语(马来西亚,文莱)
#define AUDIODIR_LANG_THAI			L"THAI\\"		//泰国
#define AUDIODIR_LANG_FILIPINO		L"FILIPINO\\"	//菲律宾语
#define AUDIODIR_LANG_CHN			L"CHN\\"		//中文普通话
#define AUDIODIR_LANG_CHN_SC		L"CHN_SC\\"		//中文四川话
#define AUDIODIR_LANG_CHN_GD		L"CHN_GD\\"		//中文广东话
#define AUDIODIR_LANG_CHN_MN		L"CHN_MN\\"		//中文闽南话
#define AUDIODIR_LANG_CHN_XZ		L"CHN_XZ\\"		//中文藏语
#define AUDIODIR_LANG_CHN_XZ_LASA	L"CHN_XZ_LASA\\"		//中文藏语拉萨
#define AUDIODIR_LANG_CHN_XZ_ANDUO	L"CHN_XZ_ANDUO\\"		//中文藏语安多
#define AUDIODIR_LANG_CHN_XZ_KANGBA	L"CHN_XZ_KANGBA\\"		//中文藏语康巴
#define AUDIODIR_LANG_CHN_EXTRA		L"CHN_EXTRA\\" 	//中文其他方言
#define AUDIODIR_LANG_KOREAN		L"KOREAN\\"		//朝鲜语(朝鲜,韩国)
#define AUDIODIR_LANG_JAPANESE		L"JAPANESE\\"	//日本
#endif

/*****************************************************************************
*	Enum					枚举类型定义
*****************************************************************************/
typedef enum
{
	kjx_country_id_none=0,
	kjx_country_id_Brazil,				//巴西
	kjx_country_id_Malaysia,			//马来西亚
	kjx_country_id_Thai,				//泰国
	kjx_country_id_Indonesia_xl,		//印度尼西亚excelcom
	kjx_country_id_Indonesia,			//印度尼西亚Telkomsel&indosat
	kjx_country_id_Vietnamese,			//越南
	kjx_country_id_Turkey,				//土耳其
	kjx_country_id_Argentina,			//阿根廷
	kjx_country_id_Egypt,				//埃及
	kjx_country_id_Russia,				//俄罗斯
	kjx_country_id_Colombia,			//哥伦比亚
	kjx_country_id_Kazakhstan,			//哈萨克斯坦
	kjx_country_id_Peru,				//秘鲁
	kjx_country_id_MexicoMiu,			//墨西哥Movistar&Iusacell&Unefon
	kjx_country_id_MexicoTel,			//墨西哥Telcel 				
	kjx_country_id_Southafrica,			//南非
	kjx_country_id_Nigeria,				//尼日利亚
	kjx_country_id_SaudiarabiaMob,		//沙特阿拉伯Mobily
	kjx_country_id_SaudiarabiaStc,		//沙特阿拉伯 Stc
	kjx_country_id_SaudiarabiaZain,		//沙特阿拉伯Zain
	kjx_country_id_Venezuela,			//委内瑞拉
	kjx_country_id_Ukraine,				//乌克兰
	kjx_country_id_IraqAsia,			//伊拉克Asia
	kjx_country_id_IraqZain,			//伊拉克Zain
	kjx_country_id_India,				//印度
	kjx_country_id_India2,				//印度2
	kjx_country_id_chile,				//智利
	kjx_country_id_China
}KJX_COUNTRY_ID_ENUM;	

typedef enum
{
	SMS_LIGHT_FALL_OFF,
	SMS_BT_ANTI_LOST
}kjx_sms_send_type;

#if defined(__KJX_MULTI_LANGUAGE__)
typedef enum
{
	LANG_BEGIN,
	LANG_ENGLISH = LANG_BEGIN,	//英
	LANG_FRENCH,				//法
	LANG_GERMAN,				//德
	LANG_ITALIAN,				//意大利
	LANG_SPANISH,				//西班牙
	LANG_PORTUGUESE,			//葡萄牙
	LANG_POLISH,				//波兰
	LANG_DANISH,				//丹麦
	LANG_SWEDISH,				//瑞典
	LANG_NORWEGIAN,				//挪威
	LANG_FINNISH,				//芬兰
	LANG_DUTCH,					//荷兰
	LANG_UKRAINIAN,				//乌克兰
	LANG_RUSSIAN,				//俄罗斯
	LANG_GREEK,					//希腊
	LANG_TURKISH,				//土耳其
	LANG_ARABIC,				//阿拉伯
	LANG_HEBREW,				//希伯来语(以色列)
	LANG_PERSIAN,				//波斯语(伊朗)
	LANG_URDU,					//乌尔都语(巴基斯坦)
	LANG_HINDI,					//印地语(印度)
	LANG_BENGALI,				//孟加拉
	LANG_LAO,					//老挝
	LANG_KHMER,					//高棉语(柬埔寨)
	LANG_MYANMAR,				//缅甸
	LANG_VIETNAMESE,			//越南
	LANG_INDONESIAN,			//印度尼西亚
	LANG_MALAY,					//马来语(马来西亚,文莱)
	LANG_THAI,					//泰国
	LANG_FILIPINO,				//菲律宾语
	LANG_CHN,					//中文普通话
	LANG_CHN_SC,				//中文四川话
	LANG_CHN_GD,				//中文广东话
	LANG_CHN_MN,				//中文闽南话
	LANG_CHN_XZ,				//中文藏语
	LANG_CHN_XZ_LASA,			//中文藏语拉萨
	LANG_CHN_XZ_ANDUO,			//中文藏语安多
	LANG_CHN_XZ_KANGBA,			//中文藏语康巴
	LANG_CHN_EXTRA,				//中文其他方言
	LANG_KOREAN,				//朝鲜语(朝鲜,韩国)
	LANG_JAPANESE,				//日本
	LANG_MAX
}KJX_SYSTEM_LANGUAGE;
#endif

/*****************************************************************************
 *	Struct					数据结构定义
 *****************************************************************************/
typedef struct
{
    S8 mcc[4];
    S8 mnc[4];
    U16 lac;
    U16 cid;
}kjx_lbs_info_struct;

#if defined(__KJX_NBR_CELL__)
/*cell info structure*/
typedef struct
{
    U16 arfcn;           /*ARFCN*/
    U8 bsic;              /*BSIC*/
    U8 rxlev;            /*Received signal level*/
    U16 mcc;            /*MCC*/
    U16 mnc;            /*MNC*/
    U16 lac;              /*LAC*/
    U16 ci;                /*CI*/
}kjx_nbr_cell_info_struct;
#endif

typedef void (*kjx_void) (void);
typedef void (*kjx_U16) (U16);
typedef void (*kjx_point)(unsigned short * );
typedef void (*kjx_sms) (kjx_sms_send_type);

typedef struct
{
    kjx_void kjx_check_fun;
    kjx_void kjx_main_custom;
    kjx_U16 kjx_set_alarm_status;
    kjx_U16 kjx_set_move_status;
    kjx_U16 kjx_set_speed_status;
#if defined(__KJX_OBD__)
    kjx_void kjx_send_obd_data;
    kjx_point kjx_send_obd_alarm;
#endif
    kjx_U16 kjx_set_gsm_led;

    kjx_void sms_out_area_alarm;
    kjx_void sms_in_area_alarm;
    kjx_void call_area_alarm;
    kjx_sms light_fall_off;
    kjx_sms bt_anti_lost;
} kjx_main_func;

#ifdef __KJX_MULTI_LANGUAGE__
typedef struct
{
	U8 id;
	U8 name[50];
}kjx_language_struct;
#endif

/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/

/****************************************************************************
* Global Variable           	全局变量
*****************************************************************************/
#if defined(__KJX_MULTI_LANGUAGE__)
extern U8 g_kjx_language;
extern U8 g_kjx_titlestr[256];
#endif

/****************************************************************************
* Global Variable - Extern			引用全局变量
*****************************************************************************/
extern BOOL HaveGetIMSI;
extern BOOL EntryTestModeReady; 	/*判断是否处于测试模式*/

extern U8 QueryCommandState;	/*0:SMS 1:ONLINE 2:AT*/
extern kal_uint8 IMEIBuffer[16];
extern kal_uint8 IMSI[17];

extern kjx_lbs_info_struct g_kjx_lbs_info_struct;
extern kjx_socket_context g_kjx_socket_context;
extern kjx_lbs_info_struct g_kjx_lbs_info_struct;
extern kjx_main_func g_kjx_main_func;

/*****************************************************************************
* Global Functions	- Extern		引用外部函数
*****************************************************************************/
#if defined(__KJX_NBR_CELL__)
extern void kjx_get_nbr_cellid_req(void);
extern double kjx_get_lbs_distance(U8 signal_leve);
#endif

extern void kjx_agps_request(void);
extern void kjx_write_work_time(void);
extern BOOL kjx_check_shut_down(void);
#if defined(__KJX_FUN_SENSOR__)
#if defined(__MOTION_SENSOR_MC3413_SUPPORT__)
extern void kjx_sensor_mc3413(void);
#endif
extern void kjx_sensor_reset(void);
extern void kjx_sensor_entry_timer(void);
#endif
extern void kjx_stop_get_cellid(void);
extern void kjx_steps_teller_send_data(void);

/*****************************************************************************
* Local Functions 		本地函数
******************************************************************************/

/*****************************************************************************
* Local Functions 		全局函数
*****************************************************************************/

#endif/*__KJX_FUN__*/

#endif/*__KJX_MAIN_H__*/

