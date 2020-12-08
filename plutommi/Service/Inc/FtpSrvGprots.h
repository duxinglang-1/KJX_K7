/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/******************************************************************************
 * 
 * Filename
 * ---------
 *  FtpSrvGprots.h
 * 
 * Project:
 * --------
 *  
 * 
 * Description:
 * ------------
 *  
 * 
 * Author:
 * -------
 * -------
 * 
 *=============================================================================
 *            HISTORY
 * Below this line,  this part is controlled by PVCS VM. DO NOT MODIFY!!
 *-----------------------------------------------------------------------------
 * $Log$
 *
 * 03 02 2011 zhanying.liu
 * removed!
 * .reduce ftp buffer size for slim load
 *
 * 12 16 2010 zhanying.liu
 * removed!
 * .update RHR code check in.
 *
 * 12 14 2010 zhanying.liu
 * removed!
 * .update RHR add files
 *
 * 12 14 2010 zhanying.liu
 * removed!
 * .MAUI RHR code check in
 *
 * 12 10 2010 zhanying.liu
 * removed!
 * .move ftp client buffer to ftp client service
 *
 * 11 27 2010 zhanying.liu
 * removed!
 * .add srv_ftps_set_permission() in FTP service
 *
 * 11 23 2010 zhanying.liu
 * removed!
 * .BT CM revise code check in
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 * 
 *-----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *=============================================================================
 ******************************************************************************/

#ifndef __FtpSrvGprots_H__
#define __FtpSrvGprots_H__
// RHR: add
#include "MMI_features.h"
#include "stack_msgs.h"
#include "MMIDataType.h"
#include "MMI_conn_app_trc.h"
#include "GlobalConstants.h"
#include "kal_general_types.h"
// RHR: add

#include "BtcmSrvGprot.h"


