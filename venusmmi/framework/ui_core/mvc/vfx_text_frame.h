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
 *  vfx_text_frame.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Text frame class
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
 
#ifndef __VFX_TEXT_FRAME_H__
#define __VFX_TEXT_FRAME_H__

#include "vfx_frame.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_basic_type.h"
#include "vfx_cpp_base.h"
#include "vrt_datatype.h"
#include "vfx_font_desc.h"
#include "vfx_draw_context.h"
#include "MMIDataType.h"

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__

#ifdef __cplusplus
extern "C"
{
#endif

#include "SST_sla.h"

#ifdef __cplusplus
}
#endif

#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
 
// The VfxTextFrame registered name
#define VFX_TEXT_FRAME_CLASS_NAME        "Text"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
class VfxTextLine;


/***************************************************************************** 
 * Class VfxTextFrame
 *****************************************************************************/

/*
 * VfxImageFrame is a primitive frame which can display a given string.
 * Support text alignment and truncate mode.
 *
 * SEE ALSO: VfxWString
 */
class VfxTextFrame : public VfxFrame
{
    VFX_DECLARE_CLASS(VfxTextFrame);

// Define
public:
    // Horizontal alignment mode
    enum AlignModeEnum
    {
        // The natural alignment according to the system language
        ALIGN_MODE_NATURAL = 0,
        // Align text to the left side of frame bounds
        ALIGN_MODE_LEFT,
        // Align text to the right side of frame bounds
        ALIGN_MODE_RIGHT,
        // Align text to the center of frame bounds
        ALIGN_MODE_CENTER,
        // Align text to the ceter of available area within margin
        ALIGN_MODE_CENTER_WITHIN_MARGIN,
        ALIGN_MODE_END_OF_ENUM
    };

    // Truncate mode
    enum TruncateModeEnum
    {
        // If m_propertyAutoResized is VFX_FALSE, the text is clipped to the frame bounds.
        TRUNCATE_MODE_NONE = 0,
        // Add the truncate string at end of missing text.
        TRUNCATE_MODE_END,
        TRUNCATE_MODE_END_OF_ENUM
    };

    // Truncate mode
    enum LineModeEnum
    {
        // Single line mode
        LINE_MODE_SINGLE = 0,
        // Multiline mode
        LINE_MODE_MULTI,
        LINE_MODE_END_OF_ENUM
    };

// Constructor / Destructor
public:
    // Default constructor
    VfxTextFrame();

// Property
public:
    // The text to be draw on the frame
    //
    // NOTE: The default value is null string.
    virtual const VfxWString &getString() const;
    // The color of the text
    //
    // NOTE: The default value is VFX_COLOR_WHITE.
    virtual const VfxColor &getColor() const;
    // The color of the text border color
    //
    // NOTE: The default value is VFX_COLOR_BLACK.
    virtual const VfxColor &getBorderColor() const;
    // The horizontal alignment mode
    //
    // NOTE: The default value is ALIGN_MODE_NATURAL.
    //
    // SEE ALSO: AlignModeEnum
    virtual AlignModeEnum getAlignMode() const;
    // The truncate mode
    //
    // NOTE: The default value is TRUNCATE_MODE_NONE.
    //    
    // SEE ALSO: TruncateModeEnum
    virtual TruncateModeEnum getTruncateMode() const;
    // Whether the auto resized is enabled
    //
    // NOTE: The default value is VFX_TRUE.
    virtual VfxBool getAutoResized() const;

    // Get the current line mode
    virtual LineModeEnum getLineMode() const;

    // Whether the auto font resized is enabled
    virtual VfxBool getAutoFontResized() const;

    // Set text of the frame.
    virtual void setString(VfxResId id);
    
    // Set text of the frame.
    virtual void setString(const VfxWChar *value);

    // Set text of the frame.
    virtual void setString(const VfxWString &value);
	
