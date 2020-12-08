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
 *  vcp_base_menu.cpp
 *
 * Project:
 * --------
 *  A basic menu framework for venus
 *
 * Description:
 * ------------
 *  
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_base_menu.h"
#include "vadp_sys_trc.h"
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vcp_wheel_menu.h"
#include "vfx_sys_memory.h"
#include "string.h"
#include "vfx_frame.h"
#include "kal_trace.h"
#include "vfx_system.h"
#include "vfx_object.h"
#include "vfx_input_event.h"
#include "vcp_scrollable.h"
#include "vfx_basic_type.h"
#include "vfx_class_info.h"
#include "vfx_animation.h"
#include "vrt_canvas.h"
#include "vfx_timer.h"
#include "vfx_signal.h"
#include "kal_public_api.h"

#if defined(__MTK_TARGET__) && defined(__VENUS_SWLA_DBG_ON__)
#define __MAUI_SOFTWARE_LA__
#endif

extern "C"
{
#if !defined(__MMI_VUI_COSMOS_CP__)
#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* !defined(__MMI_VUI_COSMOS_CP__) */


#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif

}

// #define TRACE(a) VFX_TRACE (a)

#ifndef TRACE
#   define TRACE(a)
#endif 

#define TRC_POS(_p) _p.group, _p.pos
#define TRC_POINT(_p) _p.x, _p.y
#define TRC_SIZE(_p) _p.width, _p.height
#define TRC_RECT(_r) _r.origin.x, _r.origin.y, _r.size.width, _r.size.height

#define ARRAY(_target,_index) ((VfxS32*)&_target)[_index]


/***************************************************************************** 
 * Class VcpMenuRegion
 *****************************************************************************/

VcpMenuPos VcpMenuPos::getNextPos(VcpBaseMenuLayout* layout, VfxBool includeHeader) const
{
    if (!isValid())
    {
        return VcpMenuPos();
    }

    VcpMenuPos p(*this);
    
    do
    {
        p.pos++;

        if (p.pos >= layout->getCellCount(p.group))
        {
            p.group ++;
            p.pos = -1;

            if (p.group >= layout->getGroupCount())
            {
                p.invalid();
                break;
            }

            if (!includeHeader || !layout->hasGroupHeader(p.group))
            {
                p.pos = 0;

                if (layout->getCellCount(p.group) == 0)
                {
                    // nothing in this group
                    continue;
                }
            }
        }
        break;
    } 
    while(1);

    return p;
}

VcpMenuPos VcpMenuPos::getPrevPos(VcpBaseMenuLayout* layout, VfxBool includeHeader) const
{
    if (!isValid())
    {
        return VcpMenuPos();
    }

    VcpMenuPos p(*this);

    do
    {
        p.pos--;

        if (p.pos == -1)
        {
            if (!includeHeader || !layout->hasGroupHeader(p.group))
            {
                continue; // go to next possible
            }
        }
        else if (p.pos < -1)
        {
            p.group--;
            if (p.group < 0) // EOS
            {
                p.invalid();
                break;
            }
            p.pos = layout->getCellCount(p.group) - 1;

            if (p.pos == -1 && (!includeHeader || !layout->hasGroupHeader(p.group)))
            {
                continue; // go to next possible
            }
        }
        break;
    } 
    while(1);

    return p;
}


#ifdef __MMI_VENUS_PLUG_IN_ENGINE__ 
VcpMenuPos::operator vm_base_menu_pos_struct() const
{
    vm_base_menu_pos_struct ret;

    ret.group = (VMINT32)group;
    ret.pos = (VMINT32)pos;

    return ret;
}
#endif

/***************************************************************************** 
 * Class VcpMenuRegion
 *****************************************************************************/

VcpMenuRegion VcpMenuRegion::unionRegion(const VcpMenuRegion &rgn) const
{
    VcpMenuRegion r(*this);
    if (rgn.isEmpty())
    {
        return r;
    }
    if (rgn.begin.group < r.begin.group)
    {
        r.begin.group = rgn.begin.group;
        r.begin.pos = rgn.begin.pos;
    }
    else if (rgn.begin.group == r.begin.group)
    {
        r.begin.pos = VFX_MIN(r.begin.pos, rgn.begin.pos);
    }
    if (rgn.end.group > r.end.group)
    {
        r.end.group = rgn.end.group;
        r.end.pos = rgn.end.pos;
    }
    else if (rgn.end.group == r.end.group)
    {
        r.end.pos = VFX_MAX(r.end.pos, rgn.end.pos);
    }
    return r;
}

VcpMenuRegion VcpMenuRegion::intersectRegion(const VcpMenuRegion &rgn) const
{
    VcpMenuRegion r(*this);
        
    if (rgn.isEmpty())
    {
        return r;
    }

    if (rgn.begin.group > r.begin.group)
    {
        r.begin.group = rgn.begin.group;
        r.begin.pos = rgn.begin.pos;
    }
    else if (rgn.begin.group == r.begin.group)
    {
        r.begin.pos = VFX_MAX(r.begin.pos, rgn.begin.pos);
    }
    if (rgn.end.group < r.end.group)
    {
        r.end.group = rgn.end.group;
        r.end.pos = rgn.end.pos;
    }
    else if (rgn.end.group == r.end.group)
    {
        r.end.pos = VFX_MIN(r.end.pos, rgn.end.pos);
    }

    if (r.begin.pos < 0 || r.end.pos < 0 || r.begin.pos < r.end.pos)
    {
        r.empty();
    }
    return r;
}

VfxBool VcpMenuRegion::isWithin(VfxS32 group, VfxS32 pos) const
{
    if (isEmpty())
    {
        return VFX_FALSE;
    }

    if (group == begin.group)
    {
        if (begin.group == end.group)
        {
            return (pos >= begin.pos) && (pos <= end.pos);
        }
        return pos >= begin.pos;
    }
    else if (group == end.group)
    {
        return pos <= end.pos;
    }
    else if (group > begin.group && group < end.group)
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}


#ifdef __MMI_VENUS_PLUG_IN_ENGINE__ 
VcpMenuRegion::operator vm_base_menu_region_struct() const
{
    vm_base_menu_region_struct ret;

    ret.begin = vm_base_menu_pos_struct(begin);
    ret.end = vm_base_menu_pos_struct(end);

    return ret;
}
#endif


/***************************************************************************** 
 * Class VcpMenuRegionIter
 *****************************************************************************/

VcpMenuRegionIter::VcpMenuRegionIter(VcpBaseMenuLayout* layout, VcpMenuRegion r)
{
      reset(layout, r);
}

VcpMenuRegionIter::VcpMenuRegionIter(VcpBaseMenu* menu, VcpMenuRegion r)
{
      reset(menu->m_layout, r);
}

VcpMenuPos VcpMenuRegionIter::next()
{
    VcpMenuPos p = m_pos;

    if(m_region.begin.group < m_region.end.group || 
      (m_region.begin.group == m_region.end.group && m_region.begin.pos < m_region.end.pos))
    {
        m_pos = m_pos.getNextPos(m_layout);
        
        if (m_pos.group > m_region.end.group ||
            (m_pos.group == m_region.end.group && m_pos.pos > m_region.end.pos))
        {
            m_pos.invalid();
        }
    }
    else
    {
        m_pos = m_pos.getPrevPos(m_layout);
        
        if (m_pos.group < m_region.end.group ||
            (m_pos.group == m_region.end.group && m_pos.pos < m_region.end.pos))
        {
            m_pos.invalid();
        }
    }

    return p;
}

void VcpMenuRegionIter::reset(VcpBaseMenuLayout* layout, VcpMenuRegion r)
{
    m_region = r;
    m_pos = r.begin;
    m_layout = layout;
}

/***************************************************************************** 
 * Class VcpMenuCache
 *****************************************************************************/

VcpMenuCache::VcpMenuCache() : m_itemCount(0), m_itemTotalCount(VCP_MENUCACHE_ADDITION), m_items(NULL), m_pMenu(NULL)
{
}

VcpMenuCache::~VcpMenuCache()
{
    VFX_DEV_ASSERT(m_pMenu);

    for (int i = 0; i < m_itemCount; i++)
    {
        VFX_DELETE(m_items[i]);
    }
    VFX_FREE_MEM(m_items);
    m_items = NULL;
    m_itemCount = 0;
    m_itemTotalCount = 0;
}

VfxBool VcpMenuCache::isInCache(VfxS32 group, VfxS32 pos)
{
    if (group < 0 || pos < -1)
        return VFX_FALSE;

    Key key = makeKey(group, pos);
    VfxS32 idx = bisect_left(key);

    if (idx < m_itemCount && m_items[idx]->key == key)
        return VFX_TRUE;
    
    return VFX_FALSE;
}

void VcpMenuCache::setFlag(VfxS32 group, VfxS32 pos, VfxU32 flag, VfxBool setFlag)
{
    if (group < 0 || pos < -1)
        return;
    
    Key key = makeKey(group, pos);
    VfxS32 idx = bisect_left(key);
    if (idx >= m_itemCount) // cannot find
        return;

    if (m_items[idx]->key != key)
        return;

    if (setFlag)
    {
        m_items[idx]->flag |= flag;
    }
    else
    {
        m_items[idx]->flag &= ~flag;
    }
}

VfxU32 VcpMenuCache::getFlag(VfxS32 group, VfxS32 pos)
{
    if (group < 0 || pos < -1)
        return 0;
    
    Key key = makeKey(group, pos);
    VfxS32 idx = bisect_left(key);
    if (idx >= m_itemCount) // cannot find
        return 0;

    if (m_items[idx]->key != key)
        return 0;

    return m_items[idx]->flag;
}

void VcpMenuCache::setKeepFlag(VfxS32 group, VfxS32 pos, VfxBool isKeep)
{
    setFlag(group, pos, VCP_MENUCACHE_FLAG_KEEP, isKeep);
}

void VcpMenuCache::setDummyFlag(VfxS32 group, VfxS32 pos, VfxBool isDummy)
{
    setFlag(group, pos, VCP_MENUCACHE_FLAG_DUMMY, isDummy);
}

