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
 * PushMsgSettings.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the function defination for logical implementation 
 *   of Service message settings.
 *
 * Author:
 * -------
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

//#include "MMI_include.h"

//#include "custom_nvram_editor_data_item.h"
//#include "Nvram_enums.h"
//#include "nvram_interface.h"
#include "app_usedetails.h"
#include "app_addr.h"
#include "WAPPushSrvProts.h"
    #include "WAPPushSrvTypes.h"
    #include "MMI_features.h"
    #include "MMIDataType.h"
    #include "string.h"
    #include "stdio.h"
    #include "common_nvram_editor_data_item.h"
    #include "DebugInitDef_Int.h"
    #include "kal_trace.h"
    #include "mmi_inet_app_trc.h"
    #include "MMI_inet_app_trc.h"
    #include "pmg_struct.h"
    #include "app_ltlcom.h"
    #include "kal_general_types.h"
  #if defined(__VODAFONE_R12_LIVE__)  
    #include "op_custom_wap_config.h"
 #endif /* defined(__VODAFONE_R12_LIVE__) */
    #include "stack_config.h"
    #include "stack_msgs.h"
    #include "stack_common.h"
    #include "kal_public_api.h"
    #include "custom_phb_config.h"
    #include "nvram_common_defs.h"
    #include "Unicodexdcl.h"
    #include "CustDataRes.h"
    #include "GlobalResDef.h"
    #include "mmi_frm_mem_gprot.h"
    #include "mmi_frm_nvram_gprot.h"

    #include "WAPPushResDef.h"
    #include "WAPPushSrvGprots.h"
    #include "mmi_frm_events_gprot.h"
    #include "mmi_cb_mgr_gprot.h"
    #include "mmi_frm_scenario_gprot.h"
#ifdef __WAP_PUSH_SUPPORT__

    #ifndef __COSMOS_MMI_PACKAGE__
    #include "mmi_rp_app_mmi_wap_push_def.h"
    #endif
static srv_wap_push_setting_cntxt_struct PushSettingData;
srv_wap_push_setting_cntxt_struct *g_push_set_p = &PushSettingData;

/*****************************************************************************/
/******************  Start of common functions   *****************************/
/*****************************************************************************/


#ifdef __MMI_WAP_PUSH_WHITE_LIST__




void srv_push_covert_ip_string_to_proper_format (S8* ip_string, S8 *dest_str, U16 des_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ipv4_array[4] = {0,};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (des_len < 16 || ip_string == NULL || !strlen (ip_string))
    {
        return;
    }
    applib_addr_string_2_ipv4 (ip_string, ipv4_array, 4);
    memset (dest_str, 0, des_len);
    sprintf(dest_str, "%03d.%03d.%03d.%03d", ipv4_array[0], ipv4_array[1], ipv4_array[2], ipv4_array[3]);
}






/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_get_record_and_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  record              [OUT]       
 *  index               [OUT]       
 *  for_item_num        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_get_record_and_index(U16 *record, U16 *index, S32 for_item_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *record = for_item_num / NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD;
    *index = for_item_num % NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD;
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SETTING_GET_RECORD_INDEX_FOR_ITEM, for_item_num);
}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_send_config_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_send_config_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wps_pmg_config_req_struct *local_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	local_data = (wps_pmg_config_req_struct*) construct_local_para(sizeof(wps_pmg_config_req_struct), TD_CTRL);

	local_data->wap_push_enabled = g_push_set_p->general_set.enable_push;
	if(g_push_set_p->general_set.sl_setting == SRV_WAP_PUSH_SL_SETTING_DISABLED)
	{
		local_data->sl_enabled = 0;
	}
	else
	{
		local_data->sl_enabled = 1;
	}
    
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
	local_data->trust_enabled = g_push_set_p->general_set.enable_white_list;
	local_data->max_trust_addr_no = NVRAM_PUSH_MAX_NUM_WHITE_LIST;
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
	local_data->black_list_enabled = g_push_set_p->general_set.enable_black_list;
	local_data->max_black_addr_no = NVRAM_PUSH_MAX_NUM_BLACK_LIST;
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    
    srv_wap_push_send_msg (MSG_ID_WPS_PMG_CONFIG_REQ, local_data, MOD_WPS, WPS_APP_SAP);
}


#ifdef __MMI_WAP_PUSH_BLACK_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_send_black_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  count       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_send_black_list(U16 index, U16 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cntr = 0;
    U16 real_index = 0;
    U16 rec_index = 0;
    wps_pmg_black_addr_list_req_struct *local_data = NULL;
    nvram_push_addr_struct *curr_addr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SETTING_ENTERS_SEND_BLACK_LIST);
    local_data = (wps_pmg_black_addr_list_req_struct*) construct_local_para(sizeof(wps_pmg_black_addr_list_req_struct), TD_CTRL);

    local_data->trans_id = 0;
    local_data->size = count;
    local_data->segment = index / WAP_PMG_MAX_MSG_ADDR_LIST_SIZE;
    local_data->total_segment = NVRAM_PUSH_MAX_NUM_BLACK_LIST / WAP_PMG_MAX_MSG_ADDR_LIST_SIZE;

    /* Handling boundary conditions by ARK*/
    if ((NVRAM_PUSH_MAX_NUM_BLACK_LIST % WAP_PMG_MAX_MSG_ADDR_LIST_SIZE == 0) && (NVRAM_PUSH_MAX_NUM_BLACK_LIST != 0))
    {
        local_data->total_segment--;
    }

	
    for (cntr = 0; cntr < WAP_PMG_MAX_MSG_ADDR_LIST_SIZE; cntr++)
    {
        memset(local_data->addresses[cntr].addr, '\0', WAP_PMG_MAX_ADDR_CHARS + 1);
        local_data->addresses[cntr].addr_type = 0;
    }
    for (cntr = 0; cntr < count; cntr++)
    {
        srv_wap_push_get_record_and_index(&rec_index, &real_index, index);
        curr_addr = &g_push_set_p->black_list[rec_index].black_list[real_index];

        local_data->addresses[cntr].addr_type = curr_addr->addr_type;
        strcpy((S8*) local_data->addresses[cntr].addr, (S8*) curr_addr->addr);

        index++;
    }

    srv_wap_push_send_msg (MSG_ID_WPS_PMG_BLACK_ADDR_LIST_REQ, local_data, MOD_WPS, WPS_APP_SAP);

    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SETTING_EXITS_SEND_BLACK_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_send_black_list_to_service_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_send_black_list_to_service_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;
    U16 black_addr_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_push_set_p->total_bl_entry > NVRAM_PUSH_MAX_NUM_WHITE_LIST)
    {
        ASSERT(0);
    }
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SENDING_BLACK_LIST_TOTAL, g_push_set_p->total_bl_entry);
    while (index < NVRAM_PUSH_MAX_NUM_BLACK_LIST)
    {
        if ((NVRAM_PUSH_MAX_NUM_BLACK_LIST - index) < WAP_PMG_MAX_MSG_ADDR_LIST_SIZE)
        {
            black_addr_count = NVRAM_PUSH_MAX_NUM_BLACK_LIST - index;
            srv_wap_push_send_black_list(index, black_addr_count);
            index = NVRAM_PUSH_MAX_NUM_BLACK_LIST;
        }
        else
        {
            srv_wap_push_send_black_list(index, WAP_PMG_MAX_MSG_ADDR_LIST_SIZE);
            index = index + WAP_PMG_MAX_MSG_ADDR_LIST_SIZE;
        }
    }
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ALL_BLACK_LIST_SENDED);
}
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */


#ifdef __MMI_WAP_PUSH_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_send_white_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  count       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_send_white_list(U16 index, U16 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cntr = 0;
    U16 real_index = 0;
    U16 rec_index = 0;
    wps_pmg_trust_addr_list_req_struct *local_data = NULL;
    nvram_push_addr_struct *curr_addr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SETTING_ENTERS_SEND_WHITE_LIST);

    local_data = (wps_pmg_trust_addr_list_req_struct*) construct_local_para(sizeof(wps_pmg_trust_addr_list_req_struct), TD_CTRL);

    local_data->trans_id = 0;
    local_data->size = count;
    local_data->segment = index / WAP_PMG_MAX_MSG_ADDR_LIST_SIZE;
    local_data->total_segment = NVRAM_PUSH_MAX_NUM_WHITE_LIST / WAP_PMG_MAX_MSG_ADDR_LIST_SIZE;

    /* Handling boundary conditions */
    if ((NVRAM_PUSH_MAX_NUM_WHITE_LIST % WAP_PMG_MAX_MSG_ADDR_LIST_SIZE == 0) && (NVRAM_PUSH_MAX_NUM_WHITE_LIST != 0))
    {
        local_data->total_segment--;
    }

    for (cntr = 0; cntr < WAP_PMG_MAX_MSG_ADDR_LIST_SIZE; cntr++)
    {
        memset(local_data->addresses[cntr].addr, '\0', WAP_PMG_MAX_ADDR_CHARS + 1);
        local_data->addresses[cntr].addr_type = 0;
    }
    for (cntr = 0; cntr < count; cntr++)
    {
        srv_wap_push_get_record_and_index(&rec_index, &real_index, index);
        curr_addr = &g_push_set_p->white_list[rec_index].white_list[real_index];

        local_data->addresses[cntr].addr_type = curr_addr->addr_type;
        strcpy((S8*) local_data->addresses[cntr].addr, (S8*) curr_addr->addr);

        index++;
    }

    srv_wap_push_send_msg (MSG_ID_WPS_PMG_TRUST_ADDR_LIST_REQ, local_data, MOD_WPS, WPS_APP_SAP);

    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SETTING_EXITS_SEND_WHITE_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_send_white_list_to_service_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_send_white_list_to_service_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;
    U16 white_addr_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_push_set_p->total_wl_entry > NVRAM_PUSH_MAX_NUM_WHITE_LIST)
    {
        ASSERT(0);
    }
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SENDING_WHITE_LIST_TOTAL, g_push_set_p->total_wl_entry);
    while (index < NVRAM_PUSH_MAX_NUM_WHITE_LIST)
    {
        if ((NVRAM_PUSH_MAX_NUM_WHITE_LIST - index) < WAP_PMG_MAX_MSG_ADDR_LIST_SIZE)
        {
            white_addr_count = NVRAM_PUSH_MAX_NUM_WHITE_LIST - index;
            srv_wap_push_send_white_list(index, white_addr_count);
            index = NVRAM_PUSH_MAX_NUM_WHITE_LIST;
        }
        else
        {
            srv_wap_push_send_white_list(index, WAP_PMG_MAX_MSG_ADDR_LIST_SIZE);
            index = index + WAP_PMG_MAX_MSG_ADDR_LIST_SIZE;
        }
    }
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ALL_WHITE_LIST_SENDED);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_check_duplicate_entry
 * DESCRIPTION
 *  Check if number fields contain invalid '+' character.
 * PARAMETERS
 *  list_type       [IN]        
 *  addr_type       [IN]        
 *  addr            [IN]        
 * RETURNS
 *  TRUE, if duplicate entry.
 *****************************************************************************/
