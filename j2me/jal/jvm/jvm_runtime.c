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
 *   jvm_runtime.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements JAL system service APIs
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
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * Include Header iles
 *************************************************************************/
#include "jal.h"
#include "jvm_interface.h"
#include "jvm_internal.h"
#include "jam_msg_handler.h"
#include "jam_internal.h"
////#include "rtc_sw.h"
////#include "gpt_sw.h"
#include "dcl.h"
#ifdef DATACACHE_FBBR_ON
#include "intrCtrl.h"
#include "cache_sw.h"
#endif /* DATACACHE_FBBR_ON */ /* defined(__MTK_TARGET__) && defined(MT6228) */
#include "app_crc.h"
#include "nvram_enums.h"
#include "nvram_interface.h"

#include "wap_ps_struct.h"  /* jvm_get_imei_value_with_default() use its enum */
#include "Browser_struct.h"

/*************************************************************************
 * Global Definition and Declaration
 *************************************************************************/

static DCL_HANDLE jvm_rtc_handler = -1;

/* January 1, year 1 (Gregorian) */
#define GREGORIAN_DAY_TO_JULIAN_DAY                   (1721426)
/* January 1, 1970 */
#define JAN_1_1970_GREGORIAN_DAY_TO_JULIAN_DAY           (2440588)
/* (24 * 60 * 60 * 1000) */
#define MILISPERDAT                             (86400000)

/* Julian calendar. Gregorian calendar */
short const NUM_DAYS[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
short const LEAP_NUM_DAYS[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};

/* If allocate Java heap from static memory, use pointer address directly */
long *javaheap_space;
kal_uint32 javaheap_size;
long *javaruntime_space;
kal_uint32 javaruntime_size;
kal_uint32 javaruntime_poolflag = 0;

unsigned max_java_use_space;

#if DATACACHE_FBBR_ON
static kal_int32 saveFBBRvalue;
static kal_bool FBBR_initialized = KAL_FALSE;
#endif /* DATACACHE_FBBR_ON */ 

extern kal_uint32 EnableFBBR(void);
extern void DisableFBBR(kal_uint32 val);
extern kal_bool g_jam_is_jvm_in_busy;

static kal_uint8 jvm_imsi[17];
static kal_int32 jvm_imsi_error;

extern kal_eventgrpid g_java_event_group_2;

#ifndef __MTK_TARGET__
extern kal_mutexid g_jam_modis_printf_mutex;
#endif
/* Timer ID */
#define JVM_BASE_TIMER_ID 0x0000
#define MAX_NUM_OF_JVM_TIMER 20

typedef struct
{
    eventid event_id;
    kal_timer_func_ptr callback_func;
    void *arg;
} jvm_timer_table_struct;

jvm_timer_table_struct jvm_timer_table[MAX_NUM_OF_JVM_TIMER];
event_scheduler *jvm_event_scheduler_ptr;
//stack_timer_struct jvm_base_timer;
extern kal_mutexid g_jam_timer_mutex;

extern kal_uint32 custom_get_NORFLASH_Base(void);
extern kal_bool INT_IsBootByCodeShadow(void);

extern cbm_sim_id_enum cbm_get_sim_id(kal_uint32 acct_id);

#define IMEI_DATA_LENGTH 16

/*************************************************************************
 * Function Definition
 *************************************************************************/


#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_worldclock_gprot.h"
#else
#include "worldclock.h"
extern FLOAT mmi_dt_get_tz(void);
#endif /* __COSMOS_MMI_PACKAGE__ */

/*****************************************************************************
 * FUNCTION
 *  jvm_get_timezone_impl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  time zone        
 * RETURNS
 *  
 *****************************************************************************/
float jvm_get_timezone_impl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __COSMOS_MMI_PACKAGE__
    ////if( jam_mvm_has_work_instance())    //should not call get_time_zone when task created for native function maybe not initialized
    ////    return mmi_wc_get_time_zone(mmi_wc_get_home_index());
    return 0;
#else
    return (float)mmi_dt_get_tz();
#endif /* __COSMOS_MMI_PACKAGE__ */
    
}


/*****************************************************************************
 * FUNCTION
 *  jvm_get_home_city_impl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void 
 * RETURNS
 *  city name
 *****************************************************************************/
kal_int8 * jvm_get_home_city_impl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __COSMOS_MMI_PACKAGE__
    return (kal_int8 *)GetString(mmi_wc_get_city_strid(mmi_wc_get_home_index()));
    
#else
    return (kal_int8 *)mmi_wc_get_home_city();
#endif /* __COSMOS_MMI_PACKAGE__ */
}


