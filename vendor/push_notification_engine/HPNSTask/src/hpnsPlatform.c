/******************************************************************* 
* Copyright (c) 2010 by Hesine Technologies, Inc. 
* All rights reserved. 
* 
* This file is proprietary and confidential to Hesine Technologies. 
* No part of this file may be reproduced, stored, transmitted, 
* disclosed or used in any form or by any means other than as 
* expressly provided by the written permission from Jianhui Tao 
* 
* ****************************************************************/

#include "OslMemory.h"
#include "common_nvram_editor_data_item.h"
#include "Conversions.h"
#include "MMI_features.h"
#include "Unicodexdcl.h"
#include "ProtocolEvents.h"
#include "PhonebookDef.h"
#include "SettingDefs.h"        /* For FDN on Message */
#include "SettingsGdcl.h"
#include "CommonScreens.h"
#include "app2soc_struct.h" 
#include "Soc_api.h"
#include "cbm_api.h"
#include "SMSStruct.h"
#include "fs_gprot.h"
#include "verno.h"
#include "abm_soc_enums.h"//ABM_E_SOCKET_BEARER_GSM_GPRS
#include "DataAccountCommon.h"
#include "DateTimeGprot.h"
#include "USBDeviceGprot.h"
#include "kbd_table.h"

#include "hpnsAppEngine.h"
#include "mmi_features.h"
#include "hpnsUtil.h"
#include "hpnsMsg.h"

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "init.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_ltlcom.h"
#include "task_config.h"
#include "ImeiSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "app_str.h"
#include "vmsys.h"
#include "DtcntSrvGprot.h"
#include "CbmSrvGprot.h"
#include "custom_emi_release.h"

/****************************************************************************
* Global Variable
*****************************************************************************/
#ifdef __MTK_TARGET__
extern kal_uint32 custom_get_FLASH_Size(void);
#endif
extern MMI_BOOL srv_pns_process_click_rate(SHpnsAppStatistics  *hpnsAppStatistic);

kal_uint8 g_hpns_app_id;
kal_uint32 g_hpns_aacount_id;

KAL_ADM_ID       nms_memory_id = 0;
kal_int8 gNmsStopHissageFromApp=0;

#define NMS_MEMORY_POOL	1024*22
static kal_uint8 nms_memory_pool[NMS_MEMORY_POOL] = {0};

kal_int8 gNmsIsFormat = 0;

typedef struct {
    kal_semid sem;	
	char      name[20];
} SNmsSem;

kal_bool nmsCreateLocalMemoryPool(void)
{
	nms_memory_id = kal_adm_create(nms_memory_pool,NMS_MEMORY_POOL,NULL,KAL_FALSE);

	if(!nms_memory_id) 
	{
	#ifndef __MTK_TARGET__
		nprintf("failed to create nms memory pool");
	#endif	
		return MMI_FALSE;
	}

#ifndef __MTK_TARGET__
	nprintf("nms create memory pool size : %d KB", NMS_MEMORY_POOL/1024);
#endif		
	return MMI_TRUE;
}


void *hpnsMallocL(kal_uint32 size)
{
    void* res = NULL;
	
	res = kal_adm_alloc(nms_memory_id, size);

    if(NULL == res)
	{
	#ifndef __MTK_TARGET__
		nprintf("failed to alloc memory,size:%d",size);
	#endif	
	}
	
    return res;
}

void hpnsFreeL(void* pMem)
{
    kal_adm_free(nms_memory_id, pMem);
}

void *hpnsCreateSem(char *pName, unsigned int initNum)
{
	kal_semid semid;    

	semid = kal_create_sem((kal_char*)pName, initNum);

	return (void *)semid;
}

int hpnsTakeSem(void *param)
{
    int status = KAL_SUCCESS;
	status = kal_take_sem((kal_semid)param, KAL_INFINITE_WAIT);
    return status;
}

int hpnsGiveSem(void *param)
{
    kal_give_sem((kal_semid)param);
	return 0;
}

