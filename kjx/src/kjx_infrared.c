/**********************************************************************************
*Filename:     kjx_infrared.c
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2014/04/29
*
***********************************************************************************/
#if defined(__KJX_FUN__)
#if defined(__KJX_INFRARED__)
#include "kjx_include.h"
#include "ProfilesSrv.h"

#define INFRARED_STATUS_VALID 1
U16 g_infrared_menu_id = INFRARED_MENU_MAX;
U16 kjx_dog_flag = 1;
BOOL disable_hand_free = FALSE;
static kal_mutexid g_infrared_process_mutex = NULL;
#ifdef __KJX_OBD__
extern kjx_obd_data g_kjx_obd_data[];
#endif
extern srv_prof_cntx_struct g_srv_prof;
extern kjx_main_func g_kjx_main_func;
extern kjx_a62_struct g_kjx_a62_struct;

char menu_string[INFRARED_MENU_MAX][32]=
{
	//OBD信息播报
	{0x4f,0x0,0x42,0x0,0x44,0x0,0xe1,0x4f,0x6f,0x60,0xad,0x64,0xa5,0x62,0x0,0x0},
	
	//电子狗功能
	{0x35,0x75,0x50,0x5b,0xd7,0x72,0x9f,0x52,0xfd,0x80,0x0,0x0},
	
	//音量设置
	//{0xf3,0x97,0xcf,0x91,0xbe,0x8b,0x6e,0x7f,0x0,0x0},
	
	//振动报警
	{0x2f,0x63,0xa8,0x52,0xa5,0x62,0x66,0x8b,0x0,0x0},
	
	//电子围栏
	{0x35,0x75,0x50,0x5b,0xf4,0x56,0xf,0x68,0x0,0x0},
	
	//限速提醒
	{0x50,0x96,0x1f,0x90,0xd0,0x63,0x92,0x91,0x0,0x0},
};

void kjx_trace_infrared(const char *fmt, ...)
{
#if defined(KJX_LOG_TRACE_INFRARED)
	va_list lstArg;
	kal_uint16 nLen=0;
	applib_time_struct currTime;
	char *p=get_ctrl_buffer(KJX_LOG_BUFF_SIZE);
	if(!p)
	{
		return;
	}
	memset(p, 0x00, KJX_LOG_BUFF_SIZE);
	memset(&currTime, 0x00, sizeof(currTime));
	applib_dt_get_rtc_time(&currTime);
	sprintf(p, "[%04d/%02d/%02d, %02d:%02d.%02d]", currTime.nYear,currTime.nMonth, currTime.nDay, currTime.nHour, currTime.nMin, currTime.nSec);
	nLen=strlen(p);

	va_start(lstArg, fmt);
	nLen = vsnprintf(p+nLen, KJX_LOG_BUFF_SIZE-2-nLen, fmt, lstArg);
	va_end(lstArg);
	strcat(p, "\r\n");
	nLen=strlen(p);
	
#if defined(WIN32)
	kal_printf("TraceEx: %s\n", p);
#else
	U_PutUARTBytes(uart_port1, (kal_uint8 *)p, nLen);
#endif
	free_ctrl_buffer(p);
#endif/*KJX_LOG_TRACE*/
}


void kjx_infrared_play_menu(void)
{
#if defined(__NPR_TTS__)
	if(mmi_ucs2strlen((const CHAR *)menu_string[g_infrared_menu_id])>0)
	{
		Npr_Tts_play_stop();
		Npr_Ttsplayer_playtextw(menu_string[g_infrared_menu_id],NULL);  
	}
#endif
}

/********************************************************************************/

