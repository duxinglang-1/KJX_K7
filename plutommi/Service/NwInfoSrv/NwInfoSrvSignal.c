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
 *  NwInfoSrvSignal.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Service of network infomation.
 *  This file handles signal information.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "NwInfoSrv.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "NwInfoSrvGprot.h"
#include "ps_public_enum.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_msg_struct.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_utility_gprot.h"
#include "mmi_rp_srv_nw_info_def.h"
#include "mmi_frm_timer_gprot.h"


/****************************************************************************
 * Configurations
 ****************************************************************************/

/*
 * The maximum number of the grids of signal icon
 * For example, if the signal icon ranges 0 ~ 4 grids(5 icons), this value
 * should be 4
 */
#define SRV_NW_INFO_SIGNAL_MAX_GRIDS_NUM 4

/*
 * The delay interval to degrade one signal grid.
 * When signal degrades significantly, this design can let the degrading
 * one-by-one, with this interval, to improve the UE.
 */
#define SRV_NW_INFO_SIGNAL_DEGRADING_TIME_INTERVAL 3000 /* in ms */

/* The percentage interval of one grid */
#define SRV_NW_INFO_GRID_INTERVAL \
    (100 / ((SRV_NW_INFO_SIGNAL_MAX_GRIDS_NUM) + 1))


#if defined(__UMTS_RAT__) && !defined(__UMTS_TDD128_MODE__)
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
#endif /* __UMTS_RAT__ */


/*
 * Structure for smooth signal degrading
 */
typedef struct
{
    MMI_BOOL timer_exists; /* We have triggered the timer */
    U8 target_percentage[MMI_SIM_TOTAL];
} srv_nw_info_signal_ani_cntx_struct;

static srv_nw_info_signal_ani_cntx_struct g_srv_nw_info_signal_ani_cntx;


/****************************************************************************
 * Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  Q_DBM
 * DESCRIPTION
 *  Convert dBm value to qdBm
 * PARAMETERS
 *  dBm     [IN]
 * RETURNS
 *  qdBm
 *****************************************************************************/
#define Q_DBM(dBm) ((S32)(dBm) * 4)


/*****************************************************************************
 * FUNCTION
 *  PERCENTAGE_OF
 * DESCRIPTION
 *  Calculate the percentage value by expected grids & maximum grids.
 *
 *  For example. if you prepared a 5 grids icon, namely, 6 images for 0 ~ 5
 *  grids, set the percentage to the middle value of the range of the grid#
 *  that the grid# you expect can be displayed.
 *
 *      0       1       2       3       4       5       Grid#
 *
 *  0     16.7    33.3    49.7    64.4     83.1    100  Range bound
 *  +-------+-------+-------+-------+-------+-------+
 *  0           25      42      57      74        100   Percentage
 *
 * PARAMETERS
 *  expected_grids  [IN] Number of grids which is expected,
 *                       ranges 0 ~ max_grids(included)
 *  max_grids       [IN] Maximum number of grids
 * RETURNS
 *  Suitable percentage value for the expectation
 *****************************************************************************/
#define PERCENTAGE_OF(expected_grids) \
    (((expected_grids) * 100 + 50) / ((SRV_NW_INFO_SIGNAL_MAX_GRIDS_NUM) + 1))


/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_get_next_degraging_perc
 * DESCRIPTION
 *  Get next percentage value for smooth degrading
 * PARAMETERS
 *  curr_percentage     [IN] Current percentage
 *  target_percentage   [IN] Target percentage
 * RETURNS
 *  Next percentage
 *****************************************************************************/
