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
 *  vapp_hs_cp.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Internal UI componets of home screen application category
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
#ifndef __VAPP_HS_CP_H__
#define __VAPP_HS_CP_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_control.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_cpp_base.h"
#include "vfx_basic_type.h"
#include "vfx_primitive_frame.h"
#include "vfx_timer.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_frame.h"
#include "vfx_text_frame.h"
#include "vfx_draw_context.h"
#include "vcp_marquee.h"
#include "vapp_hs_def.h"
#include "vapp_hs_widget_base.h"        // for base widget class define


/***************************************************************************** 
 * Define
 *****************************************************************************/
// LCD check
#if defined(__MMI_MAINLCD_240X320__) || \
    defined(__MMI_MAINLCD_240X400__) || \
    defined(__MMI_MAINLCD_320X240__) || \
    defined(__MMI_MAINLCD_320X480__) || \
    defined(__MMI_MAINLCD_360X640__) || \
	defined(__MMI_MAINLCD_480X800__)
#else
    #error "Venus home screen does not support this LCD resolution."
#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
class VappHsDesktop;


/***************************************************************************** 
 * Home screen UI componet: drag and drop image
 *****************************************************************************/

class VappHsDndImage : public VfxControl
{
// Declaration
public:
    // State enum
    enum DndStateEnum
    {
        STATE_DRAG,     // Drag state
        STATE_MOVE,     // Move state
        STATE_SCROLL,   // Scroll state
        STATE_DROP      // Drop state
    };

    // Scroll way enum
    enum ScrollWayEnum
    {
        NONE_SCROLL,    // No scroll
        HORI_SCROLL,    // Horizontal scroll
        VERT_SCROLL     // Vertical scroll
    };

// Signal
public:
    // Drag signal
    VfxSignal2 <VappHsDndImage *, VfxPenEvent &>    m_signalDrag;

    // Move signal
    VfxSignal2 <VappHsDndImage *, VfxPenEvent &>    m_signalMove;

    // Drop signal
    VfxSignal2 <VappHsDndImage *, VfxPenEvent &>    m_signalDrop;

    // Abort signal
    VfxSignal2 <VappHsDndImage *, VfxPenEvent &>    m_signalAbort;

// Constructor / Destructor
public:
    // Default constructor
    VappHsDndImage();

// Method
public:
    // Set image resource ID
    void setImageId(
        VfxS32 id   // [IN] image ID
    );

    void setImageSrc(
        const VfxWString &src
    );
    
    // Set image child frame
    void setImageChild(
        VfxControl *image   // [IN] image child frame
    )
    {
        addChildFrame(image);
        setBounds(image->getBounds());
    }

    // Get image resource ID
    VfxS32 getImageId();

// Override
protected:
    // On init
    virtual void onInit();

    // On pen input
    // RETURNS: VfxBool
    virtual VfxBool onPenInput(
        VfxPenEvent &event  // [IN] pen event
    );

// Variable
public:
    // State
    DndStateEnum    m_state;

    // Scroll way
    ScrollWayEnum   m_scrollWay;
};


/***************************************************************************** 
 * Home screen UI componet: interactive image array class, used for widget bar, shortcut bar / pool
 *****************************************************************************/

class VappHsInteractiveImageArray : public VfxControl
{
// Declaration
protected:
    // Scroll way enum
    enum ScrollWayEnum
    {
        NONE_SCROLL,    // No scroll
        HORI_SCROLL,    // Horizontal scroll
        VERT_SCROLL     // Vertical scroll
    };

    // Scroll and free run constant
    enum
    {
        SCROLL_TIME = 250,  // Scroll time
        FRRUN_TIME  = 500,  // Free run time
        FRRUN_SPEED = 250   // Free rum speed
    };

// Constructor / Destructor
public:
    // Default constructor
    VappHsInteractiveImageArray();

// Method
public:
    // Shuffle image array with additional space while inserting new image
    void cross(
        VfxPenEvent &event      // [IN] pen event
    );

