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

#include "vapp_camco_cp_advance_menu.h"

#ifdef __VAPP_CAMCO__

void VappCamcoCpItemContentProvider::onInit()
{
    VfxFrame::onInit();
    m_count = 0;
    
}

void VappCamcoCpItemContentProvider::setCount(VfxU32 count)
{
    m_count = count;
}

VfxU32 VappCamcoCpItemContentProvider::getCount() const
{
    return m_count;
}

void VappCamcoCpItemContentProvider::setItemText(VfxU32 index, VfxU32 content, VfxU32 icon)
{
    ASSERT(index < m_count);
    m_textContent[index] = content;
    m_imgID[index] = icon;
}

VfxBool VappCamcoCpItemContentProvider::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT) 
    {
        if (index >0 && index < m_count)
        {
            text = VFX_WSTR_RES(m_textContent[index]); 
            return VFX_TRUE; 
        }
    }

    return VFX_FALSE;
}

VfxBool VappCamcoCpItemContentProvider::getItemTextFrameFormat(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxTextFrame * frame)
{
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        VfxFontDesc font = frame->getFont();
    #if defined(VAPP_CAMCO_OSD_LAYOUT_HVGA)
        font.size = VFX_FONT_DESC_VF_SIZE(19);
    #elif defined(VAPP_CAMCO_OSD_LAYOUT_WVGA)
        font.size = VFX_FONT_DESC_VF_SIZE(25);
    #elif defined(VAPP_CAMCO_OSD_LAYOUT_WQVGA)
        font.size = VFX_FONT_DESC_VF_SIZE(16);
    #elif defined(VAPP_CAMCO_OSD_LAYOUT_QVGA)
        font.size = VFX_FONT_DESC_VF_SIZE(14);    
    #else
        font.size = VFX_FONT_DESC_VF_SIZE(19);
    #endif            
        frame->setFont(font);    
    }
    return VFX_TRUE;
}


VfxBool VappCamcoCpItemContentProvider::getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc &image)
{

    if (fieldType == VCP_LIST_MENU_FIELD_ICON ) 
    {
        if (index >0 && index < m_count)
        {
            image.setResId(m_imgID[index]);
            return VFX_TRUE; // Required if set the image successfully
        }
    }

    return VFX_FALSE;
}

VcpListMenuItemStateEnum VappCamcoCpItemContentProvider::getItemState(VfxU32 index) const 
{ 
    if(m_selected_idx == index)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;        
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
}


VcpListMenuCellBaseControl* VappCamcoCpItemContentProvider::getItemCustomControl(
    VfxU32 index,                                    
    VcpListMenuCellControlLocationTypeEnum location, 
    VfxFrame *parentFrame                            
    )
{
    if((location == VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL))
    {
        VfxImageSrc image(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
        VappCamcoCpMenuCusItemMark *m_mark;
        VFX_OBJ_CREATE_EX(m_mark, VappCamcoCpMenuCusItemMark, parentFrame, (VFX_FALSE));
        VFX_OBJ_CREATE(m_mark->m_imageFrame, VfxImageFrame, m_mark);               
        m_mark->m_imageFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_MENU_IND_ICON));
        return (VcpListMenuCellBaseControl*)m_mark;
    }
    return NULL;
}


VfxBool VappCamcoCpItemContentProvider::swapItem(
    VfxU32 index1, 
    VfxU32 index2 
    ) 
{    
    return VFX_TRUE;
}


void VappCamcoCpItemContentProvider::setSelectedIdx(VfxU32 idx)
{
    m_selected_idx = idx;    
}



VappCamcoCpAdvanceMenu* VappCamcoCpAdvanceMenuCell::getMenu()
{
    if (getParentFrame())
        return (VappCamcoCpAdvanceMenu*) getParentFrame();
    return NULL;
}

VfxS32 VappCamcoCpAdvanceMenuCell::getMenuPos()
{
    return 0;
}

void VappCamcoCpAdvanceMenuCell::onInit()
{
    VfxControl::onInit();
    
    sendToBack();
    setOpacity(1.0f);
    setAnchor(VfxFPoint(0.5, 0.5));
    setBorderWidth(0);
    
    setIsCached(VFX_TRUE);


    setAutoAnimate(VFX_TRUE);
    setBounds(VfxRect(0,0,getSize().width, getSize().height));
    
    VFX_OBJ_CREATE(m_img, VfxImageFrame, this);
    m_img->setAnchor(0.5,0.5);

    m_highlight = VFX_FALSE;

    m_signalBoundsChanged.connect(this, &VappCamcoCpAdvanceMenuCell::onBoundUpdate);

    
}
void VappCamcoCpAdvanceMenuCell::onDeinit()
{
    VfxControl::onDeinit();
}

