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


#include "vcp_app_scr.h"

#include "vcp_wheel_menu.h"
#include "vtst_rt_main.h"
#include "vfx_basic_type.h"
#include "vcp_frame_effect.h"
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
#include "vfx_transform.h"
#include "vfx_animation.h"
#include "vcp_frame_effect_type.h"
#include "vfx_signal.h"
#include "vfx_app_cat_scr.h"

/***************************************************************************** 
 * Path config parameter: should rename when you delvep real AP.
 *****************************************************************************/
#define VTST_RT_SAMPLE_MENU_1_CAMERA_DISTANCE       (240)
#define VTST_RT_SAMPLE_MENU_1_CELL_WIDTH            (160)
#define VTST_RT_SAMPLE_MENU_1_CELL_HEIGHT           (60)
#define VTST_RT_SAMPLE_MENU_1_SHIFT_X               (-20)
#define VTST_RT_SAMPLE_MENU_1_ANGLE                 (15)
#define VTST_RT_SAMPLE_MENU_1_RADIUS                (200)
#define VTST_RT_SAMPLE_MENU_1_TILE                  (30)
#define VTST_RT_SAMPLE_MENU_1_PAN                   (20)

/***************************************************************************** 
 * Wheel Menu Test Implementation
 *****************************************************************************/

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

class VtstRtSampleMenu1 : public VcpWheelMenu
{
    typedef VtstRtSampleMenu1       Self;
    typedef VcpWheelMenu    Super;

    class MyCell : public VfxControl
    {
        VfxTextFrame     *m_textFrame;
        VfxBool          m_highlight;

    public:

        VtstRtSampleMenu1* getMenu()
        {
            if (getParentFrame())
                return (VtstRtSampleMenu1*) getParentFrame();
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
            setRect(VfxRect(0, 0, VTST_RT_SAMPLE_MENU_1_CELL_WIDTH, VTST_RT_SAMPLE_MENU_1_CELL_HEIGHT));

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
    VtstRtSampleMenu1() : 
        m_filterTimeline1(NULL),
        m_filterTimeline2(NULL),
        m_filterTimeline3(NULL),
        m_filterTimeline4(NULL),
        m_filterTimeline5(NULL)
        {}
    virtual ~VtstRtSampleMenu1(){}

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
        VfxBool isEnter;
    };

    virtual VfxFrame* createCell(VfxS32 cell, VfxS32 subcell)
    {
        MyCell* item;
        VFX_OBJ_CREATE(item, MyCell, this);

        VfxWChar caption[40] = {0};
        kal_wsprintf(caption, "(%d)", cell);
        item->setCaption(VFX_WSTR_MEM(caption));
        item->setTextVisible(m_cellTextVisible);
        item->setHighlight(VFX_FALSE, VFX_FALSE);

        item->setBgColor(VtstPickupColor(1000 + cell));

        if (getFocus() == cell)
        {
            item->setHighlight(VFX_TRUE, VFX_TRUE);
        }
        
        MyWheelMenuUserData data;
        data.index = cell;
        data.isEnter = VFX_FALSE;
        setCellUserData(cell, subcell, item, &data, sizeof(MyWheelMenuUserData));

        item->setFilterTiming(1.0f);

        return item;
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
        VFX_UNUSED(cell);
        VFX_UNUSED(subcell);
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
            #endif
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
        setScrollIndex(getScrollIndex() - VfxFloat(yoffset) / VTST_RT_SAMPLE_MENU_1_CELL_HEIGHT, 0);
    }

