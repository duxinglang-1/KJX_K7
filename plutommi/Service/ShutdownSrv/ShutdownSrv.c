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
 *  ShutdownSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  The implementation of shutdown service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "ShutdownSrvIprot.h"
#include "BootupSrvGprot.h"     /* srv_bootup_get_booting_mode */
#include "UtilitySrvGprot.h"
#include "gpiosrvgprot.h"
#include "lcd_if.h"             /* lcd_power_on */
#include "mmi_frm_events.h"     /* DeInitFramework */
#include "MMI_common_app_trc.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "mmi_frm_events_gprot.h"
#include "MMI_features.h"
#include "ShutdownSrvGprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_timer_gprot.h"
#include "device.h"
#include "mmi_frm_utility_gprot.h"
#ifdef __KJX_FUN__
#include "TimerEvents.h"
#endif
#ifndef __MTK_TARGET__
#include "w32_utility.h"
#endif


#define SRV_SHUTDOWN_TRC_GROUP MMI_COMMON_TRC_G3_SHUTDOWN


/****************************************************************************
 * Global variables
 ****************************************************************************/

typedef struct
{
    MMI_BOOL is_running;
    MMI_BOOL already_exit;
    
    struct {
        srv_shutdown_deinit_completed_callback completed_callback;
        void *user_data;
        mmi_sim_enum deiniting_sim;
    } protocol;

    mmi_sim_enum closing_sim;
} srv_shutdown_cntx_struct;

static srv_shutdown_cntx_struct g_srv_shutdown_cntx =
{
    MMI_FALSE,
    MMI_FALSE
};


/****************************************************************************
 * Local functions
 ****************************************************************************/

static void srv_shutdown_deinit_protocol_complete(void);
static MMI_BOOL srv_shutdown_nw_pwroff_detach_rsp_hdlr(void *msg, S32 src_mode);
static MMI_BOOL srv_shutdown_power_off_rsp_hdlr(void *msg, S32 src_mode);


/*****************************************************************************
 * FUNCTION
 *  srv_shutdown_nw_pwroff_detach_rsp_hdlr
 * DESCRIPTION
 *  Handler for NW_PWROFF_DETACH_RSP.
 *  Send another NW_PWROFF_DETACH_REQ or determine the completion of detaches.
 * PARAMETERS
 *  sim     [IN] Which side of protocol
 *  msg     [IN]
 * RETURNS
 *  MMI_FALSE
 *****************************************************************************/
static MMI_BOOL srv_shutdown_nw_pwroff_detach_rsp_hdlr(void *msg, S32 src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim = mmi_frm_l4c_mod_to_sim((module_type)src_mod);

    MMI_ASSERT(sim == g_srv_shutdown_cntx.protocol.deiniting_sim);

    g_srv_shutdown_cntx.protocol.deiniting_sim >>= 1;
    
    if (sim != MMI_SIM1)
    {
        mmi_frm_send_ilm(
            mmi_frm_sim_to_l4c_mod(g_srv_shutdown_cntx.protocol.deiniting_sim),
            MSG_ID_MMI_NW_PWROFF_DETACH_REQ,
            NULL,
            NULL);
    }
    else
    {
        srv_shutdown_deinit_protocol_complete();
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_shutdown_deinit_protocol_complete
 * DESCRIPTION
 *  Callback client to notify protocol deinited.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_shutdown_deinit_protocol_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_shutdown_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &g_srv_shutdown_cntx;

    MMI_TRACE(SRV_SHUTDOWN_TRC_GROUP, TRC_SRV_SHUTDOWN_DEINIT_PROTOCOL_COMPLETED,
        (U32)cntx->protocol.completed_callback);

    if (cntx->protocol.completed_callback != NULL)
    {
        cntx->protocol.completed_callback(cntx->protocol.user_data);
        cntx->protocol.completed_callback = NULL;
    }
}


/****************************************************************************
 * Global functions
 ****************************************************************************/

/*****************************************************************************
 * Please refer to ShutdownSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_shutdown_is_running(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_srv_shutdown_cntx.is_running);
}


/*****************************************************************************
 * Please refer to ShutdownSrvIprot.h
 *****************************************************************************/
void srv_shutdown_deinit_protocol(
        srv_shutdown_deinit_completed_callback completed_callback,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_shutdown_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_SHUTDOWN_TRC_GROUP, TRC_SRV_SHUTDOWN_DEINIT_PROTOCOL, (U32)completed_callback);
    
    cntx = &g_srv_shutdown_cntx;
    
    MMI_ASSERT(cntx->is_running);

    cntx->protocol.completed_callback = completed_callback;
    cntx->protocol.user_data = user_data;

    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_NW_PWROFF_DETACH_RSP,
        (PsIntFuncPtr)srv_shutdown_nw_pwroff_detach_rsp_hdlr,
        MMI_FALSE);

