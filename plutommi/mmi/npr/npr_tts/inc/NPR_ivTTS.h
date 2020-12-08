/*--------------------------------------------------------------+
 |																|
 |	ivTTS.h - AiSound 4 Kernel API	            				|
 |																|
 |		Copyright (c) 1999-2008, ANHUI USTC iFLYTEK CO.,LTD.	|
 |		All rights reserved.									|
 |																|
 +--------------------------------------------------------------*/

#ifndef IFLYTEK_VOICE__TTS__H
#define IFLYTEK_VOICE__TTS__H
#ifdef __NPR_TTS__

#include "NPR_ivDefine.h"

//#define SLC_TTS_LOG

#ifdef __cplusplus
extern "C" {
#endif


/*
 *	COMMON DEFINES
 */

typedef ivUInt16 ivTTSErrID;
typedef ivPointer ivHTTS;


/*
 *	FUNCTION ENTRIES
 */

/* get SDK version */
ivTTSErrID ivCall ivTTS_GetVersion(
	ivPUInt8		piMajor,			/* [out] major version number */
	ivPUInt8		piMinor,			/* [out] minor version number */
	ivPUInt16		piRevision);		/* [out] revision number */

/* create an instance */
ivTTSErrID ivCall ivTTS_Create(
	ivHTTS ivPtr	phTTS,				/* [out] handle to an instance */
	ivPointer		pHeap,				/* [in] heap for instance */
	ivSize			nHeapSize,			/* [in] size of the heap */
	ivPointer		pCBParam,			/* [in] user callback parameter */
	ivPResPackDesc	pResPackDesc,		/* [in] resource pack description array */
	ivSize			nResPackCount);		/* [in] resource pack count */

/* get a parameter associated with an instance */
ivTTSErrID ivCall ivTTS_GetParam(
	ivHTTS			hTTS,				/* [in] handle to an instance */
	ivUInt32		nParamID,			/* [in] parameter ID */
	ivPUInt32		pnParamValue );		/* [out] buffer to receive the parameter value */

/* set a parameter associated with an instance */
ivTTSErrID ivCall ivTTS_SetParam(
	ivHTTS			hTTS,				/* [in] handle to an instance */
	ivUInt32		nParamID,			/* [in] parameter ID */
	ivUInt32		nParamValue );		/* [in] parameter value */

/* get pcm data */
ivTTSErrID ivCall ivTTS_GetData(
	ivHTTS			hTTS,				/* [in] handle to an instance */
	ivPointer		pData,				/* [in] pointer of pcm data buffer */
	ivSize ivPtr	pSize );			/* [in/out] data size */

/* exit running of an instance and leave current thread's control */
ivTTSErrID ivCall ivTTS_Exit(
	ivHTTS			hTTS );				/* [in] handle to an instance */

/* synthesize a buffer of text on an instance */
ivTTSErrID ivCall ivTTS_SynthText(
	ivHTTS			hTTS,				/* [in] handle to an instance */
	ivCPointer		pcData,				/* [in] pointer of text buffer data to be synthesized */
	ivSize			nSize );			/* [in] size of text buffer data to be synthesized */


/*
 *	ERROR CODES
 */

#define ivTTS_ERR_OK					0x0000					/* success */
#define ivTTS_ERR_FAILED				0xFFFF					/* failed */
#define ivTTS_ERR_SERVICE_LIMITED		0xFFFE					/* service limited */

#define ivTTS_STATE_BASE				0x0100					/* state base */

#define ivTTS_STATE_INVALID_DATA		ivTTS_STATE_BASE + 2	/* invalid data */
#define ivTTS_STATE_TTS_STOP			ivTTS_STATE_BASE + 3	/* TTS stop */


#define ivTTS_ERR_BASE					0x8000					/* error number base */

#define ivTTS_ERR_UNIMPEMENTED			ivTTS_ERR_BASE + 0		/* unimplemented function */
#define ivTTS_ERR_UNSUPPORTED			ivTTS_ERR_BASE + 1		/* unsupported on this platform */
#define ivTTS_ERR_INVALID_HANDLE		ivTTS_ERR_BASE + 2		/* invalid handle */
#define ivTTS_ERR_INVALID_PARAMETER		ivTTS_ERR_BASE + 3		/* invalid parameter(s) */
#define ivTTS_ERR_INSUFFICIENT_HEAP		ivTTS_ERR_BASE + 4		/* insufficient heap size  */
#define ivTTS_ERR_STATE_REFUSE			ivTTS_ERR_BASE + 5		/* refuse to do in current state  */
#define ivTTS_ERR_INVALID_PARAM_ID		ivTTS_ERR_BASE + 6		/* invalid parameter ID */
#define ivTTS_ERR_INVALID_PARAM_VALUE	ivTTS_ERR_BASE + 7		/* invalid parameter value */
#define ivTTS_ERR_SIZE_EXCEED_BUFFER	ivTTS_ERR_BASE + 8		/* get data size exceed the data buffer */
#define ivTTS_ERR_END_OF_INPUT			ivTTS_ERR_BASE + 9		/* end of input stream */
#define ivTTS_ERR_RESOURCE				ivTTS_ERR_BASE + 10		/* Resource is error */



/*
 *	INSTANCE PARAMETERS
 */

/* constants for values of field nParamID */
#define ivTTS_PARAM_PARAMCH_CALLBACK	0x00000000	/* parameter change callback entry */
#define ivTTS_PARAM_LANGUAGE			0x00000100	/* language, e.g. Chinese */
#define ivTTS_PARAM_INPUT_CODEPAGE		0x00000101	/* input code page, e.g. GBK */
#define ivTTS_PARAM_TEXT_MARK			0x00000102	/* text mark, e.g. CSSML */
#define ivTTS_PARAM_USE_PROMPTS			0x00000104	/* whether use prompts */
#define ivTTS_PARAM_RECOGNIZE_PHONEME	0x00000105	/* how to recognize phoneme input */
#define ivTTS_PARAM_PROGRESS_BEGIN		0x00000204	/* current processing position */
#define ivTTS_PARAM_PROGRESS_LENGTH		0x00000205	/* current processing length */
#define ivTTS_PARAM_PROGRESS_CALLBACK	0x00000206	/* progress callback entry */
#define ivTTS_PARAM_READ_PUNCTUATIONS	0x00000300	/* whether read punctuations */
#define ivTTS_PARAM_READ_AS_NAME		0x00000301	/* whether read as name */
#define ivTTS_PARAM_READ_DIGIT			0x00000302	/* how to read digit, e.g. read as number, read as value  */
#define ivTTS_PARAM_CHINESE_NUMBER_1	0x00000303	/* how to read number "1" in Chinese */
#define ivTTS_PARAM_PHONEME_WATCH		0x00000402	/* how to watch phoneme, e.g. Chinese Pin-Yin */
#define ivTTS_PARAM_WATCH_CALLBACK		0x00000403	/* watch callback entry */
#define ivTTS_PARAM_EVENT_CALLBACK		0x00000404	/* sleep callback entry */

#define ivTTS_PARAM_ROLE				0x00000500	/* speaker role */
#define ivTTS_PARAM_SPEAK_STYLE			0x00000501	/* speak style */
#define ivTTS_PARAM_VOICE_SPEED			0x00000502	/* voice speed */
#define ivTTS_PARAM_VOICE_PITCH			0x00000503	/* voice tone */
#define ivTTS_PARAM_VOLUME				0x00000504	/* volume value */
#define ivTTS_PARAM_DELAYTIME			0x00000505	/* delay time */
#define ivTTS_PARAM_VOLUME_INCREASE		0X00000507	/* volume value increase */


#define ivTTS_PARAM_VEMODE				0x00000600	/* voice effect - predefined mode */

#define ivTTS_PARAM_OUTPUT_BUF			0x00000700	/* output buffer */
#define ivTTS_PARAM_OUTPUT_BUFSIZE		0x00000701	/* output buffer size */


/* constants for values of parameter ivTTS_PARAM_LANGUAGE */
#define ivTTS_LANGUAGE_CHINESE			1			/* Chinese (with English) */
#define ivTTS_LANGUAGE_ENGLISH			2			/* English */

/* constants for values of parameter ivTTS_PARAM_INPUT_CODEPAGE */
#define ivTTS_CODEPAGE_ASCII			437			/* ASCII */
#define ivTTS_CODEPAGE_GBK				936			/* GBK (default) */
#define ivTTS_CODEPAGE_BIG5				950			/* Big5 */
#define ivTTS_CODEPAGE_UTF16LE			1200		/* UTF-16 little-endian */
#define ivTTS_CODEPAGE_UTF16BE			1201		/* UTF-16 big-endian */
#define ivTTS_CODEPAGE_UTF7				65000		/* UTF-7 */
#define ivTTS_CODEPAGE_UTF8				65001		/* UTF-8 */
#define ivTTS_CODEPAGE_GB2312			ivTTS_CODEPAGE_GBK
#define ivTTS_CODEPAGE_GB18030			ivTTS_CODEPAGE_GBK
#define ivTTS_CODEPAGE_UTF16			ivTTS_CODEPAGE_UTF16LE
#define ivTTS_CODEPAGE_UNICODE			ivTTS_CODEPAGE_UTF16
#define ivTTS_CODEPAGE_PHONETIC_PLAIN	23456		/* Kingsoft Phonetic Plain */

/* constants for values of parameter ivTTS_PARAM_TEXT_MARK */
#define ivTTS_TEXTMARK_NONE				0			/* none */
#define ivTTS_TEXTMARK_SIMPLE_TAGS		1			/* simple tags (default) */

/* constants for values of parameter ivTTS_PARAM_INPUT_MODE */
#define ivTTS_INPUT_FIXED_BUFFER		0			/* from fixed buffer */
#define ivTTS_INPUT_CALLBACK			1			/* from callback */

/* constants for values of parameter ivTTS_PARAM_READ_DIGIT */
#define ivTTS_READDIGIT_AUTO			0			/* decide automatically (default) */
#define ivTTS_READDIGIT_AS_NUMBER		1			/* say digit as number */
#define ivTTS_READDIGIT_AS_VALUE		2			/* say digit as value */

/* constants for values of parameter ivTTS_PARAM_CHINESE_NUMBER_1 */
#define ivTTS_CHNUM1_READ_YAO			0			/* read number "1" [yao1] in chinese (default) */
#define ivTTS_CHNUM1_READ_YI			1			/* read number "1" [yi1] in chinese */

/* constants for values of parameter ivTTS_PARAM_PHONEME_WATCH */
#define ivTTS_PHONEME_NONE				0			/* none (default) */
#define ivTTS_PHONEME_PINYIN			1			/* Chinese Pin-Yin */

/* constants for values of parameter ivTTS_PARAM_ROLE */
#define ivTTS_ROLE_YANPING				3			/* Yanping (female, Chinese) */
#define ivTTS_ROLE_YUFENG				4			/* Yufeng (male, Chinese) */
#define ivTTS_ROLE_NANNAN				7			/* Nannan (child, Chinese) */
#define ivTTS_ROLE_XIAOQIAN				11			/* Xiaoqian (female, Chinese Northeast) */
#define ivTTS_ROLE_XIAORONG				14			/* Xiaorong (female, Chinese Szechwan) */
#define ivTTS_ROLE_XIAOMEI				15			/* Xiaomei (female, Cantonese) */
#define ivTTS_ROLE_JOHN					17			/* John (male, US English) */
#define ivTTS_ROLE_TERRY				19			/* Terry (female, US English) */
#define ivTTS_ROLE_JIUXU				51			/* Jiu Xu (male, Chinese) */
#define ivTTS_ROLE_DUOXU				52			/* Duo Xu (male, Chinese) */
#define ivTTS_ROLE_XIAOPING				53			/* Xiaoping (female, Chinese) */
#define ivTTS_ROLE_DONALDDUCK			54			/* Donald Duck (male, Chinese) */
#define ivTTS_ROLE_BABYXU				55			/* Baby Xu (child, Chinese) */
#define ivTTS_ROLE_USER					99			/* user defined */

/* constants for values of parameter ivTTS_PARAM_SPEAK_STYLE */
#define ivTTS_STYLE_PLAIN				0			/* plain speak style */
#define ivTTS_STYLE_NORMAL				1			/* normal speak style (default) */

/* constants for values of parameter ivTTS_PARAM_VOICE_SPEED */
/* the range of voice speed value is from -32768 to +32767 */
#define ivTTS_SPEED_MIN					-32768		/* slowest voice speed */
#define ivTTS_SPEED_NORMAL				0			/* normal voice speed (default) */
#define ivTTS_SPEED_MAX					+32767		/* fastest voice speed */

/* constants for values of parameter ivTTS_PARAM_VOICE_PITCH */
/* the range of voice tone value is from -32768 to +32767 */
#define ivTTS_PITCH_MIN					-32768		/* lowest voice tone */
#define ivTTS_PITCH_NORMAL				0			/* normal voice tone (default) */
#define ivTTS_PITCH_MAX					+32767		/* highest voice tone */

/* constants for values of parameter ivTTS_PARAM_VOLUME */
/* the range of volume value is from -32768 to +32767 */
#define ivTTS_VOLUME_MIN				-32768		/* minimized volume */
#define ivTTS_VOLUME_NORMAL				0			/* normal volume */
#define ivTTS_VOLUME_MAX				+32767		/* maximized volume (default) */

/* constants for values of parameter ivTTS_PARAM_VOLUME_INCREASE */
/* the range of volume value is from 0 to 10 */
#define ivTTS_VOLUME_INCREASE_MIN				0		/* minimized volume (default) */
#define ivTTS_VOLUME_INCREASE_MAX				10		/* maximized volume */

/* constants for values of parameter ivTTS_PARAM_VEMODE */
#define ivTTS_VEMODE_NONE				0			/* none */
#define ivTTS_VEMODE_WANDER				1			/* wander */
#define ivTTS_VEMODE_ECHO				2			/* echo */
#define ivTTS_VEMODE_ROBERT				3			/* robert */
#define ivTTS_VEMODE_CHROUS				4			/* chorus */
#define ivTTS_VEMODE_UNDERWATER			5			/* underwater */
#define ivTTS_VEMODE_REVERB				6			/* reverb */
#define ivTTS_VEMODE_ECCENTRIC			7			/* eccentric */

/* parameter change callback type */
typedef ivTTSErrID (ivProc ivTTSCB_ParamChange)(
	ivPointer		pParameter,		/* [in] user callback parameter */
	ivUInt32		nParamID,		/* [in] parameter ID */
	ivUInt32		nParamValue );	/* [in] parameter value */

/* progress callback type */
typedef ivTTSErrID (ivProc ivTTSCB_Progress)(
	ivPointer		pParameter,		/* [in] user callback parameter */
	ivUInt32		iProcBegin,		/* [in] current processing position */
	ivUInt32		nProcLen );		/* [in] current processing length */

/* input callback type */
typedef ivTTSErrID (ivProc ivTTSCB_Input)(
	ivPointer		pParameter,		/* [in] user callback parameter */
	ivPointer		pText,			/* [out] input text buffer */
	ivSize ivPtr	pnSize );		/* [in/out] input text size */

/* output callback type */
typedef ivTTSErrID (ivProc ivTTSCB_Output)(
	ivPointer		pParameter,		/* [in] user callback parameter */
	ivUInt16		nCode,			/* [in] output data code */
	ivCPointer		pcData,			/* [in] output data buffer */
	ivSize			nSize );		/* [in] output data size */

/* parameter change callback type */
typedef ivTTSErrID (ivProc ivTTSCB_Event)(
	ivPointer		pParameter,		/* [in] user callback parameter */
	ivUInt32		nEventID,		/* [in] parameter ID */
	ivUInt32		nValue );	/* [in] parameter value */

/* constants for values of parameter nEventID */
#define ivTTS_EVENT_SLEEP				0x0100		/* sleep */
#define ivTTS_EVENT_PLAYSTART			0x0101		/* start playing */
#define ivTTS_EVENT_SWITCHCONTEXT		0x0102		/* context switch */

/* constants for values of parameter wCode */
#define ivTTS_CODE_COMMAND				0x0000		/* command */
#define ivTTS_CODE_PCM8K16B				0x0208		/* PCM 8K 16bit */
#define ivTTS_CODE_PCM11K16B			0x020B		/* PCM 11K 16bit */
#define ivTTS_CODE_PCM16K16B			0x0210		/* PCM 16K 16bit */
#define ivTTS_CODE_PCM22K16B			0x0216		/* PCM 22K 16bit */

/* structure for output command */
typedef struct tagTTSOutputCommand ivTTTSOutputCommand;
typedef ivTTTSOutputCommand ivPtr ivPTTSOutputCommand;

struct tagTTSOutputCommand
{
	ivUInt32		dwCommand;		/* command name */
	ivUInt32		dwParam1;		/* parameter 1 */
	ivUInt32		dwParam2;		/* parameter 2 */
};

/* constants for values of command name */
#define ivTTS_OUTCMD_SILENCE			0			/* output silence (dwParam1 is the length by ms) */
#define ivTTS_OUTCMD_RESET				1			/* reset the decoder */

/* watch callback type */
typedef ivTTSErrID (ivProc ivTTSCB_Watch)(
	ivPointer		pParameter,		/* [in] user callback parameter */
	ivUInt16		nSylType,		/* [in] syllable type */
	ivCPointer		pcSylText,		/* [in] syllable text buffer */
	ivSize			nTextLen,		/* [in] syllable text length */
	ivCPointer		pcSylPhone,		/* [in] syllable phoneme buffer */
	ivSize			nPhoneLen );	/* [in] syllable phoneme length */

/* constants for values of parameter wSylType */
#define ivTTS_SYL_SYMBOL				0			/* symbol */
#define ivTTS_SYL_PROMPT				1			/* prompt */
#define ivTTS_SYL_CHINESE				2			/* chinese syllable */
#define ivTTS_SYL_ENGLISH				3			/* english syllable */

#define ivTTS_SYL_ENDL1				(ivUInt16)-1	/* end L1 */
#define ivTTS_SYL_ENDL3				(ivUInt16)-3	/* end L3 */
#define ivTTS_SYL_ENDSENT			(ivUInt16)-5	/* end sentense */


/*
 *	PARAMETER STRUCTURES
 */

/* parameters for voice effect amplify */
typedef struct tagIsTTSVEAmplifyParam TIsTTSVEAmplifyParam;

struct tagIsTTSVEAmplifyParam
{
	ivUInt16	m_nPeriod;			/* 1-2000ms */
	ivUInt8		m_fAmpMin;			/* 0-100% */
	ivUInt8		m_fAmpMax;			/* 0-100% */
};


/* parameters for voice effect echo */
typedef struct tagIsTTSVEEchoParam TIsTTSVEEchoParam;

struct tagIsTTSVEEchoParam
{
	ivUInt8		m_fInitDecay;		/* 0-100% */
	ivUInt8		m_fDecay;			/* 0-100% */
	ivUInt16	m_nDelay;			/* 1-2000ms */
};


/* parameters for voice effectVE reverb */
typedef struct tagIsTTSVEReverbParam TIsTTSVEReverbParam;

struct tagIsTTSVEReverbParam
{
	ivUInt8		m_fInitDecay;		/* 0-100% */
	ivUInt8		m_nFilters;			/* 1-16 */
	ivUInt8		m_fDecay[16];		/* 0-100% */
	ivUInt8		m_nDelay[16];		/* 1-100ms */
};


/* parameters for voice effect chrous */
typedef struct tagIsTTSVEChrousParam TIsTTSVEChrousParam;

struct tagIsTTSVEChrousParam
{
	ivUInt8		m_fInitDecay;		/* 0-100% */
	ivUInt8		m_fInitRatio;		/* 0-100% */
	ivUInt8		m_nDelayMin;		/* 1-40ms */
	ivUInt8		m_nDelayMax;		/* 1-40ms */
	ivUInt8		m_nFilters;			/* 1-16 */
	ivUInt8		m_nFilterFreq;		/* 1-50Hz */
	ivUInt8		m_nFilterFreqDelta;	/* 1-50Hz */
};


/* parameters for voice effect pitch */
typedef struct tagIsTTSVEPitchParam TIsTTSVEPitchParam;

struct tagIsTTSVEPitchParam
{
	ivUInt8		m_fDeltaPitch;		/* 0-90% */
	ivUInt16	m_nPeriod;			/* 1-20000ms */
};


/*
 *   old parameters and API
 */
#define ivTTS_PARAM_MANUAL_PROSODY		0x00000304	/* whether use manual prosody */
/* destroy an instance */
ivTTSErrID ivCall ivTTS_Destroy(
	ivHTTS			hTTS );				/* [in] handle to an instance */

/* run an instance and hold current thread's control */
ivTTSErrID ivCall ivTTS_Run(
	ivHTTS			hTTS );				/* [in] handle to an instance */

/* begin to synthesize from callback on an instance */
ivTTSErrID ivCall ivTTS_SynthStart(
	ivHTTS			hTTS );				/* [in] handle to an instance */

/*
 *********************************************************************************
 *	old param 
 *********************************************************************************
 */
#define ivTTS_PARAM_INPUT_MODE			0x00000200	/* input mode, e.g. from fixed buffer, from callback */
#define ivTTS_PARAM_INPUT_TEXT_BUFFER	0x00000201	/* input text buffer */
#define ivTTS_PARAM_INPUT_TEXT_SIZE		0x00000202	/* input text size */
#define ivTTS_PARAM_INPUT_CALLBACK		0x00000203	/* input callback entry */
#define ivTTS_PARAM_OUTPUT_VOICE		0x00000400	/* output voice or not */
#define ivTTS_PARAM_OUTPUT_CALLBACK		0x00000401	/* output callback entry */

#define ivTTS_PARAM_VE_AMPLIFY			0x00000601	/* voice effect - amplify */
#define ivTTS_PARAM_VE_ECHO				0x00000602	/* voice effect - echo */
#define ivTTS_PARAM_VE_REVERB			0x00000603	/* voice effect - reverb */
#define ivTTS_PARAM_VE_CHROUS			0x00000604	/* voice effect - chrous */
#define ivTTS_PARAM_VE_PITCH			0x00000605	/* voice effect - pitch adjust */

#define ivTTS_PARAM_VOICE_TIMBRE		0x00000506	/* voice timbre */


#define ivTTS_LANGUAGE_FRENCH			3			/* French */
#define ivTTS_TEXTMARK_CSSML			2			/* CSSML */
#define ivTTS_STYLE_VIVID				2			/* vivid speak style */

#define ivTTS_PARAM_TEXT_SCOPE			0x00000103	/* text scope, e.g. number */
/* constants for values of parameter ivTTS_PARAM_TEXT_SCOPE */
#define ivTTS_SCOPE_UNLIMITED			0			/* unlimited scope (default) */
#define ivTTS_SCOPE_CHINESE_NUMBER		1			/* Chinese number */
#define ivTTS_SCOPE_CHINESE_VALUE		2			/* Chinese value */
#define ivTTS_SCOPE_CHINESE_DATETIME	3			/* Chinese date or time */

#define ivTTS_ROLE_TIANCHANG			1			/* Tianchang (female, Chinese) */
#define ivTTS_ROLE_WENJING				2			/* Wenjing (female, Chinese) */
#define ivTTS_ROLE_SHERRI				5			/* Sherri (female, US English) */
#define ivTTS_ROLE_XIAOJIN				6			/* Xiaojin (female, Chinese) */
#define ivTTS_ROLE_JINGER				8			/* Jinger (female, Chinese) */
#define ivTTS_ROLE_JIAJIA				9			/* Jiajia (girl, Chinese) */
#define ivTTS_ROLE_YUER					10			/* Yuer (female, Chinese) */
#define ivTTS_ROLE_LAOMA				12			/* Laoma (male, Chinese) */
#define ivTTS_ROLE_BUSH					13			/* Bush (male, US English) */
#define ivTTS_ROLE_ANNI					16			/* Anni (female, Chinese) */
#define ivTTS_ROLE_ANITA				18			/* Anita (female, British English) */
#define ivTTS_ROLE_CATHERINE			20			/* Catherine (female, US English) */

#define ivTTS_PARAM_ENGLISH_NUMBER_0	0x00000305	/* how to read number "0" in Englsih */

/* constants for values of parameter ivTTS_PARAM_ENGLISH_NUMBER_0 */
#define ivTTS_ENNUM0_READ_ZERO			0			/* read number "0" [zero] in english (default) */
#define ivTTS_ENNUM0_READ_O				1			/* read number "0" [o] in englsih */

#ifdef __cplusplus
}
#endif


#endif /* !IFLYTEK_VOICE__TTS__H */
#endif