pBOOL srv_wap_push_check_duplicate_entry(U16 list_type, U16 addr_type, S8 *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;
    U16 rec_index = 0;
    U16 max_record = 0;
   
    S8 temp_ip[16] = {0};
	S8 temp_ip1[16] ={0};
    nvram_push_addr_struct *curr_addr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ENTERS_DUPLICATE_CHECK);

    if (addr_type == SRV_WAP_PUSH_SENDER_ADDR_TYPE_IP_ADDRESS)
    {
        srv_push_covert_ip_string_to_proper_format (addr, temp_ip, 16);
        addr = temp_ip;
    }
   

    if (list_type == SRV_WAP_PUSH_WHITE_LIST)
    {
        max_record = SRV_WAP_PUSH_TOTAL_WHITE_LIST_RECORD;
    }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    else
    {
        max_record = SRV_WAP_PUSH_TOTAL_BLACK_LIST_RECORD;
    }
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    while (rec_index < max_record)
    {
        if (list_type == SRV_WAP_PUSH_WHITE_LIST)
        {
            curr_addr = &g_push_set_p->white_list[rec_index].white_list[index];
        }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
        else
        {
            curr_addr = &g_push_set_p->black_list[rec_index].black_list[index];
        }
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
        while ((curr_addr->addr_type != SRV_WAP_PUSH_SENDER_ADDR_TYPE_NONE) &&
               (index < NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD))
        {
            if (curr_addr->addr_type == addr_type)
            {
				  if(curr_addr->addr_type== SRV_WAP_PUSH_SENDER_ADDR_TYPE_IP_ADDRESS)
				    {   
						srv_push_covert_ip_string_to_proper_format (curr_addr->addr, temp_ip1, 16);
						if (!strcmp((S8*) temp_ip1, (S8*) addr))
							{
							  MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_EXITS_DUPLICATE_CHECK, TRUE);
							  return TRUE;
							 }
					 }
				  else
					{

      

               S8 ascii_sender1[NVRAM_PUSH_SENDER_ADDR_LEN_MAX] = { '\0', '\0' };
               S8 ascii_smsc1[NVRAM_PUSH_SENDER_ADDR_LEN_MAX] = { '\0', '\0' };
               S8 ascii_sender2[NVRAM_PUSH_SENDER_ADDR_LEN_MAX] = { '\0', '\0' };
               S8 ascii_smsc2[NVRAM_PUSH_SENDER_ADDR_LEN_MAX] = { '\0', '\0' };
               if(curr_addr->addr[0]=='+')
               srv_wap_push_parse_ph_num(ascii_sender1, ascii_smsc1, (S8*) (curr_addr->addr+1));
               else
               srv_wap_push_parse_ph_num(ascii_sender1, ascii_smsc1, (S8*) (curr_addr->addr));
               
              if(addr[0]=='+')
               srv_wap_push_parse_ph_num(ascii_sender2, ascii_smsc2, (S8*) (addr+1));
               else
               srv_wap_push_parse_ph_num(ascii_sender2, ascii_smsc2, (S8*) (addr));
                
              if(!strcmp((S8*) (ascii_sender1), (S8*) (ascii_sender2)) )
                {
                    U32 i=0,j=0;
                    if(ascii_smsc1[0]=='+')
                        i++;
                        
                    if(ascii_smsc2[0]=='+')
                        j++;
                     if(!strcmp((S8*) (ascii_smsc1+i), (S8*) (ascii_smsc2+j)) )
                              {
                                   MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_EXITS_DUPLICATE_CHECK, TRUE);
                                   return TRUE;
                             }
                   
                 
               }
              
            }

            }
            index++;
            if (index == NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD)
            {
                break;
            }
            if (list_type == SRV_WAP_PUSH_WHITE_LIST)
            {
                curr_addr = &g_push_set_p->white_list[rec_index].white_list[index];
            }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
            else
            {
                curr_addr = &g_push_set_p->black_list[rec_index].black_list[index];
            }
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
        }
        rec_index++;
        index = 0;
    }
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_EXITS_DUPLICATE_CHECK, FALSE);
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_is_valid_phone_num_digit
 * DESCRIPTION
 *  This internal function is used to check if input char is valid phone number character
 * PARAMETERS
 *  ch      [IN]        Character being checked
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
pBOOL srv_wap_push_is_valid_phone_num_digit(S8 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char p_num_special_chars[] = { '+', 'w', 'p' };
    U32 num_of_p_num_special_chars = sizeof(p_num_special_chars);
    U32 incr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch >= '0' && ch <= '9')
    {
        return TRUE;
    }

    for (incr = 0; incr < num_of_p_num_special_chars; incr++)
    {
        if (ch == p_num_special_chars[incr])
        {
            return TRUE;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_str_first_position_search
 * DESCRIPTION
 *  Search for a '+' character in string for only first position
 * PARAMETERS
 *  strNumber       [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL srv_wap_push_str_first_position_search(PS8 strNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pos;
    pBOOL secondFlag = FALSE;
    S8 charToSearch = '+';
    U8 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_ucs2ncmp((PS8) strNumber, (PS8) L"*31#", 4) == 0) ||
        (mmi_ucs2ncmp((PS8) strNumber, (PS8) L"#31#", 4) == 0))
    {
        length = mmi_ucs2strlen(strNumber) - 4;
        pos = 10;
    }
    else
    {
        length = mmi_ucs2strlen(strNumber);
        pos = 2;
    }

    while (strNumber[pos] != '\0')
    {
        if ((strNumber[pos] == charToSearch) && 
            ((strNumber[pos - 2] != '#' && strNumber[pos - 2] != '*') ||
             (strNumber[(length-1)<<1] != '#') ||
             (strNumber[0] == charToSearch)))
        {
            secondFlag = TRUE;
            break;
        }
        pos = pos + 2;
    }

    if (secondFlag == FALSE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_str_no_first_position_search
 * DESCRIPTION
 *  Search for a character in string for only first position
 * PARAMETERS
 *  strNumber           [IN]        
 *  charToSearch        [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL srv_wap_push_str_no_first_position_search(PS8 strNumber, S8 charToSearch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strNumber[0] == charToSearch)
    {
        return FALSE;
    }
    else
    {
        pos = 2;
        while (strNumber[pos] != '\0')
        {
            if (strNumber[pos] == charToSearch)
            {
		if (strNumber[pos+2] != '*' && strNumber[pos+2] != '#')
                    return TRUE;
		else
		    return FALSE;
            }
            pos = pos + 2;
        }
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_check_valid_number
 * DESCRIPTION
 *  Check if number fields contain invalid '+' character.
 * PARAMETERS
 *  number      [IN]        
 * RETURNS
 *  TRUE, if number format is correct.
 *****************************************************************************/
pBOOL srv_wap_push_check_valid_number(S8 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(number) == 0)
    {
        return TRUE;
    }
    return applib_is_valid_number_unicode((U16*)number);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_parse_ph_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ascii_sender        [OUT]       
 *  ascii_smsc          [OUT]       
 *  ascii_number        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_parse_ph_num(S8 *ascii_sender, S8 *ascii_smsc, S8 *ascii_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 len = 0;
    U16 cntr = 0;
    U16 temp = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ascii_number == NULL)
    {
        return;
    }
    len = strlen(ascii_number);
    if ((len == 0) || (*(ascii_number + 0) == '\0'))
    {
        return;
    }
    memset(ascii_sender, '\0', MAX_PUSH_PHN_NUM_LEN);
    while (*(ascii_number + cntr) != WAP_PMG_ADDR_PHONE_SEP)
    {
        *(ascii_sender + cntr) = *(ascii_number + cntr);
        cntr++;
        if (cntr >= MAX_PUSH_PHN_NUM_LEN)
        {
            break;  /* error */
        }
    }

    memset(ascii_smsc, '\0', MAX_PUSH_PHN_NUM_LEN);
    cntr++;
    while (*(ascii_number + cntr) != WAP_PMG_ADDR_PHONE_SEP)
    {
        *(ascii_smsc + temp) = *(ascii_number + cntr);
        cntr++;
        temp++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_get_display_ansii_number_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  out_string      [OUT]       
 *  in_string       [IN]        
 *  len             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_get_display_ansii_number_format(S8 *out_string, S8 *in_string, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ascii_sender[NVRAM_PUSH_SENDER_ADDR_LEN_MAX] = { '\0', '\0' };
    S8 ascii_smsc[NVRAM_PUSH_SENDER_ADDR_LEN_MAX] = { '\0', '\0' };
    S8 temp[NVRAM_PUSH_SENDER_ADDR_LEN_MAX] = { '\0', '\0' };
    S8 sep[4] = {WAP_PMG_ADDR_PHONE_SEP, '\0', '\0', '\0', };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((len == 0) || (*(in_string + 0) == '\0'))
    {
        return;
    }
    memset(out_string, '\0', len);

    srv_wap_push_parse_ph_num(ascii_sender, ascii_smsc, in_string);
    if (*(ascii_sender + 0) == '\0')
    {
        mmi_ucs2cpy(out_string, (S8*) GetString(STR_GLOBAL_NONE));
    }
    else
    {
        mmi_asc_to_ucs2((S8*) out_string, (S8*) ascii_sender);
    }
    mmi_ucs2cat(out_string, (S8*) sep);

    if (*(ascii_smsc + 0) == '\0')
    {
        mmi_ucs2cpy(temp, (S8*) GetString(STR_GLOBAL_NONE));
    }
    else
    {
        mmi_asc_to_ucs2(temp, (S8*) ascii_smsc);
    }
    mmi_ucs2cat(out_string, temp);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_count_bl_and_wl_entry
 * DESCRIPTION
 *  Initialize the global counter of black list and white list entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_count_bl_and_wl_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_count = 0;
    U16 cntr;
    nvram_push_addr_struct *white_list = NULL;

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    nvram_push_addr_struct *black_list = NULL;
    g_push_set_p->total_bl_entry = 0;
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_COUNT_BL_WL_ENTRY_START);
    g_push_set_p->total_wl_entry = 0;
    /* Started counting white list entries */
    while (record_count < SRV_WAP_PUSH_TOTAL_WHITE_LIST_RECORD)
    {
        white_list = g_push_set_p->white_list[record_count].white_list;
        for (cntr = 0; cntr < NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD; cntr++)
        {
            if (white_list[cntr].addr_type != SRV_WAP_PUSH_SENDER_ADDR_TYPE_NONE)
            {
                g_push_set_p->total_wl_entry++;
            }
        }
        record_count++;
    }

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    record_count = 0;
    /* Started counting white list entries */
    while (record_count < SRV_WAP_PUSH_TOTAL_BLACK_LIST_RECORD)
    {
        black_list = g_push_set_p->black_list[record_count].black_list;
        for (cntr = 0; cntr < NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD; cntr++)
        {
            if (black_list[cntr].addr_type != SRV_WAP_PUSH_SENDER_ADDR_TYPE_NONE)
            {
                g_push_set_p->total_bl_entry++;
            }
        }
        record_count++;
    }
    MMI_TRACE(
        SRV_INET_TRC_G4_PUSH,
        TRC_MMI_BRW_PUSH_COUNT_BL_WL_ENTRY_END,
        g_push_set_p->total_wl_entry,
        g_push_set_p->total_bl_entry);
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_convert_to_valid_number_entry
 * DESCRIPTION
 *  This API convert invalid format into valid format.
 * PARAMETERS
 *  phn_number          [IN]
 * RETURNS
 *  void.
 *****************************************************************************/
void srv_wap_push_convert_to_valid_number_entry (S8 *phn_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *ph_num = NULL;
    S8 *token = NULL;
    S8 seps[2] = {WAP_PMG_ADDR_PHONE_SEP, '\0'};
    U16 len = 0;
    U16 token_len = 0;
    U16 copied_len = 0;
    U16 last_token_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (phn_number == NULL)
    {
        return;
    }
    len = strlen(phn_number);
    if (len)
    {
        ph_num = (S8*)OslMalloc (NVRAM_PUSH_SENDER_ADDR_LEN_MAX + 1);
        token = (S8*)OslMalloc (NVRAM_PUSH_SENDER_ADDR_LEN_MAX + 1);
        memset (ph_num, 0, (NVRAM_PUSH_SENDER_ADDR_LEN_MAX + 1));
        memset (token, 0, (NVRAM_PUSH_SENDER_ADDR_LEN_MAX + 1));

        if (len < NVRAM_PUSH_SENDER_ADDR_LEN_MAX)
        {
            strncpy (ph_num, phn_number, len);
        }
        else
        {
            strncpy (ph_num, phn_number, NVRAM_PUSH_SENDER_ADDR_LEN_MAX);
        }

        memset (phn_number, 0, len);

        token_len = strcspn (ph_num,seps);
        strncpy (token, ph_num, token_len);

        if (token_len < len)
        {
            if (token_len > MAX_PUSH_PHN_NUM_LEN)
            {
                strncpy (phn_number, ph_num, MAX_PUSH_PHN_NUM_LEN);
                *(phn_number + MAX_PUSH_PHN_NUM_LEN) = WAP_PMG_ADDR_PHONE_SEP;
            }
            else
            {
                strncpy (phn_number, ph_num, token_len);
                *(phn_number + token_len) = WAP_PMG_ADDR_PHONE_SEP;
            }
            last_token_len = strcspn ((ph_num + (token_len + 1)),seps);
            strncpy (token, (ph_num + (token_len + 1)), last_token_len);

            if (token != NULL)
            {
                if (last_token_len > MAX_PUSH_PHN_NUM_LEN)
                {
                    strncat (phn_number, (ph_num + token_len + 1), MAX_PUSH_PHN_NUM_LEN);
                }
                else
                {
                    strncat (phn_number, (ph_num + token_len + 1), last_token_len);
                }
            }
            copied_len = strlen(phn_number);
            *(phn_number + copied_len) = WAP_PMG_ADDR_PHONE_SEP;
            *(phn_number + copied_len + 1) = '\0';
        }
        else
        {
            if (len > MAX_PUSH_PHN_NUM_LEN)
            {
                strncpy (phn_number, ph_num, MAX_PUSH_PHN_NUM_LEN);
                *(phn_number + MAX_PUSH_PHN_NUM_LEN) = WAP_PMG_ADDR_PHONE_SEP;

                strncat (phn_number, (ph_num + MAX_PUSH_PHN_NUM_LEN), MAX_PUSH_PHN_NUM_LEN);
                copied_len = strlen(phn_number);
                *(phn_number + copied_len) = WAP_PMG_ADDR_PHONE_SEP;
                *(phn_number + copied_len + 1) = '\0';
            }
            else
            {
                strncpy (phn_number, ph_num, MAX_PUSH_PHN_NUM_LEN);
                copied_len = strlen(phn_number);
                *(phn_number + copied_len) = WAP_PMG_ADDR_PHONE_SEP;
                *(phn_number + copied_len + 1) = WAP_PMG_ADDR_PHONE_SEP;
                *(phn_number + copied_len + 2) = '\0';
            }
        }
        OslMfree(ph_num);
        OslMfree(token);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_is_valid_ph_num_entry
 * DESCRIPTION
 *  This API check whether the given phone number is in valid format or not.
 * PARAMETERS
 *  phn_number          [IN]
 * RETURNS
 *  MMI_TRUE if number format is valid otherwise MMI_FALSE.
 *****************************************************************************/
MMI_BOOL srv_wap_push_is_valid_ph_num_entry (S8 *phn_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *string_found = NULL;
    U16 len = 0;
    U16 part_string_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (phn_number == NULL)
    {
        return MMI_FALSE;
    }
    len = strlen(phn_number);
    if (len)
    {
        string_found = strchr(phn_number, WAP_PMG_ADDR_PHONE_SEP);
        if (string_found != NULL)
        {
            part_string_len = strlen (string_found);
            if ((len - part_string_len) > MMI_PHB_NUMBER_LENGTH)
            {
                return MMI_FALSE;
            }
            else
            {
                string_found = strchr((string_found + 1), WAP_PMG_ADDR_PHONE_SEP);
                if (string_found != NULL)
                {
                    if (((part_string_len - 1) - strlen (string_found)) > MMI_PHB_NUMBER_LENGTH)
                    {
                        return MMI_FALSE;
                    }
                    else
                    {
                        return MMI_TRUE;
                    }
                }
                else
                {
                    return MMI_FALSE;
                }
            }
        }
        else
        {
            return MMI_FALSE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_validate_and_set_invalid_entry
 * DESCRIPTION
 *  This API validate a single address of NVRAM data and if found wrong it will reset the data to a valid entry.
 * PARAMETERS
 *  list          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_validate_and_set_invalid_entry (nvram_push_addr_struct *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while ((list[index].addr_type != SRV_WAP_PUSH_SENDER_ADDR_TYPE_NONE) && (index < NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD))
	{
		if (list[index].addr_type == SRV_WAP_PUSH_SENDER_ADDR_TYPE_PHONE_NUMBER)
		{
			if (!srv_wap_push_is_valid_ph_num_entry ((S8*)list[index].addr))
			{
				srv_wap_push_convert_to_valid_number_entry ((S8*)list[index].addr);
			}
		}
        index ++;
	}
}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

/*****************************************************************************/
/******************  END of common util functions  ***************************/
/*****************************************************************************/

/*****************************************************************************/
/******************  NVRAM Related API Section    ****************************/
/*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_commit_push_genearl_settings_to_nvram
 * DESCRIPTION
 *  This API commit the push general settings into NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_commit_push_genearl_settings_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_PUSH_GEN_SETTING_LID,
        1,
        &(g_push_set_p->general_set),
        sizeof(nvram_push_general_setting_struct),
        &error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_read_push_genearl_settings_from_nvram
 * DESCRIPTION
 *  This API read the push general settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_read_push_genearl_settings_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_PUSH_GEN_SETTING_LID,
        1,
        &(g_push_set_p->general_set),
        sizeof(nvram_push_general_setting_struct),
        &error);
}


#ifdef __MMI_WAP_PUSH_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_read_wl_given_record_from_nvram
 * DESCRIPTION
 *  This API read given record of white list from NVRAM
 * PARAMETERS
 *  record      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_read_wl_given_record_from_nvram(U16 record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
	U16 num_of_entries_left = 0;
	nvram_push_wl_addr_struct *buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_READ_WL_FROM_NVRAM_RECORD, record);
	buffer = (nvram_push_wl_addr_struct*) OslMalloc(sizeof(nvram_push_wl_addr_struct));
	memset (buffer, 0, sizeof(nvram_push_wl_addr_struct));

    ReadRecord(
        NVRAM_EF_PUSH_WHITE_LIST_LID,
        record,
        buffer,
        sizeof(nvram_push_wl_addr_struct),
        &error);

	if ((record * NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD) <= NVRAM_PUSH_MAX_NUM_WHITE_LIST)
	{
		memcpy ((&g_push_set_p->white_list[record - 1]), buffer, sizeof(nvram_push_wl_addr_struct));
	}
	else
	{
		num_of_entries_left = NVRAM_PUSH_MAX_NUM_WHITE_LIST % NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD;
		memcpy ((&g_push_set_p->white_list[record - 1]), buffer, (sizeof(nvram_push_addr_struct) * num_of_entries_left));
	}
	OslMfree(buffer);
	buffer = NULL;

	srv_wap_push_validate_and_set_invalid_entry ((g_push_set_p->white_list[record - 1]).white_list);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_read_all_wl_from_nvram
 * DESCRIPTION
 *  This API read all the white list entries from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_read_all_wl_from_nvram()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 wl_record_index = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (wl_record_index <= SRV_WAP_PUSH_TOTAL_WHITE_LIST_RECORD)
    {
        srv_wap_push_read_wl_given_record_from_nvram(wl_record_index);
        wl_record_index++;
    }
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_READ_WL_COMPLETED);
}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */


#ifdef __MMI_WAP_PUSH_BLACK_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_read_bl_given_record_from_nvram
 * DESCRIPTION
 *  This API read given record of black list from NVRAM
 * PARAMETERS
 *  record      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_read_bl_given_record_from_nvram(U16 record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
	U16 num_of_entries_left = 0;
	nvram_push_bl_addr_struct *buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_READ_BL_FROM_NVRAM_RECORD, record);
	buffer = (nvram_push_bl_addr_struct*) OslMalloc(sizeof(nvram_push_bl_addr_struct));
	memset (buffer, 0, sizeof(nvram_push_bl_addr_struct));

    ReadRecord(
        NVRAM_EF_PUSH_BLACK_LIST_LID,
        record,
        buffer,
        sizeof(nvram_push_bl_addr_struct),
        &error);

	if ((record * NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD) <= NVRAM_PUSH_MAX_NUM_BLACK_LIST)
	{
		memcpy ((&g_push_set_p->black_list[record - 1]), buffer, sizeof(nvram_push_bl_addr_struct));
	}
	else
	{
		num_of_entries_left = NVRAM_PUSH_MAX_NUM_BLACK_LIST % NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD;
		memcpy ((&g_push_set_p->black_list[record - 1]), buffer, (sizeof(nvram_push_addr_struct) * num_of_entries_left));
	}
	OslMfree(buffer);
	buffer = NULL;

    srv_wap_push_validate_and_set_invalid_entry ((g_push_set_p->black_list[record - 1]).black_list);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_read_all_bl_from_nvram
 * DESCRIPTION
 *  This API read all the black list entries from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_read_all_bl_from_nvram()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 bl_record_index = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (bl_record_index <= SRV_WAP_PUSH_TOTAL_BLACK_LIST_RECORD)
    {
        srv_wap_push_read_bl_given_record_from_nvram(bl_record_index);
        bl_record_index++;
    }
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_READ_BL_COMPLETED);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_write_bl_given_record_in_nvram
 * DESCRIPTION
 *  This API commits given record of black list into NVRAM
 * PARAMETERS
 *  record      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_write_bl_given_record_in_nvram(U16 record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_WRITE_BL_NVRAM_RECORD, record);
    WriteRecord(
        NVRAM_EF_PUSH_BLACK_LIST_LID,
        record,
        &(g_push_set_p->black_list[record - 1]),
        sizeof(nvram_push_bl_addr_struct),
        &error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_write_all_bl_in_nvram
 * DESCRIPTION
 *  This API commits all the black list entries into NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_write_all_bl_in_nvram()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 bl_record_index = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (bl_record_index <= SRV_WAP_PUSH_TOTAL_BLACK_LIST_RECORD)
    {
        srv_wap_push_write_bl_given_record_in_nvram(bl_record_index);
        bl_record_index++;
    }
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_WRITE_BL_COMPLETED);
}
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */


#ifdef __MMI_WAP_PUSH_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_write_wl_given_record_in_nvram
 * DESCRIPTION
 *  This API commits given record of white list into NVRAM
 * PARAMETERS
 *  record      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_write_wl_given_record_in_nvram(U16 record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_WRITE_WL_NVRAM_RECORD, record);
    WriteRecord(
        NVRAM_EF_PUSH_WHITE_LIST_LID,
        record,
        &(g_push_set_p->white_list[record - 1]),
        sizeof(nvram_push_wl_addr_struct),
        &error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_write_all_wl_in_nvram
 * DESCRIPTION
 *  This API commits all the white list entries into NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_write_all_wl_in_nvram()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 wl_record_index = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (wl_record_index <= SRV_WAP_PUSH_TOTAL_WHITE_LIST_RECORD)
    {
        srv_wap_push_write_wl_given_record_in_nvram(wl_record_index);
        wl_record_index++;
    }
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_WRITE_WL_COMPLETED);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_write_wl_entry_of_array_in_nvram
 * DESCRIPTION
 *  This API use to decide the NVRAM record for a given entry and commit that record in NVRAM.
 * PARAMETERS
 *  array_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_write_wl_entry_of_array_in_nvram(U16 array_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_index = 1;
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wap_push_get_record_and_index(&record_index, &index, array_index);
    srv_wap_push_write_wl_given_record_in_nvram((U16) (record_index + 1));
}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_set_default_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_set_default_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wap_push_read_push_genearl_settings_from_nvram();
}

/*****************************************************************************/
/******************  END of NVRAM Related API Section    *********************/
/*****************************************************************************/

/*****************************************************************************/
/******************  Start of UI related API Section  ************************/
/*****************************************************************************/


#ifdef __MMI_WAP_PUSH_BLACK_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_delete_from_black_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_delete_from_black_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;
    U16 rec_index = 0;
    nvram_push_addr_struct *curr_addr = NULL;
    nvram_push_addr_struct *next_addr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wap_push_get_record_and_index(&rec_index, &index, g_push_set_p->selected_bl_entry);
    while (rec_index < SRV_WAP_PUSH_TOTAL_BLACK_LIST_RECORD)
    {
        do
        {
            curr_addr = &g_push_set_p->black_list[rec_index].black_list[index];
            if (index < (NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD - 1))
            {
                next_addr = &g_push_set_p->black_list[rec_index].black_list[index + 1];
            }
            else
            {
                next_addr = &g_push_set_p->black_list[rec_index + 1].black_list[index];
            }
            curr_addr->addr_type = next_addr->addr_type;
            memset(curr_addr->addr, 0, NVRAM_PUSH_SENDER_ADDR_LEN_MAX);
            strcpy((S8*) curr_addr->addr, (S8*) next_addr->addr);
            index++;
            if (index == NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD)
            {
                break;
            }

        } while ((curr_addr->addr_type != SRV_WAP_PUSH_SENDER_ADDR_TYPE_NONE) &&
                 (index < NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD));
        if (index != NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD)
        {
            break;
        }
        rec_index++;
        index = 0;
    }
}
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */


#ifdef __MMI_WAP_PUSH_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_delete_from_white_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_delete_from_white_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;
    U16 rec_index = 0;
    nvram_push_addr_struct *curr_addr = NULL;
    nvram_push_addr_struct *next_addr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wap_push_get_record_and_index(&rec_index, &index, g_push_set_p->selected_wl_entry);
    while (rec_index < SRV_WAP_PUSH_TOTAL_WHITE_LIST_RECORD)
    {
        do
        {
            curr_addr = &g_push_set_p->white_list[rec_index].white_list[index];
            if (index < (NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD - 1))
            {
                next_addr = &g_push_set_p->white_list[rec_index].white_list[index + 1];
            }
            else
            {
                next_addr = &g_push_set_p->white_list[rec_index + 1].white_list[index];
            }
            curr_addr->addr_type = next_addr->addr_type;
            memset(curr_addr->addr, 0, NVRAM_PUSH_SENDER_ADDR_LEN_MAX);
            strcpy((S8*) curr_addr->addr, (S8*) next_addr->addr);
            index++;
            if (index == NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD)
            {
                break;
            }

        } while ((curr_addr->addr_type != SRV_WAP_PUSH_SENDER_ADDR_TYPE_NONE) &&
                 (index < NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD));
        if (index != NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD)
        {
            break;
        }
        rec_index++;
        index = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_delete_list_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_delete_list_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_push_set_p->selected_list_type == SRV_WAP_PUSH_WHITE_LIST)
    {
        srv_wap_push_delete_from_white_list();
        srv_wap_push_write_all_wl_in_nvram();
        g_push_set_p->total_wl_entry--;
        srv_wap_send_white_list_to_service_layer();
    }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    else
    {
        srv_wap_push_delete_from_black_list();
        srv_wap_push_write_all_bl_in_nvram();
        g_push_set_p->total_bl_entry--;
        srv_wap_send_black_list_to_service_layer();
    }
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    srv_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_EXPLICITLY_DELETED, STR_GLOBAL_DELETED);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_delete_list_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_delete_list_entry_ex(U8 *index_array, U8 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 loop_count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_push_set_p->selected_list_type == SRV_WAP_PUSH_WHITE_LIST)
    {
		for(;loop_count<count;loop_count++)
		{
			g_push_set_p->selected_wl_entry = index_array[loop_count];
			srv_wap_push_delete_from_white_list();
			g_push_set_p->total_wl_entry--;
		}

        srv_wap_push_write_all_wl_in_nvram();
        
        srv_wap_send_white_list_to_service_layer();
    }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    else
    {
		for(;loop_count<count;loop_count++)
		{
			g_push_set_p->selected_bl_entry = index_array[loop_count];
			srv_wap_push_delete_from_black_list();
			g_push_set_p->total_bl_entry--;
		}
			srv_wap_push_write_all_bl_in_nvram();
			srv_wap_send_black_list_to_service_layer();
    }
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    srv_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_EXPLICITLY_DELETED, STR_GLOBAL_DELETED);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_add_modify_list
 * DESCRIPTION
 *  Add or modify the given record into NVRAM.
 * PARAMETERS
 *  ascii_addr      [IN]        
 *  addr_type       [IN]        
 *  list_type       [IN]        
 *  array_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
srv_wap_push_add_list_error_enum srv_wap_push_add_modify_list(S8 *ascii_addr, U16 addr_type, U16 list_type, U16 array_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 rec_index = 0;
    U16 index = 0;
    nvram_push_addr_struct *curr_item = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ENTERS_ADD_MODIFY);
    if (srv_wap_push_check_duplicate_entry(list_type, addr_type, ascii_addr))
    {
        MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_EXITS_ADD_MODIFY, SRV_WAP_PUSH_ERROR_DUPLICATE_ENTRY);
        return SRV_WAP_PUSH_ERROR_DUPLICATE_ENTRY;
    }
    srv_wap_push_get_record_and_index(&rec_index, &index, array_index);
    if (list_type == SRV_WAP_PUSH_WHITE_LIST)
    {
        curr_item = &g_push_set_p->white_list[rec_index].white_list[index];
        curr_item->addr_type = (U8)addr_type;
        strcpy((S8*) curr_item->addr, ascii_addr);
        srv_wap_push_write_wl_given_record_in_nvram((U16) (rec_index + 1));
    }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    else
    {
        curr_item = &g_push_set_p->black_list[rec_index].black_list[index];
        curr_item->addr_type = (U8)addr_type;
        strcpy((S8*) curr_item->addr, ascii_addr);
        srv_wap_push_write_bl_given_record_in_nvram((U16) (rec_index + 1));
    }
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_EXITS_ADD_MODIFY, SRV_WAP_PUSH_ERROR_SUCCESS);
    return SRV_WAP_PUSH_ERROR_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_setting_modify_or_add_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_wap_push_add_list_error_enum srv_wap_push_setting_modify_or_add_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ascii_addr[NVRAM_PUSH_SENDER_ADDR_LEN_MAX] = { '\0', '\0', };
    S8 smsc_addr[NVRAM_PUSH_SENDER_ADDR_LEN_MAX] = { '\0', '\0', };
    S8 ascii_sep[2] = {WAP_PMG_ADDR_PHONE_SEP, '\0' };
    U16 array_idx = 0;
    srv_wap_push_add_list_error_enum add_error = SRV_WAP_PUSH_ERROR_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc(ascii_addr, (S8*) g_push_set_p->sender_address);
    strcat(ascii_addr, ascii_sep);
    mmi_ucs2_to_asc(smsc_addr, (S8*) g_push_set_p->smsc_address);
    strcat(ascii_addr, smsc_addr);
    strcat(ascii_addr, ascii_sep);
    if (g_push_set_p->selected_list_type == SRV_WAP_PUSH_WHITE_LIST)
    {
        if (g_push_set_p->slected_opr_type == SRV_WAP_PUSH_OPR_ADD_NEW)
        {
            array_idx = g_push_set_p->total_wl_entry;
        }
        else
        {
            array_idx = g_push_set_p->selected_wl_entry;
        }
    }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    else
    {
        if (g_push_set_p->slected_opr_type == SRV_WAP_PUSH_OPR_ADD_NEW)
        {
            array_idx = g_push_set_p->total_bl_entry;
        }
        else
        {
            array_idx = g_push_set_p->selected_bl_entry;
        }
    }
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    add_error = srv_wap_push_add_modify_list(
                    ascii_addr,
                    SRV_WAP_PUSH_SENDER_ADDR_TYPE_PHONE_NUMBER,
                    g_push_set_p->selected_list_type,
                    array_idx);
    if (add_error == SRV_WAP_PUSH_ERROR_DUPLICATE_ENTRY)
    {
      #ifndef __COSMOS_MMI_PACKAGE__
         srv_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_FAILURE, STR_ID_PUSH_SAME_ITEM_EXIST);/*Need to be changed*/
      #endif
        //srv_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_FAILURE, STR_GLOBAL_ERROR);
        return SRV_WAP_PUSH_ERROR_DUPLICATE_ENTRY;
    }
    else if (add_error == SRV_WAP_PUSH_ERROR_SUCCESS)
    {
        if (g_push_set_p->selected_list_type == SRV_WAP_PUSH_WHITE_LIST)
        {
            if (g_push_set_p->slected_opr_type == SRV_WAP_PUSH_OPR_ADD_NEW)
            {
                g_push_set_p->total_wl_entry++;
            }
            srv_wap_send_white_list_to_service_layer();
        }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
        else
        {
            if (g_push_set_p->slected_opr_type == SRV_WAP_PUSH_OPR_ADD_NEW)
            {
                g_push_set_p->total_bl_entry++;
            }
            srv_wap_send_black_list_to_service_layer();
        }
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    }
    srv_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_EXPLICITLY_SAVED, STR_GLOBAL_SAVED);
	return SRV_WAP_PUSH_ERROR_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_setting_modify_or_add_ip_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_wap_push_add_list_error_enum srv_wap_push_setting_modify_or_add_ip_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ip_sep[2] = { '.', '\0' };
    S8 temp_ip_part[SRV_WAP_PUSH_MAX_PART_IP_ADDRESS] = { '\0', };
    U16 array_idx = 0;
    srv_wap_push_add_list_error_enum add_error = SRV_WAP_PUSH_ERROR_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc(g_push_set_p->ip_addr, g_push_set_p->IP1);
    strcat((S8*) g_push_set_p->ip_addr, (S8*) ip_sep);

    mmi_ucs2_to_asc(temp_ip_part, g_push_set_p->IP2);
    strcat(g_push_set_p->ip_addr, temp_ip_part);
    strcat((S8*) g_push_set_p->ip_addr, (S8*) ip_sep);

    mmi_ucs2_to_asc(temp_ip_part, g_push_set_p->IP3);
    strcat(g_push_set_p->ip_addr, temp_ip_part);
    strcat((S8*) g_push_set_p->ip_addr, (S8*) ip_sep);

    mmi_ucs2_to_asc(temp_ip_part, g_push_set_p->IP4);
    strcat(g_push_set_p->ip_addr, temp_ip_part);

    if (g_push_set_p->selected_list_type == SRV_WAP_PUSH_WHITE_LIST)
    {
        if (g_push_set_p->slected_opr_type == SRV_WAP_PUSH_OPR_ADD_NEW)
        {
            array_idx = g_push_set_p->total_wl_entry;
        }
        else
        {
            array_idx = g_push_set_p->selected_wl_entry;
        }
    }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    else
    {
        if (g_push_set_p->slected_opr_type == SRV_WAP_PUSH_OPR_ADD_NEW)
        {
            array_idx = g_push_set_p->total_bl_entry;
        }
        else
        {
            array_idx = g_push_set_p->selected_bl_entry;
        }
    }
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

    add_error = srv_wap_push_add_modify_list(
                    g_push_set_p->ip_addr,
                    SRV_WAP_PUSH_SENDER_ADDR_TYPE_IP_ADDRESS,
                    g_push_set_p->selected_list_type,
                    array_idx);
    if (add_error == SRV_WAP_PUSH_ERROR_DUPLICATE_ENTRY)
    {
      #ifndef __COSMOS_MMI_PACKAGE__
        srv_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_FAILURE, STR_ID_PUSH_SAME_ITEM_EXIST);/*Need to be changed*/
      #endif
        //srv_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_FAILURE, STR_GLOBAL_ERROR);
        return SRV_WAP_PUSH_ERROR_DUPLICATE_ENTRY;
    }

    if (g_push_set_p->selected_list_type == SRV_WAP_PUSH_WHITE_LIST)
    {
        if (g_push_set_p->slected_opr_type == SRV_WAP_PUSH_OPR_ADD_NEW)
        {
            g_push_set_p->total_wl_entry++;
        }
        srv_wap_send_white_list_to_service_layer();
    }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    else
    {
        if (g_push_set_p->slected_opr_type == SRV_WAP_PUSH_OPR_ADD_NEW)
        {
            g_push_set_p->total_bl_entry++;
        }
        srv_wap_send_black_list_to_service_layer();
    }
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    srv_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_EXPLICITLY_SAVED, STR_GLOBAL_SAVED);
	return SRV_WAP_PUSH_ERROR_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_setting_delete_all_list_entry
 * DESCRIPTION
 *  This function delete all selected list from NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_setting_delete_all_list_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num_rec = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ENTERS_DELETE_ALL, g_push_set_p->selected_list_type);
    if (g_push_set_p->selected_list_type == SRV_WAP_PUSH_WHITE_LIST)
    {
        while (num_rec < SRV_WAP_PUSH_TOTAL_WHITE_LIST_RECORD)
        {
            memset(&g_push_set_p->white_list[num_rec], 0, sizeof(nvram_push_wl_addr_struct));
            num_rec++;
        }
        srv_wap_push_write_all_wl_in_nvram();
        g_push_set_p->total_wl_entry = 0;
        srv_wap_send_white_list_to_service_layer();
    }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    else
    {
        while (num_rec < SRV_WAP_PUSH_TOTAL_BLACK_LIST_RECORD)
        {
            memset(&g_push_set_p->black_list[num_rec], 0, sizeof(nvram_push_bl_addr_struct));
            num_rec++;
        }
        srv_wap_push_write_all_bl_in_nvram();
        g_push_set_p->total_bl_entry = 0;
        srv_wap_send_black_list_to_service_layer();
    }
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    srv_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_EXPLICITLY_DELETED, STR_GLOBAL_DELETED);
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_EXITS_DELETE_ALL);
}

