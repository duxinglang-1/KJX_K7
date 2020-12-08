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
 *  vapp_cube_media_player.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  media player cube screen 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 #include "MMI_Features.h"
#ifdef __MMI_VUI_3D_CUBE_APP_MEDIA_PLAYER__
#ifndef __VAPP_CUBE_MEDIA_PLAYER_H__
#define __VAPP_CUBE_MEDIA_PLAYER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vcp_include.h"

#include "vapp_cube_scr.h"

#include "CubeApp\vadp_v2p_cube_media_player.h"

#include "vcp_base_menu.h"
#include "vcp_frame_effect.h"
#include "vcp_status_icon_bar.h"
/***************************************************************************** 
 * Macro define
 *****************************************************************************/


/***************************************************************************** 
 * Type define
 *****************************************************************************/
  enum {
    EMPTY_MODE,
    NAVIGATION_MODE,
    PLAY_MODE,
    STARTUP_MODE,
    PRE_NAVIGATION_MODE,
  };
  enum {
    EMPTY_UI,
    NAVIGATION_UI,
    NAV_TO_PANEL_UI,
    PANEL_UI,
    PANEL_TO_NAV_UI
  };
  
  enum cube_medply_app_state{
    IDLE = 0,
    BG_PLAYING,   //  background playing at NAVIGATION_UI, 
    BG_PAUSE,     //  background pause   at NAVIGATION_UI    ,
    TAP_TO_PLAY,    //  after tap the focus cell, the next action is apply and play
    TAP_TO_PAUSE,
    TAP_TO_PREPARE, //  after tap the focus cell, the next action is apply
    TO_PLAY,
    TO_PREPARE,
    TO_RESUME_PAUSE, // after tap the focus cell, the next action is show pause 
    TO_RESUME_PLAY,  // after tap the focus cell, the next action is show play 
    SWIP_TO_PLAY,
    SWIP_TO_PREPARE,
    SWIP_TO_IDLE,
    PREPARED,   // at PANEL_UI
    PAUSE,      // at PANEL_UI
    PLAYING,     // at PANEL_UI   
    ASKED_TO_PLAY,  // media change to play
    ASKED_TO_PREPARE, // bt media change when not playing
    END_OF_STATE
  };

/***************************************************************************** 
 * Class VappCubeMediaPlayerState
 *****************************************************************************/
 class VappCubeMediaPlayerState
 {
    VfxU8 m_state;
 public:
    VappCubeMediaPlayerState() { m_state = IDLE;}
    VfxU8 get(){ return m_state;}
    VfxBool set(VfxU8 s);  
 };

/***************************************************************************** 
 * Class VappCubeMediaPlayerButton
 *****************************************************************************/
class VappCubeMediaPlayerButton:public VfxControl
{

    /* Constructor / Destructor */
  public:
    /* Default constructor */
    VappCubeMediaPlayerButton();

    /* Destructor */
    virtual ~ VappCubeMediaPlayerButton();

    /* Signal */
  public:
    /* Pen down signal */
    VfxSignal1 < VfxPenEvent & >m_eventPenDown;

    /* Pen up signal */
    VfxSignal1 < VfxPenEvent & >m_eventPenUp;

    /* Method */
  public:
    /* Set image resource ID */
    void setImage(VfxS32 upImageId,     /* [IN] up image ID */
                  VfxS32 downImageId    /* [IN] down image ID */
        );
    void getImage(VfxS32 *p_upImageId,  /* [OUT] up image ID */
                  VfxS32 *P_downImageId /* [OUT] down image ID */
        );
    /* Set display flag */
    void setDisplay(VfxBool isDisplay   /* [IN] display flag */
        );

    // The function can get the pen type of button
    // RETURNS: the current pen type 
    VfxS32 getPenType(void);

    /* Set button pen type */
    void setPenType(VfxS32 PenType  /* [IN] PenType */
        );
public:
    virtual void setIsDisabled(VfxBool isDisabled);
    
    virtual VfxBool getIsDisabled();       
    /* Override */

  private:
    /* On init */
      virtual void onInit();

    /* On deinit */
    virtual void onDeinit();

    // On pen input
    // RETURNS: VfxBool    
    virtual VfxBool onPenInput(VfxPenEvent & event);
    

    
    /* Variable */
  private:
    /* Image frame */
      VfxImageFrame *m_image;

