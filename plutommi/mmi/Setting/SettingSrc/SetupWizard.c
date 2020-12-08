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
 *  SetupWizard.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Core of setup wizard.
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

/****************************************************************************
 * Include
 ****************************************************************************/

#include "SetupWizardGProt.h"

#ifdef __MMI_SETUP_WIZARD__

#include "SettingResDef.h"

/* Header files of steps */
/* #include "XXXGprot.h" below here */



//#define __MMI_SETWIZ_UNIT_TEST__
#ifdef __MMI_SETWIZ_UNIT_TEST__
static mmi_setwiz_step_handle mmi_setwiz_test_create(
    const mmi_setwiz_step_create_param_struct* param);
static void mmi_setwiz_test_run(mmi_setwiz_step_handle handle);
static void mmi_setwiz_test_close(mmi_setwiz_step_handle handle);
#endif


/****************************************************************************
 * Configurations
 ****************************************************************************/

typedef struct
{
    mmi_setwiz_step_create_func create;
    mmi_setwiz_step_run_func run;
    mmi_setwiz_step_close_func close;
} mmi_setwiz_step_struct;

static const mmi_setwiz_step_struct g_mmi_setwiz_steps[] =
{
    /*
     * The lifecycle of a step is create() -> run() -> close(), all
     * functions should be provided and NULL is not acceptable.
     * For the prototype and meaning of each functions, please refer to
     * SetupWizardGProt.h
     */
    /* ------------ Please fill your entry below this line ------------ */
#ifdef __MMI_SETWIZ_UNIT_TEST__
    {
        mmi_setwiz_test_create,
        mmi_setwiz_test_run,
        mmi_setwiz_test_close
    },
#endif
     
    /* ------------ Please fill your entry above this line ------------ */
    { NULL, NULL, NULL }
};

static const S32 g_mmi_setwiz_steps_size =
    sizeof(g_mmi_setwiz_steps) / sizeof(g_mmi_setwiz_steps[0]);


/****************************************************************************
 * Implementation
 ****************************************************************************/

#define MMI_SETWIZ_TRACE_GROUP MMI_COMMON_TRC_G7_SETTING

typedef struct
{
    mmi_setwiz_completed_callback completed_callback;
    void *user_data;
    mmi_id grp_id;
    S16 running_index;
    mmi_setwiz_step_handle running_handle;
} mmi_setwiz_cntx_struct;

static mmi_setwiz_cntx_struct g_mmi_setwiz_cntx;


/*****************************************************************************
 * FUNCTION
 *  mmi_setwiz_notify_completed
 * DESCRIPTION
 *  Call completed callback
 * PARAMETERS
 *  cntx        [IN] Context
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_setwiz_notify_completed(mmi_setwiz_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_SETWIZ_TRACE_GROUP, TRC_MMI_SETWIZ_COMPLETED,
        cntx->running_index, (g_mmi_setwiz_steps_size - 1));
    
    if (cntx->completed_callback != NULL)
    {
        cntx->completed_callback(cntx->user_data);
        cntx->completed_callback = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_setwiz_run_next
 * DESCRIPTION
 *  Execute next step
 * PARAMETERS
 *  cntx        [IN] Context
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_setwiz_run_next(mmi_setwiz_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_setwiz_step_create_param_struct create_param;
    const mmi_setwiz_step_struct *step;
    S32 previous_index;
    mmi_setwiz_step_handle previous_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    previous_index = cntx->running_index;
    previous_handle = cntx->running_handle;
    
    cntx->running_index++;
    MMI_EXT_ASSERT(cntx->running_index >= 0 && cntx->running_index < g_mmi_setwiz_steps_size,
        cntx->running_index, g_mmi_setwiz_steps_size, 0);
        
    step = &(g_mmi_setwiz_steps[cntx->running_index]);

    if (step->create != NULL)
    {
        MMI_TRACE(MMI_SETWIZ_TRACE_GROUP, TRC_MMI_SETWIZ_RUN_NEXT, cntx->running_index, (U32)(step->run));
        
        create_param.grp_id = cntx->grp_id;
        create_param.step_id = cntx->running_index;
        create_param.user_data = (void*)cntx;
        cntx->running_handle = step->create(&create_param);
        /* Application should give a valid handle */
        MMI_EXT_ASSERT(cntx->running_handle != MMI_SETWIZ_STEP_INVALID_HANDLE,
            cntx->running_index, 0, 0);

        MMI_EXT_ASSERT(step->run != NULL && step->close != NULL,
            cntx->running_index, (U32)(step->run), (U32)(step->close));
        step->run(cntx->running_handle);
    }
    else
    {
        /* Callback before screen closed to avoid flicker */
        mmi_setwiz_notify_completed(cntx);
    }

    if (previous_index >= 0 &&
        previous_handle != MMI_SETWIZ_STEP_INVALID_HANDLE)
    {
        g_mmi_setwiz_steps[previous_index].close(previous_handle);
    }

    if (step->create == NULL)
    {
        mmi_frm_group_close(cntx->grp_id);
    }
}


