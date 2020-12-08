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
 *  vapp_sat.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file implements application functions for SAT feature.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SAT_H__
#define __VAPP_SAT_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

#ifdef __cplusplus
extern "C"{
#endif

#include "MMIDataType.h"
#include "mmi_frm_utility_gprot.h"
#include "UcmSrvGprot.h"
#include "SatSrvGprot.h"

#ifdef __cplusplus
    }
#endif

#include "vsrv_notification.h"
#include "vsrv_ncenter.h"
#include "vapp_ncenter_base_cell.h"




/***************************************************************************** 
 * Define
 *****************************************************************************/
// layout

#if defined(__MMI_MAINLCD_320X480__)
    // Event default cell
    #define VAPP_SAT_NCENTER_EVENT_CELL_HEIGHT              (51)
    #define VAPP_SAT_NCENTER_EVENT_CELL_ICON_X              (10)
    #define VAPP_SAT_NCENTER_EVENT_CELL_ICON_Y              (5)
    #define VAPP_SAT_NCENTER_EVENT_CELL_ICON_WIDTH          (30)
    #define VAPP_SAT_NCENTER_EVENT_CELL_ICON_HEIGHT         (30)

    #define VAPP_SAT_NCENTER_EVENT_CELL_TEXT_SIZE           (20)
    #define VAPP_SAT_NCENTER_EVENT_CELL_MAIN_TEXT_X         (50)
    #define VAPP_SAT_NCENTER_EVENT_CELL_TEXT_WIDTH          (200)

#elif defined(__MMI_MAINLCD_480X800__)
    // Event default cell
    #define VAPP_SAT_NCENTER_EVENT_CELL_HEIGHT              (86)
    #define VAPP_SAT_NCENTER_EVENT_CELL_ICON_X              (14)
    #define VAPP_SAT_NCENTER_EVENT_CELL_ICON_Y              (10)
    #define VAPP_SAT_NCENTER_EVENT_CELL_ICON_WIDTH          (35)
    #define VAPP_SAT_NCENTER_EVENT_CELL_ICON_HEIGHT         (35)

    #define VAPP_SAT_NCENTER_EVENT_CELL_TEXT_SIZE           (35)
    #define VAPP_SAT_NCENTER_EVENT_CELL_MAIN_TEXT_X         (67)
    #define VAPP_SAT_NCENTER_EVENT_CELL_TEXT_WIDTH          (400)

#else
    // Event default cell
    #define VAPP_SAT_NCENTER_EVENT_CELL_HEIGHT              (51)
    #define VAPP_SAT_NCENTER_EVENT_CELL_ICON_X              (10)
    #define VAPP_SAT_NCENTER_EVENT_CELL_ICON_Y              (5)
    #define VAPP_SAT_NCENTER_EVENT_CELL_ICON_WIDTH          (30)
    #define VAPP_SAT_NCENTER_EVENT_CELL_ICON_HEIGHT         (30)

    #define VAPP_SAT_NCENTER_EVENT_CELL_TEXT_SIZE           (20)
    #define VAPP_SAT_NCENTER_EVENT_CELL_MAIN_TEXT_X         (50)
    #define VAPP_SAT_NCENTER_EVENT_CELL_TEXT_WIDTH          (200)

#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef enum
{
    VAPP_SAT_USER_ACT,
    VAPP_SAT_SIM_ACT,

    VAPP_SAT_ACT_END
} VappSatLaunchModeEnum;

typedef struct
{
    VappSatLaunchModeEnum act;
    mmi_sim_enum simId;
    srv_sat_cmd_enum cmdType;
} VappSatParam;

typedef enum
{
    VAPP_SAT_MAIN_SCRN,
    VAPP_SAT_SNAP_SCRN_SIM1,
#if (MMI_MAX_SIM_NUM >= 2)
    VAPP_SAT_SNAP_SCRN_SIM2,

#if (MMI_MAX_SIM_NUM >= 3)
    VAPP_SAT_SNAP_SCRN_SIM3,

#if (MMI_MAX_SIM_NUM >= 4)
    VAPP_SAT_SNAP_SCRN_SIM4,

#endif
#endif
#endif /* MMI_MAX_SIM_NUM >= 2 */

    VAPP_SAT_SCRN_END
} VappSatScreenIdEnum;


/***************************************************************************** 
 * Function
 *****************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

mmi_ret vapp_sat_handle_instant_cmd(srv_sat_proactive_sim_struct *cmd_info);
MMI_BOOL vapp_sat_app_pre_launch(mmi_scenario_id scen_id, void *arg);

void vapp_sat_display_text_process(srv_sat_proactive_sim_struct *cmd_info);
void vapp_sat_setup_call_process(srv_sat_proactive_sim_struct *cmd_info);
void vapp_sat_send_dtmf_process(srv_sat_proactive_sim_struct *cmd_info);

void vapp_sat_user_launch(void);
void vapp_sat_sim_launch(srv_sat_proactive_sim_struct *cmd_info);

void vapp_sat_cmd_session_end(srv_sat_proactive_sim_struct *cmd_info);

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Class VappSatNcell
 *****************************************************************************/

