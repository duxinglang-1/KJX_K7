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
 *  vfx_page.cpp
 *
 * Project:
 * --------
 *  Venus FW
 *
 * Description:
 * ------------
 *  Implementation of VfxPage, see vfx_page.h
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_page.h"
#include "vfx_page_transition.h"

#include "vfx_mc_trace.h"
#include "vfx_logger.h"

extern "C"
{
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
}

#include "vfx_cpp_base.h"
#include "vfx_page_bar.h"
#include "vfx_weak_ptr.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_frame.h"
#include "vfx_signal.h"
#include "vfx_system.h"
#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_main_scr.h"
#include "vfx_auto_animate.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_timer.h"
#include "vfx_screen.h"
#include "vfx_archive.h"
#include "vfx_input_event.h"
#include "vfx_keypad.h"


#include "vadp_sys_trc.h"

#undef _CHECK_PAGE_ACTIVE_

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#if defined(VFX_CFG_SOFTWARE_LA)
#undef __MAUI_SOFTWARE_LA__
#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_PAGE_PROP_ID_IMEOFFSET    0x20101

#ifdef __COSMOS_MMI__
#define VFX_PAGE_KEY_BACK VFX_KEY_CODE_BACK
#else
#define VFX_PAGE_KEY_BACK VFX_KEY_CODE_RSK
#endif

#ifdef _CHECK_PAGE_ACTIVE_
#define _ASSERT_PAGE_ACTIVE     VFX_ASSERT(m_pageFlags & FLAGS_IS_ACTIVE)
#define _ASSERT_PAGE_INACTIVE   VFX_ASSERT(!(m_pageFlags & FLAGS_IS_ACTIVE))
#else
#define _ASSERT_PAGE_ACTIVE  
#define _ASSERT_PAGE_INACTIVE  
#endif

template <class _itemType>
class _Property : public VfxBase
{
public:
    _Property() : isDirty(VFX_TRUE), newValue(0), currValue(0) {}
    
    VfxBool set(_itemType v) 
    {
        newValue = v;
        if(v != currValue)
        {
            isDirty = VFX_TRUE;
        }
        else
        {
            isDirty = VFX_FALSE;
        }
        return isDirty;
    };
    
    void commit() {
        isDirty = VFX_FALSE;
        currValue = newValue;
    };
    
    _itemType get() const { return currValue; }
    _itemType get2() const { return newValue; }
    VfxBool dirty() const { return isDirty; }

public:
    VfxBool     isDirty;
    _itemType   newValue;
    _itemType   currValue;
};

/***************************************************************************** 
 * Class VfxPage::Bar
 *****************************************************************************/
class VfxPage::Bar : public VfxBase
{
    typedef VfxWeakPtr<VfxPageBar> VfxPageBarPtr;
public:
    Bar() : 
        m_phaseIn(NULL), 
        m_phaseOut(NULL), 
        m_closeOldBar(VFX_FALSE),
        m_reposition(VFX_FALSE),
        m_orientation(VFX_SCR_ROTATE_TYPE_NORMAL)
    {
        m_enable.set(VFX_TRUE);
        m_enable.commit();
    }

    void set(VfxPageBar* newBar, VfxBool deleteOld)
    {
        if(deleteOld)
        {
            VfxPageBar* oldBar = m_bar.get2().get();
            if(m_bar.get() == oldBar)
                m_closeOldBar = VFX_TRUE;
            else if(oldBar)
                VFX_OBJ_CLOSE(oldBar);
        }
        m_bar.set(newBar);
        if(!m_bar.dirty())
            m_closeOldBar = VFX_FALSE;
        m_visible.set(VFX_TRUE);
    }
    
    void toggle(VfxBool on)
    {
        m_visible.set(on);
    }

    void reposition()
    {
        m_reposition = VFX_TRUE;
    }

    void enable(VfxBool on)
    {
        m_enable.set(on);
    }

