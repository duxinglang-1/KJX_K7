/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_cal_java_entry.cpp
 *
 * Project:
 * --------
 *  Cosmos
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

#ifdef SUPPORT_JSR_75_PIM
extern "C"
{
    #include "app_datetime.h"
    #ifdef __SYNCML_SUPPORT__   
    #include "vapp_sync_gprot.h"
    #endif
}
#include "vapp_cal_prot.h"
#include "vapp_cal_view_detail_ext.h"
#include "vapp_cal_utility.h"
#include "vapp_cal_edit.h"
#include "vapp_cal_java_entry.h"


// write
static void mmi_tdl_pim_evtdb_wirte_req(void* info);

static mmi_evtdb_java_error_enum mmi_tdl_pim_event_add(
                                        const mmi_evtdb_java_entry_struct* java_entry, 
                                        const mmi_vclndr_db_sort_enum db_index,                        
                                        U16 *index);          

static mmi_evtdb_java_error_enum mmi_tdl_pim_task_add(const mmi_evtdb_java_entry_struct* evtdb_entry, U16 *index);

static mmi_evtdb_java_error_enum mmi_tdl_pim_event_update(
                                                U16 index, 
                                                mmi_evtdb_java_entry_struct* java_entry, 
                                                mmi_vclndr_db_sort_enum db_index);

static mmi_evtdb_java_error_enum mmi_tdl_pim_task_update(
                        U16 index, 
                        mmi_evtdb_java_entry_struct* java_entry, 
                        mmi_vclndr_db_sort_enum db_index);

static U16 mmi_tdl_pim_check_field_mask(const U16 mask, const U16 field);

static mmi_evtdb_java_error_enum mmi_tdl_pim_task_parse_field(
                        srv_tdl_task_struct *ptask,
                        const mmi_evtdb_java_entry_struct* java_entry);

static mmi_evtdb_java_error_enum mmi_tdl_pim_event_parse_field(
                        srv_tdl_event_struct *pevent,
                        const mmi_vclndr_db_sort_enum db_index,
                        const mmi_evtdb_java_entry_struct *java_entry);

// read
static VfxBool mmi_tdl_pim_event_get_field(U16 index, mmi_evtdb_java_entry_struct *entry);
static VfxBool mmi_tdl_pim_task_get_field(U16 index, mmi_evtdb_java_entry_struct *entry);
static void mmi_tdl_make_list_by_category(
                        U8 category, 
                        srv_tdl_event_task_struct *list, 
                        U16 buff_size,
                        U16 *total);
static void mmi_tdl_make_all_list(
                        srv_tdl_event_task_struct *list, 
                        U16 size,
                        U16 *total, 
                        U16 vcal_type);

static void mmi_tdl_pim_evtdb_wirte_req(void* info);
static void mmi_tdl_pim_write_rsp(U16 result, U16 store_index);
static void mmi_tdl_pim_evtdb_read_req(void* info);
static void mmi_tdl_pim_read_rsp(U16 result, U16 count);

                        
static mmi_tdl_java_context_struct g_tdl_java_cntx;


void vapp_cal_java_data_handler_init(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_tdl_pim_evtdb_wirte_req, MSG_ID_MMI_EVTDB_JAVA_SET_ENTRY_REQ);
    SetProtocolEventHandler(mmi_tdl_pim_evtdb_read_req, MSG_ID_MMI_EVTDB_JAVA_GET_ENTRY_REQ);
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_evtdb_wirte_req
* DESCRIPTION
*   This function write a todolist entry from pim request
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static void mmi_tdl_pim_evtdb_wirte_req(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evtdb_java_set_entry_req_struct* local_ptr;
    mmi_evtdb_java_entry_struct java_entry;
    mmi_evtdb_java_error_enum error_code = MMI_EVTDB_JAVA_SUCCESS;
    U16  result, record_index = 0;
    U16 vcal_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_evtdb_java_set_entry_req_struct*)info;

    if(local_ptr->sort_type != MMI_EVTDB_SORT_BY_TIME)
    {
        error_code = MMI_EVTDB_JAVA_NOT_SUPPORT;
        goto MMI_JAVA_RETURN;        
    }

    if (local_ptr->db_index < MMI_VCLNDR_DB_TASK)
    {
        vcal_type = SRV_TDL_VCAL_EVENT;
    }
    else if (local_ptr->db_index == MMI_VCLNDR_DB_TASK)
    {
        vcal_type = SRV_TDL_VCAL_TASK;
    }
    else /* MMI_VCLNDR_DB_ALL: all events. */
    {
        vcal_type = SRV_TDL_VCAL_EVENT;
    }

