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
 *  vtst_rt_menu.cpp
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vcp_base_menu.h"
#include "vtst_rt_main.h"
#include "vfx_basic_type.h"

#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vrt_datatype.h"
#include "vfx_control.h"
#include "vfx_input_event.h"
#include "vfx_text_frame.h"
#include "vfx_animation.h"
#include "vfx_auto_animate.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_string.h"
#include "vfx_frame.h"
#include "kal_public_api.h"
#include "vfx_app_cat_scr.h"

#define LAYOUT_TEST_COUNT 4

/***************************************************************************** 
 * Menu Test Implementation
 *****************************************************************************/

/***************************************************************************** 
 * class MyLayout
 *****************************************************************************/

class MyLayout : public VcpBaseMenuLayout
{
// Constructor / Destructor
public:
    MyLayout(VcpBaseMenu* menu) : VcpBaseMenuLayout(menu) {}
    virtual ~MyLayout(){}

// Override
public:
    virtual void onInit()
    {
        VcpBaseMenuLayout::onInit();

        m_cellWidth = m_cellHeight = 30;
        m_headerHeight = 30;
        m_columnCount = 3;
        m_groupGap = 10;
        resetCache();
    }

    virtual ScrollDirEnum getScrollDir()
    {
        return SCROLLDIR_VERT;
    }

    virtual VfxS32 getGroupCount()
    {
        return 3;
    }
    
    virtual VfxS32 getCellCount(VfxS32 group)
    {
        return 5 + group * 3;
    }

    virtual VfxS32 getContentLength()
    {
        return m_groupStartPt[3] - m_groupGap;
    }

    virtual VfxBool hasGroupHeader(VfxS32 group)
    {
        return VFX_TRUE;
    }

    virtual VcpMenuRegion queryRegion(const VfxRect& r)
    {
        return VcpMenuRegion(
            getCellByPos(r.origin),
            getCellByPos(VfxPoint(r.getMaxX(), r.getMaxY()))
        );
    }

    VcpMenuPos getCellByPos(VfxPoint pt)
    {
        VcpMenuPos p;
        p.group = getGroupByY(pt.y);
        VfxS32 offy = pt.y - m_groupStartPt[p.group];

        if (offy < m_headerHeight)
        {
            p.pos = -1;
            return p;
        }

        VfxS32 row = (offy - m_headerHeight) / m_cellHeight;
        VfxS32 col = VFX_MAX(pt.x - 1, 0) / m_cellHeight;
        p.pos = row * m_columnCount + col;

        if (p.pos >= getCellCount(p.group))
        {
            p.pos = getCellCount(p.group) - 1;
        }
        return p;
    }    

    // Return the header rect of a group
    virtual VfxRect queryGroupHeaderRect(VfxS32 group)
    {
        return VfxRect(
            0, 
            m_groupStartPt[group], 
            getViewSize().width, 
            m_headerHeight);
    }

    // Return a cell rect
    virtual VfxRect queryCellRect(VcpMenuPos pos)
    {
        if (pos.group < 0 || pos.pos < -1)
            return VfxRect(-1, -1, 0, 0);

        if (pos.group >= 3 || pos.pos >= getCellCount(pos.group))
            return VfxRect(-1, -1, 0, 0);

        VfxS32 y = m_groupStartPt[pos.group] + m_headerHeight;
        VfxS32 w = m_cellHeight;

        VfxS32 row = (pos.pos / m_columnCount) * m_cellHeight;
        VfxS32 col = (pos.pos % m_columnCount) * w;
                
        return VfxRect(col, y + row, w, m_cellHeight);
    }

    virtual void getPreferFocusMargin(VfxS32 margin[4])
    {
        margin[0] = 0;
        margin[1] = m_cellHeight;
        margin[2] = 0;
        margin[3] = m_cellHeight;
    }

    virtual void onViewChanged()
    {
        resetCache();
    }    

    virtual VfxBool navDir(NavDirEnum dir)
    {
        // If there is no one is focused, we pick up one in the screen
        if (!getFocusItem().isValid())
        {
            VcpMenuPos p = getCellByPos(m_viewRect.origin);
            // we cannot focus on the header
            if (p.isGroupHeader()) 
            {
                p.pos = 0;
            }
            setFocusItem(p);
            return VFX_TRUE;
        }

        VcpMenuPos p;
        if (dir == NAV_DIR_UP)
        {
            p = getFocusItem();

            VfxS32 c = p.pos % m_columnCount, r = p.pos / m_columnCount;
            VfxS32 group_row = (getCellCount(p.group)-1) / m_columnCount;

            if (r > 0)
            {
                r --;
                p.pos = r * m_columnCount + c;
            }
            else
            {
                if (p.group <= 0)
                {
                    p.group = 0;
                    p.pos = 0;
                }
                else
                {
                    p.group--;

                    VfxS32 n_group_row = getCellCount(p.group) / m_columnCount;

                    p.pos = n_group_row * m_columnCount + c;
                    if (p.pos >= getCellCount(p.group))
                    {
                        p.pos = getCellCount(p.group) - 1;
                    }
                }

            }
        }
        if (dir == NAV_DIR_DOWN)
        {
            p = getFocusItem();

            VfxS32 c = p.pos % m_columnCount, r = p.pos / m_columnCount;
            VfxS32 group_row = (getCellCount(p.group) - 1) / m_columnCount;

            if (r >= group_row)
            {
                p.group ++;
                if (p.group >= getGroupCount())
                {
                    p.group = getGroupCount() - 1;
                    p.pos = getCellCount(p.group) - 1;
                }
                else
                {
                    p.pos = c;
                    if (p.pos >= getCellCount(p.group))
                    {
                        p.pos = getCellCount(p.group) - 1;
                    }
                }
            }
            else
            {
                p.pos = (r + 1) * m_columnCount + c;
                if (p.pos >= getCellCount(p.group))
                {
                    p.pos = getCellCount(p.group) - 1;
                }
            }
        }
        if (dir == NAV_DIR_LEFT)
        {
            p = getFocusItem().getPrevPos(this, VFX_FALSE);
        }
        if (dir == NAV_DIR_RIGHT)
        {
            p = getFocusItem().getNextPos(this, VFX_FALSE);
        }
        if (p)
        {
            setFocusItem(p);
            return VFX_TRUE;
        }
        return VFX_FALSE;
    }

// Method
public:
    void setColumnCount(VfxS32 cnt)
    {
        m_columnCount = cnt;
        resetCache();
        update();
    }

