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
 *  vapp_shell_mediaplayer.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Shell Media Player Panel
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

#ifndef __VAPP_SHELL_MEDIAPLAYER_H__
#define __VAPP_SHELL_MEDIAPLAYER_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VUI_SHELL_MEDIA_PLAYER__
//#include "vfx_uc_include.h"
#include "vrt_datatype.h"
//#include "vcp_include.h"
//#include "vdat_include.h"
#include "vcp_wheel_menu.h"
#include "vcp_image_button.h"
#include "vcp_page_panel.h"
#include "vcp_popup.h"
#include "ShellApp\base\vapp_shell_panel.h"
#include "ShellApp\panel\MediaPlayer\vadp_shell_mediaplayer.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
#if defined(__MMI_AVRCP_SUPPORT__)
#if defined(__MMI_BT_BCHS_SUPPORT__)
#include "BCHSMMIAVRCPGProt.h"
#elif defined(__MMI_BT_SUPPORT__)
//#include "BTMMIScr.h"
//#include "BtcmSrvGprot.h"
#include "BTMMIAVRCPGProt.h"
#endif 
#endif /* __MMI_AVRCP_SUPPORT__ */ 

#ifdef __cplusplus
}
#endif


#include "vcp_wheel_menu.h"
#include "vcp_image_button.h"
#include "vcp_page_panel.h"
#include "vapp_shell_panel.h"
#include "vadp_shell_mediaplayer.h"
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vfx_signal.h"
#include "vfx_primitive_frame.h"
#include "vfx_base_popup.h"
#include "vfx_weak_ptr.h"
#include "vfx_object.h"
#include "vfx_timer.h"
#include "vfx_string.h"
#include "vfx_image_src.h"
#include "vcp_marquee.h"
#include "vfx_text_frame.h"
#include "vfx_class_info.h"
#include "vfx_frame.h"
#include "vcp_segment_button.h"
#include "vcp_waiting_icon.h"
#include "vcp_command_title.h"
#include "vfx_basic_type.h"
#include "vfx_sys_memory.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__MMI_MAINLCD_320X480__) && defined(__MMI_VUI_SHELL_MEDIA_PLAYER_SLIM__)
#define VAPP_SHELL_MEDIAPLAYER_FONT_LARGE             VfxFontDesc(128+18)
#define VAPP_SHELL_MEDIAPLAYER_FONT_MEDIUM             VfxFontDesc(128+14)
#define VAPP_SHELL_MEDIAPLAYER_FONT_SMALL             VfxFontDesc(128+12)
#define VAPP_SHELL_MEDIAPLAYER_FONT_LARGE_CELL             VfxFontDesc(128+14)
#define VAPP_SHELL_MEDIAPLAYER_FONT_MEDIUM_CELL             VfxFontDesc(128+12)
#define VAPP_SHELL_MEDIAPLAYER_FONT_SMALL_CELL             VfxFontDesc(128+12)
#elif defined(__MMI_MAINLCD_320X480__)
#define VAPP_SHELL_MEDIAPLAYER_FONT_LARGE             VfxFontDesc(128+18)
#define VAPP_SHELL_MEDIAPLAYER_FONT_MEDIUM             VfxFontDesc(128+14)
#define VAPP_SHELL_MEDIAPLAYER_FONT_SMALL             VfxFontDesc(128+12)
#define VAPP_SHELL_MEDIAPLAYER_FONT_LARGE_CELL             VfxFontDesc(128+18)
#define VAPP_SHELL_MEDIAPLAYER_FONT_MEDIUM_CELL             VfxFontDesc(128+14)
#define VAPP_SHELL_MEDIAPLAYER_FONT_SMALL_CELL             VfxFontDesc(128+12)
#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_SHELL_MEDIAPLAYER_FONT_LARGE             VfxFontDesc(128+14)
#define VAPP_SHELL_MEDIAPLAYER_FONT_MEDIUM             VfxFontDesc(128+12)
#define VAPP_SHELL_MEDIAPLAYER_FONT_SMALL             VfxFontDesc(128+10)
#define VAPP_SHELL_MEDIAPLAYER_FONT_LARGE_CELL             VfxFontDesc(128+13)
#define VAPP_SHELL_MEDIAPLAYER_FONT_MEDIUM_CELL             VfxFontDesc(128+11)
#define VAPP_SHELL_MEDIAPLAYER_FONT_SMALL_CELL             VfxFontDesc(128+9)
#elif defined(__MMI_MAINLCD_240X320__) 
#define VAPP_SHELL_MEDIAPLAYER_FONT_LARGE             VfxFontDesc(128+14)
#define VAPP_SHELL_MEDIAPLAYER_FONT_MEDIUM             VfxFontDesc(128+12)
#define VAPP_SHELL_MEDIAPLAYER_FONT_SMALL             VfxFontDesc(128+10)
#define VAPP_SHELL_MEDIAPLAYER_FONT_LARGE_CELL             VfxFontDesc(128+13)
#define VAPP_SHELL_MEDIAPLAYER_FONT_MEDIUM_CELL             VfxFontDesc(128+11)
#define VAPP_SHELL_MEDIAPLAYER_FONT_SMALL_CELL             VfxFontDesc(128+9)
#endif


enum VappShellMediaplayerStatusChangeEnum
{
    VAPP_SHELL_MEDIPALAYER_STATU_PLAY_TO_IDLE,
    VAPP_SHELL_MEDIPALAYER_STATU_IDLE_TO_PLAY
};

/***************************************************************************** 
 * Pre-declaration
 *****************************************************************************/
class VappShellMediaplayer;
class VappShellMediaplayerMenu;
class VappShellMediaplayerMainScreen;
class VappShellMediaplayerProgressBar;

/***************************************************************************** 
 * Class VappShellMediaplayerProgressBars
 *****************************************************************************/
class VappShellMediaplayerProgressBar : public VfxControl
{

// Constructor / Destructor    
public:
    // Default constructor
    VappShellMediaplayerProgressBar();

    // Destructor
    virtual ~VappShellMediaplayerProgressBar();

// Method 
public:

    enum
    {
        BAR_OFFSET_X = 11,
        BAR_OFFSET_Y = 109
    };


    // Set progress ratio
    void setRatio(
        VfxS32 ratio        // [IN] ratio
    );

