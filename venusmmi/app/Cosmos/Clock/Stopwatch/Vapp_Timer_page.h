#ifndef __VAPP_TIMER_H__
#define __VAPP_TIMER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_datatype.h"
#include "Vcp_include.h"
#include "Vfx_page.h"
#include "vcp_base_picker.h"
#include "mmi_rp_srv_venus_component_popup_def.h"
#include "vsrv_notification.h"
#include "vapp_ncenter_gprot.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_TIMER_TIMER_RUN     0x1
#define VAPP_TIMER_TIMER_NOT_RUN 0x0

#define VAPP_TIMER_UPDATE_SEC    0x1
#define VAPP_TIMER_UPDATE_MIN    0x2
#define VAPP_TIMER_UPDATE_HOUR   0x4

#define MYTIME_PICKER_TEXT_FONT_COLOR             VfxColor(255, 123, 123 , 123)
#define MYTIME_PICKER_FOCUS_FONT_COLOR            VfxColor(255, 15, 15 , 15)
#define TIME_PICKER_UNIT_FONT_COLOR               VfxColor(255, 255, 255 , 255)
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct
{
	VfxU8 hour; 	   // Hours, should be in 24 hours format (0-23)
	VfxU8 minute;		// Minutes (0-59)
	VfxU8 second;	   //seconds (0-59)   
}VappTimerStandardTimestruct;
typedef struct
{
	VappTimerStandardTimestruct curtime;
	VfxU32                          pobject;
	VfxBool                         time_run_flag;
	VfxBool                         time_out_flag;
	VfxBool                         time_fst_set;
}VappTimerstruct;
/***************************************************************************** 
 * Class VappTimerPage
 *****************************************************************************/
class VappTimerPage :public VfxPage
{
private:
	enum
	{
#ifdef __MMI_MAINLCD_320X480__
		TEXT_FRAME_WIDTH = 160,
		TEXT_FRAME_HEIGHT = 240,
		TEXT_FRAME_FONT_SIZE = 40,
		BUTTON_LEFT_BLANK = 4,
		BUTTON_RIGHT_BLANK = BUTTON_LEFT_BLANK,
		BUTTON_WIDTH = 140,
		BUTTON_POS_Y = TEXT_FRAME_HEIGHT

#elif (defined  __MMI_MAINLCD_240X320__ || defined  __MMI_MAINLCD_240X400__ )
		TEXT_FRAME_WIDTH = 150,
		TEXT_FRAME_HEIGHT = 160,
		TEXT_FRAME_FONT_SIZE = 36,
		BUTTON_LEFT_BLANK = 2,
		BUTTON_RIGHT_BLANK = BUTTON_LEFT_BLANK,
		BUTTON_WIDTH = 110,
		BUTTON_POS_Y = TEXT_FRAME_HEIGHT
#else
		TEXT_FRAME_WIDTH = 320,
		TEXT_FRAME_HEIGHT = 240,
		TEXT_FRAME_FONT_SIZE = 36,
		BUTTON_LEFT_BLANK = 4,
		BUTTON_RIGHT_BLANK = BUTTON_LEFT_BLANK,
		BUTTON_WIDTH = 150,
		BUTTON_POS_Y = TEXT_FRAME_HEIGHT
#endif
	};
public:
    VappTimerPage()
	{
		m_text_time = NULL;
		m_btnstart = NULL;
		m_btnsettime = NULL;
	}
    virtual ~VappTimerPage(){}
//override
protected:
    virtual void onInit();
    virtual void onDeinit();
	virtual void onEnter(VfxBool isBackwark);
	virtual void onExit(VfxBool isBackwark);
//member function
public:
    void updateTextFrame(/*VfxU8 state*/);
	void refreshTimerPage(void);
protected:
    void onButtonStartClicked(VfxObject* obj, VfxId index);
    void onButtonSetTimeClicked(VfxObject* obj, VfxId index);
    void onSetTime(VfxObject* sender, VappTimerStandardTimestruct pickerTime);
private:
    VcpButton*    m_btnstart;
    VcpButton*    m_btnsettime;
    VfxTextFrame* m_text_time;
};
/*****************************************************************************
 * Class VappTimerPicker
 *****************************************************************************/
