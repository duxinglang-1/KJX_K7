#if defined(__KJX_FUN__)
#if defined(CUSTOMER_NAME_OLDMAN)

#include "kjx_sms_oldman.h"
#include "mmi_rp_app_kjx_def.h"
#include "ProfilesSrvGprot.h"

set_cmd CurrCMD = SET_ERROR;

char superNum[20];
int g_is_sms_send = 0;
U16 kjx_call_index;
U16 sms_send_count = 0;
#if defined(__KJX_FUN_STEPS__)
extern BOOL steps_is_use;
#endif
#ifdef __KJX_SMS_ACTIVATE__
extern U8 kjxImei[SRV_MAX_IMSI_LEN];
#endif  // __KJX_SMS_ACTIVATE__

void kjx_reset_nvram_info(void)
{
	kal_int32 drv;
	FS_HANDLE handle;
	S8 usc2Path[64];
      
	memset(usc2Path, 0x00, sizeof(usc2Path));
	mmi_ucs2cpy((S8*)usc2Path, (const CHAR *)(L"Z:\\@oldman\0"));
	
	handle = FS_SetCurrentDir((WCHAR*)usc2Path);
	   
	if(handle>=FS_NO_ERROR)
	{
		handle = FS_Open(L"nvram\0", FS_READ_ONLY);
		if (handle > 0)
		{
			FS_Close(handle);
		}
		else
		{
			return;
		}
		  
		handle = FS_Delete(L"nvram\0");
	}
}

U8 Slc_toupper(kal_uint8 *str)
{
    kal_uint8 *p= str;
    while(*p != 0)
    {
        if ((*p >= 'a') && (*p <= 'z'))
        {
            *p -= 32;
        }
        p++;
    }
}

void kjx_monitor_make_call(void)
{
	char ucs2Num[64]={0};

	if(g_kjx_oldman_struct.listenStatus&&strlen(g_kjx_oldman_struct.listenNum) != 0)
	{
		memset(ucs2Num, 0x00, sizeof(ucs2Num));
		mmi_asc_to_ucs2(ucs2Num,g_kjx_oldman_struct.listenNum);
	#ifdef SMS_OLDMAN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("listenNum:%s", __func__, g_kjx_oldman_struct.listenNum);
	#endif
	#endif
	}
	else
	{
		;
	}

	MakeCall(ucs2Num);
}

#ifndef __KJX_OBD__
S16 kjx_write_imei_send(void *pBuffer, U16 nBufferSize)
{   
    nvram_ltable_entry_struct *ldi;
    S16 result;

    nvram_util_get_data_item(&ldi, NVRAM_EF_IMEI_IMEISV_LID);
    result = nvram_write_data_item(ldi,1, pBuffer, KAL_FALSE);

    return result;
}

#endif

#ifdef __KJX_SMS_ACTIVATE__
void kjx_sms_send_mode_to_app(U8 *asciiNum,U8 mode)
{
	// 工作模式已设置为:
	char sms_string[]={0xe5,0x5d,0x5c,0x4f,0x21,0x6a,0xf,0x5f,0xf2,0x5d,0xbe,0x8b,0x6e,0x7f,0x3a,0x4e,0x3a,0x0,0x0,0x0};
	//正常模式
	char mod_normal[]={0x63,0x6b,0x38,0x5e,0x21,0x6a,0xf,0x5f,0x0,0x0};
	//省电模式
	char mod_save[]={0x1,0x77,0x35,0x75,0x21,0x6a,0xf,0x5f,0x0,0x0};
	// 模式设置错误,请重新设置.
	char mod_fail[]={0x21,0x6a,0xf,0x5f,0xbe,0x8b,0x6e,0x7f,0x19,0x95,0xef,0x8b,0x2c,0x0,0xf7,0x8b,0xcd,0x91,0xb0,0x65,0xbe,0x8b,0x6e,0x7f,0x2e,0x0,0x0,0x0};
	
	if(strlen(asciiNum)==0)
		return;

	if(mode !=0 && mode !=1)
	{
		kjx_sms_send_sms(asciiNum,(unsigned short*)mod_fail, 0x08, NULL);
		return;

	}
	
	switch(mode)
	{
		case 0:	// 正常模式
		mmi_ucs2cat(sms_string,mod_normal);
			break;
			
		case 1:	// 省电模式
		mmi_ucs2cat(sms_string,mod_save);
			break;
	}

	kjx_sms_send_sms(asciiNum,(unsigned short*)sms_string, 0x08, NULL);
	
}

/*****************************************************************************
 * FUNCTION
 *  kjx_cmd_process_handle
 * DESCRIPTION
 *  Activation of GPRS and something.
 * PARAMETERS
 *  KJX,Equipment No,Project Name(OLDMAN),Mode#
 *  For example:KJX,12345678901234,OLDMAN,1#
 * RETURNS
 *  void
 *****************************************************************************/
void kjx_cmd_process_handle_workmode(U8 *asciiNum, U8 *asciiContent)
{
	const char *str = "KJX";
	const char *pro_name = "OLDMAN";
	char *pos = NULL;
	char mode[6];

	memset(mode,0x00,sizeof(mode));

	if(strstr(asciiNum,"+86"))
		asciiNum += strlen("+86");
	
	Slc_toupper(asciiContent);
	
	if(strstr(asciiContent,str))	//search KJX
	{
		if(memcmp(asciiContent+strlen(str)+1,kjxImei,SRV_MAX_IMSI_LEN-1) == 0)	//compare imei
		{
			if(strstr(asciiContent+strlen(str)+1+(SRV_MAX_IMSI_LEN-1),pro_name))	//search project number
			{
				pos = strstr(asciiContent+strlen(str)+1+(SRV_MAX_IMSI_LEN-1)+strlen(pro_name),",");
				if(pos)	//search mode type
				{
					pos += strlen(",");
					memcpy(mode,pos,1);
					g_kjx_nvram_struct.workMode = atoi(mode);
					if((atoi(mode) ==0) || (atoi(mode) ==1))
					kjx_nvram_write();
					//工作模式设置
					kjx_reset_gps_data_send_func();
					kjx_sms_send_mode_to_app(asciiNum,g_kjx_nvram_struct.workMode);
				}
				else
				{
					return;
				}
			}
			else
			{
				return;
			}
		}
		else
		{
			return;
		}
		
	}
	else
	return;
}

