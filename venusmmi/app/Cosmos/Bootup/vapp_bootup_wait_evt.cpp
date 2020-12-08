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
 *  vapp_bootup_wait_evt.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Wait for the events for bootup
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"
#include "vapp_bootup.h"
#include "mmi_rp_vapp_bootup_def.h" /* VAPP_BOOTUP_WAITING_EVENT_TIMER */
extern "C"
{
#include "ProcedureGprot.h"
#include "gpiosrvgprot.h"       /* srv_gpio_check_pwron_ready */
}


/****************************************************************************
 * Guard timer
 ****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_BOOTUP_ROCODE", rodata = "DYNAMIC_CODE_BOOTUP_RODATA"
#define VAPP_BOOTUP_WAITING_TIMEOUT_VALUE 2000

typedef struct
{
    VfxBool timeout;
    mmi_frm_proc_id_info_struct id_info;
} vapp_bootup_wait_timer_cntx_struct;

static vapp_bootup_wait_timer_cntx_struct g_vapp_bootup_wait_timer_cntx =
{
    VFX_FALSE
};


static void vapp_bootup_events_timer_timeout(void);

mmi_frm_proc_result_enum vapp_bootup_start_events_timer(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    g_vapp_bootup_wait_timer_cntx.timeout = VFX_FALSE;
    g_vapp_bootup_wait_timer_cntx.id_info = id_info;

    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_START_EVENTS_TIMER, VAPP_BOOTUP_WAITING_TIMEOUT_VALUE);
    StartTimer(VAPP_BOOTUP_WAITING_EVENT_TIMER, VAPP_BOOTUP_WAITING_TIMEOUT_VALUE, vapp_bootup_events_timer_timeout);

    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
}


static void vapp_bootup_events_timer_timeout(void)
{
    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_EVENTS_TIMER_TIMEOUT);

    g_vapp_bootup_wait_timer_cntx.timeout = VFX_TRUE;
    mmi_frm_proc_notify_completed(g_vapp_bootup_wait_timer_cntx.id_info);
}


mmi_frm_proc_ctrl_enum vapp_bootup_events_stop_on_timeout(
    void *user_data,
    const mmi_frm_proc_set_status_struct *info)
{
    if (g_vapp_bootup_wait_timer_cntx.timeout ||
        info->n_completed >= (info->n_total_procs - 1)) // Only timeout is not triggered
    {
        return MMI_FRM_PROC_CTRL_STOP;
    }

    return MMI_FRM_PROC_CTRL_CONTINUE;
}


/****************************************************************************
 * GPIO
 ****************************************************************************/

typedef struct
{
    VfxBool waiting;
    mmi_frm_proc_id_info_struct id_info;
} vapp_bootup_gpio_cntx_struct;

static vapp_bootup_gpio_cntx_struct g_vapp_bootup_gpio_cntx =
{
    VFX_FALSE
};


static void vapp_bootup_notify_gpio_arrived(void *para, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  vapp_bootup_wait_for_gpio
 * DESCRIPTION
 *  Wait for GPIO.
 * PARAMETERS
 *  arg     [IN] Unused
 *  id_info [IN] To be passed into mmi_frm_proc_notify_completed()
 * RETURNS
 *  mmi_frm_proc_result_enum
 *****************************************************************************/
mmi_frm_proc_result_enum vapp_bootup_wait_for_gpio(
                            void *arg,
                            const mmi_frm_proc_id_info_struct id_info)
{
#ifdef __MTK_TARGET__

    VfxBool isArrived = srv_gpio_check_pwron_ready(
        vapp_bootup_notify_gpio_arrived,
        &g_vapp_bootup_gpio_cntx);

    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_WAIT_FOR_GPIO, isArrived);

    if (isArrived)
    {
        return MMI_FRM_PROC_RESULT_COMPLETED;
    }

    g_vapp_bootup_gpio_cntx.waiting = VFX_TRUE;
    g_vapp_bootup_gpio_cntx.id_info = id_info;
    
    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
    
#else /* __MTK_TARGET__ */

    /* We don't need to wait for GPIO */
    return MMI_FRM_PROC_RESULT_COMPLETED;

#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  vapp_bootup_notify_gpio_arrived
 * DESCRIPTION
 *  For GPIO module to notify GPIO required message has been arrived.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_bootup_notify_gpio_arrived(void *para, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_GPIO_ARRIVED, g_vapp_bootup_gpio_cntx.waiting);
    
    if (g_vapp_bootup_gpio_cntx.waiting)
    {
        g_vapp_bootup_gpio_cntx.waiting = VFX_FALSE;
        mmi_frm_proc_notify_completed(g_vapp_bootup_gpio_cntx.id_info);
    }
}

#pragma arm section code, rodata
