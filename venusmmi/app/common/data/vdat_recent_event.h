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
 *  vdat_recent_event.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the header for the service data of recent events.
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
#ifndef __VDAT_RECENT_EVENT_H__
#define __VDAT_RECENT_EVENT_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN__

#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_string.h"
#include "vfx_date_time.h"
#include "vfx_signal.h"

/*
 * Recent Event Class
 */
class VdatRecentEvent : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VdatRecentEvent);

public:
    typedef void (*callback_t)(VfxU16 key_code, VfxU16 key_type, void *user_data);
    
    typedef enum
    {
        EVENT_CALL,
        EVENT_CALL2,
        EVENT_SMS,
        EVENT_MMS,
        EVENT_TOTAL
    } EventTypeEnum;

    typedef enum
    {
        ERR_NONE,
        ERR_SIM_INVALID,
        ERR_TOTAL
    } ErrEnum;
    
    class EventStruct : public VfxBase
    {
    public:
        EventTypeEnum    type;
        VfxBool          is_read;
        VfxWString       subject;
        VfxDateTime      time;
        void            *user_data;
    };
    
public:
    VdatRecentEvent();

    void refresh();

    VfxS32 getEventNum();
    
    ErrEnum     getErr();
    VfxS32      getEventType(VfxS32 idx);
    VfxBool     getEventIsRead(VfxS32 idx);
    VfxWString  getEventSubject(VfxS32 idx);
    VfxWString  getEventTimeString(VfxS32 idx);
    callback_t  getEventCallback(VfxS32 idx);
    void       *getEventUserData(VfxS32 idx);
    
    void processEventCleared(EventTypeEnum type);
    void processEventChanged(EventTypeEnum type, callback_t cbf);
    void processEventChanged(VfxS32 num, EventStruct *event);
    
    VfxSignal1 <VdatRecentEvent *> m_signalEventChanged;

private:
    enum
    {
        STR_LEN       = 64,
        MAX_EVENT_NUM = 10
    };
    
    VfxS32           m_num_of_event;
    ErrEnum          m_err;
    EventStruct      m_event_data[MAX_EVENT_NUM];
    EventStruct     *m_event[MAX_EVENT_NUM];
    callback_t       m_callback[EVENT_TOTAL];

    void reset(ErrEnum err);
    
    int compare(const EventStruct *a, const EventStruct *b);
    void sort_event();

    VfxBool isToday(VfxDateTime &time);
};

#endif /* __MMI_VUI_HOMESCREEN__ */
#endif /* __VDAT_RECENT_EVENT_H__ */

