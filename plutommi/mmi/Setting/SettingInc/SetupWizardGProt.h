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
 *  SetupWizardGProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface of setup wizard.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MMI_SETUP_WIZARD_H__
#define __MMI_SETUP_WIZARD_H__

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_include.h"


// TODO: Enclose by dependency
#define __MMI_SETUP_WIZARD__


#ifdef __MMI_SETUP_WIZARD__

/****************************************************************************
 * Typedef
 ****************************************************************************/

/*
 * DESCRIPTION
 *  Instance handle of a step.
 */
typedef void *mmi_setwiz_step_handle;

#define MMI_SETWIZ_STEP_INVALID_HANDLE NULL

/*
 * DESCRIPTION
 *  ID of a step.
 */
typedef S32 mmi_setwiz_step_id;


/*
 * DESCRIPTION
 *  Parameter to create a step instance.
 */
typedef struct
{
    /*
     * Screen group ID of the setup wizard. If the step screens support screen group,
     * this ID can be used for the group ID. Otherwise it can be ignored.
     * We recommend application should support screen group.
     */
    mmi_id grp_id;

    /* User data. This data shall be carried on any event to the setup wizard */
    void *user_data;
    
    /* Step ID. This ID shall be carried on any event to the setup wizard. */
    mmi_setwiz_step_id step_id;
} mmi_setwiz_step_create_param_struct;


/*****************************************************************************
 * <GROUP CallbackFunctions>
 *
 * FUNCTION
 *  mmi_setwiz_step_create_func
 * DESCRIPTION
 *  Create an instance of a step of setup wizard.
 * PARAMETERS
 *  param       : [IN] Parameter to create the instance
 * RETURNS
 *  The handle of the instance created
 *****************************************************************************/
typedef mmi_setwiz_step_handle (*mmi_setwiz_step_create_func)(
    const mmi_setwiz_step_create_param_struct* param);


/*****************************************************************************
 * <GROUP CallbackFunctions>
 *
 * FUNCTION
 *  mmi_setwiz_step_run_func
 * DESCRIPTION
 *  Display the screen of the step.
 *  Note that a step shall NOT close its screens automatically unless setup
 *  wizard calls its close function definitely.
 * PARAMETERS
 *  handle      : [IN] The instance
 * RETURNS
 *  void
 * SEE ALSO
 *  mmi_setwiz_step_close_func
 *****************************************************************************/
typedef void (*mmi_setwiz_step_run_func)(mmi_setwiz_step_handle handle);


/*****************************************************************************
 * <GROUP CallbackFunctions>
 *
 * FUNCTION
 *  mmi_setwiz_step_close_func
 * DESCRIPTION
 *  Close the screens and destroy the instance.
 * PARAMETERS
 *  handle      : [IN] The instance
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*mmi_setwiz_step_close_func)(mmi_setwiz_step_handle handle);


/*
 * DESCRIPTION
 *  Event ID of setup wizard steps.
 *  These events are emitted from each step to setup wizard. Please always use
 *  MMI_SEND_EVENT() or MMI_POST_EVENT() to emit the events to mmi_setwiz_step_notify_event().
 *  MMI_EMIT_EVENT() or MMI_EMIT_POST_EVENT() is NOT allowed.
 */
typedef enum
{
    /*
     * Go to next step.
     * Structure: mmi_setwiz_step_next_evt_struct
     * See mmi_setwiz_step_notify_event() for example.
     */
    EVT_ID_SETWIZ_STEP_NEXT,

    /*
     * User selected to exit setup wizard.
     * Structure: mmi_setwiz_step_exit_selected_evt_struct
     * See mmi_setwiz_step_notify_event() for example.
     */
    EVT_ID_SETWIZ_STEP_EXIT_SELECTED,

    /*
     * Step screen received any delete/close request from framework
     * but NOT BY THE CLOSE FUNCTION REGISTERED. This is used to notify
     * the step is closed abnormally. If the step received a close/delete
     * but decide not to close, this event SHALL NOT be emitted. If
     * the step is closed by the close function registered, this event
     * SHALL NOT be emitted either.
     * Setup wizard will not call the close function for this event,
     * The wizard flow will be stoped by this event.
     */
    EVT_ID_SETWIZ_STEP_ABNORMAL_CLOSED,

    EVT_ID_SETWIZ_STEP_END_OF_ENUM
} mmi_setwiz_step_evt_id_enum;


/*
 * DESCRIPTION
 *  Event structure of EVT_ID_SETWIZ_STEP_NEXT
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_setwiz_step_id step_id; /* Step ID */
} mmi_setwiz_step_next_evt_struct;

/*
 * DESCRIPTION
 *  Event structure of EVT_ID_SETWIZ_STEP_EXIT_SELECTED
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_setwiz_step_id step_id; /* Step ID */
} mmi_setwiz_step_exit_selected_evt_struct;


/*
 * DESCRIPTION
 *  Event structure of EVT_ID_SETWIZ_STEP_ABNORMAL_CLOSED
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_setwiz_step_id step_id; /* Step ID */
} mmi_setwiz_step_abnormal_closed_evt_struct;


/*****************************************************************************
 * FUNCTION
 *  mmi_setwiz_step_close_func
 * DESCRIPTION
 *  Notify setup wizard that any event of step.
 *  This function only accepts STEP_NEXT or STEP_EXIT event.
 *  Please use MMI_SEND_EVENT() or MMI_POST_EVENT() to invoke this function.
 * PARAMETERS
 *  evt     : [IN] mmi_setwiz_step_next_evt_struct*  or
 *                 mmi_setwiz_step_exit_selected_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 * SEE ALSO
 *  EVT_ID_SETWIZ_STEP_NEXT, EVT_ID_SETWIZ_STEP_EXIT_SELECTED
 * EXAMPLE
 * <code>
 *  SetRightSoftkeyHandler(mmi_app_setwiz_exit);
 *
 *  void mmi_app_setwiz_exit(void)
 *  {
 *      g_mmi_app_cntx *cntx;
 *      mmi_setwiz_step_exit_selected_evt_struct exit_evt;
 *
 *      cntx = (g_mmi_app_cntx*)mmi_frm_scrn_get_user_data(mmi_frm_group_get_active_id(), SCR_ID_APP_SETUP);
 *      MMI_INIT_EVENT(&exit_evt, EVT_ID_SETWIZ_STEP_EXIT_SELECTED);
 *      exit_evt.step_id = cntx->setwiz_step_id;
 *      MMI_POST_EVENT(&exit_evt, mmi_setwiz_step_notify_event, cntx->setwiz_user_data);
 *  }
 * </code>
 *****************************************************************************/
extern mmi_ret mmi_setwiz_step_notify_event(mmi_event_struct *evt);


/*****************************************************************************
 * <GROUP CallbackFunctions>
 *
 * FUNCTION
 *  mmi_setwiz_completed_callback
 * DESCRIPTION
 *  Callback for setup wizard completed
 * PARAMETERS
 *  user_data       : [IN] The data passed into mmi_setwiz_launch
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*mmi_setwiz_completed_callback)(void *user_data);


/*****************************************************************************
 * FUNCTION
 *  mmi_setwiz_launch
 * DESCRIPTION
 *  Launch setup wizard. Only bootup or Idle module can call this function.
 * PARAMETERS
 *  completed_callback  : [IN] Callback for completed
 *  user_data           : [IN] To be passed into completed_callback()
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_setwiz_launch(
                mmi_setwiz_completed_callback completed_callback,
                void *user_data);


#endif /* __MMI_SETUP_WIZARD__ */

#endif /* __MMI_SETUP_WIZARD_H__ */
 
