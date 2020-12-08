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
 * ProvisioningSrvMain.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is main file for Prov Service.
 *
 * Author:
 * -------
 * 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//#include "MMI_include.h"
#include "MMIDataType.h"
#include "MMI_features.h"
#include "mmi_frm_events_gprot.h"
#include "stack_msgs.h"
#include "kal_general_types.h"
#include "DLAgentSrvDef.h" /* DL Agent SIM ID ENUM */
#include "DLAgentSrvGProt.h"
#ifndef _PROVISIONINGSRVMAIN_C
#define _PROVISIONINGSRVMAIN_C

#include "phs_struct.h"   /* please help to double check Q05A and Q03C both support this file */
#include "ProvisioningSrvMain.h"

#ifdef __MMI_PROVISIONING_SERVICE_SUPPORT__

#ifdef __MMI_PROV_SERVICE_CCA_SUPPORT_ON__
#include "ProvisioningSrvProt.h"
#include "CcaSrvGprot.h"
#include "CcaSrvProt.h"
//#include "fs_func.h"    /* File system API */
//#include "rtfiles.h"    /* FS_open return value */
#include "fs_gprot.h"    /* File system API */
#include "SimCtrlSrvGprot.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_inet_app_trc.h"
#include "MMI_inet_app_trc.h"
//#include "fs_type.h"
#include "kal_public_api.h"
#include "Unicodexdcl.h"
#include "stack_config.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

#ifdef __PROV_OMA_PIN_VALIDATION_SUPPORT__

#include "che_api.h"

static SRV_PROV_RETCODE srv_prov_parse_header(void);
static SRV_PROV_RETCODE srv_prov_validate_data(S8 *s_pin, U16 i_pin_len);

#endif /* __PROV_OMA_PIN_VALIDATION_SUPPORT__ */ 

static void srv_prov_add_data_to_queue(S8 *prov_buffer_p, U32 prov_length, S8 *header_p, U32 i_sim_id);

static srv_prov_queue_data_struct *g_srv_prov_data_queue_p[SRV_PROV_MAX_NBR_DOCUMENTS];
static S8 g_srv_prov_data_queue_current_item = 0;
static S8 g_srv_prov_data_queue_last_item = 0;
static S8 g_srv_prov_data_queue_size = 0;
srv_prov_context_struct g_srv_prov_ctxt;


/*****************************************************************************
 * FUNCTION
 *  srv_prov_serv_init
 * DESCRIPTION
 *  Init provisioning module.
 * PARAMETERS
 *  mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_prov_serv_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Protocol Event handlers */

    /* Initialize ADM */
    srv_prov_init_adm();

#ifdef __MMI_PROV_MESSAGE_SUPPORT__

    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_SRC_INSTALL_PROV_MSG_REQ,
        (PsIntFuncPtr) srv_prov_cca_source_install_prov_msg_req_hdlr,
        MMI_TRUE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_PROVBOX_SAVE_MSG_CNF,
        (PsIntFuncPtr) srv_prov_provbox_save_msg_cnf_hdlr,
        MMI_TRUE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_PROVBOX_GET_MSG_DATA_CNF,
        (PsIntFuncPtr) srv_prov_provbox_get_msg_data_cnf_hdlr,
        MMI_TRUE);
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */
    
    return MMI_RET_OK;
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_process_new_provisioning_message
 * DESCRIPTION
 *  processes new provisioning message.
 * PARAMETERS
 *  filename                    [IN]        
 *  action_type                 [IN]        
 *  mime_type_str_string        [IN]        
 *  action_type                 [IN]        
 *  wap_addr                    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
srv_prov_retcode_enum srv_prov_process_new_provisioning_message(PU16 filename, S32 action_type, PS8 mime_type_str_string, const S8* wap_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    U32 i_no_of_items;
    U32 prov_length = 0;
    S8 *prov_buffer_p = NULL;
    S8 *ls_header_p = NULL;
    S8 temp_filename[100];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(temp_filename, 0, sizeof(temp_filename));
    mmi_ucs2_n_to_asc(temp_filename, (S8*) filename, 99);
    MMI_PRINT(SRV_PROV_TRACE_MOD_INET_APP, 
              SRV_PROV_TRACE_GRP9, 
              "[PROVS] Processing new provisioning message, filename = %s, sim_id = %d, ", 
              (S8*) temp_filename,
              action_type);

    MMI_PRINT(SRV_PROV_TRACE_MOD_INET_APP, 
              SRV_PROV_TRACE_GRP9, 
              "[PROVS] Processing new provisioning message, MIME = %s", 
              mime_type_str_string);

    file_handle = FS_Open((const WCHAR*)filename, FS_READ_ONLY);

    if (file_handle < FS_NO_ERROR)
    {
        MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_PROCESS_PROV_MSG_FILE_OPEN_ERROR);
        return SRV_PROV_CORRUPT_SETTING;
    }

    FS_GetFileSize(file_handle, &prov_length);

    if (g_srv_prov_data_queue_size != SRV_PROV_MAX_NBR_DOCUMENTS)
    {
        if (prov_length > SRV_PROV_MAX_FILE_SIZE_SUPPORT)
        {
            MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_RECEIVE_DA_FILE_ERR_MAX_SIZE_EXCEED, prov_length);
            prov_length = 0;
        }
        else
        {
            prov_buffer_p = srv_prov_mem_alloc((prov_length + 1));
            ASSERT(prov_buffer_p);
            ASSERT(FS_Read(file_handle, (void*)prov_buffer_p, prov_length, &i_no_of_items) == FS_NO_ERROR);

            /* Copy header to new pointer as it needs to be stored in queue. */
            ls_header_p = (S8*) srv_prov_mem_alloc(strlen(mime_type_str_string) + 1);
            ASSERT(ls_header_p);
            sprintf((S8*) ls_header_p, (S8*) mime_type_str_string);
        }

        srv_prov_add_data_to_queue(prov_buffer_p, prov_length, ls_header_p, action_type);

