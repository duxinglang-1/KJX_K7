
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
 * PushProv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This source file contains code for OTA provisioning of Trustlist data.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//#include "MMI_include.h"
    #include "MMI_features.h"
    #include "MMIDataType.h"
    #include "mmi_frm_mem_gprot.h"
    #include "kal_public_api.h"
    #include "kal_general_types.h"

#ifdef __WAP_PUSH_SUPPORT__

#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__

//#include "DataAccountDef.h"
//#include "DataAccountGprot.h"


//#include "WAPPushUIProts.h"
#include "mmi_inet_app_trc.h"
#include "pmg_struct.h"

#include "UCMGProt.h"
//#include "UcmSrvGprot.h"
    #include "DebugInitDef_Int.h"
#include "WAPPushSrvTypes.h"
    #include "kal_trace.h"
    #include "mmi_inet_app_trc.h"
    #include "CcaSrvGprot.h"
    #include "mmi_frm_queue_gprot.h"
    #include "app_ltlcom.h"
    #include "stack_msgs.h"
    #include "stack_config.h"
    #include "GlobalResDef.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "common_nvram_editor_data_item.h"
    #include "string.h"
    #include "mmi_frm_events_gprot.h"
    #include "Unicodexdcl.h"
    #include "CustDataRes.h"
    #include "stdio.h"
    #include "custom_phb_config.h"
#include "WAPPushSrvProts.h"
    #include "wgui_categories_text_viewer.h"
    #include "wgui_categories_util.h"
    #include "GlobalMenuItems.h"
    #include "GlobalConstants.h"
    #include "mmi_inet_app_trc.h"

/* Static API */
#ifndef __COSMOS_MMI_PACKAGE__
extern void mmi_wap_push_ota_ui_entry(void);
extern void mmi_wap_push_ota_trustlist_prov_ui_done(U16 trustlist_count);
#else
static mmi_id g_cui_id;
#endif


static mmi_cca_app_configure_ind_struct *g_srv_wap_push_ota_cca_doc_hdl;
srv_wap_push_ota_context g_srv_wap_push_ota_cntxt;


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_mem_allocate
 * DESCRIPTION
 *  Allocates requested memory from control buffer.
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_wap_push_ota_mem_allocate(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *result = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = (void*)OslMalloc(size);

    if (NULL == result)
    {
        ASSERT(result);
        return result;
    }

    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_OTA_MEM_ALLOC, size, (U32) result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_mem_free
 * DESCRIPTION
 *  Releases memory pointed by ptr.
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_ota_mem_free(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == ptr)
    {
        ASSERT(ptr);
        return;
    }

    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_OTA_MEM_FREE, (U32) ptr);
    OslMfree(ptr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_mem_free_trustlist
 * DESCRIPTION
 *  Frees memory of trustlist created.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_ota_mem_free_trustlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_wap_push_ota_cntxt.crnt_trustlist_index = 0;

    while ((index < SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT) && (g_srv_wap_push_ota_cntxt.trustlist[index] != NULL))
    {
        srv_wap_push_ota_mem_free(g_srv_wap_push_ota_cntxt.trustlist[index]);
        g_srv_wap_push_ota_cntxt.trustlist[index] = NULL;
        index++;
    }
    g_srv_wap_push_ota_cntxt.total_trustlist_count = 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_send_cca_response
 * DESCRIPTION
 *  This API sends the status of provisioning to CCA.
 * PARAMETERS
 *  status      [IN]        
 *  **cca_doc(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_ota_send_cca_response(cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_configure_rsp_struct *local_data;
   // MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_wap_push_ota_cca_doc_hdl != NULL)
    {
        /*
        local_data = (mmi_cca_app_configure_rsp_struct*) OslConstructDataPtr(sizeof(mmi_cca_app_configure_rsp_struct));
        */

        local_data=OslAllocDataPtr(mmi_cca_app_configure_rsp_struct);
        local_data->config_id = (g_srv_wap_push_ota_cca_doc_hdl)->config_id;
        local_data->hConfig = (g_srv_wap_push_ota_cca_doc_hdl)->hConfig;
        local_data->status = status;

    /*
        Message.oslMsgId = MSG_ID_MMI_CCA_APP_CONFIGURE_RSP;
        Message.oslDataPtr = (void*)local_data;
        Message.oslPeerBuffPtr = NULL;
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_MMI;
        OslMsgSendExtQueue(&Message);
     */
        mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_CCA_APP_CONFIGURE_RSP, (oslParaType *)local_data,NULL);
        srv_wap_push_ota_mem_free(g_srv_wap_push_ota_cca_doc_hdl);
        g_srv_wap_push_ota_cca_doc_hdl = NULL;
        g_srv_wap_push_ota_cntxt.cca_status_sent = MMI_TRUE;
    }
}




/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_trustlist_prov_ui_done
 * DESCRIPTION
 *  Handles Done for provisioning.
 * PARAMETERS
 *  screen_exists       [IN]        
 * RETURNS
 *  PU8(?)
 *****************************************************************************/
void srv_wap_push_ota_trustlist_prov_ui_done(MMI_BOOL screen_exists)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 next_scr_id = 0;
    U16 prev_scr_id = 0;


    mmi_event_struct evt;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_OTA_UI_DONE_ENTER, g_srv_wap_push_ota_cntxt.total_trustlist_count);

    /* This check will ensure no response is sent after END key is pressed. */
    if ((MMI_FALSE == g_srv_wap_push_ota_cntxt.cca_status_sent) && (g_srv_wap_push_ota_cntxt.total_trustlist_count > 0))        /* This condition will ensure if count = 0 then this is not reached again. */
    {
        g_srv_wap_push_ota_cntxt.total_trustlist_count--;
        g_srv_wap_push_ota_cntxt.crnt_trustlist_index++;

        if (0 == g_srv_wap_push_ota_cntxt.total_trustlist_count)
        {
            g_srv_wap_push_ota_cntxt.cca_status_sent = MMI_TRUE;
            srv_wap_push_ota_mem_free_trustlist();
            srv_wap_push_ota_send_cca_response(g_srv_wap_push_ota_cntxt.installed_result);
        }


		
			MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_PUSH_PROV_CUI_REDISPLAY);
			mmi_frm_cb_emit_event((mmi_event_struct*)&evt);

        

    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_skip_whitelist_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_ota_skip_whitelist_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CCA_STATUS_OK != g_srv_wap_push_ota_cntxt.installed_result)
    {
        g_srv_wap_push_ota_cntxt.installed_result = CCA_STATUS_SETTING_SKIPPED;
    }
    srv_wap_push_ota_trustlist_prov_ui_done(MMI_TRUE);
}





