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
 *   bam_sif.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contain the BAM Services Interface, E.g. the functionality
 *   needed to handle signals from BRS is ipmlemented here
 *   internal signal receive funtion.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*
 * bam_sif.c
 *
 * This file contain the BAM Services Interface, E.g. the functionality
 * needed to handle signals from BRS is implemented here
 * internal signal receive funtion.
 *
 */
#include "msf_core.h"
#include "msf_file.h"
#include "msf_log.h"
#include "msf_wid.h"
#include "msf_neta.h"

#include "bam_cmn.h"
#include "bam_do_elem.h"
#include "bam_hist.h"
#include "bam_msg.h"
#include "bam_main.h"
#include "bam_view.h"
#include "bam_viewopt.h"
#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
#include "bam_offline.h"
#endif
#if 0
/* under construction !*/
#endif
#include "bam_registry.h"
#include "bam_shortcuts.h"
#include "bam_sif.h"
#include "bam_req.h"
#include "bam_win.h"
#include "bam_struct.h"
#include "bam_cfg.h"

#include "brs_if.h"
#include "stk_if.h"
#if 0
/* under construction !*/
/* under construction !*/
#endif
#ifdef WAP_SEC_SUPPORT
    #ifdef MSF_MODID_SES
        #include "ses_if.h"
    #endif /* MSF_MODID_SES */
#endif /* WAP_SEC_SUPPORT */

#include "kal_release.h"
#include "wap_ps_struct.h"
#include "ps_public_enum.h"
#include "ppp_l4_enums.h"

#define BAM_SIF_BRS_INSTANCE_ID_NULL    (-1)

/************************************************************
 * Function declarations
 ************************************************************/
static void bam_sif_handle_brs_active(void);
static void bam_sif_handle_brs_terminated(void);
extern void widget_init_structure(void);
/************************************************************
 * Global variables
 ************************************************************/
static int bam_sif_brs_status;

/* Current termination mode. See msf_code.h. */
static MSF_UINT8 bam_sif_terminate_mode;
static MSF_BOOL bam_sif_brs_is_terminating;
static MSF_BOOL bam_sif_brs_is_loading;
static MSF_BOOL bam_sif_holding_bearer;
static MSF_BOOL bam_sif_navigating_internet;
static MSF_INT16 bam_sif_instance_id;
static MSF_INT32 bam_sif_current_page_size;

static MSF_BOOL bam_sif_is_fullscreen;
static brs_document_info_t *bam_sif_current_doc_info;
static brs_element_focused_t *bam_sif_current_element;

static MSF_INT32 bam_sif_document_security_id;
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
static MSF_INT32 bam_sif_add_to_history;
#endif 
MsfWindowHandle bam_sif_brs_paintbox;

#if 0
#ifdef MTK_TMP_PATCH /* CR33551 */
/* under construction !*/
#endif
#endif

#ifdef BAM_CFG_SELECT_MODE

static MSF_INT16 bam_sif_select_mode;   /* Current BRS Focusable Elements */

#endif /* BAM_CFG_SELECT_MODE */

/************************************************************
 * Functions
 ************************************************************/


/*****************************************************************************
 * FUNCTION
 *  bam_sif_init_internal_state
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_sif_init_internal_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#endif

	bam_sif_terminate_mode = 0xFF;
    bam_sif_instance_id = BAM_SIF_BRS_INSTANCE_ID_NULL;
    bam_sif_current_page_size = 0;
    bam_sif_current_doc_info = NULL;
    bam_sif_current_element = NULL;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    bam_sif_brs_paintbox = 0;
#endif

	bam_sif_brs_is_loading = FALSE;
	bam_sif_holding_bearer = FALSE;
	bam_sif_navigating_internet = FALSE;
	bam_sif_document_security_id = -1;

#ifdef BAM_CFG_SELECT_MODE

    bam_sif_select_mode = 0;

#endif /* BAM_CFG_SELECT_MODE */

}


/*****************************************************************************
 * FUNCTION
 *  bam_sif_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_sif_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	bam_sif_brs_status = BAM_SIF_BRS_NOT_ACTIVE;
    bam_sif_brs_is_terminating = FALSE;
	bam_sif_is_fullscreen = FALSE;

    bam_sif_init_internal_state();
}


/*****************************************************************************
 * FUNCTION
 *  bam_sif_terminate
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_sif_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_sif_current_doc_info)
    {
        //MSF_SIGNAL_DESTRUCT(MSF_MODID_BAM, BRS_SIG_DOCUMENT_INFO, bam_sif_current_doc_info);
		BAM_FREE(bam_sif_current_doc_info->url);
		BAM_FREE(bam_sif_current_doc_info->title);
		BAM_FREE(bam_sif_current_doc_info);
        bam_sif_current_doc_info = NULL;
    }

    if (bam_sif_current_element)
    {
        //MSF_SIGNAL_DESTRUCT(MSF_MODID_BAM, BRS_SIG_ELEMENT_FOCUSED, bam_sif_current_element);
		BAM_FREE(bam_sif_current_element->object_filePath);
		BAM_FREE(bam_sif_current_element->title);
        BAM_FREE(bam_sif_current_element->url);
		BAM_FREE(bam_sif_current_element->object_url);
		BAM_FREE(bam_sif_current_element->object_mime);
		BAM_FREE(bam_sif_current_element);
        bam_sif_current_element = NULL;
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    bam_sif_brs_paintbox = 0;
#endif
}

#ifdef WAP_SEC_SUPPORT
#ifdef MSF_MODID_SES
/*
 * This function is called in response to a previous request to the Security
 * package to return the currently used security class
 *
 * PARAMETERS
 *
 * sec_class : The currently used security class
 *
 * RETURN    : void
 */


/*****************************************************************************
 * FUNCTION
 *  bam_sif_set_security_class
 * DESCRIPTION
 *
 * PARAMETERS
 *  sec_class       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_sif_set_security_class(int sec_class)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Need to notify BrowserAPP to display the security icon */
    bam_msg_set_sec_class_ind(bam_sif_get_brs_id(), sec_class);
}

#endif /* MSF_MODID_SES */

#endif /* WAP_SEC_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  bam_sif_set_brs_status
 * DESCRIPTION
 *  This function is used to set the assumed state of the BRS
 * PARAMETERS
 *  status      [IN]    Current state as defined above
 * RETURNS
 *  void
 *****************************************************************************/