#ifdef __SYNCML_SUPPORT__   	
    if (vapp_sync_is_cal_synchronizing(0) && vcal_type == SRV_TDL_VCAL_EVENT)
    {
        error_code = MMI_EVTDB_JAVA_TDL_NOT_READY;
        goto MMI_JAVA_RETURN;
    }   

    if (vapp_sync_is_task_synchronizing(0) && vcal_type == SRV_TDL_VCAL_TASK)
    {
        error_code = MMI_EVTDB_JAVA_TDL_NOT_READY;
        goto MMI_JAVA_RETURN;
    }
#endif       

    /* delete record */
    if (local_ptr->entry_ptr == NULL)
    {
        record_index = (U8)local_ptr->index;

        result = srv_tdl_delete(record_index, (const srv_tdl_vcal_enum )vcal_type);
        if (result != SRV_TDL_RESULT_OK)
        {
            error_code = MMI_EVTDB_JAVA_OUT_OF_INDEX;
            goto MMI_JAVA_RETURN;
        }
    }  
    else /* Add and update new record */
    {
        memcpy(&java_entry, local_ptr->entry_ptr, sizeof(mmi_evtdb_java_entry_struct));

        /* Add */
        if (local_ptr->index == 0xFFFF) 
        {
            if (vcal_type == SRV_TDL_VCAL_EVENT)
            {
                error_code = mmi_tdl_pim_event_add(
                                        &java_entry, 
                                        (mmi_vclndr_db_sort_enum)local_ptr->db_index, 
                                        &record_index);
            }
            else
            {
                error_code = mmi_tdl_pim_task_add(
                                        &java_entry, 
                                        &record_index);
            }
        }
        /* Update */
        else
        {
            record_index = (U8)local_ptr->index;
            if (vcal_type == SRV_TDL_VCAL_EVENT)
            {
                error_code = mmi_tdl_pim_event_update(
                                        local_ptr->index,
                                        &java_entry, 
                                        (mmi_vclndr_db_sort_enum)local_ptr->db_index);
            }
            else
            {
                error_code = mmi_tdl_pim_task_update(
                                        local_ptr->index,
                                        &java_entry, 
                                        (mmi_vclndr_db_sort_enum)local_ptr->db_index);
            }
        }
    }

MMI_JAVA_RETURN:
    mmi_tdl_pim_write_rsp((U16)error_code,record_index);
}

/*****************************************************************************
* FUNCTION
*  mmi_phb_java_write_rsp
* DESCRIPTION
*   This function return write result to JAVA
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static void mmi_tdl_pim_write_rsp(U16 result, U16 store_index)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   mmi_evtdb_java_set_entry_rsp_struct *MsgPtr;
   MYQUEUE Message;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   MsgPtr = (mmi_evtdb_java_set_entry_rsp_struct*) 
                OslConstructDataPtr(sizeof(mmi_evtdb_java_set_entry_rsp_struct));
   MsgPtr->index = MsgPtr->handle = store_index;
   
   /* TDL may want to display some warning but it still save the task */
    if (result < MMI_EVTDB_JAVA_SUCCESS)
    {
        MsgPtr->result = MMI_EVTDB_JAVA_SUCCESS;
        MsgPtr->detail = (U8)result;
    }
    else
    {
        MsgPtr->result = (U8)result;
        MsgPtr->detail = 0xFF;
    }

   Message.oslSrcId = MOD_MMI;
   Message.oslDestId = MOD_JASYN;
   Message.oslMsgId = MSG_ID_MMI_EVTDB_JAVA_SET_ENTRY_RSP;
   Message.oslDataPtr = (oslParaType *)MsgPtr;
   Message.oslPeerBuffPtr= NULL;

   OslMsgSendExtQueue(&Message);
}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_evtdb_read_req
* DESCRIPTION
*   This function read a todolist entry from pim.
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static void mmi_tdl_pim_evtdb_read_req(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evtdb_java_get_entry_req_struct* local_ptr;
    mmi_evtdb_java_error_enum error_code = MMI_EVTDB_JAVA_SUCCESS;
    VfxBool result;
      
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_evtdb_java_get_entry_req_struct*)info;

    if(local_ptr->sort_type != MMI_EVTDB_SORT_BY_TIME)
    {
        error_code = MMI_EVTDB_JAVA_NOT_SUPPORT;
        goto MMI_TDL_JAVA_RETURN;
    }
    
    /* init tdl list, sort by date */
    if(local_ptr->index == 0 || local_ptr->count == 0)
    {
        if (local_ptr->db_index < MMI_VCLNDR_DB_TASK)
        {
            mmi_tdl_make_list_by_category(
                                local_ptr->db_index, 
                                g_tdl_java_cntx.sorted_list, 
                                NUM_OF_TDL, 
                                &g_tdl_java_cntx.total_listed_num);
        }
        else if (local_ptr->db_index == MMI_VCLNDR_DB_TASK)
        {

            mmi_tdl_make_all_list(
                                g_tdl_java_cntx.sorted_list, 
                                NUM_OF_TDL,
                                &g_tdl_java_cntx.total_listed_num,
                                SRV_TDL_VCAL_TASK);
        }
        else /* MMI_VCLNDR_DB_ALL: get all events. */
        {
            mmi_tdl_make_all_list(
                                g_tdl_java_cntx.sorted_list, 
                                NUM_OF_TDL,
                                &g_tdl_java_cntx.total_listed_num,
                                SRV_TDL_VCAL_EVENT);
        }
    }

    /* If count == 0, means only want to get total. */
    if (local_ptr->count != 0)
    {
        /* Get a record in context */
        if (local_ptr->index < (VAPP_TASK_MAX_COUNT + VAPP_CAL_MAX_COUNT))
        {
            if (local_ptr->db_index < MMI_VCLNDR_DB_TASK || local_ptr->db_index == MMI_VCLNDR_DB_ALL)
            {
                result = mmi_tdl_pim_event_get_field(local_ptr->index, local_ptr->entry_ptr);
            }
            else
            {
                result = mmi_tdl_pim_task_get_field(local_ptr->index, local_ptr->entry_ptr);
            }
            
            if (result == MMI_FALSE)
            {
                error_code = MMI_EVTDB_JAVA_NOT_FOUND;
                goto MMI_TDL_JAVA_RETURN;
            }            
        }
        else
        {
            error_code = MMI_EVTDB_JAVA_OUT_OF_INDEX;
        }
    }

