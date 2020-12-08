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
 * ToDoListSrv.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * ToDoList data access APIs.
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
#include "MMI_features.h"

#if ((defined(__MMI_CALENDAR_EVENT__) || defined(__MMI_TODOLIST__)) && !defined(__COSMOS_MMI_PACKAGE__)) || defined(__COSMOS_MMI_PACKAGE__)

//#ifdef __MMI_SRV_TODOLIST__
/*****************************************************************************
 * Include
 *****************************************************************************/
#include "TodolistSrvGprot.h"
#include "custom_mmi_default_value.h"
#include "AlarmFrameworkProt.h"
#include "Unicodexdcl.h"
#include "MMI_common_app_trc.h"
#include "DateTimeType.h"
#include "APP_datetime.h"
#include "DebugInitDef_Int.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "mmi_frm_nvram_gprot.h"
#include "nvram_common_defs.h"
#include "string.h"
#include "mmi_common_app_trc.h"
#include "kal_trace.h"
#include "Unicodexdcl.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "todolistsrvGprot.h"
#include "mmi_rp_srv_todolist_def.h"
#include "ReminderSrvGprot.h"
#include "mmi_rp_srv_reminder_def.h"


#define MMI_TDL_SRV_TRACE0(sub_grp) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp)

#define MMI_TDL_SRV_TRACE1(sub_grp, arg) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg)
		
#define MMI_TDL_SRV_TRACE2(sub_grp, arg1, arg2) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2)

#define MMI_TDL_SRV_TRACE3(sub_grp, arg1, arg2, arg3) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2, arg3)

#define MMI_TDL_SRV_TRACE4(sub_grp, arg1, arg2, arg3, arg4) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2, arg3, arg4)

/*****************************************************************************
 * Static declaration
 *****************************************************************************/
#define SNS_BEGIN
 
typedef struct
{
	MMI_BOOL have_source;
	MMI_BOOL filter; // MMI_TRUE: don't show this kind of events on MMI
	srv_tdl_event_funcptr_table funcptr;
}srv_tdl_event_source_struct;

typedef struct
{
	srv_tdl_event_search_get_struct* event_buf;
	U32 event_count;
	S32 job_id;
	MMI_BOOL in_search;
}srv_tdl_event_search_source_struct;

typedef struct
{
	S32 search_id;
	srv_tdl_search_type_enum search_type;
	srv_tdl_event_id_struct *event_buf;
	U32 event_count;
	srv_tdl_event_search_source_struct source_search[SRV_TDL_EVENT_SOURCE_TOTAL];
}srv_tdl_event_search_struct;

typedef struct
{
    srv_tdl_event_source_enum source_id;
    U32 event_id;
    MYTIME begin_time;
}srv_tdl_event_sort_struct;


static srv_tdl_event_search_struct g_event_search_context[TDL_MAX_EVENT_SEARCH_COUNT];

#define SNS_END

static srv_tdl_event_short_struct g_srv_event_list[NUM_OF_CAL];
static srv_tdl_task_short_struct g_srv_todo_list[NUM_OF_TASK];

const U8 g_srv_clndr_weekday_index[] = 
{
    0x01,   /* DAY_SUN */
    0x02,   /* DAY_MON */
    0x04,   /* DAY_TUE */
    0x08,   /* DAY_WED */
    0x10,   /* DAY_THU */
    0x20,   /* DAY_FRI */
    0x40    /* DAY_SAT */
};

static srv_tdl_event_source_struct g_srv_tdl_event_source_table[SRV_TDL_EVENT_SOURCE_TOTAL] = {(MMI_BOOL)0};
U32 g_sns_reminder_id;
U8 g_sns_reminder_source;
S32 reminder_search_id;
static U16 srv_tdl_local_event_add(
                const srv_tdl_event_struct *data, 
                const srv_tdl_event_source_enum source_id,
                U16 *index);
static U16 srv_tdl_local_event_delete(const srv_tdl_event_source_enum source_id, const U16 index);
static U16 srv_tdl_local_event_update(
                    const srv_tdl_event_struct *data, 
                    const srv_tdl_event_source_enum source_id,
                    const U16 index);
static U16 srv_tdl_local_event_get(
                srv_tdl_event_struct *buff, 
                const U16 buff_size,
                const srv_tdl_event_source_enum source_id,
                const U16 index);
static U16 srv_tdl_event_get_all_index(
                                 srv_tdl_event_task_struct *list, 
                                 const U16 buff_size, 
                                 U16 *count);
static U16 srv_tdl_event_get_free(U16 *count);
static U16 srv_tdl_task_add(
                const srv_tdl_task_struct *data, 
                U16 *index);
static U16 srv_tdl_task_delete(const U16 index);
static U16 srv_tdl_task_update(
                    const srv_tdl_task_struct *data, 
                    const U16 index);
static U16 srv_tdl_task_get(
                srv_tdl_task_struct *buff, 
                const U16 buff_size, 
                const U16 index);
static U16 srv_tdl_task_get_all_index(
                                 srv_tdl_event_task_struct *list, 
                                 const U16 buff_size, 
                                 U16 *count);
static U16 srv_tdl_task_get_free(U16 *count);
                
static MMI_BOOL srv_tdl_event_search_check_time(
                const srv_tdl_event_short_struct *pevent, 
                const MYTIME date_time);
                
static MMI_BOOL srv_tdl_event_search_check_before(
                const srv_tdl_event_short_struct *pevent, 
                const MYTIME date_time);
static MMI_BOOL srv_tdl_event_search_check_after(
                const srv_tdl_event_short_struct *pevent, 
                const MYTIME date_time);
static MMI_BOOL srv_tdl_event_search_check_incoming(
                const srv_tdl_event_short_struct *pevent, 
                const MYTIME date_time);
static MMI_BOOL srv_tdl_event_search_check_previous(
                const srv_tdl_event_short_struct *pevent, 
                const MYTIME date_time);
static MMI_BOOL srv_tdl_event_search_check_all(
                const srv_tdl_event_short_struct *pevent, 
                const MYTIME date_time);
static MMI_BOOL srv_tdl_event_search_check_duration(
                const srv_tdl_event_short_struct *pevent, 
                const MYTIME *begin_time, 
                const MYTIME *end_time);
                
static MMI_BOOL srv_tdl_event_search_check_subject(
                const srv_tdl_event_short_struct *pevent, 
                const U16 *string);
                
static MMI_BOOL srv_tdl_event_search_check_location(
                const srv_tdl_event_short_struct *pevent, 
                const U16 *string);

static MMI_BOOL srv_tdl_event_search_check_category(
                const srv_tdl_event_short_struct *pevent, 
                const U8 category);
                            
static MMI_BOOL srv_tdl_task_search_check_time(
                            const srv_tdl_task_short_struct *ptask, 
                            const MYTIME date_time);
                            
static MMI_BOOL srv_tdl_task_search_check_duration(
                            const srv_tdl_task_short_struct *ptask, 
                            const MYTIME *begin_time,
                            const MYTIME *end_time);
                            
static MMI_BOOL srv_tdl_task_search_check_subject(
                            const srv_tdl_task_short_struct *ptask, 
                            const U16 *string);
                            
static MMI_BOOL srv_tdl_task_search_check_status(
                            const srv_tdl_task_short_struct *ptask, 
                            const U16 status);
                            
static MMI_BOOL srv_tdl_task_search_check_before(
                            const srv_tdl_task_short_struct *ptask, 
                            const MYTIME date_time);
                                               
static srv_tdl_compare_result_enum srv_tdl_sort_default_compare(
                                          const U16 index1,
                                          const U16 type1, 
                                          const U16 index2, 
                                          const U16 type2, 
                                          const srv_tdl_sort_type_enum sort_type);
                                                               
static U16 srv_tdl_event_get_new_index(void);
static U16 srv_tdl_task_get_new_index(void);

#define SNS_BEGIN
#define GLOBAL_FUTION_FOR_SNS_SERVICE

/*****************************************************************************
 * FUNCTION
 *	srv_tdl_add_source
 * DESCRIPTION
 *	show external event in calendar APP
 * PARAMETERS
 *	source_id: 
 *    srv_tdl_external_event_funcptr_table: 
 * RETURNS
 *	the result of add source operation
 * RETURN VALUES
 *	MMI_TRUE:    add source success
 *    MMI_FALSE:  add source error 
 *****************************************************************************/ 

MMI_BOOL srv_tdl_add_source(srv_tdl_event_source_enum source_id, srv_tdl_event_funcptr_table funcptr_table)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/  
    if(g_srv_tdl_event_source_table[source_id].have_source == MMI_TRUE)
	{
	    ret = MMI_FALSE;
		goto END;
	}
	
    if(funcptr_table.event_get_funcptr == NULL)
	{
	    ret = MMI_FALSE;
		goto END;
	}
	else
	{
		 g_srv_tdl_event_source_table[source_id].funcptr.event_get_funcptr = funcptr_table.event_get_funcptr;
	}
	
	if(funcptr_table.event_search_funcptr == NULL && (funcptr_table.event_async_search_begin_funcptr == NULL || 
		funcptr_table.event_async_search_funcptr == NULL || funcptr_table.event_async_search_end_funcptr == NULL))
	{
	    ret = MMI_FALSE;
		goto END;
	}
	if(funcptr_table.event_search_funcptr)
	{
	    g_srv_tdl_event_source_table[source_id].funcptr.event_search_funcptr = funcptr_table.event_search_funcptr;
	}
	else
	{
		g_srv_tdl_event_source_table[source_id].funcptr.event_async_search_begin_funcptr = funcptr_table.event_async_search_begin_funcptr;
		g_srv_tdl_event_source_table[source_id].funcptr.event_async_search_funcptr = funcptr_table.event_async_search_funcptr;
		g_srv_tdl_event_source_table[source_id].funcptr.event_async_search_end_funcptr = funcptr_table.event_async_search_end_funcptr;
	}
	
	if(funcptr_table.event_update_funcptr != NULL)
	{
	    g_srv_tdl_event_source_table[source_id].funcptr.event_update_funcptr = funcptr_table.event_update_funcptr;
	}
	if(funcptr_table.event_add_funcptr != NULL)
	{
	    g_srv_tdl_event_source_table[source_id].funcptr.event_add_funcptr = funcptr_table.event_add_funcptr;
	}
	if(funcptr_table.event_delete_funcptr != NULL)
	{
	    g_srv_tdl_event_source_table[source_id].funcptr.event_delete_funcptr = funcptr_table.event_delete_funcptr;
	}
	g_srv_tdl_event_source_table[source_id].have_source = MMI_TRUE;
	
END:	
	MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_ADD_EVENT_SOURCE, source_id, ret);
	return ret;

}

/*****************************************************************************
 * FUNCTION
 *	srv_tdl_delete_source
 * DESCRIPTION
 *	not show external event in calendar APP anymore
 * PARAMETERS
 *	source_id:  
 * RETURNS
 *	the result of delete source operation
 * RETURN VALUES
 *	MMI_TRUE:    delete source success
 *    MMI_FALSE:  delete source error 
 *****************************************************************************/ 
MMI_BOOL srv_tdl_delete_source(srv_tdl_event_source_enum source_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	MMI_BOOL ret = MMI_TRUE;


	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/  
    if(g_srv_tdl_event_source_table[source_id].have_source == MMI_FALSE)
	{
	    ret = MMI_FALSE;
	}
	else
	{
        g_srv_tdl_event_source_table[source_id].have_source = MMI_FALSE;
		ret = MMI_TRUE;
	}
	
	MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_DELETE_EVENT_SOURCE, source_id, ret);
	return ret;
}

#define STATIC_FUNCTION

/*****************************************************************************
 * FUNCTION
 *  srv_tdl_get_first_available_search_id
 * DESCRIPTION
 *  Get first available search id
 * PARAMETERS
 *  void        
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 srv_tdl_event_get_available_search_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 ret = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < TDL_MAX_EVENT_SEARCH_COUNT; i++)
    {
        if (g_event_search_context[i].search_id <= 0)
        {
            memset(&g_event_search_context[i], 0, sizeof(srv_tdl_event_search_struct));
            g_event_search_context[i].search_id = 1 + i;
			ret = g_event_search_context[i].search_id;
			break;
        }
    }
	MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_GET_AVAILABLE_SEARCH_ID, ret);
    return ret;
}



/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_get_all_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  S32
 *****************************************************************************/
static srv_tdl_event_id_struct** srv_tdl_event_get_all_event(S32 search_id,  S32 *event_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    srv_tdl_event_id_struct ** evt_buf = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 0; i < TDL_MAX_EVENT_SEARCH_COUNT; i++)
	{
		if (g_event_search_context[i].search_id == search_id)
		{   
		    if(event_count)
		    {
			    *event_count = g_event_search_context[i].event_count;
			}
			evt_buf = &g_event_search_context[i].event_buf;
			break;
		}
	}
	MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_GET_ALL_EVENT, search_id, g_event_search_context[i].event_count, evt_buf);
    return evt_buf;
}



/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_get_all_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  S32
 *****************************************************************************/
static MMI_BOOL srv_tdl_event_set_all_event_count(S32 search_id,  U32 event_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 0; i < TDL_MAX_EVENT_SEARCH_COUNT; i++)
	{
		if (g_event_search_context[i].search_id == search_id)
		{   
			g_event_search_context[i].event_count = event_count;
			ret = MMI_TRUE;
			break;
		}
	}
	MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_SET_ALL_EVENT_COUNT, search_id, event_count, ret);
    return ret;
}



/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_reset_search_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 srv_tdl_event_reset_search_context(S32 search_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 ret = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 0; i < TDL_MAX_EVENT_SEARCH_COUNT; i++)
	{
		if (g_event_search_context[i].search_id == search_id)
		{   
			g_event_search_context[i].search_id = 0;
			g_event_search_context[i].event_count = 0;
		    if(g_event_search_context[i].event_buf)
			{
			    OslMfree(g_event_search_context[i].event_buf);
			}
			ret = i;
			break;
		}
	}
	MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_RESET_SEARCH_CONTEXT, search_id, ret);
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_get_search_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 srv_tdl_event_get_search_id(srv_tdl_event_source_enum source_id, S32 job_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 id = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 0; i < TDL_MAX_EVENT_SEARCH_COUNT; i++)
	{
		if (g_event_search_context[i].source_search[source_id].job_id == job_id)
		{	
			id = g_event_search_context[i].search_id;
			break;
		}
	}
	MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_GET_SEARCH_ID, source_id, job_id, id);
    return id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_set_search_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  S32
 *****************************************************************************/
static MMI_BOOL srv_tdl_event_set_search_type(S32 search_id, srv_tdl_search_type_enum search_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 0; i < TDL_MAX_EVENT_SEARCH_COUNT; i++)
	{
		if (g_event_search_context[i].search_id == search_id)
		{
			g_event_search_context[i].search_type = search_type;
			ret = MMI_TRUE;
			break;
		}
	}
	MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_SET_SEARCH_TYPE,search_id, search_type, ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_get_search_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  S32
 *****************************************************************************/
static MMI_BOOL srv_tdl_event_get_search_type(S32 search_id, srv_tdl_search_type_enum *search_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 0; i < TDL_MAX_EVENT_SEARCH_COUNT; i++)
	{
		if (g_event_search_context[i].search_id == search_id)
		{
			*search_type = g_event_search_context[i].search_type;
			ret = MMI_TRUE;
			break;
		}
	}
	MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_GET_SEARCH_TYPE,search_id, *search_type, ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_set_job_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  S32
 *****************************************************************************/
static MMI_BOOL srv_tdl_event_set_job_id(S32 search_id, srv_tdl_event_source_enum source_id, S32 job_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 0; i < TDL_MAX_EVENT_SEARCH_COUNT; i++)
	{
		if (g_event_search_context[i].search_id == search_id)
		{
			g_event_search_context[i].source_search[source_id].job_id = job_id;
			ret = MMI_TRUE;
			break;
		}
	}
	MMI_TDL_SRV_TRACE4(MMI_TDL_SRV_SET_JOB_ID,search_id, source_id, job_id, ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_get_search_job_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  S32
 *****************************************************************************/
static MMI_BOOL srv_tdl_event_get_job_id(S32 search_id, srv_tdl_event_source_enum source_id, S32 *job_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 0; i < TDL_MAX_EVENT_SEARCH_COUNT; i++)
	{
		if (g_event_search_context[i].search_id == search_id)
		{
			*job_id = g_event_search_context[i].source_search[source_id].job_id;
			ret = MMI_TRUE;
			break;
		}
	}
	MMI_TDL_SRV_TRACE4(MMI_TDL_SRV_GET_JOB_ID,search_id, source_id, *job_id, ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_get_source_buf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  S32
 *****************************************************************************/
static srv_tdl_event_search_get_struct** srv_tdl_event_get_source_buf(S32 search_id, srv_tdl_event_source_enum source_id, S32 *event_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    srv_tdl_event_search_get_struct **buf = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 0; i < TDL_MAX_EVENT_SEARCH_COUNT; i++)
	{
		if (g_event_search_context[i].search_id == search_id)
		{
		    if(event_count)
		    {
			    *event_count = g_event_search_context[i].source_search[source_id].event_count;
			}
			buf = &g_event_search_context[i].source_search[source_id].event_buf;
			break;
		}
	}
	MMI_TDL_SRV_TRACE4(MMI_TDL_SRV_GET_SOURCE_BUF,search_id, source_id, g_event_search_context[i].source_search[source_id].event_count, buf);
    return buf;
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_set_source_event_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  S32
 *****************************************************************************/
static MMI_BOOL srv_tdl_event_set_source_event_count(S32 search_id, srv_tdl_event_source_enum source_id, S32 event_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 0; i < TDL_MAX_EVENT_SEARCH_COUNT; i++)
	{
		if (g_event_search_context[i].search_id == search_id)
		{
		    g_event_search_context[i].source_search[source_id].event_count = event_count;
			ret = MMI_TRUE;
			break;
		}
	}
	MMI_TDL_SRV_TRACE4(MMI_TDL_SRV_SET_SOURCE_EVENT_COUNT,search_id, source_id, event_count, ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_set_source_search_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  S32
 *****************************************************************************/
static MMI_BOOL srv_tdl_event_set_source_search_status(S32 search_id, srv_tdl_event_source_enum source_id, MMI_BOOL in_search)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 0; i < TDL_MAX_EVENT_SEARCH_COUNT; i++)
	{
		if (g_event_search_context[i].search_id == search_id)
		{
		    g_event_search_context[i].source_search[source_id].in_search = in_search;
			ret = MMI_TRUE;
			break;
		}
	}
	MMI_TDL_SRV_TRACE4(MMI_TDL_SRV_SET_SOURCE_SEARCH_STATUS,search_id, source_id, in_search, ret);
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_get_source_search_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  S32
 *****************************************************************************/
static MMI_BOOL srv_tdl_event_get_source_search_status(S32 search_id, srv_tdl_event_source_enum source_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    MMI_BOOL ret = MMI_FALSE;
	MMI_BOOL in_search = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 0; i < TDL_MAX_EVENT_SEARCH_COUNT; i++)
	{
		if (g_event_search_context[i].search_id == search_id)
		{
		    in_search = g_event_search_context[i].source_search[source_id].in_search;
			ret = MMI_TRUE;
			break;
		}
	}
	MMI_TDL_SRV_TRACE4(MMI_TDL_SRV_GET_SOURCE_SEARCH_STATUS,search_id, source_id, in_search, ret);
    return in_search;
}


static void srv_tdl_event_insert_sort(srv_tdl_event_sort_struct *buffer, U32 count)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												         */
	/*----------------------------------------------------------------*/
	S32 i, j;
	srv_tdl_event_sort_struct curr_node;
	/*----------------------------------------------------------------*/
	/* Code Body													         */
    /*----------------------------------------------------------------*/ 
	MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_INSERT_SORT,buffer, count);
    for(i = 1; i < count; i++)
    {
        memcpy(&curr_node, &buffer[i], sizeof(srv_tdl_event_sort_struct));
        for(j = i-1; j >= 0; j--)
        {  
            if(CompareTime(curr_node.begin_time, buffer[j].begin_time, NULL) < 0)
            {
                memcpy(&buffer[j + 1], &buffer[j], sizeof(srv_tdl_event_sort_struct));
            }
            else
            { 
                break;
            }    
        }  
        memcpy(&buffer[j + 1], &curr_node, sizeof(srv_tdl_event_sort_struct));
    }
}

/*****************************************************************************
 * FUNCTION
 *	srv_tdl_event_async_search_begin
 * DESCRIPTION
 *	
 * PARAMETERS
 *	
 * RETURNS
 *	job id
 * RETURN VALUES
 *	
 *****************************************************************************/ 
static S32 srv_tdl_event_async_search_begin(
                                      srv_tdl_event_source_enum source_id,
                                      const srv_tdl_search_filter_struct *filter,
									  const srv_tdl_event_sort_enum sort_type,
									  const event_async_callback callback)

{
	/*----------------------------------------------------------------*/
	/* Local Variables												         */
	/*----------------------------------------------------------------*/
	srv_tdl_async_event_search_begin_funcptr funcptr;
    S32 job_id = 0;
    S32 ret = 0;
	/*----------------------------------------------------------------*/
	/* Code Body													         */
	/*----------------------------------------------------------------*/
	if(!g_srv_tdl_event_source_table[source_id].have_source)
	{
		 ret = -1;
		 goto END;
	}
	funcptr = g_srv_tdl_event_source_table[source_id].funcptr.event_async_search_begin_funcptr;

	if(funcptr == NULL)
	{
		ret = -2;
		goto END;
	}
    job_id = funcptr(source_id, filter, sort_type, callback);
END:	
	MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_SEARCH_BEGIN, source_id, ret, job_id);
	return job_id;

}


