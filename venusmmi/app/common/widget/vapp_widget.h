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
 *  vapp_widget.h
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

#ifndef VAPP_WIDGET_H
#define VAPP_WIDGET_H

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_widget_primitive.h"

#if defined(__COSMOS_3D_V10__)
#include "vfx_material.h"
#endif


/*****************************************************************************
 * Widget Base Class
 *****************************************************************************/

/*
 * Macro to declare a widget.
 */
#define VAPP_WIDGET_DECLARE_CLASS(_className)                               \
                                                                            \
    VFX_DECLARE_CLASS(_className);                                          \
                                                                            \
    public:                                                                 \
        static VappWidget *createWidget(VfxObject *parentObj)


/*
 * Macro to implement a widget.
 */
#define VAPP_WIDGET_IMPLEMENT_CLASS(_className, _parentClassName)           \
                                                                            \
    VFX_IMPLEMENT_CLASS(#_className, _className, _parentClassName);         \
                                                                            \
    VappWidget *_className::createWidget(VfxObject *parentObj)              \
    {                                                                       \
        _className *widget;                                                 \
        VFX_OBJ_CREATE(widget, _className, parentObj);                      \
        return widget;                                                      \
    }


/*
 * Widget Base Class
 */
class VappWidget : public VfxControl
{
    VFX_DECLARE_CLASS(VappWidget);

// Constructor / Destructor
public:
    // Default constructor
    VappWidget();

    // Default destructor
    virtual ~VappWidget();

// Signal
public:
    // This signal is emitted when the widgets does not want the user can swipe
    // the desktop.
    VfxSignal1 <VappWidget *> m_signalForbidDesktopSwipe;

    // This signal is emitted when the widgets permits the user to swipe the
    // desktop.
    VfxSignal1 <VappWidget *> m_signalPermitDesktopSwipe;

// Method
public:
    // Check if the widget view is created.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isCreated() const
    {
        return m_isCreated;
    }

    // Check if the widget view is serialized.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isSerialized() const
    {
        return m_isSerialized;
    }

    // Check if the widget cature pen
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isProcessPenCapture() const
    {
        return m_isProcessPenCapture;
    }

    // Check if the widget is suspended.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isSuspended() const
    {
        return m_isSuspended;
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

    // Check if the widget is in the focused state.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isFocused() const
    {
        return m_isFocused;
    }

    // Check-in the widget is visible on the desktop. For example, if the widget
    // is put on the second page while the active page is the first page, the
    // widget is not visible.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE;
    VfxBool isVisible() const
    {
        return m_isVisible;
    }

#if defined(__COSMOS_3D_V10__)
    // Set the material for the edit button.
    //
    // TODO: If setMaterial is a virtual function, we can override it to do this
    //       automatically.
    void setEditButtonMaterial(
        VfxMaterial *material       // [IN] Material
    );
#endif /* defined(__COSMOS_3D_V10__) */

// Override
public:
    // Get Id for this widget
    // RETURNS: string ID
    virtual VappWidgetId getId() const;

    // Get string resource ID for the name of this widget
    // RETURNS: length of the widget name
    virtual VfxS32 getName(
        VfxWChar *string,           // [OUT] String buffer
        VfxS32 size                 // [IN] Buffer size in wchar
    ) const;

    // Get max. size of the widget.
    // RETURNS: size
    virtual VfxSize getMaxSize() const;

    // Create widget icon.
    // RETURNS: widget
    virtual VfxFrame *createIcon(
        VfxObject *parentObj        // [IN] Parent object
    );

// Override
protected:
    // Override this virtual to create the widget's view.
    virtual void onCreateView();

    // Override this virtual to release the widget's view.
    virtual void onReleaseView();

// Override
public:
    // Override this virtual to tell if the CreateView is failed. This function
    // is generally called after the createView function to check if the view
    // is created successfully. If it is failed, the 'errorString' is used to
    // prompt the user about the error message. If it is successful,
    // 'errorString' is undefined.
    // RETURNS: If failure exists, return VFX_TRUE; otherwise, return VFX_FALSE.
    //
    // SEE ALSO: createView
    virtual VfxBool getCreateViewFailure(
        VfxWString &errorString     // [OUT] Prompt message for the user
    );

// Override
protected:
    // Override this virtual to serialize your view. This virtual is mainly used
    // to save more memory. Generally, it is called when the home screen becomes
    // inactive.
    //
    // SEE ALSO: onRestoreView
    virtual void onSerializeView(
        VfxArchive *ar      // [OUT] Archive to save your history
    );

    // Override this virtual to restore your view.
    //
    // SEE ALSO: onSerializeView
    virtual void onRestoreView(
        VfxArchive *ar      // [IN] Archive containing your previous history
    );

    // Override this virtual to serialize your view when page switch.
    // This virtual is mainly used to save more memory.
    // Generally, it is called when the home page swich to main menu page
    // Home and MM are integrated a single application.
    //
    // SEE ALSO: onRestoreView
    virtual void onSerializeViewForPageSwitch(
        VfxArchive *ar      // [OUT] Archive to save your history
    );

    // Override this virtual to restore your view.
    //
    // SEE ALSO: onSerializeView
    virtual void onRestoreViewForPageSwitch(
        VfxArchive *ar      // [IN] Archive containing your previous history
    );

    // Override this virtual to suspend widget.
    //
    // SEE ALSO: onResume
    virtual void onSuspend();

    // Override this virtual to resume widget.
    //
    // SEE ALSO: onSuspend
    virtual void onResume();

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

    // Override this virtual if you need to do something when your widget is
    // focused. This is useful, e.g., when your widget has an editor and you
    // might want to show a cursor on the input box.
    //
    // SEE ALSO: onDefocus
    virtual void onFocus();

    // Override this virtual if you need to do something when your widget lost
    // the focus. For example, you might need to hide the cursor on the input
    // box of the editor.
    //
    // SEE ALSO: onFocus
    virtual void onDefocus();

    // Override this virtual if you need to do something when you widget becomes
    // visible or not.
    virtual void onVisibleChanged(
        VfxBool isVisible       // [IN] Visible or not
    );

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
    // NOTE: Internal used only for VappWidget.
    VfxSignal2 <
        VappWidget *,       // [IN] This widget
        VfxPenEvent &       // [IN] Pen event
    > m_signalDrag;

    // This signal is emitted when the widget wants to be moved.
    // NOTE: Internal used only for VappWidget.
    VfxSignal2 <
        VappWidget *,       // [IN] This widget
        VfxPenEvent &       // [IN] Pen event
    > m_signalMove;

    // This signal is emitted when the widget wants to be moved.
    // NOTE: Internal used only for VappWidget.
    VfxSignal2 <
        VappWidget *,       // [IN] This widget
        VfxPenEvent &       // [IN] Pen event
    > m_signalDrop;

    // This signal is emitted when the widget wants to abort the dragging.
    // NOTE: Internal used only for VappWidget.
    VfxSignal2 <
        VappWidget *,       // [IN] This widget
        VfxPenEvent &       // [IN] Pen event
    > m_signalAbort;

    // This signal is emitted when the widget wants to be deselected from the
    // home screen.
    VfxSignal1 <
        VappWidget *        // [IN] This widget
    > m_signalDeselect;

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

    // Serialize the widget view.
    //
    // NOTE: Internal used only.
    void serializeView();

    // Restore the widget view.
    //
    // NOTE: Internal used only.
    void restoreView();

    // NOTE: Internal used only.
    void serializeViewForPageSwitch();

    // Restore the widget view.
    //
    // NOTE: Internal used only.
    void restoreViewForPageSwitch();

    // Suspend widget.
    //
    // NOTE: Internal used only.
    void suspend();

    // Resume widget.
    //
    // NOTE: Internal used only.
    void resume();

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

    // Set visible of the widget.
    //
    // NOTE: Internal used only.
    void setVisible(
        VfxBool isVisible           // [IN] Visible or not
    );

    // set widget into dragged mode directly
    // this is for scenario that put mainmenu app icon to HS
    void setWidgetDragged(VfxBool isDragged);

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

    // Robot launcher support put mainmenu's icon to HS as shortcut,
    // in this scenario, widget needs to capture pen during a peroid of pen,
    void processPenCapture();

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

// Override
protected:

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

        // This scenario is for put mainmenu app icon to HS by long press icon.
        // Widget needs to capture pen directly while put app icon from MM,
        // and enter the dragged mode like long press widget on HS scenario
        DND_CAPTURE_FROM_MM,

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

    // If the widget's view is serialized or not.
    VfxBool     m_isSerialized;

    // If the widget's view is serialized or not.
    VfxBool     m_isSerializedForPageSwitch;

    // If the widget's view is created or not.
    VfxBool     m_isProcessPenCapture;

    // If the widget is suspendeded.
    VfxBool     m_isSuspended;

    // If the widget's view is slim.
    VfxBool     m_isSlim;

    // If the widget is in the edit mode or not.
    VfxBool     m_isInEditMode;

    // If the widget is in the focused state.
    VfxBool     m_isFocused;

    // If the widget is visible.
    VfxBool     m_isVisible;

    // The number of children objects (used to check memory leak between
    // create and release the view).
    VfxS32      m_numOfChild;

    // Drag-and-Drop (DnD) state. Please refer to DndStateEnum for details.
    DndStateEnum m_dndState;

    // Used to backup the original widget's position.
    VfxPoint m_originalPosition;

    // Used to backup the serialized view of the widget.
    VfxMemArchiveSource *m_archiveSource;

    // Used to backup the serialized view of the widget for page switch.
    VfxMemArchiveSource *m_archiveSourceForPageSwitch;

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
    VappWidgetStickyButton *m_button;

// Implementation
private:
    // This function handles the signal when the sticky button is clicked.
    void onButtonClicked(
        VappWidgetStickyButton *obj     // [IN] Sticky button
    );
};

#endif /* defined(__MMI_VUI_WIDGET_FACTORY__) */
#endif /* VAPP_WIDGET_H */

