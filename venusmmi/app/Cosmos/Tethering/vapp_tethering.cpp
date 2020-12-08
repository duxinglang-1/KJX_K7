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
 *  vapp_tethering.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Internet Tethering
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_TETHERING__

/***************************************************************************** 
 * Include
 *****************************************************************************/

//#include "vtst_rt_mainscr.h"
//#include "vtst_rt_main.h"
#include "../xml/vfx_xml_loader.h"
#include "vcp_popup.h"
#include "vcp_form.h"
#include "vapp_tethering.h"
#include "vcui_dtcnt_select_gprot.h"
#include "vcp_global_popup.h"
#include "vapp_nmgr_gprot.h"
extern "C"
{
#include "GlobalResDef.h"
#include "mmi_rp_srv_tethering_def.h"
#include "mmi_rp_vapp_tethering_def.h"
#include "mmi_rp_vcui_dtcnt_def.h"
#include "TetheringSrvIprot.h"
#include "TetheringSrvGprot.h"
#include "mmi2abm_struct.h"
#include "ModeSwitchSrvGprot.h"
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
MMI_ID g_vapp_tethering_glb_popup_id = VCP_GLOBAL_POPUP_INVALID_HANDLE;

void usbTetheringLaunch();
void vappTetheringConfigConnInfo();

/***************************************************************************** 
 * Function
 *****************************************************************************/

void vappTetheringConfigConnInfo()
{
    MMI_ASSERT(SRV_DTCNT_SIM_TYPE_1 == 1);
    srv_tethering_conn_info_struct connInfo;
    srv_dtcnt_sim_type_enum simType;
    srv_dtcnt_get_sim_preference(&simType);
    connInfo.common_account_id = srv_tethering_get_dtcnt(simType);
    connInfo.used_sim = cbm_get_sim_id(connInfo.common_account_id);
    connInfo.conn_info_notify.funcptr = VappTetheringEvtListener::connInfoHdlr;
    connInfo.conn_info_notify.user_data = NULL;
    connInfo.disconnect_notify.funcptr = VappTetheringEvtListener::disconnectHdlr;
    connInfo.disconnect_notify.user_data = NULL;
    srv_tethering_set_conn_info(&connInfo);
}


extern "C"
{
void vapp_tethering_init(void)
{
}


MMI_ID vapp_tethering_launch(void* param, U32 param_size)
{
    srv_tethering_launch_result_enum result = srv_tethering_check_launch_main_menu_capab();
    if (result == SRV_TETHERING_LAUNCH_RESULT_OK)
    {
        return VfxAppLauncher::launch(
            VAPP_TETHERING,
            VFX_OBJ_CLASS_INFO(VappTethering),
            GRP_ID_ROOT,
            NULL,
            0);
    }
    else
    {
        MMI_STR_ID str;
        switch (result)
        {
            case SRV_TETHERING_LAUNCH_RESULT_FLIGHT_MODE:
                str = STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE;
                break;
                
            default:
                str = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE;
                break;
        }
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_INFO,
            (WCHAR*)GetString(str));

        return GRP_ID_INVALID;
    }
}


mmi_ret vappTetheringNoSimAvailableHdlr(mmi_event_struct* para)
{
    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->noSimAvailableHdlr();

    return MMI_RET_OK;
}
}


VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappTetheringEvtListener);
void VappTetheringEvtListener::switchCnfHdlr(
    srv_tethering_type_enum tetheringType,
    VfxBool result,
    srv_tethering_status_enum desStatus,
    void *arg)
{
    if (desStatus == SRV_TETHERING_STATUS_SRV_ON && result == MMI_TRUE)
    {
        mmi_frm_nmgr_notify_by_app(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO,
            (mmi_noti_scrn_func_ptr)&VappTetheringNmgrPopup::proxyPopup,
            NULL);
    }
    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringSwitchCnf.postEmit(tetheringType, result, desStatus);
}


void VappTetheringEvtListener::disconnectHdlr(
    srv_tethering_type_enum tetheringType,
    srv_tethering_disconn_cause_enum cause,
    void *userData)
{    
    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringDisconnect.postEmit(tetheringType, cause);

    switch (tetheringType)
    {
    #ifdef __MMI_TETHERING_WIFI__
        case SRV_TETHERING_TYPE_WIFI_HS:
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
                VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_DISCONNECT));
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
            break;
        }
    #endif /* __MMI_TETHERING_WIFI__ */

    #ifdef __USB_TETHERING__
        case SRV_TETHERING_TYPE_USB:
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
                VFX_WSTR_RES(STR_ID_SRV_TETHERING_USB_DISCONNECT));
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
            break;
        }
    #endif /* __USB_TETHERING__ */

        default:
        {
            break;
        }
    }
}


void VappTetheringEvtListener::connInfoHdlr(
    srv_tethering_type_enum tetheringType,
    void *infoData,
    void *userData
)
{
    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringConnInfo.emit(tetheringType, infoData);
}


void VappTetheringEvtListener::availStatusChangeHdlr(VfxBool enableFlag, void* userData)
{
    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringAvailStatusChange.postEmit(enableFlag);
}


void VappTetheringEvtListener::tetheringUsbCableDisconnHdlr()
{
    VappTetheringNmgrPopup::dismissPopup();
    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringUsbCableDisconn.postEmit();
}


void VappTetheringEvtListener::reactivateDemandHdlr(srv_tethering_type_enum tetheringType)
{
    vappTetheringConfigConnInfo();
    
    srv_tethering_switch_cb_funcptr_type funcPtr =
        (srv_tethering_switch_cb_funcptr_type)(VappTetheringEvtListener::switchCnfHdlr);
    srv_tethering_switch_on(tetheringType, funcPtr, NULL);
}


void VappTetheringEvtListener::dtcntChangedNotifyHdlr(
    srv_dtcnt_sim_type_enum sim,
    VfxU32 acct)
{
    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringDtcntChangedNotify.postEmit(sim, acct);
}


void VappTetheringEvtListener::noSimAvailableHdlr()
{
    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringNoSimAvailable.postEmit();
}


MMI_BOOL VappTetheringNmgrPopup::proxyPopup(mmi_scenario_id scenarioId, void *arg)
{
    MMI_BOOL ret;

    srv_dtcnt_prof_proxy_info_struct dtcntProxyInfo;
    if (MMI_TRUE == srv_dtcnt_get_proxy_info(
                        srv_tethering_get_used_dtcnt(),
                        &dtcntProxyInfo,
                        SRV_DTCNT_ACCOUNT_PRIMARY) && dtcntProxyInfo.use_proxy)
    {
        mmi_frm_start_scenario(scenarioId);

        g_vapp_tethering_glb_popup_id = vcp_global_popup_show_confirm_one_button_str(
            GRP_ID_ROOT,
            VCP_POPUP_TYPE_INFO,
            VFX_WSTR_RES(STR_ID_SRV_TETHERING_PROXY_PROMPT),
            VFX_WSTR_RES(STR_GLOBAL_OK),
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            NULL,
            NULL);

        ret = MMI_TRUE;
    }
    else
    {
        ret = MMI_FALSE;
    }

    return ret;
}


void VappTetheringNmgrPopup::dismissPopup()
{
    if (g_vapp_tethering_glb_popup_id != VCP_GLOBAL_POPUP_INVALID_HANDLE)
    {
        vcp_global_popup_cancel(g_vapp_tethering_glb_popup_id);
        mmi_frm_nmgr_cancel_deferred_scenario(
            MMI_SCENARIO_ID_DEFAULT,
            (mmi_noti_scrn_func_ptr)&VappTetheringNmgrPopup::proxyPopup,
            NULL);
        g_vapp_tethering_glb_popup_id = VCP_GLOBAL_POPUP_INVALID_HANDLE;
    }
}


#ifdef __MMI_TETHERING_WIFI__
void wifiTetheringReconn()
{
    VfxAppLauncher::launchWithAsmSize(
        VAPP_TETHERING,
        VFX_OBJ_CLASS_INFO(VappTetheringWifiReconn),
        GRP_ID_ROOT,
        100 * 1024,
        NULL,
        0);
}


VFX_IMPLEMENT_CLASS("VappTetheringWifiReconn", VappTetheringWifiReconn, VfxApp);
void VappTetheringWifiReconn::onRun(void * args,VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);
    
    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringSwitchCnf.connect(this, &VappTetheringWifiReconn::switchCnfHdlr);

    vappTetheringConfigConnInfo();

    srv_tethering_switch_cb_funcptr_type funcPtr =
        (srv_tethering_switch_cb_funcptr_type)(VappTetheringEvtListener::switchCnfHdlr);
    srv_tethering_launch_result_enum result = srv_tethering_check_launch_capab(SRV_TETHERING_TYPE_WIFI_HS);
    if (result == SRV_TETHERING_LAUNCH_RESULT_OK ||
        result == SRV_TETHERING_LAUNCH_RESULT_NETWORK_NOT_READY)
    {
        VappTetheringWifiReconnIndMainScr *indPopupScr;
        VFX_OBJ_CREATE(indPopupScr, VappTetheringWifiReconnIndMainScr, this);
        indPopupScr->show();
        srv_tethering_switch_on(SRV_TETHERING_TYPE_WIFI_HS, funcPtr, this);
    }
    else
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_FAILURE,
            VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_DISCONNECT));
        exit();
    }
}


void VappTetheringWifiReconn::switchCnfHdlr(
    srv_tethering_type_enum tetheringType,
    VfxBool result,
    srv_tethering_status_enum desStatus)
{
    // close this launcher screen
    exit();

    if (tetheringType == SRV_TETHERING_TYPE_WIFI_HS)
    {
        if (result == VFX_FALSE)
        {
            vapp_nmgr_global_popup_show_confirm_one_button_id(
                MMI_SCENARIO_ID_DEFAULT,
                VCP_POPUP_TYPE_FAILURE,
                STR_GLOBAL_FAILED,
                STR_GLOBAL_OK,
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                NULL,
                NULL);
        }
    }
}


VFX_IMPLEMENT_CLASS("VappTetheringWifiReconnIndMainScr", VappTetheringWifiReconnIndMainScr, VfxAppScr);
VappTetheringWifiReconnIndMainScr::VappTetheringWifiReconnIndMainScr()
{
    setIsSmallScreen();
}


void VappTetheringWifiReconnIndMainScr::onInit()
{
    VfxAppScr::onInit();

    //setOpacity(0);

    VcpIndicatorPopup *IndPopup;
    VFX_OBJ_CREATE(IndPopup, VcpIndicatorPopup, this);
    IndPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
    IndPopup->setText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_RECONNECT));
    IndPopup->m_signalCanceled.connect(this, &VappTetheringWifiReconnIndMainScr::onCancel);
    IndPopup->show(VFX_TRUE);
}


void VappTetheringWifiReconnIndMainScr::onDeinit()
{
    if (srv_tethering_get_ext_status(SRV_TETHERING_TYPE_WIFI_HS) == SRV_TETHERING_EXT_STATUS_REACTIVATE)
    {
        srv_tethering_stop(SRV_TETHERING_TYPE_WIFI_HS, NULL, NULL);
    }
    VfxAppScr::onDeinit();
}


void VappTetheringWifiReconnIndMainScr::onCancel(VfxObject* obj, VfxFloat result)
{
    exit();
}

