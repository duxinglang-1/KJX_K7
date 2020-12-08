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
 *  vcp_time_picker.cpp
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Time picker component
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
extern "C"
{
    #include "GlobalResDef.h"
}

#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vcp_time_picker.h"
#include "mmi_rp_srv_venus_component_base_picker_def.h"
#include "mmi_rp_srv_venus_component_time_picker_def.h"
#include "vfx_date_time.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/



static const VfxWChar *vcpTimePickerModes[3] = 
{
    (const VfxWChar *)L"AM",
    (const VfxWChar *)L"PM",
    (const VfxWChar *)L""
};
/***************************************************************************** 
 * Class VcpTimePicker 
 *****************************************************************************/  
VFX_IMPLEMENT_CLASS("VcpTimePicker", VcpTimePicker, VcpBasePicker);

VcpTimePicker::VcpTimePicker():
    m_is24HourView(VFX_FALSE)
{
    m_currTime.hour = 0;
    m_currTime.minute = 0;

    m_minTime.hour = 0;
    m_minTime.minute = 0;

    m_maxTime.hour = 23;
    m_maxTime.minute = 59;
}


void VcpTimePicker::onInit()
{
    VcpBasePicker::onInit();

    setAutoAnimate(VFX_TRUE);

    setBounds(0, 0, VCP_TIME_PICKER_WIDTH, VCP_TIME_PICKER_HEIGHT);
    m_signalBoundsChanged.connect(this,&VcpTimePicker::onBoundsChanged);
    setFieldCount(VCP_TIME_PICKER_FIELD_TOTAL);
    setFieldCellHeight(VCP_TIME_PICKER_CELL_HEIGHT);
    setBackground(VfxImageSrc(VCP_IMG_BASE_PICKER_BG));

    setContentProvider(this);
#if 0  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	resetLayout();
	VfxFontDesc fontDesc(VFX_FONT_DESC_VF_SIZE(VCP_TIME_PICKER_TEXT_FONT_SIZE));
	VfxFontDesc fontDesc2(VFX_FONT_DESC_VF_SIZE(VCP_TIME_PICKER_UNIT_FONT_SIZE));
	VfxFontDesc fontDesc3(VFX_FONT_DESC_VF_SIZE(VCP_TIME_PICKER_FOCUS_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FE1_8);

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
	tempFieldInfo.textColor = VCP_TIME_PICKER_TEXT_FONT_COLOR;	
	tempFieldInfo.focusTextColor = VCP_TIME_PICKER_FOCUS_FONT_COLOR;	
	tempFieldInfo.unitTextColor = VCP_TIME_PICKER_UNIT_FONT_COLOR;	
#endif
#endif

	tempFieldInfo.unitTextVisible = VFX_TRUE;	
	setFieldInfo(tempFieldInfo);

    tempFieldInfo.index = 0;
    tempFieldInfo.unitTextString = VFX_WSTR_RES(VCP_STR_TIME_PICKER_HOURS);    
    setFieldInfo(tempFieldInfo);

    tempFieldInfo.index = 1;
    tempFieldInfo.unitTextString = VFX_WSTR_RES(VCP_STR_TIME_PICKER_MINUTES);    
    setFieldInfo(tempFieldInfo);

    tempFieldInfo.index = 2;
    tempFieldInfo.isDataLoop = VFX_FALSE;
    tempFieldInfo.unitTextVisible = VFX_FALSE;
    tempFieldInfo.unitTextString = VFX_WSTR_NULL;    
    setFieldInfo(tempFieldInfo);  

    // Sets the current system time
    setCurrTime();
}


void VcpTimePicker::onBoundsChanged(VfxFrame *frame, const VfxRect &old)
{
    setBounds(0, 0, VCP_TIME_PICKER_WIDTH, VCP_TIME_PICKER_HEIGHT);
}


VfxS32 VcpTimePicker::getFieldCellCount(VfxS32 field)
{
    if (field == VCP_TIME_PICKER_FIELD_HOURS)
    {
        if(m_is24HourView)
        {
            return 24;        
        }
        else
        {
            return 12;        
        }
    }
    else if (field == VCP_TIME_PICKER_FIELD_MINUTES)
    {
        return 60;
    }
    else    // field == VCP_TIME_PICKER_FIELD_AMPM
    {
        if(m_is24HourView)
        {
            return 0;        
        }
        else
        {
            return 2;        
        }
    }
}


VfxWString VcpTimePicker::onGetFieldString(VfxS32 field, VfxS32 cell)
{
	VfxWChar tempStr[10] = {0,};

    if (field == VCP_TIME_PICKER_FIELD_HOURS)
    {
        if(m_is24HourView)
        {
			kal_wsprintf(tempStr,"%d",cell);
			return VFX_WSTR_MEM(tempStr);
        }
        else
        {
			if (cell == 0)
			{
				kal_wsprintf(tempStr,"%d",12);
			}
			else
			{
				kal_wsprintf(tempStr,"%d",cell);
			}
			return VFX_WSTR_MEM(tempStr);
        }
    }
    else if (field == VCP_TIME_PICKER_FIELD_MINUTES)
    {
		kal_wsprintf(tempStr,"%d",cell);
		return VFX_WSTR_MEM(tempStr);
			
    }
    else    // field == VCP_TIME_PICKER_FIELD_AMPM
    {
        if(m_is24HourView)
        {
            return VFX_WSTR_STATIC(vcpTimePickerModes[2]);
        }
        else
        {
            return VFX_WSTR_STATIC(vcpTimePickerModes[cell]);
        }
    }
}


void VcpTimePicker::onFieldFocusIndexChange(VfxS32 field, VfxS32 focusItem, VfxS32 previousFocusItem)
{
    VcpTimePickerStruct curr_time;
    curr_time = getTime();    
    
    if (field == VCP_TIME_PICKER_FIELD_HOURS)
    {
        // Emit the signal
        if(!m_is24HourView)
        {
            VfxU8 curr_m = getFieldFocus(VCP_TIME_PICKER_FIELD_AMPM);
            curr_time.hour = 12 * curr_m + focusItem;
        }
        else
        {
            curr_time.hour = focusItem;
        }
    }
    else if (field == VCP_TIME_PICKER_FIELD_MINUTES)
    {
        // Emit the signal
        curr_time.minute = focusItem;
    }
    else // field == VCP_TIME_PICKER_FIELD_AMPM
    {
        if(!m_is24HourView)
        {
            curr_time.hour = focusItem ? curr_time.hour + 12 : curr_time.hour - 12;
        }
    }
    if((curr_time.hour * 60 + curr_time.minute) <= (m_maxTime.hour * 60 + m_maxTime.minute) &&
       (curr_time.hour * 60 + curr_time.minute) >= (m_minTime.hour * 60 + m_minTime.minute))
    {
        m_currTime = curr_time;
        m_signalOnTimeChanged.emit(this, &curr_time);
    }
    else
    {
        //Set the old time cause its out of boundary
    }
}


void VcpTimePicker::onSetTranslucent(VfxBool translucent)
{
    setOpacity(translucent ? 0.5f : 1.0f);
}


void VcpTimePicker::setTime(const VcpTimePickerStruct &time)
{
    if((time.hour * 60 + time.minute) <= (m_maxTime.hour * 60 + m_maxTime.minute) &&
       (time.hour * 60 + time.minute) >= (m_minTime.hour * 60 + m_minTime.minute))
    {
        m_currTime = time;
        updateTime();
    }
}


void VcpTimePicker::setCurrTime()
{
    VcpTimePickerStruct curr_time;
    VfxDateTime curTime;
    curTime.setCurrentTime();
    curr_time.hour = curTime.getHour();
    curr_time.minute = curTime.getMinute();
    setTime(curr_time);
}


void VcpTimePicker::setMinTime(const VcpTimePickerStruct &time)
{
    if((time.hour < 24 && time.minute < 60) && 
        (time.hour * 60 + time.minute) < (m_maxTime.hour * 60 + m_maxTime.minute))
    {
        m_minTime = time;
        updateTime();
    }
}


void VcpTimePicker::setMaxTime(const VcpTimePickerStruct &time)
{
    if((time.hour < 24 && time.minute < 60) && 
        (time.hour * 60 + time.minute) > (m_minTime.hour * 60 + m_minTime.minute))
    {
        m_maxTime = time;
        updateTime();
    }
}


void VcpTimePicker::setIs24HourView(VfxBool mode)
{
    if(m_is24HourView != mode)
    {
        m_is24HourView = mode;
        resetLayout();
        updateTime();
    }
}


const VcpTimePickerStruct &VcpTimePicker::getTime() const
{
    return m_currTime;
}


const VcpTimePickerStruct &VcpTimePicker::getMinTime() const
{
    return m_maxTime;
}


const VcpTimePickerStruct &VcpTimePicker::getMaxTime() const
{
    return m_maxTime;
}


VfxBool VcpTimePicker::getIs24HourView()
{
    return m_is24HourView;
}


void VcpTimePicker::updateTime(void)
{
    if(m_is24HourView)
    {
        setFieldFocus(VCP_TIME_PICKER_FIELD_HOURS, m_currTime.hour);
        setFieldFocus(VCP_TIME_PICKER_FIELD_MINUTES, m_currTime.minute);
    }
    else
    {
        setFieldFocus(VCP_TIME_PICKER_FIELD_AMPM, m_currTime.hour < 12 ? 0 : 1);
        setFieldFocus(VCP_TIME_PICKER_FIELD_HOURS, m_currTime.hour < 12 ? m_currTime.hour : m_currTime.hour - 12);
        setFieldFocus(VCP_TIME_PICKER_FIELD_MINUTES, m_currTime.minute);
    }
}

    
void VcpTimePicker::resetLayout(void)
{
	VfxS32 x1, y1, w, h;
	setFieldBackgroundImage(VCP_TIME_PICKER_FIELD_HOURS, VfxImageSrc(VCP_IMG_BASE_PICKER_FIELD_BG));
	setFieldBackgroundImage(VCP_TIME_PICKER_FIELD_MINUTES, VfxImageSrc(VCP_IMG_BASE_PICKER_FIELD_BG));
	setFieldBackgroundImage(VCP_TIME_PICKER_FIELD_AMPM, VfxImageSrc(VCP_IMG_BASE_PICKER_FIELD_BG));
	setBackground(VfxImageSrc(VCP_IMG_BASE_PICKER_BG));

	if(m_is24HourView)
    {
        setFieldCount(VCP_TIME_PICKER_FIELD_TOTAL - 1);
        // Title
        // Hours
        x1 = VCP_TIME_PICKER_START_X;
        y1 = VCP_TIME_PICKER_START_Y;
        w = VCP_TIME_PICKER_CELL_HOURS_WIDTH_EX;
        h = VCP_TIME_PICKER_TEXT_FONT_SIZE;
        setUnitTextRect(VCP_TIME_PICKER_FIELD_HOURS, VfxRect(x1, y1, w, h));

        // Minutes
        x1 += VCP_TIME_PICKER_CELL_HOURS_WIDTH_EX + VCP_TIME_PICKER_START_X_GAP;
        w = VCP_TIME_PICKER_CELL_MINUTES_WIDTH_EX;
        setUnitTextRect(VCP_TIME_PICKER_FIELD_MINUTES, VfxRect(x1, y1, w, h));

        // Field
        // Hours
        x1 = VCP_TIME_PICKER_START_X;
        y1 = VCP_TIME_PICKER_START_Y + VCP_TIME_PICKER_TEXT_FONT_SIZE + VCP_TIME_PICKER_START_Y_GAP;
        w = VCP_TIME_PICKER_CELL_HOURS_WIDTH_EX;
        h = VCP_TIME_PICKER_HEIGHT - y1 - VCP_TIME_PICKER_START_Y_BOTTOM;
        setFieldCellRect(VCP_TIME_PICKER_FIELD_HOURS, VfxRect(x1, y1, w, h));

        // Minutes
        x1 += VCP_TIME_PICKER_CELL_HOURS_WIDTH_EX + VCP_TIME_PICKER_START_X_GAP;
        w = VCP_TIME_PICKER_CELL_MINUTES_WIDTH_EX;
        setFieldCellRect(VCP_TIME_PICKER_FIELD_MINUTES, VfxRect(x1, y1, w, h));
    }
    else
    {
        setFieldCount(VCP_TIME_PICKER_FIELD_TOTAL);

        // Title
        // Hours
        x1 = VCP_TIME_PICKER_START_X;
        y1 = VCP_TIME_PICKER_START_Y;
        w = VCP_TIME_PICKER_CELL_HOURS_WIDTH;
        h = VCP_TIME_PICKER_TEXT_FONT_SIZE;
        setUnitTextRect(VCP_TIME_PICKER_FIELD_HOURS, VfxRect(x1, y1, w, h));

        // Minutes
        x1 += VCP_TIME_PICKER_CELL_HOURS_WIDTH + VCP_TIME_PICKER_START_X_GAP;
        w = VCP_TIME_PICKER_CELL_MINUTES_WIDTH;
        setUnitTextRect(VCP_TIME_PICKER_FIELD_MINUTES, VfxRect(x1, y1, w, h));

        // AMPM
        x1 += VCP_TIME_PICKER_CELL_MINUTES_WIDTH + VCP_TIME_PICKER_START_X_GAP;
        w = VCP_TIME_PICKER_CELL_MODE_WIDTH;
        setUnitTextRect(VCP_TIME_PICKER_FIELD_AMPM, VfxRect(x1, y1, w, h));

        // Field
        // Hours
        x1 = VCP_TIME_PICKER_START_X;
        y1 = VCP_TIME_PICKER_START_Y + VCP_TIME_PICKER_TEXT_FONT_SIZE + VCP_TIME_PICKER_START_Y_GAP;
        w = VCP_TIME_PICKER_CELL_HOURS_WIDTH;
        h = VCP_TIME_PICKER_HEIGHT - y1 - VCP_TIME_PICKER_START_Y_BOTTOM;
        setFieldCellRect(VCP_TIME_PICKER_FIELD_HOURS, VfxRect(x1, y1, w, h));

        // Minutes
        x1 += VCP_TIME_PICKER_CELL_HOURS_WIDTH + VCP_TIME_PICKER_START_X_GAP;
        w = VCP_TIME_PICKER_CELL_MINUTES_WIDTH;
        setFieldCellRect(VCP_TIME_PICKER_FIELD_MINUTES, VfxRect(x1, y1, w, h));

        // AMPM
        x1 += VCP_TIME_PICKER_CELL_MINUTES_WIDTH + VCP_TIME_PICKER_START_X_GAP;
        w = VCP_TIME_PICKER_CELL_MODE_WIDTH;
        setFieldCellRect(VCP_TIME_PICKER_FIELD_AMPM, VfxRect(x1, y1, w, h));
    }
    VcpBasePicker::checkUpdate();
}

