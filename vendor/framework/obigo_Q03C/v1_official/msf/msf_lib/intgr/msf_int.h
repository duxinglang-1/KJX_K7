/*
 * Copyright (C) Teleca AB, 2002-2007.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * msf_int.h
 *
 * Created by Ingmar Persson
 *
 * Revision  history:
 * 
 *
 */

#ifndef _msf_int_h
#define _msf_int_h

#include "kal_general_types.h"

#ifndef _msf_def_h
#include "msf_def.h"
#endif
#ifndef _msf_cfg_h
#include "msf_cfg.h"
#endif

#include "msf_wid.h"

/**********************************************************************
 * Messaging
 **********************************************************************/

#define HDI_SIGNAL_OK                    0
#define HDI_SIGNAL_ERROR_QUEUE_FULL     -1
#define HDI_SIGNAL_ERROR_QUEUE_UNKNOWN  -2

void
gmms_HDIa_signalRegisterQueue (MSF_UINT8 modId);

void
gmms_HDIa_signalDeregisterQueue (MSF_UINT8 modId);

void*
gmms_HDIa_signalAllocMemory (MSF_UINT16 signalLength);

void
gmms_HDIa_signalFreeMemory (void* signalData);

#ifdef MSF_SIGNAL_API_REVISED
int gmms_HDIa_signalSend(MSF_UINT8 modId, void *signalData);
#else
int gmms_HDIa_signalSend(MSF_UINT8 modId, void *signalData, MSF_UINT16 signalDataLength);
#endif

void*
gmms_HDIa_signalRetrieve (MSF_UINT8 destModId);

int
gmms_HDIa_signalQueueLength (MSF_UINT8 modId);


/**********************************************************************
 * Named Pipes
 **********************************************************************/

/* Notification types */
#define HDI_PIPE_EVENT_CLOSED                     1
#define HDI_PIPE_EVENT_READ                       2
#define HDI_PIPE_EVENT_WRITE                      3

#ifdef NEW_PIPE_ERROR_EVENT
#define HDI_PIPE_EVENT_CLOSED_ERROR               4
#endif

/* Error codes */
#define HDI_PIPE_ERROR_BAD_HANDLE                 -1
#define HDI_PIPE_ERROR_INVALID_PARAM              -2
#define HDI_PIPE_ERROR_EXISTS                     -3
#define HDI_PIPE_ERROR_IS_OPEN                    -4
#define HDI_PIPE_ERROR_DELAYED                    -5
#define HDI_PIPE_ERROR_RESOURCE_LIMIT             -6
#define HDI_PIPE_ERROR_CLOSED                     -7
#define HDI_PIPE_ERROR_NOT_FOUND                  -8

#ifdef NEW_PIPE_ERROR_EVENT
#define HDI_PIPE_ERROR_CLOSED_ERROR               -9
#endif

int
gmms_HDIa_pipeCreate (MSF_UINT8 modId, const char* name);

int
gmms_HDIa_pipeOpen (MSF_UINT8 modId, const char *name);

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifdef WAP_DOWNLOAD_SPEEDUP
int
HDIa_pipeOpenExtended (MSF_UINT8 modId, const char *name);
#endif
#endif/*Q03C_IND_MOD_ARCH_SUPPORT*/

int
gmms_HDIa_pipeClose (int handle);
int
gmms_HDIa_pipeCloseExt (int handle,int errormode);

#ifdef NEW_PIPE_ERROR_EVENT
int
gmms_HDIa_pipeCloseError (int handle);
#endif

int
gmms_HDIa_pipeDelete (const char* name);

long
gmms_HDIa_pipe_ext (int handle, void* buf, long bufSize,int mode);

long
gmms_HDIa_pipeRead (int handle, void* buf, long bufSize);

long
gmms_HDIa_pipeWrite (int handle, void* buf, long bufSize);

int
gmms_HDIa_pipePoll (int handle);

int
gmms_HDIa_pipeStatus (int handle, int *isOpen, long *available);

void
gmms_HDIa_pipeCloseAll (MSF_UINT8 modId);

long
gmms_HDIa_pipePeek(int handle, void *buf, long bufSize);

/**********************************************************************
 * File
 **********************************************************************/

#define HDI_FILE_SET_RDONLY      1
#define HDI_FILE_SET_WRONLY      2
#define HDI_FILE_SET_RDWR        4
#define HDI_FILE_SET_APPEND      8  
#define HDI_FILE_SET_CREATE      16
#define HDI_FILE_SET_EXCL        32
#define HDI_FILE_SET_BUFFERED    64
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
#define HDI_FILE_SET_CUSTOM_BLOCKING 128
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
#define HDI_FILE_SET_CREATE_ALWAYS      256

#define HDI_FILE_SEEK_SET        1
#define HDI_FILE_SEEK_CUR        2
#define HDI_FILE_SEEK_END        3

#define HDI_FILE_DIRTYPE         1
#define HDI_FILE_FILETYPE        2

#define HDI_FILE_EVENT_READ      1
#define HDI_FILE_EVENT_WRITE     2

#define HDI_FILE_READ_READY      1
#define HDI_FILE_WRITE_READY     2

#define HDI_FILE_OK              0
#define HDI_FILE_ERROR_ACCESS   -1
#define HDI_FILE_ERROR_DELAYED  -2
#define HDI_FILE_ERROR_PATH     -3
#define HDI_FILE_ERROR_INVALID  -4
#define HDI_FILE_ERROR_SIZE     -5
#define HDI_FILE_ERROR_FULL     -6
#define HDI_FILE_ERROR_EOF      -7
#define HDI_FILE_ERROR_EXIST    -8
#define HDI_FILE_ERROR_CARD_ACCESS    -9
#define HDI_FILE_ERROR_ROOT_DIR_FULL     -10

typedef enum
{
    MSF_MMS_STORAGE_PHONE = 0,        
    MSF_MMS_STORAGE_MEM_CARD_1, 
	MSF_MMS_STORAGE_MEM_CARD_2, 
	MSF_MMS_STORAGE_NONE /*This has to be the last element of this enum*/
} msf_mms_storage_enum;

#ifdef __NON_BLOCKING_FILE_MOVE_SUPPORT__
typedef enum
{
	MSF_MMS_FILE_MOVE_FAIL,
	MSF_MMS_FILE_MOVE_DONE
}msf_mms_fs_move_response_enum;
#endif /* __NON_BLOCKING_FILE_MOVE_SUPPORT__ */

MSF_BOOL
gmms_HDIa_IsMemCardPresent(msf_mms_storage_enum storage_id);

int
gmms_HDIa_fileOpen (MSF_UINT8 modId, const char* fileName, int mode, long size);

int
gmms_HDIa_fileOpen_ext(MSF_UINT8 modId, const char *fileName, int mode, long size, msf_mms_storage_enum storage_id);

int
gmms_HDIa_fileClose (int fileHandle);

long
gmms_HDIa_fileWrite (int fileHandle, void* data, long size);

long
gmms_HDIa_fileRead (int fileHandle, void* data, long size);

void
gmms_HDIa_fileFlush (int fileHandle);

long
gmms_HDIa_fileSeek (int fileHandle, long offset, int seekMode);

int
gmms_HDIa_fileRemove_ext (const char* fileName, msf_mms_storage_enum storage_id);

int
gmms_HDIa_fileRemove(const char *fileName);

int
gmms_HDIa_fileRename_ext (const char *srcName, const char *dstName, msf_mms_storage_enum storage_id);

int
gmms_HDIa_fileRename(const char * srcName, const char * dstName);

int
gmms_HDIa_fileMkDir (const char* dirName);

int
gmms_HDIa_fileMkDir_ext (const char* dirName, msf_mms_storage_enum storage_id);

int
gmms_HDIa_fileRmDir_ext (const char* dirName, msf_mms_storage_enum storage_id);

int
gmms_HDIa_fileRmDir (const char* dirName);

int
gmms_HDIa_fileDelDir_ext (MSF_UINT8 modId, const char *path, MSF_BOOL removeDirectory, msf_mms_storage_enum storage_id);

int
gmms_HDIa_fileDelDir (MSF_UINT8 modId, const char *path, MSF_BOOL removeDirectory);

int
gmms_HDIa_fileGetSizeDir_ext(const char *dirName, msf_mms_storage_enum storage_id);

int
gmms_HDIa_fileGetSizeDir(const char *dirName);

int
gmms_HDIa_fileReadDir_ext (const char *dirName, int pos, char *nameBuf, int nameBufLength, int *type, int *size, msf_mms_storage_enum storage_id);

int
gmms_HDIa_fileReadDir  (const char *dirName, int pos, char *nameBuf, int nameBufLength, int *type, int *size);

int
gmms_HDIa_fileReadDirLong_ext (const char *dirName, int pos, char *nameBuf, int nameBufLength, int *type, long *size, msf_mms_storage_enum storage_id);

int
gmms_HDIa_fileReadDirLong (const char *dirName, int pos, char *nameBuf, int nameBufLength, int *type, long *size);

#ifdef MSF_USE_FILE_READ_DIR_SEQ
int
gmms_HDIa_fileReadDirSeq_ext(const char *dirName, int pos, char *nameBuf, int nameBufLength, int *type, int *size,int *dirHandle, msf_mms_storage_enum storage_id);
	
int
gmms_HDIa_fileReadDirSeq(const char *dirName, int pos, char *nameBuf, int nameBufLength, int *type, int *size,int *dirHandle);
	
void 
gmms_HDIa_fileReadDirSeqClose(int *dirHandle);
#endif /* MSF_USE_FILE_READ_DIR_SEQ*/

void 
gmms_HDIa_fileSelect(int fileHandle, int eventType);

long
gmms_HDIa_fileSetSize (int fileHandle, long size);

long
gmms_HDIa_fileGetSize_ext (const char* fileName, msf_mms_storage_enum storage_id);

long
gmms_HDIa_fileGetSize (const char* fileName);

void
gmms_HDIa_fileCloseAll (MSF_UINT8 modId);

int
gmms_HDIa_fileGenVirtualFileName(MSF_UINT8 modId, int fileHandle, char *vfs_name, int name_len, int offset, int len);

MSF_UINT8 *
gmms_HDIa_fileGetExternalFileName_ext(MSF_UINT8 modId, const char *src, msf_mms_storage_enum storage_id);

MSF_UINT8 *
gmms_HDIa_fileGetExternalFileName(MSF_UINT8 modId, const char *src);

int
gmms_is_mms_storage_exported_to_pc(void);

MSF_UINT32
gmms_HDIa_fileLastModifiedDate_ext(const char *src, msf_mms_storage_enum storage_id);

MSF_UINT32
gmms_HDIa_fileLastModifiedDate(const char *src);

void
gmms_HDI_send_file_move_response(MSF_INT32 status);

void
gmms_HDI_file_move_list_update(void);

void
gmms_HDI_check_next_file_move_operation(void);

void 
gmms_HDIa_send_filemove_response_signal_to_msm(MSF_INT32 result);

#ifdef __NON_BLOCKING_FILE_MOVE_SUPPORT__
void
gmms_HDIa_fileMove_ext2(MSF_UINT8 ModId, const char *src, msf_mms_storage_enum src_storage_id,
				   const char *dst, msf_mms_storage_enum dst_storage_id, int flag);

void
gmms_HDIa_fileMove(MSF_UINT8 ModId, const char *src, const char *dst, int flag);

#endif
#ifndef __NON_BLOCKING_FILE_MOVE_SUPPORT__
int gmms_HDIa_filemove_ext1(const char *srcName, msf_mms_storage_enum src_storage_id, const char *dstName, msf_mms_storage_enum dest_storage_id);
#endif
/**********************************************************************
 * Time
 **********************************************************************/

#define HDI_TIME_ZONE_UNKNOWN       9999

MSF_UINT32
gmms_HDIa_timeGetCurrent (void);

MSF_INT16
gmms_HDIa_timeGetTimeZone (void);

MSF_UINT32
gmms_HDIa_timeSecureClock (void);

MSF_UINT32
gmms_HDIa_timeUTCToLocal(MSF_UINT32 utc_time);

/**********************************************************************
 * Sockets
 **********************************************************************/

/* Socket types */
#define HDI_SOCKET_TYPE_UDP                       1
#define HDI_SOCKET_TYPE_TCP                       2
#define HDI_SOCKET_TYPE_SMS_DATA                  3
#define HDI_SOCKET_TYPE_SMS_RAW                   4

/* Bearers */
#define HDI_SOCKET_BEARER_IP_ANY                  0
#define HDI_SOCKET_BEARER_GSM_SMS                 3
#define HDI_SOCKET_BEARER_GSM_CSD                 10
#define HDI_SOCKET_BEARER_GSM_GPRS                11
#define HDI_SOCKET_BEARER_WIFI                    12
#define HDI_SOCKET_BEARER_BT                      150
#define HDI_SOCKET_BEARER_ANY                     255

/* Notification types */
#define HDI_SOCKET_EVENT_ACCEPT                   1
#define HDI_SOCKET_EVENT_CLOSED                   2
#define HDI_SOCKET_EVENT_CONNECTED                3
#define HDI_SOCKET_EVENT_RECV                     4
#define HDI_SOCKET_EVENT_SEND                     5

#define HDI_SOCKET_ERROR_BAD_ID                   -1
#define HDI_SOCKET_ERROR_INVALID_PARAM            -2
#define HDI_SOCKET_ERROR_MSG_SIZE                 -3
#define HDI_SOCKET_ERROR_DELAYED                  -4
#define HDI_SOCKET_ERROR_RESOURCE_LIMIT           -5
#define HDI_SOCKET_ERROR_CONNECTION_FAILED        -6
#define HDI_SOCKET_ERROR_HOST_NOT_FOUND           -7
#define HDI_SOCKET_ERROR_CLOSED                   -8