#endif /* __MMI_TETHERING_WIFI__ */


VFX_IMPLEMENT_CLASS("VappTethering", VappTethering, VfxApp);
void VappTethering::onRun(void * args,VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VappTetheringMainScr *mainScr;
    VFX_OBJ_CREATE(mainScr, VappTetheringMainScr, this);
    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringNoSimAvailable.connect(this, &VappTethering::exit);
    mainScr->show();
}


VFX_IMPLEMENT_CLASS("VcuiTethering", VcuiTethering, VfxCui);
void VcuiTethering::onRun(void * args,VfxU32 argSize)
{
    VfxCui::onRun(args, argSize);

    VappTetheringMainScr *mainScr;
    VFX_OBJ_CREATE(mainScr, VappTetheringMainScr, this);
    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringNoSimAvailable.connect(this, &VcuiTethering::exit);
    mainScr->show();
}


VFX_IMPLEMENT_CLASS("VappTetheringMainScr", VappTetheringMainScr, VfxMainScr);
VappTetheringMainScr::VappTetheringMainScr() :
    m_mainScrPage(NULL),
#ifdef __MMI_TETHERING_WIFI__
    m_settingsPage(NULL),
#endif /* __MMI_TETHERING_WIFI__ */
    m_connInfoPage(NULL),
    m_helpPage(NULL)
{
}


void VappTetheringMainScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringDisconnect.connect(this, &VappTetheringMainScr::disconnectHdlr);

    entryMainScrPage();
}


void VappTetheringMainScr::entryMainScrPage()
{
    VFX_OBJ_CREATE(m_mainScrPage, VappTetheringMainScrPage, this);
    pushPage(0, m_mainScrPage.get());
}


void VappTetheringMainScr::entryWifiSettingsPage()
{
#ifdef __MMI_TETHERING_WIFI__
    VFX_OBJ_CREATE(m_settingsPage, VappTetheringWifiHsSettingsPage, this);
    pushPage(0, m_settingsPage.get());
#endif /* __MMI_TETHERING_WIFI__ */
}


void VappTetheringMainScr::entryDtcntCui()
{
    cui_dtcnt_select_run_struct dtcnt_cui;
    memset(&dtcnt_cui, 0x00, sizeof(cui_dtcnt_select_run_struct));

    dtcnt_cui.bearers = DATA_ACCOUNT_BEARER_GPRS;
    dtcnt_cui.app_id = srv_tethering_get_common_cbm_app_id();
    VfxU32 sim;
    for (sim = 0; sim < MMI_SIM_TOTAL; sim++)
    {
        dtcnt_cui.sim_account_id[sim] = srv_tethering_get_dtcnt((srv_dtcnt_sim_type_enum)(sim + 1));
    }
    dtcnt_cui.sim_selection = CUI_DTCNT_SELECT_SIM_ALL;
    dtcnt_cui.option = CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT;
    dtcnt_cui.type = CUI_DTCNT_SELECT_TYPE_NORMAL;

    m_dtcntCuiId = vcui_dtcnt_select_create(getGroupId());
    vcui_dtcnt_select_set_param(m_dtcntCuiId, &dtcnt_cui);
    vfxSetCuiCallerScr(m_dtcntCuiId, this);
    vcui_dtcnt_select_run(m_dtcntCuiId);
    m_dtcntCuiExist = VFX_TRUE;
    
    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringDtcntChangedNotify.connect(this, &VappTetheringMainScr::dtcntChangedNotifyHdlr);
    srv_tethering_dtcnt_set_changed_notify_cb(
        (srv_tethering_dtcnt_changed_notify_func_ptr_type)VappTetheringEvtListener::dtcntChangedNotifyHdlr);
}


void VappTetheringMainScr::exitDtcntCui()
{
    vcui_dtcnt_select_close(m_dtcntCuiId);
}


void VappTetheringMainScr::entryConnInfoPage()
{
    VFX_OBJ_CREATE(m_connInfoPage, VappTetheringConnInfoPage, this);
    pushPage(0, m_connInfoPage.get());
}

void VappTetheringMainScr::entryProxyInfoPage()
{
    VFX_OBJ_CREATE(m_proxyInfoPage, VappTetheringProxyInfoPage, this);
    pushPage(0, m_proxyInfoPage.get());
}

void VappTetheringMainScr::entryHelpPage()
{
    VFX_OBJ_CREATE(m_helpPage, VappTetheringHelpPage, this);
    pushPage(0, m_helpPage.get());
}


void VappTetheringMainScr::disconnectHdlr(srv_tethering_type_enum tetheringType, srv_tethering_disconn_cause_enum cause)
{
    if (cause == SRV_TETHERING_DISCONNECT_CAUSE_AUTO_TURN_OFF)
    {
    #ifdef __MMI_TETHERING_WIFI__
        m_mainScrPage->wifiSwitchProcess(VFX_FALSE);
    #endif /* __MMI_TETHERING_WIFI__ */
    }
    else
    {
        getApp()->exit();
    }
}


void VappTetheringMainScr::updataSettingsReq(srv_tethering_type_enum tetheringType)
{
    if (tetheringType == SRV_TETHERING_TYPE_WIFI_HS)
    {
        vappTetheringConfigConnInfo();

        srv_tethering_switch_cb_funcptr_type funcPtr =
            (srv_tethering_switch_cb_funcptr_type)(VappTetheringEvtListener::switchCnfHdlr);

        srv_tethering_abm_update_settings(
            tetheringType,
            funcPtr,
            this->m_mainScrPage.get());
    }
}


mmi_ret VappTetheringMainScr::onProc(mmi_event_struct *evt)
{
    cui_dtcnt_select_event_result_struct *dtcntSel = (cui_dtcnt_select_event_result_struct*)evt;

    switch (evt->evt_id)
    {
        case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
        {
            cui_dtcnt_select_event_any_sim_selected_struct *sim_selected = (cui_dtcnt_select_event_any_sim_selected_struct*)evt;
            cui_dtcnt_sim_enum sim = sim_selected->selectSim;
            srv_tethering_save_dtcnt((srv_dtcnt_sim_type_enum)(sim+1), sim_selected->accountId);
            break;
        }

        case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
        case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
        case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
        case CUI_DTCNT_SELECT_EVENT_CLOSE:
            vcui_dtcnt_select_close(dtcntSel->sender_id);
            m_dtcntCuiExist = VFX_FALSE;
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}


void VappTetheringMainScr::dtcntChangedNotifyHdlr(
    srv_dtcnt_sim_type_enum sim,
    VfxU32 acct)
{
    if (m_dtcntCuiExist == VFX_TRUE)
    {
        vcui_dtcnt_select_set_account_id(
            m_dtcntCuiId,
            (cui_dtcnt_sim_enum)(sim-1),
            acct);
    }
}


VFX_IMPLEMENT_CLASS("VappTetheringMainScrPage", VappTetheringMainScrPage, VfxPage);
VappTetheringMainScrPage::VappTetheringMainScrPage() :
    m_form(NULL),
    m_pwInputPopup(NULL),
    runTurnOffWlanFlag(VFX_FALSE),
    m_CountDownTimer(NULL)
{
}


void VappTetheringMainScrPage::onInit()
{
    VfxPage::onInit();

    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringSwitchCnf.connect(this, &VappTetheringMainScrPage::switchCnfHdlr);
    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringConnInfo.connect(this, &VappTetheringMainScrPage::connInfoHdlr);

    setStatusBar(VFX_TRUE);
    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_ID_SRV_TETHERING));
    setTopBar(bar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setPos(0,0);
    m_form->setBounds(VfxRect(VfxPoint(0, 0), getSize()));
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

#ifdef __MMI_TETHERING_WIFI__
    // wifi caption
    VcpFormItemCaption *wifiCap;
    VFX_OBJ_CREATE(wifiCap, VcpFormItemCaption, m_form);
    wifiCap->setText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_HS));

    // wifi switch
    VcpFormItemSwitchCell *wifiSwitch;
    VFX_OBJ_CREATE(wifiSwitch, VcpFormItemSwitchCell, m_form);
    MMI_BOOL statusFlag = srv_tethering_is_on(SRV_TETHERING_TYPE_WIFI_HS);
    wifiSwitch->setSwitchStatus((statusFlag == MMI_TRUE ? VFX_TRUE : VFX_FALSE));
    wifiSwitch->setMainText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_HS));
    wifiSwitch->m_signalSwitchChangeReq.connect(this, &VappTetheringMainScrPage::wifiSwitchReqHdlr);

    // wifi settings
    VcpFormItemLauncherCell *launchWifiSettings;
    VFX_OBJ_CREATE(launchWifiSettings, VcpFormItemLauncherCell, m_form);
    launchWifiSettings->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    launchWifiSettings->setMainText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_HS_SETTINGS));
    launchWifiSettings->setHintText(VFX_WSTR_RES(STR_ID_VAPP_TETHERING_WIFI_SETTINGS_EXPLANATION));
    launchWifiSettings->m_signalTap.connect(this, &VappTetheringMainScrPage::onItemCellLaunch);

    // auto turn off switch
    VcpFormItemSwitchCell *autoTurnOffSwitch;
    VFX_OBJ_CREATE(autoTurnOffSwitch, VcpFormItemSwitchCell, m_form);
    autoTurnOffSwitch->setMainText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_AUTO_TURN_OFF));
    autoTurnOffSwitch->m_signalSwitchChangeReq.connect(this, &VappTetheringMainScrPage::autoTurnOffSwitchReqHdlr);    

#endif /* __MMI_TETHERING_WIFI__ */
#ifdef __USB_TETHERING__
    // usb caption
    VcpFormItemCaption *usbCap;
    VFX_OBJ_CREATE(usbCap, VcpFormItemCaption, m_form);
    usbCap->setText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_USB));

    // usb info text
    VcpFormItemCell *usbItem;
    VFX_OBJ_CREATE(usbItem, VcpFormItemCell, m_form);
    usbItem->setMainText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_USB));
    usbItem->setHintText(VFX_WSTR_RES(STR_ID_VAPP_TETHERING_USB_PROMPT_PLUG_IN));
    usbItem->setIsTappable(VFX_FALSE);
#endif /* __USB_TETHERING__ */

    // other settings and info
    VcpFormItemCaption *otherCap;
    VFX_OBJ_CREATE(otherCap, VcpFormItemCaption, m_form);
    otherCap->setText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_OTHER_SETTINGS_AND_INFORMATION));

    // data account cui
    VcpFormItemLauncherCell *launchDataAccount;
    VFX_OBJ_CREATE(launchDataAccount, VcpFormItemLauncherCell, m_form);
    launchDataAccount->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    launchDataAccount->setMainText(VFX_WSTR_RES(STR_GLOBAL_DATA_CONN_SETTING));
    //launchDataAccount->setHintText(VFX_WSTR("USB tethering status"));
    launchDataAccount->m_signalTap.connect(this, &VappTetheringMainScrPage::onItemCellLaunch);

    // connection information
    VcpFormItemLauncherCell *launchConnInfo;
    VFX_OBJ_CREATE(launchConnInfo, VcpFormItemLauncherCell, m_form);
    launchConnInfo->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    launchConnInfo->setMainText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_CONN_INFO));
    //launchConnInfo->setHintText(VFX_WSTR("USB tethering status"));
    launchConnInfo->m_signalTap.connect(this, &VappTetheringMainScrPage::onItemCellLaunch);

    // help
    VcpFormItemLauncherCell *launchHelp;
    VFX_OBJ_CREATE(launchHelp, VcpFormItemLauncherCell, m_form);
    launchHelp->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    launchHelp->setMainText(VFX_WSTR_RES(STR_GLOBAL_HELP));
    //launchConnInfo->setHintText(VFX_WSTR("USB tethering status"));
    launchHelp->m_signalTap.connect(this, &VappTetheringMainScrPage::onItemCellLaunch);