    // Insert image with specific location
    void insertImage(
        VappHsDndImage *image,  // [IN] new DND image
        VfxPenEvent &event      // [IN] pen event
    );

    // Remove image
    void removeImage(
        VappHsDndImage *image,  // [IN] image to remove
        VfxBool isArrange       // [IN] whether to arrange image array immediately
    );

    // Backup the position and the index of the image
    void backupImage(
        VappHsDndImage *image   // [IN] image to backup
    );

    // Restore the position and index of the original backuped image
    void restoreImage(
        VappHsDndImage *image,          // [IN] image to backup
        VfxBool isBlink = VFX_TRUE,     // [IN] blink the image or not
        VfxBool isArrange = VFX_TRUE    // [IN] Arrange the image array or not
    );

    // Get current number of images
    // RETURNS: number of images
    VfxS32 getImageNumber() { return m_count; }

// Overridable
public:
    // Initialize image array
    virtual void initImage(
        VfxS32 count,           // [IN] number of images
        VappHsDndImage **image  // [IN] array of DND images
    );

    // Get image array
    virtual VappHsDndImage** getImageArray() = 0;

    // Arrange image array
    virtual void arrange(VfxS32 crossIdx) = 0;

    // Align image array
    virtual void alignment() {}

    // Highlight image
    virtual void highlightImage(
        VappHsDndImage *image,  // [IN] image to highlight
        VfxBool isHighlight     // [IN] highlight or unhighlight
    );

protected:
    // Get parent handle
    // RETURNS: parent handle of images
    virtual VfxControl* getDndParent() { return this; }

    // Get max number of image array
    virtual VfxS32 getMaxNumber() = 0;

    // Get max value of scroll
    virtual VfxS32 getMaxScrollValue() {return 0;}

    // Locate position
    virtual VfxS32 locateIdx(VfxPoint pos) = 0;

// Override
protected:
    // On pen input
    // RETURNS: VfxBool
    virtual VfxBool onPenInput(
        VfxPenEvent &event  // [IN] pen event
    );

// Variable
protected:
    // Image array needs arrange
    VfxBool         m_isNeedArrange;

    // Number of images
    VfxS32          m_count;

    // Scroll way
    ScrollWayEnum   m_scrollWay;

    // Is scrolling
    VfxBool         m_isScroll;

private:
    // Original index of backup image
    VfxS32          m_oriIdx;

    // Original position of backup image
    VfxPoint        m_oriPos;
};


/***************************************************************************** 
 * Home screen UI componet: widget bar
 *****************************************************************************/

class VappHsWidgetBar : public VappHsInteractiveImageArray
{
// Declaration
private:
    // State enum
    enum WidgetBarStateEnum
    {
        STATE_INIT,             // Init state
        STATE_FOLD,             // Fold state
        STATE_UNFOLD            // Unfold state
    };

    // Pen state enum
    enum PenBehaviorStateEnum
    {
        PEN_STATE_NONE,         // No pen
        PEN_STATE_FOLD_UNFOLD,  // Pen for fold / unfold
        PEN_STATE_SCROLL        // Pen for scroll
    };

