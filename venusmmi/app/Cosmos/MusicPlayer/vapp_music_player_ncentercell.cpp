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
 *  vapp_music_player_ncentercell.cpp
 *
 * Project:
 * --------
 *  FTO Music Player notification center cell class
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

#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__
#ifdef __MMI_NCENTER_SUPPORT__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_global_popup.h"
#include "vapp_music_player_ncentercell.h"
#include "vapp_music_player.h"
#include "vapp_music_player_util.h"
#include "mmi_rp_vapp_music_player_def.h"
#include "vsrv_ncenter.h"

/* Pluto MMI headers */
#ifdef __cplusplus
extern "C"
{
#endif
#include "UCMSrvGProt.h"
#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Event receiver functions
 *****************************************************************************/
 VfxBool g_close_exit_popup = TRUE;

#ifdef __cplusplus
extern "C"
{
#endif
void vapp_music_player_update_cell()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NCENTER_UPDATE_CELL);

    VsrvNGroupSingleTitle *group;
	VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (VAPP_MUSIC_PLAYER));
	group->setTitle(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER));

	VsrvNotificationCustom *notify = NULL;
    VSRV_NOTIFICATION_CREATE_EX(notify, VsrvNotificationCustom, (VAPP_MUSIC_PLAYER, 0));
	notify->setAutoLaunch(VFX_FALSE);
	notify->setAutoClose(VFX_FALSE);
    //notify->setIntentCallback(vapp_music_player_Intent_callback, NULL, 0);
	notify->addCustomViewInfo(VFX_OBJ_CLASS_INFO(VappMusicPlayerNcenterCustomerCell),VSRV_NVIEWER_TYPE_GENERAL,NULL,0);
	notify->setHeight(NCENTER_H);
    notify->notify();
}

mmi_ret vapp_music_player_on_open_close(mmi_event_struct *evt)
{
    VappMusicPlayerOpenCloseEvtStruct *openCloseEvt = (VappMusicPlayerOpenCloseEvtStruct*) evt;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NCENTER_ON_OPEN_CLOSE, openCloseEvt->isOpen);

    if(openCloseEvt->isOpen)
    {
        // do nothing
    }
    else
    {
        VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)VAPP_MUSIC_PLAYER, 0);
    }

    return MMI_RET_OK;
}
mmi_ret vapp_music_player_on_show_hide(mmi_event_struct *evt)
{
    //MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NCENTER_ON_SHOW_HIDE, showHideEvt->isShow);
	vapp_music_player_update_cell();

    return MMI_RET_OK;
}

mmi_ret vapp_music_player_on_play_start_stop(mmi_event_struct *evt)
{
    VsrvNCenter *srvNCenter = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
    if (srvNCenter && !srvNCenter->queryNGroup(VAPP_MUSIC_PLAYER))
    {
        return MMI_RET_OK;
    }

   // MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NCENTER_ON_PLAY_START_STOP, playEvt->isPlayStart);

    vapp_music_player_update_cell();

    return MMI_RET_OK;
}

#ifdef __cplusplus
}
#endif

static mmi_ret cancel_global_popup(mmi_event_struct *evt)
{
    music_player_cancel_popup_event_struct *evnt = (music_player_cancel_popup_event_struct *)evt;
    VfxS32 popuphandle = evnt->popup_handle;
    
    if (popuphandle != NULL && g_close_exit_popup)
    { 
        vcp_global_popup_cancel(popuphandle); 

    }
    g_close_exit_popup = TRUE;
    return MMI_RET_OK;
}

static MMI_BOOL VappMusicPlayerNCellCallback(mmi_scenario_id scen_id, void *user_data)
{   
    //dummy
    return MMI_TRUE;
}