#ifdef __MMI_TETHERING_WIFI__
    m_form->addItem(wifiCap, FORM_ID_WIFI_CAP);
    m_form->addItem(wifiSwitch, FORM_ID_WIFI_SWITCH);
    m_form->addItem(launchWifiSettings, FORM_ID_WIFI_SETTINGS);
    m_form->addItem(autoTurnOffSwitch, FORM_ID_WIFI_AUTO_TURN_OFF);
#endif /* __MMI_TETHERING_WIFI__ */

#ifdef __USB_TETHERING__
    m_form->addItem(usbCap, FORM_ID_USB_CAP);
    m_form->addItem(usbItem, FORM_ID_USB_ITEM);
#endif /* __USB_TETHERING__ */

    m_form->addItem(otherCap, FORM_ID_OTHER_SETTINGS_AND_INFO_CAP);
    m_form->addItem(launchDataAccount, FORM_ID_DATA_ACCOUNT);
    m_form->addItem(launchConnInfo, FORM_ID_CONN_INFO);
    m_form->addItem(launchHelp, FORM_ID_HELP);
}


void VappTetheringMainScrPage::onEnter(VfxBool isBackward)
{
    if (srv_tethering_is_off(SRV_TETHERING_TYPE_USB) == MMI_FALSE)
    {
        VFX_OBJ_CLOSE(m_pwInputPopup);
    }
    redraw();
}


void VappTetheringMainScrPage::onItemCellLaunch(VcpFormItemCell *obj, VfxId id)
{
    switch (id)
    {
        case FORM_ID_WIFI_SETTINGS:
        {
            ((VappTetheringMainScr*)getMainScr())->entryWifiSettingsPage();
            break;
        }

        case FORM_ID_DATA_ACCOUNT:
        {
            ((VappTetheringMainScr*)getMainScr())->entryDtcntCui();
            break;
        }

        case FORM_ID_CONN_INFO:
        {
            ((VappTetheringMainScr*)getMainScr())->entryConnInfoPage();
            break;
        }

        case FORM_ID_HELP:
        {
            ((VappTetheringMainScr*)getMainScr())->entryHelpPage();
            break;
        }

        default:
            break;
    }
}


void VappTetheringMainScrPage::redraw()
{
    srv_tethering_status_enum wifiStatus = srv_tethering_get_status(SRV_TETHERING_TYPE_WIFI_HS);
    srv_tethering_status_enum usbStatus = srv_tethering_get_status(SRV_TETHERING_TYPE_USB);

#ifdef __MMI_TETHERING_WIFI__
    // switch bar
    VcpFormItemSwitchCell *wifiSwitch = (VcpFormItemSwitchCell*)m_form->getItem(FORM_ID_WIFI_SWITCH);
    if (wifiStatus == SRV_TETHERING_STATUS_SRV_OFF)
    {
        wifiSwitch->setSwitchStatus(VFX_FALSE);
    }
    else if (wifiStatus == SRV_TETHERING_STATUS_SRV_ON)
    {
        wifiSwitch->setSwitchStatus(VFX_TRUE);
    }
    else if (wifiStatus == SRV_TETHERING_STATUS_ON_SWITCHING_OFF ||
             wifiStatus == SRV_TETHERING_STATUS_ON_SWITCHING_ON)
    {
        wifiSwitch->showProcessInd();
    }
    MMI_BOOL flag = srv_tethering_check_auto_turn_off_flag();
    VfxBool auto_turn_off_flag = (flag == MMI_TRUE ? VFX_TRUE : VFX_FALSE);
    if (auto_turn_off_flag == VFX_TRUE)
    {
        startCountDown();
    }

    VcpFormItemSwitchCell *autoTurnOffSwitch = (VcpFormItemSwitchCell*)m_form->getItem(FORM_ID_WIFI_AUTO_TURN_OFF);
    autoTurnOffSwitch->setSwitchStatus(auto_turn_off_flag);

    if (usbStatus == SRV_TETHERING_STATUS_SRV_OFF)
    {
        wifiSwitch->setIsDisabled(VFX_FALSE);
    }
    else
    {
        wifiSwitch->setIsDisabled(VFX_TRUE);
    }

    // wifi hotspot settings
    if((wifiStatus == SRV_TETHERING_STATUS_SRV_OFF ||
       wifiStatus == SRV_TETHERING_STATUS_SRV_ON) &&
       usbStatus == SRV_TETHERING_STATUS_SRV_OFF)
    {
        m_form->getItem(FORM_ID_WIFI_SETTINGS)->setIsDisabled(VFX_FALSE);
    }
    else
    {
        m_form->getItem(FORM_ID_WIFI_SETTINGS)->setIsDisabled(VFX_TRUE);
    }

    // wifi auto turn off switch
    if (usbStatus == SRV_TETHERING_STATUS_SRV_OFF)
    {
        m_form->getItem(FORM_ID_WIFI_AUTO_TURN_OFF)->setIsDisabled(VFX_FALSE);
    }
    else
    {
        m_form->getItem(FORM_ID_WIFI_AUTO_TURN_OFF)->setIsDisabled(VFX_TRUE);
    }
#endif /* __MMI_TETHERING_WIFI__ */

    // dtcnt settings
    if (wifiStatus == SRV_TETHERING_STATUS_SRV_OFF &&
        usbStatus == SRV_TETHERING_STATUS_SRV_OFF)
    {
        m_form->getItem(FORM_ID_DATA_ACCOUNT)->setIsDisabled(VFX_FALSE);
    }
    else
    {
        m_form->getItem(FORM_ID_DATA_ACCOUNT)->setIsDisabled(VFX_TRUE);
    }

    // conn info
    if (wifiStatus == SRV_TETHERING_STATUS_SRV_ON ||
        usbStatus == SRV_TETHERING_STATUS_SRV_ON)
    {
        m_form->getItem(FORM_ID_CONN_INFO)->setIsDisabled(VFX_FALSE);
    }
    else
    {
        m_form->getItem(FORM_ID_CONN_INFO)->setIsDisabled(VFX_TRUE);
    }
    
    // usb item
#ifdef __USB_TETHERING__
    VcpFormItemCell *usbItem = (VcpFormItemCell*)m_form->getItem(FORM_ID_USB_ITEM);
    
    switch (usbStatus)
    {
        case SRV_TETHERING_STATUS_SRV_OFF:
        {
            usbItem->setHintText(VFX_WSTR_RES(STR_ID_VAPP_TETHERING_USB_PROMPT_PLUG_IN));
            break;
        }

        case SRV_TETHERING_STATUS_SRV_ON:
        {
            usbItem->setHintText(VFX_WSTR_RES(STR_ID_VAPP_TETHERING_USB_PROMPT_PLUG_OUT));
            break;
        }

        case SRV_TETHERING_STATUS_ON_SWITCHING_OFF:
        case SRV_TETHERING_STATUS_ON_SWITCHING_ON:
        {
            m_form->getItem(FORM_ID_CONN_INFO)->setIsDisabled(VFX_TRUE);
        }

        default:
            break;
    }
#endif /* __USB_TETHERING__ */
}


void VappTetheringMainScrPage::switchCnfHdlr(srv_tethering_type_enum tetheringType, VfxBool result, srv_tethering_status_enum desStatus)
{
#ifdef __MMI_TETHERING_WIFI__
    if (tetheringType == SRV_TETHERING_TYPE_WIFI_HS)
    {
        if (isActive() == MMI_TRUE)
        {
            VcpFormItemSwitchCell *wifiSwitch = (VcpFormItemSwitchCell*)m_form->getItem(FORM_ID_WIFI_SWITCH);
            wifiSwitch->hideProcessInd();

            startCountDown();
            if (result == VFX_FALSE)
            {
                VcpConfirmPopup *cnfPopup;
                VFX_OBJ_CREATE(cnfPopup, VcpConfirmPopup, this);

                cnfPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
                cnfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
                cnfPopup->setText(VFX_WSTR_RES(STR_GLOBAL_FAILED));
                cnfPopup->show(VFX_TRUE);
            }
        }
    }
#endif /* __MMI_TETHERING_WIFI__ */

    ((VappTetheringMainScr*)getMainScr())->exitDtcntCui();

    if (isActive() == MMI_TRUE)
    {
        redraw();
    }
}


void VappTetheringMainScrPage::connInfoHdlr(
    srv_tethering_type_enum tetheringType,
    void *infoData)
{
#ifdef __MMI_TETHERING_WIFI__
    if (tetheringType == SRV_TETHERING_TYPE_WIFI_HS)
    {
        mmi_abm_hotspot_info_struct *hotspot_info = (mmi_abm_hotspot_info_struct*)infoData;
        if (hotspot_info->sta_num == 0)
        {
            startCountDown();
        }
        else
        {
            stopCountDown();
        }
    }
#endif /* __MMI_TETHERING_WIFI__ */
}


#ifdef __MMI_TETHERING_WIFI__
void VappTetheringMainScrPage::wifiSwitchReqHdlr(
    VcpFormItemSwitchCell* sender,
    VfxId senderId,
    VfxBool desState)
{
    if (srv_tethering_is_switching(SRV_TETHERING_TYPE_WIFI_HS))
    {
        return;
    }
    wifiSwitchProcess(desState);
}


VfxBool VappTetheringMainScrPage::wifiSwitchCheck()
{
    // check data account valid
    srv_dtcnt_sim_type_enum simType;
    srv_dtcnt_get_sim_preference(&simType);
    VfxU32 accountId = srv_tethering_get_dtcnt(simType);
    if (srv_tethering_check_launch_capab_acct(SRV_TETHERING_TYPE_WIFI_HS, accountId) == SRV_TETHERING_LAUNCH_RESULT_INVALID_ACCOUNT)
    {
        VcpConfirmPopup *cnfPopup;
        VFX_OBJ_CREATE(cnfPopup, VcpConfirmPopup, this);
        cnfPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        cnfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
        cnfPopup->setText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_INVALID_DATA_ACCOUNT));
        cnfPopup->show(VFX_TRUE);

        return VFX_FALSE;
    }
    else if (srv_tethering_check_launch_capab_nw(mmi_frm_index_to_sim(simType - 1)) != SRV_TETHERING_LAUNCH_RESULT_OK)
    {
        VcpConfirmPopup *cnfPopup;
        VFX_OBJ_CREATE(cnfPopup, VcpConfirmPopup, this);
        cnfPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        cnfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
        cnfPopup->setText(VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE));
        cnfPopup->show(VFX_TRUE);

        return VFX_FALSE;
    }
#ifdef __USB_TETHERING__
    else if (srv_tethering_get_status(SRV_TETHERING_TYPE_USB) == SRV_TETHERING_STATUS_SRV_ON)
    {
        VcpConfirmPopup *cnfPopup;
        VFX_OBJ_CREATE(cnfPopup, VcpConfirmPopup, this);
        cnfPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        cnfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
        cnfPopup->setText(VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE));
        cnfPopup->show(VFX_TRUE);

        return VFX_FALSE;
    }