void VcpMenuCache::hit(VfxS32 group, VfxS32 pos)
{
    setFlag(group, pos, VCP_MENUCACHE_FLAG_HIT, VFX_TRUE);
}

VfxFrame* VcpMenuCache::getItem(VfxS32 group, VfxS32 pos)
{
    if (group < 0 || pos < -1)
        return NULL;
    
    Key key = makeKey(group, pos);
    VfxS32 idx = bisect_left(key);
    if (idx >= m_itemCount) // cannot find
        return NULL;

    if (m_items[idx]->key != key)
        return NULL;

    return m_items[idx]->ptr.get();
}

void VcpMenuCache::setParent(VcpBaseMenu* pMenu)
{
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("Bcp", SA_start);
#endif      
    m_pMenu = pMenu;

    if (m_items == NULL)
    {
        VFX_ALLOC_MEM(m_items, m_itemTotalCount * sizeof(ItemPtr), m_pMenu);
        memset(m_items, 0, sizeof(ItemPtr) * m_itemTotalCount);
    }
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("Bcp", SA_stop);
#endif      
}

void VcpMenuCache::withdrawItem(VfxS32 group, VfxS32 pos)
{
    VFX_DEV_ASSERT(!isInCache(group, pos));

    // cannot withdraw header
    if (pos < 0)
    {
        return;
    }

    for (VfxS32 i = 0; i < m_itemCount; i++)
    {
        VcpMenuPos p = decodeKey(m_items[i]->key);

        if (p.group != group)
        {
            continue;
        }
        if (p.pos < pos)
        {
            continue;
        }
        m_items[i]->key = makeKey(p.group, p.pos - 1);
    }
}

void VcpMenuCache::putinItem(VfxS32 group, VfxS32 pos)
{
    // cannot putin header
    if (pos < 0)
    {
        return;
    }

    for (VfxS32 i = 0; i < m_itemCount; i++)
    {
        VcpMenuPos p = decodeKey(m_items[i]->key);

        if (p.group != group)
        {
            continue;
        }
        if (p.pos < pos)
        {
            continue;
        }
        m_items[i]->key = makeKey(p.group, p.pos + 1);
    }
}

void VcpMenuCache::setItem(VfxS32 group, VfxS32 pos, VfxFrame* frame)
{
    if (group < 0 || pos < -1)
    {
        VFX_DEV_ASSERT(0);
        return;
    }
    
    if (frame == NULL)
    {
        removeItem(group, pos);
        return;
    }

    Key key = makeKey(group, pos);
    VfxS32 idx = bisect_left(key);

    if (idx < m_itemCount && m_items[idx]->key == key)
    {
        m_items[idx]->ptr = frame;            
    }
    else
    {
        VFX_DEV_ASSERT(idx <= m_itemCount);

        if (m_itemCount == m_itemTotalCount)
        {
            // the space is not enough
            ItemPtr *new_items;

            m_itemTotalCount += VCP_MENUCACHE_ADDITION;

            VFX_ALLOC_MEM(new_items, m_itemTotalCount * sizeof(ItemPtr), m_pMenu);

            memset(new_items, 0, sizeof(ItemPtr) * m_itemTotalCount);
            memcpy(new_items, m_items, sizeof(ItemPtr) * m_itemCount);
            
            VFX_FREE_MEM(m_items);

            m_items = new_items;
        }
    
        VFX_DEV_ASSERT(m_itemTotalCount > m_itemCount);

        m_itemCount++;
        for (VfxS32 i = m_itemCount - 1; i > idx; i--)
        {
            m_items[i] = m_items[i - 1];
        }
        VFX_ALLOC_NEW(m_items[idx], Item, m_pMenu);
        m_items[idx]->key = key;
        m_items[idx]->ptr = frame;
        m_items[idx]->flag = 0;
        m_items[idx]->flag |= VCP_MENUCACHE_FLAG_HIT;
    }
}

void VcpMenuCache::removeItem(VfxS32 group, VfxS32 pos)
{
    if (group < 0 || pos < -1)
    {
        VFX_DEV_ASSERT(0);
        return;
    }

    if (m_itemCount == 0)
    {
        // nothing can remove
        return;
    }

    Key key = makeKey(group, pos);
    VfxS32 idx = bisect_left(key);

    if (m_items[idx]->key != key)
    {
        // Cannot found item
        return;
    }

    if (idx < m_itemCount && m_items[idx]->key == key)
    {
        VFX_DELETE(m_items[idx]);
        for (VfxS32 i = idx; i < m_itemCount - 1; i++)
        {
            m_items[i] = m_items[i + 1];
        }
        m_itemCount--;

    }

    // we can reduce space
    if (m_itemTotalCount - m_itemCount >= 2 * VCP_MENUCACHE_ADDITION)
    {
        // the space is not enough

        VfxS32 newTotal = VFX_MAX(m_itemCount, VCP_MENUCACHE_ADDITION);

        newTotal = VCP_MENUCACHE_ADDITION * ((newTotal + VCP_MENUCACHE_ADDITION - 1) / VCP_MENUCACHE_ADDITION);

        ItemPtr *new_items;
        VFX_ALLOC_MEM(new_items, newTotal * sizeof(ItemPtr), m_pMenu);
        memset(new_items, 0, sizeof(ItemPtr) * newTotal);

        memcpy(new_items, m_items, sizeof(ItemPtr) * m_itemCount);
        m_itemTotalCount = newTotal;
        VFX_FREE_MEM(m_items);
        m_items = new_items;

    }
}

void VcpMenuCache::clear()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("Bcc", SA_start);
#endif
    for (VfxS32 i = 0; i < m_itemCount; i++)
    {
        VcpMenuPos p = decodeKey(m_items[i]->key);            
        VfxFrame* frame = m_items[i]->ptr.get();

        if (frame)
        {
            if (p.isGroupHeader())
            {
#ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("BOH", SA_start);
#endif
                m_pMenu->onCloseGroupHeader(p.group, frame);
#ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("BOH", SA_stop);
#endif
            }
            else
            {
#ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("BOC", SA_start);
#endif
                m_pMenu->onCloseCell(p.group, p.pos, frame);
#ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("BOC", SA_stop);
#endif                
            }
        }
        VFX_DELETE(m_items[i]);
    }
    m_itemCount = 0;
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("Bcc", SA_stop);
#endif    
}

void VcpMenuCache::debugDump()
{
    TRACE(("=============================================\n"));

    for (VfxS32 i = 0; i < m_itemCount; i++)
    {
        VcpMenuPos p = decodeKey(m_items[i]->key);

        TRACE(("(%d,%d)\t%x\t%x\n",
            p.group, p.pos, m_items[i]->ptr.get(), m_items[i]->flag
        ));
    }
}

void VcpMenuCache::clearIfNotHit()
{
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("Bch", SA_start);
#endif    
    TRACE(("clearIfNotHit:"));
    VfxS32 cnt = m_itemCount;
    for (VfxS32 i = 0; i < m_itemCount; i++)
    {
        VcpMenuPos p = decodeKey(m_items[i]->key);

        // we leave dummy item here, and don't to free it
        if (m_items[i]->flag & VCP_MENUCACHE_FLAG_KEEP)
        {
            continue;
        }

        if (m_items[i]->flag & VCP_MENUCACHE_FLAG_HIT)
        {
            continue;
        }

        TRACE(("<%d,%d>", p.group, p.pos));

        if (p.isGroupHeader())
        {
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("BOH", SA_start);
#endif  
            m_pMenu->onCloseGroupHeader(p.group, m_items[i]->ptr.get());
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("BOH", SA_stop);
#endif  

        }
        else
        {
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("BOC", SA_start);
#endif 
            m_pMenu->onCloseCell(p.group, p.pos, m_items[i]->ptr.get());
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("BOC", SA_stop);
#endif

        }
        cnt--;

        VFX_DELETE(m_items[i]);
    }
    TRACE(("\n"));

    VfxS32 fptr = 0, eptr = 0;
    while (fptr < m_itemCount)
    {
        if (m_items[fptr] != 0)
        {
            m_items[eptr] = m_items[fptr];
            eptr++;
        }
        fptr++;
    }
    VFX_DEV_ASSERT(cnt == eptr);
    m_itemCount = cnt;
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("Bch", SA_stop);
#endif        
}

void VcpMenuCache::clearHitFlag()
{
    for (VfxS32 i = 0; i < m_itemCount; i++)
    {
        m_items[i]->flag &= (~VCP_MENUCACHE_FLAG_HIT);
    }
}