HFILE hpnsFsOpen(char *name, UINT flag)
{
	WCHAR wName[HPNS_FILE_LEN] = {0};
	WCHAR *pBuffer = NULL;
	WCHAR *pDestName = NULL;
	unsigned int  NameLen = 0;
	int  ret = FS_NO_ERROR;

	if(name == NULL)
		return 0;
	pDestName = wName;
	NameLen = strlen(name);
	if(NameLen >= HPNS_FILE_LEN)
	{
		NameLen = (NameLen+1)*2;
		pBuffer = (WCHAR*)hpnsMallocL(NameLen);
		if(pBuffer == NULL)
			return 0;
		memset(pBuffer,0x00,NameLen);
		pDestName = pBuffer;
	}
	
    mmi_asc_to_ucs2((S8 *)pDestName, name);
	flag |= FS_OPEN_SHARED;
	ret = FS_Open(pDestName, flag);	
    if(ret < FS_NO_ERROR)
        ret = 0;
	if(pBuffer != NULL)
		hpnsFreeL(pBuffer);
    return ret;
}

int hpnsFsDelete(char *file)
{
	WCHAR wName[HPNS_FILE_LEN] = {0};
	WCHAR *pBuffer = NULL;
	WCHAR *pDestName = NULL;
	int ret = 0;
	unsigned int NameLen = 0;
	if(file == NULL)
		return -1;

	pDestName = wName;
	NameLen = strlen(file);
	if(NameLen >= HPNS_FILE_LEN)
	{
		NameLen = (NameLen+1)*2;
		pBuffer = (WCHAR*)hpnsMallocL(NameLen);
		if(pBuffer == NULL)
			return -1;
		memset(pBuffer,0x00,NameLen);
		pDestName = pBuffer;
	}
     mmi_asc_to_ucs2((S8 *)pDestName, file);
   	 ret = FS_Delete(pDestName);
	if(pBuffer != NULL)
		hpnsFreeL(pBuffer);
	return ret;
}

int hpnsFsRead(HFILE hFile, void *pData, int nLen, int *read)
{
	int ret = FS_NO_ERROR, TempRead = 0;
		
	if(NULL == read)
	{
		read = &TempRead;		
	}

	ret = FS_Read(hFile, pData, nLen, (UINT*)read);
	
    return ret;
}

int hpnsFsWrite(HFILE hFile, void *pData, int nLen, int *written)
{
	int ret = FS_NO_ERROR, TempWrite = 0;

	if(NULL == written)
	{
		written = &TempWrite;		
	}
	
    ret = FS_Write(hFile, pData, nLen, (kal_uint32 *)written);

	return ret;	
}

int hpnsFsSeek(HFILE hFile, int offset, int Whence)
{
    return FS_Seek(hFile, offset, Whence);
}

void hpnsFsClose(HFILE hFile)
{
	FS_Close (hFile);	
}

int hpnsFsGetFileSizeWithName(char *pName, int *size)
{
    FS_HANDLE fileHandle = NULL;

    fileHandle = hpnsFsOpen((char*)pName, FS_READ_ONLY | FS_OPEN_SHARED);

	if (fileHandle < 0)
	{
	#ifndef __MTK_TARGET__
		nprintf("failed to open file while getting it's size");
	#endif	
		return FS_FILE_NOT_FOUND;
	}
    else
    {
        FS_GetFileSize(fileHandle, (U32*)&(*size));
        FS_Close(fileHandle);
        return FS_NO_ERROR;
    }	
}

int hpnsFsFileExists (char *pName)
{
	int hr = NULL;
	unsigned int NameLen = 0;
	WCHAR wName[HPNS_FILE_LEN] = {0};
	WCHAR *pBuffer = NULL;
	WCHAR *pDestName = NULL;

	if(pName == NULL)
		return 0;

	pDestName = wName;
	NameLen = strlen(pName);
	if(NameLen >= HPNS_FILE_LEN)
	{
		NameLen = NameLen*2+2;
		pBuffer = (WCHAR*)hpnsMallocL(NameLen);
		if(pBuffer == NULL)
			return 0;
		memset(pBuffer,0x00,NameLen);
		pDestName = pBuffer;
	}
    mmi_asc_to_ucs2((S8*)pDestName, pName);
	hr = FS_GetAttributes((WCHAR*)pDestName);
	if(pBuffer != NULL)
		hpnsFreeL(pDestName);
	if (hr < 0) 
		return 0;
    else
	    return 1;

}

int hpnsFsFlush(HFILE hFile)
{
    return FS_Commit(hFile);
}


int hpnsGetOSID(void)
{
	return 40;//NMS_CLIENT_OS_MTK_6235_09A
}

kal_int32 hpnsGetSimCardSide(void)
{
    return (kal_int32)srv_sim_ctrl_get_num_of_inserted();
}

kal_bool hpnsGetImeiValue(CHAR* buffer, kal_uint32 size)
{
	return srv_imei_get_imei(MMI_SIM1, buffer, size);
}

