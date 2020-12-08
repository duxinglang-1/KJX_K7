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
 *  vcp_text_layout.h
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  text layout class header file
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

#ifndef __VCP_TEXT_LAYOUT_H__
#define __VCP_TEXT_LAYOUT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_text_utils.h"
#include "vcp_text_storage.h"
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"
#include "vfx_object.h"
#include "vfx_draw_context.h"
#include "vfx_signal.h"
#include "vfx_string.h"
#include "vfx_font_desc.h"
#include "vrt_datatype.h"
#include "lcd_sw_inc.h"

extern "C"
{
#include "PixcomFontEngine.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VCP_MAX_TEXT_LINES                  5
#define VCP_MAX_LINE_CHARS                  MAX_SHOW_STRING_TEXT_LENGTH
#define VCP_MAX_LAYOUT_LINES                200
#define VCP_MIN_LAYOUT_CHARS                300
#define VCP_MAX_LAYOUT_CHARS                2048
#define VCP_MAX_LAYOUT_TIMER                35
#define VCP_TEXT_MASK_CHARACTER             0x002A
#define VCP_TEXT_MIN_FONT_SIZE              (0x80|8)
#define VCP_TEXT_DEFAULT_LINE_GAP           0
#define VCP_TEXT_LINE_SIZE                  (32 + 4 + 8 + 4) // 32 is line struct size, +4 for vfx system memory overhead, +8 for ADM header/footer overhead, +4 for safty

#define VCP_TEXT_FRAME_MAX_WIDTH        UI_DEVICE_HEIGHT
#define VCP_TEXT_FRAME_MAX_HEIGHT       UI_DEVICE_HEIGHT

#define VCP_EDITOR_CURSOR_WIDTH            2
#define VCP_EDITOR_CURSOR_HEIGHT          25

class VcpTextLine;
class VcpTextListLine;
class VcpTextBasicLayout;
class VcpTextStaticLayout;
class VcpTextDynamicLayout;
class VcpTextSingleLineLayout;

// <group DOM_TextUtils_VcpTextLayout_Enum>
// rich text object attribute enum
enum VcpTextWrapStyleEnum
{
    VCP_TEXT_WRAP_CHARACTER_WRAP = 0,   // wrap by character
    VCP_TEXT_WRAP_WORD_WRAP,            // wrap by word
    VCP_TEXT_WRAP_OPERATOR_WRAP,        // wrap by operator "+-X/"
    VCP_TEXT_WARP_END_OF_ENUM
};

/***************************************************************************** 
 * Class VcpTextLine
 *****************************************************************************/
class VcpTextLine : public VfxBase
{
public:
    // Default constructor
    VcpTextLine();

public:
    // line start offset at the whole text
    VfxS32 m_start;
    // line end offset at the whole text
    VfxS32 m_end;
    // layout region rect of this line
    VfxRect m_rect;
    // baseline
    VfxS16 m_baseLine;
    // text height of this line
    VfxU8 m_textHeight;
    // indicate whether this line need to be truncated
    VfxBool m_isTruncated;
};


/***************************************************************************** 
 * Class VcpTextLineBlock
 *****************************************************************************/
class VcpTextLineBlock : public VfxBase
{
public:
    // Default constructor
    VcpTextLineBlock(IVfxAllocatable *client);
    ~VcpTextLineBlock();

public:
    // header line of this block
    VcpTextLine *m_header;

    // point to next line block
    VcpTextLineBlock *m_next;

    IVfxAllocatable *m_client;
};


/***************************************************************************** 
 * Class VcpTextListLine
 *****************************************************************************/

class VcpTextListLine : public VcpTextLine
{
public:
    // Default constructor
    VcpTextListLine();

    
public:
    // get the next line
    VcpTextListLine* getNext()
    {
        return m_next;
    }

    //get the last line
    VcpTextListLine* getLast();
        
    //get the line after n line of this one
    VcpTextListLine* getAfter(VfxS32 n);

    // append the next line
    VcpTextListLine* appendNext(VcpTextListLine* newLine);

    //clear all the line information and return the next line
    VcpTextListLine* clear();
    
public:
    VcpTextListLine* m_next;
};


/***************************************************************************** 
 * Class VcpTextBasicLayout
 *****************************************************************************/

// VcpTextBasicLayout implements the basic logic of text layout. It define all the functions
// of textlayout
class VcpTextBasicLayout : public VfxObject
{
// Constructor / Destructor
public:
    // <group DOM_TextView_VcpTextBasicLayout_Constructor/Destructor>
    VcpTextBasicLayout();

// Method
public:
    // <group DOM_TextView_VcpTextBasicLayout_Enum>
    // Enum for align mode
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
        ALIGN_MODE_END_OF_ENUM
    };

    // <group DOM_TextView_VcpTextBasicLayout_Enum>
    // Enum for vertical align mode
    enum VertAlignModeEnum
    {
        // top aignment
        VERT_ALIGN_MODE_TOP = 0,
        // middle alignment
        VERT_ALIGN_MODE_MID,
        // bottom alignment
        VERT_ALIGN_MODE_BOTTOM,
        // end of alignment
        VERT_ALIGN_MODE_END_OF_ENUM
    };

    // <group DOM_TextView_VcpTextBasicLayout_Enum>
    // Truncate mode
    enum TruncateModeEnum
    {
        // If m_propertyAutoResized is VFX_FALSE, the text is clipped to the frame bounds.
        TRUNCATE_MODE_NONE = 0,
        // Add the truncate string at end of missing text.
        TRUNCATE_MODE_END,
        // Add the truncate string at the middle of text
        TRUNCATE_MODE_MID,
        // truncate with frame max limitation
        TRUNCATE_WITH_AUTO_RESIZE,
        TRUNCATE_MODE_END_OF_ENUM
    };

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // draw one area of this layout
    void draw(VfxDrawContext &dc, const VfxRect &area, VfxPoint offsetToDC, VfxBool isDrawHilite = VFX_FALSE);

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // set the storage for this text layout
    void setTextStorage(VcpTextStorage* storage){
        m_storage = storage;
        m_storage->m_signalTextChanged.connect(this, &VcpTextBasicLayout::onTextChanged);
        onTextChanged(0, m_storage->getTextLength(), 0, VcpTextStorage::TEXT_CHANGE_INIT);
    }

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // set align mode
    void setAlignMode(
        AlignModeEnum value               // align mode
    );

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // set vertical align mode
    void setVerticalAlignMode(
        VertAlignModeEnum value               // align mode
    );

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Set text wrap style.
    void setTextWrapStyle(
        VcpTextWrapStyleEnum wrap             // [IN] Text wrap style.
    );

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // set truncate mode
    void setTruncateMode(TruncateModeEnum value){
        if (m_truncateMode != value)
        {
            m_truncateMode= value;
            checkUpdate();
        }
    }

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // set line gap
    void setLineGap(VfxS32 value);

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // set min line height
    void setMinLineHeight(VfxS32 value);

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Set a range of text to be highlighted
    void setHighlight (
        VfxS32 start,              // [IN] the start index of text
        VfxS32 end                 // [IN] the end index of text
        );

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Get a range of text to be highlighted
    void getHighlight (
        VfxS32 *start,              // [IN] the start index of text
        VfxS32 *end                 // [IN] the end index of text
        );
    
    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // get the height of this layout
    VfxS32 getHeight();

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // get the height of this layout
    VfxS32 getWidth();

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Apply rich text format    
    void applyTextFormat(VfxDrawContext &dc, VcpRichTextFormat *format = NULL);

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Get selection range
    VfxTextRange& getSelection() {
        return m_selection;
    }

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Set selection range
    void setSelection(
        const VfxTextRange& selection             // [IN]   selection range
    );

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Get marked text range
    VfxTextRange& getMarkedText() {
        return m_marked;
    }

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Set marked range
    void setMarkedText(
        const VfxTextRange& marked               // [IN]   marked range
    );

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Set mask character
    void setMask(
        VfxBool isMask                          // [IN]   mask or not
    );

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // get mask character
    VfxBool getMask() const
    {
        return m_isMask;
    }

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Get dirty range
    VfxTextRange& getDirtyRange() {
        return m_dirty;
    }

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Get char index of previous line
    VfxS32 getIndexOfPreLine(VfxS32 index, VfxS32 x);

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Get char index of next line
    VfxS32 getIndexOfNextLine(VfxS32 index, VfxS32 x);

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Get char position of index
    // it will return two point position in case of mix languages
    // example "|abc|CBA"
    VfxPoint getPosOfIndex(VfxS32 index, VfxPoint *point1 = NULL, VcpTextUtils *assignTu = NULL);

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Get char position of index
    VfxPoint getPosOfIndex(VfxPoint pos, VfxS32 index, VcpTextUtils *assignTu = NULL);

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Get char position of index
    VfxS32 getIndexOfPos(VfxS32 lineIndex, VfxS32 offset, VfxPoint *pos, VcpTextUtils *assignTu = NULL);

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Get char position of index
    VfxS32 getIndexOfPos(VfxPoint curPos, VfxPoint *pos, VcpTextUtils *assignTu = NULL);

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Get rich text format of position
    VcpRichTextFormat *getObjectOfPos(const VfxPoint &point);

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Get rich text format of index
    VcpRichTextFormat *getObjectOfIndex(VfxS32 index);

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // if index is the last positon of current line, should not move to next line
    // For example:
    // ________________
    // | Abcdefg|     |
    // | hijklm       |
    // |______________|
    // if cursor is after 'g' and index is 7, lineIndex will be 1, but it should be 0
    VfxBool isIndexInCurrentLine(VfxS32 index, VfxPoint pos);

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Set hint text
    void setHintText(const VfxWString &hintText){
        m_hint = hintText;
    }

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Get hint text
    const VfxWString& getHintText() const {
        return m_hint;
    }

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Hide hint text
    void hideHintText(VfxBool value);

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // set underline flag
    void setUnderline(
        VfxBool value              // [IN]    need underline or not
    )
    {
        m_isUnderline = value;
    }

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // set force layout
    void forceLayout(VfxBool isAsync = VFX_TRUE);

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // draw line text
    void drawLineText(
            VfxDrawContext &dc,
            VfxRect textRect,
            const VcpTextLine &line,
            const VfxWChar *text,
            VfxS32 count,
            VcpRichTextFormat *format,
            VfxBool isDrawHilite = VFX_FALSE
    );

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // draw line text highlight
    void drawLineTextHilite(
            VfxDrawContext &dc, 
            VfxRect textRect,
            const VcpTextLine &line,
            const VfxWChar *text,
            VfxS32 segStart,
            VfxS32 segEnd,
            VfxFontDesc font,
            vrt_text_dir_type_enum dir
    );

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // decrease font size
    VfxBool decFontSize();

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // increase font size
    VfxBool incFontSize();

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // check if the specific index is just after object
    VfxBool isIndexAfterObject(VfxS32 index);

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // set max line number
    void setMaxLineNum(VfxS32 num) { m_maxLineNum = num; }

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // set max line number
    VfxS32 getMaxLineNum() { return m_maxLineNum; }

	// <group DOM_TextView_VcpTextBasicLayout_Method>
	// get line gap
	VfxS32 getLineGap() { return m_lineGap; }

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // set is draw or not
    void setIsDraw(VfxBool value) { m_isDraw = value; }

// Signal    
public:
    // <group DOM_TextView_VcpTextBasicLayout_Signal>
    // Layout changed
    VfxSignal1 <VfxRect> m_signalLayoutChanged;

    // <group DOM_TextView_VcpTextBasicLayout_Signal>
    // Layout changed
    VfxSignal1 <VfxRect> m_signalSelectionChanged;

    // <group DOM_TextView_VcpTextBasicLayout_Event>
    // indicate the max line number reached
    VfxSignal1 <VcpTextBasicLayout*> m_signalMaxLineReached;

// Override
public:
    // <group DOM_TextView_VcpTextBasicLayout_Override>
    // defualt layout is multiline mode 
    virtual VfxBool multiline() const { return VFX_TRUE; }
        
    // <group DOM_TextView_VcpTextBasicLayout_Override>
    // return the number of lines in this layout 
    virtual VfxS32 getLineCount() const = 0;
    
    // <group DOM_TextView_VcpTextBasicLayout_Override>
    // return the text offset of the begginning of the specified line 
    virtual VfxS32 getLineStart(VfxS32 line) = 0;

    // <group DOM_TextView_VcpTextBasicLayout_Override>
    // return the text offset of the end of the specified line 
    virtual VfxS32 getLineEnd(VfxS32 line) = 0;

    // <group DOM_TextView_VcpTextBasicLayout_Override>
    // return the bounds of the specified line
    virtual const VfxRect& getLineBounds(VfxS32 line) = 0;

    // <group DOM_TextView_VcpTextBasicLayout_Override>
    // return the baseline of the specified line
    virtual VfxS32 getLineBaseLine(VfxS32 line) = 0;

    // <group DOM_TextView_VcpTextBasicLayout_Override>
    // return the text height of the specified line
    virtual VfxS32 getLineTextHeight(VfxS32 line) = 0;

    // <group DOM_TextView_VcpTextBasicLayout_Override>
    // draw the specific line
    virtual void drawLine(VfxS32 line, VfxDrawContext &dc, const VfxRect &area, VfxPoint offsetToDC, VfxBool isDrawHilite = VFX_FALSE) = 0;

    // <group DOM_TextView_VcpTextBasicLayout_Override>
    // layout the range (start, end) of text
    virtual void layout(VfxS32 start, VfxS32 end, VfxS32 changedCharCount) = 0;

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // set layout area
    virtual void setLayoutRect(const VfxRect &rect){
        m_layoutRect = rect;
    }

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // get layout area
    virtual const VfxRect& getLayoutRect() const{
        return m_layoutRect;
    }

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // get line index by text offset in buffer
    virtual VfxS32 getLineIndex(VfxS32 index) = 0;

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // get the line index by y position (pixel)
    virtual VfxS32 getLineIndexByY(VfxS32 y) = 0;

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // get line text of specific line
    virtual const VfxWChar* getLineText(VfxS32 lineIndex, VfxS32 *charCount) = 0;

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // set batch edit, if true, layout will not notify layout change
    virtual void setBatch(
        VfxBool is_batch                  // [IN]   batch edit or not
    ) = 0;

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Notify outside that the layout changed
    virtual void sendLayoutChangedNotification(
        VfxRect rect,                // [IN]      layout changed rect
        VfxBool isPost = VFX_FALSE    // [IN]      emit or postEmit the notification
    ) = 0;

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // update view content for custom frame.
    // Can be called when custo frame size or content changes and need to update the whole text view content
    // diff with updateLayout, this function will not relayout. It will only update the bounds
    virtual void UpdateViewForCustomFrame() = 0;

// Implementation
protected:
    // update layout
    void updateLayout(VfxBool isAsync = VFX_TRUE);

    // check update
    void checkUpdate();

    // get alignment by text and set alignment (m_alignMode)
    VcpTextBasicLayout::AlignModeEnum getAlignment();

    // convert to mask character buffer
    // we'll not change the original buffer directly, for example,
    // original buffer is "123a45", 'a' is under multitap state, and the password string will be "***a**"
    void convertToMaskText(const VfxWChar *src, VfxS32 srcLen, VfxWChar *dest, VfxS32 destLen, VfxTextRange markRange);

// Implementation
public:
    VcpTextStorage *m_storage;

    // hint text color
    VfxColor m_hintTextColor;

    // text color
    VfxColor m_normalTextColor;

    // text color
    VfxColor m_underlineColor;

    // text font
    VfxFontDesc m_font;

    // original font size
    VfxS32 m_orgFontSize;

    // check force update
    VfxBool m_checkForceUpdate;

// Implementation
protected:
    // layout rect
    VfxRect m_layoutRect;

    // align mode
    AlignModeEnum m_alignMode;

    // vertical align mode
    VertAlignModeEnum m_verticalAlignMode;

    // truncate mode
    TruncateModeEnum m_truncateMode;

    // gap between lines
    VfxS32 m_lineGap;

    // min line height
    VfxS32 m_minLineHeight;

    // the current selection range
    VfxTextRange m_selection;

    // the current marked range
    VfxTextRange m_marked;

    // the dirty range need to layout
    VfxTextRange m_dirty;

    // hint text when content is empty
    VfxWString m_hint;

    // hide hint text or not when content is empty
    VfxBool m_isHideHint;

    // client frame
    IVfxAllocatable* m_client;

    // if need to draw underline in one line
    VfxBool m_isUnderline;

    // layout direction by language
    vrt_text_dir_type_enum m_direction;

    // mask character mode for password display
    VfxBool m_isMask;

    // change changed
    VfxS32 m_changedCharCount;

    // max line number, if exceed max line, it will break layout and notify
    VfxS32 m_maxLineNum;

    // text wrap style
    VcpTextWrapStyleEnum m_wrapStyle;

    // is draw or not
    VfxBool m_isDraw;

    VfxTimer *m_layoutTimer;

// Implementation
private:
    // on text storage changes
    void onTextChanged(VfxS32 start, VfxS32 end, VfxS32 changedCharCount, VcpTextStorage::TextChangeEnum changed);

private:
    VfxBool m_checkUpdate;
};


