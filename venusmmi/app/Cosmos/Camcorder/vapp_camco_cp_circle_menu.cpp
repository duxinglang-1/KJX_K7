/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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

#include "vapp_camco_cp_circle_menu.h"

#ifdef __VAPP_CAMCO__

VappCamcoCpCircleMenu* VappCamcoCpCircleMenuCell::getMenu()
{
    if (getParentFrame())
        return (VappCamcoCpCircleMenu*) getParentFrame();
    return NULL;
}

VfxS32 VappCamcoCpCircleMenuCell::getMenuPos()
{
    return 0;
}
VfxS32 VappCamcoCpCircleMenuCell::getCelledge()
{
    return 0;
}

void VappCamcoCpCircleMenuCell::onInit()
{
    VfxControl::onInit();
    
    sendToBack();
    setOpacity(1.0f);
    setAnchor(VfxFPoint(0, 0));
    setBorderWidth(0);
    
    setIsCached(VFX_TRUE);
    setAutoAnimate(VFX_TRUE);
    
    VFX_OBJ_CREATE(m_img, VfxImageFrame, this);
    m_img->setAnchor(0.5, 0.5);

    updateLayout();
    
    m_highlight = VFX_FALSE;

    
}
void VappCamcoCpCircleMenuCell::onDeinit()
{
    VfxControl::onDeinit();
}

void VappCamcoCpCircleMenuCell::unclick(void)
{
    m_highlight = VFX_FALSE;    
    
    invalidate();
    
}
void VappCamcoCpCircleMenuCell::click(void)
{
    m_highlight = VFX_TRUE;    
    
    bringToFront();        
    checkUpdate();        
}

void VappCamcoCpCircleMenuCell::setMode(VfxBool isVerticalMode)
{
    m_isVerticalMode = isVerticalMode;
    updateLayout();
}

VfxU16 VappCamcoCpCircleMenuCell::getOffsetX(void)
{
    if(m_isVerticalMode)
    {
        return (m_img->getSize().width/ 2);
    }
    else
    {
        return (m_img->getSize().width/ 2);
    }
}

VfxU16 VappCamcoCpCircleMenuCell::getOffsetY(void)
{
    if(m_isVerticalMode)
    {
        return (m_img->getSize().height/ 2);
    }
    else
    {
        return (m_img->getSize().height/ 2);
    }

}

void VappCamcoCpCircleMenuCell::setPos(VfxS32 x, VfxS32 y)
{
    VfxControl::setPos(x,y);    
    updateLayout();
}

void VappCamcoCpCircleMenuCell::updateLayout(void)
{
    if(m_isVerticalMode)
    {
        m_img->setPos(getPos().x  + m_img->getSize().width/ 2, getPos().y  + m_img->getSize().height/ 2);             
        setSize(m_img->getSize());                    
    }
    else
    {        
        m_img->setPos(getPos().x  + m_img->getSize().width/ 2, getPos().y  + m_img->getSize().height/ 2);        
        setSize(m_img->getSize());                    
    }    

}
void VappCamcoCpCircleMenuCell::setImg(VfxImageSrc img)
{
    m_img->setImgContent(img);          
    m_img->setRect(VfxRect(0,0,img.getSize().width, img.getSize().height));     
    updateLayout();        
}

void VappCamcoCpCircleMenuCell::setRot(VfxTransform t)
{
    m_img->setTransform(t);
}

