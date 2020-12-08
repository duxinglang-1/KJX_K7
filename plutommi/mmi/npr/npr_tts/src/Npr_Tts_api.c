//file name: Npr_Tts_api.c
//  hyc
//语音王外部适配接口文件
#include "MMI_features.h" 
#ifdef __NPR_TTS__
#include "MMI_include.h"
#include "ConnectivityResDef.h"
#include "SettingProfile.h"
#include "IdleAppResDef.h"
#include "IdleAppDef.h"
#include "FileManagerGProt.h"
#include "NVRAMType.h"
#include "NVRAMProt.h"
#include "GlobalMenuItems.h"
#include "ProfilesAppGprot.h"
#include "custom_phb_config.h"

#include "ucmsrvgprot.h"
#include "toneselectorcui.h"
#include "mdi_audio.h"
#include "TimerEvents.h"
#include "med_utility.h"
#include "Kjx_prin.h"

//局部引用
#include "mmi_rp_app_bootup_def.h"
#include "mmi_rp_app_ucm_def.h"

#include "Npr_ivTTs.h"
#include "npr_ttsu_gprot.h"
#include "Mmi_rp_app_npr_tts_def.h"
#include "mmi_rp_app_downloadagent_def.h"

#include "mmi_rp_cui_dialer_def.h"
#if defined(__MMI_AUDIO_PLAYER__)
#include "AudioPlayerType.h"
#endif

#include "NPR_TTSgprot.h" 

//#include "../../../../../../ggt/inc/GGT_utility.h" //xuhongfu

#ifdef  __MMI_FM_RADIO__  
extern BOOL mmi_fmrdo_is_power_on(void);
#endif

#ifdef __MMI_AUDIO_PLAYER__ 
extern MMI_BOOL mmi_audply_is_playing(void);
extern S32 mdi_audio_get_background_callback_order(U8 app_level);
#endif

//extern void GT_TRACE(const char *fmt, ...); //xuhongfu

extern MMI_BOOL mmi_idle_is_active(void);
extern MMI_BOOL mmi_medply_is_play_activated(void);
extern U16 srv_sms_get_unread_sms_num(void);

void NPR_TTS_AppendString(kal_uint8 *dest_buf,kal_uint8 *src_buf)
{
    mmi_ucs2cat((PS8)dest_buf, (PS8)src_buf);

}

BOOL NPR_TTS_is_audio_bkplay(void)
{
	BOOL is_background_play = FALSE;
#if 0//defined ( __MMI_FM_RADIO__ ) 
	if( mmi_fmrdo_is_power_on() || -1 != mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_FMR))
	{
	is_background_play = TRUE;
	}
#endif
#if 0//defined (__MMI_AUDIO_PLAYER__)
	if(mmi_audply_is_playing() || -1 != mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_AUDPLY))
	{
	is_background_play = TRUE;
	}
#endif

#if  0///defined(__MMI_MEDIA_PLAYER__) || defined(__COSMOS_MUSICPLY__)  //需求更改,后台播音乐可读菜单
	if(mmi_medply_is_play_activated() || -1 != mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_MEDPLY))
	{
	is_background_play = TRUE;
	}
#endif

#ifdef __J2ME__
if( -1 != mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_JAVA))
	{
	is_background_play = TRUE;
	}
#endif

if( -1 != mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_MRE))
	{
	is_background_play = TRUE;
	}

#ifdef OPERA_V10_BROWSER
  if( -1 != mdi_audio_get_background_callback_order(MDI_BACKGROUD_APP_OPERA))
	{
	is_background_play = TRUE;
	}
#endif

        return is_background_play;
}

int NPR_TTS_DialNumberRead(UI_character_type  c)
{
	char *pText = NULL;	
	S32 scr = GetActiveScreenId();
	S32  scr2 = GetCurrScrnId();

	kal_prompt_trace(MOD_XDM, "NPR_TTS_DialNumberRead");
	if (!NPR_TTS_get_read_flag(NPR_TTS_KEYPAD ))
		return;	
	kal_prompt_trace(MOD_XDM, "NPR_TTS_DialNumberRead  11");

       if( scr !=  SCR_ID_CUI_DIALER_MAIN && scr2 != GRP_ID_IDLE_MAIN)
   		return;

	 kal_prompt_trace(MOD_XDM, "NPR_TTS_DialNumberRead  222");

	switch(c)
	{
		case '0':
			pText = "0";
			break;
		case '1':
			pText = "1";
			break;
		case '2':
			pText = "2";
			break;
		case '3' :
			pText = "3";
			break;
		case '4':
			pText = "4";
			break;
		case '5':
			pText = "5";
			break;
		case '6':
			pText = "6";
			break;
		case '7':
			pText = "7";
			break;
		case '8':
			pText = "8";
			break;
		case '9':
			pText = "9";
			break;
		case '*':
			pText = "*";
			 break;
		case 'p':
		case 'P':	
			pText = "p";
			 break;
		case 'w':
		case 'W':	
			pText = "w";
			 break;
		case '+':	
			pText = "+";
			 break;		 
		case '#':
			 pText = "#";
			 break;
		default:
			pText = "#";
			break;
	}
    return   Npr_Ttsplayer_playtextw((char *)pText, NULL);
}



