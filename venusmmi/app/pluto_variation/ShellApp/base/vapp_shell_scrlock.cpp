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
 *  vapp_shell_scrlock.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Screen Lock for Shell
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_SHELL_SCREEN_LOCK__

#include "vfx_app_cat_scr.h"
#include "vrt_datatype.h"
#include "vfx_datatype.h"
#include "vrt_system.h"
#include "vfx_basic_type.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_primitive_frame.h"
#include "vapp_hs_cp.h"
#include "vfx_control.h"
#include "vfx_signal.h"
#include "vdat_systime.h"
#include "vfx_date_time.h"
#include "vfx_system.h"
#include "vfx_string.h"
#include "vfx_font_desc.h"
#include "vfx_frame.h"
#include "vfx_text_frame.h"
#include "vcp_button.h"
#include "vcp_state_image.h"
//#include "vfx_visual.h"
#include "vfx_animation.h"
#include "vcp_status_icon_bar.h"
#include "vcp_page_panel.h"
#include "vcp_frame_effect.h"

#include "vadp_app_trc.h"

#include "mmi_rp_app_venus_shell_scrlock_def.h"
#include "vapp_shell_panel.h"
#include "vapp_shell_panel_cfg.h "
#include "vapp_shell_scrlock.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "lcd_sw_inc.h"

#include "MMIDataType.h"
#include "ScrLockerGprot.h"

#ifdef __cplusplus
}
#endif


/*****************************************************************************
 * Lock Screen
 *****************************************************************************/

VappShellScrLockScr::VappShellScrLockScr()
{
    // Do nothing.
}


void VappShellScrLockScr::onInit()
{
    VfxAppCatScr::onInit();

    setSize(LCD_WIDTH, LCD_HEIGHT);

	// 
	// Background image
	//
	VFX_OBJ_CREATE(m_bgImg, VfxImageFrame, this);
	m_bgImg->setBgColor(VfxColor(0xff00ff00));
	m_bgImg->setResId(VAPP_SHELL_IMG_SCRLOCK_BGIMG);

	//
	// Status icon bar
	//
    VFX_OBJ_CREATE(m_iconBar, VcpStatusIconBar, this);
    m_iconBar->enableBackground(VFX_FALSE);
#if defined(__MMI_NCENTER_SUPPORT__)
	m_iconBar->setIsUnhittable(VFX_TRUE);
#endif

	//
	// Date time area
	//
	VFX_OBJ_CREATE(m_dateTimeArea, VappShellScrLockDateTimeArea, this);
	m_dateTimeArea->setPos(0, VAPP_SHELL_SCRLOCK_DATE_TIME_AREA_Y);
	m_dateTimeArea->setBounds(VfxRect(VFX_POINT_ZERO , VfxSize(LCD_WIDTH, VAPP_SHELL_SCRLOCK_PROGRESS_Y - VAPP_SHELL_SCRLOCK_DATE_TIME_AREA_Y)));
	m_dateTimeArea->setBgColor(0x4f000000);

	//
	// Progress bar
	//
	VFX_OBJ_CREATE(m_progressBar, VappShellScrLockProgress, this);
	m_progressBar->setPos(0, VAPP_SHELL_SCRLOCK_PROGRESS_Y);
	m_progressBar->setSize(LCD_WIDTH, LCD_HEIGHT - VAPP_SHELL_SCRLOCK_PROGRESS_Y);
	m_progressBar->setBgColor(VfxColor(0x5f000000));
	m_progressBar->m_event1.connect(this, &VappShellScrLockScr::ButtonHandler);
}


void VappShellScrLockScr::ButtonHandler()
{
    //
    // TODO: It is better that the APP category provides a callback.
    //
	mmi_scr_locker_close();
}


/*****************************************************************************
 * Date Time Area
 *****************************************************************************/

VappShellScrLockDateTimeArea::VappShellScrLockDateTimeArea()
{
    // Do nothing.
}


