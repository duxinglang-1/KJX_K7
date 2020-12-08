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
 *   bam_main.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contain Browser Adaptation Module main functionality.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*
 * bam_main.c
 *
 * Description:
 *   This file contain Browser Adaptation Module main functionality.
 *
 */
#include "msf_cfg.h"
#include "msf_act.h"
#include "msf_def.h"
#include "msf_errc.h"
#include "msf_int.h"
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_pipe.h"
#include "msf_dcvt.h"
#include "msf_log.h"
#include "msf_file.h"
#include "msf_lib.h"
#include "msf_hdr.h"
#include "msf_url.h"
#include "msf_wid.h"
#include "msf_tel.h"

#ifdef MSF_MODID_SES
#include "ses_if.h"
#endif
#include "stk_if.h"
#include "brs_if.h"
#ifdef MSF_MODID_CPM
#include "cpm_if.h"
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#include "bam_main.h"
#include "bam_cmn.h"
#include "bam_do_elem.h"
#include "bam_file.h"
#include "bam_hist.h"
#include "bam_if.h"
#include "bam_lib.h"
#include "bam_msg.h"
#include "bam_struct.h"

#include "widget.h"

#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
#include "bam_offline.h"

#endif /* MSF_CFG_OFFLINE_PAGES_SUPPORT */

#if 0
/* under construction !*/
#endif
#include "bam_req.h"
#include "bam_registry.h"
#include "bam_resource.h"
#include "bam_sif.h"
#include "bam_sig.h"
#include "bam_shortcuts.h"
#include "bam_view.h"
#include "bam_viewopt.h"
#include "bam_ui.h"
#include "bam_win.h"

#if 0
/* under construction !*/
#endif

//#include "brs_select_file_dlg.h"
#include "msf_dlg.h"

/******************************************************************************
 * Local Defines
 ******************************************************************************/

/******************************************************************************
 * Global variables
 ******************************************************************************/
mtk_jmpbuf bam_jmpbuf;
int bam_inside_run;
int bam_wants_to_run;

MSF_BOOL bam_main_terminating;
MSF_BOOL bam_app_request_to_create_brs = FALSE;
MSF_BOOL bam_app_request_to_delete_brs = FALSE;
static MSF_UINT8 bam_main_terminate_mode;
static MSF_UINT32 bam_module_state;
static MSF_UINT32 bam_main_sub_module_state;
static MSF_INT16 bam_instance_id = 0;
#if defined(BAM_CFG_PAGE_FETCHING_STATUS_SUPPORT) || defined(MSF_CFG_FILE_UPLOAD_SUPPORT)
static MSF_BOOL bam_main_received_transaction_status = FALSE;
#endif
static MSF_BOOL bam_main_activate_browser_input_status = FALSE;
#ifdef MSF_CFG_9W_MODE_KBRD_SIMULATION
static MSF_BOOL bam_main_nine_way_navigation_mode_status = TRUE;
#endif

/******************************************************************************
 * Function definitions
 *****************************************************************************/
static void bam_terminate(MSF_UINT8 mode);
static void bam_main_terminate_delayed(void);
static void bam_main_continue_terminate(void);
static void bam_module_status(bam_signal_struct *sig);
static void bam_main_start(void);
static void bam_main_start_reg_done(void);

static void bam_main_system_event_init(void);
static void bam_main_system_event_terminate(void);
//static void bam_main_handle_system_event(msf_evnt_system_event_sig_t *p);
//static void bam_main_handle_bearer_state(MsfEvntStateType state);


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
    #if defined(__WAP_VDS_MODULE__) && defined(MSF_MODID_VDS)
/* under construction !*/
/* under construction !*/
    #endif /* __WAP_VDS_MODULE__ && MSF_MODID_VDS */
    #if defined(__WAP_SVS_MODULE__) && defined(MSF_MODID_SVS)
/* under construction !*/
    #endif /* __WAP_SVS_MODULE__ && MSF_MODID_SVS */
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
		#if defined(__WAP_VDS_MODULE__) && defined(MSF_MODID_VDS)
/* under construction !*/
		#endif /* __WAP_VDS_MODULE__ && MSF_MODID_VDS */
		#if defined(__WAP_SVS_MODULE__) && defined(MSF_MODID_SVS)
/* under construction !*/
		#endif /* __WAP_SVS_MODULE__ && MSF_MODID_SVS */
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
#if defined(__WAP_VDS_MODULE__) && defined(MSF_MODID_VDS)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#if defined(__WAP_SVS_MODULE__) && defined(MSF_MODID_SVS)
/* under construction !*/
		#endif /* __WAP_SVS_MODULE__ && MSF_MODID_SVS */			
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __WAP_VDS_MODULE__ && MSF_MODID_VDS */
/* under construction !*/
#if defined(__WAP_SVS_MODULE__) && defined(MSF_MODID_SVS)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#if defined(__WAP_VDS_MODULE__) && defined(MSF_MODID_VDS)
/* under construction !*/
        #endif /* __WAP_VDS_MODULE__ && MSF_MODID_VDS */
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
#endif /* __WAP_SVS_MODULE__ && MSF_MODID_SVS */
#endif

