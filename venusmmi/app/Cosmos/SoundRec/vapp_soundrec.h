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
 *  vapp_soundrecorder.h
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SOUNDRECORDER_H__
#define __VAPP_SOUNDRECORDER_H__

#define __MMI_SOUNDREC_GESTURE_CUT_DOWN__

#if !defined(__LOW_COST_SUPPORT_COMMON__)
    #undef __MMI_SOUNDREC_GESTURE_CUT_DOWN__
#endif

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

#include "vcp_Form.h"
#include "vcp_list_menu.h"
#include "vcp_menu_popup.h"

#include "../filemgr/Vapp_fmgr_cp.h"

#include "vapp_sound_settings_gprot.h"

/* Pluto MMI headers */
#ifdef __cplusplus
extern "C"
{
#endif
#include "mdi_datatype.h"
#include "FileMgrSrvGProt.h"
#include "custom_mmi_folders_config.h"
#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_SNDREC_FOLDER_LEN ((sizeof(RECORD_DOWNLOAD_FOLDER_NAME)/2) + 3)   /* "C:\Record\" not include null terminator */
//#define VAPP_SNDREC_FOLDER L"\\Record\\"

#define VAPP_SNDREC_FILENAME_LEN 18 /* "Recording_1000.amr" not include null terminator */
//#define VAPP_SNDREC_FILENAME_PREFIX L"Recording_"

#define VAPP_SNDREC_FILEPATH_LEN (VAPP_SNDREC_FOLDER_LEN + VAPP_SNDREC_FILENAME_LEN)

#define VAPP_SNDREC_MAX_SEQUENCE 999 /* Max file sequence */
#define VAPP_SNDREC_FIND_SEQ_RANGE 20 /* Number of file names check at one function call */

#ifdef __MMI_MAINLCD_480X800__
#define VAPP_SNDREC_FONT_REC_LARGE (85)
#define VAPP_SNDREC_FONT_REC_SMALL (22)
#define VAPP_SNDREC_FONT_PLAY_LARGE (52)
#define VAPP_SNDREC_FONT_PLAY_SMALL (52)
#define VAPP_SNDREC_FONT_PLAY_SLASH (42)
#define VAPP_SNDREC_FONT_CASETTE_TITLE (26)
#elif defined(__MMI_MAINLCD_240X320__)
#define VAPP_SNDREC_FONT_REC_LARGE (22)
#define VAPP_SNDREC_FONT_REC_SMALL (12)
#define VAPP_SNDREC_FONT_PLAY_LARGE (12)
#define VAPP_SNDREC_FONT_PLAY_SMALL (12)
#define VAPP_SNDREC_FONT_PLAY_SLASH (12)
#define VAPP_SNDREC_FONT_CASETTE_TITLE (12)
#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_SNDREC_FONT_REC_LARGE (42)
#define VAPP_SNDREC_FONT_REC_SMALL (12)
#define VAPP_SNDREC_FONT_PLAY_LARGE (24)
#define VAPP_SNDREC_FONT_PLAY_SMALL (24)
#define VAPP_SNDREC_FONT_PLAY_SLASH (24)
#define VAPP_SNDREC_FONT_CASETTE_TITLE (12)
#else /* 320x480*/
#define VAPP_SNDREC_FONT_REC_LARGE (52)
#define VAPP_SNDREC_FONT_REC_SMALL (14)
#define VAPP_SNDREC_FONT_PLAY_LARGE (32)
#define VAPP_SNDREC_FONT_PLAY_SMALL (32)
#define VAPP_SNDREC_FONT_PLAY_SLASH (26)
#define VAPP_SNDREC_FONT_CASETTE_TITLE (18)
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct
{
    int ret;
    VfxU64 disk_size;
}vapp_soundrec_check_size_result;

/***************************************************************************** 
 * Class 
 *****************************************************************************/


/***************************************************************************** 
 * Class VappSoundRecorderFileList
 *****************************************************************************/
class VappSoundRecorderFileList : public VfxObject
{
public:
    VappSoundRecorderFileList();
    virtual ~VappSoundRecorderFileList();

    /* Public functions */
    void onLoadedCallback(mmi_event_struct *param);
    VfxS32 createList(mmi_ret (*callback)(mmi_event_struct *param), void* user_data);
    void closeList(void);
    VfxBool needReload(void);
    VfxS32 getCurrentIndex(void);
    VfxU16 setCurrentIndex(VfxS32 index);
    VfxU16 setCurrentIndexFromFile(VfxWChar *rec_filename);
    void setDirty(void);
    void setStorageChange(void);
    VfxBool getCurrentFile(VfxWChar *filename, VfxU16 buffer_size);
    VfxBool getNextFile(VfxWChar *filename, VfxU16 buffer_size, VfxBool is_next);
    VfxBool isFirstFile(void);
    VfxBool isLastFile(void);
    VfxBool isNextExceedBoundary(VfxBool is_next);
    VfxBool isLoading(void);
    VfxS32 getCount(void);

    /* Public variables */
    SRV_FMGR_FILELIST_HANDLE m_fl_hdl;

private:
    VfxS32 m_fl_index;
    VfxS32 m_fl_total;
    void *m_fl_buf;
    VfxBool m_fl_need_refresh;
    VfxBool m_fl_storage_change;

};

/***************************************************************************** 
 * Class VappSoundRecorderScreen
 *****************************************************************************/
class VappSoundRecorderScreen : public VfxMainScr
{
// Override
public:
    virtual void on1stReady();
    void notifyTopPage(mmi_event_struct *evt);
};

/***************************************************************************** 
 * Class VappSoundRecorderApp
 *****************************************************************************/
class VappSoundRecorderApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappSoundRecorderApp);

