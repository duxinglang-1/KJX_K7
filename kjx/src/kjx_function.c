/**********************************************************************************
*Filename:     kjx_function.c
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2014/09/29
*
***********************************************************************************/
#if defined(__KJX_FUN__)

/****************************************************************************
* Include Files 						包含头文件
*****************************************************************************/
#include "kjx_include.h"
#include "kjx_main.h"
#include "kjx_rfid.h"
#include "kjx_gprs_format.h"
#include "SSCStringTable.h"
#include "FontRes.h"
#include "FontDcl.h"
#include "mmi_rp_srv_general_setting_def.h"
#include "mmi_frm_nvram_gprot.h"
#include "app_datetime.h"
#include "PhbSrv.h"

/*****************************************************************************
 *	Define					宏定义
 *****************************************************************************/
#ifndef ABS
#define ABS(x) ((x) > 0 ? (x) : -(x))
#endif

#define is_incomingcall() (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL,NULL) > 0)
#define is_call() (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
#define is_connected_call() (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)

#define FUNCTION_DEBUG

/*****************************************************************************
*	Enum					枚举类型定义
*****************************************************************************/
typedef enum
{
	PROJECT_ID_NONE,
	PROJECT_ID_K1,
	PROJECT_ID_K2,
	PROJECT_ID_K21,
	PROJECT_ID_K3,
	PROJECT_ID_K5,
	PROJECT_ID_K6,
	PROJECT_ID_K7,
	PROJECT_ID_K8,
	PROJECT_ID_W18,
	PROJECT_ID_MAX
}kjx_project_id;

typedef enum
{
	GPS_PWR_GPIO,
	GPS_PWR_VMC,
	GPS_PWR_VCAMD,
	GPS_PWR_TD,
	GPS_PWR_VCAMA,
	GPS_PWR_DEFAULT
}gps_type;

/*****************************************************************************
 *	Struct					数据结构定义
 *****************************************************************************/
	
/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/
static S8* Stringbuf = NULL;
static U32 Stringlen = 0;

static U8 *recv_pstr1=NULL;
static U8 *recv_pstr2=NULL;

/****************************************************************************
* Global Variable - Extern          全局变量
*****************************************************************************/
BOOL steps_is_use = FALSE;
BOOL heart_is_use = FALSE;
BOOL kjx_sos_in_call=FALSE;
BOOL kjx_sos_screen=FALSE;
BOOL kjx_is_in_charge=FALSE;
applib_time_struct lastSendTime;

/****************************************************************************
* Global Variable - Extern			全局变量
*****************************************************************************/
U32 heartbeat_need_send = 0;
U32 rfid_need_send = 0;

/****************************************************************************
* Global Variable - Extern			引用全局变量
*****************************************************************************/
extern BOOL kjx_is_listen;
extern BOOL socketConnet;
#if defined(CUSTOMER_NAME_TOUR)
extern BOOL powerDataIsSync;
#endif
extern U8 kjx_listen_callmode;
extern S8 kjxAddress[512];
extern S8 kjxTourShow[512];
extern S8 kjxTourInfor[512];
extern U32 kjx_rfid_id;
extern U32 g_ReconnetCount;
extern int SENSOR_MAX_DATA;

#ifdef __KJX_FUN_AGPS__
extern U8 g_kjx_agps_used;
extern BOOL g_kjx_agps_recving;	//0:接收完成或者空闲状态 1:正在接收
extern U32 g_kjx_agps_date_len;
extern U32 g_kjx_agps_data_recvd;
extern U8 g_kjx_agps_valid_time[50];
extern U8 g_kjx_agps_buffer[KJX_AGPS_DATA_MAX_LEN];
extern U8 g_kjx_gps_category;
#ifdef __KJX_FUN_GPS_HD__
extern double g_kjx_HD_agps_lon;//经度
extern double g_kjx_HD_agps_lat;//纬度
#endif

#endif

extern kjx_subTotal g_kjx_subTotal[];
extern kjx_socket_context g_kjx_socket_context;
extern nvram_ef_kjx_nvram_struct g_kjx_nvram_struct;
#ifdef __KJX_TOUR_NAME_STORE_CARD__
extern kjxTourNameInfo g_kjxTourNameInfo;
#endif
/*****************************************************************************
*	Global Functions	- Extern		引用外部函数
*****************************************************************************/
extern kjx_socket_notify_func g_socket_notify_func;
extern kjx_socket_event_func g_kjx_socket_event_func;
extern kjx_gps_func g_kjx_gps_func;
#ifdef __KJX_FUN_AGPS__
extern void kjx_agps_data_write_to_file(U8 *databuf, U32 datalen, BOOL delflag);
extern void kjx_agps_start_push_data_to_mode(U8 *databuf, U32 datalen);
#ifdef __KJX_FUN_GPS_HD__
extern void kjx_hd_agps_begin(void);
#endif/*__KJX_FUN_GPS_HD__*/
#endif

/*****************************************************************************
 *  Local Functions			本地函数
******************************************************************************/

/*****************************************************************************
 *  Local Functions			全局函数
 *****************************************************************************/
//数据存储
void kjx_nvram_read(void)
{
#ifdef __KJX_NEW_NVRAM__
	S16 error;   // NVRAM_READ_SUCCESS

	ReadRecord(NVRAM_EF_KJX_APPICON_LID, 1, &g_kjx_nvram_struct,NVRAM_EF_KJX_APPICON_SIZE,&error);
#else
	kal_uint32 fs_len;
	FS_HANDLE handle;
	S8 usc2Path[64];
	static kal_uint32 read_flag = 0;

	StopTimer(KJX_TIMER_ID_READ_NV);

	if(read_flag ==1)
	{
		return;
	}
	
	memset(usc2Path, 0x00, sizeof(usc2Path));	
	handle = FS_SetCurrentDir(L"Z:\\@kjx\0");

	if(handle>=FS_NO_ERROR)
	{
		FS_SetAttributes(L"nvram\0", FS_ATTR_ARCHIVE);
		handle = FS_Open(L"nvram\0", FS_READ_ONLY | FS_ATTR_ARCHIVE);
		if (handle>=FS_NO_ERROR)
		{
			memset(&g_kjx_nvram_struct, 0x00, sizeof(g_kjx_nvram_struct));
			FS_Read(handle, (void *)&g_kjx_nvram_struct, sizeof(g_kjx_nvram_struct), &fs_len);
			FS_Close(handle);
			read_flag = 1;
		}
	}
	else
	{
		memset(&g_kjx_nvram_struct, 0x00, sizeof(g_kjx_nvram_struct));
		read_flag = 0;
	}
	
	StartTimer(KJX_TIMER_ID_READ_NV, 1000*2, kjx_nvram_read);
#endif
}

void kjx_nvram_write(void)
{
#ifdef __KJX_NEW_NVRAM__
	S16 error;  // NVRAM_WRITE_SUCCESS

	WriteRecord(NVRAM_EF_KJX_APPICON_LID,1,&g_kjx_nvram_struct,NVRAM_EF_KJX_APPICON_SIZE,&error);
#else
	kal_uint32 fs_len;
	FS_HANDLE handle;
	S8 usc2Path[64];

	memset(usc2Path, 0x00, sizeof(usc2Path));	
	mmi_ucs2cpy((S8*)usc2Path, (const CHAR *)(L"Z:\\@kjx\0"));

	handle = FS_SetCurrentDir((WCHAR*)usc2Path);
	if (handle < 0)
	{
		handle = FS_CreateDir((WCHAR*)usc2Path);
		if (handle < 0 )
			return;

		handle = FS_SetCurrentDir((WCHAR*)usc2Path);	 
		if (handle < 0)
			return;
	}

	FS_SetAttributes(L"nvram\0", FS_ATTR_ARCHIVE);
	handle = FS_Open(L"nvram\0", FS_READ_WRITE | FS_ATTR_ARCHIVE);
	
	if (handle < 0)    /* failed to open existing file, or file not exists */
	{
		/* try to create file */
		handle = FS_Open(L"nvram\0", FS_READ_WRITE | FS_CREATE_ALWAYS | FS_ATTR_ARCHIVE);
		if (handle < 0)
			return;
	}

	if (handle>=FS_NO_ERROR)
	{
		FS_Write(handle, (void *)&g_kjx_nvram_struct, sizeof(g_kjx_nvram_struct), &fs_len);
		FS_Commit(handle);
		FS_Close(handle);
	}
#endif
}