/*****************************************************************************
 * FUNCTION
 *	srv_tdl_event_async_search
 * DESCRIPTION
 *	
 * PARAMETERS
 *	
 * RETURNS
 *	
 * RETURN VALUES
 *	
 *****************************************************************************/ 
static S32 srv_tdl_event_async_search(srv_tdl_event_source_enum source_id,
									    kal_int32		   job_id,	 
										srv_tdl_event_search_get_struct  *buf,	  
										const kal_uint32   buf_size,
										const kal_int32    index)

{
	/*----------------------------------------------------------------*/
	/* Local Variables												         */
	/*----------------------------------------------------------------*/
	srv_tdl_async_event_search_funcptr funcptr;
    S32 ret = 0;
    S32 err = 0;
	/*----------------------------------------------------------------*/
	/* Code Body													         */
	/*----------------------------------------------------------------*/ 
	if(!g_srv_tdl_event_source_table[source_id].have_source)
	{
		err = -1;
		goto END;
	}
	funcptr = g_srv_tdl_event_source_table[source_id].funcptr.event_async_search_funcptr;
	if(funcptr == NULL)
	{
		err = -2;
		goto END;
	}
    ret = funcptr(job_id, buf, buf_size, index);
END:	
	MMI_TDL_SRV_TRACE4(MMI_TDL_SRV_SEARCH, source_id, job_id, err, ret);
	return ret;

}


/*****************************************************************************
 * FUNCTION
 *	srv_tdl_event_async_search_end
 * DESCRIPTION
 *	
 * PARAMETERS
 *	
 * RETURNS
 *	
 * RETURN VALUES
 *	
 *****************************************************************************/ 
static S32 srv_tdl_event_async_search_end(srv_tdl_event_source_enum source_id,
                                      const kal_int32 job_id)

{
	/*----------------------------------------------------------------*/
	/* Local Variables												         */
	/*----------------------------------------------------------------*/
	srv_tdl_async_event_search_end_funcptr funcptr;
    MMI_BOOL ret = MMI_FALSE;
	S32 err = 0;

	/*----------------------------------------------------------------*/
	/* Code Body													         */
	/*----------------------------------------------------------------*/ 
	if(!g_srv_tdl_event_source_table[source_id].have_source)
	{
		err = -1;
		goto END;
	}
	funcptr = g_srv_tdl_event_source_table[source_id].funcptr.event_async_search_end_funcptr;
	if(funcptr == NULL)
	{
		err = -2;
		goto END;
	}
    ret = (MMI_BOOL)funcptr(job_id);
	MMI_TDL_SRV_TRACE4(MMI_TDL_SRV_SEARCH_END, source_id, job_id, err, ret);
END:	
	return ret;

}

/*****************************************************************************
 * FUNCTION
 *	srv_tdl_event_sync_search
 * DESCRIPTION
 *	
 * PARAMETERS
 *	
 * RETURNS
 *	the searched event number 
 * RETURN VALUES
 *	
 *****************************************************************************/ 
static S32 srv_tdl_event_sync_search(srv_tdl_event_source_enum source_id,
										const void *buffer,
										const U32  buffer_size,
										const srv_tdl_search_filter_struct filter,
										const srv_tdl_event_sort_enum sort_type)

{
	/*----------------------------------------------------------------*/
	/* Local Variables												         */
	/*----------------------------------------------------------------*/
	srv_tdl_search_event_funcptr funcptr;
    S32 ret;

	/*----------------------------------------------------------------*/
	/* Code Body													         */
	/*----------------------------------------------------------------*/ 
	if(!g_srv_tdl_event_source_table[source_id].have_source)
	{
		return 0;
	}
	funcptr = g_srv_tdl_event_source_table[source_id].funcptr.event_search_funcptr;
	if(funcptr == NULL)
	{
		return 0;
	}
    ret = funcptr(buffer, buffer_size, filter, sort_type);
	return ret;

}

void srv_tdl_event_search_timerout_handler(void* search)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_tdl_search_callback_struct op_evt;
    U32 i, source_id = 0;
    U32 search_id = (U32)search;
	srv_tdl_event_search_get_struct **source_buf;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(TIMER_ID_SRV_TDL_SEARCH_1+search_id-1);
	
	for(i = 0; i < SRV_TDL_EVENT_SOURCE_TOTAL; i++)
	{
		source_buf = srv_tdl_event_get_source_buf(search_id, (srv_tdl_event_source_enum)i, NULL);
		if(source_buf && *source_buf)
		{
		    OslMfree(*source_buf);
			*source_buf = NULL;
		}
	    if(srv_tdl_event_get_source_search_status(search_id, (srv_tdl_event_source_enum)i))
		{
            source_id |= (0x1 << i);
			srv_tdl_event_set_source_search_status(search_id, (srv_tdl_event_source_enum)i, MMI_FALSE);
		}
	}

	MMI_FRM_INIT_EVENT(&op_evt, EVT_ID_SRV_TDL_EVENT_SEARCH);
    op_evt.job_id = search_id;
	op_evt.success = MMI_FALSE;
    op_evt.event_cnt = 0;
    MMI_FRM_CB_EMIT_POST_EVENT(&op_evt);

	MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_SEARCH_TIMEOUT, search_id, source_id);
}


S32 srv_tdl_event_update_sns_reminder(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tdl_search_filter_struct search_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	search_info.type = SRV_TDL_SEARCH_TYPE_ALARM;
	GetDateTime(&search_info.u.date_time);
	reminder_search_id = srv_tdl_event_search_begin(&search_info,SRV_TDL_EVENT_SORT_ALARM_TIME, SRV_TDL_EVENT_SOURCE_TOTAL);

	MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_UPDATE_SNS_REMINDER, reminder_search_id);
	return reminder_search_id;
}

static kal_int32 srv_tdl_event_async_search_callback(srv_tdl_event_source_enum source_id,
	                                  const kal_int32 job_id, const kal_int32 event_count)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												         */
	/*----------------------------------------------------------------*/
	const S32 max_count_each_src = 80;
	S32 return_count;
	S32 total_count = 0;
	static S32 index = 0;
	int ret = 0;
	S32 i, j;
	S32 search_id;
	srv_tdl_event_search_get_struct *source_temp_buf;
	srv_tdl_event_search_get_struct **source_buf;
	srv_tdl_event_sort_struct *buffer;
	srv_tdl_event_sort_struct *temp_buf1, *temp_buf2;
	srv_tdl_event_id_struct **id_buffer = NULL;
	srv_tdl_event_id_struct *id_temp_buffer;
    MMI_BOOL timer_exist,cancel_success;
	srv_tdl_search_callback_struct op_evt;
	S32 source_event_count;
	srv_tdl_search_type_enum search_type;
	srv_tdl_event_struct *pevent; 
	MYTIME alarm_launch;
	srv_reminder_ret_enum reminder_ret = SRV_REMINDER_RET_OK;
	srv_tdl_event_source_enum temp_src_id = SRV_TDL_EVENT_SOURCE_LOCAL;
	U32 new_event_id = 0, last_event_id;  
	S16 error;
	U16 id_h, id_l, nYear;
	U8 sns_src;
	MYTIME reminder_time,incTime, currTime;
	srv_tdl_update_event_funcptr funcptr;
	/*----------------------------------------------------------------*/
	/* Code Body													         */
    /*----------------------------------------------------------------*/ 
	MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_SEARCH_CALLBACK_BEGIN, source_id, job_id, event_count);
    search_id = srv_tdl_event_get_search_id(source_id, job_id);
    if(search_id <= 0)
    {
        MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_SEARCH_CALLBACK_CANCELED, source_id, job_id );
        return -1;
    }
    // if timer has end; return
	timer_exist = IsMyTimerExist(TIMER_ID_SRV_TDL_SEARCH_1+search_id-1);
	if(!timer_exist)
	{
		return -2;
	}
	
    if(event_count > max_count_each_src)
    {
        return_count = max_count_each_src;
    }
    else
    {
        return_count = event_count;
    }
	srv_tdl_event_get_search_type(search_id, &search_type);
	
    if(return_count > 0)
	{
	    source_buf = srv_tdl_event_get_source_buf(search_id, source_id, NULL);
	    *source_buf = (srv_tdl_event_search_get_struct *)OslMalloc(return_count * sizeof(srv_tdl_event_search_get_struct));
		source_event_count = srv_tdl_event_async_search(
						                   source_id, 
						                   job_id, 
						                   *source_buf, 
						                   return_count * sizeof(srv_tdl_event_search_get_struct),
						                   index);
		if(source_id != SRV_TDL_EVENT_SOURCE_LOCAL)
		{
		    return_count = source_event_count;
		}
		if(return_count != source_event_count)
		{
			OslMfree(*source_buf);
			*source_buf = NULL;
		}
		srv_tdl_event_set_source_event_count(search_id, source_id,source_event_count);
		srv_tdl_event_get_all_event(search_id, &total_count);
		total_count += source_event_count;  
		srv_tdl_event_set_all_event_count(search_id, total_count);
	}
	
	srv_tdl_event_async_search_end(source_id, job_id);
	srv_tdl_event_set_source_search_status(search_id, source_id, MMI_FALSE);

//    check if all async search call back
	for(i = 0; i < SRV_TDL_EVENT_SOURCE_TOTAL; i++)
	{
	    if(srv_tdl_event_get_source_search_status(search_id, (srv_tdl_event_source_enum)i))
		{
		    MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_SEARCH_CALLBACK_WAIT, search_id, source_id, total_count);
		    return ret;
		}
	}

    // all source search callback
	StopTimer(TIMER_ID_SRV_TDL_SEARCH_1+search_id-1);
    srv_tdl_event_get_all_event(search_id, &total_count);
    if(total_count > 0)
    {
        buffer = (srv_tdl_event_sort_struct *)OslMalloc(total_count * sizeof(srv_tdl_event_sort_struct));
        temp_buf2 = temp_buf1 = buffer;
        
        for(i = 0; i < SRV_TDL_EVENT_SOURCE_TOTAL; i++)    
		{
		    source_buf = srv_tdl_event_get_source_buf(search_id, (srv_tdl_event_source_enum)i, &source_event_count);
			if(*source_buf)
			{
			   source_temp_buf = *source_buf;
			   for(j = 0; j < source_event_count; j++)
			   {   
			       temp_buf1->source_id = (srv_tdl_event_source_enum)i;
			       temp_buf1->event_id = source_temp_buf->event_id;
			       memcpy(&(temp_buf1->begin_time), &(source_temp_buf->begin_time),sizeof(MYTIME));
			       temp_buf1++; 
			       source_temp_buf++;
			   }
			}
		}
		// sort SNS event and local event together
		srv_tdl_event_insert_sort(buffer, total_count);

		// copy data
		id_buffer = srv_tdl_event_get_all_event(search_id, NULL);
	    *id_buffer = (srv_tdl_event_id_struct *)OslMalloc(total_count * sizeof(srv_tdl_event_id_struct));
	    id_temp_buffer = *id_buffer;
	    for(i = 0; i < total_count; i++)
	    {
	    	id_temp_buffer->source_id = temp_buf2->source_id;
			id_temp_buffer->event_id = temp_buf2->event_id;
			temp_buf2++;
			id_temp_buffer++;
	    }
	    // free buffer
	    OslMfree(buffer);
	    for(i = 0; i < SRV_TDL_EVENT_SOURCE_TOTAL; i++)
		{
		    source_buf = srv_tdl_event_get_source_buf(search_id,(srv_tdl_event_source_enum)i, NULL);
		    if(*source_buf)
			{
			    OslMfree(*source_buf);
				*source_buf = NULL;
			}
		}
	}


	if(search_type == SRV_TDL_SEARCH_TYPE_ALARM)
	{
		pevent = (srv_tdl_event_struct *)OslMalloc(sizeof(srv_tdl_event_struct));
		memset(&alarm_launch, 0, sizeof(alarm_launch));
		for(i = 0; i < total_count; i++)
		{
			srv_tdl_event_get(
				pevent, 
				sizeof(srv_tdl_event_struct),
				(*id_buffer)[i].source_id,
				(*id_buffer)[i].event_id); 
			
            // get next reminder time
	        memset(&incTime, 0, sizeof(MYTIME));
	 //       incTime.nMin = pevent->alarm.snooze_interval * pevent->alarm.snooze;
	        IncrementTime(pevent->alarm.first_launch, incTime, &reminder_time);

			GetDateTime(&currTime);
			if((CompareTime(reminder_time, currTime, NULL) <= 0) && (pevent->category != SRV_TDL_CATEGORY_BIRTHDAY))
			{
				memset(&pevent->alarm, 0, sizeof(srv_tdl_alarm_struct));
		/*		srv_tdl_event_update(
					 pevent, 
					(*id_buffer)[i].source_id,
					(*id_buffer)[i].event_id);*/
			    funcptr = g_srv_tdl_event_source_table[(*id_buffer)[i].source_id].funcptr.event_update_funcptr;
	            ret = funcptr(pevent, (*id_buffer)[i].source_id, (*id_buffer)[i].event_id);
				srv_tdl_event_update_sns_reminder();
                goto END;
			}
			else if(pevent->category == SRV_TDL_CATEGORY_BIRTHDAY)
			{
				nYear = reminder_time.nYear;
                reminder_time.nYear = currTime.nYear;
				if(CompareTime(reminder_time, currTime, NULL) <= 0)
				{
                    pevent->alarm.first_launch.nYear = currTime.nYear + 1;
				}
				else
				{
                    pevent->alarm.first_launch.nYear = currTime.nYear;
				}
				// get next reminder time
				memset(&incTime, 0, sizeof(MYTIME));
		//		incTime.nMin = pevent->alarm.snooze_interval * pevent->alarm.snooze;
				IncrementTime(pevent->alarm.first_launch, incTime, &reminder_time);
				if(nYear != pevent->alarm.first_launch.nYear)
				{
			/*		srv_tdl_event_update(
						 pevent, 
						(*id_buffer)[i].source_id,
						(*id_buffer)[i].event_id); */
					funcptr = g_srv_tdl_event_source_table[(*id_buffer)[i].source_id].funcptr.event_update_funcptr;
                    ret = funcptr(pevent, (*id_buffer)[i].source_id, (*id_buffer)[i].event_id);
					srv_tdl_event_update_sns_reminder();
					goto END;
				}
			}
			
			// get the latest reminder
			if(alarm_launch.nYear == 0 ||(CompareTime(reminder_time, alarm_launch, NULL) < 0))
			{
			    memcpy(&alarm_launch, &reminder_time, sizeof(alarm_launch));
				temp_src_id = (*id_buffer)[i].source_id;
			    new_event_id = (*id_buffer)[i].event_id;
			}
		}
		// update sns reminder
		if(total_count != 0)
		{
		    ReadValue(NVRAM_TODO_SRV_SNS_REMINDER_ID_H, &id_h, DS_SHORT, &error);
		    ReadValue(NVRAM_TODO_SRV_SNS_REMINDER_ID_L, &id_l, DS_SHORT, &error);		
			last_event_id = id_h << 16 | id_l;
			if(last_event_id != 0xFFFFFFFF)
			{
			    cancel_success = srv_reminder_cancel(SRV_REMINDER_TYPE_SNS, last_event_id);
				MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_CANCEL_SNS_REMINDER, last_event_id, cancel_success);
			}

			reminder_ret = srv_reminder_set(SRV_REMINDER_TYPE_SNS, 
				                      &alarm_launch, 
				                      new_event_id);
			
			if(reminder_ret == SRV_REMINDER_RET_OK)
			{
				g_sns_reminder_id = new_event_id;
				id_h = (new_event_id >> 16) & 0xFFFF;
				id_l = new_event_id & 0xFFFF;
				sns_src = temp_src_id;
				WriteValue(NVRAM_TODO_SRV_SNS_REMINDER_ID_H, &id_h, DS_SHORT, &error);
			    WriteValue(NVRAM_TODO_SRV_SNS_REMINDER_ID_L, &id_l, DS_SHORT, &error);
				WriteValue(NVRAM_TODO_SRV_SNS_REMINDER_SOURCE, &sns_src, DS_BYTE, &error);
			}
			else
			{
				g_sns_reminder_id = 0xFFFFFFFF;
				id_h = 0xFFFF;
				id_l = 0xFFFF;
				sns_src = 0x00;
				WriteValue(NVRAM_TODO_SRV_SNS_REMINDER_ID_H, &id_h, DS_SHORT, &error);
			    WriteValue(NVRAM_TODO_SRV_SNS_REMINDER_ID_L, &id_l, DS_SHORT, &error);
				WriteValue(NVRAM_TODO_SRV_SNS_REMINDER_SOURCE, &sns_src, DS_BYTE, &error);
			}
		}
END:		
		OslMfree(pevent);
		srv_tdl_event_search_end(search_id);
		MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_SET_SNS_REMINDER, g_sns_reminder_id, reminder_ret);
        return g_sns_reminder_id;

	}

    MMI_FRM_INIT_EVENT(&op_evt, EVT_ID_SRV_TDL_EVENT_SEARCH);
    op_evt.job_id = search_id;
	op_evt.success = MMI_TRUE;
    op_evt.event_cnt = total_count;
    MMI_FRM_CB_EMIT_POST_EVENT(&op_evt);

	MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_SEARCH_CALLBACK_END, search_id, total_count);
	return ret;
}

#define GLOBAL_FUNCTION
/*****************************************************************************
 * FUNCTION
 *	srv_tdl_event_get
 * DESCRIPTION
 *	get the event info
 * PARAMETERS
 *	source_id:
 *    event_id:
 *    buffer:
 *    buffer_size:
 * RETURNS
 *	the result of operation
 * RETURN VALUES
 *	MMI_TRUE:   get event info sucess
 *    MMI_FALSE: event no found or error
 *****************************************************************************/ 
U32 srv_tdl_event_get(srv_tdl_event_struct *buffer, const U32 buffer_size, const srv_tdl_event_source_enum source_id, const U32 event_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												         */
	/*----------------------------------------------------------------*/
	srv_tdl_get_event_funcptr funcptr;
    srv_tdl_result_enum ret = SRV_TDL_RESULT_OK;
	/*----------------------------------------------------------------*/
	/* Code Body													         */
	/*----------------------------------------------------------------*/ 
	if(buffer == NULL)
	{
	    ret = SRV_TDL_RESULT_FAIL;
		goto END;
	}
	if(buffer_size < sizeof(srv_tdl_event_struct))
	{
		ret = SRV_TDL_RESULT_ADD_NOT_ENOUGH_MEMORY;
		goto END;
	}
	if(!g_srv_tdl_event_source_table[source_id].have_source)
	{
		ret = SRV_TDL_RESULT_UNSUPPORTED_OPERATION;
		goto END;
	}
	
	funcptr = g_srv_tdl_event_source_table[source_id].funcptr.event_get_funcptr;
	if(funcptr == NULL)
	{
		ret = SRV_TDL_RESULT_UNSUPPORTED_OPERATION;
		goto END;
	}
	ret = (srv_tdl_result_enum)funcptr(buffer, buffer_size,source_id, event_id);
	if(source_id != SRV_TDL_EVENT_SOURCE_LOCAL)
	{
	    if(ret)
			ret = SRV_TDL_RESULT_OK;
		else
			ret = SRV_TDL_RESULT_FAIL;
	}
	if(ret != SRV_TDL_RESULT_OK)
	{
	    goto END;
	}
	if(source_id != SRV_TDL_EVENT_SOURCE_LOCAL)
	{
		buffer->present = 1;
	}
    buffer->src_id = source_id;
	buffer->event_id = event_id;
END:	
	MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_EVENT_GET, source_id, event_id, ret);
	return ret;

}


/*****************************************************************************
 * FUNCTION
 *	srv_tdl_event_add
 * DESCRIPTION
 *	add event into event datebase
 * PARAMETERS
 *	source_id:
 *    event_id:
 *    buffer:
 *    buffer_size:
 * RETURNS
 *	the result of operation
 * RETURN VALUES
 *	MMI_TRUE:   support
 *    MMI_FALSE: no support
 *****************************************************************************/ 
U32 srv_tdl_event_add(const srv_tdl_event_struct *buffer, const srv_tdl_event_source_enum source_id,  U32* event_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												         */
	/*----------------------------------------------------------------*/
	srv_tdl_add_event_funcptr funcptr;
	srv_tdl_event_op_struct evt_op;
    srv_tdl_result_enum ret = SRV_TDL_RESULT_OK;

	/*----------------------------------------------------------------*/
	/* Code Body													         */
	/*----------------------------------------------------------------*/ 
	if(buffer == NULL)
	{
	    ret = SRV_TDL_RESULT_FAIL;
		goto END;
	}

	if(!g_srv_tdl_event_source_table[source_id].have_source)
	{
		ret = SRV_TDL_RESULT_UNSUPPORTED_OPERATION;
		goto END;
	}
	
	funcptr = g_srv_tdl_event_source_table[source_id].funcptr.event_add_funcptr;
	if(funcptr == NULL)
	{
		ret = SRV_TDL_RESULT_UNSUPPORTED_OPERATION;
		goto END;
	}
	*event_id = 0;
	ret = (srv_tdl_result_enum)funcptr(buffer, source_id, event_id);
	if(source_id != SRV_TDL_EVENT_SOURCE_LOCAL)
	{
	    if(ret)
			ret = SRV_TDL_RESULT_OK;
		else
			ret = SRV_TDL_RESULT_FAIL;
	}
	if (ret == SRV_TDL_RESULT_OK)
    {
        MMI_FRM_INIT_EVENT(&evt_op, EVT_ID_SRV_TDL_EVENT_OP);
        evt_op.op_type = SRV_TDL_OP_ADD;
        evt_op.source_id = source_id;
        evt_op.event_id = *event_id;
        MMI_FRM_CB_EMIT_EVENT(&evt_op);
    }
END:	
	MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_EVENT_ADD, source_id, *event_id, ret);
	return ret;
}


