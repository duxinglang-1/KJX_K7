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
 *  vcp_text_view.h
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  textview class header file
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

#ifndef __VCP_TEXT_VIEW_H__
#define __VCP_TEXT_VIEW_H__

// config
#if defined(__COSMOS_MMI_PACKAGE__)
// only support cosmos because only cosmos has magnifier image
#define VCP_TEXT_MAGNIFIER_SUPPORT         1
#else
#define VCP_TEXT_MAGNIFIER_SUPPORT         0
#endif

#if defined(__MMI_CLIPBOARD__)
#define VCP_TEXT_CLIPBOARD_SUPPORT         1
#else
#define VCP_TEXT_CLIPBOARD_SUPPORT         0
#endif

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "ime\vsrv_input_manager.h"
#include "vcp_button.h"

#if VCP_TEXT_CLIPBOARD_SUPPORT
#include "clipboard\vsrv_clipboard.h"
#endif

#include "vcp_text_utils.h"
#include "vcp_text_storage.h"
#include "vcp_text_layout.h"
#include "vcp_scrollable.h"
#if defined(__COSMOS_MMI_PACKAGE__)
#include "vcp_activity_indicator.h"
#endif
#include "GUI\vadp_v2p_inputbox.h"
#include "lcd_sw_inc.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vfx_string.h"
#include "vrt_datatype.h"
#include "vfx_font_desc.h"
#include "vfx_stream.h"
#include "vfx_cpp_base.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"
#include "vfx_draw_context.h"
#include "vfx_input_event.h"
#include "vfx_control.h"

/***************************************************************************** 
 * Defination
 *****************************************************************************/
// <group DOM_TextView_Macro&Enum_Macro>
#define VCP_TEXTVIEW_CLASS_NAME             "TextView"
#define VCP_TEXTVIEW_CELLVIEW_MAX           4
#define VCP_TEXTVIEW_AUTO_SCROLL_TIMER      10
#define VCP_TEXTVIEW_AUTO_SCROLL_OFFSET      5

#if defined(__MMI_MAINLCD_480X800__)
#define VCP_TEXTVIEW_TAP_DISTANCE_RADIUS        42
#elif defined(__MMI_MAINLCD_320X480__)
#define VCP_TEXTVIEW_TAP_DISTANCE_RADIUS        28
#elif defined(__MMI_MAINLCD_240X400__)
#define VCP_TEXTVIEW_TAP_DISTANCE_RADIUS        25
#else
#define VCP_TEXTVIEW_TAP_DISTANCE_RADIUS        20
#endif

#if VCP_TEXT_MAGNIFIER_SUPPORT
#define VCP_TEXT_MAGNIFIER_START_TIMER        (600 - 400) // should conside the scrollable pen delay and VRT render timer
#define VCP_TEXTVIEW_CLIPBOARD_START_TIMER    (800 - 100) // should conside the scrollable pen delay and VRT render timer
#else
#define VCP_TEXTVIEW_CLIPBOARD_START_TIMER    (600 - 400) // should conside the scrollable pen delay and VRT render timer
#endif

