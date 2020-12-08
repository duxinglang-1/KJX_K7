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

#include "vapp_camco_cp_base_menu.h"

#ifdef __VAPP_CAMCO__

VfxU8 VappCamcoCpBaseMenu::m_isleftmoving = 0;

VappCamcoCpBaseMenu* VappCamcoCpBaseMenuCell::getMenu()
{
    if (getParentFrame())
        return (VappCamcoCpBaseMenu*) getParentFrame();
    return NULL;
}

// TODO:
VfxS32 VappCamcoCpBaseMenuCell::getMenuPos()
{
    return 0;
}

void VappCamcoCpBaseMenuCell::onInit()
{
    VfxControl::onInit();
    
    sendToBack();
    setOpacity(1.0f);
    setAnchor(VfxFPoint(0.5, 0.5));
    //setBorderColor(VRT_COLOR_WHITE);
    setBorderWidth(0);
    
    setIsCached(VFX_TRUE);

    setAutoAnimate(VFX_TRUE);
    setBounds(VfxRect(0,0,CAMCO_SAMPLE_MENU_1_CELL_WIDTH,CAMCO_SAMPLE_MENU_1_CELL_HEIGHT));
    
    VFX_OBJ_CREATE(m_subImg, VfxImageFrame, this); 
    m_subImg->setAnchor(0.5,0.5);
    m_subImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
    m_subImg->setResId(IMG_ID_VAPP_CAMCO_SETTING_SPLITER_ICON);

    VFX_OBJ_CREATE(m_img, VfxImageFrame, this);  
    m_img->setAnchor(0.5,0.5);
    m_img->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
    
    m_highlight = VFX_FALSE;

    
}

void VappCamcoCpBaseMenuCell::onDeinit()
{
    VfxControl::onDeinit();
}

void VappCamcoCpBaseMenuCell::setBounds(const VfxRect &value)
{
    VfxControl::setBounds(value);
}

void VappCamcoCpBaseMenuCell::unclick(void)
{
    m_highlight = VFX_FALSE;
}

void VappCamcoCpBaseMenuCell::click(void)
{
    m_highlight = VFX_TRUE;                
    checkUpdate();        
}

void VappCamcoCpBaseMenuCell::setImg(VfxImageSrc img, VfxU32 fixedDimSize)
{
    if(m_mode & VAPP_CAMCO_CP_BM_MODE_IS_SEPARATED)
    {
        if(img.getSize().width > 100 || img.getSize().height > 100)
        {
            m_img->setImgContent(img);
            setBounds(VfxRect(0,0,40,30));
            m_img->setPos(getSize().width / 2, getSize().height / 2);
            m_img->setRect(VfxRect(0,0,getSize().width, getSize().height));        
        }
        else
        {
            m_img->setImgContent(img);
            setBounds(VfxRect(0,0,img.getSize().width,img.getSize().height));
            m_img->setPos(getSize().width / 2, getSize().height / 2);
            m_img->setRect(VfxRect(0,0,getSize().width, getSize().height));
        }        
    }
    else
    {
        if(m_mode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL)
        {
            m_img->setImgContent(img);
            setBounds(VfxRect(0, 0, img.getSize().width,fixedDimSize));    
            m_img->setPos(getSize().width / 2, getSize().height / 2);        
            m_subImg->setPos(getSize().width / 2, getSize().height  - (m_subImg->getSize().height>>1));              
        }
        else
        {
            m_img->setImgContent(img);
            setBounds(VfxRect(0, 0, fixedDimSize, img.getSize().height));    
            m_img->setPos(getSize().width / 2, getSize().height / 2);        
            m_subImg->setPos(getSize().width  - (m_subImg->getSize().height>1), getSize().height / 2);                          
        }
    }            
    
}


void VappCamcoCpBaseMenuCell::setMode(VfxU32 mode)
{
    m_mode = mode;

    m_subImg->setHidden(VFX_TRUE);
    
    if(m_mode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL)
    {        
        VfxTransform t;
        t.setIdentity();
        t.data.affine.rz = VFX_DEG_TO_RAD(0);
        m_subImg->setTransform(t);        
    }
    else
    {
        VfxTransform t;
        t.setIdentity();
        t.data.affine.rz = VFX_DEG_TO_RAD(90);
        m_subImg->setTransform(t);
    }  
        
        
}    

