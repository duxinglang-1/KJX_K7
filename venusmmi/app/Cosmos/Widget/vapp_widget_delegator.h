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
 *  vapp_hs_widget_delegator.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Definition of widget delegator
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
#ifndef __VAPP_WIDGET_DELEGATOR_H__
#define __VAPP_WIDGET_DELEGATOR_H__

#include "MMI_features.h"

#ifdef __MMI_GADGET_SUPPORT__

#include "vfx_uc_include.h"
#include "vapp_hs_res.h"
#include "vapp_widget.h"
#include "ui_core\pme\vfx_object_list.h"
#include "vcp_include.h"

extern "C"
{
#include "wgtmgrsrvgprot.h"
}

#define WIDGET_SETTING_BUTTON_SIZE      45

#define WIDGET_MAX_ICON_PATH_LENGTH     260

#if defined(__MMI_MAINLCD_480X800__)
#define WIDGET_MAX_ROOM_WIDTH                 480
#define WIDGET_MAX_ROOM_HEIGHT                600
#elif defined(__MMI_MAINLCD_320X480__)
#define WIDGET_MAX_ROOM_WIDTH                 320
#define WIDGET_MAX_ROOM_HEIGHT                336
#elif defined(__MMI_MAINLCD_240X400__)
#define WIDGET_MAX_ROOM_WIDTH                 240
#define WIDGET_MAX_ROOM_HEIGHT                284
#else /* defined(__MMI_MAINLCD_240X320__) */
#define WIDGET_MAX_ROOM_WIDTH                 240
#define WIDGET_MAX_ROOM_HEIGHT                280
#endif

#if defined(__MMI_MAINLCD_480X800__)
#define WIDGET_MARGIN                         10
#define WIDGET_MARGIN_TOP                     15

#define WIDGET_LOADING_ICON_SIZE_WIDTH        50
#define WIDGET_LOADING_ICON_SIZE_HEIGHT       50 

#define WIDGET_DEL_BTN_MARGIN_Y               25
#define WIDGET_DEL_BTN_MARGIN_X               30

#elif defined(__MMI_MAINLCD_320X480__)
#define WIDGET_MARGIN                          5
#define WIDGET_MARGIN_TOP                     10

#define WIDGET_LOADING_ICON_SIZE_WIDTH        40
#define WIDGET_LOADING_ICON_SIZE_HEIGHT       40

#define WIDGET_DEL_BTN_MARGIN_Y               20
#define WIDGET_DEL_BTN_MARGIN_X               24

#else   /* WQVGA and QVGA*/
#define WIDGET_MARGIN                          5
#define WIDGET_MARGIN_TOP                     10

#define WIDGET_LOADING_ICON_SIZE_WIDTH        35
#define WIDGET_LOADING_ICON_SIZE_HEIGHT       35

#define WIDGET_DEL_BTN_MARGIN_Y               18
#define WIDGET_DEL_BTN_MARGIN_X               20
#endif

enum WidgetViewType{
    WIDGET_IDLE_VIEW,
    WIDGET_DETAIL_VIEW
};

class VappWidgetObjectList :
    public VfxObject
{
    VFX_DECLARE_CLASS(VappWidgetObjectList);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappWidgetObjectList);

public:    
    VappWidgetObjectList() {};

public:
    VfxObjList getList()
    {
        return m_list;
    };

    VfxObjListEntry *append(VfxObject *obj)
    { 
        return m_list.append(obj);
    };
    
    VfxBool removeOne(VfxObject *obj)
    {
        return m_list.removeOne(obj);
    };

    VfxObjListEntry *getHead() const
    {
        return m_list.getHead();
    }

    VfxU32 getCounts() const
    {
        return m_list.getEntryCount();
    }

private:
    VfxObjList m_list;
};

