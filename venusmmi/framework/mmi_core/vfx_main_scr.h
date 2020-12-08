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
 *  MainScr is a screen for common application, it provide templated UI with:
 *  1. Page stack
 *  2. Top and bottom bar area
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
#ifndef __VFX_MAIN_SCR_H__
#define __VFX_MAIN_SCR_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_app_scr.h"

#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"
#include "vfx_input_event.h"
#include "vfx_archive.h"
#include "vfx_screen.h"
#include "vfx_weak_ptr.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Class VfxMainScr
 *****************************************************************************/

class VfxIdObjStack;
class VfxPage;
class VfxPageHandler;
class VcpStatusIconBar;

/*
 * VfxMainScr. This class is a small framework providing templated UI. 
 * 1. A MainScr can have many pages 
 * 2. Each page can has up to 3 bar: status bar, top bar, bottom bar. 
 * 3. The pages are stored as a stack. Pages can be push into / pop from MainScr. 
 * 4. Animation during page changing 
 */
class VfxMainScr : public VfxAppScr
{
    VFX_DECLARE_CLASS(VfxMainScr);

// Declaration
public:

// Constructor / Destructor
public:
    // Constructor
    VfxMainScr();
    
    // Destructor
    virtual ~VfxMainScr();

// Method
public:
    // Push a page, with animated transition effect.
    // The page pointer must be valid (cannot be NULL). 
    // Note. You can use pushPageEx to archive lazy creation.
    // RETURNS: id of this page.
    VfxId pushPage(
        VfxId pageId,   // [IN] an unique id to identify the page. If it is 
                        //      VFX_ID_NULL, MainScr will automatically assign one
        VfxPage *page   // [IN] the page to be pushed, cannot be NULL
    );

    // Push a page, with animated transition effect.
    // MainScr will store the class info first. And when the page is actully needed, 
    // MainScr will create the page lazily.
    // RETURNS: id of this page.
    VfxId pushPageEx(
        VfxId pageId,   // [IN] an unique id to identify the page. If it is 
                        //      VFX_ID_NULL, MainScr will automatically assign one
        const VfxClassInfo *info // [IN] class info of page, use VFX_OBJ_CLASS_INFO(class)
    );

    // Push a page handler, with animated transition effect.
    // The page handler pointer must be valid (cannot be NULL). 
    // RETURNS: id of this page.
    VfxId pushPageHandler(
        VfxId pageId,   // [IN] an unique id to identify the page. If it is 
                        //      VFX_ID_NULL, MainScr will automatically assign one
        VfxPageHandler *handler // [IN] the page handler to be pushed, cannot be NULL
    );

    // Insert a page above another page, specified by insert_above.
    // If insert_above is 0 (VFX_ID_NULL), it will be insert to bottom.
    // The page pointer must be valid (cannot be NULL). 
    // Note. You can use pushPageEx to archive lazy creation.
    // RETURNS: id of this page.
    VfxId insertPage(
        VfxId pageId,   // [IN] an unique id to identify the page. If it is 
                        //      VFX_ID_NULL, MainScr will automatically assign one
        VfxPage *page,  // [IN] the page being inserted, cannot be NULL
        VfxId insert_above  // [IN] id of another page to specify insert position.
                            // if it is top page, behavior equal to pushPage
    );

    // Insert a page above another page, specified by insert_above.
    // If insert_above is 0 (VFX_ID_NULL), it will be insert to bottom.
    // MainScr will store the class info first. And when the page is actully needed, 
    // MainScr will create the page lazily.
    // RETURNS: id of this page.
    VfxId insertPageEx(
        VfxId pageId,   // [IN] an unique id to identify the page. If it is 
                        //      VFX_ID_NULL, MainScr will automatically assign one
        const VfxClassInfo *info, // [IN] class info of page, use VFX_OBJ_CLASS_INFO(class)
        VfxId insert_above  // [IN] id of another page to specify insert position.
                            // if it is top page, behavior equal to pushPageEx
    );

    // Insert a page handler above another page, specified by insert_above.
    // If insert_above is 0 (VFX_ID_NULL), it will be insert to bottom.
    // The page handler pointer must be valid (cannot be NULL). 
    // RETURNS: id of this page.
    VfxId insertPageHandler(
        VfxId pageId,   // [IN] an unique id to identify the page. If it is 
                        //      VFX_ID_NULL, MainScr will automatically assign one
        VfxPageHandler *handler,    // [IN] the page handler being inserted, cannot be NULL
        VfxId insert_above  // [IN] id of another page to specify insert position.
                            // if it is top page, behavior equal to pushPage
    );