/*****************************************************************************
 * Music Player Widget Base Panel Class
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappNcenterMusicPlayerBase", VappNcenterMusicPlayerBase, VfxControl);

VappNcenterMusicPlayerBase::~VappNcenterMusicPlayerBase()
{
    /* Disconnect app signal */
    if(m_mplayerSrv != NULL)
    {
        m_mplayerSrv->m_signalOnPrevNext.disconnect(this, &VappNcenterMusicPlayerBase::onPrevNext);
    }

    /* Disconnect playback singal */
    if(m_ctrlPlayback != NULL)
    {
        m_ctrlPlayback->m_signalPlaybackStateChange.disconnect(this, &VappNcenterMusicPlayerBase::onPlaybackStateChange);
        m_ctrlPlayback->m_signalMDICallback.disconnect(this, &VappNcenterMusicPlayerBase::onMDICallback);
    }
}

void VappNcenterMusicPlayerBase::getAppControl(void)
{
    m_mplayerSrv = getMusicPlayerSrv();

    if(m_mplayerSrv)
    {
        m_mplayerSrv->m_signalOnPrevNext.connect(this, &VappNcenterMusicPlayerBase::onPrevNext);

        /* Get playback control and connect state change */
        m_ctrlPlayback = m_mplayerSrv->getCtrlPlayback();
        m_ctrlPlayback->m_signalPlaybackStateChange.connect(this, &VappNcenterMusicPlayerBase::onPlaybackStateChange);
        m_ctrlPlayback->m_signalMDICallback.connect(this, &VappNcenterMusicPlayerBase::onMDICallback);
    }
}

void VappNcenterMusicPlayerBase::onPlayPause(void)
{
    if(m_ctrlPlayback != NULL)
    {
		m_ctrlPlayback->setIsAppMode(TRUE);
        PlaybackStateEnum state;
        state = m_ctrlPlayback->getPlayState();
    
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_WIDGET_MUSICPLY_INFO_PANEL_BTN_CLICK, state);
    
        if(PB_STATE_PLAY == state ||
           PB_STATE_PAUSE == state ||
           PB_STATE_OPEN == state ||
           PB_STATE_STOP == state ||
           PB_STATE_CLOSE == state ||                   
           PB_STATE_SWITCHING_PLAY == state ||
           PB_STATE_SWITCHING_NOT_PLAY == state ||
           PB_STATE_INTERRUPTED == state ||
           PB_STATE_BT_CONNECTING_WHILE_PLAYING == state)
        {
            /* Stop the song if the song is not pausable */
            if ((state == PB_STATE_PLAY || state == PB_STATE_BT_CONNECTING_WHILE_PLAYING) &&
                !m_ctrlPlayback->isSongPausable(NULL))
            {
                m_ctrlPlayback->stop();
            }
            else if (m_ctrlPlayback->m_playStateBeforeSeek == PB_STATE_PAUSE)
            {
                // do seek while pasued
                if(m_mplayerSrv)
                {
                    m_mplayerSrv->setPlayAfterSwitchSong(VFX_TRUE);
                }
                m_ctrlPlayback->play();
            }
            else
            {
                if(m_mplayerSrv)
                {
                    m_mplayerSrv->setPlayAfterSwitchSong(VFX_TRUE);
                }
                m_ctrlPlayback->playpause();
            }
        }
    }

}

void VappNcenterMusicPlayerBase::onPrev(void)
{
    if(m_mplayerSrv != NULL && isValidState())
    {
        /* Control music player to previous song */
        m_mplayerSrv->onPrev(VFX_TRUE);
    }
}

void VappNcenterMusicPlayerBase::onNext(void)
{
    if(m_mplayerSrv != NULL && isValidState())
    {
        /* Control music player to next song */
        m_mplayerSrv->onNext(NEXT, VFX_TRUE);
    }

}

VfxBool VappNcenterMusicPlayerBase::isValidState(void)
{
    if((m_mplayerSrv == NULL) || (m_mplayerSrv && (m_mplayerSrv->getActiveCount() == 0)))
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}
/*****************************************************************************
 * Music PlayerVappNcenterMusicPlayerInfoPanel Class
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappNcenterMusicPlayerInfoPanel", VappNcenterMusicPlayerInfoPanel, VappNcenterMusicPlayerBase)

VappNcenterMusicPlayerInfoPanel::~VappNcenterMusicPlayerInfoPanel()
{
    /* Deregister app event callback */
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UCM_STATUS_CHANGE,(mmi_proc_func)&VappNcenterMusicPlayerInfoPanel::staticEventHandler, this);
}

