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
 *  vcp_date_picker.cpp
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Date picker component
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
#include "vcp_date_picker.h"
#include "mmi_rp_srv_venus_component_base_picker_def.h"
#include "mmi_rp_srv_venus_component_date_picker_def.h"
#include "vfx_date_time.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Class VcpDatePicker 
 *****************************************************************************/  
VFX_IMPLEMENT_CLASS("VcpDatePicker", VcpDatePicker, VcpBasePicker);

VcpDatePicker::VcpDatePicker(VfxU16 min_year, VfxU16 max_year):
				m_format(VCP_DATE_PICKER_FORMAT_DDMMYYYY),
                m_isInReset(VFX_FALSE)
{
	intialize(min_year, max_year);
}

VcpDatePicker::VcpDatePicker():
    m_format(VCP_DATE_PICKER_FORMAT_DDMMYYYY)
{
    intialize(VCP_DATE_PICKER_YEAR_VALUE_MIN, VCP_DATE_PICKER_YEAR_VALUE_MAX);	
}

void VcpDatePicker::intialize(VfxU32 min_year, VfxU32 max_year)
{
    m_currDate.year = 0;
    m_currDate.month = 0;
    m_currDate.day = 0;

    m_minDate.year = min_year;
    m_minDate.month = 1;
    m_minDate.day = 1;

    m_maxDate.year = max_year;
    m_maxDate.month = 12;
    m_maxDate.day = 31;
}


void VcpDatePicker::onInit()
{
    VcpBasePicker::onInit();

    setAutoAnimate(VFX_TRUE);

    setBounds(0, 0, VCP_DATE_PICKER_WIDTH, VCP_DATE_PICKER_HEIGHT);
    m_signalBoundsChanged.connect(this,&VcpDatePicker::onBoundsChanged);
    setFieldCount(VCP_DATE_PICKER_FIELD_TOTAL);
    setFieldCellHeight(VCP_DATE_PICKER_CELL_HEIGHT);

    setFieldBackgroundImage(0, VfxImageSrc(VCP_IMG_BASE_PICKER_FIELD_BG));
    setFieldBackgroundImage(1, VfxImageSrc(VCP_IMG_BASE_PICKER_FIELD_BG));
    setFieldBackgroundImage(2, VfxImageSrc(VCP_IMG_BASE_PICKER_FIELD_BG));
    setContentProvider(this);

	resetLayout();

    // Sets the current system date
    setCurrDate();
}



void VcpDatePicker::onBoundsChanged(VfxFrame *frame, const VfxRect &old)
{
    setBounds(0, 0, VCP_DATE_PICKER_WIDTH, VCP_DATE_PICKER_HEIGHT);
}


VfxS32 VcpDatePicker::getFieldCellCount(VfxS32 field)
{
    VfxS32 fieldOfMonth = 1; // VCP_DATE_PICKER_FORMAT_DDMMYYYY
    VfxS32 fieldOfYear = 2;

    switch(m_format)
    {
        // case "VCP_DATE_PICKER_FORMAT_DDMMYYYY" already handled because no mapping is required. 
        case VCP_DATE_PICKER_FORMAT_MMDDYYYY : 
        {
            fieldOfMonth = 0;
            if(field == 2)
            {
                field = VCP_DATE_PICKER_FIELD_YEARS;
            }
            else if(field == 1)
            {
                field = VCP_DATE_PICKER_FIELD_DAYS;
            }
            else
            {
                field = VCP_DATE_PICKER_FIELD_MONTHS;
            }
            break;
        }
        case VCP_DATE_PICKER_FORMAT_YYYYMMDD : 
        {
            fieldOfYear = 0;
            if(field == 2)
            {
                field = VCP_DATE_PICKER_FIELD_DAYS;
            }
            else if(field == 1)
            {
                field = VCP_DATE_PICKER_FIELD_MONTHS;
            }
            else
            {
                field = VCP_DATE_PICKER_FIELD_YEARS;
            }
            break;
        }
        default : 
        {
            break;
        }
    }

    if (field == VCP_DATE_PICKER_FIELD_YEARS)
    {
        return (m_maxDate.year - m_minDate.year + 1);
    }
    else if (field == VCP_DATE_PICKER_FIELD_MONTHS)
    {
        return 12;
    }
    else    // field == VCP_DATE_PICKER_FIELD_DAYS
    {
        VfxU8 curr_month = getFieldFocus(fieldOfMonth);
        VfxU16 curr_year = getFieldFocus(fieldOfYear) + m_minDate.year;
        VfxU8 n_day = calculateDayOfMonth(curr_month, curr_year);
        if(m_currDate.day > n_day)
        {
            m_currDate.day = n_day;
        }
        return n_day;
    }
}