/*****************************************************************************
 * FUNCTION
 *  jvm_allocate_heap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 *jvm_allocate_heap(long size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 *heap_ptr = (kal_uint32*) javaheap_space;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32*) heap_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_release_heap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  space       [?] 
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_release_heap(kal_uint32 *space)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  jvm_get_heap_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 jvm_get_heap_size()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return javaheap_size;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_get_calendar_time
 * DESCRIPTION
 *  Get the system time in ms since 1900
 * PARAMETERS
 *  calendar_time       [?] 
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_get_calendar_time(kal_uint32 *calendar_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    RTC_CTRL_GET_TIME_T sys_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ////kal_mem_set(&sys_time, 0, sizeof(t_rtc));

    /* Save system time */
    ////RTC_GetTime((t_rtc*) & sys_time);

    if( jvm_rtc_handler == -1)
    {
        jvm_rtc_handler = DclRTC_Open(DCL_RTC, FLAGS_NONE);
    }
    
    DclRTC_Control(jvm_rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *)&sys_time);

    calendar_time[YEAR] = sys_time.u1Year+ 100;  /* In CLDC, year is from 00; that is, 1 is 1901 */
    calendar_time[MONTH] = sys_time.u1Mon- 1;    /* In CLDC, month is from 0 to 11 */
    calendar_time[DAY_OF_MONTH] = sys_time.u1Day;
    calendar_time[HOUR] = sys_time.u1Hour;
    calendar_time[MINUTE] = sys_time.u1Min;
    calendar_time[SECOND] = sys_time.u1Sec;    

    /* We cannot accurately determine this value, so set it to 0 for now */
    calendar_time[MILLISECOND] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_task_sleep
 * DESCRIPTION
 *  debug print
 * PARAMETERS
 *  sleep_ticks     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_task_sleep(kal_uint32 sleep_ticks)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_sleep_task(sleep_ticks);
}


/*****************************************************************************
 * FUNCTION
 *  _floor_divide
 * DESCRIPTION
 *  Get the offset time form 1970/1/1 to now in day
 * PARAMETERS
 *  numerator       [IN]        
 *  denominator     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static long _floor_divide(long numerator, long denominator)
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
 *  _julianday_to_ms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  julian      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint64 _julianday_to_ms(long julian)
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
 *  jvm_get_julian_day
 * DESCRIPTION
 *  
 * PARAMETERS
 *  year        [IN]        
 *  month       [IN]        
 *  day         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
long jvm_get_julian_day(int year, int month, int day)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int y;
    long julian_day;
    kal_bool leap_year = (kal_bool)(year % 4 == 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    y = year - 1;
    julian_day = 365L * y + _floor_divide(y, 4) + (GREGORIAN_DAY_TO_JULIAN_DAY - 3);

    leap_year = (kal_bool)(leap_year && ((year % 100 != 0) || (year % 400 == 0)));
    /* Add 2 because Gregorian calendar starts 2 days after Julian calendar */
    julian_day += _floor_divide(y, 400) - _floor_divide(y, 100) + 2;
    julian_day += leap_year ? LEAP_NUM_DAYS[month] : NUM_DAYS[month];
    julian_day += day;

    return julian_day;
}

/* Return Julian time in ms from 1970 */


/*****************************************************************************
 * FUNCTION
 *  jvm_get_julian_time_ms
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
jvm_get_julian_time_ms(
    unsigned short year,
    unsigned char month,
    unsigned char day,
    unsigned char hour,
    unsigned char minute,
    unsigned char second,
    int milli)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long julian_day = jvm_get_julian_day(year, month, day);
    kal_uint64 millis = _julianday_to_ms(julian_day);

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
 *  jvm_str_dup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string      [?] 
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_char *jvm_str_dup(kal_char *string, kal_int32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (string == NULL)
    {
        return (kal_char*) NULL;
    }

    ptr = (kal_char*) get_ctrl_buffer(length + 1);
    if (ptr == NULL)
    {
        return NULL;
    }

    kal_mem_cpy(ptr, string, length);
    ptr[length] = 0;

    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  FBBR_heap_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FBBR_heap_init(void)
{
#if DATACACHE_FBBR_ON
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long* local_javaheap_space;
    kal_uint32 local_javaheap_sizeoffset;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_jam_is_jvm_in_busy)
    {
        return;
    }

    if (INT_IsBootByCodeShadow() == KAL_FALSE && 
        custom_get_NORFLASH_Base() != 0x0 )
    {
        local_javaheap_space = NULL;
        local_javaheap_sizeoffset = (kal_uint32)javaheap_space;
    }
    else
    {
        local_javaheap_space = javaheap_space;
        local_javaheap_sizeoffset = 0;
    }
    

    if (!FBBR_initialized)
    {
        FBBR_initialized = KAL_TRUE;
        if (javaheap_size == 512 * 1024 || javaheap_size == 768 * 1024)
        {
            ASSERT((((int)local_javaheap_space) & (256 * 1024 - 1)) == 0);
        }
        else if (javaheap_size == 1024 * 1024 || javaheap_size == 1280 * 1024 || javaheap_size == 1152 * 1024)
        {
            /* MT6229 has more cache regiesters to be used by Java */
            ASSERT((((int)local_javaheap_space) & (512 * 1024 - 1)) == 0);
        }
        else if (javaheap_size == 1536 * 1024)
        {
            ASSERT((((int)local_javaheap_space) & (512 * 1024 - 1)) == 0);
        }
        else if (javaheap_size == 2 * 1024 * 1024 || javaheap_size == 3 * 1024 * 1024 ||
                 javaheap_size == 5 * 1024 * 1024)
        {
            ASSERT((((int)local_javaheap_space) & (1024 * 1024 - 1)) == 0);
        }
        else if (javaheap_size == 4 * 1024 * 1024 || javaheap_size == 6 * 1024 * 1024 ||
                 javaheap_size == 8 * 1024 * 1024)
        {
            ASSERT((((int)local_javaheap_space) & (2 * 1024 * 1024 - 1)) == 0);
        }
        else
        {
            ASSERT(0);
        }
        saveFBBRvalue = EnableFBBR();
        jvm_init_cache((unsigned char*)local_javaheap_space, (unsigned char*)local_javaheap_space + javaheap_size);
        
                
        javaheap_size -= local_javaheap_sizeoffset; 
    }