/***************************************************************************** 
 * Class VcpTextStaticLayout
 *****************************************************************************/

// VcpTextStaticLayout is a Layout for text that will not be edited after it
// is laid out.  Use VcpTextDynamicLayout for text that may change.
class VcpTextStaticLayout : public VcpTextBasicLayout
{
// Constructor / Destructor
public:
    // <group DOM_TextView_VcpTextStaticLayout_Constructor/Destructor>
    VcpTextStaticLayout(IVfxAllocatable* client);

    virtual ~VcpTextStaticLayout();

// Method
public:
    // <group DOM_TextView_VcpTextStaticLayout_Method>

    
// Signal    
public:
    // <group DOM_TextView_VcpTextStaticLayout_Signal>


// Override
public:
    // <group DOM_TextView_VcpTextStaticLayout_Override>
    // defualt layout is multiline mode 
    virtual VfxBool multiline() const { return VFX_TRUE; }
        
    // <group DOM_TextView_VcpTextStaticLayout_Override>
    // return the number of lines in this layout 
    virtual VfxS32 getLineCount() const { return m_lineCount; }
    
    // <group DOM_TextView_VcpTextStaticLayout_Override>
    // return the text offset of the begginning of the specified line 
    virtual VfxS32 getLineStart(VfxS32 line);