#endif
    srv_tethering_wifi_hs_settings_struct curr_settings;
    srv_tethering_wifi_hs_get_settings(&curr_settings);
    // first use and input the psk
    if (strlen((const char*)curr_settings.psk) < HOSTAP_PSK_MIN_LEN &&
        curr_settings.auth_mode == SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK)
    {
        VFX_OBJ_CREATE(m_pwInputPopup, VcpInputPopup, this);
        m_pwInputPopup->setTitle(VFX_WSTR_RES(STR_ID_VAPP_TETHERING_WIFI_SET_PASSWORD));
        m_pwInputPopup->setGroupNum(PASSWORD_TOTAL);
    
        m_pwInputPopup->setText(
            VFX_WSTR_EMPTY,
            HOSTAP_PSK_MAX_LEN,
            VFX_FALSE,
            PASSWORD_NEW);
        m_pwInputPopup->setIME(
            IMM_INPUT_TYPE_ASCII_PASSWORD,
            IME_SETTING_FLAG_NONE,
            PASSWORD_NEW);
        m_pwInputPopup->setHintText(
            VFX_WSTR_RES(STR_ID_VAPP_TETHERING_WIFI_NEW_PASSWORD),
            PASSWORD_NEW);

        m_pwInputPopup->setText(
            VFX_WSTR_EMPTY,
            HOSTAP_PSK_MAX_LEN,
            VFX_FALSE,
            PASSWORD_NEW_CONFIRM);
        m_pwInputPopup->setIME(
            IMM_INPUT_TYPE_ASCII_PASSWORD,
            IME_SETTING_FLAG_NONE,
            PASSWORD_NEW_CONFIRM);
        m_pwInputPopup->setHintText(
            VFX_WSTR_RES(STR_ID_VAPP_TETHERING_WIFI_CONFIRM_PASSWORD),
            PASSWORD_NEW_CONFIRM);

        m_pwInputPopup->m_signalButtonClicked.connect(
            this,
            &VappTetheringMainScrPage::pwInputPopupBtnClickHdlr);
        m_pwInputPopup->show(VFX_TRUE);
        return VFX_FALSE;
    }

    if ((srv_dtcnt_wlan_state() != SRV_DTCNT_WLAN_STATE_NULL) &&
        runTurnOffWlanFlag == VFX_FALSE)
    {
        VcpConfirmPopup *cnfPopup;
        VFX_OBJ_CREATE(cnfPopup, VcpConfirmPopup, this);
    
        cnfPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
        cnfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);   
        cnfPopup->setText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_TURN_OFF_WLAN_CNF));
        cnfPopup->setCustomButton(
            VFX_WSTR_RES(STR_GLOBAL_OK),
            VFX_WSTR_RES(STR_GLOBAL_CANCEL),
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            VCP_POPUP_BUTTON_TYPE_CANCEL);
        cnfPopup->m_signalButtonClicked.connect(this, &VappTetheringMainScrPage::turnOffWlanCnfHdlr);
        cnfPopup->show(VFX_TRUE);

        return VFX_FALSE;
    }

    runTurnOffWlanFlag = VFX_FALSE;
    // check pass
    return VFX_TRUE;
}


void VappTetheringMainScrPage::pwInputPopupBtnClickHdlr(VfxObject* sender, VcpInputPopupButtonEnum id)
{
    VfxWString pwNew;
    VfxWString pwNewCfn;
    switch (id)
    {
        case VCP_INPUT_POPUP_BTN_OK:
        {
            pwNew = m_pwInputPopup->getText(PASSWORD_NEW);
            pwNewCfn = m_pwInputPopup->getText(PASSWORD_NEW_CONFIRM);
            VfxBool validFlag = VFX_TRUE;

            if (pwNew.getLength() < HOSTAP_PSK_MIN_LEN)
            {
                m_pwInputPopup->setErrorText(
                    VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_PW_LENGTH_WARNING_SHORT),
                    PASSWORD_NEW);
                validFlag = VFX_FALSE;
            }
            else
            {
                m_pwInputPopup->setErrorText(VFX_WSTR_EMPTY, PASSWORD_NEW);
            }

            if (pwNew != pwNewCfn)
            {
                m_pwInputPopup->setErrorText(
                    VFX_WSTR_RES(STR_ID_VAPP_TETHERING_WIFI_PASSWORD_UNMATCH_WARNING),
                    PASSWORD_NEW_CONFIRM);
                validFlag = VFX_FALSE;
            }
            else
            {
                m_pwInputPopup->setErrorText(VFX_WSTR_EMPTY, PASSWORD_NEW_CONFIRM);
            }

            if (validFlag == VFX_TRUE)
            {
                VFX_OBJ_CLOSE(m_pwInputPopup);

                srv_tethering_wifi_hs_settings_struct curr_settings;
                srv_tethering_wifi_hs_get_settings(&curr_settings);

                mmi_wcs_to_asc((CHAR*)curr_settings.psk, (WCHAR*)pwNew.getBuf());
                srv_tethering_wifi_hs_save_settings(&curr_settings);

                wifiSwitchProcess(VFX_TRUE);
            }
            break;
        }

        case VCP_INPUT_POPUP_BTN_CANCEL:
        {
            VFX_OBJ_CLOSE(m_pwInputPopup);
            break;
        }

        default:
            break;
    }
}


void VappTetheringMainScrPage::turnOffWlanCnfHdlr(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1: // OK
        {
            runTurnOffWlanFlag = VFX_TRUE;
            wifiSwitchProcess(VFX_TRUE);
            break;
        }

        case VCP_CONFIRM_POPUP_BUTTON_USER_2: // CANCEL
        case VCP_POPUP_BUTTON_NO_PRESSED:
            break;

        default:
            break;
    }
}


void VappTetheringMainScrPage::wifiSwitchProcess(VfxBool desState)
{
    if (wifiSwitchCheck() == VFX_FALSE)
    {
        runTurnOffWlanFlag = VFX_FALSE;
        return;
    }
    m_form->getItem(FORM_ID_WIFI_SETTINGS)->setIsDisabled(VFX_TRUE);
    m_form->getItem(FORM_ID_DATA_ACCOUNT)->setIsDisabled(VFX_TRUE);
    m_form->getItem(FORM_ID_CONN_INFO)->setIsDisabled(VFX_TRUE);

    VcpFormItemSwitchCell *wifiSwitch = (VcpFormItemSwitchCell*)m_form->getItem(FORM_ID_WIFI_SWITCH);
    wifiSwitch->showProcessInd();

    stopCountDown();

    if (desState == VFX_TRUE)
    {
        vappTetheringConfigConnInfo();
        srv_tethering_reg_reactivate_demand_cb_hdlr(
            SRV_TETHERING_TYPE_WIFI_HS,
            VappTetheringEvtListener::reactivateDemandHdlr);

        srv_tethering_switch_cb_funcptr_type funcPtr =
            (srv_tethering_switch_cb_funcptr_type)(VappTetheringEvtListener::switchCnfHdlr);
        srv_tethering_switch_on(SRV_TETHERING_TYPE_WIFI_HS, funcPtr, this);
    }
    else
    {
        srv_tethering_switch_cb_funcptr_type funcPtr =
            (srv_tethering_switch_cb_funcptr_type)(VappTetheringEvtListener::switchCnfHdlr);
        srv_tethering_switch_off(SRV_TETHERING_TYPE_WIFI_HS, funcPtr, this);
    }
}


void VappTetheringMainScrPage::autoTurnOffSwitchReqHdlr(
    VcpFormItemSwitchCell* sender,
    VfxId senderId,
    VfxBool desState)
{
    srv_tethering_enable_auto_turn_off((MMI_BOOL)desState);
    if (desState == VFX_TRUE)
    {
        startCountDown();
        sender->setSwitchStatus(VFX_TRUE);
    }
    else
    {
        stopCountDown();
        sender->setSwitchStatus(VFX_FALSE);
    }
}


void VappTetheringMainScrPage::startCountDown()
{
    if (srv_tethering_get_status(SRV_TETHERING_TYPE_WIFI_HS) == SRV_TETHERING_STATUS_SRV_ON &&
        srv_tethering_check_auto_turn_off_flag() == MMI_TRUE &&
        srv_tethering_get_sta_num(SRV_TETHERING_TYPE_WIFI_HS) == 0)
    {
        updateCountDown();

        VFX_OBJ_CREATE(m_CountDownTimer, VfxTimer, this);
        m_CountDownTimer->setDuration(1000);
        m_CountDownTimer->m_signalTick.connect(this, &VappTetheringMainScrPage::countDownSinalTick);
        m_CountDownTimer->start();
    }
}


void VappTetheringMainScrPage::stopCountDown()
{
    VcpFormItemSwitchCell *wifiSwitch = (VcpFormItemSwitchCell*)m_form->getItem(FORM_ID_WIFI_SWITCH);
    if (wifiSwitch->getHintText() != VFX_WSTR_EMPTY &&
        wifiSwitch->getHintText() != VFX_WSTR_NULL)
    {
        wifiSwitch->setHintText(VFX_WSTR_EMPTY);
        //wifiSwitch->checkUpdate();
        //wifiSwitch->processUpdate();
    }

    if (m_CountDownTimer != NULL)
    {
        m_CountDownTimer->stop();
    }
    m_CountDownTimer = NULL;
}


void VappTetheringMainScrPage::updateCountDown()
{
    VfxS32 remainingTime = srv_tethering_auto_turn_off_get_remaining_time();

    if (remainingTime > 0 &&
        srv_tethering_check_auto_turn_off_flag() == MMI_TRUE)
    {
        VfxWString countDownText;
        VfxWChar time[32];
        mmi_wcs_itow((S32)remainingTime, (WCHAR*)time, 10);
        countDownText = VFX_WSTR_RES(STR_ID_VAPP_TETHERING_WIFI_AUTO_TURN_OFF_COUNTDOWN);
        countDownText += VFX_WSTR_MEM(time);

        VcpFormItemSwitchCell *wifiSwitch = (VcpFormItemSwitchCell*)m_form->getItem(FORM_ID_WIFI_SWITCH);
        wifiSwitch->setHintText(countDownText);
    }
    else
    {
        stopCountDown();
    }
}


void VappTetheringMainScrPage::countDownSinalTick(VfxTimer *timer)
{
    if (timer == m_CountDownTimer)
    {
        updateCountDown();
    }
}
#endif /* __MMI_TETHERING_WIFI__ */


