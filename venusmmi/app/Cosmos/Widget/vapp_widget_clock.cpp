/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_widget_clock.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the hello world widget.
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

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_widget_def.h"
#include "vapp_widget_native_factory.h"
#include "vapp_widget_clock.h"
#include "vcp_include.h"
#include "data\vdat_systime.h"
#include "mmi_rp_vapp_widget_clock_def.h"
#include "vcui_worldclock_select_city_gprot.h"
#include "vapp_worldclock_gprot.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "GlobalResDef.h"
#ifdef __cplusplus
}
#endif


static VfxU16 g_widget_clock2_city_index;
static VfxU16 g_widget_dclock_city_index;
void VappClockDataControl::getTime(VfxFloat src, VfxFloat des, VfxDateTime &dt,  VfxU16 city_index)
{
	VfxU8 increase_flag = 0;
    VfxFloat time_zone_diff = 0;
	VfxU16 home_index;

	home_index = mmi_wc_get_home_index();
    applib_time_struct temp_time, time_diff, time_result;
	applib_dt_get_rtc_time(&temp_time);
    if (des > src)
    {
        increase_flag = 1;
        time_zone_diff = des - src ;
    }
    else if (des < src)
    {
        increase_flag = 0;
        time_zone_diff = des - src ;
		time_zone_diff = - time_zone_diff;
    }
    
    time_diff = applib_conv_tz_to_mytime(time_zone_diff);
    
    if (increase_flag)
    {
        applib_dt_increase_time(&temp_time, &time_diff, &time_result);
    }
    else
    {
        applib_dt_decrease_time(&temp_time, &time_diff, &time_result);
    }

	if(home_index != city_index)
	{
		VfxU8 city_daylight;
		VfxU8 home_daylight = mmi_wc_get_home_dst();

		if(city_index == mmi_wc_get_frn_index(0))
			city_daylight = mmi_wc_get_frn_dst(0);
		else if(city_index == mmi_wc_get_frn_index(1))
			city_daylight = mmi_wc_get_frn_dst(1);
		else
			city_daylight = 0;


		if(!city_daylight && home_daylight)
        {
		    applib_time_struct decreaseDST;
            memset(&decreaseDST, 0, sizeof(applib_time_struct));
            decreaseDST.nHour = 1;
            applib_dt_decrease_time(&time_result, &decreaseDST, &time_result);
        }

		if(city_daylight && !home_daylight)
		{
			applib_time_struct increaseDST;
			memset(&increaseDST, 0, sizeof(applib_time_struct));
			increaseDST.nHour = 1;
			applib_dt_increase_time(&time_result, &increaseDST, &time_result);
		}
	}
    dt.setDateTime(&time_result);
}

/*****************************************************************************
 * Analog CP Widget
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappAnalogClock", VappAnalogClock, VcpAnalogClock);
VappAnalogClock::VappAnalogClock(VfxU8 style) :
	m_aclock(NULL),
	m_style(style)
{

}
VappAnalogClock::VappAnalogClock()
{
	m_aclock = NULL;
	m_style = CLOCK_STYLE1;
}

void VappAnalogClock::setTime(const VfxDateTime &startTime)
{
	m_aclock->setTime(startTime);
}

void VappAnalogClock::onInit()
{
	VfxControl::onInit();

	VFX_OBJ_CREATE(m_aclock, VcpAnalogClock, this);
	m_aclock->setTime();
	m_aclock->setPos(VfxPoint(0, 0));

	switch(m_style)
	{
#ifdef __MMI_VUI_WIDGET_CLOCK1__
	case CLOCK_STYLE1:
			  {
				m_aclock->setClockHourHand(IMG_CLOCK1_WIDGET_H);
				m_aclock->setClockMinuteHand(IMG_CLOCK1_WIDGET_M);
				m_aclock->setClockSecondHand(IMG_CLOCK1_WIDGET_S);
				m_aclock->setClockAxis(IMG_CLOCK1_WIDGET_CENTER);
				m_aclock->setCenter(VfxPoint(VAPP_WIDGET_CLOCK1_CENTER_X, VAPP_WIDGET_CLOCK1_CENTER_Y));
				m_aclock->setClockBackgroundImage(IMG_CLOCK1_WIDGET_BG);
				break;
			  }
#endif /* __MMI_VUI_WIDGET_CLOCK1__ */
#ifdef __MMI_VUI_WIDGET_CLOCK2__
	case CLOCK_STYLE2:
			 {
				m_aclock->setClockHourHand(IMG_CLOCK2_WIDGET_H);
				m_aclock->setClockMinuteHand(IMG_CLOCK2_WIDGET_M);
				m_aclock->setClockSecondHand(IMG_CLOCK2_WIDGET_S);
				m_aclock->setClockAxis(IMG_CLOCK2_WIDGET_CENTER);
				m_aclock->setCenter(VfxPoint(VAPP_WIDGET_CLOCK2_CENTER_X, VAPP_WIDGET_CLOCK2_CENTER_Y));
				m_aclock->setClockBackgroundImage(IMG_CLOCK2_WIDGET_BG);
				break;
			 }
