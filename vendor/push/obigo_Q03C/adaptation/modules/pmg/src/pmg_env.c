/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   pmg_env.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains PMG ILM/Obigo signal handlers and connector functions.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "msf_cfg.h"
#include "msf_core.h"
#include "msf_int.h"
#include "msf_mem.h"
//#include "msf_dcvt.h"
#include "msf_log.h"
#include "msf_pipe.h"
#include "msf_file.h"
//#include "msf_chrs.h"
#include "msf_errc.h"

#include "msf_def.h"
//#include "msf_lib.h"
//#include "msf_wid.h"

#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
//#include "stack_types.h"
#include "app_ltlcom.h" /* Task message communiction */
//#include "task_config.h"        /* Task creation */

#include "MMI_features.h"
//#include "UMGprot.h"

#include "pmg_struct.h"
#include "pmg_dl.h"
#include "pmg_env.h"
#include "pmg_main.h"
#include "pmg_if.h"
#include "pmg_msg.h"
#include "pmg_inbox.h"
#include "pmg_um.h"
#include "pmg_phs.h"

//suggested add
	#include "kal_trace.h"
    #include "wps_trc.h"
    #include "errno.h"
    #include "setjmp.h"
    #include "string.h"
    #include "msf_cmmn.h"
    #include "UmSrvDefs.h"
    #include "UmSrvStruct.h"
    #include "kal_general_types.h"
    #include "stack_config.h"
    #include "kal_public_api.h"
    #include "stack_ltlcom.h"
	#include "MMIDataType.h"


static void pmg_receive(MSF_UINT8 srcModule, MSF_UINT16 signal, void *p);


/*****************************************************************************
 * FUNCTION
 *  PMGc_start
 * DESCRIPTION
 *  PMG initialization routine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PMGc_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_inside_run = FALSE;
    pmg_init();
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_LOW, MSF_MODID_PMG, PMG_ENV_58543ACEE3AFB29A1AFE5B1C77135190,
                       "PMG: Initialised\n"));
}


/*****************************************************************************
 * FUNCTION
 *  PMGc_wantsToRun
 * DESCRIPTION
 *  check whether PMG has signal to process
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int PMGc_wantsToRun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MSF_SIGNAL_QUEUE_LENGTH(MSF_MODID_PMG) > 0);
}


/*****************************************************************************
 * FUNCTION
 *  PMGc_run
 * DESCRIPTION
 *  PMG execute routine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PMGc_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (setjmp(pmg_jmp_buf) == 0)
    {
        pmg_inside_run = TRUE;
        while (MSF_SIGNAL_RETRIEVE(MSF_MODID_PMG, pmg_receive))
            ;

        pmg_inside_run = FALSE;
    }
    else
    {
        /*
         * A longjmp from pmg_exception_handler. If we are here there is no more
         * * memory, and the situation could not be worse.
         * * Send out an error and terminate.
         */
        MSF_ERROR(MSF_MODID_PMG, MSF_ERR_MODULE_OUT_OF_MEMORY);
        MSF_PIPE_CLOSE_ALL(MSF_MODID_PMG);
        MSF_FILE_CLOSE_ALL(MSF_MODID_PMG);
        MSF_MEM_FREE_ALL(MSF_MODID_PMG);
        MSF_MODULE_IS_TERMINATED(MSF_MODID_PMG);
        MSF_SIGNAL_DEREGISTER_QUEUE(MSF_MODID_PMG);
        MSF_KILL_TASK(MSF_MODID_PMG);
    }
}


/*****************************************************************************
 * FUNCTION
 *  PMGc_kill
 * DESCRIPTION
 *  PMG termination routine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PMGc_kill(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_PIPE_CLOSE_ALL(MSF_MODID_PMG);
    MSF_FILE_CLOSE_ALL(MSF_MODID_PMG);
    MSF_MEM_FREE_ALL(MSF_MODID_PMG);
    MSF_KILL_TASK(MSF_MODID_PMG);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_receive
 * DESCRIPTION
 *  PMG signal processing routine
 * PARAMETERS
 *  srcModule       [IN]        
 *  signal          [IN]        
 *  p               [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void pmg_receive(MSF_UINT8 srcModule, MSF_UINT16 signal, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (signal)
    {

/**********************************************************************
 * Signals from the MSF
 **********************************************************************/
        case MSF_SIG_MODULE_EXECUTE_COMMAND:
			        {
                msf_module_execute_cmd_t *q = (msf_module_execute_cmd_t *)p;



            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_2EB845972207693EEE861B30A15D2F55,
                               "PMG: Received MSF_SIG_MODULE_EXECUTE_COMMAND\n"));
			                if(q)
                        {
                                PMG_MEM_FREE(q->commandOptions);
						        msf_content_data_free(MSF_MODID_PMG, q->contentData);                                                    
                        }
				}
            break;

        case MSF_SIG_MODULE_TERMINATE:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_DF8EE937AF191897006DA405CC7ED33C,
                               "PMG: Received MSF_SIG_MODULE_TERMINATE\n"));
            pmg_terminate((msf_module_terminate_t*) p);
            return;

        case MSF_SIG_TIMER_EXPIRED:
            break;

        case MSF_SIG_PIPE_NOTIFY:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_PIPE_NOTIFICATION_RECEIVED,
                               "PMG: Received MSF_SIG_PIPE_NOTIFY\n"));
            pmg_handle_pipe_notify(((msf_pipe_notify_t*) p)->handle, ((msf_pipe_notify_t*) p)->eventType);
            
            break;

