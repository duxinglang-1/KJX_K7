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
 *  vfx_main_scr.h
 *
 * Project:
 * --------
 *  Venus FW
 *
 * Description:
 * ------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_PAGE_H__
#define __VFX_PAGE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
// by RHR //#include "vfx_uc_include.h"
#include "vfx_main_scr.h"
#include "vfx_page_bar.h"

#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_signal.h"
#include "vfx_app.h"
#include "vfx_screen.h"
#include "vfx_archive.h"
#include "vfx_input_event.h"
#include "vfx_timer.h"
#include "vfx_keypad.h"
#include "vfx_weak_ptr.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Class VfxPage
 *****************************************************************************/

class VfxPageTransition;

/*
 * VfxPage. This class represent a full screen venus page. It is part of VfxMainScr.
 * A page can have a status bar, a top bar (usually title bar) and 
 * a bottom bar (usually tool bar).
 */
class VfxPage : public VfxControl
{
    VFX_DECLARE_CLASS(VfxPage);
// Declaration
public:

// Constructor / Destructor
public:
    // Constructor
    VfxPage();
    
    // Destructor
    virtual ~VfxPage();

// Method
public:
    // Query page id, it is assigned when page enter page stack.
    // So if the page is not at stack yet, VFX_ID_NULL will be returned.
    // RETURNS: page id
    VfxId       getId() const;

    // Query if this is current page
    VfxBool     isActive() const;

    // close self, with animation if page is at top.
    void        exit();

    // close self, emulate back key process
    void        back();

    // Setup a new page transition, it is used while pushing/popuping
    void        setTransition(
        VfxPageTransition *transition   // [IN] Page transition object
    );

    // Query page transition object
    VfxPageTransition *getTransition() const { return m_transition.get(); };

    // Query if a page is translucent
    VfxBool     isTranslucent() const { return (m_pageFlags & FLAGS_IS_TRANSLUCENT) ? VFX_TRUE : VFX_FALSE; }

    // Query if a page has status bar
    VfxBool     hasStatusBar() const { return ((m_pageFlags & FLAGS_HAS_STATUS_BAR) && !getIsBarHidden()); }

// Properties
public:
    // turn on/off status bar
    void        setStatusBar(
        VfxBool on  // [IN] on or off
    );

    // set customized background for status bar
    // Note. Only support static image resource
    void        setStatusBarBg(
        VfxResId bgImage  // [IN] on or off
    );

    // get customized background for status bar
    VfxResId    getStatusBarBg(void);

    // turn on/off translucent support
    void        setTranslucent(
        VfxBool on  // [IN] on or off
    );
    
    // turn on/off bar auto hiding.
    void        setBarAutoHide(
        VfxBool on  // [IN] on or off
    );

    // check if bar is in hidden or not.
    VfxBool     getIsBarHidden() const
    {
        return (m_pageFlags & FLAGS_IN_HIDDEN_STATE) ? VFX_TRUE : VFX_FALSE;
    }

    // Setup a bar to top area
    void        setTopBar(
        VfxPageBar *bar // [IN] bar pointer
    )
    { setBar(VFX_PAGE_BAR_LOCATION_TOP, bar); }

    // Setup a bar to bottom area
    void        setBottomBar(
        VfxPageBar *bar // [IN] bar pointer
    )
    { setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, bar); }

    // Allow page to be delete?
    VfxBool getAllowDelete() const
    {
        return m_allowDelete;
    }

    // Set whether allow to delete page.
    void setAllowDelete(
        VfxBool allowDelete // [IN] allow flag
    )
    {
        m_allowDelete = allowDelete;
    }


// Signal
public:
    // This signal is invoked when a page transition finish (whenever phase in or out)
    // void YourClass::onTransitionEnd(VfxObject* sender, VfxBool in, VfxS32 direction)
    VfxSignal3 <VfxObject*, VfxBool, VfxS32> m_signalTransitionStop;
    
// Method
public:
    // Query VfxApp pointer
    VfxApp      *getApp() const { return getMainScr()->getApp(); }

    // Query VfxMainScr pointer
    VfxMainScr  *getMainScr() const;

    // Attach bar to this page
    void        setBar(
        VfxPageBarLocationEnum loc,     // [IN] top or bottom area
        VfxPageBar *newBar,             // [IN] bar pointer
        VfxBool deleteOldBar = VFX_FALSE// [IN] close the old bar or not
    );

    // Turn on/off bar
    void        toggleBar(
        VfxPageBarLocationEnum loc,     // [IN] top or bottom bar to be toggle
        VfxBool on                      // [IN] on or off
    );

    // Query bar pointer
    VfxPageBar  *getBar(
        VfxPageBarLocationEnum loc      // [IN] top or bottom
    ) const;

    // Query if a bar is currenly on or off
    VfxBool     isBarOn(
        VfxPageBarLocationEnum loc      // [IN] top or bottom
    ) const;

    // Hide/unhide all bars on this page
    void        hideAllBars(
        VfxBool hide = VFX_TRUE         // [IN] hide or unhide
    );

    // Return current rotate angle of page
    VfxScrRotateTypeEnum getRotate() const;

