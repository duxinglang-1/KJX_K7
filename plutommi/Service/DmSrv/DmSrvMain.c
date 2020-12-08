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
 *  DmSrvMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  DM service main
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef SYNCML_DM_SUPPORT

/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "mmi_include.h"
#include "DmSrvIprot.h"
#include "DmSrvMain.h"
#include "DmSrvUtil.h"
#include "DmSrvAcc.h"
#include "DmSrvSession.h"
#include "DmSrvFota.h"
#include "DmSrvDl.h"
#include "DmSrvLawmo.h"
#include "DmSrvScomo.h"
#include "MMIDataType.h"
#include "BootupSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "UcmSrvGprot.h"
#include "Cbm_api.h"
#include "DmSelfRegisterGprot.h"
#include "TimerEvents.h"
#include "NwInfoSrvGprot.h"
#include "mmi_rp_srv_dm_def.h"
/****************************************************************************
 * Global Variable
 ****************************************************************************/

/****************************************************************************
 * Static Variable
 ****************************************************************************/
srv_dm_main_cntx main_cntx;

/****************************************************************************
 * Local Function
 ****************************************************************************/

mmi_ret srv_dm_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_INIT, evt->evt_id);
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_BOOTUP_NORMAL_INIT:
        {
            srv_dm_init_set_status(SRV_DM_INIT_STATUS_SRV_ON_INIT);
        #ifdef __DM_LAWMO_SUPPORT__
            srv_dm_lawmo_get_status_from_nvram();
        #endif
        
            #ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
                SetProtocolEventHandler(srv_dm_init_sr_result_ind_hdlr, MSG_ID_MMI_DM_SELF_REGISTER_RESULT_IND);
            #else
                srv_dm_init_set_flag(SRV_DM_INIT_FLAG_SR);
            #endif
            
            break;
        }

        case EVT_ID_SRV_BOOTUP_BEFORE_IDLE:
        {
            if (srv_sim_ctrl_any_sim_is_available() == MMI_TRUE)
            {
                MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_INIT_SIM_AVAIL);
            }
#if 0
            #ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
/* under construction !*/
            #else
/* under construction !*/
            #endif
#endif
                srv_dm_init_reg_cbm_app_id();
                srv_dm_acc_init();
                srv_dm_session_init();
                srv_dm_dl_init();
            #ifdef __DM_FOTA_SUPPORT__
                srv_dm_fota_init();
            #endif /* __DM_FOTA_SUPPORT__ */
            #ifdef __DM_LAWMO_SUPPORT__
                srv_dm_lawmo_init();
            #endif /* __DM_LAWMO_SUPPORT__ */
            #ifdef __DM_SCOMO_SUPPORT__
                srv_dm_scomo_init();
            #endif /* __DM_SCOMO_SUPPORT__ */

            #if !(defined(__OP01_3G__) || defined(__UMTS_RAT__))
                // only for 2G
                mmi_frm_cb_reg_event(
                    EVT_ID_SRV_UCM_STATUS_CHANGE,
                    srv_dm_ucm_status_change_hdlr,
                    NULL);
            #endif
            break;
        }

        case EVT_ID_SRV_BOOTUP_COMPLETED:
        {
            srv_dm_init_set_flag(SRV_DM_INIT_FLAG_BOOTUP);
        #ifdef __DM_FOTA_SUPPORT__
            srv_dm_fota_bootup_check_update();
        #endif /* __DM_FOTA_SUPPORT__ */

        #ifndef __MTK_TARGET__
            srv_dm_init_set_flag(SRV_DM_INIT_FLAG_SR);
        #endif /* __MTK_TARGET__ */

        #ifdef __DM_LAWMO_SUPPORT__
            if (MMI_TRUE == srv_dm_lawmo_get_lock_status_from_nvram())
            {
                srv_dm_lawmo_exe_lock_cmd(SRV_DM_LAWMO_LOCK_CMD_LOCK);
            }
            if (MMI_TRUE == srv_dm_lawmo_get_wipe_status_from_nvram())
            {
                // run unfinished wiping job
                srv_dm_lawmo_exe_wipe_cmd(SRV_DM_LAWMO_WIPE_CMD_START);
            }
        #endif /* __DM_LAWMO_SUPPORT__ */
            break;
        }

        default:
            break;
    }
    return MMI_RET_OK;
}


void srv_dm_init_reg_cbm_app_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_app_info_struct cbm_app_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cbm_app_info.app_str_id = STR_ID_DMUI_MAIN;
    cbm_app_info.app_icon_id = IMG_ID_DMUI_MAIN;
    cbm_app_info.app_type = DTCNT_APPTYPE_DM;
    cbm_register_app_id_with_app_info(&cbm_app_info, &main_cntx.cbm_app_id);
}