BOOL kjx_is_use_steps(void)
{
#ifdef FUNCTION_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("steps_is_use:%d", steps_is_use);
#endif
#endif
	return steps_is_use;
}

BOOL kjx_is_use_heart(void)
{
#ifdef FUNCTION_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("heart_is_use:%d", heart_is_use);
#endif
#endif
	return heart_is_use;
}

BOOL kjx_is_charging(void)
{
	return kjx_is_in_charge;
}

U16 kjx_get_project_id(void)
{
	#if defined(CUSTOMER_NAME_SCHOOL)||defined(CUSTOMER_NAME_OLDMAN)
		return GPS_PWR_VMC;
	#elif defined(CUSTOMER_NAME_S2)
		return GPS_PWR_VCAMD;
	#elif defined(CUSTOMER_NAME_TOUR_TAIDOU)
		return GPS_PWR_TD;
	#elif defined(CUSTOMER_NAME_TOUR)
		return GPS_PWR_GPIO;
	#else
		return GPS_PWR_GPIO;
	#endif
}

U16 kjx_return_project_id(void)
{
	#if defined(CUSTOMER_NAME_BDTS)
		return PROJECT_ID_K1;
	#elif defined(CUSTOMER_NAME_MEGE1)
		return PROJECT_ID_K2;
	#elif defined(CUSTOMER_NAME_MEGE2)
		return PROJECT_ID_K21;
	#elif defined(CUSTOMER_NAME_BABY1)
		return PROJECT_ID_K3;
	#elif defined(CUSTOMER_NAME_OLDMAN)
		return PROJECT_ID_K5;
	#elif defined(CUSTOMER_NAME_TOUR)
		return PROJECT_ID_K6;
	#elif defined(CUSTOMER_NAME_K7)
		return PROJECT_ID_K7;
	#elif defined(CUSTOMER_NAME_K8)
		return PROJECT_ID_K8;
	#elif defined(CUSTOMER_NAME_W18)
		return PROJECT_ID_K2;
	#else
		return PROJECT_ID_NONE;
	#endif
}


void kjx_set_domain_infos(void)
{
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("domain:%s, port:%d", g_kjx_nvram_struct.domain.domain, g_kjx_nvram_struct.domain.port);
#endif
	memset(g_kjxNetInfo.domain, 0x00, sizeof(g_kjxNetInfo.domain));
	memcpy(g_kjxNetInfo.domain, g_kjx_nvram_struct.domain.domain, strlen(g_kjx_nvram_struct.domain.domain));
	g_kjxNetInfo.port = g_kjx_nvram_struct.domain.port;
}

void kjx_set_apn_infos(void)
{
#ifdef FUNCTION_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("apnMode:%s, userName:%s, passWord:%s", g_kjx_nvram_struct.apn.apnMode, g_kjx_nvram_struct.apn.userName, g_kjx_nvram_struct.apn.passWord);
#endif
#endif

	memset(&g_kjxNetInfo.apn, 0x00, sizeof(kjxApnInfo));
	memcpy(g_kjxNetInfo.apn.apnMode, g_kjx_nvram_struct.apn.apnMode, strlen(g_kjx_nvram_struct.apn.apnMode));
	memcpy(g_kjxNetInfo.apn.userName, g_kjx_nvram_struct.apn.userName, strlen(g_kjx_nvram_struct.apn.userName));
	memcpy(g_kjxNetInfo.apn.passWord, g_kjx_nvram_struct.apn.passWord, strlen(g_kjx_nvram_struct.apn.passWord));
}

#ifdef __KJX_TOUR_NAME_STORE_CARD__
void kjx_update_tour_name_infor(U32 rfid_num, char *name)
{
	U32 i=0,rfid_id,flag = 0,str_len = 0;
#ifdef __KJX_RFID_LOCATION__
	U32 temp_id = rfid_num%1000000;
#else
	U32 temp_id = rfid_num;
#endif
	kal_uint32 fs_len;
	FS_HANDLE handle;
	S8 usc2Path[64] = {0};
	char tmpbuf[512] = {0};
	KJXNAMEINFO *nameinfo = NULL;

	if(rfid_num <= 0)
	{
	#ifdef FUNCTION_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return rfid_num:%d", rfid_num);
	#endif
	#endif
		return;
	}

#ifdef FUNCTION_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("name:%s", name);
#endif
#endif

	nameinfo = kjx_rfid_nameinfo_find(temp_id);
	if(nameinfo)
	{
		mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_GB18030, name, tmpbuf, sizeof(tmpbuf));
		if(strcmp(tmpbuf, nameinfo->name) != 0)
		{
			flag = 1;
			memset(nameinfo->name, 0, sizeof(nameinfo->name));
			if(strlen(tmpbuf) > (sizeof(nameinfo->name) - 2))
			{
				strncpy(nameinfo->name, tmpbuf, (sizeof(nameinfo->name) - 2));
			}
			else
			{
				strcpy(nameinfo->name, tmpbuf);
			}
		}
	}
	else
	{
		char strrfid[MAX_RFID_LEN+1] = {0};
		char strname[MAX_SHOW_NAME_LEN+1] = {0};

		sprintf(strrfid, "%08d", temp_id);
		mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_GB18030, name, strname, sizeof(strname));		
		if(kjx_rfid_nameinfo_add(strrfid, strname))
		{
			flag = 1;
		}
	}

	if(flag == 1)
	{
	#ifdef FUNCTION_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("need update file!");
	#endif
	#endif
		kal_wsprintf((WCHAR*) usc2Path, "%c%w", SRV_FMGR_CARD_DRV, AUDIODIR);

	#ifdef __KJX_MULTI_LANGUAGE__
		switch(g_kjx_language)
		{
		case LANG_ENGLISH:				//英
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_ENGLISH);
			break;
		case LANG_FRENCH:				//法
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_FRENCH);
			break;
		case LANG_GERMAN:				//德
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_GERMAN);
			break;
		case LANG_ITALIAN:				//意大利
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_ITALIAN);
			break;
		case LANG_SPANISH:				//西班牙
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_SPANISH);
			break;
		case LANG_PORTUGUESE:			//葡萄牙
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_PORTUGUESE);
			break;
		case LANG_POLISH:				//波兰
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_POLISH);
			break;
		case LANG_DANISH:				//丹麦
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_DANISH);
			break;
		case LANG_SWEDISH:				//瑞典
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_SWEDISH);
			break;
		case LANG_NORWEGIAN:			//挪威
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_NORWEGIAN);
			break;
		case LANG_FINNISH:				//芬兰
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_FINNISH);
			break;
		case LANG_DUTCH:				//荷兰
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_DUTCH);
			break;
		case LANG_UKRAINIAN:			//乌克兰
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_UKRAINIAN);
			break;
		case LANG_RUSSIAN:				//俄罗斯
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_RUSSIAN);
			break;
		case LANG_GREEK:				//希腊
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_GREEK);
			break;
		case LANG_TURKISH:				//土耳其
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_TURKISH);
			break;
		case LANG_ARABIC:				//阿拉伯
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_ARABIC);
			break;
		case LANG_HEBREW:				//希伯来语(以色列)
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_HEBREW);
			break;
		case LANG_PERSIAN:				//波斯语(伊朗)
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_PERSIAN);
			break;
		case LANG_URDU: 				//乌尔都语(巴基斯坦)
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_URDU);
			break;
		case LANG_HINDI:				//印地语(印度)
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_HINDI);
			break;
		case LANG_BENGALI:				//孟加拉
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_BENGALI);
			break;
		case LANG_LAO:					//老挝
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_LAO);
			break;
		case LANG_KHMER:				//高棉语(柬埔寨)
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_KHMER);
			break;
		case LANG_MYANMAR:				//缅甸
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_MYANMAR);
			break;
		case LANG_VIETNAMESE:			//越南
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_VIETNAMESE);
			break;
		case LANG_INDONESIAN:			//印度尼西亚
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_INDONESIAN);
			break;
		case LANG_MALAY:				//马来语(马来西亚,文莱)
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_MALAY);
			break;
		case LANG_THAI: 				//泰国
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_THAI);
			break;
		case LANG_FILIPINO: 			//菲律宾语
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_FILIPINO);
			break;
		case LANG_KOREAN:				//朝鲜语(朝鲜,韩国)
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_KOREAN);
			break;
		case LANG_JAPANESE: 			//日本
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_JAPANESE);
			break;
		case LANG_CHN:					//中文普通话
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_CHN);
			break;
		case LANG_CHN_SC:				//中文四川话
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_CHN_SC);
			break;
		case LANG_CHN_GD:				//中文广东话
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_CHN_GD);
			break;
		case LANG_CHN_MN:				//中文闽南话
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_CHN_MN);
			break;
		case LANG_CHN_XZ:				//中文藏语
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_CHN_XZ);
			break;
		case LANG_CHN_XZ_LASA:				//中文藏语拉萨
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_CHN_XZ_LASA);
			break;
		case LANG_CHN_XZ_ANDUO:				//中文藏语安多
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_CHN_XZ_ANDUO);
			break;
		case LANG_CHN_XZ_KANGBA:			//中文藏语康巴
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_CHN_XZ_KANGBA);
			break;			
		case LANG_CHN_EXTRA:			//中文其他方言
			mmi_ucs2cat((CHAR*)usc2Path, (CHAR*)AUDIODIR_LANG_CHN_EXTRA);
			break;
		}
	#endif
	
		handle = FS_SetCurrentDir((WCHAR*)usc2Path);
		if(handle>=FS_NO_ERROR)
		{
			FS_SetAttributes(AUDIONAMEINFO, FS_ATTR_ARCHIVE);
			FS_Delete(AUDIONAMEINFO);
			
			handle = FS_Open(AUDIONAMEINFO, FS_READ_WRITE | FS_ATTR_ARCHIVE |FS_CREATE_ALWAYS);
			if(handle>=FS_NO_ERROR)
			{
			#ifdef FUNCTION_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("file creat!");
			#endif
			#endif

				memset(tmpbuf, 0, sizeof(tmpbuf));
				sprintf(tmpbuf, "%d", g_kjxTourNameInfo.maxID);
				
				Stringlen = strlen(tmpbuf)+strlen("|")+g_kjxTourNameInfo.maxID*(sizeof(KJXNAMEINFO)+strlen(",")+strlen(";"))+2;
			#ifdef FUNCTION_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("Stringlen:%d", Stringlen);
			#endif
			#endif
				media_get_ext_buffer(MOD_MMI, (void **)&Stringbuf, Stringlen);
				if(Stringbuf == NULL)
				{
				#ifdef FUNCTION_DEBUG
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("申请内存失败!");
				#endif
				#endif
					FS_Close(handle);
					return;
				}
				
				memset(Stringbuf, 0x00, Stringlen);
				strcpy(Stringbuf, tmpbuf);
				strcat(Stringbuf, "|");

				i = 0;
				nameinfo = g_kjxTourNameInfo.nameinfo;
				while((i < g_kjxTourNameInfo.maxID) && (nameinfo != NULL))
				{
					strcat(Stringbuf, nameinfo->rfid_id);
					strcat(Stringbuf, ",");
					strcat(Stringbuf, nameinfo->name);
					strcat(Stringbuf, ";");
					
					nameinfo = nameinfo->next;
					i++;
				}

				str_len = strlen(Stringbuf);
			#if defined(__KJX_AUDIO_FILE_DECODE__)
				kjx_decode_string(Stringbuf, str_len);
			#endif
				FS_Write(handle, (void*)Stringbuf, str_len, &fs_len);
				FS_Commit(handle);
				FS_Close(handle);

				if(Stringbuf != NULL)
				{
					media_free_ext_buffer(MOD_MMI, (void**)&Stringbuf);
					Stringbuf = NULL;
				}				
			}
		}
		else
		{
		#ifdef FUNCTION_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("文件打开失败!");
		#endif
		#endif
		}
	}
}
#endif


