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
*  vcp_tab_bar.cpp
*
* Project:
* --------
*  Venus UI Components
*
* Description:
* ------------
*  Tab bar component
*
* Author:
* -------
 * -------
*
*============================================================================
*****************************************************************************/

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vcp_tab_bar.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vrt_system.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"
#include "vfx_signal.h"
#include "vfx_frame_aligner.h"
#include "vfx_object_list.h"
#include "vcp_button.h"
#include "vfx_auto_animate.h"
#include "vfx_animation.h"
#include "vcp_state_image.h"
#include "vfx_image_src.h"
#include "mmi_rp_srv_venus_component_tab_bar_def.h"
#include "vfx_string.h"
#include "vfx_font_desc.h"
#include "GlobalResDef.h"
#include "vcp_tab_title_bar.h"
#include "vfx_text_frame.h"
#include "vfx_keypad.h"

#if defined(__MMI_VUI_COSMOS_CP__)
#include "vcp_button_util.h"
#endif

#if !defined(__MMI_VUI_COSMOS_CP__)
#define VCP_IMG_TAB_BAR_ICON_BG IMG_GLOBAL_EMPTY

#if defined(__MMI_MAINLCD_320X480__)
#define  BUTTON_TOP_MARGIN 5
#elif defined(__MMI_MAINLCD_480X800__)
#define BUTTON_TOP_MARGIN 8
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
#define BUTTON_TOP_MARGIN 4 
#else
#define BUTTON_TOP_MARGIN 5
#endif 

#define BUTTON_BOTTOM_MARGIN 3
#endif 

#if defined (__MTK_TARGET__) && defined (__VENUS_SWLA_DBG_ON__)
	#define __MAUI_SOFTWARE_LA__
#endif // __MTK_TARGET__
#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif 


#if defined(__MMI_VUI_COSMOS_CP__)
/***************************************************************************** 
* Class VcpTabBarTab
*****************************************************************************/
VcpTabBarTab::VcpTabBarTab():
m_NIcon(NULL),
m_NTextFrm(NULL)
{}

void VcpTabBarTab::setNotificationText(const VfxWString &text)
{
    if(text == VFX_WSTR_EMPTY || text == VFX_WSTR_NULL)
    {
        if(m_NTextFrm)
        {
            VFX_OBJ_CLOSE(m_NTextFrm);
        }
        if(m_NIcon)
        {
            VFX_OBJ_CLOSE(m_NIcon);
        }
        return;    
    }

    if(!m_NTextFrm)
    {
        if(!m_NIcon)
        {
            setNotificationIcon(VfxImageSrc(VCP_IMG_TAB_BAR_NOTIFICATION_ICON));            
        }    
        VFX_OBJ_CREATE(m_NTextFrm, VfxTextFrame, m_NIcon);
        m_NTextFrm->setAnchor(0.5f, 0.5f);
        m_NTextFrm->setAutoResized(VFX_TRUE);
        m_NTextFrm->setPos(m_NIcon->getSize().width/2, m_NIcon->getSize().height/2);

        m_NTextFrm->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID,
                            VFX_FRAME_ALIGNER_MODE_MID,
                            VFX_FRAME_ALIGNER_MODE_MID,
                            VFX_FRAME_ALIGNER_MODE_MID);

        m_NTextFrm->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(20)));
        m_NTextFrm->setString(VFX_WSTR("9"));
        m_notifTextMargin = m_NIcon->getSize().width - m_NTextFrm->getSize().width;
    }
    
    m_NTextFrm->setString(text);
    m_NIcon->setSize(m_NTextFrm->getSize().width + m_notifTextMargin, m_NIcon->getSize().height);
    checkUpdate();
}

void VcpTabBarTab::setNotificationIcon(VfxImageSrc icon)
{
        if(!m_NIcon)
        {
            VFX_OBJ_CREATE(m_NIcon, VfxFrame, this);
            m_NIcon->setAnchor(0.0f, 0.0f);
            m_NIcon->setPos(getSize().width/2 + VCP_TABBAR_NOTIFICATION_POSITION_OFFSET, 0);
            m_NIcon->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID,
                            VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_NONE,
                            VFX_FRAME_ALIGNER_MODE_NONE);

        }    
        m_NIcon->setImgContent(icon);
        m_NIcon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

        m_NIcon->setSize(icon.getSize());
        checkUpdate();
}

