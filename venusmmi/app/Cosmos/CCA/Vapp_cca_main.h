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
 *  vapp_cca_main.h
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_CCA_MAIN_H__
#define __VAPP_CCA_MAIN_H__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "Vapp_cca_screen.h"

typedef enum
{
    VAPP_CCA_EVENT_PIN_CHECK = 0,
    VAPP_CCA_EVENT_PRE_INSTALL,
    VAPP_CCA_EVENT_INSTALL_LIST,
    VAPP_CCA_EVENT_INSTALL_RESULT,
    VAPP_CCA_EVENT_INSTALL_FINISHED,
    VAPP_CCA_EVENT_INVALID_MSG,
    VAPP_CCA_EVENT_NOTIFY,
    VAPP_CCA_EVENT_CLOSE_AP,  
    VAPP_CCA_EVENT_MAX_ITEM
} vapp_cca_event_enum;

#ifndef __MMI_PROV_IN_UM__
class VappCCANotifyMgr : public VfxBase
{ 
public:    
    static void viewNewSettingMsg(void);
    static void showInstallingPopup(void);
    static void createNSS(void);
    static void clearNSS(void);  
    static mmi_ret nssIntentCallback(mmi_event_struct *param);       
    static void createNcenterCell(void);
    static void clearNcenterCell(void);     
    static void ncenterIntentCallback(VsrvNotification* noti, VsrvNIntent intent, void* data, VfxU32 size);

   
public:
	static NMGR_HANDLE m_nssHandle;	
};
#endif /* __MMI_PROV_IN_UM__ */

class VappCCAInstMgr : public VfxObject
{
public:
    VappCCAInstMgr()
    {
        m_inst = NULL;
    }

    static VappCCAInstMgr* getInstance(void);
    void addInst(VfxObject *inst)
    {
        m_inst = inst;
    }
    void removeInst(VfxObject *inst)
    {
        if (m_inst == inst)
        {
            m_inst = NULL;
        }
    }
    VfxBool hasInst(void)
	{
		return (m_inst != NULL)? VFX_TRUE: VFX_FALSE;
	}
    VfxObject* getInst(void)
    {
        return m_inst;
    }
    
public:
    VfxSignal2 <vapp_cca_event_enum, mmi_event_struct*> m_eventSignal;
    
private:
    //VfxObjList m_instList;
    VfxObject *m_inst;
    static VappCCAInstMgr *m_singleInst;
    static VfxU32 m_instBuf[];
};

class VappCCACui : public VfxCui
{
    VFX_DECLARE_CLASS(VappCCACui);

public:
    typedef enum
    {
        MMI_STATE_IDLE = 0,
        MMI_STATE_PIN,
        MMI_STATE_PIN_FAIL,
        MMI_STATE_PRE_INSTALL,
        MMI_STATE_INSTALL_LIST,
        MMI_STATE_INSTALLING,
        MMI_STATE_INSTALL_RESULT,
        MMI_STATE_MAX_ITEM
    } mmi_state_enum;
    
public:
    VappCCACui();
    virtual ~VappCCACui();

    VfxMainScr* getMainScreen(void)
    {
        return m_screen;
    }
    void        setInstId(mmi_id instId)
    {
        m_instId = instId;
    }
    mmi_id      getInstId(void)
    {
        return m_instId;
    }
    
protected:
	
	using VfxApp::onProcessClose;
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);   
    virtual void onRun(void* args, VfxU32 argSize);   
    
private:
    void terminate(void);
    void onCCAEvent(vapp_cca_event_enum event, mmi_event_struct *data);
    void onScreenSel(screen_sel_result_enum result, VappCCAMMIDataPack* data);
    void onScreenClose(void);
    void openMainScreen(void);
    void closeMainScreen(void);
    void openPinScreen(void);
    void closePinScreen(void);
    void showPinVerify(mmi_event_struct *data);
    void showInstallResult(mmi_event_struct *data);
    void showInvalidPin(void);
    void showPreInstall(mmi_event_struct *data);
    void install(VappCCAMMIDataPack *data);
    void installFinished(void);
    void onPopupSel(void);
    void closeSelf(void);

    void setState(mmi_state_enum state)
    {
        m_state = state;
    }
    mmi_state_enum getState(void)
    {
        return m_state;
    }
    void setCCAHandle(SRV_CCA_HANDLE handle)
    {
        m_hCca = handle;
    }
    SRV_CCA_HANDLE getCCAHandle(void)
    {
        return m_hCca;
    }
    void setBoxMsg(VfxBool isBoxMsg)
    {
        m_boxMsg = isBoxMsg;
    }
    VfxBool getBoxMsg(void)
    {
        return m_boxMsg;
    }
    void applyPinVerify(VfxWChar*);
    void applyPinVerifyCancel(void);
    static void setPinBuf(VfxWChar*);

private:
    mmi_state_enum m_state;
    VappCCAScreen  *m_screen;
    VappCCAPinScreen *m_pinScreen;
    mmi_id          m_instId;
    SRV_CCA_HANDLE  m_hCca;
    VfxBool         m_boxMsg;
    static VfxWChar  m_pinBuf[SRV_CCA_MAX_PIN_CHARS+1];
};

#endif /* __VAPP_CCA_MAIN_H__*/

