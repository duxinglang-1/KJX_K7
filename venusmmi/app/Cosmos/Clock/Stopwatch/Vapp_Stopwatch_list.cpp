/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_Stopwatch_list.h"
#include "mmi_rp_vapp_clock_def.h"
#include "vapp_screen_lock_gprot.h"
#include "mmi_rp_vapp_ucm_def.h"
#include "Vsrv_ncenter.h"
#include "vfx_app_launcher.h"
#include "Vapp_Clock_app.h"
#include "Mmi_frm_input_gprot.h"
extern "C"
{
	#include "GpioSrvGprot.h"
	#include "GlobalConstants.h"
}
/***************************************************************************** 
 * global propety
 *****************************************************************************/
VappStopwatchstruct g_stopwatch_cntx;

/***************************************************************************** 
 * Function Declear
 *****************************************************************************/
extern "C" void vapp_stopwatch_timeout_hdlr();
extern "C" void wgui_status_icon_bar_hide_icon(S32 icon_id);
extern "C" void wgui_status_icon_bar_show_icon(S32 icon_id);
extern "C" void vapp_stopwatch_calculateDuration(VfxU64 lasttime, VfxU64 curtime, VfxWString& str_reltime, VfxBool isNomal);
extern "C" void vapp_stopwatch_msecondTostopwatchtime(VfxU64 time, stopwatchtime& reltime);
extern "C" MMI_ID vapp_clock_launch(void* param, U32 param_size);
extern "C" void vapp_clock_ncell_process_intent(VsrvNotification* noti, VsrvNIntent intent, void* viewData, VfxU32 viewDataSize);
#pragma arm section code = "DYNAMIC_CODE_CLOCK_ROCODE", rodata = "DYNAMIC_CODE_CLOCK_RODATA"
/***************************************************************************** 
 * Class VappStopwatchPage
 *****************************************************************************/
VappStopwatchPage::VappStopwatchPage():
 m_timeFrame(NULL)
{
}
void VappStopwatchPage::onInit()
{
    VfxPage::onInit();
	
	VfxSize pagesize = getSize();
	VfxU32 total_height = 0;
	VfxU32 mid_pos_x = pagesize.width / 2;
	VFX_OBJ_CREATE(m_timeFrame, VfxTextFrame, this);
	m_timeFrame->setAnchor(0.5f, 0);
	m_timeFrame->setPos(mid_pos_x, TIME_FRAME_BLANK);
    m_timeFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TIME_TEXT_FONT), 
							        VFX_FONT_DESC_ATTR_BOLD, 
							        VFX_FONT_DESC_EFFECT_NONE));
	m_timeFrame->setAutoResized(VFX_FALSE);
	m_timeFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
	m_timeFrame->setVerticalToCenter(VFX_TRUE);
	m_timeFrame->setSize(TIME_FRAME_WIDTH, pagesize.height / 6);
	m_timeFrame->setAutoFontSize(VFX_TRUE);
	
	total_height += TIME_FRAME_BLANK;
	total_height += m_timeFrame->getSize().height;
	total_height += TIME_FRAME_BLANK;

	VFX_OBJ_CREATE(m_button_start, VcpButton, this);
	m_button_start->setAnchor(1.0f, 0);
    m_button_start->setPos(mid_pos_x - BUTTON_LEFT_DISTANCE_MID, total_height);
	m_button_start->setSize(BUTTON_WIDTH, m_button_start->getSize().height);
    m_button_start->m_signalClicked.connect(this, &VappStopwatchPage::onBtnStartClick);
	m_button_start->setTextColor(VFX_COLOR_WHITE);

    VFX_OBJ_CREATE(m_button_reset, VcpButton, this);
    m_button_reset->setPos(mid_pos_x + BUTTON_RIGHT_DISTANCE_MID, total_height);
	m_button_reset->setSize(BUTTON_WIDTH, m_button_reset->getSize().height);
    m_button_reset->m_signalClicked.connect(this, &VappStopwatchPage::onBtnResetClick);

	total_height += m_button_start->getBounds().getHeight();
	total_height += BUTTON_BLANK;

    VFX_OBJ_CREATE(m_listmenu, VappStopwatchListMenu, this);
	m_listmenu->setAnchor(0.5f ,0);
	m_listmenu->setPos(mid_pos_x, total_height);
    m_listmenu->resetAllItems(VFX_TRUE);    
    VfxS32 height = getSize().height -  total_height;
    m_listmenu->setSize(getSize().width, height);    
	m_listmenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_CUSTOM);
    m_listmenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
	m_listmenu->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
	m_signalupdatetime.connect(this, &VappStopwatchListMenu::updateRelativeTime);

    g_stopwatch_cntx.pobject= (VfxU32)this;
}

void VappStopwatchPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

	refreshStopwatchPage();
	
	if (g_stopwatch_cntx.isrunning_flag)
	{
		srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
	}
}

void VappStopwatchPage::onExit(VfxBool isBackward)
{
	VfxPage::onExit(isBackward);
	if (g_stopwatch_cntx.isrunning_flag)
	{
		srv_backlight_turn_off();
	}
}

void VappStopwatchPage::onDeinit()
{
    VfxPage::onDeinit();
    g_stopwatch_cntx.pobject= 0;
}

void VappStopwatchPage::updateTextFrame()
{
	VfxWString str;
	vapp_stopwatch_calculateDuration(0, g_stopwatch_cntx.cur_time, str, VFX_TRUE);
	m_timeFrame->setString(str);
}

void VappStopwatchPage::refreshStopwatchPage(void)
{
	updateTextFrame();
    if (g_stopwatch_cntx.isrunning_flag)
    {
        m_button_start->setText(STR_ID_VAPP_STOPWATCH_STOP);
		m_button_start->setBgImageList(VcpStateImage(VCP_IMG_BUTTON_RED_N, 
													 VCP_IMG_BUTTON_RED_P, 
													 VCP_IMG_BUTTON_RED_D, 
													 VCP_IMG_BUTTON_RED_N));            
        m_button_reset->setText(STR_ID_VAPP_STOPWATCH_LAP);
	    if (m_listmenu->getCount() == VAPP_STOPWATCH_RECORDCOUNT_MAX)
	    {
	        m_button_reset->setIsDisabled(VFX_TRUE);
	    }
		else
		{
			m_button_reset->setIsDisabled(VFX_FALSE);
		}
    }
    else if (g_stopwatch_cntx.cur_time)
    {
        m_button_start->setText(STR_ID_VAPP_STOPWATCH_CONTINUE);
		m_button_start->setBgImageList(VcpStateImage(VCP_IMG_BUTTON_DEFAULT_02_N,
				                                VCP_IMG_BUTTON_DEFAULT_02_P,
				                                VCP_IMG_BUTTON_DEFAULT_02_D,
				                                VCP_IMG_BUTTON_DEFAULT_02_N));
        m_button_reset->setText(STR_ID_VAPP_STOPWATCH_RESET);
		m_button_reset->setIsDisabled(VFX_FALSE);
    }
    else
    {
    	resetStopwatchTimeRecord();
        m_timeFrame->setString(VFX_WSTR("00:00:00.0"));
		m_button_reset->setText(STR_ID_VAPP_STOPWATCH_RESET);
		m_button_reset->setIsDisabled(VFX_TRUE);
		m_button_start->setText(STR_ID_VAPP_STOPWATCH_START);		
		m_button_start->setBgImageList(VcpStateImage(VCP_IMG_BUTTON_DEFAULT_02_N,
												VCP_IMG_BUTTON_DEFAULT_02_P,
												VCP_IMG_BUTTON_DEFAULT_02_D,
												VCP_IMG_BUTTON_DEFAULT_02_N));  
    }
}

