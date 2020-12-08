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
 *  AppMemMgr.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  App-Based Shared Memory Manager
 *
 *  App-based shared memory is allocated before entering an application, and 
 *  released when exiting an application. 
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
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "mmi_frm_gprot.h"
#include "GlobalDefs.h"
#include "app_mem.h"
#include "mmi_frm_prot.h"
#include "CommonScreensEnum.h"
#include "CommonScreens.h"
#include "SettingProfile.h"         /* for tone ID */
#include "wgui_categories_fmgr.h"   /* Category 212 */
#include "mmiapi_func.h"
#include "wgui_categories_popup.h"
#include "CallmanagementGprot.h"    /* Check incoming call */
#include "custom_events_notify.h"
#include "UCMGProt.h"
#include "UcmSrvGprot.h"
#include "mmi_rp_framework_asm_def.h"
#include "mmi_frm_mem_prot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_mem_gprot.h"
#include "MMI_fw_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "kal_public_api.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "gui.h"
#include "wgui_inputs.h"
#include "gui_inputs.h"
#include "gui_theme_struct.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "string.h"
#include "mmi_frm_history_gprot.h"
#include "gui_switch.h"
#include "wgui.h"
#include "mmi_cb_mgr_gprot.h"
#include "IdleGprot.h"

#ifdef __MMI_FRM_ASM_OOM_SCREEN__

#ifdef __COSMOS_MMI_PACKAGE__
#define __COSMOS_MEM_MGR__
#define __COSMOS_MEM_MGR_DISABLE_NCENTER__
#endif

#ifdef __MMI_NCENTER_SUPPORT__
#ifndef __COSMOS_MEM_MGR_DISABLE_NCENTER__
#define __COSMOS_MEM_MGR_DISABLE_NCENTER__
#endif
#endif

#ifdef __COSMOS_MEM_MGR_DISABLE_NCENTER__
#include "vapp_ncenter_gprot.h"
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/

#ifdef __COSMOS_MEM_MGR__
void vadp_p2v_vapp_oom_init(mmi_id asmManagerGid, mmi_id launchAppId);
void vadp_p2v_vapp_oom_stop_finished(void);
#endif



/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/* Context of asm manager */
typedef struct 
{
    /* Application ID that needs to free up more memory */
    MMI_ID_TYPE app_id;
    /* ASM manager screen group ID */
    mmi_id asm_manager_gid;
    /* ASM manager state */
    mmi_frm_asm_manager_state_enum asm_manager_state;

	MMI_BOOL pre_back_to_idle;
    /* The application ID that user chooses to stop */
    mmi_id app_id_confirm_to_stop;
} mmi_frm_asm_manager_cntx_struct;

/*context of prompt screen */
typedef struct 
{
    /* Number of applications using App-based ASM */
    U32 num_app;
    /* Detailed information of each application */
    applib_mem_ap_usage_struct applist[MMI_FRM_APPMEM_MAX_APP_PROMPTED];
} mmi_frm_appmem_prompt_screen_cntx_struct;


/*****************************************************************************              
 * Local Variable                                                                    
 *****************************************************************************/

/* Life cycle: show prompt screen -> user to stop applications -> successfully get the memory or cancelled */
static mmi_frm_asm_manager_cntx_struct g_asm_manager_cntx;

/* Life cycle: inside the prompt screen only (SCR_APPMEM_STOP_PROMPT) */
static mmi_frm_appmem_prompt_screen_cntx_struct *g_mmi_frm_appmem_prompt_screen_p = NULL;

/*****************************************************************************              
 * Local Function                                                                    
 *****************************************************************************/