/**********************************************************************
 * Signals from the PMG
 **********************************************************************/
        case PMG_SIG_GET_MSG_BY_ATTRIBUTE:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_B62864E7D9877A82F7EB9AA08860AF65,
                               "PMG: Received PMG_SIG_GET_MSG_BY_ATTRIBUTE\n"));
            pmg_phs_handle_get_msg_by_attribute(srcModule, p);
            break;

        case PMG_SIG_DELETE_MSG:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_AEB75233978E0DE9A45DD827685FB024,
                               "PMG: Received PMG_SIG_DELETE_MSG\n"));
            pmg_phs_handle_delete_msg(srcModule, p);
            break;

        case PMG_SIG_CREATE_MSG:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_1DF451DD8A5C0155A25C5ED9DA9A30A4,
                               "PMG: Received PMG_SIG_CREATE_MSG\n"));
            pmg_phs_handle_create_msg(srcModule, p);
            pmg_lib_release_msg((pmg_full_msg_t*) (((pmg_create_msg_t*) p)->msg));
            break;

		case PMG_SIG_CONTENT_DATA_ROUTE_REQ:

			pmg_dl_handle_content_data_route(srcModule, p);
			
#ifndef __OBIGO_FRMW2__
			PMG_MEM_FREE(((pmg_content_send_t*)p)->startOptions);
			PMG_MEM_FREE(((pmg_content_send_t*)p)->contentData->routingIdentifier );
			PMG_MEM_FREE(((pmg_content_send_t*)p)->contentData->contentUrl);
			PMG_MEM_FREE(((pmg_content_send_t*)p)->contentData->contentSource);
			PMG_MEM_FREE(((pmg_content_send_t*)p)->contentData->contentParameters);
			PMG_MEM_FREE(((pmg_content_send_t*)p)->contentData->contentHeaders);
			PMG_MEM_FREE(((pmg_content_send_t*)p)->contentData->contentData);
			PMG_MEM_FREE(((pmg_content_send_t*)p)->contentData->auxTypeIdentifier);
			PMG_MEM_FREE(((pmg_content_send_t*)p)->contentData->attrString);
			PMG_MEM_FREE(((pmg_content_send_t*)p)->contentData->contentDRMData->drmContentHeaders);
			PMG_MEM_FREE(((pmg_content_send_t*)p)->contentData->contentDRMData->drmData );
#endif /*__OBIGO_FRMW2__*/
			
			break;
		

/**********************************************************************
 * Signals from the Service Inbox
 **********************************************************************/
        case PMG_SIG_INBOX_CONFIG_REQ:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_9CC82591C302F806438DC656867EB43F,
                               "PMG: Received PMG_SIG_INBOX_CONFIG_REQ\n"));
            pmg_inbox_handle_config_req(p);
            break;

        case PMG_SIG_INBOX_MSG_COUNT_REQ:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_939D86126AFF4B5300FCCF443D09B4C0,
                               "PMG: Received PMG_SIG_INBOX_MSG_COUNT_REQ\n"));
            pmg_inbox_handle_msg_count_req(p);
            break;

        case PMG_SIG_INBOX_MSG_LIST_REQ:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_45609388CB6A5487ABA926A5FB20DAA7,
                               "PMG: Received PMG_SIG_INBOX_MSG_LIST_REQ\n"));
            pmg_inbox_handle_msg_list_req(p);
            break;

		/* SKS */
	case PMG_SIG_INBOX_MSG_READ_STATUS_REQ:

		pmg_inbox_handle_msg_read_status_req(p);
		break;
		/* SKS */

        case PMG_SIG_INBOX_GET_MSG_REQ:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_1E3C8B459431BB8540DA5B2902C4EDFC,
                             "PMG: Received PMG_SIG_INBOX_GET_MSG_REQ\n"));
            pmg_inbox_handle_get_msg_req(p);
            break;

        case PMG_SIG_INBOX_GET_MSG_INFOTAG_REQ:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_5ADA0F03AC00AEB5A016BC4075312074,
                             "PMG: Received PMG_SIG_INBOX_GET_MSG_INFOTAG_REQ\n"));
            pmg_inbox_handle_get_msg_infotag_req(p);
            break;

        case PMG_SIG_INBOX_DELETE_MSG_REQ:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_E78B92751DC364FE4E4FB242CA6A3FC2,
                             "PMG: Received PMG_SIG_INBOX_DELETE_MSG_REQ\n"));
            pmg_inbox_handle_delete_msg_req(p);
            break;

        case PMG_SIG_INBOX_DELETE_ALL_REQ:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_F815E05E2D96CBA97DF3DD4D8F9EE7AF,
                             "PMG: Received PMG_SIG_INBOX_DELETE_ALL_REQ\n"));
            pmg_inbox_handle_delete_all_req(p);
            break;

        case PMG_SIG_INBOX_UPDATE_MSG_REQ:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_F43C2FAD9654B44BB9A61FBC60353032,
                             "PMG: Received PMG_SIG_INBOX_UPDATE_MSG_REQ\n"));
            pmg_inbox_handle_update_msg_req(p);
            break;