void VappCamcoCpAdvanceMenuCell::onBoundUpdate(VfxFrame * f, const VfxRect & R)
{
    m_img->setPos(m_img->getSize().width / 2, getSize().height / 2);

}

void VappCamcoCpAdvanceMenuCell::unclick(void)
{
    m_highlight = VFX_FALSE;    
    
    
}
void VappCamcoCpAdvanceMenuCell::click(void)
{
    m_highlight = VFX_TRUE;
    
}

void VappCamcoCpAdvanceMenuCell::setImg(VfxImageSrc img)
{
    m_img->setImgContent(img);  
    setSize(m_img->getSize().width, m_img->getSize().height);
}



VappCamcoCpAdvanceMenu* VappCamcoCpAdvanceMenuSubCell::getMenu()
{
    if (getParentFrame())
        return (VappCamcoCpAdvanceMenu*) getParentFrame();
    return NULL;
}

VfxS32 VappCamcoCpAdvanceMenuSubCell::getMenuPos()
{
    return 0;
}

void VappCamcoCpAdvanceMenuSubCell::onInit()
{
    VfxControl::onInit();
    
    setOpacity(1.0f);
    setAnchor(VfxFPoint(0, 0.5));
    setBorderWidth(0);
    
    setIsCached(VFX_TRUE);

    setAutoAnimate(VFX_TRUE);
    setBounds(VfxRect(0,0,getSize().width, getSize().height));

    VFX_OBJ_CREATE(m_text, VfxTextFrame, this);
    VfxFontDesc font;    
#if defined(VAPP_CAMCO_OSD_LAYOUT_HVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(19);
#elif defined(VAPP_CAMCO_OSD_LAYOUT_WVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(25);
#elif defined(VAPP_CAMCO_OSD_LAYOUT_WQVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(16);
#elif defined(VAPP_CAMCO_OSD_LAYOUT_QVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(14);    
#else
    font.size = VFX_FONT_DESC_VF_SIZE(19);
#endif    
    m_text->setFont(font);    
    m_text->setAnchor(0,0.5);    
    m_text->setBgColor(VFX_COLOR_TRANSPARENT);

    m_signalBoundsChanged.connect(this, &VappCamcoCpAdvanceMenuSubCell::onBoundUpdate);

    
}
void VappCamcoCpAdvanceMenuSubCell::onDeinit()
{
    VfxControl::onDeinit();
}

void VappCamcoCpAdvanceMenuSubCell::onBoundUpdate(VfxFrame * f, const VfxRect & R)
{
    m_text->setPos(40, getSize().height / 2);

}

void VappCamcoCpAdvanceMenuSubCell::unclick(void)
{
    m_highlight = VFX_FALSE;  
    //setBgColor(VFX_COLOR_GREY);
    //setOpacity(0.3);
    m_text->setColor(VFX_COLOR_GREY);
    checkUpdate();       

}
void VappCamcoCpAdvanceMenuSubCell::click(void)
{
    m_highlight = VFX_TRUE;
    //setBgColor(VFX_COLOR_BLACK);
    //setOpacity(1);
    m_text->setColor(VFX_COLOR_WHITE);        
    checkUpdate();          
}

void VappCamcoCpAdvanceMenuSubCell::setText(const VfxWString & value)
{
    m_text->setString(value);  
    onBoundUpdate(this, getRect());        
}    

VfxU32 VappCamcoCpAdvanceMenu::m_menuHeight = 0;

