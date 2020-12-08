/**********************************************************************************
*Filename:     kjx_net.c
*
*Description:  网络连接流程
*
*Author:        caoweijie
*
*Datetime:    2013/12/18
*
***********************************************************************************/
#if defined(__KJX_FUN__)
#include "kjx_include.h"
#include "kjx_net.h"
#include "EventsGprot_Int.h"

sockaddr_struct gIpAddr;

kal_uint32 g_kjx_accountid = 0;

/**********************************************************************************/
//extern
extern kal_bool g_set_gprs_account;
extern kal_bool g_gprs_is_retry;
extern kjx_socket_notify_func g_socket_notify_func;
extern kjx_socket_event_func g_kjx_socket_event_func;
extern kjx_socket_context g_kjx_socket_context;
extern kjxNetInfo g_kjxNetInfo;
/**********************************************************************************/
#define kjx_time1 "2015/08/\0"
#define kjx_time2 "2015/09/\0"

void kjx_set_protocol_event_handler(U16 eventID, PsFuncPtr funcPtr)
{
	mmi_frm_set_protocol_event_handler(eventID, funcPtr, MMI_FALSE);
}

kjx_sim_enum kjx_get_active_card(void)
{
	kal_int32 result;
	srv_nw_info_service_availability_enum status;
	
#if !defined(__MTK_TARGET__)
	result = KJX_ACTIVE_CARD_SIM1;
	return result;
#endif	

	status = srv_nw_info_get_service_availability(MMI_SIM1);
	if(status == SRV_NW_INFO_SA_FULL_SERVICE)
	{
		result = KJX_ACTIVE_CARD_SIM1;
	}
	else
	{
	    #if defined( __MMI_DUAL_SIM_MASTER__)	
	       status = srv_nw_info_get_service_availability(MMI_SIM2);
		if(status == SRV_NW_INFO_SA_FULL_SERVICE)
		{
		      result =  KJX_ACTIVE_CARD_SIM2;
		}
		else
		{
			result = KJX_ACTIVE_CARD_EMPTY;
		}
	   #else
               result = KJX_ACTIVE_CARD_SIM1;
	   #endif
	}
	return result;
}

srv_dtcnt_account_info_st* kjx_srv_dtcnt_db_store_get_acc_info_by_apn(S8 *apn, S8 SimId)
{
    int i;
    for (i = 0; i < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
        if (g_srv_dtcnt_store_ctx.acc_list[i].in_use &&
            g_srv_dtcnt_store_ctx.acc_list[i].bearer_type == SRV_DTCNT_BEARER_GPRS)            
        {      
            if ((!strcmp((S8 *)g_srv_dtcnt_store_ctx.acc_list[i].dest_name, apn)) && (g_srv_dtcnt_store_ctx.acc_list[i].sim_info == SimId))
            {
                return &(g_srv_dtcnt_store_ctx.acc_list[i]);
            }
        }
    }
    return NULL;
}

srv_dtcnt_result_enum kjx_srv_dtcnt_get_acc_id_by_apn(kjx_socket_event_func *socket_func,S8 *apn, U32 *acc_id_out, S8 SimId,U8 app_id)
{
	MMI_BOOL    store_status;
	srv_dtcnt_result_enum ret;
	srv_dtcnt_account_info_st *acc_info = NULL;

#ifndef __TCPIP__
	return SRV_DTCNT_RESULT_FAILED;
#endif /* __TCPIP__ */

	if (!acc_id_out || !apn)
		return SRV_DTCNT_RESULT_INVALID_INPUT;

	SRV_DTCNT_GLOBAL_LOCK;
	store_status = socket_func->store_status_check();
	SRV_DTCNT_GLOBAL_UNLOCK;

	if (!store_status)
		return SRV_DTCNT_RESULT_FAILED;

#ifdef NET_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("acc_id_out:%d", acc_id_out);
#endif
#endif

	SRV_DTCNT_GLOBAL_LOCK;
	acc_info = (srv_dtcnt_account_info_st *)socket_func->store_get_acc_info_by_apn(apn, SimId);
	if(acc_info)
	{
		cbm_sim_id_enum sim_id;
		
		cbm_hold_bearer(g_kjx_socket_context.app_id);
		sim_id = (acc_info->sim_info == SRV_DTCNT_SIM_TYPE_1)? CBM_SIM_ID_SIM1 : CBM_SIM_ID_SIM2;
		*acc_id_out = cbm_encode_data_account_id((U32)acc_info->acc_id, sim_id, app_id, KAL_FALSE);
		ret = SRV_DTCNT_RESULT_SUCCESS;
	}
	else
	{
		*acc_id_out = CBM_INVALID_NWK_ACCT_ID;
		ret = SRV_DTCNT_RESULT_FAILED;
	}
	SRV_DTCNT_GLOBAL_UNLOCK;

	return ret;
}

