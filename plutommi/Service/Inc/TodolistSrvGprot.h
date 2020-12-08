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

/*******************************************************************************
 * Filename:
 * ---------
 * TodolistSrvGprot.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines function prototypes used in todolist application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef TODOLIST_SERVICE_GPROT_H
#define TODOLIST_SERVICE_GPROT_H

/******************************************************************************* 
 * Include 
 *******************************************************************************/
#include "MMI_features.h"

#if ((defined(__MMI_CALENDAR_EVENT__) || defined(__MMI_TODOLIST__)) && !defined(__COSMOS_MMI_PACKAGE__)) || defined(__COSMOS_MMI_PACKAGE__)
//#ifdef __MMI_SRV_TODOLIST__
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "kal_general_types.h"

/*****************************************************************************
 * Const definitions
 *****************************************************************************/
#define SRV_TDL_SUBJECT_SIZE       (MAX_TODO_NOTE_LEN)
#define SRV_TDL_LOCATION_SIZE      (MAX_TDL_LOCATION_SIZE)
#define SRV_TDL_DETAILS_SIZE       (MAX_TDL_DETAILS_SIZE)
#define SRV_TDL_MAX_DAYS_PER_WEEK  (MAX_DAY_IN_WEEK)


/*****************************************************************************
 * Enumeration definitions
 *****************************************************************************/
typedef enum
{
    SRV_TDL_RESULT_OK,
    SRV_TDL_RESULT_FAIL,
    SRV_TDL_RESULT_ADD_NOT_ENOUGH_MEMORY,
    SRV_TDL_RESULT_INVALID_INDEX,
    SRV_TDL_RESULT_INVALID_PARAMETER,
    SRV_TDL_RESULT_EMPTY_LIST,
    SRV_TDL_RESULT_UNSUPPORTED_OPERATION,
    SRV_TDL_RESULT_END_OF_ENUM
}srv_tdl_result_enum;

typedef enum
{
    SRV_TDL_SORT_TYPE_ENTRY_TIME,
    SRV_TDL_SORT_TYPE_CREATE_TIME,
    SRV_TDL_SORT_TYPE_PRIORITY,
    SRV_TDL_SORT_TYPE_TODAY_TIME,   /* the event time of today even if it is acurrence event,
                                    if it is more than one day, will see as starting 00:00 and ending 23:59*/
    SRV_TDL_SORT_END_OF_ENUM
}srv_tdl_sort_type_enum;

typedef enum
{
    SRV_TDL_SEARCH_TYPE_TIME,
    SRV_TDL_SEARCH_TYPE_DAILY,
    SRV_TDL_SEARCH_TYPE_WEEKLY,
    SRV_TDL_SEARCH_TYPE_MONTHLY,
    SRV_TDL_SEARCH_TYPE_SUBJECT,
    SRV_TDL_SEARCH_TYPE_LOCATION,
    SRV_TDL_SEARCH_TYPE_CATEGORY,
    SRV_TDL_SEARCH_TYPE_BEFORE,
    SRV_TDL_SEARCH_TYPE_AFTER,
    SRV_TDL_SEARCH_TYPE_INCOMING,
    SRV_TDL_SEARCH_TYPE_PREVIOUS,
    SRV_TDL_SEARCH_TYPE_ALL,
    SRV_TDL_SEARCH_TYPE_STATUS,
    SRV_TDL_SEARCH_TYPE_DURATION,
    SRV_TDL_SEARCH_TYPE_ALARM,
    SRV_TDL_SEARCH_END_OF_ENUM
}srv_tdl_search_type_enum;

typedef enum
{
    SRV_TDL_REPEAT_RULE_BY_POS = 1,
    SRV_TDL_REPEAT_RULE_BY_DAY,
    SRV_TDL_REPEAT_RULE_END_OF_ENUM
}srv_tdl_repeat_rule_type_enum;

typedef enum
{
    SRV_TDL_VCAL_EVENT,
    SRV_TDL_VCAL_TASK,
    SRV_TDL_VCAL_BOTH,
    SRV_TDL_VCAL_END_OF_ENUM
} srv_tdl_vcal_enum;


typedef enum
{
     SRV_TDL_COMPARE_LESS = -1,
     SRV_TDL_COMPARE_EQUAL = 0,
     SRV_TDL_COMPARE_GREATER = 1,
     SRV_TDL_COMPARE_END_OF_ENUM
}srv_tdl_compare_result_enum;

/* MUST NOT change the order */
typedef enum
{
    SRV_TDL_RULE_ONCE,
    SRV_TDL_RULE_DAILY,
    SRV_TDL_RULE_DAYS,
    SRV_TDL_RULE_WEEKLY,
    SRV_TDL_RULE_MONTHLY,
    SRV_TDL_RULE_YEARLY,
    SRV_TDL_RULE_TOTAL
} srv_tdl_repeat_rule_enum;

/* MUST NOT change the order */
typedef enum
{
    SRV_TDL_STATUS_UNDONE,
    SRV_TDL_STATUS_DONE,
    SRV_TDL_STATUS_TOTAL
} srv_tdl_task_status_enum;

