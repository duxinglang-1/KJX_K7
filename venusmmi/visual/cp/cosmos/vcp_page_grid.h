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
 *  vcp_page_grid.h
 *
 * Project:
 * --------
 *  Venus CP
 *
 * Description:
 * ------------
 *  Venus CP
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *****************************************************************************/

#ifndef __VCP_PAGE_GRID_H__
#define __VCP_PAGE_GRID_H__

#include "MMI_features.h"

#ifdef __COSMOS_MMI__

 /*****************************************************************************
  * Include
  *****************************************************************************/
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vfx_frame.h"
#include "vfx_control.h"
#include "vfx_class_info.h"
#include "vfx_object.h"
#include "vfx_basic_type.h"

 /*****************************************************************************
  * Define
  *****************************************************************************/

#define VCP_PAGEGRID_MAX_ITEM 160

class VfxPenEvent;

class VcpPageGridLayout : public VfxBase
{
public:
    VcpPageGridLayout();

    VfxS32 rowCount;
    VfxS32 columnCount;

    VfxS32 cellStartX;
    VfxS32 cellStartY;
    VfxS32 cellOffsetX;
    VfxS32 cellOffsetY;

    VfxS32 pageMargin;

    VfxS32 pageIndicatorOffsetY;
};

class VcpPageGridCell : public VfxFrame
{
public:
    VcpPageGridCell();
    virtual void onInit();
    virtual void onShowCell();
};

class VcpPageMenuIndicatorLayout;
class VcpPageMenuIndicator;

/*****************************************************************************
  * Class VcpPageGrid
  *****************************************************************************/


/*
* The description of this class
*
*/
class VcpPageGrid : public VfxControl
{
    VFX_DECLARE_CLASS(VcpPageGrid);

// Constructor / Destructor
public:	
    // Default constructor.
    VcpPageGrid();


// Properties
public:
    VfxS32 getCurrentPageIndex() const;
    void setCurrentPageIndex(VfxS32 pageIndex, VfxBool animated);

    VfxS32 getPageCount() const;

    void setLayout(const VcpPageGridLayout & layout);
    VcpPageGridLayout getLayout() const;

    void setIndicatorLayout(const VcpPageMenuIndicatorLayout & indicatorLayout);

    VcpPageMenuIndicatorLayout getIndicatorLayout() const;

// Method
public:
    void resetCells();
    void appendCell(VcpPageGridCell * cell);

// Event
public:
    VfxSignal1<VfxS32> m_itemClicked;
    VfxSignal1<VfxS32> m_pageChanged;

// Override
protected:
    virtual void onInit();

    virtual void onUpdate();

    virtual VfxBool onKeyInput(VfxKeyEvent &event);

    virtual VfxBool onPenInput(VfxPenEvent &event);

// Implementation
private:
    // init data
    VfxS32                  m_itemCount;
    VfxBool                 m_itemDataDirty;
    VfxS32                  m_pageCount;
    VfxS32                  m_stableCurrentPageIndex;
    VcpPageGridLayout       m_layout;

    // frame data
    VcpPageGridCell     *  m_cells[VCP_PAGEGRID_MAX_ITEM];
    VcpPageMenuIndicator  *  m_pageIndicator;

    // page animation parameter
    VfxS32                  m_translateX;
    VfxS32                  m_extraGap;

    // menu state
    VfxS32                  m_hover;
    VfxBool                 m_startPen;
    VfxMsec                 m_translateDuration;
    VfxS32                  m_translateOrigX;

    // private functions

    // property wrappers
    VfxS32 getTranslateX() const;
    void setTranslateX(VfxS32 translateX);
    VfxS32 getHover() const;
    void setHover(VfxS32 hover);
    VfxMsec getTranslateDuration() const;
    void setTranslateDuration(VfxMsec translateDuration);

    // helper wrappers
    VfxS32 getCurrentTranslateX() const;
    VfxS32 getCellPosX(VcpPageGridCell * cell) const;
    VfxS32 getCellPosY(VcpPageGridCell * cell) const;
    void setCellPos(VcpPageGridCell * cell, VfxS32 posX, VfxS32 posY);
    VfxS32 getPageItemCount() const;
    VfxS32 getMaxPageCount() const;

    // screen animation functions
    void updateTranslateX(VfxS32 duration);

    // update cell frame properties
    void updateCells();
    void updateCellPos(VfxS32 index);
    void updateCellAlpha(VfxS32 index);

    void onPageIndicatorSelected(VfxS32 pageSelected);

    // helper function
    VfxS32 cellHittest(VfxPoint clickPoint, VfxBool findLast) const;
    void scrollToPage(VfxS32 pageIndex);
    VfxS32 getNearestPage() const;
    VfxS32 getNextPage() const;
    VfxS32 getPreviousPage() const;
    void limitTranslateX();
    VfxBool isTransitioning() const;

    // scroll handling
    VfxBool handlePenDown(const VfxPoint &touchDownPos);
    VfxBool handleScroll(const VfxPenEvent &event);
    void handleScrollEnd(VfxS32 diffX, VfxMsec elapse);
    void handleScrollMove(VfxS32 diffX, VfxS32 diffY);
    void handleScrollSwipe(VfxS32 diffX, VfxFloat speed);
};

#endif // __COSMOS_MMI__

#endif /* __VCP_PAGE_GRID_H__ */