    // <group DOM_TextView_VcpTextStaticLayout_Override>
    // return the text offset of the end of the specified line 
    virtual VfxS32 getLineEnd(VfxS32 line);

    // <group DOM_TextView_VcpTextStaticLayout_Override>
    // return the bounds of the specified line
    virtual const VfxRect& getLineBounds(VfxS32 line);

    // <group DOM_TextView_VcpTextStaticLayout_Override>
    // return the baseline of the specified line
    virtual VfxS32 getLineBaseLine(VfxS32 line);

    // <group DOM_TextView_VcpTextStaticLayout_Override>
    // return the text height of the specified line
    virtual VfxS32 getLineTextHeight(VfxS32 line);

    // <group DOM_TextView_VcpTextStaticLayout_Override>
    // draw the specific line
    virtual void drawLine(VfxS32 line, VfxDrawContext &dc, const VfxRect &area, VfxPoint offsetToDC, VfxBool isDrawHilite = VFX_FALSE);

    // <group DOM_TextView_VcpTextStaticLayout_Override>
    // layout the range (start, end) of text
    // for example in text "0123456", to layout "234", it will be layout(2, 5)
    virtual void layout(VfxS32 start, VfxS32 end, VfxS32 changedCharCount);

    // <group DOM_TextView_VcpTextStaticLayout_Override>
    // set layout area
    virtual void setLayoutRect(const VfxRect &rect);

