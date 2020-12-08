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
 *  vdat_recent_event.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file implements the service data of the recent events.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vdat_recent_event.h"
#include "vadp_v2p_hs_widget_recent_event.h"
#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vfx_date_time.h"
#include "vfx_system.h"
#include "vfx_cpp_base.h"
#include "vfx_signal.h"
#include "vfx_string.h"

#ifdef __cplusplus
extern "C"
{

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "app_datetime.h"
#include "MMIDataType.h"

} /* extern "C"*/
#endif


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VdatRecentEvent);


/***************************************************************************** 
 * Global function
 *****************************************************************************/
 
VdatRecentEvent::VdatRecentEvent() :
    m_num_of_event(0),
    m_err(ERR_NONE)
{
    for (VfxS32 i = 0; i < MAX_EVENT_NUM; i++)
    {
        m_event[i]           = NULL;
        m_event_data[i].type = EVENT_TOTAL;
    }
}


int VdatRecentEvent::compare(const EventStruct *a, const EventStruct *b)
{
    VfxDateTime::CompareEnum ret_time;
    VfxS32 ret;
    
    /* Compared by time */
    ret_time = a->time.compareWith(b->time);
    if (ret_time == VfxDateTime::GREATER)
    {
        return 1;
    }
    else if (ret_time == VfxDateTime::LESS)
    {
        return -1;
    }

    /* Compared by string */
    ret = vfx_sys_wcscmp(a->subject.getBuf(), b->subject.getBuf());
    if (ret != 0)
    {
        return ret;
    }

    /* Compared by user data to maintain fixed order. */
    ret = (VfxU32)a->user_data - (VfxU32)b->user_data;
    if (ret != 0)
    {
        return ret;
    }
    
    return 0; /* equal */
}


void VdatRecentEvent::sort_event()
{
    EventStruct *tmp;
    VfxS32 max;
    
    for (VfxS32 i = 0; i < m_num_of_event; i++)
    {
        max = i;
        
        for (VfxS32 j = i + 1; j < m_num_of_event; j++)
        {
            if (compare(m_event[max], m_event[j]) < 0)
            {
                max = j;
            }
        }

        // swap
        tmp = m_event[i];
        m_event[i] = m_event[max];
        m_event[max] = tmp;
    }
}