    VfxImage *m_bgImage;

    /* Up image resource ID */
    VfxS32 m_imageUpId;

    /* Down image resource ID */
    VfxS32 m_imageDownId;

    /* Current pen type */
    VfxS32 m_curr_pentype;
};

/***************************************************************************** 
 * Class VappCubeMediaPlayerProgress
 *****************************************************************************/
class VappCubeMediaPlayerProgress:public VfxFrame
{

    /* Constructor / Destructor */
  public:
    /* Default constructor */
    VappCubeMediaPlayerProgress();

    /* Destructor */
    virtual ~ VappCubeMediaPlayerProgress();

    /* Method */
  public:
    /* Set image resource ID */
    void setImage(VfxS32 bgImage,   /* [IN] background image */
                  VfxS32 fgImage    /* [IN] foreground image */
        );

    /* Set progress ratio */
    void setRatio(VfxS32 ratio  /* [IN] ratio */
        );

    // The function can get the ratio of this progress bar
    // RETURNS: the current ratio    
    VfxS32 getRatio(void) const;

    /* Override */
  private:
    /* On init */
      virtual void onInit();

    /* On Deinit */
    virtual void onDeinit();

    /* On Draw */
    virtual void onDraw(VfxDrawContext & dc);

    /* Variable */
  private:
    /* Progress bar ratio */
      VfxS32 m_ratio;

    /* Foreground image frame */
    VfxImageFrame *m_imageFg;

    /* Background image frame */
    VfxImageFrame *m_imageBg;

    /* Foreground image resource ID */
    VfxS32 m_imageFgId;

    /* Background image resource ID */
    VfxS32 m_imageBgId;
};

/***************************************************************************** 
 * Class VappCubeMediaPlayerTime
 *****************************************************************************/
class VappCubeMediaPlayerTime:public VfxFrame
{

    /* Constructor / Destructor */
  public:
    /* Default constructor */
    VappCubeMediaPlayerTime();

    /* Destructor */
    virtual ~ VappCubeMediaPlayerTime();

    /* Method */
  public:
    /* Set the time to display */
    void setTime(VfxS32 hour,   /* [IN] hour */
                 VfxS32 min,    /* [IN] min */
                 VfxS32 sec     /* [IN] sec */
        );

    /* Set the time to display */
    void setTime(VfxS32 s   /* [IN] ms */
        );

    /* Get the time of display */
    void getTime(VfxS32 *hourP, /* [OUT] hour */
                 VfxS32 *minP,  /* [OUT] min */
                 VfxS32 *secP   /* [OUT] sec */
        );
    void getTime(VfxS32 *p_total);

    /* Override */
  private:
    /* On init */
      virtual void onInit();

    /* On Deinit */
    virtual void onDeinit();

    /* Variable */
  private:
    /* Tens place of min image */
     VfxImage *m_imageH1;

    /* Ones place of min image */
    VfxImage *m_imageH2;  	

    /* Tens place of min image */
      VfxImage *m_imageM1;

    /* Ones place of min image */
    VfxImage *m_imageM2;

    /* Tens place of sec image */
    VfxImage *m_imageS1;

    /* Ones place of sec image */
    VfxImage *m_imageS2;

    /* Colon  image */
    VfxImage *m_imageColon;
    
    /* Tens place of min frame */
    VfxFrame *m_h1;

    /* Ones place of min frame */
    VfxFrame *m_h2;
    
    /* Tens place of min frame */
    VfxFrame *m_m1;

    /* Ones place of min frame */
    VfxFrame *m_m2;

    /* Tens place of sec frame */
    VfxFrame *m_s1;

    /* Ones place of sec frame */
    VfxFrame *m_s2;

    /* Colon  frame */
    VfxFrame *m_colon1;

    /* Colon  frame */
    VfxFrame *m_colon2;
    
    /* Hour value */
    VfxS32 m_hour;

    /* Min value */
    VfxS32 m_min;

    /* Sec value */
    VfxS32 m_sec;

    VfxS32 m_totalSec;

    /* if already has layout */
    VfxBool m_isLayouted;

    /* Implementation */
  public:
    /* Layout the position of image frames */
    void layout(void);
    void clear(void);
};