void VappCamcoCpAdvanceMenu::onInit()
{       
    Super::onInit();
    
    setIsZSortChild(VFX_TRUE);
    
    for(VfxU32 i = 0; i < VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CAOUNT; i++ )
    {
        m_cellDataSet[i] = VFX_FALSE;
    }

    VfxImageSrc imgsrc;
    imgsrc.setResId(IMG_ID_VAPP_CAMCO_AD_SETTING_BG_ICON);
    VFX_OBJ_CREATE(m_background, VfxFrame, this);
    m_background->setImgContent(imgsrc);
    m_background->setAnchor(0, 0);
    m_background->setPos(0, 0);    
    m_background->setPosZ(30);    
    m_background->setSize(imgsrc.getSize().width, imgsrc.getSize().height);
    m_background->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_TOP_LEFT);
    
    VFX_OBJ_CREATE(m_circle, VfxImageFrame, this);
    m_circle->setResId(IMG_ID_VAPP_CAMCO_WHEEL_BASE_ICON);
    m_circle->setAnchor(0.5, 0.5);
    m_circle->setPosZ(20);

    VFX_OBJ_CREATE(m_indicator, VfxImageFrame, this);
    m_indicator->setResId(IMG_ID_VAPP_CAMCO_WHEEL_IND_ICON);        
    m_indicator->setAnchor(0.5, 0.5);
    m_indicator->setPosZ(2);

    VFX_OBJ_CREATE(m_back, VcpImageButton, this);
    m_back->setAnchor(0.5, 0.5);           
    VcpStateImage imglist;
    imglist.setImage(IMG_ID_VAPP_CAMCO_RESET_ICON, IMG_ID_VAPP_CAMCO_RESET_ICON, IMG_ID_VAPP_CAMCO_RESET_ICON, IMG_ID_VAPP_CAMCO_RESET_ICON);
    m_back->setImage(imglist);        
    m_back->setPosZ(10);
    
    VFX_OBJ_CREATE(m_itemMenuContentProvider, VappCamcoCpItemContentProvider, this);
    VFX_OBJ_CREATE(m_itemMenu, VcpListMenu, this);    
    m_itemMenu->setAnchor(0.5, 0.5);           
    m_itemMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT); 
    m_itemMenu->setContentProvider((IVcpListMenuContentProvider*)m_itemMenuContentProvider); 
    m_itemMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE); 
    m_itemMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_FALSE); 
    m_itemMenu->m_signalItemSelectionStateChanged.connect(this, &VappCamcoCpAdvanceMenu::onSelectionChanged); 
    m_itemMenu->setThemeData(m_menu_theme);
    m_itemMenu->setShadowIsDisabled(VFX_TRUE);
    m_itemMenu->setOpacity(0.9);
    m_itemMenu->setPosZ(5);      
    m_itemMenu->enableVerticalScrollIndicator(VFX_TRUE);  
    m_itemMenu->setScrollIndicatorStyle(VcpScrollable::VC_SCROLLABLE_SCROLL_INDICATOR_STYLE_FIXED);      
    m_itemMenu->setScrollIndicatorColor(VFX_COLOR_SILVER);
    m_itemMenu->setItemSeparatorHidden(VFX_TRUE);
    
    m_signalBoundsChanged.connect(this, &VappCamcoCpAdvanceMenu::onBoundUpdate);  
    m_back->m_signalClicked.connect(this, &VappCamcoCpAdvanceMenu::onBack);     

    m_menuLeftPartRatio = g_vapp_camco_skin.Ratio;

    m_effectStep = 0;
    m_recoverEffectStep = 0;

    m_isItemTap = VFX_FALSE; 

    m_count = 0;
    
    VFX_OBJ_CREATE(m_effectTimer, VfxTimer, this);
    
}

void VappCamcoCpAdvanceMenu::onDeinit()
{
    VFX_OBJ_CLOSE(m_itemMenuContentProvider);
    m_itemMenuContentProvider = NULL;
    m_itemMenu->setContentProvider(NULL);     
    VcpWheelMenu::onDeinit();
}

void VappCamcoCpAdvanceMenu::onBack(VfxObject* sender, VfxId id)
{
    if(isAnimating())      
        return;
    
    m_signalClicked.postEmit(sender, id);
}

void VappCamcoCpAdvanceMenu::onSelectionChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState)
{
    if (newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {            
        m_itemMenuContentProvider->setSelectedIdx(index);
        MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_OSD_CP_AD_MENU_SELECT, m_ID[getFocus()], m_itemID[index]);    
        m_signalItemSelected.emit(m_ID[getFocus()], m_itemID[index]);  
    }
    m_signalMenuMoved.emit(0);
}

void VappCamcoCpAdvanceMenu::onBoundUpdate(VfxFrame * f, const VfxRect & R)
{

    m_menuHeight = m_background->getSize().height;

    m_back->setPos(g_vapp_camco_skin.SettingIconPos[0], (getSize().height >>1) - 1);    
    m_indicator->setPos(g_vapp_camco_skin.SettingIndPos[0], getSize().height >>1);
    m_circle->setPos(g_vapp_camco_skin.SettingPlatePos[0], getSize().height >>1);    

    m_background->setPos(0, ((getSize().height -  m_background->getSize().height)>>1));   
    m_background->setBounds(0, 0, getSize().width * m_menuLeftPartRatio + 1, m_background->getSize().height);

    if((getSize().height %2) == 0)
        m_itemMenu->setPos(getSize().width * ((1 + m_menuLeftPartRatio) / 2), (getSize().height >>1) - 1);
    else
        m_itemMenu->setPos(getSize().width * ((1 + m_menuLeftPartRatio) / 2), (getSize().height >>1));        
    m_itemMenu->setSize(getSize().width * (1 - m_menuLeftPartRatio), m_menuHeight);
    m_itemMenu->setItemHeight(m_menuHeight / VAPP_CAMCO_CP_ADVANCE_MENU_SHOWN_COUNT);

}

