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
 *  vapp_helloworld.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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

#include "MMI_features.h" 
#include "vapp_helloworld.h"
#include "mmi_rp_vapp_helloworld_def.h"
#ifdef __AFX_RT_TEST__
#include "vtst_rt_main.h"
#endif
#include "../xml/vfx_xml_loader.h"
#include "vcp_include.h"
extern "C"
{
#include "GlobalResDef.h"   
}

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

extern "C" void vapp_hello_world_launch(void)
{
    VfxAppLauncher::launch( 
        VAPP_HELLOWORLD,
        VFX_OBJ_CLASS_INFO(VappHelloWorldApp),
        GRP_ID_ROOT);
}

VFX_IMPLEMENT_CLASS("VappHelloWorldApp", VappHelloWorldApp, VfxApp);

void VappHelloWorldApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VappHelloWorldScreen *scr;
    VFX_OBJ_CREATE(scr, VappHelloWorldScreen, this);
    scr->show();
}

mmi_ret VappHelloWorldApp::onProc(mmi_event_struct *evt)
{
    return VfxApp::onProc(evt);
}

VFX_IMPLEMENT_CLASS("VappHelloWorldScreen", VappHelloWorldScreen, VfxMainScr);

void VappHelloWorldScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    // create and display first page
    VappHelloWorldPage *page;
    VFX_OBJ_CREATE(page, VappHelloWorldPage, this);
    pushPage(0, page);
}

VFX_IMPLEMENT_CLASS("VappHelloWorldPage", VappHelloWorldPage, VfxPage);

VappHelloWorldPage::VappHelloWorldPage():
    m_cuiId(0)
{
}

void VappHelloWorldPage::onInit()
{
    VfxPage::onInit(); // call base class

#if 0
/* under construction !*/
/* under construction !*/
#else
    VcpTitleBar *tbar;
    VFX_OBJ_CREATE(tbar, VcpTitleBar, this);
    tbar->setTitle(VFX_WSTR("Title"));
    setTopBar(tbar);

    VcpToolBar *bbar;
    VFX_OBJ_CREATE(bbar, VcpToolBar, this);
    bbar->addItem(1, VFX_WSTR_NULL, IMG_GLOBAL_L1);
    bbar->addItem(2, VFX_WSTR_NULL, IMG_GLOBAL_L2);
    setBottomBar(bbar);

    // create a frame
    VfxFrame *f;
    VFX_OBJ_CREATE(f, VfxFrame, this);
    f->setBgColor(VFX_COLOR_BLUE);

    // position it according to current size
    VfxSize size = getSize();
    size.width -= 20;
    size.height -= 20;
    f->setPos(10, 10);
    f->setSize(size);

    // align it!
    f->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

    // create a Button
    VcpButton *button;
    VFX_OBJ_CREATE(button, VcpButton, this);
    button->setPos(10, 10);
    button->setText(VFX_WSTR("Create CUI"));
    button->setIsAutoResized(VFX_TRUE);
    button->m_signalClicked.connect(this, &VappHelloWorldPage::onBtnClicked);
#endif
}

mmi_ret VappHelloWorldPage::onProc(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
    case EVT_ID_CUI_HELLOWORLD_RESULT:
        {
            cui_helloworld_result_event_struct *result = (cui_helloworld_result_event_struct*)evt;

            VcpConfirmPopup *popup;
            VFX_OBJ_CREATE(popup, VcpConfirmPopup, this);
            popup->setInfoType(VCP_POPUP_TYPE_INFO);
            VfxWString text;
            text.loadFromMem(result->buffer);
            popup->setText(text);
            popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
            popup->show(VFX_TRUE);

            VFX_DEV_ASSERT(m_cuiId == result->sender_id);
            cui_helloworld_close(result->sender_id);
            m_cuiId = 0;
        }
        return MMI_RET_OK;
    }
    return VfxPage::onProc(evt);
}

void VappHelloWorldPage::onBtnClicked(VfxObject *obj, VfxId id)
{
    m_cuiId = cui_helloworld_create(getApp()->getGroupId());
    vfxSetCuiCallerScr(m_cuiId, getMainScr());
    cui_helloworld_run(m_cuiId);
    cui_helloworld_set_content(m_cuiId, (WCHAR*)L"Cosmos");
}