public:
    /* Override */
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onInit();
    virtual void onDeinit();

    static mmi_ret eventHandler(mmi_event_struct *param);

    /* Public Variables */
    VappSoundRecorderFileList *m_file_list;

private:
    VappSoundRecorderScreen *scr;
};

#ifndef __MMI_SOUNDREC_GESTURE_CUT_DOWN__
/***************************************************************************** 
 * Class VappSoundRecorderGestureTranslator
 *****************************************************************************/
enum VappSoundRecorderGesture
{
    VG_NONE,        // no gesture or not recognized
    VG_TAP,         // user taps
    VG_DOUBLE_TAP,  // user double taps
    VG_DRAG,        // user drags around
    VG_DRAG_END,    // continue sliding after user drag endes
    VG_GO_PREV,     // user fast swipe to go previous
    VG_GO_NEXT      // user fast swipe to go next
};

class VappSoundRecorderGestureTranslator : public VfxObject
{
public:
    VappSoundRecorderGestureTranslator();
    virtual void onInit();
    
public:
    // Client should feed pen event and itself with this function
    void processPenEvent(VfxFrame *component, const VfxPenEvent &evt);
    // Retrieve last pen event fed to the translator
    const VfxPenEvent& getLastPenEvent();
    // signal invoked when a gesture is recognized
    VfxSignal2<VappSoundRecorderGestureTranslator*,   // sender object
               VappSoundRecorderGesture>             // gesture recognized
               m_signalGestureRecognized;

protected:
    void onTapTimer(VfxTimer *sender);
    
private:
    static const VfxMsec DOUBLE_TAP_INTERVAL = 400;
    static const VfxMsec MSEC_PER_SEC = 1000;
    // we track movement by ourselves,
    // because VfxPenEvent may have exactly the same prevPos,
    // which breaks the swipe detection.
    VfxMsec m_prevTimeStamp;
    VfxS32 m_prevX;
    VfxBool m_draggingMode;
    VfxBool m_delayedTap;       // VFX_TRUE if a VG_TAP is recognized but haven't sent
    VfxTimer *m_tapTimer;       // delay timer. because we want to distinguish tap from double-tap
    VfxPenEvent m_lastPenEvent; // last pen event received
};
#endif

/***************************************************************************** 
 * Class VappSoundRecorderCassetteFrame
 *****************************************************************************/
class VappSoundRecorderCassetteFrame : public VfxControl
{
public:
    VappSoundRecorderCassetteFrame();
    /* Override */
    virtual void onInit();
    virtual void onDeinit();
#ifndef __MMI_SOUNDREC_GESTURE_CUT_DOWN__
    virtual VfxBool onPenInput(VfxPenEvent &event);
#endif

