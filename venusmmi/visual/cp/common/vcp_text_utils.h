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
 *  vcp_text_utils.h
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  text utils class header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_TEXT_UTILS_H__
#define __VCP_TEXT_UTILS_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"

#ifdef __cplusplus
extern "C"
{
#include "PixcomFontEngine.h"
#include "BIDIDEF.h"
#include "gui.h"
#include "Gsm7BitNationalLang.h"
#include "Conversions.h"
}
#endif

#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_string.h"
#include "vfx_basic_type.h"
#include "vfx_font_desc.h"
#include "vrt_datatype.h"
#include "vfx_image_src.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
// <group DOM_TextView_Macro&Enum_Macro>

// min char width, for some complex languages, the character width may very small
// the macro will decide the character number per line (charPerLine)
// which in turn will affect the following performance
// 1. layout (decide each layout characters = (charPerLine * line))
// 2. find the affect area when insert/delete happens (backward)
#define VCP_TEXT_MIN_CHAR_WIDTH             3

#define TEXT_FORMAT_ATTR_TEXT_COLOR        0x00000001
#define TEXT_FORMAT_ATTR_BG_COLOR          0x00000002
#define TEXT_FORMAT_ATTR_FONT              0x00000004
#define TEXT_FORMAT_ATTR_IMAGE             0x00000008

#define VCP_TEXT_IS_PLUS_CHAR(c)          ((c) == 0x2B)
#define VCP_TEXT_IS_UCS2_CHAR(c)          UI_TEST_UCS2_CHARACTER(c)
#define VCP_TEXT_IS_GSM_EXT_CHAR(c)       UI_TEST_GSM_EXTENDED(c)
#define VCP_TEXT_IS_ASCII_CHAR(c)         UI_TEST_ASCII_CHARACTER(c)
#define VCP_TEXT_GET_GB_LEN(c)            (((c) > 255) ? 2 : 1)
#define VCP_TEXT_GET_UTF8_LEN(s)          (mmi_charset_ucs2_to_utf8_length_in_bytes((const VfxU8 *)s))
#define VCP_TEXT_IS_BIDI_CHAR(c)          ((c) == BIDI_R || (c) == AL) ? 1 : 0

/* DOM-NOT_FOR_SDK-BEGIN */
#define VCP_TEXT_FORMAT_ALLOC_NEW(_ptr, _type, _alloc) \
    do \
    { \
        switch (_type) \
        { \
        case VCP_RICH_TEXT_TYPE_TEXT: \
            VFX_ALLOC_NEW(_ptr, VcpRichText, _alloc); \
            break; \
        case VCP_RICH_TEXT_TYPE_HYPERLINK: \
            VFX_ALLOC_NEW(_ptr, VcpRichTextHyperLink, _alloc); \
            break; \
        case VCP_RICH_TEXT_TYPE_IMAGE: \
            VFX_ALLOC_NEW_EX(_ptr, VcpRichTextImage, _alloc, (_alloc)); \
            break; \
        case VCP_RICH_TEXT_TYPE_CUSTOM_FRAME: \
            VFX_ALLOC_NEW(_ptr, VcpRichTextCustomFrame, _alloc); \
            break; \
        default: \
            break; \
        } \
    } while(0)

#define VCP_TEXT_FORMAT_OBJ_COPY(_dest, _src) \
    do \
    { \
        switch (_src->getType()) \
        { \
        case VCP_RICH_TEXT_TYPE_TEXT: \
            *((VcpRichText*)_dest) = *((VcpRichText*)_src); \
            break; \
        case VCP_RICH_TEXT_TYPE_HYPERLINK: \
            *((VcpRichTextHyperLink*)_dest) = *((VcpRichTextHyperLink*)_src); \
            break; \
        case VCP_RICH_TEXT_TYPE_IMAGE: \
            *((VcpRichTextImage*)_dest) = *((VcpRichTextImage*)_src); \
            break; \
        case VCP_RICH_TEXT_TYPE_CUSTOM_FRAME: \
            *((VcpRichTextCustomFrame*)_dest) = *((VcpRichTextCustomFrame*)_src); \
            break; \
        default: \
            break; \
        } \
    } while(0)

class VcpTextUtils;
class VcpTextMetrics;
class VfxTextRange;
class VcpRichTextFormat;
class VcpRichText;
class VcpRichTextImage;
class VcpRichTextCustomFrame;

