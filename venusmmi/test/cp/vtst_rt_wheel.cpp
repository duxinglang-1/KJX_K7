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
 *  vtst_rt_wheel.cpp
 *
 * Project:
 * --------
 *  Venus Regression Test for wheel menu
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

#include "vcp_wheel_menu.h"
#include "vtst_rt_main.h"
#include "vfx_basic_type.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vfx_control.h"
#include "vfx_text_frame.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_auto_animate.h"
#include "vfx_string.h"
#include "vfx_frame.h"
#include "vfx_input_event.h"
#include "vfx_app_cat_scr.h"

/***************************************************************************** 
 * Wheel Menu Test Implementation
 *****************************************************************************/

#define CELL_ITEM_HEIGHT 60

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
 * Class VcpMyWheelMenu
 *****************************************************************************/

class MyWheelMenu : public VcpWheelMenu
{
    typedef MyWheelMenu       Self;
    typedef VcpWheelMenu    Super;

    class MyCell : public VfxControl
    {
        VfxTextFrame     *m_textFrame;
        VfxBool          m_highlight;

    public:

        MyWheelMenu* getMenu()
        {
            if (getParentFrame())
                return (MyWheelMenu*) getParentFrame();
            return NULL;
        }

        // TODO:
        VfxS32 getMenuPos()
        {
            return 0;
        }

        virtual void onInit()
        {
            VfxControl::onInit();

            VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);
            m_textFrame->setPos(VfxPoint(0, 0));
            m_textFrame->setColor(VFX_COLOR_WHITE);
            m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
            m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);            

            sendToBack();
            setOpacity(1.0f);
            setAnchor(VfxFPoint(0.5, 0.5));
            setBorderColor(VRT_COLOR_WHITE);
            setBorderWidth(1);
            setIsCached(VFX_TRUE);
            setIsOpaque(VFX_TRUE);
            setRect(VfxRect(0, 0, 200, CELL_ITEM_HEIGHT));

            m_highlight = VFX_FALSE;