    void setMinWidth(VfxS32 minWidth);

    // The function can get the ratio of this progress bar
    // RETURNS: the current ratio    
    VfxS32 getRatio(void) const;

    // Set foreground and background image resource id
    void setImage(VfxS32 bgImage,VfxS32 fgImage);

    // Set bar width
    void setBarWidth(VfxU32 width);

    void setHead(VfxResId resId);
// Override
private:
    // On init
    virtual void onInit();

    // On Deinit
    virtual void onDeinit();

    // On PenInput
    virtual VfxBool onPenInput(VfxPenEvent &event);

public:

    // Pen down signal
    VfxSignal1 <VfxS32> m_eventPenDown;

    
// Variable
private:
    // Progress bar ratio
    VfxS32 m_ratio;

    // Foreground image frame
    VfxImageFrame *m_imageFg;

    // Background image frame
    VfxImageFrame *m_imageBg;

    VfxImageFrame *m_imageHd;
    VfxU32 m_imageHdOffsetX;
    VfxU32 m_imageHdOffsetY;
    VfxU32 m_barWidth;
    VfxU32 m_barHeight;
    VfxU32 m_progressMinWidth;

    VfxU32 m_progressHeight;
    VfxU32 m_progressWidth;
    VfxU32 m_minWidth;

};


/***************************************************************************** 
 * Class VappShellMediaplayerVolCtrlPopup
 *****************************************************************************/
class VappShellMediaplayerVolCtrlPopup : public VfxBasePopup
{

    typedef VappShellMediaplayerVolCtrlPopup    Self;
    typedef VfxBasePopup                        Super;

public:
#if defined(__MMI_MAINLCD_320X480__)
    enum
    {
        VOLUME_POPUP_PANEL_OFFSET_X = 36,
        VOLUME_POPUP_PANEL_OFFSET_Y = 192,
        VOLUME_POPUP_PANEL_WIDTH = 248 ,
        VOLUME_POPUP_PANEL_HEIGHT = 116,
        VOLUME_ICON_OFFSET_X = 25,
        VOLUME_ICON_OFFSET_Y = 38,
        VOLUME_ICON_WIDTH = 41,
        VOLUME_ICON_HEIGHT = 41,
        VOLUME_BAR_OFFSET_X = 69,
        VOLUME_BAR_OFFSET_Y = 47,
        VOLUME_BAR_WIDTH = 166,
        VOLUME_BAR_MINWDITH = 12
    };
#elif defined(__MMI_MAINLCD_240X400__)
    enum
    {
        VOLUME_POPUP_PANEL_OFFSET_X = 21,
        VOLUME_POPUP_PANEL_OFFSET_Y = 153,
        VOLUME_POPUP_PANEL_WIDTH = 198 ,
        VOLUME_POPUP_PANEL_HEIGHT = 96,
        VOLUME_ICON_OFFSET_X = 15,
        VOLUME_ICON_OFFSET_Y = 36,
        VOLUME_ICON_WIDTH = 31,
        VOLUME_ICON_HEIGHT = 30,
        VOLUME_BAR_OFFSET_X = 51,
        VOLUME_BAR_OFFSET_Y = 42,
        VOLUME_BAR_WIDTH = 137,       
        VOLUME_BAR_MINWDITH = 12
    };
#elif defined(__MMI_MAINLCD_240X320__)
    enum
    {
        VOLUME_POPUP_PANEL_OFFSET_X = 22,
        VOLUME_POPUP_PANEL_OFFSET_Y = 113,
        VOLUME_POPUP_PANEL_WIDTH = 198 ,
        VOLUME_POPUP_PANEL_HEIGHT = 96,
        VOLUME_ICON_OFFSET_X = 13,
        VOLUME_ICON_OFFSET_Y = 33,
        VOLUME_ICON_WIDTH = 31,
        VOLUME_ICON_HEIGHT = 30,
        VOLUME_BAR_OFFSET_X = 51,
        VOLUME_BAR_OFFSET_Y = 37,
        VOLUME_BAR_WIDTH = 137,       
        VOLUME_BAR_MINWDITH = 12       
    };
#endif


// Constructor / Destructor
public:
    VappShellMediaplayerVolCtrlPopup ();
    
protected:
    // On init
    virtual void onInit();

    // On deinit
    virtual void onDeinit();
    
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

    virtual void onPenInputOnOutside(VfxPenEvent &event);

// Method
public:
    void increaseVolume(void);
    void decreaseVolume(void);
    void changeVolume(void);
    void setPlayer(VappShellMediaplayer* player);
private:
    void onButtonClick(VfxObject *sender, VfxId Id);
    void setMute(void);
    void setUnmute(void);
    void onRatioChange(VfxS32 ratio);
    void onTimerExpired(VfxTimer *source);
private:
    VfxImageFrame *m_bgImage;
    VappShellMediaplayer *m_player;
    VappShellMediaplayerProgressBar *m_progress;
    VcpImageButton                  *m_volCtrlButton;
    VfxU8                           m_volLevel;
    VfxBool                         m_isMute;
    VfxS32                          m_ratio;
    VfxTimer                        *m_timer;
};
 
/***************************************************************************** 
 * Class VappShellMediaplayerCell
 *****************************************************************************/
