/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vtst_hello.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Hello World example for Venus UI
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
// by RHR //#include "vfx_uc_include.h"
#include "vtst_rt_mainscr.h"
#include "vcp_tabctrl_page.h"
#include "vtst_rt_main.h"

#include "../xml/vfx_xml_loader.h"

extern "C"
{
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "mmi_res_range_def.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "MMIDataType.h"
}

#include "vfx_object.h"
#include "vfx_app_launcher.h"
#include "vfx_datatype.h"
#include "vfx_class_info.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_page.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_frame.h"
#include "vfx_input_event.h"
#include "vfx_page_bar.h"
#include "vfx_string.h"
#include "vfx_signal.h"
#include "vfx_text_frame.h"
#include "vfx_main_scr.h"
#include "vfx_archive.h"
#include "vfx_font_desc.h"
#include "vfx_animation.h"
#include "vrt_canvas.h"
#include "vfx_screen.h"
#include "vfx_top_level.h"
#include "vfx_app.h"
#include "vfx_timer.h"

#include "vcp_switch.h"
#include "vcp_state_image.h"
#include "vcp_command_title.h"
#include "vcp_button.h"
#include "vcp_segment_button.h"
#include "vcp_popup.h"

VtstMSAppBasePage* createPage2(VfxObject *parent);

/***************************************************************************** 
* Global Function
*****************************************************************************/
extern "C" void vtst_main_scr(void)
{
    VtstMSApp::TstParams tp;
    tp.type = 0;
    VfxAppLauncher::launchWithAsmSize( 
        APP1_BASE, 
        VFX_OBJ_CLASS_INFO(VtstMSApp),
        GRP_ID_ROOT, 1024 * 500,
        &tp, sizeof(tp));
}

VtstTestResultEnum vtst_rt_main_scr_entry(VfxU32 param)
{
    vtst_main_scr();
    return VTST_TR_OK;
}

VtstTestResultEnum vtst_rt_main_scr_events(VfxU32 param)
{
    VtstMSApp::TstParams tp;
    tp.type = 1;
    VfxAppLauncher::launchWithAsmSize( 
        APP1_BASE, 
        VFX_OBJ_CLASS_INFO(VtstMSApp),
        GRP_ID_ROOT, 1024 * 500,
        &tp, sizeof(tp));
    return VTST_TR_OK;
}

#define VTST_MAINSCR_BASIC

class VtstMSSwitch : public VcpSwitch
{
    VFX_DECLARE_CLASS(VtstMSSwitch);
public:
    VfxId getFunc()
    {
        return getChecked() ? m_on : m_off;
    }

public:
    VfxId m_on, m_off;
};

VFX_IMPLEMENT_CLASS("VtstMSSwitch", VtstMSSwitch, VcpSwitch);


VFX_IMPLEMENT_CLASS("VtstMSAppBasePage", VtstMSAppBasePage, VfxPage);

void VtstMSAppBasePage::onInit()
{
    VfxPage::onInit();    

    setBgColor(VFX_COLOR_WHITE);

    VfxFrame *f;
    VfxSize size = getSize();
    size.width -= 20;
    size.height -= 20;
    
    VFX_OBJ_CREATE(f, VfxFrame, this);
    f->setPos(10, 10);
    f->setSize(size);
    f->setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT, VFX_FRAME_ALIGNER_MODE_SIDE);
    f->setAlignParent(VFX_FRAME_ALIGNER_SIDE_TOP, VFX_FRAME_ALIGNER_MODE_SIDE);
    f->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_SIDE);
    f->setAlignParent(VFX_FRAME_ALIGNER_SIDE_BOTTOM, VFX_FRAME_ALIGNER_MODE_SIDE);
    f->setAutoAnimate(VFX_TRUE);
    m_frame = f;

    m_nextPos.x = 70;
    m_nextPos.y = 100;
}

VfxBool VtstMSAppBasePage::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT &&
        event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        getMainScr()->popPage();
        return VFX_TRUE;
    }
    if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT &&
        event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        onFunc(FUNC_ID_NEXT);
        return VFX_TRUE;
    }
    
    return VfxPage::onKeyInput(event);
}

void VtstMSAppBasePage::_onClicked(VfxObject *obj, VfxId id)
{
    VfxRect rect = getMainScr()->getClientRect();

    switch(id)
    {
    case FUNC_ID_PREV:
        getMainScr()->popPage();
        break;
    default:
        onFunc(id);
    }
}

void VtstMSAppBasePage::_onSwitch(VcpSwitch *obj, VfxBool isChecked)
{
    VtstMSSwitch *sw = VFX_OBJ_DYNAMIC_CAST(obj, VtstMSSwitch);
    if(sw)
    {
        onFunc(sw->getFunc());
    }
}

void VtstMSAppBasePage::setColor(const VfxColor &color) 
{ 
    m_frame->setBgColor(color); 
    if(m_tf)
    {
        VfxColor c;
        c.value = ~color.value;
        c.setA(255);
        m_tf->setColor(c);
    }
}

VfxPageBar *VtstMSAppBasePage::initToolbar(VfxResId id1, VfxResId id2, VfxResId id3) 
{
    VtstMSAppToolBar *tb;
    VFX_OBJ_CREATE(tb, VtstMSAppToolBar, this);
    tb->m_sb->addButton(1, VcpStateImage(id1), VFX_WSTR(""));
    if(id2)
        tb->m_sb->addButton(2, VcpStateImage(id2), VFX_WSTR(""));
    if(id3)
        tb->m_sb->addButton(3, VcpStateImage(id3), VFX_WSTR(""));
    setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, tb);
    return tb;
}

VfxPageBar *VtstMSAppBasePage::initTitlebar(const VfxWString &str)
{
    VtstMSAppTitleBar *tb;
    VFX_OBJ_CREATE(tb, VtstMSAppTitleBar, this);
    tb->setTitle(str);
    setBar(VFX_PAGE_BAR_LOCATION_TOP, tb);
    tb->setButton(0, VFX_WSTR("Back"), FUNC_ID_PREV, 
        VcpCommandTitleButtonCB(this, &VtstMSAppBasePage::_onClicked));
    tb->setButton(1, VFX_WSTR("Next"), FUNC_ID_NEXT, 
        VcpCommandTitleButtonCB(this, &VtstMSAppBasePage::_onClicked));
    return tb;
}