#ifndef Q03C_IND_MOD_ARCH_SUPPORT
#define HDI_SOCKET_ADDR_MAX_LEN           16
/* Address Type */
typedef struct {
  MSF_INT16     addrLen;
  unsigned char addr[HDI_SOCKET_ADDR_MAX_LEN];   /* Enough for IPv6 */
  MSF_UINT16    port;
} msf_sockaddr_t;
#else
#define HDI_SOCKET_ADDR_MAX_LEN           28
/* Address Type */
typedef struct {
  MSF_INT16     addrLen;
  unsigned char addr[HDI_SOCKET_ADDR_MAX_LEN];   /* Enough for IPv6 */
  MSF_UINT16    port;
  MSF_UINT8     type;
} msf_sockaddr_t;
#endif/*Q03C_IND_MOD_ARCH_SUPPORT*/


#ifndef Q03C_IND_MOD_ARCH_SUPPORT
int
gmms_HDIa_socketCreate (MSF_UINT8 modId, int socketType, MSF_INT32 networkAccountID);

int
gmms_HDIa_socketClose (int socketId);

int
gmms_HDIa_socketAccept (int socketId, msf_sockaddr_t *addr);

int
gmms_HDIa_socketBind (int socketId, msf_sockaddr_t *addr);

int
gmms_HDIa_socketConnect (int socketId, msf_sockaddr_t *addr);

int
gmms_HDIa_socketGetName (int socketId, msf_sockaddr_t *addr);

int
gmms_HDIa_socketListen (int socketId);

long
gmms_HDIa_socketRecv (int socketId, void *buf, long bufLen);

long
gmms_HDIa_socketRecvFrom (int socketId, void *buf, long bufLen, msf_sockaddr_t *fromAddr);

long
gmms_HDIa_socketSend (int socketId, void *data, long dataLen);

long
gmms_HDIa_socketSendTo (int socketId, void *data, long dataLen, msf_sockaddr_t *toAddr);

int
gmms_HDIa_socketSelect (int socketId, int eventType);

void
gmms_HDIa_socketCloseAll (MSF_UINT8 modId);

void
gmms_HDIa_socketGetHostByName (MSF_UINT8 modId, int requestId, const char *domainName);

void
gmms_HDIa_socketGetHostByNameNId (MSF_UINT8 modId, int requestId, const char *domainName, MSF_INT32 networkAccountID);
#else
int
HDIa_socketCreate (MSF_UINT8 modId, int socketType, MSF_INT32 networkAccountID);

int
HDIa_socketClose (int socketId);

int
HDIa_socketAccept (int socketId, msf_sockaddr_t *addr);

int
HDIa_socketBind (int socketId, msf_sockaddr_t *addr);

int
HDIa_socketConnect (int socketId, msf_sockaddr_t *addr);

int
HDIa_socketGetName (int socketId, msf_sockaddr_t *addr);

int
HDIa_socketListen (int socketId);

long
HDIa_socketRecv (int socketId, void *buf, long bufLen);

long
HDIa_socketRecvFrom (int socketId, void *buf, long bufLen, msf_sockaddr_t *fromAddr);

long
HDIa_socketSend (int socketId, void *data, long dataLen);

long
HDIa_socketSendTo (int socketId, void *data, long dataLen, msf_sockaddr_t *toAddr);

int
HDIa_socketSelect (int socketId, int eventType);

void
HDIa_socketCloseAll (MSF_UINT8 modId);

void
HDIa_socketGetHostByName (MSF_UINT8 modId, int requestId, const char *domainName);

void
HDIa_socketGetHostByNameNId (MSF_UINT8 modId, int requestId, const char *domainName, MSF_INT32 networkAccountID);
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

/**********************************************************************
 * Network Account
 **********************************************************************/

#define HDI_NETWORK_ACCOUNT_ERROR_BAD_ID -1
#define HDI_NETWORK_ACCOUNT_ERROR_NO_MORE_ID -2
#define HDI_NETWORK_ACCOUNT_ERROR_BEARER_NOT_FOUND -3

#ifndef Q03C_IND_MOD_ARCH_SUPPORT
int
gmms_HDIa_networkAccountGetBearer(MSF_INT32 networkAccountId);

int
gmms_HDIa_networkAccountGetName(MSF_INT32 networkAccountId, char *buf, int bufLen);

MSF_INT32
gmms_HDIa_networkAccountGetFirst(void);

MSF_INT32
gmms_HDIa_networkAccountGetNext(MSF_INT32 networkAccountId);

MSF_INT32
gmms_HDIa_networkAccountGetId(int bearer);
#else

int
HDIa_networkAccountGetBearer(MSF_INT32 networkAccountId);

int
HDIa_networkAccountGetName(MSF_INT32 networkAccountId, char *buf, int bufLen);

MSF_INT32
HDIa_networkAccountGetFirst(void);

MSF_INT32
HDIa_networkAccountGetNext(MSF_INT32 networkAccountId);

MSF_INT32
HDIa_networkAccountGetId(int bearer);
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/


/**********************************************************************
 * Telephone
 **********************************************************************/

/* Result types */
#define HDI_TEL_OK                            0
#define HDI_TEL_ERROR_UNSPECIFIED             -1
#define HDI_TEL_ERROR_CALLED_PARTY_IS_BUSY    -105
#define HDI_TEL_ERROR_NETWORK_NOT_AVAILABLE   -106
#define HDI_TEL_ERROR_CALLED_PARTY_NO_ANSWER  -107
#define HDI_TEL_ERROR_NO_ACTIVE_CONNECTION    -108
#define HDI_TEL_ERROR_INVALID                 -200

void
gmms_HDIa_telMakeCall (MSF_UINT8 modId, MSF_UINT16 telId, const char* number);

void
gmms_HDIa_telSendDtmf (MSF_UINT8 modId, MSF_UINT16 telId, const char* dtmf);


/**********************************************************************
 * Phonebook
 **********************************************************************/

/* Result types */
#define HDI_PB_OK                             0
#define HDI_PB_ERROR_UNSPECIFIED              -1
#define HDI_PB_ERROR_IN_NAME                  -100
#define HDI_PB_ERROR_NUMBER_TO_LONG           -102
#define HDI_PB_ERROR_PHONE_BOOK_ENTRY         -103
#define HDI_PB_ERROR_PHONE_BOOK_IS_FULL       -104
#define HDI_PB_ERROR_INVALID                  -200

void
gmms_HDIa_pbAddEntry (MSF_UINT8 modId, MSF_UINT16 pbId, const char* name, const char* number);

 
 /**********************************************************************
 * Logging
 **********************************************************************/

#define HDI_LOG_TYPE_DETAILED_LOW       0
#define HDI_LOG_TYPE_DETAILED_MEDIUM    1
#define HDI_LOG_TYPE_DETAILED_HIGH      2
#define HDI_LOG_TYPE_MEMORY             3

void
gmms_HDIa_logTrace (int type, MSF_UINT8 modId, int msgId, char *format, ...);

void
gmms_HDIa_logMsg (int type, MSF_UINT8 modId, const char *format, ...);

void
gmms_HDIa_logData (int type, MSF_UINT8 modId, const unsigned char *data, int dataLen);

void
gmms_HDIa_logSignal (MSF_UINT8 srcModId, MSF_UINT8 dstModId, const char *data);

#ifndef Q03C_IND_MOD_ARCH_SUPPORT
/**********************************************************************
 * Widget
 **********************************************************************/
#define MsfScreenHandle     MSF_UINT32
#define MsfWindowHandle     MSF_UINT32
#define MsfGadgetHandle     MSF_UINT32
#define MsfActionHandle     MSF_UINT32
#define MsfImageHandle      MSF_UINT32
#define MsfStringHandle     MSF_UINT32
#define MsfFontFamilyNumber MSF_UINT32

#define MsfIconHandle       MSF_UINT32
#define MsfSoundHandle      MSF_UINT32
#define MsfMoveHandle       MSF_UINT32
#define MsfRotationHandle   MSF_UINT32
#define MsfColorAnimHandle  MSF_UINT32
#define MsfStyleHandle      MSF_UINT32
#define MsfBrushHandle      MSF_UINT32
#define MsfAccessKeyHandle  MSF_UINT32

#define HDI_WIDGET_ERROR_UNEXPECTED    -1
#define HDI_WIDGET_ERROR_NOT_SUPPORTED -2

typedef struct {
  MSF_INT16 x;
  MSF_INT16 y;
}MsfPosition;


typedef struct {
  MSF_INT16 height;
  MSF_INT16 width;
} MsfSize;

typedef enum {
  MsfHigh = 0,
  MsfMiddle = 1,
  MsfLow = 2,
  MsfVerticalPosDefault = 3
} MsfVerticalPos;

typedef enum {
  MsfLeft = 0,
  MsfCenter = 1,
  MsfRight = 2,
  MsfHorizontalPosDefault = 3
} MsfHorizontalPos;

typedef struct {
  MsfVerticalPos verticalPos;
  MsfHorizontalPos horisontalPos;
}MsfAlignment;



typedef struct {
  MsfSize displaySize;
  int isTouchScreen;
  int hasDragAbility;
  int isColorDisplay;
  int numberOfColors;
  MSF_INT32 supportedMsfEvents; /*Deprecated*/
} MsfDeviceProperties;

typedef enum {
  MsfBack = 0,
  MsfCancel = 1,
  MsfExit = 2,
  MsfHelp = 3,
  MsfOk = 4,
  MsfMenu = 5,
  MsfStop = 6,
  MsfSelect = 7
} MsfActionType;

typedef enum {
  MsfImplicitChoice = 0,
  MsfExclusiveChoice = 1,
  MsfMultipleChoice = 2,
  MsfExclusiveChoiceDropDown = 3
} MsfChoiceType;


#define MSF_CHOICE_ELEMENT_SELECTED   0x01
#define MSF_CHOICE_ELEMENT_DISABLED   0x02
#define MSF_CHOICE_ELEMENT_FOCUSED    0x04 


typedef struct {
  int iconPos;
  int indexPos;
  int string1Pos;
  int string2Pos;
  int image1Pos;
  int image2Pos;
} MsfElementPosition;

typedef enum {
  MsfAlert    = 0,
  MsfConfirmation = 1,
  MsfWarning    = 2,
  MsfInfo     = 3,
  MsfError    = 4,
  MsfPrompt   = 5
} MsfDialogType;

typedef enum {
MsfInteractiveBar = 0,
MsfProgressBar = 1,
MsfVerticalScrollBar = 2,
MsfHorizontalScrollBar = 3
} MsfBarType ;

typedef enum {
   MsfTimeType = 0,
   MsfDateType = 1,
   MsfDateTime = 2
} MsfDateTimeType;

typedef enum {
  MsfText = 0,
  MsfName = 1,
  MsfIpAddress = 2,
  MsfUrl = 3,
  MsfEmailAddress = 4,
  MsfPhoneNumber = 5,
  MsfNumeric = 6,
  MsfNumber = 7,
  MsfInteger = 8,
  MsfPasswordText = 9,
  MsfPasswordNumber = 10,
  MsfPredictive = 11,
  MsfFile = 12,
  MsfFilePath = 13,
  MsfNoTextType = 14
} MsfTextType;

typedef struct {
  int day;
  int month;
  int year;
} MsfDate;

typedef struct {
  int hours;
  int minutes;
  int seconds;
} MsfTime;


typedef enum {
  MsfButton = 0,
  MsfButtonPressed = 1,
  MsfRadioButton = 2,
  MsfRadioButtonPressed = 3,
  MsfCheckBox = 4, 
  MsfCheckBoxChecked = 5, 
  MsfKey = 6,
  MsfBullet = 7,
  MsfTick = 8,
  MsfSquare = 9,
  MsfCircle = 10,
  MsfDisk = 11,
  MsfArrowHead = 12,
  MsfIcon1 = 13,
  MsfIcon2 = 14,
  MsfIcon3 = 15,
  MsfIcon4 = 16
} MsfIconType;

typedef enum {
  MsfPress = 0,
  MsfRelease = 1,
  MsfRepeat = 2
}MsfEventClass;

typedef enum {
  MsfKey_0 = 0, MsfKey_1 = 1, MsfKey_2 = 2, MsfKey_3 = 3, MsfKey_4 = 4,
  MsfKey_5 = 5, MsfKey_6 = 6, MsfKey_7 = 7, MsfKey_8 = 8, MsfKey_9 = 9, 
  MsfKey_Star = 10, MsfKey_Pound = 11, MsfKey_Up = 12, MsfKey_Down = 13, 
  MsfKey_Left = 14, MsfKey_Right = 15, MsfKey_Select = 16,
  MsfKey_Clear = 17, MsfKey_Yes = 18, MsfKey_No = 19, MsfKey_Menu = 20,
  MsfKey_Soft1 = 21, MsfKey_Soft2 = 22, MsfKey_Soft3 = 23,
  MsfKey_Soft4 = 24, MsfKey_Function1 = 25, MsfKey_Function2 = 26,
  MsfKey_Function3 = 27, MsfKey_Function4 = 28, MsfPointer = 29,
  MsfKey_Undefined = 30, MsfKey_PageUp = 31, MsfKey_PageDown = 32 
#ifdef MSF_CFG_9W_NAVIGATION_SUPPORT
#ifndef MSF_CFG_9W_MODE_KBRD_SIMULATION
  , MsfKey_LeftUp = 33,
  MsfKey_RightUp = 34,
  MsfKey_LeftDown = 35,
  MsfKey_RightDown = 36
#endif /* MSF_CFG_9W_MODE_KBRD_SIMULATION */
#endif /* MSF_CFG_9W_NAVIGATION_SUPPORT */
} MsfEventType;

