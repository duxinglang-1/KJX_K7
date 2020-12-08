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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/****************************************************************************
* Include Files                                                                
*****************************************************************************/

/****************************************************************************
* Define
*****************************************************************************/

/****************************************************************************
* Global Variable
*****************************************************************************/

/****************************************************************************
* Static Variable
*****************************************************************************/

#include "MMI_include.h"
#include "wgui_categories_util.h"
#include "SimSelCuiGprot.h"
#include "SimSelCuiProt.h"
#include "mmi_rp_cui_sim_sel_def.h"
#include "IdleGprot.h"
#include "NwNameSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGprot.h" /* srv_mode_switch_get_current_mode */
#include "mmi_frm_utility_gprot.h"   /* For MMI_SIM_TOTAL & MMI_SIM_ALL */

#if (MMI_MAX_SIM_NUM >= 3)

cui_sim_sel_cntx_struct g_sim_sel_cntx;
cui_sim_sel_cntx_struct *g_sim_sel_p = &g_sim_sel_cntx;


void cui_sim_sel_abort()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sim_sel_result_event_struct result_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_SIM_SEL, TRC_MMI_SIM_SEL_ABORT);

    /* Send result event to caller */
    memset(&result_evt, 0, sizeof(result_evt));
    MMI_FRM_INIT_GROUP_EVENT(&result_evt, EVT_ID_CUI_SIM_SEL_RESULT, g_sim_sel_p->group_id); 
    result_evt.result = CUI_SIM_SEL_ABORT;
    result_evt.parent_data = g_sim_sel_p->parent_data;
    mmi_frm_group_post_to_caller(g_sim_sel_p->group_id, (mmi_group_event_struct*)&result_evt);

}


static mmi_ret cui_sim_sel_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_changed_evt_struct *nw_evt;
    mmi_scenario_evt_struct *group;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (param->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            group = (mmi_scenario_evt_struct*)param;
            if (g_sim_sel_p->group_id == group->targ_group)
            {
                memset(g_sim_sel_p, 0, sizeof(cui_sim_sel_cntx_struct));
                mmi_frm_cb_dereg_event(EVT_ID_SRV_NW_NAME_CHANGED, cui_sim_sel_proc, NULL);
            }
            break;
        case EVT_ID_SRV_NW_NAME_CHANGED:
            nw_evt = (srv_nw_name_changed_evt_struct*)param;
            cui_sim_sel_update_list(nw_evt->sim);
            break;
    }

    return MMI_RET_OK;
}


mmi_id cui_sim_sel_create(mmi_id caller, mmi_sim_enum sim_id, void* parent_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_sim_sel_p->group_id)
    {
        cui_sim_sel_abort();
    }

    memset(g_sim_sel_p, 0, sizeof(cui_sim_sel_cntx_struct));

    /* Assign target sim ids */
    g_sim_sel_p->target_sim = sim_id;

    /* Prepare for no service sim list */
    /* The default behavior of SIM selector doesn't contain emergency*/
    cui_sim_sel_set_mode(MMI_FALSE);

    MMI_TRACE(MMI_COMMON_TRC_G5_SIM_SEL,TRC_MMI_SIM_SEL_CREATE,
        g_sim_sel_p->target_sim,
        g_sim_sel_p->no_service_sim);

    g_sim_sel_p->group_id = mmi_frm_group_create(caller, GRP_ID_AUTO_GEN, cui_sim_sel_proc, NULL);
    g_sim_sel_p->parent_data = parent_data;
    g_sim_sel_p->highlight_sim = MMI_SIM_NONE;

    mmi_frm_group_set_caller(g_sim_sel_p->group_id, caller);
    mmi_frm_cb_reg_event(EVT_ID_SRV_NW_NAME_CHANGED, cui_sim_sel_proc, NULL);

    return g_sim_sel_p->group_id;
}


void cui_sim_sel_set_mode(MMI_BOOL emergency)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mmi_sim_enum sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_sim_sel_p->emergency = emergency;

    g_sim_sel_p->no_service_sim = MMI_SIM_NONE;

    for (i = 0, sim = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim <<= 1)
    {
        if (!(((mmi_sim_enum)srv_mode_switch_get_current_mode()) & sim) ||
            ((emergency == MMI_FALSE) && (srv_sim_ctrl_is_available(sim) == MMI_FALSE)))
        {
            g_sim_sel_p->no_service_sim |= sim;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_SIM_SEL,TRC_MMI_SIM_SEL_SET_MODE,
        g_sim_sel_p->target_sim,
        g_sim_sel_p->no_service_sim,
        emergency);

}


void cui_sim_sel_set_highlight_sim(mmi_sim_enum highlight_sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_sim_sel_p->highlight_sim = highlight_sim;

    MMI_TRACE(MMI_COMMON_TRC_G5_SIM_SEL,TRC_MMI_SIM_SEL_SET_HIGHLIGHT_SIM, g_sim_sel_p->highlight_sim);

}


void cui_sim_sel_run(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_enter(cui_id, MMI_FRM_NODE_NONE_FLAG);

    mmi_frm_scrn_first_enter(
        g_sim_sel_p->group_id, SCR_ID_CUI_SIM_SEL_LIST, 
        (FuncPtr)cui_sim_sel_entry_list, 
        NULL);
}


void cui_sim_sel_close(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(cui_id);
}