// LCD related macro
#if defined(__MMI_MAINLCD_320X480__)
#define VCP_TEXTVIEW_BG_IMAGE_TD_MARGIN    10
#define VCP_TEXTVIEW_BG_IMAGE_LR_MARGIN    10
#define VCP_TEXTVIEW_MARGIN_FRAME_GAP       8
#define VCP_TEXTVIEW_DEFAULT_MARGIN         0
#define VCP_TEXTVIEW_AUTO_RESIZE_MIN_WIDTH  30
#define VCP_TEXTVIEW_AUTO_RESIZE_MAX_WIDTH  0x7FFFFFFF
#define VCP_TEXTVIEW_AUTO_RESIZE_MIN_HEIGHT 39
#define VCP_TEXTVIEW_AUTO_RESIZE_MAX_HEIGHT 0x7FFFFFFF
#define VCP_TEXTVIEW_DETAIL_TITLE_FONT_SIZE   20
#define VCP_TEXTVIEW_DETAIL_CONTENT_FONT_SIZE 16
#define VCP_TEXTVIEW_DETAIL_MIN_FONT_SIZE      4
#define VCP_TEXTVIEW_WAITING_ICON_SIZE         50
#if VCP_TEXT_MAGNIFIER_SUPPORT
#define VCP_TEXT_MAGNIFIER_WIDTH               152
#define VCP_TEXT_MAGNIFIER_HEIGHT               65
#define VCP_TEXT_MAGNIFIER_BG_OPACITY          1.0
#define VCP_TEXT_MAGNIFIER_CONTENT_X             4
#define VCP_TEXT_MAGNIFIER_CONTENT_Y             0
#define VCP_TEXT_MAGNIFIER_CONTENT_WIDTH       144
#define VCP_TEXT_MAGNIFIER_CONTENT_HEIGHT       58
#define VCP_TEXT_MAGNIFIER_FONT_SIZE            32
#define VCP_TEXT_MAGNIFIER_CURSOR_WIDTH          2
#define VCP_TEXT_MAGNIFIER_CURSOR_HEIGHT        50
#define VCP_TEXT_MAGNIFIER_MARK_CURSOR_WIDTH    11
#define VCP_TEXT_MAGNIFIER_MARK_CURSOR_HEIGHT   58
#define VCP_TEXT_MAGNIFIER_DIST_TO_TEXT         10
#endif
#elif defined(__MMI_MAINLCD_480X800__)
#define VCP_TEXTVIEW_BG_IMAGE_TD_MARGIN     18
#define VCP_TEXTVIEW_BG_IMAGE_LR_MARGIN     14
#define VCP_TEXTVIEW_MARGIN_FRAME_GAP       14
#define VCP_TEXTVIEW_DEFAULT_MARGIN          0
#define VCP_TEXTVIEW_AUTO_RESIZE_MIN_WIDTH  30
#define VCP_TEXTVIEW_AUTO_RESIZE_MAX_WIDTH  0x7FFFFFFF
#define VCP_TEXTVIEW_AUTO_RESIZE_MIN_HEIGHT 76
#define VCP_TEXTVIEW_AUTO_RESIZE_MAX_HEIGHT 0x7FFFFFFF
#define VCP_TEXTVIEW_DETAIL_TITLE_FONT_SIZE   30
#define VCP_TEXTVIEW_DETAIL_CONTENT_FONT_SIZE 26
#define VCP_TEXTVIEW_DETAIL_MIN_FONT_SIZE     10
#define VCP_TEXTVIEW_WAITING_ICON_SIZE        70
#if VCP_TEXT_MAGNIFIER_SUPPORT
#define VCP_TEXT_MAGNIFIER_WIDTH               257
#define VCP_TEXT_MAGNIFIER_HEIGHT              112
#define VCP_TEXT_MAGNIFIER_BG_OPACITY          1.0
#define VCP_TEXT_MAGNIFIER_CONTENT_X            10
#define VCP_TEXT_MAGNIFIER_CONTENT_Y             0
#define VCP_TEXT_MAGNIFIER_CONTENT_WIDTH       237
#define VCP_TEXT_MAGNIFIER_CONTENT_HEIGHT       95
#define VCP_TEXT_MAGNIFIER_FONT_SIZE            58
#define VCP_TEXT_MAGNIFIER_CURSOR_WIDTH          3
#define VCP_TEXT_MAGNIFIER_CURSOR_HEIGHT        87
#define VCP_TEXT_MAGNIFIER_MARK_CURSOR_WIDTH    15
#define VCP_TEXT_MAGNIFIER_MARK_CURSOR_HEIGHT   87
#define VCP_TEXT_MAGNIFIER_DIST_TO_TEXT         17
#endif
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
#define VCP_TEXTVIEW_BG_IMAGE_TD_MARGIN     10
#define VCP_TEXTVIEW_BG_IMAGE_LR_MARGIN     10
#define VCP_TEXTVIEW_MARGIN_FRAME_GAP       5
#define VCP_TEXTVIEW_DEFAULT_MARGIN         0
#define VCP_TEXTVIEW_AUTO_RESIZE_MIN_WIDTH  30
#define VCP_TEXTVIEW_AUTO_RESIZE_MAX_WIDTH  0x7FFFFFFF
#define VCP_TEXTVIEW_AUTO_RESIZE_MIN_HEIGHT 39
#define VCP_TEXTVIEW_AUTO_RESIZE_MAX_HEIGHT 0x7FFFFFFF
#define VCP_TEXTVIEW_DETAIL_TITLE_FONT_SIZE   16
#define VCP_TEXTVIEW_DETAIL_CONTENT_FONT_SIZE 14
#define VCP_TEXTVIEW_DETAIL_MIN_FONT_SIZE      3
#define VCP_TEXTVIEW_WAITING_ICON_SIZE         40
#if VCP_TEXT_MAGNIFIER_SUPPORT
#define VCP_TEXT_MAGNIFIER_WIDTH               126
#define VCP_TEXT_MAGNIFIER_HEIGHT               56
#define VCP_TEXT_MAGNIFIER_BG_OPACITY          1.0
#define VCP_TEXT_MAGNIFIER_CONTENT_X             1
#define VCP_TEXT_MAGNIFIER_CONTENT_Y             0
#define VCP_TEXT_MAGNIFIER_CONTENT_WIDTH       124
#define VCP_TEXT_MAGNIFIER_CONTENT_HEIGHT       56
#define VCP_TEXT_MAGNIFIER_FONT_SIZE            28
#define VCP_TEXT_MAGNIFIER_CURSOR_WIDTH          2
#define VCP_TEXT_MAGNIFIER_CURSOR_HEIGHT        40
#define VCP_TEXT_MAGNIFIER_MARK_CURSOR_WIDTH    11
#define VCP_TEXT_MAGNIFIER_MARK_CURSOR_HEIGHT   40
#define VCP_TEXT_MAGNIFIER_DIST_TO_TEXT         10
#endif
#else
#define VCP_TEXTVIEW_BG_IMAGE_TD_MARGIN    10
#define VCP_TEXTVIEW_BG_IMAGE_LR_MARGIN    10
#define VCP_TEXTVIEW_MARGIN_FRAME_GAP       8
#define VCP_TEXTVIEW_DEFAULT_MARGIN         0
#define VCP_TEXTVIEW_AUTO_RESIZE_MIN_WIDTH  30
#define VCP_TEXTVIEW_AUTO_RESIZE_MAX_WIDTH  0x7FFFFFFF
#define VCP_TEXTVIEW_AUTO_RESIZE_MIN_HEIGHT 40
#define VCP_TEXTVIEW_AUTO_RESIZE_MAX_HEIGHT 0x7FFFFFFF
#define VCP_TEXTVIEW_DETAIL_TITLE_FONT_SIZE   20
#define VCP_TEXTVIEW_DETAIL_CONTENT_FONT_SIZE 16
#define VCP_TEXTVIEW_DETAIL_MIN_FONT_SIZE     8
#define VCP_TEXTVIEW_WAITING_ICON_SIZE        50
#if VCP_TEXT_MAGNIFIER_SUPPORT
#define VCP_TEXT_MAGNIFIER_WIDTH               152
#define VCP_TEXT_MAGNIFIER_HEIGHT               65
#define VCP_TEXT_MAGNIFIER_BG_OPACITY          1.0
#define VCP_TEXT_MAGNIFIER_CONTENT_X             4
#define VCP_TEXT_MAGNIFIER_CONTENT_Y             0
#define VCP_TEXT_MAGNIFIER_CONTENT_WIDTH       144
#define VCP_TEXT_MAGNIFIER_CONTENT_HEIGHT       58
#define VCP_TEXT_MAGNIFIER_FONT_SIZE            32
#define VCP_TEXT_MAGNIFIER_CURSOR_WIDTH          2
#define VCP_TEXT_MAGNIFIER_CURSOR_HEIGHT        50
#define VCP_TEXT_MAGNIFIER_MARK_CURSOR_WIDTH    11
#define VCP_TEXT_MAGNIFIER_MARK_CURSOR_HEIGHT   58
#define VCP_TEXT_MAGNIFIER_DIST_TO_TEXT         10
#endif
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

class VcpTextView;
class VcpTextScrollView;
class VcpTextCellView;
class VcpTextBasicLayout;
class VcpTextStaticLayout;
class VcpTextDynamicLayout;
class VcpTextLine;
class VcpTextListLine;
class VcpEditing;
class VcpTextEbookView;
class VcpTextEbookReader;
class VcpTextInputStream;
class VcpTextCellContentView;

#if VCP_TEXT_MAGNIFIER_SUPPORT
class VcpTextMagnifier;
#endif