    // Pop current(top) page, with animated transition effect.
    void popPage();

    // Close page by page id. If the input page is current one, the 
    // behavior is eqaul to popPage(), else it will close the page 
    // directly without any update.
    void closePage(
        VfxId pageId        // [IN] id of page to be closed
    );

    // Query page pointer by page id, it will return NULL if the id
    // is not in page stack or if it is not created yet.   
    // RETURNS: page pointer.
    VfxPage *getPage(
        VfxId pageId = 0    // [IN] page id, or 0 for current(top) page
    ) const; 

    // Check if an page id is in page stack or not
    // RETURNS: if the id is in page stack
    VfxBool isPageIdValid(
        VfxId pageId        // [IN] page id
    ) const;

    // Query id of a page pointer
    // RETURNS: id of given page, or VFX_ID_NULL if it is not in stack
    VfxId getPageId(
        const VfxPage *page // [IN] page to query id
    ) const;

    // Query number of pages in stack
    // RETURNS: number of pages in stack
    VfxS32 getPageCount() const;

    // Query id of all pages in the stack. 
    // If top_down is true, Id of current(top) page will be stored at index 0, 
    // and id of bottom page will be put at index N-1. If top_down is false, 
    // bottom ones will be at index 0, and top ones at index N-1.
    // If the buffer is not enough, only first N page will be return.
    // RETURNS: number of id written into buffer.
    VfxS32 getPageIds(
        VfxId *buffer,      // [OUT] buffer to store page id
        VfxS32 bufferCount, // [IN]  max number of id to return
        VfxBool topDown = VFX_TRUE // [IN] order of stored id.
    ) const;

    // Query id of current(top) page in the stack. If stack is empty, return 
    // VFX_ID_NULL. 
    // Use with getPrevPageId to traverse stack top-down.
    // RETURNS: page id
    VfxId getTopPageId() const;

    // Query id of bottom page in the stack. If stack is empty, return VFX_ID_NULL
    // Use with getNextPageId to traverse stack bottom-up.
    // RETURNS: page id
    VfxId getBottomPageId() const;

    // Query id of page next to given page id. 'Next' means toward top.
    // It will return VFX_ID_NULL if the given page id not exist or it 
    // is current page.
    // Use with getBottomPageId to traverse stack bottom-up.
    // RETURNS: page id
    VfxId getNextPageId(
        VfxId pageId        // [IN] page id to be queried
    ) const;

    // Query id of page previous to given page id. 'Prev' means toward 
    // bottom. It will return VFX_ID_NULL if the given page id not exist 
    // or it is already bottom page.
    // Use with getTopPageId to traverse stack top-down.
    // RETURNS: page id
    VfxId getPrevPageId(
        VfxId pageId        // [IN] page id to be queried
    ) const;

    // When there is no page, and auto close is on, MainScr will close itself.
    // Auto close is on by default.
    void setAutoClose(VfxBool autoClose);

    // Query if auto close is on
    // Auto close is on by default.
    // RETURNS: if page is auto close or not.
    VfxBool getAutoClose() const;

    // Query client rectangle of a given page.
    // The coordination of return rectangle is relative to main screen.
    // RETURNS: the client area.
    VfxRect getClient(
        VfxPage *page   // [IN] page pointer, use getPage(0) to find current page.
    ) const;

    // Recalucate layout, current page will be repositioned (and resized) 
    // based on its bar setting.
    void recalcLayout(VfxBool bUpdateNow = VFX_FALSE);

    // Recalucate layout, current page will be repositioned (and resized) 
    // based on its bar setting.
    VfxControl *getStatusBar() const;

// Static Method
public:
    // Given a frame, find its VfxMainScr parent pointer.
    static VfxMainScr *findMainScr(
        VfxFrame *f     // [IN] frame pointer to query.
    );

// Overridable    
protected:
    // Lazy creation, when page is pushed without page pointer, see pushPage.
    // VfxMainScr will use this interface to create page pointer.
    virtual VfxPage *onCreatePage(
        VfxId   // id of page
    ) 
    { 
        return NULL; 
    }

    // when VfxMainScr is ready to run, this interface will be called.
    virtual void on1stReady() {}

    // when VfxMainScr is ready to run, this interface will be called.
    virtual void on2ndReady() {}

