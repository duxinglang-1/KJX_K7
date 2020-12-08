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
 *   bam_sif.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*
 * bam_sif.h
 *
 * This file contain the BAM Services Interface, E.g. the functionality
 * needed to handle signals from BRS is ipmlemented here
 * internal signal receive funtion.
 *
 */
#ifndef _bam_sif_h

#define _bam_sif_h

#include "brs_if.h"

#include "bam_cfg.h"

/************************************************************
 * Constants
 ************************************************************/
#define BAM_SIF_OBJECT_TYPE_VIEW 1
#define BAM_SIF_OBJECT_TYPE_PLAY 2
#define BAM_SIF_OBJECT_TYPE_ACTIVATE 3

/*** BRS module state ***/

/* Not started */
#define BAM_SIF_BRS_NOT_ACTIVE 1
/* Module is starting */
#define BAM_SIF_BRS_ACTIVATED  2
/* Module is started */
#define BAM_SIF_BRS_MOD_ACTIVE_NO_INST     3
/* Creating instance */
#define BAM_SIF_BRS_CREATING   4
/* Instance is created. BRS can now be used. */
#define BAM_SIF_BRS_READY    5
/* Instance is being deleted */
#define BAM_SIF_BRS_DELETING_INSTANCE 6
/* BRS module is terminating */
#define BAM_SIF_BRS_TERMINATING 7

/************************************************************
 * Type definitions
 ************************************************************/

typedef enum
{
    BAM_SIF_NAV_REFRESH,
    BAM_SIF_NAV_FORWARD,
    BAM_SIF_NAV_BACKWARD
} bam_sif_nav_enum;

/************************************************************
 * Functions
 ************************************************************/
extern void bam_sif_init(void);

extern void bam_sif_terminate(void);

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

extern void bam_sif_set_security_class(int sec_class);

#endif /* MSF_MODID_SES */

#endif /* WAP_SEC_SUPPORT */

/*
 * This function will call the MSF macros to try and start the BRS module
 *
 * PARAMETERS
 *
 * RETURN    : void
 */

extern void bam_sif_start_brs(void);

extern MSF_INT32 bam_sif_get_terminate_mode(void);

/*
 * Terminates the BRS module.
 *
 * PARAMETERS
 *
 * RETURN    : FALSE if delayed
 */
extern MSF_BOOL bam_sif_brs_terminate(MSF_UINT8 mode);

/*
 * This function is called when the BAM receives MSF_SIG_MODULE_STATUS
 * with modID BRS.
 *
 * PARAMETERS
 *
 * status    : MSF module status.
 *
 * RETURN    : void
 */
extern void bam_sif_module_status(MSF_UINT8 status);

/*
 * This function must be called when a request to instantiate the BRS has
 * returned. If there is a pending request this will be issued now.
 *
 * PARAMETERS
 *
 * p         : Pointer to signal structure
 *
 * RETURN    : void
 */
extern void bam_sif_brs_instance_created(brs_created_t *instance);

/*
 * This function is called when BRS_SIG_INSTANCE_DELETED is received.
 *
 * PARAMETERS
 *
 * inst_id   : BRS instance ID
 *
 * RETURN    : void
 */
extern void bam_sif_brs_instance_deleted(MSF_INT16 inst_id);

/*
 * This function is used to set the assumed state of the BRS
 *
 * PARAMETERS
 *
 * status    : Current state as defined above
 *
 * RETURN    : void
 */
extern void bam_sif_set_brs_status(int status);

/*
 * Returns the currently assumed BRS state
 *
 * PARAMETERS
 *
 * RETURN    : BRS state
 */
extern int bam_sif_get_brs_status(void);

/*
 * Indicate whether BRS is ready and idle
 *
 * PARAMETERS
 *
 * RETURN    : TRUE for idle, otherwise FALSE.
 */
extern MSF_BOOL bam_sif_brs_is_idle(void);

/*
 * This function is used to get the object Id previously returned in
 * a request to instantiate the BRS
 *
 * PARAMETERS
 *
 * RETURN    :
 */
extern MSF_INT16 bam_sif_get_brs_id(void);

extern MSF_INT32 bam_sif_get_brs_security_id(void);
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT  /*recent pages */

extern void bam_sif_set_add_to_history_setting(int status);
#endif 