// <group DOM_TextUtils_VcpTextUtils_Enum>
// Enum for TextUtils ellipsis mode
enum VcpTextEllipsisModeEnum
{
    VCP_TEXT_ELLIPISIS_MODE_START,
    VCP_TEXT_ELLIPISIS_MODE_MID,
    VCP_TEXT_ELLIPISIS_MODE_END,
    VCP_TEXT_ELLIPISIS_MODE_END_OF_ENUM
};

// <group DOM_TextUtils_VcpTextUtils_Enum>
// Keyword type
enum VcpTextKeyWordEnum 
{
    VCP_TEXT_KEYWORD_NONE        = 0x0,
    VCP_TEXT_KEYWORD_EMAIL       = 0x1,
    VCP_TEXT_KEYWORD_URL         = 0x2,
    VCP_TEXT_KEYWORD_PHONENUMBER = 0x4,
    VCP_TEXT_KEYWORD_USSD        = 0x8,
    VCP_TEXT_KEYWORD_END_OF_ENUM
};

/* DOM-NOT_FOR_SDK-END */

// <group DOM_TextUtils_VcpTextUtils_Enum>
// rich text type enum
enum VcpRichTextTypeEnum
{
    VCP_RICH_TEXT_TYPE_NONE,
    // formatted text
    VCP_RICH_TEXT_TYPE_TEXT,
    // hyper link text
    VCP_RICH_TEXT_TYPE_HYPERLINK,
    // image
    VCP_RICH_TEXT_TYPE_IMAGE,
    /* DOM-NOT_FOR_SDK-BEGIN */
    VCP_RICH_TEXT_TYPE_AUDIO,
    VCP_RICH_TEXT_TYPE_VIDEO,
    /* DOM-NOT_FOR_SDK-END */
    // custom frame
    VCP_RICH_TEXT_TYPE_CUSTOM_FRAME,
    VCP_RICH_TEXT_TYPE_TOTAL
};

// <group DOM_TextUtils_VcpTextUtils_Enum>
// rich text object attribute enum
enum VcpRichTextObjectAttrEnum
{
    VCP_RICH_TEXT_OBJ_ARRT_NONE         = 0x0,
    // the object embedded in text
    VCP_RICH_TEXT_OBJ_ARRT_EMBED        = 0x1,
    // the object is left align to a line
    VCP_RICH_TEXT_OBJ_ARRT_LEFT_ALIGN   = 0x2,
    // the object is middle align to a line
    VCP_RICH_TEXT_OBJ_ARRT_MID_ALIGN    = 0x4,
    // the object is right align to a line
    VCP_RICH_TEXT_OBJ_ARRT_RIGHT_ALIGN  = 0x8,
    /* DOM-NOT_FOR_SDK-BEGIN */
    VCP_RICH_TEXT_OBJ_ARRT_WRAPPING     = 0x10,  // not support currently
    // emotion icon add from icon table
    VCP_RICH_TEXT_OBJ_EMOTION_ICON      = 0x20,
    /* DOM-NOT_FOR_SDK-END */
    VCP_RICH_TEXT_OBJ_ARRT_END_OF_ENUM
};


/* DOM-NOT_FOR_SDK-BEGIN */

/***************************************************************************** 
 * Class VfxTextRange
 *****************************************************************************/

