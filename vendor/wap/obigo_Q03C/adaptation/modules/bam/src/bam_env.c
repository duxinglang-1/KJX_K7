#ifdef OBIGO_Q03C_BROWSER
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
 *   bam_env.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements BAM module execution related function
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "msf_cfg.h"
#include "msf_act.h"
#include "msf_def.h"
#include "msf_int.h"
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_dcvt.h"
#include "msf_log.h"
#include "msf_errc.h"
#include "msf_wid.h"
#include "msf_pipe.h"
#include "msf_file.h"
#include "msf_lib.h"
#if 0
/* under construction !*/
#endif
#ifdef MSF_MODID_SES
#include "ses_if.h"
#endif
#include "brs_if.h"
#ifdef MSF_MODID_CPM
#include "cpm_if.h"
#endif

#include "bam_act.h"
#include "bam_main.h"
#include "bam_sig.h"
#include "bam_registry.h"
#include "bam_cmn.h"
#include "bam_ui.h"
#include "bam_sif.h"
#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
#include "bam_offline.h"
#endif
#include "bam_msg.h"
#include "stk_if.h"

/************************************************************
 * Macros
 ************************************************************/
#ifdef MSF_LOG_MODULE
#define BAM_ENV_LOG_IGNORE bam_env_log_ignored_signal ()
#define BAM_ENV_LOG_SIGNAL(s,p) bam_env_log_signal (s, p)

#else /* MSF_LOG_MODULE */
#define BAM_ENV_LOG_IGNORE
#define BAM_ENV_LOG_SIGNAL(s,p)

#endif /* MSF_LOG_MODULE */

/**********************************************************************
 * Function declarations
 **********************************************************************/

static void bam_receive(MSF_UINT8 srcModule, MSF_UINT16 signal, void *p);

#ifdef MSF_LOG_MODULE

static void bam_env_log_signal(MSF_UINT16 signal, void *p);

static void bam_env_log_ignored_signal(void);

#endif /* MSF_LOG_MODULE */

/**********************************************************************
 * Function definitions
 **********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  BAMc_start
 * DESCRIPTION
 *  This function will be called before when the module is about to started.
 *  Put your initialization code here.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BAMc_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_FC_BEGIN(BAMc_start)
        MSF_LOG_FC_PRE_IMPL
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_LOW, MSF_MODID_BAM, BAM_ENV_5BA582536204327F8AC9608956E9830A,
                           "BAM: BAMc_start\n"));

    bam_init();
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_LOW, MSF_MODID_BAM, BAM_ENV_1FBBF9C3573267798400F38273883876,
                       "BAM: Initialized\n"));

    MSF_LOG_FC_END
}


/*****************************************************************************
 * FUNCTION
 *  BAMc_wantsToRun
 * DESCRIPTION
 *  This function is to check if the module needs to be executed before BAMc_run is called.
 *  Usually returns TRUE if the signal queue is not empty. Or internal context needs to be processed.
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
int BAMc_wantsToRun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MSF_SIGNAL_QUEUE_LENGTH(MSF_MODID_BAM) > 0 || bam_wants_to_run || bam_signal_queue_is_empty() != TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  BAMc_run
 * DESCRIPTION
 *  This function is called to perform the execution of BAM module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BAMc_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Make a setjmp, so the module can jump back to this point
       if the memory runs out. */
    if (setjmp(bam_jmpbuf) == 0)
    {
        /* Set the global variable, the module is now inside the Run function. */
        bam_inside_run = TRUE;

        /* Get external signals and process one internal signal. */
        while (MSF_SIGNAL_RETRIEVE(MSF_MODID_BAM, bam_receive))
        {
        }

        bam_signal_process();

        bam_inside_run = FALSE;
        bam_wants_to_run = FALSE;
    }
    else
    {
        /*
         * A longjmp from bam_exception_handler. If we are here there is no more
         * * memory, and the situation could not be worse.
         * * Send out an error and terminate.
         */
        MSF_ERROR(MSF_MODID_BAM, MSF_ERR_MODULE_OUT_OF_MEMORY);
        MSF_PIPE_CLOSE_ALL(MSF_MODID_BAM);
        MSF_FILE_CLOSE_ALL(MSF_MODID_BAM);
        MSF_WIDGET_RELEASE_ALL(MSF_MODID_BAM);
        MSF_MEM_FREE_ALL(MSF_MODID_BAM);
        MSF_MODULE_IS_TERMINATED(MSF_MODID_BAM);
        MSF_SIGNAL_DEREGISTER_QUEUE(MSF_MODID_BAM);
        MSF_KILL_TASK(MSF_MODID_BAM);
    }
}