const VfxImageSrc& VappCamcoCpBaseMenuCell::getImg(void)
{
    return m_img->getImgContent();
}

void VappCamcoCpBaseMenuCell::setImageHidden(VfxBool ishidden)
{
    m_img->setHidden(ishidden);
}

void VappCamcoCpBaseMenu::onInit()
{       
    Super::onInit();
    
    setIsZSortChild(VFX_TRUE);

    VFX_OBJ_CREATE(m_bgFrame, VfxImageFrame, this);   
    m_bgFrame->setAnchor(0.5,0.5);
    m_bgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_bgFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_LEFT_BAR_ICON));    
    m_bgFrame->setPosZ(100);
    
    for(VfxU32 i = 0; i < VAPP_CAMCO_CP_BASE_MENU_MAX_CAOUNT; i++ )
    {
        m_cellDataSet[i] = VFX_FALSE;
    }
    
    VFX_OBJ_CREATE(m_effectImageFrame, VfxImageFrame, this);
    m_effectImageFrame->setHidden(VFX_TRUE);
    m_effectImageFrame->setAnchor(0.5,0.5);

    m_effectStep = 0;
    m_recoverEffectStep = 0;
    
    m_signalBoundsChanged.connect(this, &VappCamcoCpBaseMenu::onBoundUpdate);      

    m_isHorzUI = VFX_TRUE;
    m_isHorzFW = VFX_TRUE;    
    m_isMirrorUI = VFX_FALSE;

    m_count = 0;
}

void VappCamcoCpBaseMenu::onBoundUpdate(VfxFrame * f, const VfxRect & R)
{
    m_bgFrame->setPos(getSize().width>>1, getSize().height>>1);      

    if(getSize().width > getSize().height)
    {
        m_bgFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_V_LEFT_BAR_ICON));            
    }
    else    
    {
        m_bgFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_LEFT_BAR_ICON));            
    }
    m_bgFrame->setSize(getSize());
    reset();
}

VfxFrame* VappCamcoCpBaseMenu::createCell(VfxS32 cell, VfxS32 subcell)
{
    VappCamcoCpBaseMenuCell* item;
    
    VFX_OBJ_CREATE(item, VappCamcoCpBaseMenuCell, this);

    item->setBgColor(VFX_COLOR_TRANSPARENT);

    ASSERT(m_cellDataSet[cell]);

    MyWheelMenuUserData data;

    if(m_mode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL)
        data.verticalMode = VFX_TRUE;       
    else
        data.verticalMode = VFX_FALSE;   
    data.count = getCount();
    
    setCellUserData(cell, subcell, item, &data, sizeof(MyWheelMenuUserData));
    
    item->setMode(m_mode);        
    item->setFilterTiming(1.0f);        
    item->setPosZ(10);
    item->setFuzzy(VFX_TRUE);

    if(m_recoverEffectStep !=0 || m_effectStep != 0)
        item->setHidden(VFX_TRUE);
    
    if(m_mode & VAPP_CAMCO_CP_BM_MODE_IS_SEPARATED)
    {
        item->setImg(m_imglist[cell].getImageNormal(), 0);
    }
    else
    {
        if(m_mode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL)
            item->setImg(m_imglist[cell].getImageNormal(), m_imglist[cell].getImageNormal().getSize().height);
        else
            item->setImg(m_imglist[cell].getImageNormal(), m_imglist[cell].getImageNormal().getSize().width);                
    }
    item->setAnchor(0.5, 0.5);

    setCellRot((VfxImageFrame*)item);

    if(item->getImg().getResId() == m_effectImageFrame->getResId())
    {
        m_focusedItem = item;
    }

    return item;
}

void VappCamcoCpBaseMenu::onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* frame)
{
    if (cell == getFocus())
    {
        frame->bringToFront();
    }
}

void VappCamcoCpBaseMenu::onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame)
{
    VFX_UNUSED(cell);
    VFX_UNUSED(subcell);
    VFX_OBJ_CLOSE(cellFrame);
}

void VappCamcoCpBaseMenu::onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem)
{ 
    VappCamcoCpBaseMenuCell* item = (VappCamcoCpBaseMenuCell*) getCellIfPresent(previousFocusItem);        
    if(item)
        item->unclick();    
    item = (VappCamcoCpBaseMenuCell*) getCellIfPresent(focusItem);    
    if(item)        
        item->click();
    
}