/***************************************************************************** 
 * Class VappCubeMediaPlayerRepeatPanel
 *****************************************************************************/
class VappCubeMediaPlayerRepeatPanel:public VfxControl
{

    /* Constructor / Destructor */
  public:
    /* Default constructor */
    VappCubeMediaPlayerRepeatPanel();

    /* Destructor */
    virtual ~ VappCubeMediaPlayerRepeatPanel();

  public:
    VfxSignal0 m_eventShuffleOn;
    VfxSignal0 m_eventShuffleOff;
    VfxSignal0 m_eventRepeatOne;
    VfxSignal0 m_eventRepeatAll;
    VfxSignal0 m_eventRepeatOff;

  public:
    VappCubeMediaPlayerButton *m_repeatOneBtn;
    VappCubeMediaPlayerButton *m_repeatAllBtn;
    VappCubeMediaPlayerButton *m_repeatOffBtn;
    VappCubeMediaPlayerButton *m_shuffleOnBtn;
    VappCubeMediaPlayerButton *m_shuffleOffBtn;

  private:
      VfxBool m_shuffle;
    VfxBool m_repeatOne;
    VfxBool m_repeatAll;
    VfxBool m_repeatOff;
    VfxBool m_isLayouted;

    VfxBool m_hasRepeat;
    VfxBool m_hasShuffle;

  public:   /* On init */
      virtual void onInit();

    /* On deinit */
    virtual void onDeinit();

    // On pen input
    // RETURNS: VfxBool    
    virtual VfxBool onPenInput(VfxPenEvent & event);

  public:
    void setRepeat(VfxBool one, VfxBool all, VfxBool off);
    void getRepeat(VfxBool *p_one, VfxBool *p_all, VfxBool *p_off);
    void setShuffle(VfxBool shuf);
    void getShuffle(VfxBool *p_shuf);
    void layout(void);
    void clear(void);
    VfxBool getIsDisabled(void);
    void setIsDisabled(VfxBool b);

  private:
    void onShuffleOn(VfxPenEvent & event);
    void onShuffleOff(VfxPenEvent & event);
    void onRepeatOne(VfxPenEvent & event);
    void onRepeatAll(VfxPenEvent & event);
    void onRepeatOff(VfxPenEvent & event);
};

/***************************************************************************** 
 * Class VappCubeMediaPlayerPlayPanel
 *****************************************************************************/
class VappCubeMediaPlayerPlayPanel:public VfxControl
{

    /* Constructor / Destructor */
  public:
    /* Default constructor */
    VappCubeMediaPlayerPlayPanel();

    /* Destructor */
    virtual ~ VappCubeMediaPlayerPlayPanel();

  public:
    VappCubeMediaPlayerButton *m_playButton;
    VappCubeMediaPlayerButton *m_pauseButton;
    VappCubeMediaPlayerButton *m_stopButton;
    VappCubeMediaPlayerButton *m_closeButton;
    VappCubeMediaPlayerRepeatPanel *m_shuffleButton;
    VappCubeMediaPlayerRepeatPanel *m_repeatButton;
    VfxAnimation *m_arrowAnim;

      VfxSignal1 < VfxS32 > m_eventSwitch;
    VfxU32 m_curIndex;

  private:
      VfxImageFrame *m_bgFrame;
    VfxFrame *m_cover;
    VcpMarquee *m_songName;
    VfxImage *m_image;
    VfxWString m_nameText;

    VappCubeMediaPlayerProgress *m_progress;

    VappCubeMediaPlayerTime *m_curTime;
    VappCubeMediaPlayerTime *m_totalTime;

    VfxBool m_isPlay;
    VfxBool m_isScroll;
    VfxBool m_isLayouted;

    VfxS32 m_curTimeValue;
    VfxS32 m_totalTimeValue;
    VfxS32 m_progressRatio;

    VfxS32 m_curr_pentype;
    VfxS32 m_penY;
    VfxS32 m_penX;

    VfxBool m_shuffle;
    VfxBool m_repeatOne;
    VfxBool m_repeatAll;
    VfxBool m_repeatOff;

    VfxImageFrame *m_upArrow;
    VfxImageFrame *m_downArrow;
    VfxFloatTimeline *m_upArrowTimeline;
    VfxFloatTimeline *m_downArrowTimeline;