    // Position, size and constant
    enum
    {
        X_POS       = 0,        // X position

#if defined(__MMI_MAINLCD_240X320__)
        Y_POS       = 18,       // Y position
#elif defined(__MMI_MAINLCD_240X400__)
        Y_POS       = 20,       // Y position
#elif defined(__MMI_MAINLCD_320X240__)
        Y_POS       = 36,       // Y position
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
        Y_POS       = 20,       // Y position
#endif

#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
        IND_X_POS   = 58,       // X position of indicator
#else
        IND_X_POS   = 50,       // X position of indicator
#endif

#if defined(__MMI_MAINLCD_240X320__)
        IND_Y_POS   = 23,      // Y position of indicator
#elif defined(__MMI_MAINLCD_240X400__)
        IND_Y_POS   = 32,      // Y position of indicator
#elif defined(__MMI_MAINLCD_320X240__)
        IND_Y_POS   = 16,       // Y position of indicator
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
        IND_Y_POS   = 42,       // Y position of indicator
#endif

#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
        IND_WIDTH   = 34,       // Width of indicator
        IND_HEIGHT  = 68,       // Height of indicator
        FOLD_WIDTH  = 58,       // Fold width
#else
        IND_WIDTH   = 24,       // Width of indicator
        IND_HEIGHT  = 60,       // Height of indicator
        FOLD_WIDTH  = 50,       // Fold width
#endif

#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)
#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
        BG_HEIGHT = 403,
#elif defined(__MMI_MAINLCD_240X400__)
        BG_HEIGHT = 323,
#else
        BG_HEIGHT = 245,
#endif
#else /* defined(__MMI_VUI_SHELL_MULTI_PAGE__) */
#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
        BG_HEIGHT = 399,
#elif defined(__MMI_MAINLCD_240X400__)
        BG_HEIGHT = 335,
#elif defined(__MMI_MAINLCD_320X240__)
        BG_HEIGHT = 159,
#else
        BG_HEIGHT = 257,
#endif
#endif /* defined(__MMI_VUI_SHELL_MULTI_PAGE__) */

        GAP         = 7,        // Gap between images
        CROSS_GAP   = 10,       // Cross gap while incoming new image
        CLICK_TIME  = 500,      // Time to fold / unfold directly
        MAX_ITEM    = VAPP_HS_WIDGET_MAX_NUM  // Max number of images
    };

// Constructor / Destructor
public:
    // Default constructor
    VappHsWidgetBar();

// Method
public:
    // Fold widget bar
    void fold();

    // Unfold widget bar
    void unfold();

    // check whether widget bar is un-folded
    VfxBool isUnfold() { return (m_state == STATE_UNFOLD) ? (VFX_TRUE) : (VFX_FALSE); }

// Signal
public:
    // Folding state signal
    VfxSignal1 <VfxBool> m_signalUpdateFolding;

private:
    // fly in all images
    void flyInAllImages();

// Override
public:
    // Init image array of widget bar
    virtual void initImage(
        VfxS32 count,           // [IN] number of images
        VappHsDndImage **image  // [IN] image array
    );

    // Get image array of widget bar
    // RETURNS: image array
    virtual VappHsDndImage** getImageArray() { return m_dndImage; }

    // Arrange image array of widget bar
    virtual void arrange(
        VfxS32 crossIdx         // [IN] cross index to shuffle
    );

    // Align image array of widget bar:
    //  Align the bounds of widget bar to make the location of each image can be fixed
    //  Moreover, if image is less than one screen, it will align to top-most.
    virtual void alignment();

protected:
    // On init
    virtual void onInit();

    // On pen input:
    //  If pen down is triggered by widget bar itself, the rest pen events represent fold / unfold widget bar.
    //  Otherwise, pen events represent scrolling the widget bar.
    // RETURNS: VfxBool
    virtual VfxBool onPenInput(
        VfxPenEvent &event      // [IN] pen event
    );
    
    // On contain point
    virtual VfxBool onContainPoint(
        const VfxPoint &point   // [IN] point
    ) const;

    // Get max number of image array of widget bar
    // RETURNS: max number
    virtual VfxS32 getMaxNumber() { return MAX_ITEM; }

    // Locate index of image for a specific position
    // RETURNS: index of image
    virtual VfxS32 locateIdx(
        VfxPoint pos            // [IN] position
    );

    // Get parent of image array of widget bar
    // RETURNS: parent frame handle
    virtual VfxControl* getDndParent() { return m_controlPanel; }

