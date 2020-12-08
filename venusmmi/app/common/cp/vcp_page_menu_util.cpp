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
 *  vcp_page_menu_util.cpp
 *
 * Project:
 * --------
 *  3D Main Menu
 *
 * Description:
 * ------------
 *  3D Main Menu
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_3D_MAINMENU__) || defined(__COSMOS_MMI__) || defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_LAUNCHER_KEY__)

#include "MMI_include.h"       // for rand()

#include "vfx_uc_include.h"
#include "vcp_page_menu_util.h"
#include "vfx_datatype.h"
#include "vfx_transform.h"
#include "vfx_cpp_base.h"
#include "vfx_control.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_frame.h"
#include "vfx_image_src.h"
#include "vfx_input_event.h"
#include "vfx_basic_type.h"
#include "vfx_signal.h"
#include "kal_public_api.h"
#include "vrt_datatype.h"
#include "kal_general_types.h"
#include "vfx_animation.h"
#include "vfx_auto_animate.h"
#include "vcp_page_menu_transition.h"

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif // __MTK_TARGET__

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif

/*****************************************************************************
 * Define
 *****************************************************************************/
#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_VUI_LAUNCHER__)|| defined(__MMI_VUI_LAUNCHER_KEY__)
#define COSMOS_MAINMENU_SHRINK_EFFECT
#endif

/*****************************************************************************
 * Global Variable
 *****************************************************************************/

// mainmenu layout constants

// cell layout

static const VfxS32 MAINMENU_PAGE_ROW_COUNT_DEFAULT = 4;
static const VfxS32 MAINMENU_PAGE_COLUMN_COUNT_DEFAULT = 4;

static const VfxS32 MAINMENU_CELL_START_X_DEFAULT = 9;
static const VfxS32 MAINMENU_CELL_START_Y_DEFAULT = 11;

static const VfxS32 MAINMENU_CELL_OFFSET_X_DEFAULT = 65+11;
static const VfxS32 MAINMENU_CELL_OFFSET_Y_DEFAULT = 65+2+20+5;

static const VfxS32 MAINMENU_PAGE_MARGIN_DEFAULT = 20;


// cell content layout default
static const VfxS32 MAINMENU_CELL_ICON_WIDTH_DEFAULT = 65;
static const VfxS32 MAINMENU_CELL_ICON_HEIGHT_DEFAULT = 65;

// misc
static const VfxS32 MAINMENU_CLIP_MARGIN_DEFAULT = 65;

static const VfxFloat MAINMENU_ROTATION_LIMIT = 15.0f;
static const VfxFloat MAINMENU_BOUND_ROTATION_LIMIT = 30.0f;

static const VfxS32 MAINMENU_TRANSITIONING_THRESHOLD = 1;

static const VfxS32 MAINMENU_ANIMTIME_INSTANT = 1;

static const VfxFloat MAINMENU_EDITING_ALPHA = 0.5f;

static const VfxFloat MAINMENU_DRAGGING_SCALE = 1.3f;

static const VfxFloat MAINMENU_CLICK_SCALE = 1.0f;

static const VfxS32 MAINMENU_ORGANIZE_DURATION = 250;


// page indicator layout constants

static const VfxS32 MAINMENU_INDICATOR_CELL_WIDTH_DEFAULT = 32;
static const VfxS32 MAINMENU_INDICATOR_HEIGHT_DEFAULT = 26;
static const VfxS32 MAINMENU_INDICATOR_BACKGROUND_HEIGHT_DEFAULT = 10;
static const VfxS32 MAINMENU_INDICATOR_BACKGROUND_OFFSET_Y_DEFAULT = 8;
static const VfxS32 MAINMENU_INDICATOR_CELL_VISIBLE_WIDTH_DEFAULT = 24;
static const VfxS32 MAINMENU_INDICATOR_CELL_VISIBLE_HEIGHT_DEFAULT = 4;

static const VfxS32 MAINMENU_INDICATOR_CELL_VISIBLE_OFFSET_X_DEFAULT = 0;
static const VfxS32 MAINMENU_INDICATOR_CELL_VISIBLE_OFFSET_Y_DEFAULT = 0;

// group constants
static const VfxS32 MAINMENU_CELL_BAR_START_Y_DEFAULT = 0;

static const VfxS32 MAINMENU_CELL_BOTTOM_BAR_OFFSET_Y_DEFAULT = -1;
static const VfxS32 MAINMENU_CELL_BOTTOM_BAR_SHIFT_Y_DEFAULT = 0;

// For folder
static const VfxFloat MAINMENU_CELL_HIT_TEST_MARGIN_FACTOR = 0.3f;


/*****************************************************************************
 * Animation structures
 *****************************************************************************/

struct VcpPageMenuAnimStruct
{
    VfxMatrix4x4 * transform;
    VcpRotatePageView * menuView;
    VcpPageMenuCell * cell;
};

struct VcpPageMenuTranslateTimelineStruct
{
    VfxFloat     * currentTranslate;
	VfxBool      * instantTranslate;
};

struct VcpPageMenuRotateTimelineStruct
{
    VfxMatrix4x4 * camera;
    VfxMatrix4x4 * transform;
    VfxFloat     * currentRotation;
    VfxBool        rotateReset;
};

struct VcpPageMenuScaleTimelineStruct
{
    VfxMatrix4x4 * scaleTransform;
    VcpRotatePageView * menuView;
};

/*****************************************************************************
 * Class VcpPageMenuIndicatorLayout Implementation
 *****************************************************************************/
VcpPageMenuIndicatorLayout::VcpPageMenuIndicatorLayout():
indicatorWidthBase(0),
indicatorWidthIncrement(MAINMENU_INDICATOR_CELL_WIDTH_DEFAULT),
indicatorHeight(MAINMENU_INDICATOR_HEIGHT_DEFAULT),
bgOffsetY(MAINMENU_INDICATOR_BACKGROUND_OFFSET_Y_DEFAULT),
bgHeight(MAINMENU_INDICATOR_BACKGROUND_HEIGHT_DEFAULT),
cellSpacing(MAINMENU_INDICATOR_CELL_WIDTH_DEFAULT),
cellOffsetX(MAINMENU_INDICATOR_CELL_VISIBLE_OFFSET_X_DEFAULT),
cellOffsetY(MAINMENU_INDICATOR_CELL_VISIBLE_OFFSET_Y_DEFAULT),
cellWidth(MAINMENU_INDICATOR_CELL_VISIBLE_WIDTH_DEFAULT),
cellHeight(MAINMENU_INDICATOR_CELL_VISIBLE_HEIGHT_DEFAULT),
cellHighlightWidth(-1),
cellHighlightHeight(-1)
{
}

/*****************************************************************************
 * Class VcpPageMenuIndicator Implementation
 *****************************************************************************/

void VcpPageMenuIndicator::onInit()
{
    Super::onInit();

    vcpPageMenuApplyFrameRenderHints(this);
    VFX_OBJ_CREATE(m_background, VfxFrame, this);
    vcpPageMenuApplyFrameRenderHints(m_background);

    m_background->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    VFX_OBJ_CREATE(m_highlight, VfxFrame, this);
    vcpPageMenuApplyFrameRenderHints(m_highlight);
    m_highlight->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
#ifndef MAINMENU_NO_INDICATOR_TRANSFORMATION_ANIMATION
    m_highlight->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_easeOut, VfxFrame, this);
    vcpPageMenuApplyFrameRenderHints(m_easeOut);
    m_easeOut->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_easeOut->setAutoAnimate(VFX_TRUE);
#endif
}

VfxBool VcpPageMenuIndicator::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN || event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        VfxPoint touchPos = event.getRelPos(this);
        VfxS32 index = getTouchPageIndex(touchPos);
        m_pageSelected.postEmit(index);
        return VFX_TRUE;
    }
    return Super::onPenInput(event);
}

VcpPageMenuIndicator::VcpPageMenuIndicator():
    m_pageCount(0),
    m_currentPage(0),
    m_highlight(NULL),
#ifndef MAINMENU_NO_INDICATOR_TRANSFORMATION_ANIMATION
    m_easeOut(NULL),
#endif
    m_background(NULL),
    m_cellHighlightImgCount(1)
{
    for (VfxS32 i = 0; i < VCP_PAGE_MENU_INDICATOR_MAX_PAGE_COUNT; ++i)
    {
        m_indicators[i] = NULL;
    }
}

VfxS32 VcpPageMenuIndicator::getCurrentPage()
{
    VFX_ASSERT(m_currentPage < VCP_PAGE_MENU_INDICATOR_MAX_PAGE_COUNT);
    return m_currentPage;
}

void VcpPageMenuIndicator::setCurrentPage(VfxS32 currentPage)
{
    VFX_ASSERT(currentPage < VCP_PAGE_MENU_INDICATOR_MAX_PAGE_COUNT);
    m_currentPage = currentPage;
}

VfxS32 VcpPageMenuIndicator::getIndicatorPageCount()
{
    VFX_ASSERT(m_pageCount <= VCP_PAGE_MENU_INDICATOR_MAX_PAGE_COUNT);
    return m_pageCount;
}

void VcpPageMenuIndicator::setIndicatorPageCount(VfxS32 pageCount)
{
    VFX_ASSERT(pageCount <= VCP_PAGE_MENU_INDICATOR_MAX_PAGE_COUNT);
    m_pageCount = pageCount;
}

void VcpPageMenuIndicator::update()
{
    setSize(m_layout.indicatorWidthBase + m_pageCount * m_layout.indicatorWidthIncrement, m_layout.indicatorHeight);
    m_background->setPos(0, m_layout.bgOffsetY);
    m_background->setSize(m_layout.indicatorWidthBase + m_pageCount * m_layout.indicatorWidthIncrement, m_layout.bgHeight);

    for (VfxS32 i = 0; i < VCP_PAGE_MENU_INDICATOR_MAX_PAGE_COUNT; ++i)
    {
        if (i < m_pageCount)
        {
            if (m_indicators[i] == NULL)
            {
                VFX_OBJ_CREATE(m_indicators[i], VfxFrame, this);
                vcpPageMenuApplyFrameRenderHints(m_indicators[i]);
                m_indicators[i]->setAnchor(0.5f, 0.5f);
                m_indicators[i]->setSize(m_layout.cellWidth, m_layout.cellHeight);
                m_indicators[i]->setImgContent(m_cellNormal);
                m_indicators[i]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
            #ifndef MAINMENU_NO_INDICATOR_TRANSFORMATION_ANIMATION
                m_indicators[i]->setAutoAnimate(VFX_TRUE);
            #endif
                insertChildFrameBefore(m_highlight, m_indicators[i]);
            }
            
        #ifndef MAINMENU_NO_INDICATOR_TRANSFORMATION_ANIMATION
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        #endif
            
            m_indicators[i]->setPos(getIndicatorPos(i));
            if (i == m_currentPage)
            {
                m_indicators[i]->setOpacity(0.0f);
            }
            else
            {
                m_indicators[i]->setOpacity(1.0f);
            }
            
        #ifndef MAINMENU_NO_INDICATOR_TRANSFORMATION_ANIMATION
            VfxAutoAnimate::commit();
        #endif
        }
        else
        {
            VFX_OBJ_CLOSE(m_indicators[i] );
        }
    }

    if (m_layout.cellHighlightWidth == -1 || m_layout.cellHighlightHeight == -1)
    {
        m_layout.cellHighlightWidth = m_layout.cellWidth;
        m_layout.cellHighlightHeight = m_layout.cellHeight;
    }

    if (m_cellHighlightImgCount > 1)
    {
        m_highlight->setImgContent(VfxImageSrc(m_cellHighlight.getResId() + VFX_MIN(m_currentPage, m_cellHighlightImgCount - 1)));
    }
    else
    {
        m_highlight->setImgContent(m_cellHighlight);
    }
    m_highlight->setAnchor(0.5f, 0.5f);
    m_highlight->setSize(m_layout.cellHighlightWidth, m_layout.cellHighlightHeight);

#ifndef MAINMENU_NO_INDICATOR_TRANSFORMATION_ANIMATION
    m_easeOut->setImgContent(m_cellNormal);
    m_easeOut->setAnchor(0.5f, 0.5f);
    m_easeOut->setSize(m_layout.cellHighlightWidth, m_layout.cellHighlightHeight);
#endif
    // highlight cell handling
    VfxPoint oldPos = m_highlight->getPos();
    VfxPoint newPos = getIndicatorPos(m_currentPage);
    if (oldPos != newPos)
    {
    #ifdef MAINMENU_NO_INDICATOR_TRANSFORMATION_ANIMATION
        m_highlight->setPos(newPos);
    #else
        VfxTransform trans;
        if (m_layout.cellWidth == m_layout.cellHighlightWidth &&
                m_layout.cellHeight == m_layout.cellHighlightHeight)
        {
            trans.setIdentity();
        }
        else
        {
            trans.init(VRT_TRANSFORM_TYPE_AFFINE);
            VfxFloat widthScale = VfxFloat(m_layout.cellWidth) / VfxFloat(m_layout.cellHighlightWidth);
            VfxFloat heightScale = VfxFloat(m_layout.cellHeight) / VfxFloat(m_layout.cellHighlightHeight);
            trans.data.affine.sx = widthScale;
            trans.data.affine.sy = heightScale;
        }

        // Init before the animation.
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);

        m_easeOut->setPos(oldPos);
        m_highlight->setPos(newPos);

        m_highlight->setTransform(trans);
        m_highlight->setOpacity(0.0f);
        m_easeOut->setTransform(VFX_TRANSFORM_IDENTITY);
        m_easeOut->setOpacity(1.0f);

        VfxAutoAnimate::commit();

        // Animate them.
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        //VfxAutoAnimate::setDuration(5000);

        m_highlight->setTransform(VFX_TRANSFORM_IDENTITY);
        m_highlight->setOpacity(1.0f);
        m_easeOut->setTransform(trans);
        m_easeOut->setOpacity(0.0f);

        VfxAutoAnimate::commit();
    #endif
    }
}