  public:
    void setIsPlay(VfxBool b);
    void getIsPlay(VfxBool *pb);

    void setIsScroll(VfxBool b);
    void getIsScroll(VfxBool *pb);

    void setCurTime(VfxS32 sec);
    void getCurTime(VfxS32 *p_sec);

    void setTotalTime(VfxS32 sec);
    void getTotalTime(VfxS32 *p_sec);

    void setProgressRatio(VfxS32 r);
    void setProgressRatio(VfxU64 child, VfxU64 parent);
    void getProgressRatio(VfxS32 *pr);

    void setRepeat(VfxBool one, VfxBool all, VfxBool off);
    void getRepeat(VfxBool *p_one, VfxBool *p_all, VfxBool *p_off);

    void setShuffle(VfxBool shuf);
    void getShuffle(VfxBool *p_shuf);

    void setPicture(VfxImage *p_image);
    void setSongName(VfxWChar *s);

    void layout(void);
    void clear(void);

    void startProcessing(void);
    void stopProcessing(void);

    void setTotalTimeDisplay(VfxBool b);
    void setCurTimeDisplay(VfxBool b);
  public:   /* On init */
      virtual void onInit();

    /* On deinit */
    virtual void onDeinit();

    // On pen input
    // RETURNS: VfxBool    
    virtual VfxBool onPenInput(VfxPenEvent & event);
    
    void onClickClose(VfxPenEvent & event);
    
  private:
    void onClickPlay(VfxPenEvent & event);
    void onClickPause(VfxPenEvent & event);    
    void onClickStop(VfxPenEvent & event);

};

/***************************************************************************** 
 * Class VappCubeMediaPlayerAgent
 *****************************************************************************/
class VappCubeMediaPlayerAgent:public VfxObject
{
    /* Declaration */
  public:
    /* The state */
    enum
    {
        STATE_INIT = VAPP_CUBE_MEDIA_PLAYER_STATE_INIT, /* Init */
        STATE_PLAY = VAPP_CUBE_MEDIA_PLAYER_STATE_PLAY, /* Playing */
        STATE_PROCESS = VAPP_CUBE_MEDIA_PLAYER_STATE_PROCESS    /* Processing */
    };

    /* Constructor / Destructor */
  public:
    /* Default constructor */
      VappCubeMediaPlayerAgent();

  public:

    VfxSignal0 m_eventUpdate;
    VfxSignal0 m_eventPlayEnd;
    VfxSignal0 m_eventMediaChanged;
    VfxSignal0 m_eventStatusChanged;
    VfxSignal0 m_eventStop;
    VfxSignal0 m_eventPause;
    VfxSignal0 m_eventPlay;

    /* Implementation */
  public:
    /* Callback from plutommi media player application */
    static void playerCallback(void *userdata,  /* [IN] userdata */
                               VfxU32 type,     /* [IN] callback type */
                               void *resultP    /* [IN] information */
        );

    void OnShuffleOn(void);

    void OnShuffleOff(void);

    void OnRepeatOne(void);

    void OnRepeatAll(void);

    void OnRepeatOff(void);

    // Play button up handle function
    // RETURNS: void    
    void onPlay(VfxPenEvent & event /* [IN] pen event */
        );

    // Pause button up handle function
    // RETURNS: void     
    void onPause(VfxPenEvent & event    /* [IN] pen event */
        );

    // Stop button up handle function
    // RETURNS: void     
    void onStop(VfxPenEvent & event /* [IN] pen event */
        );

    /* Get the state of application */
    VfxU8 getState(void);

    // Get the duration of current media file
    // RETURNS: duration
    VfxU64 getDuration(void);

    // Get the play time of current media file
    // RETURNS: play time
    VfxU64 getCurrTime(void);

    VfxS32 getCurPlayIndex();
    VfxS32 getLastPlayIndex();
    
    void getRepeat(VfxBool *p_one, VfxBool *p_all, VfxBool *p_off);

    void getShuffle(VfxBool *p_shuf);
    VfxS32 getTotalCount(void);
    void setTotalCount(VfxS32 cnt);
    void setCurPlayIndex(VfxS32 index);
    VfxBool isListEnd();
    /* Variable */
  private:
    VfxBool m_isListEnd;
    /* total items */
      S32 m_total;
    /* State */
    VfxU8 m_state;