#ifdef PHS_CFG_PUSH_SLIM_SUPPORT    
 	case PMG_SIG_INBOX_UPDATE_ALL_MSG_REQ:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_F43C2FAD9654B44BB9A61FBC60353032,
                             "PMG: Received PMG_SIG_INBOX_UPDATE_MSG_REQ\n"));
            pmg_inbox_handle_update_all_msg_req(p);
            break;
#endif
        case PMG_SIG_INBOX_NEW_MSG_RSP:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_CC29381DDBAF8EF63FA93A5903167420,
                             "PMG: Received PMG_SIG_INBOX_NEW_MSG_RSP\n"));
            pmg_inbox_handle_new_msg_rsp();
            break;
#ifdef PHS_CFG_PUSH_WHITELIST_SUPPORT
        case PMG_SIG_INBOX_AUTH_ADDR_LIST_REQ:
        {
            pmg_addr_t *addrs;
            int i, size;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_AFF71C5DA1D969DB600A7C48142D68CF,
                             "PMG: Received PMG_SIG_INBOX_AUTH_ADDR_LIST_REQ\n"));
            pmg_inbox_handle_auth_addr_list_req(p);

            addrs = (pmg_addr_t*) (((pmg_inbox_auth_addr_list_req_t*) p)->addrs);
            size = ((pmg_inbox_auth_addr_list_req_t *) p)->size;
            for (i = 0; i < size; i++)
            {
                if (addrs[i].addr)
                    PMG_MEM_FREE(addrs[i].addr);
            }
            PMG_MEM_FREE(addrs);
        }
            break;
#endif
#ifdef PHS_CFG_PUSH_SLIM_SUPPORT
        case PMG_SIG_INBOX_DLG_RESPONSE:

            if (((pmg_inbox_dlg_response_t *) p)->type == PMG_DLG_SIA_CONFIRM)
            {

                pmg_inbox_handle_dlg_sia_confirm(((pmg_inbox_dlg_response_t *) p)->id, ((pmg_inbox_dlg_response_t *) p)->result);

            }
            else if (((pmg_inbox_dlg_response_t *) p)->type == PMG_DLG_UNKNOWN_ADDR)
            {
                pmg_inbox_handle_dlg_unknown_addr(((pmg_inbox_dlg_response_t *) p)->id, ((pmg_inbox_dlg_response_t *) p)->result);
            }
#endif             
/**********************************************************************
 * Signals from the Unified Message
 **********************************************************************/
    #ifdef __MMI_PUSH_IN_UM__
        case PMG_SIG_UM_GET_MSG_NUM_REQ:
           MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_CE1EA7F8D0E93BC577A7B62C0207EEB1,
                             "PMG: Received PMG_SIG_UM_GET_MSG_NUM_REQ\n"));
            pmg_um_handle_get_msg_num_req(p);
            break;

        case PMG_SIG_UM_GET_LIST_REQ:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_DBB5B0B7BACCDE248FF03E7C86A06BF8,
                              "PMG: Received PMG_SIG_UM_GET_LIST_REQ\n"));
            pmg_um_handle_get_list_req(p);
            break;


#ifdef WPS_PMG_CONVERSATION_BOX
       case PMG_SIG_UM_GET_TRAVERSE_LIST_REQ:
			MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_GET_TRAVERSE_LIST_REQ,
                         "PMG: Received PMG_SIG_UM_GET_TRAVERSE_LIST_REQ\n"));
            pmg_um_handle_get_traverse_list_req(p);
            break;
#endif /* WPS_PMG_CONVERSATION_BOX */


        case PMG_SIG_UM_DELETE_FOLDER_REQ:
           MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_2732D714D81B964F280B735240721D82,
                               "PMG: Received PMG_SIG_UM_DELETE_FOLDER_REQ\n"));
            pmg_um_handle_delete_folder_req(p);
            break;

    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        case PMG_SIG_UM_MULTI_OP_REQ:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_PMG_SIG_UM_MULTI_OP_REQ,
                               "PMG: Received PMG_SIG_UM_MULTI_OP_REQ\n"));
            pmg_um_handle_multi_op_req(p);
            break;
    #endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
        case PMG_SIG_UM_GET_MSG_INFO_REQ:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_9212B656636DAAEC0AC9EB7FFF7A8701, "PMG: Received PMG_SIG_UM_GET_MSG_INFO_REQ\n"));
            pmg_um_handle_get_msg_info_req(p);
            break;
    #endif /* __MMI_PUSH_IN_UM__ */ 