void cui_sim_sel_get_sim_info(S32 sim_index, U8 sim_state, wgui_cat9010_text_struct *sim_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mmi_sim_enum sim_id;
    mmi_idle_service_indication_struct service_indication;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_idle_get_service_indication_string(MMI_SIM1, &service_indication);

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        if (i == sim_index)
        {
            if (g_sim_sel_p->target_sim & sim_id)
            {
                /* Target sim, get 2 line information from IDLE */
                MMI_TRACE(MMI_COMMON_TRC_G5_SIM_SEL, TRC_MMI_SIM_SEL_GET_INFO, sim_index, 1);
                mmi_idle_get_service_indication_string(sim_id, &service_indication);
                mmi_wcsncpy(sim_info->text_0 , service_indication.line1, WGUI_CAT9010_TEXT_SIZE);
                mmi_wcsncpy(sim_info->text_1, service_indication.line2, WGUI_CAT9010_TEXT_SIZE);
            }
            else
            {
                /* Not target sim */
                MMI_TRACE(MMI_COMMON_TRC_G5_SIM_SEL, TRC_MMI_SIM_SEL_GET_INFO, sim_index, 0);
                mmi_wcsncpy(sim_info->text_0 , (WCHAR *)GetString(STR_GLOBAL_NOT_SUPPORTED), WGUI_CAT9010_TEXT_SIZE);
            }
        }
    }
}


void cui_sim_sel_highlight_hdlr(S32 sim_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_id = MMI_SIM_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_SIM_SEL, TRC_MMI_SIM_SEL_HIGHLIGHT, sim_index);

    sim_id = (MMI_SIM1 << sim_index);

    if ((g_sim_sel_p->no_service_sim & sim_id) || !(g_sim_sel_p->target_sim & sim_id))
    {
	    /* No service sim or not target sim */
        ChangeLeftSoftkey(0, 0);
        ResetCenterSoftkey();
        redraw_softkey(MMI_CENTER_SOFTKEY);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
        EnableCenterSoftkey(NULL, IMG_GLOBAL_COMMON_CSK);
        redraw_softkey(MMI_CENTER_SOFTKEY);
        SetCenterSoftkeyFunction(get_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY), KEY_EVENT_UP);
    }
}


void cui_sim_sel_select_hdlr(S32 sim_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sim_sel_result_event_struct result_evt;
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    sim_id = (MMI_SIM1 << sim_index);

    if ((g_sim_sel_p->no_service_sim & sim_id) || !(g_sim_sel_p->target_sim & sim_id))
    {
        /* No service sim or not target sim */
        return;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_SIM_SEL, TRC_MMI_SIM_SEL_SELECT, sim_index);

    /* Send result event to caller */
    memset(&result_evt, 0, sizeof(result_evt));
    MMI_FRM_INIT_GROUP_EVENT(&result_evt, EVT_ID_CUI_SIM_SEL_RESULT, g_sim_sel_p->group_id); 
    result_evt.result = CUI_SIM_SEL_OK;
    result_evt.sim_id = sim_id;
    result_evt.parent_data = g_sim_sel_p->parent_data;
    mmi_frm_group_post_to_caller(g_sim_sel_p->group_id, (mmi_group_event_struct*)&result_evt);

}


void cui_sim_sel_entry_list(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 sim_state[MMI_SIM_TOTAL], i;
    mmi_sim_enum sim_id;
    U8 highlight_index = 0;
    S32 valid_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_CUI_SIM_SEL_LIST,
                    NULL,
                    (FuncPtr)cui_sim_sel_entry_list,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_SIM_SEL, TRC_MMI_SIM_SEL_ENTRY_LIST, g_sim_sel_p->target_sim);

    guiBuffer = mmi_frm_scrn_get_gui_buf(scr_info->group_id, SCR_ID_CUI_SIM_SEL_LIST);

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        if ((g_sim_sel_p->no_service_sim & sim_id) || !(g_sim_sel_p->target_sim & sim_id))
        {
            sim_state[i] = 0;
        }
        else
        {
            sim_state[i] = 1;
            valid_num ++;
        }

        if (g_sim_sel_p->highlight_sim == sim_id)
        {
            highlight_index = i;
        }
    }

    wgui_cat9010_register_highlight_handler(cui_sim_sel_highlight_hdlr);

    wgui_cat9010_register_select_handler(cui_sim_sel_select_hdlr);

    if (valid_num != 0)
    {
        EnableCenterSoftkey(NULL, IMG_GLOBAL_COMMON_CSK);
    }

    wgui_cat9010_show(
              (WCHAR*)GetString(STR_ID_CUI_SIM_SEL_SELECT_SIM),
              0,
              (WCHAR*)GetString(STR_GLOBAL_SELECT),
              0,
              (WCHAR*)GetString(STR_GLOBAL_BACK),
              0,
              cui_sim_sel_get_sim_info,
              MMI_SIM_TOTAL,
              (U8 *)sim_state,
              SIM_SELECTOR,
              highlight_index,
              guiBuffer);


    if (valid_num == 0)
    {
        ChangeLeftSoftkey(0, 0);
    }
    else
    {
        SetCenterSoftkeyFunction(get_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY), KEY_EVENT_UP);
    }

    SetRightSoftkeyFunction(cui_sim_sel_abort, KEY_EVENT_UP);

}


void cui_sim_sel_update_list(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    S32 sim_state = 0;
    mmi_sim_enum sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_SIM_SEL, TRC_MMI_SIM_SEL_UPDATE_LIST, sim_id);

    /* Grey or not */
    cui_sim_sel_set_mode(g_sim_sel_p->emergency);

    /* Update the sim info */
    for (i = 0, sim = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim <<= 1)
    {
        if (sim & sim_id)
        {
            if ((g_sim_sel_p->no_service_sim & sim_id) || !(g_sim_sel_p->target_sim & sim_id))
            {
                /* Grey: no service sim or not target sim */
                sim_state = 0;
            }
            else
            {
                sim_state = 1;
            }
            wgui_cat9010_update(i, sim_state);
            break;
        }
    }
}

#endif /* (MMI_MAX_SIM_NUM >= 3) */