VfxPoint VcpPageMenuIndicator::getIndicatorPos(VfxS32 i) const
{
    const VfxS32 cellShiftX = (m_layout.indicatorWidthBase + m_pageCount * m_layout.indicatorWidthIncrement - m_pageCount * m_layout.cellSpacing) / 2;
    VfxPoint pos;
    pos.x = cellShiftX + i * m_layout.cellSpacing + m_layout.cellOffsetX + m_layout.cellSpacing / 2;
    pos.y = m_layout.bgOffsetY + m_layout.cellOffsetY + m_layout.bgHeight / 2;
    return pos;
}

VfxS32 VcpPageMenuIndicator::getTouchPageIndex(VfxPoint pos)
{
    const VfxS32 cellShiftX = (m_layout.indicatorWidthBase + m_pageCount * m_layout.indicatorWidthIncrement - m_pageCount * m_layout.cellSpacing) / 2;
    VfxS32 index = (pos.x - cellShiftX) / m_layout.cellSpacing;

    if (index < 0)
    {
        index = 0;
    }
    if (index >= m_pageCount)
    {
        index = m_pageCount - 1;
    }
    return index;
}

void VcpPageMenuIndicator::setBgImage(VfxImageSrc bgImage)
{
    m_background->setImgContent(bgImage);
}

void VcpPageMenuIndicator::setCellImage(VfxImageSrc cellNormal, VfxImageSrc cellHighlight, VfxS32 cellHighlightImgCount)
{
    m_cellNormal = cellNormal;
    m_cellHighlight = cellHighlight;
    m_cellHighlightImgCount = cellHighlightImgCount;
//    update();
}

void VcpPageMenuIndicator::setLayout(const VcpPageMenuIndicatorLayout layout)
{
    m_layout = layout;
    if (m_layout.cellHighlightWidth == -1)
    {
        m_layout.cellHighlightWidth = m_layout.cellWidth;
    }
    if (m_layout.cellHighlightHeight == -1)
    {
        m_layout.cellHighlightHeight = m_layout.cellHeight;
    }
}

VcpPageMenuIndicatorLayout VcpPageMenuIndicator::getLayout() const
{
    return m_layout;
}

/*****************************************************************************
 * Class VcpPageMenuCell Implementation
 *****************************************************************************/

VcpPageMenuCell::VcpPageMenuCell():
    m_fpePropertyFrame(NULL),
    m_needSetExactPos(VFX_FALSE),
    m_cellGroup(-1),
    m_cellIndex(-1)
{
}

void VcpPageMenuCell::setCellIndex(VfxS32 index)
{
    m_cellIndex = index;
}

VfxS32 VcpPageMenuCell::getCellIndex() const
{
    return m_cellIndex;
}

void VcpPageMenuCell::setCellGroup(VfxS32 group)
{
    m_cellGroup = group;
}

VfxS32 VcpPageMenuCell::getCellGroup() const
{
    return m_cellGroup;
}

void VcpPageMenuCell::setCellPosY(VfxS32 posY)
{
    m_fpePropertyFrame->setPos(m_fpePropertyFrame->getPos().x, posY);
}

VfxS32 VcpPageMenuCell::getCellPosY() const
{
    return m_fpePropertyFrame->getPos().y;
}

VfxS32 VcpPageMenuCell::forceGetCellPosY() const
{
    return m_fpePropertyFrame->forceGetPos().y;
}

void VcpPageMenuCell::setCellScale(VfxFloat scale)
{
    m_fpePropertyFrame->setFpeUser0(scale);
}

VfxFloat VcpPageMenuCell::getCellScale() const
{
    return m_fpePropertyFrame->getFpeUser0();
}

VfxFloat VcpPageMenuCell::forceGetCellScale() const
{
    return m_fpePropertyFrame->forceGetFpeUser0();
}

void VcpPageMenuCell::setNeedSetExactPos(VfxBool needSetExactPos)
{
    m_needSetExactPos = needSetExactPos;
}

VfxBool VcpPageMenuCell::getNeedSetExactPos() const
{
    return m_needSetExactPos;
}

void VcpPageMenuCell::onCellDisplay()
{
}

void VcpPageMenuCell::onInit()
{
    VfxFrame::onInit();
    
    VFX_OBJ_CREATE(m_fpePropertyFrame, VfxFrame, this);
    m_fpePropertyFrame->setAutoAnimate(VFX_TRUE);
    m_fpePropertyFrame->setHidden(VFX_TRUE);
    m_fpePropertyFrame->setFpeUser0(1.0f);
}


/*****************************************************************************
 * Class VcpPageMenuLayout Implementation
 *****************************************************************************/

VcpPageMenuLayout::VcpPageMenuLayout():
    rowCount(MAINMENU_PAGE_ROW_COUNT_DEFAULT),
    columnCount(MAINMENU_PAGE_COLUMN_COUNT_DEFAULT),
    cellStartX(MAINMENU_CELL_START_X_DEFAULT),
    cellStartY(MAINMENU_CELL_START_Y_DEFAULT),
    cellOffsetX(MAINMENU_CELL_OFFSET_X_DEFAULT),
    cellOffsetY(MAINMENU_CELL_OFFSET_Y_DEFAULT),
    rowCountInFolderIcon(0),
    columnCountInFolderIcon(0),
    cellInFolderIconStartX(0),
    cellInFolderIconStartY(0),
    cellInFolderIconOffsetX(0),
    cellInFolderIconOffsetY(0),
    cellInFolderIconScale(1.0f),
    pageMargin(MAINMENU_PAGE_MARGIN_DEFAULT),
    bottomBarOffsetY(MAINMENU_CELL_BOTTOM_BAR_OFFSET_Y_DEFAULT),
    bottomBarVisibleShiftY(MAINMENU_CELL_BOTTOM_BAR_SHIFT_Y_DEFAULT)
{
}


/*****************************************************************************
 * Class VcpPageMenuFolderEditorLayout
 *****************************************************************************/

VcpPageMenuFolderEditorLayout::VcpPageMenuFolderEditorLayout():
    folderEditorPosX(0),
    folderEditorPosY(0),
    folderEditorWidth(0),
    folderEditorHeight(0),
    folderEditorMainShiftY(0),
    rowCountInFolderEditor(0),
    columnCountInFolderEditor(0),
    cellInFolderEditorStartX(0),
    cellInFolderEditorStartY(0),
    cellInFolderEditorOffsetX(0),
    cellInFolderEditorOffsetY(0)
{
}

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
#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
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
 * Class VcpRotatePageView Implementation
 *****************************************************************************/

VcpRotatePageView::VcpRotatePageView():
    m_width(0),
    m_height(0),
    m_cellIconSize(MAINMENU_CELL_ICON_WIDTH_DEFAULT, MAINMENU_CELL_ICON_HEIGHT_DEFAULT),
    m_draggingFrame(NULL),
    m_scaleFrame(NULL),
    m_animDirtyEndTime(0),
    m_organizeMode(VFX_FALSE),
    m_isUninstalling(VFX_FALSE),
    m_isEnterNCenter(VFX_FALSE),
    m_folderState(VCP_PAGE_MENU_NOT_FOLDER_MODE),
    m_tempCellInFolderIconOriginalPosX(0),
    m_tempCellInFolderIconOriginalPosY(0),
    m_currentRotation(0.0f),
    m_currentTranslate(0.0f),
	m_instantTranslate(VFX_FALSE),
#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
    m_transition(NULL),
    m_direction(0),
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
    m_translateXTimeline(NULL),
    m_rotateTimeline(NULL),
    m_scaleTimeline(NULL),
    m_shakeTransformTimeline(NULL),
    m_shakeTransfromTimelineBottom(NULL),
    m_shakeTransfromTimelineFolder(NULL)
{
    for (VfxS32 i = 0; i < VCP_PAGE_MENU_GROUP_SIZE; ++i)
    {
        m_animDummyFrame[i] = NULL;
    }
}

void VcpRotatePageView::onInit()
{
    VfxObject::onInit();

    for (VfxS32 i = 0; i < VCP_PAGE_MENU_GROUP_SIZE; ++i)
    {
        VFX_OBJ_CREATE(m_animDummyFrame[i], VfxFrame, this);
        getAnimDummyFrame(i)->setSize(1, 1);
        getAnimDummyFrame(i)->setBgColor(VFX_COLOR_RED);
        getAnimDummyFrame(i)->setOpacity(0);
        getAnimDummyFrame(i)->setAutoAnimate(VFX_TRUE);
        getAnimDummyFrame(i)->setFilterTiming(0.0f);
    }

    // add dummy frame to first parent which is a frame
    VfxObject * cursor = this;
    while (cursor)
    {
        cursor = cursor->getParent();
        if (cursor == NULL)
        {
            break;
        }
        VfxFrame * frame = VFX_OBJ_DYNAMIC_CAST(cursor, VfxFrame);
        if (frame != NULL)
        {
            for (VfxS32 i = 0; i < VCP_PAGE_MENU_GROUP_SIZE; ++i)
            {
                frame->addChildFrame(getAnimDummyFrame(i) );
            }
            break;
        }
    }

    VFX_OBJ_CREATE(m_scaleTimeline, VfxFloatTimeline, this);
    m_scaleTimeline->setToValue(1.0f);
    VFX_OBJ_CREATE(m_rotateTimeline, VfxFloatTimeline, this);
    // x = 0: rotate, y = 1: scale
    getAnimDummyFrame(VCP_PAGE_MENU_GROUP_MAIN)->setAnchor(0.0f, 1.0f);
    
    VFX_OBJ_CREATE(m_translateXTimeline, VfxS32Timeline, this);
    
    VFX_OBJ_CREATE(m_shakeTransformTimeline, VfxTransformTimeline, this);
    getAnimDummyFrame(VCP_PAGE_MENU_GROUP_MAIN)->setTransform(VfxTransform());
    VFX_OBJ_CREATE(m_shakeTransfromTimelineBottom,VfxTransformTimeline,this);    
    VFX_OBJ_CREATE(m_shakeTransfromTimelineFolder,VfxTransformTimeline,this);    
}

void VcpRotatePageView::onDeinit()
{
#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
    VFX_OBJ_CLOSE(m_transition);
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
    VfxObject::onDeinit();
}

void VcpRotatePageView::setSize(VfxS32 width, VfxS32 height)
{
    m_width = width;
    m_height = height;
    setCameraPara();
    m_transform = m_camera;
}

void VcpRotatePageView::setCellIconSize(const VfxSize & size)
{
    m_cellIconSize = size;
}

VfxS32 VcpRotatePageView::getWidth() const
{
    return m_width;
}

VfxS32 VcpRotatePageView::getHeight() const
{
    return m_height;
}