#endif /* DATACACHE_FBBR_ON */ 
}


/*****************************************************************************
 * FUNCTION
 *  FBBR_heap_finalize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FBBR_heap_finalize(void)
{
#if DATACACHE_FBBR_ON
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FBBR_initialized)
    {
        FBBR_initialized = KAL_FALSE;
        jvm_release_cache();
        DisableFBBR(saveFBBRvalue);
        
        if (INT_IsBootByCodeShadow() == KAL_FALSE && 
            custom_get_NORFLASH_Base() != 0x0 )
        {
            javaheap_size += (kal_uint32)javaheap_space;
        }

    }
#endif /* DATACACHE_FBBR_ON */ 
}

#if DATACACHE_FBBR_ON
#pragma arm section code = "INTERNCODE"
#endif /* #if defined(MT6228) || defined(MT6229) || defined(MT6230) */


/*****************************************************************************
 * FUNCTION
 *  FBBR_invalid_l1_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst         [?] 
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *FBBR_invalid_l1_cache(void *dst, kal_int32 length)
{
#if DATACACHE_FBBR_ON
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *startPtr = (U8*) dst;

    /* kal_int32 lineWidth = length; */
    U8 *invalidPtr;
    U8 *invalidPtrEnd;
    kal_int32 interruptMask;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!FBBR_initialized || (int)dst < (int)javaheap_space || (int)dst > (int)((char*)javaheap_space + javaheap_size))
    {
        return dst;
    }

    invalidPtr = (U8*) ((kal_int32) startPtr & (~0x1f));
    length >>= 5;

    if (startPtr != invalidPtr)
    {
        length += 2;
    }
    else
    {
        length++;
    }

    /*    if (((((kal_uint32) (((lineWidth << 27) >> 27) + startPtr)) >> 5) << 5) != (kal_uint32) invalidPtr)
       {
       length++;
       } */

    if (length <= 0)
    {
        return dst;
    }

    invalidPtrEnd = invalidPtr + (length << 5);

    interruptMask = SaveAndSetIRQMask();

    do
    {
        InvalidCodeCacheByAlignedAddr((kal_int32) invalidPtr);
        invalidPtr += 32;
        /*
         * enable the interrupt a while to prevent precision problem for CTIRQ 
         * * (Every 256 cache-invaliations)
         */
        if (((unsigned int)invalidPtr << 19) == 0)
        {
        #if defined(MT6228) || defined(MT6229)
            *CACHE_OP = 9 | 0x10000;    /* need to be modified */
            *CACHE_OP = 9 | 0x20000;
            *CACHE_OP = 9 | 0x40000;
            *CACHE_OP = 9 | 0x80000;
        #endif /* defined(MT6228) || defined(MT6229) */ /* #if defined(MT6228) || defined(MT6229) */
            RestoreIRQMask(interruptMask);
            interruptMask = SaveAndSetIRQMask();
        }
    } while ((kal_int32) invalidPtr < (kal_int32) invalidPtrEnd);

    /*
     * important for invalidation by address
     * * this is a software work-around for solving L1 invalidation by address bug
     */
#if defined(MT6228) || defined(MT6229)
    *CACHE_OP = 9 | 0x10000;    /* need to be modified */
    *CACHE_OP = 9 | 0x20000;
    *CACHE_OP = 9 | 0x40000;
    *CACHE_OP = 9 | 0x80000;
#endif /* defined(MT6228) || defined(MT6229) */ /* #if defined(MT6228) || defined(MT6229) */
    RestoreIRQMask(interruptMask);

    /* the bit 26 setting to on means bypassing the cache. 
       This will ensure the L2 will not cache the L1 cacheable area */
    dst = (unsigned short*)((kal_int32) dst | 0x4000000);

#endif /* DATACACHE_FBBR_ON */ 
    return dst;

}


