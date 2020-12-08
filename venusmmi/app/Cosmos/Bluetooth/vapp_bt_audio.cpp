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
 *  vapp_bt_audio.cpp
 *
 * Project:
 * --------
 *  Cosmos
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
extern "C" {
#include "MMI_features.h"
}

#if defined(__MMI_HFP_SUPPORT__) || defined(__MMI_A2DP_SUPPORT__)
extern "C" {
#include "gui_typedef.h"
#include "mmi_rp_srv_status_icons_def.h"
#include "wgui_categories_util.h"
#include "mdi_audio.h"
#include "BtAudioSrvGprot.h"
#include "BthfSrvGprot.h"
}

#include "mmi_frm_scenario_gprot.h"
#include "mmi_rp_vapp_bt_main_def.h"
#include "vapp_bt_server.h"
#include "vapp_bt_audio.h"
#include "vapp_nmgr_gprot.h" // for vcp_global_popup_show_confirm_one_button_str

#include "vapp_platform_context.h" // for VappPlatformContext


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VbtAudioApp", VbtAudioApp, VbtServer);
VbtAudioApp *VbtAudioApp::m_server;
VfxU32 VbtAudioApp::m_service;
VfxBool VbtAudioApp::m_attached;

/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C"
void vapp_btaud_init(void *param)
{
    VfxU32 mask = BTAUD_EV_ATTACH_IND |
                  BTAUD_EV_CHNL_UPDATE |
                  BTAUD_EV_ATTACH_REQ |
                  BTAUD_EV_DETACH_IND |
                  BTAUD_EV_ATTACH_ABORT |
                  BTAUD_EV_VOLUME_IND;
    srv_btaud_init();

    VbtAudioApp::m_service = srv_btaud_open(BTAUD_LEVEL_NORMAL, BTAUD_CHNL_ANY);
    srv_btaud_set_notify(VbtAudioApp::m_service, mask, &VbtAudioApp::srvNotify, NULL);
}

extern "C" void vapp_btaud_deinit(void *param)
{
#ifdef __MMI_HFP_SUPPORT__
	srv_btaud_close(VbtAudioApp::m_service);
	VbtAudioApp::m_service = 0;
	srv_bthf_deinit();
#endif
}

extern "C"
void mmi_bt_hfp_set_speaker_vol(VfxU32 volume)
{
    srv_btaud_set_volume(volume);
}

extern "C"
VfxBool mmi_bt_is_hf_car_kit_connected()
{
    VfxBool result = VFX_FALSE;
    
#if defined __MMI_HFP_SUPPORT__
    if (srv_bthf_get_status() > BTHF_STATUS_DETACH)
    {
        VfxU32 dev_id;
        bthf_dev_info_struct info;
        
        srv_bthf_list_device(&dev_id, 1);
        srv_bthf_get_device_info(dev_id, &info);

        if (info.dev_class == BTHF_DEV_CARKIT)
            result = VFX_TRUE;
    }
#endif

    return result;
}

void VbtAudioApp::srvNotify(BtAudEvent evt, VfxU32 arg, void *userData)
{
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_AUDIO_SRV_NOTIFY,evt);
    btaud_device_info devInfo;

    switch (evt) {
    case BTAUD_EV_ATTACH_IND:

        m_attached = VFX_TRUE;
        wgui_status_icon_bar_show_icon(STATUS_ICON_BT_EARPHONE_INDICATOR);

        break;

    case BTAUD_EV_CHNL_UPDATE:
        break;

    case BTAUD_EV_ATTACH_REQ:

        if (srv_btaud_get_device_info(BTAUD_CHNL_ANY, &devInfo))
        {
			if(srv_bt_cm_get_dev_num(SRV_BT_CM_PAIRED_DEV) < SRV_BT_CM_MAX_PAIRED_DEVICE_LIST
				|| srv_bt_cm_get_dev_index(&(devInfo.addr),SRV_BT_CM_PAIRED_DEV) != 0x0FFFFFFFF)
            {
				VFX_OBJ_CREATE(m_server, VbtAudioApp, VFX_OBJ_GET_INSTANCE(VappPlatformContext));
				VbtServerAgent::launchServer(m_server, &devInfo.addr);
			}
			else
			{
				vapp_nmgr_global_popup_show_confirm_one_button_str(
					MMI_SCENARIO_ID_BT_ACCESS_REQ,
					VCP_POPUP_TYPE_FAILURE,
					VFX_WSTR_RES(STR_ID_VAPP_BT_PAIR_LIST_FULL),  
					VFX_WSTR_RES(STR_GLOBAL_OK), 
					VCP_POPUP_BUTTON_TYPE_NORMAL,
					NULL,
					NULL);
			}
        }

        break;

    case BTAUD_EV_DETACH_IND:

        if (m_attached)
        {
            wgui_status_icon_bar_hide_icon(STATUS_ICON_BT_EARPHONE_INDICATOR);
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_BLUETOOTH,
                MMI_NMGR_BALLOON_TYPE_INFO,
                (VfxWChar *)GetString(STR_ID_VAPP_BT_HEADSET_DISCONNECT));
            m_attached = VFX_FALSE;
        }

    case BTAUD_EV_ATTACH_ABORT:

        if (m_server)
        {
            m_server->stop();
            m_server = NULL;
        }

        break;

     case BTAUD_EV_VOLUME_IND:
#if defined __MMI_HFP_SUPPORT__
        mdi_audio_sync_volume_from_bt((U8)arg);
#endif
        break;
         
    default:
        break;
    }
}

void VbtAudioApp::onAuthorizeDone(VfxBool result)
{
    if (result)
    {
	    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_AUDIO_AUTHORIZE_DONE,1);
        srv_btaud_accept(m_service);
    }
    else
    {
	    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_AUDIO_AUTHORIZE_DONE,0);
        srv_btaud_reject(m_service);
    }
}


#endif // __MMI_HFP_SUPPORT__


