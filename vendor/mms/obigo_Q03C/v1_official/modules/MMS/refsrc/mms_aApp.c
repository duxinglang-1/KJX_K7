/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	mms_aApp.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for new MMS features 
 *   (ex: buffer send request, handle duplicate notification ,..).
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "kal_public_api.h" 

#include "msf_cfg.h"    
#include "msf_log.h"    
#include "msf_mem.h"
#include "msf_wid.h"
#include "msf_file.h"
#include "msf_dcvt.h"
#include "msf_core.h"
#include "msm.h"    
#include "msf_neta.h"

#include "mms_def.h"
#include "mms_cfg.h"
#include "mms_if.h"   
#include "mms_env.h" //Jo
#include "msig.h"
#include "mcpdu.h"
#include "mlpdup.h"
#include "mconfig.h"
#include "fldmgr.h"
#include "mmem.h"
#include "mms_aApp.h"
#include "mcwap.h"  
#include "mnotify.h"  

/* FS service */
#include "fs_type.h"
#include "fs_func.h"

#include "kal_public_defs.h" 
#include "stack_ltlcom.h"

#include "wapadp.h"
#include "wapdef.h"
#include "wap.h"
#include "wap_ps_struct.h"
#include "mma_api.h"    /* for the error of storage type enum in mma_def.h */
#include "mma_def.h"
#include "int_exec.h"
#include "mma_setting.h"
#include "EngineerModeInetAppGprot.h" /* Added for Engineer Mode */
#include "Msf_int.h"
typedef struct{
	MSF_BOOL used;
	MSF_UINT32  msgId;	
	MSF_UINT32	checksum1;	
	MSF_UINT32	checksum2;	
}MmsMessageFileInfo;


typedef struct 
{	 
	 MSF_UINT32 checkSum;	 
     MmsMessageFileInfo msg[1];    
 
}MmsMessageFileList;

#define SET_HIGH_BIT(a)  (unsigned char)((a) | (unsigned char)0x80)

#if MMS_TEMPLATES_DEMO_SUPPORT
#include "resource_audio.h"
#define mmsBufSize  1000

extern char *generateMmsTransactionId( MSF_UINT8 modId, unsigned long *length);
typedef enum
{
    MMS_IMAGE,
    MMS_AUDIO,
    MMS_TEXT    
} MmsMediaType; 
#endif

	 

/*************** Extern Functions ***************************************************/
extern MSF_UINT32 mmsWapGetCurrentAccountId(void);
extern int mms_get_disk_label(int type);




/*************** General Functions ***************************************************/
typedef struct {
    MSF_UINT32 msgId;
    MSF_UINT32 size; 
    char fileName[MMS_FILE_LEN]; 
	char suffix;
} mmsFileInFolder;

MSF_UINT32       fileName2MsgId(char *fName);
static int              atox(char *str); 
static mmsFileInFolder  *folderFiles; 
static int			    noOfFiles;						

/*************** For handling duplicate received messages ****************************/
#if MMS_CHECK_DUPLICATE_NOTIFICATION
static MSF_BOOL         getMMSFolderInfo(void);
static void             fileName2Suffix(char *fName, char *suffix);
static char             fullName[MMS_PATH_LEN + 2];                
static char*            getFilePath(const char *fName, char *pathBuf); 
static MSF_BOOL         cmpMsgConetent(MmsMsgId NewMsgID, MmsMsgId OldMsgID, 
									   MmsMessageType chkMsgType, void* data);
static MSF_BOOL         readHeader(int fileHandle, char* buff, int buffsize);
static MSF_INT32        getIndexFromFolderFiles(MmsMsgId chkMsgID,MmsFileType suffix);
static char*            getHeaderItem(MmsMsgId chkMsgID, MmsFileType suffix,MmsHeaderTag wantHeaderTag);
#endif


/**************** For buffering send request mechanism *******************************/

/************************************************************************************************
*
*
*
*                                      General Functions
*
*
*
************************************************************************************************/