void VcpTabBarTab::onUpdate()
{
    VcpScrollingTextButton::onUpdate();
    if(m_NIcon)
    {
        m_NIcon->bringToFront();
    }
    if(m_NTextFrm)
    {
        m_NTextFrm->bringToFront();
    }
}
#endif

/***************************************************************************** 
* Class VcpTabBar
*****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpTabBar", VcpTabBar, VfxControl);


VcpTabBar::VcpTabBar() :
m_count(0),
m_layout(VCP_TABBAR_LAYOUT_TOP),
m_highlightedId(INVALID_TAB_ID),
#if defined(__MMI_VUI_COSMOS_CP__)
m_isHighlightedTextScrolling(VFX_TRUE),
#endif
m_margin(0)
#if defined(__MMI_VUI_COSMOS_CP__)
,m_iconOnTop(NULL)
#endif
{
}


void VcpTabBar::onInit()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("TbI", SA_start); 
#endif
    VfxControl::onInit();

    // set default size
    setSize(VfxSize(getParentFrame()->getSize().width, DEFAULT_THICKNESS));
    setAutoAnimate(VFX_TRUE);
    
#if defined(__MMI_VUI_COSMOS_CP__)
    //set Tab line
    VFX_OBJ_CREATE(m_tabLine, VfxFrame, this);
#endif /* #if defined(__MMI_VUI_COSMOS_CP__) */

    // set layout
    setLayout(VCP_TABBAR_LAYOUT_TOP);

    // register signal
    m_signalBoundsChanged.connect(this, &VcpTabBar::onBoundsChanged);

#if defined(__MMI_VUI_COSMOS_CP__)
    VfxKeypad::registerHandler(VFX_KEY_CODE_ARROW_LEFT, this);
    VfxKeypad::registerHandler(VFX_KEY_CODE_ARROW_RIGHT, this); 
#endif

#if defined(__MMI_VUI_COSMOS_CP__)
    VFX_OBJ_CREATE(m_iconOnTop, VfxFrame, this); // To handle black icon background on hightlighted tabs

    setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_NONE, 
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_NONE);
#endif
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("TbI", SA_stop); 
#endif
}

#if defined(__MMI_VUI_COSMOS_CP__)
void VcpTabBar::onDraw(VfxDrawContext &dc)
{
    dc.drawResizedImage(VfxRect(LEFT_MARGIN,0, getSize().width - RIGHT_MARGIN - LEFT_MARGIN, getSize().height), VfxImageSrc(VCP_IMG_TAB_BAR_TAB_HZ_N));    
    VfxControl::onDraw(dc);
}
#endif

#if defined(__MMI_VUI_COSMOS_CP__)
void VcpTabBar::setIsHighlightedTextScrolling(VfxBool state)
{
    m_isHighlightedTextScrolling = state;
    checkUpdate();
}

VfxBool VcpTabBar::getIsHighlightedTextScrolling()
{
    return m_isHighlightedTextScrolling;
}

void VcpTabBar::setTabNotification(VfxId tabId, VfxResId resId)
{
    setTabNotification(tabId, VFX_WSTR_RES(resId));
}

void VcpTabBar::setTabNotification(VfxId tabId, const VfxWChar *mem)
{
    setTabNotification(tabId, VFX_WSTR_MEM(mem));
}

void VcpTabBar::setTabNotification(VfxId tabId, const VfxWString &text)
{
    for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = i->getValidNext())
    {
        VcpTabBarTab *pTab = (VcpTabBarTab *)i->get();
        if (pTab ->getId() == tabId)
        { 
            pTab->setNotificationText(text);
            checkUpdate();
            break;
        }
    }    
}

void VcpTabBar::setTabNotification(VfxId tabId, VfxResId resId, VfxImageSrc icon)
{
    setTabNotification(tabId, VFX_WSTR_RES(resId), icon);
}

void VcpTabBar::setTabNotification(VfxId tabId, const VfxWChar *mem, VfxImageSrc icon)
{
    setTabNotification(tabId, VFX_WSTR_MEM(mem), icon);
}

