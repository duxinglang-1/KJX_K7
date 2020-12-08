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
 *   jvm_cache.cpp
 *
 * Project:
 * --------
 *   Maui_Software
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_release.h"
#include "jvm_trace_interface.h"
#include "jvm_date_time.h"
#include "DateTimeGprot.h"


#define JVM_DATE_TIME_IS_CHAR(ch) (((ch) >= 'a' && (ch) <='z') || ((ch) >='A' && (ch) <='Z'))
#define JVM_DATE_TIME_IS_DIGITAL(ch) ((ch) >= '0' && (ch) <='9')
#define JVM_DATE_TIME_IS_SEPERATOR(ch) ( ((ch) == ' ') || ((ch) == ',') || ((ch) == '-') )

/* January 1, year 1 (Gregorian) */
#define GREGORIAN_DAY_TO_JULIAN_DAY                   (1721426)
/* January 1, 1970 */
#define JAN_1_1970_GREGORIAN_DAY_TO_JULIAN_DAY           (2440588)
/* (24 * 60 * 60 * 1000) */
#define MILISPERDAT                             (86400000)

/* Julian calendar. Gregorian calendar */
static kal_int16 const DAYS_NUM[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
static kal_int16 const LEAP_DAYS_NUM[12] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};

static const kal_char *WEEKDAY_SHORTS[7] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
static const kal_char *MONTH_SHORTS[12] =
    { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
static const kal_char *WEEKDAY_FULL[7] =
    { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

/*****************************************************************************
 * FUNCTION
 *  jvm_date_time_floor_divide
 * DESCRIPTION
 *  Get the offset time form 1970/1/1 to now in day
 * PARAMETERS
 *  numerator       [IN]        
 *  denominator     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static long jvm_date_time_floor_divide(long numerator, long denominator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We do this computation in order to handle a numerator of Long.MIN_VALUE correctly */
    return (numerator >= 0) ? numerator / denominator : ((numerator + 1) / denominator) - 1;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_date_time_julianday_to_ms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  julian      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint64 jvm_date_time_julianday_to_ms(long julian)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((kal_uint64) (julian - JAN_1_1970_GREGORIAN_DAY_TO_JULIAN_DAY)) * (kal_uint64) MILISPERDAT;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_date_time_get_julian_day
 * DESCRIPTION
 *  
 * PARAMETERS
 *  year        [IN]        
 *  month       [IN]        
 *  day         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
long jvm_date_time_get_julian_day(kal_int32 year, kal_int32 month, kal_int32 day)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 y;
    long julian_day;
    kal_bool leap_year = (kal_bool)(year % 4 == 0); 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    y = year - 1;
    julian_day = 365L * y + jvm_date_time_floor_divide(y, 4) + (GREGORIAN_DAY_TO_JULIAN_DAY - 3);

    leap_year = (kal_bool)(leap_year && ((year % 100 != 0) || (year % 400 == 0)));
    /* Add 2 because Gregorian calendar starts 2 days after Julian calendar */
    julian_day += jvm_date_time_floor_divide(y, 400) - jvm_date_time_floor_divide(y, 100) + 2;
    julian_day += leap_year ? LEAP_DAYS_NUM[month] : DAYS_NUM[month];
    julian_day += day;

    return julian_day;
}

/* Return Julian time in ms from 1970 */


/*****************************************************************************
 * FUNCTION
 *  jvm_date_time_get_julian_time_ms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  year        [IN]        
 *  month       [IN]        
 *  day         [IN]        
 *  hour        [IN]        
 *  minute      [IN]        
 *  second      [IN]        
 *  milli       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint64
jvm_date_time_get_julian_time_ms(
    kal_int32 year,
    kal_int32 month,
    kal_int32 day,
    kal_int32 hour,
    kal_int32 minute,
    kal_int32 second,
    kal_int32 milli)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long julian_day = jvm_date_time_get_julian_day(year, month, day);
    kal_uint64 millis = jvm_date_time_julianday_to_ms(julian_day);

    long time_ms = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time_ms += hour;
    time_ms *= 60;
    time_ms += minute;
    time_ms *= 60;
    time_ms += second;
    time_ms *= 1000;
    time_ms += milli;
    return millis + (kal_uint64) time_ms;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_date_time_get_calendar_time
 * DESCRIPTION
 *  Get the system time in ms since 1900
 * PARAMETERS
 *  calendar_time       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_date_time_get_calendar_time(jvm_date_time_struct *calendar_time)
{

#if 0   /* remove for HAL */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  jvm_date_time_get_currenttime_tick
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
__inline kal_uint32 jvm_date_time_get_currenttime_tick(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 tick;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&tick);
#ifndef __MTK_TARGET__
    tick <<= 6;
#endif 
    return tick;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_date_time_get_currenttime_ms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
__inline kal_uint32 jvm_date_time_get_currenttime_ms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get current system ticks */
    return JVM_DATE_TIME_TICK_2_MS(jvm_date_time_get_currenttime_tick());
}