/************************************************************************
* FUNCTION                                                            
*	loadMmsDataToBuffer(MSF_UINT8 modId, MmsMsgId msgId,char suffix,char **buffer, int *bufSize)
*
* DESCRIPTION                                                           
*	Load data of a mms file into memory. 
*	Note that the size of mms file msut be lower than MMS_MAX_CHUNK_SIZE.
*
* CALLS  
*                           
* PARAMETERS
*	MSF_UINT8 modId, MmsMsgId msgId,char suffix,char **buffer, int *bufSize
* RETURNS
*	TRUE or FALSE
* GLOBALS AFFECTED
* 	Write buffer address and buffer size to buffer and bufSize if file read operation works
*************************************************************************/
MSF_BOOL loadMmsDataToBuffer(MSF_UINT8 modId, MmsMsgId msgId,char suffix,char **buffer, int *bufSize)
{
	char filepath[MMS_PATH_LEN + 2];
	int openMode=HDI_FILE_SET_RDONLY; 
   	int fileHandle=-1;
    	int fileSize=0;
       
	/* Create a full file path */
    	memset(filepath,0x00,MMS_PATH_LEN + 2);
	sprintf(filepath,"%s%lx.%c",MMS_PDU_FOLDER,msgId,suffix);

	fileHandle = MSF_FILE_OPEN_EXT( modId,filepath,openMode, 0,(msf_mms_storage_enum)0);
	if(fileHandle>=0)
	{
		if((fileSize=MSF_FILE_GETSIZE_EXT(filepath,(msf_mms_storage_enum)0))>=MMS_MAX_CHUNK_SIZE)
		{
			fileSize=MMS_MAX_CHUNK_SIZE;
		}        
		if(fileSize<=0||(*buffer=(char *)MSF_MEM_ALLOC(modId,fileSize))==NULL)
		{
			MSF_FILE_CLOSE(fileHandle);
			return FALSE;
		}
        	else if(fileSize!=(MSF_INT32)MSF_FILE_READ(fileHandle,*buffer,fileSize))
		{
			MSF_MEM_FREE(modId,*buffer);
			*buffer=NULL;
			MSF_FILE_CLOSE(fileHandle);
			return FALSE;
		}
              	MSF_FILE_CLOSE(fileHandle);
	}
	*bufSize=fileSize;
	return TRUE;
	
}

/************************************************************************
* FUNCTION                                                            
*	fileName2MsgId
*
* DESCRIPTION                                                           
*  This local function is used to extract the MSF_UINT32 msgId from a file name (ex:1a.s).
*
* CALLS  
*   checkDuplicateMsg                      
* PARAMETERS
*	*fname
* RETURNS
*	MSF_UINT32 msgId
* GLOBALS AFFECTED
*   None
*************************************************************************/
MSF_UINT32 fileName2MsgId(char *fName)
{
  char *dot; 
  char tmpFileName[MMS_FILE_LEN]; 

  dot = strchr (fName,'.' );
  if (dot != NULL)
  {
      strncpy(tmpFileName, fName, (unsigned int)dot - (unsigned int)fName);
      tmpFileName[(int)dot - (int)fName] = '\0';
  
      return (MSF_UINT32)atox(tmpFileName);
  }
  else
  {
      return 0;
  } 
} 

/************************************************************************
* FUNCTION                                                                                                                   
*	atox
*
* DESCRIPTION                                                           
*  This local function is used to transfer a hexadecimal string to integer.
*
* CALLS  
*   fileName2MsgId                       
* PARAMETERS
*	*str
* RETURNS
*	None
* GLOBALS AFFECTED
*   None
*************************************************************************/
static int atox(char *str)        
{
    int num = 0;   
    int neg = 0;     

    while (*str == '-') 
    {
        str++;
        neg = !neg;
    } 
 
    while (*str != '\0') 
    {
        if ( (*str < '0') && (*str > 'f') && ((*str >= 'a') && (*str <= '9')))                     
        {
            break;
        } 
                 
        if (*str <= '9')
        {
            num = (16 * num) + (*str - '0');
        }
        else
        {
            num = (16 * num) + (*str - 87);
        }
        str++;
    } 
 
    return (neg ? -num : num);
} 
/************************************************************************
* FUNCTION                                                            
*	IsReachMaxNumofMsg(MSF_UINT32 MMS_MAX_NO_OF_MSG)
*
* DESCRIPTION                                                           
*	Check if the current number of mms message in MMS folder is reached to the threshold value 
*
* CALLS  
*                           
* PARAMETERS
*	MSF_UINT32 mmsNoMaxMSG
* RETURNS
*	TRUE or FALSE
* GLOBALS AFFECTED
* 	None
*************************************************************************/
/*
MSF_BOOL IsReachMaxNumofMsg(MSF_UINT32 mmsNoMaxMSG)
{
	MSF_UINT32 NoOfMsg;
	NoOfMsg=MMS_MAX_NO_OF_MSG-fldrGetNoOfFreeMsg();
	
	if(NoOfMsg>=mmsNoMaxMSG)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}	
}
*/

