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
 *  vapp_tethering.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_WIFI_HS_H__
#define __VAPP_WIFI_HS_H__
#include "MMI_features.h"
#ifdef __MMI_TETHERING__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_tabctrl_page.h"
#include "vcp_list_menu.h"

extern "C"
{
#include "TetheringSrvIprot.h"
#include "TetheringSrvGprot.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
enum VappTetheringUsbLaunchTypeEnum
{
    TETHERING_USB_LAUNCH_TYPE_NORMAL,
    TETHERING_USB_LAUNCH_TYPE_RECONN,
    TETHERING_USB_LAUNCH_TYPE_END
};

/***************************************************************************** 
 * Class VappTetheringMainScrPage
 *****************************************************************************/

class VappTetheringMainScrPage: public VfxPage
{
    VFX_DECLARE_CLASS(VappTetheringMainScrPage);

// Constructor / Destructor
public:
    VappTetheringMainScrPage();
    virtual ~VappTetheringMainScrPage() {}

public:
    void switchCnfHdlr(
        srv_tethering_type_enum tethering_type,
        VfxBool result,
        srv_tethering_status_enum desStatus
    );
    void wifiSwitchProcess(VfxBool desState);
    
    void connInfoHdlr(
        srv_tethering_type_enum tetheringType,
        void *infoData);

// Override
public:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);

private:
    enum VappTetheringMainSrcItemEnum
    {
        FORM_ID_WIFI_CAP,
        FORM_ID_WIFI_SWITCH,
        FORM_ID_WIFI_SETTINGS,
        FORM_ID_WIFI_AUTO_TURN_OFF,
        FORM_ID_USB_CAP,
        FORM_ID_USB_ITEM,
        FORM_ID_OTHER_SETTINGS_AND_INFO_CAP,
        FORM_ID_DATA_ACCOUNT,
        FORM_ID_CONN_INFO,
        FORM_ID_HELP,
        FORM_ITEM_TOTAL
    };

    enum VappTetheringWifiPwInputPopupItemEnum
    {
        PASSWORD_NEW,
        PASSWORD_NEW_CONFIRM,
        PASSWORD_TOTAL
    };

//
private:
    void onItemCellLaunch(
        VcpFormItemCell *obj,
        VfxId id
        );
    
    VfxBool wifiSwitchCheck();

    void pwInputPopupBtnClickHdlr(
        VfxObject* sender,
        VcpInputPopupButtonEnum id
    );

    void wifiSwitchReqHdlr(
        VcpFormItemSwitchCell* sender,
        VfxId senderId,
        VfxBool desState
    );

    void turnOffWlanCnfHdlr(
        VfxObject* obj,
        VfxId id
    );

    void autoTurnOffSwitchReqHdlr(
        VcpFormItemSwitchCell* sender,
        VfxId senderId,
        VfxBool desState);

    void redraw();

    void startCountDown();

    void stopCountDown();

    void updateCountDown();

    void countDownSinalTick(VfxTimer *timer);

// Variable
private:
    VcpForm *m_form;
    VcpInputPopup *m_pwInputPopup;
    VfxBool runTurnOffWlanFlag;
    VfxTimer *m_CountDownTimer;
};

#ifdef __MMI_TETHERING_WIFI__
/***************************************************************************** 
 * Class VappTetheringWifiHsSettingsScrPage
 *****************************************************************************/

class VappTetheringWifiHsSettingsPage: public VfxPage
{
    VFX_DECLARE_CLASS(VappTetheringWifiHsSettingsPage);

private:
    enum VappTetheringWifiHsSettingsFormItemEnum
    {
        //WIFI_HS_SETTINGS_CAPTION,
        NETWORK_SSID_EDITOR,
        SECURITY_TYPE_BUTTON,
        PASSWORD_EDITOR,
        //GPRS_SETTINGS_CAPTION,
        //DTCNT_BUTTON,
        FORM_ITEM_TOTAL
    };
    
    enum VappTetheringWifiHsSettingsToolbarItemEnum
    {
        TOOLBAR_ITEM_SAVE,
        TOOLBAR_ITEM_CANCEL,
        TOOLBAR_ITEM_TOTAL
    };

    enum VappTetheringWifiHsSettingsFuncbarItemEnum
    {
        FUNCBAR_ITEM_SAVE,
        FUNCBAR_ITEM_TOTAL
    };

// Constructor / Destructor
public:
    VappTetheringWifiHsSettingsPage() {}
    virtual ~VappTetheringWifiHsSettingsPage() {}

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    void toolbarEventHdlr(
        VfxObject* obj,
        VfxId itemId
    );
    
    void funcbarEventHdlr(
        VfxObject* obj,
        VfxId itemId
    );