class VappSatContextNcell : public VappNCenterEventCell
{
	//VFX_DECLARE_CLASS(VappSatContextNcell);

public:
	VappSatContextNcell();
	virtual ~VappSatContextNcell();

public:
	virtual void onInit();
	virtual void updateElements();
    void createBaseCellWithMarquee(void *viewData);
private:
	VcpMarquee *m_cText;


};

class VappSatNcell : public VsrvNCell
{
	VFX_DECLARE_CLASS(VappSatNcell);
	
protected:
	virtual void onCreateView(void * viewData,VfxU32 viewDataSize);


private:
	VappSatContextNcell *m_notification;
};


/***************************************************************************** 
 * Class VappSatMgr
 *****************************************************************************/

class VappSatMainScrn;
class VappSatPopupScrn;

class VappSatMgr : VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappSatMgr);

private:
    VappSatMgr();

public:
    VappSatMainScrn *getScrn(VappSatScreenIdEnum scrnId);

    void setMainScrn(VappSatMainScrn *scrn);
    VappSatMainScrn *getMainScrn();

    void setSnapScrn(mmi_sim_enum simId, VappSatMainScrn *scrn);
    VappSatMainScrn *getSnapScrn(mmi_sim_enum simId);

    void setMainMenuItemIndex(mmi_sim_enum simId, VfxS32 index);
    VfxS32 getMainMenuItemIndex(mmi_sim_enum simId);

private:
    VfxU32 simId2Index(mmi_sim_enum simiId);

private:
    VappSatMainScrn *m_satMainScrn[VAPP_SAT_SCRN_END];
    VfxS32  m_menuItemIndex[MMI_SIM_TOTAL + 1];
};


/***************************************************************************** 
 * Class VappSatApp
 *****************************************************************************/

class VappSatApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappSatApp);

public:
    VappSatApp();
    virtual ~VappSatApp(){};

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onRun(void* args, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);

private:
    //Multi main screen
    VfxBool showScreen(const VappSatParam *param);
    static mmi_ret onRecvInd(mmi_event_struct *evt); /* global event handler */
    VfxBool checkBeforeClose();
    //void languageNotification(srv_sat_language_notification_struct *language);
    void languageNotification(srv_sat_proactive_sim_struct *cmd_info);

public:
    static mmi_ret onRecvSatSrvInd(srv_sat_proactive_sim_struct *cmd_info);	
    static mmi_ret onRecvIdleInd(mmi_event_struct *evt);	
    static void onLangNotifyBtnTapped(VfxId id, void *user_data);
    static mmi_ret langAsyncSwitch(mmi_event_struct *evt);
    static mmi_ret langResponse(mmi_event_struct *evt);

private:
    void onRegIndHdlr();
    void onDeRegIndHdlr();
	void simRefreshProcess(srv_sat_proactive_sim_struct *cmd_info);
	void showPopup(VfxWString string,  mmi_sim_enum simId);
	void showResetPopup(VfxWString string,  mmi_sim_enum simId);
	void onResetPhone(VfxObject* obj, VfxId id);
	
	//VcpConfirmPopup *resetPopup;

public:
	VcpIndicatorPopup *popupInfo;


  //  VfxBool m_endEvt;
};


/***************************************************************************** 
 * Class VappSatMainScrn
 *****************************************************************************/
class VappSatBasePage;

class VappSatMainScrn : public VfxMainScr
{
    //VFX_DECLARE_CLASS(VappSatMainScrn);

public:
	VappSatMainScrn(){};
   // VappSatMainScrn(mmi_sim_enum simId);
    VappSatMainScrn(VappSatLaunchModeEnum act, mmi_sim_enum simId, srv_sat_cmd_enum cmdType);
	virtual ~VappSatMainScrn(){};

    mmi_sim_enum getScrnSimId() const;
    srv_sat_cmd_enum getScrnCmdType() const;
    void setScrnCmdType(srv_sat_cmd_enum cmdType);

	void showPage();

// Override
protected:
    virtual void onInit();
    virtual void on1stReady();
    virtual void onDeinit();
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);

    static mmi_ret onRecvSatInd(mmi_event_struct *evt);
    static mmi_ret onRecvUcmInd(mmi_event_struct *evt);

private:
    //VfxBool isPopup(srv_sat_cmd_enum cmdType);
    S32 getSatReadyNum();

    static mmi_sim_enum callTypeToSimId(srv_ucm_call_type_enum call_type);

    void onRegIndHdlr();
    void onDeRegIndHdlr();
	void onResponse();

private:
    VappSatLaunchModeEnum   m_act;
    mmi_sim_enum            m_simId;
    srv_sat_cmd_enum        m_cmdType;
    VfxWeakPtr <VfxPage>    m_page;
	VfxS32  				m_rflag;
};


/***************************************************************************** 
 * Class VappSatPopupScrn
 *****************************************************************************/
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
#endif /* __VAPP_SAT_H__ */
