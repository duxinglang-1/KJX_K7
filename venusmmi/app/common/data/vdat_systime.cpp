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
 *  vdat_systime.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vdat_systime.h"

#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vfx_system.h"
#include "vfx_signal.h"


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

extern "C"
void vdat_system_time_changed_handler(void)
{
    if (vfx_sys_get_canvas_state() == VFX_SYS_STATE_UNKNOWN)
    {
        return;
    }

    VdatTimeNotification* systime = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systime->checkTimeEvent();
}

/***************************************************************************** 
 * Class VdatSystemTime
 *****************************************************************************/

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VdatTimeNotification);


VdatTimeNotification::VdatTimeNotification()
{
    m_curTime.setCurrentTime();
}

void VdatTimeNotification::checkTimeEvent()
{
    VfxU32 flag = 0;
    VfxU32 year, month, day;
    VfxU32 hour, minute, second;

    m_curTime.getDate(&year, &month, &day);
    m_curTime.getTime(&hour, &minute, &second);

    m_curTime.setCurrentTime();

    if (year != m_curTime.getYear())
    {
        flag |= ( VDAT_SYSTIME_CHANGED_YEAR | VDAT_SYSTIME_CHANGED_MONTH | 
                  VDAT_SYSTIME_CHANGED_DAY | VDAT_SYSTIME_CHANGED_HOUR | 
                  VDAT_SYSTIME_CHANGED_MIN );
    }
    if (month != m_curTime.getMonth())
    {
        flag |= ( VDAT_SYSTIME_CHANGED_MONTH | VDAT_SYSTIME_CHANGED_DAY | 
                  VDAT_SYSTIME_CHANGED_HOUR | VDAT_SYSTIME_CHANGED_MIN );
    }
    if (day != m_curTime.getDay())
    {
        flag |= ( VDAT_SYSTIME_CHANGED_DAY | VDAT_SYSTIME_CHANGED_HOUR | 
                  VDAT_SYSTIME_CHANGED_MIN );
    }
    if (hour != m_curTime.getHour())
    {
        flag |= ( VDAT_SYSTIME_CHANGED_HOUR | VDAT_SYSTIME_CHANGED_MIN );
    }
    if (minute != m_curTime.getMinute())
    {
        flag |= VDAT_SYSTIME_CHANGED_MIN;
    }

    if (!flag)
    {
        // the notification is from system internal, it is impossible nothing change.
        // It should be something wrong, we invoke event anyway.
        flag |= ( VDAT_SYSTIME_CHANGED_YEAR | VDAT_SYSTIME_CHANGED_MONTH | 
                  VDAT_SYSTIME_CHANGED_DAY | VDAT_SYSTIME_CHANGED_HOUR | 
                  VDAT_SYSTIME_CHANGED_MIN );
    }
    m_signalTimeChanged.emit(flag);
}


void VdatTimeNotification::reset()
{
    m_curTime.setCurrentTime();
}