#define MSF_EVENT_MODE_SHIFT      0x01
#define MSF_EVENT_MODE_ALT	      0x02 
#define MSF_EVENT_MODE_CTRL       0x04
#define MSF_EVENT_MODE_MULTITAP   0x08

typedef enum {
  MsfNotifyLostFocus = 0,
  MsfNotifyFocus = 1,
  MsfNotifyStateChange = 2,
  MsfNotifyMoveResize = 3,
  MsfNotifyResourceLoaded = 4,
  MsfNotifyResourceFailed = 5,
  MsfNotifyMarqueeDone = 6
#ifdef IMAGE_DECOMP_NOTIFY
  ,MsfNotifyResourceDecompressed = 7
  ,MsfNotifyResourceDecompressionFailed = 8
#endif
  ,MsfNotifyContentChange

} MsfNotificationType;

typedef struct {
  MSF_UINT8  eventMode;
  MsfEventClass eventClass;
  MsfEventType eventType;
  MsfPosition position;
} MsfEvent;


typedef struct {
  int r;
  int g;
  int b;
} MsfColor;

typedef enum {
  MsfFontNormal = 0,
  MsfFontOblique = 1,
  MsfFontItalic = 2
} MsfFontStyle;

typedef enum {
  MsfGenericFontSerif = 0,
  MsfGenericFontSansSerif = 1,
  MsfGenericFontCursive = 2,
  MsfGenericFontFantasy = 3,
  MsfGenericFontMonospace = 4
}MsfGenericFont;

typedef struct {
  MsfFontStyle fontStyle;
  int size;
  int weight;
  int stretch;
  int variant;
  MsfFontFamilyNumber fontFamily;   
} MsfFont;

typedef enum {
  MsfNone = 0,
  MsfDotted = 1,
  MsfDashed = 2,
  MsfSemiDotted = 3,
  MsfSolid = 4,
  MsfDouble = 5,
  MsfGroove = 6,
  MsfRidge = 7,
  MsfInset = 8,
  MsfOutset = 9
} MsfLine;

typedef struct {
  int thickness;
  MsfLine style;
} MsfLineStyle;

#define MSF_TEXT_DECORATION_UNDERLINE       0x01
#define MSF_TEXT_DECORATION_OVERLINE        0x02
#define MSF_TEXT_DECORATION_STRIKETHROUGH   0x04
#define MSF_TEXT_DECORATION_SHADOW          0x08
#define MSF_TEXT_DECORATION_BLINK           0x10


typedef struct {
  int decoration;
  int letterSpacing;
  int wordSpacing;
  int lineSpacing;
  int capitalization; 
  MsfAlignment alignment;	
} MsfTextProperty;



typedef enum {
  MsfNoPadding = 0,
  MsfHorisontal = 1,
  MsfVertical = 2,
  MsfTile = 3,
  MsfFullPadding = 4
}MsfPadding;


typedef struct {
  MsfImageHandle image;
  MsfAlignment alignment;
  MsfPadding padding;
}MsfPattern;


typedef enum {
  MsfImageZoom100 = 0,
  MsfImageZoom10 = 1,
  MsfImageZoom25 = 2,
  MsfImageZoom50 = 3,
  MsfImageZoom75 = 4,
  MsfImageZoom125 = 5,
  MsfImageZoom150 = 6,
  MsfImageZoom200 = 7,
  MsfImageZoom400 = 8,
  MsfImageZoom800 = 9,
  MsfImageZoomAutofit = 10
}MsfImageZoom;


typedef enum {
  MsfBmp = 1,
  MsfPictogram = 2,
  MsfGif = 0x1d,
  MsfJpeg = 0x1e,
  MsfPng = 0x20,
  MsfWbmp = 0x21
} MsfImageFormat;

typedef enum {
  MsfUtf8 = 106
} MsfStringFormat;

typedef enum {
  MsfAmr = 0,
  MsfMp3 = 1,
  MsfMidi = 2,
  MsfWav = 3
} MsfSoundFormat;

typedef enum {
  MsfClick = 0, MsfTone = 1, MsfSound_1 = 2, MsfSound_2 = 3, MsfSound_3 = 4, 
  MsfSound_4 = 5, MsfSound_5 = 6, MsfSound_6 = 7, MsfSound_7 = 8, MsfSound_8 = 9, 
  MsfSignal_1 = 10, MsfSignal_2 = 11, MsfSignal_3 = 12, MsfSignal_4 = 13, 
  MsfSignal_5 = 14, MsfSignal_6 = 15, MsfSignal_7 = 16, MsfSignal_8 = 17, 
  MsfMelody_1 = 18, MsfMelody_2 = 19, MsfMelody_3 = 20, MsfMelody_4 = 21, 
  MsfMelody_5 = 22, MsfMelody_6 = 23, MsfMelody_7 = 24, MsfMelody_8 = 25
} MsfPredefinedSound;

typedef enum {
  MsfMoveNormal = 0,
  MsfMoveAccelerate = 1,
  MsfMoveDescelerate = 2
} MsfMoveProperty;

typedef enum {
  MsfNoDecoration = 0,
  MsfDecorationBlink = 1,
  MsfDecorationLasVegas = 2,
  MsfDecorationAnts = 3,
  MsfDecorationShimmer = 4,
  MsfDecorationSparkle = 5
} MsfDecoration;

typedef enum {
  MsfMarqueeNone = 0,
  MsfMarqueeScroll = 1, 
  MsfMarqueeSlide = 2, 
  MsfMarqueeAlternate = 3,
  MsfMarqueeInsideScroll = 4
} MsfMarqueeType;


typedef enum {
  MsfResourceFile = 0,
  MsfResourcePipe = 1,
  MsfResourceBuffer = 2
} MsfResourceType;

typedef struct {
  const char* data;
  int dataSize;
  int moreData;
} MsfDirectData;

typedef union {
  const char* resource;
  MsfDirectData* directData;
} MsfCreateData;




/****************************************************************
  Widget General
 ***************************************************************/
int gmms_HDIa_widgetDeviceGetProperties(MsfDeviceProperties* theDeviceProperties);

int gmms_HDIa_widgetSetInFocus (MSF_UINT32 handle, int focus);

int gmms_HDIa_widgetHasFocus (MSF_UINT32 handle);

int gmms_HDIa_widgetRelease (MSF_UINT32 handle);

int gmms_HDIa_widgetReleaseAll (MSF_UINT8 modId);

MSF_UINT32 gmms_HDIa_widgetCopy (MSF_UINT8 modId, MSF_UINT32 handle);

int gmms_HDIa_widgetRemove(MSF_UINT32 handle, MSF_UINT32 handleToBeRemoved);

int gmms_HDIa_widgetAddAction (MSF_UINT32 handle, MsfActionHandle action);

int gmms_HDIa_widgetHandleMsfEvt(MSF_UINT32 handle, int msfEventType, int override, int unsubscribe);

int gmms_HDIa_widgetSetTitle (MSF_UINT32 handle, MsfStringHandle title);

int gmms_HDIa_widgetSetBorder (MSF_UINT32 handle, MsfLineStyle borderStyle);

int gmms_HDIa_widgetSetPosition(MSF_UINT32 handle, MsfPosition* position, MsfAlignment* alignment);

int gmms_HDIa_widgetSetSize (MSF_UINT32 handle, MsfSize* size);

int gmms_HDIa_widgetGetPosition (MSF_UINT32 handle, MsfPosition* position);

int gmms_HDIa_widgetGetSize (MSF_UINT32 handle, MsfSize* size);

int gmms_HDIa_widgetAddAnimation(MSF_UINT32 handle, MSF_UINT32 animation);

int gmms_HDIa_widgetSetDecoration(MSF_UINT32 handle, MsfDecoration decoration);

int gmms_HDIa_widgetMsfEvent2Utf8(MsfEvent *event, int multitap, char* buffer);

/****************************************************************
 SCREEN 
 ***************************************************************/
MsfScreenHandle gmms_HDIa_widgetScreenCreate (MSF_UINT8 modId, int notify, MsfStyleHandle defaultStyle);

int gmms_HDIa_widgetScreenSetNotify (MsfScreenHandle screen, int notify);
  
int gmms_HDIa_widgetScreenAddWindow (MsfScreenHandle screen, MsfWindowHandle window, MsfPosition* position, MsfScreenHandle nextScreen, MsfWindowHandle nextWindow);

MsfWindowHandle gmms_HDIa_widgetScreenActiveWindow (MsfScreenHandle screen);
  

/****************************************************************
 WINDOW 
 ***************************************************************/

int gmms_HDIa_widgetWindowAddGadget(MsfWindowHandle window, MsfGadgetHandle gadget, 
                               MsfPosition* position, MsfAlignment* alignment);
  
int gmms_HDIa_widgetWindowSetTicker (MsfWindowHandle window, MsfStringHandle tickerText);

#define MSF_WINDOW_PROPERTY_SCROLLBARVER  0x0001
#define MSF_WINDOW_PROPERTY_SCROLLBARHOR  0x0002
#define MSF_WINDOW_PROPERTY_TITLE         0x0004
#define MSF_WINDOW_PROPERTY_BORDER        0x0008
#define MSF_WINDOW_PROPERTY_SECURE        0x0010
#define MSF_WINDOW_PROPERTY_BUSY          0x0020
#define MSF_WINDOW_PROPERTY_TICKER_MODE   0x0040
#define MSF_WINDOW_PROPERTY_TICKER        0x0080
#define MSF_WINDOW_PROPERTY_NOTIFY        0x0100
#define MSF_WINDOW_PROPERTY_SINGLEACTION  0x0200
#define MSF_WINDOW_PROPERTY_ALWAYSONTOP   0x0400
#define MSF_WINDOW_PROPERTY_DISABLED      0x0800
#define MSF_WINDOW_PROPERTY_MOVERESIZE    0x1000

  
int gmms_HDIa_widgetWindowSetProperties (MsfWindowHandle window, int propertyMask);

int gmms_HDIa_widgetWindowSpecificSize (MsfWindowHandle window, MsfSize* size, int minimalSize);


/****************************************************************
 PAINTBOX 
 ***************************************************************/
MsfWindowHandle gmms_HDIa_widgetPaintboxCreate (MSF_UINT8 modId, MsfSize* size, 
                                           int propertyMask, MsfStyleHandle defaultStyle);

int gmms_HDIa_widgetPaintboxRedrawArea (MsfWindowHandle paintbox, MsfSize* size, MsfPosition* pos);
  

/****************************************************************
 FORM 
 ***************************************************************/
MsfWindowHandle gmms_HDIa_widgetFormCreate (MSF_UINT8 modId, MsfSize* size, int propertyMask,
                                       MsfStyleHandle defaultStyle);


/****************************************************************
 TEXT 
 ***************************************************************/
int gmms_HDIa_widgetTextSetText (MSF_UINT32 text, MsfStringHandle initialString, MsfTextType type, int maxSize, MsfStringHandle inputString, int singleLine);
    
int gmms_HDIa_widgetTextMaxSize (MSF_UINT32 text);
  
int gmms_HDIa_widgetTextClear (MSF_UINT32 text);

int gmms_HDIa_widgetTextSetProperty (MSF_UINT32 handle, MsfColor* color, MsfFont* font, MsfTextProperty* textProperty);

int gmms_HDIa_widgetTextGetProperty(MSF_UINT32 handle, MsfColor* color, MsfFont* font, MsfTextProperty* textProperty, MsfPosition* baseline);


/****************************************************************
 EDITOR 
 ***************************************************************/
MsfWindowHandle gmms_HDIa_widgetEditorCreate (MSF_UINT8 modId, MsfStringHandle initialString, 
                                         MsfStringHandle inputString, MsfTextType type, 
                                         int maxSize, int singleLine, MsfSize* size, 
                                         int propertyMask, MsfStyleHandle defaultStyle);

MsfWindowHandle gmms_HDIa_widgetEditorCreateCss (MSF_UINT8 modId, MsfStringHandle initialString, 
                                           MsfStringHandle inputString, MsfTextType type, 
                                           const char* formatString, int inputRequired, 
                                           int maxSize, int singleLine, 
                                           MsfSize* size, int propertyMask, MsfStyleHandle defaultStyle);

/****************************************************************
 CHOICE 
 ***************************************************************/
int gmms_HDIa_widgetChoiceSetElement (MSF_UINT32 choice, int index, MsfStringHandle string1, MsfStringHandle string2, MsfImageHandle image1, MsfImageHandle image2, int insert);

#ifdef MSF_CONFIG_TOOLTIP
int gmms_HDIa_widgetChoiceSetElementTT (MSF_UINT32 choice, int index, 
                                   MsfStringHandle string1, MsfStringHandle string2, 
                                   MsfImageHandle image1, MsfImageHandle image2, 
                                   MsfStringHandle tooltip, 
                                   int insert);
#endif
int gmms_HDIa_widgetChoiceRemoveElement (MSF_UINT32 choice, int index);  
    
int gmms_HDIa_widgetChoiceGetElemState (MSF_UINT32 choice, int index);

int gmms_HDIa_widgetChoiceSetElemState (MSF_UINT32 choice, int index, int state);
  
#define MSF_CHOICE_ELEMENT_ICON     0x01 
#define MSF_CHOICE_ELEMENT_INDEX    0x02 
#define MSF_CHOICE_ELEMENT_STRING_1 0x04 
#define MSF_CHOICE_ELEMENT_STRING_2 0x08 
#define MSF_CHOICE_ELEMENT_IMAGE_1  0x10 
#define MSF_CHOICE_ELEMENT_IMAGE_2  0x20 
    
int gmms_HDIa_widgetChoiceAttrProperty (MSF_UINT32 choice, MsfElementPosition* elementPos, int bitmask);

