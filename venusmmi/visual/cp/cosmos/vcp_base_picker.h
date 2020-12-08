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
 *  vcp_base_picker.h
 *
 * Project:
 * --------
 *  A basic picker for FTO picker
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_BASE_PICKER_H__
#define __VCP_BASE_PICKER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
 
#include "vcp_wheel_menu.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_font_desc.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"
#include "vrt_datatype.h"
#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_image_src.h"
#include "vfx_string.h"
#include "vfx_text_frame.h"
#include "vfx_primitive_frame.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__MMI_MAINLCD_320X480__)
    #define VCP_BASE_PICKER_MARGIN_WIDTH                    (8)
    #define VCP_BASE_PICKER_FIELD_SHADOW                    (4)
#elif defined(__MMI_MAINLCD_480X800__)
    #define VCP_BASE_PICKER_MARGIN_WIDTH                    (12)
    #define VCP_BASE_PICKER_FIELD_SHADOW                    (8)
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    #define VCP_BASE_PICKER_MARGIN_WIDTH                    (6)
    #define VCP_BASE_PICKER_FIELD_SHADOW                    (2)
#else
    #define VCP_BASE_PICKER_MARGIN_WIDTH                    (8) 
    #define VCP_BASE_PICKER_FIELD_SHADOW                    (4)
#endif
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

enum VcpPickerDataType
{
    VCP_PICKER_DATA_TYPE_STRING,
    VCP_PICKER_DATA_TYPE_FRAME,
    VCP_PICKER_DATA_TYPE_END_OF_ENUM
};


enum VcpPickerStringAlignMode
{
    VCP_PICKER_STRING_ALIGN_MODE_LEFT,
    VCP_PICKER_STRING_ALIGN_MODE_CENTER,
    VCP_PICKER_STRING_ALIGN_MODE_RIGHT,
    VCP_PICKER_STRING_ALIGN_MODE_END_OF_ENUM
};

//#define __MMI_VUI_COSMOS_CP_SLIM__
/***************************************************************************** 
 * Class VcpBasePickerField
 *  VcpBasePickerFieldInfo store the picker filed infomation
 *****************************************************************************/
class VcpBasePickerFieldInfo : public VfxBase
{
public:
    VfxS32                      index;

    VfxBool                     isDataLoop;
    VfxS32                      focusIndex;
#ifndef __MMI_VUI_COSMOS_CP_SLIM__    
    VfxColor                    textColor;    
    VfxColor                    focusTextColor;
	VfxColor                    unitTextColor;	
#endif //__MMI_VUI_COSMOS_CP_SLIM__

	VfxFontDesc                 textFont;
	VfxFontDesc                 focusTextFont;
    VfxBool                     unitTextVisible;
    VfxWString                  unitTextString;
    VfxFontDesc                 unitTextFont;


VcpBasePickerFieldInfo() : 
    index(0),
    isDataLoop(VFX_FALSE),
    focusIndex(0),
#ifndef __MMI_VUI_COSMOS_CP_SLIM__
    textColor(VFX_COLOR_WHITE),
    focusTextColor(VFX_COLOR_WHITE),
 	unitTextColor(VFX_COLOR_WHITE),
#endif
    textFont(VFX_FONT_DESC_MEDIUM),
    focusTextFont(VFX_FONT_DESC_MEDIUM),
    unitTextVisible(VFX_FALSE),     
	unitTextString(VFX_WSTR_NULL),
	unitTextFont(VFX_FONT_DESC_MEDIUM)
    {}
    
};

/***************************************************************************** 
 * Class VcpBasePickerField
 *****************************************************************************/
/*
 *  VcpBasePickerField is a field of picker. It is inherit from VcpWheelMen.
 *  So it can be scroll to change index.
 */