#if !defined(__MTK_TARGET__)||MMS_CHECK_DUPLICATE_NOTIFICATION
/************************************************************************
* FUNCTION                                                            
*	fileName2Suffix
*
* DESCRIPTION                                                           
*  This local function is used to extract the suffix from a file name (ex:1a.s).
*
* CALLS  
*   checkDuplicateMsg                      
* PARAMETERS
*	*fname, *suffix
* RETURNS
*	None
* GLOBALS AFFECTED
*   It store the result to suffix.
*************************************************************************/
static void fileName2Suffix(char *fName, char *suffix)
{
  char *dot;
  dot=strchr (fName,'.');
  if (dot != NULL)
  {
      strncpy(suffix, dot+1, 1); 
      
  }
} 
static MSF_BOOL getMMSFolderInfo()
{   
   int i=0,j=0;
   int type = 0;
   int size = 0;
   int dirHandle=-1;   
   folderFiles=NULL;
   noOfFiles=0;
   
   if(folderFiles)
   {
	   MMS_FREE(folderFiles);   
   }
   noOfFiles =  MSF_FILE_GETSIZE_DIR_EXT (MMS_SYS_FOLDER, MSF_MMS_STORAGE_PHONE);
   if(noOfFiles<=0)
	   return FALSE;
   folderFiles = (mmsFileInFolder*)MMS_CALLOC(sizeof(mmsFileInFolder) *
        (unsigned int)noOfFiles);

	//filter the messages "mms.cn", "mms.bak" and "mms.cn"  GH_Comment 031201
    for (i = 0; i < noOfFiles; i++)
    {
        if ( (MSF_FILE_READ_DIR_SEQ_EXT(MMS_SYS_FOLDER, i, folderFiles[j].fileName,
            MMS_FILE_LEN, &type, &size, &dirHandle, (msf_mms_storage_enum)0) == MSF_FILE_OK) &&
            (msf_cmmn_strcmp_nc(folderFiles[j].fileName, MMS_MMT) != 0) && 
            (msf_cmmn_strcmp_nc(folderFiles[j].fileName, MMS_MMTBACK) != 0) &&
            (msf_cmmn_strcmp_nc(folderFiles[j].fileName, MMS_MMTTMP) != 0))
        {
            folderFiles[j].size=size;
			j++;   
        } 
    }
    MSF_FILE_READ_DIR_SEQ_CLOSE(&dirHandle);
    noOfFiles = j; 

	for (i = 0; i < noOfFiles; i++)
    {
        folderFiles[i].msgId = fileName2MsgId(folderFiles[i].fileName);   
        fileName2Suffix(folderFiles[i].fileName, &folderFiles[i].suffix);
        
    } 
	return TRUE;
}
#endif

#if MMS_CHECK_DUPLICATE_NOTIFICATION
static char* getFilePath(const char *fName, char *pathBuf) 
{
    strcpy(pathBuf, MMS_PDU_FOLDER); 
    strcat(pathBuf + strlen(MMS_PDU_FOLDER), fName);
    return pathBuf;
} 
/************************************************************************
* FUNCTION                                                            
*	checkDuplicateMsg
*
* DESCRIPTION                                                           
*  This function will check if the specific mms message has duplicate mms messages in the MMS folder. 
*  It finds them and deletes them.
* CALLS  
*   MMSa_newMessage                       
* PARAMETERS
*	MmsMsgId, MmsMessageType
* RETURNS
*	None
* GLOBALS AFFECTED
*   It deletes all duplicate mms messages.
*************************************************************************/
void checkDuplicateMsg(unsigned long chkMsgID,int chkMsgType){
   
   int i;
   char *mkey=NULL;

   
    if(!getMMSFolderInfo())
		return;

	if(chkMsgType == MMS_SUFFIX_NOTIFICATION)
    {
        mkey=getHeaderItem(chkMsgID,MMS_SUFFIX_NOTIFICATION,X_MMS_CONTENT_LOCATION);								
		if(mkey!=NULL)
	    {
		    for (i = 0; i < noOfFiles; i++)
		    {
			    if((folderFiles[i].suffix==chkMsgType)&&(chkMsgID!=folderFiles[i].msgId))
			    {
				    cmpMsgConetent(chkMsgID,folderFiles[i].msgId,(MmsMessageType)chkMsgType,mkey);			    				
    				    
			    }
		    }
	    }
        
    }

	MMS_FREE(folderFiles);
	if(mkey!=NULL)
		MMS_FREE(mkey);
	
}