void VtstMSAppBasePage::init2WayButton()
{
    VcpButton *button;
    VFX_OBJ_CREATE(button, VcpButton, this);
    button->setAnchor(0.5f, 0.5f);
    button->setPos(70, 30);
    button->setText(VFX_WSTR("Back"));
    button->setIsAutoResized(VFX_TRUE);
    button->setId(FUNC_ID_PREV);
    button->m_signalClicked.connect(this, &VtstMSAppBasePage::_onClicked);

    VFX_OBJ_CREATE(button, VcpButton, this);
    button->setAnchor(0.5f, 0.5f);
    button->setPos(170, 30);
    button->setText(VFX_WSTR("Next"));
    button->setIsAutoResized(VFX_TRUE);
    button->setId(FUNC_ID_NEXT);
    button->m_signalClicked.connect(this, &VtstMSAppBasePage::_onClicked);

}

void VtstMSAppBasePage::setHint(const VfxWString &str)
{
    if(!m_tf)
    {
        VFX_OBJ_CREATE(m_tf, VfxTextFrame, this);
        m_tf->setRect(VfxRect(0, 60, 240, 20));
        m_tf->setAutoResized(VFX_FALSE);
        m_tf->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
        m_tf->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        
        VfxColor color = m_frame->getBgColor();
        color.value = ~color.value;
        color.setA(255);
        m_tf->setColor(color);
    }
    m_tf->setString(str);
}

void VtstMSAppBasePage::addFunc(const VfxWString &str, VfxId id)
{
    VFX_ASSERT(id != FUNC_ID_PREV && id != FUNC_ID_NEXT);

    VcpButton *button;
    VFX_OBJ_CREATE(button, VcpButton, this);
    button->setAnchor(0.5f, 0.5f);
    button->setPos(m_nextPos);
    button->setText(str);
    button->setIsAutoResized(VFX_TRUE);
    button->setId(id);
    button->m_signalClicked.connect(this, &VtstMSAppBasePage::_onClicked);

    // move to next pos
    if(m_nextPos.x == 70)
        m_nextPos.x = 170;
    else
    {
        m_nextPos.x = 70;
        m_nextPos.y += 30;
    }
}

void VtstMSAppBasePage::addSwitch(const VfxWString &str, VfxId id_on, VfxId id_off, VfxBool checked)
{
    // need a full line
    if(m_nextPos.x != 70)
    {
        m_nextPos.x = 70;
        m_nextPos.y += 30;
    }

    // create a label and switch
    VfxTextFrame *tf;
    VFX_OBJ_CREATE(tf, VfxTextFrame, this);
    tf->setAnchor(0.5f, 0.5f);
    tf->setPos(m_nextPos);
    tf->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    tf->setString(str);
    VfxColor color = m_frame->getBgColor();
    color.value = ~color.value;
    color.setA(255);
    tf->setColor(color);

    VtstMSSwitch *sw;
    VFX_OBJ_CREATE(sw, VtstMSSwitch, this);
    sw->m_on = id_on;
    sw->m_off = id_off;
    sw->setAnchor(0.5f, 0.5f);
    sw->setPos(VfxPoint(170, m_nextPos.y));
    sw->m_signalSwitchChanged.connect(this, &VtstMSAppBasePage::_onSwitch);
    sw->setChecked(checked);

    // move to next pos
    m_nextPos.y += 30;
}

VFX_IMPLEMENT_CLASS("VtstMSAppTitleBar", VtstMSAppTitleBar, VfxPageBar);

void VtstMSAppTitleBar::onInit()
{
    VfxPageBar::onInit();

    VFX_OBJ_CREATE(m_title, VcpCommandTitle, this);

    m_title->setPos(0, 0);
    m_title->setAutoAnimate(VFX_TRUE);
    setSize(m_title->getSize());

    // set shadow
    VfxFrame *f;
    VFX_OBJ_CREATE(f, VfxFrame, this);
    f->setSize(20, 20);
    f->setBgColor(VRT_COLOR_MAKE(128, 255, 0, 0));
    setShadowFrame(f);
}

void VtstMSAppTitleBar::setButton(VfxU32 index, const VfxWString &str, VfxId id, VcpCommandTitleButtonCB handler)
{
    m_title->setAddOnTextButton(index, str, id, handler);
}

void VtstMSAppTitleBar::onSetTranslucent(VfxBool on)
{
    VfxPageBar::onSetTranslucent(on);
    m_title->setOpacity(on ? 0.5f : 1.0f);
}

void VtstMSAppTitleBar::setBounds(const VfxRect &value)
{
    VfxPageBar::setBounds(value);

    if(m_title)
        m_title->setSize(value.size);
}

VFX_IMPLEMENT_CLASS("VtstMSAppToolBar", VtstMSAppToolBar, VfxPageBar);

void VtstMSAppToolBar::onInit()
{
    VfxPageBar::onInit();

    VFX_OBJ_CREATE(m_sb, VcpSegmentButton, this);
    m_sb->setPos(0, 0);
    m_sb->setAutoAnimate(VFX_TRUE);
    setSize(m_sb->getSize());

    m_signalBoundsChanged.connect(this, &VtstMSAppToolBar::onBoundChanged);

    // set shadow
    VfxFrame *f;
    VFX_OBJ_CREATE(f, VfxFrame, this);
    f->setSize(20, 20);
    f->setBgColor(VRT_COLOR_MAKE(128, 0, 0, 255));
    setShadowFrame(f);    
}

void VtstMSAppToolBar::onBoundChanged(VfxFrame *f, const VfxRect &r)
{
    m_sb->setSize(f->getSize());
}

void VtstMSAppToolBar::onSetTranslucent(VfxBool on)
{
    VfxPageBar::onSetTranslucent(on);
    m_sb->setOpacity(on ? 0.5f : 1.0f);
}

class VtstMSAppPage5 : public VtstMSAppBasePage
{
protected:
    virtual void onInit()
    {
        VtstMSAppBasePage::onInit();
        setColor(VFX_COLOR_SILVER);

        initTitlebar(VFX_WSTR("page5"));

        setHint(VFX_WSTR("History test"));

        addFunc(VFX_WSTR("Test1"), 10);
        addFunc(VFX_WSTR("Test2"), 11);
        addFunc(VFX_WSTR("Test3"), 12);
        addFunc(VFX_WSTR("Test4"), 13);
        addFunc(VFX_WSTR("Insert"), 14);
    }