void VappStopwatchPage::onBtnStartClick(VfxObject* pobj, VfxId id)
{
    if (g_stopwatch_cntx.isrunning_flag)
    {
    	g_stopwatch_cntx.isrunning_flag = VFX_FALSE;
		StopTimer(MMI_STOPWATCH_TIMER);       		
        wgui_status_icon_bar_hide_icon(STATUS_ICON_STOPWATCH);
		srv_backlight_turn_off();
    }
    else
    {
    	g_stopwatch_cntx.isrunning_flag = VFX_TRUE;		
		StartTimer(MMI_STOPWATCH_TIMER, 100, vapp_stopwatch_timeout_hdlr);
        wgui_status_icon_bar_show_icon(STATUS_ICON_STOPWATCH);
		srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
    }
	refreshStopwatchPage(); 
}
void VappStopwatchPage::onBtnResetClick(VfxObject* pobj, VfxId id)
{
    if (g_stopwatch_cntx.isrunning_flag)
    {
        //lap
        if (m_listmenu->getCount() < VAPP_STOPWATCH_RECORDCOUNT_MAX)
        {
            saveTimeRecord();
            updateMaxTime(m_listmenu->getCount()-1);
            updateMinTime(m_listmenu->getCount()-1);
            if (m_listmenu->getCount() == VAPP_STOPWATCH_RECORDCOUNT_MAX)
            {
                m_button_reset->setIsDisabled(VFX_TRUE);
            }
            m_listmenu->resetAllItems(VFX_FALSE);
        }
    }
    else
    {
        //Clean
	    resetStopwatchTimeRecord();
		refreshStopwatchPage();
        m_listmenu->resetAllItems(VFX_TRUE);
    }
}

void VappStopwatchPage::saveTimeRecord()
{
    VfxU64 reltime = g_stopwatch_cntx.cur_time - g_stopwatch_cntx.last_time;
    g_stopwatch_cntx.last_time = g_stopwatch_cntx.cur_time;
	vapp_stopwatch_msecondTostopwatchtime(reltime, g_stopwatch_cntx.record_data[g_stopwatch_cntx.record_count]);
    g_stopwatch_cntx.record_count++;
}

void VappStopwatchPage::updateMaxTime(U32 index)
{

    if (g_stopwatch_cntx.max_time.hour < 
        g_stopwatch_cntx.record_data[index].hour)
    {
        memcpy(&g_stopwatch_cntx.max_time, 
            &g_stopwatch_cntx.record_data[index], 
            sizeof(stopwatchtime));
    }
    else if (g_stopwatch_cntx.max_time.hour == g_stopwatch_cntx.record_data[index].hour &&
        g_stopwatch_cntx.max_time.minute < g_stopwatch_cntx.record_data[index].minute)
    {
        memcpy(&g_stopwatch_cntx.max_time, 
            &g_stopwatch_cntx.record_data[index], 
            sizeof(stopwatchtime));
    }
    else if (g_stopwatch_cntx.max_time.hour == g_stopwatch_cntx.record_data[index].hour &&
        g_stopwatch_cntx.max_time.minute == g_stopwatch_cntx.record_data[index].minute &&
        g_stopwatch_cntx.max_time.second < g_stopwatch_cntx.record_data[index].second)
    {
        memcpy(&g_stopwatch_cntx.max_time, 
            &g_stopwatch_cntx.record_data[index], 
            sizeof(stopwatchtime));
    }
    else if (g_stopwatch_cntx.max_time.hour == g_stopwatch_cntx.record_data[index].hour &&
        g_stopwatch_cntx.max_time.minute == g_stopwatch_cntx.record_data[index].minute &&
        g_stopwatch_cntx.max_time.second == g_stopwatch_cntx.record_data[index].second && 
        g_stopwatch_cntx.max_time.millisecond < g_stopwatch_cntx.record_data[index].millisecond)
    {
        memcpy(&g_stopwatch_cntx.max_time, 
            &g_stopwatch_cntx.record_data[index], 
            sizeof(stopwatchtime));
    }
}

void VappStopwatchPage::updateMinTime(U32 index)
{
    if (g_stopwatch_cntx.min_time.hour > g_stopwatch_cntx.record_data[index].hour)
    {
        memcpy(&g_stopwatch_cntx.min_time, 
            &g_stopwatch_cntx.record_data[index], 
            sizeof(stopwatchtime));
    }
    else if (g_stopwatch_cntx.min_time.hour == g_stopwatch_cntx.record_data[index].hour &&
        g_stopwatch_cntx.min_time.minute > g_stopwatch_cntx.record_data[index].minute)
    {
        memcpy(&g_stopwatch_cntx.min_time, 
            &g_stopwatch_cntx.record_data[index], 
            sizeof(stopwatchtime));
    }
    else if (g_stopwatch_cntx.min_time.hour == g_stopwatch_cntx.record_data[index].hour &&
        g_stopwatch_cntx.min_time.minute == g_stopwatch_cntx.record_data[index].minute &&
        g_stopwatch_cntx.min_time.second > g_stopwatch_cntx.record_data[index].second)
    {
        memcpy(&g_stopwatch_cntx.min_time, 
            &g_stopwatch_cntx.record_data[index], 
            sizeof(stopwatchtime));
    }
    else if (g_stopwatch_cntx.min_time.hour == g_stopwatch_cntx.record_data[index].hour &&
        g_stopwatch_cntx.min_time.minute == g_stopwatch_cntx.record_data[index].minute &&
        g_stopwatch_cntx.min_time.second == g_stopwatch_cntx.record_data[index].second &&
        g_stopwatch_cntx.min_time.millisecond > g_stopwatch_cntx.record_data[index].millisecond)
    {
        memcpy(&g_stopwatch_cntx.min_time, 
            &g_stopwatch_cntx.record_data[index], 
            sizeof(stopwatchtime));
    }
}

