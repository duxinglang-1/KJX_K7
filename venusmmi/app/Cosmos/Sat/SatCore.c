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
 *  SatCore.c
 *
 * Project:
 * --------
 *  MAUI
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
 * removed!
 * removed!
 * removed!
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

#ifdef __cplusplus
extern "C"{
#endif

#include "MMIDataType.h"
#include "gui.h"
#include "app_mem.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "mmi_frm_mem_gprot.h"
#include "AlarmSrvGprot.h"
#include "ProfilesSrvGprot.h"
#include "UcmSrvGprot.h"
#include "SatCoreProt.h"
#include "SatSrvGprot.h"
#include "mmi_rp_srv_sat_def.h"
#include "wgui_categories_list.h"



/***************************************************************************** 
 * MARCO
 *****************************************************************************/
#define MMI_SAT_ICON_PATH_LENGTH    32


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_cmd_hint
 * DESCRIPTION
 *  To get menu item hints(next indication).
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
PU8 mmi_sat_get_cmd_hint(srv_sat_cmd_enum cmd_type, srv_sat_cmd_enum for_cmd_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 res = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cmd_type)
    {
        case SRV_SAT_CMD_SEND_SMS:
            res = (PU8)GetString(STR_ID_SAT_NEXT_ACTION_SEND_SMS);
            break;

        case SRV_SAT_CMD_SETUP_CALL:
             res = (PU8)GetString(STR_ID_SAT_NEXT_ACTION_SETUP_CALL);
             break;

        case SRV_SAT_CMD_LAUNCH_BROWSER:
            res = (PU8)GetString(STR_ID_SAT_NEXT_ACTION_LAUNCH_BROWSER);
            break;

        case SRV_SAT_CMD_PROVIDE_LOCAL_INFORMATION:
            if (for_cmd_type == SRV_SAT_CMD_SETUP_MENU)
            {
                res = (PU8)GetString(STR_ID_SAT_NEXT_ACTION_PROVIDE_LOCAL_INFORMATION);
            }
            else
            {
                res = (PU8)GetString(STR_ID_SAT_NEXT_ACTION_PROVIDE_LOCAL_INFO);
            }
            break;

        default:
            break;
    }

    return res;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_setup_menu_response
 * DESCRIPTION
 *  SAT setup menu response.
 * PARAMETERS
 *  sim_id          [IN]        sim id
 *  res_type       [IN]         response type
 * RETURNS
 *  Return MMI_TRUE will show please screen.
 *****************************************************************************/
MMI_BOOL mmi_sat_setup_menu_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type, U8 item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;

    switch (res_type)
    {
        case SAT_RSP_OK:
            srv_sat_envelope_menu_selection(sim_id, item_id, MMI_FALSE);
            break;

        case SAT_RSP_HELP:
            srv_sat_envelope_menu_selection(sim_id, item_id, MMI_TRUE); 
            break;

        case SAT_RSP_BACK:
            mmi_frm_scrn_close_active_id();
            ret = MMI_FALSE;
            break;

        default:
            ret = MMI_FALSE;
            break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_select_item_response
 * DESCRIPTION
 *  select item command response function.
 * PARAMETERS
 *  sim_id      [IN]        sim id
 *  res_type   [IN]         response type
 * RETURNS
 *  Return MMI_TRUE will show please screen.
 *****************************************************************************/
MMI_BOOL mmi_sat_select_item_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type, U8 item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
    srv_sat_stop_timer(sim_id, SAT_TIMER_NO_RESPONSE);

    switch (res_type)
    {
        case SAT_RSP_OK:
            srv_sat_terminal_response_select_item(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY,
                    item_id);

            break;

        case SAT_RSP_HELP:
            srv_sat_terminal_response_select_item(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_HELP_INFO_REQUIRED_BY_USER,
                    item_id);

            break;

        case SAT_RSP_BACK:
            srv_sat_terminal_response_select_item(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_BACKWARD_MOVE_IN_PROACTIVE_SESSION_REQUESTED_BY_USER,
                    item_id);

            break;

        case SAT_RSP_TERMINATE:
            srv_sat_terminal_response_select_item(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER,
                    item_id);

            ret = MMI_FALSE;
            break;

        default:
            break;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_sat_display_text_response
* DESCRIPTION
*  Display text command response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
*  is_sent      [IN]        already sent terminal response
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_display_text_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_sat_terminal_res_enum res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res = SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY;
    srv_sat_stop_timer(sim_id, SAT_TIMER_NO_RESPONSE);
    srv_sat_stop_timer(sim_id, SAT_TIMER_CLEAR_DELAY);

    switch (res_type)
    {
        case SAT_RSP_OK:
        case SAT_RSP_IMMEDIATE_OK:
        case SAT_RSP_DELAY_OK:
            res = SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY;
            break;

        case SAT_RSP_BACK:
            res = SRV_SAT_TERMINAL_RES_BACKWARD_MOVE_IN_PROACTIVE_SESSION_REQUESTED_BY_USER;
            break;

        case SAT_RSP_TERMINATE:
            res = SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER;
            break;

        case SAT_RSP_NO_RESPONSE:
            res = SRV_SAT_TERMINAL_RES_NO_RESPONSE_FROM_USER;
            break;

        default:
            break;
    }

    srv_sat_terminal_response_display_text(
            sim_id,
            res,
            SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);

    if (res_type == SAT_RSP_OK || res_type == SAT_RSP_DELAY_OK || res_type == SAT_RSP_BACK)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_sat_get_inkey_response
* DESCRIPTION
*  Get inkey command response function.
* PARAMETERS
*  sim_id      [IN]         sim id
*  res_type   [IN]        response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_get_inkey_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type, MMI_BOOL is_yes_selected, WCHAR *input_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    srv_sat_stop_timer(sim_id, SAT_TIMER_NO_RESPONSE);

    switch (res_type)
    {
        case SAT_RSP_OK:
        {
            srv_sat_terminal_response_get_inkey(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY,
                    is_yes_selected,
                    input_buf);

            ret = MMI_TRUE;
            break;
        }

        case SAT_RSP_HELP:
        {
            srv_sat_terminal_response_get_inkey(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_HELP_INFO_REQUIRED_BY_USER,
                    MMI_FALSE,
                    NULL);

            ret = MMI_TRUE;
            break;
        }

        case SAT_RSP_BACK:
        {
            srv_sat_terminal_response_get_inkey(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_BACKWARD_MOVE_IN_PROACTIVE_SESSION_REQUESTED_BY_USER,
                    MMI_FALSE,
                    NULL);

            ret = MMI_TRUE;
            break;
        }

        case SAT_RSP_TERMINATE:
        {
            srv_sat_terminal_response_get_inkey(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER,
                    MMI_FALSE,
                    NULL);

            ret = MMI_FALSE;
            break;
        }

        default:
            ret = MMI_FALSE;
            break;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_sat_get_input_response
* DESCRIPTION
*  Get input command response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_get_input_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type, WCHAR *input_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    srv_sat_stop_timer(sim_id, SAT_TIMER_NO_RESPONSE);

    switch (res_type)
    {
        case SAT_RSP_OK:
        {
            srv_sat_terminal_response_get_input(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY,
                    input_buf);

            ret = MMI_TRUE;
            break;
        }

        case SAT_RSP_HELP:
        {
            srv_sat_terminal_response_get_input(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_HELP_INFO_REQUIRED_BY_USER,
                    NULL);

            ret = MMI_TRUE;
            break;
        }

        case SAT_RSP_BACK:
        {
            srv_sat_terminal_response_get_input(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_BACKWARD_MOVE_IN_PROACTIVE_SESSION_REQUESTED_BY_USER,
                    NULL);

            ret = MMI_TRUE;
            break;
        }

        case SAT_RSP_TERMINATE:
        {
            srv_sat_terminal_response_get_input(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER,
                    NULL);
            break;
        }

        default:
            break;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_sat_play_tone_response
* DESCRIPTION
*  Play tone command response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_play_tone_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    srv_sat_stop_timer(sim_id, SAT_TIMER_PLAY_TONE);
    srv_prof_stop_tone(SRV_PROF_TONE_SAT);

    switch (res_type)
    {
        case SAT_RSP_OK:
        {
            srv_sat_terminal_response_play_tone(
                   sim_id,
                    SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY);

            ret = MMI_TRUE;
            break;
        }

        case SAT_RSP_BACK:
        {
            srv_sat_terminal_response_play_tone(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER);

            ret = MMI_TRUE;
            break;
        }

        case SAT_RSP_TERMINATE:
        {                
            srv_sat_terminal_response_play_tone(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER);
            break;
        }

        default:
            break;
    }

    return ret;
}

//send sms screen

//send ss screen

/*****************************************************************************
* FUNCTION
*  mmi_sat_send_ss_result_response
* DESCRIPTION
*  Send SS result response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_send_ss_result_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type, U8 length, PU8 add_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_terminal_response_send_ss_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY,
            length,
            add_info);

    if (res_type == SAT_RSP_TERMINATE)
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}

//send ussd screen

/*****************************************************************************
* FUNCTION
*  mmi_sat_send_ussd_result_response
* DESCRIPTION
*  Send USSD command result response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]        response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_send_ussd_result_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type, U8 length, PU8 add_info)
{
    srv_sat_terminal_response_send_ussd_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY,
            length,
            add_info);

    if (res_type == SAT_RSP_TERMINATE)
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_sat_setup_call_response
* DESCRIPTION
*  Setup call command response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_setup_call_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type, srv_ucm_result_enum *error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    switch (res_type)
    {
        case SAT_RSP_OK:
            ret = mmi_sat_setup_call_ucm_requset(sim_id, error_code) ? MMI_FALSE : MMI_TRUE;
            break;

        case SAT_RSP_CANCEL:
            srv_sat_terminal_response_setup_call_stage2(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_USER_DID_NOT_ACCEPT_PROACTIVE_CMD,
                    SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);

            ret = MMI_TRUE;
            break;

        case SAT_RSP_TERMINATE:
            srv_sat_terminal_response_setup_call_stage2(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER,
                    SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
            break;

        default:
            break;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_sat_setup_call_ucm_requset
* DESCRIPTION
*  Call UCM service to lauch a call.
* PARAMETERS
*  sim_id      [IN]        sim id
* RETURNS
*  Return MMI_TRUE represent that make a call success.
*****************************************************************************/
MMI_BOOL mmi_sat_setup_call_ucm_requset(mmi_sim_enum sim_id, srv_ucm_result_enum *error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_dial_act_req_struct dial_req;
    srv_ucm_result_enum result;
    srv_sat_proactive_sim_struct *cmd_data = NULL;
    srv_sat_setup_call_struct *call = NULL;
    MMI_BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmd_data = (srv_sat_proactive_sim_struct *)srv_sat_get_last_proactive_sim(sim_id); 
    call = (srv_sat_setup_call_struct *)(&cmd_data->cmd_data);
    memset(&dial_req, 0, sizeof(srv_ucm_dial_act_req_struct));

#if (MMI_MAX_SIM_NUM >= 2)
    if (sim_id == MMI_SIM2)
    {
        dial_req.call_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (sim_id == MMI_SIM3)
    {
        dial_req.call_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
    }
#if (MMI_MAX_SIM_NUM >= 4)
    else if (sim_id == MMI_SIM4)
    {
        dial_req.call_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
    }
#endif /* MMI_MAX_SIM_NUM >= 4 */
#endif /* MMI_MAX_SIM_NUM >= 3 */
    else
    {
        dial_req.call_type = SRV_UCM_VOICE_CALL_TYPE;
    }
#else
    dial_req.call_type = SRV_UCM_VOICE_CALL_TYPE;
#endif /* MMI_MAX_SIM_NUM >= 2 */
	if(strlen((CHAR *)call->number) > SRV_UCM_MAX_NUM_URI_LEN )
	{
		if(call->number[0] == '+')
		{
			mmi_asc_n_to_ucs2((CHAR *)dial_req.num_uri, (CHAR *)call->number, SRV_UCM_MAX_NUM_URI_LEN);
		}
		else
		{
			mmi_asc_n_to_ucs2((CHAR *)dial_req.num_uri, (CHAR *)call->number, SRV_UCM_MAX_NUM_URI_LEN - 1);
		}

	}
	else
	{
    mmi_asc_to_ucs2((CHAR *)dial_req.num_uri, (CHAR *)call->number);
	}
    dial_req.module_id = SRV_UCM_MODULE_ORIGIN_SAT;
  

    /* Dial */
    result = srv_ucm_query_act_permit(SRV_UCM_DIAL_ACT, &dial_req);
    if (result == SRV_UCM_RESULT_OK)
    {
        srv_ucm_act_request(SRV_UCM_DIAL_ACT, &dial_req, NULL, NULL);
    }
    else
    {
        /* Error handling for action can't be performed */
        *error_code = result;
        srv_sat_terminal_response_setup_call_stage2(
                sim_id,
                SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
                SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);

        ret = MMI_FALSE;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_sat_send_dtmf_response
* DESCRIPTION
*  Send DTMF command response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_send_dtmf_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_send_dtmf_abort_req(sim_id);

    return MMI_FALSE;
}

#ifdef __SATCC__
#ifdef BROWSER_SUPPORT
/*****************************************************************************
* FUNCTION
*  mmi_sat_launch_browser_response
* DESCRIPTION
*  Launch browser response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_launch_browser_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    switch (res_type)
    {
        case SAT_RSP_OK:
            srv_sat_terminal_response_launch_browser_stage1(sim_id);
            break;

        case SAT_RSP_CANCEL:
            srv_sat_terminal_response_launch_browser_stage2(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_USER_DID_NOT_ACCEPT_PROACTIVE_CMD,
                    SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);

            ret = MMI_TRUE;
            break;

        case SAT_RSP_TERMINATE:
            srv_sat_terminal_response_launch_browser_stage2(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
                    SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
            break;

        default:
            break;
    }

    return ret;
}
#endif /* BROWSER_SUPPORT */
#endif

#ifdef __SATCE__
/*****************************************************************************
* FUNCTION
*  mmi_sat_open_channel_response
* DESCRIPTION
*  Open channel command response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_open_channel_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    switch (res_type)
    {
        case SAT_RSP_OK:
            srv_sat_terminal_response_open_channel(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY,
                    SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);

            ret = MMI_TRUE;
            break;

        case SAT_RSP_CANCEL:
            srv_sat_terminal_response_open_channel(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_USER_DID_NOT_ACCEPT_PROACTIVE_CMD,
                    SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);

            ret = MMI_TRUE;
            break;

        case SAT_RSP_TERMINATE:
            srv_sat_terminal_response_open_channel(
                    sim_id,
                    SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER,
                    SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
            break;

        default:
            break;
    }

    return ret;
}


#ifdef __SRV_SAT_TR_CLOSE_CHANNEL__
/*****************************************************************************
* FUNCTION
*  mmi_sat_close_channel_response
* DESCRIPTION
*  Close channel command response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_close_channel_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_terminal_response_close_channel(
            sim_id,
            SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER);

    return MMI_FALSE;
}
#endif /* __SRV_SAT_TR_CLOSE_CHANNEL__ */



/*****************************************************************************
* FUNCTION
*  mmi_sat_send_data_response
* DESCRIPTION
*  Send data command response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_send_data_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_terminal_response_send_data(
            sim_id,
            SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER);

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_sat_recv_data_response
* DESCRIPTION
*  Receive data command response function.
* PARAMETERS
*  sim_id      [IN]        sim id
*  res_type   [IN]         response type
* RETURNS
*  Return MMI_TRUE will show please screen.
*****************************************************************************/
MMI_BOOL mmi_sat_recv_data_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_terminal_response_receive_data(
            sim_id,
            SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER);

    return MMI_FALSE;
}
#endif /* __SATCE__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_create_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_create_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 drive;
    CHAR path_ascii[MMI_SAT_ICON_PATH_LENGTH];
    CHAR path_usc2[MMI_SAT_ICON_PATH_LENGTH];
    FS_HANDLE fh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drive = SRV_FMGR_PUBLIC_DRV;
    if (drive > 0)
    {
        sprintf(path_ascii, "%c:\\sat", (CHAR)drive);
        mmi_asc_to_ucs2(path_usc2, path_ascii);

        fh = FS_Open((U16*)path_usc2, FS_OPEN_DIR | FS_READ_ONLY);
        if (fh > 0)
        {
            FS_Close(fh);
        }
        else
        {
            if (FS_CreateDir((U16*)path_usc2) == FS_NO_ERROR)
            {
                FS_SetAttributes((U16*)path_usc2, FS_ATTR_DIR | FS_ATTR_HIDDEN);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_create_calling_icon_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
CHAR *mmi_sat_create_calling_icon_path(mmi_sim_enum sim_id, CHAR **save_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 drive;
    CHAR path_ascii[MMI_SAT_ICON_PATH_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drive = SRV_FMGR_PUBLIC_DRV;
    if (drive <= 0)
    {
        return NULL;
    }

    *save_path = (CHAR *)OslMalloc(MMI_SAT_ICON_PATH_LENGTH * ENCODING_LENGTH);
    memset(*save_path, 0, MMI_SAT_ICON_PATH_LENGTH * ENCODING_LENGTH);

    switch (sim_id)
    {
        case MMI_SIM1:
            sprintf(path_ascii, "%c:\\sat\\sat1callicon.pbm", (CHAR)drive);
            break;

#if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            sprintf(path_ascii, "%c:\\sat\\sat2callicon.pbm", (CHAR)drive);
            break;
#if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            sprintf(path_ascii, "%c:\\sat\\sat3callicon.pbm", (CHAR)drive);
            break;
#endif /* MMI_MAX_SIM_NUM >= 3 */
#if (MMI_MAX_SIM_NUM >= 4)
        case MMI_SIM4:
            sprintf(path_ascii, "%c:\\sat\\sat4callicon.pbm", (CHAR)drive);
            break;
#endif /* MMI_MAX_SIM_NUM >= 4 */
#endif /* MMI_MAX_SIM_NUM >= 2 */

        default:
            ASSERT(0);
            break;
    }

    mmi_asc_to_ucs2(*save_path, path_ascii);

    return *save_path;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_sat_save_calling_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  icon_data       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sat_save_calling_icon(mmi_sim_enum sim_id, PU8 icon_data, CHAR *save_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *app_asm_ptr = NULL;
    GDI_HANDLE temp_layer;
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (icon_data == NULL)
    {
        return MMI_FALSE;
    }

    app_asm_ptr = applib_mem_ap_alloc_framebuffer(VAPP_SAT, (*(icon_data + 8)) * (*(icon_data + 12)) * 2);

    memcpy(app_asm_ptr, (icon_data + 8 + 13), (*(icon_data + 8)) * (*(icon_data + 12)) * 2);

    ret = gdi_layer_create_cf_using_outside_memory(
                  GDI_COLOR_FORMAT_16,
                  0,
                  0,
                  *(icon_data + 8),
                  *(icon_data + 12),
                  &temp_layer,
                  (U8*)app_asm_ptr,
                  (*(icon_data + 8)) * (*(icon_data + 12)) * 2);

    MMI_ASSERT(ret == GDI_SUCCEED);

    ret = gdi_layer_save_bmp_file(temp_layer, save_path);
    gdi_layer_free(temp_layer);
    applib_mem_ap_free(app_asm_ptr);

    if (ret != GDI_SUCCEED)
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_nw_detach_before_reboot
 * DESCRIPTION
 *  Detach network before SAT reboot
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_sim_reboot(mmi_sim_enum sim_id)
{
    srv_alm_normal_reset(MMI_TRUE, 3);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_nw_detach_before_reboot
 * DESCRIPTION
 *  Detach network before SAT reboot
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_nw_detach_before_reboot(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_dest = MOD_L4C;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_sat_nw_detach_before_reboot_hdlr, MSG_ID_MMI_NW_PWROFF_DETACH_RSP);

#if (MMI_MAX_SIM_NUM >=2)
    if (sim_id == MMI_SIM1)
    {
	     module_dest = MOD_L4C;
    }
    else if (sim_id == MMI_SIM2)
    {
        module_dest = MOD_L4C_2;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (sim_id == MMI_SIM3)
    {
	     module_dest = MOD_L4C_3;
    }
#endif /* MMI_MAX_SIM_NUM >= 3 */
#if (MMI_MAX_SIM_NUM >= 4)
    else if (sim_id == MMI_SIM4)
    {
	    module_dest = MOD_L4C_4;
    }
#endif /* MMI_MAX_SIM_NUM >= 4*/
#else
    module_dest = MOD_L4C;
#endif /* MMI_MAX_SIM_NUM >= 2 */

    mmi_frm_send_ilm(module_dest, MSG_ID_MMI_NW_PWROFF_DETACH_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_nw_detach_before_reboot_hdlr
 * DESCRIPTION
 *  Detach network handler before SAT reboot
 * PARAMETERS
 *  info        [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_nw_detach_before_reboot_hdlr(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_id = MMI_SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >=2)
    if (mod_src == MOD_L4C)
    {
        sim_id = MMI_SIM1;
    }
    else if (mod_src == MOD_L4C_2)
    {
        sim_id = MMI_SIM2;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (mod_src == MOD_L4C_3)
    {
    	sim_id = MMI_SIM3;
    }
#endif /* MMI_MAX_SIM_NUM >= 3 */
#if (MMI_MAX_SIM_NUM >= 4)
    else if (mod_src == MOD_L4C_4)
    {
    	sim_id = MMI_SIM4;
    }
#endif /* MMI_MAX_SIM_NUM >= 4 */
#endif /* MMI_MAX_SIM_NUM >=2 */

    srv_sat_stop_timer(sim_id, SAT_TIMER_REFRESH_REBOOT);
    ClearProtocolEventHandler(MSG_ID_MMI_NW_PWROFF_DETACH_RSP);
    srv_alm_pwr_reset(MMI_TRUE, 3);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_screen_capability
 * DESCRIPTION
 *  Export to SMU to calculate screen capability for profile download
 * PARAMETERS
 *  max_char_down       [OUT]
 *  max_char_accross    [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_get_screen_capability(U8 *max_char_down, U8 *max_char_accross)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dialog_width, dialog_height;
    S32 string_width, string_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_character_type m_str[2] =  {'W', 0};

    /* refer to coordinate_set151[] */
#ifdef __MMI_MAINLCD_240X320__
    dialog_width = MMI_POP_UP_DIALOG_WIDTH - 12;
    dialog_height = MMI_POP_UP_DIALOG_HEIGHT - 12;
#else /* __MMI_MAINLCD_240X320__ */
    dialog_width = MMI_POP_UP_DIALOG_WIDTH - 4;
    dialog_height = MMI_POP_UP_DIALOG_HEIGHT - 8;
#endif /* __MMI_MAINLCD_240X320__ */

    string_width = 19;
    string_height = 20;
    gui_measure_string(m_str, &string_width, &string_height);

    ASSERT(string_width && string_height);

    *max_char_down = (U8)(dialog_height / string_width) - 1;    /* minus the border and space between two words */
    *max_char_accross = (U8)(dialog_width / string_height) - 3; /* minus the border and space between two words */
}


#ifdef __cplusplus
}
#endif