    // Notify when the menu is tapped
    virtual void onTap(VfxPoint pt)
    {
        MyCell* item = (MyCell*) getCellIfPresent(getFocus());
        VfxMatrix3x3Ex inv = VfxMatrix3x3Ex(item->forceGetTransform().data.matrix3x3);
        inv.inverse();

        VfxPoint point = inv.transform(pt);
        point = convertPointTo(point, item);
        if (item->getBounds().contains(point))
        {
            setFocus(getFocus());
            item->click();
            return;
        }

        item = (MyCell*) getCellIfPresent(getFocus() - 1);
        inv = VfxMatrix3x3Ex(item->forceGetTransform().data.matrix3x3);
        inv.inverse();

        point = inv.transform(pt);
        point = convertPointTo(point, item);
        if (item->getBounds().contains(point))
        {
            setFocus(getFocus() - 1);
            return;
        }


        item = (MyCell*) getCellIfPresent(getFocus() + 1);
        inv = VfxMatrix3x3Ex(item->forceGetTransform().data.matrix3x3);
        inv.inverse();

        point = inv.transform(pt);
        point = convertPointTo(point, item);
        if (item->getBounds().contains(point))
        {
            setFocus(getFocus() + 1);
            return;
        }


        item = (MyCell*) getCellIfPresent(getFocus() - 2);
        inv = VfxMatrix3x3Ex(item->forceGetTransform().data.matrix3x3);
        inv.inverse();

        point = inv.transform(pt);
        point = convertPointTo(point, item);
        if (item->getBounds().contains(point))
        {
            setFocus(getFocus() - 2);
            return;
        }

        item = (MyCell*) getCellIfPresent(getFocus() + 2);
        inv = VfxMatrix3x3Ex(item->forceGetTransform().data.matrix3x3);
        inv.inverse();

        point = inv.transform(pt);
        point = convertPointTo(point, item);
        if (item->getBounds().contains(point))
        {
            setFocus(getFocus() + 2);
            return;
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
 #endif       
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
        VFX_UNUSED(focus);
        VFX_UNUSED(userDataSize);
        VFX_DEV_ASSERT(target_frame != NULL);
        VFX_DEV_ASSERT(userDataSize == sizeof(MyWheelMenuUserData));

        MyWheelMenuUserData* data = (MyWheelMenuUserData*)userData;
 
        VfxFloat offset = data->index - fPos; 
        
        VfxMatrix4x4 totalProject;
        VfxMatrix4x4 cameraView;
        VfxMatrix4x4 modelView;
        VfxMatrix4x4 RT;
        
        // set Camear parameters :
        // Se set translateX as viewBounds.size.width/2 and 
        // translateY as viewBounds.size.height/2.
        // So the 3D origin will project into the screen center.
        // Set CameraDistance & nearPlane will change the perspecitve
        // degree of 3D scene. We set those two parameter the same
        // becasue we want to the focused item the apply no transform.
        cameraView.setCamera(
            1.0f, 
            1.0f, 
            (VfxFloat)(viewBounds.size.width/2), 
            (VfxFloat)(viewBounds.size.height/2), 
            (VfxFloat)VTST_RT_SAMPLE_MENU_1_CAMERA_DISTANCE, 
            (VfxFloat)VTST_RT_SAMPLE_MENU_1_CAMERA_DISTANCE, 
            0, 
            0, 
            0);

        // set Model View :
        // The model view matirx decides the origin and direction of model.
        // We set the origin of each item to the center of item.
        // So we need to apply a negative translate. 
        // 160/2 is the item's half width and 60/2 is item's half height.
        modelView.setTranslation((VfxFloat)((-1 * VTST_RT_SAMPLE_MENU_1_CELL_WIDTH/2)), 
                            (VfxFloat)(-1 * VTST_RT_SAMPLE_MENU_1_CELL_HEIGHT/2), 
                            0);

        // set RT matrix :
        // RT matrix decide the rotate part and translate part of model.
        // The 3,7,11 is translate part of the matrix.
        // we want to shift x to negative direction a litte, and y z path
        // as a circle in Y plane. The 15.0f means there is 15 degree between
        // two item and the 200 is radius of this circle. If radius become
        // large, the distance between will become large.
        RT.m[12] = VTST_RT_SAMPLE_MENU_1_SHIFT_X;
        RT.m[13] = vfxSin(offset * VTST_RT_SAMPLE_MENU_1_ANGLE/ 180.0f * VFX_PI) * VTST_RT_SAMPLE_MENU_1_RADIUS;
        RT.m[14] = (1 - vfxCos(offset * VTST_RT_SAMPLE_MENU_1_ANGLE / 180.0f * VFX_PI)) * VTST_RT_SAMPLE_MENU_1_RADIUS;

        // The 0,1,2,4,5,6,8,9,10 is rotate part of the matrix.
        // we want to apply two rotate rotate by x axis by 30 degree,
        // then rotate by y axis by 20 degree. notice that the first applied
        // rotation will be put on the right side of matrix and the least 
        // applied rotation will be put on the left side of matrix. The
        // result of two rotation multiplying is list as follow:
        /*
        RT.m[5] = RT.m[10] = vfxCos(offset * 30.0f / 180.0f * VFX_PI);
        RT.m[6] = vfxSin(offset * 30.0f / 180.0f * VFX_PI);
        RT.m[9] = -1 * RT.m[9];
        */
        
        VfxFloat cosA= vfxCos(offset * VTST_RT_SAMPLE_MENU_1_TILE / 180.0f * VFX_PI);
        VfxFloat sinA = vfxSin(offset * VTST_RT_SAMPLE_MENU_1_TILE / 180.0f * VFX_PI);
        VfxFloat cosB = vfxCos(offset * VTST_RT_SAMPLE_MENU_1_PAN / 180.0f * VFX_PI);
        VfxFloat sinB = vfxSin(offset * VTST_RT_SAMPLE_MENU_1_PAN / 180.0f * VFX_PI);
       
        RT.m[0] = cosB;
        RT.m[4] = sinB * sinA;
        RT.m[8] = -1 * sinB * cosA;
        
        RT.m[1] = 0;
        RT.m[5] = cosA;
        RT.m[9] = sinA;

        RT.m[2] = sinB;
        RT.m[6] = -1 * cosB * sinA;
        RT.m[10] = cosB * cosA;
        
        // Now we multiply cameraView, RT and modelview to get totalProject. 
        totalProject = cameraView * RT * modelView;

        // Set as 3x3 matrix for VRT rendering.
        target_frame->transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3; 
        totalProject.initMatrix3x3(target_frame->transform.data.matrix3x3);

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

        if (state != VCP_WHEEL_MENU_NORMAL_STATE)
        {
            VfxMatrix3x3Ex mat = VfxMatrix3x3Ex(target_frame->transform.data.matrix3x3);
            VfxMatrix3x3Ex tempMat;
            /*
            VfxFloat tx, ty;
            tx = mat.m[6];
            ty = mat.m[7];
            */
            VfxFloat p1x, p1y, p2x, p2y;

            p1x = mat.m[6]/mat.m[8];
            p1y = mat.m[7]/mat.m[8];
            
            p2x = (mat.m[0] * VTST_RT_SAMPLE_MENU_1_CELL_WIDTH + mat.m[3] * VTST_RT_SAMPLE_MENU_1_CELL_HEIGHT + mat.m[6]) /
                    (mat.m[2] * VTST_RT_SAMPLE_MENU_1_CELL_WIDTH + mat.m[5] * VTST_RT_SAMPLE_MENU_1_CELL_HEIGHT + mat.m[8]);
            
            p2y = (mat.m[1] * VTST_RT_SAMPLE_MENU_1_CELL_WIDTH + mat.m[4] * VTST_RT_SAMPLE_MENU_1_CELL_HEIGHT + mat.m[7]) /
                    (mat.m[2] * VTST_RT_SAMPLE_MENU_1_CELL_WIDTH + mat.m[5] * VTST_RT_SAMPLE_MENU_1_CELL_HEIGHT + mat.m[8]);

            tempMat.setTranslation((-1 * (p1x + p2x)/2), (-1 * (p1y + p2y)/2));
            mat = tempMat * mat;
           
            tempMat.setRotateByZ(VFX_DEG_TO_RAD(360 * level));
            mat = tempMat * mat;
            
            if (state == VCP_WHEEL_MENU_ENTER_STATE)
            {
                tempMat.setTranslation(200 - 200 * level, 0);
            }
            else
            {
                tempMat.setTranslation(-200 * level, 0);
            }
            mat = tempMat * mat;

            tempMat.setTranslation((p1x + p2x)/2 ,(p1y + p2y)/2);
            mat = tempMat * mat;

            mat.initMatrix3x3(target_frame->transform.data.matrix3x3);
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
           #endif
        }

        target_frame->pos_z = VFX_ABS(offset);
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }

    virtual VcpWheelMenuFrameEffectCBFuncPtr getFrameEffectCB()
    {
        return &VtstRtSampleMenu1::myFrameEffectCB;
    }

    virtual void onStateChangeFinished(VcpWheelMenuState finishedstate)
    {
        if (finishedstate == VCP_WHEEL_MENU_NORMAL_STATE)
        {
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
            m_movingFrame->setPos(m_focusPos2);
            VfxAutoAnimate::commit();
            pushInSubCell(m_movingFrame, getFocus(),0);
        }
    }

    void setCount(VfxS32 count)
    {
        m_count = count;
        update();
    }

    void enter()
    {
        MyCell* item = (MyCell*) getCellIfPresent(getFocus());

        if (m_filterTimeline1 == NULL)
        {
            VFX_OBJ_CREATE(m_filterTimeline1, VfxFloatTimeline, this);
        }
        m_filterTimeline1->setFromValue(0.0f);
        m_filterTimeline1->setToValue(1.0f);
        m_filterTimeline1->setDurationTime(2000);
        m_filterTimeline1->setRepeatCount(1);
        m_filterTimeline1->setTarget(item);
        m_filterTimeline1->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_filterTimeline1->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
        m_filterTimeline1->start();
        /*
        MyWheelMenuUserData data;
        data.index = getFocus();
        data.isEnter = VFX_TRUE;
        setCellUserData(getFocus(), 0, item, &data, sizeof(MyWheelMenuUserData));
        */
        item = (MyCell*) getCellIfPresent(getFocus()-1);

        if (m_filterTimeline2 == NULL)
        {
            VFX_OBJ_CREATE(m_filterTimeline2, VfxFloatTimeline, this);
        }
        m_filterTimeline2->setFromValue(0.0f);
        m_filterTimeline2->setToValue(1.0f);
        m_filterTimeline2->setDurationTime(2000);
        m_filterTimeline2->setRepeatCount(1);
        m_filterTimeline2->setTarget(item);
        m_filterTimeline2->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_filterTimeline2->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
        m_filterTimeline2->setStartTime(250);
        m_filterTimeline2->start(); 
        /*
        data.index = getFocus()-1;
        data.isEnter = VFX_TRUE;
        setCellUserData(getFocus()-1, 0, item, &data, sizeof(MyWheelMenuUserData));
        */

        item = (MyCell*) getCellIfPresent(getFocus()+1);

        if (m_filterTimeline3 == NULL)
        {
            VFX_OBJ_CREATE(m_filterTimeline3, VfxFloatTimeline, this);
        }
        m_filterTimeline3->setFromValue(0.0f);
        m_filterTimeline3->setToValue(1.0f);
        m_filterTimeline3->setDurationTime(2000);
        m_filterTimeline3->setRepeatCount(1);
        m_filterTimeline3->setTarget(item);
        m_filterTimeline3->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_filterTimeline3->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
        m_filterTimeline3->setStartTime(500);
        m_filterTimeline3->start(); 
        /*
        data.index = getFocus() + 1;
        data.isEnter = VFX_TRUE;
        setCellUserData(getFocus() + 1, 0, item, &data, sizeof(MyWheelMenuUserData));
        */
        item = (MyCell*) getCellIfPresent(getFocus()-2);

        if (m_filterTimeline4 == NULL)
        {
            VFX_OBJ_CREATE(m_filterTimeline4, VfxFloatTimeline, this);
        }
        m_filterTimeline4->setFromValue(0.0f);
        m_filterTimeline4->setToValue(1.0f);
        m_filterTimeline4->setDurationTime(2000);
        m_filterTimeline4->setRepeatCount(1);
        m_filterTimeline4->setTarget(item);
        m_filterTimeline4->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_filterTimeline4->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
        m_filterTimeline4->setStartTime(750);
        m_filterTimeline4->start(); 
        /*
        data.index = getFocus() -2;
        data.isEnter = VFX_TRUE;
        setCellUserData(getFocus() -2, 0, item, &data, sizeof(MyWheelMenuUserData));
        */
        item = (MyCell*) getCellIfPresent(getFocus()+2);

        if (m_filterTimeline5 == NULL)
        {
            VFX_OBJ_CREATE(m_filterTimeline5, VfxFloatTimeline, this);
        }
        m_filterTimeline5->setFromValue(0.0f);
        m_filterTimeline5->setToValue(1.0f);
        m_filterTimeline5->setDurationTime(2000);
        m_filterTimeline5->setRepeatCount(1);
        m_filterTimeline5->setTarget(item);
        m_filterTimeline5->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_filterTimeline5->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
        m_filterTimeline5->setStartTime(1000);
        m_filterTimeline5->start(); 
        /*
        data.index = getFocus() +2;
        data.isEnter = VFX_TRUE;
        setCellUserData(getFocus() +2, 0, item, &data, sizeof(MyWheelMenuUserData));
        */
    }


    void leave()
    {
        MyCell* item = (MyCell*) getCellIfPresent(getFocus());

        if (m_filterTimeline1 == NULL)
        {
            VFX_OBJ_CREATE(m_filterTimeline1, VfxFloatTimeline, this);
        }
        m_filterTimeline1->setFromValue(0.0f);
        m_filterTimeline1->setToValue(1.0f);
        m_filterTimeline1->setDurationTime(2000);
        m_filterTimeline1->setRepeatCount(1);
        m_filterTimeline1->setTarget(item);
        m_filterTimeline1->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_filterTimeline1->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
        m_filterTimeline1->start();

        MyWheelMenuUserData data;
        data.index = getFocus();
        data.isEnter = VFX_FALSE;
        setCellUserData(getFocus(), 0, item, &data, sizeof(MyWheelMenuUserData));

        item = (MyCell*) getCellIfPresent(getFocus()-1);

        if (m_filterTimeline2 == NULL)
        {
            VFX_OBJ_CREATE(m_filterTimeline2, VfxFloatTimeline, this);
        }
        m_filterTimeline2->setFromValue(0.0f);
        m_filterTimeline2->setToValue(1.0f);
        m_filterTimeline2->setDurationTime(2000);
        m_filterTimeline2->setRepeatCount(1);
        m_filterTimeline2->setTarget(item);
        m_filterTimeline2->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_filterTimeline2->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
        m_filterTimeline2->setStartTime(250);
        m_filterTimeline2->start(); 

        data.index = getFocus()-1;
        data.isEnter = VFX_FALSE;
        setCellUserData(getFocus()-1, 0, item, &data, sizeof(MyWheelMenuUserData));


        item = (MyCell*) getCellIfPresent(getFocus()+1);

        if (m_filterTimeline3 == NULL)
        {
            VFX_OBJ_CREATE(m_filterTimeline3, VfxFloatTimeline, this);
        }
        m_filterTimeline3->setFromValue(0.0f);
        m_filterTimeline3->setToValue(1.0f);
        m_filterTimeline3->setDurationTime(2000);
        m_filterTimeline3->setRepeatCount(1);
        m_filterTimeline3->setTarget(item);
        m_filterTimeline3->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_filterTimeline3->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
        m_filterTimeline3->setStartTime(500);
        m_filterTimeline3->start(); 

        data.index = getFocus() + 1;
        data.isEnter = VFX_FALSE;
        setCellUserData(getFocus() + 1, 0, item, &data, sizeof(MyWheelMenuUserData));

        item = (MyCell*) getCellIfPresent(getFocus()-2);

        if (m_filterTimeline4 == NULL)
        {
            VFX_OBJ_CREATE(m_filterTimeline4, VfxFloatTimeline, this);
        }
        m_filterTimeline4->setFromValue(0.0f);
        m_filterTimeline4->setToValue(1.0f);
        m_filterTimeline4->setDurationTime(2000);
        m_filterTimeline4->setRepeatCount(1);
        m_filterTimeline4->setTarget(item);
        m_filterTimeline4->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_filterTimeline4->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
        m_filterTimeline4->setStartTime(750);
        m_filterTimeline4->start(); 

        data.index = getFocus() -2;
        data.isEnter = VFX_FALSE;
        setCellUserData(getFocus() -2, 0, item, &data, sizeof(MyWheelMenuUserData));

        item = (MyCell*) getCellIfPresent(getFocus()+2);

        if (m_filterTimeline5 == NULL)
        {
            VFX_OBJ_CREATE(m_filterTimeline5, VfxFloatTimeline, this);
        }
        m_filterTimeline5->setFromValue(0.0f);
        m_filterTimeline5->setToValue(1.0f);
        m_filterTimeline5->setDurationTime(2000);
        m_filterTimeline5->setRepeatCount(1);
        m_filterTimeline5->setTarget(item);
        m_filterTimeline5->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_filterTimeline5->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
        m_filterTimeline5->setStartTime(1000);
        m_filterTimeline5->start(); 

        data.index = getFocus() +2;
        data.isEnter = VFX_FALSE;
        setCellUserData(getFocus() +2, 0, item, &data, sizeof(MyWheelMenuUserData));
    }

// Variable
protected:
    VfxBool m_cellTextVisible;
    VfxS32  m_count;
    VfxFloatTimeline *m_filterTimeline1;
    VfxFloatTimeline *m_filterTimeline2;
    VfxFloatTimeline *m_filterTimeline3;
    VfxFloatTimeline *m_filterTimeline4;
    VfxFloatTimeline *m_filterTimeline5;
public:
    VfxFrame *m_movingFrame;
    VfxPoint           m_focusPos2;
};

class VtstRtSampleMenu1Scr : public VtstRtScr
{
public:
    typedef VtstRtSampleMenu1Scr Self;
    typedef VtstRtScr   Super;

// Variable
public:
    VfxFrame          *m_background;
    VtstRtSampleMenu1 *m_menu;
    VfxFrame          *m_anotherFrame;
    VcpFrameEffect    *m_frameEffect;
    VfxFrame          *m_movingFrame;
    VfxFrame          *m_movingFrame2;
    VfxPoint           m_focusPos;
    VfxPoint           m_focusPos2;
    VfxBool           m_isLeave;

// Constructor / Destructor
public:
    VtstRtSampleMenu1Scr() : m_menu(NULL) {}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("Sample Menu 1 Test"));

