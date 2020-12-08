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
 *  vapp_app_widget.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the widget's base class.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_APP_WIDGET_H
#define VAPP_APP_WIDGET_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_desktop_gprot.h"
#include "vapp_app_widget_primitive.h"


/*****************************************************************************
 * Widget Base Class
 *****************************************************************************/

/*
 * Macro to declare a widget.
 */
#define VAPP_APP_WIDGET_DECLARE_CLASS(_className)                           \
                                                                            \
    VFX_DECLARE_CLASS(_className);                                          \
                                                                            \
    public:                                                                 \
        static VappAppWidget *createWidget(VfxObject *parentObj)


/*
 * Macro to implement a widget.
 */
#define VAPP_APP_WIDGET_IMPLEMENT_CLASS(_className, _parentClassName)       \
                                                                            \
    VFX_IMPLEMENT_CLASS(#_className, _className, _parentClassName);         \
                                                                            \
    VappAppWidget *_className::createWidget(VfxObject *parentObj)           \
    {                                                                       \
        _className *widget;                                                 \
        VFX_OBJ_CREATE(widget, _className, parentObj);                      \
        return widget;                                                      \
    }


/*
 * Widget Base Class
 */
class VappAppWidget : public VfxControl
{
    VFX_DECLARE_CLASS(VappAppWidget);

// Constructor / Destructor
public:
    // Default constructor
    VappAppWidget();

    // Default destructor
    virtual ~VappAppWidget();

// Method
public:
    // Check if the widget view is created.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isCreated() const
    {
        return m_isCreated;
    }

    // Check if the widget view is slim.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isSlim() const
    {
        return m_isSlim;
    }

    // Check if the widget is in the edit mode.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isInEditMode() const
    {
        return m_isInEditMode;
    }

    // Check if the widget is being dragged;
    VfxBool isDragged() const
    {
        return (m_dndState == DND_CAPTURE_FROM_OTHERS || 
                m_dndState == DND_LONG_TAPPED_BY_ITSELF) ? VFX_TRUE : VFX_FALSE;
    }

// Method
protected:
    // Get the default max room size on the home screen.
    // RETURNS: max room size.
    VfxSize getMaxRoomSize() const;

    // Get the room size.
    //
    // For example, if your widget will occupy a 4x2 tiles (or called cells) on
    // the home screen, you can get the required room size like below:
    //
    //  VfxSize size = getRoomSize(4, 2);
    //
    // You can use this API to implement your 'getMaxSize' virtual function.
    //
    // RETURNS: the room size.
    //
    // SEE ALSO: getMaxSize
    VfxSize getRoomSize(
        VfxS32 horizTileNum,    // [IN] Horizontal tile number
        VfxS32 vertiTileNum     // [IN] Vertical tile number
    ) const;

// Override
public:
    // Get Id for this widget
    // RETURNS: string ID
    virtual VappAppWidgetId getId() const = 0;

    // Get string resource ID for the name of this widget
    // RETURNS: length of the widget name
    virtual VfxS32 getName(
        VfxWChar *string,           // [OUT] String buffer
        VfxS32 size                 // [IN] Buffer size in wchar
    ) const = 0;

    // Get max. size of the widget.
    // RETURNS: size
    virtual VfxSize getMaxSize() const = 0;

    // Create widget icon.
    // RETURNS: widget
    virtual VfxFrame *createIcon(
        VfxObject *parentObj        // [IN] Parent object
    ) = 0;

// Override
protected:
    // Override this virtual to create the widget's view.
    virtual void onCreateView();

    // Override this virtual to release the widget's view.
    virtual void onReleaseView();

    // Override this virtual to slim your view. This virtual is mainly used to
    // enhance the UI performance, e.g., the response time and the animation
    // time. It is called when the home screen has heavy animation.
    //
    // SEE ALSO: onExitSlimView
    virtual void onEnterSlimView();

    // Override this virtual to exit your slim view.
    //
    // SEE ALSO: onEnterSlimView
    virtual void onExitSlimView();

    // Override this virtual if you needs to do something when the widget is in
    // the edit mode.
    //
    // SEE ALSO: onExitEditMode
    virtual void onEnterEditMode();

    // Override this virtual if you needs to do something when the widget exits
    // the edit mode.
    //
    // SEE ALSO: onEnterEditMode
    virtual void onExitEditMode();

    // Override this function if you need to do something when the user taps the
    // widget.
    virtual void onTap(
        const VfxPoint &pos // [IN] Pen position on the widget's coordination
    );

    // Override this function if you need to do something when the user starts
    // to drag the widget from the desktop.
    //
    // SEE ALSO: onMove, onDrop, onAbort
    virtual void onDrag(
        VfxPenEvent &event  // [IN] Pen event
    );

    // Override this function if you need to do something when the user moves
    // the widget on the desktop.
    //
    // SEE ALSO: onDrag, onDrop, onAbort
    virtual void onMove(
        VfxPenEvent &event  // [IN] Pen event
    );

    // Override this function if you need to do something when the user drops
    // the widget on the desktop.
    //
    // SEE ALSO: onDrag, onMove, onAbort
    virtual void onDrop(
        VfxPenEvent &event  // [IN] Pen event
    );

    // Override this function if you need to do something when the dragging
    // operation is aborted, e.g., by an interrupt like an incoming call.
    //
    // SEE ALSO: onDrag, onMove, onDrop
    virtual void onAbort(
        VfxPenEvent &event  // [IN] Pen event
    );

    // Override this function to change the edit button on the widget.
    // RETURNS: offset from the (0, 0) position on the widget's coordination.
    virtual VfxPoint onGetEditButtonOffset();

//
// This block declares the signals that the home screen will use to manipulate
// the widget.
//

// Signal
public:
    // This signal is emitted when the widget wants to be dragged.
    // NOTE: Internal used only for VappAppWidget.
    VfxSignal2 <VappAppWidget *, VfxPenEvent &> m_signalDrag;

    // This signal is emitted when the widget wants to be moved.
    // NOTE: Internal used only for VappAppWidget.
    VfxSignal2 <VappAppWidget *, VfxPenEvent &> m_signalMove;

    // This signal is emitted when the widget wants to be moved.
    // NOTE: Internal used only for VappAppWidget.
    VfxSignal2 <VappAppWidget *, VfxPenEvent &> m_signalDrop;

    // This signal is emitted when the widget wants to abort the dragging.
    // NOTE: Internal used only for VappAppWidget.
    VfxSignal2 <VappAppWidget *, VfxPenEvent &> m_signalAbort;

    // This signal is emitted when the widget wants to be deselected from the
    // home screen.
    VfxSignal1 <VappAppWidget *> m_signalDeselect;

// Method
public:
    // Create the widget view.
    //
    // NOTE: Internal used only.
    void createView();

    // Release the widget view.
    //
    // NOTE: Internal used only.
    void releaseView();

    // Enter the widget's slim view.
    //
    // NOTE: Internal used only.
    void enterSlimView();

    // Exit the widget's slim view.
    //
    // NOTE: Internal used only.
    void exitSlimView();

    // Backup the current position.
    //
    // NOTE: Internal used only.
    void backupPosition();

    // Restore the previous position.
    //
    // NOTE: Internal used only.
    void restorePosition();

    // Enter widget's edit mode.
    //
    // NOTE: Internal used only.
    void enterEditMode();

    // Exit widget's edit mode.
    //
    // NOTE: Internal used only.
    void exitEditMode();

    // Focus the widget.
    //
    // NOTE: Internal used only.
    void focusView();

    // Defocus the widget.
    //
    // NOTE: Internal used only.
    void defocusView();

//
// This blocks overrides the parent's virtual functions.
//

// Override
public:
    // Please refer to VfxFrame.
    virtual void setPos(
        const VfxPoint &value
    );

    // Please refer to VfxFrame.
    virtual void setBounds(
        const VfxRect &value
    );

    // Please refer to VfxFrame.
    virtual void setIsUnhittable(
        VfxBool value
    );

    // Please refer to VfxFrame.
    virtual void setFilter(
        VfxFrameFilter *value
    );

    // Please refer to VfxFrame.
    virtual void setHidden(
        VfxBool value
    );

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

    // Please refer to VfxControl.
    virtual VfxBool onPreviewPenInput(
        VfxPenEvent &event
    );

    // Please refer to VfxObject.
    virtual VfxBool onPenInput(
        VfxPenEvent &event
    );

    // revise for rarely used virtual function
    void onParentFrameChanged(
        VfxFrame *oldParentFrame
    );

    // revise for rarely used virtual function
    virtual void onObjectNotify(VfxId id,void * userData);

// Enum
private:
    // State enum for the drag-and-drop FSM.
    enum DndStateEnum
    {
        // NULL state.
        DND_NULL,

        // Pen is captured from others and can drag the widget now.
        DND_CAPTURE_FROM_OTHERS,

        // Pen is captured by ourself and wait for the 'long-tap' event.
        DND_CAPTURE_BY_ITSELF,

        // Pen is captured by ourself and 'long-tap' event is received. We can
        // drag the widget now.
        DND_LONG_TAPPED_BY_ITSELF,

        // End of enum.
        DND_END_OF_ENUM
    };

// Variable
private:
    // If the widget's view is created or not.
    VfxBool     m_isCreated;

    // If the widget's view is slim.
    VfxBool     m_isSlim;

    // If the widget is in the edit mode or not.
    VfxBool     m_isInEditMode;

    // The number of children objects (used to check memory leak between
    // create and release the view).
    VfxS32      m_numOfChild;

    // Drag-and-Drop (DnD) state. Please refer to DndStateEnum for details.
    DndStateEnum m_dndState;

    // Used to backup the original widget's position.
    VfxPoint m_originalPosition;

// Implementation
protected:
    // This function calculates the distance between these 2 points.
    // RETURN: distance.
    VfxS32 calcDistance(
        const VfxPoint &p1,         // [IN] Point 1
        const VfxPoint &p2          // [IN] Point 2
    );

    // This function checks if the pen event matches the criteria to drag the
    // widget.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isDndCriteriaFit(
        const VfxPenEvent &event    // [IN] Pen event
    );

//
// This block supports the tap function. Generally, it is used to launch other
// applications.
//

// Implementation
protected:
    // This function checks if we can invoke the tap operation.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool canInvokeTap(
        const VfxPenEvent &event    // [IN] Pen event
    );

    // This function invokes the tap operation.
    void invokeTap(
        const VfxPenEvent &event    // [IN] Pen event
    );

private:
    // This function handles the tap events.
    void handleOnTap(
        void *userData              // [IN] User data
    );

//
// This block implements the edit button sticky on the widget.
//

// Variable
private:
    // Edit button.
    VappAppWidgetStickyButton *m_button;

// Implementation
private:
    // This function handles the signal when the sticky button is clicked.
    void onButtonClicked(
        VappAppWidgetStickyButton *obj     // [IN] Sticky button
    );
};

#endif /* defined(__MMI_VUI_LAUNCHER__) */
#endif /* VAPP_APP_WIDGET_H */

