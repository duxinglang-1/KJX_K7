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
 *  vapp_app_widget_clock.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the clock widget.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "GlobalResDef.h"
#include "vcp_include.h"
#include "vdat_systime.h"
#include "vapp_app_widget_def.h"
#include "vapp_app_widget_clock.h"
#include "mmi_rp_vapp_app_widget_clock_def.h"

//
// Pluto headers
//
extern "C"
{
#include "worldclock.h"
#include "PhoneSetupGprots.h"
}


/*****************************************************************************
 * Analog Clock Widget Content Frame
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(
    "VappAnalogClockContentFrame",
    VappAnalogClockContentFrame,
    VfxFrame);


VappAnalogClockContentFrame::VappAnalogClockContentFrame() :
    m_aclock(NULL)
{
    // Do nothing.
}


void VappAnalogClockContentFrame::onInit()
{
    VfxFrame::onInit();

    VFX_OBJ_CREATE(m_aclock, VcpAnalogClock, this);
    m_aclock->setClockHourHand(IMG_ID_VAPP_WIDGET_ANALOG_CLOCK_H);
    m_aclock->setClockMinuteHand(IMG_ID_VAPP_WIDGET_ANALOG_CLOCK_M);
    m_aclock->setClockAxis(IMG_ID_VAPP_WIDGET_ANALOG_CLOCK_CENTER);
    m_aclock->setCenter(VfxPoint(CENTER_X, CENTER_Y));
    m_aclock->setClockBackgroundImage(IMG_ID_VAPP_WIDGET_ANALOG_CLOCK_BG);

    VfxImageFrame *hour = m_aclock->getHourHandImageFrame();
    VfxImageFrame *min = m_aclock->getMinuteHandImageFrame();
    VfxImageFrame *sec = m_aclock->getSecondHandImageFrame();

    hour->setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);
    min->setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);
    sec->setHidden(VFX_TRUE);

    min->setAnchor(VfxFPoint(0.5f, 0.9f));

    m_aclock->setTime();
    m_aclock->startClock();
}


void VappAnalogClockContentFrame::onDeinit()
{
    VFX_OBJ_CLOSE(m_aclock);

    VfxFrame::onDeinit();
}


void VappAnalogClockContentFrame::setTime(const VfxDateTime &startTime)
{
    m_aclock->setTime(startTime);
}


/*****************************************************************************
 * Analog Clock Widget
 *****************************************************************************/

VAPP_APP_WIDGET_IMPLEMENT_CLASS(VappAppWidgetAnalogClock, VappAppWidget);


VappAppWidgetAnalogClock::VappAppWidgetAnalogClock()
{
    // Do nothing.
}


VappAppWidgetId VappAppWidgetAnalogClock::getId() const
{
    return VappAppWidgetId(
            VAPP_APP_WIDGET_SRC_NATIVE,
            VAPP_APP_WIDGET_TYPE_ANALOG_CLOCK);
}


VfxSize VappAppWidgetAnalogClock::getMaxSize() const
{
    return getRoomSize(HORIZ_TILE_NUM, VERTI_TILE_NUM);
}


VfxS32 VappAppWidgetAnalogClock::getName(VfxWChar *string, VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_VAPP_WIDGET_ANALOG_CLOCK);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);
}


VfxFrame *VappAppWidgetAnalogClock::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;

    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_ID_VAPP_WIDGET_ANALOG_CLOCK_ICON);

    return icon;
}


void VappAppWidgetAnalogClock::onCreateView()
{
    VappAppWidget::onCreateView();

    setBounds(VfxRect(0, 0, WIDTH, HEIGHT));

    VFX_OBJ_CREATE(m_analog, VappAnalogClockContentFrame, this);
    m_analog->setBounds(VfxRect(0, 0, WIDTH, HEIGHT));
}


void VappAppWidgetAnalogClock::onReleaseView()
{
    VFX_OBJ_CLOSE(m_analog);
    VappAppWidget::onReleaseView();
}


VfxPoint VappAppWidgetAnalogClock::onGetEditButtonOffset()
{
    return VfxPoint(BUTTON_X, BUTTON_Y);
}


/*****************************************************************************
 * Digtial clock Widget
 *****************************************************************************/

VAPP_APP_WIDGET_IMPLEMENT_CLASS(VappAppWidgetDigitalClock, VappAppWidget);


VappAppWidgetDigitalClock::VappAppWidgetDigitalClock() :
    m_bg(NULL),
    m_dclock(NULL),
    m_city(NULL),
    m_date(NULL),
    m_am_pm(NULL)
{
    // Do nothing.
}


VappAppWidgetId VappAppWidgetDigitalClock::getId() const
{
    return VappAppWidgetId(
            VAPP_APP_WIDGET_SRC_NATIVE,
            VAPP_APP_WIDGET_TYPE_DIGITAL_CLOCK);
}


VfxSize VappAppWidgetDigitalClock::getMaxSize() const
{
    return getRoomSize(HORIZ_TILE_NUM, VERTI_TILE_NUM);
}


VfxS32 VappAppWidgetDigitalClock::getName(VfxWChar *string, VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_VAPP_WIDGET_DIGITAL_CLOCK);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);
}


VfxFrame *VappAppWidgetDigitalClock::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;

    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_ID_VAPP_WIDGET_DIGITAL_CLOCK_ICON);

    return icon;
}


