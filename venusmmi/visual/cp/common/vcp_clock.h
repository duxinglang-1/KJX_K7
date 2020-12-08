/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *  vcp_clock.h
 *
 * Project:
 * --------
 *  Venus UI Component
 *
 * Description:
 * ------------
 *  UI component used to display clock
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_CLOCK_H__
#define __VCP_CLOCK_H__

#ifndef __cplusplus
#error "This header file can be used in C++ only."
#endif

#include "vfx_control.h"
#include "vfx_date_time.h"
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vfx_timer.h"
#include "vfx_basic_type.h"
#include "vfx_draw_context.h"
#include "vrt_datatype.h"
#include "vfx_primitive_frame.h"

/***************************************************************************** 
 * Include
 *****************************************************************************/


/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/*****************************************************************************
 * Class VcpClock
 *****************************************************************************/

/*
 * VcpClock is a base class to implement the basic time keep function, which
 * will not do any display action.
 * The display of clock should be implemented in different inherited class of 
 * VcpClock.
 */
class VcpClock : public VfxControl
{
// Constructor / Destructor
public:
    // <group DOM_Clock_VcpClock_Constructor/Destructor>
    // Default constructor.
    VcpClock();


// Method
public:    
    // <group DOM_Clock_VcpClock_Method>
    // Start the update of clock.
    void startClock();

    // <group DOM_Clock_VcpClock_Method>
    // Suspend update of clock.
    void suspendClock();

    // <group DOM_Clock_VcpClock_Method>
    // Resume update of clock after suspended.
    void resumeClock();

    // <group DOM_Clock_VcpClock_Method>
    // Set current system time as clock object's start relative time.
    void setTime();

    // <group DOM_Clock_VcpClock_Method>
    // Set given time as clock object's start relative time.
    void setTime(
        const VfxDateTime &startTime // [IN] Is the start relative time
    );

    // <group DOM_Clock_VcpClock_Method>
    // Set update interval to clock object.
    void setUpdateInterval(
        const VfxDateTime &updateInterval // [IN] Is the update interval
    );


// Override
protected:
    // <group DOM_Clock_VcpClock_Override>
    virtual void onInit();
    // <group DOM_Clock_VcpClock_Override>
    virtual void onDeinit();


// Variable
protected:
    // <group DOM_Clock_VcpClock_Variable>
    // Is the current relative time to be displayed when clock update.
    VfxDateTime m_currentRelTime;
    // <group DOM_Clock_VcpClock_Variable>
    // Is the update interval of clock, use second as its unit.
    VfxDateTime m_updateInterval;


// Implementation
private:
    // <group DOM_Clock_VcpClock_Implementation>
    typedef enum
    {
        // Is the default start delay of clock.
        START_DELAY = 500,
        // Is the default update interval of clock.
        UPDATE_INTERVAL = 500
    } TimerDefaultSettingEnum;

    // <group DOM_Clock_VcpClock_Implementation>
    // Is the start relative time which is set in setTime().
    VfxDateTime m_startRelTime;
    // <group DOM_Clock_VcpClock_Implementation>
    // Is the exact system time when clock start.
    VfxDateTime m_startSysTime;
    // <group DOM_Clock_VcpClock_Implementation>
    // Is a flag to mark the clock whether to update or not
    VfxBool m_autoUpdate;

    // <group DOM_Clock_VcpClock_Implementation>
    // Is the head pointer of clock linked list.
    static VcpClock *s_headClock;
    // <group DOM_Clock_VcpClock_Implementation>
    // Is the pointer point to next clock.
    VcpClock *m_nextClock;

private:
    // <group DOM_Clock_VcpClock_Implementation>
    // Handle the time out event.
    void timeOut();

    // <group DOM_Clock_VcpClock_Implementation>
    // Convert the update interval to millisecond.
    static VfxS32 convertUpdateInterval(
        // [IN] Is the update interval to be converted
        const VfxDateTime &updateInterval
    );
 
