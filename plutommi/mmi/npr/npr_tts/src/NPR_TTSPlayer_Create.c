/**********************************************************************
*	FileName	：IV_TTSPlayer_Create.c
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
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "task_main_func.h"
#include "app_ltlcom.h"
#include "lcd_ip_cqueue.h"
#include "stack_types.h"
#include "task_config.h"
#include "syscomp_config.h"
#include "custom_config.h"
#include "custom_util.h"
//#include "stack_init.h"
#include "stack_ltlcom.h"

#include "NPR_TTSPlayer.h"

//#include "../../../../../../ggt/inc/GGT_utility.h" //xuhongfu

 //#define IV_TTS_TEST 
 
/*************************************************************************
* Function declaration
 *************************************************************************/
static void NPR_TTSPlayer_main(task_entry_struct * task_entry_ptr);
/*************************************************************************
* FUNCTION
*  NPR_TTSPlayer_Create
*
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
NPR_TTSPlayer_Create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct iflytek_tts_handler_info =
   {
      NPR_TTSPlayer_main,  /* task entry function */
      NULL,  /* task initialization function */
      NULL,  /* task configuration function */
      NULL,  /* task reset handler */
      NULL,  /* task termination handler */
   };

   *handle = (comptask_handler_struct *)&iflytek_tts_handler_info;
   return KAL_TRUE;
}

void NPR_TTSPlayer_SendMessageTTS2MMI(msg_type nMsgID)
{
   ilm_struct *send_ilm;

   send_ilm = allocate_ilm(MOD_IVTTS);
   send_ilm->src_mod_id = MOD_IVTTS;
   send_ilm->dest_mod_id = MOD_MMI;
   send_ilm->msg_id = nMsgID;

   msg_send_ext_queue(send_ilm);
}

extern ivBool NPR_TTSEngineCreate(void);
extern void NPR_TTSEngine_PlayText(void);
extern void NPR_TTSPlayer_EngineDestroy(void);
extern void IV_TTS_Sleep( unsigned long nTime );
extern void NPR_TTSPlayer_CheckRes(void);
void NPR_TTSPlayer_Set_MMI_MsgCB(unsigned char iMsg);
extern void NPR_TTSPlayer_TTS_Init(void);


void NPR_TTSPlayer_TestCB(void *info)
{

//GT_TRACE("NPR_TTSPlayer_TestCB AAAA");   //xuhongfu

#ifdef IV_TTS_TEST
/*
	NPR_TTSPlayer_SetParam(ivTTS_PARAM_INPUT_CODEPAGE, ivTTS_CODEPAGE_GBK);
	NPR_TTSPlayer_PlayTextA((ivCStrA)"你好，这里是科大讯飞语音合成系统。Hello, this is iFLYTEK TTS system.");
*/
	NPR_TTSPlayer_PlayTextW((ivCStrW)"\x60\x4F\x7D\x59\x0C\xFF\xD9\x8F\xCC\x91\x2F\x66\xD1\x79\
\x27\x59\xAF\x8B\xDE\x98\xED\x8B\xF3\x97\x08\x54\x10\x62\xFB\x7C\
\xDF\x7E\x02\x30\x48\x00\x65\x00\x6C\x00\x6C\x00\x6F\x00\x2C\x00\
\x20\x00\x74\x00\x68\x00\x69\x00\x73\x00\x20\x00\x69\x00\x73\x00\
\x20\x00\x69\x00\x46\x00\x4C\x00\x59\x00\x54\x00\x45\x00\x4B\x00\
\x20\x00\x54\x00\x54\x00\x53\x00\x20\x00\x73\x00\x79\x00\x73\x00\
\x74\x00\x65\x00\x6D\x00\x2E\x00\x00\x00");
#endif

//GT_TRACE("NPR_TTSPlayer_TestCB BBBB");   //xuhongfu

}

static void
NPR_TTSPlayer_main(task_entry_struct * task_entry_ptr)
{
	ilm_struct current_ilm;

	/* 打开TTS_Service */
	kal_sleep_task(1000);
	NPR_TTSPlayer_TTS_Init();
	NPR_TTSEngineCreate();
	//mmi_ucm_play_incoming_tone();
 
#ifdef IV_TTS_TEST
	kal_sleep_task(4000);
	NPR_TTSPlayer_Set_MMI_MsgCB(/*IVTTS_TTSPLAYER_MMI_START_TTS*/ 5);
	NPR_TTSPlayer_SendMessageTTS2MMI(MSG_ID_TTSPLAYER_MMI_START_TTS);
#endif

	while ( 1 )
	{
		receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);

		switch (current_ilm.msg_id)
		{
			case MSG_ID_TTSPLAYER_SERVICEOPEN:
				NPR_TTSPlayer_CheckRes();
				NPR_TTSEngineCreate();
				break;
			case MSG_ID_TTSPLAYER_SERVICECLOSE:
				//GT_TRACE("EngineDestroy line=%d",__LINE__);
				NPR_TTSPlayer_EngineDestroy();
				break;
			case MSG_ID_TTSPLAYER_PLAYTEXT:
				NPR_TTSPlayer_CheckRes();
				NPR_TTSEngine_PlayText();
				break;
			default:
				break;
		}

		free_ilm(&current_ilm);
	}

}
#endif
