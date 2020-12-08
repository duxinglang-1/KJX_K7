/*****************************************************************************
 *
 * Filename:  	Tracker_SOC.c
 *
 *
 * Author :    	Guojie
 *
 *
 * Date : 	2011-09-16
 *
 *
 * Comment:  soc连接
 *
 *
 ****************************************************************************/
#if defined(__KJX_SOC_APP__)
/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "MMI2ABM_STRUCT.H"
#include "APP2SOC_STRUCT.H"
#include "cbm_api.h"
#include "mmi_l3_enums.h"
#include "Kal_trace.h"
#include "ProtocolEvents.h"
#include "OslMemory_Int.h"  //"mmi_rp_xml.h"   //for OslMalloc  OslMfree
#include "Mmi_frm_events_gprot.h"    //for SetProtocolEventHandler   //mmi_frm_set_protocol_event_handler
#include "DtcntSrvIprot.h"    //srv_dtcnt_prof_acc_type_enum
#include "DtcntSrvGprot.h"   //srv_dtcnt_prof_gprs_struct
#include "DtcntSrvIntStruct.h"  //  srv_dtcnt_store_info_context
#include "SimCtrlSrvGprot.h"   //SRV_SIM_CTRL_MAX_SIM_NUM
#include "Mmi_msg_struct.h"   //mmi_ps_set_gprs_data_account_req_struct
#include "ProtocolEvents.h"   //PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_REQ
#include "DebugInitDef_Int.h"   //MMI_ASSERT
#include "AlarmFrameworkProt.h" /* AlmATPowerReset */
#include "Mmi_msg_struct.h"        //mmi_em_update_req_struct   mmi_em_status_ind_struct
#include "mmi_frm_queue_gprot.h"   //MYQUEUE
#include "DateTimeType.h"
#include "app_datetime.h"
#include "PhoneSetup.h"
#include "NwInfoSrvGprot.h"
#include "Gui_typedef.h"
#include "Mmi_rp_srv_status_icons_def.h"
#include "mmi_rp_srv_general_setting_def.h"    // NVRAM_RESET_BOOTUP

#ifdef __C_STL__
#include "c_RamBuffer.h"
#include "c_string.h"
#include "c_list.h"
#include "c_vector.h"
#endif /* __C_STL__ */

#include "kjx_soc.h"
//#include "Tracker_Main.h"
//#include "Tracker_Remind.h"
//#include "Tracker_GPRS_Send.h"
//#include "Tracker_SMS_Command.h"

#if defined(__GPS_BACKUP__)
#include "Tracker_Backup.h"
#endif

#if defined(__AGPS_EPO_SUPPORT__)
#include "Tracker_GPRS_AGPS.h"
#endif

#if defined(__SPECIAL_EPO_SOCKET__)
#include "Tracker_SOC_EPO.h"
#elif defined(__SPECIAL_AGPS_SOCKET__)
#include "Tracker_SOC_AGPS.h"
#endif

#if defined(__NEW_PROTOCOL__)
#include "Tracker_GPRS_GT88.h"
#elif defined(__OLD_PROTOCOL__)
#include "Tracker_GPRS_GT02A.h"
#endif


//参考AppNetWork.c

//网络信号好的时候，5S
//[13:34:24] CSW 03 : CFW_GprsAtt state = 0x1, nUTI = 0x21
//[13:34:29] CSW 03 : get API_NW_PSREGSTATUS_IND from stack psInMsg->Status: 0x1 ,psInMsg->Cause: 0xff


//网络信号差 31S
//[09:58:48] CSW 03 : CFW_GprsAtt state = 0x1, nUTI = 0x20
//[09:59:19] CSW 03 : get API_NW_PSREGSTATUS_IND from stack psInMsg->Status: 0x1 ,psInMsg->Cause: 0xff


//adp_PrepareGPRS -->Attach GPRS
//--->Attach Success      //app_Data_Conn_Callback  adp_GPRS_event.c  line 1184
//soc_StartActiveGPRS(g_apnsize,g_apnName);
//app_Data_Conn_Callback:: Activation Success
//soc_notify_GPRS_CONNECTED(0);
//有此消息发出才能去连网络

//如果两个域名在很短时间内同时去解析
//会导致前一个域名返回IP是后一个域名的解析的IP
//就是后面的域名返回两次IP
/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
#define __SOC_DEBUG__

#define __TRACKER_MTK_VERSION__    0x11B1132
#define INVALIDE_SOCKET_ID 0XFF
#define TRACKER_SEND_STATUS_DATA_TIME 5*60*1000    //状态包每5分钟发一次
#define mmi_dtcnt_acct_type_enum srv_dtcnt_prof_acc_type_enum

#define SOCKET_CONNECT_OVERTIMER_RESET_TIME  20*60*1000   //20分钟重启 
#define PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_REQ MSG_ID_MMI_PS_SET_GPRS_DATA_ACCOUNT_REQ
#define PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_RSP MSG_ID_MMI_PS_SET_GPRS_DATA_ACCOUNT_RSP
/*****************************************************************************
* Typedef  Enum
*****************************************************************************/
#if defined(__NEW_PROTOCOL__)
GPRS_SEND_INFO_TYPE  gprs_send_type = GPRS_LOGIN_INFO;
#elif defined(__OLD_PROTOCOL__)
GPRS_SEND_INFO_TYPE  gprs_send_type = GPRS_STATUS_INFO;
#endif

DNS_PARSE_STATUS DNS_Parse_Status = DNS_PARSE_IDLE;
/*****************************************************************************
 *  Struct					数据结构定义
 *****************************************************************************/
TRACKER_SOC_STRUCT soc_content = {0};
TRACKER_LOGIN_INFO_STRUCT tracker_login_info = {0};
SOC_RECEIVE_DATA_STRUCT Soc_Receive_Data = {0};


/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/
static c_vector* vec_socket_send = NULL;
static U8 Heartbeat_SendTimes = 0;      /*心跳包重发三次没有回复则断开重连*/
static U8 department[PACKET_SOC_MAX][SIGLELEN_SOC_MAX] = {0}; //最多支持3包拼包解析AGPS一包数据长度1034
//放在receive函数里面，申请不到就会重启
static U8 recvcrc_buffer[SIGLELEN_SOC_MAX];   //AGPS 一包数据 1034

/****************************************************************************
* Global Variable            全局变量
*****************************************************************************/
U16 gprs_inf_ind = 0;
U16 g_server_serno = 0; /* 收到的服务器报文流水号 */
U8 EnterNoServiceTimes = 0;
BOOL AlreadyGetNetworkId = FALSE;   /*未获取网络ID之前去Reconnect 会重启*/

/****************************************************************************
* Global Variable - Extern          引用全局变量
*****************************************************************************/
extern srv_dtcnt_store_info_context g_srv_dtcnt_store_ctx;
extern nvram_ef_tracker_gps_backup_data_param_struct backup_data_param;

/*****************************************************************************
 *  Global Functions	- Extern		引用外部函数
 *****************************************************************************/
extern void mmi_dtcnt_add_disp_list(U32 acct_id, U8 bearer_type, mmi_dtcnt_acct_type_enum account_type, U8 conn_type, U8 sim_info, U8 read_only);
extern float GetTimeZone(kal_uint8 cityIndex);
#if defined(__GK306__)||defined(__GTM100__)||defined(__GK301__)||defined(__GT88__)
extern void kksapp_adjust_time(MYTIME * dt);
#endif

/*****************************************************************************
 *  Local Functions			本地函数
*****************************************************************************/
/******************************************************************************
 *  Function    -  Tracker_Show_GPRS_Icon
 *
 *  Purpose     -  G状态图标更新
 *
 *  Description -  //IMG_SI_GPRS_INDICATOR   IMG_SI_GPRS_ATT_NO_PDP_INDICATOR
 *
 * modification history   // STATUS_ICON_GPRS_SERVICE  STATUS_ICON_GPRS_ATT_NO_PDP_INDICATOR
 * ----------------------------------------
 * v1.0  , 2012-07-13,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Show_GPRS_Icon(void)
{
    //kal_prompt_trace(MOD_TST, "Tracker_Show_GPRS_Icon %d,%d", DisplayGPRSIcon, soc_content.soc_state);
    DisplayGPRSIcon = TRUE;
    if(soc_content.soc_state == SOC_CONNECTED)
    {
        //wgui_status_icon_bar_reset_icon_display(STATUS_ICON_GPRS_ATT_NO_PDP_INDICATOR);
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_GPRS_SERVICE);
    }
    else
    {
        //wgui_status_icon_bar_reset_icon_display(STATUS_ICON_GPRS_ATT_NO_PDP_INDICATOR);
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_GPRS_SERVICE);
    }
    wgui_status_icon_bar_update();
}

/******************************************************************************
 *  Function    -  Tracker_Soc_Reset
 *
 *  Purpose     -  网络连接无回复数据超时重启
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-11-04,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
void Tracker_Soc_Reset(void)
{
    S16 error;
    U8 state = 1;

    StopTimer(TRACKER_RESET_TIMER);
    StopTimer(TRACKER_SOCKET_CONNECT_OVERTIMER);

#if defined(__SOC_DEBUG__)	
    LOGD(L_SOC, L_V5, "Tracker_Soc_Reset");
#endif/*__SOC_DEBUG__*/

    //若正在通话 返回  /*回复超时短信即可*/
    if(IS_IN_CALL() || tracker_ctrl_data.GPRSAlwaysOn == 2 || tracker_ctrl_data.GPRSAlwaysOn == 0)
    {
        StartTimer(TRACKER_RESET_TIMER, 60 * 1000, Tracker_Soc_Reset);
        return;
    }
    else if((TrackerSocAbnormalReset == FALSE) && (GPS_Get_Backup_Total_Number() >= 1)) //有备份数据延时重启
    {
        TrackerSocAbnormalReset = TRUE;

	#if defined(__GPS_BACKUP__)
        StopTimer(GPS_NVRAM_DATA_SYN_TIMER);
        GPS_NVRAM_Data_Syn();
	#endif
        StartTimer(TRACKER_RESET_TIMER, 60 * 1000, Tracker_Soc_Reset);
        return;
    }
    else if((TrackerSocAbnormalReset == TRUE) && (GPS_Get_Backup_Total_Number() == 0))
    {
        StartTimer(TRACKER_RESET_TIMER, 60 * 1000, Tracker_Soc_Reset);
        return;
    }

#if defined(__SOC_DEBUG__)
    LOGD(L_SOC, L_V5, "  soc not connect reset system:%d", tracker_ctrl_data.GPRSAlwaysOn);
#endif/*__SOC_DEBUG__*/

    if(tracker_ctrl_data.GPRSAlwaysOn == 1)
    {
	#if defined(__KD6113_MCU_CONTROL__) //停止看门狗定时器，让单片机重启
		Tracker_MCU_Reset_System();
	#else
        AlmATPowerReset(MMI_FALSE, 3);
	#endif/*__KD6113_MCU_CONTROL__*/
    }

}

#if defined(__OLD_PROTOCOL__)
/******************************************************************************
 *  Function    -  Tracker_Soc_Abnormal_Reset
 *
 *  Purpose     -  先发送异常状态包再重启
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2014-08-26,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Soc_Abnormal_Reset(void)
{
    GT02A_Abnormal_State = ABNORMAL_SOC_INVALID;
    Tracker_Send_Abnormal_Status_Data();
    StopTimer(TRACKER_RESET_TIMER);
    StartTimer(TRACKER_RESET_TIMER, 60 * 1000, Tracker_Soc_Reset);
}
#endif

/*****************************************************************************
 * FUNCTION			Tracker_Sever_adjusttime_Packet
 *
 * DESCRIPTION		时间同步
 *
 * PARAMETERS            从后台获取时间是UTC0
 *		void
 * RETURNS                 加终端时区，显示为当前时区
 *           void               此函数在本文件中调用，只能放在本文件内
 *                                不能移动到其他文件，否则出现加时区显示为
 *                                当前时间不对
 * ----------------------------------------
 * v1.0  , 2012-08-22, jinlong  written
 * ----------------------------------------
 *****************************************************************************/
static void Tracker_Sever_adjusttime_Packet(void)
{
    U32 time_temp = 0;
    U32 rtcTime = 0;
    float timezone = 0.0;
    MYTIME time, time1;

    time_temp = 0;
    time_temp = (time_temp | Soc_Receive_Data.Content[4]) << 24 ;
    rtcTime |= time_temp ;

    time_temp = 0;
    time_temp = (time_temp | Soc_Receive_Data.Content[5]) << 16 ;
    rtcTime |= time_temp ;

    time_temp = 0;
    time_temp = (time_temp | Soc_Receive_Data.Content[6]) << 8 ;
    rtcTime |= time_temp ;

    time_temp = 0;
    time_temp = (time_temp | Soc_Receive_Data.Content[7]);
    rtcTime |= time_temp ;

#if defined(__SOC_DEBUG__)
    LOGD(L_OS, L_V5, " rtcTime = %d,%d", rtcTime, g_phnset_cntx_p->currentCity);
#endif/*__SOC_DEBUG__*/

    timezone = GetTimeZone(g_phnset_cntx_p->currentCity);
    mmi_dt_utc_sec_2_mytime(rtcTime, (applib_time_struct *)&time1, 0);
    mmi_dt_utc_to_rtc(timezone, time1, time);

    kksapp_adjust_time((MYTIME *)&time);
}

/******************************************************************************
 *  Function    -  Tracker_Server_Adjusttime_Handle
 *
 *  Purpose     -  连上服务器在线同步时间
 *
 *  Description -sned 78 78 0D 1F 00 00 00 00 00 00 00 01 00 0D 06 21 0D 0A
 *                     back 78 78 09 1F 52 92 EA ED 00 0D A6 F8 0D 0A
 *                       服务器下发的是UTC+0 秒
 * modification history
 * ----------------------------------------
 * v1.0  , 2013-11-25, guojie  written
 *起始位+长度+协议号+信息内容+序列号+CRC校验+停止位
 * ----------------------------------------
 ******************************************************************************/
void Tracker_Server_Adjusttime_Handle(void)
{
    U32 time_temp = 0;
    U32 rtcTime = 0;
    float timezone = 0.0;
    MYTIME CurrTime, time1;

    time_temp = 0;
    time_temp = (time_temp | Soc_Receive_Data.Content[4]) << 24 ;
    rtcTime |= time_temp ;

    time_temp = 0;
    time_temp = (time_temp | Soc_Receive_Data.Content[5]) << 16 ;
    rtcTime |= time_temp ;

    time_temp = 0;
    time_temp = (time_temp | Soc_Receive_Data.Content[6]) << 8 ;
    rtcTime |= time_temp ;

    time_temp = 0;
    time_temp = (time_temp | Soc_Receive_Data.Content[7]);
    rtcTime |= time_temp ;


    //[4]Tracker_Server_Adjusttime_Handle rtcTime = 235406597,1977-6-17 22:43:17
    //途强平台下发的时间不对
    mmi_dt_utc_sec_2_mytime(rtcTime, (applib_time_struct *)&CurrTime, 0);

    //加时区
    GPS_Add_Timezone(&CurrTime);

#if defined(__SOC_DEBUG__)
    LOGD(L_OS, L_V5, " rtcTime = %d,%d-%d-%d %d:%d:%d", rtcTime, CurrTime.nYear, CurrTime.nMonth, CurrTime.nDay, CurrTime.nHour, CurrTime.nMin, CurrTime.nSec);
#endif/*__SOC_DEBUG__*/


    if(CurrTime.nYear >=2014&&CurrTime.nMonth!=1&&CurrTime.nDay!=1)
    {
        Update_System_Time(&CurrTime);
    }
   
}




#if defined(__PROJ_MODEM__)  //模块工程连接方式
/******************************************************************************
 *  Function    -  Tracker_Socket_Update_AccountID_PS
 *
 *  Purpose     -  获取网络accountID   (GPRS类型)
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-09-16,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Socket_Update_AccountID_PS(void)
{
    mmi_abm_update_account_info_req_struct *info_req = NULL;
    MYQUEUE Message;
#if defined(__SOC_DEBUG__)
    LOGD(L_SOC, L_V5, " ",);
#endif/*__SOC_DEBUG__*/
    info_req = (mmi_abm_update_account_info_req_struct *)construct_local_para(sizeof(mmi_abm_update_account_info_req_struct), TD_RESET);
    info_req->action = MMI_ABM_PROFILE_ADD;
    info_req->account_id = 0x3e00;   //00表示第1个account
    info_req->bearer_type = CBM_PS;   //bearer的类型为GPRS

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_ABM;
    Message.oslMsgId = MSG_ID_MMI_ABM_UPDATE_ACCOUNT_INFO_REQ;
    Message.oslSapId = MMI_ABM_SAP;
    Message.oslDataPtr = (oslParaType*) info_req;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}

/******************************************************************************
 *  Function    -  Tracker_Socket_Update_AccountID_CSD
 *
 *  Purpose     -  获取网络accountID   (CSD类型)
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-09-16,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Socket_Update_AccountID_CSD(void)
{
    mmi_abm_update_account_info_req_struct *info_req = NULL;
    MYQUEUE Message;
#if defined(__SOC_DEBUG__)
    LOGD(L_SOC, L_V5, " ");
#endif/*__SOC_DEBUG__*/
    info_req = (mmi_abm_update_account_info_req_struct *)construct_local_para(sizeof(mmi_abm_update_account_info_req_struct), TD_RESET);
    info_req->action = MMI_ABM_PROFILE_ADD;
    info_req->account_id = 0x3e01;   //01表示第2个account
    info_req->bearer_type = CBM_PS;   //bearer的类型为CSD类型

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_ABM;
    Message.oslMsgId = MSG_ID_MMI_ABM_UPDATE_ACCOUNT_INFO_REQ;
    Message.oslSapId = MMI_ABM_SAP;
    Message.oslDataPtr = (oslParaType*) info_req;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}

/******************************************************************************
*  Function    -  Tracker_Socket_Send_Update_AccountID_Ind
*
*  Purpose     -  获取网络accountID   (GPRS类型)
*
*  Description -
*
* modification history
* ----------------------------------------
* v1.0  , 2011-09-19,  guojie  written
* ----------------------------------------
******************************************************************************/
static void Tracker_Socket_Send_Update_AccountID_Ind(void)
{
    Tracker_Socket_Update_AccountID_PS();
}

/******************************************************************************
 *  Function    -  Tracker_Socket_Abm_Profile_Ind_Rsp
 *
 *  Purpose     -  回复profile MSG
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-11-03,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Socket_Abm_Profile_Ind_Rsp(kal_uint32 accountId, nvram_ef_tracker_apn_param_struct apn_param)
{
    mmi_abm_profile_query_rsp_struct *profile_query_rsp = NULL;
    MYQUEUE Message;
#if defined(__SOC_DEBUG__)
    LOGD(L_SOC, L_V5, " accountId = %d", accountId);
#endif/*__SOC_DEBUG__*/
    profile_query_rsp = (mmi_abm_profile_query_rsp_struct *)construct_local_para(sizeof(mmi_abm_profile_query_rsp_struct), TD_RESET);

    profile_query_rsp->result = KAL_TRUE;
    profile_query_rsp->account_id = accountId;  /*填入MSG_ID_MMI_ABM_PROFILE_QUERY_IND消息中的account_id*/

    //可能需要设置用户名和密码
    strncpy(profile_query_rsp->content.user_name, apn_param.user_name, strlen(apn_param.user_name));
    strncpy(profile_query_rsp->content.password, apn_param.password, strlen(apn_param.password));

    //对于PS类型的account_id (通过account_id来判断account的类型)
    strncpy(profile_query_rsp->content.ps_account_info.apn, apn_param.apn, strlen(apn_param.apn)); /*填入想配置的APN  cmwap cmnet*/
    profile_query_rsp->content.ps_account_info.apn_length = strlen(apn_param.apn);
    profile_query_rsp->content.ps_account_info.dcomp_algo = SND_NO_DCOMP;
    profile_query_rsp->content.ps_account_info.hcomp_algo = SND_NO_PCOMP;
    profile_query_rsp->content.ps_account_info.pdp_type = IPV4_ADDR_TYPE;
    profile_query_rsp->content.ps_account_info.pdp_addr_len = IPV4_ADDR_LEN;

    //对于CSD类型的account
    //strncpy(profile_query_rsp->content.csd_account_info.addr_str,"17201",strlen("17201"));   /*填入拨号地址*/
    //profile_query_rsp->content.csd_account_info.csd_ur = CSD_PROF_RATE_9600;
    //profile_query_rsp->content.csd_account_info.csd_type = CSMCC_ITC_3_1_K_AUDIO  ; /*or CSMCC_ITC_UDI*/

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_ABM;
    Message.oslMsgId = MSG_ID_MMI_ABM_PROFILE_QUERY_RSP;
    Message.oslSapId = MMI_ABM_SAP;
    Message.oslDataPtr = (oslParaType*) profile_query_rsp;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}


/******************************************************************************
 *  Function    -  Tracker_Process_Abm_Profile_Ind_Handler
 *
 *  Purpose     -  回复profile MSG
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-09-23,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Process_Abm_Profile_Ind_Handler(void * inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_profile_query_ind_struct *profile_info = (mmi_abm_profile_query_ind_struct*)inMsg;
    kal_uint32 accountId = 0;
#if defined(__SOC_DEBUG__)
    LOGD(L_SOC, L_V5, "  %d,%d,%x", profile_info->ref_count, profile_info->msg_len, profile_info->account_id);
#endif/*__SOC_DEBUG__*/
    accountId = (profile_info->account_id) & 0x00FF;
    Tracker_Socket_Abm_Profile_Ind_Rsp(accountId, tracker_apn_param);


    //2011-12-8 连接失败要启动一个定时器去检查是否Tracker_Socket_Notify
    //MSG_ID_APP_SOC_NOTIFY_IND 这个消息上来，没有要定时启动重连
}
#endif

