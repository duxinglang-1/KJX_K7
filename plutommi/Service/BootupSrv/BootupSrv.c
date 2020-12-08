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
 *  BootupSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  The implementation of Bootup service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "mmi_msg_struct.h"
#include "device.h"             /* power_on_status_enum */
#include "SimCtrlSrvGprot.h"
#include "BootupSrvIprot.h"
#include "BootupSrv.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "BootupSrvGprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "mmi_frm_utility_gprot.h"
#include "nvram_data_items.h" /* NVRAM_SYS_AUTO_TEST */
#ifndef __MTK_TARGET__ /* on MODIS */
#include "w32_utility.h"
#endif


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
    MMI_BOOL is_launched;
    MMI_BOOL is_booting;
    MMI_BOOL is_exception_mode;
    srv_bootup_mode_enum booting_mode;
    srv_bootup_sim_cntx_struct sim_cntx[SRV_SIM_CTRL_MAX_SIM_NUM];
} srv_bootup_cntx_struct;


/****************************************************************************
 * Global variable
 ****************************************************************************/

static srv_bootup_cntx_struct g_srv_bootup_cntx =
{
    MMI_FALSE,
    MMI_FALSE,
    MMI_FALSE,
    SRV_BOOTUP_MODE_INVALID
    /* Other fields will be set when received POWER_ON_IND */
};


/****************************************************************************
 * Local functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_bootup_set_mode
 * DESCRIPTION
 *  Set booting mode by mmi_eq_power_on_ind_struct.
 * PARAMETERS
 *  msg     [IN] mmi_eq_power_on_ind_struct*
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bootup_set_mode(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_eq_power_on_ind_struct* power_on_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    power_on_ind = (const mmi_eq_power_on_ind_struct*)msg;
    
    switch (power_on_ind->poweron_mode)
    {
        case POWER_ON_KEYPAD:
            g_srv_bootup_cntx.booting_mode = SRV_BOOTUP_MODE_NORMAL;
            g_srv_bootup_cntx.is_exception_mode = MMI_FALSE;
            break;
            
        case POWER_ON_EXCEPTION:
            g_srv_bootup_cntx.booting_mode = SRV_BOOTUP_MODE_NORMAL;
            g_srv_bootup_cntx.is_exception_mode = MMI_TRUE;
            break;
            
        case POWER_ON_ALARM:
            g_srv_bootup_cntx.booting_mode = SRV_BOOTUP_MODE_ALARM;
            g_srv_bootup_cntx.is_exception_mode = MMI_FALSE;
            break;
            
        case POWER_ON_CHARGER_IN:
            g_srv_bootup_cntx.booting_mode = SRV_BOOTUP_MODE_CHARGE;
            g_srv_bootup_cntx.is_exception_mode = MMI_FALSE;
            break;
            
        case POWER_ON_PRECHARGE:
            g_srv_bootup_cntx.booting_mode = SRV_BOOTUP_MODE_PRECHARGE;
            g_srv_bootup_cntx.is_exception_mode = MMI_FALSE;
            break;
            
        case POWER_ON_USB:
            g_srv_bootup_cntx.booting_mode = SRV_BOOTUP_MODE_USB;
            g_srv_bootup_cntx.is_exception_mode = MMI_FALSE;
            break;
            
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bootup_power_on_ind_hdlr
 * DESCRIPTION
 *  The event handler of MMI_EQ_POWER_ON_IND.
 *  This handler stores the necessary information from the power-on indication,
 *  and start normal booting if the power-on mode is POWER_ON_KEYPAD or
 *  POWER_ON_EXCEPTION.
 * PARAMETERS
 *  msg     [IN] mmi_eq_power_on_ind_struct*
 * RETURNS
 *  Always MMI_FALSE, means, continue message routing
 *****************************************************************************/
