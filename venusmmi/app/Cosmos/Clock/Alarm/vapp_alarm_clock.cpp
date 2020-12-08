/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_alarm_list.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Alarm list page.
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
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 

extern "C"
{
	#include "AlarmFrameworkProt.h"
	#include "AlarmSrvGprot.h"
	#include "PhoneSetupGprots.h"
	#include "ReminderSrvGprot.h"
    #include "bootupsrvGprot.h"
}

//#include "mmi_rp_vapp_alarm_def.h"
#include "mmi_rp_vapp_clock_def.h"

#ifdef __MMI_VUI_COSMOS_CP__
#include "mmi_rp_app_cosmos_global_def.h"
#endif
#include "vfx_text_frame.h"
#include "data\vdat_systime.h"

#include "vapp_alarm_clock.h"
#include "vapp_alarm.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_ALM_TIME_COLOR VFX_COLOR_BLACK
#define VAPP_ALM_AMPM_COLOR VfxColor(255, 80, 80, 80)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

/***************************************************************************** 
 * Class VappAlarmClock
 *****************************************************************************/
#ifndef __MMI_ALARM_SLIM__
void VappAlarmClock::onInit(void)
{
	VcpAnalogClock::onInit();
	
	setClockTime(m_hour, m_min);
}

void VappAlarmClock::setClockTime(const VfxU8 &hour, const VfxU8 &minute)
{
	m_hour = hour;
	m_min = minute;
	
#ifndef __LOW_COST_SUPPORT_COMMON__
	if (m_hour >= 18 || m_hour < 6)
	{
		setNightRes();
	}
	else
#endif // __LOW_COST_SUPPORT_COMMON__
	{
		setDayRes();
	}
		
	VfxImageFrame *bgImage;
	VFX_OBJ_CREATE(bgImage, VfxImageFrame, this);
	bgImage->setResId(IMG_ID_VAPP_ALARM_DCLOCK_BG);
	setCenter(bgImage->getBounds().getMidPoint());
	VFX_OBJ_CLOSE(bgImage);
	
	VfxDateTime almTime;
	almTime.setTime(m_hour, m_min, 0);
	setTime(almTime);
}

void VappAlarmClock::setDayRes(void)
{
	setClockBackground(vrt_sys_res_image_lock(IMG_ID_VAPP_ALARM_DCLOCK_BG));
	setClockHourHand(IMG_ID_VAPP_ALARM_DCLOCK_HOUR);
	setClockMinuteHand(IMG_ID_VAPP_ALARM_DCLOCK_MINUTE);
	setClockSecondHand(IMG_ID_VAPP_ALARM_DCLOCK_SECOND);
	setClockAxis(IMG_ID_VAPP_ALARM_DCLOCK_CIRCLE);
}
void VappAlarmClock::setNightRes(void)
{
	setClockBackground(vrt_sys_res_image_lock(IMG_ID_VAPP_ALARM_NCLOCK_BG));
	setClockHourHand(IMG_ID_VAPP_ALARM_NCLOCK_HOUR);
	setClockMinuteHand(IMG_ID_VAPP_ALARM_NCLOCK_MINUTE);
	setClockSecondHand(IMG_ID_VAPP_ALARM_NCLOCK_SECOND);
	setClockAxis(IMG_ID_VAPP_ALARM_NCLOCK_CIRCLE);
}
#endif
/***************************************************************************** 
 * Class VappAlarmTimeFrame
 *****************************************************************************/
VappAlarmTimeFrame::VappAlarmTimeFrame(
						const VfxU8 &hour, 
						const VfxU8 &min,
						const VfxU8 &szTime,
						const VfxU8 &szAmpm)
	: m_hour(hour), 
	  m_min(min),
	  m_szTime(szTime),
	  m_szAmpm(szAmpm),
	  m_time(NULL),
	  m_ampm(NULL)
{
}

void VappAlarmTimeFrame::onInit(void)
{
	VfxFrame::onInit();
	
	setIsOpaque(VFX_FALSE);

	VFX_OBJ_CREATE(m_time, VfxTextFrame, this);
	m_time->setFullLineHeightMode(VFX_FALSE);
	m_time->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(m_szTime)));
	m_time->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
	
	VFX_OBJ_CREATE(m_ampm, VfxTextFrame, this);
	m_ampm->setFullLineHeightMode(VFX_FALSE);
	m_ampm->setColor(VFX_COLOR_RES(VAPP_ALARM_SUB_COLOR));
	m_ampm->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(m_szAmpm)));

	setTime(m_hour, m_min);
}