    virtual void onFunc(VfxId funcId)
    {
        switch(funcId)
        {
        case 10:
            {
                VFX_ASSERT(getMainScr()->getPageCount() == 6);
                VfxId idBuf[6];
                VFX_ASSERT(getMainScr()->getPageIds(idBuf, 6) == 6);
                VfxS32 i;
                VfxId a;
                for(i=0, a = getMainScr()->getTopPageId(); a != VFX_ID_NULL; a = getMainScr()->getPrevPageId(a), i++)
                {
                    VFX_ASSERT(a == idBuf[i]);
                }
                VFX_ASSERT(i == 6);

                for(i=5, a = idBuf[5]; a != VFX_ID_NULL; a = getMainScr()->getNextPageId(a), i--)
                {
                    VFX_ASSERT(a == idBuf[i]);
                }
                VFX_ASSERT(i == -1);
            }
            break;
        case 11:
            {
                // close current = pop
                VfxId self = getMainScr()->getPageId(this);
                VFX_ASSERT(self == getMainScr()->getTopPageId());
                getMainScr()->closePage(self);
            }
            break;

        case 12:
            {
                // close all 
                VfxId idBuf[6];
                VfxS32 i, j;
                j = getMainScr()->getPageIds(idBuf, 6);
                for(i=0;i<j;i++)
                {
                    getMainScr()->closePage(idBuf[i]);
                }
            }
            break;
        case 13:
            {
                // close all, in reverse order
                VfxId idBuf[6];
                VfxS32 i, j;
                j = getMainScr()->getPageIds(idBuf, 6);
                for(i=j-1;i>=0;i--)
                {
                    getMainScr()->closePage(idBuf[i]);
                }
            }
            break;

        case 14:
            {
                VfxId self = getId();
                self = getMainScr()->getPrevPageId(self);
                getMainScr()->insertPage(0, createPage2(getMainScr()), self);
            }
            break;
        }
    }
};

class VtstMSAppPage4 : public VtstMSAppBasePage
{
protected:
    virtual void onInit()
    {
        VtstMSAppBasePage::onInit();
        setColor(VFX_COLOR_OLIVE);

        setTranslucent(VFX_TRUE);
        setBarAutoHide(VFX_TRUE);
        initTitlebar(VFX_WSTR("page4"));
        initToolbar(IMG_GLOBAL_L4, IMG_GLOBAL_L4, IMG_GLOBAL_L4);
        setHint(VFX_WSTR("Translucent"));
        addFunc(VFX_WSTR("Kick"), 10);
    }

    virtual void onFunc(VfxId funcId)
    {
        switch(funcId)
        {
        case VtstMSAppBasePage::FUNC_ID_NEXT:
            VtstMSAppBasePage *page;
            VFX_OBJ_CREATE(page, VtstMSAppPage5, getMainScr());
            getMainScr()->pushPage(0, page);
            break;
        case 10:
            hideAllBars(VFX_FALSE);            
            break;
        }
    }
};


class VtstMSAppPage3 : public VtstMSAppBasePage
{
    VFX_DECLARE_CLASS(VtstMSAppPage3);
protected:
    virtual void onInit()
    {
        VtstMSAppBasePage::onInit();
        setColor(VFX_COLOR_YELLOW);

        setStatusBar(VFX_FALSE);
        initTitlebar(VFX_WSTR("page3"));
        setHint(VFX_WSTR("Load on demand, no status bar"));
    }

    virtual void onFunc(VfxId funcId)
    {
        switch(funcId)
        {
        case VtstMSAppBasePage::FUNC_ID_NEXT:
            VtstMSAppBasePage *page;
            VFX_OBJ_CREATE(page, VtstMSAppPage4, getMainScr());
            getMainScr()->pushPage(0, page);
        }
    }

    virtual void onTransitionStop(VfxBool in, VfxS32 direction)
    {
        VfxPage::onTransitionStop(in, direction);

        if(!in)
        {
            VfxPage *page = this;
            VFX_OBJ_CLOSE(page);
        }
    }
};

VFX_IMPLEMENT_CLASS("VtstMSAppPage3", VtstMSAppPage3, VtstMSAppBasePage);

class VtstMSAppPageTabPage : public VtstMSAppBasePage
{
public:

protected:
    virtual void onInit()
    {
        VtstMSAppBasePage::onInit();

        addFunc(VFX_WSTR("On 1"), 10);
        addFunc(VFX_WSTR("Off 1"), 11);
        addFunc(VFX_WSTR("On 2"), 12);
        addFunc(VFX_WSTR("Off 2"), 13);
        addFunc(VFX_WSTR("On 3"), 14);
        addFunc(VFX_WSTR("Off 3"), 15);
        
        addFunc(VFX_WSTR("isActive"), 20);
    }
    virtual void onFunc(VfxId funcId)
    {
        VcpTabCtrlPage *pParent = VFX_OBJ_DYNAMIC_CAST(getParent(), VcpTabCtrlPage);
        VFX_ASSERT(pParent);
        switch(funcId)
        {
        case VtstMSAppBasePage::FUNC_ID_NEXT:
            getMainScr()->pushPageEx(0, VFX_OBJ_CLASS_INFO(VtstMSAppPage3));
            break;

        case 10: pParent->setTabEnabled(123, VFX_TRUE); break;
        case 11: pParent->setTabEnabled(123, VFX_FALSE); break;
        case 12: pParent->setTabEnabled(456, VFX_TRUE); break;
        case 13: pParent->setTabEnabled(456, VFX_FALSE); break;
        case 14: pParent->setTabEnabled(789, VFX_TRUE); break;
        case 15: pParent->setTabEnabled(789, VFX_FALSE); break;

        case 20:
            VcpAlertPopup *popup;
            VFX_OBJ_CREATE(popup, VcpAlertPopup, this);
            popup->setInfoType(VCP_POPUP_TYPE_INFO);
            if(isActive())
                popup->setText(VFX_WSTR("Yes"));
            else
                popup->setText(VFX_WSTR("No"));
            popup->show(VFX_TRUE);
            break;            
        }
    }
};

class VtstMSAppPageTab : public VcpTabCtrlPage
{
protected:
    virtual void onInit()
    {
        VcpTabCtrlPage::onInit();

        VtstMSAppTitleBar *tb;
        VFX_OBJ_CREATE(tb, VtstMSAppTitleBar, this);
        tb->setTitle(VFX_WSTR("Tab Page"));
        setBar(VFX_PAGE_BAR_LOCATION_TOP, tb);

        addTab(123, VFX_WSTR("Red"),   VcpStateImage(IMG_GLOBAL_L3));
        addTab(456, VFX_WSTR("Green"), VcpStateImage(IMG_GLOBAL_L6));
        addTab(789, VFX_WSTR("Blue"),  VcpStateImage(IMG_GLOBAL_L9));
        setCurrTab(123);
    }

