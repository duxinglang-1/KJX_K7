/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_launcher_key_clock.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_KEY__) || defined(__MMI_VUI_LAUNCHER_KEY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"
#include "vapp_screen_lock_key_def.h"
#include "vapp_launcher_key_clock.h"
#include "mmi_rp_app_venus_screen_lock_key_def.h"

#include "vdat_systime.h"
#include "vcp_clock.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "app_datetime.h"
#include "GeneralSettingSrvGprot.h"

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Function
 *****************************************************************************/

/*****************************************************************************
 * VappLauncherKeyClock
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherKeyClock", VappLauncherKeyClock, VfxFrame);

void VappLauncherKeyClock::onInit()
{
	VfxFrame::onInit();

	VFX_OBJ_CREATE(m_bg, VfxImageFrame, this);
	m_bg->setResId(IMG_ID_VAPP_SCRLOCK_TIME_NUM_BG);

	setBounds(m_bg->getBounds());

	getDateTime();
	createTimeClock();
	createDateClock();

	if (srv_setting_get_time_format() == SETTING_TIME_FORMAT_12_HOURS)
	{
		createAmPm();

		VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
	    systemTimeSrv->m_signalTimeChanged.connect(this, &VappLauncherKeyClock::onSystemTimeUpdate);
	}
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void VappLauncherKeyClock::getDateTime()
{
	applib_time_struct current_time;
	applib_dt_get_rtc_time(&current_time);
	m_dt.setDateTime(&current_time);
}

void VappLauncherKeyClock::createTimeClock()
{
	VFX_OBJ_CREATE(m_timeClock, VcpDigitalImageClock, this);
    m_timeClock->setPos(VAPP_SCREEN_LOCK_KEY_CLOCK_POS_TIME_X, VAPP_SCREEN_LOCK_KEY_CLOCK_POS_TIME_Y);
    m_timeClock->setTime(m_dt);
    m_timeClock->setNumber(IMG_ID_VAPP_SCRLOCK_TIME_NUM_0, IMG_ID_VAPP_SCRLOCK_TIME_NUM_9);
    m_timeClock->setNumberBackground(vrt_sys_res_image_lock(0));
    m_timeClock->setTimeSeparator(IMG_ID_VAPP_SCRLOCK_TIME_NUM_COLON, IMG_ID_VAPP_SCRLOCK_TIME_NUM_COLON);
    m_timeClock->setAmAndPm(
        vrt_sys_res_image_lock(0), 
        vrt_sys_res_image_lock(0), 
        vrt_sys_res_image_lock(0), 
        vrt_sys_res_image_lock(0));

	m_timeClock->setGap(VAPP_SCREEN_LOCK_KEY_CLOCK_GAP_TIME, VAPP_SCREEN_LOCK_KEY_CLOCK_GAP_COLON, 1);
    m_timeClock->startClock();
}

void VappLauncherKeyClock::createDateClock()
{
	VFX_OBJ_CREATE(m_dateClock, VcpDigitalTextClock, this);  
	m_dateClock->setFormatFlags(VFX_DATE_TIME_DAY_NORMAL_NAME | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY); 
	m_dateClock->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_SCREEN_LOCK_KEY_CLOCK_FONT_SIZE_DATE)));
	m_dateClock->setTextColor(VAPP_SCREEN_LOCK_KEY_CLOCK_FONT_COLOR);
	m_dateClock->setAlignMode(VcpDigitalTextClock::ALIGN_MODE_CENTER);
	m_dateClock->setPos(0, VAPP_SCREEN_LOCK_KEY_CLOCK_POS_DATE_Y);
	m_dateClock->setBounds(VfxRect(0, 0, LCD_WIDTH, VAPP_SCREEN_LOCK_KEY_CLOCK_FONT_SIZE_DATE));
	m_dateClock->setTime(m_dt);
	m_dateClock->startClock();
}

void VappLauncherKeyClock::createAmPm()
{	
	VFX_OBJ_CREATE(m_amPm, VfxImageFrame, this);
	m_amPm->setPos(VAPP_SCREEN_LOCK_KEY_CLOCK_POS_AMPM_X, VAPP_SCREEN_LOCK_KEY_CLOCK_POS_AMPM_Y);

	setAmPm();
}

void VappLauncherKeyClock::setAmPm()
{
	if(m_dt.getHour() >= 12)
		m_amPm->setResId(IMG_ID_VAPP_SCRLOCK_TIME_PM);
	else
		m_amPm->setResId(IMG_ID_VAPP_SCRLOCK_TIME_AM);
}

void VappLauncherKeyClock::onSystemTimeUpdate(VfxU32 flag)
{
	if (flag & VDAT_SYSTIME_CHANGED_HOUR)
	{
		getDateTime();
		setAmPm();
	}
}

#endif