/*---------------------------------------------------------------------------
 * FUNCTION			srv_phb_util_convert_number_to_int
 *
 * DESCRIPTION      最多比较电话号码后7位是否完全相同
 *
 * PARAMETERS
 *		void
 * RETURNS
 *  		void
 * ----------------------------------------
 * v1.0  , 2011-11-01, guojie  written
  * ----------------------------------------
 *---------------------------------------------------------------------------*/ 
static U32 srv_phb_util_convert_number_to_int(U8 *ascii_number) 
{ 
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */ 
    /*----------------------------------------------------------------*/
    U16 num_len;
    U16 ext_len;
    U16 buff_len = 40 + 1;            //MMI_PHB_NUMBER_LENGTH
    U8 *number;
    U8 temp_number[40 + 1 + 1];  		//MMI_PHB_NUMBER_LENGTH
    U8 compare_length = SOS_NUM_LAN;  		/* Maximum convert number length is 9 digits. (4 bytes integer) */
    /*----------------------------------------------------------------*/ 
    /* Code Body                                                      */ 
    /*----------------------------------------------------------------*/
    if(ascii_number != NULL)
    { 
    	strncpy((S8*) temp_number, (S8*) ascii_number, buff_len);
        memset((temp_number + buff_len), 0x00, 1);  
		/* Makre sure there will be terminator */ 
	}
    else
    { 
    	return SRV_PHB_INVALID_NUMBER; 
	}
    number = (U8*) temp_number;
    /* Ignore  *31# and #31# case */
    while(((number[0] == '*') && (number[1] == '3') && (number[2] == '1') && (number[3] == '#')) || ((number[0] == '#') && (number[1] == '3') && (number[2] == '1') && (number[3] == '#'))) 
	{ 
		number += 4; 
	}
    /* Skip the first plus sign */
    if(number[0] == '+')
    { 
    	number++; 
	}
    /* number empty */
    if(number[0] == '\0')
    {
        return SRV_PHB_INVALID_NUMBER; 
	}
    /* Find the position of extension number and remove that part */ 
	ext_len = strcspn((PS8) number, "+pw*#");
    if(!ext_len)
    { 
    	return SRV_PHB_INVALID_NUMBER; 
	}
    else
    { 
        number[ext_len] = '\0';
        num_len = strlen((PS8) number);
        /* May compare less number than 9 digits */
        if(num_len < SOS_NUM_LAN)
        { 
        	compare_length = num_len; 
		}
        /* Convert at most 9 digits integer */
        if(num_len > compare_length)
        { 
        	number += num_len - compare_length; 
		}
        /* return a 32 bits integer by atol() */
        return atol((PS8) number); 
	} 
}

/******************************************************************************
 *  Function    -  ConfirmNumberIsSOS
 *
 *  Purpose     -   确认是否是SOS号码
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2012-08-09
 * ----------------------------------------
 ******************************************************************************/
 U8 ConfirmNumberIsSOS(char* InComingNumber) 
 { 
 	int i;
    char PhoneNumber[SOS_NUM_LAN] = {0};
    int NumLen = 0, FamilyNumlen = 0;
    U32 newNumber, newWhiteListNum;
    /*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	memset(PhoneNumber, 0, sizeof(PhoneNumber));
    strcpy(PhoneNumber, (char *)InComingNumber);
    NumLen = strlen((char*)PhoneNumber);
    if(NumLen >= 3 && NumLen < SOS_NUM_LAN) //测试仪器来电号码 
    { 
    	if(NumLen == 5 && strcmp((char *)"12345", (char *)PhoneNumber) == 0)
        { 
        	return 0; 
		}
        else
        { 
        	/*用srv_phb_convert_number_to_int 转会出错*/
            newNumber = srv_phb_util_convert_number_to_int((U8 *)PhoneNumber); 
			for(i = 0; i < SOS_NUM_MAX; i++)
            { 
            	FamilyNumlen = strlen(g_kjx_nvram_struct.sosNum[i]); 
				newWhiteListNum = srv_phb_util_convert_number_to_int((U8 *)g_kjx_nvram_struct.sosNum[i]);
                if(newNumber == newWhiteListNum)
                { 
                	return i + 1;
				}
			}
		}
	}
    return 0XFF;
}