    void update(VfxPage *page, VfxPageBarLocationEnum loc, VfxBool noAnimation)
    {
        VfxFrame    *f = page->getParentFrame();
        VfxPageBar  *bar;

        if(m_bar.dirty())
        {
            m_visible.commit();
            m_enable.commit();
            
            /* current bar, phase out */
            bar = m_bar.get().get();
            if(bar)
            {
                bar->m_signalBoundsChanged.disconnect(page, &VfxPage::onBarBoundChanged);
                if(bar->startTransition(VFX_FALSE, 0, noAnimation, m_closeOldBar))
                    m_phaseOut = bar;
            }

            /* new bar, phase in */
            bar = m_bar.get2().get();
            if(bar)
            {
                bar->setAutoAnimate(VFX_TRUE);
                bar->setTranslucent(page->isTranslucent());
            
                f->addChildFrame(bar);
                //VfxSize s = f->getSize();
                //bar->setSize(s.width, bar->getSize().height);
                reposistionBar(bar, loc, noAnimation);

                bar->m_signalBoundsChanged.connect(page, &VfxPage::onBarBoundChanged);
                if(bar->startTransition(VFX_TRUE, 0, noAnimation || !m_enable.get() || !m_visible.get()))
                    m_phaseIn = bar;
                if(!m_enable.get() || !m_visible.get())
                    bar->setHidden(VFX_FALSE);
            }
            m_bar.commit();
            m_closeOldBar = VFX_FALSE;
            m_reposition = VFX_FALSE;
        }

        if(m_reposition)
        {
            bar = m_bar.get().get();
            if(bar)
            {
                reposistionBar(bar, loc, noAnimation);
            }
            m_reposition = VFX_FALSE;
        }

        if(m_visible.dirty() || m_enable.dirty())
        {
            bar = m_bar.get().get();
            if(bar)
            {
                VfxBool prev = m_enable.get() && m_visible.get();
                VfxBool next = m_enable.get2() && m_visible.get2();
                if(prev != next)
                {
                    if(bar->startTransition(next, 0, noAnimation))
                        m_phaseIn = bar;
                }
            }
            m_visible.commit();
            m_enable.commit();
        }
        VFX_MC_TRACE4(VFX_INFO, TRC_VFX_78686DE3CAF94CF59B5CB41D1B8B212E, 
            "[VfxPage](%x):bar(%d):visible=%d,enable=%d", page, loc, m_visible.get(), m_enable.get());
    }

    void startTransition(VfxPageBarLocationEnum loc, VfxBool in, VfxS32 direction)
    {
        stopTransition();

        VfxPageBar *bar = m_bar.get().get();
        if(bar && m_visible.get())
        {
            reposistionBar(bar, loc);
            bar->startTransition(in, direction);
            m_phaseIn = bar;
        }
    }
    
    void stopTransition()
    {
        // stop phaseOut first
        if(m_phaseOut.isValid())
        {
            m_phaseOut->stopTransition();
            m_phaseOut = NULL;
        }
        if(m_phaseIn.isValid())
        {
            m_phaseIn->stopTransition();
            m_phaseIn = NULL;
        }
    }

    void restartTransition()
    {
        VfxPageBar *bar = m_bar.get().get();
        if(bar && m_visible.get())
            bar->restartTransition();
    }

    VfxSize getSize() const
    { 
        if(m_bar.get().isValid() && m_visible.get() && m_enable.get()) 
            return m_bar.get()->getSize();
        return VfxSize(0, 0);
    }

    VfxBool isOn() const 
    { 
        return m_bar.get().isValid() ? m_visible.get() : VFX_FALSE; 
    }
    
    VfxPageBar *getBar() const 
    { 
        return m_bar.get2().isValid() ? m_bar.get2().get() : m_bar.get().get(); 
    }

    void reposistionBar(VfxPageBar *bar, VfxPageBarLocationEnum loc, VfxBool noAnimation = VFX_FALSE)
    {
        VfxPage *page = VFX_OBJ_DYNAMIC_CAST(bar->getParent(), VfxPage);
        VFX_ASSERT(page);
    
        VfxFrame *f = page->getParentFrame();
        VfxMainScr *scr = page->getMainScr();

        if(bar->getParentFrame() != f)
            f->addChildFrame(bar);

        VfxRect client;
        if(f == scr)
        {
            client = scr->getClient(page);
        }
        else
        {
            client.size = f->getSize();
            client.origin = VfxPoint(0, 0);
        }

        VfxSize barSize = bar->getSize();

        if(noAnimation)
        {
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
        }

        // adjust size
        barSize.width = client.size.width;
        bar->setSize(barSize);

        // adjust position        
        if(loc == VFX_PAGE_BAR_LOCATION_TOP)
            bar->setPos(client.origin.x, client.origin.y);
        else if(loc == VFX_PAGE_BAR_LOCATION_BOTTOM)
            bar->setPos(client.origin.x, client.origin.y + client.size.height - barSize.height);

        bar->setLoc(loc);
        bar->setRotate(page->getRotate());

        if(noAnimation)
        {
            VfxAutoAnimate::commit();
        }
    }

    void setHidden(VfxBool value)
    {
        VfxPageBar *bar = m_bar.get().get();
        if(!bar)
            return;

        if(value)
            bar->setHidden(VFX_TRUE);
        else if(m_visible.get() && m_enable.get())
            bar->setHidden(VFX_FALSE);            
    }

private:
    _Property<VfxPageBarPtr> m_bar;
    _Property<VfxBool>      m_visible;
    _Property<VfxBool>      m_enable;
    VfxPageBarPtr           m_phaseIn, m_phaseOut;
    VfxBool                 m_closeOldBar;
    VfxBool                 m_reposition;
    VfxScrRotateTypeEnum    m_orientation;
};