class VcpBasePickerField : public VcpWheelMenu
{
// Constructor / Destructor
public:
    // <group DOM_BasePicker_VcpBasePickerField_Constructor/Destructor>
    VcpBasePickerField();

// Method
public:
    // <group DOM_BasePicker_VcpBasePickerField_Method>
    // set current field Index
    void setFieldIndex(VfxS32 fieldIndex)
    {
        m_fieldIndex = fieldIndex;
    }
    // <group DOM_BasePicker_VcpBasePickerField_Method>
    // get current field Index
    VfxS32 getFieldNumber() const
    {
        return m_fieldIndex;
    }
    // <group DOM_BasePicker_VcpBasePickerField_Method>
    // set data type of this field
    void setDataType(VcpPickerDataType dataType)
    {
        m_dataType = dataType;
    }
    // <group DOM_BasePicker_VcpBasePickerField_Method>
    // get data type of this field
    VcpPickerDataType getDataType() const
    {
        return m_dataType;
    }
    // <group DOM_BasePicker_VcpBasePickerField_Method>
    // set each cell height of this field
    void setCellHeight(VfxS32 cellHeight)
    {
        m_cellHeight = cellHeight;
    }
    // <group DOM_BasePicker_VcpBasePickerField_Method>
    // get each cell height of this field
    VfxS32 getCellHeight() const
    {
        return m_cellHeight;
    }
    // <group DOM_BasePicker_VcpBasePickerField_Method>
    // set the data is this field is loop or not
    void setIsLoop(VfxBool value)
    {
        m_isLoop = value;
        checkUpdate();
    }
    // <group DOM_BasePicker_VcpBasePickerField_Method>
    // get the data is this field is loop or not
    VfxBool getIsLoop() const
    {
        return m_isLoop;
    }
#ifndef __MMI_VUI_COSMOS_CP_SLIM__
    // <group DOM_BasePicker_VcpBasePickerField_Method>
    // set the string align mode when the data type is VCP_PICKER_DATA_TYPE_STRING
    void setStringAlignMode(VcpPickerStringAlignMode mode)
    {
        m_stringAlignMode = mode;
    }
    // <group DOM_BasePicker_VcpBasePickerField_Method>
    // get the string align mode when the data type is VCP_PICKER_DATA_TYPE_STRING
    VcpPickerStringAlignMode getStringAlignMode() const
    {
        return m_stringAlignMode;
    }
#endif
    // <group DOM_BasePicker_VcpBasePickerField_Method>
    // set the text property when data type is VCP_PICKER_DATA_TYPE_STRING
    void setTextFont(const VfxFontDesc &font)
    {
        m_textFont = font;
    }
    // <group DOM_BasePicker_VcpBasePickerField_Method>
    // get the text property when data type is VCP_PICKER_DATA_TYPE_STRING
    const VfxFontDesc &getTextFont() const
    {
        return m_textFont;
    }
#ifndef __MMI_VUI_COSMOS_CP_SLIM__
    // <group DOM_BasePicker_VcpBasePickerField_Method>
    // set the text color when data type is VCP_PICKER_DATA_TYPE_STRING
    void setTextColor(const VfxColor &color)
    {
        m_textColor = color;
    }
    // <group DOM_BasePicker_VcpBasePickerField_Method>
    // get the text property when data type is VCP_PICKER_DATA_TYPE_STRING
    const VfxColor &getTextColor() const
    {
        return m_textColor;
    }
#endif
    // <group DOM_BasePicker_VcpBasePickerField_Method>
    // set the text property when data type is VCP_PICKER_DATA_TYPE_STRING
    void setFocusTextFont(const VfxFontDesc &font)
    {
        m_focusTextFont = font;
    }
    // <group DOM_BasePicker_VcpBasePickerField_Method>
    // get the text property when data type is VCP_PICKER_DATA_TYPE_STRING
    const VfxFontDesc &getFocusTextFont() const
    {
        return m_focusTextFont;
    }
#ifndef __MMI_VUI_COSMOS_CP_SLIM__
    // <group DOM_BasePicker_VcpBasePickerField_Method>
    // set the text color when data type is VCP_PICKER_DATA_TYPE_STRING
    void setFocusTextColor(const VfxColor &color)
    {
        m_focusTextColor = color;
    }
    // <group DOM_BasePicker_VcpBasePickerField_Method>
    // get the text property when data type is VCP_PICKER_DATA_TYPE_STRING
    const VfxColor &getFocusTextColor() const
    {
        return m_focusTextColor;
    }
#endif    
    // <group DOM_BasePicker_VcpBasePickerField_Method>
    // set focus index to target index, animTime is the duration move to target index
    void setFocusIndex(VfxS32 index, VfxMsec animTime = -1);
    // <group DOM_BasePicker_VcpBasePickerField_Method>
    // get current focus index
    VfxS32 getFocusIndex();
    // <group DOM_BasePicker_VcpBasePickerField_Method>
    // Reset Cells
	void resetCells();

// Override
protected:
    // <group DOM_BasePicker_VcpBasePickerField_Override>
    virtual void onInit();
    // <group DOM_BasePicker_VcpBasePickerField_Override>
    virtual VfxFrame* createCell(VfxS32 cell, VfxS32 subcell);
    // <group DOM_BasePicker_VcpBasePickerField_Override>
    virtual void onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* frame){}
    // <group DOM_BasePicker_VcpBasePickerField_Override>
    virtual void onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame);
    // <group DOM_BasePicker_VcpBasePickerField_Override>
    virtual void onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem);
    // <group DOM_BasePicker_VcpBasePickerField_Override>
    virtual void onDragStart();
    // <group DOM_BasePicker_VcpBasePickerField_Override>
    virtual void onDragEnd(VfxS32 xspeed, VfxS32 yspeed);
    // <group DOM_BasePicker_VcpBasePickerField_Override>
    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset);
    // <group DOM_BasePicker_VcpBasePickerField_Override>
    virtual void onTap(VfxPoint pt){}
    // <group DOM_BasePicker_VcpBasePickerField_Override>
    virtual VfxS32 getCount();
    // <group DOM_BasePicker_VcpBasePickerField_Override>
    virtual VfxS32 getBehindCount();
    // <group DOM_BasePicker_VcpBasePickerField_Override>
    virtual VfxS32 getAheadCount();
    // <group DOM_BasePicker_VcpBasePickerField_Override>
    static vrt_render_dirty_type_enum myFrameEffectCB(
        VfxS32                              cell,           // [IN] the cell index
        VfxS32                              subCell,        // [IN] the sub cell index
        VfxFloat                            cellRelPos,     // [IN] the cell position
        vrt_frame_visual_property_struct    *target_frame,  // [IN] the cell frame
        VfxFloat                            fPos,           // [IN] animating index value
        VfxS32                              focus,          // the focus value of the menu
        VfxRect                             viewBounds,     // the menu bounds
        void                                *userData,      // user data
        VfxU32                              userDataSize,   // user data size
        VcpWheelMenuState                   state,          // [IN] the state of Menu
        VfxFloat                            level           // [IN] the level of state
    );
    // <group DOM_BasePicker_VcpBasePickerField_Override>
    virtual VcpWheelMenuFrameEffectCBFuncPtr getFrameEffectCB()
    {
        return &VcpBasePickerField::myFrameEffectCB;
    }
    // <group DOM_BasePicker_VcpBasePickerField_Override>
    virtual VfxTimingFuncIdEnum getMoveTimeFunction()
    {
        return VFX_TIMING_FUNC_ID_EASE_OUT;
    }