#endif // __KJX_SMS_ACTIVATE__

set_cmd kjx_sms_set_sms_send_cmd(cmdcode cmd)
{
	switch(cmd)
	{
		case SL_CMD_CODE_SOS:
		{
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_SOS");
		#endif
		#endif
			
			cmd = SET_SOS_SUC;
		}
		break;
		
		case SL_CMD_CODE_PSW:
		{
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_PSW");
		#endif
		#endif
			
			cmd = SET_PSW_SUC;
		}
		break;
		
		case SL_CMD_CODE_MONITOR:
		{
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_MONITOR");
		#endif
		#endif
			
			cmd = SET_MONITOR_SUC;
		}
		break;
		
		case SL_CMD_CODE_IMEI:
		{
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_IMEI");
		#endif
		#endif
			
			cmd = SET_IMEI_SUC;
		}
		break;
		
		case SL_CMD_CODE_FACTORY:
		{
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_FACTORY");
		#endif
		#endif
			
			cmd = SET_FACTORY;
		}		
		break;
		
		case SL_CMD_CODE_LANGUAGE:
		{
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_LANGUAGE");
		#endif
		#endif
			
			cmd = SET_LANGUAGE_SUC;
		}
		break;
		
		case SL_CMD_CODE_TIMEZONE:
		{
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_TIMEZONE");
		#endif
		#endif
		
		#ifdef __KJX_FUN_GPS__
			if(g_kjx_gps_data.data_status == 'A')
				cmd = SET_TZONE_SUC;
			else
				cmd = SET_TZONE_FAIL;
		#endif
		}
		break;
		
		case SL_CMD_CODE_SOS_STRING:
		{
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_SOS_STRING");
		#endif
		#endif
			
			cmd = SET_SOS_STRING_SUC;
		}
		break;
		
		case SL_CMD_CODE_MOVE:
		{
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_MOVE");
		#endif
		#endif
			
			cmd = SET_MOVE_SUC;
		}
		break;

		case SL_CMD_CODE_ADMIN:
		{
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_ADMIN");
		#endif
		#endif
			
			cmd = SET_FACTORY;
		}
		break;

		case SL_CMD_CODE_WRITE_IMEI:
		{
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_WRITE_IMEI");
		#endif
		#endif
			
			cmd = SET_WRITE_IMEI_SUC;
		}
		break;
		
		case SL_CMD_CODE_DOMAIN:
		{
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_DOMAIN");
		#endif
		#endif
			
			cmd = SET_DOMAIN;
		}
		break;
		
		case SL_CMD_CODE_APN:
		{
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_APN");
		#endif
		#endif
			
			cmd = SET_APN;
		}
		break;
 	}

#ifdef SMS_OLDMAN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("cmd:%d", cmd);
#endif
#endif
	
	return cmd;
	
}