/******************************************************************************
 *  Function    -  Tracker_socket_mmi_dtcnt_add_disp_list
 *
 *  Purpose     - add disp list
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2012-05-31,  guojie  整理
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_socket_mmi_dtcnt_add_disp_list(U32 acct_id, const U8 *acct_name, const U8 *addr, U8 bearer_type, U32 account_type, U8 conn_type, U8 sim_info, U8 read_only)
{
#if (__TRACKER_MTK_VERSION__ == 0x11A1112)

#elif (__TRACKER_MTK_VERSION__ == 0x10A1103)||(__TRACKER_MTK_VERSION__ == 0x11B1132)
    mmi_dtcnt_add_disp_list(acct_id, bearer_type, account_type, conn_type, sim_info, read_only);
#else
    mmi_dtcnt_add_disp_list(acct_id, acct_name, addr, bearer_type, account_type, conn_type, sim_info, read_only);
#endif
}

/******************************************************************************
 *  Function    -  Tracker_socket_mmi_dtcnt_update_disp_list
 *
 *  Purpose     - update disp list
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2012-05-31,  guojie  整理
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_socket_mmi_dtcnt_update_disp_list(U32 acct_id, const U8 *acct_name, const U8 *addr, U8 bearer_type, U32 account_type, U8 conn_type, U8 sim_info, U8 read_only)
{
#if (__TRACKER_MTK_VERSION__ == 0x11A1112)

#elif (__TRACKER_MTK_VERSION__ == 0x10A1103)||(__TRACKER_MTK_VERSION__ == 0x11B1132)
    mmi_dtcnt_update_disp_list(acct_id, bearer_type, account_type, conn_type, sim_info, read_only);
#else
    mmi_dtcnt_update_disp_list(acct_id, acct_name, addr, bearer_type, account_type, conn_type, sim_info, read_only);
#endif
}

/******************************************************************************
 *  Function    -  Tracker_socket_mgr_update_acc_prof_id
 *
 *  Purpose     - update acc profile id
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2012-05-31,  guojie  整理
 * ----------------------------------------
 ******************************************************************************/
static BOOL Tracker_socket_mgr_update_acc_prof_id(uint32 acc_prof_id, const WCHAR* account_name,
        nvram_ef_tracker_apn_param_struct apn_param, cbm_sim_id_enum sim)
{
    srv_dtcnt_result_enum ret;
    srv_dtcnt_store_prof_data_struct prof_info;
    srv_dtcnt_prof_gprs_struct prof_gprs;
    int i;

    MMI_ASSERT(apn_param.apn != NULL);

    memset(&prof_gprs, 0, sizeof(prof_gprs));
    prof_gprs.APN = apn_param.apn;
    prof_gprs.prof_common_header.sim_info = sim + 1;
    prof_gprs.prof_common_header.AccountName = (const U8*)account_name;

    //if (accountInfo)
    {
        prof_gprs.prof_common_header.Auth_info.AuthType = apn_param.authentication_type;
        strcpy((char*)prof_gprs.prof_common_header.Auth_info.UserName, apn_param.user_name);
        strcpy((char*)prof_gprs.prof_common_header.Auth_info.Passwd, apn_param.password);
        for(i = 0; i < 4; i++)
        {
            prof_gprs.prof_common_header.PrimaryAddr[i] = apn_param.dns[i];    //guojie
        }
    }

    prof_gprs.prof_common_header.acct_type = SRV_DTCNT_PROF_TYPE_USER_CONF;

    prof_gprs.prof_common_header.px_service = SRV_DTCNT_PROF_PX_SRV_HTTP;
    if(app_stricmp((char*)apn_param.apn, (char*)"cmwap") == 0)
    {
        prof_gprs.prof_common_header.use_proxy = KAL_TRUE;
        prof_gprs.prof_common_header.px_addr[0] = 10;
        prof_gprs.prof_common_header.px_addr[1] = 0;
        prof_gprs.prof_common_header.px_addr[2] = 0;
        prof_gprs.prof_common_header.px_addr[3] = 172;
        prof_gprs.prof_common_header.px_port = 80;
    }

    strcpy(prof_gprs.prof_common_header.HomePage, "http://wap.51mrp.com");

    prof_info.prof_data = &prof_gprs;
    prof_info.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;
    prof_info.prof_type = SRV_DTCNT_BEARER_GPRS;

    ret = srv_dtcnt_store_update_prof(acc_prof_id, &prof_info);

    if(ret == SRV_DTCNT_RESULT_SUCCESS)
    {
	#if defined(__SOC_DEBUG__)
        LOGD(L_SOC, L_V5, "  ");
	#endif/*__SOC_DEBUG__*/
        Tracker_socket_mmi_dtcnt_update_disp_list(acc_prof_id, prof_gprs.prof_common_header.AccountName, prof_gprs.APN, DATA_ACCOUNT_BEARER_GPRS,
                prof_gprs.prof_common_header.acct_type, 1, prof_gprs.prof_common_header.sim_info, prof_gprs.prof_common_header.read_only);

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/******************************************************************************
 *  Function    -  Tracker_socket_mgr_find_acc_prof_id
 *
 *  Purpose     -  通过account name找到acc profile id
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2012-05-31,  guojie  整理
 * ----------------------------------------
 ******************************************************************************/
static uint32 Tracker_socket_mgr_find_acc_prof_id(const WCHAR* account_name)
{
    int i, j;
    srv_dtcnt_result_enum ret;
    srv_dtcnt_store_prof_qry_struct store_prof_qry;
    srv_dtcnt_prof_str_info_qry_struct prof_str_info_qry;
    U16 name[SRV_DTCNT_PROF_MAX_ACC_NAME_LEN + 1] = {0};

    for(j = 0; j < SRV_SIM_CTRL_MAX_SIM_NUM; ++j)
    {
        memset(&store_prof_qry, 0, sizeof(store_prof_qry));
        store_prof_qry.qry_info.filters = SRV_DTCNT_STORE_QRY_TYPE_SIM | SRV_DTCNT_STORE_QRY_TYPE_BEARER_TYPE;
        store_prof_qry.qry_info.sim_qry_info = j + 1;
        store_prof_qry.qry_info.bearer_qry_info = SRV_DTCNT_BEARER_GPRS;

        ret = srv_dtcnt_store_qry_ids(&store_prof_qry);
        if(ret == SRV_DTCNT_RESULT_SUCCESS)
        {
            for(i = 0; i < store_prof_qry.num_ids; ++i)
            {
                prof_str_info_qry.dest = (S8*)name;
                prof_str_info_qry.dest_len = sizeof(name);
                srv_dtcnt_get_account_name(store_prof_qry.ids[i], &prof_str_info_qry, SRV_DTCNT_ACCOUNT_PRIMARY);

                if(kal_wstrcmp(account_name, name) == 0)
                {
                    return store_prof_qry.ids[i];
                }
            }
        }
    }

    return -1;
}

/******************************************************************************
 *  Function    -  Tracker_socket_mgr_add_acc_prof_id
 *
 *  Purpose     -  通过account name增加acc profile id
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2012-05-31,  guojie  整理
 * ----------------------------------------
 ******************************************************************************/
static uint32 Tracker_socket_mgr_add_acc_prof_id(const WCHAR* account_name)
{
    srv_dtcnt_store_prof_data_struct store_prof_data;
    srv_dtcnt_prof_gprs_struct prof_gprs;
    uint32 acc_prof_id;
    srv_dtcnt_result_enum ret;
#if defined(__SOC_DEBUG__)
    LOGD(L_SOC, L_V5, "  ");
#endif/*__SOC_DEBUG__*/

    memset(&prof_gprs, 0, sizeof(prof_gprs));
    prof_gprs.APN = tracker_apn_param.apn;      //"cmwap";	// 这个值在应用使用的时候会修改的
    prof_gprs.prof_common_header.sim_info = SRV_DTCNT_SIM_TYPE_1;
    prof_gprs.prof_common_header.AccountName = (const U8*)account_name;

    prof_gprs.prof_common_header.acct_type = SRV_DTCNT_PROF_TYPE_USER_CONF;

    prof_gprs.prof_common_header.px_service = SRV_DTCNT_PROF_PX_SRV_HTTP;
    prof_gprs.prof_common_header.use_proxy = KAL_TRUE;
    prof_gprs.prof_common_header.px_addr[0] = 10;
    prof_gprs.prof_common_header.px_addr[1] = 0;
    prof_gprs.prof_common_header.px_addr[2] = 0;
    prof_gprs.prof_common_header.px_addr[3] = 172;
    prof_gprs.prof_common_header.px_port = 80;

    strcpy(prof_gprs.prof_common_header.HomePage, "http://wap.51mrp.com");

    store_prof_data.prof_data = &prof_gprs;
    store_prof_data.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;
    store_prof_data.prof_type = SRV_DTCNT_BEARER_GPRS;

    ret = srv_dtcnt_store_add_prof(&store_prof_data, &acc_prof_id);

    if(ret == SRV_DTCNT_RESULT_SUCCESS)
    {
        Tracker_socket_mmi_dtcnt_add_disp_list(acc_prof_id, prof_gprs.prof_common_header.AccountName, prof_gprs.APN, DATA_ACCOUNT_BEARER_GPRS,
                                               prof_gprs.prof_common_header.acct_type, 1, prof_gprs.prof_common_header.sim_info, prof_gprs.prof_common_header.read_only);
    }
    else
    {
        acc_prof_id = -1;
    }

    return acc_prof_id;
}

/******************************************************************************
 *  Function    -  Tracker_socket_mgr_find_acc_prof_id_by_apn
 *
 *  Purpose     -  通过apn找到acc profile id
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2012-05-31,  guojie  整理
 * ----------------------------------------
 ******************************************************************************/
static kal_int32 Tracker_socket_mgr_find_acc_prof_id_by_apn(const char* apn, cbm_sim_id_enum sim)
{
    int i;
#if defined(__SOC_DEBUG__)
    LOGD(L_OS,L_V5, "Entry Tracker_socket_mgr_find_acc_prof_id_by_apn apn=%s, sim=%d", apn, sim);
#endif/*__SOC_DEBUG__*/
    for(i = 0; i < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; ++i)
    {
	#if defined(__SOC_DEBUG__)
        LOGD(L_OS,L_V5, "acc_list[%d].in_use=%d,bearer_type =%d, sim_info=%d,dest_name=%s",
                         i, g_srv_dtcnt_store_ctx.acc_list[i].in_use, g_srv_dtcnt_store_ctx.acc_list[i].bearer_type,
                         (sim + 1), g_srv_dtcnt_store_ctx.acc_list[i].dest_name);
	#endif/*__SOC_DEBUG__*/

        if(g_srv_dtcnt_store_ctx.acc_list[i].in_use &&
                g_srv_dtcnt_store_ctx.acc_list[i].bearer_type == SRV_DTCNT_BEARER_GPRS &&
                g_srv_dtcnt_store_ctx.acc_list[i].sim_info == (sim + 1) &&
                app_stricmp((char*)g_srv_dtcnt_store_ctx.acc_list[i].dest_name, (char*)apn) == 0)
        {
            return g_srv_dtcnt_store_ctx.acc_list[i].acc_id;
        }
    }

    return -1;
}

/******************************************************************************
 *  Function    -  Tracket_socket_mgr_get_acc_prof_id
 *
 *  Purpose     -  获取分配给应用的数据账号，可以支持两个应用同时使用
 *
 *  Description -
 *   @param 应用handle
 *   @return 账号索引，这个值肯定是有效的
 *   1. 搜索系统中存在的数据账户
 *   2. 检查虚拟机平台账号是否已存在
 *   3. 如果存在则返回这个账号ID，如果不存在继续
 *   4. 添加一个虚拟机平台数据账号
 *   5. 如果成功 返回账号ID，如果失败则返回指定的账号ID
 * modification history
 * ----------------------------------------
 * v1.0  , 2012-05-31,  guojie 整理
 * ----------------------------------------
 ******************************************************************************/
static U32 Tracket_socket_mgr_get_acc_prof_id(nvram_ef_tracker_apn_param_struct apn_param, cbm_sim_id_enum sim_id)
{
    const WCHAR* names[] = { L"KNU1 GPRS", L"KNU2 GPRS" };
    U32 modify_acc_prof_ids[] = { SRV_DTCNT_PROF_MAX_ACCOUNT_NUM - 1, SRV_DTCNT_PROF_MAX_ACCOUNT_NUM - 2 };
    U32 acc_prof_id;
    S32 id;

    id = 0;
#if defined(__SOC_DEBUG__)
    LOGD(L_SOC, L_V5, "  apn=%s, sim=%d", (char*)apn_param.apn, sim_id);
#endif/*__SOC_DEBUG__*/

    MMI_ASSERT(id >= 0 && id <= 1);

    acc_prof_id = Tracker_socket_mgr_find_acc_prof_id_by_apn((const char*)apn_param.apn, sim_id);

#if defined(__SOC_DEBUG__)
    LOGD(L_SOC, L_V5, "  acc_prof_id=%d", acc_prof_id);
#endif/*__SOC_DEBUG__*/

    if(acc_prof_id != -1)
    {
        return acc_prof_id;
    }

    acc_prof_id = Tracker_socket_mgr_find_acc_prof_id(names[id]);

    if(acc_prof_id == -1)
    {
        acc_prof_id = Tracker_socket_mgr_add_acc_prof_id(names[id]);
    }

    if(acc_prof_id == -1)
    {
        if(id == 0)
        {
            acc_prof_id = Tracker_socket_mgr_find_acc_prof_id(names[1]);
        }
        else
        {
            acc_prof_id = Tracker_socket_mgr_find_acc_prof_id(names[0]);
        }

        if(acc_prof_id == -1)
        {
            acc_prof_id = modify_acc_prof_ids[id];
        }
        else
        {
            if(acc_prof_id == SRV_DTCNT_PROF_MAX_ACCOUNT_NUM - 1)
            {
                acc_prof_id = acc_prof_id - 1;
            }
            else
            {
                acc_prof_id = acc_prof_id + 1;
            }
        }
    }

    if(!Tracker_socket_mgr_update_acc_prof_id(acc_prof_id, names[id], apn_param, sim_id))
    {
        acc_prof_id = -1;
    }

    return acc_prof_id;
}

/******************************************************************************
 *  Function    -  Tracker_Socket_ApnSet_Req
 *
 *  Purpose     -  网络连接前设置APN
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2012-06-01,  guojie  整理
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Socket_ApnSet_Req(const char *mode, char* apn, PsFuncPtr functionAction)
{
    mmi_ps_set_gprs_data_account_req_struct *myMsgPtr;
    U8	ref_count;
    U16 msg_len;
    MYQUEUE Message;
    U8 i = 0;

#if defined(__SOC_DEBUG__)
    LOGD(L_SOC, L_V5, "  ");
#endif/*__SOC_DEBUG__*/

    myMsgPtr = (mmi_ps_set_gprs_data_account_req_struct*) OslConstructDataPtr(sizeof(mmi_ps_set_gprs_data_account_req_struct));

    if(myMsgPtr == NULL)
    {
	#if defined(__SOC_DEBUG__)
        LOGD(L_SOC, L_V5, "soc_iniDataAccount_return");
	#endif/*__SOC_DEBUG__*/
	
        return;
    }

    ref_count = myMsgPtr->ref_count;
    msg_len = myMsgPtr->msg_len;
    memset(myMsgPtr, '\0', sizeof(mmi_ps_set_gprs_data_account_req_struct));
    myMsgPtr->ref_count = ref_count;
    myMsgPtr->msg_len = msg_len;

    myMsgPtr->gprs_account.authentication_type = tracker_apn_param.authentication_type;  //0

    strcpy((char*)myMsgPtr->gprs_account.apn, tracker_apn_param.apn);
    myMsgPtr->gprs_account.apn_length = strlen(tracker_apn_param.apn);

    strcpy((char*)myMsgPtr->gprs_account.user_name, (char*)tracker_apn_param.user_name);
    strcpy((char*)myMsgPtr->gprs_account.password, (char*)tracker_apn_param.password);

    for(i = 0; i < 4; i++)
    {
        myMsgPtr->gprs_account.dns[i] = 0;
    }

    myMsgPtr->gprs_account.dcomp_algo = 0x02 ;
    myMsgPtr->gprs_account.hcomp_algo = 0x02 ;
    myMsgPtr->gprs_account.pdp_type = 0x21 ;
    myMsgPtr->gprs_account.pdp_addr_len = 0x01 ;

    Message.oslSrcId = MOD_MMI;
#if defined(__KKS_SOCKET_DUAL_SUPPORT__)
    Message.oslDestId = MOD_L4C_2;
#else
    Message.oslDestId = MOD_L4C;
#endif
    Message.oslMsgId = PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_REQ;
    Message.oslDataPtr = (oslParaType *)myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    SetProtocolEventHandler(functionAction, PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_RSP);
    OslMsgSendExtQueue(&Message);

}

/******************************************************************************
 *  Function    -  Tracker_Socket_ApnSet_Rsp
 *
 *  Purpose     -  Tracker_Socket_ApnSet_Rsp
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2012-06-01,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Socket_ApnSet_Rsp(void* info)
{
    mmi_ps_set_gprs_data_account_rsp_struct *localPtr;
    localPtr = (mmi_ps_set_gprs_data_account_rsp_struct *)info;

#if defined(__SOC_DEBUG__)
	LOGD(L_SOC, L_V5, "  localPtr->result=[%d]",  localPtr->result);
#endif/*__SOC_DEBUG__*/

    if(localPtr != NULL && localPtr->result == KAL_TRUE)
    {
        Tracker_Socket_TCP_Start();
    }
    else
    {
    }
}

/******************************************************************************
 *  Function    -  Tracker_socket_set_account_id
 *
 *  Purpose     - 根据当前SIM设置account id
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2012-05-31,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_socket_set_account_id(cbm_sim_id_enum sim_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	kal_int32 i;
	U16 vs_apn[32];
	S8 temp[32];

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	i = Tracket_socket_mgr_get_acc_prof_id(tracker_apn_param, sim_id);
	cbm_hold_bearer(soc_content.cbm_app_id);

	soc_content.nwt_account_id = cbm_encode_data_account_id(i, sim_id, soc_content.cbm_app_id, KAL_FALSE);

#if defined(__SOC_DEBUG__)
	LOGD(L_SOC, L_V5, "  app_id:%d,nwt:%d,%d",	soc_content.cbm_app_id, soc_content.nwt_account_id, i);
#endif/*__SOC_DEBUG__*/

#if defined(__SPECIAL_EPO_SOCKET__)
	epo_soc_content.nwt_account_id = soc_content.nwt_account_id;   //此值联网无效
#endif
}