VfxS32 VcpMenuCache::bisect_left(Key key)
{
    VfxS32 lo = 0, hi = m_itemCount, mid;
    while (lo < hi)
    {
        mid = (lo + hi) / 2;
        if (m_items[mid]->key < key) 
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

/***************************************************************************** 
 * Class VcpBaseMenuLayout
 *****************************************************************************/

void VcpBaseMenuLayout::update()
{
    VFX_LOG(VFX_INFO, VCP_BASEMENU_UPDATE_MSG);

    if (m_pMenu)
    {
        m_pMenu->updateLayout();
    }
}

void VcpBaseMenuLayout::clearFocusItem()
{
    if(m_pMenu)
    {
        m_pMenu->clearFocusItem();
    }
}

void VcpBaseMenuLayout::setFocusItem(VcpMenuPos focus, VfxBool isMoveToVisible)
{

    if(m_pMenu)
    {
        m_pMenu->setFocusItem(focus, isMoveToVisible);
    }
}

VcpMenuPos VcpBaseMenuLayout::getFocusItem() const
{   
    if(m_pMenu)
    {
        return m_pMenu->getFocusItem();
    }
    return VcpMenuPos();
}

VfxBool VcpBaseMenuLayout::navDir(NavDirEnum dir)
{
    VFX_UNUSED(dir);
    return VFX_FALSE; // we cannot nav by key
}

void VcpBaseMenuLayout::makeVisible(VcpMenuPos p, VfxBool isAnim)
{
    VFX_LOG(VFX_INFO, VCP_BASEMENU_MAKEVISIBLE_MSG, p.group, p.pos, isAnim);

    if (m_pMenu && p.isValid())
    {
        m_pMenu->makeVisible(p, isAnim);
    }
}

void VcpBaseMenuLayout::getPreferFocusMargin(VfxS32 margin[4])
{
    margin[0] = margin[1] = margin[2] = margin[3] = 0;
}

VfxS32 VcpBaseMenuLayout::getMarginLength(VcpBaseMenuMarginAreaEnum area)
{
    return m_pMenu->m_marginItemArray[(VfxS32)area].size()
        ? m_pMenu->m_marginItemArray[(VfxS32)area].back().m_accumulatedLength
        : 0;    
}

VfxS32 VcpBaseMenuLayout::getTotalLength()
{    
    VfxS32 sz = getContentLength();
    for(VfxS32 i = 0; i < VCP_BASE_MENU_MARGIN_AREA_END; ++i)
    {
        sz += getMarginLength((VcpBaseMenuMarginAreaEnum) i);
    }  
    return sz;
}

/***************************************************************************** 
 * Class VcpBaseMenuView
 *****************************************************************************/

VcpBaseMenuView::VcpBaseMenuView()
{
}

VcpBaseMenu* VcpBaseMenuView::getMenu()
{
    VFX_DEV_ASSERT(VFX_OBJ_DYNAMIC_CAST(getParentFrame(), VcpBaseMenu));
    return (VcpBaseMenu*) getParentFrame();
}

VfxBool VcpBaseMenuView::onPenInput(VfxPenEvent &event)
{
#ifdef __MAUI_SOFTWARE_LA__
      SLA_CustomLogging("BPI", SA_start);
#endif
    VfxBool pre_drag = m_isDragging;

    // Since we are just hook, so we call parent first
    VfxBool ret = VcpScrollableView::onPenInput(event);
    
    if (event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        getMenu()->dragView(m_isDragging, event.pos, event.downPos);
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        getMenu()->penDown(event.getRelDownPos(this));
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        // after parent::onPenInput, the drag flag will be clear, so we need to backup
        if (!pre_drag && (!m_isDecelerating || m_isResizing))
        {
            getMenu()->tapView(event.getRelPos(this));
        }
        getMenu()->penUp(event.getRelPos(this));
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_LONG_TAP)
    {
        // after parent::onPenInput, the drag flag will be clear, so we need to backup
        if (!pre_drag)
        {
            getMenu()->penLongDown(event.getRelDownPos(this));
        }
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        getMenu()->penAbort(event.getRelPos(this));
    }

#ifdef __MAUI_SOFTWARE_LA__
      SLA_CustomLogging("BPI", SA_stop);
#endif
    return ret;
}

void VcpBaseMenuView::onFreeRunSetTargetContentOffset(VfxPoint &offset)
{
    getMenu()->onScrollStopPosFix(offset);
}

/***************************************************************************** 
 * Class VcpBaseMenu
 *****************************************************************************/

VFX_IMPLEMENT_VIRTUAL_CLASS("VcpBaseMenu", VcpBaseMenu, VcpScrollable);

VcpBaseMenu::VcpBaseMenu() : 
	m_isPenProcessing(VFX_FALSE),
    m_layout(NULL), 
    m_preScrollDir(1), 
    m_contentLength(-1),
    m_needRelayout(VFX_TRUE), 
    m_needMarginItemRelayout(VFX_TRUE),
    m_needCellRelayout(VFX_TRUE), 
    m_forceResetScrollPos(VFX_FALSE),
    m_isScrolling(VFX_FALSE),
    m_state(Opening), 
    m_opeingTimeMS(VFX_TIMELINE_DEFAULT_DUR_TIME), 
    m_closingTimeMS(VFX_TIMELINE_DEFAULT_DUR_TIME),
    m_cacheLen(0),
    m_preExistCell(VFX_FALSE),
    m_isOnDeinit(VFX_FALSE),
    m_pVisibleView(NULL),
    m_cacheStyle(VCP_BASE_MENU_CACHE_STYLE_PREDICT),
    m_isContentWarning(VFX_FALSE)    
{
}

VcpScrollableView *VcpBaseMenu::onCreateView()
{
    VcpBaseMenuView *view;

    // This is very tricky, the view must have NULL parent
    VFX_OBJ_CREATE(view, VcpBaseMenuView, this);

    return view;
}

void VcpBaseMenu::updateLayout()
{
    VFX_LOG(VFX_INFO, VCP_BASEMENU_UPDATE_LAYOUT_MSG);

    // This change request is from layouter.
    // We need to async process it to avoid re-entry problems.
    m_needRelayout = VFX_TRUE;
    m_needMarginItemRelayout = VFX_TRUE;
    checkUpdate();
}

void VcpBaseMenu::setBounds(const VfxRect &value)
{
    VcpScrollable::setBounds(value);    
    m_contentLength = -1; // reset content length, so we will reset scrollable's view
    updateLayout();
}

void VcpBaseMenu::onInit()
{
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("BIN", SA_start);
#endif 
    // we set parent before scrollable onInit to void callback during onInit in scrollable.
    m_cache.setParent(this);

    VcpScrollable::onInit();

    // init timer
    VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    m_timer->setStartDelay(m_closingTimeMS);
    m_timer->setDuration(0);
    m_timer->m_signalTick.connect(this, &VcpBaseMenu::onTimerTick);
       


    m_signalScrollStarted.connect(this, &VcpBaseMenu::notifyScrollStart);
    m_signalScrollStopped.connect(this, &VcpBaseMenu::notifyScrollEnd);
    m_view->m_signalContentWarning.connect(this, &VcpBaseMenu::onContentWarning);

    newLayout();
    m_needRelayout = VFX_TRUE;
    checkUpdate();

    registerKeyHandler(VFX_KEY_CODE_SPECIAL_ALL_ARROW);

    m_state = Normal;


    for(VfxS32 i = 0; i < VCP_BASE_MENU_MARGIN_AREA_END; ++i)
    {
        m_marginItemArray[i].init(this);
    }    

#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("BIN", SA_stop);
#endif     
}

void VcpBaseMenu::onDeinit()
{
    // When deinit, we will not emit some event or callback.
    // That is because APP is nothing can do if we fire event here, that will make APP need to do more checking.
    m_isOnDeinit = VFX_TRUE;

    m_cache.clear();

    // Free make visible temp structure
    VFX_FREE_MEM(m_pVisibleView);

    VcpScrollable::onDeinit();
}


void VcpBaseMenu::addMarginItem(VcpBaseMenuMarginAreaEnum area, VcpBaseMenuMarginAreaFramePlacementEnum placement, VfxFrame *frame)
{
    VFX_ASSERT(frame);

    VfxS32 h = frame->getSize().height;

    for (VfxU32 i = 0; i < m_marginItemArray[area].size(); ++i)
    {
        m_marginItemArray[area][i].m_mpos.pos++;    
        m_marginItemArray[area][i].m_accumulatedLength += h;    
        
    }
    VcpMenuMarginItem item(VcpMenuPos(area, 0), placement, frame);
    m_marginItemArray[area].insert(0, item);

    m_view->addChildFrame(frame);

    updateLayout();


}

void VcpBaseMenu::removeMarginItem(VfxFrame *frame)
{ 
    VcpMenuPos pos;
    
    for(VfxS32 i = 0; i < VCP_BASE_MENU_MARGIN_AREA_END; ++i)
    {
        VfxBool found = VFX_FALSE;
        for (VfxU32 j = 0; j < m_marginItemArray[i].size(); ++j)
        {
            if (m_marginItemArray[i][j].m_framePtr.get() == frame)
            {
                pos = VcpMenuPos(i, j);
                found = VFX_TRUE;
                break;
            }
        }
        if (found)
        {
            break;
        }
    }    

    if (pos.isValid())        
    {
        VfxS32 h = pos.pos > 0 ? m_marginItemArray[pos.group][pos.pos].m_accumulatedLength - 
                         m_marginItemArray[pos.group][pos.pos - 1].m_accumulatedLength 
                       : m_marginItemArray[pos.group][pos.pos].m_accumulatedLength;
      
        for (VfxU32 i = pos.pos; i < m_marginItemArray[pos.group].size(); ++i)
        {
            m_marginItemArray[pos.group][i].m_mpos.pos--;
            m_marginItemArray[pos.group][i].m_accumulatedLength -= h;            
        }       
        m_marginItemArray[pos.group].erase(pos.pos);
        frame->removeFromParentFrame();
        updateLayout();        
    }

}


void VcpBaseMenu::removeMarginItem(VcpMenuPos pos)
{
    if(pos.group < 0 || pos.group >= VCP_BASE_MENU_MARGIN_AREA_END || pos.pos < 0 || pos.pos > (VfxS32) m_marginItemArray[pos.group].size() - 1)
    {
        return;
    }    

    VfxS32 h = pos.pos > 0 ? m_marginItemArray[pos.group][pos.pos].m_accumulatedLength - 
                             m_marginItemArray[pos.group][pos.pos - 1].m_accumulatedLength 
                           : m_marginItemArray[pos.group][pos.pos].m_accumulatedLength;
    
    for (VfxU32 i = pos.pos; i < m_marginItemArray[pos.group].size(); ++i)
    {
        m_marginItemArray[pos.group][i].m_mpos.pos--;
        m_marginItemArray[pos.group][i].m_accumulatedLength -= h;            
    }       

    VfxFrame *frame = getMarginItem(pos);       
    frame->removeFromParentFrame();

    m_marginItemArray[pos.group].erase(pos.pos);

    updateLayout();        


}


VfxFrame* VcpBaseMenu::getMarginItem(VcpMenuPos pos)
{
    if (pos.group >=0 && pos.group < VCP_BASE_MENU_MARGIN_AREA_END && pos.pos >= 0 && pos.pos < (VfxS32)m_marginItemArray[pos.group].size())
    {
        return m_marginItemArray[pos.group][pos.pos].m_framePtr.get();
    }
    else
    {
        return NULL;
    }   
    
}


void VcpBaseMenu::clearFocusItem()
{
    VFX_LOG(VFX_INFO, VCP_BASEMENU_CLEAR_FOCUS_ITEM_MSG);
    setFocusItem(VcpMenuPos(), VFX_FALSE);
}

void VcpBaseMenu::setFocusItem(VcpMenuPos focus, VfxBool isMoveToVisible)
{
    VFX_LOG(VFX_INFO, VCP_BASEMENU_SET_FOCUS_ITEM_MSG, focus.group, focus.pos, isMoveToVisible);
#ifdef __MAUI_SOFTWARE_LA__
      SLA_CustomLogging("BSF", SA_start);
#endif 

    if(!focus.isValid())
    {
        focus = VcpMenuPos();
    }

    if (m_focusItem != focus)
    {
        clearFocusMarginItem();
        VcpMenuPos pre = m_focusItem;
        m_focusItem = focus;

        if (!m_isOnDeinit)
        {
            VFX_LOG(VFX_INFO2, VCP_BASEMENU_ON_FOCUS_CHANGE_MSG, focus.group, focus.pos, pre.group, pre.pos);
#ifdef __MAUI_SOFTWARE_LA__
      SLA_CustomLogging("BFC", SA_start);
#endif 
            onFocusIndexChange(focus, pre);
#ifdef __MAUI_SOFTWARE_LA__
      SLA_CustomLogging("BFC", SA_stop);
#endif 
        }
        updateLayout();
    }
    
    if (isMoveToVisible)
    {
        makeVisible(m_focusItem);
    }
#ifdef __MAUI_SOFTWARE_LA__
      SLA_CustomLogging("BSF", SA_stop);
#endif 
}

VcpMenuPos VcpBaseMenu::getFocusItem() const
{
    return m_focusItem;
}


void VcpBaseMenu::clearFocusMarginItem()
{
    VFX_LOG(VFX_INFO, VCP_BASEMENU_CLEAR_FOCUS_ITEM_MSG);
    setFocusMarginItem(VcpMenuPos(), VFX_FALSE);
}



void VcpBaseMenu::setFocusMarginItem(VcpMenuPos focus, VfxBool isMoveToVisible)
{
    if(!focus.isValid())
    {
        focus = VcpMenuPos();
    }

    if (m_focusMarginItem != focus)
    {
        clearFocusItem();
        VcpMenuPos pre = m_focusMarginItem;
        m_focusMarginItem = focus;

        if (!m_isOnDeinit)
        {
            onFocusMarginIndexChange(focus, pre);
        }
    }
    updateLayout();
    if (isMoveToVisible)
    {
        makeMarginVisible(m_focusMarginItem);
    }
}

VcpMenuPos VcpBaseMenu::getFocusMarginItem() const
{
    return m_focusMarginItem;
}


void VcpBaseMenu::makeVisible(const VfxRect& r, VfxBool isAnim)
{
#ifdef __MAUI_SOFTWARE_LA__
         SLA_CustomLogging("BMV", SA_start);
#endif 
    VFX_LOG(VFX_INFO, VCP_BASEMENU_MAKE_RECT_VISIBLE_MSG, TRC_RECT(r), isAnim);

    if (m_pVisibleView == NULL)
    {
        VFX_ALLOC_MEM(m_pVisibleView, sizeof(VisibleView), this);
    }
    memset(m_pVisibleView, 0, sizeof(VisibleView));

    m_pVisibleView->flag |= VCP_BASEMENU_VISIBLEVIEW_FLAG_RECT;
    m_pVisibleView->rect = r;

    if (isAnim)
    {
        m_pVisibleView->flag |= VCP_BASEMENU_VISIBLEVIEW_FLAG_ANIM;
    }

    checkUpdate();
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("BMV", SA_stop);
#endif 
}


void VcpBaseMenu::makeVisible(VcpMenuPos p, VfxBool isAnim)
{
#ifdef __MAUI_SOFTWARE_LA__
      SLA_CustomLogging("BMV", SA_start);
#endif
    VFX_LOG(VFX_INFO, VCP_BASEMENU_MAKE_POS_VISIBLE_MSG, p.group, p.pos, isAnim);

    if (!p.isValid() || m_layout == NULL)
    {
        return;
    }

    if (m_pVisibleView == NULL)
    {
        VFX_ALLOC_MEM(m_pVisibleView, sizeof(VisibleView), this);
    }
    memset(m_pVisibleView, 0, sizeof(VisibleView));
    
    m_pVisibleView->flag |= VCP_BASEMENU_VISIBLEVIEW_FLAG_FOCUS;
    m_pVisibleView->focus = p;

    if (isAnim)
    {
        m_pVisibleView->flag |= VCP_BASEMENU_VISIBLEVIEW_FLAG_ANIM;
    }

    checkUpdate();
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("BMV", SA_stop);
#endif 
}


void VcpBaseMenu::makeMarginVisible(VcpMenuPos p, VfxBool isAnim)
{

    if (!p.isValid() || m_layout == NULL)
    {
        return;
    }

    if (m_pVisibleView == NULL)
    {
        VFX_ALLOC_MEM(m_pVisibleView, sizeof(VisibleView), this);
    }
    memset(m_pVisibleView, 0, sizeof(VisibleView));
    
    m_pVisibleView->flag |= VCP_BASEMENU_VISIBLEVIEW_FLAG_FOCUS_MARGIN;
    m_pVisibleView->focus = p;

    if (isAnim)
    {
        m_pVisibleView->flag |= VCP_BASEMENU_VISIBLEVIEW_FLAG_ANIM;
    }

    checkUpdate();
}


void VcpBaseMenu::onFocusMarginIndexChange(VcpMenuPos focusItem, VcpMenuPos preFocusItem)
{
    VFX_UNUSED(focusItem);
    VFX_UNUSED(preFocusItem);
}

VfxPoint VcpBaseMenu::calVisibleOffset(const VfxRect& r2)
{
#ifdef __MAUI_SOFTWARE_LA__
       SLA_CustomLogging("BCO", SA_start);
#endif 
    VfxRect r = r2;
    VfxRect b = m_view->getBounds();
    VfxPoint contentOrigin = m_view->getContentOrigin();
    VfxSize contentSz = getLayoutContentSize();

    VfxS32 margin[4];
    m_layout->getPreferFocusMargin(margin);

    for(VfxS32 i = 0; i < 2; ++i)
    {
        ARRAY(r.origin, i) = VFX_MAX(ARRAY(r.origin, i), ARRAY(contentOrigin, i));

        VfxS32 rmax, bmax;
        rmax = i == 0 ? r.getMaxX() : r.getMaxY();
        if (rmax >= ARRAY(contentSz, i) + ARRAY(contentOrigin, i))
        {
            ARRAY(r.size, i) = ARRAY(contentSz, i) + ARRAY(contentOrigin, i) - ARRAY(r.origin, i);
        }
            
        if (ARRAY(r.size, i) + margin[i] + margin[i + 2] > ARRAY(b.size, i))
        {
            ARRAY(b.origin, i) = ARRAY(r.origin, i) - (ARRAY(b.size, i) - ARRAY(r.size, i))/2;
        }
        else
        {
            if (ARRAY(r.origin, i) - ARRAY(b.origin, i) < margin[i])
            {
                ARRAY(b.origin, i) = ARRAY(r.origin, i) - margin[i];
            }
            
            rmax = i == 0 ? r.getMaxX() : r.getMaxY();
            bmax = i == 0 ? b.getMaxX() : b.getMaxY();                        
            if (rmax > bmax - margin[VcpBaseMenuLayout::MARGIN_RIGHT])
            {
                ARRAY(b.origin, i) = ARRAY(r.origin, i) - (ARRAY(b.size, i) - ARRAY(r.size, i) - margin[VcpBaseMenuLayout::MARGIN_RIGHT]);
            }
        }

        ARRAY(b.origin, i) = VFX_MIN(ARRAY(r.origin, i), ARRAY(b.origin, i));

        rmax = i == 0 ? r.getMaxX() : r.getMaxY();
        bmax = i == 0 ? b.getMaxX() : b.getMaxY();  
        
        if (ARRAY(r.origin, i) > bmax || rmax > bmax)
        {
            ARRAY(b.origin, i) = ARRAY(r.origin, i) - (ARRAY(b.size, i) - ARRAY(r.size, i));
        }

        bmax = i == 0 ? b.getMaxX() : b.getMaxY();  

        if (bmax >= ARRAY(contentSz, i) + ARRAY(contentOrigin, i))
        {
            ARRAY(b.origin, i) = ARRAY(contentSz, i) + ARRAY(contentOrigin, i) - ARRAY(b.size, i);
        }

        ARRAY(b.origin, i) = VFX_MAX(ARRAY(b.origin, i), ARRAY(contentOrigin, i));
    }

    
#ifdef __MAUI_SOFTWARE_LA__
       SLA_CustomLogging("BCO", SA_stop);
#endif 
    return b.origin;
}

void VcpBaseMenu::scrollContent(VfxPoint pt, VfxBool isAnim)
{
#ifdef __MAUI_SOFTWARE_LA__
           SLA_CustomLogging("BSC", SA_start);
#endif 
    VFX_LOG(VFX_INFO, VCP_BASEMENU_SCROLL_CONTENT_MSG, pt.x, pt.y, isAnim);

    VfxRect b2 = m_view->getBounds();

    if (b2.origin == pt)
    {
#ifdef __MAUI_SOFTWARE_LA__
                   SLA_CustomLogging("BSC", SA_stop);
#endif 
        return;
    }

    // If the view is too far, disable animation
    if ((VFX_ABS(b2.origin.x - pt.x) > b2.size.width) ||
        (VFX_ABS(b2.origin.y - pt.y) > b2.size.height))
    {
        isAnim = VFX_FALSE;
    }

    if (!isAnim)
    {
        m_forceResetScrollPos = VFX_TRUE;
    }

    VfxBool animation = (isAnim && !m_forceResetScrollPos && getHandle() != NULL);
    VFX_LOG(VFX_INFO, VCP_BASEMENU_SET_CONTENT_OFFSET_MSG, pt.x, pt.y, animation);
    setContentOffset(pt, animation);


#ifdef __MAUI_SOFTWARE_LA__
     SLA_CustomLogging("BSC", SA_stop);
#endif 
}


VfxBool VcpBaseMenu::onKeyInput(VfxKeyEvent &event)
{
    // if the menu state is not in normal, let's skip key handling
    if (m_state == Normal)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
        {
            if (event.keyCode == VFX_KEY_CODE_ARROW_UP)
            {
                if (m_layout->navDir(VcpBaseMenuLayout::NAV_DIR_UP))
                {
                    return VFX_TRUE;
                }
            }
            else if (event.keyCode == VFX_KEY_CODE_ARROW_DOWN)
            {
                if (m_layout->navDir(VcpBaseMenuLayout::NAV_DIR_DOWN))
                {
                    return VFX_TRUE;
                }
            }
            else if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT)
            {
                if (m_layout->navDir(VcpBaseMenuLayout::NAV_DIR_LEFT))
                {
                    return VFX_TRUE;
                }
            }
            else if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT)
            {
                if (m_layout->navDir(VcpBaseMenuLayout::NAV_DIR_RIGHT))
                {
                    return VFX_TRUE;
                }
            }
            else if (event.keyCode == VFX_KEY_CODE_CSK)
            {
                if (m_focusItem.isValid())
                {
                    VfxFrame* item = getCellIfPresent(m_focusItem.group, m_focusItem.pos);

                    if (item == NULL)
                    {
                        return VFX_FALSE;
                    }                    

                    if (m_focusItem.isGroupHeader())
                    {
                        onTapGroupHeader(m_focusItem.group, item);
                    }
                    else
                    {
                        onTapCell(m_focusItem.group, m_focusItem.pos, item);
                    }
                    
                    onTouchCell(m_focusItem, VcpBaseMenu::TouchTap, item->getBounds().getMidPoint(), item);

                    return VFX_TRUE;
                }
            }

        }
    }
    return VcpScrollable::onKeyInput(event);
}