/* start day of week enum */
typedef enum
{
    SRV_TDL_START_DAY_SUN,
    SRV_TDL_START_DAY_MON,
        
    SRV_TDL_START_DAY_SAT = 6,
    SRV_TDL_START_DAY_TOTAL
} srv_tdl_start_day_enum;

/* tdl operator enum */
typedef enum
{
    SRV_TDL_OP_ADD,
    SRV_TDL_OP_UPDATE,
    SRV_TDL_OP_DELETE,
    SRV_TDL_OP_TOTAL
}srv_tdl_operator_enum;


typedef enum
{
    EVT_ID_SRV_TDL_OP = SRV_TODOLIST_BASE + 1,
    EVT_ID_SRV_TDL_EVENT_SEARCH, 
    EVT_ID_SRV_TDL_EVENT_OP, 
    EVT_ID_SRV_TDL_LOCAL_EVENT_SEARCH,
    EVT_ID_SRV_TDL_EVT_TOTAL
} srv_tdl_op_event_enum;

#define SNS_BEGIN_ENUM

/* MUST NOT change the order */
typedef enum
{
    SRV_TDL_CATEGORY_REMINDER,
    SRV_TDL_CATEGORY_MEETING,
    SRV_TDL_CATEGORY_COURSE,
    SRV_TDL_CATEGORY_DATE,
    SRV_TDL_CATEGORY_CALL,
    SRV_TDL_CATEGORY_ANNIVERSARY,
    SRV_TDL_CATEGORY_BIRTHDAY,
    SRV_TDL_CATEGORY_TOTAL
} srv_tdl_category_enum;


typedef enum
{
    SRV_TDL_EVENT_SORT_START_TIME,
    SRV_TDL_EVENT_SORT_ALARM_TIME,
    SRV_TDL_EVENT_SORT_TOTAL
} srv_tdl_event_sort_enum;


typedef enum
{
    SRV_TDL_EVENT_SOURCE_LOCAL,
#ifdef __MMI_SNS_CALENDAR__
    SRV_TDL_EVENT_SOURCE_FACEBOOK,
    SRV_TDL_EVENT_SOURCE_KAIXIN,
    SRV_TDL_EVENT_SOURCE_RENREN,
    SRV_TDL_EVENT_SOURCE_TWITTER,
#endif
    SRV_TDL_EVENT_SOURCE_TOTAL
} srv_tdl_event_source_enum;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_tdl_operator_enum op_type;
    U32 source_id;
    U32 event_id;
}srv_tdl_event_op_struct;


#define SNS_END_ENUM
/*****************************************************************************
 * Structure definitions
 *****************************************************************************/
typedef struct
{
    U16 index;
    U16 type;
}srv_tdl_event_task_struct;

typedef struct 
{
    MYTIME date_time;
    srv_tdl_start_day_enum start_day_of_week;
}srv_tdl_search_weely_struct;
    
typedef struct
{
	srv_tdl_search_type_enum type;
	union
	{
	    srv_tdl_search_weely_struct weekly_search;    /* for WEEKLY */
        MYTIME date_time;                           /* for TIME/DAILY/MONTHLY/BEFORE */
        MYTIME duration[2];                         /* for DURATION */
        U16 str_buf[MAX_TODO_NOTE_LEN];             /* for SUBJECT/LOCATION */
        U16 status;                                 /* for STATUS */
        U8 category;                                /* for CATEGORY */
	}u;
}srv_tdl_search_filter_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_tdl_vcal_enum vcal_type;
    srv_tdl_operator_enum op_type;
    U16 store_idx;
}srv_tdl_op_evt_struct;


#define SNS_BEGIN_STRUCT

// SNS service ---> todo service 
// when search, SNS return the event_id and it's begin_time
typedef struct
{
    U32 event_id;
    MYTIME begin_time;
}srv_tdl_event_search_get_struct;

/* 
     todo service ---> calendar APP
     after async search end, todo service send EVT_ID_SRV_TDL_EVENT_SEARCH 
     to tell app how many event was found, then app alloc buffer to get these events,
     event struct is srv_tdl_event_id_struct.
*/
typedef struct
{
    MMI_EVT_PARAM_HEADER
	MMI_BOOL success;	
	S32 job_id;    // job_ id
    S32 event_cnt; // total event count, error happen if (event_cnt < 0)
} srv_tdl_search_callback_struct;


// todo service ---> calendar APP
// todo service return app event_id and it's source_id, with sorted begin_time
typedef struct
{
	srv_tdl_event_source_enum source_id;
	U32 event_id;  // event id
}srv_tdl_event_id_struct;


/*****************************************************************************
 * Function pointer definitions
 *****************************************************************************/
typedef MMI_BOOL (*srv_tdl_external_search_check_funcptr)(
                                 const void *data, 
                                 const srv_tdl_vcal_enum vcal_type,
                                 const srv_tdl_search_filter_struct search_filter);

typedef srv_tdl_compare_result_enum 
          (*srv_tdl_external_sort_compare_funcptr)(
                                const U16 index1,
                                const U16 type1, 
                                const U16 index2, 
                                const U16 type2, 
                                const srv_tdl_sort_type_enum sort_type);