#endif
#ifdef __MMI_VUI_WIDGET_CLOCK3__
	case CLOCK_STYLE3:
			 {
				m_aclock->setClockHourHand(IMG_CLOCK3_WIDGET_H);
				m_aclock->setClockMinuteHand(IMG_CLOCK3_WIDGET_M);
				m_aclock->setClockSecondHand(IMG_CLOCK3_WIDGET_S);
				m_aclock->setClockAxis(IMG_CLOCK3_WIDGET_CENTER);
				m_aclock->setCenter(VfxPoint(VAPP_WIDGET_CLOCK3_CENTER_X, VAPP_WIDGET_CLOCK3_CENTER_Y));
				m_aclock->setClockBackgroundImage(IMG_CLOCK3_WIDGET_BG);
			
	           break;
			 }
#endif /* __MMI_VUI_WIDGET_CLOCK3__ */
#ifdef __MMI_VUI_WIDGET_CLOCK4__
	case CLOCK_STYLE4:
			 {
				//m_aclock->setClockBackground(vrt_sys_res_image_lock(IMG_CLOCK4_WIDGET_BG));
				m_aclock->setClockHourHand(IMG_CLOCK4_WIDGET_H);
				m_aclock->setClockMinuteHand(IMG_CLOCK4_WIDGET_M);
				m_aclock->setClockSecondHand(IMG_CLOCK4_WIDGET_S);
				m_aclock->setClockAxis(IMG_CLOCK4_WIDGET_CENTER);
				m_aclock->setCenter(VfxPoint(VAPP_WIDGET_CLOCK4_CENTER_X, VAPP_WIDGET_CLOCK4_CENTER_Y));
	            m_aclock->setClockBackgroundImage(IMG_CLOCK4_WIDGET_BG);
				break;
			 }
#endif /*__MMI_VUI_WIDGET_CLOCK4__ */
		default:
			 break;
	}

	VfxImageFrame *hour, *min, *sec;
	hour = m_aclock->getHourHandImageFrame();
	min = m_aclock->getMinuteHandImageFrame();
	sec = m_aclock->getSecondHandImageFrame();
	hour->setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);
	min->setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);
	sec->setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);
	if(m_style == CLOCK_STYLE2)
	{
		hour->setAnchor(VfxFPoint(0.5, 0.9));
		min->setAnchor(VfxFPoint(0.5, 0.9));
	}
	if(m_style == CLOCK_STYLE3)
	{
		min->setAnchor(VfxFPoint(0.5, 0.9));
	}
	if(m_style == CLOCK_STYLE4)
	{
		sec->setHidden(VFX_TRUE);
		min->setAnchor(VfxFPoint(0.5, 0.9));

	}
	sec->setAnchor(VfxFPoint(0.5, 0.8));
	m_aclock->startClock();

}
void VappAnalogClock::setFrameCustom(VfxFrame *customFrame)
	{
	m_aclock->setFrameCustom(customFrame);
}
void VappAnalogClock::onDeinit()
{
	VFX_OBJ_CLOSE(m_aclock);
	VfxControl::onDeinit();
}
void VappAnalogClock::hideSecondHande()
{
	VfxImageFrame *sec;
	sec = m_aclock->getSecondHandImageFrame();
	sec->setHidden(VFX_TRUE);
}
void VappAnalogClock::unhideSecondHande()
{
	VfxImageFrame *sec;
	sec = m_aclock->getSecondHandImageFrame();
	sec->setHidden(VFX_FALSE);
}
VfxBool VappAnalogClock::getHiddenSecondHande()
{
	VfxImageFrame *sec;
	sec = m_aclock->getSecondHandImageFrame();
	return sec->getHidden();
}
/*****************************************************************************
 * Analog Widget 1
 *****************************************************************************/
#ifdef __MMI_VUI_WIDGET_CLOCK1__

VAPP_WIDGET_SYS_PUBLISH_NATIVE(VappWidgetClock1, VAPP_WIDGET_TYPE_CLOCK1, VappWidgetClock1Publisher);
VAPP_WIDGET_IMPLEMENT_CLASS(VappWidgetClock1, VappWidget);

VappWidgetClock1::VappWidgetClock1()
{
    // Do nothing.
}


VappWidgetId VappWidgetClock1::getId() const
{
    return VappWidgetId(VAPP_WIDGET_SRC_NATIVE, VAPP_WIDGET_TYPE_CLOCK1);
}


VfxSize VappWidgetClock1::getMaxSize() const
{
    return VfxSize(MAX_SIZE_WIDTH, MAX_SIZE_HEIGHT);
}


VfxS32 VappWidgetClock1::getName(VfxWChar *string, VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_WIDGET_CLOCK1_NAME);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);
}


VfxFrame *VappWidgetClock1::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;

    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_CLOCK1_WIDGET_ICON);

    return icon;
}


void VappWidgetClock1::onCreateView()
{
    VappWidget::onCreateView();

    setBounds(VfxRect(0, 0, WIDTH, HEIGHT));

	// analog clock
	VFX_OBJ_CREATE_EX(m_analog, VappAnalogClock, this,(VappAnalogClock::CLOCK_STYLE1));
	m_analog->setBounds(VfxRect(0, 0, WIDTH, HEIGHT));

	VFX_OBJ_CREATE (m_date, VcpDigitalTextClock, m_analog);  
	m_date->setFormatFlags(VFX_DATE_TIME_DATE_YEAR|
							VFX_DATE_TIME_DATE_MONTH|
							VFX_DATE_TIME_DATE_DAY); 
	m_date->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_WIDGET_CLOCK1_TEXT_SIZE)));
	m_date->setTextColor(VRT_COLOR_MAKE(255, 200, 200, 200));

	m_date->setPos(VfxPoint(VAPP_WIDGET_CLOCK1_TEXT_X, VAPP_WIDGET_CLOCK1_TEXT_Y));
	m_date->setBounds(VfxRect(0, 0, VAPP_WIDGET_CLOCK1_TEXT_W, VAPP_WIDGET_CLOCK1_TEXT_H));
	m_date->startClock();
	m_date->setTime();
	m_analog->setFrameCustom(m_date);

}
void VappWidgetClock1::onSerializeView(VfxArchive *ar)
{
	applib_time_struct time;

	applib_dt_get_rtc_time(&time);

	ar->writeU8(time.nDay);
	ar->writeU16(time.nMonth);
	ar->writeU32(time.nYear);
	VFX_OBJ_CLOSE(m_analog);
}