    // <group DOM_TextView_VcpTextStaticLayout_Override>
    // get line index by text offset in buffer
    virtual VfxS32 getLineIndex(VfxS32 index);

    // <group DOM_TextView_VcpTextStaticLayout_Override>
    // get the line index by y position (pixel)
    virtual VfxS32 getLineIndexByY(VfxS32 y);

    // <group DOM_TextView_VcpTextStaticLayout_Override>
    // get line text of specific line
    virtual const VfxWChar* getLineText(VfxS32 lineIndex, VfxS32 *charCount);

    // <group DOM_TextView_VcpTextStaticLayout_Override>
    // set batch edit, if true, layout will not notify layout change
    virtual void setBatch(
        VfxBool is_batch                  // [IN]   batch edit or not
    ){}

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // Notify outside that the layout changed
    virtual void sendLayoutChangedNotification(
        VfxRect rect,                // [IN]      layout changed rect
        VfxBool isPost = VFX_FALSE    // [IN]      emit or postEmit the notification
    );

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // update view content for custom frame.
    // Can be called when custo frame size or content changes and need to update the whole text view content
    // diff with updateLayout, this function will not relayout. It will only update the bounds
    virtual void UpdateViewForCustomFrame();

// Implementation
public:

    // <group DOM_TextView_VcpTextStaticLayout_Method>
    // Add line after specific index
    void addLine(VcpTextLine &line);