/******************************************************************************
 *  Function    -  Tracker_Socket_Register_Id_Get_NetworkId
 *
 *  Purpose     -  注册APP ID ，获取network account id
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-09-27,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
#if defined(__PROJ_MODEM__)   //模块工程SOCKET连接方法
static BOOL Tracker_Socket_Register_Id_Get_NetworkId(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_app_info_struct app_info;
    U8 app_id = CBM_INVALID_APP_ID;

    S8 ret = 0;
    //register app id
    memset(&app_info, 0, sizeof(app_info));
    app_info.app_icon_id = 301;
    app_info.app_str_id = 111;
    app_info.app_type = 0;   //DTCNT_APPTYPE_NONE

    ret = cbm_register_app_id_with_app_info(&app_info, &app_id);

#if defined(__SOC_DEBUG__)
    LOGD(L_SOC, L_V5, "  %d,%d", ret, app_id);
#endif/*__SOC_DEBUG__*/

    //get network id
    if(ret == CBM_OK)
    {
        soc_content.cbm_app_id = app_id;
        soc_content.nwt_account_id = cbm_encode_data_account_id(0, CBM_SIM_ID_SIM1, soc_content.cbm_app_id, KAL_FALSE);

	#if defined(__SOC_DEBUG__)
        LOGD(L_SOC, L_V5, " nwt:%d,app_id:%d", soc_content.nwt_account_id, soc_content.cbm_app_id);
	#endif/*__SOC_DEBUG__*/
	
        AlreadyGetNetworkId = TRUE;
        return TRUE;
    }
    else
    {
	#if defined(__SOC_DEBUG__)
        LOGD(L_SOC, L_V5, " Fail!");
	#endif/*__SOC_DEBUG__*/
	
        AlreadyGetNetworkId = FALSE;
        return FALSE;
    }
}
#else
BOOL Tracker_Socket_Register_Id_Get_NetworkId(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ret = 0;

    //register app id
    ret = cbm_register_app_id(&soc_content.cbm_app_id);
#if defined(__SOC_DEBUG__)	
    LOGD(L_SOC, L_V5, " ret:%d,app_id:%d", ret, soc_content.cbm_app_id);
#endif/*__SOC_DEBUG__*/

	kal_prompt_trace(MOD_TST,"Tracker_Socket_Register_Id_Get_NetworkId ret:%d,app_id:%d", ret, soc_content.cbm_app_id);

    //get network id
    if(ret == CBM_OK)
    {
	#if defined(__MMI_DUAL_SIM_MASTER__)   //yzq 双卡
        if((!mmi_bootup_is_sim_valid()) && (!mmi_bootup_is_sim2_valid()))
        {
            kal_prompt_trace(MOD_TST, "both of sim1 and sim2 are not valid");
            return FALSE;
        }
        else
        {
            if(mmi_bootup_is_sim_valid())
            {
                kal_prompt_trace(MOD_TST, "mmi_bootup_is_sim_valid");
                if(srv_sim_ctrl_is_available(MMI_SIM1) && srv_nw_info_get_service_availability(MMI_SIM1) == SRV_NW_INFO_SA_FULL_SERVICE)
                {
                    Tracker_socket_set_account_id(CBM_SIM_ID_SIM1);
                    kal_prompt_trace(MOD_TST, "sim1 is valid");
                    kal_prompt_trace(MOD_TST, "soc_content.nwt_account_id=%d,soc_content.cbm_app_id=%d", soc_content.nwt_account_id, soc_content.cbm_app_id);

                }
                else
                {
                    Tracker_socket_set_account_id(CBM_SIM_ID_SIM2);
                    kal_prompt_trace(MOD_TST, "sim1 is not valid");
                    kal_prompt_trace(MOD_TST, "soc_content.nwt_account_id=%d,soc_content.cbm_app_id=%d", soc_content.nwt_account_id, soc_content.cbm_app_id);
                }

            }
            else
            {
                kal_prompt_trace(MOD_TST, "sim is not valid");
                return FALSE;
            }
        }
	#else
		if(!(mmi_bootup_is_sim_valid()))
		{
		#if defined(__SOC_DEBUG__)
		    LOGD(L_SOC, L_V5, " sim is not valid");
		#endif/*__SOC_DEBUG__*/
			kal_prompt_trace(MOD_TST,"sim is not valid");
		    return FALSE;
		}
		else
		{
		#if defined(__SOC_DEBUG__)
		    LOGD(L_SOC, L_V5, " sim is valid");
		#endif/*__SOC_DEBUG__*/
			kal_prompt_trace(MOD_TST,"sim is valid");
		    Tracker_socket_set_account_id(CBM_SIM_ID_SIM1);
		#if defined(__SPECIAL_EPO_SOCKET__)
	        epo_soc_content.cbm_app_id = soc_content.cbm_app_id;
	        epo_soc_content.nwt_account_id= soc_content.nwt_account_id;
		#endif
		}
	#endif

	#if defined(__SOC_DEBUG__)
        LOGD(L_SOC, L_V5, " nwt:%d,app_id:%d", soc_content.nwt_account_id, soc_content.cbm_app_id);
	#endif/*__SOC_DEBUG__*/
	
		kal_prompt_trace(MOD_TST,"nwt:%d,app_id:%d", soc_content.nwt_account_id, soc_content.cbm_app_id);
        AlreadyGetNetworkId = TRUE;
        return TRUE;
    }
    else
    {
        AlreadyGetNetworkId = FALSE;
        //必须要清除才可以，不然从有信号的地方到无信号的地方会
        //一直连不上网络。
        ret = cbm_deregister_app_id(soc_content.cbm_app_id);

	#if defined(__SOC_DEBUG__)	
        LOGD(L_SOC, L_V5, " app_id:%d,ret:%d", soc_content.cbm_app_id, ret);
	#endif/*__SOC_DEBUG__*/
	
		kal_prompt_trace(MOD_TST,"app_id:%d,ret:%d", soc_content.cbm_app_id, ret);
        return FALSE;
    }
}
#endif

/******************************************************************************
 *  Function    -  Tracker_Socket_Check_Recover_Connect
 *
 *  Purpose     -  GPRS关闭后，定时检测网络信号，网络信号恢复之后
 *                       要重新开始GPRS连接
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2014-07-18,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Socket_Check_Recover_Connect(void)
{
    MYTIME currTime;

    GetDateTime(&currTime);

#if defined(__SOC_DEBUG__)
    LOGD(L_OS, L_V5, " CheckCon %d:%d  (gsm:%d,soc:%d,sim:%d)", currTime.nHour, currTime.nMin, sys_gsm_state, soc_content.soc_state, mmi_bootup_is_sim_valid());
#endif/*__SOC_DEBUG__*/

    StopTimer(TRACKER_SOCKET_RECOVER_CONNCET_TIMER);
    if(mmi_bootup_is_sim_valid() == MMI_FALSE || tracker_ctrl_data.GPRSAlwaysOn == 0)
    {
        StartTimer(TRACKER_SOCKET_RECOVER_CONNCET_TIMER, 10 * 60 * 1000, Tracker_Socket_Check_Recover_Connect);
    }
    else
    {
        /*如果是连接的，则5分钟后再来检测*/
        if(soc_content.soc_state == SOC_CONNECTED)
        {
            StartTimer(TRACKER_SOCKET_RECOVER_CONNCET_TIMER, 5 * 60 * 1000, Tracker_Socket_Check_Recover_Connect);
        }
        else
        {
            //gsm无信号
            if(sys_gsm_state == GSM_NO_SIGNAL_STATE)
            {
                Tracker_Socket_TCP_Close();

			#if defined(__SOC_DEBUG__)	
                LOGD(L_OS, L_V5, "  (GSM No Signal!)");
			#endif/*__SOC_DEBUG__*/
			
                if(IsMyTimerExist(TRACKER_SOCKET_HEARTBEAT_OVERTIME))
                {
                    StopTimer(TRACKER_SOCKET_HEARTBEAT_OVERTIME);
                }

                if(IsMyTimerExist(TRACKER_SOCKET_CONNECT_OVERTIMER))
                {
                    StopTimer(TRACKER_SOCKET_CONNECT_OVERTIMER);
                }
                StartTimer(TRACKER_SOCKET_RECOVER_CONNCET_TIMER, 60 * 1000, Tracker_Socket_Check_Recover_Connect);
            }
            //gsm从无信号到有信号要重新联网
            else
            {
                Tracker_Socket_TCP_Close();
                StopTimer(TRACKER_SOCKET_START_TIMER);
                StartTimer(TRACKER_SOCKET_START_TIMER, 5 * 1000, Tracker_Socket_TCP_Start);
                StartTimer(TRACKER_SOCKET_RECOVER_CONNCET_TIMER, 5 * 60 * 1000, Tracker_Socket_Check_Recover_Connect);
            }
        }
    }
}

/******************************************************************************
 *  Function    -  Tracker_Socket_Block_Process
 *
 *  Purpose     -  GPRS阻塞报警处理
 *
 *  Description -  链接次数大于设定的次数
 *
 * modification history  2013-01-28 guojie written
 * ----------------------------------------
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Socket_Block_Process(void)
{
    S16 Error;

    soc_content.connect_overtimes ++;

#if defined(__SOC_DEBUG__)	
    LOGD(L_OS, L_V5, "   ( times:%d,%d)", soc_content.connect_overtimes, tracker_ctrl_data.gprs_relink_times);
#endif/*__SOC_DEBUG__*/

    if(soc_content.connect_overtimes >= tracker_ctrl_data.gprs_relink_times)
    {
        soc_content.connect_overtimes = 0;
        //连接三次失败启用DNS解析,只有设定为域名连接才启用域名解析
        if(tracker_server_param.IsSaveIP)
        {
            tracker_server_param.IsSaveIP = 0;

		#if defined(__GT02R_GM__)&&defined(__OLD_PROTOCOL__)
            memset(tracker_server_param.server_ip, 0, sizeof(tracker_server_param.server_ip));
            tracker_server_param.conipinfo = 0;
		#endif
            WriteRecord(NVRAM_EF_TRACKER_SERVER_LID, 1, (void *)&tracker_server_param, NVRAM_EF_TRACKER_SERVER_SIZE, &Error);
        }

        if(!IsMyTimerExist(TRACKER_SOCKET_CONNECT_OVERTIMER))
        {
            StartTimer(TRACKER_SOCKET_CONNECT_OVERTIMER, 10 * 60 * 1000, Tracker_Soc_Reset);
        }

        if(tracker_ctrl_data.gprs_block_alarm == 1)
        {
			StartTimer(TRACKER_SEND_GPRS_BLOCKSMS_TIMER, 1000, Tracker_GPRS_Block_Alarm_Sms);
        }
    }
    Tracker_Socket_TCP_Close();
    StartTimer(TRACKER_SOCKET_CONNECT_TIMER, 5000, Tracker_Socket_TCP_ReConnect);
}

/******************************************************************************
 *  Function    -  Tracker_Socket_OutputResult
 *
 *  Purpose     -
 *
 *  Description - 2014-08-19 测试遇到解析域名一直失败，重启才恢复
 *
 * modification history
 ******************************************************************************/
static void Tracker_Socket_OutputResult(mmi_soc_con_app_result ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__SOC_DEBUG__)
    LOGD(L_SOC, L_V5, " ret:%d", ret);
#endif/*__SOC_DEBUG__*/

	kal_prompt_trace(MOD_TST,"Tracker_Socket_OutputResult, ret is:%d", ret);

    if(ret == SOC_CON_ERROR)
    {
    #if defined(__SOC_DEBUG__)
        LOGD(L_OS, L_V5, "    :return  fail!");
	#endif/*__SOC_DEBUG__*/
	
        Tracker_Socket_TCP_Close();

        StartTimer(TRACKER_SOCKET_CONNECT_TIMER, 5000, Tracker_Socket_TCP_ReConnect);
    }
    else if(ret == SOC_DNS_SUCCESS)
    {
        StartTimer(TRACKER_SOCKET_CONNECT_TIMER, 1000, Tracker_Socket_TCP_Connect);
    }

}

/******************************************************************************
 *  Function    -  Tracker_Socket_Notify_OverTime
 *
 *  Purpose     -
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2013-01-26,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Socket_Notify_OverTime(void)
{
#if defined(__SOC_DEBUG__)
    LOGD(L_SOC, L_V5, "Tracker_Socket_Notify_OverTime");
#endif/*__SOC_DEBUG__*/

    Tracker_Socket_OutputResult(SOC_CON_ERROR);
}

/******************************************************************************
 *  Function    -  Tracker_Socket_Http_GetUrl
 *
 *  Purpose     -GPRS域名解析
 *
 *  Description -
 *
 * modification history
 ******************************************************************************/
static void Tracker_Socket_Http_GetUrl(const kal_int8 *in_str, int str_len, http_url_struct * purl_parsed_info)
{
    char *hostname = NULL;
    char port_str[10] = {0};

    if(!purl_parsed_info)
    {
        return;
    }
#if defined(__SOC_DEBUG__)
    LOGD(L_SOC, L_V5, " :%s", in_str);
#endif/*__SOC_DEBUG__*/

    hostname = strstr((char*)in_str, "http://");
    if(!hostname)
    {
        return;
    }
    else
    {
        char *slash, *colon;

        hostname += 7;  /* strlen(http://) */
        slash = strchr(hostname, '/');
        if(!slash)
        {
            colon = strchr(hostname, ':');
            if(colon)
            {
                purl_parsed_info->host_name_len = (colon - hostname);
                memcpy(purl_parsed_info->host_name, hostname, purl_parsed_info->host_name_len);
                purl_parsed_info->ser_port_num = atoi(colon + 1);
			#if defined(__SOC_DEBUG__)	
                LOGD(L_SOC, L_V5, " ^1^ %d", purl_parsed_info->ser_port_num);
			#endif/*__SOC_DEBUG__*/
            }
            else
            {
                purl_parsed_info->ser_port_num = 80;
                purl_parsed_info->host_name_len = strlen(hostname);
                memcpy(purl_parsed_info->host_name, hostname, purl_parsed_info->host_name_len);
			#if defined(__SOC_DEBUG__)
				LOGD(L_SOC, L_V5, " ^2^ %d", purl_parsed_info->ser_port_num);
			#endif/*__SOC_DEBUG__*/
            }
        }
        else
        {
            colon = strchr(hostname, ':');
            if(colon)
            {
                memset(port_str, 0, sizeof(port_str));
                purl_parsed_info->host_name_len = colon - hostname;
                memcpy(purl_parsed_info->host_name, hostname, purl_parsed_info->host_name_len);

                strncpy(port_str, colon + 1, slash - colon - 1);
                purl_parsed_info->ser_port_num = atoi(port_str);
			#if defined(__SOC_DEBUG__)
				LOGD(L_SOC, L_V5, " ^3^ %d", purl_parsed_info->ser_port_num);
			#endif/*__SOC_DEBUG__*/
            }
            else
            {
                purl_parsed_info->ser_port_num = 80;
                purl_parsed_info->host_name_len = slash - hostname;
                memcpy(purl_parsed_info->host_name, hostname, purl_parsed_info->host_name_len);
			#if defined(__SOC_DEBUG__)
				LOGD(L_SOC, L_V5, " ^4^ %d", purl_parsed_info->ser_port_num);
			#endif/*__SOC_DEBUG__*/
            }
            purl_parsed_info->url_link_len = strlen(slash);
            memcpy(purl_parsed_info->url_link, slash, strlen(slash));
        }
    }
}

/******************************************************************************
 *  Function    -  Tracker_Socket_DNS_GetHostByName_Ind
 *
 *  Purpose     -
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-11-03,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Socket_DNS_GetHostByName_Ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_soc_get_host_by_name_ind_struct *dns_ind;
    S16 Error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!inMsg)
    {
        Tracker_Socket_OutputResult(SOC_CON_ERROR);
        return;
    }

    dns_ind = (app_soc_get_host_by_name_ind_struct*) inMsg;

    /* Check if the result is OK */
    if(dns_ind->result == KAL_TRUE)
    {
    #if defined(__SOC_DEBUG__)
        LOGD(L_SOC, L_V5, "  %d,IP=%d.%d.%d.%d:%d", dns_ind->result,
             dns_ind->addr[0],
             dns_ind->addr[1],
             dns_ind->addr[2],
             dns_ind->addr[3],
             soc_content.url_parsed_info.ser_port_num);
	#endif/*__SOC_DEBUG__*/
	
        //静态域名缓存IP
        memset(tracker_server_param.server_ip, 0, sizeof(tracker_server_param.server_ip));
        memcpy(tracker_server_param.server_ip, dns_ind->addr, dns_ind->addr_len);
        tracker_server_param.server_port = soc_content.url_parsed_info.ser_port_num;

        tracker_login_info.used_domain_login = KAL_FALSE;
        tracker_login_info.used_ip_login_fail_time = 0;

        tracker_server_param.IsSaveIP = 1;

        WriteRecord(NVRAM_EF_TRACKER_SERVER_LID, 1, (void *)&tracker_server_param, NVRAM_EF_TRACKER_SERVER_SIZE, &Error);
        Tracker_Socket_OutputResult(SOC_DNS_SUCCESS);
    }
    else
    {
        Tracker_Socket_OutputResult(SOC_CON_ERROR);
    }


}
/******************************************************************************
 *  Function    -  Tracker_Socket_DNS_GetHostByName
 *
 *  Purpose     -  域名获取IP
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-11-03,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Socket_DNS_GetHostByName(const kal_uint8 *hostname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    char rcvd_buffer[200] = {0};
    kal_uint32 rcvd_counter = 0;
    S16 Error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = soc_gethostbyname(
              KAL_FALSE,
              MOD_MMI,
              (kal_int32) 1,
              (kal_char*) hostname,
              (kal_uint8*) &rcvd_buffer,
              (kal_uint8*) &rcvd_counter,
              0,
              soc_content.nwt_account_id);

#if defined(__SOC_DEBUG__)
	LOGD(L_SOC, L_V5, "hostname is:%s, ret is:%d", hostname, ret);
#endif/*__SOC_DEBUG__*/

    if(ret == SOC_SUCCESS)
    {
        sprintf(
            (char*)soc_content.soc_addr.addr,
            "%d.%d.%d.%d",
            rcvd_buffer[0],
            rcvd_buffer[1],
            rcvd_buffer[2],
            rcvd_buffer[3]);
	#if defined(__SOC_DEBUG__)
        LOGD(L_SOC, L_V5, "DNS SUCCESS  %s", soc_content.soc_addr.addr);
	#endif/*__SOC_DEBUG__*/
	
        soc_content.soc_addr.addr_len = 4;

	#if defined(__NEW_PROTOCOL__)||(defined(__OLD_PROTOCOL__)&&defined(__GT02R_TQ__))
        //静态域名缓存IP
        memset(tracker_server_param.server_ip, 0, sizeof(tracker_server_param.server_ip));
        memcpy(tracker_server_param.server_ip, rcvd_buffer, 4);
        tracker_server_param.server_port = soc_content.url_parsed_info.ser_port_num;
        tracker_server_param.IsSaveIP = 1;
        WriteRecord(NVRAM_EF_TRACKER_SERVER_LID, 1, (void *)&tracker_server_param, NVRAM_EF_TRACKER_SERVER_SIZE, &Error);
	#endif
        Tracker_Socket_OutputResult(SOC_DNS_SUCCESS);
    }
    else if(ret == SOC_WOULDBLOCK)
    {
        /* waits for APP_SOC_GET_HOST_BY_NAME_IND */
        SetProtocolEventHandler(Tracker_Socket_DNS_GetHostByName_Ind, MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND);
    }
    else
    {
        Tracker_Socket_OutputResult(SOC_CON_ERROR);
    }

}
/******************************************************************************
 *  Function    -  Tracker_Socket_DNS_Parse
 *
 *  Purpose     -  DNS解析
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-11-03,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Socket_DNS_Parse(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char temp1[DOMAIN_URL_MAX_LENGTH];
    char temp2[DOMAIN_URL_MAX_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp1 , 0 , sizeof(temp1));
    memset(temp2 , 0 , sizeof(temp2));
    memset(&soc_content.url_parsed_info, 0, sizeof(http_url_struct));//xb add 2014-8-13 先初始化
    sprintf((char *)temp1, "http://");

    sprintf((char *)temp2, ":%d", tracker_server_param.server_port);
    strcat((char *)temp1, (char *)tracker_server_param.url);
    strcat((char *)temp1, temp2);
#if defined(__SOC_DEBUG__)
    LOGD(L_OS, L_V5, " %s", temp1);
#endif/*__SOC_DEBUG__*/
    memset(soc_content.http_url, 0, sizeof(soc_content.http_url));
    memcpy(soc_content.http_url, temp1, strlen(temp1));
    soc_content.http_url_len = strlen(temp1);

    Tracker_Socket_Http_GetUrl(soc_content.http_url, soc_content.http_url_len, &soc_content.url_parsed_info);

    if(soc_content.url_parsed_info.ser_port_num != 0)
    {
        Tracker_Socket_DNS_GetHostByName((kal_uint8*)soc_content.url_parsed_info.host_name);
    }
    else
    {
        Tracker_Socket_OutputResult(SOC_CON_ERROR);
    }
}


/******************************************************************************
 *  Function    -  Tracker_Socket_TCP_Start
 *
 *  Purpose     -  Socket 连接开始
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-11-03,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Socket_TCP_Start(void)
{
    /*检测到无SIM不进行网络连接*/
    if(mmi_bootup_is_sim_valid() == MMI_FALSE)
    {
    #if defined(__SOC_DEBUG__)
        LOGD(L_SOC, L_V5, "no sim");
	#endif/*__SOC_DEBUG__*/
		kal_prompt_trace(MOD_TST,"Tracker_Socket_TCP_Start no sim");

	#if 0
        /*检测不到SIM也重启，防止出现掉卡情况2014-09-01*/
        if(!IsMyTimerExist(TRACKER_SOCKET_CONNECT_OVERTIMER) && (tracker_ctrl_data.GPRSAlwaysOn == 1))
        {
		#if defined(__NEW_PROTOCOL__)
            StartTimer(TRACKER_SOCKET_CONNECT_OVERTIMER, 20*60*1000, Tracker_Soc_Reset);
		#elif defined(__OLD_PROTOCOL__)
            StartTimer(TRACKER_SOCKET_CONNECT_OVERTIMER, 10*60*1000, Tracker_Soc_Abnormal_Reset);
		#endif
        }
	#endif
	
        return;
    }
#if defined(__SOC_DEBUG__)
    LOGD(L_SOC, L_V5, " %d", sys_gsm_state);
#endif/*__SOC_DEBUG__*/
	kal_prompt_trace(MOD_TST,"Tracker_Socket_TCP_Start, %d", sys_gsm_state);

    //在无信号的地方，不启动联网
    if(srv_nw_info_get_service_availability(MMI_SIM1) != SRV_NW_INFO_SA_FULL_SERVICE)
    {
        StartTimer(TRACKER_SOCKET_START_TIMER, 30 * 1000, Tracker_Socket_TCP_Start);
        return;
    }

	kal_prompt_trace(MOD_TST,"old vec_socket_send is:%d", vec_socket_send);

    if(NULL == vec_socket_send)
    {
        VECTOR_CreateInstance(vec_socket_send);
    }

	kal_prompt_trace(MOD_TST,"new vec_socket_send is:%d", vec_socket_send);

    /*无论联网不连网状态，都需要获取网络ID，才能创建成功*/
    if(Tracker_Socket_Register_Id_Get_NetworkId() == TRUE)
    {
        /*常连接时才创建网络连接*/
        if(tracker_ctrl_data.GPRSAlwaysOn == 1)
        {
            Tracker_Socket_TCP_ReStart();
        }
    }
    else
    {
        if(!IsMyTimerExist(TRACKER_SOCKET_REGISTER_TIMER) && (soc_content.nwt_account_id == 0))
        {
            StartTimer(TRACKER_SOCKET_REGISTER_TIMER, 30 * 1000, Tracker_Socket_TCP_Start);
        }
    }

    if(!IsMyTimerExist(TRACKER_SOCKET_CONNECT_OVERTIMER) && (tracker_ctrl_data.GPRSAlwaysOn == 1))
    {
	#if defined(__NEW_PROTOCOL__)
        StartTimer(TRACKER_SOCKET_CONNECT_OVERTIMER, 20*60*1000, Tracker_Soc_Reset);
	#elif defined(__OLD_PROTOCOL__)
        StartTimer(TRACKER_SOCKET_CONNECT_OVERTIMER, 10*60*1000, Tracker_Soc_Abnormal_Reset);
	#endif
    }
}