void VappWidgetClock1::onRestoreView(VfxArchive *ar)
{
	VfxU8 day;
	VfxU16 month;
	VfxU32 year;
	applib_time_struct time;

	day = ar->readU8();
	month = ar->readU16();
    year = ar->readU32();
	applib_dt_get_rtc_time(&time);

	if(1) //(day != time.nDay) || (month != time.nMonth) || (year != time.nYear))
	{
		//VFX_OBJ_CLOSE(m_analog);
		VFX_OBJ_CREATE_EX(m_analog, VappAnalogClock, this,(VappAnalogClock::CLOCK_STYLE1));
		m_analog->setBounds(VfxRect(0, 0, WIDTH, HEIGHT));

		VFX_OBJ_CREATE (m_date, VcpDigitalTextClock, m_analog);  
		m_date->setFormatFlags(VFX_DATE_TIME_DATE_YEAR|
								VFX_DATE_TIME_DATE_MONTH|
								VFX_DATE_TIME_DATE_DAY); 
		m_date->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_WIDGET_CLOCK1_TEXT_SIZE)));
		m_date->setTextColor(VRT_COLOR_MAKE(255, 200, 200, 200));

		m_date->setPos(VfxPoint(VAPP_WIDGET_CLOCK1_TEXT_X, VAPP_WIDGET_CLOCK1_TEXT_Y));
		m_date->setBounds(VfxRect(0, 0, VAPP_WIDGET_CLOCK1_TEXT_W, VAPP_WIDGET_CLOCK1_TEXT_H));
		m_date->startClock();
		m_date->setTime();
		m_analog->setFrameCustom(m_date);
	}
}
void VappWidgetClock1::onReleaseView()
{
    VFX_OBJ_CLOSE(m_analog);
    VappWidget::onReleaseView();
}

VfxPoint VappWidgetClock1::onGetEditButtonOffset()

{
	return VfxPoint(BUTTON_X, BUTTON_Y); 
}
void VappWidgetClock1::onEnterSlimView()
{
	m_analog->hideSecondHande();
}

void VappWidgetClock1::onExitSlimView()
{
	m_analog->unhideSecondHande();
}
#endif /*__MMI_VUI_WIDGET_CLOCK1__ */

#if defined(__MMI_VUI_WIDGET_CLOCK2__) || defined(__MMI_VUI_WIDGET_DCLOCK__)
extern "C" void vapp_widget_clock_launch(VfxU16 type)
{
    VfxAppLauncher::launch( 
        VAPP_WIDGET_CLOCK,
        VFX_OBJ_CLASS_INFO(VappWidgetClock),
        GRP_ID_ROOT,
		&type,sizeof(VfxU16));
}
#endif
/*****************************************************************************
 * Analog Widget 2
 *****************************************************************************/
#ifdef __MMI_VUI_WIDGET_CLOCK2__
VAPP_WIDGET_SYS_PUBLISH_NATIVE(VappWidgetClock2, VAPP_WIDGET_TYPE_CLOCK2, VappWidgetClock2Publisher);
VAPP_WIDGET_IMPLEMENT_CLASS(VappWidgetClock2, VappWidget);

VappWidgetClock2::VappWidgetClock2()
{
    // Do nothing.

	m_launch = VFX_FALSE;

}


VappWidgetId VappWidgetClock2::getId() const
{
    return VappWidgetId(VAPP_WIDGET_SRC_NATIVE, VAPP_WIDGET_TYPE_CLOCK2);
}


VfxSize VappWidgetClock2::getMaxSize() const
{
    return VfxSize(MAX_SIZE_WIDTH, MAX_SIZE_HEIGHT);
}


VfxS32 VappWidgetClock2::getName(VfxWChar *string, VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_WIDGET_CLOCK2_NAME);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);
}


VfxFrame *VappWidgetClock2::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;

    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_CLOCK2_WIDGET_ICON);

    return icon;
}

void VappWidgetClock2::launchWorldClock()
{	
	m_launch = MMI_TRUE;
	vapp_widget_clock_launch(0);
}

void VappWidgetClock2::onTap(
        const VfxPoint &pos
    )
{
	launchWorldClock();
}

