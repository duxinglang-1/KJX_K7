#include "Vapp_clock_app.h"
#include "vapp_Stopwatch_list.h"
#include "vapp_timer_page.h"
#include "vapp_alarm_list.h"
#ifdef __LOW_COST_SUPPORT_COMMON__
	#include "vapp_worldclock_list_view.h"
#endif
#include "mmi_rp_vapp_clock_def.h"
extern "C"
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
#include "dcmgr.h" //DCM
#endif
#include "GpioSrvGprot.h"
}

extern VappTimerstruct g_timer_cntx;
extern VappStopwatchstruct g_stopwatch_cntx;

extern "C" void wgui_status_icon_bar_hide_icon(S32 icon_id);
extern "C" void wgui_status_icon_bar_show_icon(S32 icon_id);

extern "C" MMI_ID vapp_clock_launch(void* param, U32 param_size)
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
			DCM_Load(DYNAMIC_CODE_COMPRESS_CLOCK, 0, 0);
#endif

	return VfxAppLauncher::launch(
		VAPP_CLOCK,
		VFX_OBJ_CLASS_INFO(VappClockApp),
		GRP_ID_ROOT,
		param,
		param_size);
}
extern "C" void vapp_clock_ncell_process_intent(VsrvNotification* noti, VsrvNIntent intent, void* viewData, VfxU32 viewDataSize)

{
    switch (intent.type)
    {
        case VSRV_NINTENT_TYPE_LAUNCH:
        {
            if (VfxAppLauncher::findApp(VAPP_CLOCK, VFX_OBJ_CLASS_INFO(VappClockApp),
    									VFX_APP_LAUNACHER_FIND_APP_BG_FLAG | VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG))
        	{
        		VfxAppLauncher::terminate(VAPP_CLOCK);
	    	}
			vapp_clock_sub_app_type_enum type;
			if (0 == noti->getId())
			{
				type = VAPP_CLOCK_TAB_CTRL_STOPWATCH;
			}
			else if (1 == noti->getId())
			{
				type = VAPP_CLOCK_TAB_CTRL_HOURMETER;
			}
			vapp_clock_launch(&type, sizeof(vapp_clock_sub_app_type_enum));
			break;
        }        
        case VSRV_NINTENT_TYPE_TERMINATE:
        {
			if (0 == noti->getId())
			{
				if (IsMyTimerExist(MMI_STOPWATCH_TIMER))
				{
					StopTimer(MMI_STOPWATCH_TIMER);
				}
				memset(&g_stopwatch_cntx, 0, sizeof(VappStopwatchstruct));
				wgui_status_icon_bar_hide_icon(STATUS_ICON_STOPWATCH);
			}
			else if (1 == noti->getId())
			{
				if (IsMyTimerExist(MMI_TIMER_TIMER))
				{
					StopTimer(MMI_TIMER_TIMER);
				}
//				if (IsMyTimerExist(MMI_TIMER_AUTO_STOP_RING))
//				{
//					StopTimer(MMI_TIMER_AUTO_STOP_RING);
//				}
				if (g_timer_cntx.time_out_flag)
				{
					srv_prof_stop_tone(SRV_PROF_TONE_ALARM); 
					g_timer_cntx.time_out_flag = VFX_FALSE;
				}
				memset(&g_timer_cntx, 0, sizeof(VappTimerstruct));
				wgui_status_icon_bar_hide_icon(STATUS_ICON_TIMER);
			}
			break;
        }        
        default:
        {
        }        
    }

}



/***************************************************************************** 
 * Class VappClockApp
 *****************************************************************************/
 #pragma arm section code = "DYNAMIC_CODE_CLOCK_ROCODE", rodata = "DYNAMIC_CODE_CLOCK_RODATA"  
 VFX_IMPLEMENT_CLASS("VappClockApp", VappClockApp, VfxApp);
void VappClockApp::onRun(void* args, VfxU32 argSize)
{
	VfxApp::onRun(args, argSize);
	if (args)
    {
        VFX_ASSERT(argSize == sizeof(vapp_clock_sub_app_type_enum));
        vapp_clock_sub_app_type_enum *param = (vapp_clock_sub_app_type_enum *)args;
        setSubAppId(*param);
    }
	VfxMainScrEx *scr;
	VFX_OBJ_CREATE_EX(scr, VfxMainScrEx, this, (this));
	scr->show();
}

void VappClockApp::setSubAppId(vapp_clock_sub_app_type_enum type)
{
	m_subAppId = type;
}