void VappCamcoCpCircleMenu::onInit()
{       
    Super::onInit();
    setIsZSortChild(VFX_TRUE);
    for(VfxU32 i = 0; i < VAPP_CAMCO_CP_CIRCLE_MENU_MAX_CAOUNT; i++ )
    {
        m_cellDataSet[i] = VFX_FALSE;
    }
     
    VFX_OBJ_CREATE(m_circle, VfxImageFrame, this);
    m_circle->setResId(IMG_ID_VAPP_CAMCO_WHEEL_BASE_ICON);
    m_circle->setAnchor(0.5, 0.5);
    m_circle->setPosZ(30);

    VFX_OBJ_CREATE(m_indicator, VfxImageFrame, this);
    m_indicator->setResId(IMG_ID_VAPP_CAMCO_WHEEL_IND_ICON);        
    m_indicator->setAnchor(0.5, 0.5);
    m_circle->setPosZ(20);        
    
    VFX_OBJ_CREATE(m_back, VcpImageButton, this);
    m_back->setAnchor(0.5, 0.5);
    m_back->setPosZ(20);   
    
    VFX_OBJ_CREATE(m_indicatortextBg, VfxImageFrame, this);
    m_indicatortextBg->setAnchor(0, 0.5);    
    m_indicatortextBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);        
    m_indicatortextBg->setResId(IMG_ID_VAPP_CAMCO_SETTING_NAME_ICON);
    m_indicatortextBg->setHidden(VFX_TRUE);
    
    VFX_OBJ_CREATE(m_indicatortext, VfxTextFrame, this);
    m_indicatortext->setAnchor(0,0.5);        
    m_indicatortext->setHidden(VFX_TRUE);
    
    
    VFX_OBJ_CREATE(m_textEffectTimer, VfxTimer, this);
    m_textEffectTimer->m_signalTick.connect(this, &VappCamcoCpCircleMenu::onTextEffectTimerTick);
    m_textEffectTimer->setStartDelay(1000);
    
    m_signalBoundsChanged.connect(this, &VappCamcoCpCircleMenu::onBoundUpdate);  
    m_back->m_signalClicked.connect(this, &VappCamcoCpCircleMenu::onBack);

    m_isAnimating = VFX_FALSE;
    m_isOnExitAnim = VFX_FALSE;

    m_isHorzUI = VFX_TRUE;
    m_isHorzFW = VFX_TRUE;    
    m_isMirrorUI = VFX_FALSE;
    
    m_count = 0;
    
}

void VappCamcoCpCircleMenu::onBoundUpdate(VfxFrame * f, const VfxRect & R)
{

    if(m_isVerticalMode)
    {
        m_back->setPos(g_vapp_camco_skin.SettingIconPos[0], getSize().height >>1);
        m_indicator->setPos(g_vapp_camco_skin.SettingIndPos[0], getSize().height >>1);
        m_circle->setPos(g_vapp_camco_skin.SettingPlatePos[0], getSize().height >>1);               
        
    }            
    else
    {
        m_back->setPos(getSize().width >>1, g_vapp_camco_skin.SettingIconPos[0]); 
        m_indicator->setPos(getSize().width>>1, g_vapp_camco_skin.SettingIndPos[0]);
        m_circle->setPos(getSize().width >>1, g_vapp_camco_skin.SettingPlatePos[0]);                 
 
    }
}

void VappCamcoCpCircleMenu::onBack(VfxObject* sender, VfxId id)
{
    if(m_isAnimating)        
        return;
    
    m_signalClicked.postEmit(this, id);
}

void VappCamcoCpCircleMenu::onTextEffectTimerTick(VfxTimer *source)
{
    VappCamcoCpCircleMenuCell* item = (VappCamcoCpCircleMenuCell*) getCellIfPresent(getFocus());
    if(item)
        item->unclick();

    m_indicatortextBg->setHidden(VFX_TRUE);
    m_indicatortext->setHidden(VFX_TRUE);        
    
    update();
}

VfxFrame* VappCamcoCpCircleMenu::createCell(VfxS32 cell, VfxS32 subcell)
{
    VappCamcoCpCircleMenuCell* item;
    
    VFX_OBJ_CREATE(item, VappCamcoCpCircleMenuCell, this);

    item->setBgColor(VRT_COLOR_TRANSPARENT);
    
    ASSERT(m_cellDataSet[cell]);
    item->setMode(!m_isVerticalMode);
    item->setFilterTiming(1.0f);
    item->setImg(m_imglist[cell].getImageNormal());
    
    if(cell == getFocus())
    {
        item->click();       
    }
    else
    {
        item->unclick();               
    }
    item->setPosZ(10);
    item->setFuzzy(VFX_TRUE);
    
    setCellRot(item);

    CircleMenuUserData data;
    data.verticalMode = m_isVerticalMode;    
    data.loc_offset_x = item->getOffsetX();
    data.loc_offset_y = item->getOffsetY();        
    setCellUserData(cell, subcell, item, &data, sizeof(CircleMenuUserData));


    return item;
}

void VappCamcoCpCircleMenu::onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* frame)
{
    if (cell == getFocus())
    {
        frame->bringToFront();

        
    }
}

