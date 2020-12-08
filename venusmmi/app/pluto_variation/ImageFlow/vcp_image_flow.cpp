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

/*******************************************************************************
 * Filename:
 * ---------
 *  vcp_image_flow.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Venus test application. This file is in mmi_framework module.
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_image_flow.h"
#include "math.h"
#include "vcp_base_menu.h"
#include "vfx_basic_type.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vfx_keypad.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_frame.h"
#include "vrt_datatype.h"
#include "vcp_content_clone.h"
#include "vfx_signal.h"
#include "vfx_transform.h"
#include "vcp_wheel_menu.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
/*
#ifdef _WIN32
extern "C" void __stdcall OutputDebugStringA(char* str);
#else
#   define OutputDebugStringA(str)
#endif
static char tmp_buffer[256];
*/
/***************************************************************************** 
 * Local Variable
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/***************************************************************************** 
 * Class VcpImageFlowLayout
 *****************************************************************************/
 
VcpImageFlowLayout::VcpImageFlowLayout(VcpBaseMenu* menu):
    VcpBaseMenuLayout(menu),
    m_cellNumber(0),
    m_focusCellWidth(0),
    m_secCellWidth(0),
    m_cellWidth(1),
    m_cellHeight(0),
    m_margin(0)
{
}


VcpMenuPos VcpImageFlowLayout::getCellByPos(VfxPoint pt)
{
    VcpMenuPos p;
    VfxS32 focus = getFocusItem().pos;
    VfxS32 focusOrigin;
    VfxS32 focusLeftOrigin;
    VfxS32 focusRightOrigin;
    
    if (focus == 0)
    {
        focusLeftOrigin = 0;
        focusOrigin = m_margin;
        focusRightOrigin = focusOrigin + m_focusCellWidth;
    }
    else
    {
        focusLeftOrigin = (focus - 1) * m_cellWidth + m_margin;
        focusOrigin = focusLeftOrigin + m_secCellWidth;
        focusRightOrigin = focusOrigin + m_focusCellWidth;
    }
    
    p.group = 0;
    
    if (pt.x < focusLeftOrigin)
    {
        p.pos = (pt.x - m_margin)/m_cellWidth;
    }
    else if (pt.x < focusOrigin)
    {
        p.pos = focus - 1;
    }
    else if (pt.x < focusRightOrigin)
    {
        p.pos = focus;
    }
    else if (pt.x < focusRightOrigin + m_secCellWidth)
    {
        p.pos = focus + 1;
    }
    else
    {
        p.pos = (pt.x - (focusRightOrigin + m_secCellWidth))/m_cellWidth + getFocusItem().pos + 2;
    }

    if (p.pos < 0)
    {
        p.pos = 0;
    }
    
    if (p.pos >= m_cellNumber)
    {
        p.pos = m_cellNumber-1;
    }
    return p;
}


void VcpImageFlowLayout::setCellNumber(VfxS32 number)
{
    m_cellNumber = number;
    update();
}


void VcpImageFlowLayout::setCellWidth(VfxS32 width)
{
    m_cellWidth = width;
    update();
}


void VcpImageFlowLayout::setCellHeight(VfxS32 height)
{
    m_cellHeight = height;
    update();
}


void VcpImageFlowLayout::setFocusCellWidth(VfxS32 width)
{
    m_focusCellWidth = width;
    m_margin = (getViewSize().width - m_focusCellWidth)/2;
    update();
}


void VcpImageFlowLayout::setSecCellWidth(VfxS32 width)
{
    m_secCellWidth = width;
    update();
}


void VcpImageFlowLayout::setCellParameter(VfxS32 number, VfxS32 focusCellWidth, VfxS32 secCellWidth, VfxS32 cellWidth, VfxS32 cellHeight)
{
    m_cellNumber = number;
    m_cellWidth = cellWidth;
    m_cellHeight = cellHeight;
    m_focusCellWidth = focusCellWidth;
    m_secCellWidth = secCellWidth;
    m_margin = (getViewSize().width - m_focusCellWidth)/2;
    update();
}


int VcpImageFlowLayout::getCellCount(VfxS32 group)
{
    VFX_UNUSED(group);
    return m_cellNumber;
}


VfxS32 VcpImageFlowLayout::getContentLength()
{
    return m_focusCellWidth + m_secCellWidth * 2 + (m_cellNumber-3) * m_cellWidth + 2 * m_margin;
}


VcpMenuRegion VcpImageFlowLayout::queryRegion(const VfxRect & rect)
{
    return VcpMenuRegion(
            getCellByPos(rect.origin),
            getCellByPos(VfxPoint(rect.getMaxX(), rect.getMaxY()))
        );
}


VfxRect VcpImageFlowLayout::queryCellRect(VcpMenuPos pos)
{
    VfxPoint origin;
    VfxSize size;
    VfxS32 focus = getFocusItem().pos;

    origin.y = 0;

    if (pos.pos < focus)
    {
        origin.x = pos.pos * m_cellWidth + m_margin;
        if (pos.pos == focus - 1)
        {
            size = VfxSize(m_secCellWidth,m_cellHeight);
        }
        else
        {
            size = VfxSize(m_cellWidth,m_cellHeight);
        }
    }
    else if (pos.pos == focus)
    {
        origin.x = (pos.pos - 1) * m_cellWidth + m_secCellWidth + m_margin;
        size = VfxSize(m_focusCellWidth, m_cellHeight);
    }
    else if (pos.pos == focus + 1)
    {
        origin.x = (pos.pos - 2) * m_cellWidth + m_secCellWidth + m_focusCellWidth + m_margin;
        size = VfxSize(m_secCellWidth,m_cellHeight);
    }
    else
    {
        origin.x = (pos.pos - 3) * m_cellWidth + 2 * m_secCellWidth + m_focusCellWidth + m_margin;
        size = VfxSize(m_cellWidth,m_cellHeight);
    }
    
    return VfxRect(origin,size);
}


void VcpImageFlowLayout::onViewChanged()
{
    VfxS32 shift;
    VfxS32 centerX = getViewPos().x + getViewSize().width/2;
    VfxS32 newFocusX = getNewFocusByX(centerX, shift);
    VfxS32 oldFocus = getFocusItem().pos;
    if (newFocusX != oldFocus)
    {
        setFocusItem(VcpMenuPos(0,newFocusX), VFX_FALSE);
    }
}


