/**********************************************************************************
*Filename:     kjx_socket.c
*
*Description:  socket相关函数
*
*Author:        caoweijie
*
*Datetime:    2013/12/17
*
***********************************************************************************/
#if defined(__KJX_FUN__)
#include "kjx_include.h"
#include "Kjx_prin.h"
#include "EventsGprot_Int.h"

#define KJX_SOCKET_DEBUG

kjx_socket_notify_func g_socket_notify_func;
kjx_socket_event_func g_kjx_socket_event_func;

extern kal_bool g_gprs_connect;

kal_int8 kjx_socket_create(U32 account_id)
{
	kal_int8 ret = 0; 	 
	kal_int8 soc_ret = 0;
	kal_int8 val = KAL_TRUE;

#ifdef KJX_SOCKET_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("account_id:%d", account_id);
#endif
#endif

	kjx_socket_function_init();

#ifndef __MTK_TARGET__
	soc_init_win32();	/* 初始化MTK socket 库 */
#endif

	soc_ret = soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0, MOD_MMI, account_id);

	if(soc_ret >= 0)
	{
		ret = soc_setsockopt(soc_ret, SOC_NBIO, &val, sizeof(val));
		val = SOC_READ|SOC_WRITE|SOC_ACCEPT|SOC_CONNECT|SOC_CLOSE;
		ret = soc_setsockopt((kal_uint8)soc_ret, SOC_ASYNC, &val, sizeof(val));
	} 	
	return soc_ret;
}

kal_int8 kjx_socket_connect(kal_int8 socketId, U8 ip[], U16 port)
{
	kal_int8 ret = 0;
	sockaddr_struct addr;

	memset((void *)&addr, 0x00, sizeof(sockaddr_struct));
	addr.addr_len = 4;
	
	memcpy(addr.addr, ip, addr.addr_len); /* IP is 4Byte U8 number here!*/
	addr.port = port;		
	addr.sock_type=SOC_SOCK_STREAM;

#ifdef KJX_SOCKET_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("addr:%d.%d.%d.%d:%d", addr.addr[0], addr.addr[1], addr.addr[2], addr.addr[3], addr.port);
#endif
#endif	
	
	ret = soc_connect(socketId, &addr);
	kjx_socket_event_handler(SOC_CONNECT,ret);
	return ret;
}

S32 kjx_socket_send(kal_int8 socketId, const S8 *buf, S32 len)
{
	S32 ret = 0;
	kal_int8 *p;

	if(g_gprs_connect)
	{
		ret = soc_send(socketId, (U8 *)buf, len, 0);
	}
	
	return ret;
}

S32 kjx_socket_recv(kal_int8 socketId, const S8 *buf, S32 len)
{
	S32 ret = soc_recv(socketId, (U8 *)buf, len, 0);

#ifdef KJX_SOCKET_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif		

	kjx_socket_event_handler(SOC_READ,ret);
	return ret;
}

kal_int8 kjx_socket_close(kal_int8 socketId)
{
	kal_int8 ret = soc_close(socketId);

#ifdef KJX_SOCKET_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif	

	return ret;
}

void kjx_socket_notify_overtime(void)
{
#ifdef KJX_SOCKET_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	kjx_socket_session_free();
}

void kjx_socket_event_handler(soc_event_enum socket_event,S32 result)
{
	kjx_socket_notify_func g_socket_event_func = g_socket_notify_func;

#ifdef KJX_SOCKET_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("result:%d, socket_event:%d", result, socket_event);
#endif
#endif

	switch(socket_event)
	{
	case SOC_READ:
		if(result == SOC_WOULDBLOCK)
		{ 
			SetProtocolEventHandler(g_socket_event_func.socket_notify_notify, MSG_ID_APP_SOC_NOTIFY_IND);
		}
		break;
		
	case SOC_WRITE:
		break;
		
	case SOC_ACCEPT:
		break;
		
	case SOC_CONNECT:
		if((result == SOC_WOULDBLOCK) || (result == SOC_SUCCESS))
		{
			if(!IsMyTimerExist(KJX_TIMER_ID_SOCKET_NOTIFY_OVERTIME))
            {
                StartTimer(KJX_TIMER_ID_SOCKET_NOTIFY_OVERTIME, 5*60*1000, kjx_socket_notify_overtime);
            }
			SetProtocolEventHandler(g_socket_event_func.socket_notify_notify, MSG_ID_APP_SOC_NOTIFY_IND);
		}
		break;
		
	case SOC_CLOSE:
		kjx_socket_session_free();
		break;
		
	default:
		break;
	}
}

