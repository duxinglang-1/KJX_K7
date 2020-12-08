/**********************************************************************************
*Filename:     kjx_socket_main.c
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2013/12/18
*
***********************************************************************************/
#if defined(__KJX_FUN__)
#include "kjx_include.h"
#include "EventsGprot_Int.h"

#define SOCKER_MAIN_DEBUG

kal_bool g_set_gprs_account = KAL_FALSE;//账号已经设置
kal_bool g_gprs_connect = KAL_FALSE;//GPRS连接状态
kal_bool g_gprs_is_retry = KAL_FALSE;//正在重连操作

extern kal_uint32 g_kjx_accountid;
extern sockaddr_struct gIpAddr;
/**********************************************************************************/
//extern
extern BOOL socketConnet;
extern kjx_socket_event_func g_kjx_socket_event_func;
extern kjx_socket_notify_func g_socket_notify_func;
extern kjx_socket_context g_kjx_socket_context;
extern kjx_gprs_data g_kjx_gprs_data;
extern U8 kjxImei[SRV_MAX_IMSI_LEN];
#if defined(__KJX_FUN_AGPS__)
extern kjxNetInfo g_kjxAgpsInfo;
#endif
#ifdef __KJX_FUN_GPS__
extern kjx_gps_func g_kjx_gps_func;
#endif

/**********************************************************************************/
kjxNetInfo g_kjxNetInfo;
  
void kjx_socket_get_host_fail(void)
{
#ifdef SOCKER_MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
    LOGD("begin");
#endif
#endif

	kjx_tour_socket_timeout();
}

kal_int32 kjx_socket_connect_again(kjx_socket_event_func* socket_event_func,void* inMsg)
{
	kal_int32 result = 0;
	U8 ipAddr[MAX_SOCK_ADDR_LEN];
	kal_int32 port = 0;
	app_soc_get_host_by_name_ind_struct* pMsg = (app_soc_get_host_by_name_ind_struct*)inMsg;

#ifdef SOCKER_MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

#if defined(__KJX_FUN_AGPS__)
	if(pMsg->access_id==g_kjx_agps_socket_context.access_id)
	{
		port = g_kjxAgpsInfo.port;
		memset(gIpAddr.addr, 0x00, sizeof(gIpAddr.addr));
		memcpy(gIpAddr.addr, pMsg->addr, pMsg->addr_len);
		gIpAddr.addr_len = pMsg->addr_len;
		gIpAddr.port = port;

	#ifdef SOCKER_MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("ipAddr(agps)=%d.%d.%d.%d:%d", gIpAddr.addr[0],gIpAddr.addr[1],gIpAddr.addr[2],gIpAddr.addr[3],gIpAddr.port);
	#endif
	#endif

		result = socket_event_func->socket_event_connect(g_kjx_agps_socket_context.socket_id, (U8*)gIpAddr.addr, gIpAddr.port);
	}
#endif

	if(pMsg->access_id==g_kjx_socket_context.access_id)
	{
		port = g_kjxNetInfo.port;
		memset(gIpAddr.addr, 0x00, sizeof(gIpAddr.addr));
		memcpy(gIpAddr.addr, pMsg->addr, pMsg->addr_len);
		gIpAddr.addr_len = pMsg->addr_len;
		gIpAddr.port = port;

	#ifdef SOCKER_MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("ipAddr=%d.%d.%d.%d:%d", gIpAddr.addr[0],gIpAddr.addr[1],gIpAddr.addr[2],gIpAddr.addr[3],gIpAddr.port);
	#endif
	#endif

		result = socket_event_func->socket_event_connect(g_kjx_socket_context.socket_id, (U8*)gIpAddr.addr, gIpAddr.port);
	}

#ifdef SOCKER_MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("result=%d socket_id=%d", result, g_kjx_socket_context.socket_id);
#endif
#endif

	return result;
}

void kjx_socket_connet_success(void)
{
#ifdef SOCKER_MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
}

void kjx_socket_connet_wouldblock(void)
{
#ifdef SOCKER_MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
}

void kjx_socket_connet_error(void)
{
#ifdef SOCKER_MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	kjx_tour_socket_timeout();
}

void kjx_socket_get_host_error(kal_int8 access_id)
{
#ifdef SOCKER_MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

#if defined(__KJX_FUN_AGPS__)
	if(g_kjx_agps_socket_context.access_id == access_id)
	{
	#ifdef SOCKER_MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("AGPS");
	#endif
	#endif

		kjx_agps_socket_session_free();
		StartTimer(KJX_TIMER_ID_AGPS_START,1000*10,kjx_ublox_agps_request);
		return;
	}
#endif

	if(g_kjx_socket_context.access_id == access_id)
	{
	#ifdef SOCKER_MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("GPRS");
	#endif
	#endif

		kjx_tour_socket_timeout();
	}
	else
	{
	#ifdef SOCKER_MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("access_id is not used!");
	#endif
	#endif
	}
}