    virtual VfxPage *onCreateTabPage(VfxId tabId) 
    { 
        VtstMSAppPageTabPage *page;
        VFX_OBJ_CREATE(page, VtstMSAppPageTabPage, this);
        page->init2WayButton();

        switch(tabId)
        {
        case 123:
            page->setColor(VFX_COLOR_RED);
            page->initToolbar(IMG_GLOBAL_L7, IMG_GLOBAL_L8);
            page->setHint(VFX_WSTR("Toolbar(7,8)"));
            break;
        case 456:
            page->setColor(VFX_COLOR_GREEN);
            page->setHint(VFX_WSTR("Toolbar(n/a)"));
            break;
        case 789:
            page->setColor(VFX_COLOR_BLUE);
            page->initToolbar(IMG_GLOBAL_L9, IMG_GLOBAL_L8, IMG_GLOBAL_L7);
            page->setHint(VFX_WSTR("Toolbar(9,8,7)"));
            break;
        }
        return page;        
    }
};

class VtstMSAppPage2 : public VtstMSAppBasePage
{
    VFX_DECLARE_CLASS(VtstMSAppPage2);
protected:
    virtual void onInit()
    {
        VtstMSAppBasePage::onInit();
        setColor(VFX_COLOR_FUCHSIA);

        initTitlebar(VFX_WSTR("page2"));
        m_toolBar1 = initToolbar(IMG_GLOBAL_L1, IMG_GLOBAL_L2, IMG_GLOBAL_L3);
        m_toolBar2 = NULL;
        m_bar1 = VFX_TRUE;
        m_inHideAll = VFX_FALSE;
        barHeight = m_toolBar1->getSize().height;

        setHint(VFX_WSTR("Test bottomBar"));
        addFunc(VFX_WSTR("Toggle"), 10);
        addFunc(VFX_WSTR("Change"), 20);
        addFunc(VFX_WSTR("Size"),   30);
        addFunc(VFX_WSTR("All"),    40);
    }

    virtual void onFunc(VfxId funcId)
    {
        switch(funcId)
        {
        case VtstMSAppBasePage::FUNC_ID_NEXT:
            VfxPage *page;
            VFX_OBJ_CREATE(page, VtstMSAppPageTab, getMainScr());
            getMainScr()->pushPage(0, page);
            break;
        case 10:
            toggleBar(VFX_PAGE_BAR_LOCATION_BOTTOM, !isBarOn(VFX_PAGE_BAR_LOCATION_BOTTOM));
            break;
        case 20:
            m_bar1 = !m_bar1;
            if(m_bar1)
            {
                setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, m_toolBar1);
            }
            else
            {
                if(!m_toolBar2)
                {
                    m_toolBar2 = initToolbar(IMG_GLOBAL_L6, IMG_GLOBAL_L6);
                }
                else
                    setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, m_toolBar2);
            }
            break;
        case 30:
        {
            VfxPageBar *bar;
            if(m_bar1)
                bar = m_toolBar1;
            else
                bar = m_toolBar2;

            VfxSize s = bar->getSize();
            if(s.height == barHeight)
                s.height = barHeight * 2;
            else
                s.height = barHeight;
            bar->setSize(s);
            break;
        }
        case 40:
            m_inHideAll = !m_inHideAll;
            hideAllBars(m_inHideAll);
            break;
        }
    }
private:
    VfxBool m_bar1;
    VfxBool m_inHideAll;
    VfxPageBar *m_toolBar1, *m_toolBar2;
    VfxS32 barHeight;
};

VFX_IMPLEMENT_CLASS("VtstMSAppPage2", VtstMSAppPage2, VtstMSAppBasePage);

VtstMSAppBasePage* createPage2(VfxObject *parent)
{
    VtstMSAppBasePage *page;
    VFX_OBJ_CREATE(page, VtstMSAppPage2, parent);
    return page;
}

class VtstMSAppPage1 : public VtstMSAppBasePage
{
protected:
    virtual void onInit()
    {
        VtstMSAppBasePage::onInit();
        setColor(VFX_COLOR_AQUA);

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
#else
        initTitlebar(VFX_WSTR("page1"));
        initToolbar(IMG_GLOBAL_L7);
        setHint(VFX_WSTR("statusBar"));
        addFunc(VFX_WSTR("On"), 10);
        addFunc(VFX_WSTR("Off"), 20);
        addFunc(VFX_WSTR("Close 1"), 31);
        addFunc(VFX_WSTR("Close 2"), 32);
        addFunc(VFX_WSTR("Close 3"), 33);

        addFunc(VFX_WSTR("NewScr"), 41);
        addFunc(VFX_WSTR("NewApp"), 42);
#endif        
    }

    virtual void onFunc(VfxId funcId)
    {
        VtstMSAppScr *scr = VFX_OBJ_DYNAMIC_CAST(getMainScr(), VtstMSAppScr);
        switch(funcId)
        {
        case VtstMSAppBasePage::FUNC_ID_NEXT:
            VtstMSAppBasePage *page;
            VFX_OBJ_CREATE(page, VtstMSAppPage2, scr);
            scr->pushPage(0, page);
            break;
        case 10:
            setStatusBar(VFX_TRUE);
            break;
        case 20:
            setStatusBar(VFX_FALSE);
            break;
        case 31:
            scr->popPage();
            scr->pushPageEx(0, VFX_OBJ_CLASS_INFO(VtstMSAppPage2));
            break;
        case 32:
            scr->delayPushPage(VFX_OBJ_CLASS_INFO(VtstMSAppPage2), 0);
            scr->popPage();
            break;
        case 33:
            scr->setAutoClose(VFX_FALSE);
            scr->popPage();
            scr->delayPushPage(VFX_OBJ_CLASS_INFO(VtstMSAppPage2), 2000);
            break;
        case 41:
            {
                VtstMSAppScr *scr;
                VFX_OBJ_CREATE(scr, VtstMSAppScr, getApp());
                scr->show();
            }
            break;
        case 42:
            vtst_main_scr();
            break;
        }
    }
};


VFX_IMPLEMENT_CLASS("VtstMSAppScr", VtstMSAppScr, VfxMainScr);

class VtstMSAppTimer : public VfxTimer
{
public:
    VtstMSAppTimer(const VfxClassInfo *info):
        m_info(info)
    {
    }
    virtual ~VtstMSAppTimer() 
    {
    }

public:
    void pushPage(VfxMainScr* scr)
    {
        scr->pushPageEx(0, m_info);
    }

private:
    const VfxClassInfo *m_info;
};