// <group DOM_TextView_VcpTextView_Enum>
// Enum for textview line mode
enum VcpTextLineModeEnum
{
    VCP_TEXT_LINE_MODE_SINGLE,
    VCP_TEXT_LINE_MODE_MULTI,
    VCP_TEXT_LINE_MODE_END_OF_ENUM
};

// <group DOM_TextView_VcpTextView_Enum>
// Color ID
enum VcpTextColorTypeEnum
{
    VCP_TEXT_NORMAL_TEXT_COLOR,
    VCP_TEXT_HINT_TEXT_COLOR,
    /* DOM-NOT_FOR_SDK-BEGIN */
    VCP_TEXT_HIGHLIGHTED_TEXT_COLOR,
    VCP_TEXT_HIGHLIGHT_FILLER_COLOR,
    /* DOM-NOT_FOR_SDK-END */
    VCP_TEXT_UNDERLINE_COLOR,
    VCP_TEXT_COLOR_TYPE_END_OF_ENUM
};

// <group DOM_TextView_VcpTextView_Enum>
// Horizontal alignment mode
enum VcpTextAlignModeEnum
{
    // The natural alignment according to the system language
    VCP_TEXT_ALIGN_MODE_NATURAL = 0,
    // Align text to the left side of frame bounds
    VCP_TEXT_ALIGN_MODE_LEFT,
    // Align text to the right side of frame bounds
    VCP_TEXT_ALIGN_MODE_RIGHT,
    // Align text to the center of frame bounds
    VCP_TEXT_ALIGN_MODE_CENTER,
    // Align text to the ceter of available area within margin
    VCP_TEXT_ALIGN_MODE_CENTER_WITHIN_MARGIN,
    VCP_TEXT_ALIGN_MODE_END_OF_ENUM
};

// <group DOM_TextView_VcpTextView_Enum>
// Vertical alignment mode
enum VcpTextVertAlignModeEnum
{
    // align top
    VCP_TEXT_VERT_ALIGN_MODE_TOP = 0,
    // align middle
    VCP_TEXT_VERT_ALIGN_MODE_MID,
    // align bottom
    VCP_TEXT_VERT_ALIGN_MODE_BOTTOM,
    // align end
    VCP_TEXT_VERT_ALIGN_MODE_END_OF_ENUM
};

// <group DOM_TextView_VcpTextView_Enum>
// Truncate mode
enum VcpTextTruncateModeEnum
{
    // If m_propertyAutoResized is VFX_FALSE, the text is clipped to the frame bounds.
    VCP_TEXT_TRUNCATE_MODE_NONE = 0,
    // Add the truncate string at end of missing text.
    VCP_TEXT_TRUNCATE_MODE_END,
    // Add the truncate string at the middle of text
    VCP_TEXT_TRUNCATE_MODE_MID,
    // truncate with frame max limitation
    VCP_TEXT_TRUNCATE_WITH_AUTO_RESIZE,
    VCP_TEXT_TRUNCATE_MODE_END_OF_ENUM
};

// <group DOM_TextView_VcpTextView_Enum>
// Margin frame enum
enum VcpTextMarginFrameEnum
{
    // Margin image on left side
    VCP_TEXT_MARGIN_FRAME_LEFT = 0,
    // Margin image on left side
    VCP_TEXT_MARGIN_FRAME_RIGHT,
    // Margin image on top side
    VCP_TEXT_MARGIN_FRAME_TOP,
    // Margin image on bottom side
    VCP_TEXT_MARGIN_FRAME_BOTTOM,
    VCP_TEXT_MARGIN_FRAME_TOTAL
};

// <group DOM_TextView_VcpTextView_Enum>
// detail enum
enum VcpTextDetailEnum
{
    // Detail title
    VCP_TEXT_DETAIL_TITLE = 0,
    // Detail content
    VCP_TEXT_DETAIL_CONTENT,

    VCP_TEXT_DETAIL_END_OF_ENUM
};

// <group DOM_TextView_VcpTextView_Enum>
// tap area enum
enum VcpTextTapAreaEnum
{
    // Tap on text
    VCP_TEXT_TAP_AREA_TEXT = 0,
    // Tap on object
    VCP_TEXT_TAP_AREA_OBJECT,
    // Tap on empty area
    VCP_TEXT_TAP_AREA_EMPTY,

    VCP_TEXT_TAP_AREA_END_OF_ENUM
};


// <group DOM_Editor_VcpTextEditor_Enum>
// the editor tone type enum
enum VcpTextToneEnum
{
    // the text can't be insert
    VCP_TEXT_TONE_CANNOT_INSERT,
    // the text to be delete
    VCP_TEXT_TONE_CANNOT_DELETE,
    // the text to be delete all
    VCP_TEXT_TONE_CANNOT_NAVIGATE,
    // END of Enum
    VCP_TEXT_TONE_END_OF_ENUM
};


/***************************************************************************** 
 * Class VcpTextView
 *****************************************************************************/

/*
 * DESCRIPTION
 *  Text View mainly displays large number of read-only text in multiple lines,
 *  which is different from the single line display text such as Text Frame
 *  VcpTextView is a richtext control. Defaultly, it is configured to non-editable.
 *  Use VcpTextEditor to get an editable text control.
 * EXAMPLE
 * <code>
 *   VcpTextView *m_text;
 *   VFX_OBJ_CREATE(m_text, VcpTextView, this);
 *   m_text->setPos(VfxPoint(TEXT_X_OFFSET, TEXT_Y_OFFSET));
 *   m_text->setBounds(VfxRect(0, 0, TEXT_WIDTH, TEXT_HEIGHT));
 *   m_text->setText(viewText);
 *   m_text->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
 * </code>
 */
class VcpTextView : public VcpScrollable
{
    VFX_DECLARE_CLASS(VcpTextView);

// Constructor / Destructor
public:
    // <group DOM_TextView_VcpTextView_Constructor/Destructor>
    VcpTextView();

// Variable
public:
    // <group DOM_TextView_VcpTextView_Variable>
    // The pointer of one VcpEditing instance, which can make this text view editable
    VcpEditing *m_editing;
    
// Signal
public:
    // <group DOM_Editor_VcpTextView_Event>
    // indicate the keyword text have been clicked
    VfxSignal3 <
        VcpTextKeyWordEnum,     // [IN] key word type
        VfxWChar *,             // [IN] key word text
        VfxS32>                 // [IN] key word text length
        m_signalKeywordClick;

    // <group DOM_Editor_VcpTextView_Event>
    // tapped event on text view
    VfxSignal3 <
        VcpTextView *,          // [IN] text view object
        VcpTextTapAreaEnum,     // [IN] tap area
        VcpRichTextFormat *>    // [IN] tapped object
        m_signalTapEvent;

