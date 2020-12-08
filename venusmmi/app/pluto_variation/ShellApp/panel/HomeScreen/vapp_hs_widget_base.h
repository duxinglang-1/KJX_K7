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
 *  vapp_hs_widget_base.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Base widget class, all home screen widgets should inherit this
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_HS_WIDGET_BASE_H__
#define __VAPP_HS_WIDGET_BASE_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_object.h"
#include "vfx_control.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"
#include "vfx_timer.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_HS_WIDGET_CREATE(_className)                               \
    public:                                                             \
        static inline void *createWidget(void *parentObj)               \
        {                                                               \
            _className *widget;                                         \
            VFX_OBJ_CREATE(widget, _className, (VfxObject *)parentObj); \
            return widget;                                              \
        }                                                               \
                                                                        \
        inline VfxS32 getType()                                         \
        {                                                               \
            return VAPP_HS_WIDGET_TYPE_DEVICE;                          \
        }                                                               \
                                                                        \
        inline VfxS32 getId()                                           \
        {                                                               \
            return VAPP_HS_WIDGET_ENUM_##_className;                    \
        }


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
class VappHsDesktop;

/***************************************************************************** 
 * Home screen UI componet: base widget class
 *****************************************************************************/
class VappHsWidget : public VfxControl
{
    VFX_DECLARE_CLASS(VappHsWidget);

public:
    // Request id
    enum RequestId
    {
        REQ_ID_CHANGE_CUBE_TO_SCROLLABLE,
        REQ_ID_CHANGE_CUBE_TO_UNSCROLLABLE,
        REQ_ID_TOTAL
    };
    
// Declaration
protected:
    // State enum
    enum WidgetStateEnum
    {
        STATE_INIT,     // Init state
        STATE_CREATE    // Create state
    };

private:
    // constant
    enum
    {
        START_DRAG_TIME     = 450   // time to start dragging
    };

// Signal
public:
    // Drag signal
    VfxSignal2 <VappHsWidget *, VfxPenEvent &> m_signalDrag;

    // Move signal
    VfxSignal2 <VappHsWidget *, VfxPenEvent &> m_signalMove;

    // Drop signal
    VfxSignal2 <VappHsWidget *, VfxPenEvent &> m_signalDrop;

    // Request signal
    VfxSignal2 <VappHsWidget *, RequestId> m_signalRequest;

    // Reset signal
    VfxSignal2 <VappHsWidget *, VfxU16> m_signalReset;

// Constructor / Destructor
public:
    // Default constructor
    VappHsWidget();

// Method: general operation for Homescreen, specific widget operation is in onXxx
public:
    // Create widget bar icon view
    VfxBool createIconView();

    // Release widget bar icon view
    void releaseIconView()
    {
        onReleaseIconView();
        VFX_OBJ_CLOSE(m_controlIcon);
    }

    // Create widget view
    void createView();

    // Release widget view
    void releaseView(VfxBool isDeselected = VFX_FALSE);

    // Add the widget to desktop
    void addToDesktop();

    // Remove the widget from desktop
    void removeFromDesktop();

    // Check if the widget view is created
    VfxBool isCreated();

    // Set free drag and drop without any delay
    void setFreeDrag(
        VfxBool is_freeDrag // [IN] whether turns on free drag
    )
    {
        m_isFreeDrag = is_freeDrag;
    }

	// Widget is on top of the desktop
	void enterTop() {onEnterTop();}

	// Widget is not on top of the desktop
	void leaveTop() {onLeaveTop();}

// Advanced operation: let widget can add frames to the bottom of desktop with full screen coordinates
protected:
    // Add frame to bottom of desktop
    void addToBottom(
        VfxFrame* frame     // [IN] frame to add
    );

    // Remove frame from bottom of desktop
    void removeFromBottom(
        VfxFrame* frame     // [IN] frame to remove
    );

    // Get current valid rect of desktop
    VfxRect getCurrentValidRect() const;

private:
    // Set this widget to top of the desktop
    void setDesktopTop();

    // After time-out, start dragging
    void onTimerDrag(VfxTimer *timer);

// Overridable
// Widget life cycle: onInit -> onCreateView -> onAddToDesktop -> onRemoveFromDesktop -> onReleaseView -> onDeinit
//                                                  (drop) <-----------------------| (drag)
public:
    // Get type for this widget
    // RETURNS: string ID
    virtual VfxS32 getType() = 0;

    // Get Id for this widget
    // RETURNS: string ID
    virtual VfxS32 getId() = 0;

    // Get image icon resource ID for widget bar
    // RETURNS: image ID
    virtual VfxU16 getIcon() { return 0; }

    // Get string resource ID for the name of this widget
    // RETURNS: string ID
    virtual VfxU16 getName() { return 0; }

    // Get the attributes of this widget.
    // RETURNS: attributes
    virtual VfxU32 getAttr() { return 0; }

    // Create widget bar icon frame, m_controlIcon
    virtual VfxBool onCreateIconView() { return VFX_FALSE; }

    // Release widget bar icon frame, m_controlIcon is closed in base widget class by default
    virtual void onReleaseIconView() {}

    // Start to drag to desktop, widget can create its own window and service
    virtual void onCreateView() {}

    // No longer existed on desktop, widget should close all objects created in onCreateView()
    virtual void onReleaseView() {}

    // Widget is added to desktop (after createView and is sure to put on desktop)
    virtual void onAddToDesktop() {}

    // Widget is removed from desktop (not yet releaseView while dragging)
    virtual void onRemoveFromDesktop() {}

	// Widget is on top of the desktop
	virtual void onEnterTop() {}

	// Widget is not on top of the desktop
	virtual void onLeaveTop() {}

    virtual void onDeselect() {}
        
protected:
    // If widget cannot free drag and drop, directly lauch application with quick click
    virtual void onDirectLaunch() {}

// Override
protected:
    // On init
    virtual void onInit();

    // On deinit
    virtual void onDeinit();

    // On preview pen input
    // RETURNS: VfxBool
    virtual VfxBool onPreviewPenInput(
        VfxPenEvent &event  // [IN] pen event
    );

    // On pen input
    // RETURNS: VfxBool
    virtual VfxBool onPenInput(
        VfxPenEvent &event  // [IN] pen event
    );

// Variable
public:
    // Widget bar icon frame
    VfxControl      *m_controlIcon;

protected:
    // State
    WidgetStateEnum m_state;

    // Force free drag and drop;
    VfxBool         m_isForceFreeDrag;

private:
    // Desktop frame handle
    VappHsDesktop   *m_desktop;

    // Child object count, for check
    VfxU32          m_childCount;

    // Timer of starting dragging
    VfxTimer        *m_timerDrag;

    // Wether pen is captured in widget instead of desktop
    VfxBool         m_isPenDown;

    // Whther start a delay to drag and drog
    VfxBool         m_isFreeDrag;
};

#endif /* __MMI_VUI_HOMESCREEN__ */
#endif /* __VAPP_HS_WIDGET_BASE_H__ */