void bam_sif_set_brs_status(int status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_sif_brs_status = status;
}


/*****************************************************************************
 * FUNCTION
 *  bam_sif_get_brs_status
 * DESCRIPTION
 *  Returns the currently assumed BRS state
 * PARAMETERS
 *  void
 * RETURNS
 *  BRS state
 *****************************************************************************/
int bam_sif_get_brs_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return bam_sif_brs_status;
}


/*****************************************************************************
 * FUNCTION
 *  bam_sif_brs_is_idle
 * DESCRIPTION
 *  Indicate whether BRS is ready and idle
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE for idle, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL bam_sif_brs_is_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((bam_sif_brs_status == BAM_SIF_BRS_READY) && 
		    (bam_sif_brs_is_loading == FALSE));
}


/*****************************************************************************
 * FUNCTION
 *  bam_sif_get_brs_id
 * DESCRIPTION
 *  This function is used to get the object Id previously returned in
 *  a request to instantiate the BRS
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
MSF_INT16 bam_sif_get_brs_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return bam_sif_instance_id;
}


/*****************************************************************************
 * FUNCTION
 *  bam_sif_get_brs_security_id
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
MSF_INT32 bam_sif_get_brs_security_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_sif_current_doc_info)
    {
        return bam_sif_current_doc_info->securityId;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  bam_sif_get_current_page_size
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
MSF_INT32 bam_sif_get_current_page_size(void)
{
    return bam_sif_current_page_size;
}


/*****************************************************************************
 * FUNCTION
 *  bam_sif_module_status
 * DESCRIPTION
 *  This function is called when the BAM receives MSF_SIG_MODULE_STATUS
 *  with modID BRS.
 * PARAMETERS
 *  status      [IN]    MSF module status.
 * RETURNS
 *  void
 *****************************************************************************/
void bam_sif_module_status(MSF_UINT8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (status == MODULE_STATUS_ACTIVE)
    {
        bam_sif_handle_brs_active();
    }
    else if (status == MODULE_STATUS_TERMINATED)
    {
        extern MSF_BOOL bam_app_request_to_delete_brs;
        bam_sif_handle_brs_terminated();
#if 0
/* under construction !*/
#else
        if(bam_app_request_to_delete_brs == TRUE)
        {
            bam_msg_delete_instance_cnf(1 /* Currently there is only one BRS instance */ );
            bam_app_request_to_delete_brs = FALSE;
        }
#endif
    }
}

extern MSF_BOOL bam_app_request_to_create_brs;

/*****************************************************************************
 * FUNCTION
 *  bam_sif_handle_brs_active
 * DESCRIPTION
 *  This function must be called when BAM receives the signal that BRS is
 *  active. a request to create an instance of the BRS is made.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bam_sif_handle_brs_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MsfWidgetId screen_id;
    MsfDeviceProperties prop;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	bam_sif_init_internal_state();

    bam_sif_set_brs_status(BAM_SIF_BRS_MOD_ACTIVE_NO_INST);

    if (bam_sif_brs_is_terminating)
    {
        bam_sif_brs_terminate(bam_sif_terminate_mode);
        bam_msg_create_instance_cnf(bam_sif_instance_id, WAP_BAM_ERROR_TERMINATING);
		bam_app_request_to_create_brs = FALSE;
        return;
    }

#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
	bam_do_elem_init();
#endif

#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
//    bam_offline_init();
#endif
//	bam_hist_init();

	bam_cmn_init();

    bam_widget_create_screen();

    MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
    //MSF_WIDGET_GET_ID(bam_win_get_screen(), &screen_id);
    widget_init_structure();
    BRSif_createInstance(MSF_MODID_BAM, bam_win_get_screen(), 0, 0, prop.displaySize.height, prop.displaySize.width, "BAM");

    bam_sif_set_brs_status(BAM_SIF_BRS_CREATING);

}

void bam_sif_bearer_open_rsp_hdl (bam_bearer_open_rsp_struct *p)
{
    BRSif_bearer_open_response(MSF_MODID_BAM, bam_sif_instance_id, p->error_code);
	//BRSif_BearerOpenRsp(MSF_MODID_BAM, bam_sif_instance_id,p->error_code);
}
/*****************************************************************************
 * FUNCTION
 *  bam_sif_brs_instance_created
 * DESCRIPTION
 *  This function must be called when a request to instantiate the BRS has
 *  returned. If there is a pending request this will be issued now.
 * PARAMETERS
 *  instance        [IN] Pointer to signal structure
 * RETURNS
 *  void
 *****************************************************************************/