#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_get_setting_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  set_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_wap_push_get_setting_index(U16 set_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (set_type)
    {
        case SRV_WAP_PUSH_SETTING_ENABLE:
            switch (g_push_set_p->general_set.enable_push)
            {
                case WAP_PMG_RETR_DISABLED:
                    return SRV_WAP_PUSH_ENABLE_SETTING_DISABLE;
                    
            #ifdef __MMI_WAP_PUSH_WHITE_LIST__
                case WAP_PMG_RETR_ACCEPT_AUTH_OR_TRUSTED:
                    return SRV_WAP_PUSH_ENABLE_SETTING_ACCEPT_AUTHENTICATED;
            #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
                case WAP_PMG_RETR_ACCEPT_ALL:
                    return SRV_WAP_PUSH_ENABLE_SETTING_ACCEPT_ALL;
                    
            }
            break;
        case SRV_WAP_PUSH_SETTING_ENABLE_SL:
            switch (g_push_set_p->general_set.sl_setting)
            {
                case SRV_WAP_PUSH_SL_SETTING_PROMPT:
                    return SRV_WAP_PUSH_SL_SETTING_PROMPT;
                    
                case SRV_WAP_PUSH_SL_SETTING_AUTO_LAUNCH:
                    return SRV_WAP_PUSH_SL_SETTING_AUTO_LAUNCH;
                   
                case SRV_WAP_PUSH_SL_SETTING_DISABLED:
                    return SRV_WAP_PUSH_SL_SETTING_DISABLED;
                   
            }
            break;
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        case SRV_WAP_PUSH_SETTING_ENABLE_WHITE_LIST:
            switch (g_push_set_p->general_set.enable_white_list)
            {
                case WAP_PMG_WL_DISABLED:
                    return SRV_WAP_PUSH_WL_SETTING_DISABLE;
                    
                case WAP_PMG_WL_ACTION_NOTIFY:
                    return SRV_WAP_PUSH_WL_SETTING_NOTIFY;
                    
                case WAP_PMG_WL_ACTION_DISCARD:
                    return SRV_WAP_PUSH_WL_SETTING_DISCARD;
                    
            }
            break;
    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        case SRV_WAP_PUSH_SETTING_ENABLE_BLACK_LIST:
            switch (g_push_set_p->general_set.enable_black_list)
            {
                case WAP_PMG_BL_DISABLED:
                    return SRV_WAP_PUSH_BL_SETTING_DISABLE;
                    
                case WAP_PMG_BL_ACTION_NOTIFY:
                    return SRV_WAP_PUSH_BL_SETTING_NOTIFY;
                   
            }
            break;
    #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    }
    return 0;   /* error */
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_set_enable_push
 * DESCRIPTION
 *  Use to set enable push setting
 * PARAMETERS
 *  enable_push
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_set_enable_push(kal_uint8 enable_push)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

switch(enable_push)
{
		case SRV_WAP_PUSH_ENABLE_SETTING_ACCEPT_ALL:
			g_push_set_p->general_set.enable_push = WAP_PMG_RETR_ACCEPT_ALL;
			break;

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
		case SRV_WAP_PUSH_ENABLE_SETTING_ACCEPT_AUTHENTICATED:
			g_push_set_p->general_set.enable_push = WAP_PMG_RETR_ACCEPT_AUTH_OR_TRUSTED;        
			break;
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

		case SRV_WAP_PUSH_ENABLE_SETTING_DISABLE:              
			g_push_set_p->general_set.enable_push = WAP_PMG_RETR_DISABLED;
			break;


			default:
			break;
}
    srv_wap_push_commit_push_genearl_settings_to_nvram();
    srv_wap_push_send_config_ind();
    srv_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_EXPLICITLY_SAVED, STR_GLOBAL_SAVED);
}