/*OBD信息播报*/
void kjx_infrared_left_menu_obd(void)
{
#ifdef __KJX_OBD__
	int i = 0;
	U8 ucs_str[128];
	U8 asc_str[32];
	U8 playTtsString[1024];
	char noObd[]={0xa1,0x6c,0x9,0x67,0x4f,0x0,0x42,0x0,0x44,0x0,0x70,0x65,0x6e,0x63,0x1,0xff,0x0,0x0};/*没有OBD数据！*/
	U16 statusMessage = 0;

	memset(playTtsString, 0x00, sizeof(playTtsString));
	
	for(i=0;i<MAX_OBD_DATA_ID;i++)
	{
		if(g_kjx_obd_data[i].status == TRUE)
		{
			statusMessage = 1;
			if(((i>=0)&&(i<=39))||(i==64)||(i==66))
			{
				mmi_ucs2cat((CHAR *)playTtsString,g_kjx_obd_data[i].name_string);
				mmi_ucs2cat((CHAR *)playTtsString,(const CHAR *)L":");
				mmi_ucs2cat((CHAR *)playTtsString,g_kjx_obd_data[i].unit);
				mmi_ucs2cat((CHAR *)playTtsString,(const CHAR *)L";");
			}
			else if(((i>=40)&&(i<=63))||(i==65))
			{
				memset(ucs_str, 0x00, sizeof(ucs_str));
				memset(asc_str, 0x00, sizeof(asc_str));
				
				sprintf(asc_str,":%.0f",g_kjx_obd_data[i].value);
				mmi_asc_to_ucs2((S8*)ucs_str,(S8*)asc_str);
				
				mmi_ucs2cat((CHAR *)playTtsString,g_kjx_obd_data[i].name_string);
				mmi_ucs2cat((CHAR *)playTtsString,(const CHAR *)L":");
				mmi_ucs2cat((CHAR *)playTtsString,ucs_str);
				mmi_ucs2cat((CHAR *)playTtsString,g_kjx_obd_data[i].unit);
				mmi_ucs2cat((CHAR *)playTtsString,(const CHAR *)L";");
			}
		}
	}

	if(!statusMessage)
	{
		mmi_ucs2cat((CHAR *)playTtsString,noObd);
	}

#if defined(__NPR_TTS__)
	if(mmi_ucs2strlen((const CHAR *)playTtsString)>0)
	{
		Npr_Tts_play_stop();
		Npr_Ttsplayer_playtextw(playTtsString,NULL);  
	}
#endif

#endif//__KJX_OBD__
}

void kjx_infrared_right_menu_obd(void)
{
	kjx_infrared_left_menu_obd();
}

/*电子狗*/
void kjx_infrared_left_menu_dog(void)
{
	char palyStr[]={0x73,0x51,0xed,0x95,0x35,0x75,0x50,0x5b,0xd7,0x72,0x9f,0x52,0xfd,0x80,0x0,0x0};/*关闭电子狗功能*/

	kjx_dog_flag = 0;
#if defined(__NPR_TTS__)
	if(mmi_ucs2strlen((const CHAR *)palyStr)>0)
	{
		Npr_Tts_play_stop();
		Npr_Ttsplayer_playtextw(palyStr,NULL);  
	}
#endif
	
}

void kjx_infrared_right_menu_dog(void)
{
	char palyStr[]={0x0,0x5f,0x2f,0x54,0x35,0x75,0x50,0x5b,0xd7,0x72,0x9f,0x52,0xfd,0x80,0x0,0x0};/*开启电子狗功能*/
	
	kjx_dog_flag = 1;
#if defined(__NPR_TTS__)
	if(mmi_ucs2strlen((const CHAR *)palyStr)>0)
	{
		Npr_Tts_play_stop();
		Npr_Ttsplayer_playtextw(palyStr,NULL);  
	}
#endif
}

