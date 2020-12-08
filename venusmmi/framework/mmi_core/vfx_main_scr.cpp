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
 *  vfx_main_scr.cpp
 *
 * Project:
 * --------
 *  Venus FW
 *
 * Description:
 * ------------
 *  Implementation of VfxMainScr, see vfx_main_scr.h
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "vfx_main_scr.h"
#include "vfx_page.h"
#include "vfx_page_transition.h"
#include "vcp_status_icon_bar.h"

#include "vfx_mc_trace.h"

extern "C"
{
#include "kal_trace.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
    
#include "gdi_lcd_config.h"
#include "lcd_sw_inc.h"

#include "mmi_frm_input_gprot.h"    // for mmi_pen_reset()
}

#include "vrt_datatype.h"

#include "vfx_datatype.h"
#include "vfx_object.h"
#include "vfx_cpp_base.h"
#include "vfx_weak_ptr.h"
#include "vfx_class_info.h"
#include "vfx_sys_memory.h"
#include "vfx_object_list.h"
#include "vfx_app_scr.h"
#include "vfx_basic_type.h"
#include "vfx_input_event.h"
#include "vfx_system.h"
#include "vfx_signal.h"
#include "vfx_archive.h"
#include "vfx_screen.h"
#include "vfx_top_level.h"
#include "vfx_frame.h"
#include "vfx_auto_animate.h"

#include "vadp_sys_trc.h"

#include "vfx_adp_device.h"
#include "vfx_logger.h"

#if defined(__COSMOS_MMI_PACKAGE__)
#include "mmi_rp_app_cosmos_global_def.h"
#endif /* defined(__COSMOS_MMI_PACKAGE__) */

/***************************************************************************** 
 * Define
 *****************************************************************************/

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

#ifndef VFX_ID_NULL
#define VFX_ID_NULL (0)
#endif

/***************************************************************************** 
 * Class VfxMainScr
 *****************************************************************************/

class VfxIdObjStack : public VfxObject
{
// Declaration
public:
    class Info : public VfxBase
    {
    // Constructor / Destructor
    public:
        Info() : id(VFX_ID_NULL), obj(NULL), clsIf(NULL), dataPtr(NULL), dataSize(0) {}
    // Variable
    public:
        VfxId                   id;
        VfxWeakPtr<VfxObject>   obj;
        const VfxClassInfo      *clsIf;
        VfxU8                   *dataPtr;
        VfxU32                  dataSize;
        VfxBool                 m_allowDelete;
    };

// Constructor / Destructor
public:
    // Constructor
    VfxIdObjStack();

    // Destructor
    virtual ~VfxIdObjStack();
    
// Method
public:
    VfxBool insert(VfxId id, VfxObject *obj, const VfxClassInfo *clsIf, VfxS32 insert_idx);
    VfxBool push(VfxId id, VfxObject *obj, const VfxClassInfo *clsIf);
    VfxBool push(Info *info);
    Info    pop();
    Info    remove(VfxS32 idx);
    Info    *top() const;
    VfxU32  size() const { return m_objCount; }
    VfxS32  idx(VfxId id) const;
    Info    *find(VfxId id) const;
    Info    *findObj(const VfxObject *obj) const;
    Info    *at(VfxS32 idx) const;
    VfxId   randomId();

protected:
    Info*   _insert(VfxS32 insert_idx);
    virtual void    onDeinit();

private:
    Info            **m_objList;
    VfxU32          m_objCount, m_listSize;
    
};

VfxIdObjStack::VfxIdObjStack() :
    m_objList(NULL), m_objCount(0), m_listSize(0)
{

}

VfxIdObjStack::~VfxIdObjStack()
{
}

void VfxIdObjStack::onDeinit()
{
    VfxU32 i;
    for(i=0;i<m_objCount;i++)
    {
        VFX_FREE_MEM(m_objList[i]->dataPtr);
        VFX_DELETE(m_objList[i]);
    }
    VFX_FREE_MEM(m_objList);

    VfxObject::onDeinit();
}

VfxIdObjStack::Info* VfxIdObjStack::_insert(VfxS32 insert_idx)
{
    if(m_objCount == m_listSize)
    {
        m_listSize += 8;
        Info **newList;
        
        VFX_ALLOC_MEM(newList, sizeof(Info*) * m_listSize, this);
        if(m_objList)
            vfx_sys_mem_copy(newList, m_objList, sizeof(Info*) * m_objCount);
        memset(newList + m_objCount, 0, sizeof(Info*) * (m_listSize - m_objCount));
        VFX_FREE_MEM(m_objList);
        m_objList = newList;
    }

    VfxS32 i;
    for(i=m_objCount;i>insert_idx;i--)
        m_objList[i] = m_objList[i-1];

    VFX_ALLOC_NEW(m_objList[i], Info, this);
    m_objCount++;

    return m_objList[i];
}

VfxBool VfxIdObjStack::insert(VfxId id, VfxObject *obj, const VfxClassInfo *clsIf, VfxS32 insert_idx)
{
    if(id == VFX_ID_NULL || find(id))
        return VFX_FALSE;

    Info *info = _insert(insert_idx);
    info->id = id;
    info->obj = obj;
    info->clsIf = clsIf;

    return VFX_TRUE;
}