    /* Public functions */
    void setDisplayName(const VfxWString &value);
    void setTotalTime(VfxU64 total_time);
    void setCurrentTime(VfxU64 current_time);
    void startRotate(void);
    void stopRotate(void);
    void startMoveOut(VfxBool is_next);
    void startMoveOutDone(VfxBaseTimeline *timeline, VfxBool stopped);
    void startMoveIn(VfxS32 start_pos_x);
    void startMoveInDone(VfxBaseTimeline *timeline, VfxBool stopped);

#ifndef __MMI_SOUNDREC_GESTURE_CUT_DOWN__
public:
    // signal invoked when a gesture is recognized
    VfxSignal1<VappSoundRecorderGesture> m_signalGestureRecognized;
#endif

private:
    #define SNDREC_MIN_TAPE_SCALE (0.5f)
    #define SNDREC_INIT_ROLLER_ANGLE (60)

    /* Private functions */
    void updateTapeScale(void);
#ifndef __MMI_SOUNDREC_GESTURE_CUT_DOWN__
    void onGesture(VappSoundRecorderGestureTranslator *sender, VappSoundRecorderGesture gesture);
#endif

    /* Component */
    VfxImageFrame *m_image_cassette;
    VfxImageFrame *m_image_tape_left;
    VfxImageFrame *m_image_tape_right;
    VfxImageFrame *m_image_roll_left_axis;
    VfxImageFrame *m_image_roll_right_axis;
    VfxImageFrame *m_image_roll_left;
    VfxImageFrame *m_image_roll_right;

    VfxTransformTimeline *m_timeline_rotate_left;
    VfxTransformTimeline *m_timeline_rotate_right;

    VfxTextFrame *m_text_displayname;
    
#ifndef __MMI_SOUNDREC_GESTURE_CUT_DOWN__
    VappSoundRecorderGestureTranslator *m_gesture_trans;
#endif

    /* Variables */
    VfxU64 m_total_time;
    VfxU64 m_current_time;
    VfxBool m_is_first_rotate;
};



/***************************************************************************** 
 * Class VappSoundRecorderRecordPage
 *****************************************************************************/
class VappSoundRecorderRecordPage : public VfxPage
{
public:
    typedef enum
    {
        RECORD_MODE_NONE = 0,
        RECORD_MODE_APP =       0x01, /* Application mode */
#ifdef __MMI_SOUNDREC_CUI__        
        RECORD_MODE_CUI =       0x02, /* CUI mode, not enter list */
        RECORD_MODE_CUI_NO_PREVIEW =    0x04,  /* After record, not enter playback screen, return directly */
        RECORD_MODE_CUI_NO_PAUSE =          0x08,  /* No pause function */
        RECORD_MODE_CUI_DISPLAY_REC_LIMIT = 0x10,   /* Display record limit time instread of max available time */        
#endif

        RECORD_MODE_END
    }vapp_sound_rec_mode_enum;

    enum
    {
        SNDREC_PARAM_SIZE,
        SNDREC_PARAM_TIME,
        SNDREC_PARAM_QUALITY        
    }vapp_sound_rec_param_enum;

    enum
    {
        SNDREC_QUALITY_BY_SETTING,
        SNDREC_QUALITY_NORMAL,
        SNDREC_QUALITY_HIGH
    }vapp_sound_rec_quality_enum;

    
    enum 
    {
    
    #if defined(__MMI_MAINLCD_320X480__)
        POPUP_X = 160,
        POPUP_Y = 230,
    #elif defined(__MMI_MAINLCD_480X800__)
        POPUP_X = 240,
        POPUP_Y = 351,
    #elif defined(__MMI_MAINLCD_240X400__)
        POPUP_X = 120,
        POPUP_Y = 174,
    #else//if defined(__MMI_MAINLCD_240X320__)
        POPUP_X = 120,
        POPUP_Y = 152
    #endif
    };

public:
    VappSoundRecorderRecordPage();
    VappSoundRecorderRecordPage(VfxU8 mode);
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);    
    virtual void onExit(VfxBool isBackward);
    virtual mmi_ret onProc(mmi_event_struct *evt);
    void recordCallbackHdlr(mdi_result result);
    void setRecordParam(VfxU8 param, VfxU32 value);
    void recordErrorHdlr(mdi_result result);
    void onCpopupButtonClicked(VfxObject* sender, VfxId btn);

    static mmi_ret eventHandler(mmi_event_struct *param);

