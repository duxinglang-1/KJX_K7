/**********************************************************************
*	FileName	：IV_TTSPlayer.h
*	Description	：
*	Author		：jhlv
*	Create Date	：2008-6-24
*	Project		：TTS PLAYER
*	Platform	：MTK6223,MTK 6235,MTK 6225,MTK 6226
*---------------------------------------------------------------------*
*	History：
*	NO.		Data		Author		Remark
**********************************************************************/
#ifndef IFLYTEK_VOICE_TTS_MTK6226_H
#define IFLYTEK_VOICE_TTS_MTK6226_H
#ifdef __NPR_TTS__
#include "NPR_ivTTS.h"

/*  线程挂起的单位时间 */
#define	IV_TTS_SLEEP_UNIT	1

/*播音缓冲区大小，必须大于4000，单位byte*/
#define	IV_TTS_AUDIO_BUF_SIZE	(16384)

/*初始缓冲数据量（存够这么多就打开播音），必须小于IV_TTS_AUDIO_BUF_SIZE，单位byte */
#define	IV_TTS_PLAYSTART_SIZE		(4000)

//TTS资源路径
#define NPR_RES_DIR "TTS\\"

#ifdef __NPR_DIALECT_TTS_
#define NPR_RES_FEMALE_DIR "TTS\\female\\"
#define NPR_RES_GD_DIR "TTS\\gd\\"
#define NPR_RES_SC_DIR "TTS\\sc\\"
#define NPR_RES_DB_DIR "TTS\\db\\"
#define NPR_RES_MALE_DIR "TTS\\male\\"
#define NPR_RES_CHILD_DIR "TTS\\child\\"
#endif
#define NPR_RES_IVESR "esr_res.irf"
#define NPR_RES_TTS "tts_res.irf"
#define NPR_RES_IVESR_CODE  "npr_esr.npr"  //"npr_esr.npr"  //"aitalk.npr"
#define NPR_RES_TTS_CODE "npr_tts.npr"  //"tts.npr"

typedef enum{
    NRP_RES_FILE_INIT_FLAG, //无任何资源文件
    NRP_RES_FILE_TTS_RES_LOST = 0X01,
    NRP_RES_FILE_ESR_RES_LOST = 0X02,
    NRP_RES_FILE_TTS_NPR_LOST = 0X04,
    NRP_RES_FILE_ESR_NPR_LOST = 0X08,
    NRP_RES_FILE_MAX_FLAG
}NRP_RES_FILE_FLAG;

typedef enum 
{
#ifdef __NPR_DIALECT_TTS_
    NPR_TTS_RES_PATH_FEMALE,
    NPR_TTS_RES_PATH_GD,
    NPR_TTS_RES_PATH_SC,
    NPR_TTS_RES_PATH_DB,
    NPR_TTS_RES_PATH_MALE,
    NPR_TTS_RES_PATH_CHILD,
#else
    NPR_TTS_RES_PATH_BZ,
#endif
    NPR_TTS_RES_PATH_TTSCODE,
    NPR_TTS_RES_PATH_IVESR,
    NPR_TTS_RES_PATH_ESRCODE,
}NPR_TTS_RES_PATH_TYPE;

/* 引擎堆 */
#define ivTTS_HEAP_SIZE (38<<10)	/* 发包时设定，用户不可更改 */

/* TTS Player 消息ID */
typedef enum
{
	IVTTS_TTSPLAYER_SERVICEOPEN,
	IVTTS_TTSPLAYER_SERVICECLOSE,
	IVTTS_TTSPLAYER_PLAYTEXT,
	IVTTS_TTSPLAYER_STARTSYN,
	IVTTS_TTSPLAYER_SYNEND,
	IVTTS_TTSPLAYER_MMI_START_TTS,
	IVTTS_TTSPLAYER_MMI_STOP_TTS,
	IVTTS_TTSPLAYER_NULL
}ivTTS_Msgs;

/* 资源为16K */
/*#define  IFLYTEK_TTS_16K*/	/* 发包时设定，用户不可更改 */

/*#define IV_TTS_MEMORY_PREASSIGN*/  /* 发包时设定，用户不可更改 */
/* 设置参数 */
extern ivTTSErrID NPR_TTSPlayer_SetParam(ivUInt32 nParamID,  ivUInt32 nParamValue);

/* 合成文本 */
extern ivTTSErrID NPR_TTSPlayer_PlayTextA(ivCStrA pText);

/* 合成文本 */
extern ivTTSErrID NPR_TTSPlayer_PlayTextW(ivCStrW pText);

/* 停止 */
extern void IFLYTEK_TTSPlayer_Stop(void);

/* 检查TTS是否正在运行 */
extern ivBool IFLYTEK_TTSPlayer_IsPlaying(void);



//extern ivTTSErrID NPR_TTSPlayer_PlayTextW_nTimes(ivCStrW pText,ivUInt32 nTimes);


/* 开启TTS，默认开机自动打开，不需要调用此函数 */
extern ivTTSErrID IFLYTEK_TTSPlayer_ServiceOpen(void);

/* 关闭TTS，释放内存，释放文件句柄。 */
extern void IFLYTEK_TTSPlayer_ServiceClose(void);

/* 缓慢地停止，防止快速停止产生的喀吧声 */
extern void NPR_TTSPlayer_StopSlowly(void);

extern ivBool NPR_TTSEngineCreate(void);
#endif /* IFLYTEK_VOICE_TTS_MTK6226_H */
#endif