void VcpTabBar::setTabNotification(VfxId tabId, const VfxWString &text, VfxImageSrc icon)
{
    for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = i->getValidNext())
    {
        VcpTabBarTab *pTab = (VcpTabBarTab *)i->get();
        if (pTab ->getId() == tabId)
        { 
            pTab->setNotificationText(text);
            pTab->setNotificationIcon(icon);            
            checkUpdate();
            break;
        }
    }    
}



#endif

void VcpTabBar::setLayout (VcpTabBarLayoutEnum layout)
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("TbL", SA_start); 
#endif
    m_layout = layout;

    VcpStateImage newTabBkgImg;

    switch (m_layout)
    {
    case VCP_TABBAR_LAYOUT_TOP:
#if defined(__MMI_VUI_COSMOS_CP__)
        newTabBkgImg = VcpStateImage(0, VCP_IMG_TAB_BAR_MIDDLE_TAB_HZ_N_P, VCP_IMG_TAB_BAR_MIDDLE_TAB_HZ_N_P, VCP_IMG_TAB_BAR_MIDDLE_TAB_HZ_N_P);
        m_tabLine->setPos(0, getSize().height - LINE_THICKNESS);
        m_tabLine->setSize(getSize().width , LINE_THICKNESS);                
        m_tabLine->setImgContent(VfxImageSrc(VCP_IMG_TAB_BAR_HZ_LINE_N));         
        m_tabLine->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_NONE, 
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_NONE);
#else
    setImgContent(VfxImageSrc(VCP_IMG_TABBAR_TOP_H));
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);    
    newTabBkgImg = VcpStateImage(0, VCP_IMG_TAB_BAR_TAB_HZ_N_P, VCP_IMG_TAB_BAR_TAB_HZ_N_P, VCP_IMG_TAB_BAR_TAB_HZ_H);
#endif /* defined(__MMI_VUI_COSMOS_CP__) */        
        break;

#if defined(MULTI_LAYOUT_SUPPORT)
    case VCP_TABBAR_LAYOUT_BOTTOM:
        newTabBkgImg = VcpStateImage(0, VCP_IMG_TAB_BAR_MIDDLE_TAB_HZ_N_P, VCP_IMG_TAB_BAR_MIDDLE_TAB_HZ_N_P, VCP_IMG_TAB_BAR_MIDDLE_TAB_HZ_N_P);
#if defined(__MMI_VUI_COSMOS_CP__)
        m_tabLine->setPos(0, 0);
        m_tabLine->setSize(getSize().width , LINE_THICKNESS);                
        m_tabLine->setImgContent(VfxImageSrc(VCP_IMG_TAB_BAR_HZ_LINE_N));                    
#endif /* defined(__MMI_VUI_COSMOS_CP__) */        
        break;

    case VCP_TABBAR_LAYOUT_LEFT:
        newTabBkgImg = VcpStateImage(VCP_IMG_TAB_BAR_TAB_VT_H, VCP_IMG_TAB_BAR_TAB_VT_H_P, 0, 0);
        setImgContent(VfxImageSrc(VCP_IMG_TAB_BAR_TAB_VT_N));                    
#if defined(__MMI_VUI_COSMOS_CP__)
        m_tabLine->setPos(getSize().width - LINE_THICKNESS, 0);
        m_tabLine->setSize(LINE_THICKNESS, getSize().height);          
        m_tabLine->setImgContent(VfxImageSrc(VCP_IMG_TAB_BAR_VT_LINE_N));
#endif /* defined(__MMI_VUI_COSMOS_CP__) */        
        break;                        

    case VCP_TABBAR_LAYOUT_RIGHT:
        newTabBkgImg = VcpStateImage(VCP_IMG_TAB_BAR_TAB_VT_H, VCP_IMG_TAB_BAR_TAB_VT_H_P, 0, 0);
        setImgContent(VfxImageSrc(VCP_IMG_TAB_BAR_TAB_VT_N));                    
#if defined(__MMI_VUI_COSMOS_CP__)        
        m_tabLine->setPos(0, 0);
        m_tabLine->setSize(LINE_THICKNESS, getSize().height);
        m_tabLine->setImgContent(VfxImageSrc(VCP_IMG_TAB_BAR_VT_LINE_N));
#endif /* defined(__MMI_VUI_COSMOS_CP__) */        
        break;                                                                
