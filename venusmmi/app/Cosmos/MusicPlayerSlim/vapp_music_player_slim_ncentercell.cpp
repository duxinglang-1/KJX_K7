
#include "mmi_features.h"
#ifdef __MMI_MUSIC_PLAYER_SLIM__

#ifdef __MMI_NCENTER_SUPPORT__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_global_popup.h"
#include "vapp_music_player_slim_ncentercell.h"
#include "vapp_music_player_slim.h"
#include "vapp_music_player_slim_util.h"
#include "mmi_rp_vapp_music_player_slim_def.h"
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
	VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (VAPP_MUSIC_PLAYER_SLIM));
	group->setTitle(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER));

	VsrvNotificationCustom *notify = NULL;
    VSRV_NOTIFICATION_CREATE_EX(notify, VsrvNotificationCustom, (VAPP_MUSIC_PLAYER_SLIM, 0));
	notify->setAutoLaunch(VFX_FALSE);
	notify->setAutoClose(VFX_FALSE);
	notify->addCustomViewInfo(VFX_OBJ_CLASS_INFO(VappMusicPlayerNcenterCustomerCell),VSRV_NVIEWER_TYPE_GENERAL,NULL,0);
	notify->setHeight(NCENTER_H);
    notify->notify();
}

mmi_ret vapp_music_player_on_open_close(mmi_event_struct *evt)
{
    VappMusicPlayerOpenCloseEvtStruct *openCloseEvt = (VappMusicPlayerOpenCloseEvtStruct*) evt;

    //MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NCENTER_ON_OPEN_CLOSE, openCloseEvt->isOpen);

    if(openCloseEvt->isOpen)
    {
        // do nothing
    }
    else
    {
        VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)VAPP_MUSIC_PLAYER_SLIM, 0);
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
    if(m_session != NULL)
    {
		m_session->m_signalSessionEvt.disconnect(this, &VappNcenterMusicPlayerInfoPanel::onPlayStateCallback);
    }
}

void VappNcenterMusicPlayerBase::getSessionControl(void)
{
    m_session = getMusicPlayerSession();
	m_session->m_signalSessionEvt.connect(this, &VappNcenterMusicPlayerInfoPanel::onPlayStateCallback);
}

void VappNcenterMusicPlayerBase::onPlayPause(void)
{
    if(m_session != NULL && isValidState())
	{
			VfxS32 ret = m_session->pauseResumePlay();
		}
	}

VfxS32 VappNcenterMusicPlayerBase::onPrev(void)
{
    if(m_session != NULL && isValidState())
    {
	    VfxS32 index;
	    VfxS32 ret = m_session->switchPrev(index);
	    return ret;
    }
	else
	{
		return -1;
	}
}

VfxS32 VappNcenterMusicPlayerBase::onNext(void)
{
    if(m_session != NULL && isValidState())
    {
	    VfxS32 index;
	    VfxS32 ret = m_session->switchNext(index);
	    return ret; 
    }
	else
	{
		return -1;
	}
}