void VcpRotatePageView::setCameraPara()
{
    m_camera.setCamera(
                1.0f,
                1.0f,
                VfxFloat(m_width / 2),
                VfxFloat(m_height / 2),
                VfxFloat(240.0f),
                VfxFloat(240.0f),
                VfxFloat(0.0f),
                VfxFloat(0.0f),
                VfxFloat(0.0f) );
}

void VcpRotatePageView::initCellAnim(VcpPageMenuCell * cell, VfxS32 group)
{
    // set fpe for this cell
    VcpPageMenuAnimStruct animStruct;
    animStruct.transform = &m_transform;
    animStruct.menuView = this;
    animStruct.cell = cell;

    cell->setCellGroup(group);

    cell->setPropertyEffectCallback(
        getAnimDummyFrame(group),
        VcpRotatePageView::framePropertyEffectCallback,
        &animStruct,
        sizeof(animStruct) );
}

void VcpRotatePageView::setLayout(const VcpPageMenuLayout & layout)
{
    m_layout = layout;
}

void VcpRotatePageView::reset()
{
    setScaleFrame(NULL);
}

void VcpRotatePageView::setOrganizeMode(VfxBool organizeMode)
{
    m_organizeMode = organizeMode;
}

void VcpRotatePageView::setIsUninstalling(VfxBool isUninstalling)
{
    m_isUninstalling = isUninstalling;
}

void VcpRotatePageView::setIsEnterNCenter(VfxBool isEnterNCenter)
{
    m_isEnterNCenter = isEnterNCenter;
}

#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
void VcpRotatePageView::setTransitionEffect(VcpPageMenuTransitionType transitionType)
{
    VcpPageMenuTransition * toClose = m_transition;
    m_transition = vcpPageMenuCreateTransition(transitionType, this);
    if (m_transition)
    {
        m_transition->onInitTransition(m_layout, m_width, m_height);
    }
    VFX_OBJ_CLOSE(toClose);
}

void VcpRotatePageView::setTransitionDirection(VfxS32 direction)
{
    m_direction = direction;
}
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__

void VcpRotatePageView::changeCellGroup(VcpPageMenuCell * cell, VfxS32 newGroup)
{
    if (cell == NULL)
    {
        return;
    }
    
    if ((cell->getCellGroup() == VCP_PAGE_MENU_GROUP_MAIN ||
         cell->getCellGroup() == VCP_PAGE_MENU_GROUP_BOTTOM_BAR) &&
        newGroup == VCP_PAGE_MENU_GROUP_FOLDER_ICON_TEMP)
    {
        m_tempCellInFolderIconOriginalPosX = getCellPosX(cell);
        m_tempCellInFolderIconOriginalPosY = getCellPosY(cell);
        
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        setCellPosX(cell, 0);
        setCellPosY(cell, 0);
        setCellScale(cell, 1.0f);
        VfxAutoAnimate::commit();
    }
    else if (cell->getCellGroup() == VCP_PAGE_MENU_GROUP_FOLDER_ICON_TEMP &&
             (newGroup == VCP_PAGE_MENU_GROUP_MAIN ||
              newGroup == VCP_PAGE_MENU_GROUP_BOTTOM_BAR))
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        setCellPosX(cell, m_tempCellInFolderIconOriginalPosX);
        setCellPosY(cell, m_tempCellInFolderIconOriginalPosY);
        VfxAutoAnimate::commit();
        
        VfxAutoAnimate::begin();
        setCellScale(cell, 1.0f);
        VfxAutoAnimate::commit();
    }
    else if ((cell->getCellGroup() == VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON && newGroup == VCP_PAGE_MENU_GROUP_MAIN) ||
             (cell->getCellGroup() == VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON && newGroup == VCP_PAGE_MENU_GROUP_BOTTOM_BAR))
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        setCellPosX(cell, m_tempCellInFolderIconOriginalPosX + getCellPosX(cell));
        setCellPosY(cell, m_tempCellInFolderIconOriginalPosY + getCellPosY(cell));
        VfxAutoAnimate::commit();
        
        VfxAutoAnimate::begin();
        setCellScale(cell, 1.0f);
        VfxAutoAnimate::commit();
    }
    else if ((cell->getCellGroup() == VCP_PAGE_MENU_GROUP_SCREEN && newGroup == VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON) ||
             (cell->getCellGroup() == VCP_PAGE_MENU_GROUP_SCREEN && newGroup == VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON))
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        setCellPosX(cell, 0);
        setCellPosY(cell, 0);
        setCellScale(cell, 1.0f);
        VfxAutoAnimate::commit();
    }
    else
    {
        VfxS32 oldTranslateX = getCurrentTranslateXInt(cell->getCellGroup() );
        VfxS32 newTranslateX = getCurrentTranslateXInt(newGroup);
        VfxS32 oldPosX = getCellPosX(cell);
        VfxS32 newPosX = oldPosX + oldTranslateX - newTranslateX;
        
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        setCellPosX(cell, newPosX);
        VfxAutoAnimate::commit();
    }

    initCellAnim(cell, newGroup);
}

vrt_render_dirty_type_enum VcpRotatePageView::framePropertyEffectCallback(
    vrt_frame_visual_property_struct *target_frame,
    const vrt_frame_visual_property_struct *watch_frame,
    void *user_data,
    vrt_u32 user_data_size)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MFP", SA_start);
#endif

    const VcpPageMenuAnimStruct *animStruct = (const VcpPageMenuAnimStruct *)user_data;
    vrt_render_dirty_type_enum ret;

    if (animStruct->cell->getCellGroup() == VCP_PAGE_MENU_GROUP_MAIN)
    {
        ret = fpeMainGroup(target_frame, watch_frame, user_data, user_data_size);
        
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MFP", SA_stop);
    #endif
    
        return ret;
    }
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_LAUNCHER_KEY__)
    else if (animStruct->cell->getCellGroup() == VCP_PAGE_MENU_GROUP_SCREEN)
    {
	    target_frame->anchor_point.x = 0;
	    target_frame->anchor_point.y = 0;
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }
#endif

#if defined(__MMI_VUI_LAUNCHER_KEY__)
    else if (animStruct->cell->getCellGroup() == VCP_PAGE_MENU_GROUP_ANIM)
	{
		VFX_TRANSFORM_IDENTITY.initVrtTransform(target_frame->transform);
	    target_frame->anchor_point.x = 0;
	    target_frame->anchor_point.y = 0;
		return VRT_RENDER_DIRTY_TYPE_NONE;
    }
#endif
    else if (animStruct->cell->getCellGroup() == VCP_PAGE_MENU_GROUP_FOLDER_ICON_TEMP)
    {
        ret = fpeFolderIconTempGroup(target_frame, watch_frame, user_data, user_data_size);
        
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MFP", SA_stop);
    #endif
    
        return ret;
    }
    else if (animStruct->cell->getCellGroup() == VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON ||
             animStruct->cell->getCellGroup() == VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON)
    {
        ret = fpeFolderIconGroup(target_frame, watch_frame, user_data, user_data_size);
        
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MFP", SA_stop);
    #endif
    
        return ret;
    }
    else
    {
        ret = fpeOtherGroup(target_frame, watch_frame, user_data, user_data_size);
        
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MFP", SA_stop);
    #endif
    
        return ret;
    }

}

void VcpRotatePageView::framePropertyReset(vrt_frame_visual_property_struct *target_frame)
{
    target_frame->pos_z = 100.0f;
    target_frame->opacity = 1.0f;
    framePropertyResetInt(target_frame);
}

void VcpRotatePageView::framePropertyResetInt(vrt_frame_visual_property_struct *target_frame)
{
    target_frame->anchor_point.x = 0.0f;
    target_frame->anchor_point.y = 0.0f;
    target_frame->transform.type = VRT_TRANSFORM_TYPE_IDENTITY;
    target_frame->transform.data.affine.sx = 1.0f;
    target_frame->transform.data.affine.sy = 1.0f;
    target_frame->transform.data.affine.rz = 0.0f;
    target_frame->transform.data.affine.tx = 0.0f;
    target_frame->transform.data.affine.ty = 0.0f;
}

vrt_render_dirty_type_enum VcpRotatePageView::fpeMainGroup(
    vrt_frame_visual_property_struct *target_frame,
    const vrt_frame_visual_property_struct *watch_frame,
    void *user_data,
    vrt_u32 user_data_size)
{
    const VcpPageMenuAnimStruct *animStruct = (const VcpPageMenuAnimStruct *)user_data;
    const VfxFloat translate = animStruct->menuView->m_currentTranslate;
    const VfxFloat xPos = target_frame->fpe_user_0 + translate;
    const vrt_s32 yPos = animStruct->cell->forceGetCellPosY();

    const VfxTransform shakeTransform = animStruct->menuView->getCurrentShakeTransform();
    framePropertyResetInt(target_frame);

#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
    VcpPageMenuTransition * transition = animStruct->menuView->m_transition;

    if (transition != NULL &&
        !animStruct->menuView->m_organizeMode &&
        animStruct->menuView->m_folderState == VCP_PAGE_MENU_NOT_FOLDER_MODE)
    {
        framePropertyReset(target_frame);
        
        const VfxS32 mainmenuWidth = animStruct->menuView->m_width;
        const VfxS32 mainmenuHeight = animStruct->menuView->m_height;
        const vrt_s32 translate = animStruct->menuView->m_currentTranslate;
        const vrt_s32 rawPosX = static_cast<vrt_s32>(target_frame->fpe_user_0);
        const VcpPageMenuLayout & layout = animStruct->menuView->m_layout;
        const VfxS32 level = mainmenuWidth + layout.pageMargin;
        VfxS32 pageStart = rawPosX / level * level;
        vrt_float t = vrt_float(pageStart + translate) / level;

        if (t <= -1.0f || t >= 1.0f)
        {
            if (target_frame->transform.type == VRT_TRANSFORM_TYPE_IDENTITY &&
                target_frame->pos.x == -10000 &&
                target_frame->pos.y == -10000)
            {
                return VRT_RENDER_DIRTY_TYPE_NONE;
            }
            else
            {
                target_frame->transform.type = VRT_TRANSFORM_TYPE_IDENTITY;
                target_frame->pos.x = -10000;
                target_frame->pos.y = -10000;
                return VRT_RENDER_DIRTY_TYPE_DIRTY;
            }
        }
        VfxS32 indexY = (yPos - layout.cellStartY) / layout.cellOffsetY;
        VfxS32 indexX = (rawPosX - pageStart - layout.cellStartX) / layout.cellOffsetX;
        VfxS32 direction = animStruct->menuView->m_direction;

        return transition->onTransition(t, direction, indexX, indexY, layout, mainmenuWidth, mainmenuHeight, target_frame);
    }
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__

#if defined(__MMI_FTE_SUPPORT_SLIM__)
    VfxFloat rotation = 0.0f;
#else
    VfxFloat rotation = animStruct->menuView->m_currentRotation;
#endif

    const VfxS32 mainmenuWidth = animStruct->menuView->m_width;
    VfxS32 xMaxMargin = mainmenuWidth;
    VfxS32 xMinMargin = -animStruct->menuView->m_cellIconSize.width;
    if (VFX_ABS(rotation) < 0.1f)
    {
    }
    else if (rotation > 0.0f)
    {
        xMinMargin -= MAINMENU_CLIP_MARGIN_DEFAULT * static_cast<VfxS32>(rotation+1) / static_cast<VfxS32>(MAINMENU_ROTATION_LIMIT);
    }
    else
    {
        xMaxMargin += MAINMENU_CLIP_MARGIN_DEFAULT * static_cast<VfxS32>(-rotation+1) / static_cast<VfxS32>(MAINMENU_ROTATION_LIMIT);
    }

    // try to hide the frames that are not in the visible range
    if (xPos > xMaxMargin || xPos < xMinMargin)
    {
        target_frame->transform.type = VRT_TRANSFORM_TYPE_IDENTITY;
        target_frame->pos.x = -10000;
        target_frame->pos.y = -10000;
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }

    target_frame->pos_z = 100.0f;
    VfxBool needScale = VFX_FALSE;
    if (animStruct->cell == animStruct->menuView->getScaleFrame() && animStruct->menuView->m_scaleTransform.m[0] != 1.0f)
    {
        needScale = VFX_TRUE;
    }
    VfxFloat individualScale = animStruct->cell->forceGetCellScale();
    if (individualScale != 1.0f)
    {
        needScale = VFX_TRUE;
    }

#ifdef COSMOS_MAINMENU_SHRINK_EFFECT
    // removed shrink effect

    if (!needScale)
    {
        if (animStruct->menuView->m_organizeMode &&
            animStruct->menuView->m_folderState != VCP_PAGE_MENU_FIRST_FOLDER_MODE &&
            animStruct->menuView->m_folderState != VCP_PAGE_MENU_FOLDER_MODE &&
            animStruct->menuView->m_isUninstalling != VFX_TRUE &&
            animStruct->menuView->m_isEnterNCenter != VFX_TRUE &&
            shakeTransform.data.affine.rz != 0.0f)
        {
            VfxFloat tmpRandOffset = (rand() % 10) / 200.0f;
			VfxFloat tmpAnchorOffset = (rand() % 5) / 10.0f;

			target_frame->transform.type = VRT_TRANSFORM_TYPE_AFFINE;
            target_frame->pos.x = xPos + target_frame->bounds.size.width / 2;
            target_frame->pos.y = yPos + target_frame->bounds.size.height / 2;
            target_frame->transform.data.affine.rz = shakeTransform.data.affine.rz + tmpRandOffset;
            target_frame->anchor_point.x = 0.5f + (rand() % 3) / 200.0f;
            target_frame->anchor_point.y = 0.5f + (rand() % 3) / 100.0f;
            
            return VRT_RENDER_DIRTY_TYPE_DIRTY;
        }
        else if (target_frame->transform.type == VRT_TRANSFORM_TYPE_IDENTITY &&
                xPos == target_frame->pos.x && yPos == target_frame->pos.y)
        {
            return VRT_RENDER_DIRTY_TYPE_NONE;
        }
        else
        {
            target_frame->transform.type = VRT_TRANSFORM_TYPE_IDENTITY;
            target_frame->pos.x = xPos;
            target_frame->pos.y = yPos;
            return VRT_RENDER_DIRTY_TYPE_DIRTY;
        }
    }
    else
    {
        target_frame->pos.x = 0;
        target_frame->pos.y = 0;
        VfxMatrix4x4 model, totalProject;
        model.setTranslation(xPos - animStruct->menuView->m_width / 2,
                yPos - animStruct->menuView->m_height / 2, 0);

        if (animStruct->cell == animStruct->menuView->getScaleFrame() && animStruct->menuView->m_scaleTransform.m[0] != 1.0f)
        {
            totalProject = *(animStruct->transform) * model * animStruct->menuView->m_scaleTransform;
        }
        if (individualScale != 1.0f)
        {
            target_frame->pos.x = xPos;
            target_frame->pos.y = yPos;
            
            VfxMatrix4x4 individualScaleMatrix;
            individualScaleMatrix.setScale(individualScale, individualScale, 0.0f);
            totalProject = individualScaleMatrix;
        }

        VfxTransform tempTransform;
        totalProject.initMatrix3x3(tempTransform.data.matrix3x3);
        tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

        tempTransform.initVrtTransform(target_frame->transform);

        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }

#else // COSMOS_MAINMENU_SHRINK_EFFECT
    if (VFX_ABS(rotation) < 0.1f && !needScale)
    {
        if (target_frame->transform.type == VRT_TRANSFORM_TYPE_IDENTITY &&
                xPos == target_frame->pos.x && yPos == target_frame->pos.y)
        {
            return VRT_RENDER_DIRTY_TYPE_NONE;
        }
        else
        {
            target_frame->transform.type = VRT_TRANSFORM_TYPE_IDENTITY;
            target_frame->pos.x = xPos;
            target_frame->pos.y = yPos;
            return VRT_RENDER_DIRTY_TYPE_DIRTY;
        }
    }
    else
    {
        target_frame->pos.x = 0;
        target_frame->pos.y = 0;
        VfxMatrix4x4 model, totalProject;
        model.setTranslation(target_frame->fpe_user_0 + translate - animStruct->menuView->m_width / 2,
                static_cast<vrt_float>(yPos) - animStruct->menuView->m_height / 2, 0);

        if (animStruct->cell == animStruct->menuView->getScaleFrame() )
        {
            totalProject = *(animStruct->transform) * model * animStruct->menuView->m_scaleTransform;
        }
        else {
            totalProject = *(animStruct->transform) * model;
        }

        VfxTransform tempTransform;
        totalProject.initMatrix3x3(tempTransform.data.matrix3x3);
        tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

        tempTransform.initVrtTransform(target_frame->transform);

        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }
#endif // COSMOS_MAINMENU_SHRINK_EFFECT
}