void VtstMSAppScr::delayPushPage(const VfxClassInfo *info, VfxMsec delay)
{
    if(!delay)
    {
        vfxPostInvoke1(this, &VtstMSAppScr::_pushPage, info);
    }
    else
    {
        VtstMSAppTimer *timer;
        VFX_OBJ_CREATE_EX(timer, VtstMSAppTimer, this, (info));
        timer->m_signalTick.connect(this, &VtstMSAppScr::onTimer);
        timer->setStartDelay(delay);
        timer->start();
    }
}

void VtstMSAppScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VfxPage *page;
    VFX_OBJ_CREATE(page, VtstMSAppPage1, this);
    pushPage(0, page);
}

void VtstMSAppScr::_pushPage(const VfxClassInfo *info)
{
    pushPageEx(0, info);
}

void VtstMSAppScr::onTimer(VfxTimer* t)
{
    VtstMSAppTimer *timer = (VtstMSAppTimer*)t;
    if(timer)
    {
        timer->pushPage(this);
        VFX_OBJ_CLOSE(timer);
    }
}


#define VTST_MAINSCR_EVENTS

VFX_IMPLEMENT_CLASS("VtstMSEventScr", VtstMSEventScr, VfxMainScr);

void VtstMSEventScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VtstMSEventPage *page;
    VFX_OBJ_CREATE(page, VtstMSEventPage, this);
    page->m_id = m_id + 1;
    pushPage(1, page);
}

void VtstMSEventScr::onInit()
{
    VfxMainScr::onInit();

    print("onInit");
}

void VtstMSEventScr::onDeinit()
{
    print("onDeinit");

    VfxMainScr::onDeinit();
}

void VtstMSEventScr::onEnter(VfxBool isBackward)
{
    VfxMainScr::onEnter(isBackward);

    print("onEnter");
}

void VtstMSEventScr::onExit(VfxBool isBackward)
{
    VfxMainScr::onExit(isBackward);
    
    print("onExit");
}

VfxBool VtstMSEventScr::onSerialize(VfxArchive &ar)
{
    print("onSerialize");
    ar.writeU32(m_id);
    return VFX_TRUE;
}

void VtstMSEventScr::onRestore(VfxArchive &ar)
{
    m_id = ar.readU32();
    print("onRestore");
}

void VtstMSEventScr::print(const VfxChar *printStr)
{
    VfxWString str;
    str.format("S(%d)::%s()\n", m_id, printStr);
    getMyApp()->writeLine(str);
}

VFX_IMPLEMENT_CLASS("VtstMSEventPage", VtstMSEventPage, VfxPage);

void VtstMSEventPage::updateContent()
{
    VfxWString str;
    getMyApp()->getLines(str);
    m_tf2->setString(str);    
}

void VtstMSEventPage::onInit()
{
    VfxPage::onInit();

    VcpButton *button;
    VFX_OBJ_CREATE(button, VcpButton, this);
    button->setAnchor(0.5f, 0.5f);
    button->setPos(70, 30);
    button->setText(VFX_WSTR("Back"));
    button->setIsAutoResized(VFX_TRUE);
    button->setId(1);
    button->m_signalClicked.connect(this, &VtstMSEventPage::onClicked);

    VFX_OBJ_CREATE(button, VcpButton, this);
    button->setAnchor(0.5f, 0.5f);
    button->setPos(170, 30);
    button->setText(VFX_WSTR("Next"));
    button->setIsAutoResized(VFX_TRUE);
    button->setId(2);
    button->m_signalClicked.connect(this, &VtstMSEventPage::onClicked);

    VFX_OBJ_CREATE(m_tf1, VfxTextFrame, this);
    m_tf1->setRect(VfxRect(0, 50, 180, 20));
    m_tf1->setAutoResized(VFX_FALSE);
    m_tf1->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    m_tf1->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_tf1->setColor(VFX_COLOR_WHITE);
    VfxWString str;
    str.format("Page %d-%d", m_id/10, m_id%10);
    m_tf1->setString(str);

    VFX_OBJ_CREATE(m_tf, VfxTextFrame, this);
    m_tf->setRect(VfxRect(180, 50, 60, 20));
    m_tf->setAutoResized(VFX_FALSE);
    m_tf->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    m_tf->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_tf->setColor(VFX_COLOR_WHITE);

    VFX_OBJ_CREATE(m_tf2, VfxTextFrame, this);
    m_tf2->setRect(VfxRect(10, 70, 230, 330));
    m_tf2->setAutoResized(VFX_FALSE);
    m_tf2->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    m_tf2->setColor(VFX_COLOR_YELLOW);
    m_tf2->setFont(VFX_FONT_DESC_SMALL);

    print("onInit");
}

void VtstMSEventPage::onDeinit()
{
    print("onDeinit");

    VfxPage::onDeinit();
}

void VtstMSEventPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

    print("onEnter");
    VfxWString str;
    str.format("%d", ++m_count);
    m_tf->setString(str);
    str.format("Page %d-%d", m_id/10, m_id%10);
    m_tf1->setString(str);
}

void VtstMSEventPage::onEntered()
{
    VfxPage::onEntered();

    print("onEntered");
}

void VtstMSEventPage::onExit(VfxBool isBackward)
{
    print("onExit");

    VfxPage::onExit(isBackward);
}

void VtstMSEventPage::onExited()
{
    print("onExited");

    VfxPage::onExited();
}

VfxBool VtstMSEventPage::onSerialize(VfxArchive &ar)
{
    print("onSerialize");

    ar.writeU32(m_id);
    ar.writeU32(m_count);
    return VFX_TRUE;
}

void VtstMSEventPage::onRestore(VfxArchive &ar)
{
    m_id = ar.readU32();
    m_count = ar.readU32();
    print("onRestore");
}

void VtstMSEventPage::onBack()
{
    getMyApp()->clearLines();
    updateContent();
    
    VfxPage::onBack();
}

void VtstMSEventPage::print(const VfxChar *printStr)
{
    VfxWString str;
    str.format("P(%d)::%s()\n", m_id, printStr);
    getMyApp()->writeLine(str);
}