private:
    enum
    {
        SNDREC_STATE_IDLE,
        SNDREC_STATE_RECORD,
        SNDREC_STATE_PAUSE,
        SNDREC_STATE_INTERRUPTED,
        SNDREC_STATE_TOTAL
    };

    enum
    {
        SNDREC_BTN_TOOL_REC_LIST,
    #ifdef __LOW_COST_SUPPORT_COMMON__
        SNDREC_BTN_TOOL_QUALITY,
    #else
        SNDREC_BTN_TOOL_SETTING,
    #endif
        SNDREC_BTN_REC,
        SNDREC_BTN_STOP,

        SNDREC_BTN_TOTAL
    };

    enum
    {
    #ifdef __MTK_TARGET__
        TIMER_UPDATE_CURRENT_TIME = 250,
    #else
        TIMER_UPDATE_CURRENT_TIME = 1000,
    #endif
        TIMER_CHECK_REMAIN_TIME = 1000,
        TIMER_FIND_NAME = 200
    };

    /* Private functions */
    void onButtonClicked(VfxObject* obj, VfxId id);
    void onUpdateTimerExpir(VfxTimer *timer);
    void onCheckRemainTimerExpir(VfxTimer *timer);
    void onErrorCheckTimerExpir(VfxTimer *timer);
    void onFindPathTimerExpir(VfxTimer *timer);

    void createScreenComponent(void);
    VfxU64 updateRemainTimeText(VfxBool forceUpdate);
    VfxU64 updateFreeSpaceTimeText(VfxBool forceUpdate);
    VfxU64 updateLimitTimeText(VfxBool forceUpdate);
    void updateRecButtonState(VfxBool is_pause);
    void updateTimeText(VfxTextFrame *text, VfxU64 display_time);

    VfxBool findRecordPath(void);
    VfxBool findRecordPathLoop(void);
    void recordStart(void);
    void recordPause(void);
    void recordResume(void);
    void recordStop(VfxBool is_finish);

    void stopRecordAndExit(VfxBool user_stop);

    void showConfirmPopup(const VfxWString &text);
#ifndef __LOW_COST_SUPPORT_COMMON__
    void showDefaultStoragePopup(void);
    void onDefaultStorageConfirm(VfxObject* vfx_obj, VfxId id);
#endif

#ifdef __LOW_COST_SUPPORT_COMMON__
    void onQualitySelectNewItem(VfxS32 itemId, VfxS32 subItemId);
#endif

    void showLoading(void);
    void stopLoading(void);

private:
    /* Private screen components */
    VcpToolBar *toolbar;

    VfxTextFrame *m_text_record_time;
    VfxTextFrame *m_text_remain_time;

    VcpConfirmPopup *m_confirmPopup;

    VfxColor m_text_remain_time_color;

    VcpButton *m_image_btn_rec;
    VcpButton *m_image_btn_stop;

    VfxTimer *m_timer_update;
    VfxTimer *m_timer_check_remain;
    VfxTimer *m_timer_error_check;
    VfxTimer *m_timer_find_name;

    VcpActivityIndicator *m_indicator;

    VappSoundRecorderCassetteFrame *m_frame_cassette;
    VappSoundRecorderFileList *m_file_list;

    /* Private variables */
    VfxU8 m_mode;
    VfxU8 m_state;
    VfxU32 m_specify_quality; // If specify record quality by CUI
    VfxU16 m_stop_seq;
    VfxU16 m_last_seq;
    VfxU32 m_record_time_limit;
    VfxU32 m_record_size_limit;    
    VfxU64 m_current_time;
    VfxU64 m_accumulate_time; /* To keep total time for interrupt case */
    VfxU64 m_check_remain_timer_dur;
    VfxU64 m_last_update_remain_time;
    
    VfxWChar m_record_path[VAPP_SNDREC_FILEPATH_LEN + 1];
};