    VfxS32 getColumnCount()
    {
        return m_columnCount;
    }

// Variable
protected:
    VfxS32 m_cellHeight;
    VfxS32 m_cellWidth;
    VfxS32 m_headerHeight;
    VfxS32 m_columnCount;
    VfxS32 m_groupGap;
    VfxS32 m_groupStartPt[4];
    
//Implementation
protected:
    VfxS32 getWholeGroupHeight(VfxS32 group)
    {
        VfxS32 row = (getCellCount(group) + m_columnCount - 1) / m_columnCount;
        return m_headerHeight + row * m_cellHeight;
    }

    VfxS32 getGroupByY(VfxS32 y)
    {
        if (y < 0) 
        {
            return 0;
        }
        for (VfxS32 i = 0; i < 3; i++)
        {
            if (y >= m_groupStartPt[i] && y < m_groupStartPt[i + 1])
                return i;
        }
        return 2;
    }
    
    void resetCache()
    {
        m_cellWidth = getViewSize().width / m_columnCount;
        m_cellHeight = getViewSize().width / m_columnCount;

        m_groupStartPt[0] = 0;
        for (VfxS32 i = 1; i < 4; i++)
        {
            m_groupStartPt[i] = m_groupStartPt[i - 1] + getWholeGroupHeight(i - 1) + m_groupGap;
        }    
    }
};

/***************************************************************************** 
 * class MyLayout2
 *****************************************************************************/

class MyLayout2 : public VcpBaseMenuLayout
{
// Constructor / Destructor
public:
    MyLayout2(VcpBaseMenu* menu) : VcpBaseMenuLayout(menu) {}
    virtual ~MyLayout2(){}

// Override
public:
    virtual void onInit()
    {
        VcpBaseMenuLayout::onInit();

        m_cellHeight = 30;
        m_itemCount = 50;
    }

    virtual ScrollDirEnum getScrollDir()
    {
        return SCROLLDIR_VERT;
    }

    virtual VfxS32 getGroupCount()
    {
        return 1;
    }
    
    virtual VfxS32 getCellCount(VfxS32 group)
    {
        if (group == 0)
            return m_itemCount;
        return 0;
    }

    virtual VfxS32 getContentLength()
    {
        return getCellCount(0) * m_cellHeight;
    }

    virtual VfxBool hasGroupHeader(VfxS32 group)
    {
        return VFX_FALSE;
    }

    virtual VcpMenuRegion queryRegion(const VfxRect& r)
    {
        return VcpMenuRegion(
            getCellByPos(r.origin),
            getCellByPos(VfxPoint(r.getMaxX(), r.getMaxY()))
        );
    }

    VcpMenuPos getCellByPos(VfxPoint pt)
    {
        VcpMenuPos p;
        
        p.group = 0;
        p.pos = pt.y / m_cellHeight;

        if (p.pos < 0)
        {
            p.pos = 0;
        }
        if (p.pos >= getCellCount(p.group))
        {
            p.pos = getCellCount(p.group) - 1;
        }
        return p;
    }    

    // Return a cell rect
    virtual VfxRect queryCellRect(VcpMenuPos pos)
    {
        VFX_DEV_ASSERT(pos.isValid());
        VFX_DEV_ASSERT(!pos.isGroupHeader());
        return VfxRect(0, pos.pos * m_cellHeight, getViewSize().width, m_cellHeight);
    }

    virtual void getPreferFocusMargin(VfxS32 margin[4])
    {
        margin[0] = m_cellHeight;
        margin[1]   = m_cellHeight;
        margin[2]  = m_cellHeight;
        margin[3] = m_cellHeight;
    }

    virtual VfxBool navDir(NavDirEnum dir)
    {
        // Igore left and right
        if (dir == NAV_DIR_LEFT || dir == NAV_DIR_RIGHT)
        {
            return VFX_FALSE;
        }

        // If there is no one is focused, we pick up one in the screen
        if (!getFocusItem().isValid())
        {
            VcpMenuPos p = getCellByPos(m_viewRect.origin);
            // we cannot focus on the header
            if (p.isGroupHeader()) 
            {
                p.pos = 0;
            }
            setFocusItem(p);
            return VFX_TRUE;
        }

        VcpMenuPos p;
        if (dir == NAV_DIR_UP)
        {
            p = getFocusItem().getPrevPos(this, VFX_FALSE);
        }
        if (dir == NAV_DIR_DOWN)
        {
            p = getFocusItem().getNextPos(this, VFX_FALSE);
        }
        if (p)
        {
            setFocusItem(p);
            return VFX_TRUE;
        }
        return VFX_FALSE;
    }

    void setItemCount(VfxS32 cnt)
    {
        if (cnt < 0)
        {
            return;
        }

        VcpMenuPos p = getFocusItem();
        m_itemCount = cnt;

        if (cnt == 0)
        {
            clearFocusItem();
        }
        else if (p.isValid() && p.pos >= cnt)
        {
            setFocusItem(VcpMenuPos(0, cnt - 1));
        }
        update();
    }