    // Get max scroll value
    // RETURNS: max scroll vaule
    virtual VfxS32 getMaxScrollValue() {return m_controlPanel->getBounds().getHeight();}

// Variable
public:
    // Control panel to put images
    VfxControl              *m_controlPanel;

private:
    // Background image
    VfxImageFrame           *m_imageBg;

    // Button image
    VfxImageFrame           *m_imageButton;

    // Image array of widget bar
    VappHsDndImage          *m_dndImage[MAX_ITEM];

    // Timer to fold / unfold widget bar
    VfxTimer                *m_timerClick;

    // State
    WidgetBarStateEnum      m_state;

    // Original x position of pen event
    VfxS32                  m_xOri;

    // Pen state
    PenBehaviorStateEnum    m_penState;

    // Whether it is the first time to display
    VfxBool                 m_isOpening;
};


/***************************************************************************** 
 * Home screen UI componet: desktop
 *****************************************************************************/

class VappHsDesktop : public VfxControl
{
    VFX_DECLARE_CLASS(VappHsDesktop);

// Declaration
public:
    // Page constant
    enum
    {
#if defined(__MMI_MAINLCD_240X320__)
        PAGE_WIDTH      = 240,  // full width of each page of the desktop
        PAGE_HEIGHT     = 320,  // full height of each page of the desktop
#elif defined(__MMI_MAINLCD_240X400__)
        PAGE_WIDTH      = 240,  // full width of each page of the desktop
        PAGE_HEIGHT     = 400,  // full height of each page of the desktop
#elif defined(__MMI_MAINLCD_320X240__)
        PAGE_WIDTH      = 320,  // full width of each page of the desktop
        PAGE_HEIGHT     = 240,  // full height of each page of the desktop
#elif defined(__MMI_MAINLCD_320X480__)
        PAGE_WIDTH      = 320,  // full width of each page of the desktop
        PAGE_HEIGHT     = 480,  // full height of each page of the desktop
#elif defined(__MMI_MAINLCD_360X640__)
        PAGE_WIDTH      = 360,  // full width of each page of the desktop
        PAGE_HEIGHT     = 640,  // full height of each page of the desktop
#elif defined(__MMI_MAINLCD_480X800__)
        PAGE_WIDTH      = 320,  // full width of each page of the desktop
        PAGE_HEIGHT     = 480,  // full height of each page of the desktop
#endif
#if defined(VAPP_HS_CFG_MULTI_DESKTOP)
        TOTAL_PAGE      = 3     // number of pages of the desktop
#else
        TOTAL_PAGE      = 1     // number of pages of the desktop
#endif
    };

private:
    // Constant
    enum
    {
        SENSITIVITY     = 5,    // sensitivity (pixel) to switch to next / previous page
        SWITCH_TIME     = 250   // time to switch to next / previous page
    };

// Constructor / Destructor
public:
    // Default constructor
    VappHsDesktop();

// Method
public:
    // Add widget to desktop
    void addWidget(
        VappHsWidget *widget    // [IN] put widget on desktop,
                                //      the location should be set correctly in caller,
                                //      but may be adjusted here if out of valid region
    );

    // Add widget to desktop from history, ignore X position adjustment
    void addWidgetFromHistory(
        VappHsWidget *widget    // [IN] put widget on desktop,
                                //      the location should be set correctly in caller,
                                //      but may be adjusted here if out of valid region
    );

    // Remove widget from desktop
    void removeWidget(
        VappHsWidget *widget    // [IN] widget
    );

    // Align desktop to fixed position
    void alignment();

    // On pen input
    // RETURNS: VfxBool
    VfxBool doPenInput(
       VfxPenEvent &event  // [IN] event
    );

    // This function sets the valid region on the desktop.
    void setVerticalValidRegion(
        VfxS32 y,           // [IN] Y-coordinate of the vertical valid region
        VfxS32 height       // [IN] height of the vertical valid region
    );

    // This function gets the valid region on the desktop.
    VfxRect getValidRegion();

// Override
protected:
    // On init
    virtual void onInit();

private:
    // Align bottom frame
    void alignBottomFrame();

