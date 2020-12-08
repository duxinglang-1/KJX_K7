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
 *  vapp_bootup_app.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  App of Venus bootup UI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_BOOTUP_APP_H__
#define __VAPP_BOOTUP_APP_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#include "MMIDatatype.h"

extern "C"
{
#include "BootupSrvIprot.h"
#include "SimCtrlSrvGprot.h"
}

#include "GlobalResDef.h"
#include "mmi_rp_vapp_bootup_def.h"

#include "vfx_datatype.h"
#include "vfx_app.h"
#include "vfx_main_scr.h"
#include "vfx_string.h"
#include "vfx_weak_ptr.h"

#include "vcp_popup_data_type.h"

#include "vapp_password_page_gprot.h"

/***************************************************************************** 
 * Global function
 *****************************************************************************/
extern "C" mmi_ret vapp_bootup_sec_on_sim_status_changed(mmi_event_struct *evt);


/***************************************************************************** 
 * Class VappBootupApp
 *****************************************************************************/

// Bootup main app used to show UI.
// This app class only focuses on individual steps by providing independent
// function/variable set for each step. The main flow is controlled by
// vapp_bootup_flow.cpp
class VappAniPage;
class VappPasswordPage;
class VcpIndicatorPopup;
class VfxBasePopup;
class VappBootupApp : public VfxApp, public IVfxMainScrHandler
{
    VFX_DECLARE_CLASS(VappBootupApp);
	
public:
    VappBootupApp() :
        m_mainScr(NULL),
        m_waitingInd(NULL),
        m_callbackProc(NULL),
        m_callbackUserData(NULL)
    {
    }

	VfxBool checkDisk(mmi_proc_func proc, void *userData);
#if (MMI_MAX_SIM_NUM >= 2)
	void decideMode(mmi_proc_func proc, void *userData);
#endif

	/* For Animation*/
    void playAnimation(mmi_proc_func proc, void *userData);
	VappAniPage *createAniPage(void);


    void showMainScr()
    {
        if (m_mainScr != NULL && !m_mainScr->isShown())
        {
            m_mainScr->show();
        }
    }
	
	VfxMainScrEx *getMainScr(void)
	{
		return m_mainScr;
	};
	
    //void showWaiting(const VfxWString &msg = VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT));
	void showWaiting(const VfxResId msg_id = STR_GLOBAL_PLEASE_WAIT);
    void closeWaiting(VfxBool isAnim = VFX_TRUE);
	
public:
    // After push a page, the m_mainScr may not show yet. Be sure to
    // call showMainScr()
    // To close a page which we may not know its existence, call
    // closePage() instead of operating m_mainScr directly
    enum PageEnum
    {
        PAGE_BEGIN = 0,         // We should not use 0 for page ID
        PAGE_DISK_CHECK,        // Disk check page
        PAGE_SIM_SELECTION,     // Select SIM on multiple SIM project
        PAGE_ANIMATION,         // Animation page
        PAGE_PREINSTALL_WIDGETS, // Pre-install widgets

        
        /* Add fix page enum before here */
        PAGE_VERIFICATION,      // Begin of page ID for verifications. The following value
                                // should be reserved for verification.

        PAGE_END_OF_ENUM
    };

    enum event_enum
    {
        EVT_ID_DISK_CHECKED,
        EVT_ID_MODE_DECIDED,
        EVT_ID_ANIMATION_COMPLETED,
        EVT_ID_SEC_VERI_COMPLETED,

        EVT_ID_EVENT_END_OF_ENUM
    };

    typedef struct
    {
        MMI_EVT_PARAM_HEADER
    
        U32 enabled_sims;
    } mode_decided_evt_struct;

    typedef mmi_event_struct
        disk_checked_evt_struct,
        animation_completed_evt_struct,
        sec_veri_completed_evt_struct;

    // Get bootup application
    static VappBootupApp* getApp()
    {
        return s_singletonApp;
    }

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
	virtual void onScr1stReady(VfxMainScrEx *scr);
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption option);

// Implement
private:  
    void closePage(VfxId pageId);
    
    void onDiskCheckMessageConfirmed();
    
#if (MMI_MAX_SIM_NUM >= 2)
    void onUserDecidedMode(VfxU32 enabledSims);
#endif

    void onAniPlayCompleted(VappAniPage *aniPage);

	/* For Animation*/
	void onSetAniComplete(VappAniPage *obj, VfxS32 result);
	VfxBool isPlayTone(void);
	void playAniTone(void);
	
private:
    // Points to the singleton app instance
    static VappBootupApp *s_singletonApp;

    // Main screen
    VfxMainScrEx *m_mainScr;
    
    // Instance for waiting indicator, maintained by showWaiting(), closeWaiting()
    VcpIndicatorPopup *m_waitingInd; 
    
    /* For C-style event callback */

    // Proc pointer for callback
    mmi_proc_func m_callbackProc;
    // User data pointer for callback
    void *m_callbackUserData;
};


/***************************************************************************** 
 * Class VappBootupConfigSimPage
 *****************************************************************************/
