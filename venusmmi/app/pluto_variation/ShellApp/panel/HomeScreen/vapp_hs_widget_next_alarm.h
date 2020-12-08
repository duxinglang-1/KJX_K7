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
 *  vapp_hs_widget_next_alarm.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_HS_WIDGET_NEXT_ALARM_H__
#define __VAPP_HS_WIDGET_NEXT_ALARM_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_NEXT_ALARM__

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_clock.h"
#include "vapp_hs_widget_base.h"
#include "vfx_frame.h"
#include "vfx_date_time.h"
#include "vfx_draw_context.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vapp_hs_widget_cfg.h"
#include "vapp_hs_def.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_text_frame.h"


/*****************************************************************************
 * Digital image clock on the "Next Alarm" widget.
 *****************************************************************************/

class VappHsWidgetNextAlarmClock : public VfxFrame
{
// Constructor / Destructor
public:
    VappHsWidgetNextAlarmClock(VfxDateTime &time);

// Method
public:

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onDraw(VfxDrawContext &dc);

// Declaration
private:
    typedef enum
    {
        TIME_12_AM,
        TIME_12_PM,
        TIME_24
    } TimeType;

    enum
    {
        TOTAL_NUM   = 10,
        WIDTH       = 110,
        HEIGHT      = 26,
        HOUR2_X     = 20,
        COLON_X     = 40,
        MIN1_X      = 52,
        MIN2_X      = 72,
        AM_PM_X     = 94,
        AM_PM_Y     = 16,
    };

// Variable
private:
    VfxDateTime  m_time;
    VfxU8       *m_num[TOTAL_NUM];
    VfxU8       *m_colon;
    VfxU8       *m_am;
    VfxU8       *m_pm;

// Implementation
private:
    // This function gets the digit of the hour and minute.
    void getTime(
        VfxS32 &hour1,      // [OUT] 1st digit of the hour
        VfxS32 &hour2,      // [OUT] 2nd digit of the hour   
        VfxS32 &min1,       // [OUT] 1st digit of the minute
        VfxS32 &min2,       // [OUT] 2nd digit of the minute
        TimeType &type      // [OUT] A.M. or P.M.
    );
};


/*****************************************************************************
 * Home screen widget: next alarm
 *****************************************************************************/

class VappHsWidgetNextAlarm : public VappHsWidget
{
    VAPP_HS_WIDGET_CREATE(VappHsWidgetNextAlarm);

// Constructor / Destructor
public:
    // Default constructor
    VappHsWidgetNextAlarm();

// Override
public:
    virtual VfxU16 getIcon();
    virtual VfxU16 getName();
    virtual void onCreateView();
    virtual void onReleaseView();
    virtual void onDirectLaunch();

// Declaration
private:
    enum
    {
        // Y position of the title text.
        TITLE_Y             = 12,

        // X position of the digital image clock.
        TIME_X              = 22,

        // Y position of the digital image clock.
        TIME_Y              = 26,

        // Y position of the date text.
        DATE_Y              = 65,

        // Y position of the none text.
        NONE_Y              = 40,

        // Max string buffer size in UCS2 encoded, including '\0'.
        MAX_STR_BUF_SIZE    = 16
    };

// Variable
private:
    // Title "Next alarm"
    VfxTextFrame                *m_title;

    // Digital image clock of the next alarm
    VappHsWidgetNextAlarmClock  *m_clock;

    // Date of the next alarm
    VfxTextFrame                *m_date;

    // "No alarm" text when there is no next alarm.
    VfxTextFrame                *m_text;

// Implementation
private:
    // This function gets the next alarm information.
    VfxBool getNextAlarm(
        VfxDateTime &time       // [OUT] Next alarm's time
    );

    // This function updates the next alarm time.
    void updateTime(
        VfxDateTime &time       // [IN] Next alarm's time
    );

    // This function updates the "None" string on the widget.
    void updateNone();

    // This function launches the alarm application.
    void launch(
        void *user_data         // [IN] User data
    );
};

#endif /* __MMI_VUI_HOMESCREEN_NEXT_ALARM__ */
#endif /* __VAPP_HS_WIDGET_NEXT_ALARM_H__ */