void VappStopwatchPage::resetStopwatchTimeRecord()
{
	g_stopwatch_cntx.cur_time     = 0;
	g_stopwatch_cntx.last_time    = 0;
	memset(&g_stopwatch_cntx.max_time, 0, sizeof(stopwatchtime));
	memset(&g_stopwatch_cntx.min_time, 255, sizeof(stopwatchtime));
	g_stopwatch_cntx.record_count = 0;
	g_stopwatch_cntx.isrunning_flag = VFX_FALSE;
	memset(g_stopwatch_cntx.record_data, 0, VAPP_STOPWATCH_RECORDCOUNT_MAX*sizeof(stopwatchtime));
}

/***************************************************************************** 
 * Class VappStopwatchListMenu
 *****************************************************************************/
void VappStopwatchListMenu::onInit()
{
    VcpListMenu::onInit();
    setContentProvider(this);
}

void VappStopwatchListMenu::onTouchCell(VcpMenuPos cellPos, CellTouchTypeEnum touchType, VfxPoint pt, VfxFrame *cell)
{
	return;
}

VcpListMenuItemStateEnum VappStopwatchListMenu::getItemState(
		VfxU32 index   // [IN] index of the item
		) const
{
    return VCP_LIST_MENU_ITEM_STATE_NONE;
}

VcpListMenuCellClientBaseFrame* 
    VappStopwatchListMenu::getItemCustomContentFrame(
		VfxU32 index,		 // [IN] index of the item
		VfxFrame *parentFrame // [IN] parent frame of the custom content frame
		)
{
	VappStopwatchListItem *obj;
    VFX_OBJ_CREATE(obj, VappStopwatchListItem, parentFrame); 
	return obj;
}
	
void VappStopwatchListMenu::closeItemCustomContentFrame(
		VfxU32 index,  // [IN] index of the item
		VcpListMenuCellClientBaseFrame *cell // [IN] the content frame to be released
		)
{
    VFX_OBJ_CLOSE(cell);
}

VfxU32 VappStopwatchListMenu::getCount() const
{
    return g_stopwatch_cntx.record_count;
}

VfxBool VappStopwatchListMenu::getItemText(
    VfxU32 index,                   // [IN] the index of item
    VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
    VfxWString &text,               // [OUT] the text resource
    VcpListMenuTextColorEnum &color // [OUT] the text color
    )
{
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        text.format("%02d:%02d:%02d.%d",g_stopwatch_cntx.record_data[index].hour, 
                                        g_stopwatch_cntx.record_data[index].minute, 
                                        g_stopwatch_cntx.record_data[index].second, 
                                        g_stopwatch_cntx.record_data[index].millisecond);
        return VFX_TRUE;
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        text.format("%d", index+1);
        return VFX_TRUE;
    }
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    return VFX_FALSE;
}
void VappStopwatchListMenu::updateRelativeTime()
{
	updateItem(getCount());
}
/***************************************************************************** 
 * Class VappStopwatchListItem
 *****************************************************************************/

void VappStopwatchListItem::onCreateElements(void)
{
    VFX_OBJ_CREATE(m_recordNoFrame, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_relTimeFrame, VfxTextFrame, this);
}

void VappStopwatchListItem::onCloseElements(void)
{
	VFX_OBJ_CLOSE(m_recordNoFrame);
	VFX_OBJ_CLOSE(m_relTimeFrame);
}

