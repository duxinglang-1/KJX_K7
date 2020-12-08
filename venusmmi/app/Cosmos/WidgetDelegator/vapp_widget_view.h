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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   widget_view_ui.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements widget view UI presentation
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_GADGET_SUPPORT__
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_widget_adp.h"
#include "widget_adp_struct.h"

#define WIDGET_VIEW_MAX_CAPTION 256
#define WIDGET_MAX_NAME_LENGTH   40

#if defined(__MMI_MAINLCD_480X800__)
#define WIDGET_VIEW_LOADING_ICON_SIZE_WIDTH     150
#define WIDGET_VIEW_LOADING_ICON_SIZE_HEIGHT    150 

#define WIDGET_VIEW_WIDGET_ICON_SIZE_WIDTH      72
#define WIDGET_VIEW_WIDGET_ICON_SIZE_HEIGHT     72

#elif defined(__MMI_MAINLCD_320X480__)
#define WIDGET_VIEW_LOADING_ICON_SIZE_WIDTH     100
#define WIDGET_VIEW_LOADING_ICON_SIZE_HEIGHT    100

#define WIDGET_VIEW_WIDGET_ICON_SIZE_WIDTH      48
#define WIDGET_VIEW_WIDGET_ICON_SIZE_HEIGHT     48

#else   /* WQVGA and QVGA*/
#define WIDGET_VIEW_LOADING_ICON_SIZE_WIDTH     80
#define WIDGET_VIEW_LOADING_ICON_SIZE_HEIGHT    80

#define WIDGET_VIEW_WIDGET_ICON_SIZE_WIDTH      38
#define WIDGET_VIEW_WIDGET_ICON_SIZE_HEIGHT     38
#endif


extern "C"
{
extern gdi_handle gadget_adp_plugin_utils_get_video_layer();
extern VfxFrame *gadget_adp_view_get_image_frame_ptr();
extern VfxPage *gadget_adp_view_get_parent_object();
}

/*****************************************************************************
 * Static Declaration
 *****************************************************************************/
class VappWidgetViewMainScr;
class VappWidgetViewPage;
class VappWidgetEditorPage;

extern "C"
{

enum WidgetViewPageState
{
    WIDGET_VIEW_PAGE_STATE_NONE,
    WIDGET_VIEW_PAGE_STATE_ENTER,
    WIDGET_VIEW_PAGE_STATE_UPDATE,
    WIDGET_VIEW_PAGE_STATE_EXIT,
    WIDGET_VIEW_PAGE_STATE_CLOSED
};

}

/*****************************************************************************
 * Class Declaration
 *****************************************************************************/
class VappWidgetView : public VfxApp
{
    VFX_DECLARE_CLASS(VappWidgetView);

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetView();

// Override
public:
    // Application's entry point
    virtual void onRun(void* args, VfxU32 argSize);

    // Application's exit point
    virtual void onDeinit();

    // Proc funciton, handle events
    virtual mmi_ret onProc(mmi_event_struct * evt);

    // Process close function. Invoke when application is closed in OOM scenario
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);
    
	// Continue close. Please refer VfxApp::continueClose
    void continueClose(VfxAppCloseAnswerEnum answer);

// Method
public:
    // Set parameters according to show view indicator
    void onInitView(widget_show_view_ind_struct *widgetShowViewInd, VfxBool mainmenu);
    
    // Create editor page (COSMOS_INPUT_KEY_SUPPORT only)
    void onInitEditorPage(widget_enter_text_ind_struct *widgetEnterTextInd);

    // Check the widget is valid or not (Main menu support)
    VfxBool checkWidgetIsValid(VfxS32 id);    

    // Check load result (Main menu support)
    void checkLoadResult(VfxS32 result);

    // Close editor page (COSMOS_INPUT_KEY_SUPPORT only)
    void closeEditorPage();

    // Send update response to gadget task
    void sendUpdateResponse(int instance_id, void *view_handle);

    // Call page lock canvas function
    void *lockCanvas(int instance_id, void *view_handle, void **ptr_buffer, int width, int height);

    // Activate when page state changed
    void onPageStateChanged(VappWidgetViewPage *page, WidgetViewPageState state);

    // Activate when enter details view page
    void onUpatePage(void *param);    

    // Show page content
    void showPage();

    // Called when view closed
    void closeView(void *param);

    // Close details view page by id when widget is unloaded
    VfxS32 closeById(VfxS32 instance_id);

    // Terminate details view
    void terminateAll(void *param);

	// Terminate details view
    void terminate(void *param);

    // Confirm popup callback 
    void terminateCallback();

    // Activate when leave main screen
    void onLeaveMainScr(VfxBool leave);

    // Set details view response
    void setViewResponse(VfxS32 response);

    // The view is focused
    void onFocus();

    // The view is defocused
    void onDefocus();

    // Get the active page
    VfxPage *getActivePage();

    // Get widget name
	VfxWChar* getWidgetName();

// Method
private:
    // Activate when receive enter page signal
    void onEnterPage(VappWidgetViewPage *page);

    // Activate when receive exit page signal
    void onExitPage(VappWidgetViewPage *page);

    // Activate when receive page key input
    void onPageKeyInput(VfxU16 keyCode, VfxU16 keyType);

    // Activate when receive page pen input
    void onPagePenInput(VfxPoint point, VfxS32 EventType);

    // Set protocol event handler
    void setEventHandler(VfxBool isView);

