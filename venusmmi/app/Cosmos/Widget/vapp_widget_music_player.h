/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_widget_music_player.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the cosmos music player widget.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_WIDGET_MUSIC_PLAYER_H
#define VAPP_WIDGET_MUSIC_PLAYER_H

#include "MMI_features.h"

#if defined(__COSMOS_MUSICPLY__) && defined(__MMI_VUI_WIDGET_MUSIC_PLAYER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"
#include "vapp_widget_def.h"
#include "vapp_widget.h"

#include "../cosmos/musicplayer/Vapp_music_player.h"
#include "../cosmos/musicplayer/Vapp_music_player_ctrlplsv.h"
#include "../cosmos/musicplayer/Vapp_music_player_ctrlplayback.h"
#include "../cosmos/musicplayer/vapp_music_player_include.h"
#include "../cosmos/musicplayer/Vapp_music_player_service.h"

#ifdef __MMI_MAINLCD_480X800__
#define WIDGET_MP_WIDTH (425)
#define WIDGET_MP_HEIGHT (226)
#define WIDGET_MP_TITLE_FONT_SIZE (28)
#define WIDGET_MP_SUB_TITLE_FONT_SIZE (20)
#define WIDGET_MP_GET_BUFFER_OFFSET_X (14)
#define WIDGET_MP_GET_BUFFER_OFFSET_Y (17)
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
#define WIDGET_MP_WIDTH (212)
#define WIDGET_MP_HEIGHT (114)
#define WIDGET_MP_TITLE_FONT_SIZE (14)
#define WIDGET_MP_SUB_TITLE_FONT_SIZE (11)
#define WIDGET_MP_GET_BUFFER_OFFSET_X (10)
#define WIDGET_MP_GET_BUFFER_OFFSET_Y (10)
#else /*320x480*/
#define WIDGET_MP_WIDTH (286)
#define WIDGET_MP_HEIGHT (154)
#define WIDGET_MP_TITLE_FONT_SIZE (20)
#define WIDGET_MP_SUB_TITLE_FONT_SIZE (13)
#define WIDGET_MP_GET_BUFFER_OFFSET_X (14)
#define WIDGET_MP_GET_BUFFER_OFFSET_Y (17)
#endif

#define WIDGET_MP_TIMER_UPDATE_DURATION (600)
#define WIDGET_MP_TIMER_ANIMATION (250)


class VappWidgetMusicPlayerMetaFrame : public VfxControl
{
    VFX_DECLARE_CLASS(VappWidgetMusicPlayerMetaFrame);

public:
    enum
    {
        MODE_WIDGET,
        MODE_LOCK
    };
    VappWidgetMusicPlayerMetaFrame();
    VappWidgetMusicPlayerMetaFrame(VfxU8 mode, VfxS32 width, VfxS32 height);
    ~VappWidgetMusicPlayerMetaFrame();
    virtual void onInit();
    virtual VfxBool onPenInput(VfxPenEvent &event);

    void setCover(const VfxImageSrc &value);
    void setTitleSring(const VfxWString &value);
    void setAlbumSring(const VfxWString &value);
    void setArtistSring(const VfxWString &value);
    void setDurationSring(const VfxWString &value);
    void setTapTextHidden(VfxBool is_hidden);

    void closeFrame(VfxBool is_next);
    void openFrame(VfxBool is_next);

    //VfxSignal0 m_event_launch;
    VfxCallback0 m_launch_callback;

private:
    void closeFrameDone(VfxBaseTimeline *timeline, VfxBool stopped);
    void openFrameDone(VfxBaseTimeline *timeline, VfxBool stopped);

private:
    const VfxU8 m_mode;
    VfxBool m_is_closing;
    VfxBool m_is_opening;
    const VfxS32 m_width;
    const VfxS32 m_height;    

    VfxImageFrame *m_cover_border;
    VfxFrame *m_cover;

    VfxTextFrame *m_title_text;
    VfxTextFrame *m_album_text;
    VfxTextFrame *m_artist_text;
    VfxTextFrame *m_duration_text;
    VfxTextFrame *m_tap_text;
};

/*****************************************************************************
 * Music Player Base Panel
 *****************************************************************************/
