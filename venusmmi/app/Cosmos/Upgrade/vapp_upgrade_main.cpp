/*  Copyright Statement:
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
 *  vapp_upgrade_main.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

#ifdef __MMI_VPP_UPGRADE__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_upgrade_main.h"
#include "mmi_rp_vapp_upgrade_def.h"
#include "mmi_rp_srv_upgrade_def.h"
#include "mmi_rp_app_ncenter_def.h"

#include "vsrv_notification.h"
#include "vsrv_ncenter.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "Wgui_categories_util.h"
#include "NotificationGprot.h"
#include "UpgradeSrvGprot.h"
#include "mmi_inet_app_trc.h"
#include "DLAgentSrvProt.h"
#include "DLAgentSrvGProt.h"
#ifdef __cplusplus
}
#endif

/***************************************************************************** 
  * Define
  *****************************************************************************/

/***************************************************************************** 
  * Extern Function
  *****************************************************************************/
#if defined (__MMI_DOWNLOAD_AGENT__) && defined (BROWSER_SUPPORT)
extern "C"  MMI_ID vapp_dla_app_launch_ext(void *param, U32 param_size);
#endif

/***************************************************************************** 
  * Global Variable
  *****************************************************************************/
static VfxU32 g_upgrade_count[SRV_UPGRADE_ORIGINATOR_ALL] = {0};

/***************************************************************************** 
  * Implement
  *****************************************************************************/
VfxU32 vapp_upgrade_get_total_count()
{
    VfxU32 total = 0;
    
    for (int i = 0; i < (int)SRV_UPGRADE_ORIGINATOR_ALL; i++)
    {
        total += g_upgrade_count[i];
    }

	return total;
}

void vapp_upgrade_reset_count()
{
    for (int i = 0; i < (int)SRV_UPGRADE_ORIGINATOR_ALL; i++)
    {
        g_upgrade_count[i] = 0;
    }

    MMI_TRACE(TRACE_GROUP_7, TRC_MMI_VAPP_UPGRADE_RESET, vapp_upgrade_get_total_count());
}

void vapp_upgarde_discard_callback(srv_upgrage_originator_enum type)
{
    srv_upgrade_cancel(type);
    VSRV_NOTIFICATION_CLOSE_EX(VAPP_UPGRADE, type);

    /* Hide new updates icon on status bar */   
    wgui_status_icon_bar_hide_icon(STATUS_ICON_UPGRADE); 
}

void vapp_upgrade_ncenter_callback(
    VsrvNotification *noti, VsrvNIntent intent, void *userData, VfxU32 userDataSize)
{
    vapp_upgrade_ncenter_info_struct *info = (vapp_upgrade_ncenter_info_struct *)userData;

    switch (intent.type)
    {
        case VSRV_NINTENT_TYPE_LAUNCH:
        {
            MMI_TRACE(TRACE_GROUP_7, TRC_MMI_VAPP_UPGRADE_START, info->type, vapp_upgrade_get_total_count());

            if (vapp_upgrade_get_total_count() > 0)
            {
                srv_upgrade_download(info->type);
            }

            vapp_upgrade_reset_count();

            VSRV_NOTIFICATION_CLOSE_EX(VAPP_UPGRADE, info->type);
            
            /* Hide new updates icon on status bar */ 
            wgui_status_icon_bar_hide_icon(STATUS_ICON_UPGRADE); 

        #if defined (__MMI_DOWNLOAD_AGENT__) && defined (BROWSER_SUPPORT)
			srv_da_display_job_list_event_struct  evt;
			MMI_FRM_INIT_EVENT(&evt, EVT_ID_DLA_SRV_DISPLAY_JOB_LIST);
			evt.job = NULL;
			evt.list_type = SRV_DA_LIST_TYPE_DOWNLOADED;
			MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
        #endif
        
            break;
        }
        case VSRV_NINTENT_TYPE_CLEAR:
        {
            MMI_TRACE(TRACE_GROUP_7, TRC_MMI_VAPP_UPGRADE_CANCEL, info->type, vapp_upgrade_get_total_count());

            vapp_upgarde_discard_callback(info->type);
            break;
        }
    }
}

extern "C" mmi_ret vapp_upgrade_event_handler(mmi_event_struct *param)
{
    switch (param->evt_id)
    {
        case EVT_ID_SRV_UPGRADE_DOWNLOAD_REQ:
        {
            srv_upgrade_evt_download_req_struct *req = (srv_upgrade_evt_download_req_struct *)param;

            MMI_TRACE(TRACE_GROUP_7, TRC_MMI_VAPP_UPGRADE_REQ, req->info->originator, req->info->count, vapp_upgrade_get_total_count());

            g_upgrade_count[req->info->originator] = req->info->count;

            if (vapp_upgrade_get_total_count() > 0)
            {   
                VsrvNGroupSingleTitle *group = NULL;
                VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (VAPP_UPGRADE));
                group->setTitle(VFX_WSTR_RES(STR_ID_VAPP_UPGRADE));
             
                vapp_upgrade_ncenter_info_struct info;
                info.type = SRV_UPGRADE_ORIGINATOR_ALL;
                info.count = vapp_upgrade_get_total_count() ;

                VfxWString mainText = VfxWString().format("%d ", vapp_upgrade_get_total_count());
                mainText += (vapp_upgrade_get_total_count() == 1) ? VFX_WSTR_RES(STR_ID_VAPP_UPGRADE_NEW_UPDATE) : VFX_WSTR_RES(STR_ID_VAPP_UPGRADE_NEW_UPDATES);

                VsrvNotificationEvent *notification = NULL;
                VSRV_NOTIFICATION_CREATE_EX(notification, VsrvNotificationEvent, ((VsrvNGroup *)group, SRV_UPGRADE_ORIGINATOR_ALL));
                notification->setMainText(mainText);
                notification->setSubText(VFX_WSTR_RES(STR_ID_VAPP_UPGRADE_TAP_TO_DOWNLOAD));
                notification->setIcon(VfxImageSrc(IMG_ID_VAPP_UPGRADE_LIST_ICN));
                notification->setAutoLaunch(VFX_TRUE);
                notification->setIntentCallback(
                    vapp_upgrade_ncenter_callback, 
                    &info, 
                    sizeof(vapp_upgrade_ncenter_info_struct));
                notification->notify();

                /* Display new updates icon on status bar */ 
                wgui_status_icon_bar_show_icon(STATUS_ICON_UPGRADE);            
            }
            else
            {
                VSRV_NOTIFICATION_CLOSE_EX(VAPP_UPGRADE, SRV_UPGRADE_ORIGINATOR_ALL);

                /* Hide new updates icon on status bar */  
                wgui_status_icon_bar_hide_icon(STATUS_ICON_UPGRADE);            
            }

            break;
        }
        
        default:
            break;

    }
    return MMI_RET_OK;
}

#endif /*__MMI_VPP_UPGRADE__ */