#ifndef __MMI_PROV_MESSAGE_SUPPORT__
        srv_prov_cca_new_setting_ind_req(g_srv_prov_data_queue_p[g_srv_prov_data_queue_last_item - 1]->i_sim_id,
                                         &(g_srv_prov_data_queue_p[g_srv_prov_data_queue_last_item - 1]->trans_id)); /* USIM */

#else  /* __MMI_PROV_MESSAGE_SUPPORT__ */
        /* do not send the new_setting_ind to CCA */
        /* Send data of queue entry just saved. */
        /* Contains actual CCA SIM ID */
        g_srv_prov_data_queue_p[g_srv_prov_data_queue_last_item - 1]->i_sim_id = action_type;
        srv_prov_start_setting_parser();

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */
    }
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    else
    {
        ASSERT(FS_Close(file_handle) == FS_NO_ERROR);
        return SRV_PROV_MEM_FULL;
    }
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */

    ASSERT(FS_Close(file_handle) == FS_NO_ERROR);
#ifndef __MMI_PROV_MESSAGE_SUPPORT__
    FS_Delete((const WCHAR*)filename);
#endif

    return SRV_PROV_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_prov_add_data_to_queue
 * DESCRIPTION
 *  This Add's the new settings received into the queue to be processed later on.
 * PARAMETERS
 *  prov_buffer_p       [?]         S8*         Provisioing data buffer
 *  prov_length         [IN]        U32
 *  hdr_p               [?]         
 *  i_sim_id            [IN]        
 *  header_p            S8*         Data header.(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prov_add_data_to_queue(S8 *prov_buffer_p, U32 prov_length, S8 *hdr_p, U32 i_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_prov_data_queue_last_item >= SRV_PROV_MAX_NBR_DOCUMENTS)
    {
        g_srv_prov_data_queue_last_item = 0;
    }

    if (NULL == g_srv_prov_data_queue_p[g_srv_prov_data_queue_last_item])
    {
        g_srv_prov_data_queue_p[g_srv_prov_data_queue_last_item] =
            (srv_prov_queue_data_struct*) srv_prov_mem_alloc(sizeof(srv_prov_queue_data_struct));
        ASSERT(g_srv_prov_data_queue_p[g_srv_prov_data_queue_last_item]);
    }

    g_srv_prov_data_queue_p[g_srv_prov_data_queue_last_item]->pbuffer = prov_buffer_p;

    g_srv_prov_data_queue_p[g_srv_prov_data_queue_last_item]->p_header = hdr_p;

    g_srv_prov_data_queue_p[g_srv_prov_data_queue_last_item]->plength = prov_length;

    g_srv_prov_data_queue_p[g_srv_prov_data_queue_last_item]->i_sim_id = MMI_SIM1;


switch(i_sim_id)
{
	case MMI_DA_PUSH_SIM1:
		     g_srv_prov_data_queue_p[g_srv_prov_data_queue_last_item]->i_sim_id = MMI_SIM1;
			 break;
#if(MMI_MAX_SIM_NUM>=2)
    case MMI_DA_PUSH_SIM2:
		     g_srv_prov_data_queue_p[g_srv_prov_data_queue_last_item]->i_sim_id = MMI_SIM2;
			 break;
#if(MMI_MAX_SIM_NUM>=3)
    case MMI_DA_PUSH_SIM3:
		     g_srv_prov_data_queue_p[g_srv_prov_data_queue_last_item]->i_sim_id = MMI_SIM3;
			 break;
#if(MMI_MAX_SIM_NUM>=4)
    case MMI_DA_PUSH_SIM4:
		     g_srv_prov_data_queue_p[g_srv_prov_data_queue_last_item]->i_sim_id = MMI_SIM4;
			 break;
#endif
#endif
#endif
}


#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    g_srv_prov_data_queue_p[g_srv_prov_data_queue_last_item]->trans_id = g_srv_prov_ctxt.msg_trans_id;
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */

    g_srv_prov_data_queue_last_item++;
    g_srv_prov_data_queue_size++;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_delete_queue_entry
 * DESCRIPTION
 *  Deletes the current queue entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_delete_queue_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_prov_data_queue_size > 0)
    {
        if (g_srv_prov_data_queue_p[g_srv_prov_data_queue_current_item]->pbuffer)
        {
            srv_prov_mem_free(g_srv_prov_data_queue_p[g_srv_prov_data_queue_current_item]->pbuffer);
            g_srv_prov_data_queue_p[g_srv_prov_data_queue_current_item]->pbuffer = NULL;
        }

        if (g_srv_prov_data_queue_p[g_srv_prov_data_queue_current_item]->p_header)
        {
            srv_prov_mem_free(g_srv_prov_data_queue_p[g_srv_prov_data_queue_current_item]->p_header);
            g_srv_prov_data_queue_p[g_srv_prov_data_queue_current_item]->p_header = NULL;
        }

        if (g_srv_prov_data_queue_p[g_srv_prov_data_queue_current_item])
        {
            srv_prov_mem_free(g_srv_prov_data_queue_p[g_srv_prov_data_queue_current_item]);
            g_srv_prov_data_queue_p[g_srv_prov_data_queue_current_item] = NULL;
        }

        ++g_srv_prov_data_queue_current_item;
        --g_srv_prov_data_queue_size;
        if (g_srv_prov_data_queue_current_item >= SRV_PROV_MAX_NBR_DOCUMENTS)
        {
            g_srv_prov_data_queue_current_item = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_get_current_queue_data
 * DESCRIPTION
 *  returns current queue item.
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_prov_queue_data_struct**
 *****************************************************************************/
srv_prov_queue_data_struct **srv_prov_get_current_queue_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &(g_srv_prov_data_queue_p[g_srv_prov_data_queue_current_item]);
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_start_setting_parser
 * DESCRIPTION
 *  This function initiates parsing of setting wbxml data.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_start_setting_parser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    SRV_PROV_RETCODE prov_err_code = SRV_PROV_OK;
    S8 imsi_buffer[SRV_MAX_IMSI_LEN + 1];

    srv_prov_queue_data_struct *prov_data_p = *(srv_prov_get_current_queue_data());
    mmi_sim_enum  sim_id = MMI_SIM1;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_START_SETTING_PARSER_ENTER);

    if (!(g_srv_prov_data_queue_p[g_srv_prov_data_queue_current_item]->plength))
    {
        /* If file size was more than 2K then 0 is stored in length. */
        srv_prov_handle_error(SRV_PROV_MEM_FULL);
        srv_prov_delete_queue_entry();
        return;
    }

    srv_prov_context_initialize();

#ifdef __PROV_OMA_PIN_VALIDATION_SUPPORT__
    prov_err_code = srv_prov_parse_header();
    if (prov_err_code != SRV_PROV_OK)
    {
        srv_prov_handle_error(prov_err_code);
        srv_prov_delete_queue_entry();
        return;
    }
#endif /* __PROV_OMA_PIN_VALIDATION_SUPPORT__ */ 

#ifndef __MMI_PROV_MESSAGE_SUPPORT__
    if (-1 == g_srv_prov_ctxt.i_sec_value)
#else
    if ((-1 == g_srv_prov_ctxt.i_sec_value) ||
        (g_srv_prov_ctxt.msg_prov_flag & SRV_CCA_PROV_FLAG_PIN_VERIFIED))
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */
    {
        prov_err_code = srv_prov_handle_provisioning_setting();

        if (prov_err_code != SRV_PROV_OK)
        {
            srv_prov_handle_error(prov_err_code);
        }
        srv_prov_delete_queue_entry();
    }
#ifdef __PROV_OMA_PIN_VALIDATION_SUPPORT__
    else
    {
        if ((SRV_PROV_SEC_VALUE_NETWPIN == g_srv_prov_ctxt.i_sec_value) ||
            (SRV_PROV_SEC_VALUE_USERNETWPIN == g_srv_prov_ctxt.i_sec_value))
        {
 


#if (MMI_MAX_SIM_NUM>=2)
switch(prov_data_p->i_sim_id)
{
case MMI_SIM2:
	 sim_id = MMI_SIM2;
	 break;
#if(MMI_MAX_SIM_NUM>=3)
case MMI_SIM3:
	 sim_id = MMI_SIM3;
	 break;
#if(MMI_MAX_SIM_NUM>=4)
case MMI_SIM4:
	 sim_id = MMI_SIM4;
	 break;
#endif
#endif
            }
#endif


            memset(imsi_buffer, 0, sizeof(imsi_buffer));
            if(MMI_FALSE == srv_sim_ctrl_get_imsi(sim_id, imsi_buffer, sizeof(imsi_buffer)) )
            {
                MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_ERROR_IMSI_VALIDATION_FAIL);

                srv_prov_handle_error((S8) SRV_PROV_AUTHENTICATION_FAILED);
                srv_prov_delete_queue_entry();

            }
            else
            {
            srv_prov_convert_to_semi_octet((U8*)imsi_buffer, (U8*) g_srv_prov_ctxt.s_imsi);

            if (SRV_PROV_SEC_VALUE_NETWPIN == g_srv_prov_ctxt.i_sec_value)
            {
                srv_prov_handle_pin(NULL);
            }
            else if (SRV_PROV_SEC_VALUE_USERNETWPIN == g_srv_prov_ctxt.i_sec_value)
            {
                /* USERNETWPIN */
                /* 1st half of pin is IMSI, 2nd half is userpin */
                srv_prov_cca_ui_auth_req(SRV_CCA_STATUS_FAIL);
            }
            }


        }
        else    /* USERPIN, USERPINMAC */
        {
            srv_prov_cca_ui_auth_req(SRV_CCA_STATUS_FAIL);  /* FAIL indicates enter pin. */
        }
    }