void bam_sif_brs_instance_created(brs_created_t *instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfWindowHandle paint_window;
    char *url;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (instance->errorCode == 0)
    {
        bam_sif_brs_status = BAM_SIF_BRS_READY;
        bam_sif_instance_id = instance->instanceId;
    }
    else
    {
        bam_sif_brs_status = BAM_SIF_BRS_MOD_ACTIVE_NO_INST;
        bam_sif_instance_id = BAM_SIF_BRS_INSTANCE_ID_NULL;
    }

    if (!bam_sif_brs_is_terminating && instance->errorCode == 0)
    {
        paint_window = ((brs_created_t *)instance)->paintBox ;//MSF_WIDGET_GET_HANDLE(MSF_MODID_BAM, instance->paintBox);
        bam_sif_brs_paintbox = paint_window;
        /*
         * If browser is not configured to have a select mode then objects
         * must be always selectable
         */
        MSF_WIDGET_SET_IN_FOCUS(bam_sif_get_brs_paintbox(), 1);

    #ifndef BAM_CFG_SELECT_MODE

        BRSif_navigationChange(MSF_MODID_BAM, bam_sif_instance_id, BRS_FOCUSABLE_ELEMENTS_ALL_MODE);
	
	#else

//		bam_sif_enable_select_mode(BRS_FOCUSABLE_ELEMENTS_NORMAL_MODE);

    #endif /* BAM_CFG_SELECT_MODE */

#if 0
    #ifdef BAM_CFG_SHORTCUTS_ENABLED
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* BAM_CFG_SHORTCUTS_ENABLED */
#endif

	#ifdef WAP_SEC_SUPPORT
	#ifdef MSF_MODID_SES
	    bam_sif_set_security_class(0);
	#endif
	#endif /* WAP_SEC_SUPPORT */

		/* Send MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF after saved pages into is received from BRS */
//        bam_offline_start();
#if 0
/* under construction !*/
#endif
		bam_app_request_to_create_brs = FALSE;
        if((url = bam_req_get_request_url ()) != NULL)
            bam_send_request(url);
#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
        if (bam_offline_page_has_page_to_delete() == TRUE)
        {
            bam_offline_page_delete_pending_page();
        }
#endif
}
    else if (bam_sif_brs_is_terminating)
    {
        bam_sif_brs_terminate(bam_sif_terminate_mode);
        bam_msg_create_instance_cnf(bam_sif_instance_id, WAP_BAM_ERROR_TERMINATING);
		bam_app_request_to_create_brs = FALSE;
    }
    else
    {
        bam_msg_create_instance_cnf(bam_sif_instance_id, WAP_BAM_ERROR_INTERNAL);
		bam_app_request_to_create_brs = FALSE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  bam_sif_brs_instance_deleted
 * DESCRIPTION
 *  This function is called when BRS_SIG_INSTANCE_DELETED is received.
 * PARAMETERS
 *  inst_id     [IN]    BRS instance ID
 * RETURNS
 *  void
 *****************************************************************************/
void bam_sif_brs_instance_deleted(MSF_INT16 inst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(inst_id == bam_sif_instance_id))
    {
        /* Not an instance created by the BAM */
        return;
    }
    
    bam_sif_instance_id = BAM_SIF_BRS_INSTANCE_ID_NULL;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    bam_sif_brs_paintbox = 0;
#endif

	if (bam_sif_is_holding_bearer())
	{
		/* Release the bearer when BRS instance is deleted */
		bam_sif_set_holding_bearer(FALSE, bam_registry_get_int(BAM_SETTING_ID_CON_ACCOUNT));
	}

    if (bam_sif_brs_is_terminating)
    {
        MSF_MODULE_TERMINATE(MSF_MODID_BAM, MSF_MODID_BRS/*, bam_sif_terminate_mode*/);
        bam_sif_brs_status = BAM_SIF_BRS_TERMINATING;
    }
    else
    {
        bam_sif_brs_status = BAM_SIF_BRS_MOD_ACTIVE_NO_INST;
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_sif_handle_brs_terminated
 * DESCRIPTION
 *  This function should be called when the BRS has terminated
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bam_sif_handle_brs_terminated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_sif_brs_status == BAM_SIF_BRS_ACTIVATED)
    {
        /* Notify the upper layer module of this termination. */
    }

    bam_sif_brs_is_terminating = FALSE;
    bam_sif_brs_status = BAM_SIF_BRS_NOT_ACTIVE;
    bam_main_remove_sub_module_state(BAM_MAIN_SUB_STATE_BRS_ACTIVE);

    bam_win_release_screen();

    /*
     * Call the termination functions that can NOT be delayed.
     */
#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
//	bam_offline_terminate();    /* Terminate Offline Pages */
#endif 
#if 0
/* under construction !*/
#endif

	bam_sif_terminate();
//	bam_cmn_terminate();

#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
	bam_do_elem_terminate();
#endif

#if defined(__WAP_VDS_MODULE__) && defined(MSF_MODID_VDS)

    MSF_MODULE_TERMINATE(MSF_MODID_BAM, 0, MSF_MODID_VDS, 0);

#endif /* __WAP_VDS_MODULE__ && MSF_MODID_VDS */

#if defined(__WAP_SVS_MODULE__) && defined(MSF_MODID_SVS)
    MSF_MODULE_TERMINATE(MSF_MODID_BAM, 0, MSF_MODID_SVS, 0);
#endif /* __WAP_SVS_MODULE__ && MSF_MODID_SVS */

#if 0
/* under construction !*/
#endif

#if 0
/* under construction !*/
#endif
    BRSc_kill();
}


/*****************************************************************************
 * FUNCTION
 *  bam_sif_start_brs
 * DESCRIPTION
 *  This function will call the MSF macros to try and start the BRS module
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_sif_start_brs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_sif_brs_status == BAM_SIF_BRS_NOT_ACTIVE)
    {
        BRSif_startInterface();
        MSF_MODULE_START(MSF_MODID_BAM, MSF_MODID_BRS, "", NULL, NULL);
        bam_sif_set_brs_status(BAM_SIF_BRS_ACTIVATED);
        bam_main_set_sub_module_state(BAM_MAIN_SUB_STATE_BRS_ACTIVE);
        bam_app_request_to_create_brs = TRUE;
    }
    else if (bam_sif_brs_status == BAM_SIF_BRS_MOD_ACTIVE_NO_INST)
    {
        bam_sif_handle_brs_active();
    }
    /* else: BRS is busy starting or terminating */
}


MSF_INT32 bam_sif_get_terminate_mode(void)
{
	return bam_sif_terminate_mode;
}


/*****************************************************************************
 * FUNCTION
 *  bam_sif_brs_terminate
 * DESCRIPTION
 *  Terminates the BRS module.
 * PARAMETERS
 *  mode        [IN]
 * RETURNS
 *
 *****************************************************************************/
MSF_BOOL bam_sif_brs_terminate(MSF_UINT8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_sif_brs_status == BAM_SIF_BRS_NOT_ACTIVE)
    {
        return TRUE;
    }

    bam_sif_brs_is_terminating = TRUE;

    if (bam_sif_brs_status == BAM_SIF_BRS_READY)
    {
        BRSif_deleteInstance(MSF_MODID_BAM, bam_sif_get_brs_id());
        MSF_MODULE_TERMINATE(MSF_MODID_BAM, MSF_MODID_BRS);
        bam_sif_brs_status = BAM_SIF_BRS_DELETING_INSTANCE;
    }
    else if (bam_sif_brs_status == BAM_SIF_BRS_MOD_ACTIVE_NO_INST)
    {
        bam_sif_brs_status = BAM_SIF_BRS_TERMINATING;
        MSF_MODULE_TERMINATE(MSF_MODID_BAM, MSF_MODID_BRS);
    }
    else if (bam_sif_brs_status == BAM_SIF_BRS_TERMINATING && mode > bam_sif_terminate_mode)
    {
        /* Stronger termination mode received */
#if defined(__WAP_VDS_MODULE__) && defined(MSF_MODID_VDS)
		MSF_MODULE_TERMINATE(MSF_MODID_BAM, 0, MSF_MODID_VDS, mode);
#endif /* __WAP_VDS_MODULE__ && MSF_MODID_VDS */
#if defined(__WAP_SVS_MODULE__) && defined(MSF_MODID_SVS)
		MSF_MODULE_TERMINATE(MSF_MODID_BAM, 0, MSF_MODID_SVS, mode);
#endif /* __WAP_SVS_MODULE__ && MSF_MODID_SVS */
#if 0
/* under construction !*/
#endif
    }

    bam_sif_terminate_mode = mode;

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_sif_handle_brs_status
 * DESCRIPTION
 *  This function is called when the BAM receives a status notification from
 *  the BRS. This information is used to update the status bar.
 * PARAMETERS
 *  p       [IN] Pointer to status structure (brs_status_t)
 * RETURNS
 *  void
 *****************************************************************************/