/******************************************************************************
 *  Function    -  Tracker_Socket_TCP_Create
 *
 *  Purpose     -  Create 连接
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-09-27,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static BOOL Tracker_Socket_TCP_Create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 val = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    soc_content.soc_id = soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0, MOD_MMI, soc_content.nwt_account_id);

    if(soc_content.soc_id >= 0)
    {
    #if defined(__SOC_DEBUG__)
        LOGD(L_SOC, L_V5, " nwk:%d,app_id:%d,soc_id:%d", soc_content.nwt_account_id, soc_content.cbm_app_id, soc_content.soc_id);
	#endif/*__SOC_DEBUG__*/
		kal_prompt_trace(MOD_TST," nwk:%d,app_id:%d,soc_id:%d", soc_content.nwt_account_id, soc_content.cbm_app_id, soc_content.soc_id);

        //set socket option
        if(soc_setsockopt(soc_content.soc_id, SOC_NBIO, &val, sizeof(val)) < 0)
        {
        #if defined(__SOC_DEBUG__)
            LOGD(L_SOC, L_V5, " TCP_Create Set socket to nonblock mode error !!");
		#endif/*__SOC_DEBUG__*/
			kal_prompt_trace(MOD_TST," TCP_Create Set socket to nonblock mode error !!");
        }
        val = SOC_READ | SOC_WRITE | SOC_CLOSE | SOC_CONNECT;
        if(soc_setsockopt(soc_content.soc_id, SOC_ASYNC, &val, sizeof(val)) < 0)
        {
        #if defined(__SOC_DEBUG__)
            LOGD(L_SOC, L_V5, " TCP_Create Set socket to nonblock mode error !!");
		#endif/*__SOC_DEBUG__*/
			kal_prompt_trace(MOD_TST," TCP_Create Set socket to nonblock mode error !!");
        }
        SetProtocolEventHandler(Tracker_Socket_Notify, MSG_ID_APP_SOC_NOTIFY_IND);
		kal_prompt_trace(MOD_TST," TCP_Create Success!");
        soc_content.soc_state = SOC_STATE_CREATED;
        soc_content.sendstate = SOCKET_CREATED;
        return TRUE;
    }
    else
    {
    #if defined(__SOC_DEBUG__)
        LOGD(L_SOC, L_V5, " TCP_Create Fail!");
	#endif/*__SOC_DEBUG__*/
		kal_prompt_trace(MOD_TST," TCP_Create Fail!");
        return FALSE;
    }
}

#if defined(__GT02R_GM__)&&defined(__OLD_PROTOCOL__)
/******************************************************************************
 *  Function    -  Tracker_Socket_Connect_Save_GetIp
 *
 *  Purpose     -  能连上的IP保存起来
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2014-08-27, guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Socket_Connect_Save_GetIp(void)
{
    S16 Error;

    if(tracker_server_param.conipinfo == 0)
    {
        //静态域名缓存IP
        memset(tracker_server_param.server_ip, 0, sizeof(tracker_server_param.server_ip));
        memcpy(tracker_server_param.server_ip, GT02A_GetIP.server_ip, 4);
        tracker_server_param.server_port = GT02A_GetIP.server_port;
        tracker_server_param.IsSaveIP = 1;
        tracker_server_param.conipinfo = 1;
        WriteRecord(NVRAM_EF_TRACKER_SERVER_LID, 1, (void *)&tracker_server_param, NVRAM_EF_TRACKER_SERVER_SIZE, &Error);

        //Tracker_Socket_Connect_Save_GetIp  GetIp:112.90.87.86:8821//
	#if defined(__SOC_DEBUG__)
        LOGD(L_OS, L_V5, " GetIp:%d.%d.%d.%d:%d", tracker_server_param.server_ip[0], tracker_server_param.server_ip[1],
             tracker_server_param.server_ip[2], tracker_server_param.server_ip[3], tracker_server_param.server_port);
	#endif/*__SOC_DEBUG__*/
    }
}
#endif

/*****************************************************************************
 * FUNCTION			Tracker_Socket_Connect
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *		void
 * RETURNS
 *  		void
 *
 *****************************************************************************/
static void Tracker_Socket_TCP_Connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 sd, ret;
    kal_uint8 val;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_prompt_trace(MOD_TST,"Tracker_Socket_TCP_Connect begin");
    //不支持GPRS连接则不创建
    if(tracker_ctrl_data.GPRSAlwaysOn == 0)
    {
        return;
    }

    memset(soc_content.soc_addr.addr, 0, sizeof(soc_content.soc_addr.addr));
    memcpy(soc_content.soc_addr.addr, tracker_server_param.server_ip, sizeof(tracker_server_param.server_ip));
    soc_content.soc_addr.addr_len = sizeof(tracker_server_param.server_ip);
    soc_content.soc_addr.sock_type = tracker_server_param.soc_type;
    soc_content.soc_addr.port = tracker_server_param.server_port;

    soc_content.sendstate = SOCKET_CREATING;

    /*清发送队列buffer   guojie  2012-06-09*/
    memset(soc_content.snd_buffer, 0, sizeof(soc_content.snd_buffer));
    soc_content.snd_counter = 0;
    soc_content.snd_data_len = 0;
#if defined(__SOC_DEBUG__)
    LOGD(L_OS, L_V5, " SOC  Connect to IP:%d.%d.%d.%d:%d,soc_id:%d",
         soc_content.soc_addr.addr[0],
         soc_content.soc_addr.addr[1],
         soc_content.soc_addr.addr[2],
         soc_content.soc_addr.addr[3],
         soc_content.soc_addr.port, soc_content.soc_id);
#endif/*__SOC_DEBUG__*/
	kal_prompt_trace(MOD_TST,"SOC Connect to IP:%d.%d.%d.%d:%d,soc_id:%d",
         soc_content.soc_addr.addr[0],
         soc_content.soc_addr.addr[1],
         soc_content.soc_addr.addr[2],
         soc_content.soc_addr.addr[3],
         soc_content.soc_addr.port, soc_content.soc_id);
	
    if(soc_content.soc_state == SOC_STATE_CREATED)
    {
        ret = soc_connect(soc_content.soc_id, &soc_content.soc_addr);
        if(ret == SOC_SUCCESS)
        {
            soc_content.soc_state = SOC_CONNECTED;
            soc_content.sendstate = SOCKET_CONNECTED;

		#if defined(__LED_APP__)
            if(IS_IN_CALL())
            {
                if(sys_gsm_state != GSM_CALLING_STATE)
                {
                    sys_gsm_state = GSM_CALLING_STATE ;
                    LED_GSM_StatusSet(sys_gsm_state);
                }
            }
            else
            {
                if(sys_gsm_state != GSM_GRPS_CONNECT_STATE)
                {
                    sys_gsm_state = GSM_GRPS_CONNECT_STATE;
                    LED_GSM_StatusSet(sys_gsm_state);
                }
            }
		#endif /*__LED_APP__*/
		
            tracker_login_info.Success = FALSE;
		#if defined(__OLD_PROTOCOL__)
			gprs_send_type = GPRS_STATUS_INFO;
		#else
			gprs_send_type = GPRS_LOGIN_INFO;
		#endif
		
            Tracker_Socket_Send_Current_Data();
            Tracker_Socket_OutputResult(SOC_CON_SUCCESS);
		#if defined(__SOC_DEBUG__)	
            LOGD(L_SOC, L_V5, " SOC Connect Success!:%d", ret);
		#endif/*__SOC_DEBUG__*/
			kal_prompt_trace(MOD_TST," SOC Connect Success!:%d", ret);
        }
        else  if(ret == SOC_WOULDBLOCK)
        {
        #if defined(__SOC_DEBUG__)
            LOGD(L_OS, L_V5, " SOC  fail! :%d", ret);
		#endif/*__SOC_DEBUG__*/
			kal_prompt_trace(MOD_TST," SOC  fail! :%d", ret);
            //网络不好时，soc一直没有 MSG_ID_APP_SOC_NOTIFY_IND 消息上来
            //正常情况1分钟内MSG_ID_APP_SOC_NOTIFY_IND 消息上来
            if(!IsMyTimerExist(TRACKER_SOCKET_NOTIFY_OVERTIMER))
            {
                StartTimer(TRACKER_SOCKET_NOTIFY_OVERTIMER, 5 * 60 * 1000, Tracker_Socket_Notify_OverTime);
            }

            SetProtocolEventHandler(Tracker_Socket_Notify, MSG_ID_APP_SOC_NOTIFY_IND);
        }
        else
        {
            Tracker_Socket_OutputResult(SOC_CON_ERROR);
        }
    }

}

/******************************************************************************
 *  Function    -  Tracker_Socket_Notify
 *
 *  Purpose     - 网络回调
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-09-19,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
void Tracker_Socket_Notify(void * inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_soc_notify_ind_struct *soc_notify = (app_soc_notify_ind_struct*) inMsg;
    kal_int8 ret;

	kal_prompt_trace(MOD_TST,"Tracker_Socket_Notify begin");

    if(soc_notify->socket_id != soc_content.soc_id)
    {
	#if defined(__SPECIAL_EPO_SOCKET__)
        if(soc_notify->socket_id == epo_soc_content.soc_id)
        {
            Tracker_EPO_Socket_Notify(inMsg);
		#if defined(__SOC_DEBUG__)
            LOGD(L_SOC, L_V5, "EPO Notify return id:%d,epo:%d,soc:%d", soc_notify->socket_id, epo_soc_content.soc_id, soc_content.soc_id);
		#endif/*__SOC_DEBUG__*/
			kal_prompt_trace(MOD_TST,"EPO Notify return id:%d,epo:%d,soc:%d", soc_notify->socket_id, epo_soc_content.soc_id, soc_content.soc_id);
        }
	#elif defined(__SPECIAL_AGPS_SOCKET__)
        if(soc_notify->socket_id == agps_soc_content.soc_id)
        {
            Tracker_AGPS_Socket_Notify(inMsg);
		#if defined(__SOC_DEBUG__)
            LOGD(L_SOC, L_V5, "AGPS Notify return id:%d,agps:%d,soc:%d", soc_notify->socket_id, agps_soc_content.soc_id, soc_content.soc_id);
		#endif/*__SOC_DEBUG__*/
			kal_prompt_trace(MOD_TST,"AGPS Notify return id:%d,agps:%d,soc:%d", soc_notify->socket_id, agps_soc_content.soc_id, soc_content.soc_id);
        }
	#endif
        return ;
    }
#if defined(__SOC_DEBUG__)
    LOGD(L_SOC, L_V5, "   type:%d,id:%d", soc_notify->event_type, soc_notify->socket_id);
#endif/*__SOC_DEBUG__*/
	kal_prompt_trace(MOD_TST,"type:%d,id:%d", soc_notify->event_type, soc_notify->socket_id);

    switch(soc_notify->event_type)
    {
    case SOC_WRITE:
        break;

    case SOC_READ:
        Tracker_Socket_TCP_Receive();
        break;

    case SOC_CONNECT:
        if(soc_notify->result)
        {
            soc_content.connect_overtimes = 0;
            soc_content.soc_state = SOC_CONNECTED;
            soc_content.sendstate =  SOCKET_CONNECTED;
            Tracker_Socket_OutputResult(SOC_CON_SUCCESS);
		#if defined(__SOC_DEBUG__)
            LOGD(L_OS, L_V5, "SOC connect success,%d", soc_notify->result);
		#endif/*__SOC_DEBUG__*/
			kal_prompt_trace(MOD_TST,"SOC connect success,%d", soc_notify->result);
		#if defined(__LED_APP__)
			if(IS_IN_CALL())
            {
                if(sys_gsm_state != GSM_CALLING_STATE)
                {
                    sys_gsm_state = GSM_CALLING_STATE ;
                }
                LED_GSM_StatusSet(sys_gsm_state);
            }
            else
            {
                if(sys_gsm_state != GSM_GRPS_CONNECT_STATE)
                {
                    sys_gsm_state = GSM_GRPS_CONNECT_STATE;
                }
                LED_GSM_StatusSet(sys_gsm_state);
            }
		#endif

		#if defined(__NEW_PROTOCOL__)
            tracker_login_info.Success = FALSE;
            tracker_login_info.used_domain_login = FALSE;

            gprs_send_type =  GPRS_LOGIN_INFO;
            Tracker_Socket_Send_Current_Data();
		#elif defined(__OLD_PROTOCOL__)
		#if defined(__GT02R_TQ__)       //静态域名
            //待增加代码处理
            tracker_login_info.Success = FALSE;
            gprs_send_type =  GPRS_STATUS_INFO;
		#if defined(__GPS_ON_MTK__)//ylm 11.19
			//StopTimer(GPRS_SEND_GPS_TIMMER);
			if(!IsMyTimerExist(GPS_DISTANCE_DETECT_TIMER))
				StartTimer(GPS_DISTANCE_DETECT_TIMER, 10*1000, Tracker_Detect_Distance_According_To_Time);
		#endif  /*__GPS_ON_MTK__*/
            Tracker_Socket_Send_Current_Data();
		#elif defined(__GT02R_GM__)   //动态域名获取IP
            if((tracker_server_param.conipinfo == 0) && (GT02A_GetIP.get_ip == 0)) //连接的是域名
            {
                gprs_send_type =  GPRS_GETIP_INFO;
                Tracker_Socket_Send_Current_Data();
            }
            else
            {
                tracker_login_info.Success = FALSE;
                gprs_send_type =  GPRS_STATUS_INFO;
                Tracker_Socket_Send_Current_Data();

                //保存能连上的IP
                Tracker_Socket_Connect_Save_GetIp();
            }
		#endif
		#endif
        }
        else     //SIM卡信号不好会走到这里
        {
        #if defined(__SOC_DEBUG__)
            LOGD(L_OS, L_V5, " SOCconnect fail!!!,%d", soc_notify->result);
		#endif/*__SOC_DEBUG__*/

			Tracker_DW_Query_Connect_Abnormal();
		
            Tracker_Socket_Block_Process();
        }

        if(IsMyTimerExist(TRACKER_SOCKET_NOTIFY_OVERTIMER))
        {
            StopTimer(TRACKER_SOCKET_NOTIFY_OVERTIMER);
        }
        break;

    case SOC_CLOSE:
	#if defined(__SOC_DEBUG__)
		LOGD(L_OS, L_V5, "    Server Close Socket");
	#endif/*__SOC_DEBUG__*/
		Tracker_Socket_TCP_Close();
		StartTimer(TRACKER_SOCKET_CONNECT_TIMER, 5000, Tracker_Socket_TCP_ReConnect);
        break;

    default:
        break;
    }
}

#if defined(__NEW_PROTOCOL__)
/******************************************************************************
 *  Function    -  Tracker_Server_Feedback_Packet
 *
 *  Purpose     -  从服务器收到数据
 *
 *  Description - 如果先发了一个状态包，服务器没回复之前又发了一个
 *                      LBS信息包，则服务回复一个10字节数据,协议数据不是0x13
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2012-06-06,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Server_Feedback_Packet(void)
{
#if defined(__SOC_DEBUG__)
    LOGD(L_OS, L_V5, "  (have status packet replay!)");
#endif/*__SOC_DEBUG__*/

    if(StatusReplyProcess == FALSE)
    {
        return;
    }

    soc_content.connect_overtimes = 0;
    Heartbeat_SendTimes = 0;


    if(IsMyTimerExist(TRACKER_SOCKET_INIT_TIMER))
    {
        StopTimer(TRACKER_SOCKET_INIT_TIMER);
    }
    if(IsMyTimerExist(TRAKCER_SOCKET_CALL_TIMER))
    {
        StopTimer(TRAKCER_SOCKET_CALL_TIMER);
    }

    if(IsMyTimerExist(TRACKER_SOCKET_HEARTBEAT_OVERTIME))
    {
        StopTimer(TRACKER_SOCKET_HEARTBEAT_OVERTIME);
    }

    if(IsMyTimerExist(TRACKER_SOCKET_CONNECT_OVERTIMER))
    {
        StopTimer(TRACKER_SOCKET_CONNECT_OVERTIMER);
    }

#if defined(__GPSBACKUP_BTWTWOHEART__)
    memset(&Backup_GPS_LBS_Info, 0, sizeof(TRACKER_BACKUP_GPS_LBS_INFORMATION_STRUCT));
    Backup_GPS_LBS_Info.count = 0;
#endif

}

/******************************************************************************
 *  Function    -  Tracker_RecData_IsIntegrity
 *
 *  Purpose     - 检查收到的数据包是否是完整的包
 *                  1.   有头 (78 78 ) /(79 79 )
 *                  2.  有尾(0D 0A)
 *                  3.   包长度+头尾=总长度
 *                  4.   CRC校验码正确
 *                   不是完整包继续等待下一个包拼合后处理
 *                   78 78 1B 04 F6  //UBLOX AGPS 不分包04 F6 = 1270  分两包发送
 *                   78 78 1B 04 86  //UBLOX AGPS 不分包04 86 = 1158 分两包发送500 +658
 *                   78 78 00 B7 97  //长度为两位
 *  Description -
 *                 1.首先判断长度
 *                 2.判断首尾
 *                 3.判断校验
 * modification history
 * ----------------------------------------
 * v1.0  , 2013-10-16,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static TRACKER_RECERROR_TYPE Tracker_RecData_IsIntegrity(void)
{
    U16 crc_temp = 0, ContentLen = 0;
    U8 crc[2];

#if defined(__SOC_DEBUG__)
    LOGD(L_OS, L_V5, "  (%d-%x %x %x %x %x %x %x %x %x %x)",
         Soc_Receive_Data.ContLen, Soc_Receive_Data.Content[0],
         Soc_Receive_Data.Content[1], Soc_Receive_Data.Content[2], Soc_Receive_Data.Content[3],
         Soc_Receive_Data.Content[4], Soc_Receive_Data.Content[5], Soc_Receive_Data.Content[6],
         Soc_Receive_Data.Content[7], Soc_Receive_Data.Content[8], Soc_Receive_Data.Content[9],
         Soc_Receive_Data.Content[10]);
#endif/*__SOC_DEBUG__*/

    if(Soc_Receive_Data.ContLen > 0)
    {
        if((Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-2] == 0x0D) && (Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-1] == 0x0A))
        {
            if(Soc_Receive_Data.ContLen == (6 + Soc_Receive_Data.Content[2] * 256 + Soc_Receive_Data.Content[3]))
            {
                //79 79 00 38 FD 08 98 12 01 0
                //79 79 0 1d fd 3 58 62 60 20
                if((Soc_Receive_Data.Content[0] == 0x79) && (Soc_Receive_Data.Content[1] == 0x79))
                {
                    ContentLen = Soc_Receive_Data.Content[2] * 256 + Soc_Receive_Data.Content[3];
                    memset(recvcrc_buffer, 0, sizeof(recvcrc_buffer));
                    memcpy(recvcrc_buffer, &Soc_Receive_Data.Content[2], ContentLen);
                    crc_temp = GetCrc16((U8 *)&recvcrc_buffer, ContentLen);
                    crc[0] = (U8)(crc_temp / 256);
                    crc[1] = (U8)(crc_temp & 0x00ff);

                    if((Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-4] == crc[0]) && (Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-3] == crc[1]))
                    {
                        return REC_SUCCESS;
                    }
                    else
                    {
					#if defined(__SOC_DEBUG__)
                        LOGD(L_OS, L_V5, " (79 79 CRC errer!%x,%x--%x,%x)", Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-4], Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-3] , crc[0], crc[1]);
					#endif/*__SOC_DEBUG__*/
                        return REC_CRC_ERROR;
                    }
                }
                //78 78 9E 17 98 00 00 00 01 41 44 44 52 45 53 53 26 26 62
                //78 78 9D 17 97 00 00 00 01 41 44 44 52 45 53 53 26 26 7D 27 60 25 54
                else if((Soc_Receive_Data.Content[0] == 0x78) && (Soc_Receive_Data.Content[1] == 0x78))
                {
                    ContentLen = Soc_Receive_Data.Content[2] * 256 + Soc_Receive_Data.Content[3];
                    memset(recvcrc_buffer, 0, sizeof(recvcrc_buffer));
                    memcpy(recvcrc_buffer, &Soc_Receive_Data.Content[2], ContentLen);
                    crc_temp = GetCrc16((U8 *)&recvcrc_buffer, ContentLen);
                    crc[0] = (U8)(crc_temp / 256);
                    crc[1] = (U8)(crc_temp & 0x00ff);

                    if((Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-4] == crc[0]) && (Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-3] == crc[1]))
                    {
                        return REC_SUCCESS;
                    }
                    else
                    {
					#if defined(__SOC_DEBUG__)
                        LOGD(L_OS, L_V5, " (78 78 Long CRC errer!%x,%x--%x,%x)", crc[0], crc[2]);
					#endif/*__SOC_DEBUG__*/
                        return REC_CRC_ERROR;
                    }
                }
                //在线下发指令
                else if((Soc_Receive_Data.Content[0] == 0x88) && (Soc_Receive_Data.Content[1] == 0x88))
                {
                    return REC_SUCCESS;
                }
                else if((Soc_Receive_Data.Content[0] == 0x24) && (Soc_Receive_Data.Content[1] == 0x24))
                {
                    return REC_SUCCESS;
                }
                else
                {
				#if defined(__SOC_DEBUG__)
                    LOGD(L_OS, L_V5, " No Found Head return");
				#endif/*__SOC_DEBUG__*/
                    return REC_HEAD_ERROR;
                }
            }
            //登陆包，状态包，LBS扩展回复包
            else if(Soc_Receive_Data.ContLen == 5 + Soc_Receive_Data.Content[2])
            {
                if((Soc_Receive_Data.Content[0] == 0x78) && (Soc_Receive_Data.Content[1] == 0x78))
                {
                    ContentLen = Soc_Receive_Data.Content[2];
                    memset(recvcrc_buffer, 0, sizeof(recvcrc_buffer));
                    memcpy(recvcrc_buffer, &Soc_Receive_Data.Content[2], ContentLen - 1);
                    crc_temp = GetCrc16((U8 *)&recvcrc_buffer, ContentLen - 1);
                    crc[0] = (U8)(crc_temp / 256);
                    crc[1] = (U8)(crc_temp & 0x00ff);
                    if((Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-4] == crc[0]) && (Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-3] == crc[1]))
                    {
                        return REC_SUCCESS;
                    }
                    else
                    {
					#if defined(__SOC_DEBUG__)
                        LOGD(L_OS, L_V5, " (78 78 short CRC errer!%x,%x--%x,%x)", crc[0], crc[2]);
					#endif/*__SOC_DEBUG__*/
                        return REC_CRC_ERROR;
                    }

                }
                //在线下发指令
                else if((Soc_Receive_Data.Content[0] == 0x88) && (Soc_Receive_Data.Content[1] == 0x88))
                {
                    return REC_SUCCESS;
                }
                else if((Soc_Receive_Data.Content[0] == 0x24) && (Soc_Receive_Data.Content[1] == 0x24))
                {
                    return REC_SUCCESS;
                }
                else
                {
				#if defined(__SOC_DEBUG__)
                    LOGD(L_OS, L_V5, " REC_HEAD_ERROR return");
				#endif/*__SOC_DEBUG__*/
                    return REC_HEAD_ERROR;
                }
            }
            //$$log,
            else if((Soc_Receive_Data.Content[0] == 0x24) && (Soc_Receive_Data.Content[1] == 0x24))
            {
                return REC_SUCCESS;
            }
            else
            {
			#if defined(__SOC_DEBUG__)
                LOGD(L_OS, L_V5, " REC_LEN_ERROR return");
			#endif/*__SOC_DEBUG__*/
                return REC_LEN_ERROR;
            }
        }
        else
        {
		#if defined(__SOC_DEBUG__)
            LOGD(L_OS, L_V5, " REC_END_ERROR return");
		#endif/*__SOC_DEBUG__*/

            return REC_END_ERROR;
        }
    }
    else
    {
	#if defined(__SOC_DEBUG__)
        LOGD(L_OS, L_V5, " (receive data length is zero!)");
	#endif/*__SOC_DEBUG__*/
        return REC_LENZERO_ERROR;
    }
}