void VappCamcoCpCircleMenu::onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame)
{
    VFX_UNUSED(cell);
    VFX_UNUSED(subcell);
    VFX_OBJ_CLOSE(cellFrame);
}

void VappCamcoCpCircleMenu::onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem)
{ 
    updateFocus(getFocus());

    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_OSD_CP_CIRCLE_MENU_SELECT, m_ID[getFocus()]);    

    m_signalItemSet.emit(m_ID[getFocus()]); 
    
    updateText();
    m_indicatortextBg->setHidden(VFX_FALSE);
    m_indicatortext->setHidden(VFX_FALSE);    
    
    m_textEffectTimer->start();    
}

void VappCamcoCpCircleMenu::setFocus(VfxS32 index, VfxMsec animTime)
{       
    VcpWheelMenu::setFocus(index, animTime);

    if(index < 0 || index > getCount())
        return;
    
    for(VfxU8 j = 0; j < getCount(); j++)
    {    
        VappCamcoCpCircleMenuCell* item = (VappCamcoCpCircleMenuCell*) getCellIfPresent(j);
        if(item)
            item->unclick();
    } 
    
    VappCamcoCpCircleMenuCell* item = (VappCamcoCpCircleMenuCell*) getCellIfPresent(getFocus());    
    if(item)        
    {
        item->click();     

        updateText();        
        m_indicatortextBg->setHidden(VFX_FALSE);
        m_indicatortext->setHidden(VFX_FALSE);            
        
        m_textEffectTimer->start();            
    }
    
}

void VappCamcoCpCircleMenu::onDragStart() 
{
    VappCamcoCpCircleMenuCell* item = (VappCamcoCpCircleMenuCell*) getCellIfPresent(getFocus());

    item->click();    
    m_textEffectTimer->stop();
}

void VappCamcoCpCircleMenu::onDragEnd(VfxS32 xspeed, VfxS32 yspeed)
{
    if(m_isVerticalMode)
    {    
        VFX_UNUSED(xspeed);
        setFocus((VfxS32(getScrollIndex() + 0.5f)));
    }            
    else
    {
        VFX_UNUSED(yspeed);
        setFocus((VfxS32(getScrollIndex() + 0.5f)));
    }

}

void VappCamcoCpCircleMenu::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    if(m_isVerticalMode)
    {
        VFX_UNUSED(xoffset);

        VfxFloat s = (getScrollIndex() - VfxFloat(yoffset) / 55);
        if(s < -1)
            s = -1;
        if(s > m_count + 1)
            s = m_count;
        
        setScrollIndex(s, 0);
    }
    else
    {
        VFX_UNUSED(yoffset);

        VfxFloat s = (getScrollIndex() - VfxFloat(xoffset) / 55);
        if(s < -1)
            s = -1;
        if(s > m_count + 1)
            s = m_count + 1;

        setScrollIndex(s, 0);
    
    }
    if((VfxS32(getScrollIndex() + 0.5f)) != getFocus())
    {
        setFocus((VfxS32(getScrollIndex() + 0.5f)));    
        m_signalMenuMoved.emit(0);    
    }
}


void VappCamcoCpCircleMenu::onTap(VfxPoint pt)
{       
    if(m_isAnimating)        
        return;
    
    for(VfxU8 i = 0; i < VAPP_CAMCO_CP_CIRCLE_MENU_SHOWN_COUNT; i++)
    {
    
        VappCamcoCpCircleMenuCell* item = (VappCamcoCpCircleMenuCell*) getCellIfPresent(getFocus() + i - (VAPP_CAMCO_CP_CIRCLE_MENU_SHOWN_COUNT>>1));

        if(!item)
            continue;
        
        VfxPoint point = convertPointTo(pt, item);
        point.x -= item->forceGetPos().x;
        point.y -= item->forceGetPos().y;        
        
        if (item->containPoint(point, VFX_TRUE))
        {
            for(VfxU8 j = 0; j < getCount(); j++)
            {    
                VappCamcoCpCircleMenuCell* item = (VappCamcoCpCircleMenuCell*) getCellIfPresent(j);
                if(item)
                    item->unclick();
            }                 

            item->click();   
            
            setFocus((getFocus() + i - (VAPP_CAMCO_CP_CIRCLE_MENU_SHOWN_COUNT>>1)));            
            MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_OSD_CP_CIRCLE_MENU_SELECT, m_ID[getFocus()]);                
            m_signalItemSet.emit(m_ID[getFocus()]);
            return;
        }
    }          
    m_signalClicked.postEmit(this, 0);    
}