class VappWidgetDelegator :
    public VappWidget
{
    VFX_DECLARE_CLASS(VappWidgetDelegator);

// Enum
public:    
    enum State{
        NONE,
        LOADING,
        LOADED,
        LOAD_FAILED,
        UNLOADED,
        DELETING,
        MAX_REACHED
    };

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetDelegator();

    //Default destructor
    ~VappWidgetDelegator();

// Override
public:
    // Get widget id
    virtual VappWidgetId getId() const;

    // Get widget size
    virtual VfxSize getMaxSize() const;

    // Get widget name string
    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;

    // Create widget icon frame
    virtual VfxFrame *createIcon(VfxObject *parentObj);

    // Create image frame and start loading
    virtual void onCreateView();

    // Release resource and unload widget
    virtual void onReleaseView();

    // Called when enter another page  
    virtual void onSerializeView(VfxArchive *ar);

    // Called when back to home screen
    virtual void onRestoreView(VfxArchive *ar);

    // Long tap the widget
    virtual void onDrag(VfxPenEvent &event);

    // Move the widget
    virtual void onMove(VfxPenEvent &event);

    // Drop the widget
    virtual void onDrop(VfxPenEvent &event);

    // Focus in
    virtual void onFocus();

    // Focus out
    virtual void onDefocus();

	// Visible changed
	virtual void onVisibleChanged(VfxBool isVisible);

    // Pen input event
    virtual VfxBool onPenInput(VfxPenEvent &event);

    // Edit button position
    virtual VfxPoint onGetEditButtonOffset();
    
// Methods
public:

	// Get widget resize ratio
	static VfxFloat getResizeRatio(VfxS32 instance_id);

    // Create widget
    static void *createWidget(const VappWidgetId &id, VfxObject *parentObj)
    {
        VappWidgetDelegator *widget;
        VFX_OBJ_CREATE(widget, VappWidgetDelegator, parentObj);
        widget->setId(id);
    
        return widget;
    };

    // Find widget by widget id
    static VappWidgetDelegator *findByInstancId(int instance_id);

    // Get head of widget list
    static VfxObjListEntry *getHead();
    
    // Delete widget
    static void deleteWidget(VappWidgetDelegator *widget);

    // Cancel load widget callback function
    static void cancelLoadWidget(VfxId id, void *widget);

    // Delete all widgets
    static void deleteAllWidget(VfxBool checkStatus = VFX_FALSE);

    // Set view type
    void setViewType(WidgetViewType type);
    
    // Check if details view
    VfxBool isDetailView() const;

    // Set image to default resource, this function is called when 
    // entering USB MS mode.
    void setImageToDefaultRes(void);

    // Recover to widget content, this function is called when 
    // exiting USB MS mode
    void recoverImageFromDefaultRes(void);

    // Show loading icon
    void loadingImage(void);

    // Release image resource
    void releaseImageResource(void);

    // Release widget resource
    void releaseResource(void);

    // Lock image buffer
    void *lockCanvas(void **buffer, int width, int height);

    // Unlock image buffer
    static void unlockCanvas(void *lock);

    // Get view handle
    void *getViewHandle(void);

    // Query widget status is loaded or not
    VfxBool isLoaded(void)
    {
        return (m_widgetStatus == LOADED) ? VFX_TRUE : VFX_FALSE;
    };

    // Show cancel loading popup
    void cancelLoadWidgetPopup(VfxResId str_id);

    // Check widget load response and prepare to show content
    void onWidgetLoadResult(int result, void *view_handle, int width, int height);

    // Handle widget resize event
    void onWidgetResize(VfxS32 width, VfxS32 height);

    // Handle widget content update event
    void onWidgetContentUpdate(void *buffer);

    // Notify HS forbid desktop swipe event
    void onEditorCreated(void);

    // Notify HS permit desktop swipe event
    void onEditorClosed(void);

// Methods
private:
    // Set widget id
    inline void setId(const VappWidgetId &id)
    {
        m_id = id;
    }

    // Create canvas mutex
    static kal_mutexid createCanvasLock(int id);

    // Check the memory is enough to load widget or not (max: VAPP_WIDGET_IDLE_FG_SIZE)
    VfxBool checkMemAvaliable(VfxS32 instance_id, VfxU32 size);

    // Allocate double image buffer
    VfxBool allocImgBuffer(VfxU32 size);

    // Free double image buffer
    void freeImgBuffer();

    // Set image content 
    void setImageContent(VfxU32 width, VfxU32 height);

    // Set setting button position
    VfxPoint getSettingButtonPos(int, int) const;

    // After setting button is pressed, enter related application
    // RETURNS: void
    void launchSetting(VfxObject *obj, VfxId id);

    // After time-out, setting button starts disappearing
    // RETURNS: void
    void onTimerSetBut(VfxTimer *timer);

    // After fade-out, setting button will be hidden
    // RETURNS: void
    void onTlSetBut(VfxBaseTimeline *timeline, VfxBool isCompleted);

    // After loading complete
    void onAnimationStopped(VfxBaseTimeline *timeline, VfxBool stop);
    
// Variables
public:   
    // Widget status
    State m_widgetStatus;
    
private:
    static int m_instance_count;
    static VfxBool m_hasInitialized;

    // constant
    enum
    {
        SETBUT_MARGIN_GAP   = 5,    // margin gap of setting button
        SETBUT_APPEAR_TIME  = 2000, // appearance time of setting button
        SETBUT_FADEOUT_TIME = 250   // fadeout time of setting button
    };

    // widget bar icon image
    //VfxObjList m_list;

    // Widget id
    VappWidgetId m_id;

    // Widget view type
    WidgetViewType m_viewType;

    // Widget view handle
    void *m_viewHandle;

    // Dragging mode flag
    VfxBool m_isDragging;

    // Resize flag
    VfxBool m_isResizing;

    // Focused flag
    VfxBool m_focused;

    // Idle view's width
    VfxS32 m_clientWidth;

    // Idle view's height
    VfxS32 m_clientHeight;

    // Idle view image frame
    VfxImageFrame *m_imageFrame;

    // Image buffer 1
    VfxU8 *m_imageBuffer1;

    // Image buffer 2
    VfxU8 *m_imageBuffer2;

    // Loading icon
    VcpActivityIndicator *m_waitingIcon;

    // Whether there is a setting button
    MMI_BOOL m_hasSetBut;

    // Setting button Pressed flag
    VfxBool m_buttonPressed;

    // Setting button to launch related application
    VcpButton *m_buttonSetting;

    // Timer of setting button disappearance
    VfxTimer *m_timerSetBut;

    // Timeline of fade-out animation for setting button
    VfxFloatTimeline *m_tlSetBut;

    // Widget fade in time line
    VfxFloatTimeline *m_timeline;

    // Canvas lock
    kal_mutexid m_canvasLock;

    // Screen group id (use to allocate memory)
    mmi_id m_gid;

    // Is enter flag
    VfxBool m_isEnter;

    // Out of screen
    VfxBool m_isTooLarge;

    // text frame when usb ms mode
    VfxTextFrame *m_textFrame;

	// record which buffer is drawed
	VfxS32 m_drawedBuffer;

	// record which buffer is set to m_imageFrame
	VfxU8 *m_usedBuffer;
};
    
#endif /* __MMI_GADGET_SUPPORT__ */
#endif /* __VAPP_WIDGET_DELEGATOR_H__ */
