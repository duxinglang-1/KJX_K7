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
*
*
* Project:
* --------
*  MAUI
 *
* Description:
* ------------
*
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
*============================================================================
****************************************************************************/

#include "j2me_custom_option.h"
#if defined(SUPPORT_JSR_75_PIM)
#include "kal_trace.h"
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "task_main_func.h"
#include "app_ltlcom.h"

#include "j2me_trace.h"
#include "j2me_custom_option.h"
#include "jpim_interface.h"
#include "jpim_internal.h"
#include "app_str.h"
#include "GlobalDefs.h"
#include "Mmi_rp_app_java_def.h"
#include "jam_internal.h"
#ifndef __COSMOS_MMI_PACKAGE__
#include "Mmi_rp_app_todolist_def.h"
#else
#include "mmi_rp_vapp_calendar_def.h"
#endif
/*************************************************************************
 * Function Definition
 *************************************************************************/
#ifdef JSR_75_PIM_EXTRA_ALARM_TIME_USER_DEFINE
void jpim_evtdb_adjustAlarmTime(mmi_evtdb_java_entry_struct *entry, kal_uint8 db_type, kal_bool write);
#endif

extern kal_eventgrpid g_java_event_group_1;

typedef enum
{
    JPIM_EVTDB_STATE_IDLE,
    JPIM_EVTDB_STATE_GET_COUNT,
    JPIM_EVTDB_STATE_GET_ENTRY,
    JPIM_EVTDB_STATE_APPEND_ENTRY,
    JPIM_EVTDB_STATE_UPDATE_ENTRY,
    JPIM_EVTDB_STATE_DELETE_ENTRY
} jpim_evtdb_state_enum;

static kal_int32 jpim_evtdb_count = 0;
static kal_int32 jpim_evtdb_result = 0;
static kal_int32 jpim_evtdb_index = -1;
static kal_int32 jpim_evtdb_handle = 0xFFFF;

static jpim_evtdb_state_enum jpim_evtdb_state = JPIM_EVTDB_STATE_IDLE;

/*****************************************************************************
 * FUNCTION
 *  jpim_evtdb_getSupportRepeat
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/

kal_uint8 jpim_evtdb_transfer_tdl_sort(kal_uint8 sort)
{
    switch(sort)
    {

        case JPIM_EVTDB_NO_SORT:           return MMI_EVTDB_NO_SORT;
        case JPIM_EVTDB_SORT_BY_TIME:      return MMI_EVTDB_SORT_BY_TIME;
        default:
            ASSERT(0);
            return MMI_EVTDB_SORT_BY_TIME;
    }

}


/*****************************************************************************
 * FUNCTION
 *  jpim_evtdb_getSupportRepeat
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/

kal_uint8 jpim_evtdb_transfer_tdl_db(kal_uint8 db)
{
    switch(db)
    {
#ifndef __COSMOS_MMI_PACKAGE__
        case JPIM_EVTDB_REMINDER:           return MMI_VCLNDR_DB_REMINDER;
        case JPIM_EVTDB_MEETING:            return MMI_VCLNDR_DB_MEETING;
        case JPIM_EVTDB_COURSE:             return MMI_VCLNDR_DB_COURSE;
        case JPIM_EVTDB_DATE:               return MMI_VCLNDR_DB_DATE;
        case JPIM_EVTDB_CALL:               return MMI_VCLNDR_DB_CALL;
        case JPIM_EVTDB_ANNIVERSARY:        return MMI_VCLNDR_DB_ANNIVERSARY;
#else
        case JPIM_EVTDB_PERSONAL:           return MMI_VCLNDR_DB_PERSONAL;
        case JPIM_EVTDB_MEETING:            return MMI_VCLNDR_DB_MEETING;
        case JPIM_EVTDB_SPECIALDAY:         return MMI_VCLNDR_DB_SPECIALDAY;
        case JPIM_EVTDB_BIRTHDAY:           return MMI_VCLNDR_DB_BIRTHDAY;
        case JPIM_EVTDB_OTHERS:             return MMI_VCLNDR_DB_OTHER;
#endif
		case JPIM_EVTDB_TASK:               return MMI_VCLNDR_DB_TASK;
        case JPIM_EVTDB_ALL:                return MMI_VCLNDR_DB_ALL;
        default:
            ASSERT(0);
            return MMI_VCLNDR_DB_ALL;
    }

}

/*****************************************************************************
 * FUNCTION
 *  jpim_evtdb_getSupportRepeat
 * DESCRIPTION
 *  This function retriveds all supported repeat type
 * PARAMETERS
 *  type        [IN]        jpim_evtdb_db_enum
 *  size        [IN/OUT]
 *  repeat      [OUT]
 * RETURNS
 *  jpim_error_code_enum
 *****************************************************************************/