void srv_dm_init_set_flag(srv_dm_init_flag_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_INIT_SET_FLAG, flag);
    main_cntx.init_flag[flag] = 1;
    srv_dm_init_check_srv_finish();
}


void srv_dm_init_check_srv_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    MMI_BOOL init_finish = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_dm_init_get_status() == SRV_DM_INIT_STATUS_SRV_INIT_FINISH)
    {
        return;
    }

    for (i = 0; i < SRV_DM_INIT_FLAG_TOTAL; i++)
    {
        if (main_cntx.init_flag[i] == 0)
        {
            init_finish = MMI_FALSE;
            break;
        }
    }

    if (init_finish == MMI_TRUE)
    {
        srv_dm_init_srv_finish();
    }
}


void srv_dm_init_srv_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_INIT_SRV_FIN);
    srv_dm_init_set_status(SRV_DM_INIT_STATUS_SRV_INIT_FINISH);
    srv_dm_init_send_srv_init_finish_ind();
    // do some unfinished jobs.
}


void srv_dm_init_send_srv_init_finish_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_send_ilm(
        MOD_DM,
        MSG_ID_DM_SRV_INIT_FINISH_IND,
        NULL,
        NULL);
}


#ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
void srv_dm_init_sr_result_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_sr_result_ind_struct *sr_result = (srv_dm_sr_result_ind_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_INIT_SR_RESULT_IND_HDLR, sr_result->sim);
    srv_dm_init_set_flag(SRV_DM_INIT_FLAG_SR);
}
#endif /* __MMI_DM_SELF_REGISTER_SUPPORT__ */


mmi_sim_enum srv_dm_get_reg_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
    return srv_dm_sr_get_used_sim();
#else
    return MMI_SIM_NONE;
#endif
}


void srv_dm_init_set_status(srv_dm_init_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_INIT_SET_STATUS, status);
    main_cntx.init_status = status;
}


srv_dm_init_status_enum srv_dm_init_get_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return main_cntx.init_status;
}


U8 srv_dm_get_cbm_app_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return main_cntx.cbm_app_id;
}


void srv_dm_defer_user_interaction(srv_dm_app_adp_evt_enum evt_id, U32 defer_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_DEFER_USER_INTERACTION, evt_id, defer_time);
    StartTimerEx(
        TIMER_ID_DM_SRV_USER_INTERACTION_DEFER,
        defer_time,
        srv_dm_resume_user_interaction,
        (void*)evt_id);
}


void srv_dm_cancel_defer_user_interaction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_CANCEL_DEFER_USER_INTERACTION);
    StopTimer(TIMER_ID_DM_SRV_USER_INTERACTION_DEFER);
}


void srv_dm_resume_user_interaction(void* arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_app_adp_evt_enum evt_id = (srv_dm_app_adp_evt_enum)arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_RESUME_USER_INTERACTION, evt_id);
    switch (evt_id)
    {
        case SRV_DM_APP_ADP_EVT_DISPLAY_NOTIFICATION:
        {
            if (srv_dm_check_sr_sim_match() == MMI_TRUE)
            {
            if (srv_dm_session_get_status() == SRV_DM_SESSION_STATUS_NOTIFICATION_WAIT_CNF)
            {
                srv_dm_session_check_suspend();

                srv_dm_session_send_app_notification_evt();
            }
            }
            else
            {
                srv_dm_defer_user_interaction(
                    SRV_DM_APP_ADP_EVT_DISPLAY_NOTIFICATION,
                    SRV_DM_TIME_USER_INTERACTION_DEFER);                
            }
            break;
        }

        case SRV_DM_APP_ADP_EVT_DISPLAY_ALERT:
        {
            if (srv_dm_check_sr_sim_match() == MMI_TRUE)
            {
            if (srv_dm_session_get_status() == SRV_DM_SESSION_STATUS_ALERT_WAIT_CNF)
            {
                srv_dm_session_alert_send_app_alert_evt();
            }
            }
            else
            {
                srv_dm_defer_user_interaction(
                    SRV_DM_APP_ADP_EVT_DISPLAY_ALERT,
                    SRV_DM_TIME_USER_INTERACTION_DEFER);            
            }
            break;
        }

    #ifdef __DM_FOTA_SUPPORT__
        case SRV_DM_APP_ADP_EVT_FOTA_DISPLAY_UPDATE:
        {
            if (srv_dm_fota_get_status() == SRV_DM_FOTA_STATUS_UPDATE_DEFER)
            {
                srv_dm_fota_send_app_update_evt();
            }
            break;
        }
    #endif /* __DM_FOTA_SUPPORT__ */

        default:
            break;
    }
}


