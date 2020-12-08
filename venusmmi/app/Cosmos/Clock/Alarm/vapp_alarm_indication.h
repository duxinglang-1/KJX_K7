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
 *  vapp_alarm_indication.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Alarm indication popup
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
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
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_ALARM_INDICATION_H__
#define __VAPP_ALARM_INDICATION_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C"
{
	#include "MMIDatatype.h"
	#include "ProfilesSrvGprot.h"
#ifdef MOTION_SENSOR_SUPPORT
  #include "SensorSrvGport.h"
#endif	
}

#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vfx_base_popup.h"
#include "vfx_date_time.h"

#include "..\\Calendar\\vapp_cal_reminder.h"

#ifndef __LOW_COST_SUPPORT_COMMON__
extern "C"
{
void mmi_usb_terminate_alarm(void);
}
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VappAlarmIndApp
 *****************************************************************************/
class VappAlarmIndApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappAlarmIndApp);

public:
	VappAlarmIndApp(){}
	virtual ~VappAlarmIndApp(){};

// Override
protected:
    virtual void onRun(void* args, VfxU32 argSize);
	
#ifdef MOTION_SENSOR_SUPPORT
        virtual void onDeinit();
	static void motionTurnoverCallback(srv_sensor_type_enum sensor_type,void *sensor_data,void *user_data);
	
	private:
    SRV_SENSOR_HANDLE    m_handle;
#endif

// Static
public:
	static mmi_ret onReminderEvt(mmi_event_struct *evt);
	static MMI_BOOL onNmgrNotify(mmi_scenario_id scen_id, void *arg);
};

/***************************************************************************** 
 * Class VappAlarmIndicationPopup
 *****************************************************************************/
#ifndef __MMI_ALARM_SLIM__
class VappAlarmClock;
#endif
class VappAlarmTimeFrame;
class VfxTimer;
class VfxKeyEvent;
class VfxTextFrame;
class VcpButton;
class VappAlarmIndicationPopup : public VfxBasePopup
{

// Override
public:
	VappAlarmIndicationPopup(const VfxU8 &index = 0xFF);
	virtual ~VappAlarmIndicationPopup(){};

	enum{BTN_SNOOZE, BTN_STOP, BTN_TOTAL};	
	enum
	{
	#ifdef __MMI_MAINLCD_480X800__
		WIDTH = 446,
		HEIGHT = 302,
		BTN_SNOOZE_WIDTH = 175,
		BTN_LEFT_MARGIN = 15,
		BTN_BOTTOM_MARGIN = 25,
		CLOCK_LEFT_MARTIN = 20,
		CLOCK_TOP_MARTIN = 30,
		TIME_FONT_SIZE = 78, //37,
		AMPM_FONT_SIZE = 24,
		LABEL_FONT_SIZE = 23,
		TIME_TOP_MARGIN = 40,
		TIME_RIGHT_MARTIN = 35,
		LABEL_INT = 13
    #elif defined  __MMI_MAINLCD_320X480__
		WIDTH = 280,
		HEIGHT = 190,
		BTN_SNOOZE_WIDTH = 175,
		BTN_LEFT_MARGIN = 15,
		BTN_BOTTOM_MARGIN = 15,
		CLOCK_LEFT_MARTIN = 21,
		CLOCK_TOP_MARTIN = 22,
		TIME_FONT_SIZE = 25,
		AMPM_FONT_SIZE = 9,
		LABEL_FONT_SIZE = 18,
		TIME_TOP_MARGIN = 40,
		TIME_RIGHT_MARTIN = 31,
		LABEL_INT = 9
    #elif (defined  __MMI_MAINLCD_240X320__ || defined  __MMI_MAINLCD_240X400__ )
		WIDTH = 222,
		HEIGHT = 160,
		BTN_SNOOZE_WIDTH = 100,
		BTN_LEFT_MARGIN = 8,
		BTN_BOTTOM_MARGIN = 13,
		CLOCK_LEFT_MARTIN = 12,
		CLOCK_TOP_MARTIN = 14,
		TIME_FONT_SIZE = 36,
		AMPM_FONT_SIZE = 13,
		LABEL_FONT_SIZE = 13,
		TIME_TOP_MARGIN = 40,
		TIME_RIGHT_MARTIN = 15,
		LABEL_INT = 8
	#else
		WIDTH = 280,
		HEIGHT = 190,
		BTN_SNOOZE_WIDTH = 175,
		BTN_LEFT_MARGIN = 15,
		BTN_BOTTOM_MARGIN = 15,
		CLOCK_LEFT_MARTIN = 21,
		CLOCK_TOP_MARTIN = 22,
		TIME_FONT_SIZE = 25,
		AMPM_FONT_SIZE = 9,
		LABEL_FONT_SIZE = 18,
		TIME_TOP_MARGIN = 40,
		TIME_RIGHT_MARTIN = 31,
		LABEL_INT = 9
	#endif
	};
	
	mmi_ret onPlayAlarmTone(mmi_event_struct *evt);
	mmi_ret onPlayVib(mmi_event_struct *evt);

	void stopTone(void);
	void stopVib(void);

	VfxSignal2<VfxObject *, VfxId> m_signalBtnClick;
	VfxSignal2<VfxU16, VfxBool> m_singnalStatechange;
	
  static srv_prof_ret onPlayToneCallback(srv_prof_ret result);

protected:
	virtual void onInit(void);
	virtual void onDeinit(void);
	virtual void onExit(void);
	virtual VfxBool onKeyInput(VfxKeyEvent & event);
	
private:
	void onBtnClick(VfxObject* obj, VfxId id);
	void regEvtHdlr(void);
	void deregEvtHdlr(void);
	void onTimerCallback(VfxTimer *obj);
	static mmi_ret onEvtHdlr(mmi_event_struct *evt); /* global event handler */

private:
    #ifndef __MMI_ALARM_SLIM__
	VappAlarmClock *m_clock;
    #endif
	VfxTextFrame *m_label;
	VcpButton *m_btnStop;
	VcpButton *m_btnSnooze;
	