void bam_sif_handle_brs_status(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    brs_status_t *st = (brs_status_t*) p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (st->status)
    {
        case BRS_STATUS_START_TRANSACTION:
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM,
                             BAM_SIF_0044DED1479A2A94539CDE17A9076462,
                             "BAM: BRS Status id = %i, status = %i (BRS_STATUS_START_TRANSACTION)\n",
                             ((brs_status_t*) p)->instanceId, ((brs_status_t*) p)->status));
#if 0
	#ifdef MTK_TMP_PATCH /* CR33551 */
/* under construction !*/
	#endif /* MTK_TMP_PATCH */
#endif

            bam_sif_current_page_size = 0;
			bam_sif_brs_is_loading = TRUE;

#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
            if (0 == bam_offline_get_offline_mode())
            {
    			if (bam_sif_is_holding_bearer() == FALSE)
    			{
    				bam_sif_set_holding_bearer(TRUE, bam_registry_get_int(BAM_SETTING_ID_CON_ACCOUNT));
    			}
            }
#else
			if (bam_sif_is_holding_bearer() == FALSE)
			{
				bam_sif_set_holding_bearer(TRUE, bam_registry_get_int(BAM_SETTING_ID_CON_ACCOUNT));
			}
#endif
			
            break;

        case BRS_STATUS_END_TRANSACTION:
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_SIF_2F8919DCACB5DA8DD22F0E4F5B570DF9,
                             "BAM: BRS Status id = %i, status = %i (BRS_STATUS_END_TRANSACTION)\n",
                             ((brs_status_t*) p)->instanceId, ((brs_status_t*) p)->status));
#if 0
    #ifdef MTK_TMP_PATCH    /* CR33551 */
/* under construction !*/
/* under construction !*/
	#endif /* MTK_TMP_PATCH */
#endif

            if (st->document_bytes_total == 0)
            {
                bam_sif_current_page_size = st->document_bytes_read;   
            }
            else 
            {
                bam_sif_current_page_size = st->document_bytes_total;
            }
            if (bam_sif_current_page_size == 0) 
            {
                bam_sif_current_page_size = bam_sif_doc_get_size();		
            }

			if ((bam_sif_is_navigating_internet() == FALSE) &&
				(bam_sif_is_holding_bearer()))
			{
				if (bam_sif_current_doc_info &&
					(bam_sif_current_doc_info->protocol == STK_PROTOCOL_WSP_CL || 
					 bam_sif_current_doc_info->protocol == STK_PROTOCOL_WSP_CL_WTLS ||
					 bam_sif_current_doc_info->protocol == STK_PROTOCOL_WSP_CO ||
					 bam_sif_current_doc_info->protocol == STK_PROTOCOL_WSP_CO_WTLS ||
					 bam_sif_current_doc_info->protocol == STK_PROTOCOL_HTTP || 
					 bam_sif_current_doc_info->protocol == STK_PROTOCOL_HTTP_TLS ||
					 bam_sif_current_doc_info->protocol == STK_PROTOCOL_HTTP_SSL || 
					 bam_sif_current_doc_info->protocol == STK_PROTOCOL_CACHE))
				{
					bam_sif_set_navigating_internet(TRUE);
				}
				else
				{
					bam_sif_set_holding_bearer(FALSE, bam_registry_get_int(BAM_SETTING_ID_CON_ACCOUNT));
				}
			}

            /* Set the loading flag to FALSE */
			bam_sif_brs_is_loading = FALSE;

			/* Add page to access history */
		//	bam_hist_add_item(bam_cmn_get_current_page_url(), bam_cmn_get_current_page_title());
#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
            if(bam_offline_get_offline_mode() == 1)
            {
              bam_offline_set_offline_mode(FALSE);
              bam_offline_reset_offline_state();
            }
#endif    
            break;

       /* case BRS_STATUS_TRANSACTION_STATUS:
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM,
                             BAM_SIF_482F8F856F1A2F30D031622E161E973E,
                             "BAM: BRS Status id = %i, status = %i (BRS_STATUS_TRANSACTION_STATUS)\n",
                             ((brs_status_t*) p)->instanceId, ((brs_status_t*) p)->status));

            bam_sif_current_page_size = st->document_bytes_read;
            break;*/