void VappCamcoCpCircleMenu::setCellRot(VappCamcoCpCircleMenuCell* cell)
{

    if(m_isHorzFW)
    {
        if(m_isHorzUI)
        {
            VfxTransform t;
            t.setIdentity();
            if(m_isMirrorUI)            
                t.data.affine.rz = VFX_DEG_TO_RAD(-180);
            else
                t.data.affine.rz = VFX_DEG_TO_RAD(0);            
                        
            cell->setRot(t);                                    
            
        }
        else
        {
            VfxTransform t;
            t.setIdentity();
            if(m_isMirrorUI)            
                t.data.affine.rz = VFX_DEG_TO_RAD(-270);
            else            
                t.data.affine.rz = VFX_DEG_TO_RAD(-90);                      
            
            cell->setRot(t);                                                         
        }
    }
    else
    {
        if(m_isHorzUI)
        {
            
            VfxTransform t;
            t.setIdentity();
            if(m_isMirrorUI)            
                t.data.affine.rz = VFX_DEG_TO_RAD(-90);
            else            
                t.data.affine.rz = VFX_DEG_TO_RAD(90);                   
            
            cell->setRot(t);                                             
        }
        else
        {
            VfxTransform t;
            t.setIdentity();     
            if(m_isMirrorUI)            
                t.data.affine.rz = VFX_DEG_TO_RAD(-180);
            else            
                t.data.affine.rz = VFX_DEG_TO_RAD(0);   
            
            cell->setRot(t);                                         
        }    
    }

}