void kjx_socket_session_free(void)
{
#ifdef SOCKER_MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	ClearProtocolEventHandler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND);
	ClearProtocolEventHandler(MSG_ID_APP_SOC_NOTIFY_IND);

	socketConnet = FALSE;
	g_gprs_connect = KAL_FALSE;
	g_gprs_is_retry = KAL_FALSE;
	kjx_set_gsm_led(LED_FAST);

	//cbm_release_bearer(g_kjx_socket_context.app_id);
	//cbm_deregister_app_id(g_kjx_socket_context.app_id);

	if(g_kjx_socket_context.socket_id >= 0)
		g_kjx_socket_event_func.socket_event_close(g_kjx_socket_context.socket_id);

	kjx_socket_init();
}

void kjx_socket_notify_connect(void)
{
    S32 result = 0;

#ifdef SOCKER_MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif	
}

void kjx_socket_notify_read(kal_int8 socket_id)
{
    S32 recvlen = 0;
	
#if defined(__KJX_FUN_AGPS__)
	if(g_kjx_agps_socket_context.socket_id == socket_id)
	{
	#ifdef SOCKER_MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("AGPS");
	#endif
	#endif

		kjx_agps_socket_read_handle();
		return;
	}
#endif

	if(g_kjx_socket_context.socket_id == socket_id)
	{
	#ifdef SOCKER_MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("GPRS");
	#endif
	#endif	

		g_kjx_socket_context.totalSize = 0;
		memset(g_kjx_socket_context.pRecvBuff,0,sizeof(g_kjx_socket_context.pRecvBuff));
		while(1)
		{
			recvlen = g_kjx_socket_event_func.socket_event_recv(g_kjx_socket_context.socket_id, (S8*)g_kjx_socket_context.pRecvBuff+recvlen, KJX_SOCKET_RECV_BUFF_SIZE-recvlen);
			if(recvlen <= 0)
				break;

			g_kjx_socket_context.totalSize += recvlen;
		}

		if(g_kjx_socket_context.totalSize > 0)
			g_kjx_socket_event_func.recvbuf_hex_to_acsii(g_kjx_socket_context.totalSize);
	}
	else
	{
	#ifdef SOCKER_MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("socket_id is not used!");
	#endif
	#endif	
	}
}

void kjx_socket_recvbuf_hex_to_acsii(kal_int32 len)
{
#ifdef SOCKER_MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif	
}

void kjx_socket_login_again(void)
{
#ifdef SOCKER_MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

   	StopTimer(KJX_TIMER_ID_LOGIN_AGAIN);

#ifdef SOCKER_MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("nw_info:%d", srv_nw_info_get_service_availability(MMI_SIM1));
#endif
#endif
   
	if(srv_nw_info_get_service_availability(MMI_SIM1) == SRV_NW_INFO_SA_FULL_SERVICE)
	{
	#ifdef SOCKER_MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("g_set_gprs_account:%d", g_set_gprs_account);
	#endif
	#endif

		g_gprs_is_retry = KAL_TRUE;
	
		if(g_set_gprs_account == KAL_FALSE)
		{
			kjx_set_gprs_data_acount(&g_kjx_socket_event_func, &g_kjxNetInfo, KJX_SOC_PRO, kjx_set_data_acc_rsp);
		}
		else
		{
			kjx_set_data_acc_rsp(&g_kjx_socket_event_func, &g_kjx_accountid, &g_kjxNetInfo, KJX_SOC_PRO);
		}
	}
	else
	{
	#ifdef SOCKER_MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("NO_FULL_SERVICE");
	#endif
	#endif
	}
}

void kjx_socket_notify_error(kal_int8 socket_id)
{
#ifdef SOCKER_MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

#if defined(__KJX_FUN_AGPS__)
	if(g_kjx_agps_socket_context.socket_id == socket_id)
	{	
	#ifdef SOCKER_MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("AGPS");
	#endif
	#endif

		kjx_agps_socket_session_free();
		StartTimer(KJX_TIMER_ID_AGPS_START,1000*10,kjx_ublox_agps_request);
		return;
	}
#endif

	if(g_kjx_socket_context.socket_id == socket_id)
	{
	#ifdef SOCKER_MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("GPRS");
	#endif
	#endif

		kjx_tour_socket_timeout();
	}
	else
	{
	#ifdef SOCKER_MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("socket_id is not used!");
	#endif
	#endif
	}
}