void VappWidgetClock2::onCreateView()
{
    VappWidget::onCreateView();

    setBounds(VfxRect(0, 0, WIDTH, HEIGHT));

	VfxS16 error;
	VfxU16 city_index;
	applib_time_struct current_time;
	VfxDateTime dt;
	ReadValue(NVRAM_WIDGET_CLOCK2_CITY_INDEX, &city_index, DS_SHORT, &error);
	g_widget_clock2_city_index = mmi_wc_get_home_index();
	applib_dt_get_rtc_time(&current_time);
	dt.setDateTime(&current_time);

	if(city_index != 0XFFFF)
	{
		VfxFloat homeTz, newTz;
		VappClockDataControl dataInter;

		VfxU16 home_index = mmi_wc_get_home_index();

		homeTz = mmi_wc_get_time_zone(home_index);
		newTz = mmi_wc_get_time_zone(city_index);

		dataInter.getTime(homeTz, newTz, dt, city_index);
		g_widget_clock2_city_index = city_index;
	}
	// analog clock
	VFX_OBJ_CREATE_EX(m_analog, VappAnalogClock, this,(VappAnalogClock::CLOCK_STYLE2));
	m_analog->setBounds(VfxRect(0, 0, WIDTH, HEIGHT));
	m_analog->setTime(dt);

	VFX_OBJ_CREATE(m_custom, VfxFrame, this);
	m_custom->setPos(VfxPoint(0,0));
	m_custom->setBounds(VfxRect(0, 0, WIDTH, HEIGHT));

	// Month text
	VfxWString str;
	//applib_time_struct current_time;
	VFX_OBJ_CREATE(m_month_text, VfxTextFrame, m_custom);
	m_month_text->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	m_month_text->setPos(VfxPoint(MONTH_TEXT_X, MONTH_TEXT_Y));
	m_month_text->setBounds(VfxRect(0, 0, MONTH_TEXT_W, MONTH_TEXT_H));
	m_month_text->setColor(VFX_COLOR_WHITE);
	m_month_text->setFont(VfxFontDesc(VAPP_WIDGET_CLOCK2_MONTH_FONT_SIZE));
	m_month_text->setAutoResized(VFX_FALSE);
	m_month_text->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);

	//applib_dt_get_date_time(&current_time);
	//str.loadFromMem(strMonthNames1[dt.getMonth() - 1]);
	str.loadFromRes(STR_ID_WIDGET_CLOCK2_JAN+dt.getMonth()-1);
	m_month_text->setString(str);

	// Day text
	VfxWString day_str;
	VFX_OBJ_CREATE(m_day_text, VfxTextFrame, m_custom);
	m_day_text->setPos(VfxPoint(DAY_TEXT_X, DAY_TEXT_Y));
	m_day_text->setBounds(VfxRect(0, 0, DAY_TEXT_W, DAY_TEXT_H));
	day_str.format("%d", dt.getDay());
	m_day_text->setString(day_str);
	m_day_text->setColor(VFX_COLOR_WHITE);
	m_day_text->setFont(VfxFontDesc(VAPP_WIDGET_CLOCK2_DAY_FONT_SIZE));
	m_day_text->setAutoResized(VFX_FALSE);
	m_day_text->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);

	// City
	VfxWString city_str;

	city_str.loadFromRes(mmi_wc_get_city_strid(g_widget_clock2_city_index));
	//city_str.loadFromMem((const VfxWChar*)L"Beijing");
	VFX_OBJ_CREATE(m_city_text, VfxTextFrame, m_custom);
	m_city_text->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	m_city_text->setPos(VfxPoint(CITY_TEXT_X, CITY_TEXT_Y));
	m_city_text->setString(city_str);
	m_city_text->setBounds(VfxRect(0, 0, CITY_TEXT_W, CITY_TEXT_H));
	m_city_text->setColor(VFX_COLOR_WHITE);
	m_city_text->setFont(VfxFontDesc(VAPP_WIDGET_CLOCK2_CITY_FONT_SIZE));
	m_city_text->setAutoResized(VFX_FALSE);
	m_city_text->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);

    m_analog->setFrameCustom(m_custom);

	VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappWidgetClock2::onSystemTimeChanged);

}

void VappWidgetClock2::updateClock(VfxU16 city_index, VfxBool is_hidden)
{
	// city text
	VfxWString city_str;
	city_str.loadFromRes(mmi_wc_get_city_strid(city_index));
	m_city_text->setString(city_str);
    
	// update time
	VfxDateTime dt;
	VfxFloat homeTz, newTz;
	VappClockDataControl dataInter;
	VfxBool isHidden = VFX_FALSE;

	VfxU16 home_index = mmi_wc_get_home_index();

	homeTz = mmi_wc_get_time_zone(home_index);
	newTz = mmi_wc_get_time_zone(city_index);

	dataInter.getTime(homeTz, newTz, dt, city_index);
	//if(m_analog->getHiddenSecondHande())
	//{
	//	isHidden = VFX_TRUE;
	//}
	//VFX_OBJ_CLOSE(m_analog);  // avoid splash
	VFX_OBJ_CREATE_EX(m_analog, VappAnalogClock, this,(VappAnalogClock::CLOCK_STYLE2));
	m_analog->setBounds(VfxRect(0, 0, WIDTH, HEIGHT));
	m_analog->setTime(dt);

	m_analog->setFrameCustom(m_custom);
	if(isHidden)
	{
		m_analog->hideSecondHande();
	}
	// updat day and month
	VfxWString str;
	//str.loadFromMem(strMonthNames1[dt.getMonth() - 1]);
	str.loadFromRes(STR_ID_WIDGET_CLOCK2_JAN+dt.getMonth()-1);
	m_month_text->setString(str);

	VfxWString day_str;
	day_str.format("%d", dt.getDay());
	m_day_text->setString(day_str);

}

void VappWidgetClock2::onReleaseView()
{
     VFX_OBJ_CLOSE(m_analog);
	 VFX_OBJ_CLOSE(m_custom);
     VappWidget::onReleaseView();
}