/*音量设置*/
void kjx_infrared_disable_hand_free(void)
{
	
	char disableStr[]={0x59,0x97,0xf3,0x97,0x21,0x6a,0xf,0x5f,0x0,0x0};/*静音模式*/

	StopTimer(KJX_TIMER_ID_INFRARED);

	if(!Npr_Tts_is_playing())
	{
		kjx_trace_infrared("%s(%d)",__func__,__LINE__); 
		
		srv_speech_disable_hand_free();
		
		#if defined(__NPR_TTS__)
			if((mmi_ucs2strlen((const CHAR *)disableStr)>0))
			{
				Npr_Tts_play_stop();
				Npr_Ttsplayer_playtextw(disableStr,NULL);  
			}
		#endif

		disable_hand_free = TRUE;
		g_kjx_a62_struct.silentStatus = 1;
		kjx_a62_nvram_write();
		return;
	}
	kjx_trace("%s(line:%d) StartTimer" ,__func__,__LINE__);
	StartTimer(KJX_TIMER_ID_INFRARED,500,kjx_infrared_disable_hand_free);
}

void kjx_infrared_enable_hand_free(void)
{
	char disableStr[]={0x69,0x62,0xf3,0x97,0x21,0x6a,0xf,0x5f,0x0,0x0};/*扩音模式*/

	StopTimer(KJX_TIMER_ID_INFRARED);

	if(!Npr_Tts_is_playing())
	{
		kjx_trace_infrared("%s(%d)",__func__,__LINE__); 
		
		srv_speech_enable_hand_free();

		disable_hand_free = FALSE;
		g_kjx_a62_struct.silentStatus = 0;
		kjx_a62_nvram_write();
		#if defined(__NPR_TTS__)
			if((mmi_ucs2strlen((const CHAR *)disableStr)>0))
			{
				Npr_Tts_play_stop();
				Npr_Ttsplayer_playtextw(disableStr,NULL);  
			}
		#endif
		return;
	}

	StartTimer(KJX_TIMER_ID_INFRARED,500,kjx_infrared_enable_hand_free);
}

void kjx_infrared_left_menu_volume(void)
{
	srv_prof_setting_struct settings;
	char volumeStr[]={0xf3,0x97,0xcf,0x91,0xcf,0x51,0x0,0x0};/*音量减*/

	srv_prof_get_profile_values((srv_prof_internal_profile_enum)g_srv_prof.cur_prof, &settings);

	kjx_trace_infrared("%s(%d) settings.ring_vol=%d",__func__,__LINE__,settings.ring_vol); 

	if(settings.ring_vol>0)
	{
		settings.ring_vol--;
	}
	else
	{
		settings.ring_vol = 0;
	}

	kjx_trace_infrared("%s(%d) settings.ring_vol=%d",__func__,__LINE__,settings.ring_vol);

	if(settings.ring_vol == 0)
	{
		kjx_infrared_disable_hand_free();
	}
	
	kjx_trace_infrared("%s(%d) settings.ring_vol=%d,cur_prof=%d",__func__,__LINE__,settings.ring_vol,(srv_prof_internal_profile_enum)g_srv_prof.cur_prof); 
	
	mdi_audio_set_volume(MDI_VOLUME_MEDIA,settings.ring_vol);
	srv_prof_set_profile_values((srv_prof_internal_profile_enum)g_srv_prof.cur_prof, &settings);

#if defined(__NPR_TTS__)
	if((mmi_ucs2strlen((const CHAR *)volumeStr)>0)&&(settings.ring_vol != 0))
	{
		Npr_Tts_play_stop();
		Npr_Ttsplayer_playtextw(volumeStr,NULL);  
	}
#endif

}

void kjx_infrared_right_menu_volume(void)
{
	srv_prof_setting_struct settings;
	char volumeStr[]={0xf3,0x97,0xcf,0x91,0xa0,0x52,0x0,0x0};/*音量加*/

	srv_prof_get_profile_values((srv_prof_internal_profile_enum)g_srv_prof.cur_prof, &settings);

	kjx_trace_infrared("%s(%d) settings.ring_vol=%d",__func__,__LINE__,settings.ring_vol); 

	if(settings.ring_vol<6)
	{
		settings.ring_vol++;
	}
	else
	{
		settings.ring_vol = 6;
	}

	
	if(settings.ring_vol == 1)
	{
		kjx_infrared_enable_hand_free();
	}
	
	
	kjx_trace_infrared("%s(%d) settings.ring_vol=%d",__func__,__LINE__,settings.ring_vol); 

	mdi_audio_set_volume(MDI_VOLUME_MEDIA,settings.ring_vol);
	srv_prof_set_profile_values((srv_prof_internal_profile_enum)g_srv_prof.cur_prof, &settings);

#if defined(__NPR_TTS__)
	if((mmi_ucs2strlen((const CHAR *)volumeStr)>0)&&(settings.ring_vol != 1))
	{
		Npr_Tts_play_stop();
		Npr_Ttsplayer_playtextw(volumeStr,NULL);  
	}
#endif

}