#endif /* defined(MULTI_LAYOUT_SUPPORT) */
    default:            
        break;
    }
#if defined(__MMI_VUI_COSMOS_CP__)
    m_tabLine->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);    
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
#endif /* defined(__MMI_VUI_COSMOS_CP__) */        

    // set tab state image
    for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = i->getValidNext())
    {
        VcpButton *pButton = (VcpButton *)i->get();  
        pButton->setBgImageList(newTabBkgImg);  
        pButton->setMargin(7, 9, 7, 7);
    }
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("TbL", SA_stop); 
#endif	
}


void VcpTabBar::onUpdate()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("TbU", SA_start); 
#endif
    if (m_count <= 0)
    {
        return;
    }
    VfxSize size = getSize();
    #if defined(__MMI_VUI_COSMOS_CP__)
    m_tabLine->bringToFront();
    #endif
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    switch(m_layout)
    {
#if defined(MULTI_LAYOUT_SUPPORT)
        case VCP_TABBAR_LAYOUT_BOTTOM:
#endif
        case VCP_TABBAR_LAYOUT_TOP:
            {
                VfxS32 w = (size.width - (HOR_TAB_GAP * m_count) - m_margin - LEFT_MARGIN - RIGHT_MARGIN) / m_count;
                VfxS32 x = HOR_TAB_GAP + m_margin + LEFT_MARGIN;
                VfxS32 ctr =0;
#if defined(__MMI_VUI_COSMOS_CP__)                    
                VfxObjListEntry *j =  m_sepList.getValidHead();
#endif                
                for (VfxObjListEntry *i = m_list.getValidHead();                              
                    i != NULL ; 
                    ctr++, i = i->getValidNext() )
                {
                    VcpButton *pButton = (VcpButton *)i->get();
#if defined(__MMI_VUI_COSMOS_CP__)                        
                    VfxFrame *sep = (VfxFrame*)j->get();
#endif
                    VfxSize s = pButton->getSize();
                    s.width = w;
                    s.height = size.height;
                    pButton->setSize(s);

                    VfxPoint p = pButton->getPos();
                    p.x = x;
                    pButton->setPos(p);
#if defined(__MMI_VUI_COSMOS_CP__)                        
                    sep->setPos(pButton->getPos().x + pButton->getSize().width - 1, 4);                    
                    if(ctr == m_count - 1 )
                    {
                        sep->setHidden(VFX_TRUE);
                    }
                    else
                    {
                        sep->setHidden(VFX_FALSE);
                    }
#endif
                    x += (w + HOR_TAB_GAP);
#if !defined(__MMI_VUI_COSMOS_CP__) 
                    pButton->setIsHighlighted(pButton->getId() == m_highlightedId);
                    pButton->setMargin(0,BUTTON_TOP_MARGIN,0,BUTTON_BOTTOM_MARGIN);

#else
                    // set highlighted button
                   
                    if (pButton->getId() == m_highlightedId)
                    {
                        pButton->setBgImageList(VcpStateImage(VCP_IMG_TAB_BAR_TAB_HZ_H, VCP_IMG_TAB_BAR_TAB_HZ_H_P, VCP_IMG_TAB_BAR_TAB_HZ_H, VCP_IMG_TAB_BAR_TAB_HZ_H));
                        pButton->setMargin(BUTTON_LEFT_MARGIN_HL,BUTTON_TOP_MARGIN_HL, BUTTON_RIGHT_MARGIN_HL, BUTTON_BOTTOM_MARGIN_HL);
                        pButton->setSize( pButton->getSize().width + EXTRA_WIDTH_TO_COVER_SEP_LINE ,  pButton->getSize().height);
                        pButton->setPos( pButton->getPos().x - (EXTRA_WIDTH_TO_COVER_SEP_LINE >>1),  pButton->getPos().y);

                        m_iconOnTop->removeFromParentFrame();
                        pButton->addChildFrame(m_iconOnTop);

                        VcpStateImage temp = pButton->getStateImage();                                                
                        VfxImageSrc icon = temp.getImageNormal();
                        temp.setImage( temp.getImageNormal(), VfxImageSrc((VfxResId)VCP_IMG_TAB_BAR_ICON_BG), VfxImageSrc((VfxResId)VCP_IMG_TAB_BAR_ICON_BG), VfxImageSrc((VfxResId)VCP_IMG_TAB_BAR_ICON_BG));
                        m_iconOnTop->setImgContent(icon);

                        VfxRect clientRect =pButton->getBounds();

                        VfxS32 shift = (clientRect.getHeight() - (FONT_SIZE)) / 2; // FONT_SIZE + 2(Image text gap in button)

                        m_iconOnTop->setAnchor(VfxFPoint(0.5, 0.5));
                        m_iconOnTop->setPos(pButton->getSize().width/2, BUTTON_TOP_MARGIN_HL + VfxImageSrc((VfxResId)VCP_IMG_TAB_BAR_ICON_BG).getSize().height/2);

                        m_iconOnTop->setSize(icon.getSize());
                        VfxImageSrc bgIcon = VfxImageSrc((VfxResId)VCP_IMG_TAB_BAR_ICON_BG);
                        m_iconOnTop->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
                        pButton->setImage(temp);                       
                        pButton->setIsHighlighted(VFX_TRUE);
                        pButton->bringToFront();
                    }
                    else
                    {
                        VcpStateImage temp = pButton->getStateImage();   
                        temp.setImage( temp.getImageNormal(), temp.getImageNormal(), temp.getImageNormal(), VfxImageSrc((VfxResId)VCP_IMG_TAB_BAR_ICON_BG));
                        pButton->setImage(temp);  
#if defined(__MMI_VUI_COSMOS_CP__) && !defined(__MRE_SDK__)
                        if(ctr == 0)
                        {
                            pButton->setBgImageList(VcpStateImage(0, VCP_IMG_TAB_BAR_LEFT_TAB_HZ_N_P, 0, VCP_IMG_TAB_BAR_LEFT_TAB_HZ_N_P));
                        }
                        else if(ctr == m_count-1)
                        {
                            pButton->setBgImageList(VcpStateImage(0, VCP_IMG_TAB_BAR_RIGHT_TAB_HZ_N_P, 0, VCP_IMG_TAB_BAR_RIGHT_TAB_HZ_N_P));
                        }
                        else
                        {
                            pButton->setBgImageList(VcpStateImage(0, VCP_IMG_TAB_BAR_MIDDLE_TAB_HZ_N_P, 0, VCP_IMG_TAB_BAR_MIDDLE_TAB_HZ_N_P));
                        } 
						
#else
                         pButton->setBgImageList(VcpStateImage(0, VCP_IMG_TAB_BAR_TAB_HZ_N_P, VCP_IMG_TAB_BAR_TAB_HZ_N_P, VCP_IMG_TAB_BAR_TAB_HZ_N_P));
#endif /* #if defined(__MMI_VUI_COSMOS_CP__) && !defined(__MRE_SDK__) */
                        pButton->sendToBack();
                        pButton->setMargin(BUTTON_LEFT_MARGIN_N,BUTTON_TOP_MARGIN_N, BUTTON_RIGHT_MARGIN_N, BUTTON_BOTTOM_MARGIN_N);                        

                        pButton->setIsHighlighted(VFX_FALSE);
                    }

#if defined(__MMI_VUI_COSMOS_CP__)
                    ((VcpTabBarTab*)pButton)->setScrollOnHighlight(m_isHighlightedTextScrolling);                
                    if(pButton->getIsDisabled())
                        {
                        pButton->setOpacity(0.3) ;
                        }
                    else
                        {
                        pButton->setOpacity(1) ;
                        }
#endif
                    j = j->getValidNext();
#endif                    
                }
            }
            break;
#if defined(MULTI_LAYOUT_SUPPORT)
        case VCP_TABBAR_LAYOUT_LEFT:
        case VCP_TABBAR_LAYOUT_RIGHT:
            {
                VfxS32 h = VERT_TAB_HEIGHT;
                VfxS32 y = VERT_TAB_GAP;

                for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = i->getValidNext())
                {
                    VcpButton *pButton = (VcpButton *)i->get();

                    VfxSize s = pButton->getSize();
                    s.height = h;
                    s.width = size.width + 2;
                    pButton->setSize(s);

                    VfxPoint p = pButton->getPos();
                    p.y = y;
                    pButton->setPos(p);

                    y += (h + VERT_TAB_GAP);

                    // set highlighted button
                    if (pButton->getId() == m_highlightedId)
                    {
                        pButton->setBgImageList(VcpStateImage(VCP_IMG_TAB_BAR_TAB_VT_H, VCP_IMG_TAB_BAR_TAB_VT_H_P, 0, 0));
                        pButton->setIsHighlighted(VFX_TRUE);
                    }
                    else
                    {
                        pButton->setBgImageList(VcpStateImage(VCP_IMG_TAB_BAR_TAB_VT_N, VCP_IMG_TAB_BAR_TAB_VT_N_P, 0, 0));
                        pButton->setIsHighlighted(VFX_FALSE);
                    }
                }
            }
            break;