/******************************************************************************
 *  Function    -  system_string2U16
 *
 *  Purpose     -  将输入字符转为十进制数
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 26-05-2012,  guojie  arrange
 * ----------------------------------------
 ******************************************************************************/ 
U16 system_string2U16(void *string) 
{ 
	S8 str_len;
    S8 *str_ptr;
    U8 i = 0;
    U8 temp[10];
    U16 rpt;
	
    memset(temp, 0, sizeof(temp));
    str_ptr = (S8 *)string;
    str_len = strlen(string);
    if((str_len >= 6) || (str_len <= 0)) 
		return 0xFFFF;
	
    for(i = 0; i < str_len; i++)
    { 
    	if((*(str_ptr + i)) < '0' || (*(str_ptr + i)) > '9')
        { 
        	return 0xFFFF; 
		}
		
        temp[str_len-1-i] = (*(str_ptr + i)) - '0'; 
	}
	
    rpt = temp[4] * 10000 + temp[3] * 1000 + temp[2] * 100 + temp[1] * 10 + temp[0]; 
	return rpt; 
}

BOOL kjx_incoming_check_number(U16* display_name)
{
	char acssi_number[32];
	U8 astr[]={0xf7,0x01,0x0d,0xe6,0x08,0x0d,0x58,0x28,0x09};
	int i=0;
	BOOL checkStatus = FALSE;

#if defined(__KJX_INCOMING_CALL_CHECK__)	//xb add 2017-12-19 A2项目来电不做筛选
	memset(acssi_number, 0x00, sizeof(acssi_number));
	mmi_ucs2_to_asc((CHAR *)acssi_number, (CHAR *)display_name);
	
	if(strstr((char*)acssi_number,"Unknown caller")||memcmp(acssi_number,astr,sizeof(astr)) == 0)
	{/*未开通来电显示，无法获取来电号码*/
	#ifdef FUNCTION_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("Unknown caller");
	#endif
	#endif
		return FALSE;
	}

#ifdef FUNCTION_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("acssi_number:%s, sosNum[0]:%s, sosNum[1]:%s, sosNum[2]:%s", acssi_number,g_kjx_nvram_struct.sosNum[0], g_kjx_nvram_struct.sosNum[1], g_kjx_nvram_struct.sosNum[2]);
#endif
#endif

	if((kjx_check_number_different((char*)acssi_number,g_kjx_nvram_struct.sosNum[0]))
		&&(kjx_check_number_different((char*)acssi_number,g_kjx_nvram_struct.sosNum[1]))
		&&(kjx_check_number_different((char*)acssi_number,g_kjx_nvram_struct.sosNum[2])))
	{
	#ifdef FUNCTION_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("no sos number");
	#endif	
	#endif
		
		for(i=0;i<10;i++)
		{
		#ifdef FUNCTION_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("acssi_number:%s,whiteNum[%d]:%s", acssi_number, i, g_kjx_nvram_struct.whiteNum[i]);
		#endif	
		#endif
			if(kjx_check_number_different((char*)acssi_number,g_kjx_nvram_struct.whiteNum[i]))
			{
				checkStatus = FALSE;
			}
			else
			{
				checkStatus = TRUE;
				break;
			}
		}

		if(!checkStatus)
		{
		#ifdef FUNCTION_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("return FALSE checkStatus:%d", checkStatus);
		#endif		
		#endif
			return FALSE;
		}	
	}
#ifdef FUNCTION_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("return TRUE");
#endif 
#endif
	return TRUE;

#else/*__KJX_INCOMING_CALL_CHECK__*/
	return TRUE;
#endif/*__KJX_INCOMING_CALL_CHECK__*/
}

#if defined(CUSTOMER_NAME_SCHOOL)
void kjx_set_callmode(U8 callmode)
{
	//g_kjx_nvram_struct.callMode = callmode;//监听通话
#ifdef FUNCTION_DEBUG	
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("callMode:%d", g_kjx_nvram_struct.callMode);
#endif
#endif
}
#endif
U8 kjx_check_callmode(void)
{
#ifdef FUNCTION_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("callMode:%d", g_kjx_nvram_struct.callMode);
#endif
#endif

#if defined(CUSTOMER_NAME_SKY)
	g_kjx_nvram_struct.callMode = 1;//监听通话
#endif
	return g_kjx_nvram_struct.callMode;
}

U8 kjx_check_callmode_and_number(U16* display_name)
{
	/*0:挂断；
	**1:双向通话接听；
	**2:双向通话挂断；
	**3:监听通话接听；
	**4:监听通话挂断；
	*/
	U8 callMode = 0;

	if(!kjx_is_on_work_time())
	{/*上课免打扰*/
		return callMode;
	}
	
	switch(g_kjx_nvram_struct.callMode)
	{
	case 0://双向通话
	#ifdef FUNCTION_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("双向通话");
	#endif
	#endif
	
		if(kjx_incoming_check_number(display_name))
		{
			
		#if defined(CUSTOMER_NAME_SCHOOL)
			callMode = 3;
		#else
			callMode = 1;
		#endif
		}
		else
		{
			callMode = 2;
		}
		break;

	case 1://监听通话
	#ifdef FUNCTION_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("监听通话");
	#endif
	#endif
	
		if(kjx_incoming_check_number(display_name))
		{
			callMode = 3;
		}
		else
		{
			callMode = 4;
		}
		break;

	default:
		break;
	}

	return callMode;
}

void kjx_reset_callmode(void)
{
#ifdef FUNCTION_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
	if(kjx_is_in_call())
		return;

#ifdef FUNCTION_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("001");
#endif
#endif

	if((kjx_is_listen)&&(kjx_listen_callmode != g_kjx_nvram_struct.callMode))
	{
		kjx_is_listen = FALSE;
		kjx_sos_get_address();
		g_kjx_nvram_struct.callMode = kjx_listen_callmode;
		kjx_nvram_write();
	}
}

void kjx_listen_call_the_number(void)
{
	char ucs2Num[64]={0};
	char ascNum[32];
	extern U16 kjx_call_index;

#ifdef FUNCTION_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	memset(ascNum, 0x00, sizeof(ascNum));
	mmi_asc_to_ucs2((CHAR *)ascNum, (CHAR *)g_kjx_nvram_struct.listenNum);

	if(!kjx_incoming_check_number((U16*)ascNum))
	{
		return;
	}

	if((kjx_is_in_call()))
	{
	#ifdef FUNCTION_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return:is in call!");
	#endif	
	#endif
		return;
	}

	if(!strlen((char*)g_kjx_nvram_struct.listenNum))
	{
		kjx_call_index = 4;
	#ifdef FUNCTION_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return:no number!");
	#endif	
	#endif
		return;
	}

	kjx_is_listen = TRUE;
	kjx_listen_callmode = g_kjx_nvram_struct.callMode;
	g_kjx_nvram_struct.callMode = 1;//监听
	
	memset(ucs2Num, 0x00, sizeof(ucs2Num));
	mmi_asc_to_ucs2(ucs2Num,g_kjx_nvram_struct.listenNum);

	MakeCall(ucs2Num);
}