/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_install_trustlist
 * DESCRIPTION
 *  This API installs OTA trustlist.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_ota_install_trustlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp_address[SRV_WAP_PUSH_OTA_MAX_PXADDR_LEN * 2 + 4] = {0, };
    U16 temp_addr_type = SRV_WAP_PUSH_SENDER_ADDR_TYPE_IP_ADDRESS;
    srv_wap_push_add_list_error_enum add_result;
    S8 separator[3] = {0, };

    S8 *address = (S8*)g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.crnt_trustlist_index]->addr;
    U16 length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    separator[0] = WAP_PMG_ADDR_PHONE_SEP;
    separator[1] = 0;
    length = strlen (address);
    if (length > MMI_PHB_NUMBER_LENGTH)
    {
        if (*(address + 0) == '+')
        {
            length = MMI_PHB_NUMBER_LENGTH + 1;
        }
        else
        {
            length = MMI_PHB_NUMBER_LENGTH;
        }
    }

    switch (g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.crnt_trustlist_index]->addr_type)
    {
        case SRV_WAP_PUSH_OTA_TRUSTLIST_TYPE_IP:
            temp_addr_type = SRV_WAP_PUSH_SENDER_ADDR_TYPE_IP_ADDRESS;
            strcpy(
                (S8*) temp_address,
                (S8*) address);
            break;

        case SRV_WAP_PUSH_OTA_TRUSTLIST_TYPE_SENDER:
            temp_addr_type = SRV_WAP_PUSH_SENDER_ADDR_TYPE_PHONE_NUMBER;
            strncpy(
                (S8*) temp_address,
                (S8*) address,
                length);
            strcat((S8*) temp_address, (S8*) separator);
            strcat((S8*) temp_address, (S8*) separator);
            break;

        case SRV_WAP_PUSH_OTA_TRUSTLIST_TYPE_SMSC:
            temp_addr_type = SRV_WAP_PUSH_SENDER_ADDR_TYPE_PHONE_NUMBER;
            strcpy((S8*) temp_address, (S8*) separator);
            strncat(
                (S8*) temp_address,
                (S8*) address,
                length);
            strcat((S8*) temp_address, (S8*) separator);
            break;

        default:
            ASSERT(0);
    }

    add_result = srv_wap_push_add_wl_ota_addr(temp_addr_type, (S8*) temp_address);

    if (SRV_WAP_PUSH_ERROR_SUCCESS == add_result)
    {
        g_srv_wap_push_ota_cntxt.installed_result = CCA_STATUS_OK;
        srv_wap_push_ota_trustlist_prov_ui_done(MMI_FALSE);
    }

    /* callback will be called, to end work */
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_add_trustlist_result_callback
 * DESCRIPTION
 *  This API is callback for result of add trustlist.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_ota_add_trustlist_result_callback(srv_wap_push_add_list_error_enum result) /*Rename*/
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_WAP_PUSH_ERROR_SUCCESS == result)
    {
        g_srv_wap_push_ota_cntxt.installed_result = CCA_STATUS_OK;
        srv_wap_push_ota_trustlist_prov_ui_done(MMI_FALSE);
    }
   
}




