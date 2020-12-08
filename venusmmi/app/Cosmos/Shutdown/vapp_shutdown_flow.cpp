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
 *  vapp_bootup_ani.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Bootup animation of Venus MMI
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
#include "vfx_uc_include.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_shutdown.h"
#include "mmi_rp_vapp_shutdown_def.h"


extern "C"
{
#include "MMIDataType.h"
#include "ProcedureGprot.h"
#include "ShutdownSrvIprot.h"
#include "gpiosrvgprot.h"       /* srv_vibrator_post_req */
#ifdef OPERA_BROWSER
#include "opera_adp_shutdown.h" /* mmi_opera_brw_deinit */
#endif
#include "CallLogSrvGprot.h"    /* srv_clog_shutdown_hdlr */
#if defined(OBIGO_Q03C_MMS_V02) && defined(WAP_SUPPORT)
#include "MmsSrvGprot.h"
#endif
}


// Timeout to shutdown directly even if something not complete
#define VAPP_SHUTDOWN_PROCESS_TIMEOUT    15000 /* ms */


// Asynchronous deinit procedures
static mmi_frm_proc_result_enum vapp_shutdown_flow_deinit(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info);
                                    
static mmi_frm_proc_result_enum vapp_shutdown_flow_deinit_protocol(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info);

MMI_FRM_PROC_CON_DECLARE_BEGIN(g_vapp_shutdown_waiting)
#ifdef __MTK_TARGET__
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_SHUTDOWN_DEINIT_PROTOCOL, vapp_shutdown_flow_deinit_protocol, NULL)
#endif
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_SHUTDOWN_DEINIT_CALL_LOG, srv_clog_shutdown_hdlr, NULL)
#ifdef OPERA_BROWSER
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_SHUTDOWN_DEINIT_OPERA_BROWSER, mmi_opera_brw_deinit, NULL)
#endif
	/*Register for MMS*/
#if defined(OBIGO_Q03C_MMS_V02) && defined(WAP_SUPPORT)
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_SHUTDOWN_DEINIT_MMS_WAP, mmi_mms_deinit, NULL)
#endif /*Browser may register their callbak in elif condition*/

    /* --- Register the non-blocking deinit procedure before this entry --- */
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_SHUTDOWN_ANIMATION, vapp_shutdown_play_animation, NULL)
MMI_FRM_PROC_CON_DECLARE_END(g_vapp_shutdown_waiting, NULL, NULL)


/*
 * Sequential main flow of shutdown
 */
static const mmi_frm_proc_struct g_vapp_shutdown_main_flow[] =
{
    { MMI_FRM_PROC_ID_SHUTDOWN_DEINIT_APPS, vapp_shutdown_flow_deinit, NULL },
    { MMI_FRM_PROC_ID_SHUTDOWN_WAITING, mmi_frm_proc_con_create_and_execute, (void*)&g_vapp_shutdown_waiting }
};


typedef struct
{
    VfxBool is_launched;
    mmi_frm_proc_struct *flow_proc;
    mmi_id app_grp_id;
    mmi_frm_proc_id_info_struct deinit_protocol_id_info;
} vapp_shutdown_cntx_struct;

static vapp_shutdown_cntx_struct g_vapp_shutdown_cntx =
{
    VFX_FALSE,
    NULL
};


static void vapp_shutdown_flow_deinit_protocol_completed(void *user_data);
static mmi_ret vapp_shutdown_flow_completed(mmi_event_struct *evt);
static void vapp_shutdown_process_timeout_handler(void *arg);


extern "C"
mmi_ret vapp_shutdown_normal_start(mmi_event_struct *evt)
{
    vapp_shutdown_cntx_struct *cntx = &g_vapp_shutdown_cntx;

    MMI_TRACE(VAPP_SHUTDOWN_TRC_GROUP, TRC_VAPP_SHUTDOWN_NORMAL_START, cntx->is_launched);

    if (cntx->is_launched)
    {
        return MMI_RET_OK;
    }

    cntx->is_launched = VFX_TRUE;

    /* Execute shutdown flow */
    cntx->flow_proc = mmi_frm_proc_seq_create(
        mmi_frm_proc_allocate_id(),
        g_vapp_shutdown_main_flow,
        sizeof(g_vapp_shutdown_main_flow) / sizeof(g_vapp_shutdown_main_flow[0]));

    mmi_frm_proc_post_complete_execute(
        MMI_FRM_PROC_ID_SHUTDOWN,
        vapp_shutdown_flow_completed,
        cntx,
        cntx->flow_proc);

    return MMI_RET_OK;
}


static mmi_frm_proc_result_enum vapp_shutdown_flow_deinit(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(VAPP_SHUTDOWN_TRC_GROUP, TRC_VAPP_SHUTDOWN_FLOW_DEINIT);
    
    mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGHEST_SCRN);

#ifdef __MMI_POWER_ON_OFF_MUTE__
    srv_vibrator_post_req(VIB_PATTERN_1, PLAY_ONCE);
#endif
    
    srv_shutdown_deinit();

    StartTimerEx(
        VAPP_SHUTDOWN_GUARD_TIMER,
        VAPP_SHUTDOWN_PROCESS_TIMEOUT,
        vapp_shutdown_process_timeout_handler,
        &g_vapp_shutdown_cntx);

    return MMI_FRM_PROC_RESULT_COMPLETED;
}


static mmi_ret vapp_shutdown_flow_completed(mmi_event_struct *)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vapp_shutdown_cntx_struct *cntx = &g_vapp_shutdown_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(VAPP_SHUTDOWN_TRC_GROUP, TRC_VAPP_SHUTDOWN_FLOW_COMPLETED);
    
    StopTimer(VAPP_SHUTDOWN_GUARD_TIMER);

    // We don't need to terminate shutdown app
    // VfxAppLauncher::terminate(cntx->app_grp_id);

    mmi_frm_proc_seq_destroy(cntx->flow_proc);
    cntx->flow_proc = NULL;
    
    srv_shutdown_exit_system(VAPP_SHUTDOWN);

    return MMI_RET_OK;
}


static mmi_frm_proc_result_enum vapp_shutdown_flow_deinit_protocol(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(VAPP_SHUTDOWN_TRC_GROUP, TRC_VAPP_SHUTDOWN_FLOW_DEINIT_PROTOCOL);
    
    g_vapp_shutdown_cntx.deinit_protocol_id_info = id_info;
    
    srv_shutdown_deinit_protocol(
        vapp_shutdown_flow_deinit_protocol_completed,
        &g_vapp_shutdown_cntx);

    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
}


static void vapp_shutdown_flow_deinit_protocol_completed(void *)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(VAPP_SHUTDOWN_TRC_GROUP, TRC_VAPP_SHUTDOWN_FLOW_DEINIT_PROTOCOL_COMPLETED);
    
    mmi_frm_proc_notify_completed(g_vapp_shutdown_cntx.deinit_protocol_id_info);
}


static void vapp_shutdown_process_timeout_handler(void *)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(VAPP_SHUTDOWN_TRC_GROUP, TRC_VAPP_SHUTDOWN_TIMEOUT, VAPP_SHUTDOWN_PROCESS_TIMEOUT);
    
    /* Shutdown abnormally */
    srv_shutdown_exit_system(VAPP_SHUTDOWN);
}