/************************************************************************
* FUNCTION                                                            
*	readHeader
*
* DESCRIPTION                                                           
*  This local function is used to read data from the mms fils including notify, read and delivery report.
*
* CALLS  
*   getHeaderItem                      
* PARAMETERS
*	filehandle, buff, buffSize
* RETURNS
*	None
* GLOBALS AFFECTED
*   None
*************************************************************************/
static MSF_BOOL readHeader(int fileHandle, char* buff, int buffsize){
	
	int size=buffsize;
	int ret;
	int position=0;
	for (;;){
		if (size <= 0) // We have read everything that we should 
		{       		          			
			return TRUE;
		}
		ret = MSF_FILE_READ( fileHandle, buff, size);	
		position += ret;
        size -= ret;
	      			 
     }
}


/*************************************************************************
* FUNCTION                                                            
*	getIndexFromFolderFiles
*
* DESCRIPTION                                                           
*  This function is used to get the index of folderFiles for the specific msgId.
*
* CALLS  
*   getHeaderItem                       
* PARAMETERS
*	MmsMsgId
* RETURNS
*	Index
* GLOBALS AFFECTED
*   None
*************************************************************************/
static MSF_INT32 getIndexFromFolderFiles(MmsMsgId chkMsgID,MmsFileType suffix){
	int i;
	for(i=0;i<noOfFiles;i++)
	{
		if((folderFiles[i].msgId==chkMsgID)&&(folderFiles[i].suffix==suffix))
			return i;
	}
	return -1;
} 



/*************************************************************************
* FUNCTION                                                            
*	getHeaderItem
*
* DESCRIPTION                                                           
*  This function is used to get the specific header field from the one mms file.
*
* CALLS  
*   cmpMsgConetent, checkDuplicateMsg                        
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/
static char* getHeaderItem(MmsMsgId chkMsgID, MmsFileType suffix, MmsHeaderTag wantHeaderTag){

    	int fileHandle;
	int openMode;
	MSF_UINT32 length;
    	int index=getIndexFromFolderFiles(chkMsgID,suffix);
	char* buff;
	char *output=NULL;
	MmsHeaderValue cntLocation;	

	if(index>=0){
		length=folderFiles[index].size;
		buff = MMS_CALLOC(folderFiles[index].size);
		
		openMode=MSF_FILE_SET_RDONLY|HDI_FILE_SET_CUSTOM_BLOCKING;
		fileHandle = MSF_FILE_OPEN_EXT( MSF_MODID_MMS,
		    		getFilePath(folderFiles[index].fileName,fullName), 
					openMode, 0, (msf_mms_storage_enum)0);								
        memset(fullName,0x00,MMS_PATH_LEN+2);
	
		if(fileHandle >= 0){
			if(readHeader(fileHandle,buff,length))
			{	
				switch(wantHeaderTag)
				{					
					case X_MMS_CONTENT_LOCATION:
						{							
							if (!mmsPduGet( buff, length, X_MMS_CONTENT_LOCATION, &cntLocation))
							{
							MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, 
							MMS_AAPP_0989B2588E970425072E7857CCD7BBE4, "%s(%d): No X_MMS_CONTENT_LOCATION tag\n", __FILE__, __LINE__));
								output=NULL;
								break;
							}							
							if((char*)cntLocation.contentLocation)
							{
								output=MMS_CALLOC(strlen((char *)cntLocation.contentLocation)+1);
								if(output)
									strcpy(output,(char*)cntLocation.contentLocation);
			
						}							
						break;
					}
				}									
			}
			MMS_FREE(buff);
			MSF_FILE_CLOSE(fileHandle);
		}
	}
	return output;
}

/*************************************************************************
* FUNCTION                                                            
*	cmpMsgConetent
*
* DESCRIPTION                                                           
*  This function is used to check if two mms messages are duplicate.
*  If so, it deletes the old mms message and keeps the latest one.
*
* CALLS  
*   cmpMsgConetent, checkDuplicateMsg                        
* PARAMETERS
*	MsgId_A, MsgId_B, MmsMessageType, 
* RETURNS
*	TRUE or FALSE
* GLOBALS AFFECTED
*	None
*   
*************************************************************************/
static MSF_BOOL cmpMsgConetent(MmsMsgId NewMsgID, MmsMsgId OldMsgID, MmsMessageType chkMsgType, void* data){
    
    char *oldCntLocate=NULL;
    MSF_BOOL ret=FALSE;
    
    if(chkMsgType == MMS_SUFFIX_NOTIFICATION)
    {
        oldCntLocate=getHeaderItem(OldMsgID,MMS_SUFFIX_NOTIFICATION,X_MMS_CONTENT_LOCATION);
		if((data!=NULL)&&(oldCntLocate!=NULL))
		{            
			if(msf_cmmn_strcmp_nc((char*)data, oldCntLocate)==0)
			{
				//delete the new M-Notification.ind message file
				fldrMgrDeleteMessage(NewMsgID, MMS_SUFFIX_NOTIFICATION, MSF_MMS_STORAGE_PHONE); // Sandeep: Check This
				ret=TRUE;						
			}
			MMS_FREE(oldCntLocate);
		}			
    }							
	return ret;
}
#endif




