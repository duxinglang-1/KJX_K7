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
 *  vtst_nonconst_menu.cpp
 *
 * Project:
 * --------
 *  Venus Regression Test for menu
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
#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vtst_nonconst_menu.h"
#include "vcp_base_menu.h"
#include "vfx_sys_memory.h"
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "kal_public_api.h"
#include "vrt_datatype.h"
#include "kal_general_types.h"
#include "vfx_basic_type.h"
#include "vfx_object.h"
#include "vfx_frame.h"

/*****************************************************************************
 * Menu Test Implementation
 *****************************************************************************/

/*****************************************************************************
 * class VtstNonconstMenuLayout
 *****************************************************************************/

VtstNonconstMenuLayout::VtstNonconstMenuLayout(VtstNonconstMenu* menu) :
    VcpBaseMenuLayout(menu),
    m_nonconstMenu(menu),
    m_accumulateSizeArray(NULL),
    m_count(0)
{
}

VtstNonconstMenuLayout::~VtstNonconstMenuLayout()
{
    VFX_SYS_FREE_MEM(m_accumulateSizeArray);
}

void VtstNonconstMenuLayout::onInit()
{
    VcpBaseMenuLayout::onInit();
}

void VtstNonconstMenuLayout::setLayoutData()
{
    VfxU32 count = m_nonconstMenu->getNonconstCellCount();
    if (m_count == count)
    {
        return;
    }
    VFX_ASSERT(count > m_count);

    VfxU32 * newAccumulateSizeArray;
    VFX_SYS_ALLOC_MEM(newAccumulateSizeArray, count * sizeof(VfxU32));

    if (m_count == 0)
    {
        newAccumulateSizeArray[0] = m_nonconstMenu->getNonconstCellHeight(0);
        for (VfxU32 i = 1; i < count; ++i)
        {
            newAccumulateSizeArray[i] = newAccumulateSizeArray[i-1] + m_nonconstMenu->getNonconstCellHeight(i);
        }
    }
    else
    {
        VfxU32 i;
        for (i = 0; i < m_count; ++i)
        {
            newAccumulateSizeArray[i] = m_accumulateSizeArray[i];
        }
        for (i = m_count; i < count; ++i)
        {
            newAccumulateSizeArray[i] = newAccumulateSizeArray[i-1] + m_nonconstMenu->getNonconstCellHeight(i);
        }
    }
    VFX_SYS_FREE_MEM(m_accumulateSizeArray);
    m_accumulateSizeArray = newAccumulateSizeArray;
    m_count = m_nonconstMenu->getNonconstCellCount();
}

VtstNonconstMenuLayout::ScrollDirEnum VtstNonconstMenuLayout::getScrollDir()
{
    return SCROLLDIR_VERT;
}

VfxS32 VtstNonconstMenuLayout::getCellCount(VfxS32 group)
{
    VFX_UNUSED(group);

    if (m_count != m_nonconstMenu->getNonconstCellCount() )
    {
        setLayoutData();
    }
    return m_count;
}

VfxS32 VtstNonconstMenuLayout::getContentLength()
{
    if (m_count != m_nonconstMenu->getNonconstCellCount() )
    {
        setLayoutData();
    }
    return m_accumulateSizeArray[m_count - 1];
}

VcpMenuRegion VtstNonconstMenuLayout::queryRegion(const VfxRect& r)
{
    if (m_count != m_nonconstMenu->getNonconstCellCount() )
    {
        setLayoutData();
    }
    return VcpMenuRegion(
        getCellByPos(r.origin),
        getCellByPos(VfxPoint(r.getMaxX(), r.getMaxY()))
    );
}

VfxRect VtstNonconstMenuLayout::queryCellRect(VcpMenuPos pos)
{
    if (m_count != m_nonconstMenu->getNonconstCellCount() )
    {
        setLayoutData();
    }

    VfxU32 y;
    VfxU32 height;
    if (0 == pos.pos)
    {
        y = 0;
        height = m_accumulateSizeArray[0];
    }
    else
    {
        y = m_accumulateSizeArray[pos.pos - 1];
        height = m_accumulateSizeArray[pos.pos] - m_accumulateSizeArray[pos.pos - 1];
    }
    VfxU32 layoutWidth = m_nonconstMenu->getSize().width;
    VfxRect result(0, y, layoutWidth, height);
    return result;
}

void VtstNonconstMenuLayout::onViewChanged()
{
    m_nonconstMenu->onNonconstViewChanged(getViewPos().y);
}

VcpMenuPos VtstNonconstMenuLayout::getCellByPos(VfxPoint pt)
{
    VcpMenuPos p;
    p.group = 0;
    VfxU32 i;
    for (i = 0; i < m_count; ++i)
    {
        if (static_cast<VfxS32>(m_accumulateSizeArray[i]) > pt.y) // signed compare
            break;
    }
    p.pos = i;
    return p;
}

/*****************************************************************************
 * VtstNonconstMenu
 *****************************************************************************/
VtstNonconstMenu::VtstNonconstMenu()
{
}

void VtstNonconstMenu::onInit()
{
    VcpBaseMenu::onInit();
}

VcpBaseMenuLayout* VtstNonconstMenu::createLayout()
{
    VtstNonconstMenuLayout* layout;
    VFX_OBJ_CREATE_EX(layout, VtstNonconstMenuLayout, this, (this));
    return layout;
}

void VtstNonconstMenu::onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag)
{
    cell->setRect(rect);
}

void VtstNonconstMenu::onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame)
{
    VFX_OBJ_CLOSE(cellFrame);
}

void VtstNonconstMenu::onNonconstViewChanged(VfxS32 y)
{
}

#endif // __AFX_RT_TEST__

