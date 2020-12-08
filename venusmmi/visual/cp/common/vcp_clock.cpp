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
 *  vcp_date_time.cpp
 *
 * Project:
 * --------
 *  Venus UI Component
 *
 * Description:
 * ------------
 *  UI component used to display date and time
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "data\vdat_systime.h"
#include "vcp_clock.h"

#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_signal.h"
#include "vrt_datatype.h"
#include "vrt_system.h"
#include "vfx_transform.h"

#ifdef __cplusplus
extern "C"
{
#include "wgui_categories_res.h"
#include "kal_release.h"
#include "kal_general_types.h"
#include "mmi_rp_app_uiframework_def.h"
#include "MMIDataType.h"
}
#endif 

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Static Variable
 *****************************************************************************/
VfxTimer *VcpClock::s_timer = NULL;
VcpClock *VcpClock::s_headClock = NULL;

/* Is the sin table used to calculate clock hand */
static const VfxFloat acm_sine_table[] = 
{
    (VfxFloat) -0.99999820, (VfxFloat) -0.99431727, (VfxFloat) -0.97773360, (VfxFloat) -0.95042917,
    (VfxFloat) -0.91270313, (VfxFloat) -0.86496924, (VfxFloat) -0.80775119, (VfxFloat) -0.74167587,
    (VfxFloat) -0.66746803, (VfxFloat) -0.58594175, (VfxFloat) -0.49799022, (VfxFloat) -0.40457821,
    (VfxFloat) -0.30673042, (VfxFloat) -0.20551889, (VfxFloat) -0.10205382, (VfxFloat)  0.00000000,
    (VfxFloat)  0.10457040, (VfxFloat)  0.20799418, (VfxFloat)  0.30913729, (VfxFloat)  0.40689072,
    (VfxFloat)  0.50018258, (VfxFloat)  0.58798990, (VfxFloat)  0.66934994, (VfxFloat)  0.74337050,
    (VfxFloat)  0.80923998, (VfxFloat)  0.86623616, (VfxFloat)  0.91373403, (VfxFloat)  0.95121274,
    (VfxFloat)  0.97826142, (VfxFloat)  0.99458343, (VfxFloat)  0.99999980, (VfxFloat)  0.99445115,
    (VfxFloat)  0.97799831, (VfxFloat)  0.95082172, (VfxFloat)  0.91321931, (VfxFloat)  0.86560342,
    (VfxFloat)  0.80849624, (VfxFloat)  0.74252372, (VfxFloat)  0.66840956, (VfxFloat)  0.58696629,
    (VfxFloat)  0.49908672, (VfxFloat)  0.40573486, (VfxFloat)  0.30793410, (VfxFloat)  0.20675662,
    (VfxFloat)  0.10331227, (VfxFloat) -0.00126490, (VfxFloat) -0.10582843, (VfxFloat) -0.20923132,
    (VfxFloat) -0.31033998, (VfxFloat) -0.40804598, (VfxFloat) -0.50127753, (VfxFloat) -0.58901256,
    (VfxFloat) -0.67028925, (VfxFloat) -0.74421601, (VfxFloat) -0.80998244, (VfxFloat) -0.86686752,
    (VfxFloat) -0.91424734, (VfxFloat) -0.95160225, (VfxFloat) -0.97852297, (VfxFloat) -0.99471414
};
/* Is the cosine table used to calculate clock hand */
static const VfxFloat acm_cosine_table[] = 
{
    (VfxFloat)  0.00189735, (VfxFloat)  0.10645731, (VfxFloat)  0.20984996, (VfxFloat)  0.31094114,
    (VfxFloat)  0.40862330, (VfxFloat)  0.50182489, (VfxFloat)  0.58952354, (VfxFloat)  0.67075845,
    (VfxFloat)  0.74463846, (VfxFloat)  0.81035318, (VfxFloat)  0.86718264, (VfxFloat)  0.91450340,
    (VfxFloat)  0.95179643, (VfxFloat)  0.97865315, (VfxFloat)  0.99477888, (VfxFloat)  1.00000000,
    (VfxFloat)  0.99451749, (VfxFloat)  0.97813006, (VfxFloat)  0.95101742, (VfxFloat)  0.91347684,
    (VfxFloat)  0.86591997, (VfxFloat)  0.80886827, (VfxFloat)  0.74294728, (VfxFloat)  0.66887989,
    (VfxFloat)  0.58747821, (VfxFloat)  0.49963478, (VfxFloat)  0.40631283, (VfxFloat)  0.30853576,
    (VfxFloat)  0.20737548, (VfxFloat)  0.10394131, (VfxFloat) -0.00063245, (VfxFloat) -0.10519940,
    (VfxFloat) -0.20861283, (VfxFloat) -0.30973870, (VfxFloat) -0.40746839, (VfxFloat) -0.50073018,
    (VfxFloat) -0.58850135, (VfxFloat) -0.66981977, (VfxFloat) -0.74379342, (VfxFloat) -0.80961137,
    (VfxFloat) -0.86655204, (VfxFloat) -0.91399082, (VfxFloat) -0.95140769, (VfxFloat) -0.97839241,
    (VfxFloat) -0.99464897, (VfxFloat) -0.99999920, (VfxFloat) -0.99438440, (VfxFloat) -0.97786617,
    (VfxFloat) -0.95062563, (VfxFloat) -0.91296138, (VfxFloat) -0.86528656, (VfxFloat) -0.80812388,
    (VfxFloat) -0.74209994, (VfxFloat) -0.66793902, (VfxFloat) -0.58645414, (VfxFloat) -0.49853857,
    (VfxFloat) -0.40515651, (VfxFloat) -0.30733233, (VfxFloat) -0.20613779, (VfxFloat) -0.10268295
};

/***************************************************************************** 
 * Global function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  VcpClock::VcpClock
 * DESCRIPTION
 *  Constructor of clock class.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VcpClock::VcpClock() :
    m_autoUpdate(VFX_FALSE),
    m_nextClock(NULL)
{
}


/*****************************************************************************
 * FUNCTION
 *  VcpClock::setTime
 * DESCRIPTION
 *  Set current system time as clock object's start relative time.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpClock::setTime()
{
    m_startRelTime.setCurrentTime();
    m_currentRelTime = m_startRelTime;
    invalidate();
}


/*****************************************************************************
 * FUNCTION
 *  VcpClock::setTime
 * DESCRIPTION
 *  Set given time as clock object's start relative time.
 * PARAMETERS
 *  startTime          [IN] Is the reference of start time.
 * RETURNS
 *  void
 *****************************************************************************/
void VcpClock::setTime(const VfxDateTime &startTime)
{
    m_startRelTime = startTime;
    m_currentRelTime = m_startRelTime;

    VfxDateTime result;
    m_currentRelTime.increase(result);

    invalidate();
}


/*****************************************************************************
 * FUNCTION
 *  VcpClock::setUpdateInterval
 * DESCRIPTION
 *  Set update interval to clock object.
 * PARAMETERS
 *  setUpdateInterval          [IN] Is the reference of update interval.
 * RETURNS
 *  void
 *****************************************************************************/
void VcpClock::setUpdateInterval(const VfxDateTime &updateInterval)
{
    m_updateInterval = updateInterval;
}


/*****************************************************************************
 * FUNCTION
 *  VcpClock::startClock
 * DESCRIPTION
 *  Start the update of clock.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpClock::startClock(void)
{
    m_startSysTime.setCurrentTime();
    m_autoUpdate = VFX_TRUE;

    /* connect the clock to static timer */
    if (s_timer == NULL)
    {
        VFX_OBJ_CREATE(s_timer, VfxTimer, VFX_SYS_GLOBAL_CONTEXT);
        /* create the head node of clock link */
        s_headClock = this;
        s_timer->setStartDelay(START_DELAY);
        /* Always use 1 second as the duration of timer. */
        s_timer->setDuration(UPDATE_INTERVAL);
        s_timer->m_signalTick.connect(this, &VcpClock::onTimerTick);
        s_timer->start();
    }
    else
    {
        VcpClock *temp_clock = s_headClock;
        /* Search clock link to check whether it is in clock link */
        while(temp_clock != this && temp_clock != NULL)
        {
            temp_clock = temp_clock->m_nextClock;
        }
        if (temp_clock == NULL)
        {
            m_nextClock = s_headClock;
            s_headClock = this;
            s_timer->m_signalTick.connect(this, &VcpClock::onTimerTick);
        }
    }
}
void VcpClock::suspendClock(void)
{
    s_timer->m_signalTick.disconnect(this, &VcpClock::onTimerTick);
}
void VcpClock::resumeClock(void)
{
    s_timer->m_signalTick.connect(this, &VcpClock::onTimerTick);
    timeOut();
}

