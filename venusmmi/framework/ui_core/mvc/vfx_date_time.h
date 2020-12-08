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
 *  vfx_date_time.h
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
#ifndef __VFX_DATE_TIME_H__
#define __VFX_DATE_TIME_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vfx_string.h"

#ifdef __cplusplus
extern "C"
{
#include "app_datetime.h"
}
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_DATE_TIME_DATE_MASK              0x000000FF
#define VFX_DATE_TIME_DATE_YEAR              0x00000001
#define VFX_DATE_TIME_DATE_MONTH             0x00000002
#define VFX_DATE_TIME_DATE_DAY               0x00000004


#define VFX_DATE_TIME_TIME_MASK              0x0000FF00
#define VFX_DATE_TIME_TIME_HOUR              0x00000100
#define VFX_DATE_TIME_TIME_MINUTE            0x00000200
#define VFX_DATE_TIME_TIME_SECOND            0x00000400


#define VFX_DATE_TIME_DAY_MASK               0x000F0000
#define VFX_DATE_TIME_DAY_SHORT_NAME         0x00010000
#define VFX_DATE_TIME_DAY_NORMAL_NAME        0x00020000

#define VFX_DATE_TIME_DURATION_MASK                 0x00F00000
#define VFX_DATE_TIME_DURATION_FULL_FORMAT          0x00100000
#define VFX_DATE_TIME_DURATION_NO_HOUR              0x00200000

#define VFX_DATE_TIME_FORMAT_MASK                       0xFF000000
#define VFX_DATE_TIME_FORMAT_MONTH_ENGLISH_ABBR         0x01000000
#define VFX_DATE_TIME_FORMAT_NO_DATE_SEPARATOR          0x02000000
#define VFX_DATE_TIME_FORMAT_AMPM_LOWER_CASE            0x04000000
#define VFX_DATE_TIME_FORMAT_AUTO_DETECT_DATE_DISPLAY   0x08000000

#define VFX_DATE_MIN_YEAR               1900
#define VFX_DATE_MAX_YEAR               2099
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/*****************************************************************************
 * DESCRIPTION
 *  The class provides the basic operate of date-time.
 * NOTE
 *  
 * EXAMPLE
 *  
 *****************************************************************************/
class VfxDateTime: public VfxBase
{
public:
    // Enum values which are used to describe the compare result of two date-time objects.
    typedef enum
    {
        // Is an enum value which represents the source date-time object is less than target.
        LESS = 0,
        // Is an enum value which represents the source date-time object equals target.
        EQUAL,
        // Is an enum value which represents the source date-time object is greater than target.
        GREATER
    } CompareEnum;

    typedef enum
    {
        // Is an enum value which represents the day is Sunday.
        SUN = 0,
        // Is an enum value which represents the day is Monday.
        MON,
        // Is an enum value which represents the day is Tuesday.
        TUE,
        // Is an enum value which represents the day is Wednesday.
        WED,
        // Is an enum value which represents the day is Thursday.
        THU,
        // Is an enum value which represents the day is Friday.
        FRI,
        // Is an enum value which represents the day is Saturday.
        SAT
    } DayOfWeekEnum;

private:
    typedef enum
    {
        // Is an enum value which represents the max length of day string.
        DAY_NORMAL_MAX_LENGTH = 9,
        // Is an enum value which represents the max length of day abbreviate string.
        DAY_SHORT_MAX_LENGTH = 3
    } DayMaxLengthEnum;

    typedef enum
    {
        // Is an enum value which represents the number of day.
        DAY_TOTAL_NUM = 7,
        // Is an enum value which represents the number of month.
        MONTH_TOTAL_NUMBER = 12
    } TotalNumberEnum;

    typedef enum
    {
        STRING_LENGTH_MAX = 34
    } StringLengthEnum;

private:
    // Is the time that be record in date-time object.
    applib_time_struct m_time;
    VfxFloat m_timeZone;
    VfxWString m_dateTimeStr;

public:
    /*
     * Constructor / Destructor
     */
    VfxDateTime();
    VfxDateTime(const VfxDateTime &other);
    VfxDateTime &operator = (const VfxDateTime &other);

public:
    void setCurrentTime(); /* set the system time to date-time object */
    VfxBool setDate(VfxU32 year, VfxU32 month, VfxU32 day);
    VfxBool setTime(VfxU32 hour, VfxU32 minute, VfxU32 second);
    VfxBool setTimeZone(VfxFloat timeZone);
    VfxBool setDateTime(applib_time_struct *dateTime);

    applib_time_struct getDateTime() const;
    void getDate(VfxU32 *year, VfxU32 *month, VfxU32 *day) const;
    VfxU32 getYear() const;
    VfxU32 getMonth() const;
    VfxU32 getDay() const;
    void getTime(VfxU32 *hour, VfxU32 *minute, VfxU32 *second) const;
    VfxU32 getHour() const;
    VfxU32 getMinute() const;
    VfxU32 getSecond() const;
    void getDayOfWeek(DayOfWeekEnum *dayOfWeek) const;

    void getDateTimeString(
          VfxU32 flags,
          VfxWChar *dateTimeString,
          VfxU32 maxLength) const;

    VfxWString& getDateTimeString(VfxU32 flags);

    /* Is a vaild date-time or not */
    VfxBool isValidTime() const;
    VfxBool isValidDate() const;

    CompareEnum compareWith(const VfxDateTime &reference) const;
    CompareEnum getDiff(
                  const VfxDateTime &reference, 
                  VfxDateTime &result) const;
    VfxBool increase(const VfxDateTime &increment);
    VfxBool decrease(const VfxDateTime &increment);
};


#endif /* __VFX_DATE_TIME_H__ */

