#include "vmswitch.h"
#ifdef __MRE_CORE_BASE__

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
*  
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  
*
* Author:
* -------
*Jia Luo (mtk80935)
*
*==============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*------------------------------------------------------------------------------
 * removed!
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#ifdef __COSMOS_MMI_PACKAGE__
extern "C"
{
#include "vmsys.h"
#include "vmpromng.h"
#include "vmstdlib.h"
#include "vmlog.h"
#include "DialerCuiGprot.h"
}

#include "vfx_datatype.h"
#include "vfx_app.h"
#include "vfx_app_launcher.h"


class VappDialerCUIAdp : public VfxApp
{
    VFX_DECLARE_CLASS(VappDialerCUIAdp);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize); 
    
protected:
    mmi_id m_cuiId;
    virtual void onDeinit();
};

VFX_IMPLEMENT_CLASS("VappDialerCUIAdp", VappDialerCUIAdp, VfxApp);

   
void VappDialerCUIAdp::onDeinit()
{
    cui_dialer_close(m_cuiId);
    VfxApp::onDeinit();
}

void VappDialerCUIAdp::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    m_cuiId = cui_dialer_create(getGroupId());

    ASSERT(m_cuiId > 0);
    
    if (args)
    {
        cui_dialer_set_dial_string(m_cuiId, (WCHAR *)args);
    }
    
    cui_dialer_run(m_cuiId);
}

extern "C" void vm_dialer_launch_adp(VMSTR phone_num)
{
    void *arg = phone_num;
    VfxU32 argSize;

    if (!arg)
    {
        argSize = 0;
    }
    else
    {
        argSize = 2*kal_wstrlen((WCHAR *)phone_num)+2;
    }
    
    VfxAppLauncher::launch( 
        VAPP_MRE_APP_DIALER, 
        VFX_OBJ_CLASS_INFO(VappDialerCUIAdp),
        GRP_ID_ROOT,
        arg,argSize,
        VFX_FALSE);
             
}


extern "C"
{
//#include "DataAccountGprot.h"
#include "vmsock.h"
#include "vcui_dtcnt_select_gprot.h"
#include "InlineCuiGprot.h"
#include "vmsys.h"
#include "vmpromng.h"


VMINT vm_get_app_id(VMINT apn, VMUINT8 *app_id);

typedef struct
{
    VM_P_HANDLE p_hdl;
    VMINT (*cb)(VMUINT32 dtacct);
    VMINT sim_id;
}vm_adp_dtacct_selection_ctx_t;

}

#include "vfx_datatype.h"
#include "vfx_app.h"
#include "vfx_app_launcher.h"

#include "vfx_main_scr.h"

static MMI_ID m_dtcnt_id;


class VappDTCNTMainSrc : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappDTCNTMainSrc);
public:
    void setParam(void * param)
        {
            m_args = param;
        }
    void * getParam(void)
        {
            return m_args;
        }
// Override
protected:
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual void on1stReady();
private:
    void * m_args;
};

VFX_IMPLEMENT_CLASS("VappDTCNTMainSrc", VappDTCNTMainSrc, VfxMainScr);

void VappDTCNTMainSrc::on1stReady()
{
    VfxMainScr::on1stReady();
    
    cui_dtcnt_select_run_struct select_run_info;
    VMUINT8 cbm_app_id = 0;
    VMINT i = 0;


    vm_get_app_id(VM_TCP_APN_CMNET, &cbm_app_id);
    select_run_info.app_id = cbm_app_id;
    select_run_info.bearers = DATA_ACCOUNT_BEARER_GPRS;
    select_run_info.option = CUI_DTCNT_SELECT_DEFAULT;
    select_run_info.type = CUI_DTCNT_SELECT_TYPE_NORMAL;
    //select_run_info.sim_selection = /**((cui_dtcnt_select_sim_enum*)m_args);*/CUI_DTCNT_SELECT_SIM_ALL;
    if (*((cui_dtcnt_select_sim_enum*)getParam()) == 0)
    {
        select_run_info.sim_selection = CUI_DTCNT_SELECT_SIM1;
    }
#if MMI_SIM_TOTAL > 1
    else if (*((cui_dtcnt_select_sim_enum*)getParam()) == 1)
    {
        select_run_info.sim_selection = CUI_DTCNT_SELECT_SIM2;
    }
#endif
#if MMI_SIM_TOTAL > 2
    else if (*((cui_dtcnt_select_sim_enum*)getParam()) == 2)
    {
        select_run_info.sim_selection = CUI_DTCNT_SELECT_SIM3;
        //para.sim_account_id[2] = g_gps_ctx.data_account_temp;
    }
#endif
#if MMI_SIM_TOTAL > 3
    else if (*((cui_dtcnt_select_sim_enum*)getParam()) == 3)
    {
        select_run_info.sim_selection = CUI_DTCNT_SELECT_SIM4;
        //para.sim_account_id[3] = g_gps_ctx.data_account_temp;
    }
#endif
    /*
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        select_run_info.sim_account_id[i] = CBM_DEFAULT_ACCT_ID;
    }
    */

    m_dtcnt_id = vcui_dtcnt_select_create(getGroupId());
    vcui_dtcnt_select_set_param(m_dtcnt_id, &select_run_info);
    vcui_dtcnt_select_run(m_dtcnt_id);
}