#endif /* __PROV_OMA_PIN_VALIDATION_SUPPORT__ */ 

    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_START_SETTING_PARSER_EXIT);
}

#ifdef __PROV_OMA_PIN_VALIDATION_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_prov_parse_header
 * DESCRIPTION
 *  it will parse header and extract SEC, MAC value from it.
 * PARAMETERS
 *  void
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
static SRV_PROV_RETCODE srv_prov_parse_header(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *ls_header = NULL;
    S8* last_ptr = NULL;
    S8 *ls_temp;
    S8 ls_mac[SRV_PROV_MAX_MAC_CHARS + 1];
    SRV_PROV_RETCODE ret_code = SRV_PROV_OK;
    MMI_BOOL lb_mac_ind = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_PARSE_HEADER_ENTER);

    if (0 != strncmp(
                (S8*) g_srv_prov_data_queue_p[g_srv_prov_data_queue_current_item]->p_header,
                (S8*) SRV_PROV_OMA_OTA_MIME,
                strlen((S8*) SRV_PROV_OMA_OTA_MIME)))
    {
        /* Nokia setting dont parse header */
        MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_PARSE_HEADER_EXIT);
        return ret_code;
    }

    ls_header =
        (S8*) srv_prov_mem_alloc(strlen((S8*) g_srv_prov_data_queue_p[g_srv_prov_data_queue_current_item]->p_header) +
                                  1);
    if (!(ls_header))
    {
        return SRV_PROV_MEM_FULL;
    }
    strcpy(ls_header, (S8*) g_srv_prov_data_queue_p[g_srv_prov_data_queue_current_item]->p_header);

    ls_temp = strtok_r(ls_header, (S8*) SRV_PROV_HEADER_SEPARATOR, &last_ptr);      /* 1st will return MIME */

    ls_temp = strtok_r(NULL, (S8*) SRV_PROV_HEADER_SEPARATOR, &last_ptr);   /* will return SEC=1 */
    if ((NULL != ls_temp) && (0 == (strncmp(ls_temp, (S8*) SRV_PROV_SEC_TEXT, strlen((S8*) SRV_PROV_SEC_TEXT)))))
    {
        ls_temp += strlen((S8*) SRV_PROV_SEC_TEXT) + 1; /* will take the pointer next to " SEC=" */
        g_srv_prov_ctxt.i_sec_value = atoi(ls_temp);
        MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_SEC_VALUE, g_srv_prov_ctxt.i_sec_value);
    }

    ls_temp = strtok_r(NULL, (S8*) SRV_PROV_HEADER_SEPARATOR, &last_ptr);   /* will return MAC=...... */
    /* Convert string MAC into equivalent hex value */
    if ((NULL != ls_temp) && (0 == (strncmp(ls_temp, (S8*) SRV_PROV_MAC_TEXT, strlen((S8*) SRV_PROV_MAC_TEXT)))))
    {
        ls_temp += strlen((S8*) SRV_PROV_MAC_TEXT) + 1; /* will take the pointer next to " MAC=" */

        MMI_PRINT(SRV_PROV_TRACE_MOD_INET_APP, SRV_PROV_TRACE_GRP9, "[PROVS] MAC = %s", (S8*) ls_temp);

        srv_prov_convert_ascii_mac_to_hex_mac(ls_temp, ls_mac);
        memcpy(g_srv_prov_ctxt.s_mac, ls_mac, SRV_PROV_MAX_MAC_CHARS);
        g_srv_prov_ctxt.s_mac[SRV_PROV_MAX_MAC_CHARS] = 0;
        lb_mac_ind = MMI_TRUE;
    }

