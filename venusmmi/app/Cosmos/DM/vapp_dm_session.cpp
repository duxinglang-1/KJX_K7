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
 *  Vapp_dm_session.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Device management session cosmos UI.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef SYNCML_DM_SUPPORT

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_popup.h"
#include "vcp_form.h"
#include "vapp_dm_main.h"
#include "vapp_dm_session.h"
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

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

MMI_BOOL vappDmSessionNotificationNmgrHdlr(mmi_scenario_id scenarioId, void *arg)
{
    VfxAppLauncher::launch(
        VAPP_DM,
        VFX_OBJ_CLASS_INFO(VappDmSessionNotification),
        GRP_ID_ROOT,
        arg,
        sizeof(srv_dm_app_adp_evt_display_notification_struct));

    return MMI_TRUE;
}


MMI_BOOL vappDmSessionAlertNmgrHdlr(mmi_scenario_id scenarioId, void *arg)
{
    VfxAppLauncher::launch(
        VAPP_DM,
        VFX_OBJ_CLASS_INFO(VappDmSessionAlert),
        GRP_ID_ROOT,
        arg,
        sizeof(srv_dm_app_adp_evt_display_alert_struct));

    return MMI_TRUE;
}


void vappDmSessiondisplayEndingMsg(srv_dm_app_adp_session_ending_msg_enum endingMsg)
{
    switch (endingMsg)
    {
        case SRV_DM_APP_ADP_SESSION_ENDING_MSG_NONE:
            break;

        case SRV_DM_APP_ADP_SESSION_ENDING_MSG_SESSION_FAIL:
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
                (WCHAR*)GetString(STR_ID_DMUI_SESSION_FAILURE));
            break;
        }

        case SRV_DM_APP_ADP_SESSION_ENDING_MSG_NO_MEM:
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
                (WCHAR*)GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY));
            break;
        }

        case SRV_DM_APP_ADP_SESSION_ENDING_MSG_TIMEOUT:
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
                (WCHAR*)GetString(STR_ID_DMUI_TIMEOUT_POPUP));
            break;
        }

        default:
            break;
    }
}


VFX_IMPLEMENT_CLASS("VappDmSessionNotification", VappDmSessionNotification, VfxApp);
void VappDmSessionNotification::onRun(void * args,VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    srv_dm_app_adp_evt_display_notification_struct *notification =
        (srv_dm_app_adp_evt_display_notification_struct*)args;
    m_uiMode = notification->ui_mode;

    VappDmEvtHdlr::getInstance()->m_dmSessionFinish.connect(
        this,
        &VappDmSessionNotification::sessionFinishHdlr);

    VappDmSessionNotificationMainScrn *mainScrn;
    VFX_OBJ_CREATE(mainScrn, VappDmSessionNotificationMainScrn, this);
    mainScrn->show();
}


void VappDmSessionNotification::sessionFinishHdlr()
{
    exit();
}


dm_ui_mode_enum VappDmSessionNotification::getUiMode()
{
    return m_uiMode;
}


VFX_IMPLEMENT_CLASS("VappDmSessionNotificationMainScrn", VappDmSessionNotificationMainScrn, VfxAppScr);
VappDmSessionNotificationMainScrn::VappDmSessionNotificationMainScrn() :
    m_rspSrv(VFX_FALSE)
{
    setIsSmallScreen();
}


VappDmSessionNotificationMainScrn::~VappDmSessionNotificationMainScrn()
{
    if (m_rspSrv == VFX_FALSE)
    {
        rspSrv(DM_UI_INTERACTION_ACTION_DEFER);
    }
}


void VappDmSessionNotificationMainScrn::onInit()
{
    VfxAppScr::onInit();

    VappDmSessionNotification *app = (VappDmSessionNotification*)getApp();

    switch (app->getUiMode())
    {
        case DM_UI_MODE_INFORMATION:
        {
            displayInfo();
            break;
        }

        case DM_UI_MODE_USERINTERACTION:
        {
            displayCnf();
            break;
        }

        default:
            MMI_ASSERT(0);
    }
}


void VappDmSessionNotificationMainScrn::displayInfo()
{
    m_rspSrv = VFX_TRUE;
    VcpConfirmPopup *cnfPopup;
    VFX_OBJ_CREATE(cnfPopup, VcpConfirmPopup, this);
    cnfPopup->setInfoType(VCP_POPUP_TYPE_INFO);
    cnfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    cnfPopup->setText(STR_ID_DM_SESSION_NOTIFICATION_INFO);
    cnfPopup->setAutoDestory(VFX_TRUE);
    cnfPopup->m_signalButtonClicked.connect(this, &VappDmSessionNotificationMainScrn::infoScrnBtnHdlr);
    cnfPopup->show(VFX_TRUE);

    VfxTimer *timer;
    VFX_OBJ_CREATE(timer, VfxTimer, this);
    timer->setStartDelay(SRV_DM_TIME_NOTIFICATION_INFO_DISPLAY_DUR);
    timer->m_signalTick.connect(this, &VappDmSessionNotificationMainScrn::infoTimeoutHdlr);
    timer->start();
}


