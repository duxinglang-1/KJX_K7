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
 *  vtst_rt_tab_bar.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Description
 *      Screens for tab bar cp testing
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"

#if defined(__AFX_RT_TEST__)

#include "vtst_rt_main.h"
 #include "vfx_datatype.h"
 #include "vfx_text_frame.h"
 #include "vcp_button.h"
 #include "vcp_tab_bar.h"
 #include "vfx_object.h"
 #include "vfx_string.h"
 #include "mmi_rp_srv_venus_component_tab_title_bar_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
 #include "vcp_state_image.h"
 #include "vfx_cpp_base.h"
 #include "vfx_basic_type.h"
 #include "vrt_datatype.h"
 #include "vfx_sys_memory.h"
 #include "vfx_signal.h"
 #include "vfx_font_desc.h"
 #include "vfx_app_cat_scr.h"
/***************************************************************************** 
 * Class VtstRtTabBarScr
 *****************************************************************************/
class VtstRtTabBarScr : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRtTabBarScr() {}

// Override
protected:
    virtual void onInit();

    virtual VfxS32 start() {return 1;}

    virtual VfxS32 phase(VfxS32 idx);
   
    void onRotate(const VfxScreenRotateParam &param)
    {
        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        if(m_tabBar)
        {
            m_tabBar->setSize(main_screen_size.width, m_tabBar->getSize().height);
        }
        VtstRtScr::onRotate(param);
    }


// Implementation
private:
    VfxTextFrame *m_textFrame1;

    VfxTextFrame *m_textFrame2;

    VcpButton	*m_removeButton;
    VcpButton *m_addButton;
    
    VcpTabBar *m_tabBar;
#if defined(MULTI_LAYOUT_TABBAR)
    VcpTabBar *m_tabBar2;
#endif
	
    void onTabSwitched(VfxObject* sender, VfxId tabId);
	void onClearButtonPress(VfxObject* bar, VfxId id);
	void addSomeTabs(VfxObject* sender, VfxId tabId);
};


void VtstRtTabBarScr::onTabSwitched(VfxObject* sender, VfxId tabId)
{
    VfxTextFrame *pTextFrame = ((tabId / 10) == 0) ? (m_textFrame1) : (m_textFrame2);

    switch (tabId % 10)
    {
        case 0:
            pTextFrame->setString(VFX_WSTR("Tab 0"));
            break;

        case 1:
            pTextFrame->setString(VFX_WSTR("Tab 1"));
            break;

        case 2:
            pTextFrame->setString(VFX_WSTR("Tab 2"));
            break;

        default:
            pTextFrame->setString(VFX_WSTR("Tab 3"));
            break;
    }
}

void VtstRtTabBarScr::onClearButtonPress(VfxObject* bar, VfxId id)
{
	m_tabBar->removeAllTabs();	
}