VfxBool VcpImageFlowLayout::navDir(NavDirEnum dir)
{
    VFX_UNUSED(dir);
    return VFX_FALSE;
}


void VcpImageFlowLayout::getPreferFocusMargin(VfxS32 margin[4])
{
    margin[0] = (m_pMenu->getBounds().getWidth() - m_focusCellWidth)/2;
    margin[1] = 0;
    margin[2] = margin[0];
    margin[3] = 0;
}


void VcpImageFlowLayout::onStopPosFix(VfxPoint& pos)
{
    VfxS32 shift;
    VfxS32 centerX = pos.x + getViewSize().width/2;
    getNewFocusByX(centerX, shift);
    pos.x -= shift;
}


VfxS32 VcpImageFlowLayout::getNewFocusByX(VfxS32 posX, VfxS32 &shift)
{
    VfxS32 distance = posX - (m_margin + m_focusCellWidth/2 + (m_secCellWidth - m_cellWidth) - m_cellWidth/2);
    VfxS32 newFocus = distance/m_cellWidth;
    if (newFocus < 0)
    {
        newFocus = 0;
    }
    else if (newFocus >= m_cellNumber)
    {
        newFocus = m_cellNumber - 1;
    }
    shift = distance - (newFocus * m_cellWidth + m_cellWidth/2);
    return newFocus;
}


VfxS32 VcpImageFlowLayout::getAnchorPosX(VfxS32 index)
{
    return (m_margin + m_focusCellWidth/2 + (m_secCellWidth - m_cellWidth) + m_cellWidth * index);
}

/***************************************************************************** 
 * Class VcpImageFlow
 *****************************************************************************/
#ifdef VCP_IMAGE_FLOW_REFLECTED_ENABLE
void VcpImageFlowCell::onDraw(VfxDrawContext &dc)
{
    if (!m_image->isNull())
    {
        dc.drawImage(VfxPoint(0,0), m_image);
        //dc.drawImage(VfxPoint(0,m_image->getSize().height), m_image);
        //dc.setFillColor(VfxColor(128, 0, 0, 0));
        //dc.fillRect(0, m_image->getSize().height, m_image->getSize().width, m_image->getSize().height);
    }     
}
#endif
/***************************************************************************** 
 * Class VcpImageFlow
 *****************************************************************************/

VcpImageFlow::VcpImageFlow():
    m_focusCellWidth(0),
    m_focusCellHeight(0),
    m_cellWidth(0),
    m_cellHeight(0),
    m_secCellWidth(0),
    m_secCellHeight(0),
    m_rotateAngle(90),
    m_cameraDistance(120),
    m_backDistance(20),
    m_updateBackDistance(VFX_FALSE),
    m_shift(0),
#if defined(VCP_IMAGE_FLOW_REFLECTED_ENABLE) || defined(VCP_IMAGE_FLOW_REFLECTED_ENABLE_2)
    m_shadowFactor(0.5),
#else
     m_shadowFactor(0),
#endif
    m_focusUpShift(0),
    m_contentProvider(NULL),
    m_useFPE(VFX_FALSE)
{ 
}


void VcpImageFlow::updateImageContent(VfxS32 index, VfxImageSrc &image)
{
    VcpImageFlowCell* tempFrame;
    tempFrame = (VcpImageFlowCell*)getCellIfPresent(0, index);

#if defined(VCP_IMAGE_FLOW_REFLECTED_ENABLE)
    tempFrame->m_image = image;
    tempFrame->invalidate();
#elif defined(VCP_IMAGE_FLOW_REFLECTED_ENABLE_2)
	tempFrame->m_main->setImgContent(image);
	tempFrame->invalidate();
#else
    tempFrame->setImgContent(image);
#endif
}


void VcpImageFlow::setContentProvider(IVcpImageFlowContentProvider *contentProvider)
{
    m_contentProvider = contentProvider;
}


void VcpImageFlow::setFocusIndex(VfxS32 index)
{
    m_layout->setFocusItem(VcpMenuPos(0,index));
}


void VcpImageFlow::setCellNumber(VfxS32 number)
{
    ((VcpImageFlowLayout*)m_layout)->setCellNumber(number);
}


void VcpImageFlow::setCellWidth(VfxS32 width)
{
    ((VcpImageFlowLayout*)m_layout)->setCellWidth(width);
    m_cellWidth = width;
    checkUpdate();
}


void VcpImageFlow::onUpdate()
{
    VcpBaseMenu::onUpdate();
    if (m_updateBackDistance)
    {
        m_backDistance = ((m_focusCellHeight - m_cellHeight) * m_cameraDistance) / m_cellHeight;
        m_updateBackDistance = VFX_FALSE;
    }
    updateTransform();
}


void VcpImageFlow::setCellHeight(VfxS32 height)
{
    m_cellHeight = height;
    m_updateBackDistance = VFX_TRUE;
    checkUpdate();
}


void VcpImageFlow::setFocusCellWidth(VfxS32 width)
{
    ((VcpImageFlowLayout*)m_layout)->setFocusCellWidth(width);
    m_focusCellWidth = width;
    checkUpdate();
}


void VcpImageFlow::setFocusCellHeight(VfxS32 height)
{
    ((VcpImageFlowLayout*)m_layout)->setCellHeight(height);
    m_focusCellHeight = height;
    m_updateBackDistance = VFX_TRUE;
    checkUpdate();
}


void VcpImageFlow::setCellParameter(VfxS32 number, VfxS32 focusCellWidth, VfxS32 focusCellHeight, VfxS32 secCellWidth, VfxS32 cellWidth, VfxS32 cellHeight)
{
    ((VcpImageFlowLayout*)m_layout)->setCellParameter(number, focusCellWidth, secCellWidth, cellWidth, focusCellHeight);
    m_cellWidth = cellWidth;
    m_cellHeight = cellHeight;
    m_focusCellWidth = focusCellWidth;
    m_focusCellHeight = focusCellHeight;
    m_secCellWidth = secCellWidth;
    m_updateBackDistance = VFX_TRUE;
    checkUpdate();
}


void VcpImageFlow::setRotateAngle(VfxFloat angle)
{
    m_rotateAngle = angle;
    checkUpdate();
}