    VfxS32 getItemCount()
    {
        return m_itemCount;
    }

// Variable
protected:
    VfxS32 m_cellHeight;
    VfxS32 m_itemCount;
};

/***************************************************************************** 
 * class MyLayout3
 *****************************************************************************/

class MyLayout3 : public VcpBaseMenuLayout
{
// Constructor / Destructor
public:
    MyLayout3(VcpBaseMenu* menu) : VcpBaseMenuLayout(menu) {}
    virtual ~MyLayout3(){}

// Override
public:
    virtual void onInit()
    {
        VcpBaseMenuLayout::onInit();

        m_cellHeight = 60;
        m_itemCount = 100;
    }

    virtual ScrollDirEnum getScrollDir()
    {
        return SCROLLDIR_VERT;
    }

    virtual VfxS32 getGroupCount()
    {
        return 1;
    }
    
    virtual VfxS32 getCellCount(VfxS32 group)
    {
        if (group == 0)
            return m_itemCount;
        return 0;
    }

    virtual VfxS32 getContentLength()
    {
        return getCellCount(0) * m_cellHeight + getViewSize().height - m_cellHeight;
    }

    virtual VfxBool hasGroupHeader(VfxS32 group)
    {
        return VFX_FALSE;
    }

    virtual VcpMenuRegion queryRegion(const VfxRect& r)
    {
        return VcpMenuRegion(
            getCellByPos(r.origin),
            getCellByPos(VfxPoint(r.getMaxX(), r.getMaxY()))
        );
    }

    VcpMenuPos getCellByPos(VfxPoint pt)
    {
        VcpMenuPos p;
        VfxS32 diff = getViewSize().height - m_cellHeight;

        p.group = 0;
        p.pos = (pt.y - diff / 2) / m_cellHeight;

        if (p.pos < 0)
        {
            p.pos = 0;
        }
        if (p.pos >= getCellCount(p.group))
        {
            p.pos = getCellCount(p.group) - 1;
        }
        return p;
    }    

    // Return a cell rect
    virtual VfxRect queryCellRect(VcpMenuPos pos)
    {
        VFX_DEV_ASSERT(pos.isValid());
        VFX_DEV_ASSERT(!pos.isGroupHeader());
        VfxS32 diff = getViewSize().height - m_cellHeight;
        return VfxRect(0, pos.pos * m_cellHeight + diff/2, getViewSize().width, m_cellHeight);
    }

    virtual void getPreferFocusMargin(VfxS32 margin[4])
    {
        VfxS32 diff = getViewSize().height - m_cellHeight;
        margin[0] = 0;
        margin[1]   = diff/2;
        margin[2]  = 0;
        margin[3] = diff/2;
    }

    virtual VfxBool navDir(NavDirEnum dir)
    {
        // Igore left and right
        if (dir == NAV_DIR_LEFT || dir == NAV_DIR_RIGHT)
        {
            return VFX_FALSE;
        }

        // If there is no one is focused, we pick up one in the screen
        if (!getFocusItem().isValid())
        {
            VcpMenuPos p = getCellByPos(VfxPoint(m_viewRect.getMidX(), m_viewRect.getMidY()));
            // we cannot focus on the header
            if (p.isGroupHeader()) 
            {
                p.pos = 0;
            }
            setFocusItem(p);
            return VFX_TRUE;
        }

        VcpMenuPos p;
        if (dir == NAV_DIR_UP)
        {
            p = getFocusItem().getPrevPos(this, VFX_FALSE);
        }
        if (dir == NAV_DIR_DOWN)
        {
            p = getFocusItem().getNextPos(this, VFX_FALSE);
        }
        if (p)
        {
            setFocusItem(p);
            return VFX_TRUE;
        }
        return VFX_FALSE;
    }

// Variable
protected:
    VfxS32 m_cellHeight;
    VfxS32 m_itemCount;
};

/***************************************************************************** 
 * class MyLayout4
 *****************************************************************************/

#define HUGE_ITEM_COUNT 2000000
#define HUGE_ITEM_COUNT_BEGIN 1000000

class MyLayout4 : public VcpBaseMenuLayout
{
// Constructor / Destructor
public:
    MyLayout4(VcpBaseMenu* menu) : VcpBaseMenuLayout(menu) {}
    virtual ~MyLayout4(){}

// Override
public:
    virtual void onInit()
    {
        VcpBaseMenuLayout::onInit();

        m_cellHeight = 60;
    }

    virtual ScrollDirEnum getScrollDir()
    {
        return SCROLLDIR_VERT;
    }

    virtual VfxS32 getGroupCount()
    {
        return 1;
    }
    
    virtual VfxS32 getCellCount(VfxS32 group)
    {
        return HUGE_ITEM_COUNT;
    }

    virtual VfxS32 getContentLength()
    {
        return getCellCount(0) * m_cellHeight; 
    }

    virtual VfxBool hasGroupHeader(VfxS32 group)
    {
        return VFX_FALSE;
    }

    virtual VcpMenuRegion queryRegion(const VfxRect& r)
    {
        return VcpMenuRegion(
            getCellByPos(r.origin),
            getCellByPos(VfxPoint(r.getMaxX(), r.getMaxY()))
        );
    }

    VcpMenuPos getCellByPos(VfxPoint pt)
    {
        VcpMenuPos p;
        VfxS32 diff = getViewSize().height - m_cellHeight;

        p.group = 0;
        p.pos = (pt.y - diff / 2) / m_cellHeight;

        if (p.pos < 0)
        {
            p.pos = 0;
        }
        if (p.pos >= getCellCount(p.group))
        {
            VFX_DEV_ASSERT(0); // it is impossible
            p.pos = getCellCount(p.group) - 1;
        }
        return p;
    }    

