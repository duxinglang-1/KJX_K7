#ifndef __BACKUP_RESTORE_SRV_GPROT_H__
#define __BACKUP_RESTORE_SRV_GPROT_H__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "DtcntSrvGprot.h"
#include "CloudPlugin.h"

/* Event ID */
typedef enum
{
    SRV_CLD_STATUS_IND = 0, /* Status indication. */
    SRV_CLD_DATA_IND,       /* Data is arriving. */
} srv_backup_restore_event_enum;

/* Error code */
#define SRV_CLD_SUCCESS     (0)
#define SRV_CLD_ERROR       (-1)
#define SRV_CLD_WOULDBLOCK  (-2)

/* Error code */
typedef enum
{
    SRV_CLD_NODATA          = (-3),
    SRV_CLD_NO_MEMORY       = (-4),
    SRV_CLD_FS_ERROR        = (-5),
    SRV_CLD_NWK_ERROR       = (-6),
    SRV_CLD_GET_UID_ERROR   = (-7),
    SRV_CLD_BUSY            = (-8),
    SRV_CLD_LOGOUT          = (-9),
    SRV_CLD_NO_NEED_SYNC    = (-10),
    SRV_CLD_ACCT_ERROR      = (-11),
    SRV_CLD_NO_STORAGE      = (-12),
    SRV_CLD_DISK_FULL       = (-13)
}srv_cloud_error_type_enum;

#define SRV_CLD_URL_LEN     (256)

#define SRV_CLD_UID_LEN     (50)
#define SRV_CLD_ETAG_LEN    (20)
#define SRV_CLD_CTAG_LEN    (40)
#define SRV_CLOUD_ASM_SIZE  (100*1024)
#define SRV_CLOUD_INVALID_INDEX  (0xEEEE)

#define SRV_CLD_SMS_UID_LEN     SRV_CLD_UID_LEN

typedef struct
{
    CHAR id[SRV_CLD_UID_LEN + 1];
    CHAR tag[SRV_CLD_ETAG_LEN + 1];
} srv_cloud_uid_struct;

typedef struct
{
    U32 imap_uid;
    CHAR sms_uid[SRV_CLD_SMS_UID_LEN + 1];
} srv_cloud_sms_imap_uid_struct;

typedef enum
{
    SRV_CLD_UID_NOT_EXIST = 0,
    SRV_CLD_UID_EXIST_CHANGE,
    SRV_CLD_UID_EXIST_NOT_CHANGE
} srv_cloud_uid_exist_enum;

typedef enum
{
    SRV_CLD_TYPE_VCARD = 0, /* vCard */
    SRV_CLD_TYPE_SMS,       /* SMS */
    SRV_CLD_TYPE_TOTAL
} srv_cloud_type_enum;

typedef enum
{
    SRV_CLD_OPT_ACCT_INFO,  /* Set account info, srv_cloud_set_opt_acct_info_struct */
    SRV_CLD_OPT_DTYPE,      /* Set data type (VCard only), srv_cloud_dtype_enum */
    SRV_CLD_OPT_PROXY,      /* Set proxy (VCard only), proxy address and port. */
    SRV_CLD_OPT_TOTAL
} srv_cloud_opt_enum;

typedef enum
{
    SRV_CLD_OP_BACKUP = 0,  /* Backup. */
    SRV_CLD_OP_RESTORE,     /* Restore. */
    SRV_CLD_OP_TOTAL
} srv_cloud_op_enum;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
typedef enum
{
    SRV_CLD_DT_RECORD = 0,  /* Record data. */  /* use buffer */
    SRV_CLD_DT_URI,         /* Hypertext link. */ /* use file */
    SRV_CLD_DT_TOTAL
} srv_cloud_dtype_enum;

typedef enum
{
    SRV_CLD_ACTION_ADD,
    SRV_CLD_ACTION_DEL,
    SRV_CLD_ACTION_UPDATE,
    SRV_CLD_ACTION_TOTAL
}srv_cloud_set_store_enum;

typedef struct
{
    U32 provider;
    U8  account_id;
} srv_cloud_set_opt_acct_info_struct;

typedef S32 (*srv_cloud_uid_query_callback_ptr)(srv_cloud_uid_struct *uid, srv_cloud_uid_exist_enum *exist, void *userdata);

typedef struct
{
    srv_cloud_op_enum op_type;
} srv_cloud_op_struct;

typedef struct
{
    U16 port;
    srv_dtcnt_prof_px_srv_enum  service;
    //U8 address[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];
    U8 address[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN+1]; //URL Proxy
    U8 username[SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1];
    U8 passwd[SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1];
}srv_cloud_px_info_struct;

