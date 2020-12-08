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
 *  vapp_alarm_clock.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Alarm list page header file.
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
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_ALARM_CLOCK_H__
#define __VAPP_ALARM_CLOCK_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_datatype.h"
#include "vfx_frame.h"
#include "vcp_clock.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VappAlarmClock
 *****************************************************************************/
#ifndef __MMI_ALARM_SLIM__
class VappAlarmClock : public VcpAnalogClock
{
// Override
public:
	VappAlarmClock(const VfxU8 &hour = 0, const VfxU8 &minute = 0) : m_hour(hour), m_min(minute){}
	virtual ~VappAlarmClock(){};
	
    void onInit();
	
	void setClockTime(const VfxU8 &hour, const VfxU8 &minute);
	
private:
	void setDayRes(void);
	void setNightRes(void);
	
private:
	VfxU8 m_hour;
	VfxU8 m_min;
};

#endif
/***************************************************************************** 
 * Class VappAlarmTimeFrame
 *****************************************************************************/
class VfxTextFrame;
class VfxColor;
class VappAlarmTimeFrame : public VfxFrame
{
    
public:
	VappAlarmTimeFrame(const VfxU8 &hour = 0, 
					   const VfxU8 &min = 0,
					   const VfxU8 &szTime = TIME_FONT_SIZE,
					   const VfxU8 &szAmpm = AMPM_FONT_SIZE);
  

	void setTime(const VfxU8 &hour, const VfxU8 &min);
	void setTimeColor(const VfxColor &timeColor, const VfxColor &ampmColor);
	VfxS32 getAmpmHeight(void) const;

	enum
	{
#ifdef __MMI_MAINLCD_480X800__
		TIME_FONT_SIZE = 80,
		AMPM_FONT_SIZE = 26,
		AMPM_START_MARGIN = 7,
#elif __MMI_MAINLCD_320X480__
		TIME_FONT_SIZE = 58,
		AMPM_FONT_SIZE = 18,		
		AMPM_START_MARGIN = 5,
#elif (defined  __MMI_MAINLCD_240X320__ || defined  __MMI_MAINLCD_240X400__ )	
		TIME_FONT_SIZE = 42,
		AMPM_FONT_SIZE = 15,	
		AMPM_MARGIN = 5,
		AMPM_START_MARGIN = 5,
#else //temp value
		TIME_FONT_SIZE = 58,
		AMPM_FONT_SIZE = 18,
		AMPM_START_MARGIN = 5,
#endif
		TIME_TOTAL
	};
  
protected:
	virtual void onInit(void);
	
private:
	VfxU8 m_hour;
	VfxU8 m_min;
	VfxU8 m_szTime;
	VfxU8 m_szAmpm;
	VfxTextFrame *m_time;
	VfxTextFrame *m_ampm;
};

#endif /* __VAPP_ALARM_CLOCK_H__ */

