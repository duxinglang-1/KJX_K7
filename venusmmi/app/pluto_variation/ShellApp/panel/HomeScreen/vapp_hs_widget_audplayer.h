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
 *  vapp_hs_widget_audplayer.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: audplayer
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_HS_WIDGET_AUDPLAYER_H__
#define __VAPP_HS_WIDGET_AUDPLAYER_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_VUI_HOMESCREEN_AUDIO_PLAYER__
#include "vapp_hs_widget_base.h"
#include "vapp_hs_def.h"
#include "vcp_marquee.h"
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
#include "vapp_hs_widget_cfg.h"
#include "vfx_sys_memory.h"
#include "vfx_string.h"
#include "vfx_timer.h"
#include "vfx_weak_ptr.h"

extern "C"
{
#include "FileMgrSrvGProt.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_HS_AUDPLAYER_BUTTON_CLASS_NAME             "ADUPLAYERBUTTON"
#define VAPP_HS_AUDPLAYER_PROGRESS_CLASS_NAME           "ADUPLAYERPROGRESS"
#define VAPP_HS_AUDPLAYER_TIME_CLASS_NAME               "ADUPLAYERTIME"

/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * Class VappHsWidgetAudplayerButton
 *****************************************************************************/

/*
 * VappHsWidgetAudplayerButton is a class that support the button of audio player widget.
 *
 * EXAMPLE
 * <code>
 *  VappHsWidgetAudplayerButton *button;
 *  VFX_OBJ_CREATE(button, VappHsWidgetAudplayerButton, this);
 *  button->setPos(VfxPoint(13, 34));
 * </code>
 */ 
class VappHsWidgetAudplayerButton : public VfxControl
{
    VFX_DECLARE_CLASS(VappHsWidgetAudplayerButton);
    
// Constructor / Destructor    
public:
    // Default constructor
    VappHsWidgetAudplayerButton();

    // Destructor
    virtual ~VappHsWidgetAudplayerButton();

// Signal
public:
    // Pen down signal
    VfxSignal1 <VfxPenEvent &> m_eventPenDown;

    // Pen up signal
    VfxSignal1 <VfxPenEvent &> m_eventPenUp;

// Method
public:
    // Set image resource ID
    void setImage(
        VfxS32 upImage,     // [IN] up image ID
        VfxS32 downImage    // [IN] down image ID
    );

    // Set display flag
    void setDisplay(
        VfxBool isDisplay   // [IN] display flag
    );

    // The function can get the pen type of button
    // RETURNS: the current pen type 
    VfxS32 getPenType(void);

    // Set button pen type
    void setPenType(
        VfxS32 PenType      // [IN] PenType
    );
// Override    
private:
    // On init
    virtual void onInit();

    // On deinit
    virtual void onDeinit();

    // On pen input
    // RETURNS: VfxBool    
    virtual VfxBool onPenInput(
        VfxPenEvent &event
    );

// Variable    
private:
    // Image frame
    VfxImageFrame *m_image; 

    // Up image resource ID
    VfxS32 m_imageUpId;

    // Down image resource ID
    VfxS32 m_imageDownId;

    // Current pen type
    VfxS32 m_curr_pentype;
};


/***************************************************************************** 
 * Class VappHsWidgetAudplayerProgress
 *****************************************************************************/

/*
 * VappHsWidgetAudplayerProgress is a class that draws a progress bar.
 *
 * EXAMPLE
 * <code>
 *  VappHsWidgetAudplayerProgress *progress;
 *  VFX_OBJ_CREATE(progress, VappHsWidgetAudplayerProgress, this);
 *  progress->setPos(VfxPoint(0, 0));
 * </code>
 */
class VappHsWidgetAudplayerProgress : public VfxFrame
{
    VFX_DECLARE_CLASS(VappHsWidgetAudplayerProgress);

// Constructor / Destructor    
public:
    // Default constructor
    VappHsWidgetAudplayerProgress();

    // Destructor
    virtual ~VappHsWidgetAudplayerProgress();

// Method
public:
    // Set image resource ID
    void setImage(
        VfxS32 bgImage,     // [IN] background image
        VfxS32 fgImage      // [IN] foreground image
    );

    // Set progress ratio
    void setRatio(
        VfxS32 ratio        // [IN] ratio
    );

    // The function can get the ratio of this progress bar
    // RETURNS: the current ratio    
    VfxS32 getRatio(void) const;

// Override
private:
    // On init
    virtual void onInit();

    // On Deinit
    virtual void onDeinit();

    // On Draw    
    virtual void onDraw(
        VfxDrawContext &dc
    );

// Variable
private:
    // Progress bar ratio
    VfxS32 m_ratio;

    // Foreground image frame
    VfxImageFrame *m_imageFg;

    // Background image frame
    VfxImageFrame *m_imageBg;

    // Foreground image resource ID
    VfxS32 m_imageFgId;

    // Background image resource ID
    VfxS32 m_imageBgId;
};


/***************************************************************************** 
 * Class VappHsWidgetAudplayerTime
 *****************************************************************************/

/*
 * VappHsWidgetAudplayerTime is a class that displays time.
 *
 * EXAMPLE
 * <code>
 *  VappHsWidgetAudplayerTime *time;
 *  VFX_OBJ_CREATE(time, VappHsWidgetAudplayerTime, this);
 *  time->setPos(VfxPoint(0, 0));
 * </code>
 */
class VappHsWidgetAudplayerTime : public VfxImageFrame
{
    VFX_DECLARE_CLASS(VappHsWidgetAudplayerTime);

// Constructor / Destructor     
public:
    // Default constructor
    VappHsWidgetAudplayerTime();

    // Destructor
    virtual ~VappHsWidgetAudplayerTime();

// Method
public:
    // Set the time to display
    void setTime(
        VfxS32 hour,    // [IN] hour
        VfxS32 min,     // [IN] min
        VfxS32 sec      // [IN] sec
    );

    // Set the time to display    
    void setTime(
        VfxU64 msec     // [IN] ms
    );

    // Get the time of display 
    void getTime(
        VfxS32* hourP,  // [OUT] hour
        VfxS32* minP,   // [OUT] min
        VfxS32* secP    // [OUT] sec
    );

// Override    
private:
    // On init
    virtual void onInit();

    // On Deinit
    virtual void onDeinit();

// Variable    
private:
    // Tens place of hour image frame
    VfxImageFrame *m_imageH1;

    // Ones place of hour image frame
    VfxImageFrame *m_imageH2;

    // Tens place of min image frame
    VfxImageFrame *m_imageM1;

    // Ones place of min image frame
    VfxImageFrame *m_imageM2;

    // Tens place of sec image frame
    VfxImageFrame *m_imageS1;

    // Ones place of sec image frame
    VfxImageFrame *m_imageS2;

    // Colon 1 image frame
    VfxImageFrame *m_imageColon_1;

    // Colon 2 image frame
    VfxImageFrame *m_imageColon_2;

    // Number 0 image resouce ID
    VfxS32 m_imageNum0Id;

    // Number 1 image resouce ID
    VfxS32 m_imageNum1Id;

    // Number 2 image resouce ID
    VfxS32 m_imageNum2Id;

    // Number 3 image resouce ID
    VfxS32 m_imageNum3Id;

    // Number 4 image resouce ID
    VfxS32 m_imageNum4Id;

    // Number 5 image resouce ID
    VfxS32 m_imageNum5Id;

    // Number 6 image resouce ID
    VfxS32 m_imageNum6Id;

    // Number 7 image resouce ID
    VfxS32 m_imageNum7Id;

    // Number 8 image resouce ID
    VfxS32 m_imageNum8Id;

    // Number 9 image resouce ID
    VfxS32 m_imageNum9Id;

    // Colon image resouce ID
    VfxS32 m_imageColonId;

    // Hour value
    VfxS32 m_hour;

    // Min value
    VfxS32 m_min;

    // Sec value
    VfxS32 m_sec;

// Implementation
private:
    // Layout the position of image frames
    void layout(void);    
};


/***************************************************************************** 
 * Class VappHsWidgetAudplayer
 *****************************************************************************/

/*
 * VappHsWidgetAudplayer is a class that creates an audio player widget.
 *
 * EXAMPLE
 * <code>
 *  VappHsWidgetAudplayer *audplayer;
 *  VFX_OBJ_CREATE(audplayer, VappHsWidgetAudplayerTime, this);
 * </code>
 */
class VappHsWidgetAudplayer : public VappHsWidget
{
    VAPP_HS_WIDGET_CREATE(VappHsWidgetAudplayer);
    
// Declaration
private:
    // The title position
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        TITLE_START_OFFSET_X     = 11,       // The start offset x
        TITLE_START_OFFSET_Y     = 8,       // The start offset y
    #else
        TITLE_START_OFFSET_X     = 9,       // The start offset x
        TITLE_START_OFFSET_Y     = 8,       // The start offset y
    #endif

    #if defined(__MMI_MAINLCD_320X480__)
        TITLE_END_OFFSET_X       = 247,     // The end offset x
        TITLE_END_OFFSET_Y       = 38,       // The end offset y
    #else
        TITLE_END_OFFSET_X       = 180,     // The end offset x
        TITLE_END_OFFSET_Y       = 28,       // The end offset y
    #endif

    #if defined(__MMI_MAINLCD_320X480__)
        PROGRESS_BAR_OFFSET_X       = 8,
        PROGRESS_BAR_OFFSET_Y       = 43,
    #else
        PROGRESS_BAR_OFFSET_X       = 8,
        PROGRESS_BAR_OFFSET_Y       = 29,
    #endif
    
    #if defined(__MMI_MAINLCD_320X480__)
        BUTTON_PREV_OFFSET_X     = 5,
        BUTTON_PREV_OFFSET_Y     = 52,
    #else
        BUTTON_PREV_OFFSET_X     = 6,
        BUTTON_PREV_OFFSET_Y     = 35,
    #endif    

    #if defined(__MMI_MAINLCD_320X480__)
        BUTTON_PLAY_OFFSET_X     = 68,
        BUTTON_PLAY_OFFSET_Y     = 52,
    #else
        BUTTON_PLAY_OFFSET_X     = 51,
        BUTTON_PLAY_OFFSET_Y     = 35,
    #endif

    #if defined(__MMI_MAINLCD_320X480__)
        BUTTON_PAUSE_OFFSET_X    = 68,
        BUTTON_PAUSE_OFFSET_Y    = 52,
    #else
        BUTTON_PAUSE_OFFSET_X    = 51,
        BUTTON_PAUSE_OFFSET_Y    = 35,
    #endif
    
    #if defined(__MMI_MAINLCD_320X480__)
        BUTTON_NEXT_OFFSET_X     = 131,
        BUTTON_NEXT_OFFSET_Y     = 52,
    #else
        BUTTON_NEXT_OFFSET_X     = 96,
        BUTTON_NEXT_OFFSET_Y     = 35,
    #endif

    #if defined(__MMI_MAINLCD_320X480__)
        BUTTON_STOP_OFFSET_X     = 194,
        BUTTON_STOP_OFFSET_Y     = 52,
    #else
        BUTTON_STOP_OFFSET_X     = 141,
        BUTTON_STOP_OFFSET_Y     = 35,
    #endif    
    };

    // The state of audio player widget
    enum
    {
        STATE_INIT = VAPP_WIDGET_AUDPLAYER_STATE_INIT,          // Init
        STATE_PLAY = VAPP_WIDGET_AUDPLAYER_STATE_PLAY,          // Playing
        STATE_PROCESS = VAPP_WIDGET_AUDPLAYER_STATE_PROCESS     // Processing
    };

// Constructor / Destructor    
public:
    // Default constructor
    VappHsWidgetAudplayer();

// Override
public:    
    // Get icon
    virtual VfxU16 getIcon();

    // Get name
    virtual VfxU16 getName();

    // Create the whole widget content
    virtual void onCreateView();

    // Release the whole widget content
    virtual void onReleaseView();

private:
    // On Init
    virtual void onInit();

    // On Deinit
    virtual void onDeinit();

    // On pen input
    // RETURNS: VfxBool     
    virtual VfxBool onPenInput(
        VfxPenEvent &event
    );

    // On DirectLunch
    virtual void onDirectLaunch();
    
// Variable
private:
    // Text frame
    VcpMarquee *m_marqueeText;

    // Background image
    VfxImageFrame *m_imageBg;

    // Current string content
    VfxWString m_curr_show_title;

    // Polling timer
    VfxTimer *m_timer;

    // Progress bar
    VappHsWidgetAudplayerProgress *m_progress;

    // Previous button
    VappHsWidgetAudplayerButton *m_butPrev;

    // Play button
    VappHsWidgetAudplayerButton *m_butPlay;

    // Pause button
    VappHsWidgetAudplayerButton *m_butPause;

    // Next button
    VappHsWidgetAudplayerButton *m_butNext;

    // Stop button
    VappHsWidgetAudplayerButton *m_butStop;

    // Duration
    VfxU64 m_durationMsec;

    // Current time
    VfxU64 m_currTimeMsec;

    // State
    VfxS32 m_state;
    
    // Title string
    VfxChar m_title[(SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * 2];

    // Timer flag
    VfxBool m_isTimerStart;

    // Flag of rescrolling text
    VfxBool m_isRescrollText;

    // Playlist flag
    VfxBool m_isReady;
    
// Implementation
public: 
    // Callback from plutommi audio/media player application
    static void audplayerCallback(
        void* userdata,     // [IN] userdata 
        VfxU32 type,        // [IN] callback type
        void* resultP       // [IN] information
    );

private:
    
    void launchApp();
    
private:
    // Button up handle function
    void onButtonUp(
        VfxObjWeakPtr this_ptr
    );

    // Play button down handle function
    // RETURNS: void
    void onPlayDown(
        VfxPenEvent &event  // [IN] pen event
    );

    // Pause button down handle function
    // RETURNS: void
    void onPauseDown(
        VfxPenEvent &event  // [IN] pen event
    );

    // Stop button down handle function
    // RETURNS: void    
    void onStopDown(
        VfxPenEvent &event  // [IN] pen event
    );

    // Prev button down handle function
    // RETURNS: void    
    void onPrevDown(
        VfxPenEvent &event  // [IN] pen event
    );

    // Next button down handle function
    // RETURNS: void    
    void onNextDown(
        VfxPenEvent &event  // [IN] pen event
    );

    // Play button up handle function
    // RETURNS: void    
    void onPlayUp(
        VfxPenEvent &event  // [IN] pen event
    );

    // Pause button up handle function
    // RETURNS: void     
    void onPauseUp(
        VfxPenEvent &event  // [IN] pen event
    );

    // Stop button up handle function
    // RETURNS: void     
    void onStopUp(
        VfxPenEvent &event  // [IN] pen event
    );

    // Prev button up handle function
    // RETURNS: void     
    void onPrevUp(
        VfxPenEvent &event  // [IN] pen event
    );

    // Next button up handle function
    // RETURNS: void     
    void onNextUp(
        VfxPenEvent &event  // [IN] pen event
    );

    // Status change notification function
    // RETURNS: void
    void onStatusChanged(
        void* resultP       // [IN] information
    );

    // Media change notification function
    // RETURNS: void    
    void onMediaChanged(
        void* resultP       // [IN] information
    );

    // Play end notification function
    // RETURNS: void     
    void onPlayEnd(
        void* resultP       // [IN] information
    );

    void onResetTime(
        void* resultP       // [IN] information
    );
    
    // Update widget UI
    // RETURNS: void 
    void update(void);

    // Get the state of application
    void getState(void);

    // Get the duration of current media file
    // RETURNS: duration
    VfxU64 getDuration(void);

    // Get the play time of current media file
    // RETURNS: play time
    VfxU64 getCurrTime(void);

    // Get the string of current media file
    // RETURNS: string    
    VfxChar* getTitle();

    // Set current progress bar ratio
    void setCurrentProgress(void);

    // Start polling timer
    void startGetCurrtimeTimer(void);

    // Stop polling timer
    void stopGetCurrtimeTimer(void);

    // Timer callback
    void onTimerTick(
        VfxTimer *source    // [IN] timer
    );
    
};

#endif /* __MMI_VUI_HOMESCREEN_AUDIO_PLAYER__ */
#endif /* __VAPP_HS_WIDGET_AUDPLAYER_H__ */
