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
 *  vapp_ss.h
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

#ifndef __VAPP_SS_H__
#define __VAPP_SS_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMIDataType.h" /* mmi_sim_enum */

#include "vfx_datatype.h"
#include "vfx_app.h"
#include "vfx_page.h"
#include "vfx_main_scr.h"
#include "vfx_signal.h"
#include "vfx_weak_ptr.h"
#include "vcp_menu_popup.h"
#ifdef __VAPP_SS_SHOW_IN_NCENTER__
#include "vsrv_ndeclaration.h"
#include "vsrv_notification.h"
#endif // __VAPP_SS_SHOW_IN_NCENTER__
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef enum
{
    SS_TYPE_REQUESTING,
    SS_TYPE_USSD,
    SS_TYPE_USSR,
    SS_TYPE_USSN,
    SS_TYPE_ABORT,
    SS_TYPE_EXPIRE,
    SS_TYPE_CANCEL,
    SS_TYPE_INT_HIDE, /* internal type (between nCell and SS app) */
    SS_TYPE_UNKNOWN
} vapp_ss_type_enum;

typedef struct
{
    mmi_sim_enum sim;
    vapp_ss_type_enum type;
    VfxWString msg;
	VfxObjHandle timerObjHandle;
} vapp_ss_msg_struct;

typedef struct 
{
	mmi_id 		 appId;
	VfxResId	 strId;
}VappSsNcellInfo;


/***************************************************************************** 
 * Class VappSsNCell
 *****************************************************************************/
//class VsrvNotification;
class VappSsApp;
class VappSsNCell : public VfxObject
{
	VFX_OBJ_DECLARE_SINGLETON_CLASS(VappSsNCell);
	
protected:
	VappSsNCell(){}

protected:
	virtual void onInit();

public:
    void onActNotify(mmi_event_struct* info);
    void onIndication(mmi_event_struct* info);
	void showNotify(vapp_ss_msg_struct *msg, VfxBool isShowSimX = VFX_TRUE);
#ifdef __VAPP_SS_SHOW_IN_NCENTER__
    void onIntMsg(vapp_ss_msg_struct *msg);
    void onNCenterLeave(mmi_sim_enum sim);
	void createNotify(vapp_ss_msg_struct *msg);
	void releaseNotify(mmi_sim_enum sim);
    void closeAlertHandle(mmi_sim_enum sim);
    void onClearAll();
#endif // __VAPP_SS_SHOW_IN_NCENTER__
    virtual vrt_allocator_handle getAllocator();
    void entryApp(vapp_ss_msg_struct *msg);

private:
	vapp_ss_msg_struct *getMsg(mmi_sim_enum sim);
	VappSsApp *getApp(mmi_sim_enum sim);
    void onTimeOut(VfxTimer *sender);
    VfxBool notifyApp(vapp_ss_msg_struct *msg);
#ifdef __VAPP_SS_SHOW_IN_NCENTER__
	static void notifyIntentCallback(
								VsrvNotification* noti, 
								VsrvNIntent intent, 
								void* userData, 
								VfxU32 userDataSize);
    NMGR_HANDLE m_alertHandle[MMI_MAX_SIM_NUM];
#endif // __VAPP_SS_SHOW_IN_NCENTER__
	vapp_ss_msg_struct m_msg[MMI_MAX_SIM_NUM];
};

/***************************************************************************** 
 * Class VappSsSmallScr
 * this small screen is used to show sending request
 *****************************************************************************/
class VappSsSmallScr : public VfxAppScr
{

public:
    // Constructor
    VappSsSmallScr()
    {
    	setIsSmallScreen();
    }
};

// VappSsSmallScr is used to ask user to select 1 sim
// actually, other APP will always send SS using 1 definite sim
#ifdef __VAPP_SS_SELCET_SIM__
#if (MMI_MAX_SIM_NUM >= 2)
/***************************************************************************** 
 * Class  VappSsApp
 *****************************************************************************/
class VcpMenuPopup;
class VappSsSimSelScr : public VappSsSmallScr
{

// Constructor
public:
	VappSsSimSelScr(const mmi_sim_enum &simSel = MMI_SIM1) : VappSsSmallScr(), m_sim(simSel){}

// Interface
public:
	void processSimChange(mmi_event_struct *);
	
	VfxSignal1<VfxId> m_signalSimSelect;
// Override
protected:
	void onInit();
	void onDeinit();
	void onEnter(VfxBool isBackward);

// Implement
private:
	void onMenuCallack(VcpMenuPopup* menu, VcpMenuPopupEventEnum evt, VcpMenuPopupItem *item);
	static mmi_ret hdlrSimAvailabilityChange(mmi_event_struct *evt);

private:
	VfxWeakPtr<VcpMenuPopup> m_menuPopupWeakPtr;
	mmi_sim_enum m_sim;
};
#endif // MMI_MAX_SIM_NUM
#endif // __VAPP_SS_SELCET_SIM__

/***************************************************************************** 
 * Class  VappSsApp
 *****************************************************************************/
class VappSsApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappSsApp);

public:
	VappSsApp();
	
// Interface
public:
	static mmi_ret processIntercept(mmi_event_struct *para);
	static VfxResId getSimStrId(mmi_sim_enum sim);
	static mmi_id getAppId(mmi_sim_enum sim);
	static void popupCallback(VfxId id, void *userData);

	void onEvent(vapp_ss_msg_struct* msg);
	VfxBool isAborting(void) { return m_localAbort; }
	vapp_ss_msg_struct m_msg;

	enum
	{
		LAUNCH_ID_SIM_SELECTION,
		LAUNCH_ID_REQUESTING,
		LAUNCH_ID_MSG,
		LAUNCH_ID_TOTAL,
	};
// Override
protected:
	virtual void onDeinit();
	virtual void onRun(void* args, VfxU32 argSize);
    virtual void onGroupActive();
    virtual void onGroupInactive();

// Implement
private:
#ifdef __VAPP_SS_SELCET_SIM__
  #if (MMI_MAX_SIM_NUM >= 2)
	void onSimSelect(VfxId id);
  #endif // MMI_MAX_SIM_NUM
#endif // __VAPP_SS_SELCET_SIM__
    void onAbort(VfxObject* obj, VfxFloat id);
    void terminateApp(VfxObject* sender, VfxId id);
	void onPopState(VfxBasePopup *sender, VfxBasePopupStateEnum state);
    VfxBool sendSS(const mmi_sim_enum sim, const VfxWChar *ss, const VfxU32 &len);

    VfxMainScr *m_scr;
	VfxWeakPtr<VfxMainScr> m_scrWeakPtr;
    VappSsSmallScr *m_smallScr;
    VfxBool m_localAbort;
    VfxBool m_isRequsting;
	void *m_data;

	static const VfxId s_interceptExcludeModID[];
	static const VappSsNcellInfo s_NcellInfo[MMI_MAX_SIM_NUM];
};


/***************************************************************************** 
 * Class  VappSsPageMsg
 *****************************************************************************/
class VcpToolBar;
class VcpTextEditor;
class VappSsPageMsg : public VfxPage
{
// Override
protected:
    virtual void onInit();

private:
    void onToolBarTapped(VfxObject* sender, VfxId id);
    void onTextChanged(VcpTextEditor* editor);

    VappSsApp *m_app;
    VcpToolBar *m_toolBar;
    VcpTextEditor *m_textInput;

};


#endif /* __VAPP_SS_H__ */