void VappCamcoCpBaseMenu::onDragStart() 
{
}

void VappCamcoCpBaseMenu::onDragEnd(VfxS32 xspeed, VfxS32 yspeed)
{
    if(m_recoverEffectStep !=0 || m_effectStep != 0)
        return;
            
    if(m_mode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL)
    {    
        VFX_UNUSED(xspeed);
        if (yspeed == 0)
        {
            //setFocus(checkFocusIdx((VfxS32(getScrollIndex() + 0.5f))));
        }
        else
        {
            VfxS32   s      = yspeed > 0 ? 1 : -1;
            VfxFloat m      = VFX_ABS(yspeed) / 333.3f;
            
            if (m > 3) m = 3;
            
            setFocus(checkFocusIdx((VfxS32(getScrollIndex() - s * m + 0.5f))), 300);
        }
    }            
    else
    {
        VFX_UNUSED(yspeed);
        if (xspeed == 0)
        {
            //setFocus(checkFocusIdx((VfxS32(getScrollIndex() + 0.5f))));
        }
        else
        {
            VfxS32   s      = xspeed > 0 ? 1 : -1;
            VfxFloat m      = VFX_ABS(xspeed) / 333.3f;
            
            if (m > 3) m = 3;
            
            setFocus(checkFocusIdx((VfxS32(getScrollIndex() - s * m + 0.5f))), 300);
        }        
    }
}

void VappCamcoCpBaseMenu::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    if(m_recoverEffectStep !=0 || m_effectStep != 0)
        return;
        
    if(m_mode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL)
    {
        VFX_UNUSED(xoffset);

    #if defined(VAPP_CAMCO_OSD_LAYOUT_HVGA)
        setScrollIndex(checkFocusIdx2(getScrollIndex() - VfxFloat(yoffset) / 18), -1);    
    #elif defined(VAPP_CAMCO_OSD_LAYOUT_WVGA)
        setScrollIndex(checkFocusIdx2(getScrollIndex() - VfxFloat(yoffset) / 55), -1);    
    #elif defined(VAPP_CAMCO_OSD_LAYOUT_WQVGA)
        setScrollIndex(checkFocusIdx2(getScrollIndex() - VfxFloat(yoffset) / 55), -1);    
    #elif defined(VAPP_CAMCO_OSD_LAYOUT_QVGA)
        setScrollIndex(checkFocusIdx2(getScrollIndex() - VfxFloat(yoffset) / 55), -1);    
    #else
        setScrollIndex(checkFocusIdx2(getScrollIndex() - VfxFloat(yoffset) / 18), -1);    
    #endif
    }
    else
    {
        VFX_UNUSED(yoffset);

    #if defined(VAPP_CAMCO_OSD_LAYOUT_HVGA)
        setScrollIndex(checkFocusIdx2(getScrollIndex() - VfxFloat(xoffset) / 18), -1);    
    #elif defined(VAPP_CAMCO_OSD_LAYOUT_WVGA)
        setScrollIndex(checkFocusIdx2(getScrollIndex() - VfxFloat(xoffset) / 55), -1);    
    #elif defined(VAPP_CAMCO_OSD_LAYOUT_WQVGA)
        setScrollIndex(checkFocusIdx2(getScrollIndex() - VfxFloat(xoffset) / 55), -1);    
    #elif defined(VAPP_CAMCO_OSD_LAYOUT_QVGA)
        setScrollIndex(checkFocusIdx2(getScrollIndex() - VfxFloat(xoffset) / 55), -1);    
    #else
        setScrollIndex(checkFocusIdx2(getScrollIndex() - VfxFloat(xoffset) / 18), -1);    
    #endif    
    }
    m_signalMenuMoved.emit(0);    
}