/*****************************************************************************
 * FUNCTION
 *	srv_tdl_event_update
 * DESCRIPTION
 *	update event info to SNS datebase
 * PARAMETERS
 *	source_id:
 *    event_id:
 *    buffer:
 *    buffer_size:
 * RETURNS
 *	the result of operation
 * RETURN VALUES
 *	MMI_TRUE:   support
 *    MMI_FALSE: no support
 *****************************************************************************/ 
U32 srv_tdl_event_update(const srv_tdl_event_struct *buffer, const srv_tdl_event_source_enum source_id, const U32 event_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												         */
	/*----------------------------------------------------------------*/
	srv_tdl_update_event_funcptr funcptr;
	srv_tdl_event_op_struct evt_op;
    srv_tdl_result_enum ret = SRV_TDL_RESULT_OK;

	/*----------------------------------------------------------------*/
	/* Code Body													         */
	/*----------------------------------------------------------------*/ 
	if(buffer == NULL)
	{
	    ret = SRV_TDL_RESULT_FAIL;
		goto END;
	}

	if(!g_srv_tdl_event_source_table[source_id].have_source)
	{
		ret = SRV_TDL_RESULT_UNSUPPORTED_OPERATION;
	    goto END;
	}
	
	funcptr = g_srv_tdl_event_source_table[source_id].funcptr.event_update_funcptr;
	if(funcptr == NULL)
	{
		ret = SRV_TDL_RESULT_UNSUPPORTED_OPERATION;
		goto END;	
	}
	ret = (srv_tdl_result_enum)funcptr(buffer, source_id, event_id);
	if(source_id != SRV_TDL_EVENT_SOURCE_LOCAL)
	{
	    if(ret)
			ret = SRV_TDL_RESULT_OK;
		else
			ret = SRV_TDL_RESULT_FAIL;
	}
	if(ret == SRV_TDL_RESULT_OK)
	{
	    MMI_FRM_INIT_EVENT(&evt_op, EVT_ID_SRV_TDL_EVENT_OP);
        evt_op.op_type = SRV_TDL_OP_UPDATE;
        evt_op.source_id = source_id;
        evt_op.event_id = event_id;
        MMI_FRM_CB_EMIT_EVENT(&evt_op);
	}

	//if SNS event, search reminder
#ifdef __MMI_SNS_CALENDAR__	
	if(source_id != SRV_TDL_EVENT_SOURCE_LOCAL)
	{
		srv_tdl_event_update_sns_reminder();
	}	
#endif	
END:	
	MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_EVENT_UPDATE, source_id, event_id, ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *	srv_tdl_event_delete
 * DESCRIPTION
 *	add event into event datebase
 * PARAMETERS
 *	source_id:
 *    event_id:
 *    buffer:
 *    buffer_size:
 * RETURNS
 *	the result of operation
 * RETURN VALUES
 *	MMI_TRUE:   support
 *    MMI_FALSE: no support
 *****************************************************************************/ 
U32 srv_tdl_event_delete(const srv_tdl_event_source_enum source_id, const U32 event_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												         */
	/*----------------------------------------------------------------*/
	srv_tdl_delete_event_funcptr funcptr;
    srv_tdl_result_enum ret = SRV_TDL_RESULT_OK;
	srv_tdl_event_op_struct evt_op;

	/*----------------------------------------------------------------*/
	/* Code Body													         */
	/*----------------------------------------------------------------*/ 

	if(!g_srv_tdl_event_source_table[source_id].have_source)
	{
		ret = SRV_TDL_RESULT_UNSUPPORTED_OPERATION;
		goto END;
	}
	
	funcptr = g_srv_tdl_event_source_table[source_id].funcptr.event_delete_funcptr;
	if(funcptr == NULL)
	{
		ret = SRV_TDL_RESULT_UNSUPPORTED_OPERATION;
		goto END;
	}
	ret = (srv_tdl_result_enum)funcptr(source_id, event_id);
	if(source_id != SRV_TDL_EVENT_SOURCE_LOCAL)
	{
	    if(ret)
			ret = SRV_TDL_RESULT_OK;
		else
			ret = SRV_TDL_RESULT_FAIL;
	}
	if(ret == SRV_TDL_RESULT_OK)
	{
        MMI_FRM_INIT_EVENT(&evt_op, EVT_ID_SRV_TDL_EVENT_OP);
        evt_op.op_type = SRV_TDL_OP_DELETE;
        evt_op.source_id = source_id;
        evt_op.event_id = event_id;
        MMI_FRM_CB_EMIT_EVENT(&evt_op);
	}
END:	
	MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_EVENT_DELETE, source_id, event_id, ret);
    return ret;

}


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
MMI_BOOL srv_tdl_has_source(srv_tdl_event_source_enum source_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												         */
	/*----------------------------------------------------------------*/
	MMI_BOOL ret;

	/*----------------------------------------------------------------*/
	/* Code Body													         */
	/*----------------------------------------------------------------*/  
	if(!g_srv_tdl_event_source_table[source_id].have_source)
	{
	    ret = MMI_FALSE;
	}
    else
	{
	    ret = MMI_TRUE;
	}
	MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_HAS_SOURCE, source_id, ret);
	return ret;
}


/*****************************************************************************
 * FUNCTION
 *	srv_tdl_get_source_count
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
U32 srv_tdl_get_source_count(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												         */
	/*----------------------------------------------------------------*/
    U32 i = 0;
    U32 cnt = 0;
	/*----------------------------------------------------------------*/
	/* Code Body													         */
	/*----------------------------------------------------------------*/
	for(i = 0; i < SRV_TDL_EVENT_SOURCE_TOTAL; i++)
	{
		if(g_srv_tdl_event_source_table[i].have_source)
		{
		    cnt++;
		}
	}
	MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_GET_SOURCE_COUNT, cnt);
    return cnt;
}


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
MMI_BOOL srv_tdl_set_source_state(MMI_BOOL alow_show, srv_tdl_event_source_enum source_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	MMI_BOOL ret = MMI_TRUE;
	srv_tdl_event_source_enum i;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if(source_id > SRV_TDL_EVENT_SOURCE_TOTAL)
	{
	    ret = MMI_FALSE;
		goto END;
	}
	if(source_id == SRV_TDL_EVENT_SOURCE_TOTAL)
	{
	    for(i = SRV_TDL_EVENT_SOURCE_LOCAL; i < SRV_TDL_EVENT_SOURCE_TOTAL; i++)
    	{
    	    g_srv_tdl_event_source_table[i].filter = alow_show;
    	}
		goto END;
	}
	if(g_srv_tdl_event_source_table[source_id].have_source == MMI_FALSE)
	{
	    ret = MMI_FALSE;
	}
	else
	{
	    g_srv_tdl_event_source_table[source_id].filter = alow_show;
	}
END:	
	MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_SET_SOURCE_STATE, source_id, alow_show, ret);
	return ret;
}



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
 *	MMI_FRUE:  allow show
 *    MMI_FALSE: not show the event or not has this source
 *****************************************************************************/ 
MMI_BOOL srv_tdl_get_source_state(srv_tdl_event_source_enum source_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												         */
	/*----------------------------------------------------------------*/
	MMI_BOOL ret = MMI_FALSE;

	/*----------------------------------------------------------------*/
	/* Code Body													         */
	/*----------------------------------------------------------------*/
	if(g_srv_tdl_event_source_table[source_id].have_source == MMI_TRUE)
	{
		ret = g_srv_tdl_event_source_table[source_id].filter;
	}
	MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_GET_SOURCE_STATE, source_id, ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *	srv_tdl_event_search_begin
 * DESCRIPTION
 *	search all the events whose source filter ON
 * PARAMETERS
 *	filter:
 *   sort_type: 
 * RETURNS
 *	search job id
 * RETURN VALUES
 *	>0 : valid job id
 *    =0: no event source
 *   < 0:   invalid job id
 *****************************************************************************/ 
S32 srv_tdl_event_search_begin(
                              const srv_tdl_search_filter_struct *filter,
							  const srv_tdl_event_sort_enum sort_type, 
							  srv_tdl_event_source_enum source_id)

{
	/*----------------------------------------------------------------*/
	/* Local Variables												         */
	/*----------------------------------------------------------------*/
    S32 job_id;
    U32 i = 0;
    S32 search_id = 0;
    MMI_BOOL has_source = MMI_FALSE;
	MMI_BOOL result = MMI_TRUE;
	/*----------------------------------------------------------------*/
	/* Code Body													         */
	/*----------------------------------------------------------------*/ 
	search_id = srv_tdl_event_get_available_search_id();
	if(search_id <= 0)
	{
		goto END;
	}
	srv_tdl_event_set_search_type(search_id, filter->type);
	if(source_id == SRV_TDL_EVENT_SOURCE_TOTAL)
	{
	    for(i = 0; i < SRV_TDL_EVENT_SOURCE_TOTAL; i++)
	    {
	        if(srv_tdl_has_source((srv_tdl_event_source_enum)i) && srv_tdl_get_source_state((srv_tdl_event_source_enum)i))
	        {
				job_id = srv_tdl_event_async_search_begin((srv_tdl_event_source_enum)i, filter, sort_type, srv_tdl_event_async_search_callback);
				if(job_id <= 0)
				{
				    continue;		
				}
				has_source = MMI_TRUE;
				result = srv_tdl_event_set_job_id(search_id, (srv_tdl_event_source_enum)i, job_id);
				ASSERT(result == MMI_TRUE);

				result = srv_tdl_event_set_source_search_status(search_id, (srv_tdl_event_source_enum)i, MMI_TRUE);
				ASSERT(result == MMI_TRUE);
				
				StartTimerEx(TIMER_ID_SRV_TDL_SEARCH_1+search_id-1, 5000, srv_tdl_event_search_timerout_handler, (void *)search_id);
	        }
	    }
	}
	else
	{
	    if(srv_tdl_has_source(source_id) && srv_tdl_get_source_state(source_id))
        {
			job_id = srv_tdl_event_async_search_begin(source_id, filter, sort_type, srv_tdl_event_async_search_callback);
			if(job_id <= 0)
			{
			    goto END;		
			}
			has_source = MMI_TRUE;
			result = srv_tdl_event_set_job_id(search_id, source_id, job_id);
			ASSERT(result == MMI_TRUE);

			result = srv_tdl_event_set_source_search_status(search_id, source_id, MMI_TRUE);
			ASSERT(result == MMI_TRUE);

			StartTimerEx(TIMER_ID_SRV_TDL_SEARCH_1+search_id-1, 5000, srv_tdl_event_search_timerout_handler, (void *)search_id);
        }
	}
END:	
    if(has_source == MMI_FALSE)
    {
		srv_tdl_event_search_end(search_id);
		search_id = 0;
    }
	MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_EVENT_SEARCH_BEGIN, source_id, filter->type, search_id);
	return search_id;
}


/*****************************************************************************
 * FUNCTION
 *	srv_tdl_event_search_get
 * DESCRIPTION
 *	get the events from the index'th, 
 * PARAMETERS
 *	job_id:    [IN]
 *   buffer:    [IN]
 *   buf_size: [IN]
 *   index:     [IN]
 * RETURNS
 *	the event number acullay returned
 * RETURN VALUES
 *	>=0 : the geted event number
 *   < 0:   error happen
 *****************************************************************************/ 
S32 srv_tdl_event_search_get(S32 search_id, void *buffer, U32 buf_size, U32 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												         */
	/*----------------------------------------------------------------*/
    srv_tdl_event_id_struct** event_buf;
    S32 event_cnt;
	S32 ret = 0;
	/*----------------------------------------------------------------*/
	/* Code Body													         */
	/*----------------------------------------------------------------*/
	ASSERT(buffer);
	event_buf = srv_tdl_event_get_all_event(search_id, &event_cnt);
	if(event_cnt <= 0 || *event_buf == NULL)
	{
	    ret = 0;
		goto END;
	}
	if((event_cnt - index) * sizeof(srv_tdl_event_id_struct) <= buf_size)
	{
	    memcpy(buffer, (*event_buf + index * sizeof(srv_tdl_event_id_struct)), (event_cnt - index) * sizeof(srv_tdl_event_id_struct));
	    ret = event_cnt - index;
	}
	else
	{
		memcpy(buffer, (*event_buf + index * sizeof(srv_tdl_event_id_struct)), buf_size);
        ret = buf_size/sizeof(srv_tdl_event_id_struct);
	}
END:
	MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_EVENT_SEARCH_GET, search_id, ret);
	return ret;	
}


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
 *   < 0:   FAILED
 *****************************************************************************/ 
S32 srv_tdl_event_search_end(S32 search_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												         */
	/*----------------------------------------------------------------*/
    U32 i;
    S32 job_id = 0;
	/*----------------------------------------------------------------*/
	/* Code Body													         */
	/*----------------------------------------------------------------*/  
	MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_EVENT_SEARCH_END, search_id);
	
	for(i = 0; i < SRV_TDL_EVENT_SOURCE_TOTAL; i++)
    {
        srv_tdl_event_get_job_id(search_id, (srv_tdl_event_source_enum)i, &job_id);
		if(job_id > 0)
		{
		    srv_tdl_event_async_search_end((srv_tdl_event_source_enum)i, job_id);
		}
    }	
	
	srv_tdl_event_reset_search_context(search_id);
    return search_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_get_sns_reminder
 * DESCRIPTION
 *  event_id: [IN]
 *  source_id: [OUT]
 * PARAMETERS
 *  void        
 * RETURNS
 *  S32
 *****************************************************************************/
MMI_BOOL srv_tdl_get_sns_reminder_source(U32 reminder_id, srv_tdl_event_source_enum *source_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
	S16 error;
	U16 id_h, id_l;
	U32 event_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ReadValue(NVRAM_TODO_SRV_SNS_REMINDER_SOURCE, &g_sns_reminder_source, DS_BYTE, &error);
	ReadValue(NVRAM_TODO_SRV_SNS_REMINDER_ID_H, &id_h, DS_SHORT, &error);
	ReadValue(NVRAM_TODO_SRV_SNS_REMINDER_ID_L, &id_l, DS_SHORT, &error);
	*source_id = (srv_tdl_event_source_enum)g_sns_reminder_source;
	event_id = id_h;
	event_id = (event_id << 16) + id_l;
	if(event_id != reminder_id)
	{
		// error happen
		//ASSERT(0);
		ret = MMI_FALSE;
	}
	MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_GET_REMINDER_EVENT_ID, *source_id,event_id, ret);
    return ret;
}

mmi_ret srv_tdl_sns_reminder_notify_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	srv_reminder_evt_struct *remdr_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	if (evt->evt_id != EVT_ID_SRV_REMINDER_NOTIFY)
    {
        return MMI_RET_OK;
    }
	remdr_evt = (srv_reminder_evt_struct *)evt;
	switch(remdr_evt->notify)
	{		
	    case SRV_REMINDER_NOTIFY_INIT:
		case SRV_REMINDER_NOTIFY_REINIT:
#ifdef __MMI_SNS_CALENDAR__			
			srv_tdl_event_update_sns_reminder();	
#endif
			break;
			
		default:
			break;
	}
	return MMI_RET_OK;
}


#define LOCAL_EVENT_ASYNC_SEARCH
typedef struct
{
    MMI_EVT_PARAM_HEADER
    S32 source_id;
	S32 job_id;    // job_ id
    S32 event_cnt; // total event count, error happen if (event_cnt < 0)
} srv_tdl_local_search_callback_struct;

static U32 local_event[TDL_MAX_EVENT_SEARCH_COUNT+1];
static srv_tdl_event_search_get_struct * async_search_buffer[TDL_MAX_EVENT_SEARCH_COUNT+1];
static S32 srv_tdl_local_event_async_search_begin(
	                                    const srv_tdl_event_source_enum source_id,
                                        const srv_tdl_search_filter_struct *filter,
										const srv_tdl_event_sort_enum sort_type,
										const event_async_callback callback)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												         */
	/*----------------------------------------------------------------*/
	srv_tdl_event_short_struct *pevent = NULL;
	U32 total = 0, i = 0;
	static U32 index = 0;
    U32 job_id = 0;
    srv_tdl_local_search_callback_struct op_evt;
	/*----------------------------------------------------------------*/
	/* Code Body													         */
	/*----------------------------------------------------------------*/ 
	job_id = (index % TDL_MAX_EVENT_SEARCH_COUNT) + 1;
    index ++;
	async_search_buffer[job_id] = (srv_tdl_event_search_get_struct *)OslMalloc(NUM_OF_CAL * sizeof(srv_tdl_event_search_get_struct));
    for (i = 0; i < NUM_OF_CAL; i++)
    {
        pevent = &g_srv_event_list[i];
        if (MMI_TRUE == pevent->present)
        {
            if(srv_tdl_search_default_check((void*)pevent, SRV_TDL_VCAL_EVENT, *filter))
	        {
				async_search_buffer[job_id][total].event_id = i;
				memcpy(&async_search_buffer[job_id][total].begin_time, &pevent->start_time, sizeof(MYTIME));
	            total++;
	        }
        }
    }
    local_event[job_id] = total;

    MMI_FRM_INIT_EVENT(&op_evt, EVT_ID_SRV_TDL_LOCAL_EVENT_SEARCH);
    op_evt.source_id = SRV_TDL_EVENT_SOURCE_LOCAL;
    op_evt.job_id = job_id;
    op_evt.event_cnt = total;
    MMI_FRM_CB_EMIT_POST_EVENT(&op_evt);
    
	return job_id;
}


void srv_tdl_local_event_async_search_proc(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tdl_local_search_callback_struct *p_event = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_event = (srv_tdl_local_search_callback_struct*)event;
    srv_tdl_event_async_search_callback((srv_tdl_event_source_enum)p_event->source_id, p_event->job_id, p_event->event_cnt);
}


S32 srv_tdl_local_event_async_search(kal_int32          job_id,
									void         *buf,       // Working buffer should be prepared by todo service.
	                                const kal_uint32   buf_size,   // working buffer size. 
	                                const kal_int32    index)      // event index from which to get
{
	/*----------------------------------------------------------------*/
	/* Local Variables												         */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													         */
	/*----------------------------------------------------------------*/ 
    if(buf_size >= (sizeof(srv_tdl_event_search_get_struct) * local_event[job_id]))
    {
	    memcpy(buf, &async_search_buffer[job_id][index], sizeof(srv_tdl_event_search_get_struct) * local_event[job_id]);
	    return local_event[job_id];
    }
	else
	{
		 memcpy(buf, &async_search_buffer[job_id][index], buf_size);
		 return buf_size/sizeof(srv_tdl_event_search_get_struct);
	}
}



S32 srv_tdl_local_event_async_search_end(kal_int32 job_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												         */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													         */
	/*----------------------------------------------------------------*/ 
    if(async_search_buffer[job_id])
    {
        OslMfree(async_search_buffer[job_id]);
		async_search_buffer[job_id] = NULL;
		local_event[job_id] = 0;
    }
    return job_id;
}


S32 srv_tdl_search_local_event(srv_tdl_event_task_struct *buffer,
										const U32  buffer_size,
										const srv_tdl_search_filter_struct filter,
										const srv_tdl_event_sort_enum sort_type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												         */
	/*----------------------------------------------------------------*/
	srv_tdl_event_short_struct *pevent = NULL;
	U32 total = 0, i = 0;

	/*----------------------------------------------------------------*/
	/* Code Body													         */
	/*----------------------------------------------------------------*/ 
    for (i = 0; i < NUM_OF_CAL; i++)
    {
        pevent = &g_srv_event_list[i];
        if (MMI_TRUE == pevent->present)
        {
            if(srv_tdl_search_default_check((void*)pevent, SRV_TDL_VCAL_EVENT, filter))
	        {
				if(buffer)
				{
				    buffer[total].index = i;
                    buffer[total].type = SRV_TDL_VCAL_EVENT;
				}
	            total++;
	        }
        }
    }
	return total;
}


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
void srv_tdl_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tdl_event_struct *pevent;
    srv_tdl_task_struct *ptask;
    U8 event_count = 0;
    U8 todo_count = 0;
    U8 index = 0;
    S16 error;
#ifdef __MMI_TDL_NITZ_SUPPORT__
    applib_time_struct utc_time;
    applib_time_struct rtc_time;
#endif /* __MMI_TDL_NITZ_SUPPORT__ */

	srv_tdl_event_funcptr_table event_funcptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__MMI_CALENDAR_EVENT__) && !defined(__COSMOS_MMI_PACKAGE__)) || defined(__COSMOS_MMI_PACKAGE__)
    pevent = OslMalloc(sizeof(srv_tdl_event_struct));
    for (index = 0; index < NUM_OF_CAL; index++)
    {
        ReadRecord(
                NVRAM_EF_TDL_EVENT_LID,
                (U16)(index + 1),
                pevent,
                sizeof(srv_tdl_event_struct),
                &error);
        
        if (pevent->present != 1)
        {
            continue;
        }
        
#ifdef __MMI_TDL_NITZ_SUPPORT__
        /* convert utc to local time */
        memcpy(&utc_time, &pevent->start_time, sizeof(MYTIME));
        applib_dt_utc_to_rtc_with_default_tz(&utc_time, &rtc_time);
        memcpy(&pevent->start_time, &rtc_time, sizeof(MYTIME));

        memcpy(&utc_time, &pevent->end_time, sizeof(MYTIME));
        applib_dt_utc_to_rtc_with_default_tz(&utc_time, &rtc_time);
        memcpy(&pevent->end_time, &rtc_time, sizeof(MYTIME));
#endif /* __MMI_TDL_NITZ_SUPPORT__ */
                
        memcpy(&g_srv_event_list[index], pevent, sizeof(srv_tdl_event_short_struct));
        event_count++;
    }
	OslMfree(pevent);
	
	event_funcptr.event_async_search_begin_funcptr = srv_tdl_local_event_async_search_begin;
	event_funcptr.event_async_search_funcptr = (srv_tdl_async_event_search_funcptr)srv_tdl_local_event_async_search;
	event_funcptr.event_async_search_end_funcptr = srv_tdl_local_event_async_search_end;

	event_funcptr.event_search_funcptr = NULL;
	event_funcptr.event_get_funcptr = (srv_tdl_get_event_funcptr)srv_tdl_local_event_get;
	event_funcptr.event_update_funcptr = (srv_tdl_update_event_funcptr)srv_tdl_local_event_update;
	event_funcptr.event_add_funcptr = (srv_tdl_add_event_funcptr)srv_tdl_local_event_add;
	event_funcptr.event_delete_funcptr = (srv_tdl_delete_event_funcptr)srv_tdl_local_event_delete;
	srv_tdl_add_source(SRV_TDL_EVENT_SOURCE_LOCAL, event_funcptr);
