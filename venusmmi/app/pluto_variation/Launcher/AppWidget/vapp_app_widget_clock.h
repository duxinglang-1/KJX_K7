/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_app_widget_clock.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the clock widget.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_APP_WIDGET_CLOCK_H
#define VAPP_APP_WIDGET_CLOCK_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"
#include "vapp_app_widget_def.h"
#include "vapp_app_widget.h"


/*****************************************************************************
 * Analog Clock Widget Content Frame
 *****************************************************************************/

class VappAnalogClockContentFrame : public VfxFrame
{
    VFX_DECLARE_CLASS(VappAnalogClockContentFrame);

// Constructor / Destructor
public:
    VappAnalogClockContentFrame();

// Method
public:
    void setTime(
        const VfxDateTime &startTime
    );

// Override
protected:
    virtual void onInit();

    virtual void onDeinit();

// Enum
private:
    enum
    {

    #if defined(__MMI_MAINLCD_480X800__)
        CENTER_X = 100,
        CENTER_Y = 100  
    #elif defined(__MMI_MAINLCD_320X480__)
        CENTER_X = 75,
        CENTER_Y = 75  
    #elif defined(__MMI_MAINLCD_240X400__)
        CENTER_X = 50,
        CENTER_Y = 50  
    #else /* defined(__MMI_MAINLCD_240X320__) */
        CENTER_X = 50,
        CENTER_Y = 50 
    #endif /* defined(__MMI_MAINLCD_240X320__) */

    };

// Variable
private:
    VcpAnalogClock *m_aclock;
};


/*****************************************************************************
 * Analog Clock Widget
 *****************************************************************************/

class VappAppWidgetAnalogClock : public VappAppWidget
{
    VAPP_APP_WIDGET_DECLARE_CLASS(VappAppWidgetAnalogClock);

// Constructor / Destructor
public:
    // Default constructor
    VappAppWidgetAnalogClock();

// Override
public:
    virtual VappAppWidgetId getId() const;

    virtual VfxSize getMaxSize() const;

    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;

    virtual VfxFrame *createIcon(VfxObject *parentObj);

// Override
protected:
    virtual void onCreateView();

    virtual void onReleaseView();

    virtual VfxPoint onGetEditButtonOffset();

// Enum
private:
    enum
    {
        HORIZ_TILE_NUM = 2,
        VERTI_TILE_NUM = 2,

    #if defined(__MMI_MAINLCD_480X800__)
        WIDTH = 150,
        HEIGHT = 150,
        
        BUTTON_X = 120,
        BUTTON_Y = 24
    #elif defined(__MMI_MAINLCD_320X480__)
        WIDTH = 150,
        HEIGHT = 150,

        BUTTON_X = 120,
        BUTTON_Y = 24
    #elif defined(__MMI_MAINLCD_240X400__)
        WIDTH = 100,
        HEIGHT = 100,

        BUTTON_X = 90,
        BUTTON_Y = 20

    #else /* defined(__MMI_MAINLCD_240X320__) */
        WIDTH = 100,
        HEIGHT = 100,

        BUTTON_X = 90,
        BUTTON_Y = 20
    #endif /* defined(__MMI_MAINLCD_240X320__) */
    };

// Variable
private:
    VappAnalogClockContentFrame *m_analog;
};


/*****************************************************************************
 * Digtial Clock Widget
 *****************************************************************************/

class VappAppWidgetDigitalClock : public VappAppWidget
{
    VAPP_APP_WIDGET_DECLARE_CLASS(VappAppWidgetDigitalClock);

// Constructor / Destructor
public:
    // Default constructor
    VappAppWidgetDigitalClock();

// Override
public:
    virtual VappAppWidgetId getId() const;

    virtual VfxSize getMaxSize() const;

    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;

    virtual VfxFrame *createIcon(VfxObject *parentObj);

// Overide
protected:
    virtual void onCreateView();

    virtual void onReleaseView();