/************************************************************************
* FUNCTION                                                            
*  mmsa_get_max_mms_get_retry_num
* DESCRIPTION                                                           
*  This function is to get customized retry time except for CSD case.
* PARAMETERS
*  void
* RETURNS
*  void
*************************************************************************/
int mmsa_get_max_mms_get_retry_num(void)
{
    int retry = ((MSF_NETWORK_ACCOUNT_GET_BEARER(mmsWapGetCurrentAccountId()) == HDI_SOCKET_BEARER_GSM_CSD) ?
        0 : wap_custom_get_max_mms_get_retry_nums());
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_93D532AA37A1CA00F898E5C2475FA8E6, "mmsa_get_max_mms_get_retry_num() = %d", retry));
    return retry;
}

/************************************************************************
* FUNCTION                                                            
*  mmsa_get_max_mms_post_pdu_retry_num
* DESCRIPTION                                                           
*  This function is to get customized retry time except for CSD case.
* PARAMETERS
*  void
* RETURNS
*  void
*************************************************************************/
int mmsa_get_max_mms_post_pdu_retry_num(void)
{
    int retry = ((MSF_NETWORK_ACCOUNT_GET_BEARER(mmsWapGetCurrentAccountId()) == HDI_SOCKET_BEARER_GSM_CSD) ?
        0 : wap_custom_get_max_mms_post_pdu_retry_nums());
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_E4ADD0BEFDF7883106E54A9DFB13D298, "wap_custom_get_max_mms_post_pdu_retry_nums() = %d", retry));
    return retry;
}

/************************************************************************
* FUNCTION                                                            
*  mmsa_get_max_mms_post_msg_retry_num
* DESCRIPTION                                                           
*  This function is to get customized retry time except for CSD case.
* PARAMETERS
*  void
* RETURNS
*  void
*************************************************************************/
int mmsa_get_max_mms_post_msg_retry_num(void)
{
    int retry = ((MSF_NETWORK_ACCOUNT_GET_BEARER(mmsWapGetCurrentAccountId()) == HDI_SOCKET_BEARER_GSM_CSD) ?
        0 : wap_custom_get_max_mms_post_msg_retry_nums());
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_E4ADD0BEFDF7883106E54A9DFB13D298, "wap_custom_get_max_mms_post_pdu_retry_nums() = %d", retry));
    return retry;
}