cmdcode kjx_cmd_process_handle(U8 *asciiNum, U8 *asciiContent)
{
	int i = 0,j = 0;
	char *p = NULL;
	char *pw = NULL;
	char *pos = NULL;	
	char *pos_1 = NULL;	
	U8 isPw = 0;
	int cmdcode=SL_CMD_CODE_MAX;
	S32 Strlen=0;
	S32 nLen=strlen((char *)asciiContent);
	char *temp = NULL;

#ifdef __KJX_SMS_ACTIVATE__
	kjx_cmd_process_handle_workmode(asciiNum,asciiContent);
#endif

	p=(char *)asciiNum;

#ifdef SMS_OLDMAN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("asciiNum:%s, asciiContent[%d]:%s", asciiNum, nLen, asciiContent);
#endif
#endif

	Slc_toupper(asciiContent);

#ifdef SMS_OLDMAN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("toupper=%s", asciiContent);
#endif
#endif

	for(i=0; i<SL_CMD_CODE_MAX; i++)
	{
	#ifdef SMS_OLDMAN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("g_sl_cmd_tbl[%d].cmdString:%s", i, g_sl_cmd_tb[i].cmdString);
	#endif
	#endif

		pos=strstr(asciiContent, g_sl_cmd_tb[i].cmdString);

	#ifdef SMS_OLDMAN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("strstr_pos:%s", pos);
	#endif
	#endif

		if(!strncmp(g_sl_cmd_tb[i].cmdString, (char *)pos, strlen(g_sl_cmd_tb[i].cmdString)))
		{   
			cmdcode=g_sl_cmd_tb[i].cmdCode;
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("cmd0:%d", cmdcode);
		#endif
		#endif

			break;
		}
	}

	if(1)  //暂时屏蔽用于调试
	{
		memset(superNum, 0x00, sizeof(superNum));
		sprintf(superNum, "%s", p);
	}

#ifdef SMS_OLDMAN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("cmdCode:%d, asciiContent:%s", cmdcode, asciiContent);
#endif
#endif

	if((cmdcode == SL_CMD_CODE_SOS)||(cmdcode == SL_CMD_CODE_PSW)||(cmdcode == SL_CMD_CODE_ADMIN))
	{
		pw=strstr(asciiContent,g_kjx_nvram_struct.password);

	#ifdef SMS_OLDMAN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("asciiContent:%s, g_kjx_nvram_struct.password:%s, pw:%s", asciiContent, g_kjx_nvram_struct.password, pw);
	#endif
	#endif

		if(pw)
		{
			nLen = strlen(g_kjx_nvram_struct.password);
			isPw = strncmp(pw+nLen,",", strlen(","));

			if(isPw)
			{
			#ifdef SMS_OLDMAN_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("asciiContent:%s, g_kjx_nvram_struct.password:%s, pw:%s", asciiContent, g_kjx_nvram_struct.password, pw);
			#endif
			#endif
				return SL_CMD_CODE_MAX;
			}
		}
		else
		{
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("pass word is error 2");
		#endif
		#endif
			return SL_CMD_CODE_MAX;
		}
	}
	else
	{
		if((kjx_check_number_different(superNum,g_kjx_nvram_struct.sosNum[0]))
			&&(kjx_check_number_different(superNum,g_kjx_nvram_struct.sosNum[1]))
			&&(kjx_check_number_different(superNum,g_kjx_nvram_struct.sosNum[2]))
		)
		{
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("number_different");
		#endif
		#endif
			return SL_CMD_CODE_MAX;
		}
		else
		{
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("check pass");
		#endif
		#endif
		}
	}

	CurrCMD= kjx_sms_set_sms_send_cmd(cmdcode);

	/* 响应所有号码 */
	if(cmdcode<SL_CMD_CODE_MAX)
	{
		//CurrCMD = cmdcode;   /* 回复短信使用 */

		switch(cmdcode)
		{
		case SL_CMD_CODE_SOS:
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_SOS");
		#endif
		#endif
			pos=strstr(asciiContent, "KJX");
			if(!pos)
			{
				break;
			}

			pos=strstr(asciiContent, g_sl_cmd_tb[cmdcode].cmdString);
			if(pos)
			{
				pos += strlen(g_sl_cmd_tb[cmdcode].cmdString);
				for(i=0;i<3;i++)
				{
					pos_1 = strstr(pos,",");
					if(pos_1 && (ABS(pos_1-pos)<sizeof(g_kjx_nvram_struct.sosNum[i])))
					{
						memset(g_kjx_nvram_struct.sosNum[i], 0x00, sizeof(g_kjx_nvram_struct.sosNum[i]));
						memcpy(g_kjx_nvram_struct.sosNum[i], pos, ABS(pos_1-pos));  
						pos = pos_1+strlen(",");
					}
					else 
					{
						pos_1 = strstr(pos,"#");
						if(pos_1 && (ABS(pos_1-pos)<sizeof(g_kjx_nvram_struct.sosNum[i])))
						{
							memset(g_kjx_nvram_struct.sosNum[i], 0x00, sizeof(g_kjx_nvram_struct.sosNum[i]));
							memcpy(g_kjx_nvram_struct.sosNum[i], pos, ABS(pos_1-pos));  
			
							for(j=i+1;j<3;j++)
							{
								memset(g_kjx_nvram_struct.sosNum[j], 0x00, sizeof(g_kjx_nvram_struct.sosNum[j]));
							}

							//kjx_009a_nvram_write();
							kjx_sms_send_sms(superNum,set_cb_info[CurrCMD].cmdString, 0x08, NULL);

							break;
						}
					}
				}
			}
			break;

		case SL_CMD_CODE_PSW:
		{
			char ucs2_buf[128]={0};
			char ucs2_buf1[64]={0};

		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_PSW");
		#endif
		#endif

			pos=strstr(asciiContent, "KJX");
			if(!pos)
			{
				break;
			}

			pos=strstr(asciiContent, g_sl_cmd_tb[cmdcode].cmdString);
			if(pos)
			{
				pos += strlen(g_sl_cmd_tb[cmdcode].cmdString);
				pos_1 = strstr(pos,"#");

				if(pos_1 && (ABS(pos_1-pos)<sizeof(g_kjx_nvram_struct.password)))
				{
					memset(g_kjx_nvram_struct.password, 0x00, sizeof(g_kjx_nvram_struct.password));
					memcpy(g_kjx_nvram_struct.password, pos, ABS(pos_1-pos));
					//kjx_oldman_nvram_write();

					mmi_ucs2cpy((S8 *)ucs2_buf,(const CHAR *)set_cb_info[CurrCMD].cmdString);
					mmi_asc_to_ucs2(ucs2_buf1,(char*)g_kjx_nvram_struct.password);

					mmi_ucs2cat(ucs2_buf,(const S8*)ucs2_buf1);
					kjx_sms_send_sms(superNum,(U16 *)ucs2_buf, 0x08, NULL);
				}
			}
			break;
		}

		case SL_CMD_CODE_MONITOR:
		#if 0
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_MONITOR");
		#endif
		#endif

			pos=strstr(asciiContent, g_sl_cmd_tb[cmdcode].cmdString);
			if(pos)
			{
				pos += strlen(g_sl_cmd_tb[cmdcode].cmdString);
				pos_1 = strstr(pos,"#");

				if(pos_1 && (ABS(pos_1-pos)<sizeof(g_kjx_nvram_struct.listenNum))&&(ABS(pos_1-pos)>0))
				{
					memset(g_kjx_nvram_struct.listenNum, 0x00, sizeof(g_kjx_nvram_struct.listenNum));
					memcpy(g_kjx_nvram_struct.listenNum, pos, ABS(pos_1-pos));  

					g_kjx_nvram_struct.callMode = 1;									
					//kjx_009a_nvram_write();

					kal_sleep_task(1000);
					kjx_monitor_make_call();/*监听*/

					kjx_sms_send_sms(superNum,set_cb_info[CurrCMD].cmdString, 0x08, NULL);
				}
				else
				{
					g_kjx_nvram_struct.callMode = 0;		
					//kjx_009a_nvram_write();
					kjx_sms_send_sms(superNum,set_cb_info[CurrCMD].cmdString, 0x08, NULL);
				}
			}
		#endif
			break;

		case SL_CMD_CODE_LOCATION:
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_LOCATION");
		#endif
		#endif
		
			g_is_sms_send	=	1; 
			//kjx_009a_socket_send_location_data();
			kjx_sos_get_address();
			break;

		case SL_CMD_CODE_COORDINATE:
		{
		#ifdef __KJX_FUN_GPS__
			char num[50]={0};
			U16 res[50] = {0};

			kjx_lbs_info_struct *lbs_info = &g_kjx_lbs_info_struct;
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_COORDINATE");
		#endif
		#endif

			if(g_kjx_gps_data.data_status== 'A')//数据可用
			{
				sprintf(num,"GPS:%f%c,%f%c\0",
				g_kjx_gps_data.latitude,g_kjx_gps_data.latitude_dir,g_kjx_gps_data.longitude,g_kjx_gps_data.longitude_dir);
			}
			else if(g_kjx_gps_data.data_status== 'V')//数据不可用
			{
				sprintf(num,"LBS:%s,%s,%d,%d\0",
				lbs_info->mcc,lbs_info->mnc,lbs_info->lac,lbs_info->cid);
			}

			mmi_asc_to_ucs2((S8 *)res, (S8 *)num);
			kjx_sms_send_sms(superNum, (U16 *)res, 0x08, NULL);
		#endif
			break;
		}

		case SL_CMD_CODE_VER:
		{
			char ucs2_buf[128]={0};
			char ucs2_buf1[64]={0};

		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_VER");
		#endif
		#endif

			mmi_asc_to_ucs2(ucs2_buf1,(char*)release_verno());
			mmi_ucs2cpy((S8 *)ucs2_buf,ucs2_buf1);

			mmi_ucs2cat(ucs2_buf,(const S8*)(L"(build on:"));
			memset(ucs2_buf1, 0x00, sizeof(ucs2_buf1));
			mmi_asc_to_ucs2(ucs2_buf1,(char*)build_date_time());
			mmi_ucs2cat(ucs2_buf,ucs2_buf1);
			mmi_ucs2cat(ucs2_buf,(const S8*)(L")"));

			kjx_sms_send_sms(superNum, (U16 *)ucs2_buf, 0x08, NULL);

			break;
		}

		case SL_CMD_CODE_IMEI:
		{
			char ucs2_buf[64]={0};
			char ucs2_buf1[32]={0};

		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_IMEI kjxImei:%s", kjxImei);
		#endif
		#endif

			mmi_ucs2cpy((S8 *)ucs2_buf, (const S8 *)set_cb_info[CurrCMD].cmdString );
			mmi_asc_to_ucs2(ucs2_buf1,kjxImei);
			mmi_ucs2cat(ucs2_buf,ucs2_buf1);
			kjx_sms_send_sms(superNum, (U16 *)ucs2_buf, 0x08, NULL);

			break;
		}

		case SL_CMD_CODE_FACTORY:
		{
			extern void kjx_restore_factory();

		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_FACTORY");
		#endif
		#endif

			kjx_reset_nvram_info();
			//kjx_net_nvram_reset();
			/*恢复设置成功 */
			kjx_sms_send_sms(superNum, set_cb_info[CurrCMD].cmdString, 0x08, NULL);

			StartTimer(KJX_TIMER_ID_MISC, 10*1000, kjx_restore_factory);

			break;
		}

		case SL_CMD_CODE_LANGUAGE:
		{
			char language[8];

		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_LANGUAGE");
		#endif
		#endif
		
			pos=strstr(asciiContent, g_sl_cmd_tb[cmdcode].cmdString);
			if(pos)
			{
				pos += strlen(g_sl_cmd_tb[cmdcode].cmdString);
				pos_1 = strstr(pos,"#");

				if(pos_1 && (ABS(pos_1-pos)<sizeof(language)))
				{
					memset(language, 0x00, sizeof(language));
					memcpy(language, pos, ABS(pos_1-pos));  
					if(memcmp(language,"0086\0",strlen("0086\0"))==0)
					{
						g_kjx_nvram_struct.language = 0;
						//kjx_set_language();
						kjx_sms_send_sms(superNum,set_cb_info[CurrCMD].cmdString, 0x08, NULL);
					}
					else if(memcmp(language,"0044\0",strlen("0044\0"))==0)
					{
						g_kjx_nvram_struct.language = 1;
						//kjx_set_language();
						kjx_sms_send_sms(superNum,set_cb_info[CurrCMD].cmdString, 0x08, NULL);
					}
					//kjx_set_language_index((char*)g_kjx_nvram_struct.currLang);
					//kjx_009a_nvram_write();
				}
			}
			break;
		}

		case SL_CMD_CODE_URL:
		{
		#ifdef __KJX_FUN_GPS__
			double gpsLat = 0,gpsLng = 0;
			S8 ascBuf[256];
			S8 ucsBuf[512];

		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_URL");
		#endif
		#endif

			gpsLat = g_kjx_gps_data.latitude;
			gpsLng = g_kjx_gps_data.longitude;
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("gpsLng:%f, gpsLat:%f ", gpsLng, gpsLat);
		#endif
		#endif

			memset(ascBuf, 0x00, sizeof(ascBuf));
			memset(ucsBuf, 0x00, sizeof(ucsBuf));
			sprintf(ascBuf,"url:\r\nhttp://maps.google.com.hk/maps?hl=cn&q=+%f,+%f",gpsLat,gpsLng);
			mmi_asc_to_ucs2((CHAR *)ucsBuf, (CHAR *)ascBuf);						   
			kjx_sms_send_sms(superNum,(U16 *)ucsBuf, 0x08, NULL);
		#endif
			break;
		}

		case SL_CMD_CODE_TIMEZONE:
		{
		#ifdef __KJX_FUN_GPS__
			applib_time_struct cur_time;
			S8 tzone[6];
			S16 oldTimeZone=0,timeZone=0;
			S16 error;
			int time_min=0,hour_total=0;

		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_TIMEZONE");
		#endif
		#endif

			pos=strstr(asciiContent, g_sl_cmd_tb[cmdcode].cmdString);
			if(pos)
			{
				pos += strlen(g_sl_cmd_tb[cmdcode].cmdString);
				pos_1 = strstr(pos,"#");

				if(pos_1 && (ABS(pos_1-pos)<sizeof(tzone)))
				{
					memset(tzone, 0x00, sizeof(tzone));
					memcpy(tzone, pos, ABS(pos_1-pos));  
	
					kjxsettime = atof(tzone);
				#ifdef SMS_OLDMAN_DEBUG
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("atoi(tzone):%f", kjxsettime);
				#endif
				#endif

					if(g_kjx_gps_data.data_status == 'A')
					{
						PhnsetTzoneByIndex(kjxsettime);
						kjx_gps_time_sync(g_kjx_gps_data);
						kjx_sms_send_sms(superNum,set_cb_info[CurrCMD].cmdString, 0x08, NULL);
					}
					else
					{
						kjx_sms_send_sms(superNum,set_cb_info[CurrCMD].cmdString, 0x08, NULL);
					}
				}
			}
		#endif
			break;
		}

		case SL_CMD_CODE_SOS_STRING:
		#if 0
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_SOS_STRING");
		#endif
		#endif

			pos=strstr(asciiContent, g_sl_cmd_tb[cmdcode].cmdString);
			if(pos)
			{
				pos += strlen(g_sl_cmd_tb[cmdcode].cmdString);
				pos_1 = strstr(pos,"#");

				if(pos_1 && (ABS(pos_1-pos)<sizeof(g_kjx_nvram_struct.sosString)))
				{
					memset(g_kjx_nvram_struct.sosString, 0x00, sizeof(g_kjx_nvram_struct.sosString));
					memcpy(g_kjx_nvram_struct.sosString, pos, ABS(pos_1-pos));
					kjx_sms_send_sms(superNum, set_cb_info[CurrCMD].cmdString, 0x08, NULL);
				}
			}
		#endif
			break;

		case SL_CMD_CODE_RESTART:
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_RESTART");
		#endif
		#endif

			kal_sleep_task(1000);
			kjx_restart();
			break;
	
		case SL_CMD_CODE_MOVE:
		{
		#if 0
			S8 modeBuf[6];
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_MOVE");
		#endif
		#endif
			pos=strstr(asciiContent, g_sl_cmd_tb[cmdcode].cmdString);
			if(pos)
			{
				pos += strlen(g_sl_cmd_tb[cmdcode].cmdString);
				pos_1 = strstr(pos,",");

				if(pos_1 && (ABS(pos_1-pos)<sizeof(modeBuf)))
				{
					memset(modeBuf, 0x00, sizeof(modeBuf));
					memcpy(modeBuf, pos, ABS(pos_1-pos));
					g_kjx_nvram_struct.moveStatus = atoi(modeBuf);

					pos = pos_1+strlen(",");
					pos_1 = strstr(pos,"#");
					memset(modeBuf, 0x00, sizeof(modeBuf));
					memcpy(modeBuf, pos, ABS(pos_1-pos));
					g_kjx_nvram_struct.moveValue = atoi(modeBuf);
				#ifdef SMS_OLDMAN_DEBUG
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("SL_CMD_CODE_MOVE moveValue:%d",  g_kjx_nvram_struct.moveValue);
				#endif
				#endif

					//kjx_009a_nvram_write();
					kjx_sms_send_sms(superNum, set_cb_info[CurrCMD].cmdString, 0x08, NULL);
				}
			}
		#endif
			break;
		}

		case SL_CMD_CODE_ADMIN:
		{
		#if 0
			S8 imeibuf[20];
			extern U8 kjxImei[SRV_MAX_IMSI_LEN];

		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_ADMIN");
		#endif
		#endif

			pos=strstr(asciiContent, "SL");
			if(!pos)
				break;

			pos += strlen("SL");
			pos_1 = strstr(asciiContent,",");
			if(pos_1 && (ABS(pos_1-pos)<sizeof(g_kjx_oldman_struct.deviceNumber)))
			{
				memset(g_kjx_oldman_struct.deviceNumber, 0x00, sizeof(g_kjx_oldman_struct.deviceNumber));
				memcpy(g_kjx_oldman_struct.deviceNumber, pos, ABS(pos_1-pos));	
			}

			if(atoi(g_kjx_oldman_struct.deviceNumber)!=3509006)
				return SL_CMD_CODE_MAX;

			kjx_reset_nvram_info();
			//kjx_net_nvram_reset();
			/*恢复设置成功 */
			kjx_sms_send_sms(g_kjx_oldman_struct.superNum, set_cb_info[CurrCMD].cmdString, 0x08, NULL);

			StartTimer(KJX_TIMER_ID_MISC, 10*1000, kjx_restart);
		#endif
			break;
		}

		case SL_CMD_CODE_WRITE_IMEI:
		{
			S8 imeiBuf[20];
			S16 result = -1;
			int i=0,j=0;
			char parseBuf[100];
			char tem[2+1];
			char writeImei[20];

		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("SL_CMD_CODE_WRITE_IMEI");
		#endif
		#endif

			pos=strstr(asciiContent, g_sl_cmd_tb[cmdcode].cmdString);
			if(pos)
			{
				pos += strlen(g_sl_cmd_tb[cmdcode].cmdString);
				pos_1 = strstr(pos,"#");

				if(pos_1 && (ABS(pos_1-pos)<sizeof(imeiBuf)))
				{
					memset(imeiBuf, 0x00, sizeof(imeiBuf));
					memcpy(imeiBuf, pos, ABS(pos_1-pos));

					memset(writeImei,0x00,sizeof(writeImei));
					//memcpy(g_kjx_nvram_struct.writeImei,imeiBuf,ABS(pos_1-pos));

					for(i=0,j=0;i<strlen(imeiBuf);j++)
					{
						memset(tem, 0x00, sizeof(tem));
						memset(parseBuf, 0x00, sizeof(parseBuf));
						memcpy(parseBuf,imeiBuf+(i+1),1);
						strcat(tem,(const char*)parseBuf);

						memset(parseBuf, 0x00, sizeof(parseBuf));
						memcpy(parseBuf,imeiBuf+i,1);
						strcat(tem,(const char*)parseBuf);
						strcat(tem,"\0");

						writeImei[j] = atox(tem);
						i+=2;
					}

					result = kjx_write_imei_send(writeImei,sizeof(writeImei));
					if(result == 0 )
					{
						kjx_sms_send_sms(superNum, set_cb_info[CurrCMD].cmdString, 0x08, NULL);
						//kjx_009a_nvram_write();
						StartTimer(KJX_TIMER_ID_MISC, 5*1000, kjx_restart);
					}
					else
					{
						unsigned short sendBuf[]={0x0049,0x004D,0x0045,0x0049,0x5199,0x5165,0x5931,0x8D25,0xFF01,0x0000};//IMEI写入失败!

						kjx_sms_send_sms(superNum, sendBuf, 0x08, NULL);
						//kjx_009a_nvram_write();
					}
				}
			}
			break;
		}

		case SL_CMD_CODE_DOMAIN:
		{
			char portBuf[6];

			pos=strstr(asciiContent, g_sl_cmd_tb[cmdcode].cmdString);
			if(pos)
			{
				pos += strlen(g_sl_cmd_tb[cmdcode].cmdString);
				pos_1 = strstr(pos,",");
				if(pos_1)
				{
					memset(g_kjx_nvram_struct.domain.domain,0x00,sizeof(g_kjx_nvram_struct.domain.domain));
					memcpy(g_kjx_nvram_struct.domain.domain,pos, ABS(pos_1-pos));

					pos = pos_1 + strlen(",");
					pos_1 = strstr(pos,"#");

					memset(portBuf, 0x00, sizeof(portBuf));
					memcpy(portBuf, pos, ABS(pos_1-pos));

					g_kjx_nvram_struct.domain.port = atoi(portBuf);
				#ifdef SMS_OLDMAN_DEBUG
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("domain:%s, port:%d", g_kjx_nvram_struct.domain.domain, g_kjx_nvram_struct.domain.port);
				#endif
				#endif
					kjx_sms_send_sms(superNum, set_cb_info[CurrCMD].cmdString, 0x08, NULL);

					StartTimer(KJX_TIMER_ID_MISC, 5*1000, kjx_restart);
				}
			}
			break;
		}

		case SL_CMD_CODE_APN:
			pos=strstr(asciiContent, g_sl_cmd_tb[cmdcode].cmdString);
			if(pos)
			{
				pos += strlen(g_sl_cmd_tb[cmdcode].cmdString);
				pos_1 = strstr(pos,",");
				if(pos_1)
				{
					memset(g_kjx_nvram_struct.apn.apnMode,0x00,sizeof(g_kjx_nvram_struct.apn.apnMode));
					memcpy(g_kjx_nvram_struct.apn.apnMode,pos, ABS(pos_1-pos));
					pos = pos_1 + strlen(",");
					pos +=(strlen(g_kjx_nvram_struct.apn.apnMode)+strlen(","));
					pos_1 = strstr(pos,",");
					if(pos_1)
					{
						memset(g_kjx_nvram_struct.apn.userName, 0x00, sizeof(g_kjx_nvram_struct.apn.userName));
						memcpy(g_kjx_nvram_struct.apn.userName,pos, ABS(pos_1-pos));
					}
	
					pos +=(strlen(g_kjx_nvram_struct.apn.userName)+strlen(","));
					pos_1 = strstr(pos,"#");
					if(pos_1)
					{
						memset(g_kjx_nvram_struct.apn.passWord, 0x00, sizeof(g_kjx_nvram_struct.apn.passWord));
						memcpy(g_kjx_nvram_struct.apn.passWord,pos, ABS(pos_1-pos));
					}

					kjx_set_apn_infos();
					StartTimer(KJX_TIMER_ID_MISC, 5*1000, kjx_restart);
				}
			}
			break;

		default:
			//无效指令	
		#ifdef SMS_OLDMAN_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("command not match!");
		#endif
		#endif
			break;
		}
		
		kjx_nvram_write();
	}
	else
	{
		//无效指令	
	#ifdef SMS_OLDMAN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("cmdcode>SL_CMD_CODE_MAX!");
	#endif
	#endif
	}

	return cmdcode;
}
#endif