    // <group DOM_TextView_VcpTextStaticLayout_Method>
    // Add line
    VcpTextLine *getLine(VfxS32 line);

    // <group DOM_TextView_VcpTextStaticLayout_Method>
    // delete all lines
    void deleteLines(void);

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // layout Dirty Range
    void layoutDirtyRange(VfxTimer *source);

// Implementation
private:
    // total line count
    VfxS32 m_lineCount;

    // line block
    VcpTextLineBlock *m_lineBlock;

    // tail line block for add block
    VcpTextLineBlock *m_lineTailBlock;

    // block number;
    VfxU32 m_blockNum;

    VfxS32 m_cacheLineBlockIndex;
    
    VcpTextLineBlock *m_cacheLineBlock;
    
};


/***************************************************************************** 
 * Class VcpTextDynamicLayout
 *****************************************************************************/

// VcpTextDynamicLayout is a text layout that updates itself as the text is edited
class VcpTextDynamicLayout : public VcpTextBasicLayout
{
// Constructor / Destructor
public:
    // <group DOM_TextView_VcpTextDynamicLayout_Constructor/Destructor>
    VcpTextDynamicLayout(IVfxAllocatable* client);
    virtual ~VcpTextDynamicLayout();

// Method
public:
    // <group DOM_TextView_VcpTextDynamicLayout_Method>
    
// Signal    
public:
    // <group DOM_TextView_VcpTextDynamicLayout_Signal>


// Override
public:
    // <group DOM_TextView_VcpTextDynamicLayout_Override>
    // defualt layout is multiline mode 
    virtual VfxBool multiline() const { return VFX_TRUE; }
        