    /* Duration */
    VfxU64 m_durationMsec;

    /* Current time */
    VfxU64 m_currTimeMsec;

    /* current play index */
    VfxS32 m_curPlayIndex;

    /* last play index */
    VfxS32 m_lastPlayIndex;

    VfxBool m_shuffle;

    VfxBool m_repeatOne;

    VfxBool m_repeatAll;

    VfxBool m_repeatOff;

    /* Polling timer */
    VfxTimer *m_timer;

    /* Timer flag */
    VfxBool m_isTimerStart;

    VfxBool m_isWaitState;
    VfxBool m_isWaitPause;

  private:
    /* On Init */
      virtual void onInit();

    /* On Deinit */
    virtual void onDeinit();

    // Status change notification function
    // RETURNS: void
    void onStatusChanged(void *resultP  /* [IN] information */
        );

    // Media change notification function
    // RETURNS: void    
    void onMediaChanged(void *resultP   /* [IN] information */
        );

    // Play end notification function
    // RETURNS: void     
    void onPlayEnd(void *resultP    /* [IN] information */
        );

    // List end notification function
    // RETURNS: void     
    void onListEnd(void *resultP    /* [IN] information */
        );
        
    void onResetCurTime(void* resultP  /* [IN] information */
        );

    /* Start polling timer */
    void startGetCurrtimeTimer(void);

    /* Stop polling timer */
    void stopGetCurrtimeTimer(void);

    /* Timer callback */
    void onTimerTick(VfxTimer *source   /* [IN] timer */
        );
    void setRepeat(VfxBool one, VfxBool all, VfxBool off);
    void setShuffle(VfxBool shuf);

};

/***************************************************************************** 
 * Class VappCubeMediaPlayerCell
 *****************************************************************************/
class VappCubeMediaPlayerCell:public VfxControl
{
    /* Constructor / Destructor */
  public:
    /* Default constructor */
    VappCubeMediaPlayerCell();

    /* Override */
  public:
    /* On init */
    virtual void onInit();

    /* On deinit */
    virtual void onDeinit();

    /* Method */
  public:
    void setPicture(VfxImage *p_image);
    void setSongName(VfxWChar *s);
    void setScroll(VfxBool b);
    void layout(void);
    void clear(void);

    void onHightLight();

    void onDeHightLight();

    VfxBool updateImage();

    void updatePos(const VfxRect & r, VfxBool animation);

    void enter(const VfxRect & r, VfxBool animation);

    void leave(const VfxRect & r);

    VfxBool getIsHighlight()
    {
        return m_isHighlight;
    }

    void setCellInnerX(VfxS32 value)
    {
        m_innerX = value;
    }

    void setCellInnerY(VfxS32 value)
    {
        m_innerY = value;
    }

  public:

    VfxBool m_isLayouted;
    VfxImageFrame *m_cd;
    VfxImageFrame *m_cdHighlight;

    /* Variable */
  private:
    VfxS32 m_width;
    VfxS32 m_height;

    VfxImage *m_image;
    VfxFrame *m_pic;

    VfxBool m_isHighlight;
    VfxS32 m_innerX;
    VfxS32 m_innerY;

    VcpMarquee *m_songName;
    VfxWString m_nameText;

    /* backgroud image res id */
    VfxS32 m_resId;

    VfxBool m_isScroll;
    VfxBool m_hasSongName;
    VfxBool m_hasPic;

};

/***************************************************************************** 
 * Class VappCubeMediaPlayerLayout
 *****************************************************************************/

class VappCubeMediaPlayerLayout:public VcpBaseMenuLayout
{
    /* Constructor / Destructor */
  public:
    VappCubeMediaPlayerLayout(VcpBaseMenu *menu):VcpBaseMenuLayout(menu)
    {
    }

    /* Override */
  public:
      virtual void onInit();

    virtual void onDeinit();

#if 1
    /* Return the scroll direction */
    virtual ScrollDirEnum getScrollDir()
    {
        return SCROLLDIR_VERT;
    }
#endif /* 1 */ 
    // Return the number of cells of a group.
    // Inherit should override this method.
    virtual VfxS32 getCellCount(VfxS32 group    /* [IN] The group index */
        )
    {
        return m_cellCount;
    }

    // Return the whole size of the menu.
    // Inherit should override this method.
    virtual VfxS32 getContentLength();