/******************************************************************************
 *  Function    -  Tracker_RecData_JudgeType
 *
 *  Purpose     -  判断是否是那种包回复
 *
 *
 *  Description -  必须按包长度、头、协议号、尾来解析
 *                       否则出现因当时定协议不完善导致一个协议号当成
 *                       另一个协议号来解析导致重启问题
 * modification history
 * ----------------------------------------
 * v1.0  , 2014-03-13,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static TRACKER_RECDATA_TYPE Tracker_RecData_JudgeType(void)
{
    //787805010001d9dc0D0A
    if((Soc_Receive_Data.ContLen == Soc_Receive_Data.Content[2] + 5)
            && (Soc_Receive_Data.Content[0] == 0x78 && Soc_Receive_Data.Content[1] == 0x78)
            && (Soc_Receive_Data.Content[3] == 0x01))
    {
        return TRACKER_LOGIN_REPLY;
    }
    //7878051103f2b3350D0A  单独LBS包回复
    else if((Soc_Receive_Data.ContLen == Soc_Receive_Data.Content[2] + 5)
            && (Soc_Receive_Data.Content[0] == 0x78 && Soc_Receive_Data.Content[1] == 0x78)
            && Soc_Receive_Data.Content[3] == 0x11)
    {
        return TRACKER_LBS_REPLY;
    }
    else if((Soc_Receive_Data.ContLen == Soc_Receive_Data.Content[2] + 5)
            && (Soc_Receive_Data.Content[0] == 0x78 && Soc_Receive_Data.Content[1] == 0x78)
            && Soc_Receive_Data.Content[3] == 0x18)
	{
		return TRACKER_LBS_EXPAND_REPLY;
	}
    //7878051303f317040D0A
    else if((Soc_Receive_Data.ContLen == Soc_Receive_Data.Content[2] + 5)
            && (Soc_Receive_Data.Content[0] == 0x78 && Soc_Receive_Data.Content[1] == 0x78)
            && (Soc_Receive_Data.Content[3] == 0x13 && Soc_Receive_Data.ContLen == 10))
    {
        return TRACKER_STATUS_REPLY;
    }
    else if((Soc_Receive_Data.ContLen == Soc_Receive_Data.Content[2] + 5)
            && (Soc_Receive_Data.Content[0] == 0x78 && Soc_Receive_Data.Content[1] == 0x78)
            && Soc_Receive_Data.Content[3] == 0x1F)
    {
        return TRACKER_ADJUSTTIME_REPLY;
    }
    else if((Soc_Receive_Data.ContLen == Soc_Receive_Data.Content[2] + 5)
            && (Soc_Receive_Data.Content[0] == 0x78 && Soc_Receive_Data.Content[1] == 0x78)
            && (Soc_Receive_Data.Content[3] == 0x80))
    {
        return TRACKER_ONLINECOM_SET;
    }
    //在线下发
    else if((Soc_Receive_Data.ContLen == Soc_Receive_Data.Content[2] + 5)
            && (Soc_Receive_Data.Content[0] == 0x88 && Soc_Receive_Data.Content[1] == 0x88)
            && (Soc_Receive_Data.Content[3] == 0x1C))
    {
        return TRACKER_ONLINECOM_SET;
    }
    else if((Soc_Receive_Data.ContLen == Soc_Receive_Data.Content[2] + 5)
            && (Soc_Receive_Data.Content[0] == 0x78 && Soc_Receive_Data.Content[1] == 0x78)
            && (Soc_Receive_Data.Content[3] == 0x81))
    {
        return TRACKER_ONLINECOM_QUERY;
    }
    else if((Soc_Receive_Data.ContLen == Soc_Receive_Data.Content[2] + 5)
            && (Soc_Receive_Data.Content[0] == 0x78 && Soc_Receive_Data.Content[1] == 0x78)
            && (Soc_Receive_Data.Content[3] == 0x16 || Soc_Receive_Data.Content[3] == 0x17
                || Soc_Receive_Data.Content[3] == 0x19 || Soc_Receive_Data.Content[3] == 0x1A))
    {
        return TRACKER_GETCHADRESS_REPLY;
    }
    else if((Soc_Receive_Data.ContLen == (Soc_Receive_Data.Content[2] * 256 + Soc_Receive_Data.Content[3] + 6))
            && (Soc_Receive_Data.Content[0] == 0x78 && Soc_Receive_Data.Content[1] == 0x78)
            && (Soc_Receive_Data.Content[4] == 0x96 || Soc_Receive_Data.Content[4] == 0x97
                || Soc_Receive_Data.Content[4] == 0x99 || Soc_Receive_Data.Content[4] == 0x9A))
    {
        return TRACKER_GETENADRESS_REPLY;
    }

	/****************************************************************
		0x1B 0x9B服务器页面增加电子围栏报警设置，服务器根据终端上传位置，发生进、出围栏状态后，
		主动向终端下发进、出围栏地址信息包，终端将收到报警地址信息通过短信发送给已经设置的亲情号码。
		此告警由服务器主动下发,不判断，直接转发主控
	*****************************************************************/
	else if((Soc_Receive_Data.ContLen == Soc_Receive_Data.Content[2] + 5)
			&& (Soc_Receive_Data.Content[0] == 0x78 && Soc_Receive_Data.Content[1] == 0x78)
			&& (Soc_Receive_Data.Content[3] == 0x1B))
	{
		return TRACKER_FENCE_GETCHADRESS_REPLY;
	}
	else if((Soc_Receive_Data.ContLen == (Soc_Receive_Data.Content[2] * 256 + Soc_Receive_Data.Content[3] + 6))
			&& (Soc_Receive_Data.Content[0] == 0x78 && Soc_Receive_Data.Content[1] == 0x78)
			&& (Soc_Receive_Data.Content[4] == 0x9B))
	{
		return TRACKER_FENCE_GETENADRESS_REPLY;
	}

#if defined(__GPS_ON_MTK__)
    //78780510000451380D0A  单独GPS包回复
    else if((Soc_Receive_Data.ContLen == Soc_Receive_Data.Content[2] + 5)
            && (Soc_Receive_Data.Content[0] == 0x78 && Soc_Receive_Data.Content[1] == 0x78)
            && Soc_Receive_Data.Content[2] == 0x10)
    {
        return TRACKER_GPS_REPLY;
    }
#if defined(__AGPS_EPO_SUPPORT__)
    else if((Soc_Receive_Data.ContLen == Soc_Receive_Data.Content[2] + 5)
            && (Soc_Receive_Data.Content[0] == 0x78 && Soc_Receive_Data.Content[1] == 0x78)
            && (Soc_Receive_Data.Content[3] == 0x8B))
    {
        return TRACKER_LATLON_REPLY;
    }
    else if((Soc_Receive_Data.ContLen == (Soc_Receive_Data.Content[2] * 256 + Soc_Receive_Data.Content[3] + 6))
            && (Soc_Receive_Data.Content[0] == 0x79 && Soc_Receive_Data.Content[1] == 0x79)
            && (Soc_Receive_Data.Content[4] == 0xFD))
    {
        return TRACKER_EPOAGPS_REPLY;
    }
#endif/*__AGPS_EPO_SUPPORT__*/
#endif/*__GPS_ON_MTK__*/
#if defined(__LOG_OUTPUT__)&&!defined(WIN32)
    //$$set,   // 24 24 73 65 74 2C   //中转透传工具下发的指令
    //$$SET,  // 24 24 53 45 54 2C
    else if(Soc_Receive_Data.Content[0] == 0x24 && Soc_Receive_Data.Content[1] == 0x24 &&
            Soc_Receive_Data.Content[2] == 0x73 && Soc_Receive_Data.Content[3] == 0x65 &&
            Soc_Receive_Data.Content[4] == 0x74 && Soc_Receive_Data.Content[5] == 0x2C)
    {
        return TRACKER_LOG_OUTPUT;
    }
    else if(Soc_Receive_Data.Content[0] == 0x24 && Soc_Receive_Data.Content[1] == 0x24 &&
            Soc_Receive_Data.Content[2] == 0x53 && Soc_Receive_Data.Content[3] == 0x45 &&
            Soc_Receive_Data.Content[4] == 0x54 && Soc_Receive_Data.Content[5] == 0x2C)
    {
        return TRACKER_LOG_OUTPUT;
    }
#endif
    else
    {
        return TRACKER_RECDATA_OTHER;
    }
}

/******************************************************************************
 *  Function    -  Tracker_Socket_TCP_RecData_Handle
 *
 *  Purpose     -  终端数据处理
 *
 *                      拼包解析
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2013-10-16,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Socket_TCP_RecData_Handle(void)
{
    TRACKER_RECDATA_TYPE currentdatatype;

#if defined(__SOC_DEBUG__)
    LOGD(L_OS, L_V5, "   (Data handle)");
#endif/*__SOC_DEBUG__*/
	kal_prompt_trace(MOD_TST,"Tracker_Socket_TCP_RecData_Handle begin");
    //判断是一个完整数据包才解析
    if(Tracker_RecData_IsIntegrity() == REC_SUCCESS)
    {
		if(Soc_Receive_Data.ContLen > 6)
		{
			g_server_serno = Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-6]*256 + Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-5];
			LOGD(L_OS, L_V5, "--当前流水号=%d", g_server_serno);
		}
		
        currentdatatype = Tracker_RecData_JudgeType();
	#if defined(__SOC_DEBUG__)//wnq
        LOGD(L_OS, L_V5, "	 (type:%d)", currentdatatype);
	#endif/*__SOC_DEBUG__*/
		kal_prompt_trace(MOD_TST,"currentdatatype is:%d", currentdatatype);
	
        if(currentdatatype == TRACKER_LOGIN_REPLY)
        {
            if(!tracker_login_info.Success)
            {
                if(Check_RecData_Login_Information())
                {
                    Tracker_Send_Login_Success_Process();
                }
                else
                {
                    Tracker_Resend_Login_Information();
                }
            }
        }
        else if(currentdatatype == TRACKER_LBS_REPLY)
        {
            Check_RecData_SeverToTerminal();
        }
        else if(currentdatatype == TRACKER_LBS_EXPAND_REPLY)
        {
            Check_RecData_SeverToTerminal();
        }
        else if(currentdatatype == TRACKER_STATUS_REPLY)
        {
            Tracker_Server_Feedback_Packet();
        }
        else if(currentdatatype == TRACKER_ADJUSTTIME_REPLY)
        {
            Online_Synchronize_Time_Handle();
        }
        else if(currentdatatype == TRACKER_ONLINECOM_SET || currentdatatype == TRACKER_ONLINECOM_QUERY)
        {
            Online_Command_Set_Handle();
        }
        /*0x17 is LBS get address ,0x1A is GPS get address ,Sever Send Chinese Address Information*/
        else if(currentdatatype == TRACKER_GETCHADRESS_REPLY)
        {
        	if(is_Sms_Aalarm(g_server_serno)) //是否短信报警转发等 cjt
            {
            	Get_Address_Information_SendSMS();
        	}
        }
        else if(currentdatatype == TRACKER_GETENADRESS_REPLY)
        {
        	if(is_Sms_Aalarm(g_server_serno)) //是否短信报警转发等 cjt
            {
            	Get_EnglishAddress_Information_SendSMS();
        	}
        }

		/*0x1B is server send chinese electronic fence alarm information*/
		/****************************************************************
		0x1B 0x9B服务器页面增加电子围栏报警设置，服务器根据终端上传位置，发生进、出围栏状态后，
		主动向终端下发进、出围栏地址信息包，终端将收到报警地址信息通过短信发送给已经设置的亲情号码。
		此告警由服务器主动下发,不判断，直接转发主控
		*****************************************************************/
        else if(currentdatatype == TRACKER_FENCE_GETCHADRESS_REPLY)
        {
        	if(is_Sms_Aalarm(g_server_serno)) //是否短信报警转发等 cjt
            {
            	Get_FenceAlarm_Information_SendSMS();
        	}
        }
        /*0x9B is server send english electronic fence alarm information*/
        else if(currentdatatype == TRACKER_FENCE_GETENADRESS_REPLY)
        {
        	if(is_Sms_Aalarm(g_server_serno)) //是否短信报警转发等 cjt
        	{
            	Get_EnglishFenceAlarm_Information_SendSMS();
        	}
        }		
	#if defined(__GPS_ON_MTK__)
        else if(currentdatatype == TRACKER_GPS_REPLY)
        {
            Check_RecData_SeverToTerminal();
        }
	#if defined(__AGPS_EPO_SUPPORT__)
        else if(currentdatatype == TRACKER_LATLON_REPLY)
        {
            System_GetLatLon_Handle();
        }
        /*AGPS 数据处理*/
        else if(currentdatatype == TRACKER_EPOAGPS_REPLY)
        {
            Passthrough_Server_Data_Handle();
        }
	#endif/*__AGPS_EPO_SUPPORT__*/
	#endif/*__GPS_ON_MTK__*/
	#if defined(__LOG_OUTPUT__)&&!defined(WIN32)
        else if(currentdatatype == TRACKER_LOG_OUTPUT)
        {
            //Online_ToolsCommand_Set_Handle();
        }
	#endif
        else if(currentdatatype == TRACKER_RECDATA_OTHER)
        {
            Check_RecData_SeverToTerminal();
        }
        memset(&Soc_Receive_Data, 0, sizeof(SOC_RECEIVE_DATA_STRUCT));
    }
    else
    {
	#if defined(__SOC_DEBUG__)//wnq
        LOGD(L_OS, L_V5, "	 (Error_type:%d)", currentdatatype);
	#endif/*__SOC_DEBUG__*/
		kal_prompt_trace(MOD_TST, "Error_type:%d", currentdatatype);
    }
}


/******************************************************************************
 *  Function    -  Tracker_Socket_TCP_Receive
 *
 *  Purpose     - 这里AGPS分包发送1K字节分两次收到
 *                      则此种情况要判断是否有结束符
 *                      有结束符才认为是一个完整包，否则继续等待数据
 *                      拼包
 *                      防止服务器拼包的情况这里申请大空间做处理
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2013-10-15,  guojie  written
 * ----------------------------------------
 * 78 78 00 BB 97 00 B4 00 00 00 01 41 44 44 52 45 53 53 26 26 00 50 00 72 00 65 00 63 00 69 00 73 00 65 00 6C 00 79 00 20 00 4C 00 6F 00 63 00 61 00 74 00 69 00 6E 00 67 00 3A 00 68 00 74 00 74 00 70 00 3A 00 2F 00 2F 00 6D 00 61 00 70 00 73 00 2E 00 67 00 6F 00 6F 00 67 00 6C 00 65 00 2E 00 63 00 6F 00 6D 00 2F 00 6D 00 61 00 70 00 73 00 3F 00 71 00 3D 00 32 00 32 00 2E 00 35 00 37 00 37 00 32 00 32 00 36 00 2C 00 31 00 31 00 33 00 2E 00 39 00 31 00 36 00 37 00 37 00 31 26 26 31 32 35 32 30 31 35 30 31 32 35 38 34 31 30 35 00 EF BF BD 48 EF BF BD 37 23 23 00 5F 85 5C 0D 0A
 ******************************************************************************/
static void Tracker_Socket_TCP_Receive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 revlen = 0, length1 = 0, length2 = 0, length3 = 0;
    U16 departlen[4];
    U8 recvpart = 0, i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_prompt_trace(MOD_TST,"Tracker_Socket_TCP_Receive begin");
	
    memset(departlen, 0, sizeof(departlen));
    if(Soc_Receive_Data.ContLen == 0)
    {
        memset(&Soc_Receive_Data, 0, sizeof(SOC_RECEIVE_DATA_STRUCT));
        Soc_Receive_Data.ContLen = soc_recv(soc_content.soc_id, Soc_Receive_Data.Content, sizeof(Soc_Receive_Data.Content) , 0);
        //wnq add
        if(Soc_Receive_Data.ContLen > PACKET_SOC_MAX * SIGLELEN_SOC_MAX)
        {
		#if defined(__SOC_DEBUG__)
            LOGD(L_OS, L_V5, "	(ContLen:%d len too long return", Soc_Receive_Data.ContLen);
		#endif/*__SOC_DEBUG__*/
			kal_prompt_trace(MOD_TST,"	(ContLen:%d len too long return", Soc_Receive_Data.ContLen);
            return;
        }
    }
    else
    {
        revlen = soc_recv(soc_content.soc_id, &department[0], SIGLELEN_SOC_MAX , 0);

        //wnq add
        if(revlen > SIGLELEN_SOC_MAX)
        {
		#if defined(__SOC_DEBUG__)
            LOGD(L_OS, L_V5, "	(revlen:%d len too long return", revlen);
		#endif/*__SOC_DEBUG__*/
			kal_prompt_trace(MOD_TST,"	(revlen:%d len too long return", revlen);
            return;
        }

        if(Soc_Receive_Data.ContLen + revlen > PACKET_SOC_MAX * SIGLELEN_SOC_MAX)
        {
            memset(&Soc_Receive_Data, 0, sizeof(SOC_RECEIVE_DATA_STRUCT));
        }
        memcpy(&Soc_Receive_Data.Content[Soc_Receive_Data.ContLen], &department[0], revlen);
        Soc_Receive_Data.ContLen += revlen;
        memset(&department[0], 0, SIGLELEN_SOC_MAX);
    }

#if defined(__SOC_DEBUG__)
    LOGD(L_OS, L_V5, "  (Rec ContLen=%d,%d)", Soc_Receive_Data.ContLen, revlen);