/*****************************************************************************
 * FUNCTION
 *  VcpClock::onInit
 * DESCRIPTION
 *  Initialize clock class.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpClock::onInit()
{
    // Connect signal to refresh the recent event time string.
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VcpClock::onSystemTimeChanged);

    VfxControl::onInit();
}


/*****************************************************************************
 * FUNCTION
 *  VcpClock::onDeinit
 * DESCRIPTION
 *  Deinitialize clock class.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpClock::onDeinit()
{
    VcpClock *current_clock = NULL, *pre_clock = NULL;

    /* If clock object is in clock's link, delete this clock */
    if (m_autoUpdate == VFX_TRUE)
    {
        VFX_ASSERT(s_headClock != NULL);
        current_clock = s_headClock;

        /* search the link to find delete clock */
        while (current_clock != this && current_clock->m_nextClock != NULL)
        {
            pre_clock = current_clock;
            current_clock = current_clock->m_nextClock;
        }

        if (current_clock == this)
        {
            if (current_clock == s_headClock)
            {
                s_headClock = current_clock->m_nextClock;
            }
            else
            {
                pre_clock->m_nextClock = current_clock->m_nextClock;
                current_clock->m_nextClock = NULL;
            }
            s_timer->m_signalTick.disconnect(this, &VcpClock::onTimerTick);

            if (s_headClock == NULL)
            {
                VFX_OBJ_CLOSE(s_timer);
            }
        }
        else
        {
            VFX_ASSERT(0);
        }
    }

    // Disconnect system time signal
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.disconnect(this, &VcpClock::onSystemTimeChanged);

    VfxControl::onDeinit();
}


/*****************************************************************************
 * FUNCTION
 *  VcpClock::onTimerTick
 * DESCRIPTION
 *  Handle the timer tick event.
 * PARAMETERS
 *  source          [IN] Is the pointer of timer object
 * RETURNS
 *  void
 *****************************************************************************/
void VcpClock::onTimerTick(VfxTimer *source)
{
    VFX_UNUSED(source);
    timeOut();
}


/*****************************************************************************
 * FUNCTION
 *  VcpClock::needUpdate
 * DESCRIPTION
 *  Whether clock need to update time or not.
 * PARAMETERS
 *  currentRelTime      [IN] Is the referenct of current relative time.
 * RETURNS
 *  VfxBool
 *****************************************************************************/
VfxBool VcpClock::needUpdate(VfxDateTime &currentRelTime)
{
    if (m_updateInterval.getYear() > 0)
    {
        if (currentRelTime.getYear() != m_currentRelTime.getYear())
        {
            return VFX_TRUE;
        }
        return VFX_FALSE;
    }
    else if (m_updateInterval.getMonth() > 0)
    {
        if (currentRelTime.getMonth() != m_currentRelTime.getMonth())
        {
            return VFX_TRUE;
        }
        return VFX_FALSE;
    }
    else if (m_updateInterval.getDay() > 0)
    {
        if (currentRelTime.getDay() != m_currentRelTime.getDay())
        {
            return VFX_TRUE;
        }
        return VFX_FALSE;
    }
    else if (m_updateInterval.getHour() > 0)
    {
        if (currentRelTime.getHour() != m_currentRelTime.getHour())
        {
            return VFX_TRUE;
        }
        return VFX_FALSE;
    }
    else if (m_updateInterval.getMinute() > 0)
    {
        if (currentRelTime.getMinute() != m_currentRelTime.getMinute())
        {
            return VFX_TRUE;
        }
        return VFX_FALSE;
    }
    else if (m_updateInterval.getSecond() > 0)
    {
        VfxDateTime result;
        VfxDateTime::CompareEnum compare_result;

        currentRelTime.getDiff(m_currentRelTime, result);
        compare_result = result.compareWith(m_updateInterval);
        if (compare_result != VfxDateTime::LESS)
        {
            return VFX_TRUE;
        }
        return VFX_FALSE;
    }
    else
    {
        return VFX_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  VcpClock::timeOut
 * DESCRIPTION
 *  Handle the time out event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpClock::timeOut()
{
    VfxDateTime current_rel_time, temp_time, result;
    VfxDateTime::CompareEnum compare_result;


    /* get the difference between current system time and start system time */
    temp_time.setCurrentTime();
    compare_result = temp_time.getDiff(m_startSysTime, result);

    /* calculate the current relative time */
    current_rel_time = m_startRelTime;
    if (compare_result == VfxDateTime::GREATER)
    {
        current_rel_time.increase(result);
    }
    else
    {
        current_rel_time.decrease(result);
    }
    
    if ((m_autoUpdate == VFX_TRUE) && needUpdate(current_rel_time))
    {
        m_currentRelTime = current_rel_time;
        invalidate();
    }
}


/*****************************************************************************
 * FUNCTION
 *  VcpClock::convertUpdateInterval
 * DESCRIPTION
 *  Convert the update interval to millisecond.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 VcpClock::convertUpdateInterval(const VfxDateTime &updateInterval)
{
    VfxU32 hour, minute, second;
    VfxS32 result;

    updateInterval.getTime(&hour, &minute, &second);
    if (updateInterval.isValidTime())
    {
        result = ((hour * 60 + minute) * 60 + second) * 1000;
    }
    else
    {
        /* use 1 day as default update interval */
        result = 24 * 60 * 60 * 1000;
    }
    return result;    
}


void VcpClock::onSystemTimeChanged(VfxU32 flag)
{
    if ((flag & VDAT_SYSTIME_CHANGED_MIN) && (m_autoUpdate == VFX_TRUE))
    {
        timeOut();
    }
}


#ifdef __MMI_VUI_COSMOS_CP_SLIM__
/*****************************************************************************
 * FUNCTION
 *  VcpDurationClock::VcpDurationClock
 * DESCRIPTION
 *  Constructor of duration clock class.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VcpDurationClock::VcpDurationClock() :
    m_textColor(VFX_COLOR_WHITE),
    m_textBorderColor(VFX_COLOR_BLACK)
{
    m_font = VfxFontDesc(g_vfxFontMedium);
}


const VfxColor &VcpDurationClock::getTextColor() const
{
    return m_textColor;
}


const VfxColor &VcpDurationClock::getTextBorderColor() const
{
    return m_textBorderColor;
}


void VcpDurationClock::setTextColor(const VfxColor &value)
{
    m_textColor = value;
    
    invalidate();
}


void VcpDurationClock::setTextBorderColor(const VfxColor &value)
{
    m_textBorderColor = value;

    invalidate();
}


/*****************************************************************************
 * FUNCTION
 *  VcpDurationClock::onInit
 * DESCRIPTION
 *  Init duration clock class.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDurationClock::onInit()
{
    VfxDateTime temp;
    VfxRect bounds;
    VfxSize tempSize;

    VcpClock::onInit();
    bounds = getBounds();
    tempSize = onMeasureMinSize();
    if (bounds.size.width < tempSize.width || bounds.size.height < tempSize.height)
    {
        if (bounds.size.height < tempSize.height)
        {
            bounds.size.height = tempSize.height;
        }
        if (bounds.size.width < tempSize.width)
        {
            bounds.size.width = tempSize.width;
        }
        setBounds(bounds);
    }

    temp.setTime(0, 0, 1);
    setUpdateInterval(temp);
    temp.setTime(0, 0, 0);
    setTime(temp);
}


/*****************************************************************************
 * FUNCTION
 *  VcpDurationClock::onDeinit
 * DESCRIPTION
 *  Deinit duration clock class.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDurationClock::onDeinit()
{
    VcpClock::onDeinit();
}


/*****************************************************************************
 * FUNCTION
 *  VcpDurationClock::setFont
 * DESCRIPTION
 *  Set font to duration clock class.
 * PARAMETERS
 *  font
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDurationClock::setFont(const VfxFontDesc &font)
{
    VfxRect bounds;
    VfxSize tempSize;
    m_font = font;
    bounds = getBounds();
    tempSize = onMeasureMinSize();
    if (bounds.size.width < tempSize.width || bounds.size.height < tempSize.height)
    {
        if (bounds.size.height < tempSize.height)
        {
            bounds.size.height = tempSize.height;
        }
        if (bounds.size.width < tempSize.width)
        {
            bounds.size.width = tempSize.width;
        }
        setBounds(bounds);
    }
}


/*****************************************************************************
 * FUNCTION
 *  VcpDurationClock::onDraw
 * DESCRIPTION
 *  Draw the duration clock.
 * PARAMETERS
 *  dc              [IN]  Is a reference of draw context class
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDurationClock::onDraw(VfxDrawContext &dc)
{
    VfxU32 flags;
    static VfxWChar string_buf[STRING_LENGTH_MAX];
    VfxSize size, temp;
    VfxPoint pos;

    flags = VFX_DATE_TIME_DURATION_FULL_FORMAT;
    m_currentRelTime.getDateTimeString(flags, string_buf, STRING_LENGTH_MAX);

    /* Draw the duration string */
    dc.setFont(m_font);
    dc.setFillColor(getTextColor());
    if (m_font.effect == VFX_FONT_DESC_EFFECT_BORDER)
    {
        dc.setStrokeColor(getTextBorderColor());
    }
    size = (getBounds()).size;
    temp = m_font.measureStr(string_buf);
    pos.x = (size.width - temp.width) / 2;
    pos.y = (size.height - temp.height) / 2;
    if (pos.x < 0)
    {
        pos.x = 0;
    }
    if (pos.y < 0)
    {
        pos.y = 0;
    }
    dc.drawText(pos.x, pos.y, string_buf);
}