typedef kal_int32 (*event_async_callback)(srv_tdl_event_source_enum source_id,
                                               kal_int32 job_id, kal_int32 count);

typedef struct
{
    const event_async_callback    callback;   // callback function pointer
    const void                    *param;     // parameter of callback function
    const void                    *buf;       // Working buffer should be prepared by todo service.
    const kal_uint32              buf_size;   // working buffer size. 
} event_async_struct;

typedef kal_int32 (*event_search_callback)(kal_int32 job_id, kal_int32 total_count);

/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_search_begin_funcptr
 *
 * DESCRIPTION
 *  [Async]
 *  This function provides a facility to find all matching events
 *
 * PARAMETERS
 *  filter                 :[IN]       search filter 
 *  sort_type          :[IN]      event sort type
 *  callback            :[IN]      Call back function. 
 *
 * RETURNS
 *  Successful  : A positive integer. It is Job ID.
 *  Failed         : A negative integer. 
 *
 *****************************************************************************/
typedef kal_int32 (*srv_tdl_async_event_search_begin_funcptr)(
                                const srv_tdl_event_source_enum source_id,
	                            const srv_tdl_search_filter_struct *filter,
	                            const srv_tdl_event_sort_enum sort_type,
	                            const event_async_callback callback);

/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_search_funcptr 
 *  [sync]
 * DESCRIPTION
 *  This function provides a facility to find all matching events
 *
 * PARAMETERS
 *  filter                 :[IN]       search filter 
 *  sort_type          :[IN]      event sort type
 *  callback            :[IN]      Call back function. 
 *
 * RETURNS
 *  >=0   :    event count really returned
 *  <0     :    error happen
 *****************************************************************************/
typedef kal_int32 (*srv_tdl_async_event_search_funcptr)(
	                            kal_int32          job_id,     // job id get from srv_tdl_event_search_begin_funcptr
	                            srv_tdl_event_search_get_struct *buf,       // Working buffer should be prepared by todo service.
                                const kal_uint32   buf_size,   // working buffer size. 
                                const kal_int32    index      // event index from which to get
	                            );

/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_search_end_funcptr
 *
 * DESCRIPTION
 *        
 * PARAMETERS
 *  job_id         :[IN]      jod want to abort
 *
 * RETURNS
 *  Successful  : A positive integer. It is Job ID.
 *  Failed         : A negative integer. 
 *
 *****************************************************************************/

typedef kal_int32 (*srv_tdl_async_event_search_end_funcptr)(kal_int32 job_id);


//sync API

typedef S32 (*srv_tdl_search_event_funcptr)(
	                            const void *buffer,
	                            const U32  buffer_size,
	                            const srv_tdl_search_filter_struct filter,
	                            const srv_tdl_event_sort_enum sort_type);


typedef MMI_BOOL (*srv_tdl_get_event_funcptr)(
	                            const void *buffer,
	                            const U32  buffer_size,
	                            const srv_tdl_event_source_enum source_id,
	                            const U32 event_id);


typedef MMI_BOOL (*srv_tdl_update_event_funcptr)(
	                            const void *buffer,
	                            const srv_tdl_event_source_enum source_id,
	                            const U32 event_id);


typedef MMI_BOOL (*srv_tdl_add_event_funcptr)(
	                            const void *buffer,
	                            const srv_tdl_event_source_enum source_id,
	                            U32*  event_id);

typedef MMI_BOOL (*srv_tdl_delete_event_funcptr)(
	                            const srv_tdl_event_source_enum source_id,
	                            const U32 event_id);



/*****************************************************************************
 * External Variable
 *****************************************************************************/

typedef struct
{
	srv_tdl_async_event_search_begin_funcptr event_async_search_begin_funcptr;
	srv_tdl_async_event_search_funcptr event_async_search_funcptr;
	srv_tdl_async_event_search_end_funcptr event_async_search_end_funcptr;
	srv_tdl_search_event_funcptr event_search_funcptr;
	srv_tdl_get_event_funcptr event_get_funcptr;
	srv_tdl_update_event_funcptr event_update_funcptr;
	srv_tdl_add_event_funcptr event_add_funcptr;
	srv_tdl_delete_event_funcptr event_delete_funcptr;
}srv_tdl_event_funcptr_table;

#define SNS_END_STRUCT

#define TDL_MAX_EVENT_SEARCH_COUNT 7

/*****************************************************************************
 * External APIs
 *****************************************************************************/
#define APP_API_BEGIN