VfxBool VappNcenterMusicPlayerBase::isValidState(void)
{
    if((m_session == NULL) || (m_session && (m_session->getCount()== 0)))
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}
/*****************************************************************************
 * Music PlayerVappNcenterMusicPlayerInfoPanel Class
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappNcenterMusicPlayerInfoPanel", VappNcenterMusicPlayerInfoPanel, VappNcenterMusicPlayerBase)

void VappNcenterMusicPlayerInfoPanel::onInit()
{
	VfxFrame::onInit();
	
	initUI();
	getSessionControl();
	updatePanel();
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
	m_play_btn->setPos(NCENTER_PANEL_W/2, PLAY_BTN_Y);
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

void VappNcenterMusicPlayerInfoPanel::onPlayStateCallback(MusicPlayCBEvtEnum cb_event, S32 result, VfxU32 ca_para_2)
{
    switch(cb_event)
    {
        case MUSIC_CB_SONG_SWITCHED:
        {
			getSongInfo();
            break;
        }
        case MUSIC_CB_INTERRUPT:
        {
            setPlayPauseBtnImage(VFX_FALSE);
            break;
        }
        case MUSIC_CB_PAUSE:
        {
            //handle song that can not pause
            if(result == VFX_FALSE)
            {
                VfxWString info = VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_ERROR_NOT_PAUSABLE);
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
                                     MMI_EVENT_INFO_BALLOON, 
                                     MMI_NMGR_BALLOON_TYPE_FAILURE, 
                                     (WCHAR*)info.getBuf());
			    m_session->stopPlay();
                setPlayPauseBtnImage(VFX_FALSE);
            }
            else
            {
                setPlayPauseBtnImage(VFX_FALSE);
            }
            break;
        }

        case MUSIC_CB_RESUME:
        {
            setPlayPauseBtnImage(VFX_TRUE);
            break;
        }
        case MUSIC_CB_SEEKING:
        {
			if(MUSIC_SUB_SEEKING_START == result)
			{
                m_prev_btn->setIsUnhittable(VFX_TRUE);
                m_next_btn->setIsUnhittable(VFX_TRUE);
                m_play_btn->setIsUnhittable(VFX_TRUE);
			}
			else if(MUSIC_SUB_SEEKING_DONE == result)
			{
                m_prev_btn->setIsUnhittable(VFX_FALSE);
                m_next_btn->setIsUnhittable(VFX_FALSE);
                m_play_btn->setIsUnhittable(VFX_FALSE);
			}
            break;
        }
        case MUSIC_CB_PLAY:
        {  
			if(MUSIC_RET_OK == result)
			{
	            setPlayPauseBtnImage(VFX_TRUE);
			}
			else
            {
                VfxWString info;
                info = VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_ERROR_CANNOT_PLAY);
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)info.getBuf());
                setPlayPauseBtnImage(VFX_FALSE);
            }

			break;
        }
        case MUSIC_CB_MSDC_PLUG_OUT:
        {
			updatePanel();
            break;
        }
	    case MUSIC_CB_LIST_END:
        {
            setPlayPauseBtnImage(VFX_FALSE);
            break;
        }
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

void VappNcenterMusicPlayerInfoPanel::getSongInfo()
{
    VfxWString title;
    if(isValidState())
    {
		VfxS32 index = m_session->getActiveIndex();
		if(index >= 0)
		{
			m_session->getTitle(index, title);
	        if(title.isEmpty())
	        {
	            title.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_UNKNOWN_SONG);
	        }
			setIsBtnDisabled(VFX_FALSE);
		}
		else
		{
            title.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_PLAYLIST_NO_SONG);
			setIsBtnDisabled(VFX_TRUE);
		}
	}
	else
	{
        title.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_PLAYLIST_NO_SONG);
		setIsBtnDisabled(VFX_TRUE);
	}
	m_textTitle->setString(title);
}

void VappNcenterMusicPlayerInfoPanel::updatePanel()
{
	getSongInfo();
	VfxS32 index = m_session->getActiveIndex();
	if(isValidState() && index >= 0)
	{
		PlaybackStateEnum state, stateBeforeSeek ;
		stateBeforeSeek = m_session->getPlayStateBeforeSeek();
		state = m_session->getPlayState();
		if(state == PB_STATE_PLAY || state == PB_STATE_SEEKING && stateBeforeSeek == PB_STATE_PLAY)
	{
		setPlayPauseBtnImage(VFX_TRUE);
			if(state == PB_STATE_SEEKING && stateBeforeSeek == PB_STATE_PLAY)
			{
				setIsBtnDisabled(VFX_TRUE);
			}
			else
			{
				setIsBtnDisabled(VFX_FALSE);
			}
	}
	else
	{
		setPlayPauseBtnImage(VFX_FALSE);
	}
	} 
	else
	{
		setPlayPauseBtnImage(VFX_FALSE);
}
}

void VappNcenterMusicPlayerInfoPanel::onConfirmButtonClick(VfxId id, void *userData)
{
	VappNcenterMusicPlayerInfoPanel *cell =(VappNcenterMusicPlayerInfoPanel*)userData;
	
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
		VappMusicPlayerAppSlim *app = getMusicPlayerSlimApp();
		
		if(app)
		{
			app->exit();
		}
						
	    VappMusicPlayerSession *session = getMusicPlayerSession();
		
	    if(session)
    	{
	        session->destorySession();
    	}
    }	
    else if (id == VCP_CONFIRM_POPUP_BUTTON_USER_2)
    {
    	vcp_global_popup_cancel(cell->getPopupID());
    }
}
void VappNcenterMusicPlayerInfoPanel::setPlayPauseBtnImage(VfxBool isPlay)
{
    VcpStateImage imgListPlayBtn;
    VfxBool in_call = VFX_FALSE;

    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        in_call = VFX_TRUE;
    }
    if(in_call ||!isValidState())
    {
    
		imgListPlayBtn.setImage(IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N_NC, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N_NC, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_D_NC, 0);
		setIsBtnDisabled(VFX_TRUE);
    }
    else
    {		
        if(isPlay)
        {
            imgListPlayBtn.setImage(IMG_ID_VAPP_MUSICPLY_BTN_PAUSE_NC, IMG_ID_VAPP_MUSICPLY_BTN_PAUSE_NC, 0, 0);
        }
        else
        {
            imgListPlayBtn.setImage(IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N_NC, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N_NC, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_D_NC, 0);
        }
    }
    m_play_btn->setImage(imgListPlayBtn);
}

void VappNcenterMusicPlayerInfoPanel::setIsBtnDisabled(VfxBool isDisable)
{
	if(isDisable)
	{
        m_play_btn->setIsDisabled(VFX_TRUE);
        m_prev_btn->setIsDisabled(VFX_TRUE);
        m_next_btn->setIsDisabled(VFX_TRUE);
	}
	else
	{
        m_play_btn->setIsDisabled(VFX_FALSE);
        m_prev_btn->setIsDisabled(VFX_FALSE);
        m_next_btn->setIsDisabled(VFX_FALSE);
	}
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
	m_playback_panel->sendPostCloseExitpopup();
	VFX_OBJ_CLOSE(m_playback_panel);
	VsrvNCell::onCloseView();
}
#endif//__MMI_NCENTER_SUPPORT
#endif //__MMI_MUSIC_PLAYER_SLIM__