/*****************************************************************************
 * FUNCTION
 *  VcpDurationClock::onMeasureMinSize
 * DESCRIPTION
 *  Measure the min display size of duration clock.
 * PARAMETERS
 *  size              [IN]  Is the pointer of parameter to get size
 * RETURNS
 *  void
 *****************************************************************************/
VfxSize VcpDurationClock::onMeasureMinSize()
{
    vrt_size_struct size;
    VfxWChar string_buf[STRING_LENGTH_MAX];

    m_currentRelTime.getDateTimeString(
        VFX_DATE_TIME_DURATION_FULL_FORMAT,
        string_buf,
        STRING_LENGTH_MAX);
    size = m_font.measureStr(string_buf);
    return (VfxSize(size.width, size.height));
}
#endif /* __MMI_VUI_COSMOS_CP_SLIM__ */


/*****************************************************************************
 * FUNCTION
 *  VcpDigitalTextClock::VcpDigitalTextClock
 * DESCRIPTION
 *  Constructor of digital text clock class.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VcpDigitalTextClock::VcpDigitalTextClock() :
    m_formatFlags(0),
    m_font(VFX_FONT_DESC_MEDIUM),
    m_isBoundsAutoMinmize(VFX_FALSE),
    m_textColor(VFX_COLOR_WHITE),
    m_textBorderColor(VFX_COLOR_BLACK)    
{
    m_alignMode = ALIGN_MODE_CENTER;
}


const VfxColor &VcpDigitalTextClock::getTextColor() const
{
    return m_textColor;
}


const VfxColor &VcpDigitalTextClock::getTextBorderColor() const
{
    return m_textBorderColor;
}


void VcpDigitalTextClock::setTextColor(const VfxColor &value)
{
    m_textColor = value;

    invalidate();
}


void VcpDigitalTextClock::setTextBorderColor(const VfxColor &value)
{
    m_textBorderColor = value;

    invalidate();
}


/*****************************************************************************
 * FUNCTION
 *  VcpDigitalTextClock::onInit
 * DESCRIPTION
 *  Init digital text clock class.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDigitalTextClock::onInit()
{
    VfxDateTime updateInterval;
    VfxRect bounds;
    VfxSize tempSize;

    VcpClock::onInit();

    m_formatFlags = VFX_DATE_TIME_DATE_YEAR |
                     VFX_DATE_TIME_DATE_MONTH |
                     VFX_DATE_TIME_DATE_DAY |
                     VFX_DATE_TIME_TIME_HOUR |
                     VFX_DATE_TIME_TIME_MINUTE |
                     VFX_DATE_TIME_DAY_SHORT_NAME;

    bounds = getBounds();
    tempSize = onMeasureMinSize();
    if (bounds.size.width < tempSize.width || bounds.size.height < tempSize.height)
    {
        if (bounds.size.height < tempSize.height)
        {
            bounds.size.height = tempSize.height;
        }
        if (bounds.size.width < tempSize.width)
        {
            bounds.size.width = tempSize.width;
        }
        setBounds(bounds);
    }

    updateInterval.setTime(0, 1, 0);
    setUpdateInterval(updateInterval);
}


/*****************************************************************************
 * FUNCTION
 *  VcpDigitalTextClock::onDeinit
 * DESCRIPTION
 *  Deinit digital text clock class.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDigitalTextClock::onDeinit()
{
    VcpClock::onDeinit();
}


/*****************************************************************************
 * FUNCTION
 *  VcpDigitalTextClock::setFont
 * DESCRIPTION
 *  Set font to digital text clock class.
 * PARAMETERS
 *  font
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDigitalTextClock::setFont(const VfxFontDesc &font)
{
    VfxRect bounds;
    VfxSize tempSize;
    m_font = font;
    bounds = getBounds();
    tempSize = onMeasureMinSize();
    if (bounds.size.width < tempSize.width || bounds.size.height < tempSize.height)
    {
        if (bounds.size.height < tempSize.height)
        {
            bounds.size.height = tempSize.height;
        }
        if (bounds.size.width < tempSize.width)
        {
            bounds.size.width = tempSize.width;
        }
        setBounds(bounds);
    }
}


/*****************************************************************************
 * FUNCTION
 *  VcpDigitalTextClock::setAlignMode
 * DESCRIPTION
 *  Set align mode to digital text clock class.
 * PARAMETERS
 *  align mode
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDigitalTextClock::setAlignMode(const VcpDigitalTextAlignModeEnum &alignMode)
{
    m_alignMode = alignMode;
}


/*****************************************************************************
 * FUNCTION
 *  VcpDigitalTextClock::setFormatFlags
 * DESCRIPTION
 *  Set the date-time format flags to clock object.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDigitalTextClock::setFormatFlags(VfxU32 formatFlags)
{
    VfxRect bounds;
    VfxSize tempSize;
    m_formatFlags = formatFlags;
    bounds = getBounds();
    tempSize = onMeasureMinSize();
    if (bounds.size.width < tempSize.width || bounds.size.height < tempSize.height)
    {
        if (bounds.size.height < tempSize.height)
        {
            bounds.size.height = tempSize.height;
        }
        if (bounds.size.width < tempSize.width)
        {
            bounds.size.width = tempSize.width;
        }
        setBounds(bounds);
    }
}


/*****************************************************************************
 * FUNCTION
 *  VcpDigitalTextClock::onDraw
 * DESCRIPTION
 *  Draw the digital text clock.
 * PARAMETERS
 *  dc              [IN]  Is a reference of draw context class
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDigitalTextClock::onDraw(VfxDrawContext &dc)
{
    VfxWChar string_buf[STRING_LENGTH_MAX];
    VfxRect bounds;
    VfxSize temp;
    vrt_point_struct pos;

    m_currentRelTime.getDateTimeString(m_formatFlags, string_buf, STRING_LENGTH_MAX);

    /* Draw the digital test string */
    dc.setFont(m_font);
    dc.setFillColor(getTextColor());
    if (m_font.effect == VFX_FONT_DESC_EFFECT_BORDER)
    {
        dc.setStrokeColor(getTextBorderColor());
    }
    bounds = getBounds();
    if (VFX_TRUE == m_isBoundsAutoMinmize)
    {
        VfxSize tempSize;
        tempSize = onMeasureMinSize();
        bounds.size.width = tempSize.width;
        bounds.size.height = tempSize.height;
        setBounds(bounds);
    }

    temp = m_font.measureStr(VFX_WSTR_MEM(string_buf));
    pos.y = (bounds.getHeight() - temp.height) / 2;

    if (m_alignMode == ALIGN_MODE_RIGHT)
    {
        pos.x = bounds.getWidth() - temp.width;
    }
    else if (m_alignMode == ALIGN_MODE_LEFT)
    {
        pos.x = 0;
    }
    else
    {
        pos.x = (bounds.getWidth() - temp.width) / 2;
    }
    if (vrt_sys_get_text_dir() == MG_TEXT_DIR_TYPE_R2L)
    {
        pos.x = pos.x + temp.width - 1;
    }
    if (pos.x < 0)
    {
        pos.x = 0;
    }
    if (pos.y < 0)
    {
        pos.y = 0;
    }
    dc.drawText(pos.x, pos.y, string_buf);
}


/*****************************************************************************
 * FUNCTION
 *  VcpDigitalTextClock::onMeasureMinSize
 * DESCRIPTION
 *  Measure the min display size of digital text clock.
 * PARAMETERS
 *  size              [IN]  Is the pointer of parameter to get size
 * RETURNS
 *  void
 *****************************************************************************/
VfxSize VcpDigitalTextClock::onMeasureMinSize()
{
    VfxSize size;

    VfxWChar string_buf[STRING_LENGTH_MAX];

    m_currentRelTime.getDateTimeString(
        m_formatFlags,
        string_buf,
        STRING_LENGTH_MAX);
    size = m_font.measureStr(VFX_WSTR_MEM(string_buf));
    return size;
}