vapp_clock_sub_app_type_enum VappClockApp::getSubAppId()
{
	return m_subAppId;
}

void VappClockApp::onScr1stReady(VfxMainScrEx *scr)
{
    VappClockMainPage* clockmainpage;
    VFX_OBJ_CREATE(clockmainpage, VappClockMainPage, scr);
    scr->pushPage(0, clockmainpage);
}

void VappClockApp::onGroupActive()
{
    VfxApp::onGroupActive();

	if (g_stopwatch_cntx.isrunning_flag)
	{
	    mmi_event_struct evt;
	    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_CLOCK_STOPWATCH_BG_RUN_END);
	    MMI_FRM_CB_EMIT_EVENT(&evt);
		srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
	}
	if (g_timer_cntx.time_run_flag)
	{
	    mmi_event_struct evt;
	    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_CLOCK_TIMER_BG_RUN_END);
	    MMI_FRM_CB_EMIT_EVENT(&evt);
		srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
	}
}

void VappClockApp::onGroupInactive()
{
    if (g_stopwatch_cntx.isrunning_flag)
    {
        mmi_event_struct evt;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_CLOCK_STOPWATCH_BG_RUN_START);
        MMI_FRM_CB_EMIT_EVENT(&evt);
		srv_backlight_turn_off();
		
    }
	if (g_timer_cntx.time_run_flag)
	{
	    mmi_event_struct evt;
	    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_CLOCK_TIMER_BG_RUN_START);
	    MMI_FRM_CB_EMIT_EVENT(&evt);
		srv_backlight_turn_off();
	}
	VfxApp::onGroupInactive();
}

void VappClockApp::onDeinit()
{
	VfxApp::onDeinit();
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
	DCM_Unload(DYNAMIC_CODE_COMPRESS_CLOCK);
#endif
}

/***************************************************************************** 
 * class VappClockMainPage
 *****************************************************************************/
void VappClockMainPage::onInit()
{
	VcpTabCtrlPage::onInit();	
	VcpTabCtrlPage::addTab(VAPP_CLOCK_TAB_CTRL_ALARM, STR_ID_VAPP_ALARM, VcpStateImage(IMG_ID_VAPP_CLOCK_ICON_ALARM));
	VcpTabCtrlPage::addTab(VAPP_CLOCK_TAB_CTRL_WORLDCLOCK, STR_ID_VAPP_WORLDCLOCK, VcpStateImage(IMG_ID_VAPP_CLOCK_ICON_WORLDCLOCK));
	VcpTabCtrlPage::addTab(VAPP_CLOCK_TAB_CTRL_STOPWATCH, STR_ID_VAPP_STOPWATCH, VcpStateImage(IMG_ID_VAPP_CLOCK_ICON_STOPWATCH));
	VcpTabCtrlPage::addTab(VAPP_CLOCK_TAB_CTRL_HOURMETER, STR_ID_VAPP_TIMER, VcpStateImage(IMG_ID_VAPP_CLOCK_ICON_TIMER));

	VappClockApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappClockApp);
	VcpTabCtrlPage::setCurrTab(app->getSubAppId());	
}
VfxPage* VappClockMainPage::onCreateTabPage(VfxId tabId)
{
	VfxPage *page = NULL;
	switch (tabId)
	{
		case VAPP_CLOCK_TAB_CTRL_ALARM: 		
			VFX_OBJ_CREATE(page, VappAlarmlistPage, this);
			break;
		case VAPP_CLOCK_TAB_CTRL_WORLDCLOCK:
		#ifdef __LOW_COST_SUPPORT_COMMON__
			VFX_OBJ_CREATE(page, VappWCListViewPage, this); 	
		#else
			VFX_OBJ_CREATE(m_mapPage, VappWCMapPage, this);
			page = m_mapPage;
		#endif
			break;	
		case VAPP_CLOCK_TAB_CTRL_STOPWATCH:
			VFX_OBJ_CREATE(page, VappStopwatchPage, this);
			break;
		case VAPP_CLOCK_TAB_CTRL_HOURMETER:
			VFX_OBJ_CREATE(page, VappTimerPage, this);
			break;
		default:
			break;
	}
	return page;
}

void VappClockMainPage::onTabSwitched(VfxId tabId)
{
#ifndef __LOW_COST_SUPPORT_COMMON__
		if (VAPP_CLOCK_TAB_CTRL_WORLDCLOCK == tabId 
			&& m_mapPage != NULL)
		{
			m_mapPage->map2ndReady();
		}
#endif
}
#pragma arm section code, rodata