VfxBool VfxIdObjStack::push(VfxId id, VfxObject *obj, const VfxClassInfo *clsIf)
{
    return insert(id, obj, clsIf, m_objCount);
}

VfxBool VfxIdObjStack::push(VfxIdObjStack::Info *info)
{
    if(info->id == VFX_ID_NULL || find(info->id))
        return VFX_FALSE;

    Info *destInfo = _insert(m_objCount);
    destInfo->id = info->id;
    destInfo->obj = info->obj;
    destInfo->clsIf = info->clsIf;
    destInfo->dataPtr = info->dataPtr;
    destInfo->dataSize = info->dataSize;

    return VFX_TRUE;
}

VfxIdObjStack::Info VfxIdObjStack::pop()
{
    if(m_objCount == 0)
        return Info();
        
    Info i = *m_objList[m_objCount-1];
    VFX_DELETE(m_objList[m_objCount-1]);
    m_objCount--;
    return i;
}

VfxIdObjStack::Info VfxIdObjStack::remove(VfxS32 idx)
{
    if(idx < 0 || (VfxU32)idx >= m_objCount)
        return Info();
        
    Info i = *m_objList[idx];
    VFX_DELETE(m_objList[idx]);

    for(;(VfxU32)idx+1 < m_objCount;idx++)
    {
        m_objList[idx] = m_objList[idx+1];
    }

    m_objCount--;
    return i;
}

VfxIdObjStack::Info *VfxIdObjStack::top() const
{
    if(m_objCount == 0)
        return NULL;

    return m_objList[m_objCount-1];
}

VfxS32 VfxIdObjStack::idx(VfxId id) const
{
    VfxS32 i;
    for(i=m_objCount-1;i>=0;i--)
    {
        if(m_objList[i]->id == id)
            return i;
    }
    return -1;
}

VfxIdObjStack::Info *VfxIdObjStack::find(VfxId id) const
{
    VfxS32 i = idx(id);
    if(i >= 0)
        return m_objList[i];
    return NULL;
}

VfxIdObjStack::Info *VfxIdObjStack::findObj(const VfxObject *obj) const
{
    VfxS32 i;
    for(i=m_objCount-1;i>=0;i--)
    {
        if(m_objList[i]->obj.get() == obj)
            return m_objList[i];
    }
    return NULL;
}

VfxIdObjStack::Info *VfxIdObjStack::at(VfxS32 idx) const
{
    if(idx >= 0 && (VfxU32)idx < m_objCount)
        return m_objList[idx];
        
    return NULL;
}

VfxId VfxIdObjStack::randomId()
{
    VfxId id = VFX_ID_NULL;
    VfxU32 i;
    for(i=m_objCount;i>0;i--)
    {
        if(m_objList[i-1]->id > id)
            id = m_objList[i-1]->id;
    }
    return id + 1;
}

VFX_IMPLEMENT_CLASS("MainScr", VfxMainScr, VfxAppScr);

VfxMainScr::VfxMainScr() :
    m_statusBar(NULL),
    m_msFlags(FLAGS_IS_AUTO_CLOSE)
    //m_isPageDirty(VFX_FALSE),
    //m_isLayoutDirty(VFX_FALSE),
    //m_isInited(VFX_FALSE),
    //m_isForward(VFX_FALSE),
    //m_inRotateTransition(VFX_FALSE),
    //m_autoClose(VFX_TRUE),
    //m_isActive(VFX_FALSE)
{
}

VfxMainScr::~VfxMainScr()
{
}

void VfxMainScr::onInit()
{
    VFX_LOG_FUNC;
    VfxAppScr::onInit();

    VFX_OBJ_CREATE(m_pageStack,  VfxIdObjStack, this);
    VFX_OBJ_CREATE(m_deadStack,  VfxIdObjStack, this);

    VFX_OBJ_CREATE(m_statusBar, VcpStatusIconBar, this);
    m_statusBar->setAutoAnimate(VFX_TRUE);
    m_statusBar->setPos(0, 0);
    m_statusBar->setHidden(VFX_TRUE);

#if defined(__COSMOS_MMI_PACKAGE__)
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
#else /* defined(__COSMOS_MMI_PACKAGE__) */
    setBgColor(VFX_COLOR_WHITE);
#endif /* defined(__COSMOS_MMI_PACKAGE__) */
    
    setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);

    setIsZSortChild(VFX_TRUE);
}

void VfxMainScr::onAfterInit()
{
    VfxAppScr::onAfterInit();

    // Page stack should be empty here
    VFX_ASSERT(!m_pageStack->size());
}

void VfxMainScr::setBounds(const VfxRect &value)
{
    VfxAppScr::setBounds(value);
    
    if(m_statusBar)
    {
        VfxSize s = m_statusBar->getSize();
        s.width = value.size.width;
        m_statusBar->setSize(s);
    }
}

VfxBool VfxMainScr::onKeyInput(VfxKeyEvent &event)
{
    
    return VfxAppScr::onKeyInput(event);
}

VfxId VfxMainScr::pushPage(VfxId id, VfxPage *p)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XMP", SA_start);
#endif
    VFX_LOG_FUNC2("%d,<%X>", id, p);
    VfxId nid = pushPageInt(id, p, NULL);
    
    VFX_MC_TRACE4(VFX_FUNC, TRC_VFX_9422CABFB965418F97324C8CB6B9180C, 
        "[VfxMainScr](%d) pushPage(%d,%x) = %d", getScreenId(), id, p, nid);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XMP", SA_stop);
