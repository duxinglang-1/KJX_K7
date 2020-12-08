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
 *  vcp_time_picker.h
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Time picker header
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
#ifndef __VCP_TIME_PICKER_H__
#define __VCP_TIME_PICKER_H__


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
    #define VCP_TIME_PICKER_WIDTH                       (458)
    #define VCP_TIME_PICKER_HEIGHT                      (250)
    
    #define VCP_TIME_PICKER_CELL_HEIGHT                 (50)

    #define VCP_TIME_PICKER_TEXT_FONT_SIZE              (23)
    #define VCP_TIME_PICKER_TEXT_FONT_COLOR             VfxColor(255, 123, 123 , 123)

    #define VCP_TIME_PICKER_UNIT_FONT_SIZE              (33)
    #define VCP_TIME_PICKER_UNIT_FONT_COLOR             VfxColor(255, 255, 255 , 255)

    #define VCP_TIME_PICKER_FOCUS_FONT_SIZE             (45)
    #define VCP_TIME_PICKER_FOCUS_FONT_COLOR            VfxColor(255, 15, 15 , 15)

    #define VCP_TIME_PICKER_CELL_HOURS_WIDTH_EX         (208)
    #define VCP_TIME_PICKER_CELL_MINUTES_WIDTH_EX       (208)

    #define VCP_TIME_PICKER_CELL_HOURS_WIDTH            (147)
    #define VCP_TIME_PICKER_CELL_MINUTES_WIDTH 	        (147)
    #define VCP_TIME_PICKER_CELL_MODE_WIDTH             (118)

    #define VCP_TIME_PICKER_START_X                     (19)
    #define VCP_TIME_PICKER_START_X_GAP                 (4)
    #define VCP_TIME_PICKER_START_Y                     (13)
    #define VCP_TIME_PICKER_START_Y_GAP                 (12)
    #define VCP_TIME_PICKER_START_Y_BOTTOM              (12)
#elif defined(__MMI_MAINLCD_320X480__)
    #define VCP_TIME_PICKER_WIDTH                       (304)
    #define VCP_TIME_PICKER_HEIGHT                      (166)
    
    #define VCP_TIME_PICKER_CELL_HEIGHT                 (33)

    #define VCP_TIME_PICKER_TEXT_FONT_SIZE              (14)
    #define VCP_TIME_PICKER_TEXT_FONT_COLOR             VfxColor(255, 123, 123 , 123)

    #define VCP_TIME_PICKER_UNIT_FONT_SIZE              (22)
    #define VCP_TIME_PICKER_UNIT_FONT_COLOR             VfxColor(255, 255, 255 , 255)

    #define VCP_TIME_PICKER_FOCUS_FONT_SIZE             (30)
    #define VCP_TIME_PICKER_FOCUS_FONT_COLOR            VfxColor(255, 15, 15 , 15)

    #define VCP_TIME_PICKER_CELL_HOURS_WIDTH_EX         (139)
    #define VCP_TIME_PICKER_CELL_MINUTES_WIDTH_EX       (138)

    #define VCP_TIME_PICKER_CELL_HOURS_WIDTH            (98)
    #define VCP_TIME_PICKER_CELL_MINUTES_WIDTH          (98)
    #define VCP_TIME_PICKER_CELL_MODE_WIDTH             (78)

    #define VCP_TIME_PICKER_START_X                     (12)
    #define VCP_TIME_PICKER_START_X_GAP                 (3)
    #define VCP_TIME_PICKER_START_Y                     (9)
    #define VCP_TIME_PICKER_START_Y_GAP                 (8)
    #define VCP_TIME_PICKER_START_Y_BOTTOM              (8)
#elif defined(__MMI_MAINLCD_240X400__)
    #define VCP_TIME_PICKER_WIDTH                       (228)
    #define VCP_TIME_PICKER_HEIGHT                      (134)
    
    #define VCP_TIME_PICKER_CELL_HEIGHT                 (30)

    #define VCP_TIME_PICKER_TEXT_FONT_SIZE              (13)
    #define VCP_TIME_PICKER_TEXT_FONT_COLOR             VfxColor(255, 123, 123 , 123)

    #define VCP_TIME_PICKER_UNIT_FONT_SIZE              (16)
    #define VCP_TIME_PICKER_UNIT_FONT_COLOR             VfxColor(255, 255, 255 , 255)

    #define VCP_TIME_PICKER_FOCUS_FONT_SIZE             (22)
    #define VCP_TIME_PICKER_FOCUS_FONT_COLOR            VfxColor(255, 15, 15 , 15)

    #define VCP_TIME_PICKER_CELL_HOURS_WIDTH_EX         (105)
    #define VCP_TIME_PICKER_CELL_MINUTES_WIDTH_EX       (105)

    #define VCP_TIME_PICKER_CELL_HOURS_WIDTH            (75)
    #define VCP_TIME_PICKER_CELL_MINUTES_WIDTH          (75)
    #define VCP_TIME_PICKER_CELL_MODE_WIDTH             (58)

    #define VCP_TIME_PICKER_START_X                     (8)
    #define VCP_TIME_PICKER_START_X_GAP                 (2)
    #define VCP_TIME_PICKER_START_Y                     (8)
    #define VCP_TIME_PICKER_START_Y_GAP                 (7)
    #define VCP_TIME_PICKER_START_Y_BOTTOM              (8)