/***************************************************************************** 
 * Class VfxPage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("Page", VfxPage, VfxControl);

VfxPage::VfxPage() :
    m_topBar(NULL),
    m_bottomBar(NULL),
    m_autoHideTimer(NULL),
    m_pAccessKeyMgr(NULL),
    m_orientation(VFX_SCR_ROTATE_TYPE_NORMAL),
    m_pageFlags(FLAGS_HAS_STATUS_BAR),
//    m_isInited(VFX_FALSE),
//    m_isTranslucent(VFX_FALSE),
//    m_hasStatusBar(VFX_TRUE),
//    m_inHiddenState(VFX_FALSE),
//    m_isDirty(VFX_FALSE),
//    m_inIMELayout(VFX_FALSE),
    m_statusBarBgImage(VFX_RES_ID_NULL),
    m_allowDelete(VFX_TRUE)
//    m_isActive(VFX_FALSE)
{
}

VfxPage::~VfxPage()
{
}

VfxId VfxPage::getId() const
{
    VfxMainScr *main = getMainScr();
    if(main == getParentFrame())
        return main->getPageId(this);

    return VFX_ID_NULL;
}

VfxBool VfxPage::isActive() const
{
    VfxFrame *f = getParentFrame();
    if(!f)
        return VFX_FALSE;

    if(f->isKindOf(VFX_OBJ_CLASS_INFO(VfxMainScr)))
    {
        return ((VfxMainScr*)f)->getPage() == this;
    }
    else if(f->isKindOf(VFX_OBJ_CLASS_INFO(VfxPage)))
    {
        return (const VfxPage*)( ((VfxPage*)f)->getActiveChild()) == this;
    }
    else
    {
        return (const VfxPage*) (f->getFocusChildFrame()) == this;
    }
}

void VfxPage::exit()
{
    VFX_LOG_FUNC;
    VfxMainScr *main = getMainScr();
    if(main == getParentFrame())
    {
        main->closePage(getId());
    }
    else
    {
        // TODO: temp solution
        VfxPage *p = VFX_OBJ_DYNAMIC_CAST(getParentFrame(), VfxPage);
        if(p)
            p->exit();
    }        
}

void VfxPage::back()
{
    VFX_LOG_FUNC;
    if(!m_allowDelete)
        return;

    onBack();
}

void VfxPage::setTransition(VfxPageTransition* transition)
{
    if(m_transition.isValid())
        VFX_OBJ_CLOSE(m_transition);

    m_transition = transition;
    if(m_transition.isValid())
        m_transition->m_signalStopped.connect(this, &VfxPage::processTransitionStop);
}

VfxMainScr *VfxPage::getMainScr() const
{
    return VfxMainScr::findMainScr(getParentFrame());
}

void VfxPage::setBar(VfxPageBarLocationEnum loc, VfxPageBar *newBar, VfxBool deleteOldBar)
{
    VFX_LOG_FUNC;
    // Remeber to call VfxPage::onInit() at your derived class's onInit()
    VFX_DEV_ASSERT(m_topBar && m_bottomBar);

    if(newBar)
        newBar->setPosZ(getPosZ()-0.1f); // move bar to foreground
    if(loc == VFX_PAGE_BAR_LOCATION_TOP)
    {
        if(newBar != m_topBar->getBar())
        {
            m_topBar->set(onSetBar(loc, newBar), deleteOldBar);
            checkUpdate();
            m_pageFlags |= FLAGS_IS_DIRTY;
        }
    }
    else if(loc == VFX_PAGE_BAR_LOCATION_BOTTOM)
    {
        if(newBar != m_bottomBar->getBar())
        {
            m_bottomBar->set(onSetBar(loc, newBar), deleteOldBar);
            checkUpdate();
            m_pageFlags |= FLAGS_IS_DIRTY;
        }
    }
}

void VfxPage::toggleBar(VfxPageBarLocationEnum loc, VfxBool on)
{
    VFX_LOG_FUNC;
    if(loc == VFX_PAGE_BAR_LOCATION_TOP)
    {
        m_topBar->toggle(on);
        checkUpdate();
        m_pageFlags |= FLAGS_IS_DIRTY;
    }
    else if(loc == VFX_PAGE_BAR_LOCATION_BOTTOM)
    {
        m_bottomBar->toggle(on);
        checkUpdate();
        m_pageFlags |= FLAGS_IS_DIRTY;
    }
}

VfxPageBar *VfxPage::getBar(VfxPageBarLocationEnum loc) const
{
    if(loc == VFX_PAGE_BAR_LOCATION_TOP)
    {
        return m_topBar->getBar();
    }
    else if(loc == VFX_PAGE_BAR_LOCATION_BOTTOM)
    {
        return m_bottomBar->getBar();
    }
    return NULL;
}

VfxBool VfxPage::isBarOn(VfxPageBarLocationEnum loc) const
{
    if(loc == VFX_PAGE_BAR_LOCATION_TOP)
    {
        return m_topBar->isOn();
    }
    else if(loc == VFX_PAGE_BAR_LOCATION_BOTTOM)
    {
        return m_bottomBar->isOn();
    }
    return VFX_FALSE;
}

void VfxPage::setStatusBar(VfxBool on)
{
    if(on)
    {
        if(m_pageFlags & FLAGS_HAS_STATUS_BAR)
            return;

        m_pageFlags |= FLAGS_HAS_STATUS_BAR;
    }
    else
    {
        if(!(m_pageFlags & FLAGS_HAS_STATUS_BAR))
            return;

        m_pageFlags &= ~FLAGS_HAS_STATUS_BAR;
    }
    
    if(m_pageFlags & FLAGS_IS_INITED)
    {
        VfxMainScr *main = getMainScr();
        if(main == getParentFrame())
            main->recalcLayout();
    }
}

void VfxPage::setStatusBarBg(VfxResId bgImage)
{
    m_statusBarBgImage = bgImage;

    if((m_pageFlags & FLAGS_IS_INITED) && (m_pageFlags & FLAGS_HAS_STATUS_BAR))
    {
        VfxMainScr *main = getMainScr();
        if(main == getParentFrame())
            main->recalcLayout();
    }
}

VfxResId VfxPage::getStatusBarBg(void)
{
    return m_statusBarBgImage;
}

void VfxPage::setBarAutoHide(VfxBool on)
{
    if(on)
    {
        if(!m_autoHideTimer)
        {
            VFX_OBJ_CREATE(m_autoHideTimer, VfxTimer, this);
            m_autoHideTimer->m_signalTick.connect(this, &VfxPage::onTimer);
            m_autoHideTimer->setStartDelay(3000);

            if(!(m_pageFlags & FLAGS_IN_BAR_CAPTURE))
                m_autoHideTimer->start();
        }
    }
    else
    {
        VFX_OBJ_CLOSE(m_autoHideTimer);
    }
}

void VfxPage::hideAllBars(VfxBool hide)
{
    VFX_LOG_FUNC;
    if(getIsBarHidden() == hide)
    {
        if(hide == VFX_FALSE)
        {
            /* reset auto hide timer */
            if(m_autoHideTimer && !(m_pageFlags & FLAGS_IN_BAR_CAPTURE))
                m_autoHideTimer->start();
        }
        return;
    }

    if(hide)
        m_pageFlags |= FLAGS_IN_HIDDEN_STATE;
    else
        m_pageFlags &= ~FLAGS_IN_HIDDEN_STATE;
    
    if(m_pageFlags & FLAGS_IS_INITED)
    {
        VfxMainScr *main = getMainScr();
        if(main == getParentFrame())
            main->recalcLayout(hide ? VFX_FALSE : VFX_TRUE);
        if(hide)
            onBarAutoHide();
    }
}