void VappNcenterMusicPlayerInfoPanel::onInit()
{
	VfxFrame::onInit();
	initUI();
	getAppControl();
	updateButton();
	updatePanel();

    mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_STATUS_CHANGE,(mmi_proc_func)&VappNcenterMusicPlayerInfoPanel::staticEventHandler, this);
}

void VappNcenterMusicPlayerInfoPanel::initUI()
{		
	this->setPos(PANEL_X, PANEL_Y);
	this->setSize(NCENTER_PANEL_W, NCENTER_PANEL_H);
	this->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE);

	VFX_OBJ_CREATE(m_background, VfxImageFrame, this);
    m_background->setResId(IMG_ID_VAPP_MUSICPLY_BTN_BG_PANEL_NC);
    m_background->setRect(0, 0, this->getSize().width, this->getSize().height);
	m_background->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE);
    m_background->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    // icon
    VFX_OBJ_CREATE(m_icon, VfxImageFrame, this);
    m_icon->setPos(ICON_X, ICON_Y);
    m_icon->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_NONE,VFX_FRAME_ALIGNER_MODE_NONE);
    m_icon->setResId(IMG_ID_VAPP_MUSICPLY_NCENTER_ICON);

    // btn_close
    VFX_OBJ_CREATE(m_close_btn, VcpImageButton, this);
	m_close_btn->setAnchor(1.0f, 0.0f);
	m_close_btn->setPos(NCENTER_PANEL_W-ICON_X, ICON_Y);
	m_close_btn->setSize(VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_WIDTH,VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_HEIGHT);
    m_close_btn->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE,VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_NONE);
	m_close_btn->setId(BTN_COLSE);
    m_close_btn->setImage(VcpStateImage(VAPP_IMG_NCENTER_CLOSE_ICON));
	m_close_btn->m_signalClicked.connect(this,&VappNcenterMusicPlayerInfoPanel::onButtonClicked);

	
    // Song title
    VFX_OBJ_CREATE(m_textTitle, VfxTextFrame, this);
	m_textTitle->setSize(NCENTER_PANEL_W-TEXT_X*2,m_textTitle->getSize().height);
	m_textTitle->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(FONT_SIZE)));
	m_textTitle->setPos(TEXT_X, TEXT_Y);
	m_textTitle->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	m_textTitle->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);

    /* Create button */
	VFX_OBJ_CREATE(m_prev_btn,VcpButton,this);
    m_prev_btn->setId(BTN_PREV);
	m_prev_btn->setPos(PRAV_NEXT_BTN_X, PRAV_NEXT_BTN_Y);
	m_prev_btn->setImage(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_PREV_N_NC, IMG_ID_VAPP_MUSICPLY_BTN_PREV_N_NC, IMG_ID_VAPP_MUSICPLY_BTN_PREV_D_NC, 0));
	m_prev_btn->setBgImageList(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_BG2_N_NC, IMG_ID_VAPP_MUSICPLY_BTN_BG2_D_NC, IMG_ID_VAPP_MUSICPLY_BTN_BG2_N_NC, 0));
	m_prev_btn->setSize(PRAV_NEXT_BTN_SIZE, PRAV_NEXT_BTN_SIZE);
	m_prev_btn->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_NONE);
	m_prev_btn->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_prev_btn->setMargin(0,0,0,0);
	m_prev_btn->m_signalClicked.connect(this, &VappNcenterMusicPlayerInfoPanel::onButtonClicked);
  m_prev_btn->setFuzzy(VFX_FALSE);
	
	VFX_OBJ_CREATE(m_play_btn,VcpButton,this);
    m_play_btn->setId(BTN_PLAY);
	m_play_btn->setAnchor(0.5f, 0.0f);
	m_play_btn->setPos(VAPP_NCENTER_ONGOING_CELL_WIDTH/2, PLAY_BTN_Y);
	m_play_btn->setImage(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N_NC, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N_NC, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_D_NC, 0));
	m_play_btn->setBgImageList(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_BG1_N_NC, IMG_ID_VAPP_MUSICPLY_BTN_BG1_D_NC, IMG_ID_VAPP_MUSICPLY_BTN_BG1_N_NC, 0));
	m_play_btn->setSize(PLAY_BTN_W, PLAY_BTN_H);
	m_play_btn->setIsAutoResized(VFX_FALSE);
	m_play_btn->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_NONE);
	m_play_btn->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_play_btn->setMargin(0,0,0,0);
    m_play_btn->m_signalClicked.connect(this, &VappNcenterMusicPlayerInfoPanel::onButtonClicked);
  m_play_btn->setFuzzy(VFX_FALSE);

	VFX_OBJ_CREATE(m_next_btn,VcpButton,this);
    m_next_btn->setId(BTN_NEXT);
	m_next_btn->setAnchor(1.0f, 0.0f);
	m_next_btn->setPos(NCENTER_PANEL_W-PRAV_NEXT_BTN_X, PRAV_NEXT_BTN_Y);
	m_next_btn->setImage(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_NEXT_N_NC, IMG_ID_VAPP_MUSICPLY_BTN_NEXT_N_NC, IMG_ID_VAPP_MUSICPLY_BTN_NEXT_D_NC, 0));
	m_next_btn->setBgImageList(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_BG2_N_NC, IMG_ID_VAPP_MUSICPLY_BTN_BG2_D_NC, IMG_ID_VAPP_MUSICPLY_BTN_BG2_N_NC, 0));
	m_next_btn->setSize(PRAV_NEXT_BTN_SIZE, PRAV_NEXT_BTN_SIZE);
	m_next_btn->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_MID, VFX_FRAME_ALIGNER_MODE_NONE);
	m_next_btn->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_next_btn->setMargin(0,0,0,0);
	m_next_btn->m_signalClicked.connect(this, &VappNcenterMusicPlayerInfoPanel::onButtonClicked);
	m_next_btn->setFuzzy(VFX_FALSE);
}
void VappNcenterMusicPlayerInfoPanel::destroyUI()
{
    VFX_OBJ_CLOSE(m_textTitle);
	VFX_OBJ_CLOSE(m_background);
	VFX_OBJ_CLOSE(m_icon);
	VFX_OBJ_CLOSE(m_close_btn);
    VFX_OBJ_CLOSE(m_play_btn);
    VFX_OBJ_CLOSE(m_prev_btn);
    VFX_OBJ_CLOSE(m_next_btn);
	sendPostCloseExitpopup();
}