void VappStopwatchListItem::onLayoutElements(void)
{
    m_recordNoFrame->setPos(LIST_ITEM_TEXT_POS_X_DISTANCE, LIST_ITEM_TEXT_POS_Y);
	m_recordNoFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TEXT_FONT_SIZE)));

	m_relTimeFrame->setAnchor(1.0f, 0);
    m_relTimeFrame->setPos(LIST_ITEM_TEXT_POS_X_LCD_WIDTH - LIST_ITEM_TEXT_POS_X_DISTANCE, LIST_ITEM_TEXT_POS_Y);
	m_relTimeFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TEXT_FONT_SIZE)));
}

void VappStopwatchListItem::onUpdateElements(void)
{
    IVcpListMenuContentProvider *contentProvider = (IVcpListMenuContentProvider*)getContentProvider();
    VfxWString str;
    VcpListMenuTextColorEnum color;
    VfxU32 index =  g_stopwatch_cntx.record_count - getCell()->m_pos.pos - 1;
    if (m_relTimeFrame && contentProvider->getItemText(index, VCP_LIST_MENU_FIELD_TEXT, str, color))
    {
        m_relTimeFrame->setString(str);
		m_relTimeFrame->setColor(VFX_COLOR_WHITE);
    }
    if (m_recordNoFrame && contentProvider->getItemText(index, VCP_LIST_MENU_FIELD_SUB_TEXT1, str, color))
    {
        m_recordNoFrame->setString(str);
		m_recordNoFrame->setColor(VFX_COLOR_WHITE);
    }
    
    if (g_stopwatch_cntx.record_count > 1 && checkifMaxOrMin(index, g_stopwatch_cntx.max_time))
    {
    	m_recordNoFrame->setColor(VfxColor(255, 22, 161, 199));
    	m_relTimeFrame->setColor(VfxColor(255, 22, 161, 199));
    }
    else if (g_stopwatch_cntx.record_count > 1 && checkifMaxOrMin(index, g_stopwatch_cntx.min_time))
    {
	    m_recordNoFrame->setColor(VfxColor(255, 22, 161, 199));
    	m_relTimeFrame->setColor(VfxColor(255, 22, 161, 199));
    }
}

VfxBool VappStopwatchListItem::checkifMaxOrMin(VfxU32 index, stopwatchtime refdata)
{
    if (refdata.hour == g_stopwatch_cntx.record_data[index].hour &&
        refdata.minute == g_stopwatch_cntx.record_data[index].minute && 
        refdata.second == g_stopwatch_cntx.record_data[index].second && 
        refdata.millisecond == g_stopwatch_cntx.record_data[index].millisecond)
    {        
        return VFX_TRUE;
    }
    return VFX_FALSE;
}
#pragma arm section code, rodata
/***************************************************************************** 
 * Class VappStopwatchNotification
 *****************************************************************************/
 VFX_IMPLEMENT_CLASS("VappStopwatchNotification", VappStopwatchNotification, VsrvNCell);
void VappStopwatchNotification::onInit()
{
    VsrvNCell::onInit();
    m_stopwatchNCenterCell = NULL;
    m_timer = NULL;
}

void VappStopwatchNotification::onDeinit()
{
    stopStopwatchTimer();
    VFX_OBJ_CLOSE(m_stopwatchNCenterCell);
    VFX_OBJ_CLOSE(m_timer);
    VsrvNCell::onDeinit();
}

void VappStopwatchNotification::onCreateView(void* viewData, VfxU32 viewDataSize)
{
    VsrvNCell::onCreateView(viewData, viewDataSize);

    if (!m_stopwatchNCenterCell)
    {
        setSize(VAPP_NCENTER_ONGOING_CELL_WIDTH, VAPP_NCENTER_ONGOING_CELL_HEIGHT);
        VFX_OBJ_CREATE(m_stopwatchNCenterCell, VappNCenterOngoingCell, this);
        m_stopwatchNCenterCell->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE,
                                            VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
        m_stopwatchNCenterCell->setNotification(getNotification());
    }    
	m_stopwatchNCenterCell->setIcon(VfxImageSrc(IMG_ID_VAPP_CLOCK_ICON_STOPWATCH));
    m_stopwatchNCenterCell->setMainText(STR_ID_VAPP_STOPWATCH);
    m_stopwatchNCenterCell->setSubText(getStopwatchTimeDurationStr());
	m_stopwatchNCenterCell->setQuestionText(VFX_WSTR_RES(STR_ID_VAPP_STOPWATCH_NC_CLOSE));
    startStopwatchTimer();
}