VfxWString VcpDatePicker::onGetFieldString(VfxS32 field, VfxS32 cell)
{
	VfxWChar tempStr[10] = {0,};

    switch(m_format)
    {
        // case "VCP_DATE_PICKER_FORMAT_DDMMYYYY" already handled because no mapping is required. 
        case VCP_DATE_PICKER_FORMAT_MMDDYYYY : 
        {
            if(field == 2)
            {
                field = VCP_DATE_PICKER_FIELD_YEARS;
            }
            else if(field == 1)
            {
                field = VCP_DATE_PICKER_FIELD_DAYS;
            }
            else
            {
                field = VCP_DATE_PICKER_FIELD_MONTHS;
            }
            break;
        }
        case VCP_DATE_PICKER_FORMAT_YYYYMMDD : 
        {
            if(field == 2)
            {
                field = VCP_DATE_PICKER_FIELD_DAYS;
            }
            else if(field == 1)
            {
                field = VCP_DATE_PICKER_FIELD_MONTHS;
            }
            else
            {
                field = VCP_DATE_PICKER_FIELD_YEARS;
            }
            break;
        }
        default : 
        {
            break;
        }
    }
    
    if (field == VCP_DATE_PICKER_FIELD_YEARS)
    {
        VfxS32 year = m_minDate.year + cell;
		kal_wsprintf(tempStr,"%d",year);
		return VFX_WSTR_MEM(tempStr);
					
		//return VFX_WSTR_STATIC(vcpDatePickerYear[(m_minDate.year - VCP_DATE_PICKER_YEAR_VALUE_MIN) + cell]);  
    }
    else if (field == VCP_DATE_PICKER_FIELD_MONTHS)
    {
		if ((cell + 1) < 10)
		{
			tempStr[0] = '0';
			kal_wsprintf(tempStr + 1,"%d",cell + 1);
		}
		else
		{
			kal_wsprintf(tempStr,"%d",cell + 1);
		}
		return VFX_WSTR_MEM(tempStr);
    }
    else    // field == VCP_DATE_PICKER_FIELD_DAYS
    {
        if ((cell + 1) < 10)
		{
			tempStr[0] = '0';
			kal_wsprintf(tempStr + 1,"%d",cell + 1);
		}
		else
		{
			kal_wsprintf(tempStr,"%d",cell + 1);
		}
		return VFX_WSTR_MEM(tempStr);
    }
}


