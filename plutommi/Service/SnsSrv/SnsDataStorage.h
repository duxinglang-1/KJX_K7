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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  SnsDataStorage.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  sns data storage service
 *
 * Author:
 * -------
 * -------
 *                      
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SNS_SRV_H__
#define __SNS_SRV_H__

#include "gdi_include.h"
#include "app_ltlcom.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "FileMgrSrvGProt.h"
#include "gui_data_types.h"
#include "kal_public_defs.h"
#include "SnsSrvDefs.h"
#include "SnsSrvTypes.h"

#define SNS_DS_LOG_FILE_NAME               L"@sns\\snslog.data"
#define SNS_DS_ID_FILE_NAME                L"@sns\\id.data"
#define SNS_DS_FILE_EXTENSION              L"data"
#define SNS_DS_DEFAULT_FOLDER              L"@sns"
#define SNS_DS_TEMP_FOLDER                 L"@sns\\temp"
#define SNS_DS_BACKUP_FOLDER               L"@sns\\backup"

/* max filepath length */
#define SNS_DS_MAX_PATH_LEN                 ((SRV_FMGR_PATH_MAX_LEN+1))

#define SNS_DS_MIN_REQUIRE_STORAGE_SPACE     (5 * 1024 * 1024)

#define SNS_DS_SNS_WIDGET_SELECTED_FRIENDS_GROUP_ID   21

/* enum for open database  */
typedef enum
{
    SRV_SNS_OPEN_ONLY,   /* open directly, failed return */
    SRV_SNS_OPEN_NEW,   /* open, delete old db and create new one  */ 
    SRV_SNS_OPEN_END
}srv_sns_open_flag_enum;

/* tables */
typedef enum
{
    SRV_SNS_TABLE_FEEDS = 0,
    SRV_SNS_TABLE_FEEDS_BY_CONTACT,
    SRV_SNS_TABLE_FEEDS_OF_FRIEND,
    SRV_SNS_TABLE_MESSAGES,
    SRV_SNS_TABLE_THREADS,
    SRV_SNS_TABLE_NOTIFICATIONS,
    SRV_SNS_TABLE_REQUESTS,
    SRV_SNS_TABLE_PARTICIPANTS,
    SRV_SNS_TABLE_FRIENDS,
    SRV_SNS_TABLE_MEMBER,
    SRV_SNS_TABLE_NOT_MEMBER,
    SRV_SNS_TABLE_GROUPS,
    SRV_SNS_TABLE_ALBUMS,
    SRV_SNS_TABLE_LINK_CONTACTS,
    SRV_SNS_TABLE_NAME_INDEX,
#ifdef __MMI_SNS_CALENDAR__
    SRV_SNS_TABLE_EVENT,
    SRV_SNS_TABLE_BIRTHDAY,
#endif
    SRV_SNS_TABLE_END,
}srv_sns_tables_enum;

typedef enum
{
    SRV_SNS_DS_FILTER_BY_NONE = 0,
    SRV_SNS_DS_FILTER_BY_PROVIDER,
    SRV_SNS_DS_FILTER_BY_TYPE,
    SRV_SNS_DS_FILTER_BY_GROUP,
    SRV_SNS_DS_FILTER_BY_GROUP_IN_PROVIDER, // to find friends in group by provider
    SRV_SNS_DS_FILTER_BY_NOT_IN_GROUP,
    SRV_SNS_DS_FILTER_BY_NOT_IN_GROUP_IN_PROVIDER, // to find frineds not in group by provider
    SRV_SNS_DS_FILTER_BY_GROUP_MEMBER,
    SRV_SNS_DS_FILTER_BY_LINKED_BY_ID,
    SRV_SNS_DS_FILTER_BY_LINKED_BY_PROVIDER,
    // Since one contact id only links to one friend in provider, we do not need this enum value at all
    //SRV_SNS_DS_FILTER_BY_NOT_LINKED_BY_ID_IN_PROVIDER, 
    SRV_SNS_DS_FILTER_BY_NAME,
    SRV_SNS_DS_FILTER_BY_NAME_IN_GROUP_IN_PROVIDER,
    SRV_SNS_DS_FILTER_BY_NAME_NOT_IN_GROUP,
    SRV_SNS_DS_FILTER_BY_NAME_NOT_IN_GROUP_IN_PROVIDER,
    SRV_SNS_DS_FILTER_BY_ID,
    SRV_SNS_DS_FILTER_BY_USERS,
    SRV_SNS_DS_FILTER_BY_TIMESTAMP,
    SRV_SNS_DS_FILTER_BY_PROVIDER_USER,
    SRV_SNS_DS_FILTER_BY_FAVORITE,
#ifdef __MMI_SNS_CALENDAR__
    SRV_SNS_DS_FILTER_BY_EVENT_ALL,
    SRV_SNS_DS_FILTER_BY_EVENT_BIRTHDAY,
    SRV_SNS_DS_FILTER_BY_EVENT_SNS,
    SRV_SNS_DS_FILTER_BY_EVENT_ID,
    SRV_SNS_DS_FILTER_BY_EVENT_EARLIEST_ALARM,    
#endif    
    SRV_SNS_DS_FILTER_BY_TOTAL,
}srv_sns_ds_filter_by_enum;