    virtual VfxPoint onGetEditButtonOffset();

// Enum
private:
    enum
    {
        HORIZ_TILE_NUM = 3,
        VERTI_TILE_NUM = 2,

    #if defined(__MMI_MAINLCD_480X800__)
        CLOCK_WIDTH = 328,
        CLOCK_HEIGHT = 195,
        
        CLOCK_12_CENTER_X = 145,
        CLOCK_24_CENTER_X = 165,
        CLOCK_CENTER_Y = 75,
        
        CLOCK_DATE_X = 14,
        CLOCK_DATE_Y = 154,
        CLOCK_DATE_W = 110,
        CLOCK_DATE_H = 20,
        
        CLOCK_CITY_X = 135,
        CLOCK_CITY_Y = 154,
        CLOCK_CITY_W = 170,
        CLOCK_CITY_H = 23,
        
        CLOCK_AM_PM_X = 268,
        CLOCK_AM_PM_Y = 92,
        CLOCK_AM_PM_W = 50,
        CLOCK_AM_PM_H = 25,

        DATE_FONT_SIZE = 20,
        CITY_FONT_SIZE = 20,
        APM_FONT_SIZE = 20,

        BUTTON_X = 300,
        BUTTON_Y = 21,
    #elif defined(__MMI_MAINLCD_320X480__)
        CLOCK_WIDTH = 230,
        CLOCK_HEIGHT = 133,

        CLOCK_12_CENTER_X = 108,
        CLOCK_24_CENTER_X = 115,
        CLOCK_CENTER_Y = 52,

        CLOCK_DATE_X = 20,
        CLOCK_DATE_Y = 100,
        CLOCK_DATE_W = 110,
        CLOCK_DATE_H = 20,

        CLOCK_CITY_X = 130,
        CLOCK_CITY_Y = 105,
        CLOCK_CITY_W = 90,
        CLOCK_CITY_H = 20,

        CLOCK_AM_PM_X = 193,
        CLOCK_AM_PM_Y = 67,
        CLOCK_AM_PM_W = 50,
        CLOCK_AM_PM_H = 20,
        
        DATE_FONT_SIZE = 14,
        CITY_FONT_SIZE = 14,
        APM_FONT_SIZE = 14,

        BUTTON_X = 210,
        BUTTON_Y = 16
    #else
        CLOCK_WIDTH = 168,
        CLOCK_HEIGHT = 98,

        CLOCK_12_CENTER_X = 75,
        CLOCK_24_CENTER_X = 85,
        CLOCK_CENTER_Y = 38,

        CLOCK_DATE_X = 11,
        CLOCK_DATE_Y = 77,
        CLOCK_DATE_W = 80,
        CLOCK_DATE_H = 11,

        CLOCK_CITY_X = 95,
        CLOCK_CITY_Y = 76,
        CLOCK_CITY_W = 65,
        CLOCK_CITY_H = 15,

        CLOCK_AM_PM_X = 140,
        CLOCK_AM_PM_Y = 49,
        CLOCK_AM_PM_W = 30,
        CLOCK_AM_PM_H = 12,

        DATE_FONT_SIZE = 10,
        CITY_FONT_SIZE = 10,
        APM_FONT_SIZE = 10,

        BUTTON_X = 153,
        BUTTON_Y = 11
    #endif
    };

// Variable
private:
    VfxImageFrame *m_bg;
    VcpDigitalImageClock *m_dclock;
    VfxTextFrame *m_city;
    VcpDigitalTextClock *m_date;
    VfxTextFrame *m_am_pm;
    VfxDateTime m_dt;

// Implementation
private:
    void onSystemTimeChanged(
        VfxU32 flag
    );

    void createDclock(VfxDateTime dt);

    void createDate(VfxDateTime dt);
};

#endif /* defined(__MMI_VUI_LAUNCHER__) */
#endif /* VAPP_APP_WIDGET_CLOCK_H */