extern void Npr_Tts_stop_immediately(void);

extern void mmi_ucm_play_incoming_tone(void);
char npr_tts_repeat = 0;

void NPR_TTS_IncomingCallCB(void *info)
{
	mmi_ucm_play_incoming_tone();
	npr_tts_repeat = 1;
	Npr_Ttsplayer_playtextw(NULL, NULL);
}


int NPR_TTS_IncomingCallToneRead(S8 *text)
{
#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("npr_tts_repeat:%d", npr_tts_repeat);
#endif
#endif
    if (npr_tts_repeat == 1)
		return 100;

#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("npr_tts_repeat:%d, text:%s", npr_tts_repeat, text);
#endif
#endif
	
    return Npr_Ttsplayer_playtextw((char*)text, NPR_TTS_IncomingCallCB);
}

void NPR_TTS_IncomingCallToneStop(void)
{
	npr_tts_repeat = 0;
	Npr_Tts_stop_immediately();
	Npr_Ttsplayer_playtextw(NULL, NULL);
}

int NPR_TTS_PlayIncomingcall(char *ptext)
{
	S16 index = 0;
	short pText[] = {0x7684,0x6765,0x7535,0x0000};
	kal_uint8 ttsbuf[256] = {0};

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/	
#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
	if (!NPR_TTS_get_read_flag(NPR_TTS_INCOMING_CALL ))
		return 1;

	if (mmi_ucs2strlen((PS8) ptext) != 0)
	{
		NPR_TTS_AppendString(ttsbuf, (kal_uint8 *)(PS8) ptext);
		NPR_TTS_AppendString(ttsbuf, (kal_uint8 *)pText);
	}

#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("end");
#endif
#endif
	return NPR_TTS_IncomingCallToneRead((char*)ttsbuf);  
}


int NPR_TTS_ReadSmsContent(char * ptext)
{
	 if (!NPR_TTS_get_read_flag(NPR_TTS_SMS_AUTO))
  	 {
		return 1;
  	 }

	return Npr_Ttsplayer_playtextw((char *)ptext, NULL);	 
}


#if 1
#include "MmsSrvGprot.h"
S32 NPR_TTS_get_unread_mms_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 number = 0;
    S32 result = 0;
    srv_mms_get_msg_count_struct msg_count_req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    if (srv_mms_is_wap_ready())
//    {
        memset(&msg_count_req,0, sizeof(srv_mms_get_msg_count_struct));
        msg_count_req.count = 1;
        msg_count_req.req_tb[0] = SRV_MMS_QUERY_TOTAL_UNREAD_INBOX_MSG;
        result = srv_mms_get_msg_count(&msg_count_req);

        if (result == SRV_MMS_RESULT_OK)
        {
            number = msg_count_req.rsp_tb[0];
        }
//    }

    return number;
}

S32 NPR_TTS_get_read_number(void)
{
 S32 retnum = 0;
	retnum   = srv_sms_get_unread_sms_num() + NPR_TTS_get_unread_mms_number();
return retnum;
}

extern MMI_BOOL mmi_nmgr_is_active(void);

