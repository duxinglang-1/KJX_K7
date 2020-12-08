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
 *  vapp_music_player_ncentercell.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  FTO Music Player notification center cell class
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__
#ifdef __MMI_NCENTER_SUPPORT__
#include "../cosmos/widget/vapp_widget_music_player.h"

#ifndef __VAPP_MUSIC_PLAYER_NCENTERCELL_H__
#define __VAPP_MUSIC_PLAYER_NCENTERCELL_H__
#include "vsrv_ncenter.h"
#include "vsrv_notification.h"
#include "vapp_ncenter.h"
#include "vapp_ncenter_base_cell.h"
#include "Vapp_music_player_ctrlplayback.h"
#include "Vapp_music_player_service.h"

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
#define NCENTER_H 88
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

public:
    VappNcenterMusicPlayerBase() :
        m_mplayerSrv(NULL),
        m_ctrlPlayback(NULL)
        {};
    ~VappNcenterMusicPlayerBase();

// Override functions
protected:
    virtual void onPrevNext(VfxBool is_next) {};
    virtual void onPlaybackStateChange(PlaybackStateEnum state) {};
    virtual void onMDICallback(VfxS32 result) {};
    virtual void onPlayPause(void);
    virtual void onPrev(void);
    virtual void onNext(void);

protected:
    void getAppControl(void);
    VfxBool isValidState(void);

protected:
    /* Music player control */
    VappMusicPlayerService *m_mplayerSrv;
    VappMusicPlayerCtrlPlayback *m_ctrlPlayback;
};


class VappNcenterMusicPlayerInfoPanel : public VappNcenterMusicPlayerBase
{
    VFX_DECLARE_CLASS(VappNcenterMusicPlayerInfoPanel);

public:
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
public:
	~VappNcenterMusicPlayerInfoPanel();
    virtual void onInit();
    void initUI(); // Create UI component
    void destroyUI(); // Destroy UI component, used when serialize
    void updatePanel(void);
	static void onConfirmButtonClick(VfxId id, void *userData);
	void onCloseButtonClick();
	VfxS32 getPopupID();
	void onMDICallback(VfxS32 result);
    void onButtonClicked(VfxObject* obj, VfxId id);
    void onPlaybackStateChange(PlaybackStateEnum state);
    //void onPrevNext(VfxBool is_next);
    //void onMDICallback(VfxS32 result);
    void updateButton(void);
	void sendPostCloseExitpopup ();
	static mmi_ret staticEventHandler(mmi_event_struct *evt);
private:
    enum
    {
        BTN_PLAY,
        BTN_PREV,
        BTN_NEXT,
        BTN_COLSE
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
};

/***************************************************************************** 
 * MusicPlayerNcenterBaseCell
*****************************************************************************/
class VappMusicPlayerNcenterCustomerCell: public VsrvNCell 
{
	VFX_DECLARE_CLASS(VappMusicPlayerNcenterCustomerCell);
public: 
	void onCreateView(void * viewData,VfxU32 viewDataSize);
	void onCloseView(); 
private:
	VappNcenterMusicPlayerInfoPanel *m_playback_panel;
	VfxTextFrame *m_text;
};
#endif //__MMI_NCENTER_SUPPORT__
#endif /*   __VAPP_MUSIC_PLAYER_NCENTERCELL_H__ */
#endif //__COSMOS_MUSICPLY__