    // On bounds value change
    void onBoundsValueChange(
        VfxFrame *source,
        const VfxRect &oldBounds
    );

// Variable
public:
    // Bottom frame
    VfxFrame    *m_frameBottom;

private:
    // Original x position
    VfxS32       m_xOri;

    // Timer to switch page
    VfxTimer    *m_timerSwitch;

    // Y-coordinate of the valid region on the desktop.
    VfxS32       m_validY;

    // Height of the valid region on the desktop.
    VfxS32       m_validHeight;
};


/***************************************************************************** 
 * Home screen UI componet: shortcut bar class
 *****************************************************************************/

class VappHsShortcutBar : public VappHsInteractiveImageArray
{
// Declaration
public:
    // Position
    enum
    {
        X_POS       = 0,    // X position
#if defined(__MMI_MAINLCD_240X320__)
        Y_POS       = 267,  // Y position
#elif defined(__MMI_MAINLCD_240X400__)
        Y_POS       = 347,  // Y position
#elif defined(__MMI_MAINLCD_320X240__)
        Y_POS       = 187,  // Y position
#elif defined(__MMI_MAINLCD_320X480__)
        Y_POS       = 413,  // Y position
#elif defined(__MMI_MAINLCD_360X640__)
        Y_POS       = 573,  // Y position
#elif defined(__MMI_MAINLCD_480X800__)
        Y_POS       = 413,  // Y position
#endif
#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
        Y_OFFSET    = 36,   // Y offset of image
#else
        Y_OFFSET    = 30,   // Y offset of image
#endif
        LEFT_IND    = 0,    // left indicator
        RIGHT_IND   = 1     // right indicator
    };

private:
    // State enum
    enum ShortcutBarStateEnum
    {
        STATE_INIT,         // Init state
        STATE_ACTIVE,       // Active state
        STATE_CONFIGUE      // Configue state
    };

    // Position, size and constant
    enum
    {
        MAX_ITEM    = VAPP_HS_SHORTCUT_MAX_NUM,
        Y_MARGIN    = 8,    // Y margin of image
#if defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__)
        MAX_WIDTH   = 320,  // Max width of shortcut bar
#elif defined(__MMI_MAINLCD_360X640__)
        MAX_WIDTH   = 360,  // Max width of shortcut bar
#else
        MAX_WIDTH   = 240,  // Max width of shortcut bar
#endif
#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__)
        MAX_HEIGHT  = 67,   // Max height of shortcut bar
#else
        MAX_HEIGHT  = 53,   // Max height of shortcut bar
#endif
#if defined(__MMI_MAINLCD_320X240__)
        GAP         = 0,    // Gap between images
#else
        GAP         = 3,    // Gap between images
#endif
        CROSS_GAP   = 10,   // Cross gap between images while inserting new image
        HILITE_TIME = 100   // Time to highlight
    };

// Signal
public:
    // Drag signal
    VfxSignal2 <VfxS32, VfxBool> m_signalUpdateIndicator;

// Constructor / Destructor
public:
    // Default constructor
    VappHsShortcutBar();

private:
    // Update indicators
    void updateIndicators();

    // On bounds value change
    void onBoundsValueChange(
        VfxFrame *source,
        const VfxRect &oldBounds
    );

// Override
public:
    // Init image array of shortcut bar
    virtual void initImage(
        VfxS32 count,           // [IN] number of images
        VappHsDndImage **image  // [IN] image array
    );

    // Get image array of shortcut bar
    // RETURNS: image array
    virtual VappHsDndImage** getImageArray() { return m_dndImage; }

    // Arrange image array of shortcut bar
    virtual void arrange(
        VfxS32 crossIdx         // [IN] cross index to shuffle
    );

