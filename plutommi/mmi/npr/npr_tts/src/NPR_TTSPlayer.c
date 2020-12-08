/**********************************************************************
*	FileName	：IV_TTSPlayer.c
*	Description	：TTS Player For MTK
*	Author		：jhlv
*	Create Date	：2008-6-22
*	Project		：TTS Player
*	Platform	：MTK6226
*---------------------------------------------------------------------*
*	History：
*	NO.		Data		Author		Remark
**********************************************************************/
#ifdef __NPR_TTS__
#include "mmi_include.h"
#include "MMI_features.h"
#include "kal_release.h" 
#include "kal_trace.h"
#include "custom_config.h"
#include "TimerEvents.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
             
#include "L1audio.h"
#include "mdi_datatype.h" 
#include "Med_api.h"
#include "mdi_audio.h"
#include "aud_defs.h"
#include "DEVICE.H"
#include "med_utility.h"
//#include "EventsGprot.h"
#include "NPR_TTSPlayer.h"
#include "AudioPlayerDef.h"
#include "AudioPlayerType.h"
#include "SettingProfileEnum.h"
#include "ProfilesAppGprot.h"
#include "Conversions.h"
#ifdef __MMI_MMS_2__
#include "MmsSrvGprot.h"
#endif
#include "ProfilesSrv.h"
#include "GeneralDeviceGprot.h"
#include   <setjmp.h> 
#include "UcmSrvGprot.h"
#include "mmi_rp_app_npr_tts_def.h"
#include "NPR_TTSPlayer.h"
#include "NPR_TTSgprot.h"
#if defined(__KJX_LOG_OUTPUT__)
#include "Kjx_prin.h"
#endif

/* 播音缓冲区长度 */
#ifdef IFLYTEK_TTS_16K
#define IV_TTS_AUDIO_BUF_LEN	(IV_TTS_AUDIO_BUF_SIZE )
#else
#define IV_TTS_AUDIO_BUF_LEN	(IV_TTS_AUDIO_BUF_SIZE )
#endif
/* 积攒到一定数据后打开播音的阈值 */
#define IV_TTS_PLAY_START_LEN	(IV_TTS_PLAYSTART_SIZE )

#ifndef IV_TTS_MEMORY_PREASSIGN
//最大设置参数种类
#define ivMaxSetParamClass 20
#endif
#define IV_TTS_FLAG	1234457
#define GetRingVolumeLevel  srv_prof_get_ring_vol
#define gactivatedprofile srv_prof_get_activated_profile()


#ifdef IV_TTS_Trace
#undef IV_TTS_Trace
#endif

/* TTS Player 运行状态 */
typedef enum
{
	ivTTS_STATUS_IDLE,			/* 无效 */
	ivTTS_STATUS_INITIALIZED,	/* 初始化完毕 */
	ivTTS_STATUS_PAUSE,			/* 暂停 */
	ivTTS_STATUS_SYNTHESIZING,	/* 正在合成 */
	ivTTS_STATUS_PLAYING,		/* 正在播音 */
	ivTTS_STATUS_SYNTHESIZED,	/* 合成完毕 */
	ivTTS_STATUS_PALYEND		/* 播音完毕 */
}ivTTS_status;

/* TTS Service 全局结构体 */
typedef struct
{
	ivHTTS				hTTS;			/* TTS内核实例句柄 */
	ivPByte				pHeap;			/* TTS内核实例堆 */
	ivTTS_status		status;			/* TTS Player 运行状态 */
	ivTTS_status		last_status;	/* TTS Player 暂停前的状态 */
	U32 				nOutLen;		/* 输出PCM长度统计，用于计算何时开始播音 */
	U32 				nFlag;			/* 标识，用于判断TTS Service是否开启 */
	U8					bOpenDevice;		/* 表示TTS内核实例控制权 */
	ivTTSErrID			iResult;		/* 错误码 */
	ivUInt8				iTextSelect;	/* 文本选择 */
	ivPointer			pText[2];			/* 需要合成的文本 */
	ivUInt32			nTextSize[2];		/* 合成文本大小 */
	ivUInt32			nMaxTextBuff[2];	/* 文本缓冲区大小 */

	U8					*pTTS_Audio_Buff;
	ivUInt32			iTTSParam;
	ivUInt32			iCodePage;
	ivUInt8				nMsg;
	ivUInt8				iSuspend;
	MHdl *mhdl_handle;
#ifndef IV_TTS_MEMORY_PREASSIGN
	ivUInt32			id_array[ivMaxSetParamClass];
	ivUInt32      		value_array[ivMaxSetParamClass];
	ivUInt8				set_param_time;
#endif	
}ivTTS_cntx_struct;

ivTTS_cntx_struct g_ivTTS_cntx;
ivTResPackDesc g_ivTTS_tResPackDesc;	/* 资源访问结构体 */
short g_TTS_nLastSample = 0;
/* 资源配置结构体 */
/* 资源在文件系统 */
struct TResFile_IVTTS
{
	short nCacheSize;
	short nCacheCount;
};

static struct TResFile_IVTTS g_TTS_ResFile = {512, 64};
static jmp_buf jmpbufTTS;
extern char g_imei_cntx[20];
extern srv_prof_cntx_struct g_srv_prof;

#ifdef __NPR_TTS_RES_IN_ROM__
#include "Npr_Tts_Resource.hxx"
//extern 
/* 资源在ROM */
struct TResMem_IVTTS
{
	short nCacheSize;
	short nCacheCount;
	const void* pResAddr;
};

#define TTSResPackFileSetItem(a,b,c)	
#define TTSResPackMemSetItem(a,b,c)	
#define TTSResPackEndItem(a,b,c)		{0, 0, 0}

static struct TResMem_IVTTS g_TTS_ResMem[] =
{
	#include "Npr_Tts_res.hxx"
};
#endif

/* 
 * Global Function
 */
extern S32 UCS2Strlen(const S8 *arrOut);
extern kal_uint16 AnsiiToUnicodeString(kal_char *pOutBuffer, kal_char *pInBuffer );
extern kal_uint8 custom_cfg_hw_aud_output_path( kal_uint8 speaker_id );
extern BOOL mdi_audio_check_states_and_handlers( mdi_result* result_p );

extern void IFLYTEK_TTSEngineStop(void);
extern void IFLYTEK_TTSCheckStatus(void);
extern void IFLYTEK_TTSCheckBuffer(void);
extern void NPR_TTSPlayer_TestCB(void *info);
extern void IFLYTEK_MMI_StopTTSCB(void *info);
extern ivTTSErrID IFLYTEK_TTSEngineSetParam(ivUInt32 nParamID,  ivUInt32 nParamValue);
extern void NPR_TTSPlayer_CheckRes(void);

extern kal_int8 NPR_pcm_push_data( kal_int16 *pData, kal_uint32 *pnSample);
extern kal_int32 npr_pcm_getdatacount(void);
extern void NPR_TTSPlayer_SendMessageTTS2MMI(msg_type nMsgID);
extern kal_uint8 npr_tts_pcm_play_start(kal_uint16 SampleFreq);
extern kal_uint8 npr_tts_pcm_play_stop(void);
extern kal_int8 *app_ucs2_itoa (kal_int32 val, kal_int8 *buf, kal_int32 radix);
extern srv_prof_internal_profile_enum srv_prof_get_activated_profile(void);
extern BOOL mmi_profiles_is_ring_tone_playing(void);
extern U16 GetActiveScreenId(void);
extern S8 *UCS2Strcat(S8 *strDestination, const S8 *strSource);

//extern void GT_TRACE(const char *fmt, ...);  //xuhongfu
	
void NPR_TTSPlayer_EngineDestroy(void);
static char Npr_Tts_is_play_enable(void);
void Npr_Tts_stop_immediately(void);
void Npr_Tts_reset_status(void);
void Npr_Tts_set_digit_param(char mod);
void NPR_TTSGetResPath(NPR_TTS_RES_PATH_TYPE path_type, UI_character_type path[]);

typedef void (* npr_tts_end_cb_funptr)(void * info);
#define NPR_TTS_DIGIT_DEFAULT_MODE   1

