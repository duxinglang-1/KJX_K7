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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_hs_widget_next_alarm.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: next alarm
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_NEXT_ALARM__

/*****************************************************************************
 * Include
 *****************************************************************************/

/* Venus MMI header: */
#include "vapp_hs_widget_next_alarm.h"
#include "vadp_app_trc.h"
#include "vfx_date_time.h"
#include "vfx_datatype.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"
#include "vrt_system.h"
#include "vfx_draw_context.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_text_frame.h"
#include "vrt_datatype.h"
#include "vfx_string.h"
#include "vfx_async_signal.h"
#include "vadp_v2p_hs.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{

#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "gui_effect_oem.h"
#include "PhoneSetupGprots.h"
#include "AlarmProt.h"
#include "AlarmGprot.h"
#include "mmi_rp_app_venus_homescreen_wg_next_alarm_def.h"

}
#endif


/*****************************************************************************
 * Home screen widget: next alarm
 *****************************************************************************/

VappHsWidgetNextAlarmClock::VappHsWidgetNextAlarmClock(VfxDateTime &time) :
    m_colon(NULL),
    m_am(NULL),
    m_pm(NULL)
{
    VfxS32 i;

    for (i = 0; i < TOTAL_NUM; i++)
    {
        m_num[i] = NULL;
    }

    m_time = time;
}


void VappHsWidgetNextAlarmClock::onInit()
{
    VfxFrame::onInit();

    setBounds(VfxRect(0, 0, WIDTH, HEIGHT));

    m_num[0] = vrt_sys_res_image_lock(VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_NUMBER_0);
    m_num[1] = vrt_sys_res_image_lock(VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_NUMBER_1);
    m_num[2] = vrt_sys_res_image_lock(VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_NUMBER_2);
    m_num[3] = vrt_sys_res_image_lock(VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_NUMBER_3);
    m_num[4] = vrt_sys_res_image_lock(VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_NUMBER_4);
    m_num[5] = vrt_sys_res_image_lock(VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_NUMBER_5);
    m_num[6] = vrt_sys_res_image_lock(VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_NUMBER_6);
    m_num[7] = vrt_sys_res_image_lock(VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_NUMBER_7);
    m_num[8] = vrt_sys_res_image_lock(VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_NUMBER_8);
    m_num[9] = vrt_sys_res_image_lock(VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_NUMBER_9);
    m_colon = vrt_sys_res_image_lock(VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_COLON);
    m_am = vrt_sys_res_image_lock(VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_AM);
    m_pm = vrt_sys_res_image_lock(VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_PM);
}


void VappHsWidgetNextAlarmClock::onDeinit()
{
    VfxFrame::onDeinit();
}


void VappHsWidgetNextAlarmClock::onDraw(VfxDrawContext &dc)
{
    VfxS32 hour1, hour2, min1, min2;
    TimeType type;

    getTime(hour1, hour2, min1, min2, type);

    // Draw hour and minutes.
    if (hour1 >= 0 && hour1 < TOTAL_NUM &&
        hour2 >= 0 && hour2 < TOTAL_NUM &&
        min1 >= 0 && min1 < TOTAL_NUM &&
        min2 >= 0 && min2 < TOTAL_NUM)
    {
        dc.drawImageFromMem(VFX_POINT_ZERO,       m_num[hour1]);
        dc.drawImageFromMem(VfxPoint(HOUR2_X, 0), m_num[hour2]);
        dc.drawImageFromMem(VfxPoint(MIN1_X, 0),  m_num[min1]);
        dc.drawImageFromMem(VfxPoint(MIN2_X, 0),  m_num[min2]);
    }

    // Draw colon.
    dc.drawImageFromMem(VfxPoint(COLON_X, 0), m_colon);

    // Draw AM or PM if necessary.
    if (type == TIME_12_AM)
    {
        dc.drawImageFromMem(VfxPoint(AM_PM_X, AM_PM_Y), m_am);
    }
    else if (type == TIME_12_PM)
    {
        dc.drawImageFromMem(VfxPoint(AM_PM_X, AM_PM_Y), m_pm);
    }
}


void VappHsWidgetNextAlarmClock::getTime(
        VfxS32 &hour1,
        VfxS32 &hour2,
        VfxS32 &min1,
        VfxS32 &min2,
        TimeType &type)
{
    // Get minute number.
    min1 = m_time.getMinute() / 10;
    min2 = m_time.getMinute() - min1 * 10;

    // Get hour number and time type.
    if (PhnsetGetTimeFormat())
    {
        // This is 24-hour format.
        hour1 = m_time.getHour() / 10;
        hour2 = m_time.getHour() - hour1 * 10;
        type = TIME_24;
    }
    else
    {
        // This is 12-hour format.
        if (m_time.getHour() == 12)
        {
            hour1 = m_time.getHour() / 10;
            hour2 = m_time.getHour() - hour1 * 10;
            type = TIME_12_PM;
        }
        else if(m_time.getHour() == 0)
        {
            hour1 = 12 / 10;
            hour2 = 12 - 10;
            type = TIME_12_AM;
        }
        else if(m_time.getHour() > 12)
        {
            hour1 = (m_time.getHour() - 12) / 10;
            hour2 = (m_time.getHour() - 12) - hour1 * 10;
            type = TIME_12_PM;
        }
        else
        {
            hour1 = m_time.getHour() / 10;
            hour2 = m_time.getHour() - hour1 * 10;
            type = TIME_12_AM;
        }
    }
}