void VappNcenterMusicPlayerInfoPanel::sendPostCloseExitpopup()
{
	if ( m_popup_id != NULL)
	{
		music_player_cancel_popup_event_struct postInvoke;
	    MMI_FRM_INIT_EVENT(&postInvoke, 0);
	    postInvoke.popup_handle = m_popup_id;
	    MMI_FRM_POST_EVENT(&postInvoke, (mmi_proc_func)&cancel_global_popup, NULL);  
	}
}

void VappNcenterMusicPlayerInfoPanel::onButtonClicked(VfxObject* obj, VfxId id)
{
   /* if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        return;
    }*/

    switch(id)
    {
        case BTN_PLAY:
            onPlayPause();
            break;
        case BTN_PREV:
            onPrev();
            break;
        case BTN_NEXT:
            onNext();
            break;
		case BTN_COLSE:
			onCloseButtonClick();
        default:
            break;
    }
}    

void VappNcenterMusicPlayerInfoPanel::onPlaybackStateChange(PlaybackStateEnum state)
{
    switch(state)
    {
        case PB_STATE_NONE:
            /* Check if app clear its active list */
            if(!isValidState())
            {
                updatePanel();
                return;
            }
            break;
        case PB_STATE_OPEN:
            updatePanel();
            break;
        case PB_STATE_PLAY:
            updateButton();
            break;
        case PB_STATE_PAUSE:
            updateButton();
            break;
        case PB_STATE_STOP:
            updateButton();
            break;
        case PB_STATE_CLOSE:
            updatePanel();
            break;
        case PB_STATE_PLAYBACK_FAIL:
            updateButton();
            break;
        default:
            updateButton();
            break;
    }
}

