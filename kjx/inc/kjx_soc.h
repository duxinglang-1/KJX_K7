/*****************************************************************************
 *
 * Filename:  	Tracker_SOC.h
 *
 *
 * Author :    	Guojie
 *
 *
 * Date : 	2012-05-31
 *
 *
 * Comment:  soc连接
 *
 *
 ****************************************************************************/
#if defined(__KJX_SOC_APP__)

#ifndef __SOC_APP_H__
#define __SOC_APP_H__

/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "stack_ltlcom.h"
#include "soc_api.h"
#include "EngineerModeSocketDemoApp.h"
#include "Common_nvram_editor_data_item.h"
#include "DataAccountDef.h"

/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
//#define __Tracker_SOC_DEBUG__

#if defined(__SPECIAL_EPO_SOCKET__)||defined(__SPECIAL_AGPS_SOCKET__)
#define SIGLELEN_SOC_MAX 512     //地址回复包算是长
#define PACKET_SOC_MAX 3            //解析支持最大3包拼合
#else
#define SIGLELEN_SOC_MAX 1100   //SOC单包接收长度>1034 AGPS包
#define PACKET_SOC_MAX 3            //解析支持最大3包拼合
#endif


/*****************************************************************************
* Typedef  Enum
*****************************************************************************/
#if defined(__NEW_PROTOCOL__)

typedef enum
{
    GPRS_LOGIN_INFO,
	GPRS_STATUS_INFO,
	GPRS_ANALOG_INPUT_INFO,
	GPRS_DIGITAL_INPUT_INFO,
	GPRS_ADJUSTTIME_INFO,
	GPRS_LBS_GETLATLON_INFO,
#if defined(__GPS_ON_MTK__)
    GPRS_GPS_INFO,
    GPRS_GPS_LBS_INFO,
    GPRS_GPS_LBS_STATUS_INFO,
    GPRS_GPS_PHB_INFO,
#endif/*__GPS_ON_MTK__*/    
    GPRS_LBS_INFO,
#if defined(__MULTI_CELLID__)||defined(__NBR_CELL_INFO__)
    GPRS_LBSEXPAND_INFO,
#endif /* __MULTI_CELLID__ */    
    GPRS_LBS_STATUS_INFO,
    GPRS_LBS_PHB_INFO,
#if defined(__AGPS_EPO_SUPPORT__)
    GPRS_PASS_AGPS_INFO,
#endif
#if defined(__FUEL_SENSOR__)
    GPRS_FUEL_SENSOR_INFO,
#endif
#if defined(__CAR_OBD__)
    GPRS_OBD_REALTIME_INFO,
    GPRS_OBD_MILEAGE_INFO,
    GPRS_OBD_TROUBLE_INFO,
    GPRS_OBD_ONLINE_REALTIME_INFO,
    GPRS_OBD_ONLINE_MILEAGE_INFO,
    GPRS_OBD_ONLINE_TROUBLE_INFO,
#endif
#ifdef __ONLINE_CMD_NORMAL_REPLY__
	GPRS_ONLINE_ASCII_DATA_REPLY,  //ASCII数据回复平台的查询
	GPRS_ONLINE_UNICODE_DATA_REPLY, //UNICODE数据回复平台的查询
	GPRS_ONLINE_ASCII_DATA_REPLY_EX,  //ASCII数据回复平台的查询
	GPRS_ONLINE_UNICODE_DATA_REPLY_EX,	//UNICODE数据回复平台的查询
#endif
    GPRS_ONLINE_RESULT_INFO,
    GPRS_ONLINE_SEESOS_INFO,
    GPRS_ONLINE_SEEPARAM_INFO,
    GPRS_ONLINE_SEETIME_INFO,
    
    GPRS_SEND_MAX_INFO
} GPRS_SEND_INFO_TYPE;

#elif defined(__OLD_PROTOCOL__)

typedef enum
{
    GPRS_GETIP_INFO,
    GPRS_STATUS_INFO,
    GPRS_ABNORMAL_STATUS_INFO,
    GPRS_GPS_LBS_INFO,
    GPRS_GPS_PHB_INFO,
    GPRS_ONLINE_RESULT_INFO,
    GPRS_SEND_MAX_INFO
} GPRS_SEND_INFO_TYPE;

#endif


extern GPRS_SEND_INFO_TYPE  gprs_send_type;