class VappTimerPicker : public VcpBasePicker, public IVcpBasePickerContentProvider
{
	typedef enum
	{
		MYTIME_PICKER_FIELD_HOURS,
		MYTIME_PICKER_FIELD_MINUTES,
		MYTIME_PICKER_FIELD_SECONDS,
		MYTIME_PICKER_FIELD_TOTAL
	}VappTimerPickerFieldsEnum;
	enum
	{
#ifdef __MMI_MAINLCD_320X480__
		TIME_PICKER_TEXT_FONT_SIZE = 14,
		TIME_PICKER_UNIT_FONT_SIZE = 22,
		TIME_PICKER_FOCUS_FONT_SIZE = 30,
		TIME_PICKER_HEIGHT = 180,
		TIME_PICKER_TEXT_GAP = 4,
		TIME_PICKER_BLANK = 8,
		MYTIME_PICKER_CELL_HEIGHT = 46,
		MYTIME_PICKER_CELL_GAP = 2
		
#elif (defined  __MMI_MAINLCD_240X320__ || defined  __MMI_MAINLCD_240X400__ )
		TIME_PICKER_TEXT_FONT_SIZE = 13,
		TIME_PICKER_UNIT_FONT_SIZE = 16,
		TIME_PICKER_FOCUS_FONT_SIZE = 22,
		TIME_PICKER_HEIGHT = 160,
		TIME_PICKER_TEXT_GAP = 4,
		TIME_PICKER_BLANK = 8,
		MYTIME_PICKER_CELL_HEIGHT = 40,
		MYTIME_PICKER_CELL_GAP = 2
#else
		TIME_PICKER_TEXT_FONT_SIZE = 13,
		TIME_PICKER_UNIT_FONT_SIZE = 16,
		TIME_PICKER_FOCUS_FONT_SIZE = 22,
		TIME_PICKER_HEIGHT = 160,
		TIME_PICKER_TEXT_GAP = 4,
		TIME_PICKER_BLANK = 8,
		MYTIME_PICKER_CELL_HEIGHT = 40,
		MYTIME_PICKER_CELL_GAP = 2
#endif
	};
public:
	VappTimerPicker();

public:
	void setTime(
		const VappTimerStandardTimestruct &time				 // [IN]   XXX
	);
	void updateTime(const VappTimerStandardTimestruct &time);
	const VappTimerStandardTimestruct &getTimerTime() const;
	
private:	
	void resetLayout(void);

protected:

	virtual void onInit();
	virtual VfxS32 getFieldCellCount(VfxS32 field);
	virtual VfxWString onGetFieldString(VfxS32 field, VfxS32 cell);
	virtual void onFieldFocusIndexChange(VfxS32 field, VfxS32 focusItem, VfxS32 previousFocusItem);

private:
	VappTimerStandardTimestruct m_currTime;
};


/***************************************************************************** 
 * Class VappHourmeterTimerPickePage
 *****************************************************************************/
class VappMyTimePickerPopup: public VfxBasePopup
{
private:
	enum
	{
#ifdef __MMI_MAINLCD_320X480__
		TEXT_FRAME_FONT_SZIE = 14,
		TIMEPICKER_POPUP_WIDTH = 320,
		TIMEPICKER_POPUP_HEIGHT = 180,
		TIMEPICKER_POPUP_BLANK = 10,
		BUTTON_WIDTH = 130,
		BUTTON_BLANK = 6,
		TITLE_HEIGHT = 26,
		SEPERATOR_HEIGHT = 2

		
#elif (defined  __MMI_MAINLCD_240X320__ || defined  __MMI_MAINLCD_240X400__ )
		TEXT_FRAME_FONT_SZIE = 14,
		TIMEPICKER_POPUP_WIDTH = 240,
		TIMEPICKER_POPUP_HEIGHT = 160,
		TIMEPICKER_POPUP_BLANK = 6,
		BUTTON_WIDTH = 100,
		BUTTON_BLANK = 4,
		TITLE_HEIGHT = 20,
		SEPERATOR_HEIGHT = 2

#else
		TEXT_FRAME_FONT_SZIE = 14,
		TIMEPICKER_POPUP_WIDTH = 240,
		TIMEPICKER_POPUP_HEIGHT = 160,
		TIMEPICKER_POPUP_BLANK = 6,
		BUTTON_WIDTH = 100,
		BUTTON_BLANK = 4,
		TITLE_HEIGHT = 20,
		SEPERATOR_HEIGHT = 2
#endif
	};
public:
    VappMyTimePickerPopup(): m_timePicker(NULL){}
// Override
protected:
    virtual void onInit();
    virtual VfxBool onKeyInput(VfxKeyEvent & event);
    
// Implenmention
private:
    void onButtonClick(VfxObject* sender, VfxId id); 
// Signal
public:
    VfxSignal2 <
        VfxObject*,                     // sender 
        VappTimerStandardTimestruct           // data
    > m_signalButtonClicked;

// Variable    
public:
    VappTimerPicker                 *m_timePicker;
};



/***************************************************************************** 
 * Class VappStopwatchNotification
 *****************************************************************************/
class VappTimerNotification: public VsrvNCell
{
    VFX_DECLARE_CLASS(VappTimerNotification);
protected:
    virtual void onInit();
    virtual void onDeinit();

public:
    virtual void onCreateView(void* viewData, VfxU32 viewDataSize);
private:
    VappNCenterOngoingCell *m_timerNCenterCell;
    VfxDateTime     m_callStartTime;
    VfxTimer       *m_timer;

    void onTimerTicked(VfxTimer *timer);
    VfxWString getTimerDurationStr(void);
    void startNCellTimer(void);
    void stopNCellTimer(void);

};
#endif // __VAPP_TIMER_H__