class VappShellMediaplayerCell : public VfxControl
{
    typedef VappShellMediaplayerCell            Self;
    typedef VfxControl                          Super;

public:
    enum
    {
        DATA_TYPE_MEMORY     = 0,       
        DATA_TYPE_DB,
        DATA_TYPE_FILE,
        DATE_TYPE_DEFAULT
    };
#if defined(__MMI_MAINLCD_320X480__) && defined(__MMI_VUI_SHELL_MEDIA_PLAYER_SLIM__)
    enum
    {
        CELL_ITEM_WIDTH = 224,
        CELL_ITEM_HEIGHT = 111,
        CELL_ALBUM_OFFSET_X = 14,
        CELL_ALBUM_OFFSET_Y = 13,
        CELL_ALBUM_WIDTH = 69,
        CELL_ALBUM_HEIGHT = 69,
        CELL_PROGRESS_BAR_OFFSET_X = 14,
        CELL_PROGRESS_BAR_OFFSET_Y = 88,
        CELL_PROGRESS_BAR_WIDTH = 200,
        CELL_PLAYING_ICON_OFFSET_X = 197,
        CELL_PLAYING_ICON_OFFSET_Y = 16,
        CELL_SONG_NAME_OFFSET_X = 93,
        CELL_SONG_NAME_OFFSET_Y = 35,
        CELL_SONG_NAME_WIDTH = 115,
        CELL_SONG_NAME_HEIGHT =18,
        CELL_ARTIST_NAME_OFFSET_X = 93,
        CELL_ARTIST_NAME_OFFSET_Y = 55,
        CELL_ARTIST_NAME_WIDTH = 115,
        CELL_ARTIST_NAME_HEIGHT = 14,
        CELL_DURATION_OFFSET_X = 90,
        CELL_DURATION_OFFSET_Y = 72,
        CELL_DURATION_WIDTH = 115,
        CELL_DURATION_HEIGHT =14,       
        CELL_PROGRESS_BAR_MINWDITH = 7
    };
#elif defined(__MMI_MAINLCD_320X480__)
    enum
    {
        CELL_ITEM_WIDTH = 281,
        CELL_ITEM_HEIGHT = 131,
        CELL_ALBUM_OFFSET_X = 11,
        CELL_ALBUM_OFFSET_Y = 11,
        CELL_ALBUM_WIDTH = 90,
        CELL_ALBUM_HEIGHT = 90,
        CELL_PROGRESS_BAR_OFFSET_X = 9,
        CELL_PROGRESS_BAR_OFFSET_Y = 109,
        CELL_PROGRESS_BAR_WIDTH = 264,
        CELL_PLAYING_ICON_OFFSET_X = 248,
        CELL_PLAYING_ICON_OFFSET_Y = 11,
        CELL_SONG_NAME_OFFSET_X = 116,
        CELL_SONG_NAME_OFFSET_Y = 38,
        CELL_SONG_NAME_WIDTH = 150,
        CELL_SONG_NAME_HEIGHT =18,
        CELL_ARTIST_NAME_OFFSET_X = 116,
        CELL_ARTIST_NAME_OFFSET_Y = 60,
        CELL_ARTIST_NAME_WIDTH = 150,
        CELL_ARTIST_NAME_HEIGHT = 14,
        CELL_DURATION_OFFSET_X = 116,
        CELL_DURATION_OFFSET_Y = 80,
        CELL_DURATION_WIDTH = 150,
        CELL_DURATION_HEIGHT =14,       
        CELL_PROGRESS_BAR_MINWDITH = 7
    };
#elif defined(__MMI_MAINLCD_240X400__)
    enum
    {
        CELL_ITEM_WIDTH = 193,
        CELL_ITEM_HEIGHT = 96,
        CELL_ALBUM_OFFSET_X = 13,
        CELL_ALBUM_OFFSET_Y = 13,
        CELL_ALBUM_WIDTH = 58,
        CELL_ALBUM_HEIGHT = 58,
        CELL_PROGRESS_BAR_OFFSET_X = 10,
        CELL_PROGRESS_BAR_OFFSET_Y = 75,
        CELL_PROGRESS_BAR_WIDTH = 169,
        CELL_PLAYING_ICON_OFFSET_X = 164,
        CELL_PLAYING_ICON_OFFSET_Y = 12,
        CELL_SONG_NAME_OFFSET_X = 78,
        CELL_SONG_NAME_OFFSET_Y = 32,
        CELL_SONG_NAME_WIDTH = 100,
        CELL_SONG_NAME_HEIGHT = 14,
        CELL_ARTIST_NAME_OFFSET_X = 79,
        CELL_ARTIST_NAME_OFFSET_Y = 49,
        CELL_ARTIST_NAME_WIDTH = 100,
        CELL_ARTIST_NAME_HEIGHT = 12,
        CELL_DURATION_OFFSET_X = 79,
        CELL_DURATION_OFFSET_Y = 62,
        CELL_DURATION_WIDTH = 100,
        CELL_DURATION_HEIGHT = 12,       
        CELL_PROGRESS_BAR_MINWDITH = 6
    };
#elif defined(__MMI_MAINLCD_240X320__)
    enum
    {
        CELL_ITEM_WIDTH = 193,
        CELL_ITEM_HEIGHT = 96,
        CELL_ALBUM_OFFSET_X = 13,
        CELL_ALBUM_OFFSET_Y = 13,
        CELL_ALBUM_WIDTH = 58,
        CELL_ALBUM_HEIGHT = 58,
        CELL_PROGRESS_BAR_OFFSET_X = 10,
        CELL_PROGRESS_BAR_OFFSET_Y = 75,
        CELL_PROGRESS_BAR_WIDTH = 169,
        CELL_PLAYING_ICON_OFFSET_X = 164,
        CELL_PLAYING_ICON_OFFSET_Y = 12,
        CELL_SONG_NAME_OFFSET_X = 78,
        CELL_SONG_NAME_OFFSET_Y = 32,
        CELL_SONG_NAME_WIDTH = 100,
        CELL_SONG_NAME_HEIGHT = 14,
        CELL_ARTIST_NAME_OFFSET_X = 79,
        CELL_ARTIST_NAME_OFFSET_Y = 49,
        CELL_ARTIST_NAME_WIDTH = 100,
        CELL_ARTIST_NAME_HEIGHT = 12,
        CELL_DURATION_OFFSET_X = 79,
        CELL_DURATION_OFFSET_Y = 62,
        CELL_DURATION_WIDTH = 100,
        CELL_DURATION_HEIGHT = 12,       
        CELL_PROGRESS_BAR_MINWDITH = 6
    };
#endif
    enum
    {
        STATE_IDLE     = 0,       
        STATE_IMAGE,
        STATE_DECODING,
    };    

// Constructor / Destructor
public:
    // Default constructor
    VappShellMediaplayerCell(VfxS32 index);

    // Destructor
    virtual ~VappShellMediaplayerCell();

// Override
public:
    // On init
    virtual void onInit();

    // On deinit
    virtual void onDeinit();
    
// Method
public:
    void onHightLight();

    void onDeHightLight();

    void setCurrPlaytimeMsec(VfxU64 time);

    void setDurationMsec(VfxU64 duration);
    VfxU64 getDurationMsec(void);
    VfxS32 getState();