void VappCamcoCpCircleMenu::setRot(VfxBool isEnvHorz, VfxBool isCPHorz, VfxBool isCPMirror)
{
    m_isHorzUI = isCPHorz;
    m_isMirrorUI = isCPMirror;       
    m_isHorzFW = isEnvHorz;    

    if(isEnvHorz)
    {
        if(isCPHorz)
        {
            VfxTransform t;
            t.setIdentity();
            if(isCPMirror)            
                t.data.affine.rz = VFX_DEG_TO_RAD(-180);
            else
                t.data.affine.rz = VFX_DEG_TO_RAD(0);
            
            for(VfxU8 i = 0; i < VAPP_CAMCO_CP_CIRCLE_MENU_SHOWN_COUNT; i++)
            {
            
                VappCamcoCpCircleMenuCell* item = (VappCamcoCpCircleMenuCell*) getCellIfPresent(getFocus() + i - (VAPP_CAMCO_CP_CIRCLE_MENU_SHOWN_COUNT>>1));

                if(!item)
                    continue;
            
                item->setRot(t);                                    
            }  
            m_back->setTransform(t);  

            if(isCPMirror)   
            {
                t.data.affine.tx = (m_indicatortextBg->getSize().width);                
            }
            m_indicatortextBg->setTransform(t);

            if(isCPMirror)   
            {
                t.data.affine.tx = (m_indicatortext->getSize().width);                
            }
            m_indicatortext->setTransform(t);
            
        }
        else
        {
            VfxTransform t;
            t.setIdentity();
            if(isCPMirror)            
                t.data.affine.rz = VFX_DEG_TO_RAD(-270);
            else            
                t.data.affine.rz = VFX_DEG_TO_RAD(-90);        
            
            for(VfxU8 i = 0; i < VAPP_CAMCO_CP_CIRCLE_MENU_SHOWN_COUNT; i++)
            {
            
                VappCamcoCpCircleMenuCell* item = (VappCamcoCpCircleMenuCell*) getCellIfPresent(getFocus() + i - (VAPP_CAMCO_CP_CIRCLE_MENU_SHOWN_COUNT>>1));

                if(!item)
                    continue;
            
                item->setRot(t);                                             
            }           
            m_back->setTransform(t);      

            if(isCPMirror)      
            {
                t.data.affine.ty = -(m_indicatortextBg->getSize().width >> 1); 
                t.data.affine.tx = (m_indicatortextBg->getSize().height>> 1);
            }
            else
            {
                t.data.affine.ty = (m_indicatortextBg->getSize().width >> 1); 
                t.data.affine.tx = (m_indicatortextBg->getSize().height>> 1);
            }                
            m_indicatortextBg->setTransform(t);

            if(isCPMirror)      
            {
                t.data.affine.ty = -(m_indicatortext->getSize().width >> 1);         
                t.data.affine.tx = (m_indicatortextBg->getSize().height>> 1) - TEXT_SPACE;
            }
            else
            {
                t.data.affine.ty = (m_indicatortext->getSize().width >> 1);         
                t.data.affine.tx = (m_indicatortextBg->getSize().height>> 1) - TEXT_SPACE;
            }                
            m_indicatortext->setTransform(t);            
        }
    }
    else
    {
        if(isCPHorz)
        {
            
            VfxTransform t;
            t.setIdentity();
            if(isCPMirror)            
                t.data.affine.rz = VFX_DEG_TO_RAD(-90);
            else            
                t.data.affine.rz = VFX_DEG_TO_RAD(90);        
            
            for(VfxU8 i = 0; i < VAPP_CAMCO_CP_CIRCLE_MENU_SHOWN_COUNT; i++)
            {
            
                VappCamcoCpCircleMenuCell* item = (VappCamcoCpCircleMenuCell*) getCellIfPresent(getFocus() + i - (VAPP_CAMCO_CP_CIRCLE_MENU_SHOWN_COUNT>>1));

                if(!item)
                    continue;

                item->setRot(t);                                             
            }     
            m_back->setTransform(t);           

            if(isCPMirror)      
            {
                t.data.affine.ty = (m_indicatortextBg->getSize().width >> 1) - (m_indicatortextBg->getSize().height >> 1);
            }
            else
            {
                t.data.affine.ty = (m_indicatortextBg->getSize().width >> 1) - (m_indicatortextBg->getSize().height >> 1);
            }               
            m_indicatortextBg->setTransform(t);        

            if(isCPMirror)      
            {
                t.data.affine.ty = (m_indicatortextBg->getSize().width >> 1) - (m_indicatortextBg->getSize().height >> 1);
            }
            else
            {
                t.data.affine.ty = (m_indicatortextBg->getSize().width >> 1) - (m_indicatortextBg->getSize().height >> 1);
            }                
            m_indicatortext->setTransform(t);

        }
        else
        {
            VfxTransform t;
            t.setIdentity();
            if(isCPMirror)            
                t.data.affine.rz = VFX_DEG_TO_RAD(-180);
            else            
                t.data.affine.rz = VFX_DEG_TO_RAD(0);        
            
            for(VfxU8 i = 0; i < VAPP_CAMCO_CP_CIRCLE_MENU_SHOWN_COUNT; i++)
            {
            
                VappCamcoCpCircleMenuCell* item = (VappCamcoCpCircleMenuCell*) getCellIfPresent(getFocus() + i - (VAPP_CAMCO_CP_CIRCLE_MENU_SHOWN_COUNT>>1));

                if(!item)
                    continue;
           
                item->setRot(t);                                         
            }    
            m_back->setTransform(t);            
            m_indicatortextBg->setTransform(t);
            m_indicatortext->setTransform(t);            
        }    
    }

}

void VappCamcoCpCircleMenu::setVerticalMode(VfxBool v)
{
    m_isVerticalMode = v;
    if(m_isVerticalMode)
    {
        VfxTransform t;
        t.setIdentity();
        t.data.affine.rz = VFX_DEG_TO_RAD(0);
        
        m_circle->setTransform(t);
        m_indicator->setTransform(t);
    }
    else
    {
        VfxTransform t;
        t.setIdentity();
        t.data.affine.rz = VFX_DEG_TO_RAD(90);
        
        m_circle->setTransform(t);
        m_indicator->setTransform(t);            
    }
    updateText();
    
    reset();
}

VfxS32 VappCamcoCpCircleMenu::getCount()
{
    return m_count;
}

VfxS32 VappCamcoCpCircleMenu::getBehindCount()
{
    if(!m_count)
        return 0;
        
    return (VAPP_CAMCO_CP_CIRCLE_MENU_SHOWN_COUNT>>1);
}

VfxS32 VappCamcoCpCircleMenu::getAheadCount()
{
    if(!m_count)
        return 0;
        
    return (VAPP_CAMCO_CP_CIRCLE_MENU_SHOWN_COUNT>>1);
}