        VFX_OBJ_CREATE(m_background, VfxFrame, this);
        m_background->setPos(VfxPoint(10, 50));
        m_background->setBounds(VfxRect(0, 0, 220, 260));
        m_background->setBgColor(VFX_COLOR_BLACK);

        VFX_OBJ_CREATE(m_anotherFrame, VfxFrame, this);
        m_anotherFrame->setPos(VfxPoint(10, 50));
        m_anotherFrame->setBounds(VfxRect(0, 0, 220, 260));
        //m_anotherFrame->setBgColor(VFX_COLOR_BLACK);

        VfxFrame *tempFrame;
        /*
        VFX_OBJ_CREATE(tempFrame, VfxFrame, m_anotherFrame);        
        tempFrame->setRect(20, 30, 50, 50);
        tempFrame->setBgColor(VFX_COLOR_OLIVE);
        tempFrame->setIsCached(VFX_TRUE);
        */

        VFX_OBJ_CREATE(tempFrame, VfxFrame, m_anotherFrame);
        tempFrame->setRect(0, 80, 220, 180);
        tempFrame->setBgColor(VFX_COLOR_GREEN);
        tempFrame->setIsCached(VFX_TRUE);

        VFX_OBJ_CREATE(tempFrame, VfxFrame, m_anotherFrame);
        tempFrame->setRect(0, 220, 220, 40);
        tempFrame->setBgColor(VFX_COLOR_SILVER);
        tempFrame->setIsCached(VFX_TRUE);

