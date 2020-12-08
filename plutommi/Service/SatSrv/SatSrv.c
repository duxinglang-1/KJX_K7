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
 *  SatSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements service functions for SAT feature.
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
#include "MMI_include.h"

#ifndef SATSRV_C
#define SATSRV_C

#include "MMIDataType.h"
#include "stack_config.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_mem_gprot.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"
#include "browser_struct.h"
#include "stack_msgs.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "mmi_rp_srv_sat_def.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_frm_utility_gprot.h"
#include "ProtocolEvents.h"
#include "SatSrvGprot.h"
#include "SatSrv.h"
#include "GSM7BitDefaultAlphabet.h"
#include "app_addr.h"
#include "BootupSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "GCallSrvGprot.h"

#ifdef BROWSER_SUPPORT
#include "wap_adp.h"
#include "browser_struct.h"
#endif /* BROWSER_SUPPORT */

#define SRV_SAT_MAX_TIMER_TOTAL (2 * MMI_SIM_TOTAL)

typedef enum
{
    SRV_SAT_TIMER_IDLE,
    SRV_SAT_TIMER_START,
    SRV_SAT_TIMER_PAUSE,
    SRV_SAT_TIMER_TOTAL
} srv_sat_timer_enum;

typedef struct
{
    mmi_sim_enum sim_id;
    U16 timer_id;
    U16 duration;
    U16 counter;
    srv_sat_timer_enum status;
    srv_sat_callback_func_ptr callback;
    void *user_data;
} srv_sat_timer_struct;

typedef struct
{
    U16 msg_id;
    PsExtFuncPtr hdlr;
}srv_sat_ps_hdlr_table;

/* 
 * Local Variable
 */
static srv_sat_cntx_struct g_srv_sat_cntx[SRV_SAT_TOTAL];
static srv_sat_proactive_sim_struct g_srv_sat_proactive_sim[SRV_SAT_TOTAL];
static srv_sat_timer_struct g_srv_sat_timer[SRV_SAT_MAX_TIMER_TOTAL];
static U8 srv_sat_timer_run;
static U8 srv_sat_me_language[2] = {'e', 'n'};

/* 
 * Local Function
 */


/*****************************************************************************
 * FUNCTION
 *  SATID_2_L4CID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 * RETURNS
 *  module_type
 *****************************************************************************/
module_type SATID_2_L4CID(srv_sat_enum sat_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_frm_sim_to_l4c_mod(mmi_frm_index_to_sim((U32)sat_id));
}


/*****************************************************************************
 * FUNCTION
 *  L4CID_2_SATID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l4c_id      [IN]        
 * RETURNS
 *  srv_sat_enum
 *****************************************************************************/
srv_sat_enum L4CID_2_SATID(module_type l4c_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_sat_enum)mmi_frm_sim_to_index(mmi_frm_l4c_mod_to_sim((module_type) l4c_id));
}


/*****************************************************************************
 * FUNCTION
 *  SATID_2_SIMID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 * RETURNS
 *  mmi_sim_enum
 *****************************************************************************/
mmi_sim_enum SATID_2_SIMID(srv_sat_enum sat_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_frm_index_to_sim((U32)sat_id);
}


/*****************************************************************************
 * FUNCTION
 *  SIMID_2_SATID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  srv_sat_enum
 *****************************************************************************/
srv_sat_enum SIMID_2_SATID(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_sat_enum)mmi_frm_sim_to_index(sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_session_end_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_session_end_event(srv_sat_enum sat_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_session_end_event_struct event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&event, EVT_ID_SRV_SAT_SESSION_END);
    g_srv_sat_cntx[sat_id].cmd_type = SRV_SAT_CMD_NONE;
    g_srv_sat_cntx[sat_id].occurrence = 0;
    event.sim_id = SATID_2_SIMID(sat_id);
    MMI_FRM_CB_EMIT_EVENT(&event);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_proactive_sim_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  cmd_type    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_proactive_sim_event(srv_sat_enum sat_id, srv_sat_cmd_enum cmd_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_proactive_sim_event_struct event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cmd_type == g_srv_sat_cntx[sat_id].cmd_type)
    {
        /* ME continuously receives SEND SMS indication for 5 times */
        if (g_srv_sat_cntx[sat_id].occurrence == 5 && cmd_type == SRV_SAT_CMD_SEND_SMS)
        {
            /* Give MMI a chance to jump out of sending SMS screen */
            srv_sat_send_session_end_event(sat_id);

            /* Reject the message, maybe it won't come any more */
            srv_sat_terminal_response_send_sms_stage2(
                SATID_2_SIMID(sat_id),
                SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
                SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
            return;
        }

        g_srv_sat_cntx[sat_id].occurrence++;
    }
    else
    {
        g_srv_sat_cntx[sat_id].occurrence = 1;
    }
    g_srv_sat_cntx[sat_id].cmd_type = cmd_type;

    /* Start to send proactive sim event */
    g_srv_sat_proactive_sim[sat_id].sim_id = SATID_2_SIMID(sat_id);
    g_srv_sat_proactive_sim[sat_id].cmd_type = cmd_type;
    switch (cmd_type)
    {
        case SRV_SAT_CMD_SETUP_MENU:
            memcpy(
                &g_srv_sat_proactive_sim[sat_id].cmd_data.setup_menu,
                &g_srv_sat_cntx[sat_id].setup_menu,
                sizeof(srv_sat_setup_menu_struct));
            break;

        case SRV_SAT_CMD_SETUP_IDLE_MODE_TEXT:
            memcpy(
                &g_srv_sat_proactive_sim[sat_id].cmd_data.setup_idle_mode_text,
                &g_srv_sat_cntx[sat_id].setup_idle_mode_text,
                sizeof(srv_sat_setup_idle_mode_text_struct));
            break;

        default:
            break;
    }

    /* If bootup not completed, just wait bootup completed and then emit the event */
    if (!srv_bootup_is_completed() && cmd_type != SRV_SAT_CMD_SETUP_MENU)
    {
        g_srv_sat_cntx[sat_id].pending = 1;
        return;
    }

    MMI_FRM_INIT_EVENT(&event, EVT_ID_SRV_SAT_PROACTIVE_SIM);
    event.proactive_sim = &g_srv_sat_proactive_sim[sat_id];
    MMI_FRM_CB_EMIT_EVENT(&event);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_setup_idle_display_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  present     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_send_setup_idle_display_event(srv_sat_enum sat_id, MMI_BOOL present)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_setup_idle_display_event_struct event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&event, EVT_ID_SRV_SAT_SETUP_IDLE_DISPLAY);
    event.sim_id = SATID_2_SIMID(sat_id);
    event.present = present;
    MMI_FRM_CB_EMIT_EVENT(&event);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_setup_menu_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  present     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_setup_menu_event(srv_sat_enum sat_id, MMI_BOOL present)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_setup_menu_event_struct event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&event, EVT_ID_SRV_SAT_SETUP_MENU);
    event.sim_id = SATID_2_SIMID(sat_id);
    event.present = present;
    MMI_FRM_CB_EMIT_EVENT(&event);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_bootup_complete_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt:        [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_sat_bootup_complete_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_proactive_sim_event_struct event;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_SAT_TOTAL; i++)
    {
        if (g_srv_sat_cntx[i].pending && g_srv_sat_proactive_sim[i].cmd_type != SRV_SAT_CMD_NONE)
        {
            MMI_FRM_INIT_EVENT(&event, EVT_ID_SRV_SAT_PROACTIVE_SIM);
            event.proactive_sim = &g_srv_sat_proactive_sim[i];
            MMI_FRM_CB_EMIT_EVENT(&event);
        }
        g_srv_sat_cntx[i].pending = 0;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_sim_unavailable_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt:        [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_sat_sim_unavailable_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_unavailable_evt_struct *sim_ctrl_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ctrl_evt = (srv_sim_ctrl_unavailable_evt_struct*) evt;

    if (srv_sim_ctrl_get_unavailable_cause(sim_ctrl_evt->sim) == SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE ||
        srv_sim_ctrl_get_unavailable_cause(sim_ctrl_evt->sim) == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED
    #ifdef __SIM_RECOVERY_ENHANCEMENT__
        || srv_sim_ctrl_get_unavailable_cause(sim_ctrl_evt->sim) == SRV_SIM_CTRL_UA_CAUSE_RECOVERY
    #endif
        )
    {
        srv_sat_enum sat_id = SIMID_2_SATID(sim_ctrl_evt->sim);

        if (g_srv_sat_cntx[sat_id].setup_menu.present)
        {
            g_srv_sat_cntx[sat_id].setup_menu.present = MMI_FALSE;
            srv_sat_send_setup_menu_event(sat_id, g_srv_sat_cntx[sat_id].setup_menu.present);
        }
        if (g_srv_sat_cntx[sat_id].setup_idle_mode_text.present)
        {
            g_srv_sat_cntx[sat_id].setup_idle_mode_text.present = MMI_FALSE;
            srv_sat_send_setup_idle_display_event(sat_id, g_srv_sat_cntx[sat_id].setup_idle_mode_text.present);
        }
        srv_sat_send_session_end_event(sat_id);
    }

    return MMI_RET_OK;
}


#ifndef __SAT_DISABLE_ICON_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_display_text_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  result      [IN]        
 *  icon_data   [IN]        
 *  user_data   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_display_text_hdlr(srv_sat_enum sat_id, MMI_BOOL result, U8 *icon_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_display_text_struct *display_text = &g_srv_sat_proactive_sim[sat_id].cmd_data.display_text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        display_text->icon.data = icon_data;
        if (display_text->icon.attr == SRV_SAT_ICON_SELF_EX)
        {
            srv_sat_do_free(display_text->text_string);
            display_text->text_string = NULL;
        }
    }
    else
    {
        display_text->icon.available = MMI_FALSE;
    }

    srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_DISPLAY_TEXT);
}
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_display_text_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_display_text_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_display_text_struct *display_text = &g_srv_sat_proactive_sim[sat_id].cmd_data.display_text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sat_do_display_text(sat_id, &g_srv_sat_cntx[sat_id], display_text, info))
    {
    #ifndef __SAT_DISABLE_ICON_SUPPORT__
        if (display_text->icon.available)
        {
            srv_sat_do_icon(sat_id, display_text->icon.id, srv_sat_display_text_hdlr, NULL);
            return;
        }
    #endif /* __SAT_DISABLE_ICON_SUPPORT__ */

        srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_DISPLAY_TEXT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_display_text_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_display_text_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_display_text_struct *display_text = &g_srv_sat_proactive_sim[sat_id].cmd_data.display_text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_do_free(display_text->text_string);
    display_text->text_string = NULL;
#ifndef __SAT_DISABLE_ICON_SUPPORT__	
    srv_sat_do_free(display_text->icon.data);
    display_text->icon.data = NULL;
#endif
    if (!display_text->immediate_res)
    {
        g_srv_sat_proactive_sim[sat_id].cmd_type = SRV_SAT_CMD_NONE;
    }
}


#ifndef __SAT_DISABLE_ICON_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_inkey_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  result      [IN]        
 *  icon_data   [IN]        
 *  user_data   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_get_inkey_hdlr(srv_sat_enum sat_id, MMI_BOOL result, U8 *icon_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_get_inkey_struct *get_inkey = &g_srv_sat_proactive_sim[sat_id].cmd_data.get_inkey;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        get_inkey->icon.data = icon_data;
        if (get_inkey->icon.attr == SRV_SAT_ICON_SELF_EX)
        {
            srv_sat_do_free(get_inkey->text_string);
            get_inkey->text_string = NULL;
        }
    }
    else
    {
        get_inkey->icon.available = MMI_FALSE;
    }

    srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_GET_INKEY);
}
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_inkey_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_get_inkey_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_get_inkey_struct *get_inkey = &g_srv_sat_proactive_sim[sat_id].cmd_data.get_inkey;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sat_do_get_inkey(sat_id, &g_srv_sat_cntx[sat_id], get_inkey, info))
    {
    #ifndef __SAT_DISABLE_ICON_SUPPORT__
        if (get_inkey->icon.available)
        {
            srv_sat_do_icon(sat_id, get_inkey->icon.id, srv_sat_get_inkey_hdlr, NULL);
            return;
        }
    #endif /* __SAT_DISABLE_ICON_SUPPORT__ */

        srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_GET_INKEY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_inkey_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_get_inkey_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_get_inkey_struct *get_inkey = &g_srv_sat_proactive_sim[sat_id].cmd_data.get_inkey;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_do_free(get_inkey->text_string);
    get_inkey->text_string = NULL;
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    srv_sat_do_free(get_inkey->icon.data);
    get_inkey->icon.data = NULL;
#endif

    g_srv_sat_proactive_sim[sat_id].cmd_type = SRV_SAT_CMD_NONE;
}