void hpnsGetImsiImei(kal_uint8 imsi[][20], kal_uint8 *pImei)
{
	kal_int32 cardnum = 0;
    int i,j ;
    mmi_sim_enum sim = MMI_SIM1;
	MMI_BOOL getimsi = KAL_FALSE;
	CHAR tempImsi[20];
	cardnum = hpnsGetSimCardSide();
	for(i =0; i < cardnum; i++)
	{
	    switch (i)
        {
            case 0:
                sim = MMI_SIM1;
                break;
            case 1:
                sim = MMI_SIM2;
                break;
            case 2:
                sim = MMI_SIM3;
                break;
            case 3:
                sim = MMI_SIM4;
                break;
        }
		memset(tempImsi, 0, 20);
		getimsi = srv_sim_ctrl_get_imsi(sim, tempImsi, 20);
		if('9' == tempImsi[0])
		{
			for(j=1; j<20;j++)
			{
				imsi[i][j-1] = tempImsi[j];
			}
		}
		else
		{
			app_strlcpy((CHAR*)imsi[i], tempImsi, 20);
		}
		if(getimsi)
		{
			#ifndef __MTK_TARGET__
			nprintf("[PNSRV]hpnsGetImsiImei = %s\n", imsi[i]);
			#else
			kal_prompt_trace(MOD_MMI,"[PNSRV]hpnsGetImsiImei = %s\n", imsi[i]);
			#endif
	}
	}
	hpnsGetImeiValue((CHAR*)pImei, HPNS_IMEI_LEN);
	return;
}

void    hpnsGetChepSet(kal_int8 chepSet[])
{

	return ;
}


kal_uint32 hpnsGetMobileLanguage(void)
{
	kal_uint8 *lang = Get_Current_Lang_CountryCode();

    if (strcmp((char*) lang, "en-US") == 0)
    {
    	return HPNS_LANGUAGE_ENGLISH;
    }
    else if (strcmp((char*) lang, "zh-CN") == 0)
    {
    	return HPNS_LANGUAGE_CHINESE;
    }
    else if (strcmp((char*) lang, "zh-TW") == 0)
    {
    	return HPNS_LANGUAGE_CHINESE_TW;
    }
    else if (strcmp((char*) lang, "es-SA") == 0)
    {
    	return HPNS_LANGUAGE_SPAIN;
    }
    else if (strcmp((char*) lang, "de-DE") == 0)
    {
    	return HPNS_LANGUAGE_GERMANY;
    }
    else if (strcmp((char*) lang, "re-RU") == 0)
    {
    	return HPNS_LANGUAGE_RUSSIA;
    }
    else if (strcmp((char*) lang, "th-TH") == 0)
    {
    	return HPNS_LANGUAGE_THAILAND;
    }
	else if (strcmp((char*) lang, "vi-VW") == 0)
	{
	   return HPNS_LANGUAGE_VIETNAM;
	}
	else if (strcmp((char*) lang, "id-IDss") == 0)
	{
	   return HPNS_LANGUAGE_INDONESIA;
	}

	return HPNS_LANGUAGE_ENGLISH;
}	

int hpnsSendMsgToUIP(int mid, kal_uint8 *pMsg, int msgLen) 
{
	ilm_struct  *ilm_ptr;
	module_type mod_id = stack_get_active_module_id();
    SNmsQueueMsgStruct* pNmsMsg = NULL;

    pNmsMsg = (SNmsQueueMsgStruct*)OslConstructDataPtr(sizeof(SNmsQueueMsgStruct));


    if( NULL != pMsg && msgLen > 0)
    {
    	pNmsMsg->pData = hpnsMallocL(msgLen);
		memcpy(pNmsMsg->pData, pMsg,msgLen);
    }
	else
	{
		pNmsMsg->pData = (S8*)pMsg;
	}
	pNmsMsg->MsgType = mid;
	pNmsMsg->DataLen = msgLen;

    ilm_ptr = allocate_ilm(mod_id);

    ilm_ptr->msg_id = MSG_ID_MSG_TO_MMI_FROM_NMS;
    ilm_ptr->local_para_ptr = (local_para_struct*)pNmsMsg;
    ilm_ptr->peer_buff_ptr = NULL;
	ilm_ptr->src_mod_id  = mod_id;
	ilm_ptr->sap_id = INVALID_SAP;
	ilm_ptr->dest_mod_id = MOD_MMI;
	msg_send_ext_queue(ilm_ptr);

    //SEND_ILM((module_type)mod_id, MOD_MMI, 0, ilm_ptr);

	return 0;
}