kal_int32 jpim_evtdb_getSupportRepeat(kal_uint8 type, kal_int32* size, kal_int32* repeat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    const static kal_int32 m[] = { JPIM_R_FREQUENCY, JPIM_R_DAY_IN_MONTH,
        JPIM_R_DAY_IN_WEEK, JPIM_R_DAY_IN_YEAR};
    const static kal_int32 n = sizeof(m)/sizeof(kal_int32);

    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if( *size < n )
    {
        *size = n;
        return JPIM_SIZE_TOO_SMALL;
    }

    *size = n;

    for( i = 0 ;i < n ;i++ )
    {
        repeat[i] = m[i];
    }

    return JPIM_SUCCESS;
}
/*****************************************************************************
 * FUNCTION
 *  jpim_evtdb_getSupportField
 * DESCRIPTION
 *  This function retriveds all supported filed in event database.
 * PARAMETERS
 *  type        [IN]        jpim_evtdb_db_enum
 *  size        [IN/OUT]
 *  field       [OUT]
 * RETURNS
 *  jpim_error_code_enum
 *****************************************************************************/
kal_int32 jpim_evtdb_getSupportField(kal_uint8 type,kal_int32* size, kal_int32* field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __COSMOS_MMI_PACKAGE__
    const static kal_int32 mEvent[] = {
            JPIM_E_START,
            JPIM_E_END,
            JPIM_E_SUMMARY,
            JPIM_E_ALARM,
        #ifdef JSR_75_PIM_EXTRA_TODO
            JPIM_E_LOCATION,
        #endif
	    	#ifdef JSR_75_PIM_EXTRA_DETAIL
		        JPIM_E_NOTE
		    #endif
            };

    const static kal_int32 mTodo[] = {
            JPIM_E_END,
            JPIM_E_SUMMARY,
        #ifdef JSR_75_PIM_EXTRA_TODO
            JPIM_E_PRIORITY,
            JPIM_E_COMPLETED,
            JPIM_E_COMPLETION_DATE,
        #endif
		    #ifdef JSR_75_PIM_EXTRA_DETAIL
		        JPIM_E_NOTE
        #endif
            };
#else
    const static kal_int32 mEvent[] = {
            JPIM_E_SUMMARY,
            JPIM_E_START,
            JPIM_E_END,
            JPIM_E_ALARM,
        #ifdef JSR_75_PIM_EXTRA_TODO
            JPIM_E_LOCATION,
        #endif
        #ifdef JSR_75_PIM_EXTRA_DETAIL
            JPIM_E_NOTE
        #endif
            };

    const static kal_int32 mTodo[] = {
            JPIM_E_SUMMARY,
        #ifdef JSR_75_PIM_EXTRA_TODO
            JPIM_E_PRIORITY,
        #endif
            JPIM_E_END,
        #ifdef JSR_75_PIM_EXTRA_DETAIL
            JPIM_E_NOTE
        #endif
        #ifdef JSR_75_PIM_EXTRA_TODO
            ,JPIM_E_COMPLETED
            ,JPIM_E_COMPLETION_DATE
        #endif
            };
#endif

    const static kal_int32 nEvent = sizeof(mEvent)/sizeof(kal_int32);

    const static kal_int32 nTodo = sizeof(mTodo)/sizeof(kal_int32);

    kal_int32 i, n;
    const kal_int32 *m;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
#ifndef __COSMOS_MMI_PACKAGE__
    case JPIM_EVTDB_REMINDER:    /* Event */
    case JPIM_EVTDB_MEETING:     /* Event */
    case JPIM_EVTDB_COURSE:      /* Event */
    case JPIM_EVTDB_DATE:        /* Event */
    case JPIM_EVTDB_CALL:        /* Event */
    case JPIM_EVTDB_ANNIVERSARY: /* Event */
#else
    case JPIM_EVTDB_PERSONAL:    /* Event */
    case JPIM_EVTDB_MEETING:     /* Event */
    case JPIM_EVTDB_SPECIALDAY:  /* Event */
    case JPIM_EVTDB_BIRTHDAY:    /* Event */
    case JPIM_EVTDB_OTHERS:      /* Event */
#endif
        m = mEvent;
        n = nEvent;
		break;
	case JPIM_EVTDB_TASK: /* TODO */
        m = mTodo;
        n = nTodo;
        break;
    default:
        m = mEvent;
        n = nEvent;
        break;
    }

    if( *size < n )
    {
        *size = n;
        return JPIM_SIZE_TOO_SMALL;
    }

    *size = n;

    for(i = 0; i < n ;i++)
    {
        field[i] = m[i];
    }

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  jpim_evtdb_getIndexByHandle
 * DESCRIPTION
 *  This function transfer handle to index by specific sort type and database type.
 * PARAMETERS
 *  sort_type   [IN]    jpim_evtdb_sort_enum
 *  db_type     [IN]    jpim_evtdb_db_enum
 *  hanle       [IN]
 * RETURNS
 *  -1: error
 *****************************************************************************/

kal_int16 jpim_evtdb_getIndexByHandle(kal_uint8 sort_type,kal_uint8 db_type, kal_uint16 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_tdl_pim_get_sorted_index(
                    handle,
                    jpim_evtdb_transfer_tdl_sort(sort_type),
                    jpim_evtdb_transfer_tdl_db(db_type));
}