VfxScrRotateTypeEnum VfxPage::getRotate() const
{
    return m_orientation;
}

void VfxPage::setTranslucent(VfxBool on)
{
    if(on)
    {
        if(m_pageFlags & FLAGS_IS_TRANSLUCENT)
            return;

        m_pageFlags |= FLAGS_IS_TRANSLUCENT;
    }
    else
    {
        if(!(m_pageFlags & FLAGS_IS_TRANSLUCENT))
            return;

        m_pageFlags &= ~FLAGS_IS_TRANSLUCENT;
    }
    
    if(m_pageFlags & FLAGS_IS_INITED)
    {
        VfxMainScr *main = getMainScr();
        if(main == getParentFrame())
            main->recalcLayout();
    }
}

void VfxPage::prepareTransition(VfxBool in, VfxS32 direction, const VfxScreenRotateParam *param)
{
    if(!m_transition.isValid())
    {
        VFX_OBJ_CREATE(m_transition, VfxPageSlideTransition, this);
        m_transition->m_signalStopped.connect(this, &VfxPage::processTransitionStop);
    }

    m_transition->prepare(in, direction, param);
}

VfxBool VfxPage::startTransition(VfxBool autoClose)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XPS", SA_start);
#endif
    VFX_LOG_FUNC;
    VfxBool in = m_transition->getIn();
    VfxS32 direction = m_transition->getDir();

    VFX_MC_TRACE4(VFX_FUNC, TRC_VFX_6C4AE3A674B04A868B13B105B6AC5C0B, 
        "[VfxPage](%x) startTransition(%d,%d,%d)", this, in, direction, autoClose);

    doUpdate(VFX_TRUE);

    if(in)
        hideAllBars(VFX_FALSE);
    if(m_autoHideTimer)
        m_autoHideTimer->stop();

    // make sure phase-in page above phase-out page.
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    setPosZ(in ? 0.1f : 1.1f);
    VfxAutoAnimate::commit();

    m_transition->start(this, VFX_FALSE, autoClose);
    m_topBar->startTransition(VFX_PAGE_BAR_LOCATION_TOP, in, direction);
    m_bottomBar->startTransition(VFX_PAGE_BAR_LOCATION_BOTTOM, in, direction);

    if(in)
    {
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("XP1", SA_start);
#endif
        onEnter(direction < 0);
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("XP1", SA_stop);
#endif
        _ASSERT_PAGE_INACTIVE;
        m_pageFlags |= FLAGS_IS_ACTIVE;
    }
    else
    {
        _ASSERT_PAGE_ACTIVE;
        m_pageFlags &= ~FLAGS_IS_ACTIVE;
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("XP2", SA_start);
#endif
        onExit(direction < 0);
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("XP2", SA_stop);
#endif
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XPS", SA_stop);
#endif
    return VFX_TRUE;
}