    void securityBtnEventHandler(
        VfxObject* obj,
        VfxId itemId
    );

    void selPopupClickHdlr(
        VfxObject* obj,
        VfxId itemId
    );

    void selPopupStateChangeHdlr(
        VfxBasePopup* obj,
        VfxBasePopupStateEnum state
    );

    void saveHdlr();
    VfxBool checkSettingValid();
    void saveSettings();

#if 0
/* under construction !*/
/* under construction !*/
#endif
private:
    VcpForm *m_form;
    VcpToolBar *m_toolBar;
    srv_tethering_wifi_hs_auth_mode_enum m_tempAuthMode;
    VcpIndicatorPopup *m_updateIndicatorPopup;
    VcpFunctionBar *m_funcBar;
};
#endif /* __MMI_TETHERING_WIFI__ */

/***************************************************************************** 
 * Class VappTetheringConnInfoPage
 *****************************************************************************/

class VappTetheringConnInfoPage: public VfxPage
{
    VFX_DECLARE_CLASS(VappTetheringConnInfoPage);

private:
    enum VappTetheringConnInfoFormItemEnum
    {
        FORM_ID_USED_SIM,
        FORM_ID_APN,
        FORM_ID_PROXY,
        FORM_ID_WIFI_CAP,
        FORM_ID_WIFI_STATUS,
        FORM_ID_CONN_NUM,
        FORM_ID_USB_CAP,
        FORM_ID_USB_STATUS,
        FORM_ID_ITEM_TOTAL
    };

// Constructor / Destructor
public:
    VappTetheringConnInfoPage() {}
    virtual ~VappTetheringConnInfoPage() {}

    void connInfoHdlr(
        srv_tethering_type_enum tetheringType,
        void *infoData
    );

    void switchCnfHdlr(
        srv_tethering_type_enum tethering_type,
        VfxBool result,
        srv_tethering_status_enum desStatus
    );

    void onItemCellLaunch(
        VcpFormItemCell *obj,
        VfxId id
    );

private:
    void updateInfo(
        srv_tethering_type_enum tetheringType,
        void *infoData
    );

    void disconnectHdlr(
        srv_tethering_type_enum tetheringType,
        srv_tethering_disconn_cause_enum cause
    );

// Override
protected:
    virtual void onInit();

private:
    VcpForm *m_form;
};


/***************************************************************************** 
 * Class VappTetheringProxyInfoPage
 *****************************************************************************/

class VappTetheringProxyInfoPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappTetheringProxyInfoPage);

// Constructor / Destructor
public:
    VappTetheringProxyInfoPage() {}
    virtual ~VappTetheringProxyInfoPage() {}

private:
    void switchCnfHdlr(
        srv_tethering_type_enum tethering_type,
        VfxBool result,
        srv_tethering_status_enum desStatus
    );

    void disconnectHdlr(
        srv_tethering_type_enum tetheringType,
        srv_tethering_disconn_cause_enum cause
    );

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    VfxWChar *m_detailBuf;
};


/***************************************************************************** 
 * Class VappTetheringHelpPage
 *****************************************************************************/

class VappTetheringHelpPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappTetheringHelpPage);

// Constructor / Destructor
public:
    VappTetheringHelpPage() {}
    virtual ~VappTetheringHelpPage() {}

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    VfxWChar *m_detailBuf;
};


/***************************************************************************** 
 * Class VappTetheringMainScr
 *****************************************************************************/

class VappTetheringMainScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappTetheringMainScr);

// Constructor / Destructor
public:
    VappTetheringMainScr();
    virtual ~VappTetheringMainScr() {}

// Override
protected:
    virtual void on1stReady();

// Method
public:
    void entryMainScrPage();
    void entryWifiSettingsPage();
    void entryDtcntCui();
    void exitDtcntCui();
    void entryConnInfoPage();
    void entryProxyInfoPage();
    void entryHelpPage();

    void disconnectHdlr(
        srv_tethering_type_enum tethering_type,
        srv_tethering_disconn_cause_enum cause
    );
    
    void dtcntChangedNotifyHdlr(
        srv_dtcnt_sim_type_enum sim,
        VfxU32 acct);

    static void onClose();

    void updataSettingsReq(srv_tethering_type_enum tethering_type);

protected:
    virtual mmi_ret onProc(mmi_event_struct *evt);

// Variable
private:
    VfxWeakPtr<VappTetheringMainScrPage> m_mainScrPage;
#ifdef __MMI_TETHERING_WIFI__
    VfxWeakPtr<VappTetheringWifiHsSettingsPage> m_settingsPage;
