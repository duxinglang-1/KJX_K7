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
 *   bam_main.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*
 * bam_main.h
 *
 * Description:
 *   This file contain Browser Adaptation Module main functionality.
 *
 */
#ifndef _bam_main_h

#define _bam_main_h

#include "msf_cfg.h"
#include "msf_lib.h"
#include "msf_core.h"

#include "bam_if.h"


/* subscribe req. id in system events */
#define BAM_MAIN_REQID_SYSTEM_EVENT_1 1
#define BAM_MAIN_REQID_SYSTEM_EVENT_2 2

/************************************************************
 * Variables used for exeption handling
 ************************************************************/

extern mtk_jmpbuf bam_jmpbuf;
extern int bam_inside_run;
extern int bam_wants_to_run;

/*********************************************
 * Signals received by this sub module
 *********************************************/
#define BAM_MAIN_SIG_TERMINATE                          (BAM_SIG_DEST_MAIN + 0x01)
#define BAM_MAIN_SIG_STATUS                             (BAM_SIG_DEST_MAIN + 0x02)
#define BAM_MAIN_SIG_PIPE_NOTIFY                        (BAM_SIG_DEST_MAIN + 0x05)
#define BAM_MAIN_SIG_FILE_NOTIFY                        (BAM_SIG_DEST_MAIN + 0x06)
#define BAM_MAIN_SIG_CONTINUE_TERMINATE                 (BAM_SIG_DEST_MAIN + 0x08)
#define BAM_MAIN_SIG_BRS_CREATE_RESPONSE                (BAM_SIG_DEST_MAIN + 0x09)
#define BAM_MAIN_SIG_CONT_FILE_TASK                     (BAM_SIG_DEST_MAIN + 0x0a)
#define BAM_MAIN_SIG_ACT_FINISHED                       (BAM_SIG_DEST_MAIN + 0x0b)
#define BAM_MAIN_SIG_BRS_INSTANCE_DELETED               (BAM_SIG_DEST_MAIN + 0x11)
#define BAM_MAIN_SIG_BRS_SAVED_PAGES                    (BAM_SIG_DEST_MAIN + 0x12)
#define BAM_MAIN_SIG_BRS_SAVE_PAGE_RESPONSE             (BAM_SIG_DEST_MAIN + 0x13)
#define BAM_MAIN_SIG_WIDGET_ACCESS_KEY                  (BAM_SIG_DEST_MAIN + 0x15)
#define BAM_MAIN_SIG_BRS_STATUS                         (BAM_SIG_DEST_MAIN + 0x17)
#define BAM_MAIN_SIG_BRS_ERROR                          (BAM_SIG_DEST_MAIN + 0x18)
#define BAM_MAIN_SIG_BRS_DOCUMENT_INFO                  (BAM_SIG_DEST_MAIN + 0x19)
#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
#define BAM_MAIN_SIG_BRS_DO_ELEMENTS                    (BAM_SIG_DEST_MAIN + 0x1a)
#endif
#define BAM_MAIN_SIG_BRS_ELEMENT_FOCUSED                (BAM_SIG_DEST_MAIN + 0x1b)
#define BAM_MAIN_SIG_BRS_RESOURCE_LIST_RESPONSE         (BAM_SIG_DEST_MAIN + 0x1c)
#define BAM_MAIN_SIG_SES_SEC_CLASS                      (BAM_SIG_DEST_MAIN + 0x1d)
#define BAM_MAIN_SIG_START_INITIALIZATION               (BAM_SIG_DEST_MAIN + 0x1e)
#define BAM_MAIN_SIG_EVNT_SYSTEM_EVENT                  (BAM_SIG_DEST_MAIN + 0x20)
#define BAM_MAIN_SIG_BRS_SET_TITLE_STRING               (BAM_SIG_DEST_MAIN + 0x21)
#define BAM_MAIN_SIG_CPM_SET_PROFILE_REPLY              (BAM_SIG_DEST_MAIN + 0x22)

#define BAM_MAIN_SIG_HIST_SAVE_TO_FILE                  (BAM_SIG_DEST_MAIN + 0x30)

/*********************************************
 * Initialization states
 *********************************************/
#define BAM_NULL_STATE                 ((MSF_UINT32)(0x0000))
#define BAM_READING_REGISTRY           ((MSF_UINT32)(0x0001))
#define BAM_INITIALIZED                ((MSF_UINT32)(0x0002))
#define BAM_INITIALIZING               ((MSF_UINT32)(0x0004))
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
#define BAM_READING_RECENT_PAGE_LIST   ((MSF_UINT32)(0x0008))   /* History */
#endif 
#define BAM_INIT_REGISTRY              ((MSF_UINT32)(0x0010))
#define BAM_INIT_PROFILE               ((MSF_UINT32)(0x0020))

/*********************************************
 * Sub-module states
 *********************************************/
