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
 *  vapp_cbm_wlan_prefer.cpp
 *
 * Project:
 * --------
 *  COSMOS CBM WLAN Prefer
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __TCPIP__
#include "MMI_features.h"
#ifdef __MMI_WLAN_FEATURES__

extern "C" {
#include "CbmSrvGprot.h"
#include "CbmSrvIprot.h"

#include "MMIDataType.h"
#include "mmi_rp_vapp_cbm_def.h"

#include "DtcntSrvIprot.h"
#include "DtcntSrvGprot.h"
#include "DataLockSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGProt.h"

#ifdef __MMI_TETHERING_WIFI__
#include "TetheringSrvGprot.h"
#endif

#include "mmi_frm_utility_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "NotificationGprot.h"

#include "UcmSrvGprot.h"
}


#include "vapp_cbm_wlan_prefer.h"
#include "vcui_dtcnt_wlan_gprot.h"
#include "vapp_ncenter.h"
#include "vapp_screen_lock_gprot.h"
#if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
#include "vapp_ncenter_gprot.h"
#endif

#define VAPP_CBM_CONFIRM_POPUP_BACK     'BKEY'

typedef struct
{
    srv_cbm_wlan_query_evt_struct *wlanQueryEvt;
    VfxBool isWaitingScan;
    VfxBool auto_conn;
    VfxBool need_notify;
} vappCbmCntxStruct;

static vappCbmCntxStruct gVappCbmCntx;
static vappCbmCntxStruct *gVappCbmCntxPtr = NULL;
static VfxBool gVappCbmReentryDefered = VFX_FALSE;

static void vapp_cbm_wlan_scan_callback(
                U32 job_id,
                void *userData,
                srv_dtcnt_wlan_scan_result_struct *scanRes);
static VfxS32 vapp_cbm_is_wlan_query_needed(
                srv_cbm_wlan_query_type_enum query_type,
                VfxU8 ap_num,
                VfxU32 *bearer_type);
static void vapp_cbm_fill_wlan_query_param(
                cbm_wlan_prefer_info_struct *param,
                srv_cbm_wlan_query_type_enum query_type,
                VfxU8 ap_num);


VFX_IMPLEMENT_CLASS("VappCbmApp", VappCbmApp, VfxApp);
VFX_IMPLEMENT_CLASS("VappCbmMainScrn", VappCbmMainScrn, VfxMainScr);


cbm_wlan_prefer_info_struct cbm_wlan_prefer_cntx;


void cbm_wlan_prefer_select_done(CbmWlanPreferCommandEnum id)
{
    if (cbm_wlan_prefer_cntx.callback)
    {
        (*cbm_wlan_prefer_cntx.callback)(id);
        cbm_wlan_prefer_cntx.callback = NULL;
    }

    VfxApp *app = VfxAppLauncher::findApp(
                    VAPP_CBM,
                    VFX_OBJ_CLASS_INFO(VappCbmApp),
                    VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG,
                    0);
    if (app)
    {
        VfxAppLauncher::terminate(app->getGroupId());
    }
}


static void vapp_cbm_launch_result_callback(VfxAppLauncherResultEnum result, void *userData)
{
    if (result == VFX_APP_LAUNCHER_RESULT_CANCEL &&
        cbm_wlan_prefer_cntx.callback)
    {
        (*cbm_wlan_prefer_cntx.callback)(CBM_WLAN_PREFER_COMMAND_CANCEL);
        cbm_wlan_prefer_cntx.callback = NULL;
    }
}


static MMI_BOOL cbm_wlan_prefer_defer_cb(mmi_scenario_id id, void *arg)
{
    if (!srv_cbm_is_wlan_query_needed())
    {
        cbm_wlan_prefer_cntx.callback = NULL;
        OslMfree(gVappCbmCntxPtr->wlanQueryEvt);
        gVappCbmCntxPtr->wlanQueryEvt = NULL;
        return MMI_FALSE;
    }

#if 1
    VfxAppLauncherParam launchParam(VAPP_CBM, VFX_OBJ_CLASS_INFO(VappCbmApp), GRP_ID_ROOT);

    launchParam.setLauncherResultCb(vapp_cbm_launch_result_callback, NULL);
    VfxAppLauncher::launchEx(launchParam);
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return MMI_TRUE;
}


void cbm_wlan_prefer_show_command_sheet(cbm_wlan_prefer_info_struct *info)
{
    cbm_wlan_prefer_cntx.query_type = info->query_type;
    cbm_wlan_prefer_cntx.show_wlan_opt = info->show_wlan_opt;
    cbm_wlan_prefer_cntx.show_cellular_opt = info->show_cellular_opt;
    cbm_wlan_prefer_cntx.text_id = info->text_id;
    cbm_wlan_prefer_cntx.callback = info->callback;
    cbm_wlan_prefer_cntx.auto_conn_wlan = info->auto_conn_wlan;
#ifdef __MMI_OP01_WIFI__
    cbm_wlan_prefer_cntx.show_ask_cellular = info->show_ask_cellular;
    cbm_wlan_prefer_cntx.callback_cmd = info->callback_cmd;
#endif /* __MMI_OP01_WIFI__ */
    cbm_wlan_prefer_cntx.reentry_callback = NULL;
    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_NON_TONE, cbm_wlan_prefer_defer_cb, NULL);
}