vrt_render_dirty_type_enum VcpRotatePageView::fpeOtherGroup(
    vrt_frame_visual_property_struct *target_frame,
    const vrt_frame_visual_property_struct *watch_frame,
    void *user_data,
    vrt_u32 user_data_size)
{
    const VcpPageMenuAnimStruct *animStruct = (const VcpPageMenuAnimStruct *)user_data;
    const VfxFloat translate = watch_frame->pos.x;
    VfxFloat xPos;
    if (animStruct->cell->getCellGroup() == VCP_PAGE_MENU_GROUP_SCREEN)
    {
        xPos = animStruct->menuView->getCellPosX(animStruct->cell) + translate;
    }
    else
    {
        xPos = target_frame->fpe_user_0 + translate;
    }
    const vrt_s32 yPos = animStruct->cell->forceGetCellPosY();
    
    const VfxTransform shakeTransform = animStruct->menuView->getCurrentShakeTransform();
	framePropertyResetInt(target_frame);
    
    const VfxS32 mainmenuWidth = animStruct->menuView->m_width;
    VfxS32 xMaxMargin = mainmenuWidth;
    VfxS32 xMinMargin = -animStruct->menuView->m_cellIconSize.width;

    // try to hide the frames that are not in the visible range
    if (xPos > xMaxMargin || xPos < xMinMargin)
    {
        target_frame->transform.type = VRT_TRANSFORM_TYPE_IDENTITY;
        target_frame->pos.x = -10000;
        target_frame->pos.y = -10000;
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }

    if (animStruct->cell == animStruct->menuView->getScaleFrame() )
    {
        target_frame->pos_z = -1000.0f;
    }
    else if (animStruct->cell->getCellGroup() == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
    {
        target_frame->pos_z = 200.0f;
    }
    else
    {
        target_frame->pos_z = -100.0f;
    }

    VfxBool needScale = VFX_FALSE;
    if (animStruct->cell == animStruct->menuView->getScaleFrame() && animStruct->menuView->m_scaleTransform.m[0] != 1.0f)
    {
        needScale = VFX_TRUE;
    }

    if (!needScale)
    {
        if (animStruct->menuView->m_organizeMode &&
            (animStruct->cell->getCellGroup() == VCP_PAGE_MENU_GROUP_FOLDER_EDITOR ||
             (animStruct->cell->getCellGroup() == VCP_PAGE_MENU_GROUP_BOTTOM_BAR &&
              animStruct->menuView->m_folderState != VCP_PAGE_MENU_FIRST_FOLDER_MODE &&
              animStruct->menuView->m_folderState != VCP_PAGE_MENU_FOLDER_MODE)) &&
            animStruct->menuView->m_isUninstalling != VFX_TRUE &&
            animStruct->menuView->m_isEnterNCenter != VFX_TRUE &&
            shakeTransform.data.affine.rz != 0.0f)
        {
            VfxFloat tmpRandOffset = (rand() % 10) / 200.0f;
			VfxFloat tmpAnchorOffset = (rand() % 5) / 10.0f;

			target_frame->transform.type = VRT_TRANSFORM_TYPE_AFFINE;
            target_frame->pos.x = xPos + target_frame->bounds.size.width / 2;
            target_frame->pos.y = yPos + target_frame->bounds.size.height / 2;
            target_frame->transform.data.affine.rz = shakeTransform.data.affine.rz + tmpRandOffset;
            target_frame->anchor_point.x = 0.5f + (rand() % 3) / 200.0f;
            target_frame->anchor_point.y = 0.5f + (rand() % 3) / 100.0f;
            
            return VRT_RENDER_DIRTY_TYPE_DIRTY;
        }
        else if (target_frame->transform.type == VRT_TRANSFORM_TYPE_IDENTITY &&
                xPos == target_frame->pos.x && yPos == target_frame->pos.y)
        {
            return VRT_RENDER_DIRTY_TYPE_NONE;
        }
        else
        {
            target_frame->transform.type = VRT_TRANSFORM_TYPE_IDENTITY;
            target_frame->pos.x = xPos;
            target_frame->pos.y = yPos;
            return VRT_RENDER_DIRTY_TYPE_DIRTY;
        }
    }
    else
    {
        target_frame->pos.x = 0;
        target_frame->pos.y = 0;
        VfxMatrix4x4 model, totalProject;
        model.setTranslation(xPos, yPos, 0);

        if (animStruct->cell == animStruct->menuView->getScaleFrame() )
        {
            totalProject = model * animStruct->menuView->m_scaleTransform;
        }
        else {
            totalProject = model;
        }

        VfxTransform tempTransform;
        totalProject.initMatrix3x3(tempTransform.data.matrix3x3);
        tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

        tempTransform.initVrtTransform(target_frame->transform);

        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }
}

vrt_render_dirty_type_enum VcpRotatePageView::fpeFolderIconTempGroup(
    vrt_frame_visual_property_struct *target_frame,
    const vrt_frame_visual_property_struct *watch_frame,
    void *user_data,
    vrt_u32 user_data_size)
{
    const VcpPageMenuAnimStruct *animStruct = (const VcpPageMenuAnimStruct *)user_data;
    target_frame->pos.x = target_frame->fpe_user_0;
    target_frame->pos.y = animStruct->cell->forceGetCellPosY();
    if (target_frame->pos.x != 0 && target_frame->pos.y != 0)
    {
        target_frame->pos.x += animStruct->menuView->getCurrentTranslateX();
    }
    framePropertyResetInt(target_frame);
    
    return VRT_RENDER_DIRTY_TYPE_NONE;
}

vrt_render_dirty_type_enum VcpRotatePageView::fpeFolderIconGroup(
    vrt_frame_visual_property_struct *target_frame,
    const vrt_frame_visual_property_struct *watch_frame,
    void *user_data,
    vrt_u32 user_data_size)
{
    const VcpPageMenuAnimStruct *animStruct = (const VcpPageMenuAnimStruct *)user_data;
    const VfxFloat translate = watch_frame->pos.x;
    const VfxFloat xPos = target_frame->fpe_user_0 + translate;
    const vrt_s32 yPos = animStruct->cell->forceGetCellPosY();
    
    target_frame->anchor_point.x = 0.0f;
    target_frame->anchor_point.y = 0.0f;
    
    VfxFloat scale = animStruct->cell->forceGetCellScale();
    if (target_frame->pos.x == xPos && target_frame->pos.y == yPos &&
        target_frame->transform.data.matrix3x3.m[0] == scale)
    {
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }
    else
    {
        target_frame->pos.x = xPos;
        target_frame->pos.y = yPos;
        
        VfxMatrix4x4 scaleMatrix;
        VfxTransform tempTransform;
        scaleMatrix.setScale(scale, scale, 0.0f);
        scaleMatrix.initMatrix3x3(tempTransform.data.matrix3x3);
        tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;
        tempTransform.initVrtTransform(target_frame->transform);
        
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }
}

VfxTimelineInterpolationRetEnum VcpRotatePageView::translateTimelineFunc(
    void *output,
    const void *fromValue,
    const void *toValue,
    VfxTypeIdEnum typeId,
    VfxFloat t,
    void *data,
    VfxU32 data_size)
{
    VcpPageMenuTranslateTimelineStruct *animStruct = (VcpPageMenuTranslateTimelineStruct *)data;
    const VfxS32 * fromS32 = (VfxS32*)fromValue;
    const VfxS32 * toS32 = (VfxS32*)toValue;
    VfxS32 interpolate;
    interpolate = (*fromS32) + t * (*toS32 - *fromS32);

    VfxS32 * outputS32 = (VfxS32*)output;
    *outputS32 = interpolate;
	if (!(*animStruct->instantTranslate) )
	{
	    *(animStruct->currentTranslate) = interpolate;
	}

    return VFX_TIMELINE_INTERPOLATION_RET_DONE;
}

VfxTimelineInterpolationRetEnum VcpRotatePageView::rotateTimelineFunc(
    void *output,
    const void *fromValue,
    const void *toValue,
    VfxTypeIdEnum typeId,
    VfxFloat t,
    void *data,
    VfxU32 data_size)
{
    VcpPageMenuRotateTimelineStruct *animStruct = (VcpPageMenuRotateTimelineStruct *)data;
    const VfxFloat * fromFloat = (VfxFloat*)fromValue;
    const VfxFloat * toFloat = (VfxFloat*)toValue;
    VfxFloat interpolate;
    if (animStruct->rotateReset)
    {
        if (t < 0.5f)
        {
            interpolate = (*fromFloat) + (*toFloat - *fromFloat) * vfxSin(t * VFX_PI);
        }
        else
        {
            interpolate = *toFloat * vfxSin(t * VFX_PI);
        }
    }
    else
    {
        interpolate = (*fromFloat) + (*toFloat - *fromFloat) * t;
    }

#ifndef COSMOS_MAINMENU_SHRINK_EFFECT
    VfxMatrix4x4 rotateByY;
    rotateByY.setRotateByY(VFX_DEG_TO_RAD(interpolate) );
    *(animStruct->transform) = *(animStruct->camera) * rotateByY;
#endif
    VfxFloat * outputFloat = (VfxFloat*)output;
    *outputFloat = interpolate;
    *(animStruct->currentRotation) = interpolate;

    return VFX_TIMELINE_INTERPOLATION_RET_DONE;
}

VfxTimelineInterpolationRetEnum VcpRotatePageView::scaleTimelineFunc(
    void *output,
    const void *fromValue,
    const void *toValue,
    VfxTypeIdEnum typeId,
    VfxFloat t,
    void *data,
    VfxU32 data_size)
{
    VcpPageMenuScaleTimelineStruct *animStruct = (VcpPageMenuScaleTimelineStruct *)data;
    const VfxFloat * fromFloat = (VfxFloat*)fromValue;
    const VfxFloat * toFloat = (VfxFloat*)toValue;
    const VfxFloat interpolate = (*fromFloat) + (*toFloat - *fromFloat) * t;

// [ 1 0 0 dx ] * [(1+sx)      0 0 0] * [1 0 0 -dx]  =  [(1+sx)      0 0 -dx*sx]
// [ 0 1 0 dy ]   [     0 (1+sy) 0 0]   [0 1 0 -dy]     [     0 (1+sy) 0 -dy*sy]
// [ 0 0 1  0 ]   [     0      0 1 0]   [0 0 1   0]     [     0      0 1      0]
// [ 0 0 0  1 ]   [     0      0 0 1]   [0 0 0   1]     [     0      0 0      1]
    VfxMatrix4x4 shiftScale;
    VfxFloat scaleMinusOne = interpolate - 1.0f;
    shiftScale.m[0] = interpolate;
    shiftScale.m[5] = interpolate;
    shiftScale.m[12] = (-animStruct->menuView->m_cellIconSize.width / 2) * scaleMinusOne;
    shiftScale.m[13] = (-animStruct->menuView->m_cellIconSize.height / 2) * scaleMinusOne;
    *(animStruct->scaleTransform) = shiftScale;

    VfxFloat * outputFloat = (VfxFloat*)output;
    *outputFloat = interpolate;

    return VFX_TIMELINE_INTERPOLATION_RET_DONE;
}

VfxFrame * VcpRotatePageView::getAnimDummyFrame(VfxS32 i) const
{
    return m_animDummyFrame[i];
}

VcpPageMenuCell * VcpRotatePageView::getDraggingFrame() const
{
    return m_draggingFrame;
}

void VcpRotatePageView::setDraggingFrame(VcpPageMenuCell * draggingFrame)
{
    if (m_draggingFrame != NULL)
    {
        //changeCellGroup(m_draggingFrame, VCP_PAGE_MENU_GROUP_MAIN);
    }

    m_draggingFrame = draggingFrame;
    if (m_draggingFrame != NULL)
    {
        setScaleFrame(m_draggingFrame);
        changeCellGroup(m_draggingFrame, VCP_PAGE_MENU_GROUP_SCREEN);
        m_draggingFrame->bringToFront();
    }
}

VcpPageMenuCell * VcpRotatePageView::getScaleFrame() const
{
    return m_scaleFrame;
}

void VcpRotatePageView::setScaleFrame(VcpPageMenuCell * scaleFrame)
{
    m_scaleFrame = scaleFrame;
}

void VcpRotatePageView::updateScale(VfxS32 duration, VfxFloat targetScale)
{
    if (m_scaleTimeline->getToValue() == targetScale)
    {
        return;
    }

    m_scaleTimeline->setTarget(getAnimDummyFrame(VCP_PAGE_MENU_GROUP_MAIN) );
    m_scaleTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_ANCHOR_POINT_Y);
    m_scaleTimeline->setDurationTime(duration);
    m_scaleTimeline->setRepeatCount(1);
    m_scaleTimeline->setIsFromCurrent(VFX_TRUE);
    m_scaleTimeline->setToValue(targetScale);
    m_scaleTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);

    VcpPageMenuScaleTimelineStruct animStruct;
    animStruct.scaleTransform = &m_scaleTransform;
    animStruct.menuView = this;
    m_scaleTimeline->setCustomInterpolateFunc(&VcpRotatePageView::scaleTimelineFunc,&animStruct,sizeof(animStruct) );
    m_scaleTimeline->start();
}