    /* Return the region within a rectangle. */
    virtual VcpMenuRegion queryRegion(const VfxRect & r /* [IN] The rectangle to query the menu region */
        );

    /* Return the position by a point */
    virtual VcpMenuPos queryPosByPt(const VfxPoint & pt /* [IN] The point wants to do hittest */
        );

    /* Return a cell rect */
    virtual VfxRect queryCellRect(VcpMenuPos pos    /* [IN] The cell index to query */
        );

    // Change the focus by Navigation key
    // RETURNS: VFX_TRUE if you can navigation by this direction
    virtual VfxBool navDir(NavDirEnum dir   /* [IN] the change focus direction */
        );

    // Get the focus margin.
    // Focus margin is the prefer space that focus item should not be over.
    virtual void getPreferFocusMargin(VfxS32 margin[4]  /* [OUT] the focus margin in Left, Up, Right, Down */
        );

    /* Change the Focus Index */
    virtual void setFocusItem(VcpMenuPos focus, /* [IN] The focus index */
                              VfxBool isMoveToVisible = VFX_TRUE        /* [IN] whether move focus item to be visible */
        );
    
    void fixFocusIndex();

    /* Method */
  public:
    void setCellWidth(VfxS32 value)
    {
        m_cellWidth = value;
    }

    void setCellHeight(VfxS32 value)
    {
        m_cellHeight = value;
    }

    void setCellCount(VfxS32 value)
    {
        m_cellCount = value;
    }

    void setCellInnerX(VfxS32 value)
    {
        m_cellInnerX = value;
    }

    void setCellInnerY(VfxS32 value)
    {
        m_cellInnerY = value;
    }

    void setCellOffsetX(VfxS32 value)
    {
        m_cellOffsetX = value;
    }

    VfxS32 getCellInnerX()
    {
        return m_cellInnerX;
    }

    VfxS32 getCellInnerY()
    {
        return m_cellInnerY;
    }
    void setNavDisabled(VfxBool b)
    {
       m_isNavDisabled = b;     
    }
    
    VfxS32 getCellHeight()
    {
        return m_cellHeight;
    }

    /* Method */
  private:
    VcpMenuPos getCellByPos(VfxPoint pt);

    /* Variable */
  private:
    VfxS32 m_cellCount;
    VfxS32 m_cellWidth;
    VfxS32 m_cellHeight;
    VfxS32 m_cellInnerX;
    VfxS32 m_cellInnerY;
    VfxS32 m_cellOffsetX;
    VfxBool m_isNavDisabled;
};

/***************************************************************************** 
 * VappCubeMediaPlayerImageData
 *****************************************************************************/

class VappCubeMediaPlayerImageData:public VfxObject
{
  public:
    VappCubeMediaPlayerImageData()
    {
    };

    virtual ~ VappCubeMediaPlayerImageData()
    {
    };

    VfxImage *getSmallImageContent(VfxS32 index);
    VfxImage *getBigImageContent(VfxS32 index);
    virtual void closeImageContent(VfxS32 index);
    void refreshImageContent(VfxS32 index);

    /* public: */

  protected:
    virtual void onInit();
    virtual void onDeinit();

  private:
    VfxImage *m_Image[VAPP_CUBE_MEDPLY_S_COVER_BUF_NUM];
    VfxImageBuffer m_smallCover[VAPP_CUBE_MEDPLY_S_COVER_BUF_NUM];
    VfxS32 m_nBuff[VAPP_CUBE_MEDPLY_S_COVER_BUF_NUM];
    
    VfxImage *m_bigImage;
    VfxImageBuffer m_largeCover;
    VfxS32 m_bigImageIndex;
};

/***************************************************************************** 
 * Class VappCubeMediaPlayerMenu
 *****************************************************************************/

class VappCubeMediaPlayerMenu:public VcpBaseMenu
{
  public:
    struct FramePropertyEffectData
    {
        VfxS32 group;
        VfxS32 pos;
        VfxRect r;
    };

  public:
      VappCubeMediaPlayerMenu();

    /* Signal */
  public:
    /* Pen down signal */
      VfxSignal1 < VfxS32 > m_eventFocusChange;
      VfxSignal2 < VfxS32, VfxFrame *>m_eventTapCell;
	  void checkFocusResume(VappCubeMediaPlayerCell* cell);

