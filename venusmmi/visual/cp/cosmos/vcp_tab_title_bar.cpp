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
*  vcp_tab_title_bar.cpp
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
#include "vcp_tab_title_bar.h"

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_page_bar.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vrt_system.h"
#include "vfx_basic_type.h"
#include "vcp_tab_bar.h"
#include "vfx_signal.h"
#include "mmi_rp_srv_venus_component_tab_title_bar_def.h"
#include "vfx_image_src.h"
#include "vcp_state_image.h"
#include "vfx_string.h"

#if defined (__MTK_TARGET__) && defined (__VENUS_SWLA_DBG_ON__)
	#define __MAUI_SOFTWARE_LA__
#endif // __MTK_TARGET__
#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif 

/***************************************************************************** 
* Class VcpTabTitleBar
*****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpTabTitleBar", VcpTabTitleBar, VfxPageBar);


VcpTabTitleBar::VcpTabTitleBar() :
m_bar(NULL)
{
}


void VcpTabTitleBar::onInit()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("TTI", SA_start); 
#endif
    VfxPageBar::onInit();

    // set default size
    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);
    setSize(VfxSize(main_screen_size.width, DEFAULT_HEIGHT));

#if defined(__MMI_VUI_COSMOS_CP__)
    VfxFrame * shadowFrame;
    VFX_OBJ_CREATE(shadowFrame, VfxFrame, this);
    shadowFrame->setImgContent(VfxImageSrc(VCP_IMG_TAB_TITLE_BAR_SHADOW) );
    shadowFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    shadowFrame->setSize(getSize().width, 2);
    setShadowFrame(shadowFrame);
#endif

    VFX_OBJ_CREATE(m_bar, VcpTabBar, this);
    m_bar->setPos(0,0);
	m_bar->setSize(getSize().width, getSize().height);
    m_bar->m_signalTabSwitched.connect(this, &VcpTabTitleBar::onTabPress);
    //m_bar->setMargin(SIDE_MARGIN);    
    setImgContent(VfxImageSrc((VfxResId(VCP_IMG_TAB_TITLE_BAR_BG))));
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    // register signal
    m_signalBoundsChanged.connect(this, &VcpTabTitleBar::onBoundsChanged);
    checkUpdate();
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("TTI", SA_stop); 
#endif	
}

void VcpTabTitleBar::onUpdate()
{
    VfxPageBar::onUpdate();    
}

void VcpTabTitleBar::addTab2 (VfxId id, const VcpStateImage &imageList, VfxResId resId, VfxId beforeId)
{
    addTab (id, imageList, VFX_WSTR_RES(resId), beforeId);
}

void VcpTabTitleBar::addTab2 (VfxId id, const VcpStateImage &imageList, const VfxWChar *mem, VfxId beforeId)
{
    addTab (id, imageList, VFX_WSTR_MEM(mem), beforeId);
}

void VcpTabTitleBar::addTab (VfxId id, const VcpStateImage &imageList, const VfxWString &text, VfxId beforeId)
{
    if(m_bar->getTabCount() >= VCP_TTABBAR_MAX_TAB_LIMIT)
        return;

    m_bar->addTab(id, imageList, text, beforeId);
}

void VcpTabTitleBar::changeTab(VfxId id, const VcpStateImage &imageList)
{
    m_bar->changeTab(id, imageList);
}

void VcpTabTitleBar::changeTab(VfxId id, VfxResId resId)
{
    changeTab(id, VFX_WSTR_RES(resId));
}

void VcpTabTitleBar::changeTab(VfxId id, const VfxWChar *mem)
{
    changeTab(id, VFX_WSTR_MEM(mem));
}

void VcpTabTitleBar::changeTab(VfxId id, const VfxWString &text)
{
    m_bar->changeTab(id, text);
}

void VcpTabTitleBar::changeTab(VfxId id, VfxResId resId, const VcpStateImage &imageList)
{
    changeTab(id, VFX_WSTR_RES(resId), imageList);
}

void VcpTabTitleBar::changeTab(VfxId id, const VfxWChar *mem, const VcpStateImage &imageList)
{
    changeTab(id, VFX_WSTR_MEM(mem), imageList);
}

void VcpTabTitleBar::changeTab(VfxId id, const VfxWString &text, const VcpStateImage &imageList)
{
    m_bar->changeTab(id, text, imageList);
}


void VcpTabTitleBar::removeTab (VfxId id)
{
    m_bar->removeTab(id);
}

void VcpTabTitleBar::removeAllTabs()
{
    m_bar->removeAllTabs();
}

void VcpTabTitleBar::setTabEnabled ( VfxId id, VfxBool isEnabled    )
{
    m_bar->setTabIsDisabled(id,!isEnabled);
}

VfxBool VcpTabTitleBar::getTabIsEnabled ( VfxId id )
{
    return (!m_bar->getTabIsDisabled(id));
}

void VcpTabTitleBar::setHighlightedTab (VfxId id)
{
    m_bar->setHighlightedTab(id);
    checkUpdate();
}


VfxId VcpTabTitleBar::getHighlightedTab () const
{
    return m_bar->getHighlightedTab();
}

void VcpTabTitleBar::onTabPress (VfxObject* sender, VfxId Id)
{
    m_signalTabSwitched.emit(this, Id);
}


void VcpTabTitleBar::onSetTranslucent(VfxBool translucent)
{
    if(translucent)
    {
        setOpacity(0.5);
    }
    else
    {
        setOpacity(1);
    }
}

void VcpTabTitleBar::setIsHighlightedTextScrolling(VfxBool state)
{
    m_bar->setIsHighlightedTextScrolling(state);    
}

VfxBool VcpTabTitleBar::getIsHighlightedTextScrolling()
{
    return m_bar->getIsHighlightedTextScrolling();
}

void VcpTabTitleBar::setTabNotification(VfxId tabId, VfxResId resId)
{
    setTabNotification(tabId, VFX_WSTR_RES(resId));
}

void VcpTabTitleBar::setTabNotification(VfxId tabId, const VfxWChar *mem)
{
    setTabNotification(tabId, VFX_WSTR_MEM(mem));
}

void VcpTabTitleBar::setTabNotification(VfxId tabId, const VfxWString &text)
{
    m_bar->setTabNotification(tabId, text);
}

void VcpTabTitleBar::setTabNotification(VfxId tabId, VfxResId resId, VfxImageSrc icon)
{
    setTabNotification(tabId, VFX_WSTR_RES(resId), icon);
}

void VcpTabTitleBar::setTabNotification(VfxId tabId, const VfxWChar *mem, VfxImageSrc icon)
{
    setTabNotification(tabId, VFX_WSTR_MEM(mem), icon);
}

void VcpTabTitleBar::setTabNotification(VfxId tabId, const VfxWString &text, VfxImageSrc icon)
{
    m_bar->setTabNotification(tabId, text, icon);
}

