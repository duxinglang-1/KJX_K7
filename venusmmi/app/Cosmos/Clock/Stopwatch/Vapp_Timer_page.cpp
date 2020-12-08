/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_timer_page.h"
#include "vapp_clock_app.h"
#include "mmi_rp_srv_venus_component_base_picker_def.h"
#include "mmi_rp_vapp_clock_def.h"
#include "mmi_rp_vapp_calendar_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "vapp_screen_lock_gprot.h"
#include "Vsrv_ncenter.h"
#include "vfx_app_launcher.h"
#include "mmi_rp_vapp_ucm_def.h"
#include "Mmi_frm_input_gprot.h"
#include "Vapp_Timer_indication.h"
extern "C" 
{
	#include "ProfilesSrvGprot.h"
	#include "mdi_audio.h"
	#include "GpioSrvGprot.h"
	#include "NotificationGprot.h"
	#include "GlobalConstants.h"
}

/***************************************************************************** 
 * global propety
 *****************************************************************************/
VappTimerstruct g_timer_cntx;

/***************************************************************************** 
 * Function Declear
 *****************************************************************************/
extern "C" void vapp_timer_timeout_hdlr(void);
extern "C" void vapp_timer_updatetime(void);
MMI_BOOL vapp_timer_ring_hdlr(mmi_scenario_id scen_id, void *arg);
extern "C" mmi_ret vapp_timer_proc(mmi_event_struct *evt);
extern "C" void wgui_status_icon_bar_hide_icon(S32 icon_id);
extern "C" void wgui_status_icon_bar_show_icon(S32 icon_id);
extern "C" void vapp_timer_indication_launch(void* param, U32 param_size);
extern "C" mmi_ret vapp_timer_update_ncell(mmi_event_struct *evt);
extern "C" void vapp_clock_ncell_process_intent(VsrvNotification* noti, VsrvNIntent intent, void* viewData, VfxU32 viewDataSize);

#pragma arm section code = "DYNAMIC_CODE_CLOCK_ROCODE", rodata = "DYNAMIC_CODE_CLOCK_RODATA"

/***************************************************************************** 
 * Class VappTimerPage
 *****************************************************************************/
void VappTimerPage::onInit()
{
    VfxPage::onInit();

	VfxS32  mid_pos_x = getSize().width / 2;
    VFX_OBJ_CREATE(m_btnstart, VcpButton, this);
	VfxS32 button_height = m_btnstart->getBounds().getHeight();
	m_btnstart->setAnchor(1.0f, 0);
    m_btnstart->setPos(mid_pos_x - BUTTON_LEFT_BLANK, BUTTON_POS_Y);
	m_btnstart->setSize(BUTTON_WIDTH, button_height);
    m_btnstart->m_signalClicked.connect(this, &VappTimerPage::onButtonStartClicked);
	
	VFX_OBJ_CREATE(m_btnsettime, VcpButton, this);
    m_btnsettime->setPos(mid_pos_x + BUTTON_RIGHT_BLANK, BUTTON_POS_Y);
	m_btnsettime->setSize(BUTTON_WIDTH, button_height);
    m_btnsettime->m_signalClicked.connect(this, &VappTimerPage::onButtonSetTimeClicked);
    m_btnsettime->setText(STR_ID_VAPP_TIMER_SET);
	
	VFX_OBJ_CREATE(m_text_time, VfxTextFrame, this);
	m_text_time->setAnchor(0.5f, 0);
	m_text_time->setPos(mid_pos_x, 0);
	m_text_time->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TEXT_FRAME_FONT_SIZE), 
						        VFX_FONT_DESC_ATTR_BOLD, 
						        VFX_FONT_DESC_EFFECT_NONE));
	m_text_time->setSize(TEXT_FRAME_WIDTH, TEXT_FRAME_HEIGHT);
	m_text_time->setAutoResized(VFX_FALSE);
	m_text_time->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
	m_text_time->setVerticalToCenter(VFX_TRUE);

	m_text_time->setString(VFX_WSTR("00:00:00"));
	
    g_timer_cntx.pobject= (VfxU32)this;
}

void VappTimerPage::onDeinit()
{
    VfxPage::onDeinit();
    g_timer_cntx.pobject = 0;
}

void VappTimerPage::onEnter(VfxBool isBackward)
{
	VfxPage::onEnter(isBackward);
	refreshTimerPage();
	if (g_timer_cntx.time_run_flag)
	{
	    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
	}
}