/*****************************************************************************
 * FUNCTION
 *  jpim_evtdb_getHandleByIndex
 * DESCRIPTION
 *  This function transfter index to handle.
 * PARAMETERS
 *  sort_type       [IN]    jpim_evtdb_sort_enum
 *  db_type         [IN]    jpim_evtdb_db_enum
 *  index
 * RETURNS
 *  -1: error
 *****************************************************************************/

kal_int16 jpim_evtdb_getHandleByIndex(kal_uint8 sort_type,kal_uint8 db_type, kal_uint16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_tdl_pim_get_handle(
                index,
                jpim_evtdb_transfer_tdl_sort(sort_type),
                jpim_evtdb_transfer_tdl_db(db_type));
}


/*****************************************************************************
 * FUNCTION
 *  jpim_evtdb_get_name
 * DESCRIPTION
 *  This function is for application to get the name of event database.
 * PARAMETERS
 *  db_type     [IN]    jpim_evtdb_db_enum
 * RETURNS
 *  return null when error.
 *****************************************************************************/
kal_wchar *jpim_evtdb_getName(kal_uint8 db_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JPIM_DEBUG(TRACE_GROUP_2, JPIM_EVTDB_GET_NAME);

    switch(db_type)
    {
#ifndef __COSMOS_MMI_PACKAGE__
    case JPIM_EVTDB_REMINDER:           return (kal_wchar*)GetString(STR_TODO_REMINDER);
    case JPIM_EVTDB_MEETING:            return (kal_wchar*)GetString(STR_TODO_MEETING);
    case JPIM_EVTDB_COURSE:             return (kal_wchar*)GetString(STR_TODO_COURSE);
    case JPIM_EVTDB_DATE:               return (kal_wchar*)GetString(STR_TODO_DATE);
    case JPIM_EVTDB_CALL:               return (kal_wchar*)GetString(STR_TODO_CALL);
    case JPIM_EVTDB_ANNIVERSARY:        return (kal_wchar*)GetString(STR_TODO_ANNIVERSARY);
    case JPIM_EVTDB_TASK:               return (kal_wchar*)GetString(STR_ID_TDL_TASKS);
#else
    case JPIM_EVTDB_PERSONAL:           return (kal_wchar*)GetString(STR_ID_VAPP_CAL_PERSONAL);
    case JPIM_EVTDB_MEETING:            return (kal_wchar*)GetString(STR_ID_VAPP_CAL_MEETING);
    case JPIM_EVTDB_SPECIALDAY:         return (kal_wchar*)GetString(STR_ID_VAPP_CAL_SPEC_DAY);
    case JPIM_EVTDB_BIRTHDAY:           return (kal_wchar*)GetString(STR_ID_VAPP_CAL_BIRTHDAY);
    case JPIM_EVTDB_OTHERS:             return (kal_wchar*)GetString(STR_ID_VAPP_CAL_OTHERS);
    case JPIM_EVTDB_TASK:               return (kal_wchar*)GetString(STR_ID_VAPP_CAL_TASKS);
#endif
    case JPIM_EVTDB_ALL:                return (kal_wchar*)L"Event List";
    default:
        ASSERT(0);
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jpim_evtdb_getFieldLabel
 * DESCRIPTION
 *  This function retrieves the label of each field.
 * PARAMETERS
 *  field       [IN]
 * RETURNS
 *  return null when error
 *****************************************************************************/
kal_wchar *jpim_evtdb_getFieldLabel(kal_uint8 db_type, kal_int32 field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JPIM_DEBUG_1(TRACE_GROUP_2, JPIM_EVTDB_GETFIELDLABEL, field);
    switch (field)
    {
#ifndef __COSMOS_MMI_PACKAGE__
        case JPIM_E_ALARM:
            return (kal_wchar*)GetString(STR_GLOBAL_ALARM);
        case JPIM_E_END:
            return (kal_wchar*)GetString(STR_TODO_END_TIME);
        case JPIM_E_START:
            return (kal_wchar*)GetString(STR_TODO_START_TIME);
        case JPIM_E_SUMMARY:
            return (kal_wchar*)GetString(STR_GLOBAL_SUBJECT);
#ifdef JSR_75_PIM_EXTRA_TODO
        case JPIM_E_LOCATION:
            return (kal_wchar*)GetString(STR_TODO_LOCATION);
        case JPIM_E_PRIORITY:
            return (kal_wchar*)GetString(STR_GLOBAL_PRIORITY);
        case JPIM_E_COMPLETED:
            return (kal_wchar*)GetString(STR_ID_TODO_STATUS);
        case JPIM_E_COMPLETION_DATE:
            //return (kal_wchar*)L"Completion Date";
            return (kal_wchar*)GetString(STR_ID_FNG_JAVA_PIM_COMPLETION_DATE);
#endif
#ifdef JSR_75_PIM_EXTRA_DETAIL
        case JPIM_E_NOTE:
            return (kal_wchar*)GetString(STR_GLOBAL_DETAILS);
#endif
#else /* __COSMOS_MMI_PACKAGE__ */
        case JPIM_E_ALARM:
            return (kal_wchar*)GetString(STR_ID_VAPP_CAL_REMINDER);
        case JPIM_E_END:
            if (db_type == JPIM_EVTDB_TASK)
            {
                return (kal_wchar*)GetString(STR_ID_VAPP_CAL_DUE_TO);
            }
            else
            {
                return (kal_wchar*)GetString(STR_ID_VAPP_CAL_TO);
            }
        case JPIM_E_START:
            return (kal_wchar*)GetString(STR_ID_VAPP_CAL_START);
        case JPIM_E_SUMMARY:
            return (kal_wchar*)GetString(STR_ID_VAPP_CAL_SUBJECT);
#ifdef JSR_75_PIM_EXTRA_TODO
        case JPIM_E_LOCATION:
            return (kal_wchar*)GetString(STR_ID_VAPP_CAL_LOC);
        case JPIM_E_PRIORITY:
            return (kal_wchar*)GetString(STR_ID_VAPP_CAL_PRIORITY);
        case JPIM_E_COMPLETED:
            return (kal_wchar*)GetString(STR_ID_FNG_JAVA_PIM_TODO_STATUS);
        case JPIM_E_COMPLETION_DATE:
            //return (kal_wchar*)L"Completion Date";
            return (kal_wchar*)GetString(STR_ID_FNG_JAVA_PIM_COMPLETION_DATE);
#endif
#ifdef JSR_75_PIM_EXTRA_DETAIL
        case JPIM_E_NOTE:
            return (kal_wchar*)GetString(STR_ID_VAPP_CAL_NOTE);
#endif
#endif /* __COSMOS_MMI_PACKAGE__ */
        default:
            return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jpim_evtdb_getCount
 * DESCRIPTION
 *  The function retrieves the total count of event database entries.
 * PARAMETERS
 *  void
 * RETURNS
 *  0~n, -1 means database error
 *****************************************************************************/
kal_int32 jpim_evtdb_getCount(kal_uint8 db_type, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 event_group;
    mmi_evtdb_java_get_entry_req_struct *p =
        (mmi_evtdb_java_get_entry_req_struct*) construct_local_para(
                                                sizeof(mmi_evtdb_java_get_entry_req_struct),
                                                TD_CTRL | TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JPIM_DEBUG(TRACE_GROUP_2, JPIM_EVTDB_GETCOUNT);

    p->count = 0;
    p->entry_ptr = NULL;
    p->index = 1;
    p->sort_type = MMI_EVTDB_SORT_BY_TIME;
	p->db_index = jpim_evtdb_transfer_tdl_db(db_type);

    /* set cmccphk_state before send message!! */
    jpim_evtdb_state = JPIM_EVTDB_STATE_GET_COUNT;
    jpim_evtdb_result = MMI_EVTDB_JAVA_ERROR;
    jpim_evtdb_count = -1;

	if (jpim_check_vm_state(0, vm_id))
    {
        jpim_send_ilm(p, MSG_ID_MMI_EVTDB_JAVA_GET_ENTRY_REQ);
        kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_PIM_EVTDB_GETCOUNT, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
    }
	  else
    {
        free_local_para((local_para_struct*) p);
    }

    if (jpim_evtdb_result != MMI_EVTDB_JAVA_SUCCESS)
    {
        return -1;
    }
    else
    {
        return jpim_evtdb_count;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jpim_evtdb_fetchByIndex
 * DESCRIPTION
 *  This function retrieves an entry from the event database. The data is filled into "entry" parameter.
 * PARAMETERS
 *  entry           [OUT]
 *  index           [IN]        0~n-1
 *  sort_type       [IN]        jpim_evtdb_sort_enum
 *  db_type         [IN]        jpim_evtdb_db_enum
 * RETURNS
 *  jpim_error_code_enum
 *****************************************************************************/
kal_int32 jpim_evtdb_fetchByIndex(mmi_evtdb_java_entry_struct *entry,
									   kal_uint16 index,
									   kal_uint8 sort_type,
									   kal_uint8 db_type,
									   kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 event_group;

    mmi_evtdb_java_get_entry_req_struct *p =
        (mmi_evtdb_java_get_entry_req_struct*) construct_local_para(
                                                sizeof(mmi_evtdb_java_get_entry_req_struct),
                                                TD_CTRL | TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    p->entry_ptr = entry;
    p->index = index;
    p->sort_type = MMI_EVTDB_SORT_BY_TIME;
    p->db_index = jpim_evtdb_transfer_tdl_db(db_type);
    p->count = 1;

    jpim_evtdb_result = MMI_EVTDB_JAVA_ERROR;
    jpim_evtdb_state = JPIM_EVTDB_STATE_GET_ENTRY;

	if (jpim_check_vm_state(0, vm_id))
    {
        jpim_send_ilm(p, MSG_ID_MMI_EVTDB_JAVA_GET_ENTRY_REQ);
        kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_PIM_EVTDB_FETCH_INDEX, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
        JPIM_DEBUG(TRACE_GROUP_2, JPIM_EVTDB_FETCHBYINDEX, entry->handle, entry->index);
    }
    else
    {
        free_local_para((local_para_struct*) p);
    }


    if(jpim_transfer_error_code(JPIM_EVENTDB, jpim_evtdb_result) == JPIM_SUCCESS)
    {
#ifdef JSR_75_PIM_EXTRA_ALARM_TIME_USER_DEFINE
        jpim_evtdb_adjustAlarmTime(entry, db_type, KAL_FALSE);
#endif
#ifndef __COSMOS_MMI_PACKAGE__
        if (db_type == JPIM_EVTDB_REMINDER || db_type == JPIM_EVTDB_MEETING || db_type == JPIM_EVTDB_COURSE ||
		    db_type == JPIM_EVTDB_DATE || db_type == JPIM_EVTDB_CALL|| db_type == JPIM_EVTDB_ANNIVERSARY || 
		    db_type == JPIM_EVTDB_ALL)
#else
        if (db_type == JPIM_EVTDB_PERSONAL || db_type == JPIM_EVTDB_MEETING || db_type == JPIM_EVTDB_SPECIALDAY ||
		    db_type == JPIM_EVTDB_BIRTHDAY || db_type == JPIM_EVTDB_OTHERS || db_type == JPIM_EVTDB_ALL)
#endif
        {
            if (applib_dt_compare_time(&(entry->endTime), &(entry->startTime), NULL) == DT_TIME_LESS)
            {
                memcpy(&(entry->endTime), &(entry->startTime), sizeof(applib_time_struct));
            }
        }
        if (db_type == JPIM_EVTDB_TASK)
        {
#ifdef JSR_75_PIM_EXTRA_TODO
		    if (entry->status == SRV_TDL_STATUS_UNDONE)
		    {
                entry->complete_time.nYear = 0;
                entry->complete_time.nMonth = 0;
                entry->complete_time.nDay = 0;
    }
#endif
		}
		
    }

    return jpim_transfer_error_code(JPIM_EVENTDB, jpim_evtdb_result);
}

/*****************************************************************************
 * FUNCTION
 *  jpim_evtdb_appendEntry
 * DESCRIPTION
 *  This function adds a new entry into the event database.
 *  If the entry is successfully added, values are assigned to the
 *  index and handle fields of the entry.
 * PARAMETERS
 *  entry         [IN/OUT]
 *  db_type       [IN]              jpim_evtdb_db_enum
 * RETURNS
 *  jpim_error_code_enum
 *****************************************************************************/
void jpim_evtdb_adjustEntry(mmi_evtdb_java_entry_struct *entry, kal_uint8 db_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (entry->startTime.nYear == 0 && entry->endTime.nYear!= 0)
    {
        memcpy(&(entry->startTime), &(entry->endTime), sizeof(applib_time_struct));
    }
    else if(entry->startTime.nYear != 0 && entry->endTime.nYear== 0)
    {
        memcpy(&(entry->endTime), &(entry->startTime), sizeof(applib_time_struct));
    }
    else if(entry->startTime.nYear == 0 && entry->endTime.nYear== 0)
    {
        entry->startTime.nYear = 2004;
        entry->startTime.nMonth = 1;
        entry->startTime.nDay = 1;
        entry->endTime.nYear = 2004;
        entry->endTime.nMonth = 1;
        entry->endTime.nDay = 1;
    }

	if(app_ucs2_strlen((kal_int8*)entry->note) == 0)
    {
		app_asc_str_to_ucs2_str((kal_int8*)entry->note, (kal_int8*)"No Content");
	}

#ifndef __COSMOS_MMI_PACKAGE__
    if (db_type == JPIM_EVTDB_REMINDER || db_type == JPIM_EVTDB_MEETING || db_type == JPIM_EVTDB_COURSE ||
		db_type == JPIM_EVTDB_DATE || db_type == JPIM_EVTDB_CALL|| db_type == JPIM_EVTDB_ANNIVERSARY || 
		db_type == JPIM_EVTDB_ALL)
#else
    if (db_type == JPIM_EVTDB_PERSONAL || db_type == JPIM_EVTDB_MEETING || db_type == JPIM_EVTDB_SPECIALDAY ||
		db_type == JPIM_EVTDB_BIRTHDAY || db_type == JPIM_EVTDB_OTHERS || db_type == JPIM_EVTDB_ALL)
#endif
    {
        entry->field_mask |= JPIM_EVTDB_MASK_NOTE;
		entry->field_mask |= JPIM_EVTDB_MASK_START_TIME;
		entry->field_mask |= JPIM_EVTDB_MASK_END_TIME;
        entry->field_mask |= JPIM_EVTDB_MASK_ALARM;
		entry->field_mask |= JPIM_EVTDB_MASK_REPEAT;
#ifdef	JSR_75_PIM_EXTRA_DETAIL
        entry->field_mask |= JPIM_EVTDB_MASK_DETAILS;
#endif
#ifdef  JSR_75_PIM_EXTRA_TODO
        entry->field_mask |= JPIM_EVTDB_MASK_LOCATION;

        //entry->status = MMI_TDL_STATUS_TOTAL;
        //entry->Priority = MMI_TDL_PRIORITY_TOTAL;
		entry->field_mask &= ~JPIM_EVTDB_MASK_STATUS;
		entry->field_mask &= ~JPIM_EVTDB_MASK_COMPLETE_TIME;
		entry->field_mask &= ~JPIM_EVTDB_MASK_PRIORITY;
#endif

        if (applib_dt_compare_time(&(entry->endTime), &(entry->startTime), NULL) == DT_TIME_LESS)
        {
            memcpy(&(entry->endTime), &(entry->startTime), sizeof(applib_time_struct));
        }
    }

    if (db_type == JPIM_EVTDB_TASK)
    {
        entry->field_mask |= JPIM_EVTDB_MASK_NOTE;
		entry->field_mask |= JPIM_EVTDB_MASK_START_TIME;
		entry->field_mask |= JPIM_EVTDB_MASK_END_TIME;
#ifdef  JSR_75_PIM_EXTRA_TODO
		entry->field_mask |= JPIM_EVTDB_MASK_PRIORITY;
		entry->field_mask |= JPIM_EVTDB_MASK_STATUS;
		entry->field_mask |= JPIM_EVTDB_MASK_COMPLETE_TIME;
		entry->field_mask &= ~JPIM_EVTDB_MASK_LOCATION;
#endif
#ifdef	JSR_75_PIM_EXTRA_DETAIL
		entry->field_mask |= JPIM_EVTDB_MASK_DETAILS;
#endif
        //entry->alarm = TODO_LIST_ALARM_TOTAL;
        //entry->repeat = ALM_FREQ_TOTAL;
		entry->field_mask &= ~JPIM_EVTDB_MASK_ALARM;
#ifdef JSR_75_PIM_EXTRA_ALARM_TIME_USER_DEFINE
		entry->field_mask &= ~JPIM_EVTDB_MASK_ALARM_TIME;
#endif
		entry->field_mask &= ~JPIM_EVTDB_MASK_REPEAT;
    }

}

#ifdef JSR_75_PIM_EXTRA_ALARM_TIME_USER_DEFINE
/*****************************************************************************
 * FUNCTION
 *  jpim_evtdb_adjustAlarmTime
 * DESCRIPTION
 *  This function adds a new entry into the event database.
 *  If the entry is successfully added, values are assigned to the
 *  index and handle fields of the entry.
 * PARAMETERS
 *  entry         [IN/OUT]
 *  db_type       [IN]              jpim_evtdb_db_enum
 * RETURNS
 *  jpim_error_code_enum
 *****************************************************************************/
void jpim_evtdb_adjustAlarmTime(mmi_evtdb_java_entry_struct *entry, kal_uint8 db_type, kal_bool write)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct tmp_time;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __COSMOS_MMI_PACKAGE__
	  if (db_type == JPIM_EVTDB_REMINDER || db_type == JPIM_EVTDB_MEETING || db_type == JPIM_EVTDB_COURSE ||
		  db_type == JPIM_EVTDB_DATE || db_type == JPIM_EVTDB_CALL|| db_type == JPIM_EVTDB_ANNIVERSARY)
#else
    if (db_type == JPIM_EVTDB_PERSONAL || db_type == JPIM_EVTDB_MEETING || db_type == JPIM_EVTDB_SPECIALDAY ||
		db_type == JPIM_EVTDB_BIRTHDAY || db_type == JPIM_EVTDB_OTHERS)
#endif
    {
#ifndef __COSMOS_MMI_PACKAGE__
        if(entry->alarm >= TODO_LIST_ALARM_BEFORE_5_MINS && entry->alarm <= TODO_LIST_ALARM_CUSTOM)
#else
        if(entry->alarm >= VAPP_CAL_REMINDER_5MINS_EARLIER && entry->alarm <= VAPP_CAL_REMINDER_1WEEK_EARLIER)
#endif
        {
            if(write)
	          {
	              applib_dt_decrease_time((applib_time_struct*)(&entry->startTime), (applib_time_struct*)(&entry->alarm_time), &tmp_time);		    
                entry->field_mask |= JPIM_EVTDB_MASK_ALARM_TIME;
            }
            else
            {
                applib_get_time_difference((applib_time_struct*)(&entry->startTime), (applib_time_struct*)(&entry->alarm_time), &tmp_time);
            }
            memcpy(&(entry->alarm_time), &tmp_time, sizeof(applib_time_struct));
        }
#ifndef __COSMOS_MMI_PACKAGE__
		    else if(entry->alarm == TODO_LIST_ALARM_ON)
		    {
		        if(write)
	          {
	              memcpy(&(entry->alarm_time), &(entry->startTime), sizeof(applib_time_struct));		    
				entry->field_mask |= JPIM_EVTDB_MASK_ALARM_TIME;
            }
            else
            {
                entry->alarm_time.nYear = 0;
                entry->alarm_time.nMonth = 0;
                entry->alarm_time.nDay = 0;
                entry->alarm_time.nHour= 0;
                entry->alarm_time.nMin= 0;
                entry->alarm_time.nSec= 0;
            }
		    
		    }
#endif
    }

#ifdef __COSMOS_MMI_PACKAGE__
    if (db_type == JPIM_EVTDB_BIRTHDAY ||db_type == JPIM_EVTDB_SPECIALDAY)
    {
         entry->alarm_time.nHour= 9;
         entry->alarm_time.nMin= 0;
         entry->alarm_time.nSec= 0;
    }
   
#endif
}
#endif


/*****************************************************************************
 * FUNCTION
 *  jpim_evtdb_appendEntry
 * DESCRIPTION
 *  This function adds a new entry into the event database.
 *  If the entry is successfully added, values are assigned to the
 *  index and handle fields of the entry.
 * PARAMETERS
 *  entry         [IN/OUT]
 *  db_type       [IN]              jpim_evtdb_db_enum
 * RETURNS
 *  jpim_error_code_enum
 *****************************************************************************/
kal_int32 jpim_evtdb_appendEntry(mmi_evtdb_java_entry_struct *entry, kal_uint8 db_type, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 event_group;
    mmi_evtdb_java_set_entry_req_struct *p =
        (mmi_evtdb_java_set_entry_req_struct*) construct_local_para(
                                                sizeof(mmi_evtdb_java_set_entry_req_struct),
                                                TD_CTRL | TD_RESET);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JPIM_DEBUG(TRACE_GROUP_2, JPIM_EVTDB_APPENDENTRY);

    jpim_evtdb_adjustEntry(entry, db_type);

#ifdef JSR_75_PIM_EXTRA_ALARM_TIME_USER_DEFINE
    jpim_evtdb_adjustAlarmTime(entry, db_type, KAL_TRUE);
#endif

    p->entry_ptr = entry;
    p->index = 0xffff;
    p->sort_type = MMI_EVTDB_SORT_BY_TIME;
    p->db_index = jpim_evtdb_transfer_tdl_db(db_type);

    jpim_evtdb_result = MMI_EVTDB_JAVA_ERROR;
    jpim_evtdb_state = JPIM_EVTDB_STATE_APPEND_ENTRY;
    jpim_evtdb_index = 0xffff;
    jpim_evtdb_handle = 0xffff;

	if (jpim_check_vm_state(1, vm_id))
    {
        jpim_send_ilm(p, MSG_ID_MMI_EVTDB_JAVA_SET_ENTRY_REQ);
        kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_PIM_EVTDB_APPEND_ENTRY, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
        entry->index = jpim_evtdb_index;
        entry->handle = jpim_evtdb_handle;
    }
    else
    {
        free_local_para((local_para_struct*) p);
    }

    return jpim_transfer_error_code(JPIM_EVENTDB, jpim_evtdb_result);

}


/*****************************************************************************
 * FUNCTION
 *  jpim_evtdb_upddateEntry
 * DESCRIPTION
 *  This function updates an entry in the event database.
 *  The index (physical storage index) must refer to a valid entry
 *  in the database, otherwise an "invalid index" error is returned.
 *  If the sort index changes after the update, a new sort index is assigned
 * PARAMETERS
 *  entry           [IN/OUT]
 * RETURNS
 *  jpim_error_code_enum
 *****************************************************************************/
kal_int32 jpim_evtdb_upddateEntry_ext(mmi_evtdb_java_entry_struct *entry, kal_uint8 db_type, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint32 event_group;

    mmi_evtdb_java_set_entry_req_struct *p =
        (mmi_evtdb_java_set_entry_req_struct*) construct_local_para(
                                                sizeof(mmi_evtdb_java_set_entry_req_struct),
                                                TD_CTRL | TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JPIM_DEBUG(TRACE_GROUP_2, JPIM_EVTDB_UPDDATEENTRY);

    jpim_evtdb_adjustEntry(entry, db_type);

#ifdef JSR_75_PIM_EXTRA_ALARM_TIME_USER_DEFINE
	  jpim_evtdb_adjustAlarmTime(entry, db_type, KAL_TRUE);
#endif

    p->entry_ptr = entry;
    p->index = entry->handle;
    p->sort_type = MMI_EVTDB_SORT_BY_TIME;
    p->db_index = jpim_evtdb_transfer_tdl_db(db_type);

    jpim_evtdb_result = MMI_EVTDB_JAVA_ERROR;
    jpim_evtdb_state = JPIM_EVTDB_STATE_UPDATE_ENTRY;
    jpim_evtdb_index = 0xffff;
    jpim_evtdb_handle = 0xffff;

	if (jpim_check_vm_state(1, vm_id))
    {
        jpim_send_ilm(p, MSG_ID_MMI_EVTDB_JAVA_SET_ENTRY_REQ);
        kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_PIM_EVTDB_UPDATE_ENTRY, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
        entry->index = jpim_evtdb_index;
        entry->handle = jpim_evtdb_handle;
    }
    else
    {
        free_local_para((local_para_struct*) p);
    }
    return jpim_transfer_error_code(JPIM_EVENTDB, jpim_evtdb_result);
}


/*****************************************************************************
 * FUNCTION
 *  jpim_evtdb_deleteEntry
 * DESCRIPTION
 *  This function deletes an entry from the event database.
 * PARAMETERS
 *  handle           [IN]
 * RETURNS
 *  jpim_error_code_enum
 *****************************************************************************/
kal_int32 jpim_evtdb_deleteEntry(kal_uint16 handle, kal_uint8 db_type, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint32 event_group;

    mmi_evtdb_java_set_entry_req_struct *p =
        (mmi_evtdb_java_set_entry_req_struct*) construct_local_para(
                                                sizeof(mmi_evtdb_java_set_entry_req_struct),
                                                TD_CTRL | TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JPIM_DEBUG(TRACE_GROUP_2, JPIM_EVTDB_DELETEENTRY);

    p->entry_ptr = NULL;
    p->index = handle;
    p->sort_type = MMI_EVTDB_SORT_BY_TIME;
    p->db_index = jpim_evtdb_transfer_tdl_db(db_type);

    jpim_evtdb_result = MMI_EVTDB_JAVA_ERROR;
    jpim_evtdb_state = JPIM_EVTDB_STATE_DELETE_ENTRY;

	if (jpim_check_vm_state(1, vm_id))
    {
        jpim_send_ilm(p, MSG_ID_MMI_EVTDB_JAVA_SET_ENTRY_REQ);
        kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_PIM_EVTDB_DELETE_ENTRY, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
    }
    else
    {
        free_local_para((local_para_struct*) p);
    }
    return jpim_transfer_error_code(JPIM_EVENTDB, jpim_evtdb_result);
}


/*****************************************************************************
 * FUNCTION
 *  jpim_evtdb_handler
 * DESCRIPTION
 *
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *
 *****************************************************************************/
kal_bool jpim_evtdb_handler(ilm_struct *ilm_ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_MMI_EVTDB_JAVA_GET_ENTRY_RSP:
        {
            mmi_evtdb_java_get_entry_rsp_struct *p = (mmi_evtdb_java_get_entry_rsp_struct*) ilm_ptr->local_para_ptr;

            if (jpim_evtdb_state == JPIM_EVTDB_STATE_GET_COUNT)
            {
                JPIM_DEBUG(TRACE_GROUP_2, JPIM_EVTDB_GET_COUNT_RSP);
                jpim_evtdb_result = p->result;
                jpim_evtdb_count = p->count;
                kal_set_eg_events(g_java_event_group_1, JAVA_EG_PIM_EVTDB_GETCOUNT, KAL_OR);
            }
            else if (jpim_evtdb_state == JPIM_EVTDB_STATE_GET_ENTRY)
            {
                JPIM_DEBUG(TRACE_GROUP_2, JPIM_EVTDB_GET_ENTRY_RSP);
                jpim_evtdb_result = p->result;
                kal_set_eg_events(g_java_event_group_1, JAVA_EG_PIM_EVTDB_FETCH_INDEX, KAL_OR);
            }
            else
            {
                ASSERT(0);
            }
            jpim_evtdb_state = JPIM_EVTDB_STATE_IDLE;
            break;
        }
        case MSG_ID_MMI_EVTDB_JAVA_SET_ENTRY_RSP:
        {
            mmi_evtdb_java_set_entry_rsp_struct *p = (mmi_evtdb_java_set_entry_rsp_struct*) ilm_ptr->local_para_ptr;


            if (jpim_evtdb_state == JPIM_EVTDB_STATE_APPEND_ENTRY)
            {
                JPIM_DEBUG(TRACE_GROUP_2, JPIM_EVTDB_APPEND_ENTRY_RSP);
                jpim_evtdb_result = p->result;
                jpim_evtdb_index = p->index;
                jpim_evtdb_handle = p->handle;
                kal_set_eg_events(g_java_event_group_1, JAVA_EG_PIM_EVTDB_APPEND_ENTRY, KAL_OR);
            }
            else if (jpim_evtdb_state == JPIM_EVTDB_STATE_UPDATE_ENTRY)
            {
                JPIM_DEBUG(TRACE_GROUP_2, JPIM_EVTDB_UPDATE_ENTRY_RSP);
                jpim_evtdb_result = p->result;
                jpim_evtdb_index = p->index;
                jpim_evtdb_handle = p->handle;
                kal_set_eg_events(g_java_event_group_1, JAVA_EG_PIM_EVTDB_UPDATE_ENTRY, KAL_OR);
            }
            else if (jpim_evtdb_state == JPIM_EVTDB_STATE_DELETE_ENTRY)
            {
                JPIM_DEBUG(TRACE_GROUP_2, JPIM_EVTDB_DELETE_ENTRY_RSP);
                jpim_evtdb_result = p->result;
                kal_set_eg_events(g_java_event_group_1, JAVA_EG_PIM_EVTDB_DELETE_ENTRY, KAL_OR);
            }
            else
            {
                ASSERT(0);
            }
            jpim_evtdb_state = JPIM_EVTDB_STATE_IDLE;
            break;
        }

        default:
            return KAL_FALSE;
    }

    return KAL_TRUE;
}

#endif
