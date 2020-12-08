/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   vapp_fm_radio_ncenter.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  FM Radio NCenter file
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 
#include "MMI_features.h"

#ifdef __MMI_FM_RADIO__

#if defined(__MMI_NCENTER_SUPPORT__)

#include "vapp_fm_radio.h"
#include "vapp_fm_radio_ncenter.h"
#include "vapp_fm_radio_util.h"
#include "vcp_global_popup.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "mmi_rp_vapp_fm_radio_def.h"
#include "mmi_rp_app_ncenter_def.h"
#include "MMI_media_app_trc.h"
#include "mmi_cb_mgr_gprot.h"
#include "AppMgrSrvGprot.h"


mmi_ret vapp_fm_radio_on_ncenter_update(mmi_event_struct *evt)
{
    vapp_fm_radio_ncenter_update_evt_struct *power_evt = (vapp_fm_radio_ncenter_update_evt_struct*) evt;

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_ON_NCENTER_UPDATE, power_evt->is_shown);

    if(power_evt->is_shown)
    {
    	// create fm group
		VsrvNGroupSingleTitle *fm_group;
		VSRV_NGROUP_CREATE_EX(fm_group, VsrvNGroupSingleTitle, (VAPP_FM_RADIO));
		fm_group->setTitle(VFX_WSTR_RES(STR_ID_VAPP_FM));

		// create fm notification
		VsrvNotificationCustom *fm_noti;
		VSRV_NOTIFICATION_CREATE_EX(fm_noti, VsrvNotificationCustom, ((VsrvNGroup*)fm_group, 0));
		fm_noti->setHeight(VappFmRadioNCell::FM_NCELL_HEIGHT);
		fm_noti->addCustomViewInfo(VFX_OBJ_CLASS_INFO(VappFmRadioNCell), VSRV_NVIEWER_TYPE_GENERAL);
		fm_noti->setCategory(VSRV_NOTIFICAITON_CUSTOM_CATEGORY_ONGOING);
		fm_noti->setAutoLaunch(VFX_FALSE);
		fm_noti->setAutoClose(VFX_FALSE);
		fm_noti->notify();		
	}
    else
    {
    	VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)VAPP_FM_RADIO, 0);
    }

    return MMI_OK;
}


static MMI_BOOL vapp_fm_radio_ncell_callback(mmi_scenario_id scen_id, void *user_data)
{   
    //dummy
    return MMI_TRUE;
}


// Confim to close FM Radio NCell
static void vapp_fm_radio_ncell_on_popup_exit(VfxId id, void *userData)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_NCELL_ON_POPUP_EXIT);

	vadp_fm_radio_set_global_popup_could_close(VFX_TRUE);

    if(id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
    	// close fm ncenter widget
        VsrvNotification* noti = (VsrvNotification*) userData;	
        VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);        
        if (nm->checkNotification(noti))
        {
            vsrv_ncenter_send_intent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_TERMINATE, noti);

			vsrv_ncenter_send_intent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_CLOSE, noti);
            VSRV_NOTIFICATION_CLOSE(noti);
        }
    }
}


/***************************************************************************** 
 * Class VappFmRadioNCell    
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappFmRadioNCell", VappFmRadioNCell, VsrvNCell);

void VappFmRadioNCell::onCreateView(void* viewData, VfxU32 viewDataSize)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_NCELL_ON_CREATE_VIEW);

    VsrvNCell::onCreateView(viewData, viewDataSize);
	setSize(FM_NCELL_WIDTH, FM_NCELL_HEIGHT);

	// create fm panel
	VFX_OBJ_CREATE_EX(m_fmPanel, VappWidgetFmRadioPanel, this, (VappWidgetFmRadioPanel::MODE_NCENTER));
	
	// create close image
    VFX_OBJ_CREATE(m_closeButton, VcpImageButton, this);
    m_closeButton->setImage(VcpStateImage(VAPP_IMG_NCENTER_CLOSE_ICON));
	m_closeButton->setAnchor(1.0f,0.0f);
    m_closeButton->setPos((getSize().width - VappWidgetFmRadioPanel::PN_IMAGE_BTN_X - VappWidgetFmRadioPanel::PN_X), (VappWidgetFmRadioPanel::PN_IMAGE_BTN_Y + VappWidgetFmRadioPanel::PN_Y));	
	m_closeButton->setSize(VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_WIDTH, VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_HEIGHT);    
    m_closeButton->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);
	m_closeButton->m_signalClicked.connect(this, &VappFmRadioNCell::onCloseButtonClicked);
}

void VappFmRadioNCell::onCloseView()
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_NCELL_ON_CLOSE_VIEW, m_fmPanel->m_state);

    VFX_OBJ_CLOSE(m_closeButton);
    VFX_OBJ_CLOSE(m_fmPanel);
}

void VappFmRadioNCell::onProcessIntent(VsrvNotification* noti, VsrvNIntent intent, void* viewData, VfxU32 viewDataSize)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_NCELL_ON_PROCESS_INTENT, intent);

	// no need to process VSRV_NINTENT_TYPE_LAUNCH type
    if (intent.type == VSRV_NINTENT_TYPE_TERMINATE)
	{
		m_fmPanel->powerOff();
	}
}

void VappFmRadioNCell::onCloseButtonClicked(VfxObject* sender, VfxId id)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_NCELL_ON_CLOSE_BUTTON_CLICKED);

    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_WARNING, &vapp_fm_radio_ncell_callback, this);

	VfxU32 popupHandle = vcp_global_popup_show_confirm_two_button_str(GRP_ID_ROOT,
							VCP_POPUP_TYPE_WARNING,
					        VFX_WSTR_RES(STR_ID_VAPP_FM_POWER_OFF_FM_Q),
					        VFX_WSTR_RES(STR_GLOBAL_OK),
					        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
					        VCP_POPUP_BUTTON_TYPE_WARNING,
					        VCP_POPUP_BUTTON_TYPE_CANCEL,
					        &vapp_fm_radio_ncell_on_popup_exit,
					        getNotification()
					        ); 
	vadp_fm_radio_set_global_popup_handle(popupHandle);
}

#ifdef __cplusplus
}
#endif

#endif // defined(__MMI_NCENTER_SUPPORT__)

#endif /* __MMI_FM_RADIO__ */