    void updateTitle(VfxWString title);
    void updateArtist(VfxWString artist);
    void hideTime();
    void updateTime();
    void updateProgressBar();
    void useDefaultImage();

    void setImageBuffer(VfxU8 * buf_ptr, VfxS32 width, VfxS32 height);
    VfxU8 *getImageBuffer();
    void setPlaying(VfxBool isPlaying);

    VfxImageSrcTypeEnum getImageType();
    VfxS32 state();
    VfxS32 index();
//
private:
    void getTimeString(VfxU64 msec, VfxWChar *timeStr,VfxU32 maxLength) const;

    
// Variable

public:
//    VfxSignal1 <VfxS32> m_eventOnTap;
    
private:
    VfxS32          m_index;
    VfxImageFrame   *m_bgImage;
    VfxImageFrame   *m_playingIcon;
    VfxImageFrame   *m_albumPhoto;
    VcpMarquee      *m_songName;
    VfxTextFrame    *m_artistName;
    VfxBool         m_isHighlight;
    
    VappShellMediaplayerProgressBar *m_progress;

    VfxTextFrame *m_durationStr;
    //VfxTextFrame *m_currtimeStr;

    VfxWString m_durationToDisplay;
    VfxU64 m_currTimeMsec;
    VfxU64 m_durationMsec;
    VfxBool is_time_dirty;

    VfxS32 m_maxMoveOffset;    // The max offset when drag. This is used for detecting tap or scroll.

    VfxS32 m_state;
    VfxS32 m_imageWidth;
    VfxS32 m_imageHeight;
    VfxU8 * m_imageBuf;
};

    enum ShellMediaplayerResEnum
    {
        VAPP_SHELL_MEDIAPLAYER_RES_OK= 0,
        VAPP_SHELL_MEDIAPLAYER_RES_FAIL,

        VAPP_SHELL_MP_RES_MEDIACACHE_OK = 0,
        VAPP_SHELL_MP_RES_MEDIACACHE_DECODING,
        VAPP_SHELL_MP_RES_MEDIACACHE_NOT_SUPPORT,
        VAPP_SHELL_MP_RES_MEDIACACHE_BUFFER_NOT_FOUND
    };

/***************************************************************************** 
 * Class VappShellMediaplayerMainScreen
 *****************************************************************************/
class VappShellMediaplayerMainScreen : public VfxControl
{
    VFX_DECLARE_CLASS(VappShellMediaplayerMainScreen);