#ifdef __MMI_TETHERING_WIFI__
VFX_IMPLEMENT_CLASS("VappTetheringWifiHsSettingsPage", VappTetheringWifiHsSettingsPage, VfxPage);
void VappTetheringWifiHsSettingsPage::onInit()
{
    VfxPage::onInit();

    srv_tethering_wifi_hs_settings_struct curr_settings;
    srv_tethering_wifi_hs_get_settings(&curr_settings);

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_HS_SETTINGS));
    setTopBar(bar);

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->addItem(TOOLBAR_ITEM_SAVE, VFX_WSTR_RES(VCP_STR_TOOL_BAR_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    m_toolBar->addItem(TOOLBAR_ITEM_CANCEL, VFX_WSTR_RES(VCP_STR_TOOL_BAR_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect(this, &VappTetheringWifiHsSettingsPage::toolbarEventHdlr);
    setBottomBar(m_toolBar);

    // Init form
    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setPos(0,0);
    m_form->setBounds(VfxRect(VfxPoint(0, 0), getSize()));
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VFX_OBJ_CREATE(m_funcBar, VcpFunctionBar, this);
    m_funcBar->addItem(FUNCBAR_ITEM_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE));
    m_funcBar->m_signalButtonTap.connect(this, &VappTetheringWifiHsSettingsPage::funcbarEventHdlr);
    m_funcBar->setItemSpecial(FUNCBAR_ITEM_SAVE);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    // Form item ssid editor
    VcpFormItemTextInput *nwSsidEditor;
    VFX_OBJ_CREATE(nwSsidEditor, VcpFormItemTextInput, m_form);
    //nwSsidEditor->setText(VFX_WSTR("DefaultID"));
    nwSsidEditor->setLabelPosition(VCPFORM_TOP_LEFT);
    nwSsidEditor->setLabelText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_HS_SSID));
    VfxWChar wSsid[SRV_TETHERING_HOSTAP_SSID_MAX_BUF_LEN];
    mmi_chset_utf8_to_ucs2_string(
        (kal_uint8*)wSsid,
        SRV_TETHERING_HOSTAP_SSID_MAX_BUF_LEN * 2,
        (kal_uint8*)curr_settings.ssid);
    nwSsidEditor->getTextBox()->setText(
        wSsid,
        HOSTAP_SSID_MAX_LEN,
        VFX_FALSE,
        VCP_TEXT_ENCODING_UTF8);
    nwSsidEditor->getTextBox()->setIME(IMM_INPUT_TYPE_SENTENCE);
    //nwSsidEditor->getTextBox()->m_signalTextChanged.connect(this, &VappTetheringWifiHsSettingsPage::ssidEditorChangedHdlr);
    nwSsidEditor->getTextBox()->setFunctionBar(m_funcBar, VFX_FALSE);

    // Form item security button
    m_tempAuthMode = curr_settings.auth_mode;
    VcpFormItemBigButton *securityTypeBtn;
    VFX_OBJ_CREATE(securityTypeBtn, VcpFormItemBigButton, m_form);
    securityTypeBtn->setButtonText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_HS_AUTH_MODE));
    if (m_tempAuthMode == SRV_TETHERING_WIFI_HS_AUTH_MODE_OPEN)
    {
        securityTypeBtn->setHintText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_HS_AUTH_MODE_OPEN));
    }
    else if (m_tempAuthMode == SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK)
    {
        securityTypeBtn->setHintText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK));
    }
    securityTypeBtn->getButton()->m_signalClicked.connect(this, &VappTetheringWifiHsSettingsPage::securityBtnEventHandler);

    // Form item password editor
    VcpFormItemTextInput *pwEditor = NULL;
    if (m_tempAuthMode == SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK)
    {
        VFX_OBJ_CREATE(pwEditor, VcpFormItemTextInput, m_form);
        pwEditor->setLabelPosition(VCPFORM_TOP_LEFT);
        pwEditor->setLabelText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_PW_CAPTION));
        VfxWChar wPassword[SRV_TETHERING_HOSTAP_PSK_MAX_BUF_LEN];
        mmi_asc_to_wcs(wPassword, (CHAR*)curr_settings.psk);
        pwEditor->getTextBox()->setText(wPassword, HOSTAP_PSK_MAX_LEN);
        pwEditor->getTextBox()->setIME(IMM_INPUT_TYPE_ASCII_PASSWORD);
        //pwEditor->getTextBox()->m_signalTextChanged.connect(this, &VappTetheringWifiHsSettingsPage::pwEditorChangedHdlr);
        //VfxU32 pwLen = mmi_wcslen(wPassword);
        pwEditor->getTextBox()->setFunctionBar(m_funcBar, VFX_FALSE);
        //m_toolBar->setDisableItem(TOOLBAR_ITEM_SAVE, (VfxBool)(pwLen < HOSTAP_PSK_MIN_LEN));
    }

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
#endif
    //m_form->addItem(hsSettingsCap, WIFI_HS_SETTINGS_CAPTION);
    m_form->addItem(nwSsidEditor, NETWORK_SSID_EDITOR);
    m_form->addItem(securityTypeBtn, SECURITY_TYPE_BUTTON);

    if (m_tempAuthMode == SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK)
    {
        m_form->addItem(pwEditor, PASSWORD_EDITOR);
    }
}


void VappTetheringWifiHsSettingsPage::onDeinit()
{
    // should manuly close functionbar if set autoClose false in setFunctionBar
    VFX_OBJ_CLOSE(m_funcBar);
    VfxPage::onDeinit();
}


void VappTetheringWifiHsSettingsPage::saveHdlr()
{
    saveSettings();
    
    // display a waiting popup and update the settings.
    //VFX_OBJ_CREATE(m_updateIndicatorPopup, VcpIndicatorPopup, this);
    //m_updateIndicatorPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    //m_updateIndicatorPopup->setText(VFX_WSTR("Activating"));
    //m_updateIndicatorPopup->show(VFX_TRUE);
    if (srv_tethering_get_status(SRV_TETHERING_TYPE_WIFI_HS) == SRV_TETHERING_STATUS_SRV_ON)
    {
        ((VappTetheringMainScr*)getMainScr())->updataSettingsReq(SRV_TETHERING_TYPE_WIFI_HS);
    }
}


VfxBool VappTetheringWifiHsSettingsPage::checkSettingValid()
{
    VfxBool validFlag = VFX_TRUE;

    // check ssid empty
    VcpFormItemTextInput *ssidEditor = (VcpFormItemTextInput*)m_form->getItem(NETWORK_SSID_EDITOR);
    VfxU32 ssidLen = ((VfxWString)ssidEditor->getText()).getLength();
    if (ssidLen == 0)
    {
        validFlag = VFX_FALSE;
        ssidEditor->setWarningText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_SSID_EMPTY_WARNING));
        m_form->scrollItemToView(NETWORK_SSID_EDITOR, VCPFORM_SCROLL_TOP);
    }
    else
    {
        ssidEditor->setWarningText(VFX_WSTR_EMPTY);
        m_form->scrollItemToView(NETWORK_SSID_EDITOR, VCPFORM_SCROLL_TOP);
    }

    // check password at least 8 char
    if (m_tempAuthMode == SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK)
    {
        VcpFormItemTextInput *pwEditor = (VcpFormItemTextInput*)m_form->getItem(PASSWORD_EDITOR);
        VfxU32 pwLen = ((VfxWString)pwEditor->getText()).getLength();
        if (pwLen < HOSTAP_PSK_MIN_LEN)
        {
            validFlag = VFX_FALSE;
            pwEditor->setWarningText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_PW_LENGTH_WARNING_SHORT));
            m_form->scrollItemToView(PASSWORD_EDITOR, VCPFORM_SCROLL_TOP);
        }
        else
        {
            pwEditor->setWarningText(VFX_WSTR_EMPTY);
            m_form->scrollItemToView(PASSWORD_EDITOR, VCPFORM_SCROLL_TOP);
        }
    }

    return validFlag;
}


void VappTetheringWifiHsSettingsPage::saveSettings()
{
    srv_tethering_wifi_hs_settings_struct curr_settings;
    srv_tethering_wifi_hs_get_settings(&curr_settings);
    //memset(&curr_settings, 0x00, sizeof(srv_tethering_wifi_hs_settings_struct));

    curr_settings.auth_mode = m_tempAuthMode;

    VfxWChar wSsid[SRV_TETHERING_HOSTAP_SSID_MAX_BUF_LEN];
    mmi_wcscpy(
        wSsid,
        ((VcpFormItemTextInput*)(m_form->getItem(NETWORK_SSID_EDITOR)))->getText().getBuf());
    mmi_chset_ucs2_to_utf8_string(
        (kal_uint8*)curr_settings.ssid,
        SRV_TETHERING_HOSTAP_SSID_MAX_BUF_LEN,
        (kal_uint8*)wSsid);

    if (curr_settings.auth_mode == SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK)
    {
        VfxWChar wPassword[SRV_TETHERING_HOSTAP_PSK_MAX_BUF_LEN];
        mmi_wcscpy(
            wPassword,
            ((VcpFormItemTextInput*)(m_form->getItem(PASSWORD_EDITOR)))->getText().getBuf());
        mmi_wcs_to_asc((CHAR*)curr_settings.psk, wPassword);
    }
    srv_tethering_wifi_hs_save_settings(&curr_settings);
}


void VappTetheringWifiHsSettingsPage::toolbarEventHdlr(VfxObject* obj, VfxId itemId)
{
    switch (itemId)
    {
        case TOOLBAR_ITEM_SAVE:
        {
            if (checkSettingValid() == VFX_TRUE)
            {
                saveHdlr();
                exit();
            }
            break;
        }

        case TOOLBAR_ITEM_CANCEL:
        {
            exit();
            break;
        }

        default:
            break;
    }
}


void VappTetheringWifiHsSettingsPage::funcbarEventHdlr(VfxObject* obj, VfxId itemId)
{
    switch (itemId)
    {
        case FUNCBAR_ITEM_SAVE:
        {
            if (checkSettingValid() == VFX_TRUE)
            {
                saveHdlr();
                exit();
            }
            break;
        }

        default:
            break;
    }
}


void VappTetheringWifiHsSettingsPage::securityBtnEventHandler(VfxObject* obj, VfxId itemId)
{
    VcpSelectPopup *selPopup;
    VFX_OBJ_CREATE(selPopup, VcpSelectPopup, this);
    selPopup->setType(VCP_SELECT_POPUP_BUTTON_TYPE_QUICK);
    selPopup->setText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_HS_AUTH_MODE));
    selPopup->addItem(
        SRV_TETHERING_WIFI_HS_AUTH_MODE_OPEN,
        VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_HS_AUTH_MODE_OPEN),
        (VfxBool)(m_tempAuthMode == SRV_TETHERING_WIFI_HS_AUTH_MODE_OPEN));
    selPopup->addItem(
        SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK,
        VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK),
        (VfxBool)(m_tempAuthMode == SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK));
    selPopup->m_signalButtonClicked.connect(this, &VappTetheringWifiHsSettingsPage::selPopupClickHdlr);
    selPopup->m_signalPopupState.connect(this, &VappTetheringWifiHsSettingsPage::selPopupStateChangeHdlr);
    selPopup->show(VFX_TRUE);
}


void VappTetheringWifiHsSettingsPage::selPopupClickHdlr(VfxObject* obj, VfxId itemId)
{
    
}