U8 g_npr_tts_tone = 0;  //hyc.debug
U8 g_tts_vol_lev = 0;
npr_tts_end_cb_funptr Npr_Tts_end_cb = NULL;
U8 npr_temp_free = 0;
char npr_tts_digit_mod = NPR_TTS_DIGIT_DEFAULT_MODE;

void NPR_TRACE(const char *fmt, ...)
{
	//GT_TRACE(fmt);
}

#ifndef IV_TTS_MEMORY_PREASSIGN
//存储起来以便下一次创建使用
void NPR_TTSPlayer_Value_PushArray(ivUInt32 nParamID,  ivUInt32 nParamValue)
{
	int i = 0;
	for(i = 0; i < g_ivTTS_cntx.set_param_time; ++i)
	{
		//id存在，覆盖
		if(nParamID == g_ivTTS_cntx.id_array[i])
		{
			g_ivTTS_cntx.value_array[i] = nParamValue;
			return;
		}
	}
	//Array满了
	if(ivMaxSetParamClass == g_ivTTS_cntx.set_param_time)
		return;
	//id没有，增加
	g_ivTTS_cntx.id_array[g_ivTTS_cntx.set_param_time]	= nParamID;
	g_ivTTS_cntx.value_array[g_ivTTS_cntx.set_param_time] = nParamValue;
	++g_ivTTS_cntx.set_param_time;
}

//删除第nIndex个id,value组
void NPR_TTSPlayer_Value_Delete(ivUInt8 nIndex)
{
	int i;
	--g_ivTTS_cntx.set_param_time;
	for(i = nIndex; i < g_ivTTS_cntx.set_param_time; ++i)
	{
		g_ivTTS_cntx.id_array[i] = g_ivTTS_cntx.id_array[i+1];
		g_ivTTS_cntx.value_array[i] = g_ivTTS_cntx.value_array[i+1];
	}
}
#endif

void NPR_TTSPlayer_TTS_Init(void)
{
	memset(&g_ivTTS_cntx, 0, sizeof(g_ivTTS_cntx));
	g_ivTTS_cntx.nFlag = IV_TTS_FLAG;
}

void IV_TTS_Sleep( ivUInt32 nTime )
{
	kal_sleep_task(nTime);
}

void NPR_TTSPlayer_MMI_StopTTSCB(void *info)
{
	if (!g_ivTTS_cntx.nMsg)
	{
		npr_tts_end_cb_funptr endcb = 0;
		endcb = Npr_Tts_end_cb;
		Npr_Tts_end_cb = 0;

		if (endcb)
			(endcb)(info);

		IFLYTEK_MMI_StopTTSCB(info);
	#ifndef IV_TTS_MEMORY_PREASSIGN
		NPR_TTSPlayer_EngineDestroy();
	#endif
		NPR_TTSPlayer_SendMessageTTS2MMI(MSG_ID_TTSPLAYER_SYNEND);
		if (g_ivTTS_cntx.status > ivTTS_STATUS_INITIALIZED)
		{
			g_ivTTS_cntx.status = ivTTS_STATUS_INITIALIZED;
		}
	}
}

void NPR_TTSPlayer_Set_MMI_MsgCB(unsigned char iMsg)
{
	switch( iMsg )
	{
	case IVTTS_TTSPLAYER_MMI_START_TTS:
		SetProtocolEventHandler(NPR_TTSPlayer_TestCB, MSG_ID_TTSPLAYER_MMI_START_TTS);
		break;
	case IVTTS_TTSPLAYER_MMI_STOP_TTS:
		SetProtocolEventHandler(NPR_TTSPlayer_MMI_StopTTSCB, MSG_ID_TTSPLAYER_MMI_STOP_TTS);
		break;
	case IVTTS_TTSPLAYER_NULL:
		SetProtocolEventHandler(ivNull, MSG_ID_TTSPLAYER_MMI_START_TTS);
		SetProtocolEventHandler(ivNull, MSG_ID_TTSPLAYER_MMI_STOP_TTS);
		break;
	default:
		return;
	}
}

void NPR_TTSPlayer_Send_Msg_To_MMI(ivTTS_Msgs iMsg)
{
	ilm_struct *send_ilm = NULL;
#if 0

	/* 发送合成文本的消息 */
	send_ilm = allocate_ilm(MOD_IVTTS);
	send_ilm->src_mod_id = MOD_IVTTS;
#else
	module_type curr_mod = 0,dest_mod = 0;

	curr_mod = stack_get_active_module_id();
	dest_mod = MOD_MMI;
	
	/* 发送合成文本的消息 */
	send_ilm = allocate_ilm(curr_mod);
	send_ilm->src_mod_id = curr_mod;
#endif
	send_ilm->dest_mod_id = MOD_MMI;
	switch( iMsg )
	{
	case IVTTS_TTSPLAYER_MMI_START_TTS:
		send_ilm->msg_id = MSG_ID_TTSPLAYER_MMI_START_TTS;
		break;
	case IVTTS_TTSPLAYER_MMI_STOP_TTS:
		send_ilm->msg_id = MSG_ID_TTSPLAYER_MMI_STOP_TTS;
		break;
	default:
		return;
	}
	msg_send_ext_queue(send_ilm);
}

void NPR_Send_Msg_MMI_To_IVTTS(ivTTS_Msgs iMsg)
{
	ilm_struct *send_ilm = NULL;
#if 0

	/* 发送合成文本的消息 */
	send_ilm = allocate_ilm(MOD_MMI);
	send_ilm->src_mod_id = MOD_MMI;
#else
	module_type curr_mod = 0,dest_mod = 0;

	curr_mod = stack_get_active_module_id();
	dest_mod = MOD_IVTTS;
	
	/* 发送合成文本的消息 */
	send_ilm = allocate_ilm(curr_mod);
	send_ilm->src_mod_id = curr_mod;
#endif
	send_ilm->dest_mod_id = MOD_IVTTS;
	switch( iMsg )
	{
	case IVTTS_TTSPLAYER_PLAYTEXT:
		send_ilm->msg_id = MSG_ID_TTSPLAYER_PLAYTEXT;
		break;
	case IVTTS_TTSPLAYER_SERVICEOPEN:
		send_ilm->msg_id = MSG_ID_TTSPLAYER_SERVICEOPEN;
		break;
	case IVTTS_TTSPLAYER_SERVICECLOSE:
		send_ilm->msg_id = MSG_ID_TTSPLAYER_SERVICECLOSE;
		break;
	default:
		return;
	}
	msg_send_ext_queue(send_ilm);
}

/*****************************************************************************
 * FUNCTION
 *  IFLYTEK_TTSPlayer_ServiceOpen
 * DESCRIPTION
 *  Open of TTS application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* 打开TTS服务 */