	VfxU8 m_index;
	VfxBool m_isUsrAction;
	VfxDateTime m_alarmTime;
	VfxU8 m_snooze;
	VfxBool m_isTonePlaying;
};

/***************************************************************************** 
 * Class VappAlarmIndicationScr
 *****************************************************************************/
class VappAlarmIndicationPopup;
class VcpStatusIconBar;
class VappAlarmIndicationScr : public VfxAppScr
{
	//VFX_DECLARE_CLASS(VappAlarmIndicationScr);//slim min

// Override
public:
	VappAlarmIndicationScr(const VfxBool &pwrOff=VFX_FALSE, const VfxU8 &index=0xFF);
	virtual ~VappAlarmIndicationScr(){};
	
private:
	virtual void onInit(void);
	virtual void onEnter(VfxBool isBackward);
	virtual void onRotate(const VfxScreenRotateParam & param);
	void onPopupClick(VfxObject *obj, VfxId id);

	virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
	VcpStatusIconBar *m_statusBar;
	VfxWeakPtr<VappAlarmIndicationPopup> m_popup;
	VfxBool m_bPwrOff;
	VfxU8 	m_index;
};

/***************************************************************************** 
 * Class VappAlarmCardScreen
 *****************************************************************************/
#ifndef __LOW_COST_SUPPORT_COMMON__
class VappAlarmCard;
class VappAlarmCardScr : public VfxMainScr
{	
	        VFX_DECLARE_CLASS(VappAlarmCardScr);
    
public:
    VappAlarmCardScr(){}
    VappAlarmCardScr(const VfxU8 &index) : m_idx(index){}
	
public:
   virtual void on1stReady();
virtual void onDeinit(void);

public:
    void ReminderCardPageLeave(VfxObject* sender, VfxId id);
    void stop();
    void snooze();
    void onTimeOut(VfxTimer *obj);
    VfxU16 getIdx() const
    {
        return m_idx;
    }
    
protected:
    void processExit(VfxBool isBackward);
    
private:
	VappAlarmCard *m_card;
	VfxBool m_bAction;
    VfxU16 m_idx;
};
#endif
/***************************************************************************** 
 * Class VappAlarmCard
 *****************************************************************************/
#ifndef __LOW_COST_SUPPORT_COMMON__
class VappAlarmClock;
class VappAlarmTimeFrame;
class VfxTextFrame;
class VfxImageFrame;
class VappAlarmCard : public VappReminderCard
{
            
public:
	enum
	{
#ifdef __MMI_MAINLCD_480X800__ /* WVGA*/
		CLOCK_LEFT_MARGIN = 15,
		CLOCK_WIDTH = 132,
		CLOCK_HEIGHT = 132,
		TIME_LEFT_MARGIN = 10,
		TIME_FONT_SIZE = 75,
		AMPM_FONT_SIZE = 26,
		LABEL_TOP_MARGIN = 10,
		LABEL_FONT_SIZE = 16
#elif defined  __MMI_MAINLCD_320X480__ /* HVGA*/
		CLOCK_LEFT_MARGIN = 22,
		CLOCK_WIDTH = 85,
		CLOCK_HEIGHT = 85,
		TIME_LEFT_MARGIN = 5,
		TIME_FONT_SIZE = 52,
		AMPM_FONT_SIZE = 14,
		LABEL_TOP_MARGIN = 10,
		LABEL_FONT_SIZE = 14
		/* QVGA */								/* WQVGA */
#elif (defined	__MMI_MAINLCD_240X320__ || defined	__MMI_MAINLCD_240X400__ )
		CLOCK_LEFT_MARGIN = 14,
		CLOCK_WIDTH = 50,
		CLOCK_HEIGHT = 50,
		TIME_LEFT_MARGIN = 5,
		TIME_FONT_SIZE = 39,
		AMPM_FONT_SIZE = 14,
		LABEL_TOP_MARGIN = 4,
		LABEL_FONT_SIZE = 14
#else /* Default size */
		CLOCK_LEFT_MARGIN = 14,
		CLOCK_WIDTH = 132,
		CLOCK_HEIGHT = 132,
		TIME_LEFT_MARGIN = 11,
		TIME_FONT_SIZE = 39,
		AMPM_FONT_SIZE = 14,
		LABEL_TOP_MARGIN = 4,
		LABEL_FONT_SIZE = 14
#endif

	};

	VappAlarmCard(const VfxU8 &index = 0xFF);
virtual void onInit();
	virtual void onDeinit();
	
	void onBtnClick(VfxObject* obj, VfxId id);
	void regEvtHdlr(void);
	void deregEvtHdlr(void);
	void stop(void);
	void snooze(void);
	void stopTone(void);
	void stopVib(void);
	mmi_ret onPlayTone(mmi_event_struct *evt);
	mmi_ret onPlayVib(mmi_event_struct *evt);

	static mmi_ret onEvtHdlr(mmi_event_struct *evt); /* global event handler */

	virtual VfxBool isMovable(const VfxS32 &operation);

protected:
	void layout(void);
	
private:

	VappAlarmTimeFrame *m_time;
	VfxImageFrame	*m_clock;
	VfxTextFrame *m_label;
	VfxU8 m_index;
	VfxBool m_bUsrAction;
	VfxBool m_bIsTonePlaying;
};

#endif

#endif /* __VAPP_ALARM_INDICATION_H__ */

