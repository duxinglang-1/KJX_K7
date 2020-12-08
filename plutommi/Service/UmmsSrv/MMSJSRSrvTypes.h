/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * MMSJsrSrvTypes.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file intends for handling the JSR messages.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
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
 * removed!
 * removed!
 * removed!
 *
  *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _JSR_TYPES_H
#define _JSR_TYPES_H

#include "MMI_features.h"
#ifdef __MMI_MMS_2__
#include "MMIDataType.h"
#include "FileMgrSrvGProt.h"    /* SRV_FMGR_PUBLIC_DRV */
#include "mma_struct.h"
#include "fs_type.h"    /* FS_HANDLE */

/***************************************************************************** 
* Define
*****************************************************************************/

#define JSR_MAX_APP_ID_NUM 5
#define JSR_MAX_APP_ID_LENGTH 100
#define JSR_MAX_MSGS_NUM 10

#define MMS_SYS_FOLDER  SRV_FMGR_PUBLIC_DRV     /* SRV_FMGR_SYSTEM_DRV */
#define JSR_FOLDER_NAME "_UJSR"
#define SRV_MMS_MAKE_JSR_FOLDER_PATH(x)          \
        kal_wsprintf((kal_uint16 *)x, "%c:\\%s", \
        MMS_SYS_FOLDER, JSR_FOLDER_NAME);
/* File sytem Interfaces */
/* amit to do #define MMS_SYS_FOLDER SRV_FMGR_SYSTEM_DRV */

#define JSR_INFO "info.db"
//#define MMS_SYS_FOLDER "C:\\mms_sys"
//#define JSR_INFO_FILE MMS_FOLDER JSR_INFO

#define MAKE_JSR_INFO_FILE(x)                      \
      kal_wsprintf((kal_uint16 *)x, "%c:\\%s\\%s", \
      MMS_SYS_FOLDER, JSR_FOLDER_NAME,  JSR_INFO);

#define JSR_APPID_LIST "appidlist.cn"
// #define JSR_APPID_LIST_FILE MMS_SYS_FOLDER JSR_APPID_LIST

#define MAKE_JSR_APPID_LIST_FILE(x)            \
      kal_wsprintf((kal_uint16 *)x, "%c:\\%s", \
      MMS_SYS_FOLDER, JSR_APPID_LIST);

#define JSR_APPID_LIST_TMP "appidlist.tp"
// #define JSR_APPID_LIST_FILE_TMP MMS_SYS_FOLDER JSR_APPID_LIST_TMP

#define MAKE_APPID_LIST_FILE_TMP(x)            \
      kal_wsprintf((kal_uint16 *)x, "%c:\\%s", \
      MMS_SYS_FOLDER,  JSR_APPID_LIST_TMP);

#define JSR_MEDIA_OBJECT "jsrmedia.mo"
// #define JSR_MEDIA_OBJECT_FILE MMS_SYS_FOLDER JSR_MEDIA_OBJECT

#define MAKE_JSR_MEDIA_OBJECT_FILE(x)              \
      kal_wsprintf((kal_uint16 *)x, "%c:\\%s\\%s", \
      MMS_SYS_FOLDER, JSR_FOLDER_NAME,  JSR_MEDIA_OBJECT);

#define JSR_XML "jsr.xml"
//#define MMS_SYS_FOLDER "C:\\mms_sys"
//#define JSR_INFO_FILE MMS_FOLDER JSR_INFO

#define MAKE_JSR_XML_FILE(x)                       \
      kal_wsprintf((kal_uint16 *)x, "%c:\\%s\\%s", \
      MMS_SYS_FOLDER, JSR_FOLDER_NAME,  JSR_XML);

#define JSR_TEXT "jsr"
#define MAKE_JSR_XML_TEXT_FILE(x, d)                   \
      kal_wsprintf((kal_uint16 *)x, "%c:\\%s\\%s%d%s", \
      MMS_SYS_FOLDER, JSR_FOLDER_NAME,  JSR_TEXT,d, ".txt");

#define JSR_MEDIA "jsrMedia"
#define MAKE_JSR_MEDIA_FILE(x, d)                      \
      kal_wsprintf((kal_uint16 *)x, "%c:\\%s\\%s%d%s", \
      MMS_SYS_FOLDER, JSR_FOLDER_NAME,  JSR_TEXT,d, ".tmp");
#define ATTACHMENT_FILE  L"Attach.temp"

#define JSR_FILENAME_LEN_MMA  MMA_MAX_INTERNAL_FILENAME_LENGTH

#define JSR_FILENAME_LEN      40
#define JSR_ADDR_LEN       40   /* MMA_MAX_ADDR_LENGTH */
#define JSR_SUBJECT_LEN       40        /* MMA_MAX_SUBJECT_LENGTH */

#define FILE_BUF_SIZE         512

/***************************************************************************** 
* JSR Context global structure
*****************************************************************************/
#define JSR_CNTX jsr_cntx_p