// Notify when the menu is tapped
void VappCamcoCpBaseMenu::onTap(VfxPoint pt)
{   
    if(isAnimating())
        return;
    
    for(VfxU8 i = 0; i < VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT; i++)
    {
    
        VappCamcoCpBaseMenuCell* item = (VappCamcoCpBaseMenuCell*) getCellIfPresent(getFocus() + i - (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1));

        if(!item)
            continue;
        
        VfxPoint point = convertPointTo(pt, item);
        point.x -= item->forceGetPos().x;
        point.y -= item->forceGetPos().y;        
        
        
        if (item->containPoint(point, VFX_TRUE))
        {

            for(VfxU8 j = 0; j < getCount(); j++)
            {    
                VappCamcoCpBaseMenuCell* item = (VappCamcoCpBaseMenuCell*) getCellIfPresent(j);
                if(item)
                    item->unclick();
            }         
            
            m_nextFocus = ((getFocus() + i - (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1)));
            item->click();
            m_effectImageFrame->setImgContent(item->getImg());
            m_effectImageFrame->setPos(item->forceGetPos());   
            setCellRot(m_effectImageFrame);
            m_focusedItem = item;
            //m_signalItemSelected.emit(m_ID[getFocus()]);
            onEffectTimeline(NULL, VFX_TRUE);

            return;
        }
    }              
}

void VappCamcoCpBaseMenu::onStateChangeFinished(VcpWheelMenuState finishedstate)
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

void VappCamcoCpBaseMenu::onEffectTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted)
{

    if(m_effectStep == 0)
    {
        m_signalEnterEffectStart.emit(0);

        m_effectImageFrame->setHidden(VFX_FALSE);
        if(m_focusedItem.get())
            m_focusedItem.get()->setHidden(VFX_TRUE);             
        
        for(VfxU8 j = 0; j < getCount(); j++)
        {    
            VfxTransformTimeline *timeline;
            VfxTransform T;
            
            VappCamcoCpBaseMenuCell* item = (VappCamcoCpBaseMenuCell*) getCellIfPresent(j);
            if(!item)
                continue;

            setCellRot((VfxImageFrame*)item);            
            
            if(m_mode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL)
                T.data.affine.tx = -1 * getSize().width;
            else            
                T.data.affine.ty = -1 * getSize().height;
            T.data.affine.rz = item->getTransform().data.affine.rz;            
            
            VFX_OBJ_CREATE(timeline, VfxTransformTimeline, item);                      
            timeline->setTarget(item);
            timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
            timeline->setFromValue(item->getTransform());                        
            timeline->setToValue(T);
            timeline->setDurationTime(200);
            timeline->setRepeatCount(1);
            timeline->setAutoReversed(VFX_TRUE);
            timeline->start();  
            timeline->m_signalStopped.connect(this, &VappCamcoCpBaseMenu::onEndOfTimeline);            
        }
        

        VfxTransformTimeline *timeline;
        VfxTransform T;            

        VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);

        if(m_mode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL)
            T.data.affine.tx = -1 * getSize().width;
        else            
            T.data.affine.ty = -1 * getSize().height;
                  
        timeline->setTarget(m_bgFrame);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        timeline->setFromValue(getTransform());                        
        timeline->setToValue(T);
        timeline->setDurationTime(150);
        timeline->setRepeatCount(1);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->start();  
        timeline->m_signalStopped.connect(this, &VappCamcoCpBaseMenu::onEffectTimeline);
        
        m_effectStep = 1; 
    }
    else if(m_effectStep == 1)
    {           
        VFX_OBJ_CLOSE(timeline);   

        m_prevFocus = getFocus();
        setFocus(m_nextFocus, 0);

        for(VfxU8 j = 0; j < getCount(); j++)
        {    
            VappCamcoCpBaseMenuCell* item = (VappCamcoCpBaseMenuCell*) getCellIfPresent(j);
            if(item)
                item->setHidden(VFX_TRUE);
        }        
        m_bgFrame->setHidden(VFX_TRUE);
        

        VfxTransformTimeline *timeline;
        VfxTransform T;
        
        VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);


        if(m_mode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL)
            T.data.affine.ty = (getSize().height>>1) - m_effectImageFrame->getPos().y;
        else            
            T.data.affine.tx = (getSize().width>>1) - m_effectImageFrame->getPos().x;
        T.data.affine.rz = m_effectImageFrame->getTransform().data.affine.rz;
        
        m_effectImageFrame->setHidden(VFX_FALSE); 
        
        timeline->setTarget(m_effectImageFrame);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        timeline->setFromValue(m_effectImageFrame->getTransform());                        
        timeline->setToValue(T);
        timeline->setDurationTime(200);
        timeline->setRepeatCount(1);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->start();  
        timeline->m_signalStopped.connect(this, &VappCamcoCpBaseMenu::onEffectTimeline);
        
        m_effectStep = 2;             
        
    }
    else if(m_effectStep == 2)
    {
        m_effectImageFrame->setHidden(VFX_TRUE);    
        if(m_focusedItem.get())        
            m_focusedItem.get()->setHidden(VFX_FALSE);    
        
        VFX_OBJ_CLOSE(timeline);   
        MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_OSD_CP_BASE_MENU_SELECT, m_ID[getFocus()]);                
        m_signalItemSelected.emit(m_ID[getFocus()]);
        m_effectStep = 0;
    }
    
}  