    typedef VappShellMediaplayerMainScreen  Self;
    typedef VfxControl                        Super;
public:
#if defined(__MMI_MAINLCD_320X480__)
    enum
    {
        ALBUM_ICON_OFFSET_X = 17,
        ALBUM_ICON_OFFSET_Y = 330,
        ARTIST_ICON_OFFSET_X = 17,
        ARTIST_ICON_OFFSET_Y = 306,
        REPEAT_ICON_OFFSET_X = 17,
        REPEAT_ICON_OFFSET_Y = 39,
        SHUFFLE_ICON_OFFSET_X = 17,
        SHUFFLE_ICON_OFFSET_Y = 70,
        ICON_WIDTH = 26,
        ICON_HEIGHT = 26,
        VOLUME_ICON_OFFSET_X = 277,
        VOLUME_ICON_OFFSET_Y = 39,
        ALBUM_COVER_OFFSET_X = 61,
        ALBUM_COVER_OFFSET_Y = 41,
        ALBUM_COVER_WIDTH = 202,
        ALBUM_COVER_HEIGHT = 186,
        ALBUM_PHOTO_OFFSET_X = 80,
        ALBUM_PHOTO_OFFSET_Y = 46,
        ALBUM_PHOTO_WIDTH = 175,
        ALBUM_PHOTO_HEIGHT = 176,
        ALBUM_STR_OFFSET_X = 86,
        ALBUM_STR_OFFSET_Y = 196,
        ALBUM_STR_WIDTH = 160,
        ALBUM_STR_HEIGHT = 14,
        CURRENT_PLAY_TIME_OFFSET_X = 10, // 12px
        CURRENT_PLAY_TIME_OFFSET_Y = 282,
        CURRENT_PLAY_TIME_WIDTH = 40,
        CURRENT_PLAY_TIME_HEIGHT = 12,
        TOTAL_DURATION_OFFSET_X = 282,
        TOTAL_DURATION_OFFSET_Y = 282,
        TOTAL_DURATION_WIDTH = 40,
        TOTAL_DURATION_HEIGHT = 12,
        ARTIST_NAME_OFFSET_X = 50, // 14px
        ARTIST_NAME_OFFSET_Y = 311,
        ARTIST_NAME_WIDTH = 240,
        ARTIST_NAME_HEIGHT = 14,
        ALBUM_NAME_OFFSET_X = 50,  // 14px
        ALBUM_NAME_OFFSET_Y = 335,
        ALBUM_NAME_WIDTH = 240,
        ALBUM_NAME_HEIGHT = 14,
        SONG_NAME_OFFSET_X = 36, // 18px
        SONG_NAME_OFFSET_Y = 248,
        SONG_NAME_WIDTH = 248,
        SONG_NAME_HEIGHT = 18,
        PROGRESS_BAR_OFFSET_X = 48,
        PROGRESS_BAR_OFFSET_Y = 280,
        PROGRESS_BAR_WIDTH = 230,       
        PROGRESS_BAR_MINWDITH = 7
    };
#elif defined(__MMI_MAINLCD_240X400__)
    enum
    {
        ALBUM_ICON_OFFSET_X = 13,
        ALBUM_ICON_OFFSET_Y = 276,
        ARTIST_ICON_OFFSET_X = 13,
        ARTIST_ICON_OFFSET_Y = 260,
        REPEAT_ICON_OFFSET_X = 9,
        REPEAT_ICON_OFFSET_Y = 41,
        SHUFFLE_ICON_OFFSET_X = 9,
        SHUFFLE_ICON_OFFSET_Y = 66,
        VOLUME_ICON_OFFSET_X = 212,
        VOLUME_ICON_OFFSET_Y = 41,
        ICON_WIDTH = 22,
        ICON_HEIGHT = 19,
        ALBUM_COVER_OFFSET_X = 37,
        ALBUM_COVER_OFFSET_Y = 40,
        ALBUM_COVER_WIDTH = 171,
        ALBUM_COVER_HEIGHT = 160,
        ALBUM_PHOTO_OFFSET_X = 54,
        ALBUM_PHOTO_OFFSET_Y = 45,
        ALBUM_PHOTO_WIDTH = 147,
        ALBUM_PHOTO_HEIGHT = 148,
        ALBUM_STR_OFFSET_X = 57,// 14px
        ALBUM_STR_OFFSET_Y = 174,
        ALBUM_STR_WIDTH = 140,
        ALBUM_STR_HEIGHT = 14,
        CURRENT_PLAY_TIME_OFFSET_X = 9, // 10px
        CURRENT_PLAY_TIME_OFFSET_Y = 238,
        CURRENT_PLAY_TIME_WIDTH = 30,
        CURRENT_PLAY_TIME_HEIGHT = 10,
        TOTAL_DURATION_OFFSET_X = 206,
        TOTAL_DURATION_OFFSET_Y = 238,
        TOTAL_DURATION_WIDTH = 30,
        TOTAL_DURATION_HEIGHT = 10,
        ARTIST_NAME_OFFSET_X = 30, // 12px
        ARTIST_NAME_OFFSET_Y = 260,
        ARTIST_NAME_WIDTH = 190,
        ARTIST_NAME_HEIGHT = 12,
        ALBUM_NAME_OFFSET_X = 30,  // 12px
        ALBUM_NAME_OFFSET_Y = 276,
        ALBUM_NAME_WIDTH = 190,
        ALBUM_NAME_HEIGHT = 12,
        SONG_NAME_OFFSET_X = 21, // 14px
        SONG_NAME_OFFSET_Y = 214,
        SONG_NAME_WIDTH = 198,
        SONG_NAME_HEIGHT = 14,
        PROGRESS_BAR_OFFSET_X = 39,
        PROGRESS_BAR_OFFSET_Y = 237,
        PROGRESS_BAR_WIDTH = 166,       
        PROGRESS_BAR_MINWDITH = 6        
    };
#elif defined(__MMI_MAINLCD_240X320__)
    enum
    {
        ALBUM_ICON_OFFSET_X = 110,
        ALBUM_ICON_OFFSET_Y = 202,
        ARTIST_ICON_OFFSET_X = 8,
        ARTIST_ICON_OFFSET_Y = 202,
        REPEAT_ICON_OFFSET_X = 15,
        REPEAT_ICON_OFFSET_Y = 27,
        SHUFFLE_ICON_OFFSET_X = 15,
        SHUFFLE_ICON_OFFSET_Y = 53,
        VOLUME_ICON_OFFSET_X = 206,
        VOLUME_ICON_OFFSET_Y = 27,
        ICON_WIDTH = 22, 
        ICON_HEIGHT = 19, 
        ALBUM_COVER_OFFSET_X = 54,
        ALBUM_COVER_OFFSET_Y = 29,
        ALBUM_COVER_WIDTH = 134,
        ALBUM_COVER_HEIGHT = 125,
        ALBUM_PHOTO_OFFSET_X = 67,
        ALBUM_PHOTO_OFFSET_Y = 33,
        ALBUM_PHOTO_WIDTH = 113,
        ALBUM_PHOTO_HEIGHT = 114,
        ALBUM_STR_OFFSET_X = 70,// 14px
        ALBUM_STR_OFFSET_Y = 130,
        ALBUM_STR_WIDTH = 106,
        ALBUM_STR_HEIGHT = 14,
        CURRENT_PLAY_TIME_OFFSET_X = 8, // 10px
        CURRENT_PLAY_TIME_OFFSET_Y = 185,
        CURRENT_PLAY_TIME_WIDTH = 27,
        CURRENT_PLAY_TIME_HEIGHT = 10,
        TOTAL_DURATION_OFFSET_X = 207,
        TOTAL_DURATION_OFFSET_Y = 185,
        TOTAL_DURATION_WIDTH = 27,
        TOTAL_DURATION_HEIGHT = 10,
        ARTIST_NAME_OFFSET_X = 26, // 12px
        ARTIST_NAME_OFFSET_Y = 202,
        ARTIST_NAME_WIDTH = 72,
        ARTIST_NAME_HEIGHT = 12,
        ALBUM_NAME_OFFSET_X = 125,  // 12px
        ALBUM_NAME_OFFSET_Y = 202,
        ALBUM_NAME_WIDTH = 90,
        ALBUM_NAME_HEIGHT = 12,
        SONG_NAME_OFFSET_X = 21, // 14px
        SONG_NAME_OFFSET_Y = 166,
        SONG_NAME_WIDTH = 198,
        SONG_NAME_HEIGHT = 14,
        PROGRESS_BAR_OFFSET_X = 39,
        PROGRESS_BAR_OFFSET_Y = 183,
        PROGRESS_BAR_WIDTH = 164,       
        PROGRESS_BAR_MINWDITH = 6        
    };
#endif
public:
    enum
    {
        BUTTON_BACKWARD = 0,
        BUTTON_PLAY,
        BUTTON_FORWARD,
        // please don't modify above this line 
        BUTTON_SHUFFLE,
        BUTTON_REPEAT,
        BUTTON_ALBUM,
        BUTTON_VOLUME_CTRL
    };

    enum
    {
        VAPP_SHELL_MP_TOOLBAR_BACKWARD = BUTTON_BACKWARD,
        VAPP_SHELL_MP_TOOLBAR_PLAYPAUSE = BUTTON_PLAY,
        VAPP_SHELL_MP_TOOLBAR_FORWARD = BUTTON_FORWARD,      
        VAPP_SHELL_MP_TOOLBAR_TOTAL_ENUM = 3
    };

    // Constructor / Destructor
public:
    VappShellMediaplayerMainScreen(void);
    virtual ~VappShellMediaplayerMainScreen(void);

    // Overwrite 
protected:
    virtual void onInit();
    virtual void onDeinit();
    // Method
public:

    void setCurrPlaytimeMsec(VfxU64 time);
    void setPlayer(VappShellMediaplayer *player);
    void setDurationMsec(VfxU64 duration);   
    void updateMainScreenInfo();
    void updateMainScreenSetting();
    void onStatusChanged(VappShellMediaplayerStatusChangeEnum statusEnum);
    void onMediaChanged(void* resultP);
    void onPlayEnd(void* resultP);
    void onListEnd(void* resultP);
    void onFinishSwitchView(VfxFrame * target,VfxBool isCompleted);
    void prepare(void);
    void unprepare(void);
    void disableButton();
    void enableButton();
    void onExitView();
    void setNeedToSwitch(VfxBool needToSwitch);
    void showVolCtrlPopup();
    void delayPlay(VfxTimer *source);
    void onButtonClick(VfxObject *sender, VfxId Id);
    void hideWaitingIcon();
    void displayWaitingIcon();    
    void updateProgressBar();
    //VappShellMediaplayerVolCtrlPopup * getVolCtrlPopup() 
    VfxWeakPtr <VappShellMediaplayerVolCtrlPopup> getVolCtrlPopup()
	{
        return this->m_volCtrlPopup;
    }

private:
    void setAlbumPhoto(VfxImageBuffer &imageBuf);
    void onTimerExpired(VfxTimer *source);
    void getTimeString(VfxU64 time, VfxWChar *timeStr,VfxU32 maxLength) const;


    static VfxResId toolbarConfig[VAPP_SHELL_MP_TOOLBAR_TOTAL_ENUM][4];

    // Variable
public:
    VfxSignal0 m_signalSwitchButtonClicked;
    
private:
    VcpImageButton  *m_repeatButton;
    VcpImageButton  *m_shuffleButton;
    VcpImageButton  *m_albumCoverButton;
    VcpPagePanel    *m_albumPagePanel;
    VfxImageFrame   *m_albumCover;
    VfxImageFrame   *m_albumPhoto;
    VfxImageFrame   *m_albumPhoto2;
    VfxImageFrame   *m_activePhotoFrame;
    VfxImageFrame   *m_idlePhotoFrame;
    VfxTextFrame    *m_noPlaylistStr;
    VfxBool         m_needToSwitch;
    VcpImageButton *m_volumeCtrlButton;
    VcpSegmentButton    *m_toolbar;

    VfxImageFrame *m_albumIcon;
    VfxImageFrame *m_artistIcon;
    VcpMarquee   *m_songStr;
    VfxTextFrame *m_albumStr;
    VfxTextFrame *m_artistStr;
    VfxTextFrame *m_currPlaytimeStr;
    VfxTextFrame *m_totalPlaytimeStr;
    VappShellMediaplayerProgressBar *m_progress;
    VfxWeakPtr <VappShellMediaplayerVolCtrlPopup>  m_volCtrlPopup;
    //VappShellMediaplayerVolCtrlPopup *m_volCtrlPopup;
    VcpWaitingIcon      *m_waitingIcon;
    VfxTimer        *m_timer;

    VappShellMediaplayer *m_player;

    VfxU64 m_currTimeMsec;
    VfxU64 m_durationMsec;
};


#define CELL_ITEM_SCALE_X (0.125)
#define CELL_ITEM_SCALE_Y (0.25)

/***************************************************************************** 
 * Class VappShellMediaplayerMenuFrame
 *****************************************************************************/
class VappShellMediaplayerMenuFrame : public VfxFrame
{

    VFX_DECLARE_CLASS(VappShellMediaplayerMenuFrame);

    typedef VappShellMediaplayerMenuFrame   Self;
    typedef VfxFrame                        Super;
#if defined(__MMI_MAINLCD_320X480__)
    enum
    {
        STRING_OFFSET_X = 0,
        STRING_OFFSET_Y = 235,
        STRING_WIDTH = 320,
        STRING_HEIGHT = 20
    };
#elif defined(__MMI_MAINLCD_240X400__)
    enum
    {
        STRING_OFFSET_X = 0,
        STRING_OFFSET_Y = 216,
        STRING_WIDTH = 240,
        STRING_HEIGHT = 16
    };
#elif defined(__MMI_MAINLCD_240X320__)
    enum
    {
        STRING_OFFSET_X = 0,
        STRING_OFFSET_Y = 174,
        STRING_WIDTH = 240,
        STRING_HEIGHT = 16
    };    
#endif    

    // Constructor / Destructor
public:
    VappShellMediaplayerMenuFrame();


// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    void setPlayer(VappShellMediaplayer *player);
    void onBackButtonClick(VfxObject* sender, VfxId id);
    void showString(VfxS32 active_song_count);
public:
    VfxSignal0 m_signalSwitchButtonClicked;
    VappShellMediaplayerMenu *m_menu;
    VfxS32 m_backupIndex;        
private:
    VcpCommandTitle *m_cmdTitle;
    VappShellMediaplayer *m_player;
    VfxTextFrame *m_tapStr;

};

/***************************************************************************** 
 * Class VappShellMediaplayerMenu
 *****************************************************************************/
class VappShellMediaplayerMenu : public VcpWheelMenu
{
    VFX_DECLARE_CLASS(VappShellMediaplayerMenu);

