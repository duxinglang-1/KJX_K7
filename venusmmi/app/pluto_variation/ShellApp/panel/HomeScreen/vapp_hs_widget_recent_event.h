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
 *  vapp_hs_widget_recent_event.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: recent event
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

#ifndef __VAPP_HS_WIDGET_RECENT_EVENT_H__
#define __VAPP_HS_WIDGET_RECENT_EVENT_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_RECENT_EVENT__

/***************************************************************************** 
 * Include
 *****************************************************************************/
 
#include "vfx_uc_include.h"
#include "vdat_include.h"
#include "vapp_hs_res.h"
#include "vapp_hs_widget_base.h"
#include "vcp_scrollable.h"
#include "vcp_button.h"


/***************************************************************************** 
 * Home screen widget: recent event item
 *****************************************************************************/

class VappHsWidgetRecentEventItem : public VfxControl
{
// Declaration
public:
    enum
    {
        // Width of the menu item.
        WIDTH   = 166,

        // Height of the menu item.
        HEIGHT  = 41
    };
    
// Constructor / Destructor
public:
    // This function is the constructor for a recent event menu item. If 
    // "needSeparateLine" is VFX_TRUE, it draws a separated line above the menu
    // item.
    VappHsWidgetRecentEventItem(
        VfxBool needSeparateLine    // [IN] If separated line is needed
    );

// Method
public:
    // This function sets the subject of the menu item.
    void setSubject(
        const VfxWString &str   // [IN] Subject string
    );

    // This function sets the hint of the menu item.
    void setHint(
        const VfxWString &str   // [IN] Hint string
    );

    // This function sets the icon of the menu item.
    void setIcon(
        VfxS32 iconId           // [IN] Icon ID
    );

    // This function sets the bold type of the font.
    void setBold(
        VfxBool isBold          // [IN] Bold font or not
    );

// Signal
public:
    // This signal is emitted when this menu item is clicked.
    VfxSignal1 <VappHsWidgetRecentEventItem *> m_signalClick;

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onDraw(VfxDrawContext &dc);

// Declaration
private:
    enum
    {
        // X-axis position of the subject and the hint string
        TEXT_X          = 34,

        // Y-axis gap between subject and the hint string
        TEXT_GAP_Y      = 3,

        // X-axis position of the icon
        ICON_X          = 3,

        // Y-axis position of the icon
        ICON_Y          = 8,

        // X-axis position of the button
        BUTTON_X        = 145,

        // X-axis gap between button and the right margin of the menu item
        BUTTON_GAP_X    = 2,

        // Max. width of the subject
        TEXT_WIDTH      = WIDTH - TEXT_X,
        
        // Max. width of the hint. Skip "More" button for Arabic.
        HINT_WIDTH      = BUTTON_X - TEXT_X - BUTTON_GAP_X
    };

// Variable
private:
    // Subject frame
    VfxTextFrame           *m_subject;

    // Hint frame
    VfxTextFrame           *m_hint;

    // Button component
    VcpButtonInternal      *m_button;

    // Button UP image for button component
    VfxImageFrame          *m_buttonImgUp;

    // Button DOWN image for button component
    VfxImageFrame          *m_buttonImgDown;

    // Icon ID of the menu item
    VfxS32                  m_iconId;

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

    // This function aligens the UI component of the menu item.
    void alignment();
};


/***************************************************************************** 
 * Home screen widget: recent event
 *****************************************************************************/

class VappHsWidgetRecentEvent : public VappHsWidget
{
    VAPP_HS_WIDGET_CREATE(VappHsWidgetRecentEvent);

// Constructor / Destructor    
public:
    // Default constructor.
    VappHsWidgetRecentEvent();

// Override
public:
    virtual VfxS32 getIcon();
    virtual void onCreateView();
    virtual void onReleaseView();

// Declaration
private:
    enum
    {
        // Max. number of recent events in this widget
        MAX_EVENT   = 6,

        // X-axis position of the scrollable body
        BODY_POS_X  = 8,

        // Y-axis position of the scrollable body
        BODY_POS_Y  = 18,

        // Width of the scrollable body
        BODY_WIDTH  = 166,

        // Height of the scrollable body
        BODY_HEIGHT = 97
    };

// Variable
private:
    // scrollable body
    VcpScrollable                   *m_body;

    // Help text when events are not available, e.g., the mobile is in the
    // flight mode. In this case, show a "Not available" help text.
    VfxTextFrame                    *m_helpText;

    // Number of the recent events in this widget
    VfxS32                           m_numEvent;

    // Recent event array
    VappHsWidgetRecentEventItem     *m_event[MAX_EVENT];

// Implementation
private:
    // This function is the event hander when the events are changed.
    // RETURNS: event handler result
    void onEventChanged(
        VdatRecentEvent *recentEventSrv // [IN] recent event service instance
    );

    // This function is the event handler when a menu item is selected.
    // RETURNS: event handler result
    void onSelectEvent(
        VappHsWidgetRecentEventItem *event  // [IN] The selected menu item
    );

    // This function is the event handler when the mobile's time is changed. In
    // this situation, we might need to change the hint string of the menu item.
    // RETURNS: event handler result
    void onTimeChanged(
        VfxU32 flag     // [IN] Bit-OR flag indicating the change
    );

    // This function aligns the UI components in this widget.
    void alignment();

    // This function updates the help text of this widget.
    void updateHelpText();
};

#endif /* __MMI_VUI_HOMESCREEN_RECENT_EVENT__ */
#endif /* __VAPP_HS_WIDGET_RECENT_EVENT_H__ */