void VappWidgetClock2::onSerializeView(VfxArchive *ar)
{
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.disconnect(this, &VappWidgetClock2::onSystemTimeChanged);
	if(m_analog->getHiddenSecondHande())
	{
		ar->writeU16(1);
	}
	else
	{
		ar->writeU16(0);
	}
	VFX_OBJ_CLOSE(m_analog);

}

void VappWidgetClock2::onRestoreView(VfxArchive *ar)
{
	VfxS16 error;
	VfxU16 home_index = mmi_wc_get_home_index();
	if((g_widget_clock2_city_index == 0) && home_index)
		g_widget_clock2_city_index = home_index;
	VfxBool isHidden = VFX_FALSE;
	if(ar->readU16())
		isHidden = VFX_TRUE;
	updateClock(g_widget_clock2_city_index, isHidden);
	m_launch = VFX_FALSE;
	//if(m_launch)
	//WriteValue(NVRAM_WIDGET_CLOCK2_CITY_INDEX, &g_widget_clock2_city_index, DS_SHORT, &error);
	VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappWidgetClock2::onSystemTimeChanged);
}
VfxBool VappWidgetClock2::onContainPoint(const VfxPoint &point) const
{
	VfxS32 x, y, r;
	VfxS32 r1, r2;

	x = WIDTH / 2;
	y = HEIGHT / 2;

	r = (x > y) ? x : y;

	r1 = (point.x > x) ? (point.x - x) : (x - point.x);
	r2 = (point.y > y) ? (point.y - y) : (y - point.y);

   if(r1*r1 + r2*r2 <= r*r)
	   return VFX_TRUE;
   else
	   return VFX_FALSE;
}
VfxPoint VappWidgetClock2::onGetEditButtonOffset()

{
	return VfxPoint(BUTTON_X, BUTTON_Y); 
}
void VappWidgetClock2::onSystemTimeChanged(VfxU32 flag)
{
    if ((flag & VDAT_SYSTIME_CHANGED_HOUR))
    {
		// update time
		VfxDateTime dt;
		VfxFloat homeTz, newTz;
		VappClockDataControl dataInter;
		VfxU16 home_index = mmi_wc_get_home_index();

		homeTz = mmi_wc_get_time_zone(home_index);
		newTz = mmi_wc_get_time_zone(g_widget_clock2_city_index);
	
		dataInter.getTime(homeTz, newTz, dt, g_widget_clock2_city_index);
		// updat day and month
		VfxWString str;
		//str.loadFromMem(strMonthNames1[dt.getMonth() - 1]);
		str.loadFromRes(STR_ID_WIDGET_CLOCK2_JAN+dt.getMonth()-1);
		m_month_text->setString(str);

		VfxWString day_str;
		day_str.format("%d", dt.getDay());
		m_day_text->setString(day_str);
    }
}
void VappWidgetClock2::onEnterSlimView()
{
	m_analog->hideSecondHande();
}

void VappWidgetClock2::onExitSlimView()
{
	m_analog->unhideSecondHande();
}

#endif /* __MMI_VUI_WIDGET_CLOCK2__ */

#if defined(__MMI_VUI_WIDGET_CLOCK2__) || defined(__MMI_VUI_WIDGET_DCLOCK__)
VFX_IMPLEMENT_CLASS("VappWidgetClock", VappWidgetClock, VfxApp);

//MMI_ID g_wc_id = 0;
void VappWidgetClock::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);
	VappWidgetClocktScrn *scrn;
	VfxU16 *temp;
	temp = (VfxU16*)(args);
	m_type = *temp;

    VFX_OBJ_CREATE(scrn, VappWidgetClocktScrn, this);
    scrn->show();
}

mmi_ret VappWidgetClock::onProc(mmi_event_struct *evt)
{
	cui_wc_event_struct *wc_event = (cui_wc_event_struct*)evt;
	if(wc_event->evt_id == EVT_ID_CUI_WC_CITY_SELECTED)
	{
	//	vcui_wc_select_city_close(wc_event->sender_id);
#if defined(__MMI_VUI_WIDGET_CLOCK2__)
		if(m_type == 0)
		{
			S16 error;
			g_widget_clock2_city_index = wc_event->cityIndex;
		    WriteValue(NVRAM_WIDGET_CLOCK2_CITY_INDEX, &g_widget_clock2_city_index, DS_SHORT, &error);

		}
#endif
#if defined(__MMI_VUI_WIDGET_DCLOCK__)
	if(m_type == 1)
			g_widget_dclock_city_index = wc_event->cityIndex;
#endif
		VfxAppLauncher::terminate( 
        VAPP_WIDGET_CLOCK);

	 return MMI_RET_OK;

	}

	return VfxApp::onProc(evt);
}
 VfxBool VappWidgetClock::onScrBack(VfxAppScr *scr)
 {
	 return VfxApp::onScrBack(scr);
 }

 VFX_IMPLEMENT_CLASS("VappWidgetClocktScrn", VappWidgetClocktScrn, VfxMainScr);

void VappWidgetClocktScrn::on1stReady()
{
    VfxMainScr::on1stReady();
	mmi_id cui_id;
	VfxWString city_str;

	cui_wc_launch_struct wc;

	wc.isSetHomeCity = 0;
	city_str.loadFromRes(STR_ID_WIDGET_CLOCK_NEW_CITY);

	cui_id = vcui_wc_select_city_create(VAPP_WIDGET_CLOCK, wc);
	vcui_wc_select_city_set_title(cui_id, city_str);
	vcui_wc_select_city_run(cui_id);
}