/*****************************************************************************
 * FUNCTION
 *  VcpDigitalTextClock::setBoundsAutoMinmize
 * DESCRIPTION
 *  Set whether auto minmize the bounds or not.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDigitalTextClock::setBoundsAutoMinmize(VfxBool value)
{
    if (m_isBoundsAutoMinmize != value)
    {
        m_isBoundsAutoMinmize = value;
        if (value)
        {
            VfxRect bounds;
            VfxSize tempSize;
            tempSize = onMeasureMinSize();
            bounds.size.height = tempSize.height;
            bounds.size.width = tempSize.width;
            setBounds(bounds);
        }
        
    }
}


/*****************************************************************************
 * FUNCTION
 *  VcpAnalogClock::VcpAnalogClock
 * DESCRIPTION
 *  Constructor of analog clock class.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VcpAnalogClock::VcpAnalogClock() :
    m_hourHandColor(VFX_COLOR_BLACK),
    m_minuteHandColor(VFX_COLOR_BLACK),
    m_secondHandColor(VFX_COLOR_TRANSPARENT),
    m_hourHandRadius(0),
    m_minuteHandRadius(0),
    m_secondHandRadius(0),
    m_hourHandRadiusOffset(0),
    m_minuteHandRadiusOffset(0),
    m_secondHandRadiusOffset(0),
    m_center(0, 0),
    m_clockBackground(NULL),
    m_clockBackgroundImage(NULL),
    m_frameCustom(NULL),
    m_hourHandImage(NULL),
    m_minuteHandImage(NULL),
    m_secondHandImage(NULL),
    m_hourHandEndImage(NULL),
    m_minuteHandEndImage(NULL),
    m_secondHandEndImage(NULL),
    m_axisImage(NULL),
    m_clockCover(NULL)
{
}


const VfxColor &VcpAnalogClock::getHourHandColor() const
{
    return m_hourHandColor;
}


const VfxColor &VcpAnalogClock::getMinuteHandColor() const
{
    return m_minuteHandColor;
}


const VfxColor &VcpAnalogClock::getSecondHandColor() const
{
    return m_secondHandColor;
}


VfxS32 VcpAnalogClock::getHourHandRadius() const
{
    return m_hourHandRadius;
}


VfxS32 VcpAnalogClock::getMinuteHandRadius() const
{
    return m_minuteHandRadius;
}


VfxS32 VcpAnalogClock::getSecondHandRadius() const
{
    return m_secondHandRadius;
}


VfxS32 VcpAnalogClock::getHourHandRadiusOffset() const
{
    return m_hourHandRadiusOffset;
}


VfxS32 VcpAnalogClock::getMinuteHandRadiusOffset() const
{
    return m_minuteHandRadiusOffset;
}


VfxS32 VcpAnalogClock::getSecondHandRadiusOffset() const
{
    return m_secondHandRadiusOffset;
}


const VfxPoint &VcpAnalogClock::getCenter() const
{
    return m_center;
}

    
void VcpAnalogClock::setHourHandColor(const VfxColor &value)
{
    m_hourHandColor = value;

    invalidate();
}


void VcpAnalogClock::setMinuteHandColor(const VfxColor &value)
{
    m_minuteHandColor = value;

    invalidate();
}


void VcpAnalogClock::setSecondHandColor(const VfxColor &value)
{
    m_secondHandColor = value;

    invalidate();
}


void VcpAnalogClock::setHourHandRadius(VfxS32 value)
{
    m_hourHandRadius = value;

    invalidate();
}


void VcpAnalogClock::setMinuteHandRadius(VfxS32 value)
{
    m_minuteHandRadius = value;

    invalidate();
}


void VcpAnalogClock::setSecondHandRadius(VfxS32 value)
{
    m_secondHandRadius = value;

    invalidate();
}


void VcpAnalogClock::setHourHandRadiusOffset(VfxS32 value)
{
    m_hourHandRadiusOffset = value;

    invalidate();
}


void VcpAnalogClock::setMinuteHandRadiusOffset(VfxS32 value)
{
    m_minuteHandRadiusOffset = value;

    invalidate();
}


void VcpAnalogClock::setSecondHandRadiusOffset(VfxS32 value)
{
    m_secondHandRadiusOffset = value;

    invalidate();
}


void VcpAnalogClock::setCenter(const VfxPoint &value)
{
    m_center = value;

    /* update the position of every clock hand */
    if (m_hourHandImage->getHidden() == VFX_FALSE)
    {
        setClockHourHand(m_hourHandImage->getResId());
    }
    if (m_minuteHandImage->getHidden() == VFX_FALSE)
    {
        setClockMinuteHand(m_minuteHandImage->getResId());
    }
    if (m_secondHandImage->getHidden() == VFX_FALSE)
    {
        setClockSecondHand(m_secondHandImage->getResId());
    }
    if (m_hourHandEndImage->getHidden() == VFX_FALSE)
    {
        setClockHourHandEnd(m_hourHandEndImage->getResId());
    }
    if (m_minuteHandEndImage->getHidden() == VFX_FALSE)
    {
        setClockMinuteHandEnd(m_minuteHandEndImage->getResId());
    }
    if (m_secondHandEndImage->getHidden() == VFX_FALSE)
    {
        setClockSecondHandEnd(m_secondHandEndImage->getResId());
    }
    if (m_axisImage->getHidden() == VFX_FALSE)
    {
        setClockAxis(m_axisImage->getResId());
    }
    if (m_clockCover->getHidden() == VFX_FALSE)
    {
        setClockCover(m_clockCover->getResId());
    }

    invalidate();
}


/*****************************************************************************
 * FUNCTION
 *  VcpAnalogClock::onInit
 * DESCRIPTION
 *  Init analog clock class.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpAnalogClock::onInit()
{
    VfxDateTime updateInterval;
    VfxRect bounds;

    VcpClock::onInit();
    
    setHourHandRadius(20);
    setMinuteHandRadius(30);
    setHourHandRadiusOffset(3);
    setMinuteHandRadiusOffset(3);

    VFX_OBJ_CREATE(m_clockBackgroundImage, VfxImageFrame, this);
    m_clockBackgroundImage->setHidden(VFX_TRUE);
    VFX_OBJ_CREATE(m_frameCustom, VfxFrame, this);
    m_frameCustom->setHidden(VFX_TRUE);
    /* create image frames of hour, minute, second hands */
    VFX_OBJ_CREATE(m_hourHandImage, VfxImageFrame, this);
    m_hourHandImage->setHidden(VFX_TRUE);
    VFX_OBJ_CREATE(m_minuteHandImage, VfxImageFrame, this);
    m_minuteHandImage->setHidden(VFX_TRUE);
    VFX_OBJ_CREATE(m_secondHandImage, VfxImageFrame, this);
    m_secondHandImage->setHidden(VFX_TRUE);
    VFX_OBJ_CREATE(m_hourHandEndImage, VfxImageFrame, this);
    m_hourHandEndImage->setHidden(VFX_TRUE);
    VFX_OBJ_CREATE(m_minuteHandEndImage, VfxImageFrame, this);
    m_minuteHandEndImage->setHidden(VFX_TRUE);
    VFX_OBJ_CREATE(m_secondHandEndImage, VfxImageFrame, this);
    m_secondHandEndImage->setHidden(VFX_TRUE);
    VFX_OBJ_CREATE(m_axisImage, VfxImageFrame, this);
    m_axisImage->setHidden(VFX_TRUE);
	VFX_OBJ_CREATE(m_clockCover, VfxImageFrame, this);
    m_clockCover->setHidden(VFX_TRUE);
    setIsCached(VFX_TRUE);

    setCenter(VfxPoint(47, 47));
    m_clockBackground = vrt_sys_res_image_lock(IMG_ID_VENUS_ANALOG_IMAGE_CLOCK_BACKGROUND);

    bounds = getBounds();
    setBounds(VfxRect(bounds.origin, onMeasureMinSize()));

    updateInterval.setTime(0, 0, 1);
    setUpdateInterval(updateInterval);
}


/*****************************************************************************
 * FUNCTION
 *  VcpAnalogClock::onDeinit
 * DESCRIPTION
 *  Deinit analog clock class.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpAnalogClock::onDeinit()
{
    VcpClock::onDeinit();
}


/*****************************************************************************
 * FUNCTION
 *  VcpAnalogClock::setFrameCustom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
void VcpAnalogClock::setFrameCustom(VfxFrame *f)
{
    VFX_OBJ_ASSERT_VALID(f);

    replaceChildFrameWith(m_frameCustom, f);
    
    VFX_OBJ_CLOSE(m_frameCustom);
    
    m_frameCustom = f;
}


/*****************************************************************************
 * FUNCTION
 *  VcpAnalogClock::getFrameCustom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
VfxFrame * VcpAnalogClock::getFrameCustom()
{
    return m_frameCustom;
}


/*****************************************************************************
 * FUNCTION
 *  VcpAnalogClock::getFrameCustom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
VfxImageFrame * VcpAnalogClock::getHourHandImageFrame()
{
    return m_hourHandImage;
}

/*****************************************************************************
 * FUNCTION
 *  VcpAnalogClock::getFrameCustom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
VfxImageFrame * VcpAnalogClock::getMinuteHandImageFrame()
{
    return m_minuteHandImage;
}

/*****************************************************************************
 * FUNCTION
 *  VcpAnalogClock::getFrameCustom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
VfxImageFrame * VcpAnalogClock::getSecondHandImageFrame()
{
    return m_secondHandImage;
}

/*****************************************************************************
 * FUNCTION
 *  VcpAnalogClock::setClockBackground
 * DESCRIPTION
 *  Set the background image of analog clock.
 * PARAMETERS
 *  background           [IN] Is the background image.
 * RETURNS
 *  void
 *****************************************************************************/
void VcpAnalogClock::setClockBackground(VfxU8 *background)
{
    VfxRect bounds;
    bounds = getBounds();
    m_clockBackground = background;
    setBounds(VfxRect(bounds.origin, onMeasureMinSize()));
}


