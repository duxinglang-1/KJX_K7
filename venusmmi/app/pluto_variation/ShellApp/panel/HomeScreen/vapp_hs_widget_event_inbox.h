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
 *  vapp_hs_widget_event_inbox.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: event inbox
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_HS_WIDGET_EVENT_INBOX_H__
#define __VAPP_HS_WIDGET_EVENT_INBOX_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_EVENT_INBOX__

/***************************************************************************** 
 * Include
 *****************************************************************************/
 
#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vfx_cpp_base.h"
#include "vapp_hs_widget_cfg.h"
#include "vapp_hs_def.h"
#include "vfx_sys_memory.h"
#include "vfx_text_frame.h"
#include "vcp_button.h"
#include "vfx_primitive_frame.h"
#include "vapp_hs_widget_base.h"


/***************************************************************************** 
 * Home screen widget: event inbox
 *****************************************************************************/

class VappHsWidgetEventInbox : public VappHsWidget
{
    VAPP_HS_WIDGET_CREATE(VappHsWidgetEventInbox);

// Constructor / Destructor    
public:
    // Default constructor.
    VappHsWidgetEventInbox();

// Override
public:
    virtual VfxU16 getIcon();
    virtual VfxU16 getName();
    virtual void onCreateView();
    virtual void onReleaseView();

public:
    // This function draws the event counter.
    void updateCounter();

public:
    // This function is the event handler.
    // RETURNS: mmi_ret
    static mmi_ret onEventCallback(
        mmi_event_struct *event     // [IN] Event structure
    );

// Declaration
private:
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        Y_TITLE             = 17,
        X_CALL_BUTTON       = 5,
        X_SMS_BUTTON        = 80,
        X_MMS_BUTTON        = 155,
        Y_ALL_BUTTON        = 35,
        X_GAP_ICON          = 7,
        X_GAP_TEXT          = 7,
    #else /* __MMI_MAINLCD_320X480__ */
        Y_TITLE             = 15,
        X_CALL_BUTTON       = 3,
        X_SMS_BUTTON        = 58,
        X_MMS_BUTTON        = 112,
        Y_ALL_BUTTON        = 28,
        X_GAP_ICON          = 5,
        X_GAP_TEXT          = 5,
    #endif /* __MMI_MAINLCD_320X480__ */
    
        MAX_STR_BUF_SIZE    = 16
    };

    // This enum defines the event type.
    enum evt_type
    {
        EVT_CALL,       // Missed call event
        EVT_SMS,        // SMS event
        EVT_MMS,        // MMS event
        EVT_TOTAL       // Total event types
    };

// Variable
private:
    // Title.
    VfxTextFrame                    *m_title;

    // Button of each event type.
    VcpButtonInternal               *m_button[EVT_TOTAL];

    // Text of each button.
    VfxTextFrame                    *m_text[EVT_TOTAL];

    // Image frame of each button.
    VfxImageFrame                   *m_icon[EVT_TOTAL];

    // Image when the button is pressed down.
    VfxImageFrame                   *m_imgDown[EVT_TOTAL];

// Implementation
private:
    // This function creates the button.
    // RETURNS: button component.
    VcpButtonInternal *createButton(
        evt_type type,      // [IN] Event type
        VfxS32 imgIcon,     // [IN] Button image
        VfxS32 imgDown      // [IN] Button down image
    );

    // This function launches the application associated with the event.
    void launch(
        void *data          // [IN] Event type
    );
    
    // This function launches the inbox of the missed call.
    void launchCallInbox();

    // This function launches the inbox of the unread SMS.
    void launchSmsInbox();

    // This function launches the inbox of the unread MMS.
    void launchMmsInbox();

    // This function gets the number of the missed call.
    VfxS32 getMissedCallNum();

    // This function gets the number of the unread SMS.
    void getSmsNum();

    // This function gets the number of the unread MMS.
    void getMmsNum();

    // Register callback manager's events.
    void registerEvent();

    // Deregister callback manager's events.
    void deregisterEvent();
};

#endif /* __MMI_VUI_HOMESCREEN_EVENT_INBOX__ */
#endif /* __VAPP_HS_WIDGET_EVENT_INBOX_H__ */