// Implementation
private:
    // <group DOM_BasePicker_VcpBasePickerField_Implementation>
    void onResetTimerStop(VfxTimer *source);
    void resetCell();

// Variable
protected:
    // <group DOM_BasePicker_VcpBasePickerField_Variable>
    VfxS32 m_fieldIndex;
    // <group DOM_BasePicker_VcpBasePickerField_Variable>
    VcpPickerDataType m_dataType;
    // <group DOM_BasePicker_VcpBasePickerField_Variable>
    VfxS32 m_cellHeight;
    // <group DOM_BasePicker_VcpBasePickerField_Variable>
    VfxBool m_isLoop;
    // <group DOM_BasePicker_VcpBasePickerField_Variable>
    VfxS32 m_realCellCount;
    // <group DOM_BasePicker_VcpBasePickerField_Variable>
    VfxS32 m_realFocus;
#ifndef __MMI_VUI_COSMOS_CP_SLIM__
    // <group DOM_BasePicker_VcpBasePickerField_Variable>
    VcpPickerStringAlignMode m_stringAlignMode;
#endif
    // <group DOM_BasePicker_VcpBasePickerField_Variable>
    VfxFontDesc m_textFont;
    // <group DOM_BasePicker_VcpBasePickerField_Variable>
    VfxColor m_textColor;
    // <group DOM_BasePicker_VcpBasePickerField_Variable>
    VfxFontDesc m_focusTextFont;
    // <group DOM_BasePicker_VcpBasePickerField_Variable>
    VfxColor m_focusTextColor;
    // <group DOM_BasePicker_VcpBasePickerField_Variable>
    VfxTimer *m_resetTimer;
	// <group DOM_BasePicker_VcpBasePickerField_Variable> 
	VfxMsec m_defaultAnimationBackup;
};


