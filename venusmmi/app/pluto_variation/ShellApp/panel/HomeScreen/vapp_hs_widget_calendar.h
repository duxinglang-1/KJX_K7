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
 *  vapp_hs_widget_calendar.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_HS_WIDGET_CALENDAR_H__
#define __VAPP_HS_WIDGET_CALENDAR_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_CALENDAR__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_hs_widget_base.h"
#include "vcp_idle_calendar.h"

#include "vfx_cpp_base.h"
#include "vapp_hs_widget_cfg.h"
#include "vapp_hs_def.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_datatype.h"
#include "mmi_rp_app_venus_homescreen_wg_calendar_def.h"
#include "vfx_primitive_frame.h"
#include "vcp_button.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * Home screen widget: calendar
 *****************************************************************************/
class VappHsWidgetCalendar : public VappHsWidget
{
    VAPP_HS_WIDGET_CREATE(VappHsWidgetCalendar);

// Declaration
private:
    // widget bar icon: year digit position and size
    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        ICON_TEXT_X = 13,   // x of year digit
        ICON_TEXT_Y = 5,    // y of year digit
        ICON_TEXT_W = 8     // width of year digit
#else
        ICON_TEXT_X = 11,   // x of year digit
        ICON_TEXT_Y = 5,    // y of year digit
        ICON_TEXT_W = 7     // width of year digit
#endif
    };

// Constructor / Destructor
public:
    // Default constructor
    VappHsWidgetCalendar();

// Method
public:
    // get the image ID of widget bar icon
    // RETURNS: image ID
    virtual VfxU16 getIcon() { return VAPP_HS_IMG_WG_ICON_CALENDAR; }

    // Get string resource ID for the name of this widget
    // RETURNS: string ID
    virtual VfxU16 getName() { return VAPP_HS_STR_WG_CALENDAR; }

    // create widget bar icon frame, m_controlIcon
    virtual VfxBool onCreateIconView();

    // release widget bar icon frame
    virtual void onReleaseIconView();

    // create the whole widget content
    virtual void onCreateView();

    // release the whole widget content
    virtual void onReleaseView();


// Override
protected:
    // Launch setting
    virtual void onDirectLaunch();

// Implementation
private:
    // time update
    void timeUpdate(VfxU32 flag);

    // This function is the event handler when the prev button is
    // clicked. It will emit the signal to change calendar to prev month/week.
    void onPrevButtonClick();

    // This function is the event handler when the prev button is
    // clicked. It will emit the signal to change calendar to next month/week.
    void onNextButtonClick();

// Variables
private:
    // calendar
    VcpIdleCalendar *m_calendar;

    // widget icon digits
    VfxImageFrame   *m_imageIconDigits[4];

    // widget prev button
    VcpButtonInternal       *m_prevButton;

    // widget next button
    VcpButtonInternal       *m_nextButton;

    // check next / prev button while calendar is updated
    void onCalendarUpdate();
};

#endif /* __MMI_VUI_HOMESCREEN_CALENDAR__ */
#endif /* __VAPP_HS_WIDGET_CALENDAR_H__ */