void VcpDatePicker::onFieldFocusIndexChange(VfxS32 field, VfxS32 focusItem, VfxS32 previousFocusItem)
{
    VcpDatePickerStruct curr_date;
    curr_date = getDate();    
   // VfxS32 fieldOfDay = 0; // VCP_DATE_PICKER_FORMAT_DDMMYYYY
    VfxS32 previousMaxDay = calculateDayOfMonth(curr_date.month - 1, curr_date.year);
	VfxBool needToReset = VFX_FALSE;

    if (m_isInReset)
	{
        return;
	}

    switch(m_format)
    {
        // case "VCP_DATE_PICKER_FORMAT_DDMMYYYY" already handled because no mapping is required. 
        case VCP_DATE_PICKER_FORMAT_MMDDYYYY : 
        {
           // fieldOfDay = 1;
            if(field == 2)
            {
                field = VCP_DATE_PICKER_FIELD_YEARS;
            }
            else if(field == 1)
            {
                field = VCP_DATE_PICKER_FIELD_DAYS;
            }
            else
            {
                field = VCP_DATE_PICKER_FIELD_MONTHS;
            }
            break;
        }
        case VCP_DATE_PICKER_FORMAT_YYYYMMDD : 
        {
            //fieldOfDay = 2;
            if(field == 2)
            {
                field = VCP_DATE_PICKER_FIELD_DAYS;
            }
            else if(field == 1)
            {
                field = VCP_DATE_PICKER_FIELD_MONTHS;
            }
            else
            {
                field = VCP_DATE_PICKER_FIELD_YEARS;
            }
            break;
        }
        default : 
        {
            break;
        }
    }
    
    if (field == VCP_DATE_PICKER_FIELD_YEARS)
    {
        curr_date.year = focusItem + m_minDate.year;
        VfxU8 n_day = calculateDayOfMonth(curr_date.month - 1, curr_date.year);
	

		if(n_day != previousMaxDay)
		{
			if(curr_date.day > n_day)
			{
				curr_date.day = n_day;
			}
			//setFieldFocus(fieldOfDay, curr_date.day - 1, 0);			
			//vfxPostInvoke0(this,&VcpDatePicker::updateDayFieldCound);
			needToReset = VFX_TRUE;
        }
    }
    else if (field == VCP_DATE_PICKER_FIELD_MONTHS)
    {
        curr_date.month = focusItem + 1;
        VfxU8 n_day = calculateDayOfMonth(focusItem, curr_date.year);
       if(n_day != previousMaxDay)
        {
        if(curr_date.day > n_day)
        {
            curr_date.day = n_day;
        }
         //   setFieldFocus(fieldOfDay, curr_date.day - 1, 0);
			//updateDayFieldCound();
			//vfxPostInvoke0(this,&VcpDatePicker::updateDayFieldCound);
			needToReset = VFX_TRUE;
        }

    }
    else // field == VCP_DATE_PICKER_FIELD_DAYS
    {
        curr_date.day = focusItem + 1;
    }

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
    #endif
    // If the date is not in the boundary, change it. 
    if(((curr_date.year > m_minDate.year) ||                                                       // Year is later than the minDate
        ((curr_date.year == m_minDate.year) && ((curr_date.month > m_minDate.month) ||             // Month is later than the minDate
            ((curr_date.month == m_minDate.month) && (curr_date.day >= m_minDate.day)))))          // Day is later than the minDate
     && ((curr_date.year < m_maxDate.year) ||                                                      // Year is former than the maxDate
        ((curr_date.year == m_maxDate.year) && ((curr_date.month < m_maxDate.month) ||             // Month is former than the maxDate
            ((curr_date.month == m_maxDate.month) && (curr_date.day <= m_maxDate.day))))))         // Day is former than the maxDate
    {
        m_currDate = curr_date;
		if (needToReset)
		{
			updateDayFieldCount();
		}
        m_signalOnDateChanged.emit(this, &curr_date);
    }
    else
    {
        //Set the old time because its out of boundary. Using postInvoke() so the animation is completed first.
        vfxPostInvoke0(this,&VcpDatePicker::updateDate);
        //updateDate();
    }
}


void VcpDatePicker::onSetTranslucent(VfxBool translucent)
{
    setOpacity(translucent ? 0.5f : 1.0f);
}


void VcpDatePicker::setDate(const VcpDatePickerStruct &date)
{
    if(!((date.year == m_currDate.year) &&                                                   // Date is changed
       (date.month == m_currDate.month) &&                                                  // 
       (date.day == m_currDate.day)))                                                        // 
    if((date.year > m_minDate.year) ||                                                      // Year is later than the minDate
        ((date.year == m_minDate.year) && ((date.month > m_minDate.month) ||                // Month is later than the minDate
            ((date.month == m_minDate.month) && (date.day >= m_minDate.day)))))              // Day is later than the minDate
    if((date.year < m_maxDate.year) ||                                                      // Year is former than the maxDate
        ((date.year == m_maxDate.year) && ((date.month < m_maxDate.month) ||                // Month is former than the maxDate
            ((date.month == m_maxDate.month) && (date.day <= m_maxDate.day)))))              // Day is former than the maxDate
    {
        m_currDate = date;
        updateDate();
    }
}