    // <group DOM_Clock_VcpClock_Implementation>
    // Judge the clock need to update the time or not.
    VfxBool needUpdate(
        VfxDateTime &currentRelTime // [IN] Is the current relative time
    );


// Signal
private:
    /* Is the timer of clock. */
    // <group DOM_Clock_VcpClock_Signal>
    static VfxTimer *s_timer;


// Event
protected:
    // <group DOM_Clock_VcpClock_Event>
    // Handle the timer tick event.
    void onTimerTick(
        VfxTimer *source // [IN] Is the timer object
    );

private:
    // <group DOM_Clock_VcpClock_Event>
    // Handle the time change event of PLUTO system time.
    void onSystemTimeChanged(
        VfxU32 flag // [IN] Is the flag to notify the type of time change
    );
};


/*****************************************************************************
 * Class VcpDurationClock
 *****************************************************************************/
#ifdef __MMI_VUI_COSMOS_CP_SLIM__
/*
 * VcpDurationClock is a class which is used to display duration in the screen.
 *
 * EXAMPLE
 * <code>
 *  VcpDurationClock *clock = new VcpDurationClock();
 *  clock->setTime();
 *  clock->startClock();
 * </code>
 */
class VcpDurationClock : public VcpClock
{
// Constructor / Destructor
public:
    // <group DOM_Clock_VcpDurationClock_Constructor/Destructor>
    // Default constructor.
    VcpDurationClock();

// Property
public:
    // <group DOM_Clock_VcpDurationClock_Property>
    // Is the text color of duration string.
    virtual const VfxColor &getTextColor() const;
    // <group DOM_Clock_VcpDurationClock_Property>
    // Is the text border color of duration string.
    virtual const VfxColor &getTextBorderColor() const;

    // <group DOM_Clock_VcpDurationClock_Property>
    virtual void setTextColor(const VfxColor &value);
    // <group DOM_Clock_VcpDurationClock_Property>
    virtual void setTextBorderColor(const VfxColor &value);

// Override
protected:
    // <group DOM_Clock_VcpDurationClock_Override>
    virtual void onInit();
    // <group DOM_Clock_VcpDurationClock_Override>
    virtual void onDeinit();
    // <group DOM_Clock_VcpDurationClock_Override>
    virtual void onDraw(VfxDrawContext &dc);

// Overridable
protected:
    // <group DOM_Clock_VcpDurationClock_Overridable>
    /* 
     * Get the min display size of duration clock.
     * RETURNS: The size of this duration clock.
     */
    virtual VfxSize onMeasureMinSize();

// Implementation
private:
    // <group DOM_Clock_VcpDurationClock_Implementation>
    typedef enum
    {
        // Is an enum value which represents the max string length of duration.
        STRING_LENGTH_MAX = 10
    } StringLengthEnum;

    // <group DOM_Clock_VcpDurationClock_Implementation>
    // Font for text.
    VfxFontDesc m_font;
    // <group DOM_Clock_VcpDurationClock_Implementation>
    VfxColor m_textColor;
    // <group DOM_Clock_VcpDurationClock_Implementation>
    VfxColor m_textBorderColor;

// Method
public:
    // <group DOM_Clock_VcpDurationClock_Method>
    // Set the font of digital text clock.
    void setFont(
        const VfxFontDesc &font         // [IN] The font to set
    );
};
#endif /* __MMI_VUI_COSMOS_CP_SLIM__ */

/*****************************************************************************
 * Class VcpDigitalTextClock
 *****************************************************************************/

/*
 * VcpDigitalTextClock is a class which is used to display a digital clock
 * in the screen. It can display date, time and weekday in one string.
 * This clock will use text to show number and separator.
 *
 * EXAMPLE
 * <code>
 *  VcpDigitalTextClock *clock = new VcpDigitalTextClock();
 *  clock->setTime();
 *  clock->setFormatFlags(
 *      VFX_DATE_TIME_DATE_YEAR |
 *      VFX_DATE_TIME_DATE_MONTH |
 *      VFX_DATE_TIME_DATE_DAY |
 *      VFX_DATE_TIME_DAY_SHORT_NAME);
 *  clock->startClock();
 * </code>
 */