    // Align image array of shortcut bar:
    //  Align the bounds of shortcut bar to make the location of each image can be fixed.
    //  Moreover, if image is less than one screen, it will align to right-most
    virtual void alignment();

    // Highlight image
    virtual void highlightImage(
        VappHsDndImage *image,  // [IN] image to highlight
        VfxBool isHighlight     // [IN] highlight or unhighlight
    );

protected:
    // On init
    virtual void onInit();

    // On pen input
    // RETURNS: VfxBool
    virtual VfxBool onPenInput(
        VfxPenEvent &event  // [IN] pen event
    );

    // On contain point
    virtual VfxBool onContainPoint(const VfxPoint &point) const;

    // Get max number of image array
    // RETURNS: max number
    virtual VfxS32 getMaxNumber() { return MAX_ITEM; }

    // Locate index of image for a specific position
    // RETURNS: index of image
    virtual VfxS32 locateIdx(
        VfxPoint pos            // [IN] position
    );

    // Get max scroll value
    // RETURNS: max scroll value
    virtual VfxS32 getMaxScrollValue() {return MAX_WIDTH;}

// Variable
private:
    // Highlight image
    VfxImageFrame           *m_imageHighlight;

    // Image array
    VappHsDndImage          *m_dndImage[MAX_ITEM];

    // State
    ShortcutBarStateEnum    m_state;
};


/***************************************************************************** 
 * Home screen UI componet: black screen class
 *                          used to gray screen while shorcut pool is unfolded
 *****************************************************************************/

class VappHsBlackScreen : public VfxControl
{
// Declaration
private:
    // Position and size
    enum
    {
        X_POS       = 0,    // X position
        Y_POS       = 0,    // Y position
#if defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__)
        MAX_WIDTH   = 320,  // Width
#elif defined(__MMI_MAINLCD_360X640__)
        MAX_WIDTH   = 360,  // Width
#else
        MAX_WIDTH   = 240,  // Width
#endif
#if defined(__MMI_MAINLCD_240X320__)
        MAX_HEIGHT  = 274   // Height
#elif defined(__MMI_MAINLCD_240X400__)
        MAX_HEIGHT  = 354   // Height
#elif defined(__MMI_MAINLCD_320X240__)
        MAX_HEIGHT  = 194   // Height
#elif defined(__MMI_MAINLCD_320X480__)
        MAX_HEIGHT  = 434   // Height
#elif defined(__MMI_MAINLCD_360X640__)
        MAX_HEIGHT  = 594   // Height
#elif defined(__MMI_MAINLCD_480X800__)
        MAX_HEIGHT  = 434   // Height
#endif
    };

// Constructor / Destructor
public:
    // Default constructor
    VappHsBlackScreen() {}

// Signal
public:
    // Pen down signal
    VfxSignal0 m_signalDown;

// Override
protected:
    // On init
    virtual void onInit();

    // On pen input
    // RETURNS: VfxBool
    virtual VfxBool onPenInput(
        VfxPenEvent &event  // [IN] pen event
    );
};


/***************************************************************************** 
 * Home screen UI componet: shortcut pool class
 *****************************************************************************/

class VappHsShortcutPool : public VappHsInteractiveImageArray
{
// Declaration
private:
    // State enum
    enum ShortcutPoolStateEnum
    {
        STATE_INIT,         // Init state
        STATE_FOLD,         // Fold state
        STATE_UNFOLD        // Unfold state
    };