void VcpImageFlow::setUpShift(VfxFloat upShift)
{
    m_upShift = upShift;
    m_useFPE = VFX_TRUE;
    checkUpdate();
}


void VcpImageFlow::setCameraDistance(VfxFloat distance)
{
    m_cameraDistance = distance;
    checkUpdate();
}


void VcpImageFlow::setCachedCellNumber(VfxS32 number)
{
    m_cacheLen = number * m_cellWidth - m_cellWidth/2 ;
}


void VcpImageFlow::setBackDistance(VfxFloat distance)
{
    m_backDistance = distance;
    m_updateBackDistance = VFX_FALSE;
}


void VcpImageFlow::setShadowFactor(VfxFloat value)
{
   m_shadowFactor = value;
   checkUpdate();
}


void VcpImageFlow::setFocusUpShift(VfxS32 upShift)
{
    m_focusUpShift = upShift;
    checkUpdate();
}


VfxS32 VcpImageFlow::getFocusIndex() const
{
    return m_layout->getFocusItem().pos;
}


VfxS32 VcpImageFlow::getCellNumber() const
{
    return m_layout->getCellCount(0);
}


VfxS32 VcpImageFlow::getCellWidth() const
{
    return m_cellWidth;
}


VfxS32 VcpImageFlow::getCellHeight() const
{
    return m_cellHeight;
}


VfxS32 VcpImageFlow::getFocusCellWidth() const
{
    return m_focusCellWidth;
}


VfxS32 VcpImageFlow::getFocusCellHeight() const
{
    return m_focusCellHeight;
}


VfxFloat VcpImageFlow::getRotateAngle() const
{
    return m_rotateAngle;
}


VfxFloat VcpImageFlow::getCameraDistance() const
{
    return m_cameraDistance;
}


VfxFloat VcpImageFlow::getBackDistance() const
{
    return m_backDistance;
}


VfxFloat VcpImageFlow::getShadowFactor() const
{
    return m_shadowFactor;
}


VfxS32 VcpImageFlow::getFocusUpShift() const
{
    return m_focusUpShift;
}


void VcpImageFlow::onInit()
{
    VcpBaseMenu::onInit();    
    checkUpdate();
    //Register keys
    VfxKeypad::registerHandler(VFX_KEY_CODE_ARROW_LEFT, this);
    VfxKeypad::registerHandler(VFX_KEY_CODE_ARROW_RIGHT, this); 
    VfxKeypad::registerHandler(VFX_KEY_CODE_ARROW_UP, this); 
    enableHorizontalScrollIndicator(VFX_FALSE);
}


VfxBool VcpImageFlow::onKeyInput(VfxKeyEvent &event)
{
    VfxS32 index = m_layout->getFocusItem().pos;
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
    {
        switch (event.keyCode)
        {
        case VFX_KEY_CODE_ARROW_LEFT:
            if (index > 0)
            {
                m_layout->setFocusItem(VcpMenuPos(0, index -1));
            }
            return VFX_TRUE;
        case VFX_KEY_CODE_ARROW_RIGHT:
            if (index < m_layout->getCellCount(0) - 1)
            {
                m_layout->setFocusItem(VcpMenuPos(0, m_layout->getFocusItem().pos+1));
            }
            return VFX_TRUE;
        case VFX_KEY_CODE_ARROW_UP:
            return VFX_TRUE;
        }
    }    
    return VFX_FALSE;
}


VcpBaseMenuLayout* VcpImageFlow::createLayout()
{
    VcpImageFlowLayout* layout;
    VFX_OBJ_CREATE_EX(layout, VcpImageFlowLayout, this, (this));
    return layout;
}


VfxFrame* VcpImageFlow::createCell(VfxS32 group, VfxS32 pos)
{
    VFX_UNUSED(group);
    VcpImageFlowCell* cell;
    VfxS32 focus = m_layout->getFocusItem().pos;
    VFX_OBJ_CREATE(cell, VcpImageFlowCell, this);
    cell->setBounds(VfxRect(0, 0, m_focusCellWidth, (VfxS32)(m_focusCellHeight * (1+m_shadowFactor))));

    if (pos%2 == 0)
    {
        cell->setBgColor(VfxColor(VRT_COLOR_RED));
    }
    else if (pos%2 == 1)
    {
        cell->setBgColor(VfxColor(VRT_COLOR_GREEN));
    }
    
    if (pos != focus)
    {
        cell->sendToBack();
    }
    
    VfxImageSrc tempImage = m_contentProvider->getImageContent(pos);
    
    #if defined(VCP_IMAGE_FLOW_REFLECTED_ENABLE)
    // temp shadow solution
    cell->m_shadow->setPos(VfxPoint(0,m_focusCellHeight - 1));
    cell->m_shadow->setBounds(VfxRect(0, 0, m_focusCellWidth, m_focusCellHeight*m_shadowFactor));
    cell->m_shadow->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_BOTTOM);
    cell->m_shadow->setImgContent(tempImage);
    VfxTransform tramsform = VfxTransform(VFX_TRANSFORM_TYPE_MATRIX3X3);
    tramsform.data.matrix3x3.m[4] = -1;
    //tramsform.data.matrix3x3.m[5] = m_focusCellHeight*m_shadowFactor;
    tramsform.data.matrix3x3.m[7] = m_focusCellHeight*m_shadowFactor;
    cell->m_shadow->setTransform(tramsform);
    cell->m_image = tempImage;
    #elif defined(VCP_IMAGE_FLOW_REFLECTED_ENABLE_2)
    cell->m_main->setImgContent(tempImage);
    cell->m_main->setBounds(VfxRect(0, 0, m_focusCellWidth, m_focusCellHeight));
    cell->m_shadow->setPos(VfxPoint(0,m_focusCellHeight));
    cell->m_shadow->setTargetFrame(cell->m_main);
    cell->m_shadow->setFilterType(VCP_CONTENT_CLONE_FILTER_TYPE_GRADIENT_REFLECTION);
    cell->m_shadow->setTargetRect(VfxRect(0, (VfxS32)(m_focusCellHeight - m_focusCellHeight*m_shadowFactor), m_focusCellWidth, (VfxS32)(m_focusCellHeight*m_shadowFactor)));
    #else
    cell->setImgContent(tempImage);
    #endif
    cell->setIsOpaque(VFX_TRUE);
    cell->setIsCached(VFX_TRUE);

    if (m_useFPE)
    {
        cell->setAnchor(0.5,0.5);
    }
   
    return cell;
}