/* Prototype declarations: */
static void asm_mgr_enter_prompt_list_screen(void);
static void asm_mgr_invoke_release_mem_success_callback(void);
static mmi_ret mmi_frm_appmem_ucm_cb_hdlr(mmi_event_struct *arg);
static void asm_mgr_enter_progressing_screen(void);
static mmi_ret asm_manager_proc(mmi_event_struct *evt);
static void mmi_frm_appmem_prompt_rsk_hdlr(void);
/* Hierarchy ASM: default handler to handle appmem events */
static MMI_BOOL asm_mgr_check_app_stopping(applib_mem_ap_usage_struct* app_list, U32 num);
static S32 mmi_frm_oom_get_aync_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_execute_cancel_callback
 * DESCRIPTION
 *  Notify application with cancel type if cancel callback is registered.
 *  This interface should be modify if app need more info for cancel callback in future.
 * PARAMETERS
 *  type        [IN]    cancel type
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_execute_cancel_callback(mmi_frm_appmem_event_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_asmi_invoke_cancel_callback(g_asm_manager_cntx.app_id, type))
    {
        g_asm_manager_cntx.asm_manager_state = MMI_FRM_ASM_MANAGER_STATE_CANCELED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_stop_confirm_screen_yes
 * DESCRIPTION
 *  User confirm to stop an application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_stop_confirm_screen_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_stop_app_by_MMI_task(g_asm_manager_cntx.app_id_confirm_to_stop, MEM_AP_STOP_TYPE_FORCE);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_STOP_CONFIRM_YES, 
                g_asm_manager_cntx.app_id_confirm_to_stop,
                g_asm_manager_cntx.asm_manager_state);
        
    if (g_asm_manager_cntx.asm_manager_state != MMI_FRM_ASM_MANAGER_STATE_FINISHED)
    {
        /* this is async case, mmi_frm_appmem_stop_finished_handler() was not invoked inside
           applib_mem_ap_stop_app_by_MMI_task(), we display progressing
           screen to wait for mmi_frm_appmem_stop_finished_handler() */ 
        asm_mgr_enter_progressing_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_stop_comfirm_callback
 * DESCRIPTION
 *  stop confirm popup callback
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_frm_appmem_stop_comfirm_callback(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct *)event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_1:
        case MMI_ALERT_CNFM_2:
        case MMI_ALERT_CNFM_3:
            // handle softkey event here
            break;
        case MMI_ALERT_CNFM_OK:
            // handle softkey event here
            break;
        case MMI_ALERT_CNFM_YES:
            mmi_frm_appmem_stop_confirm_screen_yes();
            break;
        case MMI_ALERT_CNFM_NO:
            mmi_frm_scrn_close_active_id();
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_entry_stop_confirm_screen
 * DESCRIPTION
 *  Ask user to confirm to stop application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_entry_stop_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
	arg.softkey[0].str = (WCHAR *)((UI_string_type) GetString(STR_GLOBAL_YES));
	arg.softkey[2].str = (WCHAR *)((UI_string_type) GetString(STR_GLOBAL_NO));
	arg.callback = mmi_frm_appmem_stop_comfirm_callback;
	arg.parent_id = g_asm_manager_cntx.asm_manager_gid;
	mmi_confirm_display((WCHAR *)((UI_string_type) GetString(STR_ID_APPMEM_STOP)), MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_screen_stop_highlighted
 * DESCRIPTION
 *  Stop the current highlighted application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_prompt_screen_stop_highlighted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 highlited_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == SCR_APPMEM_STOP_PROMPT &&
               g_mmi_frm_appmem_prompt_screen_p);

    highlited_item = GetHighlightedItem();
    MMI_ASSERT((highlited_item-1) < (S32)g_mmi_frm_appmem_prompt_screen_p->num_app);

    g_asm_manager_cntx.app_id_confirm_to_stop = 
        g_mmi_frm_appmem_prompt_screen_p->applist[highlited_item-1].app_id;

    mmi_frm_appmem_entry_stop_confirm_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_screen_wait_highlighted
 * DESCRIPTION
 *  Wait a stopping application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_prompt_screen_wait_highlighted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    asm_mgr_enter_progressing_screen();
}


/*****************************************************************************
 * FUNCTION
 *  asm_mgr_enter_progressing_screen
 * DESCRIPTION
 *  progressing screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void asm_mgr_enter_progressing_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_ENTRY_PROGRESSING_SCREEN);
    g_asm_manager_cntx.asm_manager_state = MMI_FRM_ASM_MANAGER_STATE_WAITING;
	if (mmi_frm_scrn_enter(g_asm_manager_cntx.asm_manager_gid,  
                           SCR_APPMEM_STOP_PROGRESSING, 
                           NULL, 
                           asm_mgr_enter_progressing_screen, 
                           MMI_FRM_SMALL_SCRN))
    { 
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();        
        ShowCategory165Screen(
            0,                                  /* Left softkey */
            0,
            STR_GLOBAL_BACK,                    /* Right softkey */
            0,
        	(UI_string_type)GetString(STR_GLOBAL_PLEASE_WAIT),
            mmi_get_event_based_image(MMI_EVENT_PROGRESS),
            guiBuffer);

        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  asm_mgr_prompt_list_screen_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of prompt screen
 * PARAMETERS
 *  item_index  [IN]    currently highlighted menu index
 * RETURNS
 *  void
 *****************************************************************************/