/*****************************************************************************
 * FUNCTION
 *  bam_module_status
 * DESCRIPTION
 *  When a module previously started by BAM is active it returns a.
 *  signal. This function handles such notifications.
 * PARAMETERS
 *  sig     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void bam_module_status(bam_signal_struct *sig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT8 src_module;
    MSF_UINT8 status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = (MSF_UINT8) sig->i_param1;
    src_module = (MSF_UINT8) sig->u_param1;

    switch (src_module)
    {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        case MSF_MODID_BRS:
            /* Browser Service Module */
            bam_sif_module_status(status);
            break;

    #if defined(__WAP_VDS_MODULE__) && defined(MSF_MODID_VDS)
        case MSF_MODID_VDS:
            bam_vds_module_status(status);
            break;
    #endif /* __WAP_VDS_MODULE__ && MSF_MODID_VDS */
    #if defined(__WAP_SVS_MODULE__) && defined(MSF_MODID_SVS)
        case MSF_MODID_SVS:
            bam_svs_module_status(status);
            break;
    #endif /* __WAP_SVS_MODULE__ && MSF_MODID_SVS */
        default:
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MAIN_3BAE630FAC91887881DD8B9CE5F00B18,
                             "BAM: ERROR: Source module not handled in switch. (function: bam_module_status)\n"));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_main_continue_terminate
 * DESCRIPTION
 *  This function continues to terminates the BAM.
 *  It frees all allocated memory and terminates the internal
 *  signal queue. Before returning the macro MSF_MODULE_IS_TERMINATED
 *  is called to notify MSF that the BAM is terminated.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bam_main_continue_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If sub module status is BAM_MAIN_SUB_STATE_NULL termination is completed. */
    if (bam_main_sub_module_state == BAM_MAIN_SUB_STATE_NULL)
    {
        /* BAM is no longer active */

        /* Release the screen, ...RELEASE_ALL() below can not handle this one if screen is given to BRS */
        MSF_WIDGET_RELEASE(bam_win_get_screen());
        /* Remove all widgets */
        MSF_WIDGET_RELEASE_ALL(MSF_MODID_BAM);

#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
        bam_hist_terminate();
#endif
#if 0
/* under construction !*/
#endif
        /* remove signal queue */
        MSF_SIGNAL_DEREGISTER_QUEUE(MSF_MODID_BAM);
        bam_signal_terminate();

        MSF_MEM_FREE_ALL(MSF_MODID_BAM);
        MSF_MODULE_IS_TERMINATED(MSF_MODID_BAM);
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_LOW, MSF_MODID_BAM, BAM_MAIN_521E56FB652E5B975C2183D7177152C1,
                           "BAM: Terminated\n"));

        MSF_KILL_TASK(MSF_MODID_BAM);

        bam_main_terminating = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_main
 * DESCRIPTION
 *  This is the main function is in the BAM. It receives all internal signals and
 *  dispatches them to the correct function.
 * PARAMETERS
 *  sig     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void bam_main(bam_signal_struct *sig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sig->type)
    {
        case BAM_MAIN_SIG_START_INITIALIZATION:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MAIN_0BDE31FC2241C9BB0936544904CC23F1,
                             "BAM: received signal BAM_MAIN_SIG_START_INITIALIZATION\n"));
            bam_main_start();
            /* delete sig later */
            break;

        case BAM_MAIN_SIG_TERMINATE:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MAIN_B42472BF70E452408A4328682687343E,
                             "BAM: received signal BAM_MAIN_SIG_TERMINATE\n"));
            bam_terminate((MSF_UINT8) (sig->u_param1));
            /* delete sig later */
            break;

        case BAM_MAIN_SIG_CONTINUE_TERMINATE:
            /* Delete this signal first, since bam_main_continue_terminate might
               terminate the internal signal queue. */
            bam_signal_delete(sig);

            bam_main_continue_terminate();
            return; /* Function needs to return here, otherwise sig will be deleted twice. */

        case BAM_MAIN_SIG_STATUS:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MAIN_646A22172CB5708B00FD4513152BAE2F,
                             "BAM: received signal BAM_MAIN_SIG_STATUS\n"));
            bam_module_status(sig);
            /* delete sig later */
            break;

        case BAM_MAIN_SIG_WIDGET_ACCESS_KEY:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MAIN_914DA79F18DBB672E390CF4EC29E0AD4,
                             "BAM: received signal BAM_MAIN_SIG_WIDGET_ACCESS_KEY\n"));
#if 0
    #ifdef BAM_CFG_SHORTCUTS_ENABLED
/* under construction !*/
    #endif
#endif
            //MSF_SIGNAL_DESTRUCT(MSF_MODID_BAM, MSF_SIG_WIDGET_ACCESS_KEY, sig->p_param);
	BAM_FREE(sig->p_param);
            /* delete sig later */
            break;

        case BAM_MAIN_SIG_FILE_NOTIFY:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MAIN_FB6C50BE8756CB707E4FCAF0609D4FF1,
                             "BAM: received signal BAM_MAIN_SIG_FILE_NOTIFY\n"));
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
            bam_file_execute_file_task();
#endif 
            /* delete sig later */
            break;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        case BAM_MAIN_SIG_BRS_CREATE_RESPONSE:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MAIN_8522E2D4D055A0FB489E6EFBA398EC72,
                             "BAM: received signal BAM_MAIN_SIG_BRS_CREATE_RESPONSE\n"));
            bam_sif_brs_instance_created((brs_created_t*) sig->p_param);
           // MSF_SIGNAL_DESTRUCT(MSF_MODID_BAM, BRS_SIG_CREATED, sig->p_param);
			BAM_FREE(sig->p_param);
            /* delete sig later */
            break;

        case BAM_MAIN_SIG_BRS_INSTANCE_DELETED:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MAIN_924C7FBB781D9CF08002FD9C04CE0D32,
                             "BAM: received signal BAM_MAIN_SIG_BRS_INSTANCE_DELETED\n"));
            bam_sif_brs_instance_deleted((MSF_INT16) sig->i_param1);
           // MSF_SIGNAL_DESTRUCT(MSF_MODID_BAM, BRS_SIG_INSTANCE_DELETED, sig->p_param);
            /* delete sig later */
            break;
#if 0
    #ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* MSF_CFG_OFFLINE_PAGES_SUPPORT */
#endif
        case BAM_MAIN_SIG_BRS_STATUS:
            bam_sif_handle_brs_status(sig->p_param);
            //MSF_SIGNAL_DESTRUCT(MSF_MODID_BAM, BRS_SIG_STATUS, sig->p_param);
            BAM_FREE(((brs_status_t*)(sig->p_param))->url); 	
	    BAM_FREE(sig->p_param);
            /* delete sig later */
            break;

        case BAM_MAIN_SIG_BRS_ERROR:
            bam_sif_handle_brs_error(
                ((brs_error_t*) (sig->p_param))->instanceId,
                ((brs_error_t*) (sig->p_param))->errorCode);
            //MSF_SIGNAL_DESTRUCT(MSF_MODID_BAM, BRS_SIG_ERROR, sig->p_param);
			BAM_FREE(sig->p_param);
            /* delete sig later */
            break;

        case BAM_MAIN_SIG_BRS_DOCUMENT_INFO:
            bam_sif_handle_brs_doc_info(((brs_document_info_t*) (sig->p_param)));
            /* Do not destruct here */
            /* delete sig later */
            break;

#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
        case BAM_MAIN_SIG_BRS_DO_ELEMENTS:
            bam_do_elem_add(sig->p_param);
            /* Do not destruct here */
            /* delete sig later */
            break;
#endif /* BAM_CFG_BRW_DISPLAY_INLINE_DO */

        case BAM_MAIN_SIG_BRS_ELEMENT_FOCUSED:
            bam_sif_element_focused(sig->p_param);
            /* Do not destruct here */
            /* delete sig later */
            break;

        case BAM_MAIN_SIG_BRS_RESOURCE_LIST_RESPONSE:
            //bam_resource_get_rsrc_list_response(sig->p_param);
            //MSF_SIGNAL_DESTRUCT(MSF_MODID_BAM, BRS_SIG_RESOURCE_LIST_RESPONSE, sig->p_param);
            /* delete sig later */
            break;

  //      case BAM_MAIN_SIG_BRS_SET_TITLE_STRING:
   //         bam_sif_handle_brs_set_title_string(sig->p_param);
   //         MSF_SIGNAL_DESTRUCT(MSF_MODID_BAM, BRS_SIG_SET_TITLE_STRING, sig->p_param);
   //         /* delete sig later */
     //       break;