#endif


#if (defined(__MMI_TODOLIST__) && !defined(__COSMOS_MMI_PACKAGE__)) || defined(__COSMOS_MMI_PACKAGE__)
    ptask = OslMalloc(sizeof(srv_tdl_task_struct));    
    for (index = 0; index < NUM_OF_TASK; index++)
    {
        ReadRecord(
                NVRAM_EF_TDL_TASK_LID,
                (U16)(index + 1),
                ptask,
                NVRAM_EF_TDL_TASK_SIZE,
                &error);
    
        if (ptask->present != 1)
        {
            continue;
        }
        
#ifdef __MMI_TDL_NITZ_SUPPORT__
         /* convert utc to local time */
        memcpy(&utc_time, &ptask->due_time, sizeof(MYTIME));
        applib_dt_utc_to_rtc_with_default_tz(&utc_time, &rtc_time);
        memcpy(&ptask->due_time, &rtc_time, sizeof(MYTIME));
        if (ptask->status == SRV_TDL_STATUS_DONE)
        {
            memcpy(&utc_time, &ptask->complete_time, sizeof(applib_time_struct));
            applib_dt_utc_to_rtc_with_default_tz(&utc_time, &rtc_time);
            memcpy(&ptask->complete_time, &rtc_time, sizeof(MYTIME));
        }
#endif /* __MMI_TDL_NITZ_SUPPORT__ */
        
        memcpy(&g_srv_todo_list[index], ptask, sizeof(srv_tdl_task_short_struct));
        todo_count++;
    }
    OslMfree(ptask);
#endif

    MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_INI, event_count, todo_count);


}
                
#define SNS_END

/*****************************************************************************
 * FUNCTION
 *  srv_tdl_add
 * DESCRIPTION
 *  Add a task/event.
 * PARAMETERS
 *  data :      [IN] The task or event to add.
 *  buff_size : [IN] The size of data buffer.
 *  vcal_type : [IN] Identify the type, event or task.
 *  index :     [OUT] The store index of the task/event added.
 * RETURNS
 *  The error code of the add operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Add success.
 *  SRV_TDL_RESULT_FAIL : Add failed with unknown reason.
 *  SRV_TDL_RESULT_ADD_NOT_ENOUGH_MEMORY : The memory full, can not add success.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter invalid.
 *****************************************************************************/   
U16 srv_tdl_add(
                const void *data, 
                srv_tdl_vcal_enum vcal_type, 
                U16 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = SRV_TDL_RESULT_OK;
    srv_tdl_op_evt_struct op_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_ADD_ENTRY, data, vcal_type, index);
    if (!data || !index || vcal_type > SRV_TDL_VCAL_TASK)
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        goto SRV_TDL_ERROR_CLEAN;
    }
    
    if (vcal_type == SRV_TDL_VCAL_EVENT)
    {
        result = srv_tdl_local_event_add((srv_tdl_event_struct*)data,SRV_TDL_EVENT_SOURCE_LOCAL, index);
    }
    else
    {
        result = srv_tdl_task_add((srv_tdl_task_struct*)data, index);
    }

    if (result == SRV_TDL_RESULT_OK)
    {
        MMI_FRM_INIT_EVENT(&op_evt, EVT_ID_SRV_TDL_OP);
        op_evt.vcal_type = vcal_type;
        op_evt.op_type = SRV_TDL_OP_ADD;
        op_evt.store_idx = *index;
        MMI_FRM_CB_EMIT_EVENT(&op_evt);
    }
    
SRV_TDL_ERROR_CLEAN:
    MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_ADD_LEAVE, result);
    return result;
}                


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_delete
 * DESCRIPTION
 *  Delete a task/event.
 * PARAMETERS
 *  index :     [IN] The store index of the task/event to be deleted.
 *  vcal_type : [IN] Identify the type, event or task.
 * RETURNS
 *  The error code of the deletion operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Delete success.
 *  SRV_TDL_RESULT_FAIL : Delete failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_INDEX : The index is invalid.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/   
U16 srv_tdl_delete(const U16 index, const srv_tdl_vcal_enum vcal_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = SRV_TDL_RESULT_OK;    
    srv_tdl_op_evt_struct op_evt;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_DELETE_ENTRY, index, vcal_type);
    if (vcal_type > SRV_TDL_VCAL_TASK ||
        (vcal_type == SRV_TDL_VCAL_EVENT && index >= NUM_OF_CAL) ||
        (vcal_type == SRV_TDL_VCAL_TASK && index >= NUM_OF_TASK))
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        goto SRV_TDL_ERROR_CLEAN;
    }

    if (vcal_type == SRV_TDL_VCAL_EVENT)
    {
        result = srv_tdl_local_event_delete(SRV_TDL_EVENT_SOURCE_LOCAL, index);
    }
    else
    {
        result = srv_tdl_task_delete(index);
    }
    
    if (result == SRV_TDL_RESULT_OK)
    {
        MMI_FRM_INIT_EVENT(&op_evt, EVT_ID_SRV_TDL_OP);
        op_evt.vcal_type = vcal_type;
        op_evt.op_type = SRV_TDL_OP_DELETE;
        op_evt.store_idx = index;
        MMI_FRM_CB_EMIT_EVENT(&op_evt);
    }
    
SRV_TDL_ERROR_CLEAN:
    MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_DELETE_LEAVE, result);        
    return result;
}  



/*****************************************************************************
 * FUNCTION
 *  srv_tdl_update
 * DESCRIPTION
 *  Update a task/event.
 * PARAMETERS
 *  data :      [IN] The task or event to update to. data can only be srv_tdl_event_struct or srv_tdl_task_struct
 *  buff_size : [IN] The size of data buffer.
 *  vcal_type : [IN] Identify the type, event or task.
 *  index :     [IN] The store index of the task/event to update.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Update success.
 *  SRV_TDL_RESULT_FAIL : Update failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_INDEX : The index is invalid.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/ 
U16 srv_tdl_update(
                const void *data, 
                const srv_tdl_vcal_enum vcal_type,  
                const U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = SRV_TDL_RESULT_OK;
    srv_tdl_op_evt_struct op_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_UPDATE_ENTRY, data, vcal_type, index);

    if (!data || vcal_type > SRV_TDL_VCAL_TASK)
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        goto SRV_TDL_ERROR_CLEAN;
    }

    if ((vcal_type == SRV_TDL_VCAL_EVENT && index >= NUM_OF_CAL) ||
        (vcal_type == SRV_TDL_VCAL_TASK && index >= NUM_OF_TASK))
    {
        result = SRV_TDL_RESULT_INVALID_INDEX;
        goto SRV_TDL_ERROR_CLEAN;
    }
    
    if (vcal_type == SRV_TDL_VCAL_EVENT)
    {
        result = srv_tdl_local_event_update((srv_tdl_event_struct*)data, SRV_TDL_EVENT_SOURCE_LOCAL, index);
    }
    else
    {
        result = srv_tdl_task_update((srv_tdl_task_struct*)data, index);
    }
    
    if (result == SRV_TDL_RESULT_OK)
    {
        MMI_FRM_INIT_EVENT(&op_evt, EVT_ID_SRV_TDL_OP);
        op_evt.vcal_type = vcal_type;
        op_evt.op_type = SRV_TDL_OP_UPDATE;
        op_evt.store_idx = index;
        MMI_FRM_CB_EMIT_EVENT(&op_evt);
    }
    
SRV_TDL_ERROR_CLEAN:
    MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_UPDATE_LEAVE, result);
    return result;
}                  


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_get_cache
 * DESCRIPTION
 *  Get a task/event from cache buffer in order to improve the performance, 
 *  but the event or task is not complete for saving memory;
 * PARAMETERS
 *  buff :      [OUT] The pointer to point the cached task/event, please cast the 
 *      void pointer to srv_tdl_event_short_struct or srv_tdl_task_short_struct by your 
 *      specfied type before you use it;
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
U16 srv_tdl_get_cache(
                void** buff, 
                const U16 buff_size, 
                const srv_tdl_vcal_enum vcal_type, 
                const U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = SRV_TDL_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE4(MMI_TDL_SRV_GET_ENTRY_FROM_CACHE, buff, buff_size, vcal_type, index);

    if (vcal_type > SRV_TDL_VCAL_TASK)
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        goto SRV_TDL_ERROR_CLEAN;
    }

    if ((vcal_type == SRV_TDL_VCAL_EVENT && buff_size != sizeof(srv_tdl_event_short_struct)) ||
        (vcal_type == SRV_TDL_VCAL_TASK && buff_size != sizeof(srv_tdl_task_short_struct)))
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        goto SRV_TDL_ERROR_CLEAN;
    }

    if ((vcal_type == SRV_TDL_VCAL_EVENT && index >= NUM_OF_CAL) ||
        (vcal_type == SRV_TDL_VCAL_TASK && index >= NUM_OF_TASK))
    {
        result = SRV_TDL_RESULT_INVALID_INDEX;
        goto SRV_TDL_ERROR_CLEAN;
    }

    if (SRV_TDL_VCAL_EVENT == vcal_type)
    {
        if (0 == g_srv_event_list[index].present)
        {
            result = SRV_TDL_RESULT_FAIL;
        }
        *buff = &g_srv_event_list[index];
    }
    else
    {
        if (0 == g_srv_todo_list[index].present)
        {
            result = SRV_TDL_RESULT_FAIL;
        }
        *buff = &g_srv_todo_list[index];
    }

    
SRV_TDL_ERROR_CLEAN:
    MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_GET_CACHE_LEAVE, result);
    return result;
}


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
 *  index :     [IN] The store index of the task/event to get.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Get the data success.
 *  SRV_TDL_RESULT_FAIL : Get failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_INDEX : The index is invalid.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/ 
U16 srv_tdl_get(
                void *buff, 
                const U16 buff_size, 
                const srv_tdl_vcal_enum vcal_type, 
                const U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = SRV_TDL_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE4(MMI_TDL_SRV_GET_ENTRY, buff, buff_size, vcal_type, index);

    if (!buff || vcal_type > SRV_TDL_VCAL_TASK)
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        goto SRV_TDL_ERROR_CLEAN;
    }

    if ((vcal_type == SRV_TDL_VCAL_EVENT && buff_size != sizeof(srv_tdl_event_struct)) ||
        (vcal_type == SRV_TDL_VCAL_TASK && buff_size != sizeof(srv_tdl_task_struct)))
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        goto SRV_TDL_ERROR_CLEAN;
    }

    if ((vcal_type == SRV_TDL_VCAL_EVENT && index >= NUM_OF_CAL) ||
        (vcal_type == SRV_TDL_VCAL_TASK && index >= NUM_OF_TASK))
    {
        result = SRV_TDL_RESULT_INVALID_INDEX;
        goto SRV_TDL_ERROR_CLEAN;
    }

    if (vcal_type == SRV_TDL_VCAL_EVENT)
    {
        result = srv_tdl_local_event_get(buff, sizeof(srv_tdl_event_struct),SRV_TDL_EVENT_SOURCE_LOCAL, index);
    }
    else
    {
        result = srv_tdl_task_get(buff, sizeof(srv_tdl_task_struct), index);
    }
    
SRV_TDL_ERROR_CLEAN:    
    MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_GET_LEAVE, result);
    return result;
}  


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_get_all_index
 * DESCRIPTION
 *  Get all the event/task/both list.
 *  If list buffer is NULL, it will output the total count of event/task.
 * PARAMETERS
 *  list :      [IN/OUT] The list to store event/task, if NULL, will output
        total count only;
 *  length :    [IN] The size of list, it should be NUM_OF_CAL or NUM_OF_TASK;
 *  vcal_type : [IN] Identify the type, event or task.
 *  count :     [OUT] The store index of the task/event added.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Get the data successfully.
 *  SRV_TDL_RESULT_FAIL : Getting operation failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/ 
U16 srv_tdl_get_all_index(
                 srv_tdl_event_task_struct *list, 
                 const U16 length, 
                 const srv_tdl_vcal_enum vcal_type, 
                 U16 *count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = SRV_TDL_RESULT_OK;
    U16 total, total1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    if (!count)
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        goto SRV_TDL_ERROR_CLEAN;
    }

    if (vcal_type == SRV_TDL_VCAL_EVENT)
    {
        if (list && length < NUM_OF_CAL)
        {
            result = SRV_TDL_RESULT_INVALID_PARAMETER;
            goto SRV_TDL_ERROR_CLEAN;
        }
 
        result = srv_tdl_event_get_all_index(list, NUM_OF_CAL, &total);
        if (result != SRV_TDL_RESULT_OK)
        {
            goto SRV_TDL_ERROR_CLEAN;
        }
        *count = total;
    }
    else if (vcal_type == SRV_TDL_VCAL_TASK)
    {
        if (list && length < NUM_OF_TASK)
        {
            result = SRV_TDL_RESULT_INVALID_PARAMETER;
            goto SRV_TDL_ERROR_CLEAN;
        }
        result = srv_tdl_task_get_all_index(list, NUM_OF_TASK, &total);

        if (result != SRV_TDL_RESULT_OK)
        {
            goto SRV_TDL_ERROR_CLEAN;
        }
        *count = total;
    }
    else
    {
        if (list && length < (NUM_OF_CAL + NUM_OF_TASK))
        {
            result = SRV_TDL_RESULT_INVALID_PARAMETER;
            goto SRV_TDL_ERROR_CLEAN;
        }
        result = srv_tdl_task_get_all_index(
                                        list, 
                                        NUM_OF_CAL + NUM_OF_TASK, 
                                        &total);
        if (result != SRV_TDL_RESULT_OK)
        {
            goto SRV_TDL_ERROR_CLEAN;
        }
        if (list == NULL)
            
            result = srv_tdl_event_get_all_index(
                                        NULL, 
                                        NUM_OF_CAL + NUM_OF_TASK, 
                                        &total1);
        else
        result = srv_tdl_event_get_all_index(
                                        list + total, 
                                        NUM_OF_CAL + NUM_OF_TASK, 
                                        &total1);

        if (result != SRV_TDL_RESULT_OK)
        {
            goto SRV_TDL_ERROR_CLEAN;
        }

        *count = total + total1;
    }

SRV_TDL_ERROR_CLEAN:
    return result;
}                   


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_get_free
 * DESCRIPTION
 *  Get the free number of task/event.
 * PARAMETERS
 *  count :     [OUT] The free number to output.
 *  vcal_type : [IN] Identify the type, event or task.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Get the count successfully.
 *  SRV_TDL_RESULT_FAIL : Getting operation failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/ 
U16 srv_tdl_get_free(U16 *count, const srv_tdl_vcal_enum vcal_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = SRV_TDL_RESULT_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!count || vcal_type > SRV_TDL_VCAL_TASK)
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        goto SRV_TDL_ERROR_CLEAN;
    }
    
    if (vcal_type == SRV_TDL_VCAL_EVENT)
    {
        result = srv_tdl_event_get_free(count);
    }
    else
    {
        result = srv_tdl_task_get_free(count);
    }

SRV_TDL_ERROR_CLEAN:
    MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_GET_ALL_FREE_LEAVE, count, vcal_type);
    return result;
}  



/*****************************************************************************
 * FUNCTION
 *  srv_tdl_get_max
 * DESCRIPTION
 *  Get the max number of task/event.
 * PARAMETERS
 *  count :     [OUT] The max number to output.
 *  vcal_type : [IN] Identify the type, event or task.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Get the count successfully.
 *  SRV_TDL_RESULT_FAIL : Getting operation failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/ 
U16 srv_tdl_get_max(U16 *count, const srv_tdl_vcal_enum vcal_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = SRV_TDL_RESULT_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_GET_MAX_EVTRY, count, vcal_type);

    if (!count || vcal_type > SRV_TDL_VCAL_TASK)
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        goto SRV_TDL_ERROR_CLEAN;
    }
    
    if (vcal_type == SRV_TDL_VCAL_EVENT)
    {
        *count = NUM_OF_CAL;
    }
    else
    {
        *count = NUM_OF_TASK;
    }
    
SRV_TDL_ERROR_CLEAN:
    MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_GET_MAX_LEAVE, result);
    return result;    
}  


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
MMI_BOOL srv_tdl_is_full(const srv_tdl_vcal_enum vcal_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    MMI_BOOL result = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_IS_FULL_ENTRY, vcal_type);

    if (vcal_type > SRV_TDL_VCAL_TASK)
    {
        return MMI_TRUE;
    }

    if (vcal_type == SRV_TDL_VCAL_EVENT)
    {
        i = srv_tdl_event_get_new_index();
        if (i >= NUM_OF_CAL)
        {
            result = MMI_TRUE;
        }
    }
    else
    {
        i = srv_tdl_task_get_new_index();
        if (i >= NUM_OF_TASK)
        {
            result = MMI_TRUE;
        }
    }

    MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_IS_FULL_LEAVE, result);
    return result;    
}  



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
MMI_BOOL srv_tdl_is_empty(const srv_tdl_vcal_enum vcal_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;
    MMI_BOOL result = MMI_FALSE;
    U16 error_code;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_IS_EMPTY_ENTRY, vcal_type);

    if (vcal_type > SRV_TDL_VCAL_TASK)
    {
        return result;
    }

    if (vcal_type == SRV_TDL_VCAL_EVENT)
    {
        error_code = srv_tdl_event_get_all_index(NULL, 0, &count);        
    }
    else
    {
        error_code = srv_tdl_task_get_all_index(NULL, 0, &count);;    
    }

    if (error_code == SRV_TDL_RESULT_OK && count == 0)
    {
        result = MMI_TRUE;
    }

    MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_IS_EMPTY_LEAVE, result);
    return result;
}  


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_get_new_index
 * DESCRIPTION
 *  Get the new index.
 * PARAMETERS
 *  vcal_type : [IN] Identify the type, event or task.
 * RETURNS
 *  The new index.
 * RETURN VALUES
 *****************************************************************************/ 