    // <group DOM_Editor_VcpTextView_Event>
    // on hyper link clicked
    VfxSignal2 <
        VcpTextView *,          // [IN] text view object
        VfxWString>             // [IN] hyper link text
        m_signalHyperLinkClicked;

// Method
public:
    // <group DOM_TextView_VcpTextView_Method>
    // Set text with a resource string id
    void setText(
        VfxResId resId,                    // [IN] resource id of string
        VcpRichTextFormat *format = NULL   // [IN] text format appended to the string
        );

    // <group DOM_TextView_VcpTextView_Method>
    // Set text with a const string
    void setText(
        const VfxWString &text,            // [IN] text content
        VfxBool isStaticBuf = VFX_FALSE,   // [IN] need editor malloc buffer for edit
        VcpRichTextFormat *format = NULL   // [IN] text format appended to the string
        );

    // <group DOM_TextView_VcpTextView_Method>
    // Set text with a const string
    void setText(
        const VfxWChar *text,              // [IN] text content
        VfxBool isStaticBuf = VFX_FALSE,   // [IN] need editor malloc buffer for edit
        VcpRichTextFormat *format = NULL   // [IN] text format appended to the string
        );

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /* DOM-NOT_FOR_SDK-BEGIN */

    // <group DOM_TextView_VcpTextView_Method>
    // Add text to the editor of current text buffer
    VfxS32 addText(
        const VfxWString &text,             // [IN] text 
        VfxS32 maxLen,                      // [IN] max length of original buffer
        VcpRichTextFormat *format = NULL    // [IN] text format object list
        );

    // <group DOM_TextView_VcpTextView_Method>
    // Add detail to current text buffer
    VfxBool addDetail(
        const VfxWString &text,             // [IN] text 
        VcpTextDetailEnum dType,            // [IN] detail type
        VfxS32 maxLen                       // [IN] max character length of detail buffer
        );

    /* DOM-NOT_FOR_SDK-END */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    // <group DOM_TextView_VcpTextView_Method>
    // Set the font of text    
    void setFont(
        const VfxFontDesc &fontDesc        // [IN] The font description to set
    );

    // <group DOM_TextView_VcpTextView_Method>
    // get the font of text    
    VfxFontDesc &getFont() const;

    // <group DOM_TextView_VcpTextView_Method>
    // Return the plain text of TextView
    VfxWChar *getText() const;

    // <group DOM_TextView_VcpTextView_Method>
    // Return the format object list of TextView
    VcpRichTextFormat *getFormatObject() const;

    // <group DOM_TextView_VcpTextView_Method>
    // Return the text length
    VfxS32 getLength() const;
    
    // <group DOM_TextView_VcpTextView_Method>
    // Set the Hint text with string id for empty content
    void setHint(
        VfxResId resId            // [IN] resource id of hint text
        );

    // <group DOM_TextView_VcpTextView_Method>
    // Set the Hint text for empty content
    void setHint(
        const VfxWString &string  // [IN] hint text pointer
        );

    // <group DOM_TextView_VcpTextView_Method>
    // Set margins to this text view
    void setMargins(
        VfxS32 value            // [IN] Set all margins to the value
    );
    
    // <group DOM_TextView_VcpTextView_Method>
    // Set margins to this text view
    void setMargins(
        VfxS32 leftMargin,     // [IN] Set left margin to the value
        VfxS32 topMargin,      // [IN] Set top margin to the value
        VfxS32 rightMargin,    // [IN] Set right margin to the value
        VfxS32 bottomMargin    // [IN] Set bottom margin to the value
    );

    // <group DOM_TextView_VcpTextView_Method>
    // get margins of this text view
    void getMargins(
        VfxS32 *leftMargin,     // [IN] Set left margin to the value
        VfxS32 *topMargin,      // [IN] Set top margin to the value
        VfxS32 *rightMargin,    // [IN] Set right margin to the value
        VfxS32 *bottomMargin    // [IN] Set bottom margin to the value
    );
    
    // <group DOM_TextView_VcpTextView_Method>
    // Get the Hint text content
    const VfxWString &getHint() const;

    /* DOM-NOT_FOR_SDK-BEGIN */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /* DOM-NOT_FOR_SDK-END */

    // <group DOM_TextView_VcpTextView_Method>
    // Set a textformat to the current content, the text format object should linked as a list
    void setTextFormat(
        VcpRichTextFormat  *format     // [IN] text format appended to this view's content
        );

    // <group DOM_TextView_VcpTextView_Method>
    // Add a textformat to the current content
    void addTextFormat(
        const VcpRichTextFormat &format     // [IN] text format appended to this view's content
        );

    // <group DOM_TextView_VcpTextView_Method>
    // Remove a textformat to the current content
    VfxBool removeTextFormat(
        const VcpRichTextFormat &format     // [IN] text format appended to this view's content
        );

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
#endif

    // <group DOM_TextView_VcpTextView_Method>
    // Set line mode to Single or Multiline
    void setLineMode(
        VcpTextLineModeEnum mode            // [IN] line mode
        );

    // <group DOM_TextView_VcpTextView_Method>
    // Set a range of text to be highlighted
    void setHighlight(
        VfxS32 start,              // [IN] the start index of text
        VfxS32 end                 // [IN] the end index of text
        );

    // <group DOM_TextView_VcpTextView_Method>
    // Get a range of text to be highlighted
    void getHighlight(
        VfxS32 *start,              // [IN] the start index of text
        VfxS32 *end                 // [IN] the end index of text
        );

    // <group DOM_TextView_VcpTextView_Method>
    // set line gap
    void setLineGap(
        VfxS32 value                // [IN] line gap value
        );

    // <group DOM_TextView_VcpTextView_Method>
    // Set hype link text
    // Please use this API after setText because setText will clear all text format
    void setHyperLink(
        VfxS32 start,                       // [IN] the start index of text
        VfxS32 end,                         // [IN] the end index of text
        const VfxWString &hyperlink,        // [IN] the URL assigned to the text from start to end
        VfxFontDesc *font = NULL            // [IN] hyper link text font
        );

    // <group DOM_TextView_VcpTextView_Method>
    // Set Keyword Mode, only support text view mode, text editor don't support this feature
    void setKeyword(
        VfxS32  mode                        // [IN] keyword mode, use VcpTextKeyWordEnum
        );