void VappTetheringWifiHsSettingsPage::selPopupStateChangeHdlr(VfxBasePopup* obj, VfxBasePopupStateEnum state)
{
    if (state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {
        VcpSelectPopup *selPopup = (VcpSelectPopup*)obj;
        m_tempAuthMode = (srv_tethering_wifi_hs_auth_mode_enum)selPopup->getFirstSeletedId();
        VcpFormItemBigButton *securityTypeBtn = (VcpFormItemBigButton*)m_form->getItem(SECURITY_TYPE_BUTTON);
        if (m_tempAuthMode == SRV_TETHERING_WIFI_HS_AUTH_MODE_OPEN)
        {
            securityTypeBtn->setHintText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_HS_AUTH_MODE_OPEN));
        }
        else if (m_tempAuthMode == SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK)
        {
            securityTypeBtn->setHintText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK));
        }

        //m_toolBar->setDisableItem(TOOLBAR_ITEM_SAVE, VFX_FALSE);

        switch (m_tempAuthMode)
        {
            case SRV_TETHERING_WIFI_HS_AUTH_MODE_OPEN:
            {
                if (m_form->getItem(PASSWORD_EDITOR) != NULL)
                {
                    m_form->removeItem(PASSWORD_EDITOR);
                }
                break;
            }

            case SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK:
            {
                if (m_form->getItem(PASSWORD_EDITOR) == NULL)
                {
                    srv_tethering_wifi_hs_settings_struct curr_settings;
                    srv_tethering_wifi_hs_get_settings(&curr_settings);
                    // Form item password editor
                    VcpFormItemTextInput *pwEditor;
                    VFX_OBJ_CREATE(pwEditor, VcpFormItemTextInput, m_form);
                    pwEditor->setLabelPosition(VCPFORM_TOP_LEFT);
                    pwEditor->setLabelText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_PW_CAPTION));
                    VfxWChar wPassword[SRV_TETHERING_HOSTAP_PSK_MAX_BUF_LEN];
                    mmi_asc_to_wcs(wPassword, (CHAR*)curr_settings.psk);
                    pwEditor->getTextBox()->setText(wPassword, HOSTAP_PSK_MAX_LEN);
                    pwEditor->getTextBox()->setIME(IMM_INPUT_TYPE_ASCII_PASSWORD);
                    //pwEditor->getTextBox()->m_signalTextChanged.connect(this, &VappTetheringWifiHsSettingsPage::pwEditorChangedHdlr);
                    VfxU32 pwLen = mmi_wcslen(wPassword);
                    //m_toolBar->setDisableItem(TOOLBAR_ITEM_SAVE, (VfxBool)(pwLen < HOSTAP_PSK_MIN_LEN));

                    //m_funcBar->addItem(FUNCBAR_ITEM_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE));
                    pwEditor->getTextBox()->setFunctionBar(m_funcBar, VFX_FALSE);
                    //m_funcBar->setItemSpecial(FUNCBAR_ITEM_SAVE);

                    m_form->addItem(
                        pwEditor,
                        PASSWORD_EDITOR);
                }
                break;
            }

            default:
                break;
        }
    }
}
#endif /* __MMI_TETHERING_WIFI__ */


VFX_IMPLEMENT_CLASS("VappTetheringConnInfoPage", VappTetheringConnInfoPage, VfxPage);
void VappTetheringConnInfoPage::onInit()
{
    VfxPage::onInit();

    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringConnInfo.connect(this, &VappTetheringConnInfoPage::connInfoHdlr);
    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringDisconnect.connect(this, &VappTetheringConnInfoPage::disconnectHdlr);
    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringSwitchCnf.connect(this, &VappTetheringConnInfoPage::switchCnfHdlr);

    setStatusBar(VFX_TRUE);
    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_ID_SRV_TETHERING_CONN_INFO));
    setTopBar(bar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setPos(0,0);
    m_form->setBounds(VfxRect(VfxPoint(0, 0), getSize()));
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    //VappTetheringConnInfoTextItem *usedSimTxt;
    //VFX_OBJ_CREATE(usedSimTxt, VappTetheringConnInfoTextItem, m_form);
    //usedSimTxt->
    srv_tethering_conn_info_struct conn_info;
    srv_tethering_get_conn_info(&conn_info);

#if (MMI_MAX_SIM_NUM >= 2)
    // currently used sim
    VcpFormItemCell *usedSimItem;
    VFX_OBJ_CREATE(usedSimItem, VcpFormItemCell, m_form);
    usedSimItem->setMainText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_CONN_INFO_CURR_USED_SIM));
    VfxWChar *usedSimStr = NULL;
    MMI_STR_ID strId = STR_GLOBAL_SIM_1;
    // damn, the sim string index is not continuous...
    switch (conn_info.used_sim)
    {
        case CBM_SIM_ID_SIM1:
            strId = STR_GLOBAL_SIM_1;
            break;

        case CBM_SIM_ID_SIM2:
            strId = STR_GLOBAL_SIM_2;
            break;

        case CBM_SIM_ID_SIM3:
            strId = STR_GLOBAL_SIM_3;
            break;

        case CBM_SIM_ID_SIM4:
            strId = STR_GLOBAL_SIM_4;
            break;

        default:
            ASSERT(0);
            break;
    }
    usedSimStr = (VfxWChar*)GetString(strId);
    usedSimItem->setHintText(VFX_WSTR_STATIC(usedSimStr));
    usedSimItem->setIsTappable(VFX_FALSE);
#endif

    // apn
    VcpFormItemCell *apnItem;
    VFX_OBJ_CREATE(apnItem, VcpFormItemCell, m_form);
    apnItem->setMainText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_CONN_INFO_APN));

    VfxWChar apnStr[SRV_DTCNT_PROF_MAX_APN_LEN + 1];
    srv_tethering_get_used_dtcnt_apn(
        apnStr,
        SRV_DTCNT_PROF_MAX_APN_LEN + 1);
    apnItem->setHintText(VFX_WSTR_MEM(apnStr));
    apnItem->setIsTappable(VFX_FALSE);

    // proxy
    VfxBool useProxy = VFX_FALSE;
    
    VcpFormItemLauncherCell *proxyItem = NULL;
    srv_dtcnt_prof_proxy_info_struct dtcntProxyInfo;

    if (MMI_TRUE == srv_dtcnt_get_proxy_info(
                        srv_tethering_get_used_dtcnt(),
                        &dtcntProxyInfo,
                        SRV_DTCNT_ACCOUNT_PRIMARY) && dtcntProxyInfo.use_proxy)
    {
        useProxy = VFX_TRUE;
        VFX_OBJ_CREATE(proxyItem, VcpFormItemLauncherCell, m_form);
        proxyItem->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        proxyItem->setMainText(VFX_WSTR_RES(STR_GLOBAL_PROXY));
        proxyItem->m_signalTap.connect(this, &VappTetheringConnInfoPage::onItemCellLaunch);
    }

#ifdef __MMI_TETHERING_WIFI__
    // wifi caption
    VcpFormItemCaption *wifiCap;
    VFX_OBJ_CREATE(wifiCap, VcpFormItemCaption, m_form);
    wifiCap->setText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_HS));

    // wifi status
    VcpFormItemCell *wifiStatus;
    VFX_OBJ_CREATE(wifiStatus, VcpFormItemCell, m_form);
    wifiStatus->setMainText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_HS));
    if (srv_tethering_is_on(SRV_TETHERING_TYPE_WIFI_HS) == MMI_TRUE)
    {
        wifiStatus->setHintText(VFX_WSTR_RES(STR_GLOBAL_ON));
    }
    else
    {
        wifiStatus->setHintText(VFX_WSTR_RES(STR_GLOBAL_OFF));
    }
    wifiStatus->setIsTappable(VFX_FALSE);

    // wifi station number
    VcpFormItemCell *connNumItem;
    VFX_OBJ_CREATE(connNumItem, VcpFormItemCell, m_form);
    connNumItem->setMainText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_CONN_INFO_STA_NUM));
    VfxWChar staNumStr[32];
    VfxChar temp[32];
    VfxU8 staNum = srv_tethering_get_sta_num(SRV_TETHERING_TYPE_WIFI_HS);
    sprintf(temp, "%d", staNum);
    mmi_asc_to_wcs(staNumStr, temp);
    connNumItem->setHintText(VFX_WSTR_MEM(staNumStr));
    connNumItem->setIsTappable(VFX_FALSE);
#endif /* __MMI_TETHERING_WIFI__ */

#ifdef __USB_TETHERING__
    // usb caption
    VcpFormItemCaption *usbCap;
    VFX_OBJ_CREATE(usbCap, VcpFormItemCaption, m_form);
    usbCap->setText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_USB));

    // usb status
    VcpFormItemCell *usbStatus;
    VFX_OBJ_CREATE(usbStatus, VcpFormItemCell, m_form);
    usbStatus->setMainText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_USB));
    if (srv_tethering_is_on(SRV_TETHERING_TYPE_USB) == MMI_TRUE)
    {
        usbStatus->setHintText(VFX_WSTR_RES(STR_GLOBAL_ON));
    }
    else
    {
        usbStatus->setHintText(VFX_WSTR_RES(STR_GLOBAL_OFF));
    }
    usbStatus->setIsTappable(VFX_FALSE);
#endif /* __USB_TETHERING__ */

#if (MMI_MAX_SIM_NUM >= 2)
    m_form->addItem(usedSimItem, FORM_ID_USED_SIM);
#endif /* MMI_MAX_SIM_NUM >= 2 */
    m_form->addItem(apnItem, FORM_ID_APN);
    if (useProxy == VFX_TRUE)
    {
        m_form->addItem(proxyItem, FORM_ID_PROXY);
    }

#ifdef __MMI_TETHERING_WIFI__
    m_form->addItem(wifiCap, FORM_ID_WIFI_CAP);
    m_form->addItem(wifiStatus, FORM_ID_WIFI_STATUS);
    m_form->addItem(connNumItem, FORM_ID_CONN_NUM);
#endif /* __MMI_TETHERING_WIFI__ */

#ifdef __USB_TETHERING__
    m_form->addItem(usbCap, FORM_ID_USB_CAP);
    m_form->addItem(usbStatus, FORM_ID_USB_STATUS);
#endif /* __USB_TETHERING__ */
}

void VappTetheringConnInfoPage::onItemCellLaunch(VcpFormItemCell *obj, VfxId id)
{
    switch (id)
    {
        case FORM_ID_PROXY:
        {
            ((VappTetheringMainScr*)getMainScr())->entryProxyInfoPage();
            break;
        }

        default:
            break;
    }
}

void VappTetheringConnInfoPage::connInfoHdlr(
    srv_tethering_type_enum tetheringType,
    void *infoData)
{
    if (isActive() == VFX_TRUE)
    {
        updateInfo(tetheringType, infoData);
    }
}


void VappTetheringConnInfoPage::updateInfo(
    srv_tethering_type_enum tetheringType,
    void *infoData)
{
    switch (tetheringType)
    {
        case SRV_TETHERING_TYPE_WIFI_HS:
        {
            mmi_abm_hotspot_info_struct *hotspot_info = (mmi_abm_hotspot_info_struct*)infoData;
            VfxWChar staNumStr[32];
            VfxChar temp[32];
            sprintf(temp, "%d", hotspot_info->sta_num);
            mmi_asc_to_wcs(staNumStr, temp);
            VcpFormItemCell *connNumItem = (VcpFormItemCell*)m_form->getItem(FORM_ID_CONN_NUM);
            connNumItem->setHintText(VFX_WSTR_MEM(staNumStr));
            break;
        }

        default:
            break;
    }
}


void VappTetheringConnInfoPage::disconnectHdlr(
    srv_tethering_type_enum tetheringType,
    srv_tethering_disconn_cause_enum cause)
{
    exit();
}


void VappTetheringConnInfoPage::switchCnfHdlr(srv_tethering_type_enum tetheringType, VfxBool result, srv_tethering_status_enum desStatus)
{
    if (desStatus == SRV_TETHERING_STATUS_SRV_OFF)
    {
        exit();
    }
}


