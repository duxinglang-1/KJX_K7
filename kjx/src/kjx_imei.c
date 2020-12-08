/**********************************************************************************
*Filename:     kjx_imei.c
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2015/10/08
*
***********************************************************************************/
#include "kjx_include.h"
#include <stdlib.h> 
#include <stdio.h> 
#include <time.h> 

#include "ProfilesSrvGprot.h"
#include "ImeiSrvGprot.h"

#define KJX_IMEI_DEBUG

extern U8 kjxImei[SRV_IMEI_MAX_LEN+1];

BOOL kjx_check_imei_head(char* ImeiString)
{
	if(memcmp("95668\0",ImeiString,strlen("95668\0"))==0)
	{
	#ifdef KJX_IMEI_DEBUG
		kjx_trace("%s>>return TRUE", __func__);
	#endif
		return TRUE;
	}
#ifdef KJX_IMEI_DEBUG
	kjx_trace("%s>>return FALSE", __func__);
#endif
	return FALSE;
}

BOOL kjx_check_imei_project_id(char* ImeiString)
{
	U8 projectStr[4];
	U16 projectId = 0;
	extern U16 kjx_return_project_id(void);

	memset(projectStr,0,sizeof(projectStr));
	strncat(projectStr,ImeiString+strlen("95668\0"),2);
	projectId = atoi(projectStr);
#ifdef KJX_IMEI_DEBUG
	kjx_trace("%s>>projectId:%d", __func__, projectId);
#endif
	if(kjx_return_project_id()==projectId)
	{
	#ifdef KJX_IMEI_DEBUG
		kjx_trace("%s>>return TRUE", __func__);
	#endif
		return TRUE;
	}
#ifdef KJX_IMEI_DEBUG
	kjx_trace("%s>>return FALSE", __func__);
#endif
	return FALSE;
}

BOOL kjx_check_imei_rand(char* ImeiString)
{
	//U8 projectStr[6];
	U8 randStr[6];
	U8 valueStr[6];
	U8 temRandStr[6];
	int RandValue[10]={ 4, 8, 5, 2, 9, 3, 6, 0, 1, 7 };
	int projectId = 0,isSeed = 0,randNum = 0,randImei = 0,i=0,randValue1=0,randValue2=0;
	extern U16 kjx_return_project_id(void);
 
	memset(randStr,0,sizeof(randStr));
	strncat(randStr,ImeiString+strlen("95668**\0"),2);
	randImei = atoi(randStr);

	memset(temRandStr,0,sizeof(temRandStr));
	strncat(temRandStr,randStr,1);
	randValue1 = atoi((const char*)temRandStr); 
	memset(temRandStr,0,sizeof(temRandStr));
	strncat(temRandStr,randStr+1,1);
	randValue2 = atoi((const char*)temRandStr); 
#ifdef KJX_IMEI_DEBUG
	kjx_trace("%s>>randImei:%d, randValue1:%d, randValue2:%d", __func__, randImei, randValue1, randValue2);
#endif
	randValue1 = (randValue1+10-9); 
#ifdef KJX_IMEI_DEBUG
	kjx_trace("%s>>randValue1:%d", __func__, randValue1);
#endif
	for(i=0;i<10;i++)
	{
	#ifdef KJX_IMEI_DEBUG
		kjx_trace("%s>>RandValue[i]:%d, randValue1:%d", __func__, RandValue[i], randValue1);
	#endif
		if(RandValue[i]==randValue1)
		{ 
			randValue1 = i;
			break;
		}
	}
#ifdef KJX_IMEI_DEBUG
	kjx_trace("%s randValue1=%d",__func__,randValue1);
#endif
	randValue2 = (randValue2+8-8); 
#ifdef KJX_IMEI_DEBUG
	kjx_trace("%s>>randValue2:%d", __func__, randValue2);
#endif
	for(i=0;i<10;i++)
	{
	#ifdef KJX_IMEI_DEBUG
		kjx_trace("%s>>RandValue[i]:%d, randValue2:%d", __func__, RandValue[i], randValue2);
	#endif
		if(RandValue[i]==randValue2)
		{
			randValue2 = i;
			break;
		}
	}
#ifdef KJX_IMEI_DEBUG
	kjx_trace("%s>>randValue2:%d", __func__, randValue2);
	kjx_trace("%s>>randValue1:%d, randValue2:%d", __func__, randValue1, randValue2);
#endif

	memset(valueStr,0,sizeof(valueStr));
	sprintf(valueStr,"%d%d",randValue1,randValue2);
	randNum = atoi(valueStr); 
#ifdef KJX_IMEI_DEBUG
	kjx_trace("%s>>valueStr:%s, randNum:%d", __func__, valueStr, randNum);
#endif
	if(((-1<randValue1)&&(randValue1<5))&&((4<randValue2)&&(randValue2<10)))
	{
	#ifdef KJX_IMEI_DEBUG
		kjx_trace("%s>>return TRUE", __func__);
	#endif
		return TRUE;
	}

#ifdef KJX_IMEI_DEBUG
	kjx_trace("%s>>return FALSE", __func__);
#endif
	return FALSE;

}