            setAutoAnimate(VFX_TRUE);
        }
        virtual void onDeinit()
        {
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

        virtual void onUpdate()
        {
        }

        void adjustPos(const VfxRect &value)
        {
            m_textFrame->setBounds(VfxRect(0, 0, value.size.width, value.size.height));
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
        void click()
        {
            VfxColor color = getBgColor();
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
            setBgColor(0xFFFFFFFF);
            VfxAutoAnimate::commit();
            setBgColor(color);
        }
    };


// Constructor / Destructor
public:
    MyWheelMenu() : m_cells(NULL), m_removedFrame(NULL) {}
    virtual ~MyWheelMenu() {}

// Override
public:
    virtual void onInit()
    {       
        Super::onInit();
        m_cellTextVisible = VFX_FALSE;
        m_cells = NULL;
    }

    virtual void onDeinit()
    {
        if (m_cells)
        {
            VFX_FREE_MEM(m_cells);
            m_cells = NULL;
        }
        Super::onDeinit();
    }

    virtual VfxS32 getSubCellCount()
    {
        return 2;
    }

    virtual VfxFrame* createCell(VfxS32 cell, VfxS32 subcell)
    {
        VfxFrame* frame = NULL;
        if (subcell == 0)
        {
            MyCell* item;
            VFX_OBJ_CREATE(item, MyCell, this);

            VfxWChar caption[40] = {0};
            kal_wsprintf(caption, "(%d)", m_cells[cell]);
            item->setCaption(VFX_WSTR_MEM(caption));
            item->setTextVisible(m_cellTextVisible);
            item->setHighlight(VFX_FALSE, VFX_FALSE);

            item->setBgColor(VtstPickupColor(1000 + m_cells[cell]));

            if (getFocus() == cell)
            {
                item->setHighlight(VFX_TRUE, VFX_TRUE);
            }
            frame = item;
        }
        else
        {
            VfxTextFrame* textframe;
            VFX_OBJ_CREATE(textframe, VfxTextFrame, this);

            VfxWChar caption[40] = {0};
            kal_wsprintf(caption, "(%d)", m_cells[cell]);

            textframe->setString(VFX_WSTR_MEM(caption));

            frame = textframe;
        }
        return frame;
    }
    
    virtual void onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* frame)
    {
        if (cell == getFocus())
        {
            frame->bringToFront();
        }
    }

    virtual void onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame)
    {
        VFX_OBJ_CLOSE(cellFrame);
    }
    
    virtual void onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem)
    {
        if (VCP_WHEELMENU_IS_VALID_INDEX(previousFocusItem))
        {
            MyCell* item = (MyCell*) getCellIfPresent(previousFocusItem);
            if (item)
            {
                item->setHighlight(VFX_FALSE, VFX_TRUE);
            }
        }
        if (VCP_WHEELMENU_IS_VALID_INDEX(focusItem))
        {
            MyCell* item = (MyCell*) getCellIfPresent(focusItem);
            if (item)
            {
                item->setHighlight(VFX_TRUE, VFX_TRUE);
            }
        }
    }

    void setCellTextVisible(VfxBool visible)
    {
        for (VfxS32 p = getFirstVisibleIndex(); p < getLastVisibleIndex(); p++)
        {
            MyCell* cell = (MyCell*)getCellIfPresent(p);
            if (cell)
            {
                cell->setTextVisible(visible);
            }
        }
    }

    virtual VfxBool onKeyInput(VfxKeyEvent &event)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            if (event.keyCode == VFX_KEY_CODE_ARROW_UP)
            {
                setFocus(getFocus() - 1);
                return VFX_TRUE;
            }
            if (event.keyCode == VFX_KEY_CODE_ARROW_DOWN)
            {
                setFocus(getFocus() + 1);
                return VFX_TRUE;
            }
            if (event.keyCode == VFX_KEY_CODE_CAMERA)
            {
                m_cellTextVisible = !m_cellTextVisible;
                setCellTextVisible(m_cellTextVisible);
                return VFX_TRUE;
            }
            if (event.keyCode == VFX_KEY_CODE_VOL_UP)
            {
                return VFX_TRUE;
            }
            if (event.keyCode == VFX_KEY_CODE_VOL_DOWN)
            {
                return VFX_TRUE;
            }
            if (event.keyCode == VFX_KEY_CODE_1)
            {
                resetCell(getFocus());
                return VFX_TRUE;
            }
            if (event.keyCode == VFX_KEY_CODE_2 || event.keyCode == VFX_KEY_CODE_3)
            {
                if (m_removedFrame)
                {
                    VFX_OBJ_CLOSE(m_removedFrame);
                }
                    
                m_removedFrame = pullOutSubCell(getFocus(), 0);
                if (m_count > 0)
                {
                    for (VfxS32 i = getFocus(); i < m_count - 1; i++)
                    {
                        m_cells[i] = m_cells[i + 1];
                    }
                    m_count--;
                }
                withdrawCell(getFocus(), event.keyCode == VFX_KEY_CODE_2);

                if (m_removedFrame)
                {
                    m_removedFrame->setAutoAnimate(VFX_TRUE);
                    m_removedFrame->setOpacity(0);
                    VfxPoint pt = m_removedFrame->getPos();
                    VfxSize sz = m_removedFrame->getSize();
                    m_removedFrame->setPos(-sz.width, pt.y);
                }

                return VFX_TRUE;
            }
            if (event.keyCode == VFX_KEY_CODE_4)
            {
            }
            if (event.keyCode == VFX_KEY_CODE_5)
            {
            }
        }
        return Super::onKeyInput(event);
    }

    virtual void onDragStart() {}

    virtual void onDragEnd(VfxS32 xspeed, VfxS32 yspeed)
    {
        if (yspeed == 0)
        {
            setFocus(VfxS32(getScrollIndex() + 0.5f));
        }
        else
        {
            VfxS32   s      = yspeed > 0 ? 1 : -1;
            VfxFloat m      = VFX_ABS(yspeed) / 333.3f;
            
            if (m > 3) m = 3;
            
            setFocus(VfxS32(getScrollIndex() - s * m + 0.5f), 300);
        }
    }

    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset)
    {
        setScrollIndex(getScrollIndex() - VfxFloat(yoffset) / CELL_ITEM_HEIGHT, 0);
    }

    // Notify when the menu is tapped
    virtual void onTap(VfxPoint pt)
    {
        VfxS32 up       = (getSize().height - CELL_ITEM_HEIGHT) / 2;
        VfxS32 down     = (getSize().height + CELL_ITEM_HEIGHT) / 2;

        if (pt.y >= up && pt.y <= down)
        {
            MyCell* cell = (MyCell*)getCellIfPresent(getFocus());
            if (cell)
            {
                // because maybe the scroll index is changing by drag
                // fix it
                setFocus(getFocus());
                cell->click();
            }                    
        }
        else if (pt.y < up)
        {
            setFocus(getFocus() - 1);
        }
        else if (pt.y > down)
        {
            setFocus(getFocus() + 1);
        }
    }

    virtual VfxS32 getCount()
    {
        return m_count;
    }

    virtual VfxS32 getBehindCount()
    {
        return 3;
    }

    virtual VfxS32 getAheadCount()
    {
        return 3;
    }

    static vrt_render_dirty_type_enum myFrameEffectCB(
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
        VFX_DEV_ASSERT(target_frame != NULL);

        VfxS32 w = viewBounds.size.width / 2;
        VfxS32 h = viewBounds.size.height / 2;
        VfxPoint org = target_frame->pos;

        if (cellRelPos < 0)
        {
            target_frame->opacity = (4 + cellRelPos) / 4.0f;
        }
        else
        {
            target_frame->opacity = (4 - cellRelPos) / 4.0f;
        }

        if (target_frame->opacity > 1.0f)
            target_frame->opacity = 1.0f;

        if (target_frame->opacity <= 0)
            target_frame->opacity = 0;

        if (subCell == 0)
        {
            if (cellRelPos < 0)
            {
                target_frame->pos.x = VfxS32(vfxCos(cellRelPos / VFX_PI) * w);
                target_frame->pos.y = VfxS32(h + vfxSin(cellRelPos / VFX_PI) * h);
            }
            else
            {
                target_frame->pos.x = VfxS32(2* w - vfxCos(cellRelPos / VFX_PI) * w);
                target_frame->pos.y = VfxS32(h + vfxSin(cellRelPos / VFX_PI) * h);
            }

            target_frame->bounds.size.width     = VfxS32(200 * target_frame->opacity);
            target_frame->bounds.size.height    = VfxS32(CELL_ITEM_HEIGHT * target_frame->opacity);    
        }
        else
        {
            target_frame->pos.x = 0;
            target_frame->pos.y = VfxS32(h + vfxSin(cellRelPos / VFX_PI) * h);
        }

        //VFX_TRACE(("myFrameEffectCB: %d %f %d %d\n", data->index, fPos, target_frame->pos.x, target_frame->pos.y));
            
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }

    virtual VcpWheelMenuFrameEffectCBFuncPtr getFrameEffectCB()
    {
        return &MyWheelMenu::myFrameEffectCB;
    }

    void setCount(VfxS32 count)
    {
        if (m_cells) 
        {
            VFX_FREE_MEM(m_cells);
        }
        if (count == 0)
        {
            VFX_ALLOC_MEM(m_cells, sizeof(VfxS32) * 1, this);
        }
        else
        {
            VFX_ALLOC_MEM(m_cells, sizeof(VfxS32) * count, this);
        }

        for (VfxS32 i = 0; i < count; i++)
        {
            m_cells[i] = i;
        }

        m_count = count;
        update();
    }

// Variable
protected:
    VfxBool     m_cellTextVisible;
    VfxS32      m_count;
    VfxS32      *m_cells;
    VfxFrame    *m_removedFrame;
};

class VtstRtWheel : public VtstRtScr
{
public:
    typedef VtstRtWheel Self;
    typedef VtstRtScr   Super;

// Variable
public:
    MyWheelMenu *m_menu;

// Constructor / Destructor
public:
    VtstRtWheel() : m_menu(NULL) {}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("Wheel Menu Test"));

        // scrollable body
        VFX_OBJ_CREATE(m_menu, MyWheelMenu, this);
        
        m_menu->setPos(VfxPoint(10, 50));
        m_menu->setBounds(VfxRect(0, 0, 220, 260));
        m_menu->setBgColor(VFX_COLOR_BLACK);
        m_menu->setFocused(VFX_TRUE);
        m_menu->setCount(50);
        m_menu->setFocus(25);
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

VtstTestResultEnum vtst_rt_wheel(VfxU32 param)
{
    VTST_START_SCRN(VtstRtWheel);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__
