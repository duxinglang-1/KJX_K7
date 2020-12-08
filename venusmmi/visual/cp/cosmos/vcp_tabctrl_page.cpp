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
 *  vfx_tabctrl_page.cpp
 *
 * Project:
 * --------
 *  Venus FW
 *
 * Description:
 * ------------
 *  Implementation of VcpTabCtrlPage, see vfx_bar.h
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
 * removed!
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
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vcp_tabctrl_page.h"

extern "C"
{
#include "kal_general_types.h"
#include "kal_public_api.h"
}

#include "vfx_datatype.h"
#include "vfx_object.h"
#include "vfx_cpp_base.h"
#include "vfx_string.h"
#include "vfx_main_scr.h"
#include "vfx_weak_ptr.h"
#include "vfx_sys_memory.h"
#include "vfx_page_bar.h"
#include "vfx_class_info.h"
#include "vfx_signal.h"
#include "vrt_datatype.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"

#include "vcp_tab_bar.h"
#include "vcp_tab_title_bar.h"
#include "vcp_state_image.h"

/*****************************************************************************
 * Define
 *****************************************************************************/
#ifndef VFX_ID_NULL
#define VFX_ID_NULL (0)
#endif

/*****************************************************************************
 * Class VcpTabCtrlPage::List::Info
 *****************************************************************************/

inline VcpTabCtrlPage::List::Info::Info()
{
}

inline VcpTabCtrlPage::List::Info::~Info()
{
}

/*****************************************************************************
 * Class VcpTabCtrlPage::List
 *****************************************************************************/

inline VcpTabCtrlPage::List::Info * VcpTabCtrlPage::List::getFirstInfo() const
{
    return (Info*)m_objList;
}

inline VcpTabCtrlPage::List::Info * VcpTabCtrlPage::List::getLastInfo() const
{
    return m_objListEnd;
}

void VcpTabCtrlPage::List::assignListInfo(VcpTabCtrlPage::List::Info * info, VfxId id, const VfxWString &name, const VcpStateImage &icon, VfxPage *page)
{
    info->id = id;
    info->name = name;
    info->icon = icon;
    info->page = page;
}

inline VcpTabCtrlPage::List::List() :
    m_objListEnd(m_objList)
{
}

inline VcpTabCtrlPage::List::~List()
{
}

VcpTabCtrlPage::List::Info *VcpTabCtrlPage::List::find(VfxId id) const
{
    Info * i = getFirstInfo();
    while(i != getLastInfo() )
    {
        if ( i->id == id)
            return i;
        ++i;
    }
    return NULL;
}

inline VfxBool VcpTabCtrlPage::List::add(VfxId id, const VfxWString &name, const VcpStateImage &icon, VfxPage *tabPage, IVfxAllocatable * alloc)
{
    if(id == VFX_ID_NULL)
    {
        return VFX_FALSE;
    }

    if(find(id))
    {
        return VFX_FALSE;
    }

    if ((m_objListEnd - m_objList) >= 8)
    {
        return VFX_FALSE;
    }

    assignListInfo(m_objListEnd, id, name, icon, tabPage);
    ++m_objListEnd;
    return VFX_TRUE;
}

inline VfxBool VcpTabCtrlPage::List::remove(VfxId id)
{
    Info * info = find(id);
    if (!info)
    {
        return VFX_FALSE;
    }

    VfxPage * page = info->page.get();
    VFX_OBJ_CLOSE(page);

    Info * lastValidInfo = getLastInfo() - 1;

    assignListInfo(info, lastValidInfo->id, lastValidInfo->name, lastValidInfo->icon, lastValidInfo->page.get() );
    --m_objListEnd;

    return VFX_TRUE;
}

inline VfxBool VcpTabCtrlPage::List::replace(VfxId id, const VfxWString &name, const VcpStateImage &icon, VfxPage *tabPage)
{
    Info * info = find(id);
    if (info == NULL)
    {
        return VFX_FALSE;
    }

    VfxPage * page = info->page.get();
    VFX_OBJ_CLOSE(page);

    assignListInfo(info, id, name, icon, tabPage);
    return VFX_TRUE;
}

