#ifndef __VAPP_CLOCK_H__
#define __VAPP_CLOCK_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "Vfx_app.h"
#include "Vfx_main_scr.h"
#include "vcp_tabctrl_page.h"
#include "vfx_app_launcher.h"
#ifndef __LOW_COST_SUPPORT_COMMON__
	#include "vapp_worldclock_map_view.h"
#endif //__LOW_COST_SUPPORT_COMMON__
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
//tab enum    
typedef enum
{
	VAPP_CLOCK_TAB_CTRL_ALARM = 1,
	VAPP_CLOCK_TAB_CTRL_WORLDCLOCK,
    VAPP_CLOCK_TAB_CTRL_STOPWATCH,
    VAPP_CLOCK_TAB_CTRL_HOURMETER,
    VAPP_CLOCK_TAB_CTRL_TOTAL
}vapp_clock_sub_app_type_enum;
/***************************************************************************** 
 * Class VappClockApp
 *****************************************************************************/
class VappClockApp : public VfxApp, public IVfxMainScrHandler
{
	VFX_DECLARE_CLASS(VappClockApp);
public:
    VappClockApp():m_subAppId(VAPP_CLOCK_TAB_CTRL_ALARM){}
    virtual ~VappClockApp(){}
	void setSubAppId(vapp_clock_sub_app_type_enum type);
	vapp_clock_sub_app_type_enum getSubAppId();
protected:
	virtual void onGroupActive();
	virtual void onGroupInactive();
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onScr1stReady(VfxMainScrEx *scr);
	virtual void onDeinit();
private:
	vapp_clock_sub_app_type_enum m_subAppId;
};
/***************************************************************************** 
 * Class VappClockMainPage
 *****************************************************************************/
class VappClockMainPage : public VcpTabCtrlPage
{
public:
    VappClockMainPage(){}
    virtual ~VappClockMainPage(){}

//override    
protected:
    virtual void onInit();
    virtual VfxPage* onCreateTabPage(VfxId tabId);
	virtual void onTabSwitched(VfxId tabId);
	
#ifndef __LOW_COST_SUPPORT_COMMON__
//attribute    
protected:
    VappWCMapPage *m_mapPage;
#endif // __LOW_COST_SUPPORT_COMMON__
};

#endif // __VAPP_CLOCK_H__