/*****************************************************************************
 * FUNCTION
 *	srv_tdl_event_get
 * DESCRIPTION
 *	Get a event info
 * PARAMETERS
 *	buff :		   [OUT] The buffer to store the event info.
 *	buff_size :  [IN] The size of the output buffer.
 *	source_id	[IN] source id
 *	event_id :	[IN] event id.
 * RETURNS
 *	The error code of the operation.
 * RETURN VALUES
 *	SRV_TDL_RESULT_OK : Get the data success.
 *	SRV_TDL_RESULT_FAIL : Get failed with unknown reason.
 *	SRV_TDL_RESULT_INVALID_INDEX : The index is invalid.
 *	SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/ 
extern U32 srv_tdl_event_get(
				srv_tdl_event_struct *buff, 
				const U32 buff_size, 
				const srv_tdl_event_source_enum source_id,
				const U32 event_id);
				
/*****************************************************************************
 * FUNCTION
 *	srv_tdl_event_add
 * DESCRIPTION
 *	Add an event.
 * PARAMETERS
 *	data :		 [IN] The event to add.
 *	source_id	[IN] source id
 *	event_id :	   [OUT] The id of event added.
 * RETURNS
 *	The error code of the add operation.
 * RETURN VALUES
 *	SRV_TDL_RESULT_OK : Add success.
 *	SRV_TDL_RESULT_FAIL : Add failed with unknown reason.
 *	SRV_TDL_RESULT_ADD_NOT_ENOUGH_MEMORY : The memory full, can not add success.
 *	SRV_TDL_RESULT_INVALID_PARAMETER : The parameter invalid.
 *****************************************************************************/  
extern U32 srv_tdl_event_add(
				const srv_tdl_event_struct *data, 
				const srv_tdl_event_source_enum source_id,
				U32 *event_id);

/*****************************************************************************
 * FUNCTION
 *	srv_tdl_event_delete
 * DESCRIPTION
 *	Delete an event.
 * PARAMETERS
 *	source_id	[IN] source id
 *	event_id : [IN] the id of event to be deleted.
 * RETURNS
 *	The error code of the deletion operation.
 * RETURN VALUES
 *	SRV_TDL_RESULT_OK : Delete success.
 *	SRV_TDL_RESULT_FAIL : Delete failed with unknown reason.
 *	SRV_TDL_RESULT_INVALID_INDEX : The index is invalid.
 *****************************************************************************/  
extern U32 srv_tdl_event_delete(const srv_tdl_event_source_enum source_id, const U32 event_id);

/*****************************************************************************
 * FUNCTION
 *	srv_tdl_event_update
 * DESCRIPTION
 *	Update an event.
 * PARAMETERS
 *	data :		[IN] The event to update to.
 *	source_id	[IN] source id 
 *	event_id :	   [IN] the id of event to updated.
 * RETURNS
 *	The error code of the operation.
 * RETURN VALUES
 *	SRV_TDL_RESULT_OK : Update success.
 *	SRV_TDL_RESULT_FAIL : Update failed with unknown reason.
 *	SRV_TDL_RESULT_INVALID_INDEX : The index is invalid.
 *	SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/ 
extern U32 srv_tdl_event_update(
					const srv_tdl_event_struct *data, 
					const srv_tdl_event_source_enum source_id,
					const U32 event_id);


/*****************************************************************************
 * FUNCTION
 *	srv_tdl_event_search_begin
 * DESCRIPTION
 *	search all the events whose source filter ON
 * PARAMETERS
 *	filter:
 *	 sort_type: 
 * RETURNS
 *	search job id
 * RETURN VALUES
 *	>0 :  valid job id
 *    =0:   no event source
 *	< 0:  invalid job id
 *****************************************************************************/ 
extern S32 srv_tdl_event_search_begin(
                              const srv_tdl_search_filter_struct *filter,
							  const srv_tdl_event_sort_enum sort_type,
							  srv_tdl_event_source_enum source_id);



/*****************************************************************************
 * FUNCTION
 *	srv_tdl_event_search_get
 * DESCRIPTION
 *	get the events from the index'th, 
 * PARAMETERS
 *	job_id:    [IN]
 *	 buffer:	[IN]  struct: srv_tdl_search_event_struct
 *	 buf_size:[IN]
 *	 index: 	[IN]
 * RETURNS
 *	the event number acullay returned
 * RETURN VALUES
 *	>=0 : the geted event number
 *	 < 0:	error happen
 *****************************************************************************/ 
extern S32 srv_tdl_event_search_get(S32 job_id, void *buffer, U32 buf_size, U32 index);



/*****************************************************************************
 * FUNCTION
 *	srv_tdl_event_search_end
 * DESCRIPTION
 *	end the search 
 * PARAMETERS
 *	job_id: [IN] 
 * RETURNS
 *	
 * RETURN VALUES
 *	>=0 : SUCCESS
 *	 < 0:	FAILED
 *****************************************************************************/ 
extern S32 srv_tdl_event_search_end(S32 job_id);


/*****************************************************************************
 * FUNCTION
 *	srv_tdl_get_source_state
 * DESCRIPTION
 *	check if the source is ignored or not
 * PARAMETERS
 *	
 * RETURNS
 *	the state of source
 * RETURN VALUES
 *	MMI_FRUE:  show the event
 *  MMI_FALSE: not show the event
 *****************************************************************************/ 
extern MMI_BOOL srv_tdl_get_source_state(srv_tdl_event_source_enum source_id);

/*****************************************************************************
 * FUNCTION
 *	srv_tdl_set_source_state
 * DESCRIPTION
 *	show event in calendar APP or not
 * PARAMETERS
 *   alow_show: MMI_TRUE: show the event on APP screen; MMI_FALSE: not show the event on APP screen;
 *	source_id:  
 * RETURNS
 *	the result of operation
 * RETURN VALUES
 *	MMI_TRUE:   success
 *    MMI_FALSE:  error 
 *****************************************************************************/ 
