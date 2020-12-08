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
 *  vcp_twist_menu.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *   Venus Twist Menu Component
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "vcp_fancy_mode_menu.h"
#include "MMI_features.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vcp_normal_mode_menu.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_frame.h"
#include "vrt_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_image_src.h"
#include "vfx_animation.h"
#include "vfx_transform.h"
#include "vfx_signal.h"
#include "vfx_text_frame.h"
#include "vfx_font_desc.h"
#include "vcp_wheel_menu.h"
#include "vfx_timer.h"
#include "vfx_input_event.h"
#include "vfx_auto_animate.h"
#include "vfx_control.h"

#ifdef __MMI_VUI_3D_MAINMENU_FANCY__
/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
 
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
 * Class VcpTwistMenuCellDataMgr
 *****************************************************************************/

VcpFancyModeDataMgr::VcpFancyModeDataMgr() :
    m_allAppData(NULL),
    m_allAppCount(0),
    m_appOrderData(NULL),
    m_appOrderCount(0),
    m_ready1(VFX_FALSE),
    m_ready2(VFX_FALSE),
    m_mappingTable(NULL),
    m_mappingTableCount(0),
    m_blankMode(VCP_FANCY_MODE_DATA_MGR_NONE),
    m_pageCount(0)
{}


void VcpFancyModeDataMgr::onInit()
{
    VfxObject::onInit();
}


void VcpFancyModeDataMgr::onDeinit()
{
    VFX_FREE_MEM(m_mappingTable);
    VfxObject::onDeinit();
}


void VcpFancyModeDataMgr::setAllAppData(AppEntry appEntry[], VfxS32 count)
{
    m_allAppData = appEntry;
    m_allAppCount = count;
    m_ready1 = VFX_TRUE;

    if (m_ready1 && m_ready2)
    {
        makeMappingTable();
    }
}


void VcpFancyModeDataMgr::setAppOrderData(VfxS32 appOrder[], VfxS32 count)
{
    m_appOrderData = appOrder;
    m_appOrderCount = count;
    m_ready2 = VFX_TRUE;
    if (m_ready1 && m_ready2)
    {
        makeMappingTable();
    }
}


void VcpFancyModeDataMgr::makeMappingTable()
{
    // for space beam, we need align 4n
    if (m_blankMode != VCP_FANCY_MODE_DATA_MGR_NONE)
    {
        if (m_blankMode == VCP_FANCY_MODE_DATA_MGR_ROW)
        {
            // every row has count - 1 blank at most
            m_mappingTableCount = m_allAppCount + m_pageCount * (VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW - 1);
        }
        else
        {
            m_mappingTableCount = m_pageCount * VCP_FANCY_MODE_TRANSITION_CELL_COUNT;
        }
        VFX_ALLOC_MEM(m_mappingTable, m_mappingTableCount * sizeof(VfxS32), this);

        VfxS32 i;
        VfxS32 j = 0;
        
        for (i = 0; i < m_appOrderCount; i++)
        {
            if (m_appOrderData[i] != VCP_NORMAL_MODE_MENU_PAGE_BREAK)
            {
                m_mappingTable[j] = m_appOrderData[i];
                j ++;
            }
            else
            {
                VfxS32 k;

                if (m_blankMode == VCP_FANCY_MODE_DATA_MGR_ROW)
                {
                    k = j % VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW;
                    if (k != 0)
                    {
                        for (; k < VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW; k++)
                        {
                            m_mappingTable[j] = -1;
                            j ++;
                        }
                    }
                }
                else
                {
                    k = j % VCP_FANCY_MODE_TRANSITION_CELL_COUNT;
                    if (k != 0)
                    {
                        for (; k < VCP_FANCY_MODE_TRANSITION_CELL_COUNT; k++)
                        {
                            m_mappingTable[j] = -1;
                            j ++;
                        }
                    }
                }
               
                if (m_appOrderData[i + 1] == VCP_NORMAL_MODE_MENU_PAGE_BREAK)
                {
                    m_mappingTableCount = j;
                    break;
                }
                
            }
        }
    }
    else
    {
        m_mappingTableCount = m_allAppCount;
        VFX_ALLOC_MEM(m_mappingTable, m_mappingTableCount * sizeof(VfxS32), this);

        VfxS32 i;
        VfxS32 j = 0;
        for (i = 0; i < m_appOrderCount; i++)
        {
            if (m_appOrderData[i] != VCP_NORMAL_MODE_MENU_PAGE_BREAK)
            {
                m_mappingTable[j] = m_appOrderData[i];
                j ++;
            }
        }
    }
}


VfxResId VcpFancyModeDataMgr::getIconId(VfxS32 index)
{
    if (index >= m_mappingTableCount || m_mappingTable[index] == -1)
    {
        return 0;
    }
    return m_allAppData[m_mappingTable[index]].appIcon;
}


VfxWString VcpFancyModeDataMgr::getTitle(VfxS32 index)
{
    if (index >= m_mappingTableCount || m_mappingTable[index] == -1)
    {
        return VFX_WSTR_NULL;
    }
    return m_allAppData[m_mappingTable[index]].appTitle;
}


VfxS32 VcpFancyModeDataMgr::getIndex(VfxS32 index)
{
    return m_mappingTable[index];
}


VfxS32 VcpFancyModeDataMgr::getFocusedIndex(VfxS32 screenIndex)
{
    if (m_blankMode != VCP_FANCY_MODE_DATA_MGR_NONE)
    {
        VfxS32 i;
        VfxS32 count = 0;
        for (i = 0; i < m_mappingTableCount; i++)
        {
            if (m_mappingTable[i] != -1)
            {
                if (count == screenIndex)
                {
                    return i;
                }
                count ++;
            }
        }
        return m_mappingTableCount - 1;
    }
    else
    {
        return screenIndex;
    }
}


/***************************************************************************** 
 * Class VcpTwistMenuTransition
 *****************************************************************************/

VcpFancyModeMenuTransition::VcpFancyModeMenuTransition() :
    m_dataMgr(NULL),
    m_focus(0),
    m_isReverse(VFX_FALSE)
{}


void VcpFancyModeMenuTransition::onInit()
{       
    VfxFrame::onInit(); 
}


void VcpFancyModeMenuTransition::switchToTornado(VfxBool isReverse)
{
    m_isReverse = isReverse;

    if (m_dataMgr == NULL)
    {
        VFX_ASSERT(0);
    }
    // fake menu
    VfxS32 i;
    
    for (i = 0; i < VCP_FANCY_MODE_TRANSITION_CELL_COUNT; i++)
    {
        VFX_OBJ_CREATE(m_menuIcon[i] ,VfxFrame, this);
        m_menuIcon[i]->setRect(VfxRect(0, 0, VCP_FANCY_MODE_CELL_WIDTH, VCP_FANCY_MODE_CELL_HEIGHT));

        if (m_dataMgr->getIconId(m_focus + i) == 0)
        {
            m_menuIcon[i]->setHidden(VFX_TRUE);
        }
        else
        {
            m_menuIcon[i]->setImgContent(VfxImageSrc(m_dataMgr->getIconId(m_focus + i)));
        }
    }
    
    VfxS32 x,y;
    for (y = 0; y < VCP_FANCY_MODE_TRANSITION_CELL_ROW_COUNT; y++)
    {
        for (x = 0; x < VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW; x++)
        {
            m_menuIcon[y * VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW + x]->setPos(VCP_FANCY_MODE_TRANSITION_CELL_X_START + VCP_FANCY_MODE_TRANSITION_CELL_X_GAP * x,
                                            VCP_FANCY_MODE_TRANSITION_CELL_Y_START + VCP_FANCY_MODE_TRANSITION_CELL_Y_GAP * y);
        }
    }
    
    // create timeline to move
    for (i = 0; i < VCP_FANCY_MODE_TRANSITION_CELL_COUNT; i++)
    {
        VFX_OBJ_CREATE(m_menuItemTimeline[i], VfxPointTimeline, this);
        m_menuItemTimeline[i]->setTarget(m_menuIcon[i]);
        m_menuItemTimeline[i]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);

        // may set different timeline duration 
        if (i % VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW == 0)
        {
            m_menuItemTimeline[i]->setDurationTime(500);
        }
        else if (i % VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW == 1)
        {
            m_menuItemTimeline[i]->setDurationTime(450);
        }
        else if (i % VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW == 2)
        {
            m_menuItemTimeline[i]->setDurationTime(400);
        }
        else 
        {
             m_menuItemTimeline[i]->setDurationTime(550);
        }

        // to make a turning point up from vanish point 
        m_menuItemTimeline[i]->setToValue(
                                VfxPoint(VCP_FANCY_MODE_TRANSITION_TORNADO_VANISH_POINT_X, VCP_FANCY_MODE_TRANSITION_TORNADO_VANISH_POINT_Y - 100)
                                );
        if (isReverse)
        {
            m_menuItemTimeline[i]->setFromValue(
                                    VfxPoint(VCP_FANCY_MODE_TRANSITION_TORNADO_VANISH_POINT_X, VCP_FANCY_MODE_TRANSITION_TORNADO_VANISH_POINT_Y)
                                    );
        }
        else
        {
            m_menuItemTimeline[i]->setIsFromCurrent(VFX_TRUE);
        }
        m_menuItemTimeline[i]->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_menuItemTimeline[i]->start();

        // scale 
        VFX_OBJ_CREATE(m_menuItemScaleTimeline[i], VfxTransformTimeline, this);
        m_menuItemScaleTimeline[i]->setTarget(m_menuIcon[i]);
        m_menuItemScaleTimeline[i]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);

        // may set different timeline duration
        if (i % VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW == 0)
        {
            m_menuItemScaleTimeline[i]->setDurationTime(500);
        }
        else if (i % VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW == 1)
        {
            m_menuItemScaleTimeline[i]->setDurationTime(450);
        }
        else if (i % VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW == 2)
        {
            m_menuItemScaleTimeline[i]->setDurationTime(400);
        }
        else
        {
             m_menuItemScaleTimeline[i]->setDurationTime(550);
        }
        
        VfxTransform tempTransform;
        tempTransform.data.affine.sx = VCP_FANCY_MODE_TRANSITION_TORNADO_VANISH_POINT_SCALE;
        tempTransform.data.affine.sy = VCP_FANCY_MODE_TRANSITION_TORNADO_VANISH_POINT_SCALE;
        if (isReverse)
        {
            m_menuItemScaleTimeline[i]->setToValue(VfxTransform());
            m_menuItemScaleTimeline[i]->setFromValue(tempTransform);
        }
        else
        {
            m_menuItemScaleTimeline[i]->setToValue(tempTransform);
            m_menuItemScaleTimeline[i]->setIsFromCurrent(VFX_TRUE);
        }
        m_menuItemScaleTimeline[i]->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_menuItemScaleTimeline[i]->start();
    }

    for (i = 0; i < VCP_FANCY_MODE_TRANSITION_CELL_COUNT; i++)
    {
        VFX_OBJ_CREATE(m_menuItemTimeline2[i], VfxPointTimeline, this);
        m_menuItemTimeline2[i]->setTarget(m_menuIcon[i]);
        m_menuItemTimeline2[i]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        m_menuItemTimeline2[i]->setStartDelay(300);

        if (i % VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW == 0)
        {
            m_menuItemTimeline2[i]->setDurationTime(200);
        }
        else if (i % VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW == 1)
        {
            m_menuItemTimeline2[i]->setDurationTime(150);
        }
        else if (i % VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW == 2)
        {
            m_menuItemTimeline2[i]->setDurationTime(100);
        }
        else
        {
             m_menuItemTimeline2[i]->setDurationTime(250);
        }
        m_menuItemTimeline2[i]->setIsFromCurrent(VFX_TRUE);
        if (!isReverse)
        {
            m_menuItemTimeline2[i]->setToValue(
                                        VfxPoint(VCP_FANCY_MODE_TRANSITION_TORNADO_VANISH_POINT_X, VCP_FANCY_MODE_TRANSITION_TORNADO_VANISH_POINT_Y)
                                        );
        }
        m_menuItemTimeline2[i]->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_menuItemTimeline2[i]->start();
    }

    if (isReverse)
    {
        VfxS32 x,y;
        for (y = 0; y < VCP_FANCY_MODE_TRANSITION_CELL_ROW_COUNT; y++)
        {
            for (x = 0; x < VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW; x++)
            {
                m_menuItemTimeline2[y * VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW + x]->setToValue(VfxPoint(VCP_FANCY_MODE_TRANSITION_CELL_X_START + VCP_FANCY_MODE_TRANSITION_CELL_X_GAP * x,
                                            VCP_FANCY_MODE_TRANSITION_CELL_Y_START + VCP_FANCY_MODE_TRANSITION_CELL_Y_GAP * y));
            }
        }
    }
    // connect the last timeline
    m_menuItemTimeline2[VCP_FANCY_MODE_TRANSITION_CELL_COUNT-1]->m_signalStopped.connect(this, &VcpFancyModeMenuTransition::onEndOfItemTimeline);

}