int gmms_HDIa_widgetChoiceElemProperty(MSF_UINT32 choice, int index, MsfElementPosition* elementPos, int bitmask);

int gmms_HDIa_widgetChoiceSize (MSF_UINT32 choice);


/****************************************************************
 MENU 
 ***************************************************************/
MsfWindowHandle gmms_HDIa_widgetMenuCreate (MSF_UINT8 modId, MsfChoiceType type, MsfSize* size, 
                                       MsfActionHandle implicitSelectAction, MsfElementPosition* 
                                       elementPos, int bitmask, int propertyMask, 
                                       MsfStyleHandle defaultStyle);

MsfWindowHandle gmms_HDIa_widgetMenuAppCreate (MSF_UINT8 modId, MsfActionHandle implicitSelectAction,
                                          MsfElementPosition* elementPos, int bitmask,
                                          int propertyMask, MsfStyleHandle defaultStyle);


/****************************************************************
 DIALOG 
 ***************************************************************/

MsfWindowHandle gmms_HDIa_widgetDialogCreate (MSF_UINT8 modId, MsfStringHandle dialogText, 
                                         MsfDialogType type, MSF_UINT32 timeoutTime, 
                                         int propertyMask, MsfStyleHandle defaultStyle);

int gmms_HDIa_widgetDialogSetAttr (MsfWindowHandle dialog, MsfStringHandle dialogText, MSF_UINT32 timeoutTime);
  
int gmms_HDIa_widgetDialogAddInput (MsfWindowHandle dialog, MsfStringHandle label, MsfStringHandle inputText, MsfTextType inputMode, int maxSize);

int gmms_HDIa_widgetDialogRemoveInput (MsfWindowHandle dialog, int index);

int gmms_HDIa_widgetDialogSetInputAttr (MsfWindowHandle dialog, int index, MsfStringHandle label, MsfStringHandle inputText, MsfTextType inputMode, int maxSize);

/****************************************************************
 ACTION 
 ***************************************************************/
MsfActionHandle gmms_HDIa_widgetActionCreate (MSF_UINT8 modId, MsfStringHandle label, int 
                                         actionType, int priority, int propertyMask);

int gmms_HDIa_widgetActionSetAttr (MsfActionHandle action, int actionType, int priority);

int gmms_HDIa_widgetActionGetAttr (MsfActionHandle action, int* actionType, int* priority);

#define MSF_ACTION_PROPERTY_ENABLED       0x0001
#define MSF_ACTION_PROPERTY_SINGLEACTION  0x0002

int gmms_HDIa_widgetActionSetProperties (MsfActionHandle action, int propertyMask);

/****************************************************************
 GADGET 
 ***************************************************************/
#define MSF_GADGET_PROPERTY_SCROLLBARVER  0x01
#define MSF_GADGET_PROPERTY_SCROLLBARHOR  0x02
#define MSF_GADGET_PROPERTY_LABEL         0x04
#define MSF_GADGET_PROPERTY_BORDER        0x08
#define MSF_GADGET_PROPERTY_TICKERMODE    0x10
#define MSF_GADGET_PROPERTY_FOCUS         0x20
#define MSF_GADGET_PROPERTY_NOTIFY        0x40
#define MSF_GADGET_PROPERTY_ALWAYSONTOP   0x80
#define MSF_GADGET_PROPERTY_MOVERESIZE    0x1000

int gmms_HDIa_widgetGadgetSetProperties (MsfGadgetHandle gadget, int propertyMask);



/****************************************************************
 STRING GADGET 
 ***************************************************************/
MsfGadgetHandle gmms_HDIa_widgetStringGadgetCreate (MSF_UINT8 modId, MsfStringHandle text, 
                                               MsfSize* size, int singleLine, int propertyMask, 
                                               MsfStyleHandle defaultStyle);
  
int gmms_HDIa_widgetStringGadgetSet (MsfGadgetHandle stringGadget, MsfStringHandle text, int singleLine);
    

/****************************************************************
 TEXT INPUT GADGET 
 ***************************************************************/
MsfGadgetHandle gmms_HDIa_widgetTextInputCreate (MSF_UINT8 modId, MsfStringHandle initialString, 
                                            MsfStringHandle inputString, MsfTextType type, 
                                            int maxSize, int singleLine, MsfSize* size, 
                                            int propertyMask, MsfStyleHandle defaultStyle);

MsfGadgetHandle gmms_HDIa_widgetTextInputCreateCss (MSF_UINT8 modId, MsfStringHandle initialString, 
                                              MsfStringHandle inputString, MsfTextType type, 
                                              const char* formatString, int inputRequired, 
                                              int maxSize, int singleLine, 
                                              MsfSize* size, int propertyMask, MsfStyleHandle defaultStyle);


/****************************************************************
 SELECT GROUP GADGET 
 ***************************************************************/
MsfGadgetHandle gmms_HDIa_widgetSelectgroupCreate (MSF_UINT8 modId, MsfChoiceType type, 
                                              MsfSize* size, MsfElementPosition* elementPos, 
                                              int bitmask, int propertyMask, 
                                              MsfStyleHandle defaultStyle);


/****************************************************************
 IMAGE GADGET
 ***************************************************************/
MsfGadgetHandle gmms_HDIa_widgetImageGadgetCreate(MSF_UINT8 modId, MsfImageHandle image, 
                                             MsfSize* size, MsfImageZoom imageZoom, 
                                             int propertyMask, MsfStyleHandle defaultStyle);
    
int gmms_HDIa_widgetImageGadgetSet(MsfGadgetHandle imageGadget, MsfImageHandle image, 
                              MsfImageZoom imageZoom);
  

/****************************************************************
 DATE TIME GADGET
 ***************************************************************/
MsfGadgetHandle gmms_HDIa_widgetDateTimeCreate (MSF_UINT8 modId, MsfDateTimeType mode, 
                                           MsfTime* time, MsfDate* date, MsfSize* size, 
                                           int propertyMask, MsfStyleHandle defaultStyle);

int gmms_HDIa_widgetDateTimeSetValues (MsfGadgetHandle datetimeGadget, MsfDateTimeType mode, MsfTime* time, MsfDate* date);
  
int gmms_HDIa_widgetDateTimeGetValues (MsfGadgetHandle datetimeGadget, MsfTime* time, MsfDate* date);


/****************************************************************
 BAR GADGET
 ***************************************************************/
MsfGadgetHandle gmms_HDIa_widgetBarCreate (MSF_UINT8 modId, MsfBarType barType,
                                            int maxValue, int initialValue, MsfSize* size,
                                            int propertyMask, MsfStyleHandle defaultStyle);

int gmms_HDIa_widgetBarSetValues (MsfGadgetHandle bar, int value, int maxValue);

int gmms_HDIa_widgetBarGetValues (MsfGadgetHandle bar, int* value, int* maxValue);



/****************************************************************
 LOW LEVEL
 ***************************************************************/
int gmms_HDIa_widgetHoldDraw(MSF_UINT32 msfHandle);

int gmms_HDIa_widgetPerformDraw(MSF_UINT32 msfHandle);

int gmms_HDIa_widgetDrawLine (MSF_UINT32 msfHandle, 
                         MsfPosition* start, 
                         MsfPosition* end);

int gmms_HDIa_widgetDrawRect (MSF_UINT32 msfHandle, MsfPosition* position, 
                         MsfSize* size, int fill);

int gmms_HDIa_widgetDrawIcon (MSF_UINT32 msfHandle, MsfIconHandle icon, 
                         MsfPosition* position);

int gmms_HDIa_widgetDrawArc (MSF_UINT32 msfHandle, MsfPosition* position, 
                        MsfSize* size, int startAngle,
                        int angleExtent, int fill);

int gmms_HDIa_widgetDrawString(MSF_UINT32 msfHandle, MsfStringHandle string, 
                          MsfPosition* position, MsfSize* maxSize, 
                          int index, int nbrOfChars, int baseline, 
                          int useBrushStyle);

int gmms_HDIa_widgetDrawPolygon (MSF_UINT32 msfHandle, int nrOfCorners, 
                            MSF_INT16* corners, int fill);

int gmms_HDIa_widgetDrawImage(MSF_UINT32 msfHandle, MsfImageHandle image, 
                         MsfPosition* position, MsfSize* maxSize, 
                         MsfImageZoom imageZoom);

int gmms_HDIa_widgetDrawAccessKey(MSF_UINT32 msfHandle, 
                             MsfAccessKeyHandle accessKey, 
                             MsfPosition* position);


/****************************************************************
 STYLE
 ***************************************************************/
MsfStyleHandle gmms_HDIa_widgetStyleCreate(MSF_UINT8 modId, MsfColor* color, 
                                      MsfColor* backgroundColor, 
                                      MsfPattern* foreground, 
                                      MsfPattern* background, 
                                      MsfLineStyle* lineStyle, 
                                      MsfFont* font, 
                                      MsfTextProperty* textProperty);

MsfBrushHandle gmms_HDIa_widgetGetBrush(MSF_UINT32 handle);

int gmms_HDIa_widgetSetColor (MSF_UINT32 msfHandle, MsfColor* color,
                         int background);

int gmms_HDIa_widgetSetLineStyle (MSF_UINT32 msfHandle,
                             MsfLineStyle* style);

int gmms_HDIa_widgetSetTextProperty (MSF_UINT32 msfHandle, 
                                MsfTextProperty* textProperty);

int gmms_HDIa_widgetSetPattern (MSF_UINT32 msfHandle, MsfPattern* pattern,
                           int background);

int gmms_HDIa_widgetSetFont (MSF_UINT32 msfHandle, MsfFont* font);

int gmms_HDIa_widgetFontGetFamily (int nrOfFonts, char* fontNames, 
                              MsfGenericFont genericFont, 
                              MsfFontFamilyNumber * fontFamilyNumber);

int gmms_HDIa_widgetGetColor (MSF_UINT32 msfHandle, MsfColor* color, 
                         int background);

int gmms_HDIa_widgetGetFont (MSF_UINT32 msfHandle, MsfFont* font);

int gmms_HDIa_widgetFontGetValues(MsfFont* font, int* ascent, 
                             int* height, int* xHeight);

int gmms_HDIa_widgetGetLineStyle (MSF_UINT32 msfHandle, 
                             MsfLineStyle* msfLineStyle);

int gmms_HDIa_widgetGetTextProperty (MSF_UINT32 msfHandle, 
                                MsfTextProperty* textProperty);

int gmms_HDIa_widgetGetPattern(MSF_UINT32 msfHandle, int background, 
                          MsfPattern* pattern);

int gmms_HDIa_widgetSetMarquee(MSF_UINT32 handle, MsfMarqueeType marqueeType, 
                          int direction, int repeat, int scrollAmount, 
                          int scrollDelay);



/****************************************************************
 STRING
 ***************************************************************/
MsfStringHandle gmms_HDIa_widgetStringCreate (MSF_UINT8 modId, 
                                         const char* stringData, 
                                         MsfStringFormat stringFormat, 
                                         int length, 
                                         MsfStyleHandle defaultStyle);

MsfStringHandle gmms_HDIa_widgetStringGetPredefined (MSF_UINT32 resId);

MsfStringHandle gmms_HDIa_widgetStringCreateText (MSF_UINT8 modId, 
                                             MSF_UINT32 handle, 
                                             int index);
  
int gmms_HDIa_widgetStringGetLength(MsfStringHandle string,
                               int lengthInBytes, 
                               MsfStringFormat format);
  
int gmms_HDIa_widgetStringGetData(MsfStringHandle string, 
                             char* buffer, 
                             MsfStringFormat format);

int gmms_HDIa_widgetStringCompare(MsfStringHandle string1, 
                             MsfStringHandle string2);

int gmms_HDIa_widgetStringGetVisible(MsfStringHandle string, 
                                MSF_UINT32 handle, MsfSize* size,
                                int startIndex, 
                                int includeInitialWhiteSpaces, 
                                int* nbrOfCharacters, 
                                int* nbrOfEndingWhiteSpaces, 
                                int* nbrOfInitialWhiteSpaces);

int gmms_HDIa_widgetStringGetSubSize(MsfStringHandle string, 
                                MSF_UINT32 handle, int index, 
                                int nbrOfChars, int subwidth,
                                MsfSize* size);


/****************************************************************
 ICON
 ***************************************************************/
MsfIconHandle gmms_HDIa_widgetIconCreate (MSF_UINT8 modId, MsfIconType iconType, MsfStyleHandle defaultStyle);


/****************************************************************
 IMAGE
 ***************************************************************/
MsfImageHandle gmms_HDIa_widgetImageCreate (MSF_UINT8 modId, const char* imageData,
                                       int imageDataSize, MsfImageFormat imageFormat,
                                       int moreData, MsfStyleHandle defaultStyle);

int gmms_HDIa_widgetImageNextPart (MsfImageHandle image, char* imageData,
                              int imageDataSize, int moreData);
 
MsfImageHandle gmms_HDIa_widgetImageCreateIcon(MSF_UINT8 modId, MsfIconHandle icon,
                                          MsfStyleHandle defaultStyle);

MsfImageHandle gmms_HDIa_widgetImageCreateResource(MSF_UINT8 modId, char* resource, 
                                              MsfResourceType resourceType, 
                                              MsfImageFormat imageFormat);
  
MsfImageHandle gmms_HDIa_widgetImageCreateEmpty (MSF_UINT8 modId, MsfSize* size,
                                            MsfStyleHandle defaultStyle);

MsfImageHandle gmms_HDIa_widgetImageCreateFrame(MSF_UINT8 modId, MsfSize* size, MsfPosition* pos,
                                           MsfStyleHandle defaultStyle);