int hpnsSendMsgToEngineP(int mid, kal_uint8 *pMsg, int msgLen) 
{ 
	ilm_struct  *ilm_ptr;
	module_type mod_id = stack_get_active_module_id();
    SNmsQueueMsgStruct* pNmsMsg = NULL;

    pNmsMsg = (SNmsQueueMsgStruct*)OslConstructDataPtr(sizeof(SNmsQueueMsgStruct));

    if(NULL != pMsg && msgLen > 0)
    {
    	pNmsMsg->pData = hpnsMallocL(msgLen);
        memcpy(pNmsMsg->pData, pMsg,msgLen);
    }
	else
	{
		pNmsMsg->pData = (S8*)pMsg;
	}

	pNmsMsg->MsgType = mid;
	pNmsMsg->DataLen = msgLen;

    ilm_ptr = allocate_ilm(mod_id);

    ilm_ptr->msg_id = MSG_ID_MSG_TO_NMS_FROM_MMI;
    ilm_ptr->local_para_ptr = (local_para_struct*)pNmsMsg;
    ilm_ptr->peer_buff_ptr = NULL;

    ilm_ptr->src_mod_id  = mod_id;
    ilm_ptr->dest_mod_id = MOD_NMS;
    ilm_ptr->sap_id = INVALID_SAP;
    msg_send_ext_queue(ilm_ptr);
    //SEND_ILM(mod_id, MOD_NMS, 0, ilm_ptr);

	return 0;
}

kal_uint32 hpnsGetSystemTime()
{
    MYTIME t;
    S32 timeSecs;
    FLOAT tz;
    applib_time_struct time;
    U32 tzdiff = 0;
    
    DTGetRTCTime(&t);
    
    timeSecs = mmi_dt_mytime_2_utc_sec(&t,KAL_FALSE);
    tz = mmi_dt_get_tz();
    if(tz < 0)
    {
        time = applib_conv_tz_to_mytime(tz * (-1));
    }
    else
    {
        time = applib_conv_tz_to_mytime(tz);
    }
    tzdiff =  time.nHour * 3600 + time.nMin * 60 + time.nSec;
    if(tz > 0)
    {
        return timeSecs-tzdiff;
    }
    else
    {
        return timeSecs+tzdiff;
    }
}

kal_uint32  hpnsGetUsecTime(void)
{
    return hpnsGetSystemTime()*1000000;
}

char *hpnsGetTimeStamp()
{
	static char buffer[40];

	MYTIME t;
	
    DTGetRTCTime((applib_time_struct*)&t);

	sprintf (buffer, "%4d-%02d-%02d %02d:%02d:%02d ", t.nYear, t.nMonth, t.nDay, t.nHour, t.nMin, t.nSec);	

	return buffer;
}

int hpnsCloseSem(void *param)
{
	return 0;
}

void hpnsTrace(char* buf)
{
	#ifdef WIN32	
		fprintf(stdout, "%s", buf);
	#else
		kal_prompt_trace(MOD_MMI, "%s", buf);	
	#endif
}

kal_uint32 hpnsHtonl(kal_uint32 x)
{
	return soc_htonl(x);
}

kal_uint32 hpnsNtohl(kal_uint32 x)
{
	return soc_ntohl(x);
}

kal_uint16 hpnsHtons(kal_uint16 x)
{
	return soc_htons(x);
}
	
kal_uint16 hpnsNtohs(kal_uint16 x)
{
	return soc_ntohs(x);
}

//TODO:Need to implement
int hpnsGetLocationInfo(kal_uint8 *latitude, kal_uint8 *longitude)
{
    return 0;
}

int hpnsGetMemoryConfig(kal_uint32 *sizeOfRAM, kal_uint32 *sizeOfROM)
{
#ifdef __MTK_TARGET__
    kal_uint32 b = 0;
    
    b = custom_get_FLASH_Size();
    (*sizeOfROM) = b/1024; /* KB */
    b = 0;
    custom_get_EXTSRAM_size(&b);
    (*sizeOfRAM) = b/1024; /* KB */
#endif
    return 0;
}

void    hpnsGetMACAddress(kal_int8 macAddr[])
{
	//strcpy(macAddr, "11:22:33:44:55:66");
	return;

}

