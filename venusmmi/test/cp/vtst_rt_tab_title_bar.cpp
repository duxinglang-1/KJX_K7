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
 *  vtst_rt_tab_title_bar.cpp
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
#include "vadp_mmi_frm.h"
#include "vfx_uc_include.h"

#include "vtst_rt_main.h"
#include "vcp_tab_title_bar.h"

 #include "vfx_datatype.h"
 #include "vfx_text_frame.h"
 #include "vcp_button.h"
 #include "vfx_object.h"
 #include "GlobalResDef.h"
 #include "vcp_state_image.h"
 #include "vfx_string.h"
 #include "vfx_cpp_base.h"
 #include "vfx_basic_type.h"
 #include "vrt_datatype.h"
 #include "vfx_sys_memory.h"
 #include "vfx_signal.h"
 #include "mmi_rp_srv_venus_component_tab_title_bar_def.h"
 #include "vfx_app_cat_scr.h"

/***************************************************************************** 
 * Class VtstRtTabTitleBarScr
 *****************************************************************************/
class VtstRtTabTitleBarScr : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRtTabTitleBarScr() {}

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

        if(m_tTabBar)
        {
            m_tTabBar->setSize(main_screen_size.width, m_tTabBar->getSize().height);
        }
        VtstRtScr::onRotate(param);
    }
// Implementation
private:

    VcpTabTitleBar *m_tTabBar;
    VfxTextFrame *m_textFrametabInfo;

    VfxTextFrame *m_textFrameForBack;

#if 0 // Unsupported feature
/* under construction !*/
/* under construction !*/
#endif

    VcpButton *m_clearTabs;
    void onClearTabs(VfxObject* sender, VfxId id);
    
    VcpButton *m_addtab;
    void onAddTab(VfxObject* sender, VfxId id);

    VcpButton *m_transparent;
    void onTransPToggle(VfxObject* sender, VfxId id);
    
    void onTabSwitched(VfxObject* sender, VfxId tabId);
#if 0 // Unsupported feature
/* under construction !*/
#endif
};

#if 0 // Unsupported feature
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

void VtstRtTabTitleBarScr::onClearTabs(VfxObject* sender, VfxId id)
{
    m_tTabBar->removeAllTabs();    
    checkUpdate();
}

void VtstRtTabTitleBarScr::onAddTab(VfxObject* sender, VfxId id)
{                                  
	VfxId tid = m_tTabBar->getTabCount() + 1;
    switch (tid % 5)
    {
        case 1:
			    m_tTabBar->addTab( tid, VcpStateImage(VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_CL),
                                VFX_WSTR("item 1"));
            break;

        case 2:
			    m_tTabBar->addTab( tid, VcpStateImage(VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_DL),
                                VFX_WSTR("item 2"));
            break;

        case 3:
			    m_tTabBar->addTab( tid, VcpStateImage(VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_CT),
                                VFX_WSTR("item 3"));
            break;
		case 4:
			    m_tTabBar->addTab( tid, VcpStateImage(VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_SNS),
                                VFX_WSTR("item 4"));
            break;

        default:
            break;
    }
    checkUpdate();                            
}
                                                         
void VtstRtTabTitleBarScr::onTransPToggle(VfxObject* sender, VfxId id)
{                                  
    static VfxBool state;    
    m_tTabBar->setTranslucent(!state);
    state = !state;
}
void VtstRtTabTitleBarScr::onTabSwitched(VfxObject* sender, VfxId tabId)
{
    VfxTextFrame *pTextFrame = m_textFrametabInfo;
    m_tTabBar = (VcpTabTitleBar*)sender;

    m_textFrameForBack->setString(VFX_WSTR("Browsing around"));
    m_tTabBar->setHighlightedTab(tabId);    
    switch (tabId % 10)
    {
        case 0:
            pTextFrame->setString(VFX_WSTR("Tab 1"));
            break;

        case 1:
            pTextFrame->setString(VFX_WSTR("Tab 2"));
            break;

        case 2:
            pTextFrame->setString(VFX_WSTR("Tab 3"));
            break;

        case 3:
            pTextFrame->setString(VFX_WSTR("Tab 4"));
            break;
            
        case 4:
            pTextFrame->setString(VFX_WSTR("Tab 5"));
            break;
            
        case 5:
            pTextFrame->setString(VFX_WSTR("Tab 6"));
            break;

        default:
            break;
    }
}


void VtstRtTabTitleBarScr::onInit()
{
    VtstRtScr::onInit();
    setBgColor(VFX_COLOR_WHITE);

    VFX_OBJ_CREATE(m_textFrametabInfo, VfxTextFrame, this);
    m_textFrametabInfo->setRect(20, 120, 200, 25);

    VFX_OBJ_CREATE(m_textFrameForBack, VfxTextFrame, this);
    m_textFrameForBack->setRect(20, 150, 200, 25);

#if 0 // Unsupported feature        
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

    VFX_OBJ_CREATE(m_clearTabs, VcpButton, this);
    m_clearTabs->setRect(20, 220, 150, 30);
    m_clearTabs->setText(VFX_WSTR("Remove all"));
    m_clearTabs->m_signalClicked.connect(this, &VtstRtTabTitleBarScr::onClearTabs);                          
    
    VFX_OBJ_CREATE(m_addtab, VcpButton, this);
    m_addtab->setRect(20, 260, 150, 30);
    m_addtab->setText(VFX_WSTR("Add a tab"));
    m_addtab->m_signalClicked.connect(this, &VtstRtTabTitleBarScr::onAddTab);                          

    VFX_OBJ_CREATE(m_transparent, VcpButton, this);
    m_transparent->setRect(20, 300, 200, 30);
    m_transparent->setText(VFX_WSTR("Toggle Tranparency"));
    m_transparent->m_signalClicked.connect(this, &VtstRtTabTitleBarScr::onTransPToggle);                          
        
    VFX_OBJ_CREATE(m_tTabBar, VcpTabTitleBar, this);
    m_tTabBar->setPos(0, 50);
    m_tTabBar->addTab(0, VcpStateImage(VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_CL), VFX_WSTR("Call logs"));
    m_tTabBar->addTab(1, VcpStateImage(VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_DL), VFX_WSTR("Dialer"));
    m_tTabBar->addTab(2, VcpStateImage(VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_CT), VFX_WSTR("Contacts"));
    m_tTabBar->addTab(3, VcpStateImage(VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_CT), VFX_WSTR("item 4"));
    m_tTabBar->addTab(4, VcpStateImage(IMG_GLOBAL_L5), VFX_WSTR("item 5"));
    m_tTabBar->addTab(5, VcpStateImage(IMG_GLOBAL_L6), VFX_WSTR("item 6"));
    m_tTabBar->setHighlightedTab(1);
    m_tTabBar->m_signalTabSwitched.connect(this, &VtstRtTabTitleBarScr::onTabSwitched);
    m_textFrametabInfo->setString(VFX_WSTR("Tab 0"));
#if 0   // Unsupported feature 
/* under construction !*/
#endif
}


VfxS32 VtstRtTabTitleBarScr::phase(VfxS32 idx)
{
    setTitle(VFX_WSTR("Tab Bar"));
    confirm(VFX_WSTR("Result is correct?"));
    return -1;
}


VtstTestResultEnum vtst_rt_tab_title_bar(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTabTitleBarScr);
    return VTST_TR_OK;
}

#endif /* __AFX_RT_TEST__ */