S32 kjx_socket_send_data_all(void)
{
	S32 result = 0;
	U16 mustSend = 0;
	int i = 0;
	applib_time_struct currTime;

#ifdef FUNCTION_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	for(i=0;i<SERVER_TYPE_MAX;i++)
	{
		if(g_kjx_nvram_struct.updateStatus[i])
		{
		#ifdef FUNCTION_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("i:%d", i);
		#endif
		#endif
		
			mustSend=1;
			break;
		}
	}

	if(!mustSend)
		return 0;
	
	result = kjx_gprs_set_send_data();
	if(result>0)
	{
		applib_dt_get_rtc_time(&currTime);
		memset(&lastSendTime, 0, sizeof(applib_time_struct));
		memcpy(&lastSendTime,&currTime,sizeof(applib_time_struct));

		if(g_kjx_socket_context.socket_id >= 0)
		{
			result = g_kjx_socket_event_func.socket_event_send(g_kjx_socket_context.socket_id,g_kjx_socket_context.pSendBuff,result);
		#ifdef FUNCTION_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("result:%d", result);
		#endif
		#endif
	
			if(result>0)
			{
				for(i=0;i<SERVER_TYPE_MAX;i++)
				{
					g_kjx_nvram_struct.updateStatus[i] = 0;
					g_kjx_nvram_struct.service_to_tracer[i] = FALSE;
				}
			}

			return result;
		}
		else
		{
		#ifdef FUNCTION_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("socket is closed! socket_id:%d", g_kjx_socket_context.socket_id);
		#endif
		#endif
			return 0;
		}
	}

	return 0;
}


void kjx_sos_send_gps_data(void)
{/*发送当前位置到亲情号码上*/
	StopTimer(KJX_TIMER_ID_SOS_CALL);
	
	g_kjx_nvram_struct.workMode = 0;//紧急模式

	if(kjx_gps_is_valid())
		g_kjx_nvram_struct.updateStatus[SERVER_TYPE_03]=1;
	else
		g_kjx_nvram_struct.updateStatus[SERVER_TYPE_84]=1;
	
	g_kjx_nvram_struct.updateStatus[SERVER_TYPE_25]=1;

#ifdef FUNCTION_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("socketConnet:%d, in_call:%d, workmode:%d", socketConnet, kjx_is_in_call(), g_kjx_nvram_struct.workMode);
#endif
#endif

	if(((kjx_is_in_call())||(!socketConnet))/*&&(g_kjx_nvram_struct.workMode != 2)*/)
	{
		StartTimer(KJX_TIMER_ID_SOS_CALL,1000*10, kjx_sos_send_gps_data);

	#ifdef FUNCTION_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("socketConnet=%d,in_call=%d", socketConnet, kjx_is_in_call());
	#endif
	#endif
	
		if((!socketConnet)&&(!kjx_is_in_call()))
		{
			if(!IsMyTimerExist(KJX_TIMER_ID_IS_CONNET)&&!IsMyTimerExist(KJX_TIMER_ID_LOGIN_AGAIN))
			{
				kjx_tour_socket_timeout();
			}
		}
		
		return;
	}
	
	g_kjx_socket_event_func.socket_send_gps();

	StartTimer(KJX_TIMER_ID_GET_ADDRESS,1000*5, kjx_sos_get_address);
}

void kjx_sos_get_address(void)
{
	applib_time_struct currTime;

	StopTimer(KJX_TIMER_ID_GET_ADDRESS);

#ifdef FUNCTION_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	applib_dt_get_rtc_time(&currTime);

#ifdef FUNCTION_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("ABS(currTime.nMin-lastSendTime.nMin)=%d", ABS(currTime.nMin-lastSendTime.nMin));
#endif
#endif

	if(ABS(currTime.nSec-lastSendTime.nSec)<2)
	{
	#ifdef FUNCTION_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("KJX_TIMER_ID_GET_ADDRESS");
	#endif
	#endif
	
		StartTimer(KJX_TIMER_ID_GET_ADDRESS,2000,kjx_sos_get_address);
		return;
	}

	g_kjx_nvram_struct.updateStatus[SERVER_TYPE_31] = 1;
	kjx_socket_send_data_all();
}

S32 kjx_socket_send_data_with_type(kjx_socket_type socket_type)
{
	S32 result = 0;
	int i = 0;
	applib_time_struct currTime;

#ifdef FUNCTION_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("socket_type:%d", socket_type);
#endif
#endif
	
	if(!g_kjx_nvram_struct.dataIsSync)
	{
		g_kjx_nvram_struct.updateStatus[SERVER_TYPE_30] = 1;
	}
	
#if defined(CUSTOMER_NAME_TOUR)
	if(!powerDataIsSync)
	{
		g_kjx_nvram_struct.updateStatus[SERVER_TYPE_30] = 1;
	}
#endif
	
	g_kjx_nvram_struct.updateStatus[socket_type] = 1;
	result = kjx_gprs_set_send_data();
	if(result>0)
	{
		applib_dt_get_rtc_time(&currTime);
		memset(&lastSendTime, 0, sizeof(applib_time_struct));
		memcpy(&lastSendTime,&currTime,sizeof(applib_time_struct));

		if(g_kjx_socket_context.socket_id >= 0)
		{
			result = g_kjx_socket_event_func.socket_event_send(g_kjx_socket_context.socket_id,g_kjx_socket_context.pSendBuff,result);
		#ifdef FUNCTION_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("result:%d", result);
		#endif
		#endif
		
			if(result>0)
			{
				for(i=0;i<SERVER_TYPE_MAX;i++)
				{
					g_kjx_nvram_struct.updateStatus[i] = 0;
					g_kjx_nvram_struct.service_to_tracer[i] = FALSE;
				}

				if(socket_type == SERVER_TYPE_01)
				{
					if(heartbeat_need_send > 0)
						heartbeat_need_send--;
				}

				if((socket_type == SERVER_TYPE_70)
				#if defined(__KJX_POSITION_TRIGGER_PLAY__)
					|| (socket_type == SERVER_TYPE_72)
				#endif
					)
				{
					rfid_need_send = 0;
				}
			}
			else
			{
				if(socket_type == SERVER_TYPE_01)
				{
					heartbeat_need_send++;
				}

				if((socket_type == SERVER_TYPE_70)
				#if defined(__KJX_POSITION_TRIGGER_PLAY__)
					|| (socket_type == SERVER_TYPE_72)
				#endif
					)
				{
					rfid_need_send = 1;
				}
			}
			return result;
		}
		else
		{
		#ifdef FUNCTION_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("socket is closed! socket_id:%d", g_kjx_socket_context.socket_id);
		#endif
		#endif
		
			return 0;
		}
	}

	return 0;
}

void kjx_get_data_init(void)
{
	g_kjx_nvram_struct.updateStatus[SERVER_TYPE_30] = 1;
	kjx_socket_send_data_all();
}

void kjx_set_sensor_value(void)
{
	SENSOR_MAX_DATA = g_kjx_nvram_struct.sensorValue;
}

BOOL kjx_get_service_data_total(kjx_socket_type socket_type,U16 subTotal,U16 signIndex)
{
	BOOL reTotal = TRUE;

#if 1	//xb add 2017-12-14
	g_kjx_nvram_struct.service_to_tracer[socket_type] = TRUE;
#else

	if((socket_type==SERVER_TYPE_55)||(socket_type==SERVER_TYPE_04)||(socket_type==SERVER_TYPE_68))
	{
		g_kjx_nvram_struct.service_to_tracer[socket_type] = TRUE;
		return reTotal;
	}

	if((g_kjx_subTotal[socket_type].tracer_to_service==subTotal)&&(signIndex==1))
	{
		g_kjx_nvram_struct.service_to_tracer[socket_type] = TRUE;
	}
	else if((g_kjx_subTotal[socket_type].service_to_tracer==subTotal)&&(signIndex==2))
	{
		g_kjx_nvram_struct.service_to_tracer[socket_type] = TRUE;
	}
	else
	{
		reTotal = FALSE;
	}
#endif

	return reTotal;
}