#endif
    return nid;
}

VfxId VfxMainScr::pushPageEx(VfxId id, const VfxClassInfo *info)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XMP", SA_start);
#endif
    VFX_LOG_FUNC2("%d,<%X>", id, info);
    VFX_ASSERT(info);
    VfxId nid = pushPageInt(id, NULL, info);
    
    VFX_MC_TRACE4(VFX_FUNC, TRC_VFX_9422CABFB965418F97324C8CB6B9180C, 
        "[VfxMainScr](%d) pushPage(%d,%x) = %d", getScreenId(), id, info, nid);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XMP", SA_stop);
#endif
    return nid;
}

VfxId VfxMainScr::pushPageHandler(VfxId id, VfxPageHandler *handler)
{
    return pushPage(id, handler->createPage());
}

VfxId VfxMainScr::insertPage(VfxId id, VfxPage *page, VfxId insert_above)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XMI", SA_start);
#endif
    VFX_LOG_FUNC2("%d,<%X>", id, page);
    VfxId nid = insertPageInt(id, page, NULL, insert_above);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XMI", SA_stop);
#endif
    return nid;
}

VfxId VfxMainScr::insertPageEx(VfxId id, const VfxClassInfo *info, VfxId insert_above)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XMI", SA_start);
#endif
    VFX_LOG_FUNC2("%d,<%X>", id, info);
    VfxId nid = insertPageInt(id, NULL, info, insert_above);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XMI", SA_stop);
#endif
    return nid;
}

VfxId VfxMainScr::insertPageHandler(VfxId id, VfxPageHandler *handler, VfxId insert_above)
{
    return insertPage(id, handler->createPage(), insert_above);
}

void VfxMainScr::popPage()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XMO", SA_start);
#endif
    VFX_LOG_FUNC;
    VFX_MC_TRACE2(VFX_FUNC, TRC_VFX_AB4AADC7A02C4E6E8DAFA05CBB2D4C9C, 
        "[VfxMainScr](%d) popPage(stack size=%d)", getScreenId(), m_pageStack->size());
        
    if(m_pageStack->size() == 0)
    {
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("XMO", SA_stop);
#endif
        return;
    }

    // If assert here, MainScr is still doing page update,
    // please postInvoke this popPage.
    VFX_ASSERT(!(m_msFlags & FLAGS_IN_PAGE_UPDATE));

    if(!(m_msFlags & FLAGS_IS_PAGE_DIRTY))
        m_currPage = VFX_OBJ_DYNAMIC_CAST(m_pageStack->top()->obj.get(), VfxPage);

    VfxIdObjStack::Info page = m_pageStack->pop();
    m_deadStack->push(&page);
    m_msFlags &= ~FLAGS_IS_FORWARD;

    if(!(m_msFlags & FLAGS_IS_PAGE_DIRTY))
    {
        vfxPostInvoke0(this, &VfxMainScr::onUpdatePage);
        m_msFlags |= FLAGS_IS_PAGE_DIRTY;
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XMO", SA_stop);
#endif
}

void VfxMainScr::closePage(VfxId pageId)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XMC", SA_start);
#endif
    do {
        VFX_LOG_FUNC1("%d", pageId);
        VfxS32 idx = m_pageStack->idx(pageId);
        if(idx < 0)
            break;

        // If assert here, MainScr is still doing page update,
        // please postInvoke this closePage.
        VFX_ASSERT(!(m_msFlags & FLAGS_IN_PAGE_UPDATE));

        if(idx+1 == m_pageStack->size())
        {
            popPage();
            break;
        }

        VfxIdObjStack::Info page = m_pageStack->remove(idx);
        VFX_OBJ_CLOSE(page.obj);
        VFX_FREE_MEM(page.dataPtr);
    } while(0);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XMC", SA_stop);
#endif
}

VfxPage *VfxMainScr::getPage(VfxId pageId) const
{
    VfxIdObjStack::Info *info;
    if(pageId)
    {
        info = m_pageStack->find(pageId);
    }
    else
    {
        info = m_pageStack->top();
    }
    if(info)
        return VFX_OBJ_DYNAMIC_CAST(info->obj.get(), VfxPage);
    return NULL;
}

VfxBool VfxMainScr::isPageIdValid(VfxId pageId) const
{
    return m_pageStack->find(pageId) ? VFX_TRUE : VFX_FALSE;    
}

VfxId VfxMainScr::getPageId(const VfxPage *page) const
{
    VfxIdObjStack::Info *info = m_pageStack->findObj(page);
    if(info)
        return info->id;
    return NULL;
}

VfxS32 VfxMainScr::getPageCount() const
{
    return m_pageStack->size();
}

VfxS32 VfxMainScr::getPageIds(VfxId *buffer, VfxS32 bufferCount, VfxBool topDown) const
{
    VfxS32 i, j;

    if(topDown)
    {
        for(i=m_pageStack->size()-1, j=0;i>=0 && j<bufferCount;i--, j++)
        {
            buffer[j] = m_pageStack->at(i)->id;
        }
    }
    else
    {
        for(i=0, j=0;(VfxU32)i<m_pageStack->size() && j<bufferCount;i++, j++)
        {
            buffer[j] = m_pageStack->at(i)->id;
        }
    }
    return j;
}