void VappNcenterMusicPlayerInfoPanel::onMDICallback(VfxS32 result)
{
    switch (result)
    {
        case VAPP_MUSICPLY_INTERRUPT_CB_RESUME:
			if(m_popup_id != NULL)
			{
				g_close_exit_popup = FALSE;

			}

            break;

        default:
            break;
    }
}

void VappNcenterMusicPlayerInfoPanel::onCloseButtonClick()
{

    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_WARNING, &VappMusicPlayerNCellCallback, this);
	
	m_popup_id = vcp_global_popup_show_confirm_two_button_id(
		      GRP_ID_ROOT,
		      VCP_POPUP_TYPE_WARNING,
		      STR_ID_VAPP_MUSIC_PLAYER_POPUP_CLOSE_HINT,
		      STR_GLOBAL_OK,
		      STR_GLOBAL_CANCEL,
		      VCP_POPUP_BUTTON_TYPE_WARNING,
		      VCP_POPUP_BUTTON_TYPE_CANCEL,
		      &VappNcenterMusicPlayerInfoPanel::onConfirmButtonClick,
		      (void*)this);
}

VfxS32 VappNcenterMusicPlayerInfoPanel::getPopupID()
{
	return m_popup_id;
}

void VappNcenterMusicPlayerInfoPanel::updatePanel()
{
    if(isValidState())
    {
        srv_plst_media_details_struct detail_info;
        //VFX_ALLOC_MEM(detail_info, sizeof(srv_plst_media_details_struct), this);
        if(m_mplayerSrv->getCurrDetailInfo(&detail_info))
        {
            m_textTitle->setString(VFX_WSTR_MEM(detail_info.title));
        }
        else
        {
            m_textTitle->setString(STR_ID_VAPP_MUSIC_PLAYER_PLAYLIST_NO_SONG);
        }
        //VFX_FREE_MEM(detail_info);
    }
    else
    {
        m_textTitle->setString(STR_ID_VAPP_MUSIC_PLAYER_PLAYLIST_NO_SONG);
    }
    updateButton();
}