/*****************************************************************************
 * FUNCTION
 *  VcpAnalogClock::setClockBackgroundImage
 * DESCRIPTION
 *  Set the background image of analog clock.
 * PARAMETERS
 *  cover           [IN] Is the cover image.
 * RETURNS
 *  void
 *****************************************************************************/
void VcpAnalogClock::setClockBackgroundImage(VfxS32 background)
{
    m_clockBackgroundImage->setResId(background);

    VfxRect bounds = m_clockBackgroundImage->getBounds();
    setBounds(bounds);

    m_clockBackgroundImage->setAnchor(VfxFPoint(0.5, 0.5));
    m_clockBackgroundImage->setPos(getCenter());
    m_clockBackgroundImage->setHidden(VFX_FALSE);

    invalidate();
}


/*****************************************************************************
 * FUNCTION
 *  VcpAnalogClock::setClockCover
 * DESCRIPTION
 *  Set the cover image of analog clock.
 * PARAMETERS
 *  cover           [IN] Is the cover image.
 * RETURNS
 *  void
 *****************************************************************************/
void VcpAnalogClock::setClockCover(VfxS32 cover)
{
    m_clockCover->setResId(cover);

    m_hourHandImage->setAnchor(VfxFPoint(0.5, 0.5));
    m_hourHandImage->setPos(getCenter());
    m_hourHandImage->setHidden(VFX_FALSE);
    invalidate();
}


/*****************************************************************************
 * FUNCTION
 *  VcpAnalogClock::setClockHourHand
 * DESCRIPTION
 *  Set the hour hand image of analog clock.
 * PARAMETERS
 *  hourHand           [IN] Is the hour hand image.
 * RETURNS
 *  void
 *****************************************************************************/
void VcpAnalogClock::setClockHourHand(VfxS32 hourHand)
{
    m_hourHandImage->setResId(hourHand);

    m_hourHandImage->setAnchor(VfxFPoint(0.5, 1.0));
    m_hourHandImage->setPos(getCenter());
    m_hourHandImage->setHidden(VFX_FALSE);
    invalidate();
}


/*****************************************************************************
 * FUNCTION
 *  VcpAnalogClock::setClockMinuteHand
 * DESCRIPTION
 *  Set the minute hand image of analog clock.
 * PARAMETERS
 *  minuteHand           [IN] Is the minute hand image.
 * RETURNS
 *  void
 *****************************************************************************/
void VcpAnalogClock::setClockMinuteHand(VfxS32 minuteHand)
{
    m_minuteHandImage->setResId(minuteHand);

    m_minuteHandImage->setAnchor(VfxFPoint(0.5, 1.0));
    m_minuteHandImage->setPos(getCenter());
    m_minuteHandImage->setHidden(VFX_FALSE);
    invalidate();
}


/*****************************************************************************
 * FUNCTION
 *  VcpAnalogClock::setClockSecondHand
 * DESCRIPTION
 *  Set the second hand image of analog clock.
 * PARAMETERS
 *  secondHand           [IN] Is the second hand image.
 * RETURNS
 *  void
 *****************************************************************************/
void VcpAnalogClock::setClockSecondHand(VfxS32 secondHand)
{
    m_secondHandImage->setResId(secondHand);

    m_secondHandImage->setAnchor(VfxFPoint(0.5, 1.0));
    m_secondHandImage->setPos(getCenter());
    m_secondHandImage->setHidden(VFX_FALSE);
    invalidate();
}


/*****************************************************************************
 * FUNCTION
 *  VcpAnalogClock::setClockHourHandEnd
 * DESCRIPTION
 *  Set the hour hand end image of analog clock.
 * PARAMETERS
 *  hourHandEnd     [IN] Is the hour hand end image.
 * RETURNS
 *  void
 *****************************************************************************/
void VcpAnalogClock::setClockHourHandEnd(VfxS32 hourHandEnd)
{
    m_hourHandEndImage->setResId(hourHandEnd);

    m_hourHandEndImage->setAnchor(VfxFPoint(0.5, 0.0));
    m_hourHandEndImage->setPos(getCenter());
    m_hourHandEndImage->setHidden(VFX_FALSE);
    invalidate();
}


/*****************************************************************************
 * FUNCTION
 *  VcpAnalogClock::setClockMinuteHandEnd
 * DESCRIPTION
 *  Set the minute hand end image of analog clock.
 * PARAMETERS
 *  minuteHandEnd       [IN] Is the minute hand end image.
 * RETURNS
 *  void
 *****************************************************************************/
void VcpAnalogClock::setClockMinuteHandEnd(VfxS32 minuteHandEnd)
{
    m_minuteHandEndImage->setResId(minuteHandEnd);

    m_minuteHandEndImage->setAnchor(VfxFPoint(0.5, 0.0));
    m_minuteHandEndImage->setPos(getCenter());
    m_minuteHandEndImage->setHidden(VFX_FALSE);
    invalidate();
}


/*****************************************************************************
 * FUNCTION
 *  VcpAnalogClock::setClockSecondHandEnd
 * DESCRIPTION
 *  Set the second hand end image of analog clock.
 * PARAMETERS
 *  secondHandEnd       [IN] Is the second hand end image.
 * RETURNS
 *  void
 *****************************************************************************/
void VcpAnalogClock::setClockSecondHandEnd(VfxS32 secondHandEnd)
{
    m_secondHandEndImage->setResId(secondHandEnd);

    m_secondHandEndImage->setAnchor(VfxFPoint(0.5, 0.0));
    m_secondHandEndImage->setPos(getCenter());
    m_secondHandEndImage->setHidden(VFX_FALSE);
    invalidate();
}


/*****************************************************************************
 * FUNCTION
 *  VcpAnalogClock::setClockAxis
 * DESCRIPTION
 *  Set the axis image of analog clock.
 * PARAMETERS
 *  second           [IN] Is the axis image.
 * RETURNS
 *  void
 *****************************************************************************/
void VcpAnalogClock::setClockAxis(VfxS32 axis)
{
    m_axisImage->setResId(axis);

    m_axisImage->setAnchor(VfxFPoint(0.5, 0.5));
    m_axisImage->setPos(getCenter());
    m_axisImage->setHidden(VFX_FALSE);
    invalidate();
}


/*****************************************************************************
 * FUNCTION
 *  VcpAnalogClock::onMeasureMinSize
 * DESCRIPTION
 *  Measure the min display size of analog clock.
 * PARAMETERS
 *  size              [IN]  Is the pointer of parameter to get size
 * RETURNS
 *  void
 *****************************************************************************/
VfxSize VcpAnalogClock::onMeasureMinSize()
{
    vrt_size_struct size;

    VFX_ASSERT(m_clockBackground != NULL);
    size = vrt_sys_image_get_size_from_mem(m_clockBackground);
    return (VfxSize(size.width, size.height));
}


/*****************************************************************************
 * FUNCTION
 *  VcpAnalogClock::onDraw
 * DESCRIPTION
 *  Draw the analog clock.
 * PARAMETERS
 *  dc              [IN]  Is a reference of draw context class
 * RETURNS
 *  void
 *****************************************************************************/