void VappWidgetClocktScrn::onEnter(VfxBool isBackward)
{
	VfxScreen::onEnter(isBackward);

	if(isBackward)
		VfxAppLauncher::terminate( 
			VAPP_WIDGET_CLOCK);
}

#endif /*defined(__MMI_VUI_WIDGET_CLOCK2__) || defined(__MMI_VUI_WIDGET_DCLOCK__)*/
/*****************************************************************************
 * Analog Widget 3
 *****************************************************************************/
#ifdef __MMI_VUI_WIDGET_CLOCK3__
VAPP_WIDGET_SYS_PUBLISH_NATIVE(VappWidgetClock3, VAPP_WIDGET_TYPE_CLOCK3, VappWidgetClock3Publisher);
VAPP_WIDGET_IMPLEMENT_CLASS(VappWidgetClock3, VappWidget);

VappWidgetClock3::VappWidgetClock3()
{
    // Do nothing.
}


VappWidgetId VappWidgetClock3::getId() const
{
    return VappWidgetId(VAPP_WIDGET_SRC_NATIVE, VAPP_WIDGET_TYPE_CLOCK3);
}


VfxSize VappWidgetClock3::getMaxSize() const
{
    return VfxSize(MAX_SIZE_WIDTH, MAX_SIZE_HEIGHT);
}


VfxS32 VappWidgetClock3::getName(VfxWChar *string, VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_WIDGET_CLOCK3_NAME);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);
}


VfxFrame *VappWidgetClock3::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;

    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_CLOCK3_WIDGET_ICON);

    return icon;
}


void VappWidgetClock3::onCreateView()
{
    VappWidget::onCreateView();

    setBounds(VfxRect(0, 0, WIDTH, HEIGHT));

	// analog clock
	VFX_OBJ_CREATE_EX(m_analog, VappAnalogClock, this,(VappAnalogClock::CLOCK_STYLE3));
	m_analog->setBounds(VfxRect(0, 0, WIDTH, HEIGHT));
}


void VappWidgetClock3::onReleaseView()
{
    VFX_OBJ_CLOSE(m_analog);
    VappWidget::onReleaseView();
}

VfxPoint VappWidgetClock3::onGetEditButtonOffset()

{
	return VfxPoint(BUTTON_X, BUTTON_Y); 
}
void VappWidgetClock3::onEnterSlimView()
{
	m_analog->hideSecondHande();
}

void VappWidgetClock3::onExitSlimView()
{
	m_analog->unhideSecondHande();
}

#endif /*__MMI_VUI_WIDGET_CLOCK3__ */
/*****************************************************************************
 * Analog Widget 4
 *****************************************************************************/
#ifdef __MMI_VUI_WIDGET_CLOCK4__
VAPP_WIDGET_SYS_PUBLISH_NATIVE(VappWidgetClock4, VAPP_WIDGET_TYPE_CLOCK4, VappWidgetClock4Publisher);
VAPP_WIDGET_IMPLEMENT_CLASS(VappWidgetClock4, VappWidget);

VappWidgetClock4::VappWidgetClock4()
{
    // Do nothing.
}


VappWidgetId VappWidgetClock4::getId() const
{
    return VappWidgetId(VAPP_WIDGET_SRC_NATIVE, VAPP_WIDGET_TYPE_CLOCK4);
}


VfxSize VappWidgetClock4::getMaxSize() const
{
    return VfxSize(MAX_SIZE_WIDTH, MAX_SIZE_HEIGHT);
}


VfxS32 VappWidgetClock4::getName(VfxWChar *string, VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_WIDGET_CLOCK4_NAME);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);
}


VfxFrame *VappWidgetClock4::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;

    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_CLOCK4_WIDGET_ICON);

    return icon;
}


void VappWidgetClock4::onCreateView()
{
    VappWidget::onCreateView();

    setBounds(VfxRect(0, 0, WIDTH, HEIGHT));

	// analog clock
	VFX_OBJ_CREATE_EX(m_analog, VappAnalogClock, this,(VappAnalogClock::CLOCK_STYLE4));
	m_analog->setBounds(VfxRect(0, 0, WIDTH, HEIGHT));
}


void VappWidgetClock4::onReleaseView()
{
    VFX_OBJ_CLOSE(m_analog);
    VappWidget::onReleaseView();
}

VfxPoint VappWidgetClock4::onGetEditButtonOffset()
{
	return VfxPoint(BUTTON_X, BUTTON_Y); 
}
#endif /*__MMI_VUI_WIDGET_CLOCK4__ */
/*****************************************************************************
 * Digtial clock Widget
 *****************************************************************************/
#ifdef __cplusplus
extern "C"
{
extern U8 PhnsetGetTimeFormat(void);
}
#endif
#ifdef __MMI_VUI_WIDGET_DCLOCK__
VAPP_WIDGET_SYS_PUBLISH_NATIVE(VappWidgetDigtialClock, VAPP_WIDGET_TYPE_DCLOCK, VappWidgetDigtialClockPublisher);
VAPP_WIDGET_IMPLEMENT_CLASS(VappWidgetDigtialClock, VappWidget);

void VappWidgetDigtialClock::launchWorldClock()
{	
	m_launch  = VFX_TRUE;
	vapp_widget_clock_launch(1);
}

VappWidgetDigtialClock::VappWidgetDigtialClock() :
    m_bg(NULL),
	m_dclock(NULL),
	m_city(NULL),
	m_date(NULL),
	m_am_pm(NULL),
	m_launch(VFX_FALSE)
{

}