/*****************************************************************************
 * FUNCTION
 *  BAMc_kill
 * DESCRIPTION
 *  This function is called when MSF environment wants to terminate this module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BAMc_kill(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_PIPE_CLOSE_ALL(MSF_MODID_BAM);
    MSF_FILE_CLOSE_ALL(MSF_MODID_BAM);
    MSF_WIDGET_RELEASE_ALL(MSF_MODID_BAM);
    MSF_MEM_FREE_ALL(MSF_MODID_BAM);
    MSF_KILL_TASK(MSF_MODID_BAM);
}


/*****************************************************************************
 * FUNCTION
 *  bam_receive
 * DESCRIPTION
 *  This function will be called to process one signal retrieved from internal signal queue.
 *  You may also resend the signal to the internal queue maintained in the module and process
 *  it in bam_process. (NOTE: The signal needs to be destructed after it is processed.
 *  If it is processed later on, It will then be the receivers responsibility to destruct
 *  the signal.)
 * PARAMETERS
 *  src_module          [IN]
 *  signal              [IN]
 *  p                   [?]         [?]
 *  srcModule(?)        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void bam_receive(MSF_UINT8 src_module, MSF_UINT16 signal, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if 0   /* Disable the usage of MSF_ACT */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UNREFERENCED_PARAMETER(src_module);

    BAM_ENV_LOG_SIGNAL(signal, p);

/**********************************************
 * UI package
 **********************************************/
#if 0   /* Disable the usage of UI Package */
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
#endif /* 0 */

/**********************************************
 * Act package
 **********************************************/
#if 0   /* Disable the usage of MSF_ACT */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

    switch (signal)
    {
        /************************************************************
         * Signals received from MSF Manager or from the Integration
         ************************************************************/
        case MSF_SIG_MODULE_TERMINATE:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_ENV_B14F70CBDC3342E07B2A053C6CA93FC7,
                               "BAM: Received MSF_SIG_MODULE_TERMINATE\n"));
            BAM_SIGNAL_SENDTO_U(BAM_SIG_DEST_MAIN, BAM_MAIN_SIG_TERMINATE, ((msf_module_terminate_t*) p)->modId);
            break;

        case MSF_SIG_MODULE_STATUS:
            BAM_SIGNAL_SENDTO_IU(
                BAM_SIG_DEST_MAIN,
                BAM_MAIN_SIG_STATUS,
                ((msf_module_status_t*) p)->status,
                ((msf_module_status_t*) p)->modId);
            break;

        case MSF_SIG_WIDGET_ACCESS_KEY:
            BAM_SIGNAL_SENDTO_P(BAM_SIG_DEST_MAIN, BAM_MAIN_SIG_WIDGET_ACCESS_KEY, p);
            return; /* Signal not destructed here */


        case MSF_SIG_MODULE_EXECUTE_COMMAND:
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            {
                msf_module_execute_cmd_t *q = (msf_module_execute_cmd_t *)p;

                if(q)
                        {
                                MSF_MEM_FREE(MSF_MODID_BAM, q->commandOptions);
                                msf_content_data_free(MSF_MODID_BAM, q->contentData);
                                                       
                        }
            }

            break;


        case MSF_SIG_FILE_NOTIFY:
            BAM_SIGNAL_SENDTO_IU(
                BAM_SIG_DEST_MAIN,
                BAM_MAIN_SIG_FILE_NOTIFY,
                ((msf_file_notify_t*) p)->fileHandle,
                ((msf_file_notify_t*) p)->eventType);
            break;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        /* 
         * There is no any module other than BAM has chance to update registry. 
         * Therefore, BAM has no chance to receive response signal to inform 
         * registry is updated by other module. 
         */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        /**********************************************
         * BAM Signals
         **********************************************/

        /*
         * Useless!
         * case BAM_SIG_CREATE_INSTANCE_REQ:
         * break;
         */

        case BAM_SIG_DELETE_INSTANCE_REQ:
            bam_delete_instance_req_hdlr((bam_delete_instance_req_struct*) p);
            break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        case BAM_SIG_LOAD_URL_REQ:
            bam_load_url_req_hdlr((bam_load_url_req_struct*) p);
			BAM_FREE(((bam_load_url_req_struct*) p)->url);
            break;

        case BAM_SIG_LOAD_DATA_REQ:
            bam_load_data_req_hdlr((bam_load_data_req_struct*) p);
			BAM_FREE(((bam_load_data_req_struct*) p)->content_path);
            break;