class VcpDigitalTextClock : public VcpClock
{
// Enum
public:
    // <group DOM_Clock_VcpDigitalTextClock_Enum>
    // Align mode of the digital text clock
    enum VcpDigitalTextAlignModeEnum
    {
        ALIGN_MODE_LEFT = 0,
        ALIGN_MODE_RIGHT,
        ALIGN_MODE_CENTER
    };

// Constructor / Destructor
public:
    // <group DOM_Clock_VcpDigitalTextClock_Constructor/Destructor>
    // Default constructor.
    VcpDigitalTextClock();

// Property
public:
    // <group DOM_Clock_VcpDigitalTextClock_Property>
    // Is the text color of digital text clock's date&time string.
    virtual const VfxColor &getTextColor() const;
    // <group DOM_Clock_VcpDigitalTextClock_Property>
    // Is the text border color of digital text clock's date&time string.
    virtual const VfxColor &getTextBorderColor() const;

    // <group DOM_Clock_VcpDigitalTextClock_Property>
    virtual void setTextColor(const VfxColor &value);
    // <group DOM_Clock_VcpDigitalTextClock_Property>
    virtual void setTextBorderColor(const VfxColor &value);

// Method
public:
    // <group DOM_Clock_VcpDigitalTextClock_Method>
    // Set the date&time format flags to clock object.
    void setFormatFlags(
        VfxU32 formatFlags // [IN] Is the flags of date&time format
    );

    // <group DOM_Clock_VcpDigitalTextClock_Method>
    // Set the date&time bounds auto minsize.
    void setBoundsAutoMinmize(VfxBool value);

// Variable
private:
    // <group DOM_Clock_VcpDigitalTextClock_Variable>
    /*
     * Is a flags to give the date&time format of digital text clock's string.
     * It is a combination of date&time format macro in vfx_date_time.h.
     */
    VfxU32 m_formatFlags;
    // <group DOM_Clock_VcpDigitalTextClock_Variable>
    // Font for text.
    VfxFontDesc m_font;
    // <group DOM_Clock_VcpDigitalTextClock_Variable>
    // Align mode
    VcpDigitalTextAlignModeEnum m_alignMode;

    // <group DOM_Clock_VcpDigitalTextClock_Variable>
    // Auto minmize the bounds to min-size.
    VfxBool m_isBoundsAutoMinmize;

// Implementation
private:
    // <group DOM_Clock_VcpDigitalTextClock_Implementation>
    typedef enum
    {
        /*
         * Is an enum value which represents the max string length
         * of digital text clock's date&time string.
         */
        STRING_LENGTH_MAX = 34
    } StringLengthEnum;

    // <group DOM_Clock_VcpDigitalTextClock_Implementation>
    VfxColor m_textColor;
    // <group DOM_Clock_VcpDigitalTextClock_Implementation>
    VfxColor m_textBorderColor;

// Method
public:
    // <group DOM_Clock_VcpDigitalTextClock_Method>
    // Set the font of digital text clock.
    void setFont(
        const VfxFontDesc &fontDesc // [IN] The font to set
    );

    // <group DOM_Clock_VcpDigitalTextClock_Method>
    // Set align mode of digital text clock.
    void setAlignMode(
        const VcpDigitalTextAlignModeEnum &alignMode  // [IN] The align mode to set
    );

// Override
protected:
    // <group DOM_Clock_VcpDigitalTextClock_Override>
    virtual void onInit();
    // <group DOM_Clock_VcpDigitalTextClock_Override>
    virtual void onDeinit();
    // <group DOM_Clock_VcpDigitalTextClock_Override>
    virtual void onDraw(VfxDrawContext &dc);


// Overridable
protected:
    // <group DOM_Clock_VcpDigitalTextClock_Overridable>
    /* 
     * Get the min display size of digital text clock.
     * RETURNS: The size of this digital text clock.
     */
    virtual VfxSize onMeasureMinSize();
};


/*****************************************************************************
 * Class VcpAnalogClock
 *****************************************************************************/

/*
 * VcpAnalogClock is a class which is used to display an analog clock
 * in the screen. 
 *
 * EXAMPLE
 * <code>
 *  VcpAnalogClock *clock = new VcpAnalogClock();
 *  clock->setTime();
 *  clock->startClock();
 * </code>
 */
