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
#ifndef __HPNS_PLATFORM_H__
#define __HPNS_PLATFORM_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "MMIDataType.h"

#ifdef __arm
	#define  S64      long long
	#define  HPNS__packed __packed 
#else
	#define  S64 	 long
	#define  HPNS__packed 
#endif

#define HPNS_FILE_LEN           70
#define HPNS_DIRECTORY_LEN      40
#define HPNS_MAX_LOG_BUFFER     256
#define HPNS_SENDER_LEN         16
#define HPNS_REGID_LEN          12
#define HPNS_HID_LEN            8
#define HPNS_MAX_BUNDLE_APP_NUM 20

#define HPNS_SLASH              "\\"

typedef struct
{
    LOCAL_PARA_HDR

    unsigned int MsgType;
	char *pData;
	unsigned int DataLen;
}SNmsQueueMsgStruct;

/**************************************************************************************

                               ===========semphore API==============
              
***************************************************************************************/

/*===================================================================
* function: hpnsCreateSem(IN char *pName, IN unsigned int initNum);
* note: 
*	1. it is used to create a semaphore
*	2. it returns a pointer that point to semaphore address
*	3. In the parameters, pName is the semaphore name and initNum is semaphore number created
*	
=====================================================================*/
void *hpnsCreateSem(char *pName, unsigned int initNum);


/*===============================
* function: hpnsCloseSem(IN void *param) ;
* note: 
*	1. it is used to close a semaphore.
*	
================================*/
int   hpnsCloseSem(void *param) ;

/*===============================
* function: hpnsCloseSem(IN void *param) ;
* note: 
*	1. it is used to get a semaphore
*	
=================================*/
int   hpnsTakeSem(void *pSem);

/*================================
* function: hpnsCloseSem(IN void *param) ;
* note: 
*	1. it is used to free a semaphore
*	
==================================*/
int   hpnsGiveSem(void *pSem);	


/**************************************************************************************

                             ===========memory operation API==============
              
***************************************************************************************/
/*=============================================
* function: hpnsMallocL(IN kal_uint32 size)
* note: 
*	1. it is used to apply for memory, memory size is the parameters
*     2. It returns a pointer that point to the memory address.
*	
==============================================*/
void   *hpnsMallocL(kal_uint32 size);

/*=============================================
* function: hpnsFreeL(IN void* pMem)
* note: 
*	1. it is used to free the memory that has been allocated.
*	
==============================================*/
void    hpnsFreeL(void* pMem);
#define hpnsMemSet     memset
#define hpnsMemCpy     memcpy

/**************************************************************************************

                             ===========message queue API==============
              
***************************************************************************************/
/*=============================================
* function: hpnsSendMsgToEngineP(IN int mid, IN kal_uint8 *pMsg, IN int msgLen)
* note: 
*	1. it is used to send a message to Engine
*	2. In the parameters, mid is the message ID, pMsg is message 
*	     content, msgLen is message length.
*	
==============================================*/
int   hpnsSendMsgToEngineP(int mid, kal_uint8 *pMsg, int msgLen) ;

/*=============================================
* function: hpnsSendMsgToUIP(IN int mid, IN kal_uint8 *pMsg, IN int msgLen)
* note: 
*	1. it is used to send a message to UI
*     2. parameters is similar to hpnsSendMsgToEngineP().
*	
==============================================*/
int   hpnsSendMsgToUIP(int mid, kal_uint8 *pMsg, int msgLen) ; 

kal_uint32 hpnsHtonl(kal_uint32 x);
kal_uint32 hpnsNtohl(kal_uint32 x);
kal_uint16 hpnsHtons(kal_uint16 x);
kal_uint16 hpnsNtohs(kal_uint16 x);


/**************************************************************************************

                             ===========file operation API==============
              
***************************************************************************************/

typedef unsigned int           HFILE;

#define HPNS_FS_CREATE          0x00010000L
#define HPNS_FS_CREATE_ALWAYS   0x00020000L
#define HPNS_FS_READ            0x00000100L
#define HPNS_FS_READ_WRITE      0x00000000L