void VappTimerPage::onExit(VfxBool isBackward)
{
	VfxPage::onExit(isBackward);
	if (g_timer_cntx.time_run_flag)
	{
	    srv_backlight_turn_off();
	}
}

void VappTimerPage::refreshTimerPage(void)
{
	updateTextFrame();
	if (g_timer_cntx.time_run_flag)
	{
        m_btnstart->setText(STR_ID_VAPP_STOPWATCH_STOP);
		m_btnstart->setIsDisabled(VFX_FALSE);
		m_btnstart->setBgImageList(VcpStateImage(VCP_IMG_BUTTON_RED_N, 
												 VCP_IMG_BUTTON_RED_P, 
												 VCP_IMG_BUTTON_RED_D, 
												 VCP_IMG_BUTTON_RED_N));
		wgui_status_icon_bar_show_icon(STATUS_ICON_TIMER);
	}
	else if (g_timer_cntx.curtime.hour   != 0 ||
			 g_timer_cntx.curtime.minute != 0 ||
			 g_timer_cntx.curtime.second != 0)
	{
		if (g_timer_cntx.time_fst_set)
		{
			m_btnstart->setText(STR_ID_VAPP_STOPWATCH_START);
		}
		else
		{
			m_btnstart->setText(STR_ID_VAPP_STOPWATCH_CONTINUE);
		}        
		m_btnstart->setIsDisabled(VFX_FALSE);
		m_btnstart->setBgImageList(VcpStateImage(VCP_IMG_BUTTON_DEFAULT_02_N,
												 VCP_IMG_BUTTON_DEFAULT_02_P,
												 VCP_IMG_BUTTON_DEFAULT_02_D,
												 VCP_IMG_BUTTON_DEFAULT_02_N));
		wgui_status_icon_bar_hide_icon(STATUS_ICON_TIMER);
	}
	else
	{
	    m_btnstart->setText(STR_ID_VAPP_STOPWATCH_START);
	    m_btnstart->setIsDisabled(VFX_TRUE);
		m_btnstart->setBgImageList(VcpStateImage(VCP_IMG_BUTTON_DEFAULT_02_N,
	                       						 VCP_IMG_BUTTON_DEFAULT_02_P,
	                        					 VCP_IMG_BUTTON_DEFAULT_02_D,
	                        					 VCP_IMG_BUTTON_DEFAULT_02_N));
		wgui_status_icon_bar_hide_icon(STATUS_ICON_TIMER);
	}
}

void VappTimerPage::onButtonStartClicked(VfxObject* obj, VfxId index)
{
    if (g_timer_cntx.time_run_flag)
    {
        g_timer_cntx.time_run_flag = VFX_FALSE;
		srv_backlight_turn_off();
    }
    else
    {
        StartTimer(MMI_TIMER_TIMER, 1000, vapp_timer_timeout_hdlr);
        g_timer_cntx.time_run_flag = VFX_TRUE;
        g_timer_cntx.time_fst_set = VFX_FALSE;
		srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
    }
	refreshTimerPage();
}

void VappTimerPage::onButtonSetTimeClicked(VfxObject* obj, VfxId index)
{

    VappMyTimePickerPopup* mytimepickerpopup;
    VFX_OBJ_CREATE(mytimepickerpopup, VappMyTimePickerPopup, this);
    mytimepickerpopup->m_signalButtonClicked.connect(this, &VappTimerPage::onSetTime);
    mytimepickerpopup->show(VFX_TRUE);
}

void VappTimerPage::onSetTime(VfxObject* sender, VappTimerStandardTimestruct pickerTime)
{
    memcpy(&g_timer_cntx.curtime, &pickerTime, sizeof(VappTimerStandardTimestruct));

	if (IsMyTimerExist(MMI_TIMER_TIMER))
	{
		StopTimer(MMI_TIMER_TIMER);
	}
	srv_backlight_turn_off();
	g_timer_cntx.time_run_flag = VFX_FALSE;
	g_timer_cntx.time_out_flag = VFX_FALSE;
	g_timer_cntx.time_fst_set = VFX_TRUE;

	refreshTimerPage();
}

void VappTimerPage::updateTextFrame(/*VfxU8 state*/)
{
	if (m_text_time)
	{
	    VfxWString str;
	    str.format("%02d:%02d:%02d",g_timer_cntx.curtime.hour, 
	                                g_timer_cntx.curtime.minute,
	                                g_timer_cntx.curtime.second);
		m_text_time->setString(str);
	}
}