#ifndef __SAT_DISABLE_ICON_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_input_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  result      [IN]        
 *  icon_data   [IN]        
 *  user_data   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_get_input_hdlr(srv_sat_enum sat_id, MMI_BOOL result, U8 *icon_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_get_input_struct *get_input = &g_srv_sat_proactive_sim[sat_id].cmd_data.get_input;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        get_input->icon.data = icon_data;
        if (get_input->icon.attr == SRV_SAT_ICON_SELF_EX)
        {
            srv_sat_do_free(get_input->text_string);
            get_input->text_string = NULL;
        }
    }
    else
    {
        get_input->icon.available = MMI_FALSE;
    }

    srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_GET_INPUT);
}
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_input_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_get_input_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_get_input_struct *get_input = &g_srv_sat_proactive_sim[sat_id].cmd_data.get_input;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sat_do_get_input(sat_id, &g_srv_sat_cntx[sat_id], get_input, info))
    {
    #ifndef __SAT_DISABLE_ICON_SUPPORT__
        if (get_input->icon.available)
        {
            srv_sat_do_icon(sat_id, get_input->icon.id, srv_sat_get_input_hdlr, NULL);
            return;
        }
    #endif /* __SAT_DISABLE_ICON_SUPPORT__ */

        srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_GET_INPUT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_input_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_get_input_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_get_input_struct *get_input = &g_srv_sat_proactive_sim[sat_id].cmd_data.get_input;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_do_free(get_input->text_string);
    get_input->text_string = NULL;
    srv_sat_do_free(get_input->default_text);
    get_input->default_text = NULL;
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    srv_sat_do_free(get_input->icon.data);
    get_input->icon.data = NULL;
#endif
    g_srv_sat_proactive_sim[sat_id].cmd_type = SRV_SAT_CMD_NONE;
}


#ifndef __SAT_DISABLE_ICON_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_play_tone_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  result      [IN]        
 *  icon_data   [IN]        
 *  user_data   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_play_tone_hdlr(srv_sat_enum sat_id, MMI_BOOL result, U8 *icon_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_play_tone_struct *play_tone = &g_srv_sat_proactive_sim[sat_id].cmd_data.play_tone;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        play_tone->icon.data = icon_data;
        if (play_tone->icon.attr == SRV_SAT_ICON_SELF_EX)
        {
            srv_sat_do_free(play_tone->alpha_id);
            play_tone->alpha_id = NULL;
        }
    }
    else
    {
        play_tone->icon.available = MMI_FALSE;
    }

    srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_PLAY_TONE);
}
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_play_tone_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_play_tone_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_play_tone_struct *play_tone = &g_srv_sat_proactive_sim[sat_id].cmd_data.play_tone;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sat_do_play_tone(sat_id, &g_srv_sat_cntx[sat_id], play_tone, info))
    {
    #ifndef __SAT_DISABLE_ICON_SUPPORT__
        if (play_tone->icon.available)
        {
            srv_sat_do_icon(sat_id, play_tone->icon.id, srv_sat_play_tone_hdlr, NULL);
            return;
        }
    #endif /* __SAT_DISABLE_ICON_SUPPORT__ */

        srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_PLAY_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_play_tone_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_play_tone_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_play_tone_struct *play_tone = &g_srv_sat_proactive_sim[sat_id].cmd_data.play_tone;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_do_free(play_tone->alpha_id);
    play_tone->alpha_id = NULL;
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    srv_sat_do_free(play_tone->icon.data);
    play_tone->icon.data = NULL;
#endif
    g_srv_sat_proactive_sim[sat_id].cmd_type = SRV_SAT_CMD_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_refresh_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_refresh_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_refresh_struct *refresh = &g_srv_sat_proactive_sim[sat_id].cmd_data.refresh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sat_do_refresh(sat_id, &g_srv_sat_cntx[sat_id], refresh, info))
    {
        srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_REFRESH);

    #ifdef __SIM_RESET_BY_SIM__
        if (refresh->refresh_type == SRV_SAT_REFRESH_RESET)
        {
            if (g_srv_sat_cntx[sat_id].setup_menu.present)
            {
                g_srv_sat_cntx[sat_id].setup_menu.present = MMI_FALSE;
                srv_sat_send_setup_menu_event(sat_id, g_srv_sat_cntx[sat_id].setup_menu.present);
            }
            srv_sat_send_session_end_event(sat_id);
        }
    #endif /* __SIM_RESET_BY_SIM__*/
    }
}


#ifndef __SAT_DISABLE_ICON_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_menu_item_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  from        [IN]        
 *  to          [IN]        
 *  item_list   [IN]        
 *  icon_id     [IN]        
 *  icon_data   [IN]        
 *  callback    [IN]        
 *  main_menu   [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL srv_sat_menu_item_hdlr(
                    srv_sat_enum sat_id,
                    S32 from,
                    S32 to,
                    srv_sat_item_struct *item_list,
                    U8 icon_id,
                    U8 *icon_data,
                    srv_sat_do_icon_callback_type callback,
                    MMI_BOOL main_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = from; i <= to; i++)
    {
        if (icon_id == item_list[i].icon.id)
        {
            item_list[i].icon.data = icon_data;
            if (item_list[i].icon.attr == SRV_SAT_ICON_SELF_EX)
            {
                if (!main_menu)
                {
                    srv_sat_do_free(item_list[i].alpha_id);
                }
                item_list[i].alpha_id = NULL;
            }
            item_list[i].icon.copy_only = MMI_TRUE;
        }
        else if (j == -1)
        {
            j = i;
        }
    }

    if (j != -1)
    {
        srv_sat_do_icon(sat_id, item_list[j].icon.id, callback, (void*) (j + 1));
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_setup_menu_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  result      [IN]        
 *  icon_data   [IN]        
 *  user_data   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_setup_menu_hdlr(srv_sat_enum sat_id, MMI_BOOL result, U8 *icon_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_setup_menu_struct *setup_menu = &g_srv_sat_cntx[sat_id].setup_menu;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result && (S32) user_data == 0)
    {
        setup_menu->icon.data = icon_data;
        if (setup_menu->icon.attr == SRV_SAT_ICON_SELF_EX)
        {
            setup_menu->alpha_id = NULL;
        }

        if (setup_menu->item_list[0].icon.available)
        {
            if (srv_sat_menu_item_hdlr(
                    sat_id,
                    0,
                    setup_menu->num_of_item - 1,
                    setup_menu->item_list,
                    setup_menu->icon.id,
                    setup_menu->icon.data,
                    srv_sat_setup_menu_hdlr,
                    MMI_TRUE))
            {
                return;
            }
        }
    }
    else if (result && (S32) user_data >= 1 && (S32) user_data <= setup_menu->num_of_item)
    {
        i = (S32) user_data - 1;
        setup_menu->item_list[i].icon.data = icon_data;
        if (setup_menu->item_list[i].icon.attr == SRV_SAT_ICON_SELF_EX)
        {
            setup_menu->item_list[i].alpha_id = NULL;
        }

        if (setup_menu->item_list[0].icon.available)
        {
            if (srv_sat_menu_item_hdlr(
                    sat_id,
                    i + 1,
                    setup_menu->num_of_item - 1,
                    setup_menu->item_list,
                    setup_menu->item_list[i].icon.id,
                    setup_menu->item_list[i].icon.data,
                    srv_sat_setup_menu_hdlr,
                    MMI_TRUE))
            {
                return;
            }
        }
    }
    else
    {
        setup_menu->icon.available = MMI_FALSE;
    }

    srv_sat_terminal_response_setup_menu(
        SATID_2_SIMID(sat_id),
        SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY);
    srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_SETUP_MENU);
    srv_sat_send_setup_menu_event(sat_id, setup_menu->present);
}
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_setup_menu_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_setup_menu_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_setup_menu_struct *setup_menu = &g_srv_sat_cntx[sat_id].setup_menu;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sat_do_setup_menu(sat_id, &g_srv_sat_cntx[sat_id], setup_menu, info))
    {
    #ifndef __SAT_DISABLE_ICON_SUPPORT__
        if (setup_menu->icon.available)
        {
            srv_sat_do_icon(sat_id, setup_menu->icon.id, srv_sat_setup_menu_hdlr, (void*) 0);
            return;
        }

        if (setup_menu->item_list[0].icon.available)
        {
            srv_sat_do_icon(sat_id, setup_menu->item_list[0].icon.id, srv_sat_setup_menu_hdlr, (void*) 1);
            return;
        }
    #endif /* __SAT_DISABLE_ICON_SUPPORT__ */
    }

    srv_sat_terminal_response_setup_menu(
        SATID_2_SIMID(sat_id),
        SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY);
    srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_SETUP_MENU);
    srv_sat_send_setup_menu_event(sat_id, setup_menu->present);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_setup_menu_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_setup_menu_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


#ifndef __SAT_DISABLE_ICON_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_select_item_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  result      [IN]        
 *  icon_data   [IN]        
 *  user_data   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_select_item_hdlr(srv_sat_enum sat_id, MMI_BOOL result, U8 *icon_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_select_item_struct *select_item = &g_srv_sat_proactive_sim[sat_id].cmd_data.select_item;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result && (S32) user_data == 0)
    {
        select_item->icon.data = icon_data;
        if (select_item->icon.attr == SRV_SAT_ICON_SELF_EX)
        {
            srv_sat_do_free(select_item->alpha_id);
            select_item->alpha_id = NULL;
        }

        if (select_item->item_list[0].icon.available)
        {
            if (srv_sat_menu_item_hdlr(
                    sat_id,
                    0,
                    select_item->num_of_item - 1,
                    select_item->item_list,
                    select_item->icon.id,
                    select_item->icon.data,
                    srv_sat_select_item_hdlr,
                    MMI_FALSE))
            {
                return;
            }
        }
    }
    else if (result && (S32) user_data >= 1 && (S32) user_data <= select_item->num_of_item)
    {
        i = (S32) user_data - 1;
        select_item->item_list[i].icon.data = icon_data;
        if (select_item->item_list[i].icon.attr == SRV_SAT_ICON_SELF_EX)
        {
            srv_sat_do_free(select_item->item_list[i].alpha_id);
            select_item->item_list[i].alpha_id = NULL;
        }

        if (select_item->item_list[0].icon.available)
        {
            if (srv_sat_menu_item_hdlr(
                    sat_id,
                    i + 1,
                    select_item->num_of_item - 1,
                    select_item->item_list,
                    select_item->item_list[i].icon.id,
                    select_item->item_list[i].icon.data,
                    srv_sat_select_item_hdlr,
                    MMI_FALSE))
            {
                return;
            }
        }
    }
    else
    {
        select_item->icon.available = MMI_FALSE;
    }

    srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_SELECT_ITEM);
}
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_select_item_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_select_item_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_select_item_struct *select_item = &g_srv_sat_proactive_sim[sat_id].cmd_data.select_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_sat_cntx[sat_id].sent = 0;
    if (srv_sat_do_select_item(sat_id, &g_srv_sat_cntx[sat_id], select_item, info))
    {
    #ifndef __SAT_DISABLE_ICON_SUPPORT__
        if (select_item->icon.available)
        {
            srv_sat_do_icon(sat_id, select_item->icon.id, srv_sat_select_item_hdlr, (void*) 0);
            return;
        }

        if (select_item->item_list[0].icon.available)
        {
            srv_sat_do_icon(sat_id, select_item->item_list[0].icon.id, srv_sat_select_item_hdlr, (void*) 1);
            return;
        }
    #endif /* __SAT_DISABLE_ICON_SUPPORT__ */

        srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_SELECT_ITEM);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_select_item_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_select_item_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_select_item_struct *select_item = &g_srv_sat_proactive_sim[sat_id].cmd_data.select_item;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_do_free(select_item->alpha_id);
    select_item->alpha_id = NULL;
    for (i = 0; i < select_item->num_of_item; i++)
    {
        srv_sat_do_free(select_item->item_list[i].alpha_id);
        select_item->item_list[i].alpha_id = NULL;
#ifndef __SAT_DISABLE_ICON_SUPPORT__
        if (!select_item->item_list[i].icon.copy_only)
        {
            srv_sat_do_free(select_item->item_list[i].icon.data);
        }
        select_item->item_list[i].icon.data = NULL;
#endif
    }
    srv_sat_do_free(select_item->item_list);
    select_item->item_list = NULL;
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    srv_sat_do_free(select_item->icon.data);
    select_item->icon.data = NULL;
#endif
    g_srv_sat_proactive_sim[sat_id].cmd_type = SRV_SAT_CMD_NONE;
}