class VappWidgetMusicPlayerBase : public VfxControl
{
    VFX_DECLARE_CLASS(VappWidgetMusicPlayerBase);

public:
    VappWidgetMusicPlayerBase() :
        m_mplayerSrv(NULL),
        m_ctrlPlayback(NULL)
        {};
    ~VappWidgetMusicPlayerBase();

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

/*****************************************************************************
 * Music Player Info Panel
 *****************************************************************************/
class VappWidgetMusicPlayerInfoPanel : public VappWidgetMusicPlayerBase
{
    VFX_DECLARE_CLASS(VappWidgetMusicPlayerInfoPanel);

public:
    enum
    {
        MODE_WIDGET,
        MODE_LOCK
    };

// Public Functions
public:
    VappWidgetMusicPlayerInfoPanel();
    VappWidgetMusicPlayerInfoPanel(VfxU8 mode);
    ~VappWidgetMusicPlayerInfoPanel();
    virtual void onInit();

    static mmi_ret onAppOpenClose(mmi_event_struct *evt);
    static mmi_ret onAppShowHide(mmi_event_struct *evt);
    static mmi_ret staticEventHandler(mmi_event_struct *evt);

    // Export to screen which use this panel
    void initUI(); // Create UI component
    void destroyUI(); // Destroy UI component, used when serialize
    void updatePanel(void);
    void setControlHidden(VfxBool is_hidden);
    VfxBool isControlHidden(void);
    void setPanelActive(VfxBool isActive);

    // Music player app open/close event
    VfxSignal2 <
        VappWidgetMusicPlayerInfoPanel*,    // Sender
        VfxBool                             // isOpen
    > m_signalAppOpenClose;

    // Need to close info panel
    VfxSignal1 <
        VappWidgetMusicPlayerInfoPanel*    // Sender
    > m_signalPanelClose;

// Private Functions
private:
    VfxBool onKeyInput(VfxKeyEvent & event);
    void onButtonClicked(VfxObject* obj, VfxId id);
    void onCurrTimeTimerExpir(VfxTimer *timer);
    void onPlaybackStateChange(PlaybackStateEnum state);
    void onPrevNext(VfxBool is_next);
    void onMDICallback(VfxS32 result);
    void onHiddenDone(VfxBaseTimeline *timeline, VfxBool is_stop);
    void onUnHiddenDone(VfxBaseTimeline *timeline, VfxBool is_stop);
    void onAppLaunched(void);
    void changeMetaFrame(VfxBool is_next);
    void updateButton(void);
    void updateDuration(void);
    void updateCurrentTime(void);
    void resetPanel(void);
    void resetPanelString(void);

// Private Variables
private:
    enum
    {
        BTN_PLAY,
        BTN_PREV,
        BTN_NEXT
    };

private:
    const VfxU8 m_mode;
    VfxBool m_is_ctrl_hidden;
    VfxS32 m_width;
    VfxS32 m_height;
    VfxS32 m_height_ctrl;    
    VfxS32 m_height_lock;

    VfxU32 m_duration;

    VfxTextFrame *m_show_control_text;

    VfxImageFrame *m_background;
    VfxImageFrame *m_slider_bg;
    VfxImageFrame *m_slider_bar;    
    VfxSize m_slider_bar_size;

    VcpButton *m_play_btn;
    VcpButton *m_next_btn;
    VcpButton *m_prev_btn;

    VfxBool m_isKeyDown;

    VfxTimer *m_timer_curr_time;

    VfxSizeTimeline *m_tl_panel_open;
    VfxSizeTimeline *m_tl_panel_close;    

    VfxFrame* m_meta_frame_border;
    VappWidgetMusicPlayerMetaFrame* m_meta_frame;
    // Keep previous meta frame for closing
    VfxWeakPtr<VappWidgetMusicPlayerMetaFrame> m_prev_meta_frame;
};

/*****************************************************************************
 * Music Player Widget
 *****************************************************************************/

class VappWidgetMusicPlayer : public VappWidget
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetMusicPlayer);

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetMusicPlayer();

// Override
public:
    virtual VappWidgetId getId() const;
    virtual VfxSize getMaxSize() const;
    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;
    virtual VfxFrame *createIcon(VfxObject *parentObj);
    virtual VfxPoint onGetEditButtonOffset();

// Overide
public:
    virtual void onCreateView();
    virtual void onReleaseView();
    virtual void onSerializeView(VfxArchive *ar);
    virtual void onRestoreView(VfxArchive *ar);

// Variable
private:
    VappWidgetMusicPlayerInfoPanel *m_info_panel;
};

#endif /* defined(__COSMOS_MUSICPLY__) */
#endif /* VAPP_WIDGET_MUSIC_PLAYER_H */