#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
        case BAM_SIG_ACTIVATE_DO_ELEMENT_REQ:
            bam_activate_do_element_req_hdlr((bam_activate_do_element_req_struct*) p);
            break;
#endif

        case BAM_SIG_MOVE_REQ:
            bam_move_req_hdlr((bam_move_req_struct*) p);
            break;

        case BAM_SIG_RELOAD_REQ:
            bam_reload_req_hdlr((bam_reload_req_struct*) p);
            break;

        case BAM_SIG_STOP_REQ:
            bam_stop_req_hdlr((bam_stop_req_struct*) p);
            break;

        case BAM_SIG_NAVIGATION_CHANGE_REQ:
            bam_navigation_change_req_hdlr((bam_navigation_change_req_struct*) p);
            break;

#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
        case BAM_SIG_SAVE_PAGE_REQ:
            bam_save_page_req_hdlr((bam_save_page_req_struct*) p);

			BAM_FREE(((bam_save_page_req_struct*)p)->url);
            break;

        case BAM_SIG_GET_SAVED_PAGE_REQ:
            bam_get_saved_page_req_hdlr((bam_get_saved_page_req_struct*) p);
            break;

        case BAM_SIG_LOAD_SAVED_PAGE_REQ:
            bam_load_saved_page_req_hdlr((bam_load_saved_page_req_struct*) p);
            break;

        case BAM_SIG_DELETE_SAVED_PAGE_REQ:
            bam_delete_saved_page_req_hdlr((bam_delete_saved_page_req_struct*) p);
            break;

        case BAM_SIG_DELETE_N_SAVED_PAGE_REQ:
            bam_delete_n_saved_page_req_hdlr((bam_delete_n_saved_page_req_struct*) p);
            BAM_FREE(((bam_delete_n_saved_page_req_struct*) p)->index_array);
            break;

        case BAM_SIG_DELETE_ALL_SAVED_PAGES_REQ:
            bam_delete_all_saved_pages_req_hdlr((bam_delete_all_saved_pages_req_struct*) p);
            break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        case BAM_SIG_GET_SAVED_PAGES_LIST_START_REQ:
            bam_get_saved_pages_list_start_req_hdlr((bam_get_saved_pages_list_start_req_struct*) p);
            break;

        case BAM_SIG_GET_SAVED_PAGES_LIST_CONTINUE_REQ:
            bam_get_saved_pages_list_continue_req_hdlr((bam_get_saved_pages_list_continue_req_struct*) p);
            break;

        case BAM_SIG_GET_SAVED_PAGES_LIST_END_REQ:
            bam_get_saved_pages_list_end_req_hdlr((bam_get_saved_pages_list_end_req_struct*) p);
            break;
#endif

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        /*
         * Useless!
         * case BAM_SIG_NAVIGATE_TO_HOTSPOT_REQ:
         * bam_navigate_to_hotspot_req_hdlr((bam_navigate_to_hotspot_req_struct *) p);
         * break;
         */
//#ifdef MSF_CFG_9W_MODE_KBRD_SIMULATION
        case BAM_SIG_CHANGE_SETTING_VALUE_REQ:
            bam_change_setting_value_req_hdlr((bam_change_setting_value_req_struct*) p);
            break;