class VcpAnalogClock : public VcpClock
{
// Constructor / Destructor
public:
    // <group DOM_Clock_VcpAnalogClock_Constructor/Destructor>
    // Default constructor.
    VcpAnalogClock();

// Property
public:
    // <group DOM_Clock_VcpAnalogClock_Property>
    // Is the hour hand's color of analog clock.
    virtual const VfxColor &getHourHandColor() const;
    // <group DOM_Clock_VcpAnalogClock_Property>
    // Is the minute hand's color of analog clock.
    virtual const VfxColor &getMinuteHandColor() const;
    // <group DOM_Clock_VcpAnalogClock_Property>
    // Is the second hand's color of analog clock.
    virtual const VfxColor &getSecondHandColor() const;

    // <group DOM_Clock_VcpAnalogClock_Property>
    /* 
     * Is the hour hand's length which from the begin of
     * hour hand to clock center.
     */
    virtual VfxS32 getHourHandRadius() const;
    /* 
     * Is the minute hand's length which from the begin of
     * minute hand to clock center.
     */
    // <group DOM_Clock_VcpAnalogClock_Property>
    virtual VfxS32 getMinuteHandRadius() const;
    // <group DOM_Clock_VcpAnalogClock_Property>
    /* 
     * Is the second hand's length which from the begin of
     * second hand to clock center.
     */
    virtual VfxS32 getSecondHandRadius() const;

    // <group DOM_Clock_VcpAnalogClock_Property>
    /* 
     * Is the hour hand's length which from the end of
     * hour hand to clock center.
     */
    virtual VfxS32 getHourHandRadiusOffset() const;

    // <group DOM_Clock_VcpAnalogClock_Property>
    /* 
     * Is the minute hand's length which from the end of
     * minute hand to clock center.
     */
    virtual VfxS32 getMinuteHandRadiusOffset() const;

    // <group DOM_Clock_VcpAnalogClock_Property>
    /* 
     * Is the second hand's length which from the end of
     * second hand to clock center.
     */
    virtual VfxS32 getSecondHandRadiusOffset() const;

    // <group DOM_Clock_VcpAnalogClock_Property>
    // Is the center point's position of analog clock.
    virtual const VfxPoint &getCenter() const;


    // <group DOM_Clock_VcpAnalogClock_Property>
    virtual void setHourHandColor(const VfxColor &value);
    // <group DOM_Clock_VcpAnalogClock_Property>
    virtual void setMinuteHandColor(const VfxColor &value);
    // <group DOM_Clock_VcpAnalogClock_Property>
    virtual void setSecondHandColor(const VfxColor &value);

    // <group DOM_Clock_VcpAnalogClock_Property>
    virtual void setHourHandRadius(VfxS32 value);
    // <group DOM_Clock_VcpAnalogClock_Property>
    virtual void setMinuteHandRadius(VfxS32 value);
    // <group DOM_Clock_VcpAnalogClock_Property>
    virtual void setSecondHandRadius(VfxS32 value);

    // <group DOM_Clock_VcpAnalogClock_Property>
    virtual void setHourHandRadiusOffset(VfxS32 value);
    // <group DOM_Clock_VcpAnalogClock_Property>
    virtual void setMinuteHandRadiusOffset(VfxS32 value);
    // <group DOM_Clock_VcpAnalogClock_Property>
    virtual void setSecondHandRadiusOffset(VfxS32 value);

    // <group DOM_Clock_VcpAnalogClock_Property>
    virtual void setCenter(const VfxPoint &value);

// Method
public:
    // <group DOM_Clock_VcpAnalogClock_Method>
    // Set the background image of analog clock.
    void setClockBackground(
        VfxU8 *background // [IN] Is the background image
    );

    // <group DOM_Clock_VcpAnalogClock_Method>
    // Set the background image of analog clock.
	void setClockBackgroundImage(
		VfxS32 background // [IN] Is the background image
	);

    // <group DOM_Clock_VcpAnalogClock_Method>
    // Set the cover image of analog clock.
    void setClockCover(
        VfxS32 cover // [IN] Is the cover image
    );