U16 srv_tdl_get_new_index(const srv_tdl_vcal_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (type > SRV_TDL_VCAL_TASK)
    {
        return NUM_OF_TDL;
    }
    
    if (type == SRV_TDL_VCAL_EVENT)
    {
        return srv_tdl_event_get_new_index();
    }
    else
    {
        return srv_tdl_task_get_new_index();    
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  srv_tdl_search
 * DESCRIPTION
 *  Search the event/task list according to the search condition.
 * PARAMETERS
 *  list :      [OUT] The searched list.
 *  length :    [IN] The size of list, it should be NUM_OF_CAL or NUM_OF_TASK;
 *  vcal_type : [IN] Identify the type, event or task.
 *  search :    [IN] The search condition.
 *      For monthly/weekly search, the date_time is the standard to 
 *      identify the month and week.
 *      For location/subject search, the string is the key word.
 *      For duration search, the duration array stores the begin
 *      date time and the end date time to search event/task.
 *      If search event, the start time of the event should be later 
 *      than the duration[0], and the end time of the event should be 
 *      earlier than the duration[1].
 *      If search task, then the due time must in the duration.
 *  count : [OUT] The searched count.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Searched the event/task/both list successfully.
 *  SRV_TDL_RESULT_FAIL : Searched the list failed with unknown reasons.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *  SRV_TDL_RESULT_UNSUPPORTED_OPERATION : Unsupported search condition.
 *****************************************************************************/ 
U16 srv_tdl_search_ext(
                srv_tdl_event_task_struct *list, 
                const U16 length, 
                const srv_tdl_vcal_enum vcal_type,
                const srv_tdl_search_filter_struct search_filter, 
                U16 *count,
                const srv_tdl_external_search_check_funcptr funcptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tdl_event_short_struct *pevent = NULL;
    srv_tdl_task_short_struct *ptask = NULL;
    U16 i;
    U32 total = 0;
    U16 result = SRV_TDL_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_SEARCH_EXT_ENTRY, list, length, count);

    if ((vcal_type == SRV_TDL_VCAL_EVENT && list && length < NUM_OF_CAL) ||
        (vcal_type == SRV_TDL_VCAL_TASK && list && length < NUM_OF_TASK) ||
        (vcal_type == SRV_TDL_VCAL_BOTH && list && length < NUM_OF_TDL))
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        goto SRV_ERROR_CLEAN;
    }        
    
    if (vcal_type == SRV_TDL_VCAL_EVENT)
    {
        for (i = 0; i < NUM_OF_CAL; i++)
        {
            pevent = &g_srv_event_list[i];
            if (MMI_TRUE == pevent->present &&
                MMI_TRUE == funcptr((void*)pevent, SRV_TDL_VCAL_EVENT, search_filter))
            {
				if (list)
				{
					list[total].index = i;
                    list[total].type = SRV_TDL_VCAL_EVENT;
				}
                total++;
            }
        }
    }
    else if (vcal_type == SRV_TDL_VCAL_TASK)
    {
        for (i = 0; i < NUM_OF_TASK; i++)
        {
            ptask = &g_srv_todo_list[i];
            if (MMI_TRUE == ptask->present &&
                MMI_TRUE == funcptr((void*)ptask, SRV_TDL_VCAL_TASK, search_filter))
            {
				if (list)
				{
					list[total].index = i;
                    list[total].type = SRV_TDL_VCAL_TASK;
				}
                total++;
            }
        }
    
    }
    else
    {       
        for (i = 0; i < NUM_OF_CAL; i++)
        {
            pevent = &g_srv_event_list[i];
            if (MMI_TRUE == pevent->present &&
                MMI_TRUE == funcptr((void*)pevent, SRV_TDL_VCAL_EVENT, search_filter))
            {
				if (list)
				{
					list[total].index = i;
                    list[total].type = SRV_TDL_VCAL_EVENT;
				}
                total++;
            }
        }
        
        for (i = 0; i < NUM_OF_TASK; i++)
        {
            ptask = &g_srv_todo_list[i];
            if (MMI_TRUE == ptask->present &&
                MMI_TRUE == funcptr((void*)ptask, SRV_TDL_VCAL_TASK, search_filter))
            {
				if (list)
				{
					list[total].index = i;
                    list[total].type = SRV_TDL_VCAL_TASK;
				}
                total++;
            }
        }
    }

    *count = total;
    
SRV_ERROR_CLEAN:
    MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_SEARCH_EXT_LEAVE, result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_search
 * DESCRIPTION
 *  Search the event/task list according to the search condition.
 * PARAMETERS
 *  list :      [OUT] The searched list.
 *  length :    [IN] The size of list, it should be NUM_OF_CAL or NUM_OF_TASK;
 *  vcal_type : [IN] Identify the type, event or task.
 *  search :    [IN] The search condition.
 *      For monthly/weekly search, the date_time is the standard to 
 *      identify the month and week.
 *      For location/subject search, the string is the key word.
 *      For duration search, the duration array stores the begin
 *      date time and the end date time to search event/task.
 *      If search event, the start time of the event should be later 
 *      than the duration[0], and the end time of the event should be 
 *      earlier than the duration[1].
 *      If search task, then the due time must in the duration.
 *  count : [OUT] The searched count.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Searched the event/task/both list successfully.
 *  SRV_TDL_RESULT_FAIL : Searched the list failed with unknown reasons.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *  SRV_TDL_RESULT_UNSUPPORTED_OPERATION : Unsupported search condition.
 *****************************************************************************/ 
U16 srv_tdl_search(
                srv_tdl_event_task_struct *list, 
                const U16 length, 
                const srv_tdl_vcal_enum vcal_type,
                const srv_tdl_search_filter_struct search, 
                U16 *count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = SRV_TDL_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_SEARCH_ENTRY, list, length, count);
    result = srv_tdl_search_ext(
                    list, 
                    length, 
                    vcal_type, 
                    search, 
                    count, 
                    srv_tdl_search_default_check);
    MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_SEARCH_LEAVE, result);
    return result;
}                  


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_search_default_check
 * DESCRIPTION
 *  Check if the event is in the search list.
 * PARAMETERS
 *  data :   [IN] The data to be checked.
 *  filter : [IN] The check criterin.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Sort successfully.
 *  MMI_FALSE : Sort failed with unknow reasons.
 *****************************************************************************/ 
MMI_BOOL srv_tdl_search_default_check(
                                 const void *data, 
                                 const srv_tdl_vcal_enum vcal_type,
                                 const srv_tdl_search_filter_struct search_filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_SEARCH_DEFAULT_CHECK_ENTRY, vcal_type, search_filter.type);
    if (vcal_type >= SRV_TDL_VCAL_BOTH)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }
    
    switch (search_filter.type)
    {
        case SRV_TDL_SEARCH_TYPE_TIME:
            if (vcal_type == SRV_TDL_VCAL_EVENT)
            {
                result = srv_tdl_event_search_check_time(
                                            (srv_tdl_event_short_struct*)data, 
                                            search_filter.u.date_time);
            }
            else
            {
                result = srv_tdl_task_search_check_time(
                                            (srv_tdl_task_short_struct*)data, 
                                            search_filter.u.date_time);
            }
            break;
            
        case SRV_TDL_SEARCH_TYPE_DAILY:
            if (vcal_type == SRV_TDL_VCAL_EVENT)
            {
                 result = srv_tdl_event_search_check_daily(
                                            (srv_tdl_event_short_struct*)data, 
                                            search_filter.u.date_time);
            }
            else
            {
                result = srv_tdl_task_search_check_daily(
                                            (srv_tdl_task_short_struct*)data, 
                                            search_filter.u.date_time);
            }
            break;
            
        case SRV_TDL_SEARCH_TYPE_WEEKLY:
            if (vcal_type == SRV_TDL_VCAL_EVENT)
            {
                result = srv_tdl_event_search_check_weekly(
                                            (srv_tdl_event_short_struct*)data, 
                                            search_filter.u.weekly_search);
            }
            else
            {
                result = srv_tdl_task_search_check_weekly(
                                            (srv_tdl_task_short_struct*)data, 
                                            search_filter.u.weekly_search);
            }
            break;
            
        case SRV_TDL_SEARCH_TYPE_MONTHLY:
            if (vcal_type == SRV_TDL_VCAL_EVENT)
            {
                result = srv_tdl_event_search_check_monthly(
                                            (srv_tdl_event_short_struct*)data, 
                                            search_filter.u.date_time);
            }
            else
            {
                result = srv_tdl_task_search_check_monthly(
                                            (srv_tdl_task_short_struct*)data, 
                                            search_filter.u.date_time);
            }
            break;     
            
        case SRV_TDL_SEARCH_TYPE_SUBJECT:
            if (vcal_type == SRV_TDL_VCAL_EVENT)
            {
                result = srv_tdl_event_search_check_subject(
                                            (srv_tdl_event_short_struct*)data, 
                                            search_filter.u.str_buf);
            }
            else
            {
                result = srv_tdl_task_search_check_subject(
                                            (srv_tdl_task_short_struct*)data, 
                                            search_filter.u.str_buf);
            }
            break;     
            
        case SRV_TDL_SEARCH_TYPE_LOCATION:
            if (vcal_type == SRV_TDL_VCAL_EVENT)
            {
                result = srv_tdl_event_search_check_location(
                                            (srv_tdl_event_short_struct*)data, 
                                            search_filter.u.str_buf);
            }
            else
            {
                result = MMI_FALSE;
            }
            break;     

        case SRV_TDL_SEARCH_TYPE_CATEGORY:
            if (vcal_type == SRV_TDL_VCAL_EVENT)
            {
                result = srv_tdl_event_search_check_category(
                                            (srv_tdl_event_short_struct*)data, 
                                            search_filter.u.category);
            }
            else
            {
                result = MMI_FALSE;
            }
            break;

        case SRV_TDL_SEARCH_TYPE_BEFORE:
            if (vcal_type == SRV_TDL_VCAL_EVENT)
            {
                result = srv_tdl_event_search_check_before(
                                            (srv_tdl_event_short_struct*)data, 
                                            search_filter.u.date_time);
            }
            else
            {
                result = srv_tdl_task_search_check_before(
                                            (srv_tdl_task_short_struct*)data, 
                                            search_filter.u.date_time);
            }
            break;

        case SRV_TDL_SEARCH_TYPE_AFTER:
            if (vcal_type == SRV_TDL_VCAL_EVENT)
            {
                result = srv_tdl_event_search_check_after(
                                            (srv_tdl_event_short_struct*)data, 
                                            search_filter.u.date_time);
            }
            else
            {

            }
            break;
			
       case SRV_TDL_SEARCH_TYPE_INCOMING:
            if (vcal_type == SRV_TDL_VCAL_EVENT)
            {
                result = srv_tdl_event_search_check_incoming(
                                            (srv_tdl_event_short_struct*)data, 
                                            search_filter.u.date_time);
            }
            break; 
			
		case SRV_TDL_SEARCH_TYPE_PREVIOUS:
            if (vcal_type == SRV_TDL_VCAL_EVENT)
            {
                result = srv_tdl_event_search_check_previous(
                                            (srv_tdl_event_short_struct*)data, 
                                            search_filter.u.date_time);
            }
            break; 
			
		case SRV_TDL_SEARCH_TYPE_ALL:
			if (vcal_type == SRV_TDL_VCAL_EVENT)
			{
				result = srv_tdl_event_search_check_all(
											(srv_tdl_event_short_struct*)data, 
											search_filter.u.date_time);
			}
			else
			{
		
			}
			break;


        case SRV_TDL_SEARCH_TYPE_STATUS:
            if (vcal_type == SRV_TDL_VCAL_EVENT)
            {
                result = MMI_FALSE;
            }
            else
            {
                result = srv_tdl_task_search_check_status(
                                            (srv_tdl_task_short_struct*)data, 
                                            search_filter.u.status);
            }
            break;
            
        case SRV_TDL_SEARCH_TYPE_DURATION:
            if (vcal_type == SRV_TDL_VCAL_EVENT)
            {
                result = srv_tdl_event_search_check_duration(
                                            (srv_tdl_event_short_struct*)data, 
                                            &search_filter.u.duration[0],
                                            &search_filter.u.duration[1]);
            }
            else
            {
                result = srv_tdl_task_search_check_duration(
                                            (srv_tdl_task_short_struct*)data, 
                                            &search_filter.u.duration[0],
                                            &search_filter.u.duration[1]);
            }
            break;  
			
        case SRV_TDL_SEARCH_TYPE_ALARM:
            break;
			
        default:
            break;        
    }

SRV_TDL_ERROR_CLEAN:
    MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_SEARCH_DEFAULT_CHECK_LEAVE, result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_sort_ext
 * DESCRIPTION
 *  Sort the list according to giving sort type.
 * PARAMETERS
 *  list :      [IN/OUT] The list to be sorted.
 *  length :    [IN] The size of list, it should be NUM_OF_CAL or NUM_OF_TASK;
 *  sort_type : [IN] The sort type.
 *  funcptr :   [IN] The function to compare two data by custom code.
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
                const U16 length,
                const srv_tdl_sort_type_enum sort_type, 
                const srv_tdl_external_sort_compare_funcptr funcptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = SRV_TDL_RESULT_OK;
    srv_tdl_compare_result_enum error_code;
    srv_tdl_event_task_struct temp_data;
    U16 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_SORT_EXT_ENTRY, length, sort_type);
    for (i = 0; i < length; i++)
    {
        for (j = length - 1; j > i; j--)
        {
            error_code = funcptr(
                           list[j].index, 
                           list[j].type, 
                           list[j - 1].index, 
                           list[j - 1].type, 
                           sort_type);

            if (error_code >= SRV_TDL_COMPARE_END_OF_ENUM)
            {
                result = SRV_TDL_RESULT_UNSUPPORTED_OPERATION;
                goto SRV_TDL_ERROR_RETURN;
            }
        	if (error_code < 0)
            {
                memcpy(&temp_data, &list[j], sizeof(srv_tdl_event_task_struct));
                memcpy(&list[j], &list[j - 1], sizeof(srv_tdl_event_task_struct));
                memcpy(&list[j - 1], &temp_data, sizeof(srv_tdl_event_task_struct));                
            }
        }
    }
    
SRV_TDL_ERROR_RETURN:
    MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_SORT_EXT_LEAVE, result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_sort
 * DESCRIPTION
 *  Sort the list according to giving sort type.
 * PARAMETERS
 *  list :      [IN/OUT] The list to be sorted.
 *  length :    [IN] The size of list, it should be NUM_OF_CAL or NUM_OF_TASK;
 *  vcal_type : [IN] Identify the type, event or task.
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
U16 srv_tdl_sort(
                srv_tdl_event_task_struct *list, 
                const U16 length,
                const srv_tdl_sort_type_enum sort_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = SRV_TDL_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_tdl_sort_ext(list, length, sort_type, srv_tdl_sort_default_compare);
    return result;
}                  


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_get_time_in_today
 * DESCRIPTION
 *  Get a new today time in today;
 *  if the event start_time starts from today, the new_time = start_time;
 *  if start_time starts from the time before today, the new_time = start_time of today;
 *  This api is used to sort today events in some day
 * PARAMETERS
 *  new_time :  [IN/OUT] input buffer for original time and output buffer for new time
 *  type :      [IN] The event of this time repeat type
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/ 
void srv_tdl_get_time_in_today(MYTIME *new_time, srv_tdl_repeat_rule_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME today;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetDateTime(&today);
    
    if (type == SRV_TDL_RULE_ONCE)
    {
        /* the event start from today */
        if (new_time->nYear == today.nYear && new_time->nMonth == today.nMonth &&  new_time->nDay == today.nDay)
        {
            /* do noting */
        }
        /* the event start from duration before today */
        else
        {
            new_time->nHour = 0;
            new_time->nMin = 0;
            new_time->nSec= 0;
        }
    }
    
    new_time->nYear = today.nYear;
    new_time->nMonth = today.nMonth;
    new_time->nDay = today.nDay;
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_sort_default_compare
 * DESCRIPTION
 *  Compare two data.
 * PARAMETERS
 *  data1     : [IN] The first data to be checked.
 *  data2     : [IN] The first data to be checked.
 *  sort_type : [IN] The check criterion.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  +1 : data1 > data2.
 *  0  : data1 == data2.
 *  -1 : data1 < data2.
 *****************************************************************************/ 
static srv_tdl_compare_result_enum srv_tdl_sort_default_compare(
                                          const U16 index1,
                                          const U16 type1, 
                                          const U16 index2, 
                                          const U16 type2, 
                                          const srv_tdl_sort_type_enum sort_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tdl_compare_result_enum result = SRV_TDL_COMPARE_END_OF_ENUM;
    srv_tdl_event_short_struct *pevent1 = NULL, *pevent2 = NULL;
    srv_tdl_task_short_struct *ptask1 = NULL, *ptask2 = NULL;
    MYTIME time1, time2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type1 > SRV_TDL_VCAL_TASK || type2 > SRV_TDL_VCAL_TASK)
    {
        goto SRV_ERROR_RETURN;
    }
    
    if (type1 == SRV_TDL_VCAL_EVENT)
    {
        pevent1 = &g_srv_event_list[index1];
    }
    else
    {
        ptask1 = &g_srv_todo_list[index1];
    }

    if (type2 == SRV_TDL_VCAL_EVENT)
    {
        pevent2 = &g_srv_event_list[index2];
    }
    else
    {
        ptask2 = &g_srv_todo_list[index2];
    }

    switch (sort_type)
    {
        case SRV_TDL_SORT_TYPE_ENTRY_TIME:
            if (type1 == SRV_TDL_VCAL_EVENT)
            {
                memcpy(&time1, &pevent1->start_time, sizeof(MYTIME));
            }
            else
            {
                memcpy(&time1, &ptask1->due_time, sizeof(MYTIME));
            }

            if (type2 == SRV_TDL_VCAL_EVENT)
            {
                memcpy(&time2, &pevent2->start_time, sizeof(MYTIME));
            }
            else
            {  
                memcpy(&time2, &ptask2->due_time, sizeof(MYTIME));
            }
            result = (srv_tdl_compare_result_enum)CompareTime(time1, time2, NULL);
            break;

        case SRV_TDL_SORT_TYPE_CREATE_TIME:
            if (type1 == SRV_TDL_VCAL_EVENT)
            {
                memcpy(&time1, &pevent1->created_time, sizeof(MYTIME));
            }
            else
            {
                memcpy(&time1, &ptask1->created_time, sizeof(MYTIME));
            }

            if (type2 == SRV_TDL_VCAL_EVENT)
            {
                memcpy(&time2, &pevent2->created_time, sizeof(MYTIME));
            }
            else
            {  
                memcpy(&time2, &ptask2->created_time, sizeof(MYTIME));
            }
            result = (srv_tdl_compare_result_enum)CompareTime(time1, time2, NULL);
            break;

        case SRV_TDL_SORT_TYPE_PRIORITY:
            if (type1 == SRV_TDL_VCAL_EVENT || type2 == SRV_TDL_VCAL_EVENT)
            {
                goto SRV_ERROR_RETURN;
            }

            result = (srv_tdl_compare_result_enum)srv_tdl_task_compare_priority(index1, index2);
            break;

        case SRV_TDL_SORT_TYPE_TODAY_TIME:
            /* this sort type only used to today events */
            if (type1 == SRV_TDL_VCAL_EVENT)
            {
                memcpy(&time1, &pevent1->start_time, sizeof(MYTIME));
                srv_tdl_get_time_in_today(&time1, (srv_tdl_repeat_rule_enum)pevent1->repeat.rule);
            }
            else
            {
                memcpy(&time1, &ptask1->due_time, sizeof(MYTIME));
                srv_tdl_get_time_in_today(&time1, (srv_tdl_repeat_rule_enum)ptask1->repeat.rule);
            }

            if (type2 == SRV_TDL_VCAL_EVENT)
            {
                memcpy(&time2, &pevent2->start_time, sizeof(MYTIME));
                srv_tdl_get_time_in_today(&time2, (srv_tdl_repeat_rule_enum)pevent2->repeat.rule);
            }
            else
            {  
                memcpy(&time2, &ptask2->due_time, sizeof(MYTIME));
                srv_tdl_get_time_in_today(&time2, (srv_tdl_repeat_rule_enum)ptask2->repeat.rule);
            }

            result = (srv_tdl_compare_result_enum)CompareTime(time1, time2, NULL);
            
            break;

       default:
           break;
    }
SRV_ERROR_RETURN:
    return result;
}                                


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_add_event
 * DESCRIPTION
 *  Add an event.
 * PARAMETERS
 *  data :      [IN] The task or event to add.
 *  index :     [OUT] The store index of the event added.
 * RETURNS
 *  The error code of the add operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Add success.
 *  SRV_TDL_RESULT_FAIL : Add failed with unknown reason.
 *  SRV_TDL_RESULT_ADD_NOT_ENOUGH_MEMORY : The memory full, can not add success.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter invalid.
 *****************************************************************************/  
static U16 srv_tdl_local_event_add(
                const srv_tdl_event_struct *data, 
                const srv_tdl_event_source_enum source_id,
                U16 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    S16 error;
    U16 result = SRV_TDL_RESULT_OK;    
    srv_tdl_event_struct *pevent = NULL;
#ifdef __MMI_TDL_NITZ_SUPPORT__
    applib_time_struct utc_time;
    applib_time_struct rtc_time;
#endif /* __MMI_TDL_NITZ_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!data || !index)
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        goto SRV_TDL_ERROR_CLEAN;
    }
    i = srv_tdl_event_get_new_index();

    if (i >= NUM_OF_CAL)
    {
        result = SRV_TDL_RESULT_ADD_NOT_ENOUGH_MEMORY;
        goto SRV_TDL_ERROR_CLEAN;
    }

    *index = i;
    pevent = OslMalloc(sizeof(srv_tdl_event_struct));
    memcpy(pevent, data, sizeof(srv_tdl_event_struct));
    pevent->present = 1;
    pevent->event_id = i;
    pevent->src_id = SRV_TDL_EVENT_SOURCE_LOCAL;
    memcpy(
        &g_srv_event_list[*index], 
        pevent, 
        sizeof(srv_tdl_event_short_struct));       
    
#ifdef __MMI_TDL_NITZ_SUPPORT__
    memcpy(&rtc_time, &pevent->start_time, sizeof(MYTIME));
    applib_dt_rtc_to_utc_with_default_tz(&rtc_time, &utc_time);
    memcpy(&pevent->start_time, &utc_time, sizeof(MYTIME));

    memcpy(&rtc_time, &pevent->end_time, sizeof(MYTIME));
    applib_dt_rtc_to_utc_with_default_tz(&rtc_time, &utc_time);
    memcpy(&pevent->end_time, &utc_time, sizeof(MYTIME));
#endif /* __MMI_TDL_NITZ_SUPPORT__ */

    WriteRecord(
        NVRAM_EF_TDL_EVENT_LID,
        (U16)(i + 1), 
        (void*)pevent,
        NVRAM_EF_TDL_EVENT_SIZE,
        &error);
            
    OslMfree(pevent);
    
SRV_TDL_ERROR_CLEAN:
 //   MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_EVENT_ADD, result, *index);        
    return result;
}                


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_delete
 * DESCRIPTION
 *  Delete an event.
 * PARAMETERS
 *  index : [IN] The store index of the task/event to be deleted.
 * RETURNS
 *  The error code of the deletion operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Delete success.
 *  SRV_TDL_RESULT_FAIL : Delete failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_INDEX : The index is invalid.
 *****************************************************************************/   
static U16 srv_tdl_local_event_delete(const srv_tdl_event_source_enum source_id, const U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tdl_event_struct *event = NULL;
    S16 error;
    U16 result = SRV_TDL_RESULT_OK;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= NUM_OF_CAL)
    {
        result = SRV_TDL_RESULT_INVALID_INDEX;
        goto SRV_TDL_ERROR_CLEAN;
    }

    event = OslMalloc(sizeof(srv_tdl_event_struct));
    memset(event, 0, sizeof(srv_tdl_event_struct));

    WriteRecord(
        NVRAM_EF_TDL_EVENT_LID,
        (U16)(index + 1),
        event,
        NVRAM_EF_TDL_EVENT_SIZE,
        &error);
    memset(&g_srv_event_list[index], 0, sizeof(srv_tdl_event_short_struct));
    
    OslMfree(event);
    
SRV_TDL_ERROR_CLEAN:
    return result;
}  


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_update
 * DESCRIPTION
 *  Update an event.
 * PARAMETERS
 *  data :      [IN] The event to update to.
 *  index :     [IN] The store index of the event to update.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Update success.
 *  SRV_TDL_RESULT_FAIL : Update failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_INDEX : The index is invalid.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/ 