    typedef VappShellMediaplayerMenu  Self;
    typedef VcpWheelMenu              Super;

public:
#if defined(__MMI_MAINLCD_320X480__)
    enum
    {
        CELL_ITEM_OFFSET_X = 9,
        CELL_ITEM_OFFSET_Y = 18,
        CELL_ITEM_VIEW_COUNT = 5,
        CELL_ITEM_POS_Y      = 193,
        CELL_ITEM_AHEAD_COUNT = 2,
        CELL_ITEM_BEHIND_COUNT = 2,
        CELL_ITEM_X_AXIS_RADIUS = 35,
        CELL_ITEM_Y_AXIS_RADIUS = 175,
        CELL_ITEM_ROTATE_ANGLE = 72,
        CELL_ITEM_ROTATE_ANGLE_Y = 25,
        CELL_ITEM_X_SHIFT = 10,
        CELL_ITEM_PHOTO_MAX_WIDTH = 175,
        CELL_ITEM_PHOTO_MAX_HEIGHT = 175,
        CELL_ITEM_PHOTO_WIDTH = 90,
        CELL_ITEM_PHOTO_HEIGHT = 90
    };
#elif defined(__MMI_MAINLCD_240X400__)
    enum
    {
        CELL_ITEM_OFFSET_X = 9, /* not used */
        CELL_ITEM_OFFSET_Y = 18,
        CELL_ITEM_VIEW_COUNT = 5,
        CELL_ITEM_POS_Y      = 167, // TODO: CHECK ON MODIS
        CELL_ITEM_AHEAD_COUNT = 2,
        CELL_ITEM_BEHIND_COUNT = 2,
        CELL_ITEM_X_AXIS_RADIUS = 20,
        CELL_ITEM_Y_AXIS_RADIUS = 132,
        CELL_ITEM_ROTATE_ANGLE = 113,
        CELL_ITEM_ROTATE_ANGLE_Y = 30,
        CELL_ITEM_X_SHIFT = 7,
        CELL_ITEM_PHOTO_MAX_WIDTH = 148,
        CELL_ITEM_PHOTO_MAX_HEIGHT = 148,
        CELL_ITEM_PHOTO_WIDTH = 58,
        CELL_ITEM_PHOTO_HEIGHT = 58
    };
#elif defined(__MMI_MAINLCD_240X320__)
    enum
    {
        CELL_ITEM_OFFSET_X = 9, /* not used */
        CELL_ITEM_OFFSET_Y = 18,
        CELL_ITEM_VIEW_COUNT = 5,
        CELL_ITEM_POS_Y      = 155, // TODO: CHECK ON MODIS
        CELL_ITEM_AHEAD_COUNT = 1,
        CELL_ITEM_BEHIND_COUNT = 2,
        CELL_ITEM_X_AXIS_RADIUS = 20,
        CELL_ITEM_Y_AXIS_RADIUS = 132,
        CELL_ITEM_ROTATE_ANGLE = 113,
        CELL_ITEM_ROTATE_ANGLE_Y = 30,
        CELL_ITEM_X_SHIFT = 7,
        CELL_ITEM_PHOTO_MAX_WIDTH = 148,
        CELL_ITEM_PHOTO_MAX_HEIGHT = 148,
        CELL_ITEM_PHOTO_WIDTH = 58,
        CELL_ITEM_PHOTO_HEIGHT = 58
    };
#endif    
    struct WheelMenuUserData
    {
        VfxS32 index;
        VfxS32 subcell;
        VfxU32 tick;
    };

public:
    VappShellMediaplayerMenu();
    
// Override
public:
    virtual void onInit();
    virtual void onDeinit();

// Override    
protected:
    //virtual void onUpdate();
    //virtual VfxBool onKeyInput(VfxKeyEvent &event);
    //virtual VfxBool onPenInput(VfxPenEvent &event);

// Method
public :
    void setDragging(VfxBool dragging);

    void setCount(VfxS32 count);

    static vrt_render_dirty_type_enum FrameEffectCB(   VfxS32                              cell,           // [IN] the cell index
                                     VfxS32                              subCell,        // [IN] the sub cell index
                                     VfxFloat                            cellRelPos,     // [IN] the cell position
                                     vrt_frame_visual_property_struct    *target_frame,  // [IN] the cell frame
                                     VfxFloat                            fPos,           // [IN] animating index value
                                     VfxS32                              focus,          // the focus value of the menu
                                     VfxRect                             viewBounds,     // the menu bounds
                                     void                                *userData,      // user data
                                     VfxU32                              userDataSize,    // user data size
                                     VcpWheelMenuState                   state,          // [IN] the state of Menu
                                     VfxFloat                            level           // [IN] the level of state
    );
    void setPlayer(VappShellMediaplayer *player);

// Overridable
protected:  

    // Return the sub cell count of a cell.
    // virtual VfxS32 getSubCellCount();

    // Return the count of menu items.
    // Derived class should override this function.
    virtual VfxS32 getCount();

    // Return the visible menu item count which behind the focus item.
    // Derived class should override this function.
    virtual VfxS32 getBehindCount()
    {
        return m_behindCount;
    }


    // Return the visible menu item count which ahead the focus item.
    // Derived class should override this function.
    virtual VfxS32 getAheadCount()
    {
        return m_aheadCount;
    }

    // Return the frame effect callback.
    // Derived class should override this function.
    virtual VcpWheelMenuFrameEffectCBFuncPtr getFrameEffectCB();

    // Create a cell object.
    // Inheritor should override this function.
    // RETURNS: a sub cell object 
    virtual VfxFrame* createCell(
        VfxS32 cell,             // [IN] The cell index
        VfxS32 subCell           // [IN] The sub cell index
    );
    
    // Notify to update a cell's position.
    // Inheritor should override this function.
    virtual void onUpdateCell(
        VfxS32      cell,        // [IN] The cell index
        VfxS32      subCell,     // [IN] The sub cell index
        VfxFrame*   frame        // [IN] The cell object
    );


    // A notify that menu is going to close a cell
    virtual void onCloseCell(
        VfxS32 cell,             // [IN] The cell index
        VfxS32 subCell,          // [IN] The sub cell index
        VfxFrame* frame          // [IN] The sub cell frame which will be closed
    );

    // A notify about Wheel menu is starting updating cell.
    virtual void onBeforeUpdateCell();

    // A notify about Wheel menu has completed updating cell.
    virtual void onAfterUpdateCell();

    // Notify when the focus item is change
    virtual void onFocusIndexChange(
        VfxS32 focusItem,               // [IN] The focus item index now
        VfxS32 preFocusItem             // [IN] The previous focus item index
    );
    
    // Notify when the user start drag the menu
    virtual void onDragStart();

    // Notify when the user stop drag the menu
    virtual void onDragEnd(
        VfxS32 xspeed,        // [IN] how fast to release the pen in x direction. Unit is point / 1sec.
        VfxS32 yspeed         // [IN] how fast to release the pen in y direction. Unit is point / 1sec.
    );

    // Notify when the menu is dragged
    virtual void onDrag(
        VfxS32 xoffset, 
        VfxS32 yoffset);

    // Notify when the menu is tapped
    virtual void onTap(VfxPoint pt);


public:
    static void onDecodeCallBack(void* user_data, VfxS32 index, VfxS32 error_code);
    void updateDecodeResult(VfxS32 index, VfxS32 error_code);
    void onStatusChanged(VappShellMediaplayerStatusChangeEnum statusEnum);
    void onMediaChanged(void* resultP);
    void onPlayEnd(void* resultP);
    void onListEnd(void* resultP);
    void onFinishSwitchView(VfxFrame * target,VfxBool isCompleted);
    void prepare(void);
    void unprepare(void);    
    void onStopPlaying(void);
    void onStartPlaying(void);

private:
    void updateCellImage();
    void onTimerTick(VfxTimer *source);
    ShellMediaplayerResEnum unlockImageBuffer(VfxU8 *tmpImageBuf);
    ShellMediaplayerResEnum getImageBuffer(VfxS32 index, VfxS32 type, VfxU8 **tmpImageBuf, VfxS32 *tmpImageWidth, VfxS32 *tmpImageHeight);
    void onUpdateTimerExpired(VfxTimer *source);

