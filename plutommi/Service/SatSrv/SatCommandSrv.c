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
 *  SatCommandSrv.c
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
#ifndef SATCOMMANDSRV_C
#define SATCOMMANDSRV_C

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_msg_struct.h"
#include "ps_public_struct.h"
#include "resource_audio.h"
#include "mmi_rp_srv_sat_def.h"
#include "custom_srv_prof_defs.h"
#include "TimerEvents.h"
#include "sim_common_enums.h"

#include "SatSrvGprot.h"
#include "SatSrv.h"
#include "GSM7BitDefaultAlphabet.h"
#include "sim_public_api.h"
#include "sat_def.h"
#include "custom_ecc.h"
#include "UcmSrvGprot.h"
#include "GCallSrvGprot.h"
#include "NwInfoSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "SimAccessSrvGprot.h"
#include "PhbSrvGprot.h"
#include "CphsSrvGprot.h"
#include "ProfilesSrvGprot.h"
#include "NetSetSrvGprot.h"
#include "GeneralSettingSrvGprot.h"

#ifdef BROWSER_SUPPORT
#include "browser_api.h"
#endif

#if (MMI_MAX_SIM_NUM >=2)
#include "ps_public_utility.h"
#endif


/* 
 * Local Function
 */


/*****************************************************************************
 * FUNCTION
 *  ADD_TO_CACHE
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]        
 *  len         [IN]        
 *  dcs         [IN]        
 *  cache_data  [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
static U16 ADD_TO_CACHE(U8 *data, U16 len, U8 dcs, WCHAR *cache_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *convert_data;
    U16 convert_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    convert_data = CovertStringForPlatform(data, len, dcs, &convert_len);
    memcpy(cache_data, convert_data, convert_len);
    OslMfree(convert_data);
    return convert_len / 2;
}


/*****************************************************************************
 * FUNCTION
 *  ADD_TO_ICON
 * DESCRIPTION
 *  
 * PARAMETERS
 *  available   [IN]        
 *  id          [IN]        
 *  attr        [IN]        
 *  icon        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void ADD_TO_ICON(MMI_BOOL available, U8 id, srv_sat_icon_enum attr, srv_sat_icon_struct *icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (available)
    {
    #ifndef __SAT_DISABLE_ICON_SUPPORT__
        icon->available = available;
    #else
        icon->available = MMI_FALSE;
    #endif /* __SAT_DISABLE_ICON_SUPPORT__ */

        icon->id = id;
        icon->attr = attr;
    }
}


/*****************************************************************************
 * FUNCTION
 *  DO_ALPHA
 * DESCRIPTION
 *  
 * PARAMETERS
 *  present     [IN]        
 *  alpha_id    [IN]        
 *  len         [IN]        
 *  dcs         [IN]        
 * RETURNS
 *  WCHAR*
 *****************************************************************************/
