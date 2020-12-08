/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_email_api.cpp
 *
 * Project:
 * --------
 *  COSMOS Email
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "vapp_email_mgr.h"
#include "Vapp_email_gprot.h"

extern "C" {
#include "MMIDataType.h"
#include "FileMgrSrvGProt.h"
#include "ModeSwitchSrvGProt.h"
#include "BootupSrvGprot.h"
#include "ShutdownSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "EmailAppGprot.h"
#ifdef __MMI_USB_SUPPORT__
#include "mmi_rp_app_usbsrv_def.h"
#endif
#include "MMI_inet_app_trc.h"

mmi_ret vapp_email_init(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_SRV_BOOTUP_BEFORE_IDLE:
            VFX_OBJ_GET_INSTANCE(VappEmailMgr)->initEmailApp();
            break;

        default:
            break;
    }
	return MMI_RET_OK;
}


mmi_ret vapp_email_mgr_notify_hdlr(mmi_event_struct *event)
{
	switch (event->evt_id)
	{
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {
            srv_fmgr_notification_dev_plug_event_struct *plugInfo =
                (srv_fmgr_notification_dev_plug_event_struct*)event;

            if (event->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN)
            {
                VFX_OBJ_GET_INSTANCE(VappEmailMgr)->plugTcard(VFX_TRUE, plugInfo->drv_letters, plugInfo->count);
            }
            else
            {
                VFX_OBJ_GET_INSTANCE(VappEmailMgr)->plugTcard(VFX_FALSE, plugInfo->drv_letters, plugInfo->count);
            }
            break;
        }

		case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
		{
            srv_fmgr_notification_adv_action_event_struct *evt = (srv_fmgr_notification_adv_action_event_struct *)event;
            
            if (evt->state == SRV_FMGR_NOTIFICATION_STATE_AFTER)
            {
                VFX_OBJ_GET_INSTANCE(VappEmailMgr)->fmgrAdvAction();
            }
		    break;
		}

		case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
        {
            srv_fmgr_notification_format_event_struct *formatEvt =
                (srv_fmgr_notification_format_event_struct*)event;

            if (formatEvt->state == SRV_FMGR_NOTIFICATION_STATE_BEFORE)
            {
                VFX_OBJ_GET_INSTANCE(VappEmailMgr)->formatFileSystem(VFX_TRUE, formatEvt->drv_letter);
            }
            else if (formatEvt->state == SRV_FMGR_NOTIFICATION_STATE_AFTER)
            {
                VFX_OBJ_GET_INSTANCE(VappEmailMgr)->formatFileSystem(VFX_FALSE, formatEvt->drv_letter);
            }
            break;
		}

    #ifdef __MMI_USB_SUPPORT__
        case EVT_ID_USB_ENTER_MS_MODE:
        {
            VFX_OBJ_GET_INSTANCE(VappEmailMgr)->plugUsb(VFX_TRUE);
            break;
        }

        case EVT_ID_USB_EXIT_MS_MODE:
        {
            VFX_OBJ_GET_INSTANCE(VappEmailMgr)->plugUsb(VFX_FALSE);
            break;
        }
    #endif /* __MMI_USB_SUPPORT__ */

        case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
        {
            srv_mode_switch_notify_struct *flightMode = (srv_mode_switch_notify_struct*)event;
            if ((flightMode->curr_flight_mode == SRV_MODE_SWITCH_ON &&
                 flightMode->select_flight_mode == SRV_MODE_SWITCH_OFF))
            {
                VFX_OBJ_GET_INSTANCE(VappEmailMgr)->switchFlightMode(VFX_FALSE);
            }
            else if ((flightMode->curr_flight_mode == SRV_MODE_SWITCH_OFF &&
                      flightMode->select_flight_mode == SRV_MODE_SWITCH_ON))
            {
                VFX_OBJ_GET_INSTANCE(VappEmailMgr)->switchFlightMode(VFX_TRUE);
            }
            break;
        }

        case EVT_ID_SRV_SHUTDOWN_FINAL_DEINIT:
            VFX_OBJ_GET_INSTANCE(VappEmailMgr)->shutdown();
            break;

        case EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED:
        {
            srv_sim_ctrl_availability_changed_evt_struct *evt = (srv_sim_ctrl_availability_changed_evt_struct*)event;

            if (evt->is_available_before == evt->is_available_now)
            {
                return MMI_RET_OK;
            }

            VFX_OBJ_GET_INSTANCE(VappEmailMgr)->simAvailableChanged((evt->is_available_now == MMI_TRUE ? VFX_TRUE : VFX_FALSE));
            
            break;
        }

        default:
            break;
	}

    return MMI_RET_OK;
}

// dummy functions, should be removed
void mmi_email_main_goto_idle(void){}
U8   mmi_email_util_get_stop_cause(void){return 1;}
void mmi_email_highlight_main_menu(void){}
BOOL mmi_email_bearer_status_show_icon (){return FALSE;}
BOOL mmi_email_check_show_idle_data (){return FALSE;}
void mmi_email_show_idle_data (){}
void mmi_email_main_pre_entry_from_message (mmi_id parent_id){}
mmi_ret mmi_email_enter_usb_ms_callback(mmi_event_struct *event){return MMI_RET_OK;}
mmi_ret mmi_email_exit_usb_ms_callback(mmi_event_struct *event){return MMI_RET_OK;}
mmi_ret mmi_email_fmgr_reset_status_icon(mmi_event_struct *event){return MMI_RET_OK;}
mmi_ret mmi_email_notify_mount_memory_card_hdlr(mmi_event_struct *event){return MMI_RET_OK;}
mmi_ret mmi_email_notify_unmount_memory_card_hdlr(mmi_event_struct *event){return MMI_RET_OK;}
void mmi_email_main_entry_from_shortcut (void){}
void mmi_email_app_send_attch_from_vobj(const char *file_path, vobj_email_cb callback){}
void mmi_email_init (void){}
void mmi_email_nmgr_cancel(void){}
void mmi_email_nmgr_query(void){}
U8   mmi_email_check_vf_list(void){return 1;}


BOOL mmi_email_is_email_can_forward ()
{
    VappEmailStateEnum emailState = VappEmailMgr::getInstance()->getEmailAppState();
    if (emailState == VAPP_EMAIL_STATE_DEINITED ||
        emailState == VAPP_EMAIL_STATE_INITIALIZING ||
        emailState == VAPP_EMAIL_STATE_USB_MODE)
    {
        return FALSE;
    }

    return TRUE;
}

void mmi_email_fmgr_send(char *file_path, BOOL is_short)
{
    mmi_email_app_send_attch(file_path);
}

void mmi_email_app_send_to(const char *to_addr)
{
    mmi_email_app_send_to_ext(to_addr, NULL);
}

} /* extern "C" */