#if defined(BAM_CFG_PAGE_FETCHING_STATUS_SUPPORT) || defined(MSF_CFG_FILE_UPLOAD_SUPPORT)
        case BRS_STATUS_LOADING_DOCUMENT:
            MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_SIF_STATUS_LOADING_DOCUMENT, "BAM: BRS Status id = %i, status = %i (BRS_STATUS_LOADING_DOCUMENT)\n",((brs_status_t *)p)->instanceId, ((brs_status_t *)p)->status));    
            break;
        case BRS_STATUS_LOADING_DOCUMENT_DONE:
            MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_SIF_STATUS_LOADING_DOCUMENT_DONE, "BAM: BRS Status id = %i, status = %i (BRS_STATUS_LOADING_DOCUMENT_DONE)\n",((brs_status_t *)p)->instanceId, ((brs_status_t *)p)->status));
            break;
        case BRS_STATUS_LOADING_DOCUMENT_FAILED:
            MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_SIF_STATUS_LOADING_DOCUMENT_FAILED, "BAM: BRS Status id = %i, status = %i (BRS_STATUS_LOADING_DOCUMENT_FAILED)\n",((brs_status_t *)p)->instanceId, ((brs_status_t *)p)->status));
            return;
        case BRS_STATUS_LOADING_OBJECT:
            MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_SIF_STATUS_LOADING_OBJECT, "BAM: BRS Status id = %i, status = %i (BRS_STATUS_LOADING_OBJECT)\n",((brs_status_t *)p)->instanceId, ((brs_status_t *)p)->status));
            break;
        case BRS_STATUS_LOADING_OBJECT_DONE:
            MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_SIF_STATUS_LOADING_OBJECT_DONE, "BAM: BRS Status id = %i, status = %i (BRS_STATUS_LOADING_OBJECT_DONE)\n",((brs_status_t *)p)->instanceId, ((brs_status_t *)p)->status));
            break;
		case BRS_STATUS_UPLOAD_FILE:
            //MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_SIF_STATUS_LOADING_OBJECT_DONE, "BAM: BRS Status id = %i, status = %i (BRS_STATUS_LOADING_OBJECT_DONE)\n",((brs_status_t *)p)->instanceId, ((brs_status_t *)p)->status));
            break;
        case BRS_STATUS_LOADING_OBJECT_FAILED:
            MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_SIF_STATUS_LOADING_OBJECT_FAILED, "BAM: BRS Status id = %i, status = %i (BRS_STATUS_LOADING_OBJECT_FAILED)\n",((brs_status_t *)p)->instanceId, ((brs_status_t *)p)->status));
            return;
#endif
#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
#ifdef MTK_TMP_PATCH
        case BRS_STATUS_OFFLINE_MODE_OFF:
            bam_offline_set_offline_mode_from_brs(TRUE);
            return;
#endif
/* MAUI_02454764 starts */
/*
        case BRS_STATUS_OFFLINE_PAGE_SAVE_OK:
            bam_offline_saving_offline_done(TRUE);
            return;
        case BRS_STATUS_OFFLINE_PAGE_SAVE_FAILED:
            bam_offline_saving_offline_done(FALSE);
            return;
*/
        case BRS_STATUS_OFFLINE_PAGE_SAVE_OK:
        case BRS_STATUS_OFFLINE_PAGE_SAVE_FAILED:
        case BRS_STATUS_OFFLINE_PAGE_EXISTS:
            bam_offline_saving_offline_done(st->status);
            return;
/* MAUI_02454764 ends */
#endif    
			
        default:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_SIF_99A9970D7BDE9CE99373D6609CDD67B4,
                             "BAM: BRS Status Error. No such state\n"));
            return;
    }

        bam_msg_status_ind(st->instanceId, st);
}


/*****************************************************************************
 * FUNCTION
 *  bam_sif_handle_brs_error
 * DESCRIPTION
 *  This function is called when an error has occurred in the BRS (or other module
 *  used by BRS) after a request has been made. A error dialog is raised to the
 *  user.
 * PARAMETERS
 *  id          [IN]        Object id
 *  error       [IN]        Error code as defined in BRS_if.h
 * RETURNS
 *  void
 *****************************************************************************/