    // <group DOM_TextView_VcpTextView_Method>
    // Set the icon Mode
    void setIconMode(
        VfxBool mode,                       // [IN] icon mode or not
        VcpIconTable *mapping = NULL,       // [IN] icon mapping table
        VfxU8 size = 0                      // [IN] mapping table size
        );

    // <group DOM_TextView_VcpTextView_Method>
    // set truncate mode
    void setTruncateMode(
        VcpTextTruncateModeEnum value       // [IN] truncate mode
        );

    // <group DOM_TextView_VcpTextView_Method>
    // set progress value, the value should be within (0, 100) which is the percentage
    void setProgressValue(
        VfxFloat value                      // [IN] the value should be within (0, 100) which is the percentage
        );

    // <group DOM_TextView_VcpTextView_Method>
    // Set a color value for the item referred by colorId 
    void setColor(
        VcpTextColorTypeEnum  id,            // [IN] the id of color to be set
        const VfxColor &vColor               // [IN] the color value
        );

    // <group DOM_TextView_VcpTextView_Method>
    // Set a color value for the item referred by colorId 
    void setMinLineHeight(
        VfxS32 value                        // [IN] min line height
        );

    // <group DOM_TextView_VcpTextView_Method>
    // set underline style
    void setUnderline(
        VfxBool value                       // [IN] need underline or not
    )
    {
        m_layout->setUnderline(value);
    }

    /* DOM-NOT_FOR_SDK-BEGIN */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /* DOM-NOT_FOR_SDK-END */

    // <group DOM_TextView_VcpTextView_Method>
    // set normal background image
    void setNormalBgImage(
        VfxResId imageId                    // [IN] image id in resource
        );

    // <group DOM_TextView_VcpTextView_Method>
    // set highlight background image
    void setHiliteBgImage(
        VfxResId imageId                    // [IN] image id in resource
        );

    /* DOM-NOT_FOR_SDK-BEGIN */
    // <group DOM_TextView_VcpTextView_Method>
    // Set text Horizontal align mode.
    // Obsolete, will be removed, please use setHorizontalAlignMode instead
    void setAlignMode(
        VcpTextAlignModeEnum value          // [IN] Text algin mode.
    );
    /* DOM-NOT_FOR_SDK-END */

    // <group DOM_TextView_VcpTextView_Method>
    // Set text Horizontal align mode.
    void setHorizontalAlignMode(
        VcpTextAlignModeEnum value          // [IN] Text algin mode.
    );

    // <group DOM_TextView_VcpTextView_Method>
    // Set text vertical align mode.
    void setVerticalAlignMode(
        VcpTextVertAlignModeEnum value     // [IN] Text vertical algin mode.
    );

    // <group DOM_TextView_VcpTextView_Method>
    // Set text wrap style.
    void setTextWrapStyle(
        VcpTextWrapStyleEnum wrap          // [IN] Text wrap style.
    );

    // <group DOM_TextView_VcpTextView_Method>
    // Set margin frame. The frame will be center aligned both in Vertical and horizontal
    // the margin frame will not scroll with text viewer
    void setMarginFrame(
        VcpTextMarginFrameEnum value,     // [IN] Text algin mode.
        VfxFrame *frame                   // [IN] image frame pointer
    );

    // <group DOM_TextView_VcpTextView_Method>
    // Remove margin image. Before delete frame, user must call this API to remove the frame from text view
    void removeMarginFrame(
        VcpTextMarginFrameEnum value,     // [IN] Text algin mode.
        VfxFrame *frame                   // [IN] image frame pointer
    );

    // <group DOM_TextView_VcpTextView_Method>
    // Returns the number of lines of text
    VfxS32 getLineCount() const;

    /* DOM-NOT_FOR_SDK-BEGIN */

    // <group DOM_TextView_VcpTextView_Method>
    // Returns the text layout assigned to current view
    VcpTextBasicLayout *getTextLayout() const {
        return m_layout;
    }

    // <group DOM_TextView_VcpTextView_Method>
    // Returns the text layout assigned to current view
    VcpTextStorage *getTextStorage() const {
        return m_storage;
    }

    /* DOM-NOT_FOR_SDK-END */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    // <group DOM_TextView_VcpTextView_Method>
    // Enable auto resizing when text is changed.
    void setAutoResized(
        VfxBool value,                  // [IN] enable or not
        VfxS32 minValue = -1,           // [IN] max resized value, for singleline, it means max resized width, for multiline, it means max resized height
        VfxS32 maxValue = -1            // [IN] max resized value, for singleline, it means max resized width, for multiline, it means max resized height
        );

    // <group DOM_TextView_VcpTextView_Method>
    // Disable background or not.
    void disableBackground(
        VfxBool value                   // [IN] disable background or not
        );
    
    // <group DOM_TextView_VcpTextView_Method>
    // Enable auto resizing when text is changed.
    void setAutoFontSize(
        VfxBool value                   // [IN] auto font size or not
        );

    // <group DOM_TextView_VcpTextView_Method>
    // force update all layout immediatelly, will re-layout
    // if isAsync is false, will update all content at once
    // otherwise, the content will update async part by part
    void forceUpdate(VfxBool isAsync = VFX_TRUE);

    // <group DOM_TextView_VcpTextView_Method>
    // update view content for custom frame.
    // Can be called when custo frame size or content changes and need to update the whole text view content
    // diff with forceUpdate, this function will not relayout. It will only update the bounds
    void UpdateViewForCustomFrame();

    // <group DOM_TextView_VcpTextView_Method>
    // set Id, used when there are a lot of instance in one screen, and App need to differentation from each other
    // then app can set id for each instance, and use getId in app's function
    void setId(
        VfxId id                        // [IN] id
    )
    {
        m_id = id;
    }

    // <group DOM_TextView_VcpTextView_Method>
    // get Id
    VfxId getId() const
    {
        return m_id;
    }

    /* DOM-NOT_FOR_SDK-BEGIN */

    // <group DOM_TextView_VcpTextView_Method>
    // add frame to scrollable view
    void addChildToScrollable(VfxObject *child);

    /* DOM-NOT_FOR_SDK-END */

    // <group DOM_TextView_VcpTextView_Method>
    // start vertical scroll
    void startScroll();

    // <group DOM_TextView_VcpTextView_Method>
    // stop scroll
    void stopScroll();

    // <group DOM_TextView_VcpTextView_Method>
    // previous line
    VfxBool previousLine();