#ifdef WAP_SEC_SUPPORT
	#ifdef MSF_MODID_SES
		case BAM_MAIN_SIG_SES_SEC_CLASS:
			bam_sif_set_security_class (((ses_get_current_sec_class_response_t*)(sig->p_param))->sec_class);
			//MSF_SIGNAL_DESTRUCT (MSF_MODID_BAM, SES_SIG_GET_CURRENT_SEC_CLASS_RESPONSE, sig->p_param);
			BAM_FREE(sig->p_param);
			break;
	#endif /* MSF_MODID_SES */
#endif /* WAP_SEC_SUPPORT */

		case BAM_MAIN_SIG_CONT_FILE_TASK:
			MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM,
						 BAM_MAIN_DC83094613605C08FE6E69ADE1C09710, "BAM: received signal BAM_MAIN_SIG_CONT_FILE_TASK\n"));
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
			bam_file_execute_file_task();
#endif
			/* delete sig later */
			break;

        case BAM_MAIN_SIG_EVNT_SYSTEM_EVENT:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MAIN_2E409517C7549AE52C8161C79CDF249C,
                               "BAM_MAIN: received signal BAM_MAIN_SIG_EVNT_SYSTEM_EVENT\n"));
            //bam_main_handle_system_event(sig->p_param);
//            MSF_SIGNAL_DESTRUCT(MSF_MODID_BAM, MSF_SIG_EVNT_SYSTEM_EVENT, sig->p_param);
            /* delete sig later */
            break;

    #ifdef MSF_MODID_CPS
        case BAM_MAIN_SIG_CPM_SET_PROFILE_REPLY:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MAIN_04D5C261FA7BAA7C3A63D25AF238E43A,
                               "BAM_MAIN: received signal BAM_MAIN_SIG_CPM_SET_PROFILE_REPLY\n"));
            bam_registry_process_pending_profile((MSF_UINT8) sig->i_param1);
            //MSF_SIGNAL_DESTRUCT(MSF_MODID_BAM, MSF_SIG_EVNT_SYSTEM_EVENT, sig->p_param);
            BAM_FREE(sig->p_param);
            /* delete sig later */
            break;
    #endif /* MSF_MODID_CPS */
        case BAM_MAIN_SIG_HIST_SAVE_TO_FILE:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MAIN_F21A6E4944C3DE4ECB922D15F0CFCDB1,
                               "BAM_MAIN: received signal BAM_MAIN_SIG_HIST_SAVE_TO_FILE\n"));
#if 0
/* under construction !*/
#endif
			/* delete sig later */
            break;

            /************************************************************
             * Internal signals of package notification:
             ************************************************************/
    #if 0   /* Disable the usage of MSF_ACT */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */

        default:
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MAIN_5FADA0B7941B0CFAC4A170A5F5A92000,
                             "BAM main: received unknown signal: %d\n", sig->type));
    }

	bam_signal_delete(sig);
}


/*****************************************************************************
 * FUNCTION
 *  bam_exception_handler
 * DESCRIPTION
 *  This function is called when the module is running out of memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bam_exception_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If inside the bam_run function make longjmp, else do nothing, which will result in that the
       memory allocation macro return NULL; */
    if (bam_inside_run)
    {
        longjmp(bam_jmpbuf, 1);
    }
}

/******************************************************************************
 * Exported Functions
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  bam_main_set_module_state
 * DESCRIPTION
 *  Function sets the state of BAM to stat. This function is
 *  used during startup and termination. The state is typically
 *  used when reading the registry. This is a delayed operation
 *  and therefore we need to remember the state so the initialization
 *  routine is aware that it can't return MODULE_ACTIVE.
 * PARAMETERS
 *  state       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_main_set_module_state(MSF_UINT32 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_module_state |= state;
}


/*****************************************************************************
 * FUNCTION
 *  bam_main_remove_module_state
 * DESCRIPTION
 *  Function removes the previously set state of BAM to stat.
 *  used during startup and termination.
 * PARAMETERS
 *  state       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_main_remove_module_state(MSF_UINT32 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_module_state &= ~state;

    if (state == BAM_INIT_REGISTRY)
    {
        bam_main_start_reg_done();
    }
}

/*****************************************************************************
 * FUNCTION
 *  bam_main_profile_init_done
 * DESCRIPTION
 *  Function removes the previously set state of BAM_INIT_PROFILE
 *  and calls bam_init_done to set bam module ready.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_main_profile_init_done(void)
{
    if(bam_module_state & BAM_INIT_PROFILE)
    {
        bam_main_remove_module_state(BAM_INIT_PROFILE);
        bam_init_done();
    }
}

/* 
 * There is no any module other than BAM has chance to update registry. BAM has 
 * no chance to receive/process response signal to inform registry is updated 
 * by other module. 
 */

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

/*****************************************************************************
 * FUNCTION
 *  bam_init_done
 * DESCRIPTION
 *  This function is called to try if BAM has finished the initialization process.
 *  If the module is finished it starts parsing the command line if available.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_init_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_module_state == BAM_INIT_PROFILE)
    {
        bam_msg_ready_ind();
    }
    else if (bam_module_state == BAM_NULL_STATE)
    {
        /* tells MSF that the module is active. If the module will use other
           modules, this call must wait until these are up and running. */
        MSF_MODULE_IS_ACTIVE(MSF_MODID_BAM);

        bam_main_set_module_state(BAM_INITIALIZED);

        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_LOW, MSF_MODID_BAM, BAM_MAIN_125D70D89601662E7C65EE7B17B81279,
                           "BAM: Initialization is done!\n"));
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_init
 * DESCRIPTION
 *  Initialize BAM modules
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_LOW, MSF_MODID_BAM, BAM_MAIN_52706FAB6E8EA207CBBEBF790B4E7A6D,
                       "BAM: Initialization Starts!\n"));

    /* Initialize memory management */
    MSF_MEM_INIT(MSF_MODID_BAM, bam_exception_handler/*, FALSE*/);

    /* Register conversion and destruction functions, skip this if no external signal is defined. */
 //   MSF_SIGNAL_REG_FUNCTIONS(MSF_MODID_BAM, bam_convert, bam_destruct);

    /* Register external signal queue */
    MSF_SIGNAL_REGISTER_QUEUE(MSF_MODID_BAM);

    /* Notify MSF that the module is created. Note! The module is created but not active */
    MSF_MODULE_IS_CREATED(MSF_MODID_BAM, "BAM 0.1");

    /* Make sure that the BAM file directory exist */
    MSF_FILE_MKDIR("/bam");
    