    // <group DOM_Clock_VcpAnalogClock_Method>
    // Set the hour hand image of analog clock.
    void setClockHourHand(
        VfxS32 hourHand // [IN] Is the hour hand image
    );

    // <group DOM_Clock_VcpAnalogClock_Method>
    // Set the minute hand image of analog clock.
    void setClockMinuteHand(
        VfxS32 minuteHand // [IN] Is the minute hand image
    );

    // <group DOM_Clock_VcpAnalogClock_Method>
    // Set the second hand image of analog clock.
    void setClockSecondHand(
        VfxS32 secondHand // [IN] Is the clock hand image
    );

    // <group DOM_Clock_VcpAnalogClock_Method>
    // Set the hour hand end image of analog clock.
    void setClockHourHandEnd(
        VfxS32 hourHandEnd // [IN] Is the hour hand image
    );

    // <group DOM_Clock_VcpAnalogClock_Method>
    // Set the minute hand end image of analog clock.
    void setClockMinuteHandEnd(
        VfxS32 minuteHandEnd // [IN] Is the minute hand image
    );

    // <group DOM_Clock_VcpAnalogClock_Method>
    // Set the second hand end image of analog clock.
    void setClockSecondHandEnd(
        VfxS32 secondHandEnd // [IN] Is the clock hand image
    );

    // <group DOM_Clock_VcpAnalogClock_Method>
    // Set the axis image of analog clock.
    void setClockAxis(
        VfxS32 axis // [IN] Is the clock axis image
    );

    // <group DOM_Clock_VcpAnalogClock_Method>
    // Set custom frame of clock.
    void setFrameCustom(
        VfxFrame *f // [IN] Is the custom frame
    );

    // <group DOM_Clock_VcpAnalogClock_Method>
    // Get custom frame of clock.
    // RETURNS: Frame pointer of clock's custom frame.
    VfxFrame * getFrameCustom();
    
    // <group DOM_Clock_VcpAnalogClock_Method>
    // Get hour hand image frame of clock.
    // RETURNS: Frame pointer of clock's hour hand frame.
    VfxImageFrame * getHourHandImageFrame();
    
    // <group DOM_Clock_VcpAnalogClock_Method>
    // Get minute hand image frame of clock.
    // RETURNS: Frame pointer of clock's minute hand frame.
    VfxImageFrame * getMinuteHandImageFrame();
    
    // <group DOM_Clock_VcpAnalogClock_Method>
    // Get second hand image frame of clock.
    // RETURNS: Frame pointer of clock's second hand frame.
    VfxImageFrame * getSecondHandImageFrame();
    
// Override
protected:
    // <group DOM_Clock_VcpAnalogClock_Override>
    virtual void onInit();
    // <group DOM_Clock_VcpAnalogClock_Override>
    virtual void onDeinit();
    // <group DOM_Clock_VcpAnalogClock_Override>
    virtual void onDraw(VfxDrawContext &dc);

// Overridable
protected:
    // <group DOM_Clock_VcpAnalogClock_Overridable>
    /* 
     * Get the min display size of analog clock.
     * RETURNS: The size of this analog clock.
     */
    virtual VfxSize onMeasureMinSize();


// Implementation
private:
    // <group DOM_Clock_VcpAnalogClock_Implementation>
    VfxColor m_hourHandColor;
    // <group DOM_Clock_VcpAnalogClock_Implementation>
    VfxColor m_minuteHandColor;
    // <group DOM_Clock_VcpAnalogClock_Implementation>
    VfxColor m_secondHandColor;

    // <group DOM_Clock_VcpAnalogClock_Implementation>
    VfxS32 m_hourHandRadius;
    // <group DOM_Clock_VcpAnalogClock_Implementation>
    VfxS32 m_minuteHandRadius;
    // <group DOM_Clock_VcpAnalogClock_Implementation>
    VfxS32 m_secondHandRadius;

    // <group DOM_Clock_VcpAnalogClock_Implementation>
    VfxS32 m_hourHandRadiusOffset;
    // <group DOM_Clock_VcpAnalogClock_Implementation>
    VfxS32 m_minuteHandRadiusOffset;
    // <group DOM_Clock_VcpAnalogClock_Implementation>
    VfxS32 m_secondHandRadiusOffset;