void VcpAnalogClock::onDraw(VfxDrawContext &dc)
{
    VfxPoint hand_begin, hand_end, center;
    VfxPoint temp;
    VfxSize size;
    vrt_size_struct temp_size;
    VfxRect bounds;
    VfxU32 hour, minute, second;
    VfxS32 radius;

    bounds = getBounds();
    size = bounds.size;
    /* draw background */
    if ((m_clockBackgroundImage->getHidden() == VFX_TRUE) &&
        (m_clockBackground != NULL))
    {
        temp_size = vrt_sys_image_get_size_from_mem(m_clockBackground);
        temp.x = (size.width - temp_size.width) / 2;
        temp.y = (size.height - temp_size.height) / 2;
        dc.drawImageFromMem(temp.x, temp.y, m_clockBackground);
    }

    center = getCenter();
    hand_begin = center;
    hand_end = center;
    m_currentRelTime.getTime(&hour, &minute, &second);
    hour++;
    if (hour > 12)
    {
        hour -= 12;
    }
    hour = (hour - 1) * 5 + minute / 12;

    /* draw hour hand */
    if (m_hourHandImage->getHidden() == VFX_TRUE)
    {
        dc.setStrokeColor(getHourHandColor());
        radius = getHourHandRadius();
        if (radius > 0)
        {
            hand_end.x = center.x + (VfxS32)((VfxFloat)radius * acm_cosine_table[hour]);
            hand_end.y = center.y + (VfxS32)((VfxFloat)radius * acm_sine_table[hour]);
        }
        /* draw hour hand offset */
        radius = getHourHandRadiusOffset();
        if (radius > 0)
        {
            hand_begin.x = center.x - (VfxS32)((VfxFloat)radius * acm_cosine_table[hour]);
            hand_begin.y = center.y - (VfxS32)((VfxFloat)radius * acm_sine_table[hour]);
        }
        if (!(hand_begin.x == hand_end.x && hand_begin.y == hand_end.y))
        {
            dc.drawAaLine(hand_begin.x, hand_begin.y, hand_end.x, hand_end.y);
        }
    }
    else
    {
        VfxTransform trans(VFX_TRANSFORM_TYPE_AFFINE);
		VfxS32 hour_degree = hour * 6;

		trans.data.affine.rz = VFX_DEG_TO_RAD(hour_degree);
        m_hourHandImage->setTransform(trans);
        if (m_hourHandEndImage->getHidden() == VFX_FALSE)
        {
            trans.data.affine.rz = VFX_DEG_TO_RAD(hour_degree + 180);
            m_hourHandEndImage->setTransform(trans);
        }
    }

    /* draw minute hand */
    hand_begin = center;
    hand_end = center;
    if (m_minuteHandImage->getHidden() == VFX_TRUE)
    {
        dc.setStrokeColor(getMinuteHandColor());
        radius = getMinuteHandRadius();
        if (radius > 0)
        {
            hand_end.x = center.x + (VfxS32)((VfxFloat)radius * acm_cosine_table[minute]);
            hand_end.y = center.y + (VfxS32)((VfxFloat)radius * acm_sine_table[minute]);
        }
        /* draw minute hand offset */
        radius = getMinuteHandRadiusOffset();
        if (radius > 0)
        {
            hand_begin.x = center.x - (VfxS32)((VfxFloat)radius * acm_cosine_table[minute]);
            hand_begin.y = center.y - (VfxS32)((VfxFloat)radius * acm_sine_table[minute]);
        }
        if (!(hand_begin.x == hand_end.x && hand_begin.y == hand_end.y))
        {
            dc.drawAaLine(hand_begin.x, hand_begin.y, hand_end.x, hand_end.y);
        }
    }
    else
    {
        VfxTransform trans(VFX_TRANSFORM_TYPE_AFFINE);
		VfxS32 minute_degree = minute * 6;

        trans.data.affine.rz = VFX_DEG_TO_RAD(minute_degree);
        m_minuteHandImage->setTransform(trans);
        if (m_minuteHandEndImage->getHidden() == VFX_FALSE)
        {
            trans.data.affine.rz = VFX_DEG_TO_RAD(minute_degree + 180);
            m_minuteHandEndImage->setTransform(trans);
        }
    }

    /* draw second hand */
    hand_begin = center;
    hand_end = center;
    if (m_secondHandImage->getHidden() == VFX_TRUE)
    {
        dc.setStrokeColor(getSecondHandColor());
        radius = getSecondHandRadius();
        if (radius > 0)
        {
            hand_end.x = center.x + (VfxS32)((VfxFloat)radius * acm_cosine_table[second]);
            hand_end.y = center.y + (VfxS32)((VfxFloat)radius * acm_sine_table[second]);
        }
        /* draw second hand offset */
        radius = getSecondHandRadiusOffset();
        if (radius > 0)
        {
            hand_begin.x = center.x - (VfxS32)((VfxFloat)radius * acm_cosine_table[second]);
            hand_begin.y = center.y - (VfxS32)((VfxFloat)radius * acm_sine_table[second]);
        }
        if (!(hand_begin.x == hand_end.x && hand_begin.y == hand_end.y))
        {
            dc.drawAaLine(hand_begin.x, hand_begin.y, hand_end.x, hand_end.y);
        }
    }
    else
    {
        VfxTransform trans(VFX_TRANSFORM_TYPE_AFFINE);
		VfxS32 second_degree = second * 6;

        trans.data.affine.rz = VFX_DEG_TO_RAD(second_degree);
        m_secondHandImage->setTransform(trans);
        if (m_secondHandEndImage->getHidden() == VFX_FALSE)
        {
            trans.data.affine.rz = VFX_DEG_TO_RAD(second_degree + 180);
            m_secondHandEndImage->setTransform(trans);
        }
    }
}


VfxTimer *VcpDigitalImageClock::s_separatorTimer = NULL;
VfxBool VcpDigitalImageClock::s_displaySeparator = VFX_FALSE;
VfxBool VcpDigitalImageClock::s_setStartDelay = VFX_FALSE;
VcpDigitalImageClock *VcpDigitalImageClock::s_headClock = NULL;
/*****************************************************************************
 * FUNCTION
 *  VcpDigitalImageClock::VcpDigitalImageClock
 * DESCRIPTION
 *  Constructor of digital image clock class.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VcpDigitalImageClock::VcpDigitalImageClock() :
    m_amPmHDisplay(AMPM_H_DISPLAY_RIGHT_TOP),
    m_amPmVDisplay(AMPM_NO_V_DISPLAY),
    m_normal_gap(IMAGE_NORMAL_GAP),
    m_separator_gap(IMAGE_SEPARATOR_GAP),
    m_ampm_gap(IMAGE_AMPM_GAP),
    m_background(NULL),
    m_numberBackground(NULL),
    m_timeSeparatorForeground(0),
    m_timeSeparatorBackground(0),
    m_timeAmForeground(NULL),
    m_timeAmBackground(NULL),
    m_timePmForeground(NULL),
    m_timePmBackground(NULL),
    m_separator(NULL),
    m_nextClock(NULL)
{
    VfxU32 i;
    for(i = 0; i < 10; i++)
    {
        m_number[i] = NULL;
    }
}


VcpDigitalImageClock::AmPmHDisplayEnum VcpDigitalImageClock::getAmPmHDisplay() const
{
    return m_amPmHDisplay;
}


VcpDigitalImageClock::AmPmVDisplayEnum VcpDigitalImageClock::getAmPmVDisplay() const
{
    return m_amPmVDisplay;
}


void VcpDigitalImageClock::setAmPmHDisplay(AmPmHDisplayEnum value)
{
    VFX_UNUSED(value);
    VfxRect bounds = getBounds();
    setBounds(VfxRect(bounds.origin, onMeasureMinSize()));
    
    invalidate();
}


void VcpDigitalImageClock::setAmPmVDisplay(AmPmVDisplayEnum value)
{
    VFX_UNUSED(value);
    VfxRect bounds = getBounds();
    setBounds(VfxRect(bounds.origin, onMeasureMinSize()));
    
    invalidate();
}


/*****************************************************************************
 * FUNCTION
 *  VcpDigitalImageClock::onInit
 * DESCRIPTION
 *  Initialize digital image clock class.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDigitalImageClock::onInit()
{
    VfxDateTime updateInterval;
    VfxRect bounds;

    VcpClock::onInit();

    m_number[0] = vrt_sys_res_image_lock(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_0);
    m_number[1] = vrt_sys_res_image_lock(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_1);
    m_number[2] = vrt_sys_res_image_lock(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_2);
    m_number[3] = vrt_sys_res_image_lock(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_3);
    m_number[4] = vrt_sys_res_image_lock(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_4);
    m_number[5] = vrt_sys_res_image_lock(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_5);
    m_number[6] = vrt_sys_res_image_lock(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_6);
    m_number[7] = vrt_sys_res_image_lock(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_7);
    m_number[8] = vrt_sys_res_image_lock(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_8);
    m_number[9] = vrt_sys_res_image_lock(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_9);
    m_numberBackground = vrt_sys_res_image_lock(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_BACKGROUND);

    m_timeSeparatorForeground = IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_TIME_SEPERATOR_FOREGROUND;
    m_timeSeparatorBackground = IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_TIME_SEPERATOR_BACKGROUND;
    VFX_OBJ_CREATE(m_separator, VfxImageFrame, this);
    if (s_displaySeparator == VFX_TRUE)
    {
        m_separator->setResId(m_timeSeparatorForeground);
    }
    else
    {
        m_separator->setResId(m_timeSeparatorBackground);
    }
    setIsCached(VFX_TRUE);

    m_timeAmForeground = vrt_sys_res_image_lock(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_AM_FOREGROUND);
    m_timeAmBackground = vrt_sys_res_image_lock(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_AM_BACKGROUND);
    m_timePmForeground = vrt_sys_res_image_lock(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_PM_FOREGROUND);
    m_timePmBackground = vrt_sys_res_image_lock(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_PM_BACKGROUND);
    bounds = getBounds();
    setBounds(VfxRect(bounds.origin, onMeasureMinSize()));

    updateInterval.setTime(0, 1, 0);
    setUpdateInterval(updateInterval);

    /* connect the clock to static timer */
    if (s_separatorTimer == NULL)
    {
        VFX_OBJ_CREATE(s_separatorTimer, VfxTimer, VFX_SYS_GLOBAL_CONTEXT);
        s_headClock = this;
        s_separatorTimer->setStartDelay(500);
        s_separatorTimer->setDuration(500);
        s_separatorTimer->m_signalTick.connect(this, &VcpDigitalImageClock::onSeparatorTimerTick);
    }
    else
    {
        s_separatorTimer->m_signalTick.connect(this, &VcpDigitalImageClock::onSeparatorTimerTick);
        m_nextClock = s_headClock;
        s_headClock = this;
    }
}


