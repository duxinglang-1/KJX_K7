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
 *  vapp_bt_main.h
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_BT_MAIN_H__
#define __VAPP_BT_MAIN_H__

#include "MMI_features.h" 

#ifdef __MMI_BT_SUPPORT__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_include.h"
#include "vcp_tabctrl_page.h"
#include "..\..\framework\mmi_core\vfx_cui.h"
#include "BTcmSrvGprot.h"
extern "C" 
{
	#include "FileMgrSrvGProt.h" // for srv_fmgr_drivelist_type_enum
}


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
class VappBtSettingPage;
/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappBtSettingApp : public VfxCui, IVfxMainScrHandler
{
	VFX_DECLARE_CLASS(VappBtSettingApp);
public:
    virtual void onRun(void* args, VfxU32 argSize);

/*---------------------------------------------------------------------------*
 * Function: offEventsNotify()
 * Date:Apr/19/2012
 * Description: callback function, be called when BT is turn off.
 *    
 * Parameters
 *    @event: 
 *    @para: 
 *---------------------------------------------------------------------------*/
	static void offEventsNotify(VfxU32 event, void* para);

/*---------------------------------------------------------------------------*
 * Function: onScr1stReady()
 * Date:Jan/9/2012
 * Description: virtual function from IVfxMainScrHandler, call back when the scr is ready.
 *    
 * Parameters
 *    @*scr: the handle of the screen.
 *---------------------------------------------------------------------------*/
    virtual void onScr1stReady(VfxMainScrEx *scr);

/*---------------------------------------------------------------------------*
 * Function: onScr2ndReady()
 * Date:Feb/13/2012
 * Description: virtual function from IVfxMainScrHandler, call back when the scr is 2nd ready.
 *    
 * Parameters
 *    @scr: the handle of the screen.
 *---------------------------------------------------------------------------*/
	virtual void onScr2ndReady(VfxMainScrEx * scr);

/*---------------------------------------------------------------------------*
 * Function: onDeinit()
 * Date:Apr/19/2012
 * Description: 
 *    
 *---------------------------------------------------------------------------*/
	virtual void onDeinit();

public:
	S32 m_serviceHandle; //service handle, if it is less than 0, it means invalid handle
	
private:	
	VappBtSettingPage* m_settingPage;

};

class VappBtTabCtrlPage : public VcpTabCtrlPage
{
public:
    virtual VfxPage *onCreateTabPage(VfxId tabId);
};

class VappBtSettingPage : public VfxPage
{
  //  VFX_DECLARE_CLASS(VappBtSettingPage);
public:

    void onSwitchVisibility(VcpFormItemSwitchCell* sender, VfxId senderid, VfxBool status);

    void onSetDevNameHdlr(VfxObject*, VcpInputPopupButtonEnum res);
/*---------------------------------------------------------------------------*
 * Function: on2ndInit()
 * Date:Feb/13/2012
 * Description: be called by VfxMainScr::on2ndReady(), to load some data.
 *    
 *---------------------------------------------------------------------------*/
	void on2ndInit();
    
    virtual void onEnter(VfxBool isBackward);

    void onButtonClick(VcpFormItemCell*, VfxId Id);

    void onEnterMSHdlr(void);

    void onExitMSHdlr(void);

    static void btSettingEventHandle(U32 event, void* para);
    static void storageCellUpdate();
    static VappBtSettingPage* m_btSettingPageSelf;
    
	VfxWString 	m_hostNameString;
protected:
    virtual void onInit();
    virtual void onDeinit();

private:

/*---------------------------------------------------------------------------*
 * Function: getHostName()
 * Date:Dec 1/2011
 * Description: remove duplicate codes.
 *    
 *    @return: return the host dev name string.
 *---------------------------------------------------------------------------*/
	VfxWString getHostName();

/*---------------------------------------------------------------------------*
 * Function: getDriveCount()
 * Date:Dec 1/2011
 * Description: get the count of the phone driver.
 *    
 *    @return: return the count of the phone driver.
 *---------------------------------------------------------------------------*/
	VfxU32 getDriveCount(srv_fmgr_drivelist_type_enum type);
    
private:
    //VcpForm *m_form;
    VcpFormItemSwitchCell* m_visibility;
    VcpFormItemLauncherCell* m_hostname;
    VcpFormItemLauncherCell* m_storage;
#ifdef __MTK_INTERNAL__
/* under construction !*/
#endif
	VcpForm * m_form;