#ifdef __cplusplus
extern "C"
{
#endif

#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)

/*****************************************************************
 *   External GLOBAL VARIABLE
 ****************************************************************/

/* FTP Client memory buffer size */
#ifndef __LOW_COST_SUPPORT_COMMON__
#define FTPC_MEM_BUFF_SIZE              (14336)
#else
#define FTPC_MEM_BUFF_SIZE              (7168)
#endif    
/* indicate the unknown size */
#define SRV_FTP_UNKNOWN_SIZE            0xFFFFFFFF

/* OBEX FTP UUID */
extern const kal_uint8 OBEX_FTP_UUID[];


/************************************************************************
 * External APIs
 ************************************************************************/

/****************************************************************************** 
 * FUNCTION
 *  srv_ftp_init
 * DESCRIPTION
 *  this function is to init ftp (both client and server if support)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
extern void srv_ftp_init(void);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftp_deinit
 * DESCRIPTION
 *  this function is to deinit ftp (both client and server if support)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
extern void srv_ftp_deinit(void);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftp_event_handle
 * DESCRIPTION
 *  this function is to handle the ftp protocol event
 * PARAMETERS
 *  msg_id:    [IN]    event id
 *  msg:       [IN]    message
 *  
 * RETURNS
 *  void
 ******************************************************************************/
extern void srv_ftp_event_handle(msg_type msg_id, void* msg);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftp_usb_plugin_check
 * DESCRIPTION
 *  the check func for callback when usb mass plug in
 * PARAMETERS
 *  void
 * RETURNS
 *  True: execute;
 *  False: not execute
 ******************************************************************************/
extern MMI_BOOL srv_ftp_usb_plugin_check(void);


/* the form of the FTP notification callback */
typedef void (*ftp_notify)(S32 hd, U16 event, void* para);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftp_open
 * DESCRIPTION
 *  this function is to open a service handler
 * PARAMETERS
 *  role:    [IN]    identify to open a client or server service handler
 *  
 * RETURNS
 *  positive number: valid service handler
 *  negative number: invalid service handler
 ******************************************************************************/
extern S32 srv_ftp_open(U16 role);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftp_close
 * DESCRIPTION
 *  this function is to close a service handler
 * PARAMETERS
 *  srv_hd:    [IN]    service handler
 *  
 * RETURNS
 *  SRV_FTP_RESULT_OK: success
 *  SRV_FTP_INVALID_HANDLE: failed due to invalid handler
 ******************************************************************************/
extern S32 srv_ftp_close(S32 srv_hd);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftp_set_notify
 * DESCRIPTION
 *  this function is to set callback function to the service
 * PARAMETERS
 *  srv_hd:        [IN]    service handle
 *  notifier:      [IN]    callback function
 *  event_mask:    [IN]    event mask, service will call the callback function according to the event mask
 *  
 * RETURNS
 *  SRV_FTP_RESULT_OK: success
 *  SRV_FTP_INVALID_HANDLE: the reason is invalid handler
 ******************************************************************************/
extern S32 srv_ftp_set_notify(S32 srv_hd, ftp_notify notifier, U16 event_mask);


#ifdef __MMI_FTC_SUPPORT__
/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_connect_server
 * DESCRIPTION
 *  this function is to initiate the action to connect ftp server
 * PARAMETERS
 *  srv_hd:     [IN]    service handler
 *  bd_addr:    [IN]    bluetooth device address
 *  
 * RETURNS
 *  SRV_FTP_RESULT_OK: success
 *  SRV_FTP_RESULT_FAIL: invalid handler
 ******************************************************************************/
extern S32 srv_ftpc_connect_server(S32 srv_hd, srv_bt_cm_bt_addr bd_addr);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_disconnect_server
 * DESCRIPTION
 *  this function is used to set screen delete callback,
 *  when the screen is deleted, it may call this function
 * PARAMETERS
 *  hd:    [IN]    service handler
 *  
 * RETURNS
 *  void
 ******************************************************************************/
extern void srv_ftpc_disconnect_server(S32 hd);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_disconnect_conn
 * DESCRIPTION
 *  this function is to disconnect ftp server with connection ID
 * PARAMETERS
 *  conn_id:    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
extern void srv_ftpc_disconnect_conn(U32 conn_id);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_is_running
 * DESCRIPTION
 *  this function is to judge whether ftp client is running
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: ftp client is running
 *  MMI_FALSE: ftp client is not running
 ******************************************************************************/
extern MMI_BOOL srv_ftpc_is_running(void);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_is_receiving
 * DESCRIPTION
 *  this function is to judge whether ftp client is receiving
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: ftp client is receiving
 *  MMI_FALSE: ftp client is not receiving
 ******************************************************************************/
extern MMI_BOOL srv_ftpc_is_receiving(void);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_is_aborting
 * DESCRIPTION
 *  this function is to judge whether ftp client is aborting
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: ftp client is aborting
 *  MMI_FALSE: ftp client is not aborting
 ******************************************************************************/
extern MMI_BOOL srv_ftpc_is_aborting(void);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_stop_receiving
 * DESCRIPTION
 *  this function is to deal with the scenario that USB plugs in
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
extern void srv_ftpc_stop_receiving(void);
#endif /* __MMI_FTC_SUPPORT__ */


#ifdef __MMI_FTS_SUPPORT__
/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_activate
 * DESCRIPTION
 *  this function is to activate ftp server
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
extern void srv_ftps_activate(void);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_deactivate
 * DESCRIPTION
 *  this function is to deactivate ftp server
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
extern void srv_ftps_deactivate(void);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_disconnect_client
 * DESCRIPTION
 *  this function is to disconnect ftp client
 * PARAMETERS
 *  bd_addr:      [IN]    bluetooth device address
 *  
 * RETURNS
 *  void
 ******************************************************************************/
extern void srv_ftps_disconnect_client(srv_bt_cm_bt_addr bd_addr);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_disconnect_conn
 * DESCRIPTION
 *  this function is to disconnect ftp client with connection ID
 * PARAMETERS
 *  conn_id:    [IN]    connection ID
 *  
 * RETURNS
 *  void
 ******************************************************************************/
extern void srv_ftps_disconnect_conn(U32 conn_id);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_is_receiving
 * DESCRIPTION
 *  this function is to judge whether ftp server is receiving
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: ftp server is receiving
 *  MMI_FALSE: ftp server is not receiving
 ******************************************************************************/
extern MMI_BOOL srv_ftps_is_receiving(void);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_stop_receiving
 * DESCRIPTION
 *  this function is to deal with the scenario that USB plugs in
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
extern void srv_ftps_stop_receiving(void);
#endif /* __MMI_FTS_SUPPORT__ */ 


/*****************************************************************
 *   Internal Global Variable
 *****************************************************************/

//#define SRV_FTP_MAX_OBJ_SIZE_LEN         (16)             /* object size buffer's length */

/* for add trace */
#define MMI_FTP_TRC_CLASS                MMI_CONN_TRC_G7_BT
/* object cteated date buffer's length */
#define SRV_FTP_MAX_OBJ_CREATED_DATE_LEN (80)
/* extention name length, is used for storage the truncated name's extention name */
#define SRV_FTP_FILE_EXTENTION_LEN       (5)



/* ftp success result */
#define SRV_FTP_RESULT_OK      (0)
/* ftp faild result */
#define SRV_FTP_RESULT_FAIL    (-1)
/* ftp invalid handler */
#define SRV_FTP_INVALID_HANDLE (-2)


/* MMI usb context bit-wise flag defination */

/* success */
#define SRV_FTP_MASK_RESULT_OK          (0x00)

//#define SRV_FTP_MASK_FOLDER_ERR       (0x01)

/* write file fail */
#define SRV_FTP_MASK_WRITE_FILE_FAIL    (0x04)
/* disk is full */
#define SRV_FTP_MASK_DISK_FULL          (0x08)
/* root directory is full */
#define SRV_FTP_MASK_ROOT_DIR_FULL      (0x10)
/* driver is exported(usb plugin) */
#define SRV_FTP_MASK_DEVICE_EXPORTED    (0x20)

//#define SRV_FTP_MASK_RESERVED_5       (0x40)
//#define SRV_FTP_MASK_RESERVED_6       (0x80)
/* When long fs operation on card, fs api will become Non-blockong */

/* device is busy */
#define SRV_FTP_MASK_FS_DEVICE_BUSY     (0x100)
/* file system lock */
#define SRV_FTP_MASK_FS_LOCK_MUTEX_FAIL (0x200)
/* memory card is removed */
#define SRV_FTP_MASK_FS_NO_CARD         (0x400)
/* file system write protection */
#define SRV_FTP_MASK_FS_WRITE_PROTEC    (0x800)
/* fail from remote device */
#define SRV_FTP_MASK_RESULT_FAIL        (0x1000)

/* ftp object type enum, to identify the selected object type */
typedef enum
{
    SRV_FTP_OBJ_TYPE_NONE,   /* the initial state */
    SRV_FTP_OBJ_TYPE_FILE,   /* means the obj is a file */
    SRV_FTP_OBJ_TYPE_FOLDER, /* means the obj is a folder */
    SRV_FTP_OBJ_TYPE_END_OF_ENUM
} srv_ftp_obj_type_enum;


/* ftp client notify enum */
typedef enum
{
    SRV_FTPC_NOTIFY_DISK_FULL,               /* Disk full. */
    SRV_FTPC_NOTIFY_ROOT_DIR_FULL,           /* Root Directory full. */
    SRV_FTPC_NOTIFY_WRITE_FILE_FAIL,         /* Write File Fail. */
    SRV_FTPC_NOTIFY_CONNECTION_DISCONNECTED, /* Failure occurs in bluetooth connection disconnected */
    SRV_FTPC_NOTIFY_REJECT_FROM_SERVER,      /* Failure occurs due to server's rejection */
    SRV_FTPC_NOTIFY_ACTION_NOT_ALLOWED,      /* Failure occurs due to wrong state */
    SRV_FTPC_NOTIFY_BROWSE_FILES_FAILED,     /* Setting folder failed, popup string */
    SRV_FTPC_NOTIFY_GOEP_STATUS_BUSY,        /* connect_rsp failed with goep_status_busy, popup string */
    SRV_FTPC_NOTIFY_WORK_FOLDER_NO_EXIST,    /* workong folder z:\@folder\ not exist */
    SRV_FTPC_NOTIFY_FS_DEVICE_BUSY,          /* 6223P:  FS API card non blocking */
    SRV_FTPC_NOTIFY_NO_CARD,                 /* Device not found */
    SRV_FTPC_NOTIFY_FS_WRITE_PROTEC,         /* fs write protect */
    SRV_FTPC_NOTIFY_LAST                     /* This is the last error type */
} srv_ftpc_notify_enum;


/* ftp entity struct */
typedef struct
{
    /* short name is only for display*/
    U16 name[MAX_SUBMENU_CHARACTERS + (SRV_FTP_FILE_EXTENTION_LEN - 3) + 1]; /* 3 means the length of "...",
                                                                              * here will use the length to save the extention name */
    U16 actual_name_len;                                    /* actual name length*/
    U16 created_date[SRV_FTP_MAX_OBJ_CREATED_DATE_LEN / 2]; /* create date buffer */

    //U16 size[SRV_FTP_MAX_OBJ_SIZE_LEN / 2];               /* object size buffer */

    U32 size;                                               /* 0xFFFFFFFF means unkonw size */
    U8  type;                                               /* object type: identify file or folder */
} srv_ftp_entity_struct;


/* ftp role enum */
typedef enum
{
    SRV_FTP_ROLE_CLIENT, /* FTP client */
    SRV_FTP_ROLE_SERVER, /* FTP server */
    SRV_FTP_ROLE_END_OF_ENUM
} srv_ftp_role_enmu;


#ifdef __MMI_FTC_SUPPORT__
/* ftp client display folder enum */
typedef enum
{
    SRV_FTPC_FOLDER_FULL,       /* get all the folder content */
    SRV_FTPC_FOLDER_PARTIAL,    /* get only partial of the folder content */
    SRV_FTPC_FOLDER_EMPTY,      /* faild to get the folder content */
    SRV_FTPC_FOLDER_END_OF_ENUM
} srv_ftpc_disp_folder_enum;


/* ftp client event enum */
typedef enum
{
    SRV_FTPC_EVENT_CONNECT            = 0x0001, /* connect operation */
    SRV_FTPC_EVENT_SET_FOLDER         = 0x0002, /* set folder path */
    SRV_FTPC_EVENT_GET_FOLDER_CONTENT = 0x0004, /* get folder content */
    SRV_FTPC_EVENT_RECEV_PROGRESSING  = 0x0008, /* ftpc receive progress */
    SRV_FTPC_EVENT_GET_FILE           = 0x0010, /* pull file from server */
    SRV_FTPC_EVENT_DISCONNECT         = 0x0020, /* disconnect operation */
    SRV_FTPC_EVENT_END_OF_ENUM
} srv_ftpc_event_enum;


/* ftp client set folder enum */
typedef enum
{
    SRV_FTPC_SET_FOLDER_SUCCESS,            /* success to set folder forward */
    SRV_FTPC_SET_FOLDER_BACK_SUCCESS,       /* success to back to parent folder */
    SRV_FTPC_SET_FOLDER_BACK_ROOT_SUCCESS,  /* success to back to root folder */
    SRV_FTPC_SET_FOLDER_NOT_ALLOWED,        /* it can't do the set folder action for service under current state */
    SRV_FTPC_SET_FOLDER_REJECT_FROM_SERVER, /* set folder forward fail */
    SRV_FTPC_SET_FOLDER_BACK_FAIL,          /* faild to back to parent folder or root folder */

    //SRV_FTPC_SET_FOLDER_FAIL,             /* back parent or back root  */
    //SRV_FTPC_SET_FOLDER_BACK_ROOT_FAIL,

    SRV_FTPC_SET_FOLDER_END_OF_ENUM
} srv_ftpc_set_folder_enum;


/* ftp client set folder struct */
typedef struct
{
    U16 result; /* set folder result */
} srv_ftpc_set_folder_struct;

    
/* ftp client connect result enum */
typedef enum
{
    SRV_FTPC_CONNECT_SUCCESS,              /* success */
    SRV_FTPC_CONNECT_REJECT_FROM_SERVER,   /* unauthorized */
    SRV_FTPC_CONNECT_SCO_REJECT,           /* rsp->rsp_code == GOEP_STATUS_SCO_REJECT */
    SRV_FTPC_CONNECT_FAIL,                 /* connect fail */

    //SRV_FTPC_CONNECT_DEVICE_BLOCKED,     /* blocked device */
    //SRV_FTPC_CONNECT_DEVICE_BUSY,        /* is in mass storage mode */
    //SRV_FTPC_CONNECT_REJECT_NOT_ALLOWED, /* rsp->rsp_code == GOEP_STATUS_SCO_REJECT */

    SRV_FTPC_CONNECT_END_OF_ENUM
} srv_ftpc_connect_enum;


/* ftp client get folder result enum */
typedef enum
{
    SRV_FTPC_GET_FOLDER_SUCCESS,          /* success to get folder content */
    SRV_FTPC_GET_FOLDER_FAIL,             /* fail to get the content of server's folder content */
    SRV_FTPC_GET_FOLDER_PATIAL_CONTENT,   /* parse file fail, include parser initialization fails,
                                           * it means it will has parsed 0 or some files */

    //SRV_FTPC_GET_FOLDER_FAIL,           /* means it is wrong to call service API this time */
    //SRV_FTPC_GET_FOLDER_NOT_ALLOWED,    /* incorrect state to call the service API */
    //SRV_FTPC_GET_FOLDER_FAIL_FINAL,     /* fail to get the content of server's folder content */

    SRV_FTPC_GET_FOLDER_END_OF_ENUM
} srv_ftpc_get_folder_enum;
    

/* ftp client get file result enum */
typedef enum
{
    SRV_FTPC_GET_FILE_SUCCESS,               /* success */
    SRV_FTPC_GET_FILE_DISK_FULL,             /* disk is full */
    SRV_FTPC_GET_FILE_NO_CARD,               /* memory card removed */
    SRV_FTPC_GET_FILE_WRITE_FILE_FAIL,       /* write file fail */
    SRV_FTPC_GET_FILE_GOEP_STATUS_BUSY,
    SRV_FTPC_GET_FILE_FAIL,                  /* it is wrong to call service API this time */

    //SRV_FTPC_GET_FILE_FOLDER_NOT_EXIST,    /* folder doesn't exist */
    //SRV_FTPC_GET_FILE_FS_DEVICE_BUSY,      /* write file error */
    //SRV_FTPC_GET_FILE_FS_WRITE_PROTECTION, /* write protection */
    //SRV_FTPC_GET_FILE_NOT_ALLOWED,         /* incorrect state to call service API */
    //SRV_FTPC_GET_FILE_GOEP_STATUS_BUSY,
    //SRV_FTPC_GET_FILE_ROOT_DIR_FULL,       /* root dir full */

    SRV_FTPC_GET_FILE_END_OF_ENUM
} srv_ftpc_get_file_enum;


/* ftp client connect struct */
typedef struct
{
    MMI_BOOL          is_abort_from_client; /* whether it is abort the connection from client */
    srv_bt_cm_bt_addr bd_address;           /* bluetooth device address */
    U32               cm_conn_id;           /* connection id */
    U8                req_id;               /* request id */
    U8                connect_result;       /* connect result */

    //srv_ftpc_connect_enum connect_result;
} srv_ftpc_connect_struct;


/* ftp client get folder struct */
typedef struct
{
    U16 entity_cnt;             /* entity(file and folder) count */
    U16 file_cnt;               /* file count */
    U16 result;                 /* get folder result */
} srv_ftpc_get_folder_struct;


/* ftp client get file struct */
typedef struct
{
    U8       result;               /* get file result */
    MMI_BOOL is_abort_from_client; /* whether is abort from client */
} srv_ftpc_get_file_struct;


/* ftp client disconnect struct */
typedef struct
{
    MMI_BOOL          is_from_client; /* 1: from client, 0 from server */
    U8                req_id;         /* request id */
    srv_bt_cm_bt_addr bd_address;     /* bluetooth device address */
    U32               cm_conn_id;     /* connection id */
} srv_ftpc_disconnect_struct;


/********************************************************************************
 *    Internal APIs
 ********************************************************************************/

/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_get_obj_info
 * DESCRIPTION
 *  this function is to get an object's(folder or file) information,
 *  if the actual name's length is longer than 41, it will give a truncated name with extention name,
 *  if want to get the actual name, please use the following API
 * PARAMETERS
 *  hd:          [IN]    service handler
 *  index:       [IN]    object index in the folder content list
 *  entity_p:    [OUT]   memory address for writting the the object information
 *  
 * RETURNS
 *  nonnegative number: success
 *  negative number: failded to get the object actual name
 ******************************************************************************/
extern S32 srv_ftpc_get_obj_info(S32 hd, U16 index, srv_ftp_entity_struct* entity_p);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_get_obj_detail_info
 * DESCRIPTION
 *  this function is to get an object's(folder or file) actual name
 * PARAMETERS
 *  hd:               [IN]    service handler
 *  index:            [IN]    object index in current folder
 *  actual_name_p:    [IN]    object name pointer
 *  
 * RETURNS
 *  nonnegative number: success
 *  negative number: failded to get the object actual name
 ******************************************************************************/
extern S32 srv_ftpc_get_obj_detail_info(S32 hd, U16 index, U16* actual_name_p);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_change_folder
 * DESCRIPTION
 *  this function is to change folder forward
 * PARAMETERS
 *  hd:       [IN]   service handler
 *  index:    [IN]   the folder index in the folder content list
 *  
 * RETURNS
 *  SRV_FTP_RESULT_OK: success to initiate the change folder forward action
 *  SRV_FTP_RESULT_FAIL: failed to initiate the change folder forward action
 ******************************************************************************/
extern S32 srv_ftpc_change_folder(S32 hd, U16 index);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_refresh_folder
 * DESCRIPTION
 *  this function is to refresh the current folder content
 * PARAMETERS
 *  hd:    [IN]    srvice handle
 *  
 * RETURNS
 *  SRV_FTP_RESULT_OK: success
 *  SRV_FTP_RESULT_FAIL: failed
 ******************************************************************************/
extern S32 srv_ftpc_refresh_folder(S32 hd);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_back_folder
 * DESCRIPTION
 *  this function is to go back to the parent folder
 * PARAMETERS
 *  hd:    [IN]    service handler
 *  
 * RETURNS
 *  SRV_FTP_RESULT_OK: success to initiate back parent folder action
 *  SRV_FTP_INVALID_HANDLE, SRV_FTP_RESULT_FAIL: failed to initiate back parent folder action
 ******************************************************************************/
extern S32 srv_ftpc_back_folder(S32 hd);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_back_root_folder
 * DESCRIPTION
 *  this function is to go back to the root folder
 * PARAMETERS
 *  hd:    [IN]    service handler
 *  
 * RETURNS
 *  SRV_FTP_RESULT_OK: success to initiate the back root folder action
 *  SRV_FTP_RESULT_FAIL, SRV_FTP_INVALID_HANDLE: faild to initiate the back root folder action
 ******************************************************************************/
extern S32 srv_ftpc_back_root_folder(S32 hd);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_get_file
 * DESCRIPTION
 *  this function is to initiate the action to get a file
 * PARAMETERS
 *  hd:           [IN]    service handler
 *  index:        [IN]    file index in the folder content list
 *  recv_path:    [IN]    the path to save the file
 *  
 * RETURNS
 *  SRV_FTPC_GET_FILE_SUCCESS: success to initiate pulling a file action
 *  SRV_FTPC_GET_FILE_FAIL: failed to get a file, such as index is wrong, invalid service handler
 ******************************************************************************/
extern S32 srv_ftpc_get_file(S32 hd, U16 index, const U16* recv_path);


/****************************************************************************** 
 * FUNCTION
 *  
 * DESCRIPTION
 *  this function is to abort current action,
 *  including abort connection and abort getting a file
 * PARAMETERS
 *  hd:    [IN]    service handler
 *  
 * RETURNS
 *  SRV_FTP_RESULT_OK: success to initiate abort
 *  SRV_FTP_RESULT_FAIL: failed to abort, such as invalid handler or incorrect state
 ******************************************************************************/
extern S32 srv_ftpc_abort(S32 hd);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_get_total_obj_size
 * DESCRIPTION
 *  this function is to return total object size if there is any, or it will return 0xFFFFFFFF
 * PARAMETERS
 *  void
 * RETURNS
 *  total object size 
 *  if there is none, it will return 0xFFFFFFFF
 ******************************************************************************/
extern U32 srv_ftpc_get_total_obj_size(void);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_get_recved_obj_size
 * DESCRIPTION
 *  this function is to get the current received object size for display.
 * PARAMETERS
 *  void
 * RETURNS
 *  received object size
 ******************************************************************************/
extern U32 srv_ftpc_get_recved_obj_size(void);



/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_get_fileindex
 * DESCRIPTION
 *  this function is to get the n-th file index in the folder content
 * PARAMETERS
 *  hd:       [IN]    service handle
 *  index:    [IN]    nth file
 *  
 * RETURNS
 *  index    the file index in the folder content, note:0xFF means no such file index
 ******************************************************************************/
extern U16 srv_ftpc_get_fileindex(S32 hd, U16 index);
#endif /* __MMI_FTC_SUPPORT__ */


#ifdef __MMI_FTS_SUPPORT__

/* ftp server handle value domain */
#define SRV_FTP_SERVER_HANDLE_DOMAIN (100)

/* ftp server event enum */
typedef enum
{
    SRV_FTPS_EVENT_START              = 0x0001, /* ftp server sdp */
    SRV_FTPS_EVENT_STOP               = 0x0002, /* ftp server deregister */
    SRV_FTPS_EVENT_CONNECT            = 0x0004, /* ftp connect indication */
    SRV_FTPS_EVENT_AUTHORIZE          = 0x0008, /* ftp authorize indication */
    SRV_FTPS_EVENT_DISCONNECT         = 0x0010, /* disconnect operation */
    SRV_FTPS_EVENT_SET_PATH           = 0x0020, /* set folder operation */
    SRV_FTPS_EVENT_OPERATION_BEGIN    = 0x0040, /* ftp server operation begin, such as push */
    SRV_FTPS_EVENT_OPERATION_PROGRESS = 0x0080, /* ftp server operation process, such as push */
    SRV_FTPS_EVENT_OPERATION_END      = 0x0100, /* ftp server operation end, such as push */
    SRV_FTPS_EVENT_END_OF_ENUM
} srv_ftps_event_enum;


/* ftp server start sdp result enum */
typedef enum
{
    SRV_FTPS_START_OK,          /* ftp server start(sdp) success */
    SRV_FTPS_START_FAIL,        /* ftp server start(sdp) fail */
    SRV_FTPS_START_END_OF_ENUM
} srv_ftps_start_enum;

typedef enum
{
    SRV_FTPS_PERMISSION_FULL_CONTROL,
    SRV_FTPS_PERMISSION_READ_ONLY,
    SRV_FTPS_PERMISSION_TOTAL
} srv_ftps_access_right_enum;

/* ftp server start indication struct */
typedef struct
{
    U16 result;                 /* service start indication result */
} srv_ftps_start_indication_struct;

    
/* ftp server authorize indication struct */
typedef struct
{
    U32               conn_id;    /* connection id */
    srv_bt_cm_bt_addr bd_address; /* bluetooth device address */
    U8*               dev_name_p; /* device name pointer, in the format of utf-8 */
} srv_ftps_authorize_indication_struct;


/* typedef enum */
/* { */
/*     SRV_FTPS_OPERATION_OK, */
/*     SRV_FTPS_OPERATION_WRITE_FILE_FAIL, */
/*     SRV_FTPS_OPERATION_FS_DEVICE_BUSY, */
/*     SRV_FTPS_OPERATION_DISK_FULL, */
/*     SRV_FTPS_OPERATION_ROOT_DIR_FULL, */
/*     SRV_FTPS_OPERATION_NO_CARD, */
/*     SRV_FTPS_OPERATION_WRITE_PROTEC, */
/*     SRV_FTPS_OPERATION_DEVICE_EXPORTED, */
/*     SRV_FTPS_OPERATION_RESULT__END_OF_ENUM */
/* } srv_ftps_operation_result_enum; */


/* ftp server connect indication struct */
typedef struct
{
    srv_bt_cm_bt_addr bd_address; /* bluetooth device address */
    U32               cm_conn_id; /* cm connection id */
} srv_ftps_connect_indication_struct;


/* ftp server disconnect indication struct */
typedef struct
{
    srv_bt_cm_bt_addr bd_address; /* bluetooth device address */
    U32               cm_conn_id; /* cm connection id */
} srv_ftps_disconnect_indication_struct;


/* typedef struct */
/* { */
/*     srv_ftps_event_error_enum set_folder_result; */
/* } srv_fpts_set_folder_struct; */


/* ftp server operation type enum */
typedef enum
{
    SRV_FTPS_OPERATION_PULL,    /* pull operation */
    SRV_FTPS_OPERATION_PUSH,    /* push operation */
    SRV_FTPS_OPERATION_DELETE,  /* delete operation */
    SRV_FTPS_OPERATION_END_OF_ENUM
} srv_ftps_operation_enum;


/* ftp server operation begin struct */
typedef struct
{
    U8   operation;             /* operation, such as pull or push, etc */
    U8   result;                /* operation result */
    U16* name_p;                /* ojbect name */
    U32  obj_total_size;        /* ojbect total size */

    //U16 name[(SRV_FMGR_PATH_MAX_LEN+1) * ENCODING_LENGTH];
    //goep_push_ind_struct* ind;
} srv_ftps_operation_begin_struct;


/* ftp server operation process struct */
typedef struct
{
    U8  operation;              /* operation, such as pull or push, etc */
    U32 result;                 /* operation result */
    U32 obj_operation_size;     /* current operation size, such as pulled size or pushed size */
} srv_ftps_operation_progess_struct;


/* ftp server operation end struct */
typedef struct
{
    U8  operation;              /* operation, such as pull or push, etc */
    U32 result;                 /* operation result */
    U32 obj_operation_size;     /* current operation size, such as pulled size or pushed size */
} srv_ftps_operation_end_struct;
    

/********************************************************************************
 *    Internal APIs
 *********************************************************************************/

/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_authorize_accept
 * DESCRIPTION
 *  this function is to accept a connection
 * PARAMETERS
 *  hd:         [IN]    service handler
 *  
 * RETURNS
 *  SRV_FTP_RESULT_OK: success
 *  SRV_FTP_INVALID_HANDLE: invalid handler
 ******************************************************************************/
extern S32 srv_ftps_authorize_accept(S32 hd);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_authorize_reject
 * DESCRIPTION
 *  this function is to reject a connection
 * PARAMETERS
 *  hd:         [IN]    service handler
 *  
 * RETURNS
 *  SRV_FTP_RESULT_OK: success
 *  SRV_FTP_INVALID_HANDLE: invalid handler
 ******************************************************************************/
extern S32 srv_ftps_authorize_reject(S32 hd);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_accept_push_obj
 * DESCRIPTION
 *  this function is to accept the push object according to APP's behavior
 * PARAMETERS
 *  hd:           [IN]    service handler
 *  conn_id:      [IN]    connection id
 *  save_path:    [IN]    save path
 *  
 * RETURNS
 *  void
 ******************************************************************************/
extern void srv_ftps_accept_push_obj(S32 hd, U32 conn_id, U16* save_path);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_reject_push_obj
 * DESCRIPTION
 *  this function is to reject push object according to APP's behavior
 * PARAMETERS
 *  hd:         [IN]    service handler
 *  conn_id:    [IN]    connection id
 *  
 * RETURNS
 *  void
 ******************************************************************************/
extern void srv_ftps_reject_push_obj(S32 hd, U32 conn_id);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_get_current_folder
 * DESCRIPTION
 *  this function is to get the ftp server's current folder
 * PARAMETERS
 *  void
 * RETURNS
 *  U16*: the current folder address.
 ******************************************************************************/
extern U16* srv_ftps_get_current_folder(void);


/****************************************************************************** 
 * FUNCTION
 *  srv_ftps_set_permission
 * DESCRIPTION
 *  this function is to set FTP server access permission
 * PARAMETERS
 *  right:    [IN]    access right
 *  
 * RETURNS
 *  SRV_FTP_RESULT_OK:   success
 *  SRV_FTP_RESULT_FAIL: fail
 ******************************************************************************/
extern S32 srv_ftps_set_permission(S32 right);

#endif /* __MMI_FTS_SUPPORT__ */

#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */ 

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* __FtpSrvGprots_H__ */
