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
 * Path config parameter: should rename when you delvep real AP.
 *****************************************************************************/
#define VTST_RT_SAMPLE_MENU_5_CELL_WIDTH            (160)
#define VTST_RT_SAMPLE_MENU_5_CELL_HEIGHT           (60)
#define VTST_RT_SAMPLE_MENU_5_SEMIMAJOR             (200)
#define VTST_RT_SAMPLE_MENU_5_SEMIMINOR             (150)
#define VTST_RT_SAMPLE_MENU_5_ANGLE                 (15)
#define VTST_RT_SAMPLE_MENU_5_SHIFT_X               (-20)
#define VTST_RT_SAMPLE_MENU_5_SCALE_X               (0.125)
#define VTST_RT_SAMPLE_MENU_5_SCALE_Y               (0.25)

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

VfxBool g_disableEffect = VRT_FALSE;

/***************************************************************************** 
 * Class VcpMyWheelMenu
 *****************************************************************************/

class VtstRtSampleMenu5 : public VcpWheelMenu
{
    typedef VtstRtSampleMenu5       Self;
    typedef VcpWheelMenu    Super;

    class MyCell : public VfxControl
    {
        VfxTextFrame     *m_textFrame;
        VfxBool          m_highlight;

    public:

        VtstRtSampleMenu5* getMenu()
        {
            if (getParentFrame())
                return (VtstRtSampleMenu5*) getParentFrame();
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
            setRect(VfxRect(0, 0, VTST_RT_SAMPLE_MENU_5_CELL_WIDTH, VTST_RT_SAMPLE_MENU_5_CELL_HEIGHT));

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
    VtstRtSampleMenu5(){}
    virtual ~VtstRtSampleMenu5(){}

// Override
public:
    virtual void onInit()
    {       
        Super::onInit();
        m_cellTextVisible = VFX_FALSE;
        m_disableEffect = VFX_FALSE;
        setIsZSortChild(VFX_TRUE);
    }

    struct MyWheelMenuUserData
    {
        VfxS32 index;
        VfxS32 radius;
        VfxS32 a;
        VfxS32 b;
        VfxBool disable;
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
		data.radius = 200;
        data.a = 200;
        data.b = 100;
        data.disable = VFX_FALSE;
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
                MyCell* cell = (MyCell*)getCellIfPresent(getFocus());
                cell->setAutoAnimate(VFX_TRUE);
                cell->setPos(VfxPoint(0,0));
                return VFX_TRUE;
            }
            if (event.keyCode == VFX_KEY_CODE_2)
            {
                if (g_disableEffect)
                {
                    g_disableEffect = VRT_FALSE;
                }
                else
                {
                    g_disableEffect = VRT_TRUE;
                }          
                return VFX_TRUE;
            }
            if (event.keyCode == VFX_KEY_CODE_3)
            {
                if (m_disableEffect)
                {
                    MyWheelMenuUserData data;
                    data.index = getFocus();
            		data.radius = 200;
                    data.a = 200;
                    data.b = 100;
                    data.disable = VFX_FALSE;
                    setCellUserData(getFocus(), getCellIfPresent(getFocus()), &data, sizeof(MyWheelMenuUserData));
                    MyCell* cell = (MyCell*)getCellIfPresent(getFocus());
                    cell->setAutoAnimate(VFX_TRUE);
                    cell->setPos(VfxPoint(0,0));
                    m_disableEffect = VFX_FALSE;
                }
                else
                {
                    MyWheelMenuUserData data;
                    data.index = getFocus();
            		data.radius = 200;
                    data.a = 200;
                    data.b = 100;
                    data.disable = VFX_TRUE;
                    setCellUserData(getFocus(), getCellIfPresent(getFocus()), &data, sizeof(MyWheelMenuUserData));
                    MyCell* cell = (MyCell*)getCellIfPresent(getFocus());
                    cell->setAutoAnimate(VFX_TRUE);
                    cell->setPos(VfxPoint(0,0));
                    m_disableEffect = VFX_TRUE;
                }
                return VFX_TRUE;
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
            
            //if (m > 2) m = 2;
            
            setFocus(VfxS32(getScrollIndex() - s * m + 0.5f), 300);
        }
    }

    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset)
    {
        VFX_UNUSED(xoffset);
        setScrollIndex(getScrollIndex() - VfxFloat(yoffset) / VTST_RT_SAMPLE_MENU_5_CELL_HEIGHT, 0);
    }

