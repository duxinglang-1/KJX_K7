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
 *  vtst_navi_title_bar.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Venus test application. This file is in mmi_framework module.
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

#include "vtst_rt_main.h"
#include "vfx_datatype.h"
#include "vcp_navi_title_bar.h"
#include "vfx_app.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_main_scr.h"
#include "vfx_page.h"
#include "vfx_page_bar.h"
#include "vfx_string.h"
#include "vfx_basic_type.h"
#include "MMIDataType.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vrt_datatype.h"
#include "vcp_button.h"
#include "vfx_signal.h"
#include "vfx_primitive_frame.h"
#include "vfx_app_launcher.h"
#include "mmi_res_range_def.h"
#include "GlobalResDef.h"
#include "vfx_app_cat_scr.h"


/***************************************************************************** 
 * VcpTitleBar testbed
 *****************************************************************************/


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define DATA_U32(_d0)                   ((VfxU32)(_d0))
#define DATA_U16(_d0, _d1)              ((VfxU32)(_d0) + ((VfxU32)(_d1) << 16))
#define DATA_U8(_d0, _d1, _d2, _d3)     (((VfxU32)(_d0)) + ((VfxU32)(_d1) << 8) + ((VfxU32)(_d2) << 16) + ((VfxU32)(_d3) << 24))

/***************************************************************************** 
 * Class VtstTitleBarApp declaration
 *****************************************************************************/

class VtstTitleBarAppScr;

class VtstTitleBarApp : public VfxApp
{
    VFX_DECLARE_CLASS(VtstTitleBarApp);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
};


/***************************************************************************** 
 * Class VtstTitleBarAppScr declaration
 *****************************************************************************/

class VtstTitleBarAppScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VtstTitleBarAppScr);

// Override
protected:
    virtual void on1stReady();
};


/***************************************************************************** 
 * Class VtstTitleBarAppBasePage declaration
 *****************************************************************************/

class VtstTitleBarAppBasePage : public VfxPage
{
    VFX_DECLARE_CLASS(VtstTitleBarAppBasePage);
public:
    VtstTitleBarAppBasePage() {}

    VfxPageBar *initTitlebar(VfxWString &str);
    VfxPageBar *initToolbar(VfxResId id1, VfxResId id2 = 0, VfxResId id3 = 0);
    void setHint(const VfxWString &str);
    void addFunc(const VfxWString &str, VfxId id);

protected:
    virtual void onInit();
    virtual void onFunc(VfxId funcId) {}

    enum {
        FUNC_ID_PREV = 1,
        FUNC_ID_NEXT,
        FUNC_ID_END_OF_ENUM
    };
    void _onClicked(VfxObject *obj, VfxId id);
        
private:
    VfxPoint        m_nextPos;
    VfxS32          m_buttonHeight;
};



/***************************************************************************** 
 * Class VtstTitleBarPage declaration
 *****************************************************************************/

class VtstTitleBarPage : public VtstTitleBarAppBasePage
{
    VFX_DECLARE_CLASS(VtstTitleBarPage);

    // Constructor / Destructor
public:
    VtstTitleBarPage() {}

    S32 pageID;
    void initTitleBar();

// Override
protected:
    virtual void onInit();

    virtual void onFunc(VfxId funcId);

    virtual VfxScrRotateTypeEnum onQueryRotateEx(const VfxScreenRotateParam &param)
    {
        return param.rotateTo;
    }

// implementation
private:
    VcpTitleBar * m_titleBar;
};