#ifdef PHS_CFG_PUSH_SLIM_SUPPORT  
        case PMG_SIG_DISPLAY_DIALOG_REQ:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_F8C2FE9FB271DB301CC48BCF9579CCC4, "PMG: Received PMG_SIG_DISPLAY_DIALOG_REQ"));
            pmg_inbox_handle_display_dialog_req(p);
            break;

        case PMG_SIG_INBOX_DLG_QUERY_REQ:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_1DD8664F641D99E2F2675C1C968586B1, "PMG: Received PMG_SIG_INBOX_DLG_QUERY_REQ"));
            pmg_inbox_handle_dlg_query_req(p);
		break;
#endif
/**********************************************************************
 * Unrecognised signal
 **********************************************************************/
        default:
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_1D308790447F1C96F9EDC2220657E356,
                              "PMG: Received unknown signal (%04x)\n", signal));
            break;
    }
#ifdef __OBIGO_FRMW2__
    MSF_SIGNAL_DESTRUCT(MSF_MODID_PMG, signal, p);
#else
	MSF_MEM_FREE(MSF_MODID_PMG, p);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  pmg_external_msg_hdlr
 * DESCRIPTION
 *  PMG external queue handler routine
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  
 *****************************************************************************/
int pmg_external_msg_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = (ilm_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
            /* From Service Inbox */
        case MSG_ID_WPS_PMG_CONFIG_REQ:
        {
            wps_pmg_config_req_struct *data = (wps_pmg_config_req_struct*) (ilm_ptr->local_para_ptr);

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_089C7D4401F70932357AF41BB20F2C2D,
                               "PMG: Received MSG_ID_WPS_PMG_CONFIG_REQ\n"));
            PMGif_inboxConfigReq(
                data->wap_push_enabled, 
                data->sl_enabled, 
                data->trust_enabled,
                data->black_list_enabled,
                data->max_trust_addr_no,
                data->max_black_addr_no);
            return 1;
        }
        case MSG_ID_WPS_PMG_MSG_COUNT_REQ:
        {
            wps_pmg_msg_count_req_struct *data = (wps_pmg_msg_count_req_struct*) (ilm_ptr->local_para_ptr);

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_14DF0B6A93B484B0A9F05956F7FD8B53,
                               "PMG: Received MSG_ID_WPS_PMG_MSG_COUNT_REQ\n"));
            PMGif_inboxMsgCountReq(data->trans_id, data->msg_type, data->is_read, data->is_expired, data->has_info);
            return 1;
        }
        case MSG_ID_WPS_PMG_MSG_LIST_REQ:
        {
            wps_pmg_msg_list_req_struct *data = (wps_pmg_msg_list_req_struct*) (ilm_ptr->local_para_ptr);

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_B460681842234BDD5AAFCDD3AC77BEDD,
                               "PMG: Received MSG_ID_WPS_PMG_MSG_LIST_REQ\n"));
            PMGif_inboxMsgListReq(
                data->trans_id,
                data->msg_type,
                data->is_read,
                data->is_expired,
                data->has_info,
                data->start_from,
                data->size);
            return 1;
        }
        case MSG_ID_WPS_PMG_GET_MSG_REQ:
        {
            wps_pmg_get_msg_req_struct *data = (wps_pmg_get_msg_req_struct*) (ilm_ptr->local_para_ptr);

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_9B8AC3DCE38F2E2E9CFA50A791CD5EA8,
                               "PMG: Received MSG_ID_WPS_PMG_GET_MSG_REQ\n"));
            PMGif_inboxGetMsgReq(data->trans_id, data->msg_id);
            return 1;
        }

	/* SKS */
	case MSG_ID_WPS_PMG_MSG_READ_STATUS_REQ:
	{
		wps_pmg_msg_read_status_req_struct *data = (wps_pmg_msg_read_status_req_struct *) (ilm_ptr->local_para_ptr);

		PMGif_inboxGetReadStatus(data->msg_id, (srv_wap_push_msg_read_status_func) data->status_func);
		return 1;
	}
#ifdef __MMI_PUSH_TURN_ON_OFF_SWITCH__
	case MSG_ID_WPS_PMG_TURN_ON_OFF_PUSH_REQ:
	{
		wps_pmg_push_turn_on_off_req_struct *data = (wps_pmg_push_turn_on_off_req_struct*)(ilm_ptr->local_para_ptr);
		
		PMGif_inboxTurnOnOffPush(data->push_turn_on_switch);
	}