VFX_IMPLEMENT_CLASS("VappTetheringProxyInfoPage", VappTetheringProxyInfoPage, VfxPage);
void VappTetheringProxyInfoPage::onInit()
{
    VfxPage::onInit();

    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringDisconnect.connect(this, &VappTetheringProxyInfoPage::disconnectHdlr);
    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringSwitchCnf.connect(this, &VappTetheringProxyInfoPage::switchCnfHdlr);

    setStatusBar(VFX_TRUE);
    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_GLOBAL_PROXY));
    setTopBar(bar);

    const VfxS32 xGap = 10;
    const VfxS32 yGap = 10;

    VcpTextView *textView;
    VFX_OBJ_CREATE(textView, VcpTextView, this);
    textView->setPos(0, 0);
    textView->setMargins(xGap, 0, xGap, yGap);
    textView->setSize(getSize());

    textView->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    
    VfxS32 totalLen =
        SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1 +
        SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1 +
        SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1 +
        mmi_wcslen((WCHAR*)GetString(STR_ID_SRV_TETHERING_PROXY_GUIDE)) + 1 +
        64;

    VFX_ALLOC_MEM(m_detailBuf, totalLen * sizeof(VfxWChar), this);
    m_detailBuf[0] = 0;
    textView->setText(m_detailBuf, VFX_TRUE);

    srv_dtcnt_prof_proxy_info_struct proxyInfo;
    srv_dtcnt_get_proxy_info(
        srv_tethering_get_used_dtcnt(),
        &proxyInfo,
        SRV_DTCNT_ACCOUNT_PRIMARY);
    VfxWChar wAddr[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1];
    VfxWChar wPort[5 + 1];
    VfxWChar wName[SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1];
    VfxWChar wPw[SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1];

    mmi_asc_to_wcs(wAddr, (CHAR*)proxyInfo.px_addr);
    mmi_wcs_itow(proxyInfo.px_port, wPort, 10);
    mmi_asc_to_wcs(wName, (CHAR*)proxyInfo.px_authid);
    //mmi_asc_to_wcs(wPw, (CHAR*)proxyInfo.px_authpw);
    VfxU32 i = 0;
    for (; i < strlen((CHAR*)proxyInfo.px_authpw); i++)
    {
        wPw[i] = (VfxWChar)L'*';
    }
    wPw[i] = 0;

    // add strings
    textView->addDetail(VFX_WSTR_RES(STR_ID_SRV_TETHERING_PROXY_GUIDE), VCP_TEXT_DETAIL_CONTENT, totalLen);
    textView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_CONTENT, totalLen);
    textView->addDetail(VFX_WSTR_RES(STR_GLOBAL_ADDRESS), VCP_TEXT_DETAIL_TITLE, totalLen);
    textView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, totalLen);
    textView->addDetail(VFX_WSTR_MEM(wAddr), VCP_TEXT_DETAIL_CONTENT, totalLen);
    textView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_CONTENT, totalLen);
    textView->addDetail(VFX_WSTR_RES(STR_ID_SRV_TETHERING_PROXY_PORT), VCP_TEXT_DETAIL_TITLE, totalLen);
    textView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, totalLen);
    textView->addDetail(VFX_WSTR_MEM(wPort), VCP_TEXT_DETAIL_CONTENT, totalLen);
    textView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_CONTENT, totalLen);
    textView->addDetail(VFX_WSTR_RES(STR_GLOBAL_USERNAME), VCP_TEXT_DETAIL_TITLE, totalLen);
    textView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, totalLen);
    textView->addDetail(VFX_WSTR_MEM(wName), VCP_TEXT_DETAIL_CONTENT, totalLen);
    textView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_CONTENT, totalLen);
    textView->addDetail(VFX_WSTR_RES(STR_GLOBAL_PASSWORD), VCP_TEXT_DETAIL_TITLE, totalLen);
    textView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, totalLen);
    textView->addDetail(VFX_WSTR_MEM(wPw), VCP_TEXT_DETAIL_CONTENT, totalLen);
}


void VappTetheringProxyInfoPage::onDeinit()
{
    VFX_FREE_MEM(m_detailBuf);
    VfxPage::onDeinit();
}


void VappTetheringProxyInfoPage::disconnectHdlr(
    srv_tethering_type_enum tetheringType,
    srv_tethering_disconn_cause_enum cause)
{
    exit();
}


void VappTetheringProxyInfoPage::switchCnfHdlr(srv_tethering_type_enum tetheringType, VfxBool result, srv_tethering_status_enum desStatus)
{
    if (desStatus == SRV_TETHERING_STATUS_SRV_OFF)
    {
        exit();
    }
}


VFX_IMPLEMENT_CLASS("VappTetheringHelpPage", VappTetheringHelpPage, VfxPage);
void VappTetheringHelpPage::onInit()
{
    VfxPage::onInit();
    
    setStatusBar(VFX_TRUE);
    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_GLOBAL_HELP));
    setTopBar(bar);

    const VfxS32 xGap = 10;
    const VfxS32 yGap = 10;

    VcpTextView *textView;
    VFX_OBJ_CREATE(textView, VcpTextView, this);
    textView->setPos(0, 0);
    textView->setMargins(xGap, 0, xGap, yGap);
    textView->setSize(getSize());

    textView->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    
    VfxS32 totalLen = 10; // /n length
    // sum length
    totalLen += mmi_wcslen((WCHAR*)GetString(STR_ID_SRV_TETHERING_HELP_CONTENT));
#ifdef __MMI_TETHERING_WIFI__
    VfxS32 wifiTitleLen = mmi_wcslen((WCHAR*)GetString(STR_ID_SRV_TETHERING_WIFI_HS));
    VfxS32 wifiContentLen = mmi_wcslen((WCHAR*)GetString(STR_ID_SRV_TETHERING_HELP_WIFI_CONTENT));
    totalLen += wifiTitleLen;
    totalLen += wifiContentLen;
#endif /* __MMI_TETHERING_WIFI__ */
#ifdef __USB_TETHERING__
    VfxS32 usbTitleLen = mmi_wcslen((WCHAR*)GetString(STR_ID_SRV_TETHERING_USB));
    VfxS32 usbContentLen = mmi_wcslen((WCHAR*)GetString(STR_ID_SRV_TETHERING_HELP_USB_CONTENT));
    totalLen += usbTitleLen;
    totalLen += usbContentLen;
#endif /* __USB_TETHERING__ */

    VFX_ALLOC_MEM(m_detailBuf, totalLen * 2, this);
    m_detailBuf[0] = 0;
    textView->setText(m_detailBuf, VFX_TRUE);

    // add strings
    textView->addDetail(VFX_WSTR_RES(STR_ID_SRV_TETHERING_HELP_CONTENT), VCP_TEXT_DETAIL_CONTENT, totalLen);

#ifdef __MMI_TETHERING_WIFI__
    // wifi title
    textView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_CONTENT, totalLen);
    textView->addDetail(VFX_WSTR_RES(STR_ID_SRV_TETHERING_WIFI_HS), VCP_TEXT_DETAIL_TITLE, totalLen);
    textView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, totalLen);
    // wifi content
    textView->addDetail(VFX_WSTR_RES(STR_ID_SRV_TETHERING_HELP_WIFI_CONTENT), VCP_TEXT_DETAIL_CONTENT, totalLen);
#endif /* __MMI_TETHERING_WIFI__ */
#ifdef __USB_TETHERING__
    // usb title
    textView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_CONTENT, totalLen);
    textView->addDetail(VFX_WSTR_RES(STR_ID_SRV_TETHERING_USB), VCP_TEXT_DETAIL_TITLE, totalLen);
    textView->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, totalLen);
    // usb content
    textView->addDetail(VFX_WSTR_RES(STR_ID_SRV_TETHERING_HELP_USB_CONTENT), VCP_TEXT_DETAIL_CONTENT, totalLen);
#endif /* __USB_TETHERING__ */
}


void VappTetheringHelpPage::onDeinit()
{
    VFX_FREE_MEM(m_detailBuf);
    VfxPage::onDeinit();
}


VFX_IMPLEMENT_CLASS("VappTetheringSettingCell", VappTetheringSettingCell, VcpFormItemLauncherCell);
void VappTetheringSettingCell::onInit()
{
    VcpFormItemLauncherCell::onInit();

    setMainText(VFX_WSTR_RES(STR_ID_SRV_TETHERING));
    //str.loadFromRes(STR_ID_DTCNT_DATA_ACCOUNT_ENTRY_HINT);
    setHintText(VFX_WSTR_RES(STR_ID_VAPP_TETHERING_EXPLANATION));
    setAccessory(VCPFORM_NEXT_ITEM_ICON);
    if (srv_tethering_check_launch_main_menu_capab() != SRV_TETHERING_LAUNCH_RESULT_OK ||
        srv_mode_switch_is_switching() != MMI_FALSE)
    {
        setIsDisabled(VFX_TRUE);
    }
    m_signalTap.connect(this, &VappTetheringSettingCell::onTap);
    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringAvailStatusChange.connect(this, &VappTetheringSettingCell::availStatusChangeHdlr);
    srv_tethering_reg_app_avail_status_change_cb(
        (srv_tethering_app_avail_status_change_notify_funcptr_type)VappTetheringEvtListener::availStatusChangeHdlr,
        NULL);
}


void VappTetheringSettingCell::onDeinit()
{
    VcpFormItemLauncherCell::onDeinit();
}


void VappTetheringSettingCell::onTap(VcpFormItemCell* sender, VfxId senderId)
{
    VfxMainScr *mainScr;
    mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);
    if (mainScr)
    {
        VfxApp *app = mainScr->getApp();
        MMI_ID cui_gid;
        cui_gid = VfxAppLauncher::createCui(
                    VAPP_TETHERING,
                    VFX_OBJ_CLASS_INFO(VcuiTethering),
                    app->getGroupId(),
                    NULL,
                    0);
        VfxAppLauncher::runCui(cui_gid);
    }
}


void VappTetheringSettingCell::availStatusChangeHdlr(VfxBool enableFlag)
{
    if (enableFlag == VFX_FALSE ||
        srv_tethering_check_launch_main_menu_capab() != SRV_TETHERING_LAUNCH_RESULT_OK)
    {
        setIsDisabled(VFX_TRUE);
    }
    else
    {
        setIsDisabled(VFX_FALSE);
    }
}


#ifdef __USB_TETHERING__
void usbTetheringLaunch()
{
    VappTetheringUsbLaunchTypeEnum launchType = TETHERING_USB_LAUNCH_TYPE_NORMAL;
    VfxAppLauncher::launchWithAsmSize(
        VAPP_TETHERING,
        VFX_OBJ_CLASS_INFO(VappTetheringUsb),
        GRP_ID_ROOT,
        100 * 1024,
        &launchType,
        sizeof(launchType));
}


void usbTetheringReconn()
{
    VappTetheringUsbLaunchTypeEnum launchType = TETHERING_USB_LAUNCH_TYPE_RECONN;
    VfxAppLauncher::launchWithAsmSize(
        VAPP_TETHERING,
        VFX_OBJ_CLASS_INFO(VappTetheringUsb),
        GRP_ID_ROOT,
        100 * 1024,
        &launchType,
        sizeof(launchType));
}