#endif
        default:
            break;
    }
                    
    VfxAutoAnimate::commit();                    
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("TbU", SA_stop); 
#endif
}

void VcpTabBar::addTabFromXML(VcpTabBarItem *tabContent)
{
    addTab(tabContent->id, tabContent->imagelist, tabContent->text);
} 

void VcpTabBar::addTab (VfxId id, const VcpStateImage &imageList, VfxResId resId, VfxId beforeId)
{
    addTab (id, imageList, VFX_WSTR_RES(resId), beforeId);
}

void VcpTabBar::addTab (VfxId id, const VcpStateImage &imageList, const VfxWChar *mem, VfxId beforeId)
{
    addTab (id, imageList, VFX_WSTR_MEM(mem), beforeId);
}

void VcpTabBar::addTab (VfxId id, const VcpStateImage &imageList, const VfxWString &text, VfxId beforeId)
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("TbA", SA_start); 
#endif
#if defined(__MMI_VUI_COSMOS_CP__)
    VcpTabBarTab *button;
    VFX_OBJ_CREATE(button, VcpTabBarTab, this);
#else
    VcpButton *button;
    VFX_OBJ_CREATE(button, VcpButton, this);
#endif
    button->setId(id);
    button->setImage(imageList);
    button->setText(text);
    button->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_TOP);
    button->setTextFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(FONT_SIZE), VFX_FE1_9));