/*    if ((-1 == g_srv_prov_ctxt.i_sec_value) || MAUI_00845669 USIM */
    if ((-1 != g_srv_prov_ctxt.i_sec_value) &&
        (SRV_PROV_SEC_VALUE_USERPINMAC != g_srv_prov_ctxt.i_sec_value) && 
        (!(lb_mac_ind)))
    {
        /* No Security validation information defined for OMA or */
        /* Invalid setting error MAC absent */

        ret_code = (S8) SRV_PROV_ERR;
    }

    srv_prov_mem_free(ls_header);

    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_PARSE_HEADER_EXIT);

    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_convert_ascii_mac_to_hex_mac
 * DESCRIPTION
 *  It will construct Hex mac from ascii mac value. It will convert 2 ASCII
 *  characters to corresponding BYTE value.
 * PARAMETERS
 *  s_ascii_mac     [IN]         
 *  s_hex_mac       [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_convert_ascii_mac_to_hex_mac(S8 *s_ascii_mac, S8 *s_hex_mac)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 i, j, upper_nbl, lower_nbl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0, j = 0; i < (2 * SRV_PROV_MAX_MAC_CHARS); i += 2, j++)
    {
        upper_nbl = srv_prov_char_to_nibble(s_ascii_mac[i]);
        lower_nbl = srv_prov_char_to_nibble(s_ascii_mac[i + 1]);
        s_hex_mac[j] = (S8) ((upper_nbl << 4) | lower_nbl);
    }
    s_hex_mac[j] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_convert_to_semi_octet
 * DESCRIPTION
 *  It will convert IMSI to semi-octet value.
 *  
 *  Network Pin is the IMSI.  The IMSI is required to be
 *  in the semi-octet format defined in GSM 11.11
 *  (ESTI: ETS 300 977) (See 10.3.2 page 54-55 of Version 5.10.1).
 *  The IMSI description:
 *  
 *  BYTE      Description          B8  B7 B6 B5    B4  B3 B2 B1
 *  1        IMSI length
 *  2        Digit 1 | Parity     M1  .. .. L1    P   0  0  1
 *  3        Digit 3 | Digit 2    M3  .. .. L3    M2  .. .. L2
 *  4        Digit 5 | Digit 4    M5  .. .. L5    M4  .. .. L4
 *  5        Digit 7 | Digit 6    M7  .. .. L7    M6  .. .. L6
 *  6        Digit 9 | Digit 8    M9  .. .. L9    M8  .. .. L8
 *  7        Digit 11 | Digit 10  M11 .. .. L11   M10 .. .. L10
 *  8        Digit 13 | Digit 12  M11 .. .. L11   M12 .. .. L12
 *  9        Digit 15 | Digit 14  M11 .. .. L11   M14 .. .. L14
 *  
 *  Key:  P   - parity bit
 *  Mx  - MSB of digit x
 *  Lx  - LSB of digit x
 *  
 *  The IMSI length byte MUST NOT be used in the key.
 *  
 *  Any unused bytes (i.e. IMSI length less than 15) MUST NOT be
 *  used in the key.
 *  
 *  If the IMSI length is an even number, the key MUST USE the
 *  filler 0xF in the spare nibble.
 *  
 *  Example 1: IMSI Length is 15
 *  
 *  IMSI = 262022033864727
 *  
 *  GSM 11.11 Format:
 *  
 *  BYTE    Description               Value  Note
 *  1      IMSI length               0x08   NOT USED IN THE KEY
 *  2      Digit 1 | Parity          0x29
 *  3      Digit 3 | Digit 2         0x26
 *  4      Digit 5 | Digit 4         0x20
 *  5      Digit 7 | Digit 6         0x02
 *  6      Digit 9 | Digit 8         0x33
 *  7      Digit 11 | Digit 10       0x68
 *  8      Digit 13 | Digit 12       0x74
 *  9      Digit 15 | Digit 14       0x72
 *  
 *  key should point to an array  {0x29, 0x26, 0x20, 0x02, 0x33, 0x68, 0x74, 0x72}
 *  and keyLength should be 8
 *  
 *  Example 2: IMSI Length is 2
 *  
 *  IMSI = 26
 *  
 *  GSM 11.11 Format:
 *  
 *  BYTE    Description               Value  Note
 *  1      IMSI length               0x02   NOT USED IN THE KEY
 *  2      Digit 1 | Parity          0x29
 *  3      Digit 3 | Digit 2         0xF6
 *  4      Digit 5 | Digit 4         0xFF   UNUSED DATA
 *  5      Digit 7 | Digit 6         0xFF   UNUSED DATA
 *  6      Digit 9 | Digit 8         0xFF   UNUSED DATA
 *  7      Digit 11 | Digit 10       0xFF   UNUSED DATA
 *  8      Digit 13 | Digit 12       0xFF   UNUSED DATA
 *  9      Digit 15 | Digit 14       0xFF   UNUSED DATA
 *  
 *  key should point to an array {0x21, 0xF6} and keyLength should be 2.
 * PARAMETERS
 *  input       [IN]     
 *  output      [OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_convert_to_semi_octet(U8 *input, U8 *output)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 ls_result[SRV_PROV_MAX_IMSI_CHARS + 1] = {0, };
    U16 li_len;
    U16 counter, index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(input))
    {
        /* Blank IMSI */
        return;
    }

    strcpy((S8*) ls_result, (S8*) (input));
    li_len = strlen((S8*) ls_result) - 1;   /* Ignoring parity byte(1st) from length */

    for (counter = 0; counter <= li_len; counter++)
    {
        ls_result[counter] = srv_prov_char_to_nibble((U8) ls_result[counter]);
    }

    /* Mark remaining characters as 0xff */
    for (counter = counter; counter < SRV_PROV_MAX_IMSI_CHARS; counter++)
    {
        ls_result[counter] = 0xff;
    }

    /* Add remaining Non 0xff nibbles to result. */
    for (counter = index = 0; counter < SRV_PROV_MAX_IMSI_CHARS; counter += 2, index++)
    {
        ls_result[index] = (ls_result[counter + 1] << 4) | ls_result[counter];
        if (ls_result[index] == 0xff)
        {
            break;
        }
    }

    ls_result[index] = 0;
    g_srv_prov_ctxt.i_imsi_len = index;

    memcpy((U8*) output, ls_result, index);
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_validate_data
 * DESCRIPTION
 *  This API will validate data using the entered PIN.
 * PARAMETERS
 *  s_pin           [IN]         
 *  i_pin_len       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE        : SRV_PROV_OK (success), SRV_PROV_ERR (failure)
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_validate_data(S8 *s_pin, U16 i_pin_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    STCHE che_context;
    U8 result_mac[SRV_PROV_MAX_MAC_CHARS + 1] = {0, };
    U8 temp_mac[SRV_PROV_MAX_MAC_CHARS + 1] = {0, };
    SRV_PROV_RETCODE ret_code = SRV_PROV_ERR;
    U32 counter;
    srv_prov_queue_data_struct *prov_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_VALIDATE_DATA_ENTER);

    prov_data_p = *(srv_prov_get_current_queue_data());

    che_init(&che_context, CHE_MAC_SHA1);
    che_key_action(&che_context, CHE_SET_KEY, (U8*) s_pin, i_pin_len);
    che_process(
        &che_context,
        CHE_MAC_SHA1,
        CHE_MODE_NULL,
        CHE_HASH,
        (U8*) prov_data_p->pbuffer,
        (U8*) result_mac,
        prov_data_p->plength,
        KAL_TRUE);

    che_deinit(&che_context);

    /* Convert MAC to OMA SPEC[PROVBOOT] format if USERPINMAC */
    if (SRV_PROV_SEC_VALUE_USERPINMAC == g_srv_prov_ctxt.i_sec_value)
    {
        memcpy((S8*) temp_mac, (S8*) result_mac, SRV_PROV_MAX_MAC_CHARS);
        for (counter = 0; counter < SRV_PROV_MAX_MAC_CHARS; counter++)
        {
            result_mac[counter] = (U8) ((temp_mac[counter] % 10) + (U8) 48);    /* 48 = ascii '0', OMA Spec [PROVBOOT] */
        }
        result_mac[counter] = 0;
    }

    if (0 == (memcmp(g_srv_prov_ctxt.s_mac, result_mac, g_srv_prov_ctxt.i_mac_len)))
    {
        ret_code = SRV_PROV_OK;
    }

    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_VALIDATE_DATA_EXIT);

    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_handle_pin
 * DESCRIPTION
 *  This API will handle the pin entered.
 * PARAMETERS
 *  s_pin       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_handle_pin(S8 *s_pin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 li_pinmac_len;
    S8 ls_key[SRV_PROV_MAX_PIN_CHARS + SRV_PROV_MAX_IMSI_CHARS + 1] = {0, };
    SRV_PROV_RETCODE prov_ret_code = SRV_PROV_OK;
    U16 li_key_len = 0;
    U16 index, index_1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_prov_ctxt.i_sec_value)
    {
        case SRV_PROV_SEC_VALUE_NETWPIN:
            memcpy(ls_key, (S8*) g_srv_prov_ctxt.s_imsi, g_srv_prov_ctxt.i_imsi_len);
            li_key_len = g_srv_prov_ctxt.i_imsi_len;
            break;

        case SRV_PROV_SEC_VALUE_USERPIN:
            ASSERT(s_pin);
            strcpy(ls_key, (S8*) s_pin);
            li_key_len = strlen(s_pin);
            break;

        case SRV_PROV_SEC_VALUE_USERNETWPIN:
            ASSERT(s_pin);
            /* 1st half of pin = imsi */
            memcpy(ls_key, (S8*) g_srv_prov_ctxt.s_imsi, g_srv_prov_ctxt.i_imsi_len);
            /* 2nd half of pin = userpin */
            for (index = g_srv_prov_ctxt.i_imsi_len, index_1 = 0; index_1 < strlen((S8*) s_pin); index++, index_1++)
            {
                ls_key[index] = s_pin[index_1];
            }
            li_key_len = index;
            break;

        case SRV_PROV_SEC_VALUE_USERPINMAC:
            ASSERT(s_pin);
            li_pinmac_len = strlen((S8*) s_pin);

            /*
             * pin should be minimum 8 len (min 4 digits of key + 4 digits of MAC)
             * * and even len defined from OMA SPEC [PROVBOOT]
             */
            if ((li_pinmac_len >= 8) && (0 == (li_pinmac_len % 2)))
            {
                /* 1st half of entered value is pin */
                /* strlen can be used here as value is ascii coded */
                memset(ls_key, 0, (SRV_PROV_MAX_PIN_CHARS + SRV_PROV_MAX_IMSI_CHARS + 1));
                memcpy(ls_key, (S8*) s_pin, (SRV_PROV_MAX_PIN_CHARS + SRV_PROV_MAX_IMSI_CHARS ));

                /* 2nd half of entered value is MAC digits */

                memset((S8*) g_srv_prov_ctxt.s_mac, 0, (SRV_PROV_MAX_MAC_CHARS + 1));
                memcpy((S8*) g_srv_prov_ctxt.s_mac, (S8*) (s_pin + (li_pinmac_len / 2)), (SRV_PROV_MAX_MAC_CHARS));
                /* strlen can be used here as value is ascii coded */
                g_srv_prov_ctxt.i_mac_len = strlen((S8*) g_srv_prov_ctxt.s_mac);
                li_key_len = strlen(ls_key);
            }
            else
            {
                /* wrong value entered, re-enter pin */
                srv_prov_cca_ui_auth_req(SRV_CCA_STATUS_FAIL);
                return;
            }
            break;

        default:
            /* Error value */
            MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_ERROR_SEC_VALUE, g_srv_prov_ctxt.i_sec_value);
            prov_ret_code = (S8) SRV_PROV_ERR;
            goto error_jmp;
    }

    prov_ret_code = srv_prov_validate_data(ls_key, li_key_len);
    if (SRV_PROV_ERR == prov_ret_code)
    {
        if (SRV_PROV_SEC_VALUE_NETWPIN != g_srv_prov_ctxt.i_sec_value)
        {
            /* Validation failed re-enter pin. */
            srv_prov_cca_ui_auth_req(SRV_CCA_STATUS_FAIL);
            return;
        }
        else
        {
            /* NETWPIN validation failed discard setting. */
            MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_ERROR_IMSI_VALIDATION_FAIL);
            prov_ret_code = (S8) SRV_PROV_AUTHENTICATION_FAILED;
            goto error_jmp;
        }
    }
    if (SRV_PROV_SEC_VALUE_NETWPIN != g_srv_prov_ctxt.i_sec_value)
    {
        /* Send OK ind to cca to indicate success pin validation. */
        srv_prov_cca_ui_auth_req(SRV_CCA_STATUS_OK);
    }
    prov_ret_code = srv_prov_handle_provisioning_setting();

  error_jmp:

    if (prov_ret_code != SRV_PROV_OK)
    {
        srv_prov_handle_error(prov_ret_code);
    }
    srv_prov_delete_queue_entry();
}