#ifndef __SAT_DISABLE_ICON_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_sms_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  result      [IN]        
 *  icon_data   [IN]        
 *  user_data   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_sms_hdlr(srv_sat_enum sat_id, MMI_BOOL result, U8 *icon_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_send_sms_struct *send_sms = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_sms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        send_sms->icon.data = icon_data;
        if (send_sms->icon.attr == SRV_SAT_ICON_SELF_EX)
        {
            srv_sat_do_free(send_sms->alpha_id);
            send_sms->alpha_id = NULL;
        }
    }
    else
    {
        send_sms->icon.available = MMI_FALSE;
    }

    srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_SEND_SMS);
}
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_sms_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_sms_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_send_sms_struct *send_sms = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_sms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sat_do_send_sms(sat_id, &g_srv_sat_cntx[sat_id], send_sms, info))
    {
    #ifndef __SAT_DISABLE_ICON_SUPPORT__
        if (send_sms->icon.available)
        {
            srv_sat_do_icon(sat_id, send_sms->icon.id, srv_sat_send_sms_hdlr, NULL);
            return;
        }
    #endif /* __SAT_DISABLE_ICON_SUPPORT__ */

        srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_SEND_SMS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_sms_stage1_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_sms_stage1_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_sms_stage1_rsp_struct *sim_rsp;
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_rsp = (mmi_sat_send_sms_stage1_rsp_struct*) info;
    srv_sat_terminal_response_send_sms_stage2(
        SATID_2_SIMID(sat_id),
        (srv_sat_terminal_res_enum) sim_rsp->res,
        (srv_sat_additional_res_enum) sim_rsp->cause);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_sms_stage2_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_sms_stage2_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_send_sms_struct *send_sms = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_sms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_do_free(send_sms->alpha_id);
    send_sms->alpha_id = NULL;
    srv_sat_do_free(send_sms->addr);
    send_sms->addr = NULL;
    srv_sat_do_free(send_sms->tpdu);
    send_sms->tpdu = NULL;
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    srv_sat_do_free(send_sms->icon.data);
    send_sms->icon.data = NULL;
#endif
    g_srv_sat_proactive_sim[sat_id].cmd_type = SRV_SAT_CMD_NONE;
}


#ifndef __SAT_DISABLE_ICON_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_ss_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  result      [IN]        
 *  icon_data   [IN]        
 *  user_data   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_ss_hdlr(srv_sat_enum sat_id, MMI_BOOL result, U8 *icon_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_send_ss_struct *send_ss = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_ss;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        send_ss->icon.data = icon_data;
        if (send_ss->icon.attr == SRV_SAT_ICON_SELF_EX)
        {
            srv_sat_do_free(send_ss->alpha_id);
            send_ss->alpha_id = NULL;
        }
    }
    else
    {
        send_ss->icon.available = MMI_FALSE;
    }

    srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_SEND_SS);
}
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_ss_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_ss_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_send_ss_struct *send_ss = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_ss;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sat_do_send_ss(sat_id, &g_srv_sat_cntx[sat_id], send_ss, info))
    {
    #ifndef __SAT_DISABLE_ICON_SUPPORT__
        if (send_ss->icon.available)
        {
            srv_sat_do_icon(sat_id, send_ss->icon.id, srv_sat_send_ss_hdlr, NULL);
            return;
        }
    #endif /* __SAT_DISABLE_ICON_SUPPORT__ */

        srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_SEND_SS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_ss_stage1_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_ss_stage1_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_ss_stage1_rsp_struct *sim_rsp;
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_send_ss_struct *send_ss = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_ss;
    U16 gsm_len, text_len;
    U8 *gsm_string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_rsp = (mmi_sat_send_ss_stage1_rsp_struct*) info;

    if (send_ss->alpha_id[0] && sim_rsp->res == SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY)
    {
        if (sim_rsp->length > 8 && sim_rsp->addition_info[0] == 0x3B)
        {
        	int flag = sim_rsp->addition_info[2] == 0x81 ? 1 : 0;
            send_ss->length = sim_rsp->length;
            send_ss->additional_info = (U8*) OslMalloc(sim_rsp->length * sizeof(U8));
            memcpy(send_ss->additional_info, sim_rsp->addition_info, sim_rsp->length);

			
			gsm_len = applib_addr_gsm7_strlen(sim_rsp->addition_info + 7 + flag, (U16) (sim_rsp->length - 7 - flag));
			gsm_string = (U8*) get_ctrl_buffer_ext((gsm_len + 1) * sizeof(U8), 0, 0);
                /* data is given after data_length */
			applib_addr_gsm7_2_string(sim_rsp->addition_info + 8 + flag, gsm_string, gsm_len + 1);

            send_ss->text_string =
                (WCHAR*) CovertStringForPlatform(gsm_string, gsm_len, MMI_8BIT_DCS, &text_len);
            OslMfree(gsm_string);

            srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_SEND_SS_RETURN_RESULT);
            return;
        }
    }

    srv_sat_terminal_response_send_ss_stage2(
        SATID_2_SIMID(sat_id),
        (srv_sat_terminal_res_enum) sim_rsp->res,
        sim_rsp->length,
        sim_rsp->addition_info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_ss_stage2_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_ss_stage2_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_send_ss_struct *send_ss = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_ss;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_do_free(send_ss->alpha_id);
    send_ss->alpha_id = NULL;
    srv_sat_do_free(send_ss->ss_string);
    send_ss->ss_string = NULL;
    srv_sat_do_free(send_ss->additional_info);
    send_ss->additional_info = NULL;
    srv_sat_do_free(send_ss->text_string);
    send_ss->text_string = NULL;
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    srv_sat_do_free(send_ss->icon.data);
    send_ss->icon.data = NULL;
#endif
    g_srv_sat_proactive_sim[sat_id].cmd_type = SRV_SAT_CMD_NONE;
}


#ifndef __SAT_DISABLE_ICON_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_ussd_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  result      [IN]        
 *  icon_data   [IN]        
 *  user_data   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_ussd_hdlr(srv_sat_enum sat_id, MMI_BOOL result, U8 *icon_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_send_ussd_struct *send_ussd = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_ussd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        send_ussd->icon.data = icon_data;
        if (send_ussd->icon.attr == SRV_SAT_ICON_SELF_EX)
        {
            srv_sat_do_free(send_ussd->alpha_id);
            send_ussd->alpha_id = NULL;
        }
    }
    else
    {
        send_ussd->icon.available = MMI_FALSE;
    }

    srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_SEND_USSD);
}
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_ussd_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_ussd_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_send_ussd_struct *send_ussd = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_ussd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sat_do_send_ussd(sat_id, &g_srv_sat_cntx[sat_id], send_ussd, info))
    {
    #ifndef __SAT_DISABLE_ICON_SUPPORT__
        if (send_ussd->icon.available)
        {
            srv_sat_do_icon(sat_id, send_ussd->icon.id, srv_sat_send_ussd_hdlr, NULL);
            return;
        }
    #endif /* __SAT_DISABLE_ICON_SUPPORT__ */

        srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_SEND_USSD);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_ussd_stage1_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_ussd_stage1_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_ussd_stage1_rsp_struct *sim_rsp;
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_send_ussd_struct *send_ussd = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_ussd;
    U16 gsm_len, text_len;
    U8 *gsm_string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_rsp = (mmi_sat_send_ussd_stage1_rsp_struct*) info;

    if (send_ussd->alpha_id[0] && sim_rsp->res == SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY)
    {
        if (sim_rsp->length > 1)
        {
            send_ussd->length = sim_rsp->length;
            send_ussd->additional_info = (U8*) OslMalloc(sim_rsp->length * sizeof(U8));
            memcpy(send_ussd->additional_info, sim_rsp->addition_info, sim_rsp->length);

            if (sim_rsp->length > 3 && sim_rsp->addition_info[0] == 0x11)
            {
                send_ussd->additional_info[0] = MMI_UCS2_DCS;
                send_ussd->text_string =
                    (WCHAR*) CovertStringForPlatform(sim_rsp->addition_info + 3, (U16) (sim_rsp->length - 3), MMI_UCS2_DCS, &text_len);
            }
            else if (sim_rsp->addition_info[0] == 0x00)
            {
                gsm_len = applib_addr_gsm7_strlen(sim_rsp->addition_info + 1, (U16) (sim_rsp->length - 1));
                gsm_string = (U8*) OslMalloc((gsm_len + 1) * sizeof(U8));
                applib_addr_gsm7_2_string(sim_rsp->addition_info + 1, gsm_string, gsm_len + 1);
                send_ussd->text_string =
                    (WCHAR*) CovertStringForPlatform(gsm_string, gsm_len, MMI_8BIT_DCS, &text_len);
                OslMfree(gsm_string);
            }
            else
            {
                send_ussd->text_string =
                    (WCHAR*) CovertStringForPlatform(sim_rsp->addition_info + 1, (U16) (sim_rsp->length - 1), sim_rsp->addition_info[0], &text_len);
            }

            srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_SEND_USSD_RETURN_RESULT);
            return;
        }
    }

    srv_sat_terminal_response_send_ussd_stage2(
        SATID_2_SIMID(sat_id),
        (srv_sat_terminal_res_enum) sim_rsp->res,
        sim_rsp->length,
        sim_rsp->addition_info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_ussd_stage2_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_ussd_stage2_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_send_ussd_struct *send_ussd = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_ussd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_do_free(send_ussd->alpha_id);
    send_ussd->alpha_id = NULL;
    srv_sat_do_free(send_ussd->ussd_string);
    send_ussd->ussd_string = NULL;
    srv_sat_do_free(send_ussd->additional_info);
    send_ussd->additional_info = NULL;
    srv_sat_do_free(send_ussd->text_string);
    send_ussd->text_string = NULL;
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    srv_sat_do_free(send_ussd->icon.data);
    send_ussd->icon.data = NULL;
#endif
    g_srv_sat_proactive_sim[sat_id].cmd_type = SRV_SAT_CMD_NONE;
}


#ifndef __SAT_DISABLE_ICON_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_setup_call_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  result      [IN]        
 *  icon_data   [IN]        
 *  user_data   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_setup_call_hdlr(srv_sat_enum sat_id, MMI_BOOL result, U8 *icon_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_setup_call_struct *setup_call = &g_srv_sat_proactive_sim[sat_id].cmd_data.setup_call;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result && (S32) user_data == 0)
    {
        setup_call->icon1.data = icon_data;
        if (setup_call->icon1.attr == SRV_SAT_ICON_SELF_EX)
        {
            srv_sat_do_free(setup_call->alpha_id1);
            setup_call->alpha_id1 = NULL;
        }

        if (setup_call->icon2.available)
        {
            if (setup_call->icon1.id == setup_call->icon2.id)
            {
                setup_call->icon2.data = icon_data;
                if (setup_call->icon2.attr == SRV_SAT_ICON_SELF_EX)
                {
                    srv_sat_do_free(setup_call->alpha_id2);
                    setup_call->alpha_id2 = NULL;
                }
                setup_call->icon2.copy_only = MMI_TRUE;
            }
            else
            {
                srv_sat_do_icon(sat_id, setup_call->icon2.id, srv_sat_setup_call_hdlr, (void*) 2);
                return;
            }
        }
    }
    else if (result && (S32) user_data == 1)
    {
        setup_call->icon2.data = icon_data;
        if (setup_call->icon2.attr == SRV_SAT_ICON_SELF_EX)
        {
            srv_sat_do_free(setup_call->alpha_id2);
            setup_call->alpha_id2 = NULL;
        }
    }
    else
    {
        setup_call->icon1.available = MMI_FALSE;
    }

    srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_SETUP_CALL);
}
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_setup_call_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_setup_call_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_setup_call_struct *setup_call = &g_srv_sat_proactive_sim[sat_id].cmd_data.setup_call;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sat_do_setup_call(sat_id, &g_srv_sat_cntx[sat_id], setup_call, info))
    {
    #ifndef __SAT_DISABLE_ICON_SUPPORT__
        if (setup_call->icon1.available)
        {
            srv_sat_do_icon(sat_id, setup_call->icon1.id, srv_sat_setup_call_hdlr, (void*) 0);
            return;
        }

        if (setup_call->icon2.available)
        {
            srv_sat_do_icon(sat_id, setup_call->icon2.id, srv_sat_setup_call_hdlr, (void*) 1);
            return;
        }
    #endif /* __SAT_DISABLE_ICON_SUPPORT__ */

        srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_SETUP_CALL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_setup_call_stage1_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_setup_call_stage1_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_call_setup_stage1_rsp_struct *sim_rsp;
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_sat_cntx[sat_id].sent == 0)
    {
        sim_rsp = (mmi_sat_call_setup_stage1_rsp_struct*) info;
        srv_sat_terminal_response_setup_call_stage2(
            SATID_2_SIMID(sat_id),
            (srv_sat_terminal_res_enum) sim_rsp->terminal_res,
            (srv_sat_additional_res_enum) sim_rsp->additional_res);
        if ((sim_rsp->terminal_res != SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY &&
             sim_rsp->terminal_res != SRV_SAT_TERMINAL_RES_CMD_PERFORMED_WITH_PARTIAL_COMPREHENSION &&
             sim_rsp->terminal_res != SRV_SAT_TERMINAL_RES_CMD_PERFORMED_WITH_MISSING_INFO) ||
            sim_rsp->result.flag == L4C_ERROR)
        {
            srv_gcall_sat_notify_mo_fail(sim_rsp->result.cause);            
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_setup_call_stage2_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_setup_call_stage2_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_setup_call_struct *setup_call = &g_srv_sat_proactive_sim[sat_id].cmd_data.setup_call;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_do_free(setup_call->alpha_id1);
    setup_call->alpha_id1 = NULL;
    srv_sat_do_free(setup_call->number);
    setup_call->number = NULL;
    srv_sat_do_free(setup_call->addr);
    setup_call->addr = NULL;
    srv_sat_do_free(setup_call->ccp);
    setup_call->ccp = NULL;
    srv_sat_do_free(setup_call->subadrr);
    setup_call->subadrr = NULL;
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    srv_sat_do_free(setup_call->icon1.data);
    setup_call->icon1.data = NULL;
#endif
    srv_sat_do_free(setup_call->alpha_id2);
    setup_call->alpha_id2 = NULL;
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    if (!setup_call->icon2.copy_only)
    {
        srv_sat_do_free(setup_call->icon2.data);
    }
    setup_call->icon2.data = NULL;
#endif
    g_srv_sat_proactive_sim[sat_id].cmd_type = SRV_SAT_CMD_NONE;
}


#ifndef __SAT_LOWCOST_UI_DISABLE__

/*****************************************************************************
 * FUNCTION
 *  srv_sat_provide_language_info_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_provide_language_info_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_terminal_response_provide_language_info(SATID_2_SIMID(sat_id), srv_sat_me_language);
}

#endif /* __SAT_LOWCOST_UI_DISABLE__ */


#ifndef __SAT_DISABLE_ICON_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_setup_idle_mode_text_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  result      [IN]        
 *  icon_data   [IN]        
 *  user_data   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_setup_idle_mode_text_hdlr(srv_sat_enum sat_id, MMI_BOOL result, U8 *icon_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_setup_idle_mode_text_struct *setup_idle_mode_text = &g_srv_sat_cntx[sat_id].setup_idle_mode_text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        setup_idle_mode_text->icon.data = icon_data;
        if (setup_idle_mode_text->icon.attr == SRV_SAT_ICON_SELF_EX)
        {
            srv_sat_do_free(setup_idle_mode_text->text_string);
            setup_idle_mode_text->text_string = NULL;
        }
    }
    else
    {
        setup_idle_mode_text->icon.available = MMI_FALSE;
    }

    srv_sat_terminal_response_setup_idle_mode_text(
        SATID_2_SIMID(sat_id),
        SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY);
    srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_SETUP_IDLE_MODE_TEXT);
    srv_sat_send_setup_idle_display_event(sat_id, setup_idle_mode_text->present);
}
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_setup_idle_mode_text_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_setup_idle_mode_text_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_setup_idle_mode_text_struct *setup_idle_mode_text = &g_srv_sat_cntx[sat_id].setup_idle_mode_text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sat_do_setup_idle_mode_text(sat_id, &g_srv_sat_cntx[sat_id], setup_idle_mode_text, info))
    {
    #ifndef __SAT_DISABLE_ICON_SUPPORT__
        if (setup_idle_mode_text->icon.available)
        {
            srv_sat_do_icon(sat_id, setup_idle_mode_text->icon.id, srv_sat_setup_idle_mode_text_hdlr, NULL);
            return;
        }
    #endif /* __SAT_DISABLE_ICON_SUPPORT__ */

        srv_sat_terminal_response_setup_idle_mode_text(
            SATID_2_SIMID(sat_id),
            SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY);
        srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_SETUP_IDLE_MODE_TEXT);
        srv_sat_send_setup_idle_display_event(sat_id, setup_idle_mode_text->present);
    }
}


