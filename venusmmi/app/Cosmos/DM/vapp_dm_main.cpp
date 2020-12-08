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
 *  vapp_dm_main.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Device management main
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef SYNCML_DM_SUPPORT

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_popup.h"
#include "vcp_form.h"
#include "vfx_app.h"
#include "vfx_app_launcher.h"
#include "vfx_app_scr.h"
#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"
#include "vcp_confirm_popup.h"
#include "vapp_nmgr_gprot.h"
#include "vcp_global_popup.h"

#include "vapp_dm_main.h"
#include "vapp_dm_session.h"
#include "vapp_dm_otap.h"
#include "vapp_dm_dl.h"
#include "vapp_dm_fota.h"

extern "C"
{
#include "GlobalResDef.h"
#include "mmi_rp_srv_dm_def.h"
#include "mmi_rp_vapp_dm_def.h"
#include "DmSrvIprot.h"
}


/***************************************************************************** 
 * Static Variable
 *****************************************************************************/
static VappDmNmgr *gDmNmgr;

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern VappDmDlCtrler *gDmDlCtrler;

/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C"
void vapp_dm_init()
{
    VappDmEvtHdlr::getInstance()->evtHdlrInit();
}


VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappDmEvtHdlr);
void VappDmEvtHdlr::evtHdlrInit()
{
    srv_dm_app_adp_reg_cb(VappDmEvtHdlr::srvEvtHdlr);
}


void VappDmEvtHdlr::srvEvtHdlr(srv_dm_app_adp_evt_struct *evt)
{
    switch(evt->evt_id)
    {
        case SRV_DM_APP_ADP_EVT_DISPLAY_NOTIFICATION:
        {
            srv_dm_app_adp_evt_display_notification_struct *notification_evt =
                (srv_dm_app_adp_evt_display_notification_struct*)evt->arg;

            VFX_ALLOC_NEW_EX(
                gDmNmgr,
                VappDmNmgr,
                VappDmEvtHdlr::getInstance(),
                (notification_evt,
                 sizeof(srv_dm_app_adp_evt_display_notification_struct),
                 vappDmSessionNotificationNmgrHdlr,
                 MMI_EVENT_INFO));
            break;
        }

        case SRV_DM_APP_ADP_EVT_DISPLAY_ALERT:
        {
            srv_dm_app_adp_evt_display_alert_struct *alert_evt =
                (srv_dm_app_adp_evt_display_alert_struct*)evt->arg;

            VFX_ALLOC_NEW_EX(
                gDmNmgr,
                VappDmNmgr,
                VappDmEvtHdlr::getInstance(),
                (alert_evt,
                 sizeof(srv_dm_app_adp_evt_display_alert_struct),
                 vappDmSessionAlertNmgrHdlr,
                 MMI_EVENT_INFO));
            break;
        }

        case SRV_DM_APP_ADP_EVT_DISPLAY_ENDING_MSG:
        {
            srv_dm_app_adp_evt_display_ending_msg_struct *ending_msg_evt =
                (srv_dm_app_adp_evt_display_ending_msg_struct*)evt->arg;
            vappDmSessiondisplayEndingMsg(ending_msg_evt->ending_msg);
            break;
        }

        case SRV_DM_APP_ADP_EVT_SESSION_ABORT:
        case SRV_DM_APP_ADP_EVT_SESSION_FINISH:
        {
            gDmNmgr->cancelSessionNmgr();
            VappDmEvtHdlr::getInstance()->m_dmSessionFinish.postEmit();
            break;
        }

        case SRV_DM_APP_ADP_EVT_DL_START:
        {
            srv_dm_app_adp_evt_dl_start_struct *dl_start_evt =
                (srv_dm_app_adp_evt_dl_start_struct*)evt->arg;
            if (gDmDlCtrler == NULL)
            {
                VFX_ALLOC_NEW(gDmDlCtrler, VappDmDlCtrler, VappDmEvtHdlr::getInstance());
            }
            gDmDlCtrler->dlStartEvtHdlr(
                dl_start_evt->is_resume,
                dl_start_evt->auto_resume);
            break;
        }

        case SRV_DM_APP_ADP_EVT_DL_PROGRESS:
        {
            srv_dm_app_adp_evt_dl_progress_struct *dl_progress_evt =
                (srv_dm_app_adp_evt_dl_progress_struct*)evt->arg;
            VFX_ASSERT(gDmDlCtrler);
            gDmDlCtrler->dlProgressHdlr(
                dl_progress_evt->acc_size,
                dl_progress_evt->total_size);
            break;
        }

        case SRV_DM_APP_ADP_EVT_DL_FINISH:
        {
            srv_dm_app_adp_evt_dl_finish_struct *dl_finish_evt =
                (srv_dm_app_adp_evt_dl_finish_struct*)evt->arg;
            VFX_ASSERT(gDmDlCtrler);
            gDmDlCtrler->dlFinishHdlr(dl_finish_evt->cause);
            break;
        }

    #ifdef __DM_FOTA_SUPPORT__
        case SRV_DM_APP_ADP_EVT_FOTA_UPDATE_RESULT:
        {
            srv_dm_app_adp_evt_fota_update_result_struct *fota_update_result_evt =
                (srv_dm_app_adp_evt_fota_update_result_struct*)evt->arg;
            MMI_STR_ID strId;
            if (fota_update_result_evt->result == MMI_TRUE)
            {
                strId = STR_ID_DMUI_UPDATE_SUCCESS;
            }
            else
            {
                strId = STR_ID_DMUI_UPDATE_FAILURE;
            }
            vapp_nmgr_global_popup_show_confirm_one_button_id(
                MMI_SCENARIO_ID_DM,
                VCP_POPUP_TYPE_INFO,
                strId,
                STR_GLOBAL_OK,
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                NULL,
                NULL);
            break;
        }

        case SRV_DM_APP_ADP_EVT_FOTA_DISPLAY_UPDATE:
        {
            srv_dm_app_adp_evt_fota_display_update_struct *fota_display_update_evt =
                (srv_dm_app_adp_evt_fota_display_update_struct*)evt->arg;
            VappDmNmgr *nmgr;
            VFX_ALLOC_NEW_EX(
                nmgr,
                VappDmNmgr,
                VappDmEvtHdlr::getInstance(),
                (fota_display_update_evt,
                 sizeof(srv_dm_app_adp_evt_fota_display_update_struct),
                 vappDmFotaUpdateHdlr,
                 MMI_EVENT_INFO));
            break;
        }
    #endif /* __DM_FOTA_SUPPORT__ */

        case SRV_DM_APP_ADP_EVT_OTAP_INSTALL_PROF:
        {
        #ifdef __CCA_SUPPORT__
            vcui_dm_otap_create();
        #endif
            break;
        }

        case SRV_DM_APP_ADP_EVT_DISPLAY_NMGR_POPUP:
        {
            srv_dm_app_adp_evt_display_nmgr_popup_struct *display_nmgr_popup_evt =
                (srv_dm_app_adp_evt_display_nmgr_popup_struct*)evt->arg;
            mmi_nmgr_balloon_type_enum balloon_type;
            switch (display_nmgr_popup_evt->type)
            {
                case MMI_EVENT_FAILURE:
                    balloon_type = MMI_NMGR_BALLOON_TYPE_FAILURE;
                    break;

                case MMI_EVENT_INFO:
                    balloon_type = MMI_NMGR_BALLOON_TYPE_INFO;
                    break;

                case MMI_EVENT_WARNING:
                    balloon_type = MMI_NMGR_BALLOON_TYPE_WARNING;
                    break;

                case MMI_EVENT_SUCCESS:
                    balloon_type = MMI_NMGR_BALLOON_TYPE_SUCCESS;
                    break;

                case MMI_EVENT_PROGRESS:
                    balloon_type = MMI_NMGR_BALLOON_TYPE_PROGRESS;
                    break;

                default:
                    balloon_type = MMI_NMGR_BALLOON_TYPE_INFO;
                    break;
            }
            mmi_frm_nmgr_balloon(
                display_nmgr_popup_evt->scenario_id,
                MMI_EVENT_INFO_BALLOON,
                balloon_type,
                display_nmgr_popup_evt->string);
            break;
        }

        default:
            break;
    }
}


