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
 *  vapp_bootup_mode.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Mode decision
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C"
{
#include "BootupSrvIprot.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "GeneralSettingSrvGprot.h" /* Primary SIM */
}

#include "vapp_bootup.h"
#include "vapp_bootup_app.h"
#pragma arm section code = "DYNAMIC_CODE_BOOTUP_ROCODE", rodata = "DYNAMIC_CODE_BOOTUP_RODATA"
typedef struct
{
    mmi_frm_proc_id_info_struct id_info;
    U32 enabled_sims;
} vapp_bootup_mode_cntx_struct;

static vapp_bootup_mode_cntx_struct g_vapp_bootup_mode_cntx;


static mmi_ret vapp_bootup_on_mode_decided(mmi_event_struct *evt);
static void vapp_bootup_on_protocol_ready(void *user_data);


#if (MMI_MAX_SIM_NUM >= 2)
void VappBootupApp::decideMode(mmi_proc_func proc, void *userData)
{
    VappBootupConfigSimPage *page = NULL;

    m_callbackProc = proc;
    m_callbackUserData = userData;

    VFX_OBJ_CREATE(page, VappBootupConfigSimPage, m_mainScr);
    page->m_signalDone.connect(this, &VappBootupApp::onUserDecidedMode);
    page->setAllowDelete(VFX_FALSE);
    
    m_mainScr->pushPage(PAGE_SIM_SELECTION, page);

    showMainScr();
}


void VappBootupApp::onUserDecidedMode(VfxU32 enabledSims)
{
    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_ON_USER_DECIDED_MODE, enabledSims, 0);

    VfxPage *page = m_mainScr->getPage(PAGE_SIM_SELECTION);
    if (page != NULL)
    {
        page->setIsDisabled(VFX_TRUE);
    }

    if (m_callbackProc != NULL)
    {
        mmi_proc_func proc = m_callbackProc;
        void *user_data = m_callbackUserData;
        m_callbackProc = NULL;

        mode_decided_evt_struct decided_evt;
        MMI_FRM_INIT_EVENT(&decided_evt, EVT_ID_MODE_DECIDED);
        decided_evt.enabled_sims = enabledSims;
        MMI_FRM_SEND_EVENT(&decided_evt, proc, user_data);
    }
}
#endif /* (MMI_MAX_SIM_NUM >= 2) */


static void vapp_bootup_on_sim_module_ready(void *user_data)
{
    vapp_bootup_mode_cntx_struct *cntx;

    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_ON_SIM_MODULE_READY);

    cntx = static_cast<vapp_bootup_mode_cntx_struct*>(user_data);
    mmi_frm_proc_notify_completed(cntx->id_info);
}


mmi_frm_proc_result_enum vapp_bootup_init_sim_module(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_INIT_SIM_MODULE);

#if (MMI_MAX_SIM_NUM >= 2)

    g_vapp_bootup_mode_cntx.id_info = id_info;

    srv_bootup_init_sim_module(
        vapp_bootup_on_sim_module_ready,
        &(g_vapp_bootup_mode_cntx));

    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;

#else

    /* Only dual SIM projects need to be initialized now */
    return MMI_FRM_PROC_RESULT_COMPLETED;

#endif
}


mmi_frm_proc_result_enum vapp_bootup_decide_mode(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    vapp_bootup_mode_cntx_struct *cntx = &g_vapp_bootup_mode_cntx;

    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_DECIDE_MODE);

    cntx->id_info = id_info;
    cntx->enabled_sims = 0;

    if (srv_bootup_is_exception_mode())
    {
        cntx->enabled_sims = static_cast<U32>(srv_mode_switch_get_current_mode());
        return MMI_FRM_PROC_RESULT_COMPLETED;
    }

    if (!srv_mode_switch_is_network_service_available())
    {
        MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_DECIDE_MODE_FLIGHT_MODE);
        cntx->enabled_sims = MMI_SIM_NONE;
        return MMI_FRM_PROC_RESULT_COMPLETED;
    }

#if (MMI_MAX_SIM_NUM >= 2)

    VfxS32 n_inserted_sims = 0;
    VfxU32 inserted_sims_bit_set = 0;

    for (VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
    {
        mmi_sim_enum sim = srv_sim_ctrl_get_sim_by_index(i);
        if (srv_bootup_sim_is_inserted(sim))
        {
            n_inserted_sims++;
            inserted_sims_bit_set |= sim;
        }
    }

    if (srv_mode_switch_is_query_mode_enabled())
    {
        if (n_inserted_sims >= 2) /* More than 2 SIMs inserted */
        {
            if (!srv_bootup_is_auto_power_on_test())
            {
                VappBootupApp *app = VappBootupApp::getApp();
                app->decideMode(vapp_bootup_on_mode_decided, cntx);
                return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
            }
            else
            {
                cntx->enabled_sims = inserted_sims_bit_set;
            }
        }
        else if (n_inserted_sims == 1)
        {
            cntx->enabled_sims = inserted_sims_bit_set;
        }
        else
        {
            /* Enable SIM1 for emergency call */
            cntx->enabled_sims = MMI_SIM1;
        }
    }
    else
    {
        cntx->enabled_sims = inserted_sims_bit_set;

        if (cntx->enabled_sims == 0) /* No SIM is inserted */
        {
            /* Enable SIM1 for emergency call */
            cntx->enabled_sims = MMI_SIM1;
        }
    }
    
    return MMI_FRM_PROC_RESULT_COMPLETED;
    
#else /* (MMI_MAX_SIM_NUM >= 2) */

    cntx->enabled_sims = MMI_SIM1;

    return MMI_FRM_PROC_RESULT_COMPLETED;

#endif /* (MMI_MAX_SIM_NUM >= 2) */
}


static mmi_ret vapp_bootup_on_mode_decided(mmi_event_struct *evt)
{
    vapp_bootup_mode_cntx_struct *cntx;
    VappBootupApp::mode_decided_evt_struct *decided_evt;

    cntx = static_cast<vapp_bootup_mode_cntx_struct*>(evt->user_data);
    decided_evt = reinterpret_cast<VappBootupApp::mode_decided_evt_struct*>(evt);
    cntx->enabled_sims = decided_evt->enabled_sims;

    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_ON_MODE_DECIDED, cntx->enabled_sims);
    
    mmi_frm_proc_notify_completed(cntx->id_info);

    return MMI_RET_OK;
}


mmi_frm_proc_result_enum vapp_bootup_boot_protocol(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    vapp_bootup_mode_cntx_struct *cntx = &g_vapp_bootup_mode_cntx;

    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_BOOT_PROTOCOL);

    cntx->id_info = id_info;
    
    srv_bootup_boot_protocol(
        static_cast<srv_bootup_protocol_mode_enum>(cntx->enabled_sims),
        vapp_bootup_on_protocol_ready,
        cntx);

    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
}


static void vapp_bootup_on_protocol_ready(void *user_data)
{
    vapp_bootup_mode_cntx_struct *cntx;

    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_ON_PROTOCOL_READY);

    VappBootupApp::getApp()->closeWaiting();
    
    cntx = static_cast<vapp_bootup_mode_cntx_struct*>(user_data);
    mmi_frm_proc_notify_completed(cntx->id_info);
}
#pragma arm section code, rodata