void VappCamcoCpBaseMenu::onEndOfTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
}      

void VappCamcoCpBaseMenu::onRecoverEffectTimeline(VfxBaseTimeline *prevTimeline, VfxBool isCompleted)
{

    if(m_recoverEffectStep == 0)
    {
        m_effectImageFrame->setHidden(VFX_FALSE);   
        
        for(VfxU8 j = 0; j < getCount(); j++)
        {    
            VappCamcoCpBaseMenuCell* item = (VappCamcoCpBaseMenuCell*) getCellIfPresent(j);
            if(item)
                item->setHidden(VFX_TRUE);
        }        
        m_bgFrame->setHidden(VFX_TRUE);
        
        VfxTransformTimeline *timeline;
        
        VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);

        setCellRot(m_effectImageFrame);

        if(m_mode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL)
            m_effectImageFrame->setPos(m_effectImageFrame->getPos().x, (getSize().height>>1));
        else            
            m_effectImageFrame->setPos((getSize().width>>1), m_effectImageFrame->getPos().y);
        
        timeline->setTarget(m_effectImageFrame);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        timeline->setFromValue(m_effectImageFrame->getTransform());                        
        timeline->setToValue(m_effectImageFrame->getTransform());
        timeline->setDurationTime(100);
        timeline->setRepeatCount(1);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->start();  
        timeline->m_signalStopped.connect(this, &VappCamcoCpBaseMenu::onRecoverEffectTimeline);

        m_recoverEffectStep = 1; 

        
    }
    else if(m_recoverEffectStep == 1)
    {           
        VFX_OBJ_CLOSE(prevTimeline);   


        for(VfxU8 j = 0; j < getCount(); j++)
        {    
            VappCamcoCpBaseMenuCell* item = (VappCamcoCpBaseMenuCell*) getCellIfPresent(j);
            if(item)
                item->setHidden(VFX_FALSE);
        }        
        m_bgFrame->setHidden(VFX_FALSE);
        if(m_focusedItem.get())
            m_focusedItem.get()->setHidden(VFX_TRUE);              
        
        for(VfxU8 j = 0; j < getCount(); j++)
        {    
            VfxTransformTimeline *timeline;
            VfxTransform T;
            
            VappCamcoCpBaseMenuCell* item = (VappCamcoCpBaseMenuCell*) getCellIfPresent(j);
            if(!item)
                continue;

            setCellRot((VfxImageFrame*)item);  
            
            if(m_mode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL)
                T.data.affine.tx = -1 * getSize().width;
            else            
                T.data.affine.ty = -1 * getSize().height;
            T.data.affine.rz = item->getTransform().data.affine.rz;            
            
            VFX_OBJ_CREATE(timeline, VfxTransformTimeline, item);                      
            timeline->setTarget(item);
            timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
            timeline->setFromValue(T);                        
            timeline->setToValue(item->getTransform());
            timeline->setDurationTime(300);
            timeline->setRepeatCount(1);
            timeline->setAutoReversed(VFX_TRUE);
            timeline->start();  
            timeline->m_signalStopped.connect(this, &VappCamcoCpBaseMenu::onEndOfTimeline);            
        }
        

        VfxTransformTimeline *timeline;
        VfxTransform T;            

        VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);

        if(m_mode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL)
            T.data.affine.tx = -1 * getSize().width;
        else            
            T.data.affine.ty = -1 * getSize().height;
                  
        timeline->setTarget(m_bgFrame);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        timeline->setFromValue(T);                        
        timeline->setToValue(getTransform());
        timeline->setDurationTime(300);
        timeline->setRepeatCount(1);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->start();  
        timeline->m_signalStopped.connect(this, &VappCamcoCpBaseMenu::onRecoverEffectTimeline);
        
        m_recoverEffectStep = 2;             

        // make sure the previeous animation result will be shown before change it again
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->mustShowNextFrame(); 
        
    }
    else if(m_recoverEffectStep == 2)
    {
        m_effectImageFrame->setHidden(VFX_TRUE);  
        if(m_focusedItem.get())
            m_focusedItem.get()->setHidden(VFX_FALSE);                         
        VFX_OBJ_CLOSE(prevTimeline);   
        reset();
        m_recoverEffectStep = 0;
        m_signalLeaveEffectDone.emit(0);
    }

}    