#if (MMI_MAX_SIM_NUM >= 4)
    g_srv_shutdown_cntx.protocol.deiniting_sim = MMI_SIM4; // Gemini+
#elif (MMI_MAX_SIM_NUM >= 3)
    g_srv_shutdown_cntx.protocol.deiniting_sim = MMI_SIM3; // Gemini+
#elif (MMI_MAX_SIM_NUM >= 2)
    g_srv_shutdown_cntx.protocol.deiniting_sim = MMI_SIM2;
#else
    g_srv_shutdown_cntx.protocol.deiniting_sim = MMI_SIM1;
#endif

    mmi_frm_send_ilm(
        mmi_frm_sim_to_l4c_mod(g_srv_shutdown_cntx.protocol.deiniting_sim),
        MSG_ID_MMI_NW_PWROFF_DETACH_REQ,
        NULL,
        NULL);
}

#ifdef __KJX_FUN__
#include "Kjx_prin.h"
extern void kjx_handle_send_poweroff_notify(void);
//强制立即关机，不进行各种告警 
void my_shutdown_normal_start(void) 
{ 
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */ 
    /*----------------------------------------------------------------*/ 
	srv_shutdown_normal_start_evt_struct start_evt;
    /*----------------------------------------------------------------*/ 
    /* Code Body                                                      */ 
    /*----------------------------------------------------------------*/ 
    if (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_NORMAL)
    { 
    	/* Give the control to shutdown flow module */
        MMI_FRM_INIT_EVENT(&start_evt, EVT_ID_SRV_SHUTDOWN_NORMAL_START); 
		MMI_FRM_CB_EMIT_EVENT(&start_evt); 
	}
    else
    {
    	/*
         	* For other power-on mode, we don't need to deinit other application
         	* and play animation.
         	*/
        srv_shutdown_exit_system(0); 
	}
}
#endif

/*****************************************************************************
 * Please refer to ShutdownSrvGprot.h
 *****************************************************************************/
void srv_shutdown_normal_start(MMI_ID trigger_man_app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_shutdown_normal_start_evt_struct start_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_SHUTDOWN_TRC_GROUP, TRC_SRV_SHUTDOWN_NORMAL_START,
        trigger_man_app_id, g_srv_shutdown_cntx.is_running);

    /* g_srv_shutdown_cntx.is_running will be set to TRUE in srv_shutdown_deinit() */
    if (g_srv_shutdown_cntx.is_running)
    {
        return;
    }

#ifdef	__KJX_FUN__ 	//xb add 2017-08-09 关机之前通知后台
	if(IsMyTimerExist(KJX_TIMER_ID_POWER_OFF_DELAY))
	{
		LOGD("正在通知后台");
		
		return;
	}
	else
	{
		LOGD("准备通知后台");
		
		kjx_handle_send_poweroff_notify();
		StartTimer(KJX_TIMER_ID_POWER_OFF_DELAY, 2*1000, my_shutdown_normal_start);
		return;
	}
#endif

    if (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_NORMAL)
    {
        /* Give the control to shutdown flow module */
        MMI_FRM_INIT_EVENT(&start_evt, EVT_ID_SRV_SHUTDOWN_NORMAL_START);
        MMI_FRM_CB_EMIT_EVENT(&start_evt);
    }
    else
    {
        /*
         * For other power-on mode, we don't need to deinit other application
         * and play animation.
         */
        srv_shutdown_exit_system(trigger_man_app_id);
    }
}


/*****************************************************************************
 * Please refer to ShutdownSrvIprot.h
 *****************************************************************************/
void srv_shutdown_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_shutdown_deinit_evt_struct deinit_evt;
    srv_shutdown_handler_reset_evt_struct handler_reset_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_SHUTDOWN_TRC_GROUP, TRC_SRV_SHUTDOWN_DEINIT);
    
    if (g_srv_shutdown_cntx.is_running)
    {
        return;
    }

    g_srv_shutdown_cntx.is_running = MMI_TRUE;