VfxBool VcpBaseMenu::onPreviewPenInput(VfxPenEvent &event)
{
    VFX_UNUSED(event);
    
    // we ignore the pen input when the menu state is not stable
    if (m_state != Normal)
    {
        return VFX_TRUE;
    }    
    return VcpScrollable::onPreviewPenInput(event);
}


void VcpBaseMenu::reset()
{
    //  clear previous make visible request
    VFX_FREE_MEM(m_pVisibleView);

    if (IsSupportTransition())
    {
        // have a transition state for animation
        m_state = Closing;
    }
    else
    {
        resetInternal();
    }

    m_needRelayout = VFX_TRUE;
    checkUpdate();
}

void VcpBaseMenu::newLayout()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("BNL", SA_start);
#endif 
    VFX_LOG(VFX_INFO, VCP_BASEMENU_NEWLAYOUT_MSG);

    VFX_DEV_ASSERT(m_layout == NULL);
    
    m_layout = createLayout();
    VFX_ASSERT(m_layout);

    m_layout->setViewRect(m_view->getBounds());
    enableBounce(!m_layout->isScrollVert(), m_layout->isScrollVert());

    updateLayout();
    onAfterCreateLayout();
    m_signalResetLayout.emit(this);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("BNL", SA_stop);
#endif     
}

