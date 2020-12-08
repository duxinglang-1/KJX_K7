//file name: Npr_Tts_vload.h
//  hyc
//语音王动态加载适配文件

#ifndef NPR_TTS_VLOAD__H
#define NPR_TTS_VLOAD__H
#include "mmi_features.h"
#if defined (__NPR_TTS__) && defined (__NPR_TTS_VLOAD__)
#include "Npr_Tts_type.h"

typedef void (*pJD_Trancefun)(jdCHAR *fmt,...);

typedef struct 
{
//预留。暂时没用到
  jdU8 flag;	
  pJD_Trancefun         f_Trancefun; 
} JDYNC_TTS_S;

// for platform
typedef ivTTSErrID ivCall (*pJT_ivTTS_Destroy)(ivHTTS hTTS);
typedef ivTTSErrID ivCall (*pJT_ivTTS_Create)(ivHTTS ivPtr phTTS, ivPointer pHeap, ivSize nHeapSize, ivPointer pCBParam, ivPResPackDesc pResPackDesc, ivSize nResPackCount);
typedef ivTTSErrID ivCall (*pJT_ivTTS_SetParam)(ivHTTS hTTS, ivUInt32 nParamID, ivUInt32 nParamValue);
typedef ivTTSErrID ivCall (*pJT_ivTTS_SynthText)(ivHTTS hTTS, ivCPointer pcData, ivSize nSize);

typedef struct 
{
	pJT_ivTTS_Destroy					f_ivTTS_Destroy;
	pJT_ivTTS_Create					f_ivTTS_Create;
	pJT_ivTTS_SetParam					f_ivTTS_SetParam;
	pJT_ivTTS_SynthText					f_ivTTS_SynthText;	
} JDYNC_TTS_INTERFACE_S;

#endif
#endif 