typedef void * ( *srv_cloud_mem_alloc)(U32 len);
typedef void ( *srv_cloud_mem_free)(void* ptr);

typedef void (*srv_cloud_set_opt_cb_t)(S32 result);

typedef struct
{
        srv_cloud_set_opt_acct_info_struct acct;    /* for SRV_CLD_OPT_ACCT_INFO */
        srv_cloud_dtype_enum data_type;             /* for SRV_CLD_OPT_DTYPE */
        srv_cloud_px_info_struct proxy;             /* for SRV_CLD_OPT_PROXY */
        srv_cloud_mem_alloc  mem_alloc;
        srv_cloud_mem_free   mem_free; 
        srv_cloud_set_opt_cb_t cb_func;             /* for asynchronous to set option */
} srv_cloud_opt_struct;

/* Vcard data structure. */
typedef struct
{
    U8 *url;
    U8 *tag;        // version
    U8 *data;       // vcard data
    U32 length;     // data buffer length
} srv_cloud_card_struct;

#define NUMBER_SEPERATOR_CHAR  ';'

/* SMS data structure. */
typedef struct
{
    U32 date;
    void *number;           // CHAR eg. "120;999;119", seperator is NUMBER_SEPERATOR_CHAR
    U32   number_buf_len;
    void *content;          // WCHAR
    U32   content_buf_len;
    void *sms_data;         // buffer
    U32    sms_data_len;
    /* TODO: need SMS owner to fill this struct */
} srv_cloud_sms_struct;



/**************************************************** 
*  struct of EVT_ID_SRV_CLD_ERROR_IND;
*
*  In both backup and restore process
*  After app call srv_cloud_operate(), it should handle this event;
*  This event indicate the error information; 
*
*  type: application type
*  error_type: root cause of fail
*
*****************************************************/
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;             /* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;        /* Piggyback user data */
#endif
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER    /* MMI_EVENT_COMMON_HEADER */
    /* DOM-NOT_FOR_SDK-END */
    srv_cloud_type_enum type;
    srv_cloud_error_type_enum error_type;
}srv_cloud_error_evt_struct;

/*********************************************************
* struct of EVT_ID_SRV_CLD_ASYNC_UID_DONE_IND;
*
* In both backup and restore process
* After app call srv_cloud_async_set_store_uid(), it should handle this event;
* When async add done, service post this event to app
*
* type: application type
*
************************************************************/
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;             /* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;        /* Piggyback user data */
#endif
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER    /* MMI_EVENT_COMMON_HEADER */
    /* DOM-NOT_FOR_SDK-END */
    srv_cloud_type_enum type;

}srv_cloud_post_async_done_evt_struct;


/****************************************************
* struct of EVT_ID_SRV_CLD_BACKUP_BEGIN_IND
*
* In backup process
* After app call srv_cloud_operate(), it should handle this event;
* This event notify application to begin backup.
*
* type: application type
*
*****************************************************/
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;             /* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;        /* Piggyback user data */
#endif
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER    /* MMI_EVENT_COMMON_HEADER */
    /* DOM-NOT_FOR_SDK-END */
    srv_cloud_type_enum type;

}srv_cloud_post_backup_begin_evt_struct;


/***********************************************************
* struct of EVT_ID_SRV_CLD_PUT_DATA_RES_IND
*
* In backup process
* After app call srv_cloud_put_data(), it should handle this event;
* This event return the result of put_data.
*
* result: 0, success
*
************************************************************/
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;             /* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;        /* Piggyback user data */
#endif
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER    /* MMI_EVENT_COMMON_HEADER */
    /* DOM-NOT_FOR_SDK-END */
    U8 result;
    srv_cloud_type_enum type;
}srv_cloud_put_data_result_evt_struct;


/***************************************************************
* struct of EVT_ID_SRV_CLD_CLOSE_DONE_IND
*
* In both backup and restore process
* After app call srv_cloud_close(), it should handle this event;
* This event notify application service is closed done.
*
* type: application type
*
****************************************************************/
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;             /* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;        /* Piggyback user data */
#endif
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER    /* MMI_EVENT_COMMON_HEADER */
    /* DOM-NOT_FOR_SDK-END */
    srv_cloud_type_enum type;
}srv_cloud_post_close_done_struct;