#ifndef __SAT_DISABLE_ICON_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_run_at_command_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  result      [IN]        
 *  icon_data   [IN]        
 *  user_data   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_run_at_command_hdlr(srv_sat_enum sat_id, MMI_BOOL result, U8 *icon_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_run_at_command_struct *run_at_command = &g_srv_sat_proactive_sim[sat_id].cmd_data.run_at_command;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        run_at_command->icon.data = icon_data;
        if (run_at_command->icon.attr == SRV_SAT_ICON_SELF_EX)
        {
            srv_sat_do_free(run_at_command->alpha_id);
            run_at_command->alpha_id = NULL;
        }
    }
    else
    {
        run_at_command->icon.available = MMI_FALSE;
    }

    srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_RUN_AT_COMMAND);
}
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_run_at_command_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_run_at_command_ind(void *info, int mod_src)
{
#ifdef __SATCB__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_run_at_command_struct *run_at_command = &g_srv_sat_proactive_sim[sat_id].cmd_data.run_at_command;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sat_do_run_at_command(sat_id, &g_srv_sat_cntx[sat_id], run_at_command, info))
    {
    #ifndef __SAT_DISABLE_ICON_SUPPORT__
        if (run_at_command->icon.available)
        {
            srv_sat_do_icon(sat_id, run_at_command->icon.id, srv_sat_run_at_command_hdlr, NULL);
            return;
        }
    #endif /* __SAT_DISABLE_ICON_SUPPORT__ */

        srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_RUN_AT_COMMAND);
    }
#endif
}


#ifndef __SAT_DISABLE_ICON_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_dtmf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  result      [IN]        
 *  icon_data   [IN]        
 *  user_data   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_dtmf_hdlr(srv_sat_enum sat_id, MMI_BOOL result, U8 *icon_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_send_dtmf_struct *send_dtmf = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_dtmf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        send_dtmf->icon.data = icon_data;
        if (send_dtmf->icon.attr == SRV_SAT_ICON_SELF_EX)
        {
            srv_sat_do_free(send_dtmf->alpha_id);
            send_dtmf->alpha_id = NULL;
        }
    }
    else
    {
        send_dtmf->icon.available = MMI_FALSE;
    }

    srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_SEND_DTMF);
}
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_dtmf_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_dtmf_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_send_dtmf_struct *send_dtmf = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_dtmf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sat_do_send_dtmf(sat_id, &g_srv_sat_cntx[sat_id], send_dtmf, info))
    {
    #ifndef __SAT_DISABLE_ICON_SUPPORT__
        if (send_dtmf->icon.available)
        {
            srv_sat_do_icon(sat_id, send_dtmf->icon.id, srv_sat_send_dtmf_hdlr, NULL);
            return;
        }
    #endif /* __SAT_DISABLE_ICON_SUPPORT__ */

        srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_SEND_DTMF);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_dtmf_stage1_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_dtmf_stage1_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_dtmf_stage1_rsp_struct *sim_rsp;
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_rsp = (mmi_sat_send_dtmf_stage1_rsp_struct*) info;
    srv_sat_terminal_response_send_dtmf_stage2(
        SATID_2_SIMID(sat_id),
        (srv_sat_terminal_res_enum) sim_rsp->terminal_res,
        (srv_sat_additional_res_enum) sim_rsp->cause);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_dtmf_stage2_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_dtmf_stage2_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_send_dtmf_struct *send_dtmf = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_dtmf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_do_free(send_dtmf->alpha_id);
    send_dtmf->alpha_id = NULL;
    srv_sat_do_free(send_dtmf->dtmf_string);
    send_dtmf->dtmf_string = NULL;
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    srv_sat_do_free(send_dtmf->icon.data);
    send_dtmf->icon.data = NULL;
#endif

    g_srv_sat_proactive_sim[sat_id].cmd_type = SRV_SAT_CMD_NONE;
}


#ifndef __SAT_LOWCOST_UI_DISABLE__

/*****************************************************************************
 * FUNCTION
 *  srv_sat_language_notification_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_language_notification_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_language_notification_struct *language_notification = &g_srv_sat_proactive_sim[sat_id].cmd_data.language_notification;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sat_do_language_notification(sat_id, &g_srv_sat_cntx[sat_id], language_notification, info))
    {
        srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_LANGUAGE_NOTIFICATION);
    }
}


#ifndef __SAT_DISABLE_ICON_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_launch_browser_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  result      [IN]        
 *  icon_data   [IN]        
 *  user_data   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_launch_browser_hdlr(srv_sat_enum sat_id, MMI_BOOL result, U8 *icon_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_launch_browser_struct *launch_browser = &g_srv_sat_proactive_sim[sat_id].cmd_data.launch_browser;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        launch_browser->icon.data = icon_data;
        if (launch_browser->icon.attr == SRV_SAT_ICON_SELF_EX)
        {
            srv_sat_do_free(launch_browser->alpha_id);
            launch_browser->alpha_id = NULL;
        }
    }
    else
    {
        launch_browser->icon.available = MMI_FALSE;
    }

    srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_LAUNCH_BROWSER);
}
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */

#ifdef __SATCC__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_launch_browser_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_launch_browser_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_launch_browser_struct *launch_browser = &g_srv_sat_proactive_sim[sat_id].cmd_data.launch_browser;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sat_do_launch_browser(sat_id, &g_srv_sat_cntx[sat_id], launch_browser, info))
    {
    #ifndef __SAT_DISABLE_ICON_SUPPORT__
        if (launch_browser->icon.available)
        {
            srv_sat_do_icon(sat_id, launch_browser->icon.id, srv_sat_launch_browser_hdlr, NULL);
            return;
        }
    #endif /* __SAT_DISABLE_ICON_SUPPORT__ */

        srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_LAUNCH_BROWSER);
    }
}

#ifdef BROWSER_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  srv_sat_launch_browser_stage1_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_launch_browser_stage1_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmi_lauch_browser_rsp_struct *launch_browser;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    launch_browser = (wap_mmi_lauch_browser_rsp_struct*) info;
    srv_sat_terminal_response_launch_browser_stage2(
        (mmi_sim_enum) launch_browser->sim_id,
        (srv_sat_terminal_res_enum) launch_browser->res,
        (srv_sat_additional_res_enum) launch_browser->additionalInfo);
}

#endif /* BROWSER_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_launch_browser_stage2_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_launch_browser_stage2_rsp(void *info, int mod_src)
{
#ifdef BROWSER_SUPPORT

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_launch_browser_struct *launch_browser = &g_srv_sat_proactive_sim[sat_id].cmd_data.launch_browser;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_do_free(launch_browser->url);
    launch_browser->url = NULL;
    srv_sat_do_free(launch_browser->bearer);
    launch_browser->bearer = NULL;
    srv_sat_do_free(launch_browser->gateway);
    launch_browser->gateway = NULL;
    srv_sat_do_free(launch_browser->alpha_id);
    launch_browser->alpha_id = NULL;
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    srv_sat_do_free(launch_browser->icon.data);
    launch_browser->icon.data = NULL;
#endif

    g_srv_sat_proactive_sim[sat_id].cmd_type = SRV_SAT_CMD_NONE;
#endif /* BROWSER_SUPPORT */
}
#endif //__SATCC__
#endif /* __SAT_LOWCOST_UI_DISABLE__ */

#ifdef __SATCE__


#ifndef __SAT_DISABLE_ICON_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_open_channel_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  result      [IN]        
 *  icon_data   [IN]        
 *  user_data   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_open_channel_hdlr(srv_sat_enum sat_id, MMI_BOOL result, U8 *icon_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_open_channel_struct *open_channel = &g_srv_sat_proactive_sim[sat_id].cmd_data.open_channel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        open_channel->icon.data = icon_data;
        if (open_channel->icon.attr == SRV_SAT_ICON_SELF_EX)
        {
            srv_sat_do_free(open_channel->alpha_id);
            open_channel->alpha_id = NULL;
        }
    }
    else
    {
        open_channel->icon.available = MMI_FALSE;
    }

    srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_OPEN_CHANNEL);
}
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_open_channel_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_open_channel_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_open_channel_struct *open_channel = &g_srv_sat_proactive_sim[sat_id].cmd_data.open_channel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sat_do_open_channel(sat_id, &g_srv_sat_cntx[sat_id], open_channel, info))
    {
    #ifndef __SAT_DISABLE_ICON_SUPPORT__
        if (open_channel->icon.available)
        {
            srv_sat_do_icon(sat_id, open_channel->icon.id, srv_sat_open_channel_hdlr, NULL);
            return;
        }
    #endif /* __SAT_DISABLE_ICON_SUPPORT__ */

        srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_OPEN_CHANNEL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_open_channel_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_open_channel_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_open_channel_struct *open_channel = &g_srv_sat_proactive_sim[sat_id].cmd_data.open_channel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_do_free(open_channel->alpha_id);
    open_channel->alpha_id = NULL;
    srv_sat_do_free(open_channel->icon.data);
    open_channel->icon.data = NULL;

    g_srv_sat_proactive_sim[sat_id].cmd_type = SRV_SAT_CMD_NONE;
}


#ifndef __SAT_DISABLE_ICON_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_close_channel_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  result      [IN]        
 *  icon_data   [IN]        
 *  user_data   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_close_channel_hdlr(srv_sat_enum sat_id, MMI_BOOL result, U8 *icon_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_close_channel_struct *close_channel = &g_srv_sat_proactive_sim[sat_id].cmd_data.close_channel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        close_channel->icon.data = icon_data;
        if (close_channel->icon.attr == SRV_SAT_ICON_SELF_EX)
        {
            srv_sat_do_free(close_channel->alpha_id);
            close_channel->alpha_id = NULL;
        }
    }
    else
    {
        close_channel->icon.available = MMI_FALSE;
    }

    srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_CLOSE_CHANNEL);
}
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_close_channel_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_close_channel_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_close_channel_struct *close_channel = &g_srv_sat_proactive_sim[sat_id].cmd_data.close_channel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sat_do_close_channel(sat_id, &g_srv_sat_cntx[sat_id], close_channel, info))
    {
    #ifndef __SAT_DISABLE_ICON_SUPPORT__
        if (close_channel->icon.available)
        {
            srv_sat_do_icon(sat_id, close_channel->icon.id, srv_sat_close_channel_hdlr, NULL);
            return;
        }
    #endif /* __SAT_DISABLE_ICON_SUPPORT__ */

        srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_CLOSE_CHANNEL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_close_channel_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_close_channel_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_close_channel_struct *close_channel = &g_srv_sat_proactive_sim[sat_id].cmd_data.close_channel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_do_free(close_channel->alpha_id);
    close_channel->alpha_id = NULL;
    srv_sat_do_free(close_channel->icon.data);
    close_channel->icon.data = NULL;

    g_srv_sat_proactive_sim[sat_id].cmd_type = SRV_SAT_CMD_NONE;
}