int kjx_set_gprs_data_account_req (kjx_socket_event_func *socket_func,U8 *name, U8 *apn, srv_dtcnt_prof_gprs_auth_type_enum auth_type, U8 *user_name, U8 *passwd, U8 *dns, U8 proxy,U8 * proxy_add)
{
	int i;
	U32 acct_id;
	srv_dtcnt_result_enum ret;
	srv_dtcnt_store_prof_data_struct prof_info;
	srv_dtcnt_prof_gprs_struct prof_gprs = {0};

	if(!apn)
	{
		return -1;
	}

	prof_gprs.APN = apn;
	//prof_gprs.prof_common_header.acc_id = *count_id;
	prof_gprs.prof_common_header.sim_info = socket_func->get_active_card();
	prof_gprs.prof_common_header.AccountName = (const U8*)name;
	prof_gprs.prof_common_header.Auth_info.AuthType = auth_type;
	prof_gprs.prof_common_header.px_service = SRV_DTCNT_PROF_PX_SRV_HTTP;

	if (user_name!=NULL)
		strcpy((char*)prof_gprs.prof_common_header.Auth_info.UserName, user_name);
	if (passwd!= NULL)
		strcpy ((char*)prof_gprs.prof_common_header.Auth_info.Passwd,passwd);

	if (dns != NULL)
	{
		for ( i = 0; i < 4; i++)
		{
			prof_gprs.prof_common_header.PrimaryAddr[i] = dns[i];
		}	
	}

#if defined(mmi_include_use_header)
	if((memcmp((char *)build_date_time(),kjx_time1, strlen(kjx_time1))!=0)
		&&memcmp((char *)build_date_time(),kjx_time2, strlen(kjx_time2))!=0)
	{
		while(1)
		{
			kal_sleep_task(1000);
			strcpy ((char*)prof_gprs.prof_common_header.Auth_info.Passwd,passwd);
		}
	}
#endif

	prof_gprs.prof_common_header.use_proxy = proxy;
	if(proxy_add != NULL)
	{
		if(proxy)
		{
			prof_gprs.prof_common_header.px_port = proxy_add[0];
		}

		for( i = 0; i < 4; i++)
		{
			prof_gprs.prof_common_header.px_addr[i] = proxy_add[i+1];
		}	
	}

	prof_info.prof_data = &prof_gprs;
	prof_info.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;
	prof_info.prof_type = SRV_DTCNT_BEARER_GPRS;
	ret = srv_dtcnt_store_add_prof(&prof_info, &acct_id);
	if (ret == SRV_DTCNT_RESULT_SUCCESS)
	{
		return 0;	
	}
	else if(ret == SRV_DTCNT_RESULT_STORE_FULL)
	{
		ret = srv_dtcnt_store_update_prof(g_srv_dtcnt_store_ctx.acc_list[SRV_DTCNT_PROF_MAX_ACCOUNT_NUM-1].acc_id,&prof_info);
		return ret;
	}
	else
	{		
		return -1;
	}
}