void VcpBaseMenu::resetInternal()
{
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("BRI", SA_start);
#endif
    VFX_LOG(VFX_INFO, VCP_BASEMENU_RESET_INTERNAL_MSG);

    // Close all cell in the screen
    VcpMenuRegionIter itr(m_layout, m_curRegion);
    while(!itr.isEnd())
    {
        VcpMenuPos p = itr.next();
        delCell(p);
    }

    // Reset create layout
    VFX_OBJ_CLOSE(m_layout);

    setContentSize(getBounds().size);
    setValidContentRect(getBounds());
    setWarningContentRect(getBounds());
    scrollContent(VfxPoint(getContentOrigin().x, getContentOrigin().y), VFX_FALSE);
    clearFocusItem();
    clearFocusMarginItem();

    m_cache.clear();
    
    m_preExistCell  = VFX_FALSE;
    m_curValidRect  = VfxRect(0, 0, 0, 0);
    m_preScrollDir  = 1;
    m_contentLength = -1; // means never get length before

    m_curRegion.empty();
    m_targetRegion.empty();
    if (IsSupportTransition())
    {
        m_state = Opening;
    }
    else
    {
        m_state = Normal;
    }

    newLayout();

    checkUpdate();

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("BRI", SA_stop);
#endif    
}

VfxFrame* VcpBaseMenu::getCell(VcpMenuPos pos, VfxU32& flag)
{
    VfxFrame* cell = m_cache.getItem(pos);
    if (!cell)
    {
        if (pos.group >= m_layout->getGroupCount() || pos.pos >= m_layout->getCellCount(pos.group))
        {
            return NULL;
        }

        if (m_cache.getFlag(pos.group, pos.pos) & VCP_MENUCACHE_FLAG_DUMMY)
        {
            // the cell is dummy cell, return NULL since it is not normal cell.
            return NULL;
        }

        VFX_LOG(VFX_INFO2, VCP_BASEMENU_CREATE_CELL_MSG, pos.group, pos.pos);

        flag |= VCP_CELL_FLAG_FIRSTINIT;
        if (pos.isGroupHeader())
        {
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("BCH", SA_start);
#endif                 
            cell = createGroupHeader(pos.group);
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("BCH", SA_stop);
#endif                 
        }
        else
        {
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("BCC", SA_start);
#endif
            cell = createCell(pos.group, pos.pos);
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("BCC", SA_stop);
#endif

        }
        m_cache.setItem(pos, cell);
    }
    return cell;
}

void VcpBaseMenu::delCell(VcpMenuPos pos)
{
    VFX_LOG(VFX_INFO2, VCP_BASEMENU_DEL_CELL_MSG, pos.group, pos.pos);


    VfxFrame* cell = m_cache.getItem(pos);
    if (cell)
    {
        // free this cell if it is dummy frame
        if (m_cache.getFlag(pos.group, pos.pos) & VCP_MENUCACHE_FLAG_DUMMY)
        {
            VFX_OBJ_CLOSE(cell);
        }
        else if (pos.isGroupHeader())
        {
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("BOH", SA_start);
#endif
            onCloseGroupHeader(pos.group, cell);
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("BOH", SA_stop);
#endif
        }
        else
        {
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("BOC", SA_start);
#endif            
            onCloseCell(pos.group, pos.pos, cell);
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("BOC", SA_stop);
#endif
        }
        m_cache.removeItem(pos);
    }
}

void VcpBaseMenu::updateCell(const VfxRect &rect, VcpMenuPos pos, VfxU32 flag)
{
    VFX_LOG(VFX_INFO2, VCP_BASEMENU_UPDATE_CELL_MSG, pos.group, pos.pos);
    VfxFrame* cell = getCell(pos, flag);
    if (cell)
    {
        if (pos.isGroupHeader())
        {
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("BUH", SA_start);
#endif            
            onUpdateGroupHeader(rect, pos.group, cell, flag);
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("BUH", SA_stop);
#endif

        }
        else
        {
#ifdef __MAUI_SOFTWARE_LA__
           SLA_CustomLogging("BUC", SA_start);
#endif            
           onUpdateCell(rect, pos.group, pos.pos, cell, flag);
#ifdef __MAUI_SOFTWARE_LA__
           SLA_CustomLogging("BUC", SA_stop);
#endif

        }
    }
}

void VcpBaseMenu::onViewBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds)
{
    VcpScrollable::onViewBoundsValueChange(source, oldBounds);
        
    if (m_layout)
    {
        m_layout->setViewRect(m_view->getBounds());
    }
    checkUpdate();
}

VfxRect VcpBaseMenu::calValidView()
{
#ifdef __MAUI_SOFTWARE_LA__
           SLA_CustomLogging("BCV", SA_start);
#endif

    if (!m_isContentWarning && getValidContentRect() != VFX_RECT_ZERO && m_cacheStyle == VCP_BASE_MENU_CACHE_STYLE_CENTER)
    {
        return getValidContentRect();
    }


    m_isContentWarning = VFX_FALSE;



    VfxRect curView;
    VfxRect validRect, sbValidRect;
    VfxRect warnRect, sbWarnRect;
    VfxPoint contentOrigin = getContentOrigin();
    
    if (!m_forceResetScrollPos && m_view->getHandle() != NULL)
    {
        curView = getViewBounds();

        // before VRT commit, the value is different from that of VFX
        // for resize case, use the worst case to avoid the asynchronous issue
        curView.size.width = VFX_MAX(curView.size.width, m_view->getBounds().size.width);
        curView.size.height = VFX_MAX(curView.size.height, m_view->getBounds().size.height);
    }
    else
    {
        curView = m_view->getBounds();
    }

    VfxRect targetView = m_view->getBounds();
    VfxS32 contentLength = m_layout->getTotalLength();
    VfxS32 scrollDir = m_preScrollDir;

    validRect = curView;
    warnRect = curView;

    VfxBool isScroll[2];
    isScroll[0] = !m_layout->isScrollVert();
    isScroll[1] = m_layout->isScrollVert();


    for (VfxS32 i = 0; i < 2; ++i)
    {
        if (isScroll[i])
        {
            VfxS32 cacheRange = (m_cacheLen > 0) ? m_cacheLen : ARRAY(targetView.size, i) / 4;
            VfxS32 diff = ARRAY(targetView.origin, i) - ARRAY(curView.origin, i);            
            if (diff > 0)
            {
                scrollDir = 1;
            }
            else if (diff < 0)
            {
                scrollDir = -1;
            }

            if (m_cacheStyle == VCP_BASE_MENU_CACHE_STYLE_CENTER)
            {
               // if in free run, the cache range keep the same as current view size
               if (m_view->m_isDecelerating == VFX_FALSE)
               {
                   ARRAY(validRect.size, i) += cacheRange;
                   ARRAY(validRect.origin, i) -= cacheRange / 2;
                   ARRAY(warnRect.size, i) += cacheRange / 2;
                   ARRAY(warnRect.origin, i) -= cacheRange / 4;
               }
            }
            else 
            {
                if (scrollDir > 0)
                {
                    ARRAY(validRect.size, i) += cacheRange;
                    ARRAY(warnRect.size, i) += cacheRange / 2;
                }
                else
                {
                    ARRAY(validRect.size, i) += cacheRange;
                    ARRAY(validRect.origin, i) -= cacheRange;
                    ARRAY(warnRect.size, i) += cacheRange / 2;
                    ARRAY(warnRect.origin, i) -= cacheRange / 2;
                }
            }       

            ARRAY(validRect.origin, i) = VFX_MAX(VFX_MIN(ARRAY(validRect.origin, i), ARRAY(contentOrigin, i) + contentLength - ARRAY(validRect.size, i)), ARRAY(contentOrigin, i));
            ARRAY(warnRect.origin, i) = VFX_MAX(VFX_MIN(ARRAY(warnRect.origin, i), ARRAY(contentOrigin, i) + contentLength - ARRAY(warnRect.size, i)), ARRAY(contentOrigin, i));            
        }

    }
 
    m_preScrollDir = scrollDir;

    VFX_LOG(VFX_INFO2, VCP_BASEMENU_SET_VALID_CONTENT_MSG, TRC_RECT(validRect));
    setValidContentRect(validRect);

    VFX_LOG(VFX_INFO2, VCP_BASEMENU_SET_WARNING_CONTENT_MSG, TRC_RECT(warnRect));
    setWarningContentRect(warnRect);

#ifdef __MAUI_SOFTWARE_LA__
      SLA_CustomLogging("BCV", SA_stop);
#endif
    return validRect;
}