mmi_ret VappDTCNTMainSrc::onProc(mmi_event_struct *evt)
{

    return VfxMainScr::onProc(evt);;

}


class VappDTCNTApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappDTCNTApp);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize); 
    
    static mmi_id           m_mmiId;
protected:
    virtual void onDeinit();
    virtual mmi_ret onProc(mmi_event_struct *evt);

private:
    static vm_adp_dtacct_selection_ctx_t m_ctx;
};

VFX_IMPLEMENT_CLASS("VappDTCNTApp", VappDTCNTApp, VfxApp);
mmi_id VappDTCNTApp::m_mmiId = 0;
vm_adp_dtacct_selection_ctx_t VappDTCNTApp::m_ctx = {0};

void VappDTCNTApp::onDeinit()
{
    //vcui_dtcnt_select_close(VappDTCNTApp::m_mmiId);
    //exit();
    VfxApp::onDeinit();
}

mmi_ret VappDTCNTApp::onProc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_abort_struct *inline_abort = (cui_event_inline_abort_struct*)evt;
    cui_dtcnt_select_event_any_sim_selected_struct *dtcnt_select = (cui_dtcnt_select_event_any_sim_selected_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(inline_abort->sender_id);
            break;
            
        case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
        {
            //VMINT sim_id = 0;
            
            //ASSERT(VappDTCNTApp::m_ctx_p);
            PMNG_WRAP_CALLBACK(VappDTCNTApp::m_ctx.p_hdl, 
                VappDTCNTApp::m_ctx.cb(/*(VMINT)dtcnt_select->selectSim, */(VMUINT32)dtcnt_select->accountId));
            
            /*
            vcui_dtcnt_select_close(dtcnt_select->sender_id);
            exit();
            */
            
            //vcui_dtcnt_select_close(dtcnt_select->sender_id);
            //VappDTCNTApp::m_ctx_p->cb = NULL;
            //VappDTCNTApp::m_ctx_p->dtcnt_cid = 0;
            //VappDTCNTApp::m_ctx_p->parent_gid = 0;
            //VappDTCNTApp::m_ctx_p->p_hdl = 0;
            //exit();
            break;
        }
        case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
        case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
        case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
        case CUI_DTCNT_SELECT_EVENT_CLOSE:
            vcui_dtcnt_select_close(m_dtcnt_id);
            VappDTCNTApp::m_ctx.cb = NULL;
            VappDTCNTApp::m_ctx.p_hdl = 0;
            VappDTCNTApp::m_ctx.sim_id = 0;
            exit();
            break;

        case EVT_ID_GROUP_EXIT:
        {
        }

        default:
            break;
    }
    return VfxApp::onProc(evt);
}

void VappDTCNTApp::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);
    
    vm_adp_dtacct_selection_ctx_t * tmp = (vm_adp_dtacct_selection_ctx_t *)args;
    VappDTCNTApp::m_ctx.cb = tmp->cb;
    VappDTCNTApp::m_ctx.p_hdl = tmp->p_hdl;
    VappDTCNTApp::m_ctx.sim_id = tmp->sim_id;
    
    //create main screen
    VappDTCNTMainSrc *pScr;
    VFX_OBJ_CREATE(pScr, VappDTCNTMainSrc, this);
    pScr->setParam((void *)&(VappDTCNTApp::m_ctx.sim_id));
    pScr->show();
    



}

extern "C" MMI_ID vm_vapp_dtcnt_select_run(VM_P_HANDLE p_hdl, VMINT (*cb)(VMUINT32 dtacct), VMINT sim_id)
{
    vm_adp_dtacct_selection_ctx_t ctx;
    ctx.cb = cb;
    ctx.p_hdl = p_hdl;
    ctx.sim_id = sim_id;

    VappDTCNTApp::m_mmiId = VfxAppLauncher::launch(
    	VAPP_MRE_APP_DTCNT, 
    	VFX_OBJ_CLASS_INFO(VappDTCNTApp),
    	GRP_ID_ROOT,
    	(void*)&ctx, sizeof(ctx),
    	VFX_FALSE);

    return VappDTCNTApp::m_mmiId;
}

#endif /* __COSMOS_MMI_PACKAGE__ */

#endif /* __MRE_CORE_BASE__ */