    // <group DOM_TextView_VcpTextDynamicLayout_Override>
    // return the number of lines in this layout 
    virtual VfxS32 getLineCount() const { return m_lineCount; }
    
    // <group DOM_TextView_VcpTextDynamicLayout_Override>
    // return the text offset of the begginning of the specified line 
    virtual VfxS32 getLineStart(VfxS32 line);

    // <group DOM_TextView_VcpTextDynamicLayout_Override>
    // return the text offset of the end of the specified line 
    virtual VfxS32 getLineEnd(VfxS32 line);

    // <group DOM_TextView_VcpTextDynamicLayout_Override>
    // return the bounds of the specified line
    virtual const VfxRect& getLineBounds(VfxS32 line);

    // <group DOM_TextView_VcpTextDynamicLayout_Override>
    // return the baseline of the specified line
    virtual VfxS32 getLineBaseLine(VfxS32 line);

    // <group DOM_TextView_VcpTextDynamicLayout_Override>
    // return the text height of the specified line
    virtual VfxS32 getLineTextHeight(VfxS32 line);

    // <group DOM_TextView_VcpTextDynamicLayout_Override>
    // draw the specific line
    virtual void drawLine(VfxS32 line, VfxDrawContext &dc, const VfxRect &area, VfxPoint offsetToDC, VfxBool isDrawHilite = VFX_FALSE);