VfxSize VcpBaseMenu::getLayoutContentSize()
{
    VfxS32 sz = m_layout->getTotalLength();
     
    VfxRect b = m_view->getBounds();


    if (m_layout->isScrollVert())
    {
        return VfxSize(b.size.width, sz);
    }
    else
    {
        return VfxSize(sz, b.size.height);
    }
}

void VcpBaseMenu::onUpdate()
{
#ifdef __MAUI_SOFTWARE_LA__
      SLA_CustomLogging("BUP", SA_start);
#endif   
    VFX_LOG(VFX_INFO2, VCP_BASEMENU_ONUPDATE_MSG);

    VcpScrollable::onUpdate();

    VfxRect targetView  = m_view->getBounds();
    VfxPoint contentOrigin = getContentOrigin();

    if (m_needRelayout)
    {
        VFX_LOG(VFX_INFO2, VCP_BASEMENU_DO_RELAYOUT_MSG);

#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("BRL", SA_start);
#endif   
        VfxS32 sz = m_layout->getTotalLength();
       
        if (sz != m_contentLength)
        {
            VfxSize contentSize = getLayoutContentSize();
            m_contentLength = sz;
            setContentSize(contentSize);

            VfxPoint pt(
                    VFX_MAX(VFX_MIN(targetView.origin.x, contentOrigin.x + contentSize.width - targetView.size.width), contentOrigin.x),
                    VFX_MAX(VFX_MIN(targetView.origin.y, contentOrigin.y + contentSize.height - targetView.size.height), contentOrigin.y)
            );
            scrollContent(pt, VFX_TRUE);

            

        }        
        m_needRelayout = VFX_FALSE;
        m_needCellRelayout = VFX_TRUE;
        checkUpdate();


#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("BRL", SA_stop);
#endif   

#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("BUP", SA_stop);
#endif   
        return;
    }

    // Since APP may call make visible after reset, onInit, ....
    // So make visible will become async as well.
    if (m_pVisibleView && (m_state == Opening || m_state == Normal))
    {
       
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("BVV", SA_start);
#endif  
        bool isAnim = (m_pVisibleView->flag & VCP_BASEMENU_VISIBLEVIEW_FLAG_ANIM) != 0;

        // If no cell, disable scroll animation
        if (!m_preExistCell)
        {
            isAnim = VFX_FALSE;
        }

        if (m_pVisibleView->flag & VCP_BASEMENU_VISIBLEVIEW_FLAG_OFFSET)
        {
            // get view's bounds
            VfxRect r = m_view->getBounds();
            // offset the rect
            r.origin = m_pVisibleView->contentOffset;
            // fix the rect because it may out of bounds
            VfxPoint pt = calVisibleOffset(r);
            // scroll the view
            scrollContent(pt, isAnim);
        }

        if (m_pVisibleView->flag & VCP_BASEMENU_VISIBLEVIEW_FLAG_FOCUS)
        {
            if (m_pVisibleView->focus.isValid() && m_layout)
            {
                m_pVisibleView->flag |= VCP_BASEMENU_VISIBLEVIEW_FLAG_RECT;
                m_pVisibleView->rect = m_layout->queryCellRect(m_pVisibleView->focus);
            }
        }
        if (m_pVisibleView->flag & VCP_BASEMENU_VISIBLEVIEW_FLAG_FOCUS_MARGIN)
        {
            if (m_pVisibleView->focus.isValid() && m_layout)
            {
                m_pVisibleView->flag |= VCP_BASEMENU_VISIBLEVIEW_FLAG_RECT;
                m_pVisibleView->rect = m_layout->queryMarginItemRect(m_pVisibleView->focus);
            }
        }

        if (m_pVisibleView->flag & VCP_BASEMENU_VISIBLEVIEW_FLAG_RECT)
        {
            VfxPoint pt = calVisibleOffset(m_pVisibleView->rect);
            scrollContent(pt, isAnim);
        }

        VFX_FREE_MEM(m_pVisibleView);

        checkUpdate();
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("BVV", SA_stop);
#endif         

#ifdef __MAUI_SOFTWARE_LA__
              SLA_CustomLogging("BUP", SA_stop);
#endif   
        return;
    }

    if (m_needMarginItemRelayout)
    {
        m_needMarginItemRelayout = VFX_FALSE;

        for(VfxS32 i = 0; i < VCP_BASE_MENU_MARGIN_AREA_END; ++i)
        {
            for (VfxU32 j = 0; j < m_marginItemArray[i].size(); ++j)
            {
                if(m_marginItemArray[i][j].m_framePtr.get())
                {
                    onUpdateMarginItem(m_layout->queryMarginItemRect(m_marginItemArray[i][j].m_mpos),
                                                                   m_marginItemArray[i][j].m_mpos, m_marginItemArray[i][j].m_framePtr.get());
                }
                else
                {
                    removeMarginItem(VcpMenuPos(i, j));
                }                
            }         
        }       
        checkUpdate();
        return ;
    }
    
    


    VfxRect             validRect   = calValidView();

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("BQV", SA_start);
#endif      
    VcpMenuRegion       rgn         = m_layout->queryRegion(validRect);  
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("BQV", SA_stop);
#endif  

    VcpMenuRegion       preRegion   = m_curRegion;

    m_curRegion     = rgn;

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("BQT", SA_start);
#endif  
    m_targetRegion  = m_layout->queryRegion(targetView);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("BQT", SA_stop);
#endif  

    TRACE(("m_curRegion: %d %d - %d %d\n", rgn.begin.group, rgn.begin.pos, rgn.end.group, rgn.end.pos));

    // Clear hit first
    m_cache.clearHitFlag();
   
    // clear unneed cell first
    VcpMenuRegionIter   itr(m_layout, m_curRegion);
    while(!itr.isEnd())
    {
        VcpMenuPos p = itr.next();
        TRACE(("<%d %d>", p.group, p.pos));
        m_cache.hit(p);
    }
    TRACE(("\n"));

    m_cache.clearIfNotHit();

    onBeforeUpdate(m_curRegion, m_targetRegion);

     itr.reset(m_layout, rgn);
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("BIC", SA_start);
#endif 
     while(!itr.isEnd())
     {
         VcpMenuPos p = itr.next();
     
         if (!m_needCellRelayout && preRegion.isWithin(p))
         {
             continue; // this cell is in screen
         }
     
         VfxU32 flag = 0;
     
         // Add Opeing flag
         if (m_state == Opening)
         {
            flag |= VCP_CELL_FLAG_OPENING;
         }
         else if (m_state == Closing)
         {
            flag |= VCP_CELL_FLAG_CLOSING;
         }
     
         // Add Target flag
         if (m_targetRegion.isWithin(p))
         {
            flag |= VCP_CELL_FLAG_TARGET;
         }
     
     
         getCell(p, flag);
     
         VfxRect r;       
     
         if (p.isGroupHeader())
         {
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("BQH", SA_start);
#endif 
             r = m_layout->queryGroupHeaderRect(p.group);
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("BQH", SA_stop);
#endif
         }
         else
         {
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("BQC", SA_start);
#endif
             r = m_layout->queryCellRect(p);
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("BQC", SA_stop);
#endif
         }
        
         // Speed up, if there is no content, and we are in closing state, just ignore update cell.
         if (!(m_preExistCell == VFX_FALSE && (flag & VCP_CELL_FLAG_CLOSING)))
         {
             updateCell(r, p, flag);            
         }
        
     }
 
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("BIC", SA_stop);
#endif     
    if (m_state == Opening)
    {
        m_state = Normal;
    }

    if (m_state == Closing)
    {
        if (IsSupportTransition())
        {
            m_timer->setStartDelay(m_closingTimeMS);
            m_timer->start();
            m_state = WaitClosing;
        }
        else
        {
            // directly reset all content
            vfxPostInvoke0(this, &VcpBaseMenu::resetInternal);
        }
    }
    
    if (m_cache.getCount() > 0)
    {
        m_preExistCell = VFX_TRUE;     // we have context
    }
    m_curValidRect          = validRect;
    m_forceResetScrollPos   = VFX_FALSE;
    m_needCellRelayout      = VFX_FALSE;

    TRACE(("CELL Count: %d\n", m_cache.getCount()));

    onAfterUpdate(m_curRegion, m_targetRegion);
#ifdef __MAUI_SOFTWARE_LA__
      SLA_CustomLogging("BUP", SA_stop);
#endif       
}