#endif/*__MMI_PUSH_TURN_ON_OFF_SWITCH__*/
	
	/* SKS */
        case MSG_ID_WPS_PMG_GET_MSG_INFOTAG_REQ:
        {
            wps_pmg_get_msg_infotag_req_struct *data = (wps_pmg_get_msg_infotag_req_struct*) (ilm_ptr->local_para_ptr);

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_91159D3374DDDD3515C1FEE1DA3FBE66,
                               "PMG: Received MSG_ID_WPS_PMG_GET_MSG_INFOTAG_REQ\n"));
            PMGif_inboxGetMsgInfoTagReq(data->trans_id, data->msg_id, data->start_from);
            return 1;
        }
        case MSG_ID_WPS_PMG_DELETE_MSG_REQ:
        {
            wps_pmg_delete_msg_req_struct *data = (wps_pmg_delete_msg_req_struct*) (ilm_ptr->local_para_ptr);

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_C907406EEB34F5F48A2CFD21451A34F4,
                               "PMG: Received MSG_ID_WPS_PMG_DELETE_MSG_REQ\n"));
            PMGif_inboxDeleteMsgReq(data->trans_id, data->msg_id);
            return 1;
        }
        case MSG_ID_WPS_PMG_DELETE_ALL_REQ:
        {
            wps_pmg_delete_all_req_struct *data = (wps_pmg_delete_all_req_struct*) (ilm_ptr->local_para_ptr);

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_83F9A2FB15CEF98E780F4E71588A1A19,
                               "PMG: Received MSG_ID_WPS_PMG_DELETE_ALL_REQ\n"));
            PMGif_inboxDeleteAllReq(data->trans_id, data->msg_type);
            return 1;
        }
        case MSG_ID_WPS_PMG_UPDATE_MSG_REQ:
        {
            wps_pmg_update_msg_req_struct *data = (wps_pmg_update_msg_req_struct*) (ilm_ptr->local_para_ptr);

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_0B350B60C239ABB54B4F7D3A697CB01F,
                              "PMG: Received MSG_ID_WPS_PMG_UPDATE_MSG_REQ\n"));
            PMGif_inboxUpdateMsgReq(data->trans_id, data->msg_id, data->read);
            return 1;
        }
#ifdef PHS_CFG_PUSH_SLIM_SUPPORT  
	case MSG_ID_WPS_PMG_UPDATE_ALL_MSG_REQ:
		 {
            wps_pmg_update_all_msg_req_struct *data = (wps_pmg_update_all_msg_req_struct*) (ilm_ptr->local_para_ptr);

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_0B350B60C239ABB54B4F7D3A697CB01F,
                              "PMG: Received MSG_ID_WPS_PMG_UPDATE_ALL_MSG_REQ\n"));
            PMGif_inboxUpdateAllMsgReq(data->read);
            return 1;
        }
#endif	
        case MSG_ID_WPS_PMG_NEW_MSG_RSP:
        {
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_0E3762E1F76CF0D844675438C773793E,
                               "PMG: Received MSG_ID_WPS_PMG_NEW_MSG_RSP\n"));
            PMGif_inboxNewMsgRsp();
            return 1;
        }
#ifdef PHS_CFG_PUSH_WHITELIST_SUPPORT
        case MSG_ID_WPS_PMG_TRUST_ADDR_LIST_REQ:
        {
            pmg_addr_t *addrs = 0;
            int i;
            wps_pmg_trust_addr_list_req_struct *data = (wps_pmg_trust_addr_list_req_struct*) (ilm_ptr->local_para_ptr);

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_74339FBAE1F6B6F8151ABC54E68F7241,
                              "PMG: Received MSG_ID_WPS_PMG_TRUST_ADDR_LIST_REQ\n"));

            addrs = pmg_mem_alloc(data->size * sizeof(pmg_addr_t));
            memset(addrs, 0, data->size * sizeof(pmg_addr_t));

            for (i = 0; i < (int)(data->size); i++)
            {
                addrs[i].addr = msf_cmmn_strdup(MSF_MODID_PMG, (const char*)(data->addresses[i].addr));
                addrs[i].addrType = (MSF_UINT8) (data->addresses[i].addr_type);
            }

            PMGif_inboxSetAuthListReq(data->trans_id, PMG_AUTH_LIST_TYPE_WHITE, data->segment, data->size, (int)addrs, data->total_segment);
            return 1;
        }

        case MSG_ID_WPS_PMG_BLACK_ADDR_LIST_REQ:
        {
            pmg_addr_t *addrs = 0;
            int i;
            wps_pmg_black_addr_list_req_struct *data = (wps_pmg_black_addr_list_req_struct*) (ilm_ptr->local_para_ptr);

            MSF_LOG_MSG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, "PMG: Received MSG_ID_WPS_PMG_BLACK_ADDR_LIST_REQ\n"));

            addrs = pmg_mem_alloc(data->size * sizeof(pmg_addr_t));
            memset(addrs, 0, data->size * sizeof(pmg_addr_t));

            for (i = 0; i < (int)(data->size); i++)
            {
                addrs[i].addr = msf_cmmn_strdup(MSF_MODID_PMG, (const char*)(data->addresses[i].addr));
                addrs[i].addrType = (MSF_UINT8) (data->addresses[i].addr_type);
            }

            PMGif_inboxSetAuthListReq(data->trans_id, PMG_AUTH_LIST_TYPE_BLACK, data->segment, data->size, (int)addrs, data->total_segment);
            return 1;
        }
