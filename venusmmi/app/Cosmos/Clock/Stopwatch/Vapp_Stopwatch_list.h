#ifndef __VAPP_STOPWATCH_H__
#define __VAPP_STOPWATCH_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "Vfx_page.h"
#include "Vcp_button.h"
#include "Vfx_text_frame.h"
#include "Vcp_list_menu.h"
#include "vsrv_notification.h"
#include "vapp_ncenter_gprot.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_STOPWATCH_RECORDCOUNT_MAX 20

//#define VAPP_STOPWATCH_TIMERUN_FLAG 0x1
//#define VAPP_STOPWATCH_TIMESTOP_FLAG 0x00

#define VAPP_STOPWATCH_TIMERESET_FLAG 0x1
#define VAPP_STOPWATCH_TIMENOTRESET_FLAG 0x00

#define VAPP_STOPWATCH_UPDATE_MAXTEXTFRAME 0x1
#define VAPP_STOPWATCH_UPDATE_MINTEXTFRAME 0x2
#define VAPP_STOPWATCH_UPDATE_MAXMIN_NONE  0x0
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct
{
    VfxU8 millisecond;
    VfxU8 second;
    VfxU8 minute;
    VfxU8 hour;
}stopwatchtime;

typedef struct
{
	stopwatchtime	record_data[VAPP_STOPWATCH_RECORDCOUNT_MAX];
	VfxU64	cur_time;
	VfxU64	last_time;
	stopwatchtime	max_time;
	stopwatchtime	min_time;
	VfxU32	record_count;
	VfxBool	isrunning_flag;
	VfxU32	pobject;
}VappStopwatchstruct;
/***************************************************************************** 
 * Class Declare
 *****************************************************************************/
class VappStopwatchListItem;
class VappStopwatchListMenu;
class VappStopwatchPage;
/***************************************************************************** 
 * Class VappStopwatchPage
 *****************************************************************************/
class VappStopwatchPage : public VfxPage
{
private:
	enum 
	{
#ifdef __MMI_MAINLCD_320X480__
		BUTTON_LEFT_DISTANCE_MID = 4,
		BUTTON_RIGHT_DISTANCE_MID = 4,
		BUTTON_WIDTH = 140,
		BUTTON_BLANK = 6,
		TIME_FRAME_BLANK = 8,
		TIME_FRAME_WIDTH = 195,
		TIME_TEXT_FONT = 40

#elif (defined  __MMI_MAINLCD_240X320__ || defined  __MMI_MAINLCD_240X400__ )
		BUTTON_LEFT_DISTANCE_MID = 2,
		BUTTON_RIGHT_DISTANCE_MID = 2,
		BUTTON_WIDTH = 110,
		BUTTON_BLANK = 4,
		TIME_FRAME_BLANK = 4,
		TIME_FRAME_WIDTH = 180,
		TIME_TEXT_FONT = 36
#else
		BUTTON_LEFT_DISTANCE_MID = 4,
		BUTTON_RIGHT_DISTANCE_MID = 4,
		BUTTON_WIDTH = 140,
		BUTTON_BLANK = 6,
		TIME_FRAME_BLANK = 4,
		TIME_TEXT_FONT = 36

#endif
	};
public:
    VappStopwatchPage(void);
    virtual ~VappStopwatchPage(){}
//override
public:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
	virtual void onExit(VfxBool isBackward);
    virtual void onDeinit();
//Member function
public:
    void updateTextFrame();
	void refreshStopwatchPage(void);
private:
    void updateMaxMinFrame(VfxBool max, VfxBool min);
    void onBtnStartClick(VfxObject* pobj, VfxId id);
    void onBtnResetClick(VfxObject* pobj, VfxId id);
    void saveTimeRecord();
    void updateMaxTime(U32 index);
    void updateMinTime(U32 index);
    void resetStopwatchTimeRecord();
//signal
public:
	VfxSignal0 m_signalupdatetime;
//attribute    
private:
	VfxTextFrame*			m_timeFrame;
    VcpButton*              m_button_start;
    VcpButton*              m_button_reset;
    VappStopwatchListMenu*  m_listmenu;
};

/***************************************************************************** 
 * Class VappStopwatchListMenu
 *****************************************************************************/