/*****************************************************************************
 * FUNCTION
 *  FBBR_invalid_l1_cache_img
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst             [?] 
 *  x_pos           [IN]        
 *  y_pos           [IN]        
 *  width           [IN]        
 *  height          [IN]        
 *  dst_width       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *FBBR_invalid_l1_cache_img(void *dst, int x_pos, int y_pos, int width, int height, int dst_width)
{
#if DATACACHE_FBBR_ON
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* invalidating l1 cache entry starts here */

    U8 *startPtr = (U8*) dst + ((y_pos * dst_width + x_pos) << 1);
    kal_int32 lineWidth = width;
    U8 *invalidPtr = (U8*) ((kal_int32) startPtr & (~0x1f));
    kal_int32 width_count;
    kal_int32 i, j;
    kal_int32 interruptMask;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* make sure not use the function when FBBR not initilized */
    /* if(!FBBR_initialized || (int)dst < (int)javaheap_space || 
       (int)dst > (int)((char*)javaheap_space + javaheap_size)){
       return dst;
       } */

    width_count = lineWidth >> 4;

    if (startPtr != invalidPtr)
    {
        width_count++;
    }

    if ((startPtr + (width << 1)) > (invalidPtr + (width_count << 5)))
    {
        width_count++;
    }

    if (width_count <= 0)
    {
        return dst;
    }

    interruptMask = SaveAndSetIRQMask();

    if ((width_count << 4) >= dst_width)
    {
        /* memset(invalidPtr - 5, 0x66, (dst_->width * height) << 1); */
        U8 *invalidPtrEnd = invalidPtr + ((dst_width * height) << 1);

        do
        {
            InvalidCodeCacheByAlignedAddr((kal_int32) invalidPtr);
            invalidPtr += 32;
            if (((unsigned int)invalidPtr << 19) == 0)
            {
            #if defined(MT6228) || defined(MT6229)
                *CACHE_OP = 9 | 0x10000;    /* need to be modified */
                *CACHE_OP = 9 | 0x20000;
                *CACHE_OP = 9 | 0x40000;
                *CACHE_OP = 9 | 0x80000;
            #endif /* defined(MT6228) || defined(MT6229) */ /* #if defined(MT6228) || defined(MT6229) */
                RestoreIRQMask(interruptMask);
                interruptMask = SaveAndSetIRQMask();
            }
        } while ((kal_int32) invalidPtr < (kal_int32) invalidPtrEnd);
    }
    else
    {
        if (width_count > 64)
        {
            int counter = 256;

            for (i = 0; i < height; i++)
            {
                /* memset(invalidPtr - 5, 0x66, width_count << 5); */
                for (j = 0; j < width_count; j++)
                {
                    /* invalid l1 cache line */
                    //                                           *CACHE_OP = ((((unsigned int)invalidPtr) << 19) >> 19) | 9 | 0x10000;
                    //                                           *CACHE_OP = ((((unsigned int)invalidPtr) << 19) >> 19) | 9 | 0x20000;
                    //                                           *CACHE_OP = ((((unsigned int)invalidPtr) << 19) >> 19) | 9 | 0x40000;
                    //                                           *CACHE_OP = ((((unsigned int)invalidPtr) << 19) >> 19) | 9 | 0x80000;
                    InvalidCodeCacheByAlignedAddr((kal_int32) invalidPtr);
                    /* *CACHE_OP = (int)invalidPtr; */
                    invalidPtr += 32;
                    /*
                     * enable the interrupt a while to prevent precision problem for CTIRQ 
                     * * (Every 256 cache-invaliations)
                     */
                    if ((counter--) == 0)
                    {
                        counter = 256;
                    #if defined(MT6228) || defined(MT6229)
                        *CACHE_OP = 9 | 0x10000;    /* need to be modified */
                        *CACHE_OP = 9 | 0x20000;
                        *CACHE_OP = 9 | 0x40000;
                        *CACHE_OP = 9 | 0x80000;
                    #endif /* defined(MT6228) || defined(MT6229) */ /* #if defined(MT6228) || defined(MT6229) */
                        RestoreIRQMask(interruptMask);
                        interruptMask = SaveAndSetIRQMask();
                    }
                }
                startPtr += (dst_width << 1);
                invalidPtr = (U8*) ((kal_int32) startPtr & (~0x1F)) + 5;
            }
        }
        else
        {
            int counter = 128;

            for (i = 0; i < height; i++)
            {
                /* memset(invalidPtr - 5, 0x66, width_count << 5); */
                for (j = 0; j < width_count; j++)
                {
                    /* invalid l1 cache line */
                    //                                           *CACHE_OP = ((((unsigned int)invalidPtr) << 19) >> 19) | 9 | 0x10000;
                    //                                           *CACHE_OP = ((((unsigned int)invalidPtr) << 19) >> 19) | 9 | 0x20000;
                    //                                           *CACHE_OP = ((((unsigned int)invalidPtr) << 19) >> 19) | 9 | 0x40000;
                    //                                           *CACHE_OP = ((((unsigned int)invalidPtr) << 19) >> 19) | 9 | 0x80000;
                    InvalidCodeCacheByAlignedAddr((kal_int32) invalidPtr);
                    /* *CACHE_OP = (int)invalidPtr; */
                    invalidPtr += 32;
                    /*
                     * enable the interrupt a while to prevent precision problem for CTIRQ 
                     * * (Every 64 cache-invaliations)
                     */
                    counter--;
                }
                if ((counter--) <= 0)
                {
                    counter = 128;
                #if defined(MT6228) || defined(MT6229)
                    *CACHE_OP = 9 | 0x10000;    /* need to be modified */
                    *CACHE_OP = 9 | 0x20000;
                    *CACHE_OP = 9 | 0x40000;
                    *CACHE_OP = 9 | 0x80000;
                #endif /* defined(MT6228) || defined(MT6229) */ /* #if defined(MT6228) || defined(MT6229) */
                    RestoreIRQMask(interruptMask);
                    interruptMask = SaveAndSetIRQMask();
                }
                startPtr += (dst_width << 1);
                invalidPtr = (U8*) ((kal_int32) startPtr & (~0x1F)) + 5;
            }
        }
    }
    /*
     * important for invalidation by address
     * * this is a software work-around for solving L1 invalidation by address bug
     */