static void asm_mgr_prompt_list_screen_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_ASSERT(g_mmi_frm_appmem_prompt_screen_p); 
    if (g_mmi_frm_appmem_prompt_screen_p->num_app == 0)
    {
        return;
    }
    
    MMI_ASSERT(item_index < (S32)g_mmi_frm_appmem_prompt_screen_p->num_app + 1);
    
    if (!g_mmi_frm_appmem_prompt_screen_p->applist[item_index-1].is_stopping)
    {
        ChangeLeftSoftkey(STR_GLOBAL_STOP, 0);
        SetLeftSoftkeyFunction(mmi_frm_appmem_prompt_screen_stop_highlighted, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_frm_appmem_prompt_screen_stop_highlighted, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(STR_ID_APPMEM_WAIT, 0);
        SetLeftSoftkeyFunction(mmi_frm_appmem_prompt_screen_wait_highlighted, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_frm_appmem_prompt_screen_wait_highlighted, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  asm_mgr_invoke_release_mem_success_callback
 * DESCRIPTION
 *  Invoke the calling application there is enough memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void asm_mgr_invoke_release_mem_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mmi_frm_asmi_check_enough_memory(g_asm_manager_cntx.app_id));
    MMI_ASSERT(mmiapi_is_MMI_task());
    
    /* 
     * If press END key go back idle, we make the asm process ended and won't invoke success callback here.
     * Actually, mmi_display_popupcallback won't invoke callback if exit this popup screen.
     */
#ifndef __COSMOS_MMI_PACKAGE__
    if (g_asm_manager_cntx.asm_manager_state == MMI_FRM_ASM_MANAGER_STATE_FINISHED)
#endif
    {
        mmi_frm_asmi_invoke_success_callback(g_asm_manager_cntx.app_id);
        mmi_frm_group_close(g_asm_manager_cntx.asm_manager_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  asm_refresh_prompt_list_screen
 * DESCRIPTION
 *  refresh category 211, when application free memory background. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void asm_refresh_prompt_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_mmi_frm_appmem_prompt_screen_p);
    
    g_mmi_frm_appmem_prompt_screen_p->num_app = (S32)mmi_frm_asm_get_asm_usage(
		g_asm_manager_cntx.app_id,
		g_mmi_frm_appmem_prompt_screen_p->applist,
        MMI_FALSE,
        MMI_FALSE);
	wgui_cat1031_refresh_list(g_mmi_frm_appmem_prompt_screen_p->num_app + 1, 0, mmi_frm_oom_get_aync_item, NULL);   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_stop_finished
 * DESCRIPTION
 *  Callback handler when an application finished stop operation
 * PARAMETERS
 *  app_id      [IN]    ID of the application to be stopped
 *  string_id   [IN]    Name of the application to be stopped
 *  result      [IN]    whether the stop operation suceeds or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_stop_finished(kal_uint32 app_id, kal_uint32 string_id, kal_bool result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == SCR_APPMEM_STOP_PROMPT &&
        !mmi_frm_asmi_check_enough_memory(g_asm_manager_cntx.app_id))
    {
        asm_refresh_prompt_list_screen();
        return;
    }


    if ((g_asm_manager_cntx.asm_manager_state != MMI_FRM_ASM_MANAGER_STATE_FINISHED) &&
        (g_asm_manager_cntx.asm_manager_gid != GRP_ID_INVALID)) /* In confirm screen */
    {
        U32 msgId;
        mmi_event_notify_enum pop_event_id; 
        if (mmi_frm_asmi_check_enough_memory(g_asm_manager_cntx.app_id))
        {
            msgId = STR_ID_APPMEM_NOTIFY_STARTING_NEW;
            pop_event_id = MMI_EVENT_INFO;
        }
        else if (result) 
        {
            msgId = STR_ID_APPMEM_NOTIFY_STOPPED;
            pop_event_id = MMI_EVENT_SUCCESS;
        }
        else
        {
            msgId = STR_GLOBAL_FAILED;
            pop_event_id = MMI_EVENT_FAILURE;
        }
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_STOP_FINISHED, msgId);

        mmi_popup_display_simple((WCHAR*)((UI_string_type)GetString((U16)msgId)), pop_event_id, g_asm_manager_cntx.asm_manager_gid, NULL);
		mmi_frm_scrn_close(g_asm_manager_cntx.asm_manager_gid, SCR_APPMEM_STOP_PROGRESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_check_prompt_screen
 * DESCRIPTION
 *  if ordinary screen based app invoke asm manager just return app id, else if the app is
 *  screen group return root app id.
 * PARAMETERS
 *  void 
 * RETURNS
 *  Root app id which invoke asm manager.
 *****************************************************************************/
applib_mem_ap_id_enum mmi_frm_appmem_check_prompt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID root_parent_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_frm_group_is_present(g_asm_manager_cntx.asm_manager_gid))
    {
        root_parent_id = mmi_frm_get_root_app(g_asm_manager_cntx.app_id);
        /* if ordinary screen based app invoke asm manager just return app id */
        if (root_parent_id == GRP_ID_INVALID)
            return (applib_mem_ap_id_enum)g_asm_manager_cntx.app_id;
            
        /* return root screen group app */
        else
            return (applib_mem_ap_id_enum)root_parent_id;            
    }
    else
    {
        return APPLIB_MEM_AP_ID_DUMMY;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ucm_cb_hdlr
 * DESCRIPTION
 *  Callback handler of ucm incoming call to stop asm manager and notify application
 *  if cancel callback has been registered.
 * PARAMETERS
 *  void
 * RETURNS
 * applib_mem_ap_id_enum application id which invoke prompt screen
 *****************************************************************************/
static mmi_ret asm_ucm_cancel_cb_post_evt(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    mmi_frm_appmem_execute_cancel_callback(MMI_FRM_APPMEM_CANCEL_BY_UCM_CALL);
    mmi_frm_group_close(g_asm_manager_cntx.asm_manager_gid);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ucm_cb_hdlr
 * DESCRIPTION
 *  Callback handler of ucm incoming call to stop asm manager and notify application
 *  if cancel callback has been registered.
 * PARAMETERS
 *  void
 * RETURNS
 * applib_mem_ap_id_enum application id which invoke prompt screen
 *****************************************************************************/
static mmi_ret mmi_frm_appmem_ucm_cb_hdlr(mmi_event_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        MMI_FRM_INIT_EVENT(&evt, 0);

        MMI_FRM_POST_EVENT(&evt, asm_ucm_cancel_cb_post_evt, NULL);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  asm_mgr_exit_prompt_list_screen
 * DESCRIPTION
 *  prompt screen exit function, release screen based ASM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 **************************************************************************/
static void asm_mgr_exit_prompt_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_frm_appmem_prompt_screen_p)
    {
        mmi_mfree(g_mmi_frm_appmem_prompt_screen_p);
        g_mmi_frm_appmem_prompt_screen_p = NULL; 
    }
}


/*****************************************************************************
 * FUNCTION
 *  asm_manager_enter_prompt_list_screen
 * DESCRIPTION
 *  prompt list screen entry function.
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 **************************************************************************/
static MMI_BOOL asm_mgr_check_app_stopping(applib_mem_ap_usage_struct* app_list, U32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < num; i++)
    {
        if (app_list[i].is_stopping)
        {
            return MMI_TRUE;
    }
}
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_oom_get_aync_item
 * DESCRIPTION
 *  dynamic list get list item
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 **************************************************************************/
static S32 mmi_frm_oom_get_aync_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_ap_usage_struct *applist;
    UI_string_type str_buff;
    S8 size_str[32];
//    S8 size_str_ucs2[32 * 2];
    S32 app_name_len;
    U32 i,j;
    UI_string_type msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_mmi_frm_appmem_prompt_screen_p &&
               start_index < ((S32)g_mmi_frm_appmem_prompt_screen_p->num_app + 1));
               
    applist = g_mmi_frm_appmem_prompt_screen_p->applist;

    for(i=start_index,j = 0; j< data_size; i++,j++)
    {
        str_buff = menu_data[j].item_list[0];
        if(i == 0)
        {
            msg = (UI_string_type) GetString(STR_ID_APPMEM_PROMPT_STOP_APP);
            mmi_ucs2cpy((CHAR*)str_buff, (CHAR*)msg);
            continue;
        }
        i--;

        if (APPMEM_STR_NON_DEFINED == applist[i].string_id) /* string ID is non-registered */
        {
            /* use APP<app_id> as app name */
            sprintf((char*) size_str, "APP%d", applist[i].app_id);
            mmi_asc_to_ucs2((CHAR *)str_buff, size_str);
        }
        else
        {
            mmi_ucs2ncpy((S8*) str_buff, GetString((U16) applist[i].string_id), (MAX_SUB_MENU_SIZE / 2));
        }
        app_name_len = mmi_ucs2strlen((CHAR *) str_buff);

        if (applist[i].is_stopping)
        {
            mmi_ucs2ncpy(
                (CHAR *) str_buff + (app_name_len * 2), 
                (CHAR *) GetString(STR_ID_APPMEM_ATTR_STOPPING),
                (MAX_SUB_MENU_SIZE / 2) - app_name_len);
        }
        else
        {
		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        }
        wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NUMBER);
        menu_data[j].image_list[0] = (PU8) wgui_get_list_menu_icon(i, IMG_GLOBAL_L1);
        wgui_restore_list_menu_slim_style();
        i++;

    }

    return data_size;

}
static MMI_BOOL asm_mgr_prompt_list_screen_get_flags(S32 index, U32* flag, U32* flag_ex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        *flag |= UI_MENUITEM_DISABLE_ICON;        
		*flag |= UI_MENUITEM_STATE_DISABLED;
		*flag_ex |= UI_MENUITEM_EXT_SHOW_DOWN_SEPARATORLINE;
		*flag_ex |= UI_MENUITEM_EXT_DISABLED_NORMAL_TEXT;
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


static MMI_RET oom_fail_handler(mmi_event_struct *evt)
{
    mmi_event_struct tmp;
    mmi_frm_appmem_execute_cancel_callback(MMI_FRM_APPMEM_CANCEL_BACK_FROM_PROMPT_SCRN);
    mmi_frm_group_close(g_asm_manager_cntx.asm_manager_gid);
    mmi_popup_display_simple_ext(STR_GLOBAL_INSUFFICIENT_MEMORY, MMI_EVENT_INFO, GRP_ID_ROOT, NULL);
    MMI_FRM_INIT_EVENT(&tmp, EVT_ID_OOM_HANDLE_FAIL);
    MMI_FRM_CB_EMIT_EVENT(&tmp);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  asm_manager_enter_prompt_list_screen
 * DESCRIPTION
 *  prompt list screen entry function.
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 **************************************************************************/
static void asm_mgr_enter_prompt_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    mmi_event_notify_enum pop_event_id; 
    U32 msgId;
    S32 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_mmi_frm_appmem_prompt_screen_p == NULL);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_ENTRY_PROMPT_SCREEN);
    if (!mmi_frm_scrn_enter(g_asm_manager_cntx.asm_manager_gid, 
                            SCR_APPMEM_STOP_PROMPT, 
                            asm_mgr_exit_prompt_list_screen, 
                            asm_mgr_enter_prompt_list_screen, 
                            MMI_FRM_FULL_SCRN))
    {
        return;
    }
    g_asm_manager_cntx.asm_manager_state = MMI_FRM_ASM_MANAGER_STATE_NORMAL;
    /* some app will release its memory in exit function, so maybe the memory
       is enough, we just invoke success callback directly. This is the forward case */
    if (mmi_frm_asmi_check_enough_memory(g_asm_manager_cntx.app_id) && !mmi_is_redrawing_bk_screens())
    {
        g_asm_manager_cntx.asm_manager_state = MMI_FRM_ASM_MANAGER_STATE_FINISHED;
        
        if (mmi_frm_is_in_backward_scenario()) /* backward*/
        {
            msgId = STR_ID_APPMEM_NOTIFY_STARTING_NEW;
            pop_event_id = MMI_EVENT_INFO;
            mmi_popup_display_simple((WCHAR*)((UI_string_type)GetString((U16)msgId)), 
                                      pop_event_id, 
                                      g_asm_manager_cntx.asm_manager_gid, 
                                      NULL);
        }
        else /* forward, invoke success callback directly */
        {
            asm_mgr_invoke_release_mem_success_callback();
        }       
    }
    /* normal case: the memory is not enough, we should show prompt screen(app list) */
    else
    {
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();

        if (!g_mmi_frm_appmem_prompt_screen_p)
        {
            g_mmi_frm_appmem_prompt_screen_p = mmi_malloc(sizeof(mmi_frm_appmem_prompt_screen_cntx_struct));
        }
        
        g_mmi_frm_appmem_prompt_screen_p->num_app = (S32) mmi_frm_asm_get_asm_usage(
			g_asm_manager_cntx.app_id,
			g_mmi_frm_appmem_prompt_screen_p->applist,
            MMI_FALSE,
            MMI_FALSE);
        if (!mmi_frm_is_in_backward_scenario() 
            && asm_mgr_check_app_stopping(g_mmi_frm_appmem_prompt_screen_p->applist, g_mmi_frm_appmem_prompt_screen_p->num_app))
        {
            asm_mgr_enter_progressing_screen();  
         }
        else
        {
            if (g_mmi_frm_appmem_prompt_screen_p->num_app == 0)
            {
                mmi_event_struct tmp;
                MMI_FRM_INIT_EVENT(&tmp, 0);
                MMI_FRM_POST_EVENT(&tmp, oom_fail_handler, NULL);
                return;
            }
            
            EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            RegisterHighlightHandler(asm_mgr_prompt_list_screen_highlight_hdlr);
			wgui_fixed_list_register_get_flags_handler(asm_mgr_prompt_list_screen_get_flags);
			wgui_cat1031_set_disable_sc_show(MMI_TRUE);
            wgui_cat1043_show(
                STR_GLOBAL_INSUFFICIENT_MEMORY,
                0, 
                STR_GLOBAL_STOP,
            	STR_GLOBAL_BACK, 
                g_mmi_frm_appmem_prompt_screen_p->num_app + 1, 
                mmi_frm_oom_get_aync_item, 
                NULL, 0, 
            	0, 
                IMG_GLOBAL_L1,
                0,//IMG_GLOBAL_L1,
                guiBuffer,
                &error);

            
            SetRightSoftkeyFunction(mmi_frm_appmem_prompt_rsk_hdlr, KEY_EVENT_UP);
        }
    }
}