/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_mem_allocate_trustlist_entry
 * DESCRIPTION
 *  This API allocates memory for trustlist entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_ota_mem_allocate_trustlist_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        SRV_INET_TRC_G4_PUSH,
        TRC_MMI_BRW_PUSH_OTA_ALLOCATE_TRUSTLIST,
        g_srv_wap_push_ota_cntxt.total_trustlist_count);

    if ((g_srv_wap_push_ota_cntxt.total_trustlist_count == -1) ||
        (g_srv_wap_push_ota_cntxt.total_trustlist_count >= SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT))
    {
        ASSERT(g_srv_wap_push_ota_cntxt.total_trustlist_count != -1);
        ASSERT(g_srv_wap_push_ota_cntxt.total_trustlist_count < SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT);
        return;
    }

    if (!(g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.total_trustlist_count]))
    {
        g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.total_trustlist_count] =
            (nvram_push_addr_struct*) srv_wap_push_ota_mem_allocate(sizeof(nvram_push_addr_struct));

        memset(
            g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.total_trustlist_count]->addr,
            0,
            sizeof(g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.total_trustlist_count]->addr));
        g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.total_trustlist_count]->addr_type =
            SRV_WAP_PUSH_OTA_TRUSTLIST_TYPE_END;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_is_current_value_duplicate
 * DESCRIPTION
 *  This API allocates memory for trustlist entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_wap_push_ota_is_current_value_duplicate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S8 temp_address[SRV_WAP_PUSH_OTA_MAX_PXADDR_LEN * 2 + 2] = {0, };
    U16 temp_addr_type = SRV_WAP_PUSH_SENDER_ADDR_TYPE_IP_ADDRESS;
    S8 separator[3] = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    separator[0] = WAP_PMG_ADDR_PHONE_SEP;
    separator[1] = 0;

    /* Check for value in the recieved list. */
    for (i = 0; ((i < g_srv_wap_push_ota_cntxt.total_trustlist_count) && (g_srv_wap_push_ota_cntxt.trustlist[i])); i++)
    {
        if (g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.total_trustlist_count]->addr_type !=
            g_srv_wap_push_ota_cntxt.trustlist[i]->addr_type)
        {
            continue;
        }

        if (strcmp(
                (S8*) g_srv_wap_push_ota_cntxt.trustlist[i]->addr,
                (S8*) g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.total_trustlist_count]->addr) ==
            0)
        {
            /* Duplicate value */
            return MMI_TRUE;
        }
    }

    /* Check for duplicate in NVRAM */
    switch (g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.total_trustlist_count]->addr_type)
    {
        case SRV_WAP_PUSH_OTA_TRUSTLIST_TYPE_IP:
            temp_addr_type = SRV_WAP_PUSH_SENDER_ADDR_TYPE_IP_ADDRESS;
            strcpy(
                (S8*) temp_address,
                (S8*) g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.total_trustlist_count]->addr);
            break;

        case SRV_WAP_PUSH_OTA_TRUSTLIST_TYPE_SENDER:
            temp_addr_type = SRV_WAP_PUSH_SENDER_ADDR_TYPE_PHONE_NUMBER;
            strcpy(
                (S8*) temp_address,
                (S8*) g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.total_trustlist_count]->addr);
            strcat((S8*) temp_address, (S8*) separator);
            strcat((S8*) temp_address, (S8*) separator);
            break;

        case SRV_WAP_PUSH_OTA_TRUSTLIST_TYPE_SMSC:
            temp_addr_type = SRV_WAP_PUSH_SENDER_ADDR_TYPE_PHONE_NUMBER;
            strcpy((S8*) temp_address, (S8*) separator);
            strcat(
                (S8*) temp_address,
                (S8*) g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.total_trustlist_count]->addr);
            strcat((S8*) temp_address, (S8*) separator);
            break;
    }

    return srv_wap_push_check_duplicate_entry(SRV_WAP_PUSH_WHITE_LIST, temp_addr_type, (S8*) temp_address);

}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_create_profile
 * DESCRIPTION
 *  This API creates the profile list.
 * PARAMETERS
 *  app_node            [IN]        
 *  data_type           [IN]        
 *  proxy_node(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_wap_push_ota_create_profile(srv_wap_push_application_tag_struct *app_node, void *data_node, U8 data_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_ota_proxy_tag_struct *proxy_content;
    srv_wap_push_ota_napdef_tag_struct *napdef_content;
    U8 temp_address[SRV_WAP_PUSH_OTA_MAX_PXADDR_LEN * 2 + 2] = {0, };
    U8 temp_ip[4] = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (data_type)
    {
        case SRV_WAP_PUSH_OTA_DATA_SRC_PROXY:   /* Proxy type data */
        {
            proxy_content = (srv_wap_push_ota_proxy_tag_struct*) data_node;
            if (CCA_NS_VAL_E164 != proxy_content->px_addrtype)
            {
                /* IPV4 data */
                strcpy((S8*) temp_address, (S8*) (proxy_content->px_addr));
                if (srv_wap_push_convert_proxy_ipstring_to_array((U8*) (temp_address), (U8*) temp_ip) !=
                    SRV_WAP_PUSH_ERR)
                {
                    /* Valid value to be added in list */
                    srv_wap_push_ota_mem_allocate_trustlist_entry();

                    strcpy(
                        (S8*) g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.total_trustlist_count]->addr,
                        (S8*) (proxy_content->px_addr));
                    g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.total_trustlist_count]->addr_type =
                        SRV_WAP_PUSH_OTA_TRUSTLIST_TYPE_IP;
                }
                else
                {
                    /* Invalid value */
                    return MMI_FALSE;
                }
            }
            else
            {
                /* Number type data. */
                mmi_asc_to_ucs2((S8*) temp_address, (S8*) (proxy_content->px_addr));
                if (mmi_ucs2strlen((S8*) temp_address) && srv_wap_push_check_valid_number((S8*) (temp_address)))
                {
                    /* Valid value to be added in list */
                    srv_wap_push_ota_mem_allocate_trustlist_entry();

                    strcpy(
                        (S8*) g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.total_trustlist_count]->addr,
                        (S8*) (proxy_content->px_addr));
                    g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.total_trustlist_count]->addr_type =
                        SRV_WAP_PUSH_OTA_TRUSTLIST_TYPE_SENDER;
                }
                else
                {
                    /* Invalid value */
                    return MMI_FALSE;
                }
            }
        }
            break;

        case SRV_WAP_PUSH_OTA_DATA_SRC_NAPDEF:  /* NAPDEF type data */
        {
            napdef_content = (srv_wap_push_ota_napdef_tag_struct*) data_node;
            if (CCA_NS_VAL_IPV4 != napdef_content->nap_addrtype)
            {
                /* Number type data. */
                mmi_asc_to_ucs2((S8*) temp_address, (S8*) (napdef_content->nap_addr));
                if (mmi_ucs2strlen((S8*) temp_address) && srv_wap_push_check_valid_number((S8*) (temp_address)))
                {
                    /* Valid value to be added in list */
                    srv_wap_push_ota_mem_allocate_trustlist_entry();

                    strcpy(
                        (S8*) g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.total_trustlist_count]->addr,
                        (S8*) (napdef_content->nap_addr));
                    g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.total_trustlist_count]->addr_type =
                        SRV_WAP_PUSH_OTA_TRUSTLIST_TYPE_SMSC;
                }
                else
                {
                    /* Invalid value */
                    return MMI_FALSE;
                }
            }
            else
            {
                /* IPV4 data */
                strcpy((S8*) temp_address, (S8*) (napdef_content->nap_addr));
                if (srv_wap_push_convert_proxy_ipstring_to_array((U8*) (temp_address), (U8*) temp_ip) !=
                    SRV_WAP_PUSH_ERR)
                {
                    /* Valid value to be added in list */
                    srv_wap_push_ota_mem_allocate_trustlist_entry();

                    strcpy(
                        (S8*) g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.total_trustlist_count]->addr,
                        (S8*) (napdef_content->nap_addr));
                    g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.total_trustlist_count]->addr_type =
                        SRV_WAP_PUSH_OTA_TRUSTLIST_TYPE_IP;

                }
                else
                {
                    /* Invalid value */
                    return MMI_FALSE;
                }
            }
        }
            break;
    }

    /* duplicate check. */
    if (srv_wap_push_ota_is_current_value_duplicate())
    {
        /* Duplicate value discard and free memory. */
        srv_wap_push_ota_mem_free(g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.total_trustlist_count]);
        g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.total_trustlist_count] = NULL;

        if (CCA_STATUS_OK != g_srv_wap_push_ota_cntxt.installed_result)
        {
            g_srv_wap_push_ota_cntxt.installed_result = CCA_STATUS_SETTING_SKIPPED;
        }
        return MMI_FALSE;
    }
    else
    {
        /* Valid value do nothing. */
        g_srv_wap_push_ota_cntxt.total_trustlist_count++;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_create_trustlist
 * DESCRIPTION
 *  This API creates trustlists based on the proxy, napdef and application lists.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_ota_create_trustlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 napid_list_index;
    S32 app_to_napid_index = 0;
    S16 proxy_index, app_index, app_to_proxy_index = 0;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (app_index = 0; (app_index < SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT) &&
         (g_srv_wap_push_ota_cntxt.app_list[app_index] != NULL) &&
         (g_srv_wap_push_ota_cntxt.total_trustlist_count < SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT);)
    {
        proxy_index = 0;
        napid_list_index = 0;
        result = MMI_FALSE;

        while ((proxy_index < SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT) &&
               (g_srv_wap_push_ota_cntxt.proxy_list[proxy_index] != NULL) &&
               (strlen((S8*) g_srv_wap_push_ota_cntxt.app_list[app_index]->app_to_proxy[app_to_proxy_index])) &&
               (g_srv_wap_push_ota_cntxt.total_trustlist_count < SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT))
        {
            if ((strcmp(
                    (S8*) g_srv_wap_push_ota_cntxt.app_list[app_index]->app_to_proxy[app_to_proxy_index],
                    (S8*) g_srv_wap_push_ota_cntxt.proxy_list[proxy_index]->px_id) == 0))
            {
                /* Proxy matches. */
                result = srv_wap_push_ota_create_profile(
                            g_srv_wap_push_ota_cntxt.app_list[app_index],
                            (void*)(g_srv_wap_push_ota_cntxt.proxy_list[proxy_index]),
                            SRV_WAP_PUSH_OTA_DATA_SRC_PROXY);
                if (MMI_TRUE == result)
                {
                    /* Break out as to_proxy has been used. */
                    break;
                }
                else
                {
                    /* proxy matched but profile not created for that proxy, hence do not set it as last proxy. */
                    proxy_index++;
                }
            }
            else
            {
                proxy_index++;
            }
        }

        /* Create Trustlist from TO-NAPID */
        while ((napid_list_index < SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT) &&
               (g_srv_wap_push_ota_cntxt.nap_address_list[napid_list_index] != NULL) &&
               (g_srv_wap_push_ota_cntxt.total_trustlist_count < SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT) &&
               (strlen((S8*) g_srv_wap_push_ota_cntxt.app_list[app_index]->app_to_napid[app_to_napid_index])))
        {
            if ((strcmp(
                    (S8*) g_srv_wap_push_ota_cntxt.app_list[app_index]->app_to_napid[app_to_napid_index],
                    (S8*) g_srv_wap_push_ota_cntxt.nap_address_list[napid_list_index]->nap_id) == 0))
            {
                /* NAPID matches. */
                result = srv_wap_push_ota_create_profile(
                            g_srv_wap_push_ota_cntxt.app_list[app_index],
                            (void*)(g_srv_wap_push_ota_cntxt.nap_address_list[napid_list_index]),
                            SRV_WAP_PUSH_OTA_DATA_SRC_NAPDEF);
                if (MMI_TRUE == result)
                {
                    /* Break out as to_napid has been used. */
                    break;
                }
            }
            napid_list_index++;
        }

        /* 
         * Increment to_proxy and traverse proxy again.
         */
        app_to_proxy_index++;
        app_to_napid_index++;

        if ((app_to_proxy_index >= SRV_WAP_PUSH_OTA_MAX_TO_PROXY) ||
            (app_to_napid_index >= SRV_WAP_PUSH_OTA_MAX_TO_NAPID))
        {
            /* 
             * As there are no more to_proxy in the current app, increment app_index
             * and reset to_proxy.
             */
            app_to_proxy_index = 0;
            app_to_napid_index = 0;
            app_index++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_mem_allocate_napdef_node
 * DESCRIPTION
 *  Allocates 1 napdef node, at current napdef index.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S8 srv_wap_push_ota_mem_allocate_napdef_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; ((i < SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT) &&
                 (g_srv_wap_push_ota_cntxt.nap_address_list[i] != NULL)); i++)
    {
        /* Finding 1st available slot to allocate */
    }

    if (i >= SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT)
    {
        return (S8) - 1;
    }

    /* MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_SRV_WAP_PUSH_OTA_ALLOCATE_NAPDEF, i); */

    if (g_srv_wap_push_ota_cntxt.nap_address_list[i] == NULL)
    {
        g_srv_wap_push_ota_cntxt.nap_address_list[i] =
            (srv_wap_push_ota_napdef_tag_struct*)
            srv_wap_push_ota_mem_allocate(sizeof(srv_wap_push_ota_napdef_tag_struct));
    }

    memset(
        g_srv_wap_push_ota_cntxt.nap_address_list[i]->nap_id,
        '\0',
        sizeof(g_srv_wap_push_ota_cntxt.nap_address_list[i]->nap_id));

    memset(
        g_srv_wap_push_ota_cntxt.nap_address_list[i]->nap_addr,
        '\0',
        sizeof(g_srv_wap_push_ota_cntxt.nap_address_list[i]->nap_addr));
    g_srv_wap_push_ota_cntxt.nap_address_list[i]->nap_addrtype = -1;

    return (S8) i;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_is_duplicate_nap_addr
 * DESCRIPTION
 *  Searches the nap list and finds if the nap addr is already present.
 * PARAMETERS
 *  napaddr       [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_wap_push_ota_is_duplicate_nap_addr(S8 *napaddr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; g_srv_wap_push_ota_cntxt.nap_address_list[i]; i++)
    {
        if (strcmp(
                (S8*) napaddr,
                (S8*) g_srv_wap_push_ota_cntxt.nap_address_list[i]->nap_addr) == 0)
        {
            /* Duplicate value */
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_handle_napdef_tag
 * DESCRIPTION
 *  Handles napdef tag from CCA doc.
 * PARAMETERS
 *  iter_datalist       [IN]        
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum srv_wap_push_ota_handle_napdef_tag(cca_iterator_struct *iter_datalist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data = NULL;
    S8 *trace_string = NULL;
    cca_status_enum result = CCA_STATUS_OK;
    srv_wap_push_ota_napdef_tag_struct *napdef_content;
    S8 nap_idx;
    U16 copy_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nap_idx = srv_wap_push_ota_mem_allocate_napdef_node();

    //MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_SRV_WAP_PUSH_OTA_HANDLE_NAPDEF_TAG, nap_idx);

    if ((S8) - 1 != nap_idx)
    {

        napdef_content = g_srv_wap_push_ota_cntxt.nap_address_list[nap_idx];
        mmi_cca_iterator_restart(iter_datalist);
        while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
        {
            MMI_ASSERT(data != NULL);
            switch (data->id)
            {
                case CCA_NS_OMA_NAP_ADDRTYPE:
                    napdef_content->nap_addrtype = data->values.i[0];
                    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_OTA_NAPADDR_TYPE, data->values.i[0]);
                    break;

                case CCA_NS_OMA_NAPID:
                    if (data->values.s[0])
                    {
                        trace_string = (S8*) "[PUSH][OTA] NAP ID = %s";
                        strncpy(
                            (S8*) napdef_content->nap_id,
                            (S8*) data->values.s[0],
                            sizeof(napdef_content->nap_id) - 1);
                    }
                    break;

                case CCA_NS_OMA_NAP_ADDRESS:
                    if (data->values.s[0])
                    {
                        trace_string = (S8*) "[PUSH][OTA] NAP ADDR = %s";

                        if (srv_wap_push_ota_is_duplicate_nap_addr((S8*) data->values.s[0]) == MMI_FALSE)
                        {
                            copy_len = sizeof(napdef_content->nap_addr) - 3;
                            if (*(data->values.s[0] + 0) == '+')
                            {
                                copy_len++;
                            }
                        strncpy(
                            (S8*) napdef_content->nap_addr,
                            (S8*) data->values.s[0],
                            copy_len);
                    }
                        else
                        {
                            /* Duplicate value discard proxy node */
                            srv_wap_push_ota_mem_free(g_srv_wap_push_ota_cntxt.nap_address_list[nap_idx]);
                            g_srv_wap_push_ota_cntxt.nap_address_list[nap_idx] = NULL;
                            goto nap_result;
                        }


                    }
                    break;
            }

            if (NULL != trace_string)
            {
                trace_string = NULL;
            }
        }
    }

nap_result:
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_mem_allocate_proxy_node
 * DESCRIPTION
 *  Allocates 1 proxy node, at current proxy index.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S8 srv_wap_push_ota_mem_allocate_proxy_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; ((i < SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT) && (g_srv_wap_push_ota_cntxt.proxy_list[i] != NULL)); i++)
    {
        /* Finding 1st available slot to allocate */
    }

    if (i >= SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT)
    {
        return (S8) - 1;
    }

    if (g_srv_wap_push_ota_cntxt.proxy_list[i] == NULL)
    {
        g_srv_wap_push_ota_cntxt.proxy_list[i] =
            (srv_wap_push_ota_proxy_tag_struct*)
            srv_wap_push_ota_mem_allocate(sizeof(srv_wap_push_ota_proxy_tag_struct));
    }
    memset(g_srv_wap_push_ota_cntxt.proxy_list[i]->px_id, '\0', sizeof(g_srv_wap_push_ota_cntxt.proxy_list[i]->px_id));

    memset(
        g_srv_wap_push_ota_cntxt.proxy_list[i]->px_addr,
        '\0',
        sizeof(g_srv_wap_push_ota_cntxt.proxy_list[i]->px_addr));
    g_srv_wap_push_ota_cntxt.proxy_list[i]->px_addrtype = -1;

    return (S8) i;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_is_duplicate_proxy_addr
 * DESCRIPTION
 *  Searches the proxy list and finds if the proxy addr is already present.
 * PARAMETERS
 *  pxaddr       [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_wap_push_ota_is_duplicate_proxy_addr(S8 *pxaddr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; g_srv_wap_push_ota_cntxt.proxy_list[i]; i++)
    {
        if (strcmp(
                (S8*) pxaddr,
                (S8*) g_srv_wap_push_ota_cntxt.proxy_list[i]->px_addr) == 0)
        {
            /* Duplicate value */
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_handle_proxy_tag
 * DESCRIPTION
 *  Handles proxy tag from CCA doc.
 * PARAMETERS
 *  iter_datalist       [IN]        
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum srv_wap_push_ota_handle_proxy_tag(cca_iterator_struct *iter_datalist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data = NULL;
    S8 *trace_string = NULL;
    cca_status_enum result = CCA_STATUS_OK;
    srv_wap_push_ota_proxy_tag_struct *proxy_content;
    S8 prx_idx;
    U16 copy_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prx_idx = srv_wap_push_ota_mem_allocate_proxy_node();
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_OTA_HANDLE_PROXY_TAG, prx_idx);

    if ((S8) - 1 != prx_idx)
    {
        proxy_content = g_srv_wap_push_ota_cntxt.proxy_list[prx_idx];
        mmi_cca_iterator_restart(iter_datalist);
        while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
        {
            MMI_ASSERT(data != NULL);
            switch (data->id)
            {
                case CCA_NS_OMA_PXADDRTYPE:
                    proxy_content->px_addrtype = data->values.i[0];
                    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_OTA_PXADDR_TYPE, data->values.i[0]);
                    break;

                case CCA_NS_OMA_PROXY_ID:
                    if (data->values.s[0])
                    {
                        trace_string = (S8*) "[PUSH][OTA] Proxy ID = %s";
                        strncpy(
                            (S8*) proxy_content->px_id,
                            (S8*) data->values.s[0],
                            sizeof(proxy_content->px_id) - 1);
                    }
                    break;

                case CCA_NS_OMA_PXADDR:
                    if (data->values.s[0])
                    {
                        trace_string = (S8*) "[PUSH][OTA] Proxy ADDR = %s";
                        if (srv_wap_push_ota_is_duplicate_proxy_addr((S8*) data->values.s[0]) == MMI_FALSE)
                        {
                            copy_len = sizeof(proxy_content->px_addr) - 3;
                            if (*(data->values.s[0] + 0) == '+')
                            {
                                copy_len++;
                            }
                        strncpy(
                            (S8*) proxy_content->px_addr,
                            (S8*) data->values.s[0],
                            copy_len);
                    }
                        else
                        {
                            /* Duplicate value discard proxy node */
                            srv_wap_push_ota_mem_free(g_srv_wap_push_ota_cntxt.proxy_list[prx_idx]);
                            g_srv_wap_push_ota_cntxt.proxy_list[prx_idx] = NULL;
                            goto prx_result;
                        }
                    }
                    break;
            }

            if (NULL != trace_string)
            {
                trace_string = NULL;
            }
        }
    }

prx_result:
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_mem_allocate_app_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *****************************************************************************/
S8 srv_wap_push_ota_mem_allocate_app_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, app_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (app_idx = 0; ((app_idx < SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT) &&
                       (g_srv_wap_push_ota_cntxt.app_list[app_idx] != NULL)); app_idx++)
    {
        /* Finding 1st available slot to allocate */
    }

    if (app_idx >= SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT)
    {
        return (S8) - 1;
    }

    if (g_srv_wap_push_ota_cntxt.app_list[app_idx] == NULL)
    {
        g_srv_wap_push_ota_cntxt.app_list[app_idx] =
            (srv_wap_push_application_tag_struct*)
            srv_wap_push_ota_mem_allocate(sizeof(srv_wap_push_application_tag_struct));
    }

    for (i = 0; i < SRV_WAP_PUSH_OTA_MAX_TO_PROXY; i++)
    {
        memset(
            g_srv_wap_push_ota_cntxt.app_list[app_idx]->app_to_proxy[i],
            0,
            sizeof(g_srv_wap_push_ota_cntxt.app_list[app_idx]->app_to_proxy[i]));
    }

    for (i = 0; i < SRV_WAP_PUSH_OTA_MAX_TO_NAPID; i++)
    {
        memset(
            g_srv_wap_push_ota_cntxt.app_list[app_idx]->app_to_napid[i],
            0,
            sizeof(g_srv_wap_push_ota_cntxt.app_list[app_idx]->app_to_napid[i]));
    }

    return (S8) app_idx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_handle_application_tag
 * DESCRIPTION
 *  Handles application tag from CCA doc.
 * PARAMETERS
 *  iter_datalist       [IN]        
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum srv_wap_push_ota_handle_application_tag(cca_iterator_struct *iter_datalist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data = NULL;
    cca_status_enum result = CCA_STATUS_OK;
    S32 count = 0, i = 0;
    srv_wap_push_application_tag_struct *application_content;
    S8 *trace_string = NULL;
    S8 app_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app_idx = srv_wap_push_ota_mem_allocate_app_node();

    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_OTA_HANDLE_APPLICATION_TAG, app_idx);

    if ((S8) - 1 != app_idx)
    {
        application_content = g_srv_wap_push_ota_cntxt.app_list[app_idx];

        while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
        {
			MMI_ASSERT(data != NULL);
            switch (data->id)
            {
                case CCA_NS_OMA_TO_PROXY:
                    count = (data->size < SRV_WAP_PUSH_OTA_MAX_TO_PROXY) ? data->size : SRV_WAP_PUSH_OTA_MAX_TO_PROXY;
                    trace_string = (S8*) "[PUSH][OTA] APP To Proxy = %s";
                    for (i = 0; i < count; i++)
                    {
                        strncpy(
                            (S8*) application_content->app_to_proxy[i],
                            (S8*) data->values.s[i],
                            (SRV_WAP_PUSH_OTA_PROXY_ID_LEN - 1));
                    }
                    break;

                case CCA_NS_OMA_TO_NAPID:
                    count = (data->size < SRV_WAP_PUSH_OTA_MAX_TO_NAPID) ? data->size : SRV_WAP_PUSH_OTA_MAX_TO_NAPID;
                    trace_string = (S8*) "[PUSH][OTA] APP To NAPID = %s";
                    for (i = 0; i < count; i++)
                    {
                        strncpy(
                            (S8*) application_content->app_to_napid[i],
                            (S8*) data->values.s[i],
                            (SRV_WAP_PUSH_OTA_MAX_NAPID_LEN - 1));
                    }
                    break;
            }
            if ((NULL != trace_string) && (data->values.s[0]))
            {
                trace_string = NULL;
            }
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_process_cca_nodes_callback
 * DESCRIPTION
 *  Callback function called by CCA as per the node like (proxy, port, apllication & bookmark)
 *  being triggered. Used only for browser.
 * PARAMETERS
 *  hConfig             [IN]        
 *  hNode               [IN]        
 *  node_symbol         [IN]        
 *  iter_datalist       [IN]        
 *  user_data           [IN]        
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum srv_wap_push_process_cca_nodes_callback(
                    S32 hConfig,
                    S32 hNode,
                    U16 node_symbol,
                    cca_iterator_struct *iter_datalist,
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum result = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (node_symbol)
    {
        case SRV_WAP_PUSH_CCA_NODE_PROXY:
            if (mmi_cca_oma_is_virtual_proxy(hNode) == 0)
            {
                result = srv_wap_push_ota_handle_proxy_tag(iter_datalist);
            }
            break;

        case SRV_WAP_PUSH_CCA_NODE_APP:
            result = srv_wap_push_ota_handle_application_tag(iter_datalist);
            break;

        case SRV_WAP_PUSH_CCA_NODE_NAPDEF:
            result = srv_wap_push_ota_handle_napdef_tag(iter_datalist);
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_cca_doc_processor
 * DESCRIPTION
 *  Processes CCA doc.
 * PARAMETERS
 *  hConfig     [IN]        
 *  app_id(?)
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
cca_status_enum srv_wap_push_ota_cca_doc_processor(S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum result = CCA_STATUS_INVALID_SETTING;
    const U16 cca_mapping_push[] = 
    {
        CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, SRV_WAP_PUSH_CCA_NODE_PROXY, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, SRV_WAP_PUSH_CCA_NODE_APP, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_NAPDEF, SRV_WAP_PUSH_CCA_NODE_NAPDEF, 0xFFFF,
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_cca_doc_process(
                hConfig,
                cca_mapping_push,
                sizeof(cca_mapping_push) / sizeof(U16),
                0,
                srv_wap_push_process_cca_nodes_callback,
                0);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_free_proxy_app_nodes
 * DESCRIPTION
 *  This API frees all the memory used to create a profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_ota_free_proxy_app_nodes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_OTA_RELEASE_APP_PRX_NAP_NODES);

    while (i < SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT && g_srv_wap_push_ota_cntxt.proxy_list[i] != NULL)
    {
        srv_wap_push_ota_mem_free(g_srv_wap_push_ota_cntxt.proxy_list[i]);
        g_srv_wap_push_ota_cntxt.proxy_list[i] = NULL;
        i++;
    }
    i = 0;
    while (i < SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT && g_srv_wap_push_ota_cntxt.app_list[i] != NULL)
    {
        srv_wap_push_ota_mem_free(g_srv_wap_push_ota_cntxt.app_list[i]);
        g_srv_wap_push_ota_cntxt.app_list[i] = NULL;
        i++;
    }
    i = 0;
    while (i < SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT && g_srv_wap_push_ota_cntxt.nap_address_list[i] != NULL)
    {
        srv_wap_push_ota_mem_free(g_srv_wap_push_ota_cntxt.nap_address_list[i]);
        g_srv_wap_push_ota_cntxt.nap_address_list[i] = NULL;
        i++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_ota_app_configure_ind_hdlr
 * DESCRIPTION
 *  Entry point for New Doc indication.
 * PARAMETERS
 *  newconfigdoc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_push_ota_app_configure(mmi_cca_app_configure_ind_struct *newconfigdoc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum result = CCA_STATUS_INVALID_SETTING;


    mmi_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_srv_wap_push_ota_cca_doc_hdl)
    {
        g_srv_wap_push_ota_cca_doc_hdl =
            (mmi_cca_app_configure_ind_struct*)
            srv_wap_push_ota_mem_allocate(sizeof(mmi_cca_app_configure_ind_struct));
    }
    if (g_srv_wap_push_ota_cca_doc_hdl == NULL)
    {
        ASSERT(g_srv_wap_push_ota_cca_doc_hdl);
        return;
    }
    g_srv_wap_push_ota_cca_doc_hdl->config_id = newconfigdoc->config_id;
    g_srv_wap_push_ota_cca_doc_hdl->hConfig = newconfigdoc->hConfig;
    g_srv_wap_push_ota_cca_doc_hdl->prov_flag = newconfigdoc->prov_flag;
    g_srv_wap_push_ota_cca_doc_hdl->prov_type = newconfigdoc->prov_type;
    g_srv_wap_push_ota_cntxt.cca_status_sent = MMI_FALSE;
    g_srv_wap_push_ota_cntxt.scr_deleted = MMI_FALSE;

    if (CCA_CONFIG_PUSH != g_srv_wap_push_ota_cca_doc_hdl->config_id)
    {
        srv_wap_push_ota_send_cca_response(CCA_STATUS_SETTING_SKIPPED);
        return;
    }

    g_srv_wap_push_ota_cntxt.crnt_trustlist_index = 0;
    g_srv_wap_push_ota_cntxt.total_trustlist_count = 0;
    g_srv_wap_push_ota_cntxt.installed_result = CCA_STATUS_INVALID_SETTING;

    result = srv_wap_push_ota_cca_doc_processor(g_srv_wap_push_ota_cca_doc_hdl->hConfig);

    if (CCA_STATUS_OK == result)
    {
        srv_wap_push_ota_create_trustlist();
        if (g_srv_wap_push_ota_cntxt.total_trustlist_count > 0)
        {
						
				MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_PUSH_PROV_CUI_CREATE);
				mmi_frm_cb_emit_event((mmi_event_struct*)&evt);

        }
        else
        {
            srv_wap_push_ota_send_cca_response(g_srv_wap_push_ota_cntxt.installed_result);
        }
    }
    else
    {
        srv_wap_push_ota_send_cca_response(CCA_STATUS_INVALID_SETTING);
    }
    srv_wap_push_ota_free_proxy_app_nodes();
}
#endif /* __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__ */ 
#endif /* WAP_SUPPORT */ 