BOOL NPR_TTS_NeedReadRecvSms(void)
{

	if (!NPR_TTS_get_read_flag(NPR_TTS_RECV_SMS ))
	return 0;
	
	if   (srv_prof_get_activated_profile() == MMI_PROFILE_SILENT || srv_prof_get_activated_profile() == MMI_PROFILE_MEETING )
	return 0;
	if (!mmi_idle_is_active())
	return 0;
	
	return 1;
}
int  new_msg_recv_read(void)
{
	U16 buffer[20] = {0};
	S32 error= 0;
	U16 receive[3] = {25910,21040,0};
	U16 sms[4] = {26465,30701,20449,0};
	U8 dummyString[5];  
	S8 sms_count[10];
	
      // kal_prompt_trace(MOD_XDM, "control_notification 222");


     
	mmi_ucs2cat((CHAR *)buffer,(CHAR *)receive);

	sprintf(sms_count, "%d", NPR_TTS_get_read_number());//srv_sms_get_unread_sms_num());

	strcpy((PS8) dummyString, sms_count);

	mmi_asc_to_ucs2((PS8) sms_count, (PS8) dummyString);

	mmi_ucs2cat((CHAR *)buffer,(CHAR *)sms_count);

	mmi_ucs2cat((CHAR *)buffer,(CHAR *)sms);
	Npr_Tts_set_digit_read_mod(1);
	error = Npr_Ttsplayer_playtextw((char *)buffer, NULL);
	return error;
}
#endif

void NPR_TTS_AppendTime(kal_uint8 *dest_buf)
{

	MYTIME currTime;
	U8 dummyString[5];  /* max length is of year 4 */
	S8 gHour[MAX_LENGTH * ENCODING_LENGTH];
	S8 gMinute[MAX_LENGTH * ENCODING_LENGTH];
       char *dot = ";";

	GetDateTime(&currTime);
	
	sprintf(gHour, "%02d", currTime.nHour);
	sprintf(gMinute, "%02d", currTime.nMin);

	strcpy((PS8) dummyString, gHour);
	mmi_asc_to_ucs2((PS8) gHour, (PS8) dummyString);

	strcpy((PS8) dummyString, gMinute);
	mmi_asc_to_ucs2((PS8) gMinute, (PS8) dummyString);

	mmi_ucs2cat((PS8) dest_buf, (PS8) gHour);
	mmi_ucs2cat((PS8) dest_buf, (PS8) ":");
	mmi_ucs2cat((PS8) dest_buf, (PS8) gMinute);
	mmi_ucs2cat((PS8) dest_buf, (PS8) " ");
	memset (dummyString, 0, 5);
	mmi_asc_to_ucs2((PS8) dummyString, (PS8) dot);
	mmi_ucs2cat((PS8) dest_buf, (PS8) dummyString);
	mmi_ucs2cat((PS8) dest_buf, (PS8) dummyString);
	
}

void NPR_TTS_PlayAutoTime(void)
{
        MYTIME currTime;
	 const short timetext[] = {0x73b0,0x5728,0x662f,0x5317,0x4eac,0x65f6,0x95f4,0xff0c,0x0000};
	kal_uint8 ttsbuf[128] = {0};

	 if (!NPR_TTS_get_read_flag(NPR_TTS_TIME_AUTO))
  	 {
		return;
  	 }
	 
	 GetDateTime(&currTime);
	
	// if((currTime.nMin % 30 == 0)&&(currTime.nSec == 0))    //xuhongfu
	//{
		if(!mmi_idle_is_active())
		{
			return;
		}
		if(srv_prof_get_activated_profile() == MMI_PROFILE_SILENT||srv_prof_get_activated_profile() == MMI_PROFILE_MEETING )
		{
			return;
		}
		
		NPR_TTS_AppendString((kal_uint8 *)ttsbuf, (kal_uint8 *)timetext);	
		NPR_TTS_AppendTime((kal_uint8 *)ttsbuf);	
		Npr_Tts_set_digit_read_mod(1);
		Npr_Ttsplayer_playtextw((char *)ttsbuf, NULL);
						
	//}  //xuhongfu
}

void NPR_TTS_PlayAnyTime(void)
{
       MYTIME currTime;
	MMI_BOOL is_background_play = MMI_FALSE;   
	const short timetext[] = {0x73b0,0x5728,0x662f,0x5317,0x4eac,0x65f6,0x95f4,0xff0c,0x0000};
	kal_uint8 ttsbuf[128] = {0};

	GetDateTime(&currTime);
	if (!NPR_TTS_get_read_flag(NPR_TTS_TIME_HAND))
	{
		return;
	}

#if 0  //xuhongfu
	if(!mmi_idle_is_active())
	{
		return;
	}
#endif
	
	NPR_TTS_AppendString((kal_uint8 *)ttsbuf, (kal_uint8 *)timetext);	
	NPR_TTS_AppendTime((kal_uint8 *)ttsbuf);	
	Npr_Tts_set_digit_read_mod(1);

#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("001");
#endif
#endif
	Npr_Ttsplayer_playtextw((char *)ttsbuf, NULL);
}