typedef enum
{
    SRV_SNS_DS_REFRESH_AT_ONCE = 0,
    SRV_SNS_DS_REFRESH_START,
    SRV_SNS_DS_REFRESH_CONTINUE,
    SRV_SNS_DS_REFRESH_FINISH,
    SRV_SNS_DS_REFRESH_APPEND,
    SRV_SNS_DS_REFRESH_TOTAL,
}srv_sns_ds_refresh_enum;

typedef enum
{
    SRV_SNS_DS_UPDATE_SYNCED = 0,
}srv_sns_ds_update_field_enum;

typedef enum
{
    /* api execute OK, no error */
    SRV_SNS_DS_OK = 0,
    SRV_SNS_DS_RET_ERR_BEGIN = -5000,
    SRV_SNS_DS_RET_ERR_MEMORY_NOT_ENOUGH,
    SRV_SNS_DS_RET_ERR_CARD_NOT_EXIST,
    SRV_SNS_DS_RET_ERR_DATA_NOT_EXIST,
    SRV_SNS_DS_RET_ERR_DISK_NOT_ENOUGH,
    SRV_SNS_DS_RET_ERR_SQLITE_ERROR,
    SRV_SNS_DS_RET_ERR_PARAM_ERROR,
    SRV_SNS_DS_RET_ERR_UNKOWN_ERROR,
    SRV_SNS_DS_RET_ERR_FS_ERROR,
    SRV_SNS_DS_RET_ERR_NO_MORE_DATA,
    SRV_SNS_DS_RET_ERR_DS_NOT_READY,
    SRV_SNS_DS_RET_ERR_NOT_SUPPORTED,
    SRV_SNS_DS_RET_ERR_PROCESSING_ANOTHER_REQUEST,
    SRV_SNS_DS_RET_ERR_REQUEST_ABORT,
    SRV_SNS_DS_RET_ERR_DATA_CORRUPT_RECOVERABLE,
    SRV_SNS_DS_RET_ERR_DATA_CORRUPT_UNRECOVERABLE,
    SRV_SNS_DS_RET_ERR_DEVICE_BUSY,
    /* end of enum */
    SRV_SNS_DS_RET_END  
}srv_sns_caller_handler_enum;


typedef enum
{
    SRV_SNS_DRIVE_PHONE_ONLY,
    SRV_SNS_DRIVE_CARD_EXIST,
    SRV_SNS_DRIVE_TOTAL
}srv_sns_drive_state_enum;

typedef struct
{
    U32 count;
    U32 total;
    void *data;
}srv_sns_ds_rsp_data_struct;

typedef S32 (*cb_func)(void* user_data, S32 result, srv_sns_ds_rsp_data_struct *rsp);

typedef struct 
{
    U8 update_type;
    U32 provider;
    U32 timestamp; // for fast data search
    U32 group_id;
    U32 blob_size;
    union {       
        CHAR *id;
        void* users;
    }row;
    union {
        U8 unread;
        WCHAR *name;
        void *blob;
#ifdef __MMI_SNS_CALENDAR__
        srv_sns_event_struct *event;
#endif
    }value;
} srv_sns_ds_update_struct;

