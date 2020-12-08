/***************************************************************************** 
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_widget_key_musicplayer.h
 *
 * Project:
 * --------
 *  MAUI
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
#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_KEY_MUSIC_PLAYER__)
#include "vapp_widget_def.h"
#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vfx_cpp_base.h"
#include "vfx_primitive_frame.h"
#include "vfx_frame.h"
#include "vfx_draw_context.h"
#include "vapp_widget.h"
#include "vfx_sys_memory.h"
#include "vfx_string.h"
#include "vfx_timer.h"
#include "vfx_weak_ptr.h"
#include "vfx_text_frame.h"
#include "vcp_image_button.h"
#include "vcp_waiting_icon.h"

extern "C"
{
#include "wgui.h"
#include "FileMgrSrvGProt.h"
#include "meta_tag_api.h"
}


/* Audio player info enumeration */
typedef enum
{
    VAPP_WIDGET_AUDPLAYER_INFO_STATE,        /* State */
    VAPP_WIDGET_AUDPLAYER_INFO_TITLE,        /* Title */
    VAPP_WIDGET_AUDPLAYER_INFO_FILEPATH,     /* Filename */
    VAPP_WIDGET_AUDPLAYER_INFO_ARTIST,       /* Artist */
    VAPP_WIDGET_AUDPLAYER_INFO_DURATION,     /* Duration */
    VAPP_WIDGET_AUDPLAYER_INFO_CURR_TIME,     /* Current time */
    VAPP_WIDGET_AUDPLAYER_INFO_PAUSE_DISABLE
} VappWidgetAudplayerGetInfoEnum;


typedef enum
{
    VAPP_WIDGET_BUTTON_PLAY,         /* Play button */
    VAPP_WIDGET_BUTTON_STOP,         /* Stop button */
    VAPP_WIDGET_BUTTON_PAUSE,        /* Pause button */
    VAPP_WIDGET_BUTTON_PREV,         /* Prev button */
    VAPP_WIDGET_BUTTON_NEXT          /* Next button */
} VappWidgetButtonTypeEnum;

/* Audio player widget state - Init */
#define VAPP_WIDGET_AUDPLAYER_STATE_INIT    (0)
/* Audio player widget state - Play */
#define VAPP_WIDGET_AUDPLAYER_STATE_PLAY    (1)
/* Audio player widget state - Process */
#define VAPP_WIDGET_AUDPLAYER_STATE_PROCESS (2)


//#define VAPP_HS_FYL_BUTTON_CLASS_NAME     "FYLBOTTON"

#define VAPP_WIDGET_PLAYER_TOUCH_MIN_RDS  20


class VappWidgetKeyMusicPlayerButton:public VfxControl
{
public:
    
    VappWidgetKeyMusicPlayerButton();
    
    ~VappWidgetKeyMusicPlayerButton();  

    // Override    
protected:
    // On init
    virtual void onInit();

    // On Deinit
    virtual void onDeinit();

public:
    void setImage(VfxS32 imageid );
    void setDisplay(VfxBool isDisplay);
    VfxBool isContains(VfxPoint pos, VfxU8 type);

private:
    // Image frame
    VfxImageFrame *m_image;
    // Up image resource ID
    VfxS32 m_imageId;
};


class VappWidgetKeyMusicPlayerProgress:public VfxFrame
{
public: 
    VappWidgetKeyMusicPlayerProgress();
    ~VappWidgetKeyMusicPlayerProgress();

protected:
    virtual void onInit();
    virtual void onDeinit();
    
public:
    void setRatio(VfxS32 ratio);
    VfxS32 getRatio(void) const;
    void setImage(VfxS32 m_Image1, VfxS32 m_Image2);

private:
    VfxImageFrame  *m_ProgressBg;
    VfxImageFrame  *m_ProgressFg;
    VfxImageFrame  *m_ProgressFgP;
    VfxS32 m_Ratio;
    VfxS32 m_ImageBg;
    VfxS32 m_ImageFg; 
};


class VappWidgetKeyMusicPlayerCover:  public VfxFrame
{
public :
    VappWidgetKeyMusicPlayerCover();
    ~VappWidgetKeyMusicPlayerCover();

protected:
    virtual void onInit();
    virtual void onDeinit();
	
public:
	void OnPaserTimerClick(VfxTimer *Source);
	void setAlbumPhoto(VfxImageBuffer &imageBuf);
	void onStartTimer(void);
	void onStopTimer(void);
	void getCovermem(void);
	void switchAutoEffect(VfxBool is_up, VfxBool is_current);
	void onAutoEffectCancel(void);
	void switchAutoEffectDone(VfxBaseTimeline * timeline,VfxBool isComplete);
	void setDragSmart(VfxSize size, VfxPoint Pos);
	void setDragSmartDone(VfxSize size, VfxPoint pos);
	void cancelDragSmart(VfxPoint pos);
	VfxBool isContains(VfxPoint pos);
	void setAnimaDirection(VfxBool is_up);
	void OnPaserBack(meta_tag_async_info_struct *detail);
	void retsetWaitingState(void);
	void setParentInfo(void* parent_info);
        void setAutoSwitch(void);
	void setSwitchInfo(VfxU8 type);
	VfxBool switchState(void);
	void startWaiting(void);
        void stopWaiting(void);
	
public:
static VfxU32 parserCallback(void* user_data, VfxU8 type, VfxU8 result, VfxU32 param);

private:
    VfxImageFrame  *m_CoverActive;
    VfxImageFrame  *m_CoverIdle;
    VfxImageFrame  *m_DefaultImg;
    VcpWaitingIcon *m_WaitingIcon;
    VfxBool m_IsTimerStart;
    VfxPointTimeline *m_pointTimeline[2];
    VfxTimer *m_TimerParser;
    VfxBool is_DefaultSet;
    VfxBool m_IsUp;
    VfxBool m_IsParserStart;
    VfxBool m_IsWaiting;
    VfxBool m_IsCancelStart;
    VfxBool m_IsWaitingSwitch;
    VfxU8 m_Switch;
    void* m_Parent;
};