typedef enum
{
    REC_LENZERO_ERROR,   //接收数据长度为0
    REC_LEN_ERROR,      //长度不对接收长度和数据包里长度不对应
    REC_END_ERROR,  //尾错
    REC_HEAD_ERROR,   //头错
    REC_CRC_ERROR,    //CRC错误
    REC_SUCCESS,         //接收数据正确
    REC_TYPE_MAX
} TRACKER_RECERROR_TYPE;


#if defined(__NEW_PROTOCOL__)

typedef enum
{
    TRACKER_LOGIN_REPLY,   //登陆回复包
    TRACKER_LBS_REPLY,    //LBS回复包
    TRACKER_LBS_EXPAND_REPLY,    //LBS扩展回复包
    TRACKER_STATUS_REPLY,  //状态回复包
    TRACKER_ADJUSTTIME_REPLY,  //时间校准
    TRACKER_ONLINECOM_SET,     //在线指令设置
    TRACKER_ONLINECOM_QUERY,  //在线指令查询
    TRACKER_GETCHADRESS_REPLY,  //获取中文地址回复
    TRACKER_GETENADRESS_REPLY,  //获取英文地址回复
    TRACKER_FENCE_GETCHADRESS_REPLY,	//服务器直接下发电子围栏报警中文地址
    TRACKER_FENCE_GETENADRESS_REPLY,	//服务器直接下发电子围栏报警英文地址
#if defined(__GPS_ON_MTK__)
    TRACKER_GPS_REPLY,    //GPS回复包
#if defined(__AGPS_EPO_SUPPORT__)
    TRACKER_LATLON_REPLY,   //LBS获取经纬度回复
    TRACKER_EPOAGPS_REPLY,     //EPO文件获取回复
#endif
#endif
#if defined(__LOG_OUTPUT__)&&!defined(WIN32)
    TRACKER_LOG_OUTPUT,     //网络在线日志输出
#endif
    TRACKER_RECDATA_OTHER,  //其他包回复
    TRACKER_RECDATA_MAX
} TRACKER_RECDATA_TYPE;

#elif defined(__OLD_PROTOCOL__)
typedef enum
{
    TRACKER_STATUS_REPLY,  //状态回复包
    TRACKER_ABNORMAL_STATUS_REPLY,  //异常状态回复
    TRACKER_ONLINECOM_SET,     //在线指令设置
    TRACKER_GETCHADRESS_REPLY,  //获取中文地址回复
    TRACKER_GETENADRESS_REPLY,  //获取英文地址回复
    TRACKER_GETIP_REPLY,     //获取IP地址回复
#if defined(__LOG_OUTPUT__)&&!defined(WIN32)
    TRACKER_LOG_OUTPUT,     //网络在线日志输出
#endif
#if defined(__AGPS_EPO_SUPPORT__)
    TRACKER_LATLON_REPLY,   //LBS获取经纬度回复
    TRACKER_EPOAGPS_REPLY,     //EPO文件获取回复
#endif
    TRACKER_RECDATA_OTHER,  //其他包回复
    TRACKER_RECDATA_MAX
} TRACKER_RECDATA_TYPE;
#endif


/*****************************************************************************
 *  Struct					数据结构定义
 *****************************************************************************/
typedef enum
{
    SOC_NO_MEMORY = -3,
    SOC_CON_ERROR = -2,
    SOC_DNS_FAIL = -1,
    SOC_DNS_SUCCESS = 0, //0
    SOC_CON_SUCCESS = 1, //1
    SOC_CON_MAX
} mmi_soc_con_app_result;

typedef enum
{
    SOC_INVALID,
    SOC_STATE_CREATED,
    SOC_CONNECTED,
    SOC_SEND
} TRACKER_SOC_STATE_ENUM;

/* Structs */
typedef struct
{
    char host_name[DOMAIN_URL_MAX_LENGTH];    //DOMAIN_URL_MAX_LENGTH  100
    kal_int32 host_name_len;
    char url_link[DOMAIN_URL_MAX_LENGTH];          //DOMAIN_URL_MAX_LENGTH  100
    kal_int32 url_link_len;
    int ser_port_num;
} http_url_struct;


typedef enum
{
    SOCKET_CREATING,
    SOCKET_CREATED,
    SOCKET_CONNECTED,
    SOCKET_DNS_QUERY,
    SOCKET_HTTP_TCP_CREATING,
    SOCKET_HTTP_TCP_CREATED,
    SOCKET_SEND_RETRY,
    SOCKET_SENDING,
    SOCKET_SENT,
    SOCKET_RCVING,
    SOCKET_RCVD,
    SOCKET_CLOSING,
    SOCKET_CLOSED
} mmi_soc_state_enum;