U8 kjx_sys_get_listen_status(void)
{
	if(g_kjx_nvram_struct.callMode)
	{
		return g_kjx_nvram_struct.callMode;
	}
}

void kjx_set_outcall_monitor_state(U8 state)
{
	monitor_out_state = state;
#ifdef SMS_OLDMAN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("monitor_out_state:%d", monitor_out_state);
#endif
#endif
}

U8 kjx_is_outcall_with_monitor(void)
{
#ifdef SMS_OLDMAN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("monitor_out_state:%d", monitor_out_state);
#endif
#endif
	return monitor_out_state;
}

void kjx_oldman_in_area_alarm_callback(void)
{
	static U16 sms_send = 0;
	//安全提醒：您的家人已进入指定区域范围！
	char smsString[]={0x89,0x5b,0x68,0x51,0xd0,0x63,0x92,0x91,0x1a,0xff,0xa8,0x60,0x84,0x76,0xb6,0x5b,0xba,0x4e,0xf2,0x5d,0xdb,0x8f,0x65,0x51,0x7,0x63,0x9a,0x5b,0x3a,0x53,0xdf,0x57,0x3,0x83,0xf4,0x56,0x1,0xff,0x0,0x0};

	sms_send = sms_send_count;
	sms_send++;
	if(sms_send < 3)
	{
		if(strlen(g_kjx_nvram_struct.sosNum[sms_send])>0)
		{
			sms_send_count = sms_send;
			kjx_sms_send_sms(g_kjx_nvram_struct.sosNum[sms_send_count],(unsigned short *)smsString, 0x08, kjx_oldman_in_area_alarm_callback);
		}
		else if(strlen(g_kjx_nvram_struct.sosNum[sms_send+1])>0)
		{
			sms_send_count = (sms_send+1);
			kjx_sms_send_sms(g_kjx_nvram_struct.sosNum[sms_send_count],(unsigned short *)smsString, 0x08, kjx_oldman_in_area_alarm_callback);
		}

	}
	else if(sms_send >= 3)
	{
		sms_send = 0;
	}
}