typedef struct 
{
    U8 filter_type;
    MMI_BOOL cached;
    union {
        U32 provider;
        U32 group_id;
       // WCHAR name[60];
    }u;
} srv_sns_ds_cache_struct;


typedef struct
{
    S32 err_code;
    U32 srv_hdr;
    MMI_BOOL is_cancelled;
}srv_sns_db_context_struct;

typedef struct
{
    U8 drive;
    void *user_data;
    cb_func callback;
    U32 srv_handle;
    S32 error_code;
    S32 ture_err_code;
    MMI_BOOL is_processsing;
    MMI_BOOL is_abort;
    MMI_BOOL is_logout;
    srv_sns_open_flag_enum open_flag;
    U32 providers[SRV_SNS_MAX_NUM_PROVIDERS];
    WCHAR sns_path[SNS_DS_MAX_PATH_LEN];

}srv_sns_ds_info_struct;

typedef struct
{
    srv_sns_ds_info_struct ds_info;
}srv_sns_main_context_struct;

typedef struct 
{
    U8 filter_type;
    U16 contact_id;
    U32 offset;
    U32 limit;
    U32 provider;
    U32 group_id;
    MMI_BOOL from_cache; // for friend table to search from cached results
    union {           
        U32 timestamp;
        U32 index;
        U32 type;
        CHAR *id;
        WCHAR *name;
        void *users;
        U32 *ids;
#ifdef __MMI_SNS_CALENDAR__    
        srv_sns_event_search_filter_struct tdl_search_struct;
#endif
    }u;
} srv_sns_ds_filter_struct;

void sns_prompt_trace(const char *fmt,...);

/*****************************************************************************
 * FUNCTION
 *  srv_sns_ds_init
 * DESCRIPTION
 *  initialize data storage service
 * PARAMETERS
 *  *result                :  [OUT]     error code
 *  *user_data             :  [IN]      user data
 *  callback               :  [IN]      callback function
 *  *allocator             :  [IN]      memory allcator for data storage service 
 *  db_in_phone            :  [IN]      store data in phone or memory card
 * RETURNS
 *  return service handle
 *****************************************************************************/ 
U32 srv_sns_ds_init(S32* result, 
                    void* user_data, 
                    cb_func callack, 
                    MMI_BOOL db_in_phone,
                    U32 available_providers[SRV_SNS_MAX_NUM_PROVIDERS]);

/*****************************************************************************
 * FUNCTION
 *  srv_sns_ds_deinit
 * DESCRIPTION
 *  de-initialize data storage service
 * PARAMETERS
 *  ds_hdlr     [IN]   service handle
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
S32 srv_sns_ds_deinit(U32 ds_hdlr);

/*****************************************************************************
 * FUNCTION
 *  srv_sns_ds_open
 * DESCRIPTION
 *  handles database open request
 * PARAMETERS
 *  ds_hdlr     [IN]    service handle
 *  open_flag   [IN]    open a new database or not 
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
S32 srv_sns_ds_open(U32 ds_hdlr, srv_sns_open_flag_enum open_flag);

/*****************************************************************************
 * FUNCTION
 *  srv_sns_ds_close
 * DESCRIPTION
 *  close database file
 * PARAMETERS
 *  ds_hdlr     [IN]   service handle
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
S32 srv_sns_ds_close(U32 ds_hdlr);

/*****************************************************************************
 * FUNCTION
 *  srv_sns_ds_insert
 * DESCRIPTION
 *  add data to data storage service
 * PARAMETERS
 *  ds_hdlr     [IN]   service handle
 *  table       [IN]   where data will be added
 *  *input      [IN]   data to be added 
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
S32 srv_sns_ds_insert(U32 ds_hdlr, U32 provider, srv_sns_tables_enum table, U16 count, void *input, U32 state);

/*****************************************************************************
 * FUNCTION
 *  srv_sns_ds_update
 * DESCRIPTION
 *  update data to data storage service
 * PARAMETERS
 *  ds_hdlr     [IN]   service handle
 *  table       [IN]   where data will be updated
 *  *input      [IN]   data to be updated 
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
S32 srv_sns_ds_update(U32 ds_hdlr, srv_sns_tables_enum table, srv_sns_ds_update_struct *input);

/*****************************************************************************
 * FUNCTION
 *  srv_sns_ds_query
 * DESCRIPTION
 *  query data from data storage service
 * PARAMETERS
 *  ds_hdlr      [IN]   service handle
 *  table        [IN]   where data will be qurried from
 *  *filter      [IN]   information filter
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
S32 srv_sns_ds_query(U32 ds_hdlr, srv_sns_tables_enum table, srv_sns_ds_filter_struct *filter, MMI_BOOL select_count);

#ifdef __MMI_SNS_CALENDAR__
/*****************************************************************************
 * FUNCTION
 *  srv_sns_ds_update_event
 * DESCRIPTION
 *  sync api for updating sns event
 * PARAMETERS
 *  *update_item      [IN]   event to be updated
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
S32 srv_sns_ds_update_event(U32 ds_hdlr, srv_sns_ds_update_struct *update_item);

/*****************************************************************************
 * FUNCTION
 *  srv_sns_ds_query_event_event
 * DESCRIPTION
 *  sync api for qurrying sns event
 * PARAMETERS
 *  ds_hdlr      [IN]   service handle
 *  *filter      [IN]   information filter
 *  *result      [IN]   result error code
 * RETURNS
 *  return event found
 *****************************************************************************/ 