static char *NPR_TTS_read_menu_text = NULL;

MMI_BOOL NPR_TTS_get_menu_read_enble(void)
{
if (! NPR_TTS_get_read_flag(NPR_TTS_MENU))
	return MMI_FALSE;
if (NPR_TTS_is_audio_bkplay())
	return MMI_FALSE;

return MMI_TRUE;
}
void NPR_TTS_read_menu_cb(void)
{
       gui_cancel_timer(NPR_TTS_read_menu_cb);
	Npr_Tts_set_digit_read_mod(2); 
	Npr_Ttsplayer_playtextw(NPR_TTS_read_menu_text, NULL);
}


int NPR_TTS_menu_read(char * pText)
{
	gui_cancel_timer(NPR_TTS_read_menu_cb);
	if (!NPR_TTS_get_read_flag(NPR_TTS_MENU ))
		return 1;
	
	if (!NPR_TTS_get_menu_read_enble())
		return 1;

	   NPR_TTS_read_menu_text = pText;
	  gui_start_timer(10, NPR_TTS_read_menu_cb);

	 return 0; 
}

void Npr_Tts_stop_menuread_immediately(void)
{
	gui_cancel_timer(NPR_TTS_read_menu_cb);
	Npr_Tts_stop_immediately();
}


#if 1

///////////////电话本朗读BEGIN/////////////////////////////////////
void npr_tts_phb_name(U16 *WName,S32 Index,U8 SortFlg)
{

        if(0 == SortFlg) 
	{
               srv_phb_get_name(srv_phb_sse_sort_index_to_store_index(PHB_STORAGE_MAX,Index), WName, (MMI_PHB_NAME_LENGTH + 1));
        } 
	else
	{
                srv_phb_get_name(Index, WName, (MMI_PHB_NAME_LENGTH + 1));
        }        
   
}
void npr_tts_phb_num(U16 *WNum,S32 Index,U8 SortFlg)
{

        if(0 == SortFlg) 
	{
                srv_phb_get_number(srv_phb_sse_sort_index_to_store_index(PHB_STORAGE_MAX,Index), (U16*)WNum, (MMI_PHB_NUMBER_LENGTH + 1));
        }
	else 
        {
                srv_phb_get_number(Index, (U16*)WNum, (MMI_PHB_NUMBER_LENGTH + 1));
        }

}

char    phbreadtext[256];
short npr_tts_phone_book_info(int index)
{
       // char    *phbreadtext;
        char    *text1;
        U16     length = 0;
        short   err;

	gui_cancel_timer(NPR_TTS_read_menu_cb);
	if (!NPR_TTS_get_read_flag(NPR_TTS_MENU ))
		return 1;
	
	if (!NPR_TTS_get_menu_read_enble())
		return 1;

	kal_print("npr_tts_phone_book_info  000");
	
       // phbreadtext = (char*)med_alloc_ext_mem(512);
       // if(!phbreadtext) return 111;
        kal_print("npr_tts_phone_book_info  111");      
        npr_tts_phb_name((U16 *)phbreadtext,index,1);
        kal_print("npr_tts_phone_book_info  2222");      
 
        //mmi_ucs2cat((S8*) phbreadtext, (S8*)read_str_00);
        length = mmi_ucs2strlen((S8*) phbreadtext);

        npr_tts_phb_num((U16 *)(phbreadtext + length * 2), index, 1);
        text1 = phbreadtext + length * 2;
	kal_print("npr_tts_phone_book_info  333");      
	
        /* +不读  +86送给引擎处理 */
        if ( '+' == text1[0] && ('8' != text1[2] || '6' != text1[4]) ) 
	{
                text1[0] = ' ';
        }
        length += mmi_ucs2strlen((S8*) (phbreadtext + length * 2));
       // mmi_ucs2cat((S8*) phbreadtext, (S8*)read_str_02);
        kal_print("npr_tts_phone_book_info  444");      
      err = NPR_TTS_menu_read(phbreadtext);
  	kal_print("npr_tts_phone_book_info  555");      

		
     //  med_free_ext_mem((void **)&phbreadtext);
	kal_print("npr_tts_phone_book_info  666");      
      return err;
}

///////////////电话本朗读END/////////////////////////////////////

 BOOL Npr_Tts_read_need(void)
 {
 //预留接口，客户可添加不朗读条件

 return TRUE;
 }
#endif
#endif