static S32 srv_nw_info_get_next_degraging_perc(
                S32 curr_percentage,
                S32 target_percentage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const U8 SIGNAL_STEP_PERCENTAGES[SRV_NW_INFO_SIGNAL_MAX_GRIDS_NUM + 1] =
    {
        0,
        PERCENTAGE_OF(1),
        PERCENTAGE_OF(2),
        PERCENTAGE_OF(3),
#if SRV_NW_INFO_SIGNAL_MAX_GRIDS_NUM > 4
        PERCENTAGE_OF(4),
#endif
#if SRV_NW_INFO_SIGNAL_MAX_GRIDS_NUM > 5
        PERCENTAGE_OF(5),
#endif
#if SRV_NW_INFO_SIGNAL_MAX_GRIDS_NUM > 6
        PERCENTAGE_OF(6),
#endif
#if SRV_NW_INFO_SIGNAL_MAX_GRIDS_NUM > 7
        PERCENTAGE_OF(7),
#endif
        100
    };
    const S32 STEP_ARR_SIZE = SRV_NW_INFO_SIGNAL_MAX_GRIDS_NUM + 1;

    S32 i;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 1; i < STEP_ARR_SIZE; i++)
    {
        if ((S32)SIGNAL_STEP_PERCENTAGES[i] >= curr_percentage)
        {
            break;
        }
    }

    --i;
    /* Now SIGNAL_STEP_PERCENTAGES[i] < curr_percentage */
    
    if (2 * (curr_percentage - (S32)SIGNAL_STEP_PERCENTAGES[i]) <=
            SRV_NW_INFO_GRID_INTERVAL) /* The same grid */
    {
        --i;
    }

    if (i <= 0)
    {
        i = 0;
    }

    if (SIGNAL_STEP_PERCENTAGES[i] <= target_percentage)
    {
        return target_percentage;
    }

    return SIGNAL_STEP_PERCENTAGES[i];
}

