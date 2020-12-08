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
 *  vapp_hs_widget_alarm.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: alarm
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_HS_WIDGET_ALARM_H__
#define __VAPP_HS_WIDGET_ALARM_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_ALARM__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

#include "custom_mmi_default_value.h"   // NUM_OF_ALM

#ifdef __cplusplus
}
#endif

#include "vfx_uc_include.h"
#include "vapp_hs_widget_base.h"
#include "vcp_scrollable.h"
#include "vcp_button.h"


/***************************************************************************** 
 * Home screen widget: alarm item
 *****************************************************************************/

class VappHsWidgetAlarmItem : public VfxControl
{
// Declaration
public:
    enum
    {
        // Width of the menu item
        WIDTH       = 108,

        // Height of the menu item
        HEIGHT      = 23
    };

// Constructor / Destructor
public:
    // This function is the constructor for a alarm menu item. If 
    // "needSeparateLine" is VFX_TRUE, it draws a separated line above the menu
    // item.
    VappHsWidgetAlarmItem(
        VfxBool needSeparateLine    // [IN] If separated line is needed
    );

// Method
public:
    // This function sets the time string of the alarm.
    void setTimeString(
        VfxU8 *str                  // [IN] Time string
    );

    // This function sets the state of the alarm for the toggle box.
    void setStatus(
        VfxBool isEnable            // [IN] If the alarm is on or off
    );

// Signal
public:
    // This signal is emitted if the user toggles the alarm.
    VfxSignal1 <VappHsWidgetAlarmItem *> m_signalToggle;

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onDraw(VfxDrawContext &dc);

// Declaration
private:
    enum
    {
        // X-axis position of the button
        BUTTON_X   = 4,

        // X-axis position of the time string
        TEXT_X     = 22,

        // Max. width of the time string
        TEXT_WIDTH = WIDTH - TEXT_X
    };

// Variable
private: 
    // Time string frame
    VfxTextFrame           *m_timeString;
    
    // Button component
    VcpButtonInternal      *m_button;
    
    // Button UP image for the button component
    VfxImageFrame          *m_buttonImgUp;

    // Button DOWN image for the button component
    VfxImageFrame          *m_buttonImgDown;

    // If this menu item needs a separated line in the above of itself
    VfxBool                 m_needSeparateLine;

    // Image data of the separated line
    vrt_u8                 *m_lineImgData;

    // Image size of the separated line
    vrt_size_struct         m_lineImgSize;

// Implementation
private:
    // This function is the event handler when the button of this menu item is
    // clicked. It will emit the signal to notify the subscriber.
    // RETURNS: event handler result
    void onClick();

    // This function aligns the UI component of this menu item.
    void alignment();
};


/***************************************************************************** 
 * Home screen widget: alarm
 *****************************************************************************/

class VappHsWidgetAlarm : public VappHsWidget
{
    VAPP_HS_WIDGET_CREATE(VappHsWidgetAlarm);

// Constructor / Destructor
public:
    // Default constructor
    VappHsWidgetAlarm();

// Override
public:
    virtual VfxS32 getIcon();
    virtual void onCreateView();
    virtual void onReleaseView();

// Declaration
private:
    enum 
    {
        // Max. string length for the time string
        STR_LEN     = 32,

        // X-axis position of the scrollable body 
        MAIN_POS_X  = 9,

        // Y-axis position of the scrollable body
        MAIN_POS_Y  = 20,

        // Width of the scrollable body
        MAIN_WIDTH  = 108,

        // Height of the scrollable body
        MAIN_HEIGHT = 60
    };

// Variable
private:
    // Scrollable body
    VcpScrollable          *m_body;

    // Alarm array
    VappHsWidgetAlarmItem  *m_alarm[NUM_OF_ALM];

// Implementation
private:
    // This function is the event handler when the user toggles an alarm.
    // RETURNS: event handler result
    void onToggleAlarm(
        VappHsWidgetAlarmItem *alarm    // [IN] Alarm menu item
    );
};

#endif /* __MMI_VUI_HOMESCREEN_ALARM__ */
#endif /* __VAPP_HS_WIDGET_ALARM_H__ */