MsfImageHandle gmms_HDIa_widgetImageCreateFormat(MSF_UINT8 modId, MsfCreateData* imageData, 
                                            const char* imageFormat, MsfResourceType resourceType, 
                                            MsfStyleHandle defaultStyle);

MsfImageHandle gmms_HDIa_widgetImageGetPredefined(MSF_UINT32 resId, const char* resString);


/****************************************************************
 SOUND
 ***************************************************************/
MsfSoundHandle gmms_HDIa_widgetSoundCreate (MSF_UINT8 modId, char* soundData, 
                                       MsfSoundFormat soundFormat, 
                                       int size, int moreData);

int gmms_HDIa_widgetSoundNextPart (MsfSoundHandle sound, char* soundData, int size, int moreData);

int gmms_HDIa_widgetSoundPlay (MsfSoundHandle sound);

int gmms_HDIa_widgetSoundPlayPredefined (MsfPredefinedSound sound);

int gmms_HDIa_widgetSoundStop (MsfSoundHandle sound);

MsfSoundHandle gmms_HDIa_widgetSoundCreateResource(MSF_UINT8 modId, 
                                              char* resource, 
                                              MsfResourceType resourceType, 
                                              MsfSoundFormat soundFormat);

MsfSoundHandle gmms_HDIa_widgetSoundCreateFormat(MSF_UINT8 modId, MsfCreateData* soundData, 
                                            const char* soundFormat, MsfResourceType resourceType);

MsfSoundHandle gmms_HDIa_widgetSoundGetPredefined(MSF_UINT32 resId);


/****************************************************************
 ACCESS KEYS
 ***************************************************************/
MsfAccessKeyHandle gmms_HDIa_widgetSetAccessKey(MSF_UINT32 handle,
                                           char* accessKeyDefinition,
                                           int override, int index,
                                           int visualise);

int gmms_HDIa_widgetRemoveAccessKey(MSF_UINT32 handle, 
                               MsfAccessKeyHandle accessKey);

/****************************************************************
 ANIMATION
 ***************************************************************/
MsfMoveHandle gmms_HDIa_widgetMoveCreate (MSF_UINT8 modId, MsfPosition* origin,
                                     MsfPosition* destination, int duration, 
                                     int nrOfSteps, MsfMoveProperty property, int repeat);

MsfRotationHandle gmms_HDIa_widgetRotationCreate (MSF_UINT8 modId, int startAngle, 
                                             int endAngle, int duration, int nrOfSteps, 
                                             MsfMoveProperty property, int repeat);

MsfColorAnimHandle gmms_HDIa_widgetColorAnimCreate (MSF_UINT8 modId, MsfColor* startColor, 
                                              MsfColor* endColor, int duration, 
                                              int nrOfSteps, MsfMoveProperty property, int repeat);

/****************************
 * Mouse Pointer Support
 ****************************/
#ifdef  __MMI_WAP_MOUSE_POINTER_SUPPORT__
extern void HDIa_widgetGetMousePointerPos(MsfPosition *mouse_pos);
extern void HDIa_widgetGetMousePointerSize(MsfSize *mouse_size);
extern void HDIa_widgetUpdateMousePointerParameters(int x, int y, int is_hand_tool_image);
#endif /*  __MMI_WAP_MOUSE_POINTER_SUPPORT__ */

/**********************************************************************
 * Object Actions
 **********************************************************************/
void gmms_HDIa_objectAction (const char *action_cmd, const char *mime_type, 
                        MsfResourceType data_type, const unsigned char *data, 
                        MSF_INT32 data_len, const char *src_path, 
                        const char *default_name);

#ifdef MSF_CONFIG_PIM

/**********************************************************************
 * PIM
 **********************************************************************/

/* PIM field */
typedef struct
{
	MSF_UINT16 field;
  MSF_UINT8  type;
  MSF_UINT32 length;
	MSF_UINT8  *data;
	}MsfPimField;

/* Record info */
typedef struct
{
  MSF_UINT16 field;
  MSF_UINT8  type;
  MSF_UINT32 length;
	MSF_UINT8  *data;
	MSF_UINT32 recordId;
}MsfPimAddrRecordInfo;


/* Field types */
#define HDI_PIM_ADDR_FIELD_NAME                 1
#define HDI_PIM_ADDR_FIELD_SHORT_NAME           2
#define HDI_PIM_ADDR_FIELD_NICK_NAME            3
#define HDI_PIM_ADDR_FIELD_JOB_TITLE            4
#define HDI_PIM_ADDR_FIELD_STREET               5
#define HDI_PIM_ADDR_FIELD_CITY                 6
#define HDI_PIM_ADDR_FIELD_ZIP                  7
#define HDI_PIM_ADDR_FIELD_STATE                8
#define HDI_PIM_ADDR_FIELD_COUNTRY              9
#define HDI_PIM_ADDR_FIELD_POST_CODE            10
#define HDI_PIM_ADDR_FIELD_TEL                  11
#define HDI_PIM_ADDR_FIELD_MOBILE               12
#define HDI_PIM_ADDR_FIELD_TEL_FAX              13
#define HDI_PIM_ADDR_FIELD_EMAIL                14
#define HDI_PIM_ADDR_FIELD_BIRTHDAY             15
#define HDI_PIM_ADDR_FIELD_HOMEPAGE             16
#define HDI_PIM_ADDR_FIELD_GROUP                17
#define HDI_PIM_ADDR_FIELD_CATEGORY             18
#define HDI_PIM_ADDR_FIELD_PICTURE              19
#define HDI_PIM_ADDR_FIELD_SOUND                20
#define HDI_PIM_ADDR_FIELD_VOICE_MAIL_BOX       21
#define HDI_PIM_ADDR_FIELD_IM                   22

/* Location types */
#define HDI_PIM_WORK                        1
#define HDI_PIM_HOME                        2

/* Result types */
#define HDI_PIM_OK                          0
#define HDI_PIM_ERROR_NOT_OPEN              -1 
#define HDI_PIM_ERROR_NO_RECORD             -2
#define HDI_PIM_ERROR_CANCEL_BY_USER        -3
#define HDI_PIM_ERROR_UNSPECIFIED           -4
#define HDI_PIM_ERROR_INVALID               -5
#define HDI_PIM_ERROR_MEM_FULL              -6
#define HDI_PIM_ERROR_DUPLICATE_RECORD      -7

/* Pim objects */
#define HDI_PIM_OBJECT_PHONE_BOOK           1
#define HDI_PIM_OBJECT_CALENDAR             2
#define HDI_PIM_OBJECT_TODO                 3
#define HDI_PIM_OBJECT_ALARM                4

/* Filters */
#define HDI_PIM_ADDR_FILTER_MOBILE          1
#define HDI_PIM_ADDR_FILTER_FAX             2
#define HDI_PIM_ADDR_FILTER_STREET          3
#define HDI_PIM_ADDR_FILTER_EMAIL           4
#define HDI_PIM_ADDR_FILTER_IM              5
#define HDI_PIM_ADDR_FILTER_PHONE           6
#define HDI_PIM_ADDR_FILTER_TEL             7
#define HDI_PIM_ADDR_FILETR_GROUP           8
#define HDI_PIM_ADDR_FILTER_PIC             9
#define HDI_PIM_ADDR_FILTER_SOUND           10
#define HDI_PIM_ADDR_FILTER_URI             11
#define HDI_PIM_ADRR_FILTER_ALL             12
#define HDI_PIM_ADRR_FILTER_NONE            13


void 
gmms_HDIa_pimOpen (MSF_UINT8 modId, MSF_UINT16 requestId, MSF_UINT16 pimObject);

void 
gmms_HDIa_pimClose (MSF_UINT8 modId, MSF_UINT16 requestId);

void 
gmms_HDIa_pimAddrLookup (MSF_UINT8 modId, MSF_UINT16 requestId,  
                    MSF_UINT16 resultFilter, const char* positionStr);

void 
gmms_HDIa_pimAddrLookupName (MSF_UINT8 modId, MSF_UINT16 requestId, 
                        MSF_UINT16 searchFilter, MSF_UINT16 nameField,
                        const char* searchStr);

void 
gmms_HDIa_pimAddrGetRecord (MSF_UINT8 modId, MSF_UINT16 requestId, MSF_UINT32 recordId);


void 
gmms_HDIa_pimAddrSetRecord (MSF_UINT8 modId, MSF_UINT16 requestId, MSF_UINT16 setFilter, 
                       const char *name, MsfResourceType dataType, const MSF_UINT8 *data, 
                       MSF_UINT32 len, const char *srcPath, const char *mimeType);


#endif /*MSF_CONFIG_PIM*/

#else
/**********************************************************************
 * Widget
 **********************************************************************/
#define MsfScreenHandle     MSF_UINT32
#define MsfWindowHandle     MSF_UINT32
#define MsfGadgetHandle     MSF_UINT32
#define MsfActionHandle     MSF_UINT32
#define MsfImageHandle      MSF_UINT32
#define MsfStringHandle     MSF_UINT32
#define MsfFontFamilyNumber MSF_UINT32

#define MsfIconHandle       MSF_UINT32
#define MsfSoundHandle      MSF_UINT32
#define MsfMoveHandle       MSF_UINT32
#define MsfRotationHandle   MSF_UINT32
#define MsfColorAnimHandle  MSF_UINT32
#define MsfStyleHandle      MSF_UINT32
#define MsfBrushHandle      MSF_UINT32
#define MsfAccessKeyHandle  MSF_UINT32

#define HDI_WIDGET_ERROR_UNEXPECTED    -1
#define HDI_WIDGET_ERROR_NOT_SUPPORTED -2

#define MSF_SOCKADDR_TYPE_UNKNOWN                  0
#define MSF_SOCKADDR_TYPE_IPV4                     1
#define MSF_SOCKADDR_TYPE_IPV6                     2
#define MSF_SOCKADDR_TYPE_SMS                      3

typedef struct {
  MSF_INT16 x;
  MSF_INT16 y;
}MsfPosition;


typedef struct {
  MSF_INT16 height;
  MSF_INT16 width;
} MsfSize;

typedef enum {
  MsfHigh = 0,
  MsfMiddle = 1,
  MsfLow = 2,
  MsfVerticalPosDefault = 3
} MsfVerticalPos;

typedef enum {
  MsfLeft = 0,
  MsfCenter = 1,
  MsfRight = 2,
  MsfHorizontalPosDefault = 3
} MsfHorizontalPos;

typedef struct {
  MsfVerticalPos verticalPos;
  MsfHorizontalPos horisontalPos;
}MsfAlignment;



typedef struct {
  MsfSize displaySize;
  int isTouchScreen;
  int hasDragAbility;
  int isColorDisplay;
  int numberOfColors;
  MSF_INT32 supportedMsfEvents; /*Deprecated*/
} MsfDeviceProperties;

typedef enum {
  MsfBack = 0,
  MsfCancel = 1,
  MsfExit = 2,
  MsfHelp = 3,
  MsfOk = 4,
  MsfMenu = 5,
  MsfStop = 6,
  MsfSelect = 7
} MsfActionType;

typedef enum {
  MsfImplicitChoice = 0,
  MsfExclusiveChoice = 1,
  MsfMultipleChoice = 2,
  MsfExclusiveChoiceDropDown = 3
} MsfChoiceType;


#define MSF_CHOICE_ELEMENT_SELECTED   0x01
#define MSF_CHOICE_ELEMENT_DISABLED   0x02
#define MSF_CHOICE_ELEMENT_FOCUSED    0x04 


typedef struct {
  int iconPos;
  int indexPos;
  int string1Pos;
  int string2Pos;
  int image1Pos;
  int image2Pos;
} MsfElementPosition;

/* NEW POPUP- by ankit */


typedef enum {
  MsfFailure = 0,
  MsfInfo,
  MsfWarning,
  MsfSuccess,
  MsfProgress,
  MsfQuery,
  MsfMessageSent,
  MsfNewMessage,
  MsfAlert,
  MsfConfirmation,
  MsfPrompt,
  MsfDialogTotal
} MsfDialogType; /* name changed by ankit - in review */


typedef enum {
MsfInteractiveBar = 0,
MsfProgressBar = 1,
MsfVerticalScrollBar = 2,
MsfHorizontalScrollBar = 3
} MsfBarType ;

typedef enum {
   MsfTimeType = 0,
   MsfDateType = 1,
   MsfDateTime = 2
} MsfDateTimeType;

typedef enum {
  MsfText = 0,
  MsfName = 1,
  MsfIpAddress = 2,
  MsfUrl = 3,
  MsfEmailAddress = 4,
  MsfPhoneNumber = 5,
  MsfNumeric = 6,
  MsfNumber = 7,
  MsfInteger = 8,
  MsfPasswordText = 9,
  MsfPasswordNumber = 10,
  MsfPredictive = 11,
  MsfFile = 12,
  MsfFilePath = 13,
  MsfNoTextType = 14,
  MsfTextarea = 15
} MsfTextType;

typedef struct {
  int day;
  int month;
  int year;
} MsfDate;

typedef struct {
  int hours;
  int minutes;
  int seconds;
} MsfTime;


typedef enum {
  MsfButton = 0,
  MsfButtonPressed = 1,
  MsfRadioButton = 2,
  MsfRadioButtonPressed = 3,
  MsfCheckBox = 4, 
  MsfCheckBoxChecked = 5, 
  MsfKey = 6,
  MsfBullet = 7,
  MsfTick = 8,
  MsfSquare = 9,
  MsfCircle = 10,
  MsfDisk = 11,
  MsfArrowHead = 12,
  MsfIcon1 = 13,
  MsfIcon2 = 14,
  MsfIcon3 = 15,
  MsfIcon4 = 16,
  MsfAltText = 17
#ifdef  __MMI_WAP_MOUSE_POINTER_SUPPORT__
 ,MsfMousePointer = 18
 ,MsfLinkSelectTool
#endif /*  __MMI_WAP_MOUSE_POINTER_SUPPORT__ */
} MsfIconType;