void kjx_oldman_out_area_alarm_callback(void)
{
	static U16 sms_send = 0;
	//安全提醒：您的家人已离开指定区域范围！
	char smsString[]={0x89,0x5b,0x68,0x51,0xd0,0x63,0x92,0x91,0x1a,0xff,0xa8,0x60,0x84,0x76,0xb6,0x5b,0xba,0x4e,0xf2,0x5d,0xbb,0x79,0x0,0x5f,0x7,0x63,0x9a,0x5b,0x3a,0x53,0xdf,0x57,0x3,0x83,0xf4,0x56,0x1,0xff,0x0,0x0};

	sms_send = sms_send_count;
	sms_send++;
	if(sms_send < 3)
	{
		if(strlen(g_kjx_nvram_struct.sosNum[sms_send])>0)
		{
			sms_send_count = sms_send;
			kjx_sms_send_sms(g_kjx_nvram_struct.sosNum[sms_send_count],(unsigned short *)smsString, 0x08, kjx_oldman_out_area_alarm_callback);
		}
		else if(strlen(g_kjx_nvram_struct.sosNum[sms_send+1])>0)
		{
			sms_send_count = (sms_send+1);
			kjx_sms_send_sms(g_kjx_nvram_struct.sosNum[sms_send_count],(unsigned short *)smsString, 0x08, kjx_oldman_out_area_alarm_callback);
		}

	}
	else if(sms_send >= 3)
	{
		sms_send = 0;
	}
}