vrt_render_dirty_type_enum VappCamcoCpCircleMenu::myFrameEffectCB(
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

    VFX_DEV_ASSERT(userDataSize == sizeof(CircleMenuUserData));

    CircleMenuUserData* data = (CircleMenuUserData*)userData;

    VfxFloat offset = cell - fPos; 
    
    if(data->verticalMode)
    {         
        VfxU32 R = g_vapp_camco_skin.Rad; //((viewBounds.getHeight() - 40)>>1);  
        VfxU32 n = (VAPP_CAMCO_CP_CIRCLE_MENU_SHOWN_COUNT>>1);        

        target_frame->pos.x = g_vapp_camco_skin.radOffset + R * vfxCos(VFX_DEG_TO_RAD((90.0*vfxAbs(offset)/n))) - data->loc_offset_x;
        target_frame->pos.y = (viewBounds.getHeight()>>1) + R * vfxSin(VFX_DEG_TO_RAD((90.0*offset/n)))- data->loc_offset_y;
    }
    else
    {   
        VfxU32 R = g_vapp_camco_skin.Rad; //((viewBounds.getWidth() - 40)>>1);       
        VfxU32 n = (VAPP_CAMCO_CP_CIRCLE_MENU_SHOWN_COUNT>>1);        

        target_frame->pos.y = g_vapp_camco_skin.radOffset + R * vfxCos(VFX_DEG_TO_RAD((90.0*vfxAbs(offset)/n))) - data->loc_offset_y;
        target_frame->pos.x = (viewBounds.getWidth()>>1) + R * vfxSin(VFX_DEG_TO_RAD((90.0*offset/n))) - data->loc_offset_x;
    }
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

VcpWheelMenuFrameEffectCBFuncPtr VappCamcoCpCircleMenu::getFrameEffectCB()
{
    return &VappCamcoCpCircleMenu::myFrameEffectCB;
}

void VappCamcoCpCircleMenu::onStateChangeFinished(VcpWheelMenuState finishedstate)
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

void VappCamcoCpCircleMenu::updateFocus(VfxU32 i)
{
    for(VfxU8 j = 0; j < getCount(); j++)
    {    
        if(i != j)
        {        
            VappCamcoCpCircleMenuCell* item = (VappCamcoCpCircleMenuCell*) getCellIfPresent(j, 0);
            if(item)
                item->unclick();
        }
        else
        {                   
            VappCamcoCpCircleMenuCell* item = (VappCamcoCpCircleMenuCell*) getCellIfPresent(j, 0);
            if(item)
                item->click();
        }
    }                        

}

void VappCamcoCpCircleMenu::updateText(void)
{  

#if defined(VAPP_CAMCO_OSD_LAYOUT_QVGA)
    VfxFontDesc font = m_indicatortext->getFont();
    font.size = VFX_FONT_DESC_VF_SIZE(15);
    m_indicatortext->setFont(font);    
#endif

    m_indicatortext->setString(m_text[getFocus()]);    
    m_indicatortextBg->setSize(m_indicatortext->getSize().width + TEXT_SPACE * 2, VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_NAME_ICON).getSize().height);    
    
    // it mean Horz UI
    if(m_isVerticalMode)
    {
        m_indicatortextBg->setAnchor(0, 0.5);
        m_indicatortext->setAnchor(0, 0.5);            
        m_indicatortextBg->setPos(m_circle->getPos().x + m_circle->getSize().width/ 2 + 15 , m_circle->getPos().y);
        m_indicatortext->setPos(m_indicatortextBg->getPos().x + TEXT_SPACE, m_circle->getPos().y);
    }
    //it mean Vert UI
    else
    {
        m_indicatortextBg->setAnchor(0.5, 0.5);
        m_indicatortext->setAnchor(0.5, 0.5);
        m_indicatortextBg->setPos(m_circle->getPos().x, m_circle->getPos().y + (m_circle->getSize().width/2) + 17 + (VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_NAME_ICON).getSize().height / 2)); 
        m_indicatortext->setPos(m_indicatortextBg->getPos().x, m_indicatortextBg->getPos().y);                 
    }

    setRot(m_isHorzFW, m_isHorzUI, m_isMirrorUI);

}