VfxId VfxMainScr::getTopPageId() const
{
    if(m_pageStack->size() == 0)
        return VFX_ID_NULL;
    return m_pageStack->top()->id;
}

VfxId VfxMainScr::getBottomPageId() const
{
    if(m_pageStack->size() == 0)
        return VFX_ID_NULL;
    return m_pageStack->at(0)->id;
}

VfxId VfxMainScr::getNextPageId(VfxId pageId) const
{
    VfxS32 idx = m_pageStack->idx(pageId);
    if(idx < 0)
        return VFX_ID_NULL;
    idx++;
    if((VfxU32)idx >= m_pageStack->size())
        return VFX_ID_NULL;

    return m_pageStack->at(idx)->id;
}

VfxId VfxMainScr::getPrevPageId(VfxId pageId) const
{
    VfxS32 idx = m_pageStack->idx(pageId);
    if(idx < 0)
        return VFX_ID_NULL;
    idx--;
    if(idx < 0)
        return VFX_ID_NULL;

    return m_pageStack->at(idx)->id;
}

void VfxMainScr::setAutoClose(VfxBool autoClose)
{
    if(autoClose)
        m_msFlags |= FLAGS_IS_AUTO_CLOSE;
    else
        m_msFlags &= ~FLAGS_IS_AUTO_CLOSE;
}

VfxBool VfxMainScr::getAutoClose() const
{
    return (m_msFlags & FLAGS_IS_AUTO_CLOSE) ? VFX_TRUE : VFX_FALSE;
}

VfxRect VfxMainScr::getClient(VfxPage *page) const
{
    VfxSize s(getSize());
    VfxPoint t(0, 0);
    if(page->hasStatusBar())
    {
        t.y = m_statusBar->getSize().height;
        s.height -= t.y;
    }
    return VfxRect(t, s);
}

void VfxMainScr::recalcLayout(VfxBool bUpdateNow /* = VFX_FALSE */)
{
    if(bUpdateNow)
    {
        processUpdateLayout(VFX_TRUE);
        return;
    }
    
    if(m_msFlags & FLAGS_IS_LAYOUT_DIRTY)
        return;

    m_msFlags |= FLAGS_IS_LAYOUT_DIRTY;
    vfxPostInvoke0(this, &VfxMainScr::onUpdateLayout);
}

VfxControl *VfxMainScr::getStatusBar() const
{
    return m_statusBar;
}

VfxRect VfxMainScr::onGetClientRect() const
{
    if(m_pageStack->top())
    {
        VfxPage *currPage = VFX_OBJ_DYNAMIC_CAST(m_pageStack->top()->obj.get(), VfxPage);
        if(currPage)
        {
            return VfxRect(currPage->getPos(), currPage->getSize());
        }
    }
    
    return VfxAppScr::onGetClientRect();
}

void VfxMainScr::processEnter(VfxBool isBackward)
{
    VFX_LOG_FUNC1("%d", isBackward);

    // During screen enter, all pending page animation should be turnned off
    // to make SSE correct.
    if(m_msFlags & (FLAGS_IS_INITED|FLAGS_IS_PAGE_DIRTY))
    {
        onUpdatePage();
    }

    VFX_ASSERT(!(m_msFlags & FLAGS_IS_ACTIVE));
    m_msFlags |= FLAGS_IS_ACTIVE;

    // do it once before onEnter
    if(!(m_msFlags & FLAGS_IS_INITED))
    {
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("XM1", SA_start);
#endif
        on1stReady();
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("XM1", SA_stop);
#endif

        if(m_msFlags & FLAGS_IS_PAGE_DIRTY)
            onUpdatePage();

        m_msFlags |= FLAGS_IS_INITED;
    }

    VfxWeakPtr<VfxScreen> self(this);
    VfxAppScr::processEnter(isBackward);
    if(!self.isValid())
        return;

    // Enter current page
    VfxIdObjStack::Info *info = m_pageStack->top();
    if(info)
    {
        VfxPage *p = VFX_OBJ_DYNAMIC_CAST(info->obj.get(), VfxPage);
        if(!p)
        {
            // restore it
            processPageRestore(info->id);
            p = VFX_OBJ_DYNAMIC_CAST(info->obj.get(), VfxPage);
            p->reposistionBars(VFX_TRUE);
        }
        p->setFocused(VFX_TRUE);
        p->processEnter(isBackward);

        // if page != mainscr
        if(p->getRotate() != getRotateType())
        {
            VfxScrRotateTypeEnum rotateType = getRotateType();
            
            VfxScreenRotateParam param;
            param.rotateFrom = p->getRotate();
            param.rotateTo = rotateType;
            param.durTime = VFX_SCREEN_DEFAULT_ROTATE_DUR;
            p->queryRotate(param);

            if(param.rotateTo == rotateType)
            {
                p->processRotate(param);
            }
        }
    }
}

void VfxMainScr::processEntered(VfxBool isBackward)
{
    VFX_LOG_FUNC;

    VFX_ASSERT(m_msFlags & FLAGS_IS_ACTIVE);

    // do it once only
    if(!(m_msFlags & FLAGS_IS_INITED_2))
    {
        on2ndReady();

        m_msFlags |= FLAGS_IS_INITED_2;
    }

    VfxAppScr::processEntered(isBackward);
}