class VappWidgetKeyMusicPlayerPanel: public VfxControl
{
enum
{
    STATE_INIT = VAPP_WIDGET_AUDPLAYER_STATE_INIT,          // Init
    STATE_PLAY = VAPP_WIDGET_AUDPLAYER_STATE_PLAY,          // Playing
    STATE_PROCESS = VAPP_WIDGET_AUDPLAYER_STATE_PROCESS     // Processing
};

public:
    VappWidgetKeyMusicPlayerPanel();
    ~VappWidgetKeyMusicPlayerPanel();

protected:
    virtual void onInit();
    virtual void onDeinit();
    

private:
    VfxU64 getDuration(void);
    VfxU64 getPlaytime(void);
    VfxChar* getArtistname(void);
    VfxChar* getFilename(void);
    VfxU16 getState(void);
    void onTimerClick(VfxTimer *timer);    
    void startCurTimer(void);
    void stopCurTimer(void);
    void setCurProgress(void);
    void onLongPTClick(VfxTimer *timer);
    void startLPTimer(void);
    void stopLPTimer(void);
    void getTimeString(VfxU64 msec, VfxWChar *timeStr,VfxU32 maxLength) const;

public:
    virtual VfxBool onKeyInput(VfxKeyEvent & event);
    virtual VfxBool onPenInput(VfxPenEvent & event);
    void switchSong(VfxU8 type);

    static void playerCallback(void *user_data, VfxU32 type, void* result);
    void onPlayend(void* result);
    void onMediaChanged(void *result);
    void onResetTime(void *result);
    void onStatusChanged(void *result);
    void updateDisplay(void);
    void onPlayDown(VfxPenEvent &event);
    void onPlayUp(VfxPenEvent &event);
    void onPauseDown(VfxPenEvent &event);
    void onPauseUp(VfxPenEvent &event);
    void switchPrev(VfxKeyEvent & event);
    void switchPlayPause(VfxKeyEvent & event);
    void switchNext(VfxKeyEvent & event);
    void nameFadeOut(void);
    void nameFadeIn(void);
    void onButtonUp(VfxObjWeakPtr this_ptr);
    void suspend(void);
    void resume(void);
    
public:
    VfxChar m_ArtistName[(META_TAG_FRAME_MAX_LEN + 1) * 2];
    VfxBool m_IsRescrollText;
    
private:
    VfxImageFrame  *m_ImageClassBg;
    VappWidgetKeyMusicPlayerCover *m_Album;
    VappWidgetKeyMusicPlayerButton  *m_PlayButton;
    VappWidgetKeyMusicPlayerButton  *m_PrevButton;
    VappWidgetKeyMusicPlayerButton  *m_NextButton;
    VfxImageFrame  *m_NameBg;
    VcpMarquee   *m_MarqueeText;
    VfxTextFrame  *m_DuraTime;
    VfxTextFrame  *m_PlayTime;
    VappWidgetKeyMusicPlayerProgress *m_Prog;
    VfxTimer *m_LongPressTimer;
    VfxTimer  *m_Timer;
    VfxU64 m_Duration;
    VfxU64 m_CurrentTime;   
    VfxChar m_FileName[(SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * 2];
    VfxBool m_IsReady;
    VfxBool m_IsTimerStart;
    VfxBool m_IsLongPressTimerStart;
    VfxBool m_IsPickPrev;
    VfxBool m_IsPickNext;
    VfxBool m_IsDownGetFirst;
    VfxU16 m_State;
    VfxPoint m_LastMovePos;
    VfxPoint m_FirstTap;
    VfxBool m_IsSwitchSong;
    VfxBool m_IsSwitchState;
    VfxBool m_IsLaunchApp;
    VfxBool m_IsPenEventCancel;
    VfxBool m_IsPrevPressing;
    VfxBool m_IsNextPressing;
    VfxBool m_IsPowerPressing;
};

class VappWidgetKeyMusicPlayer : public VappWidget
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetKeyMusicPlayer);
   
public:
    VappWidgetKeyMusicPlayer();
// Override

// Override
public:
    virtual VappWidgetId getId() const;
    virtual VfxSize getMaxSize() const;
    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;
    virtual VfxFrame *createIcon(VfxObject *parentObj);
    virtual VfxPoint onGetEditButtonOffset();

    virtual void onCreateView();
    virtual void onSuspend();
    virtual void onResume();
    // Release the whole widget content
    virtual void onReleaseView();
    VfxBool onPreviewPenInput(VfxPenEvent & event);
    VfxBool onPenInput(VfxPenEvent & event);


private:
    VfxImageFrame *m_Test;
    VappWidgetKeyMusicPlayerPanel  *m_Panel;    
};
#endif