    /* Override */
  public:
    /* On init */
      virtual void onInit();

    virtual void onDeinit();

    virtual VcpBaseMenuLayout *createLayout();

    virtual VfxFrame *createCell(VfxS32 group,  /* [IN] The group index */
                                 VfxS32 pos     /* [IN] The cell index */
        );

    /* A notify that menu is going to close a cell */
    virtual void onCloseCell(VfxS32 group,          /* [IN] The group index */
                             VfxS32 pos,            /* [IN] The cell index */
                             VfxFrame *cellFrame    /* [IN] The cell will be closed */
        );
#if 1   //@TODO: this should open till new basemenu load is ready , will remove to .cpp file
    static vrt_render_dirty_type_enum VappCubeMediaPlayerMenu::framePropertyEffectCallback(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size)
    {
        VFX_DEV_ASSERT(target_frame != NULL);
        VFX_DEV_ASSERT(watch_frame != NULL);
        VFX_DEV_ASSERT(user_data != NULL && user_data_size == sizeof(FramePropertyEffectData));
        FramePropertyEffectData* data = (FramePropertyEffectData*)user_data;

        VfxS32 offset = target_frame->pos.y - watch_frame->bounds.origin.y - data->r.size.height * 2;
        
        VfxS32 org = target_frame->pos.x;
        target_frame->pos.x = 6 + data->r.size.width -
            VfxS32(
                vfxCos((1.5f * offset)  / VfxFloat(data->r.size.width))
                    * data->r.size.width);

        return (org != target_frame->pos.x) ? VRT_RENDER_DIRTY_TYPE_DIRTY : VRT_RENDER_DIRTY_TYPE_NONE;
    }
#endif /* 0 */ 
    // Notify to update a cell's attributes
    // Inheritor should override this function.
    virtual void onUpdateCell(const VfxRect & rect, /* [IN] The position that layouter report */
                              VfxS32 group,         /* [IN] The group index */
                              VfxS32 pos,           /* [IN] The cell index in the group */
                              VfxFrame *cell,       /* [IN] The cell object */
                              VfxU32 flag           /* [IN] The state about this cell */
        );

    /* Notify when a cell is clicked */
    virtual void onTapCell(VfxS32 group,    /* [IN] The group index */
                           VfxS32 pos,      /* [IN] The cell index in the group */
                           VfxFrame *cell   /* [IN] The cell object */
        );

    virtual void onTouchCell(VcpMenuPos cellPos,            /* [IN] The cell position */
                             CellTouchTypeEnum touchType,   /* [IN] The touch type */
                             VfxPoint pt,                   /* [IN] The pen position */
                             VfxFrame *cell                 /* [IN] The cell object */
        );

    /* Notify when the focus item is change */
    virtual void onFocusIndexChange(VcpMenuPos focusItem,   /* [IN] The focus item index now */
                                    VcpMenuPos previousFocusItem        /* [IN] The previous focus item index */
        );

    /* Notify when the user start drag the menu */
    virtual void onDragStart();

    /* Notify when the user stop drag the menu */
    virtual void onDragEnd();
    
    // Notify the view is scrolling.
    virtual void onViewScrollStart();

    // Notify the view is end of scrolling.
    virtual void onViewScrollEnd();
    