/***************************************************************************** 
 * Class VappSoundRecorderPlayPage
 *****************************************************************************/
class VappSoundRecorderPlayPage : public VfxPage
{

public:
    typedef enum
    {
        PLAYBACK_MODE_APP,
#ifdef __MMI_SOUNDREC_CUI__        
        PLAYBACK_MODE_CUI,
#endif
        PLAYBACK_MODE_END
    }vapp_sound_play_mode_enum;

private:
    enum
    {
        SNDREC_STATE_IDLE,
        SNDREC_STATE_STOP,
        SNDREC_STATE_PLAY,
        SNDREC_STATE_PAUSE,
        SNDREC_STATE_TOTAL
    };

    enum
    {
        SNDREC_SEEK_IDLE,
        SNDREC_SEEK_SEEKING,
        SNDREC_SEEK_STOP,
        SNDREC_SEEK_TOTAL
    };

    enum
    {
        /* For Control button */
        SNDREC_BTN_PLAY,
        SNDREC_BTN_PREV,
        SNDREC_BTN_NEXT,

        /* For App toobar */
        SNDREC_BTN_TOOL_NEW_RECORD,
        SNDREC_BTN_TOOL_DELETE,
        SNDREC_BTN_TOOL_RENAME,
    
    #ifdef __MMI_SET_AS_RINGTONE_POPUP__
        SNDREC_BTN_TOOL_SET_AS,
    #endif
        SNDREC_BTN_TOOL_SHARE,
#ifdef __MMI_SOUNDREC_CUI__        
        /* For CUI toolbar */
        SNDREC_BTN_TOOL_RE_RECORD,
        SNDREC_BTN_TOOL_INSERT,
        SNDREC_BTN_TOOL_CANCEL,
#endif
        SNDREC_BTN_TOTAL
    };

    enum
    {
        OPTION_SHARE_MMS,
        OPTION_SHARE_EMAIL,
        OPTION_SHARE_BLUETOOTH,
        OPTION_MENU_ID_CANCEL
    };

    enum
    {
        TIMER_PLAY_NEXT = 400,
        TIMER_UPDATE_DUR_FASTEST = 50,
        TIMER_UPDATE_DUR_FAST = 100,
        TIMER_UPDATE_DUR_NORMAL = 300,
        TIMER_EOF = 100
    };

    enum
    {
        UPDATE_DURATION_FAST = 3000,
        UPDATE_DURATION_NORMAL = 20000
    };

    enum 
    {

    #if defined(__MMI_MAINLCD_320X480__)
        POPUP_X = 160,
        POPUP_Y = 230,
        TEXT_X_GAP = 7
    #elif defined(__MMI_MAINLCD_480X800__)
        POPUP_X = 240,
        POPUP_Y = 351,
        TEXT_X_GAP = 12
    #elif defined(__MMI_MAINLCD_240X400__)
        POPUP_X = 120,
        POPUP_Y = 174,
        TEXT_X_GAP = 3
    #else//if defined(__MMI_MAINLCD_240X320__)
        POPUP_X = 120,
        POPUP_Y = 152
    #endif
    };

public:
    VappSoundRecorderPlayPage();
    VappSoundRecorderPlayPage(const VfxWString &file_path, vapp_sound_play_mode_enum mode, VfxBool auto_play);
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);
    virtual mmi_ret onProc(mmi_event_struct *evt);
    static mmi_ret onStaticProc(mmi_event_struct *evt);

    // Start play according to state
    void playReq(void);
    // Play callback handler
    void playCallbackHdlr(kal_int32 result);
    void seekCallbackHdlr(kal_int32 result);
    // Open File
    void playOpen(void);
    // Start play
    void playStart(void);
    // Stop play
    void playStop(void);
    // Pause play
    void playPause(VfxTimer *timer);
    // Resume play
    void playResume(VfxTimer *timer);
    // Close play
    void playClose(void);

    static mmi_ret onListLoadedCallback(mmi_event_struct *param);
    
    static mmi_ret onDeleteFileCallback(mmi_event_struct *param);

private:
    /* Private functions */
    void onButtonClicked(VfxObject* obj, VfxId id);