#if defined(MT6228) || defined(MT6229)
    *CACHE_OP = 9 | 0x10000;    /* need to be modified */
    *CACHE_OP = 9 | 0x20000;
    *CACHE_OP = 9 | 0x40000;
    *CACHE_OP = 9 | 0x80000;
#endif /* defined(MT6228) || defined(MT6229) */ /* #if defined(MT6228) || defined(MT6229) */
    RestoreIRQMask(interruptMask);

    /* the bit 26 setting to on means bypassing the cache. 
       This will ensure the L2 will not cache the L1 cacheable area */
    dst = (unsigned short*)((kal_int32) dst | 0x4000000);

    /* *CACHE_OP = 0x3; */
    /* end of cache manipulation */
#endif /* DATACACHE_FBBR_ON */ 
    return dst;
}

#if DATACACHE_FBBR_ON
#pragma arm section code
#endif 


/*****************************************************************************
 * FUNCTION
 *  jvm_recv_get_imsi_res
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_recv_get_imsi_res(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_get_imsi_res_struct *msg;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_java_get_imsi_res_struct*) MsgStruct;

    jvm_imsi_error = msg->error;

    for (i = 0; i < 17; i++)
    {
        jvm_imsi[i] = msg->imsi[i];
    }

    kal_set_eg_events(g_java_event_group_2, J2ME_EG_GET_IMSI, KAL_OR);
}


/*****************************************************************************
 * FUNCTION
 *  jvm_send_get_imsi_ind
 * DESCRIPTION
 *  Send MSG_ID_MMI_JAVA_GET_IMSI_IND to MMI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_send_get_imsi_ind(kal_int8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //ilm_struct *ilm_ptr;
    mmi_java_get_imsi_ind_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_java_get_imsi_ind_struct*) construct_local_para(sizeof(mmi_java_get_imsi_ind_struct),TD_CTRL);
    msg->sim_id = sim_id;
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_GET_IMSI_IND,msg);
}

/*****************************************************************************
 * FUNCTION
 *  jvm_get_imsi_all
 * DESCRIPTION
 *  get imsi of SIM card
 * PARAMETERS
 *  void
 * RETURNS
 *  return NULL if fail
 *  return a uint8 array with size 3 back, caller should release
 *  this array by jvm_free
 *****************************************************************************/