typedef enum {
  MsfPress = 0,
  MsfRelease = 1,
  MsfLongTap = 2,
  MsfRepeat = 3,
  MsfMove = 4, /* value is set to 4 so that it is in sync with the MMI event */
  MsfAbort = 5 /* value is set to 5 so that it is in sync with the MMI event */
}MsfEventClass;

typedef enum {
  MsfKey_0 = 0, MsfKey_1 = 1, MsfKey_2 = 2, MsfKey_3 = 3, MsfKey_4 = 4,
  MsfKey_5 = 5, MsfKey_6 = 6, MsfKey_7 = 7, MsfKey_8 = 8, MsfKey_9 = 9, 
  MsfKey_Star = 10, MsfKey_Pound = 11, MsfKey_Up = 12, MsfKey_Down = 13, 
  MsfKey_Left = 14, MsfKey_Right = 15, MsfKey_Select = 16,
  MsfKey_Clear = 17, MsfKey_Yes = 18, MsfKey_No = 19, MsfKey_Menu = 20,
  MsfKey_Soft1 = 21, MsfKey_Soft2 = 22, MsfKey_Soft3 = 23,
  MsfKey_Soft4 = 24, MsfKey_Function1 = 25, MsfKey_Function2 = 26,
  MsfKey_Function3 = 27, MsfKey_Function4 = 28, MsfPointer = 29,
  MsfKey_Undefined = 30, MsfKey_PageUp = 31, MsfKey_PageDown = 32 
#ifdef MSF_CFG_9W_NAVIGATION_SUPPORT
#ifndef MSF_CFG_9W_MODE_KBRD_SIMULATION
  , MsfKey_LeftUp = 33,
  MsfKey_RightUp = 34,
  MsfKey_LeftDown = 35,
  MsfKey_RightDown = 36
#endif /* MSF_CFG_9W_MODE_KBRD_SIMULATION */
#endif /* MSF_CFG_9W_NAVIGATION_SUPPORT */
} MsfEventType;

#define MSF_EVENT_MODE_SHIFT      0x01
#define MSF_EVENT_MODE_ALT	      0x02 
#define MSF_EVENT_MODE_CTRL       0x04
#define MSF_EVENT_MODE_MULTITAP   0x08

typedef enum {
  MsfNotifyLostFocus = 0,
  MsfNotifyFocus = 1,
  MsfNotifyStateChange = 2,
  MsfNotifyMoveResize = 3,
  MsfNotifyResourceLoaded = 4,
  MsfNotifyResourceFailed = 5,
  MsfNotifyMarqueeDone = 6
#ifdef IMAGE_DECOMP_NOTIFY
  ,MsfNotifyResourceDecompressed = 7
  ,MsfNotifyResourceDecompressionFailed = 8
#endif
  ,MsfNotifyContentChange

} MsfNotificationType;

typedef struct {
  MSF_UINT8  eventMode;
  MsfEventClass eventClass;
  MsfEventType eventType;
  MsfPosition position;
} MsfEvent;


typedef struct {
  int r;
  int g;
  int b;
} MsfColor;

typedef enum {
  MsfFontNormal = 0,
  MsfFontOblique = 1,
  MsfFontItalic = 2
} MsfFontStyle;

typedef enum {
  MsfGenericFontSerif = 0,
  MsfGenericFontSansSerif = 1,
  MsfGenericFontCursive = 2,
  MsfGenericFontFantasy = 3,
  MsfGenericFontMonospace = 4
}MsfGenericFont;

typedef struct {
  MsfFontStyle fontStyle;
  int size;
  int weight;
  int stretch;
  int variant;
  MsfFontFamilyNumber fontFamily;   
} MsfFont;

typedef enum {
  MsfNone = 0,
  MsfDotted = 1,
  MsfDashed = 2,
  MsfSemiDotted = 3,
  MsfSolid = 4,
  MsfDouble = 5,
  MsfGroove = 6,
  MsfRidge = 7,
  MsfInset = 8,
  MsfOutset = 9
} MsfLine;

typedef struct {
  int thickness;
  MsfLine style;
} MsfLineStyle;

#define MSF_TEXT_DECORATION_UNDERLINE       0x01
#define MSF_TEXT_DECORATION_OVERLINE        0x02
#define MSF_TEXT_DECORATION_STRIKETHROUGH   0x04
#define MSF_TEXT_DECORATION_SHADOW          0x08
#define MSF_TEXT_DECORATION_BLINK           0x10


typedef struct {
  int decoration;
  int letterSpacing;
  int wordSpacing;
  int lineSpacing;
  int capitalization; 
  MsfAlignment alignment;	
} MsfTextProperty;



typedef enum {
  MsfNoPadding = 0,
  MsfHorisontal = 1,
  MsfVertical = 2,
  MsfTile = 3,
  MsfFullPadding = 4
}MsfPadding;


typedef struct {
  MsfImageHandle image;
  MsfAlignment alignment;
  MsfPadding padding;
}MsfPattern;


typedef enum {
  MsfImageZoom100 = 0,
  MsfImageZoom10 = 1,
  MsfImageZoom25 = 2,
  MsfImageZoom50 = 3,
  MsfImageZoom75 = 4,
  MsfImageZoom125 = 5,
  MsfImageZoom150 = 6,
  MsfImageZoom200 = 7,
  MsfImageZoom400 = 8,
  MsfImageZoom800 = 9,
  MsfImageZoomAutofit = 10
}MsfImageZoom;


typedef enum {
  MsfBmp = 1,
  MsfPictogram = 2,
  MsfGif = 0x1d,
  MsfJpeg = 0x1e,
  MsfPng = 0x20,
  MsfWbmp = 0x21
} MsfImageFormat;

typedef enum {
  MsfUtf8 = 106
} MsfStringFormat;

typedef enum {
  MsfAmr = 0,
  MsfMp3 = 1,
  MsfMidi = 2,
  MsfWav = 3,
  MsfVm = 4,
  MsfRa = 5
} MsfSoundFormat;

typedef enum {
  MsfClick = 0, MsfTone = 1, MsfSound_1 = 2, MsfSound_2 = 3, MsfSound_3 = 4, 
  MsfSound_4 = 5, MsfSound_5 = 6, MsfSound_6 = 7, MsfSound_7 = 8, MsfSound_8 = 9, 
  MsfSignal_1 = 10, MsfSignal_2 = 11, MsfSignal_3 = 12, MsfSignal_4 = 13, 
  MsfSignal_5 = 14, MsfSignal_6 = 15, MsfSignal_7 = 16, MsfSignal_8 = 17, 
  MsfMelody_1 = 18, MsfMelody_2 = 19, MsfMelody_3 = 20, MsfMelody_4 = 21, 
  MsfMelody_5 = 22, MsfMelody_6 = 23, MsfMelody_7 = 24, MsfMelody_8 = 25
} MsfPredefinedSound;

typedef enum {
  MsfMoveNormal = 0,
  MsfMoveAccelerate = 1,
  MsfMoveDescelerate = 2
} MsfMoveProperty;

typedef enum {
  MsfNoDecoration = 0,
  MsfDecorationBlink = 1,
  MsfDecorationLasVegas = 2,
  MsfDecorationAnts = 3,
  MsfDecorationShimmer = 4,
  MsfDecorationSparkle = 5
} MsfDecoration;

typedef enum {
  MsfMarqueeNone = 0,
  MsfMarqueeScroll = 1, 
  MsfMarqueeSlide = 2, 
  MsfMarqueeAlternate = 3,
  MsfMarqueeInsideScroll = 4
} MsfMarqueeType;


typedef enum {
  MsfResourceFile = 0,
  MsfResourcePipe = 1,
  MsfResourceBuffer = 2
} MsfResourceType;

typedef struct {
  const char* data;
  int dataSize;
  int moreData;
} MsfDirectData;

typedef union {
  const char* resource;
  MsfDirectData* directData;
} MsfCreateData;




/****************************************************************
  Widget General
 ***************************************************************/
int HDIa_widgetDeviceGetProperties(MsfDeviceProperties* theDeviceProperties);

int HDIa_widgetSetInFocus (MSF_UINT32 handle, int focus);

int HDIa_widgetHasFocus (MSF_UINT32 handle);

int HDIa_widgetRelease (MSF_UINT32 handle);

int HDIa_widgetReleaseAll (MSF_UINT8 modId);

MSF_UINT32 HDIa_widgetCopy (MSF_UINT8 modId, MSF_UINT32 handle);

int HDIa_widgetRemove(MSF_UINT32 handle, MSF_UINT32 handleToBeRemoved);

int HDIa_widgetAddAction (MSF_UINT32 handle, MsfActionHandle action);

int HDIa_widgetHandleMsfEvt(MSF_UINT32 handle, int msfEventType, int override, int unsubscribe);

int HDIa_widgetSetTitle (MSF_UINT32 handle, MsfStringHandle title);

int HDIa_widgetSetBorder (MSF_UINT32 handle, MsfLineStyle borderStyle);

int HDIa_widgetSetPosition(MSF_UINT32 handle, MsfPosition* position, MsfAlignment* alignment);

int HDIa_widgetSetSize (MSF_UINT32 handle, MsfSize* size);

int HDIa_widgetGetPosition (MSF_UINT32 handle, MsfPosition* position);

int HDIa_widgetGetSize (MSF_UINT32 handle, MsfSize* size);

int HDIa_widgetAddAnimation(MSF_UINT32 handle, MSF_UINT32 animation);

int HDIa_widgetSetDecoration(MSF_UINT32 handle, MsfDecoration decoration);

int HDIa_widgetMsfEvent2Utf8(MsfEvent *event, int multitap, char* buffer);

/****************************************************************
 SCREEN 
 ***************************************************************/
MsfScreenHandle HDIa_widgetScreenCreate (MSF_UINT8 modId, int notify, MsfStyleHandle defaultStyle);

int HDIa_widgetScreenSetNotify (MsfScreenHandle screen, int notify);
  
int HDIa_widgetScreenAddWindow (MsfScreenHandle screen, MsfWindowHandle window, MsfPosition* position, MsfScreenHandle nextScreen, MsfWindowHandle nextWindow);

MsfWindowHandle HDIa_widgetScreenActiveWindow (MsfScreenHandle screen);
  

/****************************************************************
 WINDOW 
 ***************************************************************/

int HDIa_widgetWindowAddGadget(MsfWindowHandle window, MsfGadgetHandle gadget, 
                               MsfPosition* position, MsfAlignment* alignment);
  
int HDIa_widgetWindowSetTicker (MsfWindowHandle window, MsfStringHandle tickerText);

#define MSF_WINDOW_PROPERTY_SCROLLBARVER  0x0001
#define MSF_WINDOW_PROPERTY_SCROLLBARHOR  0x0002
#define MSF_WINDOW_PROPERTY_TITLE         0x0004
#define MSF_WINDOW_PROPERTY_BORDER        0x0008
#define MSF_WINDOW_PROPERTY_SECURE        0x0010
#define MSF_WINDOW_PROPERTY_BUSY          0x0020
#define MSF_WINDOW_PROPERTY_TICKER_MODE   0x0040
#define MSF_WINDOW_PROPERTY_TICKER        0x0080
#define MSF_WINDOW_PROPERTY_NOTIFY        0x0100
#define MSF_WINDOW_PROPERTY_SINGLEACTION  0x0200
#define MSF_WINDOW_PROPERTY_ALWAYSONTOP   0x0400
#define MSF_WINDOW_PROPERTY_DISABLED      0x0800
#define MSF_WINDOW_PROPERTY_MOVERESIZE    0x1000

  
int HDIa_widgetWindowSetProperties (MsfWindowHandle window, int propertyMask);

int HDIa_widgetWindowSpecificSize (MsfWindowHandle window, MsfSize* size, int minimalSize);


/****************************************************************
 PAINTBOX 
 ***************************************************************/
MsfWindowHandle HDIa_widgetPaintboxCreate (MSF_UINT8 modId, MsfSize* size, 
                                           int propertyMask, MsfStyleHandle defaultStyle);

int HDIa_widgetPaintboxRedrawArea (MsfWindowHandle paintbox, MsfSize* size, MsfPosition* pos);
  

/****************************************************************
 FORM 
 ***************************************************************/
MsfWindowHandle HDIa_widgetFormCreate (MSF_UINT8 modId, MsfSize* size, int propertyMask,
                                       MsfStyleHandle defaultStyle);


/****************************************************************
 TEXT 
 ***************************************************************/
int HDIa_widgetTextSetText (MSF_UINT32 text, MsfStringHandle initialString, MsfTextType type, int maxSize, MsfStringHandle inputString, int singleLine);
    
int HDIa_widgetTextMaxSize (MSF_UINT32 text);
  
int HDIa_widgetTextClear (MSF_UINT32 text);

int HDIa_widgetTextSetProperty (MSF_UINT32 handle, MsfColor* color, MsfFont* font, MsfTextProperty* textProperty);

int HDIa_widgetTextGetProperty(MSF_UINT32 handle, MsfColor* color, MsfFont* font, MsfTextProperty* textProperty, MsfPosition* baseline);


/****************************************************************
 EDITOR 
 ***************************************************************/
MsfWindowHandle HDIa_widgetEditorCreate (MSF_UINT8 modId, MsfStringHandle initialString, 
                                         MsfStringHandle inputString, MsfTextType type, 
                                         int maxSize, int singleLine, MsfSize* size, 
                                         int propertyMask, MsfStyleHandle defaultStyle);