/****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_rsk_hdlr
 * DESCRIPTION
 *  RSK handler of prompt screen, notify application if cancel callback is registered.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_prompt_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_frm_appmem_execute_cancel_callback(MMI_FRM_APPMEM_CANCEL_BACK_FROM_PROMPT_SCRN);
    mmi_frm_group_close(g_asm_manager_cntx.asm_manager_gid);
}


/*****************************************************************************
 * FUNCTION
 *  asm_manager_proc
 * DESCRIPTION
 *  asm manager screen group proc, recieve events.
 * PARAMETERS
 *  evt :       [IN] event struct.
 * RETURNS
 *  MMI_RET_OK.
 **************************************************************************/
static mmi_ret asm_manager_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        /* mmi_display_popupcallback_with_sg will send/post event to parent proc */
	#ifdef __PLUTO_MMI_PACKAGE__
		case EVT_ID_GROUP_ENTER:
			mmi_frm_cb_reg_event(EVT_ID_APP_TERMINATED, asm_manager_proc, NULL);
		break;
	#endif

        case EVT_ID_POPUP_QUIT:
            if (g_asm_manager_cntx.asm_manager_gid != GRP_ID_INVALID)
            {
                if (mmi_frm_asmi_check_enough_memory(g_asm_manager_cntx.app_id))
                {
                    g_asm_manager_cntx.asm_manager_state = MMI_FRM_ASM_MANAGER_STATE_FINISHED;
                    asm_mgr_invoke_release_mem_success_callback();
                }
                else
                {
                    mmi_frm_scrn_multiple_close(g_asm_manager_cntx.asm_manager_gid, 
                                                mmi_frm_scrn_get_active_id(), 
                                                1, 0, SCR_APPMEM_STOP_PROMPT, 0);
                }
            }
            break;
        /* some interrupt will goback to idle and will call displayidlescreen */
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
		{
			if (g_asm_manager_cntx.pre_back_to_idle == MMI_FALSE)
			{
				mmi_event_struct evt;
				MMI_FRM_INIT_EVENT(&evt, EVT_ID_ASM_OOM_BACK_TO_IDLE);
				MMI_FRM_POST_EVENT(&evt, asm_manager_proc, NULL);
                return MMI_RET_STOP_END_KEY_FLOW;
			}
			else
			{
				break;
			}
		}

		case EVT_ID_ASM_OOM_BACK_TO_IDLE:
		{
			mmi_frm_appmem_execute_cancel_callback(MMI_FRM_APPMEM_CANCEL_DEL_BY_INTERRUPT);
			g_asm_manager_cntx.pre_back_to_idle = MMI_TRUE;
			mmi_idle_display();
			break;
		}

    #ifdef __PLUTO_MMI_PACKAGE__
		case EVT_ID_APP_TERMINATED:
		{
			if ((g_asm_manager_cntx.asm_manager_state == MMI_FRM_ASM_MANAGER_STATE_NORMAL)
				&& mmi_frm_asmi_check_enough_memory(g_asm_manager_cntx.app_id))
			{
				U32 msgId;
				mmi_event_notify_enum pop_event_id = MMI_EVENT_INFO; 
				g_asm_manager_cntx.asm_manager_state = MMI_FRM_ASM_MANAGER_STATE_FINISHED;
				msgId = STR_ID_APPMEM_NOTIFY_STARTING_NEW;
				pop_event_id = MMI_EVENT_INFO;
				mmi_popup_display_simple((WCHAR*)((UI_string_type)GetString((U16)msgId)), 
                                      pop_event_id, 
                                      g_asm_manager_cntx.asm_manager_gid, 
                                      NULL);
			}
			break;
		}
    #endif
        case  EVT_ID_GROUP_DEINIT:
            mmi_frm_cb_dereg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, mmi_frm_appmem_ucm_cb_hdlr, NULL);
            mmi_frm_appmem_set_cancel_callback((applib_mem_ap_id_enum)g_asm_manager_cntx.asm_manager_gid, NULL);   /* clear cancel callback */
            g_asm_manager_cntx.asm_manager_gid = GRP_ID_INVALID;
            if (g_asm_manager_cntx.asm_manager_state != MMI_FRM_ASM_MANAGER_STATE_FINISHED)
            {
                mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGH_SCRN);
            }
		#ifdef __PLUTO_MMI_PACKAGE__
			mmi_frm_cb_dereg_event(EVT_ID_APP_TERMINATED, asm_manager_proc, NULL);
		#endif
            break;
            
         case EVT_ID_ASMI_STOP_FINISHED:
    #ifdef __COSMOS_MEM_MGR__
            if (mmi_frm_asmi_check_enough_memory(g_asm_manager_cntx.app_id))
            {
                g_asm_manager_cntx.asm_manager_state = MMI_FRM_ASM_MANAGER_STATE_FINISHED;
                asm_mgr_invoke_release_mem_success_callback();
            }
    #else
			{		    
				mmi_frm_asmi_stop_finished_evt_struct * finishevt;
				finishevt = (mmi_frm_asmi_stop_finished_evt_struct*)evt;
	            mmi_frm_appmem_stop_finished(finishevt->app_id, finishevt->str_id, finishevt->result);
			}
    #endif
            break;