/*****************************************************************************
 * Please refer to SetupWizardGprot.h
 *****************************************************************************/
mmi_ret mmi_setwiz_step_notify_event(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_setwiz_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &(g_mmi_setwiz_cntx);

    /* Application should pass the user_data to this handler */
    MMI_EXT_ASSERT(evt->user_data == cntx, evt->evt_id, (U32)evt->user_data, (U32)cntx);

    if (evt->evt_id == EVT_ID_SETWIZ_STEP_NEXT)
    {
        const mmi_setwiz_step_next_evt_struct *next_evt;

        next_evt = (const mmi_setwiz_step_next_evt_struct*)evt;
        MMI_EXT_ASSERT(next_evt->step_id == cntx->running_index,
            next_evt->step_id, cntx->running_index, 0);

        MMI_TRACE(MMI_SETWIZ_TRACE_GROUP, TRC_MMI_SETWIZ_STEP_NOTIFY_EVENT,
            next_evt->evt_id, next_evt->step_id);

        mmi_setwiz_run_next(cntx);
    }
    else if (evt->evt_id == EVT_ID_SETWIZ_STEP_EXIT_SELECTED)
    {
        const mmi_setwiz_step_exit_selected_evt_struct *exit_evt;

        exit_evt = (const mmi_setwiz_step_exit_selected_evt_struct*)evt;
        MMI_EXT_ASSERT(exit_evt->step_id == cntx->running_index,
            exit_evt->step_id, cntx->running_index, 0);
        MMI_TRACE(MMI_SETWIZ_TRACE_GROUP, TRC_MMI_SETWIZ_STEP_NOTIFY_EVENT,
            exit_evt->evt_id, exit_evt->step_id);
            
        MMI_TRACE(MMI_SETWIZ_TRACE_GROUP, TRC_MMI_SETWIZ_COMPLETED,
            cntx->running_index, (g_mmi_setwiz_steps_size - 1));

        /* Callback before screen closed to avoid flicker */
        mmi_setwiz_notify_completed(cntx);

        g_mmi_setwiz_steps[cntx->running_index].close(cntx->running_handle);

        mmi_frm_group_close(cntx->grp_id);
    }
    else if (evt->evt_id == EVT_ID_SETWIZ_STEP_ABNORMAL_CLOSED)
    {
        const mmi_setwiz_step_abnormal_closed_evt_struct *close_evt;

        close_evt = (const mmi_setwiz_step_abnormal_closed_evt_struct*)evt;
        MMI_EXT_ASSERT(close_evt->step_id == cntx->running_index,
            close_evt->step_id, cntx->running_index, 0);
        MMI_TRACE(MMI_SETWIZ_TRACE_GROUP, TRC_MMI_SETWIZ_STEP_NOTIFY_EVENT,
            close_evt->evt_id, close_evt->step_id);

        mmi_setwiz_notify_completed(cntx);
    }
    else

    {
        MMI_EXT_ASSERT(MMI_FALSE, evt->evt_id, 0, 0);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_setwiz_group_event_hdlr
 * DESCRIPTION
 *  Proc function of screen group events.
 * PARAMETERS
 *  cntx        [IN] Context
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_setwiz_group_event_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_setwiz_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &(g_mmi_setwiz_cntx);

    if (evt->evt_id == EVT_ID_GROUP_DEINIT)
    {   
        /*
         * To protect that the case of the active step did not emit
         * EVT_ID_SETWIZ_STEP_ABNORMAL_CLOSED
         */
        if (cntx->completed_callback != NULL)
        {
            mmi_setwiz_notify_completed(cntx);
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * Please refer to SetupWizardGprot.h
 *****************************************************************************/
void mmi_setwiz_launch(
        mmi_setwiz_completed_callback completed_callback,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_setwiz_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_SETWIZ_TRACE_GROUP, TRC_MMI_SETWIZ_LAUNCH, (U32)completed_callback);
    
    cntx = &(g_mmi_setwiz_cntx);
    
    cntx->completed_callback = completed_callback;
    cntx->user_data = user_data;
    cntx->running_index = -1;
    cntx->running_handle = MMI_SETWIZ_STEP_INVALID_HANDLE;
    cntx->grp_id = GRP_ID_SETUP_WIZARD;

    mmi_frm_group_create(GRP_ID_ROOT, cntx->grp_id, mmi_setwiz_group_event_hdlr, cntx);
    mmi_frm_group_enter(cntx->grp_id, MMI_FRM_NODE_NONE_FLAG);
    
    mmi_setwiz_run_next(cntx);
}



/*****************************************************************************
 * [Unit test]
 *
 *
 *****************************************************************************/

#ifdef __MMI_SETWIZ_UNIT_TEST__

typedef struct
{
    mmi_id grp_id;
    mmi_id scr_id;
    void *user_data;
    mmi_setwiz_step_id step_id;
    WCHAR text[20];
} mmi_setwiz_test_cntx_struct;


static mmi_ret mmi_setwiz_test_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_setwiz_test_cntx_struct *cntx;
    mmi_setwiz_step_abnormal_closed_evt_struct close_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
            cntx = (mmi_setwiz_test_cntx_struct*)evt->user_data;

            MMI_INIT_EVENT(&close_evt, EVT_ID_SETWIZ_STEP_ABNORMAL_CLOSED);
            close_evt.step_id = cntx->step_id;
            MMI_POST_EVENT(&close_evt, mmi_setwiz_step_notify_event, cntx->user_data);

            mmi_frm_scrn_set_leave_proc(
                cntx->grp_id,
                cntx->scr_id,
                NULL);

            OslMfree(cntx);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


static void mmi_setwiz_test_next_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_setwiz_test_cntx_struct *cntx;
    mmi_setwiz_step_next_evt_struct next_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_setwiz_test_cntx_struct*)mmi_frm_scrn_get_user_data(
            mmi_frm_group_get_active_id(),
            mmi_frm_scrn_get_active_id());

    MMI_INIT_EVENT(&next_evt, EVT_ID_SETWIZ_STEP_NEXT);
    next_evt.step_id = cntx->step_id;
    MMI_POST_EVENT(&next_evt, mmi_setwiz_step_notify_event, cntx->user_data);
}


static void mmi_setwiz_test_exit_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_setwiz_test_cntx_struct *cntx;
    mmi_setwiz_step_exit_selected_evt_struct exit_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_setwiz_test_cntx_struct*)mmi_frm_scrn_get_user_data(
            mmi_frm_group_get_active_id(),
            mmi_frm_scrn_get_active_id());

    MMI_INIT_EVENT(&exit_evt, EVT_ID_SETWIZ_STEP_EXIT_SELECTED);
    exit_evt.step_id = cntx->step_id;
    MMI_POST_EVENT(&exit_evt, mmi_setwiz_step_notify_event, cntx->user_data);
}