/************************************************************************
* FUNCTION                                                            
*	mmsGetFreeSpace(void)
*
* DESCRIPTION                                                           
*	It is used to get disk free size for MMS storage
*
* PARAMETERS
* RETURNS
*   Free size in bytes
* GLOBALS AFFECTED
*************************************************************************/
MSF_UINT32 mmsGetFreeSpace(MSF_UINT8 storageType)
{
        /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR wpath[16] = {0};
    char path[16] = {0};
    FS_DiskInfo diskinfo = {0};
    MSF_UINT32 freebytes = 0;
    int drive_letter;

#if defined(__FS_QM_SUPPORT__) && !defined(MMS_IN_LARGE_STORAGE)
    int ret = 0;
#endif 
    drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (storageType == MSF_MMS_STORAGE_PHONE)
    {
#ifdef MMS_IN_LARGE_STORAGE
    /* Order: 1. Invisible NAND 2. Visible NAND 3. visible NOR 4. Invisible NOR */
        drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
#endif /* MMS_IN_LARGE_STORAGE */ 
        kal_wsprintf(wpath, "%c:\\", (char)drive_letter);
        sprintf(path, "%c:\\@mms\\", (char)drive_letter);

#if !defined(MMS_IN_LARGE_STORAGE)
#if defined(__FS_QM_SUPPORT__)
        ret = FS_QmGetFree((BYTE*) "Z:\\@mms\\");
        if (ret < 0)
        {
            freebytes = 0;
        }
        else
        {
            freebytes = ret;
        }
#else /* defined(__FS_QM_SUPPORT__) */ 
        if (FS_GetDiskInfo(wpath, &diskinfo, FS_DI_FREE_SPACE | FS_DI_BASIC_INFO) >= 0)
        {
            freebytes = diskinfo.FreeClusters * diskinfo.SectorsPerCluster * diskinfo.BytesPerSector;
        }
#endif /* defined(__FS_QM_SUPPORT__) */ 

#elif defined(MMS_IN_LARGE_STORAGE)
        if (FS_GetDiskInfo(wpath, &diskinfo, FS_DI_FREE_SPACE | FS_DI_BASIC_INFO) >= 0)
        {
            freebytes = diskinfo.FreeClusters * diskinfo.SectorsPerCluster * diskinfo.BytesPerSector;
        }

#endif /* defined(__FS_QM_SUPPORT__) && !defined(MMS_IN_LARGE_STORAGE) */
    }
    else if (storageType == MSF_MMS_STORAGE_MEM_CARD_1) /* Check if there is need to check for card plug-in ststus*/
    {
        drive_letter = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
        if (drive_letter >= 0)
        {
            kal_wsprintf(wpath, "%c:\\", (char)drive_letter);
            if (FS_GetDiskInfo(wpath, &diskinfo, FS_DI_FREE_SPACE | FS_DI_BASIC_INFO) >= 0)
            {
                freebytes = diskinfo.FreeClusters * diskinfo.SectorsPerCluster * diskinfo.BytesPerSector;
            }
        }
    }

    if (freebytes >= 0xFFFFFFFF)
    {
        freebytes = 0xFFFFFFFF;
    }
    return (MSF_UINT32) freebytes;
}


/************************************************************************
* FUNCTION                                                            
*    MMSa_getDriveLetter
* DESCRIPTION                                                           
*    To provide the Drive letter for the storage type
* PARAMETERS
*    storage_type
* RETURNS
*    char
*************************************************************************/
char MMSa_getDriveLetter(MSF_UINT8 storage_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char mms_disk = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(storage_type > MSF_MMS_STORAGE_PHONE && storage_type < MSF_MMS_STORAGE_NONE)
	{				
		mms_disk = (char)FS_GetDrive(FS_DRIVE_V_REMOVABLE, storage_type, FS_NO_ALT_DRIVE);
        return mms_disk;
	}

    if(storage_type == MSF_MMS_STORAGE_PHONE)
	{
#ifdef MMS_IN_LARGE_STORAGE
        mms_disk = (char)mms_get_disk_label(MMS_STORAGE_PUBLIC);
#else					
        mms_disk = (char)mms_get_disk_label(MMS_STORAGE_SYSTEM);
#endif /*MMS_IN_LARGE_STORAGE*/
    }	
    return mms_disk;
}

/************************************************************************
* FUNCTION                                                            
*	mmsa_getRoamingmode(simId)
*
* DESCRIPTION                                                           
*	It is used to get Roaming retrival mode
*
* PARAMETERS
* RETURNS
*   retrival mode
* GLOBALS AFFECTED
*************************************************************************/
MSF_UINT32 mmsa_getRoamingmode(MSF_UINT8 simId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(mma_setting_is_roaming(simId))
    {
        return MMS_ROAMING;
    }
    else
    {
        return MMS_NOT_ROAMING;
    }
}