void VappShellScrLockDateTimeArea::timeUpdate(VfxU32 flag)
{
	if(flag & VDAT_SYSTIME_CHANGED_MIN || flag & VDAT_SYSTIME_CHANGED_HOUR || flag & VDAT_SYSTIME_CHANGED_DAY || flag & VDAT_SYSTIME_CHANGED_MONTH)
	{
	    vrt_size_struct main_screen_size;
	    VfxColorTypeEnum main_screen_color_format;
	    vrt_sys_get_main_screen_info(
	        &main_screen_size, 
	        &main_screen_color_format);

		VfxDateTime date;
		date.setCurrentTime();

		VfxWChar string_buf[32], ampm_buf[3];
		VfxRect time_rect, day_rect, date_rect, ampm_rect;
		VfxS32 time_x, time_y, day_x, day_y;
		VfxU8 str_len;
		VfxBool ampm_exist = VFX_FALSE;


	    date.getDateTimeString(VFX_DATE_TIME_TIME_MINUTE|VFX_DATE_TIME_TIME_HOUR, (VfxWChar*)string_buf, 32);
		str_len = vfx_sys_wcslen((VfxWChar*)string_buf);
		if(str_len > 6)//with AMPM
		{
			ampm_exist = VFX_TRUE;
			vfx_sys_wcscpy((VfxWChar*) ampm_buf, (VfxWChar*) &string_buf[str_len-2]);
            string_buf[str_len-3] = 0; /* \space */
            string_buf[str_len-2] = 0; 
            string_buf[str_len-1] = 0;
			m_AmPm->setString(VFX_WSTR_MEM(ampm_buf));
			m_AmPm->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(18), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
			m_AmPm->setAutoResized(VFX_TRUE);
            m_AmPm->setFullLineHeightMode(VFX_FALSE);
			ampm_rect = m_AmPm->getMeasureBounds();
		}
		m_Time->setString(VFX_WSTR_MEM(string_buf));
		m_Time->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(73), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
		m_Time->setAutoResized(VFX_TRUE);
        m_Time->setFullLineHeightMode(VFX_FALSE);
		time_rect = m_Time->getMeasureBounds();

		date.getDateTimeString(VFX_DATE_TIME_DAY_NORMAL_NAME, (VfxWChar*)string_buf, 32);
		time_x = vfx_sys_wcslen((VfxWChar*)string_buf);
		string_buf[time_x] = ',';
		string_buf[time_x + 1] = 0;
		m_WeekDay->setString(VFX_WSTR_MEM(string_buf));
		m_WeekDay->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(16), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
		m_WeekDay->setColor(VfxColor(255, 188, 188, 188));
		m_WeekDay->setAutoResized(VFX_TRUE);
        m_WeekDay->setFullLineHeightMode(VFX_FALSE);
		day_rect = m_WeekDay->getMeasureBounds();

		date.getDateTimeString(
            VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY | VFX_DATE_TIME_DATE_YEAR,
            (VfxWChar*)string_buf,
            32);

		m_Date->setString(VFX_WSTR_MEM(string_buf));
		m_Date->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(16), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
		m_Date->setColor(VfxColor(255, 188, 188, 188));
		m_Date->setAutoResized(VFX_TRUE);
        m_Date->setFullLineHeightMode(VFX_FALSE);
		date_rect = m_Date->getMeasureBounds();

		if(ampm_exist == VFX_TRUE)
		{
			time_x = (main_screen_size.width-time_rect.getWidth()-ampm_rect.getWidth() - 2)>>1;
			time_y = (VAPP_SHELL_SCRLOCK_DATE_TIME_AREA_HEIGHT-time_rect.getHeight()-day_rect.getHeight())/3;
			m_AmPm->setPos(time_x + time_rect.getWidth() + 2, time_y +time_rect.getHeight()-ampm_rect.getHeight());
		}
		else
		{
			time_x = (main_screen_size.width-time_rect.getWidth())>>1;
			time_y = (VAPP_SHELL_SCRLOCK_DATE_TIME_AREA_HEIGHT-time_rect.getHeight()-day_rect.getHeight())/3;
		}
		m_Time->setPos(time_x, time_y);

		day_x = (main_screen_size.width-day_rect.getWidth()-date_rect.getWidth() - 2)>>1;
		day_y = (time_y<<1) + time_rect.getHeight();
		m_WeekDay->setPos(day_x, day_y);
		m_Date->setPos(day_x + day_rect.getWidth() + 2, day_y);
	}
}


void VappShellScrLockDateTimeArea::onInit()
{
	VfxFrame::onInit();

	setIsOpaque(VFX_FALSE);

	VFX_OBJ_CREATE(m_Time, VfxTextFrame, this);
	VFX_OBJ_CREATE(m_AmPm, VfxTextFrame, this);
	VFX_OBJ_CREATE(m_WeekDay, VfxTextFrame, this);
	VFX_OBJ_CREATE(m_Date, VfxTextFrame, this);

    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappShellScrLockDateTimeArea::timeUpdate);

	timeUpdate(VDAT_SYSTIME_CHANGED_MIN);
}


void VappShellScrLockDateTimeArea::onDeinit()
{
	VFX_OBJ_CLOSE(m_Time);
	VFX_OBJ_CLOSE(m_AmPm);
	VFX_OBJ_CLOSE(m_WeekDay);
	VFX_OBJ_CLOSE(m_Date);
	VfxFrame::onDeinit();
}