void VappAlarmTimeFrame::setTime(const VfxU8 &hour, const VfxU8 &min)
{
	VfxDateTime dateTime;
	
	if (!dateTime.setTime(hour, min, 0))
	{
			VFX_ASSERT(!VFX_WSTR("Wrong time"));
	}
	
	VfxWChar buffer[64], ampmBuf[3];;

	dateTime.getDateTimeString(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE, 
							   buffer, 
							   64);
	
	VfxBool hasAmpm = VFX_FALSE;
	VfxU8 length;
	length = vfx_sys_wcslen((VfxWChar*)buffer);
	if(length > 6)//with AMPM
	{
	  hasAmpm = VFX_TRUE;
	  vfx_sys_wcscpy((VfxWChar*)ampmBuf, (VfxWChar*) &buffer[length - 2]);
	  
	  buffer[length - 3] = 0; /* \space */
	  buffer[length - 2] = 0; 
	  buffer[length - 1] = 0;
	  
	  m_ampm->setString(ampmBuf);
	}
	
	m_time->setString(buffer);

	setSize(m_time->getSize().width + m_ampm->getBounds().getWidth() + AMPM_START_MARGIN, 
			m_time->getSize().height); 

	if (hasAmpm)
	{
		m_ampm->setAnchor(0.0F, 1.0F);
		m_ampm->setPos(m_time->getBounds().getMaxX() + AMPM_START_MARGIN, 
					   m_time->getBounds().getMaxY() + 1);
		
		m_ampm->setHidden(VFX_FALSE);
	}
	else
	{
		m_ampm->setHidden(VFX_TRUE);
	}
}

void VappAlarmTimeFrame::setTimeColor(const VfxColor &timeColor, const VfxColor &ampmColor)
{
	m_time->setColor(timeColor);
	m_ampm->setColor(ampmColor);
}

VfxS32 VappAlarmTimeFrame::getAmpmHeight(void) const
{
	return m_ampm->getSize().height;
}

extern "C"
{
	void OrgInit(void)
	{
		VappAlarmApp::refreshStatusIcon();
	}
	void mmi_alm_set_alarm_state(U8 index, U8 state)
	{
		srv_alm_node_type *node = srv_alm_read(index);
		node->State= state;
		srv_alm_write(index, node);
	}
	void mmi_alm_get_info(U8 index, U8 *hour, U8 *min, U8 *state)
	{
		srv_alm_node_type *node = srv_alm_read(index);
		*hour = node->Hour;
		*min = node->Min;
		*state = node->State;
	}
	
	void InitAlarmFrameWork(void)
	{
		srv_reminder_init(NULL);
	}
	void AlmDeInit(void)
	{}

	void PendingAlarmReminder(void)
	{
		srv_reminder_notify_finish(MMI_FALSE);
	}


	U8 AlmIsRTCPwron(void)
	{
		return (U8)(srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_ALARM);
	}
	void AlmReInitialize(void)
	{}

	U8 AlmIsTonePlaying(void)
	{
		return (U8)srv_reminder_is_expiring();
	}


	MMI_BOOL mmi_alm_is_in_alarm(void)
	{
		return srv_reminder_is_expiring();
	}

	void AlmATPowerReset(U8 power_off, U8 time)
	{
		U8 rboot_time;
	
		if (time)
		{
			rboot_time = time;
		}
		else
		{
			rboot_time = 3;
		}

		srv_alm_pwr_reset((MMI_BOOL)(power_off != 0), rboot_time);
	}

#if (defined(__MMI_ENGINEER_MODE__)) 
	void FactorySetAlarm(U8 sec)
	{
		AlmATPowerReset(MMI_FALSE, sec);
	}
#endif

	mmi_ret mmi_alm_notify_hdlr(mmi_event_struct *evt){ return MMI_RET_OK; }

	void InitThemes(void){}
	BOOL ATSetTheme(U8 index){return FALSE;}
}