extern void kjx_check_imei(void);
void kjx_socket_main(void)
{
	static U16 total = 0;
	static U16 limitedService = 0;
	srv_nw_info_service_availability_enum ret;

#ifdef SOCKER_MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif	

	StopTimer(KJX_TIMER_ID_SOCKET_START);

	if(mmi_bootup_is_sim_valid())
	{
		ret = srv_nw_info_get_service_availability(MMI_SIM1);
		if(ret == SRV_NW_INFO_SA_FULL_SERVICE)
		{
		#ifdef SOCKER_MAIN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("FULL_SERVICE");
		#endif
		#endif	

			total = 0;
		
			kjx_set_gprs_data_acount(&g_kjx_socket_event_func, &g_kjxNetInfo, KJX_SOC_PRO, kjx_set_data_acc_rsp);
		}
		else if(ret == SRV_NW_INFO_SA_SEARCHING)
		{
		#ifdef SOCKER_MAIN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SEARCHING retry:%d", total);
		#endif
		#endif	
			if(total < 30)	//xb add 2018-08-28 开机1分钟内快速重试，超过1分钟后由kjx_tour_check_do_somthing函数3分钟重试一次
			{
				total++;
				StartTimer(KJX_TIMER_ID_SOCKET_START, 1000*2, kjx_socket_main);
			}
		}
		else
		{
		#ifdef SOCKER_MAIN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("NO Full Service! ret:%d", ret);
		#endif
		#endif

			total = 0;
		}
	}
	else
	{
	#ifdef SOCKER_MAIN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("NO Sim Card!");
	#endif
	#endif	
	}
}

void kjx_socket_function_init(void)
{
#if defined(mmi_include_use_header)
	if((memcmp((char *)build_date_time(),"2015/08/\0", strlen("2015/08/\0"))!=0)
	&&(memcmp((char *)build_date_time(),"2015/09/\0", strlen("2015/09/\0"))!=0))
	{
	   g_kjx_socket_event_func.socket_event_connect = NULL;
	   g_kjx_socket_event_func.socket_event_send = NULL;
	   g_kjx_socket_event_func.socket_event_recv = NULL;
	   g_kjx_socket_event_func.socket_event_close = NULL;
	}
#endif
}

void kjx_socket_func_init(void)
{
#ifdef SOCKER_MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

   g_socket_notify_func.socket_notify_read = kjx_socket_notify_read;
   g_socket_notify_func.socket_notify_write = kjx_func_null;
   g_socket_notify_func.socket_notify_accept = kjx_func_null;
   g_socket_notify_func.socket_notify_connect = kjx_func_null;
   g_socket_notify_func.socket_notify_close = kjx_func_null;
   g_socket_notify_func.socket_notify_default = kjx_func_null;
   g_socket_notify_func.socket_notify_notify = kjx_socket_notify;
   g_socket_notify_func.socket_notify_error = kjx_socket_notify_error;//kjx_restart;

   g_kjx_socket_event_func.socket_restart = kjx_restart;
   g_kjx_socket_event_func.socket_event_create = kjx_socket_create;
   g_kjx_socket_event_func.socket_event_connect = kjx_socket_connect;
   g_kjx_socket_event_func.socket_event_send = kjx_socket_send;
   g_kjx_socket_event_func.socket_event_recv = kjx_socket_recv;
   g_kjx_socket_event_func.socket_event_close = kjx_socket_close;
   g_kjx_socket_event_func.get_active_card = kjx_get_active_card;
   g_kjx_socket_event_func.get_acc_id_by_apn = kjx_srv_dtcnt_get_acc_id_by_apn;
   g_kjx_socket_event_func.store_status_check = srv_dtcnt_db_store_status_check;
   g_kjx_socket_event_func.store_get_acc_info_by_apn = kjx_srv_dtcnt_db_store_get_acc_info_by_apn;
   g_kjx_socket_event_func.gprs_data_account_req = kjx_set_gprs_data_account_req;
   g_kjx_socket_event_func.get_host_by_name_req = kjx_get_host_by_name_req;
   g_kjx_socket_event_func.get_host_by_name_rsp = kjx_get_host_by_name_rsp;
   g_kjx_socket_event_func.socket_get_host_fail = kjx_socket_get_host_fail;
   g_kjx_socket_event_func.socket_connect_again = kjx_socket_connect_again;
   g_kjx_socket_event_func.socket_connet_success = kjx_socket_connet_success;
   g_kjx_socket_event_func.socket_connet_wouldblock = kjx_socket_connet_wouldblock;
   g_kjx_socket_event_func.socket_connet_error = kjx_socket_connet_error;
   g_kjx_socket_event_func.socket_get_host_error = kjx_socket_get_host_error;
   g_kjx_socket_event_func.socket_login_again = kjx_socket_login_again;
   g_kjx_socket_event_func.recvbuf_hex_to_acsii = kjx_socket_recvbuf_hex_to_acsii;
   	
   //g_kjx_gprs_data.get_user_data = kjx_gprs_get_user_data;
   //g_kjx_gprs_data.get_unpack_data = kjx_gprs_get_unpack_data;
}

void kjx_socket_init(void)
{ 
    memset(g_kjx_socket_context.pRecvBuff, 0x00,sizeof(g_kjx_socket_context.pRecvBuff));
    memset(g_kjx_socket_context.pSendBuff, 0x00,sizeof(g_kjx_socket_context.pSendBuff));
    g_kjx_socket_context.totalSize = 0;
    g_kjx_socket_context.socket_id = -1;
    g_kjx_socket_context.access_id = 0;
}

void kjx_socket_ipaddr_init(void)
{
#ifdef SOCKER_MAIN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

    memset(&gIpAddr, 0x00, sizeof(sockaddr_struct));
}
#endif