// Variable
public:
    // Record widget id which is launched in main menu
    static VfxS32 m_mainmenuId;
    
    // Widget id
    static VfxS32 m_widgetId;

    // Widget view handle
    static void *m_viewHandle;

    // Widget view type
    static VfxS32 m_viewType;

// Variable
private:
    // Main screen
    VappWidgetViewMainScr *m_screen;
    
    // Widget view flags
    VfxS32 m_viewFlags;

    // Widget details view width
    VfxU32 m_viewWidth;

    // Widget details view height
    VfxU32 m_viewHeight;

    // Widget options view title
    VfxWChar m_viewCaption[WIDGET_VIEW_MAX_CAPTION];

    // Close by engine flag
    VfxBool m_closedByEngine;

    // Exception occured flag
    VfxBool m_exceptionOccured;

    // Confirm popup response
    VfxU32 m_viewResponse;

    // Page state
    WidgetViewPageState m_pageState;

    // Resize ratio
    VfxFloat m_resizeRatio;

    // Prepared flag
    VfxBool m_prepared;

	// Name string
	VfxWChar *m_nameString;

    // Launch type
    VfxBool m_mainmenu;
};


// VappWidgetViewMainScr class declaration
class VappWidgetViewMainScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappWidgetViewMainScr);

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetViewMainScr();


// Override
public:
    // Please refer VfxMainScr::on1stReady
    virtual void on1stReady();

    // Main screen exit point
    virtual void onDeinit();

// Method
public:
    // Create page for widget details view
    VappWidgetViewPage *createWidgetViewPage();

    // Create page for widget editor page
    VappWidgetEditorPage *createWidgetEditorPage();

    // Close widget editor page
    void closeWidgetEditorPage();
    
// Signal
public:
    // This signal is used to notify leave main screen
    VfxSignal1 <VfxBool> m_signalLeaved;

// Variable
private:
    // Widget details view page
    VfxWeakPtr <VappWidgetViewPage> m_viewPage;

    // Widget editor page
    VfxWeakPtr <VappWidgetEditorPage> m_editorPage;
};


// VappWidgetViewPage class declaration
class VappWidgetViewPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappWidgetViewPage);

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetViewPage();

// Override
public:
    // This function will be invoked when entering page
    virtual void onEnter(VfxBool isBackward);

    // This function will be invoked when exiting page
    virtual void onExited2();

    // Page exit point
    virtual void onDeinit();

    // Handle key input event
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

    // Handle pen input event
    virtual VfxBool onPenInput(VfxPenEvent &event);

// Method
public:
    // Show loading icon
    void displayLoadingIcon();

    // Show details view content
    VfxBool show(VfxWChar *caption, int is_fullscreen, VfxU32 width, VfxU32 height);
    
    // Set details view image content
    void setImageContent(VfxU32 width, VfxU32 height);

    // Close page
    void closePage();

    // Lock image buffer
    void *lockCanvas(VfxS32 view_type, void **ptr_buffer);

    // Unlock image buffer
    static void unlockCanvas(void *p);

	// Get image buffer pointer
	VfxFrame *getImageFramePtr();  

private:
    // Draw title bars and bottom bar
    void drawBars(VfxWChar *caption);

    // Allocate image buffer
    VfxBool prepareImgBuffer(VfxBool alloc_flag, VfxU32 size);

    // Get page height
    VfxU32 getPageHeight();

    // Activate when tool bar button clicked
    void onToolBarClick(VfxObject *sender, VfxId id);

    // Create mutex
    void createMutex();

    // Get mutex
    void takeMutex();

    // Give mutex
    static void giveMutex();

public:
    // State changed signal
    VfxSignal2 <VappWidgetViewPage*, WidgetViewPageState> m_signalStateChanged;

    // Pen input signal
    VfxSignal2 <VfxPoint, VfxS32> m_singalPenInput;

    // Key input signal
    VfxSignal2 <VfxU16, VfxU16> m_singalKeyInput;

    // Mutex of image buffer
    static kal_mutexid m_imageBufferMutex;

    // Page state
    static WidgetViewPageState m_state;

    // Set Resize ratio
    void setResizeRatio(VfxFloat ratio)
    {
        m_resizeRatio = ratio;
    }
   
private:
    // Resize ratio
    VfxFloat m_resizeRatio;

    // Image frame to show details view content
    VfxWeakPtr <VfxImageFrame> m_imageFrame;

    // Image buffer 1
    VfxU8 *m_imageBuffer1;

    // Image buffer 2
    VfxU8 *m_imageBuffer2;

    // Group id (use to allocate memory)
    mmi_id m_gid;

    // Loading icon
    VfxWeakPtr <VcpActivityIndicator> m_loadingIcon;

    // Widget icon
    VfxWeakPtr <VfxFrame> m_widgetIcon;

    // Real width of widget
    VfxS32 m_width;

    // Real height of widget
    VfxS32 m_height;

	// Image buffer size
	VfxS32 m_bufferSize;

    // record which buffer is drawed
	VfxS32 m_drawedBuffer;

    // weak pointer
    VfxWeakPtr <VappWidgetViewPage> weakPtr;
};

#endif