extern MMI_BOOL srv_tdl_set_source_state(MMI_BOOL alow_show, srv_tdl_event_source_enum source_id);

/*****************************************************************************
 * FUNCTION
 *	srv_tdl_has_source
 * DESCRIPTION
 *	check if the source_id supported by todolist srv
 * PARAMETERS
 *	source_id:  
 * RETURNS
 *	the result of operation
 * RETURN VALUES
 *	MMI_TRUE:   support
 *    MMI_FALSE: no support
 *****************************************************************************/ 
extern MMI_BOOL srv_tdl_has_source(srv_tdl_event_source_enum source_id);

/*****************************************************************************
 * FUNCTION
 *	srv_tdl_get_source_num
 * DESCRIPTION
 *	get the total number of source
 * PARAMETERS
 *	
 * RETURNS
 *	the num of event source
 * RETURN VALUES
 *	
 *    
 *****************************************************************************/ 
extern U32 srv_tdl_get_source_count(void);


/*****************************************************************************
 * FUNCTION
 *	srv_tdl_get_sns_reminder_source
 * DESCRIPTION
 *	get the sns reminder source
 * PARAMETERS
 *  event_id: [IN]
 *  source_id: [OUT]
 * RETURNS
 *	
 * RETURN VALUES
 *	
 *    
 *****************************************************************************/ 
extern MMI_BOOL srv_tdl_get_sns_reminder_source(U32 reminder_id, srv_tdl_event_source_enum *source_id);

#define APP_API_END	


#define SNS_API_BEGIN

/*****************************************************************************
 * FUNCTION
 *	srv_tdl_add_source
 * DESCRIPTION
 *	add event action funcptr into todolist funcptr table
 * PARAMETERS
 *	source_id: 
 *    srv_tdl_external_event_funcptr_table: 
 * RETURNS
 *	the result of add source operation
 * RETURN VALUES
 *	MMI_TRUE:    add source success
 *    MMI_FALSE:  add source error 
 *****************************************************************************/ 
extern MMI_BOOL srv_tdl_add_source(srv_tdl_event_source_enum source_id, srv_tdl_event_funcptr_table funcptr_table);

/*****************************************************************************
 * FUNCTION
 *	srv_tdl_delete_source
 * DESCRIPTION
 *	delete event action funcptr from todolist funcptr table
 * PARAMETERS
 *	source_id:  
 * RETURNS
 *	the result of delete source operation
 * RETURN VALUES
 *	MMI_TRUE:    delete source success
 *    MMI_FALSE:  delete source error 
 *****************************************************************************/ 
extern MMI_BOOL srv_tdl_delete_source(srv_tdl_event_source_enum source_id);

#define SNS_END_END
/*DOM-NOT_FOR_SDK-BEGIN*/
/*****************************************************************************
 * FUNCTION
 *  srv_tdl_init
 * DESCRIPTION
 *  initialize task and event list in service, It will be called when power on by default;
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/   
extern void srv_tdl_init(void);
/*DOM-NOT_FOR_SDK-END*/


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_add
 * DESCRIPTION
 *  Add a task/event.
 * PARAMETERS
 *  data : [IN] The task or event to add.
 *  vcal_type : [IN] Identify the type, event or task.
 *  index : [OUT] The store index of the task/event added.
 * RETURNS
 *  The error code of the add operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Add success.
 *  SRV_TDL_RESULT_FAIL : Add failed with unknown reason.
 *  SRV_TDL_RESULT_ADD_NOT_ENOUGH_MEMORY : The memory full, can not add success.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter invalid.
 *****************************************************************************/   
extern U16 srv_tdl_add(
                const void *data, 
                srv_tdl_vcal_enum vcal_type, 
                U16 *index);


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_delete
 * DESCRIPTION
 *  Delete a task/event.
 * PARAMETERS
 *  index : [IN] The store index of the task/event to be deleted.
 *  vcal_type : [IN] Identify the type, event or task.
 * RETURNS
 *  The error code of the deletion operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Delete success.
 *  SRV_TDL_RESULT_FAIL : Delete failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_INDEX : The index is invalid.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/   
extern U16 srv_tdl_delete(const U16 index, const srv_tdl_vcal_enum vcal_type);


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_update
 * DESCRIPTION
 *  Update a task/event.
 * PARAMETERS
 *  data : [IN] The task or event to update to.
 *  buff_size : [IN] The size of data buffer.
 *  vcal_type : [IN] Identify the type, event or task.
 *  index : [IN] The store index of the task/event to update.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Update success.
 *  SRV_TDL_RESULT_FAIL : Update failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_INDEX : The index is invalid.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/ 