VfxFrame* VappCamcoCpAdvanceMenu::createCell(VfxS32 cell, VfxS32 subcell)
{

    ASSERT(m_cellDataSet[cell]);


    if(subcell == 0)
    {
        VappCamcoCpAdvanceMenuCell* item;        
        VFX_OBJ_CREATE(item, VappCamcoCpAdvanceMenuCell, this);
        
        item->setBgColor(VRT_COLOR_TRANSPARENT);
        item->setSize(getSize().width * m_menuLeftPartRatio , getSize().height / VAPP_CAMCO_CP_ADVANCE_MENU_SHOWN_COUNT );
        item->setPosZ(10);       
        
        MyWheelMenuUserData data;
        data.limitLength = getSize().width * m_menuLeftPartRatio;
        setCellUserData(cell, subcell, item, &data, sizeof(MyWheelMenuUserData));

        item->setFilterTiming(1.0f);

        item->setImg(m_imglist[cell].getImageNormal());

        
        if(getFocus() == cell)
        {
            item->click();
        }
        else
        {
            item->unclick();
        }                
        return item;
    }
    else
    {
        VappCamcoCpAdvanceMenuSubCell* item;        
        VFX_OBJ_CREATE(item, VappCamcoCpAdvanceMenuSubCell, this);
        
        item->setSize(getSize().width * m_menuLeftPartRatio , getSize().height / VAPP_CAMCO_CP_ADVANCE_MENU_SHOWN_COUNT );
        item->setPosZ(30);      
        
        MyWheelMenuUserData data;
        data.limitLength = getSize().width * m_menuLeftPartRatio;
        setCellUserData(cell, subcell, item, &data, sizeof(MyWheelMenuUserData));        
        item->setFilterTiming(1.0f);

        if(m_effectStep == 1)
        {
            item->setHidden(VFX_TRUE);
        }
        else
        {
            item->setHidden(VFX_FALSE);            
        }
        
        item->setText(m_text[cell]);   
        if(getFocus() == cell)
        {
            item->click();
        }
        else
        {
            item->unclick();
        }           

        return item;
    }

}

void VappCamcoCpAdvanceMenu::onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* frame)
{
    if (cell == getFocus())
    {
        //frame->bringToFront();
        m_circle->sendToBack();
    }
}

void VappCamcoCpAdvanceMenu::onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame)
{       
    VFX_UNUSED(cell);
    VFX_UNUSED(subcell);
    VFX_OBJ_CLOSE(cellFrame);
}

void VappCamcoCpAdvanceMenu::onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem)
{
    updateFocus(getFocus());
    
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_OSD_CP_AD_MENU_TRAVERSE, m_ID[getFocus()]);            
    m_signalTraversed.emit(m_ID[getFocus()]);  
}


void VappCamcoCpAdvanceMenu::onDragStart() 
{
}

void VappCamcoCpAdvanceMenu::onDragEnd(VfxS32 xspeed, VfxS32 yspeed)
{
    if(!m_isItemTap)
        return;

    VFX_UNUSED(xspeed);
    if (yspeed == 0)
    {
        setFocus( ((VfxS32(getScrollIndex() + 0.5f))));
    }
    else
    {
        VfxS32   s      = yspeed > 0 ? 1 : -1;
        VfxFloat m      = VFX_ABS(yspeed) / 333.3f;
        
        if (m > 3) m = 3;
        
        setFocus( ((VfxS32(getScrollIndex() - s * m + 0.5f))), 300);
    }
    m_isItemTap = VFX_FALSE;    
}

void VappCamcoCpAdvanceMenu::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    if(!m_isItemTap)
        return;
    
    VFX_UNUSED(xoffset);

    VfxFloat newIdx = getScrollIndex();
    newIdx -= (VfxFloat(yoffset) / (m_background->getSize().height/VAPP_CAMCO_CP_ADVANCE_MENU_SHOWN_COUNT));
    setScrollIndex(checkFocusIdx(newIdx), 0);

    m_signalMenuMoved.emit(0);
}