/*****************************************************************************
 * FUNCTION
 *  jvm_date_time_parse_weekday
 * DESCRIPTION
 *  
 * PARAMETERS
 *  weekday_list        [IN]        
 *  str                 [?]         
 *  str_length          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_date_time_parse_weekday(const kal_char **weekday_list, kal_char *str, kal_int32 str_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = 0, j = 0;
    kal_bool equal = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 7; i++)
    {
        equal = KAL_TRUE;
        for (j = 0; j < str_length; j++)
        {
            if (weekday_list[i][j] != str[j])
            {
                equal = KAL_FALSE;
                break;
            }
        }

        if (equal)
            return i;
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_date_time_parse_month
 * DESCRIPTION
 *  
 * PARAMETERS
 *  month_list      [IN]        
 *  str             [?]         
 *  str_length      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_date_time_parse_month(const kal_char **month_list, kal_char *str, kal_int32 str_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = 0, j = 0;
    kal_bool equal = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 12; i++)
    {
        equal = KAL_TRUE;
        for (j = 0; j < str_length; j++)
        {
            if (month_list[i][j] != str[j])
            {
                equal = KAL_FALSE;
                break;
            }
        }

        if (equal)
            return i;
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_date_time_parse_rfc1123
 * DESCRIPTION
 *  
 * PARAMETERS
 *  http_date_time_ptr      [?]     
 *  date_time               [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jvm_date_time_parse_rfc1123(
            jvm_date_time_http_formate_parse_struct *http_date_time_ptr,
            jvm_date_time_struct *date_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char a = 0, b = 0, c = 0, d = 0;
    kal_char *func_name = "jvm_date_time_parse_rfc1123";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(http_date_time_ptr != NULL);
    ASSERT(date_time != NULL);
    if (http_date_time_ptr->word_num != JVM_DATE_TIME_FORMATE_RFC1123_TOTAL ||
        http_date_time_ptr->word_length[JVM_DATE_TIME_FORMATE_RFC1123_WEEKDAY] != 3)
    {
        jvm_trace_error(
            "[%s],parse word num(length) error,word_num=%d,first word length=%d\n",
            func_name,
            http_date_time_ptr->word_num,
            http_date_time_ptr->word_length[0]);
        return KAL_FALSE;
    }

    if (jvm_date_time_parse_weekday(WEEKDAY_SHORTS, http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC1123_WEEKDAY], 3)
        < 0)
    {
        jvm_trace_error("[%s],parse weekday error\n", func_name);
        return KAL_FALSE;
    }

    /* parse day,2 digital,"DD" */
    if (http_date_time_ptr->word_length[JVM_DATE_TIME_FORMATE_RFC1123_DAY] == 2)
    {
        a = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC1123_DAY][0] - '0';
        b = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC1123_DAY][1] - '0';
        date_time->date.day = (kal_uint16) (a * 10 + b);
    }
    else
    {
        /* error */
        jvm_trace_error("[%s],parse day error\n", func_name);
        return KAL_FALSE;
    }

    /* parse month,3 chars, "Mon" */
    if (http_date_time_ptr->word_length[JVM_DATE_TIME_FORMATE_RFC1123_MONTH] == 3)
    {
        date_time->date.month =
            (kal_uint16) jvm_date_time_parse_month(
                            MONTH_SHORTS,
                            http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC1123_MONTH],
                            3);
    }
    else
    {
        /* error */
        jvm_trace_error("[%s],parse month error\n", func_name);
        return KAL_FALSE;
    }

    /* parse year,4 digital ,"YYYY" */
    if (http_date_time_ptr->word_length[JVM_DATE_TIME_FORMATE_RFC1123_YEAR] == 4)
    {
        a = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC1123_YEAR][0] - '0';
        b = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC1123_YEAR][1] - '0';
        c = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC1123_YEAR][2] - '0';
        d = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC1123_YEAR][3] - '0';

        date_time->date.year = (kal_uint16) (a * 1000 + b * 100 + c * 10 + d);
    }
    else
    {
        /* error */
        jvm_trace_error("[%s],parse year error\n", func_name);
        return KAL_FALSE;
    }

    /* parse time,4 chars,"00:00:00" ~ "23:59:59" */
    if (http_date_time_ptr->word_length[JVM_DATE_TIME_FORMATE_RFC1123_TIME] == 8
        && http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC1123_TIME][2] == ':'
        && http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC1123_TIME][5] == ':')
    {
        a = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC1123_TIME][0] - '0';
        b = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC1123_TIME][1] - '0';
        date_time->time.hour = a * 10 + b;

        a = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC1123_TIME][3] - '0';
        b = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC1123_TIME][4] - '0';
        date_time->time.minute = a * 10 + b;

        a = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC1123_TIME][6] - '0';
        b = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC1123_TIME][7] - '0';
        date_time->time.second = a * 10 + b;

        date_time->time.millisecond = 0;
    }
    else
    {
        /* error */
        jvm_trace_error("[%s],parse time error\n", func_name);
        return KAL_FALSE;
    }

    /* parse timezone,3 chars ,"GMT" */
    if (http_date_time_ptr->word_length[JVM_DATE_TIME_FORMATE_RFC1123_TIME_ZONE] == 3
        && http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC1123_TIME_ZONE][0] == 'G'
        && http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC1123_TIME_ZONE][1] == 'M'
        && http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC1123_TIME_ZONE][2] == 'T')
    {

    }
    else
    {
        /* error */
        jvm_trace_error("[%s],parse timezone error\n", func_name);
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_date_time_parse_asctime
 * DESCRIPTION
 *  
 * PARAMETERS
 *  http_date_time_ptr      [?]     
 *  date_time               [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jvm_date_time_parse_asctime(
            jvm_date_time_http_formate_parse_struct *http_date_time_ptr,
            jvm_date_time_struct *date_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char a = 0, b = 0, c = 0, d = 0;
    kal_char *func_name = "jvm_date_time_parse_asctime";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(http_date_time_ptr != NULL);
    ASSERT(date_time != NULL);
    if (http_date_time_ptr->word_num != JVM_DATE_TIME_FORMATE_ASCTIME_TOTAL ||
        http_date_time_ptr->word_length[JVM_DATE_TIME_FORMATE_ASCTIME_WEEKDAY] != 3)
    {
        jvm_trace_error(
            "[%s],parse word num(length) error,word_num=%d,first word length=%d\n",
            func_name,
            http_date_time_ptr->word_num,
            http_date_time_ptr->word_length[0]);
        return KAL_FALSE;
    }

    if (jvm_date_time_parse_weekday(WEEKDAY_SHORTS, http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_ASCTIME_WEEKDAY], 3)
        < 0)
    {
        jvm_trace_error("[%s],parse weekday error\n", func_name);
        return KAL_FALSE;
    }

    /* parse day,1 or 2 digital,"D' or "DD" */
    if (http_date_time_ptr->word_length[JVM_DATE_TIME_FORMATE_ASCTIME_DAY] == 2)
    {
        a = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_ASCTIME_DAY][0] - '0';
        b = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_ASCTIME_DAY][1] - '0';
        date_time->date.day = (kal_uint16) (a * 10 + b);
    }
    else if (http_date_time_ptr->word_length[JVM_DATE_TIME_FORMATE_ASCTIME_DAY] == 1)
    {
        a = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_ASCTIME_DAY][0] - '0';
        date_time->date.day = (kal_uint16) a;
    }
    else
    {
        /* error */
        jvm_trace_error("[%s],parse day error\n", func_name);
        return KAL_FALSE;
    }

    /* parse month,3 chars, "Mon" */
    if (http_date_time_ptr->word_length[JVM_DATE_TIME_FORMATE_ASCTIME_MONTH] == 3)
    {
        date_time->date.month =
            (kal_uint16) jvm_date_time_parse_month(
                            MONTH_SHORTS,
                            http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_ASCTIME_MONTH],
                            3);
    }
    else
    {
        /* error */
        jvm_trace_error("[%s],parse month error\n", func_name);
        return KAL_FALSE;
    }

    /* parse year,4 digital ,"YYYY" */
    if (http_date_time_ptr->word_length[JVM_DATE_TIME_FORMATE_ASCTIME_YEAR] == 4)
    {
        a = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_ASCTIME_YEAR][0] - '0';
        b = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_ASCTIME_YEAR][1] - '0';
        c = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_ASCTIME_YEAR][2] - '0';
        d = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_ASCTIME_YEAR][3] - '0';

        date_time->date.year = (kal_uint16) (a * 1000 + b * 100 + c * 10 + d);
    }
    else
    {
        /* error */
        jvm_trace_error("[%s],parse year error\n", func_name);
        return KAL_FALSE;
    }

    /* parse time,4 chars,"00:00:00" ~ "23:59:59" */
    if (http_date_time_ptr->word_length[JVM_DATE_TIME_FORMATE_ASCTIME_TIME] == 8
        && http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_ASCTIME_TIME][2] == ':'
        && http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_ASCTIME_TIME][5] == ':')
    {
        a = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_ASCTIME_TIME][0] - '0';
        b = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_ASCTIME_TIME][1] - '0';
        date_time->time.hour = a * 10 + b;

        a = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_ASCTIME_TIME][3] - '0';
        b = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_ASCTIME_TIME][4] - '0';
        date_time->time.minute = a * 10 + b;

        a = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_ASCTIME_TIME][6] - '0';
        b = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_ASCTIME_TIME][7] - '0';
        date_time->time.second = a * 10 + b;

        date_time->time.millisecond = 0;
    }
    else
    {
        /* error */
        jvm_trace_error("[%s],parse time error\n", func_name);
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_date_time_parse_rfc850
 * DESCRIPTION
 *  
 * PARAMETERS
 *  http_date_time_ptr      [?]     
 *  date_time               [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jvm_date_time_parse_rfc850(
            jvm_date_time_http_formate_parse_struct *http_date_time_ptr,
            jvm_date_time_struct *date_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char a = 0, b = 0;
    kal_char *func_name = "jvm_date_time_parse_rfc850";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(http_date_time_ptr != NULL);
    ASSERT(date_time != NULL);
    if (http_date_time_ptr->word_num != JVM_DATE_TIME_FORMATE_RFC850_TOTAL)
    {
        jvm_trace_error(
            "[%s],parse word num(length) error,word_num=%d,first word length=%d\n",
            func_name,
            http_date_time_ptr->word_num,
            http_date_time_ptr->word_length[0]);
        return KAL_FALSE;
    }

    if (jvm_date_time_parse_weekday(WEEKDAY_FULL, http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC850_WEEKDAY], 3) <
        0)
    {
        jvm_trace_error("[%s],parse weekday error\n", func_name);
        return KAL_FALSE;
    }

    /* parse day,2 digital,"DD" */
    if (http_date_time_ptr->word_length[JVM_DATE_TIME_FORMATE_RFC850_DAY] == 2)
    {
        a = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC850_DAY][0] - '0';
        b = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC850_DAY][1] - '0';
        date_time->date.day = (kal_int32) (a * 10 + b);
    }
    else
    {
        /* error */
        jvm_trace_error("[%s],parse day error\n", func_name);
        return KAL_FALSE;
    }

    /* parse month,3 chars, "Mon" */
    if (http_date_time_ptr->word_length[JVM_DATE_TIME_FORMATE_RFC850_MONTH] == 3)
    {
        date_time->date.month =
            (kal_int32) jvm_date_time_parse_month(
                            MONTH_SHORTS,
                            http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC850_MONTH],
                            3);
    }
    else
    {
        /* error */
        jvm_trace_error("[%s],parse month error\n", func_name);
        return KAL_FALSE;
    }

    /* parse year,2 digital ,"YY" */
    if (http_date_time_ptr->word_length[JVM_DATE_TIME_FORMATE_RFC850_YEAR] == 2)
    {
        a = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC850_YEAR][0] - '0';
        b = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC850_YEAR][1] - '0';

        date_time->date.year = (kal_int32) (a * 10 + b + 1900); /* ?? why need to add 1900 ?? */
    }
    else
    {
        /* error */
        jvm_trace_error("[%s],parse year error\n", func_name);
        return KAL_FALSE;
    }

    /* parse time,4 chars,"00:00:00" ~ "23:59:59" */
    if (http_date_time_ptr->word_length[JVM_DATE_TIME_FORMATE_RFC850_TIME] == 8
        && http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC850_TIME][2] == ':'
        && http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC850_TIME][5] == ':')
    {
        a = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC850_TIME][0] - '0';
        b = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC850_TIME][1] - '0';
        date_time->time.hour = a * 10 + b;

        a = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC850_TIME][3] - '0';
        b = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC850_TIME][4] - '0';
        date_time->time.minute = a * 10 + b;

        a = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC850_TIME][6] - '0';
        b = http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC850_TIME][7] - '0';
        date_time->time.second = a * 10 + b;

        date_time->time.millisecond = 0;
    }
    else
    {
        /* error */
        jvm_trace_error("[%s],parse time error\n", func_name);
        return KAL_FALSE;
    }

    /* parse timezone,3 chars ,"GMT" */
    if (http_date_time_ptr->word_length[JVM_DATE_TIME_FORMATE_RFC850_TIME_ZONE] == 3
        && http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC850_TIME_ZONE][0] == 'G'
        && http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC850_TIME_ZONE][1] == 'M'
        && http_date_time_ptr->word[JVM_DATE_TIME_FORMATE_RFC850_TIME_ZONE][2] == 'T')
    {

    }
    else
    {
        /* error */
        jvm_trace_error("[%s],parse timezone error\n", func_name);
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_date_time_parse_http_date_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  date_time_str               [?]         
 *  date_time_str_length        [IN]        
 *  date_time                   [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jvm_date_time_parse_http_date_time(
            kal_char *date_time_str,
            kal_int32 date_time_str_length,
            jvm_date_time_struct *date_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = 0;
    kal_bool new_word_start = KAL_FALSE;
    kal_int32 new_word_start_index = 0;
    kal_int32 word_length = 0;
    jvm_date_time_http_formate_parse_struct http_date_time_struct;
    kal_char *func_name = "jvm_date_time_parse_http_date_time";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_info("[%s]str=%s,length=%d\n", func_name, date_time_str, date_time_str_length);

    memset(&http_date_time_struct, 0x00, sizeof(jvm_date_time_http_formate_parse_struct));
    for (i = 0; i < date_time_str_length; i++)
    {
        if (JVM_DATE_TIME_IS_SEPERATOR(date_time_str[i]) || i == (date_time_str_length - 1))
        {
            if (new_word_start)
            {
                /* find a new word */
                http_date_time_struct.word[http_date_time_struct.word_num] = date_time_str + new_word_start_index;
                if (i == (date_time_str_length - 1) && !JVM_DATE_TIME_IS_SEPERATOR(date_time_str[i]))
                {
                    word_length = i - new_word_start_index + 1;
                }
                else
                {
                    word_length = i - new_word_start_index;
                }
                http_date_time_struct.word_length[http_date_time_struct.word_num] = word_length;

                if (http_date_time_struct.word_num == 1)
                {
                    if (http_date_time_struct.word_length[0] > 3)
                    {
                        http_date_time_struct.formate_type = JVM_DATE_TIME_FORMATE_RFC850;
                    }
                    else if (JVM_DATE_TIME_IS_CHAR(http_date_time_struct.word[http_date_time_struct.word_num][0]))
                    {
                        http_date_time_struct.formate_type = JVM_DATE_TIME_FORMATE_ASCTIME;
                    }
                    else if (JVM_DATE_TIME_IS_DIGITAL(http_date_time_struct.word[http_date_time_struct.word_num][0]))
                    {
                        http_date_time_struct.formate_type = JVM_DATE_TIME_FORMATE_RFC1123;
                    }
                    else
                    {
                        http_date_time_struct.formate_type = JVM_DATE_TIME_FORMATE_UNKNOWN;
                    }
                }

                http_date_time_struct.word_num++;
                new_word_start = KAL_FALSE;
            }
            else
            {
                continue;
            }
        }
        else if (JVM_DATE_TIME_IS_CHAR(date_time_str[i]) || JVM_DATE_TIME_IS_DIGITAL(date_time_str[i]))
        {
            if (!new_word_start)
            {
                new_word_start = KAL_TRUE;
                new_word_start_index = i;
            }
            else
            {
                continue;
            }
        }
        else if (date_time_str[i] == '-' || date_time_str[i] == ':')
        {
            if (!new_word_start)
            {
                /* formate error */
                jvm_trace_error("[%s],string formate error1");
                return KAL_FALSE;

            }
            else
            {
                continue;
            }
        }
        else
        {
            /* formate error */
            jvm_trace_error("[%s],string formate error2");
            return KAL_FALSE;
        }
    }

    switch (http_date_time_struct.formate_type)
    {
        case JVM_DATE_TIME_FORMATE_RFC1123:
            return jvm_date_time_parse_rfc1123(&http_date_time_struct, date_time);
        case JVM_DATE_TIME_FORMATE_RFC850:
            return jvm_date_time_parse_rfc850(&http_date_time_struct, date_time);
        case JVM_DATE_TIME_FORMATE_ASCTIME:
            return jvm_date_time_parse_asctime(&http_date_time_struct, date_time);
        default:
            return KAL_FALSE;
    }
}