#endif /* __PROV_OMA_PIN_VALIDATION_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_prov_queue_is_not_empty
 * DESCRIPTION
 *  It will check if there is any data in queue or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_prov_queue_is_not_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_prov_data_queue_size > 0)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_handle_error
 * DESCRIPTION
 *  error handler.
 * PARAMETERS
 *  i_ret       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_handle_error(SRV_PROV_RETCODE i_ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_status_enum status = SRV_CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (i_ret)
    {
        case SRV_PROV_ERR:
        case SRV_PROV_UNKNOWN_TAG:
            status = SRV_CCA_STATUS_FAIL;
            break;

    #ifdef __PROV_OMA_PIN_VALIDATION_SUPPORT__

        case SRV_PROV_AUTHENTICATION_FAILED:
            status = SRV_CCA_STATUS_AUTH_FAILED;
            break;

    #endif /* __PROV_OMA_PIN_VALIDATION_SUPPORT__ */ 

        case SRV_PROV_MEM_FULL:
            status = SRV_CCA_STATUS_MEMFULL;
            break;

        case SRV_PROV_CORRUPT_SETTING:
            status = SRV_CCA_STATUS_CORRUPTED_SETTING;
            break;
            
        case SRV_PROV_GET_MSG_FAILED:
            status = SRV_CCA_STATUS_GET_MSG_FAILED;
            break;

        default:
            ASSERT(0);
    }
    srv_prov_cca_invalid_setting_ind_req(status);
    
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    srv_prov_send_cca_source_install_prov_msg_cnf(g_srv_prov_ctxt.msg_id, 
            g_srv_prov_ctxt.msg_trans_id, g_srv_prov_ctxt.msg_sim_id,
        g_srv_prov_ctxt.msg_prov_type, g_srv_prov_ctxt.msg_prov_flag, status);
#endif
}