    // Set font color.
    virtual void setColor(
        const VfxColor &value   // [IN] Fill color of text.
    );
    // Set strok color.
    //
    // TODO: Fix border color, it is conflicted by border color of frame.
    virtual void setBorderColor(
        const VfxColor &value   // [IN] Stroke color of text.
    );
    // Set text align mode.
    virtual void setAlignMode(
        AlignModeEnum value     // [IN] Text algin mode.
    );
    // Set text truncate mode.
    virtual void setTruncateMode(
        TruncateModeEnum value  // [IN] Text truncate mode.
    );
    // Enable auto resizing when text is changed.
    virtual void setAutoResized(VfxBool value);
    
    // set margins to textframe
    virtual void setMargins(
        VfxS32 value            // [IN] Set all margins to the value
    );
    
    // set margins to textframe
    virtual void setMargins(
        VfxS32 leftMargin,     // [IN] Set left margin to the value
        VfxS32 topMargin,      // [IN] Set top margin to the value
        VfxS32 rightMargin,    // [IN] Set right margin to the value
        VfxS32 bottomMargin    // [IN] Set bottom margin to the value
    );

    // set singline or multiline mode
    virtual void setLineMode(
         LineModeEnum value    // [IN] Set multiline or singleline mode
    );

    // set whether auto resize the font size
    virtual void setAutoFontSize(
        VfxBool value          // [IN] indicate whether auto adjust font size
    );

    // set the indent for the first character
    virtual void setIndent(
        VfxS32 value           // [IN] value of indent
    );

    // set the max line count as the limitation of auto-resized multiline frame
    virtual void setMaxLines(
        VfxS32 value           // [IN] max line count
    );

    // set the line gap in multiline mode
    virtual void setLineGap(
        VfxS32 value           // [IN] value of gap between lines
    );
    
    // set the min line height in multiline mode
    virtual void setMinLineHeight(
        VfxS32 value           // [In] value of min line height of one line
    );

// Methods
public:
    // Set the font of text    
    void setFont(
        const VfxFontDesc &fontDesc // [IN] The font description to set
    );

    // Set Singline line height as fully-character height
    void setFullLineHeightMode(
        const VfxBool value         // [IN] indicate whether line height is fully-character height
    );

    // Return the font of text
    //
    // RETURNS: The font of text
    const VfxFontDesc &getFont() const
    {
        return m_font;
    }
    
    // Measure the size of text
    // 
    // RETURNS: The size of text
    VfxRect getMeasureBounds() const;
    
    // Get the line count of text
    // RETURNS: the line count of text
    VfxS32 getLineCount() const;

    //Align the text to the center of vertical
    void setVerticalToCenter(
        VfxBool value           // [IN] indicate whether align to center of vertical
    );

    //Dec width to match the all lines width, only available for multiline with auto resized mode
    void setBestFitWidth(
        VfxBool value           // [IN] indicate whether dec width
    );

    void setBasePos(const VfxPoint pos);
// Override
public:
    virtual void setBounds(const VfxRect &value);
    void setBounds(
        VfxS32 x,                   // [IN] The x coordinate to set
        VfxS32 y,                   // [IN] The y coordinate to set
        VfxS32 width,               // [IN] The width to set
        VfxS32 height               // [IN] The height to set
    )
    {
        // this function is overrided only for avoid compiler error if overrided
        // a function which has another one with the same name.
        VfxFrame::setBounds(x, y, width, height);
    }
    
    virtual const VfxRect &getBounds() const;

    // Set the frame bounds size
    void setSize(
        const VfxSize &value        // [IN] The size to set
    )
    {
        setBounds(VfxRect(0, 0, value.width, value.height));
    }

    // Set the frame bounds size
    void setSize(
        VfxS32 width,               // [IN] The width to set
        VfxS32 height               // [IN] The height to set
    )
    {
        setSize(VfxSize(width, height));
    }

// Update
public:
    // This function will post emit the onUpdate function.
    // And this function will only invoke once onUpdate function even you call it many times.
    void checkUpdate();

    // force update all layout immediatelly
    void forceUpdate();
    
// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onDraw(VfxDrawContext &dc);

private:
    void updateSize();

    // reset line information
    void resetLineInfo();
    