/***************************************************************************** 
 * Class VappTimerPicker
 *****************************************************************************/
VappTimerPicker::VappTimerPicker()
{
	m_currTime.hour = 0;
    m_currTime.minute = 0;
    m_currTime.second = 0;
}


void VappTimerPicker::onInit()
{
    VcpBasePicker::onInit();

    setAutoAnimate(VFX_TRUE);

    setFieldCount(MYTIME_PICKER_FIELD_TOTAL);
    setFieldCellHeight(MYTIME_PICKER_CELL_HEIGHT);
    setBackground(VfxImageSrc(VCP_IMG_BASE_PICKER_BG));

    setContentProvider(this);

	resetLayout();
	VfxFontDesc fontDesc(VFX_FONT_DESC_VF_SIZE(TIME_PICKER_TEXT_FONT_SIZE));
	VfxFontDesc fontDesc2(VFX_FONT_DESC_VF_SIZE(TIME_PICKER_UNIT_FONT_SIZE));
	VfxFontDesc fontDesc3(VFX_FONT_DESC_VF_SIZE(TIME_PICKER_FOCUS_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FE1_8);

    VcpBasePickerFieldInfo tempFieldInfo;
	
	tempFieldInfo.isDataLoop = VFX_TRUE;
	tempFieldInfo.focusIndex = 0;
	tempFieldInfo.textFont = fontDesc2;
	tempFieldInfo.focusTextFont = fontDesc3;
	tempFieldInfo.unitTextFont = fontDesc;
#ifndef __MMI_VUI_COSMOS_CP_SLIM__
#ifdef __MMI_VUI_COSMOS_CP__
	tempFieldInfo.textColor = VFX_COLOR_RES(CLR_COSMOS_BASE_PICKER_TXT);
    tempFieldInfo.focusTextColor = VFX_COLOR_RES(CLR_COSMOS_BASE_PICKER_FOCUS_TXT);    
	tempFieldInfo.unitTextColor = VFX_COLOR_RES(CLR_COSMOS_BASE_PICKER_UNIT_TXT);
#else
	tempFieldInfo.textColor = MYTIME_PICKER_TEXT_FONT_COLOR;	
	tempFieldInfo.focusTextColor = MYTIME_PICKER_FOCUS_FONT_COLOR;	
	tempFieldInfo.unitTextColor = TIME_PICKER_UNIT_FONT_COLOR;	
#endif
#endif

	tempFieldInfo.unitTextVisible = VFX_TRUE;	
	setFieldInfo(tempFieldInfo);

    tempFieldInfo.index = 0;
    tempFieldInfo.unitTextString.loadFromRes(STR_ID_VAPP_TIMER_HOUR);/*= VFX_WSTR_RES(STR_ID_VAPP_TIMER_HOUR);    */
    setFieldInfo(tempFieldInfo);

    tempFieldInfo.index = 1;
    tempFieldInfo.unitTextString.loadFromRes(STR_ID_VAPP_TIMER_MINUTE);/*= VFX_WSTR_RES(STR_ID_VAPP_TIMER_MINUTE);    */
    setFieldInfo(tempFieldInfo);

    tempFieldInfo.index = 2;
    tempFieldInfo.unitTextString.loadFromRes(STR_ID_VAPP_TIMER_SECOND);/*= VFX_WSTR_RES(STR_ID_VAPP_TIMER_SECOND);    */
    setFieldInfo(tempFieldInfo);
}

VfxS32 VappTimerPicker::getFieldCellCount(VfxS32 field)
{
    if (field == MYTIME_PICKER_FIELD_HOURS)
    {
        return 24;
    }
    else if (field == MYTIME_PICKER_FIELD_MINUTES)
    {
        return 60;
    }
    else    // field == MYTIME_PICKER_FIELD_SECONDS
    {
        return 60;
    }
}


VfxWString VappTimerPicker::onGetFieldString(VfxS32 field, VfxS32 cell)
{
	VfxWChar tempStr[10] = {0,};

    if (field == MYTIME_PICKER_FIELD_HOURS)
    {
		kal_wsprintf(tempStr,"%d",cell);
		return VFX_WSTR_MEM(tempStr);
    }
    else if (field == MYTIME_PICKER_FIELD_MINUTES)
    {
		kal_wsprintf(tempStr,"%d",cell);
		return VFX_WSTR_MEM(tempStr);			
    }
    else    // field == MYTIME_PICKER_FIELD_SECONDS
    {
		kal_wsprintf(tempStr,"%d",cell);
		return VFX_WSTR_MEM(tempStr);
    }
}


void VappTimerPicker::onFieldFocusIndexChange(VfxS32 field, VfxS32 focusItem, VfxS32 previousFocusItem)
{
    VappTimerStandardTimestruct curr_time;
    curr_time = getTimerTime();    
    
    if (field == MYTIME_PICKER_FIELD_HOURS)
    {
        // Emit the signal
        curr_time.hour = focusItem;
    }
    else if (field == MYTIME_PICKER_FIELD_MINUTES)
    {
        // Emit the signal
        curr_time.minute = focusItem;
    }
    else // field == VCP_MYTIME_PICKER_FIELD_SECONDS
    {
        curr_time.second= focusItem;
    }
    m_currTime = curr_time;
}

const VappTimerStandardTimestruct &VappTimerPicker::getTimerTime() const
{
    return m_currTime;
}

void VappTimerPicker::updateTime(const VappTimerStandardTimestruct &time)
{
    setFieldFocus(MYTIME_PICKER_FIELD_HOURS, time.hour);
    setFieldFocus(MYTIME_PICKER_FIELD_MINUTES, time.minute);
    setFieldFocus(MYTIME_PICKER_FIELD_SECONDS, time.second);
	m_currTime = time;
}

    
void VappTimerPicker::resetLayout(void)
{
	VfxS32 x1, y1, cell_height;
	setFieldBackgroundImage(MYTIME_PICKER_FIELD_HOURS, VfxImageSrc(VCP_IMG_BASE_PICKER_FIELD_BG));
	setFieldBackgroundImage(MYTIME_PICKER_FIELD_MINUTES, VfxImageSrc(VCP_IMG_BASE_PICKER_FIELD_BG));
	setFieldBackgroundImage(MYTIME_PICKER_FIELD_SECONDS, VfxImageSrc(VCP_IMG_BASE_PICKER_FIELD_BG));
	setBackground(VfxImageSrc(VCP_IMG_BASE_PICKER_BG));
	
    VfxS32 picker_start_x = 6;
    VfxS32 picker_start_y = TIME_PICKER_TEXT_GAP;
	VfxS32 cell_width = (((VappMyTimePickerPopup*)getParent())->getSize().width - 
									2 * picker_start_x - 6 * MYTIME_PICKER_CELL_GAP)/3;
    setFieldCount(MYTIME_PICKER_FIELD_TOTAL);
    // Title
    // Hours
    x1 = picker_start_x;
    y1 = picker_start_y;
    setUnitTextRect(MYTIME_PICKER_FIELD_HOURS, VfxRect(x1, y1, cell_width, TIME_PICKER_TEXT_FONT_SIZE));

    // Minutes
    x1 += cell_width;
	x1 += MYTIME_PICKER_CELL_GAP;
    setUnitTextRect(MYTIME_PICKER_FIELD_MINUTES, VfxRect(x1, y1, cell_width, TIME_PICKER_TEXT_FONT_SIZE));

    // Second
    x1 += cell_width;
	x1 += MYTIME_PICKER_CELL_GAP;
    setUnitTextRect(MYTIME_PICKER_FIELD_SECONDS, VfxRect(x1, y1, cell_width, TIME_PICKER_TEXT_FONT_SIZE));

    // Field
    // Hours
    x1 = picker_start_x;
    y1 = picker_start_y + TIME_PICKER_TEXT_FONT_SIZE+TIME_PICKER_TEXT_GAP;
    cell_height = TIME_PICKER_HEIGHT - y1;
    setFieldCellRect(MYTIME_PICKER_FIELD_HOURS, VfxRect(x1, y1, cell_width, cell_height));

    // Minutes
    x1 += cell_width;
	x1 += MYTIME_PICKER_CELL_GAP;
    setFieldCellRect(MYTIME_PICKER_FIELD_MINUTES, VfxRect(x1, y1, cell_width, cell_height));
    
    // Minutes
    x1 += cell_width;
	x1 += MYTIME_PICKER_CELL_GAP;
    setFieldCellRect(MYTIME_PICKER_FIELD_SECONDS, VfxRect(x1, y1, cell_width, cell_height));

	setSize(((VappMyTimePickerPopup*)getParent())->getSize().width - 4 * MYTIME_PICKER_CELL_GAP, TIME_PICKER_HEIGHT+TIME_PICKER_BLANK);
    VcpBasePicker::checkUpdate();
}

/***************************************************************************** 
 * Class VappMyTimePickerPopup
 *****************************************************************************/
void VappMyTimePickerPopup::onInit()
{
    VfxBasePopup::onInit();

	VfxU32 mid_pos_x = ((VfxPage*)getParent())->getSize().width / 2;
	
	// total height
    VfxS32 totalHeight = 0;
    setAutoAnimate(VFX_TRUE);
	
    // title background
    VfxFrame* titleBg;
    VFX_OBJ_CREATE(titleBg, VfxFrame, this);        
    titleBg->setImgContent(VfxImageSrc(VCP_IMG_POPUP_MORE_BACKGROUND_TOP));
    titleBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	titleBg->setAnchor(0.5f, 0);
	titleBg->setPos(mid_pos_x, totalHeight);
    titleBg->setSize(TIMEPICKER_POPUP_WIDTH, TITLE_HEIGHT);
    titleBg->setAutoAnimate(VFX_TRUE);
	
	VfxFrame* background;
    VFX_OBJ_CREATE(background, VfxFrame, this);
    background->setImgContent(VfxImageSrc(VCP_IMG_POPUP_MORE_BACKGROUND_BOTTOM));
    background->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    background->setIsCached(VFX_TRUE);
	background->setAnchor(0.5f, 0);
    background->setPos(mid_pos_x, totalHeight + TITLE_HEIGHT);	
    background->setAutoAnimate(VFX_TRUE);

	VfxTextFrame* titleFrame;
    VFX_OBJ_CREATE(titleFrame, VfxTextFrame, this);
    titleFrame->setString(STR_ID_VAPP_TIMER_SET);
	titleFrame->setAnchor(0.5f, 0);
	titleFrame->setPos(mid_pos_x, totalHeight);
	titleFrame->setAutoResized(VFX_FALSE);
	titleFrame->setSize(TIMEPICKER_POPUP_WIDTH, TITLE_HEIGHT);
    titleFrame->setColor(VFX_COLOR_WHITE);
    titleFrame->setVerticalToCenter(VFX_TRUE);
    titleFrame->setFont(VfxFontDesc(
								VFX_FONT_DESC_VF_SIZE(TEXT_FRAME_FONT_SZIE), 
								VFX_FONT_DESC_ATTR_NORMAL,
								VFX_FE1_9));
    titleFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    titleFrame->setAutoAnimate(VFX_TRUE); 

	totalHeight += TITLE_HEIGHT;
	setSize(TIMEPICKER_POPUP_WIDTH, totalHeight);
    //Time picker
    VFX_OBJ_CREATE(m_timePicker, VappTimerPicker, this);
    m_timePicker->updateTime(g_timer_cntx.curtime);
	m_timePicker->setAnchor(0.5f, 0);
	m_timePicker->setPos(mid_pos_x, totalHeight);
	
    totalHeight += TIMEPICKER_POPUP_HEIGHT;
	totalHeight += 2*TIMEPICKER_POPUP_BLANK;
	
    // draw line
    VfxImageFrame *seperator;
    VFX_OBJ_CREATE(seperator, VfxImageFrame, this);
	seperator->setResId(IMG_ID_VAPP_CAL_PICKER_SEPERATOR);
	seperator->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	seperator->setAnchor(0.5f, 0);
	seperator->setPos(mid_pos_x, totalHeight);
	seperator->setSize(TIMEPICKER_POPUP_WIDTH-TIMEPICKER_POPUP_BLANK, SEPERATOR_HEIGHT);

	totalHeight += SEPERATOR_HEIGHT;
	totalHeight += TIMEPICKER_POPUP_BLANK;
	
	VcpButton* leftButton;
    VFX_OBJ_CREATE(leftButton, VcpButton, this);
	leftButton->setAnchor(1.0f, 0);
	VfxU16 buttonH = leftButton->getSize().height;
    leftButton->setText(STR_ID_VAPP_TIMER_OK);
    leftButton->setIsAutoResized(VFX_FALSE);
	leftButton->setPos(mid_pos_x - BUTTON_BLANK, totalHeight);
	leftButton->setSize(BUTTON_WIDTH, buttonH);
    leftButton->m_signalClicked.connect(this, &VappMyTimePickerPopup::onButtonClick);
    leftButton->setTextColor(VfxColorResHelper(CLR_COSMOS_TEXT_MAIN));
    leftButton->setId(0);
    leftButton->setAutoAnimate(VFX_TRUE);

	VcpButton* rightButton;
    VFX_OBJ_CREATE(rightButton, VcpButton, this);
    rightButton->setText(STR_ID_VAPP_TIMER_CANCEL);
    rightButton->setIsAutoResized(VFX_FALSE);
	rightButton->setPos(mid_pos_x + BUTTON_BLANK, totalHeight);
	rightButton->setSize(BUTTON_WIDTH, buttonH);
    rightButton->m_signalClicked.connect(this, &VappMyTimePickerPopup::onButtonClick);
    rightButton->setTextColor(VfxColorResHelper(CLR_COSMOS_TEXT_MAIN));
    rightButton->setId(1);
    rightButton->setAutoAnimate(VFX_TRUE);

	totalHeight += buttonH;
	
    background->setSize(TIMEPICKER_POPUP_WIDTH, totalHeight - 10);
    
    setSize(TIMEPICKER_POPUP_WIDTH, totalHeight + 10);
}

VfxBool VappMyTimePickerPopup::onKeyInput(VfxKeyEvent & event)
{
    if (event.keyCode == VFX_KEY_CODE_BACK &&
        event.type == VFX_KEY_EVENT_TYPE_DOWN)	
    {
    	leave(VFX_TRUE);
		return VFX_TRUE;
	}
	
	return VfxBasePopup::onKeyInput(event);
}
void VappMyTimePickerPopup::onButtonClick(VfxObject* sender, VfxId id)
{
    if (id == 0)// set the time
    {
        VappTimerStandardTimestruct pickerTime;
        pickerTime = m_timePicker->getTimerTime();
        m_signalButtonClicked.emit(this, pickerTime);
    }
    leave(VFX_TRUE);
}
/***************************************************************************** 
 * Function Define
 *****************************************************************************/

#pragma arm section code, rodata

/***************************************************************************** 
 * Class VappTimerNotification
 *****************************************************************************/
 VFX_IMPLEMENT_CLASS("VappTimerNotification", VappTimerNotification, VsrvNCell);
void VappTimerNotification::onInit()
{
    VsrvNCell::onInit();
    m_timerNCenterCell = NULL;
    m_timer = NULL;
}

void VappTimerNotification::onDeinit()
{
    stopNCellTimer();
    VFX_OBJ_CLOSE(m_timerNCenterCell);
    VFX_OBJ_CLOSE(m_timer);
    VsrvNCell::onDeinit();
}

void VappTimerNotification::onCreateView(void* viewData, VfxU32 viewDataSize)
{
    VsrvNCell::onCreateView(viewData, viewDataSize);

    if (!m_timerNCenterCell)
    {
        setSize(VAPP_NCENTER_ONGOING_CELL_WIDTH, VAPP_NCENTER_ONGOING_CELL_HEIGHT);
        VFX_OBJ_CREATE(m_timerNCenterCell, VappNCenterOngoingCell, this);
        m_timerNCenterCell->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE,
                                            VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
        m_timerNCenterCell->setNotification(getNotification());
    }    
	m_timerNCenterCell->setIcon(VfxImageSrc(IMG_ID_VAPP_CLOCK_ICON_TIMER));
    m_timerNCenterCell->setMainText(STR_ID_VAPP_TIMER);
	VfxWString str;
    str.format("%02d:%02d:%02d",g_timer_cntx.curtime.hour, 
                            g_timer_cntx.curtime.minute,
                            g_timer_cntx.curtime.second);
	m_timerNCenterCell->setSubText(str);
	m_timerNCenterCell->setQuestionText(VFX_WSTR_RES(STR_ID_VAPP_TIMER_NC_CLOSE));
    startNCellTimer();
}
void VappTimerNotification::startNCellTimer(void)
{
    if (!m_timer)
    {
        VFX_OBJ_CREATE(m_timer, VfxTimer, this);
        m_timer->setDuration(1000);
        m_timer->m_signalTick.connect(this, &VappTimerNotification::onTimerTicked);
    }
    m_timer->start();
}

void VappTimerNotification::stopNCellTimer(void)
{
    if (m_timer)
    {
        m_timer->stop();
    }
}

void VappTimerNotification::onTimerTicked(VfxTimer *timer)
{
    VfxWString str;
    str.format("%02d:%02d:%02d",g_timer_cntx.curtime.hour, 
                                g_timer_cntx.curtime.minute,
                                g_timer_cntx.curtime.second);
    m_timerNCenterCell->setSubText(str);
}

void vapp_timer_updatetime()
{
    g_timer_cntx.curtime.second--;
    if (g_timer_cntx.curtime.second == 255)
    {
        g_timer_cntx.curtime.second = 59;
        g_timer_cntx.curtime.minute--;
        if (g_timer_cntx.curtime.minute == 255)
        {
            g_timer_cntx.curtime.minute = 59;
            g_timer_cntx.curtime.hour--;
        }
    }
}

void vapp_timer_timeout_hdlr(void)
{
    if (g_timer_cntx.time_run_flag)
    {
    	vapp_timer_updatetime();
        if (g_timer_cntx.pobject != NULL 
			&& ((VappTimerPage*)g_timer_cntx.pobject)->isActive())
        {     
            ((VappTimerPage*)g_timer_cntx.pobject)->updateTextFrame();
        }
		
		if (0 == g_timer_cntx.curtime.hour &&
	        0 == g_timer_cntx.curtime.minute &&
	        0 == g_timer_cntx.curtime.second)
	    {
            mmi_frm_nmgr_notify_by_app(
                    MMI_SCENARIO_ID_REMINDER_ALARM,
                    MMI_EVENT_REMINDER_ALARM,
                    vapp_timer_ring_hdlr,
                    NULL);
	    }
		else
		{
	        StartTimer(MMI_TIMER_TIMER, 1000, vapp_timer_timeout_hdlr);
		}
    }
}

mmi_ret vapp_timer_proc(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{
		case EVT_ID_VAPP_TIMER_IND_RESET:
		{
			if (g_timer_cntx.pobject != NULL
				&& ((VappTimerPage*)g_timer_cntx.pobject)->isActive())
			{	
				((VappTimerPage*)g_timer_cntx.pobject)->refreshTimerPage();
			}
			else
			{
				if (g_timer_cntx.time_run_flag)
				{
					wgui_status_icon_bar_show_icon(STATUS_ICON_TIMER);
				}
				else
				{
					wgui_status_icon_bar_hide_icon(STATUS_ICON_TIMER);
				}
			}
			break;
		}
		default:
			break;
	}
	return MMI_RET_OK;
}

extern "C"
mmi_ret vapp_timer_update_ncell(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
       case EVT_ID_VAPP_CLOCK_TIMER_BG_RUN_START:
        {
            VsrvNGroupSingleTitle *ngroup = NULL;
            VSRV_NGROUP_CREATE_EX(ngroup, VsrvNGroupSingleTitle, (VAPP_CLOCK));
            ngroup->setTitle(VFX_WSTR_RES(STR_ID_VAPP_CLOCK));
            VsrvNotificationCustom *noti = NULL;
            VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationCustom, ((VsrvNGroup *)ngroup, 1));
            noti->setCategory(VSRV_NOTIFICAITON_CUSTOM_CATEGORY_ONGOING);
            noti->setIntentCallback(vapp_clock_ncell_process_intent);
            noti->addCustomViewInfo(VFX_OBJ_CLASS_INFO(VappTimerNotification), VSRV_NVIEWER_TYPE_GENERAL);
            noti->notify();
			break;
       	}            
        case EVT_ID_VAPP_CLOCK_TIMER_BG_RUN_END:
        {
            VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)VAPP_CLOCK, 1);        
            break;
    	}
        default:
            break;
    }
    return MMI_RET_OK;
}

MMI_BOOL vapp_timer_ring_hdlr(mmi_scenario_id scen_id, void *arg)
{
	g_timer_cntx.time_out_flag = VFX_TRUE;
	
	if (IsMyTimerExist(MMI_TIMER_TIMER))
	{
		StopTimer(MMI_TIMER_TIMER);
	}
	
	if (!VfxAppLauncher::findApp(VAPP_TIMER_IND, 
								VFX_OBJ_CLASS_INFO(VappTimerIndApp),
								VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG))
	{
		vapp_timer_indication_launch(NULL, 0);
	}
	
	return MMI_TRUE;
}
