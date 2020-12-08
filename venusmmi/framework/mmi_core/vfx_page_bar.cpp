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
 *  vfx_page_bar.cpp
 *
 * Project:
 * --------
 *  Venus FW
 *
 * Description:
 * ------------
 *  Implementation of VfxPageBar, see vfx_page_bar.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_page_bar.h"
#include "vfx_page_transition.h"
#include "vfx_main_scr.h"
#include "vfx_page.h"

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_app.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Class VfxPageBarTrans
 *****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/***************************************************************************** 
 * Class VfxPageBar
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("Bar", VfxPageBar, VfxControl);

VfxPageBar::VfxPageBar():
    m_loc(VFX_PAGE_BAR_LOCATION_TOP),
    m_enableShadow(VFX_TRUE)
{
}

VfxPageBar::~VfxPageBar()
{
}


void VfxPageBar::setPos(const VfxPoint &value)
{
    VfxControl::setPos(value);

    if(m_shadow.isValid())
    {
        VfxPoint p = value;
        switch(m_loc)
        {
        case VFX_PAGE_BAR_LOCATION_TOP:
            p.y += getSize().height;
            break;
        case VFX_PAGE_BAR_LOCATION_BOTTOM:
            p.y -= m_shadow->getSize().height;
            break;
        }
        m_shadow->setPos(p);
    }
}

void VfxPageBar::setPosZ(VfxFloat value)
{
    VfxControl::setPosZ(value);
    if(m_shadow.isValid())
    {
        m_shadow->setPosZ(value);
    }
}

void VfxPageBar::setBounds(const VfxRect &value)
{
    VfxControl::setBounds(value);

    if(m_shadow.isValid())
    {
        VfxSize s = m_shadow->getSize();
        s.width = getSize().width;
        m_shadow->setSize(s);
    }
}

void VfxPageBar::setOpacity(VfxFloat value)
{
    VfxControl::setOpacity(value);
    if(m_shadow.isValid())
    {
        m_shadow->setOpacity(value);
    }
}

void VfxPageBar::setTransform(const VfxTransform &value)
{
    VfxControl::setTransform(value);
    if(m_shadow.isValid())
    {
        m_shadow->setTransform(value);
    }
}

void VfxPageBar::setHidden(VfxBool value)
{
    VfxControl::setHidden(value);
    if(m_shadow.isValid() && m_enableShadow)
    {
        m_shadow->setHidden(value);
    }
}

VfxBool VfxPageBar::processFocusKey(VfxKeyEvent &event)
{
    VfxBool ret = VfxControl::processFocusKey(event);

    // pass the event to page if bar not handle it.
    if(!ret)
    {
        VfxFrame *frm = (VfxFrame*)VFX_OBJ_DYNAMIC_CAST(getParent(), VfxFrame);
        if(frm && (frm != getParentFrame()))
            ret = frm->processFocusKey(event);
    }
    
    return ret;
}

void VfxPageBar::onParentFrameChanged(VfxFrame *origParentFrame)
{
    VfxControl::onParentFrameChanged(origParentFrame);
    if(m_shadow.isValid())
    {
        if(m_shadow->getParentFrame() != getParentFrame())
        {
            getParentFrame()->addChildFrame(m_shadow.get());
        }
    }
}


void VfxPageBar::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_FRAME_NOTIFY_ID_PARENT_FRAME_CHANGED:
        {
            onParentFrameChanged((VfxFrame *)userData);
            return;
        }
        default:
        {
            VfxControl::onObjectNotify(id, userData);
            return;
        }
    }
}

VfxBool VfxPageBar::onPreviewPenInput(VfxPenEvent &event)
{
    VfxBool ret = VfxControl::onPreviewPenInput(event);

    /* notify page for preview event */
    VfxPage *page = getPage();
    if(page)
        page->previewBarPenInput(event);

    return ret;
}

VfxBool VfxPageBar::onPenInput(VfxPenEvent &event)
{
    // Eat all pen event, so that preview pen input can paired.
    return VFX_TRUE;
}