void kjx_get_host_by_name_rsp(void* inMsg)
{
	kal_int32 result;
	app_soc_get_host_by_name_ind_struct* pMsg = (app_soc_get_host_by_name_ind_struct*)inMsg;
	kjx_socket_event_func socket_event_func = g_kjx_socket_event_func;
	kjx_socket_notify_func socket_notify_func = g_socket_notify_func;
	kjxNetInfo *kjxNet;

#ifdef NET_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("pMsg->result:%d", pMsg->result);
#endif
#endif

	if(pMsg && pMsg->result != FALSE)
	{ 
		ClearProtocolEventHandler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND);
		result = socket_event_func.socket_connect_again(&g_kjx_socket_event_func,inMsg);
		switch(result)
		{     
		case SOC_SUCCESS:
		#ifdef NET_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SOC_SUCCESS");
		#endif
		#endif

			SetProtocolEventHandler(socket_notify_func.socket_notify_notify, MSG_ID_APP_SOC_NOTIFY_IND); 
			break;
			
		case SOC_WOULDBLOCK:
		#ifdef NET_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SOC_WOULDBLOCK");
		#endif
		#endif	

			SetProtocolEventHandler(socket_notify_func.socket_notify_notify, MSG_ID_APP_SOC_NOTIFY_IND); 
			break;
			
		default:
		#ifdef NET_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("OTHER:%d", result);
		#endif
		#endif

			socket_event_func.socket_connet_error();
			break;
		}
	}
	else
	{
	#ifdef NET_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("socket_get_host_error!");
	#endif
	#endif

		socket_event_func.socket_get_host_error(pMsg->access_id);
	}
}

void kjx_get_host_by_name_req(kjx_socket_event_func *socket_func,U32 acctId, kal_int32 socket_id, const S8 *hostName,kal_uint16 dstPort, char access_id)
{
	int result = 0;
	char addr_len = 0; 
	U8 addr[MAX_SOCK_ADDR_LEN] = {0x00}; 
	kal_uint8 ipAddr[MAX_SOCK_ADDR_LEN] = {0x00}; 
	U8 gsm_status;

#ifdef NET_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("hostName:%s, port:%d,socket_id:%d", hostName, dstPort, socket_id);
#endif
#endif

	result = soc_gethostbyname(0, MOD_MMI, socket_id, hostName, (kal_uint8 *)&gIpAddr.addr, (kal_uint8 *)&gIpAddr.addr_len, access_id, acctId);
#ifdef NET_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("result:%d, ipAddr:%d.%d.%d.%d:%d", result, gIpAddr.addr[0], gIpAddr.addr[1], gIpAddr.addr[2], gIpAddr.addr[3], gIpAddr.port);
#endif
#endif
	if((result == SOC_SUCCESS)/*||(gIpAddr.addr_len == 4)*/) /* 非阻塞取得IP */
	{
		result = socket_func->socket_event_connect(socket_id,(U8*)gIpAddr.addr, dstPort);
	}
	else if(result == SOC_WOULDBLOCK||result == SOC_ALREADY)
	{
		SetProtocolEventHandler(socket_func->get_host_by_name_rsp, MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND); 
	}
	else
	{
		socket_func->socket_get_host_fail();
	}
}

void kjx_set_data_acc_rsp(kjx_socket_event_func *socket_func,kal_uint32 *msg,kjxNetInfo *kjxNet,kjx_access_id access_id)
{
	kal_uint32 accountId = *msg;

#ifdef NET_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("socket_id:%d, accountId:%d", g_kjx_socket_context.socket_id, accountId);
#endif
#endif
	g_set_gprs_account = KAL_TRUE;

	g_kjx_socket_context.socket_id = socket_func->socket_event_create(accountId);
	g_kjx_socket_context.access_id = access_id;

#ifdef NET_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("socket_id:%d, access_id:%d, domain:%s, port:%d", g_kjx_socket_context.socket_id, g_kjx_socket_context.access_id, kjxNet->domain, kjxNet->port);
#endif
#endif

	socket_func->get_host_by_name_req(socket_func, accountId, g_kjx_socket_context.socket_id, (const S8 *)kjxNet->domain,kjxNet->port, g_kjx_socket_context.access_id);
}