void VfxMainScr::processExit(VfxBool isBackward)
{
    VFX_ASSERT(m_msFlags & FLAGS_IS_ACTIVE);
    m_msFlags &= ~FLAGS_IS_ACTIVE;
    m_msFlags &= ~FLAGS_HAS_SNAPSHOTED;

    VFX_LOG_FUNC1("%d", isBackward);

    VfxWeakPtr<VfxScreen> self(this);

    // stop transition to trigger onExited/onEntered correctly
    stopTransition();
    if(!self.isValid())
        return;

    // also exit current page
    VfxWeakPtr<VfxPage> p;
    if(m_msFlags & FLAGS_IS_PAGE_DIRTY)
    {
        p = m_currPage;
    }
    else
    {
        p = getPage();
    }
    
    if(p.isValid())
    {
        p->processExit(isBackward);
    }

    if(self.isValid())
        VfxAppScr::processExit(isBackward);

    if(self.isValid())
        m_msFlags |= FLAGS_HAS_SNAPSHOTED;

    if(p.isValid())
    {
        p->processExited();
    }

}

mmi_ret VfxMainScr::processProc(mmi_event_struct *evt)
{
    VfxPage *p;
    VfxS32 i;
    
    for(i=m_pageStack->size()-1;i>=0;i--)
    {
        p = VFX_OBJ_DYNAMIC_CAST(m_pageStack->at(i)->obj.get(), VfxPage);
        if(p)
        {
            mmi_ret result = p->processProc(evt);
            if(result != MMI_RET_DONT_CARE)
                return result;
        }
    }

    return onProc(evt);
}

VfxBool VfxMainScr::processSerialize(VfxArchive &ar)
{
    VFX_LOG_FUNC;

    // serialize top page if necessary
    VfxPage *page = getPage();
    if(page)
        processPageSerialize(page);
    
    // check if all page are already serialized.
    VfxU32 i, pageCount = m_pageStack->size();
    VfxIdObjStack::Info *info;

    for(i=0;i<pageCount;i++)
    {
        info = m_pageStack->at(i);
        if(info->obj.isValid())
            return VFX_FALSE;
    }

    if(!VfxAppScr::processSerialize(ar))
        return VFX_FALSE;

    setAllowDelete(getAllowDelete());

    // ok, write all data
    ar.writeU32(pageCount);
    for(i=0;i<pageCount;i++)
    {
        info = m_pageStack->at(i);
        ar.writeU32(info->id);
        ar.writeU32((VfxU32)info->clsIf);
        if(info->dataPtr)
        {
            ar.writeU32(info->dataSize);
            ar.write(info->dataPtr, info->dataSize);
        }
        else
        {
            ar.writeU32(0);
        }
    }
    return VFX_TRUE;
}

void VfxMainScr::processRestore(VfxArchive &ar)
{
    VFX_LOG_FUNC;
    VfxAppScr::processRestore(ar);
    
    // Page stack should be empty here
    VFX_ASSERT(!m_pageStack->size());

    // retrieve data from ar
    VfxU32 pageCount = ar.readU32();
    VfxU32 i, size;
    VfxIdObjStack::Info info;
    for(i=0;i<pageCount;i++)
    {
        info.obj = NULL;
        info.id = ar.readU32();
        info.clsIf = (const VfxClassInfo*)ar.readU32();
        size = ar.readU32();
        info.dataSize = size;
        if(size)
        {
            VFX_ALLOC_MEM(info.dataPtr, size, this);
            ar.read(info.dataPtr, size);
        }
        else
        {
            info.dataPtr = NULL;
        }
        m_pageStack->push(&info);
    }
    m_msFlags |= FLAGS_IS_INITED;
}


void VfxMainScr::queryRotate(VfxScreenRotateParam &param)
{
    VfxPage *page = getPage();
    if (page)
    {
        page->queryRotate(param);
        return;
    }

    VfxAppScr::queryRotate(param);
}


void VfxMainScr::processRotate(const VfxScreenRotateParam &param)
{
    VFX_LOG_FUNC;
    VfxAppScr::processRotate(param);

    VfxPage *page = getPage();
    if(page)
    {
        if(m_msFlags & FLAGS_IN_ROTATE_TRANSIT)
        {
            page->startTransition();
            m_phaseInPage = page;
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
        }

        if (isNoAnimRotate())
        {
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
        }

        page->processRotate(param);

        if (isNoAnimRotate())
        {
            VfxAutoAnimate::commit();
        }

        if(m_msFlags & FLAGS_IN_ROTATE_TRANSIT)
        {
            VfxAutoAnimate::commit();
        }
    }
}


VfxBool VfxMainScr::queryFocusChange(VfxFrame *childFrame)
{
    VfxPage *p = getPage();

    // if childFrame is a page and it is current page
    if (!p || p == childFrame)
        return VFX_TRUE;

    // if childFrame is a bar and it belong to current page
    if (childFrame->getParent() == p)
        return VFX_TRUE;

    return VFX_FALSE;
}


void VfxMainScr::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_OBJECT_NOTIFY_ID_AFTER_INIT:
        {
            onAfterInit();
            return;
        }
        case VFX_FRAME_NOTIFY_ID_QUERY_FOCUS_CHANGE:
        {
            VfxFrameQueryFocusChangeData *para = (VfxFrameQueryFocusChangeData *)userData;
            para->ret = queryFocusChange(para->childFrame);
            return;
        }
        default:
        {
            VfxAppScr::onObjectNotify(id, userData);
            return;
        }
    }
}