    // <group DOM_TextView_VcpTextDynamicLayout_Override>
    // layout the range (start, end) of text
    virtual void layout(VfxS32 start, VfxS32 end, VfxS32 changedCharCount);

    // <group DOM_TextView_VcpTextDynamicLayout_Override>
    // set layout area
    virtual void setLayoutRect(const VfxRect &rect);

    // <group DOM_TextView_VcpTextDynamicLayout_Override>
    // get line index by text offset in buffer
    virtual VfxS32 getLineIndex(VfxS32 index);

    // <group DOM_TextView_VcpTextDynamicLayout_Override>
    // get the line index by y position (pixel)
    virtual VfxS32 getLineIndexByY(VfxS32 y);

    // <group DOM_TextView_VcpTextDynamicLayout_Override>
    // get line text of specific line
    virtual const VfxWChar* getLineText(VfxS32 lineIndex, VfxS32 *charCount);

    // <group DOM_TextView_VcpTextDynamicLayout_Override>
    // set batch edit, if true, layout will not notify layout change
    virtual void setBatch(
        VfxBool is_batch                  // [IN]   batch edit or not
    );

    // <group DOM_TextView_VcpTextDynamicLayout_Override>
    // Notify outside that the layout changed
    virtual void sendLayoutChangedNotification(
        VfxRect rect,                // [IN]      layout changed rect
        VfxBool isPost = VFX_FALSE    // [IN]      emit or postEmit the notification
    );

    // <group DOM_TextView_VcpTextDynamicLayout_Override>
    // update view content for custom frame.
    // Can be called when custo frame size or content changes and need to update the whole text view content
    // diff with updateLayout, this function will not relayout. It will only update the bounds
    virtual void UpdateViewForCustomFrame();

// Implementation
public:

// Implementation
private:
    // get line by line index
    VcpTextListLine* getLine(VfxS32 index);

    // clear all lines
    void clearLines();

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // delete lines, return deleted lines total height
    VfxS32 deleteLines(VfxS32 start, VfxS32 end, VfxS32 changedCharCount);

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // insert line after index line
    void insertLine(VcpTextListLine *line, VfxS32 index);

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // layout Dirty Range
    void layoutDirtyRange(VfxTimer *source);

    // <group DOM_TextView_VcpTextBasicLayout_Method>
    // get line index from origin buffer
    VfxS32 getLineIndexFromOrg(VfxS32 index);

// Implementation
private:
    // total line count
    VfxS32 m_lineCount;
    // line pointer, use array for static layout
    VcpTextListLine *m_lines;

    // cache line index
    VfxS32 m_cacheLineIndex;

    // cache line pointer
    VcpTextListLine *m_cacheLine;

    // batch edit flag
    VfxBool m_batch;

    // batch edit rect
    VfxRect m_batchRect;
};


/***************************************************************************** 
 * Class VcpTextSingleLineLayout
 *****************************************************************************/

