
#ifndef VAPP_SCREEN_LOCK_RHYTHM_H
#define VAPP_SCREEN_LOCK_RHYTHM_H

#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_FACTORY__) && defined(__MMI_VUI_SCREEN_LOCK_RHYTHM__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_screen_lock_base.h"
#include "vapp_wallpaper.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VAPP_SCREEN_LOCK_RHYTHM_BACKLIGHT_OFF_TIME                8


/*****************************************************************************
 * Screen Lock Painting Class
 *****************************************************************************/

/*
 * Screen Lock Painting Class
 */
class VappScreenLockRhythmUnlockPanel;

class VappScreenLockRhythmIndicatorPanel;

class VappScreenLockRhythmIndicatorCell;

class VappScreenLockRhythm : public VappScreenLock
{
    VAPP_SCREEN_LOCK_DECLARE_CLASS(VappScreenLockRhythm);

// Constructor / Destructor
public:
    // Default constructor
    VappScreenLockRhythm();

// Override
public:
    virtual VappScreenLockId getId() const;

    // This function gets the number of the screenshots.
    // RETURNS: Number of screenshots.
    virtual VfxS32 getScreenshotNum() const;

    // This function creates the screenshots.
    // RETURNS: Array of the screenshots.
    virtual VfxFrame **createScreenshot(
        VfxObject *parent           // [IN] Parent of the screenshots
    ) const;

    virtual VfxS32 getName(
        VfxWChar *string,            // [OUT] String buffer
        VfxS32 size                 // [IN] Buffer size in wchar
    ) const;

    virtual VfxFrame *createIcon(
        VfxObject *parentObj        // [IN] Parent object
    );

    static mmi_ret eventHandler(mmi_event_struct *event);

    static vrt_render_dirty_type_enum fpeUnlock(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size);

    static vrt_render_dirty_type_enum fpeBounce(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size);
    
// Override
protected:
    virtual void onCreateView();
    
    virtual void onReleaseView();
    
    virtual void onPageEnter();
    
    virtual void onPageExit();
    
    virtual VfxResId onGetStatusBarBg();
    
    virtual VfxBool onGetStatusBarTranslucent();
    
    virtual VfxBool onPenInput(VfxPenEvent &event);

    virtual void onBacklightOn();

    virtual void onBacklightOff();
    
// Method
private:
    void onUnlockHandler(VfxObject* sender);

    void onStopAnimHandler();
    
    void initWallpaper();
    
    void createWallpaper();
    
    void releaseWallpaper();
    
    void deinitWallpaper();
    
    void wallpaperUpdatedHdlr();
    
    void initEvent();

    void deinitEvent();

    VfxBool updateUnreadMsg();

    VfxBool updateMissedCall();
    
    VfxU32 getUnreadMsgNum();

    void bounceAnimation(VfxFrame *frame, VfxU32 max_range);

    void checkBounceTimer();

    void bindToPanel();

    void riseUp();

    void onTimelineBounceStopped(VfxBaseTimeline *timeline, VfxBool isCompleted);

    void onTimelineRiseUpStopped(VfxBaseTimeline *timeline, VfxBool isCompleted);

    void onTimerTriggerBounce(VfxTimer *timer);

    //for performance tuning, prevent frame and its child frame from cache.
    void preventAllChildCache(VfxFrame *parent);

// Variable
private:

    VappWallpaper *m_wallpaperTop;    //wallpaper

    VappWallpaper *m_wallpaperBottom;

    VfxFrame *m_wpContainerTop;

    VfxFrame *m_wpContainerBottom;

    VappScreenLockRhythmUnlockPanel *m_unlockPanel;

    VappScreenLockRhythmIndicatorPanel *m_indicatorPanel;

    VfxFloatTimeline *m_tlBounceEffect;

    VfxS32Timeline *m_tlRiseUp;

    VfxTimer *m_timerTriggerBounce;

    VfxBool m_isNeedUpdate;
    
    static const VfxFloat s_degrade[];

    static VfxFloat s_oldTiming;

    static VfxS32 s_currentBounceCount;
};


class VappScreenLockRhythmUnlockPanel : public VfxControl
{

    enum StateEnum
    {
        STATE_NORMAL,                    // normal state
        STATE_PRESSED,                   // pressed state
        STATE_END_OF_ENUM                // end of the enum
    };
// Constructor / Destructor
public:
    // Default constructor
    VappScreenLockRhythmUnlockPanel();


// Override
protected:
    virtual void onInit();   
  
    virtual VfxBool onPenInput(VfxPenEvent &event);

public:    
    void restoreOriginPosition(VfxBool isNoAnimation);

    void playArrow();

    void stopArrow();
    
private:
    void timeUpdate(VfxU32 flag);

    void dismiss();

    void onTimelineStopped(VfxBaseTimeline * timeline,VfxBool isCompleted);

    void onTimerArrowAnimation(VfxTimer *timer);

private:
    VfxFrame *m_dummyFrame;

    VfxImageFrame *m_bg;

    VfxImageFrame *m_arrow[3];

    VfxTextFrame *m_time;

    VfxTextFrame *m_AmPm;
    VfxTextFrame *m_date;

    VfxTimer *m_timerArrowAnimation;

    StateEnum m_state;

    VfxU32 m_counter;

    VfxBool m_isAnim;

    static const VfxFloat s_arrow_opacity[3];
    
public:
    VfxSignal1 <VfxObject*> m_signalUnlock;

    VfxSignal0 m_signalStopAnim;

    VfxSignal0 m_signalCheckTimer;

};


class VappScreenLockRhythmIndicatorPanel : public VfxFrame
{
public:
    enum CellTypeEnum
    {
        CELL_TYPE_UNREAD_MESSAGE,
        CELL_TYPE_MISSED_CALL,
        CELL_TYPE_TOTAL,
        CELL_TYPE_INVALIAD  
    };

public:
    class CellEntry : public VfxBase
    {
        public:
            CellEntry(VfxResId image_id, VfxResId string_id) :
                m_imgId(image_id),
                m_strId(string_id)
            {
            }
        public:
            VfxResId m_imgId;
            VfxResId m_strId;
    };
    
//Constructor/Destructor
public:
    VappScreenLockRhythmIndicatorPanel();

public:
    void updateCell(CellTypeEnum type, VfxU32 num);

    VfxBool isEmpty();

    void restoreOriginPosition();

private:
    void updateLayout();
    
private:

    VappScreenLockRhythmIndicatorCell *m_cell[CELL_TYPE_TOTAL];

    static const CellEntry s_cellTbl[];
    
    VfxU32 m_cellCount;
};


class VappScreenLockRhythmIndicatorCell : public VfxFrame
{
//Constructor/Destructor
public:
    VappScreenLockRhythmIndicatorCell(VfxResId image_id, VfxResId string_id);

public:
    void updateNum(VfxU32 num);

protected:
    void virtual onInit();

private:
    void layout();

private:
    VfxResId m_imgId;
    
    VfxImageFrame *m_img;

    VfxResId m_stringId;
    
    VfxTextFrame *m_text;

    VfxU32 m_num;
};
#endif /* defined(__MMI_VUI_SCREEN_LOCK_FACTORY__) && defined(__MMI_VUI_SCREEN_LOCK_RHYTHM__) */
#endif /* VAPP_SCREEN_LOCK_NEW_H */