void VcpImageFlow::onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame)
{
    VFX_UNUSED(group);
    VFX_OBJ_CLOSE(cellFrame);
    m_signalCellClosed.emit(this, pos);
}


vrt_render_dirty_type_enum VcpImageFlow::framePropertyEffectCallback(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size)
{
    VFX_UNUSED(user_data_size);
    VFX_DEV_ASSERT(target_frame != NULL);
    VFX_DEV_ASSERT(watch_frame != NULL);
    VFX_DEV_ASSERT(user_data != NULL && user_data_size == sizeof(VcpImageFlowFrameData));
    VcpImageFlowFrameData* data = (VcpImageFlowFrameData*)user_data;

    VfxFloat R = 500;
    
    VfxS32 offset = data->posX - (watch_frame->bounds.origin.x + watch_frame->bounds.size.width/2);
    
    VfxS32 org = target_frame->pos.y;
    target_frame->pos.y = (vrt_s32)(100 - (R - sqrt(R*R-offset*offset)));
    target_frame->pos.x = (watch_frame->bounds.origin.x + watch_frame->bounds.size.width/2) + offset/2;

    return (org != target_frame->pos.y) ? VRT_RENDER_DIRTY_TYPE_DIRTY : VRT_RENDER_DIRTY_TYPE_NONE;
}


void VcpImageFlow::onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag)
{
    VFX_UNUSED(group);
    VcpImageFlowCell *imageFlowCell = (VcpImageFlowCell*)cell; 
    VfxMatrix4x4 temp,totalProject;
    VfxTransform frame_transform;
    VfxS32 focus = m_layout->getFocusItem().pos;
    VfxS32 shift;

    if (flag & VCP_CELL_FLAG_FIRSTINIT)
    {
        cell->setAutoAnimate(VFX_FALSE);
    }
    else
    {
        if (!m_useFPE)
        {
            cell->setAutoAnimate(VFX_TRUE);
        }
    }

    if (pos > focus)
    {
        if (!m_useFPE)
        {
            if ((pos - focus) == 1)
            {
                shift = (VfxS32)(((m_focusCellWidth/2 + m_secCellWidth + m_shift) * m_backDistance)/ (m_backDistance + m_cameraDistance));
                imageFlowCell->setPos(VfxPoint(rect.origin.x - m_focusCellWidth + shift - m_shift, rect.origin.y + (m_bounds.getHeight() - m_focusCellHeight)/2));
            }
            else
            {
                shift =  (VfxS32)(((m_focusCellWidth/2 + m_secCellWidth + (pos - focus -1) * m_cellWidth + m_shift) * m_backDistance)/ (m_backDistance + m_cameraDistance));
                imageFlowCell->setPos(VfxPoint(rect.origin.x - (m_focusCellWidth + m_secCellWidth +(pos - (focus + 2)) * m_cellWidth) + shift - m_shift, rect.origin.y + (m_bounds.getHeight() - m_focusCellHeight)/2));
            }
            
            temp = m_rightMatrix;
            temp.m[12] += (pos - (focus + 1)) * m_cellWidth;
                    
            frame_transform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;
            totalProject = m_compositeMatrix * temp;                
            totalProject.initMatrix3x3(frame_transform.data.matrix3x3);
                    
            imageFlowCell->setTransform(frame_transform);
            
            imageFlowCell->sendToBack();
        }
        else
        {
            imageFlowCell->setPos(VfxPoint(rect.origin.x + m_focusCellWidth/2,rect.origin.y + m_focusCellHeight/2));
            imageFlowCell->sendToBack();
        }
    }
    else if (pos < focus)
    {
        if (!m_useFPE)
        {
            if ((focus - pos) == 1)
            {
                shift = (VfxS32)(((m_focusCellWidth/2 + m_secCellWidth - m_shift) * m_backDistance)/ (m_backDistance + m_cameraDistance));
                imageFlowCell->setPos(VfxPoint(rect.origin.x + m_secCellWidth - shift - m_shift, rect.origin.y + (m_bounds.getHeight() - m_focusCellHeight)/2));
            }
            else
            {
                shift = (VfxS32)(((m_focusCellWidth/2 + m_secCellWidth + (focus - pos - 1) * m_cellWidth - m_shift) * m_backDistance)/ (m_backDistance + m_cameraDistance) + 0.5);
                imageFlowCell->setPos(VfxPoint(rect.origin.x + m_secCellWidth + (focus - pos - 1) * m_cellWidth - shift - m_shift, rect.origin.y + (m_bounds.getHeight() - m_focusCellHeight)/2));
            }
            
            temp = m_leftMatrix;
            temp.m[12] -= ((focus - 1) - pos) * m_cellWidth;
                    
            frame_transform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;
            totalProject = m_compositeMatrix * temp;                
            totalProject.initMatrix3x3(frame_transform.data.matrix3x3);
                    
            imageFlowCell->setTransform(frame_transform);
            imageFlowCell->bringToFront();
        }
        else
        {
            imageFlowCell->setPos(VfxPoint(rect.origin.x + m_focusCellWidth/2,rect.origin.y + m_focusCellHeight/2));
            imageFlowCell->bringToFront();
        }
    }
    else
    {
        if (!m_useFPE)
        {
            imageFlowCell->setPos(VfxPoint(rect.origin.x - m_shift, rect.origin.y + (m_bounds.getHeight() - m_focusCellHeight)/2));
            temp = m_centerMatrix;
                    
            frame_transform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;
            totalProject = m_compositeMatrix * temp;                
            totalProject.initMatrix3x3(frame_transform.data.matrix3x3);
                    
            imageFlowCell->setTransform(frame_transform);
            
            imageFlowCell->bringToFront();
        }
        else
        {
            imageFlowCell->setPos(VfxPoint(rect.origin.x + m_focusCellWidth/2,rect.origin.y + m_focusCellHeight/2));
            imageFlowCell->bringToFront();
        }
    }

    if (m_useFPE && (flag & VCP_CELL_FLAG_FIRSTINIT))
    {    
        VcpImageFlowFrameData data;
        data.posX = imageFlowCell->getPos().x;
        data.width = m_focusCellWidth;
        data.height = m_focusCellHeight;
        data.secondWidth = m_secCellWidth;
        data.thirdWidth = m_cellWidth;
        data.upShift = (VfxS32)m_upShift;
        data.disable = VFX_FALSE;
        
        cell->setPropertyEffectCallback(
                    m_view,
                    &VcpImageFlow::framePropertyEffectCallback, 
                    &data,
                    sizeof(data),
                    VRT_FPE_TRIGGER_TYPE_DIRTY);
    }
}