// VcpTextSingleLineLayout is a Single line Layout for text.
class VcpTextSingleLineLayout : public VcpTextBasicLayout
{
// Constructor / Destructor
public:
    // <group DOM_TextView_VcpTextSingleLineLayout_Constructor/Destructor>
    VcpTextSingleLineLayout(IVfxAllocatable* client);

    virtual ~VcpTextSingleLineLayout();

// Method
public:
    // <group DOM_TextView_VcpTextSingleLineLayout_Method>

    
// Signal    
public:
    // <group DOM_TextView_VcpTextSingleLineLayout_Signal>


// Override
public:
    // <group DOM_TextView_VcpTextSingleLineLayout_Override>
    // defualt layout is multiline mode 
    virtual VfxBool multiline() const { return VFX_FALSE; }
        
    // <group DOM_TextView_VcpTextSingleLineLayout_Override>
    // return the number of lines in this layout 
    virtual VfxS32 getLineCount() const { return 1; }
    
    // <group DOM_TextView_VcpTextSingleLineLayout_Override>
    // return the text offset of the begginning of the specified line 
    virtual VfxS32 getLineStart(VfxS32 line);

    // <group DOM_TextView_VcpTextSingleLineLayout_Override>
    // return the text offset of the end of the specified line 
    virtual VfxS32 getLineEnd(VfxS32 line);

    // <group DOM_TextView_VcpTextSingleLineLayout_Override>
    // return the bounds of the specified line
    virtual const VfxRect& getLineBounds(VfxS32 line);

    // <group DOM_TextView_VcpTextSingleLineLayout_Override>
    // return the baseline of the specified line
    virtual VfxS32 getLineBaseLine(VfxS32 line);

    // <group DOM_TextView_VcpTextSingleLineLayout_Override>
    // return the text height of the specified line
    virtual VfxS32 getLineTextHeight(VfxS32 line);

    // <group DOM_TextView_VcpTextSingleLineLayout_Override>
    // draw the specific line
    virtual void drawLine(VfxS32 line, VfxDrawContext &dc, const VfxRect &area, VfxPoint offsetToDC, VfxBool isDrawHilite = VFX_FALSE);

    // <group DOM_TextView_VcpTextSingleLineLayout_Override>
    // layout the range (start, end) of text
    virtual void layout(VfxS32 start, VfxS32 end, VfxS32 changedCharCount);

    // <group DOM_TextView_VcpTextSingleLineLayout_Override>
    // set layout area
    virtual void setLayoutRect(const VfxRect &rect);

    // <group DOM_TextView_VcpTextSingleLineLayout_Override>
    // get line index by text offset in buffer
    virtual VfxS32 getLineIndex(VfxS32 index);

    // <group DOM_TextView_VcpTextSingleLineLayout_Override>
    // get the line index by y position (pixel)
    virtual VfxS32 getLineIndexByY(VfxS32 y) { return 0; }

    // <group DOM_TextView_VcpTextSingleLineLayout_Override>
    // get line text of specific line
    virtual const VfxWChar* getLineText(VfxS32 lineIndex, VfxS32 *charCount);

    // <group DOM_TextView_VcpTextSingleLineLayout_Override>
    // set batch edit, if true, layout will not notify layout change
    virtual void setBatch(
        VfxBool is_batch                  // [IN]   batch edit or not
    );

    // <group DOM_TextView_VcpTextSingleLineLayout_Override>
    // set layout chagned notification
    virtual void sendLayoutChangedNotification(
        VfxRect rect, 
        VfxBool isPost = VFX_FALSE
        );

    // <group DOM_TextView_VcpTextSingleLineLayout_Override>
    // update view content for custom frame.
    // Can be called when custo frame size or content changes and need to update the whole text view content
    // diff with updateLayout, this function will not relayout. It will only update the bounds
    virtual void UpdateViewForCustomFrame() {}

// Implementation
private:
    // line
    VcpTextLine m_lines;

    // batch edit flag
    VfxBool m_batch;

    // batch edit rect
    VfxRect m_batchRect;
};

#endif /* __VCP_TEXT_LAYOUT_H__ */