#endif/*__SOC_DEBUG__*/
	kal_prompt_trace(MOD_TST,"  (Rec ContLen=%d,%d)", Soc_Receive_Data.ContLen, revlen);
    soc_content.soc_state = SOC_CONNECTED;

    //有结束符才去分段处理
    if((Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-2] == 0x0D) && (Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-1] == 0x0A))
    {
        //UBLOX AGPS协议 不分包78但协议长度是两位
        if((Soc_Receive_Data.Content[0] == 0x78) && (Soc_Receive_Data.Content[1] == 0x78) && (Soc_Receive_Data.Content[2] == 0x1B))
        {
            recvpart = 1;
        }
        ////POSITION查位置回复位置 头是 78 但长度是 两位
        else if((Soc_Receive_Data.Content[0] == 0x78) && (Soc_Receive_Data.Content[1] == 0x78)
                && ((Soc_Receive_Data.Content[4] == 0x96) || (Soc_Receive_Data.Content[4] == 0x97) || (Soc_Receive_Data.Content[4] == 0x99) || (Soc_Receive_Data.Content[4] == 0x9A)))
        {
            recvpart = 1;
        }
        else
        {
            memset(departlen, 0, 4);
            memset(department, 0, PACKET_SOC_MAX * SIGLELEN_SOC_MAX);
            for(i = 0; i < 3; i++)
            {
                departlen[0] = 0;
                if((Soc_Receive_Data.Content[departlen[i] + 0] == 0x78) && (Soc_Receive_Data.Content[departlen[i] + 1] == 0x78))
                {
                    departlen[i+1] = departlen[i] + Soc_Receive_Data.Content[departlen[i] + 2] + 5;
				#if defined(__SOC_DEBUG__)
                    LOGD(L_OS, L_V5, "  (78 departlen[%d]=%d,%d,%d)", i, departlen[i], i + 1, departlen[i+1]);
				#endif/*__SOC_DEBUG__*/
                    if(departlen[i+1] == Soc_Receive_Data.ContLen)
                    {
                        recvpart = i + 1;
                        memcpy(&department[i][0], &Soc_Receive_Data.Content[departlen[i]], departlen[i+1] - departlen[i]);
                        break;
                    }
                    else
                    {
                        memcpy(&department[i][0], &Soc_Receive_Data.Content[departlen[i]], departlen[i+1] - departlen[i]);
                    }
                }
                //wnq 兼容旧协议
                else if((Soc_Receive_Data.Content[departlen[i] + 0] == 0x88) && (Soc_Receive_Data.Content[departlen[i] + 1] == 0x88))
                {
                    departlen[i+1] = departlen[i] + Soc_Receive_Data.Content[departlen[i] + 2] + 5;
				#if defined(__SOC_DEBUG__)
                    LOGD(L_OS, L_V5, "  (88 departlen[%d]=%d,%d,%d)", i, departlen[i], i + 1, departlen[i+1]);
				#endif/*__SOC_DEBUG__*/
                    if(departlen[i+1] == Soc_Receive_Data.ContLen)
                    {
                        recvpart = i + 1;
                        memcpy(&department[i][0], &Soc_Receive_Data.Content[departlen[i]], departlen[i+1] - departlen[i]);
                        break;
                    }
                    else
                    {
                        memcpy(&department[i][0], &Soc_Receive_Data.Content[departlen[i]], departlen[i+1] - departlen[i]);
                    }
                }
                else if((Soc_Receive_Data.Content[departlen[i] + 0] == 0x79) && (Soc_Receive_Data.Content[departlen[i] + 1] == 0x79))
                {
                    departlen[i+1] = departlen[i] + Soc_Receive_Data.Content[departlen[i] + 2] * 256 + Soc_Receive_Data.Content[departlen[i] + 3] + 6;
				#if defined(__SOC_DEBUG__)
                    LOGD(L_OS, L_V5, " (79 length[%d]=%d,%d,%d)", i, departlen[i], i + 1, departlen[i+1]);
				#endif/*__SOC_DEBUG__*/
                    if(departlen[i+1] == Soc_Receive_Data.ContLen)
                    {
                        recvpart = i + 1;
                        memcpy(&department[i][0], &Soc_Receive_Data.Content[departlen[i]], departlen[i+1] - departlen[i]);
                        break;
                    }
                    else
                    {
                        memcpy(&department[i][0], &Soc_Receive_Data.Content[departlen[i]], departlen[i+1] - departlen[i]);
                    }
                }

            }

		#if defined(__SOC_DEBUG__)
            LOGD(L_OS, L_V5, " (recvpart=%d,%d,%d,%d,%d)", recvpart, departlen[0], departlen[1], departlen[2], departlen[3]);
		#endif/*__SOC_DEBUG__*/
			kal_prompt_trace(MOD_TST," (recvpart=%d,%d,%d,%d,%d)", recvpart, departlen[0], departlen[1], departlen[2], departlen[3]);
        }

        //未拼包单独处理
        if(recvpart == 1)
        {
            Tracker_Socket_TCP_RecData_Handle();
        }
        else   //拼包则循环解析
        {
            memset(&Soc_Receive_Data, 0, sizeof(SOC_RECEIVE_DATA_STRUCT));
            for(i = 0; i < recvpart; i++)
            {
                Soc_Receive_Data.ContLen = departlen[i+1] - departlen[i];
                memcpy(&Soc_Receive_Data.Content[0], &department[i][0], Soc_Receive_Data.ContLen);
                Tracker_Socket_TCP_RecData_Handle();
            }
        }
    }
    //$$log,直接处理
    else if((Soc_Receive_Data.Content[0] == 0x24) && (Soc_Receive_Data.Content[1] == 0x24))
    {
        Tracker_Socket_TCP_RecData_Handle();
    }
    else
    {
	#if defined(__SOC_DEBUG__)
        LOGD(L_OS, L_V5, "	Not Found 0D0A!!");
	#endif/*__SOC_DEBUG__*/
    }
}

#elif defined(__OLD_PROTOCOL__)
/******************************************************************************
 *  Function    -  Tracker_Server_Feedback_Packet
 *
 *  Purpose     -  从服务器收到数据
 *
 *  Description - 如果先发了一个状态包，服务器没回复之前又发了一个
 *                      LBS信息包，则服务回复一个10字节数据,协议数据不是0x13
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2014-08-22,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Server_Feedback_Packet(void)
{
    if(StatusReplyProcess == FALSE)
    {
        return;
    }

#if defined(__SOC_DEBUG__)
    LOGD(L_OS, L_V5, "  (have status packet replay!)");
#endif/*__SOC_DEBUG__*/

    tracker_login_info.Success = TRUE;
    soc_content.connect_overtimes = 0;
    Heartbeat_SendTimes = 0;

    if(IsMyTimerExist(TRACKER_SOCKET_INIT_TIMER))
    {
        StopTimer(TRACKER_SOCKET_INIT_TIMER);
    }

    if(IsMyTimerExist(TRAKCER_SOCKET_CALL_TIMER))
    {
        StopTimer(TRAKCER_SOCKET_CALL_TIMER);
    }

    if(IsMyTimerExist(TRACKER_SOCKET_HEARTBEAT_OVERTIME))
    {
        StopTimer(TRACKER_SOCKET_HEARTBEAT_OVERTIME);
    }

    if(IsMyTimerExist(TRACKER_SOCKET_CONNECT_OVERTIMER))
    {
        StopTimer(TRACKER_SOCKET_CONNECT_OVERTIMER);
    }
#if defined(__SOC_DEBUG__)
    LOGD(L_OS, L_V5, "  (heartbeat overtime have: %d)", (IsMyTimerExist(TRACKER_SOCKET_HEARTBEAT_OVERTIME)));
#endif/*__SOC_DEBUG__*/
#if defined(__GPSBACKUP_BTWTWOHEART__)
    memset(&Backup_GPS_LBS_Info, 0, sizeof(TRACKER_BACKUP_GPS_LBS_INFORMATION_STRUCT));
    Backup_GPS_LBS_Info.count = 0;
#endif
}

/******************************************************************************
 *  Function    -  Tracker_RecData_IsIntegrity
 *
 *  Purpose     - 检查收到的数据包是否是完整的包
 *                  1.   有头 (78 78 ) /(88 88 ) /68 68/54 68
 *                  2.  有尾(0D 0A)
 *                  3.   包长度+头尾=总长度
 *                  4.   CRC校验码正确
 *                   不是完整包继续等待下一个包拼合后处理
 *                   78 78 1B 04 F6  //UBLOX AGPS 不分包04 F6 = 1270  分两包发送
 *                   78 78 1B 04 86  //UBLOX AGPS 不分包04 86 = 1158 分两包发送500 +658
 *                   78 78 00 B7 97  //长度为两位
 *  Description -
 *                 1.首先判断长度
 *                 2.判断首尾
 *                 3.判断校验
 * modification history
 * ----------------------------------------
 * v1.0  , 2014-08-22,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static TRACKER_RECERROR_TYPE Tracker_RecData_IsIntegrity(void)
{
    U16 crc_temp = 0, ContentLen = 0;
    U8 crc[2];

#if defined(__SOC_DEBUG__)
    LOGD(L_SOC, L_V5, "  (%d-%x %x %x %x %x %x %x %x %x %x)",
         Soc_Receive_Data.ContLen, Soc_Receive_Data.Content[0],
         Soc_Receive_Data.Content[1], Soc_Receive_Data.Content[2], Soc_Receive_Data.Content[3],
         Soc_Receive_Data.Content[4], Soc_Receive_Data.Content[5], Soc_Receive_Data.Content[6],
         Soc_Receive_Data.Content[7], Soc_Receive_Data.Content[8], Soc_Receive_Data.Content[9],
         Soc_Receive_Data.Content[10]);
#endif/*__SOC_DEBUG__*/

    if(Soc_Receive_Data.ContLen > 0)
    {
        if((Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-2] == 0x0D) && (Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-1] == 0x0A))
        {
            //状态回复包
            //54 68 1A 0D 0A
            //68 68 1E 0D 0A
            if(Soc_Receive_Data.ContLen == 0x05)
            {
                if((Soc_Receive_Data.Content[0] == 0x68) && (Soc_Receive_Data.Content[1] == 0x68))
                {
                    return REC_SUCCESS;
                }
                else if((Soc_Receive_Data.Content[0] == 0x54) && (Soc_Receive_Data.Content[1] == 0x68))
                {
                    return REC_SUCCESS;
                }
            }
            //英文地址回复包
            else if(Soc_Receive_Data.ContLen == (6 + Soc_Receive_Data.Content[2] * 256 + Soc_Receive_Data.Content[3]))
            {
                //78 78 9E 17 98 00 00 00 01 41 44 44 52 45 53 53 26 26 62
                //78 78 9D 17 97 00 00 00 01 41 44 44 52 45 53 53 26 26 7D 27 60 25 54
                if((Soc_Receive_Data.Content[0] == 0x78) && (Soc_Receive_Data.Content[1] == 0x78))
                {
                    ContentLen = Soc_Receive_Data.Content[2] * 256 + Soc_Receive_Data.Content[3];
                    memset(recvcrc_buffer, 0, sizeof(recvcrc_buffer));
                    memcpy(recvcrc_buffer, &Soc_Receive_Data.Content[2], ContentLen);
                    crc_temp = GetCrc16((U8 *)&recvcrc_buffer, ContentLen);
                    crc[0] = (U8)(crc_temp / 256);
                    crc[1] = (U8)(crc_temp & 0x00ff);

                    if((Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-4] == crc[0]) && (Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-3] == crc[1]))
                    {
                        return REC_SUCCESS;
                    }
                    else
                    {
					#if defined(__SOC_DEBUG__)
                        LOGD(L_OS, L_V5, " (78 78 Long CRC errer!%x,%x--%x,%x)", crc[0], crc[2]);
					#endif/*__SOC_DEBUG__*/
                        return REC_CRC_ERROR;
                    }
                }
                else if((Soc_Receive_Data.Content[0] == 0x24) && (Soc_Receive_Data.Content[1] == 0x24))
                {
                    return REC_SUCCESS;
                }
                else
                {
                    return REC_HEAD_ERROR;
                }
            }
            //中文地址回复包，IP获取包
            else if(Soc_Receive_Data.ContLen == 5 + Soc_Receive_Data.Content[2])
            {
                //中文地址回复包
                //IP地址请求包
                if((Soc_Receive_Data.Content[0] == 0x78) && (Soc_Receive_Data.Content[1] == 0x78))
                {
                    ContentLen = Soc_Receive_Data.Content[2];
                    memset(recvcrc_buffer, 0, sizeof(recvcrc_buffer));
                    memcpy(recvcrc_buffer, &Soc_Receive_Data.Content[2], ContentLen - 1);
                    crc_temp = GetCrc16((U8 *)&recvcrc_buffer, ContentLen - 1);
                    crc[0] = (U8)(crc_temp / 256);
                    crc[1] = (U8)(crc_temp & 0x00ff);
                    if((Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-4] == crc[0]) && (Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-3] == crc[1]))
                    {
                        return REC_SUCCESS;
                    }
                    else
                    {
					#if defined(__SOC_DEBUG__)
                        LOGD(L_OS, L_V5, " (78 78 short CRC errer!%x,%x--%x,%x)", crc[0], crc[2]);
					#endif/*__SOC_DEBUG__*/
                        return REC_CRC_ERROR;
                    }
                }
                //在线下发指令
                else if((Soc_Receive_Data.Content[0] == 0x88) && (Soc_Receive_Data.Content[1] == 0x88))
                {
                    return REC_SUCCESS;
                }
                else if((Soc_Receive_Data.Content[0] == 0x24) && (Soc_Receive_Data.Content[1] == 0x24))
                {
                    return REC_SUCCESS;
                }
                else
                {
                    return REC_HEAD_ERROR;
                }
            }
            //$$log,
            else if((Soc_Receive_Data.Content[0] == 0x24) && (Soc_Receive_Data.Content[1] == 0x24))
            {
                return REC_SUCCESS;
            }
            else
            {
                return REC_LEN_ERROR;
            }
        }
        else
        {
            return REC_END_ERROR;
        }
    }
    else
    {
	#if defined(__SOC_DEBUG__)
        LOGD(L_OS, L_V5, " (receive data length is zero!)");
	#endif/*__SOC_DEBUG__*/
        return REC_LENZERO_ERROR;
    }
}


/******************************************************************************
 *  Function    -  Tracker_RecData_JudgeType
 *
 *  Purpose     -  判断是否是那种包回复
 *
 *
 *  Description -  必须按包长度、头、协议号、尾来解析
 *                       否则出现因当时定协议不完善导致一个协议号当成
 *                       另一个协议号来解析导致重启问题
 * modification history
 * ----------------------------------------
 * v1.0  , 2014-08-22,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static TRACKER_RECDATA_TYPE Tracker_RecData_JudgeType(void)
{
    //54 68 1A 0D 0A
    if((Soc_Receive_Data.Content[0] == 0x54) && (Soc_Receive_Data.Content[1] == 0x68)
            && (Soc_Receive_Data.Content[2] == 0x1A))
    {
        return TRACKER_STATUS_REPLY;
    }
    //68 68 1E 0D 0A
    else if((Soc_Receive_Data.Content[0] == 0x68) && (Soc_Receive_Data.Content[1] == 0x68)
            && (Soc_Receive_Data.Content[2] == 0x1E))
    {
        return TRACKER_ABNORMAL_STATUS_REPLY;
    }
    //在线下发
    else if((Soc_Receive_Data.ContLen == Soc_Receive_Data.Content[2] + 5)
            && (Soc_Receive_Data.Content[0] == 0x88 && Soc_Receive_Data.Content[1] == 0x88)
            && (Soc_Receive_Data.Content[3] == 0x1C))
    {
        return TRACKER_ONLINECOM_SET;
    }
    else if((Soc_Receive_Data.ContLen == Soc_Receive_Data.Content[2] + 5)
            && (Soc_Receive_Data.Content[0] == 0x78 && Soc_Receive_Data.Content[1] == 0x78)
            && (Soc_Receive_Data.Content[3] == 0x16 || Soc_Receive_Data.Content[3] == 0x17
                || Soc_Receive_Data.Content[3] == 0x19 || Soc_Receive_Data.Content[3] == 0x1A))
    {
        return TRACKER_GETCHADRESS_REPLY;
    }
    else if((Soc_Receive_Data.ContLen == (Soc_Receive_Data.Content[2] * 256 + Soc_Receive_Data.Content[3] + 6))
            && (Soc_Receive_Data.Content[0] == 0x78 && Soc_Receive_Data.Content[1] == 0x78)
            && (Soc_Receive_Data.Content[4] == 0x96 || Soc_Receive_Data.Content[4] == 0x97
                || Soc_Receive_Data.Content[4] == 0x99 || Soc_Receive_Data.Content[4] == 0x9A))
    {
        return TRACKER_GETENADRESS_REPLY;
    }
    else if((Soc_Receive_Data.Content[0] == 0x78) && (Soc_Receive_Data.Content[1] == 0x78)
            && (Soc_Receive_Data.Content[3] == 0x00))
    {
        return TRACKER_GETIP_REPLY;
    }
#if defined(__LOG_OUTPUT__)&&!defined(WIN32)
    //$$set,   // 24 24 73 65 74 2C   //中转透传工具下发的指令
    //$$SET,  // 24 24 53 45 54 2C
    else if(Soc_Receive_Data.Content[0] == 0x24 && Soc_Receive_Data.Content[1] == 0x24 &&
            Soc_Receive_Data.Content[2] == 0x73 && Soc_Receive_Data.Content[3] == 0x65 &&
            Soc_Receive_Data.Content[4] == 0x74 && Soc_Receive_Data.Content[5] == 0x2C)
    {
        return TRACKER_LOG_OUTPUT;
    }
    else if(Soc_Receive_Data.Content[0] == 0x24 && Soc_Receive_Data.Content[1] == 0x24 &&
            Soc_Receive_Data.Content[2] == 0x53 && Soc_Receive_Data.Content[3] == 0x45 &&
            Soc_Receive_Data.Content[4] == 0x54 && Soc_Receive_Data.Content[5] == 0x2C)
    {
        return TRACKER_LOG_OUTPUT;
    }
#endif
    else
    {
        return TRACKER_RECDATA_OTHER;
    }
}

/******************************************************************************
 *  Function    -  Tracker_Socket_TCP_RecData_Handle
 *
 *  Purpose     -  终端数据处理
 *
 *                      拼包解析
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2013-10-16,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Socket_TCP_RecData_Handle(void)
{
    TRACKER_RECDATA_TYPE currentdatatype;
#if defined(__SOC_DEBUG__)
    LOGD(L_SOC, L_V5, "   (Data handle ,login:%d)", tracker_login_info.Success);
#endif/*__SOC_DEBUG__*/
	kal_prompt_trace(MOD_TST,"Tracker_Socket_TCP_RecData_Handle,  tracker_login_info.Success is:%d", tracker_login_info.Success);

    //判断是一个完整数据包才解析
    if(Tracker_RecData_IsIntegrity() == REC_SUCCESS)
    {
        currentdatatype = Tracker_RecData_JudgeType();
	#if defined(__SOC_DEBUG__)
        LOGD(L_OS, L_V5, "   (datatype:%d)", currentdatatype);
	#endif/*__SOC_DEBUG__*/
		kal_prompt_trace(MOD_TST,"datatype is:%d", currentdatatype);

        if(currentdatatype == TRACKER_STATUS_REPLY)
        {
            if(!tracker_login_info.Success)
            {
                tracker_login_info.Success = TRUE;
                if(GPSCurrentLocation == TRUE)
                {
                    Tracker_Send_GPS_Data();
                }
				else
				{
				#if defined(__MULTI_CELLID__)||defined(__NBR_CELL_INFO__)
					Tracker_Send_LBSExpand_Data();
				#else
					Tracker_Send_LBS_Data();
				#endif
				}

                if(GT02A_Abnormal_State != ABNORMAL_NO_STATE)
                {
                    Tracker_Send_Abnormal_Status_Data();
                }
            }
            Tracker_Server_Feedback_Packet();
        }
        else if(currentdatatype == TRACKER_ABNORMAL_STATUS_REPLY)
        {
            Tracker_Server_Feedback_Packet();
        }
        else if(currentdatatype == TRACKER_ONLINECOM_SET)
        {
            GT02A_Online_Command_Set_Handle();
        }
        /*0x17 is LBS get address ,0x1A is GPS get address ,Sever Send Chinese Address Information*/
        else if(currentdatatype == TRACKER_GETCHADRESS_REPLY)
        {
            GT02A_Get_Address_Information_SendSMS();
        }
        else if(currentdatatype == TRACKER_GETENADRESS_REPLY)
        {
            GT02A_Get_EnglishAddress_Information_SendSMS();
        }
        else if(currentdatatype == TRACKER_GETIP_REPLY)
        {
            GT02A_GetIP_Reply_Handle();
        }
	#if defined(__LOG_OUTPUT__)&&!defined(WIN32)
        else if(currentdatatype == TRACKER_LOG_OUTPUT)
        {
            //Online_ToolsCommand_Set_Handle();
        }
	#endif
        else if(currentdatatype == TRACKER_RECDATA_OTHER)
        {

        }
        memset(&Soc_Receive_Data, 0, sizeof(SOC_RECEIVE_DATA_STRUCT));
    }
}

/******************************************************************************
 *  Function    -  Tracker_Socket_TCP_Receive
 *
 *  Purpose     - 这里AGPS分包发送1K字节分两次收到
 *                      则此种情况要判断是否有结束符
 *                      有结束符才认为是一个完整包，否则继续等待数据
 *                      拼包
 *                      防止服务器拼包的情况这里申请大空间做处理
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2013-10-15,  guojie  written
 * ----------------------------------------
 * 78 78 00 BB 97 00 B4 00 00 00 01 41 44 44 52 45 53 53 26 26 00 50 00 72 00 65 00 63 00 69 00 73 00 65 00 6C 00 79 00 20 00 4C 00 6F 00 63 00 61 00 74 00 69 00 6E 00 67 00 3A 00 68 00 74 00 74 00 70 00 3A 00 2F 00 2F 00 6D 00 61 00 70 00 73 00 2E 00 67 00 6F 00 6F 00 67 00 6C 00 65 00 2E 00 63 00 6F 00 6D 00 2F 00 6D 00 61 00 70 00 73 00 3F 00 71 00 3D 00 32 00 32 00 2E 00 35 00 37 00 37 00 32 00 32 00 36 00 2C 00 31 00 31 00 33 00 2E 00 39 00 31 00 36 00 37 00 37 00 31 26 26 31 32 35 32 30 31 35 30 31 32 35 38 34 31 30 35 00 EF BF BD 48 EF BF BD 37 23 23 00 5F 85 5C 0D 0A
 ******************************************************************************/