VFX_IMPLEMENT_CLASS("VcuiHelloWorldCui", VcuiHelloWorldCui, VfxCui);

void VcuiHelloWorldCui::onRun(void * args, VfxU32 argSize)
{
    VfxCui::onRun(args, argSize);

    // create and display main screen
    VcuiHelloWorldScreen *scr;
    VFX_OBJ_CREATE(scr, VcuiHelloWorldScreen, this);
    scr->show();
}

void VcuiHelloWorldCui::setContent(const VfxWString &value)
{
    m_content = value;

    if(isRunning())
    {
        // update UI
        VfxMainScr *scr = VFX_OBJ_DYNAMIC_CAST(getTopScreen(), VfxMainScr);
        VcuiHelloWorldPage *p = VFX_OBJ_DYNAMIC_CAST(scr->getPage(), VcuiHelloWorldPage);
        if(p)
        {
            p->updateUI();
        }
    }
}

VFX_IMPLEMENT_CLASS("VcuiHelloWorldScreen", VcuiHelloWorldScreen, VfxMainScr);

void VcuiHelloWorldScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    // create and display first page
    VcuiHelloWorldPage *page;
    VFX_OBJ_CREATE(page, VcuiHelloWorldPage, this);
    pushPage(0, page);
}


VFX_IMPLEMENT_CLASS("VcuiHelloWorldPage", VcuiHelloWorldPage, VfxPage);

void VcuiHelloWorldPage::onInit()
{
    VfxPage::onInit(); // call base class

    VcpTitleBar *tbar;
    VFX_OBJ_CREATE(tbar, VcpTitleBar, this);
    tbar->setTitle(VFX_WSTR("Helloworld CUI"));
    setTopBar(tbar);

    // create a frame
    VfxFrame *f;
    VFX_OBJ_CREATE(f, VfxFrame, this);
    f->setBgColor(VFX_COLOR_RED);

    // position it according to current size
    VfxSize size = getSize();
    size.width -= 20;
    size.height -= 20;
    f->setPos(10, 10);
    f->setSize(size);

    // align it!
    f->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

    // text frame
    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);
    m_textFrame->setPos(10, 100);
    VcuiHelloWorldCui *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiHelloWorldCui);
    m_textFrame->setString(cui->getContent());

    // create a button to send back parent event
    VcpButton *button;
    VFX_OBJ_CREATE(button, VcpButton, this);
    button->setPos(10, 10);
    button->setText(VFX_WSTR("Notify parent result"));
    button->setIsAutoResized(VFX_TRUE);
    button->m_signalClicked.connect(this, &VcuiHelloWorldPage::onBtnClicked);
}

void VcuiHelloWorldPage::onBtnClicked(VfxObject *obj, VfxId id)
{
    cui_helloworld_result_event_struct evt;

    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_HELLOWORLD_RESULT, getApp()->getGroupId());

    VfxWString text(VFX_WSTR("Hello!"));
    mmi_wcscpy(evt.buffer, text.getBuf());

    VfxCui *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VfxCui);
    app->postToCaller((mmi_group_event_struct*)&evt);
}

void VcuiHelloWorldPage::updateUI()
{
    VcuiHelloWorldCui *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiHelloWorldCui);
    m_textFrame->setString(cui->getContent());
}

extern "C"
{
mmi_id cui_helloworld_create(mmi_id parent_id)
{
    mmi_id cui_id = VfxAppLauncher::createCui(
                                        VCUI_HELLOWORLD,
                                        VFX_OBJ_CLASS_INFO(VcuiHelloWorldCui),
                                        parent_id,
                                        NULL,
                                        0);
    return cui_id;
}

void cui_helloworld_run(mmi_id cui_id)
{
    VfxAppLauncher::runCui(cui_id);
}

void cui_helloworld_close(mmi_id cui_id)
{
    VfxAppLauncher::terminate(cui_id);
}

void cui_helloworld_set_content(mmi_id cui_id, const WCHAR *content)
{
    VcuiHelloWorldCui *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VcuiHelloWorldCui);
    VfxWString value;
    value.loadFromMem(content);
    cui->setContent(value);
}

}

#ifdef __AFX_RT_TEST__
VtstTestResultEnum vtst_rt_vapp_helloworld(VfxU32 param)
{
    vapp_hello_world_launch();
    return VTST_TR_OK;
}
#endif