ivTTSErrID IFLYTEK_TTSPlayer_ServiceOpen(void)
{
	NPR_TTSPlayer_CheckRes();
	NPR_TTSEngineCreate();
	g_ivTTS_cntx.nFlag = IV_TTS_FLAG;
	return ivTTS_ERR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  IFLYTEK_TTSPlayer_ServiceClose
 * DESCRIPTION
 *  Close of TTS application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* 关闭TTS服务 */
void IFLYTEK_TTSPlayer_ServiceClose(void)
{
	ivUInt16 nWaitTime = 0;
	//GT_TRACE("IFLYTEK_TTSPlayer_ServiceClose line=%d",__LINE__);
#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
	IFLYTEK_TTSPlayer_Stop();
	// 发送关闭服务的消息
	NPR_Send_Msg_MMI_To_IVTTS(IVTTS_TTSPLAYER_SERVICECLOSE);

	while ( ivTTS_STATUS_IDLE != g_ivTTS_cntx.status )
	{
		IV_TTS_Sleep(20);
		nWaitTime += 20;
		if ( nWaitTime > 400 )
		{
			break;
		}
	}
	g_ivTTS_cntx.nFlag = 0;
}

void IV_TTS_Media_Pause(void){}

void IV_TTS_Media_Resume(void){}

ivUInt32 IV_TTS_Media_GetDataCount(void)
{
    return (ivUInt32)npr_pcm_getdatacount();
}

ivBool IV_TTS_Is_Background_Suspended(void)
{
	return (ivBool)mdi_audio_is_background_play_suspended();
}

void NPR_TTS_Suspend_Background(void)
{
	ivUInt8 n = g_ivTTS_cntx.status;

	mdi_audio_suspend_background_play();
#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("status:%d", g_ivTTS_cntx.status);
#endif
#endif
	g_ivTTS_cntx.status = n;
}

void IV_TTS_Resume_Background(void)
{
#ifdef SLC_TTS_LOG    
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
	mdi_audio_resume_background_play();
} 

void* IV_TTS_Alloc(ivInt32 nSize)
{
#ifdef IV_TTS_Trace
	kal_prompt_trace(MOD_IVTTS, "IV_TTS_Alloc");
#endif
#if defined (__MED_IN_ASM__)
	return applib_asm_alloc_anonymous(nSize);
#else
	return med_alloc_ext_mem(nSize);
#endif
}

void IV_TTS_Free(void** pointer)
{
#ifdef	IV_TTS_Trace
	kal_prompt_trace(MOD_IVTTS, "IV_TTS_Free");
#endif
#if defined (__MED_IN_ASM__)
	applib_asm_free_anonymous(*pointer);
#else
	med_free_ext_mem(pointer);
#endif
}

ivInt32 NPR_TTS_Get_UCStr_Len(ivCStrW pText)
{
#ifdef	IV_TTS_Trace
	int n = mmi_ucs2strlen((const S8*)pText);
	kal_prompt_trace(MOD_IVTTS, "play text len = %d", n);
	return n;
#endif
	return (ivInt32)mmi_ucs2strlen((const S8*)pText);
}

void IV_TTS_Media_Stop(void)
{
	/* 释放播音设备 */
	npr_tts_pcm_play_stop();
#ifdef	IV_TTS_Trace
	kal_prompt_trace(MOD_IVTTS, "TTS Play Stop");
#endif
}

void NPR_TTS_Media_Play(void)
{
	kal_uint8 result;
	srv_prof_setting_struct settings;

#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

#ifdef IFLYTEK_TTS_16K
	result = npr_tts_pcm_play_start(16000);
#else
	result = npr_tts_pcm_play_start(8000);
#endif

#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("result:%d", result);
#endif
#endif

	/* 发送合成文本的消息 */
	NPR_Send_Msg_MMI_To_IVTTS(IVTTS_TTSPLAYER_PLAYTEXT);
	NPR_TTSPlayer_SendMessageTTS2MMI(MSG_ID_TTSPLAYER_STARTSYN);
	if ( 0 != result )
	{
		IFLYTEK_TTSEngineStop();
	}
	else
	{   
		srv_prof_get_profile_values((srv_prof_internal_profile_enum)g_srv_prof.cur_prof, &settings);

	#if 0//defined(CUSTOMER_NAME_TOUR)	   
		{
			extern U8 kjx_get_earphone_plugged(void);

			if(kjx_get_earphone_plugged())
		}
	#else
		//mdi_audio_set_volume(MDI_VOLUME_MEDIA, settings.ring_vol);
		mdi_audio_set_volume(MDI_VOLUME_MEDIA, 6);
	#endif

	#ifdef SLC_TTS_LOG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("end");
	#endif
	#endif
	}
}

ivTTSErrID NPR_TTS_SendData(ivCPointer pcData, ivSize nSize)
{
	kal_uint8 result;
	kal_int16 *lpSrc;
	kal_uint32 nPCMLen;
	kal_uint32 nTemp = 0;

	/* 看是否需要暂停 */
	//IFLYTEK_TTSCheckStatus();
#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
	lpSrc = (kal_int16 *) g_ivTTS_cntx.pTTS_Audio_Buff;

#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_ivTTS_cntx.nOutLen:%d", g_ivTTS_cntx.nOutLen);
#endif
#endif

	while ( g_ivTTS_cntx.nOutLen )
	{
		nPCMLen = g_ivTTS_cntx.nOutLen >> 1;
		NPR_pcm_push_data( lpSrc, &nPCMLen);
		if ( nPCMLen )
		g_TTS_nLastSample = *(lpSrc + nPCMLen - 1);
		lpSrc += nPCMLen;
		g_ivTTS_cntx.nOutLen = g_ivTTS_cntx.nOutLen - nPCMLen * 2;

		kal_sleep_task(1);
		nTemp += 1;
		if ( nTemp > 200 || g_ivTTS_cntx.status <= ivTTS_STATUS_SYNTHESIZING )
		{
		#ifdef SLC_TTS_LOG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("return 001 ivTTS_ERR_FAILED");
		#endif
		#endif
			return ivTTS_ERR_FAILED;
		}
	}

	lpSrc = (kal_int16 *)pcData;
	nPCMLen = nSize >> 1;

#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("nPCMLen:%d", nPCMLen);
#endif
#endif

	if(nPCMLen == 0)
		return ivTTS_ERR_FAILED;

	while ( nPCMLen )
	{
		nTemp = nPCMLen;
		result = NPR_pcm_push_data( lpSrc, &nTemp);
		if ( nTemp )
		g_TTS_nLastSample = *(lpSrc + nTemp - 1);
		lpSrc += nTemp;
		nPCMLen = nPCMLen - nTemp;

		if ( nPCMLen )
		{
		#ifdef SLC_TTS_LOG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("nPCMLen:%d, result:%d", nPCMLen, result);
		#endif
		#endif
		}
		kal_sleep_task(1);
		if ( g_ivTTS_cntx.status <= ivTTS_STATUS_SYNTHESIZING
			|| 0 == result 
			|| g_ivTTS_cntx.nMsg > 1 )
		{
		#ifdef SLC_TTS_LOG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("return 002 ivTTS_ERR_FAILED");
		#endif
		#endif
			return ivTTS_ERR_FAILED;
		}
	}

	return ivTTS_ERR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  NPR_TTSEngineOutputCB
 * DESCRIPTION
 *  Output call back of TTS application
 * PARAMETERS
 *  void
 * RETURNS
 *  If success, return ivTTS_ERR_OK,else return ivTTS_ERR_FAILED
 *****************************************************************************/
/* output callback */

//extern void Npr_Tts_pcm_log(void*PcmBuf,int size);

ivTTSErrID ivCall NPR_TTSEngineOutputCB(
						   ivPointer		pParameter,		/* [in] user callback parameter */
						   ivUInt16			nCode,			/* [in] output data code */
						   ivCPointer		pcData,			/* [in] output data buffer */
						   ivSize			nSize )			/* [in] output data size */
{
#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("status:%d, nSize:%d", g_ivTTS_cntx.status, nSize);
#endif
#endif
	if ( g_ivTTS_cntx.status < ivTTS_STATUS_SYNTHESIZING )
	{
	#ifdef SLC_TTS_LOG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return 001 ivTTS_ERR_FAILED");
	#endif
	#endif
		return ivTTS_ERR_FAILED;
	}
	else if ( g_ivTTS_cntx.nMsg > 1 )
	{
	#ifdef SLC_TTS_LOG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("return 002 ivTTS_ERR_FAILED");
	#endif
	#endif
		return ivTTS_ERR_FAILED;
	}

	if(0 == nSize )
	{
		//kal_sleep_task(0);
		return ivTTS_ERR_OK;
	}

	if( g_ivTTS_cntx.status == ivTTS_STATUS_SYNTHESIZING )
	{
		memcpy(&g_ivTTS_cntx.pTTS_Audio_Buff[g_ivTTS_cntx.nOutLen], pcData, nSize);
		g_ivTTS_cntx.nOutLen += nSize;

		/* 数据积攒够了，开始播音 */
		if ( g_ivTTS_cntx.nOutLen >= IV_TTS_PLAY_START_LEN )
		{
		#ifdef SLC_TTS_LOG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("TTS Data OK");
		#endif
		#endif
			g_ivTTS_cntx.status = ivTTS_STATUS_PLAYING;
		}
	}
	else
	{
		/* 送数据 */
	#ifdef SLC_TTS_LOG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("003");
	#endif
	#endif
		if ( NPR_TTS_SendData(pcData, nSize) != ivTTS_ERR_OK )
		{
		#ifdef SLC_TTS_LOG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("return 004 ivTTS_ERR_FAILED");
		#endif
		#endif	
			return ivTTS_ERR_FAILED;
		}
	}

	kal_sleep_task(IV_TTS_SLEEP_UNIT);
	return ivTTS_ERR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  NPR_TTSEngineReadResCB
 * DESCRIPTION
 *  read resource callback of TTS application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* read resource callback */
void ivCall NPR_TTSEngineReadResCB(ivPointer		pParameter,		/* [in] user callback parameter */
    ivPointer		pBuffer,		/* [out] read resource buffer */
    ivResAddress	iPos,			/* [in] read start position */
    ivResSize		nSize )			/* [in] read size */
{
	UINT size;
	FS_HANDLE pFile = (FS_HANDLE)pParameter;

	if(FS_Seek(pFile, iPos, FS_FILE_BEGIN) < 0)
	{
		longjmp(jmpbufTTS, 1);
	}
	if(FS_Read(pFile, pBuffer, nSize, &size) < 0)
	{
		longjmp(jmpbufTTS, 1);
	}
}

/*****************************************************************************
 * FUNCTION
 *  NPR_TTSEngineReadResMemCB
 * DESCRIPTION
 *  read resource callback of TTS application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* read resource callback */
void ivCall NPR_TTSEngineReadResMemCB(ivPointer		pParameter,		/* [in] user callback parameter */
					  ivPointer		pBuffer,		/* [out] read resource buffer */
					  ivResAddress	iPos,			/* [in] read start position */
					  ivResSize		nSize )			/* [in] read size */
{
	memcpy(pBuffer, (ivPByte)pParameter + iPos, nSize);
}

/*****************************************************************************
 * FUNCTION
 *  NPR_TTSEngineCreate
 * DESCRIPTION
 *  Create TTS application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* 创建TTS */
ivBool NPR_TTSEngineCreate_StepOne()
{
	FS_HANDLE pFile;
	UI_character_type path[50] = {0};

#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
	if ( g_ivTTS_cntx.status != ivTTS_STATUS_IDLE && g_ivTTS_cntx.nFlag == IV_TTS_FLAG )
		return TRUE;

	if (npr_temp_free == 0)
	{
		/* 分配空间 */
		g_ivTTS_cntx.pTTS_Audio_Buff = (U8*)IV_TTS_Alloc(IV_TTS_AUDIO_BUF_LEN);
		g_ivTTS_cntx.pHeap = (ivPByte)IV_TTS_Alloc(ivTTS_HEAP_SIZE);
		g_ivTTS_cntx.pText[0] = (ivPointer)IV_TTS_Alloc(512);
		g_ivTTS_cntx.nMaxTextBuff[0] = 512;
		g_ivTTS_cntx.pText[1] = (ivPointer)IV_TTS_Alloc(512);
		g_ivTTS_cntx.nMaxTextBuff[1] = 512;

		if ( ivNull == g_ivTTS_cntx.pTTS_Audio_Buff || ivNull == g_ivTTS_cntx.pHeap
		|| ivNull == g_ivTTS_cntx.pText[0] || ivNull == g_ivTTS_cntx.pText[1]
		)
		{
		#ifdef SLC_TTS_LOG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("return 001");
		#endif
		#endif
			NPR_TTSPlayer_EngineDestroy();
			return FALSE;
		}

	#ifdef SLC_TTS_LOG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("001");
	#endif
	#endif
		/* 初始化资源包 */
		memset(&g_ivTTS_tResPackDesc, 0, sizeof(g_ivTTS_tResPackDesc));

		NPR_TTSGetResPath((NPR_TTS_RES_PATH_TYPE)g_npr_tts_tone, path);

		pFile = FS_Open(path, FS_READ_ONLY);
		/* 配置文件系统中的资源包 */

	#ifdef SLC_TTS_LOG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("pFile:%d", pFile);
	#endif
	#endif
		if(pFile > FS_NO_ERROR)
		{
			g_ivTTS_tResPackDesc.pCBParam = (ivPointer)pFile;
			g_ivTTS_tResPackDesc.pfnRead = NPR_TTSEngineReadResCB;

			if ( g_TTS_ResFile.nCacheSize > 0 && g_TTS_ResFile.nCacheCount > 0 )
			{
				if (g_ivTTS_tResPackDesc.pCBParam)
				{
					g_ivTTS_tResPackDesc.pCacheBlockIndex = (ivPUInt8)IV_TTS_Alloc(g_TTS_ResFile.nCacheCount + 4);
					g_ivTTS_tResPackDesc.pCacheBuffer = (ivPUInt8)IV_TTS_Alloc((g_TTS_ResFile.nCacheCount + 4) * g_TTS_ResFile.nCacheSize);
					g_ivTTS_tResPackDesc.nCacheBlockSize = g_TTS_ResFile.nCacheSize;
					g_ivTTS_tResPackDesc.nCacheBlockCount = g_TTS_ResFile.nCacheCount;
					g_ivTTS_tResPackDesc.nCacheBlockExt = 4;
				}
				if ( 0 == g_ivTTS_tResPackDesc.pCacheBlockIndex || 0 == g_ivTTS_tResPackDesc.pCacheBuffer )
				{
				#ifdef SLC_TTS_LOG
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("return 002");
				#endif
				#endif
					NPR_TTSPlayer_EngineDestroy();
					return FALSE;
				}
			}
		}
	#ifdef __NPR_TTS_RES_IN_ROM__
		else if(1)
		{
		#ifdef SLC_TTS_LOG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("002");
		#endif
		#endif
			/* 配置ROM中的资源包 */
			g_ivTTS_tResPackDesc.pCBParam = (ivPointer)g_NPR_ResData;//(ivPointer)g_TTS_ResMem[0].pResAddr;
			g_ivTTS_tResPackDesc.pfnRead = NPR_TTSEngineReadResMemCB;
			g_ivTTS_tResPackDesc.pfnMap = 0;
			g_ivTTS_tResPackDesc.nSize = 0;

			if ( g_TTS_ResMem[0].nCacheCount > 0 && g_TTS_ResMem[0].nCacheSize > 255 )
			{
			#ifdef SLC_TTS_LOG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("003");
			#endif
			#endif
				g_ivTTS_tResPackDesc.pCacheBlockIndex = (ivPUInt8)IV_TTS_Alloc(g_TTS_ResMem[0].nCacheCount + 4);
				g_ivTTS_tResPackDesc.pCacheBuffer = (ivPUInt8)IV_TTS_Alloc((g_TTS_ResMem[0].nCacheCount + 4) * g_TTS_ResMem[0].nCacheSize);
				g_ivTTS_tResPackDesc.nCacheBlockSize = g_TTS_ResMem[0].nCacheSize;
				g_ivTTS_tResPackDesc.nCacheBlockCount = g_TTS_ResMem[0].nCacheCount;
				g_ivTTS_tResPackDesc.nCacheBlockExt = 4;

				if(0 == g_ivTTS_tResPackDesc.pCacheBlockIndex || 0 == g_ivTTS_tResPackDesc.pCacheBuffer )
				{
				#ifdef SLC_TTS_LOG
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("return 003");
				#endif
				#endif
					NPR_TTSPlayer_EngineDestroy();
					return FALSE;
				}
			}
		}
	#endif
		else
		{
		#ifdef SLC_TTS_LOG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("return 004");
		#endif
		#endif
			NPR_TTSPlayer_EngineDestroy();
			return FALSE;
		}
	}
#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("004");
#endif
#endif
	g_ivTTS_cntx.status = ivTTS_STATUS_INITIALIZED;
	//g_ivTTS_cntx.iTTSParam = 0;

	g_ivTTS_cntx.mhdl_handle = ivNull;
	g_ivTTS_cntx.nMsg = 0;
#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("005");
#endif
#endif
	g_ivTTS_cntx.iSuspend = 0;
	g_ivTTS_cntx.iTextSelect = 0;
	g_ivTTS_cntx.bOpenDevice = ivFalse;
	g_ivTTS_cntx.hTTS = 0;

#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("end");
#endif
#endif
	return TRUE;
}

ivBool NPR_TTSEngineCreate_StepTwo(void)
{
    ivTTSErrID ivTTSError = ivTTS_ERR_FAILED;
	
#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
    if ( g_ivTTS_cntx.hTTS )
        return TRUE;
    /* 创建 TTS 实例 */

#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("001");
#endif
#endif
    ivTTSError = ivTTS_Create(&g_ivTTS_cntx.hTTS, (ivPointer)g_ivTTS_cntx.pHeap, ivTTS_HEAP_SIZE, NULL, (ivPResPackDesc)&g_ivTTS_tResPackDesc, 1);
#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("ivTTSError:%d", ivTTSError);
#endif
#endif
    if (ivTTSError == ivTTS_ERR_OK)
    {
        /* 设置音频输出回调 */
        ivTTS_SetParam(g_ivTTS_cntx.hTTS, ivTTS_PARAM_OUTPUT_CALLBACK,
            (ivUInt32)NPR_TTSEngineOutputCB);

        /* 设置文本格式 */
        //默认UTF16
        if(ivTTS_PARAM_INPUT_CODEPAGE == g_ivTTS_cntx.iTTSParam) 
        {
            g_ivTTS_cntx.iTTSParam = 0;
            ivTTS_SetParam(g_ivTTS_cntx.hTTS, ivTTS_PARAM_INPUT_CODEPAGE, g_ivTTS_cntx.iCodePage);
        }
        else
        {
            g_ivTTS_cntx.iTTSParam = 0;
            g_ivTTS_cntx.iCodePage = ivTTS_CODEPAGE_UNICODE;
            ivTTS_SetParam(g_ivTTS_cntx.hTTS, ivTTS_PARAM_INPUT_CODEPAGE, ivTTS_CODEPAGE_UNICODE);
        }
        /* 设置语种 */
        ivTTS_SetParam(g_ivTTS_cntx.hTTS, ivTTS_PARAM_LANGUAGE, ivTTS_LANGUAGE_CHINESE);

        /* 设置音量 */
        ivTTS_SetParam(g_ivTTS_cntx.hTTS, ivTTS_PARAM_VOLUME, ivTTS_VOLUME_MAX);
 
        /* 设置发音人 */
        ivTTS_SetParam(g_ivTTS_cntx.hTTS, ivTTS_PARAM_ROLE, ivTTS_ROLE_YANPING);
   
        /* 设置发音风格 */
        ivTTS_SetParam(g_ivTTS_cntx.hTTS, ivTTS_PARAM_SPEAK_STYLE, ivTTS_STYLE_VIVID);
  
        /* 设置语调 */
        //ivTTS_SetParam(g_ivTTS_cntx.hTTS, ivTTS_PARAM_VOICE_PITCH, -2500);
        #ifndef IV_TTS_MEMORY_PREASSIGN
        {
            //设置参数
            int i;
            for(i = 0; i < g_ivTTS_cntx.set_param_time; ++i)
            {
                if(ivTTS_ERR_INVALID_PARAM_ID == ivTTS_SetParam(g_ivTTS_cntx.hTTS,
                    g_ivTTS_cntx.id_array[i], g_ivTTS_cntx.value_array[i]))
                {
                    //参数id非法，删除该id.value对，第i对得重新设置
                    NPR_TTSPlayer_Value_Delete(i);
                    i--;
                }
            }
        }		
        #endif

	#ifdef SLC_TTS_LOG  
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("TTS Create Success");
	#endif
	#endif
		return TRUE;
    }
	
#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("TTS Create Failed, ivTTSError:%d", ivTTSError);
#endif
#endif

    NPR_TTSPlayer_EngineDestroy();
    return FALSE;
}

ivBool NPR_TTSEngineCreate(void)
{
#ifdef IV_TTS_MEMORY_PREASSIGN
	if(FALSE == NPR_TTSEngineCreate_StepOne())
	{
		return FALSE;
	}
	return NPR_TTSEngineCreate_StepTwo();
#endif
	return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  NPR_TTSPlayer_EngineDestroy
 * DESCRIPTION
 *  Destroy of TTS application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* 销毁实例 */
void NPR_TTSPlayer_EngineDestroy(void)
{
#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif 
#endif
    if ( g_ivTTS_cntx.hTTS )
    {
        /* 如果没停止，先停止运行 */
        if (g_ivTTS_cntx.status > ivTTS_STATUS_INITIALIZED)
        {
            IFLYTEK_TTSEngineStop();
        }
        /* 逆初始化 */
        ivTTS_Destroy(g_ivTTS_cntx.hTTS);	
    }

    /* 释放空间 */
    if ( g_ivTTS_cntx.pTTS_Audio_Buff )
    {
        IV_TTS_Free((void**)&g_ivTTS_cntx.pTTS_Audio_Buff);
        g_ivTTS_cntx.pTTS_Audio_Buff = 0;
    }
    if (g_ivTTS_cntx.pHeap)
    {
        IV_TTS_Free((void**)&g_ivTTS_cntx.pHeap);
        g_ivTTS_cntx.pHeap = 0;
    }
    if ( g_ivTTS_cntx.pText[0] )
    {
        IV_TTS_Free((void**)&g_ivTTS_cntx.pText[0]);
        g_ivTTS_cntx.pText[0] = 0;
    }
    if ( g_ivTTS_cntx.pText[1] )
    {
        IV_TTS_Free((void**)&g_ivTTS_cntx.pText[1]);
        g_ivTTS_cntx.pText[1] = 0;
    }

    /* 释放资源包 */
    if ( g_ivTTS_tResPackDesc.pfnRead == NPR_TTSEngineReadResCB )
    {
        if ( g_ivTTS_tResPackDesc.pCBParam )
        {
            FS_Close((FS_HANDLE)g_ivTTS_tResPackDesc.pCBParam);
            g_ivTTS_tResPackDesc.pCBParam = 0;
        }
    }

    if ( g_ivTTS_tResPackDesc.pCacheBlockIndex )
    {
        IV_TTS_Free((void**)&g_ivTTS_tResPackDesc.pCacheBlockIndex);
        g_ivTTS_tResPackDesc.pCacheBlockIndex = 0;
    }
    if ( g_ivTTS_tResPackDesc.pCacheBuffer )
    {
        IV_TTS_Free((void**)&g_ivTTS_tResPackDesc.pCacheBuffer);
        g_ivTTS_tResPackDesc.pCacheBuffer = 0;
    }
	npr_temp_free = 0;
	npr_tts_digit_mod = NPR_TTS_DIGIT_DEFAULT_MODE;
    g_ivTTS_tResPackDesc.pfnRead = 0;
    g_ivTTS_tResPackDesc.nCacheBlockSize = 0;
    g_ivTTS_tResPackDesc.nCacheBlockCount = 0;
    g_ivTTS_tResPackDesc.nCacheBlockExt = 0;

    NPR_TTSPlayer_TTS_Init();
#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("001");
#endif
#endif
    g_ivTTS_cntx.status = ivTTS_STATUS_IDLE;
    g_ivTTS_cntx.hTTS = 0;

#ifdef SLC_TTS_LOG    
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("TTS Destroy Success");
#endif
#endif
}

void NPR_TTSPlayer_CheckRes(void)
{
    int iReadRes = FS_NO_ERROR;
    UINT size;
    UINT nRead;
    FS_HANDLE pFile;

    if (g_ivTTS_cntx.status > ivTTS_STATUS_IDLE && IV_TTS_FLAG == g_ivTTS_cntx.nFlag )
    {
        if ( g_ivTTS_tResPackDesc.pfnRead == NPR_TTSEngineReadResCB )
        {
       	#ifdef SLC_TTS_LOG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("001");
		#endif
		#endif
            pFile = (FS_HANDLE)g_ivTTS_tResPackDesc.pCBParam;
            FS_Seek(pFile, 0, FS_FILE_BEGIN);
            iReadRes = FS_Read(pFile, &nRead, sizeof(UINT), &size);
        }
	#ifdef SLC_TTS_LOG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("iReadRes:%d", iReadRes);
	#endif
	#endif
        if ( iReadRes != FS_NO_ERROR )
        {
            NPR_TTSPlayer_EngineDestroy();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  NPR_TTSPlayer_PlayTextA
 * DESCRIPTION
 *  PlayText ASCII code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* 合成文本 */
ivTTSErrID NPR_TTSPlayer_PlayTextA(ivCStrA pText)
{
	ivUInt8	i;
#if 0	
	//检查当前代码页
	if(g_ivTTS_cntx.iCodePage == ivTTS_CODEPAGE_UNICODE)
	{
		return ivTTS_ERR_FAILED;
	}	
#endif	
	if ( IV_TTS_FLAG != g_ivTTS_cntx.nFlag )
	{
		return ivTTS_ERR_FAILED; 
	}
	if(FALSE == NPR_TTSEngineCreate_StepOne())
	{
		return ivTTS_ERR_FAILED; 	
	}
	/* pText为NULL时停止 */
	if ( ivNull == pText )
	{
		IFLYTEK_TTSPlayer_Stop();
		return ivTTS_ERR_OK;
	}

#ifndef IV_TTS_MEMORY_PREASSIGN
	/*强制设置代码页*/
	if(0 == g_ivTTS_cntx.iTTSParam)
	{
		g_ivTTS_cntx.iTTSParam = ivTTS_PARAM_INPUT_CODEPAGE;
		g_ivTTS_cntx.iCodePage = ivTTS_CODEPAGE_GBK;
	}
#endif
	

	/* 把文本拷贝到全局结构体 */
	if ( 0 == g_ivTTS_cntx.nMsg )
		i = g_ivTTS_cntx.iTextSelect;
	else
		i = (g_ivTTS_cntx.iTextSelect + 1) & 0x01;

	g_ivTTS_cntx.nTextSize[i] = strlen((char*)pText);
	if ( g_ivTTS_cntx.nTextSize[i] > 10240 )
		g_ivTTS_cntx.nTextSize[i] = 10240;
	if ( g_ivTTS_cntx.nTextSize[i] > g_ivTTS_cntx.nMaxTextBuff[i] )
	{
		ivPointer pTemp = (ivPointer)IV_TTS_Alloc(g_ivTTS_cntx.nTextSize[i]);
		if ( pTemp )
		{
			IV_TTS_Free((void**)&g_ivTTS_cntx.pText[i]);
			g_ivTTS_cntx.pText[i] = pTemp;
			g_ivTTS_cntx.nMaxTextBuff[i] = g_ivTTS_cntx.nTextSize[i];
		}
		else
		{
			g_ivTTS_cntx.nTextSize[i] = g_ivTTS_cntx.nMaxTextBuff[i];
		}
	}

	memcpy(g_ivTTS_cntx.pText[i], pText, g_ivTTS_cntx.nTextSize[i]);

	if ( g_ivTTS_cntx.nMsg > 1 ) {
		return ivTTS_ERR_OK;
    }
	if ( g_ivTTS_cntx.status >= ivTTS_STATUS_SYNTHESIZING )
	{
		/* 发送合成文本的消息 */
		g_ivTTS_cntx.nMsg += 1;
	#ifdef SLC_TTS_LOG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("001");
	#endif
	#endif
		g_ivTTS_cntx.status = ivTTS_STATUS_SYNTHESIZING;
	#ifdef IV_TTS_Trace
		kal_prompt_trace(MOD_XDM, "NPR_Send_Msg_MMI_To_IVTTS, g_ivTTS_cntx.nMsg = %d", g_ivTTS_cntx.nMsg);
	#endif
		NPR_Send_Msg_MMI_To_IVTTS(IVTTS_TTSPLAYER_PLAYTEXT);
	}
	else
	{
		if ( !IV_TTS_Is_Background_Suspended())
		{
			NPR_TTS_Suspend_Background();
			g_ivTTS_cntx.iSuspend = 1;
		}
		NPR_TTSPlayer_Set_MMI_MsgCB(IVTTS_TTSPLAYER_MMI_STOP_TTS);
		g_ivTTS_cntx.nMsg += 1;
	#ifdef SLC_TTS_LOG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("002");
	#endif
	#endif
		g_ivTTS_cntx.status = ivTTS_STATUS_SYNTHESIZING;
	#ifdef IV_TTS_Trace
		kal_prompt_trace(MOD_XDM, "NPR_Send_Msg_MMI_To_IVTTS, g_ivTTS_cntx.nMsg = %d", g_ivTTS_cntx.nMsg);
	#endif
		IV_TTS_Sleep(10);
		NPR_TTS_Media_Play();
	}
	return ivTTS_ERR_OK;
}

 
/*****************************************************************************
 * FUNCTION
 *  NPR_TTSPlayer_PlayTextW
 * DESCRIPTION
 *  PlayText UNICODE
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* 合成文本 */
extern void mmi_ucm_play_waitingtone(void);
extern void NPR_TTS_IncomingCallCB(void *info);
ivTTSErrID NPR_TTSPlayer_PlayTextW(ivCStrW pText)
{
	ivUInt8	i;

#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
	/* pText为NULL时停止 */
	if (ivNull == pText)
	{
		return ivTTS_ERR_OK;
	}

	Npr_Tts_reset_status();

	if (!Npr_Tts_is_play_enable())
		return ivTTS_ERR_FAILED;

#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_ivTTS_cntx.nFlag:%d", g_ivTTS_cntx.nFlag);
#endif
#endif
	if (IV_TTS_FLAG != g_ivTTS_cntx.nFlag )
	{
		return ivTTS_ERR_SERVICE_LIMITED; 
	}
#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("001");
#endif
#endif
	if(!NPR_TTSEngineCreate_StepOne())
	{
		return ivTTS_ERR_FAILED; 	
	}
#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("002");
#endif
#endif
	NPR_TTSPlayer_SetParam(ivTTS_PARAM_INPUT_CODEPAGE, ivTTS_CODEPAGE_UNICODE);
	Npr_Tts_set_digit_param(npr_tts_digit_mod);
#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("003");
#endif
#endif
	/* 把文本拷贝到全局结构体 */
	//if (!g_ivTTS_cntx.hTTS )
	//	mmi_ucm_play_waitingtone();

	if ( 0 == g_ivTTS_cntx.nMsg )
		i = g_ivTTS_cntx.iTextSelect;
	else
		i = (g_ivTTS_cntx.iTextSelect + 1) & 0x01;

	g_ivTTS_cntx.nTextSize[i] = NPR_TTS_Get_UCStr_Len(pText) * 2;
	if (g_ivTTS_cntx.nTextSize[i] > 10240 )
		g_ivTTS_cntx.nTextSize[i] = 10240;

#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("004");
#endif
#endif
	if ( g_ivTTS_cntx.nTextSize[i] > g_ivTTS_cntx.nMaxTextBuff[i] )
	{
		ivPointer pTemp = (ivPointer)IV_TTS_Alloc(g_ivTTS_cntx.nTextSize[i]);
		if(pTemp)
		{
			IV_TTS_Free((void**)&g_ivTTS_cntx.pText[i]);
			g_ivTTS_cntx.pText[i] = pTemp;
			g_ivTTS_cntx.nMaxTextBuff[i] = g_ivTTS_cntx.nTextSize[i];
		}
		else
		{
			g_ivTTS_cntx.nTextSize[i] = g_ivTTS_cntx.nMaxTextBuff[i];
		}
	}

#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("005");
#endif
#endif
	memcpy(g_ivTTS_cntx.pText[i], pText, g_ivTTS_cntx.nTextSize[i]);
	if ( g_ivTTS_cntx.nMsg > 1 )
		return ivTTS_ERR_OK;

#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_ivTTS_cntx.status:%d, g_ivTTS_cntx.nMsg:%d", g_ivTTS_cntx.status, g_ivTTS_cntx.nMsg);
#endif
#endif
	if ( g_ivTTS_cntx.status >= ivTTS_STATUS_SYNTHESIZING )
	{
		/* 发送合成文本的消息 */
	#ifdef SLC_TTS_LOG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("006");
	#endif
	#endif

		g_ivTTS_cntx.nMsg += 1;
		g_ivTTS_cntx.status = ivTTS_STATUS_SYNTHESIZING;
		NPR_Send_Msg_MMI_To_IVTTS(IVTTS_TTSPLAYER_PLAYTEXT);
	}
	else
	{
	#ifdef SLC_TTS_LOG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("007");
	#endif
	#endif

		if ( !IV_TTS_Is_Background_Suspended())
		{
			NPR_TTS_Suspend_Background();
			g_ivTTS_cntx.iSuspend = 1;
		}
		NPR_TTSPlayer_Set_MMI_MsgCB(IVTTS_TTSPLAYER_MMI_STOP_TTS);
		g_ivTTS_cntx.nMsg += 1;
		g_ivTTS_cntx.status = ivTTS_STATUS_SYNTHESIZING;
		NPR_TTS_Media_Play();
	}

#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("end");
#endif
#endif
	return ivTTS_ERR_OK;
}

void NPR_TTS_PCM_ROLLOFF(void)
{
	short pRollOff[128];
	unsigned int nSample = 128;
	short nValue = 16384 - 128;
	int nTemp;
	short i = 0;

	if ( g_TTS_nLastSample < 128 && g_TTS_nLastSample > -128 )
		return;
	
	for ( i = 0; i < 128; ++ i )
	{
		nTemp = g_TTS_nLastSample * nValue;
		pRollOff[i] = (short)(nTemp >> 14);
		nValue -= 128;
	}

	IV_TTS_Sleep(1);
	NPR_pcm_push_data( pRollOff, &nSample);
	if ( nSample != 128 )
	{
		nSample = 128 - nSample;
		NPR_pcm_push_data( &pRollOff[128 - nSample], &nSample);
	}
}

void NPR_TTSPlayer_StopSlowly(void)
{
	NPR_TTSPlayer_PlayTextW((ivCStrW)" ");
}

void NPR_TTSEngine_PlayText(void)
{
#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
	NPR_TTSEngineCreate_StepTwo();

#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_ivTTS_cntx.status:%d", g_ivTTS_cntx.status);
#endif
#endif
	if ( g_ivTTS_cntx.status == ivTTS_STATUS_SYNTHESIZING )
	{
	#ifdef SLC_TTS_LOG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("001");
	#endif
	#endif
		/* 输出长度置零 */
		g_ivTTS_cntx.nOutLen = 0;

		/* 代码页变了 */
		if ( ivTTS_PARAM_INPUT_CODEPAGE == g_ivTTS_cntx.iTTSParam )
		{
			g_ivTTS_cntx.iTTSParam = 0;
			ivTTS_SetParam(g_ivTTS_cntx.hTTS, ivTTS_PARAM_INPUT_CODEPAGE, g_ivTTS_cntx.iCodePage);
		}

	#ifdef SLC_TTS_LOG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("002");
	#endif
	#endif
		/* 内核开始合成 */
		if ( 1 == g_ivTTS_cntx.nMsg )
		{
			int nJumpValue = setjmp(jmpbufTTS);
			int error = -100;
			
		#ifdef SLC_TTS_LOG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("nJumpValue:%d", nJumpValue);
		#endif
		#endif
			g_TTS_nLastSample = 0;
			if(nJumpValue == 0)
			{
				error = ivTTS_SynthText(g_ivTTS_cntx.hTTS, 
				g_ivTTS_cntx.pText[g_ivTTS_cntx.iTextSelect], g_ivTTS_cntx.nTextSize[g_ivTTS_cntx.iTextSelect]);
			#ifdef SLC_TTS_LOG	 
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("error:%d, g_ivTTS_cntx.status:%d", error, g_ivTTS_cntx.status);
			#endif
			#endif
				if(ivTTS_STATUS_PLAYING == g_ivTTS_cntx.status)
					NPR_TTS_SendData(ivNull,0); /* 强制输出剩余数据 */
			}
			NPR_TTS_PCM_ROLLOFF();
		}
		else
		{
			g_ivTTS_cntx.iTextSelect = (g_ivTTS_cntx.iTextSelect + 1) & 0x01;
			g_ivTTS_cntx.nMsg -= 1;
			return;
		}

		/* 看是否被中途停止 */
		if ( g_ivTTS_cntx.status > ivTTS_STATUS_SYNTHESIZING )
		{
			int nSleep = 0;
			g_ivTTS_cntx.status = ivTTS_STATUS_SYNTHESIZED;
			/* 等待播音播完缓冲区 */
			while ( g_ivTTS_cntx.status != ivTTS_STATUS_PALYEND )
			{
				/* 看是否被中途停止 */
				IV_TTS_Sleep(5);
				nSleep += 5;
				if ( g_ivTTS_cntx.status <= ivTTS_STATUS_SYNTHESIZING )
				{
					break;
				}
				if (nSleep > 1000)
				{
					g_ivTTS_cntx.status = ivTTS_STATUS_PALYEND;
					break;
				}
				IFLYTEK_TTSCheckBuffer();
			}
			if ( ivTTS_STATUS_PALYEND  == g_ivTTS_cntx.status )
				IV_TTS_Sleep(25);
		#if 1	
			if ( g_ivTTS_cntx.status > ivTTS_STATUS_SYNTHESIZING )
				g_ivTTS_cntx.status = ivTTS_STATUS_SYNTHESIZING;
		#endif
		}
	}

#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_ivTTS_cntx.status:%d", g_ivTTS_cntx.status);
#endif
#endif
	g_ivTTS_cntx.iTextSelect = (g_ivTTS_cntx.iTextSelect + 1) & 0x01;
	g_ivTTS_cntx.nMsg -= 1;


#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_ivTTS_cntx.nMsg:%d", g_ivTTS_cntx.nMsg);
#endif
#endif
	/* 发送关闭TTS的消息 */
	NPR_TTSPlayer_Send_Msg_To_MMI(IVTTS_TTSPLAYER_MMI_STOP_TTS);
#if 1
	if( g_ivTTS_cntx.status != ivTTS_STATUS_INITIALIZED && 0 == g_ivTTS_cntx.nMsg )
		IV_TTS_Sleep(10);
#endif	
}

/*****************************************************************************
 * FUNCTION
 *  NPR_TTSPlayer_SetParam
 * DESCRIPTION
 *  Setting of TTS application
 * PARAMETERS
 *  nParamID
 *  nParamValue
 * RETURNS
 *  void
 *****************************************************************************/
/* 设置参数 */
ivTTSErrID NPR_TTSPlayer_SetParam(ivUInt32 nParamID,  ivUInt32 nParamValue)
{
	if ( IV_TTS_FLAG != g_ivTTS_cntx.nFlag )
	{
		return ivTTS_ERR_FAILED; 
	}
#ifdef IV_TTS_MEMORY_PREASSIGN	//预分配
	/* 设置代码页只在IFLYTEK_TTSEngine_PlayText中生效 */
	if (ivTTS_PARAM_INPUT_CODEPAGE == nParamID )
	{
		g_ivTTS_cntx.iTTSParam = ivTTS_PARAM_INPUT_CODEPAGE;
		g_ivTTS_cntx.iCodePage = nParamValue;
		g_ivTTS_cntx.iResult = ivTTS_ERR_OK;
	}

	if ( ivTTS_PARAM_VOLUME == nParamID )
	{
		g_ivTTS_cntx.iResult = ivTTS_ERR_OK;
	}
	else
	{

		g_ivTTS_cntx.iResult = IFLYTEK_TTSEngineSetParam(nParamID,  nParamValue);

	}
#else
	//代码页参数（引擎只有播放和未创建两种状态）
	if(ivTTS_PARAM_INPUT_CODEPAGE == nParamID)
	{
		g_ivTTS_cntx.iTTSParam = ivTTS_PARAM_INPUT_CODEPAGE;
		g_ivTTS_cntx.iCodePage = nParamValue;
	}	
	//音量参数
	else if ( ivTTS_PARAM_VOLUME == nParamID )
	{
		g_ivTTS_cntx.iResult = ivTTS_ERR_OK;
	}
	//其他参数
	else
	{
		//强制设置一次，不管是播放过程中还是引擎未创建
		IFLYTEK_TTSEngineSetParam(nParamID,  nParamValue);
		NPR_TTSPlayer_Value_PushArray(nParamID,nParamValue);
	}
	g_ivTTS_cntx.iResult = ivTTS_ERR_OK;
#endif
	return g_ivTTS_cntx.iResult;
}

/****************************************************************************
* add by cxchen
*
* Description: get imei for net  validation.
*
* Date :Nov 10 2010

****************************************************************************/

BOOL NPR_TTSPlayer_IsRun(void)
{
	if( (g_ivTTS_cntx.status >= ivTTS_STATUS_PLAYING))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int JD_PUB_GetTtsInitTimerId(void) 
{ 
	return TIMER_NPR_TTS_NET_INIT; 
} 

int Npr_Tts_GetTtsInitTimerId(void) 
{ 
	return TIMER_NPR_TTS_NET_INIT1; 
} 


void Npr_Tts_set_vol_lev(char lev)
{
    g_tts_vol_lev = lev;
        if(6 < g_tts_vol_lev  )
           g_tts_vol_lev  = 6;
}

U8 tts_silent = 0;
void Npr_Ttsplay_set_play_flag(U8 status)
{
	tts_silent = status;
}

U8 Npr_Ttsplay_get_play_flag(void)
{
	return tts_silent;
}

int Npr_Ttsplayer_playtextw(char* pszText,void (*end_call)(void*info))
{
	int err;
	char gbString[1024] = {0};

#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
	mmi_chset_ucs2_to_text_str((kal_uint8*)gbString, sizeof(gbString), (kal_uint8 *)pszText, GB2312_ENCODING_TYPE);
	Npr_Tts_end_cb = end_call;
	err = NPR_TTSPlayer_PlayTextW((ivCStrW)pszText);
	return err;
}


char Npr_Tts_is_playing(void)
{
	iv_tts_is_playing();
}

extern BOOL Npr_Tts_read_need(void);
static char Npr_Tts_is_play_enable(void)
{
	if ( 
		/*提供接口给客户，客户可以自定义那些情况不朗读*/
		#if 1
			!Npr_Tts_read_need()
		#endif
	)
		return 0;

	return 1;
}
extern void iv_pcm_stop_req_hdlr(void);
void Npr_Tts_stop_immediately(void)
{
IFLYTEK_TTSPlayer_Stop();
kal_sleep_task(30);
}
void Npr_Tts_reset_status(void)
{
IFLYTEK_TTSPlayer_Stop();
kal_sleep_task(30);
}

void Npr_Tts_play_stop(void)
{
	mdi_audio_stop_all();
	Npr_Tts_stop_immediately();
}

////TTS 资源处理部分
void NPR_TTSGetResPath(NPR_TTS_RES_PATH_TYPE path_type, UI_character_type path[])
{
	U32 drive = (S8) FS_GetDrive(FS_DRIVE_I_SYSTEM, 2, FS_DRIVE_I_SYSTEM|FS_DRIVE_V_NORMAL);  //xuhongfu
	char tmp[50] = {0};

#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
    switch(path_type) 
    {
    #ifdef __NPR_DIALECT_TTS_
        case NPR_TTS_RES_PATH_FEMALE:
            kal_wsprintf(path, "%c:\\%s%s", drive, NPR_RES_FEMALE_DIR, NPR_RES_TTS);
            break;
        case NPR_TTS_RES_PATH_GD:
            kal_wsprintf(path, "%c:\\%s%s", drive, NPR_RES_GD_DIR, NPR_RES_TTS);
            break;
        case NPR_TTS_RES_PATH_SC:
            kal_wsprintf(path, "%c:\\%s%s", drive, NPR_RES_SC_DIR, NPR_RES_TTS);
            break;
        case NPR_TTS_RES_PATH_DB:
            kal_wsprintf(path, "%c:\\%s%s", drive, NPR_RES_DB_DIR, NPR_RES_TTS);
            break;
        case NPR_TTS_RES_PATH_MALE:
            kal_wsprintf(path, "%c:\\%s%s", drive, NPR_RES_MALE_DIR, NPR_RES_TTS);
            break;
        case NPR_TTS_RES_PATH_CHILD:
            kal_wsprintf(path, "%c:\\%s%s", drive, NPR_RES_CHILD_DIR, NPR_RES_TTS);
            break;
	#else
	    case NPR_TTS_RES_PATH_BZ:
            kal_wsprintf(path, "%c:\\%s%s", drive, NPR_RES_DIR, NPR_RES_TTS);
            break;
	#endif
    	    case NPR_TTS_RES_PATH_TTSCODE:
    	    kal_wsprintf(path, "%c:\\%s%s", drive, NPR_RES_DIR, NPR_RES_TTS_CODE);
    	    break;
        case NPR_TTS_RES_PATH_IVESR:
            kal_wsprintf(path, "%c:\\%s%s", drive, NPR_RES_DIR, NPR_RES_IVESR);
		    break;
        case NPR_TTS_RES_PATH_ESRCODE:
            kal_wsprintf(path, "%c:\\%s%s", drive, NPR_RES_DIR, NPR_RES_IVESR_CODE);
	     break;
	  default:
	    ASSERT(0);
    }

#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("end");
#endif
#endif
}

U8 NPR_Check_Res_File(void)
{
	U8 ret = 0;
	UI_character_type path[64] = {0};
	FS_HANDLE pFile = FS_NO_ERROR;
	NPR_TTS_RES_PATH_TYPE restypes[4] = {
			#ifndef __NPR_DIALECT_TTS_
				NPR_TTS_RES_PATH_BZ,
			#else
			#endif
				NPR_TTS_RES_PATH_IVESR, 
				NPR_TTS_RES_PATH_TTSCODE,
				NPR_TTS_RES_PATH_ESRCODE
	};
	NRP_RES_FILE_FLAG status[] = {NRP_RES_FILE_TTS_RES_LOST, NRP_RES_FILE_ESR_RES_LOST, NRP_RES_FILE_TTS_NPR_LOST, NRP_RES_FILE_ESR_NPR_LOST};
	U8 i = 0;

#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
#ifdef __NPR_TTS_RES_IN_ROM__
	return 0;
#endif
	for(; i < 4; i++)
	{
#ifndef __NPR_SIRI_TTS__
	if (restypes[i] == NPR_TTS_RES_PATH_IVESR)
		continue;
#endif
#ifndef __NPR_TTS_VLOAD__
	if (restypes[i] == NPR_TTS_RES_PATH_TTSCODE)
	continue;
#endif
#ifndef __NPR_AITALK_LOAD__
	if (restypes[i] == NPR_TTS_RES_PATH_ESRCODE)
	continue;
#endif

	NPR_TTSGetResPath(restypes[i], path);

	pFile = FS_Open(path, FS_READ_ONLY);
	if (pFile >= FS_NO_ERROR)
	{
	FS_Close(pFile);
	}
	else
	{
	ret |= status[i];
	}			
	}
#ifdef SLC_TTS_LOG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("ret:%d", ret);
#endif
#endif
	return ret;
}
void Npr_Tts_set_digit_read_mod(char mod)
{
	npr_tts_digit_mod = mod;
	if (npr_tts_digit_mod >2)
		npr_tts_digit_mod = NPR_TTS_DIGIT_DEFAULT_MODE;
}
void Npr_Tts_set_digit_param(char mod)
{
	if(mod == 1)
	{
		NPR_TTSPlayer_SetParam(ivTTS_PARAM_READ_DIGIT, ivTTS_READDIGIT_AUTO);
	}
	else if(mod == 0)
	{
  		NPR_TTSPlayer_SetParam(ivTTS_PARAM_READ_DIGIT, ivTTS_READDIGIT_AS_NUMBER);
             NPR_TTSPlayer_SetParam(ivTTS_PARAM_CHINESE_NUMBER_1, ivTTS_CHNUM1_READ_YI);
	}
	else if(mod == 2)
	{
		NPR_TTSPlayer_SetParam(ivTTS_PARAM_READ_DIGIT, ivTTS_READDIGIT_AS_NUMBER);
             NPR_TTSPlayer_SetParam(ivTTS_PARAM_CHINESE_NUMBER_1, ivTTS_CHNUM1_READ_YAO);
	}
}

////////////

#endif