#ifdef __COSMOS_MEM_MGR_DISABLE_NCENTER__
         case EVT_ID_VAPP_NCENTER_DRAG:
            return MMI_RET_ERR; // disable NCenter
#endif
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_manager_launch
 * DESCRIPTION
 *  Initialize context and Launch asm manager screen group.
 * PARAMETERS
 *  caller_id        :  [IN]    APP ID that needs more memory. 
 *  app_icon         :  [IN]    Image ID of the application (not used now).
 *  required_size    :  [IN]    Minimum required memory for the application.
 *  success_callback :  [IN]    Callback function when getting memory successfully.
 *  require_full_pool:  [IN]    If require full pool or not.
 * RETURNS
 *  ASM manager screen group ID.
 **************************************************************************/
mmi_id mmi_frm_asm_manager_launch(mmi_id caller_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_asm_mgr_on_top = mmi_frm_group_is_in_active_serial(g_asm_manager_cntx.asm_manager_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* avoid re-entry the group */
    if (g_asm_manager_cntx.asm_manager_gid != GRP_ID_INVALID)
    {
        /* enter dummy screen to prevent from active group change */
        if (is_asm_mgr_on_top)
            mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_APPMEM_DUMMY, MMI_dummy_function, MMI_dummy_function, MMI_FRM_UNKNOW_SCRN);
        mmi_frm_group_close(g_asm_manager_cntx.asm_manager_gid);
    }
    /* Avoid reentrance of the asm manager screen group.
       Application developers should be careful on designing the screen flow */
    /* Register UCM callback, exit asm manager when call coming. */
    mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, mmi_frm_appmem_ucm_cb_hdlr, NULL);
    g_asm_manager_cntx.app_id = caller_id;
    g_asm_manager_cntx.app_id_confirm_to_stop = APPLIB_MEM_AP_ID_DUMMY;
    g_asm_manager_cntx.asm_manager_state = MMI_FRM_ASM_MANAGER_STATE_NORMAL;
    g_asm_manager_cntx.asm_manager_gid = GRP_ID_INVALID;
	g_asm_manager_cntx.pre_back_to_idle = MMI_FALSE;

    /***********************************************/
    //MMI_ASSERT(!mmi_frm_appmem_check_enough_memory());
    if (mmi_frm_asmi_check_enough_memory(g_asm_manager_cntx.app_id))
    {
        g_asm_manager_cntx.asm_manager_state = MMI_FRM_ASM_MANAGER_STATE_FINISHED;
        asm_mgr_invoke_release_mem_success_callback();
        mmi_frm_scrn_close(GRP_ID_ROOT, SCR_APPMEM_DUMMY);
        return GRP_ID_INVALID;
    }

    /* create and enter asm manager screen group */
    g_asm_manager_cntx.asm_manager_gid = mmi_frm_group_create_ex(
                                             GRP_ID_ROOT, 
                                             GRP_ID_AUTO_GEN, 
                                             asm_manager_proc, 
                                             NULL,
                                             MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGH_SCRN);