MsfWindowHandle HDIa_widgetEditorCreateCss (MSF_UINT8 modId, MsfStringHandle initialString, 
                                           MsfStringHandle inputString, MsfTextType type, 
                                           const char* formatString, int inputRequired, 
                                           int maxSize, int singleLine, 
                                           MsfSize* size, int propertyMask, MsfStyleHandle defaultStyle);

/****************************************************************
 CHOICE 
 ***************************************************************/
int HDIa_widgetChoiceSetElement (MSF_UINT32 choice, int index, MsfStringHandle string1, MsfStringHandle string2, MsfImageHandle image1, MsfImageHandle image2, int insert);

#ifdef MSF_CONFIG_TOOLTIP
int HDIa_widgetChoiceSetElementTT (MSF_UINT32 choice, int index, 
                                   MsfStringHandle string1, MsfStringHandle string2, 
                                   MsfImageHandle image1, MsfImageHandle image2, 
                                   MsfStringHandle tooltip, 
                                   int insert);
#endif
int HDIa_widgetChoiceRemoveElement (MSF_UINT32 choice, int index);  
    
int HDIa_widgetChoiceGetElemState (MSF_UINT32 choice, int index);

int HDIa_widgetChoiceSetElemState (MSF_UINT32 choice, int index, int state);
  
#define MSF_CHOICE_ELEMENT_ICON     0x01 
#define MSF_CHOICE_ELEMENT_INDEX    0x02 
#define MSF_CHOICE_ELEMENT_STRING_1 0x04 
#define MSF_CHOICE_ELEMENT_STRING_2 0x08 
#define MSF_CHOICE_ELEMENT_IMAGE_1  0x10 
#define MSF_CHOICE_ELEMENT_IMAGE_2  0x20 
    
int HDIa_widgetChoiceAttrProperty (MSF_UINT32 choice, MsfElementPosition* elementPos, int bitmask);

int HDIa_widgetChoiceElemProperty(MSF_UINT32 choice, int index, MsfElementPosition* elementPos, int bitmask);

int HDIa_widgetChoiceSize (MSF_UINT32 choice);


/****************************************************************
 MENU 
 ***************************************************************/
MsfWindowHandle HDIa_widgetMenuCreate (MSF_UINT8 modId, MsfChoiceType type, MsfSize* size, 
                                       MsfActionHandle implicitSelectAction, MsfElementPosition* 
                                       elementPos, int bitmask, int propertyMask, 
                                       MsfStyleHandle defaultStyle);

MsfWindowHandle HDIa_widgetMenuAppCreate (MSF_UINT8 modId, MsfActionHandle implicitSelectAction,
                                          MsfElementPosition* elementPos, int bitmask,
                                          int propertyMask, MsfStyleHandle defaultStyle);


/****************************************************************
 DIALOG 
 ***************************************************************/

/* MsfWindowHandle HDIa_widgetDialogCreate (MSF_UINT8 modId, MsfStringHandle dialogText, 
                                         MsfDialogType type, MSF_UINT32 timeoutTime, 
                                         int propertyMask, MsfStyleHandle defaultStyle); */ 
MsfWindowHandle HDIa_widgetDialogCreateWithType (MSF_UINT8 modId, MsfStringHandle dialogText, 
                                                 MsfDialogType type, 
                                         int propertyMask, MsfStyleHandle defaultStyle);

int HDIa_widgetDialogSetAttr (MsfWindowHandle dialog, MsfStringHandle dialogText, MSF_UINT32 timeoutTime);
  
int HDIa_widgetDialogAddInput (MsfWindowHandle dialog, MsfStringHandle label, MsfStringHandle inputText, MsfTextType inputMode, int maxSize);

int HDIa_widgetDialogRemoveInput (MsfWindowHandle dialog, int index);

int HDIa_widgetDialogSetInputAttr (MsfWindowHandle dialog, int index, MsfStringHandle label, MsfStringHandle inputText, MsfTextType inputMode, int maxSize);

/****************************************************************
 ACTION 
 ***************************************************************/
MsfActionHandle HDIa_widgetActionCreate (MSF_UINT8 modId, MsfStringHandle label, int 
                                         actionType, int priority, int propertyMask);

int HDIa_widgetActionSetAttr (MsfActionHandle action, int actionType, int priority);

int HDIa_widgetActionGetAttr (MsfActionHandle action, int* actionType, int* priority);

#define MSF_ACTION_PROPERTY_ENABLED       0x0001
#define MSF_ACTION_PROPERTY_SINGLEACTION  0x0002

int HDIa_widgetActionSetProperties (MsfActionHandle action, int propertyMask);

/****************************************************************
 GADGET 
 ***************************************************************/
#define MSF_GADGET_PROPERTY_SCROLLBARVER  0x01
#define MSF_GADGET_PROPERTY_SCROLLBARHOR  0x02
#define MSF_GADGET_PROPERTY_LABEL         0x04
#define MSF_GADGET_PROPERTY_BORDER        0x08
#define MSF_GADGET_PROPERTY_TICKERMODE    0x10
#define MSF_GADGET_PROPERTY_FOCUS         0x20
#define MSF_GADGET_PROPERTY_NOTIFY        0x40
#define MSF_GADGET_PROPERTY_ALWAYSONTOP   0x80
#define MSF_GADGET_PROPERTY_MOVERESIZE    0x1000

int HDIa_widgetGadgetSetProperties (MsfGadgetHandle gadget, int propertyMask);



/****************************************************************
 STRING GADGET 
 ***************************************************************/
MsfGadgetHandle HDIa_widgetStringGadgetCreate (MSF_UINT8 modId, MsfStringHandle text, 
                                               MsfSize* size, int singleLine, int propertyMask, 
                                               MsfStyleHandle defaultStyle);
  
int HDIa_widgetStringGadgetSet (MsfGadgetHandle stringGadget, MsfStringHandle text, int singleLine);
    

/****************************************************************
 TEXT INPUT GADGET 
 ***************************************************************/
MsfGadgetHandle HDIa_widgetTextInputCreate (MSF_UINT8 modId, MsfStringHandle initialString, 
                                            MsfStringHandle inputString, MsfTextType type, 
                                            int maxSize, int singleLine, MsfSize* size, 
                                            int propertyMask, MsfStyleHandle defaultStyle);

MsfGadgetHandle HDIa_widgetTextInputCreateCss (MSF_UINT8 modId, MsfStringHandle initialString, 
                                              MsfStringHandle inputString, MsfTextType type, 
                                              const char* formatString, int inputRequired, 
                                              int maxSize, int singleLine, 
                                              MsfSize* size, int propertyMask, MsfStyleHandle defaultStyle);


/****************************************************************
 SELECT GROUP GADGET 
 ***************************************************************/
MsfGadgetHandle HDIa_widgetSelectgroupCreate (MSF_UINT8 modId, MsfChoiceType type, 
                                              MsfSize* size, MsfElementPosition* elementPos, 
                                              int bitmask, int propertyMask, 
                                              MsfStyleHandle defaultStyle);


/****************************************************************
 IMAGE GADGET
 ***************************************************************/
MsfGadgetHandle HDIa_widgetImageGadgetCreate(MSF_UINT8 modId, MsfImageHandle image, 
                                             MsfSize* size, MsfImageZoom imageZoom, 
                                             int propertyMask, MsfStyleHandle defaultStyle);
    
int HDIa_widgetImageGadgetSet(MsfGadgetHandle imageGadget, MsfImageHandle image, 
                              MsfImageZoom imageZoom);
  

/****************************************************************
 DATE TIME GADGET
 ***************************************************************/
MsfGadgetHandle HDIa_widgetDateTimeCreate (MSF_UINT8 modId, MsfDateTimeType mode, 
                                           MsfTime* time, MsfDate* date, MsfSize* size, 
                                           int propertyMask, MsfStyleHandle defaultStyle);

int HDIa_widgetDateTimeSetValues (MsfGadgetHandle datetimeGadget, MsfDateTimeType mode, MsfTime* time, MsfDate* date);
  
int HDIa_widgetDateTimeGetValues (MsfGadgetHandle datetimeGadget, MsfTime* time, MsfDate* date);


/****************************************************************
 BAR GADGET
 ***************************************************************/
MsfGadgetHandle HDIa_widgetBarCreate (MSF_UINT8 modId, MsfBarType barType,
                                            int maxValue, int initialValue, MsfSize* size,
                                            int propertyMask, MsfStyleHandle defaultStyle);

int HDIa_widgetBarSetValues (MsfGadgetHandle bar, int value, int maxValue);

int HDIa_widgetBarGetValues (MsfGadgetHandle bar, int* value, int* maxValue);



/****************************************************************
 LOW LEVEL
 ***************************************************************/
int HDIa_widgetHoldDraw(MSF_UINT32 msfHandle);

int HDIa_widgetPerformDraw(MSF_UINT32 msfHandle);

int HDIa_widgetDrawLine (MSF_UINT32 msfHandle, 
                         MsfPosition* start, 
                         MsfPosition* end);

int HDIa_widgetDrawRect (MSF_UINT32 msfHandle, MsfPosition* position, 
                         MsfSize* size, int fill);

int HDIa_widgetDrawIcon (MSF_UINT32 msfHandle, MsfIconHandle icon, 
                         MsfPosition* position);

int HDIa_widgetDrawArc (MSF_UINT32 msfHandle, MsfPosition* position, 
                        MsfSize* size, int startAngle,
                        int angleExtent, int fill);

int HDIa_widgetDrawString(MSF_UINT32 msfHandle, MsfStringHandle string, 
                          MsfPosition* position, MsfSize* maxSize, 
                          int index, int nbrOfChars, int baseline, 
                          int useBrushStyle);

int HDIa_widgetDrawPolygon (MSF_UINT32 msfHandle, int nrOfCorners, 
                            MSF_INT16* corners, int fill);

int HDIa_widgetDrawImage(MSF_UINT32 msfHandle, MsfImageHandle image, 
                         MsfPosition* position, MsfSize* maxSize, 
                         MsfImageZoom imageZoom);

int HDIa_widgetDrawAccessKey(MSF_UINT32 msfHandle, 
                             MsfAccessKeyHandle accessKey, 
                             MsfPosition* position);

int HDIa_widgetDrawIconWithSize(MSF_UINT32 msfHandle, 
                                MsfIconHandle icon, 
                                MsfPosition *position, 
                                MsfSize *size);


/****************************************************************
 STYLE
 ***************************************************************/
MsfStyleHandle HDIa_widgetStyleCreate(MSF_UINT8 modId, MsfColor* color, 
                                      MsfColor* backgroundColor, 
                                      MsfPattern* foreground, 
                                      MsfPattern* background, 
                                      MsfLineStyle* lineStyle, 
                                      MsfFont* font, 
                                      MsfTextProperty* textProperty);

MsfBrushHandle HDIa_widgetGetBrush(MSF_UINT32 handle);

int HDIa_widgetSetColor (MSF_UINT32 msfHandle, MsfColor* color,
                         int background);

int HDIa_widgetSetLineStyle (MSF_UINT32 msfHandle,
                             MsfLineStyle* style);

int HDIa_widgetSetTextProperty (MSF_UINT32 msfHandle, 
                                MsfTextProperty* textProperty);

int HDIa_widgetSetPattern (MSF_UINT32 msfHandle, MsfPattern* pattern,
                           int background);

int HDIa_widgetSetFont (MSF_UINT32 msfHandle, MsfFont* font);

int HDIa_widgetFontGetFamily (int nrOfFonts, char* fontNames, 
                              MsfGenericFont genericFont, 
                              MsfFontFamilyNumber * fontFamilyNumber);

int HDIa_widgetGetColor (MSF_UINT32 msfHandle, MsfColor* color, 
                         int background);

int HDIa_widgetGetFont (MSF_UINT32 msfHandle, MsfFont* font);

int HDIa_widgetFontGetValues(MsfFont* font, int* ascent, 
                             int* height, int* xHeight);

int HDIa_widgetGetLineStyle (MSF_UINT32 msfHandle, 
                             MsfLineStyle* msfLineStyle);

int HDIa_widgetGetTextProperty (MSF_UINT32 msfHandle, 
                                MsfTextProperty* textProperty);

int HDIa_widgetGetPattern(MSF_UINT32 msfHandle, int background, 
                          MsfPattern* pattern);

int HDIa_widgetSetMarquee(MSF_UINT32 handle, MsfMarqueeType marqueeType, 
                          int direction, int repeat, int scrollAmount, 
                          int scrollDelay);



/****************************************************************
 STRING
 ***************************************************************/
MsfStringHandle HDIa_widgetStringCreate (MSF_UINT8 modId, 
                                         const char* stringData, 
                                         MsfStringFormat stringFormat, 
                                         int length, 
                                         MsfStyleHandle defaultStyle);

MsfStringHandle HDIa_widgetStringGetPredefined (MSF_UINT32 resId);

MsfStringHandle HDIa_widgetStringCreateText (MSF_UINT8 modId, 
                                             MSF_UINT32 handle, 
                                             int index);
  
int HDIa_widgetStringGetLength(MsfStringHandle string,
                               int lengthInBytes, 
                               MsfStringFormat format);
  
int HDIa_widgetStringGetData(MsfStringHandle string, 
                             char* buffer, 
                             MsfStringFormat format);

int HDIa_widgetStringCompare(MsfStringHandle string1, 
                             MsfStringHandle string2);

int HDIa_widgetStringGetVisible(MsfStringHandle string, 
                                MSF_UINT32 handle, MsfSize* size,
                                int startIndex, 
                                int includeInitialWhiteSpaces, 
                                int* nbrOfCharacters, 
                                int* nbrOfEndingWhiteSpaces, 
                                int* nbrOfInitialWhiteSpaces);

int HDIa_widgetStringGetSubSize(MsfStringHandle string, 
                                MSF_UINT32 handle, int index, 
                                int nbrOfChars, int subwidth,
                                MsfSize* size);


