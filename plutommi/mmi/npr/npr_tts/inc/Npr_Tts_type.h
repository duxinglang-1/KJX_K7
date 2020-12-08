#ifndef NPR_TTS_TYPE__H
#define NPR_TTS_TYPE__H
#include "mmi_features.h"
#ifdef __NPR_TTS__
#include "NPR_ivTTS.h"
#ifndef IV_TTS_MEMORY_PREASSIGN
#define ivMaxSetParamClass 20
#endif

#ifdef __NPR_BASE2_SUPPORT__
#include "jd_base_types.h"
#else
typedef unsigned char			jdU8;
typedef char					jdCHAR;
typedef unsigned short			jdU16;
typedef unsigned short			jdWCHAR;
typedef unsigned int			jdUINT;
typedef unsigned int			jdU32;
typedef void					jdVOID;

typedef signed char				jdI8;
typedef signed short int		jdI16;
typedef int						jdINT;
typedef signed int				jdI32;
typedef unsigned long			jdU64;
typedef signed long				jdI64;

#ifdef WIN32
	typedef unsigned __int64	jdU128;
	typedef __int64				jdI128;
#else
	typedef unsigned long long	jdU128;
	typedef long long			jdI128;
#endif
typedef enum {
	jdFALSE = 0,
	jdTRUE = 1
} jdBOOL;
typedef int jdFILE;

#ifndef NULL
#define NULL					0
#endif


#define PUBLIC
#define LOCAL					static

#endif

typedef void* (*jt_pvNPREntry)(void*);

void* JT_pvLoadTTSNPR(jdBOOL bLoad, void *pvData);
#if 1
typedef enum {
	ivTTS_STATUS_IDLE,			// 无效
	ivTTS_STATUS_INITIALIZED,	// 初始化完毕
	ivTTS_STATUS_PAUSE,			// 暂停
	ivTTS_STATUS_SYNTHESIZING,	// 正在合成
	ivTTS_STATUS_PLAYING,		// 正在播音
	ivTTS_STATUS_SYNTHESIZED,	// 合成完毕
	ivTTS_STATUS_PALYEND		// 播音完毕
} ivTTS_status;

typedef struct {
	ivHTTS				hTTS;			/* TTS内核实例句柄 */
	ivPByte				pHeap;			/* TTS内核实例堆 */
	ivTTS_status		status;			/* TTS Player 运行状态 */
	ivTTS_status		last_status;	/* TTS Player 暂停前的状态 */
	jdU32 				nOutLen;		/* 输出PCM长度统计，用于计算何时开始播音 */
	jdU32 				nFlag;			/* 标识，用于判断TTS Service是否开启 */
	jdU8				bOpenDevice;		/* 表示TTS内核实例控制权 */
	ivTTSErrID			iResult;		/* 错误码 */
	ivUInt8				iTextSelect;	/* 文本选择 */
	ivPointer			pText[2];			/* 需要合成的文本 */
	ivUInt32			nTextSize[2];		/* 合成文本大小 */
	ivUInt32			nMaxTextBuff[2];	/* 文本缓冲区大小 */

	jdU8				*pTTS_Audio_Buff;
	ivUInt32			iTTSParam;
	ivUInt32			iCodePage;
	ivUInt8				nMsg;
	ivUInt8				iSuspend;
	void *mhdl_handle; // MHdl
#ifndef IV_TTS_MEMORY_PREASSIGN
	ivUInt32			id_array[ivMaxSetParamClass];
	ivUInt32            value_array[ivMaxSetParamClass];
	ivUInt8				set_param_time;
#endif	
}ivTTS_cntx_struct;
#endif
#endif
#endif 