#ifdef __COSMOS_MEM_MGR__
    vadp_p2v_vapp_oom_init(g_asm_manager_cntx.asm_manager_gid, caller_id);
#else
    asm_mgr_enter_prompt_list_screen();
#endif
    mmi_frm_scrn_close(GRP_ID_ROOT, SCR_APPMEM_DUMMY);
    return g_asm_manager_cntx.asm_manager_gid;
}


/***************************************************************************** 
 * FUNCTION
 *  mmi_frm_asm_manager_close
 * DESCRIPTION
 *  Close the asm manager group.
 * PARAMETERS
 *  asm_mgr_id  : [IN] The asm manager group id.
 * RETURNS
 *  void
 **************************************************************************/
void mmi_frm_asm_manager_close(mmi_id asm_mgr_id)
    {
    // TODO: close asm manager here
    mmi_frm_group_close(asm_mgr_id);
}


/***************************************************************************** 
 * FUNCTION
 *  mmi_frm_asm_manager_is_launched
 * DESCRIPTION
 *  Check if the asm manager group is present.
 * PARAMETERS
 *  id_ptr  : [IN/OUT] The asm manager group id.
 * RETURNS
 *  Return MMI_TRUE is launched.
 **************************************************************************/
MMI_BOOL mmi_frm_asm_manager_is_launched(mmi_id *id_ptr)
    {
    if (id_ptr)
        *id_ptr = g_asm_manager_cntx.asm_manager_gid;
    return mmi_frm_group_is_present(g_asm_manager_cntx.asm_manager_gid);
}