/*振动报警*/
void kjx_infrared_left_menu_vibr(void)
{
	char palyStr[]={0x73,0x51,0xed,0x95,0x2f,0x63,0xa8,0x52,0xa5,0x62,0x66,0x8b,0x0,0x0};/*关闭振动报警*/

	g_kjx_main_func.kjx_set_alarm_status(0);
#if defined(__NPR_TTS__)
	if(mmi_ucs2strlen((const CHAR *)palyStr)>0)
	{
		Npr_Tts_play_stop();
		Npr_Ttsplayer_playtextw(palyStr,NULL);  
	}
#endif
}

void kjx_infrared_right_menu_vibr(void)
{
	char palyStr[]={0x0,0x5f,0x2f,0x54,0x2f,0x63,0xa8,0x52,0xa5,0x62,0x66,0x8b,0x0,0x0};/*开启振动报警*/
	
	g_kjx_main_func.kjx_set_alarm_status(1);
#if defined(__NPR_TTS__)
	if(mmi_ucs2strlen((const CHAR *)palyStr)>0)
	{
		Npr_Tts_play_stop();
		Npr_Ttsplayer_playtextw(palyStr,NULL);  
	}
#endif
}

/*电子围栏*/
void kjx_infrared_left_menu_move(void)
{
	char palyStr[]={0x73,0x51,0xed,0x95,0x35,0x75,0x50,0x5b,0xf4,0x56,0xf,0x68,0x0,0x0};/*关闭电子围栏*/
	
	g_kjx_main_func.kjx_set_move_status(0);
#if defined(__NPR_TTS__)
	if(mmi_ucs2strlen((const CHAR *)palyStr)>0)
	{
		Npr_Tts_play_stop();
		Npr_Ttsplayer_playtextw(palyStr,NULL);  
	}
#endif
}

void kjx_infrared_right_menu_move(void)
{
	char palyStr[]={0x0,0x5f,0x2f,0x54,0x35,0x75,0x50,0x5b,0xf4,0x56,0xf,0x68,0x0,0x0};/*开启电子围栏*/
	
	g_kjx_main_func.kjx_set_move_status(1);
#if defined(__NPR_TTS__)
	if(mmi_ucs2strlen((const CHAR *)palyStr)>0)
	{
		Npr_Tts_play_stop();
		Npr_Ttsplayer_playtextw(palyStr,NULL);  
	}
#endif
}

void kjx_infrared_left_menu_speed(void)
{
	g_kjx_main_func.kjx_set_speed_status(0);
}

void kjx_infrared_right_menu_speed(void)
{
	g_kjx_main_func.kjx_set_speed_status(1);
}

void kjx_infrared_left_eint_switch(void)
{
	kjx_trace_infrared("%s",__func__); 
	
	switch(g_infrared_menu_id)
	{
		case  INFRARED_MENU_OBD:
			kjx_infrared_left_menu_obd();
			break;
			
		case  INFRARED_MENU_DOG:
			kjx_infrared_left_menu_dog();
			break;
			
		#if 0
		case  INFRARED_MENU_VOLUME:
			kjx_infrared_left_menu_volume();
			break;
		#endif
		
		case  INFRARED_MENU_VIBR:
			kjx_infrared_left_menu_vibr();
			break;
		
		case  INFRARED_MENU_MOVE:
			kjx_infrared_left_menu_move();
			break;
		
		case INFRARED_MENU_SPEED:
			kjx_infrared_left_menu_speed();
			break;

		default:
			kjx_infrared_left_menu_obd();
			break;
			
	}
}