VfxBool VfxPage::stopTransition()
{
    if(m_autoHideTimer)
        m_autoHideTimer->stop();

    m_topBar->stopTransition();
    m_bottomBar->stopTransition();

    if(m_transition.isValid())
        return m_transition->stop();

    return VFX_FALSE;
}

void VfxPage::reposistionBars(VfxBool noAnimation /* = VFX_FALSE */)
{
    VFX_MC_TRACE1(VFX_FUNC, TRC_VFX_8AD69028F634407F97328C5549F84EE7, 
        "[VfxPage](%x) reposistionBars()", this);
    m_topBar->enable(!getIsBarHidden());
    m_topBar->reposition();
    m_bottomBar->enable(!getIsBarHidden());
    m_bottomBar->reposition();
    
    if(noAnimation)
    {
        doUpdate(VFX_TRUE);
    }
    else
    {
        checkUpdate();
        m_pageFlags |= FLAGS_IS_DIRTY;
    }
}

VfxBool VfxPage::previewBarPenInput(VfxPenEvent &event)
{
    switch(event.type)
    {
    case VFX_PEN_EVENT_TYPE_DOWN:
        m_pageFlags |= FLAGS_IN_BAR_CAPTURE;
        if(m_autoHideTimer)
            m_autoHideTimer->stop();
        break;

    case VFX_PEN_EVENT_TYPE_UP:
    case VFX_PEN_EVENT_TYPE_ABORT:
        m_pageFlags &= ~FLAGS_IN_BAR_CAPTURE;
        if(m_autoHideTimer)
            m_autoHideTimer->start();
        break;
    }

    return VFX_FALSE;
}

void VfxPage::processEnter(VfxBool isBackward, VfxBool doFirstHalf, VfxBool doSecondHalf)
{
    VFX_LOG_FUNC;

    if(doFirstHalf)
    {
        setHidden(VFX_FALSE);
        onEnter(isBackward);
        
        _ASSERT_PAGE_INACTIVE;
        m_pageFlags |= FLAGS_IS_ACTIVE;
    }

    if(doSecondHalf)
    {
        onEntered();
    }
}

void VfxPage::processExit(VfxBool isBackward, VfxBool doFirstHalf, VfxBool doSecondHalf)
{
    VFX_LOG_FUNC;

    if(doFirstHalf)
    {
        VfxWeakPtr<VfxPage> page = this;
        
        _ASSERT_PAGE_ACTIVE;
        m_pageFlags &= ~FLAGS_IS_ACTIVE;

        if(m_transition.isValid() && m_transition->inAnimation())
            stopTransition();
        
        onExit(isBackward);
        
        if(!page.isValid())
            doSecondHalf = VFX_FALSE;
    }

    if(doSecondHalf)
    {
        onExited();
    }
}

void VfxPage::processExited()
{
    VFX_LOG_FUNC;
    onExited2();
}

VfxBool VfxPage::processSerialize(VfxArchive &ar)
{
    VFX_LOG_FUNC;
    // TODO: Some page variable may need to be stored
    return onSerialize(ar);
}

void VfxPage::processRestore(VfxArchive &ar)
{
    VFX_LOG_FUNC;
    // TODO: Some page variable may need to be restored
    onRestore(ar);
}

void VfxPage::queryRotate(VfxScreenRotateParam &param)
{
    onQueryRotateEx(param);
}