    //  Position, size and constant
    enum
    {
        X_POS       = 0,    // X position
#if defined(__MMI_MAINLCD_240X320__)
        Y_POS       = 274,  // Y position
#elif defined(__MMI_MAINLCD_240X400__)
        Y_POS       = 354,  // Y position
#elif defined(__MMI_MAINLCD_320X240__)
        Y_POS       = 194,  // Y position
#elif defined(__MMI_MAINLCD_320X480__)
        Y_POS       = 420,  // Y position
#elif defined(__MMI_MAINLCD_360X640__)
        Y_POS       = 580,  // Y position
#elif defined(__MMI_MAINLCD_480X800__)
        Y_POS       = 420,  // Y position
#endif
#if defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__)
        MAX_WIDTH   = 320,  // Width
#elif defined(__MMI_MAINLCD_360X640__)
        MAX_WIDTH   = 360,  // Width
#else
        MAX_WIDTH   = 240,  // Width
#endif
#if defined(__MMI_MAINLCD_320X240__)
        MAX_HEIGHT  = 152,  // Height
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__)
        MAX_HEIGHT  = 266,  // Height
#else
        MAX_HEIGHT  = 200,  // Height
#endif
#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__)
        ITEM_WIDTH  = 60,   // Item width
        ITEM_HEIGHT = 60,   // Item height
#else
        ITEM_WIDTH  = 45,   // Item width
        ITEM_HEIGHT = 45,   // Item height
#endif
        Y_GAP       = 4,    // Y gap between images
        CROSS_GAP   = 10,   // Cross gap between images while inserting new image
        HILITE_TIME = 100,  // Time to highlight
        MAX_ITEM    = VAPP_HS_SHORTCUT_MAX_NUM    // Max number of images
    };

// Constructor / Destructor
public:
    // Default constructor
    VappHsShortcutPool();

// Method
public:
    // Fold shortcut pool
    void fold();

    // Unfold shortcut pool
    void unfold();

    // Check whether it is fold
    VfxBool isUnfold() { return (m_state == STATE_UNFOLD) ? (VFX_TRUE) : (VFX_FALSE); }

// Override
public:
    // Init images of shortcut pool
    virtual void initImage(
        VfxS32 count,           // [IN] number of images
        VappHsDndImage **image  // [IN] image array
    );

    // Get image array of shortcut pool
    // RETURNS: image array
    virtual VappHsDndImage** getImageArray() { return m_dndImage; }

    // Arrange image array of shortcut pool
    virtual void arrange(
        VfxS32 crossIdx         // [IN] Cross index while inserting new image
    );

    // Highlight image
    virtual void highlightImage(
        VappHsDndImage *image,  // [IN] image to highlight
        VfxBool isHighlight     // [IN] highlight or unhighlight
    );

protected:
    // On init
    virtual void onInit();

    // On pen input
    // RETURNS: VfxBool
    virtual VfxBool onPenInput(
        VfxPenEvent &event      // [IN] pen event
    );

    // Get max number of images of shortcut pool
    // RETURNS: number of images
    virtual VfxS32 getMaxNumber() { return MAX_ITEM; }

    // Locate index of image for a specific position
    // RETURNS: index of image
    virtual VfxS32 locateIdx(
        VfxPoint pos            // [IN] position
    );

// Variable
private:
    // Image array
    VappHsDndImage          *m_dndImage[MAX_ITEM];

    // Highlight image
    VfxImageFrame           *m_imageHighlight;

    // State
    ShortcutPoolStateEnum   m_state;

    // Row to cross
    VfxS32                  m_crossRow;

    // Whether it is first time to display shortcut pool
    VfxBool                 m_isOpening;
};


/***************************************************************************** 
 * Home screen UI componet: native status icon class
 *****************************************************************************/

class VappHsStatusIcon : public VfxControl
{
// Constructor / Destructor
public:
    // Default constructor
    VappHsStatusIcon() {}

// Override
protected:
    virtual void onInit();
};


/***************************************************************************** 
 * Home screen UI componet: idle mode text class
 *****************************************************************************/
class VappHsIdleModeText : public VfxFrame
{
public:
    VappHsIdleModeText();
    void setText(const VfxWString &str);
    void setIcon(const VfxU8 *iconData);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onDraw(VfxDrawContext &dc);

private:
    enum
    {
        // idle mode icon (for SAT)
        ICON_GAP_Y      = 2,
        ICON_WIDTH      = 13,
        ICON_HEIGHT     = 13,

