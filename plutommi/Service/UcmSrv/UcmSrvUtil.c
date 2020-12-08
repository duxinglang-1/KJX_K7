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
 *  UcmSrvUtil.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM service utility function
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
#include "custom_phb_config.h"
#include "GlobalConstants.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "MMI_features.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "sim_common_enums.h"
#include "ps_public_enum.h"
#include "custom_mmi_default_value.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "GlobalResDef.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_rp_srv_ucm_def.h"
#include "UcmSrvGprot.h"
#include "UcmSrvIntProt.h"
#include "UcmSrvProt.h"
#include "app_usedetails.h" /* applib_ss_string_parsing */

#define SRV_UCM_CALL_LIST_SIZE ((SRV_UCM_MAX_CALL_IN_CALL_SRV * (((MMI_PHB_NAME_LENGTH + 1) * 2) + ((SRV_UCM_MAX_DISP_NAME_LEN + 1) * 2) + (SRV_UCM_MAX_NUM_URI_LEN + 1))) + 300)

#if (SRV_UCM_CALL_LIST_SIZE >= 2000)
U32 srv_ucm_memory[3][SRV_UCM_CALL_LIST_SIZE/4]; /* Should take care of alignment problem */
#endif /* (SRV_UCM_CALL_LIST_SIZE >= 2000) */

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_busy
 * DESCRIPTION
 *  The function to check if UCM service is busy
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means UCM service is busy; FALSE means UCM service is not busy.
 *****************************************************************************/
MMI_BOOL srv_ucm_is_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((srv_ucm_get_process_state(SRV_UCM_WAIT_PROCESS_STATE, NULL) != 0) || 
        (srv_ucm_get_process_state(SRV_UCM_DO_PROCESS_STATE, NULL) != 0) || 
        (srv_ucm_get_process_state(SRV_UCM_COMP_PROCESS_STATE, NULL) != 0) || 
        (srv_ucm_query_group_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) != 0) || 
        (srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) != 0) || 
        (srv_ucm_is_emergency_call() == MMI_TRUE))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_pending_action
 * DESCRIPTION
 *  The function to query if there is any pending action
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means there is pending action; MMI_FALSE means there is not.
 *****************************************************************************/
MMI_BOOL srv_ucm_is_pending_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((srv_ucm_get_process_state(SRV_UCM_WAIT_PROCESS_STATE, NULL) == 0) && 
        (srv_ucm_get_process_state(SRV_UCM_DO_PROCESS_STATE, NULL) == 0) && 
        (srv_ucm_get_process_state(SRV_UCM_COMP_PROCESS_STATE, NULL) == 0))
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}

#ifdef __MMI_BACKGROUND_CALL__
/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_app_exit
 * DESCRIPTION
 *  Query function for if there is any app who doesn't want to exit,
 *  when the background outgoing call is connected
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means all apps can exit
 *  MMI_FALSE means any of apps can't exit
 *****************************************************************************/
MMI_BOOL srv_ucm_query_app_exit()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_app_exit_query_evt_struct evt;
    mmi_ret result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0)
    {
        if ((g_ucm_srv_p->call_list.group_info[g_ucm_srv_p->call_misc.index_list[0].group_index].call_info[0].module_id == SRV_UCM_MODULE_ORIGIN_AT) ||
        #if (MMI_MAX_SIM_NUM >= 2)
            (g_ucm_srv_p->call_list.group_info[g_ucm_srv_p->call_misc.index_list[0].group_index].call_info[0].module_id == SRV_UCM_MODULE_ORIGIN_AT_SIM2) ||
        #if (MMI_MAX_SIM_NUM >= 3)
            (g_ucm_srv_p->call_list.group_info[g_ucm_srv_p->call_misc.index_list[0].group_index].call_info[0].module_id == SRV_UCM_MODULE_ORIGIN_AT_SIM3) ||
        #if (MMI_MAX_SIM_NUM == 4)
            (g_ucm_srv_p->call_list.group_info[g_ucm_srv_p->call_misc.index_list[0].group_index].call_info[0].module_id == SRV_UCM_MODULE_ORIGIN_AT_SIM4) ||
        #endif /* (MMI_MAX_SIM_NUM == 4) */
        #endif /* (MMI_MAX_SIM_NUM >= 3) */
        #endif /* (MMI_MAX_SIM_NUM >= 2) */
            (g_ucm_srv_p->call_list.group_info[g_ucm_srv_p->call_misc.index_list[0].group_index].call_type & SRV_UCM_CALL_TYPE_DATA_CSD_ALL))
        {
            return MMI_FALSE;
        }
        else
        {
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_UCM_APP_EXIT_QUERY);
            result = MMI_FRM_CB_EMIT_EVENT(&evt);
            return (result == SRV_UCM_APP_EXIT_QUERY_RESULT_NO)? MMI_FALSE : MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_background_call
 * DESCRIPTION
 *  Function to query if it is in background call
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means there is background call. The background call may be outgoing, incoming, active, and held calls.
 *  MMI_FALSE means there is no call, there is foreground call, or there is CSD call.
 *****************************************************************************/
MMI_BOOL srv_ucm_is_background_call()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, MMI_FALSE, NULL) > 0) && 
    #ifdef __MMI_VIDEO_TELEPHONY__
        (srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VIDEO_CALL_TYPE_ALL, MMI_FALSE, NULL) == 0) &&
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        MMI_TRUE)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;

}
#endif /* __MMI_BACKGROUND_CALL__ */

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_get_process_state
 * DESCRIPTION
 *  Get index by process state
 * PARAMETERS
 *  proc_state      [IN]            Process state
 *  index_list      [IN/OUT]        Index list that matches the condition
 * RETURNS
 *  Number of calls that is in the given process state.
 *****************************************************************************/
S32 srv_ucm_get_process_state(srv_ucm_process_state_enum proc_state, srv_ucm_index_info_struct *index_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, numTotal = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < g_ucm_srv_p->call_list.num_group; i++)
    {
        for (j = 0; j < g_ucm_srv_p->call_list.group_info[i].num_call; j++)
        {
            if (g_ucm_srv_p->call_list.group_info[i].call_info[j].proc_state == proc_state)
            {
                if (index_list != NULL)
                {
                    index_list[numTotal].group_index = i;
                    index_list[numTotal].call_index = j;
                }
                numTotal++;
            }
        }
    }

    return numTotal;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_set_process_state
 * DESCRIPTION
 *  Set process state
 * PARAMETERS
 *  group_index     [IN]            Group index
 *  call_index      [IN]            Call index
 *  old_state       [IN]            Old process state
 *  new_state       [IN]            New process state
 * RETURNS
 *  Number of calls that is changed its process state.
 *****************************************************************************/