void VtstMSEventPage::onClicked(VfxObject *obj, VfxId id)
{
    getMyApp()->clearLines();
    updateContent();
    
    if(id == 1)
    {
        exit();
    }
    else
    {
        switch(getId())
        {
        case 1:
            VtstMSEventPage *page;
            VFX_OBJ_CREATE(page, VtstMSEventPage, getMainScr());
            page->m_id = m_id + 1;
            getMainScr()->pushPage(2, page);
            break;

        case 2:
            VtstMSEventScr *scr;
            VFX_OBJ_CREATE(scr, VtstMSEventScr, getApp());
            scr->m_id = (m_id/10+1) * 10;
            scr->show();
            break;
        }
    }
}

#define VTST_MAINSCR_EVENTS_AUTO

class VtstMSAppEventsAuto : public VtstMSApp
{
    VFX_DECLARE_CLASS(VtstMSAppEventsAuto);

// Override
public:
    virtual VfxS32 start();
    virtual VfxS32 phase(VfxS32 idx);

private:
    VfxWString m_correctAnswer;
};

VFX_IMPLEMENT_CLASS("VtstMSAppEventsAuto", VtstMSAppEventsAuto, VtstMSApp);


static void vtst_dummy_entry(mmi_scrn_essential_struct* scrn_info)
{
    mmi_frm_scrn_enter(scrn_info->group_id, scrn_info->scrn_id, NULL, (FuncPtr)vtst_dummy_entry, MMI_FRM_FULL_SCRN);
}

VfxS32 VtstMSAppEventsAuto::start()
{
    // To prevent auto close
    mmi_frm_scrn_first_enter(getGroupId(), SCR_ID_DUMMY, (FuncPtr)vtst_dummy_entry, NULL);
    return 0;
}

VfxS32 VtstMSAppEventsAuto::phase(VfxS32 idx)
{
    switch(idx)
    {
    /****************************************************************************/
    case 0: // Test 1:  create and enter 1st screen
        {
            clearLines();
            VtstMSEventScr *scr;
            VFX_OBJ_CREATE(scr, VtstMSEventScr, this);
            scr->m_id = 10;
            scr->show();

            m_correctAnswer = VFX_WSTR("S(0)::onInit()\nP(0)::onInit()\nS(10)::onEnter()\nP(11)::onEnter()\nP(11)::onEntered()\n");
        }
        break;

    /****************************************************************************/
    case 2: // Test 2:  push 2nd page
        {
            clearLines();

            // find Top page
            VtstMSEventScr *scr = VFX_OBJ_DYNAMIC_CAST(getScreen(getTopScreenId()), VtstMSEventScr);
            VtstMSEventPage *page;
            VFX_OBJ_CREATE(page, VtstMSEventPage, scr);
            page->m_id = scr->m_id + 2;
            scr->pushPage(2, page);

            m_correctAnswer = VFX_WSTR("P(0)::onInit()\nP(11)::onExit()\nP(12)::onEnter()\nP(11)::onExited()\nP(11)::onSerialize()\nP(11)::onDeinit()\nP(12)::onEntered()\n");
        }
        break;

    /****************************************************************************/
    case 4: // Test 3:  create and enter 2nd screen
        {
            clearLines();
            VtstMSEventScr *scr;
            VFX_OBJ_CREATE(scr, VtstMSEventScr, this);
            scr->m_id = 20;
            scr->show();

            m_correctAnswer = VFX_WSTR("S(0)::onInit()\nP(12)::onExit()\nP(12)::onExited()\nP(12)::onSerialize()\nP(12)::onDeinit()\nS(10)::onExit()\nS(10)::onSerialize()\nS(10)::onDeinit()\nP(0)::onInit()\nS(20)::onEnter()\nP(21)::onEnter()\nP(21)::onEntered()\n");
        }
        break;

    /****************************************************************************/
    case 6: // Test 4:  exit 2nd screen
        {
            clearLines();
            VtstMSEventScr *scr = VFX_OBJ_DYNAMIC_CAST(getScreen(getTopScreenId()), VtstMSEventScr);
            scr->popPage();

            m_correctAnswer = VFX_WSTR("P(21)::onExit()\nP(21)::onExited()\nS(20)::onExit()\nS(0)::onInit()\nS(10)::onRestore()\nS(20)::onDeinit()\nP(21)::onDeinit()\nS(10)::onEnter()\nP(0)::onInit()\nP(12)::onRestore()\nP(12)::onEnter()\nP(12)::onEntered()\n");
        }
        break;

    /****************************************************************************/
    case 8: // Test 5:  pop 2nd page of 1st screen
        {
            clearLines();
            VtstMSEventScr *scr = VFX_OBJ_DYNAMIC_CAST(getScreen(getTopScreenId()), VtstMSEventScr);
            scr->popPage();

            m_correctAnswer = VFX_WSTR("P(0)::onInit()\nP(11)::onRestore()\nP(12)::onExit()\nP(11)::onEnter()\nP(12)::onExited()\nP(12)::onDeinit()\nP(11)::onEntered()\n");
        }
        break;

    /****************************************************************************/
    case 10: // Test 6: pop 1st page of 1st screen
        {
            clearLines();
            VtstMSEventScr *scr = VFX_OBJ_DYNAMIC_CAST(getScreen(getTopScreenId()), VtstMSEventScr);
            scr->popPage();

            m_correctAnswer = VFX_WSTR("P(11)::onExit()\nP(11)::onExited()\nS(10)::onExit()\nS(10)::onDeinit()\nP(11)::onDeinit()\n");
        }
        break;        
    }

    if(idx % 2 == 0)
    {
        if(m_correctAnswer.isEmpty())
            return VTST_RT_END_TESTCASE;    // end test case
        else
            return VFX_TIMELINE_DEFAULT_DUR_TIME*5;
    }

    // Verify phase
    VfxWString str, testname;
    testname.format("Stage %d", (idx-1)/2+1);

    getLines(str);
    check(str == m_correctAnswer, testname);
    m_correctAnswer.setNull();
    return 0;   // next phase
}

VtstTestResultEnum vtst_rt_main_scr_events_auto(VfxU32 param)
{
    VfxAppLauncher::launchWithAsmSize( 
        APP1_BASE, 
        VFX_OBJ_CLASS_INFO(VtstMSAppEventsAuto),
        GRP_ID_ROOT, 1024 * 500);
    return VTST_TR_OK;
}

#define VTST_MAINSCR_ROTATE

class VtstMSAppRotateScr : public VfxMainScr
{
// Override
protected:
    virtual void on1stReady();
};