/*****************************************************************************
 * Class VcpTabCtrlPage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("TabCtrlPage", VcpTabCtrlPage, VfxPage);

VcpTabCtrlPage::VcpTabCtrlPage() :
    m_currTab(VFX_ID_NULL),
    m_newTab(VFX_ID_NULL)
{
}

VcpTabCtrlPage::~VcpTabCtrlPage()
{
}

void VcpTabCtrlPage::onInit()
{
    VfxPage::onInit();

    // create tab bar, and connect onTabSwitched to it
    VFX_OBJ_CREATE(m_bar, VcpTabTitleBar, this);
    m_bar->m_signalTabSwitched.connect(this, &VcpTabCtrlPage::onTabBarSwitched);
    m_bar->setPosZ(-1.0f);

    // connect onBoundChange
    m_signalBoundsChanged.connect(this, &VcpTabCtrlPage::onBoundChanged);
    setIsZSortChild(VFX_TRUE);
}

void VcpTabCtrlPage::onObjectNotify(VfxId id, void *userData)
{
    VfxPage::onObjectNotify(id, userData);

    if (id == VFX_OBJECT_NOTIFY_ID_AFTER_INIT)
    {
        doTabSwitch(VFX_TRUE);
    }
}

VfxRect VcpTabCtrlPage::onGetPageRect() const
{
    VfxS32 barH = m_bar->getSize().height;
    return VfxRect(0, barH, getSize().width, getSize().height -barH);
}

VfxFrame *VcpTabCtrlPage::onGetActiveChild() const
{
    return getTabPage(m_currTab);
}

VfxPageBar *VcpTabCtrlPage::onSetBar(VfxPageBarLocationEnum loc, VfxPageBar *newBar)
{
    // because we also have tab bar, so disable top bar's shadow
    if(loc == VFX_PAGE_BAR_LOCATION_TOP)
        newBar->setEnableShadow(VFX_FALSE);
    return newBar;
}

void VcpTabCtrlPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

    // if there is page switch ongoing, switch it w/o animation
    doTabSwitch(VFX_TRUE);

    // enter current page
    VfxPage *p = getTabPage(m_currTab);
    if(p)
    {
        p->processEnter(isBackward, VFX_TRUE, VFX_FALSE);
    }
}

void VcpTabCtrlPage::onEntered()
{
    VfxPage::onEntered();

    // entered current page
    VfxPage *p = getTabPage(m_currTab);
    if(p)
    {
        p->processEnter(VFX_FALSE, VFX_FALSE, VFX_TRUE);
    }
}

void VcpTabCtrlPage::onExit(VfxBool isBackward)
{
    // exit current page
    VfxPage *p = getTabPage(m_currTab);
    if(p)
        p->processExit(isBackward, VFX_TRUE, VFX_FALSE);

    VfxPage::onExit(isBackward);
}

void VcpTabCtrlPage::onExited()
{
    VfxPage *p = getTabPage(m_currTab);
    if(p)
        p->processExit(VFX_FALSE, VFX_FALSE, VFX_TRUE);

    VfxPage::onExited();
}

void VcpTabCtrlPage::onExited2()
{
    // exited current page
    VfxPage *p = getTabPage(m_currTab);
    if(p)
        p->processExited();

    VfxPage::onExited2();
}

void VcpTabCtrlPage::processRotate(const VfxScreenRotateParam &param)
{
    VfxPage::processRotate(param);

    // rotate all tabs
    List::Info * i = m_pageList.getFirstInfo();
    while(i != m_pageList.getLastInfo() )
    {
        VfxPage * page = i->page.get();
        if(page)
            page->processRotate(param);
        ++i;
    }
}

mmi_ret VcpTabCtrlPage::processProc(mmi_event_struct *evt)
{
    mmi_ret result;
    VfxPage * currPage;
    currPage = getTabPage(m_currTab);
    if (currPage)
    {
        result = currPage->processProc(evt);
        if(result != MMI_RET_DONT_CARE)
        {
            return result;
        }
    }

    List::Info * i = m_pageList.getFirstInfo();
    while(i != m_pageList.getLastInfo() )
    {
        if(i->id != m_currTab)
        {
            VfxPage * page = i->page.get();
            if(page)
            {
                result = page->processProc(evt);
                if(result != MMI_RET_DONT_CARE)
                    return result;
            }
        }
        ++i;
    }

    return VfxPage::onProc(evt);
}

VfxBool VcpTabCtrlPage::addTab(VfxId tabId, const VfxWString &name, const VcpStateImage &icon, VfxPage *tabPage)
{
    VfxBool result = m_pageList.add(tabId, name, icon, tabPage, this);
    if (!result)
    {
        return VFX_FALSE;
    }

    m_bar->addTab(tabId, icon, name);
    fixRotation(tabPage);

    if(m_currTab == VFX_ID_NULL && m_newTab == VFX_ID_NULL) // one time init
    {
        setCurrTab(tabId);
    }
    return VFX_TRUE;
}
VfxBool VcpTabCtrlPage::addTab(VfxId tabId, const VfxResId nameId, const VcpStateImage &icon, VfxPage *tabPage)
{
	return addTab(tabId, VFX_WSTR_RES(nameId), icon, tabPage);
}
VfxBool VcpTabCtrlPage::addTab(VfxId tabId, const VfxWChar *name, const VcpStateImage &icon, VfxPage *tabPage)
{
	return addTab(tabId, VFX_WSTR_MEM(name), icon, tabPage);
}
VfxBool VcpTabCtrlPage::replaceTab(VfxId tabId, const VfxWString &name, const VcpStateImage &icon, VfxPage *tabPage)
{
    if (m_newTab != VFX_ID_NULL)
    {
        return VFX_FALSE;
    }

    if (!m_pageList.replace(tabId, name, icon, tabPage) )
    {
        return VFX_FALSE;
    }

    m_bar->changeTab(tabId, name, icon);
    fixRotation(tabPage);

    return VFX_TRUE;
}
VfxBool VcpTabCtrlPage::replaceTab(VfxId tabId, const VfxResId nameId, const VcpStateImage &icon, VfxPage *tabPage)
{
	return replaceTab(tabId, VFX_WSTR_RES(nameId), icon, tabPage);
}
VfxBool VcpTabCtrlPage::replaceTab(VfxId tabId, const VfxWChar* name, const VcpStateImage &icon, VfxPage *tabPage)
{
	return replaceTab(tabId, VFX_WSTR_MEM(name), icon, tabPage);
}

VfxBool VcpTabCtrlPage::closeTab(VfxId tabId)
{
    // cannot close current tab
    if (tabId == m_currTab || tabId == m_newTab)
    {
        return VFX_FALSE;
    }

    if (!m_pageList.remove(tabId) )
    {
        return VFX_FALSE;
    }
    m_bar->removeTab(tabId);

    return VFX_TRUE;
}

void VcpTabCtrlPage::changeTab(VfxId tabId, const VcpStateImage &icon)
{
    m_bar->changeTab(tabId, icon);
}

void VcpTabCtrlPage::changeTab(VfxId tabId, const VfxWString &name)
{
    m_bar->changeTab(tabId, name);
}
void VcpTabCtrlPage::changeTab(VfxId tabId, const VfxResId nameId)
{
    m_bar->changeTab(tabId, VFX_WSTR_RES(nameId));
}
void VcpTabCtrlPage::changeTab(VfxId tabId, const VfxWChar *name)
{
    m_bar->changeTab(tabId, VFX_WSTR_MEM(name));
}

void VcpTabCtrlPage::changeTab(VfxId tabId, const VfxWString &name, const VcpStateImage &icon)
{
    m_bar->changeTab(tabId, name, icon);
}
void VcpTabCtrlPage::changeTab(VfxId tabId, const VfxResId nameId, const VcpStateImage &icon)
{
    m_bar->changeTab(tabId, VFX_WSTR_RES(nameId), icon);
}
void VcpTabCtrlPage::changeTab(VfxId tabId, const VfxWChar *name, const VcpStateImage &icon)
{
    m_bar->changeTab(tabId, VFX_WSTR_MEM(name), icon);
}
VfxBool VcpTabCtrlPage::setCurrTab(VfxId tabId)
{
    if(!m_pageList.find(tabId))
        return VFX_FALSE;

    if(tabId == m_currTab)
        return VFX_FALSE;

    m_newTab = tabId;
    m_bar->setHighlightedTab(tabId);
    checkUpdate();
    return VFX_TRUE;
}

VfxId VcpTabCtrlPage::getCurrTab() const
{
    return m_currTab;
}

VfxPage* VcpTabCtrlPage::getTabPage(VfxId tabId) const
{
    List::Info *info;
    info = m_pageList.find(tabId);
    if(info)
    {
        return info->page.get();
    }
    return NULL;
}

VfxBool VcpTabCtrlPage::setTabEnabled(VfxId tabId, VfxBool isEnabled)
{
    // cannot disable current tab
    if(tabId == getCurrTab() && !isEnabled)
        return VFX_FALSE;

    // not a valid tab
    if(!m_pageList.find(tabId))
        return VFX_FALSE;

    m_bar->setTabEnabled(tabId, isEnabled);

    return VFX_TRUE;
}

VfxBool VcpTabCtrlPage::getTabIsEnabled(VfxId tabId)
{
    return m_bar->getTabIsEnabled(tabId);
}

VcpTabTitleBar* VcpTabCtrlPage::getTabCtrl() const
{
    return m_bar;
}

VfxPage *VcpTabCtrlPage::onCreateTabPage(VfxId tabId)
{
    VFX_UNUSED(tabId);
    return NULL;
}

void VcpTabCtrlPage::onTabSwitching(VfxId tabId)
{
    VFX_UNUSED(tabId);
}

void VcpTabCtrlPage::onTabSwitched(VfxId tabId)
{
    VFX_UNUSED(tabId);
}

void VcpTabCtrlPage::onUpdate()
{
    VfxPage::onUpdate();

    doTabSwitch(VFX_FALSE);
}

void VcpTabCtrlPage::onTabBarSwitched(VfxObject* obj, VfxId newTabId)
{
    VFX_UNUSED(obj);

    setCurrTab(newTabId);
}

void VcpTabCtrlPage::doTabSwitch(VfxBool noAnimation)
{
#ifdef __MMI_VUI_COSMOS_CP_SLIM__
    // turn off switch page animation for performance issue in 50
    noAnimation = VFX_TRUE;
#endif // __MMI_VUI_COSMOS_CP_SLIM__

    if(m_newTab == VFX_ID_NULL)
    {
        return;
    }

    stopTransition();

    List::Info *info = m_pageList.find(m_newTab);
    VFX_ASSERT(info);

    onTabSwitching(m_newTab);

    VfxPage * newPage = info->page.get();
    if(newPage == NULL)
    {
        newPage = onCreateTabPage(m_newTab);
        // Please override onCreateTabPage() and return a valid VfxPage pointer
        VFX_ASSERT(newPage);
        info->page = newPage;
        addChildFrame(newPage);
        newPage->reposistionBars(VFX_TRUE);
    }
    newPage->setFocused(VFX_TRUE);

    VfxPage * currPage = getTabPage(m_currTab);

    // skip animation during initialization
    if(isActive() && !noAnimation)
    {
        if (currPage)
        {
            currPage->prepareTransition(VFX_FALSE);
            currPage->startTransition();
            m_phaseOutTab = m_currTab;
        }

        newPage->prepareTransition(VFX_TRUE);
        newPage->startTransition();
        m_phaseInTab = m_newTab;
        newPage->m_signalTransitionStop.connect(this, &VcpTabCtrlPage::onTabTransitStop);

        m_currTab = m_newTab;
    }
    else
    {
        if (currPage)
        {
            currPage->setHidden(VFX_TRUE);
            currPage->processExit(VFX_FALSE, VFX_TRUE, VFX_FALSE);
        }
        newPage->setHidden(VFX_FALSE);
        newPage->processEnter(VFX_FALSE, VFX_TRUE, VFX_FALSE);

        m_currTab = m_newTab;

        if (currPage)
        {
            currPage->processExit(VFX_FALSE, VFX_FALSE, VFX_TRUE);
            currPage->processExited();
        }
        newPage->processEnter(VFX_FALSE, VFX_FALSE, VFX_TRUE);

        m_signalTabSwitched.postEmit(this, m_currTab);
        onTabSwitched(m_currTab);
    }

    // do Rotate if necessary
    VfxScreenRotateParam param;
    param.rotateFrom = newPage->getRotate();
    param.rotateTo = getRotate();
    param.durTime = VFX_TIMELINE_DEFAULT_DUR_TIME;
    if(param.rotateFrom != param.rotateTo)
        newPage->processRotate(param);

    m_newTab = VFX_ID_NULL;
}

void VcpTabCtrlPage::onTabTransitStop(VfxObject *obj, VfxBool in, VfxS32 direction)
{
    m_signalTabSwitched.postEmit(this, m_currTab);
    onTabSwitched(m_currTab);
    stopTransition();
}

void VcpTabCtrlPage::onBoundChanged(VfxFrame *f, const VfxRect &r)
{
    VFX_UNUSED(r);

    // adjust bar
    VfxSize s = m_bar->getSize();
    m_bar->setSize(f->getSize().width, s.height);

    // adjust all page
    VfxPage *p;

    f = getFirstChildFrame();
    while(f)
    {
        p = VFX_OBJ_DYNAMIC_CAST(f, VfxPage);
        if(p)
            p->reposistionBars(VfxAutoAnimate::getDisable());

        f = f->getNextFrame();
    }
}

void VcpTabCtrlPage::stopTransition()
{
    VfxPage * page;
    page = getTabPage(m_phaseInTab);
    if (page)
    {
        page->m_signalTransitionStop.disconnect(this, &VcpTabCtrlPage::onTabTransitStop);
        page->stopTransition();
    }
    m_phaseInTab = VFX_ID_NULL;

    page = getTabPage(m_phaseOutTab);
    if (page)
    {
        page->stopTransition();
    }
    m_phaseOutTab = VFX_ID_NULL;
}

void VcpTabCtrlPage::fixRotation(VfxPage * page)
{
    if (page != NULL && page->getRotate() != getRotate() )
    {
        VfxScreenRotateParam param;
        param.rotateFrom = page->getRotate();
        param.rotateTo = getRotate();
        param.durTime = 0;
        page->processRotate(param);
    }
}