/*****************************************************************************
 * FUNCTION
 *  VcpDigitalImageClock::onDeinit
 * DESCRIPTION
 *  Deinitialize digital image clock class.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDigitalImageClock::onDeinit()
{
    VcpDigitalImageClock *current_clock = NULL, *pre_clock = NULL;

    VFX_ASSERT(s_headClock != NULL);
    current_clock = s_headClock;
    /* search the link to find delete clock */
    while (current_clock != this && current_clock->m_nextClock != NULL)
    {
        pre_clock = current_clock;
        current_clock = current_clock->m_nextClock;
    }

    if (current_clock == this)
    {
        if (current_clock == s_headClock)
        {
            s_headClock = current_clock->m_nextClock;
        }
        else
        {
            pre_clock->m_nextClock = current_clock->m_nextClock;
            current_clock->m_nextClock = NULL;
        }
        s_separatorTimer->m_signalTick.disconnect(this, &VcpDigitalImageClock::onSeparatorTimerTick);

        if (s_headClock == NULL)
        {
            VFX_OBJ_CLOSE(s_separatorTimer);
            s_displaySeparator = VFX_FALSE;
            s_setStartDelay = VFX_FALSE;
        }
    }
    else
    {
        VFX_ASSERT(0);
    }

    VFX_OBJ_CLOSE(m_separator);
    VcpClock::onDeinit();
}

    // the gap between every number.
    // the gap between number and separator.
    // the gap between number and AM/PM.
/*****************************************************************************
 * FUNCTION
 *  VcpDigitalImageClock::setGap
 * DESCRIPTION
 *  Set the gap to digital image clock.
 * PARAMETERS
 *  normal_gap           [IN] the gap between every number.
 *  separator_gap        [IN] the gap between number and separator.
 *  ampm_gap             [IN] the gap between number and AM/PM.
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDigitalImageClock::setGap(VfxU8 normal_gap, VfxU8 separator_gap, VfxU8 ampm_gap)
{
    m_normal_gap = normal_gap;
    m_separator_gap = separator_gap;
    m_ampm_gap = ampm_gap;
}

/*****************************************************************************
 * FUNCTION
 *  VcpDigitalImageClock::setBackground
 * DESCRIPTION
 *  Set the background to digital image clock.
 * PARAMETERS
 *  background           [IN] Is the background image
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDigitalImageClock::setBackground(VfxU8 *background)
{
    VfxRect bounds;
    bounds = getBounds();
    m_background = background;
    setBounds(VfxRect(bounds.origin, onMeasureMinSize()));
}


/*****************************************************************************
 * FUNCTION
 *  VcpDigitalImageClock::setNumber
 * DESCRIPTION
 *  Set the number image to digital image clock.
 * PARAMETERS
 *  number              [IN] Is the ASCII code of number
 *  numberSrc          [IN] Is the number image
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDigitalImageClock::setNumber(VfxChar number, VfxU8 *numberSrc)
{
    m_number[number - '0'] = numberSrc;
}


/*****************************************************************************
 * FUNCTION
 *  VcpDigitalImageClock::setNumber
 * DESCRIPTION
 *  Set the number image to digital image clock.
 * PARAMETERS
 *  numberBeginId         [IN] Is the number begin image ID
 *  numberEndId           [IN] Is the number end image ID
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDigitalImageClock::setNumber(
      VfxS32 numberBeginId,
      VfxS32 numberEndId)
{
    VfxS32 i;
    VfxRect bounds = getBounds();

    for (i = 0; i < numberEndId - numberBeginId + 1; i++)
    {
        m_number[i] = vrt_sys_res_image_lock(numberBeginId + i);
    }
    setBounds(VfxRect(bounds.origin, onMeasureMinSize()));
}


/*****************************************************************************
 * FUNCTION
 *  VcpDigitalImageClock::setNumberBackground
 * DESCRIPTION
 *  Set the number background image to digital image clock.
 * PARAMETERS
 *  numberBackground       [IN] Is the number background image
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDigitalImageClock::setNumberBackground(VfxU8 *numberBackground)
{
    VfxRect bounds = getBounds();
    m_numberBackground = numberBackground;
    setBounds(VfxRect(bounds.origin, onMeasureMinSize()));
}


/*****************************************************************************
 * FUNCTION
 *  VcpDigitalImageClock::setTimeSeparator
 * DESCRIPTION
 *  Set the time separator's foreground and background image to digital image clock.
 * PARAMETERS
 *  separatorForeground       [IN] Is time separator's foreground
 *  separatorBackground       [IN] Is time separator's background
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDigitalImageClock::setTimeSeparator(
      VfxS32 separatorForeground,
      VfxS32 separatorBackground)
{
    m_timeSeparatorForeground = separatorForeground;
    m_timeSeparatorBackground = separatorBackground;
    if (s_displaySeparator == VFX_TRUE)
    {
        m_separator->setResId(m_timeSeparatorForeground);
    }
    else
    {
        m_separator->setResId(m_timeSeparatorBackground);
    }
}


/*****************************************************************************
 * FUNCTION
 *  VcpDigitalImageClock::setAmAndPm
 * DESCRIPTION
 *  Set am and pm foreground and background image to digital image clock.
 * PARAMETERS
 *  amForeground       [IN] Is am's foreground
 *  amBackground       [IN] Is am's background
 *  pmForeground       [IN] Is pm's foreground
 *  pmBackground       [IN] Is pm's background
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDigitalImageClock::setAmAndPm(
      VfxU8 *amForeground,
      VfxU8 *amBackground,
      VfxU8 *pmForeground,
      VfxU8 *pmBackground)
{
    VfxRect bounds;
    bounds = getBounds();
    m_timeAmForeground = amForeground;
    m_timeAmBackground = amBackground;
    m_timePmForeground = pmForeground;
    m_timePmBackground = pmBackground;
    setBounds(VfxRect(bounds.origin, onMeasureMinSize()));
}


/*****************************************************************************
 * FUNCTION
 *  VcpDigitalImageClock::onMeasureMinSize
 * DESCRIPTION
 *  Measure the min display size of digital image clock.
 * PARAMETERS
 *  size              [IN]  Is the pointer of parameter to get size
 * RETURNS
 *  void
 *****************************************************************************/
VfxSize VcpDigitalImageClock::onMeasureMinSize()
{
    vrt_size_struct size, background, temp;

    if (m_background != NULL)
    {
        background = vrt_sys_image_get_size_from_mem(m_background);
    }
    else
    {
        background.width = 0;
        background.height = 0;
    }

    if (m_number[0] != NULL)
    {
        temp = vrt_sys_image_get_size_from_mem(m_number[0]);
        /* the display format is 0--0-:-0--0 */
        size.width = temp.width * 4 + m_normal_gap * 2;
        size.height = temp.height;
        VFX_ASSERT(m_timeSeparatorForeground > 0);
        temp = vrt_sys_image_get_size_from_mem(
                   vrt_sys_res_image_lock(m_timeSeparatorForeground));
        size.width = size.width + temp.width + m_separator_gap * 2;
        /* measure the am/pm height */
        if (m_timeAmForeground != NULL)
        {
            temp = vrt_sys_image_get_size_from_mem(m_timeAmForeground);
            if (getAmPmVDisplay() == AMPM_NO_V_DISPLAY)
            {
                size.height += temp.height + m_ampm_gap;
            }
            else
            {
                size.width += temp.width + m_ampm_gap;
            }
        }
    }
    else
    {
        size.width = 0;
        size.height = 0;
    }

    if (background.width >= size.width && background.height >= size.height)
    {
        return (VfxSize(background.width, background.height));
    }
    return (VfxSize(size.width, size.height));
}