class VtstMSAppRotatePage3 : public VtstMSAppBasePage
{
    VFX_DECLARE_CLASS(VtstMSAppRotatePage3);
protected:
    virtual void onInit()
    {
        VtstMSAppBasePage::onInit();
        
        setColor(VFX_COLOR_PURPLE);
        
        initTitlebar(VFX_WSTR("page 3"));
        initToolbar(IMG_GLOBAL_L3, IMG_GLOBAL_L3, IMG_GLOBAL_L3);
    }
    virtual void onFunc(VfxId funcId)
    {
        switch(funcId)
        {
        case VtstMSAppBasePage::FUNC_ID_NEXT:
            VtstMSAppRotateScr *scr;
            VFX_OBJ_CREATE(scr, VtstMSAppRotateScr, getApp());
            scr->show();
            break;
        }
    }
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
        param.rotateTo = VFX_SCR_ROTATE_TYPE_180;
    }
public:

};

VFX_IMPLEMENT_CLASS("VtstMSAppRotatePage3", VtstMSAppRotatePage3, VtstMSAppBasePage);

class VtstMSAppRotatePage2 : public VtstMSAppBasePage
{
    VFX_DECLARE_CLASS(VtstMSAppRotatePage2);
protected:
    virtual void onInit()
    {
        VtstMSAppBasePage::onInit();
        
        setColor(VFX_COLOR_AQUA);
        
        initTitlebar(VFX_WSTR("page 2"));
        initToolbar(IMG_GLOBAL_L2, IMG_GLOBAL_L2, IMG_GLOBAL_L2);

        addFunc(VFX_WSTR("Rotate"), 10);
        addFunc(VFX_WSTR("Reset"), 20);
        m_ready = VFX_FALSE;
    }
    virtual void onEntered()
    {
        VtstMSAppBasePage::onEntered();
        m_ready = VFX_TRUE;
        m_idx = 1;
    }
    virtual void onExit(VfxBool isBackward)
    {
        m_ready = VFX_FALSE;
        VtstMSAppBasePage::onExit(isBackward);
    }
    virtual void onFunc(VfxId funcId)
    {
        VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
        switch(funcId)
        {
        case VtstMSAppBasePage::FUNC_ID_NEXT:
            VfxPage *page;
            VFX_OBJ_CREATE(page, VtstMSAppRotatePage3, getMainScr());
            getMainScr()->pushPage(0, page);
            break;
        case 10:
            m_idx = (m_idx+1)%4;
            topLevel->setScreenRotateType(m_angle[m_idx]);
            break;
        case 20:
            topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_NORMAL);
            m_idx = 0;
            break;
        }
    }
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
        if(!m_ready)
            param.rotateTo = VFX_SCR_ROTATE_TYPE_90;
    }
private:
    const static VfxScrRotateTypeEnum m_angle[4];
    VfxS32 m_idx;
    VfxBool m_ready;
};

const VfxScrRotateTypeEnum VtstMSAppRotatePage2::m_angle[4] = {
    VFX_SCR_ROTATE_TYPE_0,
    VFX_SCR_ROTATE_TYPE_90,
    VFX_SCR_ROTATE_TYPE_180,
    VFX_SCR_ROTATE_TYPE_270
};

VFX_IMPLEMENT_CLASS("VtstMSAppRotatePage2", VtstMSAppRotatePage2, VtstMSAppBasePage);

class VtstMSAppRotatePage1 : public VtstMSAppBasePage
{
    VFX_DECLARE_CLASS(VtstMSAppRotatePage1);
protected:
    virtual void onInit()
    {
        VtstMSAppBasePage::onInit();
        
        setColor(VFX_COLOR_YELLOW);
        
        initTitlebar(VFX_WSTR("page 1"));
        initToolbar(IMG_GLOBAL_L1, IMG_GLOBAL_L1, IMG_GLOBAL_L1);
    }
    virtual void onFunc(VfxId funcId)
    {
        switch(funcId)
        {
        case VtstMSAppBasePage::FUNC_ID_NEXT:
            VfxPage *page;
            VFX_OBJ_CREATE(page, VtstMSAppRotatePage2, getMainScr());
            getMainScr()->pushPage(0, page);
            break;
        }
    }
public:

};

VFX_IMPLEMENT_CLASS("VtstMSAppRotatePage1", VtstMSAppRotatePage1, VtstMSAppBasePage);

void VtstMSAppRotateScr::on1stReady()
{
    VfxPage *page;
    VFX_OBJ_CREATE(page, VtstMSAppRotatePage1, this);
    pushPage(0, page);
}

VtstTestResultEnum vtst_rt_main_scr_rotate(VfxU32 param)
{
    VtstMSApp::TstParams tp;
    tp.type = 2;
    VfxAppLauncher::launchWithAsmSize( 
        APP1_BASE, 
        VFX_OBJ_CLASS_INFO(VtstMSApp),
        GRP_ID_ROOT, 1024 * 500,
        &tp, sizeof(tp));
    return VTST_TR_OK;
}

#define VTST_APP

VFX_IMPLEMENT_CLASS("VtstMSApp", VtstMSApp, VtstRtApp);

void VtstMSApp::onInit()
{
    VfxApp::onInit();

    m_start = 0;
    m_count = 0;
}

void VtstMSApp::writeLine(const VfxWString &str)
{
    if(m_count < VTST_MS_MAX_LINES)
    {
        m_lines[m_count] = str;
        m_count++;
    }
    else
    {
        m_lines[m_start] = str;
        m_start++;
        if(m_start == VTST_MS_MAX_LINES)
            m_start = 0;
    }

    VtstMSEventScr *scr = VFX_OBJ_DYNAMIC_CAST(getScreen(getTopScreenId()), VtstMSEventScr);
    if(scr)
    {
        VtstMSEventPage *p = VFX_OBJ_DYNAMIC_CAST(scr->getPage(), VtstMSEventPage);
        if(p)
            p->updateContent();
    }
}

void VtstMSApp::getLines(VfxWString &str) const
{
    VfxS32 i;
    str.setNull();
    for(i = m_start; i<m_start+m_count; i++)
    {
        str += m_lines[i % VTST_MS_MAX_LINES];
    }
}

void VtstMSApp::clearLines()
{
    m_start = 0;
    m_count = 0;
}

void VtstMSApp::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    TstParams *tp = (TstParams*)args;
    if(tp)
    {
        if(tp->type == 0)
        {
            VtstMSAppScr *scr;
            VFX_OBJ_CREATE(scr, VtstMSAppScr, this);
            scr->show();
        }
        else if(tp->type == 1)
        {
            VtstMSEventScr *scr;
            VFX_OBJ_CREATE(scr, VtstMSEventScr, this);
            scr->m_id = 10;
            scr->show();
        }
        else if(tp->type == 2)
        {
            VtstMSAppRotateScr *scr;
            VFX_OBJ_CREATE(scr, VtstMSAppRotateScr, this);
            scr->show();
        }
    }
    else
    {
        vtst_testcase_start(this, VFX_FALSE);
    }
}