void kjx_infrared_right_eint_switch(void)
{
	kjx_trace_infrared("%s",__func__); 

	switch(g_infrared_menu_id)
	{
		case  INFRARED_MENU_OBD:
			kjx_infrared_right_menu_obd();
			break;
			
		case  INFRARED_MENU_DOG:
			kjx_infrared_right_menu_dog();
			break;

		#if 0	
		case  INFRARED_MENU_VOLUME:
			kjx_infrared_right_menu_volume();
			break;
		#endif
		
		case  INFRARED_MENU_VIBR:
			kjx_infrared_right_menu_vibr();
			break;
			
		
		case  INFRARED_MENU_MOVE:
			kjx_infrared_right_menu_move();
			break;
		
		case INFRARED_MENU_SPEED:
			kjx_infrared_right_menu_speed();
			break;

		default:
			kjx_infrared_right_menu_obd();
			break;
			
	}
}
 
void kjx_infrared_menu_eint_switch(void)
{
	kjx_trace_infrared("%s",__func__); 

	if(g_infrared_menu_id <= INFRARED_MENU_MAX)
	{
		g_infrared_menu_id++;
		if(g_infrared_menu_id >= INFRARED_MENU_MAX)
		{
			g_infrared_menu_id = INFRARED_MENU_OBD;
		}
	}
		
	kjx_infrared_play_menu();
}


void kjx_infrared_back_eint_switch(void)
{
	char disableStr[]={0x59,0x97,0xf3,0x97,0x21,0x6a,0xf,0x5f,0x0,0x0};/*静音模式*/
	char enableStr[]={0x69,0x62,0xf3,0x97,0x21,0x6a,0xf,0x5f,0x0,0x0};/*扩音模式*/
	
	kjx_trace_infrared("%s",__func__); 

	#if 0
	disable_hand_free = FALSE;
	#endif
	
	if(g_kjx_a62_struct.silentStatus == 1){
		g_kjx_a62_struct.silentStatus = 0;
	#if defined(__NPR_TTS__)
	if((mmi_ucs2strlen((const CHAR *)enableStr)>0))
	{
		Npr_Tts_play_stop();
		Npr_Ttsplayer_playtextw(enableStr,NULL);  
	}
	#endif
	
	}
	else if(g_kjx_a62_struct.silentStatus == 0){
	#if defined(__NPR_TTS__)
	if((mmi_ucs2strlen((const CHAR *)disableStr)>0))
	{
		Npr_Tts_play_stop();
		Npr_Ttsplayer_playtextw(disableStr,NULL);  
	}
	#endif
		g_kjx_a62_struct.silentStatus = 1;
	}
	kjx_a62_nvram_write();

	#if 0
	g_infrared_menu_id = INFRARED_MENU_OBD;
	kjx_infrared_play_menu();
	#endif
}

/********************************************************************************/

/********************************************************************************/
/********************************************************************************/
void kjx_infrared_left_eint_hisr(void)
{
	ilm_struct *fmr_ilm;

	kjx_trace_infrared("%s",__func__); 

	DRV_SendPrimitive(fmr_ilm,MOD_EINT_HISR,MOD_INFRARED,MSG_ID_INFRARED_LEFT_IND,NULL, KJX_INFRARED);
	msg_send_ext_queue(fmr_ilm);
}

void kjx_infrared_right_eint_hisr(void)
{
	ilm_struct *fmr_ilm;

	kjx_trace_infrared("%s",__func__); 

	DRV_SendPrimitive(fmr_ilm,MOD_EINT_HISR,MOD_INFRARED,MSG_ID_INFRARED_RIGHT_IND,NULL, KJX_INFRARED);
	msg_send_ext_queue(fmr_ilm);
}