MMI_TDL_JAVA_RETURN:
    mmi_tdl_pim_read_rsp((U16)error_code, g_tdl_java_cntx.total_listed_num);
    return;
}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_read_rsp
* DESCRIPTION
*   This function return read result to JAVA
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static void mmi_tdl_pim_read_rsp(U16 result, U16 count)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   mmi_evtdb_java_get_entry_rsp_struct *MsgPtr;
   MYQUEUE Message;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   MsgPtr = (mmi_evtdb_java_get_entry_rsp_struct*)
                    OslConstructDataPtr(sizeof(mmi_evtdb_java_get_entry_rsp_struct));

   MsgPtr->result = (U8)result;
   MsgPtr->count = count;

   Message.oslSrcId=MOD_MMI;
   Message.oslDestId=MOD_JASYN;
   Message.oslMsgId = MSG_ID_MMI_EVTDB_JAVA_GET_ENTRY_RSP;
   Message.oslDataPtr = (oslParaType *)MsgPtr;
   Message.oslPeerBuffPtr= NULL;

   OslMsgSendExtQueue(&Message);
}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_check_field_mask
* DESCRIPTION
*   This function update tdl record
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static U16 mmi_tdl_pim_check_field_mask(const U16 mask, const U16 field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (mask & field) ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_add_event
* DESCRIPTION
*   This function update tdl record
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static mmi_evtdb_java_error_enum mmi_tdl_pim_event_add(
                        const mmi_evtdb_java_entry_struct* java_entry, 
                        const mmi_vclndr_db_sort_enum db_index,                        
                        U16 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 error_code;
    srv_tdl_event_struct *pevent = NULL;
    mmi_evtdb_java_error_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_SYS_ALLOC_MEM(pevent, sizeof(srv_tdl_event_struct));
    VFX_ASSERT(pevent);
    memset(pevent, 0, sizeof(srv_tdl_event_struct));

    pevent->vcal = SRV_TDL_VCAL_EVENT;
    
    result = mmi_tdl_pim_event_parse_field(pevent, db_index, java_entry);
    if (result !=  MMI_EVTDB_JAVA_SUCCESS)
    {
        goto MMI_TDL_JAVA_RETURN;
    }

    VappCalViewDetailFromExtPage::adjustDataValidation((void *)pevent, SRV_TDL_VCAL_EVENT);
    
    // Alarm check.
    if (!VappCalUtility::isValidAlarm((void *)pevent, SRV_TDL_VCAL_EVENT))
    {
        result = MMI_EVTDB_JAVA_TDL_INVALID_ALARM;
        goto MMI_TDL_JAVA_RETURN;
    }


    //caculate reminder,and save the reminder
    VAPP_CAL_REMINDER_ENUM reminderType = (VAPP_CAL_REMINDER_ENUM)pevent->alarm.type;
    if (reminderType != VAPP_CAL_REMINDER_NEVER)
    {
        VappCalEditPage::setReminderFirstLaunchTime(&(pevent->start_time), 
                        &pevent->alarm.first_launch,
                        reminderType,
                        (VfxBool)(pevent->all_day),
                        VappCalEditPage::convertCategoryStoM((srv_vcal_category_type_enum)(pevent->category)));
    }


    error_code = srv_tdl_add(pevent, SRV_TDL_VCAL_EVENT, index);

    if (error_code == SRV_TDL_RESULT_ADD_NOT_ENOUGH_MEMORY)
    {
        result = MMI_EVTDB_JAVA_STORAGE_FULL;
        goto MMI_TDL_JAVA_RETURN;
    }

    if (error_code != SRV_TDL_RESULT_OK)
    { 
        result = MMI_EVTDB_JAVA_NOT_SUPPORT;
        goto MMI_TDL_JAVA_RETURN;
    }

    result = MMI_EVTDB_JAVA_SUCCESS;
    
MMI_TDL_JAVA_RETURN:
	VFX_FREE_MEM(pevent);
    return result;
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_add_task
* DESCRIPTION
*   This function update tdl record
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static mmi_evtdb_java_error_enum mmi_tdl_pim_task_add(
                        const mmi_evtdb_java_entry_struct* java_entry, 
                        U16 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 error_code;
    srv_tdl_task_struct *ptask = NULL;
    mmi_evtdb_java_error_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_SYS_ALLOC_MEM(ptask, sizeof(srv_tdl_task_struct));
    VFX_ASSERT(ptask);

    memset(ptask, 0, sizeof(srv_tdl_task_struct));

    ptask->vcal = SRV_TDL_VCAL_TASK;
    
    result = mmi_tdl_pim_task_parse_field(ptask, java_entry);
    if (result !=  MMI_EVTDB_JAVA_SUCCESS)
    {
        goto MMI_TDL_JAVA_RETURN;
    }

    VappCalViewDetailFromExtPage::adjustDataValidation((void *)ptask, SRV_TDL_VCAL_TASK);

    VAPP_CAL_REMINDER_ENUM reminderType = (VAPP_CAL_REMINDER_ENUM)ptask->alarm.type;

    if (reminderType != VAPP_CAL_REMINDER_NEVER)
    {
        VappCalEditPage::setReminderFirstLaunchTime(&(ptask->due_time), 
                                &ptask->alarm.first_launch, 
                                reminderType);
    }


    error_code = srv_tdl_add(
                    ptask, 
                    SRV_TDL_VCAL_TASK, 
                    index);

    if (error_code == SRV_TDL_RESULT_ADD_NOT_ENOUGH_MEMORY)
    {
        result = MMI_EVTDB_JAVA_STORAGE_FULL;
        goto MMI_TDL_JAVA_RETURN;
    }

    if (error_code != SRV_TDL_RESULT_OK)
    { 
        result = MMI_EVTDB_JAVA_NOT_SUPPORT;
        goto MMI_TDL_JAVA_RETURN;
    }

    result = MMI_EVTDB_JAVA_SUCCESS;
    
MMI_TDL_JAVA_RETURN:
    VFX_FREE_MEM(ptask);
    return result;
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_task_parse_field
* DESCRIPTION
*   This function update tdl record
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static mmi_evtdb_java_error_enum mmi_tdl_pim_task_parse_field(
                        srv_tdl_task_struct *ptask,
                        const mmi_evtdb_java_entry_struct* java_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evtdb_java_error_enum result;
    mmi_evtdb_java_entry_struct* pentry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_SYS_ALLOC_MEM(pentry, sizeof(mmi_evtdb_java_entry_struct));
    VFX_ASSERT(pentry);

    memcpy(pentry, java_entry, sizeof(mmi_evtdb_java_entry_struct));

    if (!mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_SUBJECT))
    {
        result = MMI_EVTDB_JAVA_TDL_INVALID_NOTES;
        goto MMI_TDL_JAVA_RETURN;
    }
    else
    {
        memcpy(ptask->subject, pentry->note, MAX_TODO_LIST_NOTE);
    }
    
    if (!mmi_tdl_pim_check_field_mask(
                            pentry->field_mask, 
                            MMI_TDL_JAVA_FIELD_END_TIME) ||
        !applib_dt_check_valid_by_app(
                            (U16)VAPP_CAL_MIN_YEAR, 
                            (U16)VAPP_CAL_MAX_YEAR, 
                            &pentry->endTime))
    {
        result = MMI_EVTDB_JAVA_TDL_INVALID_END_TIME;
        goto MMI_TDL_JAVA_RETURN;
    }
    else
    {
        memcpy(&ptask->due_time, &pentry->endTime, sizeof(MYTIME));
    }
 
    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_ALARM))
    {
        ptask->alarm.type = pentry->alarm;
    }
#ifdef JSR_75_PIM_EXTRA_ALARM_TIME_USER_DEFINE
    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_ALARM_TIME))
    {
        memcpy(&ptask->alarm.first_launch, &pentry->alarm_time, sizeof(MYTIME));
    }