void VappDmSessionNotificationMainScrn::infoScrnBtnHdlr(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_OK: // OK
        {
            exit();
            break;
        }

        default:
            break;
    }
}


void VappDmSessionNotificationMainScrn::infoTimeoutHdlr(VfxTimer *obj)
{
    exit();
}


void VappDmSessionNotificationMainScrn::displayCnf()
{
    VcpConfirmPopup *cnfPopup;
    VFX_OBJ_CREATE(cnfPopup, VcpConfirmPopup, this);

    cnfPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    cnfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);   
    cnfPopup->setText(STR_ID_DM_SESSION_NOTIFICATION_USER_INTERACTION);
    cnfPopup->setCustomButton(
        STR_GLOBAL_CONFIRM,
        STR_GLOBAL_CANCEL,
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        VCP_POPUP_BUTTON_TYPE_CANCEL);
    cnfPopup->m_signalButtonClicked.connect(this, &VappDmSessionNotificationMainScrn::cnfScrnBtnHdlr);
    cnfPopup->show(VFX_TRUE);
    VfxTimer *timer;
    VFX_OBJ_CREATE(timer, VfxTimer, this);
    timer->setStartDelay(SRV_DM_TIME_NOTIFICATION_CNF_USER_INTERACTION);
    timer->m_signalTick.connect(this, &VappDmSessionNotificationMainScrn::cnfTimeoutHdlr);
    timer->start();
}


void VappDmSessionNotificationMainScrn::cnfScrnBtnHdlr(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1: // Confirm
        {
            rspSrv(DM_UI_INTERACTION_ACTION_ACCEPT);
            exit();
            break;
        }

        case VCP_CONFIRM_POPUP_BUTTON_USER_2: // Cancel
        {
            rspSrv(DM_UI_INTERACTION_ACTION_CANCEL);
            exit();
            break;
        }

        default:
            break;
    }
}


void VappDmSessionNotificationMainScrn::cnfTimeoutHdlr(VfxTimer *obj)
{
    exit();
    rspSrv(DM_UI_INTERACTION_ACTION_CANCEL);
}


void VappDmSessionNotificationMainScrn::rspSrv(dm_ui_interaction_enum result)
{
    m_rspSrv = VFX_TRUE;
    srv_dm_session_notification_app_rsp(result);
}


VFX_IMPLEMENT_CLASS("VappDmSessionAlert", VappDmSessionAlert, VfxApp);
void VappDmSessionAlert::onRun(void * args,VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);
    m_alert = ((srv_dm_app_adp_evt_display_alert_struct*)args)->alert;
    VappDmEvtHdlr::getInstance()->m_dmSessionFinish.connect(
        this,
        &VappDmSessionAlert::sessionFinishHdlr);

    VappDmSessionAlertMainScrn *mainScrn;
    VFX_OBJ_CREATE(mainScrn, VappDmSessionAlertMainScrn, this);
    mainScrn->show();
}


void VappDmSessionAlert::sessionFinishHdlr()
{
    exit();
}


dm_alert_struct *VappDmSessionAlert::getAlertPtr()
{
    return m_alert;
}


VFX_IMPLEMENT_CLASS("VappDmSessionAlertMainScrn", VappDmSessionAlertMainScrn, VfxMainScr);
VappDmSessionAlertMainScrn::VappDmSessionAlertMainScrn() :
    m_rspSrv(VFX_FALSE)
{
}


VappDmSessionAlertMainScrn::~VappDmSessionAlertMainScrn()
{
    if (m_rspSrv == VFX_FALSE)
    {
        dm_alert_rsp_struct alert_rsp;
        alert_rsp.ui_interaction = DM_UI_INTERACTION_ACTION_DEFER;
        rspSrv(&alert_rsp);
    }
}


void VappDmSessionAlertMainScrn::on1stReady()
{
    VfxMainScr::on1stReady();
    VappDmSessionAlert *app = (VappDmSessionAlert*)getApp();

    switch (app->getAlertPtr()->alert_type)
    {
        case DM_UI_INTERACTION_DISPLAY:
        {
            VappDmSessionAlertInfoPage *alertInfoPage;
            VFX_OBJ_CREATE(alertInfoPage, VappDmSessionAlertInfoPage, this);
            pushPage(0, alertInfoPage);
            break;
        }

        case DM_UI_INTERACTION_CONFIRM:
        {
            VappDmSessionAlertCnfPage *alertCnfPage;
            VFX_OBJ_CREATE(alertCnfPage, VappDmSessionAlertCnfPage, this);
            pushPage(0, alertCnfPage);
            break;
        }

        default:
            MMI_ASSERT(0);
    }
}


void VappDmSessionAlertMainScrn::rspSrv(dm_alert_rsp_struct *alertRsp)
{
    m_rspSrv = VFX_TRUE;
    srv_dm_session_alert_app_rsp(alertRsp);
}