static void mmi_setwiz_test_entry(mmi_scrn_essential_struct *es_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_setwiz_test_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_setwiz_test_cntx_struct*)es_data->user_data;

    if (!mmi_frm_scrn_enter(
        cntx->grp_id,
        cntx->scr_id,
        NULL,
        (FuncPtr)mmi_setwiz_test_entry,
        MMI_FRM_FULL_SCRN))
    {
        return;
    }

    ShowCategory66Screen(
        STR_GLOBAL_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_EXIT,
        0,
        (U8*)(cntx->text),
        STR_GLOBAL_COPYING,
        mmi_frm_scrn_get_active_gui_buf());

    SetLeftSoftkeyFunction(mmi_setwiz_test_next_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_setwiz_test_exit_hdlr, KEY_EVENT_UP);
    mmi_frm_scrn_set_leave_proc(cntx->grp_id, cntx->scr_id, mmi_setwiz_test_leave_proc);
}


static mmi_setwiz_step_handle mmi_setwiz_test_create(
    const mmi_setwiz_step_create_param_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_setwiz_test_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_setwiz_test_cntx_struct*)OslMalloc(sizeof(mmi_setwiz_test_cntx_struct));

    cntx->grp_id = param->grp_id;
    cntx->scr_id = (mmi_id)(GRP_ID_SETUP_WIZARD + 1 + param->step_id);
    cntx->user_data = param->user_data;
    cntx->step_id = param->step_id;
    kal_wsprintf(cntx->text, "Step: %d", (S32)cntx->step_id);

    return cntx;
}


static void mmi_setwiz_test_run(mmi_setwiz_step_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_setwiz_test_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_setwiz_test_cntx_struct*)handle;

    mmi_frm_scrn_first_enter(
        cntx->grp_id,
        cntx->scr_id,
        (FuncPtr)mmi_setwiz_test_entry,
        cntx);
}


static void mmi_setwiz_test_close(mmi_setwiz_step_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_setwiz_test_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_setwiz_test_cntx_struct*)handle;

    mmi_frm_scrn_set_leave_proc(
        cntx->grp_id,
        cntx->scr_id,
        NULL);

    mmi_frm_scrn_close(cntx->grp_id, cntx->scr_id);
    OslMfree(cntx);
}

#endif /* __MMI_SETWIZ_UNIT_TEST__ */

#endif /* __MMI_SETUP_WIZARD__ */