void kjx_oldman_send_sms_in_area_alarm(void)
{
	U16 i = 0;
	//安全提醒：您的家人已进入指定区域范围！
	char smsString[]={0x89,0x5b,0x68,0x51,0xd0,0x63,0x92,0x91,0x1a,0xff,0xa8,0x60,0x84,0x76,0xb6,0x5b,0xba,0x4e,0xf2,0x5d,0xdb,0x8f,0x65,0x51,0x7,0x63,0x9a,0x5b,0x3a,0x53,0xdf,0x57,0x3,0x83,0xf4,0x56,0x1,0xff,0x0,0x0};
	
	for(i=0;i<3;i++)
	{
		if(strlen(g_kjx_nvram_struct.sosNum[i])>0)
		{
			sms_send_count = i;
			kjx_sms_send_sms(g_kjx_nvram_struct.sosNum[i],(unsigned short *)smsString, 0x08, kjx_oldman_in_area_alarm_callback);
			break;
		}
	}
}

void kjx_oldman_send_sms_out_area_alarm(void)
{
	U16 i = 0;
	//安全提醒：您的家人已离开指定区域范围！
	char smsString[]={0x89,0x5b,0x68,0x51,0xd0,0x63,0x92,0x91,0x1a,0xff,0xa8,0x60,0x84,0x76,0xb6,0x5b,0xba,0x4e,0xf2,0x5d,0xbb,0x79,0x0,0x5f,0x7,0x63,0x9a,0x5b,0x3a,0x53,0xdf,0x57,0x3,0x83,0xf4,0x56,0x1,0xff,0x0,0x0};
	
	for(i=0;i<3;i++)
	{
		if(strlen(g_kjx_nvram_struct.sosNum[i])>0)
		{
			sms_send_count = i;
			kjx_sms_send_sms(g_kjx_nvram_struct.sosNum[i],(unsigned short *)smsString, 0x08, kjx_oldman_out_area_alarm_callback);
			break;
		}
	}
}