static void vappCbmWlanPreferCancelIfExisted(void)
{
    if (cbm_wlan_prefer_cntx.callback)
    {
        VfxApp *app;

        app = VfxAppLauncher::findApp(
                VAPP_CBM,
                VFX_OBJ_CLASS_INFO(VappCbmApp),
                VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG,
                0);

        if (app)
        {
        #if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
            if (vapp_ncenter_is_entered())
            {
                vapp_ncenter_disable_leave();
            }
        #endif /* defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

            VfxAppLauncher::terminate(app->getGroupId());
        }
        else
        {
            mmi_frm_nmgr_cancel_deferred_scenario(
                MMI_SCENARIO_ID_DEFAULT,
                cbm_wlan_prefer_defer_cb,
                NULL);

        #ifdef __MMI_OP01_WIFI__
            if (cbm_wlan_prefer_cntx.callback_cmd < CBM_WLAN_PREFER_COMMAND_TOTAL)
            {
                (*cbm_wlan_prefer_cntx.callback)(cbm_wlan_prefer_cntx.callback_cmd);
            }
            else
        #endif /* __MMI_OP01_WIFI__ */
            {
            #ifdef __CBM_BEARER_SWITCH__
                if (cbm_wlan_prefer_cntx.query_type == SRV_CBM_WLAN_QUERY_TYPE_FOUND)
                {
                    (*cbm_wlan_prefer_cntx.callback)(CBM_WLAN_PREFER_COMMAND_CELLULAR);
                }
                else
            #endif /* __CBM_BEARER_SWITCH__ */
                {
                    (*cbm_wlan_prefer_cntx.callback)(CBM_WLAN_PREFER_COMMAND_CANCEL);
                }
            }
            cbm_wlan_prefer_cntx.callback = NULL;
        }
    }
}


static void vappCbmWlanPreferReentryIfExisted(VfxBool deferReentry)
{
    if (cbm_wlan_prefer_cntx.callback)
    {
        VfxApp *app;

        app = VfxAppLauncher::findApp(
                VAPP_CBM,
                VFX_OBJ_CLASS_INFO(VappCbmApp),
                VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG,
                0);

        if (app)
        {
            if (deferReentry)
            {
                gVappCbmReentryDefered = VFX_TRUE;
            }

            cbm_wlan_prefer_cntx.reentry_callback = cbm_wlan_prefer_cntx.callback;
            cbm_wlan_prefer_cntx.callback = NULL;

        #if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
            if (vapp_ncenter_is_entered())
            {
                vapp_ncenter_disable_leave();
            }
        #endif /* defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

            VfxAppLauncher::terminate(app->getGroupId());
        }
    }
}


static VfxBool cbm_wlan_prefer_cancel_if_not_active(void)
{
    VfxApp *app;

    app = VfxAppLauncher::findApp(
            VAPP_CBM,
            VFX_OBJ_CLASS_INFO(VappCbmApp),
            VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG,
            0);

    if (app)
    {
        if (app->isGroupActive())
        {
            return VFX_FALSE;
        }
        else
        {
        #if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
            if (vapp_ncenter_is_entered())
            {
                vapp_ncenter_disable_leave();
            }
        #endif /* defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

            cbm_wlan_prefer_cntx.callback = NULL;
            VfxAppLauncher::terminate(app->getGroupId());
            return VFX_TRUE;
        }
    }
    else
    {
        MMI_BOOL is_defer;

        is_defer = mmi_frm_nmgr_is_scenario_deferred(MMI_SCENARIO_ID_DEFAULT, cbm_wlan_prefer_defer_cb, NULL);

        if (is_defer)
        {
            return VFX_FALSE;
        }
        else
        {
            return VFX_TRUE;
        }
    }
}


static mmi_ret vapp_cbm_wlan_prefer_reentry_callback(mmi_event_struct *evt)
{
    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_NON_TONE,
        cbm_wlan_prefer_defer_cb,
        NULL);
    return MMI_RET_OK;
}


void VappCbmApp::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VappCbmMainScrn *mainScrn;
    VFX_OBJ_CREATE(mainScrn, VappCbmMainScrn, this);
    mainScrn->show();
}


void VappCbmApp::onGroupActive()
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


void VappCbmApp::onGroupInactive()
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


VappCbmMainScrn::VappCbmMainScrn()
{
    m_statusBar = NULL;
    m_dir = VFX_SCR_ROTATE_TYPE_NORMAL;
    m_wlanId = 0;
    setIsSmallScreen();
}