#if (MMI_MAX_SIM_NUM >= 2)
class VcpButton;
class VcpSwitch;
class VappStyleDyer;
class VappBootupConfigSimPage : public VfxPage
{
public:
    VappBootupConfigSimPage() : m_okBtn(NULL)
    {
        m_simModeSwitch[0] = NULL;
    }
	VfxSignal1<VfxU32> m_signalDone;

protected:
    virtual void onInit();

private:
    //void onOkBtnClicked(VfxObject *obj, VfxId id);
    void onOkBtnClicked(VfxId id);
    VfxS32 createHorizontalLine(VfxS32 x, VfxS32 y, VfxS32 len);
	void onSwitch(VcpFormItemSwitchCell* item, VfxId id, VfxBool state);
private:
    enum LayoutConfig
    {
#if defined(__MMI_MAINLCD_480X800__)
        MARGIN = 20,
        PROMPT_TEXT_FONT_SIZE = 28,
        PROMPT_TEXT_BOTTOM_Y = 94,
        PROMPT_TEXT_HEIGHT = 28,
        FORM_ITEM_TEXT_FONT_SIZE = 34,
        FORM_ITEM_SUB_TEXT_FONT_SIZE = 30,
        CONFIG_FORM_Y = 120,
        OK_BUTTON_MARGIN_ABOVE = 40,
        OK_BUTTON_HEIGHT = 80,
        LINE_WIDTH = 1,
#elif defined(__MMI_MAINLCD_240X320__)
        MARGIN = 8,
        PROMPT_TEXT_FONT_SIZE = 15,
        PROMPT_TEXT_BOTTOM_Y = 24,
        PROMPT_TEXT_HEIGHT = 16,
        FORM_ITEM_TEXT_FONT_SIZE = 18,
        FORM_ITEM_SUB_TEXT_FONT_SIZE = 16,
        CONFIG_FORM_Y = 34,
        OK_BUTTON_MARGIN_ABOVE = 10,
        OK_BUTTON_HEIGHT = 42,
        LINE_WIDTH = 1,
#elif defined(__MMI_MAINLCD_240X400__)
        MARGIN = 8,
        PROMPT_TEXT_FONT_SIZE = 15,
        PROMPT_TEXT_BOTTOM_Y = 34,
        PROMPT_TEXT_HEIGHT = 16,
        FORM_ITEM_TEXT_FONT_SIZE = 18,
        FORM_ITEM_SUB_TEXT_FONT_SIZE = 16,
        CONFIG_FORM_Y = 52,
        OK_BUTTON_MARGIN_ABOVE = 22,
        OK_BUTTON_HEIGHT = 42,
        LINE_WIDTH = 1,
#else /* __MMI_MAINLCD_320X480__ */
        MARGIN = 10,
        PROMPT_TEXT_FONT_SIZE = 20,
        PROMPT_TEXT_BOTTOM_Y = 78,
        PROMPT_TEXT_HEIGHT = 20,
        FORM_ITEM_TEXT_FONT_SIZE = 20,
        FORM_ITEM_SUB_TEXT_FONT_SIZE = 18,
        CONFIG_FORM_Y = 98,
        OK_BUTTON_MARGIN_ABOVE = 30,
        OK_BUTTON_HEIGHT = 45,
        LINE_WIDTH = 1,
#endif

        END_OF_LAYOUT_CONSTANT
    };
	enum BootupCfgItemEnum
	{
		SIM1,
		SIM2,
	#if	(MMI_MAX_SIM_NUM >= 3)
		SIM3,
	#if (MMI_MAX_SIM_NUM >= 4)
		SIM4,
	#endif
	#endif
		Button
	};
    
    //VcpButton *m_okBtn;
    //VcpSwitch *m_simModeSwitch[MMI_SIM_TOTAL];
    VcpFormItemBigButton *m_okBtn;
	VcpFormItemSwitchCell *m_simModeSwitch[MMI_SIM_TOTAL];
	VcpForm *m_form;
};
#endif

/***************************************************************************** 
 * Helper Function
 *****************************************************************************/
namespace VappBootupSimStr
{
    VfxResId getSimStrByIndex(VfxS32 sim_index);

    VfxWString composeSimStr(
        VfxResId str_template_id,
        mmi_sim_enum sim);

    VfxWString getInputPrompt(
        mmi_sim_enum sim,
        srv_bootup_verification_type_enum veri_type);
        
    VfxWString getMessageOfResult(
        const srv_bootup_verify_result_struct *result);

    VfxWString getSimErrorMsg(mmi_sim_enum sim, srv_sim_ctrl_ua_cause_enum cause);

    VfxWString getRemainingPromptStr(
        S32 nRemainingAttempts,
        VfxObject *tempBufferSrc);

    VfxWString getFailureMsgWithRemaining(
        const VfxWString &prompt,
        S32 nRemainingAttempts,
        VfxObject *tempBufferSrc);
};

#endif /* __VAPP_BOOTUP_APP_H__ */