#endif
    #ifdef __MMI_PUSH_IN_UM__
            /* from Unified Message */
        case MSG_ID_MMI_UM_GET_MSG_NUM_REQ:
        {
            /* srv_um_get_msg_num_req_struct *data = (srv_um_get_msg_num_req_struct*)(ilm_ptr->local_para_ptr); */
            if (((srv_um_get_msg_num_req_struct*) (ilm_ptr->local_para_ptr))->msg_type != SRV_UM_MSG_WAP_PUSH)
                return 0;
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_E4AC0803576E0BDA3EC5EBF5FE1065DC,
                               "PMG: Received MSG_ID_MMI_UM_GET_MSG_NUM_REQ\n"));
            PMGif_umGetMsgNumReq(PMG_MSGTYPE_SI | PMG_MSGTYPE_SL);
            return 1;
        }
        case MSG_ID_MMI_UM_GET_MSG_LIST_REQ:
        {
            srv_um_get_msg_list_req_struct *data = (srv_um_get_msg_list_req_struct*) (ilm_ptr->local_para_ptr);
			MSF_UINT32 sim_id;

            if (data->msg_type != SRV_UM_MSG_WAP_PUSH)
                return 0;
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_92848222CE62FD0EBFEA2C4A9A6DEF8F,
                               "PMG: Received MSG_ID_MMI_UM_GET_MSG_LIST_REQ\n"));

            if (data->msg_box_type != SRV_UM_MSG_BOX_INBOX)
            {
                srv_um_get_msg_list_rsp_struct *local_param =
                    (srv_um_get_msg_list_rsp_struct*)construct_local_para((kal_uint16) sizeof(srv_um_get_msg_list_rsp_struct), TD_RESET);
                    local_param->result = KAL_TRUE;
                    local_param->msg_type = SRV_UM_MSG_WAP_PUSH;
                    local_param->msg_box_type = data->msg_box_type;
                pmg_send_primitive(MOD_MMI, MSG_ID_MMI_UM_GET_MSG_LIST_RSP, (void*)local_param, (void*)0);
                return 1;
            }

#if(MMI_MAX_SIM_NUM >= 2)
			/* fill sim id attribute */

			   if(data->sim_id == SRV_UM_SIM_GSM_SIM1)
			   {
					sim_id = WAP_PMG_SIM1;
			   }
			   else if(data->sim_id == SRV_UM_SIM_GSM_SIM2)
			   {
					sim_id = WAP_PMG_SIM2;
		   	   }
 #if (MMI_MAX_SIM_NUM >= 3)
			   else if(data->sim_id == SRV_UM_SIM_GSM_SIM3)
			   {
					sim_id = WAP_PMG_SIM3;
		   	   }
			   
#endif /*MMI_MAX_SIM_NUM >= 3)*/
 #if (MMI_MAX_SIM_NUM >= 4)
			   else if(data->sim_id == SRV_UM_SIM_GSM_SIM4)
			   {
					sim_id = WAP_PMG_SIM4;
		   	   }
 #endif /*MMI_MAX_SIM_NUM >= 4)*/
			   else
			   	sim_id = WAP_PMG_SIM_ALL;
			
#else
			sim_id = WAP_PMG_SIM_DEFAULT;
#endif /*__MMI_DUAL_SIM_MASTER__*/
		

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
            PMGif_umGetListReq(PMG_MSGTYPE_SI | PMG_MSGTYPE_SL, (MSF_UINT32) data->start_entry, (MSF_UINT8) data->list_idx_type, sim_id);
#else
			PMGif_umGetListReq(PMG_MSGTYPE_SI | PMG_MSGTYPE_SL, (MSF_UINT32) data->start_entry, sim_id);

	#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
            return 1;
        }


#ifdef WPS_PMG_CONVERSATION_BOX
	case MSG_ID_MMI_UM_TRAVERSE_MSG_REQ:
	{
           int i;
		   MSF_UINT32 sim_id; 
	   srv_um_traverse_msg_req_struct	*data = (srv_um_traverse_msg_req_struct*) (ilm_ptr->local_para_ptr);
	   set_msg_id_with_num (data->msg_number, (MSF_UINT8)0);

	  

#ifdef __MMI_DUAL_SIM_MASTER__
			sim_id = WAP_PMG_SIM_ALL;
#else
			sim_id = WAP_PMG_SIM_DEFAULT;
#endif /*__MMI_DUAL_SIM_MASTER__*/

	   if (data->msg_type != SRV_UM_MSG_WAP_PUSH)
               return 0;
	   
	   MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_UM_GET_TRAVERSE_LIST,
              "PMG: Received MSG_ID_MMI_UM_TRAVERSE_MSG_REQ\n"));
	   
	   if (data->start_entry < 0)
	   {
			for (i = 0; i < data->msg_number; i++)
			{
				set_msg_id_with_num (data->msg_id[i], (MSF_UINT8)i+1);
			}
	   }
	   else
	   {
                  if (data->msg_box_type != SRV_UM_MSG_BOX_INBOX)
                  {
			srv_um_traverse_msg_rsp_struct *local_param =
						(srv_um_traverse_msg_rsp_struct*)construct_local_para((kal_uint16) sizeof(srv_um_traverse_msg_rsp_struct), TD_RESET);
			local_param->result = KAL_TRUE;
			local_param->more = KAL_FALSE;
			local_param->msg_number = 0;	/* as push message is not stored other then inbox */
			local_param->msg_type = SRV_UM_MSG_WAP_PUSH;

			pmg_send_primitive(MOD_MMI, MSG_ID_MMI_UM_TRAVERSE_MSG_RSP, (void*)local_param, (void*)0);
			return 0;
                  }
	   }

	   PMGif_umGetTraverseListReq(PMG_MSGTYPE_SI | PMG_MSGTYPE_SL, (MSF_INT16) data->start_entry, (srv_um_traverse_func) data->traverse_func, data->user_data, data->app_id, sim_id);
       return 1; 
	}