/***************************************************************************** 
 * Class IVcpBasePickerContentProvider
 *  IVcpBasePickerContentProvider define some interface to get picker field 
 *  data. user can inherit it to do date picker, time picker or other picker.
 *****************************************************************************/
class IVcpBasePickerContentProvider 
{
// Overridable
public: 
    // <group DOM_BasePicker_IVcpBasePickerContentProvider_Overridable>
    // get the cell count of specific field
    virtual VfxS32 getFieldCellCount(VfxS32 field) = 0;
    
    // <group DOM_BasePicker_IVcpBasePickerContentProvider_Overridable>
    // get the data type of specific field
    virtual VcpPickerDataType getFieldDatatype(VfxS32 field)
    {
        return VCP_PICKER_DATA_TYPE_STRING;
    }
    // <group DOM_BasePicker_IVcpBasePickerContentProvider_Overridable>
    // get the string of specific field, this function will be call when field data type is string 
    virtual VfxWString onGetFieldString(VfxS32 field, VfxS32 cell)
    {
        return VFX_WSTR_NULL;
    };
    // <group DOM_BasePicker_IVcpBasePickerContentProvider_Overridable>
    // get the frame of specific field, this function will be call when field data type is frame 
    virtual VfxFrame *onGetFieldFrame(VfxS32 field, VfxS32 cell)
    {
        return NULL;
    };
    // <group DOM_BasePicker_IVcpBasePickerContentProvider_Overridable>
    // notifiy when the cell is closed, this function will be call when field data type is frame
    virtual void onFieldCloseCell(VfxS32 field, VfxS32 cell, VfxFrame* cellFrame){};
    // <group DOM_BasePicker_IVcpBasePickerContentProvider_Overridable>
    // notifiy when focused changed of specific field
    virtual void onFieldFocusIndexChange(VfxS32 field, VfxS32 focusItem, VfxS32 previousFocusItem){};
};

/***************************************************************************** 
 * Class VcpBasePicker
 *  VcpBasePicker is a basic picker UI class. It can contain 1 to 3 field.
 *  Each Field UI is using VcpBasePickerField and data is using
 *  IVcpBasePickerContentProvider. VcpBasePicker cannot use by APP
 *  directly. There must be some class inhert form VcpBasePicker and
 *  IVcpBasePickerContentProvider.
 *****************************************************************************/
class VcpBasePicker : public VfxControl
{
    VFX_DECLARE_CLASS(VcpBasePicker);

// Constructor / Destructor
public:
    // <group DOM_BasePicker_VcpBasePicker_Constructor/Destructor>
    VcpBasePicker();

// Override
protected:
    // <group DOM_BasePicker_VcpBasePicker_Override>
    virtual void onInit();
    // <group DOM_BasePicker_VcpBasePicker_Override>
    virtual void onUpdate();
    // <group DOM_BasePicker_VcpBasePicker_Override>
    virtual VfxBool onPenAbortAccepted(
        VfxControl *aborter, 
        VfxPenAbortReasonEnum reason
    );

// Method
public:
    // picker related API
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // set an contentProvider as this picker's contentProvider
    void setContentProvider(IVcpBasePickerContentProvider *contentProvider)
    {
        m_contentProvider = contentProvider;
    }
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // get this picker's contentProvider
    IVcpBasePickerContentProvider* getContentProvider()
    {
        return m_contentProvider;
    }
    
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // set the number of field in picker
    // please call set FieldCount before call any other API to let 
    void setFieldCount(
        VfxS32 count                        // [IN] number count of field
        );
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // get the number of field in picker
    VfxS32 getFieldCount() const
    {
        return m_fieldCount;
    }
    
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // set background of the picker 
    void setBackground(
        VfxImageSrc img                     // [IN] background image
        );
    // field related API

    // <group DOM_BasePicker_VcpBasePicker_Method>
    // set field area rectangle 
    void setFieldCellRect(VfxS32 index, const VfxRect &rect)
    {
        if (index < 0 || index >= 3)
        {
            VFX_DEV_ASSERT(0);
        }
        else
        {
            m_fieldRect[index] = rect;
        }
        checkUpdate();
    }
    
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // set unit text area rectangle 
    void setUnitTextRect(VfxS32 index, const VfxRect &rect)
    {
        if (index < 0 || index >= 3)
        {
            VFX_DEV_ASSERT(0);
        }
        else
        {
            m_unitTextRect[index] = rect;
        }
        checkUpdate();
    }

