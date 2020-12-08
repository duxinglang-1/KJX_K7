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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_nw_info.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Network information application
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"
#include "vcp_global_popup.h"
#include "GlobalResDef.h"
#include "mmi_rp_vapp_nw_info_def.h"
extern "C"
{
#include "BootupSrvGprot.h"
#include "NotificationGprot.h"
#include "NwInfoSrvGprot.h"
#include "SimCtrlSrvGprot.h"
}
#include "vfx_datatype.h"


typedef struct
{
    VfxU32 to_show_invalid_sim;
    VfxS32 displaying_popup_handle[MMI_SIM_TOTAL];
} vapp_nw_info_cntx_struct;

static vapp_nw_info_cntx_struct g_vapp_nw_info_cntx =
{
    0
};


void vapp_nw_info_register_fail_confirmed(VfxId id, void *userData)
{
    VfxS32 *display_popup_handle_slot = static_cast<VfxS32*>(userData);
    
    // display_popup_id_slot == &(g_vapp_nw_info_cntx.displaying_popup_handle[sim_index])
    *display_popup_handle_slot = 0;
}


VfxWString vapp_nw_info_get_register_fail_msg(mmi_sim_enum sim)
{
#if (MMI_MAX_SIM_NUM >= 2)
    if (srv_sim_ctrl_get_num_of_inserted() >= 2)
    {
        //static const VfxS32 MAX_STR_LEN = 128;
        static const VfxU16 SIM_STR_ID[MMI_SIM_TOTAL] =
        {
            STR_GLOBAL_SIM_1,
            STR_GLOBAL_SIM_2,
        #if (MMI_MAX_SIM_NUM >= 3)
            STR_GLOBAL_SIM_3,
        #endif
        #if (MMI_MAX_SIM_NUM >= 4)
            STR_GLOBAL_SIM_4
        #endif
        };

        //VfxS32 simIndex = mmi_frm_sim_to_index(sim);
    
        //VfxWChar *buffer = (VfxWChar *)OslMalloc((MAX_STR_LEN + 1) * sizeof(WCHAR));
        //VFX_SYS_ALLOC_MEM(buffer, );
        //mmi_wsprintf(
        //    buffer,
        //    MAX_STR_LEN,
        //    STR_ID_VAPP_NW_INFO_INVALID_SIMX_MSG,
        //    SIM_STR_ID[simIndex]);

        //VfxWString msgStr = VFX_WSTR_MEM(buffer);
        //OslMfree(buffer);
        
        VfxWString msgStr;
        msgStr.format((VfxWChar*)GetString(STR_ID_VAPP_NW_INFO_INVALID_SIMX_MSG),(VfxWChar*)GetString(SIM_STR_ID[mmi_frm_sim_to_index(sim)]));
        //VfxWString msgStr(STR_ID_VAPP_NW_INFO_INVALID_SIMX_MSG);
        //msgStr += VFX_WSTR_RES(SIM_STR_ID[mmi_frm_sim_to_index(sim)]);
        return msgStr;
    }
#endif

    return VFX_WSTR_RES(STR_ID_VAPP_NW_INFO_INVALID_SIM_MSG);
}


MMI_BOOL vapp_nw_info_show_next_register_fail(void)
{
    for (VfxS32 sim_index = 0;
         g_vapp_nw_info_cntx.to_show_invalid_sim != 0 && sim_index < MMI_SIM_TOTAL;
         sim_index++)
    {
        mmi_sim_enum sim = srv_sim_ctrl_get_sim_by_index(sim_index);
    
        if ((g_vapp_nw_info_cntx.to_show_invalid_sim & sim) != 0)
        {
            VfxS32 popup_handle 
                = vcp_global_popup_show_confirm_one_button_str(
                GRP_ID_ROOT,
                VCP_POPUP_TYPE_INFO,
                vapp_nw_info_get_register_fail_msg(sim),
                VFX_WSTR_RES(STR_GLOBAL_OK),
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                vapp_nw_info_register_fail_confirmed,
                &(g_vapp_nw_info_cntx.displaying_popup_handle[sim_index]));
            g_vapp_nw_info_cntx.displaying_popup_handle[sim_index] = popup_handle;

            g_vapp_nw_info_cntx.to_show_invalid_sim &= ~sim;
        }
    }

    return MMI_FALSE;
}


MMI_BOOL vapp_nw_info_show_register_fail(mmi_scenario_id scen_id, void *arg)
{
    return vapp_nw_info_show_next_register_fail();
}


extern "C"
mmi_ret vapp_nw_info_on_register_failed(mmi_event_struct *evt)
{
    srv_nw_info_register_failed_evt_struct *failed_evt;

    failed_evt = reinterpret_cast<srv_nw_info_register_failed_evt_struct*>(evt);
    
    g_vapp_nw_info_cntx.to_show_invalid_sim |= failed_evt->sim;

    if (!srv_bootup_is_completed())
    {
        return MMI_RET_OK;
    }

    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_NW_REGISTER_FAIL,
        vapp_nw_info_show_register_fail,
        NULL);
            
    return MMI_RET_OK;
}



mmi_ret vapp_nw_info_show_invalid_sim_postly(mmi_event_struct *evt)
{
    if (g_vapp_nw_info_cntx.to_show_invalid_sim != 0)
    {
        mmi_frm_nmgr_notify_by_app(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_NW_REGISTER_FAIL,
            vapp_nw_info_show_register_fail,
            NULL);
    }

    return MMI_RET_OK;
}

extern "C"
mmi_ret vapp_nw_info_on_bootup_completed(mmi_event_struct *evt)
{
    if (g_vapp_nw_info_cntx.to_show_invalid_sim != 0)
    {
        // invoke NMGR postly
        mmi_event_struct evt;
        MMI_FRM_INIT_EVENT(&evt, 0);
        MMI_FRM_POST_EVENT(&evt, vapp_nw_info_show_invalid_sim_postly, &g_vapp_nw_info_cntx);
    }

    return MMI_RET_OK;
}