#ifndef __MMI_SOUNDREC_GESTURE_CUT_DOWN__
    void onGesture(VappSoundRecorderGesture gesture);
#endif
    void onAppToolbarButtonClicked(VfxObject* obj, VfxId id);
#ifdef __MMI_SOUNDREC_CUI__        
    void onCuiToolbarButtonClicked(VfxObject* obj, VfxId id);
#endif
    void onSliderPressed(VcpSlider* slider, VfxFloat val);
    void onSliderValueChange(VcpSlider* slider, VfxFloat val);
    void onSliderReleased(VcpSlider* slider, VfxFloat val);    
    void onUpdateTimerExpir(VfxTimer *timer);
    void onPlayNextTimerExpir(VfxTimer *timer);
    void onEOFTimerExpir(VfxTimer *timer);
    void onSeekTimerExpir(VfxTimer *timer);

    void createScreenComponent(void);
    void updatePlayButtonState(VfxBool show_pause);
    void updateTimeText(VfxTextFrame *text, VfxU64 display_time);
    void updateCurrentTime(void);
    void updateDuration(void);
    void showChangeTapeAnimate(void);
    void updateEndTime(VfxTimer *timer);

    void playNext(void);
    void pickNext(void);
    void seekStart(void);
    void seekStop(void);
    void showCurrentFile(VfxBool is_animate);
    void loadList(VfxBool need_find_index, VfxBool pick_next, VfxBool is_animate);
    void findCurrentFileIndex(void);
    void showLoading(void);
    void stopLoading(void);

    void showErrorConfirm(const VfxWString &text, VfxBool exit_page);
    void onErrorConfirmClicked(VfxObject* vfx_obj, VfxId id);
    void deleteFilePopup(void);
    void onDeleteFileClicked(VfxObject* vfx_obj, VfxId id);
    void renameFilePopup(void);
    void onRenameFileClicked(VfxObject* sender, VcpInputPopupButtonEnum id);
    void shareFilePopup(void);
    void onShareFileClicked(VfxObject* sender, VfxId buttonId);
    void launchSetRingtone(void);
    void launchUnifiedComposer(void);
    void launchBluetooth(void);
    void launchEmail(void);

public:
    VfxSignal0 m_playPageListChange;
    U8 *m_cacheTable;
    
private:
    /* Private screen components */
    VcpToolBar *toolbar;

    VcpButton *m_image_btn_play;
    VcpButton *m_image_btn_prev;
    VcpButton *m_image_btn_next; 

    VfxTextFrame *m_text_current_time;
    VfxTextFrame *m_text_duration;
    VfxTextFrame *m_text_slash;
	VfxTextFrame *m_text_total_time;

    VcpSlider *m_slider_progress;
    VfxTimer *m_timer_update;
    VfxTimer *m_timer_play_next;
    VfxTimer *m_timer_eof;
    VfxTimer *m_timer_seek;
	VfxTimer *m_timer_endfile_time_update;
    VfxTimer *m_timer_play_manager;
    VfxTimer *m_timer_pause_manager;

    VappSoundRecorderCassetteFrame *m_frame_cassette;
    VcpActivityIndicator *m_indicator;

    VcpConfirmPopup *m_delete_popup;
    VappFileNameEditorPopup *m_rename_popup;

    VfxWString m_filepath; /* init at constructor */
    VappSoundRecorderFileList *m_file_list;

#ifdef __MMI_SET_AS_RINGTONE_POPUP__
    VappSetAsRingToneCommandPopup *m_set_as_ring_tone_popup;
#endif

    /* Private variables */
    VfxU8 m_mode;
    VfxU8 m_state;
    VfxU8 m_prev_state;
    VfxU8 m_seek_state;
    VfxU32 m_display_hour;
    VfxBool m_is_next;
    VfxBool m_is_slider_pressed;
    VfxBool m_load_find_index;
    VfxBool m_load_pick_next;
    VfxBool m_load_show_animate;
    VfxBool m_auto_play;
    VfxBool m_reset_seek_state;
    VfxU32 m_current_time;
    VfxU32 m_duration;
    VfxPoint m_cassette_pos;
};
   

/***************************************************************************** 
 * Class VappSoundRecorderSettingPage
 *****************************************************************************/