    // <group DOM_Clock_VcpAnalogClock_Implementation>
    VfxPoint m_center;

    // <group DOM_Clock_VcpAnalogClock_Implementation>
    // Is the background image of analog clock.
    VfxU8 *m_clockBackground;

    // <group DOM_Clock_VcpAnalogClock_Implementation>
    // Is the background image of analog clock.
    VfxImageFrame *m_clockBackgroundImage;

    // <group DOM_Clock_VcpAnalogClock_Implementation>
    // Is the frame used for user to draw its own content.
    VfxFrame    *m_frameCustom;
    // <group DOM_Clock_VcpAnalogClock_Implementation>
    // Is the hour hand image frame
    VfxImageFrame *m_hourHandImage;
    // <group DOM_Clock_VcpAnalogClock_Implementation>
    // Is the minute hand image frame
    VfxImageFrame *m_minuteHandImage;
    // <group DOM_Clock_VcpAnalogClock_Implementation>
    // Is the second hand image frame
    VfxImageFrame *m_secondHandImage;
    // <group DOM_Clock_VcpAnalogClock_Implementation>
    // Is the hour hand end image frame
    VfxImageFrame *m_hourHandEndImage;
    // <group DOM_Clock_VcpAnalogClock_Implementation>
    // Is the minute hand end image frame
    VfxImageFrame *m_minuteHandEndImage;
    // <group DOM_Clock_VcpAnalogClock_Implementation>
    // Is the second hand end image frame
    VfxImageFrame *m_secondHandEndImage;
    // <group DOM_Clock_VcpAnalogClock_Implementation>
    // Is the axis image frame
    VfxImageFrame *m_axisImage;
    // <group DOM_Clock_VcpAnalogClock_Implementation>
    // Is the cover image of analog clock.
    VfxImageFrame *m_clockCover;
};


/*****************************************************************************
 * Class VcpDigitalImageClock
 *****************************************************************************/

/*
 * VcpDigitalImageClock is a class which is used to display an digital time 
 * clock in the screen.
 * This clock will use image to show number and separator.
 *
 * EXAMPLE
 * <code>
 *  VcpDigitalImageClock *clock = new VcpDigitalImageClock();
 *  clock->setTime();
 *  clock->startClock();
 * </code>
 */
class VcpDigitalImageClock : public VcpClock
{
// Enum
public:
    // <group DOM_Clock_VcpDigitalImageClock_Enum>
    /*
     * Is Enum value which are used to inform the horizontal
     * display type of AM and PM.
     */
    typedef enum
    {
        /* 
         * Is an enum value which represents that AM and PM not
         * display in the same line.
         */
        AMPM_NO_H_DISPLAY = 0,
        /* 
         * Is an enum value which represents that AM and PM will
         * display in the same line of clock's left-top corner.
         */
        AMPM_H_DISPLAY_LEFT_TOP,
        /* 
         * Is an enum value which represents that AM and PM will
         * display in the same line of clock's left-bottom corner.
         */
        AMPM_H_DISPLAY_LEFT_BOTTOM,
        /* 
         * Is an enum value which represents that AM and PM will
         * display in the same line of clock's right-top corner.
         */
        AMPM_H_DISPLAY_RIGHT_TOP,
        /* 
         * Is an enum value which represents that AM and PM will
         * display in the same line of clock's right-bottom corner.
         */
        AMPM_H_DISPLAY_RIGHT_BOTTOM
    } AmPmHDisplayEnum;