VappCbmMainScrn::~VappCbmMainScrn()
{
    if (m_wlanId != 0)
    {
        vcui_wifi_ap_list_close(m_wlanId);
        m_wlanId = 0;
    }

    if (cbm_wlan_prefer_cntx.callback)
    {
    #ifdef __MMI_OP01_WIFI__
        if (cbm_wlan_prefer_cntx.callback_cmd < CBM_WLAN_PREFER_COMMAND_TOTAL)
        {
            (*cbm_wlan_prefer_cntx.callback)(cbm_wlan_prefer_cntx.callback_cmd);
        }
        else
    #endif /* __MMI_OP01_WIFI__ */
        {
        #ifdef __CBM_BEARER_SWITCH__
            if (cbm_wlan_prefer_cntx.query_type == SRV_CBM_WLAN_QUERY_TYPE_FOUND)
            {
                (*cbm_wlan_prefer_cntx.callback)(CBM_WLAN_PREFER_COMMAND_CELLULAR);
            }
            else
        #endif /* __CBM_BEARER_SWITCH__ */
            {
                (*cbm_wlan_prefer_cntx.callback)(CBM_WLAN_PREFER_COMMAND_CANCEL);
            }
        }
        cbm_wlan_prefer_cntx.callback = NULL;
    }
    else if (cbm_wlan_prefer_cntx.reentry_callback)
    {
        cbm_wlan_prefer_cntx.callback = cbm_wlan_prefer_cntx.reentry_callback;
        cbm_wlan_prefer_cntx.reentry_callback = NULL;

        if (!gVappCbmReentryDefered)
        {
            mmi_event_struct reEntryEvt;

            MMI_FRM_INIT_EVENT(&reEntryEvt, 0);
            MMI_FRM_POST_EVENT(&reEntryEvt, vapp_cbm_wlan_prefer_reentry_callback, NULL);
        }
    }
}


void VappCbmMainScrn::onInit()
{
    VfxMainScr::onInit();

    //VFX_OBJ_CREATE(m_statusBar, VcpStatusIconBar, this);
    //m_statusBar->setPos(0, 0);
}


void VappCbmMainScrn::on1stReady()
{
    VfxMainScr::on1stReady();

    setBgColor(VFX_COLOR_TRANSPARENT);
    setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);

    m_wlanId = 0;
    if (cbm_wlan_prefer_cntx.show_wlan_opt || cbm_wlan_prefer_cntx.show_cellular_opt)
    {
        VappCbmQuestionPop *wlanPreferPopup;
        VFX_OBJ_CREATE(wlanPreferPopup, VappCbmQuestionPop, this);
        wlanPreferPopup->setText(VFX_WSTR_RES(cbm_wlan_prefer_cntx.text_id));
        wlanPreferPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
        wlanPreferPopup->setAutoDestory(VFX_TRUE);
        if (cbm_wlan_prefer_cntx.show_wlan_opt)
        {
            wlanPreferPopup->addItem(CBM_WLAN_PREFER_COMMAND_WLAN, VFX_WSTR_RES(STR_ID_VAPP_CBM_USE_WLAN_NETWORK));
        }
        if (cbm_wlan_prefer_cntx.show_cellular_opt)
        {
            wlanPreferPopup->addItem(CBM_WLAN_PREFER_COMMAND_CELLULAR, VFX_WSTR_RES(STR_ID_VAPP_CBM_USE_CELLULAR));
        }
        wlanPreferPopup->addItem(CBM_WLAN_PREFER_COMMAND_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
        wlanPreferPopup->m_signalButtonClicked.connect(this, &VappCbmMainScrn::onCommandSheetClicked);
        wlanPreferPopup->show(VFX_TRUE);
    }
    else
    {
        VappCbmConfirmPop *connFailPopup;
        VFX_OBJ_CREATE(connFailPopup, VappCbmConfirmPop, this);
        connFailPopup->setText(VFX_WSTR_RES(cbm_wlan_prefer_cntx.text_id));
        connFailPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        connFailPopup->setAutoDestory(VFX_TRUE);
        connFailPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        connFailPopup->m_signalButtonClicked.connect(this, &VappCbmMainScrn::onCommandSheetClicked);
        connFailPopup->show(VFX_TRUE);
    }
}


void VappCbmMainScrn::onEnter(VfxBool isBackward)
{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    m_dir = renderer->getPreScreenRotateType();

    VfxMainScr::onEnter(isBackward);
}


void VappCbmMainScrn::onEntered(VfxBool isBackward)
{
    if (!m_statusBar)
    {
        VFX_OBJ_CREATE(m_statusBar, VcpStatusIconBar, this);
        m_statusBar->setPos(0, 0);
        m_statusBar->setSize(getSize().width, m_statusBar->getSize().height);
    }

    VfxMainScr::onEntered(isBackward);
}