void VcpImageFlow::onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem)
{
    VFX_UNUSED(previousFocusItem);
    adjustRenderSequence();
    m_signalFocusChanged.emit(this, focusItem.pos);   
}


void VcpImageFlow::onDragEnd()
{
}


void VcpImageFlow::onTap(const VfxPoint &pt)
{
    VcpMenuPos hitMenuPos = ((VcpImageFlowLayout*)m_layout)->getCellByPos(pt);
    VfxS32 focus = m_layout->getFocusItem().pos;

    if (hitMenuPos.pos == focus)
    {
        m_signalSelected.emit(this, getCellIfPresent(0,focus), focus);   
    }
    else
    {
        m_layout->setFocusItem(hitMenuPos);
    }
}


void VcpImageFlow::updateTransform()
{
    // construct 3D model
    m_compositeMatrix.setCamera(
        1.0f, 
        1.0f, 
        (VfxFloat)(m_focusCellWidth/2), 
        (VfxFloat)(m_focusCellHeight/2), 
        (VfxFloat)m_cameraDistance, 
        (VfxFloat)m_cameraDistance, 
        0, 
        0, 
        0);
    m_centerMatrix.setTranslation((VfxFloat)((-1 * m_focusCellWidth/2) + m_shift), 
                        (VfxFloat)(-1 * m_focusCellHeight/2), 
                        0);


    m_leftMatrix.setRotateByY(VFX_DEG_TO_RAD(-1 * m_rotateAngle));
    m_leftMatrix.m[12] = (VfxFloat)(-1 * (m_secCellWidth));
    //m_leftMatrix.m[13] = -1 * m_upShift;
    m_leftMatrix.m[14] = m_backDistance;
    m_leftMatrix = m_centerMatrix * m_leftMatrix;

    m_rightMatrix.setRotateByY(VFX_DEG_TO_RAD(m_rotateAngle));
    m_rightMatrix.m[12] = (VfxFloat)(m_focusCellWidth + m_secCellWidth - m_focusCellWidth * vfxCos(VFX_DEG_TO_RAD(m_rotateAngle)));
    //m_rightMatrix.m[13] = -1 * m_upShift;
    m_rightMatrix.m[14] = m_focusCellWidth * vfxSin(VFX_DEG_TO_RAD(m_rotateAngle)) + m_backDistance;
    m_rightMatrix = m_centerMatrix * m_rightMatrix;
}


void VcpImageFlow::adjustRenderSequence()
{
    VcpMenuRegion region = getRealContentRegion();
    VfxS32 i;
    VcpImageFlowCell* tempFrame;
    VfxS32 focus = m_layout->getFocusItem().pos;

    for(i = region.end.pos - 1; i > focus; i--)
    {
        tempFrame = (VcpImageFlowCell*)getCellIfPresent(0, i);
        if (tempFrame)
        {
            //tempFrame->bringToFront();
            tempFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_BOTTOM_LEFT);
        }
    }

    for(i = region.begin.pos; i < focus; i++)
    {
        tempFrame = (VcpImageFlowCell*)getCellIfPresent(0, i);
        if (tempFrame)
        {
            //tempFrame->bringToFront();
            tempFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_BOTTOM_RIGHT);
        }
    }

    tempFrame = (VcpImageFlowCell*)getCellIfPresent(0, focus);
    if (tempFrame)
    {
        //tempFrame->bringToFront();
        tempFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_BOTTOM);
    }
}


void VcpImageFlow::setAllAutoAnimate(VfxBool value)
{
    VcpMenuRegionIter itr(this, getRealContentRegion());
    while(!itr.isEnd())
    {
        VcpMenuPos p = itr.next();
        VcpImageFlowCell* tempFrame = (VcpImageFlowCell*)getCellIfPresent(p.group, p.pos);
           
        if (tempFrame)
        {
            tempFrame->setAutoAnimate(value);
        }
    }
}


void VcpImageFlow::setAllCellisCached(VfxBool value)
{
    VcpMenuRegionIter itr(this, getRealContentRegion());
    while(!itr.isEnd())
    {
        VcpMenuPos p = itr.next();
        VcpImageFlowCell* tempFrame = (VcpImageFlowCell*)getCellIfPresent(p.group, p.pos);
           
        if (tempFrame)
        {
            tempFrame->setIsCached(value);
        }
    }
}


/***************************************************************************** 
 * Class VcpImageFlowWheel
 *****************************************************************************/
VcpImageFlowWheel::VcpImageFlowWheel():
    m_count(0),
    m_focusCellWidth(0),
    m_focusCellHeight(0),
    m_cellWidth(0),
    m_cellHeight(0),
    m_secCellWidth(0),
    m_secCellHeight(0),
    m_rotateAngle(90),
    m_cameraDistance(120),
    m_backDistance(20),
    m_updateBackDistance(VFX_FALSE),
    m_shift(0),
#if defined(VCP_IMAGE_FLOW_REFLECTED_ENABLE) || defined(VCP_IMAGE_FLOW_REFLECTED_ENABLE_2)
    m_shadowFactor(0.5),
#else
    m_shadowFactor(0),
#endif
    m_focusUpShift(0),
    m_contentProvider(NULL)
{ 
}

void VcpImageFlowWheel::updateImageContent(VfxS32 index, VfxImageSrc &image)
{
    VcpImageFlowCell* tempFrame;
    tempFrame = (VcpImageFlowCell*)getCellIfPresent(index);
#if defined(VCP_IMAGE_FLOW_REFLECTED_ENABLE)
    tempFrame->m_image = image;
    tempFrame->invalidate();
#elif defined(VCP_IMAGE_FLOW_REFLECTED_ENABLE_2)
	tempFrame->m_main->setImgContent(image);
	tempFrame->m_main->invalidate();
#else
    tempFrame->setImgContent(image);
#endif
}