/*
 * DESCRIPTION
 *  A range of text 
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VfxTextRange
{

// Constructor / Destructor    
public:
    // <group DOM_TextUtils_VfxTextRange_Constructor/Destructor>
    VfxTextRange() { m_start = 0; m_end = 0; }

    // <group DOM_TextUtils_VfxTextRange_Constructor/Destructor>
    VfxTextRange(VfxS32 start, VfxS32 end) { m_start = start; m_end = end; }

    // <group DOM_TextUtils_VfxTextRange_Constructor/Destructor>
    VfxTextRange(const VfxTextRange& range) { 
        m_start = range.m_start; 
        m_end = range.m_end; 
    }

// Method
public:
    // <group DOM_TextUtils_VfxTextRange_Method>
    // set the range
    void setRange(VfxS32 start, VfxS32 end) { m_start = start; m_end = end; }
    void setRange(VfxTextRange& range) { 
        m_start = range.getStart(); 
        m_end = range.getEnd(); 
    }

    // <group DOM_TextUtils_VfxTextRange_Method>
    // get the start pos
    void setStart(VfxS32 start) { m_start = start; }
    VfxS32 getStart() const { return m_start; }

    // <group DOM_TextUtils_VfxTextRange_Method>
    //get the end pos
    void setEnd(long end) { m_end = end; }
    VfxS32 getEnd() const { return m_end; }

    // <group DOM_TextUtils_VfxTextRange_Method>
    // return the range length
    VfxS32 getLength() const { return m_end - m_start; }

    // <group DOM_TextUtils_VfxTextRange_Method>
    // Returns true if this range is completely outside 'range'
    VfxBool isOutside(const VfxTextRange& range) const { 
        return range.m_start >= m_end || range.m_end <= m_start; 
    }

    // <group DOM_TextUtils_VfxTextRange_Method>
    // Returns true if this range is completely within 'range'
    VfxBool isWithin(const VfxTextRange& range) const { 
        return m_start >= range.m_start && m_end <= range.m_end; 
    }

    // <group DOM_TextUtils_VfxTextRange_Method>
    // Limit this range to be within 'range'
    VfxBool limitTo(const VfxTextRange& range) ;

    // <group DOM_TextUtils_VfxTextRange_Method>
    // Shift this range by 'offset'
    void shift(VfxS32 offset) {
        m_start += offset;
        m_end += offset;
    }

    // <group DOM_TextUtils_VfxTextRange_Method>
    // RETURNS: Return VFX_TRUE the range is equal to the other.    
    VfxBool operator ==(const VfxTextRange &other) const
    {
        return ((m_start == other.m_start) && (m_end == other.m_end)) ? VFX_TRUE : VFX_FALSE;
    }

// Variable  
protected:
    // <group DOM_TextUtils_VfxTextRange_Implementation>
    VfxS32 m_start;

    // <group DOM_TextUtils_VfxTextRange_Implementation>
    VfxS32 m_end;
};

/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
 * Class VcpTextUtils
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VcpTextUtils is a class provide text utils function.
 *    1. It provide more information about text metrics.
 *    2. It's a Wrapper of pluto font engine APIs.
 *    3. Support rich text (Text format)
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VcpTextUtils : public VfxBase
{

// Constructor / Destructor
public:
    // <group DOM_TextView_VcpTextUtils_Constructor/Destructor>
    VcpTextUtils(IVfxAllocatable *owner);

    // <group DOM_TextView_VcpTextUtils_Constructor/Destructor>
    virtual ~VcpTextUtils();

// Method
public:
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
#endif

    // <group DOM_TextView_VcpTextUtils_Method>
    // Set text with a const string
    void setText(
        const VfxWChar *text,              // [IN] text content
        VcpRichTextFormat *format = NULL   // [IN] text format appended to the string
        );

    // <group DOM_TextView_VcpTextUtils_Method>
    // Set text with a const string with specific text length, len = -1 means set whole text
    void setText(
        const VfxWChar *text,                    // [IN] text content
        VfxS32 len,                        // [IN] text length
        VcpRichTextFormat *format = NULL   // [IN] text format appended to the string
        );

    // <group DOM_TextView_VfxTextUtils_Method>
    // Return the plain text of TextUtils
    const VfxWChar *getText();

    // <group DOM_TextView_VfxTextUtils_Method>
    // Return the plain text of TextUtils
    VfxS32 getTextLength(void) const;

    // <group DOM_TextView_VcpTextUtils_Method>
    // Return text width/height of specific text length, len = -1 means set whole text
    VfxSize getTextMetrics(
        VfxS32 n,                          // [IN] text length to measure
        VcpRichTextFormat *format = NULL   // [IN] text format if any
        );

    /* DOM-NOT_FOR_SDK-BEGIN */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    // <group DOM_TextView_VcpTextUtils_Method>
    // Return text width/height of specific text length, len = -1 means set whole text
    VfxSize getTextMetrics(
        VfxS32 start,                      // [IN] text position start to measure
        VfxS32 n,                          // [IN] text length to measure
        VfxFontDesc *font,                 // [IN] text font
        VfxS32 max_width,                  // [IN] max width to measure
        VfxS32 *len,                       // [OUT] txt length in max_width
        VfxS32 *baseline,                  // [OUT] text baseline
        VcpRichTextFormat *format = NULL,  // [IN] text format if any
        VfxU8 isWordWrap = 1,              // [IN] word wrap or not
        VfxBool isNeedClusterMetric = VFX_TRUE, // [IN] need save cluster information or not
        VfxS32 *adv_w = NULL               // [OUT] advance width
        );

    // <group DOM_TextView_VcpTextUtils_Method>
    // get metric with specific index (in memroy)
    VcpTextMetrics *getMetric(
        VfxS32 index                        // [IN] index in memory
        );

    // <group DOM_TextView_VcpTextUtils_Method>
    // get metric with specific index (in visual)
    VcpTextMetrics *getMetricByVisual(
        VfxS32 index                        // [IN] index in visual
        );

    // <group DOM_TextView_VcpTextUtils_Method>
    // Get char index of specify offset
    void getIndex(
        VfxS32 x_offset,                    // [IN] text offset.
        VfxS32 *index1,                     // [IN] index1
        VfxS32 *index2,                     // [IN] index2
        VfxS32 *newX = NULL                 // [OUT] position aligned to choosed character
        );

    // <group DOM_TextView_VcpTextUtils_Method>
    // Get Char offset
    void getOffset(
        VfxS32 index_before,               // [IN] index before
        VfxS32 index_after,                // [IN] index after
        VfxS32 *offset1,                   // [IN] offset of first index
        VfxS32 *offset2                    // [IN] offset of second index
        );