/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_set_sl_setting
 * DESCRIPTION
 *  Use to set sl setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_set_sl_setting(kal_uint8 sl_setting)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

switch(sl_setting)
{
		case SRV_WAP_PUSH_SL_SETTING_PROMPT:
			g_push_set_p->general_set.sl_setting = SRV_WAP_PUSH_SL_SETTING_PROMPT;                   
                        break;
                case SRV_WAP_PUSH_SL_SETTING_AUTO_LAUNCH:
					g_push_set_p->general_set.sl_setting = SRV_WAP_PUSH_SL_SETTING_AUTO_LAUNCH;
                    break;
                case SRV_WAP_PUSH_SL_SETTING_DISABLED:
    g_push_set_p->general_set.sl_setting = SRV_WAP_PUSH_SL_SETTING_DISABLED;
                    break;
				default:
					break;
}
    srv_wap_push_commit_push_genearl_settings_to_nvram();
    srv_wap_push_send_config_ind();
    srv_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_EXPLICITLY_SAVED, STR_GLOBAL_SAVED);

}


#ifdef __MMI_WAP_PUSH_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_set_wl_setting
 * DESCRIPTION
 *  Use to set whitelist setting.
 * PARAMETERS
 *  wl_setting
 * RETURNS
 *  void
 *****************************************************************************/
    