void VfxPage::processRotate(const VfxScreenRotateParam &param)
{
    VFX_LOG_FUNC;
    m_orientation = param.rotateTo;
    reposistionBars(VfxAutoAnimate::getDisable());
    VfxScreenRotateParam p = param;
    vfxPostInvoke2(this, &VfxPage::doRotate, p, VfxAutoAnimate::getDisable());
}

VfxRect VfxPage::getPageRect() const
{
    return onGetPageRect();
}

VfxFrame* VfxPage::getActiveChild() const
{
    return onGetActiveChild();
}

mmi_ret VfxPage::processProc(mmi_event_struct *evt)
{
    return onProc(evt);
}

void VfxPage::onEnter(VfxBool isBackward)
{
}

void VfxPage::onEntered()
{
}

void VfxPage::onExit(VfxBool isBackward)
{
}

void VfxPage::onExited()
{
}

void VfxPage::onExited2()
{
}

VfxBool VfxPage::onSerialize(VfxArchive &ar)
{
    VFX_UNUSED(ar);
    return VFX_FALSE;
}

void VfxPage::onRestore(VfxArchive &ar)
{
    VFX_UNUSED(ar);
}

void VfxPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
    param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
}

void VfxPage::onRotate(const VfxScreenRotateParam &param)
{
    VFX_UNUSED(param);
}

void VfxPage::onTransitionStop(VfxBool in, VfxS32 direction)
{
    VFX_UNUSED(in);
    VFX_UNUSED(direction);
}

void VfxPage::onBack()
{
    VfxMainScr *main = getMainScr();
    if(main == getParentFrame())
    {
        main->processPageBack(this);
    }
    else
    {
        VfxPage *p = VFX_OBJ_DYNAMIC_CAST(getParentFrame(), VfxPage);
        main->processPageBack(p);
    }
}

void VfxPage::onBarAutoHide()
{
}

mmi_ret VfxPage::onProc(mmi_event_struct *evt)
{
    VFX_UNUSED(evt);
    return MMI_RET_DONT_CARE;
}

VfxRect VfxPage::onGetPageRect() const
{
    return VfxRect(VfxPoint(0, 0), getSize());
}

VfxFrame *VfxPage::onGetActiveChild() const
{
    return getFocusChildFrame();
}

VfxPageBar *VfxPage::onSetBar(VfxPageBarLocationEnum loc, VfxPageBar *newBar)
{
    return newBar;
}

void VfxPage::onInit()
{
    VFX_LOG_FUNC;
    VfxControl::onInit();

    VFX_ALLOC_NEW(m_topBar, Bar, this);
    VFX_ALLOC_NEW(m_bottomBar, Bar, this);

    setSize(getParentFrame()->getSize());
    setAutoAnimate(VFX_TRUE);

    setPosZ(0.1f);
}

void VfxPage::onDeinit()
{
    VFX_LOG_FUNC;
    VFX_DELETE(m_topBar);
    VFX_DELETE(m_bottomBar);

    VfxControl::onDeinit();
}

void VfxPage::onAfterInit()
{
    VFX_LOG_FUNC;
    VfxControl::onAfterInit();

    if(m_checkUpdate)
        processUpdate();

    setHidden(VFX_TRUE);

    m_pageFlags |= FLAGS_IS_INITED;
}


void VfxPage::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_OBJECT_NOTIFY_ID_AFTER_INIT:
        {
            onAfterInit();
            return;
        }
        case VFX_FRAME_NOTIFY_ID_QUERY_IME_MODE:
        {
            VfxFrameImeModeEnum ret = getImeMode();
            *((VfxFrameImeModeEnum *)userData) = ret;
            return;
        }
        case VFX_FRAME_NOTIFY_ID_ADJUST_IME_RESIZE:
        {
            VfxFrameAdjustImeResizeData *para = (VfxFrameAdjustImeResizeData *)userData;
            adjustImeResize(para->size, para->focusFrame);
            return;
        }
       
        default:
        {
            VfxControl::onObjectNotify(id, userData);
            return;
        }
    }
}


void VfxPage::onUpdate()
{
    VFX_LOG_FUNC;
    VfxControl::onUpdate();

    if(m_pageFlags & FLAGS_IS_DIRTY)
    {
        VFX_MC_TRACE2(VFX_FUNC, TRC_VFX_BBD8AFE125E24BFE8F171BCC9F90E7DD, 
            "[VfxPage](%x) onUpdate(%d)", this, (m_pageFlags & FLAGS_IS_INITED) ? 1 : 0);

        doUpdate(!(m_pageFlags & FLAGS_IS_INITED));

        if(m_transition.isValid() && m_transition->inAnimation())
        {
            m_topBar->restartTransition();
            m_bottomBar->restartTransition();
            m_transition->restart();
        }

        m_pageFlags &= ~FLAGS_IS_DIRTY;
    }
}