/*****************************************************************************
 * Home screen widget: next alarm
 *****************************************************************************/

VappHsWidgetNextAlarm::VappHsWidgetNextAlarm() :
    m_title(NULL),
    m_clock(NULL),
    m_date(NULL),
    m_text(NULL)
{
}


VfxU16 VappHsWidgetNextAlarm::getIcon()
{
    return VAPP_HS_IMG_WG_ICON_NEXT_ALARM;
}


VfxU16 VappHsWidgetNextAlarm::getName()
{
    return VAPP_HS_STR_WG_NEXT_ALARM;
}


void VappHsWidgetNextAlarm::onCreateView()
{
    // Background image
    VfxImageSrc bgImage;
    bgImage.setResId(VAPP_HS_IMG_WG_NEXT_ALARM_BG);

#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    setIsOpaque(VFX_TRUE);
#endif

    VfxSize size = bgImage.getSize();

    setImgContent(bgImage);
    setBounds(VfxRect(VFX_POINT_ZERO, size));
    setIsCached(VFX_TRUE);

    // Title
    VFX_OBJ_CREATE(m_title, VfxTextFrame, this);
    m_title->setAnchor(VfxFPoint(0.5f, 0.5f));
    m_title->setPos(VfxPoint(size.width / 2, TITLE_Y));
    m_title->setColor(VFX_COLOR_WHITE);
    m_title->setFont(VfxFontDesc(g_vfxFontSmall));
    m_title->setString(VFX_WSTR_RES(VAPP_HS_STR_WG_NEXT_ALARM));

    // Time
    VfxDateTime time;

    if (getNextAlarm(time))
    {
        updateTime(time);
    }
    else
    {
        updateNone();
    }
}


void VappHsWidgetNextAlarm::onReleaseView()
{
    VFX_OBJ_CLOSE(m_title);
    VFX_OBJ_CLOSE(m_clock);
    VFX_OBJ_CLOSE(m_date);
    VFX_OBJ_CLOSE(m_text);
}


void VappHsWidgetNextAlarm::launch(void *user_data)
{
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_VUI_ENGINE__)
    gui_screen_switch_effect_v2p_setup_widget();
#endif

    EntryAlmMenu();
}


void VappHsWidgetNextAlarm::onDirectLaunch()
{
    vfxPostInvoke(this, &VappHsWidgetNextAlarm::launch);
}


VfxBool VappHsWidgetNextAlarm::getNextAlarm(VfxDateTime &time)
{
    MYTIME t;

    if (!mmi_alm_get_next_alarm(&t, MMI_FALSE))
    {
        return VFX_FALSE; // do not have alarm.
    }

    time.setDate(t.nYear, t.nMonth, t.nDay);
    time.setTime(t.nHour, t.nMin, t.nSec);

    return VFX_TRUE;
}


void VappHsWidgetNextAlarm::updateTime(VfxDateTime &time)
{
    VfxWChar strBuf[MAX_STR_BUF_SIZE];

    VfxImageSrc bgImage;
    bgImage.setResId(VAPP_HS_IMG_WG_NEXT_ALARM_BG);

    VfxSize size = bgImage.getSize();

    // Digital image clock in the central of the widget.
    VFX_OBJ_CREATE_EX(m_clock, VappHsWidgetNextAlarmClock, this, (time));
    m_clock->setPos(VfxPoint(TIME_X, TIME_Y));

    // Date string in the buttom of the widget.
    VFX_OBJ_CREATE(m_date, VfxTextFrame, this);
    m_date->setAnchor(VfxFPoint(0.5f, 0.5f));
    m_date->setPos(VfxPoint(size.width / 2, DATE_Y));
    m_date->setColor(VFX_COLOR_WHITE);
    m_date->setFont(VfxFontDesc(g_vfxFontSmall));

    VfxS32 formatFlags = VFX_DATE_TIME_DATE_YEAR |
                         VFX_DATE_TIME_DATE_MONTH |
                         VFX_DATE_TIME_DATE_DAY;

    time.getDateTimeString(formatFlags, strBuf, MAX_STR_BUF_SIZE);
    m_date->setString(VFX_WSTR_MEM(strBuf));
}


void VappHsWidgetNextAlarm::updateNone()
{
    // "None" string in the central of the widget.
    VfxImageSrc bgImage;
    bgImage.setResId(VAPP_HS_IMG_WG_NEXT_ALARM_BG);

    VfxSize size = bgImage.getSize();

    VFX_OBJ_CREATE(m_text, VfxTextFrame, this);
    m_text->setAnchor(VfxFPoint(0.5f, 0.5f));
    m_text->setPos(VfxPoint(size.width / 2, NONE_Y));
    m_text->setColor(VFX_COLOR_WHITE);
    m_text->setFont(VfxFontDesc(g_vfxFontSmall));
    m_text->setString(VFX_WSTR_RES(STR_GLOBAL_NONE));
}

#endif /* __MMI_VUI_HOMESCREEN_NEXT_ALARM__ */