void bam_sif_handle_brs_error(MSF_INT16 id, MSF_INT16 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern MSF_INT32 HDIa_getLastError(void);
	MSF_INT32 detail_error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Currently these error codes are ignored since they are minor.
       We can enable them if necessary. */
   // if (error == BRS_ERROR_AUTHENTICATION_CANCELLED ||
   //     error == BRS_ERROR_SECURE_CONNECTION_CANCELLED) 
   // {
   //     return;    
   // }
    
	/* According to Obigo's original design, BRS_ERROR_ABORTED belongs to commnuication error. */
    if(error == BRS_ERROR_AUTHENTICATION)
        return;
    detail_error = HDIa_getLastError();
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_SIF_STATUS_DETAIL_ERROR, "BAM: detail_error = %d", detail_error));
    if (error == BRS_ERROR_HOST_NOT_FOUND && detail_error)
    {
        error = BRS_ERROR_CONNECTION_FAILED;
    }
	if (error == BRS_ERROR_ABORTED)
	{
		error = BRS_ERROR_COMMUNICATION;
	}

	if (error == BRS_ERROR_CONNECTION_FAILED)
	{

		if (detail_error == ABM_E_REJECTED)
		{
			error = WAP_BAM_ERROR_ABM_REJECTED;
		}
	
		if (MSF_NETWORK_ACCOUNT_GET_BEARER(bam_registry_get_int(BAM_SETTING_ID_CON_ACCOUNT)) == HDI_SOCKET_BEARER_GSM_GPRS)
		{
			/* Replace error code with GPRS error if any */
			switch (detail_error)
			{
	    	    case UNKNOWN_APN:
					error = WAP_BAM_ERROR_GPRS_UNKNOWN_APN;
					break;
				case AUTHENTICATION_FAILURE:
					error = WAP_BAM_ERROR_GPRS_AUTHENTICATION_FAILURE;
					break;
		        case UNSUPPORTED_SERVICE_OPTION:
					error = WAP_BAM_ERROR_GPRS_UNSUPPORTED;
					break;
				case UNSUBSCRIBED_SERVICE_OPTION:
					error = WAP_BAM_ERROR_GPRS_NOT_SUBSCRIBED;
					break;
			}
		}
		if (MSF_NETWORK_ACCOUNT_GET_BEARER(bam_registry_get_int(BAM_SETTING_ID_CON_ACCOUNT)) == HDI_SOCKET_BEARER_GSM_CSD)
		{
			/* Replace error code with CSD error if any */
			switch (detail_error)
			{
				case PPPE_AUTH_FAIL:
					error = WAP_BAM_ERROR_CSD_AUTHENTICATION_FAILURE;
					break;
	    	    case ABM_E_CSD_REACTIVATE:
					error = WAP_BAM_ERROR_CSD_REACTIVATE;
					break;
				case ABM_E_CSD_PPP_NEGOTIATED_FAILED:
					error = WAP_BAM_ERROR_CSD_PPP_NEGOTIATED_FAILED;
					break;
		        case ABM_E_CSD_ACT_FAILED:
					error = WAP_BAM_ERROR_CSD_ACT_FAILED;
					break;
				case ABM_E_CSD_CALL_SETUP_FAILED:
					error = WAP_BAM_ERROR_CSD_CALL_SETUP_FAILED;
					break;
			}
		}
	}
    switch(error)
    {
    case BRS_ERROR_INVALID_INPUT:
        error = WAP_BAM_ERROR_INVALID_INPUT;
        break;
    case BRS_ERROR_INVALID_URL:
        error = WAP_BAM_ERROR_INVALID_URL;
        break;
    case BRS_ERROR_INVALID_SCHEME:
        error = WAP_BAM_ERROR_INVALID_SCHEME;
        break;
    case BRS_ERROR_UNKNOWN_CHARSET:
        error = WAP_BAM_ERROR_UNKNOWN_CHARSET;
        break;
    case BRS_ERROR_SYNTAX:
        error = WAP_BAM_ERROR_SYNTAX;
        break;
    case BRS_ERROR_UNKNOWN_DOCTYPE:
        error = WAP_BAM_ERROR_UNKNOWN_DOCTYPE;
        break;
    case BRS_ERROR_UNSUPPORTED_WBXML:
        error = WAP_BAM_ERROR_UNSUPPORTED_WBXML;
        break;
    case BRS_ERROR_UNEXPECTED_END_OF_DOC:
        error = WAP_BAM_ERROR_SYNTAX;
        break;
    case BRS_ERROR_VALIDATION:
        error = WAP_BAM_ERROR_VALIDATION;
        break;
    case BRS_ERROR_ABORTED:
        error = WAP_BAM_ERROR_ABORTED;
        break;
    case BRS_ERROR_REQUIRE_FRAMES:
        error = WAP_BAM_ERROR_REQUIRE_FRAMES;
        break;
    case BRS_ERROR_WMLS:
        error = WAP_BAM_ERROR_WMLS;
        break;
    case BRS_ERROR_WMLS_VERIFICATION:
        error = WAP_BAM_ERROR_WMLS_VERIFICATION;
        break;
    case BRS_ERROR_WMLS_LIB:
        error = WAP_BAM_ERROR_WMLS_LIB;
        break;
    case BRS_ERROR_WMLS_FUNC_ARGS:
        error = WAP_BAM_ERROR_WMLS_FUNC_ARGS;
        break;
    case BRS_ERROR_WMLS_EXTERNAL:
        error = WAP_BAM_ERROR_WMLS_EXTERNAL;
        break;
    case BRS_ERROR_WMLS_LOAD:
        error = WAP_BAM_ERROR_WMLS_LOAD;
        break;
    case BRS_ERROR_WMLS_INTERPRETING:
        error = WAP_BAM_ERROR_WMLS_INTERPRETING;
        break;
    case BRS_ERROR_WMLS_ABORT:
        error = WAP_BAM_ERROR_WMLS_ABORT;
        break;
    case BRS_ERROR_WMLS_EXIT:
        error = WAP_BAM_ERROR_WMLS_EXIT;
        break;
    case BRS_ERROR_ACCESS_RESTRICTIONS_WML:
        error = WAP_BAM_ERROR_ACCESS_RESTRICTIONS_WML;
        break;
    case BRS_ERROR_ACCESS_RESTRICTIONS_WMLS:
        error = WAP_BAM_ERROR_ACCESS_RESTRICTIONS_WMLS;
        break;
    case BRS_ERROR_COMMUNICATION:
        error = WAP_BAM_ERROR_COMMUNICATION;
        break;
    case BRS_ERROR_HOST_NOT_FOUND:
        error = WAP_BAM_ERROR_HOST_NOT_FOUND;
        break;
    case BRS_ERROR_REQUEST_TIMED_OUT:
        error = WAP_BAM_ERROR_REQUEST_TIMED_OUT;
        break;
    case BRS_ERROR_CONNECTION_FAILED:
        error = WAP_BAM_ERROR_CONNECTION_FAILED;
        break;
    case BRS_ERROR_SECURE_CONNECTION_FAILED:
        error = WAP_BAM_ERROR_SECURE_CONNECTION_FAILED;
        break;
    case BRS_ERROR_INTERNAL:
        error = WAP_BAM_ERROR_INTERNAL;
        break;
    case BRS_ERROR_RESEND_POST_WARNING:
        error = WAP_BAM_ERROR_RESEND_POST_WARNING;
        break;
    case BRS_ERROR_OUT_OF_MEMORY:
        error = WAP_BAM_ERROR_OUT_OF_MEMORY;
        break;
    case BRS_ERROR_CONTENT_TOO_LARGE:
        error = WAP_BAM_ERROR_CONTENT_TOO_LARGE;
        break;
    case BRS_ERROR_UNSUPPORTED_SCRIPT_WARNING:
        error = WAP_BAM_ERROR_UNSUPPORTED_SCRIPT_WARNING;
        break;
    case BRS_ERROR_NO_DISPLAY_CONTENT:
        error = WAP_BAM_ERROR_NO_DISPLAY_CONTENT;
        break;
	case BRS_ERROR_FILE_SIZE_TOO_LARGE:
		error = WAP_BAM_ERROR_FILE_SIZE_TOO_LARGE;
		break;
#ifdef __BAIDU_TRANSCODING_SUPPORT__
    case BRS_ERROR_TRANSCODE_PROXY_FAIL:
        error = WAP_BAM_ERROR_PAGE_NOT_FOUND;
        break;
#endif
    default:
        break;
    }
    bam_msg_error_ind(id, error);
}


void bam_sif_set_full_screen_mode(MSF_BOOL is_full_screen)
{
    bam_sif_is_fullscreen = is_full_screen;
}


