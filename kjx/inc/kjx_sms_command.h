/*****************************************************************************
 *
 * Filename:  	Tracker_SMS_Command.h
 *
 *
 * Author :    	Guojie
 *
 *
 * Date : 	2011-09-15
 *
 *
 * Comment:  短信处理
 *
 *
 ****************************************************************************/
#ifndef __SMS_APP_H__
#define __SMS_APP_H__
/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "SmsSrvGprot.h"              //for srv_sms_event_new_sms_struct
#include "UcmSrvGprot.h"               //srv_ucm_incoming_call_ind_struct 
#include "App_str.h"                      //for app_asc_str_to_ucs2_str
#include "uart_sw.h"                     //RCV_PARAM_DATA_MAX
#include "common_nvram_editor_data_item.h"       
#include "kjx_at_command.h"

/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
#define  __SMS_APP_DEBUG__

#define   Tracker_LBS_interval_Max 60          //unit:Minute
#define   Tracker_LBS_interval_Min 1
#define   Tracker_GPS_interval_Max 60          //unit:s
#define   Tracker_GPS_interval_Min 10
#define   Tracker_GPS_Work_Time_Max   300  //uint:Minute
#define   Tracker_GPS_Work_Time_Min    5

#define   GPS_Distance_Max 500     //uint:metre
#define   GPS_Distance_Min  100
#define   GPS_Distance_Interval_Max   60  //uint:Second
#define   GPS_Distance_Interval_Min   10
#define   GPS_Position_Time_Max 30 //uint:Minute
#define   GPS_Position_Time_Min 5

#define RCV_PARAM_DATA_MAX 100


#define ERRORCODELENGTH  9

/*****************************************************************************
* Typedef  Enum
*****************************************************************************/
typedef enum
{
    SMS_Command_State,    //短信发出的命令
    AT_Command_State,    //AT发出的命令
 #if defined(__AT_USE_UART1__)
    UART1_Command_State,    //AT发出的命令
 #endif
    ONLine_Command_State //终端在线服务器下发指令
} SYS_COMMAND_STATE;

typedef enum
{
    SMS_Command_0 = 0,
    //SMS_Command_1,
    SMS_Command_2,
    SMS_Command_3,
    SMS_Command_4,
    SMS_Command_5,
    SMS_Command_6,
    SMS_Command_7,
    SMS_Command_8,
#ifdef __SOS_CALL__
    SMS_Command_9,
#endif
    SMS_Command_10,
    SMS_Command_11,
    SMS_Command_12,
    SMS_Command_13,
    SMS_Command_14,
    SMS_Command_15,
    SMS_Command_16,
    SMS_Command_17,
#if defined(__LOG_OUTPUT__)
    SMS_Command_18,
#endif
    SMS_Command_19,
#ifdef __CALL_MONITOR__
    SMS_Command_20,
#endif
    SMS_Command_21,
    SMS_Command_22,

    SMS_Command_MAX
} SMS_COMMAND_INDEX;

typedef struct
{
    char *cmd_string;
    BOOL    valid;
} ERROR_CODE_STRUCT;


/*****************************************************************************
 *  Struct					数据结构定义
 *****************************************************************************/
typedef struct
{
    BOOL valid;//数据可用;
    U16 sms_index;
    U8 part;
    U8 main_str[RCV_PARAM_DATA_MAX];
    U8 passwd[RCV_PARAM_DATA_MAX];
    U8 param0[RCV_PARAM_DATA_MAX*4];//操作
    U8 param1[RCV_PARAM_DATA_MAX];//参数
    U8 param2[RCV_PARAM_DATA_MAX];//操作
    U8 param3[RCV_PARAM_DATA_MAX];//参数
    U8 param4[RCV_PARAM_DATA_MAX];//操作
    U8 param5[RCV_PARAM_DATA_MAX];//参数
    U8 param6[RCV_PARAM_DATA_MAX];//操作
    U8 param7[RCV_PARAM_DATA_MAX];//参数
    U8 param8[RCV_PARAM_DATA_MAX];//参数
    U8 param9[RCV_PARAM_DATA_MAX];//参数
    U8 param10[RCV_PARAM_DATA_MAX];//参数
    U8 ph_num[RCV_PARAM_DATA_MAX];
}RECEIVED_DATA_STRUCT;


typedef struct
{
    U8		len;                    //短信息长度
    S8		content[400];
    U8		num[21];  // FAMILY_PHB_NUM_LEN_MIN
} SYS_SMS_STRUCT;