void VcpFancyModeMenuTransition::switchToSpaceBeam(VfxBool isReverse)
{
    m_isReverse = isReverse;

    if (m_dataMgr == NULL)
    {
        VFX_ASSERT(0);
    }
    // fake menu
    VfxS32 i;

    for (i = 0; i < VCP_FANCY_MODE_TRANSITION_CELL_COUNT; i++)
    {
        VFX_OBJ_CREATE(m_menuIcon[i] ,VfxFrame, this);
        m_menuIcon[i]->setRect(VfxRect(0, 0, VCP_FANCY_MODE_CELL_WIDTH, VCP_FANCY_MODE_CELL_HEIGHT));

        if (m_dataMgr->getIconId(m_focus + i) == 0)
        {
            m_menuIcon[i]->setHidden(VFX_TRUE);
        }
        else
        {
            m_menuIcon[i]->setImgContent(VfxImageSrc(m_dataMgr->getIconId(m_focus + i)));
        }
    }

    VfxS32 x,y;
    for (y = 0; y < VCP_FANCY_MODE_TRANSITION_CELL_ROW_COUNT; y++)
    {
        for (x = 0; x < VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW; x++)
        {
            m_menuIcon[y * VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW + x]->setPos(VCP_FANCY_MODE_TRANSITION_CELL_X_START + VCP_FANCY_MODE_TRANSITION_CELL_X_GAP * x,
                                            VCP_FANCY_MODE_TRANSITION_CELL_Y_START + VCP_FANCY_MODE_TRANSITION_CELL_Y_GAP * y);
        }
    }
    
    // create timeline to move
    for (i = 0; i < VCP_FANCY_MODE_TRANSITION_CELL_COUNT; i++)
    {
        VFX_OBJ_CREATE(m_menuItemTimeline[i], VfxPointTimeline, this);
        m_menuItemTimeline[i]->setTarget(m_menuIcon[i]);
        m_menuItemTimeline[i]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        m_menuItemTimeline[i]->setDurationTime(500);
        m_menuItemTimeline[i]->setStartDelay(20*i);
        
        if (!isReverse)
        {
            m_menuItemTimeline[i]->setToValue(
                                        VfxPoint(VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_X, VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_Y)
                                        );
            m_menuItemTimeline[i]->setIsFromCurrent(VFX_TRUE);
        }
        m_menuItemTimeline[i]->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_menuItemTimeline[i]->start();

        // scale 
        VFX_OBJ_CREATE(m_menuItemScaleTimeline[i], VfxTransformTimeline, this);
        m_menuItemScaleTimeline[i]->setTarget(m_menuIcon[i]);
        m_menuItemScaleTimeline[i]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        m_menuItemScaleTimeline[i]->setDurationTime(500);
        m_menuItemScaleTimeline[i]->setStartDelay(20*i);
        
        VfxTransform tempTransform;
        tempTransform.data.affine.sx = VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_SCALE;
        tempTransform.data.affine.sy = VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_SCALE;
        if (isReverse)
        {
            m_menuItemScaleTimeline[i]->setToValue(VfxTransform());
            m_menuItemScaleTimeline[i]->setFromValue(tempTransform);
        }
        else
        {
            m_menuItemScaleTimeline[i]->setToValue(tempTransform);
            m_menuItemScaleTimeline[i]->setIsFromCurrent(VFX_TRUE);
        }
        m_menuItemScaleTimeline[i]->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_menuItemScaleTimeline[i]->start();

        // opacity
        VFX_OBJ_CREATE(m_menuItemOpacityTimeline[i], VfxFloatTimeline, this);
        m_menuItemOpacityTimeline[i]->setTarget(m_menuIcon[i]);
        m_menuItemOpacityTimeline[i]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
        m_menuItemOpacityTimeline[i]->setDurationTime(500);
        m_menuItemOpacityTimeline[i]->setStartDelay(20*i);
        if (isReverse)
        {
            m_menuItemOpacityTimeline[i]->setToValue(1.0f);
            m_menuItemOpacityTimeline[i]->setFromValue(0);
        }
        else
        {
            m_menuItemOpacityTimeline[i]->setToValue(0);
            m_menuItemOpacityTimeline[i]->setIsFromCurrent(VFX_TRUE);
        }
        m_menuItemOpacityTimeline[i]->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_menuItemOpacityTimeline[i]->start();
    }

    if (isReverse)
    {
        VfxTransform tempTransform;
        tempTransform.data.affine.sx = VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_SCALE;
        tempTransform.data.affine.sy = VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_SCALE;
        for (y = 0; y < VCP_FANCY_MODE_TRANSITION_CELL_ROW_COUNT; y++)
        {
            for (x = 0; x < VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW; x++)
            {
                m_menuIcon[y * VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW + x]->setPos(VfxPoint(VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_X, VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_Y));
                m_menuIcon[y * VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW + x]->setTransform(tempTransform);
                m_menuIcon[y * VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW + x]->setOpacity(0);
                m_menuItemTimeline[y * VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW + x]->setFromValue(VfxPoint(VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_X, VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_Y));
                m_menuItemTimeline[y * VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW + x]->setToValue(VfxPoint(VCP_FANCY_MODE_TRANSITION_CELL_X_START + VCP_FANCY_MODE_TRANSITION_CELL_X_GAP * x,
                                            VCP_FANCY_MODE_TRANSITION_CELL_Y_START + VCP_FANCY_MODE_TRANSITION_CELL_Y_GAP * y));
            }
        }
    }
    // connect the last timeline
    m_menuItemTimeline[VCP_FANCY_MODE_TRANSITION_CELL_COUNT - 1]->m_signalStopped.connect(this, &VcpFancyModeMenuTransition::onEndOfItemTimeline);
    
}


void VcpFancyModeMenuTransition::onEndOfItemTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    
    if (isCompleted)
    {
        if (m_isReverse)
        {
            for (VfxU32 i = 0; i < VCP_FANCY_MODE_TRANSITION_CELL_COUNT; i++)
            {
                VFX_OBJ_CREATE(m_menuText[i] ,VfxTextFrame, this);

                if (m_dataMgr->getTitle(m_focus + i) == VFX_WSTR_NULL)
                {
                    m_menuText[i]->setHidden(VFX_TRUE);
                }
                else
                {
                    m_menuText[i]->setString(m_dataMgr->getTitle(m_focus + i));
                    VfxFontDesc fontDesc;
                    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_FANCY_MODE_TRANSITION_CELL_TEXT_SIZE);
                    m_menuText[i]->setFont(fontDesc);
                    m_menuText[i]->setFullLineHeightMode(VFX_TRUE);
                    VfxS32 x = VCP_FANCY_MODE_TRANSITION_CELL_TEXT_X_START + (i % VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW) * VCP_FANCY_MODE_TRANSITION_CELL_X_GAP;
                    VfxS32 y = VCP_FANCY_MODE_TRANSITION_CELL_TEXT_Y_START + (i / VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW) * VCP_FANCY_MODE_TRANSITION_CELL_Y_GAP;
                    m_menuText[i]->setPos(x, y);
                    m_menuText[i]->setOpacity(0.0f);
                    m_menuText[i]->setSize(VCP_FANCY_MODE_TRANSITION_CELL_TEXT_WIDTH, VCP_FANCY_MODE_TRANSITION_CELL_TEXT_HEIGHT);
                    m_menuText[i]->setAnchor(0.0f, 0.0f);
                    m_menuText[i]->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
                    m_menuText[i]->setAutoResized(VFX_FALSE);
                    m_menuText[i]->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

                    VFX_OBJ_CREATE(m_menuItemAlphaTimeline[i], VfxFloatTimeline, this);
                    m_menuItemAlphaTimeline[i]->setTarget(m_menuText[i]);
                    m_menuItemAlphaTimeline[i]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
                    m_menuItemAlphaTimeline[i]->setDurationTime(250);
                    m_menuItemAlphaTimeline[i]->setFromValue(0.0f);
                    m_menuItemAlphaTimeline[i]->setToValue(1.0f);
                    m_menuItemAlphaTimeline[i]->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
                    m_menuItemAlphaTimeline[i]->start();
                }

            }
            m_menuItemAlphaTimeline[0]->m_signalStopped.connect(this, &VcpFancyModeMenuTransition::onEndOfItemTextTimeline);
        }
        else
        {
            m_signalTransitionFinished.emit();
        }
    }
}