void srv_wap_push_set_wl_setting(kal_uint8 wl_setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

switch(wl_setting)
{
		case SRV_WAP_PUSH_WL_SETTING_DISABLE:
			g_push_set_p->general_set.enable_white_list = WAP_PMG_WL_DISABLED;               
                        break;
                case SRV_WAP_PUSH_WL_SETTING_NOTIFY:
			g_push_set_p->general_set.enable_white_list = WAP_PMG_WL_ACTION_NOTIFY;
                        break;
                case SRV_WAP_PUSH_WL_SETTING_DISCARD:
			g_push_set_p->general_set.enable_white_list = WAP_PMG_WL_ACTION_DISCARD;
                        break; 
		default:
			break;
}
    srv_wap_push_commit_push_genearl_settings_to_nvram();
    srv_wap_push_send_config_ind();
    srv_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_EXPLICITLY_SAVED, STR_GLOBAL_SAVED);
}
#endif /*__MMI_WAP_PUSH_WHITE_LIST__*/


#ifdef __MMI_WAP_PUSH_BLACK_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_set_bl_setting
 * DESCRIPTION
 *  Use to set blacklist setting.
 * PARAMETERS
 *  bl_setting
 * RETURNS
 *  void
 *****************************************************************************/
    
void srv_wap_push_set_bl_setting(kal_uint8 bl_setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

switch(bl_setting)
{
		case SRV_WAP_PUSH_BL_SETTING_DISABLE:
			g_push_set_p->general_set.enable_black_list = WAP_PMG_BL_DISABLED;                
                        break;
                case SRV_WAP_PUSH_BL_SETTING_NOTIFY:
			g_push_set_p->general_set.enable_black_list = WAP_PMG_BL_ACTION_NOTIFY;
                        break;

		default:
			break;
}
    srv_wap_push_commit_push_genearl_settings_to_nvram();
    srv_wap_push_send_config_ind();
    srv_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_EXPLICITLY_SAVED, STR_GLOBAL_SAVED);
}
#endif /*__MMI_WAP_PUSH_BLACK_LIST__*/


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_init_nvram_push_setting_data
 * DESCRIPTION
 *  Read the NVRAM data of various push seting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_init_nvram_push_setting_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    g_push_set_p->total_wl_entry = 0;
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    g_push_set_p->total_bl_entry = 0;
    srv_wap_push_read_all_bl_from_nvram();
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    srv_wap_push_read_all_wl_from_nvram();
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    srv_wap_push_read_push_genearl_settings_from_nvram();
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_setting_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_setting_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_delete_setting_struct event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wap_push_init_nvram_push_setting_data();
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    srv_wap_push_count_bl_and_wl_entry();
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    MMI_FRM_INIT_EVENT(&event, EVT_ID_SRV_PUSH_DELETE_PUSH_SETTING);
    mmi_frm_cb_emit_event((mmi_event_struct*)&event);
}