/***************************************************************************** 
* JSR Enums
*****************************************************************************/
typedef enum
{
    JSR_OP_IDLE,
    JSR_OP_SEND_MSG,
    JSR_OP_RECV_MSG,
    JSR_OP_ABORT_SENDING_MSG,
    JSR_OP_ABORT_RECIEVING_MSG,
    JSR_OP_UPLOAD_MSG,
    JSR_OP_DELETE_MSG,
    JSR_OP_CHECK_MSG,
    JSR_OP_READ_MSG,
    JSR_OP_CFG_APP_ID
} JsrOperations;

typedef enum
{
    JSR_STATE_IDLE,
    JSR_STATE_READ_FOLDER,
    JSR_STATE_CREATE_MSG,
    JSR_STATE_UPLOAD_MSG,
    JSR_STATE_DELETE_MSG,
    JSR_STATE_PROCESS_SEND_MSG_HDR,
    JSR_STATE_PROCESS_SEND_MSG_BDY,
    JSR_STATE_RECV_MSG_HDR,
    JSR_STATE_RECV_MSG_BDY,
    JSR_STATE_SEND_MSG
} JsrStates;

/***************************************************************************** 
* JSR Local Structures
*****************************************************************************/
typedef struct jsr_msg_info_struct
{
    U32 msgId;
    struct jsr_msg_info_struct *next;
    struct jsr_msg_info_struct *prev;
    U8 is_checked;
} jsr_msg_info;

typedef struct jsr_appid_list_struct
{
    char *appId;
    jsr_msg_info *msgs;
    struct jsr_appid_list_struct *next;
    struct jsr_appid_list_struct *prev;
} jsr_appid_msgid_list;

typedef struct
{
    char *appId;
} jsr_appid_info_struct;

/***************************************************************************** 
* JSR Structures mapped as per AT and JSR SAP
*****************************************************************************/
typedef enum
{
    JSR_BASIC_PHONE = 1,
    JSR_FULL_PHONE,
    JSR_BASIC_CARD,
    JSR_FULL_CARD
} JsrRetrievalMode;

/* create message modes */

typedef enum
{
    JSR_NONE = 0x0,
    JSR_INBOX = 0x1,
    JSR_OUTBOX = 0x2,
    JSR_SENT = 0x4,
    JSR_DRAFTS = 0x8,
    JSR_PREDEF_TEMPLATE = 0x10,
    JSR_USRDEF_TEMPLATE = 0x20,
    JSR_ARCHIVE = 0x40,
    JSR_ALL_FOLDERS = 0xFFFF
} JsrFolderType;

typedef enum
{

    JSR_PHSUITE_NONE = 0x0,
    JSR_PHSUITE_INBOX = 0x1,
    JSR_PHSUITE_OUTBOX = 0x2,
    JSR_PHSUITE_SENT = 0x4,
    JSR_PHSUITE_DRAFTS = 0x8,
    JSR_PHSUITE_PREDEF_TEMPLATE = 0x40
} JsrPhSuiteFolderType;

typedef enum
{
    JSR_SUFFIX_TEMPLATE = 't',
    JSR_SUFFIX_SEND_REQ = 's',
    JSR_SUFFIX_MSG = 'm',
    JSR_SUFFIX_NOTIFICATION = 'n',
    JSR_SUFFIX_READREPORT = 'r',
    JSR_SUFFIX_DELIVERYREPORT = 'd'
} JsrFileType;

typedef enum
{
    JSR_WAP_MMS_PROF_MMSC_ADDRESS   /* WAP MMSC address */
} jsr_wap_mms_prof_access_enum;

typedef struct
{
    U32 numOfMsg;
    U32 numOfUnreadMsg;
    U8 mmsHomeDirectory[JSR_FILENAME_LEN_MMA];
    U8 infoFilePath[JSR_FILENAME_LEN_MMA];
} JsrFolderInfo;

typedef struct
{
    U32 msgId;
    U32 offset;
    U32 size;
    U32 date;
    U8 filename[JSR_FILENAME_LEN];
    U8 address[JSR_ADDR_LEN];
    U8 subject[JSR_SUBJECT_LEN];
} JsrMessageInfo;

/***************************************************************************** 
* JSR Context structure
*****************************************************************************/
typedef struct
{
    U32 msgId;
    U32 folderId;
    U32 numofMsg;
    U32 numofUnreadMsg;
    U32 *msgIDList;
    U32 counter;
    U32 req_id;
    U32 dest_mod_id;
    U32 xml_file_size;
    U16 *object_file;
    S8 *file_path;
    FS_HANDLE file_handle;
    /* FS_HANDLE xml_file_handle; */
    /* jsr_msg_info *msg_list; */
    JsrMessageInfo msgInfolist[10];
    U8 is_abort_get_req;
    U8 buffer_index;
    U8 op;
    U8 state;
    U8 curr_media_obj_no;
    U8 total_media_obj_no;
    U8 retrievalMode;
    U8 sim_Id;
    U8 is_more_msg;
    U8 msg_storage;
} jsr_context_struct;

/***************************************************************************** 
* For compilation only TO BE REMOVED
*****************************************************************************/

#endif /* __MMI_MMS_2__ */ 
#endif /* _JSR_TYPES_H */ 

