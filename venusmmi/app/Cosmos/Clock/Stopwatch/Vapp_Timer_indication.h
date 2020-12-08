#ifndef __VAPP_TIMER_INDICATION_H__
#define __VAPP_TIMER_INDICATION_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_datatype.h"
//#include "vfx_signal.h"
#include "vfx_base_popup.h"
#include "vfx_date_time.h"
#include "vfx_app.h"
#include "vfx_app_scr.h"
#include "vfx_text_frame.h"
#include "vcp_confirm_popup.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VappTimerIndApp
 *****************************************************************************/
class VappTimerIndApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappTimerIndApp);

public:
	VappTimerIndApp(){}
	virtual ~VappTimerIndApp(){}

// Override
protected:
    virtual void onRun(void* args, VfxU32 argSize);
	virtual void onGroupInactive();
};

/***************************************************************************** 
 * Class VappTimerIndicationScr
 *****************************************************************************/
class VappTimerIndicationPopup;
class VappTimerIndicationScr : public VfxAppScr
{
// Override
public:
	VappTimerIndicationScr();
	virtual ~VappTimerIndicationScr(){}
	void onBtnClick(VfxObject* obj, VfxId id);
private:
	virtual void onInit(void);
	virtual void onEnter(VfxBool isBackward);
private:
	VappTimerIndicationPopup* m_popup;
};

/***************************************************************************** 
 * Class VappTimerIndicationPopup
 *****************************************************************************/
class VappTimerIndicationPopup : public VcpConfirmPopup
{
// Override
public:
	VappTimerIndicationPopup(void){}
	virtual ~VappTimerIndicationPopup(){}
	enum
	{
    #ifdef __MMI_MAINLCD_320X480__
		WIDTH = 320,
		HEIGHT = 480
    #elif (defined  __MMI_MAINLCD_240X320__ || defined  __MMI_MAINLCD_240X400__ )
		WIDTH = 240,
		HEIGHT = 320
	#else
		WIDTH = 240,
		HEIGHT = 320
	#endif
	};
public:
	void onTimerCallback(VfxTimer* timer);
protected:
	virtual void onInit(void);
	virtual void onDeinit(void);
	virtual VfxBool onKeyInput(VfxKeyEvent & event);
private:
	static mmi_ret onEvtHdlr(mmi_event_struct *evt); /* global event handler */
	void playTone(void);
};
#endif /* __VAPP_TIMER_INDICATION_H__ */