#endif /* WPS_PMG_CONVERSATION_BOX */


        case MSG_ID_MMI_UM_DELETE_FOLDER_REQ:
        {
            /* srv_um_delete_folder_req_struct *data = (srv_um_delete_folder_req_struct*)(ilm_ptr->local_para_ptr); */
            if (((srv_um_delete_folder_req_struct*) (ilm_ptr->local_para_ptr))->msg_type != SRV_UM_MSG_WAP_PUSH)
                return 0;
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_28CB05AD70701C91CBF15FF4BB43663D,
                               "PMG: Received MSG_ID_MMI_UM_DELETE_FOLDER_REQ\n"));

            if ((((srv_um_delete_folder_req_struct*)(ilm_ptr->local_para_ptr))->msg_box_type & SRV_UM_MSG_BOX_INBOX) == 0)
            {
                srv_um_delete_folder_rsp_struct *local_param =
                    (srv_um_delete_folder_rsp_struct*)construct_local_para((kal_uint16) sizeof(srv_um_delete_folder_rsp_struct), TD_RESET);
                    local_param->result = KAL_TRUE;
                    local_param->msg_type = SRV_UM_MSG_WAP_PUSH;
                pmg_send_primitive(MOD_MMI, MSG_ID_MMI_UM_DELETE_FOLDER_RSP, (void*)local_param, (void*)0);
                return 1;
            }

            PMGif_umDeleteFolderReq(PMG_MSGTYPE_SI | PMG_MSGTYPE_SL);
            return 1;
        }
        case MSG_ID_MMI_UM_DELETE_ALL_RES:
        {
            srv_um_delete_all_res_struct *local_param = (srv_um_delete_all_res_struct*)ilm_ptr->local_para_ptr;

            if (local_param->msg_type != SRV_UM_MSG_WAP_PUSH)
                return 0;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_8E6CAC8878E8235827CC949F724E5022,
                               "PMG: Received MSG_ID_MMI_UM_DELETE_ALL_RES\n"));
            ilm_ptr->local_para_ptr = 0;

            pmg_send_primitive(MOD_MMI, MSG_ID_MMI_UM_DELETE_ALL_RES, (void*)local_param, (void*)0);
            return 1;
        }
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        case MSG_ID_MMI_UM_ENTRY_MARK_SEVERAL_RSP:
        {
            srv_um_entry_mark_several_rsp_struct *local_param = (srv_um_entry_mark_several_rsp_struct*)ilm_ptr->local_para_ptr;

            if (local_param->msg_type != SRV_UM_MSG_WAP_PUSH)
                return 0;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_MMI_UM_ENTRY_MARK_SEVERAL_RSP,
                               "PMG: Received MSG_ID_MMI_UM_ENTRY_MARK_SEVERAL_RSP\n"));

            //hold_local_para(ilm_ptr->local_para_ptr);
            ilm_ptr->local_para_ptr = 0;

            pmg_send_primitive(MOD_MMI, MSG_ID_MMI_UM_ENTRY_MARK_SEVERAL_RSP, (void*)local_param, (void*)0);
            return 1;
        }
        case MSG_ID_MMI_UM_MARK_SEVERAL_OP_REQ:
        {
            srv_um_mark_several_op_req_struct *data = (srv_um_mark_several_op_req_struct*)(ilm_ptr->local_para_ptr);
            MSF_UINT8 action;
            MSF_UINT32 *msgIDs = 0;

            if (data->msg_type != SRV_UM_MSG_WAP_PUSH)
                return 0;
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_MMI_UM_MULTI_OP_REQ,
                               "PMG: Received MSG_ID_MMI_UM_MARK_SEVERAL_OP_REQ\n"));

            if ((data->msg_box_type & SRV_UM_MSG_BOX_INBOX) == 0 || data->msg_number == 0)
            {
                srv_um_mark_several_op_rsp_struct *local_param =
                    (srv_um_mark_several_op_rsp_struct*)construct_local_para((kal_uint16) sizeof(srv_um_mark_several_op_rsp_struct), TD_RESET);
                    local_param->msg_type = SRV_UM_MSG_WAP_PUSH;
                    /* local_param->app_id = default to 0 */
                    local_param->msg_box_type = data->msg_box_type;
                    local_param->action_type = data->action_type;
                    local_param->msg_number = data->msg_number;
                    memcpy(local_param->msg_id, data->msg_id, SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP*sizeof(kal_uint32));
                    /* local_param->action_result = default to 0 */
                pmg_send_primitive(MOD_MMI, MSG_ID_MMI_UM_MARK_SEVERAL_OP_RSP, (void*)local_param, (void*)0);
                return 1;
            }

            pmg_um_multi_op_action_to_pmg(1, (void*)&(data->action_type), &action);

            ASSERT(data->msg_number <= SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP);
            msgIDs = pmg_mem_alloc(data->msg_number * sizeof(MSF_UINT32));
            memcpy(msgIDs, data->msg_id, data->msg_number * sizeof(MSF_UINT32));

            PMGif_umMultiOpReq(action, (MSF_UINT32)data->msg_number, msgIDs);
            return 1;
        }
    #endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
    
        case MSG_ID_MMI_UM_GET_MSG_INFO_REQ:
        {
            srv_um_get_msg_info_req_struct *data = (srv_um_get_msg_info_req_struct*)(ilm_ptr->local_para_ptr);
            MSF_UINT32 *msgIDs = 0;

            if (data->msg_type != SRV_UM_MSG_WAP_PUSH)
                return 0;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_885C375165CF8D5CDE759CAF5411BF70, "PMG: Received MSG_ID_MMI_UM_GET_MSG_INFO_REQ\n"));
            if ((data->msg_box_type & SRV_UM_MSG_BOX_INBOX) == 0 || data->msg_number == 0)
            {
                srv_um_get_msg_info_rsp_struct *local_param =
                    (srv_um_get_msg_info_rsp_struct*)construct_local_para((kal_uint16) sizeof(srv_um_get_msg_info_rsp_struct), TD_RESET);

                /* local_param->result = default to 0 */
                local_param->msg_type = SRV_UM_MSG_WAP_PUSH;
                /* local_param->app_id = default to 0 */
                local_param->msg_box_type = data->msg_box_type;
                local_param->msg_number = data->msg_number;
                memcpy(local_param->msg_id, data->msg_id, SRV_UM_MAX_GET_MSG_INFO_NUMBER * sizeof(kal_uint32));
                /* local_param->msg_info = default to 0 */
                pmg_send_primitive(MOD_MMI, MSG_ID_MMI_UM_GET_MSG_INFO_RSP, (void*)local_param, (void*)0);
                return 1;
            }

            msgIDs = pmg_mem_alloc(data->msg_number * sizeof(MSF_UINT32));
            memcpy(msgIDs, data->msg_id, data->msg_number * sizeof(MSF_UINT32));

            PMGif_umGetMsgInfoReq(PMG_MSGTYPE_SI | PMG_MSGTYPE_SL, data->msg_number, (MSF_UINT32 *) msgIDs);
            return 1;
        }
    #endif /* __MMI_PUSH_IN_UM__ */ 
	#ifdef PHS_CFG_PUSH_SLIM_SUPPORT  
        case MSG_ID_WPS_PMG_DLG_SIA_CONFIRM_CNF:
        {
            wps_pmg_dlg_sia_confirm_cnf_struct *data = (wps_pmg_dlg_sia_confirm_cnf_struct*) (ilm_ptr->local_para_ptr);

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_AA2A1C4421D5BC1CF72BB2C9F630D65D,
                               "PMG: Received MSG_ID_WPS_PMG_DLG_SIA_CONFIRM_CNF\n"));
            PMGif_inboxDialogResponse(PMG_DLG_SIA_CONFIRM, data->trans_id, (int)data->result);
            return 1;
        }
	
        case MSG_ID_WPS_PMG_DLG_UNKNOWN_ADDR_CNF:
        {
            wps_pmg_dlg_unknown_addr_cnf_struct *data =
                (wps_pmg_dlg_unknown_addr_cnf_struct*) (ilm_ptr->local_para_ptr);
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_9E9C3269CF3F11F73A9294C53225A7E7,
                               "PMG: Received MSG_ID_WPS_PMG_DLG_UNKNOWN_ADDR_CNF\n"));
            PMGif_inboxDialogResponse(PMG_DLG_UNKNOWN_ADDR, data->trans_id, (int)data->result);
            return 1;
        }
        case MSG_ID_WPS_PMG_DLG_QUERY_REQ:
        {
            wps_pmg_dlg_query_req_struct *data =
                (wps_pmg_dlg_query_req_struct*) (ilm_ptr->local_para_ptr);
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_ENV_2EA8AA783EFBAD75027BBDC050439F29, "PMG: Received MSG_ID_WPS_PMG_DLG_QUERY_REQ\n"));
            PMGif_inboxDialogQueryReq(data->trans_id, data->dlg_trans_id);
            return 1;
        }
#endif
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_send_primitive
 * DESCRIPTION
 *  PMG send ILM routine
 * PARAMETERS
 *  destmod         [IN]        
 *  msgid           [IN]        
 *  local_param     [?]         
 *  peer_buff       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_send_primitive(module_type destmod, msg_type msgid, void *local_param, void *peer_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    sap_type sap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sap = WPS_APP_SAP;

    ilm_ptr = allocate_ilm(MOD_WPS);
    ilm_ptr->src_mod_id = MOD_WPS;
    ilm_ptr->dest_mod_id = destmod;
    ilm_ptr->sap_id = sap;
    ilm_ptr->msg_id = msgid;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff;
    msg_send_ext_queue(ilm_ptr);
}