#ifndef __SAT_DISABLE_ICON_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_data_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  result      [IN]        
 *  icon_data   [IN]        
 *  user_data   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_data_hdlr(srv_sat_enum sat_id, MMI_BOOL result, U8 *icon_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_send_data_struct *send_data = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        send_data->icon.data = icon_data;
        if (send_data->icon.attr == SRV_SAT_ICON_SELF_EX)
        {
            srv_sat_do_free(send_data->alpha_id);
            send_data->alpha_id = NULL;
        }
    }
    else
    {
        send_data->icon.available = MMI_FALSE;
    }

    srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_SEND_DATA);
}
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_data_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_data_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_send_data_struct *send_data = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sat_do_send_data(sat_id, &g_srv_sat_cntx[sat_id], send_data, info))
    {
    #ifndef __SAT_DISABLE_ICON_SUPPORT__
        if (send_data->icon.available)
        {
            srv_sat_do_icon(sat_id, send_data->icon.id, srv_sat_send_data_hdlr, NULL);
            return;
        }
    #endif /* __SAT_DISABLE_ICON_SUPPORT__ */

        srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_SEND_DATA);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_data_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_data_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_send_data_struct *send_data = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_do_free(send_data->alpha_id);
    send_data->alpha_id = NULL;
    srv_sat_do_free(send_data->icon.data);
    send_data->icon.data = NULL;

    g_srv_sat_proactive_sim[sat_id].cmd_type = SRV_SAT_CMD_NONE;
}


#ifndef __SAT_DISABLE_ICON_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_receive_data_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  result      [IN]        
 *  icon_data   [IN]        
 *  user_data   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_receive_data_hdlr(srv_sat_enum sat_id, MMI_BOOL result, U8 *icon_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_receive_data_struct *receive_data = &g_srv_sat_proactive_sim[sat_id].cmd_data.receive_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        receive_data->icon.data = icon_data;
        if (receive_data->icon.attr == SRV_SAT_ICON_SELF_EX)
        {
            srv_sat_do_free(receive_data->alpha_id);
            receive_data->alpha_id = NULL;
        }
    }
    else
    {
        receive_data->icon.available = MMI_FALSE;
    }

    srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_RECEIVE_DATA);
}
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_receive_data_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_receive_data_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_receive_data_struct *receive_data = &g_srv_sat_proactive_sim[sat_id].cmd_data.receive_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sat_do_receive_data(sat_id, &g_srv_sat_cntx[sat_id], receive_data, info))
    {
    #ifndef __SAT_DISABLE_ICON_SUPPORT__
        if (receive_data->icon.available)
        {
            srv_sat_do_icon(sat_id, receive_data->icon.id, srv_sat_receive_data_hdlr, NULL);
            return;
        }
    #endif /* __SAT_DISABLE_ICON_SUPPORT__ */

        srv_sat_send_proactive_sim_event(sat_id, SRV_SAT_CMD_RECEIVE_DATA);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_receive_data_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_receive_data_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_receive_data_struct *receive_data = &g_srv_sat_proactive_sim[sat_id].cmd_data.receive_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_do_free(receive_data->alpha_id);
    receive_data->alpha_id = NULL;
    srv_sat_do_free(receive_data->icon.data);
    receive_data->icon.data = NULL;

    g_srv_sat_proactive_sim[sat_id].cmd_type = SRV_SAT_CMD_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_notify_mmi_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_notify_mmi_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_id = mmi_frm_l4c_mod_to_sim((module_type)mod_src);
    mmi_sat_notify_mmi_ind_struct *notify = (mmi_sat_notify_mmi_ind_struct *)info;
    srv_sat_cmd_enum cmd_type = SRV_SAT_CMD_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (notify->state)
    {
        case SRV_SAT_CLOSE_CHANNEL_FINISHED:
            cmd_type = SRV_SAT_CMD_CLOSE_CHANNEL;
            break;

        case SRV_SAT_SEND_DATA_FINISHED:
        case SRV_SAT_SEND_DATA_TERMINATED:
            cmd_type = SRV_SAT_CMD_SEND_DATA;
            break;

        case SRV_SAT_RECEIVE_DATA_FINISHED:
        case SRV_SAT_RECEIVE_DATA_TERMINATED:
            cmd_type = SRV_SAT_CMD_RECEIVE_DATA;
            break;

        default:
            break;
    }

    if (cmd_type != SRV_SAT_CMD_NONE)
    {
        srv_sat_free_last_proactive_sim(sim_id, cmd_type);
        srv_sat_send_session_end_event(SIMID_2_SATID(sim_id));
    }
}

#endif /* __SATCE__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_no_other_cmd_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_no_other_cmd_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_send_session_end_event(sat_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_call_control_by_sim_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_call_control_by_sim_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sat_do_call_control_by_sim(sat_id, info);
}


#ifndef __SAT_LOWCOST_UI_DISABLE__
#ifdef __SATCC__

/*****************************************************************************
 * FUNCTION
 *  srv_sat_browser_termination_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_browser_termination_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_id[] = {MMI_SIM1, MMI_SIM2, MMI_SIM3, MMI_SIM4};
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (srv_sim_ctrl_is_available(sim_id[i]))
        {
            srv_sat_envelope_browser_termination(
                sim_id[i],
                (srv_sat_browser_termination_enum) ((mmi_sat_evdl_browser_termination_rsp_struct*) info)->result);
        }
    }
}
#endif /*SATCC*/
#endif /* __SAT_LOWCOST_UI_DISABLE__ */


/* Protocol Handlers Table for SAT */
static const srv_sat_ps_hdlr_table g_srv_sat_ps_hdlr_table[] =
                                        {
                                            {PRT_MMI_SAT_DISPLAY_TEXT_IND, srv_sat_display_text_ind},
                                            {PRT_MMI_SAT_DISPLAY_TEXT_RES_RSP, srv_sat_display_text_rsp},

                                            {PRT_MMI_SAT_GET_INKEY_IND, srv_sat_get_inkey_ind},
                                            {PRT_MMI_SAT_GET_INKEY_RES_RSP, srv_sat_get_inkey_rsp},

                                            {PRT_MMI_SAT_GET_INPUT_IND, srv_sat_get_input_ind},
                                            {PRT_MMI_SAT_GET_INPUT_RES_RSP, srv_sat_get_input_rsp},

                                            {PRT_MMI_SAT_PLAY_TONE_IND, srv_sat_play_tone_ind},
                                            {PRT_MMI_SAT_PLAY_TONE_RES_RSP, srv_sat_play_tone_rsp},

                                            {PRT_MMI_SAT_SIM_FILE_CHANGE_IND, srv_sat_refresh_ind},

                                            {PRT_MMI_SAT_SETUP_MENU_IND, srv_sat_setup_menu_ind},
                                            {PRT_MMI_SAT_SETUP_MENU_RES_RSP, srv_sat_setup_menu_rsp},

                                            {PRT_MMI_SAT_SELECT_ITEM_IND, srv_sat_select_item_ind},
                                            {PRT_MMI_SAT_SELECT_ITEM_RES_RSP, srv_sat_select_item_rsp},

                                            {PRT_MMI_SAT_SEND_SMS_IND, srv_sat_send_sms_ind},
                                            {PRT_MMI_SAT_SEND_SMS_STAGE1_RSP, srv_sat_send_sms_stage1_rsp},
                                            {PRT_MMI_SAT_SEND_SMS_STAGE2_RSP, srv_sat_send_sms_stage2_rsp},

                                            {PRT_MMI_SAT_SEND_SS_IND, srv_sat_send_ss_ind},
                                            {PRT_MMI_SAT_SEND_SS_STAGE1_RSP, srv_sat_send_ss_stage1_rsp},
                                            {PRT_MMI_SAT_SEND_SS_STAGE2_RSP, srv_sat_send_ss_stage2_rsp},

                                            {PRT_MMI_SAT_SEND_USSD_IND, srv_sat_send_ussd_ind},
                                            {PRT_MMI_SAT_SEND_USSD_STAGE1_RSP, srv_sat_send_ussd_stage1_rsp},
                                            {PRT_MMI_SAT_SEND_USSD_STAGE2_RSP, srv_sat_send_ussd_stage2_rsp},

                                            {PRT_MMI_SAT_CALL_SETUP_IND, srv_sat_setup_call_ind},
                                            {PRT_MMI_SAT_CALL_SETUP_STAGE1_RSP, srv_sat_setup_call_stage1_rsp},
                                            {PRT_MMI_SAT_CALL_SETUP_STAGE2_RSP, srv_sat_setup_call_stage2_rsp},

                                        #ifndef __SAT_LOWCOST_UI_DISABLE__
                                            {PRT_MMI_SAT_PROVIDE_LANG_INFO_IND, srv_sat_provide_language_info_ind},
                                        #endif

                                            {PRT_MMI_SAT_SETUP_IDLE_DISPLAY_IND, srv_sat_setup_idle_mode_text_ind},

                                            {PRT_MMI_SAT_RUN_AT_COMMAND_IND, srv_sat_run_at_command_ind},

                                            {PRT_MMI_SAT_SEND_DTMF_IND, srv_sat_send_dtmf_ind},
                                            {PRT_MMI_SAT_SEND_DTMF_STAGE1_RSP, srv_sat_send_dtmf_stage1_rsp},
                                            {PRT_MMI_SAT_SEND_DTMF_STAGE2_RSP, srv_sat_send_dtmf_stage2_rsp},

                                        #ifndef __SAT_LOWCOST_UI_DISABLE__
                                            {PRT_MMI_SAT_LANG_NOTIFY_IND, srv_sat_language_notification_ind},
					#ifdef __SATCC__
                                            {PRT_MMI_SAT_LAUNCH_BROWSER_IND, srv_sat_launch_browser_ind},
										
                                        #ifdef BROWSER_SUPPORT
                                            {PRT_WAP_MMI_LAUNCH_BROWSER_RSP, srv_sat_launch_browser_stage1_rsp},
                                        #endif
                                            {PRT_MMI_SAT_LAUNCH_BROWSER_RES_RSP, srv_sat_launch_browser_stage2_rsp},
                                        #endif
                                        #endif /* __SAT_LOWCOST_UI_DISABLE__ */

                                        #ifdef __SATCE__
                                            {MSG_ID_MMI_SAT_OPEN_CHANNEL_IND, srv_sat_open_channel_ind},
                                            {MSG_ID_MMI_SAT_OPEN_CHANNEL_RSP, srv_sat_open_channel_rsp},

                                            {MSG_ID_MMI_SAT_CLOSE_CHANNEL_IND, srv_sat_close_channel_ind},
                                            {MSG_ID_MMI_SAT_CLOSE_CHANNEL_RSP, srv_sat_close_channel_rsp},

                                            {MSG_ID_MMI_SAT_SEND_DATA_IND, srv_sat_send_data_ind},
                                            {MSG_ID_MMI_SAT_SEND_DATA_RSP, srv_sat_send_data_rsp},

                                            {MSG_ID_MMI_SAT_RECV_DATA_IND, srv_sat_receive_data_ind},
                                            {MSG_ID_MMI_SAT_RECV_DATA_RSP, srv_sat_receive_data_rsp},

                                            {MSG_ID_MMI_SAT_NOTIFY_MMI_IND, srv_sat_notify_mmi_ind},
                                        #endif /* __SATCE__ */

                                            /* A proactive SIM session starts with the status response '91 xx' (proactive command pending) and
                                                                           ends with a status response of '90 00' (normal ending of command) after Terminal Response. */
                                            {PRT_MMI_SAT_NO_OTHER_CMD_IND, srv_sat_no_other_cmd_ind},

                                            /* Call control and MO Short Message control by SIM */
                                            {PRT_MMI_SAT_MMI_INFO_IND, srv_sat_call_control_by_sim_ind},

                                        /* Event download */
                                        #ifndef __SAT_LOWCOST_UI_DISABLE__
										#ifdef __SATCC__
                                            {PRT_WAP_MMI_BROWSER_TERMINATION_IND, srv_sat_browser_termination_ind}
										#endif
                                        #endif
                                        };


