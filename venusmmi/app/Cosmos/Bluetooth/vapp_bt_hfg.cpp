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
 *  vapp_bt_hfg.cpp
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

#ifdef __MMI_HFP_SUPPORT__
extern "C" {
#include "mdi_audio.h"
#include "BthfSrvGprot.h"
}

#include "mmi_rp_vapp_bt_main_def.h"
#include "vapp_bt_server.h"
#include "vapp_bt_hfg.h"

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
VFX_IMPLEMENT_CLASS("VbtHfgProfile", VbtHfgProfile, VbtServer);
VbtHfgProfile *VbtHfgProfile::m_server;

/***************************************************************************** 
 * Function
 *****************************************************************************/
void vapp_hfg_init(void *param)
{
    VfxU32 mask = 0xffff;

    srv_bthf_init();

    VbtHfgProfile::m_service = srv_bthf_open();
    srv_bthf_set_notify(VbtHfgProfile::m_service, &VbtHfgProfile::srvNotify, mask, BTHF_MOP_NEW);
}

void vapp_hfg_deinit(void *param)
{
}

BTHFHandle VbtHfgProfile::m_service = 0;
VfxS32 VbtHfgProfile::srvNotify(BTHFHandle handle, VfxU32 evt, VfxU32 param)
{
    bthf_dev_info_struct devInfo;
    
    switch (evt) {
    case BTHF_EV_ATTACH:
        break;

    case BTHF_EV_REQ_ATTACH:

        srv_bthf_get_device_info(param, &devInfo);

		VFX_OBJ_CREATE(m_server, VbtHfgProfile, VFX_OBJ_GET_INSTANCE(VappPlatformContext));
		VbtServerAgent::launchServer(m_server, &devInfo.addr);
        m_server->m_devID = param;
        
        break;

    case BTHF_EV_REQ_ABORT:

        if (m_server)
        {
            m_server->stop();
            m_server = NULL;
        }
 
        break;
        
    case BTHF_EV_DETACH:

        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO,
            MMI_NMGR_BALLOON_TYPE_INFO,
            (VfxWChar *)GetString(STR_ID_VAPP_BT_HEADSET_DISCONNECT));
        
        if (m_server)
        {
            m_server->stop();
            m_server = NULL;
        }

        break;

     case BTHF_EV_VOL_CHANGE:
        
        mdi_audio_sync_volume_from_bt((U8)((param >> 16) & 0xffff));
            
        break;
         
    default:
        break;
    }
    return 0;
}

void VbtHfgProfile::onAuthorizeDone(VfxBool result)
{
    if (result)
        srv_bthf_accept(m_service, m_devID);
    else
        srv_bthf_reject(m_service, m_devID);
}


#endif // __MMI_HFP_SUPPORT__