int hpnsGetMREVersionInfo(kal_int8 MREVersion[])
{
    char tmpbuf[50] = {0};
#ifdef __MTK_TARGET__
    //app_strlcpy((kal_char*)MREVersion, (const kal_char*)vm_get_mre_version, 16);
    sprintf(tmpbuf, "VER_%d", MRE_VERSION);
    app_strlcpy((kal_char*)MREVersion, (const kal_char*)tmpbuf, HPNS_MRE_VERSION_LEN);
#endif
    return 0;
}

int hpnsGetCapabilities(kal_uint32 *voiceCap, kal_uint32 *videoCap, kal_uint32 *imageCap, kal_uint32 *otherCap)
{
    return 0;
}

int hpnsGetDisplayMetrics(kal_uint16 *hSize, kal_uint16 *wSize)
{
    (*hSize) = LCD_HEIGHT;
    (*wSize) = LCD_WIDTH;
    return 0;
}

void hpnsGetChipSet(kal_int8 chipSet[])
{
    app_strlcpy((kal_char*)chipSet, PLATFORM, HPNS_CHIPSET_LEN);
}

int hpnsGetOSInfo(kal_int8 clientOS[])
{
    version_struct ver_struct;

    INT_VersionNumbers(&ver_struct);

    app_strlcpy((kal_char*)clientOS, (const kal_char*)ver_struct.mcu_sw_branch, 20);
    return 0;
}

int hpnsGetNwkNetAcctId()//get iap
{
    kal_int8 cbm_ret = CBM_OK;
    cbm_app_info_struct app_info;
    srv_dtcnt_sim_type_enum preferred_sim = SRV_DTCNT_SIM_TYPE_NONE;
    cbm_sim_id_enum simId;

    memset(&app_info, 0, sizeof(app_info));
	app_info.app_icon_id = GetRootTitleIcon(IMG_GLOBAL_OK);
	app_info.app_str_id = STR_GLOBAL_OK;
	app_info.app_type = DTCNT_APPTYPE_PUSH;//DTCNT_APPTYPE_MRE_WAP;
	if (g_hpns_app_id == 0) cbm_register_app_id_with_app_info(&app_info, &g_hpns_app_id);
    if(MMI_FALSE == srv_dtcnt_get_sim_preference(&preferred_sim))
    {
        preferred_sim = SRV_DTCNT_SIM_TYPE_1;
    }
    switch(preferred_sim)
    {
        case SRV_DTCNT_SIM_TYPE_1:
            simId = CBM_SIM_ID_SIM1;
            break;
        case SRV_DTCNT_SIM_TYPE_2:
            simId = CBM_SIM_ID_SIM2;
            break;
        case SRV_DTCNT_SIM_TYPE_3:
            simId = CBM_SIM_ID_SIM3;
            break;
        case SRV_DTCNT_SIM_TYPE_4:
            simId = CBM_SIM_ID_SIM4;
            break;
        default:
            simId = CBM_SIM_ID_SIM1;
            break;
    }
    g_hpns_aacount_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, simId, g_hpns_app_id, KAL_FALSE);
    cbm_ret = cbm_hold_bearer(cbm_get_app_id(g_hpns_aacount_id));
	kal_prompt_trace(MOD_NMS,"cbm_hold_bearer = %d",cbm_ret);

    HPNS_TRACE2(TRC_HPNS_d1f534a8f72542e2af02bb6c94f86942, g_hpns_app_id, g_hpns_aacount_id);
	return g_hpns_aacount_id;
}

kal_uint8 hpnsGetAppId()
{
    return g_hpns_app_id;
}

kal_uint32 hpnsGetAccountId()
{
    HPNS_TRACE1(TRC_HPNS_8cb4cf44effd4da8a3005b71d236dd4d, g_hpns_aacount_id);
    return g_hpns_aacount_id;
}

void hpnsInitAppId()
{
    g_hpns_app_id = 0;
    g_hpns_aacount_id = 0;
}

module_type hpnsGetTaskId()
{
    return MOD_NMS;
}

int hpnsGetAppStatisticsInfo(SHpnsAppStatistics  *hpnsAppStatistic)
{
    int ret = 0;
    
    if (!srv_pns_process_click_rate(hpnsAppStatistic))
    {
        ret = -1;
    }

    return ret;
}


int     hpnsGetAPName(kal_int8 APName[])
{
	//strcpy(APName, "xitang");
	return 0;
}

int     hpnsGetAPNType()
{
	return 1;
}