void VappCbmMainScrn::onCommandSheetClicked(VfxObject*, VfxId id)
{
    if (id == CBM_WLAN_PREFER_COMMAND_WLAN)
    {
        if (cbm_wlan_prefer_cntx.auto_conn_wlan)
        {
            cbm_wlan_prefer_select_done(CBM_WLAN_PREFER_COMMAND_WLAN);
        }
        else
        {
            if (m_wlanId == 0)
            {
                m_wlanId = vcui_wifi_ap_list_create(getApp()->getGroupId(), NULL);
                if (m_wlanId != 0)
                {
                    vfxSetCuiCallerScr(m_wlanId, this);
                    vcui_wifi_ap_list_run(m_wlanId);
                }
            }
        }
    }
    else if (id == CBM_WLAN_PREFER_COMMAND_CELLULAR ||
             id == CBM_WLAN_PREFER_COMMAND_CANCEL)
    {
    #ifdef __MMI_OP01_WIFI__
        if (cbm_wlan_prefer_cntx.show_ask_cellular &&
            id == CBM_WLAN_PREFER_COMMAND_CELLULAR &&
            srv_cbm_get_ask_cellular_setting())
        {
            /* show ask cellular confirm screen */
            VappCbmConfirmPop *askCellPopup;
            VFX_OBJ_CREATE(askCellPopup, VappCbmConfirmPop, this);
            askCellPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_CBM_WLAN_NOT_AVAILABLE_USE_CELLULAR_NO_MORE_ASK));
            askCellPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
            askCellPopup->setAutoDestory(VFX_TRUE);
            askCellPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
            askCellPopup->m_signalButtonClicked.connect(this, &VappCbmMainScrn::onCommandSheetClicked);
            askCellPopup->show(VFX_TRUE);

            cbm_wlan_prefer_cntx.callback_cmd = CBM_WLAN_PREFER_COMMAND_CELLULAR;
        }
        else
    #endif /* __MMI_OP01_WIFI__ */
        {
            cbm_wlan_prefer_select_done((CbmWlanPreferCommandEnum)id);
        }
    }
    else if (id == VCP_CONFIRM_POPUP_BUTTON_OK ||
             id == VAPP_CBM_CONFIRM_POPUP_BACK
         #ifdef __MMI_OP01_WIFI__
             || id == VCP_CONFIRM_POPUP_BUTTON_YES
             || id == VCP_CONFIRM_POPUP_BUTTON_NO
         #endif /* __MMI_OP01_WIFI__ */
             )
    {
    #ifdef __MMI_OP01_WIFI__
        if (id == VCP_CONFIRM_POPUP_BUTTON_YES)
        {
            srv_cbm_set_ask_cellular_setting(MMI_FALSE);
        }

        if (cbm_wlan_prefer_cntx.callback_cmd < CBM_WLAN_PREFER_COMMAND_TOTAL)
        {
            cbm_wlan_prefer_select_done(cbm_wlan_prefer_cntx.callback_cmd);
        }
        else
    #endif /* __MMI_OP01_WIFI__ */
        {
        #ifdef __CBM_BEARER_SWITCH__
            if (cbm_wlan_prefer_cntx.query_type == SRV_CBM_WLAN_QUERY_TYPE_FOUND)
            {
                cbm_wlan_prefer_select_done(CBM_WLAN_PREFER_COMMAND_CELLULAR);
            }
            else
        #endif /* __CBM_BEARER_SWITCH__ */
            {
                cbm_wlan_prefer_select_done(CBM_WLAN_PREFER_COMMAND_CANCEL);
            }
        }
    }
}


mmi_ret VappCbmMainScrn::onProc(mmi_event_struct *evt)
{
    /* only one of these three events will be emitted */
    if (m_wlanId != 0)
    {
        vcui_wifi_ap_list_close(m_wlanId);
        m_wlanId = 0;
    }

    switch (evt->evt_id)
    {
        case EVT_ID_VCUI_WLAN_LIST_EVENT_RESULT_OK:
            cbm_wlan_prefer_select_done(CBM_WLAN_PREFER_COMMAND_WLAN);
            break;

        case EVT_ID_VCUI_WLAN_LIST_EVENT_RESULT_CANCEL:
        #ifdef __CBM_BEARER_SWITCH__
            if (cbm_wlan_prefer_cntx.query_type == SRV_CBM_WLAN_QUERY_TYPE_FOUND)
            {
                cbm_wlan_prefer_select_done(CBM_WLAN_PREFER_COMMAND_CELLULAR);
            }
            else
        #endif /* __CBM_BEARER_SWITCH__ */
            {
                cbm_wlan_prefer_select_done(CBM_WLAN_PREFER_COMMAND_CANCEL);
            }
            break;

        case EVT_ID_VCUI_WLAN_LIST_EVENT_CLOSE:
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


void VappCbmMainScrn::onRotate(const VfxScreenRotateParam &param)
{
    VfxMainScr::onRotate(param);
    if (m_statusBar)
    {
        m_statusBar->setSize(getSize().width, m_statusBar->getSize().height);
    }
}


VfxBool VappCbmConfirmPop::onKeyInput(VfxKeyEvent & event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN && event.keyCode == VFX_KEY_CODE_BACK)
    {
        m_signalButtonClicked.emit(this, VAPP_CBM_CONFIRM_POPUP_BACK);
        return VFX_TRUE;
    }

    return VcpConfirmPopup::onKeyInput(event);
}


VfxBool VappCbmQuestionPop::onKeyInput(VfxKeyEvent & event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN && event.keyCode == VFX_KEY_CODE_BACK)
    {
        m_signalButtonClicked.emit(this, VAPP_CBM_CONFIRM_POPUP_BACK);
        return VFX_TRUE;
    }

    return VcpQuestionPopup::onKeyInput(event);
}