    // <group DOM_TextView_VcpTextView_Method>
    // next linie
    VfxBool nextLine();

    // <group DOM_TextView_VcpTextView_Method>
    // previous page
    VfxBool previousPage();

    // <group DOM_TextView_VcpTextView_Method>
    // next Page
    VfxBool nextPage();

    // <group DOM_TextView_VcpTextView_Method>
    // scroll specific offset
    VfxBool scroll(
        VfxS32 offsetX,                // [IN] x offset
        VfxS32 offsetY,                // [IN] y offset
        VfxBool isAnimation = VFX_TRUE // [IN] need animation or not
        );

    // <group DOM_TextView_VcpTextView_Method>
    // scroll to the Start
    VfxBool scrollToStart();

    // <group DOM_TextView_VcpTextView_Method>
    // scroll to the end
    VfxBool scrollToEnd();

    // <group DOM_TextView_VcpTextView_Method>
    // set disable clipboard function
    void setDisableClipboard(
        VfxBool isDisable               // [IN] disable clipboard or not
        )
    {
        m_isDisableClipboard = isDisable;
    }

    // <group DOM_TextView_VcpTextView_Method>
    // set is disable magnifier function
    void setDisableMagnifier(
        VfxBool isDisable               // [IN] disable magnifier or not
        )
    {
        m_isDisableMagnifier = isDisable;
    }

    // <group DOM_TextView_VcpTextView_Method>
    // adjust index for language (cluster...)
    VfxS32 adjustIndexForLanguage(VfxS32 index, VfxBool isPrevious = VFX_FALSE);

    /* DOM-NOT_FOR_SDK-BEGIN */

    // <group DOM_TextView_VcpTextView_Method>
    // set max line number
    void setMaxLineNum(VfxS32 num) { m_layout->setMaxLineNum(num); } 

    // <group DOM_TextView_VcpTextView_Method>
    // set max layout memory overhead
    void setMaxLayoutMemory(VfxS32 bufSize);

    // <group DOM_TextView_VcpTextView_Method>
    // is reach max line number
    VfxBool isReachMaxLineNum();

    // <group DOM_TextView_VcpTextView_Method>
    // set is draw content or not
    void setIsDrawContent(VfxBool value)
    {
        m_layout->setIsDraw(value);
        checkUpdate();
    }

    // <group DOM_TextView_VcpTextView_Method>
    // set baseline pos
    void setBasePos(const VfxPoint pos);

    /* DOM-NOT_FOR_SDK-END */

// Override
public: 
    // <group DOM_TextView_VcpTextView_Override>
    // set bounds
    virtual void setBounds(
        const VfxRect &value            // [IN] bounds value
        );
    
    // <group DOM_TextView_VcpTextView_Override>
    // Indicate this textview editable or not
    virtual VfxBool editable() const { 
        return (m_editing != NULL);
    }
    
    // <group DOM_TextView_VcpTextView_Override>
    // Active this textview
    virtual void activate(
        VfxBool isSetFocus = VFX_TRUE   // [IN] unused
        )
    {
        m_activated = VFX_TRUE;
		if (isSetFocus)
        {
            setFocused(VFX_TRUE);
        }
    }

    // <group DOM_TextView_VcpTextView_Override>
    // Deactivate this textview
    virtual void deactivate(
        VfxBool isSetFocus = VFX_TRUE   // [IN] unused
        )
    {
    #if VCP_TEXT_CLIPBOARD_SUPPORT
        if (m_clipboard->hideMenu())
        {
            getTextLayout()->setSelection(VfxTextRange(0, 0));
        }
    #endif
        m_activated = VFX_FALSE;
		if (isSetFocus)
        {
            setFocused(VFX_FALSE);
	    }
    }

    // <group DOM_TextView_VcpTextView_Override>
    // query active or not
    virtual VfxBool isActive(){
        return m_activated;
    }

// Override
protected:
    // <group DOM_TextView_VcpTextView_Override>
    // on text view init
    virtual void onInit();

    // <group DOM_TextView_VcpTextView_Override>
    // on text view deinit
    virtual void onDeinit();

    // <group DOM_TextView_VcpTextView_Override>
    // on text view create view
    virtual VcpScrollableView *onCreateView();

    // <group DOM_TextView_VcpTextView_Override>
    // on text view update
    virtual void onUpdate();

    // <group DOM_TextView_VcpTextView_Override>
    // on text view draw
    virtual void onDraw(VfxDrawContext &dc);

    // <group DOM_TextView_VcpTextView_Override>
    // on text view key input
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event          // [IN] The key event to be handled
    );

    // <group DOM_TextView_VcpTextView_Override>
    // on object notify
    virtual void onObjectNotify(VfxId eventId, void *userData);
    
// implenmention
protected:
    // <group DOM_TextView_VcpTextView_Implementation>
    // on text view focus changed
    void onFocusChanged(VfxBool focused);

    // <group DOM_TextView_VcpTextView_Implementation>
    // on add child text view
    void onAddChild(VfxObject *child);

    // <group DOM_TextView_VcpTextView_Implementation>
    // play warning tone
    void playTone(VcpTextToneEnum type);

    // <group DOM_TextView_VcpTextView_Implementation>
    // on view bounds changed
    void onViewBoundsChanged(VfxFrame *view, const VfxRect &old);

    // <group DOM_TextView_VcpTextView_Implementation>
    // on content warning
    void onContentWarning(VcpScrollableView* sender);

    // <group DOM_TextView_VcpTextView_Implementation>
    // on content error
    void onContentError(VcpScrollableView* sender);

    // <group DOM_TextView_VcpTextView_Implementation>
    // notify scroll start
    void notifyScrollStart(VcpScrollable* sender);

    // <group DOM_TextView_VcpTextView_Implementation>
    // notify scroll end
    void notifyScrollEnd(VcpScrollable* sender);

    // <group DOM_TextView_VcpTextView_Implementation>
    // scroll cell view
    void scrollCellView();

    // <group DOM_TextView_VcpTextView_Implementation>
    // set valid content rect
    void setValidContent(
        VfxRect rect    // [IN] valid content rect
    );

    // <group DOM_TextView_VcpTextView_Implementation>
    // get valid view bounds
    // if in intersect mode, return intersect rect, else return bounds rect
    VfxRect getValidViewBounds();

    
