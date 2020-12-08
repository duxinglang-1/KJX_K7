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
 *  vcp_date_picker.h
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Date picker header
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_DATE_PICKER_H__
#define __VCP_DATE_PICKER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_base_picker.h"

#if defined(__MMI_VUI_COSMOS_CP__) 

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
// Coordinates
#ifdef __MMI_MAINLCD_480X800__
    #define VCP_DATE_PICKER_WIDTH                       (458)
    #define VCP_DATE_PICKER_HEIGHT                      (250)
    
    #define VCP_DATE_PICKER_CELL_HEIGHT                 (50)

    #define VCP_DATE_PICKER_TEXT_FONT_SIZE              (23)
    #define VCP_DATE_PICKER_TEXT_FONT_COLOR             VfxColor(255, 123, 123 , 123)

    #define VCP_DATE_PICKER_UNIT_FONT_SIZE              (33)
    #define VCP_DATE_PICKER_UNIT_FONT_COLOR             VfxColor(255, 255, 255 , 255)

    #define VCP_DATE_PICKER_FOCUS_FONT_SIZE             (45)
    #define VCP_DATE_PICKER_FOCUS_FONT_COLOR            VfxColor(255, 15, 15 , 15)

    #define VCP_DATE_PICKER_CELL_MONTH_WIDTH            (117)
    #define VCP_DATE_PICKER_CELL_DAY_WIDTH 	            (117)
    #define VCP_DATE_PICKER_CELL_YEAR_WIDTH             (178)

    #define VCP_DATE_PICKER_START_X                     (19)
    #define VCP_DATE_PICKER_START_X_GAP                 (4)
    #define VCP_DATE_PICKER_START_Y                     (13)
    #define VCP_DATE_PICKER_START_Y_GAP                 (12)
    #define VCP_DATE_PICKER_START_Y_BOTTOM              (12)
#elif defined(__MMI_MAINLCD_320X480__)
    #define VCP_DATE_PICKER_WIDTH                       (304)
    #define VCP_DATE_PICKER_HEIGHT                      (166)
    
    #define VCP_DATE_PICKER_CELL_HEIGHT                 (33)

    #define VCP_DATE_PICKER_TEXT_FONT_SIZE              (14)
    #define VCP_DATE_PICKER_TEXT_FONT_COLOR             VfxColor(255, 123, 123 , 123)

    #define VCP_DATE_PICKER_UNIT_FONT_SIZE              (22)
    #define VCP_DATE_PICKER_UNIT_FONT_COLOR             VfxColor(255, 255, 255 , 255)

    #define VCP_DATE_PICKER_FOCUS_FONT_SIZE             (30)
    #define VCP_DATE_PICKER_FOCUS_FONT_COLOR            VfxColor(255, 15, 15 , 15)

    #define VCP_DATE_PICKER_CELL_MONTH_WIDTH            (78)
    #define VCP_DATE_PICKER_CELL_DAY_WIDTH 	            (78)
    #define VCP_DATE_PICKER_CELL_YEAR_WIDTH             (118)

    #define VCP_DATE_PICKER_START_X                     (12)
    #define VCP_DATE_PICKER_START_X_GAP                 (3)
    #define VCP_DATE_PICKER_START_Y                     (9)
    #define VCP_DATE_PICKER_START_Y_GAP                 (8)
    #define VCP_DATE_PICKER_START_Y_BOTTOM              (8)