/* DOM-NOT_FOR_SDK-BEGIN */
// Method
public:
    // Prepare a transition. call before startTransition and before screen rotation.
    // This API is internal used, only called by VfxMainScr. 
    void        prepareTransition(
        VfxBool in = VFX_TRUE,          // [IN] transit in or out
        VfxS32 direction = 0,           // [IN] direction, can be 1, 0, -1
        const VfxScreenRotateParam *param = NULL    // [IN] rotate information
    );

    // Start a transition.
    // This API is internal used, only called by VfxMainScr. 
    VfxBool     startTransition(
        VfxBool autoClose = VFX_FALSE   // [IN] close page after finishing transit out
    );

    // Stop a transition.
    // This API is internal used, only called by VfxMainScr. 
    VfxBool     stopTransition();

    // Reposition bars when parent's client area change.
    // This API is internal used, only called by VfxMainScr. 
    void        reposistionBars(VfxBool noAnimation = VFX_FALSE);

    // This API is internal used, only called by VfxPageBar. 
    VfxBool     previewBarPenInput(VfxPenEvent &event);

    // This API is internal used, only called by VfxMainScr. 
    virtual void processEnter(VfxBool isBackward, VfxBool doFirstHalf = VFX_TRUE, VfxBool doSecondHalf = VFX_TRUE);

    // This API is internal used, only called by VfxMainScr. 
    virtual void processExit(VfxBool isBackward, VfxBool doFirstHalf = VFX_TRUE, VfxBool doSecondHalf = VFX_TRUE);

    // This API is internal used, only called by VfxMainScr. 
    virtual void processExited();

    // This API is internal used, only called by VfxMainScr. 
    virtual VfxBool processSerialize(VfxArchive &ar);

    // This API is internal used, only called by VfxMainScr. 
    virtual void processRestore(VfxArchive &ar);

    // This API is internal used, only called by VfxMainScr. 
    void queryRotate(VfxScreenRotateParam &param);

    // This API is internal used, only called by VfxMainScr. 
    virtual void processRotate(const VfxScreenRotateParam &param);

    // This API is internal used, only called by VfxMainScr. 
    VfxRect getPageRect() const;

    // This API is internal used, only called by VfxMainScr. 
    VfxFrame* getActiveChild() const;

    // This API is internal used, only called by VfxMainScr. 
    virtual mmi_ret processProc(mmi_event_struct *evt);
/* DOM-NOT_FOR_SDK-END */

// Overridable    
protected:
    // While entering the page to be active
    virtual void onEnter(VfxBool isBackward);
    
    // After the page entered. If there is transit effect, it will 
    // be called when the effect finished.
    virtual void onEntered();

    // While leaving the screen to be inactive
    virtual void onExit(VfxBool isBackward);
    
    // After the page exited. If there is transit effect, it will 
    // be called when the effect finished.
    virtual void onExited();

    // After the page exited and after the screen snapshot. 
    virtual void onExited2();

    // After the page exited. Page can store data into archive (serialize)
    // RETURNS: VFX_TRUE if the page serialize itself.
    //          VFX_FALSE default behavior, do nothing.
    virtual VfxBool onSerialize(VfxArchive &ar);

    // If the page was serialized, onRestore will be called when it is about
    // to display again. 
    // After onInit, before onEnter.
    virtual void onRestore(VfxArchive &ar);

    // Override this virtual function to return the screen support rotate types.
    //  The defualt behavior is setting param.rotateTo to VFX_SCREEN_SUPPORT_ROTATE_NORMAL
    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );

    // While the LCD screen has been rotate
    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    );

    // Notify that transition effect is finished
    // If you override this function, please remember to call VfxPage::onTransitionStop()
    virtual void onTransitionStop(
        VfxBool in,         // [IN] in or out
        VfxS32 direction    // [IN] direction of trasnsition, can be 1, 0, -1
    );

    // Notify for back key process
    virtual void onBack();

    // Notify when Bar is about to become invisible. Only when setBarAutoHide(VFX_TRUE)
    virtual void onBarAutoHide();

    // Notify for general events
    virtual mmi_ret onProc(mmi_event_struct *evt);

/* DOM-NOT_FOR_SDK-BEGIN */
protected:
    // Query client area of a page 
    // This API is internal used. 
    virtual VfxRect onGetPageRect() const;

    // Query active child of a page
    // This API is internal used. 
    virtual VfxFrame *onGetActiveChild() const;

    // Allow for customize set bar behavior 
    // This API is internal used. 
    virtual VfxPageBar *onSetBar(VfxPageBarLocationEnum loc, VfxPageBar *newBar);