    VfxS32 m_cmSrvHd;
};


// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
#define MMI_BT_MASK_ON                      0x01
#define MMI_BT_MASK_ON_IN_FLIGHT_MODE       0x02
#define MMI_BT_MASK_OFF_BY_FLIGHT_MODE      0x04
#define MMI_BT_MASK_ON_BY_FLIGHT_MODE       0x08
#define MMI_BT_MASK_JUST_NOTIFY_FLIGHT_MODE 0x10

typedef enum
{
    VAPP_BT_EVENT_INIT_POWER = VAPP_BT_MAIN + 1,
    VAPP_BT_EVENT_SWITCHH_FLIGHT_MODE,
    VAPP_BT_EVENT_TOTAL
} vapp_bt_event_enum;


class VappBtCm : public VfxObject
{
  //  VFX_DECLARE_CLASS(VappBtCm);
public:
    static void initCM(void* para);
    static void onInitPower(void);
    static VfxBool getInitPowerStatus(void);
    static void btCmEventHandle(U32 event, void* para);
    static void btCmPanicHandle(void);
    
    static VfxS32 m_cmSrvHd;
    static VfxU8 m_cmSetting;
    static VfxBool m_initPowerState;
    static VfxSignal2 <VfxS32, VfxS32> m_signalBtCm;
};


// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
typedef enum
{
    VAPP_BT_POWER_ON_CONFIRM = 1,
    VAPP_BT_POWER_OFF_CONFIRM,
    VAPP_BT_POWER_ENUM_TOTAL
} vapp_bt_power_confirm_type_enum;

class VappBtPowerSwitchCell: public VcpFormItemSwitchCell
{
	VFX_DECLARE_CLASS(VappBtPowerSwitchCell);
public:
    virtual void onInit();
    virtual void onDeinit();
    
public:
    void onSwitch(VcpFormItemSwitchCell* sender, VfxId senderid, VfxBool status);
    void onButtonClick(VfxObject* sender, VfxU32 id);
    void onReceiveBtCmEvent(VfxS32 event, VfxS32 result);
    static void btPowerSwitchEventHandle(U32 event, void* para);
    void btCmPanicHandle(void);
    static VappBtPowerSwitchCell* m_btPowerSwitchCellSelf;
private:
    void showConfirmScreen();
private:
    VfxS32 m_cmSrvHd;
    VfxU32 m_confirmFlag;
    VcpConfirmPopup* m_confirmPopup;
};


class VappBtSettingCell: public VcpFormItemLauncherCell
{
   VFX_DECLARE_CLASS(VappBtSettingCell);
public:
    virtual void onInit();
    virtual void onDeinit();
    void onTap(VcpFormItemCell* sender, VfxId senderId);
    
public:
    static void btSettingEventHandle(U32 event, void* para);
    static void onSwitchUpdateCell(VfxBool disableState);
    static VappBtSettingCell* m_btSettingSelf;
	
    void btCmPanicHandle(void);
	
    void onReceiveBtCmEvent(VfxS32 event, VfxS32 result);


private:
    VfxS32 m_cmSrvHd;
};

enum BtStatusNotify {
    BT_NOTIFY_ON,
    BT_NOTIFY_OFF,
    BT_NOTIFY_CONN_UP,
    BT_NOTIFY_CONN_DOWN,
    BT_NOTIFY_TRANS_BEGIN,
    BT_NOTIFY_TRANS_END,
    
};

void vapp_bt_update_status(BtStatusNotify status);

#endif  // __MMI_BT_SUPPORT__

#endif // __VAPP_BT_MAIN_H__
