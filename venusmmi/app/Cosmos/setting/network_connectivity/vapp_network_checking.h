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
 *  vapp_network_checking.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_NETWORK_CHECKING_H__
#define __VAPP_NETWORK_CHECKING_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/

// If all the turn on RF has no service, a query screen will be displayed
#ifdef __MMI_DUAL_SIM_DYNAMIC_MODE__
class VappNetworkCheckingController : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappNetworkCheckingController);
    // Methods
    public:
    // Check input SIM network service mode, if no service will display query popup
    void enableNetworkChecking(mmi_sim_enum sim);
    void enableNetworkCheckingforAllSim(void);
    void onNetworkUsablilityChange(mmi_sim_enum sim, VfxU8 status);
    void showChooseSimPop()
    {
		    showReconfigRfPopup();
		    resetCheckingStatus();    
    }
    
    private:
    VappNetworkCheckingController();
    virtual ~VappNetworkCheckingController();
    void showReconfigRfPopup();
    void resetCheckingStatus();

    public:
    static void onConfirmPopupClicked(VfxId id, void *userData);
    static MMI_BOOL onNmgrNotified(mmi_scenario_id scenarioId, void *userData);
    static mmi_ret onEntryRfSelectScreen(mmi_event_struct evt);
    
    // Variables
    protected:
    VfxBool m_isSimNoService[MMI_SIM_TOTAL];
    VfxBool m_isCheckingEnabled;
};


class VappNetworkCheckingMainScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappNetworkCheckingMainScr);
    // Overrides
    protected:
    virtual void on1stReady();
    virtual void onDeinit() {VfxMainScr::onDeinit(); m_isAvailable = VFX_FALSE;}

    // Methods
    public:
    VappNetworkCheckingMainScr();

    void onRfSelectPopupClicked(VfxObject *obj, VfxId id);
    void switchFinished(VfxBool result);
    static mmi_ret onRfSwitchFinished(mmi_event_struct *evt);
    static VfxBool isMainScrAvailable() {return m_isAvailable;}

    protected:
    void showRfSwitchPopup();
    // Variable
    public:
    static VfxBool m_isAvailable;
    VfxSignal0     m_signalClose;
    protected:
    VcpSelectPopup    *m_queryPopup;
    VcpIndicatorPopup *m_indPopup;
};

class VappNetworkCheckingApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappNetworkCheckingApp);
    // Overrides
    protected:
    virtual void onRun(void * args, VfxU32 argSize);

    public:
    void onClose();
};
#endif /* __MMI_DUAL_SIM_DYNAMIC_MODE__ */


#ifdef __MMI_NETSET_3G_ENHANCE__
class VappManualNetworkCheckingController : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappManualNetworkCheckingController);
    // Methods
    public:
    // Check input SIM network service mode, if no service and it is in manual network selection mode
    // a query popup will be displayed, currently only support SIM1
    void enableNetworkChecking(mmi_sim_enum sim);
    void onNetworkUsablilityChange(mmi_sim_enum sim, VfxU8 status); 
    
    
    private:
    VappManualNetworkCheckingController();
    ~VappManualNetworkCheckingController();
    void showNetworkSearchPopup();
    void resetCheckingStatus();

    public:
    static void onConfirmPopupClicked(VfxId id, void *userData);
    static MMI_BOOL onNmgrNotified(mmi_scenario_id scenarioId, void *userData);
    
    // Variables
    protected:
    VfxBool m_isSimNoService;
    VfxBool m_isCheckingEnabled;
};

// Display the menu of network selection
class VappManualNetworkCheckingApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappManualNetworkCheckingApp);
    // Overrides
    protected:
    virtual void onRun(void * args, VfxU32 argSize);

    public:
    void onNwSelectPageReady();

    protected:
    VfxMainScr *m_mainScr;
    VfxPage *m_nwSelectPage;
};
#endif /* __MMI_NETSET_3G_ENHANCE__ */

#endif /* __VAPP_NETWORK_CHECKING_H__ */
 