VFX_IMPLEMENT_CLASS("VappDmSessionAlertInfoPage", VappDmSessionAlertInfoPage, VfxPage);
void VappDmSessionAlertInfoPage::onInit()
{
    VfxPage::onInit();
    
    setStatusBar(VFX_TRUE);

    VfxTextFrame *textFrame;
    VFX_OBJ_CREATE(textFrame, VfxTextFrame, this);
    VfxWChar *alertStr = srv_dm_session_alert_get_display_str_ptr();
    textFrame->setString(alertStr);
    textFrame->setPos(0, 0);
    textFrame->setSize(getSize());
    textFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    textFrame->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_NONE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_NONE);
    textFrame->setColor(CLR_COSMOS_TEXT_MAIN);

    VcpToolBar *toolBar;
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    toolBar->addItem(0, VCP_STR_TOOL_BAR_EXIT, VCP_IMG_TOOL_BAR_COMMON_ITEM_EXIT);
    toolBar->m_signalButtonTap.connect(this, &VappDmSessionAlertInfoPage::toolbarEventHdlr);
    setBottomBar(toolBar);

    VfxU32 duration;
    if (MMI_FALSE == srv_dm_session_alert_get_option_val(
                        DM_ALERT_MINDT_MASK,
                        &duration))
    {
        duration = SRV_DM_TIME_ALERT_DEFAULT_MINDT;
    }

    VfxTimer *timer;
    VFX_OBJ_CREATE(timer, VfxTimer, this);
    timer->setStartDelay(duration);
    timer->m_signalTick.connect(this, &VappDmSessionAlertInfoPage::displayTimeoutHdlr);
    timer->start();
}


void VappDmSessionAlertInfoPage::toolbarEventHdlr(VfxObject* obj, VfxId itemId)
{
    switch (itemId)
    {
        case 0:
        {
            exit();
            break;
        }

        default:
            break;
    }
}


void VappDmSessionAlertInfoPage::displayTimeoutHdlr(VfxTimer *obj)
{
    exit();
}


VFX_IMPLEMENT_CLASS("VappDmSessionAlertCnfPage", VappDmSessionAlertCnfPage, VfxPage);
void VappDmSessionAlertCnfPage::onInit()
{
    VfxPage::onInit();

    setStatusBar(VFX_TRUE);

    VfxTextFrame *textFrame;
    VFX_OBJ_CREATE(textFrame, VfxTextFrame, this);
    VfxWChar *alertStr = srv_dm_session_alert_get_display_str_ptr();
    textFrame->setString(alertStr);
    textFrame->setPos(0, 0);
    textFrame->setSize(getSize());
    textFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    textFrame->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_NONE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_NONE);
    textFrame->setColor(CLR_COSMOS_TEXT_MAIN);

    VcpToolBar *toolBar;
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    toolBar->addItem(TOOLBAR_ITEM_OK, VCP_STR_TOOL_BAR_OK, VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    toolBar->addItem(TOOLBAR_ITEM_CANCEL, VCP_STR_TOOL_BAR_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    toolBar->m_signalButtonTap.connect(this, &VappDmSessionAlertCnfPage::toolbarEventHdlr);
    setBottomBar(toolBar);

    VfxU32 duration;
    srv_dm_session_alert_get_option_val(DM_ALERT_MAXDT_MASK, &duration);
    VfxTimer *timer;
        VFX_OBJ_CREATE(timer, VfxTimer, this);
        timer->setStartDelay(duration);
        timer->m_signalTick.connect(this, &VappDmSessionAlertCnfPage::cnfTimeoutHdlr);
        timer->start();
}


void VappDmSessionAlertCnfPage::toolbarEventHdlr(VfxObject* obj, VfxId itemId)
{
    dm_alert_rsp_struct alert_rsp;
    VappDmSessionAlertMainScrn *mainScrn = (VappDmSessionAlertMainScrn*)getMainScr();

    switch (itemId)
    {
        case TOOLBAR_ITEM_OK:
        {
            alert_rsp.ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;
            mainScrn->rspSrv(&alert_rsp);
            exit();
            break;
        }

        case TOOLBAR_ITEM_CANCEL:
        {
            alert_rsp.ui_interaction = DM_UI_INTERACTION_ACTION_CANCEL;
            mainScrn->rspSrv(&alert_rsp);
            exit();
            break;
        }

        default:
            break;
    }
}


void VappDmSessionAlertCnfPage::cnfTimeoutHdlr(VfxTimer *obj)
{
    exit();
    VappDmSessionAlertMainScrn *mainScrn = (VappDmSessionAlertMainScrn*)getMainScr();
    dm_alert_rsp_struct alert_rsp;
    alert_rsp.ui_interaction = DM_UI_INTERACTION_ACTION_CANCEL;
    mainScrn->rspSrv(&alert_rsp);
}

#endif /* SYNCML_DM_SUPPORT */