#elif defined(__MMI_MAINLCD_240X400__)
    #define VCP_DATE_PICKER_WIDTH                       (228)
    #define VCP_DATE_PICKER_HEIGHT                      (134)
    
    #define VCP_DATE_PICKER_CELL_HEIGHT                 (30)

    #define VCP_DATE_PICKER_TEXT_FONT_SIZE              (13)
    #define VCP_DATE_PICKER_TEXT_FONT_COLOR             VfxColor(255, 123, 123 , 123)

    #define VCP_DATE_PICKER_UNIT_FONT_SIZE              (16)
    #define VCP_DATE_PICKER_UNIT_FONT_COLOR             VfxColor(255, 255, 255 , 255)

    #define VCP_DATE_PICKER_FOCUS_FONT_SIZE             (22)
    #define VCP_DATE_PICKER_FOCUS_FONT_COLOR            VfxColor(255, 15, 15 , 15)

    #define VCP_DATE_PICKER_CELL_MONTH_WIDTH            (63)
    #define VCP_DATE_PICKER_CELL_DAY_WIDTH 	            (63)
    #define VCP_DATE_PICKER_CELL_YEAR_WIDTH             (82)

    #define VCP_DATE_PICKER_START_X                     (8)
    #define VCP_DATE_PICKER_START_X_GAP                 (2)
    #define VCP_DATE_PICKER_START_Y                     (8)
    #define VCP_DATE_PICKER_START_Y_GAP                 (7)
    #define VCP_DATE_PICKER_START_Y_BOTTOM              (8)
#elif defined(__MMI_MAINLCD_240X320__)
    #define VCP_DATE_PICKER_WIDTH                       (228)
    #define VCP_DATE_PICKER_HEIGHT                      (134)
    
    #define VCP_DATE_PICKER_CELL_HEIGHT                 (30)

    #define VCP_DATE_PICKER_TEXT_FONT_SIZE              (13)
    #define VCP_DATE_PICKER_TEXT_FONT_COLOR             VfxColor(255, 123, 123 , 123)

    #define VCP_DATE_PICKER_UNIT_FONT_SIZE              (16)
    #define VCP_DATE_PICKER_UNIT_FONT_COLOR             VfxColor(255, 255, 255 , 255)

    #define VCP_DATE_PICKER_FOCUS_FONT_SIZE             (22)
    #define VCP_DATE_PICKER_FOCUS_FONT_COLOR            VfxColor(255, 15, 15 , 15)

    #define VCP_DATE_PICKER_CELL_MONTH_WIDTH            (63)
    #define VCP_DATE_PICKER_CELL_DAY_WIDTH              (63)
    #define VCP_DATE_PICKER_CELL_YEAR_WIDTH             (82)

    #define VCP_DATE_PICKER_START_X                     (8)
    #define VCP_DATE_PICKER_START_X_GAP                 (2)
    #define VCP_DATE_PICKER_START_Y                     (8)
    #define VCP_DATE_PICKER_START_Y_GAP                 (7)
    #define VCP_DATE_PICKER_START_Y_BOTTOM              (8)
#else
    // Temp values
    #define VCP_DATE_PICKER_WIDTH                       (228)
    #define VCP_DATE_PICKER_HEIGHT                      (134)
    
    #define VCP_DATE_PICKER_CELL_HEIGHT                 (30)

    #define VCP_DATE_PICKER_TEXT_FONT_SIZE              (13)
    #define VCP_DATE_PICKER_TEXT_FONT_COLOR             VfxColor(255, 123, 123 , 123)

    #define VCP_DATE_PICKER_UNIT_FONT_SIZE              (16)
    #define VCP_DATE_PICKER_UNIT_FONT_COLOR             VfxColor(255, 255, 255 , 255)

    #define VCP_DATE_PICKER_FOCUS_FONT_SIZE             (22)
    #define VCP_DATE_PICKER_FOCUS_FONT_COLOR            VfxColor(255, 15, 15 , 15)

    #define VCP_DATE_PICKER_CELL_MONTH_WIDTH            (63)
    #define VCP_DATE_PICKER_CELL_DAY_WIDTH              (63)
    #define VCP_DATE_PICKER_CELL_YEAR_WIDTH             (82)

    #define VCP_DATE_PICKER_START_X                     (8)
    #define VCP_DATE_PICKER_START_X_GAP                 (2)
    #define VCP_DATE_PICKER_START_Y                     (8)
    #define VCP_DATE_PICKER_START_Y_GAP                 (7)
    #define VCP_DATE_PICKER_START_Y_BOTTOM              (8)