        VFX_OBJ_CREATE(tempFrame, VfxFrame, m_anotherFrame);
        tempFrame->setRect(180, 40, 30, 30);
        tempFrame->setBgColor(VFX_COLOR_FUCHSIA);
        tempFrame->setIsCached(VFX_TRUE);

        m_anotherFrame->setHidden(VFX_TRUE);


        // scrollable body
        VFX_OBJ_CREATE(m_menu, VtstRtSampleMenu1, this);
        
        m_menu->setPos(VfxPoint(10, 50));
        m_menu->setBounds(VfxRect(0, 0, 220, 260));
        //m_menu->setBgColor(VFX_COLOR_BLACK);
        m_menu->setFocused(VFX_TRUE);
        m_menu->setCount(50);
        m_menu->setFocus(25);

        VFX_OBJ_CREATE(m_movingFrame2, VfxFrame, this);        
        m_movingFrame2->setRect(20, 30, 160, 60);
        m_movingFrame2->setAnchor(VfxFPoint(0.5, 0.5));
        m_movingFrame2->setBgColor(VFX_COLOR_OLIVE);
        m_movingFrame2->setIsCached(VFX_TRUE);
        m_movingFrame2->setOpacity(0);
        m_movingFrame2->setAutoAnimate(VFX_TRUE);


