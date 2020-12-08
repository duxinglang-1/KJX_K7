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
 *  vapp_dm_session.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Device management session UI header file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DM_SESSION_H__
#define __VAPP_DM_SESSION_H__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_tabctrl_page.h"
#include "vcp_list_menu.h"
extern "C"
{
#include "DmSrvIprot.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/
/***************************************************************************** 
 * Function
 *****************************************************************************/
 
extern MMI_BOOL vappDmSessionNotificationNmgrHdlr(mmi_scenario_id scenarioId, void *arg);
extern MMI_BOOL vappDmSessionAlertNmgrHdlr(mmi_scenario_id scenarioId, void *arg);
extern void vappDmSessiondisplayEndingMsg(srv_dm_app_adp_session_ending_msg_enum endingMsg);

/***************************************************************************** 
 * Class VappDmSessionNotificationMainScrn
 *****************************************************************************/

class VappDmSessionNotificationMainScrn : public VfxAppScr
{
    VFX_DECLARE_CLASS(VappDmSessionNotificationMainScrn);

// Constructor / Destructor
public:
    VappDmSessionNotificationMainScrn();
    ~VappDmSessionNotificationMainScrn();

private:
    void displayInfo();
    void infoScrnBtnHdlr(VfxObject* obj, VfxId id);
    void infoTimeoutHdlr(VfxTimer *obj);
    void displayCnf();
    void cnfTimeoutHdlr(VfxTimer *obj);
    void cnfScrnBtnHdlr(VfxObject* obj, VfxId id);
    void rspSrv(dm_ui_interaction_enum result);
// Override
protected:
    virtual void onInit();

// Method
public:

// Variable
private:
    VfxBool m_rspSrv;
};


/***************************************************************************** 
 * Class VappDmSessionNotification
 *****************************************************************************/

class VappDmSessionNotification : public VfxApp
{
    VFX_DECLARE_CLASS(VappDmSessionNotification);

// Constructor / Destructor
public:
    VappDmSessionNotification() {}
    ~VappDmSessionNotification() {}

// Method
public:
    virtual void onRun(
        void* args,
        VfxU32 argSize
    );

    dm_ui_mode_enum getUiMode();

// Method
private:
    void sessionFinishHdlr();
// Variable

// Override

// Declaration

// Variable
private:
    dm_ui_mode_enum m_uiMode;
};


/***************************************************************************** 
 * Class VappDmSessionAlertInfoPage
 *****************************************************************************/

class VappDmSessionAlertInfoPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappDmSessionAlertInfoPage);

// Constructor / Destructor
public:
    VappDmSessionAlertInfoPage() {}
    ~VappDmSessionAlertInfoPage() {}

private:
    void displayTimeoutHdlr(VfxTimer *obj);
    void toolbarEventHdlr(VfxObject* obj, VfxId itemId);
// Override
protected:
    virtual void onInit();
};


/***************************************************************************** 
 * Class VappDmSessionAlertInfoPage
 *****************************************************************************/

class VappDmSessionAlertCnfPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappDmSessionAlertCnfPage);
private:
    enum VappDmSessionAlertCnfToolbarItemEnum
    {
        TOOLBAR_ITEM_OK,
        TOOLBAR_ITEM_CANCEL,
        TOOLBAR_ITEM_TOTAL
    };

// Constructor / Destructor
public:
    VappDmSessionAlertCnfPage() {}
    ~VappDmSessionAlertCnfPage() {}

private:
    void cnfTimeoutHdlr(VfxTimer *obj);
    void toolbarEventHdlr(VfxObject* obj, VfxId itemId);
// Override
protected:
    virtual void onInit();
};


/***************************************************************************** 
 * Class VappDmSessionAlertMainScrn
 *****************************************************************************/

class VappDmSessionAlertMainScrn : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappDmSessionAlertMainScrn);

// Constructor / Destructor
public:
    VappDmSessionAlertMainScrn();
    ~VappDmSessionAlertMainScrn();

public:
    void rspSrv(dm_alert_rsp_struct *alertRsp);

private:
    void displayInfo();
    void displayCnf();
    void cnfScrnBtnHdlr(VfxObject* obj, VfxId id);
// Override
protected:
    virtual void on1stReady();

// Method
public:

// Variable
private:
    VfxBool m_rspSrv;
};


/***************************************************************************** 
 * Class VappDmSessionAlert
 *****************************************************************************/

class VappDmSessionAlert : public VfxApp
{
    VFX_DECLARE_CLASS(VappDmSessionAlert);

// Constructor / Destructor
public:
    VappDmSessionAlert() {}
    ~VappDmSessionAlert() {}

// Method
public:
    virtual void onRun(
        void* args,
        VfxU32 argSize
    );

    dm_alert_struct *getAlertPtr();

// Method
private:
    void sessionFinishHdlr();
// Variable

// Override

// Declaration

// Variable
private:
    dm_alert_struct *m_alert;
};

#endif /* __VAPP_DM_SESSION_H__ */