VfxWString VappStopwatchNotification::getStopwatchTimeDurationStr(void)
{
    VfxWString str;
	vapp_stopwatch_calculateDuration(0, g_stopwatch_cntx.cur_time, str, VFX_TRUE);
    return str;
}

void VappStopwatchNotification::startStopwatchTimer(void)
{
    if (!m_timer)
    {
        VFX_OBJ_CREATE(m_timer, VfxTimer, this);
        m_timer->setDuration(100);
        m_timer->m_signalTick.connect(this, &VappStopwatchNotification::onStopwatchTimerTicked);
    }
    m_timer->start();
}

void VappStopwatchNotification::stopStopwatchTimer(void)
{
    if (m_timer)
    {
        m_timer->stop();
    }
}

void VappStopwatchNotification::onStopwatchTimerTicked(VfxTimer *timer)
{
    m_stopwatchNCenterCell->setSubText(getStopwatchTimeDurationStr());
}

extern "C"
mmi_ret vapp_stopwatch_update_ncell(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
       case EVT_ID_VAPP_CLOCK_STOPWATCH_BG_RUN_START:
        {
            VsrvNGroupSingleTitle *ngroup = NULL;
            VSRV_NGROUP_CREATE_EX(ngroup, VsrvNGroupSingleTitle, (VAPP_CLOCK));
            ngroup->setTitle(VFX_WSTR_RES(STR_ID_VAPP_CLOCK));
            VsrvNotificationCustom *noti = NULL;
            VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationCustom, ((VsrvNGroup *)ngroup, 0));
            noti->setCategory(VSRV_NOTIFICAITON_CUSTOM_CATEGORY_ONGOING);
            noti->setIntentCallback(vapp_clock_ncell_process_intent);
            noti->addCustomViewInfo(VFX_OBJ_CLASS_INFO(VappStopwatchNotification), VSRV_NVIEWER_TYPE_GENERAL);
            noti->notify();
        }
            break;
        case EVT_ID_VAPP_CLOCK_STOPWATCH_BG_RUN_END:
        {
            VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)VAPP_CLOCK, 0);
        }
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}

/***************************************************************************** 
 * Function Define
 *****************************************************************************/
void vapp_stopwatch_timeout_hdlr()
{
    if (g_stopwatch_cntx.isrunning_flag)
    {
		g_stopwatch_cntx.cur_time++;
        if (g_stopwatch_cntx.pobject != NULL 
			&& ((VappStopwatchPage*)g_stopwatch_cntx.pobject)->isActive())
        {
            ((VappStopwatchPage*)g_stopwatch_cntx.pobject)->updateTextFrame();
        }
		StartTimer(MMI_STOPWATCH_TIMER, 100, vapp_stopwatch_timeout_hdlr);
    }
}

void vapp_stopwatch_calculateDuration(VfxU64 lasttime, VfxU64 curtime, VfxWString& str_reltime, VfxBool isNomal)
{
	stopwatchtime reltime;
	memset(&reltime, 0, sizeof(stopwatchtime));
	if (curtime >= lasttime)
	{
		lasttime = curtime - lasttime;
		vapp_stopwatch_msecondTostopwatchtime(lasttime, reltime);
		if (isNomal)
		{
			str_reltime.format("%02d:%02d:%02d.%d", reltime.hour, reltime.minute, reltime.second, reltime.millisecond);
		}
		else
		{
			str_reltime.format("%02d:%02d:%02d", reltime.hour, reltime.minute, reltime.second);
		}
	}
	else
	{
		ASSERT(0);
	}
}
void vapp_stopwatch_msecondTostopwatchtime(VfxU64 time, stopwatchtime& reltime)
{
	if (time >= 36000)
	{
		reltime.hour   = (VfxU8)(time / 36000);
		time	  %= 36000;
	}
	if (time >= 600)
	{
		reltime.minute = (VfxU8)(time / 600);
		time	  %= 600;
	}
	if (time >= 10)
	{
		reltime.second= (VfxU8)(time / 10);
		time	  %= 10;
	}
	reltime.millisecond = (VfxU8)time;
}