static void Tracker_Socket_TCP_Receive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 revlen = 0, length1 = 0, length2 = 0, length3 = 0;
    U16 departlen[4];
    U8 recvpart = 0, i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_prompt_trace(MOD_TST,"Tracker_Socket_TCP_Receive begin");
	
    memset(departlen, 0, sizeof(departlen));
    if(Soc_Receive_Data.ContLen == 0)
    {
        memset(&Soc_Receive_Data, 0, sizeof(SOC_RECEIVE_DATA_STRUCT));
        Soc_Receive_Data.ContLen = soc_recv(soc_content.soc_id, Soc_Receive_Data.Content, sizeof(Soc_Receive_Data.Content) , 0);
    }
    else
    {
        revlen = soc_recv(soc_content.soc_id, &department[0], SIGLELEN_SOC_MAX , 0);
        if(Soc_Receive_Data.ContLen + revlen > PACKET_SOC_MAX * SIGLELEN_SOC_MAX)
        {
            memset(&Soc_Receive_Data, 0, sizeof(SOC_RECEIVE_DATA_STRUCT));
        }
        memcpy(&Soc_Receive_Data.Content[Soc_Receive_Data.ContLen], &department[0], revlen);
        Soc_Receive_Data.ContLen += revlen;
        memset(&department[0], 0, SIGLELEN_SOC_MAX);
    }

#if defined(__SOC_DEBUG__)
    LOGD(L_OS, L_V5, "  (Rec ContLen=%d,%d)", Soc_Receive_Data.ContLen, revlen);
#endif/*__SOC_DEBUG__*/

    soc_content.soc_state = SOC_CONNECTED;

    //有结束符才去分段处理
    if((Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-2] == 0x0D) && (Soc_Receive_Data.Content[Soc_Receive_Data.ContLen-1] == 0x0A))
    {
        ////POSITION查位置回复位置 头是 78 但长度是 两位
        if((Soc_Receive_Data.Content[0] == 0x78) && (Soc_Receive_Data.Content[1] == 0x78)
                && ((Soc_Receive_Data.Content[4] == 0x96) || (Soc_Receive_Data.Content[4] == 0x97) || (Soc_Receive_Data.Content[4] == 0x99) || (Soc_Receive_Data.Content[4] == 0x9A)))
        {
            recvpart = 1;
        }
        //54 68 1A 0D 0A
        else if((Soc_Receive_Data.Content[0] == 0x54) && (Soc_Receive_Data.Content[1] == 0x68)
                && (Soc_Receive_Data.Content[2] == 0x1A) && (Soc_Receive_Data.ContLen == 5))
        {
            recvpart = 1;
        }
        //68 68 1A 0D 0A
        else if((Soc_Receive_Data.Content[0] == 0x68) && (Soc_Receive_Data.Content[1] == 0x68)
                && (Soc_Receive_Data.Content[2] == 0x1D) && (Soc_Receive_Data.ContLen == 5))
        {
            recvpart = 1;
        }
        else if((Soc_Receive_Data.Content[0] == 0x54) && (Soc_Receive_Data.Content[1] == 0x68)
                && (Soc_Receive_Data.Content[2] == 0x1A) && (Soc_Receive_Data.ContLen > 5))
        {
            memset(department, 0, PACKET_SOC_MAX * SIGLELEN_SOC_MAX);
            memcpy(&department[0][0], &Soc_Receive_Data.Content[0], 5);
            memcpy(&department[1][0], &Soc_Receive_Data.Content[5], Soc_Receive_Data.ContLen - 5);
            recvpart = 2;
        }
        //68 68 1A 0D 0A
        else if((Soc_Receive_Data.Content[0] == 0x68) && (Soc_Receive_Data.Content[1] == 0x68)
                && (Soc_Receive_Data.Content[2] == 0x1D) && (Soc_Receive_Data.ContLen > 5))
        {
            recvpart = 2;
            memset(department, 0, PACKET_SOC_MAX * SIGLELEN_SOC_MAX);
            memcpy(&department[0][0], &Soc_Receive_Data.Content[0], 5);
            memcpy(&department[1][0], &Soc_Receive_Data.Content[5], Soc_Receive_Data.ContLen - 5);
        }
        else
        {
            recvpart = 1;
        }

        //未拼包单独处理
        if(recvpart == 1)
        {
            Tracker_Socket_TCP_RecData_Handle();
        }
        else   //拼包则循环解析
        {
            memset(&Soc_Receive_Data, 0, sizeof(SOC_RECEIVE_DATA_STRUCT));
            for(i = 0; i < recvpart; i++)
            {
                Soc_Receive_Data.ContLen = departlen[i+1] - departlen[i];
                memcpy(&Soc_Receive_Data.Content[0], &department[i][0], Soc_Receive_Data.ContLen);
                Tracker_Socket_TCP_RecData_Handle();
            }
        }
    }
    //$$log,直接处理
    else if((Soc_Receive_Data.Content[0] == 0x24) && (Soc_Receive_Data.Content[1] == 0x24))
    {
        Tracker_Socket_TCP_RecData_Handle();
    }
}


#endif


/******************************************************************************
 *  Function    -  Tracker_Socket_TCP_ReStart
 *
 *  Purpose     -  Socket 重新连接开始，不需要重新注册
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-11-07,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Socket_TCP_ReStart(void)
{
#if defined(__SOC_DEBUG__)
    LOGD(L_OS, L_V5, "Restart connecttype=%d,saveip:%d", tracker_server_param.conecttype, tracker_server_param.IsSaveIP);
#endif/*__SOC_DEBUG__*/
	kal_prompt_trace(MOD_TST,"Restart connecttype=%d,saveip:%d", tracker_server_param.conecttype, tracker_server_param.IsSaveIP);

    if(tracker_ctrl_data.GPRSAlwaysOn == 0)
    {
    #if defined(__SOC_DEBUG__)
        LOGD(L_SOC, L_V5, "  GPRSON=OFF");
	#endif/*__SOC_DEBUG__*/
        return;
    }

    if(Tracker_Socket_TCP_Create() == TRUE)
    {
	#if defined(__OLD_PROTOCOL__)&&defined(__GT02R_GM__)
        //动态域名，去获取IP链接
        if((tracker_server_param.conecttype == 0) || (GT02A_GetIP.get_ip == 1)
                || ((tracker_server_param.conecttype == 1) && (tracker_server_param.conipinfo != 0)))
        {
            StartTimer(TRACKER_SOCKET_CONNECT_TIMER, 3 * 1000, Tracker_Socket_TCP_Connect);
        }
        else
        {
            StartTimer(TRACKER_SOCKET_DNS_TIMER , 3 * 1000, Tracker_Socket_DNS_Parse);
        }
	#else
        //没有缓存IP时根据conecttype连接后台
        //缓存IP后直接根据IP连接
        //缓存IP两次连不上进行域名解析
        //后台设定以IP连接时，始终不启用域名解析
        if((tracker_server_param.conecttype == 0)
				|| ((tracker_server_param.conecttype == 1) && (tracker_server_param.IsSaveIP == 1)
			#if defined(__KD6113_WORK_MODE__)		//xb add 2015-08-18 防止模式2下平台IP改变导致一直无法联网的问题
				&& (tracker_ctrl_data.workmode.type == MODE_WORK_1 || tracker_ctrl_data.workmode.type == MODE_WORK_3)
			#endif		
				)
			)
        {
            StartTimer(TRACKER_SOCKET_CONNECT_TIMER, 3 * 1000, Tracker_Socket_TCP_Connect);
        }
        else
        {
            StartTimer(TRACKER_SOCKET_DNS_TIMER , 3 * 1000, Tracker_Socket_DNS_Parse);
        }
	#endif
    }
    else
    {
    #if defined(__SOC_DEBUG__)
        LOGD(L_CMD, L_V5, " Socket Create Fail!");
	#endif/*__SOC_DEBUG__*/
        Tracker_Socket_OutputResult(SOC_CON_ERROR);
    }
}
#if defined(__GPS_ON_MTK__)
/******************************************************************************
 *  Function    -  Tracker_Socket_Msg_Backup_Req
 *
 *  Purpose     -  GPRS发送失败的数据备份
 *
 *  Description -  发送失败的数据备份，备份时判断是GPS包才备份
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2012-06-09,  guojie arrange
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Socket_Msg_Backup_Req(vec_gprs_socket_send_struct* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    gprs_socket_backup_req_struct *myMsgPtr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    myMsgPtr = (gprs_socket_backup_req_struct*) OslConstructDataPtr(sizeof(gprs_socket_backup_req_struct));

    memset(myMsgPtr->buffer , 0 , MAX_SND_BUFFER_SIZE);
    memcpy(myMsgPtr->buffer , data->buffer , data->len);
#if defined(__SOC_DEBUG__)	
    LOGD(L_CMD, L_V5, " type: %x", data->buffer[3]);
#endif/*__SOC_DEBUG__*/
#if defined(__OLD_PROTOCOL__)
    if(data->buffer[15] == 0x10)
#else
    if(data->buffer[3] == 0x22)
#endif
    {
        myMsgPtr->len = data->len ;
        Message.src_mod_id = MOD_MMI;
        Message.dest_mod_id = MOD_MMI;
        Message.sap_id = MMI_MMI_SAP;
        Message.msg_id = (msg_type) MSG_ID_MMI_GPS_NVRAM_GPSBACKUP;
        Message.local_para_ptr = (local_para_struct*) myMsgPtr;
        Message.peer_buff_ptr = NULL;
        OslMsgSendExtQueue(&Message);
    }

}

#endif

#if defined(__OLD_PROTOCOL__)
/******************************************************************************
 *  Function    -  Tracker_Socket_Send
 *
 *  Purpose     -GPRS连接发送数据
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2012-06-04,  guojie arrange
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Socket_Send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ret;
    vec_gprs_socket_send_struct* buf;
    S16 Error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_prompt_trace(MOD_TST, "Tracker_Socket_Send  sendstate:%d", soc_content.sendstate);
    //这里不停止TIMER,Tracker_GPRS_Socket_Send_Req 不会重新启动TIMER发送数据
    StopTimer(TRACKER_SOCKET_SEND_TIMER_ID);
    if(soc_content.sendstate <= SOCKET_CREATED || soc_content.sendstate >= SOCKET_CLOSING)
    {
        if(VECTOR_Size(vec_socket_send))
        {
            buf = VECTOR_At(vec_socket_send, 0);
		#if defined(__GPS_BACKUP__)
            Tracker_Socket_Msg_Backup_Req(buf);
		#endif
            VECTOR_Erase(vec_socket_send, 0, 1);
            RamBuffer_Free(buf);
        }
        return;
    }

    kal_prompt_trace(MOD_TST, "Tracker_Socket_Send login:%d,size:%d", tracker_login_info.Success, VECTOR_Size(vec_socket_send));

    if(VECTOR_Size(vec_socket_send))
    {
        if(soc_content.sendstate != SOCKET_SENDING)
        {
            buf = VECTOR_At(vec_socket_send, 0);
            buf->status = 1;
            soc_content.snd_counter = 0;
            memcpy(soc_content.snd_buffer , buf->buffer, buf->len);
            soc_content.snd_data_len = buf->len;
        }
        soc_content.sendstate = SOCKET_SENDING;

        ret = soc_send(soc_content.soc_id,
                       (kal_uint8*)(&soc_content.snd_buffer[soc_content.snd_counter]),
                       (soc_content.snd_data_len - soc_content.snd_counter),
                       0);

        kal_prompt_trace(MOD_TST, "Tracker_Socket_Send ^^ ret:%d", ret);

        kal_prompt_trace(MOD_TST, "Tracker_Socket_Send (ret:%d,type:%x)", ret, soc_content.snd_buffer[soc_content.snd_counter+3]);
        //返回SOC发送数据为:65535 则表示链接被关闭
        if(ret > 0 && ret <1024)
        {
            if(ret == (kal_int32) soc_content.snd_data_len)
            {
                soc_content.sendstate = SOCKET_SENT;   //已发送
                soc_content.post_retry_counter++;
                buf = VECTOR_At(vec_socket_send, 0);
                if(buf->status)
                {
                    VECTOR_Erase(vec_socket_send, 0, 1);
                    RamBuffer_Free(buf);
                }
                if(VECTOR_Size(vec_socket_send))
                {
                    StartTimer(TRACKER_SOCKET_SEND_TIMER_ID, 1000, Tracker_Socket_Send);
                }
            }
            else
            {
                soc_content.snd_counter += ret;
            }
        }
        else if(ret == SOC_WOULDBLOCK)
        {
            SetProtocolEventHandler(Tracker_Socket_Notify, MSG_ID_APP_SOC_NOTIFY_IND);
        }
        else
        {
            buf = VECTOR_At(vec_socket_send, 0);
		#if defined(__GPS_BACKUP__)
            Tracker_Socket_Msg_Backup_Req(buf);
		#endif
            VECTOR_Erase(vec_socket_send, 0, 1);
            RamBuffer_Free(buf);
		#if defined(__SOC_DEBUG__)	
            LOGD(L_OS, L_V5, "   (Send Data error!Reconncet.)");
		#endif/*__SOC_DEBUG__*/
            kal_prompt_trace(MOD_TST, "Tracker_Socket_Send  Error!Reconnect!");

            Tracker_Socket_TCP_Close();
            StartTimer(TRACKER_SOCKET_CONNECT_TIMER, 15000, Tracker_Socket_TCP_ReConnect);
        }
    }
}
#else
/******************************************************************************
 *  Function    -  Tracker_Socket_Send
 *
 *  Purpose     -GPRS连接发送数据
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2012-06-04,  guojie arrange
 * ----------------------------------------
 ******************************************************************************/
static void Tracker_Socket_Send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ret;
    S16 gprs_flow_value = 0;
    vec_gprs_socket_send_struct* buf;
    MYTIME currTime;
    char Timebuf[10];
    S16 Error;

    GetDateTime(&currTime);
    memset(Timebuf, 0, sizeof(Timebuf));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_prompt_trace(MOD_TST,"Tracker_Socket_Send, soc_content.sendstate is:%d", soc_content.sendstate);
	
    if(soc_content.sendstate <= SOCKET_CREATED || soc_content.sendstate >= SOCKET_CLOSING)
    {
        if(VECTOR_Size(vec_socket_send))
        {
            buf = VECTOR_At(vec_socket_send, 0);
		#if defined(__GPS_ON_MTK__)
            Tracker_Socket_Msg_Backup_Req(buf);
		#endif
            VECTOR_Erase(vec_socket_send, 0, 1);
            RamBuffer_Free(buf);
        }
        return;
    }


    sprintf(Timebuf, "  ^^[ %d:%d]", currTime.nHour, currTime.nMin);

    if(VECTOR_Size(vec_socket_send))
    {
        if(soc_content.sendstate != SOCKET_SENDING)
        {
            buf = VECTOR_At(vec_socket_send, 0);
            buf->status = 1;
            soc_content.snd_counter = 0;
            memcpy(soc_content.snd_buffer , buf->buffer, buf->len);
            soc_content.snd_data_len = buf->len;
        }
        soc_content.sendstate = SOCKET_SENDING;

        //这里登陆包未发送成功，然后发送GPS定位数据会导致断开链接
        if(tracker_login_info.Success == FALSE)
        {
            if((soc_content.snd_buffer[soc_content.snd_counter+3] == 0x01))
            {
                ret = soc_send(soc_content.soc_id,
                               (kal_uint8*)(&soc_content.snd_buffer[soc_content.snd_counter]),
                               (soc_content.snd_data_len - soc_content.snd_counter),
                               0);
			#if defined(__SOC_DEBUG__)	
                LOGD(L_OS, L_V5, " Login %s", Timebuf);
			#endif/*__SOC_DEBUG__*/
				kal_prompt_trace(MOD_TST," Login %s", Timebuf);
            }
            //备份数据发送过程中突然SOC断开，还保留在
            //vec_socket_send 里面直接将first退回1条
            else if((soc_content.snd_buffer[soc_content.snd_counter+3] == 0x10))
            {
                //GPS数据重新备份
                if(PACKET_GPS_LBS_SIGE_LENGTH == (kal_int32) soc_content.snd_data_len)
                {
                    soc_content.sendstate = SOCKET_CONNECTED;
                    buf = VECTOR_At(vec_socket_send, 0);
                    if(buf->status)
                    {
                        VECTOR_Erase(vec_socket_send, 0, 1);
                        RamBuffer_Free(buf);
                        if(backup_data_param.data_first > 2)
                        {
                            backup_data_param.data_first --;
                            WriteRecord(NVRAM_EF_TRACKER_GPS_BACKUP_DATA_PARAM_LID, 1, (void *)&backup_data_param, NVRAM_EF_TRACKER_GPS_BACKUP_DATA_PARAM_SIZE, &Error);
                        }
                    }

                    if(VECTOR_Size(vec_socket_send))
                    {
                        StartTimer(TRACKER_SOCKET_SEND_TIMER_ID, 1000, Tracker_Socket_Send);
                    }
                }
			#if defined(__SOC_DEBUG__)	
                LOGD(L_OS, L_V5, " GPS %s,%d,%d", Timebuf, PACKET_GPS_LBS_SIGE_LENGTH, soc_content.snd_data_len);
			#endif/*__SOC_DEBUG__*/
				kal_prompt_trace(MOD_TST," GPS %s,%d,%d", Timebuf, PACKET_GPS_LBS_SIGE_LENGTH, soc_content.snd_data_len);
                return;
            }
            else   //其他包则直接擦除
            {
                soc_content.sendstate = SOCKET_CONNECTED;
                buf = VECTOR_At(vec_socket_send, 0);
                if(buf->status)
                {
                    VECTOR_Erase(vec_socket_send, 0, 1);
                    RamBuffer_Free(buf);
                }

                if(VECTOR_Size(vec_socket_send))
                {
                    StartTimer(TRACKER_SOCKET_SEND_TIMER_ID, 1000, Tracker_Socket_Send);
                }
			#if defined(__SOC_DEBUG__)
                LOGD(L_OS, L_V5, " others");
			#endif/*__SOC_DEBUG__*/
                return;
            }
        }
        else
        {
            ret = soc_send(soc_content.soc_id,
                           (kal_uint8*)(&soc_content.snd_buffer[soc_content.snd_counter]),
                           (soc_content.snd_data_len - soc_content.snd_counter),
                           0);
        }

        if((soc_content.snd_buffer[soc_content.snd_counter] == 0x78))
        {
        #if defined(__SOC_DEBUG__)
            LOGD(L_OS, L_V5, "  sent_bytes=%d,type:%x,ind:%d,%d,%d", ret, soc_content.snd_buffer[soc_content.snd_counter+3], soc_content.snd_buffer[ret-5], soc_content.snd_data_len, soc_content.snd_counter);
		#endif/*__SOC_DEBUG__*/
        }
        else if((soc_content.snd_buffer[soc_content.snd_counter] == 0x79))
        {
        #if defined(__SOC_DEBUG__)
            LOGD(L_OS, L_V5, " sent_bytes=%d,type:%x,ind:%d,%d,%d", ret, soc_content.snd_buffer[soc_content.snd_counter+4], soc_content.snd_buffer[ret-5], soc_content.snd_data_len, soc_content.snd_counter);
		#endif/*__SOC_DEBUG__*/
        }
        if(ret > 0)
        {
		#if defined(__LED_APP__)
            if(IS_IN_CALL())
            {
                if(sys_gsm_state != GSM_CALLING_STATE)
                {
                    sys_gsm_state = GSM_CALLING_STATE ;
                    LED_GSM_StatusSet(sys_gsm_state);
                }
            }
            else
            {
                if(sys_gsm_state != GSM_GRPS_CONNECT_STATE)
                {
                    sys_gsm_state = GSM_GRPS_CONNECT_STATE;
                    LED_GSM_StatusSet(sys_gsm_state);
                }
            }
		#endif
		#ifdef __KKSAPP_GPRS_MONITOR_SUPPORT__
            if(tracker_gprs_flowrate.monitorstatus == 1)
            {
                gprs_flow_value = ret + 53;
                gprs_flow_statistic_add(gprs_flow_value);
            }
		#endif
            if(ret == (kal_int32) soc_content.snd_data_len)
            {
                soc_content.sendstate = SOCKET_SENT;
                soc_content.post_retry_counter++;
                buf = VECTOR_At(vec_socket_send, 0);
                if(buf->status)
                {
                    VECTOR_Erase(vec_socket_send, 0, 1);
                    RamBuffer_Free(buf);
                }
                if(VECTOR_Size(vec_socket_send))
                {
                    StartTimer(TRACKER_SOCKET_SEND_TIMER_ID, 1000, Tracker_Socket_Send);
                }
            }
            else
            {
                soc_content.snd_counter += ret;
            }
        }
        else if(ret == SOC_WOULDBLOCK)
        {
        	kal_prompt_trace(MOD_TST,"ret == SOC_WOULDBLOCK");
            SetProtocolEventHandler(Tracker_Socket_Notify, MSG_ID_APP_SOC_NOTIFY_IND);
        }
        else
        {
            buf = VECTOR_At(vec_socket_send, 0);
		#if defined(__GPS_ON_MTK__)
            Tracker_Socket_Msg_Backup_Req(buf);
		#endif
            VECTOR_Erase(vec_socket_send, 0, 1);
            RamBuffer_Free(buf);
		#if defined(__SOC_DEBUG__)	
            LOGD(L_OS, L_V5, "   (Send Data error!Reconncet.)");
		#endif/*__SOC_DEBUG__*/
			kal_prompt_trace(MOD_TST,"(Send Data error!Reconncet.)");

            soc_content.soc_state = SOC_INVALID;
            Tracker_Socket_TCP_Close();
            StartTimer(TRACKER_SOCKET_CONNECT_TIMER, 5000, Tracker_Socket_TCP_ReConnect);
        }
    }
}

