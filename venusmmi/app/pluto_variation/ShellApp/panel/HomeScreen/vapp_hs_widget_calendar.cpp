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
 *  vapp_hs_widget_calendar.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: calendar
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_CALENDAR__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_hs_widget_calendar.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "vfx_datatype.h"
#include "vdat_systime.h"
#include "vfx_date_time.h"
#include "mmi_rp_app_venus_homescreen_wg_calendar_def.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_basic_type.h"
#include "vfx_primitive_frame.h"
#include "vfx_signal.h"
#include "vcp_idle_calendar.h"
#include "vcp_button.h"

extern "C"
{
#ifdef __MMI_TOUCH_SCREEN__
#include "gui_typedef.h"
#endif
#include "gui_effect_oem.h"
#include "CalendarGprot.h"
#include "GlobalResDef.h"
}

extern "C" void mmi_clndr_monthly_prev_on_idle(void);
extern "C" void mmi_clndr_monthly_next_on_idle(void);
extern "C" void wgui_calendar_idle_update(void);
extern "C" MMI_BOOL mmi_clndr_is_monthly_prev_move_enable(void);
extern "C" MMI_BOOL mmi_clndr_is_monthly_next_move_enable(void);

#ifdef __MMI_TOUCH_SCREEN__
extern "C" void wgui_calendar_switch_prev(gui_calendar_time_switch_enum type);
extern "C" void wgui_calendar_switch_next(gui_calendar_time_switch_enum type);
#endif /* __MMI_TOUCH_SCREEN__ */

/***************************************************************************** 
 * Home screen widget: calendar
 *****************************************************************************/
VappHsWidgetCalendar::VappHsWidgetCalendar() :
    m_calendar(NULL),
    m_prevButton(NULL),
    m_nextButton(NULL)
{
    for (VfxS32 i = 0 ; i < 4 ; i++)
    {
        m_imageIconDigits[i] = NULL;
    }
}


void VappHsWidgetCalendar::timeUpdate(VfxU32 flag)
{
    if (flag & VDAT_SYSTIME_CHANGED_YEAR)
    {
        VfxDateTime date;

        date.setCurrentTime();

        VfxU32 year = date.getYear();

        for (VfxS32 i = 3 ; i >= 0 ; i--)
        {
            m_imageIconDigits[i]->setResId(VAPP_HS_IMG_WG_ICON_CALENDAR_D0 + (year % 10));
            year /= 10;
        }
    }
}


VfxBool VappHsWidgetCalendar::onCreateIconView()
{
    // background image
    m_controlIcon->setImgContent(VfxImageSrc(VAPP_HS_IMG_WG_ICON_CALENDAR_BG));
    m_controlIcon->setBounds(VfxRect(VFX_POINT_ZERO, m_controlIcon->getImgContent().getSize()));

    VfxS32 i;
    for (i = 0 ; i < 4 ; i++)
    {
        VFX_OBJ_CREATE(m_imageIconDigits[i], VfxImageFrame, m_controlIcon);
    }
    timeUpdate(VDAT_SYSTIME_CHANGED_YEAR);

    VfxPoint pos(ICON_TEXT_X, ICON_TEXT_Y);
    for (i = 0 ; i < 4 ; i++)
    {
        m_imageIconDigits[i]->setPos(pos);
        pos.x += ICON_TEXT_W;
    }

    // connect signal to refresh the time string
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappHsWidgetCalendar::timeUpdate);

    return VFX_TRUE;    
}


void VappHsWidgetCalendar::onReleaseIconView()
{
    m_controlIcon->setImgContent(VFX_IMAGE_SRC_NULL);

    // Disconnect system time signal
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.disconnect(this, &VappHsWidgetCalendar::timeUpdate);

    for (VfxS32 i = 0 ; i < 4 ; i++)
    {
        VFX_OBJ_CLOSE(m_imageIconDigits[i]);
    }
}