    // <group DOM_BasePicker_VcpBasePicker_Method>
    // set background image of each field
    void setFieldBackgroundImage(
        VfxS32 field,                       // [IN] field index
        VfxImageSrc img                     // [IN] field background image
        )
    {
        if (field < m_fieldCount)
        {
            m_fieldBackground[field]->setImgContent(img);
        }
    }

    // <group DOM_BasePicker_VcpBasePicker_Method>
    // set the cell height of all fields
    void setFieldCellHeight(
        VfxS32 height                       // [IN] field cell height
        )
    {
        m_fieldCellHeight = height;
        checkUpdate();
    }
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // get the cell height of all fields
    VfxS32 getFieldCellHeight()
    {
        return m_fieldCellHeight;
    }
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // set the data of specific field is loop or not
    void setFieldIsDataLoop(
        VfxS32 field,                       // [IN] field index
        VfxBool value                       // [IN] is loop or not
        );
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // get the data of specific field is loop or not
    VfxBool getFieldIsDataLoop(
        VfxS32 field                        // [IN] field index
        );
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // set the data type of specific field
    void setFieldDataType(
        VfxS32 field,                       // [IN] field index
        VcpPickerDataType value             // [IN] data type
        );
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // get the data type of specific field
    VcpPickerDataType getFieldDataType(
        VfxS32 field                        // [IN] field index
        );
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // set the focus of specific field, it will do an animation to that foucs index
    void setFieldFocus(
        VfxS32 field,                       // [IN] field index
        VfxS32 focus,                       // [IN] focus index
        VfxMsec animTime = 250              // [IN] animation time
        );
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // get the focus of specific field
    VfxS32 getFieldFocus(
        VfxS32 field                        // [IN] field index
        );
     // <group DOM_BasePicker_VcpBasePicker_Method>
     // Resets the field cells
	void resetFieldCells(VfxS32 field);
#ifndef __MMI_VUI_COSMOS_CP_SLIM__
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // set the font of specific field, this property is only activated when data type is string 
    void setFieldTextFont(
        VfxS32 field,                       // [IN] field index
        const VfxFontDesc &font                        // [IN] text font
        );
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // get the font of specific field, this property is only activated when data type is string 
    VfxFontDesc getFieldTextFont(
        VfxS32 field                        // [IN] field index
        );
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // set the text color of specific field, this property is only activated when data type is string 
    void setFieldTextColor(
        VfxS32 field,                       // [IN] field index
        VfxColor color                      // [IN] text color
        );
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // get the text color of specific field, this property is only activated when data type is string
    VfxColor getFieldTextColor(
        VfxS32 field                        // [IN] field index
        );

    // <group DOM_BasePicker_VcpBasePicker_Method>
    // set the font of specific field, this property is only activated when data type is string 
    void setFieldFocusTextFont(
        VfxS32 field,                       // [IN] field index
        const VfxFontDesc &font                        // [IN] text font
        );
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // get the font of specific field, this property is only activated when data type is string 
    VfxFontDesc getFieldFocusTextFont(
        VfxS32 field                        // [IN] field index
        );
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // set the text color of specific field, this property is only activated when data type is string 
    void setFieldFocusTextColor(
        VfxS32 field,                       // [IN] field index
        VfxColor color                      // [IN] text color
        );
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // get the text color of specific field, this property is only activated when data type is string
    VfxColor getFieldFocusTextColor(
        VfxS32 field                        // [IN] field index
        );
    
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // set the text align mode of specific field, this property is only activated when data type is string
    void setFieldStringAlignMode(
        VfxS32 field,                       // [IN] field index
        VcpPickerStringAlignMode mode       // [IN] align mode
        );
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // get the text align mode of specific field, this property is only activated when data type is string
    VcpPickerStringAlignMode getFieldStringAlignMode(
        VfxS32 field                        // [IN] field index
        );
    
    // unit text frame related API