VappDmNmgr::VappDmNmgr(void *arg, VfxU32 argLen, mmi_noti_scrn_func_ptr nmgrHdlr, mmi_event_notify_enum type)
{
    VFX_ALLOC_MEM(m_arg, argLen, this);
    memcpy(m_arg, arg, argLen);
    m_nmgrHdlr = nmgrHdlr;
    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_DM,
        type,
        (mmi_noti_scrn_func_ptr)VappDmNmgr::nmgrHdlr,
        this);
}


VappDmNmgr::~VappDmNmgr()
{
    mmi_frm_nmgr_cancel_deferred_scenario(
        MMI_SCENARIO_ID_DM,
        (mmi_noti_scrn_func_ptr)VappDmNmgr::nmgrHdlr,
        this);
    VFX_FREE_MEM(m_arg);
}


MMI_BOOL VappDmNmgr::nmgrHdlr(mmi_scenario_id scenarioId, void *arg)
{
    VappDmNmgr *obj = (VappDmNmgr*)arg;
    mmi_frm_start_scenario(scenarioId);
    obj->m_nmgrHdlr(scenarioId, obj->m_arg);

    VFX_DELETE(obj);
    return MMI_TRUE;
}


void VappDmNmgr::cancelSessionNmgr()
{
    if (m_arg)
    {
        if (m_nmgrHdlr == vappDmSessionNotificationNmgrHdlr ||
            m_nmgrHdlr == vappDmSessionAlertNmgrHdlr)
        {
            VFX_DELETE(gDmNmgr);
        }
    }
}

#endif /* SYNCML_DM_SUPPORT */