class VappStopwatchListMenu : public VcpListMenu, public IVcpListMenuContentProvider
{
//    VFX_DECLARE_CLASS(VappStopwatchListMenu);
public:
    VappStopwatchListMenu(){}
    virtual ~VappStopwatchListMenu(){}
public:
    //override
	virtual void onInit();
	virtual VcpListMenuItemStateEnum getItemState(
		VfxU32 index   // [IN] index of the item
		) const;
	
	virtual void onTouchCell(VcpMenuPos cellPos, 
		CellTouchTypeEnum touchType, 
		VfxPoint pt, 
		VfxFrame *cell);
		

	virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
		VfxU32 index,		 // [IN] index of the item
		VfxFrame *parentFrame // [IN] parent frame of the custom content frame
		);
	
	virtual void closeItemCustomContentFrame(
		VfxU32 index,  // [IN] index of the item
		VcpListMenuCellClientBaseFrame *cell // [IN] the content frame to be released
		);
	
    virtual VfxU32 getCount() const;
	
    virtual VfxBool getItemText(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxWString &text,               // [OUT] the text resource
        VcpListMenuTextColorEnum &color // [OUT] the text color
        );
	void updateRelativeTime();
};

/***************************************************************************** 
 * Class VappStopwatchListItem
 *****************************************************************************/
class VappStopwatchListItem : public VcpListMenuCellClientBaseFrame
{
private:
	enum
	{
#ifdef __MMI_MAINLCD_320X480__
		LIST_ITEM_TEXT_POS_X_DISTANCE = 14,
//		LIST_ITEM_TEXT_POS_X_MAX_MIN = 40,
		LIST_ITEM_TEXT_POS_X_LCD_WIDTH = 320,
		LIST_ITEM_TEXT_POS_Y = 16,
		TEXT_FONT_SIZE = 20
	
#elif (defined  __MMI_MAINLCD_240X320__ || defined  __MMI_MAINLCD_240X400__ )
		LIST_ITEM_TEXT_POS_X_DISTANCE = 6,
//		LIST_ITEM_TEXT_POS_X_MAX_MIN = 40,
		LIST_ITEM_TEXT_POS_X_LCD_WIDTH = 240,
		LIST_ITEM_TEXT_POS_Y = 14,
		TEXT_FONT_SIZE = 16

#else
		LIST_ITEM_TEXT_POS_X_DISTANCE = 6,
//		LIST_ITEM_TEXT_POS_X_MAX_MIN = 40,
		LIST_ITEM_TEXT_POS_X_LCD_WIDTH = 240,
		LIST_ITEM_TEXT_POS_Y = 14,
		TEXT_FONT_SIZE = 20
#endif
	};
public:
    VappStopwatchListItem(){}
    virtual ~VappStopwatchListItem(){}
// Overridable
public:
    virtual void onCreateElements(void);
    virtual void onCloseElements(void);
    virtual void onLayoutElements(void);
    virtual void onUpdateElements(void);
private:
    VfxBool checkifMaxOrMin(VfxU32 index, stopwatchtime refdata);

private:
    VfxTextFrame*               m_recordNoFrame;
//    VfxTextFrame*               m_MaxMinFrame;
    VfxTextFrame*               m_relTimeFrame;
    VfxU32                      m_index;
};

/***************************************************************************** 
 * Class VappStopwatchNotification
 *****************************************************************************/
class VappStopwatchNotification: public VsrvNCell
{
    VFX_DECLARE_CLASS(VappStopwatchNotification);
protected:
    virtual void onInit();
    virtual void onDeinit();

public:
    virtual void onCreateView(void* viewData, VfxU32 viewDataSize);
//    VfxU32          m_callCount;

private:
    VappNCenterOngoingCell *m_stopwatchNCenterCell;
    VfxDateTime     m_callStartTime;
//    VfxWString      m_callStatus;
    VfxTimer       *m_timer;

    void onStopwatchTimerTicked(VfxTimer *timer);
    VfxWString getStopwatchTimeDurationStr(void);
    void startStopwatchTimer(void);
    void stopStopwatchTimer(void);

};


#endif // __VAPP_STOPWATCH_H__