void VcpBaseMenu::onTimerTick(VfxTimer *source)
{
    VFX_UNUSED(source);
    if (m_state == WaitClosing)
    {
        VFX_LOG(VFX_INFO2, VCP_BASEMENU_RESET_ALL_MSG);

        resetInternal();
    }
}

VfxFrame* VcpBaseMenu::getCellIfPresent(VfxS32 group, VfxS32 pos)
{
    if (m_cache.getFlag(group, pos) & VCP_MENUCACHE_FLAG_DUMMY)
    {
        return NULL;
    }
    VfxFrame* cell = m_cache.getItem(group, pos);
    return cell;
}

VfxFrame* VcpBaseMenu::getHeaderIfPresent(VfxS32 group)
{
    VfxFrame* cell = m_cache.getItem(group, -1);
    return cell;
}

void VcpBaseMenu::onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos preFocusItem)
{
    VFX_UNUSED(focusItem);
    VFX_UNUSED(preFocusItem);
}

void VcpBaseMenu::onDragStart()
{
}

void VcpBaseMenu::onDragEnd()
{
    if (getLayout())
    {
        VfxPoint pos = m_view->getBounds().origin;
        getLayout()->onStopPosFix(pos);
        if (pos != m_view->getBounds().origin)
        {
            setContentOffset(pos, VFX_TRUE);
        }
    }
}

void VcpBaseMenu::onViewScrollStart()
{
    TRACE(("<<< onViewScrollStart >>>\n"));
}

void VcpBaseMenu::onViewScrollEnd()
{
    TRACE(("<<< onViewScrollEnd >>>\n"));
}


void VcpBaseMenu::onScrollStopPosFix(VfxPoint& pos)
{
    VFX_LOG(VFX_INFO2, VCP_BASEMENU_BEFORE_SCROLL_FIX_MSG, pos.x, pos.y);

    if (getLayout())
    {
        getLayout()->onStopPosFix(pos);
        VFX_LOG(VFX_INFO2, VCP_BASEMENU_AFTER_SCROLL_FIX_MSG, pos.x, pos.y);
    }
}

VfxBool VcpBaseMenu::IsSupportTransition()
{
    return VFX_TRUE;
}

void VcpBaseMenu::onContentWarning(VcpScrollableView* sender)
{
    m_isContentWarning = VFX_TRUE;
    VFX_UNUSED(sender);
    VFX_LOG(VFX_INFO2, VCP_BASEMENU_ON_CONTENT_WARNING_MSG);
    checkUpdate();
}

void VcpBaseMenu::notifyScrollStart(VcpScrollable* sender)
{
    VFX_UNUSED(sender);
//    ASSERT(m_isScrolling == VFX_FALSE);
    m_isScrolling = VFX_TRUE;
    

    if (m_view->m_isTracking)
    {
        m_isPenProcessing = VFX_TRUE;
        TRACE(("<<<< onDragStart ...\n"));
        VFX_LOG(VFX_INFO2, VCP_BASEMENU_ON_DRAG_START_MSG);
        onDragStart();
    }
    

    VFX_LOG(VFX_INFO2, VCP_BASEMENU_EMIT_SCROLL_START_MSG);
    onViewScrollStart();

}

void VcpBaseMenu::notifyScrollEnd(VcpScrollable* sender)
{
    VFX_UNUSED(sender);
//    ASSERT(m_isScrolling == VFX_TRUE);
    m_isScrolling = VFX_FALSE;

    if (m_isPenProcessing)
    {
        m_isPenProcessing = VFX_FALSE;
        TRACE((".... onDragEnd >>>>\n"));
        VFX_LOG(VFX_INFO2, VCP_BASEMENU_ON_DRAG_END_MSG);
        onDragEnd();
    }

    VFX_LOG(VFX_INFO2, VCP_BASEMENU_EMIT_SCROLL_END_MSG);
    onViewScrollEnd();

    //when free run end, checkUpdate to restore cache range back to normal size 
    if (m_cacheStyle == VCP_BASE_MENU_CACHE_STYLE_CENTER)
    {
        m_isContentWarning = VFX_TRUE;
        checkUpdate();
    }
}

void VcpBaseMenu::tapView(const VfxPoint &pt)
{
    VFX_LOG(VFX_INFO2, VCP_BASEMENU_EMIT_TAP_MSG, pt.x, pt.y);
    onTap(pt);
}

VcpMenuPos VcpBaseMenu::hitTestCell(const VfxPoint &pt)
{
    VcpMenuRegionIter itr(this, getRealContentRegion());
    while(!itr.isEnd())
    {
        VcpMenuPos p = itr.next();
        VfxFrame* item = m_cache.getItem(p);

        if (item == NULL)
        {
            continue;
        }

        // do hit test
        // VFX_DEV_ASSERT(m_view == item->getParentFrame());
        VfxPoint localpt = m_view->convertPointTo(pt, item);
    
        if (item->getBounds().contains(localpt))
        {
            return p;
        }
    }
    return VcpMenuPos();
}

void VcpBaseMenu::penDown(const VfxPoint &pt)
{
    VcpMenuPos p = hitTestCell(pt);
    VfxFrame* item = m_cache.getItem(p);

    if (item == NULL)
    {
        return;
    }

    VfxPoint cellPt = m_view->convertPointTo(pt, item);
    m_clickedCell = item;
    m_clickedPos = p;

    VFX_LOG(VFX_INFO2, VCP_BASEMENU_EMIT_TOUCH_DM_CELL_MSG, p.group, p.pos, cellPt.x, cellPt.y);

#if !defined(__MMI_VUI_COSMOS_CP__)
#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
#endif
#endif /* !defined(__MMI_VUI_COSMOS_CP__) */

    onTouchCell(p, VcpBaseMenu::TouchDown, cellPt, item);
}

void VcpBaseMenu::penUp(const VfxPoint &pt)
{
    if (m_clickedCell.get())
    {
        VfxPoint cellPt = m_view->convertPointTo(pt, m_clickedCell.get());
        VFX_LOG(VFX_INFO2, VCP_BASEMENU_EMIT_TOUCH_UP_CELL_MSG, TRC_POS(m_clickedPos), TRC_POINT(cellPt));
        onTouchCell(m_clickedPos, VcpBaseMenu::TouchUp, cellPt, m_clickedCell.get());
        m_clickedCell = NULL;
        m_clickedPos.invalid(); 
    }
}

void VcpBaseMenu::penLongDown(const VfxPoint &pt)
{
    if (m_clickedCell.get())
    {
        VfxPoint cellPt = m_view->convertPointTo(pt, m_clickedCell.get());
        //VFX_LOG(VFX_INFO2, VCP_BASEMENU_EMIT_TOUCH_UP_CELL_MSG, TRC_POS(m_clickedPos), TRC_POINT(cellPt));
        onTouchCell(m_clickedPos, VcpBaseMenu::TouchLongTap, cellPt, m_clickedCell.get());
    }
}

void VcpBaseMenu::penAbort(const VfxPoint &pt)
{
    // we do the same thing as penUp without tap event
    if (m_clickedCell.get())
    {
        VfxPoint cellPt = m_view->convertPointTo(pt, m_clickedCell.get());
        VFX_LOG(VFX_INFO2, VCP_BASEMENU_EMIT_TOUCH_UP_CELL_MSG, TRC_POS(m_clickedPos), TRC_POINT(cellPt));
        onTouchCell(m_clickedPos, VcpBaseMenu::TouchUp, cellPt, m_clickedCell.get());
        m_clickedCell = NULL;
        m_clickedPos.invalid(); 
    }
}

void VcpBaseMenu::onTap(const VfxPoint &pt)
{
    VfxFrame* item = m_clickedCell.get();

    if (item == NULL)
    {
        return;
    }

    VfxPoint cellPt = m_view->convertPointTo(pt, item);

    if (!item->getBounds().contains(cellPt))
    {
        // the pen has out side the cell
        return;
    }

    if (m_clickedPos.isGroupHeader())
    {
        onTapGroupHeader(m_clickedPos.group, item);
    }
    else
    {
        onTapCell(m_clickedPos.group, m_clickedPos.pos, item);
    }

    if (m_clickedCell.get())
    {
        VFX_LOG(VFX_INFO2, VCP_BASEMENU_EMIT_TOUCH_TAP_CELL_MSG, TRC_POS(m_clickedPos), TRC_POINT(cellPt));
        onTouchCell(m_clickedPos, VcpBaseMenu::TouchTap, cellPt, item);
    }
}

void VcpBaseMenu::dragView(VfxBool isDrag, const VfxPoint& pt, const VfxPoint& down_pt)
{
    if (isDrag)
    {
        VFX_LOG(VFX_INFO2, VCP_BASEMENU_ON_DRAG_MSG, pt.x - down_pt.x, pt.y - down_pt.y);
        onDrag(pt.x - down_pt.x, pt.y - down_pt.y);
    }
}

void VcpBaseMenu::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    VFX_UNUSED(xoffset);
    VFX_UNUSED(yoffset);
}


void VcpBaseMenu::closeGroupHeader(VfxS32 group)
{
    VcpMenuPos p(group, -1);
    delCell(p);
}

void VcpBaseMenu::closeCell(VfxS32 group, VfxS32 pos)
{
    VcpMenuPos p(group, pos);
    delCell(p);
}

void VcpBaseMenu::swapCell(VcpMenuPos pos1, VcpMenuPos pos2)
{
    VFX_LOG(VFX_INFO2, VCP_BASEMENU_SWAP_CELL_MSG, TRC_POS(pos1), TRC_POS(pos2));

    if (pos1 == pos2)
    {
        return;
    }

    VfxFrame* item1 = m_cache.getItem(pos1);
    VfxFrame* item2 = m_cache.getItem(pos2);

    if (item1)
    {
        m_cache.setItem(pos2, item1);
    }
    else
    {
        m_cache.removeItem(pos2);
    }

    if (item2)
    {
        m_cache.setItem(pos1, item2);
    }
    else
    {
        m_cache.removeItem(pos1);
    }
    
    m_needCellRelayout = VFX_TRUE;
    checkUpdate();
}