    // Return a cell rect
    virtual VfxRect queryCellRect(VcpMenuPos pos)
    {
        VFX_DEV_ASSERT(pos.isValid());
        VFX_DEV_ASSERT(!pos.isGroupHeader());
        VfxS32 diff = getViewSize().height - m_cellHeight;
        return VfxRect(0, pos.pos * m_cellHeight + diff/2, getViewSize().width, m_cellHeight);
    }

    virtual void getPreferFocusMargin(VfxS32 margin[4])
    {
        VfxS32 diff = getViewSize().height - m_cellHeight;
        margin[0] = 0;
        margin[1] = diff/2;
        margin[2] = 0;
        margin[3] = diff/2;
    }

    virtual void onStopPosFix(VfxPoint& pos)
    {
        VfxPoint prePos = pos;
        VfxS32 diff = getViewSize().height - m_cellHeight;
        VfxPoint mid = pos;
        mid.x += getViewSize().width/2;
        mid.y += getViewSize().height/2;

        VcpMenuPos p = getCellByPos(mid);
        
        VfxRect r = queryCellRect(p);

        pos.y = r.origin.y - diff/2;
        
        VFX_TRACE(("onStopPosFix(%d, %d)->(%d, %d)\n", prePos.x, prePos.y, pos.x, pos.y));
    }

    virtual VfxBool navDir(NavDirEnum dir)
    {
        // Igore left and right
        if (dir == NAV_DIR_LEFT || dir == NAV_DIR_RIGHT)
        {
            return VFX_FALSE;
        }

        // If there is no one is focused, we pick up one in the screen
        if (!getFocusItem().isValid())
        {
            VcpMenuPos p = getCellByPos(VfxPoint(m_viewRect.getMidX(), m_viewRect.getMidY()));
            // we cannot focus on the header
            if (p.isGroupHeader()) 
            {
                p.pos = 0;
            }
            setFocusItem(p);
            return VFX_TRUE;
        }

        VcpMenuPos p;
        if (dir == NAV_DIR_UP)
        {
            p = getFocusItem().getPrevPos(this, VFX_FALSE);
        }
        if (dir == NAV_DIR_DOWN)
        {
            p = getFocusItem().getNextPos(this, VFX_FALSE);
        }
        if (p)
        {
            setFocusItem(p);
            return VFX_TRUE;
        }
        return VFX_FALSE;
    }

// Variable
protected:
    VfxS32 m_cellHeight;
};


/***************************************************************************** 
 * Color
 *****************************************************************************/


static const VfxU32 g_colorlst[] = {
    //VRT_COLOR_WHITE,
    VRT_COLOR_RED,
    VRT_COLOR_GREEN,
    VRT_COLOR_BLUE,
    VRT_COLOR_AQUA,
    VRT_COLOR_FUCHSIA,
    VRT_COLOR_YELLOW,
    VRT_COLOR_GREY,
    VRT_COLOR_TEAL,
    VRT_COLOR_PURPLE,
    VRT_COLOR_OLIVE,
    VRT_COLOR_SILVER,
};
#define GCOLORCNT (sizeof(g_colorlst) / sizeof(g_colorlst[0]))

static VfxS32 g_color_idx = 0;

static VfxColor VtstPickupColor(VfxS32 index = -1)
{
    if (index == -1)
    {
        index = g_color_idx++;
    }
    return VfxColor(g_colorlst[index % GCOLORCNT]);
}

/***************************************************************************** 
 * Class VcpMyMenu
 *****************************************************************************/

class VcpMyMenu : public VcpBaseMenu
{
    class MyCell : public VfxControl
    {
        // This control is the dragable thumb control.
        class CellThumb : public VfxControl
        {
        public:
            MyCell* getCell()
            {
                return (MyCell*)getParentControl();
            }
            virtual void onInit()
            {
                VfxControl::onInit();
                setBgColor(VfxColor(255, 160, 160, 160));  
                setAutoAnimate(VFX_TRUE);                
            }
            virtual VfxBool onPenInput(VfxPenEvent &event)
            {
                switch (event.type)
                {
                    case VFX_PEN_EVENT_TYPE_DOWN:
                        getCell()->onCellDrag(event);
                        return VFX_TRUE;
                    case VFX_PEN_EVENT_TYPE_MOVE:
                        getCell()->onCellMove(event);
                        return VFX_TRUE;
                    case VFX_PEN_EVENT_TYPE_UP:
                    case VFX_PEN_EVENT_TYPE_ABORT:
                        getCell()->onCellDrop(event);
                        return VFX_TRUE;
                };
                return VfxControl::onPenInput(event);
            }
        };
       

        VfxTextFrame     *m_textFrame;
        VfxFloatTimeline *m_timeline1;
        VfxSizeTimeline  *m_timeline3;
        VfxBool          m_highlight;
        CellThumb        *m_dragThumb;
        VfxS32           m_group, m_pos;
        VfxBool          m_dragging;
        VfxPoint         m_dragPt;
        VfxTimer         *m_withdrawTimer;
        VfxBool          m_hasColor;


    public:

        VcpMyMenu* getMenu()
        {
            if (getParentFrame() && getParentFrame()->getParentFrame())
                return (VcpMyMenu*) getParentFrame()->getParentFrame();
            return NULL;
        }

        void onCellDrag(VfxPenEvent &event)
        {
            m_dragging = VFX_TRUE;
            m_dragPt = event.getRelDownPos(this);

            bringToFront();
        }

        void onCellMove(VfxPenEvent &event)
        {
            VfxPoint p = event.getRelPos(this);
            VfxPoint parentPt = getParentFrame()->convertPointFrom(p, this);
            VfxSize sz = getBounds().size;
            
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
            
            setPos(VfxPoint(parentPt.x - m_dragPt.x + sz.width/2, parentPt.y - m_dragPt.y + sz.height/2));

            VfxAutoAnimate::commit();
            
            getMenu()->startDragCell(getMenuPos(), this);
        }