#if defined(__MMI_VUI_COSMOS_CP__)
    button->setTextColor(VCP_TAB_BAR_TEXT_COLOR, VCP_TAB_BAR_TEXT_COLOR, VCP_TAB_BAR_TEXT_COLOR, VCP_TAB_BAR_TEXT_COLOR);  
#else
    button->setTextColor(VCP_TAB_BAR_TEXT_COLOR, VCP_TAB_BAR_TEXT_COLOR, VCP_TAB_BAR_TEXT_COLOR, VCP_TAB_BAR_TEXT_COLOR_HGHLGHT);  
    button->setBgImageList(VcpStateImage(0, VCP_IMG_TAB_BAR_TAB_HZ_N_P, VCP_IMG_TAB_BAR_TAB_HZ_N_P, VCP_IMG_TAB_BAR_TAB_HZ_H));

#endif
    button->m_signalClicked.connect(this, &VcpTabBar::onButtonClicked);
    button->m_signalStateChanged.connect(this, &VcpTabBar::onButtonStateChanged);
#if defined(__MMI_VUI_COSMOS_CP__)
    VfxFrame *separator;
    VFX_OBJ_CREATE(separator, VfxFrame, this);
    separator->setImgContent(VfxImageSrc(VCP_IMG_TAB_BAR_HZ_TAB_SEP));
    separator->setSize(2, getSize().height - 4);
#endif    
    VfxBool isEnd = VFX_TRUE;
    if (beforeId != INVALID_TAB_ID)
    {
#if defined(__MMI_VUI_COSMOS_CP__)    
        VfxObjListEntry *j =  m_sepList.getValidHead();
#endif        
        for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = i->getValidNext())
        {
            VcpButton *pButton = (VcpButton *)i->get();

            if (pButton->getId() == beforeId)
            {   // insert item before beforeId
                m_list.insertBefore(i, button);
                isEnd = VFX_FALSE;
#if defined(__MMI_VUI_COSMOS_CP__)    
                m_sepList.insertBefore(j, separator);    
#endif
            }
#if defined(__MMI_VUI_COSMOS_CP__)                
            j = j->getValidNext();
#endif            
        }
    }

    if (isEnd)
    {   // add item to the end
        m_list.append(button);
#if defined(__MMI_VUI_COSMOS_CP__)            
        m_sepList.append(separator);
#endif
    }

    m_count ++;
    if(1 == m_count) // First tab
    {
        setHighlightedTab(id);
    }
    checkUpdate();
    invalidate();
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("TbA", SA_stop); 
#endif	
}