/************************************************************************
* FUNCTION                                                            
*	mmsa_getProfileStrParam(simId)
*
* DESCRIPTION                                                           
*	get Profile String value
*
* PARAMETERS
* RETURNS
*  
*************************************************************************/
char * mmsa_getProfileStrParam(MSF_UINT8 param, MSF_UINT8 simId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_setting_profile_struct * prof_p;  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prof_p = mma_setting_get_profile(simId);
    
    switch(param)
    {
        case MMS_CFG_GW_ADDRESS:
            return (char*)prof_p->proxy_addr;
        case MMS_CFG_GW_USERNAME:
            return (char*)prof_p->username;
        case MMS_CFG_GW_PASSWORD:
            return (char*)prof_p->password;
        case MMS_CFG_GW_REALM:
            return MMS_DEFAULT_GW_REALM;
        case MMS_CFG_PROXY_RELAY:
            return (char*)prof_p->mmsc_url_server;
        case MMS_CFG_POST_URI:
            return (char*)prof_p->mmsc_url_uri;
        case MMS_CFG_PROXY_RELAY_SCHEME:
            return (char*)prof_p->mmsc_url_scheme;
    }
    return NULL;
}

/************************************************************************
* FUNCTION                                                            
*	mmsa_getProfileIntParam(simId)
*
* DESCRIPTION                                                           
*	get Profile Int value
*
* PARAMETERS
* RETURNS
*  
*************************************************************************/
MSF_UINT32 mmsa_getProfileIntParam(MSF_UINT8 param, MSF_UINT8 simId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_setting_profile_struct * prof_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prof_p = mma_setting_get_profile(simId);
    switch(param)
    {
        case MMS_CFG_STK_CONNECTION_TYPE:
            return prof_p->connection_type;
        case MMS_CFG_GW_HTTP_PORT:
            return prof_p->proxy_port;
        case MMS_CFG_NETWORK_ACCOUNT:
            return prof_p->data_account;
        case MMS_CFG_GW_SECURE_PORT:
            return MMS_DEFAULT_GW_SECURE_PORT;
        case MMS_CFG_PORT:
            return prof_p->mmsc_url_port;
    }
    return 0;
}

/************************************************************************
* FUNCTION                                                            
*	mmsa_getProfileStrParam(simId)
*
* DESCRIPTION                                                           
*	get Profile String value
*
* PARAMETERS
* RETURNS
*  
*************************************************************************/
char * mmsa_getSettingStrParam(MSF_UINT8 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param)
    {
        case MMS_CFG_FROM_NAME:
            return "";
        case MMS_CFG_FROM_ADDRESS:
            return "";
        case MMS_CFG_CLIENT_USER_AGENT:
            return (char*)mma_setting_get_user_agent();
        case MMS_CFG_CLIENT_HTTP_HEADER:
            return  (MSF_INT8*) MMS_DEFAULT_CLIENT_HTTP_HEADER;
        case MMS_CFG_CLIENT_USER_AGENT_PROFILE:
            return (char*)mma_setting_get_user_prof();
        case MMS_CFG_IMMEDIATE_RETRIEVAL_SERVER:
            return MMS_DEFAULT_IMMEDIATE_RETRIEVAL_SERVER;
    }
    return NULL;
}