void VcpImageFlowWheel::setContentProvider(IVcpImageFlowContentProvider *contentProvider)
{
    m_contentProvider = contentProvider;
}


void VcpImageFlowWheel::setFocusIndex(VfxS32 index)
{
    setFocus(index);
}


void VcpImageFlowWheel::setCellNumber(VfxS32 number)
{
    m_count = number;
}


void VcpImageFlowWheel::setCellWidth(VfxS32 width)
{
    m_cellWidth = width;
    checkUpdate();
}


void VcpImageFlowWheel::setCellHeight(VfxS32 height)
{
    m_cellHeight = height;
    m_updateBackDistance = VFX_TRUE;
    checkUpdate();
}


void VcpImageFlowWheel::setFocusCellWidth(VfxS32 width)
{
    m_focusCellWidth = width;
    checkUpdate();
}


void VcpImageFlowWheel::setFocusCellHeight(VfxS32 height)
{
    m_focusCellHeight = height;
    m_updateBackDistance = VFX_TRUE;
    checkUpdate();
}


void VcpImageFlowWheel::setCellParameter(VfxS32 number, VfxS32 focusCellWidth, VfxS32 focusCellHeight, VfxS32 secCellWidth, VfxS32 cellWidth, VfxS32 cellHeight)
{
    m_count = number;
    m_cellWidth = cellWidth;
    m_cellHeight = cellHeight;
    m_focusCellWidth = focusCellWidth;
    m_focusCellHeight = focusCellHeight;
    m_secCellWidth = secCellWidth;
    m_updateBackDistance = VFX_TRUE;
    checkUpdate();
}


void VcpImageFlowWheel::setRotateAngle(VfxFloat angle)
{
    m_rotateAngle = angle;
    checkUpdate();
}


void VcpImageFlowWheel::setUpShift(VfxFloat upShift)
{
    m_upShift = upShift;
    checkUpdate();
}


void VcpImageFlowWheel::setCameraDistance(VfxFloat distance)
{
    m_cameraDistance = distance;
    checkUpdate();
}


void VcpImageFlowWheel::setCachedCellNumber(VfxS32 number)
{
}


void VcpImageFlowWheel::setBackDistance(VfxFloat distance)
{
    m_backDistance = distance;
    m_updateBackDistance = VFX_FALSE;
}


void VcpImageFlowWheel::setShadowFactor(VfxFloat value)
{
   m_shadowFactor = value;
   checkUpdate();
}


void VcpImageFlowWheel::setFocusUpShift(VfxS32 upShift)
{
    m_focusUpShift = upShift;
    checkUpdate();
}


void VcpImageFlowWheel::onUpdate()
{
    VcpWheelMenu::onUpdate();
}


VfxS32 VcpImageFlowWheel::getFocusIndex() const
{
    return getFocus();
}


VfxS32 VcpImageFlowWheel::getCellNumber() const
{
    return m_count;
}


VfxS32 VcpImageFlowWheel::getCellWidth() const
{
    return m_cellWidth;
}


VfxS32 VcpImageFlowWheel::getCellHeight() const
{
    return m_cellHeight;
}


VfxS32 VcpImageFlowWheel::getFocusCellWidth() const
{
    return m_focusCellWidth;
}


VfxS32 VcpImageFlowWheel::getFocusCellHeight() const
{
    return m_focusCellHeight;
}


VfxFloat VcpImageFlowWheel::getRotateAngle() const
{
    return m_rotateAngle;
}


VfxFloat VcpImageFlowWheel::getCameraDistance() const
{
    return m_cameraDistance;
}


VfxFloat VcpImageFlowWheel::getBackDistance() const
{
    return m_backDistance;
}


VfxFloat VcpImageFlowWheel::getShadowFactor() const
{
    return m_shadowFactor;
}


VfxS32 VcpImageFlowWheel::getFocusUpShift() const
{
    return m_focusUpShift;
}


void VcpImageFlowWheel::onInit()
{
    VcpWheelMenu::onInit();    
    checkUpdate();
    
    setIsZSortChild(VFX_TRUE);
    //Register keys
    VfxKeypad::registerHandler(VFX_KEY_CODE_ARROW_LEFT, this);
    VfxKeypad::registerHandler(VFX_KEY_CODE_ARROW_RIGHT, this); 
    VfxKeypad::registerHandler(VFX_KEY_CODE_ARROW_UP, this); 
}


VfxBool VcpImageFlowWheel::onKeyInput(VfxKeyEvent &event)
{
    VfxS32 index = getFocus();
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
    {
        switch (event.keyCode)
        {
        case VFX_KEY_CODE_ARROW_LEFT:
            if (index > 0)
            {
                setFocus(index - 1);
            }
            return VFX_TRUE;
        case VFX_KEY_CODE_ARROW_RIGHT:
            if (index < m_count - 1)
            {
                setFocus(index + 1);
            }
            return VFX_TRUE;
        }
    }    
    return VFX_FALSE;
}



