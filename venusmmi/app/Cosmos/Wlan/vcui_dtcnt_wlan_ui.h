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
 *  vcui_dtcnt_wlan_ui.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCUI_DTCNT_WLAN_UI_H__
#define __VCUI_DTCNT_WLAN_UI_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#include "vapp_dtcnt_wlan_ui.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
class VcuiDtcntWlanScr;
class VcuiWlanInputScr;
class VcuiWlanSatellite;
class VcuiDtcntWlanSetting;

class VcuiDtcntWlanSetting : public VfxCui
{
    VFX_DECLARE_CLASS(VcuiDtcntWlanSetting);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onDeinit();

public:    
    VappWlanMainScrn* getWlanMainScreen(void);
    
// Variable
private:
    VappWlanMainScrn        *m_wlanSettingScr;
};

class VcuiDtcntWlanCui : public VfxCui
{
    VFX_DECLARE_CLASS(VcuiDtcntWlanCui);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onDeinit();

// Variable
private:
    VcuiDtcntWlanScr        *m_dtcntWlanScr;
};

class VcuiDtcntWlanScr : public VfxAppScr
{
//    VFX_DECLARE_CLASS(VcuiDtcntWlanScr);

// Constructor / Destructor
public:
    VcuiDtcntWlanScr();
    
// Override
public:
    virtual void onInit();
    virtual void onEnter (VfxBool isBackward);
    virtual void onDeinit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

// Method
    static void afterStopTethering(srv_tethering_type_enum tethering_type, MMI_BOOL result, void *user_data);
    void showConnectingPopup(VappWlanProfile* hiltAp);
    void showApListContextPopup();
    void abortScanRequest(VfxObject *sender);
    void connectToAp(VappWlanProfile* hiltAp);
    void refreshAplist();

    void start();
    void run(SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg);
    void end();

    void CuiSendEventToApp(VCUI_WLAN_AP_LIST_EVENT_ENUM evt_id);
    
#ifdef __MMI_OP01_WIFI__
    VfxBool VerifyNetWorkStatus();  
    void entryCMCCConnectProcByCui ();
#endif

// Variable
private:
    VfxBool                      m_isScanCompleted;
    VcpIndicatorPopup           *m_waitingPopup;
    VcuiWlanSatellite           *m_wlanSatellite;
    VappWlanRepository          *m_repository;
    VcuiWlanInputScr            *m_inputScr;
    VcpIndicatorPopup           *m_searchingPopup;
    VfxWeakPtr<VcuiWlanInputScr>   m_scrWeakPtr;
    VfxWeakPtr<VcuiWlanSatellite>  m_pageWeakPtr;
    VfxWeakPtr<VcpIndicatorPopup>  m_popupWeakPtr;
    
    VcpMenuPopup                *m_apListPopup;
    VfxWeakPtr<VcpMenuPopup>     m_menuWeakPtr;
    VfxU8                        m_apNum;
    
    VfxScrRotateTypeEnum         m_dir;

// Implement
private:
    void onConfirmBtnClicked(VfxObject* sender, VfxId id);
    void onAfterJoinNetwork(VfxBool isJoin, VappWlanProfile* network);
    void onItemTapped (VcpMenuPopup* sender, VcpMenuPopupEventEnum evt, VcpMenuPopupItem* ap);
    void onNoApExistConfirm (VfxObject* sender, VfxId id);
    void onPopupSpecialKeyClick (VfxObject *sender, VfxId id);
    void onFailConfirmBtnClick (VfxObject *sender, VfxId id);
    void onWpaNoneConfirmBtnClick (VfxObject *sender, VfxId id);
    void informWlanCui(srv_tethering_type_enum tethering_type, MMI_BOOL result, void *user_data);
    void informDtcntService(srv_dtcnt_wlan_search_ap_open_rsp_enum action);
    
};

class VcuiWlanInputScr : public VfxMainScr
{
//    VFX_DECLARE_CLASS(VcuiWlanInputScr);

// Constructor / Destructor
public:
    VcuiWlanInputScr();
    VcuiWlanInputScr(VappWlanProfile* hiltAp);
    
// Override
public:
    virtual void on1stReady();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

// Method
public:
    void inputSecurityInfo();

// Variable
public:
    VfxSignal2 <VfxBool, VappWlanProfile*> m_signalAfterInput;
    
private:
    VappWlanProfile*            m_ap;
    
// Implement
    void onJoinNetwork(VfxBool isJoin, VappWlanProfile* network);
};

class VcuiWlanSatellite : public Observer
{
// Declaration
//    VFX_DECLARE_CLASS(VcuiWlanSatellite);

// Constructor / Destructor
public:
    VcuiWlanSatellite();
    VcuiWlanSatellite(VappWlanRepository *repository);
    virtual ~VcuiWlanSatellite();

// Method

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void UpdatePage (SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg);

// Variable
public:
    VfxSignal1<SUBSCRIBE_SRV_WLAN_EVENT_ENUM>  m_signalReceiveDtcntMsg;

private:
    VappWlanRepository         *m_repository;

// Implementation
};

#endif