        VFX_OBJ_CREATE(m_frameEffect, VcpFrameEffect, this);
        //m_menu->enter();
    }

    virtual VfxBool onKeyInput(VfxKeyEvent &event)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            if (event.keyCode == VFX_KEY_CODE_1)
            {
                m_menu->configureStatePara(VCP_WHEEL_MENU_ENTER_STATE, 2000, 250, VCP_WHEEL_MENU_FOCUS_FISRT);
                m_menu->changeState(VCP_WHEEL_MENU_ENTER_STATE);
                //enter();
            }
            if (event.keyCode == VFX_KEY_CODE_2)
            {
                m_movingFrame = m_menu->pullOutSubCell(m_menu->getFocus(),0);
                m_menu->configureStatePara(VCP_WHEEL_MENU_LEAVE_STATE, 2000, 250, VCP_WHEEL_MENU_FOCUS_LAST);
                m_menu->changeState(VCP_WHEEL_MENU_LEAVE_STATE);

                // set pullout frame to the same position but transform = I
                VfxTransform tempTransform = m_movingFrame->forceGetTransform();
                m_focusPos2 = m_movingFrame->getPos();
                m_focusPos = VfxPoint((VfxS32)(m_movingFrame->getPos().x + tempTransform.data.matrix3x3.m[6]), (VfxS32)(m_movingFrame->getPos().y + tempTransform.data.matrix3x3.m[7]));
                VfxAutoAnimate::begin();
                VfxAutoAnimate::setDisable(VFX_TRUE);

                m_movingFrame2->setPos(10 + m_focusPos.x, 50 + m_focusPos.y);
                m_movingFrame2->setBounds(m_movingFrame->getBounds());

                m_movingFrame->setPos(m_focusPos.x, m_focusPos.y);
                // because value of mmi is the same as VfxTransform(), we need set another value first
                m_movingFrame->setTransform(tempTransform);
                m_movingFrame->setTransform(VfxTransform());

                VfxAutoAnimate::commit();

                m_anotherFrame->setHidden(VFX_FALSE);
                m_frameEffect->applyEffect(m_anotherFrame, VCP_EFFECT_TRANSFORMER, 3000, VCP_EFFECT_DIRECTION_FROM_NONE, VFX_FALSE, NULL, 0);
                m_frameEffect->m_signalFinished.connect(this, &VtstRtSampleMenu1Scr::onFrameEffectFinished);
                m_isLeave = VFX_TRUE;

                VfxAutoAnimate::begin();
                VfxAutoAnimate::setDuration(1000);
                m_movingFrame->setPos(45,55);
                m_movingFrame->setBounds(0, 0, 50, 50);
                m_movingFrame->setOpacity(0);

                m_movingFrame2->setPos(10 + 45, 50 + 55);
                m_movingFrame2->setBounds(0, 0, 50, 50);
                m_movingFrame2->setOpacity(1);
                VfxAutoAnimate::commit();
                //leave();
            }