void VfxMainScr::onScreenDisabled(VfxBool isDisabled)
{
    m_statusBar->setFreeze(isDisabled);
}

VfxBool VfxMainScr::getAllowDelete() const
{
    /* check if User enable allowDelete */
    if(!VfxAppScr::getAllowDelete())
        return VFX_FALSE;

    /* check if any Page not allowDelete */
    VfxS32 i;
    VfxPage *page;
    VfxIdObjStack::Info *info;
    for(i=m_pageStack->size()-1;i>=0 ;i--)
    {
        info = m_pageStack->at(i);
        page = VFX_OBJ_DYNAMIC_CAST(info->obj.get(), VfxPage);
        
        if(page)
        {
            if(!page->getAllowDelete())
                return VFX_FALSE;
        }
        else
        {
            // serialized
            if(!info->m_allowDelete)
                return VFX_FALSE;
        }
    }

    return VFX_TRUE;
}

VfxBool VfxMainScr::onPageBack(VfxPage* page)
{
    VFX_UNUSED(page);
    
    return VFX_TRUE;
}

VfxId VfxMainScr::pushPageInt(VfxId id, VfxPage *page, const VfxClassInfo *info)
{
    do {
        // If assert here, MainScr is still doing page update,
        // please postInvoke this pushPage.
        VFX_ASSERT(!(m_msFlags & FLAGS_IN_PAGE_UPDATE));
    
        if(id == VFX_ID_NULL)
        {
            id = m_pageStack->randomId();
            VFX_ASSERT(id != VFX_ID_NULL);
        }

        if(!(m_msFlags & FLAGS_IS_PAGE_DIRTY) && m_pageStack->size())
            m_currPage = VFX_OBJ_DYNAMIC_CAST(m_pageStack->top()->obj.get(), VfxPage);

        if(!m_pageStack->push(id, page, info))
            break;
            
        m_msFlags |= FLAGS_IS_FORWARD;

        if(!(m_msFlags & FLAGS_IS_PAGE_DIRTY))
        {
            vfxPostInvoke0(this, &VfxMainScr::onUpdatePage);
            m_msFlags |= FLAGS_IS_PAGE_DIRTY;
        }
    }while(0);
    
    return id;
}

VfxId VfxMainScr::insertPageInt(VfxId id, VfxPage *page, const VfxClassInfo *info, VfxId insert_above)
{
    if(insert_above == getTopPageId())
    {
        return pushPageInt(id, page, info);
    }
    
    // If assert here, MainScr is still doing page update,
    // please postInvoke this insertPage.
    VFX_ASSERT(!(m_msFlags & FLAGS_IN_PAGE_UPDATE));

    VfxS32 idx;
    if(insert_above == VFX_ID_NULL)
    {
        idx = 0;
    }
    else
    {
        idx = m_pageStack->idx(insert_above)+1;
        if(idx <= 0)
            return VFX_ID_NULL;
    }

    do {
        if(id == VFX_ID_NULL)
        {
            id = m_pageStack->randomId();
            VFX_ASSERT(id != VFX_ID_NULL);
        }

        if(!m_pageStack->insert(id, page, info, idx))
            break;
    }while(0);
    
    return id;
}