void VcpFancyModeMenuTransition::onEndOfItemTextTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);

    if (isCompleted)
    {
        m_signalTransitionFinished.emit();
    }
}

/***************************************************************************** 
 * Class VcpTornadoMenu
 *****************************************************************************/
 
VcpTornadoMenu::VcpTornadoMenu() :
    m_subCount(1),
    m_cellOpaque(VFX_FALSE),
    m_cellTextOn(VFX_FALSE),
    m_cellOpacity(VFX_TRUE),
    m_dataMgr(NULL),
    m_isSwipe(VFX_FALSE),
    m_qualityTimer(NULL),
    m_textVisible(VFX_FALSE)
{}


void VcpTornadoMenu::onInit()
{       
    VcpWheelMenu::onInit();

    setIsZSortChild(VFX_TRUE);

    // set Text area , we does not calculate text position and size from 3D model
    // because set size will make it blur, and it is diffcult to pass 3D matrix out
    // from FPE. Set small font can get clear text

    VfxFontDesc fontDesc;
    VfxS32 i;

    for (i = 0; i < VCP_TORNADO_MENU_TEXT_COUNT; i++)
    {
        VFX_OBJ_CREATE(m_text[i], VfxTextFrame, this);
        m_text[i]->setAnchor(0.5f, 0.5f);
        m_text[i]->setOpacity(0);
        m_text[i]->setAutoAnimate(VFX_TRUE);
        // text always on the top of any thing, set a very small number
        m_text[i]->setPosZ(-1000);
        m_text[i]->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_text[i]->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_text[i]->setFullLineHeightMode(VFX_TRUE);
        
    }
    // adjust postion and font size for each resolution
#if defined(__MMI_MAINLCD_320X480__)
    m_text[0]->setPos(160, 88);
    m_text[0]->setBounds(0, 0, 80, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(14);
    m_text[0]->setFont(fontDesc);
    
    m_text[1]->setPos(160, 190);
    m_text[1]->setBounds(0, 0, 70, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(12);
    m_text[1]->setFont(fontDesc);
   
    m_text[2]->setPos(160, 273);
    m_text[2]->setBounds(0, 0, 65, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(11);
    m_text[2]->setFont(fontDesc);
    
    m_text[3]->setPos(160, 340);
    m_text[3]->setBounds(0, 0, 55, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(8);
    m_text[3]->setFont(fontDesc);
    
    m_text[4]->setPos(160, 400);
    m_text[4]->setBounds(0, 0, 55, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(8);
    m_text[4]->setFont(fontDesc);
#elif defined(__MMI_MAINLCD_240X320__)
    m_text[0]->setPos(120, 71);
    m_text[0]->setBounds(0, 0, 80, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(14);
    m_text[0]->setFont(fontDesc);
    
    m_text[1]->setPos(120, 138);
    m_text[1]->setBounds(0, 0, 70, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(13);
    m_text[1]->setFont(fontDesc);
   
    m_text[2]->setPos(120, 198);
    m_text[2]->setBounds(0, 0, 65, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(12);
    m_text[2]->setFont(fontDesc);
    
    m_text[3]->setPos(120, 251);
    m_text[3]->setBounds(0, 0, 55, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(11);
    m_text[3]->setFont(fontDesc);
    
#elif defined(__MMI_MAINLCD_240X400__)
#if defined(__MMI_FTE_SUPPORT_SLIM__)
    m_text[0]->setPos(120, 100);
    m_text[0]->setBounds(0, 0, 80, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(14);
    m_text[0]->setFont(fontDesc);
    
    m_text[1]->setPos(120, 205);
    m_text[1]->setBounds(0, 0, 70, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(13);
    m_text[1]->setFont(fontDesc);
   
    m_text[2]->setPos(120, 295);
    m_text[2]->setBounds(0, 0, 65, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(12);
    m_text[2]->setFont(fontDesc);
    
    m_text[3]->setPos(120, 420);
    m_text[3]->setBounds(0, 0, 55, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(11);
    m_text[3]->setFont(fontDesc);
    
    m_text[4]->setPos(120, 420);
    m_text[4]->setBounds(0, 0, 55, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(10);
    m_text[4]->setFont(fontDesc);
#else
    m_text[0]->setPos(120, 70);
    m_text[0]->setBounds(0, 0, 80, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(14);
    m_text[0]->setFont(fontDesc);
    
    m_text[1]->setPos(120, 150);
    m_text[1]->setBounds(0, 0, 70, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(13);
    m_text[1]->setFont(fontDesc);
   
    m_text[2]->setPos(120, 220);
    m_text[2]->setBounds(0, 0, 65, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(12);
    m_text[2]->setFont(fontDesc);
    
    m_text[3]->setPos(120, 277);
    m_text[3]->setBounds(0, 0, 55, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(11);
    m_text[3]->setFont(fontDesc);
    
    m_text[4]->setPos(120, 330);
    m_text[4]->setBounds(0, 0, 55, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(10);
    m_text[4]->setFont(fontDesc);
#endif /* __MMI_FTE_SUPPORT_SLIM__ */
#else
    m_text[0]->setPos(160, 88);
    m_text[0]->setBounds(0, 0, 80, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(14);
    m_text[0]->setFont(fontDesc);
    
    m_text[1]->setPos(160, 190);
    m_text[1]->setBounds(0, 0, 70, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(12);
    m_text[1]->setFont(fontDesc);
   
    m_text[2]->setPos(160, 273);
    m_text[2]->setBounds(0, 0, 65, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(11);
    m_text[2]->setFont(fontDesc);
    
    m_text[3]->setPos(160, 340);
    m_text[3]->setBounds(0, 0, 55, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(8);
    m_text[3]->setFont(fontDesc);
    
    m_text[4]->setPos(160, 400);
    m_text[4]->setBounds(0, 0, 55, 30);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(8);
    m_text[4]->setFont(fontDesc);
#endif

}


void VcpTornadoMenu::setBounds(const VfxRect &value)
{
    VcpWheelMenu::setBounds(value);
    // set Camera parameter
    m_camera.setCamera(
        1.0f, 
        1.0f, 
        (VfxFloat)(getBounds().size.width/2), 
        (VfxFloat)(getBounds().size.height/2 + VCP_TORNADO_MENU_Y_SHIFT), // shift to up 55
        (VfxFloat)VCP_TORNADO_MENU_NEAR_PLANE, 
        (VfxFloat)VCP_TORNADO_MENU_CAMERA_DISTANCE, 
        0, 
        0, 
        0);
}


VfxFrame* VcpTornadoMenu::createCell(VfxS32 cell, VfxS32 subcell)
{
    if (m_dataMgr == NULL)
    {
        VFX_ASSERT(0);
    }
    if (subcell == 0)
    {
        VfxFrame *item;
        VFX_OBJ_CREATE(item, VfxFrame, this);
        item->setRect(VfxRect(0, 0, VCP_FANCY_MODE_CELL_WIDTH, VCP_FANCY_MODE_CELL_HEIGHT));
        item->setImgContent(VfxImageSrc(m_dataMgr->getIconId(cell)));
        item->setQuality(VFX_RENDER_QUALITY_NORMAL);
    #if defined(__MMI_FTE_SUPPORT_SLIM__)
        item->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_COLOR_KEY);
    #endif
        if (m_cellOpaque)
        {
            item->setIsOpaque(VFX_TRUE);
        }
    
        VcpTwistMenuUserData data;
        data.isOpacity = m_cellOpacity;
        data.camera = m_camera;
        setCellUserData(cell, subcell, item, &data, sizeof(data));

        return item;
    }
    else
    {
        VfxTextFrame  *item;
        VFX_OBJ_CREATE(item, VfxTextFrame, this);

        item->setBounds(0, 0, VCP_FANCY_MODE_CELL_WIDTH, 30);
        item->setColor(VFX_COLOR_WHITE);
        item->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        item->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        item->setFont(VFX_FONT_DESC_SMALL);
        item->setCullingType(VFX_FRAME_CULLING_TYPE_BACK);
        item->setBgColor(VFX_COLOR_BLACK);
        item->setIsOpaque(VFX_TRUE);

        item->setString(m_dataMgr->getTitle(cell));

        VcpTwistMenuUserData data;
        data.isOpacity = m_cellOpacity;
        data.camera = m_camera;
        setCellUserData(cell, subcell, item, &data, sizeof(data));

        return item;
    }

}
   

void VcpTornadoMenu::onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame)
{
    VFX_UNUSED(cell);
    VFX_UNUSED(subcell);

    VFX_OBJ_CLOSE(cellFrame);
}
    

void VcpTornadoMenu::onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem)
{}


void VcpTornadoMenu::onStateChangeFinished(VcpWheelMenuState finishedState)
{
    if (finishedState == VCP_WHEEL_MENU_ENTER_STATE)
    {
        m_signalEnterFinished.emit();
        setTextVisible(VFX_TRUE);
        setAllCellQuality(VFX_RENDER_QUALITY_HIGH);
    }
}


void VcpTornadoMenu::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    VFX_UNUSED(yoffset);
    setScrollIndex(getScrollIndex() - VfxFloat(xoffset) / VCP_FANCY_MODE_CELL_WIDTH, 0);
    if (xoffset != 0)
    {
        setTextVisible(VFX_FALSE);
    }
    VFX_OBJ_CLOSE(m_qualityTimer);
}


void VcpTornadoMenu::setAllCellQuality(VfxRenderQualityEnum value)
{
    VfxS32 i;
    VfxFrame *temp;
    for (i = m_firstVisibleItem; i < m_lastVisibleItem; i++)
    {
        temp = getCellIfPresent(i);
        temp->setQuality(value);
    }
}


void VcpTornadoMenu::onQualityTimerStop(VfxTimer *source)
{
    VFX_OBJ_CLOSE(m_qualityTimer);
    setAllCellQuality(VFX_RENDER_QUALITY_HIGH);
    setTextVisible(VFX_TRUE);
}


VfxBool VcpTornadoMenu::onPenInput(VfxPenEvent & event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        m_isSwipe = VFX_FALSE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        VfxPoint dowmpt = event.getRelDownPos(this);
        VfxPoint pt     = event.getRelPos(this);
        if (VFX_ABS(pt.x - dowmpt.x) > 200 || VFX_ABS(pt.y - dowmpt.y) > 200)
        {
            m_isSwipe = VFX_TRUE;
        }
    }
    return VcpWheelMenu::onPenInput(event);
}

void VcpTornadoMenu::onDragEnd(VfxS32 xspeed, VfxS32 yspeed)
{
    VFX_UNUSED(yspeed);
    VfxMsec duration = 300;

    VfxS32   s = xspeed > 0 ? 1 : -1;
    if (xspeed == 0) 
    {
        if (getScrollIndex() > getFocus())
        {
            setFocus((VfxS32)vfxCeil(getScrollIndex()), duration);
        }
        else if (getScrollIndex() < getFocus())
        {
            setFocus((VfxS32)vfxFloor(getScrollIndex()), duration);
        }
        else
        {
            // getScrollIndex() == getFocus() do not set quality
            //return;
        }
    }
    else if (VFX_ABS(xspeed) < 320 || !m_isSwipe)
    {
        VfxS32 newFocus =  (VfxS32) (s > 0 ? vfxFloor : vfxCeil) (getScrollIndex());

        setFocus(newFocus, duration);
    }
    else
    {
        VfxFloat m = VFX_ABS(xspeed) / 66.6f;        
        if (m > 16) 
        {
            m = 16;
        }        
        duration = 800;
        setFocus(VfxS32(getScrollIndex() - s * m + 0.5f), duration);
    }
    if (m_textVisible == VFX_FALSE)
    {
        setAllCellQuality(VFX_RENDER_QUALITY_NORMAL);
        // start a timer to reset quality
        VFX_OBJ_CREATE(m_qualityTimer, VfxTimer, this);
        m_qualityTimer->m_signalTick.connect(this, &VcpTornadoMenu::onQualityTimerStop);
        m_qualityTimer->setStartDelay(duration);
        m_qualityTimer->start();
    }
   
}


VfxBool VcpTornadoMenu::hitTestonCell(VfxPoint pt, VfxS32 cell, VfxS32 subCell)
{
    VfxFrame* item = getCellIfPresent(cell, subCell);
    if (item)
    {
        m_clickBgTransform = item->forceGetTransform();
        VfxMatrix3x3Ex inv = VfxMatrix3x3Ex(m_clickBgTransform.data.matrix3x3);
        inv.inverse();

        VfxPoint point = inv.transform(pt);
        point = convertPointTo(point, item);
        if (item->getBounds().contains(point))
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

void VcpTornadoMenu::onTap(VfxPoint pt)
{
    // forground cell
    VfxS32 focusCell = getFocus();
    VfxS32 testCell = focusCell;

    // because we don't support tap according to Z pos.
    // We need to do hit test by the sequence we assume.
    // We fisrt test the neareset cell then test other cell outside.
    // Because it is relative to the number of cell in one circle and 
    // the number of total cell in screen. So, if you modify the number 
    // we discuss above, you need to modify the number of calling hitTestonCell()

    // hit test on launch area

    // find the fisrt launch cell.
    while (testCell >= focusCell - VCP_TORNADO_MENU_AHEAD_COUNT && testCell >= 0)
    {
        testCell -= VCP_TORNADO_MENU_CELL_COUNT_IN_CIRCLE;
    }
    while (testCell < focusCell + VCP_TORNADO_MENU_BEHIND_COUNT && testCell < getCount())
    {
        testCell += VCP_TORNADO_MENU_CELL_COUNT_IN_CIRCLE;
        if (hitTestonCell(pt, testCell, 0))
        {
            m_signalSelected.emit(this, m_dataMgr->getIndex(testCell));
            return;
        }
    }
    VfxS32 distance = 1;
    while (distance <= VCP_TORNADO_MENU_CELL_COUNT_IN_CIRCLE/2)
    {
        testCell = focusCell - distance;
        while (testCell >= focusCell - VCP_TORNADO_MENU_AHEAD_COUNT  && testCell >= 0)
        {
            testCell -= VCP_TORNADO_MENU_CELL_COUNT_IN_CIRCLE;
        }
        while (testCell < focusCell + VCP_TORNADO_MENU_BEHIND_COUNT && testCell < getCount())
        {
            testCell += VCP_TORNADO_MENU_CELL_COUNT_IN_CIRCLE;
            if (hitTestonCell(pt, testCell, 0))
            {
                // move
                // consider boundary case
                if (focusCell == 0)
                {
                    setFocus(focusCell + VCP_TORNADO_MENU_CELL_COUNT_IN_CIRCLE - distance, 300);
                }
                else
                {
                    setFocus(focusCell - distance, 300);
                }
                // change text context
                setTextVisible(VFX_TRUE);
                return;
            }
        }
        testCell = focusCell + distance;
        while (testCell >= focusCell - VCP_TORNADO_MENU_AHEAD_COUNT  && testCell >= 0)
        {
            testCell -= VCP_TORNADO_MENU_CELL_COUNT_IN_CIRCLE;
        }
        while (testCell < focusCell + VCP_TORNADO_MENU_BEHIND_COUNT && testCell < getCount())
        {
            testCell += VCP_TORNADO_MENU_CELL_COUNT_IN_CIRCLE;
            if (hitTestonCell(pt, testCell, 0))
            {
                // move
                // consider boundary case
                if (focusCell + distance > getCount() - 1)
                {
                    setFocus(testCell, 300);
                }
                else
                {
                    setFocus(focusCell + distance, 300);
                }
                // change text context
                setTextVisible(VFX_TRUE);
                return;
            }
        }
        distance ++;
    }
    
}

void VcpTornadoMenu::setTextVisible(VfxBool value)
{
    m_textVisible = value;
    if (value == VFX_TRUE)
    {
        VfxS32 i;
        VfxS32 testCell = getFocus();
        testCell -= VCP_TORNADO_MENU_CELL_COUNT_IN_CIRCLE;
        for (i = 0; i < VCP_TORNADO_MENU_TEXT_COUNT; i++)
        {
            if (getCellIfPresent(testCell, 0))
            {
                m_text[i]->setString(m_dataMgr->getTitle(testCell));
                m_text[i]->setOpacity(1.0f);
                //m_text[i]->bringToFront();
            }
            else
            {
                m_text[i]->setOpacity(0);
            }
            testCell += VCP_TORNADO_MENU_CELL_COUNT_IN_CIRCLE;
        }
    }
    else
    {
        VfxS32 i;
        for (i = 0; i < VCP_TORNADO_MENU_TEXT_COUNT; i++)
        {
            m_text[i]->setOpacity(0);
        }
    }
}

#ifdef __MTK_TARGET__
#pragma arm
#endif

vrt_render_dirty_type_enum VcpTornadoMenu::myFrameEffectCB(
    VfxS32                              cell,           // [IN] the cell index
    VfxS32                              subCell,        // [IN] the sub cell index
    VfxFloat                            cellRelPos,     // [IN] the cell position
    vrt_frame_visual_property_struct    *target_frame,  // [IN] the cell frame
    VfxFloat                            fPos,           // [IN] animating index value
    VfxS32                              focus,          // the focus value of the menu
    VfxRect                             viewBounds,     // the menu bounds
    void                                *userData,      // user data
    VfxU32                              userDataSize,   // user data size
    VcpWheelMenuState                   state,          // [IN] the state of Menu
    VfxFloat                            level           // [IN] the level of state
)
{
    VFX_UNUSED(focus);
    VFX_UNUSED(userDataSize);
    VFX_DEV_ASSERT(target_frame != NULL);

    VFX_DEV_ASSERT(userDataSize == sizeof(VcpTwistMenuUserData));
    VcpTwistMenuUserData* data = (VcpTwistMenuUserData*)userData;

    VfxFloat offset;

    if (state == VCP_WHEEL_MENU_NORMAL_STATE)
    {
        offset = cellRelPos;
    }
    else if (state == VCP_WHEEL_MENU_ENTER_STATE)
    {
        offset = level * (cellRelPos - (VCP_TORNADO_MENU_BEHIND_COUNT + 3)) + (VCP_TORNADO_MENU_BEHIND_COUNT + 3);
    }
    else // if (state == VCP_WHEEL_MENU_LEAVE_STATE)
    {
        offset = (1 - level) * (cellRelPos - (VCP_TORNADO_MENU_BEHIND_COUNT + 3)) + (VCP_TORNADO_MENU_BEHIND_COUNT + 3);
    }
    
    VfxMatrix4x4 totalProject;
    VfxMatrix4x4 cameraView;
    VfxMatrix4x4 modelView;
    VfxMatrix4x4 RT;
    
    cameraView = data->camera;
    
    // set Model View :
    // The model view matirx decides the origin and direction of model.
    // We set the origin of each item to the center of item.
    // So we need to apply a negative translate. 
    if (subCell == 0)
    {
        modelView.setTranslation((VfxFloat)((-1 * VCP_FANCY_MODE_CELL_WIDTH/2)), 
                        (VfxFloat)(-1 * VCP_FANCY_MODE_CELL_HEIGHT/2), 
                        0);
    }
    else
    {
        modelView.setTranslation((VfxFloat)((-1 * VCP_FANCY_MODE_CELL_WIDTH/2)), 
                        (VfxFloat)(VCP_FANCY_MODE_CELL_HEIGHT/2), 
                        0);
    }

    if (offset > VCP_TORNADO_MENU_BEHIND_COUNT)
    {
        
        VfxFloat tempOffset = VCP_TORNADO_MENU_BEHIND_COUNT;
        VfxFloat distance = ((tempOffset + VCP_TORNADO_MENU_AHEAD_COUNT) * (VCP_TORNADO_MENU_TO_RADIUS - VCP_TORNADO_MENU_FROM_RADIUS)/(VCP_TORNADO_MENU_AHEAD_COUNT + VCP_TORNADO_MENU_BEHIND_COUNT) + VCP_TORNADO_MENU_FROM_RADIUS);

        #define  VCP_TWIST_MENU_OPT_AAA  (VCP_TORNADO_MENU_ANGLE/ 180.0f * VFX_PI)
        VfxFloat angleAAA = tempOffset * VCP_TWIST_MENU_OPT_AAA - VFX_PI/2;
        
        RT.m[12] = vfxCos(angleAAA) * distance;
        RT.m[13] = (tempOffset * 0.125f + (offset - tempOffset)) * VCP_TORNADO_MENU_Y_GAP;
        RT.m[14] = vfxSin(angleAAA) * distance;

        #define  VCP_TWIST_MENU_OPT_BBB  (-1.0f * VCP_TORNADO_MENU_ANGLE/ 180.0f * VFX_PI)
        VfxFloat angleBBB = tempOffset * VCP_TWIST_MENU_OPT_BBB;
        
        RT.m[0] = RT.m[10] = vfxCos(angleBBB);
        RT.m[8] = vfxSin(angleBBB);
        RT.m[2] = -1 * RT.m[8];
    }
    else
    {
        VfxFloat distance = ((offset + VCP_TORNADO_MENU_AHEAD_COUNT) * (VCP_TORNADO_MENU_TO_RADIUS - VCP_TORNADO_MENU_FROM_RADIUS)/(VCP_TORNADO_MENU_AHEAD_COUNT + VCP_TORNADO_MENU_BEHIND_COUNT) + VCP_TORNADO_MENU_FROM_RADIUS);
        //VfxFloat distance = 150;
        
        #define  VCP_TWIST_MENU_OPT_AAA  (VCP_TORNADO_MENU_ANGLE/ 180.0f * VFX_PI)
        VfxFloat angleAAA = offset * VCP_TWIST_MENU_OPT_AAA - VFX_PI/2;

        RT.m[12] = vfxCos(angleAAA) * distance;
        RT.m[13] = offset * 0.125f * VCP_TORNADO_MENU_Y_GAP; 
        RT.m[14] = vfxSin(angleAAA) * distance;

        #define  VCP_TWIST_MENU_OPT_BBB  (-1.0f * VCP_TORNADO_MENU_ANGLE/ 180.0f * VFX_PI)
        VfxFloat angleBBB = offset * VCP_TWIST_MENU_OPT_BBB;

        RT.m[0] = RT.m[10] = vfxCos(angleBBB);
        RT.m[8] = vfxSin(angleBBB);
        RT.m[2] = -1 * RT.m[8];
    }
    
    // Now we multiply cameraView, RT and modelview to get totalProject. 
    //totalProject = cameraView * RT * modelView;
    
    //totalProject = cameraView;
    //totalProject *= RT;
    //totalProject *= modelView;

    // Set as 3x3 matrix for VRT rendering.
    //target_frame->transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3; 
    //totalProject.initMatrix3x3(target_frame->transform.data.matrix3x3);

    // optimize above code
    target_frame->transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3; 
    VfxFloat temp = RT.m[2] * modelView.m[12] + RT.m[14];
    target_frame->transform.data.matrix3x3.m[0] = RT.m[0] + cameraView.m[8] * RT.m[2];
    target_frame->transform.data.matrix3x3.m[3] = 0;
    target_frame->transform.data.matrix3x3.m[6] = RT.m[0] * modelView.m[12] + RT.m[12] + cameraView.m[8] * temp + cameraView.m[12];
    target_frame->transform.data.matrix3x3.m[1] = cameraView.m[9] * RT.m[2];
    target_frame->transform.data.matrix3x3.m[4] = 1.0f;
    target_frame->transform.data.matrix3x3.m[7] = modelView.m[13] + RT.m[13] + cameraView.m[9] * temp + cameraView.m[13];
    target_frame->transform.data.matrix3x3.m[2] = cameraView.m[11] * RT.m[2];
    target_frame->transform.data.matrix3x3.m[5] = 0;
    target_frame->transform.data.matrix3x3.m[8] = cameraView.m[11] * temp + cameraView.m[15];
    
    target_frame->pos_z = RT.m[14];

    // adjust opacity
    // boundary check
    
    // check addional 10 item
    if (offset > VCP_TORNADO_MENU_BEHIND_COUNT + 10)
    {
        target_frame->opacity = 1.0f - (offset - VCP_TORNADO_MENU_BEHIND_COUNT);
        if (target_frame->opacity < 0)
        {
            target_frame->opacity = 0;
        }    
    }
    else if (offset < -1 * VCP_TORNADO_MENU_AHEAD_COUNT)
    {
        //target_frame->opacity = 1.0f - (-1 * VCP_TORNADO_MENU_AHEAD_COUNT - offset);
        target_frame->opacity = 1.0f + VCP_TORNADO_MENU_AHEAD_COUNT + offset;
        if (target_frame->opacity < 0)
        {
            target_frame->opacity = 0;
        }
    }
    else
    {
        if (subCell == 0)
        {
            if (data->isOpacity)
            {
                VfxFloat shift;
                // We want the item far from the screen opacity near to 0.5,
                // and close to screen near to 1.
                // This code also relative to the number in a circle and the
                // total number of cell in screen. if you add more items,
                // you need to add enough if check
                if (offset > -16 && offset <= -8)
                {
                    shift = VFX_ABS(offset - (-12));
                }
                else if (offset > -8  && offset <= 0)
                {
                    shift = VFX_ABS(offset - (-4));
                }
                else if (offset > 0 && offset <= 8)
                {
                    shift = VFX_ABS(offset - (4));
                }
                else if (offset > 8 && offset <= 16)
                {
                    shift = VFX_ABS(offset - (12));
                }
                else if (offset > 16 && offset <= 24)
                {
                    shift = VFX_ABS(offset - (20));
                }
                else
                {
                    shift = 4;
                }
                //target_frame->opacity = shift / 4 * 0.5 + 0.5;
                target_frame->opacity = shift * 0.125 + 0.5;
            }
            else
            {
                target_frame->opacity = 1;
            }
        }
        else
        {
            target_frame->opacity = 1;
        }
    }
   
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

#ifdef __MTK_TARGET__
#pragma thumb
#endif

void VcpTornadoMenu::enter()
{
    configureStatePara(VCP_WHEEL_MENU_ENTER_STATE, 500, 250, VCP_WHEEL_MENU_ALL_TOGETHER);
    changeState(VCP_WHEEL_MENU_ENTER_STATE);
}

void VcpTornadoMenu::leave()
{
    configureStatePara(VCP_WHEEL_MENU_LEAVE_STATE, 500, 250, VCP_WHEEL_MENU_ALL_TOGETHER);
    changeState(VCP_WHEEL_MENU_LEAVE_STATE);

    // do not trigger qualityTimer time out when leave
    VFX_OBJ_CLOSE(m_qualityTimer);

    // Artist want to inVisible immediately
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    setTextVisible(VFX_FALSE);
    VfxAutoAnimate::commit();
}

/***************************************************************************** 
 * Class VcpSpaceBeamMenu
 *****************************************************************************/
 
VcpSpaceBeamMenu::VcpSpaceBeamMenu() :
    m_subCount(VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW),
    m_cellOpaque(VFX_FALSE),
    m_cellTextOn(VFX_FALSE),
    m_cellOpacity(VFX_FALSE),
    m_dataMgr(NULL),
    m_isSwipe(VFX_FALSE),
    m_qualityTimer(NULL),
    m_textVisible(VFX_FALSE)
{}


void VcpSpaceBeamMenu::onInit()
{       
    VcpWheelMenu::onInit();
    setIsZSortChild(VFX_TRUE);

    // set Text area , we does not calculate text position and size from 3D model
    // because set size will make it blur, and it is diffcult to pass 3D matrix out
    // from FPE. Set small font can get clear text

    VfxFontDesc fontDesc;
    VfxS32 i;
    for (i = 0; i < VCP_SPACE_BEAM_MENU_TEXT_COUNT; i++)
    {
        VFX_OBJ_CREATE(m_text[i], VfxTextFrame, this);
        m_text[i]->setAnchor(0.5f, 0.5f);
        m_text[i]->setOpacity(0);
        m_text[i]->setAutoAnimate(VFX_TRUE);
        // text always on the top of any thing, set a very small number
        m_text[i]->setPosZ(-1000);
        m_text[i]->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_text[i]->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        fontDesc.size = VFX_FONT_DESC_VF_SIZE(13);
        m_text[i]->setFont(fontDesc);
        m_text[i]->setFullLineHeightMode(VFX_TRUE);
    }
// adjust postion and font size for each resolution    
#if defined(__MMI_MAINLCD_320X480__)
    m_text[0]->setPos(47, 325);
    m_text[0]->setBounds(0, 0, 73, 30);
    
    m_text[1]->setPos(123, 325);
    m_text[1]->setBounds(0, 0, 73, 30);

    m_text[2]->setPos(198, 325);
    m_text[2]->setBounds(0, 0, 73, 30);

    m_text[3]->setPos(274, 325);
    m_text[3]->setBounds(0, 0, 73, 30);
#elif defined(__MMI_MAINLCD_240X320__)

    m_text[0]->setPos(50, 243);
    m_text[0]->setBounds(0, 0, 61, 30);
    
    m_text[1]->setPos(120, 243);
    m_text[1]->setBounds(0, 0, 61, 30);

    m_text[2]->setPos(190, 243);
    m_text[2]->setBounds(0, 0, 61, 30);

#elif defined(__MMI_MAINLCD_240X400__)

    m_text[0]->setPos(40, 308);
    m_text[0]->setBounds(0, 0, 61, 30);
    
    m_text[1]->setPos(120, 308);
    m_text[1]->setBounds(0, 0, 61, 30);

    m_text[2]->setPos(200, 308);
    m_text[2]->setBounds(0, 0, 61, 30);

#else
    m_text[0]->setPos(47, 325);
    m_text[0]->setBounds(0, 0, 73, 30);
    
    m_text[1]->setPos(123, 325);
    m_text[1]->setBounds(0, 0, 73, 30);

    m_text[2]->setPos(198, 325);
    m_text[2]->setBounds(0, 0, 73, 30);

    m_text[3]->setPos(274, 325);
    m_text[3]->setBounds(0, 0, 73, 30);
#endif

}


void VcpSpaceBeamMenu::setBounds(const VfxRect &value)
{
    VcpWheelMenu::setBounds(value);
    // set Camera parameter
    m_camera.setCamera(
        1.0f, 
        1.0f, 
        (VfxFloat)(getBounds().size.width/2), 
        (VfxFloat)(getBounds().size.height/2 + VCP_SPACE_BEAM_MENU_Y_SHIFT),
        (VfxFloat)VCP_SPACE_BEAM_MENU_NEAR_PLANE, 
        (VfxFloat)VCP_SPACE_BEAM_MENU_CAMERA_DISTANCE, 
        (VfxFloat)VCP_SPACE_BEAM_MENU_CAMERA_UP, 
        0, 
        0);
}


VfxFrame* VcpSpaceBeamMenu::createCell(VfxS32 cell, VfxS32 subcell)
{
    if (m_dataMgr == NULL)
    {
        VFX_ASSERT(0);
    }
    if (subcell < VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW)
    {      
        VfxS32 index = cell * VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW + subcell;

        VfxFrame *item;
        VFX_OBJ_CREATE(item, VfxFrame, this);
        item->setRect(VfxRect(0, 0, VCP_FANCY_MODE_CELL_WIDTH, VCP_FANCY_MODE_CELL_HEIGHT));
        if (m_dataMgr->getIconId(index) == 0)
        {
            // empty cell
            item->setHidden(VFX_TRUE);
        }
        else
        {
            item->setImgContent(VfxImageSrc(m_dataMgr->getIconId(index)));
        }
        item->setQuality(VFX_RENDER_QUALITY_HIGH);
    #if defined(__MMI_FTE_SUPPORT_SLIM__)
        item->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_COLOR_KEY);
    #endif
        VcpSpaceBeamMenuUserData data;
        data.isOpacity = m_cellOpacity;
        data.camera = m_camera;
        data.rowCount = m_count;
        
        setCellUserData(cell, subcell, item, &data, sizeof(data));
        if (m_cellOpaque)
        {
            item->setIsOpaque(VFX_TRUE);
        }
        return item;
    }
    else
    {
        VfxS32 index = cell * VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW + subcell - VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW;

        VfxTextFrame  *item;
        VFX_OBJ_CREATE(item, VfxTextFrame, this);

        item->setBounds(0,0,VCP_FANCY_MODE_CELL_WIDTH, 30);
        item->setColor(VFX_COLOR_WHITE);
        item->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        item->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        item->setFont(VFX_FONT_DESC_SMALL);
        item->setCullingType(VFX_FRAME_CULLING_TYPE_BACK);
        item->setBgColor(VFX_COLOR_BLACK);
        item->setIsOpaque(VFX_TRUE);

        if (m_dataMgr->getTitle(index).isNull())
        {
            // empty cell
            item->setHidden(VFX_TRUE);
        }
        else
        {
            item->setString(m_dataMgr->getTitle(index));
        }
        
        VcpSpaceBeamMenuUserData data;
        data.isOpacity = m_cellOpacity;
        data.camera = m_camera;
        data.rowCount = m_count;
        
        setCellUserData(cell, subcell, item, &data, sizeof(data));
        return item;
    }
}
   

void VcpSpaceBeamMenu::onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame)
{
    VFX_UNUSED(cell);
    VFX_UNUSED(subcell);
    VFX_OBJ_CLOSE(cellFrame);
}
    

void VcpSpaceBeamMenu::onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem)
{
}


void VcpSpaceBeamMenu::onStateChangeFinished(VcpWheelMenuState finishedState)
{
    if (finishedState == VCP_WHEEL_MENU_ENTER_STATE)
    {
        m_signalEnterFinished.emit();
        setTextVisible(VFX_TRUE);
        setAllCellQuality(VFX_RENDER_QUALITY_HIGH);
    }
}


void VcpSpaceBeamMenu::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    VFX_UNUSED(xoffset);
    
    
    VfxFloat newIndex = getScrollIndex() + VfxFloat(yoffset) / VCP_FANCY_MODE_CELL_HEIGHT;
    
    if (newIndex > m_count - 1)
    {
        newIndex = m_count - 1;
    }
    
    setScrollIndex(newIndex, 0);
    if (yoffset != 0)
    {
        setTextVisible(VFX_FALSE);
    }
    VFX_OBJ_CLOSE(m_qualityTimer);
}


void VcpSpaceBeamMenu::setAllCellQuality(VfxRenderQualityEnum value)
{
    VfxS32 i,j;
    VfxFrame *temp;
    for (i = m_firstVisibleItem; i < m_lastVisibleItem; i++)
    {
        for (j = 0; j < VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW; j++)
        {
            temp = getCellIfPresent(i, j);
            temp->setQuality(value);
        }
    }
    // the first row should be nearest when move to edge.
    // otherwise, there are some shift between bilinear and nearest.
    if (getScrollIndex() <= 0)
    {
        i = m_firstVisibleItem;
        for (j = 0; j < VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW; j++)
        {
            temp = getCellIfPresent(i, j);
            temp->setQuality(VFX_RENDER_QUALITY_HIGH);
        }
    }
    else if (getFocus() == m_count - 1)
    {
        i = m_lastVisibleItem - 1;
        for (j = 0; j < VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW; j++)
        {
            temp = getCellIfPresent(i, j);
            temp->setQuality(VFX_RENDER_QUALITY_HIGH);
        }
    }
}


void VcpSpaceBeamMenu::onQualityTimerStop(VfxTimer *source)
{
    VFX_OBJ_CLOSE(m_qualityTimer);
    setAllCellQuality(VFX_RENDER_QUALITY_HIGH);
    setTextVisible(VFX_TRUE);
}


VfxBool VcpSpaceBeamMenu::onPenInput(VfxPenEvent & event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        m_isSwipe = VFX_FALSE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        VfxPoint dowmpt = event.getRelDownPos(this);
        VfxPoint pt     = event.getRelPos(this);
        if (VFX_ABS(pt.x - dowmpt.x) > 200 || VFX_ABS(pt.y - dowmpt.y) > 200)
        {
            m_isSwipe = VFX_TRUE;
        }
    }
    return VcpWheelMenu::onPenInput(event);
}


void VcpSpaceBeamMenu::onDragEnd(VfxS32 xspeed, VfxS32 yspeed)
{
    VFX_UNUSED(xspeed);
    VfxMsec duration = 300;

    VfxS32   s = yspeed > 0 ? 1 : -1;
    if (yspeed == 0) 
    {        
        if (getScrollIndex() > getFocus())
        {
            setFocus((VfxS32)vfxCeil(getScrollIndex()), duration);
        }
        else if (getScrollIndex() < getFocus())
        {
            setFocus((VfxS32)vfxFloor(getScrollIndex()), duration);
        }
        else
        {
            // getScrollIndex() == getFocus() do not set quality. 
            //return;
        }
    }
    else if (VFX_ABS(yspeed) < 320 || !m_isSwipe)
    {
        VfxS32 newFocus =  (VfxS32) (s < 0 ? vfxFloor : vfxCeil) (getScrollIndex());

        setFocus(newFocus, duration);
    }
    else
    {
        VfxFloat m = VFX_ABS(yspeed) / 66.6f;        
        if (m > m_count - 1) 
        {
            m = m_count - 1;
        }        
        duration = 800;
        setFocus(VfxS32(getScrollIndex() + s * m + 0.5f), duration);
    }
    if (m_textVisible == VFX_FALSE)
    {
        setAllCellQuality(VFX_RENDER_QUALITY_NORMAL);
        // start a timer to reset quality
        VFX_OBJ_CREATE(m_qualityTimer, VfxTimer, this);
        m_qualityTimer->m_signalTick.connect(this, &VcpSpaceBeamMenu::onQualityTimerStop);
        m_qualityTimer->setStartDelay(duration);
        m_qualityTimer->start();
    }
}


VfxBool VcpSpaceBeamMenu::hitTestonCell(VfxPoint pt, VfxS32 cell, VfxS32 subCell)
{
    VfxFrame* item = getCellIfPresent(cell, subCell);
    if (item)
    {
        VfxMatrix3x3Ex inv = VfxMatrix3x3Ex(item->forceGetTransform().data.matrix3x3);
        inv.inverse();

        VfxPoint point = inv.transform(pt);
        point = convertPointTo(point, item);
        if (item->getBounds().contains(point))
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

void VcpSpaceBeamMenu::onTap(VfxPoint pt)
{
    VfxS32 focusCell = getFocus();
    VfxS32 testCell;
   
    VfxS32 testSubCell;
    for (testCell = focusCell; testCell <= focusCell + VCP_SPACE_BEAM_MENU_BEHIND_COUNT; testCell++)
    {
        for (testSubCell = 0; testSubCell < VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW; testSubCell++)
        {
            if (hitTestonCell(pt, testCell, testSubCell))
            {
                m_signalSelected.emit(this, m_dataMgr->getIndex(testCell * VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW + testSubCell));
                return;
            }
        }
    }
}

void VcpSpaceBeamMenu::setTextVisible(VfxBool value)
{
    m_textVisible = value;
    if (value == VFX_TRUE)
    {
        VfxS32 i;
        VfxS32 testCell = getFocus();
        for (i = 0; i < VCP_SPACE_BEAM_MENU_TEXT_COUNT; i++)
        {
            if (getCellIfPresent(testCell, i))
            {
                m_text[i]->setString(m_dataMgr->getTitle(testCell * VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW + i));
                m_text[i]->setOpacity(1.0f);
            }
            else
            {
                m_text[i]->setOpacity(0);
            }
        }
    }
    else
    {
        VfxS32 i;
        for (i = 0; i < VCP_SPACE_BEAM_MENU_TEXT_COUNT; i++)
        {
            m_text[i]->setOpacity(0);
        }
    }
}


#ifdef __MTK_TARGET__
#pragma arm
#endif

vrt_render_dirty_type_enum VcpSpaceBeamMenu::myFrameEffectCB(
    VfxS32                              cell,           // [IN] the cell index
    VfxS32                              subCell,        // [IN] the sub cell index
    VfxFloat                            cellRelPos,     // [IN] the cell position
    vrt_frame_visual_property_struct    *target_frame,  // [IN] the cell frame
    VfxFloat                            fPos,           // [IN] animating index value
    VfxS32                              focus,          // the focus value of the menu
    VfxRect                             viewBounds,     // the menu bounds
    void                                *userData,      // user data
    VfxU32                              userDataSize,   // user data size
    VcpWheelMenuState                   state,          // [IN] the state of Menu
    VfxFloat                            level           // [IN] the level of state
)
{
    VFX_UNUSED(focus);
    VFX_UNUSED(userDataSize);
    VFX_DEV_ASSERT(target_frame != NULL);

    VFX_DEV_ASSERT(userDataSize == sizeof(VcpSpaceBeamMenuUserData));
    VcpSpaceBeamMenuUserData* data = (VcpSpaceBeamMenuUserData*)userData;

    VfxFloat offset;

    if (state == VCP_WHEEL_MENU_NORMAL_STATE)
    {
        offset = cellRelPos;
    }
    else if (state == VCP_WHEEL_MENU_ENTER_STATE)
    {
        if (cellRelPos < VCP_SPACE_BEAM_MENU_BEHIND_COUNT)
        {
            offset = level * (cellRelPos - VCP_SPACE_BEAM_MENU_BEHIND_COUNT) + VCP_SPACE_BEAM_MENU_BEHIND_COUNT;
        }
        else
        {
            offset = cellRelPos;
        }
    }
    else // if (state == VCP_WHEEL_MENU_LEAVE_STATE)
    {
        if (cellRelPos < VCP_SPACE_BEAM_MENU_BEHIND_COUNT)
        {
            offset = (1 - level) * (cellRelPos - VCP_SPACE_BEAM_MENU_BEHIND_COUNT) + VCP_SPACE_BEAM_MENU_BEHIND_COUNT;
        }
        else
        {
            offset = cellRelPos;
        }
    }
    
    VfxMatrix4x4 totalProject;
    VfxMatrix4x4 cameraView;
    VfxMatrix4x4 modelView;
    VfxMatrix4x4 RT;
    
    cameraView = data->camera;
    
    // set Model View :
    // The model view matirx decides the origin and direction of model.
    // We set the origin of each item to the center of item.
    // So we need to apply a negative translate. 
#if defined(__MMI_MAINLCD_320X480__)
    if (subCell == 0)
    {
        modelView.setTranslation((VfxFloat)((-1 * (VCP_FANCY_MODE_CELL_WIDTH * 2 + VCP_SPACE_BEAM_MENU_GAP * 3 /2))), 
                        (VfxFloat)(-1 * VCP_FANCY_MODE_CELL_HEIGHT/2), 
                        0);
    }
    else if (subCell == 1)
    {
        modelView.setTranslation((VfxFloat)((-1 * (VCP_FANCY_MODE_CELL_WIDTH  + VCP_SPACE_BEAM_MENU_GAP/2))), 
                        (VfxFloat)(-1 * VCP_FANCY_MODE_CELL_HEIGHT/2), 
                        0);
    }
    else if (subCell == 2)
    {
        modelView.setTranslation((VfxFloat)((VCP_SPACE_BEAM_MENU_GAP/2)), 
                        (VfxFloat)(-1 * VCP_FANCY_MODE_CELL_HEIGHT/2), 
                        0);
    }
    else if (subCell == 3)
    {
        modelView.setTranslation((VfxFloat)((VCP_FANCY_MODE_CELL_WIDTH + VCP_SPACE_BEAM_MENU_GAP*3/2)), 
                        (VfxFloat)(-1 * VCP_FANCY_MODE_CELL_HEIGHT/2), 
                        0);
    }
    else if (subCell == 4)
    {
        modelView.setTranslation((VfxFloat)((-1 * (VCP_FANCY_MODE_CELL_WIDTH * 2 + VCP_SPACE_BEAM_MENU_GAP * 3 /2))), 
                        (VfxFloat)(VCP_FANCY_MODE_CELL_HEIGHT/2), 
                        0);
    }
    else if (subCell == 5)
    {
        modelView.setTranslation((VfxFloat)((-1 * (VCP_FANCY_MODE_CELL_WIDTH  + VCP_SPACE_BEAM_MENU_GAP/2))), 
                        (VfxFloat)(VCP_FANCY_MODE_CELL_HEIGHT/2), 
                        0);
    }
    else if (subCell == 6)
    {
        modelView.setTranslation((VfxFloat)((VCP_SPACE_BEAM_MENU_GAP/2)), 
                        (VfxFloat)(VCP_FANCY_MODE_CELL_HEIGHT/2), 
                        0);
    }
    else if (subCell == 7)
    {
        modelView.setTranslation((VfxFloat)((VCP_FANCY_MODE_CELL_WIDTH + VCP_SPACE_BEAM_MENU_GAP*3/2)), 
                        (VfxFloat)(VCP_FANCY_MODE_CELL_HEIGHT/2), 
                        0);
    }

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    if (subCell == 0)
    {
        modelView.setTranslation((VfxFloat)((-1 * (VCP_FANCY_MODE_CELL_WIDTH * 3/2 + VCP_SPACE_BEAM_MENU_GAP))), 
                        (VfxFloat)(-1 * VCP_FANCY_MODE_CELL_HEIGHT/2), 
                        0);
    }
    else if (subCell == 1)
    {
        modelView.setTranslation((VfxFloat)((-1 * (VCP_FANCY_MODE_CELL_WIDTH / 2))), 
                        (VfxFloat)(-1 * VCP_FANCY_MODE_CELL_HEIGHT/2), 
                        0);
    }
    else if (subCell == 2)
    {
        modelView.setTranslation((VfxFloat)((VCP_FANCY_MODE_CELL_WIDTH/2 + VCP_SPACE_BEAM_MENU_GAP)), 
                        (VfxFloat)(-1 * VCP_FANCY_MODE_CELL_HEIGHT/2), 
                        0);
    }
#else
    if (subCell == 0)
    {
        modelView.setTranslation((VfxFloat)((-1 * (VCP_FANCY_MODE_CELL_WIDTH * 2 + VCP_SPACE_BEAM_MENU_GAP * 3 /2))), 
                        (VfxFloat)(-1 * VCP_FANCY_MODE_CELL_HEIGHT/2), 
                        0);
    }
    else if (subCell == 1)
    {
        modelView.setTranslation((VfxFloat)((-1 * (VCP_FANCY_MODE_CELL_WIDTH  + VCP_SPACE_BEAM_MENU_GAP/2))), 
                        (VfxFloat)(-1 * VCP_FANCY_MODE_CELL_HEIGHT/2), 
                        0);
    }
    else if (subCell == 2)
    {
        modelView.setTranslation((VfxFloat)((VCP_SPACE_BEAM_MENU_GAP/2)), 
                        (VfxFloat)(-1 * VCP_FANCY_MODE_CELL_HEIGHT/2), 
                        0);
    }
    else if (subCell == 3)
    {
        modelView.setTranslation((VfxFloat)((VCP_FANCY_MODE_CELL_WIDTH + VCP_SPACE_BEAM_MENU_GAP*3/2)), 
                        (VfxFloat)(-1 * VCP_FANCY_MODE_CELL_HEIGHT/2), 
                        0);
    }
#endif

    if (fPos < 0)
    {
        // spring effect when fPos is negative
        if (cell == 0)
        {
            RT.m[14] = 0;
        }
        else
        {
            RT.m[14] = VCP_SPACE_BEAM_MENU_Z_GAP * (cell - fPos * cell * 0.2);
        }
    }
    else if (fPos >= data->rowCount - 1 && state == VCP_WHEEL_MENU_NORMAL_STATE)
    {
        // stop scroll when last row.
        if (cell == data->rowCount - 1)
        {
            RT.m[14] = 0 ;
        }
    }
    else
    {
        // normal case
        RT.m[14] = VCP_SPACE_BEAM_MENU_Z_GAP * offset;
    }
    
    // Now we multiply cameraView, RT and modelview to get totalProject. 
    //totalProject = cameraView * RT * modelView;
    // Set as 3x3 matrix for VRT rendering.
    //target_frame->transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3; 
    //totalProject.initMatrix3x3(target_frame->transform.data.matrix3x3);

    // optimize above code
    target_frame->transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3; 
    target_frame->transform.data.matrix3x3.m[0] = 1;
    target_frame->transform.data.matrix3x3.m[3] = 0;
    target_frame->transform.data.matrix3x3.m[6] = modelView.m[12] + cameraView.m[8] * RT.m[14] + cameraView.m[12];
    target_frame->transform.data.matrix3x3.m[1] = 0;
    target_frame->transform.data.matrix3x3.m[4] = 1.0f;
    target_frame->transform.data.matrix3x3.m[7] = modelView.m[13] + RT.m[13] + cameraView.m[9] * RT.m[14] + cameraView.m[13];
    target_frame->transform.data.matrix3x3.m[2] = 0;
    target_frame->transform.data.matrix3x3.m[5] = 0;
    target_frame->transform.data.matrix3x3.m[8] = cameraView.m[11] * RT.m[14] + cameraView.m[15];

    target_frame->pos_z = RT.m[14];
    
    if (offset > VCP_SPACE_BEAM_MENU_BEHIND_COUNT)
    {
        target_frame->opacity = 1.0f - (offset - VCP_SPACE_BEAM_MENU_BEHIND_COUNT);
        if (target_frame->opacity < 0)
        {
            target_frame->opacity = 0;
        }    
    }
    else if (offset < -1 * VCP_SPACE_BEAM_MENU_AHEAD_COUNT)
    {
        target_frame->opacity = 1.0f - (-1 * VCP_SPACE_BEAM_MENU_AHEAD_COUNT - offset);
        if (target_frame->opacity < 0)
        {
            target_frame->opacity = 0;
        }
    }
    else
    {   
        if (state == VCP_WHEEL_MENU_LEAVE_STATE)
        {
            if (level < 0.5)
            {
                target_frame->opacity = 1.0f;
            }
            else
            {
                target_frame->opacity = 1.0f - 2 * (level - 0.5);
            }
        }
        else
        {
            if (data->isOpacity)
            {
                if (offset == 0)
                {
                    target_frame->opacity = 1;
                   
                }
                else
                {
                    target_frame->opacity = 0.5f;
                }
            }
            else
            {
                target_frame->opacity = 1;
            }
        }
    }
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}


#ifdef __MTK_TARGET__
#pragma thumb
#endif

void VcpSpaceBeamMenu::enter()
{
    configureStatePara(VCP_WHEEL_MENU_ENTER_STATE, 500, 250, VCP_WHEEL_MENU_ALL_TOGETHER);
    changeState(VCP_WHEEL_MENU_ENTER_STATE);
}

void VcpSpaceBeamMenu::leave()
{
    configureStatePara(VCP_WHEEL_MENU_LEAVE_STATE, 500, 250, VCP_WHEEL_MENU_ALL_TOGETHER);
    changeState(VCP_WHEEL_MENU_LEAVE_STATE);

    // do not trigger qualityTimer time out when leave
    VFX_OBJ_CLOSE(m_qualityTimer);
    
    // Artist want to inVisible immediately
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    setTextVisible(VFX_FALSE);
    VfxAutoAnimate::commit();
}


/***************************************************************************** 
 * Class VcpFancyModeMenu
 *****************************************************************************/
VcpFancyModeMenu::VcpFancyModeMenu() :
    m_tornadoMenu(NULL),
    m_spaceBeamMenu(NULL),
    m_transition(NULL),
    m_dataMgr(NULL),
    m_allAppData(NULL),
    m_allAppCount(0),
    m_appOrder(NULL),
    m_orderCount(0),
    m_pageCount(0),
    m_focusedIndex(0),
    m_type(VCP_FANCY_MODE_MENU_NULL),
    m_timer(NULL),
    m_focus(-1),
    m_isAnim(VFX_FALSE)
{}


void VcpFancyModeMenu::onInit()
{
    VfxControl::onInit();
}


void VcpFancyModeMenu::setAllAppData(AppEntry appEntry[], VfxS32 count)
{
    m_allAppData = appEntry;
    m_allAppCount = count;
}


void VcpFancyModeMenu::enter(VcpFancyModeMenuType type, VfxS32 appOrder[], VfxS32 orderCount, VfxS32 pageCount, VfxS32 focusedIndex, VfxBool isAnim)
{
    m_type = type;
    m_appOrder = appOrder;
    m_orderCount = orderCount;
    m_pageCount = pageCount;
    m_focusedIndex = focusedIndex;
    m_isAnim = isAnim;

    if (isAnim)
    {
        VFX_OBJ_CREATE(m_transition, VcpFancyModeMenuTransition, this);

        VcpFancyModeDataMgr *dataMgr;
        VFX_OBJ_CREATE(dataMgr, VcpFancyModeDataMgr, m_transition);
        dataMgr->setBlankMode(VCP_FANCY_MODE_DATA_MGR_PAGE);
        dataMgr->setPageCount(m_pageCount);

        dataMgr->setAllAppData(m_allAppData, m_allAppCount);
        dataMgr->setAppOrderData(m_appOrder, m_orderCount);
        
        m_transition->setDataMgr(dataMgr);
        m_transition->setFocusIndex(dataMgr->getFocusedIndex(m_focusedIndex));
        
        m_transition->setBounds(getBounds());
        m_transition->m_signalTransitionFinished.connect(this, &VcpFancyModeMenu::onTransitionFinished);
        switch (m_type)
        {
            case VCP_FANCY_MODE_MENU_TORNADO: 
            {
                m_transition->switchToTornado(VFX_FALSE);
                break;
            }
            case VCP_FANCY_MODE_MENU_SPACE_BEAM:
            {     
                m_transition->switchToSpaceBeam(VFX_FALSE);
                break;
            }
            default:
                VFX_ASSERT(0);
        }
    }
    else
    {
        // call on TransitionFinished immedately
        onTransitionFinished();
    }
   
}


void VcpFancyModeMenu::leave()
{
    
    switch (m_type)
    {
        case VCP_FANCY_MODE_MENU_TORNADO:
            m_tornadoMenu->leave();
            break;
        case VCP_FANCY_MODE_MENU_SPACE_BEAM:
            m_spaceBeamMenu->leave();
            break;
        default:
            VFX_ASSERT(0);
    }
    
    // delay timer
    VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    m_timer->m_signalTick.connect(this, &VcpFancyModeMenu::onTimerStop);
    m_timer->setStartDelay(500);
    m_timer->start();
}


void VcpFancyModeMenu::onTransitionFinished()
{
    VFX_OBJ_CLOSE(m_transition);
    switch (m_type)
    {
        case VCP_FANCY_MODE_MENU_TORNADO: 
        {       
            VFX_OBJ_CREATE(m_tornadoMenu, VcpTornadoMenu, this);

            VcpFancyModeDataMgr *dataMgr;
            VFX_OBJ_CREATE(dataMgr, VcpFancyModeDataMgr, m_tornadoMenu);

            dataMgr->setBlankMode(VCP_FANCY_MODE_DATA_MGR_NONE);
            dataMgr->setPageCount(m_pageCount);

            dataMgr->setAllAppData(m_allAppData, m_allAppCount);
            dataMgr->setAppOrderData(m_appOrder, m_orderCount);
            m_tornadoMenu->setDataMgr(dataMgr);

            m_tornadoMenu->setPos(VfxPoint(0, 0));
            m_tornadoMenu->setBounds(getBounds());
            m_tornadoMenu->setFocused(VFX_TRUE);
            m_tornadoMenu->setCount(m_allAppCount);

            if (m_focus == -1)
            {
                // defalut value
                m_tornadoMenu->setFocus(VCP_TORNADO_MENU_AHEAD_COUNT);
            }
            else
            {
                m_tornadoMenu->setFocus(m_focus);
            }
            if (m_isAnim)
            {
                m_tornadoMenu->enter();
            }
            else
            {
                // help notify m_tornadoMenu show text
                m_tornadoMenu->setTextVisible(VFX_TRUE);
                m_tornadoMenu->setAllCellQuality(VFX_RENDER_QUALITY_HIGH);
            }
            m_tornadoMenu->m_signalSelected.connect(this, &VcpFancyModeMenu::onUserSelected);
            m_tornadoMenu->m_signalEnterFinished.connect(this, &VcpFancyModeMenu::onEnterFinished);
            break;
        }
        case VCP_FANCY_MODE_MENU_SPACE_BEAM:
        {
            VFX_OBJ_CREATE(m_spaceBeamMenu, VcpSpaceBeamMenu, this);

            VcpFancyModeDataMgr *dataMgr;
            VFX_OBJ_CREATE(dataMgr, VcpFancyModeDataMgr, m_spaceBeamMenu);
            dataMgr->setBlankMode(VCP_FANCY_MODE_DATA_MGR_NONE);
            dataMgr->setPageCount(m_pageCount);

            dataMgr->setAllAppData(m_allAppData, m_allAppCount);
            dataMgr->setAppOrderData(m_appOrder, m_orderCount);
            m_spaceBeamMenu->setDataMgr(dataMgr);

            m_spaceBeamMenu->setPos(VfxPoint(0, 0));
            m_spaceBeamMenu->setBounds(getBounds());
            m_spaceBeamMenu->setFocused(VFX_TRUE);
            m_spaceBeamMenu->setCountOfRow(dataMgr->getTotalCount());
            if (m_focus == -1)
            {
                // defalut value
                m_spaceBeamMenu->setFocusIndex(0);
            }
            else
            {
                // beacuse m_focus is wheel menu focus
                m_spaceBeamMenu->setFocus(m_focus);
            }
            
            if (m_isAnim)
            {
                m_spaceBeamMenu->enter();
            }
            else
            {
                // help notify m_tornadoMenu show text
                m_spaceBeamMenu->setTextVisible(VFX_TRUE);
                m_spaceBeamMenu->setAllCellQuality(VFX_RENDER_QUALITY_HIGH);
            }
            m_spaceBeamMenu->m_signalSelected.connect(this, &VcpFancyModeMenu::onUserSelected);
            m_spaceBeamMenu->m_signalEnterFinished.connect(this, &VcpFancyModeMenu::onEnterFinished);
            break;
        }
        default :
            VFX_ASSERT(0);
    }
}

void VcpFancyModeMenu::onTransitionFinished2()
{
    VFX_OBJ_CLOSE(m_transition);
    m_signalLeaveFinished.emit();
}


void VcpFancyModeMenu::onEnterFinished()
{
    m_signalEnterFinished.emit();
}


void VcpFancyModeMenu::onUserSelected(VfxObject *menu, VfxS32 index)
{
    VFX_UNUSED(menu);
    m_appClicked.emit(index);
}


void VcpFancyModeMenu::onTimerStop(VfxTimer *source)
{
    VFX_OBJ_CLOSE(source);

    VFX_OBJ_CREATE(m_transition, VcpFancyModeMenuTransition, this);

    VcpFancyModeDataMgr *dataMgr;
    VFX_OBJ_CREATE(dataMgr, VcpFancyModeDataMgr, m_transition);
    
    dataMgr->setBlankMode(VCP_FANCY_MODE_DATA_MGR_PAGE);
    dataMgr->setPageCount(m_pageCount);

    dataMgr->setAllAppData(m_allAppData, m_allAppCount);
    dataMgr->setAppOrderData(m_appOrder, m_orderCount);
    
    m_transition->setDataMgr(dataMgr);
    m_transition->setFocusIndex(dataMgr->getFocusedIndex(m_focusedIndex));
    
    m_transition->setBounds(getBounds());
    m_transition->m_signalTransitionFinished.connect(this, &VcpFancyModeMenu::onTransitionFinished2);

    switch (m_type)
    {
        case VCP_FANCY_MODE_MENU_TORNADO: 
        {   
            VFX_OBJ_CLOSE(m_tornadoMenu);
            m_transition->switchToTornado(VFX_TRUE);
            break;
        }
        case VCP_FANCY_MODE_MENU_SPACE_BEAM:
        {   
            VFX_OBJ_CLOSE(m_spaceBeamMenu);
            m_transition->switchToSpaceBeam(VFX_TRUE);
            break;
        }
        default:
            VFX_ASSERT(0);
    }
    
}


VfxS32 VcpFancyModeMenu::getFocus()
{
    switch (m_type)
    {
        case VCP_FANCY_MODE_MENU_TORNADO: 
        {   
            return m_tornadoMenu->getFocus();
        }
        case VCP_FANCY_MODE_MENU_SPACE_BEAM:
        {   
            return m_spaceBeamMenu->getFocus();
        }
        default:
            VFX_ASSERT(0);
    }
}

#endif /* __MMI_VUI_3D_MAINMENU_FANCY__ */