void VcpRotatePageView::updateRotation(VfxS32 duration, VfxFloat rotateAngle, VfxBool rotateReset)
{
    // use anchor point x to store the rotation data
    m_rotateTimeline->setTarget(getAnimDummyFrame(VCP_PAGE_MENU_GROUP_MAIN) );
    m_rotateTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_ANCHOR_POINT_X);
    m_rotateTimeline->setDurationTime(duration);
    m_rotateTimeline->setRepeatCount(1);
    m_rotateTimeline->setIsFromCurrent(VFX_TRUE);
    m_rotateTimeline->setToValue(rotateAngle);
    m_rotateTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    VcpPageMenuRotateTimelineStruct animStruct;
    animStruct.camera = &m_camera;
    animStruct.transform = &m_transform;
    animStruct.currentRotation = &m_currentRotation;
    animStruct.rotateReset = rotateReset;
    m_rotateTimeline->setCustomInterpolateFunc(&VcpRotatePageView::rotateTimelineFunc,&animStruct,sizeof(animStruct) );
    m_rotateTimeline->start();
}

void VcpRotatePageView::updateTranslateX(VfxS32 duration, VfxFloat translate)
{
    if (duration > 1)
    {
        // fpe user 0 change would not dirty, set dirty manually
        setAnimDirty(duration);

        // use fpe user 0 to store the translation data
        m_translateXTimeline->setTarget(getAnimDummyFrame(VCP_PAGE_MENU_GROUP_MAIN) );
        m_translateXTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
        m_translateXTimeline->setDurationTime(duration);
        m_translateXTimeline->setRepeatCount(1);
        m_translateXTimeline->setIsFromCurrent(VFX_FALSE);
        m_translateXTimeline->setFromValue(m_currentTranslate);
        m_translateXTimeline->setToValue(translate);
        m_translateXTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        VcpPageMenuTranslateTimelineStruct animStruct;
        animStruct.currentTranslate = &m_currentTranslate;
        animStruct.instantTranslate = &m_instantTranslate;
		m_instantTranslate = VFX_FALSE;
        m_translateXTimeline->setCustomInterpolateFunc(&VcpRotatePageView::translateTimelineFunc,&animStruct,sizeof(animStruct) );
        m_translateXTimeline->start();
    }
}

void VcpRotatePageView::updateTranslateXInstant(VfxFloat translate)
{
    m_translateXTimeline->stop();
    m_currentTranslate = translate;
	m_instantTranslate = VFX_TRUE;
    getAnimDummyFrame(VCP_PAGE_MENU_GROUP_MAIN)->setContentDirty();
}

void VcpRotatePageView::updateShakeTransform(VfxBool isOrganizeMode)
{
    if (isOrganizeMode)
    {
        if (!m_shakeTransformTimeline->getIsEnabled())
        {
            // trigger animation for main group
			initShakeTransformTimeline(m_shakeTransformTimeline, VCP_PAGE_MENU_GROUP_MAIN);

            // trigger animation for bottom bar group
			initShakeTransformTimeline(m_shakeTransfromTimelineBottom, VCP_PAGE_MENU_GROUP_BOTTOM_BAR);

            // trigger animation for folder editor group
			initShakeTransformTimeline(m_shakeTransfromTimelineFolder, VCP_PAGE_MENU_GROUP_FOLDER_EDITOR);
        }
    }
    else
    {
        m_shakeTransformTimeline->stop();
        m_shakeTransfromTimelineBottom->stop();
        m_shakeTransfromTimelineFolder->stop();
    }
}

void VcpRotatePageView::initShakeTransformTimeline(VfxTransformTimeline *shakeTransformTimeline, VfxS32 type)
{
	VfxTransform tempTransformBegin;
	tempTransformBegin.type = VFX_TRANSFORM_TYPE_AFFINE;
	tempTransformBegin.data.affine.rz = VFX_DEG_TO_RAD(-3);
	
	VfxTransform tempTransformTo;
	tempTransformTo.type = VFX_TRANSFORM_TYPE_AFFINE;
	tempTransformTo.data.affine.rz = VFX_DEG_TO_RAD(3);

	shakeTransformTimeline->setTarget(getAnimDummyFrame(type));
	shakeTransformTimeline->setFromValue(tempTransformBegin);
	shakeTransformTimeline->setToValue(tempTransformTo);
	shakeTransformTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM); 	 
	shakeTransformTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
	shakeTransformTimeline->setDuration(200);
	shakeTransformTimeline->setAutoReversed(VFX_TRUE);
	shakeTransformTimeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
	shakeTransformTimeline->start();
}

void VcpRotatePageView::setAnimDirty(VfxS32 duration)
{
    VfxMsec ctime = VfxTimer::getCurrentTime();
    if (ctime + duration < m_animDirtyEndTime)
    {
        return;
    }
    m_animDirtyEndTime = ctime + duration;

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDuration(duration);

    for (VfxS32 i = 0; i < VCP_PAGE_MENU_GROUP_SIZE; ++i)
    {
        VfxFrame * dummy = getAnimDummyFrame(i);
        if (dummy->getFilterTiming() < 100.0f)
        {
            dummy->setFilterTiming(dummy->getFilterTiming() + 0.001f);
        }
        else
        {
            dummy->setFilterTiming(0.0f);
        }
    }

    VfxAutoAnimate::commit();
}

VfxS32 VcpRotatePageView::getCurrentTranslateX() const
{
    return getCurrentTranslateXInt(VCP_PAGE_MENU_GROUP_MAIN);
}

VfxS32 VcpRotatePageView::getCurrentTranslateXInt(VfxS32 group) const
{
    if (group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        return m_currentTranslate;
    }
    else
    {
        return getAnimDummyFrame(group)->forceGetPos().x;
    }
}

VfxTransform VcpRotatePageView::getCurrentShakeTransform()
{
    return getAnimDummyFrame(VCP_PAGE_MENU_GROUP_MAIN)->forceGetTransform();
}

VfxS32 VcpRotatePageView::getCellPosX(VcpPageMenuCell * cell) const
{
    return static_cast<VfxS32>(cell->getFpeUser0() );
}

void VcpRotatePageView::setCellPosX(VcpPageMenuCell * cell, VfxS32 posX)
{
    cell->setFpeUser0(static_cast<VfxFloat>(posX) );
}

VfxS32 VcpRotatePageView::getCellPosY(VcpPageMenuCell * cell) const
{
    return cell->getCellPosY();
}

void VcpRotatePageView::setCellPosY(VcpPageMenuCell * cell, VfxS32 posY)
{
    cell->setCellPosY(posY);
}

VfxFloat VcpRotatePageView::getCellScale(VcpPageMenuCell *cell) const
{
    return cell->getCellScale();
}

void VcpRotatePageView::setCellScale(VcpPageMenuCell *cell, VfxFloat scale)
{
    cell->setCellScale(scale);
}

const VcpPageMenuFolderEditorLayout &VcpRotatePageView::getFolderEditorLayout() const
{
    return m_folderEditorLayout;
}

void VcpRotatePageView::setFolderEditorLayout(const VcpPageMenuFolderEditorLayout &folderEditorLayout)
{
    m_folderEditorLayout = folderEditorLayout;
}

void VcpRotatePageView::setFolderState(VcpPageMenuFolderStateEnum folderState)
{
    m_folderState = folderState;
}