#endif
#ifdef JSR_75_PIM_EXTRA_DETAIL
    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_DETAILS))
    {
        memcpy(ptask->details, pentry->details, MAX_TDL_DETAILS_SIZE * ENCODING_LENGTH);
    }
#endif
    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_REPEAT))
    {
        ptask->repeat.rule = pentry->repeat;
    }

#ifdef JSR_75_PIM_EXTRA_TODO
    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_STATUS))
    {
        if (pentry->status < SRV_TDL_STATUS_TOTAL)
        {
            ptask->status = pentry->status;
        }
    }

    if (ptask->status == SRV_TDL_STATUS_DONE)
    {
        if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_DONE_TIME))
        {
            memcpy(&ptask->complete_time, &pentry->complete_time, sizeof(MYTIME));
        }
        else
        {
            GetDateTime(&ptask->complete_time);
        }
    }
    
    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_PRIORITY))
    {
        ptask->priority = pentry->Priority;
    }
#endif
    result = MMI_EVTDB_JAVA_SUCCESS;
MMI_TDL_JAVA_RETURN:
    VFX_FREE_MEM(pentry);
    return result;
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_event_parse_field
* DESCRIPTION
*   This function update tdl record
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static mmi_evtdb_java_error_enum mmi_tdl_pim_event_parse_field(
                        srv_tdl_event_struct *pevent,
                        const mmi_vclndr_db_sort_enum db_index,
                        const mmi_evtdb_java_entry_struct* java_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evtdb_java_error_enum result;
    mmi_evtdb_java_entry_struct* pentry;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_SYS_ALLOC_MEM(pentry, sizeof(mmi_evtdb_java_entry_struct));
    VFX_ASSERT(pentry);

    memcpy(pentry, java_entry, sizeof(mmi_evtdb_java_entry_struct));

    if (!mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_SUBJECT))
    {
        result = MMI_EVTDB_JAVA_TDL_INVALID_NOTES;
        goto MMI_TDL_JAVA_RETURN;
    }
    else
    {
        memcpy(pevent->subject, pentry->note, MAX_TODO_LIST_NOTE);
    }

    if (!mmi_tdl_pim_check_field_mask(
                            pentry->field_mask, 
                            MMI_TDL_JAVA_FIELD_START_TIME) ||
        !applib_dt_check_valid_by_app(
                            VAPP_CAL_MIN_YEAR, 
                            VAPP_CAL_MAX_YEAR, 
                            &pentry->startTime))
    {
        result = MMI_EVTDB_JAVA_TDL_INVALID_START_TIME;
        goto MMI_TDL_JAVA_RETURN;
    }
    else
    {
        memcpy(&pevent->start_time, &pentry->startTime, sizeof(MYTIME));
    }

    if (!mmi_tdl_pim_check_field_mask(
                            pentry->field_mask, 
                            MMI_TDL_JAVA_FIELD_END_TIME) ||
        !applib_dt_check_valid_by_app(
                            (U16)VAPP_CAL_MIN_YEAR, 
                            (U16)VAPP_CAL_MAX_YEAR, 
                            &pentry->endTime))    
    {
        result = MMI_EVTDB_JAVA_TDL_INVALID_END_TIME;
        goto MMI_TDL_JAVA_RETURN;
    }
    else
    {
        memcpy(&pevent->end_time, &pentry->endTime, sizeof(MYTIME));
    }

    if (db_index < MMI_VCLNDR_DB_TASK)
    {
        pevent->category = db_index;
    }

    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_ALARM))
    {
        pevent->alarm.type = pentry->alarm;
    }