void VappCamcoCpBaseMenu::recoverEffect(void)
{
    onRecoverEffectTimeline(NULL,VFX_TRUE);
}

VfxU32 VappCamcoCpBaseMenu::getRecoverEffectDur(void)
{
    return VAPP_CAMCO_CP_BASE_MENU_RECOVER_DUR;
}    

VappCamcoCpBaseMenuCell* VappCamcoCpBaseMenu::getCell(VfxU32 n)
{
    return (VappCamcoCpBaseMenuCell*) getCellIfPresent(n);
}

VfxU32 VappCamcoCpBaseMenu::getCellID(VfxU32 i)
{
    // return a invalid ID
    if(i > m_count)
        return 65536;
        
    return m_ID[i];
}


VfxS32 VappCamcoCpBaseMenu::getTapThreshold()
{
#if defined(VAPP_CAMCO_OSD_LAYOUT_HVGA)
    return 20;
#elif defined(VAPP_CAMCO_OSD_LAYOUT_WVGA)
    return 60;
#elif defined(VAPP_CAMCO_OSD_LAYOUT_WQVGA)
    return 40;
#elif defined(VAPP_CAMCO_OSD_LAYOUT_QVGA)
    return 40;
#else
    return 20;
#endif 
}

VfxS32 VappCamcoCpBaseMenu::getCount()
{
    return m_count;
}

VfxS32 VappCamcoCpBaseMenu::getBehindCount()
{
    if(!m_count)
        return 0;
        
    return (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1);
}

VfxS32 VappCamcoCpBaseMenu::getAheadCount()
{
    if(!m_count)
        return 0;
        
    return (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1);
}

VfxS32 VappCamcoCpBaseMenu::getPrevFocus()
{
    return m_prevFocus;
}

VfxS32 VappCamcoCpBaseMenu::getPostFocus() 
{   
    for(VfxU8 j = 0; j < getCount(); j++)
    {    
        if(m_effectImageFrame->getResId() ==  m_imglist[j].getImageNormal().getResId())
            return j;        
    }
    return m_nextFocus;
}

vrt_render_dirty_type_enum VappCamcoCpBaseMenu::myFrameEffectCB(
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

    VfxFloat offset = cell - fPos; 
    if(data->verticalMode)
    {
        VfxFloat h = (viewBounds.getHeight() / (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT - 0.5));
        VfxFloat d = h / 2;
        if(data->count < VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT)
        {
        }
        else if(data->count == VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT)
        {
            if(fPos  > (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1))
                VappCamcoCpBaseMenu::m_isleftmoving = 2;
            else if(fPos  < (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1))
                VappCamcoCpBaseMenu::m_isleftmoving = 1;

            if(VappCamcoCpBaseMenu::m_isleftmoving == 2)
                d = 0;                
        }
        else
        {        
            if((focus >= (data->count- (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1)) - 1))
                d = 0;
        }
        
        target_frame->pos.x = (viewBounds.getWidth()>>1);        
        target_frame->pos.y = d + (offset + (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1)) * h;     
        target_frame->opacity = 1;           

    }
    else
    {
        VfxFloat w = (viewBounds.getWidth() / (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT - 0.5));
        VfxFloat d = w/2;
        if(data->count < VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT)
        {
            d = 0;        	
        }
        else if(data->count == VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT)
        {
            if(fPos  > (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1))
                VappCamcoCpBaseMenu::m_isleftmoving = 2;
            else if(fPos  < (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1))
                VappCamcoCpBaseMenu::m_isleftmoving = 1;

            if(VappCamcoCpBaseMenu::m_isleftmoving == 2)
                d = 0;        
        }
        else
        {
            if(focus >= (data->count - (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1)) - 1)
                d = 0;
        }

        target_frame->pos.y = (viewBounds.getHeight()>>1);        
        target_frame->pos.x = d + (offset + (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1)) * w;     
        target_frame->opacity = 1;         

    }
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

VcpWheelMenuFrameEffectCBFuncPtr VappCamcoCpBaseMenu::getFrameEffectCB()
{
    return &VappCamcoCpBaseMenu::myFrameEffectCB;
}

void VappCamcoCpBaseMenu::setCellRot(VfxImageFrame* cell)
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
                        
            cell->setTransform(t);                                    
            
        }
        else
        {
            VfxTransform t;
            t.setIdentity();
            if(m_isMirrorUI)            
                t.data.affine.rz = VFX_DEG_TO_RAD(-270);        
            else                          
                t.data.affine.rz = VFX_DEG_TO_RAD(-90);        
            
            cell->setTransform(t);                                                         
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
            
            cell->setTransform(t);                                             
        }
        else
        {
            VfxTransform t;
            t.setIdentity();
            if(m_isMirrorUI)            
                t.data.affine.rz = VFX_DEG_TO_RAD(-180);        
            else              
                t.data.affine.rz = VFX_DEG_TO_RAD(0);        
                       
            cell->setTransform(t);                                         
        }    
    }

}