            if (event.keyCode == VFX_KEY_CODE_3)
            {
                VfxAutoAnimate::begin();
                VfxAutoAnimate::setDuration(1000);
                m_movingFrame->setPos(m_focusPos);
                m_movingFrame->setBounds(0, 0, 160, 60);
                m_movingFrame->setOpacity(1);

                m_movingFrame2->setPos(10 + m_focusPos.x, 50 + m_focusPos.y);
                m_movingFrame2->setBounds(0, 0, 160, 60);
                m_movingFrame2->setOpacity(0);
                VfxAutoAnimate::commit();

                m_menu->setHidden(VFX_FALSE);
                m_menu->configureStatePara(VCP_WHEEL_MENU_ENTER_STATE, 2000, 250, VCP_WHEEL_MENU_FOCUS_FISRT);
                m_menu->changeState(VCP_WHEEL_MENU_ENTER_STATE);
                
                m_anotherFrame->setHidden(VFX_FALSE);
                m_frameEffect->applyEffect(m_anotherFrame, VCP_EFFECT_TRANSFORMER, 3000, VCP_EFFECT_DIRECTION_FROM_NONE, VFX_TRUE, NULL, 0);
                m_frameEffect->m_signalFinished.connect(this, &VtstRtSampleMenu1Scr::onFrameEffectFinished);
                m_isLeave = VFX_FALSE;

                m_menu->m_movingFrame = m_movingFrame;
                m_menu->m_focusPos2 = m_focusPos2;
                
                //m_menu->pushInSubCell(m_movingFrame, m_menu->getFocus(),0);
            }
            