VappWidgetId VappWidgetDigtialClock::getId() const
{
    return VappWidgetId(VAPP_WIDGET_SRC_NATIVE, VAPP_WIDGET_TYPE_DCLOCK);
}


VfxSize VappWidgetDigtialClock::getMaxSize() const
{
    return VfxSize(MAX_SIZE_WIDTH, MAX_SIZE_HEIGHT);
}


VfxS32 VappWidgetDigtialClock::getName(VfxWChar *string, VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_WIDGET_DCLOCK_NAME);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);
}


VfxFrame *VappWidgetDigtialClock::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;

    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(VAPP_HS_IMG_WG_DCLOCK_ICON);

    return icon;
}

void VappWidgetDigtialClock::createDclock(VfxDateTime dt)
{
	VFX_OBJ_CREATE(m_dclock, VcpDigitalImageClock, this);
    m_dclock->setAnchor(VfxFPoint(0.5, 0.5));
    m_dclock->setPos(VfxPoint(D_CLOCK_12_CENTER_X, D_CLOCK_CENTER_Y));
    m_dclock->setTime(dt);
    m_dclock->setNumber(VAPP_HS_IMG_WG_DCLOCK_NUM_0, VAPP_HS_IMG_WG_DCLOCK_NUM_9);
    m_dclock->setNumberBackground(vrt_sys_res_image_lock(0));
    m_dclock->setTimeSeparator(VAPP_HS_IMG_WG_DCLOCK_COLON, VAPP_HS_IMG_WG_DCLOCK_COLON);
    m_dclock->setAmAndPm(
        vrt_sys_res_image_lock(0), 
        vrt_sys_res_image_lock(0), 
        vrt_sys_res_image_lock(0), 
        vrt_sys_res_image_lock(0));

	m_dclock->setGap(1, 1, 1);
    m_dclock->startClock();
}

void VappWidgetDigtialClock::createDate(VfxDateTime dt)
{
	VFX_OBJ_CREATE (m_date, VcpDigitalTextClock, this);  
	m_date->setFormatFlags(VFX_DATE_TIME_DATE_YEAR|
							VFX_DATE_TIME_DATE_MONTH|
							VFX_DATE_TIME_DATE_DAY); 
	m_date->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(DATE_FONT_SIZE)));
	m_date->setTextColor(VFX_COLOR_WHITE);
	//m_date->setFont(dateFont);
	m_date->setPos(VfxPoint(D_CLOCK_DATE_X, D_CLOCK_DATE_Y));
	m_date->setBounds(VfxRect(0, 0, D_CLOCK_DATE_W, D_CLOCK_DATE_H));
	m_date->setTime(dt);
	m_date->startClock();
}
void VappWidgetDigtialClock::onCreateView()
{
    VappWidget::onCreateView();

    setBounds(VfxRect(0, 0, D_CLOCK_WIDTH, D_CLOCK_HEIGHT));

	// Background
	VFX_OBJ_CREATE(m_bg, VfxImageFrame, this);
	m_bg->setPos(VfxPoint(0,0));
	m_bg->setBounds(VfxRect(0, 0, D_CLOCK_WIDTH, D_CLOCK_HEIGHT));
	m_bg->setResId(VAPP_HS_IMG_WG_DCLOCK_BG);

	// Get real time
	VfxS16 error;
	VfxU16 city_index;
	applib_time_struct current_time;
	ReadValue(NVRAM_WIDGET_DCLOCK_CITY_INDEX, &city_index, DS_SHORT, &error);
	g_widget_dclock_city_index = mmi_wc_get_home_index();
	applib_dt_get_rtc_time(&current_time);
	m_dt.setDateTime(&current_time);

	if(city_index != 0XFFFF)
	{
		VfxFloat homeTz, newTz;
		VappClockDataControl dataInter;

		VfxU16 home_index = mmi_wc_get_home_index();

		homeTz = mmi_wc_get_time_zone(home_index);
		newTz = mmi_wc_get_time_zone(city_index);
		dataInter.getTime(homeTz, newTz, m_dt, city_index);
		g_widget_dclock_city_index = city_index;
	}
	// Digitial clock
	createDclock(m_dt);

	// Digitial text clock
	createDate(m_dt);

	//city
	VfxWString city_str;

	city_str.loadFromRes(mmi_wc_get_city_strid(g_widget_dclock_city_index));
	VFX_OBJ_CREATE(m_city, VfxTextFrame, this);
	m_city->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	m_city->setPos(VfxPoint(D_CLOCK_CITY_X, D_CLOCK_CITY_Y));
	m_city->setString(city_str);
	m_city->setBounds(VfxRect(0, 0, D_CLOCK_CITY_W, D_CLOCK_CITY_H));
	m_city->setColor(VFX_COLOR_WHITE);
	m_city->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(CITY_FONT_SIZE)));
	m_city->setAutoResized(VFX_FALSE);
	m_city->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);

	// AM, PM
	VfxWString am_str;
	if(m_dt.getHour() >=12)
		am_str.loadFromMem((const VfxWChar*)L"PM");
	else
		am_str.loadFromMem((const VfxWChar*)L"AM");
	VFX_OBJ_CREATE(m_am_pm, VfxTextFrame, this);
	m_am_pm->setPos(VfxPoint(D_CLOCK_AM_PM_X, D_CLOCK_AM_PM_Y));
	m_am_pm->setString(am_str);
	m_am_pm->setBounds(VfxRect(0, 0, D_CLOCK_AM_PM_W, D_CLOCK_AM_PM_H));
	m_am_pm->setColor(VFX_COLOR_WHITE);
	m_am_pm->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(APM_FONT_SIZE)));
	m_am_pm->setAutoResized(VFX_FALSE);
	m_am_pm->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);

	if(PhnsetGetTimeFormat()) // return 0 -- > 12 hours
	{
		m_am_pm->setHidden(VFX_TRUE);
		m_dclock->setPos(VfxPoint(D_CLOCK_24_CENTER_X, D_CLOCK_CENTER_Y));
	}
	//slot to system change
	VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappWidgetDigtialClock::onSystemTimeChanged);

}