void VappCamcoCpBaseMenu::setRot(VfxBool isEnvHorz, VfxBool isCPHorz, VfxBool isCPMirror)
{
    m_isHorzUI = isCPHorz;
    m_isMirrorUI = isCPMirror;       
    m_isHorzFW = isEnvHorz;    

    if(isEnvHorz)
    {
        if(isCPHorz)
        {
            for(VfxU8 i = 0; i < VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT; i++)
            {            
                VappCamcoCpBaseMenuCell* item = (VappCamcoCpBaseMenuCell*) getCellIfPresent(getFocus() + i - (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1));

                if(!item)
                    continue;
            
                VfxTransform t;
                t.setIdentity();
                if(isCPMirror)            
                    t.data.affine.rz = VFX_DEG_TO_RAD(-180);
                else                    
                    t.data.affine.rz = VFX_DEG_TO_RAD(0);
                item->setTransform(t);                    
                
            }     
            
        }
        else
        {
            for(VfxU8 i = 0; i < VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT; i++)
            {            
                VappCamcoCpBaseMenuCell* item = (VappCamcoCpBaseMenuCell*) getCellIfPresent(getFocus() + i - (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1));

                if(!item)
                    continue;
            
                VfxTransform t;
                t.setIdentity();
                if(isCPMirror)            
                    t.data.affine.rz = VFX_DEG_TO_RAD(-270);
                else                  
                    t.data.affine.rz = VFX_DEG_TO_RAD(-90);
                item->setTransform(t);                    
                
            }           
        }
    }
    else
    {
        if(isCPHorz)
        {
            for(VfxU8 i = 0; i < VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT; i++)
            {            
                VappCamcoCpBaseMenuCell* item = (VappCamcoCpBaseMenuCell*) getCellIfPresent(getFocus() + i - (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1));

                if(!item)
                    continue;
            
                VfxTransform t;
                t.setIdentity();
                if(isCPMirror)            
                    t.data.affine.rz = VFX_DEG_TO_RAD(-90);
                else                  
                    t.data.affine.rz = VFX_DEG_TO_RAD(90);
                item->setTransform(t);                    
                
            }     

        }
        else
        {
            for(VfxU8 i = 0; i < VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT; i++)
            {            
                VappCamcoCpBaseMenuCell* item = (VappCamcoCpBaseMenuCell*) getCellIfPresent(getFocus() + i - (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1));

                if(!item)
                    continue;
            
                VfxTransform t;
                t.setIdentity();
                if(isCPMirror)            
                    t.data.affine.rz = VFX_DEG_TO_RAD(-180);
                else                  
                    t.data.affine.rz = VFX_DEG_TO_RAD(0);
                item->setTransform(t);                    
                
            }           
        }    
    }

}


void VappCamcoCpBaseMenu::searchFocusItem(VfxMsec animTime)
{
    for(VfxU8 j = 0; j < getCount(); j++)
    {    
        VappCamcoCpBaseMenuCell* item = (VappCamcoCpBaseMenuCell*) getCellIfPresent(j);
        if(item)
        {
            if(item->getImg().getResId() == m_effectImageFrame->getResId())
            {
                setFocus(j, animTime);
            }
        }
    }   
}