        void onCellDrop(VfxPenEvent &event)
        {
            getMenu()->endDragCell(getMenuPos(), this);
            m_dragging = VFX_FALSE;
        }

        VcpMenuPos getMenuPos()
        {
            VcpMyMenu* pMenu = getMenu();

            VcpMenuRegionIter itr(pMenu, pMenu->getRealContentRegion());
            while(!itr.isEnd())
            {
                VcpMenuPos p = itr.next();
                
                if (p.isGroupHeader())
                {
                    if (pMenu->getHeaderIfPresent(p.group) == this)
                        return p;
                }
                else
                {
                    if (pMenu->getCellIfPresent(p.group, p.pos) == this)
                        return p;
                }
            }
            // The menu item is not in menu anymore, maybe remove from menu
            return VcpMenuPos();
        }

        virtual void onInit()
        {
            VfxControl::onInit();

            sendToBack();
            setOpacity(0);
            setAnchor(VfxFPoint(0.5, 0.5));
            setBorderColor(VRT_COLOR_WHITE);
            setBorderWidth(1);
            setIsCached(VFX_TRUE);
            setIsOpaque(VFX_TRUE);
            m_hasColor = VFX_FALSE;

            m_dragThumb = NULL;
            m_highlight = VFX_FALSE;
            m_dragging = VFX_FALSE;

            VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);
            m_textFrame->setPos(VfxPoint(0, 0));
            m_textFrame->setColor(VFX_COLOR_WHITE);
            m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
            m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
            
            VFX_OBJ_CREATE(m_timeline1, VfxFloatTimeline, this);
            m_timeline1->setTarget(this);
            m_timeline1->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
            m_timeline1->setDurationTime(250);

            VFX_OBJ_CREATE(m_timeline3, VfxSizeTimeline, this);
            m_timeline3->setTarget(this);
            m_timeline3->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BOUNDS_SIZE);
            m_timeline3->setDurationTime(250);
            
            VFX_OBJ_CREATE(m_withdrawTimer, VfxTimer, this);
            m_withdrawTimer->setStartDelay(300);
            m_withdrawTimer->m_signalTick.connect(this, &MyCell::onWithdrawTimerCB);            

            setAutoAnimate(VFX_TRUE);
        }
        virtual void onDeinit()
        {
            m_timeline1->stop();
            m_timeline3->stop();
            VfxControl::onDeinit();
        }
        void setHighlight(VfxBool isHighLight, VfxBool isAnim)
        {
            m_highlight = isHighLight;
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(!isAnim);

            if (m_highlight)
            {
                setBorderWidth(5);
            }
            else
            {
                setBorderWidth(1);
            }            
            VfxAutoAnimate::commit();

            checkUpdate();
        }

        void onUpdate()
        {
            if (!m_hasColor)
            {
                m_hasColor = VFX_TRUE;
                VcpMenuPos p = getMenuPos();
                setBgColor(VtstPickupColor(p.group * 1000 + p.pos + 2000));
            }
        }

        void enter(const VfxRect& r, VfxBool animation, VfxS32 delay)
        {
            if (animation)
            {
                // set the position without animation
                // But timeline will not be affect
                updatePos(r, VFX_FALSE);

                m_timeline1->setStartTime(delay);
                m_timeline1->setToValue(1.0f);
                m_timeline1->setFromValue(0.0f);
                m_timeline1->setToValue(1.0f);
                m_timeline1->start();

                m_timeline3->setStartTime(delay);
                m_timeline3->setFromValue(VfxSize(0, 0));
                m_timeline3->setToValue(r.size);
                m_timeline3->start();
            }
            else
            {
                updatePos(r, VFX_FALSE);
                setOpacity(1.0f);
            }
        }

        void onWithdrawTimerCB(VfxTimer *source)
        {
            MyCell* _this = this;
            VFX_OBJ_CLOSE(_this);
        }

        void withdraw()
        {
            VfxPoint pt = getPos();
            pt.x += 300;
            setPos(pt);
            setOpacity(0);
            m_withdrawTimer->start();
        }

        void leave(const VfxRect& r)
        {
            m_timeline1->stop();
            m_timeline1->setStartTime(0);
            m_timeline1->setFromValue(1.0f);
            m_timeline1->setToValue(0.0f);
            m_timeline1->start();

            m_timeline3->stop();
            m_timeline3->setStartTime(0);
            m_timeline3->setFromValue(r.size);
            m_timeline3->setToValue(VfxSize(0, 0));
            m_timeline3->start();
        }

        void updatePos(const VfxRect& r, VfxBool isAnim)
        {
            if (m_dragging)
                return;

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(!isAnim);

            setPos(VfxPoint(r.getMidX(), r.getMidY()));
            setBounds(VfxRect(VfxPoint(0, 0), r.size));

            VfxAutoAnimate::commit();
        }
        void adjustPos(const VfxRect &value)
        {
            m_textFrame->setBounds(VfxRect(0, 0, value.size.width, value.size.height));
            if (m_dragThumb)
            {
                m_dragThumb->setPos(VfxPoint(value.size.width - value.size.height, 0));
                m_dragThumb->setBounds(VfxRect(0, 0, value.size.height, value.size.height));
            }
        }
        virtual void setBounds(const VfxRect &value)
        {
            VfxControl::setBounds(value);
            adjustPos(value);
        }
        void setCaption(const VfxWString& string)
        {
            m_textFrame->setString(string);
        }
        void setTextVisible(VfxBool visible)
        {
            m_textFrame->setHidden(!visible);
        }
        void setDragable(VfxBool dragable)
        {
            if (dragable)
            {
                if (m_dragThumb == NULL)
                {
                    VFX_OBJ_CREATE(m_dragThumb, CellThumb, this);
                    adjustPos(getBounds());
                }
            }
            else
            {
                VFX_OBJ_CLOSE(m_dragThumb);
            }
        }
        void click()
        {
            if (m_highlight)
            {
                VcpMyMenu* menu = (VcpMyMenu*) getParentControl()->getParentControl();
                menu->nextStyle();
            }
        }
    };
    class MyHeader : public MyCell
    {
    public:
        virtual void onInit()
        {
            MyCell::onInit();
        }
    };