// Override
public:
    virtual void setPosZ(VfxFloat value);
    virtual void setHidden(VfxBool value);

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onObjectNotify(VfxId eventId, void *userData);
    void onAfterInit();
    virtual void onUpdate();
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

    virtual void processRegisterAccessKeyHandler(VfxKeyCodeEnum keyCode, VfxControl *target);
    virtual void processUnregisterAccessKeyHandler(VfxKeyCodeEnum keyCode, VfxControl *target);
    virtual void processUnregisterAllAccessKeyHandler(VfxControl *target);

// Override
public:
    virtual VfxBool processFocusKey(VfxKeyEvent &event);
    VfxFrameImeModeEnum getImeMode() {return VFX_FRAME_IME_MODE_RESIZE;}
    void adjustImeResize(const VfxSize &size, VfxFrame *focusFrame);

// Implemetation
private:
    enum
    {
        FLAGS_IS_INITED         = 1 << 0,    // If page is inited
        FLAGS_IS_ACTIVE         = 1 << 1,    // If page is active
        FLAGS_IS_TRANSLUCENT    = 1 << 2,    // If page is translucent
        FLAGS_IS_DIRTY          = 1 << 3,    // If page is dirty
        FLAGS_HAS_STATUS_BAR    = 1 << 4,    // If page has status bar
        FLAGS_IN_HIDDEN_STATE   = 1 << 5,    // If page is in hidden state
        FLAGS_IN_IME_LAYOUT     = 1 << 6,    // If page is in IME layout state
        FLAGS_IN_BAR_CAPTURE    = 1 << 7,    // If page is in Bar capture mode

        FLAGS_MAX
    };

// Variable
private:
    class Bar;
    friend class Bar;
    Bar             *m_topBar, *m_bottomBar;
    VfxTimer        *m_autoHideTimer;       /* if bar auto hide enable */
    VfxAccessKeyMgr *m_pAccessKeyMgr;       // Access key manager.
    
    VfxWeakPtr<VfxPageTransition> m_transition;
    VfxScrRotateTypeEnum m_orientation;
    VfxU32          m_pageFlags;
    //VfxBool         m_isInited;
    //VfxBool         m_isTranslucent;
    //VfxBool         m_hasStatusBar;
    //VfxBool         m_inHiddenState;        /* if bar should be hidden now */
    //VfxBool         m_isDirty;
    //VfxBool         m_inIMELayout;
    VfxResId        m_statusBarBgImage;

    // data need to be serialized
    VfxBool         m_allowDelete;          /* allow delete or not */
    
    //VfxBool         m_isActive;

// Implementation
private:
    void        processTransitionStop(VfxBool in, VfxS32 direction);
    void        doUpdate(VfxBool noAnimation);
    void        doRotate(VfxScreenRotateParam param, VfxBool noAnimation);
    void        adjustClient();
    
    void        onBarBoundChanged(VfxFrame *f, const VfxRect &r);
    void        onTimer(VfxTimer *timer);
/* DOM-NOT_FOR_SDK-END */
};

class IVfxPageHandler;

class VfxPageEx : public VfxPage
{
// Constructor
public:
    VfxPageEx(IVfxPageHandler *handler);
    virtual ~VfxPageEx();

// Method
public:
    void doDefaultBack();

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);
    virtual void onExited();
    virtual void onExited2();

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    virtual void onRotate(const VfxScreenRotateParam &param);
    
    virtual void onBack();
    virtual mmi_ret onProc(mmi_event_struct *evt);
    
private:
    IVfxPageHandler* m_handler;
};

class IVfxPageHandler
{
public:
    virtual void onPageInit(VfxPageEx *page) {}
    virtual void onPageDeinit(VfxPageEx *page) {}

    virtual void onPageEnter(VfxPageEx *page, VfxBool isBackward) {}
    virtual void onPageEntered(VfxPageEx *page) {}
    virtual void onPageExit(VfxPageEx *page, VfxBool isBackward) {}
    virtual void onPageExited(VfxPageEx *page) {}
    virtual void onPageExited2(VfxPageEx *page) {}

    virtual VfxScrRotateTypeEnum onPageQueryRotate(VfxPageEx *page, const VfxScreenRotateParam &param) { return VFX_SCR_ROTATE_TYPE_NORMAL; }
    virtual void onPageRotate(VfxPageEx *page, const VfxScreenRotateParam &param) {}

    virtual void onPageBack(VfxPageEx *page) { page->doDefaultBack(); }
    virtual mmi_ret onPageProc(VfxPageEx *page, mmi_event_struct *evt) { return MMI_RET_DONT_CARE; }
};

class VfxPageHandler : public VfxObject, public IVfxPageHandler
{
// Constructor
public:
    VfxPageHandler();
    virtual ~VfxPageHandler();

// Method
public:
    VfxPageEx *createPage(void);

// Method
protected:
    VfxPageEx *getPage(void) { return m_page; }

// Override
public:
    virtual void onPageInit(VfxPageEx *page);
    virtual void onPageDeinit(VfxPageEx *page);

private:
    VfxPageEx *m_page;
};


#endif /* __VFX_PAGE_H__ */