// Notify when the menu is tapped
void VappCamcoCpAdvanceMenu::onTap(VfxPoint pt)
{      
    if(isAnimating())
        return;    
    
    for(VfxU8 i = 0; i < VAPP_CAMCO_CP_ADVANCE_MENU_SHOWN_COUNT; i++)
    {        
        VappCamcoCpAdvanceMenuCell* item = (VappCamcoCpAdvanceMenuCell*) getCellIfPresent(getFocus() + i - (VAPP_CAMCO_CP_ADVANCE_MENU_SHOWN_COUNT>>1), 0);
        VappCamcoCpAdvanceMenuSubCell* subitem = (VappCamcoCpAdvanceMenuSubCell*) getCellIfPresent(getFocus() + i - (VAPP_CAMCO_CP_ADVANCE_MENU_SHOWN_COUNT>>1), 1);

        if(item)
        {
            VfxPoint point = convertPointTo(pt, item);
            point.x -= item->forceGetPos().x;
            point.y -= item->forceGetPos().y;        
            
            if (item->getBounds().contains(point))
            {
                setFocus(((getFocus() + i - (VAPP_CAMCO_CP_ADVANCE_MENU_SHOWN_COUNT>>1))));
                updateFocus(getFocus());                

                MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_OSD_CP_AD_MENU_TRAVERSE, m_ID[getFocus()]);        
                m_signalTraversed.emit(m_ID[getFocus()]);          
                return;
            }
        }

        if(subitem)
        {
            VfxPoint point = convertPointTo(pt, subitem);
            point.x -= subitem->forceGetPos().x;
            point.y -= subitem->forceGetPos().y;  
            
            if(subitem->getBounds().contains(point))
            {
                setFocus(((getFocus() + i - (VAPP_CAMCO_CP_ADVANCE_MENU_SHOWN_COUNT>>1))));
                updateFocus(getFocus());                

                MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_OSD_CP_AD_MENU_TRAVERSE, m_ID[getFocus()]);        
                m_signalTraversed.emit(m_ID[getFocus()]);
                return;
            }            
        }
    }    
    
    // for right menu part, no need to fuzzy the touch region
    // if user tap on the outer region of menu
    // return back event 
    VfxPoint point = convertPointTo(pt, this);    
    if(!getBounds().contains(point))
    {
        if(point.x > m_circle->getPos().x + (m_circle->getSize().width * 0.7))
        {
            m_signalClicked.postEmit(this, 0);    
        }
    }
}

VfxBool VappCamcoCpAdvanceMenu::onPenInput(VfxPenEvent & event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {    
        VfxPoint pos(event.getRelPos(this));
        
        // if touch on menu part, no need to triger drag event
        if(pos.x > m_itemMenu->getPos().x - (m_itemMenu->getSize().width>>1))
        {
            m_isItemTap = VFX_FALSE;        
        }        
        else
        {
            m_isItemTap = VFX_TRUE;        
        }
    }                
    return VcpWheelMenu::onPenInput(event);
}

void VappCamcoCpAdvanceMenu::updateFocus(VfxU32 i)
{
    for(VfxU8 j = 0; j < getCount(); j++)
    {    
        if(i != j)
        {
    
            kal_char s[60];
            sprintf(s,"unclick %d \n",j);
            printf(s);            
            VappCamcoCpAdvanceMenuCell* item = (VappCamcoCpAdvanceMenuCell*) getCellIfPresent(j, 0);
            if(item)
                item->unclick();

            VappCamcoCpAdvanceMenuSubCell* subitem = (VappCamcoCpAdvanceMenuSubCell*) getCellIfPresent(j, 1);
            if(subitem)
                subitem->unclick();         
        }
        else
        {
            kal_char s[60];
            sprintf(s,"click %d \n",j);
            printf(s);                        
            VappCamcoCpAdvanceMenuCell* item = (VappCamcoCpAdvanceMenuCell*) getCellIfPresent(j, 0);
            if(item)
                item->click();

            VappCamcoCpAdvanceMenuSubCell* subitem = (VappCamcoCpAdvanceMenuSubCell*) getCellIfPresent(j, 1);
            if(subitem)
                subitem->click();     
        }

    }                        

}

VfxS32 VappCamcoCpAdvanceMenu::getCount()
{
    return m_count;
}

VfxS32 VappCamcoCpAdvanceMenu::getSubCellCount()
{
    return 2;
}

VfxS32 VappCamcoCpAdvanceMenu::getBehindCount()
{
    if(!m_count)
        return 0;
    
    return (VAPP_CAMCO_CP_ADVANCE_MENU_SHOWN_COUNT>>1);
}

VfxS32 VappCamcoCpAdvanceMenu::getAheadCount()
{
    if(!m_count)
        return 0;

    return (VAPP_CAMCO_CP_ADVANCE_MENU_SHOWN_COUNT>>1);
}

