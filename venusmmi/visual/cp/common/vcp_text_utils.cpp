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
 *  Vcp_text_utils.cpp
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  text utils class
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_text_utils.h"

#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vfx_sys_memory.h"
#include "vfx_cpp_base.h"
#include "vfx_system.h"
#include "vfx_basic_type.h"
#include "vfx_font_desc.h"  
#include "vrt_datatype.h"
#include "vfx_image_src.h"

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

extern "C"
{
#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif
}

extern "C"
{
#include "BIDIDef.h"
#include "string.h"
#include "PixcomFontEngine.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#ifdef __MMI_BIDI_ALG__
#include "BIDIGProt.h"
#endif
}

/***************************************************************************** 
 * Class VcpTextUtils
 *****************************************************************************/
VcpTextUtils::VcpTextUtils(IVfxAllocatable *owner) :
    m_text(VFX_WSTR_NULL),
    m_metrics(NULL),
    m_direction(BIDI_L),
    m_format(NULL)
{
    m_client = owner;
}


VcpTextUtils::~VcpTextUtils()
{
    // deinitialize
    resetTextInfo();
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void VcpTextUtils::setText(const VfxWChar *text, VcpRichTextFormat *format)
{
    setText(text, -1, format);
}


void VcpTextUtils::setText(const VfxWChar *text, VfxS32 len, VcpRichTextFormat *format)
{
    if (len > 0)
    {
        VfxWChar *textBuffer;
        VFX_ALLOC_MEM(textBuffer, sizeof(VfxWChar) * (len + 1), m_client);
        memcpy(textBuffer, text, sizeof(VfxWChar) * len);
        textBuffer[len] = 0;
        m_text = VFX_WSTR_MEM((const VfxWChar *)textBuffer);
        VFX_FREE_MEM(textBuffer);
    }
    else
    {
        m_text = VFX_WSTR_STATIC((const VfxWChar *)text);
    }
    m_format = format;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

const VfxWChar* VcpTextUtils::getText(void)
{
    return m_text.getBuf();
}


VfxS32 VcpTextUtils::getTextLength(void) const
{
    return vfx_sys_wcslen(m_text.getBuf());
}


VfxSize VcpTextUtils::getTextMetrics(
    VfxS32 n,
    VcpRichTextFormat *format)
{
    return getTextMetrics(0, n, NULL, -1, NULL, NULL, format);
}


VfxSize VcpTextUtils::getTextMetrics(
    VfxS32 start,
    VfxS32 n,
    VfxFontDesc *font,
    VfxS32 max_width,
    VfxS32 *len,
    VfxS32 *baseline,
    VcpRichTextFormat *format,
    VfxU8 isWordWrap,
    VfxBool isNeedClusterMetric,
    VfxS32 *adv_w)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TU1", SA_start);
#endif
    // Get text metrics and save cluster information
    mmi_fe_get_string_info_param_struct query;
    VfxSize textSize;
    VfxU32 ret_len = 0;

    if (n != 0)
    {
        // n = -1 mean metrics the whole text
        n = (n > 0) ? n : (m_text.getLength() - start);
    }

    if (max_width > 0)
    {
        // to enhance performance, we not check whole length characters
        n = VFX_MIN(n, max_width / VCP_TEXT_MIN_CHAR_WIDTH);
    }

    // set query structure
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = (VfxU8 *)m_text.getBuf() + start * ENCODING_LENGTH;
    query.n = n;
    query.w = 0;
    if (max_width >= 0)
    {
        query.targetWidth = max_width;
        query.enableTruncated = MMI_TRUE;
        query.checkCompleteWord = isWordWrap;
        query.checklinebreak = 1;
    }
    // Set font
    if (font)
    {
        setFont(*font);
    }

    VcpRichTextFormat *tuFormat = (format != NULL) ? format : m_format;
    // if plain text or richtext format which not affect layout
    if (tuFormat == NULL || !tuFormat->testAffectLayout(font, start, query.n))
    {
        if (isNeedClusterMetric)
        {
            ret_len = mmi_fe_get_string_widthheight_ext(&query, &m_direction, VcpTextUtils::getTextInfo, this);
        }
        else
        {
            // get text width height without BIDI(passing NULL to mmi_fe_get_string_widthheight_ext on third param means not BIDI)
            // Here should not use the string after BIDI for line break
            // for example text in memory buffer is: 
            // "ABCDEFGabcdefg" (Upper case is arabic character, low case is English character)
            // it will display in visual after BIDI as: abcdefgGFEDCBA
            // if we use the string after BIDI to break line, it will be:
            // | efgGFEDCBA|
            // |       abcd|
            // which is wrong, the last character "efg shows on the first line"
            // the right layout of line break should be
            // | abcFEDCBA|
            // |       efg|
            ret_len = mmi_fe_get_string_widthheight_ext(&query, &m_direction, NULL, this);

            // after line break, should get the text width height again to get it's real width height after BIDI 
            // which is the same as display
#if defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__)
            if (bidi_is_need_bidi(query.String, query.n))
            {
                if (max_width != -1)
                {
                    // for shapping characters, it will be different if there is character afterward or not.
                    // so we use a while loop to get its real width
                    // for example: string "WWWWWWWWWW"
                    // after shapping: "IIIIIIIIIW" ('W' is wider than 'I')
                    // If we get first five character width using following way, the return value is different:
                    // 1. "IIIIIIIIIW" pass whole string and get first 5 characters, it will get width of "IIIII"
                    // 2. "IIIII" pass first 5 characters alone, it will get width of "IIIIW"

                    // counter used to avoid infinit loop
                    VfxS32 counter = 0;
                    do
                    {
                        query.n = ret_len;
                        ret_len = mmi_fe_get_string_widthheight_ext(&query, &m_direction, VcpTextUtils::getTextInfo, this);

                        counter++;
                        // break in case of infinit loop
                        if (counter > 5)
                        {
                            break;
                        }
                    } while (ret_len != query.n);
                }
                else
                {
                    // for singleline always use query.n to get the string width because single line don't do line break
                    ret_len = mmi_fe_get_string_widthheight_ext(&query, &m_direction, VcpTextUtils::getTextInfo, this);
                }
            }
#endif
        }

        if (adv_w)
        {
            *adv_w = query.adv_w;
        }
        textSize.width = query.pWidth;
        textSize.height = query.pHeight;

        if (baseline)
        {
            *baseline = query.baseline;
        }
    }
    else
    {
        // handle rich text complicate case
        VfxS32 maxDescent = 0;
        VfxS32 maxAscent = 0;
        VfxSize maxSize;

        // get size by text segment separate by format
        VfxS32 segStart = 0;
        VfxS32 segEnd = 0;
        VcpRichTextFormat *curFormat = format;
        VfxSize segTextSize;
        VfxS32 segTextAdvW = 0;
        VfxS32 segMaxWidth = max_width;
        VfxS32 segRetLen = 0;
        VfxS32 segBaseline = 0;
        VfxS32 segDescent = 0;
        VfxBool isBreak = VFX_FALSE;
        if (adv_w)
        {
            *adv_w = 0;
        }
        while (segStart < n)
        {
            isBreak = VFX_FALSE;
            if (curFormat == NULL || 
               (curFormat && segStart < curFormat->m_range.getStart() /*|| (curFormat->m_attrFlag & TEXT_FORMAT_ATTR_IMAGE)*/))
            {
                if (curFormat)
                {
                    segEnd = VFX_MIN(curFormat->m_range.getStart(), n);
                }
                else
                {
                    segEnd = n;
                }

                segTextSize = getTextMetrics(
                    segStart,
                    (segEnd - segStart),
                    font,
                    segMaxWidth,
                    &segRetLen,
                    &segBaseline,
                    NULL,
                    isWordWrap,
                    isNeedClusterMetric,
                    &segTextAdvW);

                // blank baseline is 0, so should not handle it
                if (segBaseline > 0)
                {
                    segDescent = segTextSize.height - segBaseline;
                }

                // To avoid the baseline jump as the text changes, we set the min descent get from all common language
                VfxS32 ascent, descent;
                getTextHeightOfCommonLang(font, &ascent, &descent);
                segDescent = VFX_MAX(segDescent, descent);
                segBaseline = VFX_MAX(segBaseline, ascent);

                // break if word wrapping
                if (segRetLen < (segEnd - segStart))
                {
                    isBreak = VFX_TRUE;
                }
            }
            else
            {
                // draw text under this text format
                segEnd = VFX_MIN(curFormat->m_range.getEnd(), n);

                if (curFormat->getType() != VCP_RICH_TEXT_TYPE_TEXT &&
                    curFormat->getType() != VCP_RICH_TEXT_TYPE_HYPERLINK)
                {
                    if (segStart > 0 && curFormat->isOccopyOneLine())
                    {
                        break;
                    }
                    else
                    {
                        if (segMaxWidth < 0 || curFormat->getSize().width <= segMaxWidth)
                        {
                            // there is no width limit or the frame width is less than limit width, go on
                            segTextSize = curFormat->getSize();
                            segTextAdvW = segTextSize.width;
                            segRetLen = segEnd - segStart;
                            segBaseline = segTextSize.height;
                            segDescent = 0;

                            // save pos information when layout
                            if (curFormat->getType() == VCP_RICH_TEXT_TYPE_CUSTOM_FRAME)
                            {
                                ((VcpRichTextCustomFrame *)curFormat)->setPos(VfxPoint(maxSize.width, 0));
                                if (segTextSize.width < max_width)
                                {
                                    VfxS32 widthDiff = max_width - segTextSize.width;
                                    if (curFormat->getObjectAttribute() & VCP_RICH_TEXT_OBJ_ARRT_MID_ALIGN)
                                    {
                                        ((VcpRichTextCustomFrame *)curFormat)->setPos(VfxPoint(widthDiff / 2, 0));
                                    }
                                    else if (curFormat->getObjectAttribute() & VCP_RICH_TEXT_OBJ_ARRT_RIGHT_ALIGN)
                                    {
                                        ((VcpRichTextCustomFrame *)curFormat)->setPos(VfxPoint(widthDiff, 0));
                                    }
                                }
                            }

                            if ((segStart == 0) && curFormat->isOccopyOneLine())
                            {
                                isBreak = VFX_TRUE;
                            }
                        }
                        else if ((segMaxWidth == max_width) && (curFormat->getSize().width > max_width))
                        {
                            // the image takes one line
                            segTextSize = curFormat->getSize();
                            segTextAdvW = segTextSize.width;
                            segRetLen = segEnd - segStart;
                            segBaseline = segTextSize.height;
                            segDescent = 0;
                            isBreak = VFX_TRUE;

                            // save pos information when layout
                            if (curFormat->getType() == VCP_RICH_TEXT_TYPE_CUSTOM_FRAME)
                            {
                                ((VcpRichTextCustomFrame *)curFormat)->setPos(VfxPoint(maxSize.width, 0));
                                if (segTextSize.width < max_width)
                                {
                                    VfxS32 widthDiff = max_width - segTextSize.width;
                                    if (curFormat->getObjectAttribute() & VCP_RICH_TEXT_OBJ_ARRT_MID_ALIGN)
                                    {
                                        ((VcpRichTextCustomFrame *)curFormat)->setPos(VfxPoint(widthDiff / 2, 0));
                                    }
                                    else if (curFormat->getObjectAttribute() & VCP_RICH_TEXT_OBJ_ARRT_RIGHT_ALIGN)
                                    {
                                        ((VcpRichTextCustomFrame *)curFormat)->setPos(VfxPoint(widthDiff, 0));
                                    }
                                }
                            }

                            if ((segStart == 0) && curFormat->isOccopyOneLine())
                            {
                                isBreak = VFX_TRUE;
                            }
                        }
                        else
                        {
                            // exceed the required with, break
                            break;
                        }
                    }
                }
                else
                {
                    segTextSize = getTextMetrics(
                        segStart,
                        (segEnd - segStart),
                        &(((VcpRichText *)curFormat)->m_font),
                        segMaxWidth,
                        &segRetLen,
                        &segBaseline,
                        NULL,
                        isWordWrap,
                        isNeedClusterMetric,
                        &segTextAdvW);

                    segDescent = segTextSize.height - segBaseline;

                    // To avoid the baseline jump as the text changes, we set the min descent get from all common language
                    VfxS32 ascent, descent;
                    getTextHeightOfCommonLang(&(((VcpRichText *)curFormat)->m_font), &ascent, &descent);
                    segDescent = VFX_MAX(segDescent, descent);
                    segBaseline = VFX_MAX(segBaseline, ascent);

                    // break if word wrapping
                    if (segRetLen < (segEnd - segStart))
                    {
                        isBreak = VFX_TRUE;
                    }
                }

                // set current format to next format
                curFormat = curFormat->getNext();
            }

            // update line segment metrics
            if (segMaxWidth >= 0)
            {
                segMaxWidth -= segTextAdvW;
                if (segMaxWidth < 0)
                {
                    segMaxWidth = 0;
                }
            }
            maxDescent = VFX_MAX(maxDescent, segDescent);
            maxAscent = VFX_MAX(maxAscent, segBaseline);
            if (isBreak)
            {
                maxSize.width += segTextSize.width;
            }
            else
            {
                maxSize.width += segTextAdvW;
            }

            if (adv_w)
            {
                *adv_w += segTextAdvW;
            }
            maxSize.height = maxAscent + maxDescent; //maxVFX_MAX(maxSize.height, segTextSize.height);

            // move to next segment
            segStart += segRetLen;
            ret_len += segRetLen;

            if (isBreak)
                break;
        }

        textSize = maxSize;

        if (baseline)
        {
            // we use (Max text height - maxDescent of all text segment) as baseline
            // To avoid the baseline jump as the text changes, we set the min descent get from all common language
            *baseline = textSize.height - maxDescent;
        }
    }

    if (len)
    {
        *len = ret_len;
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TU1", SA_stop);
#endif
    return textSize;
}


VcpTextMetrics *VcpTextUtils::getMetric(VfxS32 index)
{
    // get text metrics if never call getTextMetrics
    if (m_metrics == NULL)
    {
        getTextMetrics(-1);
    }

    VcpTextMetrics *p = m_metrics;
    while (p)
    {
        if ((p->metrics.len == 1 && p->metrics.index == index) ||
            (p->metrics.len > 1 && p->metrics.index <= index &&
            (p->metrics.index + p->metrics.len) > index))
        {
            return p;
        }

        p = p->getNext();
    }

    return NULL;
}


VcpTextMetrics *VcpTextUtils::getMetricByVisual(VfxS32 index)
{
    // get text metrics if never call getTextMetrics
    if (m_metrics == NULL)
    {
        getTextMetrics(-1);
    }

    VcpTextMetrics *p = m_metrics;
    VfxS32 vIndex = 0;
    while (p)
    {
        if ((p->metrics.len == 1 && vIndex == index) ||
            (p->metrics.len > 1 && vIndex <= index &&
            (vIndex + p->metrics.len) > index))
        {
            return p;
        }
        vIndex += p->metrics.len;
        p = p->getNext();
    }

    return NULL;
}


void VcpTextUtils::getIndex(VfxS32 x_offset, VfxS32 *index1, VfxS32 *index2, VfxS32 *newX)
{
    if (getTextLength() <= 0)
    {
        *index1 = *index2 = 0;
        if (newX)
        {
            *newX = 0;
        }
        return;
    }
    
    // get text metrics if never call getTextMetrics
    if (m_metrics == NULL)
    {
        getTextMetrics(-1);
    }

    VcpTextMetrics *p = m_metrics;
    VcpTextMetrics *first = m_metrics;
    VcpTextMetrics *q = NULL;
    vrt_text_dir_type_enum textDir = getTextDirection();

    while (p)
    {
        q = p->getNext();

        // offset out of left boundary of this line, return first character of this line
        if (x_offset <= first->metrics.x)
        {
            if (VCP_TEXT_IS_BIDI_CHAR(first->metrics.bidi_type))
            {
                // if arabic character, should return last index (index + len)
                *index1 = *index2 = first->metrics.index + first->metrics.len;
            }
            else
            {
                *index1 = *index2 = first->metrics.index;
            }
            if (newX)
            {
                *newX = first->metrics.x;
            }
            return;
        }

        // offset out of right boundary of this line, return last character of this line
        if (q == NULL && x_offset >= p->metrics.x + p->metrics.adv_w)
        {
            if (!isFirstBidiChar())
            {
                VfxWChar* textBuf = (VfxWChar*)(m_text.getBuf());
                if (FONT_TEST_NEW_LINE_CHAR(textBuf[p->metrics.index]))
                {
                    *index1 = *index2 = p->metrics.index;
                }
                else
                {
                    if (VCP_TEXT_IS_BIDI_CHAR(p->metrics.bidi_type))
                    {
                        *index1 = *index2 = p->metrics.index;
                    }
                    else
                    {
                        *index1 = *index2 = p->metrics.index + p->metrics.len;
                    }
                }
            }
            else
            {
                // return first position if in R2L
                *index1 = *index2 = 0;
            }
            if (newX)
            {
                *newX = p->metrics.x + p->metrics.adv_w;
            }
            return;
        }

        if ((p->metrics.x < x_offset) && (p->metrics.x + (p->metrics.adv_w / 2) >= x_offset))
        {
            // offset locate first half of the character
            if (VCP_TEXT_IS_BIDI_CHAR(p->metrics.bidi_type))
            {
                *index1 = *index2 = p->metrics.index + p->metrics.len;
            }
            else
            {
                *index1 = *index2 = p->metrics.index;
            }
            if (newX)
            {
                *newX = p->metrics.x;
            }
            return;
        }
        else if (((p->metrics.x + (p->metrics.adv_w / 2)) < x_offset) &&
                 ((p->metrics.x + p->metrics.adv_w) > x_offset))
        {
            // offset locate second half of the character
            if (VCP_TEXT_IS_BIDI_CHAR(p->metrics.bidi_type))
            {
                *index1 = *index2 = p->metrics.index;
            }
            else
            {
                //*index1 = *index2 = (p->getNext() == NULL) ? (p->metrics.index + p->metrics.len) : (p->getNext()->metrics.index);
                *index1 = *index2 = p->metrics.index + p->metrics.len;
            }
            if (newX)
            {
                *newX = p->metrics.x + p->metrics.adv_w;
            }
            return;
        }
        else if (((p->metrics.x + p->metrics.adv_w) == x_offset) || // just after the p
                 (q && x_offset < q->metrics.x))                    // after p and before q
        {
            // just after the p
            *index1 = p->metrics.index;
            *index2 = (p->getNext() == NULL) ? (p->metrics.index + p->metrics.len) : (p->getNext()->metrics.index);
            if (newX)
            {
                *newX = x_offset;
            }
            return;
        }

        p = q;
    }
}



void VcpTextUtils::getOffset(VfxS32 index_before, VfxS32 index_after, VfxS32 *offset1, VfxS32 *offset2)
{
#if !defined(__MMI_BIDI_ALG__)
    VfxS32 tempOffset2 = 0;
#endif

    *offset1 = 0;
    if (offset2)
    {
        *offset2 = 0;
    }

    if (getTextLength() <= 0)
    {
        return;
    }

    // get text metrics if never call getTextMetrics
    if (m_metrics == NULL)
    {
        getTextMetrics(-1);
    }

    // offset2 == NULL means we need to get the accurate offset, not ambiguous (two offsets)
    if (offset2 == NULL)
    {
#if defined(__MMI_BIDI_ALG__)
        VfxWChar *pAfterBidiBuf;
        VfxU16 *pLToV;
        VfxU16 visiualStrLen = 0;
        VfxU16 visiualCursorPos = 0;
        VFX_ALLOC_MEM(pAfterBidiBuf, sizeof(VfxWChar) * (getTextLength() + 2), m_client);
        VFX_ALLOC_MEM(pLToV, sizeof(VfxU16) * (getTextLength() + 2), m_client);
        bidi_main_ext(
            (VfxU8 *)m_text.getBuf(),
            m_text.getLength(),
            index_after,
            (VfxU8 *)pAfterBidiBuf,
            &visiualStrLen,
            &visiualCursorPos,
            pLToV,
            NULL,
            0,
            0,
            0,
            P_ON);

        // get metric according to the visiual cursor position
        VcpTextMetrics *p = getMetricByVisual(visiualCursorPos);
        if (p)
        {
            *offset1 = p->metrics.x;
        }
        else
        {
            VcpTextMetrics *p = getMetricByVisual(visiualCursorPos - 1);
            if (p)
            {
                *offset1 = p->metrics.x + p->metrics.adv_w;
            }
        }

        VFX_FREE_MEM(pAfterBidiBuf);
        VFX_FREE_MEM(pLToV);
        return;
#else
        offset2 = &tempOffset2;
#endif
    }

    // Check if the index is contigeous or not
    VcpTextMetrics *p = m_metrics;
    VcpTextMetrics *q = NULL;
    VcpTextMetrics *pLast = p; // save the last metrics in memory (the largest index)
    VcpTextMetrics *p1 = NULL;
    VcpTextMetrics *p2 = NULL;
    VfxBool bCon = VFX_FALSE;

    // If index_before < 0, the first position
    if (index_before < 0)
    {
        while (p)
        {
            if (p->metrics.index == 0)
            {
                //if (m_direction == BIDI_L)
                if (!VCP_TEXT_IS_BIDI_CHAR(p->metrics.bidi_type))
                {
                    *offset1 = *offset2 = p->metrics.x;
                }
                else
                {
                    *offset1 = *offset2 = p->metrics.x + p->metrics.adv_w;
                }
                return;
            }
            p = p->getNext();
        }
    }
    
    while (p)
    {
        q = p->getNext();
        // considering the cluster, the index before is in the cluster range
        if ((p->metrics.len == 1 && p->metrics.index == index_before) ||
            (p->metrics.len > 1 && p->metrics.index <= index_before &&
            (p->metrics.index + p->metrics.len) > index_before))
        {
            p1 = p;
        }
        else if (p->metrics.index == index_after)
        {
            p2 = p;
        }

        if (p->metrics.index > pLast->metrics.index)
        {
            pLast = p;
        }

        // If not found q, return the last position of the text metrics
        // q == NULL means has reach the last metric
        if (!q && ((p1 && !p2) || (!p1)))
        {
            if (m_direction == BIDI_L)
            {
                if (VCP_TEXT_IS_BIDI_CHAR(pLast->metrics.bidi_type))
                {
                    *offset1 = *offset2 = pLast->metrics.x;
                }
                else
                {
                    *offset1 = *offset2 = pLast->metrics.x + pLast->metrics.adv_w;
                }
            }
            else
            {
                if (pLast->metrics.bidi_type == BIDI_L || pLast->metrics.bidi_type == AN || pLast->metrics.bidi_type == EN)
                {
                    *offset1 = *offset2 = pLast->metrics.x + pLast->metrics.adv_w;
                }
                else
                {
                    *offset1 = *offset2 = pLast->metrics.x;
                }
            }
            return;
        }

        if (p && q)
        {
            if ((p->metrics.index == index_before) && (q->metrics.index == index_after))
            {
                bCon = VFX_TRUE;
                p1 = p;
                p2 = q;
                break;
            }
            else if ((p->metrics.index == index_after) && (q->metrics.index == index_before))
            {
                bCon = VFX_TRUE;
                p1 = q;
                p2 = p;
                break;
            }
        }
        p = q;
    }

    if (p1 && !p2)
    {
        if (!VCP_TEXT_IS_BIDI_CHAR(p1->metrics.bidi_type))
        {
            *offset1 = *offset2 = (p1->metrics.x + p1->metrics.adv_w);
        }
        else
        {
            *offset1 = *offset2 = p1->metrics.x;
        }
    }
    else if (p1 && p2)
    {
        if (!VCP_TEXT_IS_BIDI_CHAR(p1->metrics.bidi_type))
        {
            *offset1 = p1->metrics.x + p1->metrics.adv_w;
            if (!VCP_TEXT_IS_BIDI_CHAR(p2->metrics.bidi_type))
            {
                // after E before E
                if (bCon)
                {
                    // the same position
                    *offset2 = *offset1;
                }
                else
                {
                    *offset2 = p2->metrics.x;
                }
            }
            else
            {
                // after E before A
                *offset2 = p2->metrics.x + p2->metrics.adv_w;
            }
        }
        else
        {
            *offset1 = p1->metrics.x;// + p1->metrics.adv_w;
            if (!VCP_TEXT_IS_BIDI_CHAR(p2->metrics.bidi_type))
            {
                // after A before E
                *offset2 = p2->metrics.x;
            }
            else
            {
                // after A before A
                if (bCon)
                {
                    // the same position
                    *offset2 = *offset1;
                }
                else
                {
                    *offset2 = p2->metrics.x + p2->metrics.adv_w;
                }
            }
        }
    }

    if (*offset1 > *offset2)
    {
        VfxS32 temp;
        temp = *offset1;
        *offset1 = *offset2;
        *offset2 = temp;
    }
}


#if __FOR_TODO__

VfxS32 VcpTextUtils::getPreIndex(VfxS32 index, VfxS32 *newX)
{
    VfxS32 offset1, offset2;
    VfxS32 index1, index2;
    if (index == 0)
    {
        return 0;
    }

    getOffset((index - 1), index, &offset1, &offset2);

    *newX = offset1;
    getIndex(offset1, &index1, &index2);

    return index1;
}


VfxS32 VcpTextUtils::getNextIndex(VfxS32 index, VfxS32 *newX)
{
    VfxS32 offset1, offset2;
    VfxS32 index1, index2;

    if (index >= getTextLength())
    {
        return getTextLength();
    }

    getOffset(index, (index + 1), &offset1, &offset2);

    *newX = offset2;
    getIndex(offset2, &index1, &index2);
    
    return index2;
}


VfxS32 VcpTextUtils::getLeftIndex(VfxS32 index, VfxS32 x_offset, VfxS32 *newX)
{
    VfxS32 index1, index2;

    if (getTextLength() <= 0)
    {
        *newX = 0;
        return 0;
    }

    // get text metrics if never call getTextMetrics
    if (m_metrics == NULL)
    {
        getTextMetrics(-1);
    }

    getIndex(x_offset, &index1, &index2);

    if (index1 == index2)
    {
        *newX = x_offset - m_metrics->getBefore(index)->metrics.adv_w;
        return m_metrics->getBefore(index)->metrics.index;
    }
    else
    {
        if (index2 == index)
        {
            *newX = x_offset;
            return index1;
        }
        else
        {
            *newX = x_offset - m_metrics->getBefore(index)->metrics.adv_w;
            return m_metrics->getBefore(index)->metrics.index;
        }
    }
}


VfxS32 VcpTextUtils::getRightIndex(VfxS32 index, VfxS32 x_offset, VfxS32 *newX)
{
    VfxS32 index1, index2;

    if (getTextLength() <= 0)
    {
        *newX = 0;
        return 0;
    }

    // get text metrics if never call getTextMetrics
    if (m_metrics == NULL)
    {
        getTextMetrics(-1);
    }

    getIndex(x_offset, &index1, &index2);

    if (index1 == index2)
    {
        // return the index on the left side of specific index cluster
        *newX = x_offset + m_metrics->getAfter(index)->metrics.adv_w;
        return m_metrics->getAfter(index)->metrics.index;
    }
    else
    {
        if (index1 == index)
        {
            *newX = x_offset;
            return index2;
        }
        else
        {
            *newX = x_offset + m_metrics->getAfter(index)->metrics.adv_w;
            return m_metrics->getAfter(index)->metrics.index;
        }
    }
}
#endif


void VcpTextUtils::resetTextInfo()
{
    VcpTextMetrics* metrics = m_metrics;

    // Free metrics memory    
    while (metrics)
    {
        metrics = metrics->getNext();
        VFX_DELETE(m_metrics);
        m_metrics = metrics;
    }
}


void VcpTextUtils::getTextInfo(mmi_fe_cluster_metrics_struct metrics, void *user_data)
{
    VcpTextMetrics* newMetrics;
    VcpTextUtils* obj = (VcpTextUtils*)user_data;

    //create a new text metrics info
    VFX_ALLOC_NEW(newMetrics, VcpTextMetrics, obj->m_client);

    memcpy(&newMetrics->metrics, &metrics, sizeof(mmi_fe_cluster_metrics_struct));

    if (obj->m_metrics == NULL)
        obj->m_metrics = newMetrics;
    else
        obj->m_metrics->appendNext(newMetrics);    
}


VfxS32 VcpTextUtils::indexOf(VfxWChar ch, VfxS32 start, VfxS32 end)
{
    VfxS32 i = 0;

    start = start > 0 ? start : 0;
    end = end > 0 ? end : 0;

    VFX_ASSERT(start <= end);
    for (i = start; i < end; i++)
    {
        if (m_text.getBuf()[i] == ch)
        {
            return i;
        }
    }

    return -1;
}


VfxS32 VcpTextUtils::lastIndexOf(VfxWChar ch, VfxS32 start, VfxS32 end)
{
    VfxS32 i = 0;

    start = start > 0 ? start : 0;
    end = end > 0 ? end : 0;

    VFX_ASSERT(start <= end);
    for (i = end; i >= start; i--)
    {
        if (m_text.getBuf()[i] == ch)
        {
            return i;
        }
    }

    return -1;
}


VfxS32 VcpTextUtils::getTextHeightOfCommonLang(VfxFontDesc *font, VfxS32 *pAscent, VfxS32 *pDescent)
{
    VfxS32 pHeight;

    mmi_fe_get_char_info_of_common_lang(font->size, &pHeight, pAscent, pDescent);

    return pHeight;
}


void VcpTextUtils::getTextInfoOfSimpleLang(VfxU8 size, VfxS32 *pHeight, VfxS32 *pAscent, VfxS32 *pDescent)
{
    mmi_fe_get_string_info_param_struct query;

    static VfxS32 ascent = 0, dscent = 0, height = 0, backup_size = 0;

//#if defined(__MMI_LANG_SM_CHINESE__)
    static const VfxWChar measureString[] = {0x0041, 0x0067, 0x5BB6, 0}; /* 'Ag' */
//#elif defined(__MMI_LANG_HK_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__)
    //static const VfxWChar measureString[] = {0x0041, 0x0067, 0x570B, 0}; /* 'Ag' */
//#else
    //static const VfxWChar measureString[] = {0x0041, 0x0067, 0}; /* 'Ag' */
//#endif

    if (backup_size == size && height != 0)
    {
        if (pAscent != NULL)
            *pAscent = ascent;

        if (pDescent != NULL)
            *pDescent = dscent;

        if (pHeight != NULL)
            *pHeight = height;

        return;
    }

    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = (unsigned char*)measureString;
    query.n = vfx_sys_wcslen(measureString);
    query.w = 0;

    vrt_font_struct v_font = {0};
    v_font.size = size;
    SetFont((*((stFontAttribute *)&v_font)), 0);
    mmi_fe_get_string_widthheight(&query);

    backup_size = size;
    ascent = query.maxAscent;
    dscent = query.maxDescent;
    height = query.pHeight;

    if (pAscent != NULL)
        *pAscent = ascent;

    if (pDescent != NULL)
        *pDescent = dscent;

    if (pHeight != NULL)
        *pHeight = height;

    return;
}


void VcpTextUtils::setFont(const VfxFontDesc &fontDesc)
{
    vrt_font_struct v_font;
    fontDesc.initVrtFont(v_font);
    SetFont((*((stFontAttribute *)&v_font)), 0);
}


vrt_text_dir_type_enum VcpTextUtils::getTextDirection()
{
    VfxU8 retDir = 0;

    retDir = mmi_fe_get_string_direction((VfxU8 *)m_text.getBuf(), m_text.getLength());

    if (retDir == BIDI_L)
    {
        return MG_TEXT_DIR_TYPE_L2R;
    }
    else
    {
        return MG_TEXT_DIR_TYPE_R2L;
    }   
}


VfxBool VcpTextUtils::isFirstBidiChar()
{
    if (getTextLength() <= 0)
    {
        return VFX_FALSE;
    }

    // get text metrics if never call getTextMetrics
    if (m_metrics == NULL)
    {
        getTextMetrics(-1);
    }

    VcpTextMetrics *p = NULL;
    p = getMetric(0);
    if (p)
    {
        if (VCP_TEXT_IS_BIDI_CHAR(p->metrics.bidi_type))
        {
            return VFX_TRUE;
        }
        else
        {
            return VFX_FALSE;
        }
    }
    else
    {
        return VFX_FALSE;
    }
}


/***************************************************************************** 
 * Class VcpTextMetrics
 *****************************************************************************/

VcpTextMetrics::VcpTextMetrics() : 
    m_next(NULL)
{
    // Initialize
}


VcpTextMetrics::VcpTextMetrics(const VcpTextMetrics &other) : 
    m_next(NULL)
{
    // Initialize
    memcpy(&metrics, &other.metrics, sizeof(mmi_fe_cluster_metrics_struct));
}


VcpTextMetrics &VcpTextMetrics::operator =(const VcpTextMetrics &other)
{
    memcpy(&metrics, &other.metrics, sizeof(mmi_fe_cluster_metrics_struct));

    return *this;
}


VcpTextMetrics* VcpTextMetrics::appendNext(VcpTextMetrics* newMetrics)
{    
    if (m_next == NULL)
    {
        m_next = newMetrics;
    }
    else
    {
        VcpTextMetrics *pNext = m_next;
        while (pNext->m_next != NULL)
        {
            pNext = pNext->m_next;
        }
        pNext->m_next = newMetrics;
    }

    return newMetrics;
}


VcpTextMetrics* VcpTextMetrics::getBefore(VfxS32 index)
{
    VcpTextMetrics* p = this;
    VcpTextMetrics* q = NULL;

    while (p)
    {
        q = p->getNext();
        if (q && q->metrics.index == index)
        {
            return p;
        }

        p = p->getNext();
    }

    return NULL;
}


VcpTextMetrics* VcpTextMetrics::getAfter(VfxS32 index)
{
    VcpTextMetrics* p = this;

    while (p)
    {
        if (p->metrics.index == index)
        {
            return p->getNext();
        }

        p = p->getNext();
    }

    return NULL;
}


/***************************************************************************** 
 * Class VfxTextRange
 *****************************************************************************/
VfxBool VfxTextRange::limitTo(const VfxTextRange& range)
{
    if (m_start < range.m_start)
        m_start = range.m_start;

    if (m_end > range.m_end)
        m_end = range.m_end;

    return 1;
}


/***************************************************************************** 
 * Class VcpRichTextFormat
 *****************************************************************************/
VcpRichTextFormat::VcpRichTextFormat() :
    m_next(NULL),
    m_type(VCP_RICH_TEXT_TYPE_NONE),
    m_objAttribute(VCP_RICH_TEXT_OBJ_ARRT_EMBED),
    m_bAdd(VFX_FALSE)
{
    m_range.setRange(0, 0);
}

VcpRichTextFormat::VcpRichTextFormat(const VcpRichTextFormat &other) : 
    m_next(NULL),
    m_type(VCP_RICH_TEXT_TYPE_NONE),
    m_bAdd(VFX_FALSE)
{
    m_type = other.m_type;
    m_range = other.m_range;
    m_objAttribute = other.m_objAttribute;
}


VcpRichTextFormat::~VcpRichTextFormat()
{
    if (m_bAdd && m_next)
    {
        //VFX_DELETE(m_next);
        VcpRichTextFormat* p_next = m_next;
        VcpRichTextFormat *temp = NULL;
        while(p_next != NULL)
        {
            temp = p_next;
            p_next = p_next->getNext();
            VFX_DELETE(temp);
        }
    }
}


VcpRichTextFormat &VcpRichTextFormat::operator =(const VcpRichTextFormat &other)
{
    m_type = other.m_type;
    m_range = other.m_range;
    m_objAttribute = other.m_objAttribute;
    return *this;
}


VcpRichTextFormat* VcpRichTextFormat::getLast()
{
    VcpRichTextFormat* last = this;

    while (last->getNext() != NULL)
    {
        last = last->getNext();
    }

    return last;
}


VcpRichTextFormat* VcpRichTextFormat::append(VcpRichTextFormat* format)
{
    if (m_next == NULL)
    {
        m_next = format;
    }
    else
    {
        VcpRichTextFormat *pNext = m_next;
        while (pNext->m_next != NULL)
        {
            pNext = pNext->m_next;
        }
        pNext->m_next = format;
    }
    return format;
}


VcpRichTextFormat& VcpRichTextFormat::add(VcpRichTextFormat &format, IVfxAllocatable *owner)
{
    VcpRichTextFormat *obj = NULL;
  //  VCP_TEXT_FORMAT_ALLOC_NEW(obj, format.getType(), NULL);
    switch (format.getType())
    {
    case VCP_RICH_TEXT_TYPE_TEXT:
        VFX_ALLOC_NEW(obj, VcpRichText, owner);
        break;
    case VCP_RICH_TEXT_TYPE_HYPERLINK:
        VFX_ALLOC_NEW(obj, VcpRichTextHyperLink, owner);
        break;
    case VCP_RICH_TEXT_TYPE_IMAGE:
        VFX_ALLOC_NEW_EX(obj, VcpRichTextImage, owner, (owner));
        break;
    case VCP_RICH_TEXT_TYPE_CUSTOM_FRAME:
        VFX_ALLOC_NEW(obj, VcpRichTextCustomFrame, owner);
        break;
    default:
        break;
    }
  //  VCP_TEXT_FORMAT_OBJ_COPY(obj, &format);
    switch (format.getType())
    {
    case VCP_RICH_TEXT_TYPE_TEXT:
        *((VcpRichText*)obj) = *((VcpRichText*)&format);
        break;
    case VCP_RICH_TEXT_TYPE_HYPERLINK:
        *((VcpRichTextHyperLink*)obj) = *((VcpRichTextHyperLink*)&format);
        break;
    case VCP_RICH_TEXT_TYPE_IMAGE:
        *((VcpRichTextImage*)obj) = *((VcpRichTextImage*)&format);
        break;
    case VCP_RICH_TEXT_TYPE_CUSTOM_FRAME:
        *((VcpRichTextCustomFrame*)obj) = *((VcpRichTextCustomFrame*)&format);
        break;
    default:
        break;
    }

    if (m_next == NULL)
    {
        m_next = obj;
    }
    else
    {
        VcpRichTextFormat *pNext = m_next;
        while (pNext->m_next != NULL)
        {
            pNext = pNext->m_next;
        }
        pNext->m_next = obj;
    }

    m_bAdd = VFX_TRUE;
    return *obj;
}


VfxBool VcpRichTextFormat::testAffectLayout(VfxFontDesc *font, VfxS32 start, VfxS32 end)
{
    VcpRichTextFormat *head = this;
    VfxBool ret = VFX_FALSE;

    // find start format object
    VfxTextRange textRange(start, end);
    while (head)
    {
        if (head->m_range.isOutside(textRange) &&
            !(head->m_range.getStart() == head->m_range.getEnd() && head->m_range.getStart() == start))
        {
            head = head->m_next;
        }
        else
        {
            if (head->isAffectLayout(start, end))
            {
                return VFX_TRUE;
            }
            break;
        }
    }

    VcpRichTextFormat *next = head;
    vrt_font_struct currFont;
    VfxBool bCurFOnt = VFX_FALSE;
    while (next && next->m_range.getStart()< end)
    {
        if ((((VcpRichText*)next)->m_attrFlag & TEXT_FORMAT_ATTR_FONT) &&
            (next->getType() == VCP_RICH_TEXT_TYPE_TEXT ||
            next->getType() == VCP_RICH_TEXT_TYPE_HYPERLINK))
        {
            // the font effect and font attribute will affect the string measure
            // for example, the underline font will be higher than normal font
            // the shadow font effect will be wider than normal font (Not consider yet)
            if (((VcpRichText*)next)->m_font.attr != VFX_FONT_DESC_ATTR_NORMAL/* ||
                ((VcpRichText*)next)->m_font.effect != VFX_FONT_DESC_EFFECT_NONE*/)
            {
                return VFX_TRUE;
            }

            ((VcpRichText*)next)->m_font.initVrtFont(currFont);
            bCurFOnt = VFX_TRUE;
        }

        // only image and font size will affect the layout
    #ifdef __MMI_VECTOR_FONT_SUPPORT__
        if (next->isAffectLayout(start, end) ||
            (bCurFOnt && font && (mmi_fe_size_to_pixel(font->size) != mmi_fe_size_to_pixel(currFont.size))))
    #else
        if (next->isAffectLayout(start, end) ||
            (bCurFOnt && font && (font->size != currFont.size)))
    #endif
        {
            ret = VFX_TRUE;
        }
        next = next->m_next;
    }

    return ret;
}


VfxBool VcpRichTextFormat::isOccopyOneLine()
{
    if ((m_objAttribute & VCP_RICH_TEXT_OBJ_ARRT_LEFT_ALIGN) ||
        (m_objAttribute & VCP_RICH_TEXT_OBJ_ARRT_MID_ALIGN)  ||
        (m_objAttribute & VCP_RICH_TEXT_OBJ_ARRT_RIGHT_ALIGN))
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


/***************************************************************************** 
 * Class VcpRichText
 *****************************************************************************/
VcpRichText::VcpRichText()
{
    m_textColor = VRT_COLOR_BLACK;
    m_textBgColor = VRT_COLOR_BLACK;
    m_attrFlag = 0;
    m_mode = VCP_TEXT_KEYWORD_NONE;
    m_next = NULL;
    m_type = VCP_RICH_TEXT_TYPE_TEXT;
}

VcpRichText::VcpRichText(const VcpRichText &other)
{
    m_textColor = other.m_textColor;
    m_textBgColor = other.m_textBgColor;
    m_font = other.m_font;
    m_range = other.m_range;
    m_attrFlag = other.m_attrFlag;
    m_mode = other.m_mode;
    m_objAttribute = other.m_objAttribute;
    m_next = NULL;
    m_type = VCP_RICH_TEXT_TYPE_TEXT;
}


VcpRichText &VcpRichText::operator =(const VcpRichText &other)
{
    m_textColor = other.m_textColor;
    m_textBgColor = other.m_textBgColor;
    m_font = other.m_font;
    m_range = other.m_range;
    m_attrFlag = other.m_attrFlag;
    m_mode = other.m_mode;
    m_objAttribute = other.m_objAttribute;

    return *this;
}


void VcpRichText::setFont(const VfxFontDesc &font)
{
    m_font = font;
    m_attrFlag |= TEXT_FORMAT_ATTR_FONT;
}


void VcpRichText::setTextColor(const VfxColor &value)
{
    m_textColor = value;
    m_attrFlag |= TEXT_FORMAT_ATTR_TEXT_COLOR;
}


void VcpRichText::setTextBgColor(const VfxColor &value)
{
    m_textBgColor = value;
    m_attrFlag |= TEXT_FORMAT_ATTR_BG_COLOR;
}


/***************************************************************************** 
 * Class VcpRichTextHyperLink
 *****************************************************************************/
VcpRichTextHyperLink::VcpRichTextHyperLink()
{
    m_linkText = VFX_WSTR_EMPTY;
    m_type = VCP_RICH_TEXT_TYPE_HYPERLINK;
}

VcpRichTextHyperLink::VcpRichTextHyperLink(const VcpRichTextHyperLink &other)
{
    m_linkText = other.m_linkText;
    m_type = VCP_RICH_TEXT_TYPE_HYPERLINK;
}


VcpRichTextHyperLink &VcpRichTextHyperLink::operator =(const VcpRichTextHyperLink &other)
{
    m_textColor = other.m_textColor;
    m_textBgColor = other.m_textBgColor;
    m_font = other.m_font;
    m_range = other.m_range;
    m_attrFlag = other.m_attrFlag;
    m_mode = other.m_mode;
    m_objAttribute = other.m_objAttribute;
    m_linkText = other.m_linkText;

    return *this;
}


/***************************************************************************** 
 * Class VcpRichTextImage
 *****************************************************************************/
VcpRichTextImage::VcpRichTextImage(IVfxAllocatable *client)
{
    m_image = NULL;
    m_next = NULL;
    m_type = VCP_RICH_TEXT_TYPE_IMAGE;
    m_client = client;
}


VcpRichTextImage &VcpRichTextImage::operator =(const VcpRichTextImage &other)
{
    m_range = other.m_range;
    m_objAttribute = other.m_objAttribute;
    VFX_ALLOC_NEW(m_image, VfxImageSrc, m_client);
    
    *m_image = *(other.m_image);

    return *this;
}


VcpRichTextImage::~VcpRichTextImage()
{
    if (m_image != NULL)
    {
        // release memory allocate when setImage
        VFX_DELETE(m_image);
    }
}


void VcpRichTextImage::setImage(const VfxImageSrc *image)
{
    if (m_image)
    {
        VFX_DELETE(m_image);
    }

    VFX_ALLOC_NEW(m_image, VfxImageSrc, m_client);

    *m_image = *image;
}


void VcpRichTextImage::setImage(VfxResId imageId)
{
    if (m_image)
    {
        VFX_DELETE(m_image);
    }

    // create image object, will be delete when close format object
    VFX_ALLOC_NEW(m_image, VfxImageSrc, m_client);

    m_image->setResId(imageId);
}


void VcpRichTextImage::draw(VfxDrawContext &dc, const VfxPoint &point)
{
    if (m_image)
    {
        dc.drawImage(point, *m_image);
    }
}


VfxSize VcpRichTextImage::getSize() const
{
    if (m_image)
    {
        return m_image->getSize();
    }
    else
    {
        return VfxSize(0, 0);
    }
}


/***************************************************************************** 
 * Class VcpRichTextCustomFrame
 *****************************************************************************/
VcpRichTextCustomFrame::VcpRichTextCustomFrame()
{
    m_customFrame = NULL;
    m_next = NULL;
    m_type = VCP_RICH_TEXT_TYPE_CUSTOM_FRAME;
    m_objAttribute = VCP_RICH_TEXT_OBJ_ARRT_MID_ALIGN;
}

VcpRichTextCustomFrame::VcpRichTextCustomFrame(const VcpRichTextCustomFrame &other)
{
    m_range = other.m_range;
    m_customFrame = NULL;
    m_next = NULL;
    m_type = VCP_RICH_TEXT_TYPE_CUSTOM_FRAME;
    m_objAttribute = other.m_objAttribute;
    m_pos = other.m_pos;
}


VcpRichTextCustomFrame &VcpRichTextCustomFrame::operator =(const VcpRichTextCustomFrame &other)
{
    m_range = other.m_range;
    m_objAttribute = other.m_objAttribute;
    m_customFrame = other.m_customFrame;
    m_pos = other.m_pos;

    return *this;
}


VcpRichTextCustomFrame::~VcpRichTextCustomFrame()
{

}


void VcpRichTextCustomFrame::setFrame(VfxFrame *frame)
{
    m_customFrame = frame;
    if (m_customFrame.get())
    {
        // hide custom frame until draw
        m_customFrame->setHidden(VFX_TRUE);

        // turn off auto animate to avoid the custom frame flash in wrong place
        m_customFrame->setAutoAnimate(VFX_FALSE);
    }
}


void VcpRichTextCustomFrame::draw(VfxDrawContext &dc, const VfxPoint &point)
{
    if (m_customFrame.get())
    {
     //   m_customFrame->invalidate();
        m_customFrame->setHidden(VFX_FALSE);
    }
}


VfxSize VcpRichTextCustomFrame::getSize() const
{
    if (m_customFrame.get())
    {
        return m_customFrame->getSize();
    }
    else
    {
        return VfxSize(0, 0);
    }
}