void VappNcenterMusicPlayerInfoPanel::onConfirmButtonClick(VfxId id, void *userData)
{
	VappNcenterMusicPlayerInfoPanel *cell =(VappNcenterMusicPlayerInfoPanel*)userData;
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        // close APP
    	VappMusicPlayerApp *app = getMusicPlayerApp();
    	if (app)
    	{
        	app->goToRoot();
    	}
		
        VappMusicPlayerService *srv = getMusicPlayerSrv();
        if (srv)
        {
           srv->closeMusicPlayer();
        }
    }	
    else if (id == VCP_CONFIRM_POPUP_BUTTON_USER_2)
    {
    	vcp_global_popup_cancel(cell->getPopupID());
    }
}
void VappNcenterMusicPlayerInfoPanel::updateButton(void)
{
    VcpStateImage imgListPlayBtn;
    VfxBool in_call = VFX_FALSE;

    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        in_call = VFX_TRUE;
    }

    if(in_call || (m_ctrlPlayback == NULL) || !isValidState())
    {
    
		imgListPlayBtn.setImage(IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N_NC, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N_NC, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_D_NC, 0);
        m_play_btn->setIsDisabled(VFX_TRUE);
        m_prev_btn->setIsDisabled(VFX_TRUE);
        m_next_btn->setIsDisabled(VFX_TRUE);
    }
    else
    {
        VfxBool isPlayImage = VFX_TRUE;
        
        if (m_ctrlPlayback)
        {
            isPlayImage = m_ctrlPlayback->getPlayPauseState();
        }
        if(isPlayImage)
        {
            imgListPlayBtn.setImage(IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N_NC, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N_NC, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_D_NC, 0);
        }
        else
        {
            imgListPlayBtn.setImage(IMG_ID_VAPP_MUSICPLY_BTN_PAUSE_NC, IMG_ID_VAPP_MUSICPLY_BTN_PAUSE_NC, 0, 0);
        }

        // Check if need to disable play icon
        // Playback fail or interrupted in playback fail state, do not enable UI
        InterruptStruct interrupt = m_ctrlPlayback->getInterruptedInfo();
        PlaybackStateEnum state = m_ctrlPlayback->getPlayState();

        if (( state == PB_STATE_PLAYBACK_FAIL) || (interrupt.isInterrupted && (interrupt.state == PB_STATE_PLAYBACK_FAIL)))
        {
            m_play_btn->setIsDisabled(VFX_TRUE);
        }
        else
        {
            m_play_btn->setIsDisabled(VFX_FALSE);
        }

        // Set button unhittable when switching play
        if (state == PB_STATE_SWITCHING_PLAY || state == PB_STATE_SWITCHING_NOT_PLAY || state == PB_STATE_SEEKING)
        {
            // Make button up when change song
            m_play_btn->setState(VCP_BUTTON_STATE_NORMAL);
            m_play_btn->setIsUnhittable(VFX_TRUE);
            m_prev_btn->setState(VCP_BUTTON_STATE_NORMAL);
            m_prev_btn->setIsUnhittable(VFX_TRUE);
            m_next_btn->setState(VCP_BUTTON_STATE_NORMAL);
            m_next_btn->setIsUnhittable(VFX_TRUE);
        }
        else
        {
            m_play_btn->setIsUnhittable(VFX_FALSE);
            m_prev_btn->setIsUnhittable(VFX_FALSE);
            m_next_btn->setIsUnhittable(VFX_FALSE);
        }
        m_prev_btn->setIsDisabled(VFX_FALSE);
        m_next_btn->setIsDisabled(VFX_FALSE);
    }
    m_play_btn->setImage(imgListPlayBtn);
}

mmi_ret VappNcenterMusicPlayerInfoPanel::staticEventHandler(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_SRV_UCM_STATUS_CHANGE:
        {
            VappNcenterMusicPlayerInfoPanel* ncenter = (VappNcenterMusicPlayerInfoPanel*) evt->user_data;

            if(ncenter->m_play_btn)
            {
                VcpStateImage imgListPlayBtn;
                imgListPlayBtn.setImage(IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N_NC, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N_NC, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_D_NC, 0);
                ncenter->m_play_btn->setImage(imgListPlayBtn);

                if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
                {
                    ncenter->m_play_btn->setIsDisabled(VFX_TRUE);
                    ncenter->m_prev_btn->setIsDisabled(VFX_TRUE);
                    ncenter->m_next_btn->setIsDisabled(VFX_TRUE);
                }
                else
                {
                    if(ncenter->isValidState())
                    {
                        ncenter->m_play_btn->setIsDisabled(VFX_FALSE);
                        ncenter->m_prev_btn->setIsDisabled(VFX_FALSE);
                        ncenter->m_next_btn->setIsDisabled(VFX_FALSE);
                    }
                }
            }
            break;
        }
        default:
            break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * Music Player NCenter BaseCell Class
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerNcenterCustomerCell",VappMusicPlayerNcenterCustomerCell, VsrvNCell);

void VappMusicPlayerNcenterCustomerCell::onCreateView(void *viewData,VfxU32 viewDataSize)
{
	VsrvNCell::onCreateView(viewData, viewDataSize);
	this->setSize(VAPP_NCENTER_ONGOING_CELL_WIDTH, NCENTER_H);
	
	VFX_OBJ_CREATE(m_playback_panel, VappNcenterMusicPlayerInfoPanel, this);
}

void VappMusicPlayerNcenterCustomerCell::onCloseView()
{
	m_playback_panel->destroyUI();
	VFX_OBJ_CLOSE(m_playback_panel);
	
	VsrvNCell::onCloseView();
}
#endif//__MMI_NCENTER_SUPPORT
#endif //__COSMOS_MUSICPLY__