static VfxBool vapp_cbm_cellular_need_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU32 i;
    mmi_sim_enum simId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_mode_switch_is_network_service_available() ||
        srv_mode_switch_is_switching() ||
    #ifdef __MMI_DATA_LOCK__
        !srv_data_lock_get_setting() ||
    #endif
        srv_sim_ctrl_get_num_of_inserted() == 0 ||
        !srv_sim_ctrl_any_sim_is_available() ||
        srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF)
    {
        return VFX_FALSE;
    }
    else
    {
        for (i = 0; i < MMI_SIM_TOTAL; i++)
        {
            simId = mmi_frm_index_to_sim((U32)i);
            if (srv_sim_ctrl_is_available(simId) &&
                srv_mode_switch_get_network_mode(simId) == SRV_MODE_SWITCH_ON)
            {
                return VFX_TRUE;
            }
        }

        return VFX_FALSE;
    }
}


static void vapp_cbm_wlan_auto_conn_dummy_callback(VCUI_WLAN_AUTO_CONN_ACTION_ENUM action)
{
}


#ifdef __CBM_BEARER_SWITCH__
static void vapp_cbm_wlan_auto_conn_found_callback(VCUI_WLAN_AUTO_CONN_ACTION_ENUM action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 bearer_type = CBM_BEARER_WIFI;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(gVappCbmCntxPtr->wlanQueryEvt);

    if (action != VCUI_WLAN_AUTO_CONN_ACTION_START)
    {
        bearer_type = CBM_BEARER_TOTAL;
    }

    gVappCbmCntxPtr->wlanQueryEvt->rsp_callback(bearer_type);
    OslMfree(gVappCbmCntxPtr->wlanQueryEvt);
    gVappCbmCntxPtr->wlanQueryEvt = NULL;
}
#endif /* __CBM_BEARER_SWITCH__ */


static void vapp_cbm_wlan_query_callback(CbmWlanPreferCommandEnum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 bearer_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(gVappCbmCntxPtr->wlanQueryEvt);

#ifdef __CBM_BEARER_SWITCH__
    if (gVappCbmCntxPtr->wlanQueryEvt->query_type == SRV_CBM_WLAN_QUERY_TYPE_FOUND)
    {
        if (result == CBM_WLAN_PREFER_COMMAND_WLAN &&
            gVappCbmCntxPtr->auto_conn)
        {
            vcui_wlan_auto_conn_networks(vapp_cbm_wlan_auto_conn_found_callback);
            return;
        }
    }
#endif /* __CBM_BEARER_SWITCH__ */

    switch (result)
    {
        case CBM_WLAN_PREFER_COMMAND_WLAN:
            bearer_type = CBM_BEARER_WIFI;
            break;

        case CBM_WLAN_PREFER_COMMAND_CELLULAR:
            bearer_type = CBM_BEARER_PS;
            break;

        default:
            bearer_type = CBM_BEARER_NONE;
            break;
    }

    gVappCbmCntxPtr->wlanQueryEvt->rsp_callback(bearer_type);
    OslMfree(gVappCbmCntxPtr->wlanQueryEvt);
    gVappCbmCntxPtr->wlanQueryEvt = NULL;
}


#ifdef __CBM_BEARER_SWITCH__
static void vapp_cbm_wlan_auto_conn_callback(VCUI_WLAN_AUTO_CONN_ACTION_ENUM action)
{
    srv_cbm_wlan_query_evt_struct *evtPtr = gVappCbmCntxPtr->wlanQueryEvt;
    cbm_wlan_prefer_info_struct param;
    VfxU32 needQuery;
    VfxU32 bearerType = CBM_BEARER_NONE;

    if (action == VCUI_WLAN_AUTO_CONN_ACTION_START)
    {
        evtPtr->rsp_callback(CBM_BEARER_WIFI);
        OslMfree(gVappCbmCntxPtr->wlanQueryEvt);
        gVappCbmCntxPtr->wlanQueryEvt = NULL;
    }
    else
    {
        needQuery = vapp_cbm_is_wlan_query_needed(evtPtr->query_type, 0, &bearerType);
        if (needQuery == VAPP_CBM_RET_YES)
        {
            vapp_cbm_fill_wlan_query_param(&param, evtPtr->query_type, 0);
            cbm_wlan_prefer_show_command_sheet(&param);
        }
        else if (needQuery == VAPP_CBM_RET_NO)
        {
            evtPtr->rsp_callback(bearerType);
            OslMfree(gVappCbmCntxPtr->wlanQueryEvt);
            gVappCbmCntxPtr->wlanQueryEvt = NULL;
        }
    }
}
#endif /* __CBM_BEARER_SWITCH__ */