VfxFrame* VcpImageFlowWheel::createCell(VfxS32 cell, VfxS32 subCell)
{
    VcpImageFlowCell* ImageFlowCell;
    VfxS32 focus = getFocus();
    VFX_OBJ_CREATE(ImageFlowCell, VcpImageFlowCell, this);
    ImageFlowCell->setBounds(VfxRect(0, 0, m_focusCellWidth, VfxS32(m_focusCellHeight * (1+m_shadowFactor))));
    /*
    if (cell%2 == 0)
    {
        ImageFlowCell->setBgColor(VfxColor(VRT_COLOR_RED));
    }
    else if (cell%2 == 1)
    {
        ImageFlowCell->setBgColor(VfxColor(VRT_COLOR_GREEN));
    }
    */
    if (cell != focus)
    {
        ImageFlowCell->sendToBack();
    }
    if (m_contentProvider)
    {
        VfxImageSrc tempImage = m_contentProvider->getImageContent(cell);

    #if defined(VCP_IMAGE_FLOW_REFLECTED_ENABLE)
        // temp shadow solution
        ImageFlowCell->m_shadow->setPos(VfxPoint(0,m_focusCellHeight - 1));
        ImageFlowCell->m_shadow->setBounds(VfxRect(0, 0, m_focusCellWidth, m_focusCellHeight*m_shadowFactor));
        ImageFlowCell->m_shadow->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_BOTTOM);
        ImageFlowCell->m_shadow->setImgContent(tempImage);
        VfxTransform tramsform = VfxTransform(VFX_TRANSFORM_TYPE_MATRIX3X3);
        tramsform.data.matrix3x3.m[4] = -1;
        //tramsform.data.matrix3x3.m[5] = m_focusCellHeight*m_shadowFactor;
        tramsform.data.matrix3x3.m[7] = m_focusCellHeight*m_shadowFactor;
        ImageFlowCell->m_shadow->setTransform(tramsform);
        ImageFlowCell->m_image = tempImage;
    #elif defined(VCP_IMAGE_FLOW_REFLECTED_ENABLE_2)
        ImageFlowCell->m_main->setImgContent(tempImage);
        ImageFlowCell->m_main->setBounds(VfxRect(0, 0, m_focusCellWidth, m_focusCellHeight));
        ImageFlowCell->m_shadow->setPos(VfxPoint(0,m_focusCellHeight));
        ImageFlowCell->m_shadow->setTargetFrame(ImageFlowCell->m_main);
        ImageFlowCell->m_shadow->setFilterType(VCP_CONTENT_CLONE_FILTER_TYPE_GRADIENT_REFLECTION);
        ImageFlowCell->m_shadow->setTargetRect(VfxRect(0, (VfxS32)(m_focusCellHeight - m_focusCellHeight*m_shadowFactor), m_focusCellWidth, (VfxS32)(m_focusCellHeight*m_shadowFactor)));
    #else
        ImageFlowCell->setImgContent(tempImage);
    #endif
    }

    ImageFlowCell->setIsOpaque(VFX_TRUE);
    ImageFlowCell->setIsCached(VFX_TRUE);
    ImageFlowCell->setAnchor(0.5,0.5);

    VcpImageFlowWheelUserData data;
    data.index = cell;
	data.width = m_focusCellWidth;
    data.height = m_focusCellHeight;
    data.secondWidth = m_secCellWidth;
    data.thirdWidth = m_cellWidth;
    data.upShift = m_upShift;
    data.focusUpShift = m_focusUpShift;
    data.scaleSlope = m_cameraDistance / (m_cameraDistance + m_backDistance) - 1.0f;
    data.disable = VFX_FALSE;
    setCellUserData(cell, subCell, ImageFlowCell, &data, sizeof(VcpImageFlowWheelUserData));
   
    return ImageFlowCell;
}

void VcpImageFlowWheel::onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* frame)
{
    if (cell == getFocus())
    {
        frame->bringToFront();
    }
    frame->setPosZ((VfxFloat)VFX_ABS(cell-getFocus()));
}


void VcpImageFlowWheel::onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame)
{
    VFX_UNUSED(cell);
    VFX_UNUSED(subcell);
    VFX_OBJ_CLOSE(cellFrame);
    m_signalCellClosed.emit(this, cell);
}


void VcpImageFlowWheel::onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem)
{
    VFX_UNUSED(previousFocusItem);
    m_signalFocusChanged.emit(this, focusItem);  
}


void VcpImageFlowWheel::onDragEnd(VfxS32 xspeed, VfxS32 yspeed)
{
    VFX_UNUSED(xspeed);
    if (xspeed == 0)
    {
        setFocus(VfxS32(getScrollIndex() + 0.5f));
    }
    else
    {
        VfxS32   s      = xspeed > 0 ? 1 : -1;
        VfxFloat m      = VFX_ABS(xspeed) / 333.3f;
        
        if (m > 3) m = 3;
        
        setFocus(VfxS32(getScrollIndex() - s * m + 0.5f), 300);
    }
}

void VcpImageFlowWheel::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    VFX_UNUSED(xoffset);
    setScrollIndex(getScrollIndex() - VfxFloat(xoffset) / 60, 0);
}

// Notify when the menu is tapped
void VcpImageFlowWheel::onTap(VfxPoint pt)
{
    VfxS32 originX, originY, endX, endY;

    VcpImageFlowCell* item = (VcpImageFlowCell*) getCellIfPresent(getFocus());
    VfxPoint pos = item->forceGetPos();
    VfxTransform transform = item->forceGetTransform();
    
    originX = (VfxS32) (pos.x - (m_focusCellWidth * transform.data.affine.sx)/2);
    originY = (VfxS32) (pos.y - (m_focusCellHeight * (1.0f + m_shadowFactor) * transform.data.affine.sy)/2);

    endX = (VfxS32) (pos.x + (m_focusCellWidth * transform.data.affine.sx)/2);
    endY = (VfxS32) (originY + (m_focusCellHeight * transform.data.affine.sy));
    
    if (pt.x >= originX && pt.x < endX && pt.y >= originY && pt.y < endY)
    {
        m_signalSelected.emit(this, getCellIfPresent(getFocus()), getFocus());
        return;
    }

    // region focus -1 
    item = (VcpImageFlowCell*) getCellIfPresent(getFocus() - 1);
    if (item)
    {
        pos = item->forceGetPos();
        transform = item->forceGetTransform();

        originX = (VfxS32) (pos.x - (m_focusCellWidth * transform.data.affine.sx)/2);
        originY = (VfxS32) (pos.y - (m_focusCellHeight * (1.0f + m_shadowFactor) * transform.data.affine.sy)/2);

        endX = (VfxS32) (pos.x + (m_focusCellWidth * transform.data.affine.sx)/2);
        endY = (VfxS32) (originY + (m_focusCellHeight * transform.data.affine.sy));

        if (pt.x >= originX && pt.x < endX && pt.y >= originY && pt.y < endY)
        {
            setFocus(getFocus() - 1);
            return;
        }
    }

    // region focus +1 
    item = (VcpImageFlowCell*) getCellIfPresent(getFocus() + 1);
    if (item)
    {
        pos = item->forceGetPos();
        transform = item->forceGetTransform();

        originX = (VfxS32) (pos.x - (m_focusCellWidth * transform.data.affine.sx)/2);
        originY = (VfxS32) (pos.y - (m_focusCellHeight * (1.0f + m_shadowFactor) * transform.data.affine.sy)/2);

        endX = (VfxS32) (pos.x + (m_focusCellWidth * transform.data.affine.sx)/2);
        endY = (VfxS32) (originY + (m_focusCellHeight * transform.data.affine.sy));

        if (pt.x >= originX && pt.x < endX && pt.y >= originY && pt.y < endY)
        {
            setFocus(getFocus() + 1);
            return;
        }
    }

    // region focus -2 
    item = (VcpImageFlowCell*) getCellIfPresent(getFocus() - 2);
    if (item)
    {
        pos = item->forceGetPos();
        transform = item->forceGetTransform();

        originX = (VfxS32) (pos.x - (m_focusCellWidth * transform.data.affine.sx)/2);
        originY = (VfxS32) (pos.y - (m_focusCellHeight * (1.0f + m_shadowFactor) * transform.data.affine.sy)/2);

        endX = (VfxS32) (pos.x + (m_focusCellWidth * transform.data.affine.sx)/2);
        endY = (VfxS32) (originY + (m_focusCellHeight * transform.data.affine.sy));

        if (pt.x >= originX && pt.x < endX && pt.y >= originY && pt.y < endY)
        {
            setFocus(getFocus() - 2);
            return;
        }
    }

    // region focus + 2 
    item = (VcpImageFlowCell*) getCellIfPresent(getFocus() + 2);
    if (item)
    {
        pos = item->forceGetPos();
        transform = item->forceGetTransform();

        originX = (VfxS32) (pos.x - (m_focusCellWidth * transform.data.affine.sx)/2);
        originY = (VfxS32) (pos.y - (m_focusCellHeight * (1.0f + m_shadowFactor) * transform.data.affine.sy)/2);

        endX = (VfxS32) (pos.x + (m_focusCellWidth * transform.data.affine.sx)/2);
        endY = (VfxS32) (originY + (m_focusCellHeight * transform.data.affine.sy));

        if (pt.x >= originX && pt.x < endX && pt.y >= originY && pt.y < endY)
        {
            setFocus(getFocus() + 2);
            return;
        }
    }
}