void jvm_get_imsi_all(kal_uint8* buf,int vmId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 event_group;
    kal_uint8 i;
    kal_uint8 sim_id;
    srv_dtcnt_prof_proxy_info_cnf_struct* prof;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prof = jam_mvm_get_network_profile_by_vm_id(vmId);
    sim_id = cbm_get_sim_id(prof->px_info.acc_id);
    jvm_send_get_imsi_ind(sim_id);
    kal_retrieve_eg_events(g_java_event_group_2, J2ME_EG_GET_IMSI, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
    if (jvm_imsi_error != J2ME_NO_ERROR)
    {
        for (i = 0; i < 16; i++)
        {
            buf[i] = 0;
        }
    }
    else
    {
        for (i = 1; i < 17; i++)
        {
            buf[i-1] = jvm_imsi[i];
        }
    }

    return;
}

#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  jvm_get_imei_value
 * DESCRIPTION
 *  To get the activated sim card's IMEI value, if WiFi or others, return sim1's value
 * PARAMETERS
 *  imei_buf    [OUT]       buffer to fill in IMEI
 * RETURNS
 *  KAL_TRUE: SUCCESS
 *  KAL_FALSE: FAIL
 *****************************************************************************/
kal_bool jvm_get_imei_value_with_default(kal_uint8 *imei_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 sim_id; 
    kal_bool is_always_ask = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
    sim_id = WAP_SIM_ID_SIM1; 
    
#ifdef __MMI_DUAL_SIM_MASTER__    
    if (!is_always_ask &&
        (jam_nw_get_sim_id(jam_mvm_get_storage_name_by_vm_id(0)) == WAP_SIM_ID_SIM2))
    {
        sim_id = WAP_SIM_ID_SIM2;
    }
#endif

    return jvm_get_imei_value(IMEI_DATA_LENGTH, imei_buf, sim_id);
    
}


/*****************************************************************************
 * FUNCTION
 *  jvm_get_imei_value
 * DESCRIPTION
 *  To get the IMEI value via blocking function
 *  @TODO remove length parameter and notify ijet & aplix.
 * PARAMETERS
 *  length      [IN]        Length of imei_buf, in byte, at least 8 bytes.
 *  imei_buf    [OUT]       buffer to fill in IMEI
 *  rec_index   [IN]        Can be 1 or 2 to access both IMEI on dual sim project.
 *                          It should be 1 on single sim project.
 * RETURNS
 *  KAL_TRUE: SUCCESS
 *  KAL_FALSE: FAIL
 *****************************************************************************/
kal_bool jvm_get_imei_value(kal_uint8 length, kal_uint8 *imei_buf, kal_uint16 rec_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 imei_BCD_buf[8];
    kal_uint8 i; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
    if(nvram_get_imei_value(8, imei_BCD_buf, rec_index))
    {
        for(i=0;i<8;i++)
        {
            imei_buf[2*i] = (kal_uint8)((imei_BCD_buf[i] & 0xF) + (kal_uint8)'0');   			
            if(i != 7)
                imei_buf[2*i+1] = (kal_uint8)((imei_BCD_buf[i]>>4 & 0xF) + (kal_uint8)'0');
            else
                imei_buf[2*i+1] = (kal_uint8)'\0';
        }
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }        
    
}
static mmi_java_get_lai_res_struct g_jvm_local_area_information;
/*****************************************************************************
 * FUNCTION
 *  jvm_recv_get_imsi_res
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_recv_get_lai_res(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //kal_int32 len = 0;
    //kal_char* value = NULL;
    mmi_java_get_lai_res_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_java_get_lai_res_struct*) MsgStruct;
    if(msg== NULL)
    {
        return;
    }
    memcpy(&g_jvm_local_area_information,msg,sizeof(mmi_java_get_lai_res_struct));
}

kal_char *jvm_get_nw_ratio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return "GSM";
}


/*****************************************************************************
 * FUNCTION
 *  jvm_get_lai_mnc
 * DESCRIPTION
 *   get the mnc of current mobile network code, not SIM card
 * PARAMETERS
 *  void
 * RETURNS
 *  return NULL if fail
 *  return a uint8 array, caller should release
 *  this array by jvm_free
 *****************************************************************************/
kal_char *jvm_get_lai_cmnc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jvm_local_area_information.error != J2ME_NO_ERROR
        ||strlen(g_jvm_local_area_information.mnc)==0)
    {
        return NULL;
    }

    return g_jvm_local_area_information.mnc;
}
/*****************************************************************************
 * FUNCTION
 *  jvm_get_lai_mnc
 * DESCRIPTION
 *  get mcc of current mobile country code 
 * PARAMETERS
 *  void
 * RETURNS
 *  return NULL if fail
 *  return a uint8, caller should release
 *  this array by jvm_free
 *****************************************************************************/
kal_char *jvm_get_lai_cmcc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jvm_local_area_information.error != J2ME_NO_ERROR
        ||strlen(g_jvm_local_area_information.mcc)==0)
    {
        return NULL;
    }


    return g_jvm_local_area_information.mcc;
}
/*****************************************************************************
 * FUNCTION
 *  jvm_get_lai_cellid
 * DESCRIPTION
 *  get current mobile network cell id code.
 * PARAMETERS
 *  void
 * RETURNS
 *  return NULL if fail
 *  return a uint8, caller should release
 *  this array by jvm_free
 *****************************************************************************/
kal_char *jvm_get_lai_cell_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jvm_local_area_information.error != J2ME_NO_ERROR
        ||strlen(g_jvm_local_area_information.cell_id)==0)
    {
        return NULL;
    }

    return g_jvm_local_area_information.cell_id;
}
/*****************************************************************************
 * FUNCTION
 *  jvm_get_lai_cellid
 * DESCRIPTION
 *  get lac of current local area code
 * PARAMETERS
 *  void
 * RETURNS
 *  return NULL if fail
 *  return a uint8, caller should release
 *  this array by jvm_free
 *****************************************************************************/
kal_char *jvm_get_lai_lac(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jvm_local_area_information.error != J2ME_NO_ERROR
        ||strlen(g_jvm_local_area_information.lac)==0)
    {
        return NULL;
    }

    return g_jvm_local_area_information.lac;
}

/*****************************************************************************
 * FUNCTION
 *  jvm_get_ext_queue_info
 * DESCRIPTION
 *  This routine implements to get external queue's information
 * PARAMETERS
 *  messages        [?]     -  Pointer to number of queue's messages
 * RETURNS
 *  KAL_TRUE if success, else fail
 *****************************************************************************/
kal_bool jvm_get_ext_queue_info(kal_uint32 *messages)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool retval;
    kal_msgq_info msgq_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    retval = kal_get_queue_info(task_info_g[INDX_J2ME].task_ext_qid, &msgq_info);

    if (retval == KAL_TRUE)
    {
        *messages = msgq_info.pending_msgs;
    }

    return retval;
}