MSF_BOOL bam_sif_is_full_screen_mode(void)
{
    return bam_sif_is_fullscreen;
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
#if 0
/* under construction !*/
/* under construction !*/
#ifdef MTK_TMP_PATCH /* CR35811 */
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef OWL_ENABLE_FULLSCREEN
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef MTK_TMP_PATCH /* CR35811 */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  bam_sif_navigate
 * DESCRIPTION
 *
 * PARAMETERS
 *  navigation      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_sif_navigate(bam_sif_nav_enum navigation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (navigation)
    {
        case BAM_SIF_NAV_REFRESH:
            BRSif_reload(MSF_MODID_BAM, bam_sif_instance_id);
            break;

        case BAM_SIF_NAV_FORWARD:
            BRSif_move(MSF_MODID_BAM, bam_sif_instance_id, BRS_MOVE_FORWARD, 1);
            break;

        case BAM_SIF_NAV_BACKWARD:
            BRSif_move(MSF_MODID_BAM, bam_sif_instance_id, BRS_MOVE_BACKWARD, 1);
            break;
    }
}
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
/*************************************
 * Document info
 *************************************/
/*****************************************************************************
 * FUNCTION
 *  bam_not_add_to_history
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_sif_set_add_to_history_setting(int status)
{
    bam_sif_add_to_history=status;

}

#endif 
/*****************************************************************************
 * FUNCTION
 *  bam_sif_handle_brs_doc_info
 * DESCRIPTION
 *  When a request is completed the BRS send information about the loaded request.
 *  this function handles such information e.g. Title and url. This function also
 *  remove any previous Do-Elements which now are obsolete
 * PARAMETERS
 *  p       [IN]    Pointer to document info structure (brs_document_info_t)
 * RETURNS
 *  void
 *****************************************************************************/
void bam_sif_handle_brs_doc_info(brs_document_info_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Remove any do-elements on previous page */
#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
    bam_do_elem_remove();
#endif

    if (p->flags/* & BRS_INFO_FLAG_MAIN_WINDOW*/)
    {

        /* New document info */
        if (bam_sif_current_doc_info)
        {
            //MSF_SIGNAL_DESTRUCT(MSF_MODID_BAM, BRS_SIG_DOCUMENT_INFO, bam_sif_current_doc_info);
			BAM_FREE(bam_sif_current_doc_info->title);
		BAM_FREE(bam_sif_current_doc_info->url);
		BAM_FREE(bam_sif_current_doc_info);
        }
        bam_sif_current_doc_info = p;
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
        /* Add page to access history */
		//bam_sif_add_to_history=1;
        if(bam_sif_add_to_history)
        {
        bam_hist_add_item(p->url, p->title);
        }
#endif 
		if (bam_sif_document_security_id != p->securityId)
		{
			bam_sif_document_security_id = p->securityId;
			
	    #ifdef WAP_SEC_SUPPORT
    	#ifdef MSF_MODID_SES

        	if (p->securityId >= 0)
	        {
    	        /* This call will result in a call to bam_sif_set_security_class() */
        	    SESif_getCurrentSecClass(MSF_MODID_BAM, bam_sif_get_brs_id(), p->securityId);
	        }
    	    else
        	{
            	bam_sif_set_security_class(0);
	        }

    	#endif /* MSF_MODID_SES */
	    #endif /* WAP_SEC_SUPPORT */
		}

    }
    p->flags |= BRS_INFO_FLAG_MAIN_WINDOW;
    bam_msg_document_info_ind(p->instanceId, p);
}

int bam_sif_doc_get_size(void)
{
    if (bam_sif_current_doc_info) 
    {
        return bam_sif_current_doc_info->size;
    }
    else 
    {
        return 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  bam_sif_handle_brs_set_title_string
 * DESCRIPTION
 *  When the title of render page need to be updated due to JaveScript execution,
 *  BRS will notify BAM and then BAM will notify Browser APP to update title. 
 *  This function is used to handle this case.
 * PARAMETERS
 *  p       [IN]    Pointer to set title string structure (brs_set_title_string_t)
 * RETURNS
 *  void
 *****************************************************************************/
void bam_sif_handle_brs_set_title_string(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_msg_notify_app_ind(wap_bam_notify_app_set_title_string, p);
}

/*************************************
 * Element in focus
 *************************************/


/*****************************************************************************
 * FUNCTION
 *  bam_sif_element_focused
 * DESCRIPTION
 *  This function is called from the BRS (via Signals) when an content element is selected
 * PARAMETERS
 *  p       [IN]    Information about the selected element
 * RETURNS
 *  void
 *****************************************************************************/
void bam_sif_element_focused(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_sif_current_element)
    {
       // MSF_SIGNAL_DESTRUCT(MSF_MODID_BAM, BRS_SIG_ELEMENT_FOCUSED, bam_sif_current_element);
		BAM_FREE(bam_sif_current_element->object_filePath);
		BAM_FREE(bam_sif_current_element->title);
        BAM_FREE(bam_sif_current_element->url);
		BAM_FREE(bam_sif_current_element->object_url);
		BAM_FREE(bam_sif_current_element->object_mime);
		BAM_FREE(bam_sif_current_element);
    }

    bam_sif_current_element = (brs_element_focused_t*) p;
#ifndef BRS_CFG_CACHE_SINGLE_CONTENT_FILE
	if (bam_sif_current_element && bam_sif_select_mode_is_enabled())
	{
		if (bam_sif_current_element->object_filePath && 
            (MSF_FILE_EXIST (bam_sif_current_element->object_filePath) == HDI_FILE_ERROR_PATH))
		{
			BAM_FREE(bam_sif_current_element->object_filePath);
			bam_sif_current_element->object_filePath = NULL;
		}
	}
#endif
    bam_msg_element_focused_ind(bam_sif_get_brs_id(), bam_sif_current_element);
}


/*****************************************************************************
 * FUNCTION
 *  bam_sif_object_is_downloadable
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
MSF_BOOL bam_sif_object_is_downloadable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Note: BRS_FOCUSED_ELEMENT_IMAGE actually represent images AND objects. */
    if (bam_sif_current_element &&
/*        bam_sif_current_element->type == BRS_FOCUSED_ELEMENT_IMAGE &&*/
        bam_sif_current_element->object_filePath &&
        strlen(bam_sif_current_element->object_filePath) &&
        /*(MSF_FILE_EXIST(bam_sif_current_element->object_filePath) != HDI_FILE_ERROR_PATH) &&*/
        !(bam_sif_current_element->drm_restriction/* & BRS_FOCUSED_ELEM_DRM_RESTRICTION_NO_SAVE*/))
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
 *  bam_sif_object_is_form_elements
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
MSF_BOOL bam_sif_object_is_form_elements(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_sif_current_element &&
        (bam_sif_current_element->type == BRS_FOCUSED_ELEMENT_TEXTINPUT ||
         bam_sif_current_element->type == BRS_FOCUSED_ELEMENT_SELECT ||
         bam_sif_current_element->type == BRS_FOCUSED_ELEMENT_INPUT ||
         bam_sif_current_element->type == BRS_FOCUSED_ELEMENT_BUTTON ||
         bam_sif_current_element->type == BRS_FOCUSED_ELEMENT_SUBMIT ||
         bam_sif_current_element->type == BRS_FOCUSED_ELEMENT_RESET ||
         bam_sif_current_element->type == BRS_FOCUSED_ELEMENT_FILE_INPUT ||
//         bam_sif_current_element->type == BRS_FOCUSED_ELEMENT_INPUT_SELECTED ||
//         bam_sif_current_element->type == BRS_FOCUSED_ELEMENT_INPUT_UNSELECTED ||
         bam_sif_current_element->type == BRS_FOCUSED_ELEMENT_AREA))
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
 *  bam_sif_focused_element_is_link
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
MSF_BOOL bam_sif_focused_element_is_link(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_sif_current_element && bam_sif_current_element->type == BRS_FOCUSED_ELEMENT_LINK)
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
 *  bam_sif_focused_element_is_select
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
MSF_BOOL bam_sif_focused_element_is_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_sif_current_element && bam_sif_current_element->type == BRS_FOCUSED_ELEMENT_SELECT)
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
 *  bam_sif_object_get_title
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
const char *bam_sif_object_get_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_sif_current_element)
    {
        return bam_sif_current_element->title;
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_sif_object_get_drm
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
MSF_INT16 bam_sif_object_get_drm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_sif_current_element)
    {
        return bam_sif_current_element->drm_restriction;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_sif_object_get_file_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
const char *bam_sif_object_get_file_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_sif_current_element)
    {
        return bam_sif_current_element->object_filePath;
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_sif_object_get_mime
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
const char *bam_sif_object_get_mime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_sif_current_element)
    {
        return bam_sif_current_element->object_mime;
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_sif_object_get_url
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
const char *bam_sif_object_get_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_sif_current_element)
    {
        return bam_sif_current_element->object_url;
    }
    else
    {
        return NULL;
    }
}