#ifndef __MTK_TARGET__
    /*
     * On MoDIS, if the mobile starts the power-off procedure, notify MoDIS
     * such that it can hide the MoDIS menu.
     */
    w32_set_mmi_is_in_power_off_period(KAL_TRUE);
#endif
    
    MMI_FRM_INIT_EVENT(&deinit_evt, EVT_ID_SRV_SHUTDOWN_DEINIT);
    MMI_FRM_CB_EMIT_EVENT(&deinit_evt);

    mmi_frm_clear_all_protocol_event_handler();
    mmi_frm_stop_all_timer();

    MMI_FRM_INIT_EVENT(&handler_reset_evt, EVT_ID_SRV_SHUTDOWN_HANDLER_RESET);
    MMI_FRM_CB_EMIT_EVENT(&handler_reset_evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_shutdown_emit_final_deinit_event
 * DESCRIPTION
 *  Emit FINAL_DEINIT event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_shutdown_emit_final_deinit_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_shutdown_final_deinit_evt_struct final_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&final_evt, EVT_ID_SRV_SHUTDOWN_FINAL_DEINIT);
    MMI_FRM_CB_EMIT_EVENT(&final_evt);
}


/*****************************************************************************
 * Please refer to ShutdownSrvGprot.h
 *****************************************************************************/
void srv_shutdown_exit_system(MMI_ID trigger_man_app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_SHUTDOWN_TRC_GROUP, TRC_SRV_SHUTDOWN_EXIT_SYSTEM,
        trigger_man_app_id, g_srv_shutdown_cntx.is_running, g_srv_shutdown_cntx.already_exit);
    
    if (g_srv_shutdown_cntx.already_exit)
    {
        return;
    }
    
    g_srv_shutdown_cntx.is_running = MMI_TRUE;
    g_srv_shutdown_cntx.already_exit = MMI_TRUE;

    /* turn off backlight to prevent blank screen */
    srv_gpio_set_device_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL0);
    
    srv_shutdown_emit_final_deinit_event();

#ifdef __MTK_TARGET__

    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_EQ_POWER_OFF_RSP,
        (PsIntFuncPtr)srv_shutdown_power_off_rsp_hdlr,
        MMI_FALSE);

#if (MMI_MAX_SIM_NUM >= 2)
    if (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_NORMAL)
    {
    #if (MMI_MAX_SIM_NUM >= 4)
        g_srv_shutdown_cntx.closing_sim = MMI_SIM4; // Gemini+
    #elif (MMI_MAX_SIM_NUM >= 3)
        g_srv_shutdown_cntx.closing_sim = MMI_SIM3; // Gemini+
    #else
        g_srv_shutdown_cntx.closing_sim = MMI_SIM2;
    #endif
    }
    else
    {
        /* SIM2 is not enabled in non-normal mode */
        g_srv_shutdown_cntx.closing_sim = MMI_SIM1;
    }
#else
    g_srv_shutdown_cntx.closing_sim = MMI_SIM1;
#endif

    mmi_frm_send_ilm(
        mmi_frm_sim_to_l4c_mod(g_srv_shutdown_cntx.closing_sim),
        MSG_ID_MMI_EQ_POWER_OFF_REQ,
        NULL,
        NULL);

#else /* __MTK_TARGET__ */

    DeInitFramework();

    exit(0);

#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_shutdown_power_off_rsp_hdlr
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EQ_POWER_OFF_RSP.
 *  The final step: Turn off LCD and keypad.
 * PARAMETERS
 *  sim         [IN] From while SIM
 *  msg         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_shutdown_power_off_rsp_hdlr(void *msg, S32 src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim = mmi_frm_l4c_mod_to_sim((module_type)src_mod);

    MMI_ASSERT(sim == g_srv_shutdown_cntx.closing_sim);

    g_srv_shutdown_cntx.closing_sim >>= 1;

    if (sim != MMI_SIM1)
    {
        mmi_frm_send_ilm(
            mmi_frm_sim_to_l4c_mod(g_srv_shutdown_cntx.closing_sim),
            MSG_ID_MMI_EQ_POWER_OFF_REQ,
            NULL,
            NULL);
    }
    else
    {
        srv_backlight_turn_off_keypad_light();

        DeInitFramework();

        lcd_power_on(MAIN_LCD, KAL_FALSE); /* power off lcd */
#ifdef __MMI_SUBLCD__
        lcd_power_on(SUB_LCD, KAL_FALSE);  /* power off sub-lcd */
#endif
    }

    return MMI_FALSE;
}