/*****************************************************************************
 * Class VcpPageMenuView
 *****************************************************************************/
VcpPageMenuView::VcpPageMenuView():
    m_pageView(NULL),
    m_clickFrame(NULL),
    m_translateX(0),
    m_translateDuration(MAINMENU_ANIMTIME_INSTANT),
    m_translateDirty(VFX_FALSE),
    m_rotateAngle(0.0f),
    m_rotateDuration(MAINMENU_ANIMTIME_INSTANT),
    m_rotateReset(VFX_TRUE),
    m_rotateDirty(VFX_FALSE),
    m_clipMargin(MAINMENU_CLIP_MARGIN_DEFAULT),
#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
    m_transitionType(VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL),
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
    m_organizeMode(VFX_FALSE),
    m_hover(-1, -1),
    m_dragOnIndicator(VFX_FALSE),
    m_folderState(VCP_PAGE_MENU_NOT_FOLDER_MODE),
    m_folderCellPos(-1, -1),
    m_organizeDragOffset(0, 0)
{
}

void VcpPageMenuView::onInit()
{
    VfxObject::onInit();

    VcpRotatePageView * rotateView;
    VFX_OBJ_CREATE(rotateView, VcpRotatePageView, this);
    m_pageView = rotateView;
}

void VcpPageMenuView::setSize(VfxS32 width, VfxS32 height)
{
    m_pageView->setSize(width, height);
}

void VcpPageMenuView::setCellIconSize(const VfxSize & size)
{
    m_pageView->setCellIconSize(size);
}

void VcpPageMenuView::initCellAnim(VcpPageMenuCell * cell, VfxS32 group)
{
    m_pageView->initCellAnim(cell, group);
}

void VcpPageMenuView::reset()
{
    m_pageView->reset();
}

void VcpPageMenuView::changeCellGroup(VcpPageMenuCell * cell, VfxS32 newGroup)
{
    m_pageView->changeCellGroup(cell, newGroup);
}

VcpPageMenuCell * VcpPageMenuView::getDraggingFrame() const
{
    return m_pageView->getDraggingFrame();
}

void VcpPageMenuView::setDraggingFrame(VcpPageMenuCell * draggingFrame)
{
    m_clickFrame = NULL;
    m_pageView->setDraggingFrame(draggingFrame);
}

void VcpPageMenuView::setClickFrame(VcpPageMenuCell * clickFrame)
{
    if (m_clickFrame)
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        m_clickFrame->setOpacity(1.0f);
        VfxAutoAnimate::commit();
    }
    m_clickFrame = clickFrame;
    if (m_clickFrame)
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        m_clickFrame->setOpacity(MAINMENU_EDITING_ALPHA);
        VfxAutoAnimate::commit();
    }
}

void VcpPageMenuView::setAnimDirty(VfxS32 duration)
{
    m_pageView->setAnimDirty(duration);
}

const VcpPageMenuLayout & VcpPageMenuView::getLayout() const
{
    return m_layout;
}

void VcpPageMenuView::setLayout(const VcpPageMenuLayout & layout)
{
    m_layout = layout;
    m_pageView->setLayout(layout);
}

VfxS32 VcpPageMenuView::getPageItemCount() const
{
    return m_layout.rowCount * m_layout.columnCount;
}

VfxS32 VcpPageMenuView::getMaxPageCount(VfxS32 maxCellCount) const
{
    return (maxCellCount + getPageItemCount() - 1) / getPageItemCount();
}

VfxBool VcpPageMenuView::isCellInRange(VfxS32 index)
{
    const VfxS32 x = index / getPageItemCount() * getPageLevel() +
                    index % getLayout().columnCount * getLayout().cellOffsetX +
                    getLayout().cellStartX;

    VfxS32 xmin = 0;
    VfxS32 xmax = 0;
    if (getTranslateX() < m_pageView->getCurrentTranslateX() )
    {
        xmin = x + getTranslateX();
        xmax = x + m_pageView->getCurrentTranslateX() + getLayout().cellOffsetX;
    }
    else
    {
        xmin = x + m_pageView->getCurrentTranslateX();
        xmax = x + getTranslateX() + getLayout().cellOffsetX;
    }

    if ( (xmin > m_pageView->getWidth() + m_clipMargin) || (xmax < -getLayout().cellOffsetX - m_clipMargin) )
    {
        return VFX_FALSE;
    }
    return VFX_TRUE;
}

VfxBool VcpPageMenuView::isCellInMiddleOfLongRange(VfxS32 index)
{
    const VfxS32 x = index / getPageItemCount() * getPageLevel() +
                    index % getLayout().columnCount * getLayout().cellOffsetX +
                    getLayout().cellStartX;

    VfxS32 xmin = 0;
    VfxS32 xmax = 0;
    if (getTranslateX() < m_pageView->getCurrentTranslateX() )
    {
        xmin = x + getTranslateX();
        xmax = x + m_pageView->getCurrentTranslateX() + getLayout().cellOffsetX;
    }
    else
    {
        xmin = x + m_pageView->getCurrentTranslateX();
        xmax = x + getTranslateX() + getLayout().cellOffsetX;
    }

    if ((xmin < -getLayout().cellOffsetX - m_clipMargin - getPageLevel()) &&
        (xmax > m_pageView->getWidth() + m_clipMargin + getPageLevel()))
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VfxS32 VcpPageMenuView::getPageLevel() const
{
    return m_pageView->getWidth() + getLayout().pageMargin;
}

VfxS32 VcpPageMenuView::getPageTranslateX(VfxS32 pageIndex) const
{
    return -pageIndex * getPageLevel();
}

VfxS32 VcpPageMenuView::getTranslateX() const
{
    return m_translateX;
}

void VcpPageMenuView::setTranslateX(VfxS32 translateX, VfxS32 translateDuration)
{
    if (m_translateX != translateX || m_translateDuration != translateDuration)
    {
        m_translateX = translateX;
        m_translateDuration = translateDuration;
        m_translateDirty = VFX_TRUE;

        // special handling to reduce pen move dragging latency
        if (translateDuration <= 1)
        {
            m_pageView->updateTranslateXInstant(translateX);
        }
    }
}

VfxFloat VcpPageMenuView::getRotateAngle() const
{
    return m_rotateAngle;
}

void VcpPageMenuView::setRotateAngle(VfxFloat rotateAngle, VfxS32 rotateDuration, VfxBool rotateReset)
{
    // limit
    if (rotateAngle > MAINMENU_BOUND_ROTATION_LIMIT)
    {
        rotateAngle = MAINMENU_BOUND_ROTATION_LIMIT;
    }
    else if (rotateAngle < -MAINMENU_BOUND_ROTATION_LIMIT)
    {
        rotateAngle = -MAINMENU_BOUND_ROTATION_LIMIT;
    }

    if (m_rotateAngle != rotateAngle || m_rotateDuration != rotateDuration || m_rotateReset != rotateReset)
    {
        m_rotateAngle = rotateAngle;
        m_rotateDuration = rotateDuration;
        m_rotateReset = rotateReset;
        m_rotateDirty = VFX_TRUE;
    }
}

VfxMsec VcpPageMenuView::getRotateDuration() const
{
    return m_rotateDuration;
}

VfxMsec VcpPageMenuView::getTranslateDuration() const
{
    return m_translateDuration;
}

void VcpPageMenuView::setOrganizeMode(VfxBool organizeMode)
{
    m_organizeMode = organizeMode;
    m_pageView->setOrganizeMode(m_organizeMode);
}

VfxBool VcpPageMenuView::getOrganizeMode()
{
    return m_organizeMode;
}

void VcpPageMenuView::setHover(VcpPageMenuCellPos hover)
{
    m_hover = hover;
}

VcpPageMenuCellPos VcpPageMenuView::getHover()
{
    return m_hover;
}

void VcpPageMenuView::setClipMargin(VfxS32 clipMargin)
{
    m_clipMargin = clipMargin;
}

void VcpPageMenuView::setIsUninstalling(VfxBool isUninstalling)
{
    m_pageView->setIsUninstalling(isUninstalling);
}

void VcpPageMenuView::setIsEnterNCenter(VfxBool isEnterNCenter)
{
    m_pageView->setIsEnterNCenter(isEnterNCenter);
}

#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
VcpPageMenuTransitionType VcpPageMenuView::getTransitionEffect() const
{
    return (VcpPageMenuTransitionType)m_transitionType;
}

void VcpPageMenuView::setTransitionEffect(VcpPageMenuTransitionType transitionType)
{
    m_transitionType = transitionType;
    m_pageView->setTransitionEffect(transitionType);
}

void VcpPageMenuView::setTransitionDirection(VfxS32 direction)
{
    m_pageView->setTransitionDirection(direction);
}
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__

void VcpPageMenuView::setDragOnIndicator(VfxBool dragOnIndicator)
{
    m_dragOnIndicator = dragOnIndicator;
}

void VcpPageMenuView::syncTranslateX()
{
    setTranslateX(m_pageView->getCurrentTranslateX(), MAINMENU_ANIMTIME_INSTANT);
}

void VcpPageMenuView::forceDirty()
{
    m_translateDirty = VFX_TRUE;
    m_translateDuration = MAINMENU_ANIMTIME_INSTANT;
}

VfxS32 VcpPageMenuView::getNearestPage() const
{
    // use the center of the margin between 2 pages as the separation of pages
    const VfxS32 andHalf = getTranslateX() + m_pageView->getWidth() / 2 + getLayout().pageMargin / 4;
    if (andHalf > 0)
    {
        return -(andHalf / getPageLevel() );
    }
    else
    {
        return -( (andHalf - getPageLevel() + 1) / getPageLevel() );
    }
}

VfxS32 VcpPageMenuView::getNextPage() const
{
    const VfxS32 shift = getTranslateX() - 10;
    if (shift > 0)
    {
        return -( shift / getPageLevel() );
    }
    else
    {
        return -( (shift - getPageLevel() + 1) / getPageLevel() );
    }
}

VfxS32 VcpPageMenuView::getPreviousPage() const
{
    const VfxS32 shift = getTranslateX() + 10;
    if (shift > 0)
    {
        return -( (shift + getPageLevel() - 1) / getPageLevel() );
    }
    else
    {
        return -( shift / getPageLevel() );
    }
}

VfxBool VcpPageMenuView::isTransitioning() const
{
    const VfxS32 page = getNearestPage();
    const VfxS32 targetTranslateX = page * -getPageLevel();
    const VfxS32 diffTranslateX = VFX_ABS(targetTranslateX - getTranslateX() );
    const VfxS32 diffCurrentTranslateX = VFX_ABS(targetTranslateX - m_pageView->getCurrentTranslateX() );
    if (diffTranslateX < MAINMENU_TRANSITIONING_THRESHOLD && diffCurrentTranslateX < MAINMENU_TRANSITIONING_THRESHOLD)
    {
        return VFX_FALSE;
    }
    return VFX_TRUE;
}

VfxPoint VcpPageMenuView::getOrganizeDragOffset() const
{
    return m_organizeDragOffset;
}

VcpPageMenuCellPos VcpPageMenuView::baseCellHittest(VfxPoint clickPoint, VfxS32 maxCellCount, VcpPageMenuCellHitAreaEnum *hitArea) const
{
    if (m_folderState == VCP_PAGE_MENU_FIRST_FOLDER_MODE || m_folderState == VCP_PAGE_MENU_FOLDER_MODE)
    {
        return baseCellHittestFolderEditor(clickPoint);
    }
    
    if (getLayout().bottomBarOffsetY != -1 && clickPoint.y > getLayout().bottomBarOffsetY)
    {
        return baseCellHittestBar(clickPoint, hitArea);
    }

    if (clickPoint.x < getLayout().cellStartX || clickPoint.x > getLayout().cellOffsetX * getLayout().columnCount + getLayout().cellStartX)
    {
        return VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN, MAINMENU_HITTEST_NOT_FOUND);
    }
    if (clickPoint.y < getLayout().cellStartY || clickPoint.y > getLayout().cellStartY + getLayout().cellOffsetY * getLayout().rowCount)
    {
        return VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN, MAINMENU_HITTEST_NOT_FOUND);
    }

    const VfxS32 x = clickPoint.x / getLayout().cellOffsetX;
    const VfxS32 y = (clickPoint.y - getLayout().cellStartY) / getLayout().cellOffsetY;

    // XXX : the following 4 lines are redundant checks
    if (x < 0 || x >= getLayout().columnCount)
    {
        return VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN, MAINMENU_HITTEST_NOT_FOUND);
    }
    if (y < 0 || y >= getLayout().rowCount)
    {
        return VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN, MAINMENU_HITTEST_NOT_FOUND);
    }

    const VfxS32 panelIndex = -1 * ( (getTranslateX() - getPageLevel() / 2) / getPageLevel() );
    const VfxS32 index = x + getLayout().columnCount * y + getPageItemCount() * panelIndex;

    if (index < 0 || index >= maxCellCount)
    {
        return VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN, MAINMENU_HITTEST_NOT_FOUND);
    }

    if (hitArea)
    {
        VfxS32 topAreaBoundary = getLayout().cellStartY + y * getLayout().cellOffsetY + MAINMENU_CELL_HIT_TEST_MARGIN_FACTOR * getLayout().cellOffsetY;
        VfxS32 downAreaBoundary = getLayout().cellStartY + (y+1) * getLayout().cellOffsetY - MAINMENU_CELL_HIT_TEST_MARGIN_FACTOR * getLayout().cellOffsetY;
        VfxS32 leftAreaBoundary = getLayout().cellStartX + x * getLayout().cellOffsetX + MAINMENU_CELL_HIT_TEST_MARGIN_FACTOR * getLayout().cellOffsetX;
        VfxS32 rightAreaBoundary = getLayout().cellStartX + (x+1) * getLayout().cellOffsetX - MAINMENU_CELL_HIT_TEST_MARGIN_FACTOR * getLayout().cellOffsetX;
        *hitArea = baseCellHittestArea(clickPoint, topAreaBoundary, downAreaBoundary, leftAreaBoundary, rightAreaBoundary);
    }
    
    return VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN, index);
}