/*================================================
* function: hpnsFsOpen(IN char *name, IN kal_uint32 flag)
* note: 
*	1. it is used to open a file
*	2. In the parameters,  name is file name, flag refers to above definitions.
*	3. it returns file handle, and if error happens, return 0
*	
=================================================*/
HFILE   hpnsFsOpen(char *name,  kal_uint32 flag);

/*============================================================
* function: hpnsFsRead(IN HFILE hFile, OUT void *pData, IN int nLen, OUT int *Read);
* note: 
*	1. it is used to read from file
*	2. In the parameters, hFile is file handle, pData is a pointer that the read contents 
*	write to, len is the content length need to read, * read is the actual bytes being read, 
*	and it is the same to return number
*	
=============================================================*/
int     hpnsFsRead(HFILE hFile, void *pData, int nLen, int *Read);

/*============================================================
* function: hpnsFsWrite(IN HFILE hFile, IN void *pData, IN int nLen, OUT int *Written)
* note: 
*	1. it is used to write to file
*	2. In the parameters, hFile is file handle, pData is a pointer that the contents which want to 
*	write, len is the content length need to be written, * Written is the actual bytes being written, 
*	and it is the same to return number
*	
=============================================================*/
int     hpnsFsWrite(HFILE hFile, void *pData, int nLen, int *Written);


#define HPNS_FS_FILE_BEGIN      0
#define HPNS_FS_FILE_CURRENT    1
#define HPNS_FS_FILE_END        2
/*================================================
* function: hpnsFsSeek(IN HFILE hFile, IN int offset, IN int Whence)
* note: 
*	1. it is used to set the file position indicator for the stream.
*	2. parameters is similar to fseek();
*	
=================================================*/
int 	hpnsFsSeek(HFILE hFile, int offset, int Whence);

/*================================================
* function: hpnsFsFlush(IN HFILE hFile)
* note: 
*	1. it is used to  force  a  write  of all user-space buffered data 
*	similated  to fflush(). 
*	
=================================================*/
int     hpnsFsFlush(HFILE hFile) ;

/*================================================
* function: hpnsFsClose(IN HFILE hFile)
* note: 
*	1. it is used to  close file
*	
=================================================*/
void    hpnsFsClose(HFILE hFile);

/*================================================
* function: hpnsFsGetFileSizeWithName(IN char* filePath, OUT int* pSize)
* note: 
*	1. it is used to  get file size
*	2.  In the parameters,  filePath is file path and file name, pSize is the
*	file size, it is the same to return number
*	
=================================================*/
int     hpnsFsGetFileSizeWithName(char* filePath, int* pSize);

/*================================================
* function: hpnsFsFileExists(kal_int8* filename)
* note: 
*	1. it is used to check a file if exist
*	2. If return 1: exist; and return 0: not exist
*	
=================================================*/
int     hpnsFsFileExists(char* filename);



/**************************************************************************************

                             ===========device info API==============
              
***************************************************************************************/

/*================================================
* function: hpnsGetImsiImei(OUT kal_uint8 imsi[][20], OUT kal_uint8 *pImei)
* note: 
*	1. it is used to  get IMSI that the mobile uses and IMEI
*	
=================================================*/
void    hpnsGetImsiImei(kal_uint8 imsi[][20], kal_uint8 *pImei);

/*================================================
* function: hpnsGetMobileLanguage(void)
* note: 
*	1. it is used to get the mobile language,return the definition referred to hpnsMsg.h
*	
=================================================*/
kal_uint32  hpnsGetMobileLanguage(void);

/*================================================
* function: hpnsGetOSID(OUT kal_int8 clientOS[])
* note: 
*	1. it is used to get the OS info, the max length of clientOS is 20 bytes
*     2. if successful, it returns 0; or returns -1;
*	
=================================================*/
int     hpnsGetOSInfo(kal_int8 clientOS[]);

/*================================================
* function: hpnsGetLocationInfo(OUT float *latitude, OUT  float *longitude)
* note: 
*	1. it is used to get the location info,the max length of latitude is 16 byres
*     2.  if successful, it returns 0; or returns -1;
*	
=================================================*/
int     hpnsGetLocationInfo(kal_uint8 *latitude, kal_uint8 *longitude);