#if defined(__SMS_TRANSMISSION__)
typedef struct
{
    U8 isonlineorsms;
    U8 operator_num[21];   //FAMILY_PHB_NUM_LEN_MIN  // 移动、联通运营商号码 如 :10086,10000
    U8 receiver_num[21];  //FAMILY_PHB_NUM_LEN_MIN    //查询手机号码 ,回复查询余额到该手机号码
    U8 content[300];     //查询内容
    U16 contentlen;
} tracker_queryfee_struct;
extern tracker_queryfee_struct queryfee_sms;
#endif



/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/


/****************************************************************************
* Global Variable - Extern          全局变量
*****************************************************************************/
#if defined(__KJX_AT_APP__)
extern AT_DATA_STRUCT DATA_SET;
#endif /*__KJX_AT_APP__*/
#if defined(__GPS_ON_MTK__)
extern int GetAddressLen;    /*服务器下发地址长度*/
#endif
extern BOOL is_sms_asc_dcs;
extern U8 dwxx_flg;

extern char sms_buf[1024];
extern char sms_buf_ex[1024];

extern SYS_COMMAND_STATE Command_State;
extern RECEIVED_DATA_STRUCT received_data;//接收到的数据
extern SYS_SMS_STRUCT   sys_rcv_sms;          //接收到的短信内容
extern SYS_SMS_STRUCT   sys_send_sms;       //要发送的短信内容
/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/
static char* Parse_SMS_Head(char  *data_ptr);
static BOOL Tracker_smscmd_checkparts(void *src_data, void *dest_data);
static BOOL Server_command_checkparts(void *src_data, void *dest_data);
static BOOL Server_command_fn_checkparts(void *src_data, void *dest_data);

#if defined(__KJX_AT_APP__)
static void ChangeCatcherMode(void *ptr);
#endif

static void Tracker_SOS_Phone_Number(void);

#if defined(__SOC_APP__)
static void Tracker_Set_APN(void);
static void Tracker_Set_APN_Auto_Adaption(void);
static void Tracker_Set_Server(void);
#endif /*__SOC_APP__*/
static void Tracker_Command_RESET(void);
#if defined(__GPS_FENCE__)
static void Tracker_Set_Fence_Circle_Single(void);
static void Tracker_Set_Fence_Rectangle_Single(void);
static void Tracker_Set_Electronic_Fence_Single(void);
static void Tracker_See_Electronic_Fence_Set_Single(void);
#ifdef __MULTI_FENCE__
extern kal_bool is_any_fence_open_flag(void);
static void Tracker_See_Electronic_Fence_Set_Multi(void);
static void Tracker_See_Electronic_Fence_Set_Multi_1(int fence_order);
static void Tracker_Set_Fence_Circle_Multi(void);
static void Tracker_Set_Fence_Rectangle_Multi(void);
static void Tracker_Set_Electronic_Fence_Multi(void);
static void Tracker_See_Electronic_Fence_Set_Multi(void);
#endif/*__MULTI_FENCE__*/
#endif/*__GPS_FENCE__*/


static void AT_OR_SMS_Command_Pro(void);
static void Tracker_Get_LatLon_Information(void);

//static kal_bool Tracker_Search_Error_Result(char *Message);
/*****************************************************************************
 *  Global Functions			全局函数
 *****************************************************************************/
extern void make_Capital_Letter(char* buf);

extern void Commit_All_Params(void);
extern void Commit_All_Gfences(void);

extern void Tracker_GPS_Transparent_Transmission(void);
extern void Tracker_DW_Query_Connect_Abnormal(void);

#if defined(__KJX_FUN_GPS__)
extern void kjx_open_gps(void);
extern void kjx_close_gps(void);
extern void kjx_gps_software_reset(void);
#endif

#if defined(__GPS_ON_MTK__)
extern void Tracker_Send_DW_QuerySMS(void);
extern void Tracker_Send_WHERE_QuerySMS(void);
extern void Tracker_Send_URL_QuerySMS(void);
extern void Tracker_Reback_Address_URL(U8* number);
#endif
extern void Tracker_Query_GetLBS_Address(void);

extern void Kjx_ATCommand_Process(void);
extern void Tracker_SMSCommand_Process(void);
extern void Tracker_Command_Active_GPS(void);
extern void Tracker_Set_Defense_Start(void);
extern void Tracker_Set_Defense_Stop(void);
extern void Send_Command_Message_Replay(void);
extern BOOL Tracker_SMSComand_Analyse(char *data, U16 data_len);
extern BOOL Tracker_Server_Comand_Analyse(char *data, U16 data_len);
extern U8 Tracker_SMS_Handle_My_Msg(srv_sms_event_new_sms_struct * event_info);
#endif	/* __SMS_APP_H__*/