#elif defined(__MMI_MAINLCD_240X320__)
    #define VCP_TIME_PICKER_WIDTH                       (228)
    #define VCP_TIME_PICKER_HEIGHT                      (134)
    
    #define VCP_TIME_PICKER_CELL_HEIGHT                 (30)

    #define VCP_TIME_PICKER_TEXT_FONT_SIZE              (13)
    #define VCP_TIME_PICKER_TEXT_FONT_COLOR             VfxColor(255, 123, 123 , 123)

    #define VCP_TIME_PICKER_UNIT_FONT_SIZE              (16)
    #define VCP_TIME_PICKER_UNIT_FONT_COLOR             VfxColor(255, 255, 255 , 255)

    #define VCP_TIME_PICKER_FOCUS_FONT_SIZE             (22)
    #define VCP_TIME_PICKER_FOCUS_FONT_COLOR            VfxColor(255, 15, 15 , 15)

    #define VCP_TIME_PICKER_CELL_HOURS_WIDTH_EX         (105)
    #define VCP_TIME_PICKER_CELL_MINUTES_WIDTH_EX       (105)

    #define VCP_TIME_PICKER_CELL_HOURS_WIDTH            (75)
    #define VCP_TIME_PICKER_CELL_MINUTES_WIDTH          (75)
    #define VCP_TIME_PICKER_CELL_MODE_WIDTH             (58)

    #define VCP_TIME_PICKER_START_X                     (8)
    #define VCP_TIME_PICKER_START_X_GAP                 (2)
    #define VCP_TIME_PICKER_START_Y                     (8)
    #define VCP_TIME_PICKER_START_Y_GAP                 (7)
    #define VCP_TIME_PICKER_START_Y_BOTTOM              (8)
#else
    // Temp values
    #define VCP_TIME_PICKER_WIDTH                       (228)
    #define VCP_TIME_PICKER_HEIGHT                      (134)
    
    #define VCP_TIME_PICKER_CELL_HEIGHT                 (30)

    #define VCP_TIME_PICKER_TEXT_FONT_SIZE              (13)
    #define VCP_TIME_PICKER_TEXT_FONT_COLOR             VfxColor(255, 123, 123 , 123)

    #define VCP_TIME_PICKER_UNIT_FONT_SIZE              (16)
    #define VCP_TIME_PICKER_UNIT_FONT_COLOR             VfxColor(255, 255, 255 , 255)

    #define VCP_TIME_PICKER_FOCUS_FONT_SIZE             (22)
    #define VCP_TIME_PICKER_FOCUS_FONT_COLOR            VfxColor(255, 15, 15 , 15)

    #define VCP_TIME_PICKER_CELL_HOURS_WIDTH_EX         (105)
    #define VCP_TIME_PICKER_CELL_MINUTES_WIDTH_EX       (105)

    #define VCP_TIME_PICKER_CELL_HOURS_WIDTH            (75)
    #define VCP_TIME_PICKER_CELL_MINUTES_WIDTH          (75)
    #define VCP_TIME_PICKER_CELL_MODE_WIDTH             (58)

    #define VCP_TIME_PICKER_START_X                     (8)
    #define VCP_TIME_PICKER_START_X_GAP                 (2)
    #define VCP_TIME_PICKER_START_Y                     (8)
    #define VCP_TIME_PICKER_START_Y_GAP                 (7)
    #define VCP_TIME_PICKER_START_Y_BOTTOM              (8)
#endif


typedef enum
{
    VCP_TIME_PICKER_FIELD_HOURS,
    VCP_TIME_PICKER_FIELD_MINUTES,
    VCP_TIME_PICKER_FIELD_AMPM,
    VCP_TIME_PICKER_FIELD_TOTAL
}VcpTimePickerFieldsEnum;
/* DOM-NOT_FOR_SDK-END */

/*
 * Structure to be used in XML
 ********************************************************
    <Struct name="VcpTimePickerStruct">
        <Member    name="hours"       type="VfxU8"/>
        <Member    name="minutes"      type="VfxU8"/>
    </Struct>
 ********************************************************
*/

// <group DOM_TimePicker_struct>
//This Structure is used to specify the time value
struct VcpTimePickerStruct : public VfxBase
{
    VfxU32 hour;        // Hours, should be in 24 hours format (0-23)
    VfxU32 minute;	// Minutes (0-59)
};