extern U16 srv_tdl_update(
                const void *data, 
                const srv_tdl_vcal_enum vcal_type,  
                const U16 index);


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_get_cache
 * DESCRIPTION
 *  Get a task/event from cache buffer in order to improve the performance, 
 *  but the event or task is not complete for saving memory
 *  note: MUST NOT modify the buff content;
 * PARAMETERS
 *  buff :      [OUT] The pointer to point the cached task/event, please cast the 
 *  void pointer to srv_tdl_event_short_struct or srv_tdl_task_short_struct by your 
 *  specfied type before you use it;
 *  buff_size : [IN] The size of the output buffer.
 *  vcal_type : [IN] Identify the type, event or task.
 *  index :     [IN] The store index of the task/event to get.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Get the data success.
 *  SRV_TDL_RESULT_FAIL : Get failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_INDEX : The index is invalid.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/ 
extern U16 srv_tdl_get_cache(
                void** buff, 
                const U16 buff_size, 
                const srv_tdl_vcal_enum vcal_type, 
                const U16 index);


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_get
 * DESCRIPTION
 *  Get a task/event.
 * PARAMETERS
 *  buff :      [OUT] The pointer to point the cached task/event, please cast the 
 *  void pointer to srv_tdl_event_short_struct or srv_tdl_task_short_struct by your 
 *  specfied type before you use it;
 *  buff_size : [IN] The size of the output buffer.
 *  vcal_type : [IN] Identify the type, event or task.
 *  index : [IN] The store index of the task/event to get.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Get the data success.
 *  SRV_TDL_RESULT_FAIL : Get failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_INDEX : The index is invalid.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/ 
extern U16 srv_tdl_get(
                void *buff, 
                const U16 buff_size, 
                const srv_tdl_vcal_enum vcal_type, 
                const U16 index);


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_get_all_index
 * DESCRIPTION
 *  Get all the event/task/both list.
 *  If list buffer is NULL, it will output the total count of event/task.
 * PARAMETERS
 *  list : [IN/OUT] The list to store event/task, if NULL, will output
           total count only.
 *  buff_size : [IN] The size of list.
 *  vcal_type : [IN] Identify the type, event or task.
 *  count : [OUT] The store index of the task/event added.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Get the data successfully.
 *  SRV_TDL_RESULT_FAIL : Getting operation failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_INDEX : The index is invalid.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/ 
extern U16 srv_tdl_get_all_index(
                 srv_tdl_event_task_struct *list, 
                 const U16 buff_size, 
                 const srv_tdl_vcal_enum vcal_type, 
                 U16 *count);


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_get_free
 * DESCRIPTION
 *  Get the free number of task/event.
 * PARAMETERS
 *  count : [OUT] The free number to output.
 *  vcal_type : [IN] Identify the type, event or task.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Get the count successfully.
 *  SRV_TDL_RESULT_FAIL : Getting operation failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/ 
extern U16 srv_tdl_get_free(U16 *count, const srv_tdl_vcal_enum vcal_type);



/*****************************************************************************
 * FUNCTION
 *  srv_tdl_get_max
 * DESCRIPTION
 *  Get the max number of task/event.
 * PARAMETERS
 *  count : [OUT] The max number to output.
 *  vcal_type : [IN] Identify the type, event or task.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Get the count successfully.
 *  SRV_TDL_RESULT_FAIL : Getting operation failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/ 
extern U16 srv_tdl_get_max(U16 *count, const srv_tdl_vcal_enum vcal_type);


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_is_full
 * DESCRIPTION
 *  Check wether the task/event list is full.
 * PARAMETERS
 *  vcal_type : [IN] Identify the type, event or task.
 * RETURNS
 *  Full or not
 * RETURN VALUES
 *  MMI_TRUE : Full.
 *  MMI_FALSE : Not full.
 *****************************************************************************/ 
extern MMI_BOOL srv_tdl_is_full(const srv_tdl_vcal_enum vcal_type);


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_is_empty
 * DESCRIPTION
 *  Check wether the task/event list is empty.
 * PARAMETERS
 *  vcal_type : [IN] Identify the type, event or task.
 * RETURNS
 *  Empty or not
 * RETURN VALUES
 *  MMI_TRUE : Empty.
 *  MMI_FALSE : Not empty.
 *****************************************************************************/ 
extern MMI_BOOL srv_tdl_is_empty(const srv_tdl_vcal_enum vcal_type);


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_search
 * DESCRIPTION
 *  Search the event/task list according to the search condition.
 * PARAMETERS
 *  list : [OUT] The searched list.
 *  buff_size : [IN] The buffer size of the list.
 *  vcal_type : [IN] Identify the type, event or task.
 *  search : [IN] The search condition.
 *           For monthly/weekly search, the date_time is the standard to 
 *  identify the month and week.
 *           For location/subject search, the string is the key word.
 *           For duration search, the duration array stores the begin
 *  date time and the end date time to search event/task.
 *  If search event, the start time of the event should be later 
 *  than the duration[0], and the end time of the event should be 
 *  earlier than the duration[1].
 *  If search task, then the due time must in the duration.
 *  count : [OUT] The searched count.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Searched the event/task/both list successfully.
 *  SRV_TDL_RESULT_FAIL : Searched the list failed with unknown reasons.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *  SRV_TDL_RESULT_UNSUPPORTED_OPERATION : Unsupported search condition.
 *****************************************************************************/ 