static U16 srv_tdl_local_event_update(
                    const srv_tdl_event_struct *data, 
                    const srv_tdl_event_source_enum source_id,
                    const U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = SRV_TDL_RESULT_OK;
    srv_tdl_event_struct *pevent = NULL;    
    S16 error;
#ifdef __MMI_TDL_NITZ_SUPPORT__
    applib_time_struct utc_time;
    applib_time_struct rtc_time;
#endif /* __MMI_TDL_NITZ_SUPPORT__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= NUM_OF_CAL)
    {
        result = SRV_TDL_RESULT_INVALID_INDEX;
        goto SRV_TDL_ERROR_CLEAN;        
    }
    
    pevent = OslMalloc(sizeof(srv_tdl_event_struct));
    memcpy(pevent, data, sizeof(srv_tdl_event_struct));
    pevent->present = 1;
    memcpy(
        &g_srv_event_list[index], 
        pevent, 
        sizeof(srv_tdl_event_short_struct));

#ifdef __MMI_TDL_NITZ_SUPPORT__
    memcpy(&rtc_time, &pevent->start_time, sizeof(MYTIME));
    applib_dt_rtc_to_utc_with_default_tz(&rtc_time, &utc_time);
    memcpy(&pevent->start_time, &utc_time, sizeof(MYTIME));

    memcpy(&rtc_time, &pevent->end_time, sizeof(MYTIME));
    applib_dt_rtc_to_utc_with_default_tz(&rtc_time, &utc_time);
    memcpy(&pevent->end_time, &utc_time, sizeof(MYTIME));
#endif /* __MMI_TDL_NITZ_SUPPORT__ */
   
    WriteRecord(
        NVRAM_EF_TDL_EVENT_LID,
        (U16)(index + 1),
        (void*)pevent,
        NVRAM_EF_TDL_EVENT_SIZE,
        &error);
    
    OslMfree(pevent);
    
SRV_TDL_ERROR_CLEAN:
    return result;
}                    


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_get
 * DESCRIPTION
 *  Get a task/event.
 * PARAMETERS
 *  buff :      [OUT] The buffer to store the task or event got.
 *  buff_size : [IN] The size of the output buffer.
 *  index :     [IN] The store index of the task/event to get.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Get the data success.
 *  SRV_TDL_RESULT_FAIL : Get failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_INDEX : The index is invalid.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/ 
static U16 srv_tdl_local_event_get(
                srv_tdl_event_struct *buff, 
                const U16 buff_size, 
                const srv_tdl_event_source_enum source_id,
                const U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = SRV_TDL_RESULT_OK;
    S16 error;    
#ifdef __MMI_TDL_NITZ_SUPPORT__
    applib_time_struct utc_time;
    applib_time_struct rtc_time;
#endif /* __MMI_TDL_NITZ_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (index > NUM_OF_CAL)
    {
        result = SRV_TDL_RESULT_INVALID_INDEX;
        goto SRV_TDL_ERROR_CLEAN;        
    }
    
    if (!buff || buff_size != sizeof(srv_tdl_event_struct))
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        goto SRV_TDL_ERROR_CLEAN;
    }

    ReadRecord(
            NVRAM_EF_TDL_EVENT_LID,
            (U16)(index + 1),
            buff,
            sizeof(srv_tdl_event_struct),
            &error);

    if (buff->present != 1)
    {
        result = SRV_TDL_RESULT_INVALID_INDEX;
        goto SRV_TDL_ERROR_CLEAN;
    }
    
#ifdef __MMI_TDL_NITZ_SUPPORT__
    memcpy(&utc_time, &buff->start_time, sizeof(MYTIME));
    applib_dt_utc_to_rtc_with_default_tz(&utc_time, &rtc_time);
    memcpy(&buff->start_time, &rtc_time, sizeof(MYTIME));

    /* end time */
    memcpy(&utc_time, &buff->end_time, sizeof(MYTIME));
    applib_dt_utc_to_rtc_with_default_tz(&utc_time, &rtc_time);
    memcpy(&buff->end_time, &rtc_time, sizeof(MYTIME));
#endif /* __MMI_TDL_NITZ_SUPPORT__ */
    
SRV_TDL_ERROR_CLEAN:
    return result;    
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_get_all_index
 * DESCRIPTION
 *  Get all the event/task/both list.
 *  If list buffer is NULL, it will output the total count of event/task.
 * PARAMETERS
 *  list :      [IN/OUT] The list to store event/task, if NULL, will output
        total count only.
 *  length :    [IN] The size of list.
 *  count :     [OUT] The store index of the task/event added.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Get the data successfully.
 *  SRV_TDL_RESULT_FAIL : Getting operation failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/ 
static U16 srv_tdl_event_get_all_index(
                                 srv_tdl_event_task_struct *list, 
                                 const U16 length, 
                                 U16 *count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = SRV_TDL_RESULT_OK;
    U16 i;
    U16 total = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (!count || (list && length < NUM_OF_CAL))
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        goto SRV_TDL_ERROR_CLEAN;
    }
    
    for (i = 0; i < NUM_OF_CAL; i++)
    {
        if (g_srv_event_list[i].present)
        {
            if (list)
            {
                list[total].index = i;
                list[total].type = SRV_TDL_VCAL_EVENT;
            }
            total++;
        }       
    }

    *count = total;
    
SRV_TDL_ERROR_CLEAN:
    MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_EVENT_GET_ALL_INDEX, result, total);
    return result;    
}                 


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_get_free
 * DESCRIPTION
 *  Get the free number of task/event.
 * PARAMETERS
 *  count :     [OUT] The free number to output.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Get the count successfully.
 *  SRV_TDL_RESULT_FAIL : Getting operation failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/ 
static U16 srv_tdl_event_get_free(U16 *count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 total = 0;
    U16 i;
    U16 result = SRV_TDL_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (!count)
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        goto SRV_TDL_ERROR_CLEAN;
    }
   
    for (i = 0; i < NUM_OF_CAL; i++)
    {
        if (!g_srv_event_list[i].present)
        {
            total++;
        }       
    }

    *count = total;

SRV_TDL_ERROR_CLEAN:
    MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_EVENT_GET_FREE, result, total);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_search_check_daily
 * DESCRIPTION
 *  Search the daily event list.
 * PARAMETERS
 *  pevent :[IN] The event to be checked.
 *  date :  [IN] The search condition.
 *          The start time of the events in the searched list should be 
 *      earlier than 23:59 of this date and end time should be later than
 *      00:00 of the date.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/ 
MMI_BOOL srv_tdl_event_search_check_daily(
                const srv_tdl_event_short_struct *pevent, 
                const MYTIME date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    MYTIME date_start;
    MYTIME date_end;
    U8 day_index;
    U32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_EVENT_CHECK_DAILY_DATE, date.nYear, date.nMonth, date.nDay);
    if (date.nYear == 0 || date.nMonth == 0 || date.nDay == 0)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }

    memcpy(&date_start, &date, sizeof(MYTIME));
    date_start.nHour = 0;
    date_start.nMin = 0;
    date_start.nSec = 0;

    memcpy(&date_end, &date, sizeof(MYTIME));
    date_end.nHour = 23;
    date_end.nMin = 59;
    date_end.nSec = 59;    
    date_start.DayIndex = date_start.DayIndex = DOW(date.nYear, date.nMonth, date.nDay);
	
    /* event presents and start time before current date 23:59 */
    if (pevent->present && 
        CompareTime(pevent->start_time, date_end, NULL) <= 0)
    {
        switch (pevent->repeat.rule)
        {
            case SRV_TDL_RULE_ONCE:
                /* event's end time should later than current date 00:00 */
                if (CompareTime(date_start, pevent->end_time, NULL) <= 0)
                {
                    result = MMI_TRUE;
                }
                break;
                
            case SRV_TDL_RULE_DAILY:
                result = MMI_TRUE; 
                break;
                
            case SRV_TDL_RULE_WEEKLY:
				if(pevent->start_time.nDay == pevent->end_time.nDay)  // only one day
				{
					if(pevent->start_time.DayIndex == date.DayIndex)
					{
						result = MMI_TRUE;
					}
					return result;
				}
				for(i = pevent->start_time.DayIndex, j = 0; j < 7; j++ )  // more than one day
                {
					if(i == date.DayIndex)
					{
                        result = MMI_TRUE;
						break;
					}
					i++;
					i = i % 7;
					if(i == pevent->end_time.DayIndex)
					{
						if(i == date.DayIndex)
						{
							result = MMI_TRUE;
						}
						break;
					}						
                }
                break;

            case SRV_TDL_RULE_DAYS:
                /* Need to add expiry time checking in the future. */
                day_index = DOW(date.nYear, date.nMonth, date.nDay);
                for (i = 0; i < SRV_TDL_MAX_DAYS_PER_WEEK; i++)
                {
                    if ((pevent->repeat.dows & g_srv_clndr_weekday_index[i]) && 
                        (i == day_index))
                    {
                        result = MMI_TRUE;
                        break;
                    }
                }
                break;
                
            case SRV_TDL_RULE_MONTHLY:
                if(pevent->start_time.nMonth == pevent->end_time.nMonth)
				{
					for(i = pevent->start_time.nDay; i <= pevent->end_time.nDay; i++)
	                {
						if(i == date.nDay)
						{
	                        result = MMI_TRUE;
							break;
						}
	                }

				}
				else
				{
					if((pevent->start_time.nMonth == date.nMonth && pevent->start_time.nDay <= date.nDay)||
					   (pevent->end_time.nMonth == date.nMonth && pevent->end_time.nDay >= date.nDay))
					{
						result = MMI_TRUE;
					}
				}
                break;
                
            case SRV_TDL_RULE_YEARLY:
				if(pevent->start_time.nYear == pevent->end_time.nYear)
				{
					date_start.nYear = date_end.nYear = pevent->start_time.nYear;
					if ((CompareTime(date_end, pevent->start_time, 0) < DT_TIME_EQUAL)||
						(CompareTime(date_start, pevent->end_time, 0) > DT_TIME_EQUAL))
					{
						result = MMI_FALSE;
					}
					else
					{
					    result = MMI_TRUE;
					}
				}
				else
				{
					if(date.nMonth > pevent->start_time.nMonth || date.nMonth < pevent->end_time.nMonth)
					{
						 result = MMI_TRUE;
					}
					else if((pevent->start_time.nMonth == date.nMonth && pevent->start_time.nDay <= date.nDay)||
					   (pevent->end_time.nMonth == date.nMonth && pevent->end_time.nDay >= date.nDay))
					{
						result = MMI_TRUE;
					}
				}
                break;            
                
            default:
                break;
        }
    }   
    
SRV_TDL_ERROR_CLEAN:
    return result;    
}                  


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_search_check_weekly
 * DESCRIPTION
 *  Search the weekly event list.
 * PARAMETERS
 *  pevent : [IN] The event to be checked.
 *  weekly_search : [IN] The search condition.
 *              The start time of the events in the searched list should be 
 *         earlier than 23:59 end of the week and end time shoud be later
 *         than 00:00 start time of the week.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/ 
MMI_BOOL srv_tdl_event_search_check_weekly(
                const srv_tdl_event_short_struct *pevent, 
                const srv_tdl_search_weely_struct weekly_search)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    MYTIME curr_week_begin;
    MYTIME next_week_begin;
    MYTIME inc_time;
    U16 day_index;
    S16 date_temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE3(
        MMI_TDL_SRV_EVENT_CHECK_WEEKLY_DATE, 
        weekly_search.date_time.nYear, 
        weekly_search.date_time.nMonth, 
        weekly_search.date_time.nDay);
    
    if (!pevent ||
        weekly_search.date_time.nYear == 0 || 
        weekly_search.date_time.nMonth == 0 || 
        weekly_search.date_time.nDay == 0)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }

    srv_tdl_cal_week_get_first_date(
        &weekly_search.date_time, 
        &curr_week_begin, 
        weekly_search.start_day_of_week);

    memset(&inc_time, 0, sizeof(MYTIME));
    inc_time.nDay = SRV_TDL_MAX_DAYS_PER_WEEK;
    
    applib_dt_increase_time(
        (applib_time_struct*)&curr_week_begin,
        (applib_time_struct*)&inc_time,
        (applib_time_struct*)&next_week_begin);
        
    /* event presents and start time before the beginning of the next week. */
    if (pevent->present && CompareTime(pevent->start_time, next_week_begin, NULL) < 0)
    {
        switch (pevent->repeat.rule)
        {
            case SRV_TDL_RULE_ONCE:
                /* Event's end time should later than current week's beginning 00:00 */
                if (CompareTime(
                        curr_week_begin, 
                        pevent->end_time, 
                        NULL) <= 0)
                {
                    result = MMI_TRUE;
                }
                break;
                
            case SRV_TDL_RULE_DAILY:
                /* Need to add expiry time checking in the future. */
                result = MMI_TRUE; 
                break;
                
            case SRV_TDL_RULE_WEEKLY:
                /* Need to add expiry time checking in the future. */
                result = MMI_TRUE;
                break;

            case SRV_TDL_RULE_DAYS:
                /* Need to add expiry time checking in the future. */
                result = MMI_TRUE; 
                break;
                
            case SRV_TDL_RULE_MONTHLY:
                /* Need to add expiry time checking in the future. */
                for (day_index = 1; 
                     day_index <= SRV_TDL_MAX_DAYS_PER_WEEK; 
                     day_index++)
                {
                    date_temp = next_week_begin.nDay - day_index;
                    if (date_temp > 0 && 
                        date_temp == pevent->start_time.nDay)
                    {   
                        result = MMI_TRUE;
                        break;
                    }
                    else if (date_temp <= 0)
                    {
                        date_temp += applib_dt_last_day_of_mon(
                                            curr_week_begin.nMonth, 
                                            curr_week_begin.nYear);
                                            
                        if (date_temp == pevent->start_time.nDay)
                        {
                            result = MMI_TRUE;
                            break;
                        }                                    
                    }
                }
                break;
                
            case SRV_TDL_RULE_YEARLY:
                /* Need to add expiry time checking in the future. */
                for (day_index = 1; 
                     day_index <= SRV_TDL_MAX_DAYS_PER_WEEK; 
                     day_index++)
                {
                    date_temp = next_week_begin.nDay - day_index;
                    if (date_temp > 0 && 
                        date_temp == pevent->start_time.nDay &&
                        next_week_begin.nMonth == pevent->start_time.nMonth)
                    {   
                        result = MMI_TRUE;
                        break;
                    }
                    else if (date_temp <= 0)
                    {
                        date_temp += applib_dt_last_day_of_mon(
                                            curr_week_begin.nMonth, 
                                            curr_week_begin.nYear);
                                            
                        if (date_temp == pevent->start_time.nDay &&
                            curr_week_begin.nMonth == pevent->start_time.nMonth)
                        {
                            result = MMI_TRUE;
                            break;
                        }                                    
                    }
                }
                break;

            default:
                break;
        }
}   
    
SRV_TDL_ERROR_CLEAN:
    return result;    
}                  


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
MMI_BOOL srv_tdl_event_search_check_monthly(
                const srv_tdl_event_short_struct *pevent, 
                const MYTIME date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    MYTIME curr_month_begin;
    MYTIME next_month_begin;
    MYTIME inc_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_EVENT_CHECK_MONTHLY_DATE, date.nYear, date.nMonth, date.nDay);
    if (!pevent ||
        date.nYear == 0 || 
        date.nMonth == 0 || 
        date.nDay == 0)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }

    memset(&inc_time, 0, sizeof(MYTIME));
    memcpy(&curr_month_begin, &date, sizeof(MYTIME));
    curr_month_begin.nDay = 1;
    curr_month_begin.nHour = 0;
    curr_month_begin.nMin = 0;
    curr_month_begin.nSec = 0;
    
    inc_time.nMonth = 1;
    
    applib_dt_increase_time(
        (applib_time_struct*)&curr_month_begin,
        (applib_time_struct*)&inc_time,
        (applib_time_struct*)&next_month_begin);
        
    /* event presents and start time before the beginning of the next week. */
    if (pevent->present && 
        CompareTime(pevent->start_time, next_month_begin, NULL) < 0)
    {
        switch (pevent->repeat.rule)
        {
            case SRV_TDL_RULE_ONCE:
                /* Event's end time should later than current week's beginning 00:00 */
                if (CompareTime(
                        curr_month_begin, 
                        pevent->end_time, 
                        NULL) <= 0)
                {
                    result = MMI_TRUE;
                }
                break;
                
            case SRV_TDL_RULE_DAILY:
                /* Need to add expiry time checking in the future. */
                result = MMI_TRUE; 
                break;
                
            case SRV_TDL_RULE_WEEKLY:
                /* Need to add expiry time checking in the future. */
                result = MMI_TRUE;
                break;

            case SRV_TDL_RULE_DAYS:
                /* Need to add expiry time checking in the future. */
                result = MMI_TRUE; 
                break;
                
            case SRV_TDL_RULE_MONTHLY:
                /* Need to add expiry time checking in the future. */
                result = MMI_TRUE;
                break;
                
            case SRV_TDL_RULE_YEARLY:
                if(pevent->start_time.nYear == pevent->end_time.nYear)
				{
					curr_month_begin.nYear = pevent->start_time.nYear;
					if (curr_month_begin.nMonth >= pevent->start_time.nMonth && curr_month_begin.nMonth <= pevent->end_time.nMonth)
					{
					    result = MMI_TRUE;
					}
				}
				else if(curr_month_begin.nMonth >= pevent->start_time.nMonth || curr_month_begin.nMonth <= pevent->end_time.nMonth)
				{
				    result = MMI_TRUE;
				}
                break;

            default:
                break;
        }
    }
    
SRV_TDL_ERROR_CLEAN:
    return result;    
}                  


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_search_check_time
 * DESCRIPTION
 *  Search the events that include this time;
 * PARAMETERS
 *  pevent : [IN] The event to be checked.
 *  date_time : [IN] The search condition.
 *                   The start time of the events in the searched list 
 *              should be earlier than date_time and end time shoud be 
 *              later than date_time.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/ 
MMI_BOOL srv_tdl_event_search_check_time(
                const srv_tdl_event_short_struct *pevent, 
                const MYTIME date_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    S32 ret1 = 0, ret2;
	MYTIME temp_time, temp2_time;
    U32 i, j;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_EVENT_CHECK_TIME_DATE, date_time.nYear, date_time.nMonth, date_time.nDay);
    MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_EVENT_CHECK_TIME_TIME, date_time.nHour, date_time.nMin, date_time.nSec);
        
    if (date_time.nYear == 0 || 
        date_time.nMonth == 0 || 
        date_time.nDay == 0)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }
    
    /* 
       1. Event presents.
       2. Start time before search time. 
       3. End time after search time.
     */
    memcpy(&temp_time, &date_time, sizeof(MYTIME)); 
	memcpy(&temp2_time, &date_time, sizeof(MYTIME)); 
    if (pevent->present &&
		CompareTime(pevent->start_time, date_time, NULL) <= 0)
    {
		switch(pevent->repeat.rule)
		{
			case SRV_TDL_RULE_ONCE:
			{
		        ret2 = CompareTime(date_time, pevent->end_time, NULL);
		        if (ret2 <= 0)
		        {
		            result = MMI_TRUE;
		        }
				break;
			}

			case  SRV_TDL_RULE_DAYS:    // may run to next case SRV_TDL_RULE_DAILY
			{
				if(pevent->start_time.nDay == pevent->end_time.nDay)
				{
		            if (pevent->repeat.dows & (0x1 << temp_time.DayIndex))
	                {
						ret1 = 1;
	                    break;
	                }
				}
				else
				{
					if ((pevent->repeat.dows & (0x1 << temp_time.DayIndex)) ||
						(pevent->repeat.dows & (0x1 << ((temp_time.DayIndex + 7 -1)%7))))
	                {
						ret1 = 1;
	                    break;
	                }
				}
				if(!ret1)
				{    
					// not run to next case: SRV_TDL_RULE_DAILY
				    break;
				}
			}
            case  SRV_TDL_RULE_DAILY:
			{
				temp_time.nYear = pevent->start_time.nYear;
				temp_time.nMonth = pevent->start_time.nMonth;
				temp_time.nDay = pevent->start_time.nDay;
				
				if(pevent->start_time.nDay == pevent->end_time.nDay)
				{
					if(CompareTime(temp_time, pevent->end_time, NULL) <= 0 &&
					   CompareTime(temp_time, pevent->start_time, NULL) >= 0)
					{
						result = MMI_TRUE;
					}
				}
				else
				{
					if(CompareTime(temp_time, pevent->start_time, NULL) >= 0)
					{
						result = MMI_TRUE;
					}
					else
					{
						temp_time.nDay = pevent->end_time.nDay;
						if(CompareTime(temp_time, pevent->end_time, NULL) <= 0)
						{
							result = MMI_TRUE;
						}
					}
				}
				break;
            }
				
			case  SRV_TDL_RULE_WEEKLY:
			{				
				if(pevent->start_time.DayIndex == temp_time.DayIndex)
				{
					if(pevent->start_time.nDay == pevent->end_time.nDay) // one day
					{
						if(temp_time.DayIndex == pevent->end_time.DayIndex)
						{
							temp_time.nYear = pevent->start_time.nYear;
							temp_time.nMonth = pevent->start_time.nMonth;
							temp_time.nDay = pevent->start_time.nDay;
							
							if(CompareTime(temp_time, pevent->end_time, NULL) <= 0 &&
							   CompareTime(temp_time, pevent->start_time, NULL) >= 0)
							{
								result = MMI_TRUE;
							}
						}
					}
					else  // cross 7 days
					{
						if(temp_time.DayIndex != pevent->end_time.DayIndex)
						{
							result = MMI_TRUE;
						}
						else
						{
							temp_time.nYear = pevent->start_time.nYear;
							temp_time.nMonth = pevent->start_time.nMonth;
							temp_time.nDay = pevent->start_time.nDay;
							if(CompareTime(temp_time, pevent->start_time, NULL) >= 0)
							{
								result = MMI_TRUE;
							}
							else
							{
								temp_time.nYear = pevent->end_time.nYear;
								temp_time.nMonth = pevent->end_time.nMonth;
								temp_time.nDay = pevent->end_time.nDay;
								if(CompareTime(temp_time, pevent->end_time, NULL) <= 0)
								{
									result = MMI_TRUE;
								}
							}
						}
					}
				}
                else if(temp_time.DayIndex == pevent->start_time.DayIndex)
                {
					temp_time.nYear = pevent->start_time.nYear;
					temp_time.nMonth = pevent->start_time.nMonth;
					temp_time.nDay = pevent->start_time.nDay;
					if(CompareTime(temp_time, pevent->start_time, NULL) >= 0)
					{
						result = MMI_TRUE;
					}
                }
				else if(temp_time.DayIndex == pevent->end_time.DayIndex)
                {
					temp_time.nYear = pevent->end_time.nYear;
					temp_time.nMonth = pevent->end_time.nMonth;
					temp_time.nDay = pevent->end_time.nDay;
					if(CompareTime(temp_time, pevent->end_time, NULL) <= 0)
					{
						result = MMI_TRUE;
					}
                }
				else
				{
					for(i = (pevent->start_time.DayIndex + 1)%7, j = 0; j < 7; j++ )
	                {
						if(i == temp_time.DayIndex)
						{
	                        result = MMI_TRUE;
							break;
						}
						i = (i++) % 7;
						if(i == pevent->end_time.DayIndex)
						{
							break;
						}						
	                }
				}
				break;
            }	
			
			case  SRV_TDL_RULE_MONTHLY:
			{
				temp_time.nYear = pevent->start_time.nYear;
				temp_time.nMonth = pevent->start_time.nMonth;
				
				if(pevent->start_time.nMonth == pevent->end_time.nMonth)
				{
					if(CompareTime(temp_time, pevent->end_time, NULL) <= 0 &&
					   CompareTime(temp_time, pevent->start_time, NULL) >= 0)
					{
						result = MMI_TRUE;
					}
				}
				else
				{
					if(CompareTime(temp_time, pevent->start_time, NULL) >= 0)
					{
						result = MMI_TRUE;
					}
					else
					{
						temp_time.nMonth = pevent->end_time.nMonth;
						if(CompareTime(temp_time, pevent->end_time, NULL) <= 0)
						{
							result = MMI_TRUE;
						}
					}
				}
				break;
            }
			
			case  SRV_TDL_RULE_YEARLY:
			{
				temp_time.nYear = pevent->start_time.nYear;
				
				if(pevent->start_time.nYear == pevent->end_time.nYear)
				{
					if(CompareTime(temp_time, pevent->end_time, NULL) <= 0 &&
					   CompareTime(temp_time, pevent->start_time, NULL) >= 0)
					{
						result = MMI_TRUE;
					}
				}
				else
				{
					if(CompareTime(temp_time, pevent->start_time, NULL) >= 0)
					{
						result = MMI_TRUE;
					}
					else
					{
						temp_time.nYear = pevent->end_time.nYear;
						if(CompareTime(temp_time, pevent->end_time, NULL) <= 0)
						{
							result = MMI_TRUE;
						}
					}
				}
				break;
            }
			
			default:
				break;
		}
    }
    