    // <group DOM_Clock_VcpDigitalImageClock_Enum>
    /*
     * Is Enum value which are used to inform the vertical
     * display type of AM and PM.
     */
    typedef enum
    {
        /* 
         * Is an enum value which represents that AM and PM not
         * display in the same column.
         */
        AMPM_NO_V_DISPLAY = 0,
        /* 
         * Is an enum value which represents that AM and PM will
         * display in the same column of clock's right-top corner.
         */
        AMPM_V_DISPLAY_RIGHT_TOP,
        /* 
         * Is an enum value which represents that AM and PM will
         * display in the same column of clock's right-bottom corner.
         */
        AMPM_V_DISPLAY_RIGHT_BOTTOM,
        /* 
         * Is an enum value which represents that AM and PM will display
         * in the same column of clock's right part in equal distance.
         */
        AMPM_V_DISPLAY_RIGHT_EQUIDISTANCE
    } AmPmVDisplayEnum;

// Constructor / Destructor
public:
    // <group DOM_Clock_VcpDigitalImageClock_Constructor/Destructor>
    // Default constructor.
    VcpDigitalImageClock();

// Method
public:
    // <group DOM_Clock_VcpDigitalImageClock_Method>
    /*
     * Is the horizontal display property of Am and Pm,
     * which use AmPmHDisplayEnum as its value. Its default value is
     * AMPM_H_DISPLAY_LEFT_TOP.
     * This property and m_propertyAmPmVDisplay are mutually-exclusive.
     */
    virtual AmPmHDisplayEnum getAmPmHDisplay() const;

    // <group DOM_Clock_VcpDigitalImageClock_Method>
    /*
     * Is the vertical display property of Am and Pm,
     * which use AmPmVDisplayEnum as its value. Its default value is
     * AMPM_NO_V_DISPLAY.
     * This property and m_propertyAmPmHDisplay are mutually-exclusive.
     */
    virtual AmPmVDisplayEnum getAmPmVDisplay() const;

    // <group DOM_Clock_VcpDigitalImageClock_Method>
    virtual void setAmPmHDisplay(AmPmHDisplayEnum value);
    // <group DOM_Clock_VcpDigitalImageClock_Method>
    virtual void setAmPmVDisplay(AmPmVDisplayEnum value);

// Method
public:

    // <group DOM_Clock_VcpDigitalImageClock_Method>
    // Set the gap to digital image clock.
    void setGap(
        VfxU8 normal_gap, 
        VfxU8 separator_gap, 
        VfxU8 ampm_gap
    );

    // <group DOM_Clock_VcpDigitalImageClock_Method>
    // Set the background image to digital image clock.
    void setBackground(
        VfxU8 *background // [IN] Is the background image
    );

    // <group DOM_Clock_VcpDigitalImageClock_Method>
    // Set the number image to digital image clock.
    void setNumber(
        VfxChar number,   // [IN] Is the ASCII code of number
        VfxU8 *numberSrc  // [IN] Is the corresponding number image
    );

    // <group DOM_Clock_VcpDigitalImageClock_Method>
    // Set all the number images to digital image clock.
    void setNumber(
        VfxS32 numberBeginId, // [IN] Is the number begin image ID
        VfxS32 numberEndId    // [IN] Is the number end image ID
    );

    // <group DOM_Clock_VcpDigitalImageClock_Method>
    // Set the number background image to digital image clock.
    void setNumberBackground(
        VfxU8 *numberBackground // [IN] Is the number background image
    );

    // <group DOM_Clock_VcpDigitalImageClock_Method>
    /*
     * Set the time separator's foreground and background image
     * to digital image clock.
     */
    void setTimeSeparator(
        VfxS32 separatorForeground, // [IN] Is separator's foreground image
        VfxS32 separatorBackground  // [IN] Is separator's background image
    );

    // <group DOM_Clock_VcpDigitalImageClock_Method>
    // Set am and pm foreground and background image to digital image clock.
    void setAmAndPm(
        VfxU8 *amForeground, // [IN] Is am's foreground image
        VfxU8 *amBackground, // [IN] Is am's background image
        VfxU8 *pmForeground, // [IN] Is pm's foreground image
        VfxU8 *pmBackground  // [IN] Is pm's background image
    );

// Signal
private:
    // <group DOM_Clock_VcpDigitalImageClock_Signal>
    // Is the timer to update separator.
    static VfxTimer *s_separatorTimer;

// Implementation
private:
    // <group DOM_Clock_VcpDigitalImageClock_Implementation>
    typedef enum
    {
        // Is an enum value which represents the gap between every number.
        IMAGE_NORMAL_GAP = 5,
        // Is an enum value which represents the gap between number and separator.
        IMAGE_SEPARATOR_GAP = 3,
        // Is an enum value which represents the gap between number and AM/PM.
        IMAGE_AMPM_GAP = 4
    } ImageGapEnum;

// Implementation
private:
    // <group DOM_Clock_VcpDigitalImageClock_Implementation>
    AmPmHDisplayEnum m_amPmHDisplay;
    // <group DOM_Clock_VcpDigitalImageClock_Implementation>
    AmPmVDisplayEnum m_amPmVDisplay;
    