#define BAM_MAIN_SUB_STATE_NULL        ((MSF_UINT32)(0x0000))
#define BAM_MAIN_SUB_STATE_BRS_ACTIVE  ((MSF_UINT32)(0x0001))
#define BAM_MAIN_SUB_STATE_STK_ACTIVE  ((MSF_UINT32)(0x0002))
#define BAM_MAIN_SUB_STATE_CPS_ACTIVE  ((MSF_UINT32)(0x0004))
#define BAM_MAIN_SUB_STATE_SES_ACTIVE  ((MSF_UINT32)(0x0008))
#define BAM_MAIN_SUB_STATE_DLS_ACTIVE  ((MSF_UINT32)(0x0010))
#define BAM_MAIN_SUB_STATE_HIST_ACTIVE ((MSF_UINT32)(0x0020))
#define BAM_MAIN_SUB_STATE_OWL_ACTIVE  ((MSF_UINT32)(0x0040))   /* Add OWL module */
#if defined(__WAP_VDS_MODULE__) && defined(MSF_MODID_VDS)
#define BAM_MAIN_SUB_STATE_VDS_ACTIVE  ((MSF_UINT32)(0x0080))   /* Add VDS module */

#endif /* __WAP_VDS_MODULE__ && MSF_MODID_VDS */
#if defined(__WAP_SVS_MODULE__) && defined(MSF_MODID_SVS)
#define BAM_MAIN_SUB_STATE_SVS_ACTIVE  ((MSF_UINT32)(0x0100))   /* Add SVS module */
#endif /* __WAP_SVS_MODULE__ && MSF_MODID_SVS */

/*********************************************
 * Exported function
 *********************************************/

extern void bam_init(void);

extern void bam_process(void);

#if 0
/* under construction !*/
#endif

/*
 * Function sets the state of BAM to stat. This function is
 * used during startup and termination. The state is typically
 * used when reading the registry. This is a delayed operation
 * and therefore we need to remember the state so the initialization
 * routine is aware that it can't return MODULE_ACTIVE.
 *
 * PARAMETERS
 *
 * state     : The state as defined above to be set
 *
 * RETURN    : void
 */
extern void bam_main_set_module_state(MSF_UINT32 state);

/*
 * Function removes the previously set state of BAM to stat.
 * used during startup and termination.
 *
 * PARAMETERS
 *
 * state     : The state to be removed
 *
 * RETURN    : void
 */
extern void bam_main_remove_module_state(MSF_UINT32 state);

/*
* Set bam profile ready and make bam ready
*/
extern void bam_main_profile_init_done(void);

/*
 * Set sub-module state.
 */
extern void bam_main_set_sub_module_state(MSF_UINT32 state);

/*
 * Remove sub-module state.
 */
extern void bam_main_remove_sub_module_state(MSF_UINT32 state);

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
#endif

/*
 * This function is called to try if BAM has finished the initialization process.
 * If the module is finished it starts parsing the command line if available.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
extern void bam_init_done(void);

/*
 * This function terminates the Browser Adaptation module
 * and frees all necessary resources.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
extern void bam_main_terminate(void);

/*
 * This function is called when the BAM receives MSF_SIG_MODULE_STATUS
 * with modID OWL.
 *
 * PARAMETERS
 *
 * status    : MSF module status.
 *
 * RETURN    : void
 */
extern void bam_owl_module_status(MSF_UINT8 status);

/*****************************
 * BAM Signal handling
 *****************************/

extern void bam_delete_instance_req_hdlr(bam_delete_instance_req_struct *delete_instance_req);

#if 0
/* under construction !*/
#endif

extern void bam_load_url_req_hdlr(bam_load_url_req_struct *load_url_req);

extern void bam_load_data_req_hdlr(bam_load_data_req_struct *load_data_req);

#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
extern void bam_activate_do_element_req_hdlr(bam_activate_do_element_req_struct *activate_do_element_req);
#endif

extern void bam_move_req_hdlr(bam_move_req_struct *move_req);

extern void bam_reload_req_hdlr(bam_reload_req_struct *reload_req);

extern void bam_stop_req_hdlr(bam_stop_req_struct *stop_req);

extern void bam_navigation_change_req_hdlr(bam_navigation_change_req_struct *navigation_change_req);

#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
extern void bam_save_page_req_hdlr(bam_save_page_req_struct *save_page_req);

extern void bam_get_saved_page_req_hdlr(bam_get_saved_page_req_struct *get_saved_page_req);

extern void bam_load_saved_page_req_hdlr(bam_load_saved_page_req_struct *load_saved_page_req);

extern void bam_delete_saved_page_req_hdlr(bam_delete_saved_page_req_struct *delete_saved_page_req);

extern void bam_delete_n_saved_page_req_hdlr(bam_delete_n_saved_page_req_struct *delete_n_saved_page_req);