extern U16 srv_tdl_search(
                srv_tdl_event_task_struct *list, 
                const U16 buff_size, 
                const srv_tdl_vcal_enum vcal_type,
                const srv_tdl_search_filter_struct search, 
                U16 *count);


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_search_ext
 * DESCRIPTION
 *  Search the event/task list according to the search condition.
 * PARAMETERS
 *  list : [OUT] The searched list.
 *  buff_size : [IN] The buffer size of the list.
 *  vcal_type : [IN] Identify the type, event or task.
 *  search : [IN] The search condition.
 *           For monthly/weekly search, the date_time is the standard to 
 *  identify the month and week.
 *           For location/subject search, the string is the key word.
 *           For duration search, the duration array stores the begin
 *  date time and the end date time to search event/task.
 *  If search event, the start time of the event should be later 
 *  than the duration[0], and the end time of the event should be 
 *  earlier than the duration[1].
 *  If search task, then the due time must in the duration.
 *  count : [OUT] The searched count.
 *  funcptr : [IN] Function to check if in the searched list.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Searched the event/task/both list successfully.
 *  SRV_TDL_RESULT_FAIL : Searched the list failed with unknown reasons.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *  SRV_TDL_RESULT_UNSUPPORTED_OPERATION : Unsupported search condition.
 *****************************************************************************/ 
extern U16 srv_tdl_search_ext(
                srv_tdl_event_task_struct *list, 
                const U16 buff_size, 
                const srv_tdl_vcal_enum vcal_type,
                const srv_tdl_search_filter_struct search, 
                U16 *count,
                const srv_tdl_external_search_check_funcptr funcptr);


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_sort
 * DESCRIPTION
 *  Sort the list according to giving sort type.
 * PARAMETERS
 *  list : [IN/OUT] The list to be sorted.
 *  buff_size : [IN] The buffer size of the list.
 *  sort_type : [IN] The sort type.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Sort successfully.
 *  SRV_TDL_RESULT_FAIL : Sort failed with unknow reasons.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *  SRV_TDL_RESULT_UNSUPPORTED_OPERATION : The operation is unsupported. This 
 *                                         error code will be returned when
 *                                         what to sort by unsupported field.
 *                                         Such as want to sort a event list 
 *                                         with priority.
 *****************************************************************************/ 
extern U16 srv_tdl_sort(
                srv_tdl_event_task_struct* list, 
                const U16 buff_size,
                const srv_tdl_sort_type_enum sort_type);    


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_get_time_in_today
 * DESCRIPTION
 *  Get a new time in today, the event MUST be today event
 * PARAMETERS
 *  new_time : [IN/OUT] input buffer for original time and output buffer for new time
 *  type : [IN] The event of this time repeat type
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/ 
extern void srv_tdl_get_time_in_today(MYTIME *new_time, srv_tdl_repeat_rule_enum type);


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_sort_ext
 * DESCRIPTION
 *  Sort the list according to giving sort type.
 * PARAMETERS
 *  list : [IN/OUT] The list to be sorted.
 *  buff_size : [IN] The buffer size of the list.
 *  sort_type : [IN] The sort type.
 *  funcptr : [IN] The function to compare two data by custom code.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Sort successfully.
 *  SRV_TDL_RESULT_FAIL : Sort failed with unknow reasons.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *  SRV_TDL_RESULT_UNSUPPORTED_OPERATION : The operation is unsupported. This 
 *                                         error code will be returned when
 *                                         what to sort by unsupported field.
 *                                         Such as want to sort a event list 
 *                                         with priority.
 *****************************************************************************/ 
U16 srv_tdl_sort_ext(
                srv_tdl_event_task_struct *list, 
                const U16 count,
                const srv_tdl_sort_type_enum sort_type, 
                const srv_tdl_external_sort_compare_funcptr funcptr);

/*****************************************************************************
 * FUNCTION
 *  srv_tdl_task_compare_priority
 * DESCRIPTION
 *  Compare two tasks' priority.
 * PARAMETERS
 *  index1 : [IN] The first task's index.
 *  index2 : [IN] The second task's index.
 * RETURNS
 *  The compare result.
 * RETURN VALUES
 *   SRV_TDL_COMPARE_LESS : index1 < index2
 *   SRV_TDL_COMPARE_EQUAL : index1 = index2
 *   SRV_TDL_COMPARE_GREATER : index1 > index
 *****************************************************************************/ 
extern S16 srv_tdl_task_compare_priority(U16 index1, U16 index2);            


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_cal_week_get_first_date
 * DESCRIPTION
 *  Get the first date in the week according to specific date.
 * PARAMETERS
 *  curr_date : [IN] The given date.
 *  first_date_of_week : [OUT] The output compute result.
 *  start_day_of_week: [IN] start day of week (Mon , Sun or Sat)
 * RETURNS
 *  The compare result.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Get the first date in the week successfully.
 *  SRV_TDL_RESULT_FAIL : Get the first date in the week failed with unknown reasons.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/                