void kjx_oldman_send_call_area_alarm(void)
{//电话推送报警
	
}

U16 kjx_sos_outcalling_sign = 0;
void kjx_oldman_key_sos1(void)
{
#ifdef __KJX_FACTORY_TEST__
	MakeCall(L"10086");
	U_PutUARTBytes(0,"kjx_oldman_key_sos1\r\n", strlen("kjx_oldman_key_sos2\r\n"));
#else

	char ucs2Num[64]={0};

#if defined(__KJX_FUN_STEPS__)
	if(steps_is_use)
	{
		ClearKeyHandler(KEY_VOL_UP, KEY_LONG_PRESS);
		return;
	}
#endif
#ifdef SMS_OLDMAN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	if((kjx_is_in_call()))
	{
	#ifdef SMS_OLDMAN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return:is in call!");
	#endif
	#endif
		return;
	}

	if(!strlen((char*)g_kjx_nvram_struct.sosNum[0]))
	{
		kjx_call_index = 4;
	#ifdef SMS_OLDMAN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return:no number!");
	#endif
	#endif
		DisplayPopup((PU8) GetString(STR_KJX_OUTCALL_NONUMBER),IMG_GLOBAL_EMPTY,1,1500,WARNING_TONE);
		return;
	}
	
	memset(ucs2Num, 0x00, sizeof(ucs2Num));
	mmi_asc_to_ucs2(ucs2Num,g_kjx_nvram_struct.sosNum[0]);

	kjx_sos_outcalling_sign = 1;
	MakeCall(ucs2Num);
#endif	
}