volatile int jvm_timer_mutex_cnt = 0;
volatile module_type jvm_timer_mutex_tid = MOD_NIL;


/*****************************************************************************
 * FUNCTION
 *  jvm_timer_mutex_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_timer_mutex_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* GDI_LOCK; */
    if (kal_get_active_module_id() != jvm_timer_mutex_tid)
    {
        kal_take_mutex(g_jam_timer_mutex);
        jvm_timer_mutex_tid = kal_get_active_module_id();
    }
    ++jvm_timer_mutex_cnt;

}


/*****************************************************************************
 * FUNCTION
 *  jvm_timer_mutex_unlock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_timer_mutex_unlock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(jvm_timer_mutex_tid == kal_get_active_module_id());

    --jvm_timer_mutex_cnt;

    if (jvm_timer_mutex_cnt == 0)
    {
        jvm_timer_mutex_tid = MOD_NIL;
        kal_give_mutex(g_jam_timer_mutex);
    }
    /* GDI_UNLOCK; */
}


/*****************************************************************************
 * FUNCTION
 *  jvm_init_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_init_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(jvm_timer_table, 0, sizeof(jvm_timer_table_struct) * MAX_NUM_OF_JVM_TIMER);
}

#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  jvm_timer_expiry_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [?] 
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_timer_expiry_callback(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *timer_id = (kal_uint8*) arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_timer_mutex_lock();
    if ((kal_uint32) timer_id < (kal_uint32) MAX_NUM_OF_JVM_TIMER)
    {
        jvm_timer_table[(kal_uint32) (timer_id)].event_id = NULL;
        (jvm_timer_table[(kal_uint32) (timer_id)].callback_func) (jvm_timer_table[(kal_uint32) (timer_id)].arg);
    }
    jvm_timer_mutex_unlock();
}


/*****************************************************************************
 * FUNCTION
 *  jvm_start_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  period              [IN]        
 *  timer_expiry        [IN]        
 *  arg                 [?] 
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jvm_start_timer(kal_uint32 period, kal_timer_func_ptr timer_expiry, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 temp = (period * 7) >> 5;    /* ~= x 1/4.615 */
    kal_int32 i, timer_id = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_timer_mutex_lock();
    /* Search for free timer */
    for (i = 0; i < MAX_NUM_OF_JVM_TIMER; i++)
    {
        if (jvm_timer_table[i].event_id == NULL)
        {
            timer_id = i;
            break;
        }
    }

    /* No free timer */
    if (timer_id == -1)
    {
        jvm_timer_mutex_unlock();
        return -1;
    }

    if (temp == 0)
    {
        temp = 1;
    }
    jvm_timer_table[timer_id].callback_func = timer_expiry;
    jvm_timer_table[timer_id].arg = arg;
    jvm_timer_table[timer_id].event_id = evshed_set_event(
                                            jvm_event_scheduler_ptr,
                                            (kal_timer_func_ptr) jvm_timer_expiry_callback,
                                            (void*)timer_id,
                                            temp);
    jvm_timer_mutex_unlock();
    return timer_id;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_stop_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timer_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_stop_timer(kal_int32 timer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_timer_mutex_lock();
    
    if (jvm_timer_table[timer_id].event_id != NULL)
    {
        evshed_cancel_event(jvm_event_scheduler_ptr, &(jvm_timer_table[timer_id].event_id));
        jvm_timer_table[timer_id].event_id = NULL;
    }
    jvm_timer_mutex_unlock();
}


/*****************************************************************************
 * FUNCTION
 *  jvm_stop_all_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_stop_all_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 timer_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    jvm_timer_mutex_lock();
    /* Search for free timer */
    for (timer_id = 0; timer_id < MAX_NUM_OF_JVM_TIMER; timer_id++)
    {
        jvm_stop_timer(timer_id);
    }
    jvm_timer_mutex_unlock();
}

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)  
/*****************************************************************************
 * FUNCTION
 *  jvm_l1_cache_invalidate_and_clean_region
 * DESCRIPTION
 *  transfer the buf form cached address to non cached address
 *  if flag on it also do invalidate  and clean and 32 byte alignment
 * PARAMETERS
 *  void        *dst              
 *  kal_uint32  len                 in byte
 *  kal_bool    clean_flag          if true, clean the cached buf
 *  kal_bool    invalidate_flag     if true, invalidate the cached buf
 *  kal_uint8   type_flag           if != 0, do alignment
 *                                        1, mean 4-byte ptr, so buf+=8              
 *                                   others, not define yet
 * RETURNS
 *  void
 *****************************************************************************/
