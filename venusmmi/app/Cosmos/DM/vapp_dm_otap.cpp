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
 *  Vapp_dm_otap.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Devise management otap
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#if defined(SYNCML_DM_SUPPORT) && defined(__CCA_SUPPORT__)

#include "vcp_include.h"
#include "vapp_dtcnt_gprot.h"
#include "vcp_global_popup.h"
#include "vcp_popup.h"
#include "vcp_form.h"
#include "vfx_app.h"
#include "vfx_app_launcher.h"
#include "vfx_app_scr.h"

#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"
#include "vcp_confirm_popup.h"

#include "vapp_cca_gprot.h"
#include "mmi_rp_srv_dm_def.h"
#include "mmi_rp_vapp_cca_def.h"
#include "mmi_rp_vapp_dm_def.h"
#include "mmi_rp_vcui_dm_otap_def.h"
#include "vapp_dm_otap.h"

extern "C" void vcui_dm_otap_create(void)
{
    MMI_ID cui_id;
    cui_id = VfxAppLauncher::createCui(
        VCUI_DM_OTAP,
        VFX_OBJ_CLASS_INFO(VcuiDmOtapCui),
        vapp_cca_get_parent_id(),
        NULL,
        0);
    VfxAppLauncher::runCui(cui_id);
}


VFX_IMPLEMENT_CLASS("VcuiDmOtapCui", VcuiDmOtapCui, VfxCui);
void VcuiDmOtapCui::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VappDmOtapMainScrn *mainScrn;
    VFX_OBJ_CREATE(mainScrn, VappDmOtapMainScrn, this);
    mainScrn->show();
}


VFX_IMPLEMENT_CLASS("VappDmOtapMainScrn", VappDmOtapMainScrn, VfxMainScr);
VappDmOtapMainScrn::VappDmOtapMainScrn() :
    m_rspSrv(VFX_FALSE)
{
}


VappDmOtapMainScrn::~VappDmOtapMainScrn()
{
    if (m_rspSrv == VFX_FALSE)
    {
        rspSrv(SRV_CCA_STATUS_ENDKEY_PRESSED);
    }
}


void VappDmOtapMainScrn::on1stReady(void)
{
    VappDmOtapProfInfoPage *page;
    VFX_OBJ_CREATE(page, VappDmOtapProfInfoPage, this);
    pushPage(0, page);
}


void VappDmOtapMainScrn::rspSrv(srv_cca_status_enum result)
{
    m_rspSrv = VFX_TRUE;
    srv_dm_otap_install_prof_app_rsp(result);
}


VFX_IMPLEMENT_CLASS("VappDmOtapProfInfoPage", VappDmOtapProfInfoPage, VfxPage);
void VappDmOtapProfInfoPage::onInit()
{
    VfxPage::onInit();

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(STR_ID_VAPP_CCA_INSTALL_SETTING);
    setTopBar(bar);

    VcpToolBar *m_toolBar;
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->m_signalButtonTap.connect(
        this, &VappDmOtapProfInfoPage::onToolBarClick);
    m_toolBar->addItem(
        'INST',
        STR_GLOBAL_INSTALL,
        IMG_ID_VAPP_CCA_INSTALL);
    m_toolBar->addItem(
        'SKIP',
        STR_ID_VAPP_CCA_SKIP,
        IMG_ID_VAPP_CCA_SKIP);
    setBottomBar(m_toolBar);

    VcpTextView *m_text;
    VFX_OBJ_CREATE(m_text, VcpTextView, this);

    m_text->setPos(LEFT_GAPS, TOP_GAPS);
    m_text->setSize(
        getSize().width - LEFT_GAPS - RIGHT_GAPS,
        getSize().height - TOP_GAPS - BOTTOM_GAPS);
    m_text->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_text->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
    composeProfInfo(m_text);
}


void VappDmOtapProfInfoPage::composeProfInfo(VcpTextView *text)
{
    WCHAR info1[512] = {0};
    WCHAR info2[512] = {0};
    S32 i = 0;
    S32 curr_valid_num = srv_dm_otap_get_curr_valid_prof_num();
    U8 curr_iter = srv_dm_otap_get_curr_prof_iter();
    U8 *server_id = srv_dm_otap_get_curr_prof_server_id();
    U8 *server_addr = srv_dm_otap_get_curr_prof_server_addr();
    WCHAR *showText;
    VFX_ALLOC_MEM(showText, 2000, this);

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    kal_wsprintf(
        info1,
        "%w\n%w%d/%d\n",
        (WCHAR*)GetString(STR_ID_VAPP_CCA_SYNCMLDM),
        (WCHAR*)GetString(STR_ID_DM_OTA_PROFILE),
        curr_valid_num,
        srv_dm_otap_get_valid_prof_num());

    kal_wsprintf(
        info2,
        "\n%w%s\n%w%s\n",
        GetString(STR_ID_DM_OTA_SERVERID),
        server_id,
        GetString(STR_ID_DM_OTA_SERVER_ADDRESS),
        server_addr);

    if (srv_dm_otap_check_curr_prof_is_to_udpate() == MMI_TRUE)
    {
        kal_wsprintf(
            showText,
            "%w%w\n%w",
            info1,
            GetString(STR_ID_VAPP_CCA_UPDATE_PROFILE),
            info2);
    }
    else
    {
        kal_wsprintf(
            showText,
            "%w%w",
            info1,
            info2);
    }
#else /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    kal_wsprintf(
        showText,
        "%w: %s\n\n%w%d/%d\n\n%w%s\n\n",
        GetString(STR_ID_VAPP_CCA_SYNCMLDM),
        server_id,
        GetString(STR_ID_DM_OTA_PROFILE),
        curr_valid_num,
        srv_dm_otap_get_valid_prof_num(),
        GetString(STR_ID_DM_OTA_SERVER_ADDRESS),
        server_addr);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */


    text->setText((const VfxWChar*)showText);

    VFX_FREE_MEM(showText);
}


void VappDmOtapProfInfoPage::onToolBarClick(VfxObject *obj, VfxId id)
{
    switch(id)
    {
        case 'INST':
        {
            ((VappDmOtapMainScrn*)getMainScr())->rspSrv(SRV_CCA_STATUS_OK);
            getApp()->exit();
            break;
        }

        case 'SKIP':
        {
            ((VappDmOtapMainScrn*)getMainScr())->rspSrv(SRV_CCA_STATUS_SETTING_SKIPPED);
            getApp()->exit();
            break;
        }

        default:
            break;
    }
}



VfxBool VappDmOtapProfInfoPage::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_BACK &&
        event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        ((VappDmOtapMainScrn*)getMainScr())->rspSrv(SRV_CCA_STATUS_SETTING_SKIPPED);
        return VFX_TRUE;
    }
    else if (event.keyCode == VFX_KEY_CODE_HOME &&
        event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        ((VappDmOtapMainScrn*)getMainScr())->rspSrv(SRV_CCA_STATUS_ENDKEY_PRESSED);
        return VFX_TRUE;
    }
    return VfxPage::onKeyInput(event);
}
#endif /* defined(SYNCML_DM_SUPPORT) && defined(__CCA_SUPPORT__) */