/****************************************************************
 ICON
 ***************************************************************/
MsfIconHandle HDIa_widgetIconCreate (MSF_UINT8 modId, MsfIconType iconType, MsfStyleHandle defaultStyle);


/****************************************************************
 IMAGE
 ***************************************************************/
MsfImageHandle HDIa_widgetImageCreate (MSF_UINT8 modId, const char* imageData,
                                       int imageDataSize, MsfImageFormat imageFormat,
                                       int moreData, MsfStyleHandle defaultStyle);

int HDIa_widgetImageNextPart (MsfImageHandle image, char* imageData,
                              int imageDataSize, int moreData);
 
MsfImageHandle HDIa_widgetImageCreateIcon(MSF_UINT8 modId, MsfIconHandle icon,
                                          MsfStyleHandle defaultStyle);

MsfImageHandle HDIa_widgetImageCreateResource(MSF_UINT8 modId, char* resource, 
                                              MsfResourceType resourceType, 
                                              MsfImageFormat imageFormat);
  
MsfImageHandle HDIa_widgetImageCreateEmpty (MSF_UINT8 modId, MsfSize* size,
                                            MsfStyleHandle defaultStyle);

MsfImageHandle HDIa_widgetImageCreateFrame(MSF_UINT8 modId, MsfSize* size, MsfPosition* pos,
                                           MsfStyleHandle defaultStyle);

MsfImageHandle HDIa_widgetImageCreateFormat(MSF_UINT8 modId, MsfCreateData* imageData, 
                                            const char* imageFormat, MsfResourceType resourceType, 
                                            MsfStyleHandle defaultStyle);

MsfImageHandle HDIa_widgetImageGetPredefined(MSF_UINT32 resId, const char* resString);


/****************************************************************
 SOUND
 ***************************************************************/
#ifdef WIDGET_SUPPORT_SOUND
MsfSoundHandle HDIa_widgetSoundCreate (MSF_UINT8 modId, char* soundData, 
                                       MsfSoundFormat soundFormat, 
                                       int size, int moreData);

int HDIa_widgetSoundNextPart (MsfSoundHandle sound, char* soundData, int size, int moreData);

int HDIa_widgetSoundPlay (MsfSoundHandle sound);



int HDIa_widgetSoundStop (MsfSoundHandle sound);

MsfSoundHandle HDIa_widgetSoundCreateResource(MSF_UINT8 modId, 
                                              char* resource, 
                                              MsfResourceType resourceType, 
                                              MsfSoundFormat soundFormat);

MsfSoundHandle HDIa_widgetSoundCreateFormat(MSF_UINT8 modId, MsfCreateData* soundData, 
                                            const char* soundFormat, MsfResourceType resourceType);

MsfSoundHandle HDIa_widgetSoundGetPredefined(MSF_UINT32 resId);
#endif /* WIDGET_SUPPORT_SOUND */
int HDIa_widgetSoundPlayPredefined (MsfPredefinedSound sound);

/****************************************************************
 ACCESS KEYS
 ***************************************************************/
MsfAccessKeyHandle HDIa_widgetSetAccessKey(MSF_UINT32 handle,
                                           char* accessKeyDefinition,
                                           int override, int index,
                                           int visualise);

int HDIa_widgetRemoveAccessKey(MSF_UINT32 handle, 
                               MsfAccessKeyHandle accessKey);

/****************************************************************
 ANIMATION
 ***************************************************************/
MsfMoveHandle HDIa_widgetMoveCreate (MSF_UINT8 modId, MsfPosition* origin,
                                     MsfPosition* destination, int duration, 
                                     int nrOfSteps, MsfMoveProperty property, int repeat);

MsfRotationHandle HDIa_widgetRotationCreate (MSF_UINT8 modId, int startAngle, 
                                             int endAngle, int duration, int nrOfSteps, 
                                             MsfMoveProperty property, int repeat);

MsfColorAnimHandle HDIa_widgetColorAnimCreate (MSF_UINT8 modId, MsfColor* startColor, 
                                              MsfColor* endColor, int duration, 
                                              int nrOfSteps, MsfMoveProperty property, int repeat);

/****************************
 * Mouse Pointer Support
 ****************************/
#ifdef  __MMI_WAP_MOUSE_POINTER_SUPPORT__
extern void HDIa_widgetGetMousePointerPos(MsfPosition *mouse_pos);
extern void HDIa_widgetGetMousePointerSize(MsfSize *mouse_size);
extern void HDIa_widgetUpdateMousePointerParameters(int x, int y, int is_hand_tool_image);
#endif /*  __MMI_WAP_MOUSE_POINTER_SUPPORT__ */

/**********************************************************************
 * Object Actions
 **********************************************************************/
void HDIa_objectAction (const char *action_cmd, const char *mime_type, 
                        MsfResourceType data_type, const unsigned char *data, 
                        MSF_INT32 data_len, const char *src_path, 
                        const char *default_name);

#ifdef MSF_CONFIG_PIM

/**********************************************************************
 * PIM
 **********************************************************************/

/* PIM field */
typedef struct
{
	MSF_UINT16 field;
  MSF_UINT8  type;
  MSF_UINT32 length;
	MSF_UINT8  *data;
	}MsfPimField;

/* Record info */
typedef struct
{
  MSF_UINT16 field;
  MSF_UINT8  type;
  MSF_UINT32 length;
	MSF_UINT8  *data;
	MSF_UINT32 recordId;
}MsfPimAddrRecordInfo;


/* Field types */
#define HDI_PIM_ADDR_FIELD_NAME                 1
#define HDI_PIM_ADDR_FIELD_SHORT_NAME           2
#define HDI_PIM_ADDR_FIELD_NICK_NAME            3
#define HDI_PIM_ADDR_FIELD_JOB_TITLE            4
#define HDI_PIM_ADDR_FIELD_STREET               5
#define HDI_PIM_ADDR_FIELD_CITY                 6
#define HDI_PIM_ADDR_FIELD_ZIP                  7
#define HDI_PIM_ADDR_FIELD_STATE                8
#define HDI_PIM_ADDR_FIELD_COUNTRY              9
#define HDI_PIM_ADDR_FIELD_POST_CODE            10
#define HDI_PIM_ADDR_FIELD_TEL                  11
#define HDI_PIM_ADDR_FIELD_MOBILE               12
#define HDI_PIM_ADDR_FIELD_TEL_FAX              13
#define HDI_PIM_ADDR_FIELD_EMAIL                14
#define HDI_PIM_ADDR_FIELD_BIRTHDAY             15
#define HDI_PIM_ADDR_FIELD_HOMEPAGE             16
#define HDI_PIM_ADDR_FIELD_GROUP                17
#define HDI_PIM_ADDR_FIELD_CATEGORY             18
#define HDI_PIM_ADDR_FIELD_PICTURE              19
#define HDI_PIM_ADDR_FIELD_SOUND                20
#define HDI_PIM_ADDR_FIELD_VOICE_MAIL_BOX       21
#define HDI_PIM_ADDR_FIELD_IM                   22

/* Location types */
#define HDI_PIM_WORK                        1
#define HDI_PIM_HOME                        2

/* Result types */
#define HDI_PIM_OK                          0
#define HDI_PIM_ERROR_NOT_OPEN              -1 
#define HDI_PIM_ERROR_NO_RECORD             -2
#define HDI_PIM_ERROR_CANCEL_BY_USER        -3
#define HDI_PIM_ERROR_UNSPECIFIED           -4
#define HDI_PIM_ERROR_INVALID               -5
#define HDI_PIM_ERROR_MEM_FULL              -6
#define HDI_PIM_ERROR_DUPLICATE_RECORD      -7

/* Pim objects */
#define HDI_PIM_OBJECT_PHONE_BOOK           1
#define HDI_PIM_OBJECT_CALENDAR             2
#define HDI_PIM_OBJECT_TODO                 3
#define HDI_PIM_OBJECT_ALARM                4

/* Filters */
#define HDI_PIM_ADDR_FILTER_MOBILE          1
#define HDI_PIM_ADDR_FILTER_FAX             2
#define HDI_PIM_ADDR_FILTER_STREET          3
#define HDI_PIM_ADDR_FILTER_EMAIL           4
#define HDI_PIM_ADDR_FILTER_IM              5
#define HDI_PIM_ADDR_FILTER_PHONE           6
#define HDI_PIM_ADDR_FILTER_TEL             7
#define HDI_PIM_ADDR_FILETR_GROUP           8
#define HDI_PIM_ADDR_FILTER_PIC             9
#define HDI_PIM_ADDR_FILTER_SOUND           10
#define HDI_PIM_ADDR_FILTER_URI             11
#define HDI_PIM_ADRR_FILTER_ALL             12
#define HDI_PIM_ADRR_FILTER_NONE            13


void 
HDIa_pimOpen (MSF_UINT8 modId, MSF_UINT16 requestId, MSF_UINT16 pimObject);

void 
HDIa_pimClose (MSF_UINT8 modId, MSF_UINT16 requestId);

void 
HDIa_pimAddrLookup (MSF_UINT8 modId, MSF_UINT16 requestId,  
                    MSF_UINT16 resultFilter, const char* positionStr);

void 
HDIa_pimAddrLookupName (MSF_UINT8 modId, MSF_UINT16 requestId, 
                        MSF_UINT16 searchFilter, MSF_UINT16 nameField,
                        const char* searchStr);

void 
HDIa_pimAddrGetRecord (MSF_UINT8 modId, MSF_UINT16 requestId, MSF_UINT32 recordId);


void 
HDIa_pimAddrSetRecord (MSF_UINT8 modId, MSF_UINT16 requestId, MSF_UINT16 setFilter, 
                       const char *name, MsfResourceType dataType, const MSF_UINT8 *data, 
                       MSF_UINT32 len, const char *srcPath, const char *mimeType);


#endif /*MSF_CONFIG_PIM*/
#endif

/**********************************************************************
 * Memory
 **********************************************************************/

#ifdef MSF_CONFIG_INTERNAL_MALLOC

void*
gmms_HDIa_memInternalInit (MSF_UINT8 modId, MSF_UINT32* size);

#else

#ifdef MSF_LOG_MEM_ALLOC
void*
gmms_HDIa_memAlloc(MSF_UINT8 modId, MSF_UINT32 size, const char *filename, int lineno);
#else
void*
gmms_HDIa_memAlloc (MSF_UINT8 modId, MSF_UINT32 size);
#endif

#ifdef MSF_LOG_MEM_ALLOC
void
gmms_HDIa_memFree (MSF_UINT8 modId, void* p, const char *filename, int lineno);
#else
void
gmms_HDIa_memFree (MSF_UINT8 modId, void* p);
#endif

#endif

void*
gmms_HDIa_memExternalAlloc (MSF_UINT8 modId, MSF_UINT32 size);

void
gmms_HDIa_memExternalFree (MSF_UINT8 modId, void* p);

MSF_UINT32 
gmms_HDIa_getAvailableFreeMemory(void);


/**********************************************************************
 * Errors
 **********************************************************************/

/* Main error code categories */
#define HDI_ERR_SYSTEM                              0x100
#define HDI_ERR_MODULE                              0x200

/* System errors */
#define HDI_ERR_SYSTEM_REG_ABORTED                  HDI_ERR_SYSTEM + 1
#define HDI_ERR_SYSTEM_REG_FILE_CORRUPT             HDI_ERR_SYSTEM + 2
#define HDI_ERR_SYSTEM_FATAL                        HDI_ERR_SYSTEM + 3
#define HDI_ERR_SYSTEM_REG_TXT_FILE                 HDI_ERR_SYSTEM + 4
#define HDI_ERR_SYSTEM_REG_TXT_PARSE                HDI_ERR_SYSTEM + 5

/* Module errors */
#define HDI_ERR_MODULE_OUT_OF_MEMORY                HDI_ERR_MODULE + 1


void
gmms_HDIa_error (MSF_UINT8 modId, int errorNo);


/**********************************************************************
 * Module
 **********************************************************************/
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
MSF_UINT8
gmms_HDIa_getModuleID (void);
#else
MSF_UINT8 HDIa_getModuleID(void);
#endif

void
gmms_HDIa_killTask (MSF_UINT8 modId);

#define HDIa_signalAllocMemory gmms_HDIa_signalAllocMemory

#define HDIa_signalFreeMemory gmms_HDIa_signalFreeMemory

#define HDIa_signalSend gmms_HDIa_signalSend

#define HDIa_signalRetrieve gmms_HDIa_signalRetrieve

#define HDIa_signalQueueLength gmms_HDIa_signalQueueLength

#define HDIa_memInternalInit gmms_HDIa_memInternalInit

#define HDIa_memAlloc gmms_HDIa_memAlloc

#define HDIa_memFree gmms_HDIa_memFree

#define HDIa_memExternalAlloc gmms_HDIa_memExternalAlloc

#define HDIa_memExternalFree gmms_HDIa_memExternalFree

#define HDIa_error gmms_HDIa_error

#define HDIa_timeGetCurrent gmms_HDIa_timeGetCurrent

#define HDIa_logSignal gmms_HDIa_logSignal

#define HDIa_getAvailableFreeMemory gmms_HDIa_getAvailableFreeMemory

typedef enum wap_continue_ind_type_t
{
	WAP_CONTINUE_BRS_HTTP_ABORT,

	WAP_CONTINUE_END
} wap_continue_ind_type;


typedef struct wap_continue_ind_struct_t
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
	int signal_type;	/* Used to differentiate type of signal. */
	int dst_mod_id;		/* Continue to which module */
	void *data;			/* can be used to keep data. */
} wap_continue_ind_struct;

extern void HDIa_widgetPlayToneAndVibration(void);
extern void HDIa_widgetPlayVibration(void);

#endif