#endif /* __MMI_TETHERING_WIFI__ */
    VfxWeakPtr<VappTetheringConnInfoPage> m_connInfoPage;
    VfxWeakPtr<VappTetheringProxyInfoPage> m_proxyInfoPage;
    VfxWeakPtr<VappTetheringHelpPage> m_helpPage;
    MMI_ID m_dtcntCuiId;
    VfxBool m_dtcntCuiExist;
};


/***************************************************************************** 
 * Class VappTethering
 *****************************************************************************/

class VappTethering : public VfxApp
{
    VFX_DECLARE_CLASS(VappTethering);

// Constructor / Destructor
public:
    VappTethering() {}
    virtual ~VappTethering() {}

// Method
public:
    virtual void onRun(
        void* args,
        VfxU32 argSize
    );

// Method

// Variable

// Override

// Declaration

// Variable
};


/***************************************************************************** 
 * Class VcuiTethering
 *****************************************************************************/

class VcuiTethering : public VfxCui
{
    VFX_DECLARE_CLASS(VcuiTethering);

// Constructor / Destructor
public:
    VcuiTethering() {}
    virtual ~VcuiTethering() {}

// Method
public:
    virtual void onRun(
        void* args,
        VfxU32 argSize
    );

// Method

// Variable

// Override

// Declaration

// Variable
};


/***************************************************************************** 
 * Class VappTetheringListMenuCustomContentFrame
 *****************************************************************************/

class VappTetheringListMenuCustomContentFrame : public VcpListMenuCellClientBaseFrame
{
    VFX_DECLARE_CLASS(VappTetheringListMenuCustomContentFrame);

// Constructor / Destructor
public:
    VappTetheringListMenuCustomContentFrame(){}
    virtual ~VappTetheringListMenuCustomContentFrame(){}

// Override
public:
    virtual void onCreateElements();
    virtual void onCloseElements();
    virtual void onLayoutElements();
    virtual void onUpdateElements();
};

/***************************************************************************** 
 * Class VappTetheringSettingCell
 *****************************************************************************/

class VappTetheringSettingCell: public VcpFormItemLauncherCell
{
    VFX_DECLARE_CLASS(VappTetheringSettingCell);
public:
    virtual void onInit();
    virtual void onDeinit();
    void onTap(VcpFormItemCell* sender, VfxId senderId);

private:
    void availStatusChangeHdlr(VfxBool enableFlag);
};


#ifdef __MMI_TETHERING_WIFI__
/***************************************************************************** 
 * Class VappTetheringWifiReconnIndMainScr
 *****************************************************************************/

class VappTetheringWifiReconnIndMainScr : public VfxAppScr
{
    VFX_DECLARE_CLASS(VappTetheringWifiReconnIndMainScr);

// Constructor / Destructor
public:
    VappTetheringWifiReconnIndMainScr();
    virtual ~VappTetheringWifiReconnIndMainScr() {}

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    void onCancel(
        VfxObject* obj,
        VfxFloat result
    );
};


/***************************************************************************** 
 * Class VappTetheringWifiReconn
 *****************************************************************************/

class VappTetheringWifiReconn : public VfxApp
{
    VFX_DECLARE_CLASS(VappTetheringWifiReconn);

// Constructor / Destructor
public:
    VappTetheringWifiReconn() {}
    virtual ~VappTetheringWifiReconn() {}

// Method
public:
    virtual void onRun(
        void* args,
        VfxU32 argSize
    );

    void switchCnfHdlr(
        srv_tethering_type_enum tethering_type,
        VfxBool result,
        srv_tethering_status_enum desStatus
    );

private:

// Method

// Variable

// Override

// Declaration

// Variable

};

#endif /* __MMI_TETHERING_WIFI__ */

#ifdef __USB_TETHERING__

/***************************************************************************** 
 * Class VappTetheringUsbLauncherPage
 *****************************************************************************/

class VappTetheringUsbLauncherPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappTetheringUsbLauncherPage);

// Constructor / Destructor
public:
    VappTetheringUsbLauncherPage() : m_waitInd(NULL) {}
    virtual ~VappTetheringUsbLauncherPage() {}

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

private:

    enum VappTetheringUsbLauncherToolbarItemEnum
    {
        TOOLBAR_ITEM_OK,
        TOOLBAR_ITEM_CANCEL,
        TOOLBAR_ITEM_TOTAL
    };

    void toolbarEventHdlr(
        VfxObject* obj,
        VfxId itemId
    );

// Variable
private:
    VcpIndicatorPopup *m_waitInd;
};

/***************************************************************************** 
 * Class VappTetheringUsbLauncherMainScr
 *****************************************************************************/

class VappTetheringUsbLauncherMainScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappTetheringUsbLauncherMainScr);

// Constructor / Destructor
public:
    VappTetheringUsbLauncherMainScr() : m_mainScrPage(NULL) {}
    virtual ~VappTetheringUsbLauncherMainScr() {}

// Override
protected:
    virtual void on1stReady();

// Method
public:
    void entryLauncherPage();
    void disconnectHdlr(
        srv_tethering_type_enum tethering_type,
        srv_tethering_disconn_cause_enum cause
    );
    void tetheringUsbCableDisconnHdlr();

// Variable
private:
    VfxWeakPtr<VappTetheringUsbLauncherPage> m_mainScrPage;
};


/***************************************************************************** 
 * Class VappTetheringUsb
 *****************************************************************************/

class VappTetheringUsb : public VfxApp
{
    VFX_DECLARE_CLASS(VappTetheringUsb);

// Constructor / Destructor
public:
    VappTetheringUsb() : m_usbLauncherMainScr(NULL) {}
    virtual ~VappTetheringUsb() {}

// Method
public:
    virtual void onRun(
        void* args,
        VfxU32 argSize
    );
    
    void launchUsbTethering();

    void switchCnfHdlr(
        srv_tethering_type_enum tethering_type,
        VfxBool result,
        srv_tethering_status_enum desStatus
    );

// Method
private:
    void reConnect();

// Variable

// Override

// Declaration

// Variable
private:
    VappTetheringUsbLauncherMainScr *m_usbLauncherMainScr;
};


/***************************************************************************** 
 * Class VappTetheringUsbReconnIndMainScr
 *****************************************************************************/

class VappTetheringUsbReconnIndMainScr : public VfxAppScr
{
    VFX_DECLARE_CLASS(VappTetheringUsbReconnIndMainScr);

// Constructor / Destructor
public:
    VappTetheringUsbReconnIndMainScr();
    virtual ~VappTetheringUsbReconnIndMainScr() {}

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    void onCancel(
        VfxObject* obj,
        VfxFloat result
    );
};
#endif /* __USB_TETHERING__ */


/***************************************************************************** 
 * Class VappTetheringEvtListener
 *****************************************************************************/

class VappTetheringEvtListener : public VfxObject
{
VFX_OBJ_DECLARE_SINGLETON_CLASS(VappTetheringEvtListener);
// Constructor / Destructor
public:
    VappTetheringEvtListener() {}
    virtual ~VappTetheringEvtListener() {}

// Method
public:
    static void switchCnfHdlr(
        srv_tethering_type_enum tetheringType,
        VfxBool result,
        srv_tethering_status_enum desStatus,
        void *arg
    );

    static void disconnectHdlr(
        srv_tethering_type_enum tetheringType,
        srv_tethering_disconn_cause_enum cause,
        void *userData
    );

    static void connInfoHdlr(
        srv_tethering_type_enum tetheringType,
        void *infoData,
        void *userData
    );

    static void availStatusChangeHdlr(
        VfxBool enableFlag,
        void* userData
    );

    static void tetheringUsbCableDisconnHdlr();

    static void reactivateDemandHdlr(
        srv_tethering_type_enum tetheringType
    );

    static void dtcntChangedNotifyHdlr(
        srv_dtcnt_sim_type_enum sim,
        VfxU32 acct
    );

    static void noSimAvailableHdlr();
// Variable
public:
    VfxSignal3<
        srv_tethering_type_enum,
        VfxBool,
        srv_tethering_status_enum
    > m_tetheringSwitchCnf;

    VfxSignal2<
        srv_tethering_type_enum,
        srv_tethering_disconn_cause_enum
    > m_tetheringDisconnect;

    VfxSignal2<
        srv_tethering_type_enum,
        void*
    > m_tetheringConnInfo;

    VfxSignal1<
        VfxBool
    > m_tetheringAvailStatusChange;

    VfxSignal2<
        srv_dtcnt_sim_type_enum,
        VfxU32
    > m_tetheringDtcntChangedNotify;
    
    VfxSignal0 m_tetheringUsbCableDisconn;

    VfxSignal0 m_tetheringNoSimAvailable;
// Override

// Declaration

// Variable
};


/***************************************************************************** 
 * Class VappTetheringNmgrPopup
 *****************************************************************************/

class VappTetheringNmgrPopup : public VfxBase
{
// Constructor / Destructor
public:
    VappTetheringNmgrPopup() {}
    virtual ~VappTetheringNmgrPopup() {}

// Method
public:
    static MMI_BOOL proxyPopup(
        mmi_scenario_id scenarioId,
        void *arg
    );

    static void dismissPopup();

// Override

// Declaration

// Variable
};

#endif /* __MMI_TETHERING__ */
#endif /* __VAPP_WIFI_HS_H__ */