void VappAppWidgetDigitalClock::createDclock(VfxDateTime dt)
{
    VFX_OBJ_CREATE(m_dclock, VcpDigitalImageClock, this);

    m_dclock->setAnchor(VfxFPoint(0.5f, 0.5f));
    m_dclock->setPos(VfxPoint(CLOCK_12_CENTER_X, CLOCK_CENTER_Y));
    m_dclock->setTime(dt);
    m_dclock->setNumber(IMG_ID_VAPP_WIDGET_DIGITAL_CLOCK_NUM_0, IMG_ID_VAPP_WIDGET_DIGITAL_CLOCK_NUM_9);
    m_dclock->setNumberBackground(vrt_sys_res_image_lock(0));
    m_dclock->setTimeSeparator(IMG_ID_VAPP_WIDGET_DIGITAL_CLOCK_COLON, IMG_ID_VAPP_WIDGET_DIGITAL_CLOCK_COLON);

    m_dclock->setAmAndPm(
        vrt_sys_res_image_lock(0),
        vrt_sys_res_image_lock(0),
        vrt_sys_res_image_lock(0),
        vrt_sys_res_image_lock(0));

    m_dclock->setGap(1, 1, 1);

    m_dclock->startClock();
}


void VappAppWidgetDigitalClock::createDate(VfxDateTime dt)
{
    VFX_OBJ_CREATE (m_date, VcpDigitalTextClock, this);
    m_date->setFormatFlags(VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY);
    m_date->setAlignMode(VcpDigitalTextClock::ALIGN_MODE_LEFT);
    m_date->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(DATE_FONT_SIZE)));
    m_date->setTextColor(VFX_COLOR_WHITE);
    m_date->setPos(CLOCK_DATE_X, CLOCK_DATE_Y);
    m_date->setSize(CLOCK_DATE_W, CLOCK_DATE_H);
    m_date->setTime(dt);
    m_date->startClock();
}


void VappAppWidgetDigitalClock::onCreateView()
{
    VappAppWidget::onCreateView();

    setBounds(VfxRect(0, 0, CLOCK_WIDTH, CLOCK_HEIGHT));

    // Background
    VFX_OBJ_CREATE(m_bg, VfxImageFrame, this);
    m_bg->setBounds(VfxRect(0, 0, CLOCK_WIDTH, CLOCK_HEIGHT));
    m_bg->setResId(IMG_ID_VAPP_WIDGET_DIGITAL_CLOCK_BG);

    // Get real time
    applib_time_struct current_time;
    applib_dt_get_rtc_time(&current_time);
    m_dt.setDateTime(&current_time);

    // Digitial clock
    createDclock(m_dt);

    // Digitial text clock
    createDate(m_dt);

    //city
    VFX_OBJ_CREATE(m_city, VfxTextFrame, this);
    m_city->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_city->setPos(VfxPoint(CLOCK_CITY_X, CLOCK_CITY_Y));
    m_city->setString(VFX_WSTR_MEM((VfxWChar *)mmi_wc_get_home_city()));
    m_city->setBounds(VfxRect(0, 0, CLOCK_CITY_W, CLOCK_CITY_H));
    m_city->setColor(VFX_COLOR_WHITE);
    m_city->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(CITY_FONT_SIZE)));
    m_city->setAutoResized(VFX_FALSE);
    m_city->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);

    // AM, PM
    VfxWString am_str;

    if(m_dt.getHour() >= 12)
    {
        am_str.loadFromMem((const VfxWChar*)L"PM");
    }
    else
    {
        am_str.loadFromMem((const VfxWChar*)L"AM");
    }

    VFX_OBJ_CREATE(m_am_pm, VfxTextFrame, this);
    m_am_pm->setPos(VfxPoint(CLOCK_AM_PM_X, CLOCK_AM_PM_Y));
    m_am_pm->setString(am_str);
    m_am_pm->setBounds(VfxRect(0, 0, CLOCK_AM_PM_W, CLOCK_AM_PM_H));
    m_am_pm->setColor(VFX_COLOR_WHITE);
    m_am_pm->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(APM_FONT_SIZE)));
    m_am_pm->setAutoResized(VFX_FALSE);
    m_am_pm->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);

    if(PhnsetGetTimeFormat()) // return 0 -- > 12 hours
    {
        m_am_pm->setHidden(VFX_TRUE);
        m_dclock->setPos(VfxPoint(CLOCK_24_CENTER_X, CLOCK_CENTER_Y));
    }

    //slot to system change
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappAppWidgetDigitalClock::onSystemTimeChanged);
}


void VappAppWidgetDigitalClock::onReleaseView()
{
    VFX_OBJ_CLOSE(m_dclock);
    VFX_OBJ_CLOSE(m_bg);
    VFX_OBJ_CLOSE(m_city);
    VFX_OBJ_CLOSE(m_date);
    VFX_OBJ_CLOSE(m_am_pm);
    VappAppWidget::onReleaseView();
}


void VappAppWidgetDigitalClock::onSystemTimeChanged(VfxU32 flag)
{
    if (flag & VDAT_SYSTIME_CHANGED_HOUR)
    {
        applib_time_struct current_time;
        applib_dt_get_rtc_time(&current_time);
        m_dt.setDateTime(&current_time);

        // AM, PM
        VfxWString am_str;

        if(m_dt.getHour() >= 12)
        {
            am_str.loadFromMem((const VfxWChar*)L"PM");
        }
        else
        {
            am_str.loadFromMem((const VfxWChar*)L"AM");
        }

        m_am_pm->setString(am_str);
    }
}


VfxPoint VappAppWidgetDigitalClock::onGetEditButtonOffset()
{
    return VfxPoint(BUTTON_X, BUTTON_Y);
}

#endif /* defined(__MMI_VUI_LAUNCHER__) */