void kjx_gprs_check_recvbuf_data(U8 *databuf)
{
	U8 parseBuf[512];
	U8 tatol=0,strLen=0;
	int i=0,j=0,lenght=0,datalen=0;
	U8* temString=NULL;
	U8* tem2String=NULL;
	extern U8 kjxIccid[64];

#ifdef FUNCTION_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("databuf=%s", databuf);
#endif
#endif

	if(IsMyTimerExist(KJX_TIMER_ID_IS_CONNET))
		StopTimer(KJX_TIMER_ID_IS_CONNET);
	if(IsMyTimerExist(KJX_TIMER_ID_LOGIN_AGAIN))
		StopTimer(KJX_TIMER_ID_LOGIN_AGAIN);

	/*更新GPRS状态图标*/
	wgui_status_icon_bar_reset_icon_display(STATUS_ICON_GPRS_UNLINK);
	wgui_status_icon_bar_set_icon_display(STATUS_ICON_GPRS_LINK);
	wgui_status_icon_bar_update();

	if(!strstr(databuf,"KJX\0"))
	{
		return;
	}

	temString = strstr(databuf,"{\0");
	if(temString)
	{
		strLen = temString-databuf-strlen("KJX\0");
	}
	memset(parseBuf, 0x00, sizeof(parseBuf));
	memcpy(parseBuf, databuf+strlen("KJX\0"),strLen);
	tatol = atoi(parseBuf);

#ifdef FUNCTION_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("tatol:%d", tatol);
#endif
#endif

	if(tatol<=0)
	{
		return;
	}

	if(!socketConnet)
	{
		g_ReconnetCount = 0;
		socketConnet = TRUE;

		if(!IsMyTimerExist(KJX_TIMER_ID_HEART_BEAT))
			StartTimer(KJX_TIMER_ID_HEART_BEAT, 3*1000, kjx_tour_socket_send_heartbeat);
	#if defined(CUSTOMER_NAME_MEGE2)
		if(!isLfashConnet)
		{
			isLfashConnet = TRUE;
		#if defined(__MEGE_LED_LIGHT__)
			LED_all_light();
		#endif
		}
	#endif
	}

	if(!g_kjx_nvram_struct.dataIsSync)
	{
		g_kjx_nvram_struct.dataIsSync = TRUE;
	#if defined(CUSTOMER_NAME_MEGE2)
		if(!strlen(kjxIccid))
			kjx_get_iccid();

		kjx_send_sms_to_my_phone();
	#endif
	}
	
#if defined(CUSTOMER_NAME_TOUR)
	if(!powerDataIsSync)
	{
		powerDataIsSync = TRUE;
	}
#endif

	temString=NULL;
	temString = strstr(databuf,"C31#\0");
	if(temString && (temString == databuf+6))
	{ 
		//地址数据
	#ifdef FUNCTION_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("地址数据 len:%d",mmi_ucs2strlen(temString));
	#endif
	#endif
		memset(kjxAddress, 0x00, sizeof(kjxAddress));
		memcpy(kjxAddress, temString+strlen("C31#\0"), sizeof(kjxAddress));
		kjx_send_address_to_sos();

		g_kjx_nvram_struct.updateStatus[SERVER_TYPE_31] = 1;
		g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_31] = TRUE;
		kjx_socket_send_data_all();
		return;
	}

#if defined(CUSTOMER_NAME_TOUR)
	temString=NULL;
	temString = strstr(databuf,"D13#\0");
	if(temString && (temString == databuf+6))
	{ 
		//语音推送
		extern S8 kjxPlayTts[512];
		extern U16 TTsPlayRepeat;
		extern BOOL kjx_tts_play_is_stop;
		extern void kjx_voice_push_and_play(void);

	#ifdef FUNCTION_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("语音推送 len:%d",  strlen(temString));
	#endif
	#endif
		memset(kjxPlayTts, 0x00, sizeof(kjxPlayTts));
		memcpy(kjxPlayTts, temString+strlen("D13#\0"), sizeof(kjxPlayTts));
		for(i=0;i<strlen(kjxPlayTts);i++)
		{
			if(kjxPlayTts[i]=='>')
			{
				kjxPlayTts[i]='\0';
				break;
			}
		}

		kjx_tts_play_is_stop = FALSE;
		TTsPlayRepeat = 3;

		kjx_voice_push_and_play();
		
		g_kjx_nvram_struct.updateStatus[SERVER_TYPE_13] = 1;
		kjx_socket_send_data_all();

		return;
	}
#elif defined(CUSTOMER_NAME_OLDMAN)
	temString=NULL;
	temString = strstr(databuf,"D13#\0");
	if(temString && (temString == databuf+6))
	{	 
		//语音推送
		extern void kjx_oldman_show_push_string(void);
		extern S8 kjxPlayTts[512];

	#ifdef FUNCTION_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("语音推送 len:%d",  strlen(temString));
	#endif
	#endif
		memset(kjxPlayTts, 0x00, sizeof(kjxPlayTts));
		memcpy(kjxPlayTts, temString+strlen("D13#\0"), sizeof(kjxPlayTts));
		for(i=0;i<strlen(kjxPlayTts);i++)
		{
			if(kjxPlayTts[i]=='>')
			{
				kjxPlayTts[i]='\0';
				break;
			}
		}

		kjx_oldman_show_push_string();
		g_kjx_nvram_struct.updateStatus[SERVER_TYPE_13] = 1;
		kjx_socket_send_data_all();

		return;
	}
#endif

	temString=NULL;
	temString = strstr(databuf,"D70#\0");
	if(temString && (temString == databuf+6))
	{ 
		//景点介绍
		char rfid_id_buf[32] = {0};
		U32 rfid_id_tmp = 0;
		extern U8 kjx_audio_status;
		extern UI_string_type kjx_scrolling_show[512];
		extern void mmi_show_scrolling_infor(void);
		extern S32 g_rfid_played_id;

	#ifdef FUNCTION_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("RFID景点介绍 len:%d", strlen(temString));
	#endif
	#endif

		memset(kjxTourShow, 0x00, sizeof(kjxTourShow));
		memcpy(kjxTourShow, temString+strlen("D70#\0"), sizeof(kjxTourShow));
		for(i=0;i<strlen(kjxTourShow);i++)
		{
			if(kjxTourShow[i]=='>')
			{
				kjxTourShow[i]='\0';
				break;
			}
		}

		temString = (U8*)kjxTourShow;
		tem2String = strstr(temString, ",");
		if(tem2String)
		{
			memcpy(rfid_id_buf, temString, tem2String-temString);

		#ifdef FUNCTION_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("rfid_id_buf:%s", rfid_id_buf);
		#endif
		#endif
		
			rfid_id_tmp = atoi(rfid_id_buf);
			if(rfid_id_tmp <= 0)
				return;

			tem2String += strlen(",");
			strcpy(kjxTourShow, tem2String);
		}
		
	#if defined(__KJX_OLED_64_48_UI__)
		memset(kjxTourInfor, 0, sizeof(kjxTourInfor));
		mmi_chset_utf8_to_ucs2_string((kal_uint8 *)kjxTourInfor, sizeof(kjxTourInfor), kjxTourShow);

	#ifdef __KJX_TOUR_NAME_STORE_CARD__
		if(mmi_ucs2strlen((CHAR*)kjxTourInfor) > 0)
		{
			kjx_update_tour_name_infor(rfid_id_tmp, (char*)kjxTourInfor);
		}
	#endif

	#ifdef FUNCTION_DEBUG
	 #ifdef __KJX_RFID_LOCATION__
      #if defined(__KJX_LOG_OUTPUT__)
		LOGD("kjx_rfid_id:%d, rfid_id_tmp:%d", kjx_rfid_id%1000000, rfid_id_tmp%1000000);
      #endif
     #else
      #if defined(__KJX_LOG_OUTPUT__)
		LOGD("kjx_rfid_id:%d, rfid_id_tmp:%d", kjx_rfid_id, rfid_id_tmp);
      #endif
     #endif
    #endif
	
		if((kjx_audio_status == 1 || kjx_audio_status == 2) && (mmi_ucs2strlen((CHAR*)kjxTourInfor) > 0) && !is_call()&&(kjx_get_foctory_test_mode() == 0)
			#ifdef __KJX_RFID_LOCATION__
				&& ((kjx_rfid_id%1000000) == (rfid_id_tmp%1000000)) 
			#else
				&& (kjx_rfid_id == rfid_id_tmp) 
			#endif
			)
		{
			if(rfid_id_tmp == g_rfid_played_id)
			{
				memset(kjx_scrolling_show, 0, sizeof(kjx_scrolling_show));
				mmi_ucs2cpy((CHAR*)kjx_scrolling_show, (CHAR*)kjxTourInfor);
				mmi_show_scrolling_infor();
			}
		}
	#endif/*__KJX_OLED_64_48_UI__*/

		g_kjx_nvram_struct.updateStatus[SERVER_TYPE_70] = 1;
		g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_70] = TRUE;
		kjx_socket_send_data_all();

		return;
	}