vrt_render_dirty_type_enum VappCamcoCpAdvanceMenu::myFrameEffectCB(
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

    VfxFloat offset = cell - fPos; 
    if(vfxAbs(offset) <= (VAPP_CAMCO_CP_ADVANCE_MENU_SHOWN_COUNT>>1))        
    {
        if(subCell == 0)
        {
            VfxU32 R = g_vapp_camco_skin.Rad; //((viewBounds.getHeight() - 40)>>1);
            VfxU32 n = (VAPP_CAMCO_CP_ADVANCE_MENU_SHOWN_COUNT>>1);

            target_frame->pos.x = g_vapp_camco_skin.radOffset + R * vfxCos(VFX_DEG_TO_RAD((90.0*vfxAbs(offset)/n)));
            target_frame->pos.y = (viewBounds.getHeight()>>1) + R * vfxSin(VFX_DEG_TO_RAD((90.0*offset/n)));

            target_frame->opacity = 1;
        }
        else
        {
            VfxFloat h = target_frame->bounds.size.height;
            VfxU32 R = g_vapp_camco_skin.Rad; //((viewBounds.getHeight() - 40)>>1);
            VfxU32 n = (VAPP_CAMCO_CP_ADVANCE_MENU_SHOWN_COUNT>>1);

            target_frame->pos.x = g_vapp_camco_skin.radOffset + g_vapp_camco_skin.textOffset + 0.4 * R * vfxCos(VFX_DEG_TO_RAD((90.0*vfxAbs(offset)/n)));
            target_frame->pos.y = (viewBounds.getHeight()>>1) + offset * h - 1;     
            
            target_frame->opacity = 1;            
        }
    }
    else
    {
        target_frame->opacity = 0;       
    }

    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

VcpWheelMenuFrameEffectCBFuncPtr VappCamcoCpAdvanceMenu::getFrameEffectCB()
{
    return &VappCamcoCpAdvanceMenu::myFrameEffectCB;
}

void VappCamcoCpAdvanceMenu::setRot(VfxBool isEnvHorz, VfxBool isCPHorz, VfxBool isCPMirror)
{
    m_isHorzUI = isCPHorz;
    m_isMirrorUI = isCPMirror;    
    m_isHorzFW = isEnvHorz;    
}

void VappCamcoCpAdvanceMenu::onStateChangeFinished(VcpWheelMenuState finishedstate)
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

void VappCamcoCpAdvanceMenu::setSettingImg(VcpStateImage imglist)
{
    m_back->setImage(imglist);        
    m_back->setSize(imglist.getImageNormal().getSize().width, imglist.getImageNormal().getSize().height);    
    onBoundUpdate(this, getBounds());
}
    
void VappCamcoCpAdvanceMenu::setCount(VfxS32 count)
{
    ASSERT(count < VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CAOUNT);
    m_count = count;        
    update();
}

void VappCamcoCpAdvanceMenu::setMenuitemRatio(VfxFloat L1Ratio) 
{
    m_menuLeftPartRatio = L1Ratio;
}


void VappCamcoCpAdvanceMenu::setCellData(VfxU32 idx, VfxU32 ID, VcpStateImage imglist, const VfxWString & value)
{
    m_ID[idx] = ID;
    m_imglist[idx] = imglist;
    m_cellDataSet[idx] = VFX_TRUE;
    m_text[idx] = value;
}

void VappCamcoCpAdvanceMenu::setitemData(VfxU32 idx, VfxU32 ID, VfxU32 icon, VfxU32 str_id)        
{  
    m_itemID[idx] = ID;
    m_itemMenuContentProvider->setItemText(idx, str_id, icon); 
}

void VappCamcoCpAdvanceMenu::setitemCount(VfxU32 count)        
{    
    m_itemMenuContentProvider->setCount(count); 
}

void VappCamcoCpAdvanceMenu::setItemFocus(VfxU32 idx)        
{    
    m_itemMenuContentProvider->setSelectedIdx(idx);
    m_itemMenu->setItemState(idx, VCP_LIST_MENU_ITEM_STATE_SELECTED);
    m_itemMenu->setVisibleMenuItem(idx);
       
}   

void VappCamcoCpAdvanceMenu::updateItem(void)
{
    m_itemMenu->resetAllItems();   
}

void VappCamcoCpAdvanceMenu::reset(void)
{
    for(VfxU16 i = 0; i < m_count; i++)
    {    
        resetCell(i);
    }
}    

void VappCamcoCpAdvanceMenu::setHidden(VfxBool value)
{
    VfxBool hiddenStatus = getHidden();
    
    VcpWheelMenu::setHidden(value);

    if(hiddenStatus == VFX_TRUE && value == VFX_FALSE)
    {
        onEffectTimeline(NULL,VFX_TRUE);
    }

}
void VappCamcoCpAdvanceMenu::onEffect(VfxTimer *source)
{
    onEffectTimeline(NULL,VFX_TRUE);
}

void VappCamcoCpAdvanceMenu::onEffectTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    if(m_effectStep == 0)
    {
        m_signalEnterEffectStart.emit(0);
        
        for(VfxU8 i = 0; i < getCount(); i++)
        {           
            VappCamcoCpAdvanceMenuSubCell* subitem = (VappCamcoCpAdvanceMenuSubCell*) getCellIfPresent(i, 1);
            if(subitem)
                subitem->setHidden(VFX_TRUE);
        }
        m_itemMenu->setHidden(VFX_TRUE);
        m_background->setHidden(VFX_TRUE);
    
        VfxTransformTimeline *timeline;
        VfxTransform T;
        
        VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);

        T.data.affine.sx = 24.0 / getSize().width; 
        T.data.affine.sy = 24.0 / getSize().height;
                    
        timeline->setTarget(this);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        timeline->setFromValue(T);
                    
        timeline->setToValue(getTransform());
        timeline->setDurationTime(350);
        timeline->setRepeatCount(1);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->start();  
        timeline->m_signalStopped.connect(this, &VappCamcoCpAdvanceMenu::onEffectTimeline);

        m_effectStep = 1;
                    
    }
    else if(m_effectStep == 1)
    {
        VFX_OBJ_CLOSE(timeline);   
                
        for(VfxU8 i = 0; i < getCount(); i++)
        {           
            VappCamcoCpAdvanceMenuSubCell* subitem = (VappCamcoCpAdvanceMenuSubCell*) getCellIfPresent(i , 1);
            if(subitem)
            {
                subitem->setHidden(VFX_FALSE);
            
                VfxTransformTimeline *timeline;
                VfxTransform T;
                
                VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);

                T.data.affine.tx = -1 * subitem->getSize().width; 
                            
                timeline->setTarget(subitem);
                timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
                timeline->setFromValue(T);
                            
                timeline->setToValue(getTransform());
                timeline->setDurationTime(150);
                timeline->setRepeatCount(1);
                timeline->setAutoReversed(VFX_TRUE);
                timeline->start();  
                timeline->m_signalStopped.connect(this, &VappCamcoCpAdvanceMenu::onEndOfTimeline);                   
            }
        }   
        
        m_itemMenu->setHidden(VFX_FALSE);

        VfxTransformTimeline *timeline;
        VfxTransform T;
        
        VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);

        T.data.affine.tx = -1 * m_itemMenu->getSize().width; 
                    
        timeline->setTarget(m_itemMenu);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        timeline->setFromValue(T);
                    
        timeline->setToValue(getTransform());
        timeline->setDurationTime(150);
        timeline->setRepeatCount(1);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->start();  
        timeline->m_signalStopped.connect(this, &VappCamcoCpAdvanceMenu::onEndOfTimeline);     

        VfxTransformTimeline *timeline2;
        
        VFX_OBJ_CREATE(timeline2, VfxTransformTimeline, this);

        m_background->setHidden(VFX_FALSE);

        T.data.affine.tx = -1 * m_background->getSize().width; 
                    
        timeline2->setTarget(m_background);
        timeline2->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        timeline2->setFromValue(T);
                    
        timeline2->setToValue(getTransform());
        timeline2->setDurationTime(150);
        timeline2->setRepeatCount(1);
        timeline2->setAutoReversed(VFX_TRUE);
        timeline2->start();  
        timeline2->m_signalStopped.connect(this, &VappCamcoCpAdvanceMenu::onEffectTimeline);     
        
        m_effectStep = 2;
    }            
    else if(m_effectStep == 2)
    {
        VFX_OBJ_CLOSE(timeline);           
        m_effectStep = 0;
        
    }        
}