void VappCamcoCpCircleMenu::reset(void)
{
    for(VfxU16 i = 0; i < m_count; i++)
    {    
        resetCell(i);
    }
}

    
void VappCamcoCpCircleMenu::setCount(VfxS32 count)
{
    ASSERT(count < VAPP_CAMCO_CP_CIRCLE_MENU_MAX_CAOUNT);
    m_count = count;        
    update();
}

void VappCamcoCpCircleMenu::setSettingImg(VcpStateImage imglist)
{
    m_back->setImage(imglist);        
    m_back->setSize(imglist.getImageNormal().getSize().width, imglist.getImageNormal().getSize().height);    
    onBoundUpdate(this, getBounds());
}

VfxBool VappCamcoCpCircleMenu::onPenInput(VfxPenEvent & event)
{

    if(m_isAnimating || getHidden())
        return VFX_TRUE;

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {    
        VappCamcoCpCircleMenuCell* item = (VappCamcoCpCircleMenuCell*) getCellIfPresent(getFocus());
        VfxPoint pos(event.getRelPos(this));

        if(item)
        {            
            if(m_isVerticalMode)
            {
                if(pos.x > m_circle->getPos().x + (m_circle->getSize().width * 0.8))
                {
                    return VFX_FALSE;        
                }        
            }
            else
            {
                if(pos.y > m_circle->getPos().y + (m_circle->getSize().width * 0.8))
                {
                    return VFX_FALSE;        
                }                        
            }
        }

    }                
    return VcpWheelMenu::onPenInput(event);
}


void VappCamcoCpCircleMenu::setCellData(VfxU32 idx, VfxU32 ID, VcpStateImage imglist, const VfxWString & value)
{
    m_ID[idx] = ID;
    m_imglist[idx] = imglist;
    m_cellDataSet[idx] = VFX_TRUE;
    m_text[idx] = value;
}

void VappCamcoCpCircleMenu::setHidden(VfxBool value)
{
    VfxBool hiddenStatus = getHidden();
    
    VcpWheelMenu::setHidden(value);

    if(hiddenStatus == VFX_TRUE && value == VFX_FALSE)
    {
        m_signalEnterEffectStart.emit(0);
        
        VfxTransformTimeline *timeline;
        VfxTransform T;
        
        VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);


        T.data.affine.sx = 24.0 / getSize().width; 
        T.data.affine.sy = 24.0 / getSize().height;
                    
        timeline->setTarget(this);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        timeline->setFromValue(T);
                    
        timeline->setToValue(getTransform());
        timeline->setDurationTime(VAPP_CAMCO_CP_CIRCLE_MENU_RECOVER_DUR);
        timeline->setRepeatCount(1);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->start();  
        timeline->m_signalStopped.connect(this, &VappCamcoCpCircleMenu::onEndOfTimeline);

        m_isAnimating = VFX_TRUE;

    }

}

void VappCamcoCpCircleMenu::recoverEffect(void)
{
    VfxTransformTimeline *timeline;
    VfxTransform T;
    
    VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);


    T.data.affine.sx = 24.0 / getSize().width; 
    T.data.affine.sy = 24.0 / getSize().height;
                
    timeline->setTarget(this);
    timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
    timeline->setFromValue(getTransform());
                
    timeline->setToValue(T);
    timeline->setDurationTime(VAPP_CAMCO_CP_CIRCLE_MENU_RECOVER_DUR);
    timeline->setRepeatCount(1);
    timeline->setAutoReversed(VFX_TRUE);
    timeline->start();  
    timeline->m_signalStopped.connect(this, &VappCamcoCpCircleMenu::onEndOfTimeline);

    m_isAnimating = VFX_TRUE;

    m_isOnExitAnim = VFX_TRUE;


}
void VappCamcoCpCircleMenu::onEndOfTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    m_isAnimating = VFX_FALSE;
    VFX_OBJ_CLOSE(timeline);    
    if(m_isOnExitAnim)
    {
        m_isOnExitAnim = VFX_FALSE;
        m_signalLeaveEffectDone.emit(0);    
    }
}

VfxU32 VappCamcoCpCircleMenu::getRecoverEffectDur(void)
{
    return VAPP_CAMCO_CP_CIRCLE_MENU_RECOVER_DUR;
}

VfxBool VappCamcoCpCircleMenu::isAnimating(void)
{
    return m_isAnimating;
}


#endif