extern U16 srv_tdl_cal_week_get_first_date(
                    const MYTIME *curr_date, 
                    MYTIME *first_date_of_week,
                    const srv_tdl_start_day_enum start_day_of_week);


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_cal_change_dow
 * DESCRIPTION
 *  the dow will be changed to new dow by start_day,if the dow is get from applib_dt_dow, 
 *  Sunday is the first day of week by default;
 * PARAMETERS
 *  dow :       [IN/OUT] the pointer original dow and new dow
 *  start_day : [IN] start day of week, 
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void srv_tdl_cal_change_dow(U8 *dow, const srv_tdl_start_day_enum start_day);


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_search_default_check
 * DESCRIPTION
 *  check the event/task if in the search filter.
 * PARAMETERS
 *  date : [IN] event/Task struct
 *  date : [IN] event or Task
 *  date : [IN] search filter
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/   
 extern MMI_BOOL srv_tdl_search_default_check(
                                 const void *data, 
                                 const srv_tdl_vcal_enum vcal_type,
                                 const srv_tdl_search_filter_struct filter);

/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_search_check_weekly
 * DESCRIPTION
 *  Search the weekly event list.
 * PARAMETERS
 *  pevent : [IN] The event to be checked.
 *  date : [IN] The search condition.
 *              The start time of the events in the searched list should be 
 *         earlier than 23:59 end of the week and end time shoud be later
 *         than 00:00 start time of the week.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/                     
extern MMI_BOOL srv_tdl_event_search_check_weekly(
                const srv_tdl_event_short_struct *pevent, 
                const srv_tdl_search_weely_struct weekly_search);


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_search_check_monthly
 * DESCRIPTION
 *  Search the monthly event list.
 * PARAMETERS
 *  pevent : [IN] The event to be checked.
 *  date : [IN] The search condition.
 *              The start time of the events in the searched list should be 
 *         earlier than 23:59 end of the month and end time shoud be later
 *         than 00:00 start time of the month.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Searched the event list successfully.
 *  SRV_TDL_RESULT_FAIL : Searched the list failed with unknown reasons.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *  SRV_TDL_RESULT_UNSUPPORTED_OPERATION : Unsupported search condition.
 *****************************************************************************/                 
extern MMI_BOOL srv_tdl_event_search_check_monthly(
                const srv_tdl_event_short_struct *pevent, 
                const MYTIME date);


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_search_check_daily
 * DESCRIPTION
 *  Check wether the task/event list is full.
 * PARAMETERS
 *  pevent : [IN] The event to be checked.
 *  date : [IN] The search condition.
 *              The start time of the events in the searched list should be 
 *         earlier than 23:59 end of the month and end time shoud be later
 *         than 00:00 start time of the month.
 * RETURNS
 *  New index.
 * RETURN VALUES
 *****************************************************************************/ 
extern MMI_BOOL srv_tdl_event_search_check_daily(
                const srv_tdl_event_short_struct *pevent, 
                const MYTIME date);

/*****************************************************************************
 * FUNCTION
 *  srv_tdl_task_search_check_daily
 * DESCRIPTION
 *  Search the daily task list.
 * PARAMETERS
 *  list : [OUT] The searched list. If NULL, means only want to get total.
 *  date : [IN] The search condition.
 *              The due time of the tasks in the searched list should be 
 *         earlier than 23:59 and later than 00:00 of the date.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/ 
extern MMI_BOOL srv_tdl_task_search_check_daily(
                            const srv_tdl_task_short_struct *ptask, 
                            const MYTIME date);
                            
/*****************************************************************************
 * FUNCTION
 *  srv_tdl_task_search_check_weekly
 * DESCRIPTION
 *  Search the weekly task list.
 * PARAMETERS
 *  list : [OUT] The searched list. If NULL, means only want to get total.
 *  weekly_search : [IN] The search condition.
 *              The due time of the tasks in the searched list should be 
 *         earlier than 23:59 end of the week and later than 00:00 start 
 *         time of the week.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/ 
extern MMI_BOOL srv_tdl_task_search_check_weekly(
                            const srv_tdl_task_short_struct *ptask, 
                            const srv_tdl_search_weely_struct weekly_search);

/*****************************************************************************
 * FUNCTION
 *  srv_tdl_task_search_check_monthly
 * DESCRIPTION
 *  Search the monthly task list.
 * PARAMETERS
 *  list : [OUT] The searched list. If NULL, means only want to get total.
 *  buff_size : [IN] The buffer size of the list.
 *  date : [IN] The search condition.
 *              The due time of the tasks in the searched list should be 
 *         earlier than 23:59 end of the month and later than 00:00 start 
 *         time of the month.
 *  count : [OUT] The searched count.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/ 
extern MMI_BOOL srv_tdl_task_search_check_monthly(
                            const srv_tdl_task_short_struct *ptask, 
                            const MYTIME date);

/*****************************************************************************
 * FUNCTION
 *  srv_tdl_get_new_index
 * DESCRIPTION
 *  Check wether the task/event list is full.
 * PARAMETERS
 *  vcal_type : [IN] Identify the type, event or task.
 * RETURNS
 *  New index.
 * RETURN VALUES
 *****************************************************************************/ 
extern U16 srv_tdl_get_new_index(const srv_tdl_vcal_enum type);

#endif /* __MMI_SRV_TODOLIST__ */

#endif /* TODOLIST_SERVICE_GPROT_H */                    
