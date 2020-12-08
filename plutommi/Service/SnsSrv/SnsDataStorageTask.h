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
 *  SnsDataStorageTask.c
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SRV_SNS_SQL_H__
#define __SRV_SNS_SQL_H__


#include "SnsDataStorage.h"
#include "snsSrvTypes.h"

typedef enum
{
    SRV_SNS_DS_FRIEND_STATUS_NOT_EXIST = 0,
    SRV_SNS_DS_FRIEND_STATUS_INDEX_CHANGED,
    SRV_SNS_DS_FRIEND_STATUS_OK,
    SRV_SNS_DS_FRIEND_STATUS_TOTAL
}srv_sns_ds_friend_status_enum;

#define SNS_DS_FILE_NAME_FEEDS              L"feeds"
#define SNS_DS_FILE_NAME_FEEDS_BY           L"feeds_by"
#define SNS_DS_FILE_NAME_FEEDS_OF           L"feeds_of"
#define SNS_DS_FILE_NAME_FRIENDS            L"friends"
#define SNS_DS_FILE_NAME_NOTIFICATIONS      L"notifications"
#define SNS_DS_FILE_NAME_REQUESTS           L"requests"
#define SNS_DS_FILE_NAME_ALBUMS             L"albums"
#define SNS_DS_FILE_NAME_PARTICIPANTS       L"participants"
#define SNS_DS_FILE_NAME_THREADS            L"threads"
#define SNS_DS_FILE_NAME_MESSAGES           L"messages"
#define SNS_DS_FILE_NAME_GROUPS             L"groups"
#define SNS_DS_FILE_NAME_MEMBER             L"member"
#define SNS_DS_FILE_NAME_PHOTOS             L"photos"
#define SNS_DS_FILE_NAME_FRIEND_INDEX       L"friend_index"
#define SNS_DS_FILE_NAME_NOT_IN_GROUP       L"not_in_group"
#define SNS_DS_FILE_NAME_FEED_INDEX         L"feed_index"
#define SNS_DS_FILE_NAME_ALL_FRIENDS        L"all_friends"
#define SNS_DS_FILE_NAME_FRIEND_NAME        L"friend_name"
#define SNS_DS_FILE_NAME_LINK_CONTACT       L"link_contact"
#define SNS_DS_FILE_NAME_NOT_LINK_CONTACT   L"not_link_contact"
#define SNS_DS_FILE_NAME_SUFFIX_INDEX       "index"  // should not be wide char

#ifdef __MMI_SNS_CALENDAR__
#define SNS_DS_FILE_NAME_EVENT              L"event"
#define SNS_DS_FILE_NAME_ALARM_BIRTHDAY     L"alarm_birthday"
#define SNS_DS_FILE_NAME_BIRTHDAY           L"birthday"
#define SNS_DS_FILE_NAME_BIRTHDAY_TEMP      L"birthday_temp"
#endif

typedef struct
{
    LOCAL_PARA_HDR
    U32 handler;  
} sns_ds_init_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U32 handler;
    S32 result;
} sns_ds_init_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U32 handler;
} sns_ds_deinit_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    U32 handler;
    S32 result;
} sns_ds_deinit_rsp_struct;


typedef struct
{
    LOCAL_PARA_HDR
    U32 handler;
} sns_ds_open_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U32 handler; 
    S32 result;
} sns_ds_open_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U32 handler;
} sns_ds_close_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    U32 handler;  
    S32 result;
} sns_ds_close_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 count;
    U32 handler;
    U32 provider;
    U32 table;
    U32 state;
    void *input;
} sns_ds_insert_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    srv_sns_db_context_struct *db_handle;    
    U32 handler;
    S32 result;
} sns_ds_insert_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U32 handler;
    U32 table;
    srv_sns_ds_update_struct *field;
} sns_ds_update_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    U32 handler; 
    S32 result;
} sns_ds_update_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U32 handler;
    U32 table;
    MMI_BOOL select_count;
    srv_sns_ds_filter_struct *filter;
} sns_ds_query_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U32 handler;  
    S32 result;
    U32 table;
    U32 count;
    U32 total;
    void *data;
} sns_ds_query_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U32 handler;
    U32 table;
    srv_sns_ds_filter_struct *filter;
} sns_ds_delete_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U32 handler;
    S32 result;
} sns_ds_delete_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U32 handler;
    U32 provider;
} sns_ds_logout_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U32 handler;
    S32 result;
} sns_ds_logout_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    S32 req_id;
    WCHAR *dst;
    S32 dest_width;
    S32 dest_height;
    U8 cf;
    U8 * buf_ptr;
    S32 buf_size;
    void *user_data;
} sns_encode_jpeg_req_struct;