#endif

/*****************************************************************************
 *  Global Functions			全局函数
 *****************************************************************************/
/******************************************************************************
*  Function    -  Tracker_socket_APN_Set
*
*  Purpose     -  网络连接前设置APN
*
*  Description -
*
* modification history
* ----------------------------------------
* v1.0  , 2012-06-01,  guojie  written
* ----------------------------------------
******************************************************************************/
void Tracker_socket_APN_Set(void)
{
#if defined(__SOC_DEBUG__)
	LOGD(L_OS, L_V5, "begin");
#endif/*__SOC_DEBUG__*/

    Tracker_Socket_ApnSet_Req(NULL, (char*)tracker_apn_param.apn, Tracker_Socket_ApnSet_Rsp);
}


/*****************************************************************************
*  Function    -  Tracker_Socket_Initial
*
*  Purpose     -  Socket初始化准备
*
*  Description -
*
* modification history
* ----------------------------------------
* v1.0  , 2011-11-03,  guojie  written
* ----------------------------------------
*****************************************************************************/
void Tracker_Socket_Initial(void)
{
#if defined(__SOC_DEBUG__)
    LOGD(L_OS, L_V5, "begin");
#endif/*__SOC_DEBUG__*/

#if defined(__PROJ_MODEM__)  //模块工程连接方式
    //set socket connect bearer type is gprs
    Tracker_Socket_Update_AccountID_PS();

    StartTimer(TRACKER_SOCKET_START_TIMER, 5 * 1000, Tracker_Socket_TCP_Start);

    SetProtocolEventHandler(Tracker_Process_Abm_Profile_Ind_Handler, MSG_ID_MMI_ABM_PROFILE_QUERY_IND);
#else

#if defined(__ACC_DETECT__)
    //初始化上传间隔点时间
    if(tracker_acc_state == ACC_ON)
    {
        tracker_ctrl_data.gps_time_interval = tracker_ctrl_data.gps_accon_interval;
        tracker_ctrl_data.status_time_interval = tracker_ctrl_data.status_accon_interval;
    }
    else
    {
        tracker_ctrl_data.gps_time_interval = tracker_ctrl_data.gps_accoff_interval;
        tracker_ctrl_data.status_time_interval = tracker_ctrl_data.status_accoff_interval;
    }
#endif/*__ACC_DETECT__*/

    //5S上传一条则1分钟备份12条
    if(tracker_ctrl_data.gps_time_interval == 5000)
    {
        GPSBackupSum1Min = 20;
    }
    //10S以上则1分钟备份10条
    else if(tracker_ctrl_data.gps_time_interval >= 10000)
    {
        GPSBackupSum1Min = 10;
    }
    else
    {
        GPSBackupSum1Min = 10;
    }

    /*常连接开机才启动SOCKET连接*/
    StartTimer(TRACKER_SOCKET_START_TIMER,  1000, Tracker_Socket_TCP_Start);

#endif
}


/******************************************************************************
 *  Function    -  Tracker_Socket_TCP_Close
 *
 *  Purpose     -GPRS连接关闭
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-09-22,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
void Tracker_Socket_TCP_Close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__SOC_DEBUG__)	
    LOGD(L_OS, L_V5, "SOC Close, soc_id is:%d", soc_content.soc_id);
#endif/*__SOC_DEBUG__*/
#if defined(__LED_APP__)
	if(sys_gsm_state != GSM_NORMAL_STATE)
	{
		sys_gsm_state = GSM_NORMAL_STATE;
        LED_GSM_StatusSet(sys_gsm_state);
    }
#endif

    Heartbeat_SendTimes = 0;
    tracker_login_info.Success = FALSE;
    soc_content.soc_state = SOC_INVALID;
    soc_content.sendstate = SOCKET_CLOSING;
    soc_close(soc_content.soc_id);

    /*关闭时释放资源，避免出现网络阻塞*/
    cbm_release_bearer(soc_content.cbm_app_id);
    cbm_deregister_app_id(soc_content.cbm_app_id);

    StopTimer(TRACKER_LOGIN_INFORMATION_SEND_TIMER);
    StopTimer(GPRS_SEND_SEESOS_TIMER);
    StopTimer(GPRS_SEND_LBS_TIMMER);
    StopTimer(GPRS_SEND_STATUS_TIMMER);
    StopTimer(LBS_BASESTATION_DETECT_TIMER);
    StopTimer(TRACKER_SOCKET_HEARTBEAT_OVERTIME);
#if defined(__GPS_ON_MTK__)
    StopTimer(GPRS_SEND_GPS_TIMMER);
    //ylm 12.13 StopTimer(GPS_DISTANCE_DETECT_TIMER);
#endif  /*__GPS_ON_MTK__*/
#if defined(__AGPS_EPO_SUPPORT__)
    AGPSPacketSendTimes = 0;
    StopTimer(TRACKER_SOCKET_PASSAGPS_OVERTIME);
#endif

#if defined(__GS503__)
#if defined(__GK306__)
    Tracker_Show_GPRS_Icon();
#elif defined(__GS503__)
    ShowSubLcdIconsStatus();
#endif/*__GS503__*/
#endif

    //备份数据发送失败，断开链接时要把这里的数据清除
    //否则下次联网成功继续发送GPS备份数据导致联网一直不成功
    //SOC断开连接，要启动备份数据
    GPS_Backup_Save_Data_SOCClose();
}


/*****************************************************************************
*  Function    -  Tracker_Socket_TCP_ReConnect
*
*  Purpose     -  TCP IP重连接
*
*  Description -
*
* modification history
* ----------------------------------------
* v1.0  , 2011-11-04,  guojie  written
* ----------------------------------------
*****************************************************************************/
void Tracker_Socket_TCP_ReConnect(void)
{
#if defined(__SOC_DEBUG__)
    LOGD(L_OS, L_V5, "   SOC reconnet %d,%d,%d", mmi_bootup_is_sim_valid(), tracker_ctrl_data.GPRSAlwaysOn, IsMyTimerExist(TRACKER_SOCKET_CONNECT_OVERTIMER));
#endif/*__SOC_DEBUG__*/
    if(IS_IN_CALL())
    {
        StartTimer(TRACKER_SOCKET_CONNECT_TIMER, 60 * 1000, Tracker_Socket_TCP_ReConnect);
        return;
    }

    if((mmi_bootup_is_sim_valid() == MMI_TRUE) && (PhoneTestMode == FALSE) && (tracker_ctrl_data.GPRSAlwaysOn == 1 || tracker_ctrl_data.GPRSAlwaysOn == 2))
    {
        if(AlreadyGetNetworkId == FALSE)
        {
            StartTimer(TRACKER_SOCKET_CONNECT_TIMER, 30 * 1000, Tracker_Socket_TCP_ReConnect);
        }
        else
        {
			/*进入到没网络的地方把网络ID清0*/
			if(soc_content.nwt_account_id == 0)
			{
				StartTimer(TRACKER_SOCKET_START_TIMER , 10 * 1000,  Tracker_Socket_TCP_Start);
			}
			else
			{
				StartTimer(TRACKER_SOCKET_START_TIMER , 20 * 1000,  Tracker_Socket_TCP_ReStart);
			}
		}
	}

    if(!IsMyTimerExist(TRACKER_SOCKET_CONNECT_OVERTIMER) && (tracker_ctrl_data.GPRSAlwaysOn == 1))
    {
	#if defined(__NEW_PROTOCOL__)
        StartTimer(TRACKER_SOCKET_CONNECT_OVERTIMER, 20*60*1000, Tracker_Soc_Reset);
	#elif defined(__OLD_PROTOCOL__)
        StartTimer(TRACKER_SOCKET_CONNECT_OVERTIMER, 10*60*1000, Tracker_Soc_Abnormal_Reset);
	#endif
    }
}

/******************************************************************************
 *  Function    -  Tracker_GPRS_Socket_Send_Req
 *
 *  Purpose     -  GPRS连接发送数据请求
 *
 *  Description -  在11B上用08B的队列发送会重启
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2012-06-06,  guojie arrange
 * ----------------------------------------
 ******************************************************************************/
void Tracker_GPRS_Socket_Send_Req(U8* data, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ret;
    vec_gprs_socket_send_struct* buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_prompt_trace(MOD_TST,"Tracker_GPRS_Socket_Send_Req, len is:%d, data is:%s", len, data);
#if defined(__SOC_DEBUG__)
	LOGD(L_OS, L_V5, " %d", len);
#endif/*__SOC_DEBUG__*/

    //加了此句会在LOGD里面进入死循环，一直重复打一个日志导致重启
	kal_prompt_trace(MOD_TST,"vec_socket_send is:%d", vec_socket_send);

    if(NULL == vec_socket_send)
    {
	#if defined(__SOC_DEBUG__)
		LOGD(L_SOC, L_V5, " createInstance %d", len);
	#endif/*__SOC_DEBUG__*/

        VECTOR_CreateInstance(vec_socket_send);
		kal_prompt_trace(MOD_TST,"VECTOR_CreateInstance success");
    }

    //发送长度大于最大值，或等于0会导致发送数据ret =65536
    if(len > MAX_SND_BUFFER_SIZE || len == 0)
    {
        return;
    }
    else
    {
        buf = (vec_gprs_socket_send_struct*)RamBuffer_Alloc(sizeof(vec_gprs_socket_send_struct));
        if(buf)
        {
        	kal_prompt_trace(MOD_TST,"Tracker_GPRS_Socket_Send_Req success get RAM!");
            buf->status = 0;
            memcpy(buf->buffer , data , len);
            buf->len =  len;
            VECTOR_PushBack(vec_socket_send, buf);
            if(!IsMyTimerExist(TRACKER_SOCKET_SEND_TIMER_ID))
            {
                StartTimer(TRACKER_SOCKET_SEND_TIMER_ID, 1000, Tracker_Socket_Send);
            }
        }
        else
        {
            kal_prompt_trace(MOD_TST, "Tracker_GPRS_Socket_Send_Req can not get RAM!");
		#if defined(__SOC_DEBUG__)
			LOGD(L_OS, L_V5, " (can not get RAM!)");
		#endif/*__SOC_DEBUG__*/
        }
	}
}

#if defined(__GK301__)||defined(__GK306__)
/******************************************************************************
 *  Function    -  Tracker_Server_Feedback_OverTime
 *
 *  Purpose     -  定时检测从服务收到回应包，验证连接是否正常
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-11-09,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
void Tracker_Server_Feedback_OverTime(void)
{
#if defined(__SOC_DEBUG__)
    LOGD(L_SOC, L_V5, " Heartbeat_SendTimes=%d", Heartbeat_SendTimes);
#endif/*__SOC_DEBUG__*/
    if(IS_IN_CALL())
    {
        if(soc_content.soc_state != SOC_INVALID)
        {
            Tracker_Socket_TCP_Close();
        }

        if((!IsMyTimerExist(TRAKCER_SOCKET_CALL_TIMER)))
        {
            StartTimer(TRAKCER_SOCKET_CALL_TIMER  , 3 * 60 * 1000, Tracker_Socket_Send_AllType_GPRS_Data);
        }

        if((!IsMyTimerExist(TRACKER_SOCKET_HEARTBEAT_OVERTIME)))
        {
            StartTimer(TRACKER_SOCKET_HEARTBEAT_OVERTIME  , 3 * 60 * 1000, Tracker_Server_Feedback_OverTime);
        }
    }
    else
    {
        Heartbeat_SendTimes ++;
        if(Heartbeat_SendTimes >= 1)
        {
            Heartbeat_SendTimes = 0;
            Tracker_Socket_TCP_Close();
            StartTimer(TRACKER_SOCKET_CONNECT_TIMER, 5000, Tracker_Socket_TCP_ReConnect);
            soc_content.connect_overtimes++;
            if(soc_content.connect_overtimes >= tracker_ctrl_data.gprs_relink_times)
            {
                if(!IsMyTimerExist(TRACKER_SOCKET_CONNECT_OVERTIMER))
                {
                    StartTimer(TRACKER_SOCKET_CONNECT_OVERTIMER, 10 * 60 * 1000, Tracker_Soc_Reset);
                }
                soc_content.connect_overtimes = 0;
            }
        }
    }
}
#elif defined(__GT88__)||defined(__GTM100__)
/******************************************************************************
 *  Function    -  Tracker_Server_Feedback_OverTime
 *
 *  Purpose     -  定时检测从服务收到回应包，验证连接是否正常
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2011-11-09,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
void Tracker_Server_Feedback_OverTime(void)
{
#if defined(__SOC_DEBUG__)
    LOGD(L_OS, L_V5, "   SendTimes=%d,%d", Heartbeat_SendTimes, soc_content.connect_overtimes);
#endif/*__SOC_DEBUG__*/
    kal_prompt_trace(MOD_TST, "Tracker_Server_Feedback_OverTime   SendTimes=%d,%d", Heartbeat_SendTimes, soc_content.connect_overtimes);

    if(IS_IN_CALL())
    {
        if(soc_content.soc_state != SOC_INVALID)
        {
            Tracker_Socket_TCP_Close();
        }

        if((!IsMyTimerExist(TRACKER_SOCKET_HEARTBEAT_OVERTIME)))
        {
            StartTimer(TRACKER_SOCKET_HEARTBEAT_OVERTIME  , 2 * 60 * 1000, Tracker_Server_Feedback_OverTime);
        }
    }
    else
    {
        Heartbeat_SendTimes ++;
        if(Heartbeat_SendTimes >= 1)
        {
            Tracker_Socket_TCP_Close();
            Heartbeat_SendTimes = 0;
            StartTimer(TRACKER_SOCKET_CONNECT_TIMER, 5000, Tracker_Socket_TCP_ReConnect);
        }
    }

#if defined(__GPSBACKUP_BTWTWOHEART__)
    Check_Feedback_OverTime_GPS_LBS_Pack();
#endif

}
#endif

/******************************************************************************
 *  Function    -  Tracker_Enter_NetWork_NoService_Handle
 *
 *  Purpose     -  进入无服务区处理3次则关闭连接

 *  Description -  进入到无服务区，需要连接时G图标一直在
 *
 * modification history  刚进入到无信号区立即出来，不关闭SOC连接出来
 *                                即可立即发送数据到网络，网络也会回复数据
 *soc_content.cbm_app_id 不能在关闭网络之前清楚，否则会导致资源不释放
 * 下一次获取network id fail 而连不上网络
 * ----------------------------------------
 * v1.0  , 2012-11-06,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
void Tracker_Enter_NetWork_NoService_Handle(void)
{
#if defined(__SOC_DEBUG__)
    LOGD(L_OS, L_V5, "  reconnect soc_state=%d,%d", soc_content.soc_state, EnterNoServiceTimes);
#endif/*__SOC_DEBUG__*/
    if(soc_content.soc_state != SOC_INVALID)
    {
        if(EnterNoServiceTimes >= 2)
        {
            soc_content.nwt_account_id = 0;
            EnterNoServiceTimes = 0;
            Tracker_Socket_TCP_Close();
        }
        else
        {
            EnterNoServiceTimes++;
        }
    }
#if defined(__GK306__)
    Tracker_Show_GPRS_Icon();
#endif/*__GS503__*/

}

/******************************************************************************
 *  Function    -  Tracker_Enter_NetWork_FullService_Handle
 *
 *  Purpose     -  进入服务区处理

 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2012-11-06,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
void Tracker_Enter_NetWork_FullService_Handle(void)
{
#if defined(__SOC_DEBUG__)
    LOGD(L_SOC, L_V5, " soc_state=%d,%d", soc_content.soc_state, EnterNoServiceTimes);
#endif/*__SOC_DEBUG__*/

#if defined(__GK306__)
    Tracker_Show_GPRS_Icon();
#endif/*__GS503__*/

    if(tracker_ctrl_data.GPRSAlwaysOn == 1)
    {
        EnterNoServiceTimes = 0;
        if(soc_content.soc_state == SOC_INVALID)
        {
            Tracker_Socket_TCP_ReConnect();
        }

        if(!IsMyTimerExist(TRACKER_CHECK_FULLSERVICE_CONNECT))
        {
            StartTimer(TRACKER_CHECK_FULLSERVICE_CONNECT, 3 * 60 * 1000, Tracker_Enter_NetWork_FullService_Handle);
        }
    }
}

#if defined(__PARAM_BACKUP__)
void backup_restore_reconnect_gprs(void)
{
    if(tracker_ctrl_data.GPRSAlwaysOn == 1)
    {
        Tracker_Socket_TCP_Close();
        StartTimer(TRACKER_SOCKET_START_TIMER, 5 * 1000, Tracker_Socket_TCP_ReConnect);
    }
}
#endif

void tracker_soc_reconnect(void)
{
    if(tracker_ctrl_data.GPRSAlwaysOn == 1)
    {
        Tracker_Socket_TCP_Close();
        StartTimer(TRACKER_SOCKET_START_TIMER, 5 * 1000, Tracker_Socket_TCP_ReConnect);
    }
}

/******************************************************************************
 *  Function    -  System_GetLatLon_Handle
 *
 *  Purpose     -  从服务器获取经纬度
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2013-10-10,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
void System_GetLatLon_Handle(void)
{
    MYTIME CurrTime;
    U8 Timezone_direct;
    U16 Timezone;
    U32 ValueTimezone = 0;

    //时间
    CurrTime.nYear = Soc_Receive_Data.Content[4] + 2000;
    CurrTime.nMonth = Soc_Receive_Data.Content[5];
    CurrTime.nDay = Soc_Receive_Data.Content[6];
    CurrTime.nHour = Soc_Receive_Data.Content[7];
    CurrTime.nMin = Soc_Receive_Data.Content[8];
    CurrTime.nSec = Soc_Receive_Data.Content[9];

    //纬度 30000
    last_latlon_data.lbslat = HEX_To_U32(&Soc_Receive_Data.Content[10], 4);
    //精度 30000
    last_latlon_data.lbslon = HEX_To_U32(&Soc_Receive_Data.Content[14], 4);

    //时区
    // bit15 --bit4  = 8:00   8*100 = 800 = 0x320
    //bit3 -0 东 bit3 --1 西
    //东八区0x32 0x00

#if 0 // 产品部要求禁止服务器通过LBS调整终端时区 cjt
    ValueTimezone = HEX_To_U32(&Soc_Receive_Data.Content[18], 2);

    Timezone_direct = ValueTimezone & 0x0000000F;
    if(Timezone_direct == 1)
    {
        tracker_time_zone.zone = 'W';
    }
    else
    {
        tracker_time_zone.zone = 'E';
    }

    Timezone = (ValueTimezone & 0xFFF0) >> 4;

    tracker_time_zone.time = Timezone / 100;

    tracker_time_zone.time_min = Timezone % 100;
#endif

    //修正时区后调整时间
    GPS_Add_Timezone(&CurrTime);
#if defined(__SOC_DEBUG__)
    LOGD(L_OS,L_V5, " 获取经纬度%d,%d,%d^^ %d-%d-%d,%d:%d:%d", tracker_time_zone.zone, tracker_time_zone.time, tracker_time_zone.time_min, CurrTime.nYear , CurrTime.nMonth , CurrTime.nDay, CurrTime.nHour, CurrTime.nMin , CurrTime.nSec);
#endif/*__SOC_DEBUG__*/
    Update_System_Time(&CurrTime);
	if(DateTime_Update_First == 2)
		DateTime_Update_First = 1;	//xb add 2015-3-19 恢复成非GPS校时状态

    //方向 南北纬，东西经
    last_latlon_data.lbslatlondirect = Soc_Receive_Data.Content[20];
#if defined(__ACC_DETECT__)
    //补传ACC点
    if(tracker_acc_data.upload_accstate > 0)
    {
        tracker_gpspoint_state = TRACKER_GPS_ACC_SEND;
        Tracker_Send_GPS_LBS_Data();
    }
#endif

}


/******************************************************************************
 *  Function    -  Tracker_Socket_TCP_Close_ReConnect
 *
 *  Purpose     -  修改APN等先在线回复后再关闭SOC
 *
 *  Description -  进入到无服务区，需要连接时G图标一直在
 *
 *  Description - //设置服务器后后，这里启动timer 不会去reconnect
 *                       原因待查
 * modification history
 * ----------------------------------------
 * v1.0  , 2014-06-27,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
void Tracker_Socket_TCP_Close_ReConnect(void)
{
#if defined(__SOC_DEBUG__)
    LOGD(L_OS, L_V5, " Close_ReConnect");
#endif/*__SOC_DEBUG__*/
    Tracker_Socket_TCP_Close();
    StartTimer(TRACKER_SOCKET_START_TIMER , 15 * 1000,  Tracker_Socket_TCP_ReStart);
    //这里调reconnect 不响应，调restart 则可以，原因不明,guojie,20140627
    //StartTimer(TRACKER_SOCKET_CONNECT_TIMER, 15 * 1000, Tracker_Socket_TCP_ReConnect);
}

/******************************************************************************
 *  Function    -  Tracker_Socket_Set_GPRS_Detached
 *
 *  Purpose     -  隔段时间检查网络连接是否正常
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2014-07-17,  guojie  written
 * ----------------------------------------
 ******************************************************************************/
void Tracker_Socket_Set_GPRS_Detached(void)
{
    if(tracker_ctrl_data.GPRSAlwaysOn == 1)
    {
        if(soc_content.soc_state >= SOC_CONNECT)
        {
            sprintf(sms_buf, "GPRS Detached successfull!");
        }
        else
        {
            sprintf(sms_buf, "GPRS Detached fail!");
        }
    }
	else
	{
		sprintf(sms_buf, "GPRS Detached fail!");
	}
}

#endif	/*__SOC_APP__*/