VfxBool VdatRecentEvent::isToday(VfxDateTime &time)
{
    applib_time_struct currTime;
    
    applib_dt_get_date_time(&currTime);

    if (time.getYear() == currTime.nYear &&
        time.getMonth() == currTime.nMonth &&
        time.getDay() == currTime.nDay)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


void VdatRecentEvent::reset(ErrEnum err)
{
    // Not available. Set on error code and clear all events.
    m_err = err;
    
    m_num_of_event = 0;
    
    for (VfxS32 i = 0; i < MAX_EVENT_NUM; i++)
    {
        m_event[i]           = NULL;
        m_event_data[i].type = EVENT_TOTAL;
    }
}


void VdatRecentEvent::processEventCleared(EventTypeEnum type)
{
    for (VfxS32 i = 0; i < m_num_of_event; i++)
    {
        if (m_event[i]->type == type)
        {
            m_event[i]->type = EVENT_TOTAL;
            
            for (VfxS32 j = i; j < m_num_of_event - 1; j++)
            {
                m_event[j] = m_event[j + 1];
            }
            
            --m_num_of_event;
            --i;
        }
    }
}


void VdatRecentEvent::processEventChanged(EventTypeEnum type, callback_t cbf)
{
    EXT_ASSERT(type < EVENT_TOTAL, type, 0, 0);

    m_callback[type] = cbf;
}


void VdatRecentEvent::processEventChanged(VfxS32 num, EventStruct *event)
{
    // If the recent event list is not available now, clear all the events and
    // emit the signal for the user.
    
    if (!vadp_v2p_hs_recent_event_is_available())
    {
        // TODO: distinguish different error type.
        reset(ERR_SIM_INVALID);
        
        // Emit the event immediately.
        m_signalEventChanged.emit(this);

        return;
    }

    // Otherwise, update the recent event list.
    
    for (VfxS32 i = 0; i < num; i++)
    {
        VfxS32 j;

        if (m_num_of_event < MAX_EVENT_NUM)
        {
            // found an empty slot
            for (j = 0; j < MAX_EVENT_NUM; j++)
            {
                if (m_event_data[j].type == EVENT_TOTAL)
                {
                    break;
                }
            }

            ASSERT(j < MAX_EVENT_NUM); // assert if not found

            m_event_data[j].type      = event[i].type;
            m_event_data[j].is_read   = event[i].is_read;
            m_event_data[j].subject   = event[i].subject;
            m_event_data[j].time      = event[i].time;
            m_event_data[j].user_data = event[i].user_data;
            
            m_event[m_num_of_event++] = &m_event_data[j];
        }
        else
        {
            /* Find the event with the smallest time value. */
            EventStruct *min = m_event[0];
            
            for (j = 1; j < m_num_of_event; j++)
            {
                if (min->time.compareWith(m_event[j]->time) == VfxDateTime::GREATER)
                {
                    min = m_event[j];
                }
            }

            /* If the new event's time value is larger than the smallest one, 
               replace the smallest one. */
            if (event[i].time.compareWith(min->time) == VfxDateTime::GREATER)
            {
                min->type      = event[i].type;
                min->is_read   = event[i].is_read;
                min->subject   = event[i].subject;
                min->time      = event[i].time;
                min->user_data = event[i].user_data;

            }
        }
    }

    // sort and emit the signal
    sort_event();
    m_signalEventChanged.emit(this);
}


void VdatRecentEvent::refresh()
{
    if (vadp_v2p_hs_recent_event_is_available())
    {
        // Available. Reset error code and refresh the events.
        m_err = ERR_NONE; 

        // Refresh the data.
        vadp_v2p_hs_recent_event_refresh();
    }
    else
    {
        // TODO: distinguish different error type.
        reset(ERR_SIM_INVALID);

        // Emit the event immediately.
        m_signalEventChanged.emit(this);
    }
}


VdatRecentEvent::ErrEnum VdatRecentEvent::getErr()
{
    return m_err;
}


VfxS32 VdatRecentEvent::getEventNum()
{
    return m_num_of_event;
}


VfxS32 VdatRecentEvent::getEventType(VfxS32 idx)
{
    EXT_ASSERT(idx < m_num_of_event, idx, 0, 0);

    return m_event[idx]->type;
}


VfxBool VdatRecentEvent::getEventIsRead(VfxS32 idx)
{
    EXT_ASSERT(idx < m_num_of_event, idx, 0, 0);

    return m_event[idx]->is_read;
}


VfxWString VdatRecentEvent::getEventSubject(VfxS32 idx)
{
    EXT_ASSERT(idx < m_num_of_event, idx, 0, 0);

    return m_event[idx]->subject;
}


VfxWString VdatRecentEvent::getEventTimeString(VfxS32 idx)
{
    VfxWChar buf[STR_LEN];
    VfxU32 flags;
    
    EXT_ASSERT(idx < m_num_of_event, idx, 0, 0);

    if (isToday(m_event[idx]->time))
    {
        flags = VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE;
    }
    else
    {
        flags = VFX_DATE_TIME_DATE_MASK;
    }
    
    m_event[idx]->time.getDateTimeString(flags, (VfxWChar *)buf, sizeof(buf));
    
    return VFX_WSTR_MEM(buf);
}


VdatRecentEvent::callback_t VdatRecentEvent::getEventCallback(VfxS32 idx)
{
    EXT_ASSERT(idx < m_num_of_event, idx, 0, 0);

    return m_callback[m_event[idx]->type];
}


void *VdatRecentEvent::getEventUserData(VfxS32 idx)
{
    EXT_ASSERT(idx < m_num_of_event, idx, 0, 0);

    return m_event[idx]->user_data;
}

#endif /* __MMI_VUI_HOMESCREEN__ */