void VcpTabBar::changeTab(VfxId id, const VcpStateImage &imageList)
{
    for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = i->getValidNext())
    {
        VcpButton *pButton = (VcpButton *)i->get();
        if (pButton->getId() == id)
        { 
            pButton->setImage(imageList);
            checkUpdate();
            break;
        }
    }
}

void VcpTabBar::changeTab(VfxId id, VfxResId resId)
{
    changeTab(id, VFX_WSTR_RES(resId));
}

void VcpTabBar::changeTab(VfxId id, const VfxWChar *mem)
{
    changeTab(id, VFX_WSTR_MEM(mem));
}

void VcpTabBar::changeTab(VfxId id, const VfxWString &text)
{
    for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = i->getValidNext())
    {
        VcpButton *pButton = (VcpButton *)i->get();
        if (pButton->getId() == id)
        { 
            pButton->setText(text);
            checkUpdate();
            break;
        }
    }
}

void VcpTabBar::changeTab(VfxId id, VfxResId resId, const VcpStateImage &imageList)
{
    changeTab(id, VFX_WSTR_RES(resId), imageList);
}

void VcpTabBar::changeTab(VfxId id, const VfxWChar *mem, const VcpStateImage &imageList)
{
    changeTab(id, VFX_WSTR_MEM(mem), imageList);
}

void VcpTabBar::changeTab(VfxId id, const VfxWString &text, const VcpStateImage &imageList)
{
    for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = i->getValidNext())
    {
        VcpButton *pButton = (VcpButton *)i->get();
        if (pButton->getId() == id)
        { 
            pButton->setText(text);
            pButton->setImage(imageList);
            checkUpdate();
            break;
        }
    }
}

void VcpTabBar::removeTab (VfxId id)
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("TbR", SA_start); 
#endif
#if defined(__MMI_VUI_COSMOS_CP__)    
    VfxObjListEntry *j =  m_sepList.getValidHead();
#endif    
    for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = i->getValidNext())
    {
        VcpButton *pButton = (VcpButton *)i->get();

        if (pButton->getId() == id)
        { 
            m_list.removePos(i);
            VFX_OBJ_CLOSE(pButton);
#if defined(__MMI_VUI_COSMOS_CP__)    
            VfxFrame *sep = (VfxFrame*)j->get();
            m_sepList.removePos(j);
            VFX_OBJ_CLOSE(sep);
#endif
            m_count --;
            break;
        }
#if defined(__MMI_VUI_COSMOS_CP__)            
        j = j->getValidNext();
#endif        
    }

    checkUpdate();
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("TbR", SA_stop); 
#endif	
}

void VcpTabBar::removeAllTabs ()
{

    VfxObjListEntry *i = m_list.getValidHead(); 
#if defined(__MMI_VUI_COSMOS_CP__)    
    VfxObjListEntry *j =  m_sepList.getValidHead();
#endif    
    while(i != NULL)
    {
        VfxObjListEntry *next;

        VcpButton *pButton = (VcpButton *)i->get();    
        next = i->getValidNext();
        m_list.removePos(i);
        VFX_OBJ_CLOSE(pButton);
        i = next;
#if defined(__MMI_VUI_COSMOS_CP__)    
        VfxFrame *sep = (VcpButton *)j->get();    
        next = j->getValidNext();
        m_sepList.removePos(j);
        VFX_OBJ_CLOSE(sep);
        j = next;
#endif
        m_count--;
    }  
    checkUpdate();

}

void VcpTabBar::setTabIsDisabled (VfxId id, VfxBool isDisabled)
{
    for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = i->getValidNext())
    {
        VcpButton *pButton = (VcpButton *)i->get();

        if (pButton->getId() == id)
        {
            pButton->setIsDisabled(isDisabled);
            break;
        }
    }
    checkUpdate();
}


VfxBool VcpTabBar::getTabIsDisabled (VfxId id) const
{
    for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = i->getValidNext())
    {
        VcpButton *pButton = (VcpButton *)i->get();

        if (pButton->getId() == id)
        {
            return pButton->getIsDisabled();
        }
    }

    return VFX_FALSE;
}