/*================================================
* function: hpnsGetMemoryConfig(OUT kal_uint32 *sizeOfRAM, OUT kal_uint32 *sizeOfROM)
* note: 
*	1. it is used to get memory config including RAM(M) and ROM(M)
*     2. if successful, it returns 0; or returns -1;
*	
=================================================*/
int  hpnsGetMemoryConfig(kal_uint32 *sizeOfRAM, kal_uint32 *sizeOfROM);

/*================================================
* function: hpnsGetMREVersionInfo(OUT kal_int8 MREVersion[])
* note: 
*	1. it is used to get the MRE version info, the max length of MREVersion is 16 bytes
*     2. if successful, it returns 0; or returns -1;
*	
=================================================*/
int     hpnsGetMREVersionInfo(kal_int8 MREVersion[]);

/*================================================
* function: hpnsGetCapabilities(kal_uint32 *voiceCap, kal_uint32 *videoCap, kal_uint32 *imageCap, kal_uint32	*otherCap )
* note: 
*	1. it is used to get the capabilities,the Audio/Video/Picture/Other related capabilities is
*       respectively represented by one integer defined by the platforms themselves.
*     2. if successful, it returns 0; or returns -1;
*	
=================================================*/
int     hpnsGetCapabilities(kal_uint32 *voiceCap, kal_uint32 *videoCap, kal_uint32 *imageCap, kal_uint32	*otherCap );

/*================================================
* function: hpnsGetDisplayMetrics(OUT kal_uint16 *hSize, OUT kal_uint16 *wSize)
* note: 
*	1. it is used to get the screen resolution 
*     2. if successful, it returns 0; or returns -1;
*	
=================================================*/
int     hpnsGetDisplayMetrics(kal_uint16 *hSize, kal_uint16 *wSize);

/*================================================
* function: hpnsGetChipSet(OUT kal_int8 chipSet[])
* note: 
*	1. it is used to get the chipset
*	
=================================================*/
void    hpnsGetChipSet(kal_int8 chipSet[]);

/*================================================
* function: hpnsGetMACAddress(OUT kal_int8 macAddr[])
* note: 
*	1. it is used to get the mobile MAC address
*	
=================================================*/
void    hpnsGetMACAddress(kal_int8 macAddr[]);

/*================================================
* function: hpnsGetAPName(kal_int8 APName[])
* note: 
*	1. it is used to get AP name , len is HPNS_AP_NAME_LEN
*	2. if successful, it returns 0; or returns -1;
=================================================*/
int     hpnsGetAPName(kal_int8 APName[]);

/*================================================
* function: hpnsGetAPNType(kal_int8 APName[])
* note: 
*#define HPNS_APN_DEFAULT                  0
*#define HPNS_APN_WIFI                     1
*#define HPNS_APN_GPRS                     2
*#define HPNS_APN_WCDMA                    3;
*it returns the above num
=================================================*/
int     hpnsGetAPNType(void);


/*================================================
* function: hpnsGetSystemTime(void)
* note: 
*	1. it is used to get seconds of the current system time in timeval struct
*	
=================================================*/
kal_uint32  hpnsGetSystemTime(void);

/*================================================
* function: hpnsGetUsecTime(void)
* note: 
*	1. it is used to get microseconds of the current system time in timeval struct.
*	
=================================================*/
kal_uint32  hpnsGetUsecTime(void);

/*================================================
* function: hpnsGetTimeStamp(void)
* note: 
*	1. it is used to get the current system time. But it returns a string
*	like "HH:MM:SS:UUU" .
*	
=================================================*/
char    *hpnsGetTimeStamp(void);
void    hpnsTrace(char* buf);

int hpnsGetNwkNetAcctId(void);

extern U16 GetRootTitleIcon(U16 ItemId);

extern U16 GetRootTitleIcon(U16 ItemId);

void hpnsInitAppId(void);

module_type hpnsGetTaskId(void);


#endif