// Constructor / Destructor
public:
    VcpMyMenu(){}
    virtual ~VcpMyMenu(){}

// Override
public:
    virtual void onInit()
    {
        m_isSupportTransition = VFX_TRUE;
        m_cellTextVisible = VFX_FALSE;
        m_testStyle = 0;
        m_firstPos = 0;
        m_dragMode = VFX_FALSE;
        m_delayTicks = 0;
        
        VcpBaseMenu::onInit();
    }

    void nextStyle()
    {
        m_testStyle++;
        m_dragMode = VFX_FALSE;
        reset();
    }

    virtual VcpBaseMenuLayout* createLayout()
    {
        if (m_testStyle % LAYOUT_TEST_COUNT == 0)
        {
            MyLayout* layout;
            VFX_OBJ_CREATE_EX(layout, MyLayout, this, (this));
            return layout;
        }
        else if (m_testStyle % LAYOUT_TEST_COUNT == 1)
        {
            MyLayout2* layout;
            VFX_OBJ_CREATE_EX(layout, MyLayout2, this, (this));
            return layout;
        }
        else if (m_testStyle % LAYOUT_TEST_COUNT == 2)
        {
            MyLayout3* layout;
            VFX_OBJ_CREATE_EX(layout, MyLayout3, this, (this));
            layout->setFocusItem(VcpMenuPos(0, 0));
            return layout;
        }
        else if (m_testStyle % LAYOUT_TEST_COUNT == 3)
        {
            MyLayout4* layout;
            VFX_OBJ_CREATE_EX(layout, MyLayout4, this, (this));
            return layout;
        }
        return NULL;
    }

    virtual void onAfterCreateLayout()
    {
        // Move the view port to center of whole space
        if (m_testStyle % LAYOUT_TEST_COUNT == 3)
        {
            makeVisible(VcpMenuPos(0, HUGE_ITEM_COUNT_BEGIN), VFX_FALSE);
        }
    }

    virtual VfxFrame* createGroupHeader(VfxS32 group)
    {
        MyHeader* item;
        VFX_OBJ_CREATE(item, MyHeader, this);

        VfxWChar caption[40] = {0};
        kal_wsprintf(caption, "(Group %d)", group);
        item->setCaption(VFX_WSTR_MEM(caption));
        item->setTextVisible(m_cellTextVisible);
        item->setHighlight(VFX_FALSE, VFX_FALSE);

        if (m_delayTicks)
        {
            kal_sleep_task(m_delayTicks);
        }

        return item;
    }

    virtual VfxFrame* createCell(VfxS32 group, VfxS32 pos)
    {
        MyCell* item;
        VFX_OBJ_CREATE(item, MyCell, this);

        VfxWChar caption[40] = {0};
        if (m_testStyle % LAYOUT_TEST_COUNT == 3)
        {
            // This is circular menu, so we need to fix position
            VfxS32 itemCount = 11;
            VfxS32 realPos = (((pos - HUGE_ITEM_COUNT_BEGIN) % itemCount) + itemCount) % itemCount;
            kal_wsprintf(caption, "%d", realPos);
        }
        else
        {
            kal_wsprintf(caption, "(%d, %d)", group, pos);
        }
        item->setCaption(VFX_WSTR_MEM(caption));
        item->setTextVisible(m_cellTextVisible);
        item->setHighlight(VFX_FALSE, VFX_FALSE);

        if (getLayout()->getFocusItem() == VcpMenuPos(group, pos))
        {
            item->setHighlight(VFX_TRUE, VFX_TRUE);
        }

        // Set cell into drag mode if we are in drag mode
        item->setDragable(m_dragMode);

        if (m_delayTicks)
        {
            kal_sleep_task(m_delayTicks);
        }

        return item;
    }
    
    virtual void onCloseGroupHeader(VfxS32 group, VfxFrame* groupFrame)
    {
        VFX_OBJ_CLOSE(groupFrame);
    }
    
    virtual void onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame)
    {
        VFX_OBJ_CLOSE(cellFrame);
    }
    
    virtual void onUpdateGroupHeader(const VfxRect &rect, VfxS32 group, VfxFrame* header, VfxU32 flag)
    {
        MyHeader* item = (MyHeader*) header;

        if (flag & VCP_CELL_FLAG_FIRSTINIT)
        {
            if (flag & VCP_CELL_FLAG_OPENING)
            {
                item->enter(rect, VFX_TRUE, 0);
            }
            else
            {
                item->enter(rect, VFX_FALSE, 0);
            }
        }
        else if (flag & VCP_CELL_FLAG_CLOSING)
        {
            item->leave(rect);
        }
        else if (flag & VCP_CELL_FLAG_FORCESET)
        {
            item->updatePos(rect, VFX_FALSE);
        }
        else
        {
            item->updatePos(rect, VFX_TRUE);
        }
    }

    virtual void onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem)
    {
        if (previousFocusItem.isValid() && !previousFocusItem.isGroupHeader())
        {
            MyCell* item = (MyCell*) getCellIfPresent(previousFocusItem.group, previousFocusItem.pos);
            if (item)
            {
                item->setHighlight(VFX_FALSE, VFX_TRUE);
            }
        }
        if (focusItem.isValid() && !focusItem.isGroupHeader())
        {
            MyCell* item = (MyCell*) getCellIfPresent(focusItem.group, focusItem.pos);
            if (item)
            {
                item->setHighlight(VFX_TRUE, VFX_TRUE);
            }
        }
    }

    virtual void onBeforeUpdate(
        const VcpMenuRegion& currentRegion,
        const VcpMenuRegion& targetRegion
    )
    {
        m_firstPos = currentRegion.begin.pos;
    }

    struct FramePropertyEffectData
    {
        VfxS32  group;
        VfxS32  pos;
        VfxRect r;
    };

    static vrt_render_dirty_type_enum framePropertyEffectCallback(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size)
    {
        VFX_DEV_ASSERT(target_frame != NULL);
        VFX_DEV_ASSERT(watch_frame != NULL);
        VFX_DEV_ASSERT(user_data != NULL && user_data_size == sizeof(FramePropertyEffectData));
        FramePropertyEffectData* data = (FramePropertyEffectData*)user_data;

        // define the radio of the circule
        const VfxS32 radio = 300;

        // offset is the distance between cell center and view center                
        VfxS32 offset = target_frame->pos.y - (watch_frame->bounds.origin.y + watch_frame->bounds.size.height/2);
        
        // backup the original value
        VfxS32 org = target_frame->pos.x;
        
        // caculate the X offset
        target_frame->pos.x = 
            (data->r.size.width / 2) +
            radio - vfxSqrt(radio*radio - offset*offset);

        // return whether the frame is dirty
        return (org != target_frame->pos.x) ? VRT_RENDER_DIRTY_TYPE_DIRTY : VRT_RENDER_DIRTY_TYPE_NONE;
    }

    virtual void onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag)
    {
        MyCell* item = (MyCell*) cell;

        VfxRect r = rect;
        r.origin.x += 1;
        r.origin.y += 1;
        r.size.width -= 2;
        r.size.height -= 2;

        if (flag & VCP_CELL_FLAG_FIRSTINIT)
        {
            if (flag & VCP_CELL_FLAG_OPENING)
            {
                item->enter(r, VFX_TRUE, (pos - m_firstPos) * 50);
            }
            else
            {
                item->enter(r, VFX_FALSE, 0);
            }
        }
        else if (flag & VCP_CELL_FLAG_CLOSING)
        {
            item->leave(r);
        }
        else if (flag & VCP_CELL_FLAG_FORCESET)
        {
            item->updatePos(r, VFX_FALSE);
        }
        else
        {
            item->updatePos(r, VFX_TRUE);
        }

        if (m_testStyle % LAYOUT_TEST_COUNT == 3)
        {
            if (flag & VCP_CELL_FLAG_FIRSTINIT)
            {
                FramePropertyEffectData data;
                data.group = group;
                data.pos = pos;
                data.r = rect;

                cell->setPropertyEffectCallback(
                    m_view,
                    &VcpMyMenu::framePropertyEffectCallback, 
                    &data,
                    sizeof(data));
            }
        }
    }

    virtual void onTapGroupHeader(VfxS32 group, VfxFrame* groupObject)
    {
        MyHeader* item = (MyHeader*) groupObject;
        item->click();
    }
    
    virtual void onTapCell(VfxS32 group, VfxS32 pos, VfxFrame* cell)
    {
        MyCell* item = (MyCell*) cell;
        item->click();
        
        getLayout()->setFocusItem(VcpMenuPos(group, pos));
    }

    void setCellTextVisible(VfxBool visible)
    {
        VcpMenuRegionIter itr(this, getRealContentRegion());
        while(!itr.isEnd())
        {
            VcpMenuPos p = itr.next();
            if (p.isGroupHeader())
            {
                MyHeader* header = (MyHeader*)getHeaderIfPresent(p.group);
                if (header)
                {
                    header->setTextVisible(visible);
                }                
            }
            else
            {
                MyCell* cell = (MyCell*)getCellIfPresent(p.group, p.pos);
                if (cell)
                {
                    cell->setTextVisible(visible);
                }
            }
        }
    }

    void setCellDragMode(VfxBool dragMode)
    {
        m_dragMode = dragMode;

        VcpMenuRegionIter itr(this, getRealContentRegion());
        while(!itr.isEnd())
        {
            VcpMenuPos p = itr.next();
            if (!p.isGroupHeader())
            {
                MyCell* cell = (MyCell*)getCellIfPresent(p.group, p.pos);
                if (cell)
                {
                    cell->setDragable(m_dragMode);
                }
            }
        }
    }

    VfxBool onKeyInput(VfxKeyEvent &event)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            if (event.keyCode == VFX_KEY_CODE_CAMERA)
            {
                m_cellTextVisible = !m_cellTextVisible;
                setCellTextVisible(m_cellTextVisible);
                return VFX_TRUE;
            }
            if (event.keyCode == VFX_KEY_CODE_VOL_UP)
            {
                if (m_testStyle % LAYOUT_TEST_COUNT == 0)
                {
                    MyLayout* layout = (MyLayout*)getLayout();
                    VfxS32 cnt = layout->getColumnCount();
                    if (cnt > 1)
                    {
                        layout->setColumnCount(cnt - 1);
                    }
                    return VFX_TRUE;
                }
                else if (m_testStyle % LAYOUT_TEST_COUNT == 1)
                {
                    MyLayout2* layout = (MyLayout2*)getLayout();
                    VfxS32 cnt = layout->getItemCount();
                    layout->setItemCount(cnt + 10);
                    return VFX_TRUE;
                }
            }
            if (event.keyCode == VFX_KEY_CODE_VOL_DOWN)
            {
                if (m_testStyle % LAYOUT_TEST_COUNT == 0)
                {
                    MyLayout* layout = (MyLayout*)getLayout();
                    VfxS32 cnt = layout->getColumnCount();
                    if (cnt < 3)
                    {
                        layout->setColumnCount(cnt + 1);
                    }
                    return VFX_TRUE;
                }
                else if (m_testStyle % LAYOUT_TEST_COUNT == 1)
                {
                    MyLayout2* layout = (MyLayout2*)getLayout();
                    VfxS32 cnt = layout->getItemCount();
                    layout->setItemCount(cnt - 10);
                    return VFX_TRUE;
                }
            }
            if (event.keyCode == VFX_KEY_CODE_1)
            {
                VcpMenuPos p1 = getLayout()->getFocusItem();
                VcpMenuPos p2 = p1.getNextPos(getLayout(), VFX_FALSE);

                getLayout()->clearFocusItem();

                if (p1.isValid() && p2.isValid())
                {
                    swapCell(p1, p2);
                }
            }
            if (event.keyCode == VFX_KEY_CODE_2)
            {
                setCellDragMode(!m_dragMode);
            }
            if (event.keyCode == VFX_KEY_CODE_4)
            {
                m_delayTicks += 10;
            }
            if (event.keyCode == VFX_KEY_CODE_5)
            {
                m_delayTicks -= 10;
                if (m_delayTicks < 0)
                    m_delayTicks = 0;
            }
            if (event.keyCode == VFX_KEY_CODE_6)
            {
                VcpMenuPos p = getLayout()->getFocusItem();
                MyCell* cell = (MyCell*) pullOutCell(p);
                if (cell)
                {
                    cell->withdraw();
                    withdrawCell(p.group, p.pos);
                }
                return VFX_TRUE;
            }
            if (event.keyCode == VFX_KEY_CODE_7)
            {
                VcpMenuPos p = getLayout()->getFocusItem();
                if (p.isValid())
                {
                    putinCell(p.group, p.pos);
                }
                return VFX_TRUE;
            }
            if (event.keyCode == VFX_KEY_CODE_9)
            {
                m_isSupportTransition = !m_isSupportTransition;
            }
        }
        return VcpBaseMenu::onKeyInput(event);
    }

    virtual void onDragStart()
    {
        VFX_TRACE(("onDragStart\n"));;
        VcpBaseMenu::onDragStart();
    }

    virtual void onDragEnd()
    {
        VFX_TRACE(("onDragEnd\n"));;
        VcpBaseMenu::onDragEnd();

        if (m_testStyle % LAYOUT_TEST_COUNT == 2)
        {
            getLayout()->navDir(VcpBaseMenuLayout::NAV_DIR_NONE);
        }
        else if (m_testStyle % LAYOUT_TEST_COUNT == 3)
        {
            getLayout()->navDir(VcpBaseMenuLayout::NAV_DIR_NONE);
        }

        VFX_TRACE(("Real: (%d, %d), Bounds:(%d, %d)\n", 
            m_view->forceGetBounds().origin.x, 
            m_view->forceGetBounds().origin.y, 
            m_view->getBounds().origin.x, 
            m_view->getBounds().origin.y
        ));
    }

    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset)
    {
        VFX_TRACE(("onDrag: %d %d\n", xoffset, yoffset));;
        getLayout()->clearFocusItem();
    }

    void startDragCell(VcpMenuPos pos, VfxFrame* dragCell)
    {
        getLayout()->clearFocusItem();

        VfxS32     minDistance = 1000 * 1000 + 1000 * 1000; // Set a max distance
        VcpMenuPos pointCell;

        VfxS32 cx = dragCell->getPos().x + VfxS32(dragCell->getBounds().size.width * (0.5f - dragCell->getAnchor().x));
        VfxS32 cy = dragCell->getPos().y + VfxS32(dragCell->getBounds().size.height * (0.5f - dragCell->getAnchor().y));

        VcpMenuRegionIter itr(this, getRealContentRegion());
        while(!itr.isEnd())
        {
            VcpMenuPos p = itr.next();

            if (!p.isGroupHeader())
            {
                VfxRect r = getLayout()->queryCellRect(p);                
                VfxS32 x = r.getMidX();
                VfxS32 y = r.getMidY();
                VfxS32 distance = VFX_ABS(cx - x) * VFX_ABS(cx - x) + VFX_ABS(cy - y) * VFX_ABS(cy - y);

                if (minDistance > distance)
                {
                    minDistance = distance;
                    pointCell = p;
                }
            }
        }
        if (pointCell.isValid() && pointCell != pos)
        {
            swapCell(pointCell, pos);
            makeVisible(pointCell);
            makeVisible(pos);
        }
    }

    void endDragCell(VcpMenuPos pos, VfxFrame* dragCell)
    {
        updateLayout();
    }

    virtual VfxBool IsSupportTransition()
    {
        return m_isSupportTransition;
    }

// Variable
protected:
    VfxS32  m_firstPos;
    VfxS32  m_testStyle;
    VfxBool m_cellTextVisible;
    VfxBool m_dragMode;
    VfxS32  m_delayTicks; // this is for simulate if create cell is very slow
    VfxBool m_isSupportTransition;
};

class VtstRtMenu : public VtstRtScr
{
// Variable
public:
    VcpMyMenu *m_menu;

// Constructor / Destructor
public:
    VtstRtMenu() : m_menu(NULL) {}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("Menu Test"));

        // scrollable body
        VFX_OBJ_CREATE(m_menu, VcpMyMenu, this);
        
        m_menu->setPos(VfxPoint(10, 50));
        m_menu->setBounds(VfxRect(0, 0, 220, 260));
        m_menu->setBgColor(VFX_COLOR_BLACK);
        m_menu->setFocused(VFX_TRUE);
    }

    virtual int start()
    {      
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }
};

VtstTestResultEnum vtst_rt_menu(VfxU32 param)
{
    VTST_START_SCRN(VtstRtMenu);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__
