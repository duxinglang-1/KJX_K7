
#include "mmi_features.h"
#ifdef __MMI_MUSIC_PLAYER_SLIM__

#ifdef __MMI_NCENTER_SUPPORT__

#ifndef __VAPP_MUSIC_PLAYER_SLIM_NCENTERCELL_H__
#define __VAPP_MUSIC_PLAYER_SLIM_NCENTERCELL_H__
#include "vsrv_ncenter.h"
#include "vsrv_notification.h"
#include "vapp_ncenter.h"
#include "vapp_music_player_slim.h"
#include "vapp_ncenter_base_cell.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "AppMgrSrvGprot.h"
#include "mmi_cb_mgr_gprot.h"
#ifdef __cplusplus
}
#endif

#ifdef __MMI_MAINLCD_480X800__
#define NCENTER_H 167
#elif __MMI_MAINLCD_320X480__ 
#define NCENTER_H 101
#else
#define NCENTER_H 93
#endif

typedef struct 
{
    MMI_EVT_PARAM_HEADER
    VfxS32 popup_handle;
} music_player_cancel_popup_event_struct;


/*****************************************************************************
 * Music Player Base Panel
 *****************************************************************************/
class VappNcenterMusicPlayerBase : public VfxControl
{
    VFX_DECLARE_CLASS(VappNcenterMusicPlayerBase);

protected:
    /* Music player control */
    VappMusicPlayerSession *m_session;
	
public:
    VappNcenterMusicPlayerBase() :
        m_session(NULL)
        {};
    virtual ~VappNcenterMusicPlayerBase();

// Override functions
protected:
    virtual void onPlayPause(void);
    virtual VfxS32 onPrev(void);
    virtual VfxS32 onNext(void);

protected:
    void getSessionControl(void);
    VfxBool isValidState(void);

};


class VappNcenterMusicPlayerInfoPanel : public VappNcenterMusicPlayerBase
{
    VFX_DECLARE_CLASS(VappNcenterMusicPlayerInfoPanel);

public:

    enum
    {
        BTN_PLAY,
        BTN_PREV,
        BTN_NEXT,
        BTN_COLSE
    };
	
	enum
    {
#ifdef __MMI_MAINLCD_480X800__
		PANEL_X = 8,
		PANEL_Y = 10,
		ICON_X = 12,
		ICON_Y = 11,
		NCENTER_PANEL_H = 152,
		NCENTER_PANEL_W = 464,
        PRAV_NEXT_BTN_X = 86,
        PRAV_NEXT_BTN_Y = 79,
        PRAV_NEXT_BTN_SIZE = 52,
        PLAY_BTN_H = 66,
        PLAY_BTN_W = 66,
        PLAY_BTN_Y = 72,
        TEXT_X = 90,
        TEXT_Y = 22,
        FONT_SIZE = 26
#elif __MMI_MAINLCD_320X480__ 
		PANEL_X = 3,
		PANEL_Y = 5,
		ICON_X = 12,
		ICON_Y = 7,
		NCENTER_PANEL_H = 96,
		NCENTER_PANEL_W = 314,
        PRAV_NEXT_BTN_X = 44,
        PRAV_NEXT_BTN_Y = 47,
        PRAV_NEXT_BTN_SIZE = 34,
        PLAY_BTN_H = 42,
        PLAY_BTN_W = 43,
        PLAY_BTN_Y = 43,
        TEXT_X = 46,
        TEXT_Y = 12,
        FONT_SIZE = 14
#else
		PANEL_X = 4,
		PANEL_Y = 5,
		ICON_X = 6,
		ICON_Y = 6,
		NCENTER_PANEL_H = 86,
		NCENTER_PANEL_W = 232,
        PRAV_NEXT_BTN_X = 25,
        PRAV_NEXT_BTN_Y = 44,
        PRAV_NEXT_BTN_SIZE = 30,
        PLAY_BTN_H = 36,
        PLAY_BTN_W = 36,
        PLAY_BTN_Y = 41,
        TEXT_X = 38,
        TEXT_Y = 11,
        FONT_SIZE = 13
#endif
    };

private:
	
    VfxS32 m_width;
    VfxS32 m_height;
	VfxImageFrame *m_background;
	VfxImageFrame *m_icon;
	VcpImageButton *m_close_btn;
	VfxS32	m_popup_id;
    VfxTextFrame *m_textTitle;
    VcpButton *m_play_btn;
    VcpButton *m_next_btn;
    VcpButton *m_prev_btn;  
	
public:
    virtual void onInit();
    void initUI(); // Create UI component
    void getSongInfo(void);
	void updatePanel();
	static void onConfirmButtonClick(VfxId id, void *userData);
	void onCloseButtonClick();
	VfxS32 getPopupID();
	void sendPostCloseExitpopup ();
    void onButtonClicked(VfxObject* obj, VfxId id);
    void onPlayStateCallback(MusicPlayCBEvtEnum cb_event, S32 result, VfxU32 ca_para_2);
    void setPlayPauseBtnImage(VfxBool isPlay);
	void setIsBtnDisabled(VfxBool isDisable);
};

/***************************************************************************** 
 * MusicPlayerNcenterBaseCell
*****************************************************************************/
class VappMusicPlayerNcenterCustomerCell: public VsrvNCell 
{
	VFX_DECLARE_CLASS(VappMusicPlayerNcenterCustomerCell);
public: 
	virtual void onCreateView(void * viewData,VfxU32 viewDataSize);
	virtual void onCloseView(); 
private:
	VappNcenterMusicPlayerInfoPanel *m_playback_panel;
	VfxTextFrame *m_text;
};
#endif //__MMI_NCENTER_SUPPORT__
#endif /*   __VAPP_MUSIC_PLAYER_NCENTERCELL_H__ */
#endif //__MMI_MUSIC_PLAYER_SLIM__