static WCHAR *DO_ALPHA(MMI_BOOL present, U8 *alpha_id, U16 len, U8 dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *alpha_data, *convert_data;
    U16 alpha_len, convert_len;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (present)
    {
        if (dcs == MMI_UCS2_DCS)
        {
            if (len % ENCODING_LENGTH)
            {
                len--;
                if (*alpha_id == 0x80 && len > 0)
                {
                    alpha_data = (U8*) OslMalloc(len + ENCODING_LENGTH);
                    for (i = 0; i < len; i++)
                    {
                        *(alpha_data + i) = *(alpha_id + i + 1);
                    }
                    convert_data = CovertStringForPlatform(alpha_data, len, dcs, &convert_len);
                    OslMfree(alpha_data);
                    return (WCHAR*) convert_data;
                }
            }
        }
        return (WCHAR*) CovertStringForPlatform(alpha_id, len, dcs, &alpha_len);
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  DO_ALPHA_EX
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string_id   [IN]        
 * RETURNS
 *  WCHAR*
 *****************************************************************************/
static WCHAR *DO_ALPHA_EX(U16 string_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *alpha_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    alpha_id = (WCHAR *)OslMalloc(mmi_ucs2strlen(GetString(string_id)) * ENCODING_LENGTH + ENCODING_LENGTH);
    mmi_ucs2cpy((CHAR *)alpha_id, GetString(string_id));
    return alpha_id;
}


/*****************************************************************************
 * FUNCTION
 *  DO_TEXT
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text_string [IN]        
 *  len         [IN]        
 *  dcs         [IN]        
 * RETURNS
 *  WCHAR*
 *****************************************************************************/
static WCHAR *DO_TEXT(U8 *text_string, U16 len, U8 dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *text_data, *convert_data;
    U16 text_len, convert_len;
    U32 i, j = 0;
    MMI_BOOL remove = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dcs == MMI_8BIT_DCS)
    {
        dcs = MMI_DEFAULT_DCS;
    }

    if (dcs == MMI_UCS2_DCS)
    {
        if (len % ENCODING_LENGTH)
        {
            len--;
            remove = MMI_TRUE;
        }
        if (len > 0)
        {
            text_data = (U8*) OslMalloc(len + ENCODING_LENGTH);
            if (*text_string == 0x80 && remove)
            {
                for (i = 0; i < len; i++)
                {
                    *(text_data + i) = *(text_string + i + 1);
                }
            }
            else
            {
                memcpy(text_data, text_string, len);
            }
            for (i = 0; i < len; i += 2)
            {
                if ((text_data[i] | text_data[i + 1] << 8) != 0xFFFF)
                {
                    text_data[j++] = text_data[i];
                    text_data[j++] = text_data[i + 1];
                }
            }
            //convert_data = CovertStringForPlatform(text_data, j, dcs, &convert_len);
            //OslMfree(text_data);
            //return (WCHAR*) convert_data;
        }
    }
    else
    {
        if (len > 0)
        {
            text_data = (U8*) OslMalloc(len + 1);
            for (i = 0; i < len; i++)
            {
                if (text_string[i] != 0xFF)
                {
                    text_data[j++] = text_string[i];
                }
            }

            //convert_data = CovertStringForPlatform(text_data, j, dcs, &convert_len);
            //OslMfree(text_data);
            //return (WCHAR*) convert_data;
        }
    }
	if(len > 0)
	{

            convert_data = CovertStringForPlatform(text_data, j, dcs, &convert_len);
            OslMfree(text_data);
            return (WCHAR*) convert_data;

    }

    return (WCHAR*) CovertStringForPlatform(text_string, len, dcs, &text_len);
}


/*****************************************************************************
 * FUNCTION
 *  DO_MENU_ITEM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id               [IN]
 *  cmd_type          [IN]
 *  context             [IN]
 *  item_num           [IN]
 *  item_data          [IN]
 *  hint_num           [IN]
 *  hint_list            [IN]
 *  icon_num          [IN]
 *  icon_id_list        [IN]
 *  icon_list_attr     [IN]
 * RETURNS
 *  srv_sat_item_struct*
 *****************************************************************************/
static srv_sat_item_struct *DO_MENU_ITEM(
                                srv_sat_enum sat_id,
                                srv_sat_cmd_enum cmd_type,
                                srv_sat_cntx_struct *context,
                                S32 item_num,
                                U8 *item_data,
                                S32 hint_num,
                                U8 *hint_list,
                                S32 icon_num,
                                U8 *icon_id_list,
                                srv_sat_icon_enum icon_list_attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_item_struct *item_list, *item;
    U8 *item_data_ptr;
    S32 i;
    U16 len;
    U8 dcs;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_list = (srv_sat_item_struct *)OslMalloc(item_num * sizeof(srv_sat_item_struct));

    item = item_list;
    item_data_ptr = item_data;
    for (i = 0; i < item_num; i++, item++)
    {
        memset(item, 0, sizeof(srv_sat_item_struct));
        item_data_ptr++;
        len = *item_data_ptr++;
        item->id = *item_data_ptr++;
        dcs = *item_data_ptr++;
        if (len != 0)
        {
            if (cmd_type == SRV_SAT_CMD_SETUP_MENU)
            {
                item->alpha_id = context->cache.data + context->cache.len;
                context->cache.len += ADD_TO_CACHE(item_data_ptr, len, dcs, context->cache.data + context->cache.len);
            }
            else    /* SRV_SAT_CMD_SELECT_ITEM*/
            {
                item->alpha_id = DO_ALPHA(MMI_TRUE, item_data_ptr, len, dcs);
            }
            item_data_ptr += len;
        }
        else
        {
            item->alpha_id = NULL;
        }

#if (MMI_MAX_SIM_NUM >= 2)
        if (is_test_sim(l4c_gemini_get_switched_sim_id((sim_interface_enum)sat_id)))
#else
        if (is_test_sim())
#endif
        {
            if (hint_num > 0)
            {
                switch (hint_list[i])
                {
                    case 0x10:
                        item->next_action_ind = SRV_SAT_CMD_SETUP_CALL;
                        break;

                    case 0x13:
                        item->next_action_ind = SRV_SAT_CMD_SEND_SMS;
                        break;

                    case 0x15:
                        item->next_action_ind = SRV_SAT_CMD_LAUNCH_BROWSER;
                        break;

                    case 0x26:
                        item->next_action_ind = SRV_SAT_CMD_PROVIDE_LOCAL_INFORMATION;
                        break;

                    default:
                        item->next_action_ind = SRV_SAT_CMD_NONE;
                        break;
                }
            }
        }

        if (icon_num > 0)
        {
            ADD_TO_ICON(MMI_TRUE, icon_id_list[i], icon_list_attr, &item->icon);
        }
    }

    return item_list;
}


U8* srv_sat_malloc_with_len(kal_uint8 dest_len, kal_uint8* dest)
{
	U8* source = NULL;
    if (dest_len > 0)
    {
        source = (U8*) OslMalloc(dest_len * sizeof(U8));
        memcpy(source, dest, dest_len);
    }
	return source;

}

/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_sim_refresh_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  full_change [IN]        
 *  refresh_type[IN]        
 *  num_of_file [IN]        
 *  file_list   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_sim_refresh_event(
                srv_sat_enum sat_id,
                MMI_BOOL full_change,
                srv_sat_refresh_enum refresh_type,
                S32 num_of_file,
                U16 *file_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_sim_refresh_event_struct event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&event, EVT_ID_SRV_SAT_SIM_REFRESH);
    event.sim_id = SATID_2_SIMID(sat_id);
    event.full_change = full_change;
    event.refresh_type = refresh_type;
    event.num_of_file = num_of_file;
    memcpy(event.file_list, file_list, 120 * sizeof(U16));
    MMI_FRM_CB_EMIT_EVENT(&event);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_sim_ctrl_info_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN] 
 *  alpha_id   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_send_sim_ctrl_info_event(WCHAR *alpha_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_sim_ctrl_info_event_struct event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&event, EVT_ID_SRV_SAT_SIM_CTRL_INFO);
    event.alpha_id = alpha_id;
    MMI_FRM_CB_EMIT_EVENT(&event);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  check_type:     [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_do_check(srv_sat_enum sat_id, srv_sat_check_enum check_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_id = SATID_2_SIMID(sat_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_sim_ctrl_is_available(sim_id))
    {
        return MMI_FALSE;
    }

    if ((check_type & SRV_SAT_CHECK_FLIGHT_MODE) == SRV_SAT_CHECK_FLIGHT_MODE)
    {
        if (!srv_mode_switch_is_network_service_available())
        {
            return MMI_FALSE;
        }
    }

    if ((check_type & SRV_SAT_CHECK_DM_SETTING) == SRV_SAT_CHECK_DM_SETTING)
    {
        if (srv_mode_switch_get_network_mode(sim_id) != SRV_MODE_SWITCH_ON)
        {
            return MMI_FALSE;
        }
    }

    if ((check_type & SRV_SAT_CHECK_NW_REG_STATUS) == SRV_SAT_CHECK_NW_REG_STATUS)
    {
        if (srv_nw_info_sim_is_rejected(sim_id))
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data_ptr:       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_do_free(void *data_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_ptr)
    {
        OslMfree(data_ptr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_display_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  display_text:   [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_do_display_text(
            srv_sat_enum sat_id,
            srv_sat_cntx_struct *context,
            srv_sat_display_text_struct *display_text,
            void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_display_text_ind_struct *sim_ind;
    mmi_sim_enum sim_id = SATID_2_SIMID(sat_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ind = (mmi_sat_display_text_ind_struct*) info;

    memset(display_text, 0, sizeof(srv_sat_display_text_struct));
    memcpy(display_text->cmd_detail, sim_ind->cmd_detail, 5 * sizeof(U8));

    if (context->cmd_type == SRV_SAT_CMD_SEND_SS_RETURN_RESULT ||
        context->cmd_type == SRV_SAT_CMD_SEND_USSD_RETURN_RESULT)
    {
        srv_sat_terminal_response_display_text(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY,
            SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
        return MMI_FALSE;
    }

    if (!srv_sat_do_check(sat_id, SRV_SAT_CHECK_DM_SETTING_EX))
    {
        srv_sat_terminal_response_display_text(
            sim_id,
            SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
            SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
        return MMI_FALSE;
    }

    /* If the ME receives an icon and either an empty, or no, alpha identifier/text string is given by
       the SIM, than the ME shall reject the command with general result "Command data not understood by ME". */
    if (sim_ind->is_icon_available && !sim_ind->no_text_string)
    {
        srv_sat_terminal_response_display_text(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_DATA_NOT_UNDERSTAND_BY_ME,
            SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
        return MMI_FALSE;
    }

    display_text->priority = (srv_sat_priority_enum) sim_ind->priority;
    display_text->clear_type = (srv_sat_clear_enum) sim_ind->clear_text_type;
    display_text->immediate_res = (MMI_BOOL) sim_ind->immediate_res;

    display_text->text_string =
        DO_TEXT(sim_ind->text_string, sim_ind->no_text_string, sim_ind->dcs_of_text_string);

    ADD_TO_ICON(
        (MMI_BOOL) sim_ind->is_icon_available, sim_ind->icon_info.icon_id,
        (srv_sat_icon_enum) sim_ind->icon_info.icon_attr, &display_text->icon);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_get_inkey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  get_inkey:      [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_do_get_inkey(
            srv_sat_enum sat_id,
            srv_sat_cntx_struct *context,
            srv_sat_get_inkey_struct *get_inkey,
            void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_get_inkey_ind_struct *sim_ind;
    mmi_sim_enum sim_id = SATID_2_SIMID(sat_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ind = (mmi_sat_get_inkey_ind_struct*) info;

    memset(get_inkey, 0, sizeof(srv_sat_get_inkey_struct));
    memcpy(get_inkey->cmd_detail, sim_ind->cmd_detail, 5 * sizeof(U8));

    if (!srv_sat_do_check(sat_id, SRV_SAT_CHECK_DM_SETTING_EX))
    {
        srv_sat_terminal_response_get_inkey(
            sim_id,
            SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
            MMI_FALSE,
            NULL);
        return MMI_FALSE;
    }

    /* If the ME receives an icon and either an empty, or no, alpha identifier/text string is given by
       the SIM, than the ME shall reject the command with general result "Command data not understood by ME". */
    if (sim_ind->is_icon_available && !sim_ind->no_text_string)
    {
        srv_sat_terminal_response_get_inkey(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_DATA_NOT_UNDERSTAND_BY_ME,
            MMI_FALSE,
            NULL);
        return MMI_FALSE;
    }

    if (sim_ind->type_of_input == TYPE_ONLY_DIGIT_UCS2)
    {
        get_inkey->input_type = SRV_SAT_INPUT_DIGIT_ONLY;
    }
    else
    {
        get_inkey->input_type = (srv_sat_input_enum) sim_ind->type_of_input;
    }

	get_inkey->dcs_type = get_inkey->cmd_detail[4] & 0x06 == 0x02 ? SRV_SAT_DCS_UCS2 : SRV_SAT_DCS_8BIT;
	
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    get_inkey->help_available = (MMI_BOOL) sim_ind->is_help_info_available;

    get_inkey->text_string =
        DO_TEXT(sim_ind->text_string, sim_ind->no_text_string, sim_ind->dcs_of_text_string);

    ADD_TO_ICON(
        (MMI_BOOL) sim_ind->is_icon_available, sim_ind->icon_info.icon_id,
        (srv_sat_icon_enum) sim_ind->icon_info.icon_attr, &get_inkey->icon);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_get_input
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  get_input:      [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_do_get_input(
            srv_sat_enum sat_id,
            srv_sat_cntx_struct *context,
            srv_sat_get_input_struct *get_input,
            void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_get_input_ind_struct *sim_ind;
    mmi_sim_enum sim_id = SATID_2_SIMID(sat_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ind = (mmi_sat_get_input_ind_struct*) info;

    memset(get_input, 0, sizeof(srv_sat_get_input_struct));
    memcpy(get_input->cmd_detail, sim_ind->cmd_detail, 5 * sizeof(U8));

    if (!srv_sat_do_check(sat_id, SRV_SAT_CHECK_DM_SETTING_EX))
    {
        srv_sat_terminal_response_get_input(
            sim_id,
            SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
            NULL);
        return MMI_FALSE;
    }

    /* If the ME receives an icon and either an empty, or no, alpha identifier/text string is given by
       the SIM, than the ME shall reject the command with general result "Command data not understood by ME". */
    if (sim_ind->is_icon_available && !sim_ind->no_text_string)
    {
        srv_sat_terminal_response_get_input(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_DATA_NOT_UNDERSTAND_BY_ME,
            NULL);
        return MMI_FALSE;
    }

    if (sim_ind->type_of_input == TYPE_ONLY_DIGIT_UCS2)
    {
        get_input->input_type = SRV_SAT_INPUT_DIGIT_ONLY;
    }
    else
    {
        get_input->input_type = (srv_sat_input_enum) sim_ind->type_of_input;
    }

    if (!(get_input->cmd_detail[4] & 0x02))
    {
        if (!(get_input->cmd_detail[4] & 0x08))
        {
            get_input->dcs_type = SRV_SAT_DCS_8BIT;
        }
        else
        {
            get_input->dcs_type = SRV_SAT_DCS_SMS_DEFAULT;
        }
    }
    else
    {
        get_input->dcs_type = SRV_SAT_DCS_UCS2;
    }

    get_input->echo_mode = (MMI_BOOL) sim_ind->is_input_revealed_to_user;
    get_input->min_length = sim_ind->len_of_min_input;
    get_input->max_length = sim_ind->len_of_max_input;
    get_input->help_available = (MMI_BOOL) sim_ind->is_help_info_available;

    get_input->text_string =
        DO_TEXT(sim_ind->text_string, sim_ind->no_text_string, sim_ind->dcs_of_text_string);

    get_input->default_text =
        DO_TEXT(sim_ind->default_text, sim_ind->no_default_text, sim_ind->dcs_of_default_text);

    ADD_TO_ICON(
        (MMI_BOOL) sim_ind->is_icon_available, sim_ind->icon_info.icon_id,
        (srv_sat_icon_enum) sim_ind->icon_info.icon_attr, &get_input->icon);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_play_tone_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback_data:  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_do_play_tone_hdlr(srv_sat_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(callback_data && callback_data->result);
    srv_prof_stop_tone(SRV_PROF_TONE_SAT);
    srv_sat_terminal_response_play_tone(callback_data->sim_id, SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_play_tone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  play_tone:      [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_do_play_tone(
            srv_sat_enum sat_id,
            srv_sat_cntx_struct *context,
            srv_sat_play_tone_struct *play_tone,
            void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_play_tone_ind_struct *sim_ind;
    mmi_sim_enum sim_id = SATID_2_SIMID(sat_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ind = (mmi_sat_play_tone_ind_struct*) info;

    memset(play_tone, 0, sizeof(srv_sat_play_tone_struct));
    memcpy(play_tone->cmd_detail, sim_ind->cmd_detail, 5 * sizeof(U8));

    if (!srv_sat_do_check(sat_id, SRV_SAT_CHECK_DM_SETTING_EX))
    {
        srv_sat_terminal_response_play_tone(
            sim_id,
            SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD);
        return MMI_FALSE;
    }

    /* If the ME receives an icon and either an empty, or no, alpha identifier/text string is given by
       the SIM, than the ME shall reject the command with general result "Command data not understood by ME". */
    if (sim_ind->is_icon_available && !sim_ind->no_alpha_id)
    {
        srv_sat_terminal_response_play_tone(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_DATA_NOT_UNDERSTAND_BY_ME);
        return MMI_FALSE;
    }

    /* If the ME is in, or is setting up a speech call, it shall superimpose the tone on top of the downlink
       audio (if any), for the duration given in the command. */

    play_tone->tone = TONE_GENERAL_BEEP;    /* default value */

    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, NULL) > 0)
    {
        if (sim_ind->tone_id > 0 && sim_ind->tone_id <= SAT_TONE_NEG_ACK)
        {
            /* refer to sat_tone_id_enum */
            audio_id_enum tone[] =
                    {
                        TONE_GENERAL_BEEP, /* 0x00 */
                        TONE_DIAL_CALL_GSM,
                        TONE_BUSY_CALL_GSM,
                        TONE_CONGESTION_GSM,
                        TONE_RADIO_PATH,
                        TONE_RADIO_NA,
                        TONE_ERROR_INFO,
                        TONE_CALL_WAITING,
                        TONE_RINGING_CALL_GSM,
                        TONE_GENERAL_BEEP, /* 0x09 */
                        TONE_GENERAL_BEEP,
                        TONE_GENERAL_BEEP,
                        TONE_GENERAL_BEEP,
                        TONE_GENERAL_BEEP,
                        TONE_GENERAL_BEEP,
                        TONE_GENERAL_BEEP, /* 0x0F */
                        TONE_GENERAL_BEEP, /* 0x10 */
                        TONE_POSITIVE_ACK,
                        TONE_NEGATIVE_ACK,
                    };

            play_tone->tone = tone[sim_ind->tone_id];
        }
    }
    else
    {
        if (sim_ind->tone_id > 0 && sim_ind->tone_id <= SAT_TONE_NEG_ACK)
        {
            /* refer to sat_tone_id_enum */
            audio_id_enum tone[] =
                    {
                        TONE_GENERAL_BEEP, /* 0x00 */
                        TONE_DIAL_CALL_GSM_STK,
                        TONE_BUSY_CALL_GSM_STK,
                        TONE_CONGESTION_GSM_STK,
                        TONE_RADIO_PATH_STK,
                        TONE_RADIO_NA_STK,
                        TONE_ERROR_INFO_STK,
                        TONE_CALL_WAITING_STK,
                        TONE_RINGING_CALL_GSM_STK,
                        TONE_GENERAL_BEEP, /* 0x09 */
                        TONE_GENERAL_BEEP,
                        TONE_GENERAL_BEEP,
                        TONE_GENERAL_BEEP,
                        TONE_GENERAL_BEEP,
                        TONE_GENERAL_BEEP,
                        TONE_GENERAL_BEEP, /* 0x0F */
                        TONE_GENERAL_BEEP, /* 0x10 */
                        TONE_POSITIVE_ACK_STK,
                        TONE_NEGATIVE_ACK_STK,
                    };

            play_tone->tone = tone[sim_ind->tone_id];
        }
    }

    play_tone->duration = (U16) (sim_ind->duration / 1000);
    if (play_tone->duration == 0)
    {
        /* If no duration is specified, the ME shall default to a duration determined by the ME manufacturer. */
        play_tone->duration = 1;
    }

    play_tone->alpha_id =
        DO_ALPHA((MMI_BOOL) sim_ind->is_alpha_id_present, sim_ind->alpha_id, sim_ind->no_alpha_id, sim_ind->dcs_of_alpha_id);
    if (!play_tone->alpha_id)
    {
        play_tone->alpha_id = DO_ALPHA_EX(STR_ID_SAT_PLAY_TONE);
    }
    else if (!play_tone->alpha_id[0])
    {
    #ifdef __MMI_SILENT_MEETING_PROFILE__
        if (!(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == SRV_PROF_RET_PROFILE_ACTIVATED) &&
            !(srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE) == SRV_PROF_RET_PROFILE_ACTIVATED))
    #else
        if (!(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == SRV_PROF_RET_PROFILE_ACTIVATED))
    #endif
        {
            srv_prof_play_tone_with_id(SRV_PROF_TONE_SAT, play_tone->tone, SRV_PROF_RING_TYPE_REPEAT, NULL);
        }

        srv_sat_start_timer(sim_id, SAT_PLAY_TONE_TIMER, play_tone->duration, srv_sat_do_play_tone_hdlr, NULL);
        return MMI_FALSE;
    }

    ADD_TO_ICON(
        (MMI_BOOL) sim_ind->is_icon_available, sim_ind->icon_info.icon_id,
        (srv_sat_icon_enum) sim_ind->icon_info.icon_attr, &play_tone->icon);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_cphs_network_dummy_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret srv_sat_cphs_network_dummy_func(mmi_event_struct *param)
{
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_read_sim_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_do_read_sim_hdlr(srv_sim_cb_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_data_struct *sim_data;
    mmi_cphs_mmi_info_ind_struct cphs_info;
    U8 csp_data[22];
    U8 alpha_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_data = (srv_sim_data_struct*) param->data;

    if (param->result)
    {
        switch ((S32) param->user_data)
        {
            case FILE_MSISDN_IDX:
                memset(&cphs_info, 0, sizeof(mmi_cphs_mmi_info_ind_struct));

                cphs_info.no_msisdn = 1;

                if (sim_data->data[0] >= 0x80 && sim_data->data[0] <= 0x82)
                {
                    for (alpha_len = 0; *(sim_data->data + 1 + alpha_len) != 0xFF; alpha_len++);
                    cphs_info.msisdn[0].alpha_id_size = alpha_len;
                    cphs_info.msisdn[0].alpha_id_dcs = MMI_UCS2_DCS + sim_data->data[0] - 0x80;
                    memcpy(cphs_info.msisdn[0].alpha_id, sim_data->data + 1, alpha_len);
                }
                else
                {
                    for (alpha_len = 0; *(sim_data->data + alpha_len) != 0xFF; alpha_len++);
                    cphs_info.msisdn[0].alpha_id_size = alpha_len;
                    cphs_info.msisdn[0].alpha_id_dcs = MMI_DEFAULT_DCS;
                    memcpy(cphs_info.msisdn[0].alpha_id, sim_data->data, alpha_len);
                }

                cphs_info.msisdn[0].alpha_id[alpha_len] = 0;
                cphs_info.msisdn[0].ton_npi = *(sim_data->data + sim_data->length - 13);

                cphs_info.msisdn[0].digit_size =
                    (U8) srv_phb_convert_to_digit(cphs_info.msisdn[0].digit, sim_data->data + sim_data->length - 12, 41);

                srv_cphs_parse_msisdn_info(cphs_info.no_msisdn, cphs_info.msisdn, param->sim_id);
                break;

            case FILE_CSP_IDX:
                memcpy(csp_data, sim_data->data, sim_data->length);
                srv_cphs_parse_csp_info(csp_data, param->sim_id);
                srv_sat_terminal_response_refresh(param->sim_id);

                /* change networek selection mode to auto */
                if (srv_netset_get_nw_selection_mode(param->sim_id) != SRV_NETSET_AUTO_SEL)
                {
                    srv_netset_set_nw_selection_mode(param->sim_id, SRV_NETSET_AUTO_SEL, srv_sat_cphs_network_dummy_func, NULL);
                }

                break;

            default:
                break;
        }
    }

    if (!param->result && ((S32)param->user_data) == FILE_CSP_IDX)
    {
        srv_sat_terminal_response_refresh(param->sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_read_file_info_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_do_read_file_info_hdlr(srv_sim_cb_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_file_info_struct *sim_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_info = (srv_sim_file_info_struct*) param->data;

    if (param->result)
    {
        switch ((S32) param->user_data)
        {
            case FILE_MSISDN_IDX:
                if (sim_info->file_size && sim_info->num_of_rec)
                {
                    srv_sim_read_record(
                        FILE_MSISDN_IDX,
                        NULL,
                        1,
                        sim_info->file_size / sim_info->num_of_rec,
                        param->sim_id,
                        srv_sat_do_read_sim_hdlr,
                        (void*) FILE_MSISDN_IDX);
                }
                break;

            case FILE_CSP_IDX:
                if (sim_info->file_size)
                {
                    srv_sim_read_binary(
                        FILE_CSP_IDX,
                        NULL,
                        0,
                        sim_info->file_size,
                        param->sim_id,
                        srv_sat_do_read_sim_hdlr,
                        (void*) FILE_CSP_IDX);
                }
                break;

            default:
                break;
        }
    }

    if (!param->result && ((S32)param->user_data) == FILE_CSP_IDX)
    {
        srv_sat_terminal_response_refresh(param->sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_refresh
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  refresh:        [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_do_refresh(
            srv_sat_enum sat_id,
            srv_sat_cntx_struct *context,
            srv_sat_refresh_struct *refresh,
            void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_sim_file_change_ind_struct *sim_ind;
    S32 i;
    MMI_BOOL csp_exist = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ind = (mmi_sat_sim_file_change_ind_struct*) info;

    refresh->refresh_type = (srv_sat_refresh_enum) sim_ind->refresh_type;

    if (refresh->refresh_type != SRV_SAT_REFRESH_FILE_CHANGE)
    {
        context->setup_idle_mode_text.present = MMI_FALSE;
        srv_sat_do_free(context->setup_idle_mode_text.text_string);
        context->setup_idle_mode_text.text_string = NULL;
        srv_sat_do_free(context->setup_idle_mode_text.icon.data);
        context->setup_idle_mode_text.icon.data = NULL;
        srv_sat_send_setup_idle_display_event(sat_id, MMI_FALSE);
    }

#ifndef __SIM_RESET_BY_SIM__
    if (refresh->refresh_type == SRV_SAT_REFRESH_RESET)
    {
        return MMI_TRUE;
    }
#endif

    srv_sat_send_sim_refresh_event(
        sat_id,
        (MMI_BOOL) sim_ind->is_full_changed,
        (srv_sat_refresh_enum) sim_ind->refresh_type,
        sim_ind->num_of_file,
        sim_ind->file_list);

    if (sim_ind->refresh_type == SRV_SAT_REFRESH_FILE_CHANGE)
    {
        for (i = 0; i < sim_ind->num_of_file; i++)
        {
            switch (sim_ind->file_list[i])
            {
                case FILE_MSISDN_IDX:
                    srv_sim_get_file_info(
                        FILE_MSISDN_IDX,
                        NULL,
                        SATID_2_SIMID(sat_id),
                        srv_sat_do_read_file_info_hdlr,
                        (void*) FILE_MSISDN_IDX);
                    break;

                case FILE_CSP_IDX:
                    csp_exist = MMI_TRUE;
                    srv_sim_get_file_info(
                        FILE_CSP_IDX,
                        NULL,
                        SATID_2_SIMID(sat_id),
                        srv_sat_do_read_file_info_hdlr,
                        (void*) FILE_CSP_IDX);
                    break;

                default:
                    break;
            }
        }
    }

    if (sim_ind->is_full_changed)
    {
        csp_exist = MMI_TRUE;
        srv_sim_get_file_info(FILE_MSISDN_IDX, NULL, SATID_2_SIMID(sat_id), srv_sat_do_read_file_info_hdlr, (void *)FILE_MSISDN_IDX);
        srv_sim_get_file_info(FILE_CSP_IDX, NULL, SATID_2_SIMID(sat_id), srv_sat_do_read_file_info_hdlr, (void *)FILE_CSP_IDX);
    }

    if (!csp_exist)
    {
        srv_sat_terminal_response_refresh(SATID_2_SIMID(sat_id));
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_setup_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  setup_menu:     [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_do_setup_menu(
            srv_sat_enum sat_id,
            srv_sat_cntx_struct *context,
            srv_sat_setup_menu_struct *setup_menu,
            void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_setup_menu_ind_struct *sim_ind;
    mmi_sim_enum sim_id = SATID_2_SIMID(sat_id);
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ind = (mmi_sat_setup_menu_ind_struct*) info;
// TODO:

    for (i = 0; i < setup_menu->num_of_item; i++)
    {
        if (!setup_menu->item_list[i].icon.copy_only)
        {
            srv_sat_do_free(setup_menu->item_list[i].icon.data);
        }
        setup_menu->item_list[i].icon.data = NULL;
    }
	
    srv_sat_do_free(setup_menu->item_list);
    setup_menu->item_list = NULL;
    srv_sat_do_free(setup_menu->icon.data);
    setup_menu->icon.data = NULL;
    setup_menu->icon.available = MMI_FALSE;

    if (context->cache.len > 0)
    {
        memset(context->cache.data, 0, 256 * sizeof(WCHAR));
        context->cache.len = 0;
    }

    memcpy(setup_menu->cmd_detail, sim_ind->cmd_detail, 5 * sizeof(U8));

    setup_menu->num_of_item = sim_ind->num_of_item;
    if (setup_menu->num_of_item == 0)
    {
        setup_menu->present = MMI_FALSE;
        return MMI_FALSE;
    }

    setup_menu->help_available = (MMI_BOOL) sim_ind->is_help_info_available;
    setup_menu->alpha_id = context->cache.data;
    context->cache.len =
        ADD_TO_CACHE(sim_ind->alpha_id, sim_ind->no_alpha_id, sim_ind->dcs_of_alpha_id, context->cache.data);

    setup_menu->item_list = DO_MENU_ITEM(
                                sat_id,
                                SRV_SAT_CMD_SETUP_MENU,
                                context,
                                setup_menu->num_of_item,
                                sim_ind->item_data,
                                (S32)sim_ind->no_next_action_ind_list,
                                sim_ind->next_action_ind_list,
                                (S32)sim_ind->no_item_icon_id_list,
                                sim_ind->item_icon_id_list,
                                (srv_sat_icon_enum)sim_ind->item_icon_list_attr);

    ADD_TO_ICON(
        (MMI_BOOL) sim_ind->is_icon_available, sim_ind->icon_info.icon_id,
        (srv_sat_icon_enum) sim_ind->icon_info.icon_attr, &setup_menu->icon);

    setup_menu->present = MMI_TRUE;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_select_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  select_item:    [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_do_select_item(
            srv_sat_enum sat_id,
            srv_sat_cntx_struct *context,
            srv_sat_select_item_struct *select_item,
            void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_select_item_ind_struct *sim_ind;
    mmi_sim_enum sim_id = SATID_2_SIMID(sat_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ind = (mmi_sat_select_item_ind_struct*) info;

    memset(select_item, 0, sizeof(srv_sat_select_item_struct));
    memcpy(select_item->cmd_detail, sim_ind->cmd_detail, 5 * sizeof(U8));

    if (!srv_sat_do_check(sat_id, SRV_SAT_CHECK_DM_SETTING_EX))
    {
        srv_sat_terminal_response_select_item(
            sim_id,
            SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
            0);
        return MMI_FALSE;
    }

    select_item->num_of_item = sim_ind->num_of_item;
    if (select_item->num_of_item == 0)
    {
        srv_sat_terminal_response_select_item(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_DATA_NOT_UNDERSTAND_BY_ME,
            0);
        return MMI_FALSE;
    }

    select_item->help_available = (MMI_BOOL) sim_ind->is_help_info_available;
    select_item->alpha_id =
        DO_ALPHA(MMI_TRUE, sim_ind->alpha_id, sim_ind->no_alpha_id, sim_ind->dcs_of_alpha_id);

    select_item->item_list = DO_MENU_ITEM(
                                sat_id,
                                SRV_SAT_CMD_SELECT_ITEM,
                                context,
                                select_item->num_of_item,
                                sim_ind->item_data,
                                (S32)sim_ind->no_next_action_ind_list,
                                sim_ind->next_action_ind_list,
                                (S32)sim_ind->no_item_icon_id_list,
                                sim_ind->item_icon_id_list,
                                (srv_sat_icon_enum)sim_ind->item_icon_list_attr);

    if (sim_ind->is_item_id_available)
    {
        select_item->default_id = sim_ind->item_id;
    }

    ADD_TO_ICON(
        (MMI_BOOL) sim_ind->is_icon_available, sim_ind->icon_info.icon_id,
        (srv_sat_icon_enum) sim_ind->icon_info.icon_attr, &select_item->icon);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_send_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  send_sms:       [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_do_send_sms(
            srv_sat_enum sat_id,
            srv_sat_cntx_struct *context,
            srv_sat_send_sms_struct *send_sms,
            void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_sms_ind_struct *sim_ind;
    mmi_sim_enum sim_id = SATID_2_SIMID(sat_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ind = (mmi_sat_send_sms_ind_struct*) info;

    memset(send_sms, 0, sizeof(srv_sat_send_sms_struct));
    memcpy(send_sms->cmd_detail, sim_ind->cmd_detail, 5 * sizeof(U8));

    if (!srv_sat_do_check(sat_id, SRV_SAT_CHECK_NW_REG_STATUS_EX))
    {
        srv_sat_terminal_response_send_sms_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
            SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
        return MMI_FALSE;
    }

    /* If the ME receives an icon and either an empty, or no, alpha identifier/text string is given by
       the SIM, than the ME shall reject the command with general result "Command data not understood by ME". */
    if (sim_ind->is_icon_available && !sim_ind->no_alpha_id)
    {
        srv_sat_terminal_response_send_sms_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_DATA_NOT_UNDERSTAND_BY_ME,
            SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
        return MMI_FALSE;
    }

    send_sms->sms_packed = (MMI_BOOL) sim_ind->is_sms_packed_required;
    send_sms->addr_len = sim_ind->size_of_addr;
	send_sms->addr = srv_sat_malloc_with_len(sim_ind->size_of_addr, sim_ind->addr);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    send_sms->tpdu_len = sim_ind->no_sms_tpdu;
	send_sms->tpdu = srv_sat_malloc_with_len(sim_ind->no_sms_tpdu, sim_ind->sms_tpdu);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    send_sms->alpha_id =
        DO_ALPHA((MMI_BOOL) sim_ind->is_alpha_id_present, sim_ind->alpha_id, sim_ind->no_alpha_id, sim_ind->dcs_of_alpha_id);
    if (!send_sms->alpha_id)
    {
        send_sms->alpha_id = DO_ALPHA_EX(STR_ID_SAT_SEND_SMS);
    }
    else if (!send_sms->alpha_id[0])
    {
        srv_sat_terminal_response_send_sms_stage1(sim_id);
        return MMI_FALSE;
    }

    ADD_TO_ICON(
        (MMI_BOOL) sim_ind->is_icon_available, sim_ind->icon_info.icon_id,
        (srv_sat_icon_enum) sim_ind->icon_info.icon_attr, &send_sms->icon);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_send_ss
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  send_ss:        [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_do_send_ss(
            srv_sat_enum sat_id,
            srv_sat_cntx_struct *context,
            srv_sat_send_ss_struct *send_ss,
            void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_ss_ind_struct *sim_ind;
    mmi_sim_enum sim_id = SATID_2_SIMID(sat_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ind = (mmi_sat_send_ss_ind_struct*) info;

    memset(send_ss, 0, sizeof(srv_sat_send_ss_struct));
    memcpy(send_ss->cmd_detail, sim_ind->cmd_detail, 5 * sizeof(U8));

    if (!srv_sat_do_check(sat_id, SRV_SAT_CHECK_NW_REG_STATUS_EX))
    {
        srv_sat_terminal_response_send_ss_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
            0,
            NULL);
        return MMI_FALSE;
    }

    /* If the ME receives an icon and either an empty, or no, alpha identifier/text string is given by
       the SIM, than the ME shall reject the command with general result "Command data not understood by ME". */
    if (sim_ind->is_icon_available && !sim_ind->no_alpha_id)
    {
        srv_sat_terminal_response_send_ss_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_DATA_NOT_UNDERSTAND_BY_ME,
            0,
            NULL);
        return MMI_FALSE;
    }

    send_ss->cc_type = sim_ind->type_of_modification;
    send_ss->ss_len = sim_ind->no_ss_string;
	send_ss->ss_string = srv_sat_malloc_with_len(sim_ind->no_ss_string, sim_ind->ss_string);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    send_ss->alpha_id =
        DO_ALPHA((MMI_BOOL) sim_ind->is_alpha_id_present, sim_ind->alpha_id, sim_ind->no_alpha_id, sim_ind->dcs_of_alpha_id);
    if (!send_ss->alpha_id)
    {
        send_ss->alpha_id = DO_ALPHA_EX(STR_ID_SAT_SEND_SS);
    }
    else if (!send_ss->alpha_id[0])
    {
        srv_sat_terminal_response_send_ss_stage1(sim_id);
        return MMI_FALSE;
    }

    ADD_TO_ICON(
        (MMI_BOOL) sim_ind->is_icon_available, sim_ind->icon_info.icon_id,
        (srv_sat_icon_enum) sim_ind->icon_info.icon_attr, &send_ss->icon);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_send_ussd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  send_ussd:      [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_do_send_ussd(
            srv_sat_enum sat_id,
            srv_sat_cntx_struct *context,
            srv_sat_send_ussd_struct *send_ussd,
            void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_ussd_ind_struct *sim_ind;
    mmi_sim_enum sim_id = SATID_2_SIMID(sat_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ind = (mmi_sat_send_ussd_ind_struct*) info;

    memset(send_ussd, 0, sizeof(srv_sat_send_ussd_struct));
    memcpy(send_ussd->cmd_detail, sim_ind->cmd_detail, 5 * sizeof(U8));

    if (!srv_sat_do_check(sat_id, SRV_SAT_CHECK_NW_REG_STATUS_EX))
    {
        srv_sat_terminal_response_send_ussd_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
            0,
            NULL);
        return MMI_FALSE;
    }

    /* If the ME receives an icon and either an empty, or no, alpha identifier/text string is given by
       the SIM, than the ME shall reject the command with general result "Command data not understood by ME". */
    if (sim_ind->is_icon_available && !sim_ind->no_alpha_id)
    {
        srv_sat_terminal_response_send_ussd_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_DATA_NOT_UNDERSTAND_BY_ME,
            0,
            NULL);
        return MMI_FALSE;
    }

    send_ussd->cc_type = sim_ind->type_of_modification;
    send_ussd->ussd_dcs = sim_ind->dcs_of_ussd_string;
    send_ussd->ussd_len = sim_ind->no_ussd_string;
	send_ussd->ussd_string = srv_sat_malloc_with_len(sim_ind->no_ussd_string, sim_ind->ussd_string);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    send_ussd->alpha_id =
        DO_ALPHA((MMI_BOOL) sim_ind->is_alpha_id_present, sim_ind->alpha_id, sim_ind->no_alpha_id, sim_ind->dcs_of_alpha_id);
    if (!send_ussd->alpha_id)
    {
        send_ussd->alpha_id = DO_ALPHA_EX(STR_ID_SAT_SEND_USSD);
    }
    else if (!send_ussd->alpha_id[0])
    {
        srv_sat_terminal_response_send_ussd_stage1(sim_id);
        return MMI_FALSE;
    }

    ADD_TO_ICON(
        (MMI_BOOL) sim_ind->is_icon_available, sim_ind->icon_info.icon_id,
        (srv_sat_icon_enum) sim_ind->icon_info.icon_attr, &send_ussd->icon);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_setup_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  setup_call:     [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_do_setup_call(
            srv_sat_enum sat_id,
            srv_sat_cntx_struct *context,
            srv_sat_setup_call_struct *setup_call,
            void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_call_setup_ind_struct *sim_ind;
    mmi_sim_enum sim_id = SATID_2_SIMID(sat_id);
    U16 num_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ind = (mmi_sat_call_setup_ind_struct*) info;

    memset(setup_call, 0, sizeof(srv_sat_setup_call_struct));
    memcpy(setup_call->cmd_detail, sim_ind->cmd_detail, 5 * sizeof(U8));

    if (!srv_sat_do_check(sat_id, SRV_SAT_CHECK_DM_SETTING_EX))
    {
        srv_sat_terminal_response_setup_call_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
            SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
        return MMI_FALSE;
    }

    if (srv_nw_info_sim_is_rejected(sim_id) &&
        !ecc_custom_verify_emergency_number(
            sim_ind->addr,
            sim_ind->no_addr,
            ECC_ENCODING_BCD,
            ECC_SAT_CALL,
            NULL,
            NULL,
            NULL))
    {
        srv_sat_terminal_response_setup_call_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
            SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
        return MMI_FALSE;
    }

    /* If the ME receives an icon and either an empty, or no, alpha identifier/text string is given by
       the SIM, than the ME shall reject the command with general result "Command data not understood by ME". */
    if ((sim_ind->is_icon1_available && !sim_ind->no_alpha_id1) ||
        (sim_ind->is_icon2_available && !sim_ind->no_alpha_id2))
    {
        srv_sat_terminal_response_setup_call_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_DATA_NOT_UNDERSTAND_BY_ME,
            SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
        return MMI_FALSE;
    }

    setup_call->condition = (srv_sat_setup_enum) sim_ind->condition;
    if ((setup_call->condition == SRV_SAT_SETUP_IF_NO_ANOTHER_CALL ||
         setup_call->condition == SRV_SAT_SETUP_WITH_REDIAL_IF_NO_ANOTHER_CALL) &&
        srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        srv_sat_terminal_response_setup_call_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
            SRV_SAT_ADDITIONAL_RES_ME_CURRENTLY_BUSY_ON_CALL);
        return MMI_FALSE;
    }

    setup_call->number = ConvertBCDToString(sim_ind->addr, sim_ind->no_addr, &num_len);

    setup_call->cc_type = sim_ind->type_of_modification;
    setup_call->addr_len = sim_ind->no_addr;
	setup_call->addr = srv_sat_malloc_with_len(sim_ind->no_addr, sim_ind->addr);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    setup_call->ccp_len = sim_ind->size_of_ccp;
	setup_call->ccp = srv_sat_malloc_with_len(sim_ind->size_of_ccp, sim_ind->ccp);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    setup_call->subadrr_len = sim_ind->size_of_subaddr;
	setup_call->subadrr = srv_sat_malloc_with_len(sim_ind->size_of_subaddr, sim_ind->subaddr);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    setup_call->alpha_id1 =
        DO_ALPHA((MMI_BOOL) sim_ind->is_alpha_id1_present, sim_ind->alpha_id1, sim_ind->no_alpha_id1, sim_ind->dcs_of_alpha_id1);
    if (!setup_call->alpha_id1 || !setup_call->alpha_id1[0])
    {
        setup_call->alpha_id1 = DO_ALPHA_EX(STR_ID_SAT_SETUP_CALL_CONFIRM);
    }

    ADD_TO_ICON(
        (MMI_BOOL) sim_ind->is_icon1_available, sim_ind->icon_info1.icon_id,
        (srv_sat_icon_enum) sim_ind->icon_info1.icon_attr, &setup_call->icon1);

    setup_call->alpha_id2 =
        DO_ALPHA((MMI_BOOL) sim_ind->is_alpha_id2_present, sim_ind->alpha_id2, sim_ind->no_alpha_id2, sim_ind->dcs_of_alpha_id2);

    ADD_TO_ICON(
        (MMI_BOOL) sim_ind->is_icon2_available, sim_ind->icon_info2.icon_id,
        (srv_sat_icon_enum) sim_ind->icon_info2.icon_attr, &setup_call->icon2);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_setup_idle_mode_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  setup_idle_mode_text:   [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_do_setup_idle_mode_text(
            srv_sat_enum sat_id,
            srv_sat_cntx_struct *context,
            srv_sat_setup_idle_mode_text_struct *setup_idle_mode_text,
            void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_setup_idle_display_ind_struct *sim_ind;
    mmi_sim_enum sim_id = SATID_2_SIMID(sat_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ind = (mmi_sat_setup_idle_display_ind_struct*) info;

    srv_sat_do_free(setup_idle_mode_text->text_string);
    setup_idle_mode_text->text_string = NULL;
    srv_sat_do_free(setup_idle_mode_text->icon.data);
    setup_idle_mode_text->icon.data = NULL;

    memcpy(setup_idle_mode_text->cmd_detail, sim_ind->cmd_detail, 5 * sizeof(U8));

    /* If the ME receives an icon and either an empty, or no, alpha identifier/text string is given by
       the SIM, than the ME shall reject the command with general result "Command data not understood by ME". */
    if (sim_ind->is_icon_available && !sim_ind->no_text_string)
    {
        srv_sat_terminal_response_setup_idle_mode_text(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_DATA_NOT_UNDERSTAND_BY_ME);
        return MMI_FALSE;
    }

    setup_idle_mode_text->text_string =
        DO_TEXT(sim_ind->text_string, sim_ind->no_text_string, sim_ind->dcs_of_text_string);

    ADD_TO_ICON(
        (MMI_BOOL) sim_ind->is_icon_available, sim_ind->icon_info.icon_id,
        (srv_sat_icon_enum) sim_ind->icon_info.icon_attr, &setup_idle_mode_text->icon);

    if (setup_idle_mode_text->text_string[0])
    {
        setup_idle_mode_text->present = MMI_TRUE;
    }
    else
    {
        setup_idle_mode_text->present = MMI_FALSE;
    }

    return MMI_TRUE;
}

#if __SATCB__

/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_run_at_command
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  run_at_command: [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_do_run_at_command(
            srv_sat_enum sat_id,
            srv_sat_cntx_struct *context,
            srv_sat_run_at_command_struct *run_at_command,
            void *info)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_run_at_command_ind_struct *sim_ind;
    mmi_sim_enum sim_id = SATID_2_SIMID(sat_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ind = (mmi_sat_run_at_command_ind_struct*) info;

    memset(run_at_command, 0, sizeof(srv_sat_run_at_command_struct));
    memcpy(run_at_command->cmd_detail, sim_ind->cmd_detail, 5 * sizeof(U8));

    if (!srv_sat_do_check(sat_id, SRV_SAT_CHECK_DM_SETTING_EX))
    {
        return MMI_FALSE;
    }

    /* If the ME receives an icon and either an empty, or no, alpha identifier/text string is given by
       the SIM, than the ME shall reject the command with general result "Command data not understood by ME". */
    if (sim_ind->is_icon_available && !sim_ind->no_alpha_id)
    {
        return MMI_FALSE;
    }

    run_at_command->alpha_id =
        DO_ALPHA((MMI_BOOL) sim_ind->is_alpha_id_present, sim_ind->alpha_id, sim_ind->no_alpha_id, sim_ind->dcs_of_alpha_id);
    if (!run_at_command->alpha_id)
    {
        run_at_command->alpha_id = DO_ALPHA_EX(STR_ID_SAT_RUN_AT_COMMAND);
    }
    else if (!run_at_command->alpha_id[0])
    {
        srv_sat_do_free(run_at_command->alpha_id);
        run_at_command->alpha_id = NULL;
        return MMI_FALSE;
    }

    ADD_TO_ICON(
        (MMI_BOOL) sim_ind->is_icon_available, sim_ind->icon_info.icon_id,
        (srv_sat_icon_enum) sim_ind->icon_info.icon_attr, &run_at_command->icon);

    return MMI_TRUE;

}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_send_dtmf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  send_dtmf:      [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_do_send_dtmf(
            srv_sat_enum sat_id,
            srv_sat_cntx_struct *context,
            srv_sat_send_dtmf_struct *send_dtmf,
            void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_dtmf_ind_struct *sim_ind;
    mmi_sim_enum sim_id = SATID_2_SIMID(sat_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ind = (mmi_sat_send_dtmf_ind_struct*) info;

    memset(send_dtmf, 0, sizeof(srv_sat_send_dtmf_struct));
    memcpy(send_dtmf->cmd_detail, sim_ind->cmd_detail, 5 * sizeof(U8));

    if (!srv_sat_do_check(sat_id, SRV_SAT_CHECK_NW_REG_STATUS_EX))
    {
        srv_sat_terminal_response_send_dtmf_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
            SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
        return MMI_FALSE;
    }

    /* The sending of a DTMF string applies only to the currently active call. */
    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, NULL) == 0)
    {
        srv_sat_terminal_response_send_dtmf_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
            SRV_SAT_ADDITIONAL_RES_NOT_IN_SPEECH_MODE);
        return MMI_FALSE;
    }

    /* If the ME receives an icon and either an empty, or no, alpha identifier/text string is given by
       the SIM, than the ME shall reject the command with general result "Command data not understood by ME". */
    if (sim_ind->is_icon_available && !sim_ind->no_alpha_id)
    {
        srv_sat_terminal_response_send_dtmf_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_DATA_NOT_UNDERSTAND_BY_ME,
            SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
        return MMI_FALSE;
    }

    send_dtmf->dtmf_len = sim_ind->no_dtmf;
    if (send_dtmf->dtmf_len > 0)
    {
        send_dtmf->dtmf_string = (U8*) OslMalloc(send_dtmf->dtmf_len * sizeof(U8));
        memcpy(send_dtmf->dtmf_string, sim_ind->dtmf, sim_ind->no_dtmf);
    }

    send_dtmf->alpha_id =
        DO_ALPHA((MMI_BOOL) sim_ind->is_alpha_id_present, sim_ind->alpha_id, sim_ind->no_alpha_id, sim_ind->dcs_of_alpha_id);
    if (!send_dtmf->alpha_id)
    {
        send_dtmf->alpha_id = DO_ALPHA_EX(STR_ID_SAT_SEND_DTMF);
    }
    else if (!send_dtmf->alpha_id[0])
    {
        srv_sat_terminal_response_send_dtmf_stage1(sim_id);
        return MMI_FALSE;
    }

    ADD_TO_ICON(
        (MMI_BOOL) sim_ind->is_icon_available, sim_ind->icon_info.icon_id,
        (srv_sat_icon_enum) sim_ind->icon_info.icon_attr, &send_dtmf->icon);

    return MMI_TRUE;
}


#ifndef __SAT_LOWCOST_UI_DISABLE__

/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_language_notification
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  language_notification:  [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_do_language_notification(
            srv_sat_enum sat_id,
            srv_sat_cntx_struct *context,
            srv_sat_language_notification_struct *language_notification,
            void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_lang_notify_ind_struct *sim_ind;
    static U8 last_lang_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ind = (mmi_sat_lang_notify_ind_struct*) info;

    memcpy(language_notification->cmd_detail, sim_ind->cmd_detail, 5 * sizeof(U8));

    language_notification->is_specified = sim_ind->is_language_specified;
    if (sim_ind->is_language_specified == MMI_TRUE)
    {
        memcpy(language_notification->lang, sim_ind->iso639_language, 2 * sizeof(U8));
#ifndef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
        last_lang_index = srv_setting_get_language();
#endif
    }
    else
    {
        language_notification->lang[0] = last_lang_index;
        language_notification->lang[1] = 0;
    }

    return MMI_TRUE;
}

#ifdef __SATCC__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_launch_browser
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  launch_browser: [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_do_launch_browser(
            srv_sat_enum sat_id,
            srv_sat_cntx_struct *context,
            srv_sat_launch_browser_struct *launch_browser,
            void *info)
{
#ifdef BROWSER_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_launch_browser_ind_struct *sim_ind;
    mmi_sim_enum sim_id = SATID_2_SIMID(sat_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ind = (mmi_sat_launch_browser_ind_struct*) info;

    memset(launch_browser, 0, sizeof(srv_sat_launch_browser_struct));
    memcpy(launch_browser->cmd_detail, sim_ind->cmd_detail, 5 * sizeof(U8));

    if (!srv_sat_do_check(sat_id, SRV_SAT_CHECK_NW_REG_STATUS_EX))
    {
        srv_sat_terminal_response_launch_browser_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
            SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
        return MMI_FALSE;
    }

    /* If the ME receives an icon and either an empty, or no, alpha identifier/text string is given by
       the SIM, than the ME shall reject the command with general result "Command data not understood by ME". */
    if (sim_ind->is_icon_available && !sim_ind->no_alpha_id)
    {
        srv_sat_terminal_response_launch_browser_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_DATA_NOT_UNDERSTAND_BY_ME,
            SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
        return MMI_FALSE;
    }

    if (sim_ind->browser_mode == SRV_SAT_LAUNCH_IF_NO_LAUNCHED && wap_browser_is_open())
    {
        srv_sat_terminal_response_launch_browser_stage2(
            sim_id,
            SRV_SAT_TERMINAL_RES_LAUNCH_BROWER_GENERIC_ERROR_CODE,
            SRV_SAT_ADDITIONAL_RES_BROWSER_UNAVAILABLE);
        return MMI_FALSE;
    }

    launch_browser->browser_mode = (srv_sat_launch_enum) sim_ind->browser_mode;
    launch_browser->browser_identity = sim_ind->browser_identity;
    launch_browser->url_len = sim_ind->no_url;
    if (launch_browser->url_len)
    {
        launch_browser->url = CovertStringForPlatform(
                                sim_ind->url,
                                sim_ind->no_url,
                                MMI_DEFAULT_DCS,
                                &launch_browser->url_len);
    }
    launch_browser->bearer_len = sim_ind->no_bearer;
    if (launch_browser->bearer_len)
    {
        launch_browser->bearer = (U8*) OslMalloc(sim_ind->no_bearer * sizeof(U8));
        memcpy(launch_browser->bearer, sim_ind->bearer, sim_ind->no_bearer);
    }
    launch_browser->gateway_len = sim_ind->no_gateway;
    if (launch_browser->gateway_len)
    {
        launch_browser->gateway = CovertStringForPlatform(
                                    sim_ind->gateway,
                                    sim_ind->no_gateway,
                                    sim_ind->dcs_of_gateway,
                                    &launch_browser->gateway_len);
    }

    launch_browser->alpha_id =
        DO_ALPHA((MMI_BOOL) sim_ind->is_alpha_id_present, sim_ind->alpha_id, sim_ind->no_alpha_id, sim_ind->dcs_of_alpha_id);
    if (!launch_browser->alpha_id)
    {
        launch_browser->alpha_id = DO_ALPHA_EX(STR_ID_SAT_LAUNCH_BROWSER_CONFIRM);
    }
    else if (!launch_browser->alpha_id[0])
    {
        srv_sat_terminal_response_launch_browser_stage1(sim_id);
        return MMI_FALSE;
    }

    ADD_TO_ICON(
        (MMI_BOOL) sim_ind->is_icon_available, sim_ind->icon_info.icon_id,
        (srv_sat_icon_enum) sim_ind->icon_info.icon_attr, &launch_browser->icon);

    return MMI_TRUE;
#else /* BROWSER_SUPPORT */

    mmi_sim_enum sim_id = SATID_2_SIMID(sat_id);

    srv_sat_terminal_response_launch_browser_stage2(
        sim_id,
        SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
        SRV_SAT_ADDITIONAL_RES_BEARER_UNAVAILABLE);

    return MMI_FALSE;
#endif /* BROWSER_SUPPORT */
}
#endif /*SATCC*/
#endif /* __SAT_LOWCOST_UI_DISABLE__ */


#ifdef __SATCE__

/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_open_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  open_channel:   [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_do_open_channel(
            srv_sat_enum sat_id,
            srv_sat_cntx_struct *context,
            srv_sat_open_channel_struct *open_channel,
            void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_open_channel_ind_struct *sim_ind;
    mmi_sim_enum sim_id = SATID_2_SIMID(sat_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ind = (mmi_sat_open_channel_ind_struct*) info;

    memset(open_channel, 0, sizeof(srv_sat_open_channel_struct));
    memcpy(open_channel->cmd_detail, sim_ind->cmd_detail, 5 * sizeof(U8));

    if (!srv_sat_do_check(sat_id, SRV_SAT_CHECK_NW_REG_STATUS_EX))
    {
        srv_sat_terminal_response_open_channel(
            sim_id,
            SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
            SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
        return MMI_FALSE;
    }

    /* If the ME receives an icon and either an empty, or no, alpha identifier/text string is given by
       the SIM, than the ME shall reject the command with general result "Command data not understood by ME". */
    if (sim_ind->is_icon_available && !sim_ind->no_alpha_id)
    {
        srv_sat_terminal_response_open_channel(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_DATA_NOT_UNDERSTAND_BY_ME,
            SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
        return MMI_FALSE;
    }

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        srv_sat_terminal_response_open_channel(
            sim_id,
            SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
            SRV_SAT_ADDITIONAL_RES_ME_CURRENTLY_BUSY_ON_CALL);
        return MMI_FALSE;
    }

    open_channel->alpha_id =
        DO_ALPHA((MMI_BOOL) sim_ind->is_alpha_id_present, sim_ind->alpha_id, sim_ind->no_alpha_id, sim_ind->dcs_of_alpha_id);
    if (!open_channel->alpha_id)
    {
        open_channel->alpha_id = DO_ALPHA_EX(STR_ID_SAT_OPEN_CHANNEL_CONFIRM);
    }
    else if (!open_channel->alpha_id[0])
    {
        srv_sat_terminal_response_open_channel(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY,
            SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
        return MMI_FALSE;
    }

    ADD_TO_ICON(
        (MMI_BOOL) sim_ind->is_icon_available, sim_ind->icon_info.icon_id,
        (srv_sat_icon_enum) sim_ind->icon_info.icon_attr, &open_channel->icon);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_close_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  close_channel:  [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_do_close_channel(
            srv_sat_enum sat_id,
            srv_sat_cntx_struct *context,
            srv_sat_close_channel_struct *close_channel,
            void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_close_channel_ind_struct *sim_ind;
    mmi_sim_enum sim_id = SATID_2_SIMID(sat_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ind = (mmi_sat_close_channel_ind_struct*) info;

    memset(close_channel, 0, sizeof(srv_sat_close_channel_struct));
    memcpy(close_channel->cmd_detail, sim_ind->cmd_detail, 5 * sizeof(U8));

#ifdef __SRV_SAT_TR_CLOSE_CHANNEL__
    if (!srv_sat_do_check(sat_id, SRV_SAT_CHECK_NW_REG_STATUS_EX))
    {
        srv_sat_terminal_response_close_channel(
            sim_id,
            SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD);
        return MMI_FALSE;
    }

    /* If the ME receives an icon and either an empty, or no, alpha identifier/text string is given by
       the SIM, than the ME shall reject the command with general result "Command data not understood by ME". */
    if (sim_ind->is_icon_available && !sim_ind->no_alpha_id)
    {
        srv_sat_terminal_response_close_channel(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_DATA_NOT_UNDERSTAND_BY_ME);
        return MMI_FALSE;
    }
#endif /* __SRV_SAT_TR_CLOSE_CHANNEL__ */

    close_channel->alpha_id =
        DO_ALPHA((MMI_BOOL) sim_ind->is_alpha_id_present, sim_ind->alpha_id, sim_ind->no_alpha_id, sim_ind->dcs_of_alpha_id);
    if (!close_channel->alpha_id)
    {
        close_channel->alpha_id = DO_ALPHA_EX(STR_ID_SAT_CLOSE_CHANNEL);
    }
    else if (!close_channel->alpha_id[0])
    {
        srv_sat_do_free(close_channel->alpha_id);
        close_channel->alpha_id = NULL;
        return MMI_FALSE;
    }

    ADD_TO_ICON(
        (MMI_BOOL) sim_ind->is_icon_available, sim_ind->icon_info.icon_id,
        (srv_sat_icon_enum) sim_ind->icon_info.icon_attr, &close_channel->icon);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_send_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  send_data:      [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_do_send_data(
            srv_sat_enum sat_id,
            srv_sat_cntx_struct *context,
            srv_sat_send_data_struct *send_data,
            void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_data_ind_struct *sim_ind;
    mmi_sim_enum sim_id = SATID_2_SIMID(sat_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ind = (mmi_sat_send_data_ind_struct*) info;

    memset(send_data, 0, sizeof(srv_sat_send_data_struct));
    memcpy(send_data->cmd_detail, sim_ind->cmd_detail, 5 * sizeof(U8));

    if (!srv_sat_do_check(sat_id, SRV_SAT_CHECK_NW_REG_STATUS_EX))
    {
        srv_sat_terminal_response_send_data(
            sim_id,
            SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD);
        return MMI_FALSE;
    }

    /* If the ME receives an icon and either an empty, or no, alpha identifier/text string is given by
       the SIM, than the ME shall reject the command with general result "Command data not understood by ME". */
    if (sim_ind->is_icon_available && !sim_ind->no_alpha_id)
    {
        srv_sat_terminal_response_send_data(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_DATA_NOT_UNDERSTAND_BY_ME);
        return MMI_FALSE;
    }

    send_data->alpha_id =
        DO_ALPHA((MMI_BOOL) sim_ind->is_alpha_id_present, sim_ind->alpha_id, sim_ind->no_alpha_id, sim_ind->dcs_of_alpha_id);
    if (!send_data->alpha_id)
    {
        send_data->alpha_id = DO_ALPHA_EX(STR_ID_SAT_SEND_DATA);
    }
    else if (!send_data->alpha_id[0])
    {
        srv_sat_do_free(send_data->alpha_id);
        send_data->alpha_id = NULL;
        return MMI_FALSE;
    }

    ADD_TO_ICON(
        (MMI_BOOL) sim_ind->is_icon_available, sim_ind->icon_info.icon_id,
        (srv_sat_icon_enum) sim_ind->icon_info.icon_attr, &send_data->icon);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_receive_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  receive_data:   [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sat_do_receive_data(
            srv_sat_enum sat_id,
            srv_sat_cntx_struct *context,
            srv_sat_receive_data_struct *receive_data,
            void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_recv_data_ind_struct *sim_ind;
    mmi_sim_enum sim_id = SATID_2_SIMID(sat_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ind = (mmi_sat_recv_data_ind_struct*) info;

    memset(receive_data, 0, sizeof(srv_sat_receive_data_struct));
    memcpy(receive_data->cmd_detail, sim_ind->cmd_detail, 5 * sizeof(U8));

    if (!srv_sat_do_check(sat_id, SRV_SAT_CHECK_NW_REG_STATUS_EX))
    {
        srv_sat_terminal_response_receive_data(
            sim_id,
            SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD);
        return MMI_FALSE;
    }

    /* If the ME receives an icon and either an empty, or no, alpha identifier/text string is given by
       the SIM, than the ME shall reject the command with general result "Command data not understood by ME". */
    if (sim_ind->is_icon_available && !sim_ind->no_alpha_id)
    {
        srv_sat_terminal_response_receive_data(
            sim_id,
            SRV_SAT_TERMINAL_RES_CMD_DATA_NOT_UNDERSTAND_BY_ME);
        return MMI_FALSE;
    }

    receive_data->alpha_id =
        DO_ALPHA((MMI_BOOL) sim_ind->is_alpha_id_present, sim_ind->alpha_id, sim_ind->no_alpha_id, sim_ind->dcs_of_alpha_id);
    if (!receive_data->alpha_id)
    {
        receive_data->alpha_id = DO_ALPHA_EX(STR_ID_SAT_RECV_DATA);
    }
    else if (!receive_data->alpha_id[0])
    {
        srv_sat_do_free(receive_data->alpha_id);
        receive_data->alpha_id = NULL;
        return MMI_FALSE;
    }

    ADD_TO_ICON(
        (MMI_BOOL) sim_ind->is_icon_available, sim_ind->icon_info.icon_id,
        (srv_sat_icon_enum) sim_ind->icon_info.icon_attr, &receive_data->icon);

    return MMI_TRUE;
}

#endif /* __SATCE__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_call_control_by_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  info:           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_do_call_control_by_sim(srv_sat_enum sat_id, void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_mmi_info_ind_struct *sim_ind;
    U8 *number, *display;
    U16 length;
    sat_mmi_info_type_enum mmi_info_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_ind = (mmi_sat_mmi_info_ind_struct *)info;
    mmi_info_type = (sat_mmi_info_type_enum)(sim_ind->mmi_info_type);

    if (mmi_info_type != SAT_NUM_CHANGED_CALL_TO_CALL)
    {
        if (sim_ind->is_alpha_id_present)
        {
            if (sim_ind->no_alpha_id != 0)
            {
                display = CovertStringForPlatform(
                            sim_ind->alpha_id,
                            sim_ind->no_alpha_id,
                            sim_ind->dcs_of_alpha_id,
                            &length);

                srv_sat_send_sim_ctrl_info_event((WCHAR *)display);
            }
        }

        return;
    }

    number = CovertStringForPlatform(
                sim_ind->address,
                sim_ind->len_of_address,
                MMI_8BIT_DCS,
                &length);

    /* if non-empty alpha id present, call app cannot handle both changed number and alpha identifer to be displayed . so now only notify changed number */
    if (sim_ind->is_alpha_id_present && sim_ind->no_alpha_id == 0)
    {
        display = CovertStringForPlatform(
                    sim_ind->alpha_id,
                    sim_ind->no_alpha_id,
                    sim_ind->dcs_of_alpha_id,
                    &length);
    }
    else
    {
        display = number;
    }

    srv_gcall_sat_notify_mo_number_change(number, display);

    if (display == number)
    {
        display = NULL;
    }

    OslMfree(number);

    if (display)
    {
        OslMfree(display);
    }
}

#endif /* SATCOMMANDSRV_C */

