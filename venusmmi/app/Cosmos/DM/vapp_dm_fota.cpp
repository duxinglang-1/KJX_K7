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
 *  Vapp_dm_fota.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Device management FOTA cosmos UI.
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __DM_FOTA_SUPPORT__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_popup.h"
#include "vcp_form.h"
#include "vapp_dm_fota.h"
#include "vcp_global_popup.h"
extern "C"
{
#include "GlobalResDef.h"
#include "mmi_rp_srv_dm_def.h"
#include "mmi_rp_vapp_dm_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "DmSrvIprot.h"
}

/***************************************************************************** 
 * Static Variable
 *****************************************************************************/
static const VfxU32 deferTimerList[] = {1, 2, 4, 24};

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

MMI_BOOL vappDmFotaUpdateHdlr(mmi_scenario_id scenarioId, void *arg)
{
    VfxAppLauncher::launch(
        VAPP_DM,
        VFX_OBJ_CLASS_INFO(VappDmFotaUpdate),
        GRP_ID_ROOT,
        arg,
        sizeof(srv_dm_app_adp_evt_fota_display_update_struct));

    return MMI_TRUE;
}

VFX_IMPLEMENT_CLASS("VappDmFotaUpdate", VappDmFotaUpdate, VfxApp);
void VappDmFotaUpdate::onRun(void * args,VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VappDmFotaUpdateMainScrn *mainScrn;
    VFX_OBJ_CREATE(mainScrn, VappDmFotaUpdateMainScrn, this);
    mainScrn->show();
}


void VappDmFotaUpdate::onDeinit()
{
    mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGHEST_SCRN);
}


VFX_IMPLEMENT_CLASS("VappDmFotaUpdateMainScrn", VappDmFotaUpdateMainScrn, VfxMainScr);
VappDmFotaUpdateMainScrn::VappDmFotaUpdateMainScrn() :
    m_rspSrv(VFX_FALSE)
{
}


VappDmFotaUpdateMainScrn::~VappDmFotaUpdateMainScrn()
{
    if (m_rspSrv == VFX_FALSE)
    {
        rspSrv(DM_UI_INTERACTION_ACTION_DEFER, SRV_DM_TIME_USER_INTERACTION_DEFER);
    }
}


void VappDmFotaUpdateMainScrn::on1stReady()
{
    VfxMainScr::on1stReady();
    VappDmFotaUpdatePage *LockPage;
    VFX_OBJ_CREATE(LockPage, VappDmFotaUpdatePage, this);
    pushPage(0, LockPage);
}


void VappDmFotaUpdateMainScrn::rspSrv(dm_ui_interaction_enum result, U32 defer_time)
{
    m_rspSrv = VFX_TRUE;
    srv_dm_fota_update_app_rsp(result, defer_time);
}

VFX_IMPLEMENT_CLASS("VappDmFotaUpdatePage", VappDmFotaUpdatePage, VfxPage);
void VappDmFotaUpdatePage::onInit()
{
    VfxPage::onInit();

    VfxTextFrame *textFrame;
    VFX_OBJ_CREATE(textFrame, VfxTextFrame, this);
    const VfxS32 xGap = 10;
    const VfxS32 yGap = 10;
    textFrame->setMargins(xGap, yGap, xGap, yGap);
    textFrame->setString(STR_ID_DMUI_NOTIF_UPDATE_REBOOT);
    textFrame->setPos(0, 0);
    textFrame->setSize(getSize());
    textFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    textFrame->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    textFrame->setColor(CLR_COSMOS_TEXT_MAIN);

    VcpToolBar *toolBar;
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    toolBar->addItem(0, STR_GLOBAL_UPDATE, VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    toolBar->addItem(1, STR_ID_DMUI_NOTIF_UPDATE_DEFER, VCP_IMG_TOOL_BAR_COMMON_ITEM_FORWARD);
    toolBar->m_signalButtonTap.connect(this, &VappDmFotaUpdatePage::toolbarEventHdlr);
    setBottomBar(toolBar);
}


void VappDmFotaUpdatePage::toolbarEventHdlr(VfxObject* obj, VfxId itemId)
{
    switch (itemId)
    {
        case 0:
        {
            VappDmFotaUpdateMainScrn *mainScrn = (VappDmFotaUpdateMainScrn*)getMainScr();
            mainScrn->rspSrv(DM_UI_INTERACTION_ACTION_ACCEPT, 0);

            exit();
            break;
        }

        case 1:
        {
            showDeferMenuPopup();
            break;
        }

        default:
            break;
    }
}


void VappDmFotaUpdatePage::showDeferMenuPopup()
{
    VcpMenuPopup *menuPopup;
    VFX_OBJ_CREATE(menuPopup, VcpMenuPopup, this);
    menuPopup->setAutoDestory(VFX_TRUE);
    menuPopup->setTitle(STR_ID_DM_FOTA_UPDATE_DEFER_TITLE);
    menuPopup->showMenu();

    for (VfxU32 i = 0; i < sizeof(deferTimerList)/sizeof(deferTimerList[0]); i++)
    {
        WCHAR timeWStr[10];
        mmi_wcs_itow(deferTimerList[i], timeWStr, 10);
        menuPopup->addItem(i, timeWStr);
    }

    menuPopup->m_signalMenuCallback.connect(this, &VappDmFotaUpdatePage::onMenuCallack);
    menuPopup->showMenu();
}


void VappDmFotaUpdatePage::onMenuCallack(
    VcpMenuPopup* menu,
    VcpMenuPopupEventEnum evt,
    VcpMenuPopupItem *item)
{
    if (evt == VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
    {
        VfxS32 index = item->getId();
        VfxU32 time = deferTimerList[index] * 3600 * 1000;
        VappDmFotaUpdateMainScrn *mainScrn = (VappDmFotaUpdateMainScrn*)getMainScr();
        mainScrn->rspSrv(DM_UI_INTERACTION_ACTION_DEFER, time);
        exit();
    }
}

#endif /* __DM_FOTA_SUPPORT__ */