#if __FOR_TODO__
    // <group DOM_TextView_VcpTextUtils_Method>
    // Get pre char index (Move cursor in logic)
    VfxS32 getPreIndex(
        VfxS32 index,                       // [IN] index
        VfxS32 *newX                        // [OUT] new position
        );

    // <group DOM_TextView_VcpTextUtils_Method>
    // Get next char index (Move cursor in logic)
    VfxS32 getNextIndex(
        VfxS32 index,                       // [IN] index
        VfxS32 *newX                        // [OUT] new position
        );

    // <group DOM_TextView_VcpTextUtils_Method>
    // Get Left char index (Move cursor in visiual)
    VfxS32 getLeftIndex(
        VfxS32 index,                      // [IN] index
        VfxS32 x_offset,                   // [IN] offset
        VfxS32 *newX                       // [OUT] new position
        );

    // <group DOM_TextView_VcpTextUtils_Method>
    // Get right char index (Move cursor in visiual)
    VfxS32 getRightIndex(
        VfxS32 index,                     // [IN] index
        VfxS32 x_offset,                  // [IN] offset
        VfxS32 *newX                      // [OUT] new position
        );
#endif

    // <group DOM_TextView_VcpTextUtils_Method>
    // Get char index of next text, return -1 if not found
    VfxS32 indexOf(
        VfxWChar ch,                    // [IN] ch
        VfxS32 start,                   // [IN] start pos
        VfxS32 end                      // [IN] end pos
        );

    // <group DOM_TextView_VcpTextUtils_Method>
    // Get char index of previous, return -1 if not found
    VfxS32 lastIndexOf(
        VfxWChar ch,                    // [IN] ch
        VfxS32 start,                   // [IN] start pos
        VfxS32 end                      // [IN] end pos
        );

    // <group DOM_TextView_VcpTextUtils_Method>
    // Common utils function, get text height of common language
    VfxS32 getTextHeightOfCommonLang(
        VfxFontDesc *font,              // [IN]  font
        VfxS32 *pAscent,                // [OUT] ascent
        VfxS32 *pDescent                // [OUT] descent
        );

    // <group DOM_TextView_VcpTextUtils_Method>
    // Common utils function, get text height of simple language including Chinese, English, Number
    void getTextInfoOfSimpleLang(
        VfxU8 size,                  // [IN]  font size
        VfxS32 *pHeight,             // [IN]  height
        VfxS32 *pAscent,             // [IN]  ascent
        VfxS32 *pDescent             // [IN]  descent
        );

    // <group DOM_TextView_VcpTextUtils_Method>
    // set font
    void setFont(
        const VfxFontDesc &fontDesc  // [IN] font desc
        );

    // <group DOM_TextView_VcpTextUtils_Method>
    // Common utils function, get text direction
    vrt_text_dir_type_enum getTextDirection();

    // <group DOM_TextView_VcpTextUtils_Method>
    // check if first char is BIDI char or not
    VfxBool isFirstBidiChar();

// Override
public:

// Implementation
protected:
    // <group DOM_TextView_VcpTextUtils_Implementation>
    // get text infor
    static void getTextInfo(mmi_fe_cluster_metrics_struct metrics, void *user_data);

    // <group DOM_TextView_VcpTextUtils_Implementation>
    // reset text info
    void resetTextInfo(void);

// Implementation
private:
    // <group DOM_TextView_VcpTextUtils_Implementation>
    VfxWString m_text;

    // <group DOM_TextView_VcpTextUtils_Implementation>
    VcpTextMetrics* m_metrics;

    // <group DOM_TextView_VcpTextUtils_Implementation>
    VfxU8 m_direction;

    // <group DOM_TextView_VcpTextUtils_Implementation>
    VfxFontDesc m_font;

    // <group DOM_TextView_VcpTextUtils_Implementation>
    VcpRichTextFormat *m_format;

    // <group DOM_TextView_VcpTextUtils_Implementation>
    IVfxAllocatable *m_client;
};


/* DOM-NOT_FOR_SDK-BEGIN */

/***************************************************************************** 
 * Class VcpTextMetrics
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VcpTextMetrics is a class to get and save cluster information of a string.
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VcpTextMetrics : public VfxBase
{

// Constructor / Destructor
public:
    // <group DOM_TextUtils_VcpTextMetrics_Constructor/Destructor>
    VcpTextMetrics();

    // <group DOM_TextUtils_VcpTextMetrics_Constructor/Destructor>
    VcpTextMetrics(const VcpTextMetrics &other);

// Operator
public:
    // <group DOM_TextUtils_VcpTextMetrics_Constructor/Destructor>
    VcpTextMetrics &operator =(const VcpTextMetrics &other);

// Implementation
public:
    // <group DOM_TextUtils_VcpTextMetrics_Implementation>
    // Text metrics
    mmi_fe_cluster_metrics_struct metrics;
    
// Method
public:
    // <group DOM_TextUtils_VcpTextMetrics_Method>
    // Get next text metrics
    VcpTextMetrics* getNext()
    {
        return m_next;
    }

    // <group DOM_TextUtils_VcpTextMetrics_Method>
    //get the metrics after the index of cluster
    VcpTextMetrics* getAfter(
        VfxS32 index                 // [IN] index
        );

    // <group DOM_TextUtils_VcpTextMetrics_Method>
    //get the metrics before athe index of cluster
    VcpTextMetrics* getBefore(
        VfxS32 index                 // [IN]     index
        );

    // <group DOM_TextUtils_VcpTextMetrics_Method>
    // append the next metrics
    VcpTextMetrics* appendNext(
        VcpTextMetrics* newMetrics   // [IN]     new Metrics
        );

// Implementation
public:
    // <group DOM_TextUtils_VcpTextMetrics_Implementation>
    VcpTextMetrics *m_next;
};


/* DOM-NOT_FOR_SDK-END */


/***************************************************************************** 
 * Class VcpRichTextFormat
 *****************************************************************************/