void *jvm_l1_cache_invalidate_and_clean_region(void *dst, kal_uint32 len, kal_bool clean_flag, kal_bool invalidate_flag, kal_uint8 type_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_uint8  remain_bits;		
    kal_uint32 *invalidPtr;
            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/            
    remain_bits =  ((kal_int32) dst & (0x1f));
    invalidPtr = (kal_uint32*) ((kal_int32) dst & (~0x1f));
    //len = ((width * height * 2) >> 5);
    len = (len >>5);
    
    if ((kal_uint32*)dst != invalidPtr)
    {
        if(type_flag == 1)
        {
            invalidPtr+=8;
        }
        else
        {
            len += 2;
        }            
    }
    else
    {
        if(type_flag != 1)
        {
            len++;
        }        
        
    }	 
    if(clean_flag)
    {
        clean_dcache((kal_uint32)invalidPtr, len<<5);    
    }
    if(invalidate_flag)
    {        
        invalidate_dcache((kal_uint32)invalidPtr, len<<5);
    }
    
    dynamic_switch_cacheable_region((void *)&invalidPtr, (len<<5), PAGE_NO_CACHE);       
    invalidPtr = (kal_uint32*)((kal_int32)invalidPtr | remain_bits);  
    
    return invalidPtr;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_l1_cache_invalidate_and_clean_region_by_line
 * DESCRIPTION
 *  transfer the buf form cached address to non cached address
 *  it also do invalidate
 * PARAMETERS
 *  void *dst 
 *  int x_pos 
 *  int y_pos 
 *  int width
 *  int height
 *  int dst_width
 * RETURNS
 *  void
 *****************************************************************************/
void *jvm_l1_cache_invalidate_and_clean_region_by_line(void *dst, kal_uint32 x_pos, kal_uint32 y_pos, kal_uint32 width, kal_uint32 height, kal_uint32 dst_width, kal_uint32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/      
    kal_uint16 *invalidPtr16;
    kal_uint32 *invalidPtr;
    kal_uint32 len;
    //kal_uint32 ii;
    kal_uint32 line_len;
    kal_uint32 end = ((kal_uint32)dst + (kal_uint32)buffer_size);
    //kal_uint32 h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    line_len = ((width ) >> 4);  /*(* 2 / 32)*/
    line_len = line_len << 5;            
    line_len = line_len + 64;         
    invalidPtr16 = dst;
    invalidPtr16 += (kal_uint32)((y_pos) * dst_width + x_pos);
#if ( (LCD_WIDTH != 176) || (LCD_HEIGHT != 220) )
    if(line_len < dst_width)
    {	
        /*
        for(ii = 0; ii < height; ii++)            
        {
            invalidPtr = (kal_uint32*)invalidPtr16;            
            if((kal_int32)invalidPtr % 32)
            {
                invalidPtr = (kal_uint32*)(((kal_int32)invalidPtr >>5)<<5);						        
            } 
            if((kal_uint32)(invalidPtr + (len<<3)) > (kal_uint32)end) 
            {
                break;
            }			                    
            clean_dcache((kal_uint32)invalidPtr, line_len);  
            invalidPtr16 += (dst_width);                
        }    
        */
        invalidPtr = (kal_uint32*)invalidPtr16; 
        
        while(height-- && ((kal_uint32)(invalidPtr + (line_len)) <= (kal_uint32)end))            
        {
            invalidPtr = (kal_uint32*)invalidPtr16;            
            invalidPtr = (kal_uint32*)(((kal_int32)invalidPtr >>5)<<5);
            clean_dcache((kal_uint32)invalidPtr, line_len);  
		    invalidate_dcache((kal_uint32)invalidPtr, line_len);       
            invalidPtr16 += (dst_width);                
        }  

        invalidPtr = (kal_uint32*)(((kal_int32)invalidPtr >>5)<<5);              
        if(height && ((kal_uint32)end > ((kal_uint32)invalidPtr + 32)) )
        {
            clean_dcache((kal_uint32)invalidPtr, (kal_uint32)((((kal_uint32)end -(kal_uint32)invalidPtr)>>5)<<5));      
		    invalidate_dcache((kal_uint32)invalidPtr, (kal_uint32)((((kal_uint32)end -(kal_uint32)invalidPtr)>>5)<<5));    
        }

    }
    else
#endif       
    {
        invalidPtr = (kal_uint32*)invalidPtr16;            
        if((kal_int32)invalidPtr % 32)
        {
            invalidPtr = (kal_uint32*)(((kal_int32)invalidPtr >>5)<<5);
						        
        }  
        len = ((dst_width * height * 2)  >> 5);
    
        if ((kal_uint32*)invalidPtr16 != invalidPtr)
        {
            len += 2;
        }
        else
        {
            len++;
        }	        
        if((kal_uint32)invalidPtr < (kal_uint32)end)   
        {
            if((kal_uint32)(invalidPtr + (len<<3)) > (kal_uint32)end) 
            {
                len = (kal_uint32)(((kal_uint32)(end) - (kal_uint32)(invalidPtr)) >> 5);
                clean_dcache((kal_uint32)invalidPtr, len<<5);            
                invalidate_dcache((kal_uint32)invalidPtr, len<<5);               
            }	
            else        	        
            {
                clean_dcache((kal_uint32)invalidPtr, len<<5);            
                invalidate_dcache((kal_uint32)invalidPtr, len<<5);            	
            }
        }
    }    

	 invalidPtr = (kal_uint32 *)virt_to_phys(dst);
    
    return invalidPtr;
}
#endif  