VcpPageMenuCellPos VcpPageMenuView::baseCellHittestBar(VfxPoint clickPoint, VcpPageMenuCellHitAreaEnum *hitArea) const
{
    if (clickPoint.x < getLayout().cellStartX || clickPoint.x > getLayout().cellOffsetX * getLayout().columnCount + getLayout().cellStartX)
    {
        return VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_BOTTOM_BAR, MAINMENU_HITTEST_NOT_FOUND);
    }

    const VfxS32 x = clickPoint.x / getLayout().cellOffsetX;

    if (x < 0 || x >= getLayout().columnCount)
    {
        return VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_BOTTOM_BAR, MAINMENU_HITTEST_NOT_FOUND);
    }

    if (hitArea)
    {
        VfxS32 topAreaBoundary = getLayout().bottomBarOffsetY + MAINMENU_CELL_HIT_TEST_MARGIN_FACTOR * getLayout().cellOffsetY;
        VfxS32 downAreaBoundary = getLayout().bottomBarOffsetY + getLayout().cellOffsetY - MAINMENU_CELL_HIT_TEST_MARGIN_FACTOR * getLayout().cellOffsetY;
        VfxS32 leftAreaBoundary = getLayout().cellStartX + x * getLayout().cellOffsetX + MAINMENU_CELL_HIT_TEST_MARGIN_FACTOR * getLayout().cellOffsetX;
        VfxS32 rightAreaBoundary = getLayout().cellStartX + (x+1) * getLayout().cellOffsetX - MAINMENU_CELL_HIT_TEST_MARGIN_FACTOR * getLayout().cellOffsetX;
        *hitArea = baseCellHittestArea(clickPoint, topAreaBoundary, downAreaBoundary, leftAreaBoundary, rightAreaBoundary);
    }
    
    return VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_BOTTOM_BAR, x);
}

void VcpPageMenuView::update(VcpPageMenuCell ** cells, VfxS32 cellCount, VcpPageMenuCell ** groupCells, VfxS32 groupCellCount)
{
    if (m_rotateDirty)
    {
        m_pageView->updateRotation(getRotateDuration(), getRotateAngle(), m_rotateReset);
        m_rotateDirty = VFX_FALSE;
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM3", SA_start);
#endif
    if (m_translateDirty)
    {
        m_pageView->updateTranslateX(getTranslateDuration(), getTranslateX());
        m_translateDirty = VFX_FALSE;
    }

#if !(defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_LAUNCHER_KEY__))
    if (getDraggingFrame() != NULL &&
        (getFolderState() != VCP_PAGE_MENU_FIRST_PREPARE_TO_FOLDER_MODE &&
         getFolderState() != VCP_PAGE_MENU_PREPARE_TO_FOLDER_MODE))
    {
        m_pageView->updateScale(MAINMENU_ORGANIZE_DURATION, MAINMENU_DRAGGING_SCALE);
    }
    else if (m_clickFrame != NULL && getOrganizeMode() == VFX_FALSE)
    {
        m_pageView->updateScale(MAINMENU_ORGANIZE_DURATION, MAINMENU_CLICK_SCALE);
    }
    else
    {
        m_pageView->updateScale(MAINMENU_ORGANIZE_DURATION, 1.0f);
    }
#endif

#if defined(__MMI_VUI_LAUNCHER_COSMOS__) || defined(__MMI_VUI_LAUNCHER_MM__)
    m_pageView->updateShakeTransform(getOrganizeMode());
#endif

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM3", SA_stop);
    SLA_CustomLogging("MM3", SA_start);
#endif
    updateCells(cells, cellCount);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM3", SA_stop);
    SLA_CustomLogging("MM3", SA_start);
#endif
    updateGroupCells(groupCells, groupCellCount);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM3", SA_stop);
#endif
}

void VcpPageMenuView::updateEx(VcpPageMenuCell **cells, VfxS32 cellCount,
                               VcpPageMenuCell **groupCells, VfxS32 groupCellCount,
                               VcpPageMenuCell **cellsInFolderIcon, VfxS32 folderCount, VfxS32 cellInFolderIconCount,
                               VcpPageMenuCell **groupCellsInFolderIcon, VfxS32 groupFolderCount, VfxS32 groupCellInFolderIconCount,
                               VcpPageMenuCell **cellsInFolderEditor, VfxS32 cellInFolderEditorCount)
{
    update(cells, cellCount, groupCells, groupCellCount);
    updateCellsInFolderIcon(cellsInFolderIcon, folderCount, cellInFolderIconCount);
    updateCellsInFolderIcon(groupCellsInFolderIcon, groupFolderCount, groupCellInFolderIconCount);
    updateCellsInFolderEditor(cellsInFolderEditor, cellInFolderEditorCount);
}

void VcpPageMenuView::setFolderState(VcpPageMenuFolderStateEnum folderState)
{
    m_folderState = folderState;
    m_pageView->setFolderState(folderState);
}

VcpPageMenuFolderStateEnum VcpPageMenuView::getFolderState()
{
    return m_folderState;
}

void VcpPageMenuView::setFolderCellPos(VcpPageMenuCellPos folderCellPos)
{
    m_folderCellPos = folderCellPos;
}

VcpPageMenuCellPos VcpPageMenuView::getFolderCellPos()
{
    return m_folderCellPos;
}

VfxS32 VcpPageMenuView::getFolderIconItemCount() const
{
    return m_layout.rowCountInFolderIcon * m_layout.columnCountInFolderIcon;
}

const VcpPageMenuFolderEditorLayout &VcpPageMenuView::getFolderEditorLayout() const
{
    return m_pageView->getFolderEditorLayout();
}

void VcpPageMenuView::setFolderEditorLayout(const VcpPageMenuFolderEditorLayout &folderEditorLayout)
{
    m_pageView->setFolderEditorLayout(folderEditorLayout);
}

void VcpPageMenuView::updateCells(VcpPageMenuCell ** cells, VfxS32 cellCount)
{
    if (cells == NULL || cellCount == 0)
    {
        return;
    }

    for (VfxS32 i = 0; i < cellCount; ++i)
    {
        if (cells[i] == NULL)
        {
            continue;
        }

    #if defined(__MMI_FTE_SUPPORT_SLIM__)
        cells[i]->setQuality(VFX_RENDER_QUALITY_NORMAL);
    #else
        cells[i]->setQuality(VFX_RENDER_QUALITY_HIGH);
    #endif

        VfxAutoAnimate::begin();

        // use ease out for all pos animation
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);

        if (isCellInRange(i))
        {
            cells[i]->onCellDisplay();
        }
        updateCellPos(cells[i], i);
        updateCellAttribute(cells[i], VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN, i));
        
        VfxAutoAnimate::commit();
    }
}

void VcpPageMenuView::updateGroupCells(VcpPageMenuCell ** cells, VfxS32 cellCount)
{
    if (cells == NULL || cellCount == 0 || getLayout().bottomBarOffsetY == -1)
    {
        return;
    }

    for (VfxS32 i = 0; i < cellCount; ++i)
    {
        if (cells[i] == NULL)
        {
            continue;
        }

    #if defined(__MMI_FTE_SUPPORT_SLIM__)
        cells[i]->setQuality(VFX_RENDER_QUALITY_NORMAL);
    #else
        cells[i]->setQuality(VFX_RENDER_QUALITY_HIGH);
    #endif
    
        VfxAutoAnimate::begin();

        // use ease out for all pos animation
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        
        cells[i]->onCellDisplay();
        updateGroupCellPos(cells[i], i, getLayout().bottomBarOffsetY + getLayout().bottomBarVisibleShiftY);
        updateCellAttribute(cells[i], VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_BOTTOM_BAR, i));

        VfxAutoAnimate::commit();
    }
}

void VcpPageMenuView::updateCellPosInt(VcpPageMenuCell * cell, VfxS32 x, VfxS32 y, VfxBool isFolder)
{    
    m_pageView->setCellPosX(cell, x);
    m_pageView->setCellPosY(cell, y);
    
    if (getTranslateX() % getPageLevel() == 0 && cell->getNeedSetExactPos() && getOrganizeMode())
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        if (isFolder)
            cell->setPos(x, y);
        else
            cell->setPos(x + getTranslateX(), y);
        VfxAutoAnimate::commit();
    }
}