/*****************************************************************************
 * FUNCTION
 *  srv_sat_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(g_srv_sat_ps_hdlr_table) / sizeof(srv_sat_ps_hdlr_table); i++)
    {
        mmi_frm_set_protocol_event_handler(g_srv_sat_ps_hdlr_table[i].msg_id, (PsIntFuncPtr)g_srv_sat_ps_hdlr_table[i].hdlr, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_last_proactive_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  srv_sat_proactive_sim_struct*
 *****************************************************************************/
const srv_sat_proactive_sim_struct* srv_sat_get_last_proactive_sim(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_srv_sat_proactive_sim[sat_id];
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_free_last_proactive_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  cmd_type:       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_free_last_proactive_sim(mmi_sim_enum sim_id, srv_sat_cmd_enum cmd_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cmd_type)
    {
        case SRV_SAT_CMD_RUN_AT_COMMAND:
            {
                srv_sat_run_at_command_struct *run_at_command = &g_srv_sat_proactive_sim[sat_id].cmd_data.run_at_command;
                srv_sat_do_free(run_at_command->alpha_id);
                run_at_command->alpha_id = NULL;
                srv_sat_do_free(run_at_command->icon.data);
                run_at_command->icon.data = NULL;
            }
            break;

    #ifdef __SATCE__
        case SRV_SAT_CMD_CLOSE_CHANNEL:
            {
                srv_sat_close_channel_struct *close_channel = &g_srv_sat_proactive_sim[sat_id].cmd_data.close_channel;
                srv_sat_do_free(close_channel->alpha_id);
                close_channel->alpha_id = NULL;
                srv_sat_do_free(close_channel->icon.data);
                close_channel->icon.data = NULL;
            }
            break;

        case SRV_SAT_CMD_SEND_DATA:
            {
                srv_sat_send_data_struct *send_data = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_data;
                srv_sat_do_free(send_data->alpha_id);
                send_data->alpha_id = NULL;
                srv_sat_do_free(send_data->icon.data);
                send_data->icon.data = NULL;
            }
            break;

        case SRV_SAT_CMD_RECEIVE_DATA:
            {
                srv_sat_receive_data_struct *receive_data = &g_srv_sat_proactive_sim[sat_id].cmd_data.receive_data;
                srv_sat_do_free(receive_data->alpha_id);
                receive_data->alpha_id = NULL;
                srv_sat_do_free(receive_data->icon.data);
                receive_data->icon.data = NULL;
            }
            break;
    #endif /* __SATCE__ */

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_setup_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  srv_sat_setup_menu_struct*
 *****************************************************************************/
const srv_sat_setup_menu_struct* srv_sat_get_setup_menu(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_srv_sat_cntx[sat_id].setup_menu;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_setup_idle_mode_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  srv_sat_setup_idle_mode_text_struct*
 *****************************************************************************/
const srv_sat_setup_idle_mode_text_struct* srv_sat_get_setup_idle_mode_text(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_srv_sat_cntx[sat_id].setup_idle_mode_text;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_icon_res
 * DESCRIPTION
 *  
 * PARAMETERS
 *  terminal_res:         [IN] 
 * icon                       [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
srv_sat_terminal_res_enum srv_sat_get_icon_res(srv_sat_terminal_res_enum terminal_res, srv_sat_icon_struct icon)
{
	if(terminal_res == SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY 
		&&icon.id > 0 && !icon.available)
	{
		return SRV_SAT_TERMINAL_RES_CMD_PERFORMED_BUT_ICON_COULD_NOT_DISPLAY;
	}
	else
	{
		return terminal_res;
	}

}

/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_display_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  additional_res: [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_display_text(
        mmi_sim_enum sim_id,
        srv_sat_terminal_res_enum terminal_res,
        srv_sat_additional_res_enum additional_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_display_text_res_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_display_text_struct *display_text = &g_srv_sat_proactive_sim[sat_id].cmd_data.display_text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_display_text_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_display_text_res_req_struct));
    memcpy(data_ptr->cmd_detail, display_text->cmd_detail, 5 * sizeof(U8));

	data_ptr->res = srv_sat_get_icon_res(terminal_res, display_text->icon);

    data_ptr->additional_info = additional_res;

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_DISPLAY_TEXT_RES_REQ, (oslParaType*) data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_get_inkey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  is_yes_selected:[IN]        
 *  text_string:    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_get_inkey(
        mmi_sim_enum sim_id,
        srv_sat_terminal_res_enum terminal_res,
        MMI_BOOL is_yes_selected,
        WCHAR *text_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_get_inkey_res_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_get_inkey_struct *get_inkey = &g_srv_sat_proactive_sim[sat_id].cmd_data.get_inkey;
    U16 text_len = !text_string ? 0 : mmi_wcslen(text_string);
    U8 *input;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr =
        (mmi_sat_get_inkey_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_get_inkey_res_req_struct) +
                                                text_len * ENCODING_LENGTH);
    memcpy(data_ptr->cmd_detail, get_inkey->cmd_detail, 5 * sizeof(U8));
	data_ptr->res = srv_sat_get_icon_res(terminal_res, get_inkey->icon);

    data_ptr->is_yes_selected = is_yes_selected;
    data_ptr->dcs_of_text_string = get_inkey->dcs_type;

    if (!text_len)
    {
        data_ptr->no_text_string = 0;
    }
    else
    {    
        S32 add_num = 1;
        MMIDCSENUM dcs = MMI_DEFAULT_DCS;
        input = (U8*) OslMalloc(text_len * ENCODING_LENGTH + ENCODING_LENGTH);
        if (data_ptr->dcs_of_text_string == SRV_SAT_DCS_UCS2)
        {
            add_num = 2;
            dcs = MMI_UCS2_DCS;
        }

        data_ptr->no_text_string = InputboxConvertDeviceEncodingToGSM(
                                                (PU8) text_string,
                                                input,
                                                text_len * ENCODING_LENGTH + ENCODING_LENGTH,
                                                dcs,
                                                0,
                                                1) - add_num;
        memcpy(data_ptr->text_string, input, data_ptr->no_text_string);
        OslMfree(input);
    }

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_GET_INKEY_RES_REQ, (oslParaType*) data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_get_input
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  text_string:    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_get_input(
        mmi_sim_enum sim_id,
        srv_sat_terminal_res_enum terminal_res,
        WCHAR *text_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_get_input_res_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_get_input_struct *get_input = &g_srv_sat_proactive_sim[sat_id].cmd_data.get_input;
    U16 text_len = !text_string ? 0 : mmi_wcslen(text_string);
    U8 *input;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr =
        (mmi_sat_get_input_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_get_input_res_req_struct) +
                                                text_len * ENCODING_LENGTH);
    memcpy(data_ptr->cmd_detail, get_input->cmd_detail, 5 * sizeof(U8));
	data_ptr->res = srv_sat_get_icon_res(terminal_res, get_input->icon);

    data_ptr->dcs_of_text_string = get_input->dcs_type;

    if (!text_len)
    {
        data_ptr->no_text_string = 0;
    }
    else
    {
        S32 add_num = 1;
        MMIDCSENUM dcs = MMI_DEFAULT_DCS;
        input = (U8*) OslMalloc(text_len * ENCODING_LENGTH + ENCODING_LENGTH);
        if (data_ptr->dcs_of_text_string == SRV_SAT_DCS_UCS2)
        {
            add_num = 2;
            dcs = MMI_UCS2_DCS;
        }

        data_ptr->no_text_string = InputboxConvertDeviceEncodingToGSM(
                                                (PU8) text_string,
                                                input,
                                                text_len * ENCODING_LENGTH + ENCODING_LENGTH,
                                                dcs,
                                                0,
                                                1) - add_num;

        memcpy(data_ptr->text_string, input, data_ptr->no_text_string);
        OslMfree(input);
    }

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_GET_INPUT_RES_REQ, (oslParaType*) data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_play_tone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_play_tone(
        mmi_sim_enum sim_id,
        srv_sat_terminal_res_enum terminal_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_play_tone_res_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_play_tone_struct *play_tone = &g_srv_sat_proactive_sim[sat_id].cmd_data.play_tone;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_play_tone_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_play_tone_res_req_struct));
    memcpy(data_ptr->cmd_detail, play_tone->cmd_detail, 5 * sizeof(U8));
	data_ptr->res = srv_sat_get_icon_res(terminal_res, play_tone->icon);

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_PLAY_TONE_RES_REQ, (oslParaType*) data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_setup_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_setup_menu(
        mmi_sim_enum sim_id,
        srv_sat_terminal_res_enum terminal_res)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_setup_menu_res_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_setup_menu_struct *setup_menu = &g_srv_sat_cntx[sat_id].setup_menu;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_setup_menu_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_setup_menu_res_req_struct));
    memcpy(data_ptr->cmd_detail, setup_menu->cmd_detail, 5 * sizeof(U8));

    if (terminal_res == SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY)
    {
        if (setup_menu->icon.id > 0 && !setup_menu->icon.available)
        {
            data_ptr->res = SRV_SAT_TERMINAL_RES_CMD_PERFORMED_BUT_ICON_COULD_NOT_DISPLAY;
        }
        else
        {
            data_ptr->res = SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY;
            for (i = 0; i < setup_menu->num_of_item; i++)
            {
                if (setup_menu->item_list[i].icon.id > 0 && !setup_menu->item_list[i].icon.available)
                {
                    data_ptr->res = SRV_SAT_TERMINAL_RES_CMD_PERFORMED_BUT_ICON_COULD_NOT_DISPLAY;
                    break;
                }
            }
        }
    }
    else

    {
        data_ptr->res = terminal_res;
    }

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_SETUP_MENU_RES_REQ, (oslParaType*) data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_select_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  item_id:        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_select_item(
        mmi_sim_enum sim_id,
        srv_sat_terminal_res_enum terminal_res,
        U8 item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_select_item_res_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_select_item_struct *select_item = &g_srv_sat_proactive_sim[sat_id].cmd_data.select_item;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_sat_cntx[sat_id].sent = 1;
    data_ptr = (mmi_sat_select_item_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_select_item_res_req_struct));
    memcpy(data_ptr->cmd_detail, select_item->cmd_detail, 5 * sizeof(U8));

    if (terminal_res == SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY)
    {
        if (select_item->icon.id > 0 && !select_item->icon.available)
        {
            data_ptr->res = SRV_SAT_TERMINAL_RES_CMD_PERFORMED_BUT_ICON_COULD_NOT_DISPLAY;
        }
        else
        {
            data_ptr->res = SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY;
            for (i = 0; i < select_item->num_of_item; i++)
            {
                if (select_item->item_list[i].icon.id > 0 && !select_item->item_list[i].icon.available)
                {
                    data_ptr->res = SRV_SAT_TERMINAL_RES_CMD_PERFORMED_BUT_ICON_COULD_NOT_DISPLAY;
                    break;
                }
            }
        }
    }
    else
    {
        data_ptr->res = terminal_res;
    }
    data_ptr->item_id = item_id;

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_SELECT_ITEM_RES_REQ, (oslParaType*) data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_send_sms_stage1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_send_sms_stage1(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_sms_stage1_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_send_sms_struct *send_sms = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_sms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_send_sms_stage1_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_sms_stage1_req_struct));
    data_ptr->is_sms_packed_required = send_sms->sms_packed;
    data_ptr->no_addr = send_sms->addr_len;
    if (data_ptr->no_addr > 0)
    {
        memcpy(data_ptr->addr, send_sms->addr, 41);
    }
    data_ptr->tpdu_length = send_sms->tpdu_len;
    if (data_ptr->tpdu_length > 0)
    {
        memcpy(data_ptr->tpdu, send_sms->tpdu, 175);
    }

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_SEND_SMS_STAGE1_REQ, (oslParaType*) data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_send_sms_stage2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  additional_res: [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_send_sms_stage2(
        mmi_sim_enum sim_id,
        srv_sat_terminal_res_enum terminal_res,
        srv_sat_additional_res_enum additional_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_sms_stage2_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_send_sms_struct *send_sms = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_sms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_send_sms_stage2_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_sms_stage2_req_struct));
    memcpy(data_ptr->cmd_detail, send_sms->cmd_detail, 5 * sizeof(U8));
	data_ptr->res = srv_sat_get_icon_res(terminal_res, send_sms->icon);

    data_ptr->cause = additional_res;

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_SEND_SMS_STAGE2_REQ, (oslParaType*) data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_send_ss_stage1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_send_ss_stage1(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_ss_stage1_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_send_ss_struct *send_ss = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_ss;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_send_ss_stage1_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_ss_stage1_req_struct));
    memcpy(data_ptr->input, send_ss->ss_string, MAX_DIGITS_USSD);
    data_ptr->length = send_ss->ss_len;
    data_ptr->type_of_modification = send_ss->cc_type;

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_SEND_SS_STAGE1_REQ, (oslParaType*) data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_send_ss_stage2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  length:         [IN]        
 *  additional_info:[IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_send_ss_stage2(
        mmi_sim_enum sim_id,
        srv_sat_terminal_res_enum terminal_res,
        U8 length,
        U8 *additional_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_ss_stage2_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_send_ss_struct *send_ss = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_ss;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_send_ss_stage2_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_ss_stage2_req_struct));
    memcpy(data_ptr->cmd_detail, send_ss->cmd_detail, 5 * sizeof(U8));
	data_ptr->res = srv_sat_get_icon_res(terminal_res, send_ss->icon);

    data_ptr->size_of_additional_info = length;
    if (length > 0)
    {
        memcpy(data_ptr->additional_info, additional_info, length);
    }

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_SEND_SS_STAGE2_REQ, (oslParaType*) data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_send_ussd_stage1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_send_ussd_stage1(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_ussd_stage1_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_send_ussd_struct *send_ussd = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_ussd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_send_ussd_stage1_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_ussd_stage1_req_struct));
    memcpy(data_ptr->input, send_ussd->ussd_string, MAX_DIGITS_USSD);
    data_ptr->length = send_ussd->ussd_len;
    data_ptr->dcs = send_ussd->ussd_dcs;
    data_ptr->type_of_modification = send_ussd->cc_type;

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_SEND_USSD_STAGE1_REQ, (oslParaType*) data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_send_ussd_stage2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  length:         [IN]        
 *  additional_info:[IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_send_ussd_stage2(
        mmi_sim_enum sim_id,
        srv_sat_terminal_res_enum terminal_res,
        U8 length,
        U8 *additional_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_ussd_stage2_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_send_ussd_struct *send_ussd = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_ussd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_send_ussd_stage2_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_ussd_stage2_req_struct));
    memcpy(data_ptr->cmd_detail, send_ussd->cmd_detail, 5 * sizeof(U8));
	data_ptr->res = srv_sat_get_icon_res(terminal_res, send_ussd->icon);

    data_ptr->size_of_additional_info = length;
    if (length > 0)
    {
        memcpy(data_ptr->additional_info, additional_info, length);
    }

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_SEND_USSD_STAGE2_REQ, (oslParaType*) data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_setup_call_stage1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_setup_call_stage1(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_call_setup_stage1_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_setup_call_struct *setup_call = &g_srv_sat_proactive_sim[sat_id].cmd_data.setup_call;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_sat_cntx[sat_id].sent = 0;
    data_ptr = (mmi_sat_call_setup_stage1_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_call_setup_stage1_req_struct));
    data_ptr->sat_call_type = setup_call->condition;
    data_ptr->no_addr = setup_call->addr_len;
    if (data_ptr->no_addr > 0)
    {
        memcpy(data_ptr->addr, setup_call->addr, 41);
    }
    data_ptr->no_ccp = setup_call->ccp_len;
    if (data_ptr->no_ccp > 0)
    {
        memcpy(data_ptr->ccp, setup_call->ccp, 15);
    }
    data_ptr->no_sub_addr = setup_call->subadrr_len;
    if (data_ptr->no_sub_addr > 0)
    {
        memcpy(data_ptr->sub_addr, setup_call->subadrr, 21);
    }
    data_ptr->type_of_modification = setup_call->cc_type;

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_CALL_SETUP_STAGE1_REQ, (oslParaType*) data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_setup_call_stage2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  additional_res: [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_setup_call_stage2(
        mmi_sim_enum sim_id,
        srv_sat_terminal_res_enum terminal_res,
        srv_sat_additional_res_enum additional_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_call_setup_stage2_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_setup_call_struct *setup_call = &g_srv_sat_proactive_sim[sat_id].cmd_data.setup_call;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_sat_cntx[sat_id].sent = 1;
    data_ptr = (mmi_sat_call_setup_stage2_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_call_setup_stage2_req_struct));
    memcpy(data_ptr->cmd_detail, setup_call->cmd_detail, 5 * sizeof(U8));
	data_ptr->res = srv_sat_get_icon_res(terminal_res, setup_call->icon1);
	if(data_ptr->res != SRV_SAT_TERMINAL_RES_CMD_PERFORMED_BUT_ICON_COULD_NOT_DISPLAY)
    {
		data_ptr->res = srv_sat_get_icon_res(terminal_res, setup_call->icon2);
    }

    data_ptr->cause = additional_res;

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_CALL_SETUP_STAGE2_REQ, (oslParaType*) data_ptr, NULL);
}