void VappCamcoCpBaseMenu::setFocus(VfxS32 focus, VfxMsec animTime)
{
    if(animTime != 0)
    {
        VcpWheelMenu::setFocus(focus, animTime);
    }
    else if(animTime == VAPP_CAMCO_CP_BASE_MENU_NO_ANIMATE)
    {
        VcpWheelMenu::setFocus(focus, 0);
    }
}

void VappCamcoCpBaseMenu::setFocusOnCenter(void)
{
    if(getCount() < VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT)
    {
        if(m_mode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL)
            setFocus(VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1, 0);
        else
            setFocus(getCount() - 1 - (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1), 0);
    }
    else
    {
        setFocus(getCount()>>1, 0);
    }
}

void VappCamcoCpBaseMenu::setFocusandCheck(VfxU32 f)
{
    if(getCount() < VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT)
    {
        if(m_mode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL)
            setFocus(VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1, 0);
        else
            setFocus(getCount() - 1 - (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1), 0);
    }
    else
    {
        if(m_mode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL)  
        {
            if(f > getCount() - 1 - (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1))        
                setFocus(getCount() - 1 - (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1), 0);
            else
                setFocus(f, 0);
        }
        else
        {
            if(f < (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1))
                setFocus((VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1), 0);                
            else
                setFocus(f, 0);        
        }
    }
}


void VappCamcoCpBaseMenu::setCount(VfxS32 count)
{
    ASSERT(count < VAPP_CAMCO_CP_BASE_MENU_MAX_CAOUNT);
    m_count = count;            

    reset();
    
    update();


    if(count < VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT)
    {
        if(m_prevFocus > VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1)
        {
            (m_prevFocus = VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1);
        }            
    }
}



void VappCamcoCpBaseMenu::setCellData(VfxU32 idx, VfxU32 ID, VcpStateImage imglist)
{
    m_ID[idx] = ID;
    m_imglist[idx] = imglist;
    m_cellDataSet[idx] = VFX_TRUE;
}


void VappCamcoCpBaseMenu::setMode(VfxU32 mode, VfxSize newSize)
{
    VfxU32 previousMode = m_mode;

    m_mode = mode;

    if((m_mode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL) && !(previousMode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL) ||
       !(m_mode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL) && (previousMode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL) )
    {
        setFocusandCheck(getFocus());

        if(m_mode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL)
            m_effectImageFrame->setPos(getSize().height - m_effectImageFrame->getPos().y, m_effectImageFrame->getPos().x);
        else
            m_effectImageFrame->setPos(m_effectImageFrame->getPos().y, getSize().height - m_effectImageFrame->getPos().x);            
    }
    setSize(newSize);
    
    reset();           
}

void VappCamcoCpBaseMenu::setHidden(VfxBool value)
{
    VcpWheelMenu::setHidden(value);    

    for(VfxU8 j = 0; j < getCount(); j++)
    {    
        VappCamcoCpBaseMenuCell* item = (VappCamcoCpBaseMenuCell*) getCellIfPresent(j);
        if(item)
            item->setHidden(value);
    }        
    m_bgFrame->setHidden(value);


}

void VappCamcoCpBaseMenu::reset(void)
{
    for(VfxU16 i = 0; i < m_count; i++)
    {    
        resetCell(i);
    }
}

VfxBool VappCamcoCpBaseMenu::isAnimating(void)
{
    if(m_recoverEffectStep !=0 || m_effectStep != 0 || getIsScrolling())
        return VFX_TRUE;
    else
        return VFX_FALSE;
}

VfxU32 VappCamcoCpBaseMenu::checkFocusIdx(VfxS32 idx)
{
    if(getCount() < VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT)
    {
        if(m_mode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL)
            return (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1);                
        else
            return (getCount() - 1 - (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1));              
    }

    if(idx > (getCount() - 1) - (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1))
        return ((getCount() - 1) - (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1)); 
        
    if(idx < (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1))
        return (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1);      

    return idx;
}

VfxFloat VappCamcoCpBaseMenu::checkFocusIdx2(VfxFloat idx)
{
    if(getCount() < VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT)
    {
        if(m_mode & VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL)
            return (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1);                
        else
            return (getCount() - 1 - (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1));              
    }
 
    if(idx > (getCount() - 1) - (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1) + 1)
        return ((getCount() - 1) - (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1) + 1); 
        
    if(idx < (VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1) - 1)
        return ((VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT>>1) - 1);      

	return idx;
}

#endif