VfxBool VfxPage::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_PAGE_KEY_BACK &&
        event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        back();
        return VFX_TRUE;
    }
    
    return VfxControl::onKeyInput(event);
}

void VfxPage::setPosZ(VfxFloat value)
{
    VfxControl::setPosZ(value);

    // make sure bar above page
    if(m_topBar->getBar())
        m_topBar->getBar()->setPosZ(value-0.1f);
    if(m_bottomBar->getBar())
        m_bottomBar->getBar()->setPosZ(value-0.1f);
}

void VfxPage::setHidden(VfxBool value)
{
    VfxControl::setHidden(value);

    m_topBar->setHidden(value);
    m_bottomBar->setHidden(value);
}

void VfxPage::processRegisterAccessKeyHandler(VfxKeyCodeEnum keyCode, VfxControl *target)
{
    if(!m_pAccessKeyMgr)
        VFX_OBJ_CREATE(m_pAccessKeyMgr, VfxAccessKeyMgr, this);

    m_pAccessKeyMgr->registerHandler(keyCode, target);
}

void VfxPage::processUnregisterAccessKeyHandler(VfxKeyCodeEnum keyCode, VfxControl *target)
{
    if(m_pAccessKeyMgr)
        m_pAccessKeyMgr->unregisterHandler(keyCode, target);
}

void VfxPage::processUnregisterAllAccessKeyHandler(VfxControl *target)
{   
    if(m_pAccessKeyMgr)
        m_pAccessKeyMgr->unregisterAllHandler(target);
}
    
VfxBool VfxPage::processFocusKey(VfxKeyEvent &event)
{
    VfxBool ret = VFX_FALSE;

    // If there is focused child, let it handle first
    if (getFocusChildFrame())
    {
        ret = getFocusChildFrame()->processFocusKey(event);
    }

    // If there is access key registered, process it
    if (!ret && m_pAccessKeyMgr)
    {
        ret = m_pAccessKeyMgr->processKeyInput(event);
    }

    // If there is no other one handle it, handle it by screen it self.
    if (!ret)
    {
        ret = onKeyInput(event);
    }
    return ret;
}

void VfxPage::adjustImeResize(const VfxSize &size, VfxFrame *focusFrame)
{
    if(focusFrame)
    {
        // save IME suggested size
        m_pageFlags |= FLAGS_IN_IME_LAYOUT;
        VfxS32 offset = size.height + m_topBar->getSize().height;
        setAttachProperty(VFX_PAGE_PROP_ID_IMEOFFSET, (void*)&offset, sizeof(VfxS32));
        
        // set size accoding to IME suggested
        setSize(size);
    }
    else
    {
        // reset
        m_pageFlags &= ~FLAGS_IN_IME_LAYOUT;
        setAttachProperty(VFX_PAGE_PROP_ID_IMEOFFSET, NULL, 0);

        // use own setting while restore
        adjustClient();

        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->blockAfterNextCommit(VfxAutoAnimate::getDuration());
    }
}

void VfxPage::processTransitionStop(VfxBool in, VfxS32 direction)
{
    VFX_LOG_FUNC;
    VfxWeakPtr<VfxPage> page = this;

    m_signalTransitionStop.postEmit(this, in, direction);
    onTransitionStop(in, direction);

    if(!page.isValid())
        return;
    
    if(in)
    {
        if(m_autoHideTimer && !(m_pageFlags & FLAGS_IN_BAR_CAPTURE))
            m_autoHideTimer->start();
        onEntered();
    }
    else
    {
        onExited();
        
        if(page.isValid())
            onExited2();
        
        if(page.isValid() && direction >= 0)
        {
            VfxMainScr *main = getMainScr();
            if(main == getParentFrame())
                main->processPageSerialize(this);
        }
    }
    
}

void VfxPage::doUpdate(VfxBool noAnimation)
{
    VFX_LOG_FUNC1("%d", noAnimation);
    m_topBar->update(this, VFX_PAGE_BAR_LOCATION_TOP, noAnimation);
    m_bottomBar->update(this, VFX_PAGE_BAR_LOCATION_BOTTOM, noAnimation);
    if(noAnimation)
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
    }
    adjustClient();
    if(noAnimation)
    {
        VfxAutoAnimate::commit();
    }

    /* reset auto hide timer */
    if(m_autoHideTimer && !(m_pageFlags & FLAGS_IN_BAR_CAPTURE))
        m_autoHideTimer->start();
}

void VfxPage::doRotate(VfxScreenRotateParam param, VfxBool noAnimation)
{
    VFX_LOG_FUNC;
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XPR", SA_start);
#endif
    if(noAnimation)
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
    }
    onRotate(param);
    if(noAnimation)
    {
        VfxAutoAnimate::commit();
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XPR", SA_stop);
#endif
}