/***************************************************************************** 
 * Class VtstTitleBarApp implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstTitleBarApp", VtstTitleBarApp, VfxApp);

void VtstTitleBarApp::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VtstTitleBarAppScr *scr;
    VFX_OBJ_CREATE(scr, VtstTitleBarAppScr, this);
    scr->show();
}

/***************************************************************************** 
 * Class VtstTitleBarAppScr implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstTitleBarAppScr", VtstTitleBarAppScr, VfxMainScr);

void VtstTitleBarAppScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VtstTitleBarPage *page;
    VFX_OBJ_CREATE(page, VtstTitleBarPage, this);
    page->pageID = 0;
    page->initTitleBar();
    pushPage(VFX_ID_NULL, page);
}


/***************************************************************************** 
 * Class VtstTitleBarAppBasePage implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstTitleBarAppBasePage", VtstTitleBarAppBasePage, VfxPage);

void VtstTitleBarAppBasePage::onInit()
{
    VfxPage::onInit();    

    setBgColor(VFX_COLOR_BLUE);

    VcpButton *button;
    VFX_OBJ_CREATE(button, VcpButton, this);
    m_buttonHeight = button->getSize().height;
    VFX_OBJ_CLOSE(button);
    m_nextPos.x = m_buttonHeight;
    m_nextPos.y = m_buttonHeight * 2;
}


void VtstTitleBarAppBasePage::addFunc(const VfxWString &str, VfxId id)
{
    VcpButton *button;
    VFX_OBJ_CREATE(button, VcpButton, this);
    button->setAnchor(0.5f, 0.5f);
    button->setPos(m_nextPos);
    button->setText(str);
    button->setIsAutoResized(VFX_TRUE);
    button->setId(id);
    button->m_signalClicked.connect(this, &VtstTitleBarAppBasePage::_onClicked);

    // move to next pos
    if(m_nextPos.x == m_buttonHeight)
        m_nextPos.x = m_buttonHeight + m_buttonHeight * 3;
    else
    {
        m_nextPos.x = m_buttonHeight;
        m_nextPos.y += m_buttonHeight + 10;
    }
}

void VtstTitleBarAppBasePage::_onClicked(VfxObject *obj, VfxId id)
{
    onFunc(id);
}


/***************************************************************************** 
 * Class VtstTitleBarPage implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstTitleBarPage", VtstTitleBarPage, VtstTitleBarAppBasePage);

void VtstTitleBarPage::onInit()
{
    VtstTitleBarAppBasePage::onInit();

    addFunc(VFX_WSTR("prev"), VtstTitleBarAppBasePage::FUNC_ID_PREV);
    addFunc(VFX_WSTR("next"), VtstTitleBarAppBasePage::FUNC_ID_NEXT);
    addFunc(VFX_WSTR("add str"), 200);
//    addFunc(VFX_WSTR("trans"), 202);
//    addFunc(VFX_WSTR("orient"), 203);
//    addFunc(VFX_WSTR("style"), 204);
    addFunc(VFX_WSTR("reset str"), 205);
}

void VtstTitleBarPage::initTitleBar()
{
    VfxWString title;
    title.format("Test Title %d,", pageID);
    VfxWString subtitle;
    subtitle.format("Test Subtitle %d,", pageID);

	VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    //m_titleBar->setTitleStyle(VCP_TITLE_BAR_STYLE_HAS_SUBTITLE);
    m_titleBar->setTitle(title);

    setTopBar(m_titleBar);
}

void VtstTitleBarPage:: onFunc(VfxId funcId)
{
    switch(funcId)
    {
        case VtstTitleBarAppBasePage::FUNC_ID_PREV:
            getMainScr()->popPage();
            break;
        case VtstTitleBarAppBasePage::FUNC_ID_NEXT:
            if (pageID >= 4)
                break;
            VtstTitleBarPage *page;
            VFX_OBJ_CREATE(page, VtstTitleBarPage, getMainScr());
            page->pageID = pageID + 1;
            page->initTitleBar();
            getMainScr()->pushPage(VFX_ID_NULL, page);
            break;
        case 200:
            {
                VfxWString title = m_titleBar->getTitle();
                title += VFX_WSTR("A");
                m_titleBar->setTitle(title);
                break;
            }
        case 202:
            //setTranslucent(!isTranslucent());
            m_titleBar->testSetTranslucent(!m_titleBar->testGetTranslucent());
            break;
        case 203:
            if (m_titleBar->testGetRotation() == VFX_SCR_ROTATE_TYPE_NORMAL)
                m_titleBar->testSetRotation(VFX_SCR_ROTATE_TYPE_90);
            else
                m_titleBar->testSetRotation(VFX_SCR_ROTATE_TYPE_NORMAL);
            break;
        case 204:
            m_titleBar->setTitleStyle(VCP_TITLE_BAR_STYLE_BASE);
            break;
        case 205:
            {
                m_titleBar->setTitle(VFX_WSTR("123"));
                break;
            }
        case 206:
            break;
        default:
            break;
    }
}



class VtstRtTitleBarAutoScr : public VtstRtScr
{
// Variable
public:
    
// Constructor / Destructor
public:
    VtstRtTitleBarAutoScr(): m_phaseCount(4)
    {
        for (int i = 0; i < 3; ++i)
        {
            m_titleBar[i] = NULL;
        }
        m_phaseCount = 1;
    }

    VfxS32 m_phaseCount;

// Override
protected:
    virtual void onInit();

    virtual int start() {
        if (m_phaseCount > 4)
            return 4;
        return m_phaseCount;
    }

    virtual VfxS32 phase(VfxS32 idx);

    void phase0();

    VfxS32 phase1();

    VfxS32 phase2();

    void commonPhaseInit();

private:
    VcpTitleBar * m_titleBar[3];

    VfxBool fuzzyEqual(VfxS32 left, VfxS32 right)
    {
        VfxS32 diff = left - right;
        const VfxS32 range = 1;
        if (diff >= -range && diff <= range)
            return VFX_TRUE;
        return VFX_FALSE;
    }
};

void VtstRtTitleBarAutoScr::onInit()
{
    VtstRtScr::onInit();
}

VfxS32 VtstRtTitleBarAutoScr::phase(VfxS32 idx)
{
    switch(m_phase)
    {
        case 0:
            phase0();
            return 0;
            
        case 1:
            return phase1();

        case 2:
            return phase2();

        default:
            break;
    }
    return 0;
}

void VtstRtTitleBarAutoScr::phase0()
{
    setTitle(VFX_WSTR("VcpTitleBar 0"));

//    VfxColor color0;
//    check(color0.value == 0, VFX_WSTR("Zero VfxColor #1"));
//    check(color0.getA() == 0, VFX_WSTR("Zero VfxColor #2"));

    VcpTitleBar * titleBar = NULL;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);

    // check default value
    check(titleBar->getTitleStyle() == VCP_TITLE_BAR_STYLE_BASE, 
        VFX_WSTR("VcpTitleBar default #2") );
    check(titleBar->getTitle() == VFX_WSTR("default title"), VFX_WSTR("VcpTitleBar default #3") );

    // basic set get
    VfxWString testTitle = VFX_WSTR("Test Title");
    titleBar->setTitle(testTitle);
    check(titleBar->getTitle() == testTitle, VFX_WSTR("VcpTitleBar get set #1") );

    // check background
    VfxSize size(240, 50);
    titleBar->setSize(size);
    titleBar->testForceUpdate();
    VfxImageFrame * background = titleBar->testGetBackground();
    check(background->getSize() == size,  VFX_WSTR("VcpTitleBar back ground #1") );

    // style base test
    titleBar->setTitleStyle(VCP_TITLE_BAR_STYLE_BASE);
    titleBar->testForceUpdate();
    // check background, title, subtitle, back button are properly created or not created
    check(titleBar->testGetBackground() != NULL,  VFX_WSTR("VcpTitleBar style base #1") );
    check(titleBar->testGetTitleControl() != NULL,  VFX_WSTR("VcpTitleBar style base #2") );

    // style empty test
    titleBar->setTitleStyle(VCP_TITLE_BAR_STYLE_EMPTY);
    titleBar->testForceUpdate();
    // check background, title, subtitle, back button are properly created or not created
    check(titleBar->testGetBackground() != NULL,  VFX_WSTR("VcpTitleBar style empty #1") );
    check(titleBar->testGetTitleControl() == NULL,  VFX_WSTR("VcpTitleBar style empty #2") );

    //check(VFX_FALSE, VFX_WSTR("VcpTitleBar intentional fail") );

    VFX_OBJ_CLOSE(titleBar);
}

void VtstRtTitleBarAutoScr::commonPhaseInit()
{
    // common setup
    for (int i = 0; i < 3; ++i)
    {
        VFX_OBJ_CLOSE(m_titleBar[i]);
        VFX_OBJ_CREATE(m_titleBar[i], VcpTitleBar, this);
        m_titleBar[i]->setSize(getSize().width, 50);
        m_titleBar[i]->setPos(0, 70 * i);
    }
}

VfxS32 VtstRtTitleBarAutoScr::phase1()
{
    // style base interactive test
    setTitle(VFX_WSTR("VcpTitleBar 1"));

    commonPhaseInit();
    for (int i = 0; i < 3; ++i)
    {
        m_titleBar[i]->setTitleStyle(VCP_TITLE_BAR_STYLE_BASE);
    }
    m_titleBar[1]->setTitle(VFX_WSTR("The quick brown fox jumps over the lazy dog"));
    m_titleBar[1]->testSetTranslucent(VFX_TRUE);

    m_titleBar[2]->setTitle(VFX_WSTR("012345678901234"));

    confirm(VFX_WSTR("looks OK?"));


    return -1;
}

VfxS32 VtstRtTitleBarAutoScr::phase2()
{
    // style empty interactive test
    setTitle(VFX_WSTR("VcpTitleBar 3"));

    commonPhaseInit();
    for (int i = 0; i < 3; ++i)
    {
        m_titleBar[i]->setTitleStyle(VCP_TITLE_BAR_STYLE_EMPTY);
    }

    m_titleBar[1]->testSetTranslucent(VFX_TRUE);

    confirm(VFX_WSTR("looks OK?"));

    return -1;
}


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

VtstTestResultEnum vtst_rt_title_bar(VfxU32 param)
{
    VFX_UNUSED(param);
    VfxAppLauncher::launchWithAsmSize( 
        APP1_BASE, 
        VFX_OBJ_CLASS_INFO(VtstTitleBarApp),
        GRP_ID_ROOT, 204800 * 1,
        NULL, 0);
   return VTST_TR_OK;
}

VtstTestResultEnum vtst_rt_title_bar_auto(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTitleBarAutoScr);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