#if defined(__KJX_POSITION_TRIGGER_PLAY__)
	temString=NULL;
	temString = strstr(databuf,"D72#\0");
	if(temString && (temString == databuf+6))
	{
		//景点介绍
		char rfid_id_buf[32] = {0};
		U32 rfid_id_tmp = 0;
		extern U8 kjx_audio_status;
		extern UI_string_type kjx_scrolling_show[512];
		extern void mmi_show_scrolling_infor(void);

	#ifdef FUNCTION_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("位置景点介绍 len:%d", strlen(temString));
	#endif
	#endif

		memset(kjxTourShow, 0x00, sizeof(kjxTourShow));
		memcpy(kjxTourShow, temString+strlen("D72#\0"), sizeof(kjxTourShow));
		for(i=0;i<strlen(kjxTourShow);i++)
		{
			if(kjxTourShow[i]=='>')
			{
				kjxTourShow[i]='\0';
				break;
			}
		}

		temString = (U8*)kjxTourShow;
		tem2String = strstr(temString, ",");
		if(tem2String)
		{
			memcpy(rfid_id_buf, temString, tem2String-temString);
		#ifdef FUNCTION_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("rfid_id_buf:%s", rfid_id_buf);
		#endif
		#endif
			rfid_id_tmp = atoi(rfid_id_buf);
			if(rfid_id_tmp <= 0)
				return;

			tem2String += strlen(",");
			strcpy(kjxTourShow, tem2String);
		}
		
	#if defined(__KJX_OLED_64_48_UI__)
		memset(kjxTourInfor, 0, sizeof(kjxTourInfor));
		mmi_chset_utf8_to_ucs2_string((kal_uint8 *)kjxTourInfor, sizeof(kjxTourInfor), kjxTourShow);

	#ifdef __KJX_TOUR_NAME_STORE_CARD__
		if(mmi_ucs2strlen((CHAR*)kjxTourInfor) > 0)
		{
			kjx_update_tour_name_infor(rfid_id_tmp, (char*)kjxTourInfor);
		}
	#endif

	#ifdef FUNCTION_DEBUG
	 #ifdef __KJX_RFID_LOCATION__
	  #if defined(__KJX_LOG_OUTPUT__)
		LOGD("kjx_rfid_id:%d, rfid_id_tmp:%d", kjx_rfid_id%1000000, rfid_id_tmp%1000000);
	  #endif
	 #else
	  #if defined(__KJX_LOG_OUTPUT__)
		LOGD("kjx_rfid_id:%d, rfid_id_tmp:%d", kjx_rfid_id, rfid_id_tmp);
	  #endif
	 #endif
	#endif

		if((kjx_audio_status == 1 || kjx_audio_status == 2) && (mmi_ucs2strlen((CHAR*)kjxTourInfor) > 0) && !is_call()&&(kjx_get_foctory_test_mode() == 0)
			#ifdef __KJX_RFID_LOCATION__
				&& ((kjx_rfid_id%1000000) == (rfid_id_tmp%1000000)) 
			#else
				&& (kjx_rfid_id == rfid_id_tmp) 
			#endif
			)
		{
			memset(kjx_scrolling_show, 0, sizeof(kjx_scrolling_show));
			mmi_ucs2cpy((CHAR*)kjx_scrolling_show, (CHAR*)kjxTourInfor);
			mmi_show_scrolling_infor();
		}
	#endif/*__KJX_OLED_64_48_UI__*/

		g_kjx_nvram_struct.updateStatus[SERVER_TYPE_72] = 1;
		g_kjx_nvram_struct.service_to_tracer[SERVER_TYPE_72] = TRUE;
		kjx_socket_send_data_all();

		return;
	}
#endif

#ifdef __KJX_FUN_AGPS__
#ifdef __KJX_FUN_GPS_ZKW__
	temString=NULL;
	temString = strstr(databuf,"D83#\0");
	if(temString && (temString == databuf+6))
	{
		//星历数据
		U8 *ptr,*p1,*p2;
		U32 datalen;
		U8 tmpbuf[50] = {0};

	#ifdef FUNCTION_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("中科微星历数据");
	#endif
	#endif
		//AGNSS data from CASIC
		//DataLength: 2582
		//Limitation: 1/1000

		if(g_kjx_agps_recving == 0)
		{
			g_kjx_agps_recving = 1;

			memset(g_kjx_agps_valid_time, 0, sizeof(g_kjx_agps_valid_time));
			memcpy(g_kjx_agps_valid_time, temString+strlen("D83#"), 14);//20180308121314
		#ifdef FUNCTION_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("有效截止时间:%s", g_kjx_agps_valid_time);
		#endif
		#endif
		
			ptr = strstr(temString, "AGNSS data from CASIC");
			if(ptr != NULL)
			{
				p1 = strstr(ptr, "DataLength: ");
				if(p1 == NULL)
				{
				#ifdef FUNCTION_DEBUG
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("未找到 DataLength: ");
				#endif
				#endif
					g_kjx_agps_date_len = 0;
					g_kjx_agps_data_recvd = 0;
					g_kjx_agps_used = 0;
					g_kjx_agps_recving = 0;
					return;
				}
				
				p1 = p1+strlen("DataLength: ");
				p2 = strstr(p1, ".\n");
				if(p2 == NULL)
				{
				#ifdef FUNCTION_DEBUG
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("未找到 .\n");
				#endif
				#endif
					g_kjx_agps_date_len = 0;
					g_kjx_agps_data_recvd = 0;
					g_kjx_agps_used = 0;
					g_kjx_agps_recving = 0;
					return;
				}
				
				memcpy(tmpbuf, p1, p2-p1);
				g_kjx_agps_date_len = atoi(tmpbuf);

				p2 += 2;
				p1 = strstr(p2, "Limitation: ");
				if(p1 == NULL)
				{
				#ifdef FUNCTION_DEBUG
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("未找到 Limitation: ");
				#endif
				#endif
					g_kjx_agps_date_len = 0;
					g_kjx_agps_data_recvd = 0;
					g_kjx_agps_used = 0;
					g_kjx_agps_recving = 0;
					return;
				}

				p1 = p1+strlen("Limitation: ");
				p2 = strstr(p1, ".\n");
				if(p2 == NULL)
				{
				#ifdef FUNCTION_DEBUG
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("未找到 .\n");
				#endif
				#endif
					g_kjx_agps_date_len = 0;
					g_kjx_agps_data_recvd = 0;
					g_kjx_agps_used = 0;
					g_kjx_agps_recving = 0;
					return;
				}

				p2 += 2;

				datalen = g_kjx_socket_context.totalSize - (p2 - g_kjx_socket_context.pRecvBuff);
				datalen = datalen<g_kjx_agps_date_len ? datalen : g_kjx_agps_date_len;
				g_kjx_agps_data_recvd = datalen;

			#ifdef FUNCTION_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("星历数据长度:%d, 本次接收长度:%d", g_kjx_agps_date_len, g_kjx_agps_data_recvd);
			#endif
			#endif

				memset(g_kjx_agps_buffer, 0x00, KJX_AGPS_DATA_MAX_LEN);
				memcpy(g_kjx_agps_buffer, p2, g_kjx_agps_data_recvd);

				kjx_agps_data_write_to_file(p2, g_kjx_agps_data_recvd, TRUE);

				if(g_kjx_agps_data_recvd == g_kjx_agps_date_len)
				{
					kjx_agps_start_push_data_to_mode(g_kjx_agps_buffer, g_kjx_agps_data_recvd);

					g_kjx_agps_used = 0;
					g_kjx_agps_recving = 0;
				}
			}
			else
			{
			#ifdef FUNCTION_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("未找到 AGNSS data from CASIC");
			#endif
			#endif
				g_kjx_agps_date_len = 0;
				g_kjx_agps_data_recvd = 0;
				g_kjx_agps_used = 0;
				g_kjx_agps_recving = 0;
				return;
			}
		}
		return;
	}
