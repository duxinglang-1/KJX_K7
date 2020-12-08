/**********************************************************************************
*Filename:     kjx_sms.c
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2013/12/17
*
***********************************************************************************/
#if defined(__KJX_FUN__)
#include "kjx_sms.h"
#include "Kjx_prin.h"

PsFuncPtr kjx_sendSmsCallback;
char input_buf[256];

void kjx_sms_send_sms_callback(srv_sms_callback_struct* callback_data)
{
#ifdef KJX_SMS_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	if(kjx_sendSmsCallback != NULL)
	{
		kjx_sendSmsCallback(callback_data);
	}
}

kal_bool kjx_check_number_different(char* src_num,char* dst_num)
{
	kal_bool result = KAL_TRUE;
	S32 str1_len = 0;
	S32 str2_len = 0;
	S32 short_len = 0;
	char num1_str[32];
	char num2_str[32];
	S32 i = 0;

	if((src_num == NULL) || (dst_num == NULL))
	{ 
		return result;
	}
	

	memset(num1_str,0,sizeof(num1_str));
	memset(num2_str,0,sizeof(num2_str));

	str1_len = strlen(src_num);
	str2_len = strlen(dst_num);
	short_len = ((str1_len)<(str2_len)?(str1_len):(str2_len));

	if(short_len==0)
	{
	   return result;
	}

	if(short_len> 32)
	{
		short_len = 32;
	}
	
	

	for(i = 0;i<str1_len;i++)
	{
		num1_str[i] = src_num[str1_len-i-1];
	}
	for(i = 0;i<str2_len;i++)
	{
		num2_str[i] = dst_num[str2_len-i-1];
	}
	
	if(memcmp(num1_str,num2_str,short_len) == 0)
	{
		result = KAL_FALSE;
	}

	return result;

}

/*set sms send type*/
U16 kjx_get_sms_send_type(void)
{
	U16 sms_send_type;

	sms_send_type = SRV_SMS_FG_SEND; // SRV_SMS_FG_SEND  SRV_SMS_BG_SEND

	return sms_send_type;
}