    // <group DOM_BasePicker_VcpBasePicker_Method>
    // set the uint text of specific field is visible or not
    void setUnitTextVisible(
        VfxS32 field,                       // [IN] field index
        VfxBool value                       // [IN] is visible or not
        );
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // get the uint text of specific field is visible or not
    VfxBool getUnitTextVisible(
        VfxS32 field                        // [IN] field index
        );
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // set the uint text string of specific field 
    void setUnitTextString(
        VfxS32 field,                       // [IN] field index
        const VfxWString &str               // [IN] unit text string
        );
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // get the uint text string of specific field 
    VfxWString getUnitTextString(
        VfxS32 field                        // [IN] field index
    ) const;
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // set the uint text font of specific field 
    void setUintTextFont(
        VfxS32 field,                       // [IN] field index
        const VfxFontDesc &font                        // [IN] unit text font
        );
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // get the uint text font of specific field 
    VfxFontDesc getUintTextFont(VfxS32 field) const;
    
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // set the uint text color of specific field 
    void setUintTextColor(
        VfxS32 field,                       // [IN] field index
        VfxColor color                      // [IN] uint text color
        );
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // get the uint text color of specific field
    VfxColor getUnitTextColor(
        VfxS32 field                        // [IN] field index
        );
#endif
    // <group DOM_BasePicker_VcpBasePicker_Method>
    // set field infomation
    void setFieldInfo(const VcpBasePickerFieldInfo &info);
    
// Variable
protected:
    IVcpBasePickerContentProvider *m_contentProvider;
    // <group DOM_BasePicker_VcpBasePicker_Variable>
    VfxFrame *m_background;
    // <group DOM_BasePicker_VcpBasePicker_Variable>
    VcpBasePickerField *m_field[3];
    // <group DOM_BasePicker_VcpBasePicker_Variable>
    VfxTextFrame *m_unitTextFrame[3];
    // <group DOM_BasePicker_VcpBasePicker_Variable>
    VfxFrame *m_fieldBackground[3];
    // <group DOM_BasePicker_VcpBasePicker_Variable>
    VfxS32 m_fieldCount;
    // <group DOM_BasePicker_VcpBasePicker_Variable>
    VfxS32 m_fieldCellWidth[3];
    // <group DOM_BasePicker_VcpBasePicker_Variable>
    VfxS32 m_fieldCellHeight;
    // <group DOM_BasePicker_VcpBasePicker_Variable>
    VfxBool m_isDataLoop[3];
    // <group DOM_BasePicker_VcpBasePicker_Variable>
    VfxS32 m_fieldFocus[3];
    // <group DOM_BasePicker_VcpBasePicker_Variable>
    VcpPickerDataType m_fieldCellDataType[3];
#ifndef __MMI_VUI_COSMOS_CP_SLIM__
    // <group DOM_BasePicker_VcpBasePicker_Variable>
    VcpPickerStringAlignMode m_fieldStringAlignMode[3];
#endif
    // <group DOM_BasePicker_VcpBasePicker_Variable>
    VfxFontDesc m_fieldTextFont[3];
#ifndef __MMI_VUI_COSMOS_CP_SLIM__
    // <group DOM_BasePicker_VcpBasePicker_Variable>
    VfxColor m_fieldTextColor[3];
#endif

    // <group DOM_BasePicker_VcpBasePicker_Variable>
    VfxFontDesc m_fieldFocusTextFont[3];
#ifndef __MMI_VUI_COSMOS_CP_SLIM__
    // <group DOM_BasePicker_VcpBasePicker_Variable>
    VfxColor m_fieldFocusTextColor[3];
#endif

    // <group DOM_BasePicker_VcpBasePicker_Variable>
    VfxRect m_fieldRect[3];
    // <group DOM_BasePicker_VcpBasePicker_Variable>
    VfxRect m_unitTextRect[3];
    // <group DOM_BasePicker_VcpBasePicker_Variable>
    VfxImageFrame *m_leftArrow;
    // <group DOM_BasePicker_VcpBasePicker_Variable>
    VfxImageFrame *m_rightArrow;
    // <group DOM_BasePicker_VcpBasePicker_Variable>
    VfxImageFrame *m_shadowUp;
    // <group DOM_BasePicker_VcpBasePicker_Variable>
    VfxImageFrame *m_shadowDown;
    

private:
   friend class VcpBasePickerField;
};

#endif // __VCP_BASE_PICKER_H__