SRV_TDL_ERROR_CLEAN:   
    return result;    
}                  


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_search_check_duration
 * DESCRIPTION
 *  Search the event list by specific duration.
 * PARAMETERS
 *  pevent :     [IN] The event to be checked.
 *  begin_time : [IN] The search condition.
 *                    The start time of the events in the searched list 
 *               should be later than begin_time.
 *  end_time :   [IN] The end time of the events shoud be 
 *               later than date_time.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/ 
static MMI_BOOL srv_tdl_event_search_check_duration(
                const srv_tdl_event_short_struct *pevent, 
                const MYTIME *begin_time, 
                const MYTIME *end_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
	MYTIME event_start_time, event_end_time;
	MYTIME inc_time, result_time;
	U32 j, l, r;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE3(
        MMI_TDL_SRV_EVENT_CHECK_DURATION_BEGIN_DATE, 
        begin_time->nYear, 
        begin_time->nMonth, 
        begin_time->nDay);

    MMI_TDL_SRV_TRACE3(
        MMI_TDL_SRV_EVENT_CHECK_DURATION_BEGIN_TIME, 
        begin_time->nHour, 
        begin_time->nMin, 
        begin_time->nSec);

    MMI_TDL_SRV_TRACE3(
        MMI_TDL_SRV_EVENT_CHECK_DURATION_END_DATE, 
        end_time->nYear, end_time->nMonth, end_time->nDay);

    MMI_TDL_SRV_TRACE3(
        MMI_TDL_SRV_EVENT_CHECK_DURATION_END_TIME, 
        end_time->nHour, end_time->nMin, end_time->nSec);
        
    if (!pevent ||
        begin_time->nYear == 0 || 
        begin_time->nMonth == 0 || 
        begin_time->nDay == 0 ||
        end_time->nYear == 0 || 
        end_time->nMonth == 0 || 
        end_time->nDay == 0)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }

    /* 
       1. Event presents.
       2. Start time before begin time. 
       3. End time after end time.
     */
    memcpy(&event_start_time, &pevent->start_time, sizeof(MYTIME)); 
	memcpy(&event_end_time, &pevent->end_time, sizeof(MYTIME)); 
	memset(&inc_time, 0, sizeof(MYTIME));
	
    if (pevent->present && CompareTime(pevent->start_time, *end_time, NULL) < 0)
    {
		if(pevent->repeat.rule == SRV_TDL_RULE_ONCE)
		{
			if(((CompareTime(*begin_time, pevent->end_time, NULL) <= 0) && 
				(CompareTime(pevent->start_time, pevent->end_time, NULL) == 0)) ||
				((CompareTime(*begin_time, pevent->end_time, NULL) < 0) && 
				(CompareTime(pevent->start_time, pevent->end_time, NULL) != 0)))
			{
				result = MMI_TRUE;
			}
		}
		else
		{   
			switch(pevent->repeat.rule)
			{		
				case SRV_TDL_RULE_DAYS:
					inc_time.nDay = 1;
					break;
					
				case SRV_TDL_RULE_DAILY:
					inc_time.nDay = 1;
					break;
					
			    case SRV_TDL_RULE_WEEKLY:
					inc_time.nDay = 7;
					break;
					
			    case SRV_TDL_RULE_MONTHLY:
					inc_time.nMonth = 1;
					break;
					
			    case SRV_TDL_RULE_YEARLY:
					inc_time.nYear = 1;
				    break;
					
				default:
					inc_time.nDay = 1;
					break;
			}
							
			for( ;CompareTime(event_start_time, *end_time, NULL) < 0; )
			{
				if(pevent->repeat.rule == SRV_TDL_RULE_DAYS)
				{
					r = pevent->start_time.DayIndex;
					if(((0x1 << r) & pevent->repeat.dows) == 0)
					{
	//					ASSERT(0);
					}
					for(l = (r + 1) , j = 0; j < 7 ;j++)
					{
						l = (r + 1) % 7;
						if(((0x1 << l)& pevent->repeat.dows) != 0)
						{
							continue;
						}
						if(l != r)
						{
						    inc_time.nDay = (l - r + 7)%7;	
							r = l;
							break;
						}
						else
						{
							inc_time.nDay = 7;
							break;
						}	
					}
				}
				if(((CompareTime(*begin_time, event_end_time, NULL) <= 0) && 
				(CompareTime(event_start_time, event_end_time, NULL) == 0)) ||
				((CompareTime(*begin_time, event_end_time, NULL) < 0) && 
				(CompareTime(event_start_time, event_end_time, NULL) != 0)))
				{
					result = MMI_TRUE;
					break;
				}
				
				applib_dt_increase_time(
	                (applib_time_struct*)&event_start_time, 
	                (applib_time_struct*)&inc_time, 
	                (applib_time_struct*)&result_time);
			    memcpy(&event_start_time, &result_time, sizeof(MYTIME));
				
				applib_dt_increase_time(
	                (applib_time_struct*)&event_end_time, 
	                (applib_time_struct*)&inc_time, 
	                (applib_time_struct*)&result_time);
			    memcpy(&event_end_time, &result_time, sizeof(MYTIME));	
			}
		}
    }
        
SRV_TDL_ERROR_CLEAN:   
    return result;    
}                  


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_search_check_subject
 * DESCRIPTION
 *  Search the event list by subject.
 * PARAMETERS
 *  pevent : [IN] The event to be checked.
 *  string : [IN] The string to search.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/ 
static MMI_BOOL srv_tdl_event_search_check_subject(
                const srv_tdl_event_short_struct *pevent, 
                const U16 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    WCHAR subject[MAX_TODO_LIST_NOTE / ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (!pevent)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }

    memcpy(subject, pevent->subject, MAX_TODO_LIST_NOTE);
    mmi_wcsupr(subject);
    mmi_wcsupr((WCHAR*)string);

    /* 
       1. Event presents.
       2. Subject contains string.
     */
    if (pevent->present && 
        mmi_ucs2str((CHAR*)subject, (CHAR*)string))
    {
        result = MMI_TRUE;
    }
    

SRV_TDL_ERROR_CLEAN:   
    return result;    
}                  



/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_search_check_location
 * DESCRIPTION
 *  Search the event list by subject.
 * PARAMETERS
 *  pevent : [IN] The event to be checked.
 *  string : [IN] The string to search.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/ 
static MMI_BOOL srv_tdl_event_search_check_location(
                const srv_tdl_event_short_struct *pevent, 
                const U16 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    WCHAR location[MAX_TDL_LOCATION_SIZE];    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!pevent)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }

    memcpy(location, pevent->location, MAX_TODO_LIST_NOTE);
    mmi_wcsupr(location);
    mmi_wcsupr((WCHAR*)string);

    /* 
       1. Event presents.
       2. Location contains string.
     */
    if (pevent->present &&		
        mmi_ucs2str((CHAR*)location, (CHAR*)string))
    {
        result = MMI_TRUE;
    }
        
SRV_TDL_ERROR_CLEAN:
    return result;    
}                  




/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_search_check_before
 * DESCRIPTION
 *  Search the event list which end time before gived time.
 * PARAMETERS
 *  pevent : [IN] The event to be checked.
 *  category : [IN] The category id to search.
 * RETURNS
 *  The error code of the operation.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/ 
static MMI_BOOL srv_tdl_event_search_check_before(
                const srv_tdl_event_short_struct *pevent, 
                const MYTIME date_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
    if (!pevent)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }
    if (pevent->present && 
        pevent->repeat.rule == SRV_TDL_RULE_ONCE)
    {
        ret = CompareTime(pevent->end_time, date_time, NULL);
        if (ret <= 0)
        {
            result = MMI_TRUE;
        }
    }
    
SRV_TDL_ERROR_CLEAN:   
    return result;    
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_search_check_after
 * DESCRIPTION
 *  Search the event list which end time before gived time.
 * PARAMETERS
 *  pevent : [IN] The event to be checked.
 *  category : [IN] The category id to search.
 * RETURNS
 *  The error code of the operation.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/ 
static MMI_BOOL srv_tdl_event_search_check_after(
                const srv_tdl_event_short_struct *pevent, 
                const MYTIME date_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
    if (!pevent)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }
    if (pevent->present)
    {
		if(pevent->repeat.rule != SRV_TDL_RULE_ONCE)
		{
			result = MMI_TRUE;
		}
		else
		{
	        ret = CompareTime(pevent->start_time, date_time, NULL);
	        if (ret >= 0)
	        {
	            result = MMI_TRUE;
	        }
		}
    }
    
SRV_TDL_ERROR_CLEAN:   
    return result;    
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_search_check_incoming
 * DESCRIPTION
 *  Search the event list which start time after gived time.
 * PARAMETERS
 *  pevent : [IN] The event to be checked.
 *  category : [IN] The category id to search.
 * RETURNS
 *  The error code of the operation.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/ 
static MMI_BOOL srv_tdl_event_search_check_incoming(
                const srv_tdl_event_short_struct *pevent, 
                const MYTIME date_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
    if (!pevent)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }
    if (pevent->present)
    {
        ret = CompareTime(pevent->start_time, date_time, NULL);
        if (ret >= 0)
        {
            result = MMI_TRUE;
        }
    }
    
SRV_TDL_ERROR_CLEAN:   
    return result;    
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_search_check_previous
 * DESCRIPTION
 *  Search the event list which start time before gived time.
 * PARAMETERS
 *  pevent : [IN] The event to be checked.
 *  category : [IN] The category id to search.
 * RETURNS
 *  The error code of the operation.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/ 
static MMI_BOOL srv_tdl_event_search_check_previous(
                const srv_tdl_event_short_struct *pevent, 
                const MYTIME date_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
    if (!pevent)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }
    if (pevent->present)
    {
        ret = CompareTime(pevent->start_time, date_time, NULL);
        if (ret < 0)
        {
            result = MMI_TRUE;
        }
    }
    
SRV_TDL_ERROR_CLEAN:   
    return result;    
}

/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_search_check_all
 * DESCRIPTION
 *  Search the event list which end time before gived time.
 * PARAMETERS
 *  pevent : [IN] The event to be checked.
 *  category : [IN] The category id to search.
 * RETURNS
 *  The error code of the operation.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/ 
static MMI_BOOL srv_tdl_event_search_check_all(
                const srv_tdl_event_short_struct *pevent, 
                const MYTIME date_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
    if (!pevent)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }
    if (pevent->present)
    {
        result = MMI_TRUE;
    }
    
SRV_TDL_ERROR_CLEAN:   
    return result;    
}



/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_search_check_location
 * DESCRIPTION
 *  Search the event list by subject.
 * PARAMETERS
 *  pevent : [IN] The event to be checked.
 *  category : [IN] The category id to search.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/ 
static MMI_BOOL srv_tdl_event_search_check_category(
                const srv_tdl_event_short_struct *pevent, 
                const U8 category)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
    if (!pevent)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }
    
    /* 
       1. Event presents.
       2. Category equal with input para.
     */
    if (pevent->present && 
        pevent->category == category)
    {
        result = MMI_TRUE;
    }
        
SRV_TDL_ERROR_CLEAN:   
    return result;    
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_event_get_new_index
 * DESCRIPTION
 *  Check wether the task/event list is full.
 * PARAMETERS
 *  void
 * RETURNS
 *  New index.
 * RETURN VALUES
 *****************************************************************************/ 
static U16 srv_tdl_event_get_new_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for (i = 0; i < NUM_OF_CAL; i++)
    {
        if (!g_srv_event_list[i].present) break;
    }
    
    MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_GET_NEW_INDEX, i);
    return i;
} 



/*****************************************************************************
 * FUNCTION
 *  srv_tdl_add_task
 * DESCRIPTION
 *  Add a task.
 * PARAMETERS
 *  data :  [IN] The task or event to add.
 *  index : [OUT] The store index of the task added.
 * RETURNS
 *  The error code of the add operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Add success.
 *  SRV_TDL_RESULT_FAIL : Add failed with unknown reason.
 *  SRV_TDL_RESULT_ADD_NOT_ENOUGH_MEMORY : The memory full, can not add success.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter invalid.
 *****************************************************************************/  
static U16 srv_tdl_task_add(
                const srv_tdl_task_struct *data, 
                U16 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    S16 error;
    U16 result = SRV_TDL_RESULT_OK;     
    srv_tdl_task_struct *ptask = NULL;
#ifdef __MMI_TDL_NITZ_SUPPORT__
    applib_time_struct utc_time;
    applib_time_struct rtc_time;
#endif /* __MMI_TDL_NITZ_SUPPORT__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!data || !index)
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        goto SRV_TDL_ERROR_CLEAN;
    }

    i = srv_tdl_task_get_new_index();

    if (i >= NUM_OF_TASK)
    {
        result = SRV_TDL_RESULT_ADD_NOT_ENOUGH_MEMORY;
        goto SRV_TDL_ERROR_CLEAN;
    }

    *index = i;
    ptask = OslMalloc(sizeof(srv_tdl_task_struct));
    memcpy(ptask, data, sizeof(srv_tdl_task_struct));
    ptask->present = 1;
    memcpy(
        &g_srv_todo_list[*index], 
        ptask, 
        sizeof(srv_tdl_task_short_struct));   

#ifdef __MMI_TDL_NITZ_SUPPORT__
    memcpy(&rtc_time, &ptask->due_time, sizeof(MYTIME));
    applib_dt_rtc_to_utc_with_default_tz(&rtc_time, &utc_time);
    memcpy(&ptask->due_time, &utc_time, sizeof(MYTIME));
#endif /* __MMI_TDL_NITZ_SUPPORT__ */
    
    WriteRecord(
        NVRAM_EF_TDL_TASK_LID,
        (U16)(i + 1), 
        (void*)ptask,
        NVRAM_EF_TDL_TASK_SIZE,
        &error);
    
    OslMfree(ptask);
    
SRV_TDL_ERROR_CLEAN:
    MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_TASK_ADD, result, *index);
    return result;
} 


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_task_delete
 * DESCRIPTION
 *  Delete a task.
 * PARAMETERS
 *  index :     [IN] The store index of the task to be deleted.
 *  vcal_type : [IN] Identify the type, event or task.
 * RETURNS
 *  The error code of the deletion operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Delete success.
 *  SRV_TDL_RESULT_FAIL : Delete failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_INDEX : The index is invalid.
 *****************************************************************************/   
static U16 srv_tdl_task_delete(const U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tdl_task_struct *task = NULL;
    S16 error;
    U16 result = SRV_TDL_RESULT_OK;  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= NUM_OF_TASK)
    {
        result = SRV_TDL_RESULT_INVALID_INDEX;
        goto SRV_TDL_ERROR_CLEAN;
    }

    task = OslMalloc(sizeof(srv_tdl_task_struct));
    memset(task, 0, sizeof(srv_tdl_task_struct));

    WriteRecord(
        NVRAM_EF_TDL_TASK_LID,
        (U16)(index + 1),
        (void*)task,
        NVRAM_EF_TDL_TASK_SIZE,
        &error);
        
    memset(&g_srv_todo_list[index], 0, sizeof(srv_tdl_task_short_struct));
        
    OslMfree(task);
    
SRV_TDL_ERROR_CLEAN:
    return result;    
}  



/*****************************************************************************
 * FUNCTION
 *  srv_tdl_task_update
 * DESCRIPTION
 *  Update a task.
 * PARAMETERS
 *  data :      [IN] The task to update to.
 *  buff_size : [IN] The size of data buffer.
 *  index :     [IN] The store index of the task to update.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Update success.
 *  SRV_TDL_RESULT_FAIL : Update failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_INDEX : The index is invalid.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/ 
static U16 srv_tdl_task_update(
                    const srv_tdl_task_struct *data, 
                    const U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = SRV_TDL_RESULT_OK;
    srv_tdl_task_struct *ptask = NULL;    
    S16 error;
#ifdef __MMI_TDL_NITZ_SUPPORT__
    applib_time_struct utc_time;
    applib_time_struct rtc_time;
#endif /* __MMI_TDL_NITZ_SUPPORT__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= NUM_OF_TASK)
    {
        result = SRV_TDL_RESULT_INVALID_INDEX;
        goto SRV_TDL_ERROR_CLEAN;        
    }

    ptask = OslMalloc(sizeof(srv_tdl_task_struct));
    memcpy(ptask, data, sizeof(srv_tdl_task_struct));
    ptask->present = 1;
    memcpy(
        &g_srv_todo_list[index], 
        ptask, 
        sizeof(srv_tdl_task_short_struct));
    
#ifdef __MMI_TDL_NITZ_SUPPORT__
    memcpy(&rtc_time, &ptask->due_time, sizeof(MYTIME));
    applib_dt_rtc_to_utc_with_default_tz(&rtc_time, &utc_time);
    memcpy(&ptask->due_time, &utc_time, sizeof(MYTIME));
#endif /* __MMI_TDL_NITZ_SUPPORT__ */

    WriteRecord(
        NVRAM_EF_TDL_TASK_LID,
        (U16)(index + 1),
        (void*)ptask,
        NVRAM_EF_TDL_TASK_SIZE,
        &error);
    
    OslMfree(ptask);
    
SRV_TDL_ERROR_CLEAN:
    return result;
}                    


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_task_get
 * DESCRIPTION
 *  Get a task/event.
 * PARAMETERS
 *  buff :      [OUT] The buffer to store the task or event got.
 *  buff_size : [IN] The size of the output buffer.
 *  index :     [IN] The store index of the task/event to get.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Get the data success.
 *  SRV_TDL_RESULT_FAIL : Get failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_INDEX : The index is invalid.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/ 
static U16 srv_tdl_task_get(
                srv_tdl_task_struct *buff, 
                const U16 buff_size, 
                const U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = SRV_TDL_RESULT_OK;
    S16 error;    
#ifdef __MMI_TDL_NITZ_SUPPORT__
    applib_time_struct utc_time;
    applib_time_struct rtc_time;
#endif /* __MMI_TDL_NITZ_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (index > NUM_OF_TASK)
    {
        result = SRV_TDL_RESULT_INVALID_INDEX;
        goto SRV_TDL_ERROR_CLEAN;        
    }
    
    if (!buff || buff_size != sizeof(srv_tdl_task_struct))
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        goto SRV_TDL_ERROR_CLEAN;
    }
    
    ReadRecord(
            NVRAM_EF_TDL_TASK_LID,
            (U16)(index + 1),
            buff,
            NVRAM_EF_TDL_TASK_SIZE,
            &error);

    if (buff->present != 1)
    {
        result = SRV_TDL_RESULT_INVALID_INDEX;
        goto SRV_TDL_ERROR_CLEAN;
    }
    