void kjx_sms_send_sms(char* pAsciiDstNumber, unsigned short * pSMSContent, smsal_dcs_enum contentDcs, PsFuncPtr callback)
{
	int numlen = 0;
	kjx_sim_enum sim;
	SMS_HANDLE srv_send_handle;
	S8 ucs2_addr[(SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
	BOOL isBusy = FALSE;
	U16 sms_send_type;
	U16 content_size;

#if 0
	if(!srv_sms_is_sms_ready()) //not ready 
	{
	#ifdef KJX_SMS_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return:sms is not ready!");
	#endif
	#endif 
		return; 
	}
    else if(srv_sms_check_send_action_pending(SRV_SMS_BG_SEND))
    {
    #ifdef KJX_SMS_DEBUG
	#if defined(__KJX_LOG_OUTPUT__) 
		LOGD("return:SRV_SMS_BG_SEND check_action_pending == TRUE"); 
	#endif
	#endif
		return; 
	}
    else if(srv_sms_check_send_action_pending(SRV_SMS_FG_SEND))
    { 
    #ifdef KJX_SMS_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return:SRV_SMS_FG_SEND check_action_pending == TRUE"); 
	#endif 
	#endif
		return; 
	}

	srv_send_handle = srv_sms_get_send_handle();
	if(srv_send_handle == NULL)
	{
	#ifdef KJX_SMS_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return:get_send_handle FALSE"); 
	#endif 
	#endif
		return;
	}

	memset(ucs2_addr, 0, (SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH);
	mmi_asc_n_to_ucs2((S8*)ucs2_addr, pAsciiDstNumber, numlen+1);

	srv_sms_set_address(srv_send_handle, ucs2_addr);
	srv_sms_set_sim_id(srv_send_handle, SRV_SMS_SIM_1);
	if(contentDcs==SRV_SMS_DCS_UCS2)
	{
		content_size = ENCODING_LENGTH * mmi_ucs2strlen((const char*)pSMSContent); 
		srv_sms_set_content_dcs(srv_send_handle, SRV_SMS_DCS_UCS2);
	}
	else
	{
		content_size = strlen((const char*)pSMSContent); 
		srv_sms_set_content_dcs(srv_send_handle, SMSAL_DEFAULT_DCS);
	}
	srv_sms_set_content(srv_send_handle, (S8*)pSMSContent, content_size);
	srv_sms_set_no_sending_icon(srv_send_handle);
	srv_sms_send_msg(srv_send_handle, kjx_sms_send_sms_callback, NULL);
#else
	sim = kjx_get_active_card();
	sms_send_type = kjx_get_sms_send_type();

	if(sms_send_type == SRV_SMS_BG_SEND)
		isBusy = srv_sms_is_bg_send_action_busy(); //add by zhangping 20150528
	else if(sms_send_type == SRV_SMS_FG_SEND)
		isBusy = srv_sms_is_send_action_busy();

	srv_send_handle = srv_sms_get_send_handle();
	if (srv_send_handle == NULL)
	{
	#ifdef KJX_SMS_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return:get_send_handle FALSE");
	#endif
	#endif
		return;
	}

	if(!srv_sms_is_sms_ready())
	{
	#ifdef KJX_SMS_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return:sms is not ready!");
	#endif
	#endif
		return;
	}
	
	if(isBusy)
	{
	#ifdef KJX_SMS_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return:sms is busy!");
	#endif
	#endif
		return;
	}

	if(KJX_ACTIVE_CARD_EMPTY == sim || strlen(pAsciiDstNumber)==0)
	{
	#ifdef KJX_SMS_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return:sim is empty or num is empty!");
	#endif
	#endif
		return;
	}

	kjx_sendSmsCallback = callback;
	numlen = strlen(pAsciiDstNumber) > MAX_DIGITS_SMS?MAX_DIGITS_SMS:strlen(pAsciiDstNumber);
	if(numlen <= 0)
	{
		if(NULL!=callback)
		{
			callback(NULL);
		}
		return;
	}
	
	srv_send_handle = srv_sms_get_send_handle();
	memset(ucs2_addr, 0, (SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH);
	mmi_asc_n_to_ucs2((S8*)ucs2_addr, pAsciiDstNumber, numlen+1);
	srv_sms_set_address(srv_send_handle, ucs2_addr);
	
	if(KJX_ACTIVE_CARD_SIM2 == sim)
	{
		srv_sms_set_sim_id(srv_send_handle, SRV_SMS_SIM_2);
	}
	else
	{
		srv_sms_set_sim_id(srv_send_handle, SRV_SMS_SIM_1);
	}
	
	if (contentDcs==SRV_SMS_DCS_UCS2)
	{
		srv_sms_set_content_dcs(srv_send_handle, SRV_SMS_DCS_UCS2);
		srv_sms_set_content(srv_send_handle, (S8 *)pSMSContent, mmi_ucs2strlen((const char*)pSMSContent) * 2);
	}
	else
	{
		srv_sms_set_content_dcs(srv_send_handle, SMSAL_DEFAULT_DCS);
		srv_sms_set_content(srv_send_handle, (S8 *)pSMSContent, strlen((const char*)pSMSContent));
	}

	srv_sms_set_no_sending_icon(srv_send_handle);

	if(sms_send_type == SRV_SMS_BG_SEND)
		srv_sms_set_send_type(srv_send_handle, SRV_SMS_BG_SEND);
	else if(sms_send_type == SRV_SMS_FG_SEND)
		srv_sms_set_send_type(srv_send_handle, SRV_SMS_FG_SEND);	

	srv_sms_set_status_report(srv_send_handle, MMI_FALSE);
	srv_sms_send_msg(srv_send_handle, kjx_sms_send_sms_callback, NULL);
#endif	
}


S32 kjx_sms_filter_handle(srv_sms_event_struct *evt)
{
	S32 result = 0;
	U8 *pBuff = NULL;
	S32 messageLen=0;
     
	 
	srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
	srv_sms_event_new_sms_struct* event_info = (srv_sms_event_new_sms_struct *)event_data->event_info;
	srv_sms_new_msg_struct *new_msg_data = (srv_sms_new_msg_struct *)event_info->msg_data;

	kjx_trace("%s, number:%s, dcs:%d, content:%s,len=%d", __func__,new_msg_data->number, new_msg_data->dcs, event_info->content,new_msg_data->message_len);

     
	if((new_msg_data->dcs == SRV_SMS_DCS_UCS2)||(new_msg_data->dcs == SRV_SMS_DCS_7BIT))
	{
		messageLen = (new_msg_data->message_len+2)/2;
		pBuff = get_ctrl_buffer(messageLen);
		memset(pBuff, 0x00, messageLen);
		mmi_ucs2_to_asc(pBuff,  event_info->content);
	}
	else
	{
		messageLen = new_msg_data->message_len;
		pBuff = get_ctrl_buffer(messageLen);
		sprintf((CHAR *)pBuff, "%s", (CHAR *)event_info->content);
	}
	
		kjx_trace("%s2,event_info->content =%s",__func__,event_info->content);

	 
		memset(input_buf, 0x00, sizeof(input_buf));
		memcpy(input_buf,event_info->content, new_msg_data->message_len+2);

   		kjx_trace("%s,input_buf =%s,pBuff=%s",__func__,input_buf,pBuff);
		
		//result = kjx_cmd_process_handle(new_msg_data->number, pBuff);
		kjx_cmd_process_handle(new_msg_data->number, pBuff);

		kjx_trace("sls_sms_filter_handle() result :%d",result);
		
		/*if(result >= CMD_CODE_MAX)
		{	
			result = GT_WRT_cmd_process_handle(new_msg_data->number, pBuff);
		}*/

		kjx_trace("kjx_sms_filter_handle(), number:%d,%d",new_msg_data->msg_id,event_info->msg_id);
	
		free_ctrl_buffer(pBuff);
	
		return result;
}

void kjx_sms_register_filter_handle(void)
{
	kjx_trace("%s",__func__);
	
     srv_sms_reg_port(
            65535,
            SRV_SMS_SIM_1,
            kjx_sms_filter_handle,
            NULL);
}



#endif