/***************************************************************************** 
 * FUNCTION
 *  mmi_frm_asm_manager_get_app_id
 * DESCRIPTION
 *  Get app id that request oom
 * PARAMETERS
 *  void
 * RETURNS
 *  Return the app id.
 **************************************************************************/
mmi_id mmi_frm_asm_manager_get_app_id(void)
{
    return g_asm_manager_cntx.app_id;
}


/***************************************************************************** 
 * FUNCTION
 *  mmi_frm_asm_get_manger_state
 * DESCRIPTION
 *  Get asm mamager state.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return the state
 **************************************************************************/
U16 mmi_frm_asm_get_manger_state(void)
    {       
    return g_asm_manager_cntx.asm_manager_state;
}


/***************************************************************************** 
 * FUNCTION
 *  mmi_frm_asm_get_applist_in_pool
 * DESCRIPTION
 *  Get the asm pool applist.
 * PARAMETERS
 *  app_list : [OUT] The applist.
 *  num      : [OUT] The number of applist
 * RETURNS
 *  void
 **************************************************************************/
void mmi_frm_asm_get_applist_in_pool(applib_mem_ap_usage_struct* app_list, U32 num)
{
    if (g_mmi_frm_appmem_prompt_screen_p)
    {
        memcpy(app_list, g_mmi_frm_appmem_prompt_screen_p->applist, sizeof(applib_mem_ap_usage_struct) * num);
    }

}
#else
MMI_BOOL mmi_frm_asm_manager_is_launched(mmi_id *ptr)
{
    return MMI_FALSE;
}
applib_mem_ap_id_enum mmi_frm_appmem_check_prompt_screen(void)
{
    return APPLIB_MEM_AP_ID_DUMMY;
}

#endif