static void srv_nw_info_sent_signal_changed(mmi_sim_enum sim, U32 old_percentage, U32 new_percentage)
{
    srv_nw_info_signal_strength_changed_evt_struct strength_evt;

    MMI_TRACE(SRV_NW_INFO_TRC_GROUP, TRC_SRV_NW_INFO_SIGNAL_STRENGTH,
            sim, old_percentage, new_percentage);

    MMI_FRM_INIT_EVENT(&strength_evt, EVT_ID_SRV_NW_INFO_SIGNAL_STRENGTH_CHANGED);
    strength_evt.sim = sim;
    strength_evt.old_percentage = (U8)old_percentage;
    strength_evt.new_percentage = (U8)new_percentage;
    MMI_FRM_CB_EMIT_EVENT(&strength_evt);
}
/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_update_next_percentage
 * DESCRIPTION
 *  Update next percentage of given SIM for smooth degrading
 * PARAMETERS
 *  cntx                [IN] Context
 *  sim                 [IN] Network of SIM
 *  target_percentage   [IN] Target percentage
 *  start_timer         [OUT] Need to trigger timer for next degrading
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nw_info_update_next_percentage(
                srv_nw_info_cntx_struct *cntx,
                mmi_sim_enum sim,
                S32 target_percentage,
                MMI_BOOL *start_timer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 diff;
    U8 old_signal_strength_in_percentage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_signal_strength_in_percentage = cntx->signal.strength_in_percentage;
    
    diff = (S32)cntx->signal.strength_in_percentage - target_percentage;
    if (diff == 0)
    {
        /* Do nothing */
        return;
    }
    else if (diff <= SRV_NW_INFO_GRID_INTERVAL) /* target > curr || 0 or 1 grid difference */
    {
        /* Update directly */
        cntx->signal.strength_in_percentage = target_percentage;
    }
    else /* Signal degrades & large(>1 grids) difference */
    {
        cntx->signal.strength_in_percentage = (U8)srv_nw_info_get_next_degraging_perc(
            cntx->signal.strength_in_percentage,
            target_percentage);
        *start_timer = MMI_TRUE;
    }

	srv_nw_info_sent_signal_changed(sim, old_signal_strength_in_percentage, cntx->signal.strength_in_percentage);
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_update_signal_strength
 * DESCRIPTION
 *  Update next percentage of each SIM for smooth degrading.
 *  This will be invoked by degrading animation timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nw_info_update_signal_strength(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_nw_info_cntx_struct *cntx;
    MMI_BOOL start_timer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start_timer = MMI_FALSE;
    
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        mmi_sim_enum sim = mmi_frm_index_to_sim(i);
        
        cntx = srv_nw_info_get_cntx(sim);
        srv_nw_info_update_next_percentage(
            cntx,
            sim,
            g_srv_nw_info_signal_ani_cntx.target_percentage[i],
            &start_timer);
    }

    if (start_timer)
    {
        g_srv_nw_info_signal_ani_cntx.timer_exists = MMI_TRUE;
        
        StartTimer(
            TIMER_ID_SRV_NW_INFO_SIGNAL_ANIMATION,
            SRV_NW_INFO_SIGNAL_DEGRADING_TIME_INTERVAL,
            srv_nw_info_update_signal_strength);
    }
    else
    {
        g_srv_nw_info_signal_ani_cntx.timer_exists = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_set_target_signal_percentage
 * DESCRIPTION
 *  Set 
 * PARAMETERS
 *  cntx                [IN] Context
 *  sim                 [IN] Network of SIM
 *  target_percentage   [IN] Target percentage
 * RETURNS
 *  void
 *****************************************************************************/
void srv_nw_info_set_target_signal_percentage(
        srv_nw_info_cntx_struct *cntx,
        mmi_sim_enum sim,
        S32 target_percentage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sim_index;
    MMI_BOOL start_timer;
    U8 old_signal_strength_in_percentage;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = srv_nw_info_get_cntx(sim);
    sim_index = mmi_frm_sim_to_index(sim);
    g_srv_nw_info_signal_ani_cntx.target_percentage[sim_index] = target_percentage;

    old_signal_strength_in_percentage = cntx->signal.strength_in_percentage;

    if (target_percentage == cntx->signal.strength_in_percentage)
    {
        /* Do nothing */
        MMI_TRACE(SRV_NW_INFO_TRC_GROUP, TRC_SRV_NW_INFO_SIGNAL_STRENGTH,
            sim, old_signal_strength_in_percentage, cntx->signal.strength_in_percentage);
    }
    else if (target_percentage > cntx->signal.strength_in_percentage)
    {
        /* Update right away */
        cntx->signal.strength_in_percentage = (U8)target_percentage;
        
		srv_nw_info_sent_signal_changed(sim, old_signal_strength_in_percentage, cntx->signal.strength_in_percentage);
    }
    else /* target_percentage < cntx->signal.strength_in_percentage */
    {
        if (!g_srv_nw_info_signal_ani_cntx.timer_exists)
        {
            /* the same as (!IsMyTimerExist(TIMER_ID_SRV_NW_INFO_SIGNAL_ANIMATION)) */

            start_timer = MMI_FALSE;
            
            srv_nw_info_update_next_percentage(cntx, sim, target_percentage, &start_timer);

            if (start_timer)
            {
                g_srv_nw_info_signal_ani_cntx.timer_exists = MMI_TRUE;
                StartTimer(
                    TIMER_ID_SRV_NW_INFO_SIGNAL_ANIMATION,
                    SRV_NW_INFO_SIGNAL_DEGRADING_TIME_INTERVAL,
                    srv_nw_info_update_signal_strength);
            }
        }
        else
        {
            /* Let the timer to update the signal */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_get_band_from_l4_value
 * DESCRIPTION
 *  Map L4 band enum to srv_nw_band_enum
 * PARAMETERS
 *  l4_band     [IN] 
 * RETURNS
 *  Percentage
 *****************************************************************************/
static srv_nw_band_enum srv_nw_info_get_band_from_l4_value(kal_uint8 l4_band)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_band_enum band;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    band = SRV_NW_BAND_NONE;
    
    switch (l4_band)
    {
        case NW_BAND_PGSM900:
        case NW_BAND_EGSM900:
        case NW_BAND_RGSM900:
            band = SRV_NW_BAND_GSM900;
            break;

        case NW_BAND_DCS1800:
            band = SRV_NW_BAND_DCS1800;
            break;

        case NW_BAND_PCS1900:
            band = SRV_NW_BAND_PCS1900;
            break;

        case NW_BAND_GSM450:
            band = SRV_NW_BAND_GSM450;
            break;
            
        case NW_BAND_GSM480:
            band = SRV_NW_BAND_GSM480;
            break;
            
        case NW_BAND_GSM850:
            band = SRV_NW_BAND_GSM850;
            break;

        default:
            band = SRV_NW_BAND_OTHERS;
            break;
    }

    return band;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_get_percentage_from_gsm_rssi
 * DESCRIPTION
 *  Convert GSM RSSI to percentage value
 * PARAMETERS
 *  rssi_in_qdBm    [IN]
 * RETURNS
 *  Percentage
 *****************************************************************************/
static U8 srv_nw_info_get_percentage_from_gsm_rssi(S32 rssi_in_qdBm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 percentage = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /*
     * You may use macro PERCENTAGE_OF() here to calculate the percentage
     * by expected grids.
     */
    if (rssi_in_qdBm < Q_DBM(-107))
    {
        percentage = 0;
    }
    else if (rssi_in_qdBm < Q_DBM(-77))
    {
        percentage =
            ((rssi_in_qdBm - Q_DBM(-107)) * 100) / (Q_DBM(-77) - Q_DBM(-107));
    }
    else
    {
        percentage = 100;
    }

    return (U8)percentage;
}


#ifdef __UMTS_RAT__
/* under construction !*/
#ifdef __UMTS_TDD128_MODE__
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
#else /* __UMTS_TDD128_MODE__ */
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
#endif /* __UMTS_TDD128_MODE__ */
#endif /* __UMTS_RAT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_rx_level_ind_hdlr
 * DESCRIPTION
 *  Handler of NW_RX_LEVEL_IND.
 *  Update signal strength and camp-on band information.
 * PARAMETERS
 *  sim     [IN] From which layer
 *  msg     [IN] mmi_nw_rx_level_ind_struct*
 * RETURNS
 *  MMI_FALSE; continue message routing
 *****************************************************************************/
MMI_BOOL srv_nw_info_rx_level_ind_hdlr(void *msg, S32 src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;
    srv_nw_info_cntx_struct *cntx;
    mmi_nw_rx_level_ind_struct *rx_level_ind;
    U8 target_percentage;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim = mmi_frm_l4c_mod_to_sim((module_type)src_mod);
    cntx = srv_nw_info_get_cntx(sim);
    rx_level_ind = (mmi_nw_rx_level_ind_struct*)msg;

    /* qdBm = dBm * 4 */
    if (rx_level_ind->rat == L4C_RAT_GSM)
    {
        if (rx_level_ind->rssi_in_qdbm < 0)
        {
            cntx->signal.gsm_band = srv_nw_info_get_band_from_l4_value(rx_level_ind->current_band);
            cntx->signal.gsm_RSSI_in_qdBm = rx_level_ind->rssi_in_qdbm;
            target_percentage = srv_nw_info_get_percentage_from_gsm_rssi(cntx->signal.gsm_RSSI_in_qdBm);
        #ifdef __OP01_3G__
            if (target_percentage <= 0 &&
                srv_nw_info_get_service_availability(sim) == SRV_NW_INFO_SA_FULL_SERVICE ||
                srv_nw_info_is_need_display_fake_nw_status(sim) == MMI_TRUE)
            {
                // CMCC request not display empty signal icon
                target_percentage = 1;
            }
        #endif /* __OP01_3G__ */
            srv_nw_info_set_target_signal_percentage(cntx, sim, target_percentage);
        }
    }
#ifdef __UMTS_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __UMTS_TDD128_MODE__
/* under construction !*/
/* under construction !*/
    #ifdef __OP01_3G__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __OP01_3G__ */
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif /* __UMTS_RAT__ */

    return MMI_FALSE;
}


/*****************************************************************************
 * Please refer to NwInfoSrvGprot.h
 *****************************************************************************/
srv_nw_band_enum srv_nw_info_get_camp_on_band(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = srv_nw_info_get_cntx(sim);

    if (cntx->service_availability == SRV_NW_INFO_SA_NO_SERVICE)
    {
        return SRV_NW_BAND_NONE;
    }

    if (cntx->protocol != MMI_GSM)
    {
        return SRV_NW_BAND_OTHERS;
    }

    return (cntx->signal.gsm_band);
}


/*****************************************************************************
 * Please refer to NwInfoSrvGprot.h
 *****************************************************************************/
U8 srv_nw_info_get_signal_strength_in_percentage(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = srv_nw_info_get_cntx(sim);

    return (cntx->signal.strength_in_percentage);
}

#if defined(__KJX_FUN__)
S16 srv_nw_info_get_signal_strength_in_qdBm(mmi_sim_enum sim)
{
	S16 nRSSI;
    srv_nw_info_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = srv_nw_info_get_cntx(sim);
	nRSSI = cntx->signal.gsm_RSSI_in_qdBm;
	nRSSI >>=2;

    return nRSSI;
}

S16 srv_nw_info_get_signal_strength_in_qdBm_from_percentage(U8 percentage)
{
	S16 nRSSI;

	if( percentage > 100 )
		percentage = 100;

	nRSSI = percentage*(Q_DBM(-77) - Q_DBM(-107))/100 +  Q_DBM(-107);
	nRSSI >>=2;

	return nRSSI;
}
#endif