void VfxPage::adjustClient()
{
    VfxFrame *f = getParentFrame();

    if(m_pageFlags & FLAGS_IS_TRANSLUCENT)
    {
        if(m_pageFlags & FLAGS_IN_IME_LAYOUT)
            return;
    
        VFX_MC_TRACE5(VFX_FUNC, TRC_VFX_F5FD630A0FA44B6990DD4AC43AE75B29, 
            "[VfxPage](%x) adjustClient(%d,%d,%dx%d)", this, 0, 0, f->getSize().width, f->getSize().height);

        setPos(0, 0);
        setSize(f->getSize());
    }
    else
    {
        VfxS32 barH;
        VfxRect client;
        VfxSize s;
        VfxPoint t;

        if(f->isKindOf(VFX_OBJ_CLASS_INFO(VfxMainScr)))
        {
            client = ((VfxMainScr*)f)->getClient(this);
        }
        else if(f->isKindOf(VFX_OBJ_CLASS_INFO(VfxPage)))
        {
            client = ((VfxPage*)f)->getPageRect();
        }
        else
        {
            client.size = f->getSize();
            client.origin.x = 0;
            client.origin.y = 0;
        }
        
        s = client.size;
        t = client.origin;

        barH = m_topBar->getSize().height;
        t.y += barH;
        s.height -= barH;

        barH = m_bottomBar->getSize().height;
        if(m_pageFlags & FLAGS_IN_IME_LAYOUT)
        {
            VfxS32 *imeOffset = (VfxS32*)getAttachProperty(VFX_PAGE_PROP_ID_IMEOFFSET, sizeof(VfxS32));
            VfxS32 imeH = client.size.height - (*imeOffset);
            if(barH < imeH)
                barH = imeH;
        }
        s.height -= barH;

        VFX_MC_TRACE5(VFX_FUNC, TRC_VFX_F5FD630A0FA44B6990DD4AC43AE75B29, 
            "[VfxPage](%x) adjustClient(%d,%d,%dx%d)", this, t.x, t.y, s.width, s.height);
            
        setRect(VfxRect(t, s));
    }
}

void VfxPage::onBarBoundChanged(VfxFrame *f, const VfxRect &r)
{
    if(r.size != f->getSize())
    {
        reposistionBars(m_transition.isValid() && m_transition->inAnimation() ? VFX_TRUE : VFX_FALSE);
    }
}

void VfxPage::onTimer(VfxTimer* t)
{
    if(t == m_autoHideTimer)
    {
        hideAllBars();
    }
}

VfxPageEx::VfxPageEx(IVfxPageHandler *handler):
    m_handler(handler)
{
    VFX_ASSERT(handler);
}

VfxPageEx::~VfxPageEx()
{

}

void VfxPageEx::doDefaultBack()
{
    VfxPage::onBack();
}

void VfxPageEx::onInit()
{
    VfxPage::onInit();
    m_handler->onPageInit(this);
}

void VfxPageEx::onDeinit()
{
    m_handler->onPageDeinit(this);
    m_handler = NULL;
    VfxPage::onDeinit();
}

void VfxPageEx::onEnter(VfxBool isBackward)
{
    m_handler->onPageEnter(this, isBackward);
}

void VfxPageEx::onEntered()
{
    m_handler->onPageEntered(this);
}

void VfxPageEx::onExit(VfxBool isBackward)
{
    m_handler->onPageExit(this, isBackward);
}

void VfxPageEx::onExited()
{
    m_handler->onPageExited(this);
}

void VfxPageEx::onExited2()
{
    m_handler->onPageExited2(this);
}

void VfxPageEx::onQueryRotateEx(VfxScreenRotateParam &param)
{
    m_handler->onPageQueryRotate(this, param);
}

void VfxPageEx::onRotate(const VfxScreenRotateParam &param)
{
    m_handler->onPageRotate(this, param);
}

void VfxPageEx::onBack()
{
    m_handler->onPageBack(this);
}

mmi_ret VfxPageEx::onProc(mmi_event_struct *evt)
{
    return m_handler->onPageProc(this, evt);
}

VfxPageHandler::VfxPageHandler() :
    m_page(NULL)
{

}

VfxPageHandler::~VfxPageHandler()
{

}

VfxPageEx *VfxPageHandler::createPage()
{
    VFX_ASSERT(!m_page);
    VFX_OBJ_CREATE_EX(m_page, VfxPageEx, getParent(), (this));
    return m_page;
}

void VfxPageHandler::onPageInit(VfxPageEx *page)
{
    m_page = page;
}

void VfxPageHandler::onPageDeinit(VfxPageEx *page)
{
    VfxObject *self = this;
    VFX_OBJ_CLOSE(self);
}