            if (event.keyCode == VFX_KEY_CODE_4)
            {
                m_menu->configureStatePara(VCP_WHEEL_MENU_ENTER_STATE, 2000, 250, VCP_WHEEL_MENU_INCREASE);
                m_menu->changeState(VCP_WHEEL_MENU_ENTER_STATE);
            }
            
            if (event.keyCode == VFX_KEY_CODE_5)
            {
                m_menu->configureStatePara(VCP_WHEEL_MENU_LEAVE_STATE, 2000, 250, VCP_WHEEL_MENU_DECREASE);
                m_menu->changeState(VCP_WHEEL_MENU_LEAVE_STATE);
            }
            
            if (event.keyCode == VFX_KEY_CODE_6)
            {
                m_menu->configureStatePara(VCP_WHEEL_MENU_ENTER_STATE, 2000, 250, VCP_WHEEL_MENU_ALL_TOGETHER);
                m_menu->changeState(VCP_WHEEL_MENU_ENTER_STATE);
            }

            if (event.keyCode == VFX_KEY_CODE_7)
            {
                m_movingFrame = m_menu->pullOutSubCell(m_menu->getFocus(),0);
            }

            if (event.keyCode == VFX_KEY_CODE_8)
            {
                m_menu->pushInSubCell(m_movingFrame, m_menu->getFocus(),0);
            }
        }
        return Super::onKeyInput(event);
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

    void onFrameEffectFinished(VfxFrame *target, VfxBool isCompleted)
    {
        if (isCompleted)
        {
            if (m_isLeave)
            {
                m_menu->setHidden(VFX_TRUE);
                m_menu->m_movingFrame = NULL;
            }
            else
            {
                m_anotherFrame->setHidden(VFX_TRUE);
                
                //m_menu->m_movingFrame = m_movingFrame;
                //m_movingFrame->setFpeUser0(1);
               // m_menu->pushInSubCell(m_movingFrame, m_menu->getFocus(),0);
            }
        }
    }
};

VtstTestResultEnum vtst_rt_sample_menu_1(VfxU32 param)
{
    VFX_UNUSED(param);
    VTST_START_SCRN(VtstRtSampleMenu1Scr);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__