/*
 * DESCRIPTION
 *  Rich text format base class
 *  All other rich text format is inherit from this class
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VcpRichTextFormat : public VfxBase
{

// Constructor / Destructor
public:
    // <group DOM_TextView_VcpRichTextFormat_Constructor/Destructor>
    VcpRichTextFormat();

    // <group DOM_TextView_VcpRichTextFormat_Constructor/Destructor>
    VcpRichTextFormat(const VcpRichTextFormat &other);

    // <group DOM_TextView_VcpRichTextFormat_Constructor/Destructor>
    virtual ~VcpRichTextFormat();

// Operator
public:
    // <group DOM_TextView_VcpRichTextImage_Method>
    VcpRichTextFormat &operator =(const VcpRichTextFormat &other);

// Method
public:
    // <group DOM_TextView_VcpRichTextImage_Method>
    // set format range
    // if start = end mean the object is embeded in start position
    void setRange(
        VfxS32 start,       // [IN] start
        VfxS32 end          // [IN] end
        )
    {
        m_range.setRange(start, end);
    }

    // <group DOM_TextView_VcpRichTextFormat_Method>
    // Get next format object
    VcpRichTextFormat* getNext()
    {
        return m_next;
    }

    // <group DOM_TextView_VcpRichTextFormat_Method>
    // get Last format object
    VcpRichTextFormat *getLast();

    // <group DOM_TextView_VcpRichTextFormat_Method>
    // append the text format to the end
    VcpRichTextFormat* append(
        VcpRichTextFormat* format       // [IN] format object need to append
    );

    /* DOM-NOT_FOR_SDK-BEGIN */

    // <group DOM_TextView_VcpRichTextFormat_Method>
    // add the text format to the end, temp solution for add format in list menu
    // WARNING: plese do not use it except for set more than one format to list menu (getItemTextFormat)
    VcpRichTextFormat& add(
        VcpRichTextFormat &format,       // [IN] format object need to append
        IVfxAllocatable *owner                  // [IN] onwer of format
    );

    /* DOM-NOT_FOR_SDK-END */

    // <group DOM_TextView_VcpRichTextFormat_Method>
    // get rich text format type
    VcpRichTextTypeEnum getType() { return m_type; }

    /* DOM-NOT_FOR_SDK-BEGIN */

    // <group DOM_TextView_VcpRichTextFormat_Method>
    // check if the format object list will affect the layout or not
    VfxBool testAffectLayout(
        VfxFontDesc *font,       // [IN] default font
        VfxS32 start,            // [IN] layout start position
        VfxS32 end               // [IN] layout end position
    );

    /* DOM-NOT_FOR_SDK-END */

    // <group DOM_TextView_VcpRichTextFormat_Method>
    // set object attribute, use VcpRichTextObjectAttrEnum
    void setObjectAttribute(
        VfxS32 attr             // [IN] attribute
        )
     {
        m_objAttribute = attr;
     }

    // <group DOM_TextView_VcpRichTextFormat_Method>
    // get object attribute, use VcpRichTextObjectAttrEnum
    VfxS32 getObjectAttribute(void) const { return m_objAttribute; }

    // <group DOM_TextView_VcpRichTextFormat_Method>
    // check if the object occupy one line
    VfxBool isOccopyOneLine(void);

// Override
public:

    /* DOM-NOT_FOR_SDK-BEGIN */

    // <group DOM_TextView_VcpRichTextFormat_Method>
    // Is the text format will affect the layout
    // For example, font size, font attribute will affect while text corlor not
    virtual VfxBool isAffectLayout(
        VfxS32 start,            // [IN] layout start position
        VfxS32 end               // [IN] layout end position
    ) = 0;

    // <group DOM_TextView_VcpRichTextFormat_Method>
    // rich text draw function
    virtual void draw(
        VfxDrawContext &dc,      // [IN]   device context
        const VfxPoint &point    // [IN]   draw position
    ) = 0;

    /* DOM-NOT_FOR_SDK-END */

    // <group DOM_TextView_VcpRichTextFormat_Method>
    // RETURNS: The size of the format
    virtual VfxSize getSize() const = 0;
    

// Implementation
public:
    // <group DOM_TextView_VcpRichTextFormat_Implementation>
    // next text format object pointer
    VcpRichTextFormat* m_next;

    // <group DOM_TextView_VcpRichTextFormat_Implementation>
    // text format type
    VcpRichTextTypeEnum m_type;

    // <group DOM_TextView_VcpRichTextFormat_Implementation>
    // format applied text range
    // for normal image, the range indicate the image position of text
    // for icon image, the range indicate the range it covers
    VfxTextRange m_range;

    // <group DOM_TextView_VcpRichTextFormat_Implementation>
    // object attribute flag
    VfxS32 m_objAttribute;

    // <group DOM_TextView_VcpRichTextFormat_Implementation>
    VfxBool m_bAdd;
};


/***************************************************************************** 
 * Class VcpRichText
 *****************************************************************************/
/*
 * DESCRIPTION
 *  Rich text text format class
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VcpRichText : public VcpRichTextFormat
{

// Constructor / Destructor
public:
    // <group DOM_TextView_VcpRichText_Constructor/Destructor>
    VcpRichText();

    // <group DOM_TextView_VcpRichText_Constructor/Destructor>
    VcpRichText(const VcpRichText &other);

    // <group DOM_TextView_VcpRichText_Constructor/Destructor>
    virtual ~VcpRichText() {}

// Operator
public:
    // <group DOM_TextView_VcpRichText_Method>
    // assign with another format
    VcpRichText &operator =(const VcpRichText &other);

// Override
public:

    /* DOM-NOT_FOR_SDK-BEGIN */

    // <group DOM_TextView_VcpRichText_Method>
    // Is the text format will affect the layout
    // For example, font size, font attribute will affect while text corlor not
    virtual VfxBool isAffectLayout(
        VfxS32 start,               // [IN] start index
        VfxS32 end                  // [IN] end index
        )
    {
        return VFX_FALSE;
    }

    // <group DOM_TextView_VcpRichText_Method>
    // rich text draw function
    virtual void draw(
        VfxDrawContext &dc,             // [IN]   device context
        const VfxPoint &point           // [IN]   draw position
    ) {}

    /* DOM-NOT_FOR_SDK-END */

    // <group DOM_TextView_VcpRichText_Method>
    // RETURNS: The size of the text
    virtual VfxSize getSize() const { return VfxSize(0, 0); }