static VfxS32 vapp_cbm_is_wlan_query_needed(
                srv_cbm_wlan_query_type_enum query_type,
                VfxU8 ap_num,
                VfxU32 *bearer_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS32 ret = VAPP_CBM_RET_YES;
    VfxBool show_cellular;
    srv_dtcnt_wlan_state_enum wlan_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wlan_state = srv_dtcnt_wlan_state();
    if (wlan_state == SRV_DTCNT_WLAN_STATE_NULL ||
        wlan_state == SRV_DTCNT_WLAN_STATE_TOTAL ||
        wlan_state == SRV_DTCNT_WLAN_STATE_DEINIT_WAIT)
    {
    #ifdef __CBM_BEARER_SWITCH__
        if (query_type == SRV_CBM_WLAN_QUERY_TYPE_FOUND)
        {
            *bearer_type = CBM_BEARER_TOTAL;
        }
        else
    #endif /* __CBM_BEARER_SWITCH__ */
        {
            *bearer_type = CBM_BEARER_NONE;
        }

        return VAPP_CBM_RET_NO;
    }

    show_cellular = vapp_cbm_cellular_need_show();

    switch (query_type)
    {
        case SRV_CBM_WLAN_QUERY_TYPE_STARTUP:
        #ifdef __MMI_OP01_WIFI__
            if (ap_num == 0)
            {
                MMI_BOOL ask_cellular = srv_cbm_get_ask_cellular_setting();

                if (!show_cellular || !ask_cellular)
                {
                    if (show_cellular)
                    {
                        *bearer_type = CBM_BEARER_PS;
                    }
                    else
                    {
                        *bearer_type = CBM_BEARER_NONE;
                    }
                    ret = VAPP_CBM_RET_NO;
                }
            }
        #else /* __MMI_OP01_WIFI__ */
            if (ap_num == 0)
            {
                if (show_cellular)
                {
                    *bearer_type = CBM_BEARER_PS;
                }
                else
                {
                    *bearer_type = CBM_BEARER_NONE;
                }
                ret = VAPP_CBM_RET_NO;
            }
        #endif /* __MMI_OP01_WIFI__ */
            break;

        case SRV_CBM_WLAN_QUERY_TYPE_RECONNECT:
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
            break;

    #ifdef __CBM_BEARER_SWITCH__
        case SRV_CBM_WLAN_QUERY_TYPE_DISCONNECTED:
            if (ap_num == 0)
            {
                if (!show_cellular)
                {
                    *bearer_type = CBM_BEARER_NONE;
                    ret = VAPP_CBM_RET_NO;
                }
            }
            else
            {
                if (gVappCbmCntxPtr->auto_conn)
                {
                    vcui_wlan_auto_conn_networks(vapp_cbm_wlan_auto_conn_callback);
                    ret = VAPP_CBM_RET_WOULDBLOCK;
                }
            }
            break;

        case SRV_CBM_WLAN_QUERY_TYPE_RESWITCH:
            if (gVappCbmCntxPtr->auto_conn && !show_cellular)
            {
                *bearer_type = CBM_BEARER_NONE;
                ret = VAPP_CBM_RET_NO;
            }
            break;

        case SRV_CBM_WLAN_QUERY_TYPE_FOUND:
            if (ap_num == 0 || !gVappCbmCntxPtr->need_notify)
            {
                if (ap_num != 0 && gVappCbmCntxPtr->auto_conn)
                {
                    vcui_wlan_auto_conn_networks(vapp_cbm_wlan_auto_conn_found_callback);
                    ret = VAPP_CBM_RET_WOULDBLOCK;
                }
                else
                {
                    *bearer_type = CBM_BEARER_TOTAL;
                    ret = VAPP_CBM_RET_NO;
                }
            }
            break;
    #endif /* __CBM_BEARER_SWITCH__ */

        default:
            break;
    }

    return ret;
}