#endif

typedef enum
{
    VCP_DATE_PICKER_YEAR_VALUE_MIN = 1970,
    VCP_DATE_PICKER_YEAR_VALUE_MAX = 2030,
    VCP_DATE_PICKER_YEAR_VALUE_TOTAL
}VcpDatePickerYearValuesEnum;

typedef enum
{
    VCP_DATE_PICKER_FIELD_DAYS,
    VCP_DATE_PICKER_FIELD_MONTHS,
    VCP_DATE_PICKER_FIELD_YEARS,
    VCP_DATE_PICKER_FIELD_TOTAL
}VcpDatePickerFieldsEnum;

/* DOM-NOT_FOR_SDK-END */


//<group DOM_DatePicker_enum>
//This enums defines the supported date format
typedef enum
{
    VCP_DATE_PICKER_FORMAT_DDMMYYYY,	// DD/MM/YYYY
    VCP_DATE_PICKER_FORMAT_MMDDYYYY,	// MM/DD/YYYY
    VCP_DATE_PICKER_FORMAT_YYYYMMDD,	// YYYY/MM/DD
    VCP_DATE_PICKER_FORMAT_TOTAL
}VcpDatePickerFormatEnum;


/*
 * Structure to be used in XML
 ********************************************************
    <Struct name="VcpDatePickerStruct">
        <Member    name="years"       type="VfxU8"/>
        <Member    name="months"      type="VfxU8"/>
        <Member    name="days"      type="VfxU8"/>
    </Struct>
 ********************************************************
*/


//<group DOM_DatePicker_struct>
// This Structure is used to specify the date value.
struct VcpDatePickerStruct : public VfxBase
{
    VfxS32 year;	// Year
    VfxS32 month;	// Month of the year
    VfxS32 day;		// Day of the month
};

    inline VfxBool checkLeapYear(VfxU16 curr_year)
    {
        if(curr_year%400 == 0 || (curr_year%100 != 0 && curr_year%4 == 0)) return VFX_TRUE; else return VFX_FALSE;
    }

    inline VfxU8 calculateDayOfMonth(VfxU8 curr_month, VfxU16 curr_year)
    {
        if(curr_month == 0 ||
           curr_month == 2 ||
           curr_month == 4 ||
           curr_month == 6 ||
           curr_month == 7 ||
           curr_month == 9 ||
           curr_month == 11)
        {
            return 31;
        }
        else if(curr_month == 3 ||
           curr_month == 5 ||
           curr_month == 8 ||
           curr_month == 10)
        {
            return 30;
        }
        else    
        {
            // Check leap year for Feb
            if(checkLeapYear(curr_year))
            {
                return 29;
            }
            else
            {
                return 28;
            }
        }
    }


/*****************************************************************************
 * Class VcpDatePicker
 *****************************************************************************/
/*
 * VcpDatePicker - a Date Picker.
 *
 * EXAMPLE
 * <code>
 *  VcpDatePicker *dtpicker;
 *  VFX_OBJ_CREATE(dtpicker, VcpDatePicker, this);
 *  panel->setPos(75, 50); 
 * </code>
 */
class VcpDatePicker : public VcpBasePicker, public IVcpBasePickerContentProvider
{
    VFX_DECLARE_CLASS(VcpDatePicker);

// Constructor / Destructor
public:
    // <group DOM_DatePicker_VcpDatePicker_Constructor/Destructor>
    // Default constructor.
    VcpDatePicker();
	// <group DOM_DatePicker_VcpDatePicker_Constructor/Destructor>
    // constructor with minimum and maximum year range.
	VcpDatePicker(VfxU16 min_year, VfxU16 max_year);

public:
    // <group DOM_DatePicker_VcpDatePicker_Method>
    // To set the date value.
    void setDate(
        const VcpDatePickerStruct &date                // [IN]   XXX
    );