BOOL kjx_check_imei_string_and_checksum(char* ImeiString)
{
	U8 imeiString[6];
	U8 randStr[6];
	int imeiValue = 0,randNum = 0,randImei = 0,checksum = 0;
	int checksunRand[10] = { 1, 3, 4, 8, 0, 7, 2, 6, 5, 9 };
	extern U16 kjx_return_project_id(void);

	memset(randStr,0,sizeof(randStr));
	strncat(randStr,ImeiString+strlen("95668**\0"),2);
	randImei = atoi(randStr);

	memset(imeiString,0,sizeof(imeiString));
	strncat(imeiString,ImeiString+strlen("95668**@@\0"),5);
	imeiValue = atoi(imeiString);
#ifdef KJX_IMEI_DEBUG
	kjx_trace("%s>>imeiValue:%d", __func__, imeiValue);
#endif
	randNum = (randImei + imeiValue + checksunRand[imeiValue%10])%9;

	memset(imeiString,0,sizeof(imeiString));
	strncat(imeiString,ImeiString+strlen("95668**@@#####\0"),5);
	checksum = atoi(imeiString);
#ifdef KJX_IMEI_DEBUG
	kjx_trace("%s>>checksum:%d, randNum:%d ", __func__, checksum, randNum);
#endif
	if(randNum==checksum)
	{
	#ifdef KJX_IMEI_DEBUG
		kjx_trace("%s>>return TRUE", __func__);
	#endif
		return TRUE;
	}
#ifdef KJX_IMEI_DEBUG
	kjx_trace("%s>>return FALSE", __func__);
#endif
	return FALSE;

}

void kjx_check_imei_error(void)
{
#ifdef KJX_IMEI_DEBUG
	kjx_trace("%s>>begin", __func__);
#endif

	while(1)
	{
		kal_sleep_task(1000);
	}
 
}

void kjx_check_imei(void)
{
#ifdef KJX_IMEI_DEBUG
	kjx_trace("%s>>kjxImei:%s", __func__, kjxImei);
#endif
	if(!strlen(kjxImei))
	{       
		//srv_prof_play_tone_with_id(SRV_PROF_TONE_FM, (U16)(SRV_PROF_AUD_TONE3), SRV_PROF_RING_TYPE_REPEAT, NULL);
		return;
	}

	//srv_profiles_stop_tone(SRV_PROF_TONE_FM);
	
	if(!kjx_check_imei_head((char*)kjxImei))
	{
		goto imei_error;
	}
	
	if(!kjx_check_imei_project_id((char*)kjxImei))
	{
		goto imei_error;
	}

	if(!kjx_check_imei_rand((char*)kjxImei))
	{
		goto imei_error;
	}

	if(!kjx_check_imei_string_and_checksum((char*)kjxImei))
	{
		goto imei_error;
	}
#ifdef KJX_IMEI_DEBUG
	kjx_trace("%s>>imei_OK", __func__);
#endif
	return;
	  
imei_error:
	srv_prof_play_tone_with_id(SRV_PROF_TONE_FM, (U16)(SRV_PROF_AUD_TONE1), SRV_PROF_RING_TYPE_REPEAT, NULL);

#ifdef KJX_IMEI_DEBUG
	kjx_trace("%s>>imei_error", __func__);
 #endif
 
	StartTimer(KJX_TIMER_ID_IMEI_CHECK_ERROR, 1000*10, kjx_check_imei_error);
}