/**********************************************************
* struct of EVT_ID_SRV_CLD_GET_DATA_IND
*
* In restore process
* After app call srv_cloud_operate(), it should handle this event;
* This event means application should get data from service.
*
* type: application type
* over_flag: FALSE, app should get data; 
*               TRUE, there is no data anymore;
*
************************************************************/
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;             /* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;        /* Piggyback user data */
#endif
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER    /* MMI_EVENT_COMMON_HEADER */
    /* DOM-NOT_FOR_SDK-END */
    U16 index;
    MMI_BOOL over_flag;
    srv_cloud_type_enum type;
    U8 is_add;
}srv_cloud_get_data_ind_evt_struct;



typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;     
    U16 size;           
    void *user_data;   
#endif
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER    /* MMI_EVENT_COMMON_HEADER */
    /* DOM-NOT_FOR_SDK-END */
    U32 count;
    srv_cloud_type_enum type;
}srv_cloud_progress_ind_evt_struct;



/******************************************************************************
 * FUNCTION
 *     srv_cloud_create
 * DESCRIPTION
 *     Create a service descriptor for the later synchronization or backup and allocate the related resource.
 *     This is the first function to call when the application wants to synchronize or backup with the server.
 *     Only support single instance, before application call this API, should call last instance's srv_cloud_close(). 
 * PARAMETERS
 *    type   : [IN] could service type
 * RETURNS
 *    On success, return the service handle; otherwise return the error code that is less than 0.
 ******************************************************************************/
extern S32 srv_cloud_create(srv_cloud_type_enum type);

/******************************************************************************
 * FUNCTION
 *     srv_cloud_close
 * DESCRIPTION
 *    Close the service descriptor, release the related resource and free the memory occupied. 
 *    The application should call the function after it has finished the synchronize or backup.
 * PARAMETERS
 *    hdl   : [IN] service handle
 * RETURNS
 *    On success, return SRV_CLD_SUCCESS; otherwise return error code.
 ******************************************************************************/
extern S32 srv_cloud_close(S32 hdl);

/******************************************************************************
 * FUNCTION
 *     srv_cloud_setopt
 * DESCRIPTION
 *    Set the user option.
 * PARAMETERS
 *    hdl   : [IN] service handle
 *    opt   : [IN] set option type
 * RETURNS
 *    On success, return SRV_CLD_SUCCESS; otherwise return error code.
 ******************************************************************************/
extern S32 srv_cloud_setopt(S32 hdl, const srv_cloud_opt_struct *opt);

/******************************************************************************
 * FUNCTION
 *     srv_cloud_operate
 * DESCRIPTION
 *    Begin an operation, such as restore, backup, synchronization etc.
 * PARAMETERS
 *    hdl   : [IN] service handle
 *    op    : [IN] operation struct pointer
 * RETURNS
 *    On success, return SRV_CLD_SUCCESS; otherwise return error code.
 ******************************************************************************/
extern S32 srv_cloud_operate(S32 hdl, const srv_cloud_op_struct *op);

/******************************************************************************
 * FUNCTION
 *     srv_cloud_abort
 * DESCRIPTION
 *    Abort the current operation
 * PARAMETERS
 *    hdl   : [IN] service handle
 * RETURNS
 *    On success, return SRV_CLD_SUCCESS; otherwise return error code.
 ******************************************************************************/
extern S32 srv_cloud_abort(S32 hdl);

/******************************************************************************
 * FUNCTION
 *     srv_cloud_get_data
 * DESCRIPTION
 *    Get the data from the server. It indicates there is not more data if it returns SRV_CLD_NODATA.
 * PARAMETERS
 *    hdl   : [IN]  service handle
 *    buf   : [OUT] data struct pointer
 *    num   : [OUT] record number
 *    len   : [OUT] written length
 * RETURNS
 *    On success, return SRV_CLD_SUCCESS; otherwise return error code.
 ******************************************************************************/
extern S32 srv_cloud_get_data(S32 hdl, void *buf, U32 *num, U32 *len);

/******************************************************************************
 * FUNCTION
 *     srv_cloud_put_data
 * DESCRIPTION
 *    Put  the data to the service.
 *    if len = 0, buf is the file name; if len >0, buf is record data; if buf = NULL and len = 0, there is no more data.
 * PARAMETERS
 *    hdl   : [IN] service handle
 *    buf   : [IN] data struct pointer or file path pointer
 *    num   : [IN] index of a SMS or vCard
 *    len   : [IN] buffer length
 * RETURNS
 *    On success, return SRV_CLD_SUCCESS; otherwise return error code.
 ******************************************************************************/
extern S32 srv_cloud_put_data(S32 hdl, const void *buf, U32 num, U32 len);