void kjx_oldman_key_sos2(void)
{
#ifdef __KJX_FACTORY_TEST__
	MakeCall(L"13480106089");
	U_PutUARTBytes(0,"kjx_oldman_key_sos2\r\n", strlen("kjx_oldman_key_sos2\r\n"));
#else

	char ucs2Num[64]={0};

#if defined(__KJX_FUN_STEPS__)
	if(steps_is_use)
	{
		ClearKeyHandler(KEY_VOL_DOWN, KEY_LONG_PRESS);
		return;
	}
#endif
#ifdef SMS_OLDMAN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	if((kjx_is_in_call()))
	{
	#ifdef SMS_OLDMAN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return:is in call!");
	#endif
	#endif
		return;
	}

	if(!strlen((char*)g_kjx_nvram_struct.sosNum[1]))
	{
		kjx_call_index = 4;
	#ifdef SMS_OLDMAN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return:no number!");
	#endif
	#endif
		DisplayPopup((PU8) GetString(STR_KJX_OUTCALL_NONUMBER),IMG_GLOBAL_EMPTY,1,1500,WARNING_TONE);
		return;
	}

	memset(ucs2Num, 0x00, sizeof(ucs2Num));
	mmi_asc_to_ucs2(ucs2Num,g_kjx_nvram_struct.sosNum[1]);

	kjx_sos_outcalling_sign = 2;
	MakeCall(ucs2Num);
#endif
}


void kjx_oldman_key_sos3(void)
{
#ifdef __KJX_FACTORY_TEST__
	EntryFMMenu();
	mmi_fm_select_echo_loop();
	srv_speech_enable_hand_free();
#else
	char ucs2Num[64]={0};
	char sosNum[32];
	static U8 sosIndex = 0;
	extern BOOL kjx_is_listen;
	extern U8 kjx_listen_callmode;
	extern BOOL kjx_sos_in_call;
	extern BOOL kjx_sos_screen;
	
#if defined(__KJX_FUN_STEPS__)
	if(steps_is_use)
	{
		ClearKeyHandler(KEY_RIGHT_ARROW, KEY_LONG_PRESS);
		return;
	}
#endif
#ifdef SMS_OLDMAN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
	StopTimer(KJX_TIMER_ID_KEY_SOS);
	
	if((kjx_is_in_call()))
	{
		StartTimer(KJX_TIMER_ID_KEY_SOS,1000*3,kjx_oldman_key_sos3);
	#ifdef SMS_OLDMAN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return:is in call!");
	#endif
	#endif
		return;
	}
#ifdef SMS_OLDMAN_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("sosIndex:%d", sosIndex);
#endif
#endif
	if(sosIndex>=3)
	{
		sosIndex = 0;
		kjx_sos_screen = FALSE;
		kjx_sos_in_call = FALSE;
		kjx_reset_callmode();
		return;
	}

	memset(sosNum, 0x00, sizeof(sosNum));

	switch(sosIndex)
	{
		case 0:
			if(strlen((char*)g_kjx_nvram_struct.sosNum[0])>0)
			{
				sosIndex=1;
				memcpy(sosNum,g_kjx_nvram_struct.sosNum[0], strlen(g_kjx_nvram_struct.sosNum[0]));
			}
			else if(strlen((char*)g_kjx_nvram_struct.sosNum[1])>0)
			{
				sosIndex=2;
				memcpy(sosNum,g_kjx_nvram_struct.sosNum[1], strlen(g_kjx_nvram_struct.sosNum[1]));
			}
			else if(strlen((char*)g_kjx_nvram_struct.sosNum[2])>0)
			{
				sosIndex=3;
				memcpy(sosNum,g_kjx_nvram_struct.sosNum[2], strlen(g_kjx_nvram_struct.sosNum[2]));
			}
			else
			{
				sosIndex=4;
			}
			break;

		case 1:
			if(strlen((char*)g_kjx_nvram_struct.sosNum[1])>0)
			{
				sosIndex=2;
				memcpy(sosNum,g_kjx_nvram_struct.sosNum[1], strlen(g_kjx_nvram_struct.sosNum[1]));
			}
			else if(strlen((char*)g_kjx_nvram_struct.sosNum[2])>0)
			{
				sosIndex=3;
				memcpy(sosNum,g_kjx_nvram_struct.sosNum[2], strlen(g_kjx_nvram_struct.sosNum[2]));
			}
			else
			{
				sosIndex=4;
			}
			break;

		case 2:
			if(strlen((char*)g_kjx_nvram_struct.sosNum[2])>0)
			{
				sosIndex=3;
				memcpy(sosNum,g_kjx_nvram_struct.sosNum[2], strlen(g_kjx_nvram_struct.sosNum[2]));
			}
			else
			{
				sosIndex=4;
			}
			break;

		default:
			break;

			
	}

	if(!strlen((char*)sosNum))
	{
		if(kjx_check_sos_number_is_empty())
		kjx_call_index = 4;
	#ifdef SMS_OLDMAN_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return:no number!");
	#endif
	#endif
		sosIndex = 0;
		//kjx_sos_screen = FALSE;
		//kjx_sos_in_call = FALSE;
		kjx_reset_callmode();
		return;
	}

	if((kjx_sos_in_call==TRUE)&&(kjx_sos_screen==FALSE))
	{
		sosIndex = 0;
		kjx_sos_screen = FALSE;
		kjx_sos_in_call = FALSE;
		kjx_reset_callmode();
		return;
	}
	
	if(!kjx_sos_screen && !kjx_sos_in_call)
	{
		g_kjx_nvram_struct.workMode = 0;
		kjx_oldman_open_gps_timer();
		if(mmi_get_gps_status())
			kjx_sos_send_gps_data();
		else
			StartTimer(KJX_TIMER_ID_SOS_CALL,1000*60,kjx_sos_send_gps_data);
	}
		
	kjx_is_listen = TRUE;
	kjx_listen_callmode = g_kjx_nvram_struct.callMode;
	g_kjx_nvram_struct.callMode = 1;//监听

	kjx_sos_screen = TRUE;
	memset(ucs2Num, 0x00, sizeof(ucs2Num));
	mmi_asc_to_ucs2(ucs2Num,sosNum);

	MakeCall(ucs2Num);
	
	if((kjx_sos_screen==TRUE)&&(kjx_sos_in_call==FALSE))
	{
		StartTimer(KJX_TIMER_ID_KEY_SOS,1000*5,kjx_oldman_key_sos3);
	}
#endif	
}

#endif
#endif