VfxApp *VfxPageBar::getApp() const
{ 
    return getMainScr()->getApp(); 
}

VfxMainScr *VfxPageBar::getMainScr() const
{
    return VfxMainScr::findMainScr(getParentFrame());
}

VfxPage *VfxPageBar::getPage() const
{
    return VFX_OBJ_DYNAMIC_CAST(getParent(), VfxPage);
}

VfxPageBarLocationEnum VfxPageBar::getLoc() const
{
    return m_loc;
}

void VfxPageBar::setTransition(VfxPageTransition* trans)
{
    if(m_transition.isValid())
        VFX_OBJ_CLOSE(m_transition);

    m_transition = trans;
}

void VfxPageBar::setEnableShadow(VfxBool value)
{
    if(value != m_enableShadow)
    {
        m_enableShadow = value;

        if(m_shadow.isValid())
        {
            m_shadow->setHidden(!value);
        }
    }
}

VfxBool VfxPageBar::startTransition(VfxBool in, VfxS32 direction, VfxBool noAnimation, VfxBool autoClose)
{
    if(!m_transition.isValid())
    {
        //VFX_OBJ_CREATE_EX(m_transition, VfxPageBarTrans, this, (m_loc == VFX_PAGE_BAR_LOCATION_TOP));
        VFX_OBJ_CREATE(m_transition, VfxPageSlideTransition, this);
    }

    if(!noAnimation)
        m_transition->m_signalStopped.connect(this, &VfxPageBar::processTransitionStop);
    m_transition->prepare(in, direction);
    return m_transition->start(this, noAnimation, autoClose);
}

VfxBool VfxPageBar::stopTransition()
{
    if(m_transition.isValid())
    {
        m_transition->m_signalStopped.disconnect(this, &VfxPageBar::processTransitionStop);
        return m_transition->stop();
    }
    return VFX_FALSE;
}

VfxBool VfxPageBar::restartTransition()
{
    if(m_transition.isValid())
    {
        return m_transition->restart();
    }
    return VFX_FALSE;
}

void VfxPageBar::doBackFunc()
{
    getMainScr()->popPage();
}

VfxFrame *VfxPageBar::setShadowFrame(VfxFrame *shadow)
{
    VfxFrame *old = m_shadow.get();

    if(shadow)
    {
        shadow->setIsUnhittable(VFX_TRUE);
    
        shadow->setAutoAnimate(VFX_TRUE);

        // parent
        getParentFrame()->addChildFrame(shadow);

        // pos
        VfxPoint p = getPos();
        switch(m_loc)
        {
        case VFX_PAGE_BAR_LOCATION_TOP:
            p.y += getSize().height;
            break;
        case VFX_PAGE_BAR_LOCATION_BOTTOM:
            p.y -= shadow->getSize().height;
            break;
        }
        shadow->setPos(p);

        // Z order
        shadow->setPosZ(getPosZ());

        // size
        VfxSize s = shadow->getSize();
        s.width = getSize().width;
        shadow->setSize(s);

        // opacity
        shadow->setOpacity(getOpacity());

        // hidden
        shadow->setHidden(getHidden() | !m_enableShadow);
    }
    
    m_shadow = shadow;
    return old;
}

void VfxPageBar::setLoc(VfxPageBarLocationEnum newLoc)
{
    if(m_loc != newLoc)
    {
        m_loc = newLoc;

        if(m_shadow.isValid())
        {
            VfxPoint p = getPos();
            switch(m_loc)
            {
            case VFX_PAGE_BAR_LOCATION_TOP:
                p.y += getSize().height;
                break;
            case VFX_PAGE_BAR_LOCATION_BOTTOM:
                p.y -= m_shadow->getSize().height;
                break;
            }
            m_shadow->setPos(p);
        }
    }

}

void VfxPageBar::processTransitionStop(VfxBool in, VfxS32 direction)
{
    m_transition->m_signalStopped.disconnect(this, &VfxPageBar::processTransitionStop);
    
    onTransitionStop(in, direction);
}