#define SNS_ENCODE_STOP    (1<<0)
#define SNS_JOB_MAX   0x0FFFFFFF

typedef struct
{
    kal_bool waiting;
    kal_uint32 req_id;
    kal_uint32 working_id;
    kal_eventgrpid g_sns_encode_event;
} sns_encode_cntx_struct;

#ifdef __MMI_SNS_CALENDAR__
/*****************************************************************************
 * FUNCTION
 *  snst_ds_get_sns_events
 * DESCRIPTION
 *  for sns task to query sns events
 * PARAMETERS
 *  *filter      [IN]   information to filter data
 *  *number      [OUT]  the number events returned in this query
 *  *total       [OUT]  total number of events found
 *  *result      [OUT]  result error code
 * RETURNS
 *  return sns event list
 *****************************************************************************/ 
void *snst_ds_get_sns_events(srv_sns_ds_filter_struct *filter, U32 *number, U32 *total, S32 *result);

/*****************************************************************************
 * FUNCTION
 *  snst_ds_get_birthday_events
 * DESCRIPTION
 *  for sns task to query birthday events
 * PARAMETERS
 *  *filter      [IN]   information to filter data
 *  *number      [OUT]  the number events returned in this query
 *  *total       [OUT]   total number of events found
 *  *result      [OUT]  result error code
 * RETURNS
 *  return birthday event list
 *****************************************************************************/ 
void *snst_ds_get_birthday_events(srv_sns_ds_filter_struct *filter, U32 *number, U32 *total, S32 *result);

/*****************************************************************************
 * FUNCTION
 *  snst_ds_update_sns_event
 * DESCRIPTION
 *  for sns task to update sns event
 * PARAMETERS
 *  *udpate_item     [IN]   event to be updated
 * RETURNS
 *  return error code
 *****************************************************************************/
S32 snst_ds_update_sns_event(srv_sns_event_struct *update_item);

/*****************************************************************************
 * FUNCTION
 *  snst_ds_update_birthday_event
 * DESCRIPTION
 *  for sns task to update birthday event
 * PARAMETERS
 *  *udpate_item     [IN]   event to be updated
 * RETURNS
 *  return error code
 *****************************************************************************/
S32 snst_ds_update_birthday_event(srv_sns_event_struct *update_item);
#endif
#ifdef __MMI_SNS_CONTACTS__
/*****************************************************************************
 * FUNCTION
 *  snst_ds_get_is_contact_linked
 * DESCRIPTION
 *  for sns task to query if a contact was linked to friends before
 * PARAMETERS
 *  *filter      [IN]   information to filter data
 *  *number      [OUT]  number of items returned in this query
 *  *total       [OUT]  total number of items found
 *  *result      [OUT]  result error code
 * RETURNS
 *  return request list
 *****************************************************************************/ 
S32 snst_ds_get_is_contact_linked(srv_sns_ds_filter_struct *filter, MMI_BOOL *exist);

/*****************************************************************************
 * FUNCTION
 *  snst_ds_delete_contact_links
 * DESCRIPTION
 *  for sns task to links from contacts to friend
 * PARAMETERS
 *  *filter      [IN]   filter
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
S32 snst_ds_delete_contact_links(srv_sns_ds_filter_struct *filter);
#endif
#endif