S32 srv_ucm_set_process_state(S32 group_index, S32 call_index, srv_ucm_process_state_enum old_state, srv_ucm_process_state_enum new_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, numTotal = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((group_index == -1) && (call_index == -1))
    {
        for (i = 0; i < g_ucm_srv_p->call_list.num_group; i++)
        {
            for (j = 0; j < g_ucm_srv_p->call_list.group_info[i].num_call; j++)
            {
                if (g_ucm_srv_p->call_list.group_info[i].call_info[j].proc_state == old_state)
                {
                    g_ucm_srv_p->call_list.group_info[i].call_info[j].proc_state = new_state;
                    numTotal++;
                }
            }
        }
    }
    else if ((group_index != -1) && (call_index == -1))
    {
        for (i = 0; i < g_ucm_srv_p->call_list.group_info[group_index].num_call; i++)
        {
            if (g_ucm_srv_p->call_list.group_info[group_index].call_info[i].proc_state == old_state)
            {
                g_ucm_srv_p->call_list.group_info[group_index].call_info[i].proc_state = new_state;
                numTotal++;
            }
        }
    }
    else if (g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state == old_state)
    {
        g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = new_state;
        numTotal = 1;
    }
    else
    {
        MMI_ASSERT(0); /* old state mismatch */
    }
    return numTotal;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_first_end_act_op
 * DESCRIPTION
 *  The function to query the first end action according to compound action
 * PARAMETERS
 *  comp_op:         [IN]            Compound action op-code
 *  act_op:          [IN]            Must be END_ALL, END_SINGLE or END_CONF, which call service supports
 * RETURNS
 *  srv_ucm_act_opcode_enum, SRV_UCM_END_ALL_ACT, SRV_UCM_END_ALL_ACTIVE_ACT or SRV_UCM_END_ALL_HELD_ACT
 *****************************************************************************/
srv_ucm_act_opcode_enum srv_ucm_query_first_end_act_op(srv_ucm_act_opcode_enum comp_op, srv_ucm_act_opcode_enum act_op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_act_opcode_enum end_act_op = SRV_UCM_NO_ACT;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((act_op != SRV_UCM_END_ALL_ACT) &&
        (act_op != SRV_UCM_END_SINGLE_ACT) &&
        (act_op != SRV_UCM_END_CONFERENCE_ACT))
    {
        MMI_ASSERT(0);
    }
    else
    {
        switch (comp_op)
        {
        #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_DIAL__
            case SRV_UCM_END_ALL_AND_DIAL_ACT:
                end_act_op = SRV_UCM_END_ALL_ACT;
                break;
        #endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_DIAL__ */

        #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_ACCEPT__
            case SRV_UCM_END_ALL_AND_ACCEPT_ACT:
                end_act_op = SRV_UCM_END_ALL_ACT;
                break;
        #endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_ACCEPT__ */

            case SRV_UCM_END_ALL_ACTIVE_ACT:
        #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__
            case SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT:
        #endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__ */
            case SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT:
                end_act_op = SRV_UCM_END_ALL_ACTIVE_ACT;
                break;

        #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
            case SRV_UCM_END_ALL_HELD_ACT:
                end_act_op = SRV_UCM_END_ALL_HELD_ACT;
                break;
        #endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__ */

            default:
                MMI_ASSERT(0);
                break;
        }
    }

    return end_act_op;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_act_type
 * DESCRIPTION
 *  The function to check the action type according to action op-code
 *  The second action op-code should be subset of first action op-code
 * PARAMETERS
 *  first_op           [IN]            First action op-code
 *  second_op          [IN]            Second action op-code
 * RETURNS
 *  srv_ucm_act_type_enum, single, compound, compound first, compound second
 *****************************************************************************/
srv_ucm_act_type_enum srv_ucm_query_act_type(srv_ucm_act_opcode_enum first_op, srv_ucm_act_opcode_enum second_op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_act_type_enum act_type = SRV_UCM_ACT_TYPE_TOTAL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (first_op)
    {
        case SRV_UCM_DIAL_ACT:
        case SRV_UCM_ACCEPT_ACT:
        case SRV_UCM_HOLD_ACT:
        case SRV_UCM_RETRIEVE_ACT:
        case SRV_UCM_CONFERENCE_ACT:
        case SRV_UCM_SPLIT_ACT:
    #ifdef __MMI_UCM_DEFLECT__
        case SRV_UCM_DEFLECT_ACT:
    #endif /* __MMI_UCM_DEFLECT__ */
    #ifdef __MMI_UCM_TRANSFER__
        case SRV_UCM_TRANSFER_ACT:
    #endif /* __MMI_UCM_TRANSFER__ */
    #ifdef __MMI_UCM_ECT__
        case SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT:
    #endif /* __MMI_UCM_ECT__ */
        case SRV_UCM_END_SINGLE_ACT:
        case SRV_UCM_END_CONFERENCE_ACT:
        case SRV_UCM_END_ALL_ACT:
        case SRV_UCM_END_ALL_ACTIVE_ACT:
    #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
        case SRV_UCM_END_ALL_HELD_ACT:
    #endif
        case SRV_UCM_END_ALL_PROCESSING_ACT:
        case SRV_UCM_START_DTMF_ACT:
        case SRV_UCM_STOP_DTMF_ACT:
        case SRV_UCM_SEND_DTMF_DIGITS_ACT:
    #if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
        case SRV_UCM_VT_FALLTO_VOICE_ACT:
    #endif /* (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */
            if (first_op == second_op)
            {
                act_type = SRV_UCM_ACT_TYPE_SINGLE;
            }
            else
            {
                MMI_ASSERT(0);
            }
            break;

        case SRV_UCM_SWAP_ACT:
            if (second_op == SRV_UCM_SWAP_ACT)
            {
                act_type = SRV_UCM_ACT_TYPE_COMPOUND;
            }
            else if (second_op == SRV_UCM_HOLD_ACT)
            {
                act_type = SRV_UCM_ACT_TYPE_COMPOUND_FIRST;
            }
            else if (second_op == SRV_UCM_RETRIEVE_ACT)
            {
                act_type = SRV_UCM_ACT_TYPE_COMPOUND_SECOND;
            }
            else
            {
                MMI_ASSERT(0);
            }
            break;

    #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_DIAL__
        case SRV_UCM_END_ALL_AND_DIAL_ACT:
            if (second_op == SRV_UCM_END_ALL_AND_DIAL_ACT)
            {
                act_type = SRV_UCM_ACT_TYPE_COMPOUND;
            }
            else if (second_op == SRV_UCM_END_ALL_ACT)
            {
                act_type = SRV_UCM_ACT_TYPE_COMPOUND_FIRST;
            }
            else if (second_op == SRV_UCM_DIAL_ACT)
            {
                act_type = SRV_UCM_ACT_TYPE_COMPOUND_SECOND;
            }
            else
            {
                MMI_ASSERT(0);
            }
            break;
    #endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_DIAL__ */

        case SRV_UCM_END_ALL_AND_ACCEPT_ACT:
            if (second_op == SRV_UCM_END_ALL_AND_ACCEPT_ACT)
            {
                act_type = SRV_UCM_ACT_TYPE_COMPOUND;
            }
            else if (second_op == SRV_UCM_END_ALL_ACT)
            {
                act_type = SRV_UCM_ACT_TYPE_COMPOUND_FIRST;
            }
            else if (second_op == SRV_UCM_ACCEPT_ACT)
            {
                act_type = SRV_UCM_ACT_TYPE_COMPOUND_SECOND;
            }
            else
            {
                MMI_ASSERT(0);
            }
            break;

    #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__
        case SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT:
            if (second_op == SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT)
            {
                act_type = SRV_UCM_ACT_TYPE_COMPOUND;
            }
            else if (second_op == SRV_UCM_END_ALL_ACTIVE_ACT)
            {
                act_type = SRV_UCM_ACT_TYPE_COMPOUND_FIRST;
            }
            else if (second_op == SRV_UCM_RETRIEVE_ACT)
            {
                act_type = SRV_UCM_ACT_TYPE_COMPOUND_SECOND;
            }
            else
            {
                MMI_ASSERT(0);
            }
            break;
    #endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__ */

        case SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT:
            if (second_op == SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT)
            {
                act_type = SRV_UCM_ACT_TYPE_COMPOUND;
            }
            else if (second_op == SRV_UCM_END_ALL_ACTIVE_ACT)
            {
                act_type = SRV_UCM_ACT_TYPE_COMPOUND_FIRST;
            }
            else if (second_op == SRV_UCM_ACCEPT_ACT)
            {
                act_type = SRV_UCM_ACT_TYPE_COMPOUND_SECOND;
            }
            else
            {
                MMI_ASSERT(0);
            }
            break;

        case SRV_UCM_HOLD_AND_DIAL_ACT:
            if (second_op == SRV_UCM_HOLD_AND_DIAL_ACT)
            {
                act_type = SRV_UCM_ACT_TYPE_COMPOUND;
            }
            else if (second_op == SRV_UCM_HOLD_ACT)
            {
                act_type = SRV_UCM_ACT_TYPE_COMPOUND_FIRST;
            }
            else if (second_op == SRV_UCM_DIAL_ACT)
            {
                act_type = SRV_UCM_ACT_TYPE_COMPOUND_SECOND;
            }
            else
            {
                MMI_ASSERT(0);
            }
            break;

        case SRV_UCM_HOLD_AND_ACCEPT_ACT:
            if (second_op == SRV_UCM_HOLD_AND_ACCEPT_ACT)
            {
                act_type = SRV_UCM_ACT_TYPE_COMPOUND;
            }
            else if (second_op == SRV_UCM_HOLD_ACT)
            {
                act_type = SRV_UCM_ACT_TYPE_COMPOUND_FIRST;
            }
            else if (second_op == SRV_UCM_ACCEPT_ACT)
            {
                act_type = SRV_UCM_ACT_TYPE_COMPOUND_SECOND;
            }
            else
            {
                MMI_ASSERT(0);
            }
            break;

        default:
            MMI_ASSERT(0); /* not valid op_code */
            break;
    }

    return act_type;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_end_act_op
 * DESCRIPTION
 *  The function to check the end action type according to action op-codes
 * PARAMETERS
 *  act_op             [IN]            End related compound action
 *  second_op          [IN]            Second action op-code
 * RETURNS
 *  srv_ucm_act_opcode_enum, SRV_UCM_END_ALL_ACT or SRV_UCM_END_ALL_ACTIVE_ACT
 *****************************************************************************/
srv_ucm_act_opcode_enum srv_ucm_query_end_act_op(srv_ucm_act_opcode_enum act_op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_act_opcode_enum end_act_op;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (act_op)
    {
    #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_DIAL__
        case SRV_UCM_END_ALL_AND_DIAL_ACT:
            end_act_op = SRV_UCM_END_ALL_ACT;
            break;
    #endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_DIAL__ */

    #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_ACCEPT__
        case SRV_UCM_END_ALL_AND_ACCEPT_ACT: 
            end_act_op = SRV_UCM_END_ALL_ACT;
            break;
    #endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_ACCEPT__ */

    #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__
        case SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT:
    #endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__ */
        case SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT:
            end_act_op = SRV_UCM_END_ALL_ACTIVE_ACT;
            break;

        default:
            end_act_op = SRV_UCM_NO_ACT; /* Not end related compound action */
            break;
    }

    return end_act_op;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_int_act_op
 * DESCRIPTION
 *  The function to query internal action op-code by action op-code
 * PARAMETERS
 *  act_op             [IN]            Action op-code
 * RETURNS
 *  Internal action op-code
 *****************************************************************************/
srv_ucm_int_act_opcode_enum srv_ucm_query_int_act_op(srv_ucm_act_opcode_enum act_op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_act_opcode_enum int_act_op = SRV_UCM_INT_NO_ACT;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (act_op)
    {
        case SRV_UCM_DIAL_ACT:
            int_act_op = SRV_UCM_INT_DIAL_ACT;
            break;

        case SRV_UCM_ACCEPT_ACT:
            int_act_op = SRV_UCM_INT_ACCEPT_ACT;
            break;

        case SRV_UCM_HOLD_ACT:
            int_act_op = SRV_UCM_INT_HOLD_ACT;
            break;

        case SRV_UCM_RETRIEVE_ACT:
            int_act_op = SRV_UCM_INT_RETRIEVE_ACT;
            break;

        case SRV_UCM_SWAP_ACT:
            int_act_op = SRV_UCM_INT_SWAP_ACT;
            break;

        case SRV_UCM_CONFERENCE_ACT:
            int_act_op = SRV_UCM_INT_CONFERENCE_ACT;
            break;

        case SRV_UCM_SPLIT_ACT:
            int_act_op = SRV_UCM_INT_SPLIT_ACT;
            break;

    #ifdef __MMI_UCM_DEFLECT__
        case SRV_UCM_DEFLECT_ACT:
            int_act_op = SRV_UCM_INT_DEFLECT_ACT;
            break;
    #endif /* __MMI_UCM_DEFLECT__ */

    #ifdef __MMI_UCM_TRANSFER__
        case SRV_UCM_TRANSFER_ACT:
            int_act_op = SRV_UCM_INT_TRANSFER_ACT;
            break;
    #endif /* __MMI_UCM_TRANSFER__ */

    #ifdef __MMI_UCM_ECT__
        case SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT:
            int_act_op = SRV_UCM_INT_EXPLICIT_CALL_TRANSFER_ACT;
            break;
    #endif /* __MMI_UCM_ECT__ */

        case SRV_UCM_END_SINGLE_ACT:
            int_act_op = SRV_UCM_INT_END_SINGLE_ACT;
            break;

        case SRV_UCM_END_CONFERENCE_ACT:
            int_act_op = SRV_UCM_INT_END_CONFERENCE_ACT;
            break;

        case SRV_UCM_END_ALL_ACT:
            int_act_op = SRV_UCM_INT_END_ALL_ACT;
            break;

        case SRV_UCM_START_DTMF_ACT:
            int_act_op = SRV_UCM_INT_START_DTMF_ACT;
            break;

        case SRV_UCM_STOP_DTMF_ACT:
            int_act_op = SRV_UCM_INT_STOP_DTMF_ACT;
            break;

    #if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
        case SRV_UCM_VT_FALLTO_VOICE_ACT:
            int_act_op = SRV_UCM_INT_VT_FALLTO_VOICE_ACT;
            break;
    #endif /* (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */

        default:
            MMI_ASSERT(0); /* not valid op_code */
            break;
    }

    return int_act_op;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_act_op
 * DESCRIPTION
 *  The function to query action op-code by internal action op-code
 * PARAMETERS
 *  int_act_op         [IN]            Internal action op-code
 * RETURNS
 *  Action op-code
 *****************************************************************************/
srv_ucm_act_opcode_enum srv_ucm_query_act_op(srv_ucm_int_act_opcode_enum int_act_op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_act_opcode_enum act_op = SRV_UCM_NO_ACT;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (int_act_op)
    {
        case SRV_UCM_INT_DIAL_ACT:
            act_op = SRV_UCM_DIAL_ACT;
            break;

        case SRV_UCM_INT_ACCEPT_ACT:
            act_op = SRV_UCM_ACCEPT_ACT;
            break;

        case SRV_UCM_INT_HOLD_ACT:
            act_op = SRV_UCM_HOLD_ACT;
            break;

        case SRV_UCM_INT_RETRIEVE_ACT:
            act_op = SRV_UCM_RETRIEVE_ACT;
            break;

        case SRV_UCM_INT_SWAP_ACT:
            act_op = SRV_UCM_SWAP_ACT;
            break;

        case SRV_UCM_INT_CONFERENCE_ACT:
            act_op = SRV_UCM_CONFERENCE_ACT;
            break;

        case SRV_UCM_INT_SPLIT_ACT:
            act_op = SRV_UCM_SPLIT_ACT;
            break;

    #ifdef __MMI_UCM_DEFLECT__
        case SRV_UCM_INT_DEFLECT_ACT:
            act_op = SRV_UCM_DEFLECT_ACT;
            break;
    #endif /* __MMI_UCM_DEFLECT__ */

    #ifdef __MMI_UCM_TRANSFER__
        case SRV_UCM_INT_TRANSFER_ACT:
            act_op = SRV_UCM_TRANSFER_ACT;
            break;
    #endif /* __MMI_UCM_TRANSFER__ */

    #ifdef __MMI_UCM_ECT__
        case SRV_UCM_INT_EXPLICIT_CALL_TRANSFER_ACT:
            act_op = SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT;
            break;
    #endif /* __MMI_UCM_ECT__ */

        case SRV_UCM_INT_END_SINGLE_ACT:
            act_op = SRV_UCM_END_SINGLE_ACT;
            break;

        case SRV_UCM_INT_END_CONFERENCE_ACT:
            act_op = SRV_UCM_END_CONFERENCE_ACT;
            break;

        case SRV_UCM_INT_END_ALL_ACT:
            act_op = SRV_UCM_END_ALL_ACT;
            break;

        case SRV_UCM_INT_START_DTMF_ACT:
            act_op = SRV_UCM_START_DTMF_ACT;
            break;

        case SRV_UCM_INT_STOP_DTMF_ACT:
            act_op = SRV_UCM_STOP_DTMF_ACT;
            break;

    #if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
        case SRV_UCM_INT_VT_FALLTO_VOICE_ACT:
            act_op = SRV_UCM_VT_FALLTO_VOICE_ACT;
            break;
    #endif /* (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */

        default:
            MMI_ASSERT(0); /* not valid op_code */
            break;
    }

    return act_op;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_incoming_call
 * DESCRIPTION
 *  check if there is incoming call
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means there is incoming call.
 *  MMI_FALSE means there is no incoming call.
 *****************************************************************************/
MMI_BOOL srv_ucm_is_incoming_call()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_outgoing_call
 * DESCRIPTION
 *  check if there is outgoing call
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means there is outgoing call.
 *  MMI_FALSE means there is no outgoing call.
 *****************************************************************************/
MMI_BOOL srv_ucm_is_outgoing_call()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_any_call
 * DESCRIPTION
 *  check if there is any call
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means there is any call.
 *  MMI_FALSE means there is no call.
 *****************************************************************************/
MMI_BOOL srv_ucm_is_any_call()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_emergency_call
 * DESCRIPTION
 *  check if there is emergency call exists
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means there is emergency call.
 *  MMI_FALSE means there is no emergency call.
 *****************************************************************************/
extern MMI_BOOL srv_ucm_is_emergency_call()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0, call_index = 0;
    srv_ucm_int_query_number_struct number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (group_index = 0; group_index < g_ucm_srv_p->call_list.num_group; group_index++)
    {
        for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[group_index].num_call; call_index++)
        {
            memset(&number, 0, sizeof(srv_ucm_int_query_number_struct));
            memcpy(&number.num_uri, &g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].remote_info.num_uri, SRV_UCM_MAX_NUM_URI_LEN); 
            number.module = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].module_id;
            if (srv_ucm_int_query(g_ucm_srv_p->call_list.group_info[group_index].call_type, SRV_UCM_INT_ECC_NUMBER, (void *)&number) == MMI_TRUE)
            {
                return MMI_TRUE;
            }
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_call_srv_available
 * DESCRIPTION
 *  The function to query if the call type service is available now
 * PARAMETERS
 *  call_type:       [IN]        Call type
 * RETURNS
 *  MMI_TRUE means any of input cal types is available
 *****************************************************************************/
MMI_BOOL srv_ucm_is_call_srv_available(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    MMI_BOOL result = MMI_FALSE;
    srv_ucm_int_query_callback_func_ptr query_cb = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < SRV_UCM_TOTAL_CALL_TYPE ; i++)
    {
        if (call_type & (srv_ucm_call_type_enum)(1 << i))
        {
            query_cb = srv_ucm_int_query_call_srv_query_callback((srv_ucm_call_type_enum)(1 << i));
            if (query_cb != NULL)
            {
                result = query_cb((srv_ucm_call_type_enum)(1 << i), SRV_UCM_INT_CALL_SRV_AVAILABLE, NULL);
                if (result == MMI_TRUE)
                {
                    return result;
                }
            }
        }
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_call_srv_tmp_unavailable
 * DESCRIPTION
 *  The function to query if the call type service is temporarily unavailable now
 * PARAMETERS
 *  call_type:       [IN]        Call type
 * RETURNS
 *  MMI_TRUE means any of input cal types is temporarily unavailable now
 *****************************************************************************/
MMI_BOOL srv_ucm_is_call_srv_tmp_unavailable(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    MMI_BOOL result = MMI_FALSE;
    srv_ucm_int_query_callback_func_ptr query_cb = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < SRV_UCM_TOTAL_CALL_TYPE ; i++)
    {
        if (call_type & (srv_ucm_call_type_enum)(1 << i))
        {
            query_cb = srv_ucm_int_query_call_srv_query_callback((srv_ucm_call_type_enum)(1 << i));
            if (query_cb != NULL)
            {
                result = query_cb((srv_ucm_call_type_enum)(1 << i), SRV_UCM_INT_CALL_SRV_TMP_UNAVAILABLE, NULL);
                if (result == MMI_TRUE)
                {
                    return result;
                }
            }
        }
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_valid_number
 * DESCRIPTION
 *  The function to check if the number is valid or not
 * PARAMETERS
 *  call_type:      [IN]        Call type, can use bitwise value to query multiple call types
 *  number:         [IN]        Number, ascii
 * RETURNS
 *  MMI_TRUE means it is valid number for any of input cal types
 *  MMI_FALSE means it is not valid number for any of input cal types
 *****************************************************************************/
MMI_BOOL srv_ucm_is_valid_number(srv_ucm_call_type_enum call_type, U8 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    srv_ucm_int_query_number_struct num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (strlen((CHAR *)number) > SRV_UCM_MAX_NUM_URI_LEN)
    {
        return MMI_FALSE;
    }

    memset(&num, 0, sizeof(srv_ucm_int_query_number_struct));
    memcpy(&num.num_uri, number, SRV_UCM_MAX_NUM_URI_LEN); 
    num.module = SRV_UCM_MODULE_ORIGIN_COMMON;

    for (i = 0; i < SRV_UCM_TOTAL_CALL_TYPE ; i++)
    {
        if (call_type & (srv_ucm_call_type_enum)(1 << i))
        {
            if (srv_ucm_int_query((srv_ucm_call_type_enum)(1 << i), SRV_UCM_INT_NUMBER, (void *)&num) == MMI_TRUE)
            {
                return MMI_TRUE;
            }
        }
    }

    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_emergency_number
 * DESCRIPTION
 *  The function to check if the number is emergency number or not
 * PARAMETERS
 *  call_type:      [IN]        Call type, can use bitwise value to query multiple call types 
 *  number:         [IN]        Number, ascii
 * RETURNS
 *  MMI_TRUE means it is emergency number for any of input cal types
 *  MMI_FALSE means it is not emergency number for any of input cal types
 *****************************************************************************/
MMI_BOOL srv_ucm_is_emergency_number(srv_ucm_call_type_enum call_type, U8 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    srv_ucm_int_query_number_struct num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&num, 0, sizeof(srv_ucm_int_query_number_struct));
    memcpy(&num.num_uri, number, SRV_UCM_MAX_NUM_URI_LEN); 
    num.module = SRV_UCM_MODULE_ORIGIN_COMMON;

    for (i = 0; i < SRV_UCM_TOTAL_CALL_TYPE ; i++)
    {
        if (call_type & (srv_ucm_call_type_enum)(1 << i))
        {
            if (srv_ucm_int_query((srv_ucm_call_type_enum)(1 << i), SRV_UCM_INT_ECC_NUMBER, (void *)&num) == MMI_TRUE)
            {
                return MMI_TRUE;
            }
        }
    }

    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_valid_dtmf_digit
 * DESCRIPTION
 *  The function to check if the digit is valid DTMF digit or not
 * PARAMETERS
 *  call_type:       [IN]        Call type, can use bitwise value to query multiple call types 
 *  digit:           [IN]        Digit
 * RETURNS
 *  MMI_TRUE means it is valid DTMF digit for any of input cal types
 *  MMI_FALSE means it is not valid DTMF digit for any of input cal types
 *****************************************************************************/
MMI_BOOL srv_ucm_is_valid_dtmf_digit(srv_ucm_call_type_enum call_type, U16 digit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    srv_ucm_dtmf_struct dtmf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&dtmf, 0, sizeof(srv_ucm_dtmf_struct));
    dtmf.digit = digit;

    for (i = 0; i < SRV_UCM_TOTAL_CALL_TYPE ; i++)
    {
        if (call_type & (srv_ucm_call_type_enum)(1 << i))
        {
            if (srv_ucm_int_query((srv_ucm_call_type_enum)(1 << i), SRV_UCM_INT_DTMF_DIGIT, (void *)&dtmf) == MMI_TRUE)
            {
                return MMI_TRUE;
            }
        }
    }

    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_get_caller_res_info
 * DESCRIPTION
 *  get caller resource information
 * PARAMETERS
 *  call_id:         [IN]         call id
 *  res_info:        [OUT]        resource information
 * RETURNS
 *  MMI_TRUE means res_info is valid
 *  MMI_FALSE means res_info is invalid (get caller res info fails)
 *****************************************************************************/
MMI_BOOL srv_ucm_get_caller_res_info(srv_ucm_id_info_struct call_id, srv_ucm_caller_res_struct *res_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    srv_ucm_int_query_caller_res_struct* int_res_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!res_info)
    {
        return MMI_FALSE;
    }

    int_res_info = OslMalloc(sizeof(srv_ucm_int_query_caller_res_struct));
    memset(int_res_info, 0, sizeof(srv_ucm_call_entry_struct));

    memcpy(&(int_res_info->uid_info), &call_id, sizeof(srv_ucm_id_info_struct));

    for (i = 0; i < SRV_UCM_TOTAL_CALL_TYPE ; i++)
    {
        if (call_id.call_type & (srv_ucm_call_type_enum)(1 << i))
        {
            if (srv_ucm_int_query((srv_ucm_call_type_enum)(1 << i), SRV_UCM_INT_CALLER_RES, (void *)int_res_info) == MMI_TRUE)
            {
                res_info->res_type = int_res_info->res_type;
                res_info->pic_id = int_res_info->pic_id;
                memcpy(res_info->pic_path, int_res_info->pic_path, sizeof(res_info->pic_path));
                res_info->tone_id = int_res_info->tone_id;
                memcpy(res_info->tone_path, int_res_info->tone_path, sizeof(res_info->tone_path));
                res_info->video_id = int_res_info->video_id;
                memcpy(res_info->video_path, int_res_info->video_path, sizeof(res_info->video_path));
                res_info->is_video_sound = int_res_info->is_video_sound;
                OslMfree(int_res_info);
                return MMI_TRUE;
            }
        }
    }
    OslMfree(int_res_info);
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_call_count
 * DESCRIPTION
 *  The function to query call information, you can specify call state, call type,
 *  and get call count and index list as return
 *  Call index and group index will be initialized as -1, which means invalid index
 * PARAMETERS
 *  call_state:      [IN]        Call state
 *  call_type:       [IN]        Call type
 *  indexs_list:     [OUT]       Index list, array size is SRV_UCM_MAX_CALL, include group index and call index
 * RETURNS
 *  Call count
 *****************************************************************************/
S32 srv_ucm_query_call_count(srv_ucm_call_state_enum call_state, srv_ucm_call_type_enum call_type, srv_ucm_index_info_struct *index_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0, call_index, num_total = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Set default index as -1 */
    if (index_list != NULL)
    {
        for (call_index = 0; call_index < SRV_UCM_MAX_CALL; call_index++)
        {
            index_list[call_index].group_index = -1;
            index_list[call_index].call_index = -1;
        }
    }

    /* Search call table */
    for (group_index = 0; group_index < g_ucm_srv_p->call_list.num_group; group_index++)
    {
        for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[group_index].num_call; call_index++)
        {
            if ((g_ucm_srv_p->call_list.group_info[group_index].call_type & call_type) && 
                (g_ucm_srv_p->call_list.group_info[group_index].call_state & call_state) &&
                (g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id != SRV_UCM_INVALID_ID))
            {
                if (index_list != NULL)
                {
                    index_list[num_total].group_index = group_index;
                    index_list[num_total].call_index = call_index;
                }
                num_total ++;
            }
        }
    }

    return num_total;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_disconnecting_call_count
 * DESCRIPTION
 *  The function to query disconnecting call information, you can specify call state, call type,
 *  and get call count and index list as return
 *  Call index and group index will be initialized as -1, which means invalid index
 * PARAMETERS
 *  call_state:      [IN]        Call state
 *  call_type:       [IN]        Call type
 *  indexs_list:     [OUT]       Index list, array size is SRV_UCM_MAX_CALL, include group index and call index
 * RETURNS
 *  Call count
 *****************************************************************************/
S32 srv_ucm_query_disconnecting_call_count(srv_ucm_call_state_enum call_state, srv_ucm_call_type_enum call_type, srv_ucm_index_info_struct *index_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0, call_index, num_total = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Set default index as -1 */
    if (index_list != NULL)
    {
        for (call_index = 0; call_index < SRV_UCM_MAX_CALL; call_index++)
        {
            index_list[call_index].group_index = -1;
            index_list[call_index].call_index = -1;
        }
    }

    /* Search call table */
    for (group_index = 0; group_index < g_ucm_srv_p->call_list.num_group; group_index++)
    {
        for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[group_index].num_call; call_index++)
        {
            if ((g_ucm_srv_p->call_list.group_info[group_index].call_type & call_type) && 
                (g_ucm_srv_p->call_list.group_info[group_index].call_state & call_state) &&
                (g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id != SRV_UCM_INVALID_ID) &&
                (g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].is_disconnecting == MMI_TRUE))
            {
                if (index_list != NULL)
                {
                    index_list[num_total].group_index = group_index;
                    index_list[num_total].call_index = call_index;
                }
                num_total ++;
            }
        }
    }

    return num_total;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_call_data
 * DESCRIPTION
 *  From srv_ucm_query_call_count, you have group index and call index,
 *  this function is for you to get more detail information
 * PARAMETERS
 *  index:           [IN]        Call index and group index
 *  call_info:       [OUT]       Detail information for the specified call 
 * RETURNS
 *  MMI_TRUE means the call is found. Otherwise return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_ucm_query_call_data(srv_ucm_index_info_struct index, srv_ucm_call_info_struct *call_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0, call_index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (call_info == NULL)
    {
        MMI_ASSERT(0);
    }

    memset(call_info, 0, sizeof(srv_ucm_call_info_struct));
    group_index = index.group_index;
    call_index = index.call_index;

    if (g_ucm_srv_p->call_list.group_info[group_index].num_call != 0)
    {
        call_info->uid_info.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
        call_info->uid_info.group_id= g_ucm_srv_p->call_list.group_info[group_index].group_id;
        call_info->uid_info.call_id= g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;
        call_info->call_state = g_ucm_srv_p->call_list.group_info[group_index].call_state;
        memcpy(&call_info->remote_info, &g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].remote_info, sizeof(srv_ucm_remote_info_struct));
        call_info->module_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].module_id;
        call_info->proc_state = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state;
        call_info->act_op = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type;
        call_info->is_disconnecting = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].is_disconnecting;
        memcpy(&call_info->start_time, &g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].start_time, sizeof(MYTIME)); 

        return MMI_TRUE;
    }

    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_group_count
 * DESCRIPTION
 *  The function to query group information, you can specify call state, call type,
 *  and get group count and group index list as return
 *  Group index will be initialized as -1 which means invalid index
 * PARAMETERS
 *  call_state:      [IN]        Call state
 *  call_type:       [IN]        Call type
 *  single_only:     [IN]        Only care the groups with single call in it
 *  index_list:      [OUT]       Group index list, array size is SRV_UCM_MAX_GROUP
 * RETURNS
 *  Group count
 *****************************************************************************/
extern S32 srv_ucm_query_group_count(srv_ucm_call_state_enum call_state, srv_ucm_call_type_enum call_type, MMI_BOOL single_only, S32 *index_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0, num_total = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Set default index as -1 */
    if (index_list != NULL)
    {
        for (group_index = 0; group_index < SRV_UCM_MAX_GROUP; group_index++)
        {
            index_list[group_index] = -1;
        }
    }

    /* Search call table */
    for (group_index = 0; group_index < g_ucm_srv_p->call_list.num_group; group_index++)
    {
        if ((g_ucm_srv_p->call_list.group_info[group_index].call_type & call_type) && 
            (g_ucm_srv_p->call_list.group_info[group_index].call_state & call_state) &&
            (g_ucm_srv_p->call_list.group_info[group_index].call_info[0].call_id != SRV_UCM_INVALID_ID))
        {
            if (((single_only == MMI_TRUE) && (g_ucm_srv_p->call_list.group_info[group_index].num_call == 1)) ||
                (single_only == MMI_FALSE))
            {
                if (index_list != NULL)
                {
                    index_list[num_total] = group_index;
                }
                num_total ++;
            }
        }
    }

    return num_total;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_group_data
 * DESCRIPTION
 *  From srv_ucm_query_group_count, you have group index,
 *  this function is for you to get more detail information
 * PARAMETERS
 *  group_index:     [IN]        Group index
 *  group_info:      [OUT]       Group information
 * RETURNS
 *  Call count in the group
 *****************************************************************************/
extern S32 srv_ucm_query_group_data(S32 group_index, srv_ucm_group_info_struct *group_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 call_count = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((group_index >= SRV_UCM_MAX_GROUP) || (group_index < 0))
    {
        /* Invalid index */
        call_count = 0;
    }
    else if (g_ucm_srv_p->call_list.group_info[group_index].num_call != 0)
    {
        if (group_info != NULL)
        {
            /* Caller doesn't need group info */
            memset(group_info, 0, sizeof(srv_ucm_group_info_struct));
            group_info->group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
            group_info->call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
            group_info->call_state = g_ucm_srv_p->call_list.group_info[group_index].call_state;
        }
        call_count = g_ucm_srv_p->call_list.group_info[group_index].num_call;
    }

    return call_count;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_call_exist
 * DESCRIPTION
 *  Query if the call exists
 * PARAMETERS 
 *  uid_info:        [IN]        UID
 *  call_state:      [IN]        call state, can be bitwise
 * RETURNS
 *  MMI_TRUE means the call is found. Otherwise return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL srv_ucm_query_call_exist(srv_ucm_id_info_struct* uid_info, srv_ucm_call_state_enum call_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < g_ucm_srv_p->call_list.num_group; i++)
    {
        if ((g_ucm_srv_p->call_list.group_info[i].group_id == uid_info->group_id) &&
            (g_ucm_srv_p->call_list.group_info[i].call_type & uid_info->call_type) &&
            (g_ucm_srv_p->call_list.group_info[i].call_state & call_state))
        {
            for (j = 0; j < g_ucm_srv_p->call_list.group_info[i].num_call ; j++)
            {
                if (g_ucm_srv_p->call_list.group_info[i].call_info[j].call_id == uid_info->call_id)
                {
                    return MMI_TRUE;                    
                }
            }
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_group_exist
 * DESCRIPTION
 *  Query if the group exists
 * PARAMETERS 
 *  group_id:        [IN]        group id
 *  call_type:       [IN]        call type
 *  call_state:      [IN]        call state, can be bitwise
 * RETURNS
 *  MMI_TRUE means the group is found. Otherwise return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL srv_ucm_query_group_exist(S32 group_id, srv_ucm_call_type_enum call_type, srv_ucm_call_state_enum call_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < g_ucm_srv_p->call_list.num_group; i++)
    {
        if ((g_ucm_srv_p->call_list.group_info[i].group_id == group_id) &&
            (g_ucm_srv_p->call_list.group_info[i].call_type & call_type) &&
            (g_ucm_srv_p->call_list.group_info[i].call_state & call_state))
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_index_by_id
 * DESCRIPTION
 *  Get group index and call index from uid
 *  Call index and group index will be initialized as -1, which means invalid index
 * PARAMETERS 
 *  uid_info         [IN]        UID
 *  index:           [OUT]       Index contains group index and call index
 * RETURNS
 *  MMI_TRUE means the call is found. Otherwise return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL srv_ucm_query_index_by_id(srv_ucm_id_info_struct* uid_info, srv_ucm_index_info_struct* index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 j = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index->group_index = SRV_UCM_INVALID_INDEX;
    index->call_index = SRV_UCM_INVALID_INDEX;
 
    for (i = 0; i < g_ucm_srv_p->call_list.num_group; i++)
    {
        if ((g_ucm_srv_p->call_list.group_info[i].group_id == uid_info->group_id) &&
            (g_ucm_srv_p->call_list.group_info[i].call_type & uid_info->call_type))
        {
            for (j = 0; j < g_ucm_srv_p->call_list.group_info[i].num_call ; j++)
            {
                if (g_ucm_srv_p->call_list.group_info[i].call_info[j].call_id == uid_info->call_id)
                {
                    index->group_index = i;
                    index->call_index = j;
                    return MMI_TRUE;                    
                }
            }
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_group_index_by_group_id
 * DESCRIPTION
 *  Get group index from group id
 *  Group index will be initialized as -1, which means invalid index
 * PARAMETERS 
 *  group_id         [IN]        group id
 *  call_type        [IN]        call type, can't be bitwise, should be unique
 *  group_index:     [OUT]       group index
 * RETURNS
 *  MMI_TRUE means the group is found. Otherwise return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL srv_ucm_query_group_index_by_group_id(S16 group_id, srv_ucm_call_type_enum call_type, S32* group_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    *group_index = SRV_UCM_INVALID_INDEX;

    for (i = 0; i < g_ucm_srv_p->call_list.num_group; i++)
    {
        if ((g_ucm_srv_p->call_list.group_info[i].call_type == call_type) &&
            (g_ucm_srv_p->call_list.group_info[i].group_id == group_id))
        {
            *group_index = i;
            return MMI_TRUE;                    
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_curr_action
 * DESCRIPTION
 *  Query current ongoing action
 * PARAMETERS 
 * 
 * RETURNS
 *  srv_ucm_act_opcode_enum: current action
 *****************************************************************************/
srv_ucm_act_opcode_enum srv_ucm_query_curr_action()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_ucm_srv_p->call_misc.curr_action;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_reset_group_entry
 * DESCRIPTION
 *  Reset group entry.
 * PARAMETERS
 *  group_index     [IN]            Group index that is going to be reset
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_reset_group_entry(S32 group_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_ucm_srv_p->call_list.group_info[group_index], 0, sizeof(srv_ucm_group_entry_struct));
    g_ucm_srv_p->call_list.group_info[group_index].group_id = -1;
    for (i = 0; i < SRV_UCM_MAX_CALL_IN_GROUP; i++)
    {
        srv_ucm_reset_call_entry(group_index, i);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_reset_call_entry
 * DESCRIPTION
 *  Reset call entry.
 * PARAMETERS
 *  group_index     [IN]            Group index that is going to be reset 
 *  call_index      [IN]            Call index that is going to be reset
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_reset_call_entry(S32 group_index, S32 call_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index], 0, sizeof(srv_ucm_call_entry_struct));
    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id = -1;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_reset_index_list
 * DESCRIPTION
 *  Reset index list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_reset_index_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_ucm_srv_p->call_misc.index_list, -1, (SRV_UCM_MAX_CALL * sizeof(srv_ucm_index_info_struct)));
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_search_call_list
 * DESCRIPTION
 *  Your description
 * PARAMETERS 
 *  call_list       [IN]            Call service call list
 *  index_list      [IN/OUT]        Index list that matches the condition
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_search_call_list(srv_ucm_int_call_list_entry_info_struct call_list, srv_ucm_index_info_struct *index_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_ucm_srv_p->call_list.num_group; i++)
    {
        if ((call_list.uid_info.call_type == g_ucm_srv_p->call_list.group_info[i].call_type) && 
            (call_list.uid_info.group_id == g_ucm_srv_p->call_list.group_info[i].group_id))
        {
            index_list->group_index = i;
            for (j = 0; j < g_ucm_srv_p->call_list.group_info[i].num_call; j++)
            {
                if (call_list.uid_info.call_id == g_ucm_srv_p->call_list.group_info[i].call_info[j].call_id)
                {
                    index_list->call_index = j;
                    return; /* Group index, call index are found */
                }
            }
            return; /* Group index is found */
        }
    }
    return; /* Not found */
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_call_index_by_call_id
 * DESCRIPTION
 *  Get call index of the call list by call id
 * PARAMETERS
 *  call_list       [IN]        Call service call list
 *  call_list_size  [IN]        Call number in the list
 *  call_id         [IN]        Call id
 * RETURNS
 *  call index of the call list.
 *  -1 means the call is not found.
 *****************************************************************************/
S32 srv_ucm_query_call_index_by_call_id(srv_ucm_call_entry_struct *call_list, U8 call_list_size, S16 call_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 call_index = -1;
    U8 call_list_index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (call_list_index = 0; call_list_index <= call_list_size; call_list_index++)
    {
        if (call_list[call_list_index].call_id == call_id)
        {
            call_index = call_list_index;
            break;
        }
    }

    return call_index;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_group_index_by_call_state
 * DESCRIPTION
 *  Query group index by call state
 * PARAMETERS 
 *  call_state       [IN]        Call state
 * RETURNS
 *  Group index or -1 if call with the specified state does not exist.
 *****************************************************************************/
S32 srv_ucm_query_group_index_by_call_state(srv_ucm_call_state_enum call_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_ucm_srv_p->call_list.num_group; i++)
    {
        if (g_ucm_srv_p->call_list.group_info[i].call_state == call_state)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_GET_GROUP_INDEX_BY_CALL_STATE, call_state, i);
            return i;
        }
    }
    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_GET_GROUP_INDEX_BY_CALL_STATE_NO_CALL,call_state);
    return -1;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_error_message
 * DESCRIPTION
 *  Default error message for srv_ucm_result_enum
 * PARAMETERS
 *  error_cause:     [IN]        Error cause
 * RETURNS
 *  String ID for error message
 *****************************************************************************/
U16 srv_ucm_query_error_message(srv_ucm_result_enum error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (error_cause)
    {
    #ifdef __MMI_UCM_DETAIL_ERROR_MSG__
        case SRV_UCM_RESULT_USER_ABORT:
            return STR_ID_SRV_UCM_RESULT_USER_ABORT;
        case SRV_UCM_RESULT_INVALID_NUMBER: 
            return STR_GLOBAL_INVALID_NUMBER;
        case SRV_UCM_RESULT_EMPTY_NUMBER:
            return STR_ID_SRV_UCM_RESULT_EMPTY_NUMBER;
        case SRV_UCM_RESULT_CALLED_PARTY_BUSY:
            return STR_ID_SRV_UCM_RESULT_CALLED_PARTY_BUSY;
        case SRV_UCM_RESULT_NETWORK_NOT_AVAILABLE:
            return STR_ID_SRV_UCM_RESULT_NETWORK_NOT_AVAILABLE;
        case SRV_UCM_RESULT_CALLED_PARTY_NOT_ANSWERED:
            return STR_ID_SRV_UCM_RESULT_CALLED_PARTY_NOT_ANSWERED;
        case SRV_UCM_RESULT_UCM_BUSY:
            return STR_ID_SRV_UCM_RESULT_UCM_BUSY;
        case SRV_UCM_RESULT_CANCEL:
            return STR_ID_SRV_UCM_RESULT_CANCEL;
        case SRV_UCM_RESULT_FLIGHT_MODE_PROHIBIT:
            return STR_ID_SRV_UCM_RESULT_FLIGHT_MODE_PROHIBIT;
        case SRV_UCM_RESULT_PREFERRED_MODE_PROHIBIT:
            return STR_ID_SRV_UCM_RESULT_PREFERRED_MODE_PROHIBIT;
        case SRV_UCM_RESULT_SOS_CALL_EXISTS:
            return STR_ID_SRV_UCM_RESULT_SOS_CALL_EXISTS;
        case SRV_UCM_RESULT_SOS_NUMBER_ONLY:
            return STR_ID_SRV_UCM_RESULT_SOS_NUMBER_ONLY;
        case SRV_UCM_RESULT_LOW_BATTERY:
            return STR_ID_SRV_UCM_RESULT_LOW_BATTERY;
        case SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL:
            return STR_ID_SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL;
        case SRV_UCM_RESULT_NOT_ALLOWED_TO_ACCEPT:
            return STR_ID_SRV_UCM_RESULT_NOT_ALLOWED_TO_ACCEPT;
        case SRV_UCM_RESULT_ACTION_NOT_ALLOWED:
            return STR_ID_SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
        case SRV_UCM_RESULT_NO_ACTIVE_CALL:
            return STR_ID_SRV_UCM_RESULT_NO_ACTIVE_CALL;
        case SRV_UCM_RESULT_UNSPECIFIED_ERROR:
            return STR_GLOBAL_ERROR;
    #endif /* __MMI_UCM_DETAIL_ERROR_MSG__ */
        default:
            return STR_GLOBAL_ERROR;
    }
}

#ifdef __MMI_CM_BLACK_LIST_EXT__
/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_blacklist_call_type
 * DESCRIPTION
 *  Get blacklist call type by ucm call type
 * PARAMETERS
 *  ucm_call_type       [IN]        ucm call type
 * RETURNS
 *  srv_callset_call_type_enum
 *****************************************************************************/
srv_callset_call_type_enum srv_ucm_query_blacklist_call_type(srv_ucm_call_type_enum ucm_call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (ucm_call_type & SRV_UCM_VOICE_CALL_TYPE_ALL)
    {
        return SRV_CALLSET_VOICE_CALL;
    }
#ifdef __MMI_VIDEO_TELEPHONY__
    else if (ucm_call_type & SRV_UCM_VIDEO_CALL_TYPE_ALL)
    {
        return SRV_CALLSET_VIDEO_CALL;
    }
#endif /*__MMI_VIDEO_TELEPHONY__ */
    else
    {
        return SRV_CALLSET_CALL_TYPE_INVALID;
    }
}
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_malloc
 * DESCRIPTION
 *  Call list is too large, UCM provides memory allocation function for call srv
 * PARAMETERS
 *  size:            [IN]        size
 * RETURNS
 *  pointer
 *****************************************************************************/
void* srv_ucm_int_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 size_of_list = SRV_UCM_CALL_LIST_SIZE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((sizeof(srv_ucm_int_call_list_struct) > size_of_list) ||
        (g_ucm_srv_p->call_misc.mem_occupied == 3))
    {
        /* Check the define of SRV_UCM_CALL_LIST_SIZE or not free yet */
        MMI_ASSERT(0);
    }

    g_ucm_srv_p->call_misc.mem_occupied++;

#if (SRV_UCM_CALL_LIST_SIZE >= 2000)
    memset(&srv_ucm_memory[g_ucm_srv_p->call_misc.mem_occupied-1],
        0,
        sizeof(srv_ucm_memory[g_ucm_srv_p->call_misc.mem_occupied-1]));
    return &srv_ucm_memory[g_ucm_srv_p->call_misc.mem_occupied-1];
#else /* (SRV_UCM_CALL_LIST_SIZE >= 2000) */
    return OslMalloc(size);
#endif /* (SRV_UCM_CALL_LIST_SIZE >= 2000) */

}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_mfree
 * DESCRIPTION
 *  Memory free function provided by UCM
 * PARAMETERS
 *  p:               [IN]        pointer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_int_mfree(void* p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_ucm_srv_p->call_misc.mem_occupied == 0)
    {
        /* Not allocated yet */
        MMI_ASSERT(0);
    }

    g_ucm_srv_p->call_misc.mem_occupied--;

#if (SRV_UCM_CALL_LIST_SIZE < 2000)
    OslMfree(p);
    p = NULL;
#endif /* (SRV_UCM_CALL_LIST_SIZE < 2000) */

}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_voice_type_by_sim
 * DESCRIPTION
 *  Get ucm service voice call type by sim id
 * PARAMETERS
 *  sim_id       [IN]        sim id
 * RETURNS
 *  voice call type
 *****************************************************************************/
srv_ucm_call_type_enum srv_ucm_query_voice_type_by_sim(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_call_type_enum call_type = SRV_UCM_VOICE_CALL_TYPE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (sim_id)
    {
        case MMI_SIM1:
            call_type = SRV_UCM_VOICE_CALL_TYPE;
            break;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            call_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
            break;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            call_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
            break;
    #if (MMI_MAX_SIM_NUM == 4)
        case MMI_SIM4:
            call_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
            break;
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        default:
            MMI_ASSERT(0);
            break;
    }
    return call_type;
}