void VcpDatePicker::setFormat(VcpDatePickerFormatEnum format)
{
    if(m_format != format)
    {
        m_format = format;
        resetLayout();
    }
}


void VcpDatePicker::setCurrDate()
{
    VfxDateTime curDate;
    VcpDatePickerStruct curr_date;

    curDate.setCurrentTime();
    curr_date.month = curDate.getMonth();
    curr_date.year = curDate.getYear();
    curr_date.day = curDate.getDay();

    setDate(curr_date);
}


void VcpDatePicker::setMinDate(const VcpDatePickerStruct &date)
{
    if((date.year > m_minDate.year) ||                                                      // Year is later than the minDate
        ((date.year == m_minDate.year) && ((date.month > m_minDate.month) ||                // Month is later than the minDate
            ((date.month == m_minDate.month) && (date.day >= m_minDate.day)))))             // Day is later than the minDate
    {
        m_minDate = date;
        // Update the date when its not inside the new boundary
        updateDate();
    }
}


void VcpDatePicker::setMaxDate(const VcpDatePickerStruct &date)
{
    if((date.year < m_maxDate.year) ||                                                      // Year is former than the maxDate
        ((date.year == m_maxDate.year) && ((date.month < m_maxDate.month) ||                // Month is former than the maxDate
            ((date.month == m_maxDate.month) && (date.day <= m_maxDate.day)))))             // Day is former than the maxDate
    {
        m_maxDate = date;
        // Update the date when its not inside the new boundary
        updateDate();
    }
}


const VcpDatePickerStruct &VcpDatePicker::getDate() const
{
    return m_currDate;
}


const VcpDatePickerStruct &VcpDatePicker::getMinDate() const
{
    return m_minDate;
}


const VcpDatePickerStruct &VcpDatePicker::getMaxDate() const
{
    return m_maxDate;
}

void VcpDatePicker::updateDayFieldCount(void)
{
	VfxS32 dayField = VCP_DATE_PICKER_FIELD_DAYS;
	
	switch(m_format)
    {        
        case VCP_DATE_PICKER_FORMAT_MMDDYYYY : 
        {
            dayField = VCP_DATE_PICKER_FIELD_MONTHS;
			break;     
        }
        case VCP_DATE_PICKER_FORMAT_YYYYMMDD : 
        {
            dayField = VCP_DATE_PICKER_FIELD_YEARS;         
            break;    
        }
        default : 
        {
        }
    }

	resetFieldCells(dayField); 

    setFieldFocus(dayField, m_currDate.day - 1, 0);
 //   setFieldFocus(f2, m_currDate.month - 1, 0);
  //  setFieldFocus(f3, m_currDate.year - m_minDate.year, 0);

}
void VcpDatePicker::updateDate(void)
{
    VfxS32 f1, f2, f3;
    // Warninfg removal for case VCP_DATE_PICKER_FORMAT_DDMMYYYY : 
    f1 = VCP_DATE_PICKER_FIELD_DAYS;
    f2 = VCP_DATE_PICKER_FIELD_MONTHS;
    f3 = VCP_DATE_PICKER_FIELD_YEARS;

    switch(m_format)
    {
        // Already handled "case VCP_DATE_PICKER_FORMAT_DDMMYYYY"
        case VCP_DATE_PICKER_FORMAT_MMDDYYYY : 
        {
            f1 = VCP_DATE_PICKER_FIELD_MONTHS;
            f2 = VCP_DATE_PICKER_FIELD_DAYS;
            f3 = VCP_DATE_PICKER_FIELD_YEARS;
            break;    
        }
        case VCP_DATE_PICKER_FORMAT_YYYYMMDD : 
        {
            f1 = VCP_DATE_PICKER_FIELD_YEARS;
            f2 = VCP_DATE_PICKER_FIELD_MONTHS;
            f3 = VCP_DATE_PICKER_FIELD_DAYS;
            break;    
        }
        default : 
        {
        }
    }

    setFieldFocus(f1, m_currDate.day - 1);
    setFieldFocus(f2, m_currDate.month - 1);
    setFieldFocus(f3, m_currDate.year - m_minDate.year);
    //VcpBasePicker::checkUpdate();
}