static void vapp_cbm_fill_wlan_query_param(
                cbm_wlan_prefer_info_struct *param,
                srv_cbm_wlan_query_type_enum query_type,
                VfxU8 ap_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param->query_type = query_type;
    param->text_id = 0;
    param->show_wlan_opt = VFX_FALSE;
    param->show_cellular_opt = vapp_cbm_cellular_need_show();
    param->auto_conn_wlan = gVappCbmCntxPtr->auto_conn;
    param->callback = vapp_cbm_wlan_query_callback;
#ifdef __MMI_OP01_WIFI__
    param->show_ask_cellular = VFX_FALSE;
    param->callback_cmd = CBM_WLAN_PREFER_COMMAND_TOTAL;
#endif /* __MMI_OP01_WIFI__ */

    switch (query_type)
    {
        case SRV_CBM_WLAN_QUERY_TYPE_STARTUP:
            if (ap_num == 0)
            {
                param->text_id = STR_ID_VAPP_CBM_WLAN_NOT_AVAILABLE_USE_CELLULAR;
            #ifdef __MMI_OP01_WIFI__
                param->show_ask_cellular = VFX_TRUE;
            #endif
            }
            else
            {
                param->text_id = STR_ID_VAPP_CBM_WLAN_SIGNAL_AVAILABLE_USE_NOW;
                param->show_wlan_opt = VFX_TRUE;
            }
            break;

        case SRV_CBM_WLAN_QUERY_TYPE_RECONNECT:
            if (ap_num != 0)
            {
                param->text_id = STR_ID_VAPP_CBM_WLAN_CONNECTION_FAILED_USE_OTHER;
                param->show_wlan_opt = VFX_TRUE;
            }
            else if (param->show_cellular_opt)
            {
                param->text_id = STR_ID_VAPP_CBM_WLAN_CONNECTION_FAILED_USE_CELLULAR;
            }
            else
            {
                param->text_id = STR_ID_VAPP_CBM_WLAN_CONNECTION_FAILED;
            }
            break;

    #ifdef __CBM_BEARER_SWITCH__
        case SRV_CBM_WLAN_QUERY_TYPE_DISCONNECTED:
            if (ap_num != 0)
            {
                param->text_id = STR_ID_VAPP_CBM_WLAN_DISCONNECTED_USE_OTHER;
                param->show_wlan_opt = VFX_TRUE;
            }
            else if (param->show_cellular_opt)
            {
                param->text_id = STR_ID_VAPP_CBM_WLAN_DISCONNECTED_USE_CELLULAR;
            }
            else
            {
                param->text_id = STR_ID_VAPP_CBM_WLAN_DISCONNECTED;
            }
            break;

        case SRV_CBM_WLAN_QUERY_TYPE_RESWITCH:
            if (gVappCbmCntxPtr->auto_conn)
            {
                if (param->show_cellular_opt)
                {
                    param->text_id = STR_ID_VAPP_CBM_WLAN_DISCONNECTED_USE_CELLULAR;
                }
                else
                {
                    param->text_id = STR_ID_VAPP_CBM_WLAN_DISCONNECTED;
                }
            }
            else
            {
                if (ap_num != 0)
                {
                    param->text_id = STR_ID_VAPP_CBM_WLAN_CONNECTION_FAILED_USE_OTHER;
                    param->show_wlan_opt = VFX_TRUE;
                }
                else if (param->show_cellular_opt)
                {
                    param->text_id = STR_ID_VAPP_CBM_WLAN_CONNECTION_FAILED_USE_CELLULAR;
                }
                else
                {
                    param->text_id = STR_ID_VAPP_CBM_WLAN_CONNECTION_FAILED;
                }
            }
            break;

        case SRV_CBM_WLAN_QUERY_TYPE_FOUND:
            param->text_id = STR_ID_VAPP_CBM_WLAN_SIGNAL_AVAILABLE_WARNING;
            param->show_wlan_opt = VFX_TRUE;
            param->show_cellular_opt = VFX_FALSE;
            break;
    #endif /* __CBM_BEARER_SWITCH__ */

        default:
            break;
    }
}


static void vapp_cbm_wlan_scan_callback(
                U32 job_id,
                void *userData,
                srv_dtcnt_wlan_scan_result_struct *scanRes)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_wlan_query_evt_struct *evtPtr = gVappCbmCntxPtr->wlanQueryEvt;
    cbm_wlan_prefer_info_struct param;
    VfxU32 needQuery;
    VfxU32 bearerType = CBM_BEARER_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G6_CBM,
        TRC_VAPP_CBM_WLAN_SCAN_CALLBACK,
        scanRes->result,
        scanRes->ap_list_num,
        gVappCbmCntxPtr->isWaitingScan,
        (evtPtr ? evtPtr->query_type : -1));

    if (!gVappCbmCntxPtr->isWaitingScan)
    {
        return;
    }
    gVappCbmCntxPtr->isWaitingScan = MMI_FALSE;

    if (scanRes->result != SRV_DTCNT_WLAN_SCAN_RESULT_SUCCESS)
    {
        scanRes->ap_list_num = 0;
    }

    needQuery = vapp_cbm_is_wlan_query_needed(
                    evtPtr->query_type,
                    scanRes->ap_list_num,
                    &bearerType);

    if (needQuery == VAPP_CBM_RET_YES)
    {
        vapp_cbm_fill_wlan_query_param(&param, evtPtr->query_type, scanRes->ap_list_num);
        cbm_wlan_prefer_show_command_sheet(&param);
    }
    else if (needQuery == VAPP_CBM_RET_NO)
    {
        evtPtr->rsp_callback(bearerType);
        OslMfree(gVappCbmCntxPtr->wlanQueryEvt);
        gVappCbmCntxPtr->wlanQueryEvt = NULL;
    }
}