void VcpPageMenuView::updateCellPos(VcpPageMenuCell * cell, VfxS32 index)
{
    if (cell == getDraggingFrame() )
    {
        return;
    }

    VfxS32 x = index % getLayout().columnCount * getLayout().cellOffsetX + getLayout().cellStartX;
    x += index / getPageItemCount() * getPageLevel();
    VfxS32 y = (index % getPageItemCount() ) / getLayout().columnCount * getLayout().cellOffsetY + getLayout().cellStartY;

    // Shift cell in folder mode if necessary
    if (getFolderState() == VCP_PAGE_MENU_FIRST_FOLDER_MODE ||
        getFolderState() == VCP_PAGE_MENU_FOLDER_MODE)
    {
        if (getFolderCellPos().group == VCP_PAGE_MENU_GROUP_MAIN)
        {
            VfxS32 originalFolderPosY = (getFolderCellPos().index % getPageItemCount()) / getLayout().columnCount * getLayout().cellOffsetY + getLayout().cellStartY;
            VfxS32 changedFolderPosY = getFolderEditorLayout().folderEditorPosY - getFolderEditorLayout().folderEditorMainShiftY;
            
            if (y <= originalFolderPosY)
            {
                y += (changedFolderPosY - originalFolderPosY);
            }
            else
            {
                y += getFolderEditorLayout().folderEditorHeight;
            }
        }
        else if (getFolderCellPos().group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
        {
            y -= getFolderEditorLayout().folderEditorHeight;
        }
    }
    
    updateCellPosInt(cell, x, y, VFX_FALSE);
}

void VcpPageMenuView::updateGroupCellPos(VcpPageMenuCell * cell, VfxS32 index, VfxS32 shiftY)
{
    if (cell == getDraggingFrame() )
    {
        return;
    }

    VfxS32 x = index % getLayout().columnCount * getLayout().cellOffsetX + getLayout().cellStartX;
    VfxS32 y = (index % getPageItemCount() ) / getLayout().columnCount * getLayout().cellOffsetY + MAINMENU_CELL_BAR_START_Y_DEFAULT + shiftY;

    // Shift cell in folder mode if necessary
    if (getFolderState() == VCP_PAGE_MENU_FIRST_FOLDER_MODE ||
        getFolderState() == VCP_PAGE_MENU_FOLDER_MODE)
    {
        if (getFolderCellPos().group == VCP_PAGE_MENU_GROUP_MAIN)
        {
            y += getFolderEditorLayout().folderEditorHeight;
        }
    }
    
    updateCellPosInt(cell, x, y, VFX_TRUE);
}

void VcpPageMenuView::updateCellsInFolderIcon(VcpPageMenuCell **cellsInFolderIcon, VfxS32 folderCount, VfxS32 cellInFolderIconCount)
{
    if (cellsInFolderIcon == NULL || folderCount == 0 || cellInFolderIconCount == 0)
    {
        return;
    }

    VfxAutoAnimate::begin();
    // use ease out for all pos animation
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    
    for (VfxS32 i = 0; i < folderCount; ++i)
    {
        for (VfxS32 j = 0; j < cellInFolderIconCount; ++j)
        {
            if (cellsInFolderIcon[i*cellInFolderIconCount + j] == NULL)
            {
                continue;
            }
            
            if (isCellInRange(i) ||
                cellsInFolderIcon[i*cellInFolderIconCount + j]->getCellGroup() == VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON)
            {
                cellsInFolderIcon[i*cellInFolderIconCount + j]->onCellDisplay();
            }
            
            updateCellInFolderIconPos(cellsInFolderIcon[i*cellInFolderIconCount + j], j);
//            updateCellAttribute(cellsInFolder[i*cellInFolderCount + j], VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON, i));
            m_pageView->setCellScale(cellsInFolderIcon[i*cellInFolderIconCount + j], getLayout().cellInFolderIconScale);
        }
    }
    
    VfxAutoAnimate::commit();
}

void VcpPageMenuView::updateCellInFolderIconPos(VcpPageMenuCell *cell, VfxS32 subIndex)
{
    if (cell == getDraggingFrame())
    {
        return;
    }

    VfxS32 x;
    VfxS32 y;
    if (subIndex < getFolderIconItemCount())
    {
        x = subIndex % getLayout().columnCountInFolderIcon * getLayout().cellInFolderIconOffsetX + getLayout().cellInFolderIconStartX;
        y = subIndex / getLayout().columnCountInFolderIcon * getLayout().cellInFolderIconOffsetY + getLayout().cellInFolderIconStartY;
    }
    else
    {
        x = -10000;
        y = -10000;
    }
    
    m_pageView->setCellPosX(cell, x);
    m_pageView->setCellPosY(cell, y);
}

void VcpPageMenuView::updateCellsInFolderEditor(VcpPageMenuCell **cellsInFolderEditor, VfxS32 cellInFolderEditorCount)
{
    if (cellsInFolderEditor == NULL || cellInFolderEditorCount == 0)
    {
        return;
    }

    VfxAutoAnimate::begin();
    // use ease out for all pos animation
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    
    for (VfxS32 i = 0; i < cellInFolderEditorCount; ++i)
    {
        if (cellsInFolderEditor[i] == NULL)
        {
            continue;
        }

        cellsInFolderEditor[i]->onCellDisplay();
        updateCellInFolderEditorPos(cellsInFolderEditor[i], i);
        updateCellAttribute(cellsInFolderEditor[i], VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_FOLDER_EDITOR, i));
    }
    
    VfxAutoAnimate::commit();
}

void VcpPageMenuView::updateCellInFolderEditorPos(VcpPageMenuCell *cell, VfxS32 index)
{
    if (cell == getDraggingFrame())
    {
        return;
    }

    VfxS32 x = index % getFolderEditorLayout().columnCountInFolderEditor * getFolderEditorLayout().cellInFolderEditorOffsetX + getFolderEditorLayout().cellInFolderEditorStartX;
    VfxS32 y = index / getFolderEditorLayout().columnCountInFolderEditor * getFolderEditorLayout().cellInFolderEditorOffsetY + getFolderEditorLayout().cellInFolderEditorStartY;

    updateCellPosInt(cell, x, y, VFX_TRUE);
}

VcpPageMenuCellHitAreaEnum VcpPageMenuView::baseCellHittestArea(VfxPoint clickPoint,
                                                                VfxS32 topAreaBoundary,
                                                                VfxS32 downAreaBoundary,
                                                                VfxS32 leftAreaBoundary,
                                                                VfxS32 rightAreaBoundary) const
{
    if (clickPoint.y < topAreaBoundary)
    {
        if (clickPoint.x < leftAreaBoundary)
        {
            return VCP_PAGE_MENU_CELL_HIT_AREA_LEFT_TOP;
        }
        else if (clickPoint.x > rightAreaBoundary)
        {
            return VCP_PAGE_MENU_CELL_HIT_AREA_RIGHT_TOP;
        }
        else
        {
            return VCP_PAGE_MENU_CELL_HIT_AREA_CENTER_TOP;
        }
    }
    else if (clickPoint.y > downAreaBoundary)
    {
        if (clickPoint.x < leftAreaBoundary)
        {
            return VCP_PAGE_MENU_CELL_HIT_AREA_LEFT_DOWN;
        }
        else if (clickPoint.x > rightAreaBoundary)
        {
            return VCP_PAGE_MENU_CELL_HIT_AREA_RIGHT_DOWN;
        }
        else
        {
            return VCP_PAGE_MENU_CELL_HIT_AREA_CENTER_DOWN;
        }
    }
    else
    {
        if (clickPoint.x < leftAreaBoundary)
        {
            return VCP_PAGE_MENU_CELL_HIT_AREA_LEFT_CENTER;
        }
        else if (clickPoint.x > rightAreaBoundary)
        {
            return VCP_PAGE_MENU_CELL_HIT_AREA_RIGHT_CENTER;
        }
        else
        {
            return VCP_PAGE_MENU_CELL_HIT_AREA_CENTER;
        }
    }
}

VcpPageMenuCellPos VcpPageMenuView::baseCellHittestFolderEditor(VfxPoint clickPoint) const
{
    if (clickPoint.x < getFolderEditorLayout().cellInFolderEditorStartX ||
        clickPoint.x > getFolderEditorLayout().cellInFolderEditorStartX + getFolderEditorLayout().cellInFolderEditorOffsetX * getFolderEditorLayout().columnCountInFolderEditor)
    {
        return VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_FOLDER_EDITOR, MAINMENU_HITTEST_NOT_FOUND);
    }
    if (clickPoint.y < getFolderEditorLayout().cellInFolderEditorStartY ||
        clickPoint.y > getFolderEditorLayout().cellInFolderEditorStartY + getFolderEditorLayout().cellInFolderEditorOffsetY * getFolderEditorLayout().rowCountInFolderEditor)
    {
        return VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_FOLDER_EDITOR, MAINMENU_HITTEST_NOT_FOUND);
    }

    const VfxS32 x = (clickPoint.x - getFolderEditorLayout().cellInFolderEditorStartX) / getFolderEditorLayout().cellInFolderEditorOffsetX;
    const VfxS32 y = (clickPoint.y - getFolderEditorLayout().cellInFolderEditorStartY) / getFolderEditorLayout().cellInFolderEditorOffsetY;

    if (x < 0 || x >= getFolderEditorLayout().columnCountInFolderEditor)
    {
        return VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_FOLDER_EDITOR, MAINMENU_HITTEST_NOT_FOUND);
    }
    if (y < 0 || y >= getFolderEditorLayout().rowCountInFolderEditor)
    {
        return VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_FOLDER_EDITOR, MAINMENU_HITTEST_NOT_FOUND);
    }
    
    const VfxS32 index = x + getLayout().columnCount * y;
    return VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_FOLDER_EDITOR, index);
}

void VcpPageMenuView::updateCellAttribute(VcpPageMenuCell * cell, VcpPageMenuCellPos pos)
{
    VfxFloat opacity;
    if (cell == getDraggingFrame() )
    {
        if (!m_dragOnIndicator)
        {
            opacity = 1.0f;
        }
        else
        {
            opacity = MAINMENU_EDITING_ALPHA;
        }
    }
    else if (m_organizeMode)
    {
        opacity = MAINMENU_EDITING_ALPHA;
    }
    else if (pos == m_hover)
    {
        opacity = MAINMENU_EDITING_ALPHA;
    }
    else
    {
        opacity = 1.0f;
    }

    // no animation for alpha
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    cell->setOpacity(opacity);
    VfxAutoAnimate::commit();
}

void VcpPageMenuView::setHoldFrame(VcpPageMenuCell * holdFrame)
{
    if (holdFrame == NULL)
    {
        return;
    }
    holdFrame->setOpacity(0.0f);

    // shift the hold frame to avoid strange animation when handleOrganizePut()
    m_pageView->setCellPosX(holdFrame, m_pageView->getCellPosX(holdFrame) + getLayout().cellOffsetX);
}

void VcpPageMenuView::setDraggingFramePos(VfxS32 touchPosX, VfxS32 touchPosY)
{
    m_pageView->setAnimDirty(MAINMENU_ORGANIZE_DURATION);
    
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    m_pageView->setCellPosX(getDraggingFrame(), touchPosX + m_organizeDragOffset.x);
    m_pageView->setCellPosY(getDraggingFrame(), touchPosY + m_organizeDragOffset.y);
    VfxAutoAnimate::commit();
    
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_LAUNCHER_KEY__)
    getDraggingFrame()->forcePos(VfxPoint(touchPosX + m_organizeDragOffset.x, touchPosY + m_organizeDragOffset.y));
#endif
}

void VcpPageMenuView::initDraggingFramePos(VcpPageMenuCell * hoverCell, VfxS32 cellGroup, VfxS32 touchPosX, VfxS32 touchPosY)
{
    VfxS32 hoverPosX = m_pageView->getCellPosX(hoverCell);
    VfxS32 hoverPosY = m_pageView->getCellPosY(hoverCell);
    if (cellGroup == VCP_PAGE_MENU_GROUP_MAIN)
    {
        m_organizeDragOffset = VfxPoint(hoverPosX - touchPosX - getNearestPage() * getPageLevel(), hoverPosY - touchPosY);
    }
    else if (cellGroup == VCP_PAGE_MENU_GROUP_BOTTOM_BAR ||
             cellGroup == VCP_PAGE_MENU_GROUP_FOLDER_EDITOR)
    {
        m_organizeDragOffset = VfxPoint(hoverPosX - touchPosX, hoverPosY - touchPosY);
    }
    else
    {
        VFX_ASSERT(VFX_FALSE);
    }
}


/*****************************************************************************
  * Menu Cell Utility Functions
  *****************************************************************************/

VfxBool vcpPageMenuIsPageEmpty(VcpPageMenuCell ** cells, VfxS32 pageItemCount, VfxS32 pageIndex)
{
    // assume in page apps are always compacted
    if (cells[pageIndex * pageItemCount] == NULL)
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

void vcpPageMenuMovePageContent(VcpPageMenuCell **cells, VfxS32 pageItemCount, VfxS32 srcPageIndex, VfxS32 destPageIndex,
                                VcpPageMenuCell **cellsInFolderIcon, VfxS32 cellsCountPerFolder)
{
    if (srcPageIndex == destPageIndex)
        return;

    for (VfxS32 i = 0; i < pageItemCount; ++i)
    {
        const VfxS32 destIndex = destPageIndex * pageItemCount + i;
        const VfxS32 srcIndex = srcPageIndex * pageItemCount + i;
        cells[destIndex] = cells[srcIndex];
        cells[srcIndex] = NULL;
        
        for (VfxS32 j = 0; j < cellsCountPerFolder; ++j)
        {
            cellsInFolderIcon[destIndex * cellsCountPerFolder + j] = cellsInFolderIcon[srcIndex * cellsCountPerFolder + j];
            cellsInFolderIcon[srcIndex * cellsCountPerFolder + j] = NULL;
        }
    }
}

void vcpPageMenuClearPageContent(VcpPageMenuCell **cells, VfxS32 pageItemCount, VfxS32 pageIndex,
                                 VcpPageMenuCell **cellsInFolderIcon, VfxS32 cellsCountPerFolder)
{
    for (VfxS32 i = 0; i < pageItemCount; ++i)
    {
        cells[pageIndex * pageItemCount + i] = NULL;
        
        for (VfxS32 j = 0; j < cellsCountPerFolder; ++j)
        {
            cellsInFolderIcon[(pageIndex * pageItemCount + i) * cellsCountPerFolder + j] = NULL;
        }
    }
}

void vcpPageMenuApplyFrameRenderHints(VfxFrame * frame)
{
    frame->setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);
}

#endif // defined(__MMI_VUI_3D_MAINMENU__) || defined(__COSMOS_MMI__) || defined(__MMI_VUI_LAUNCHER__)|| defined(__MMI_VUI_LAUNCHER_KEY__)