VfxS32 VcpImageFlowWheel::getCount()
{
    return m_count;
}

VfxS32 VcpImageFlowWheel::getBehindCount()
{
    return 2;
}

VfxS32 VcpImageFlowWheel::getAheadCount()
{
    return 2;
}

vrt_render_dirty_type_enum VcpImageFlowWheel::myFrameEffectCB(
    VfxS32                              cell,           // [IN] the cell index
    VfxS32                              subCell,        // [IN] the sub cell index
    VfxFloat                            cellRelPos,     // [IN] the cell position
    vrt_frame_visual_property_struct    *target_frame,  // [IN] the cell frame
    VfxFloat                            fPos,           // [IN] animating index value
    VfxS32                              focus,          // [IN] the focus value of the menu
    VfxRect                             viewBounds,     // [IN] the menu bounds
    void                                *userData,      // [IN] user data
    VfxU32                              userDataSize,   // [IN] user data size
    VcpWheelMenuState                   state,          // [IN] the state of Menu
    VfxFloat                            level           // [IN] the level of state
)
{
    //return VRT_FALSE;
    VFX_UNUSED(focus);
    VFX_UNUSED(userDataSize);
    VFX_DEV_ASSERT(target_frame != NULL);
    VFX_DEV_ASSERT(userDataSize == sizeof(VcpImageFlowWheelUserData));
    
    VcpImageFlowWheelUserData* data = (VcpImageFlowWheelUserData*)userData;
    if (data->disable)
    {
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }

    VfxFloat offset = data->index - fPos;
    VfxS32 w = viewBounds.size.width / 2;
    VfxS32 h = viewBounds.size.height / 2 - data->focusUpShift;
    // define the semimajor axis a and semiminor axis b of ellipse.
    VfxFloat H = data->upShift;
    VfxFloat S = (VfxFloat)data->secondWidth;
    VfxFloat T = (VfxFloat)data->thirdWidth;
    
    VfxFloat a = (-1.0f * H * (T-S))/(S*T*(T+S));
    VfxFloat b = H * (T-S)/ (S*T) + (2.0f * H)/(T+S); 

    VfxFloat absOffset = VFX_ABS(offset);
    VfxS32 realOffset;

    if (absOffset <= 1)
    {
        realOffset = VfxS32(S * absOffset);
    }
    else
    {
        realOffset = (VfxS32)(S + VfxS32(T * (absOffset - 1)));
    }

    if (offset > 0)
    {
        target_frame->pos.x = w + realOffset;
    }
    else
    {
        target_frame->pos.x = w - realOffset;
    }

    target_frame->pos.y = (vrt_s32)(h - (a * realOffset * realOffset + b * realOffset));
    
    target_frame->transform.type = VRT_TRANSFORM_TYPE_AFFINE;
    target_frame->transform.data.affine.sx = data->scaleSlope * VFX_ABS(offset) + 1.0f;
    target_frame->transform.data.affine.sy = data->scaleSlope * VFX_ABS(offset) + 1.0f;
    
    // set opacity
    if (VFX_ABS(offset) < 2)
    {
        target_frame->opacity = 1;
    }
    else
    {
        target_frame->opacity = 1.0f - (VFX_ABS(offset) - 2);
        if (target_frame->opacity < 0)
        {
            target_frame->opacity = 0;
        }
    }

    target_frame->pos_z = VFX_ABS(offset);

    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

VcpWheelMenuFrameEffectCBFuncPtr VcpImageFlowWheel::getFrameEffectCB()
{
    return &VcpImageFlowWheel::myFrameEffectCB;
}


void VcpImageFlowWheel::setAllAutoAnimate(VfxBool value)
{
    for (VfxS32 i = getFirstVisibleIndex(); i < getLastVisibleIndex(); i++)
    {
        VcpImageFlowCell* tempFrame = (VcpImageFlowCell*)getCellIfPresent(i);
           
        if (tempFrame)
        {
            tempFrame->setAutoAnimate(value);
        }
    }
}


void VcpImageFlowWheel::setAllCellisCached(VfxBool value)
{
    for (VfxS32 i = getFirstVisibleIndex(); i < getLastVisibleIndex(); i++)
    {
        VcpImageFlowCell* tempFrame = (VcpImageFlowCell*)getCellIfPresent(i);
           
        if (tempFrame)
        {
            tempFrame->setIsCached(value);
        }
    }
}