extern void bam_delete_all_saved_pages_req_hdlr(bam_delete_all_saved_pages_req_struct *delete_all_saved_pages_req);

#if 0
/* under construction !*/
#endif

extern void
bam_get_saved_pages_list_start_req_hdlr(bam_get_saved_pages_list_start_req_struct *get_saved_pages_list_start_req);

extern void
bam_get_saved_pages_list_continue_req_hdlr(
    bam_get_saved_pages_list_continue_req_struct *get_saved_pages_list_continue_req);

extern void bam_get_saved_pages_list_end_req_hdlr(
                bam_get_saved_pages_list_end_req_struct *get_saved_pages_list_end_req);
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
#endif
/*
 * void
 * bam_navigate_to_hotspot_req_hdlr(bam_navigate_to_hotspot_req_struct *navigate_to_hotspot_req);
 */
//#ifdef MSF_CFG_9W_MODE_KBRD_SIMULATION
extern void bam_change_setting_value_req_hdlr(bam_change_setting_value_req_struct *change_setting_value_req);
//#endif

extern void bam_set_profile_req_hdlr(bam_set_profile_req_struct *set_profile_req);
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT

extern void
bam_get_recent_pages_list_start_req_hdlr(bam_get_recent_pages_list_start_req_struct *get_recent_pages_list_start_req);

extern void
bam_get_recent_pages_list_continue_req_hdlr(
    bam_get_recent_pages_list_continue_req_struct *get_recent_pages_list_continue_req);

extern void bam_get_recent_pages_list_end_req_hdlr(
                bam_get_recent_pages_list_end_req_struct *get_recent_pages_list_end_req);

extern void bam_get_recent_page_req_hdlr(bam_get_recent_page_req_struct *get_recent_page_req);

extern void bam_load_recent_page_req_hdlr(bam_load_recent_page_req_struct *load_recent_page_req);

extern void bam_delete_recent_page_req_hdlr(bam_delete_recent_page_req_struct *delete_recent_page_req);

extern void bam_delete_recent_n_page_req_hdlr(bam_delete_n_recent_page_req_struct *delete_n_recent_page_req);

extern void bam_delete_all_recent_pages_req_hdlr(bam_delete_all_recent_pages_req_struct *delete_all_recent_pages_req);
#endif 
extern void bam_register_keypad_handler_req_hdlr(bam_register_keypad_handler_req_struct *register_keypad_handler_req);

#ifdef __MMI_TOUCH_SCREEN__
extern void bam_handle_pen_event_req_hdlr(bam_handle_pen_event_req_struct *handle_pen_event_req);
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

extern void bam_notify_screen_info_req_hdlr(bam_notify_screen_info_req_struct *notify_screen_info_req);

#ifdef MSF_CFG_FILE_UPLOAD_SUPPORT
extern void bam_select_file_rsp_hdlr(bam_select_file_rsp_struct * select_file_rsp);
#endif

extern void bam_wtai_tel_rsp_hdlr(bam_wtai_tel_rsp_struct *wtai_tel_rsp);

extern void bam_wtai_pb_rsp_hdlr(bam_wtai_pb_rsp_struct *wtai_pb_rsp);

extern void bam_uri_request_rsp_hdlr(bam_uri_request_rsp_struct *uri_request_rsp);

extern void bam_wait_user_action_ind_hdlr(bam_wait_user_action_ind_struct *user_action_ind);

extern void bam_wait_user_action_rsp_hdlr(bam_wait_user_action_rsp_struct *user_action_rsp);

extern void bam_object_action_req_hdlr(bam_object_action_req_struct *object_action_req);

extern void bam_show_auth_dialog_rsp_hdlr(bam_show_auth_dialog_rsp_struct *show_auth_dialog_rsp);

extern MSF_INT16 bam_main_get_instance_id(void);

extern void bam_main_create_instance(void);

extern void bam_main_delete_instance(void);

#if defined(BAM_CFG_PAGE_FETCHING_STATUS_SUPPORT) || defined(MSF_CFG_FILE_UPLOAD_SUPPORT)
extern void bam_main_set_received_transaction_status(MSF_BOOL status);

extern MSF_BOOL bam_main_get_received_transaction_status(void);
#endif

extern void bam_main_set_activate_browser_input_status(MSF_BOOL status);

extern MSF_BOOL bam_main_get_activate_browser_input_status(void);

extern void bam_main_close_connection_by_netid(void *p);

#ifdef MSF_CFG_9W_MODE_KBRD_SIMULATION
extern void bam_main_set_nine_way_navigation_mode_status(MSF_BOOL STATUS);

extern MSF_BOOL bam_main_get_nine_way_navigation_mode_status(void);
#endif

#endif /* _bam_main_h */


#endif /*OBIGO_Q03C_BROWSER*/