void VappWidgetDigtialClock::updateView(VfxU16 city_index)
{
	// city text
	VfxWString city_str;
	city_str.loadFromRes(mmi_wc_get_city_strid(city_index));
	m_city->setString(city_str);

	// update time
	VfxFloat homeTz, newTz;
	VappClockDataControl dataInter;

	VfxU16 home_index = mmi_wc_get_home_index();

	homeTz = mmi_wc_get_time_zone(home_index);
	newTz = mmi_wc_get_time_zone(g_widget_dclock_city_index);
	dataInter.getTime(homeTz, newTz, m_dt, g_widget_dclock_city_index);

	// Digitial clock
	VFX_OBJ_CLOSE(m_dclock);
	createDclock(m_dt);

	// Update date;
	// Digitial text clock
	VFX_OBJ_CLOSE(m_date);
	createDate(m_dt);

	// AM, PM
	VfxWString am_str;
	if(m_dt.getHour() >=12)
		am_str.loadFromMem((const VfxWChar*)L"PM");
	else
		am_str.loadFromMem((const VfxWChar*)L"AM");
	m_am_pm->setString(am_str);

}
void VappWidgetDigtialClock::onTap(
        const VfxPoint &pos
    )
{
	launchWorldClock();
}
void VappWidgetDigtialClock::onReleaseView()
{
    VFX_OBJ_CLOSE(m_dclock);
	VFX_OBJ_CLOSE(m_bg);
	VFX_OBJ_CLOSE(m_city);
	VFX_OBJ_CLOSE(m_date);
	VFX_OBJ_CLOSE(m_am_pm);
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.disconnect(this, &VappWidgetDigtialClock::onSystemTimeChanged);

    VappWidget::onReleaseView();
}
void VappWidgetDigtialClock::onSerializeView(VfxArchive *ar)
{
	ar->writeU16(g_widget_dclock_city_index);
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.disconnect(this, &VappWidgetDigtialClock::onSystemTimeChanged);

}
void VappWidgetDigtialClock::onRestoreView(VfxArchive *ar)
{
	VfxDateTime dt;
	VfxFloat homeTz, newTz;
	VappClockDataControl dataInter;
	VfxU16 home_index = mmi_wc_get_home_index();

	homeTz = mmi_wc_get_time_zone(home_index);
	newTz = mmi_wc_get_time_zone(g_widget_dclock_city_index);
	dataInter.getTime(homeTz, newTz, dt, g_widget_dclock_city_index);
	// AM, PM
	VfxWString am_str;
	if(dt.getHour() >=12)
		am_str.loadFromMem((const VfxWChar*)L"PM");
	else
		am_str.loadFromMem((const VfxWChar*)L"AM");
	m_am_pm->setString(am_str);

	VfxS16 error;
	if(m_launch)
	{
		if(ar->readU16() != g_widget_dclock_city_index)
	    {
		    updateView(g_widget_dclock_city_index);
		    WriteValue(NVRAM_WIDGET_DCLOCK_CITY_INDEX, &g_widget_dclock_city_index, DS_SHORT, &error);
	    }
	}
	else
	{
		if((g_widget_dclock_city_index == 0) && home_index)
			g_widget_dclock_city_index = home_index;
		updateView(g_widget_dclock_city_index);
	}
	m_launch = VFX_FALSE;
	if(PhnsetGetTimeFormat()) // return 0 -- > 12 hours
	{
		m_am_pm->setHidden(VFX_TRUE);
		m_dclock->setPos(VfxPoint(D_CLOCK_24_CENTER_X, D_CLOCK_CENTER_Y));
	}
	else
	{
		m_am_pm->setHidden(VFX_FALSE);
		m_dclock->setPos(VfxPoint(D_CLOCK_12_CENTER_X, D_CLOCK_CENTER_Y));
	}
	VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappWidgetDigtialClock::onSystemTimeChanged);
}	

void VappWidgetDigtialClock::onSystemTimeChanged(VfxU32 flag)
{
	if (flag & VDAT_SYSTIME_CHANGED_HOUR)
	{
		VfxFloat homeTz, newTz;
		VappClockDataControl dataInter;
		VfxU16 home_index = mmi_wc_get_home_index();

		homeTz = mmi_wc_get_time_zone(home_index);
		newTz = mmi_wc_get_time_zone(g_widget_dclock_city_index);
		dataInter.getTime(homeTz, newTz, m_dt, g_widget_dclock_city_index);
		// AM, PM
		VfxWString am_str;
		if(m_dt.getHour() >=12)
			am_str.loadFromMem((const VfxWChar*)L"PM");
		else
			am_str.loadFromMem((const VfxWChar*)L"AM");
		m_am_pm->setString(am_str);
	}
}

VfxPoint VappWidgetDigtialClock::onGetEditButtonOffset()

{
	return VfxPoint(BUTTON_X, BUTTON_Y); 
}
#endif /*__MMI_VUI_WIDGET_DCLOCK__ */