void VappHsWidgetCalendar::onCreateView()
{
	mmi_clndr_create_calendar_on_idle();
    VFX_OBJ_CREATE(m_calendar, VcpIdleCalendar, this);
#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    m_calendar->setIsOpaque(VFX_TRUE);
    setIsOpaque(VFX_TRUE);
#endif /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */
    setIsCached(VFX_FALSE);
    m_calendar->m_signalUpdate.connect(this, &VappHsWidgetCalendar::onCalendarUpdate);

    VfxRect bounds = m_calendar->getBounds();
    setBounds(bounds);

    // Create prev button
    VFX_OBJ_CREATE(m_prevButton, VcpButtonInternal, this);
    m_prevButton->setPos(VfxPoint(0, 0));
    m_prevButton->m_eventUp.connect(this, &VappHsWidgetCalendar::onPrevButtonClick);

    // Add prev button down image
    m_prevButton->setBackgroundDown(VfxImageSrc(VAPP_HS_IMG_WG_ICON_CALENDAR_PREV_BUTTON_DOWN));

    // Add prev button up image
    m_prevButton->setBackgroundUp(VfxImageSrc(VAPP_HS_IMG_WG_ICON_CALENDAR_PREV_BUTTON_UP));
    if (mmi_clndr_is_monthly_prev_move_enable() == MMI_FALSE)
    {
        m_prevButton->setHidden(VFX_TRUE);
    }

    // Create next button
    VFX_OBJ_CREATE(m_nextButton, VcpButtonInternal, this);
    m_nextButton->setAnchor(VfxFPoint(1.0f, 0.0f));
    m_nextButton->setPos(VfxPoint(bounds.getWidth(), 0));
    m_nextButton->m_eventUp.connect(this, &VappHsWidgetCalendar::onNextButtonClick);
    if (mmi_clndr_is_monthly_next_move_enable() == MMI_FALSE)
    {
        m_nextButton->setHidden(VFX_TRUE);
    }

    // Add next button down image
    m_nextButton->setBackgroundDown(VfxImageSrc(VAPP_HS_IMG_WG_ICON_CALENDAR_NEXT_BUTTON_DOWN));
    m_nextButton->setBackgroundUp(VfxImageSrc(VAPP_HS_IMG_WG_ICON_CALENDAR_NEXT_BUTTON_UP));
}


void VappHsWidgetCalendar::onReleaseView()
{
	mmi_clndr_exit_set_calendar_on_idle();
    VFX_OBJ_CLOSE(m_prevButton);
    VFX_OBJ_CLOSE(m_nextButton);
    VFX_OBJ_CLOSE(m_calendar);
}


void VappHsWidgetCalendar::onPrevButtonClick()
{
    mmi_clndr_monthly_prev_on_idle();
    wgui_calendar_switch_prev(GUI_CALENDAR_TIME_SWITCH_MONTH);
    wgui_calendar_idle_update();

    if (mmi_clndr_is_monthly_prev_move_enable() == MMI_FALSE)
    {
        m_prevButton->setHidden(VFX_TRUE);
    }
    if (mmi_clndr_is_monthly_next_move_enable() == MMI_TRUE)
    {
        m_nextButton->setHidden(VFX_FALSE);
    }
}


void VappHsWidgetCalendar::onNextButtonClick()
{
    mmi_clndr_monthly_next_on_idle();
    wgui_calendar_switch_next(GUI_CALENDAR_TIME_SWITCH_MONTH);
    wgui_calendar_idle_update();

    if (mmi_clndr_is_monthly_prev_move_enable() == MMI_TRUE)
    {
        m_prevButton->setHidden(VFX_FALSE);
    }
    if (mmi_clndr_is_monthly_next_move_enable() == MMI_FALSE)
    {
        m_nextButton->setHidden(VFX_TRUE);
    }
}


void VappHsWidgetCalendar::onDirectLaunch()
{
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_VUI_ENGINE__)
    gui_screen_switch_effect_v2p_setup_widget();
#endif

    mmi_clndr_launch(GRP_ID_ROOT, MMI_CAL_LAUNCH_TYPE_AUTO, NULL);
}


void VappHsWidgetCalendar::onCalendarUpdate()
{
    VfxBool isHidden = VFX_TRUE;

    isHidden = (mmi_clndr_is_monthly_prev_move_enable()) ? (VFX_FALSE) : (VFX_TRUE);
    m_prevButton->setHidden(isHidden);

    isHidden = (mmi_clndr_is_monthly_next_move_enable()) ? (VFX_FALSE) : (VFX_TRUE);
    m_nextButton->setHidden(isHidden);
}

#endif /* __MMI_VUI_HOMESCREEN_CALENDAR__ */

