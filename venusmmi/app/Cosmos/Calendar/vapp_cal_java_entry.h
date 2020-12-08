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
 *  Vapp_cal_java_entry.h
 *
 * Project:
 * --------
 *  Venus
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_CAL_JAVA_ENTRY_H__
#define __VAPP_CAL_JAVA_ENTRY_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/

#if defined(SUPPORT_JSR_75_PIM)

#ifdef __cplusplus
extern "C"
{
#endif

    #include "todolistsrvgprot.h"
    #include "app_datetime.h"
    #include "Vcalsrvgprot.h"
    #include "vapp_cal_prot.h"

    #define MMI_TDL_JAVA_FIELD_SUBJECT             (0x0001)
    #define MMI_TDL_JAVA_FIELD_START_TIME          (0x0002)
    #define MMI_TDL_JAVA_FIELD_END_TIME            (0x0004)
    #define MMI_TDL_JAVA_FIELD_CATEGORY            (0x0008)
    #define MMI_TDL_JAVA_FIELD_ALARM               (0x0010)
    #define MMI_TDL_JAVA_FIELD_ALARM_TIME          (0x0020)
    #define MMI_TDL_JAVA_FIELD_REPEAT              (0x0040)
    #define MMI_TDL_JAVA_FIELD_LOCATION            (0x0080)
    #define MMI_TDL_JAVA_FIELD_DETAILS             (0x0100)
    #define MMI_TDL_JAVA_FIELD_STATUS              (0x0200)
    #define MMI_TDL_JAVA_FIELD_DONE_TIME           (0x0400)
    #define MMI_TDL_JAVA_FIELD_PRIORITY            (0x0800)

    typedef struct
    {
        kal_uint16                  index;  /* display index. */
        kal_uint16                  handle; /* store index */
        applib_time_struct          startTime;
        applib_time_struct          endTime;
        kal_uint8                   note[MAX_TODO_LIST_NOTE]; /* The subject field in todo */
        kal_uint16                  field_mask;
#ifdef JSR_75_PIM_EXTRA_DETAIL
        kal_uint8                   details[MAX_TDL_DETAILS_SIZE * ENCODING_LENGTH];
#endif
#ifdef JSR_75_PIM_EXTRA_ALARM_TIME_USER_DEFINE
        applib_time_struct          alarm_time;
#endif
        kal_uint8                   alarm;          /* The alarm type field in todo */
        kal_uint8                   repeat;
        kal_uint8                   days;
#ifdef JSR_75_PIM_EXTRA_TODO
        kal_uint8                   status;                                 /* completed, done or undone */
        kal_uint8                   Type;                               /* Type of task */
        kal_uint8                   Priority;                               /* Priority of task */
        applib_time_struct          complete_time;                          /* completed time */    
        kal_uint8                   Location[MAX_TDL_LOCATION_SIZE * ENCODING_LENGTH];           /* Location of an Task */
#endif
    } mmi_evtdb_java_entry_struct;

    /*
       Add:
          sort_type : sort by which type, the result will return in response msg
          index:      0xFFFF
          return ---  index : sort by sort_type, handle: phsical index

       update:
          sort_type : sort type
          index:      if sort type = MMI_EVTDB_NO_SORT, index = store_index
                      else , index = sort_index
          return ---  index/handle : no use

       delete:
          sort_type  : sort type
          index:      if sort type = MMI_EVTDB_NO_SORT, index = store_index
                      else , index = sort_index
          return ---  index/handle : no use
    */

    typedef struct
    {
       LOCAL_PARA_HDR
       kal_uint8  sort_type;  // add by eric, reference to mmi_evtdb_sort_enum
       kal_uint16 index;      // change by eric
       kal_uint8   db_index;
       mmi_evtdb_java_entry_struct* entry_ptr;
    } mmi_evtdb_java_set_entry_req_struct;

    typedef struct
    {
       LOCAL_PARA_HDR
       kal_uint8 result;
       kal_uint16 index;
       kal_uint8   db_index;
       kal_uint8   detail;
       kal_uint16 handle;
    } mmi_evtdb_java_set_entry_rsp_struct;


    /*
        Get:
          sort_type : sort by which type
          index:      if sort type = MMI_EVTDB_NO_SORT, index = store_index
                      else , index = sort_index
          count:      1

        Get Total:
          count:      0

    */


    typedef struct
    {
       LOCAL_PARA_HDR
       kal_uint8  sort_type;
       kal_uint16 index;
       kal_uint16 count;
       kal_uint8   db_index;
       mmi_evtdb_java_entry_struct* entry_ptr;
    } mmi_evtdb_java_get_entry_req_struct;

    typedef struct
    {
       LOCAL_PARA_HDR
       kal_uint8 result;
       kal_uint16 count;
       kal_uint8   db_index;
       kal_uint8   detail;
    } mmi_evtdb_java_get_entry_rsp_struct;

    typedef struct
    {
        srv_tdl_event_task_struct sorted_list[VAPP_CAL_MAX_COUNT + VAPP_TASK_MAX_COUNT];
        U16 total_listed_num;
    }mmi_tdl_java_context_struct;


    typedef enum MMI_EVTDB_ERROR_ENUM
    {
        MMI_EVTDB_JAVA_TDL_EXPIRED_ALARM =0,   /* Repeat is once and start time is overdue*/
        MMI_EVTDB_JAVA_SUCCESS,
        MMI_EVTDB_JAVA_NOT_SUPPORT,
        MMI_EVTDB_JAVA_TDL_NOT_READY,
        MMI_EVTDB_JAVA_NOT_FOUND,
        MMI_EVTDB_JAVA_STORAGE_FULL,
        MMI_EVTDB_JAVA_DELETE_FAIL,
        MMI_EVTDB_JAVA_OUT_OF_INDEX,
        MMI_EVTDB_JAVA_INVALID_HANDLE,
        MMI_EVTDB_JAVA_INVALID_DATE,
        MMI_EVTDB_JAVA_TDL_INVALID_START_TIME,
        MMI_EVTDB_JAVA_TDL_INVALID_END_TIME,
        MMI_EVTDB_JAVA_TDL_INVALID_NOTES,       /* Notes is empty*/     
        MMI_EVTDB_JAVA_TDL_INVALID_ALARM,
        MMI_EVTDB_JAVA_TDL_INVALID_REPEAT,
        MMI_EVTDB_JAVA_TDL_REPEAT_OUT_OF_BOUNDARY,
        MMI_EVTDB_JAVA_TDL_ALARM_TIME_OVERRUN,
        MMI_EVTDB_JAVA_ERROR
    }mmi_evtdb_java_error_enum;
    
    typedef enum
    {
        MMI_EVTDB_NO_SORT,
        MMI_EVTDB_SORT_BY_TIME,
        MMI_EVTDB_SORT_MAX
    }mmi_evtdb_sort_enum;

    typedef enum
    {
        MMI_VCLNDR_DB_PERSONAL = SRV_VCAL_CATEGORY_TYPE_REMINDER,
        MMI_VCLNDR_DB_MEETING = SRV_VCAL_CATEGORY_TYPE_MEETING,
        MMI_VCLNDR_DB_SPECIALDAY = SRV_VCAL_CATEGORY_TYPE_ANNIVERSARY,
        MMI_VCLNDR_DB_BIRTHDAY = SRV_VCAL_CATEGORY_TYPE_BIRTHDAY,
        MMI_VCLNDR_DB_OTHER = SRV_VCAL_CATEGORY_TYPE_DATE,
        MMI_VCLNDR_DB_TASK = SRV_VCAL_CATEGORY_TYPE_TOTAL,
        MMI_VCLNDR_DB_ALL,
        MMI_VCLNDR_DB_MAX = MMI_VCLNDR_DB_ALL
    }mmi_vclndr_db_sort_enum;
    
    void vapp_cal_java_data_handler_init(void);
    
    extern S16 mmi_tdl_pim_get_handle(U16 index, U8 sort_type, U8 db_index);
    extern S16 mmi_tdl_pim_get_sorted_index(U16 handle, U8 sort_type, U8 db_index);
    
#ifdef __cplusplus
}
#endif

#endif /*SUPPORT_JSR_75_PIM*/

#endif //__VAPP_CAL_JAVA_ENTRY_H__