#ifdef JSR_75_PIM_EXTRA_ALARM_TIME_USER_DEFINE
    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_ALARM_TIME)||(pentry->alarm == 0))
    {
        memcpy(&pevent->alarm.first_launch, &pentry->alarm_time, sizeof(MYTIME));
    }
#endif

#ifdef JSR_75_PIM_EXTRA_TODO
    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_LOCATION))
    {
        memcpy(pevent->location, pentry->Location, MAX_TDL_LOCATION_LEN * ENCODING_LENGTH);
    }
#endif

#ifdef JSR_75_PIM_EXTRA_DETAIL
    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_DETAILS))
    {
        memcpy(pevent->details, pentry->details, MAX_TDL_DETAILS_SIZE * ENCODING_LENGTH);
    }
#endif
    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_REPEAT))
    {
        pevent->repeat.rule = pentry->repeat;
        if (pevent->repeat.rule == SRV_TDL_RULE_DAYS)
        {
            pevent->repeat.dows = pentry->days;
        }
    }

    result = MMI_EVTDB_JAVA_SUCCESS;

MMI_TDL_JAVA_RETURN:
    VFX_FREE_MEM(pentry);
    return result;
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_task_update
* DESCRIPTION
*   This function update tdl record
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static mmi_evtdb_java_error_enum mmi_tdl_pim_task_update(
                        U16 index, 
                        mmi_evtdb_java_entry_struct* java_entry, 
                        mmi_vclndr_db_sort_enum db_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evtdb_java_error_enum result;
    srv_tdl_task_struct *ptask = NULL;
    U16 error_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_SYS_ALLOC_MEM(ptask, sizeof(srv_tdl_task_struct));
    VFX_ASSERT(ptask);

    error_code = srv_tdl_get(
                    ptask, 
                    sizeof(srv_tdl_task_struct), 
                    SRV_TDL_VCAL_TASK, 
                    index);

    if (error_code != SRV_TDL_RESULT_OK || !ptask->present)
    {
        result = MMI_EVTDB_JAVA_OUT_OF_INDEX;
        goto MMI_TDL_JAVA_RETURN;
    }

    ptask->vcal = SRV_TDL_VCAL_TASK;
    
    result = mmi_tdl_pim_task_parse_field(ptask, java_entry);
    if (result !=  MMI_EVTDB_JAVA_SUCCESS)
    {
        goto MMI_TDL_JAVA_RETURN;
    }

    VappCalViewDetailFromExtPage::adjustDataValidation((void *)ptask, SRV_TDL_VCAL_TASK);

    error_code = srv_tdl_update(ptask, SRV_TDL_VCAL_TASK, index);
                        
    if (error_code != SRV_TDL_RESULT_OK)
    {
        result = MMI_EVTDB_JAVA_OUT_OF_INDEX;
        goto MMI_TDL_JAVA_RETURN;
    }
    
    result = MMI_EVTDB_JAVA_SUCCESS;
    
MMI_TDL_JAVA_RETURN:    
    VFX_FREE_MEM(ptask);
    return result;
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_update_event
* DESCRIPTION
*   This function update tdl record
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static mmi_evtdb_java_error_enum mmi_tdl_pim_event_update(
                        U16 index, 
                        mmi_evtdb_java_entry_struct* java_entry, 
                        mmi_vclndr_db_sort_enum db_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evtdb_java_error_enum result;
    srv_tdl_event_struct *pevent = NULL;
    U16 error_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_SYS_ALLOC_MEM(pevent, sizeof(srv_tdl_event_struct));
    VFX_ASSERT(pevent);

    error_code = srv_tdl_get(
                    pevent, 
                    sizeof(srv_tdl_event_struct), 
                    SRV_TDL_VCAL_EVENT, 
                    index);

    if (error_code != SRV_TDL_RESULT_OK || !pevent->present)
    {
        result = MMI_EVTDB_JAVA_OUT_OF_INDEX;
        goto MMI_TDL_JAVA_RETURN;
    }

    pevent->vcal = SRV_TDL_VCAL_EVENT;
    
    result = mmi_tdl_pim_event_parse_field(pevent, db_index, java_entry);

    if (result !=  MMI_EVTDB_JAVA_SUCCESS)
    {
        goto MMI_TDL_JAVA_RETURN;
    }


    VappCalViewDetailFromExtPage::adjustDataValidation((void *)pevent, SRV_TDL_VCAL_EVENT);
    

    if((pevent->all_day))
    {
        if((pevent->start_time.nHour!=0)||(pevent->start_time.nMin!=0)||(pevent->start_time.nSec!=0))
        {
            result = MMI_EVTDB_JAVA_TDL_INVALID_START_TIME;
            goto MMI_TDL_JAVA_RETURN;
        }
    }
    
    // Alarm check.
    if (!VappCalUtility::isValidAlarm((void *)pevent, SRV_TDL_VCAL_EVENT))
    {
        result = MMI_EVTDB_JAVA_TDL_INVALID_ALARM;
        goto MMI_TDL_JAVA_RETURN;
    }


    //caculate reminder,and save the reminder
    VAPP_CAL_REMINDER_ENUM reminderType = (VAPP_CAL_REMINDER_ENUM)pevent->alarm.type;
    if (reminderType != VAPP_CAL_REMINDER_NEVER)
    {
        VappCalEditPage::setReminderFirstLaunchTime(&(pevent->start_time), 
                                &pevent->alarm.first_launch,
                                reminderType,
                                (VfxBool)(pevent->all_day),
                                VappCalEditPage::convertCategoryStoM((srv_vcal_category_type_enum)(pevent->category)));
    }

    // clear snooze flag.
    pevent->alarm.snooze = 0;

    error_code = srv_tdl_update(pevent, SRV_TDL_VCAL_EVENT, index);
                        
    if (error_code != SRV_TDL_RESULT_OK)
    {
        result = MMI_EVTDB_JAVA_OUT_OF_INDEX;    
        goto MMI_TDL_JAVA_RETURN;
    }
    
    result = MMI_EVTDB_JAVA_SUCCESS;
    
MMI_TDL_JAVA_RETURN:    
    VFX_FREE_MEM(pevent);
    return result;
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_task_get_field
* DESCRIPTION
*   This function get tdl info by index
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static VfxBool mmi_tdl_pim_task_get_field(U16 index, mmi_evtdb_java_entry_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxBool result;
    srv_tdl_task_struct *ptask = NULL;
    U16 error_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_SYS_ALLOC_MEM(ptask, sizeof(srv_tdl_task_struct));
    VFX_ASSERT(ptask);

    error_code = srv_tdl_get(
                    ptask, 
                    sizeof(srv_tdl_task_struct), 
                    SRV_TDL_VCAL_TASK, 
                    g_tdl_java_cntx.sorted_list[index].index);
                
    if (!ptask->present || error_code != SRV_TDL_RESULT_OK)
    {
        result = VFX_FALSE;
        goto MMI_TDL_JAVA_RETURN;
    }
    
    memcpy(&entry->startTime, &ptask->due_time, sizeof(MYTIME));
    memcpy(&entry->endTime, &ptask->due_time, sizeof(MYTIME));
    
    entry->alarm = ptask->alarm.type;
#ifdef JSR_75_PIM_EXTRA_ALARM_TIME_USER_DEFINE    
    memcpy(&entry->alarm_time, &ptask->alarm.first_launch, sizeof(MYTIME));
#endif    
    mmi_ucs2ncpy((CHAR*)&entry->note, (CHAR*)&ptask->subject, MAX_TODO_NOTE_LEN - 1);
#ifdef JSR_75_PIM_EXTRA_DETAIL
    mmi_ucs2ncpy((CHAR*)&entry->details, (CHAR*)&ptask->details, MAX_TDL_DETAILS_LEN);
#endif
    entry->repeat= ptask->repeat.rule;
    entry->days= ptask->repeat.dows;

#ifdef JSR_75_PIM_EXTRA_TODO   
    entry->Priority = ptask->priority;
    entry->status = ptask->status;
    memcpy(&entry->complete_time, &ptask->complete_time, sizeof(MYTIME));
#endif /* JSR_75_PIM_EXTRA_TODO */

    entry->index= index;
    entry->handle= g_tdl_java_cntx.sorted_list[index].index;
    
    result = VFX_TRUE;

MMI_TDL_JAVA_RETURN:
    VFX_FREE_MEM(ptask);
    return result;
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_event_get_field
* DESCRIPTION
*   This function get tdl info by index
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static VfxBool mmi_tdl_pim_event_get_field(U16 index, mmi_evtdb_java_entry_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxBool result;
    srv_tdl_event_struct *pevent = NULL;
    VfxU16 error_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_SYS_ALLOC_MEM(pevent, sizeof(srv_tdl_event_struct));
    VFX_ASSERT(pevent);

    error_code = srv_tdl_get(
                    pevent, 
                    sizeof(srv_tdl_event_struct), 
                    SRV_TDL_VCAL_EVENT, 
                    g_tdl_java_cntx.sorted_list[index].index);
                
    if (!pevent->present || error_code != SRV_TDL_RESULT_OK)
    {
        result = VFX_FALSE;
        goto MMI_TDL_JAVA_RETURN;
    }
    
    memcpy(&entry->startTime, &pevent->start_time, sizeof(MYTIME));
    memcpy(&entry->endTime, &pevent->end_time, sizeof(MYTIME));
    
#if defined(JSR_75_PIM_EXTRA_TODO)
    entry->Type = pevent->category;
    memcpy(&entry->Location, &pevent->location, MAX_TDL_LOCATION_LEN * ENCODING_LENGTH);    
#endif /* JSR_75_PIM_EXTRA_TODO */

    entry->alarm = pevent->alarm.type;

    // alarm_time need to keep consistant with preminder enum value.
    VappCalViewDetailFromExtPage::getEventAlarmTime(pevent, (MYTIME *)&entry->alarm_time);

    mmi_ucs2ncpy((S8*)&entry->note, (S8*)&pevent->subject, MAX_TODO_NOTE_LEN - 1);
#ifdef JSR_75_PIM_EXTRA_DETAIL
    mmi_ucs2ncpy((S8*)&entry->details, (S8*)&pevent->details, MAX_TDL_DETAILS_LEN);
#endif
    entry->repeat= pevent->repeat.rule;
    entry->days= pevent->repeat.dows;

    entry->index= index;
    entry->handle= g_tdl_java_cntx.sorted_list[index].index;
    
    result = VFX_TRUE;

MMI_TDL_JAVA_RETURN:
    VFX_FREE_MEM(pevent);
    return result;
}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_get_handle
* DESCRIPTION
*   This function gets handle by sorted index.
*
* PARAMETERS
*  void
* RETURNS
*  handle index, -1 means no matched record
* GLOBALS AFFECTED
*   none
*****************************************************************************/
S16 mmi_tdl_pim_get_handle(U16 index, U8 sort_type, U8 db_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tdl_event_task_struct *temp_list = NULL;
    U16 total;
    S16 result;
    U16 max_count = VAPP_TDL_MAX_COUNT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_SYS_ALLOC_MEM(temp_list, sizeof(srv_tdl_event_task_struct) * max_count);
    VFX_ASSERT(temp_list);

    memset(temp_list, 0xFF, sizeof(srv_tdl_event_task_struct) * max_count);

    /* Required index should not be larger than NUM_OF_TDL*/
    if (index >= max_count)
    {
        result = -1;
        goto MMI_TDL_JAVA_RETURN;
    }
    
    switch (sort_type)
    {
        case MMI_EVTDB_SORT_BY_TIME:

            if(db_index < MMI_VCLNDR_DB_TASK)
            {
                mmi_tdl_make_list_by_category(
                                        db_index,
                                        temp_list,
                                        max_count,
                                        &total);
            }
            else if(db_index == MMI_VCLNDR_DB_TASK)
            {
                mmi_tdl_make_all_list(
                                temp_list,
                                max_count,
                                &total,
                                SRV_TDL_VCAL_TASK);
            }
            else /* MMI_VCLNDR_DB_ALL: get all events. */
            {
                mmi_tdl_make_all_list(
                                temp_list,
                                max_count,
                                &total,
                                SRV_TDL_VCAL_EVENT);
            }

            /* if the index is not exist */
            if (temp_list[index].index == 0xFF)
            {
                result = -1;
            }
            else
            {
                result = (S16)temp_list[index].index;
            }
            break;
            
        default:
            result = -1;
    }
    
MMI_TDL_JAVA_RETURN:
    VFX_FREE_MEM(temp_list);
    return result;
}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_get_sorted_index
* DESCRIPTION
*   This function get tdl info by index
*
* PARAMETERS
*  void
* RETURNS
*  handle index, -1 means no matched record
* GLOBALS AFFECTED
*   none
*****************************************************************************/
S16 mmi_tdl_pim_get_sorted_index(U16 store_index, U8 sort_type, U8 db_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    S16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sort_type)
    {
        case MMI_EVTDB_SORT_BY_TIME:
            /* sort the tdl by date */
            if(db_index < MMI_VCLNDR_DB_TASK)
            {
                mmi_tdl_make_list_by_category(
                                        db_index,
                                        g_tdl_java_cntx.sorted_list,
                                        NUM_OF_TDL,
                                        &g_tdl_java_cntx.total_listed_num);
            }
            else if(db_index == MMI_VCLNDR_DB_TASK)
            {
                mmi_tdl_make_all_list(
                                g_tdl_java_cntx.sorted_list,
                                NUM_OF_TDL,
                                &g_tdl_java_cntx.total_listed_num,
                                SRV_TDL_VCAL_TASK);
            }
            else /* MMI_VCLNDR_DB_ALL: get all events. */
            {
                mmi_tdl_make_all_list(
                                g_tdl_java_cntx.sorted_list,
                                NUM_OF_TDL,
                                &g_tdl_java_cntx.total_listed_num,
                                SRV_TDL_VCAL_EVENT);
            }
            
            for (i = 0; i < VAPP_TDL_MAX_COUNT; i++)
            {
                if (g_tdl_java_cntx.sorted_list[i].index == store_index)    
                    break;
            }

            if(i >= VAPP_TDL_MAX_COUNT)
            {
                result = -1;
                goto MMI_TDL_JAVA_RETURN;
            }
            else
            {
                result = (S16)i;
                goto MMI_TDL_JAVA_RETURN;
            }
            break;
            
        default:
            result = -1;
            goto MMI_TDL_JAVA_RETURN;
    }

MMI_TDL_JAVA_RETURN:
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_make_list_by_category
 * DESCRIPTION
 *  To make the list of all tasks to be displayed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_tdl_make_list_by_category(
                                U8 category, 
                                srv_tdl_event_task_struct *list, 
                                U16 buff_size,
                                U16 *total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tdl_search_filter_struct search_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(list);

    if (buff_size < VAPP_CAL_MAX_COUNT)
    {
        return;
    }
    
    search_info.type = SRV_TDL_SEARCH_TYPE_CATEGORY;
    search_info.u.category = category;
    srv_tdl_search(
                list, 
                buff_size, 
                SRV_TDL_VCAL_EVENT, 
                search_info, 
                total);
                
    srv_tdl_sort(
                list, 
                *total, 
                SRV_TDL_SORT_TYPE_ENTRY_TIME);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_make_all_list
 * DESCRIPTION
 *  To make the list of all tasks to be displayed.
 * PARAMETERS
 *  list : [OUT] the sorted list result, if list == NULL, searched result
 *               will be stored in g_tdl_cntx.sorted_list, and total will 
 *               be stored in g_tdl_cntx.total_listed_num.
 *  total : [OUT] searched total.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_tdl_make_all_list(
                        srv_tdl_event_task_struct *list, 
                        U16 size,
                        U16 *total, 
                        U16 vcal_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_tdl_get_all_index(list, size, (srv_tdl_vcal_enum)vcal_type, total);
    srv_tdl_sort(list, *total, SRV_TDL_SORT_TYPE_ENTRY_TIME);
}

#endif /* SUPPORT_JSR_75_PIM */ 