// Implementation
private:
    // <group DOM_TextView_VcpTextView_Implementation>
    // on layout changed
    void onLayoutChanged(VfxRect rect);

    // <group DOM_TextView_VcpTextView_Implementation>
    // on selection changed
    void onSelectionChanged(VfxRect rect);

    // <group DOM_TextView_VcpTextView_Implementation>
    // on hyperlink clicked
    void onHyperLinkClicked(VcpTextView *view, VcpTextTapAreaEnum type, VcpRichTextFormat *obj);

    // <group DOM_TextView_VcpTextView_Implementation>
    // refresh all cell view
    void refreshAllCell();

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    // <group DOM_TextView_VcpTextView_Implementation>
    // get the needed multi view count 
    VfxS32 getNeedMultiViewCount();

    // <group DOM_TextView_VcpTextView_Implementation>
    // release all cell view
    void releaseCellView();

    // <group DOM_TextView_VcpTextView_Implementation>
    // sort cell view
    void sortCellView();

    // <group DOM_TextView_VcpTextView_Implementation>
    // build cell view
    void buildCellView();

#if VCP_TEXT_CLIPBOARD_SUPPORT
    // <group DOM_TextView_VcpTextView_Implementation>
    // on clipboard event
    void onClipboardEvent(VfxCcpEventType type, VfxWChar** string, VfxS32 len, VfxS32 *ret_len);
#endif
    // <group DOM_TextView_VcpTextView_Implementation>
    // on clipboard timer
    void onClipboardTimer(VfxTimer *timer);

    // <group DOM_TextView_VcpTextView_Implementation>
    // get cell view width
    VfxS32 cellViewWidth() const{
        return VFX_MIN(m_view->getSize().width, VCP_TEXT_FRAME_MAX_WIDTH);
    }

    // <group DOM_TextView_VcpTextView_Implementation>
    // get cell view height
    VfxS32 cellViewHeight() const{
        return VFX_MIN(m_view->getSize().height, VCP_TEXT_FRAME_MAX_HEIGHT);
    }

    // <group DOM_TextView_VcpTextView_Implementation>
    // scroll warning area
    void scrollWarningArea();

    // <group DOM_TextView_VcpTextView_Implementation>
    // limit text view to valid rect
    void limitTextViewToValidRect();

    // <group DOM_TextView_VcpTextView_Implementation>
    // update layout information
    void updateLayoutInfo();

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    // <group DOM_TextView_VcpTextView_Implementation>
    // check force update
    void checkForceUpdate();

    // <group DOM_TextView_VcpTextView_Implementation>
    // force update internal
    void forceUpdateInternal(VfxBool isAsync = VFX_TRUE);

    // <group DOM_TextView_VcpTextView_Implementation>
    // auto scroll
    void onAutoScroll(VfxTimer *timer);

#if VCP_TEXT_MAGNIFIER_SUPPORT
    // <group DOM_TextView_VcpTextView_Implementation>
    // on magnifier timer
    void onMagnifierTimer(VfxTimer *timer);
#endif

    // <group DOM_TextView_VcpTextView_Implementation>
    // set bounds internal
    void setBoundsInternal(const VfxRect &value, VfxBool isForce);

    // <group DOM_TextView_VcpTextView_Implementation>
    void setValidRectTimerHandler(VfxTimer *source);

    // <group DOM_TextView_VcpTextView_Implementation>
    void scrollVisibleTimerHandler(VfxTimer *source);

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // on rotated
    void onRotated(VfxScreenRotateParam rotateParam);

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // on before rotate
    void onBeforeRotate(VfxScreenRotateParam rotateParam);

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // on max layout line number reached
    void onMaxLayoutLineNumReached(VcpTextBasicLayout *layout);

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // scroll rect to visible start saved before rotate
    void scrollToVisibleStart();

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // set layout
    void setLayout();
    
    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // set view and layout rect
    void setLayoutRect();

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // get layout rect
    VfxRect getLayoutRect();

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    void setBasePosInternal(const VfxPoint pos);

// Implementation
protected:
    // <group DOM_TextView_VcpTextView_Implementation>
    VcpTextStorage *m_storage;

    // <group DOM_TextView_VcpTextView_Implementation>
    VcpTextBasicLayout *m_layout;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxS32 m_minHeight, m_maxHeight;

    // <group DOM_TextView_VcpTextView_Implementation>
    VcpTextCellView* m_cellView[VCP_TEXTVIEW_CELLVIEW_MAX];

    // <group DOM_TextView_VcpTextView_Implementation>
    VcpTextLineModeEnum m_lineMode;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxU8 m_countOfCellView;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxU8 m_scrollDir, m_scrollWarning;

#if VCP_TEXT_CLIPBOARD_SUPPORT
    // <group DOM_TextView_VcpTextView_Implementation>
    VsrvClipboard *m_clipboard;
#endif
    // <group DOM_TextView_VcpTextView_Implementation>
    VfxTimer *m_clipboardTimer;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxPoint m_penDownPos;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxPoint m_penMovePos;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxS32 m_selStart;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxS32 m_leftMargin, m_rightMargin, m_topMargin, m_bottomMargin;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxBool m_activated;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxBool m_autoResized;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxBool m_autoFontSize;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxBool m_isDisableBg;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxBool m_checkForceUpdate;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxBool m_isDisableClipboard;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxBool m_isDisableMagnifier;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxS32 m_autoResizedMinValue;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxS32 m_autoResizedMaxValue;

#if 0
/* under construction !*/
/* under construction !*/
#endif

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxFloat m_progressValue;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxFrame *m_progressFrame;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxFrame **m_marginFrame;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxId m_id;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxResId m_normalBgImageId;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxResId m_hiliteBgImageId;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxS32 m_orgFontSize;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxBool m_isUpdating;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxTimer *m_scrollTimer;

    // <group DOM_TextView_VcpTextView_Implementation>
    // indicate whether is selecting text
    VfxBool m_isSelectingText;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxBool m_isMagnifierState;

#if VCP_TEXT_MAGNIFIER_SUPPORT
    // <group DOM_TextView_VcpTextView_Implementation>
    VcpTextMagnifier *m_magnifier;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxTimer *m_magnifierTimer;
#endif

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxFrame *m_bgImageFrame;

#if defined(__COSMOS_MMI_PACKAGE__)
    // <group DOM_TextView_VcpTextView_Implementation>
    VcpActivityIndicator *m_waitingInd;
#endif

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxTimer *m_setValidRectTimer;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxS32 m_visibleStartIndex;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxTimer *m_scrollVisibleTimer;

    // <group DOM_TextView_VcpTextView_Implementation>
    VfxPoint m_basePos;

    friend class VcpEditing;
    friend class VcpTextCursor;
    friend class VcpTextScrollView;
};