extern "C" mmi_ret vappCbmSrvCbmWlanQueryEvtHdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_wlan_query_evt_struct *wlan_query_p;
    srv_dtcnt_wlan_state_enum wlan_state;
    VfxBool result;
    MMI_BOOL autoConn;
    MMI_BOOL needNotify;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wlan_query_p = (srv_cbm_wlan_query_evt_struct*)param;

    if (!gVappCbmCntxPtr)
    {
        gVappCbmCntxPtr = &gVappCbmCntx;
        memset(gVappCbmCntxPtr, 0, sizeof(vappCbmCntxStruct));
    }

    if (wlan_query_p->query_type == SRV_CBM_WLAN_QUERY_TYPE_REQUERY)
    {
        MMI_ASSERT(gVappCbmCntxPtr->wlanQueryEvt);

        if (gVappCbmCntxPtr->isWaitingScan)
        {
            return MMI_RET_OK;
        }

        result = cbm_wlan_prefer_cancel_if_not_active();
        if (!result)
        {
            return MMI_RET_OK;
        }
    }
    else if (wlan_query_p->query_type == SRV_CBM_WLAN_QUERY_TYPE_AUTO_CONN)
    {
        vcui_wlan_auto_conn_networks(vapp_cbm_wlan_auto_conn_dummy_callback);
        wlan_query_p->rsp_callback(CBM_BEARER_WIFI);
        return MMI_RET_OK;
    }
    else
    {
        MMI_ASSERT(!gVappCbmCntxPtr->wlanQueryEvt && !gVappCbmCntxPtr->isWaitingScan);

        gVappCbmCntxPtr->wlanQueryEvt = (srv_cbm_wlan_query_evt_struct*)
            OslMalloc(sizeof(srv_cbm_wlan_query_evt_struct));

        memcpy(
            gVappCbmCntxPtr->wlanQueryEvt,
            wlan_query_p,
            sizeof(srv_cbm_wlan_query_evt_struct));
    }

    srv_cbm_get_wlan_prefer_setting(wlan_query_p->query_type, &autoConn, &needNotify);

    gVappCbmCntxPtr->auto_conn = autoConn ? VFX_TRUE : VFX_FALSE;
    gVappCbmCntxPtr->need_notify = needNotify ? VFX_TRUE : VFX_FALSE;

    gVappCbmCntxPtr->isWaitingScan = VFX_TRUE;

    wlan_state = srv_dtcnt_wlan_state();

    if (
    #ifdef __MMI_OP01_WIFI__
        !srv_mode_switch_is_network_service_available() ||
    #endif
        srv_mode_switch_is_switching() ||
        wlan_state == SRV_DTCNT_WLAN_STATE_NULL ||
        wlan_state == SRV_DTCNT_WLAN_STATE_TOTAL ||
        wlan_state == SRV_DTCNT_WLAN_STATE_DEINIT_WAIT
    #ifdef __MMI_TETHERING_WIFI__
        || !srv_tethering_is_off(SRV_TETHERING_TYPE_WIFI_HS)
    #endif
        )
    {
        srv_dtcnt_wlan_scan_result_struct scan_res;
        scan_res.result = SRV_DTCNT_WLAN_SCAN_RESULT_SUCCESS;
        scan_res.ap_list_num = 0;
        vapp_cbm_wlan_scan_callback(0, NULL, &scan_res);
        return MMI_RET_OK;
    }

#ifndef WENKE_TEST
    srv_dtcnt_wlan_scan(vapp_cbm_wlan_scan_callback, NULL);
#else
    {
        srv_dtcnt_wlan_scan_result_struct scan;
        scan.result = SRV_DTCNT_WLAN_SCAN_RESULT_SUCCESS;
        scan.ap_list_num = 1;
        vapp_cbm_wlan_scan_callback(0, NULL, &scan);
    }
#endif

    return MMI_RET_OK;
}


extern "C" mmi_ret vappCbmEvtProcHdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_VAPP_SCREEN_LOCK_LOCKED_EVT:
            vappCbmWlanPreferReentryIfExisted(VFX_FALSE);
            break;

        case EVT_ID_SRV_UCM_INDICATION:
            {
                srv_ucm_ind_evt_struct *ucmInd = (srv_ucm_ind_evt_struct*)evt;
                if (ucmInd->ind_type == SRV_UCM_INCOMING_CALL_IND)
                {
                    vappCbmWlanPreferReentryIfExisted(VFX_FALSE);
                }
            }
            break;

    #if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        case EVT_ID_VAPP_NCENTER_ENTERED:
            break;

        case EVT_ID_VAPP_NCENTER_EXITED:
        #if 0
/* under construction !*/
        #else
            if (cbm_wlan_prefer_cntx.callback)
            {
                VfxApp *app;

                app = VfxAppLauncher::findApp(
                        VAPP_CBM,
                        VFX_OBJ_CLASS_INFO(VappCbmApp),
                        VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG,
                        0);

                if (app)
                {
                    if (!app->isGroupTopActive())
                    {
                        cbm_wlan_prefer_cntx.reentry_callback = cbm_wlan_prefer_cntx.callback;
                        cbm_wlan_prefer_cntx.callback = NULL;

                        VfxAppLauncher::terminate(app->getGroupId());
                    }
                }
            }
        #endif
            break;
    #endif /* defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

        case EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND:
            {
                srv_dtcnt_wlan_deinit_res_ind_evt_struct *wlanDeinitInd =
                    (srv_dtcnt_wlan_deinit_res_ind_evt_struct*)evt;

                if (wlanDeinitInd->res == SRV_DTCNT_WLAN_REQ_RES_DONE)
                {
                    vappCbmWlanPreferCancelIfExisted();
                }
            }
            break;

        case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
            {
                srv_mode_switch_notify_struct *flightMode =
                    (srv_mode_switch_notify_struct*)evt;

                if ((flightMode->curr_flight_mode == SRV_MODE_SWITCH_OFF &&
                      flightMode->select_flight_mode == SRV_MODE_SWITCH_ON))
                {
                    vappCbmWlanPreferCancelIfExisted();
                }
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}

#endif /* __MMI_WLAN_FEATURES__ */
#endif /* __TCPIP__ */