srv_sns_event_struct *srv_sns_ds_query_event(U32 ds_hdlr, srv_sns_ds_filter_struct *filter, S32* result);
#endif
#ifdef __MMI_SNS_CONTACTS__
/*****************************************************************************
 * FUNCTION
 *  srv_sns_ds_is_contact_linked
 * DESCRIPTION
 *  check if a contact is linked
 * PARAMETERS
 *  ds_hdlr      [IN]   service handle
 *  *filter      [IN]   information filter
 *  *result      [IN]   result error code
 * RETURNS
 *  MMI_TRUE:
 *  MMI_FALSE:
 *****************************************************************************/ 
MMI_BOOL srv_sns_ds_is_contact_linked(U32 ds_hdlr, srv_sns_ds_filter_struct *filter, S32 *result);

/*****************************************************************************
 * FUNCTION
 *  srv_sns_ds_delete_linked_friends_by_contact_id
 * DESCRIPTION
 *  delete linked friends by contact id
 * PARAMETERS
 *  ds_hdlr      [IN]   service handle
 *  table        [IN]   table name
 *  *filter      [IN]   filter information
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
S32 srv_sns_ds_delete_linked_friends_by_contact_id(U32 ds_hdlr, srv_sns_tables_enum table, srv_sns_ds_filter_struct *filter);
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_sns_ds_delete
 * DESCRIPTION
 *  delete data from data storage service
 * PARAMETERS
 *  ds_hdlr      [IN]   service handle
 *  table        [IN]   where data will be deleted from
 *  *filter      [IN]   information filter
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
S32 srv_sns_ds_delete(U32 ds_hdlr, srv_sns_tables_enum table, srv_sns_ds_filter_struct *filter);

/*****************************************************************************
 * FUNCTION
 *  srv_sns_ds_abort
 * DESCRIPTION
 *  abort inserting/querying data to/from data storage service
 * PARAMETERS
 *  ds_hdlr      [IN]   service handle
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
S32 srv_sns_ds_abort(U32 ds_hdlr);

/*****************************************************************************
 * FUNCTION
 *  srv_sns_ds_account_login
 * DESCRIPTION
 *  Notifiy to add available provider
 * PARAMETERS
 *  ds_hdlr      [IN]   service handle
 *  provider     [IN]   new provider's flag 
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
S32 srv_sns_ds_account_login(U32 ds_hdlr, U32 provider);

/*****************************************************************************
 * FUNCTION
 *  srv_sns_ds_account_logout
 * DESCRIPTION
 *  Notify to remove an account
 * PARAMETERS
 *  ds_hdlr      [IN]   service handle
 *  account      [IN]   account flag  
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
S32 srv_sns_ds_account_logout(U32 ds_hdlr, U32 provider);

#endif