mmi_ret srv_dm_sim_unavailable_notify_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_event_detected_evt_struct *event =
        (srv_sim_ctrl_event_detected_evt_struct*)para;
    mmi_sim_enum reg_sim = srv_dm_get_reg_sim();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SIM_UNAVAILABLE_NOTIFY_HDLR, event->sim, reg_sim);

    if (event->sim == reg_sim)
    {
        srv_dm_session_abort();
        srv_dm_cancel_defer_user_interaction();
    }
    return MMI_RET_OK;
}


mmi_ret srv_dm_restore_start_notify_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_RESTORE_START_NOTIFY_HDLR);
    main_cntx.is_restore_factory = MMI_TRUE;
    return MMI_RET_OK;
}


MMI_BOOL srv_dm_check_restore_factory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return main_cntx.is_restore_factory;
}


void srv_dm_nw_changed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL nw_status = srv_dm_check_nw_available();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_NW_CHANGED, nw_status);
    if (nw_status == MMI_TRUE)
    {
        mmi_frm_send_ilm(
            MOD_DM,
            MSG_ID_DM_NETWORK_SERVICE_AVAILABLE_IND,
            NULL,
            NULL);
    }
    else
    {
        mmi_frm_send_ilm(
            MOD_DM,
            MSG_ID_DM_NETWORK_SERVICE_NOT_AVAILABLE_IND,
            NULL,
            NULL);
    }

    srv_dm_session_check_suspend();
    srv_dm_dl_check_suspend();
}


MMI_BOOL srv_dm_check_nw_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (main_cntx.nw_mask == 0)
    {
        ret = MMI_TRUE;
    }
    else
    {
        ret = MMI_FALSE;
    }
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_CHECK_NW_AVAILABLE, ret);

    return ret;
}


MMI_BOOL srv_dm_check_nw_mask(U32 mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((main_cntx.nw_mask & mask) == mask)
    {
        ret = MMI_TRUE;
    }
    else
    {
        ret = MMI_FALSE;
    }

    return ret;
}


void srv_dm_set_nw_mask(U32 mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SET_NW_MASK, mask);
    main_cntx.nw_mask |= mask;
    srv_dm_nw_changed();
}


void srv_dm_unset_nw_mask(U32 mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_UNSET_NW_MASK, mask);
    main_cntx.nw_mask &= ~mask;
    srv_dm_nw_changed();
}


void srv_dm_reset_nw_mask(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    main_cntx.nw_mask = 0;
}


mmi_ret srv_dm_nw_info_srv_avail_changed_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_service_availability_changed_evt_struct *srv_evt =
        (srv_nw_info_service_availability_changed_evt_struct*)evt;
    mmi_sim_enum used_sim = srv_dm_get_reg_sim();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G3_DM,
        TRC_SRV_DM_NW_INFO_SRV_AVAIL_CHANGED_HDLR,
        srv_evt->new_status,
        srv_evt->sim,
        used_sim);

    if (srv_evt->sim != used_sim ||
        srv_evt->sim == MMI_SIM_NONE ||
        used_sim == MMI_SIM_NONE)
    {
        return MMI_RET_OK;
    }

    if (srv_evt->new_status == SRV_NW_INFO_SA_FULL_SERVICE)
    {
        srv_dm_unset_nw_mask(SRV_DM_NW_MASK_NO_SERVICE);
    }
    else if (srv_evt->new_status == SRV_NW_INFO_SA_NO_SERVICE ||
             srv_evt->new_status == SRV_NW_INFO_SA_LIMITED_SERVICE ||
             srv_evt->new_status == SRV_NW_INFO_SA_SEARCHING)
    {
        srv_dm_set_nw_mask(SRV_DM_NW_MASK_NO_SERVICE);
    }

    return MMI_RET_OK;
}


mmi_ret srv_dm_ucm_status_change_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = srv_ucm_is_any_call();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_UCM_STATUS_CHANGED_HDLR, result);
    if (result == MMI_TRUE)
    {
        srv_dm_set_nw_mask(SRV_DM_NW_MASK_IN_CALL);
    }
    else
    {
        srv_dm_unset_nw_mask(SRV_DM_NW_MASK_IN_CALL);
    }
    return MMI_RET_OK;
}


void srv_dm_send_app_display_nmgr_popup_evt(mmi_scenario_id scenario_id, mmi_event_notify_enum type, WCHAR* string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_app_adp_evt_display_nmgr_popup_struct display_nmgr_popup_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    display_nmgr_popup_evt.scenario_id = scenario_id;
    display_nmgr_popup_evt.type = type;
    display_nmgr_popup_evt.string = string;

    srv_dm_app_adp_send_evt(SRV_DM_APP_ADP_EVT_DISPLAY_NMGR_POPUP, (void*)&display_nmgr_popup_evt);
}
#endif /* SYNCML_DM_SUPPORT */