void VfxMainScr::onUpdatePage()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XMU", SA_start);
#endif
    VFX_LOG_FUNC;
    VFX_MC_TRACE2(VFX_FUNC, TRC_VFX_F2F1289D7BC54778A81E930AA649BFF1, 
        "[VfxMainScr](%d) onUpdatePage(%d)", getScreenId(), (m_msFlags & FLAGS_IS_PAGE_DIRTY)?1:0);

    if(!(m_msFlags & FLAGS_IS_PAGE_DIRTY))
    {
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("XMU", SA_stop);
#endif
        return;
    }

    VFX_DEV_ASSERT(!(m_msFlags & FLAGS_IN_PAGE_UPDATE));
    m_msFlags |= FLAGS_IN_PAGE_UPDATE;

    stopTransition();

    if(!m_pageStack->size())
    {
        VfxPage *p = m_currPage.get();
        if(p && (m_msFlags & FLAGS_IS_ACTIVE))
        {
            p->processExit(VFX_TRUE);
            
            if(m_currPage.isValid())
                p->processExited();
        }

        // If screen is active, we need to keep the page to make SSE correct
        // They will be free while screen exit()
        if (!(m_msFlags & FLAGS_IS_ACTIVE) && (m_msFlags & FLAGS_HAS_SNAPSHOTED))
        {
            while(m_deadStack->size())
            {
                VfxIdObjStack::Info *np = m_deadStack->top();
                VFX_OBJ_CLOSE(np->obj);
                VFX_FREE_MEM(np->dataPtr);
                m_deadStack->pop();
            }
        }

        if(m_msFlags & FLAGS_IS_AUTO_CLOSE)
            exit();
        else if(m_currPage.isValid())
            VFX_OBJ_CLOSE(p);

        m_currPage = NULL;
        m_msFlags &= ~FLAGS_IS_PAGE_DIRTY;
        m_msFlags &= ~FLAGS_IN_PAGE_UPDATE;
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("XMU", SA_stop);
#endif
        return;
    }
     
    VfxIdObjStack::Info *np = m_pageStack->top();
    
    /* lazy create page */
    if(!np->obj.isValid())
    {
        if(np->clsIf)
        {
            np->obj = np->clsIf->createObject(this);
            processPageRestore(np->id);
        }
        else
        {
            // TODO: obsolete, remove later
            np->obj = onCreatePage(np->id);
        }
        VFX_DEV_ASSERT(np->obj.isValid());
    
        VFX_MC_TRACE3(VFX_FUNC, TRC_VFX_0BD04636765F4CDD8F462132E5BF4C3F, 
            "[VfxMainScr](%d) onCreatePage(%d)=%x", getScreenId(), np->id, np->obj.get());
        vfxPostInvoke0(this, &VfxMainScr::onUpdatePage);
        
        m_msFlags &= ~FLAGS_IN_PAGE_UPDATE;
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("XMU", SA_stop);
#endif
        return;
    }
    VfxPage *newPage = VFX_OBJ_DYNAMIC_CAST(np->obj.get(), VfxPage);

    if(newPage->getParentFrame() != this)
    {
        addChildFrame(newPage);
        newPage->reposistionBars();
    }

    /* clean up deadStack */
    VfxBool closeCurrPage = VFX_FALSE;
    while(m_deadStack->size())
    {
        VfxIdObjStack::Info *np = m_deadStack->top();
        if (np->obj.get() != m_currPage.get())
        {
            VFX_OBJ_CLOSE(np->obj);
            VFX_FREE_MEM(np->dataPtr);
        }
        else
            closeCurrPage = VFX_TRUE;
        m_deadStack->pop();
    }

    /* do transition */
    if(m_currPage != newPage)
    {
        /* bar setting */
        setStatusBar(newPage, VFX_FALSE);
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("XMF", SA_start);
#endif
        newPage->setFocused(VFX_TRUE);
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("XMF", SA_stop);
#endif

        if((m_msFlags & FLAGS_IS_INITED) && (m_msFlags & FLAGS_IS_ACTIVE))
        {
            VfxS32 direction = m_currPage.isValid() ? ((m_msFlags & FLAGS_IS_FORWARD) ? 1 : -1) : 0;

            /* check rotation */
            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            VfxScreenRotateParam param;
            param.rotateFrom    = topLevel->getScreenRotateType();
            param.rotateTo      = vfx_adp_srs_get_value();
            param.durTime       = VFX_SCREEN_DEFAULT_ROTATE_DUR;

            // Ask want rotate type
            newPage->queryRotate(param);

            // old page phase out
            if(m_currPage.isValid())
            {
                m_currPage->prepareTransition(VFX_FALSE, direction, &param);
                m_currPage->startTransition(closeCurrPage);
                m_phaseOutPage = m_currPage;
            }

            newPage->prepareTransition(VFX_TRUE, direction, &param);
            if (param.rotateTo == param.rotateFrom)
            {
                VfxScrRotateTypeEnum pageRotate = newPage->getRotate();
                if(pageRotate != param.rotateTo)
                {
                    /* resize (without animation) before phase in */
                    newPage->reposistionBars(VFX_TRUE);
                }

                /* new page direct phase in */
                newPage->startTransition();
                m_phaseInPage = newPage;
                if(pageRotate != param.rotateTo)
                {
                    param.rotateFrom = pageRotate;

                    VfxAutoAnimate::begin();
                    VfxAutoAnimate::setDisable(VFX_TRUE);
                    newPage->processRotate(param);
                    VfxAutoAnimate::commit();
                }
            }
            else
            {
                /* new page rotate and phase in */
                m_msFlags |= FLAGS_IN_ROTATE_TRANSIT;
                topLevel->setScreenRotateType(param.rotateTo);
                m_msFlags &= ~FLAGS_IN_ROTATE_TRANSIT;
            }

            #if defined(__MMI_TOUCH_SCREEN__)
            // reset pen event while page switching
            mmi_pen_reset();
            #endif
        }
        else
        {
            newPage->setHidden(VFX_FALSE);
            newPage->setOpacity(1.0f);
            newPage->reposistionBars(VFX_TRUE);

            // clean up dead stack
            if(m_currPage.isValid())
            {
                VfxPage *p = m_currPage.get();
                VfxPageTransition *t = p->getTransition();

                if(t)
                {
                    t->prepare(VFX_FALSE);
                    t->start(p, VFX_TRUE, closeCurrPage);
                }
                else
                {
                    if(closeCurrPage)
                    {
                        VFX_OBJ_CLOSE(p);
                    }
                    else
                    {
                        p->setHidden(VFX_TRUE);
                    }
                }
            }
        }
    }

    m_currPage = NULL;
    m_msFlags &= ~FLAGS_IS_PAGE_DIRTY;
    m_msFlags &= ~FLAGS_IN_PAGE_UPDATE;
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XMU", SA_stop);
#endif
}

void VfxMainScr::onUpdateLayout()
{
    VFX_MC_TRACE2(VFX_FUNC, TRC_VFX_07F8E0E1DDFB4716B009DAAC1E2BB9C0, 
        "[VfxMainScr](%d) onUpdateLayout(%d)", getScreenId(), (m_msFlags & FLAGS_IS_LAYOUT_DIRTY)?1:0);
        
    if(!(m_msFlags & FLAGS_IS_LAYOUT_DIRTY))
        return;

    processUpdateLayout(VFX_FALSE);
}