void kjx_socket_notify(void *inMsg)
{
	app_soc_notify_ind_struct *msg = (app_soc_notify_ind_struct *)inMsg;
	kjx_socket_notify_func g_notify_func = g_socket_notify_func;
	
	//ClearProtocolEventHandler(MSG_ID_APP_SOC_NOTIFY_IND);
	StopTimer(KJX_TIMER_ID_SOCKET_NOTIFY_OVERTIME);
	
#ifdef KJX_SOCKET_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("result:%d, socket_id:%d, event_type:%d, ref_count:%d", msg->result,msg->socket_id,msg->event_type, msg->ref_count);
#endif
#endif
	if((msg->result) > 0)
	{
		switch (msg->event_type)
		{
		case SOC_READ:
		#ifdef KJX_SOCKET_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SOC_READ");
		#endif
		#endif
			g_notify_func.socket_notify_read(msg->socket_id);
			break;

		case SOC_WRITE:
		#ifdef KJX_SOCKET_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SOC_WRITE");
		#endif
		#endif	

			g_notify_func.socket_notify_write();
			break;

		case SOC_ACCEPT:
		#ifdef KJX_SOCKET_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SOC_ACCEPT");
		#endif
		#endif	

			g_notify_func.socket_notify_accept();
			break;

		case SOC_CONNECT:
		#ifdef KJX_SOCKET_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SOC_CONNECT");
		#endif
		#endif	
			g_gprs_connect = KAL_TRUE;
		
			g_notify_func.socket_notify_connect(msg->socket_id);
			break;

		case SOC_CLOSE:
		#ifdef KJX_SOCKET_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SOC_CLOSE");
		#endif
		#endif	

		#if defined(__KJX_FUN_AGPS__)
			if(g_kjx_agps_socket_context.socket_id == msg->socket_id)
			{
			#ifdef SOCKER_MAIN_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("AGPS");
			#endif
			#endif
		
				kjx_agps_socket_session_free();
			}
		#endif

			if(g_kjx_socket_context.socket_id == msg->socket_id)
			{
				kjx_socket_session_free();			
			}
			break;

		default:
		#ifdef KJX_SOCKET_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("default");
		#endif
		#endif	

			g_notify_func.socket_notify_default();
			break;
		}
	}
	else
	{
		switch (msg->event_type)
		{
		case SOC_READ:
		#ifdef KJX_SOCKET_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SOC_ERROR:READ");
		#endif
		#endif
			break;

		case SOC_WRITE:
		#ifdef KJX_SOCKET_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SOC_ERROR:WRITE");
		#endif
		#endif	
			break;

		case SOC_ACCEPT:
		#ifdef KJX_SOCKET_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SOC_ERROR:ACCEPT");
		#endif
		#endif	
			break;

		case SOC_CONNECT:
		#ifdef KJX_SOCKET_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SOC_ERROR:CONNECT");
		#endif
		#endif	
			break;

		case SOC_CLOSE:
		#ifdef KJX_SOCKET_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SOC_ERROR:CLOSE");
		#endif
		#endif	
			break;

		default:
		#ifdef KJX_SOCKET_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SOC_ERROR:default");
		#endif
		#endif	
			break;
		}

		g_notify_func.socket_notify_error(msg->socket_id);
	}
}

#endif