    // update the layout information
    void updateLayoutInfo();

    void updateSingleline();
    void updateMultiline();
    void drawSingleline(VfxDrawContext &dc);
    void drawMultiline(VfxDrawContext &dc);
    VfxBool decFontSize();
    AlignModeEnum convertAlignMode();
    VfxRect getBoundsWithMargin() const;
    void setBasePosInternal(const VfxPoint pos);
    
// Implementation
private:
    VfxFontDesc m_font, m_orgFont;
    VfxWString m_string;
    VfxColor m_color;
    VfxColor m_borderColor;
    AlignModeEnum m_alignMode;
    TruncateModeEnum m_truncateMode;
    VfxBool m_autoResized;
    VfxBool m_verticalCenter;
    VfxBool m_bestFitWidth;
    
    VfxS32 m_leftMargin, m_rightMargin, m_topMargin, m_bottomMargin;
    VfxS32 m_indent, m_paragraphIndent;
    VfxS32 m_lineCountLimit, m_lineGap, m_minLineHeight;
    LineModeEnum m_lineMode;
    VfxBool m_autoFontSize;
    VfxTextLine* m_lines;
    VfxBool m_checkUpdate;
    VfxBool m_fullyHeight;
    VfxBool m_noAnimUpdate;
    VfxPoint m_basePos;
};


/***************************************************************************** 
 * Class VfxTextLine
 *****************************************************************************/

class VfxTextLine : public VfxBase
{
public:
    // Default constructor
    VfxTextLine();
    
public:
    // line start and end offset at the whole text
    VfxS32 m_start, m_end;
    // layout region rect of this line
    VfxRect m_rect;
    // y offset of line position
    VfxS32 m_offsetY;
    // indicate whether this line need to be truncated
    VfxBool m_isTruncated;
    // indicate the base line
    VfxS32 m_baseLine;

public:
    // get the next line
    VfxTextLine* getNext() const
    {
        return m_next;
    }

    //get the last line
    VfxTextLine* getLast() const ;
        
    //get the line after n line of this one
    VfxTextLine* getAfter(VfxS32 n);

    // append the next line
    VfxTextLine* appendNext(VfxTextLine* newLine);

    //clear all the line information and return the next line
    VfxTextLine* clear();
    
    //get the max width of all the lines
    VfxS32 getMaxWidth() const;

    // draw string with this line information
    void draw(VfxDrawContext &dc, const VfxWChar *string);
    
private:
    VfxTextLine* m_next;
};


// TODO: this class function should be applied to VfxFontDesc
#include "PixcomFontEngine.h"

class VfxAdpFontEngine
{   
public:
    //measure a string within a area
    VfxU32 getStringWidthHeight(
        const VfxWChar *string,
        VfxS32 w, 
        VfxS32 n, 
        VfxS32 *pWidth, 
        VfxS32 *pHeight, 
        VfxS32 max_width, 
        VfxU8 checkLineBreak, 
        VfxU8 checkCompleteWord
        )
    {
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TF3", SA_start);
    #endif
        VfxU32 ret = Get_StringWidthHeight_variant((VfxU8*)string, w, n, pWidth, pHeight, max_width, checkLineBreak, checkCompleteWord);
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TF3", SA_stop);
    #endif
        return ret;
    }

    void setFont(const VfxFont *font) 
    {
        SetFont((*(stFontAttribute *)font), 0);
    }

    void getCharInfoForAllLang(const VfxFontDesc &font, VfxS32 *pHeight, VfxS32 *pAscent, VfxS32 *pDescent);

    void getCharInfoForCommonLang(const VfxFontDesc &font, VfxS32 *pHeight, VfxS32 *pAscent, VfxS32 *pDescent);
    
    VfxU32 queryStringinfo(mmi_fe_get_string_info_param_struct* query)
    {
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TF4", SA_start);
    #endif
        VfxU32 ret = mmi_fe_get_string_widthheight(query);
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TF4", SA_stop);
    #endif
        return ret;
    }
};

#endif /* __VFX_PRIMITIVE_FRAME_H__ */

