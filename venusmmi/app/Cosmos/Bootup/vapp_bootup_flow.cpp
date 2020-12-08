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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_bootup_flow.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Bootup flow of Venus MMI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vapp_bootup.h"
#include "vapp_bootup_app.h"
#include "vapp_launcher_gprot.h"
extern "C"
{
#include "gpiosrvgprot.h" /* srv_vibrator_post_req, srv_backlight_turn_on */
#include "ShutdownSrvGprot.h"

#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_C__) 
#include "dcmgr.h" // DCM
#endif

}

#pragma arm section code = "DYNAMIC_CODE_BOOTUP_ROCODE", rodata = "DYNAMIC_CODE_BOOTUP_RODATA"
MMI_FRM_PROC_CON_DECLARE_BEGIN(g_vapp_bootup_waiting_con_proc)
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_BOOTUP_WAITING_TIMER, vapp_bootup_start_events_timer, NULL)
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_BOOTUP_WAIT_FOR_GPIO, vapp_bootup_wait_for_gpio, NULL)
MMI_FRM_PROC_CON_DECLARE_END(g_vapp_bootup_waiting_con_proc, vapp_bootup_events_stop_on_timeout, NULL)


MMI_FRM_PROC_CON_DECLARE_BEGIN(g_vapp_bootup_animation_phase)
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_BOOTUP_PROTOCOL, vapp_bootup_boot_protocol, NULL)
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_BOOTUP_ANIMATION, vapp_bootup_play_animation, NULL)
    /*
     * NORMAL_INIT should be the last entry, because:
     * 1. It is a time-consuming blocking function. As we call it, following procedures should be
     *    delayed to it completes
     * 2. Apps in NORMAL_INIT may determines the state set in boot_protocol()
     */
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_BOOTUP_NORMAL_INIT, vapp_bootup_normal_init, NULL)
MMI_FRM_PROC_CON_DECLARE_END(g_vapp_bootup_animation_phase, vapp_bootup_ani_on_proc_status_changed, NULL)


static mmi_frm_proc_result_enum vapp_bootup_flow_early_init(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info);

static mmi_frm_proc_result_enum vapp_bootup_flow_disable_interrupt(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info);

static mmi_frm_proc_result_enum vapp_bootup_flow_enable_interrupt(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info);

static const mmi_frm_proc_struct g_vapp_bootup_main_flow[] =
{
    { MMI_FRM_PROC_ID_BOOTUP_WAIT_FOR_EVENTS, mmi_frm_proc_con_create_and_execute, (void*)&g_vapp_bootup_waiting_con_proc },
    { MMI_FRM_PROC_ID_BOOTUP_EARLY_INIT, vapp_bootup_flow_early_init, NULL },
    { MMI_FRM_PROC_ID_BOOTUP_DISABLE_INTERRUPT, vapp_bootup_flow_disable_interrupt, NULL },
    { MMI_FRM_PROC_ID_BOOTUP_DISK_CHECK, vapp_bootup_flow_disk_check, NULL },
    { MMI_FRM_PROC_ID_BOOTUP_INIT_SIM, vapp_bootup_init_sim_module, NULL },
    { MMI_FRM_PROC_ID_BOOTUP_MODE_DECISION, vapp_bootup_decide_mode, NULL },
    { MMI_FRM_PROC_ID_BOOTUP_ANI_PHASE, mmi_frm_proc_con_create_and_execute, (void*)&g_vapp_bootup_animation_phase },
    { MMI_FRM_PROC_ID_BOOTUP_ENABLE_INTERRUPT, vapp_bootup_flow_enable_interrupt, NULL },
    { MMI_FRM_PROC_ID_BOOTUP_SECURITY, vapp_bootup_flow_security, NULL },
#ifdef __GADGET_SUPPORT__
    { MMI_FRM_PROC_ID_BOOTUP_PREINSTALL_WIDGET, vapp_widget_preinstall_widget, NULL},
#endif
};


typedef struct
{
    mmi_id app_grp_id;
	mmi_id parent_grp_id;
    mmi_frm_proc_struct *main_flow;
} vapp_bootup_flow_cntx_struct;

static vapp_bootup_flow_cntx_struct g_vapp_bootup_flow_cntx;


static mmi_frm_proc_ctrl_enum vapp_bootup_flow_stop_check(
    void *user_data,
    const mmi_frm_proc_set_status_struct *set_status);
static mmi_ret vapp_bootup_flow_completed(mmi_event_struct *evt);
#pragma arm section code, rodata