#ifdef MSF_MODID_CPM
    CPMif_startInterface();
#endif

    /* Initialize global variables */
    bam_inside_run = FALSE;
    bam_module_state = BAM_INITIALIZING;

    bam_main_sub_module_state = BAM_MAIN_SUB_STATE_NULL;
    bam_main_terminating = FALSE;
	bam_app_request_to_create_brs = FALSE;
	bam_app_request_to_delete_brs = FALSE;
    bam_instance_id = 0;
    bam_wants_to_run = FALSE;

    /* 
     * BAM does not need to subscribe or get the registry updates becuase other 
     * modules have no chance to update registry. In addition, in the current 
     * implementation, BAM will do nothing after receving response of registry 
     * updates.
     */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /*
     * NOTE: The following initiation functions should NOT allocate memory.
     * If they do they must check the result of the allocations, since
     * exception handling is not active (bam_inside_run == 0).
     */

    bam_signal_init();
    /* register the destination for the signals sent to this module */
    bam_signal_register_dst(BAM_SIG_DEST_MAIN, bam_main);

    bam_sif_init();

#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
    bam_file_start();
#endif  
    bam_req_init_request_url();

#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
    bam_hist_init();
#endif

#if 0
#ifdef BAM_CFG_SHORTCUTS_ENABLED
/* under construction !*/
#endif
#endif

    /* Start module */
    BAM_SIGNAL_SENDTO(BAM_SIG_DEST_MAIN, BAM_MAIN_SIG_START_INITIALIZATION);
}


/*****************************************************************************
 * FUNCTION
 *  bam_main_start
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bam_main_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_registry_init();
    bam_main_system_event_init();
}


/*****************************************************************************
 * FUNCTION
 *  bam_main_start_reg_done
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bam_main_start_reg_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Call functions utilizing registry */
    bam_main_remove_module_state(BAM_INITIALIZING);
    bam_init_done();
}


/*****************************************************************************
 * FUNCTION
 *  bam_main_terminate
 * DESCRIPTION
 *  This function terminates the Browser Adaptation module.
 *  All resources are freed including the termination of all modules started by
 *  the Browser Adaptation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_main_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 //   MSF_MODULE_IS_SHUTTING_DOWN(MSF_MODID_BAM);
//    BAM_SIGNAL_SENDTO_U(BAM_SIG_DEST_MAIN, BAM_MAIN_SIG_TERMINATE, MSF_MOD_SHUTDOWN_ALLOW_UI);
}


/*****************************************************************************
 * FUNCTION
 *  bam_terminate
 * DESCRIPTION
 *  This function is the start of the termination routine.
 * PARAMETERS
 *  mode        [IN]
 *  MSF_UINT8(?)
 * RETURNS
 *  void
 *****************************************************************************/
void bam_terminate(MSF_UINT8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!bam_main_terminating)
    {

        /* Set the status variable to indicate that we are terminating the BAM */
        bam_main_terminating = TRUE;
        bam_main_terminate_mode = mode;
#if defined(BAM_CFG_PAGE_FETCHING_STATUS_SUPPORT) || defined(MSF_CFG_FILE_UPLOAD_SUPPORT)
        bam_main_received_transaction_status = FALSE;
#endif
        bam_main_activate_browser_input_status = FALSE;
#ifdef MSF_CFG_9W_MODE_KBRD_SIMULATION
        bam_main_nine_way_navigation_mode_status = TRUE;
#endif
        /*
         * Call the termination functions that can NOT be delayed.
         */
        bam_sif_terminate();
        bam_req_clear_pending_req_url();
        bam_main_system_event_terminate();
        bam_registry_terminate();

        /* Continue by terminating functions that can be delayed. */
        bam_main_terminate_delayed();
    }
    else if (mode > bam_main_terminate_mode)
    {
        bam_main_terminate_mode = mode;
        /* Send termination signals to all modules with this new mode. */
        bam_main_terminate_delayed();
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_main_terminate_delayed
 * DESCRIPTION
 *  Calls the termination functions that are affected by the termination mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bam_main_terminate_delayed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_sif_brs_terminate(bam_main_terminate_mode); /* MSF_MOD_SHUTDOWN_ALLOW_UI ? */

#ifdef MSF_MODID_DLS
    /* bam_sif_dls_terminate (bam_main_terminate_mode); */
#endif
#ifdef MSF_MODID_SES
    /* bam_sif_ses_terminate (bam_main_terminate_mode); */
#endif
    /* bam_sif_stk_terminate (bam_main_terminate_mode); */

    BAM_SIGNAL_SENDTO(BAM_SIG_DEST_MAIN, BAM_MAIN_SIG_CONTINUE_TERMINATE);
}


/*****************************************************************************
 * FUNCTION
 *  bam_process
 * DESCRIPTION
 *  This function is called immediately after signal queue is processed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  bam_main_set_sub_module_state
 * DESCRIPTION
 *  Set sub-module state.
 * PARAMETERS
 *  state       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_main_set_sub_module_state(MSF_UINT32 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_main_sub_module_state |= state;
}


/*****************************************************************************
 * FUNCTION
 *  bam_main_remove_sub_module_state
 * DESCRIPTION
 *  Remove sub-module state.
 * PARAMETERS
 *  state       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_main_remove_sub_module_state(MSF_UINT32 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_main_sub_module_state &= ~state;
    if (bam_main_terminating)
    {
        BAM_SIGNAL_SENDTO(BAM_SIG_DEST_MAIN, BAM_MAIN_SIG_CONTINUE_TERMINATE);
    }
}

/*****************************
 * Event handling
 *****************************/


/*****************************************************************************
 * FUNCTION
 *  bam_main_system_event_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bam_main_system_event_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    MSF_EVNT_SUBSCRIBE(MSF_MODID_BAM, BAM_MAIN_REQID_SYSTEM_EVENT_1, MSF_EVNT_DISPLAY1_RESIZED);
}


/*****************************************************************************
 * FUNCTION
 *  bam_main_system_event_terminate
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bam_main_system_event_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    MSF_EVNT_UNSUBSCRIBE(MSF_MODID_BAM, BAM_MAIN_REQID_SYSTEM_EVENT_1, MSF_EVNT_DISPLAY1_RESIZED);
}

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*****************************
 * Content routing
 *****************************/