//#endif

        case BAM_SIG_SET_PROFILE_REQ:
            bam_set_profile_req_hdlr((bam_set_profile_req_struct*) p);
            return; /* Signal not destructed here */
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
        case BAM_SIG_GET_RECENT_PAGES_LIST_START_REQ:
            bam_get_recent_pages_list_start_req_hdlr((bam_get_recent_pages_list_start_req_struct*) p);
            break;

        case BAM_SIG_GET_RECENT_PAGES_LIST_CONTINUE_REQ:
            bam_get_recent_pages_list_continue_req_hdlr((bam_get_recent_pages_list_continue_req_struct*) p);
            break;

        case BAM_SIG_GET_RECENT_PAGES_LIST_END_REQ:
            bam_get_recent_pages_list_end_req_hdlr((bam_get_recent_pages_list_end_req_struct*) p);
            break;

        case BAM_SIG_GET_RECENT_PAGE_REQ:
            bam_get_recent_page_req_hdlr((bam_get_recent_page_req_struct*) p);
            break;

        case BAM_SIG_LOAD_RECENT_PAGE_REQ:
            bam_load_recent_page_req_hdlr((bam_load_recent_page_req_struct*) p);
            break;

        case BAM_SIG_DELETE_RECENT_PAGE_REQ:
            bam_delete_recent_page_req_hdlr((bam_delete_recent_page_req_struct*) p);
            break;

        case BAM_SIG_DELETE_N_RECENT_PAGE_REQ:
            bam_delete_n_recent_page_req_hdlr((bam_delete_n_recent_page_req_struct*) p);
			BAM_FREE(((bam_delete_n_recent_page_req_struct*) p)->index_array);
            break;

        case BAM_SIG_DELETE_ALL_RECENT_PAGES_REQ:
            bam_delete_all_recent_pages_req_hdlr((bam_delete_all_recent_pages_req_struct*) p);
            break;
#endif /* recent pages */
        case BAM_SIG_REGISTER_KEYPAD_HANDLER_REQ:
            bam_register_keypad_handler_req_hdlr((bam_register_keypad_handler_req_struct*) p);
            break;

#ifdef __MMI_TOUCH_SCREEN__
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        case BAM_SIG_NOTIFY_SCREEN_INFO_REQ:
            bam_notify_screen_info_req_hdlr((bam_notify_screen_info_req_struct*) p);
            break;

#ifdef MSF_CFG_FILE_UPLOAD_SUPPORT
        case BAM_SIG_SELECT_FILE_RSP:
            bam_select_file_rsp_hdlr((bam_select_file_rsp_struct*) p);
			BAM_FREE(((bam_select_file_rsp_struct*) p)->filename);
            break;
#endif

/*        case BAM_SIG_WTAI_TEL_RSP:
            bam_wtai_tel_rsp_hdlr((bam_wtai_tel_rsp_struct*) p);
            break;

        case BAM_SIG_WTAI_PB_RSP:
            bam_wtai_pb_rsp_hdlr((bam_wtai_pb_rsp_struct*) p);
            break;
*/
        case BAM_SIG_URI_REQUEST_RSP:
            bam_uri_request_rsp_hdlr((bam_uri_request_rsp_struct*) p);
            break;

		case BAM_SIG_WAIT_USER_ACTION_IND:
            bam_wait_user_action_ind_hdlr((bam_wait_user_action_ind_struct*) p);
            break;

        case BAM_SIG_WAIT_USER_ACTION_RSP:
            bam_wait_user_action_rsp_hdlr((bam_wait_user_action_rsp_struct*) p);
            break;

        case BAM_SIG_OBJECT_ACTION_REQ:
            bam_object_action_req_hdlr((bam_object_action_req_struct*) p);
            break;

        case BAM_SIG_SHOW_AUTH_DIALOG_RSP:
            bam_show_auth_dialog_rsp_hdlr((bam_show_auth_dialog_rsp_struct*) p);
            BAM_FREE(((bam_show_auth_dialog_rsp_struct*) p)->username);
            BAM_FREE(((bam_show_auth_dialog_rsp_struct*) p)->password);
            break;

	
#ifdef MSF_CFG_BRW_WMLS_NON_WIDGET_DLG_SUPPORT
        case BAM_SIG_WMLS_CREATE_DIALOGUE_RSP:
			bam_wmls_create_dialogue_rsp_hdlr((bam_wmls_create_dialogue_rsp_struct*) p);
			break;