VFX_IMPLEMENT_CLASS("VappTetheringUsb", VappTetheringUsb, VfxApp);
void VappTetheringUsb::onRun(void * args,VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);
    VappTetheringUsbLaunchTypeEnum launchType = *((VappTetheringUsbLaunchTypeEnum*)args);

    VappTetheringNmgrPopup::dismissPopup();
    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringNoSimAvailable.connect(this, &VappTetheringUsb::exit);

    if (launchType == TETHERING_USB_LAUNCH_TYPE_NORMAL)
    {
        VFX_OBJ_CREATE(m_usbLauncherMainScr, VappTetheringUsbLauncherMainScr, this);
        m_usbLauncherMainScr->show();
    }
    else if (launchType == TETHERING_USB_LAUNCH_TYPE_RECONN)
    {
        reConnect();
    }
}


void VappTetheringUsb::reConnect()
{
    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringSwitchCnf.connect(this, &VappTetheringUsb::switchCnfHdlr);
    srv_tethering_switch_cb_funcptr_type funcPtr =
        (srv_tethering_switch_cb_funcptr_type)(VappTetheringEvtListener::switchCnfHdlr);
    vappTetheringConfigConnInfo();
    srv_tethering_launch_result_enum result = srv_tethering_check_launch_capab(SRV_TETHERING_TYPE_USB);
    if (result == SRV_TETHERING_LAUNCH_RESULT_OK ||
        result == SRV_TETHERING_LAUNCH_RESULT_NETWORK_NOT_READY)
    {
        VappTetheringUsbReconnIndMainScr *indPopupScr;
        VFX_OBJ_CREATE(indPopupScr, VappTetheringUsbReconnIndMainScr, this);
        indPopupScr->show();
        srv_tethering_switch_on(SRV_TETHERING_TYPE_USB, funcPtr, this);
    }
    else
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_FAILURE,
            VFX_WSTR_RES(STR_ID_SRV_TETHERING_USB_DISCONNECT));
        exit();
    }
}


void VappTetheringUsb::launchUsbTethering()
{
    // setting conn info
    vappTetheringConfigConnInfo();
    srv_tethering_reg_reactivate_demand_cb_hdlr(SRV_TETHERING_TYPE_USB, VappTetheringEvtListener::reactivateDemandHdlr);

    // run
    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringSwitchCnf.connect(this, &VappTetheringUsb::switchCnfHdlr);
    srv_tethering_switch_cb_funcptr_type funcPtr =
        (srv_tethering_switch_cb_funcptr_type)(VappTetheringEvtListener::switchCnfHdlr);
    srv_tethering_switch_on(SRV_TETHERING_TYPE_USB, funcPtr, this);
}


void VappTetheringUsb::switchCnfHdlr(
    srv_tethering_type_enum tetheringType,
    VfxBool result,
    srv_tethering_status_enum desStatus)
{
    // close this launcher screen
    exit();

    if (tetheringType == SRV_TETHERING_TYPE_USB)
    {
        if (result == VFX_FALSE)
        {
            vapp_nmgr_global_popup_show_confirm_one_button_id(
                MMI_SCENARIO_ID_DEFAULT,
                VCP_POPUP_TYPE_FAILURE,
                STR_GLOBAL_FAILED,
                STR_GLOBAL_OK,
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                NULL,
                NULL);
        }
    }
}


VFX_IMPLEMENT_CLASS("VappTetheringUsbLauncherMainScr", VappTetheringUsbLauncherMainScr, VfxMainScr);
void VappTetheringUsbLauncherMainScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringDisconnect.connect(this, &VappTetheringUsbLauncherMainScr::disconnectHdlr);

    srv_tethering_usb_reg_cable_disconnect_cb_hdlr(VappTetheringEvtListener::tetheringUsbCableDisconnHdlr);
    VFX_OBJ_GET_INSTANCE(VappTetheringEvtListener)->m_tetheringUsbCableDisconn.connect(this, &VappTetheringUsbLauncherMainScr::tetheringUsbCableDisconnHdlr);

    entryLauncherPage();
}


void VappTetheringUsbLauncherMainScr::entryLauncherPage()
{
    VFX_OBJ_CREATE(m_mainScrPage, VappTetheringUsbLauncherPage, this);
    pushPage(0, m_mainScrPage.get());
}


void VappTetheringUsbLauncherMainScr::disconnectHdlr(srv_tethering_type_enum tetheringType, srv_tethering_disconn_cause_enum cause)
{
    if (tetheringType == SRV_TETHERING_TYPE_USB)
    {
        exit();
    }
}


void VappTetheringUsbLauncherMainScr::tetheringUsbCableDisconnHdlr()
{
    exit();
}


VFX_IMPLEMENT_CLASS("VappTetheringUsbLauncherPage", VappTetheringUsbLauncherPage, VfxPage);
void VappTetheringUsbLauncherPage::onInit()
{
    VfxPage::onInit();

    setStatusBar(VFX_TRUE);
    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_ID_SRV_TETHERING_USB));
    setTopBar(bar);

    VcpToolBar *toolBar;
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    toolBar->addItem(TOOLBAR_ITEM_OK, VFX_WSTR_RES(VCP_STR_TOOL_BAR_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    toolBar->addItem(TOOLBAR_ITEM_CANCEL, VFX_WSTR_RES(VCP_STR_TOOL_BAR_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    toolBar->m_signalButtonTap.connect(this, &VappTetheringUsbLauncherPage::toolbarEventHdlr);
    setBottomBar(toolBar);

    // configure the textview
    //VfxWChar *summary = (VfxWChar*)GetString(STR_ID_SRV_TETHERING_HELP_CONTENT);
    //VfxWChar *usbContent = (VfxWChar*)GetString(STR_ID_SRV_TETHERING_HELP_USB_CONTENT);

    const VfxS32 xGap = 10;
    const VfxS32 yGap = 10;

    VcpTextView *textView;
    VFX_OBJ_CREATE(textView, VcpTextView, this);
    textView->setPos(0, 0);
    textView->setMargins(xGap, 0, xGap, yGap);
    textView->setSize(getSize());
    textView->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    textView->setText((WCHAR*)GetString(STR_ID_SRV_TETHERING_USB_REMIND_SHORT), VFX_TRUE);
}


void VappTetheringUsbLauncherPage::onDeinit()
{
    VfxPage::onDeinit();
}


void VappTetheringUsbLauncherPage::toolbarEventHdlr(VfxObject* obj, VfxId itemId)
{
    switch (itemId)
    {
        case TOOLBAR_ITEM_OK:
        {
            // check able to run
            srv_tethering_launch_result_enum result = srv_tethering_check_launch_capab_common(SRV_TETHERING_TYPE_USB);
            VfxResId strId;
            switch (result)
            {
                case SRV_TETHERING_LAUNCH_RESULT_WIFI_TETHERING_ACTIVATED:
                {
                    strId = STR_ID_SRV_TETHERING_WIFI_TETHERING_ACTIVATED_WARNNING;
                }
                    break;

                case SRV_TETHERING_LAUNCH_RESULT_DIALUP_ACTIVATED:
                {
                    strId = STR_ID_SRV_TETHERING_DIALUP_ACTIVATED_WARNNING;
                }
                    break;

                case SRV_TETHERING_LAUNCH_RESULT_UNAVAILABLE_SIM:
                {
                    strId = STR_GLOBAL_UNAVAILABLE_SIM;
                }
                    break;

                case SRV_TETHERING_LAUNCH_RESULT_NETWORK_NOT_READY:
                {
                    strId = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE;
                }
                    break;

                case SRV_TETHERING_LAUNCH_RESULT_FLIGHT_MODE:
                {
                    strId = STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE;
                }
                    break;

                default:
                    strId = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE;
                    break;
            }

            if (result != SRV_TETHERING_LAUNCH_RESULT_OK)
            {
                VcpConfirmPopup *cnfPopup;
                VFX_OBJ_CREATE(cnfPopup, VcpConfirmPopup, this);

                cnfPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
                cnfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
                cnfPopup->setText(VFX_WSTR_RES(strId));
                cnfPopup->show(VFX_TRUE);
                return;
            }

            // check network available
            srv_dtcnt_sim_type_enum simType;
            srv_dtcnt_get_sim_preference(&simType);
            mmi_sim_enum sim;
            VFX_ASSERT(SRV_DTCNT_SIM_TYPE_1 == 1);
            sim = mmi_frm_index_to_sim(simType - 1);
            if (srv_tethering_check_launch_capab_nw(sim) != SRV_TETHERING_LAUNCH_RESULT_OK)
            {
                VcpConfirmPopup *cnfPopup;
                VFX_OBJ_CREATE(cnfPopup, VcpConfirmPopup, this);

                cnfPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
                cnfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
                cnfPopup->setText(VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE));
                cnfPopup->show(VFX_TRUE);
                return;
            }

            // check data account
            if (SRV_TETHERING_LAUNCH_RESULT_INVALID_ACCOUNT == srv_tethering_check_launch_capab_acct(SRV_TETHERING_TYPE_USB, srv_tethering_get_dtcnt(simType)))
            {
                VcpConfirmPopup *cnfPopup;
                VFX_OBJ_CREATE(cnfPopup, VcpConfirmPopup, this);

                cnfPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
                cnfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
                cnfPopup->setText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_INVALID_DATA_ACCOUNT));
                cnfPopup->show(VFX_TRUE);
                return;
            }

            // display waiting popup indicator
            VFX_OBJ_CREATE(m_waitInd, VcpIndicatorPopup, this);
            m_waitInd->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
            m_waitInd->setText(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT));
            m_waitInd->setAutoDestory(VFX_FALSE);
            m_waitInd->show(VFX_TRUE);

            VappTetheringUsb *appObj = (VappTetheringUsb*)getApp();
            appObj->launchUsbTethering();
            break;
        }

        case TOOLBAR_ITEM_CANCEL:
        {
            exit();
            break;
        }

        default:
            break;
    }
}


VFX_IMPLEMENT_CLASS("VappTetheringUsbReconnIndMainScr", VappTetheringUsbReconnIndMainScr, VfxAppScr);
VappTetheringUsbReconnIndMainScr::VappTetheringUsbReconnIndMainScr()
{
    setIsSmallScreen();
}


void VappTetheringUsbReconnIndMainScr::onInit()
{
    VfxAppScr::onInit();

    //setOpacity(0);

    VcpIndicatorPopup *IndPopup;
    VFX_OBJ_CREATE(IndPopup, VcpIndicatorPopup, this);
    IndPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
    IndPopup->setText(VFX_WSTR_RES(STR_ID_SRV_TETHERING_USB_RECONNECT));
    IndPopup->m_signalCanceled.connect(this, &VappTetheringUsbReconnIndMainScr::onCancel);
    IndPopup->show(VFX_TRUE);
}


void VappTetheringUsbReconnIndMainScr::onDeinit()
{
    if (srv_tethering_get_ext_status(SRV_TETHERING_TYPE_USB) == SRV_TETHERING_EXT_STATUS_REACTIVATE)
    {
        srv_tethering_stop(SRV_TETHERING_TYPE_USB, NULL, NULL);
    }
    VfxAppScr::onDeinit();
}


void VappTetheringUsbReconnIndMainScr::onCancel(VfxObject* obj, VfxFloat result)
{
    exit();
}
#endif /* __USB_TETHERING__ */

#endif /* __MMI_TETHERING__ */