#ifdef __cplusplus
extern "C"
{
extern U8 PhnsetGetTimeFormat(void);
}
#endif
/*****************************************************************************
 * FUNCTION
 *  VcpDigitalImageClock::onDraw
 * DESCRIPTION
 *  Draw the digital image clock.
 * PARAMETERS
 *  dc              [IN]  Is a reference of draw context class
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDigitalImageClock::onDraw(VfxDrawContext &dc)
{
    VfxPoint temp = VFX_POINT_ZERO, number, separator;
    VfxRect bounds = getBounds();
    vrt_size_struct temp_size = {0, 0}, min_size = {0, 0};
    vrt_size_struct num_size = {0, 0}, am_size = {0, 0};
    VfxSize separator_size = VFX_SIZE_ZERO;
    VfxU32 hour, minute, second;
    VfxU32 num1, num2;
    VfxU8 *timeAmPmImage = NULL;

    /* show background image */
    if (m_background != NULL)
    {
        temp_size = vrt_sys_image_get_size_from_mem(m_background);
        temp.x = (bounds.getWidth() - temp_size.width) / 2;
        temp.y = (bounds.getHeight() - temp_size.height) / 2;
        dc.drawImageFromMem(temp.x, temp.y, m_background);        
    }
    if (m_number[0] != NULL)
    {
        num_size = vrt_sys_image_get_size_from_mem(m_number[0]);
    }
    if (m_timeSeparatorForeground != NULL)
    {
        separator_size = vrt_sys_image_get_size_from_mem(
                             vrt_sys_res_image_lock(m_timeSeparatorForeground));
    }

    m_currentRelTime.getTime(&hour, &minute, &second);
    /* show digital clock's hour image */
    if (PhnsetGetTimeFormat()) /* Is 12 hour format */
    {
        num1 = hour / 10;
        num2 = hour - num1 * 10;
    }
    else
    {
        if (hour == 12)
        {
            num1 = hour / 10;
            num2 = hour - num1 * 10;
            timeAmPmImage = m_timePmForeground;
        }
        else if(hour == 0)
        {
            num1 = 12 / 10;
            num2 = 12 - 10;
            timeAmPmImage = m_timeAmForeground;
        }
        else if(hour > 12)
        {
            num1 = (hour - 12) / 10;
            num2 = (hour - 12) - num1 * 10;
            timeAmPmImage = m_timePmForeground;
        }
        else
        {
            num1 = hour / 10;
            num2 = hour - num1 * 10;
            timeAmPmImage = m_timeAmForeground;
        }
    }

    /* Display hour number */
    temp_size.width = bounds.getWidth();
    temp_size.height = bounds.getHeight();
    if (m_number[0] != NULL)
    {
        num_size = vrt_sys_image_get_size_from_mem(m_number[0]);
        /* the display format is 0--0-:-0--0 */
        min_size.width = num_size.width * 4 + m_normal_gap * 2;
        min_size.height = num_size.height;
        VFX_ASSERT(m_timeSeparatorForeground > 0);
        separator_size = vrt_sys_image_get_size_from_mem(
                             vrt_sys_res_image_lock(m_timeSeparatorForeground));
        min_size.width = min_size.width + separator_size.width + m_separator_gap * 2;
        if (m_timeAmForeground != NULL)
        {
            am_size = vrt_sys_image_get_size_from_mem(m_timeAmForeground);
        }
        if (getAmPmHDisplay() == AMPM_NO_H_DISPLAY)
        {            
            min_size.width = min_size.width + am_size.width + m_ampm_gap;
        }
        else
        {
            min_size.height = min_size.height + am_size.height + m_ampm_gap;
        }
    }

    number.x = (temp_size.width - min_size.width) / 2;
    number.y = (temp_size.height - min_size.height) / 2;
    // if display am and pm in the same line
    if (getAmPmVDisplay() == AMPM_NO_V_DISPLAY)
    {
        if (getAmPmHDisplay() == AMPM_H_DISPLAY_LEFT_TOP ||
            getAmPmHDisplay() == AMPM_H_DISPLAY_RIGHT_TOP)
        {
            number.y = number.y + am_size.height + m_ampm_gap;
        }
        separator.y = number.y + (num_size.height - separator_size.height) / 2;
    }
    else
    {
        separator.y = (temp_size.height - separator_size.height) / 2;
    }
    if (number.x < 0)
    {
        number.x = 0;
    }
    if (number.y < 0)
    {
        number.y = 0;
    }
    if (m_numberBackground != NULL)
    {
        dc.drawImageFromMem(number.x, number.y, m_numberBackground);
    }
    if (m_number[num1] != NULL)
    {
        dc.drawImageFromMem(number.x, number.y, m_number[num1]);
    }
    number.x += m_normal_gap + num_size.width;
    if (m_numberBackground != NULL)
    {
        dc.drawImageFromMem(number.x, number.y, m_numberBackground);
    }
    if (m_number[num2] != NULL)
    {
        dc.drawImageFromMem(number.x, number.y, m_number[num2]);
    }
    separator.x = number.x + m_separator_gap + num_size.width;

    /* set separator position */
    m_separator->setPos(separator);
    m_separator->setBounds(VfxRect(VFX_POINT_ZERO, separator_size));
    if (s_setStartDelay == VFX_FALSE)
    {
        s_separatorTimer->start();
        s_setStartDelay = VFX_TRUE;
    }

    /* draw minute number */
    num1 = minute / 10;
    num2 = minute - num1 * 10;
    number.x = separator.x + m_separator_gap + separator_size.width;
    if (m_numberBackground != NULL)
    {
        dc.drawImageFromMem(number.x, number.y, m_numberBackground);
    }
    if (m_number[num1] != NULL)
    {
        dc.drawImageFromMem(number.x, number.y, m_number[num1]);
    }
    number.x += m_normal_gap + num_size.width;
    if (m_numberBackground != NULL)
    {
        dc.drawImageFromMem(number.x, number.y, m_numberBackground);
    }
    if (m_number[num2] != NULL)
    {
        dc.drawImageFromMem(number.x, number.y, m_number[num2]);
    }
    number.x += num_size.width;

    /* draw am/pm */
    if (m_timeAmForeground != NULL)
    {
        am_size = vrt_sys_image_get_size_from_mem(m_timeAmForeground);
    }
    // if display am and pm in the same line
    if (getAmPmVDisplay() == AMPM_NO_V_DISPLAY)
    {
        if (getAmPmHDisplay() == AMPM_H_DISPLAY_RIGHT_TOP)
        {
            temp.y = number.y - am_size.height - m_ampm_gap;
            temp.x = number.x - am_size.width * 2 - m_ampm_gap;
        }
        else if (getAmPmHDisplay() == AMPM_H_DISPLAY_RIGHT_BOTTOM)
        {
            temp.y = number.y + num_size.height + m_ampm_gap;
            temp.x = number.x - am_size.width * 2 - m_ampm_gap;
        }
        else if (getAmPmHDisplay() == AMPM_H_DISPLAY_LEFT_TOP)
        {
            temp.y = number.y - am_size.height - m_ampm_gap;
            temp.x = (temp_size.width - min_size.width) / 2;
        }
        else if (getAmPmHDisplay() == AMPM_H_DISPLAY_LEFT_BOTTOM)
        {
            temp.y = number.y + num_size.height + m_ampm_gap;
            temp.x = (temp_size.width - min_size.width) / 2;
        }
        else
        {
            VFX_ASSERT(0);
        }

        if (m_timeAmBackground != NULL)
        {
            dc.drawImageFromMem(temp.x, temp.y, m_timeAmBackground);
        }
        if (timeAmPmImage == m_timeAmForeground)
        {
            dc.drawImageFromMem(temp.x, temp.y, m_timeAmForeground);
        }
        temp.x += am_size.width + m_ampm_gap;
        if (m_timePmBackground != NULL)
        {
            dc.drawImageFromMem(temp.x, temp.y, m_timePmBackground);
        }
        if (timeAmPmImage == m_timePmForeground)
        {
            dc.drawImageFromMem(temp.x, temp.y, m_timePmForeground);
        }
    }
    else // display am and pm in the same column
    {
        temp.x = number.x + m_ampm_gap;
        if (getAmPmVDisplay() == AMPM_V_DISPLAY_RIGHT_TOP ||
            getAmPmVDisplay() == AMPM_V_DISPLAY_RIGHT_EQUIDISTANCE)
        {
            temp.y = number.y;
        }
        else if (getAmPmVDisplay() == AMPM_V_DISPLAY_RIGHT_BOTTOM)
        {
            temp.y = number.y + num_size.height - am_size.height * 2 - m_ampm_gap;
        }
        else
        {
            VFX_ASSERT(0);
        }
        if (m_timeAmBackground != NULL)
        {
            dc.drawImageFromMem(temp.x, temp.y, m_timeAmBackground);
        }
        if (timeAmPmImage == m_timeAmForeground)
        {
            dc.drawImageFromMem(temp.x, temp.y, m_timeAmForeground);
        }

        if (getAmPmVDisplay() == AMPM_V_DISPLAY_RIGHT_EQUIDISTANCE)
        {
            temp.y = number.y + num_size.height - am_size.height;
        }
        else
        {
            temp.y += am_size.height + m_ampm_gap;
        }
        if (m_timePmBackground != NULL)
        {
            dc.drawImageFromMem(temp.x, temp.y, m_timePmBackground);
        }
        if (timeAmPmImage == m_timePmForeground)
        {
            dc.drawImageFromMem(temp.x, temp.y, m_timePmForeground);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  VcpDigitalImageClock::onSeparatorTimerTick
 * DESCRIPTION
 *  Draw the digital image clock.
 * PARAMETERS
 *  dc              [IN]  Is a reference of draw context class
 * RETURNS
 *  void
 *****************************************************************************/
void VcpDigitalImageClock::onSeparatorTimerTick(VfxTimer *source)
{
    VFX_UNUSED(source);

    VcpDigitalImageClock *current_clock;

    if (s_displaySeparator == VFX_TRUE)
    {
        s_displaySeparator = VFX_FALSE;
    }
    else
    {
        s_displaySeparator = VFX_TRUE;
    }

    current_clock = s_headClock;
    while(current_clock != NULL)
    {
        if (s_displaySeparator == VFX_TRUE)
        {
            current_clock->m_separator->setResId(current_clock->m_timeSeparatorForeground);
        }
        else
        {
            current_clock->m_separator->setResId(current_clock->m_timeSeparatorBackground);
        }

        current_clock = current_clock->m_nextClock;
    }
    vfxStopEmit();
}