#endif


        /**********************************************
         * BRS Signals
         **********************************************/
        case BRS_SIG_CREATED:
            BAM_SIGNAL_SENDTO_P(BAM_SIG_DEST_MAIN, BAM_MAIN_SIG_BRS_CREATE_RESPONSE, p);
            return; /* Signal not destructed here */

        /*case BRS_SIG_INSTANCE_DELETED:
            BAM_SIGNAL_SENDTO_I(
                BAM_SIG_DEST_MAIN,
                BAM_MAIN_SIG_BRS_INSTANCE_DELETED,
                ((brs_instance_deleted_t*) p)->instanceId);
            break;*/

        case BRS_SIG_STATUS:
            BAM_SIGNAL_SENDTO_P(BAM_SIG_DEST_MAIN, BAM_MAIN_SIG_BRS_STATUS, p);
            return; /* Signal not destructed here */

        case BRS_SIG_ERROR:
            MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM,
                        BAM_SIF_STATUS_SIG_ERROR, "BAM: Received BRS_SIG_ERROR id = %i, error = %i\n",((brs_error_t *)p)->instanceId, ((brs_error_t *)p)->errorCode));
            BAM_SIGNAL_SENDTO_P(BAM_SIG_DEST_MAIN, BAM_MAIN_SIG_BRS_ERROR, p);
            return; /* Signal not destructed here */

        case BRS_SIG_DOCUMENT_INFO:
            {
            //MsfDeviceProperties prop;
            BAM_SIGNAL_SENDTO_P(BAM_SIG_DEST_MAIN, BAM_MAIN_SIG_BRS_DOCUMENT_INFO, p);
            // MSF_WIDGET_SET_IN_FOCUS(bam_sif_get_brs_paintbox(), 1);
            //bam_win_enable_focus();
            
            }
            return; /* Signal not destructed here */

#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
        case BRS_SIG_DO_ELEMENTS:
            BAM_SIGNAL_SENDTO_P(BAM_SIG_DEST_MAIN, BAM_MAIN_SIG_BRS_DO_ELEMENTS, p);
            return; /* Signal not destructed here */
#endif

        case BRS_SIG_ELEMENT_FOCUSED:
            BAM_SIGNAL_SENDTO_P(BAM_SIG_DEST_MAIN, BAM_MAIN_SIG_BRS_ELEMENT_FOCUSED, p);
            return; /* Signal not destructed here */

//        case BRS_SIG_RESOURCE_LIST_RESPONSE:
 //           BAM_SIGNAL_SENDTO_P(BAM_SIG_DEST_MAIN, BAM_MAIN_SIG_BRS_RESOURCE_LIST_RESPONSE, p);
 //           return; /* Signal not destructed here */

 //       case BRS_SIG_SET_TITLE_STRING:
  //          BAM_SIGNAL_SENDTO_P(BAM_SIG_DEST_MAIN, BAM_MAIN_SIG_BRS_SET_TITLE_STRING, p);
  //          return; /* Signal not destructed here */
    
    #ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
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
#else
        case BRS_SIG_PAGE_NOT_FOUND_OFFLINE:
            bam_offline_page_not_found (p);
            break;
        case BAM_SIG_DELETE_OFFLINE_PAGE_RESPONSE:
            bam_offline_handle_delete_response();
			BAM_FREE(((bam_delete_offline_page_rsp_struct*) p)->url);
            break;