#ifdef __MMI_TDL_NITZ_SUPPORT__
    memcpy(&utc_time, &buff->due_time, sizeof(MYTIME));
    applib_dt_utc_to_rtc_with_default_tz(&utc_time, &rtc_time);
    memcpy(&buff->due_time, &rtc_time, sizeof(MYTIME));
#endif /* __MMI_TDL_NITZ_SUPPORT__ */
    
SRV_TDL_ERROR_CLEAN:
    return result;        
}            


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_task_get_all_index
 * DESCRIPTION
 *  Get all the event/task/both list.
 *  If list buffer is NULL, it will output the total count of event/task.
 * PARAMETERS
 *  list :      [IN/OUT] The list to store event/task, if NULL, will output
        total count only.
 *  length :    [IN] The size of list.
 *  vcal_type : [IN] Identify the type, event or task.
 *  count :     [OUT] The store index of the task/event added.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Get the data successfully.
 *  SRV_TDL_RESULT_FAIL : Getting operation failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/ 
static U16 srv_tdl_task_get_all_index(
                                 srv_tdl_event_task_struct *list, 
                                 const U16 length, 
                                 U16 *count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = SRV_TDL_RESULT_OK;
    U16 i;
    U16 total = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (!count || (list && length < NUM_OF_TASK))
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        goto SRV_TDL_ERROR_CLEAN;
    }
    
    for (i = 0; i < NUM_OF_TASK; i++)
    {            
        if (g_srv_todo_list[i].present)
        {
            if (list)
            {
                list[total].index = i;
                list[total].type = SRV_TDL_VCAL_TASK;
            }
            total++;
        }       
    }
    *count = total;
    
SRV_TDL_ERROR_CLEAN:    
    MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_TASK_GET_ALL_INDEX, result, total);
    return result;    
}  


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_task_get_free
 * DESCRIPTION
 *  Get the free number of task/event.
 * PARAMETERS
 *  count : [OUT] The free number to output.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Get the count successfully.
 *  SRV_TDL_RESULT_FAIL : Getting operation failed with unknown reason.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/ 
static U16 srv_tdl_task_get_free(U16 *count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 total = 0;
    U16 i;
    U16 result = SRV_TDL_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (!count)
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        goto SRV_TDL_ERROR_CLEAN;
    }
    
    for (i = 0; i < NUM_OF_TASK; i++)
    {            
        if (!g_srv_todo_list[i].present)
        {
            total++;
        }       
    }

    *count = total;
    
SRV_TDL_ERROR_CLEAN:    
    MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_TASK_GET_FREE, result); 
    return result;      
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_task_search_check_time
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
MMI_BOOL srv_tdl_task_search_check_daily(
                            const srv_tdl_task_short_struct *ptask, 
                            const MYTIME date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    MYTIME date_start;
    MYTIME date_end;
    U8 day_index;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_TASK_CHECK_DAILY_DATE, date.nYear, date.nMonth, date.nDay);
    if (date.nYear == 0 || date.nMonth == 0 || date.nDay == 0)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }

    memcpy(&date_start, &date, sizeof(MYTIME));
    date_start.nHour = 0;
    date_start.nMin = 0;
    date_start.nSec = 0;

    memcpy(&date_end, &date, sizeof(MYTIME));
    date_end.nHour = 23;
    date_end.nMin = 59;
    date_end.nSec = 59;    

    /* task presents and start time before current date 23:59 */
    if (ptask->present && 
        CompareTime(ptask->due_time, date_end, NULL) <= 0)
    {
        switch (ptask->repeat.rule)
        {
            case SRV_TDL_RULE_ONCE:
                /* task's due time should later than current date 00:00 */
                if (CompareTime(date_start, ptask->due_time, NULL) <= 0)
                {
                    result = MMI_TRUE;
                }
                break;
                
            case SRV_TDL_RULE_DAILY:
                /* Need to add expiry time checking in the future. */
                result = MMI_TRUE; 
                break;
                
            case SRV_TDL_RULE_WEEKLY:
                /* Need to add expiry time checking in the future. */
                if (DOW(date.nYear, date.nMonth, date.nDay) ==
                    DOW(ptask->due_time.nYear, 
                        ptask->due_time.nMonth, 
                        ptask->due_time.nDay))
                {
                    result = MMI_TRUE;
                }
                break;
                
            case SRV_TDL_RULE_DAYS:
                /* Need to add expiry time checking in the future. */
                day_index = DOW(date.nYear, date.nMonth, date.nDay);

                for (i = 0; i < SRV_TDL_MAX_DAYS_PER_WEEK; i++)
                {
                    if ((ptask->repeat.dows & g_srv_clndr_weekday_index[i]) && 
                        (i == day_index))
                    {
                        result = MMI_TRUE;
                        break;
                    }
                }
                break;                
            case SRV_TDL_RULE_MONTHLY:
                /* Need to add expiry time checking in the future. */
                if (ptask->due_time.nDay == date.nDay)
                {
                    result = MMI_TRUE;
                }
                break;
                
            case SRV_TDL_RULE_YEARLY:
                /* Need to add expiry time checking in the future. */
                if (ptask->due_time.nDay == date.nDay &&
                    ptask->due_time.nMonth == date.nMonth)
                {
                    result = MMI_TRUE;
                }
                break;            
                
            default:
                break;
        }
    }       

SRV_TDL_ERROR_CLEAN:    
    return result;    
}                  


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
MMI_BOOL srv_tdl_task_search_check_weekly(
                            const srv_tdl_task_short_struct *ptask, 
                            const srv_tdl_search_weely_struct weekly_search)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    MYTIME curr_week_begin;
    MYTIME next_week_begin;
    MYTIME inc_time;
    U16 day_index;
    S32 date_temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE3(
        MMI_TDL_SRV_TASK_CHECK_WEEKLY_DATE, 
        weekly_search.date_time.nYear, 
        weekly_search.date_time.nMonth, 
        weekly_search.date_time.nDay);
    
    if (!ptask || 
        weekly_search.date_time.nYear == 0 || 
        weekly_search.date_time.nMonth == 0 || 
        weekly_search.date_time.nDay == 0)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }

    srv_tdl_cal_week_get_first_date(
        &weekly_search.date_time, 
        &curr_week_begin,
        weekly_search.start_day_of_week);
    
    memset(&inc_time, 0, sizeof(MYTIME));
    inc_time.nDay = SRV_TDL_MAX_DAYS_PER_WEEK;
    
    applib_dt_increase_time(
        (applib_time_struct*)&curr_week_begin,
        (applib_time_struct*)&inc_time,
        (applib_time_struct*)&next_week_begin);
        
    /* task presents and start time before the beginning of the next week. */
    if (ptask->present && 
        CompareTime(ptask->due_time, next_week_begin, NULL) < 0)
    {
        switch (ptask->repeat.rule)
        {
            case SRV_TDL_RULE_ONCE:
                /* task's end time should later than current week's beginning 00:00 */
                if (CompareTime(curr_week_begin, ptask->due_time, NULL) <= 0)
                {
                    result = MMI_TRUE;
                }
                break;
                
            case SRV_TDL_RULE_DAILY:
                /* Need to add expiry time checking in the future. */
                result = MMI_TRUE; 
                break;
                
            case SRV_TDL_RULE_WEEKLY:
                /* Need to add expiry time checking in the future. */
                result = MMI_TRUE;
                break;

            case SRV_TDL_RULE_DAYS:
                /* Need to add expiry time checking in the future. */
                result = MMI_TRUE; 
                break;
                
            case SRV_TDL_RULE_MONTHLY:
                /* Need to add expiry time checking in the future. */
                for (day_index = 1; 
                     day_index <= SRV_TDL_MAX_DAYS_PER_WEEK; 
                     day_index++)
                {
                    date_temp = next_week_begin.nDay - day_index;
                    if (date_temp > 0 &&
                        date_temp == ptask->due_time.nDay)
                    {   
                        result = MMI_TRUE;
                        break;
                    }
                    else if (date_temp <= 0)
                    {
                        date_temp += applib_dt_last_day_of_mon(
                                            curr_week_begin.nMonth, 
                                            curr_week_begin.nYear);
                                            
                        if (date_temp == 
                            ptask->due_time.nDay)
                        {
                            result = MMI_TRUE;
                            break;
                        }                                    
                    }
                }
                break;
                
            case SRV_TDL_RULE_YEARLY:
                /* Need to add expiry time checking in the future. */
                for (day_index = 1; 
                     day_index <= SRV_TDL_MAX_DAYS_PER_WEEK; 
                     day_index++)
                {
                    date_temp = next_week_begin.nDay - day_index;
                    if (date_temp > 0 && 
                        date_temp == ptask->due_time.nDay &&
                        next_week_begin.nMonth == ptask->due_time.nMonth)
                    {   
                        result = MMI_TRUE;
                        break;
                    }
                    else if (date_temp <= 0)
                    {
                        date_temp += applib_dt_last_day_of_mon(
                                            curr_week_begin.nMonth, 
                                            curr_week_begin.nYear);
                                            
                        if (date_temp == ptask->due_time.nDay &&
                            curr_week_begin.nMonth == ptask->due_time.nMonth)
                        {
                            result = MMI_TRUE;
                            break;
                        }                                    
                    }
                }
                break;

            default:
                break;
        }
    }       
    
SRV_TDL_ERROR_CLEAN:
    return result;    
}                  


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
MMI_BOOL srv_tdl_task_search_check_monthly(
                            const srv_tdl_task_short_struct *ptask, 
                            const MYTIME date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    MYTIME curr_month_begin;
    MYTIME next_month_begin;
    MYTIME inc_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_TASK_CHECK_MONTHLY_ENTRY, date.nYear, date.nMonth, date.nDay);
    if (!ptask|| date.nYear == 0 || date.nMonth == 0 || date.nDay == 0)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }

    memcpy(&curr_month_begin, &date, sizeof(MYTIME));
    curr_month_begin.nDay = 1;
    curr_month_begin.nHour = 0;
    curr_month_begin.nMin = 0;
    curr_month_begin.nSec = 0;
    
    memset(&inc_time, 0, sizeof(MYTIME));    
    inc_time.nMonth = 1;
    
    applib_dt_increase_time(
        (applib_time_struct*)&curr_month_begin,
        (applib_time_struct*)&inc_time,
        (applib_time_struct*)&next_month_begin);
        
    /* task presents and start time before the beginning of the next week. */
    if (ptask->present && 
        CompareTime(ptask->due_time, next_month_begin, NULL) < 0)
    {
        switch (ptask->repeat.rule)
        {
            case SRV_TDL_RULE_ONCE:
                /* task's end time should later than current week's beginning 00:00 */
                if (CompareTime(curr_month_begin, ptask->due_time, NULL) <= 0)
                {
                    result = MMI_TRUE;
                }
                break;
                
            case SRV_TDL_RULE_DAILY:
                /* Need to add expiry time checking in the future. */
                result = MMI_TRUE; 
                break;
                
            case SRV_TDL_RULE_WEEKLY:
                /* Need to add expiry time checking in the future. */
                result = MMI_TRUE;
                break;

            case SRV_TDL_RULE_DAYS:
                /* Need to add expiry time checking in the future. */
                result = MMI_TRUE; 
                break;
                
            case SRV_TDL_RULE_MONTHLY:
                /* Need to add expiry time checking in the future. */
                result = MMI_TRUE;
                break;
                
            case SRV_TDL_RULE_YEARLY:
                /* Need to add expiry time checking in the future. */
                if (date.nMonth == ptask->due_time.nMonth)
                {
                    result = MMI_TRUE; 
                }
                break;

            default:
                break;
        }
    }       
    
SRV_TDL_ERROR_CLEAN:
    return result;    
}                  


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_task_search_check_before
 * DESCRIPTION
 *  Search the task list in which due time before than gived date time.
 * PARAMETERS
 *  list : [OUT] The searched list. If NULL, means only want to get total.
 *  buff_size : [IN] The buffer size of the list.
 *  date_time : [IN] The search condition.
 *                   The due time of the tasks in the searched list 
 *              should be equal to date_time.
 *  count : [OUT] The searched count.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/ 
static MMI_BOOL srv_tdl_task_search_check_before(
                            const srv_tdl_task_short_struct *ptask, 
                            const MYTIME date_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_TASK_CHECK_BEFORE_DATE, date_time.nYear, date_time.nMonth, date_time.nDay);
    MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_TASK_CHECK_BEFORE_TIME, date_time.nHour, date_time.nMin, date_time.nSec);
        
    if (!ptask ||
        date_time.nYear == 0 || 
        date_time.nMonth == 0 || 
        date_time.nDay == 0)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }

    /* 
       1. Task presents.
       2. Due time before than search time. 
     */
    if (ptask->present &&
        ptask->repeat.rule == SRV_TDL_RULE_ONCE)
    {
        ret = CompareTime(ptask->due_time, date_time, NULL);

        if (ret < 0)
        {
            result = MMI_TRUE;
        }
    }
        
SRV_TDL_ERROR_CLEAN:
    return result;    
}                  


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_task_search_check_time
 * DESCRIPTION
 *  Search the task list by specific time.
 * PARAMETERS
 *  list : [OUT] The searched list. If NULL, means only want to get total.
 *  buff_size : [IN] The buffer size of the list.
 *  date_time : [IN] The search condition.
 *                   The due time of the tasks in the searched list 
 *              should be equal to date_time.
 *  count : [OUT] The searched count.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/ 
static MMI_BOOL srv_tdl_task_search_check_time(
                            const srv_tdl_task_short_struct *ptask, 
                            const MYTIME date_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_TASK_CHECK_TIME_DATE, date_time.nYear, date_time.nMonth, date_time.nDay);
    MMI_TDL_SRV_TRACE3(MMI_TDL_SRV_TASK_CHECK_TIME_TIME, date_time.nHour, date_time.nMin, date_time.nSec);
        
    if (!ptask ||
        date_time.nYear == 0 || 
        date_time.nMonth == 0 || 
        date_time.nDay == 0)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }

    /* 
       1. Task presents.
       2. Due time equal to search time. 
     */
    if (ptask->present)
    {
        ret = CompareTime(ptask->due_time, date_time, NULL);

        if (ret == 0)
        {
            result = MMI_TRUE;
        }
    }
        
SRV_TDL_ERROR_CLEAN:    
    return result;    
}                  


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_task_search_check_duration
 * DESCRIPTION
 *  Search the task list by specific duration.
 * PARAMETERS
 *  list : [OUT] The searched list. If NULL, means only want to get total.
 *  buff_size : [IN] The buffer size of the list.
 *  date_time : [IN] The search condition.
 *                   The start time of the tasks in the searched list 
 *              should be earlier than date_time and end time shoud be 
 *              later than date_time.
 *  count : [OUT] The searched count.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/ 
static MMI_BOOL srv_tdl_task_search_check_duration(
                            const srv_tdl_task_short_struct *ptask, 
                            const MYTIME *begin_time,
                            const MYTIME *end_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    S32 ret1, ret2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE3(
            MMI_TDL_SRV_TASK_CHECK_DURATION_BEGIN_DATE, 
            begin_time->nYear, 
            begin_time->nMonth, 
            begin_time->nDay);

    MMI_TDL_SRV_TRACE3(
            MMI_TDL_SRV_TASK_CHECK_DURATION_BEGIN_TIME,
        begin_time->nHour, begin_time->nMin, begin_time->nSec);

    MMI_TDL_SRV_TRACE3(
            MMI_TDL_SRV_TASK_CHECK_DURATION_END_DATE,
        end_time->nYear, end_time->nMonth, end_time->nDay);

    MMI_TDL_SRV_TRACE3(
            MMI_TDL_SRV_TASK_CHECK_DURATION_END_TIME,
        end_time->nHour, end_time->nMin, end_time->nSec);
        
    if (!ptask ||
        begin_time->nYear == 0 || 
        begin_time->nMonth == 0 || 
        begin_time->nDay == 0 ||
        end_time->nYear == 0 || 
        end_time->nMonth == 0 || 
        end_time->nDay == 0)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }

    /* 
      1. Task presents.
      2. Due time is contained in duration times. 
    */
    if (ptask->present &&
        ptask->repeat.rule == SRV_TDL_RULE_ONCE)
    {
        ret1 = CompareTime(begin_time, ptask->due_time, NULL);
        ret2 = CompareTime(ptask->due_time, end_time, NULL);

        if (ret1 <= 0 && ret2 <= 0)
        {
            result = MMI_TRUE;
        }
    }
        
SRV_TDL_ERROR_CLEAN:
    return result;    
}                  


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_task_search_check_subject
 * DESCRIPTION
 *  Search the task list by subject.
 * PARAMETERS
 *  list : [OUT] The searched list. If NULL, means only want to get total.
 *  buff_size : [IN] The buffer size of the list.
 *  string : [IN] The string to search.
 *  count : [OUT] The searched count.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/ 
static MMI_BOOL srv_tdl_task_search_check_subject(
                            const srv_tdl_task_short_struct *ptask, 
                            const U16 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    if (!ptask)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }

    /* 
       1. task presents.
       2. Subject contains string.
     */
    mmi_wcsupr((WCHAR*)ptask->subject);
    mmi_wcsupr((WCHAR*)string);
    if (ptask->present && 
        mmi_ucs2str((CHAR*)ptask->subject, (CHAR*)string))
    {
        result = MMI_TRUE;
    }    
    
SRV_TDL_ERROR_CLEAN:
    return result;    
}                  


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_task_search_check_status
 * DESCRIPTION
 *  Search the task list by status undone.
 * PARAMETERS
 *  list : [OUT] The searched list. If NULL, means only want to get total.
 *  buff_size : [IN] The buffer size of the list.
 *  string : [IN] The string to search.
 *  count : [OUT] The searched count.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/ 
static MMI_BOOL srv_tdl_task_search_check_status(
                            const srv_tdl_task_short_struct *ptask, 
                            const U16 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    if (!ptask)
    {
        goto SRV_TDL_ERROR_CLEAN;
    }
    
    if (ptask->present && ptask->status == status)
    {
        result = MMI_TRUE;
    }
    
SRV_TDL_ERROR_CLEAN:    
    return result;    
}                  


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_task_get_new_index
 * DESCRIPTION
 *  Check wether the task/event list is full.
 * PARAMETERS
 *  void
 * RETURNS
 *  New index
 * RETURN VALUES
 *****************************************************************************/ 
static U16 srv_tdl_task_get_new_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    for (i = 0; i < NUM_OF_TASK; i++)
    {
        if (!g_srv_todo_list[i].present) break;
    }

    return i;
}


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
S16 srv_tdl_task_compare_priority(U16 index1, U16 index2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tdl_compare_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE2(MMI_TDL_SRV_TASK_COMPARE_PRIORITY, index1, index2);
    if (g_srv_todo_list[index1].priority < 
        g_srv_todo_list[index2].priority)
    {
        result = SRV_TDL_COMPARE_LESS;
    }
    else if(g_srv_todo_list[index1].priority == 
            g_srv_todo_list[index2].priority)
    {
        result = SRV_TDL_COMPARE_EQUAL;
    }
    else
    {
        result = SRV_TDL_COMPARE_GREATER;
    }
    
    MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_TASK_COMPARE_PRIORITY_LEAVE, result);
    return result;
}  


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
void srv_tdl_cal_change_dow(U8 *dow, const srv_tdl_start_day_enum start_day)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (start_day != SRV_TDL_START_DAY_SUN)
    {
        if (*dow < start_day)
        {
            *dow += (SRV_TDL_MAX_DAYS_PER_WEEK - start_day);
        }
        else
        {
            *dow -= start_day;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_tdl_cal_week_get_first_date
 * DESCRIPTION
 *  Get the first date in the week specified according to the curr_date.
 * PARAMETERS
 *  curr_date : [IN]
 *  first_date_of_week : [OUT]
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  SRV_TDL_RESULT_OK : Searched the task list successfully.
 *  SRV_TDL_RESULT_FAIL : Searched the list failed with unknown reasons.
 *  SRV_TDL_RESULT_INVALID_PARAMETER : The parameter is invalid.
 *****************************************************************************/
U16 srv_tdl_cal_week_get_first_date(
                    const MYTIME *curr_date, 
                    MYTIME *first_date_of_week, 
                    const srv_tdl_start_day_enum start_day_of_week)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 day;
    U16 result = SRV_TDL_RESULT_OK;
    MYTIME inc_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_SRV_TRACE3(
            MMI_TDL_SRV_CAL_FIRST_DATE_WEEK,
        curr_date->nYear, curr_date->nMonth, curr_date->nDay);  
        
    if (!first_date_of_week)
    {
        result = SRV_TDL_RESULT_INVALID_PARAMETER;
        goto SRV_TDL_ERROR_CLEAN;
    }
    memset(&inc_time, 0, sizeof(MYTIME));

    day = (U8)applib_dt_dow(
                        curr_date->nYear, 
                        curr_date->nMonth, 
                        curr_date->nDay);

    srv_tdl_cal_change_dow(&day, start_day_of_week);

    inc_time.nDay = day;

    applib_dt_decrease_time(
        (applib_time_struct*) curr_date,
        (applib_time_struct*) &inc_time,
        (applib_time_struct*) first_date_of_week);
        
    first_date_of_week->nHour = 0;
    first_date_of_week->nMin = 0;
    first_date_of_week->nSec = 0;
    
SRV_TDL_ERROR_CLEAN:
    MMI_TDL_SRV_TRACE1(MMI_TDL_SRV_CAL_FIRST_DATE_WEEK_LEAVE, result); 
    return result;
}

#endif /* __MMI_SRV_TODOLIST__ */