/*****************************************************************************/
/******************  END of UI related API Section  **************************/
/*****************************************************************************/

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_cancel_ota_replace
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_cancel_ota_replace(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_push_set_p->sender_address, '\0', sizeof(g_push_set_p->sender_address));
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_USER_CANCEL_OTA_SETTING_REPLACE);
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_replace_selected_wl_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_replace_selected_wl_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_add_list_error_enum error = SRV_WAP_PUSH_ERROR_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error = srv_wap_push_add_modify_list(
                g_push_set_p->sender_address,
                g_push_set_p->ota_addr_type,
                SRV_WAP_PUSH_WHITE_LIST,
                g_push_set_p->selected_wl_entry);
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_USER_ACCEPT_OTA_SETTING_REPLACE, error);
    memset(g_push_set_p->sender_address, '\0', sizeof(g_push_set_p->sender_address));
    srv_wap_send_white_list_to_service_layer();
    g_push_set_p->slected_opr_type = SRV_WAP_PUSH_OPR_TOTAL;
#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
    srv_wap_push_ota_add_trustlist_result_callback(error);
#endif 
}

#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_add_wl_ota_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  add_type        [IN]        
 *  addr            [IN]        
 * RETURNS
 *  error enum value.
 *****************************************************************************/
srv_wap_push_add_list_error_enum srv_wap_push_add_wl_ota_addr(srv_wap_push_sender_addr_type_enum add_type, S8 *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_add_list_error_enum error = SRV_WAP_PUSH_ERROR_SUCCESS;
    S8 temp_ip[16] = {0};
    srv_wap_push_delete_setting_struct event_setting;
    srv_wap_push_ota_list_entry_struct event_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (addr == NULL)
    {
        return SRV_WAP_PUSH_ERROR_NULL_ADDR;
    }

    if (add_type == SRV_WAP_PUSH_SENDER_ADDR_TYPE_IP_ADDRESS)
    {
        srv_push_covert_ip_string_to_proper_format (addr, temp_ip, 16);
        addr = temp_ip;
    }
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ADD_OTA_REQ, add_type);
    MMI_FRM_INIT_EVENT(&event_setting, EVT_ID_SRV_PUSH_DELETE_PUSH_SETTING);
    mmi_frm_cb_emit_event((mmi_event_struct*)&event_setting);

	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ADD_OTA_REQ_TOTAL_WL, g_push_set_p->total_wl_entry);
    if (g_push_set_p->total_wl_entry >= NVRAM_PUSH_MAX_NUM_WHITE_LIST)
    {
        g_push_set_p->selected_list_type = SRV_WAP_PUSH_WHITE_LIST;
        g_push_set_p->slected_opr_type = SRV_WAP_PUSH_OPR_ADD_OTA;
        g_push_set_p->ota_addr_type = add_type;
        strcpy(g_push_set_p->sender_address, addr);
        MMI_FRM_INIT_EVENT(&event_list, EVT_ID_SRV_PUSH_OTA_LIST_ENTRY);
        mmi_frm_cb_emit_event((mmi_event_struct*)&event_list);
        return SRV_WAP_PUSH_ERROR_LIST_FULL;
    }
    else
    {
        error = srv_wap_push_add_modify_list(
                    addr,
                    (U16) add_type,
                    SRV_WAP_PUSH_WHITE_LIST,
                    g_push_set_p->total_wl_entry);
        if (SRV_WAP_PUSH_ERROR_SUCCESS == error)
        {
            g_push_set_p->total_wl_entry++;
            srv_wap_send_white_list_to_service_layer();
        }
        return error;
    }
}
#endif /* __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__ */ 