// Method
public:
    // <group DOM_TextView_VcpRichText_Method>
    // set text font
    void setFont(
        const VfxFontDesc &font         // [IN] font
        );

    // <group DOM_TextView_VcpRichText_Method>
    // set text color
    void setTextColor(
        const VfxColor &value           // [IN] text color
        );

    // <group DOM_TextView_VcpRichText_Method>
    // set text background color
    void setTextBgColor(
        const VfxColor &value           // [IN] text background
        );

    // <group DOM_TextView_VcpRichText_Method>
    // is keyword text format
    VfxBool isKeywordFormat() { return (m_mode == VCP_TEXT_KEYWORD_NONE) ? VFX_FALSE : VFX_TRUE; }

// Implementation
public:
    // <group DOM_TextView_VcpRichText_Implementation>
    // text color
    VfxColor m_textColor;

    // <group DOM_TextView_VcpRichText_Implementation>
    // text background color
    VfxColor m_textBgColor;

    // <group DOM_TextView_VcpRichText_Implementation>
    // text font
    VfxFontDesc m_font;

    // <group DOM_TextView_VcpRichText_Implementation>
    // key word mode
    VcpTextKeyWordEnum m_mode;

    // <group DOM_TextView_VcpRichText_Implementation>
    // text format attribute flag, see 
    VfxS32 m_attrFlag;
};


/***************************************************************************** 
 * Class VcpRichTextHyperLink
 *****************************************************************************/
/*
 * DESCRIPTION
 *  Rich text hyper link format class
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VcpRichTextHyperLink : public VcpRichText
{

// Constructor / Destructor
public:
    // <group DOM_TextView_VcpRichTextHyperLink_Constructor/Destructor>
    VcpRichTextHyperLink();

    // <group DOM_TextView_VcpRichTextHyperLink_Constructor/Destructor>
    VcpRichTextHyperLink(const VcpRichTextHyperLink &other);

    // <group DOM_TextView_VcpRichTextHyperLink_Constructor/Destructor>
    virtual ~VcpRichTextHyperLink() {}

// Operator
public:
    // <group DOM_TextView_VcpRichTextHyperLink_Method>
    // assign with another format
    VcpRichTextHyperLink &operator =(const VcpRichTextHyperLink &other);

// Method
public:
    // <group DOM_TextView_VcpRichTextHyperLink_Method>
    // set link text
    void setLinkText(
        const VfxWString &str       // [IN] hyper link text
        )
    {
        m_linkText = str;
    }

    // <group DOM_TextView_VcpRichTextHyperLink_Method>
    // get link text
    VfxWString getLinkText()
    {
        return m_linkText;
    }

// Implementation
public:
    // <group DOM_TextView_VcpRichTextHyperLink_Implementation>
    // hyperlink text
    VfxWString m_linkText;
};


/***************************************************************************** 
 * Class VcpRichTextImage
 *****************************************************************************/
/*
 * DESCRIPTION
 *  Rich text image class
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VcpRichTextImage : public VcpRichTextFormat
{

// Constructor / Destructor
public:
    // <group DOM_TextView_VcpRichTextImage_Constructor/Destructor>
    VcpRichTextImage(IVfxAllocatable *client);
    // <group DOM_TextView_VcpRichTextImage_Constructor/Destructor>
    virtual ~VcpRichTextImage();

// Operator
public:
    // <group DOM_TextView_VcpRichTextImage_Method>
    // assign with another format
    VcpRichTextImage &operator =(const VcpRichTextImage &other);

// Override
public:

    /* DOM-NOT_FOR_SDK-BEGIN */
    
    // <group DOM_TextView_VcpRichTextImage_Method>
    // Is the text format will affect the layout
    // For example, font size, font attribute will affect while text corlor not
    virtual VfxBool isAffectLayout(
        VfxS32 start,               // [IN] start index
        VfxS32 end                  // [IN] end index
        )
    {
        return VFX_TRUE;
    }

    // <group DOM_TextView_VcpRichTextImage_Method>
    // rich text draw function
    virtual void draw(
        VfxDrawContext &dc,             // [IN]   device context
        const VfxPoint &point           // [IN]   draw position
    );

    /* DOM-NOT_FOR_SDK-END */

    // <group DOM_TextView_VcpRichTextImage_Method>
    // RETURNS: The size of the image
    virtual VfxSize getSize() const;