/*****************************************************************************
 * FUNCTION
 *  bam_content_routing_request
 * DESCRIPTION
 *
 * PARAMETERS
 *  content                 [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_content_routing_request(msf_content_data_t *content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if 1
#if 0
/* under construction !*/
/* under construction !*/
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_CONTENT_SEND(
        MSF_MODID_BAM,
        MSF_MODID_MSM,
        NULL,
        content,
        FALSE,
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
        bam_cmn_new_handle());
#endif
    
    if (content != NULL)
    {
/*        BAM_FREE(content->contentData);
        BAM_FREE(content->contentHeaders);
        BAM_FREE(content->contentParameters);*/
        BAM_FREE(content->contentSource);
#if 0
/* under construction !*/
/* under construction !*/
#endif
        BAM_FREE(content->contentUrl);
        BAM_FREE(content->routingIdentifier);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/*        if (content->contentDRMDataExists == TRUE)
        {
            BAM_FREE(content->contentDRMData->drmData);
            BAM_FREE(content->contentDRMData->drmContentHeaders);
            BAM_FREE(content->contentDRMData);
        }*/
#endif
    }
#else
/* under construction !*/
#endif
}

/*****************************
 * BAM Signal handling
 *****************************/


/*****************************************************************************
 * FUNCTION
 *  bam_delete_instance_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  delete_instance_req     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_delete_instance_req_hdlr(bam_delete_instance_req_struct *delete_instance_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef WAP_DECODE_USE_ASM_POOL
        extern void stk_dcmp_terminate();
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!bam_instance_id)
    {
#ifdef WAP_DECODE_USE_ASM_POOL
        stk_dcmp_terminate();
#endif /*WAP_DECODE_USE_ASM_POOL*/
        /* Need to send confirmation so that app can perform reset activity after wap reset */
        bam_msg_delete_instance_cnf(1 /* Currently there is only one BRS instance */ );
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_LOW, MSF_MODID_BAM, BAM_MAIN_SENT_DELETE_INSTANCE_CONF_AFTER_WAP_RESET,
                           "BAM: sent delete instance conf after wap reset\n"));
        return;
    }
	if (bam_app_request_to_delete_brs == TRUE || bam_app_request_to_create_brs == TRUE)
	{
		/* 
		 * Error handling: BAM will do nothing in below cases.
		 * (1) BAM receives MSG_ID_WAP_BAM_DELETE_INSTANCE_REQ more than once 
		 *     before BAM responds MSG_ID_WAP_BAM_DELETE_INSTANCE_CNF.
		 * (2) BAM receives MSG_ID_WAP_BAM_DELETE_INSTANCE_REQ during creating
		 *     BRS instance.
		 */
		return;
	}
	
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__WAP_VDS_MODULE__) && defined(MSF_MODID_VDS)
/* under construction !*/
#endif /* __WAP_VDS_MODULE__ && MSF_MODID_VDS */
#if defined(__WAP_SVS_MODULE__) && defined(MSF_MODID_SVS)
/* under construction !*/
#endif /* __WAP_SVS_MODULE__ && MSF_MODID_SVS */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__WAP_VDS_MODULE__) && defined(MSF_MODID_VDS)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __WAP_VDS_MODULE__ && MSF_MODID_VDS */
#if defined(__WAP_SVS_MODULE__) && defined(MSF_MODID_SVS)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __WAP_SVS_MODULE__ && MSF_MODID_SVS */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#else
    if (bam_sif_get_brs_status() == BAM_SIF_BRS_READY)
#endif
	{
        bam_app_request_to_delete_brs = TRUE;
		bam_sif_brs_terminate(0);
	}
    else
    {
        bam_msg_delete_instance_cnf(1 /* Currently there is only one BRS instance */ );
    }
#ifdef WAP_DECODE_USE_ASM_POOL
    stk_dcmp_terminate();
#endif /*WAP_DECODE_USE_ASM_POOL*/
#if defined(BAM_CFG_PAGE_FETCHING_STATUS_SUPPORT) || defined(MSF_CFG_FILE_UPLOAD_SUPPORT)
    bam_main_received_transaction_status = FALSE;