MMI_BOOL srv_bootup_power_on_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_eq_power_on_ind_struct *power_on_ind;
    srv_bootup_start_evt_struct start_evt;
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg != NULL);
    //power_on_ind = (mmi_eq_power_on_ind_struct*)msg;

    /* This module only care normal power-on */
    if (g_srv_bootup_cntx.booting_mode != SRV_BOOTUP_MODE_NORMAL)
    {
        return MMI_FALSE;
    }

    g_srv_bootup_cntx.is_launched = MMI_TRUE;
    g_srv_bootup_cntx.is_booting = MMI_TRUE;
    
    srv_bootup_protocol_init();

    /* Initialize context */
    for (i = 0; i < SRV_SIM_CTRL_MAX_SIM_NUM; i++)
    {
        g_srv_bootup_cntx.sim_cntx[i].is_inserted = MMI_FALSE;
    }

    MMI_TRACE(SRV_BOOTUP_TRC_GROUP, TRC_SRV_BOOTUP_POWER_ON_IND, 
        g_srv_bootup_cntx.booting_mode, g_srv_bootup_cntx.is_exception_mode);


    /* Notify bootup flow control to start booting */
    MMI_FRM_INIT_EVENT(&start_evt, EVT_ID_SRV_BOOTUP_START);
    start_evt.is_exception_mode = g_srv_bootup_cntx.is_exception_mode;
    MMI_FRM_CB_EMIT_EVENT(&start_evt);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bootup_get_sim_cntx
 * DESCRIPTION
 *  Get the context of SIM, which is in g_srv_bootup_cntx.
 * PARAMETERS
 *  sim     [IN] Which SIM
 * RETURNS
 *  Always MMI_FALSE, means, continue message routing
 *****************************************************************************/
srv_bootup_sim_cntx_struct *srv_bootup_get_sim_cntx(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (&(g_srv_bootup_cntx.sim_cntx[mmi_frm_sim_to_index(sim)]));
}


/*****************************************************************************
 * Please refer to BootupSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_bootup_is_launched(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_srv_bootup_cntx.is_launched);
}


/*****************************************************************************
 * Please refer to BootupSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_bootup_is_booting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_srv_bootup_cntx.is_booting);
}


/*****************************************************************************
 * Please refer to BootupSrvGprot.h
 *****************************************************************************/
srv_bootup_mode_enum srv_bootup_get_booting_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_srv_bootup_cntx.booting_mode);
}


/*****************************************************************************
 * Please refer to BootupSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_bootup_is_exception_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_srv_bootup_cntx.is_exception_mode);
}


/*****************************************************************************
 * Please refer to BootupSrvIprot.h
 *****************************************************************************/
void srv_bootup_notify_completed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_bootup_cntx.is_booting = MMI_FALSE;

    MMI_TRACE(SRV_BOOTUP_TRC_GROUP, TRC_SRV_BOOTUP_COMPLETED);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_auto_power_on_test
 * DESCRIPTION
 *  Is current power-on mode auto power-on test?
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if auto power-on test currently
 *****************************************************************************/
MMI_BOOL srv_bootup_is_auto_power_on_test(void)
{
#ifndef __MTK_TARGET__ /* on MODIS */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (w32_modis_is_autopower() || w32_modis_is_autotest()) ?
                MMI_TRUE : MMI_FALSE;
    
#else

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 auto_test_data[NVRAM_EF_SYS_CACHE_OCTET_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ReadRecord(
            NVRAM_EF_SYS_CACHE_OCTET_LID,
            NVRAM_SYS_AUTO_TEST,
            auto_test_data,
            NVRAM_EF_SYS_CACHE_OCTET_SIZE,
            &error) >= 0)
    {
        if (error != NVRAM_READ_FAIL && auto_test_data[0] > 0)
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
    
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_bootup_auto_shutdown_is_enabled
 * DESCRIPTION
 *  Auto shutdown after bootup completed
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if need to trigger shutdown after bootup completed
 *****************************************************************************/
MMI_BOOL srv_bootup_auto_shutdown_is_enabled(void)
{
#ifndef __MTK_TARGET__ /* on MODIS */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return w32_modis_is_autopower() ? MMI_TRUE : MMI_FALSE;

#else

    return MMI_FALSE;

#endif
}