#ifndef __SAT_LOWCOST_UI_DISABLE__

/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_provide_language_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  lang:           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_provide_language_info(mmi_sim_enum sim_id, U8 *lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_provide_lang_info_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_provide_lang_info_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_provide_lang_info_req_struct));
    memcpy(data_ptr->lang, lang, 2 * sizeof(U8));

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_PROVIDE_LANG_INFO_REQ, (oslParaType*) data_ptr, NULL);
}

#endif /* __SAT_LOWCOST_UI_DISABLE__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_refresh
 * DESCRIPTION
 *  Follow the AT&T spec
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_refresh(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_file_change_res_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_file_change_res_req_struct *) OslConstructDataPtr(sizeof(mmi_sat_file_change_res_req_struct));
    data_ptr->is_successful = MMI_TRUE;

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_FILE_CHANGE_RES_REQ, (oslParaType *)data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_setup_idle_mode_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_setup_idle_mode_text(
        mmi_sim_enum sim_id,
        srv_sat_terminal_res_enum terminal_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_setup_idle_display_res_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_setup_idle_mode_text_struct *setup_idle_mode_text = &g_srv_sat_cntx[sat_id].setup_idle_mode_text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_setup_idle_display_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_setup_idle_display_res_req_struct));
    memcpy(data_ptr->cmd_detail, setup_idle_mode_text->cmd_detail, 5 * sizeof(U8));
	data_ptr->res = srv_sat_get_icon_res(terminal_res, setup_idle_mode_text->icon);


    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_SETUP_IDLE_DISPLAY_RES_REQ, (oslParaType*) data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_send_dtmf_stage1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_send_dtmf_stage1(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_dtmf_stage1_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_send_dtmf_struct *send_dtmf = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_dtmf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_send_dtmf_stage1_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_dtmf_stage1_req_struct));
    memcpy(data_ptr->dtmf_digit, send_dtmf->dtmf_string, MAX_CC_ADDR_BCD_LEN);
    data_ptr->no_digit = send_dtmf->dtmf_len;

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_SEND_DTMF_STAGE1_REQ, (oslParaType*) data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_send_dtmf_stage2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  additional_res: [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_send_dtmf_stage2(
        mmi_sim_enum sim_id,
        srv_sat_terminal_res_enum terminal_res,
        srv_sat_additional_res_enum additional_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_dtmf_stage2_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_send_dtmf_struct *send_dtmf = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_dtmf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_send_dtmf_stage2_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_dtmf_stage2_req_struct));
    memcpy(data_ptr->cmd_detail, send_dtmf->cmd_detail, 5 * sizeof(U8));
	data_ptr->res = srv_sat_get_icon_res(terminal_res, send_dtmf->icon);

    data_ptr->additional_info = additional_res;

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_SEND_DTMF_STAGE2_REQ, (oslParaType*) data_ptr, NULL);
}


#ifndef __SAT_LOWCOST_UI_DISABLE__

/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_language_notification
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_language_notification(
        mmi_sim_enum sim_id,
        srv_sat_terminal_res_enum terminal_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_lang_notify_res_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_language_notification_struct *language_notification = &g_srv_sat_proactive_sim[sat_id].cmd_data.language_notification;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_lang_notify_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_lang_notify_res_req_struct));
    memcpy(data_ptr->cmd_detail, language_notification->cmd_detail, 5 * sizeof(U8));
    data_ptr->res = terminal_res;

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_LANG_NOTIFY_RES_REQ, (oslParaType*) data_ptr, NULL);
}

#ifdef __SATCC__
#ifdef BROWSER_SUPPORT

/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_launch_browser_stage1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_launch_browser_stage1(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmi_lauch_browser_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_launch_browser_struct *launch_browser = &g_srv_sat_proactive_sim[sat_id].cmd_data.launch_browser;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr =
        (wap_mmi_lauch_browser_req_struct*) OslConstructDataPtr(
                                                sizeof(wap_mmi_lauch_browser_req_struct) +
                                                (launch_browser->url_len) * ENCODING_LENGTH +
                                                (launch_browser->bearer_len) * ENCODING_LENGTH +
                                                (launch_browser->gateway_len) * ENCODING_LENGTH);
    data_ptr->browserMode = launch_browser->browser_mode;
    data_ptr->browserIdentity = launch_browser->browser_identity;
    data_ptr->sim_id = sim_id;
    data_ptr->noUrl = launch_browser->url_len;
    data_ptr->url = (PU8) data_ptr + sizeof(wap_mmi_lauch_browser_req_struct);
    if (launch_browser->url_len > 0)
    {
        memcpy(data_ptr->url, launch_browser->url, (launch_browser->url_len) * ENCODING_LENGTH * sizeof(U8));
    }
    data_ptr->noBearer = launch_browser->bearer_len;
    data_ptr->bearer = (PU8) data_ptr->url + (launch_browser->url_len) * ENCODING_LENGTH * sizeof(U8);
    if (launch_browser->bearer_len > 0)
    {
        memcpy(data_ptr->bearer, launch_browser->bearer, (launch_browser->bearer_len) * ENCODING_LENGTH * sizeof(U8));
    }
    data_ptr->noGateway = launch_browser->gateway_len;
    data_ptr->gateway = (PU8) data_ptr->bearer + (launch_browser->bearer_len) * ENCODING_LENGTH * sizeof(U8);
    if (launch_browser->gateway_len > 0)
    {
        memcpy(data_ptr->gateway, launch_browser->gateway, (launch_browser->gateway_len) * ENCODING_LENGTH * sizeof(U8));
    }

    mmi_frm_send_ilm(wap_get_service_module(PRT_WAP_MMI_LAUNCH_BROWSER_REQ), PRT_WAP_MMI_LAUNCH_BROWSER_REQ, (oslParaType*) data_ptr, NULL);
}

#endif /* BROWSER_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_launch_browser_stage2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  additional_res: [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_launch_browser_stage2(
        mmi_sim_enum sim_id,
        srv_sat_terminal_res_enum terminal_res,
        srv_sat_additional_res_enum additional_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_launch_browser_res_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_launch_browser_struct *launch_browser = &g_srv_sat_proactive_sim[sat_id].cmd_data.launch_browser;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_launch_browser_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_launch_browser_res_req_struct));
    memcpy(data_ptr->cmd_detail, launch_browser->cmd_detail, 5 * sizeof(U8));
	data_ptr->res = srv_sat_get_icon_res(terminal_res, launch_browser->icon);

    data_ptr->additional_res = additional_res;

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_LAUNCH_BROWSER_RES_REQ, (oslParaType*) data_ptr, NULL);
}

#endif
#endif /* __SAT_LOWCOST_UI_DISABLE__ */


#ifdef __SATCE__

/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_open_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  additional_res: [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_open_channel(
        mmi_sim_enum sim_id,
        srv_sat_terminal_res_enum terminal_res,
        srv_sat_additional_res_enum additional_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_open_channel_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_open_channel_struct *open_channel = &g_srv_sat_proactive_sim[sat_id].cmd_data.open_channel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_open_channel_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_open_channel_req_struct));
    memcpy(data_ptr->cmd_detail, open_channel->cmd_detail, 5 * sizeof(U8));
    if (terminal_res == SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY &&
        open_channel->icon.id > 0 && !open_channel->icon.available)
    {
        data_ptr->res = SRV_SAT_TERMINAL_RES_CMD_PERFORMED_BUT_ICON_COULD_NOT_DISPLAY;
    }
    else
    {
        data_ptr->res = terminal_res;
    }
    data_ptr->additional_info = additional_res;

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), MSG_ID_MMI_SAT_OPEN_CHANNEL_REQ, (oslParaType*) data_ptr, NULL);
}


#ifdef __SRV_SAT_TR_CLOSE_CHANNEL__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_close_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_close_channel(
        mmi_sim_enum sim_id,
        srv_sat_terminal_res_enum terminal_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_close_channel_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_close_channel_struct *close_channel = &g_srv_sat_proactive_sim[sat_id].cmd_data.close_channel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_close_channel_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_close_channel_req_struct));
    memcpy(data_ptr->cmd_detail, close_channel->cmd_detail, 5 * sizeof(U8));
    if (terminal_res == SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY &&
        close_channel->icon.id > 0 && !close_channel->icon.available)
    {
        data_ptr->res = SRV_SAT_TERMINAL_RES_CMD_PERFORMED_BUT_ICON_COULD_NOT_DISPLAY;
    }
    else
    {
        data_ptr->res = terminal_res;
    }

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), MSG_ID_MMI_SAT_CLOSE_CHANNEL_REQ, (oslParaType*) data_ptr, NULL);
}
#endif /* __SRV_SAT_TR_CLOSE_CHANNEL__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_send_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_send_data(
        mmi_sim_enum sim_id,
        srv_sat_terminal_res_enum terminal_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_data_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_send_data_struct *send_data = &g_srv_sat_proactive_sim[sat_id].cmd_data.send_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_send_data_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_data_req_struct));
    memcpy(data_ptr->cmd_detail, send_data->cmd_detail, 5 * sizeof(U8));
    if (terminal_res == SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY &&
        send_data->icon.id > 0 && !send_data->icon.available)
    {
        data_ptr->res = SRV_SAT_TERMINAL_RES_CMD_PERFORMED_BUT_ICON_COULD_NOT_DISPLAY;
    }
    else
    {
        data_ptr->res = terminal_res;
    }

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), MSG_ID_MMI_SAT_SEND_DATA_REQ, (oslParaType*) data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_receive_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_receive_data(
        mmi_sim_enum sim_id,
        srv_sat_terminal_res_enum terminal_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_recv_data_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_receive_data_struct *receive_data = &g_srv_sat_proactive_sim[sat_id].cmd_data.receive_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_recv_data_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_recv_data_req_struct));
    memcpy(data_ptr->cmd_detail, receive_data->cmd_detail, 5 * sizeof(U8));
    if (terminal_res == SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY &&
        receive_data->icon.id > 0 && !receive_data->icon.available)
    {
        data_ptr->res = SRV_SAT_TERMINAL_RES_CMD_PERFORMED_BUT_ICON_COULD_NOT_DISPLAY;
    }
    else
    {
        data_ptr->res = terminal_res;
    }

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), MSG_ID_MMI_SAT_RECV_DATA_REQ, (oslParaType*) data_ptr, NULL);
}