/*****************************************************************************
 * Progress Bar
 *****************************************************************************/

VappShellScrLockProgress::VappShellScrLockProgress()
{
    // Do nothing.
}


void VappShellScrLockProgress::onInit()
{
	VfxFrame::onInit();

	setIsOpaque(VFX_FALSE);

	VFX_OBJ_CREATE(m_bgImg, VfxImageFrame, this);
	m_bgImg->setResId(VAPP_SHELL_IMG_SCRLOCK_PROGRESS_N); 
	m_bgImg->setSize(VAPP_SHELL_SCRLOCK_PROGRESS_WIDTH, VAPP_SHELL_SCRLOCK_PROGRESS_HEIGHT);
	
	VFX_OBJ_CREATE(m_Progress, VfxImageFrame, this);
	m_Progress->setResId(VAPP_SHELL_IMG_SCRLOCK_PROGRESS_P); 
	m_Progress->setSize(VAPP_SHELL_SCRLOCK_PROGRESS_WIDTH, VAPP_SHELL_SCRLOCK_PROGRESS_HEIGHT);
	m_Progress->setHidden(VFX_TRUE);
	
	/* unlock button */
	VFX_OBJ_CREATE(m_ActButton, VcpButton, this);

	VcpStateImage btnImg;
	btnImg.setImage(VAPP_SHELL_IMG_SCRLOCK_LOCK_U, VAPP_SHELL_IMG_SCRLOCK_LOCK_D, 0, 0);
	m_ActButton->setImage(btnImg);

    VcpStateImage bgImg;
    bgImg.setImage(VAPP_SHELL_IMG_SCRLOCK_LOCK_BG_N, VAPP_SHELL_IMG_SCRLOCK_LOCK_BG_P, 0, 0);
    m_ActButton->setBgImageList(bgImg);

	m_ActButton->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_TOP);
	m_ActButton->setText(VFX_WSTR_RES(VAPP_SHELL_SCRLOCK_UNLOCK_STR));
	m_ActButton->setTextFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(14), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
	m_ActButton->setTextColor(VfxColor(255, 255, 255, 255));
	m_ActButton->setPos(VAPP_SHELL_SCRLOCK_PROGRESS_WIDTH, 0);
	m_ActButton->setSize(LCD_WIDTH - VAPP_SHELL_SCRLOCK_PROGRESS_WIDTH, VAPP_SHELL_SCRLOCK_PROGRESS_HEIGHT);
    m_ActButton->setMargin(0, TOP_MARGIN, 0, BOTTOM_MARGIN);

	m_ActButton->m_signalStateChanged.connect(this, &VappShellScrLockProgress::ButtonStateChange);

    // Time line
	VFX_OBJ_CREATE(m_timeline, VfxS32Timeline, this);
}


void VappShellScrLockProgress::ButtonStateChange(VfxObject* sender, VfxId Id, VcpButtonStateEnum state)
{
	switch (state)
	{
		case VCP_BUTTON_STATE_NORMAL:
			Cancel();
			break;
		case VCP_BUTTON_STATE_PRESSED:
			Start();
			break;
		default:
			break;
	}
}


void VappShellScrLockProgress::Start()
{
	m_Progress->setHidden(VFX_FALSE);
	m_ActButton->setTextColor(VfxColor(255, 74, 66, 14));

	m_timeline->setTarget(m_Progress);
	m_timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BOUNDS_SIZE_WIDTH);
	m_timeline->setStartTime(0);
	m_timeline->setFromValue(0);
	m_timeline->setToValue(VAPP_SHELL_SCRLOCK_PROGRESS_WIDTH);
	m_timeline->setDuration(800);
	m_timeline->m_signalStopped.connect(this, &VappShellScrLockProgress::TimeStop);
	m_timeline->start();
}


void VappShellScrLockProgress::TimeStop(VfxBaseTimeline * obj, VfxBool reason)
{
    //
    // 'reason': timeline completed or stopped
    //
	if(reason == VFX_TRUE)
	{
		m_event1.emit();
	}
	else
	{
		m_Progress->setSize(0, VAPP_SHELL_SCRLOCK_PROGRESS_HEIGHT);
		m_bgImg->invalidate();
		m_Progress->invalidate();
	}
}


void VappShellScrLockProgress::Cancel()
{
	m_timeline->stop();
	m_Progress->setHidden(VFX_TRUE);
	m_ActButton->setTextColor(VFX_COLOR_WHITE);
}

#endif /* __MMI_VUI_SHELL_SCREEN_LOCK__ */