    // when user do back process on child page.
    // The default implementation is close the page.
    virtual VfxBool onPageBack(
        VfxPage* page   // [IN] the page who is doing back process.
    );

/* DOM-NOT_FOR_SDK-BEGIN */
// Override
protected:
    virtual void onInit();
    void onAfterInit();
    virtual void setBounds(const VfxRect &value);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    
    virtual VfxRect onGetClientRect() const;
    virtual void processEnter(VfxBool isBackward);
    virtual void processEntered(VfxBool isBackward);
    virtual void processExit(VfxBool isBackward);

    virtual mmi_ret processProc(mmi_event_struct *evt);
    virtual VfxBool processSerialize(VfxArchive &ar);
    virtual void processRestore(VfxArchive &ar);

    virtual void queryRotate(VfxScreenRotateParam &param);
    virtual void processRotate(const VfxScreenRotateParam &param);

    VfxBool queryFocusChange(VfxFrame *childFrame);
    virtual void onScreenDisabled(VfxBool isDisabled);
    virtual void onObjectNotify(VfxId eventId, void *userData);

public:
    virtual VfxBool getAllowDelete() const;
    
// Implemetation
private:
    enum
    {
        FLAGS_IS_INITED        = 1 << 0,    // If scr is inited
        FLAGS_IS_ACTIVE        = 1 << 1,    // If scr is active
        FLAGS_IS_PAGE_DIRTY    = 1 << 2,    // If scr is dirty (page)
        FLAGS_IS_LAYOUT_DIRTY  = 1 << 3,    // If scr is dirty (layout)
        FLAGS_IS_FORWARD       = 1 << 4,    // If scr is in forward direction
        FLAGS_IN_ROTATE_TRANSIT= 1 << 5,    // If scr is in rotate transition
        FLAGS_IS_AUTO_CLOSE    = 1 << 6,    // If scr is auto close (close when no page)
        FLAGS_IN_PAGE_UPDATE   = 1 << 7,    // If scr is in onUpatePage()
        FLAGS_IS_INITED_2      = 1 << 8,    // If scr is inited (and is SSE entered)
        FLAGS_HAS_SNAPSHOTED   = 1 << 9,    // If scr is snapshoted by SSE already 
                                            // (so that we can remove cp without doubt)

        FLAGS_MAX
    };

// Variable
private:
    VfxWeakPtr<VfxPage> m_currPage;
    VfxWeakPtr<VfxPage> m_phaseInPage, m_phaseOutPage;

    VfxIdObjStack       *m_pageStack, *m_deadStack;

    VcpStatusIconBar    *m_statusBar;
    VfxU32              m_msFlags;
    //VfxBool             wm_isPageDirty;
    //VfxBool             m_isLayoutDirty;
    //VfxBool             m_isInited;
    //VfxBool             m_isForward;
    //VfxBool             m_inRotateTransition;
    //VfxBool             m_autoClose;
    //VfxBool             m_isActive;

// Implementation
private:
    VfxId pushPageInt(VfxId id, VfxPage *page, const VfxClassInfo *info);
    VfxId insertPageInt(VfxId id, VfxPage *page, const VfxClassInfo *info, VfxId insert_pos);
    void onUpdatePage();    /* handle page dirty */
    void onUpdateLayout();  /* handle layout dirty */
    void processUpdateLayout(VfxBool bUpdateNow);
    void stopTransition();
    void setStatusBar(VfxPage *page, VfxBool noAnimation);
    void processPageRestore(VfxId pageId);

// Method
public:
    // This API is internal used, only called by VfxPage. 
    void processPageSerialize(VfxPage *page);

    // This API is internal used, only called by VfxPage. 
    void processPageBack(VfxPage *page);

/* DOM-NOT_FOR_SDK-END */
};

class VfxMainScrEx;

class IVfxMainScrHandler
{
public:
    virtual void onScrInit(VfxMainScrEx *scr) {}
    virtual void onScrDeinit(VfxMainScrEx *scr) {}
    virtual void onScr1stReady(VfxMainScrEx *scr) {}
    virtual void onScr2ndReady(VfxMainScrEx *scr) {}
};

class VfxMainScrEx : public VfxMainScr
{
// Constructor
public:    
    VfxMainScrEx(IVfxMainScrHandler *handler);
    virtual ~VfxMainScrEx();

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void on1stReady();
    virtual void on2ndReady();
    
private:
    IVfxMainScrHandler* m_handler;
};

#endif /* __VFX_MAIN_SCR_H__ */