/*************************************
 * Select mode
 *************************************/
#ifdef BAM_CFG_SELECT_MODE

//#include "owl_core.h"


/*****************************************************************************
 * FUNCTION
 *  bam_sif_enable_select_mode
 * DESCRIPTION
 *  Set the navigation mode.
 * PARAMETERS
 *  mode        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_sif_enable_select_mode(MSF_INT16 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_sif_select_mode != mode)
    {
        bam_sif_select_mode = mode;

        if(mode == WAP_BAM_FOCUSABLE_ELEMENTS_OBJECT_MODE)
            BRSif_navigationChange(MSF_MODID_BAM, bam_sif_instance_id, BRS_MARKABLE_ELEMENT_IMG | BRS_MARKABLE_ELEMENT_OBJECT | BRS_MARKABLE_ELEMENT_INPUT_IMAGE);
        else
            BRSif_navigationChange(MSF_MODID_BAM, bam_sif_instance_id, BRS_MARKABLE_ELEMENT_DEFAULT);

        /* We should not call owl_core_send_notification() directly in BAM. */
        //owl_core_send_notification(bam_sif_brs_paintbox, MsfNotifyLostFocus);
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_sif_select_mode_is_enabled
 * DESCRIPTION
 *  Check if browser is in select mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  FALSE = select mode off
 *  TRUE  = select mode on
 *****************************************************************************/
MSF_BOOL bam_sif_select_mode_is_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (bam_sif_select_mode & WAP_BAM_FOCUSABLE_ELEMENTS_OBJECT_MODE);
}

#endif /* BAM_CFG_SELECT_MODE */

/*************************************
 * Offline mode
 *************************************/
#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  bam_sif_offline_mode_is_enabled
 * DESCRIPTION
 *  Check if browser is in offline mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  FALSE = offline mode off
 *  TRUE  = offline mode on
 *****************************************************************************/
MSF_BOOL bam_sif_offline_mode_is_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_sif_current_doc_info && (bam_sif_current_doc_info->flags /*& BRS_INFO_FLAG_SAVED_PAGE*/))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

#endif /* MSF_CFG_OFFLINE_PAGES_SUPPORT */

void bam_sif_set_holding_bearer(MSF_BOOL is_holding, MSF_INT32 net_acc_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	bam_sif_holding_bearer = is_holding;
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT

	if (bam_sif_holding_bearer == TRUE)
	{
		bam_cmn_hold_bearer(net_acc_id);
	}
	else
	{
		bam_cmn_release_bearer(net_acc_id);
	}
#endif 
}

MSF_BOOL bam_sif_is_holding_bearer(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return bam_sif_holding_bearer;
}

void bam_sif_set_navigating_internet(MSF_BOOL navigated)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	bam_sif_navigating_internet = navigated;
}

MSF_BOOL bam_sif_is_navigating_internet(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return bam_sif_navigating_internet;
}

/*****************************************************************************
 * FUNCTION
 *  bam_sif_get_brs_paintbox
 * DESCRIPTION
 *  This function is used to get the paintbox previously returned in
 *  a request to instantiate the BRS
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
MsfWindowHandle bam_sif_get_brs_paintbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return bam_sif_brs_paintbox;
}


#endif /*OBIGO_Q03C_BROWSER*/

const char* bam_sif_get_https_pgdl_support()
{
#ifdef OBIGO_Q03C_BROWSER
    return BAM_SIF_HTTPS_PGDL_SUPPORT;
#else
    return "";
#endif
}
const char* bam_sif_get_hw_release_version()
{
#ifdef OBIGO_Q03C_BROWSER
    return BAM_SIF_HW_RELEASE_VER;
#else
    return "";
#endif
}
const char* bam_sif_get_release_version()
{
#ifdef OBIGO_Q03C_BROWSER
    return BAM_SIF_RELEASE_VERSION;
#else
    return "";
#endif
}
const char* bam_sif_get_build_date_and_time()
{
#ifdef OBIGO_Q03C_BROWSER
    return BAM_SIF_BUILD_DATE_TIME;
#else
    return "";
#endif
}
const char* bam_sif_get_j2me_midp_version()
{
#ifdef OBIGO_Q03C_BROWSER
    return BAM_SIF_J2ME_MIDP_VERSION;
#else
    return "";
#endif
}
const char* bam_sif_get_j2me_cldc_version()
{
#ifdef OBIGO_Q03C_BROWSER
    return BAM_SIF_J2ME_CLDC_VERSION;
#else
    return "";
#endif
}
const char* bam_sif_get_language()
{
#ifdef OBIGO_Q03C_BROWSER
    return BAM_SIF_LANGUAGE_CODE;
#else
    return "";
#endif
}