extern MSF_INT32 bam_sif_get_current_page_size(void);

/*
 * This function is called when the BAM receives a status notification from
 * the BRS. This information is used to update the status bar.
 *
 * PARAMETERS
 *
 * p         : Pointer to status structure (brs_status_t)
 *
 * RETURN    : void
 */
extern void bam_sif_handle_brs_status(void *p);

/*
 * This function is called when an error has occurred in the BRS (or other module
 * used by BRS) after a request has been made. A error dialog is raised to the
 * user.
 *
 * PARAMETERS
 *
 * id        : object id
 * error     : Error code as defined in BRS_if.h
 *
 * RETURN    : void
 */
extern void bam_sif_handle_brs_error(MSF_INT16 id, MSF_INT16 error);

extern void bam_sif_set_full_screen_mode(MSF_BOOL is_full_screen);

extern MSF_BOOL bam_sif_is_full_screen_mode(void);

extern void bam_sif_resize_browser(MSF_UINT16 bottom_y_offset, MSF_BOOL is_full_screen);

extern void bam_sif_navigate(bam_sif_nav_enum navigation);

/*************************************
 * Document info
 *************************************/
/*
 * When a request is completed the BRS send information about the loaded request.
 * this function handles such information e.g. Title and url. This function also
 * remove any previous Do-Elements which now are obsolete
 *
 * PARAMETERS
 *
 * p         : Pointer to document info structure (brs_document_info_t)
 *
 * RETURN    :
 */
extern void bam_sif_handle_brs_doc_info(brs_document_info_t *p);

extern int bam_sif_doc_get_size(void);

extern void bam_sif_handle_brs_set_title_string(void *p);
    
/*************************************
 * Element in focus
 *************************************/
/*
 * This function is called from the BRS (via Signals) when an content element is selected
 *
 * PARAMETERS
 *
 * p         : Information about the selected element
 *
 * RETURN    : void
 */
extern void bam_sif_element_focused(void *p);

extern MSF_BOOL bam_sif_object_is_downloadable(void);

extern MSF_BOOL bam_sif_object_is_form_elements(void);

extern MSF_BOOL bam_sif_focused_element_is_link(void);

extern MSF_BOOL bam_sif_focused_element_is_select(void);

extern const char *bam_sif_object_get_title(void);

extern MSF_INT16 bam_sif_object_get_drm(void);

extern const char *bam_sif_object_get_file_path(void);

extern const char *bam_sif_object_get_mime(void);

extern const char *bam_sif_object_get_url(void);

/*************************************
 * Select mode
 *************************************/
#ifdef BAM_CFG_SELECT_MODE
/*
 * Set the navigation mode.
 *
 * PARAMETERS
 *
 * mode       :
 *
 * RETURN    : void
 */

extern void bam_sif_enable_select_mode(MSF_INT16 mode);

/*
 * Check if browser is in select mode.
 *
 * PARAMETERS
 *
 * RETURN    : FALSE = select mode off
 *             TRUE  = select mode on
 *
 */
extern MSF_BOOL bam_sif_select_mode_is_enabled(void);

#endif /* BAM_CFG_SELECT_MODE */

/*************************************
 * Offline mode
 *************************************/
#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT

/*
 * Check if browser is in offline mode.
 *
 * PARAMETERS
 *
 * RETURN    : FALSE = offline mode off
 *             TRUE  = offline mode on
 *
 */

extern MSF_BOOL bam_sif_offline_mode_is_enabled(void);

#endif /* MSF_CFG_OFFLINE_PAGES_SUPPORT */

extern void bam_sif_set_holding_bearer(MSF_BOOL is_holding, MSF_INT32 net_acc_id);

extern MSF_BOOL bam_sif_is_holding_bearer(void);

extern void bam_sif_set_navigating_internet(MSF_BOOL navigated);

extern MSF_BOOL bam_sif_is_navigating_internet(void);

/*
 * Get the paintbox previously returned in a request to instantiate the BRS
 *
 * PARAMETERS
 *
 * RETURN    : BRS paintbox
 */
extern MsfWindowHandle bam_sif_get_brs_paintbox(void);

#endif /* _bam_sif_h */


#endif /*OBIGO_Q03C_BROWSER*/