void VappCamcoCpAdvanceMenu::onRecoverEffectTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    if(m_recoverEffectStep == 0)
    {
        m_itemMenu->setHidden(VFX_FALSE);

        VfxTransformTimeline *timeline;
        VfxTransform T;
        
        VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);

        T.data.affine.tx = -1 * m_background->getSize().width; 
                    
        timeline->setTarget(m_itemMenu);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        timeline->setFromValue(getTransform());
                    
        timeline->setToValue(T);
        timeline->setDurationTime(150);
        timeline->setRepeatCount(1);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->start();  
        timeline->m_signalStopped.connect(this, &VappCamcoCpAdvanceMenu::onRecoverEffectTimeline); 

        m_background->setHidden(VFX_FALSE);      

        VfxTransformTimeline *timeline2;
        
        VFX_OBJ_CREATE(timeline2, VfxTransformTimeline, this);

        T.data.affine.tx = -1 * m_background->getSize().width; 
                    
        timeline2->setTarget(m_background);
        timeline2->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        timeline2->setFromValue(getTransform());
                    
        timeline2->setToValue(T);
        timeline2->setDurationTime(150);
        timeline2->setRepeatCount(1);
        timeline2->setAutoReversed(VFX_TRUE);
        timeline2->start();  
        timeline2->m_signalStopped.connect(this, &VappCamcoCpAdvanceMenu::onEndOfTimeline); 
        
        for(VfxU8 i = 0; i < getCount(); i++)
        {           
            VappCamcoCpAdvanceMenuSubCell* subitem = (VappCamcoCpAdvanceMenuSubCell*) getCellIfPresent(i , 1);
            if(subitem)
            {
                //subitem->setHidden(VFX_FALSE);
            
                VfxTransformTimeline *timeline;
                VfxTransform T;
                
                VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);

                T.data.affine.tx = -1 * m_background->getSize().width; 
                            
                timeline->setTarget(subitem);
                timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
                timeline->setFromValue(getTransform());
                            
                timeline->setToValue(T);
                timeline->setDurationTime(140);
                timeline->setRepeatCount(1);
                timeline->setAutoReversed(VFX_TRUE);
                timeline->start();  

                timeline->m_signalStopped.connect(this, &VappCamcoCpAdvanceMenu::onEndOfTimeline);    
            }
        }  
        
        m_recoverEffectStep = 1;
    }
    else if(m_recoverEffectStep == 1)
    {
        VFX_OBJ_CLOSE(timeline);  

        for(VfxU8 i = 0; i < getCount(); i++)
        {           
            VappCamcoCpAdvanceMenuSubCell* subitem = (VappCamcoCpAdvanceMenuSubCell*) getCellIfPresent(i, 1);
            if(subitem)
                subitem->setHidden(VFX_TRUE);
        }
        m_itemMenu->setHidden(VFX_TRUE);       
        m_background->setHidden(VFX_TRUE);  

        VfxTransformTimeline *timeline;
        VfxTransform T;
        
        VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);
                    
        timeline->setTarget(m_background);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        timeline->setFromValue(getTransform());
                    
        timeline->setToValue(T);
        timeline->setDurationTime(10);
        timeline->setRepeatCount(1);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->start();  
        timeline->m_signalStopped.connect(this, &VappCamcoCpAdvanceMenu::onRecoverEffectTimeline); 
        
        m_recoverEffectStep = 2;
    }        
    else if(m_recoverEffectStep == 2)
    {
        VFX_OBJ_CLOSE(timeline);  

        for(VfxU8 i = 0; i < getCount(); i++)
        {           
            VappCamcoCpAdvanceMenuSubCell* subitem = (VappCamcoCpAdvanceMenuSubCell*) getCellIfPresent(i, 1);
            if(subitem)
                subitem->setHidden(VFX_TRUE);
        }
        m_itemMenu->setHidden(VFX_TRUE);       
        m_background->setHidden(VFX_TRUE);       
        
        VfxTransformTimeline *timeline;
        VfxTransform T;
        
        VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);

        T.data.affine.sx = 24.0 / getSize().width; 
        T.data.affine.sy = 24.0 / getSize().height;
                    
        timeline->setTarget(this);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        timeline->setFromValue(getTransform());
                    
        timeline->setToValue(T);
        timeline->setDurationTime(350);
        timeline->setRepeatCount(1);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->start();  
        timeline->m_signalStopped.connect(this, &VappCamcoCpAdvanceMenu::onRecoverEffectTimeline);                  

        m_recoverEffectStep = 3;
        
    }                
    else if(m_recoverEffectStep == 3)
    {
        VFX_OBJ_CLOSE(timeline);         

        for(VfxU8 i = 0; i < getCount(); i++)
        {           
            VappCamcoCpAdvanceMenuSubCell* subitem = (VappCamcoCpAdvanceMenuSubCell*) getCellIfPresent(i, 1);
            if(subitem)
                subitem->setHidden(VFX_FALSE);
        }
        m_itemMenu->setHidden(VFX_FALSE);      
        m_background->setHidden(VFX_FALSE);      
        
        m_recoverEffectStep = 0;

        m_signalLeaveEffectDone.emit(0);
    }        
}


void VappCamcoCpAdvanceMenu::recoverEffect(void)
{
    onRecoverEffectTimeline(NULL,VFX_TRUE);
}

void VappCamcoCpAdvanceMenu::onEndOfTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_OBJ_CLOSE(timeline);            
}

VfxU32 VappCamcoCpAdvanceMenu::getRecoverEffectDur(void)
{
    return VAPP_CAMCO_CP_ADVANCE_MENU_RECOVER_DUR;
}    

VfxBool VappCamcoCpAdvanceMenu::isAnimating(void)
{
    if(m_recoverEffectStep !=0 || m_effectStep != 0)
        return VFX_TRUE;
    else
        return VFX_FALSE;
}

VfxFloat VappCamcoCpAdvanceMenu::checkFocusIdx(VfxFloat idx)
{
    if(idx > (getCount() + 1))
        return (getCount() + 1); 
    
    if(idx < -2)
        return (-2);   

    return idx;
}

#endif