void VtstRtTabBarScr::addSomeTabs(VfxObject* sender, VfxId tabId)
{
	m_tabBar->removeAllTabs();	
    m_tabBar->addTab(2, VcpStateImage(VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_CL), VFX_WSTR("item 2"));
    m_tabBar->addTab(3, VcpStateImage(VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_DL), VFX_WSTR("item 3"));
    m_tabBar->addTab(4, VcpStateImage(VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_CT), VFX_WSTR("item 4"));

    m_tabBar->setTabNotification(2, VFX_WSTR("22"), VfxImageSrc(IMG_COSMOS_SEARCH));
    m_tabBar->setTabNotification(3, VFX_WSTR("33") );
    m_tabBar->setTabNotification(4, VFX_WSTR_EMPTY);

    m_tabBar->setHighlightedTab(2);
    //m_tabBar->setTabIsDisabled(4, VFX_TRUE);
}
void VtstRtTabBarScr::onInit()
{
    VtstRtScr::onInit();
    setBgColor(VFX_COLOR_WHITE);

    VFX_OBJ_CREATE(m_textFrame1, VfxTextFrame, this);
    m_textFrame1->setRect(20, 120, 200, 25);

    VFX_OBJ_CREATE(m_textFrame2, VfxTextFrame, this);
    m_textFrame2->setRect(20, 150, 200, 25);

	VFX_OBJ_CREATE(m_removeButton, VcpButton, this);
	m_removeButton->setRect(100, 120, 150, 50);
	m_removeButton->m_signalClicked.connect(this, &VtstRtTabBarScr::onClearButtonPress);
    m_removeButton->setTextFont(VfxFontDesc (5) );
    m_removeButton->setText(VFX_WSTR("Clear tabs"));

	VFX_OBJ_CREATE(m_addButton, VcpButton, this);
	m_addButton->setRect(100, 180, 150, 50);
	m_addButton->m_signalClicked.connect(this, &VtstRtTabBarScr::addSomeTabs);
    m_addButton->setTextFont(VfxFontDesc (5) );
    m_addButton->setText(VFX_WSTR("Restore tabs"));

    VFX_OBJ_CREATE(m_tabBar, VcpTabBar, this);
    m_tabBar->addTab(0, VcpStateImage(VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_CL), VFX_WSTR("item 1"));
    m_tabBar->addTab(1, VcpStateImage(VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_DL), VFX_WSTR("item 2"));
    m_tabBar->setHighlightedTab(0);	
    m_tabBar->setPos(0, 50);
    m_tabBar->m_signalTabSwitched.connect(this, &VtstRtTabBarScr::onTabSwitched);
    m_textFrame1->setString(VFX_WSTR("Tab 0"));

#if defined(MULTI_LAYOUT_TABBAR)
    VcpTabBar *m_tabBar2;
    VFX_OBJ_CREATE(m_tabBar2, VcpTabBar, this);
    m_tabBar2->setPos(0, 360);
    m_tabBar2->addTab(10, VcpStateImage(IMG_GLOBAL_L1, 0, IMG_GLOBAL_L21, 0), VFX_WSTR("item 1"));
    m_tabBar2->setTabIsDisabled(10, VFX_TRUE);
    m_tabBar2->addTab(11, VcpStateImage(IMG_GLOBAL_L2), VFX_WSTR("item 2"));
    m_tabBar2->setLayout(VCP_TABBAR_LAYOUT_BOTTOM);
    m_tabBar2->addTab(12, VcpStateImage(IMG_GLOBAL_L3), VFX_WSTR("item 3"));
    m_tabBar2->removeTab(12);
    m_tabBar2->addTab(12, VcpStateImage(IMG_GLOBAL_L3, IMG_GLOBAL_L10, IMG_GLOBAL_L11, IMG_GLOBAL_L12), VFX_WSTR("item 3"), 1);
    m_tabBar2->addTab(13, VcpStateImage(IMG_GLOBAL_L4, 0, IMG_GLOBAL_L5, 0), VFX_WSTR("item 4"));
    m_tabBar2->setHighlightedTab(11);
    m_tabBar2->m_signalTabSwitched.connect(this, &VtstRtTabBarScr::onTabSwitched);
    m_textFrame2->setString(VFX_WSTR("Tab 1"));

    VcpTabBar *m_tabBarVert;
    VFX_OBJ_CREATE(m_tabBarVert, VcpTabBar, this);
    m_tabBarVert->setPos(270, 150);
    m_tabBarVert->setSize(50, 200);
    m_tabBarVert->addTab(1, VcpStateImage(IMG_GLOBAL_L1, 0, IMG_GLOBAL_L5, 0), VFX_WSTR("item 1")); 
    m_tabBarVert->addTab(2, VcpStateImage(IMG_GLOBAL_L2, 0, IMG_GLOBAL_L5, 0), VFX_WSTR("item 2")); 
    m_tabBarVert->setHighlightedTab(1);
    m_tabBarVert->m_signalTabSwitched.connect(this, &VtstRtTabBarScr::onTabSwitched);
    m_tabBarVert->setLayout(VCP_TABBAR_LAYOUT_RIGHT);
#endif
    
}


VfxS32 VtstRtTabBarScr::phase(VfxS32 idx)
{
    setTitle(VFX_WSTR("Tab Bar"));
    confirm(VFX_WSTR("Result is correct?"));
    return -1;
}


VtstTestResultEnum vtst_rt_tab_bar(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTabBarScr);
    return VTST_TR_OK;
}

#endif /* __AFX_RT_TEST__ */
