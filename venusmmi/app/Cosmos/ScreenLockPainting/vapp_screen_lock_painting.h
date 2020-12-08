
#ifndef VAPP_SCREEN_LOCK_PAINTING_H
#define VAPP_SCREEN_LOCK_PAINTING_H

#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_FACTORY__) && defined(__MMI_VUI_SCREEN_LOCK_PAINTING__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_screen_lock_base.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VAPP_SCREEN_LOCK_PAINTING_BACKLIGHT_OFF_TIME                8


/*****************************************************************************
 * Screen Lock Painting Class
 *****************************************************************************/

/*
 * Screen Lock Painting Class
 */
class VappScreenLockPaintingTimeArea;

class VappDragonFlyFilter;

class VappScreenLockPainting : public VappScreenLock
{
    VAPP_SCREEN_LOCK_DECLARE_CLASS(VappScreenLockPainting);

// Constructor / Destructor
public:
    // Default constructor
    VappScreenLockPainting();

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
		VfxWChar *string,			// [OUT] String buffer
		VfxS32 size 				// [IN] Buffer size in wchar
	) const;

	virtual VfxFrame *createIcon(
		VfxObject *parentObj		// [IN] Parent object
	);

// Override
protected:
    virtual void onCreateView();
	
    virtual void onReleaseView();
	
    virtual void onPageEnter();
	
    virtual void onPageExit();
	
	virtual VfxResId onGetStatusBarBg();
	
	virtual VfxBool onGetStatusBarTranslucent();
	
	virtual VfxBool onPenInput(VfxPenEvent &event);
	
// Method
private:
    void onUnlockHandler(VfxObject* sender);

	void onFishAnimationEndCallback(VfxObject *frame);

	void onTimerTickFish(VfxTimer * timer);

	void onTimerTickFlap(VfxTimer *timer);

// Variable
private:

	VfxImageFrame *m_bg;

	VfxFrame *m_time_bg;

	VfxAnimImageFrame *m_fish;

	VfxImageFrame *m_dragonFly;

	VappScreenLockPaintingTimeArea *m_timeArea;

	VfxTimer *m_timerFish;

	VfxTimer *m_timerFlap;  

	VfxBool m_isFlapOn;

	VappDragonFlyFilter *m_dragonFlyFilter;

	VfxFloatTimeline *m_dragonFlyTimeline;
};


class VappScreenLockPaintingTimeArea : public VfxControl
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
	VappScreenLockPaintingTimeArea();


// Override
protected:
    virtual void onInit();   
  
	virtual VfxBool onPenInput(VfxPenEvent &event);


private:
	void layoutTimeArea();

	void timeUpdate(VfxU32 flag);

	void reset(VfxBool isNoAnimation);

	void flyOut();

	void onTimelineStopped(VfxBaseTimeline * timeline,VfxBool isCompleted);

private:

	VfxImageFrame	*m_timeBg;

	VfxImageFrame	*m_timeIndicator;

	VfxImageFrame	*m_timeHour[2];

	VfxImageFrame	*m_timeMin[2];

	VfxImageFrame	*m_timeDot;

	StateEnum		m_state;

public:
	VfxSignal1	<VfxObject*>	m_signalUnlock;

};

class VappDragonFlyFilter : public VfxFrameFilter
{
public:
	VappDragonFlyFilter();

protected:
	virtual void onInit();
	
	virtual VfxBool onProcess(VfxU8 * outBuf,VfxImageBuffer & inBuf,VfxFloat timing);
	
	virtual BufferModeEnum onGetBufferMode() const
	{
	    return BUFFER_MODE_IN_PLACE;
    }

private:
	VfxU32 m_count;
};

#endif /* defined(__MMI_VUI_SCREEN_LOCK_FACTORY__)  && defined(__MMI_VUI_SCREEN_LOCK_PAINTING__) */
#endif /* VAPP_SCREEN_LOCK_H */