void VcpBaseMenu::getViewState(VcpBaseMenuViewState* history)
{
    if (history == NULL)
        return;

    history->contentXOffset = m_view->getBounds().origin.x;
    history->contentYOffset = m_view->getBounds().origin.y;
    history->focusGroup = getLayout()->getFocusItem().group;
    history->focusPos = getLayout()->getFocusItem().pos;

    if (m_pVisibleView)
    {
        if (m_pVisibleView->flag & VCP_BASEMENU_VISIBLEVIEW_FLAG_OFFSET)
        {
            history->contentXOffset = m_pVisibleView->contentOffset.x;
            history->contentYOffset = m_pVisibleView->contentOffset.y;           
        }
        if (m_pVisibleView->flag & VCP_BASEMENU_VISIBLEVIEW_FLAG_FOCUS)
        {
            history->focusGroup = m_pVisibleView->focus.group;
            history->focusPos = m_pVisibleView->focus.pos;           
        }
    }
}

void VcpBaseMenu::setViewState(VcpBaseMenuViewState* history)
{
    if (history == NULL)
        return;

    if (m_pVisibleView == NULL)
    {
        VFX_ALLOC_MEM(m_pVisibleView, sizeof(VisibleView), this);
    }
    memset(m_pVisibleView, 0, sizeof(VisibleView));

    VfxPoint pt(history->contentXOffset, history->contentYOffset);
    if (pt != VfxPoint(0, 0))
    {
        m_pVisibleView->flag |= VCP_BASEMENU_VISIBLEVIEW_FLAG_OFFSET;
        m_pVisibleView->contentOffset = pt;
    }

    VcpMenuPos pos(history->focusGroup, history->focusPos);
    if (pos.isValid())
    {
        m_pVisibleView->flag |= VCP_BASEMENU_VISIBLEVIEW_FLAG_FOCUS;
        m_pVisibleView->focus = pos;
    }

    checkUpdate();
}

VfxFrame* VcpBaseMenu::pullOutCell(VcpMenuPos pos)
{
    VfxFrame* item = m_cache.getItem(pos);

    if (item == NULL)
    {
        return NULL;
    }

    VfxFrame* dummyFrame;
    VFX_OBJ_CREATE(dummyFrame, VfxFrame, this);
    dummyFrame->setOpacity(0);

    m_cache.setItem(pos, dummyFrame);
    m_cache.setDummyFlag(pos, VFX_TRUE);

    return item;
}

void VcpBaseMenu::withdrawCell(VfxS32 group, VfxS32 pos)
{
    // delete item first
    VcpMenuPos p(group, pos);
    delCell(p);

    // shift item index in the group
    
    // We don't need to care header
    if (pos < 0)
    {
        return;
    }

    m_cache.withdrawItem(group, pos);
    updateLayout();
}

void VcpBaseMenu::putinCell(VfxS32 group, VfxS32 pos)
{

    m_cache.putinItem(group, pos);
    updateLayout();
}

#if defined(__MMI_VUI_COSMOS_CP__)
void vcpBaseMenuLayoutQueryMarginRectByPt(VcpBaseMenu * menu, VcpBaseMenuLayout * layout, const VfxPoint &p, VfxRect & result)
{
    for(VfxS32 i = 0; i < VCP_BASE_MENU_MARGIN_AREA_END; ++i)
    {
        for (VfxU32 j = 0; j < menu->m_marginItemArray[i].size(); ++j)
        {               
            VfxRect r = layout->queryMarginItemRect(menu->m_marginItemArray[i][j].m_mpos);
            if (r.contains(p))
            {
                result = r;
                return;
            }
        }    
    }
    result = VFX_RECT_ZERO;
}

static void vcpBaseMenuNavDirQueryGroupHeaderHelper(VcpBaseMenuLayout * layout, const VcpMenuPos & newPos, VfxRect & result)
{
    result = (newPos.pos == -1) ? (layout->queryGroupHeaderRect(newPos.group)) : (layout->queryCellRect(newPos));
}

static void vcpBaseMenuNavDirModifyMarginHelper(VcpBaseMenu * menu, VcpBaseMenuLayout * layout, const VcpMenuPos & newPos, VfxS32 x, VfxS32 y, const VfxRect & orgRect, VfxRect & result)
{
    if(newPos.isValid())
    {
        vcpBaseMenuNavDirQueryGroupHeaderHelper(layout, newPos, result);
    }
    else
    {
        VfxRect r;
        vcpBaseMenuLayoutQueryMarginRectByPt(menu, layout, VfxPoint(x, y), r);
        result = r == VFX_RECT_ZERO ? orgRect : r;
    }
}

VfxBool vcpBaseMenuNavDirHelper(VcpBaseMenu * menu, VcpBaseMenuLayout * layout, VcpBaseMenuLayout::NavDirEnum dir, const VcpMenuPos & pos, const VcpMenuPos & newPos, VfxRect & targetRect)
{
    VfxRect rect;
    vcpBaseMenuNavDirQueryGroupHeaderHelper(layout, pos, rect);

    if (dir == VcpBaseMenuLayout::NAV_DIR_UP)
    {       
        if(targetRect.getMinY() <= rect.getMinY())
        {
            vcpBaseMenuNavDirModifyMarginHelper(menu, layout, newPos, targetRect.origin.x, targetRect.origin.y, targetRect, rect);
        }
        else if(targetRect.getMinY() < rect.getMaxY() && targetRect.getMinY() >= rect.getMinY())
        {
            rect = targetRect;
            rect.origin.y -= rect.size.height;
        }
        targetRect.origin.y = rect.getMaxY() - targetRect.getHeight() + 1;
    }
    else // (dir == NAV_DIR_DOWN)
    {
        if (targetRect.getMaxY() >= rect.getMaxY())
        {
            vcpBaseMenuNavDirModifyMarginHelper(menu, layout, newPos, targetRect.getMaxX(), targetRect.getMaxY(), targetRect, rect);
        }
        else if(targetRect.getMaxY() > rect.getMinY() && targetRect.getMaxY() <= rect.getMaxY())
        {           
            rect = targetRect;
            rect.origin.y += rect.size.height;
        }
        targetRect.origin.y = rect.getMinY();
    }
    return VFX_TRUE;
}


#else // defined(__MMI_VUI_COSMOS_CP__)
VcpMenuPos vcpBaseMenuLayoutQueryMarginItemByPt(VcpBaseMenu * menu, VcpBaseMenuLayout * layout, const VfxPoint &p)
{
    for(VfxS32 i = 0; i < VCP_BASE_MENU_MARGIN_AREA_END; ++i)
    {
        for (VfxS32 j = 0; j < menu->m_marginItemArray[i].size(); ++j)
        {
            VfxRect r = layout->queryMarginItemRect(menu->m_marginItemArray[i][j].m_mpos);
            if (r.contains(p))
            {
                return VcpMenuPos(i, j);
            }
        }
    }
    return VcpMenuPos();
}
#endif // defined(__MMI_VUI_COSMOS_CP__)

VfxRect queryMarginItemRectHelper(VcpBaseMenu * menu, VcpBaseMenuLayout * layout, const VfxRect & viewRect, VcpMenuPos pos, VfxBool reverse)
{
    if(pos.group < 0 || pos.group >= VCP_BASE_MENU_MARGIN_AREA_END || 
        menu->m_marginItemArray[pos.group].size() == 0 || (VfxS32)menu->m_marginItemArray[pos.group].size() < pos.pos)
    {
        return VFX_RECT_ZERO;
    }

    VfxFrame *frame = menu->getMarginItem(pos);
    VfxS32 x = frame->getPos().x, y = 0;    
    VfxS32 w = frame->getSize().width, h = frame->getSize().height;    
    VfxS32 vw = viewRect.size.width;

    switch (menu->m_marginItemArray[pos.group][pos.pos].m_placement)
    {
        case VCP_BASE_MENU_MARGIN_AREA_FRAME_PLACEMENT_CENTER:
            x = (vw - w) / 2;
            break;

        case VCP_BASE_MENU_MARGIN_AREA_FRAME_PLACEMENT_LEFT:
            x = 0;
            break;

        case VCP_BASE_MENU_MARGIN_AREA_FRAME_PLACEMENT_RIGHT:
            x = vw - w;
            break;
        case VCP_BASE_MENU_MARGIN_AREA_FRAME_PLACEMENT_FULL:
            x = 0;
            w = vw;
            break;
        default:
            VFX_ASSERT(0);
            break;
    }

    if (pos.group == VCP_BASE_MENU_MARGIN_AREA_TOP)
    {
        if (reverse)
        {
            VfxS32 offset = VFX_MAX(0, viewRect.getHeight() - layout->getTotalLength());
            y = - layout->getMarginLength(VCP_BASE_MENU_MARGIN_AREA_BOTTOM) - layout->getContentLength() - menu->m_marginItemArray[pos.group][pos.pos].m_accumulatedLength - offset;
        }
        else
        {
            y = menu->m_marginItemArray[pos.group].back().m_accumulatedLength - menu->m_marginItemArray[pos.group][pos.pos].m_accumulatedLength;         
        }
    }
    else if (pos.group == VCP_BASE_MENU_MARGIN_AREA_BOTTOM)
    {
        if (reverse)
        {
            y = - menu->m_marginItemArray[pos.group].back().m_accumulatedLength;
        }
        else
        {
            y = layout->getMarginLength(VCP_BASE_MENU_MARGIN_AREA_TOP) + layout->getContentLength();            
        }               

        if (pos.pos > 0)
        {
            y += menu->m_marginItemArray[pos.group][pos.pos - 1].m_accumulatedLength;            
        }
    }    

    return VfxRect(x, y, w, h);
}