#endif /* __SATCE__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_envelope_menu_selection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  item_id:        [IN]        
 *  help_request:   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_envelope_menu_selection(mmi_sim_enum sim_id, U8 item_id, MMI_BOOL help_request)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_menu_select_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_menu_select_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_menu_select_req_struct));
    data_ptr->item_id = item_id;
    data_ptr->is_help_info_requested = help_request;

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_MENU_SELECT_REQ, (oslParaType*) data_ptr, NULL);
}


#ifndef __SAT_LOWCOST_UI_DISABLE__

/*****************************************************************************
 * FUNCTION
 *  srv_sat_envelope_idle_screen_available_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_envelope_idle_screen_available_ext(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_envelope_idle_screen_available
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_envelope_idle_screen_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (srv_sim_ctrl_is_available((mmi_sim_enum)(0x01 << i)))
        {
            srv_sat_envelope_idle_screen_available_ext((mmi_sim_enum)(0x01 << i));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_envelope_language_selection_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  lang:           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_envelope_language_selection_ext(mmi_sim_enum sim_id, U8 *lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_language_selection_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_language_selection_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_language_selection_req_struct));
    memcpy(data_ptr->iso639_language, lang, 2 * sizeof(U8));

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_LANGUAGE_SELECTION_REQ, (oslParaType*) data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_envelope_language_selection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lang:           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_envelope_language_selection(U8 *lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(srv_sat_me_language, lang, 2 * sizeof(U8));

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (srv_sim_ctrl_is_available((mmi_sim_enum)(0x01 << i)))
        {
            srv_sat_envelope_language_selection_ext((mmi_sim_enum)(0x01 << i), lang);
        }
    }
}

#ifdef __SATCC__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_envelope_browser_termination
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  cause:          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_envelope_browser_termination(
        mmi_sim_enum sim_id,
        srv_sat_browser_termination_enum cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_evdl_browser_termination_req_struct *data_ptr;
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (mmi_sat_evdl_browser_termination_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_evdl_browser_termination_req_struct));
    data_ptr->browser_termination_cause = cause;

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_EVDL_BROWSER_TERMINATION_REQ, (oslParaType*) data_ptr, NULL);
}
#endif /*SATCC*/
#endif /* __SAT_LOWCOST_UI_DISABLE__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_setup_call_abort_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_setup_call_abort_req(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);
    srv_sat_setup_call_struct *setup_call = &g_srv_sat_proactive_sim[sat_id].cmd_data.setup_call;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_sat_cntx[sat_id].sent == 0 && g_srv_sat_proactive_sim[sat_id].cmd_type == SRV_SAT_CMD_SETUP_CALL)
    {
        if (setup_call->disconnect_cause == SRV_SAT_CALL_DISCONNECT_BEFORE_CONNECT)
        {
            srv_sat_terminal_response_setup_call_stage2(
                sim_id,
                SRV_SAT_TERMINAL_RES_USER_CLEAR_DOWN_CALL_BEFORE_CONNECTION,
                SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
            srv_gcall_sat_notify_mo_fail(0);
        }
        else
        {
            srv_sat_terminal_response_setup_call_stage2(
                sim_id,
                SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
                SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_dtmf_abort_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_send_dtmf_abort_req(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SAT_ABORT_DTMF_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_is_menu_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_is_menu_present(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_sat_do_check(sat_id, SRV_SAT_CHECK_DM_SETTING_EX))
    {
        return MMI_FALSE;
    }

    if (!srv_sim_ctrl_is_available(sim_id))
    {
        return MMI_FALSE;
    }

    return g_srv_sat_cntx[sat_id].setup_menu.present;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_menu_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  WCHAR*
 *****************************************************************************/
const WCHAR* srv_sat_get_menu_title(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_sat_cntx[sat_id].setup_menu.alpha_id &&
        g_srv_sat_cntx[sat_id].setup_menu.alpha_id[0] &&
        g_srv_sat_cntx[sat_id].setup_menu.present)
    {
        return g_srv_sat_cntx[sat_id].setup_menu.alpha_id;
    }
    else
    {
        return (WCHAR*) GetString(STR_ID_SAT_MENU_TITLE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_menu_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  item_index:     [IN]        
 * RETURNS
 *  WCHAR*
 *****************************************************************************/
const WCHAR* srv_sat_get_menu_item(mmi_sim_enum sim_id, S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(item_index < g_srv_sat_cntx[sat_id].setup_menu.num_of_item);
    return g_srv_sat_cntx[sat_id].setup_menu.item_list[item_index].alpha_id;
}





/*****************************************************************************
 * FUNCTION
 *  srv_sat_is_idle_display_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_is_idle_display_present(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_sat_do_check(sat_id, SRV_SAT_CHECK_DM_SETTING_EX))
    {
        return MMI_FALSE;
    }

    if (!srv_sim_ctrl_is_available(sim_id))
    {
        return MMI_FALSE;
    }

    return g_srv_sat_cntx[sat_id].setup_idle_mode_text.present;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_idle_display_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  WCHAR*
 *****************************************************************************/
const WCHAR* srv_sat_get_idle_display_text(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_sat_cntx[sat_id].setup_idle_mode_text.text_string;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_idle_display_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  U8*
 *****************************************************************************/
const U8* srv_sat_get_idle_display_icon(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_sat_cntx[sat_id].setup_idle_mode_text.icon.data;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_call_display_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  WCHAR*
 *****************************************************************************/
const WCHAR* srv_sat_get_call_display_text(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_sat_proactive_sim[sat_id].cmd_data.setup_call.alpha_id2;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_set_call_disconnect_cause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  cause:          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_set_call_disconnect_cause(mmi_sim_enum sim_id, srv_sat_call_disconnect_enum cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_enum sat_id = SIMID_2_SATID(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_sat_proactive_sim[sat_id].cmd_data.setup_call.disconnect_cause = cause;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_session_reset
 * DESCRIPTION
 *  reset SAT session
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_session_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SIM_TOTAL; i ++)
    {
        if ((g_srv_sat_cntx[i].sent == 0) && (g_srv_sat_cntx[i].cmd_type == SRV_SAT_CMD_SELECT_ITEM))
        {
            srv_sat_select_item_struct *item = (srv_sat_select_item_struct *)(&g_srv_sat_proactive_sim[i].cmd_data);
            srv_sat_terminal_response_select_item(
                        (mmi_sim_enum)(1 << i),
                        SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER,
                        item->item_list[0].id);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    srv_sat_callback_struct callback_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < SRV_SAT_MAX_TIMER_TOTAL)
    {
        if (g_srv_sat_timer[i].status == SRV_SAT_TIMER_START)
        {
            g_srv_sat_timer[i].counter++;

            if (g_srv_sat_timer[i].counter == g_srv_sat_timer[i].duration)
            {
                if (srv_sat_timer_run)
                {
                    srv_sat_timer_run--;
                }
                if (g_srv_sat_timer[i].callback)
                {
                    srv_sat_callback_func_ptr callback = g_srv_sat_timer[i].callback;

                    callback_data.result = MMI_TRUE;
                    callback_data.sim_id = g_srv_sat_timer[i].sim_id;
                    callback_data.timer_id = g_srv_sat_timer[i].timer_id;
                    callback_data.user_data = g_srv_sat_timer[i].user_data;
                    memset(&g_srv_sat_timer[i], 0, sizeof(srv_sat_timer_struct));
                    callback(&callback_data);
                }
                else
                {
                    memset(&g_srv_sat_timer[i], 0, sizeof(srv_sat_timer_struct));
                }
            }
        }
        i++;
    }

    if (srv_sat_timer_run)
    {
        StartTimer(SAT_MESSAGE_WAIT_TIMER, 1000, srv_sat_timeout);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_start_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  timer_id:       [IN]        
 *  duration:       [IN]        
 *  callback:       [IN]        
 *  user_data:      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_start_timer(
        mmi_sim_enum sim_id,
        U16 timer_id,
        U16 duration,
        srv_sat_callback_func_ptr callback,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 j = 0;
    U32 free_timer = 0xFF;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (j < srv_sat_timer_run)
    {
        if (g_srv_sat_timer[i].status != SRV_SAT_TIMER_IDLE)
        {
            if (g_srv_sat_timer[i].sim_id == sim_id && g_srv_sat_timer[i].timer_id == timer_id)
            {
                free_timer = i;
                break;
            }
            j++;

            if (j == srv_sat_timer_run)
            {
                free_timer = j;
            }
        }
        else if (free_timer == 0xFF)
        {
            free_timer = i;
            break;
        }
        i++;
    }

    if (srv_sat_timer_run == 0)
    {
        free_timer = 0;
        memset(g_srv_sat_timer, 0, sizeof(srv_sat_timer_struct) * SRV_SAT_MAX_TIMER_TOTAL);
        StartTimer(SAT_MESSAGE_WAIT_TIMER, 1000, srv_sat_timeout);
    }

    if (free_timer >= SRV_SAT_MAX_TIMER_TOTAL)
    {
        return;
    }

    g_srv_sat_timer[free_timer].sim_id = sim_id;
    g_srv_sat_timer[free_timer].timer_id = timer_id;
    g_srv_sat_timer[free_timer].duration = duration;
    g_srv_sat_timer[free_timer].counter = 0;
    g_srv_sat_timer[free_timer].status = SRV_SAT_TIMER_START;
    g_srv_sat_timer[free_timer].callback = callback;
    g_srv_sat_timer[free_timer].user_data = user_data;
    srv_sat_timer_run++;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_stop_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  timer_id:       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_stop_timer(mmi_sim_enum sim_id, U16 timer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 j = 0;
    srv_sat_callback_struct callback_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (j < srv_sat_timer_run)
    {
        if (g_srv_sat_timer[i].status != SRV_SAT_TIMER_IDLE)
        {
            if (g_srv_sat_timer[i].sim_id == sim_id && g_srv_sat_timer[i].timer_id == timer_id)
            {
                if (srv_sat_timer_run)
                {
                    srv_sat_timer_run--;
                }
                if (g_srv_sat_timer[i].callback)
                {
                    srv_sat_callback_func_ptr callback = g_srv_sat_timer[i].callback;

                    callback_data.result = MMI_FALSE;
                    callback_data.sim_id = g_srv_sat_timer[i].sim_id;
                    callback_data.timer_id = g_srv_sat_timer[i].timer_id;
                    callback_data.user_data = g_srv_sat_timer[i].user_data;
                    memset(&g_srv_sat_timer[i], 0, sizeof(srv_sat_timer_struct));
                    callback(&callback_data);
                }
                else
                {
                    memset(&g_srv_sat_timer[i], 0, sizeof(srv_sat_timer_struct));
                }
                break;
            }
            j++;
        }
        i++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_pause_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  timer_id:       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_pause_timer(mmi_sim_enum sim_id, U16 timer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (j < srv_sat_timer_run)
    {
        if (g_srv_sat_timer[i].status != SRV_SAT_TIMER_IDLE)
        {
            if (g_srv_sat_timer[i].sim_id == sim_id && g_srv_sat_timer[i].timer_id == timer_id)
            {
                g_srv_sat_timer[i].status = SRV_SAT_TIMER_PAUSE;
                break;
            }
            j++;
        }
        i++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_resume_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  timer_id:       [IN]        
 *  is_reset:       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_resume_timer(mmi_sim_enum sim_id, U16 timer_id, MMI_BOOL is_reset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (j < srv_sat_timer_run)
    {
        if (g_srv_sat_timer[i].status != SRV_SAT_TIMER_IDLE)
        {
            if (g_srv_sat_timer[i].sim_id == sim_id && g_srv_sat_timer[i].timer_id == timer_id)
            {
                g_srv_sat_timer[i].status = SRV_SAT_TIMER_START;
                if (is_reset)
                {
                    g_srv_sat_timer[i].counter = 0;
                }
                break;
            }
            j++;
        }
        i++;
    }
}

#endif /* SATSRV_C */