#endif

    #endif /* MSF_CFG_OFFLINE_PAGES_SUPPORT */

        case BAM_SIG_EM_SETTING_CHANGED_IND:
            bam_registry_handle_em_setting_changed_ind(p);
            break;
        case BAM_SIG_CHANNEL_CONFIG_NOTIFY_IND:
            bam_registry_handle_channel_config_notify();
            break;
        case BAM_SIG_CLOSE_CONNECTION_BY_NETID:
            bam_main_close_connection_by_netid(p);
            break;
	/**********************************************
 	 * Security
	 **********************************************/
	#ifdef MSF_MODID_SES
		case SES_SIG_GET_CURRENT_SEC_CLASS_RESPONSE:
			BAM_SIGNAL_SENDTO_P (BAM_SIG_DEST_MAIN, BAM_MAIN_SIG_SES_SEC_CLASS, p);
			return; /* Signal not destructed here */
	#endif
	
	#ifdef MSF_MODID_CPS
        case CPM_SIG_SET_PROFILE_REPLY:
            BAM_SIGNAL_SENDTO_U(
                BAM_SIG_DEST_MAIN,
                BAM_MAIN_SIG_CPM_SET_PROFILE_REPLY,
                ((cpm_set_profile_reply_t*) p)->result);
            break;  /* Signal not destructed here */
	#endif /* MSF_MODID_CPS */
        case STK_SIG_CONN_CLOSED_BY_NET_ACC_ID:
            //bam_msg_error_ind(bam_sif_get_brs_id(), BAM_ERROR_LONG_IDLE_TIMEOUT);
            bam_msg_conn_closed_by_net_acc_id_rsp();
            break;
		case BAM_SIG_BEARER_OPEN_RSP:
			
			bam_sif_bearer_open_rsp_hdl ((bam_bearer_open_rsp_struct*)p);

        default:
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_ENV_7B5CCF43A89FFB69B95AFA38D894FE44,
                              "BAM: Received unknown signal (%04x)\n", signal));
            break;
    }

	BAM_FREE(p);
    //MSF_SIGNAL_DESTRUCT(MSF_MODID_BAM, signal, p);
}

/* ------------------------------------------------------------------------- */

#ifdef MSF_LOG_MODULE