/******************************************************************************
 * FUNCTION
 *     srv_cloud_put_data_commit
 * DESCRIPTION
 *    Notify service put data done
 * PARAMETERS
 *    hdl   : [IN] service handle
 * RETURNS
 *    void
 ******************************************************************************/
extern void srv_cloud_put_data_commit(S32 hdl);

/******************************************************************************
 * FUNCTION
 *     srv_cloud_backup_uid_check
 * DESCRIPTION
 *    Check whether this index need to backup
 * PARAMETERS
 *    index   : [IN] index of item
 *    type   : [IN] SMS or vCard
 * RETURNS
 *    If exist, return 1, otherwise return 0. For errors, return value < 0
 ******************************************************************************/
MMI_BOOL srv_cloud_backup_uid_check( U16 index, srv_cloud_type_enum type);


/******************************************************************************
*Fucntion
*  srv_cloud_sync_set_store_uid
*DESCRIPTION
*  Sync pdata uid list in the database
*  When app add/delete/update a record, App call this API to update the UID store in service 
*PARAMETERS
*  index : [IN] id of a vCard or SMS
*  uid :    [IN] new uid, if application doesn't store UID, please pass NULL
*  type:   [IN] SMS or vCard
*  action: [IN] add or delete or update
*RETURNS
*  if success return SRV_CLD_SUCCESS; otherwise return error code.
******************************************************************************/
extern S32 srv_cloud_sync_set_store_uid(U16 index, 
                                 srv_cloud_uid_struct *uid, 
                                 srv_cloud_type_enum type, 
                                 srv_cloud_set_store_enum action);

/**********************************************************************************
*Fucntion
*  srv_cloud_async_get_store_uid
*DESCRIPTION
*  Get UID from NVRAM 
*PARAMETERS
*  index : [IN] id of a vCard or SMS
*  uid :    [OUT] UID in the NVRAM
*  type:   [IN] SMS or vCard
*RETURNS
*  if success return SRV_CLD_SUCCESS; otherwise return error code.
************************************************************************************/
extern S32 srv_cloud_sync_get_store_uid(U16 index, 
                               srv_cloud_uid_struct *uid, 
                               srv_cloud_type_enum type);

/**********************************************************************************
*Fucntion
*  srv_cloud_async_set_store_uid
*DESCRIPTION
*  Async updata uid list store in the database 
*PARAMETERS
*  buf :    [IN]  app use this buf to store the index set
*  num :   [IN]  num of index in buf
*  type:   [IN]  SMS or vCard
*  action: [IN]  only support ADD now
*RETURNS
*  if success return SRV_CLD_SUCCESS; otherwise return error code.
************************************************************************************/

extern S32 srv_cloud_async_set_store_uid(U16 * buf, U16 num, 
                                        srv_cloud_type_enum type,
                                        srv_cloud_set_store_enum action);


/**********************************************************************************
*Fucntion
*  srv_cloud_is_support_backup_restore
*DESCRIPTION
*  Check the provider whether support backup restore feature 
*PARAMETERS
*  type:   [IN]  SMS or vCard
*  id:       [IN]  provider id
*RETURNS
*  if support return MMI_TRUE; otherwise return MMI_FALSE.
************************************************************************************/

extern MMI_BOOL srv_cloud_is_support_backup_restore(srv_cloud_type_enum type, U32 id);

/**********************************************************************************
*Fucntion
*  srv_cloud_support_backup_restore_list
*DESCRIPTION
*  Check the provider list that support backup restore feature 
*PARAMETERS
*  type:   [IN]  SMS or vCard
*  id:       [OUT]  provider id list
* num:     [OUT] list num
*RETURNS
*  NULL
************************************************************************************/

extern void srv_cloud_support_backup_restore_list(srv_cloud_type_enum type, U32* id, U8 * num);


/**********************************************************************************
*Fucntion
*  srv_cloud_query_provider_info
*DESCRIPTION
*  get provider info 
*PARAMETERS
*  id:       [IN]      provider id
*  info:    [OUT]   provider info
*RETURNS
*  if find the provider info, return MMI_TRUE; otherwise return MMI_FALSE.
************************************************************************************/

extern MMI_BOOL srv_cloud_query_provider_info( U32 id, cloud_plugin_provider_struct * info);

extern MMI_BOOL srv_cloud_query_server_info(U32 id, U32 feature, cloud_plugin_server_info_struct *info);

extern S32 srv_cloud_retry(S32 hdl, srv_cloud_set_opt_acct_info_struct *acct);
extern MMI_BOOL srv_cloud_add_real_time(srv_cloud_type_enum type);


#endif /* */