void kjx_infrared_menu_eint_hisr(void)
{
	ilm_struct *fmr_ilm;

	kjx_trace_infrared("%s",__func__); 

	DRV_SendPrimitive(fmr_ilm,MOD_EINT_HISR,MOD_INFRARED,MSG_ID_INFRARED_MENU_IND,NULL, KJX_INFRARED);
	msg_send_ext_queue(fmr_ilm);
}

void kjx_infrared_back_eint_hisr(void)
{
	ilm_struct *fmr_ilm;

	kjx_trace_infrared("%s",__func__); 

	DRV_SendPrimitive(fmr_ilm,MOD_EINT_HISR,MOD_INFRARED,MSG_ID_INFRARED_BACK_IND,NULL, KJX_INFRARED);
	msg_send_ext_queue(fmr_ilm);
}

void kjx_infrared_init(void)
{
	kjx_trace_infrared("%s",__func__); 

	EINT_Registration(INFRARED_LEFT_NO, KAL_FALSE, INFRARED_STATUS_VALID,kjx_infrared_left_eint_hisr,KAL_TRUE);     
	EINT_Set_Sensitivity(INFRARED_LEFT_NO, EDGE_SENSITIVE); 
	EINT_Set_Polarity(INFRARED_LEFT_NO, KAL_TRUE);
 
	EINT_Registration(INFRARED_RIGHT_NO, KAL_FALSE, INFRARED_STATUS_VALID,kjx_infrared_right_eint_hisr,KAL_TRUE);     
	EINT_Set_Sensitivity(INFRARED_RIGHT_NO, EDGE_SENSITIVE); 
	EINT_Set_Polarity(INFRARED_RIGHT_NO, KAL_TRUE);

	EINT_Registration(INFRARED_MENU_NO, KAL_FALSE, INFRARED_STATUS_VALID,kjx_infrared_menu_eint_hisr,KAL_TRUE);   
	EINT_Set_Sensitivity(INFRARED_MENU_NO, EDGE_SENSITIVE); 
	EINT_Set_Polarity(INFRARED_MENU_NO, KAL_TRUE);

	EINT_Registration(INFRARED_BACK_NO, KAL_FALSE, INFRARED_STATUS_VALID,kjx_infrared_back_eint_hisr,KAL_TRUE);     
	EINT_Set_Sensitivity(INFRARED_BACK_NO, EDGE_SENSITIVE); 
	EINT_Set_Polarity(INFRARED_BACK_NO, KAL_TRUE);

}

kal_bool kjx_infrared_task_init(task_indx_type task_indx)
{
    g_infrared_process_mutex = kal_create_mutex("infrared_process");	 
   return KAL_TRUE;
}


void kjx_infrared_task_main(task_entry_struct * task_entry_ptr)
{
   kal_status result;
   ilm_struct current_ilm;
   kal_uint32 my_index = 0;

   kal_get_my_task_index(&my_index);
   while (1) 
   {
       result = receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
       stack_set_active_module_id(my_index, current_ilm.dest_mod_id);

	switch (current_ilm.msg_id) 
	{
		case MSG_ID_INFRARED_LEFT_IND:
			kjx_infrared_left_eint_switch();
			break;
			
		case MSG_ID_INFRARED_RIGHT_IND:
			kjx_infrared_right_eint_switch();
			break;
			
		case MSG_ID_INFRARED_MENU_IND:
			kjx_infrared_menu_eint_switch();
			break;
			
		case MSG_ID_INFRARED_BACK_IND:
			kjx_infrared_back_eint_switch();
			break;

		default:
			break;
			
	}
       free_ilm(&current_ilm);
   }
}

kal_bool kjx_infrared_task_create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct custom2_handler_info =
   {
      kjx_infrared_task_main,  /* task entry function */
      kjx_infrared_task_init,  /* task initialization function */
      NULL,  /* task configuration function */
      NULL,  /* task reset handler */
      NULL,  /* task termination handler */
   };

   *handle = (comptask_handler_struct *)&custom2_handler_info;
   return KAL_TRUE;
}
#endif
#endif