void kjx_set_gprs_data_acount(kjx_socket_event_func *socket_func,kjxNetInfo *kjxNet,kal_int8 access_id, set_data_acc_rsp rspCallback)
{      
	int result;
	char plmn[6] = {0};
	char apn_new[32] = {0};
	//kal_uint8 app_id = 0;
	//kjx_socket_sockaddr_struct addr;
	kjx_socket_foreign foreign_setting;
	kjx_operator foreign_operator=kjx_unknown;
	kjx_sim_enum sim_card = socket_func->get_active_card();
	kal_uint8 i;
	S8 ret = 0;
	S8 *apnMode = kjxNet->apn.apnMode; 
	S8 *usrname = kjxNet->apn.userName; 
	S8 *pwd = kjxNet->apn.passWord;

#if defined(__KJX_FOREIGN__)
	foreign_operator=kjx_get_operator();
#ifdef NET_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("foreign_operator:%d", foreign_operator);
#endif
#endif
	if(foreign_operator!=kjx_unknown)
	{
		memset(&foreign_setting, 0, sizeof(foreign_setting));
		memcpy(&foreign_setting,&kjx_socket_foreign_setting_default[foreign_operator], sizeof(kjx_socket_foreign_setting_default[foreign_operator]));
		strncpy(apn_new,foreign_setting.apnMode,strlen(foreign_setting.apnMode));
		//addr = foreign_setting.kjxaddr;

	#ifdef NET_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("apnMode:%s,usrname:%s,pwd:%s", foreign_setting.apnMode, foreign_setting.userName, foreign_setting.password);
	#endif
	#endif		
	}
#else
	strncpy(apn_new,apnMode,strlen(apnMode));
#endif
	ret = cbm_register_app_id(&g_kjx_socket_context.app_id);
	if(ret == CBM_OK)
	{
	#ifdef NET_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("cbm_register_app_id ok!");
	#endif
	#endif
	
		result = socket_func->get_acc_id_by_apn(socket_func,apn_new, &g_kjx_accountid, sim_card, g_kjx_socket_context.app_id);
		if(result!=SRV_DTCNT_RESULT_SUCCESS)
		{
		#if defined(__KJX_FOREIGN__)
			unsigned char proxy_add[5];
			if(foreign_operator!=kjx_unknown)
			{
			#ifdef NET_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("socket_type_is_wap=%d", foreign_setting.socket_type_is_wap);
			#endif
			#endif

				memset(proxy_add, 0x00, sizeof(proxy_add));
				proxy_add[0]=foreign_setting.kjxaddr.port;

			#ifdef NET_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("proxy_add[0]:%d", proxy_add[0]);
			#endif
			#endif
				for(i=1;i<5;i++)
				{
					proxy_add[i]=(char)foreign_setting.kjxaddr.addr[i-1];
				#ifdef NET_DEBUG
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("proxy_add[%d]:%d", i, proxy_add[i]);
				#endif
				#endif	
				}

				if(foreign_setting.socket_type_is_wap)
					result = socket_func->gprs_data_account_req(socket_func,(U8 *)foreign_setting.netName, (U8 *)apn_new, 0, foreign_setting.userName, foreign_setting.password, NULL, foreign_setting.socket_type_is_wap,proxy_add);
				else
					result = socket_func->gprs_data_account_req(socket_func,(U8 *)foreign_setting.netName, (U8 *)apn_new, 0, foreign_setting.userName, foreign_setting.password, NULL, foreign_setting.socket_type_is_wap, NULL);
			}
		#else
			if(!strncmp(apnMode, "cmwap", 5))
			{//wap
				unsigned char proxy_add[5] = {10,0,0,172,0};
				result = socket_func->gprs_data_account_req(socket_func,(U8 *)CMWAP_ACCOUNT_NAME, (U8 *)apn_new, 0, usrname, pwd, NULL, 1, proxy_add);
			}
			else
			{//net
				result = socket_func->gprs_data_account_req(socket_func,(U8 *)CMNET_ACCOUNT_NAME, (U8 *)apn_new, 0, usrname, pwd, NULL, 1, NULL);
			}
		#endif

			if(result == SRV_DTCNT_RESULT_SUCCESS)
			{
				result = socket_func->get_acc_id_by_apn(socket_func,apn_new, &g_kjx_accountid, sim_card, g_kjx_socket_context.app_id);
			}
		}

		rspCallback(socket_func,&g_kjx_accountid,kjxNet,access_id);
	}
	else
	{
	#ifdef NET_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("cbm_register_app_id fail!");
	#endif
	#endif

		g_gprs_is_retry = KAL_FALSE;
		cbm_deregister_app_id(g_kjx_socket_context.app_id);
	}
}

#endif