typedef enum
{
    DNS_PARSE_IDLE,
    DNS_PARSE_START,
    DNS_PARSE_END,
    DNS_PARSE_MAX
} DNS_PARSE_STATUS;

extern DNS_PARSE_STATUS DNS_Parse_Status;


typedef struct
{
    kal_uint8 cbm_app_id;
    kal_uint32 nwt_account_id;
    kal_int8 soc_id;
    kal_uint8 soc_type;
    kal_uint8 connect_overtimes;                                        /*连接超时三次重启*/
    TRACKER_SOC_STATE_ENUM soc_state;
    sockaddr_struct soc_addr;
    char http_url[DOMAIN_URL_MAX_LENGTH];          //http_url[100];  100
    kal_uint8   http_url_len;
    http_url_struct url_parsed_info;

    mmi_soc_state_enum sendstate;                          /*队列发送*/
    kal_uint8 post_retry_counter;
    kal_char snd_buffer[MAX_SND_BUFFER_SIZE];
    kal_uint32 snd_data_len;
    kal_uint32 snd_counter;
} TRACKER_SOC_STRUCT;


typedef struct
{
    BOOL  Success;                                     /*登陆成功*/
    kal_uint8 sendtimes;                              /*登陆包发送次数*/
    BOOL  used_domain_login;			/* 使用域名登录*/
    kal_uint8	used_ip_login_fail_time;		/* 使用IP 登录失败次数*/
    kal_uint8	domain_index;				/* 域名ID  */
} TRACKER_LOGIN_INFO_STRUCT;


typedef struct
{
    U8 Content[PACKET_SOC_MAX*SIGLELEN_SOC_MAX];
    U16 ContLen;
} SOC_RECEIVE_DATA_STRUCT;


typedef struct
{
    LOCAL_PARA_HDR kal_char buffer[MAX_SND_BUFFER_SIZE];
    int len;
} gprs_socket_backup_req_struct;

/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/


/****************************************************************************
* Global Variable - Extern          全局变量
*****************************************************************************/
extern U16 gprs_inf_ind;
extern TRACKER_SOC_STRUCT soc_content;
extern TRACKER_LOGIN_INFO_STRUCT tracker_login_info;
extern SOC_RECEIVE_DATA_STRUCT Soc_Receive_Data;

extern BOOL AlreadyGetNetworkId;
/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/
void Tracker_Soc_Reset(void);
static void Tracker_Socket_ApnSet_Req(const char *mode, char* apn, PsFuncPtr functionAction);
static void Tracker_Socket_ApnSet_Rsp(void* info);
static void Tracker_socket_set_account_id(cbm_sim_id_enum sim_id);
static void Tracker_Socket_OutputResult(mmi_soc_con_app_result ret);
static void Tracker_Socket_Http_GetUrl(const kal_int8 *in_str, int str_len, http_url_struct * purl_parsed_info);
static void Tracker_Socket_DNS_GetHostByName_Ind(void *inMsg);
static void Tracker_Socket_DNS_GetHostByName(const kal_uint8 *hostname);
static void Tracker_Socket_DNS_Parse(void);
static void Tracker_Socket_TCP_Start(void);
static BOOL Tracker_Socket_TCP_Create(void);
static void Tracker_Socket_TCP_Connect(void);
static void Tracker_Socket_TCP_Receive(void);
static void Tracker_Socket_TCP_ReStart(void);

/*****************************************************************************
 *  Global Functions			全局函数
 *****************************************************************************/
extern BOOL Tracker_Socket_Register_Id_Get_NetworkId(void);
extern void Tracker_Socket_Notify(void * inMsg);
extern void Tracker_socket_APN_Set(void);
extern void Tracker_Socket_Initial(void);
extern void Tracker_Socket_TCP_Close(void);
extern void Tracker_Socket_TCP_ReConnect(void);
extern void Tracker_GPRS_Socket_Send_Req(U8* data, int len);
extern void Tracker_Socket_TCP_Close_ReConnect(void);
extern void Tracker_Socket_Notify_OverTime(void);
extern void Tracker_Socket_Check_Connect_Normal(void);
extern void Tracker_Socket_Set_GPRS_Detached(void);
extern void System_GetLatLon_Handle(void);
#endif   /*__SOC_APP__*/
#endif	/*__SOC_APP_H__ */