/*****************************************************************************
 * Class VcpTimePicker
 *****************************************************************************/
/*
 * VcpTimePicker - a Time Picker.
 *
 * EXAMPLE
 * <code>
 *  VcpTimePicker *tpicker;
 *  VFX_OBJ_CREATE(tpicker, VcpTimePicker, this);
 *  panel->setPos(75, 50); 
 * </code>
 */
class VcpTimePicker : public VcpBasePicker, public IVcpBasePickerContentProvider
{
    VFX_DECLARE_CLASS(VcpTimePicker);

// Constructor / Destructor
public:
    // <group DOM_TimePicker_VcpTimePicker_Constructor/Destructor>
    // Default constructor.
    VcpTimePicker();

public:
    // <group DOM_TimePicker_VcpTimePicker_Method>
    // To set the time value.
    void setTime(
        const VcpTimePickerStruct &time                // [IN]   XXX
    );

    // <group DOM_TimePicker_VcpTimePicker_Method>
    // To set the time value equal to the current time of the system.
    void setCurrTime();

    // <group DOM_TimePicker_VcpTimePicker_Method>
    // To set the minimum limit for the time value.
    void setMinTime(
        const VcpTimePickerStruct &time                // [IN]   XXX
    );

    // <group DOM_TimePicker_VcpTimePicker_Method>
    // To set the maximum limit for the time value.
    void setMaxTime(
        const VcpTimePickerStruct &time                // [IN]   XXX
    );

    // <group DOM_TimePicker_VcpTimePicker_Method>
    // To specify the format of the time.
    // TRUE means 24 hours format.
    // FALSE means 12 hours format.
    void setIs24HourView(
        VfxBool mode                // [IN]   XXX
    );

    // <group DOM_TimePicker_VcpTimePicker_Method>
    // To get the current time set in the time picker.
    const VcpTimePickerStruct &getTime() const;

    // <group DOM_TimePicker_VcpTimePicker_Method>
    // To get the minimum limit for time value.
    const VcpTimePickerStruct &getMinTime() const;

    // <group DOM_TimePicker_VcpTimePicker_Method>
    // To get the maximum limit for time value.
    const VcpTimePickerStruct &getMaxTime() const;

    // <group DOM_TimePicker_VcpTimePicker_Method>
    // To get the time format.
    // TRUE: 24 hours format.
    // FALSE: 12 hours format
    VfxBool getIs24HourView();

private:
    // <group DOM_TimePicker_VcpTimePicker_Implementation>
    // Update the fields to the set time
    void updateTime(void);

    // <group DOM_TimePicker_VcpTimePicker_Implementation>
    // Reset the layout once user changes the time format.
    void resetLayout(void);

    // <group DOM_TimePicker_VcpTimePicker_Implementation>
    // On bound change.
    void onBoundsChanged(VfxFrame *frame, const VfxRect &old);


public:
    // <group DOM_TimePicker_VcpTimePicker_Event>
    // This is used to notify the application when time changes.
    // Application must register its handler with this slot.
    // This signal is emitted everytime user changes the time. 
    VfxSignal2 < VfxObject*, VcpTimePickerStruct*> m_signalOnTimeChanged;

protected:
    // <group DOM_TimePicker_VcpTimePicker_Override>
    // On Init.
    virtual void onInit();

    // <group DOM_TimePicker_VcpTimePicker_Override>
    // Called when opicity changes.
    virtual void onSetTranslucent(VfxBool translucent);

    // <group DOM_TimePicker_VcpTimePicker_Override>
    // To get the cell count for a particular field
    // RETURN: Cell count.
    virtual VfxS32 getFieldCellCount(VfxS32 field);

    // <group DOM_TimePicker_VcpTimePicker_Override>
    // To get the cell's string for a particular field.
    // RETURN: String
    virtual VfxWString onGetFieldString(VfxS32 field, VfxS32 cell);

    // <group DOM_TimePicker_VcpTimePicker_Override>
    // This is called when focussed item is changed.
    // Sets the updated time value and notify the application about updated time value.
    virtual void onFieldFocusIndexChange(VfxS32 field, VfxS32 focusItem, VfxS32 previousFocusItem);

private:
    // <group DOM_TimePicker_VcpTimePicker_Property>
    // Current time value.
    VcpTimePickerStruct m_currTime;
    
    // <group DOM_TimePicker_VcpTimePicker_Property>
    // Minimum limit for time value.
    VcpTimePickerStruct m_minTime;            

    // <group DOM_TimePicker_VcpTimePicker_Property>
    // Maximum limit for time value.
    VcpTimePickerStruct m_maxTime;            

    // <group DOM_TimePicker_VcpTimePicker_Property>
    // To specify if 24 hour view or not.
    VfxBool m_is24HourView;            

//Variable
};

#endif /* #if defined (__MMI_VUI_COSMOS_CP__)  */ 
#endif /* __VCP_TIME_PICKER_H__ */