#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_set_setting_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  set_type        [IN]  
 *  index           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_set_setting_index(U16 set_type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (set_type)
    {
        case SRV_WAP_PUSH_SETTING_ENABLE:
            switch (index)
            {
                case SRV_WAP_PUSH_ENABLE_SETTING_DISABLE:
                    g_push_set_p->general_set.enable_push = WAP_PMG_RETR_DISABLED;
                    break;
            #ifdef __MMI_WAP_PUSH_WHITE_LIST__
                case SRV_WAP_PUSH_ENABLE_SETTING_ACCEPT_AUTHENTICATED:
                    g_push_set_p->general_set.enable_push = WAP_PMG_RETR_ACCEPT_AUTH_OR_TRUSTED;
                    break;
            #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
                case SRV_WAP_PUSH_ENABLE_SETTING_ACCEPT_ALL:
                    g_push_set_p->general_set.enable_push = WAP_PMG_RETR_ACCEPT_ALL;
                    break;
            }
            break;
        case SRV_WAP_PUSH_SETTING_ENABLE_SL:
            switch (index)
            {
                case SRV_WAP_PUSH_SL_SETTING_PROMPT:
                    g_push_set_p->general_set.sl_setting = SRV_WAP_PUSH_SL_SETTING_PROMPT;
                    break;
                case SRV_WAP_PUSH_SL_SETTING_AUTO_LAUNCH:
                    g_push_set_p->general_set.sl_setting = SRV_WAP_PUSH_SL_SETTING_AUTO_LAUNCH;
                    break;
                case SRV_WAP_PUSH_SL_SETTING_DISABLED:
                    g_push_set_p->general_set.sl_setting = SRV_WAP_PUSH_SL_SETTING_DISABLED;
                    break;
            }
            break;
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        case SRV_WAP_PUSH_SETTING_ENABLE_WHITE_LIST:
            switch (index)
            {
                case SRV_WAP_PUSH_WL_SETTING_DISABLE:
                    g_push_set_p->general_set.enable_white_list = WAP_PMG_WL_DISABLED;
                    break;
                case SRV_WAP_PUSH_WL_SETTING_NOTIFY:
                    g_push_set_p->general_set.enable_white_list = WAP_PMG_WL_ACTION_NOTIFY;
                    break;
                case SRV_WAP_PUSH_WL_SETTING_DISCARD:
                    g_push_set_p->general_set.enable_white_list = WAP_PMG_WL_ACTION_DISCARD;
                    break;
            }
            break;
    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        case SRV_WAP_PUSH_SETTING_ENABLE_BLACK_LIST:
            switch (index)
            {
                case SRV_WAP_PUSH_BL_SETTING_DISABLE:
                    g_push_set_p->general_set.enable_black_list = WAP_PMG_BL_DISABLED;
                    break;
                case SRV_WAP_PUSH_BL_SETTING_NOTIFY:
                    g_push_set_p->general_set.enable_black_list = WAP_PMG_BL_ACTION_NOTIFY;
                    break;
            }
            break;
    #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    }
    srv_wap_push_commit_push_genearl_settings_to_nvram();
    srv_wap_push_send_config_ind();
}


void srv_wap_push_get_trustlist_item(S32 itemIndex, WCHAR *strBuff)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ucs2_str[(NVRAM_PUSH_SENDER_ADDR_LEN_MAX + 2) * ENCODING_LENGTH] = { '\0', '\0', };
    U16 record_index = 0;
    U16 index = 0;
    U16 string_len = 0;
    nvram_push_addr_struct *curr_item = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_push_set_p->selected_list_type == SRV_WAP_PUSH_WHITE_LIST)
    {
        srv_wap_push_get_record_and_index(&record_index, &index, itemIndex);
        curr_item = &g_push_set_p->white_list[record_index].white_list[index];
    }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    else
    {
        srv_wap_push_get_record_and_index(&record_index, &index, itemIndex);
        curr_item = &g_push_set_p->black_list[record_index].black_list[index];
    }
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

    if (curr_item->addr_type == SRV_WAP_PUSH_SENDER_ADDR_TYPE_PHONE_NUMBER)
    {
        string_len = strlen((S8*) curr_item->addr);
        srv_wap_push_get_display_ansii_number_format(ucs2_str, (S8*) curr_item->addr, string_len);
        string_len = mmi_ucs2strlen(ucs2_str);

        if (string_len > MAX_SUBMENU_CHARACTERS)
        {
            mmi_ucs2ncpy((S8*) strBuff, (S8*) ucs2_str, (MAX_SUBMENU_CHARACTERS - 3));
            mmi_ucs2cat((S8*) strBuff, ".\0.\0.\0");
        }
        else
        {
            mmi_ucs2ncpy((S8*) strBuff, (S8*) ucs2_str, string_len);
        }
    }
    else if (curr_item->addr_type == SRV_WAP_PUSH_SENDER_ADDR_TYPE_IP_ADDRESS)
    {
        mmi_asc_to_ucs2((S8*) strBuff, (S8*) curr_item->addr);
    }
    
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
}



U16 srv_wap_push_get_number_of_white_list (void)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   return g_push_set_p->total_wl_entry;
#else
return 0;
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_number_of_black_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  number of black list.
 *****************************************************************************/
U16 srv_wap_push_get_number_of_black_list (void)
{
#ifdef __MMI_WAP_PUSH_BLACK_LIST__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */

    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   return g_push_set_p->total_bl_entry;
#else
return 0;
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

}