    // Variable 

public:
    VfxSignal0 m_signalTapToPlay;
private:
    VfxS32  m_count;
    VfxS32  m_behindCount;
    VfxS32  m_aheadCount;
    VappShellMediaplayer *m_player;
    VfxBool m_isDragging;
    VfxBool m_isDecoding;
    VfxTimer *m_timer;
    VfxTimer *m_updateTimer;
    VfxS32 m_lastIndex;
};


 
/***************************************************************************** 
 * Class VappShellMediaplayer
 *****************************************************************************/
class VappShellMediaplayer : public VappShellPanel
{   
    VFX_DECLARE_CLASS(VappShellMediaplayer);
    VAPP_SHELL_PANEL_CREATE(VappShellMediaplayer, VFX_FALSE);

    typedef VappShellMediaplayer  Self;
    typedef VappShellPanel        Super;

public:
    enum
    {
        MAIN_SCREEN_VIEW = 0,
        LIST_MENU_VIEW = 1
    };

public:
    enum VappShellMediaplayerStateEnum
    {
        STATE_IDLE ,
        STATE_PROCESSING,
        STATE_PLAYING,
        STATE_MEDIACHANGE,
        STATE_TAPTOPLAY,
        STATE_TAPTOSTOP
    };
public:
    enum VappShellMediaplayerSrvStateEnum
    {
        SRV_STATE_IDLE,
        SRV_STATE_READY,
        SRV_STATE_NOT_READY
    };


    // Constructor / Destructor
public:
    VappShellMediaplayer();
    
// Override
protected:
    // On init. application can do component initalization here. Don't 
    // create components here. In this stage, it is only supposed to
    // do some component initialization, such as send message to other
    // task to gather some data.
    virtual void onInit();

    // On Deinit. application can do component deinitalization here.
    virtual void onDeinit();
    
    
    // init view. application can create components here
    virtual void onInitView();
    
    // deinit view. applicaiton can close components which are created in onInitView stage
    virtual void onDeinitView();
    
    // enter view. Application can create components which waste
    // lots of resources here.
    virtual void onEnterView();
    
    // exit view. Application can release those resources which
    // is obtained in onEnterView
    virtual void onExitView(ShellExitCauseEnum cause);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

// Method
public:
    VfxBool isNext();
    void setIsNext(VfxBool isNext);
    //void setMainScreenAlbum();
    VfxS32 getSongCount();
    VfxS32 getSongCountMenu();
    VfxS32 index();
    VfxS32 getLastIndex();
    void setLastIndex(VfxS32 i);
    void setIndex(VfxS32 index);
    void setViewMode(VfxS32 m_viewMode);
    VfxS32 getViewMode();
    VfxS32 next();
    VfxS32 prev();
    VfxBool isEnterView();
    VappShellMediaplayerSrvStateEnum getSrvState();
    VfxU8 playerState();
    VappShellMediaplayerStateEnum state();
    void setVol(VfxU8 volume);
    void setState(VappShellMediaplayer::VappShellMediaplayerStateEnum state);
    void setDuration(VfxU64 durationMsec);
    void setCurrPlayTime(VfxU64 currPlayTimeMsec);
    VfxU64 getCurrPlayTime();
    VfxU64 getDuration();
    void onListChange(void);
    static void onPlayerCallback(void* userdata, VfxU32 type, void* resultP);
    static void onListChange(void* user_data);

    vadp_shell_mediaplayer_repeat_mode_enum repeatMode();
    void setRepeatMode(vadp_shell_mediaplayer_repeat_mode_enum mode);
    VfxBool isShuffle();
    void setShuffle(VfxBool shuffle);

#if defined(__MMI_AVRCP_SUPPORT__) 
    VfxU8 avrcpCommandHandler(void* userdata, VfxU8 command, mmi_avrcp_key_events event);
    static VfxU8 avrcpCmdHdlr(void* userdata, VfxU8 command, mmi_avrcp_key_events event);
#endif
    void onFinishSwitchView(VfxFrame * target,VfxBool isCompleted);
// Private method
private:

    void onStatusChanged(void* resultP);
    void onMediaChanged(void* resultP);
    void onPlayEnd(void* resultP);
    void onListEnd(void* resultP);
    void onMenuDragStart(void);
    void onSwitchView(void);
    void onTapToPlay();
    void onWaitingTimerExpired(VfxTimer *source);
    ShellMediaplayerResEnum initPlstService();
    ShellMediaplayerResEnum deinitPlstService();
    ShellMediaplayerResEnum initMediaCacheService();
    ShellMediaplayerResEnum deinitMediaCacheService();   


// Variables
private:
    VcpPagePanel                    *m_pagePanel;
    VfxWeakPtr <VappShellMediaplayerMenuFrame>  m_menuFrame;
    VfxWeakPtr <VappShellMediaplayerMainScreen> m_mainScreen;

    VfxBool m_isShuffle;
    VfxBool m_forceToPlay;
    vadp_shell_mediaplayer_repeat_mode_enum m_repeatMode;
    
    VfxS32 m_viewMode;
    VfxS32 m_highlightIndex;
    VfxS32 m_preIndex;
    VfxS32 m_songCount;
    VfxS32 m_songCountMenu;
    
    VfxU64 m_currTimeMsec;
    VfxU64 m_durationMsec;
    VfxBool m_isNext;
    VappShellMediaplayerStateEnum m_state;
    VfxU8 m_playerState;
    VfxU8 m_volume;
    VfxTimer *m_waitingTimer;
    VappShellMediaplayerSrvStateEnum m_initService;
    VfxBool m_isEnterView;
};

#endif /* __MMI_VUI_SHELL_MEDIA_PLAYER__ */
#endif /* __VAPP_SHELL_MEDIAPLAYER_H__ */