    // <group DOM_DatePicker_VcpDatePicker_Method>
    // To set the date format.
    void setFormat(
        VcpDatePickerFormatEnum format                 // [IN]   XXX
    );
    
    // <group DOM_DatePicker_VcpDatePicker_Method>
    // To set the date value equal to the current date of the system.
    void setCurrDate();

    // <group DOM_DatePicker_VcpDatePicker_Method>
    // To set the minimum limit for date value.
    void setMinDate(
        const VcpDatePickerStruct &date                // [IN]   XXX
    );

    // <group DOM_DatePicker_VcpDatePicker_Method>
    // To set maximum limit for date value.
    void setMaxDate(
        const VcpDatePickerStruct &date                // [IN]   XXX
    );

    // <group DOM_DatePicker_VcpDatePicker_Method>
    // To get the date value set in the date picker.
    const VcpDatePickerStruct &getDate() const;

    // <group DOM_DatePicker_VcpDatePicker_Method>
    // To get the minimum limit for date value.
    const VcpDatePickerStruct &getMinDate() const;

    // <group DOM_DatePicker_VcpDatePicker_Method>
    // To get the maximum limit for date value.
    const VcpDatePickerStruct &getMaxDate() const;

private:
    // <group DOM_DatePicker_VcpDatePicker_Implementation>
	// To intialize max and min date values
	void intialize(VfxU32 min_year, VfxU32 max_year);
    // <group DOM_DatePicker_VcpDatePicker_Implementation>
    // To reset the layout, when format changes.
    void resetLayout(void);

    // <group DOM_DatePicker_VcpDatePicker_Implementation>
    // Update the date value.
    void updateDate(void);
    // <group DOM_DatePicker_VcpDatePicker_Implementation>
    // Update field cell count
	void updateDayFieldCount(void);

    // <group DOM_DatePicker_VcpDatePicker_Implementation>
    // On Bound change.
    void onBoundsChanged(VfxFrame *frame, const VfxRect &old);


public:
    // <group DOM_DatePicker_VcpDatePicker_Event>
    // This is used to notify the application when date changes.
    // Application must register its handler with this slot.
    // This signal is emitted everytime user changes the date.
    VfxSignal2 < VfxObject*, VcpDatePickerStruct*> m_signalOnDateChanged;

protected:
    // <group DOM_DatePicker_VcpDatePicker_Override>
    // On Init.
    virtual void onInit();

    // <group DOM_DatePicker_VcpDatePicker_Override>
    // On changing the opicity.
    virtual void onSetTranslucent(VfxBool translucent);

    // <group DOM_DatePicker_VcpDatePicker_Override>
    // To get the cell count for a particulr field.
    // RETURN: Cell count
    virtual VfxS32 getFieldCellCount(VfxS32 field);

    // <group DOM_DatePicker_VcpDatePicker_Override>
    // To get the cell string for a particular field.
    // RETURN: String
    virtual VfxWString onGetFieldString(VfxS32 field, VfxS32 cell);

    // <group DOM_DatePicker_VcpDatePicker_Override>
    // This is called when focussed item is changed.
    // Sets the updated date value and notify the application about updated date value.
    virtual void onFieldFocusIndexChange(VfxS32 field, VfxS32 focusItem, VfxS32 previousFocusItem);

private:
    // <group DOM_DatePicker_VcpDatePicker_Property>
    // Current date value.
    VcpDatePickerStruct m_currDate;
    
    // <group DOM_DatePicker_VcpDatePicker_Property>
    // Minimum limit for date value.
    VcpDatePickerStruct m_minDate;            

    // <group DOM_DatePicker_VcpDatePicker_Property>
    // Maximum limit for date value.
    VcpDatePickerStruct m_maxDate;            

    // <group DOM_DatePicker_VcpDatePicker_Property>
    // Date Format.
    VcpDatePickerFormatEnum m_format;
    VfxBool m_isInReset;
	
//Variable
};


#endif /* defined (__MMI_VUI_COSMOS_CP__) */
#endif /* __VCP_DATE_PICKER_H__ */