/* DOM-NOT_FOR_SDK-BEGIN */

/***************************************************************************** 
 * Class VcpTextScrollView
 *****************************************************************************/

// VcpTextScrollView is used to hook pen state from Scrollable.
// It will pass pen input to menu class.
class VcpTextScrollView : public VcpScrollableView
{
// Constructor / Destructor
public:
    // <group DOM_TextView_VcpTextScrollView_Constructor/Destructor>
    VcpTextScrollView();

// Method
public:
    // <group DOM_TextView_VcpTextScrollView_Method>
    // get the parent textview
    VcpTextView* getTextView();

    // <group DOM_TextView_VcpTextScrollView_Method>
    // Limit pos within rect
    void limitPosWithinRect(VfxPoint &pos, VfxRect rect);

// Override
protected:
    // <group DOM_TextView_VcpTextScrollView_Override>
    virtual VfxBool onPenInput(VfxPenEvent &event);

    // <group DOM_TextView_VcpTextScrollView_Override>
    virtual VfxBool onPenAbortAccepted(
        VfxControl *aborter, 
        VfxPenAbortReasonEnum reason
    );

// Variable
protected:
    // <group DOM_TextView_VcpTextScrollView_Implementation>
    // Is current in drag state?
    VfxBool m_isDraged;

    // <group DOM_TextView_VcpTextScrollView_Implementation>
    VfxBool m_selectingText;
    
// Implement
protected:
    friend class VcpTextView;
};


/***************************************************************************** 
 * Class VcpTextCellView
 *****************************************************************************/

// VcpTextCellView is a displayed region unit of the whole view.
// It will pass pen input to menu class.
class VcpTextCellView : public VfxControl
{
    VFX_DECLARE_CLASS(VcpTextCellView);

// Constructor / Destructor
public:
    // <group DOM_TextView_VcpTextCellView_Constructor/Destructor>
    VcpTextCellView(){}

// Override   
public:
    virtual void setBounds(const VfxRect &value);
    
// Override
protected:
    // <group DOM_TextView_VcpTextCellView_Override>
    virtual void onDraw(VfxDrawContext &dc);

    // <group DOM_TextView_VcpTextCellView_Override>
    virtual void onInit();

// Method
public:
    // <group DOM_TextView_VcpTextCellView_Method>
    // set layout
    void setLayout(VcpTextBasicLayout* layout);

    // <group DOM_TextView_VcpTextCellView_Method>
    // refresh cell view
    void refresh(VfxBool isNeedRedrawText = VFX_TRUE);

// Implement
private:
    // <group DOM_TextView_VcpTextCellView_Implementation>
    VcpTextBasicLayout *m_layout;

    VcpTextCellContentView *m_contentText;

    VcpTextCellContentView *m_contentHilite;    
};


/***************************************************************************** 
 * Class VcpTextCellContentView
 *****************************************************************************/

// VcpTextCellContentView is a displayed region content unit of the whole view.
class VcpTextCellContentView : public VfxControl
{

public:
// Enum
    enum VcpTextCellContentEnum
    {
        VCP_TEXT_CELL_CONTENT_TEXT,
        VCP_TEXT_CELL_CONTENT_HILITE,
        VCP_TEXT_CELL_CONTENT_END_OF_ENUM
    };
// Constructor / Destructor
public:
    // <group DOM_TextView_VcpTextCellContentView_Constructor/Destructor>
    VcpTextCellContentView(VcpTextCellContentEnum type)
    {
        m_type = type;
    }
    
// Override
protected:
    // <group DOM_TextView_VcpTextCellContentView_Override>
    virtual void onDraw(VfxDrawContext &dc);

    // <group DOM_TextView_VcpTextCellContentView_Override>
    virtual void onInit();

// Method
public:
    // <group DOM_TextView_VcpTextCellContentView_Method>
    // set layout
    void setLayout(VcpTextBasicLayout* layout){
        m_layout = layout;
    }

    // <group DOM_TextView_VcpTextCellContentView_Method>
    // refresh cell view
    void refresh();

// Implement
private:
    // <group DOM_TextView_VcpTextCellContentView_Implementation>
    VcpTextBasicLayout *m_layout;

    VcpTextCellContentEnum m_type;
};



#if VCP_TEXT_MAGNIFIER_SUPPORT

/***************************************************************************** 
 * Class VcpTextMagnifier
 *****************************************************************************/

// VcpTextMagnifier is a displayed region unit of specific area for magnifier
class VcpTextMagnifier : public VfxControl
{
// Constructor / Destructor
public:
    // <group DOM_TextView_VcpTextMagnifier_Constructor/Destructor>
    VcpTextMagnifier();
    
// Override
protected:
    // <group DOM_TextView_VcpTextMagnifier_Override>
    virtual void onInit();

    // <group DOM_TextView_VcpTextMagnifier_Override>
    virtual void onDeinit();

// Method
public:
    // Set frame position.
    virtual void setPos(const VfxPoint &value);

    // <group DOM_TextView_VcpTextMagnifier_Method>
    VcpTextView *getContentView()
    {
        return m_contentView;
    }

    // <group DOM_TextView_VcpTextMagnifier_Method>
    void setSelectTextMode(VfxBool value);

    // <group DOM_TextView_VcpTextMagnifier_Method>
    // set text to magnifier
    void setText(VfxWChar *text, VcpRichTextFormat *format);

public:
    // <group DOM_TextView_VcpTextMagnifier_Implementation>
    VfxS32 m_lineIndex;

// Implement
private:
    // <group DOM_TextView_VcpTextMagnifier_Implementation>
    VcpTextView *m_contentView;

    // <group DOM_TextView_VcpTextMagnifier_Implementation>
    VfxFrame *m_textFrame;

    // <group DOM_TextView_VcpTextMagnifier_Implementation>
    VfxFrame *m_magnifierBackground;
    
    // <group DOM_TextView_VcpTextMagnifier_Implementation>
    VfxFrame *m_magnifierMask;

    // <group DOM_TextView_VcpTextMagnifier_Implementation>
    VfxFrame *m_magnifierCursorFrame;

    // <group DOM_TextView_VcpTextMagnifier_Implementation>
    VfxFontEffect *m_effect;
};
#endif

/* DOM-NOT_FOR_SDK-END */

#endif /* __VCP_TEXT_VIEW_H__ */