        // idle mode text
    #if defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__)
        TEXT_WIDTH      = 300,
    #elif defined(__MMI_MAINLCD_360X640__)
        TEXT_WIDTH      = 340,
    #else
        TEXT_WIDTH      = 220,
    #endif
        TEXT_HEIGHT     = 37,

    #if defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__)
        FRAME_WIDTH     = 320,
    #elif defined(__MMI_MAINLCD_360X640__)
        FRAME_WIDTH     = 360,
    #else
        FRAME_WIDTH     = 240,
    #endif
        FRAME_HEIGHT    = TEXT_HEIGHT + ICON_GAP_Y + ICON_HEIGHT,

        // Marquee
        MARQUEE_START_DELAY = 3000,
        MARQUEE_SPEED       = 10,

        END_OF_ENUM
    };

    VfxImageFrame       *m_bgImg;
    VcpMarquee          *m_marquee;
    const VfxU8         *m_iconData;
    VfxBool              m_isTextPresent;

private:
    void updateHidden();
};


/***************************************************************************** 
 * Home screen UI componet: desktop indicator
 *****************************************************************************/
class VappHsDesktopIndicator : public VfxFrame
{
public:
    VappHsDesktopIndicator();
    void highlight(VfxS32 pos);

protected:
    virtual void onInit();
    virtual void onDraw(VfxDrawContext &dc);

private:
    enum
    {
        IND_WIDTH  = 11,   // width of page indicator
        IND_HEIGHT = 13,   // height of page indicator
        PAGE_WIDTH = VappHsDesktop::PAGE_WIDTH,
        TOTAL_PAGE = VappHsDesktop::TOTAL_PAGE
    };

    VfxS32  m_highlightIndex;
};


#if defined(__MMI_SEARCH_WEB_GOOGLE__)

/*****************************************************************************
 * Home screen UI component: Search Bar
 *****************************************************************************/

class VappHsSearchBar : public VfxControl
{
    VFX_DECLARE_CLASS(VappHsSearchBar);

// Constructor / Destructor
public:
    // Default constructor
    VappHsSearchBar();

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxControl.
    virtual VfxBool onPenInput(
        VfxPenEvent &event
    );

// Define
private:
#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
    #define VAPP_HS_SEARCH_BAR_FONT     VFX_FONT_DESC_MEDIUM
#else
    #define VAPP_HS_SEARCH_BAR_FONT     VFX_FONT_DESC_SMALL
#endif /* defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__) */

// Enum
private:
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
        WIDTH = 190,
        HEIGHT = 40,
        ICON_POS_X = 3,
        TEXT_POS_X = 45
    #elif defined(__MMI_MAINLCD_240X400__)
        WIDTH = 150,
        HEIGHT = 32,
        ICON_POS_X = 3,
        TEXT_POS_X = 36 
    #elif defined(__MMI_MAINLCD_320X240__)
        WIDTH = 150,
        HEIGHT = 32,
        ICON_POS_X = 3,
        TEXT_POS_X = 36
    #else /* defined(__MMI_MAINLCD_240X320__) */
        WIDTH = 150,
        HEIGHT = 32,
        ICON_POS_X = 3,
        TEXT_POS_X = 36 
    #endif /* defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__) */
    };

// Variable
private:
    VfxImageFrame *m_bgImg;

    VfxImageFrame *m_icon;

    VfxTextFrame *m_text;

    static const VfxFloat s_pressedOpacity;

// Implementation
private:
    // This function sets if the search bar is pressed or not.
    void setPressed(
        VfxBool isPressed   // [IN] Search bar is pressed or not
    );

    // This function launches the search APP.
    void onLaunchSearchApp();
};
#endif /* defined(__MMI_SEARCH_WEB_GOOGLE__) */

#endif /* __MMI_VUI_HOMESCREEN__ */
#endif /* __VAPP_HS_CP_H__ */