#define VTST_VFX_KEY

class VtstKeyApp : public VtstRtApp
{
    VFX_DECLARE_CLASS(VtstKeyApp);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);
    virtual mmi_ret onGroupDeleteReq(DelReason reason)
    {
        return getAllowDelete() ? MMI_RET_OK : MMI_RET_ERR;
    }

public:
    void setMode(VfxS32 mode, VfxWString &hint);

    void setAllowDelete(VfxBool);
    VfxBool getAllowDelete();

private:
    void onConfirmPopup(VfxObject *obj, VfxId ansId);
    void onStop(VfxTimer *timer);

private:
    VfxS32 m_mode;
    VfxBool m_allowDelete;
};

class VtstKeyScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VtstKeyScr);

// Override
protected:
    virtual void on1stReady();
};

class VtstKeyPage1 : public VtstMSAppBasePage
{
    VFX_DECLARE_CLASS(VtstKeyPage1);
protected:
    virtual void onInit()
    {
        VtstMSAppBasePage::onInit();
        setColor(VFX_COLOR_AQUA);

        initTitlebar(VFX_WSTR("End key"));
        initToolbar(IMG_GLOBAL_L7);
        addFunc(VFX_WSTR("Mode 1"), 10);
        addFunc(VFX_WSTR("Mode 2"), 11);
        addFunc(VFX_WSTR("Mode 3"), 12);
        addFunc(VFX_WSTR("Mode 4"), 13);
        
        addFunc(VFX_WSTR("exit"), 20);
        addFunc(VFX_WSTR("hide"), 21);

        VtstKeyApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VtstKeyApp);
        VFX_DEV_ASSERT(app);
        
        addSwitch(VFX_WSTR("A:allowDel"), 30, 31, app->getAllowDelete());
        addSwitch(VFX_WSTR("S:allowDel"), 32, 33, getMainScr()->getAllowDelete());
        addSwitch(VFX_WSTR("P:allowDel"), 34, 35, getAllowDelete());
        
        onFunc(10);
    }

    virtual void onFunc(VfxId funcId)
    {
        VtstKeyApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VtstKeyApp);
        VFX_DEV_ASSERT(app);

        switch(funcId)
        {
        case VtstMSAppBasePage::FUNC_ID_NEXT:
            break;
        case 10:
        case 11:
        case 12:
        case 13:
            {
                VfxWString hint;
                app->setMode(funcId - 10, hint);
                setHint(hint);
            }
            break;

        case 20:
            app->exit();
            break;
        case 21:
            app->setHidden(VFX_TRUE);
            break;

        case 30:
        case 31:
            app->setAllowDelete(funcId == 30 ? VFX_TRUE : VFX_FALSE);
            break;

        case 32:
        case 33:
            getMainScr()->setAllowDelete(funcId == 32 ? VFX_TRUE : VFX_FALSE);
            break;

        case 34:
        case 35:
            setAllowDelete(funcId == 34 ? VFX_TRUE : VFX_FALSE);
            break;
        }
    }
};

VFX_IMPLEMENT_CLASS("VtstKeyPage1", VtstKeyPage1, VtstMSAppBasePage);

VFX_IMPLEMENT_CLASS("VtstKeyScr", VtstKeyScr, VfxMainScr);

void VtstKeyScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VfxPage *page;
    VFX_OBJ_CREATE(page, VtstKeyPage1, this);
    pushPage(0, page);
}

VFX_IMPLEMENT_CLASS("VtstKeyApp", VtstKeyApp, VtstRtApp);

void VtstKeyApp::onRun(void* args, VfxU32 argSize)
{
    m_allowDelete = VFX_TRUE;
    
    VtstKeyScr *scr;
    VFX_OBJ_CREATE(scr, VtstKeyScr, this);
    scr->show();
}

VfxAppCloseAnswerEnum VtstKeyApp::onProcessClose(VfxAppCloseOption options)
{
    switch(m_mode)
    {
    case 0:
        return VFX_APP_CLOSE_ANSWER_YES;
    case 1:
        return VFX_APP_CLOSE_ANSWER_NO;
    case 2:
        {
            VfxTimer *timer;
            VFX_OBJ_CREATE(timer, VfxTimer, this);
            timer->m_signalTick.connect(this, &VtstKeyApp::onStop);
            timer->setStartDelay(3000);
            timer->start();
            
            return VFX_APP_CLOSE_ANSWER_LATER;
        }
    case 3:
        return VFX_APP_CLOSE_ANSWER_BG;

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
#endif
    }

    return VtstRtApp::onProcessClose(options);
}

void VtstKeyApp::setMode(VfxS32 mode, VfxWString &hint)
{
    switch(mode)
    {
    case 0: hint = VFX_WSTR("Yes");             break;
    case 1: hint = VFX_WSTR("No");              break;
    case 2: hint = VFX_WSTR("Async dead");      break;
    case 3: hint = VFX_WSTR("BG");              break;
    default:
        return;
    }
    m_mode = mode;
}

void VtstKeyApp::setAllowDelete(VfxBool flag)
{
    m_allowDelete = flag;
}

VfxBool VtstKeyApp::getAllowDelete()
{
    return m_allowDelete;
}

void VtstKeyApp::onConfirmPopup(VfxObject *obj, VfxId ansId)
{
    switch(ansId)
    {
    case VCP_CONFIRM_POPUP_BUTTON_YES:
        // do something
        continueClose();
        break;

    case VCP_CONFIRM_POPUP_BUTTON_NO:
        continueClose(VFX_APP_CLOSE_ANSWER_NO);
        break;
    }
}

void VtstKeyApp::onStop(VfxTimer *timer)
{
    continueClose();
}

VtstTestResultEnum vtst_rt_venusfw_keys(VfxU32 param)
{
    VfxApp *app = VfxAppLauncher::findApp(APP1_BASE, VFX_OBJ_CLASS_INFO(VtstKeyApp), VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);
    if(app)
    {
        app->setHidden(VFX_FALSE);
    }
    else
    {
        VfxAppLauncher::launchWithAsmSize( 
            APP1_BASE, 
            VFX_OBJ_CLASS_INFO(VtstKeyApp),
            GRP_ID_ROOT, 1024 * 500);
    }
    return VTST_TR_OK;
}