void VfxMainScr::processUpdateLayout(VfxBool bUpdateNow)
{
    VFX_LOG_FUNC;
    if(m_pageStack->top())
    {
        VfxPage *currPage = VFX_OBJ_DYNAMIC_CAST(m_pageStack->top()->obj.get(), VfxPage);
        if(currPage)
        {
            setStatusBar(currPage, bUpdateNow);
            currPage->reposistionBars(bUpdateNow);
        }
    }
    m_msFlags &= ~FLAGS_IS_LAYOUT_DIRTY;
}

void VfxMainScr::stopTransition()
{
    // stop phaseOut first, so that Exited is before Entered
    if(m_phaseOutPage.isValid())
    {
        m_phaseOutPage->stopTransition();
        m_phaseOutPage = NULL;
    }

    if(m_phaseInPage.isValid())
    {
        m_phaseInPage->stopTransition();
        m_phaseInPage = NULL;
    }
}

VfxMainScr *VfxMainScr::findMainScr(VfxFrame *f)
{
    while(f)
    {
        if(f->isKindOf(VFX_OBJ_CLASS_INFO(VfxMainScr)))
            return VFX_OBJ_DYNAMIC_CAST(f, VfxMainScr);
     
        f = f->getParentFrame();
    }
    return NULL;
}

void VfxMainScr::setStatusBar(VfxPage *page, VfxBool noAnimation)
{
    if(noAnimation)
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
    }

    if(page->hasStatusBar())
    {
        m_statusBar->setHidden(VFX_FALSE);
        m_statusBar->bringToFront();
        m_statusBar->setTranslucent(page->isTranslucent());
        m_statusBar->setStatusbarBG(page->getStatusBarBg());
        m_statusBar->setEnable(VFX_TRUE);
        m_statusBar->setIsUnhittable(VFX_FALSE);
    }
    else
    {
        m_statusBar->setEnable(VFX_FALSE);
        m_statusBar->setIsUnhittable(VFX_TRUE);
    }

    if(noAnimation)
    {
        VfxAutoAnimate::commit();
    }
}

void VfxMainScr::processPageRestore(VfxId pageId)
{
    VFX_LOG_FUNC;
    VfxIdObjStack::Info *info = m_pageStack->find(pageId);
    VFX_ASSERT(info);

    if(info->dataPtr)
    {
        VfxPage *page = VFX_OBJ_DYNAMIC_CAST(info->obj.get(), VfxPage);
        if(!page)
        {
            VFX_ASSERT(info->clsIf);
            info->obj = info->clsIf->createObject(this);
            page = VFX_OBJ_DYNAMIC_CAST(info->obj.get(), VfxPage);
        }    

        VfxArchive          *pArchive;
        VfxMemArchiveSource *pSource;
        
        VFX_OBJ_CREATE(pArchive, VfxArchive, this);
        VFX_OBJ_CREATE(pSource, VfxMemArchiveSource, pArchive);

        pSource->attachBuffer((VfxU8*)info->dataPtr, info->dataSize);
        pArchive->setSource(pSource);

        info->dataPtr = NULL;
        info->dataSize = 0;

        page->processRestore(*pArchive);
    }
}

void VfxMainScr::processPageSerialize(VfxPage *page)
{
    VFX_LOG_FUNC;
    VfxIdObjStack::Info *info = m_pageStack->findObj(page);
    if(!info)
        return;
        
    VfxArchive          *pArchive;
    VfxMemArchiveSource *pSource;

    VFX_OBJ_CREATE(pArchive, VfxArchive, this);
    VFX_OBJ_CREATE(pSource, VfxMemArchiveSource, pArchive);
    pArchive->setSource(pSource);
    
    VfxBool ret = page->processSerialize(*pArchive);

    if(ret)
    {
        info->m_allowDelete = page->getAllowDelete();
        info->clsIf = page->getClassInfo();

        if(info->dataPtr)
            VFX_FREE_MEM(info->dataPtr);

        pSource->detachBuffer(&info->dataPtr, &info->dataSize);

        VFX_OBJ_CLOSE(page);
    }

    VFX_OBJ_CLOSE(pArchive);

}

void VfxMainScr::processPageBack(VfxPage *page)
{
    VFX_LOG_FUNC;
    if(onPageBack(page))
    {
        stopTransition();
        
        if(getPageCount() == 1 && (m_msFlags & FLAGS_IS_AUTO_CLOSE))
        {
            VfxAppScr::onBack();
        }
        else
        {
            closePage(page->getId());
        }
    }
}

VfxMainScrEx::VfxMainScrEx(IVfxMainScrHandler *handler):
    m_handler(handler)
{
    VFX_ASSERT(handler);
}

VfxMainScrEx::~VfxMainScrEx()
{

}

void VfxMainScrEx::onInit() 
{
    VfxMainScr::onInit();
    m_handler->onScrInit(this);
}

void VfxMainScrEx::onDeinit()
{
    m_handler->onScrDeinit(this);
    m_handler = NULL;
    VfxMainScr::onDeinit();
}

void VfxMainScrEx::on1stReady()
{
    m_handler->onScr1stReady(this);
}

void VfxMainScrEx::on2ndReady()
{
    m_handler->onScr2ndReady(this);
}


