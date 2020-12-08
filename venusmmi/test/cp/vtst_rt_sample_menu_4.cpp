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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vadp_mmi_frm.h"
#include "vfx_uc_include.h"
#include "vcp_app_scr.h"
#include "vcp_wheel_menu.h"
#include "vtst_rt_main.h"
#include "vcp_include.h"
#include "ui_core\base\vfx_basic_type.h"

#ifdef __AFX_RT_TEST__

/***************************************************************************** 
 * Wheel Menu Test Implementation
 *****************************************************************************/

#define CELL_ITEM_HEIGHT 60

/***************************************************************************** 
 * Color
 *****************************************************************************/
static const vrt_matrix3x3_struct g_transformArray[8] =
{
    {0.04801f, 0.00658f, -0.00054f, -0.04881f, 0.13032f, -0.00010, 197.0f, 45.0f, 1.0f},
    {0.22556f, -0.07550f, 0.00008f, 0.37368f, 0.24602f, 0.00103f, 214.0f, 22.0f, 1.0f},
    {0.38901f, -0.06668f, 0.00029f, 0.07033f, 0.27139f, -0.00008f, 212.0f, -17.0f, 1.0f},
    {0.58687f, -0.07668f, 0.00047f, 0.07114f, 0.33119f, -0.00027f, 95.0f, -48.0f, 1.0f},
    {1.0f, 0, 0, 0, 1.0f, 0, 0, 0, 1.0f},
    {0.44043f, 0.09329f, 0.00006f, -0.17208f, 0.26277f, -0.00054f, 28.0f, 124.0f, 1.0f},
    {0.21743f, 0.07781f, -0.00013f, -0.11347f, 0.07510f, -0.00078f, -7.0f, 162.0f, 1.0f},
    {0.21698f, -0.00247f, 0.00041f, 0.13339f, 0.33906f, 0.00049f, 9.0f, 216.0f, 1.0f}
};


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

class VtstRtSampleMenu4 : public VcpWheelMenu
{
    typedef VtstRtSampleMenu4       Self;
    typedef VcpWheelMenu    Super;
    
    class MyCell : public VfxControl
    {
        VfxTextFrame     *m_textFrame;
        VfxBool          m_highlight;

    public:

        VtstRtSampleMenu4* getMenu()
        {
            if (getParentFrame())
                return (VtstRtSampleMenu4*) getParentFrame();
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
            //setAnchor(VfxFPoint(0.5, 0.5));
            setBorderColor(VRT_COLOR_WHITE);
            setBorderWidth(1);
            setIsCached(VFX_TRUE);
            setIsOpaque(VFX_TRUE);
            //setRect(VfxRect(0, 0, 200, CELL_ITEM_HEIGHT));
            setRect(VfxRect(48, 36, 224, 168));

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
    VtstRtSampleMenu4(){}
    virtual ~VtstRtSampleMenu4(){}

// Override
public:
    virtual void onInit()
    {       
        Super::onInit();
        m_cellTextVisible = VFX_FALSE;
        setIsZSortChild(VFX_TRUE);
    }

    struct MyWheelMenuUserData
    {
        VfxS32 index;
    };

    virtual VfxFrame* createCell(VfxS32 pos)
    {
        MyCell* item;
        VFX_OBJ_CREATE(item, MyCell, this);

        VfxWChar caption[40] = {0};
        kal_wsprintf(caption, "(%d)", pos);
        item->setCaption(VFX_WSTR_MEM(caption));
        item->setTextVisible(m_cellTextVisible);
        item->setHighlight(VFX_FALSE, VFX_FALSE);

        item->setBgColor(VtstPickupColor(1000 + pos));

        if (getFocus() == pos)
        {
            item->setHighlight(VFX_TRUE, VFX_TRUE);
        }

        MyWheelMenuUserData data;
        data.index = pos;
        setCellUserData(pos, item, &data, sizeof(MyWheelMenuUserData));

        return item;
    }
    
    virtual void onUpdateCell(VfxS32 p, VfxFrame* cell)
    {
        if (p == getFocus())
        {
            cell->bringToFront();
        }
    }

    virtual void onCloseCell(VfxS32 pos, VfxFrame* cellFrame)
    {
        VFX_UNUSED(pos);
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
            }
            if (event.keyCode == VFX_KEY_CODE_2)
            {
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
        VFX_UNUSED(xspeed);
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
        VFX_UNUSED(xoffset);
        setScrollIndex(getScrollIndex() - VfxFloat(yoffset) / CELL_ITEM_HEIGHT, 0);
    }

    // Notify when the menu is tapped
    virtual void onTap(VfxPoint pt)
    {
        VfxS32 up       = 36;
        VfxS32 down     = 204;

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
        return 2;
    }

    virtual VfxS32 getAheadCount()
    {
        return 3;
    }

    static vrt_bool myFrameEffectCB(
        vrt_frame_visual_property_struct    *target_frame,  // [IN] the cell frame
        VfxFloat                            fPos,           // [IN] animating index value
        VfxS32                              focus,          // the focus value of the menu
        VfxRect                             viewBounds,     // the menu bounds
        void                                *userData,      // user data
        VfxU32                              userDataSize    // user data size
    )
    {
        VFX_UNUSED(focus);
        VFX_UNUSED(viewBounds);
        VFX_UNUSED(userDataSize);
        VFX_DEV_ASSERT(target_frame != NULL);
        VFX_DEV_ASSERT(userDataSize == sizeof(MyWheelMenuUserData));

        MyWheelMenuUserData* data = (MyWheelMenuUserData*)userData;
        
        VfxFloat offset = data->index - fPos;
        VfxS32 i;
        // becase focused index = 4
        VfxFloat index = 4 + offset;

        // check out of range, then set boundary transform
        if (index < 0)
        {
            target_frame->transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3;
            target_frame->transform.data.matrix3x3 = g_transformArray[0];
        }
        else if (index > 7)
        {
            target_frame->transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3;
            target_frame->transform.data.matrix3x3 = g_transformArray[7];
        } 
        else
        {
            // find out the lowIndex and upIndex for linear interpolation.
            VfxS32 lowIndex = VfxS32(index);
            VfxS32 upIndex = lowIndex + 1;
            vrt_matrix3x3_struct tempTransform;

            for (i = 0; i < 9; i++)
            {
                tempTransform.m[i] = ((VfxFloat)upIndex - index) * g_transformArray[lowIndex].m[i] + (index - lowIndex) * g_transformArray[upIndex].m[i];
            }
            
            target_frame->transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3;
            target_frame->transform.data.matrix3x3 = tempTransform;
        }

        
        // set Opacity
        if (offset < 2 && offset > -3)
        {
            target_frame->opacity = 1;
        }
        else
        {
            if (offset > 0)
            {
                target_frame->opacity = 1.0f - (offset - 2);
            }
            else
            {
                target_frame->opacity = 1.0f - (VFX_ABS(offset) - 3);
                
            }
            if (target_frame->opacity < 0)
            {
                target_frame->opacity = 0;
            }
        }
        target_frame->pos_z = VFX_ABS(offset);
        return VRT_TRUE;
    }

    virtual VcpWheelMenuFrameEffectCBFuncPtr getFrameEffectCB()
    {
        return &VtstRtSampleMenu4::myFrameEffectCB;
    }

    void setCount(VfxS32 count)
    {
        m_count = count;
        update();
    }

// Variable
protected:
    VfxBool m_cellTextVisible;
    VfxS32  m_count;
};

class VtstRtSampleMenu4Scr : public VtstRtScr
{
public:
    typedef VtstRtSampleMenu4Scr Self;
    typedef VtstRtScr   Super;

// Variable
public:
    VtstRtSampleMenu4 *m_menu;

// Constructor / Destructor
public:
    VtstRtSampleMenu4Scr() : m_menu(NULL) {}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("Sample Menu 4 Test"));

        // scrollable body
        VFX_OBJ_CREATE(m_menu, VtstRtSampleMenu4, this);
        
        m_menu->setPos(VfxPoint(0, 0));
        m_menu->setBounds(VfxRect(0, 0, 320, 240));
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
        VFX_UNUSED(idx);
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }
};

VtstTestResultEnum vtst_rt_sample_menu_4(VfxU32 param)
{
    VFX_UNUSED(param);
    VTST_START_SCRN_ROTATE(VtstRtSampleMenu4Scr);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__