    /* Notify when the view is dragged, maybe remove the focus */
    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset);

    // Test if the frame contains the specified point
    // RETURNS:
    //  Return VFX_TRUE if the clip bound of the frame contains the point
    virtual VfxBool onContainPoint(const VfxPoint & point   /* [IN] the point in the coordinate of the frame */
        ) const;
    virtual VfxBool getIsDisabled();

    // Set the control to disabled state.
    virtual void setIsDisabled(
        VfxBool isDisabled   // [IN] The disable state
    );
    /* Method */
  public:
    void setCacheNumber(VfxS32 number); 
    
    void setCellWidth(VfxS32 value);

    void setCellHeight(VfxS32 value);

    void setCellCount(VfxS32 value);

    void setCellInnerX(VfxS32 value);

    void setCellInnerY(VfxS32 value);

    void setHighLightIdx(VfxS32 value, VfxBool goToPlay);

    void setCellOffsetX(VfxS32 value);

    /* Timer callback */
    void onScrollTimerTick(VfxTimer *source /* [IN] Timer */
        );

    void updateCellPic(VfxS32 index, VfxImage *image);

    static void updateAll(void *user_data, VfxS32 index);
    VfxFrame *getScrPtr()
    {
        VfxFrame *p = (VfxFrame *)getParentFrame()->getParentFrame();  
        return p;
    }
    void onUpdateImageCell(VfxS32 index);
    
    void onUpdateImageTick(VfxTimer *source);
    
    void onScrollStopPosFix(VfxPoint& pos);

    /* Variable */
  public:
    VfxU32 m_isManualSwitch;
    VfxBool m_isPageActReged;
    VfxS32 m_updateFocusIndex;
    VappCubeMediaPlayerLayout *m_listLayout;
    VfxBool m_isViewScrolling;

  public:
    VfxTimer *m_scrollTimer;
    VfxTimer *m_updateTimer;
    VfxS32   m_updateSeqNum;
    VappCubeMediaPlayerImageData *m_imageFlowData;
    VappCubeMediaPlayerPlayPanel *m_playPanel;
    VappCubeMediaPlayerState     *m_pState;

  protected:
	VfxBool m_bWaitingFocusCell;
};

/***************************************************************************** 
 * Class VappCubeMediaPlayerScr
 *****************************************************************************/

class VappCubeMediaPlayerScr:public VappCubeScr
{
    /* Constructor / Destructor */
  public:
    /* Default constructor */
    VappCubeMediaPlayerScr();

    /* Override */
  public:
    void regDefaultPageAct(VfxControl *obj)
    {
        VappCubeScr::regDefaultPageAct(obj);
    }
    
    void deregDefaultPageAct(VfxControl *obj)
    {
        VappCubeScr::deregDefaultPageAct(obj);
    }

    /* Override */
  protected:
      virtual void onInit();
    virtual void onDeinit();

    /* Method */
  public:
    void regPageAct(VfxControl *obj);
    void deregPageAct(VfxControl *obj);
    /* Slot */
  private:
    void onEventFocusChange(VfxS32 index);
    void adjustFocusItem();
    /* Timer callback */
    void onTimerTick(VfxTimer *source   /* [IN] Timer */
        );

    /* Timer callback */
    void onSwitchPlay(VfxS32 delta);
    void onBackEffectFinish(VfxFrame *cell, VfxBool b);
    void onFrontEffectFinish(VfxFrame *cell, VfxBool b);
    void onEventTapCell(VfxS32 index, VfxFrame *cell);
    void loadPlayPanel();
    void onEventUpClose(VfxPenEvent & event);
    void onEventUpCurPlay(VfxPenEvent & event);
    void onEventUpdate(void);
    void onEventPlayEnd(void);
    void onEventMediaChange(void);
    void onEventStatusChange(void);
    void onEventPlayPaused();
    void onEventPlayStop();
    void onEventPlaying();
    void preparePlayPanel();
    void directClosePanel();
    void keepInNavigation();
    void delayAskToPlay();
    void disableNavigation();
    void enableNavigation();
    void delayToPlay();
    
    /* Variable */
  private:

      VappCubeMediaPlayerMenu *m_menu;
    VfxS32 m_lcdWidth;
    VfxS32 m_lcdHeight;
    VfxS32 m_cellCount;
    VfxS32 m_cellWidth;
    VfxS32 m_cellHeight;
    VfxS32 m_cellInnerX;
    VfxS32 m_cellInnerY;
    VfxS32 m_highLightIdx;

    VfxTimer *m_timer;

    /* Background image */
    VappCubeMediaPlayerPlayPanel *m_playPanel;
    VappCubeMediaPlayerAgent     *m_playAgent;
    VappCubeMediaPlayerButton *m_curPlayBtn;
    
    VcpFrameEffect *m_effectFront;
    VcpFrameEffect *m_effectBack;
    VfxImageFrame *m_bgImage;

    VfxBool m_isPageActReged;
    VfxBool m_hasSetPlayIndex;

  public:    
    VfxU32 m_uiStyle;
    VfxU32 m_mode;    
    VappCubeMediaPlayerState m_state;  // not pointer!!    
};

#endif /* __VAPP_CUBE_MEDIA_PLAYER_H__ */ 
#endif