extern "C"
mmi_ret vapp_bootup_flow_start(mmi_event_struct *evt)
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_C__)
    DCM_Load(DYNAMIC_CODE_COMPRESS_BOOTUP, 0, 0);
#endif	
    vapp_bootup_flow_cntx_struct *cntx;

    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_FLOW_START);

    cntx = &g_vapp_bootup_flow_cntx;

    cntx->main_flow = mmi_frm_proc_seq_create(
        mmi_frm_proc_allocate_id(),
        g_vapp_bootup_main_flow,
        sizeof(g_vapp_bootup_main_flow) / sizeof(g_vapp_bootup_main_flow[0]));

    mmi_frm_proc_seq_set_status_callback(
        cntx->main_flow,
        vapp_bootup_flow_stop_check,
        cntx);

    mmi_frm_proc_post_complete_execute(
        MMI_FRM_PROC_ID_BOOTUP_MAIN,
        vapp_bootup_flow_completed,
        cntx,
        cntx->main_flow);
	
    return MMI_RET_OK;
}
#pragma arm section code = "DYNAMIC_CODE_BOOTUP_ROCODE", rodata = "DYNAMIC_CODE_BOOTUP_RODATA"
mmi_id vapp_bootup_dummy_group(void)
{
	return mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN,  NULL, NULL, MMI_FRM_NODE_NONE_FLAG);
}


static mmi_frm_proc_result_enum vapp_bootup_flow_early_init(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    vapp_bootup_flow_cntx_struct *cntx = &g_vapp_bootup_flow_cntx;

    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_FLOW_EARLY_INIT);
    
    vapp_bootup_early_init();

	cntx->parent_grp_id = vapp_bootup_dummy_group();
	
    cntx->app_grp_id = VfxAppLauncher::launch(
        VAPP_BOOTUP,
        VFX_OBJ_CLASS_INFO(VappBootupApp),
        cntx->parent_grp_id);

    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_APP_LAUNCHED, cntx->app_grp_id);

    if (!srv_bootup_is_exception_mode())
    {
#ifdef __MMI_POWER_ON_OFF_MUTE__
        srv_vibrator_post_req(VIB_PATTERN_1, PLAY_ONCE);
#endif
        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    }

    return MMI_FRM_PROC_RESULT_COMPLETED;
}


static mmi_frm_proc_result_enum vapp_bootup_flow_disable_interrupt(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_DISALBE_INTERRUPT);
    mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGHEST_SCRN);
    
    return MMI_FRM_PROC_RESULT_COMPLETED;
}


static mmi_frm_proc_result_enum vapp_bootup_flow_enable_interrupt(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_ENABLE_INTERRUPT);
    mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGHEST_SCRN);
    
    return MMI_FRM_PROC_RESULT_COMPLETED;
}


static mmi_frm_proc_ctrl_enum vapp_bootup_flow_stop_check(
    void *user_data,
    const mmi_frm_proc_set_status_struct *set_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_shutdown_is_running() ?
        MMI_FRM_PROC_CTRL_STOP : MMI_FRM_PROC_CTRL_CONTINUE);
}

static void vapp_bootup_dcm_timeout(void)
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_C__)
    DCM_Unload(DYNAMIC_CODE_COMPRESS_BOOTUP);
#endif
}

static mmi_ret vapp_bootup_flow_completed(mmi_event_struct *evt)
{
    vapp_bootup_flow_cntx_struct *cntx;
    vapp_launcher_launch_param_struct param;

    if (srv_shutdown_is_running())
    {
        return MMI_RET_OK;
    }

    cntx = static_cast<vapp_bootup_flow_cntx_struct*>(evt->user_data);

    vapp_bootup_notify_before_idle();

    mmi_frm_proc_seq_destroy(cntx->main_flow);
    cntx->main_flow = NULL;

	//
	// Bootup & Launcher shouldn't be cocurrency to avoid memory exhaust.
	//
	VfxAppLauncher::terminate(cntx->app_grp_id);
	
    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_LAUNCH_HOME_SCREEN);
    param.base_app_id = cntx->parent_grp_id;
    vapp_launcher_launch(&param, sizeof(vapp_launcher_launch_param_struct));
	
    mmi_frm_group_close(cntx->parent_grp_id);

    srv_bootup_notify_completed();
	// Emit completed event after set the flag of service
    vapp_bootup_notify_completed();
		StartTimer(VAPP_BOOTUP_DCM_TIMER, 1, vapp_bootup_dcm_timeout);
    return MMI_RET_OK;
}
#pragma arm section code, rodata