void VcpDatePicker::resetLayout(void)
{
	VfxS32 x1, y1, w, h;
	VcpBasePickerFieldInfo tempFieldInfo;

	VfxFontDesc fontDesc(VFX_FONT_DESC_VF_SIZE(VCP_DATE_PICKER_TEXT_FONT_SIZE));
	VfxFontDesc fontDesc2(VFX_FONT_DESC_VF_SIZE(VCP_DATE_PICKER_UNIT_FONT_SIZE));
	VfxFontDesc fontDesc3(VFX_FONT_DESC_VF_SIZE(VCP_DATE_PICKER_FOCUS_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FE1_8);
	
    tempFieldInfo.isDataLoop = VFX_TRUE;
#ifndef __MMI_VUI_COSMOS_CP_SLIM__
#ifdef __MMI_VUI_COSMOS_CP__
    tempFieldInfo.textColor = VFX_COLOR_RES(CLR_COSMOS_BASE_PICKER_TXT);
    tempFieldInfo.focusTextColor = VFX_COLOR_RES(CLR_COSMOS_BASE_PICKER_FOCUS_TXT);    
	tempFieldInfo.unitTextColor = VFX_COLOR_RES(CLR_COSMOS_BASE_PICKER_UNIT_TXT);
#else
	tempFieldInfo.textColor = VCP_DATE_PICKER_TEXT_FONT_COLOR;
    tempFieldInfo.focusTextColor = VCP_DATE_PICKER_FOCUS_FONT_COLOR;    
	tempFieldInfo.unitTextColor = VCP_DATE_PICKER_UNIT_FONT_COLOR;    
#endif
#endif
	tempFieldInfo.focusTextFont = fontDesc3;
    tempFieldInfo.textFont = fontDesc2;
    tempFieldInfo.unitTextVisible = VFX_TRUE;
    tempFieldInfo.unitTextFont = fontDesc;
	
	setBackground(VfxImageSrc(VCP_IMG_BASE_PICKER_BG));
	m_isInReset = VFX_TRUE;
    switch(m_format)
    {
        case VCP_DATE_PICKER_FORMAT_DDMMYYYY : 
        {
            // Title
            // Day
            x1 = VCP_DATE_PICKER_START_X;
            y1 = VCP_DATE_PICKER_START_Y;
            w = VCP_DATE_PICKER_CELL_DAY_WIDTH;
            h = VCP_DATE_PICKER_TEXT_FONT_SIZE;
            setUnitTextRect(0, VfxRect(x1, y1, w, h));

            // Month
            x1 += VCP_DATE_PICKER_CELL_DAY_WIDTH + VCP_DATE_PICKER_START_X_GAP;
            w = VCP_DATE_PICKER_CELL_MONTH_WIDTH;
            setUnitTextRect(1, VfxRect(x1, y1, w, h));

            // Year
            x1 += VCP_DATE_PICKER_CELL_MONTH_WIDTH + VCP_DATE_PICKER_START_X_GAP;
            w = VCP_DATE_PICKER_CELL_YEAR_WIDTH;
            setUnitTextRect(2, VfxRect(x1, y1, w, h));

            // Field
            // Day
            x1 = VCP_DATE_PICKER_START_X;
            y1 = VCP_DATE_PICKER_START_Y + VCP_DATE_PICKER_TEXT_FONT_SIZE + VCP_DATE_PICKER_START_Y_GAP;
            w = VCP_DATE_PICKER_CELL_DAY_WIDTH;
            h = VCP_DATE_PICKER_HEIGHT - y1- VCP_DATE_PICKER_START_Y_BOTTOM;
            setFieldCellRect(0, VfxRect(x1, y1, w, h));

            // Month
            x1 += VCP_DATE_PICKER_CELL_DAY_WIDTH + VCP_DATE_PICKER_START_X_GAP;
            w = VCP_DATE_PICKER_CELL_MONTH_WIDTH;
            setFieldCellRect(1, VfxRect(x1, y1, w, h));

            // Year
            x1 += VCP_DATE_PICKER_CELL_MONTH_WIDTH + VCP_DATE_PICKER_START_X_GAP;
            w = VCP_DATE_PICKER_CELL_YEAR_WIDTH;
            setFieldCellRect(2, VfxRect(x1, y1, w, h));

            tempFieldInfo.index = 2;
            tempFieldInfo.focusIndex = m_currDate.year - m_minDate.year;
            tempFieldInfo.unitTextString = VFX_WSTR_RES(VCP_STR_DATE_PICKER_YEAR);
            setFieldInfo(tempFieldInfo);


            tempFieldInfo.index = 1;
            tempFieldInfo.focusIndex = m_currDate.month - 1;
            tempFieldInfo.unitTextString = VFX_WSTR_RES(VCP_STR_DATE_PICKER_MONTH);
            setFieldInfo(tempFieldInfo);


            tempFieldInfo.index = 0;
            tempFieldInfo.focusIndex = m_currDate.day - 1;
            tempFieldInfo.unitTextString = VFX_WSTR_RES(VCP_STR_DATE_PICKER_DAYS);
            setFieldInfo(tempFieldInfo);    

 
            break;
        }
        case VCP_DATE_PICKER_FORMAT_MMDDYYYY : 
        {
            VfxS32 x1, y1, w, h;

            // Title
            // Month
            x1 = VCP_DATE_PICKER_START_X;
            y1 = VCP_DATE_PICKER_START_Y;
            w = VCP_DATE_PICKER_CELL_MONTH_WIDTH;
            h = VCP_DATE_PICKER_TEXT_FONT_SIZE;
            setUnitTextRect(0, VfxRect(x1, y1, w, h));

            // Day
            x1 += VCP_DATE_PICKER_CELL_MONTH_WIDTH + VCP_DATE_PICKER_START_X_GAP;
            w = VCP_DATE_PICKER_CELL_DAY_WIDTH;
            setUnitTextRect(1, VfxRect(x1, y1, w, h));

            // Year
            x1 += VCP_DATE_PICKER_CELL_DAY_WIDTH + VCP_DATE_PICKER_START_X_GAP;
            w = VCP_DATE_PICKER_CELL_YEAR_WIDTH;
            setUnitTextRect(2, VfxRect(x1, y1, w, h));

            // Field
            // Month
            x1 = VCP_DATE_PICKER_START_X;
            y1 = VCP_DATE_PICKER_START_Y + VCP_DATE_PICKER_TEXT_FONT_SIZE + VCP_DATE_PICKER_START_Y_GAP;
            w = VCP_DATE_PICKER_CELL_MONTH_WIDTH;
            h = VCP_DATE_PICKER_HEIGHT - y1- VCP_DATE_PICKER_START_Y_BOTTOM;
            setFieldCellRect(0, VfxRect(x1, y1, w, h));

            // Day
            x1 += VCP_DATE_PICKER_CELL_MONTH_WIDTH + VCP_DATE_PICKER_START_X_GAP;
            w = VCP_DATE_PICKER_CELL_DAY_WIDTH;
            setFieldCellRect(1, VfxRect(x1, y1, w, h));

            // Year
            x1 += VCP_DATE_PICKER_CELL_DAY_WIDTH + VCP_DATE_PICKER_START_X_GAP;
            w = VCP_DATE_PICKER_CELL_YEAR_WIDTH;
            setFieldCellRect(2, VfxRect(x1, y1, w, h));

            setBackground(VfxImageSrc(VCP_IMG_BASE_PICKER_BG));

            tempFieldInfo.index = 0;
            tempFieldInfo.focusIndex = m_currDate.month - 1;
            tempFieldInfo.unitTextString = VFX_WSTR_RES(VCP_STR_DATE_PICKER_MONTH);
            setFieldInfo(tempFieldInfo);

            tempFieldInfo.index = 1;
            tempFieldInfo.focusIndex = m_currDate.day - 1;
            tempFieldInfo.unitTextString = VFX_WSTR_RES(VCP_STR_DATE_PICKER_DAYS);
            setFieldInfo(tempFieldInfo);

            tempFieldInfo.index = 2;
            tempFieldInfo.focusIndex = m_currDate.year - m_minDate.year;
            tempFieldInfo.unitTextString = VFX_WSTR_RES(VCP_STR_DATE_PICKER_YEAR);
            setFieldInfo(tempFieldInfo);    
            break;
        }
        case VCP_DATE_PICKER_FORMAT_YYYYMMDD : 
        {
            VfxS32 x1, y1, w, h;

            // Title
            // Year
            x1 = VCP_DATE_PICKER_START_X;
            y1 = VCP_DATE_PICKER_START_Y;
            w = VCP_DATE_PICKER_CELL_YEAR_WIDTH;
            h = VCP_DATE_PICKER_TEXT_FONT_SIZE;
            setUnitTextRect(0, VfxRect(x1, y1, w, h));

            // Month
            x1 += VCP_DATE_PICKER_CELL_YEAR_WIDTH + VCP_DATE_PICKER_START_X_GAP;
            w = VCP_DATE_PICKER_CELL_MONTH_WIDTH;
            setUnitTextRect(1, VfxRect(x1, y1, w, h));

            // Day
            x1 += VCP_DATE_PICKER_CELL_MONTH_WIDTH + VCP_DATE_PICKER_START_X_GAP;
            w = VCP_DATE_PICKER_CELL_DAY_WIDTH;
            setUnitTextRect(2, VfxRect(x1, y1, w, h));

            // Field
            // Year
            x1 = VCP_DATE_PICKER_START_X;
            y1 = VCP_DATE_PICKER_START_Y + VCP_DATE_PICKER_TEXT_FONT_SIZE + VCP_DATE_PICKER_START_Y_GAP;
            w = VCP_DATE_PICKER_CELL_YEAR_WIDTH;
            h = VCP_DATE_PICKER_HEIGHT - y1- VCP_DATE_PICKER_START_Y_BOTTOM;
            setFieldCellRect(0, VfxRect(x1, y1, w, h));

            // Month
            x1 += VCP_DATE_PICKER_CELL_YEAR_WIDTH + VCP_DATE_PICKER_START_X_GAP;
            w = VCP_DATE_PICKER_CELL_MONTH_WIDTH;
            setFieldCellRect(1, VfxRect(x1, y1, w, h));

            // Day
            x1 += VCP_DATE_PICKER_CELL_MONTH_WIDTH + VCP_DATE_PICKER_START_X_GAP;
            w = VCP_DATE_PICKER_CELL_DAY_WIDTH;
            setFieldCellRect(2, VfxRect(x1, y1, w, h));


            tempFieldInfo.index = 0;
            tempFieldInfo.focusIndex = m_currDate.year - m_minDate.year;
            tempFieldInfo.unitTextString = VFX_WSTR_RES(VCP_STR_DATE_PICKER_YEAR);
            setFieldInfo(tempFieldInfo);

            tempFieldInfo.index = 1;
            tempFieldInfo.focusIndex = m_currDate.month - 1;
            tempFieldInfo.unitTextString = VFX_WSTR_RES(VCP_STR_DATE_PICKER_MONTH);
            setFieldInfo(tempFieldInfo);

            tempFieldInfo.index = 2;
            tempFieldInfo.focusIndex = m_currDate.day - 1;
            tempFieldInfo.unitTextString = VFX_WSTR_RES(VCP_STR_DATE_PICKER_DAYS);
            setFieldInfo(tempFieldInfo);    
            break;
        }
        default : 
        {
        }
    }
    VcpBasePicker::checkUpdate();
    m_isInReset = VFX_FALSE;
}