/*****************************************************************************
 * FUNCTION
 *  bam_env_log_signal
 * DESCRIPTION
 *
 * PARAMETERS
 *  signal      [IN]
 *  p           [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void bam_env_log_signal(MSF_UINT16 signal, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *sig_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (signal)
    {
        /************************************************************
         * Signals received from the Application using BAM:
         ************************************************************/

        /**********************************************
         * BRS Signals
         **********************************************/
        case BRS_SIG_STATUS:
            sig_name = "BRS_SIG_STATUS";
            break;

        default:
            sig_name = "Unknown";
            break;
    }

	switch (signal)
    {
        /************************************************************
         * Signals received from MSF Manager or from the Integration
         ************************************************************/
        case MSF_SIG_MODULE_TERMINATE:
            sig_name = "MSF_SIG_MODULE_TERMINATE";
            break;

        case MSF_SIG_MODULE_STATUS:
            sig_name = "MSF_SIG_MODULE_STATUS";
            break;

        case MSF_SIG_WIDGET_ACCESS_KEY:
            sig_name = "MSF_SIG_WIDGET_ACCESS_KEY";
            break;

        case MSF_SIG_MODULE_EXECUTE_COMMAND:
            sig_name = "MSF_SIG_MODULE_EXECUTE_COMMAND";
            break;

        case MSF_SIG_FILE_NOTIFY:
            sig_name = "MSF_SIG_FILE_NOTIFY";
            break;

        case MSF_SIG_PIPE_NOTIFY:
            sig_name = "MSF_SIG_PIPE_NOTIFY";
            break;

        case MSF_SIG_REG_RESPONSE:
            sig_name = "MSF_SIG_REG_RESPONSE";
            break;

//        case MSF_SIG_EVNT_SYSTEM_EVENT:
 //           sig_name = "MSF_SIG_EVNT_SYSTEM_EVENT";
 //           break;

        /**********************************************
         * BAM Signals
         **********************************************/

        /*
         * Useless!
         * case BAM_SIG_CREATE_INSTANCE_REQ:
         * break;
         */

        case BAM_SIG_DELETE_INSTANCE_REQ:
            sig_name = "BAM_SIG_DELETE_INSTANCE_REQ";
            break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        case BAM_SIG_LOAD_URL_REQ:
            sig_name = "BAM_SIG_LOAD_URL_REQ";
            break;

        case BAM_SIG_LOAD_DATA_REQ:
            sig_name = "BAM_SIG_LOAD_DATA_REQ";
            break;

#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
        case BAM_SIG_ACTIVATE_DO_ELEMENT_REQ:
            sig_name = "BAM_SIG_ACTIVATE_DO_ELEMENT_REQ";
            break;
#endif

        case BAM_SIG_MOVE_REQ:
            sig_name = "BAM_SIG_MOVE_REQ";
            break;

        case BAM_SIG_RELOAD_REQ:
            sig_name = "BAM_SIG_RELOAD_REQ";
            break;

        case BAM_SIG_STOP_REQ:
            sig_name = "BAM_SIG_STOP_REQ";
            break;

        case BAM_SIG_NAVIGATION_CHANGE_REQ:
            sig_name = "BAM_SIG_NAVIGATION_CHANGE_REQ";
            break;

#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
        case BAM_SIG_SAVE_PAGE_REQ:
            sig_name = "BAM_SIG_SAVE_PAGE_REQ";
            break;

        case BAM_SIG_GET_SAVED_PAGE_REQ:
            sig_name = "BAM_SIG_GET_SAVED_PAGE_REQ";
            break;

        case BAM_SIG_LOAD_SAVED_PAGE_REQ:
            sig_name = "BAM_SIG_LOAD_SAVED_PAGE_REQ";
            break;

        case BAM_SIG_DELETE_SAVED_PAGE_REQ:
            sig_name = "BAM_SIG_DELETE_SAVED_PAGE_REQ";
            break;

        case BAM_SIG_DELETE_N_SAVED_PAGE_REQ:
            sig_name = "BAM_SIG_DELETE_N_SAVED_PAGE_REQ";
            break;

        case BAM_SIG_DELETE_ALL_SAVED_PAGES_REQ:
            sig_name = "BAM_SIG_DELETE_ALL_SAVED_PAGES_REQ";
            break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        case BAM_SIG_GET_SAVED_PAGES_LIST_START_REQ:
            sig_name = "BAM_SIG_GET_SAVED_PAGES_LIST_START_REQ";
            break;

        case BAM_SIG_GET_SAVED_PAGES_LIST_CONTINUE_REQ:
            sig_name = "BAM_SIG_GET_SAVED_PAGES_LIST_CONTINUE_REQ";
            break;

        case BAM_SIG_GET_SAVED_PAGES_LIST_END_REQ:
            sig_name = "BAM_SIG_GET_SAVED_PAGES_LIST_END_REQ";
            break;
#endif
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
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        case BAM_SIG_SET_PROFILE_REQ:
            sig_name = "BAM_SIG_SET_PROFILE_REQ";
            break;
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
        case BAM_SIG_GET_RECENT_PAGES_LIST_START_REQ:
            sig_name = "BAM_SIG_GET_RECENT_PAGES_LIST_START_REQ";
            break;

        case BAM_SIG_GET_RECENT_PAGES_LIST_CONTINUE_REQ:
            sig_name = "BAM_SIG_GET_RECENT_PAGES_LIST_CONTINUE_REQ";
            break;

        case BAM_SIG_GET_RECENT_PAGES_LIST_END_REQ:
            sig_name = "BAM_SIG_GET_RECENT_PAGES_LIST_END_REQ";
            break;

        case BAM_SIG_GET_RECENT_PAGE_REQ:
            sig_name = "BAM_SIG_GET_RECENT_PAGE_REQ";
            break;

        case BAM_SIG_LOAD_RECENT_PAGE_REQ:
            sig_name = "BAM_SIG_LOAD_RECENT_PAGE_REQ";
            break;

        case BAM_SIG_DELETE_RECENT_PAGE_REQ:
            sig_name = "BAM_SIG_DELETE_RECENT_PAGE_REQ";
            break;

        case BAM_SIG_DELETE_N_RECENT_PAGE_REQ:
            sig_name = "BAM_SIG_DELETE_N_RECENT_PAGE_REQ";
            break;

        case BAM_SIG_DELETE_ALL_RECENT_PAGES_REQ:
            sig_name = "BAM_SIG_DELETE_ALL_RECENT_PAGES_REQ";
            break;
#endif 
        case BAM_SIG_REGISTER_KEYPAD_HANDLER_REQ:
            sig_name = "BAM_SIG_REGISTER_KEYPAD_HANDLER_REQ";
            break;

#ifdef __MMI_TOUCH_SCREEN__
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        case BAM_SIG_NOTIFY_SCREEN_INFO_REQ:
            sig_name = "BAM_SIG_NOTIFY_SCREEN_INFO_REQ";
            break;

#ifdef MSF_CFG_FILE_UPLOAD_SUPPORT
        case BAM_SIG_SELECT_FILE_RSP:
            sig_name = "BAM_SIG_SELECT_FILE_RSP";
            break;
#endif
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
        case BAM_SIG_WTAI_TEL_RSP:
            sig_name = "BAM_SIG_WTAI_TEL_RSP";
            break;

        case BAM_SIG_WTAI_PB_RSP:
            sig_name = "BAM_SIG_WTAI_PB_RSP";
            break;
#endif

        case BAM_SIG_URI_REQUEST_RSP:
            sig_name = "BAM_SIG_URI_REQUEST_RSP";
            break;

        case BAM_SIG_WAIT_USER_ACTION_IND:
            sig_name = "BAM_SIG_WAIT_USER_ACTION_IND";
            break;

        case BAM_SIG_WAIT_USER_ACTION_RSP:
            sig_name = "BAM_SIG_WAIT_USER_ACTION_RSP";
            break;

        case BAM_SIG_OBJECT_ACTION_REQ:
            sig_name = "BAM_SIG_OBJECT_ACTION_REQ";
            break;

        case BAM_SIG_SHOW_AUTH_DIALOG_RSP:
            sig_name = "BAM_SIG_SHOW_AUTH_DIALOG_RSP";
            break;

        /**********************************************
         * BRS Signals
         **********************************************/
        case BRS_SIG_CREATED:
            sig_name = "BRS_SIG_CREATED";
            break;

/*        case BRS_SIG_INSTANCE_DELETED:
            sig_name = "BRS_SIG_INSTANCE_DELETED";
            break;*/

        case BRS_SIG_STATUS:
            sig_name = "BRS_SIG_STATUS";
            break;

        case BRS_SIG_ERROR:
            sig_name = "BRS_SIG_ERROR";
            break;

        case BRS_SIG_DOCUMENT_INFO:
            sig_name = "BRS_SIG_DOCUMENT_INFO";
            break;

#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
        case BRS_SIG_DO_ELEMENTS:
            sig_name = "BRS_SIG_DO_ELEMENTS";
            break;
#endif

        case BRS_SIG_ELEMENT_FOCUSED:
            sig_name = "BRS_SIG_ELEMENT_FOCUSED";
            break;

//        case BRS_SIG_RESOURCE_LIST_RESPONSE:
  //          sig_name = "BRS_SIG_RESOURCE_LIST_RESPONSE";
  //          break;

    #ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT

 /*       case BRS_SIG_SAVE_PAGE_RESPONSE:
            sig_name = "BRS_SIG_SAVE_PAGE_RESPONSE";
            break;

        case BRS_SIG_SAVED_PAGES:
            sig_name = "BRS_SIG_SAVED_PAGES";
            break;

        case BRS_SIG_SAVED_RESOURCE:
            sig_name = "BRS_SIG_SAVED_RESOURCE";
            break;
*/
    #endif /* MSF_CFG_OFFLINE_PAGES_SUPPORT */

	/**********************************************
 	 * Security
	 **********************************************/
	#ifdef MSF_MODID_SES
		case SES_SIG_GET_CURRENT_SEC_CLASS_RESPONSE:
			sig_name = "SES_SIG_GET_CURRENT_SEC_CLASS_RESPONSE";
            break;
	#endif
	
	#ifdef MSF_MODID_CPS
        case CPM_SIG_SET_PROFILE_REPLY:
            sig_name = "CPM_SIG_SET_PROFILE_REPLY";
            break;
	#endif /* MSF_MODID_CPS */

/*        case MSF_SIG_CONTENT_IS_REGISTERED_RESP:
            sig_name = "MSF_SIG_CONTENT_IS_REGISTERED_RESP";
            break;*/
		case BAM_SIG_BEARER_OPEN_RSP:
			sig_name= "BAM_SIG_BEARER_OPEN_RSP";
			break;

        default:
            sig_name = "Unknown";
            break;
    }

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_ENV_1F43D0CC9C3491F6AEF38F0B03393A90,
                      "BAM: Received signal: %s.\n", sig_name));
}


/*****************************************************************************
 * FUNCTION
 *  bam_env_log_ignored_signal
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bam_env_log_ignored_signal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_ENV_EDDE09B7FED2E0E81F233E11FD740EAD,
                       "BAM: Previous signal was deliberately not handled.\n"));
}


#endif /* MSF_LOG_MODULE */


#endif /*OBIGO_Q03C_BROWSER*/