#endif

#ifdef __KJX_FUN_GPS_HD__
	temString = NULL;
	temString = strstr(databuf,"D85#\0");
	if(temString && (temString == databuf+6))
	{
		//星历数据
		U8 *ptr,*p1,*p2;
		U32 datalen = 0;
		U8 tmpbuf[50] = {0};
		U8 float_len = 0;

	#ifdef FUNCTION_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("华大星历数据");
	#endif
	#endif

		if(g_kjx_agps_recving == 0)
		{
			g_kjx_agps_recving = 1;

			g_kjx_HD_agps_lon = 0;
			g_kjx_HD_agps_lat = 0;
			g_kjx_agps_date_len = 0;
			memset(g_kjx_agps_valid_time, 0, sizeof(g_kjx_agps_valid_time));

			//经度
			ptr = temString+4;
			p2 = strstr(ptr, ",");
			if(p2 == NULL)
			{
			#ifdef FUNCTION_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("未找到经度");
			#endif
			#endif
				g_kjx_agps_date_len = 0;
				g_kjx_agps_data_recvd = 0;
				g_kjx_agps_used = 0;
				g_kjx_agps_recving = 0;
				g_kjx_HD_agps_lon = 0;
				g_kjx_HD_agps_lat = 0;
				return;
			}
			memcpy(tmpbuf, ptr, p2-ptr);
			g_kjx_HD_agps_lon = g_kjx_gps_func.gps_data_into_number(tmpbuf, strlen(tmpbuf), &float_len);
			if(float_len > 6)
				float_len = 6;
			g_kjx_HD_agps_lon = g_kjx_HD_agps_lon/pow(10,float_len);
		#ifdef FUNCTION_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("g_kjx_HD_agps_lon:%f", g_kjx_HD_agps_lon);
		#endif
		#endif

			//纬度
			p1 = p2 + 1;
			p2 = strstr(p1, ",");
			if(p2 == NULL)
			{
			#ifdef FUNCTION_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("未找到纬度");
			#endif
			#endif
				g_kjx_agps_date_len = 0;
				g_kjx_agps_data_recvd = 0;
				g_kjx_agps_used = 0;
				g_kjx_agps_recving = 0;
				g_kjx_HD_agps_lon = 0;
				g_kjx_HD_agps_lat = 0;
				return;
			}
			memset(tmpbuf, 0x00, sizeof(tmpbuf));
			memcpy(tmpbuf, p1, p2-p1);
			g_kjx_HD_agps_lat = g_kjx_gps_func.gps_data_into_number(tmpbuf, strlen(tmpbuf), &float_len);
			if(float_len > 6)
				float_len = 6;
			g_kjx_HD_agps_lat = g_kjx_HD_agps_lat/pow(10,float_len);
		#ifdef FUNCTION_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("g_kjx_HD_agps_lat:%f", g_kjx_HD_agps_lat);
		#endif
		#endif

			//有效时间
			p1 = p2 + 1;
			memcpy(g_kjx_agps_valid_time, p1, 14);//20180308121314
		#ifdef FUNCTION_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("有效截止时间:%s", g_kjx_agps_valid_time);
		#endif
		#endif

			//星历数据长度
			p1 += 15;//时间后面还有个逗号
			p2 = strstr(p1, ",");
			if(p2 == NULL)
			{
			#ifdef FUNCTION_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("未找到星历长度");
			#endif
			#endif
				g_kjx_agps_date_len = 0;
				g_kjx_agps_data_recvd = 0;
				g_kjx_agps_used = 0;
				g_kjx_agps_recving = 0;
				g_kjx_HD_agps_lon = 0;
				g_kjx_HD_agps_lat = 0;
				return;
			}
			memset(tmpbuf, 0x00, sizeof(tmpbuf));
			memcpy(tmpbuf, p1, p2-p1);
			g_kjx_agps_date_len = atoi(tmpbuf);
		#ifdef FUNCTION_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("星历数据长度:%d", g_kjx_agps_date_len);
		#endif
		#endif

			//星历数据
			p2 += 1;//长度后面也有个逗号
			datalen = g_kjx_socket_context.totalSize - (p2 - g_kjx_socket_context.pRecvBuff);
			datalen = datalen<g_kjx_agps_date_len ? datalen : g_kjx_agps_date_len;
			g_kjx_agps_data_recvd = datalen;
		#ifdef FUNCTION_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("星历数据长度:%d, 本次接收长度:%d", g_kjx_agps_date_len, g_kjx_agps_data_recvd);
		#endif
		#endif

			memset(g_kjx_agps_buffer, 0x00, KJX_AGPS_DATA_MAX_LEN);
			memcpy(g_kjx_agps_buffer, p2, g_kjx_agps_data_recvd);
			kjx_agps_data_write_to_file(p2, g_kjx_agps_data_recvd, TRUE);
			if(g_kjx_agps_data_recvd == g_kjx_agps_date_len)
			{
				kjx_hd_agps_begin();
				g_kjx_agps_recving = 0;
			}
		}
		return;
	}
#endif/*__KJX_FUN_GPS_HD__*/

#endif

	for(i=0;i<tatol;i++)
	{	
		temString=NULL;
		temString=kjx_get_parameter_string_extern(databuf,"{","}","<",">",i+1);
		kjx_do_with_service_data(temString);
	}

	kjx_nvram_write();
	kjx_socket_send_data_all();
}

void kjx_resrecv_buf_handle(void)
{
	if(recv_pstr1)
	{
		kjx_gprs_check_recvbuf_data(recv_pstr1);
		recv_pstr2 = recv_pstr1 + strlen("KJX\0");
		recv_pstr1 = strstr(recv_pstr2,"KJX\0");

		StartTimer(KJX_TIMER_ID_SOCKET_RECEIVE_DELAY, 100, kjx_resrecv_buf_handle);
	}
	else
	{
	}
}

void kjx_gprs_recvbuf_parse(kal_int32 len)
{
	U32 datalen;
#ifdef FUNCTION_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("pRecvBuff=%s", g_kjx_socket_context.pRecvBuff);
#endif
#endif

#ifdef __KJX_FUN_AGPS__
	if(g_kjx_agps_recving == 1)
	{
	#ifdef FUNCTION_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("正在接收AGPS分包数据,星历长度:%d, 已经接收:%d, 本次接收:%d", g_kjx_agps_date_len, g_kjx_agps_data_recvd, g_kjx_socket_context.totalSize);
	#endif
	#endif

		datalen = (g_kjx_socket_context.totalSize<(g_kjx_agps_date_len - g_kjx_agps_data_recvd)) ? g_kjx_socket_context.totalSize : (g_kjx_agps_date_len-g_kjx_agps_data_recvd);
	#ifdef FUNCTION_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("实际有效数据:%d", datalen);
	#endif
	#endif
		if(datalen > 0)
		{
			memcpy(g_kjx_agps_buffer+g_kjx_agps_data_recvd, g_kjx_socket_context.pRecvBuff, datalen);

			kjx_agps_data_write_to_file(g_kjx_socket_context.pRecvBuff, datalen, FALSE);

			g_kjx_agps_data_recvd += datalen;
			if(g_kjx_agps_data_recvd >= g_kjx_agps_date_len)
			{
				switch(g_kjx_gps_category)
				{
				case GPS_ZKW_MODE:
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("中科微模块，直接灌星!");
				#endif
		
					kjx_agps_start_push_data_to_mode(g_kjx_agps_buffer, g_kjx_agps_data_recvd);
					g_kjx_agps_used = 0;
					break;
					
			#ifdef __KJX_FUN_GPS_HD__
				case GPS_HD_MODE:
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("华大模块，启动指令!");
				#endif

					kjx_hd_agps_begin();
					break;
			#endif
				}
			
				g_kjx_agps_recving = 0;
			}
		}
		else
		{
			g_kjx_agps_recving = 0;
		}
	}
#endif

	recv_pstr1 = strstr(g_kjx_socket_context.pRecvBuff,"KJX\0");
	kjx_resrecv_buf_handle();
}

#endif