#if defined(__MMI_VUI_COSMOS_CP__)
VfxBool VcpTabBar::onKeyInput(VfxKeyEvent &event)
{
    switch(event.type)
    {
        case VFX_KEY_EVENT_TYPE_REPEAT:
        case VFX_KEY_EVENT_TYPE_DOWN:        
        {
            for (VfxObjListEntry *i = m_list.getValidHead(); i != NULL ; i = i->getValidNext()   )
            {
                VcpButton *pButton = (VcpButton *)i->get();
                if(pButton->getId() == m_highlightedId)
                {
                    while(1)
                    {
                        if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT)
                        {
                            i = i->getValidNext();
                        }                    
                        else if(event.keyCode == VFX_KEY_CODE_ARROW_LEFT)
                        {
                            i = i->getValidPrev();
                        }                     
                        if (i != NULL)
                        {
                            pButton = (VcpButton *)i->get();
                            if(!pButton->getIsDisabled())
                            {
                                setHighlightedTab(pButton->getId());
                                m_signalTabSwitched.postEmit(this, pButton->getId());
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }

                    return VFX_TRUE;
                }
            }            
        }
    default:
        break;
    }
    return VFX_FALSE;
}
#endif /* defined(__MMI_VUI_COSMOS_CP__) */


void VcpTabBar::onButtonClicked (VfxObject* sender, VfxId Id)
{
    if (Id != m_highlightedId)
    {
        setHighlightedTab(Id);
        m_signalTabSwitched.postEmit(this, Id);
    }
    checkUpdate();
}

void VcpTabBar::onButtonStateChanged (VfxObject* sender, VfxId Id, VcpButtonStateEnum state)
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("TbS", SA_start); 
#endif
    switch (state)
    {
    case VCP_BUTTON_STATE_NORMAL:
#if defined(MULTI_LAYOUT_SUPPORT)
        if(getLayout() == VCP_TABBAR_LAYOUT_TOP 
            || getLayout() == VCP_TABBAR_LAYOUT_BOTTOM 
            )
#endif /* defined(MULTI_LAYOUT_SUPPORT) */
        {
#if !defined(__MMI_VUI_COSMOS_CP__)
    setImgContent(VfxImageSrc(VCP_IMG_TABBAR_TOP_H));
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);    
#else
            m_tabLine->setImgContent(VfxImageSrc(VCP_IMG_TAB_BAR_HZ_LINE_N));                    
            m_tabLine->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
#endif            
        }
#if defined(MULTI_LAYOUT_SUPPORT)
        else
        {
#if defined(__MMI_VUI_COSMOS_CP__)            
            m_tabLine->setImgContent(VfxImageSrc(VCP_IMG_TAB_BAR_VT_LINE_N));
            m_tabLine->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
#endif            
        }                                                                                            
#endif /* defined(MULTI_LAYOUT_SUPPORT) */
        break;

    case VCP_BUTTON_STATE_PRESSED:
        if (Id == m_highlightedId)
        {
#if defined(MULTI_LAYOUT_SUPPORT)
            if(getLayout() == VCP_TABBAR_LAYOUT_TOP 
                || getLayout() == VCP_TABBAR_LAYOUT_BOTTOM
                )
#endif /* defined(MULTI_LAYOUT_SUPPORT) */
            {
#if !defined(__MMI_VUI_COSMOS_CP__)
                setImgContent(VfxImageSrc(VCP_IMG_TABBAR_TOP_P));
                setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);    
#else        
                m_tabLine->setImgContent(VfxImageSrc(VCP_IMG_TAB_BAR_HZ_LINE_P));                    
                m_tabLine->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
#endif                
            }
#if defined(MULTI_LAYOUT_SUPPORT)
            else
            {
#if defined(__MMI_VUI_COSMOS_CP__)                
                m_tabLine->setImgContent(VfxImageSrc(VCP_IMG_TAB_BAR_VT_LINE_P));
                m_tabLine->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
#endif                
            }     
#endif /* defined(MULTI_LAYOUT_SUPPORT) */
        }
        break;

    default:
        break;
    }

#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("TbS", SA_stop); 
#endif
}