// Method
public:
    // <group DOM_TextView_VcpRichTextImage_Method>
    // set Image with image src
    void setImage(
        const VfxImageSrc *image        // [IN] image pointer
        );

    // <group DOM_TextView_VcpRichTextImage_Method>
    // set image with resource ID
    void setImage(
        VfxResId imageId                // [IN] image id
        );

// Implementation
private:
    // <group DOM_TextView_VcpRichTextImage_Implementation>
    // image pointer
    VfxImageSrc *m_image;

    // <group DOM_TextView_VcpRichTextImage_Implementation>
    // client frame
    IVfxAllocatable *m_client;
};


/***************************************************************************** 
 * Class VcpRichTextCustomFrame
 *****************************************************************************/
/*
 * DESCRIPTION
 *  Rich text custom frame class
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VcpRichTextCustomFrame : public VcpRichTextFormat
{

// Constructor / Destructor
public:
    // <group DOM_TextView_VcpRichTextCustomFrame_Constructor/Destructor>
    VcpRichTextCustomFrame();

    // <group DOM_TextView_VcpRichTextCustomFrame_Constructor/Destructor>
    VcpRichTextCustomFrame(const VcpRichTextCustomFrame &other);

    // <group DOM_TextView_VcpRichTextCustomFrame_Constructor/Destructor>
    virtual ~VcpRichTextCustomFrame();

// Operator
public:
    // <group DOM_TextView_VcpRichTextCustomFrame_Method>
    // assign with another format
    VcpRichTextCustomFrame &operator =(const VcpRichTextCustomFrame &other);

// Override
public:

    /* DOM-NOT_FOR_SDK-BEGIN */

    // <group DOM_TextView_VcpRichTextCustomFrame_Method>
    // Is the text format will affect the layout
    // For example, font size, font attribute will affect while text corlor not
    virtual VfxBool isAffectLayout(
        VfxS32 start,               // [IN] start index
        VfxS32 end                  // [IN] end index
        )
    {
        return VFX_TRUE;
    }

    // <group DOM_TextView_VcpRichTextCustomFrame_Method>
    // rich text draw function
    virtual void draw(
        VfxDrawContext &dc,             // [IN] device context
        const VfxPoint &point           // [IN] draw position
    );

    /* DOM-NOT_FOR_SDK-END */

    // <group DOM_TextView_VcpRichTextCustomFrame_Method>
    // RETURNS: The size of the image
    virtual VfxSize getSize() const;

// Method
public:
    // <group DOM_TextView_VcpRichTextCustomFrame_Method>
    // set custom frame
    void setFrame(
        VfxFrame *frame                 // [IN] custom frame pointer, CANNOT be NULL
        );

    // <group DOM_TextView_VcpRichTextCustomFrame_Method>
    // get custom frame
    VfxFrame *getFrame() const { return m_customFrame.get(); }

    /* DOM-NOT_FOR_SDK-BEGIN */

    // <group DOM_TextView_VcpRichTextCustomFrame_Method>
    // set custom frame pos
    void setPos(const VfxPoint &pos) { m_pos = pos; }

    // <group DOM_TextView_VcpRichTextCustomFrame_Method>
    // get custom frame pos
    VfxPoint getPos() const { return m_pos; }

    /* DOM-NOT_FOR_SDK-END */

// Implementation
private:
    // <group DOM_TextView_VcpRichTextCustomFrame_Implementation>
    // image pointer
    VfxWeakPtr<VfxFrame> m_customFrame;

    // <group DOM_TextView_VcpRichTextCustomFrame_Implementation>
    // frame pos
    VfxPoint m_pos;
};


#endif /* __VFX_TEXT_UTILS_H__ */