#endif
    bam_main_activate_browser_input_status = FALSE;
    bam_main_delete_instance();
}

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  bam_load_url_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  load_url_req        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_load_url_req_hdlr(bam_load_url_req_struct *load_url_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (load_url_req->instance_id == bam_main_get_instance_id())
    {
#if 0
/* under construction !*/
#endif
        bam_send_request(load_url_req->url/*, load_url_req->charset, load_url_req->options*/);
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_load_data_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  load_data_req       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_load_data_req_hdlr(bam_load_data_req_struct *load_data_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (load_data_req->instance_id == bam_main_get_instance_id())
    {
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
    #endif /* 0 */
#if 0
/* under construction !*/
#endif
        bam_send_request(load_data_req->content_path/*, load_data_req->charset, load_data_req->options*/);
    }
}


#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
/*****************************************************************************
 * FUNCTION
 *  bam_activate_do_element_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  activate_do_element_req     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_activate_do_element_req_hdlr(bam_activate_do_element_req_struct *activate_do_element_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (activate_do_element_req->instance_id == bam_main_get_instance_id())
    {
        bam_do_elem_activate(activate_do_element_req->element_id);
    }
}
#endif /* BAM_CFG_BRW_DISPLAY_INLINE_DO */


/*****************************************************************************
 * FUNCTION
 *  bam_move_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  move_req        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_move_req_hdlr(bam_move_req_struct *move_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (move_req->instance_id == bam_main_get_instance_id())
    {
        switch (move_req->direction)
        {
            case BAM_MOVE_BACKWARD:
                bam_sif_navigate(BAM_SIF_NAV_BACKWARD);
                break;
            case BAM_MOVE_FORWARD:
                bam_sif_navigate(BAM_SIF_NAV_FORWARD);
                break;
            default:
                /* BAM_MOVE_RELOAD */
                bam_sif_navigate(BAM_SIF_NAV_REFRESH);
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_reload_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  reload_req      [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_reload_req_hdlr(bam_reload_req_struct *reload_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (reload_req->instance_id == bam_main_get_instance_id())
    {
        bam_sif_navigate(BAM_SIF_NAV_REFRESH);
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_stop_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  stop_req        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_stop_req_hdlr(bam_stop_req_struct *stop_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (stop_req->instance_id == bam_main_get_instance_id())
    {
        bam_req_stop();
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_navigation_change_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  navigation_change_req       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_navigation_change_req_hdlr(bam_navigation_change_req_struct *navigation_change_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (navigation_change_req->instance_id == bam_main_get_instance_id())
    {
        bam_sif_enable_select_mode(navigation_change_req->elements);
    }
}


#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  bam_save_page_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  save_page_req       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_save_page_req_hdlr(bam_save_page_req_struct *save_page_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_offline_save(save_page_req->label, save_page_req->url, save_page_req->overwrite);
}


/*****************************************************************************
 * FUNCTION
 *  bam_get_saved_page_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  get_saved_page_req      [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_get_saved_page_req_hdlr(bam_get_saved_page_req_struct *get_saved_page_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_offline_handle_get_saved_page_req(get_saved_page_req->index);
}


/*****************************************************************************
 * FUNCTION
 *  bam_load_saved_page_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  load_saved_page_req     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_load_saved_page_req_hdlr(bam_load_saved_page_req_struct *load_saved_page_req)
{
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
#else
    bam_offline_load_selected_ofln(load_saved_page_req->index, BAM_OFFLINE_STATE_LOAD_REQUEST);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  bam_delete_saved_page_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  delete_saved_page_req       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_delete_saved_page_req_hdlr(bam_delete_saved_page_req_struct *delete_saved_page_req)
{
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
#else
    bam_offline_delete(delete_saved_page_req->index);
#endif
}


void bam_delete_n_saved_page_req_hdlr(bam_delete_n_saved_page_req_struct *delete_n_saved_page_req)
{
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
#else
    bam_offline_delete_pending_page(delete_n_saved_page_req);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  bam_delete_all_saved_pages_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  delete_all_saved_pages_req      [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_delete_all_saved_pages_req_hdlr(bam_delete_all_saved_pages_req_struct *delete_all_saved_pages_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_offline_delete_all();
}


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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  bam_get_saved_pages_list_start_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  get_saved_pages_list_start_req      [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_get_saved_pages_list_start_req_hdlr(bam_get_saved_pages_list_start_req_struct *get_saved_pages_list_start_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    bam_offline_init();
    bam_msg_get_saved_pages_list_start_cnf(WAP_BAM_ERROR_OK, bam_offline_get_num_saved_pages());
#endif
}


/*****************************************************************************
 * FUNCTION
 *  bam_get_saved_pages_list_continue_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  get_saved_pages_list_continue_req       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_get_saved_pages_list_continue_req_hdlr(
        bam_get_saved_pages_list_continue_req_struct *get_saved_pages_list_continue_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (get_saved_pages_list_continue_req->instance_id == bam_main_get_instance_id())
    {
        peer_buff_struct *peer_buff = construct_peer_buff(BAM_MAX_PEER_BUFFER_SIZE, 0, 0, TD_CTRL);

        if (peer_buff)
        {
            kal_uint16 pdu_len;
            void *item_buff = get_pdu_ptr(peer_buff, &pdu_len);
            int packed_items;
            MSF_UINT16 error_code = (MSF_UINT16) bam_offline_pack_list_item_from_index(
                                                    item_buff,
                                                    BAM_MAX_PEER_BUFFER_SIZE,
                                                    get_saved_pages_list_continue_req->start_index,
                                                    &packed_items);

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
#endif
            bam_msg_get_saved_pages_list_continue_cnf(
                error_code,
                get_saved_pages_list_continue_req->start_index,
                packed_items,
                peer_buff);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_get_saved_pages_list_end_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  get_saved_pages_list_end_req        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_get_saved_pages_list_end_req_hdlr(bam_get_saved_pages_list_end_req_struct *get_saved_pages_list_end_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#else
    bam_offline_destroy();
#endif
}
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
#ifdef __BAIDU_TRANSCODING_SUPPORT__
extern void bam_registry_change_transcode_proxy_value(int i);
#endif
//#ifdef MSF_CFG_9W_MODE_KBRD_SIMULATION
/*****************************************************************************
 * FUNCTION
 *  bam_change_setting_value_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  change_setting_value_req        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_change_setting_value_req_hdlr(bam_change_setting_value_req_struct *change_setting_value_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (change_setting_value_req->instance_id == bam_main_get_instance_id())
    {
#ifdef MSF_CFG_9W_MODE_KBRD_SIMULATION
        if (change_setting_value_req->setting_id == BAM_SETTING_ID_9WAY)
        {
            if (change_setting_value_req->value_i)
                bam_main_set_nine_way_navigation_mode_status(TRUE);
            else
                bam_main_set_nine_way_navigation_mode_status(FALSE);
        }
#endif
        if (change_setting_value_req->setting_id == BAM_SETTING_ID_IMAGES)
		{
            bam_registry_enable_object_setting(change_setting_value_req->value_i, "image/*");
		}

#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
        if (change_setting_value_req->setting_id == BAM_SETTING_ID_ADD_HISTORY)
		{
            bam_sif_set_add_to_history_setting(change_setting_value_req->value_i);

		}
#endif
#ifdef __BAIDU_TRANSCODING_SUPPORT__
		if (change_setting_value_req->setting_id == BAM_SETTING_ID_TRANSCODE_PROXY)
		{
            bam_registry_change_transcode_proxy_value(change_setting_value_req->value_i);
		}
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
#endif
    }
}
//#endif


/*****************************************************************************
 * FUNCTION
 *  bam_set_profile_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  set_profile_req     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_set_profile_req_hdlr(bam_set_profile_req_struct *set_profile_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_registry_set_profile(
        (MSF_UINT8) set_profile_req->setting_id,
		(bam_set_profile_option_enum)set_profile_req->type,
        (MSF_INT32*) set_profile_req->int_value_table,
        set_profile_req->str_value_table,
        set_profile_req);
}

#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  bam_get_recent_pages_list_start_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  get_recent_pages_list_start_req     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_get_recent_pages_list_start_req_hdlr(
        bam_get_recent_pages_list_start_req_struct *get_recent_pages_list_start_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
#else
    if (get_recent_pages_list_start_req->instance_id == bam_main_get_instance_id())
    {
        bam_msg_get_recent_pages_list_start_cnf(BAM_ERROR_OK, (MSF_INT16) bam_hist_ui_get_sel_list_size());
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  bam_get_recent_pages_list_continue_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  get_recent_pages_list_continue_req      [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_get_recent_pages_list_continue_req_hdlr(
        bam_get_recent_pages_list_continue_req_struct *get_recent_pages_list_continue_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (get_recent_pages_list_continue_req->instance_id == bam_main_get_instance_id())
    {
        peer_buff_struct *peer_buff = construct_peer_buff(BAM_MAX_PEER_BUFFER_SIZE, 0, 0, TD_CTRL);

        if (peer_buff)
        {
            kal_uint16 pdu_len;
            void *item_buff = get_pdu_ptr(peer_buff, &pdu_len);
            int packed_items;
            MSF_UINT16 error_code = (MSF_UINT16) bam_hist_ui_pack_list_item_from_index(
                                                    item_buff,
                                                    BAM_MAX_PEER_BUFFER_SIZE,
                                                    get_recent_pages_list_continue_req->start_index,
                                                    &packed_items);

            switch (error_code)
            {
                case BAM_HIST_ERROR_OK:
                    error_code = BAM_ERROR_OK;
                    break;
                case BAM_HIST_ERROR_NOT_FOUND:
                    error_code = BAM_ERROR_RECENT_PAGES_NOT_FOUND;
                    break;
                default:
                    error_code = BAM_ERROR_RECENT_PAGES_FAILED;
            }
            bam_msg_get_recent_pages_list_continue_cnf(
                error_code,
                get_recent_pages_list_continue_req->start_index,
                packed_items,
                peer_buff);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_get_recent_pages_list_end_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  get_recent_pages_list_end_req       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_get_recent_pages_list_end_req_hdlr(bam_get_recent_pages_list_end_req_struct *get_recent_pages_list_end_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
//    bam_hist_terminate();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  bam_get_recent_page_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  get_recent_page_req     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_get_recent_page_req_hdlr(bam_get_recent_page_req_struct *get_recent_page_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (get_recent_page_req->instance_id == bam_main_get_instance_id())
    {
        bam_hist_ui_handle_get_recent_page_req(get_recent_page_req->index);
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_load_recent_page_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  load_recent_page_req        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_load_recent_page_req_hdlr(bam_load_recent_page_req_struct *load_recent_page_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (load_recent_page_req->instance_id == bam_main_get_instance_id())
    {
        bam_hist_ui_handle_load_recent_page_req(load_recent_page_req->index);
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_delete_recent_page_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  delete_recent_page_req      [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_delete_recent_page_req_hdlr(bam_delete_recent_page_req_struct *delete_recent_page_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (delete_recent_page_req->instance_id == bam_main_get_instance_id())
    {
        bam_hist_ui_handle_delete_recent_page_req(delete_recent_page_req->index);
    }
}

/*****************************************************************************
 * FUNCTION
 *  bam_delete_n_recent_page_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  delete_recent_page_req      [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_delete_n_recent_page_req_hdlr(bam_delete_n_recent_page_req_struct *delete_n_recent_page_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (delete_n_recent_page_req->instance_id == bam_main_get_instance_id())
    {   
        bam_hist_ui_handle_delete_n_recent_page_req(delete_n_recent_page_req->index_array, delete_n_recent_page_req->count); 
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_delete_all_recent_pages_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  delete_all_recent_pages_req     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_delete_all_recent_pages_req_hdlr(bam_delete_all_recent_pages_req_struct *delete_all_recent_pages_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (delete_all_recent_pages_req->instance_id == bam_main_get_instance_id())
    {
        bam_hist_ui_handle_delete_all_recent_page_req();
    }
}

#endif /* recent pages */
/*****************************************************************************
 * FUNCTION
 *  bam_register_keypad_handler_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  register_keypad_handler_req     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_register_keypad_handler_req_hdlr(bam_register_keypad_handler_req_struct *register_keypad_handler_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Make OWL register suitable keypad events and event handlers. */
    if (bam_main_get_instance_id() == (MSF_INT16) register_keypad_handler_req->instance_id)
    {
        
        widget_paintboxV2_register_keys();
    }
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  bam_handle_pen_event_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  handle_pen_event_req        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_handle_pen_event_req_hdlr(bam_handle_pen_event_req_struct *handle_pen_event_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Make OWL handle the given keypad event. */
    if (bam_main_get_instance_id() == (MSF_INT16) handle_pen_event_req->instance_id)
    {
        mmi_pen_point_struct pos;

        pos.x = handle_pen_event_req->pos_x;
        pos.y = handle_pen_event_req->pos_y;
       widget_paintboxV2_pen_handler(pos, handle_pen_event_req->type);
		
    }
}
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
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  bam_notify_screen_info_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  notify_screen_info_req      [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_notify_screen_info_req_hdlr(bam_notify_screen_info_req_struct *notify_screen_info_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Notify OWL of the current category screen information, including layer
       handle used and what area to draw. */
    if (bam_main_get_instance_id() == (MSF_INT16) notify_screen_info_req->instance_id)
    {
        HDIa_widgetDeviceSetProperties(
            notify_screen_info_req->x,
            notify_screen_info_req->y,
            notify_screen_info_req->w,
            notify_screen_info_req->h,
            notify_screen_info_req->category_lyr_a_hndl,
            notify_screen_info_req->category_lyr_b_hndl);
    }
}

#ifdef MSF_CFG_FILE_UPLOAD_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  bam_select_file_rsp_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  select_file_rsp     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_select_file_rsp_hdlr(bam_select_file_rsp_struct *select_file_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (select_file_rsp->error_code != WAP_BAM_ERROR_FILE_SELECTION_OK || 
		select_file_rsp->filename == NULL || select_file_rsp->filename[0] == '\0')
	{
		brs_dlg_select_file_rsp(select_file_rsp->instance_id, select_file_rsp->request_id, FALSE, NULL);
	}
	else
	{
		char *native_filename;
		MSF_UINT16 i, len;
		
		native_filename = msf_cmmn_strcat(MSF_MODID_BAM, "/external/", select_file_rsp->filename);

		len = strlen(native_filename);
		
		for (i = 0; i < len; i++)
		{
			if (native_filename[i] == '\\')
			{
				native_filename[i] = '/';
			}
		}

		brs_dlg_select_file_rsp(select_file_rsp->instance_id, select_file_rsp->request_id, TRUE, native_filename);

		MSF_MEM_FREE(MSF_MODID_BAM, native_filename);
	}
}
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



static MSF_INT32 bam_uri_agent_get_result(MSF_UINT16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(result)
	{
    case WAP_BAM_WTAI_RESULT_OK:
		return MSF_TEL_OK;

    case WAP_BAM_WTAI_RESULT_UNSPECIFIED:
		return MSF_TEL_ERROR_UNSPECIFIED;

    case WAP_BAM_WTAI_RESULT_TEL_CALLED_PARTY_IS_BUSY:   
		return MSF_TEL_ERROR_CALLED_PARTY_IS_BUSY;

    case WAP_BAM_WTAI_RESULT_TEL_NETWORK_NOT_AVAILABLE:   
		return MSF_TEL_ERROR_NETWORK_NOT_AVAILABLE;

    case WAP_BAM_WTAI_RESULT_TEL_CALLED_PARTY_NO_ANSWER:  
		return MSF_TEL_ERROR_CALLED_PARTY_NO_ANSWER;

    case WAP_BAM_WTAI_RESULT_TEL_NO_ACTIVE_CONNECTION:  
		return MSF_TEL_ERROR_NO_ACTIVE_CONNECTION;

	case WAP_BAM_WTAI_RESULT_PB_IN_NAME:
		return HDI_PB_ERROR_IN_NAME;
		
	case WAP_BAM_WTAI_RESULT_PB_NUMBER_TO_LONG:
		return HDI_PB_ERROR_NUMBER_TO_LONG;

	case WAP_BAM_WTAI_RESULT_PB_PHONE_BOOK_ENTRY:
		return HDI_PB_ERROR_PHONE_BOOK_ENTRY;

	case WAP_BAM_WTAI_RESULT_PB_PHONE_BOOK_IS_FULL:
		return HDI_PB_ERROR_PHONE_BOOK_IS_FULL;

    case WAP_BAM_WTAI_RESULT_INVALID:
		return MSF_TEL_ERROR_INVALID;  
		
	default:
		return MSF_TEL_ERROR_UNSPECIFIED;
	}
}


/*****************************************************************************
 * FUNCTION
 *  bam_uri_request_rsp_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  uri_request_rsp     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_uri_request_rsp_hdlr(bam_uri_request_rsp_struct *uri_request_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    BRSif_sendUriResponse(MSF_MODID_BAM , uri_request_rsp->request_id, bam_uri_agent_get_result(uri_request_rsp->error_code));

}


/*****************************************************************************
 * FUNCTION
 *  bam_wait_user_action_ind_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  user_action_ind     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_wait_user_action_ind_hdlr(bam_wait_user_action_ind_struct *user_action_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_msg_wait_user_action_ind(user_action_ind->enable_positive_sk, 
									user_action_ind->positive_label, 
									user_action_ind->positive_label_len,
									user_action_ind->enable_negative_sk, 
									user_action_ind->negative_label,
									user_action_ind->negative_label_len);
}





#ifdef MSF_CFG_BRW_WMLS_NON_WIDGET_DLG_SUPPORT
void bam_wmls_create_dialogue_rsp_hdlr(bam_wmls_create_dialogue_rsp_struct *wmls_create_dialogue_rsp)
{

	BRSif_wmlsDlgResponse(MSF_MODID_BAM , wmls_create_dialogue_rsp->instance_id,wmls_create_dialogue_rsp->dialup_type, wmls_create_dialogue_rsp->result,wmls_create_dialogue_rsp->msg);

}
#endif

/*****************************************************************************
 * FUNCTION
 *  bam_wait_user_action_rsp_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  user_action_rsp     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_wait_user_action_rsp_hdlr(bam_wait_user_action_rsp_struct *user_action_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Dihrin Softkey begin */
//    owl_adp_mmi_activate_skey(user_action_rsp->press_positive_sk);
    /* Dihrin Softkey end */
}


/*****************************************************************************
 * FUNCTION
 *  bam_object_action_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  object_action_req       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_object_action_req_hdlr(bam_object_action_req_struct *object_action_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_sif_object_is_downloadable())
    {
        msf_content_data_t cd;

#if 0
/* under construction !*/
#endif
        cd.routingFormat = (MSF_UINT8) MSF_ROUTING_TYPE_MIME;
        cd.routingIdentifier = msf_cmmn_strdup(MSF_MODID_BAM, bam_sif_object_get_mime());
        cd.contentUrl = msf_cmmn_strdup(MSF_MODID_BAM, bam_sif_object_get_url());

        cd.contentSource = msf_cmmn_strdup(MSF_MODID_BAM, bam_sif_object_get_file_path());
        cd.contentDataType = MSF_CONTENT_DATA_FILE;
        cd.contentHeaders = NULL;
        cd.contentParameters = NULL;
        cd.contentData = NULL;
        cd.networkAccountId = 0;
        cd.contentDataLength = 0;
        cd.contentDRMDataExists = 0;
        cd.contentDRMData = NULL;

        bam_content_routing_request(&cd);
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_show_auth_dialog_rsp_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  show_auth_dialog_rsp        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_show_auth_dialog_rsp_hdlr(bam_show_auth_dialog_rsp_struct *show_auth_dialog_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_main_get_instance_id() == (MSF_INT16) show_auth_dialog_rsp->instance_id)
    {
        STKif_authCredentials(
            MSF_MODID_BRS,
            show_auth_dialog_rsp->request_id,
            show_auth_dialog_rsp->username,
            show_auth_dialog_rsp->password,
            show_auth_dialog_rsp->options);
    }
}


MSF_INT16 bam_main_get_instance_id(void)
{
    return bam_instance_id;
}

void bam_main_create_instance(void)
{
    bam_instance_id++;
#ifdef MSF_CFG_9W_MODE_KBRD_SIMULATION
    bam_main_nine_way_navigation_mode_status = TRUE;
#endif
#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
    bam_offline_reset_offline_state();
#endif
}

void bam_main_delete_instance(void)
{
    bam_instance_id--;
}

#if defined(BAM_CFG_PAGE_FETCHING_STATUS_SUPPORT) || defined(MSF_CFG_FILE_UPLOAD_SUPPORT)
void bam_main_set_received_transaction_status(MSF_BOOL status)
{
    bam_main_received_transaction_status = status;
}

MSF_BOOL bam_main_get_received_transaction_status(void)
{
    return bam_main_received_transaction_status;
}
#endif

void bam_main_set_activate_browser_input_status(MSF_BOOL status)
{
    bam_main_activate_browser_input_status = status;
}

MSF_BOOL bam_main_get_activate_browser_input_status(void)
{
    return bam_main_activate_browser_input_status;
}

void bam_main_close_connection_by_netid(void *p)
{
    bam_close_connection_by_netid_struct *data = (bam_close_connection_by_netid_struct*)p;
    STKif_closeConnectionsByNetAccId(MSF_MODID_BAM, data->net_id);
}
#ifdef MSF_CFG_9W_MODE_KBRD_SIMULATION
void bam_main_set_nine_way_navigation_mode_status(MSF_BOOL status)
{
    bam_main_nine_way_navigation_mode_status = status;
    if(bam_sif_get_brs_status() == BAM_SIF_BRS_READY)
        BRSif_change9wmode(MSF_MODID_BAM, bam_sif_get_brs_id());
    widget_send_update_event_to_wap();
}

MSF_BOOL bam_main_get_nine_way_navigation_mode_status(void)
{
    return bam_main_nine_way_navigation_mode_status;
}
#endif

char* bam_main_getVrsnNo(void)
{
  return BRSif_getVrsnNo();
}

#endif /*OBIGO_Q03C_BROWSER*/