/************************************************************************
* FUNCTION                                                            
*	mmsa_getSettingIntParam(simId)
*
* DESCRIPTION                                                           
*	get Profile Int value
*
* PARAMETERS
* RETURNS
*  
*************************************************************************/
MSF_UINT32 mmsa_getSettingIntParam(MSF_UINT8 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT32 value;
    wap_mma_set_setting_req_struct * set_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    set_p = mma_setting_get_settings();
    switch(param)
    {
        case MMS_CFG_PROXY_RELAY_VERSION:
            if (set_p->mms_version == MMI_EM_INET_MMS_VERSION_10)
            {
                return MMS_VERSION_10;
            }
            else if (set_p->mms_version == MMI_EM_INET_MMS_VERSION_11)
            {
                return MMS_VERSION_11;
            }
            else if (set_p->mms_version == MMI_EM_INET_MMS_VERSION_12)
            {
                return MMS_VERSION_12;
            }
            else
            {
                return MMS_VERSION_11;
            }
        case MMS_CFG_ROAMING_MODE:
                value = set_p->retrieval_setting.roaming;
                if (value == MMA_RETRIEVAL_MODE_AS_HOME)
                {
                    value = set_p->retrieval_setting.home_network;
                }
                if (value == MMA_RETRIEVAL_MODE_IMMED)
                {
                    return MMS_ROAM_DEFAULT;
                }
                else if (value == MMA_RETRIEVAL_MODE_DEFERRED)
                {
                    return MMS_ROAM_DELAYED;
                }
                else if (value == MMA_RETRIEVAL_MODE_REJECT)
                {
                    return MMS_ROAM_REJECT;
                }
                break;
        case MMS_CFG_RETRIEVAL_MODE:
            value = set_p->retrieval_setting.home_network;
            if (value == MMA_RETRIEVAL_MODE_IMMED)
            {
                return MMS_RETRIEVE_IMMEDIATE;
            }
            else if (value == MMA_RETRIEVAL_MODE_DEFERRED)
            {
                return MMS_RETRIEVE_DELAYED;
            }
            else if (value == MMA_RETRIEVAL_MODE_REJECT)
            {
                return MMS_RETRIEVE_REJECT;
            }
            break;
        case MMS_CFG_ANONYMOUS_SENDER:
            value = set_p->retrieval_setting.anonymous_filter;
            return (value == 0)? 1: 0; /* change due to opposit enum in app */
        case MMS_CFG_CLASS_PERSONAL:
            return TRUE; 
        case MMS_CFG_CLASS_ADVERTISEMENT:
            value = set_p->retrieval_setting.advertisement_filter;
            return (value == 0)? 1: 0;
        case MMS_CFG_CLASS_INFORMATIONAL:
            return TRUE; 
        case MMS_CFG_CLASS_AUTO:
            return TRUE; 
        case MMS_CFG_MAX_RETRIEVAL_SIZE:
            return mma_setting_get_max_retrival_size();
        case MMS_CFG_REPORT_ALLOWED:
            if (set_p->retrieval_setting.delivery_report == KAL_TRUE)
            {
                return MMS_DELIVERY_REPORT_YES;
            }
            else
            {
                return MMS_DELIVERY_REPORT_NO;
            }
    }
    return 0;
}

/************************************************************************
* FUNCTION                                                            
*	mmsa_getGeneralIntParam(simId)
*
* DESCRIPTION                                                           
*	get Profile Int value
*
* PARAMETERS
* RETURNS
*  
*************************************************************************/
MSF_UINT32 mmsa_getGeneralIntParam(MSF_UINT8 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param)
    {
        case MMS_CFG_TREAT_AS_DELAYED_RETRIEVAL:
            return (MSF_UINT32)TRUE;
        case MMS_CFG_FROM_ADDRESS_TYPE:
            return (MSF_UINT32)MMS_PLMN;
        case MMS_CFG_FROM_ADDRESS_INSERT_TYPE:
            return (MSF_UINT32)MMS_FROM_INSERT_ADDRESS;   
        case MMS_CFG_DISCONNECT_ON_IDLE:
            return (MSF_UINT32)MMS_DEFAULT_DISCONNECT_ON_IDLE; 
        case MMS_CFG_NOTIF_MATCH_TO_MMSC:
            return MMS_DEFAULT_NOTIF_MATCH_TO_MMSC;
    }   
    return 0;
}

/************************************************************************
* FUNCTION                                                            
*	mmsa_getReadReportStrParam(simId)
*
* DESCRIPTION                                                           
*	get Profile String value
*
* PARAMETERS
* RETURNS
*  
*************************************************************************/
char * mmsa_getReadReportStrParam(MSF_UINT8 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_setting_read_report_res_struct value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    value = mma_setting_get_rr_settings();
    switch(param)
    {
        case MMS_CFG_TEXT_READ:
            return (char*)value.rr_text_read;
        case MMS_CFG_TEXT_YOUR_MSG:
            return (char*)value.rr_text_your_msg;
        case MMS_CFG_TEXT_FROM:
            return (char*)value.rr_text_from;
        case MMS_CFG_TEXT_TO:
            return (char*)value.rr_text_to;
        case MMS_CFG_TEXT_MSGID:
            return (char*)value.rr_text_msgId;
        case MMS_CFG_TEXT_SUBJECT:
            return (char*)value.rr_text_subject;
        case MMS_CFG_TEXT_SENT:
            return (char*)value.rr_text_sent;
        case MMS_CFG_TEXT_WAS_READ:
            return (char*)value.rr_text_was_read;
    }
    return NULL;
}

/************************************************************************
* FUNCTION                                                            
*	mmsa_profile_updated()
*
* DESCRIPTION                                                           
*	get Proxy Relay value
*
* PARAMETERS
* RETURNS
*  MMS size
* GLOBALS AFFECTED
*************************************************************************/
void mmsa_profile_updated(MSF_UINT8 simId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmsWapChannelDisconnect((MmsSimCardEnum)simId);
  
}