#endif /* __MMI_PROV_SERVICE_CCA_SUPPORT_ON__ */ 
#endif /* __MMI_PROVISIONING_SERVICE_SUPPORT__ */ 


#ifndef __MMI_PROVISIONING_SERVICE_SUPPORT__
MMI_BOOL srv_prov_delete_file(PU16 filename, PS8 mime_type_str_string, const S8* wap_addr)
{
	 FS_HANDLE file_handle;
    S8 temp_filename[100];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(temp_filename, 0, sizeof(temp_filename));
    mmi_ucs2_n_to_asc(temp_filename, (S8*) filename, 99);

    file_handle = FS_Open((const WCHAR*)filename, FS_READ_ONLY);

    if (file_handle < FS_NO_ERROR)
    {
        return MMI_FALSE;
    }

    ASSERT(FS_Close(file_handle) == FS_NO_ERROR);
    FS_Delete((const WCHAR*)filename);

    return MMI_TRUE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_prov_da_push_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_id                  [IN]        
 *  mime_type                   [IN]        
 *  mime_subtype                [IN]        
 *  action                      [IN]        
 *  filesize                    [IN]        
 *  url                         [IN]        
 *  mime_type_string            [IN]      
 *  content_len                 [IN]
 *  content                     [IN]
 *  setting                     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_da_push_setting(
    S32 session_id,
    S32 mime_type,
    S32 mime_subtype,
    S32 action,
    U32 filesize,
    PS8 url,
    PS8 mime_type_string,
    U32 content_len,
    PS8 content,
    srv_da_setting_struct * setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PROVISIONING_SERVICE_SUPPORT__
    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_DA_PUSH_SETTING_SOURCE, action);
#endif

    if ((action != MMI_DA_PUSH && action != MMI_DA_PUSH_SIM2) && (action !=MMI_DA_PUSH_SIM3 && action !=MMI_DA_PUSH_SIM4))
    {
        srv_da_default_setting(
            session_id,
            mime_type,
            mime_subtype,
            action,
            filesize,
            url,
            mime_type_string,
            content_len,
            content,
            setting);
        setting->do_dispatch = MMI_FALSE;
    }
    else
    {
        srv_da_push_setting(
            session_id,
            mime_type,
            mime_subtype,
            action,
            filesize,
            url,
            mime_type_string,
            content_len,
            content,
            setting);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_receive_da_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_id                  [IN]        
 *  mime_type                   [IN]        
 *  mime_subtype                [IN]        
 *  action_type                 [IN]        
 *  filename                    [IN]        
 *  download_url                [IN]        
 *  mime_type_str_string        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_receive_da_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action_type,
        PU16 filename,
        PS8 download_url,
        PS8 mime_type_str_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_phs_addr_struct *sender_addr = NULL;
    const srv_da_extra_info_struct *extra_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PROVISIONING_SERVICE_SUPPORT__
    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_RECEIVE_DA_FILE_ENTER);
#endif

    /* get sender address info from extra_info */
    extra_info = srv_da_get_extra_info(session_id);
    if (extra_info != NULL)
    {
        if (extra_info->size < sizeof(wap_phs_addr_struct))
            sender_addr = NULL;
        else
        sender_addr = (wap_phs_addr_struct*)extra_info->data;
    }
#ifdef __MMI_PROVISIONING_SERVICE_SUPPORT__
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    srv_prov_send_provbox_save_msg_req((U8)action_type, filename, mime_type_str_string, (const S8*)sender_addr);
#else
    srv_prov_process_new_provisioning_message(filename, action_type, mime_type_str_string, (const S8*)sender_addr);
#endif
#else
	srv_prov_delete_file(filename,mime_type_str_string,(const S8*)sender_addr);
#endif
#ifdef __MMI_PROVISIONING_SERVICE_SUPPORT__
    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_RECEIVE_DA_FILE_EXIT);
#endif
}

#endif /* _PROVSERVICEMAIN_C */ 