    // Notify when the menu is tapped
    virtual void onTap(VfxPoint pt)
    {

        VfxS32 originX, originY, width, height,a,b,shiftX;
        VfxFloat angle, scaleX, scaleY;
        // Center Cell Postion
        VfxS32 w = getBounds().getWidth()/2;
        VfxS32 h = getBounds().getHeight()/2;
        originX = w + VTST_RT_SAMPLE_MENU_5_SHIFT_X - VTST_RT_SAMPLE_MENU_5_CELL_WIDTH/2;
        originY = h - VTST_RT_SAMPLE_MENU_5_CELL_HEIGHT/2;
        width = VTST_RT_SAMPLE_MENU_5_CELL_WIDTH;
        height = VTST_RT_SAMPLE_MENU_5_CELL_HEIGHT;
        angle = VTST_RT_SAMPLE_MENU_5_ANGLE;
        scaleX = VTST_RT_SAMPLE_MENU_5_SCALE_X;
        scaleY = VTST_RT_SAMPLE_MENU_5_SCALE_Y;
        a = VTST_RT_SAMPLE_MENU_5_SEMIMAJOR;
        b = VTST_RT_SAMPLE_MENU_5_SEMIMINOR;
        shiftX = VTST_RT_SAMPLE_MENU_5_SHIFT_X;

        if (pt.x >= originX && pt.x < originX + width && pt.y >= originY && pt.y < originY + height)
        {
            MyCell* cell = (MyCell*)getCellIfPresent(getFocus());
            if (cell)
            {
                // because maybe the scroll index is changing by drag
                // fix it
                setFocus(getFocus());
                cell->click();
            } 
            return;
        }
        // margin focus -1 
        originX = VfxS32(w + (1 - vfxCos(-1 * angle / 180.0f * VFX_PI)) * a + shiftX - w * (1 - scaleX * 1) / 2);
        originY = VfxS32(h + vfxSin(-1 * angle / 180.0f * VFX_PI) * b - height * (1 - scaleY * 1)/2);
        width = width * (1 - scaleX * 1);
        height = height * (1 - scaleY * 1);

        if (pt.x >= originX && pt.x < originX + width && pt.y >= originY && pt.y < originY + height)
        {
            setFocus(getFocus() - 1);
            return;
        }
        // margin focus -2 
        originX = VfxS32(w + (1 - vfxCos(-2 * angle / 180.0f * VFX_PI)) * a + shiftX - w * (1 - scaleX * 2) / 2);
        originY = VfxS32(h + vfxSin(-2 *  angle / 180.0f * VFX_PI) * b - height * (1 - scaleY * 2)/2);
        width = width * (1 - scaleX * 2);
        height = height * (1 - scaleY * 2);

        if (pt.x >= originX && pt.x < originX + width && pt.y >= originY && pt.y < originY + height)
        {
            setFocus(getFocus() - 2);
            return;
        }
        // margin focus +1
        originX = VfxS32(w + (1 - vfxCos(1 * angle / 180.0f * VFX_PI)) * a + shiftX - w * (1 - scaleX * 1) / 2);
        originY = VfxS32(h + vfxSin(1 * angle / 180.0f * VFX_PI) * b - height * (1 - scaleY * 1)/2);
        width = width * (1 - scaleX * 1);
        height = height * (1 - scaleY * 1);

        if (pt.x >= originX && pt.x < originX + width && pt.y >= originY && pt.y < originY + height)
        {
            setFocus(getFocus() + 1);
            return;
        }
        // margin focus +2
        originX = VfxS32(w + (1 - vfxCos(2 * angle / 180.0f * VFX_PI)) * a + shiftX - w * (1 - scaleX * 2) / 2);
        originY = VfxS32(h + vfxSin(2 * angle / 180.0f * VFX_PI) * b - height * (1 - scaleY * 2)/2);
        width = width * (1 - scaleX * 2);
        height = height * (1 - scaleY * 2);

        if (pt.x >= originX && pt.x < originX + width && pt.y >= originY && pt.y < originY + height)
        {
            setFocus(getFocus() + 2);
            return;
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
        return 2;
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
        VFX_UNUSED(userDataSize);
        VFX_DEV_ASSERT(target_frame != NULL);
        VFX_DEV_ASSERT(userDataSize == sizeof(MyWheelMenuUserData));
        
        MyWheelMenuUserData* data = (MyWheelMenuUserData*)userData;
        if (g_disableEffect || data->disable)
        {
            return VRT_FALSE;
        }

        VfxFloat offset = data->index - fPos;
        VfxS32 w = viewBounds.size.width / 2;
        VfxS32 h = viewBounds.size.height / 2;
        // define the semimajor axis a and semiminor axis b of ellipse. 
        VfxS32 a = VTST_RT_SAMPLE_MENU_5_SEMIMAJOR;
        VfxS32 b = VTST_RT_SAMPLE_MENU_5_SEMIMINOR;

        // calculate the pos by ellipse parametric equation.
        // notice that we offset 20 in X axis, so the menu is looked on left side.
		target_frame->pos.x = VfxS32(w + (1 - vfxCos(offset * VTST_RT_SAMPLE_MENU_5_ANGLE / 180.0f * VFX_PI)) * a + VTST_RT_SAMPLE_MENU_5_SHIFT_X);
        target_frame->pos.y = VfxS32(h + vfxSin(offset * VTST_RT_SAMPLE_MENU_5_ANGLE / 180.0f * VFX_PI) * b);

        // set opacity
        target_frame->opacity = (3 - VFX_ABS(offset))/3.0f;
        if (target_frame->opacity < 0)
        {
            target_frame->opacity = 0;
        }

        //scale the item
		target_frame->transform.type = VRT_TRANSFORM_TYPE_AFFINE;
		target_frame->transform.data.affine.sx = 1 - VFX_ABS(offset) * VTST_RT_SAMPLE_MENU_5_SCALE_X;
        target_frame->transform.data.affine.sy = 1 - VFX_ABS(offset) * VTST_RT_SAMPLE_MENU_5_SCALE_Y;
        target_frame->pos_z = VFX_ABS(offset);
        return VRT_TRUE;
    }

    virtual VcpWheelMenuFrameEffectCBFuncPtr getFrameEffectCB()
    {
        return &VtstRtSampleMenu5::myFrameEffectCB;
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
    VfxBool m_disableEffect;
};

class VtstRtSampleMenu5Scr : public VtstRtScr
{
public:
    typedef VtstRtSampleMenu5Scr Self;
    typedef VtstRtScr   Super;

// Variable
public:
    VtstRtSampleMenu5 *m_menu;

// Constructor / Destructor
public:
    VtstRtSampleMenu5Scr() : m_menu(NULL) {}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("Sample Menu 5 Test"));

        // scrollable body
        VFX_OBJ_CREATE(m_menu, VtstRtSampleMenu5, this);
        
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
        VFX_UNUSED(idx);
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }
};

VtstTestResultEnum vtst_rt_sample_menu_5(VfxU32 param)
{
    VFX_UNUSED(param);
    VTST_START_SCRN(VtstRtSampleMenu5Scr);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__