#ifndef __LOW_COST_SUPPORT_COMMON__
class VappSoundRecorderSettingPage : public VfxPage
{
public:
    virtual void onInit();
	void onItemTapped(VcpFormItemCell* sender, VfxId Id);
	void onSelectNewItem(VfxS32 itemId, VfxS32 subItemId);

private:

    VcpForm *m_form;
    VcpFormItemLauncherCell *m_setting[2];

    VfxS32 m_radioSelectIndex1;
    VfxS32 m_radioSelectIndex2;

};

#endif

/***************************************************************************** 
 * Class VappSoundRecorderListPage
 *****************************************************************************/
class VappSoundRecorderListPage : public VfxPage, public IVcpListMenuContentProvider
{
    
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);
    virtual void onBack();
    virtual mmi_ret onProc(mmi_event_struct *evt);

    static mmi_ret onListLoadedCallback(mmi_event_struct *param);
    static mmi_ret onListDeleteCallback(mmi_event_struct *param);
    static mmi_ret onLongTapDeleteCallback(mmi_event_struct *param);


private:
    enum
    {
        LIST_MODE_BROWSE,
        LIST_MODE_DELETE
    };

    enum
    {
        TOOLBAR_SELECT_ALL,
        TOOLBAR_DELETE,
        TOOLBAR_CANCEL
    };

    enum
    {
        LTAP_DELETE,
        LTAP_RENAME
    };

private:
    /* Private functions */
    void onListModeButtonClicked(VfxObject* obj, VfxId id);
    void onDeleteModeButtonClicked(VfxObject* obj, VfxId id);    
    void onListItemTapped(VcpListMenu *menu, VfxU32 index);
    void onListItemLongTapped(VcpListMenu *menu, VfxU32 index);    
    void onListItemLongTappedOptionCallback(VcpMenuPopup* menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item);
    void onListSelectionChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState);
    void onListMarkAll(VfxBool reload_list);
    void onPlayPageListChanged(void);

    void showMultiDeleteConfirm(void);
    void onMultiDeleteClicked(VfxObject* vfx_obj, VfxId id);
    void showMultiDeleteProcessing(void);
    void stopMultiDeleteProcessing(void);
    void onMultiDeleteCancel(VfxObject* obj, VfxFloat processing);

    void showLongTapDeleteConfirm(void);
    void onLongTapDeleteClicked(VfxObject* vfx_obj, VfxId id);
    void showLongTapRenamePopup(void);
    void onLongTapRenameClicked(VfxObject* sender, VcpInputPopupButtonEnum id);
    void showListErrorConfirm(const VfxWString &text, VfxBool exit_page);
    void onListErrorClicked(VfxObject* vfx_obj, VfxId id);
    VfxBool showFileListMenu(void);

    VfxBool deleteFileAsync(void);
    void loadFileListMenu(void);
    void setToolBarMode(VfxU8 mode);
    void changeListMode(VfxU8 mode);

    void showLoading(void);
    void stopLoading(void);

    /* IVcpListMenuContentProvider */
    virtual VfxBool getItemText(
        VfxU32 index,                   
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,        
        VcpListMenuTextColorEnum &color);
    virtual VfxU32 getCount(void) const;
    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index) const;
    virtual VfxBool getMenuEmptyText(
        VfxWString &text,
        VcpListMenuTextColorEnum &color
        );

    /* Private componenets */
    VcpTitleBar *m_bar;
    VcpToolBar *m_toolbar_delete;    
    VcpListMenu *m_list_menu;
    VcpActivityIndicator *m_indicator;
    VcpIndicatorPopup *m_deleting_popup;    

    VappSoundRecorderFileList *m_file_list;

    /* Private variables */
    VfxU8 m_mode;
    VfxBool m_delete_abort;
    VfxBool m_show_select_all;
    VfxBool m_list_need_refresh;
    VfxBool m_is_backward;
    VfxBool m_play_page_change_list;
    VfxBool *m_select_state;
    VfxS32 m_next_del_index;
    VfxU32 m_select_num;
    VfxU32 m_long_tap_index;
    VfxS32 m_fmgr_job_id; // For async delete job id

};

#endif /* __VAPP_SOUNDRECORDER_H__ */

