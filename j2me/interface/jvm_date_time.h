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
 *   jvm_date_time.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __JVM_DATE_TIME_H__
#define __JVM_DATE_TIME_H__

typedef struct
{
    kal_int32 year;
    kal_int32 month;
    kal_int32 day;
    
}jvm_date_struct;

typedef struct
{
    kal_int32 hour;
    kal_int32 minute;
    kal_int32 second;
    kal_int32 millisecond;
}jvm_time_struct;

typedef struct
{
    jvm_date_struct date;
    jvm_time_struct time;
    kal_int32 timezone;
}jvm_date_time_struct;

typedef enum
{
    JVM_DATE_TIME_FORMATE_RFC1123,
    JVM_DATE_TIME_FORMATE_RFC850,
    JVM_DATE_TIME_FORMATE_ASCTIME,
    JVM_DATE_TIME_FORMATE_UNKNOWN,
    JVM_DATE_TIME_FORMATE_TOTAL
}jvm_date_time_formate_enum;

typedef enum
{   
    JVM_DATE_TIME_FORMATE_RFC1123_WEEKDAY   = 0,
    JVM_DATE_TIME_FORMATE_RFC1123_DAY       = 1,
    JVM_DATE_TIME_FORMATE_RFC1123_MONTH     = 2,
    JVM_DATE_TIME_FORMATE_RFC1123_YEAR      = 3,
    JVM_DATE_TIME_FORMATE_RFC1123_TIME      = 4,
    JVM_DATE_TIME_FORMATE_RFC1123_TIME_ZONE = 5,

    JVM_DATE_TIME_FORMATE_RFC1123_TOTAL
}jvm_date_time_formate_rfc1123_enum;


typedef enum
{   
    JVM_DATE_TIME_FORMATE_RFC850_WEEKDAY   = 0,
    JVM_DATE_TIME_FORMATE_RFC850_DAY       = 1,
    JVM_DATE_TIME_FORMATE_RFC850_MONTH     = 2,
    JVM_DATE_TIME_FORMATE_RFC850_YEAR      = 3,
    JVM_DATE_TIME_FORMATE_RFC850_TIME      = 4,
    JVM_DATE_TIME_FORMATE_RFC850_TIME_ZONE = 5,

    JVM_DATE_TIME_FORMATE_RFC850_TOTAL
}jvm_date_time_formate_rfc850_enum;

typedef enum
{   
    JVM_DATE_TIME_FORMATE_ASCTIME_WEEKDAY   = 0,
    JVM_DATE_TIME_FORMATE_ASCTIME_MONTH     = 1,
    JVM_DATE_TIME_FORMATE_ASCTIME_DAY       = 2,
    JVM_DATE_TIME_FORMATE_ASCTIME_TIME      = 3,
    JVM_DATE_TIME_FORMATE_ASCTIME_YEAR      = 4,

    JVM_DATE_TIME_FORMATE_ASCTIME_TOTAL
}jvm_date_time_formate_asctime_enum;


typedef struct
{
    jvm_date_time_formate_enum formate_type;
    kal_int32 word_num;
    kal_char * word[6];
    kal_int32  word_length[6];
}jvm_date_time_http_formate_parse_struct;


                      
#define JVM_DATE_TIME_GET_TIME_ZONE                          mmi_dt_get_tz
#define JVM_DATE_TIME_GET_HOME_CITY                          mmi_wc_get_home_city
#define JVM_DATE_TIME_MS_2_TICK(ms)                          (kal_uint32)(((kal_uint64)(ms) * 14200) >> 16)
#define JVM_DATE_TIME_TICK_2_MS(tick)                        (kal_uint32)(((kal_uint64)(tick) * 302448) >> 16)
extern kal_uint32 jvm_date_time_get_currenttime_tick(void);
extern kal_uint32 jvm_date_time_get_currenttime_ms(void);

/**
 *  HTTP-date      = rfc1123-date | rfc850-date | asctime-date
 *  rfc1123-date   = wkday "," SP date1 SP time SP "GMT"
 *  rfc850-date    = weekday "," SP date2 SP time SP "GMT"
 *  asctime-date   = wkday SP date3 SP time SP 4DIGIT
 *  date1          = 2DIGIT SP month SP 4DIGIT
 *                  ; day month year (e.g., 02 Jun 1982)
 *  date2          = 2DIGIT "-" month "-" 2DIGIT
 *                  ; day-month-year (e.g., 02-Jun-82)
 *  date3          = month SP ( 2DIGIT | ( SP 1DIGIT ))
 *                  ; month day (e.g., Jun  2)
 *  time           = 2DIGIT ":" 2DIGIT ":" 2DIGIT
 *                  ; 00:00:00 - 23:59:59
 *  wkday          = "Mon" | "Tue" | "Wed"
 *                | "Thu" | "Fri" | "Sat" | "Sun"
 *  weekday        = "Monday" | "Tuesday" | "Wednesday"
 *                | "Thursday" | "Friday" | "Saturday" | "Sunday"
 *  month          = "Jan" | "Feb" | "Mar" | "Apr"
 *                | "May" | "Jun" | "Jul" | "Aug"
 *                | "Sep" | "Oct" | "Nov" | "Dec"
 */
extern kal_bool jvm_date_time_parse_http_date_time(kal_char * date_time_str,kal_int32 date_time_str_length, jvm_date_time_struct * date_time);

#endif /*__JVM_DATE_TIME_H__ */
