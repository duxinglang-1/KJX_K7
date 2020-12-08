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
 *  vfx_date_time.cpp
 *
 * Project:
 * --------
 *  Venus UI Component
 *
 * Description:
 * ------------
 *  Basic class to handle date and time info
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

#include "vfx_date_time.h"

extern "C"
{
#include "app_datetime.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
}

#include "vfx_system.h"
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include <stdio.h>


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Global function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::VfxDateTime
 * DESCRIPTION
 *  Constructor of date-time class.
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
VfxDateTime::VfxDateTime()
{
    m_time.nYear = 0;
    m_time.nMonth = 0;
    m_time.nDay = 0;
    m_time.nHour = 0;
    m_time.nMin = 0;
    m_time.nSec = 0;
    m_time.DayIndex = 0;
    m_timeZone = 0.0;
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::VfxDateTime
 * DESCRIPTION
 *  Constructor of date-time class.
 * PARAMETERS
 *  other           [IN] Is a reference of date-time object.
 * RETURNS
 *
 *****************************************************************************/
VfxDateTime::VfxDateTime(const VfxDateTime &other):
 m_time(other.m_time),
 m_timeZone(other.m_timeZone)
{}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::operator
 * DESCRIPTION
 *  Assign operator.
 * PARAMETERS
 *  other           [IN] Is a reference of date-time object.
 * RETURNS
 *
 *****************************************************************************/
VfxDateTime &VfxDateTime::operator = (const VfxDateTime &other)
{
    m_time = other.m_time;
    m_timeZone = other.m_timeZone;
    return *this;
}


#ifdef __cplusplus
extern "C"
{
    extern U8 PhnsetGetHomeCity(void);
    extern FLOAT GetTimeZone(U8 cityIndex);
}
#endif
/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::setCurrentTime
 * DESCRIPTION
 *  Set the system time to date-time object.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VfxDateTime::setCurrentTime()
{
    applib_dt_get_rtc_time(&m_time);
    m_timeZone = GetTimeZone(PhnsetGetHomeCity());
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::setDate
 * DESCRIPTION
 *  Set the date information to date-time object.
 * PARAMETERS
 *  year               [IN] Is the new year
 *  month              [IN] Is the new month
 *  day                [IN] Is the new day
 * RETURNS
 *  VfxBool
 *****************************************************************************/
VfxBool VfxDateTime::setDate(VfxU32 year, VfxU32 month, VfxU32 day)
{
    applib_time_struct temp_time;

    temp_time = m_time;

    m_time.nYear = year;
    m_time.nMonth = month;
    m_time.nDay = day;
    if (isValidDate() == VFX_TRUE)
    {
        m_time.DayIndex = applib_dt_dow(
                              (VfxU16)m_time.nYear,
                              (VfxU8)m_time.nMonth,
                              (VfxU8)m_time.nDay);
        return VFX_TRUE;
    }
    else
    {
        m_time = temp_time;
    }
    return VFX_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::setTime
 * DESCRIPTION
 *  Set the time information to date-time object.
 * PARAMETERS
 *  hour               [IN] Is the new hour
 *  minute             [IN] Is the new minute
 *  second             [IN] Is the new second
 * RETURNS
 *  VfxBool
 *****************************************************************************/
VfxBool VfxDateTime::setTime(VfxU32 hour, VfxU32 minute, VfxU32 second)
{
    applib_time_struct temp_time;

    temp_time = m_time;

    m_time.nHour = hour;
    m_time.nMin = minute;
    m_time.nSec = second;
    if (isValidTime() == VFX_TRUE)
    {
        return VFX_TRUE;
    }
    else
    {
        m_time = temp_time;
    }
    return VFX_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::setDateTime
 * DESCRIPTION
 *  Set the time information to date-time object.
 * PARAMETERS
 *  dateTime           [IN] Is the new date & time
 * RETURNS
 *  VfxBool
 *****************************************************************************/
VfxBool VfxDateTime::setDateTime(applib_time_struct *dateTime)
{
    applib_time_struct temp_time;

    if (dateTime != NULL)
    {
        temp_time = m_time;

        m_time.nYear = dateTime->nYear;
        m_time.nMonth = dateTime->nMonth;
        m_time.nDay = dateTime->nDay;
        if (isValidDate() == VFX_FALSE)
        {
            m_time = temp_time;
            return VFX_FALSE;
        }
        m_time.nHour = dateTime->nHour;
        m_time.nMin = dateTime->nMin;
        m_time.nSec = dateTime->nSec;
        if (isValidTime() == VFX_FALSE)
        {
            m_time = temp_time;
            return VFX_FALSE;
        }
        m_time.DayIndex = applib_dt_dow(
                              (VfxU16)m_time.nYear,
                              (VfxU8)m_time.nMonth,
                              (VfxU8)m_time.nDay);
        return VFX_TRUE;
    }
    return VFX_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::setTimeZone
 * DESCRIPTION
 *  Assign the time zone to an date-time object.
 * PARAMETERS
 *  timeZone           [IN] Is the time zone of date-time object. 
 * RETURNS
 *  void
 *****************************************************************************/
VfxBool VfxDateTime::setTimeZone(VfxFloat timeZone)
{
    VfxU8 increase_flag;
    VfxFloat time_zone_diff;
    applib_time_struct temp_time, time_diff, time_result;

    if (timeZone > m_timeZone)
    {
        increase_flag = 1;
        time_zone_diff = (VfxFloat)(timeZone - m_timeZone) / 4;
    }
    else if (timeZone < timeZone)
    {
        increase_flag = 0;
        time_zone_diff = (VfxFloat)(timeZone - m_timeZone) / 4;
    }
    else
    {
        return VFX_FALSE;
    }
    
    time_diff = applib_conv_tz_to_mytime(time_zone_diff);
    temp_time = m_time;

    if (increase_flag)
    {
        applib_dt_increase_time(&temp_time, &time_diff, &time_result);
    }
    else
    {
        applib_dt_decrease_time(&temp_time, &time_diff, &time_result);
    }

    if (applib_dt_is_valid(&time_result) == KAL_TRUE)
    {
        m_time = time_result;
        m_timeZone = timeZone;
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::getDateTime
 * DESCRIPTION
 *  get date and time information.
 * PARAMETERS
 *  void
 * RETURNS
 *  applib_time_struct
 *****************************************************************************/
applib_time_struct VfxDateTime::getDateTime() const
{
    return m_time;
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::getDate
 * DESCRIPTION
 *  Get the date information to date-time object.
 * PARAMETERS
 *  year               [IN] Is the pointer of parameter to get year
 *  month              [IN] Is the pointer of parameter to get month
 *  day                [IN] Is the pointer of parameter to get day
 * RETURNS
 *  void
 *****************************************************************************/
void VfxDateTime::getDate(
      VfxU32 *year,
      VfxU32 *month,
      VfxU32 *day) const
{
    *year = m_time.nYear;
    *month = m_time.nMonth;
    *day = m_time.nDay;
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::getYear
 * DESCRIPTION
 *  Get the year information to date-time object.
 * PARAMETERS
 *  void
 * RETURNS
 *  VfxU32
 *****************************************************************************/
VfxU32 VfxDateTime::getYear() const
{
    return (m_time.nYear);
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::getMonth
 * DESCRIPTION
 *  Get the month information to date-time object.
 * PARAMETERS
 *  void
 * RETURNS
 *  VfxU32
 *****************************************************************************/
VfxU32 VfxDateTime::getMonth() const
{
    return (m_time.nMonth);
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::getDay
 * DESCRIPTION
 *  Get the day information to date-time object.
 * PARAMETERS
 *  void
 * RETURNS
 *  VfxU32
 *****************************************************************************/
VfxU32 VfxDateTime::getDay() const
{
    return (m_time.nDay);
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::getTime
 * DESCRIPTION
 *  Get the time information to date-time object.
 * PARAMETERS
 *  hour               [IN] Is the pointer of parameter to get hour
 *  minute             [IN] Is the pointer of parameter to get minute
 *  second             [IN] Is the pointer of parameter to get second
 * RETURNS
 *  void
 *****************************************************************************/
void VfxDateTime::getTime(
      VfxU32 *hour,
      VfxU32 *minute,
      VfxU32 *second) const
{
    *hour = m_time.nHour;
    *minute = m_time.nMin;
    *second = m_time.nSec;
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::getHour
 * DESCRIPTION
 *  Get the hour information to date-time object.
 * PARAMETERS
 *  void
 * RETURNS
 *  VfxU32
 *****************************************************************************/
VfxU32 VfxDateTime::getHour() const
{
    return (m_time.nHour);
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::getMinute
 * DESCRIPTION
 *  Get the minute information to date-time object.
 * PARAMETERS
 *  void
 * RETURNS
 *  VfxU32
 *****************************************************************************/
VfxU32 VfxDateTime::getMinute() const
{
    return (m_time.nMin);
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::getSecond
 * DESCRIPTION
 *  Get the second information to date-time object.
 * PARAMETERS
 *  void
 * RETURNS
 *  VfxU32
 *****************************************************************************/
VfxU32 VfxDateTime::getSecond() const
{
    return (m_time.nSec);
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::getDayOfWeek
 * DESCRIPTION
 *  Get the day information to date-time object.
 * PARAMETERS
 *  dayOfWeek        [IN] Is the pointer of parameter to get day
 * RETURNS
 *  void
 *****************************************************************************/
void VfxDateTime::getDayOfWeek(DayOfWeekEnum *dayOfWeek) const
{
    
    *dayOfWeek = (DayOfWeekEnum)(SUN + applib_dt_dow(
                                                (VfxU16)m_time.nYear,
                                                (VfxU8)m_time.nMonth,
                                                (VfxU8)m_time.nDay));
}


#ifdef __cplusplus
extern "C"
{
    extern U8 PhnsetGetDateSeperatorFormat(void);
    extern U8 PhnsetGetDateFormat(void);
    extern U8 PhnsetGetTimeFormat(void);
}
#endif
/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::getDateTimeString
 * DESCRIPTION
 *  Get the date time string of date-time object.
 * PARAMETERS
 *  flags               [IN] Is the flags of date-time object
 *  dateTimeString    [IN] Is the pointer of buffer to get string
 *  maxLength          [IN] Is the max length of buffer
 * RETURNS
 *  void
 *****************************************************************************/
void VfxDateTime::getDateTimeString(
      VfxU32 flags,
      VfxWChar *dateTimeString,
      VfxU32 maxLength) const
{
    VfxWChar *wtemp;
    VfxU32 remain_length;
    VfxU32 wtemp_length;

    VfxChar seperator;
    VfxChar *temp;
    VfxWChar *temp_w;
    VfxChar temp_string[STRING_LENGTH_MAX];
    VfxWChar temp_wstring[STRING_LENGTH_MAX];
    //VfxChar buffer[STRING_LENGTH_MAX];

    const VfxResId day_normal_str[DAY_TOTAL_NUM] =
        {STR_GLOBAL_SUNDAY, STR_GLOBAL_MONDAY, STR_GLOBAL_TUESDAY, STR_GLOBAL_WEDNESDAY, STR_GLOBAL_THURSDAY, STR_GLOBAL_FRIDAY, STR_GLOBAL_SATURDAY};
    const VfxResId day_short_str[DAY_TOTAL_NUM] =
        {STR_GLOBAL_SUNDAY_SHORT, STR_GLOBAL_MONDAY_SHORT, STR_GLOBAL_TUESDAY_SHORT, STR_GLOBAL_WEDNESDAY_SHORT, STR_GLOBAL_THURSDAY_SHORT, STR_GLOBAL_FRIDAY_SHORT, STR_GLOBAL_SATURDAY_SHORT};
    const VfxResId month_normal_str[MONTH_TOTAL_NUMBER] =
        {STR_GLOBAL_JANUARY_SHORT, STR_GLOBAL_FEBRUARY_SHORT, STR_GLOBAL_MARCH_SHORT, STR_GLOBAL_APRIL_SHORT, STR_GLOBAL_MAY_SHORT, STR_GLOBAL_JUNE_SHORT, STR_GLOBAL_JULY_SHORT, STR_GLOBAL_AUGEST_SHORT, STR_GLOBAL_SEPTEMBER_SHORT, STR_GLOBAL_OCTOBER_SHORT, STR_GLOBAL_NOVEMBER_SHORT, STR_GLOBAL_DECEMBER_SHORT};

    wtemp = dateTimeString;
    remain_length = maxLength;

    temp = temp_string;

    /* duration is a special case of get string */
    if (flags & VFX_DATE_TIME_DURATION_MASK)
    {
        if ((flags & VFX_DATE_TIME_DURATION_FULL_FORMAT) ||
            (flags & VFX_DATE_TIME_DURATION_NO_HOUR))
        {
            /* Set seperator */
            seperator = ':';
            if (flags & VFX_DATE_TIME_DURATION_FULL_FORMAT)
            {
                sprintf(temp, "%02d%c%02d%c%02d", m_time.nHour, seperator, m_time.nMin, seperator, m_time.nSec);
                /* convert duration string */
                *(temp + 8) = '\0';
            }
            else
            {
                sprintf(temp, "%02d%c%02d", m_time.nMin, seperator, m_time.nSec);
                /* convert duration string */
                *(temp + 5) = '\0';
            }
            wtemp_length = vfx_sys_strlen(temp_string);
            mmi_asc_n_to_ucs2((CHAR *)temp_wstring, (CHAR *)temp_string, wtemp_length + 1);
            if (wtemp_length >= remain_length)
            {
                return;
            }
            vfx_sys_wcscpy(wtemp, temp_wstring);
            return;
        }
    }

    /* parse special flags */
    if (flags & VFX_DATE_TIME_FORMAT_AUTO_DETECT_DATE_DISPLAY)
    {
        applib_time_struct time;
        applib_dt_get_rtc_time(&time);
        if (m_time.nYear == time.nYear && m_time.nMonth == time.nMonth && m_time.nDay == time.nDay)
        {
            flags = VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE;
        }
        else
        {
            flags = VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY;
        }
    }

    /* parse day of week flags */
    if (flags & VFX_DATE_TIME_DAY_MASK)
    {
        if (flags & VFX_DATE_TIME_DAY_NORMAL_NAME)
        {
            wtemp_length = vfx_sys_wcslen((VfxWChar *)GetString(day_normal_str[m_time.DayIndex]));
            if (wtemp_length >= remain_length)
            {
                return;
            }
            vfx_sys_wcscpy(wtemp, (VfxWChar *)GetString(day_normal_str[m_time.DayIndex]));

            remain_length -= wtemp_length;
            wtemp += wtemp_length;
        }
        else if (flags & VFX_DATE_TIME_DAY_SHORT_NAME)
        {
            wtemp_length = vfx_sys_wcslen((VfxWChar *)GetString(day_short_str[m_time.DayIndex]));
            if (wtemp_length >= remain_length)
            {
                return;
            }
            vfx_sys_wcscpy(wtemp, (VfxWChar *)GetString(day_short_str[m_time.DayIndex]));

            remain_length -= wtemp_length;
            wtemp += wtemp_length;
        }
    }

    /* parse date flags */
    if (flags & VFX_DATE_TIME_DATE_MASK) 
    {
        temp_w = temp_wstring;

        if (flags & VFX_DATE_TIME_FORMAT_NO_DATE_SEPARATOR)
        {
            seperator = ' ';
        }
        else
        {
            /* Get seperator */
            switch (PhnsetGetDateSeperatorFormat())
            {
                case 0:
                    seperator = '.';
                    break;

                case 1:
                    seperator = ':';
                    break;

                case 2:
                    seperator = '/';
                    break;

                case 3:
                    seperator = '-';
                    break;

                default:
                    seperator = '.';
                    break;
            }
        }

        /* add a space in string */
        if (flags & VFX_DATE_TIME_DAY_MASK)
        {
            *temp_w = L' ';
            temp_w += 1;            
        }

        switch (PhnsetGetDateFormat())  /* Get the current format of date */
        {
            case 0: /* day,month,year */
                {
                    if (flags & VFX_DATE_TIME_DATE_DAY)
                    {
                        sprintf(temp, "%02d", m_time.nDay);
                        mmi_asc_n_to_ucs2((CHAR *)temp_w, (CHAR *)temp, 2);
                        temp_w += 2;

                        if ((flags & VFX_DATE_TIME_DATE_MONTH) || (flags & VFX_DATE_TIME_DATE_YEAR))
                        {
                            mmi_asc_n_to_ucs2((CHAR *)temp_w, (CHAR *)&seperator, 1);
                            temp_w += 1;
                        }
                    }
                    if (flags & VFX_DATE_TIME_DATE_MONTH)
                    {
                        if (flags & VFX_DATE_TIME_FORMAT_MONTH_ENGLISH_ABBR)
                        {
                            if (m_time.nMonth >= 1 && m_time.nMonth <= 12)
                            {
                                wtemp_length = vfx_sys_wcslen((VfxWChar *)GetString(month_normal_str[m_time.nMonth - 1]));
                                vfx_sys_wcsncpy(temp_w, (VfxWChar *)GetString(month_normal_str[m_time.nMonth - 1]), wtemp_length);
                                temp_w += wtemp_length;
                            }
                        }
                        else
                        {
                            sprintf(temp, "%02d", m_time.nMonth);
                            mmi_asc_n_to_ucs2((CHAR *)temp_w, (CHAR *)temp, 2);
                            temp_w += 2;
                        }

                        if (flags & VFX_DATE_TIME_DATE_YEAR)
                        {
                            mmi_asc_n_to_ucs2((CHAR *)temp_w, (CHAR *)&seperator, 1);
                            temp_w += 1;
                        }
                    }
                    if (flags & VFX_DATE_TIME_DATE_YEAR)
                    {
                        sprintf(temp, "%04d", m_time.nYear);
                        mmi_asc_n_to_ucs2((CHAR *)temp_w, (CHAR *)temp, 4);
                        temp_w += 4;
                    }
                }
                break;

            case 1: /* month, day, year */
                {
                    if (flags & VFX_DATE_TIME_DATE_MONTH)
                    {
                        if (flags & VFX_DATE_TIME_FORMAT_MONTH_ENGLISH_ABBR)
                        {
                            if (m_time.nMonth >= 1 && m_time.nMonth <= 12)
                            {
                                wtemp_length = vfx_sys_wcslen((VfxWChar *)GetString(month_normal_str[m_time.nMonth - 1]));
                                vfx_sys_wcsncpy(temp_w, (VfxWChar *)GetString(month_normal_str[m_time.nMonth - 1]), wtemp_length);
                                temp_w += wtemp_length;
                            }
                        }
                        else
                        {
                            sprintf(temp, "%02d", m_time.nMonth);
                            mmi_asc_n_to_ucs2((CHAR *)temp_w, (CHAR *)temp, 2);
                            temp_w += 2;
                        }

                        if ((flags & VFX_DATE_TIME_DATE_DAY) || (flags & VFX_DATE_TIME_DATE_YEAR))
                        {
                            mmi_asc_n_to_ucs2((CHAR *)temp_w, (CHAR *)&seperator, 1);
                            temp_w += 1;
                        }
                    }
                    if (flags & VFX_DATE_TIME_DATE_DAY)
                    {
                        sprintf(temp, "%02d", m_time.nDay);
                        mmi_asc_n_to_ucs2((CHAR *)temp_w, (CHAR *)temp, 2);
                        temp_w += 2;

                        if (flags & VFX_DATE_TIME_DATE_YEAR)
                        {
                            mmi_asc_n_to_ucs2((CHAR *)temp_w, (CHAR *)&seperator, 1);
                            temp_w += 1;
                        }
                    }
                    if (flags & VFX_DATE_TIME_DATE_YEAR)
                    {
                        sprintf(temp, "%04d", m_time.nYear);
                        mmi_asc_n_to_ucs2((CHAR *)temp_w, (CHAR *)temp, 4);
                        temp_w += 4;
                    }
                }
                break;
                        
            case 2: /* year, month, day */
            default:
                {
                    if (flags & VFX_DATE_TIME_DATE_YEAR)
                    {
                        sprintf(temp, "%04d", m_time.nYear);
                        mmi_asc_n_to_ucs2((CHAR *)temp_w, (CHAR *)temp, 4);
                        temp_w += 4;

                        if ((flags & VFX_DATE_TIME_DATE_DAY) || (flags & VFX_DATE_TIME_DATE_MONTH))
                        {
                            mmi_asc_n_to_ucs2((CHAR *)temp_w, (CHAR *)&seperator, 1);
                            temp_w += 1;
                        }
                    }
                    if (flags & VFX_DATE_TIME_DATE_MONTH)
                    {
                        if (flags & VFX_DATE_TIME_FORMAT_MONTH_ENGLISH_ABBR)
                        {
                            if (m_time.nMonth >= 1 && m_time.nMonth <= 12)
                            {
                                wtemp_length = vfx_sys_wcslen((VfxWChar *)GetString(month_normal_str[m_time.nMonth - 1]));
                                vfx_sys_wcsncpy(temp_w, (VfxWChar *)GetString(month_normal_str[m_time.nMonth - 1]), wtemp_length);
                                temp_w += wtemp_length;
                            }
                        }
                        else
                        {
                            sprintf(temp, "%02d", m_time.nMonth);
                            mmi_asc_n_to_ucs2((CHAR *)temp_w, (CHAR *)temp, 2);
                            temp_w += 2;
                        }

                        if (flags & VFX_DATE_TIME_DATE_DAY)
                        {
                            mmi_asc_n_to_ucs2((CHAR *)temp_w, (CHAR *)&seperator, 1);
                            temp_w += 1;
                        }
                    }
                    if (flags & VFX_DATE_TIME_DATE_DAY)
                    {
                        sprintf(temp, "%02d", m_time.nDay);
                        mmi_asc_n_to_ucs2((CHAR *)temp_w, (CHAR *)temp, 2);
                        temp_w += 2;
                    }
                }
                break;
        }

        /* convert date string */
        *temp_w = L'\0';
        wtemp_length = vfx_sys_wcslen(temp_wstring);
        if (wtemp_length >= remain_length)
        {
            return;
        }
        vfx_sys_wcscpy(wtemp, temp_wstring);

        remain_length -= wtemp_length;
        wtemp += wtemp_length;
    }

    /* parse time flags */
    if (flags & VFX_DATE_TIME_TIME_MASK) 
    {
        /* Set seperator */
        seperator = ':';

        /* add a space in string */
        if ((flags & VFX_DATE_TIME_DATE_MASK) || (flags & VFX_DATE_TIME_DAY_MASK))
        {
            sprintf(temp_string, "%c", ' ');
            temp = temp_string + 1;            
        }

        if (flags & VFX_DATE_TIME_TIME_HOUR)
        {
            if (PhnsetGetTimeFormat()) /* 24 hour format */
            {
                if (flags & VFX_DATE_TIME_TIME_MINUTE)
                {
                    sprintf(temp, "%02d%c%02d", m_time.nHour, seperator, m_time.nMin);
                    temp += 5;
                }
                else
                {
                    sprintf(temp, "%02d", m_time.nHour);
                    temp += 2;
                }
            }
            else /* 12 hour format */
            {
                if (m_time.nHour == 12)
                {
                    if (flags & VFX_DATE_TIME_TIME_MINUTE)
                    {
                        if (flags & VFX_DATE_TIME_FORMAT_AMPM_LOWER_CASE)
                        {
                            sprintf(temp, "%02d%c%02d pm", m_time.nHour, seperator, m_time.nMin);
                        }
                        else
                        {
                            sprintf(temp, "%02d%c%02d PM", m_time.nHour, seperator, m_time.nMin);
                        }
                        temp += 8;
                    }
                    else
                    {
                        if (flags & VFX_DATE_TIME_FORMAT_AMPM_LOWER_CASE)
                        {
                            sprintf(temp, "%02d pm", m_time.nHour);
                        }
                        else
                        {
                            sprintf(temp, "%02d PM", m_time.nHour);
                        }
                        temp += 5;
                    }
                }
                else if (m_time.nHour == 0)
                {
                    if (flags & VFX_DATE_TIME_TIME_MINUTE)
                    {
                        if (flags & VFX_DATE_TIME_FORMAT_AMPM_LOWER_CASE)
                        {
                            sprintf(temp, "%02d%c%02d am", 12, seperator, m_time.nMin);
                        }
                        else
                        {
                            sprintf(temp, "%02d%c%02d AM", 12, seperator, m_time.nMin);
                        }
                        temp += 8;
                    }
                    else
                    {
                        if (flags & VFX_DATE_TIME_FORMAT_AMPM_LOWER_CASE)
                        {
                            sprintf(temp, "%02d am", 12);
                        }
                        else
                        {
                            sprintf(temp, "%02d AM", 12);
                        }
                        temp += 5;
                    }
                }
                else if (m_time.nHour > 12)
                {
                    if (flags & VFX_DATE_TIME_TIME_MINUTE)
                    {
                        if (flags & VFX_DATE_TIME_FORMAT_AMPM_LOWER_CASE)
                        {
                        #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
                            sprintf(temp, "%d%c%02d pm", m_time.nHour - 12, seperator, m_time.nMin);
                        #else
                            sprintf(temp, "%02d%c%02d pm", m_time.nHour - 12, seperator, m_time.nMin);
                        #endif
                        }
                        else
                        {
                        #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
                            sprintf(temp, "%d%c%02d PM", m_time.nHour - 12, seperator, m_time.nMin);
                        #else
                            sprintf(temp, "%02d%c%02d PM", m_time.nHour - 12, seperator, m_time.nMin);
                        #endif
                        }
                    #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
                        temp += 7;
                        if ((m_time.nHour - 12) > 9)
                        {
                            temp += 1;
                        }
                    #else
                        temp += 8;
                    #endif
                    }
                    else
                    {
                        if (flags & VFX_DATE_TIME_FORMAT_AMPM_LOWER_CASE)
                        {
                        #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
                            sprintf(temp, "%d pm", m_time.nHour - 12);
                        #else
                            sprintf(temp, "%02d pm", m_time.nHour - 12);
                        #endif
                        }
                        else
                        {
                        #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
                            sprintf(temp, "%d PM", m_time.nHour - 12);
                        #else
                            sprintf(temp, "%02d PM", m_time.nHour - 12);
                        #endif
                        }
                    #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
                        temp += 4;
                        if ((m_time.nHour - 12) > 9)
                        {
                            temp += 1;
                        }
                    #else
                        temp += 5;
                    #endif
                    }
                }
                else
                {
                    if (flags & VFX_DATE_TIME_TIME_MINUTE)
                    {
                        if (flags & VFX_DATE_TIME_FORMAT_AMPM_LOWER_CASE)
                        {
                        #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
                            sprintf(temp, "%d%c%02d am", m_time.nHour, seperator, m_time.nMin);
                        #else
                            sprintf(temp, "%02d%c%02d am", m_time.nHour, seperator, m_time.nMin);
                        #endif
                        }
                        else
                        {
                        #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
                            sprintf(temp, "%d%c%02d AM", m_time.nHour, seperator, m_time.nMin);
                        #else
                            sprintf(temp, "%02d%c%02d AM", m_time.nHour, seperator, m_time.nMin);
                        #endif
                        }
                    #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
                        temp += 7;
                        if (m_time.nHour > 9)
                        {
                            temp += 1;
                        }
                    #else
                        temp += 8;
                    #endif
                    }
                    else
                    {
                        if (flags & VFX_DATE_TIME_FORMAT_AMPM_LOWER_CASE)
                        {
                        #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
                            sprintf(temp, "%d am", m_time.nHour);
                        #else
                            sprintf(temp, "%02d am", m_time.nHour);
                        #endif
                        }
                        else
                        {
                        #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
                            sprintf(temp, "%d AM", m_time.nHour);
                        #else
                            sprintf(temp, "%02d AM", m_time.nHour);
                        #endif
                        }
                    #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
                        temp += 4;
                        if (m_time.nHour > 9)
                        {
                            temp += 1;
                        }
                    #else
                        temp += 5;
                    #endif
                    }
                }
            }
        }

        if (flags & VFX_DATE_TIME_TIME_SECOND)
        {
            if (PhnsetGetTimeFormat()) /* 24 hour format */
            {
                sprintf(temp, "%c%02d", seperator, m_time.nSec);
                temp += 3;
            }
            else
            {
                sprintf(temp, " %02d", m_time.nSec);
                temp += 3;
            }
        }

        /* convert date string */
        *temp = '\0';
        wtemp_length = vfx_sys_strlen(temp_string);
        if (wtemp_length >= remain_length)
        {
            return;
        }

        mmi_asc_n_to_ucs2((CHAR *)temp_wstring, (CHAR *)temp_string, wtemp_length + 1);
        vfx_sys_wcscpy(wtemp, temp_wstring);
    }
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::getDateTimeString
 * DESCRIPTION
 *  Get the date time string of date-time object.
 * PARAMETERS
 *  flags               [IN] format flags
 * RETURNS
 *  the date time string
 *****************************************************************************/
VfxWString& VfxDateTime::getDateTimeString(VfxU32 flags)
{
    VfxWChar buffer[STRING_LENGTH_MAX];

    getDateTimeString(flags, buffer, STRING_LENGTH_MAX);
    m_dateTimeStr = VFX_WSTR_MEM(buffer);

    return m_dateTimeStr;
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::is_vaild_date
 * DESCRIPTION
 *  The date is vaild or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxBool VfxDateTime::isValidDate() const
{
    applib_time_struct temp = m_time;
    if (applib_dt_check_valid_by_app(VFX_DATE_MIN_YEAR, VFX_DATE_MAX_YEAR, &temp) ==
        KAL_TRUE)
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::is_vaild_time
 * DESCRIPTION
 *  The time is vaild or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxBool VfxDateTime::isValidTime() const
{
    if (m_time.nHour > 23)
    {
        return VFX_FALSE;
    }

    if (m_time.nMin > 59)
    {
        return VFX_FALSE;
    }

    if (m_time.nSec > 59)
    {
        return VFX_FALSE;
    }
    return VFX_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::compareWith
 * DESCRIPTION
 *  Compare two date-time object.
 * PARAMETERS
 *  reference           [IN] Is the reference date-time object.
 * RETURNS
 *  VfxDateTime::CompareEnum
 * RETURN VALUES
 *  
 *****************************************************************************/
VfxDateTime::CompareEnum VfxDateTime::compareWith(
                                  const VfxDateTime &reference) const
{
    applib_time_struct time_diff;
    applib_time_struct temp = m_time;
    applib_time_struct temp_reference = reference.m_time;
    VfxS32 compare_result;

    compare_result = applib_dt_compare_time(
                         &temp,
                         &temp_reference,
                         &time_diff);
    if (compare_result == DT_TIME_GREATER)
    {
        return GREATER;
    }
    else if(compare_result == DT_TIME_LESS)
    {
        return LESS;
    }
    return EQUAL;
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::getDiff
 * DESCRIPTION
 *  Get the difference of two date-time object.
 * PARAMETERS
 *  reference           [IN] Is the reference date-time object.
 *  result              [IN] Is the date-time object to record compare result.
 * RETURNS
 *  VfxDateTime::CompareEnum
 * RETURN VALUES
 *  
 *****************************************************************************/
VfxDateTime::CompareEnum VfxDateTime::getDiff(
                                  const VfxDateTime &reference, 
                                  VfxDateTime &result) const
{
    CompareEnum compare_result;
    applib_time_struct temp = m_time;
    applib_time_struct temp_reference = reference.m_time;

    compare_result = compareWith(reference);
    if (compare_result == LESS)
    {
        applib_get_time_difference_ext(&temp_reference, &temp, &result.m_time);
    }
    else if(compare_result == GREATER)
    {
        applib_get_time_difference_ext(&temp, &temp_reference, &result.m_time);
    }
    else
    {
        result.m_time.nYear = 0;
        result.m_time.nMonth = 0;
        result.m_time.nDay = 0;
        result.m_time.nHour = 0;
        result.m_time.nMin = 0;
        result.m_time.nSec = 0;
        result.m_time.DayIndex = 0;
    }
    return compare_result;
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::increase
 * DESCRIPTION
 *  Increase the increment to one date-time object.
 * PARAMETERS
 *  increment           [IN] Is the increment.
 * RETURNS
 *  VfxBool
 * RETURN VALUES
 *  
 *****************************************************************************/
VfxBool VfxDateTime::increase(const VfxDateTime &increment)
{
    applib_time_struct result;
    applib_time_struct temp = increment.m_time;
    
    applib_dt_increase_time(&m_time, &temp, &result);
    m_time = result;
    return VFX_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  VfxDateTime::decrease
 * DESCRIPTION
 *  Decrease the increment to one date-time object.
 * PARAMETERS
 *  increment           [IN] Is the increment.
 * RETURNS
 *  VfxBool
 * RETURN VALUES
 *  
 *****************************************************************************/
VfxBool VfxDateTime::decrease(const VfxDateTime &increment)
{
    applib_time_struct result;
    applib_time_struct temp = increment.m_time;
    
    applib_dt_decrease_time(&m_time, &temp, &result);
    m_time = result;
    return VFX_TRUE;
}