    // <group DOM_Clock_VcpDigitalImageClock_Implementation>
    // the gap between every number.
    VfxU8 m_normal_gap;
    // <group DOM_Clock_VcpDigitalImageClock_Implementation>
    // the gap between number and separator.
    VfxU8 m_separator_gap;
    // <group DOM_Clock_VcpDigitalImageClock_Implementation>
    // the gap between number and AM/PM.
    VfxU8 m_ampm_gap;
        
    // <group DOM_Clock_VcpDigitalImageClock_Implementation>
     // Is the background image of digital image clock.
    VfxU8 *m_background;
    // <group DOM_Clock_VcpDigitalImageClock_Implementation>
    // Is the number images of 0 ~ 9.
    VfxU8 *m_number[10];
    // <group DOM_Clock_VcpDigitalImageClock_Implementation>
    // Is the background image of number.
    VfxU8 *m_numberBackground;

    // <group DOM_Clock_VcpDigitalImageClock_Implementation>
    // Is the foreground image of time separator.
    VfxS32 m_timeSeparatorForeground;
    // <group DOM_Clock_VcpDigitalImageClock_Implementation>
    // Is the background image of time separator.
    VfxS32 m_timeSeparatorBackground;

    // <group DOM_Clock_VcpDigitalImageClock_Implementation>
    // Is the foreground image of am.
    VfxU8 *m_timeAmForeground;
    // <group DOM_Clock_VcpDigitalImageClock_Implementation>
    // Is the background image of am.
    VfxU8 *m_timeAmBackground;
    // <group DOM_Clock_VcpDigitalImageClock_Implementation>
    // Is the foreground image of pm.
    VfxU8 *m_timePmForeground;
    // <group DOM_Clock_VcpDigitalImageClock_Implementation>
    // Is the background image of pm.
    VfxU8 *m_timePmBackground;

private:
    // <group DOM_Clock_VcpDigitalImageClock_Implementation>
    VfxImageFrame *m_separator; // Is the separator image frame
    // <group DOM_Clock_VcpDigitalImageClock_Implementation>
    // Is a flag to record whether to display separator.
    static VfxBool s_displaySeparator;
    // <group DOM_Clock_VcpDigitalImageClock_Implementation>
    // Is a flag to record whether separator timer start or not.
    static VfxBool s_setStartDelay;
    // <group DOM_Clock_VcpDigitalImageClock_Implementation>
    // Is the head pointer of digital image clock linked list.
    static VcpDigitalImageClock *s_headClock;
    // <group DOM_Clock_VcpDigitalImageClock_Implementation>
    // Is the pointer point to next digital image clock.
    VcpDigitalImageClock *m_nextClock;

// Override
protected:
    // <group DOM_Clock_VcpDigitalImageClock_Override>
    virtual void onInit();
    // <group DOM_Clock_VcpDigitalImageClock_Override>
    virtual void onDeinit();
    // <group DOM_Clock_VcpDigitalImageClock_Override>
    virtual void onDraw(VfxDrawContext &dc);


// Overridable
protected:
    // <group DOM_Clock_VcpDigitalImageClock_Overridable>
    /* 
     * Get the min display size of digital image clock.
     * RETURNS: The size of this digital image clock.
     */
    virtual VfxSize onMeasureMinSize();

// Event
protected:
    // <group DOM_Clock_VcpDigitalImageClock_Event>
    // Handle the timer tick event.
    void onSeparatorTimerTick(
        VfxTimer *source // [IN] Is the timer object
    );
};

#endif /* __VCP_CLOCK_H__ */