U16 srv_wap_push_modify_add_sender_smsc_address(void)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 rec_index = 0;
    U16 index = 0;
    S8 ascii_addr[NVRAM_PUSH_SENDER_ADDR_LEN_MAX] = { '\0', '\0', };
    S8 smsc_addr[NVRAM_PUSH_SENDER_ADDR_LEN_MAX] = { '\0', '\0', };
    S8 ascii_sep[2] = {WAP_PMG_ADDR_PHONE_SEP, '\0' };
    nvram_push_addr_struct *curr_item = NULL;
	srv_wap_push_add_list_error_enum add_error = SRV_WAP_PUSH_ERROR_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_ucs2strlen(g_push_set_p->sender_address) == 0) && ((mmi_ucs2strlen(g_push_set_p->smsc_address) == 0)))
    {
        //mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_ID_PUSH_ATLEAST_ONE_FIELD_REQUIRED);
        return SRV_WAP_PUSH_TL_NO_FIELD_ERROR;
    }
    if (g_push_set_p->slected_opr_type == SRV_WAP_PUSH_OPR_EDIT)
    {
        mmi_ucs2_to_asc(ascii_addr, (S8*) g_push_set_p->sender_address);
        strcat(ascii_addr, ascii_sep);
        mmi_ucs2_to_asc(smsc_addr, (S8*) g_push_set_p->smsc_address);
        strcat(ascii_addr, smsc_addr);
        strcat(ascii_addr, ascii_sep);
        if (g_push_set_p->selected_list_type == SRV_WAP_PUSH_WHITE_LIST)
        {
            srv_wap_push_get_record_and_index(&rec_index, &index, g_push_set_p->selected_wl_entry);
            curr_item = &g_push_set_p->white_list[rec_index].white_list[index];
        }
    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        else
        {
            srv_wap_push_get_record_and_index(&rec_index, &index, g_push_set_p->selected_bl_entry);
            curr_item = &g_push_set_p->black_list[rec_index].black_list[index];
        }
    #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
        if (!(strcmp((S8*) curr_item->addr, ascii_addr)))   /* User edited again with same entry no need to modify */
        {
			//return SRV_WAP_PUSH_TL_SAME_ENTRY;
            return SRV_WAP_PUSH_TL_NO_ERROR;
        }
    }
    if (!srv_wap_push_check_valid_number(g_push_set_p->sender_address))
    {
        //mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_ID_PUSH_SETTING_INVALID_SENDER);
        return SRV_WAP_PUSH_TL_INVALID_SENDER;
    }
    if (!srv_wap_push_check_valid_number(g_push_set_p->smsc_address))
    {
        //mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_ID_PUSH_SETTING_INVALID_SMSC);
        return SRV_WAP_PUSH_TL_INVALID_SMSC;
    }
    /*
    mmi_wap_push_event_based_confirm (
        STR_GLOBAL_SAVE_ASK,
        mmi_wap_push_setting_modify_or_add_list,
        mmi_wap_push_go_back_two_screen,
		mmi_wap_push_setting_modify_or_add_list);*/


 add_error =  srv_wap_push_setting_modify_or_add_list();
 if(add_error == SRV_WAP_PUSH_ERROR_DUPLICATE_ENTRY)
	 return SRV_WAP_PUSH_TL_SAME_ENTRY;
 else
    return SRV_WAP_PUSH_TL_NO_ERROR;
#else 
 return SRV_WAP_PUSH_TL_NO_ERROR;
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_confirm_ip_add_modify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_wap_push_add_modify_ip_address(void)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ip_value[4] = { '\0', };
    U32 ip_sum = 0;
    S8 ip_sep[2] = { '.', '\0' };
    S8 temp_ip_part[SRV_WAP_PUSH_MAX_PART_IP_ADDRESS] = { '\0', };
    S8 ip_addr[MAX_PUSH_IP_ADDR_NUM_LEN * ENCODING_LENGTH];
    U16 rec_index = 0;
    U16 index = 0;
    nvram_push_addr_struct *curr_item = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ip_value[0] = (U8) gui_atoi((UI_string_type) g_push_set_p->IP1);
    ip_value[1] = (U8) gui_atoi((UI_string_type) g_push_set_p->IP2);
    ip_value[2] = (U8) gui_atoi((UI_string_type) g_push_set_p->IP3);
    ip_value[3] = (U8) gui_atoi((UI_string_type) g_push_set_p->IP4);

    ip_sum = ip_value[0] + ip_value[1] + ip_value[2] + ip_value[3];

    if (ip_sum == 0x00)
    {
        //mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_ID_PUSH_INVALID_IP);
        return SRV_WAP_PUSH_TL_INVALID_IP;
    }
    if (g_push_set_p->slected_opr_type == SRV_WAP_PUSH_OPR_EDIT)
    {
        if (g_push_set_p->selected_list_type == SRV_WAP_PUSH_WHITE_LIST)
        {
            srv_wap_push_get_record_and_index(&rec_index, &index, g_push_set_p->selected_wl_entry);
            curr_item = &g_push_set_p->white_list[rec_index].white_list[index];
        }
    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        else
        {
            srv_wap_push_get_record_and_index(&rec_index, &index, g_push_set_p->selected_bl_entry);
            curr_item = &g_push_set_p->black_list[rec_index].black_list[index];
        }
    #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
        mmi_ucs2_to_asc((S8*) ip_addr, g_push_set_p->IP1);
        strcat((S8*) ip_addr, (S8*) ip_sep);

        mmi_ucs2_to_asc(temp_ip_part, g_push_set_p->IP2);
        strcat(ip_addr, temp_ip_part);
        strcat((S8*) ip_addr, (S8*) ip_sep);

        mmi_ucs2_to_asc(temp_ip_part, g_push_set_p->IP3);
        strcat(ip_addr, temp_ip_part);
        strcat((S8*) ip_addr, (S8*) ip_sep);

        mmi_ucs2_to_asc(temp_ip_part, g_push_set_p->IP4);
        strcat((S8*) ip_addr, temp_ip_part);
        if (!strcmp((S8*) ip_addr, (S8*) curr_item->addr))
        {
			//return SRV_WAP_PUSH_TL_SAME_ENTRY;
            return SRV_WAP_PUSH_TL_NO_ERROR;
        }
    }
    /*
    mmi_wap_push_event_based_confirm (
        STR_GLOBAL_SAVE_ASK,
        mmi_wap_push_setting_modify_or_add_ip_addr,
        mmi_wap_push_go_back_two_screen,
		mmi_wap_push_setting_modify_or_add_ip_addr);*/

    if (srv_wap_push_setting_modify_or_add_ip_addr() == SRV_WAP_PUSH_ERROR_DUPLICATE_ENTRY)
		return SRV_WAP_PUSH_TL_SAME_ENTRY;

    return SRV_WAP_PUSH_TL_NO_ERROR;

#else 
	return SRV_WAP_PUSH_TL_NO_ERROR;
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_prepare_trustlist_modify_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_wap_push_prepare_trustlist_modify_data(WCHAR **sender_addr,WCHAR **SMSC_addr,WCHAR **IP_addr, U16 selected_index)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 rec_index = 0;
    U16 index = 0;
    nvram_push_addr_struct *curr_item = NULL;
    S8 ascii_sender[MAX_PUSH_PHN_NUM_LEN] = { '\0', };
    S8 ascii_smsc[MAX_PUSH_PHN_NUM_LEN] = { '\0', };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	*sender_addr = (WCHAR *)g_push_set_p->sender_address;
	*SMSC_addr = (WCHAR *)g_push_set_p->smsc_address;
	*IP_addr = (WCHAR *)g_push_set_p->ip_addr;


    g_push_set_p->slected_opr_type = SRV_WAP_PUSH_OPR_EDIT;
    if (g_push_set_p->selected_list_type == SRV_WAP_PUSH_WHITE_LIST)
    {
		g_push_set_p->selected_wl_entry = selected_index;
        srv_wap_push_get_record_and_index(&rec_index, &index, g_push_set_p->selected_wl_entry);
        curr_item = &g_push_set_p->white_list[rec_index].white_list[index];
    }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    else
    {
 		g_push_set_p->selected_bl_entry = selected_index;
       srv_wap_push_get_record_and_index(&rec_index, &index, g_push_set_p->selected_bl_entry);
        curr_item = &g_push_set_p->black_list[rec_index].black_list[index];
    }
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    if (curr_item->addr_type == SRV_WAP_PUSH_SENDER_ADDR_TYPE_PHONE_NUMBER)
    {
        srv_wap_push_parse_ph_num(ascii_sender, ascii_smsc, (S8*) curr_item->addr);
        mmi_asc_to_ucs2(g_push_set_p->smsc_address, ascii_smsc);
        mmi_asc_to_ucs2(g_push_set_p->sender_address, ascii_sender);
		return SRV_WAP_PUSH_SENDER_ADDR_TYPE_PHONE_NUMBER;
    }
    else
    {
        //strcpy(g_push_set_p->ip_addr, (S8*) curr_item->addr);
		mmi_asc_to_ucs2(g_push_set_p->ip_addr, (S8*) curr_item->addr);
		return SRV_WAP_PUSH_SENDER_ADDR_TYPE_IP_ADDRESS;
    }
#else 

	return SRV_WAP_PUSH_SENDER_ADDR_TYPE_NONE;
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
}

/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_get_max_white_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_wap_push_get_max_white_list(void)
{
	#ifdef __MMI_WAP_PUSH_WHITE_LIST__

	return NVRAM_PUSH_MAX_NUM_WHITE_LIST;

	#else 

	return 0;
	#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_get_max_white_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_wap_push_get_max_black_list(void)
{
	#ifdef __MMI_WAP_PUSH_BLACK_LIST__

	return NVRAM_PUSH_MAX_NUM_BLACK_LIST;

	#else
	return 0;

	#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
}

#endif /* WAP_SUPPORT */ 
