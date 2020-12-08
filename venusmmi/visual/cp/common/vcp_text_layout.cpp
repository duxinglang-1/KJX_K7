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
 *  Vcp_text_layout.cpp
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  text layout class
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "vcp_text_layout.h"
#include "vcp_text_view.h"
//#include "GlobalResdef.h"
#include "mmi_rp_srv_venus_component_text_view_def.h"
#include "vadp_sys_trc.h"
#include "vrt_datatype.h"
#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_draw_context.h"
#include "vfx_basic_type.h"
#include "vcp_text_utils.h"
#include "vrt_system.h"
#include "vcp_text_storage.h"
#include "vfx_signal.h"
#include "vfx_object.h"
#include "vfx_system.h"
#include "vfx_font_desc.h"
#include "vfx_sys_memory.h"
#include "vfx_frame.h"

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
#include "MMIDataType.h"
#include "PixcomFontEngine.h"
#include "string.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "App_str.h"
}

#define VCP_TEXT_BASELINE_GAP         3
#define VCP_TEXT_LINE_MIN_WIDTH       2

#if defined(__MMI_MAINLCD_480X800__)
#define VCP_TEXT_CUSTOM_FRAME_GAP     7  // the gap between custom frame and next line
#define VCP_TEXT_BOTTOM_FRAME_GAP    14  // the gap between bottom frame and last line text
#else
#define VCP_TEXT_CUSTOM_FRAME_GAP     4  // the gap between custom frame and next line
#define VCP_TEXT_BOTTOM_FRAME_GAP     8  // the gap between bottom frame and last line text
#endif

/***************************************************************************** 
 * Class VcpTextBasicLayout
 *****************************************************************************/
VcpTextBasicLayout::VcpTextBasicLayout()
{
    m_storage = NULL;
    m_hintTextColor = VFX_COLOR_GREY;
    m_normalTextColor = VFX_COLOR_BLACK;
    m_underlineColor = VFX_COLOR_GREY;
    m_hint = VFX_WSTR_EMPTY;
    m_isHideHint = VFX_FALSE;
    m_alignMode = ALIGN_MODE_NATURAL;
    m_verticalAlignMode = VERT_ALIGN_MODE_TOP;
    m_truncateMode = TRUNCATE_MODE_NONE;
    m_lineGap = VCP_TEXT_DEFAULT_LINE_GAP;
    m_minLineHeight = 0;
    m_checkForceUpdate = VFX_FALSE;
    m_checkUpdate = VFX_FALSE;
    m_client = NULL;
    m_isUnderline = VFX_FALSE;
    m_direction = MG_TEXT_DIR_TYPE_NORMAL;
    m_isMask = VFX_FALSE;
    m_changedCharCount = 0;
    m_wrapStyle = VCP_TEXT_WRAP_WORD_WRAP;
    m_isDraw = VFX_TRUE;

#if defined(__COSMOS_MMI_PACKAGE__)
    m_hintTextColor = VFX_COLOR_RES(VCP_COL_TEXT_VIEW_HINT_TEXT);
    m_normalTextColor = VFX_COLOR_RES(VCP_COL_TEXT_VIEW_NRML_TEXT);
    m_underlineColor = VFX_COLOR_RES(VCP_COL_TEXT_VIEW_UNDERLINE);
    m_font = VFX_FONT_RES(VCP_FNT_TEXT_VIEW_TXT);
#endif

    m_orgFontSize = m_font.size;
    m_maxLineNum = -1;

    m_layoutTimer = NULL;
}


void VcpTextBasicLayout::draw(VfxDrawContext &dc, const VfxRect &area, VfxPoint offsetToDC, VfxBool isDrawHilite)
{
   if (!m_isDraw)
       return;

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TLD", SA_start);
#endif
    VfxS32 lineStart, lineEnd;
    VfxRect clip = area;
    VcpTextUtils tuTemp(m_client);
    VfxS32 minLineHeight, ascent, descent;
    VfxS32 i = 0;
    minLineHeight = tuTemp.getTextHeightOfCommonLang(&m_font, &ascent, &descent);

    clip.offsetWith(offsetToDC);
    dc.setClip(clip);

    if (area.isEmpty())
    {
        lineStart = 0;
        lineEnd = getLineCount();
    }
    else
    {
        lineStart = getLineIndexByY(area.getMinY());
        lineEnd = getLineIndexByY(area.getMaxY());
    }

    // Draw empty area underline
    if (m_isUnderline && (getHeight() < m_layoutRect.getHeight()) && !isDrawHilite)
    {
        VfxRect lastRect = getLineBounds(lineEnd);
        VfxS32 startY = lastRect.getMaxY() + offsetToDC.y + m_lineGap;
        VfxS32 baseline = getLineBaseLine(lineEnd);

        dc.setStrokeColor(m_underlineColor);

        VfxS32 lineHeight = VFX_MAX(minLineHeight, m_minLineHeight);

        // if first line is custom frame, the baseline will be -1, 
        // so in this case, we'll use lineHeight to draw empty line 
        if (baseline < 0)
        {
            baseline = lineHeight;
        }

        while ((getHeight() + i * lineHeight + baseline) < m_layoutRect.getHeight())
        {
            dc.drawLine(
                m_layoutRect.getMinX() + offsetToDC.x,
                startY + baseline + VCP_TEXT_BASELINE_GAP,
                m_layoutRect.getMaxX() + offsetToDC.x,
                startY + baseline + VCP_TEXT_BASELINE_GAP);

            startY += lineHeight + m_lineGap;
            i++;
        }
    }

    // Show hint text if content empty
    if (m_storage->getTextLength() <= 0 && !m_isHideHint && !isDrawHilite)
    {
        VfxS32 baseline = 0;
        VfxS32 heightDiff = 0;

        // use simple language info to draw hint text
        // for singleline, the min height is get from simple language, the hint may not 
        // vertical align if not use simple langauge info
        tuTemp.getTextInfoOfSimpleLang(m_font.size, &minLineHeight, &ascent, &descent);

        if (minLineHeight < m_minLineHeight)
        {
            heightDiff = m_minLineHeight - minLineHeight;
            baseline = ascent + heightDiff;
        }
        else
        {
            baseline = ascent;
            heightDiff = 0;
        }
        dc.setFont(m_font);
        dc.setFillColor(m_hintTextColor);

        VfxRect hintRect = getLineBounds(0);
        // get hint text width
        VfxSize hintSize;
        hintSize = m_font.measureStr(m_hint);
        hintRect.size.width = hintSize.width;
        if (vrt_sys_get_text_dir() == MG_TEXT_DIR_TYPE_R2L)
        {
            hintRect.origin.x += hintSize.width;
        }
        dc.drawTextBaseline(hintRect, baseline, m_hint, m_hint.getLength());

        // draw underline
        if (m_isUnderline)
        {
            VfxS32 startY = m_layoutRect.getMinY() + offsetToDC.y + m_lineGap;
            dc.setStrokeColor(m_underlineColor);
            dc.drawLine(
                    m_layoutRect.getMinX() + offsetToDC.x,
                    startY + baseline + VCP_TEXT_BASELINE_GAP,
                    m_layoutRect.getMaxX() + offsetToDC.x,
                    startY + baseline + VCP_TEXT_BASELINE_GAP);
        }

    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TLD", SA_stop);
    #endif
        return;
    }
    
    for (i=lineStart; i<=lineEnd; i++)
    {
        if (i >= getLineCount())
            break;

        drawLine(i, dc, area, offsetToDC, isDrawHilite);
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TLD", SA_stop);
#endif
}


VfxS32 VcpTextBasicLayout::getHeight()
{
    VfxS32 count = getLineCount();
    VfxRect rectFirstLine;
    VfxRect rect;
    VfxS32 ret;

    if (count == 0)
        return 0;
    
    rectFirstLine = getLineBounds(0);
    rect = getLineBounds(count - 1);

    ret = m_lineGap + rect.getMaxY() - rectFirstLine.getMinY() + 1;

    if (m_isUnderline)
    {
        ret += VCP_TEXT_BASELINE_GAP;
    }

    return ret;
    //return rect.getMaxY() + 1;
}


VfxS32 VcpTextBasicLayout::getWidth()
{
    VfxS32 count = getLineCount();
    VfxRect rect;
    
    if (count == 0)
        return 0;
    
    if (multiline())
    {
        rect = getLayoutRect();
        return rect.getWidth();
    }
    else
    {
        rect = getLineBounds(0);
        return rect.getWidth() + VCP_EDITOR_CURSOR_WIDTH; // left for cursor width
    }
}


void VcpTextBasicLayout::onTextChanged(VfxS32 start, VfxS32 end, VfxS32 changedCharCount, VcpTextStorage::TextChangeEnum changed)
{
    if (changed == VcpTextStorage::TEXT_CHANGE_INIT)
    {
        m_dirty.setRange(start, end);
        m_changedCharCount = 0;
    }
    else
    {
        if (m_dirty.getLength() > 0)
        {
            // union with old dirty range
            VfxS32 rangeStart = VFX_MIN(m_dirty.getStart(), start);
            VfxS32 rangeEnd = VFX_MAX(m_dirty.getEnd(), end);
            m_dirty.setRange(rangeStart, rangeEnd);
        }
        else
        {
            m_dirty.setRange(start, end);
        }

        if (changed == VcpTextStorage::TEXT_CHANGE_DELETED)
        {
            // adjust dirty end within text range
            VfxS32 dirtyEnd = m_dirty.getEnd();
            VfxS32 textLen = m_storage->getTextLength();

            if (m_maxLineNum > 0 && getLineCount() >= m_maxLineNum)
            {
                dirtyEnd = textLen;
            }
            else
            {
                dirtyEnd = VFX_MIN(dirtyEnd, textLen);
            }
            m_dirty.setRange(m_dirty.getStart(), dirtyEnd);
        }
        m_changedCharCount += changedCharCount;
    }
    
    checkUpdate();
}


void VcpTextBasicLayout::applyTextFormat(VfxDrawContext &dc, VcpRichTextFormat *format)
{
    if (format && (format->getType() == VCP_RICH_TEXT_TYPE_TEXT || format->getType() == VCP_RICH_TEXT_TYPE_HYPERLINK))
    {
        if (((VcpRichText*)format)->m_attrFlag & TEXT_FORMAT_ATTR_TEXT_COLOR)
        {
            // text color
            dc.setFillColor(((VcpRichText*)format)->m_textColor);

            // underline/strikethrough color
            dc.setStrokeColor(((VcpRichText*)format)->m_textColor);
        }

        if (((VcpRichText*)format)->m_attrFlag & TEXT_FORMAT_ATTR_FONT)
        {
            dc.setFont(((VcpRichText*)format)->m_font);
        }
        else
        {
            dc.setFont(m_font);
        }
    }
    else
    {
        // use default
        dc.setStrokeColor(m_normalTextColor);
        dc.setFillColor(m_normalTextColor);
        dc.setFont(m_font);
    }
}


void VcpTextBasicLayout::setHighlight(VfxS32 start, VfxS32 end)
{
    setSelection(VfxTextRange(start, end));
}


void VcpTextBasicLayout::getHighlight(VfxS32 *start, VfxS32 *end)
{
    if (start)
    {
        *start = m_selection.getStart();
    }
    if (end)
    {
        *end = m_selection.getEnd();
    }
}


void VcpTextBasicLayout::checkUpdate()
{
    if (!m_checkUpdate)
    {
        m_checkUpdate = VFX_TRUE;

        // if already under layout process, stop it.
        if (m_layoutTimer && m_layoutTimer->getIsEnabled())
        {
            VFX_OBJ_CLOSE(m_layoutTimer);
        }
        vfxPostInvoke1(this, &VcpTextBasicLayout::updateLayout, VFX_TRUE);
    }
}


void VcpTextBasicLayout::setLineGap(VfxS32 value)
{
    if (m_lineGap != value)
    {
        m_lineGap = value;

        checkUpdate();
    }
}


void VcpTextBasicLayout::setMinLineHeight(VfxS32 value)
{
    if (m_minLineHeight != value)
    {
        m_minLineHeight = value;

        checkUpdate();
    }
}


void VcpTextBasicLayout::setAlignMode(AlignModeEnum value)
{
    if (m_alignMode != value)
    {
        m_alignMode = value;

        checkUpdate();
    }
}


void VcpTextBasicLayout::setVerticalAlignMode(VertAlignModeEnum value)
{
    if (m_verticalAlignMode != value)
    {
        m_verticalAlignMode = value;

        checkUpdate();
    }
}


void VcpTextBasicLayout::setTextWrapStyle(VcpTextWrapStyleEnum wrap)
{
    if (m_wrapStyle!= wrap)
    {
        m_wrapStyle = wrap;

        checkUpdate();
    }
}


void VcpTextBasicLayout::setMask(VfxBool isMask)
{
    if (m_isMask != isMask)
    {
        m_isMask = isMask;

        // need to force layout if change to non-mask mode to mask mode
        // if not set dirty range, updateLayout will not relayout because dirty length is 0
        m_dirty.setRange(0, m_storage->getTextLength());

        checkUpdate();
    }
}


void VcpTextBasicLayout::hideHintText(VfxBool value)
{
    if (m_isHideHint != value)
    {
        m_isHideHint = value;
        checkUpdate();
    }
}

        
void VcpTextBasicLayout::updateLayout(VfxBool isAsync)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TLU", SA_start);
#endif
    // re-layout whole text when text layout changes, (layout rect, bounds, linegap...)
    if (m_checkUpdate && m_storage->getText() && !m_checkForceUpdate)
    {
        m_checkUpdate = VFX_FALSE;

        VfxS32 textLength = m_storage->getTextLength();

        // get key word
        // only support text view
        if (m_storage->isKeywordMode())
        {
            // get key word
            VcpRichTextFormat *format;
            format = m_storage->getKeyword();
            m_storage->addFormatObject(format);
            m_storage->deleteRichTextFormat(format);
        }

    #ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
        if (m_storage->isIconMode())
        {
            kal_uint32 time1,time2;
            kal_get_time(&time1);
            // -3 for emotion icon
            if (m_dirty.getStart() >= 3)
            {
                m_storage->updateFormatForIcon(m_dirty.getStart() - 3, m_dirty.getEnd());
            }
            else
            {
                m_storage->updateFormatForIcon(0, m_dirty.getEnd());
            }
            kal_get_time(&time2); 
            VFX_LOG(VFX_FUNC2, VCP_TEXT_LAYOUT_UPDATE_ICON, m_dirty.getStart(), m_dirty.getEnd(), kal_ticks_to_milli_secs(time2 - time1));
        }
    #endif

        // 1). layout when dirty area > 0 or 
        // 2). m_changedCharCount != 0;
        //       |abc  |
        //       |d|   |
        //     delete 'd' before cursor, the dirty area  = 0 but m_changedCharCount = -1 
        //     so we need to update layout in this case
        // 3). When content is empty (textLength == 0), should layout once
        if (m_dirty.getLength() > 0 || (m_changedCharCount != 0) || (textLength == 0))
        {
            layout(m_dirty.getStart(), m_dirty.getEnd(), m_changedCharCount);
            m_changedCharCount = 0;

            // if not async mode, should layout all at once
            while (!isAsync && (m_dirty.getLength() > 0))
            {
                layout(m_dirty.getStart(), m_dirty.getEnd(), m_changedCharCount);
            }
        }
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TLU", SA_stop);
#endif
}


VfxS32 VcpTextBasicLayout::getIndexOfPreLine(VfxS32 index, VfxS32 x)
{
    VfxS32 lineIndex = getLineIndex(index);
    VfxS32 retIndex = 0;

    if (lineIndex == 0)
        return -1;

    // when make the cursor at the end of one line by tap (only though tap), the index is the start of next line (before 'c')
    // so in this case, lineIndex will be the next line (line 3), in this case, we need to -2 (line 1)
    // example:
    // 1 | aaaaaaa  |  UNK    | aaaaaa|a |
    // 2 | bbbbbbb| |  --->   | bbbbbbb  |
    // 3 | ccccccc  |         | ccccccc  |
    if ((getLineStart(lineIndex) == index) && (getLineBounds(lineIndex - 1).getMaxX() == (x - 1)))
    {
        lineIndex -= 2;

        if (lineIndex < 0)
            return -1;
    }
    else
    {
        // move to previous line
        lineIndex--;
    }

    // -1 to makes the utils getIndex return the only value of index 
    // to avoid the x just in the middle of two character
    retIndex = getIndexOfPos(lineIndex, x - 1, NULL);

    VfxS32 lineStart = getLineStart(lineIndex);
    VfxS32 lineEnd = getLineEnd(lineIndex);
    // if locate to the end of line, move to previous character 
    // because we can't locate cursor to the end line by previous/next line
    if (retIndex == lineEnd && (lineEnd - lineStart) > 1)
    {
        retIndex--;

        // Adjust cursor position for icon
        if (m_storage->getRichTextFormat())
        {
            VcpRichTextFormat *obj = getObjectOfIndex(retIndex);
            if (obj && (obj->getType() == VCP_RICH_TEXT_TYPE_IMAGE) &&
                (retIndex > obj->m_range.getStart() && (retIndex < obj->m_range.getEnd())))
            {
                retIndex = obj->m_range.getStart();
            }
        }        
    }

    return retIndex;
}


VfxS32 VcpTextBasicLayout::getIndexOfNextLine(VfxS32 index, VfxS32 x)
{
    VfxS32 lineIndex = getLineIndex(index);
    VfxS32 retIndex = 0;

    // move to next line

    // when make the cursor at the end of one line by tap (only though tap), the index is the start of next line (before 'b')
    // so in this case, lineIndex will be the next line (line 2), in this case, next line index is lineIndex.
    // example:
    // 1 | aaaaaaa| |  DNK    | aaaaaaa  |
    // 2 | bbbbbbb  |  --->   | bbbbbb|b |
    // 3 | ccccccc  |         | ccccccc  |
    if (!(lineIndex > 0 && (getLineStart(lineIndex) == index) && (getLineBounds(lineIndex - 1).getMaxX() == (x - 1))))
    {
        if (lineIndex == (getLineCount() - 1))
            return -1;
        lineIndex++;
    }

    // -1 to makes the utils getIndex return the only value of index (index1 == index2)
    // to avoid the x just in the middle of two character
    retIndex = getIndexOfPos(lineIndex, x - 1, NULL);

    VfxS32 lineStart = getLineStart(lineIndex);
    VfxS32 lineEnd = getLineEnd(lineIndex);
    // if locate to the end of line, move to previous character 
    // because we can't locate cursor to the end line by previous/next line
    if (retIndex == lineEnd && (lineEnd - lineStart) > 1 && (lineIndex != getLineCount() - 1))
    {
        retIndex--;

        // Adjust cursor position for icon
        if (m_storage->getRichTextFormat())
        {
            VcpRichTextFormat *obj = getObjectOfIndex(retIndex);
            if (obj && (obj->getType() == VCP_RICH_TEXT_TYPE_IMAGE) &&
                (retIndex > obj->m_range.getStart() && (retIndex < obj->m_range.getEnd())))
            {
                retIndex = obj->m_range.getStart();
            }
        } 
    }

    return retIndex;
}


VfxPoint VcpTextBasicLayout::getPosOfIndex(VfxPoint pos, VfxS32 index, VcpTextUtils *assignTu)
{
    VfxS32 lineIndex = getLineIndex(index);
    VfxRect lineRect = getLineBounds(lineIndex);

    if (!isIndexInCurrentLine(index, pos))
    {
        /* If Cursor locate at the last position of line, return the last point of previous line */
        lineRect = getLineBounds(lineIndex - 1);

        // if first char is BIDI char, the last position is on the left, otherwise, on the right side
        VcpTextUtils tuDir(m_client);
        VfxS32 lineStart, lineEnd;
        lineStart = getLineStart(lineIndex - 1);
        lineEnd = getLineEnd(lineIndex - 1);
        VfxS32 preLineHeight = getLineTextHeight(lineIndex - 1);
        if (lineStart == lineEnd)
        {
            // if previous line is custom frame, return the max y of previous line
            preLineHeight = 1;
        }
        tuDir.setText(m_storage->getText() + lineStart, lineEnd - lineStart + 1);
        if (tuDir.isFirstBidiChar())
        {
            return VfxPoint(lineRect.getMinX(), lineRect.getMaxY() - preLineHeight + 1);
        }
        else
        {
            return VfxPoint(lineRect.getMaxX(), lineRect.getMaxY() - preLineHeight + 1);
        }
    }
    else
    {
        VfxPoint p1, p2;
        p1 = getPosOfIndex(index, &p2, assignTu);

        // return a point which is near to specific pos
        if (VFX_ABS(p1.x - pos.x) < VFX_ABS(p2.x - pos.x))
        {
            return p1;
        }
        else
        {
            return p2;
        }
    }
}


VfxBool VcpTextBasicLayout::isIndexInCurrentLine(VfxS32 index, VfxPoint pos)
{
    VfxS32 lineIndex = getLineIndex(index);
    VfxRect lineRect = getLineBounds(lineIndex);
    VfxS32 textLength = m_storage->getTextLength();

    // if singleline return true
    if (!multiline())
    {
        return VFX_TRUE;
    }

    if (index == 0 && lineIndex == 0)
    {
        // the first position
        return VFX_TRUE;
    }
    else if (pos.y < 0)
    {
        // out of laout area
        if (lineIndex == 0)
        {
            return VFX_TRUE;
        }
        else
        {
            return VFX_FALSE;
        }
    }
    else if ((pos.y >= 0 && pos.y < lineRect.getMinY()) &&
             (index == getLineStart(lineIndex)) &&
             (textLength > 0))
    {
        return VFX_FALSE;
    }
    else
    {
        VcpRichTextFormat *textFormat = NULL;
        textFormat = m_storage->getRichTextFormat();
        if (textFormat)
        {
            textFormat = textFormat->getLast();
        }

        // pen on last line and last line is custom frame or image
        // should return previous line
        if (textFormat && textFormat->isOccopyOneLine() &&
            textFormat->m_range.getStart() == textLength &&
            lineIndex == (getLineCount() -1))
        {
            return VFX_FALSE;
        }
        else
        {
            return VFX_TRUE;
        }
    }
}


VfxPoint VcpTextBasicLayout::getPosOfIndex(VfxS32 index, VfxPoint *point1, VcpTextUtils *assignTu)
{
    VfxPoint p(0, 0);
    VfxRect rect;
    const VfxWChar *text;
    VfxS32 lineCharCount = 0;
    VfxS32 offset1, offset2;
    
    if (getLineCount() == 0)
        return p;

    // empty content
    if (m_storage->getTextLength() == 0)
    {
        VfxRect lineRect = getLineBounds(0);
        p = lineRect.origin;
        p.y = lineRect.getMaxY() - getLineTextHeight(0) + 1;
        switch (m_alignMode)
        {
        case ALIGN_MODE_RIGHT:
            p.x = m_layoutRect.getMaxX();
            break;
        case ALIGN_MODE_CENTER:
            p.x = m_layoutRect.origin.x + m_layoutRect.getWidth() / 2;
            break;
        default:
            p.x = m_layoutRect.getMinX();
            break;
        }
        if (point1)
        {
            *point1 = p;
        }
        return p;
    }

    VfxS32 lineIndex = getLineIndex(index);
    text = getLineText(lineIndex, &lineCharCount);

    // store mask character buffer
    // we'll not change the original buffer directly, for example,
    // original buffer is "123a45", 'a' is under multitap state, and the password string will be "***a**"
    VfxWChar *temp_String = NULL;
    // convert to mask characters
    if (m_isMask)
    {
        VFX_ALLOC_MEM(temp_String, (lineCharCount + 1) * sizeof(VfxWChar), m_client);

        VfxTextRange markRange = m_marked;
        VfxTextRange lineRange = VfxTextRange(getLineStart(lineIndex), getLineEnd(lineIndex));
        if (!(m_marked.isOutside(lineRange)))
        {
            markRange.limitTo(lineRange);
            markRange.shift(-getLineStart(lineIndex));
        }
        else
        {
            markRange.setRange(0, 0);
        }

        convertToMaskText(text, lineCharCount, temp_String, lineCharCount, markRange);

        text = temp_String;
    }
    
    rect = getLineBounds(lineIndex);
    VfxS32 lineStart = getLineStart(lineIndex);

    // convert index to current line index;
    index -= lineStart;

    // handle format
    VcpRichTextFormat *format;
    VfxS32 start, end;
    start = lineStart;
    end = start + lineCharCount;
    format = m_storage->getRichTextFormat(start, end);
    if (format == NULL)
    {
        // plain text
        if (assignTu)
        {
            assignTu->setText(text, lineCharCount);
            assignTu->setFont(m_font);
            if (point1)
            {
                // ambiguous offset
                assignTu->getOffset(index - 1, index, &offset1, &offset2);
            }
            else
            {
                // accurate offset
                assignTu->getOffset(index - 1, index, &offset1, NULL);
            }
        }
        else
        {
            VcpTextUtils tu(m_client);
            tu.setText(text, lineCharCount);
            tu.setFont(m_font);
            if (point1)
            {
                // ambiguous offset
                tu.getOffset(index - 1, index, &offset1, &offset2);
            }
            else
            {
                // accurate offset
                tu.getOffset(index - 1, index, &offset1, NULL);
            }
        }

        if (m_alignMode == ALIGN_MODE_RIGHT)
        {
            // if right alignment, the rect width is not the real width of content
            // otherwise, the cursor maybe cut or hide by the rect
            offset1 = VFX_MIN(offset1, rect.getWidth());
            if (point1)
            {
                offset2 = VFX_MIN(offset2, rect.getWidth());
            }
        }

        p.x = rect.getMinX() + offset1;
        p.y = rect.getMaxY() - getLineTextHeight(lineIndex) + 1;
        if (point1)
        {
            point1->x = rect.getMinX() + offset2;
            point1->y = rect.getMaxY() - getLineTextHeight(lineIndex) + 1;
        }
    }
    else
    {
        // used to calculate the cursor size (p.y)
        VfxS32 minHeight, ascent, descent;
       
        VcpRichTextFormat *curFormat = format;
        VfxS32 segStart = 0;
        VfxS32 segEnd = 0;
        VfxSize segTextSize;

        // get current system text direction
        vrt_text_dir_type_enum dir = vrt_sys_get_text_dir();

        // get line text direction
        VcpTextUtils tuDir(m_client);
        tuDir.setText(text);
        vrt_text_dir_type_enum textDir = tuDir.getTextDirection();

        VfxS32 posX = 0;
        if (textDir == MG_TEXT_DIR_TYPE_L2R)
        {
            posX = rect.origin.x;
        }
        else
        {
            posX = rect.origin.x + rect.getWidth() - 1;
        }

        // convert end to line index offset
        end -= start;
        while (segStart < end)
        {
            VcpTextUtils tu(m_client);
            if (curFormat == NULL || 
                (curFormat && segStart < curFormat->m_range.getStart()))
            {
                if (curFormat)
                {
                    segEnd = VFX_MIN(curFormat->m_range.getStart(), end);
                }
                else
                {
                    segEnd = end;
                }

                tu.setText(text + segStart, segEnd - segStart);

                // set y position to text position
                // when there are object and text on same line, the cursor height will change by the position
                // for example, Ot, O is object, t is text, when move cursor after O and t, the height will be different
                tu.setFont(m_font);
                VfxS32 segAdvW = 0;
                segTextSize = tu.getTextMetrics(
                    0,
                    (segEnd - segStart),
                    NULL,
                    -1,
                    NULL,
                    NULL,
                    NULL,
                    (VfxU8)m_wrapStyle,
                    VFX_TRUE,
                    &segAdvW);
                minHeight = tu.getTextHeightOfCommonLang(&m_font, &ascent, &descent);
                p.y = rect.getMaxY() - VFX_MAX(segTextSize.height, minHeight) + 1;

                // the index is not in this segment
                if (segEnd < index)
                {
                    // move to next segment by text direction
                    if (textDir == MG_TEXT_DIR_TYPE_R2L)
                    {
                        posX -= segAdvW;
                    }
                    else
                    {
                        posX += segAdvW;
                    }
                    p.x = posX;
                    segStart = segEnd;
                }
                else
                {
                    // found the pos
                    if (point1)
                    {
                        tu.getOffset(index - 1 - segStart, index - segStart, &offset1, &offset2);
                    }
                    else
                    {
                        tu.getOffset(index - 1 - segStart, index - segStart, &offset1, NULL);
                    }

                    if (textDir == MG_TEXT_DIR_TYPE_R2L)
                    {
                        p.x = posX - segAdvW + offset1;
                        if (point1)
                        {
                            point1->x = posX - segAdvW + offset2;
                        }
                    }
                    else
                    {
                        p.x = posX + offset1;
                        if (point1)
                        {
                            point1->x = posX + offset2;
                        }
                    }
                    if (point1)
                    {
                        point1->y = p.y;
                    }
                    break;
                }
            }
            else // in text format
            {
                segEnd = VFX_MIN(curFormat->m_range.getEnd(), end);

                // format object
                if (curFormat->getType() != VCP_RICH_TEXT_TYPE_TEXT &&
                    curFormat->getType() != VCP_RICH_TEXT_TYPE_HYPERLINK)
                {
                    VfxS32 formatWidth = curFormat->getSize().width;

                    // used to calculate the cursor size (p.y)
                    VfxS32 minHeight, ascent, descent;
                    VcpTextUtils tuTemp(m_client);
                    minHeight = tuTemp.getTextHeightOfCommonLang(&m_font, &ascent, &descent);
                    p.y = rect.getMaxY() - minHeight + 1;

                    if (index == segStart)
                    {
                        // found index, the index is before image
                        p.x = posX;
                        if (point1)
                        {
                            *point1 = p;
                        }
                        break;
                    }
                    else if (index == segEnd)
                    {
                        // found index, the index is after image
                        if (textDir == MG_TEXT_DIR_TYPE_R2L)
                        {
                            p.x = posX - formatWidth;
                        }
                        else
                        {
                            p.x = posX + formatWidth;
                        }
                        p.y = rect.getMinY();
                        if (point1)
                        {
                            *point1 = p;
                        }
                        break;
                    }
                    else
                    {
                        // move to next segment by text direction
                        if (textDir == MG_TEXT_DIR_TYPE_R2L)
                        {
                            posX -= formatWidth;
                        }
                        else
                        {
                            posX += formatWidth;
                        }
                        p.x = posX;
                        if (point1)
                        {
                            *point1 = p;
                        }
                        segStart = segEnd;
                    }
                }
                else // format text
                {
                    // found the pos
                    VfxFontDesc font;
                    if (((VcpRichText *)curFormat)->m_attrFlag & TEXT_FORMAT_ATTR_FONT)
                    {
                        font = ((VcpRichText *)curFormat)->m_font;
                    }
                    else
                    {
                        font = m_font;
                    }
                    tu.setFont(font);
                    tu.setText(text + segStart, segEnd - segStart);
                    VfxS32 segAdvW = 0;
                    segTextSize = tu.getTextMetrics(
                        0,
                        (segEnd - segStart),
                        NULL,
                        -1,
                        NULL,
                        NULL,
                        NULL,
                        (VfxU8)m_wrapStyle,
                        VFX_TRUE,
                        &segAdvW);

                    if (segEnd < index)
                    {
                        // the index is not in this segment
                        // move to next segment by text direction
                        if (textDir == MG_TEXT_DIR_TYPE_R2L)
                        {
                            posX -= segAdvW;
                        }
                        else
                        {
                            posX += segAdvW;
                        }
                        p.x = posX;
                        if (point1)
                        {
                            *point1 = p;
                        }
                        segStart = segEnd;
                    }
                    else
                    {
                        if (point1)
                        {
                            tu.getOffset(index - 1 - segStart, index - segStart, &offset1, &offset2);
                        }
                        else
                        {
                            tu.getOffset(index - 1 - segStart, index - segStart, &offset1, NULL);
                        }

                        // set y position to text position
                        minHeight = tu.getTextHeightOfCommonLang(&font, &ascent, &descent);
                        p.y = rect.getMaxY() - VFX_MAX(segTextSize.height, minHeight) + 1;

                        if (textDir == MG_TEXT_DIR_TYPE_R2L)
                        {
                            p.x = posX - segAdvW + offset1;
                            if (point1)
                            {
                                point1->x = posX - segAdvW + offset2;
                            }
                        }
                        else
                        {
                            p.x = posX + offset1;
                            if (point1)
                            {
                                point1->x = posX + offset2;
                            }
                        }
                        if (point1)
                        {
                            point1->y = p.y;
                        }
                        break;
                    }
                }

                // set current format to next format
                curFormat = curFormat->getNext();
            }
        }
    }

    // delete temp format
    m_storage->deleteRichTextFormat(format);

    VFX_FREE_MEM(temp_String);

    return p;
}


VfxS32 VcpTextBasicLayout::getIndexOfPos(VfxPoint curPos, VfxPoint *pos, VcpTextUtils *assignTu)
{
    VfxS32 lineIndex = getLineIndexByY(curPos.y);
    
    if (lineIndex >= getLineCount())
    {
        return m_storage->getTextLength();
    }
    else
    {
        return getIndexOfPos(lineIndex, curPos.x, pos, assignTu);
    }
}


VfxS32 VcpTextBasicLayout::getIndexOfPos(VfxS32 lineIndex, VfxS32 offset, VfxPoint *pos, VcpTextUtils *assignTu)
{
    VfxPoint p;
    VfxRect rect;
    const VfxWChar *text;
    VfxS32 lineCharCount = 0;
    VfxS32 index1 = 0, index2 = 0, newX = 0;
    
    if (getLineCount() == 0)
        return 0;

    rect = getLineBounds(lineIndex);
    text = getLineText(lineIndex, &lineCharCount);

    // get current system text direction
    vrt_text_dir_type_enum dir = vrt_sys_get_text_dir();
    // get line text direction
    VcpTextUtils tuDir(m_client);
    tuDir.setText(text);
    vrt_text_dir_type_enum textDir = tuDir.getTextDirection();

    // covnert screen offset to line offset
    VfxS32 offsetToLine = offset - rect.getMinX();

    VfxWChar *temp_String = NULL;

    // convert to mask characters
    if (m_isMask)
    {
        VFX_ALLOC_MEM(temp_String, (lineCharCount + 1) * sizeof(VfxWChar), m_client);

        VfxTextRange markRange = m_marked;
        VfxTextRange lineRange = VfxTextRange(getLineStart(lineIndex), getLineEnd(lineIndex));
        if (!(m_marked.isOutside(lineRange)))
        {
            markRange.limitTo(lineRange);
            markRange.shift(-getLineStart(lineIndex));
        }
        else
        {
            markRange.setRange(0, 0);
        }

        convertToMaskText(text, lineCharCount, temp_String, lineCharCount, markRange);

        text = temp_String;
    }

    VfxS32 start, end;
    start = getLineStart(lineIndex);
    end = start + lineCharCount;

    VcpRichTextFormat *format;
    format = m_storage->getRichTextFormat(start, end);
    if (format == NULL)     
    {
        // plain text
        if (assignTu)
        {
            assignTu->setText(text, lineCharCount);
            assignTu->setFont(m_font);
            assignTu->getIndex(offsetToLine, &index1, &index2, &newX);
        }
        else
        {
            VcpTextUtils tu(m_client);
            tu.setText(text, lineCharCount);
            tu.setFont(m_font);
            tu.getIndex(offsetToLine, &index1, &index2, &newX);
        }

        if (m_alignMode == ALIGN_MODE_RIGHT)
        {
            // if right alignment, the rect width is not the real width of content
            // otherwise, the cursor maybe cut or hide by the rect
            newX = VFX_MIN(newX, rect.getWidth());
        }

     //   if (textDir == MG_TEXT_DIR_TYPE_R2L)
        {
            // convert newX to screen position in R2L
            newX = newX + rect.getMinX();
        }
        if (pos)
        {
            pos->y = rect.getMaxY() - getLineTextHeight(lineIndex) + 1;
        }
    }
    else
    {
        // used to calculate the cursor size (p.y)
        VfxS32 minHeight, ascent, descent;
        VcpTextUtils tuTemp(m_client);
        minHeight = tuTemp.getTextHeightOfCommonLang(&m_font, &ascent, &descent);
        if (pos)
        {
            pos->y = rect.getMaxY() - minHeight + 1;
        }

        VfxS32 segOffsetEnd = rect.origin.x;
        if (dir == MG_TEXT_DIR_TYPE_L2R)
        {
            if (textDir == MG_TEXT_DIR_TYPE_L2R)
            {
                segOffsetEnd = rect.origin.x;
            }
            else
            {
                segOffsetEnd = rect.origin.x + rect.getWidth() - 1;
            }
        }
        else
        {
            if (textDir == MG_TEXT_DIR_TYPE_L2R)
            {
                segOffsetEnd = rect.origin.x;
            }
            else
            {
                segOffsetEnd = rect.origin.x + rect.getWidth() - 1;
            }
        }

        VcpRichTextFormat *curFormat = format;
        VfxS32 segStart = 0;
        VfxS32 segEnd = 0;
        VfxSize segTextSize;
        // convet to line end
        end = lineCharCount;
        while (segStart < end)
        {
            VcpTextUtils tu(m_client);
            if (curFormat == NULL || 
                (curFormat && segStart < curFormat->m_range.getStart()))
            {
                if (curFormat)
                {
                    segEnd = VFX_MIN(curFormat->m_range.getStart(), end);
                }
                else
                {
                    segEnd = end;
                }

                tu.setText(text + segStart, segEnd - segStart);

                VfxS32 segAdvW = 0;
                segTextSize = tu.getTextMetrics(
                        0,
                        (segEnd - segStart),
                        &m_font,
                        -1,
                        NULL,
                        NULL,
                        NULL,
                        (VfxU8)m_wrapStyle,
                        VFX_TRUE,
                        &segAdvW);
                
                minHeight = tu.getTextHeightOfCommonLang(&m_font, &ascent, &descent);

                if (textDir == MG_TEXT_DIR_TYPE_R2L)
                {
                    if (segOffsetEnd - segAdvW > offset)
                    {
                        // the offset is not in this segment
                        segOffsetEnd -= segAdvW;
                        segStart = segEnd;
                        newX = segOffsetEnd;
                        index1 = index2 = segEnd;
                        if (pos)
                        {
                            pos->y = rect.getMaxY() - VFX_MAX(segTextSize.height, minHeight) + 1;
                        }

                        // if next char is new line symbol, break it
                        if (FONT_TEST_NEW_LINE_CHAR(text[segEnd - 1]))
                        {
                            index1 = index2 = segEnd - 1;
                            break;
                        }
                    }
                    else
                    {
                        // found the pos
                        tu.setFont(m_font);
                        segOffsetEnd -= segAdvW;
                        tu.getIndex(offset - segOffsetEnd, &index1, &index2, &newX);
                        index1 += segStart;
                        index2 += segStart;
                        newX += segOffsetEnd;
                        if (index1 > segStart && pos)
                        {
                            pos->y = rect.getMaxY() - VFX_MAX(segTextSize.height, minHeight) + 1;
                        }
                        break;
                    }
                }
                else
                {
                    if (segOffsetEnd + segAdvW < offset)
                    {
                        // the offset is not in this segment
                        segOffsetEnd += segAdvW;
                        segStart = segEnd;
                        newX = segOffsetEnd;
                        index1 = index2 = segEnd;
                        if (pos)
                        {
                            pos->y = rect.getMaxY() - VFX_MAX(segTextSize.height, minHeight) + 1;
                        }

                        // if next char is new line symbol, break it
                        if (FONT_TEST_NEW_LINE_CHAR(text[segEnd - 1]))
                        {
                            index1 = index2 = segEnd - 1;
                            break;
                        }
                    }
                    else
                    {
                        // found the pos
                        tu.setFont(m_font);
                        tu.getIndex(offset - segOffsetEnd, &index1, &index2, &newX);
                        index1 += segStart;
                        index2 += segStart;
                        newX += segOffsetEnd;
                        if (index1 > segStart && pos)
                        {
                            pos->y = rect.getMaxY() - VFX_MAX(segTextSize.height, minHeight) + 1;
                        }
                        break;
                    }
                }
            }
            else // format
            {
                segEnd = VFX_MIN(curFormat->m_range.getEnd(), end);

                // format object
                if (curFormat->getType() != VCP_RICH_TEXT_TYPE_TEXT &&
                    curFormat->getType() != VCP_RICH_TEXT_TYPE_HYPERLINK)
                {
                    VfxS32 formatWidth = curFormat->getSize().width;

                    if (textDir == MG_TEXT_DIR_TYPE_R2L)
                    {
                        if ((offset > (segOffsetEnd - formatWidth)) &&
                            (offset <= segOffsetEnd - (formatWidth >>1)))
                        {
                            // the offset is at first half image
                            index1 = curFormat->m_range.getStart();
                            index2 = curFormat->m_range.getStart();
                            newX = segOffsetEnd - formatWidth;
                            break;
                        }
                        else if ((offset > segOffsetEnd - (formatWidth >>1)) &&
                                 (offset <= segOffsetEnd))
                        {
                            // the offset is at second half image
                            index1 = curFormat->m_range.getEnd();
                            index2 = curFormat->m_range.getEnd();
                            newX = segOffsetEnd;
                            if (pos)
                            {
                                pos->y = rect.getMinY();
                            }
                            break;
                        }
                        else
                        {
                            // go on to next segment
                            segOffsetEnd -= formatWidth;
                            segStart = segEnd;
                            newX = segOffsetEnd;
                            index1 = index2 = segEnd;
                            if (pos)
                            {
                                pos->y = rect.getMinY();
                            }
                        }
                    }
                    else
                    {
                        if ((offset <= segOffsetEnd) ||
                            ((offset > segOffsetEnd) && (offset <= segOffsetEnd + (formatWidth >>1))))
                        {
                            // the offset is at first half image
                            index1 = curFormat->m_range.getStart();
                            index2 = curFormat->m_range.getStart();
                            newX = segOffsetEnd;
                            break;
                        }
                        else if ((offset > segOffsetEnd + (formatWidth >>1)) && (offset <= segOffsetEnd + formatWidth))
                        {
                            // the offset is at second half image
                            index1 = curFormat->m_range.getEnd();
                            index2 = curFormat->m_range.getEnd();
                            newX = segOffsetEnd + formatWidth;
                            if (pos)
                            {
                                pos->y = rect.getMinY();
                            }
                            break;
                        }
                        else
                        {
                            // go on to next segment
                            segOffsetEnd += formatWidth;
                            segStart = segEnd;
                            newX = segOffsetEnd;
                            index1 = index2 = segEnd;
                            if (pos)
                            {
                                pos->y = rect.getMinY();
                            }

                            // if next char is new line symbol, break it
                            if (FONT_TEST_NEW_LINE_CHAR(text[segEnd]))
                            {
                                break;
                            }
                        }
                    }
                }
                else // format text
                {
                    tu.setText(text + segStart, segEnd - segStart);
                    VfxFontDesc font;
                    if (((VcpRichText*)curFormat)->m_attrFlag & TEXT_FORMAT_ATTR_FONT)
                    {
                        font = ((VcpRichText*)curFormat)->m_font;
                    }
                    else
                    {
                        font = m_font;
                    }
                    tu.setFont(font);
                    VfxS32 segAdvW = 0;
                    segTextSize = tu.getTextMetrics(
                            0,
                            (segEnd - segStart),
                            NULL,
                            -1,
                            NULL,
                            NULL,
                            NULL,
                            (VfxU8)m_wrapStyle,
                            VFX_TRUE,
                            &segAdvW);

                    if (textDir == MG_TEXT_DIR_TYPE_R2L)
                    {
                        if (segOffsetEnd - segAdvW > offset && offset >= 0)
                        {
                            // the offset is not in this segment
                            segOffsetEnd -= segAdvW;
                            segStart = segEnd;
                            index1 = index2 = segEnd;
                        }
                        else
                        {
                            // found the pos
                            segOffsetEnd -= segAdvW;
                            tu.getIndex(offset - segOffsetEnd, &index1, &index2, &newX);
                            index1 += segStart;
                            index2 += segStart;
                            newX += segOffsetEnd;

                            minHeight = tu.getTextHeightOfCommonLang(&font, &ascent, &descent);
                            if (pos)
                            {
                                pos->y = rect.getMaxY() - VFX_MAX(segTextSize.height, minHeight) + 1;
                            }
                            break;
                        }
                    }
                    else
                    {
                        if (segOffsetEnd + segAdvW < offset)
                        {
                            // the offset is not in this segment
                            segOffsetEnd += segAdvW;
                            segStart = segEnd;
                            index1 = index2 = segEnd;
                        }
                        else
                        {
                            // found the pos
                            tu.getIndex(offset - segOffsetEnd, &index1, &index2, &newX);
                            index1 += segStart;
                            index2 += segStart;
                            newX += segOffsetEnd;

                            minHeight = tu.getTextHeightOfCommonLang(&font, &ascent, &descent);
                            if (pos)
                            {
                                pos->y = rect.getMaxY() - VFX_MAX(segTextSize.height, minHeight) + 1;
                            }
                            break;
                        }
                    }
                }

                // set current format to next format
                curFormat = curFormat->getNext();
            }
        }
    }

    // delete temp format
    m_storage->deleteRichTextFormat(format);
    VFX_FREE_MEM(temp_String);

    // empty content
    if (pos)
    {
        if (m_storage->getTextLength() == 0)
        {
            VfxRect lineRect = getLineBounds(0);
            switch (m_alignMode)
            {
            case ALIGN_MODE_RIGHT:
                pos->x = m_layoutRect.getMaxX();
                break;
            case ALIGN_MODE_CENTER:
                pos->x = m_layoutRect.origin.x + m_layoutRect.getWidth() / 2;
                break;
            default:
                pos->x = m_layoutRect.getMinX();
                break;
            }
        }
        else
        {
            // convert line offset to screen offset
            if (textDir == MG_TEXT_DIR_TYPE_R2L)
            {
                pos->x = newX;
            }
            else
            {
                pos->x = newX;// + rect.getMinX();
            }
        }
    }
    
    return index1 + getLineStart(lineIndex);
}


VcpRichTextFormat *VcpTextBasicLayout::getObjectOfPos(const VfxPoint &point)
{
    VfxS32 lineIndex = getLineIndexByY(point.y);
    VfxS32 charLineIndex = 0;
    VfxPoint newPos;
    
    if (lineIndex >= getLineCount())
    {
        return NULL;
    }

    charLineIndex = getIndexOfPos(lineIndex, point.x, &newPos);

    VcpRichTextFormat *obj = m_storage->getRichTextFormat();
    while (obj)
    {
        if ((obj->m_range.getLength() == 0 && obj->m_range.getStart() == charLineIndex) ||
            (obj->m_range.getStart() <= charLineIndex) && (charLineIndex < obj->m_range.getEnd()))
        {
            return obj;
        }
        obj = obj->getNext();   
    }

    return NULL;
}


VcpRichTextFormat *VcpTextBasicLayout::getObjectOfIndex(VfxS32 index)
{
    VcpRichTextFormat *obj = m_storage->getRichTextFormat();
    while (obj)
    {
        if ((obj->m_range.getStart() <= index) && (index < obj->m_range.getEnd()))
        {
            return obj;
        }
        obj = obj->getNext();   
    }

    return NULL;
}


VfxBool VcpTextBasicLayout::isIndexAfterObject(VfxS32 index)
{
    VcpRichTextFormat *obj = m_storage->getRichTextFormat();
    while (obj)
    {
        if (index == obj->m_range.getEnd())
        {
            return VFX_TRUE;
        }
        obj = obj->getNext();   
    }

    return VFX_FALSE;
}


void VcpTextBasicLayout::setSelection(const VfxTextRange& selection)
{
    VfxTextRange notifySeletion;

    if (m_selection == selection ||
        (m_selection.getLength() == 0 && selection.getLength() == 0))
    {
        return;
    }
    else if (m_selection.getLength() == 0 && selection.getLength() != 0)
    {
        notifySeletion = selection;
    }
    else if (m_selection.getLength() != 0 && selection.getLength() == 0)
    {
        notifySeletion = m_selection;
    }
    else
    {
        notifySeletion.setStart(VFX_MIN(m_selection.getStart(), selection.getStart()));
        notifySeletion.setEnd(VFX_MAX(m_selection.getEnd(), selection.getEnd()));
    }

    // layout change notification to view that this range is invalid and need update for highlight
    VfxRect rectStart, rectEnd;
    rectStart = getLineBounds(getLineIndex(notifySeletion.getStart()));
    rectEnd = getLineBounds(getLineIndex(notifySeletion.getEnd()));
    rectStart.unionWith(rectEnd);

    rectStart.size.width += 2; // +2 for cursor area also need to update, otherwise the dirty area will not update

    m_signalSelectionChanged.postEmit(rectStart);
    //sendLayoutChangedNotification(rectStart, VFX_TRUE);
    m_selection = selection;
}


void VcpTextBasicLayout::setMarkedText(const VfxTextRange& marked) 
{
    VfxTextRange notifySeletion;

    if (m_marked == marked)
    {
        return;
    }
    else if (m_marked.getLength() == 0 && marked.getLength() != 0)
    {
        notifySeletion = marked;
    }
    else if (m_marked.getLength() != 0 && marked.getLength() == 0)
    {
        notifySeletion = m_marked;
    }
    else
    {
        notifySeletion.setStart(VFX_MIN(m_marked.getStart(), marked.getStart()));
        notifySeletion.setEnd(VFX_MAX(m_marked.getEnd(), marked.getEnd()));
    }

    // layout change notification to view that this range is invalid and need update for highlight
    VfxRect rectStart, rectEnd;
    rectStart = getLineBounds(getLineIndex(notifySeletion.getStart()));
    rectEnd = getLineBounds(getLineIndex(notifySeletion.getEnd()));
    rectStart.unionWith(rectEnd);
    
    sendLayoutChangedNotification(rectStart, VFX_TRUE);
    m_marked = marked;
}


void VcpTextBasicLayout::drawLineTextHilite(
    VfxDrawContext &dc, 
    VfxRect textRect,
    const VcpTextLine &line,
    const VfxWChar *text,
    VfxS32 segStart,
    VfxS32 segEnd,
    VfxFontDesc font,
    vrt_text_dir_type_enum dir)
{
    // Draw text highlight
    // Because for mix language (L2R, R2L), the highlight maybe in more than one block
    // so we draw the highlight with multiply blocks with following steps
    // 1. find nearby clusters and union the highlight rect
    // 2. if the next cluster is not connect with previous blocks, draw the previous highligh light
    // example ("abcdefgA"), draw highlight in (0 ~ 4), (abcdefg is L2R, A is R2L)
    // we need to draw two blocks, (abc) and (A)
    VfxTextRange segRange(segStart + line.m_start, segEnd + line.m_start);
    if (m_selection.getLength() > 0 && !m_selection.isOutside(segRange))
    {
        // compute line highlight start and line highlight end position
        VfxS32 highlightStart, highlightEnd;
        VcpTextUtils tu(m_client);
        VfxS32 lineStartX = 0;

        highlightStart = ((segStart > (m_selection.getStart() - line.m_start)) ? segStart : (m_selection.getStart() - line.m_start)) - segStart;
        highlightEnd = ((segEnd < (m_selection.getEnd() - line.m_start)) ? segEnd : (m_selection.getEnd() - line.m_start)) - segStart;
      
        if (dir == MG_TEXT_DIR_TYPE_R2L)
        {
            lineStartX = textRect.origin.x - textRect.getWidth() + 1;
        }
        else
        {
            lineStartX = textRect.origin.x;
        }

        tu.setText(text + segStart, (segEnd - segStart));
        tu.setFont(font);

        VcpTextMetrics *pMetrics;
        VcpTextMetrics *pMHiliteHead = NULL;
        VcpTextMetrics *pMHiliteTail = NULL;
        VfxRect highlightRect;
        VfxRect metricRect;
        for (VfxS32 mIndex = highlightStart; mIndex < highlightEnd;)
        {
            pMetrics = tu.getMetric(mIndex);

            if (pMetrics)
            {
                metricRect = VfxRect(
                    pMetrics->metrics.x + lineStartX,
                    textRect.getMaxY() - line.m_textHeight + 1,
                    pMetrics->metrics.adv_w,
                    line.m_textHeight);

                if (!(pMHiliteHead == NULL && pMHiliteTail == NULL))
                {
                    // check if connect with tail
                    if (pMHiliteTail && pMHiliteTail->getNext() == pMetrics)
                    {
                        highlightRect.unionWith(metricRect);
                        pMHiliteTail = pMetrics;
                    }
                    else if (pMetrics->getNext() == pMHiliteHead)
                    {
                        // check if connect with head
                        highlightRect.unionWith(metricRect);
                        pMHiliteHead = pMetrics;
                    }
                    else
                    {
                        // draw this block
                    #if defined(__COSMOS_MMI_PACKAGE__)
                        // limit highilght image rect within image max width
                        // we use two screen width as max highlight image width
                        vrt_size_struct mainScreenSize;
                        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
                        VfxRect rectValid(-mainScreenSize.width / 2, highlightRect.origin.y, mainScreenSize.width * 2,  highlightRect.size.height);
                        highlightRect.intersectWith(rectValid);

                        dc.drawResizedImageFromRes(highlightRect, VCP_IMG_TEXT_HLT_BG);
                    #else
                        dc.setFillColor(VFX_COLOR_GREEN);
                        dc.fillRect(highlightRect);
                    #endif
                        highlightRect = metricRect;
                        pMHiliteHead = pMHiliteTail = pMetrics;
                    }
                }
                else
                {
                    highlightRect = metricRect;
                    pMHiliteHead = pMHiliteTail = pMetrics;
                }
                mIndex += pMetrics->metrics.len;
            }
            else
            {
                mIndex++;
            }
        }

        if (!highlightRect.isEmpty())
        {     
        #if defined(__COSMOS_MMI_PACKAGE__)
            // limit highilght image rect within image max width
            // we use two screen width as max highlight image width
            vrt_size_struct mainScreenSize;
            vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
            VfxRect rectValid(-mainScreenSize.width / 2, highlightRect.origin.y, mainScreenSize.width * 2,  highlightRect.size.height);
            highlightRect.intersectWith(rectValid);

            dc.drawResizedImageFromRes(highlightRect, VCP_IMG_TEXT_HLT_BG);
        #else
            dc.setFillColor(VFX_COLOR_GREEN);
            dc.fillRect(highlightRect);
        #endif
        }
    }
}


void VcpTextBasicLayout::drawLineText(
    VfxDrawContext &dc, 
    VfxRect textRect,
    const VcpTextLine &line,
    const VfxWChar *text,
    VfxS32 count,
    VcpRichTextFormat *format,
    VfxBool isDrawHilite)
{
    VfxS32 truncateStrWidth = 0;
    if (line.m_isTruncated)
    {
        truncateStrWidth = m_font.measureStr(VFX_WSTR("...")).width;
    }

    if (format == NULL)
    {
        if (isDrawHilite)
        {
            drawLineTextHilite(dc, textRect, line, text, 0, (line.m_end - line.m_start), m_font, vrt_sys_get_text_dir());
            return;
        }
        else
        {
            applyTextFormat(dc);
            if (line.m_isTruncated)
            {
                // if the rect not enough to draw the truncate, draw the truncate text directly
                if (textRect.getWidth() < truncateStrWidth)
                {
                    textRect.size.width = truncateStrWidth;
                    dc.drawTextBaseline(textRect, line.m_baseLine, VFX_WSTR("..."), 3);
                    return;
                }
                else
                {
                    dc.setEllipsis(VFX_WSTR("...")); 
                    dc.drawTextTruncatedBaseline(
                        textRect,
                        text,
                        VFX_MIN(textRect.getWidth(), m_layoutRect.getWidth()) - 1, // -1 to make the width not enough to show all line text then it will draw "..."
                        line.m_baseLine);
                }
            }
            else
            {
                dc.drawTextBaseline(textRect, line.m_baseLine, text, count);
            }
        }
    }
    else
    {
        // draw rich text line
        // draw text segment by text format
        VfxS32 segStart = 0;
        VfxS32 segEnd = 0;
        VcpRichTextFormat *curFormat = format;
        VfxRect segTextRect = textRect;
        vrt_text_dir_type_enum dir = vrt_sys_get_text_dir();

        // get line text direction
        VcpTextUtils tuDir(m_client);
        tuDir.setText(text);
        vrt_text_dir_type_enum textDir = tuDir.getTextDirection();

        if (dir == MG_TEXT_DIR_TYPE_R2L && textDir == MG_TEXT_DIR_TYPE_L2R)
        {
            segTextRect.origin.x = textRect.origin.x - textRect.getWidth() + 1;
        }
        else if (dir == MG_TEXT_DIR_TYPE_L2R && textDir == MG_TEXT_DIR_TYPE_R2L)
        {
            segTextRect.origin.x = textRect.origin.x + textRect.getWidth() - 1;
        }

        if ((count == 0) && curFormat &&
            curFormat->getType() != VCP_RICH_TEXT_TYPE_TEXT &&
            curFormat->getType() != VCP_RICH_TEXT_TYPE_HYPERLINK)
        {
            // draw image
            VfxPoint p;
            VfxSize formatSize;
            formatSize = curFormat->getSize();
            p.x = segTextRect.origin.x;
            p.y = segTextRect.getMaxY() - formatSize.height;
            curFormat->draw(dc, p);
            return;
        }

        // used for check if need to truncate
        VfxS32 remainingWidth = textRect.getWidth();
        VfxBool isEnd = VFX_FALSE;
        while (segStart < count && !isEnd && remainingWidth > 0)
        {
            if (curFormat == NULL || 
               (curFormat && segStart < curFormat->m_range.getStart()) /*||
               (curFormat && !(curFormat->m_attrFlag & TEXT_FORMAT_ATTR_IMAGE))*/)
            {
                if (curFormat)
                {
                    segEnd = VFX_MIN(curFormat->m_range.getStart(), count);
                }
                else
                {
                    segEnd = count;
                }

                // default normal format
                applyTextFormat(dc);
                
                // update text rect
                VcpTextUtils tu(m_client);
                VfxSize textSize;
                VfxS32 segAdvW;
                tu.setText(text);
                textSize = tu.getTextMetrics(
                    segStart,
                    (segEnd - segStart),
                    &m_font,
                    -1,
                    NULL,
                    NULL,
                    NULL,
                    (VfxU8)m_wrapStyle,
                    VFX_TRUE,
                    &segAdvW);

                segTextRect.size.width = textSize.width;
                segTextRect.size.height = textRect.getHeight();

                // save orginX for draw highlight
                VfxRect savedOrgRect = segTextRect;
                // used for draw
                VfxRect drawSegRect = segTextRect;

                // draw text without text format from segStart to segEnd, using default text format
                if (dir == MG_TEXT_DIR_TYPE_L2R)
                {
                    if (textDir == MG_TEXT_DIR_TYPE_R2L)
                    {
                        segTextRect.origin.x -= segAdvW;
                        drawSegRect = segTextRect;
                        if (line.m_isTruncated && (remainingWidth < segTextRect.size.width))
                        {
                            drawSegRect.origin.x += (segTextRect.size.width - remainingWidth);
                        }
                    }
                    else
                    {
                        segTextRect.origin.x += segAdvW;
                    }
                }
                else
                {
                    if (textDir == MG_TEXT_DIR_TYPE_L2R)
                    {
                        segTextRect.origin.x += segAdvW;
                        drawSegRect = segTextRect;
                        if (line.m_isTruncated && (remainingWidth < segTextRect.size.width))
                        {
                            drawSegRect.origin.x -= (segTextRect.size.width - remainingWidth);
                        }
                    }
                    else
                    {
                        segTextRect.origin.x -= segAdvW;
                    }
                }

                if (isDrawHilite)
                {
                    drawLineTextHilite(dc, savedOrgRect, line, text, segStart, segEnd, m_font, textDir);
                }

                if (line.m_isTruncated && ((remainingWidth - segTextRect.size.width) < truncateStrWidth))
                {
                    if (!isDrawHilite)
                    {
                        dc.setEllipsis(VFX_WSTR("..."));
                        dc.drawTextTruncatedBaseline(drawSegRect, (text + segStart), remainingWidth - 1, line.m_baseLine);
                    }
                    isEnd = VFX_TRUE;
                }
                else
                {
                    if (!isDrawHilite)
                    {
                        dc.drawTextBaseline(drawSegRect, line.m_baseLine, (text + segStart), (segEnd - segStart));
                    }
                }

                remainingWidth -= segAdvW;
            }
            else
            {
                if (curFormat->getType() != VCP_RICH_TEXT_TYPE_TEXT &&
                    curFormat->getType() != VCP_RICH_TEXT_TYPE_HYPERLINK)
                {
                    // draw image
                    VfxPoint p;
                    VfxSize formatSize;
                    formatSize = curFormat->getSize();

                    if (line.m_isTruncated && ((remainingWidth - formatSize.width) < truncateStrWidth))
                    {
                        if (!isDrawHilite)
                        {
                            if (dir == MG_TEXT_DIR_TYPE_R2L)
                            {
                                if (textDir == MG_TEXT_DIR_TYPE_L2R)
                                {
                                    segTextRect.origin.x += truncateStrWidth;
                                }
                            }
                            else
                            {
                                if (dir == MG_TEXT_DIR_TYPE_R2L)
                                {
                                    segTextRect.origin.x -= truncateStrWidth;
                                }
                            }
                            applyTextFormat(dc);
                            if (line.m_baseLine == textRect.getHeight())
                            {
                                // the whole line is image, -5 to avoid the "..." position is too low with the image
                                dc.drawTextBaseline(segTextRect, line.m_baseLine - 5, VFX_WSTR("..."), 3);
                            }
                            else
                            {
                                dc.drawTextBaseline(segTextRect, line.m_baseLine, VFX_WSTR("..."), 3);
                            }
                        }
                        isEnd = VFX_TRUE;
                    }
                    else
                    {
                        if (textDir == MG_TEXT_DIR_TYPE_R2L)
                        {
                            segTextRect.origin.x -= formatSize.width;
                            p.x = segTextRect.origin.x;
                        }
                        else
                        {
                            p.x = segTextRect.origin.x;
                            segTextRect.origin.x += formatSize.width;
                        }

                        p.y = segTextRect.getMaxY() - formatSize.height + 1;

                        if (isDrawHilite)
                        {
                            VfxTextRange segRange(curFormat->m_range.getStart() + line.m_start, curFormat->m_range.getEnd() + line.m_start);
                            if (m_selection.getLength() > 0 && !m_selection.isOutside(segRange))
                            {
                                VfxRect highlightRect(
                                    p.x,
                                    textRect.getMaxY() - line.m_textHeight + 1,
                                    formatSize.width,
                                    line.m_textHeight);
                            #if !defined(__COSMOS_MMI_PACKAGE__)
                                dc.setFillColor(VFX_COLOR_GREEN);
                                dc.fillRect(highlightRect);
                            #else
                                dc.drawResizedImageFromRes(highlightRect, VCP_IMG_TEXT_HLT_BG);
                            #endif
                            }
                        }
                        else
                        {
                            curFormat->draw(dc, p);
                        }
                    }

                    segEnd = curFormat->m_range.getEnd();
                    remainingWidth -= formatSize.width;
                }
                else
                {
                    // draw text under this text format
                    segEnd = VFX_MIN(curFormat->m_range.getEnd(), count);

                    VfxFontDesc segFont;
                    if (((VcpRichText*)curFormat)->m_attrFlag & TEXT_FORMAT_ATTR_FONT)
                    {
                        segFont = ((VcpRichText*)curFormat)->m_font;
                    }
                    else
                    {
                        segFont = m_font;
                    }
                    applyTextFormat(dc, curFormat);

                    // update text rect
                    VcpTextUtils tu(m_client);
                    VfxSize textSize;
                    VfxS32 segAdvW;
                    tu.setText(text);
                    textSize = tu.getTextMetrics(
                        segStart,
                        (segEnd - segStart),
                        &segFont,
                        -1,
                        NULL,
                        NULL,
                        NULL,
                        (VfxU8)m_wrapStyle,
                        VFX_TRUE,
                        &segAdvW);
                    segTextRect.size.width = textSize.width;
                    segTextRect.size.height = textRect.getHeight();

                    // save orginX for draw highlight because it will change after draw text
                    VfxRect savedOrgRect = segTextRect;

                    // used for draw
                    VfxRect drawSegRect = segTextRect;

                    // draw text background
                    if (((VcpRichText*)curFormat)->m_attrFlag & TEXT_FORMAT_ATTR_BG_COLOR && !isDrawHilite)
                    {
                        VfxRect hiliteRect = segTextRect;
                        // to make the bg color filler not to close to the character boundary.
                        hiliteRect.size.width += 1;
                        if (textDir == MG_TEXT_DIR_TYPE_R2L)
                        {
                            hiliteRect.origin.x = segTextRect.origin.x - hiliteRect.getWidth() + 1;
                        }
                        dc.setFillColor(((VcpRichText*)curFormat)->m_textBgColor);
                        dc.fillRect(hiliteRect);
                        
                        // need to reset text format because the fill color is changed
                        applyTextFormat(dc, curFormat);
                    }

                    // draw text with text format from segStart to segEnd
                    if (dir == MG_TEXT_DIR_TYPE_L2R)
                    {
                        if (textDir == MG_TEXT_DIR_TYPE_R2L)
                        {
                            segTextRect.origin.x -= segAdvW;
                            drawSegRect = segTextRect;
                            if (line.m_isTruncated && (remainingWidth < segTextRect.size.width))
                            {
                                drawSegRect.origin.x += (segTextRect.size.width - remainingWidth);
                            }
                        }
                        else
                        {
                            segTextRect.origin.x += segAdvW;
                        }
                    }
                    else
                    {
                        if (textDir == MG_TEXT_DIR_TYPE_L2R)
                        {
                            VfxS32 saveOrgX = segTextRect.origin.x;
                            // use seg width to draw text
                            segTextRect.origin.x += textSize.width - 1;
                            drawSegRect = segTextRect;
                            if (line.m_isTruncated && (remainingWidth < segTextRect.size.width))
                            {
                                drawSegRect.origin.x -= (segTextRect.size.width - remainingWidth);
                            }
                            // use seg adv width to move to next segment
                            segTextRect.origin.x = saveOrgX + segAdvW - 1;
                        }
                        else
                        {
                            segTextRect.origin.x -= segAdvW;
                        }
                    }

                    if (isDrawHilite)
                    {
                        drawLineTextHilite(dc, savedOrgRect, line, text, segStart, segEnd, segFont, textDir);
                    }
                    // need to reset text format because the fill color is changed
                    applyTextFormat(dc, curFormat);
                    if (line.m_isTruncated && ((remainingWidth - segTextRect.size.width) < truncateStrWidth))
                    {
                        if (!isDrawHilite)
                        {
                            dc.setEllipsis(VFX_WSTR("..."));
                            dc.drawTextTruncatedBaseline(drawSegRect, (text + segStart), remainingWidth - 1, line.m_baseLine);
                        }
                        isEnd = VFX_TRUE;
                    }
                    else
                    {
                        if (!isDrawHilite)
                        {
                            dc.drawTextBaseline(drawSegRect, line.m_baseLine, (text + segStart), (segEnd - segStart));
                        }
                    }

                    remainingWidth -= segAdvW;
                }
                // set current format to next format
                curFormat = curFormat->getNext();
            }

            segStart = segEnd;
        }
    }
}


VfxBool VcpTextBasicLayout::decFontSize()
{
    VcpRichTextFormat *format = m_storage->getRichTextFormat();
    VfxBool ret = VFX_TRUE;

    if (format)
    {
        // default font size
        if (m_font.size > VCP_TEXT_MIN_FONT_SIZE)
        {
            m_font.size--;
            ret = VFX_TRUE;
        }
        else
        {
            ret = VFX_FALSE;
        }

        while (format)
        {
            if (format->getType() == VCP_RICH_TEXT_TYPE_TEXT ||
                format->getType() == VCP_RICH_TEXT_TYPE_HYPERLINK)
            {
                if (((VcpRichText*)format)->m_font.size > VCP_TEXT_MIN_FONT_SIZE)
                {
                    ((VcpRichText*)format)->m_font.size--;
                    ret = VFX_TRUE;
                }
            }

            format = format->getNext();
        }
    }
    else
    {
        // use default
        if (m_font.size > VCP_TEXT_MIN_FONT_SIZE)
        {
            m_font.size--;
            ret = VFX_TRUE;
        }
        else
        {
            ret = VFX_FALSE;
        }
    }

    if (ret)
    {
        checkUpdate();
    }

    return ret;
}


VfxBool VcpTextBasicLayout::incFontSize()
{
    VcpRichTextFormat *format = m_storage->getRichTextFormat();
    VfxBool ret = VFX_TRUE;

    if (format)
    {
        // default original font size
        if (m_font.size < m_orgFontSize)
        {
            m_font.size++;
            ret = VFX_TRUE;
        }
        else
        {
            ret = VFX_FALSE;
        }

        while (format)
        {
            if (format->getType() == VCP_RICH_TEXT_TYPE_TEXT ||
                format->getType() == VCP_RICH_TEXT_TYPE_HYPERLINK)
            {
                if (((VcpRichText*)format)->m_font.size < m_orgFontSize)
                {
                    ((VcpRichText*)format)->m_font.size++;
                    ret = VFX_TRUE;
                }
            }

            format = format->getNext();
        }
    }
    else
    {
        // use default
        if (m_font.size < m_orgFontSize)
        {
            m_font.size++;
            ret = VFX_TRUE;
        }
        else
        {
            ret = VFX_FALSE;
        }
    }

    if (ret)
    {
        checkUpdate();
    }

    return ret;
}


VcpTextBasicLayout::AlignModeEnum VcpTextBasicLayout::getAlignment()
{
    AlignModeEnum alignMode = m_alignMode;
    vrt_text_dir_type_enum textDir = m_direction;
    vrt_text_dir_type_enum dir = vrt_sys_get_text_dir();

    if (textDir == MG_TEXT_DIR_TYPE_R2L)
    {
        dir = MG_TEXT_DIR_TYPE_R2L;
    }

    dir = textDir;
    if (alignMode == ALIGN_MODE_NATURAL)
    {
        switch (dir)
        {
            case MG_TEXT_DIR_TYPE_L2R:
                alignMode = ALIGN_MODE_LEFT;
                break;
                    
            case MG_TEXT_DIR_TYPE_R2L:
                alignMode = ALIGN_MODE_RIGHT;
                break;
                    
            default:
                VFX_ASSERT(0);
        };
    }    

    return alignMode;
}


void VcpTextBasicLayout::forceLayout(VfxBool isAsync)
{
    // update layout immediately
    m_dirty.setRange(0, m_storage->getTextLength());
    m_changedCharCount = 0;
    m_checkUpdate = VFX_TRUE;
    updateLayout(isAsync);
}


void VcpTextBasicLayout::convertToMaskText(const VfxWChar *src, VfxS32 srcLen, VfxWChar *dest, VfxS32 destLen, VfxTextRange markRange)
{
    // convert to mask characters
    if (m_isMask)
    {
        VfxS32 i = 0, j = 0;

        dest[srcLen] = 0;

        if (markRange.getLength() == 0)
        {
            for (i = 0; i < srcLen; i++)
            {
                dest[i] = VCP_TEXT_MASK_CHARACTER;
            }
        }
        else
        {
            for (i = 0; i < markRange.getStart(); i++)
            {
                dest[i] = VCP_TEXT_MASK_CHARACTER;
            }
            for (j = 0; j < markRange.getLength(); j++)
            {
                dest[i] = src[i];
                i++;
            }
            for (; i < srcLen; i++)
            {
                dest[i] = VCP_TEXT_MASK_CHARACTER;
            }
        }
    }
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

/***************************************************************************** 
 * Class VcpTextStaticLayout
 *****************************************************************************/
VcpTextStaticLayout::VcpTextStaticLayout(IVfxAllocatable* client)
{
    m_client = client;
    VFX_ALLOC_NEW_EX(m_lineBlock, VcpTextLineBlock, client, (client));
    m_lineTailBlock = m_lineBlock;
    m_lineCount = 0;
    m_blockNum = 1;
    m_cacheLineBlockIndex = -1;
    m_cacheLineBlock = NULL;
}


VcpTextStaticLayout::~VcpTextStaticLayout()
{
    deleteLines();
}


void VcpTextStaticLayout::deleteLines()
{
    m_lineCount = 0;
    m_blockNum = 0;

    VcpTextLineBlock *block = m_lineBlock;
    while (block)
    {
        block = block->m_next;
        VFX_DELETE(m_lineBlock);
        m_lineBlock = block;
    }
    m_lineTailBlock = NULL;
}


void VcpTextStaticLayout::layoutDirtyRange(VfxTimer *source)
{
    if (m_layoutTimer)
    {
        m_layoutTimer->stop();
    }
    
    if (m_dirty.getLength() == 0)
    {
        return;
    }

    layout(m_dirty.getStart(), m_dirty.getEnd(), 0);
}


VcpTextLine *VcpTextStaticLayout::getLine(VfxS32 line)
{
    if (m_dirty.getLength() > 0)
    {
        m_cacheLineBlockIndex = -1;
        m_cacheLineBlock = NULL;
    }

    VcpTextLineBlock *block = m_lineBlock;
    VfxU32 i = 0;

    if (line >= m_lineCount)
    {
        line = m_lineCount - 1;
    }

    if (line < 0)
    {
        line = 0;
    }

    // get block index
    VfxU32 blockIndex = line / VCP_MAX_TEXT_LINES;

    // if cached line before, find from cached line
    if (m_cacheLineBlockIndex != -1 && m_cacheLineBlock)
    {
        if (blockIndex == m_cacheLineBlockIndex)
        {
            return (VcpTextLine *)&(m_cacheLineBlock->m_header[line - (blockIndex * VCP_MAX_TEXT_LINES)]);
        }
        else if (blockIndex > (VfxU32)m_cacheLineBlockIndex)
        {
            i = m_cacheLineBlockIndex;
            block = m_cacheLineBlock;
        }
    }

    while (block)
    {
        if (i == blockIndex)
        {
            break;
        }
        block = block->m_next;
        i++;
    }

    // __SLIM_TODO__ block can't be NULL, Remove the check
    //if (block)
    //{
        // save cache when layout already done
        if (m_dirty.getLength() == 0)
        {
            m_cacheLineBlockIndex = blockIndex;
            m_cacheLineBlock = block;
        }
    
        return (VcpTextLine *)&(block->m_header[line - (blockIndex * VCP_MAX_TEXT_LINES)]);
    //}
    //else
    //{
      //  return NULL;
   // }
}


void VcpTextStaticLayout::addLine(VcpTextLine &line)
{
    // get block index
    VcpTextLine *pLine;

    if (m_lineCount <= 0)
    {
        deleteLines();
    }

    if ((m_lineCount % VCP_MAX_TEXT_LINES) == 0)
    {
        // alloc new link block
        VcpTextLineBlock *newBlock;
        VFX_ALLOC_NEW_EX(newBlock, VcpTextLineBlock, m_client, (m_client));

        // add to line block list
        if (m_lineTailBlock)
        {
            m_lineTailBlock->m_next = newBlock;
            m_lineTailBlock = newBlock;
        }
        else
        {
            m_lineBlock = m_lineTailBlock = newBlock;
        }
        m_blockNum++;
    }

    m_lineCount++;
    pLine = getLine(m_lineCount);
    *pLine = line;
}


VfxS32 VcpTextStaticLayout::getLineStart(VfxS32 line)
{
    // get block index
    VcpTextLine *pLine;
    pLine = getLine(line);
    return pLine->m_start;
}


VfxS32 VcpTextStaticLayout::getLineEnd(VfxS32 line)
{
    // get block index
    VcpTextLine *pLine;
    pLine = getLine(line);
    return pLine->m_end;
}


const VfxRect& VcpTextStaticLayout::getLineBounds(VfxS32 line)
{
    return getLine(line)->m_rect;
}


VfxS32 VcpTextStaticLayout::getLineBaseLine(VfxS32 line)
{
    return getLine(line)->m_baseLine;
}


VfxS32 VcpTextStaticLayout::getLineTextHeight(VfxS32 line)
{
    return getLine(line)->m_textHeight;
}


void VcpTextStaticLayout::drawLine(VfxS32 line, VfxDrawContext &dc, const VfxRect &area, VfxPoint offsetToDC, VfxBool isDrawHilite)
{
    VcpRichTextFormat *textFormat = NULL;

    // first line is custom frame
    textFormat = m_storage->getRichTextFormat();
    if (line == 0 && textFormat && textFormat->getType() == VCP_RICH_TEXT_TYPE_CUSTOM_FRAME &&
        textFormat->m_range.getStart() == 0 && textFormat->isOccopyOneLine())
    {
        return;
    }

    VcpTextLine *pLine = getLine(line);
    VfxS32 count = pLine->m_end - pLine->m_start;

    // draw line underline
    if (m_isUnderline && !isDrawHilite)
    {
        VfxS32 baseline = pLine->m_baseLine;
        // for custom frame, the baseline maybe -1, so we use custom frame height to draw underline
        // only draw underline after text line (Don't draw under line for first custom frame line before text)
        if (count == 0)
        {
            baseline = pLine->m_rect.size.height;
        }

        // draw underline
        dc.setStrokeColor(m_underlineColor);
        VfxS32 baselineGap = VCP_TEXT_BASELINE_GAP;
        if (baseline == pLine->m_rect.getHeight())
        {
            baselineGap = 0;
        }
        dc.drawLine(
            m_layoutRect.getMinX() + offsetToDC.x,
            pLine->m_rect.getMinY() + baseline + offsetToDC.y - 1 + baselineGap,
            m_layoutRect.getMaxX() + offsetToDC.x,
            pLine->m_rect.getMinY() + baseline + offsetToDC.y - 1 + baselineGap);
    }

    // Get text from textstorage
    const VfxWChar* s = NULL;
    VfxS32 len = 0;
    m_storage->getText(&s, &len);

    // Get text format from textstorage
    if (pLine->m_start == pLine->m_end)
    {
        textFormat = m_storage->getRichTextFormat(pLine->m_start, pLine->m_end);
    }
    else
    {
        VcpRichTextFormat *temFormat;
        temFormat = m_storage->getRichTextFormat(pLine->m_start);
        if (temFormat && temFormat->isOccopyOneLine())
        {
            temFormat = temFormat->getNext();
        }
        textFormat = m_storage->getRichTextFormat(temFormat, pLine->m_start, pLine->m_end);
    }

    VfxWChar *temp_String = NULL;
    if (pLine->m_start >= 0 && pLine->m_end >= 0)
    {
        s = (VfxWChar*)s + pLine->m_start;
        VFX_ALLOC_MEM(temp_String, (count + 1) * sizeof(VfxWChar), m_client);
        memcpy(temp_String, s, count*sizeof(VfxWChar));
        temp_String[count] = 0;
        s = temp_String;
    }

    VfxRect textRect = pLine->m_rect;
    vrt_text_dir_type_enum dir = vrt_sys_get_text_dir();
    if (dir == MG_TEXT_DIR_TYPE_L2R)
    {
        textRect.origin.x += offsetToDC.x;
    }
    else
    {   
        textRect.origin.x += (pLine->m_rect.size.width - 1 + offsetToDC.x);
    }
    textRect.origin.y += offsetToDC.y;
    drawLineText(dc, textRect, *pLine, s, count, textFormat, isDrawHilite);

    // free format object memory
    m_storage->deleteRichTextFormat(textFormat);
    VFX_FREE_MEM(temp_String);
}


void VcpTextStaticLayout::layout(VfxS32 start, VfxS32 end, VfxS32 changedCharCount)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TL2", SA_start);
#endif
    const VfxWChar* s = NULL;
    VfxS32 len = 0;
    VfxRect layoutRect;
    VcpTextUtils tuTemp(m_client);
    VfxS32 minHeight, ascent, descent;
    minHeight = tuTemp.getTextHeightOfCommonLang(&m_font, &ascent, &descent);
    vrt_text_dir_type_enum dir = vrt_sys_get_text_dir();
    AlignModeEnum alignMode = m_alignMode;
    VfxS32 offsetIndex = start, offsetY = m_lineGap;
    VcpRichTextFormat *format;

    // clear cache
    m_cacheLineBlockIndex = -1;
    m_cacheLineBlock = NULL;

    // Get text from textstorage
    m_storage->getText(&s, &len);

    VcpRichTextFormat *currObj = m_storage->getRichTextFormat();

    if (s == NULL)
    {
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TL2", SA_stop);
    #endif
        return;
    }

    // Empty string
    if (*s == 0 && (currObj == NULL))
    {
        m_lineBlock->m_header[0].m_rect = VfxRect(m_layoutRect.getMinX(), 0, m_layoutRect.getWidth(), VFX_MAX(minHeight, m_minLineHeight));
        if (m_minLineHeight > minHeight)
        {
            m_lineBlock->m_header[0].m_baseLine = ascent + (m_minLineHeight - minHeight);
        }
        else
        {
            m_lineBlock->m_header[0].m_baseLine = ascent;
        }
        m_lineBlock->m_header[0].m_start = 0;
        m_lineBlock->m_header[0].m_end = 0;
        m_lineBlock->m_header[0].m_textHeight = minHeight;
        m_lineCount = 1;
        sendLayoutChangedNotification(m_lineBlock->m_header[0].m_rect);
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TL2", SA_stop);
    #endif
        return;
    }
    else if (start == 0)
    {
        m_lineCount = 0;

        // hide all custom frame before layout to avoid the custom frame flash in wrong position
        VcpRichTextFormat *custFrame = currObj;
        while (custFrame)
        {
            if (custFrame->getType() == VCP_RICH_TEXT_TYPE_CUSTOM_FRAME)
            {
                VfxFrame *cFrame = ((VcpRichTextCustomFrame *)custFrame)->getFrame();
                if (cFrame)
                {
                    cFrame->setHidden(VFX_TRUE);
                }
            }
            custFrame = custFrame->getNext();
        }
    }
    else
    {
        if ((m_maxLineNum > 0) && (m_lineCount >= m_maxLineNum))
        {
        #ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("TL2", SA_stop);
        #endif
            return;
        }

        // get previous line y position
        VfxRect lastLineRect = getLineBounds(m_lineCount - 1);
        offsetY = lastLineRect.getMaxY();
    }
    
    // No affect area, don't layout
    if (start == end && (currObj == NULL))
    {
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TL2", SA_stop);
    #endif
        return;
    }

    // get text direction
    if (start == 0)
    {
        VcpTextUtils tuDir(m_client);
        tuDir.setText(s, NULL);
        m_direction = tuDir.getTextDirection();
    }

    if (m_direction == MG_TEXT_DIR_TYPE_R2L)
    {
        dir = MG_TEXT_DIR_TYPE_R2L;
    }
    alignMode = getAlignment();

    // calc the layout char number each time
    // first layout VCP_MAX_LAYOUT_CHARS chars
    // calc the rest chars by charPerLine * layoutLineCnt
    VfxS32 layoutCharCount = 0;
    if (start == 0)
    {
        layoutCharCount = VCP_MAX_LAYOUT_CHARS;
    }
    else
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
        VfxS32 charPerLine = m_layoutRect.getWidth() / VCP_TEXT_MIN_CHAR_WIDTH;
        VfxS32 layoutLineCnt = VFX_MIN(m_layoutRect.getHeight(), mainScreenSize.height) / VFX_MAX(minHeight, m_minLineHeight) + 2;
        layoutCharCount = charPerLine * layoutLineCnt;
        layoutCharCount = VFX_MAX(layoutCharCount, VCP_MIN_LAYOUT_CHARS);
    }

    // is current line is stand alone custom frame line
    VcpRichTextFormat *standAloneObject = NULL;
    VfxS32 layoutedLineCount = 0;
    while (offsetIndex < end)
    {
        standAloneObject = NULL;

        VcpTextLine newLine;
        VfxS32 lineCount;
        VfxS32 baseline;
        VcpTextUtils tu(m_client);
        AlignModeEnum lineAlign = alignMode;

        tu.setText(s + offsetIndex);

        format = m_storage->getRichTextFormat(currObj, offsetIndex, end);

        minHeight = tuTemp.getTextHeightOfCommonLang(&m_font, &ascent, &descent);

        // use format font as the mini line height, currently we only check the 
        // first format object
        if (format && (format->getType() == VCP_RICH_TEXT_TYPE_TEXT || format->getType() == VCP_RICH_TEXT_TYPE_HYPERLINK))
        {
            if (((VcpRichText *)format)->m_attrFlag & TEXT_FORMAT_ATTR_FONT)
            {
                minHeight = tuTemp.getTextHeightOfCommonLang(&(((VcpRichText*)format)->m_font), &ascent, &descent);
            }
        }

        // set the line bounds
        newLine.m_start = newLine.m_end = offsetIndex;
        newLine.m_rect.origin.x = m_layoutRect.getX();
        newLine.m_rect.origin.y = offsetY;

        if (offsetIndex == 0)
        {
            layoutRect.origin = newLine.m_rect.origin;
        }

        // Get line metrics
        newLine.m_rect.size = tu.getTextMetrics(
            0,
            -1,
            &m_font,
            m_layoutRect.getWidth(),
            &lineCount,
            &baseline,
            format,
            (VfxU8)m_wrapStyle,
            VFX_FALSE);

        // free format object memory
        m_storage->deleteRichTextFormat(format);
        
        if (lineCount == 0)
        {
            if (newLine.m_rect.getWidth() == 0)
            {
                if (!FONT_TEST_NEW_LINE_CHAR(*(s + offsetIndex)))
                {
                    // break if the layout width is too small
                    break;
                }
                else
                {
                    // set Newline symbol line width
                    newLine.m_rect.size = VfxSize(VCP_TEXT_LINE_MIN_WIDTH, VFX_MAX(minHeight, m_minLineHeight));
                    if (m_minLineHeight > minHeight)
                    {
                        newLine.m_baseLine= ascent + (m_minLineHeight - minHeight);
                    }
                    else
                    {
                        newLine.m_baseLine= ascent;
                    }
                }
            }
            else
            {
                // the line is object            
                if (currObj)
                {
                    // alignment adjust
                 //   if (newLine.m_rect.size.width <= m_layoutRect.getWidth())
                    {
                        switch (currObj->getObjectAttribute())
                        {
                        case VCP_RICH_TEXT_OBJ_ARRT_LEFT_ALIGN:
                            lineAlign = ALIGN_MODE_LEFT;
                            standAloneObject = currObj;
                            break;
                        case VCP_RICH_TEXT_OBJ_ARRT_MID_ALIGN:
                            lineAlign = ALIGN_MODE_CENTER;
                            standAloneObject = currObj;
                            break;
                        case VCP_RICH_TEXT_OBJ_ARRT_RIGHT_ALIGN:
                            lineAlign = ALIGN_MODE_RIGHT;
                            standAloneObject = currObj;
                            break;
                        default:
                            break;
                        }
                    }
                    
                    currObj = currObj->getNext();
                }
            }
        }
        else
        {
            newLine.m_baseLine= baseline;
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
          //  currObj = m_storage->getRichTextFormat(newLine.m_end + lineCount);
        }

        if (FONT_TEST_NEW_LINE_CHAR(*(s + offsetIndex + lineCount)) && !standAloneObject)
        {
            // count newline symbol
            // lineCount += app_ucs2_is_newline((VfxWChar *)(s + offsetIndex + lineCount));
            lineCount += app_ucs2_is_newline((VfxWChar *)(s + offsetIndex + lineCount));
        }

        newLine.m_end += lineCount;
        offsetIndex += lineCount;

        VfxRect lineBounds = newLine.m_rect;

        // in some cases, the text size width may be 0, so we should use min line width
        lineBounds.size.width = VFX_MAX(VCP_TEXT_LINE_MIN_WIDTH, lineBounds.size.width);

        switch (lineAlign)
        {
        case ALIGN_MODE_RIGHT:
            if (m_layoutRect.getWidth() >= lineBounds.size.width)
            {
                lineBounds.offsetWith(m_layoutRect.getWidth() - lineBounds.size.width, 0);

                // handle object alignment
                if (standAloneObject)
                {
                    if (standAloneObject->getType() == VCP_RICH_TEXT_TYPE_CUSTOM_FRAME)
                    {
                        VfxPoint p = ((VcpRichTextCustomFrame *)standAloneObject)->getPos();
                        ((VcpRichTextCustomFrame *)standAloneObject)->setPos(VfxPoint(lineBounds.origin.x/* + p.x*/, offsetY));
                    }
                }
            }

            break;

        case ALIGN_MODE_CENTER:
        //    if (m_layoutRect.getWidth() >= lineBounds.size.width)
            {
                lineBounds.origin.x =  m_layoutRect.getMidX() - lineBounds.getWidth()/2;

                // handle object alignment
                if (standAloneObject)
                {
                    if (standAloneObject->getType() == VCP_RICH_TEXT_TYPE_CUSTOM_FRAME)
                    {
                        // if center alignment, set anchor to middle positon
                        VfxFrame *cFrame = ((VcpRichTextCustomFrame *)standAloneObject)->getFrame();
                        if (cFrame)
                        {
                            cFrame->setAnchor(0.5f, 0);
                        }
                        ((VcpRichTextCustomFrame *)standAloneObject)->setPos(VfxPoint(m_layoutRect.getMinX() + m_layoutRect.getWidth() / 2, offsetY));
                    }
                }
            }
            break;
        }

        // the custom frame is hide when set and it is show when layout this frame done
        // otherwise, it will flash in wrong place
        if (standAloneObject && standAloneObject->getType() == VCP_RICH_TEXT_TYPE_CUSTOM_FRAME)
        {
            VfxFrame *cFrame = ((VcpRichTextCustomFrame *)standAloneObject)->getFrame();
            if (cFrame)
            {
                cFrame->setHidden(VFX_FALSE);
            }
            lineBounds.size.height += VCP_TEXT_CUSTOM_FRAME_GAP;
        }

        newLine.m_rect = lineBounds;
        newLine.m_textHeight = VFX_MAX(minHeight, lineBounds.getHeight());//minHeight;

        // Adjust line bounds by App set height height

        if (lineBounds.getHeight() < minHeight)
        {
            VfxS32 diff = minHeight - lineBounds.getHeight();

            newLine.m_rect.size.height += diff;
            lineBounds.size.height += diff;
            newLine.m_baseLine= ascent;
			if (baseline > ascent)
            {
                // use string real baseline to avoid the special character cut on top like character with tone marker
                newLine.m_baseLine = baseline;
            }
        }

        if (lineBounds.getHeight() < m_minLineHeight)
        {
            // adjust the line height to the min line height
            newLine.m_rect.size.height += m_minLineHeight - lineBounds.getHeight();
            newLine.m_baseLine += (m_minLineHeight - lineBounds.getHeight());
        }

        if ((m_truncateMode == TRUNCATE_MODE_END || m_truncateMode == TRUNCATE_MODE_MID) && (offsetIndex < end))
        {
            if ((lineBounds.getHeight() >= m_layoutRect.getHeight()) ||                          // line height small than layout height
                ((lineBounds.origin.y + lineBounds.getHeight() <= m_layoutRect.getHeight()) &&   // this line is within layout rect
                 (lineBounds.origin.y + 2 * lineBounds.getHeight() > m_layoutRect.getHeight()))) // next line is out of layout rect
            {
                newLine.m_isTruncated = VFX_TRUE;
                newLine.m_rect.size.width --;

                // use layout rect height as the line height
                if (lineBounds.getHeight() >= m_layoutRect.getHeight())
                {
                    newLine.m_rect.size.height = m_layoutRect.getHeight() - m_lineGap;
                }
            }
            else if (lineBounds.origin.y + lineBounds.getHeight() > m_layoutRect.getHeight())
            {
                // set current line as truncate line and use min line height as line height
                // Case: previous line is normal line, and current line is format line with object and line height is large than normal line
                newLine.m_isTruncated = VFX_TRUE;
                newLine.m_rect.size.width --;
                newLine.m_rect.size.height = minHeight;
            }
        }

        if ((m_truncateMode == TRUNCATE_WITH_AUTO_RESIZE) && (offsetIndex < end) &&
            ((lineBounds.getHeight() >= VCP_TEXT_FRAME_MAX_HEIGHT) ||
            (lineBounds.origin.y + lineBounds.getHeight() > VCP_TEXT_FRAME_MAX_HEIGHT)))
        {
            newLine.m_isTruncated = VFX_TRUE;
            newLine.m_rect.size.width --;
        }

        offsetY += newLine.m_rect.getHeight() + m_lineGap;

        // Add to new line
        addLine(newLine);

        layoutedLineCount++;

        //update dirty range
        m_dirty.setStart(offsetIndex);

        // all text has been updated
        if (offsetIndex > m_dirty.getEnd() || (newLine.m_isTruncated == VFX_TRUE))
        {
            m_dirty.setRange(0, 0);
			VFX_OBJ_CLOSE(m_layoutTimer);
            break;
        }

        //if (layoutedLineCount >= VCP_MAX_LAYOUT_LINES)
        if ((offsetIndex - start) > layoutCharCount)
        {
            // start a timer to layout rest of lines
            if (!m_layoutTimer)
            {
                VFX_OBJ_CREATE(m_layoutTimer, VfxTimer, this);
                m_layoutTimer->setStartDelay(VCP_MAX_LAYOUT_TIMER);
                m_layoutTimer->m_signalTick.connect(this, &VcpTextStaticLayout::layoutDirtyRange);
            }
            
            m_layoutTimer->start();
            break;
        }

        if ((m_maxLineNum > 0) && (m_lineCount >= m_maxLineNum))
        {
            m_dirty.setRange(offsetIndex, offsetIndex);
            m_signalMaxLineReached.postEmit(this);
            break;
        }
    }

    VcpRichTextFormat *pFormat = m_storage->getRichTextFormat();
    VcpRichTextFormat *custFrame = pFormat;
    // handle custom frame at last position
    if (pFormat && (m_dirty.getLength() == 0))
    {
        VcpRichTextFormat *pLast = pFormat->getLast();

        if (pLast && (pLast->m_range.getStart() == end) && pLast->isOccopyOneLine())
        {
            // add to line
            VcpTextLine newLine;

            // if not the first format, add the bottom gap
            if (pLast->m_range.getStart() > 0)
            {
                offsetY += VCP_TEXT_BOTTOM_FRAME_GAP;
            }
            newLine.m_rect.origin.x = m_layoutRect.getX();
            newLine.m_rect.origin.y = offsetY;
            newLine.m_rect.size = pLast->getSize();

            // handle zero width/height frame
            newLine.m_rect.size.width = newLine.m_rect.size.width > 0 ? newLine.m_rect.size.width : 1;
            newLine.m_rect.size.height = newLine.m_rect.size.height > 0 ? newLine.m_rect.size.height : 1;

            if (pLast->m_range.getStart() > 0)
            {
                newLine.m_rect.size.height += VCP_TEXT_BOTTOM_FRAME_GAP;
            }
            newLine.m_start = newLine.m_end = end;

            // alignment adjust
            if (newLine.m_rect.size.width <= m_layoutRect.getWidth())
            {
                switch (pLast->getObjectAttribute())
                {
                // __SLIM_TODO__ Remove case
               // case VCP_RICH_TEXT_OBJ_ARRT_LEFT_ALIGN:
                 //   break;
                case VCP_RICH_TEXT_OBJ_ARRT_MID_ALIGN:
                    newLine.m_rect.origin.x = m_layoutRect.getX() + (m_layoutRect.getWidth() - newLine.m_rect.size.width) / 2;
                    break;
                case VCP_RICH_TEXT_OBJ_ARRT_RIGHT_ALIGN:
                    newLine.m_rect.origin.x = m_layoutRect.getX() + (m_layoutRect.getWidth() - newLine.m_rect.size.width);
                    break;
                default:
                    break;
                }
            }
 
            if (pLast->getType() == VCP_RICH_TEXT_TYPE_CUSTOM_FRAME)
            {
                VfxFrame *cFrame = ((VcpRichTextCustomFrame *)pLast)->getFrame();
                if (pLast->getObjectAttribute() == VCP_RICH_TEXT_OBJ_ARRT_MID_ALIGN)
                {
                    if (cFrame)
                    {
                        cFrame->setAnchor(0.5f, 0);
                    }
                    ((VcpRichTextCustomFrame *)pLast)->setPos(VfxPoint(m_layoutRect.getMinX() + m_layoutRect.getWidth() / 2, offsetY));
                }
                else
                {
                    ((VcpRichTextCustomFrame *)pLast)->setPos(VfxPoint(newLine.m_rect.origin.x, offsetY));
                }

                // the custom frame is hide when set and it is show when layout this frame done
                // otherwise, it will flash in wrong place
                if (cFrame)
                {
                    cFrame->setHidden(VFX_FALSE);
                }
            }
            addLine(newLine);
        }
    }

    // add custom frame to text scrollable view
    while (custFrame)
    {
        if ((custFrame->getType() == VCP_RICH_TEXT_TYPE_CUSTOM_FRAME) && m_client)
        {
            VfxFrame *pFrame = ((VcpRichTextCustomFrame *)custFrame)->getFrame();
            // add custom frame to scrollable only when the frame layout is done (when show)
            if (pFrame && !pFrame->getHidden())
            {
                // client is VcpTextView
                ((VcpTextView *)m_client)->addChildToScrollable(pFrame);
               // pFrame->getParentFrame()->setIsZSortChild(VFX_TRUE);
               // pFrame->setPosZ(-1);
                pFrame->bringToFront();
                pFrame->setPos(((VcpRichTextCustomFrame *)custFrame)->getPos());

                // need to set aligner when layout is done
                // when application call forceupdate, the layout may not done due to partical update
                // so when layout done, we should help to call align to parent.
                // App scenario: set custom frame -> forceUpdate -> cust frame setAlignParent
                // setAlignParent will use wrong coordinate if the frame is layout in partical update
                VfxFrameAligner *pAligner = pFrame->getAligner();
                if (pAligner)
                {
                    VfxFrameAlignerModeEnum left = pAligner->getAlignMode(VFX_FRAME_ALIGNER_SIDE_LEFT);
                    VfxFrameAlignerModeEnum top = pAligner->getAlignMode(VFX_FRAME_ALIGNER_SIDE_TOP);
                    VfxFrameAlignerModeEnum right = pAligner->getAlignMode(VFX_FRAME_ALIGNER_SIDE_RIGHT);
                    VfxFrameAlignerModeEnum bottom = pAligner->getAlignMode(VFX_FRAME_ALIGNER_SIDE_BOTTOM);
                    if (left || right || top || bottom)
                    {
                        pFrame->setAlignParent(
                            left,
                            top,
                            right,
                            bottom);
                    }
                }
            }
        }
        custFrame = custFrame->getNext();
    }

    // get last line
    if (m_lineCount > 0)
    {
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
    #endif
        sendLayoutChangedNotification(VfxRect(0, 0, 0, 0));
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TL2", SA_stop);
#endif
}


void VcpTextStaticLayout::setLayoutRect(const VfxRect &rect)
{
    if (m_layoutRect != rect)
    {
        if (m_layoutRect.getWidth() != rect.getWidth())
        {
            m_dirty.setRange(0, m_storage->getTextLength());
            m_changedCharCount = 0;
            checkUpdate();
        }
        else
        {
            sendLayoutChangedNotification(VfxRect(0, 0, getWidth(), getHeight()));
        }
        m_layoutRect = rect;
    }
}


VfxS32 VcpTextStaticLayout::getLineIndex(VfxS32 index)
{
    VfxS32 i = 0;
    VcpTextLine *pLine;

    if (m_storage->getTextLength() <= 0)
    {
        return 0;
    }

    for (i = 0; i < m_lineCount; i++)
    {
        pLine = getLine(i);
        if (pLine->m_start <= index && pLine->m_end > index)
        {
            return i;
        }
    }

    return i - 1;
}


VfxS32 VcpTextStaticLayout::getLineIndexByY(VfxS32 y)
{
    VfxS32 end = getLineCount(), start = -1, mid;
    VfxRect rect;
    
    rect = getLineBounds(end-1);
    
    if (rect.getMaxY() < y)
        return end;

    while (end - start > 1) {
        mid = (end + start) / 2;

        rect = getLineBounds(mid);

        // conside the line gap
        if (m_lineGap > 0)
        {
            rect.origin.y -= m_lineGap;
            rect.size.height += m_lineGap;
        }

        if (rect.contains(VfxPoint(rect.origin.x, y)))
            return mid;
        else if (rect.origin.y > y)
            end = mid;
        else
            start = mid;
    }

    if (start < 0)
        return 0;
    else
        return start;
}


const VfxWChar* VcpTextStaticLayout::getLineText(VfxS32 lineIndex, VfxS32 *charCount)
{
    VcpTextLine *pLine = getLine(lineIndex);
    if (lineIndex < m_lineCount)
    {
        *charCount = pLine->m_end - pLine->m_start;
        return m_storage->getText() + pLine->m_start;
    }
    else
    {
        // return last line
        VcpTextLine *pLastLine = getLine(m_lineCount - 1);
        *charCount = pLastLine->m_end - pLastLine->m_start;
        return m_storage->getText() + pLastLine->m_start;
    }
}


void VcpTextStaticLayout::sendLayoutChangedNotification(VfxRect rect, VfxBool isPost)
{
    if (rect.isEmpty() && m_lineCount > 0)
    {
        VcpTextLine *lastLine = getLine(m_lineCount -1);
        VfxRect layoutRect = getLineBounds(0);
        layoutRect.size.height = lastLine->m_rect.getMaxY() - layoutRect.getMinY() + 1;
        layoutRect.size.width = lastLine->m_rect.getMaxX() - layoutRect.getMinX() + 1;

        // vertical alignment
        VfxS32 realRect = m_layoutRect.getHeight() - 2 * m_lineGap;
        if (layoutRect.size.height < realRect)
        {
            VfxS32 heightDiff = 0;
            switch (m_verticalAlignMode)
            {
            case VERT_ALIGN_MODE_MID:
                heightDiff = (realRect - layoutRect.size.height) / 2;
                break;
            case VERT_ALIGN_MODE_BOTTOM:
                heightDiff = (realRect - layoutRect.size.height);
                break;
            default:
                break;
            }
            layoutRect.origin.y += heightDiff;
            for (VfxS32 i = 0; i < m_lineCount; i++)
            {
                VcpTextLine *pLine = getLine(i);
                pLine->m_rect.origin.y += heightDiff;
            }
        }
        rect = layoutRect;
    }

    if (isPost)
    {
        m_signalLayoutChanged.postEmit(rect);
    }
    else
    {
        m_signalLayoutChanged.emit(rect);
    }
}


void VcpTextStaticLayout::UpdateViewForCustomFrame()
{
    VcpRichTextFormat *obj = m_storage->getRichTextFormat();
    VcpTextLine *line = NULL;
    VfxS32 lineIndex = 0;
    VfxBool isUpdated = VFX_FALSE;
    VcpRichTextFormat *pLast = obj->getLast();
    VfxS32 cFrameCnt = 0;

    while (obj)
    {
        if (obj->getType() == VCP_RICH_TEXT_TYPE_CUSTOM_FRAME)
        {
            // get custom frame line
            if (obj->m_range.getStart() == 0)
            {
                // header area
                line = getLine(0);
                lineIndex = 1;
            }
            else if (obj->m_range.getStart() == m_storage->getTextLength())
            {
                // footer area
                line = getLine(m_lineCount - 1);
                lineIndex = m_lineCount;
            }
            else
            {
                // handle custom frame in middle part
                lineIndex = getLineIndex(obj->m_range.getStart());
                line = getLine(lineIndex - 1);
            }

            if (line)
            {
                // update custom frame line
                line->m_rect.size.height = ((VcpRichTextCustomFrame *)obj)->getSize().height;
                VfxS32 lineY = line->m_rect.getMaxY() + 1;

                // update custom frame pos
                VfxPoint pos = ((VcpRichTextCustomFrame *)obj)->getPos();

                // do not update pos if only one custom frame line
                if (m_lineCount > 1)
                {
                    // if last frame y pos has been update in previous step (cFrameCnt > 0) when update other custom frame
                    // add bottom gap otherwise the y pos is its real pos so no need to add gap
                    if (obj == pLast && obj->m_range.getStart() > 0 && cFrameCnt > 0)
                    {
                        line->m_rect.origin.y += VCP_TEXT_BOTTOM_FRAME_GAP;
                        pos.y = line->m_rect.origin.y;
                        line->m_rect.size.height += VCP_TEXT_BOTTOM_FRAME_GAP;
                    }
                    else
                    {
                        line->m_rect.size.height += VCP_TEXT_CUSTOM_FRAME_GAP;
                        lineY += VCP_TEXT_CUSTOM_FRAME_GAP;
                        pos.y = line->m_rect.origin.y;
                        // update line bounds afterwards
                        for (; lineIndex < m_lineCount; lineIndex++)
                        {
                            line = getLine(lineIndex);
                            line->m_rect.origin.y = lineY;
                            lineY += line->m_rect.getHeight();
                        }
                    }
                }
                // set frame pos
                ((VcpRichTextCustomFrame *)obj)->setPos(pos);
                VfxFrame *cFrame = ((VcpRichTextCustomFrame *)obj)->getFrame();
                if (cFrame)
                {
                    cFrame->setPos(pos);
                }
            }
            isUpdated = VFX_TRUE;

            cFrameCnt++;
        }

        obj = obj->getNext();
    }

    // get last line
    if (isUpdated && m_lineCount > 0)
    {
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
    #endif
        sendLayoutChangedNotification(VfxRect(0, 0, 0, 0));
    }
}


/***************************************************************************** 
 * Class VcpTextDynamicLayout
 *****************************************************************************/
VcpTextDynamicLayout::VcpTextDynamicLayout(IVfxAllocatable* client)
{
    m_lines = NULL;
    m_cacheLineIndex = -1;
    m_cacheLine = NULL;
    m_lineCount = 0;
    m_client = client;
    m_batch = VFX_FALSE;
}

VcpTextDynamicLayout::~VcpTextDynamicLayout()
{
    clearLines();
}


void VcpTextDynamicLayout::clearLines()
{
    m_lineCount = 0;
    VcpTextListLine* line;
        
    while (m_lines)
    {
        line = m_lines->getNext();
        VFX_DELETE(m_lines);
        m_lines = line;
    }
}


VfxS32 VcpTextDynamicLayout::deleteLines(VfxS32 start, VfxS32 end, VfxS32 changedCharCount)
{
    VfxS32 startLine, endLine;
    VcpTextListLine *pStart, *pEnd;
    VfxS32 deleteHeight = 0;

    if (!m_lines)
        return 0;

    // all line need to be deleted
    if (start == 0 && end == m_storage->getTextLength())
    {
        clearLines();
        return 0;
    }

    startLine = getLineIndex(start);
    endLine = getLineIndexFromOrg(end - changedCharCount - 1);

    // to handle last character is newline case
    VcpTextListLine *pLast = m_lines->getLast();
    const VfxWChar *pText = m_storage->getText();
    if (/*FONT_TEST_NEW_LINE_CHAR(pText[end - 1]) && */end == m_storage->getTextLength() && 
        (pLast->m_start == pLast->m_end))
    {
        endLine = m_lineCount - 1;
    }

    // end line should not smaller than start line
    endLine = VFX_MAX(endLine, startLine);

    pStart = getLine(startLine);
    pEnd = getLine(endLine);

    // find the line before start line and link it to the line next to end line
    VcpTextListLine *pLine = m_lines;
    if (startLine > 0)
    {
        while (pLine)
        {
            if (pLine->getNext() == pStart)
            {
                break;
            }
            else
            {
                pLine = pLine->getNext();
            }
        }

        // found the line and link it the the next line of end line
        if (pLine)
        {
            pLine->m_next = pEnd->m_next;
        }
    }
    else
    {
        m_lines = pEnd->m_next;
    }

    // free lines
    VcpTextListLine *line = pStart;
    VcpTextListLine *pDeleteUpto = pEnd->m_next;
    while (pStart && pStart != pDeleteUpto)
    {
        line = pStart->getNext();
        deleteHeight += (pStart->m_rect.getHeight() + m_lineGap);
        VFX_DELETE(pStart);
        pStart = line;
    }

    // update the line info afterward
    line = pDeleteUpto;
    while (line)
    {
        line->m_rect.origin.y -= deleteHeight;
        line->m_start += changedCharCount;
        line->m_end += changedCharCount;
        line = line->getNext();
    }

    m_lineCount -= (endLine- startLine + 1);
    // If empty content
    if (m_lineCount < 0)
    {
        m_lineCount = 0;
    }

    return deleteHeight;
}


void VcpTextDynamicLayout::insertLine(VcpTextListLine *line, VfxS32 index)
{
    VcpTextListLine *pInsert = getLine(index);
    VcpTextListLine *pAfter = pInsert->getNext();

    if (line == NULL)
    {
        return;
    }

    // Insert
    if (index == 0 && (line->m_start == 0))
    {
        // insert at text start position
        m_lines = line;
        m_lines->m_next = pInsert;
        pAfter = pInsert;
    }
    else if (pInsert)
    {
        pInsert->m_next = line;
        line->m_next = pAfter;
        line->m_rect.origin.y = pInsert->m_rect.origin.y + pInsert->m_rect.getHeight() + m_lineGap;
    }

    // Update line info afterwards
    while (pAfter)
    {
        pAfter->m_rect.origin.y += line->m_rect.getHeight() + m_lineGap;
        pAfter = pAfter->getNext();
    } 
}


VfxS32 VcpTextDynamicLayout::getLineStart(VfxS32 line)
{
    VcpTextListLine *pLine = getLine(line);

    if (pLine)
    {
        return pLine->m_start;
    }
    else
    {
        return 0;
    }
}


VfxS32 VcpTextDynamicLayout::getLineEnd(VfxS32 line)
{
    VcpTextListLine *pLine = getLine(line);

    if (pLine)
    {
        return pLine->m_end;
    }
    else
    {
        return 0;
    }
}


void VcpTextDynamicLayout::layoutDirtyRange(VfxTimer *source)
{
    if (m_layoutTimer)
    {
        m_layoutTimer->stop();
    }
    
    if (m_dirty.getLength() == 0)
    {
        VFX_OBJ_CLOSE(m_layoutTimer);
        return;
    }

    layout(m_dirty.getStart(), m_dirty.getEnd(), 0);

    if (m_dirty.getLength() == 0)
    {
        VFX_OBJ_CLOSE(m_layoutTimer);
    }
}


const VfxRect& VcpTextDynamicLayout::getLineBounds(VfxS32 line)
{
    return getLine(line)->m_rect;
}


VfxS32 VcpTextDynamicLayout::getLineBaseLine(VfxS32 line)
{
    VcpTextListLine *pLine = getLine(line);

    if (pLine)
    {
        return pLine->m_baseLine;
    }
    else
    {
        return 0;
    }
}


VfxS32 VcpTextDynamicLayout::getLineTextHeight(VfxS32 line)
{
    VcpTextListLine *pLine = getLine(line);

    if (pLine)
    {
        return pLine->m_textHeight;
    }
    else
    {
        return 0;
    }
}


void VcpTextDynamicLayout::drawLine(VfxS32 line, VfxDrawContext &dc, const VfxRect &area, VfxPoint offsetToDC, VfxBool isDrawHilite)
{
    VcpRichTextFormat *textFormat = NULL;

    // first line is custom frame
    textFormat = m_storage->getRichTextFormat();
    if (line == 0 && textFormat && textFormat->getType() == VCP_RICH_TEXT_TYPE_CUSTOM_FRAME &&
        textFormat->m_range.getStart() == 0 && textFormat->isOccopyOneLine())
    {
        return;
    }

    VcpTextListLine *pLine = getLine(line);
    if (pLine == NULL)
    {
        return;
    }

    VfxS32 count = pLine->m_end - pLine->m_start;

    const VfxWChar* s = NULL;
    VfxS32 len = 0;
    // Get text from textstorage
    m_storage->getText(&s, &len);

    if (m_isUnderline && !isDrawHilite)
    {
        VfxS32 baseline = pLine->m_baseLine;

        // draw underline
        dc.setStrokeColor(m_underlineColor);
        VfxS32 baselineGap = VCP_TEXT_BASELINE_GAP;
        if (baseline == pLine->m_rect.getHeight())
        {
            baselineGap = 0;
        }
        dc.drawLine(
            m_layoutRect.getMinX() + offsetToDC.x,
            pLine->m_rect.getMinY() + baseline + offsetToDC.y - 1 + baselineGap,
            m_layoutRect.getMaxX() + offsetToDC.x,
            pLine->m_rect.getMinY() + baseline + offsetToDC.y - 1 + baselineGap);
    }

    VfxWChar *temp_String = NULL;
    if (pLine->m_start >= 0 && pLine->m_end >= 0)
    {
        s = (VfxWChar*)s + pLine->m_start;

        // __SLIM_TODO__ Use funtion to convert mask character buffer
        if (m_isMask)
        {
            VFX_ALLOC_MEM(temp_String, (count + 1) * sizeof(VfxWChar), m_client);

            VfxTextRange markRange = m_marked;
            VfxTextRange lineRange = VfxTextRange(pLine->m_start, pLine->m_end);
            if (!(m_marked.isOutside(lineRange)))
            {
                markRange.limitTo(lineRange);
                markRange.shift(-pLine->m_start);
            }
            else
            {
                markRange.setRange(0, 0);
            }

            convertToMaskText(s, count, temp_String, count, markRange);

            s = temp_String;
        }
    }

    vrt_text_dir_type_enum dir = vrt_sys_get_text_dir();
    VfxRect textRect = pLine->m_rect;
    if (dir == MG_TEXT_DIR_TYPE_L2R)
    {
        textRect.origin.x += offsetToDC.x;
    }
    else
    {   
        textRect.origin.x += (pLine->m_rect.size.width - 1 + offsetToDC.x);
    }
    textRect.origin.y += offsetToDC.y;

    textFormat = m_storage->getRichTextFormat(pLine->m_start, pLine->m_end);
    drawLineText(dc, textRect, *pLine, s, count, textFormat, isDrawHilite);

    // free format object memory
    m_storage->deleteRichTextFormat(textFormat);
    VFX_FREE_MEM(temp_String);
}


void VcpTextDynamicLayout::layout(VfxS32 start, VfxS32 end, VfxS32 changedCharCount)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TL3", SA_start);
#endif
    kal_uint32 layoutTime1,layoutTime2, layoutTime3, layoutTime4;
    kal_get_time(&layoutTime1); 
    const VfxWChar* s = NULL;
    VfxS32 len = 0;
    // Get text from textstorage
    m_storage->getText(&s, &len);
    if (s == NULL)
    {
        // initialize stage
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TL3", SA_stop);
    #endif
        return;
    }

    // clear cache line
    m_cacheLineIndex = -1;
    m_cacheLine = NULL;

    VcpTextUtils tuTemp(m_client);
    VfxS32 minHeight, ascent, descent;
    minHeight = tuTemp.getTextHeightOfCommonLang(&m_font, &ascent, &descent);
    // Empty string
    if (*s == 0)
    {
        VcpTextListLine* newLine;

        // clear all lines
        clearLines();

        // clear dirty range
        m_dirty.setRange(0, 0);

        VFX_ALLOC_NEW(newLine, VcpTextListLine, m_client);
        newLine->m_rect = VfxRect(m_layoutRect.getMinX(), m_lineGap, m_layoutRect.getWidth(), VFX_MAX(minHeight, m_minLineHeight));
        if (m_minLineHeight > minHeight)
        {
             newLine->m_baseLine= ascent + (m_minLineHeight - minHeight);
        }
        else
        {
             newLine->m_baseLine= ascent;
        }
        newLine->m_textHeight= minHeight;
        m_lines = newLine;
        m_lineCount = 1;

        // vertical alignment
        VfxS32 realRect = m_layoutRect.getHeight() - 2 * m_lineGap;
        if (newLine->m_rect.size.height < realRect)
        {
            VfxS32 heightDiff = 0;
            switch (m_verticalAlignMode)
            {
            case VERT_ALIGN_MODE_MID:
                heightDiff = (realRect - newLine->m_rect.size.height) / 2;
                break;
            case VERT_ALIGN_MODE_BOTTOM:
                heightDiff = (realRect - newLine->m_rect.size.height);
                break;
            default:
                break;
            }
            newLine->m_rect.origin.y += heightDiff;
        }
        sendLayoutChangedNotification(newLine->m_rect);
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TL3", SA_stop);
    #endif
        return;
    }

    // hanlde mask string (password)
    VfxWChar *temp_String = NULL;
    if (m_isMask)
    {
        // handle mask character
        VfxS32 textLen = vfx_sys_wcslen(s);
        VFX_ALLOC_MEM(temp_String, (textLen + 1) * sizeof(VfxWChar), m_client);
        convertToMaskText(s, textLen, temp_String, textLen, m_marked);
        s = temp_String;
    }

    // delete dirty lines
    // only delete once if partical update layout
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
#else
	if (start == 0 && end == m_storage->getTextLength())
    {
        clearLines();
    }
	else
    {
        // adjust start/end position to line start/end
        VfxS32 sLineIndex = getLineIndex(start);
        sLineIndex -= 1;
        sLineIndex = VFX_MAX(0,sLineIndex);
        start = getLineStart(sLineIndex);
        deleteLines(start, end, changedCharCount);
    }
#endif

    if ((m_maxLineNum > 0) && (m_lineCount >= m_maxLineNum))
    {
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TL3", SA_stop);
    #endif
        return;
    }

    VcpRichTextFormat *format;
    VfxRect layoutRect;
    VfxS32 offsetIndex = start, offsetY = m_lineGap;

    // get text direction
    if (start == 0)
    {
        VcpTextUtils tuDir(m_client);
        tuDir.setText(s, NULL);
        m_direction = tuDir.getTextDirection();
    }

    vrt_text_dir_type_enum dir = vrt_sys_get_text_dir();
    AlignModeEnum alignMode = m_alignMode;
    if (m_direction == MG_TEXT_DIR_TYPE_R2L)
    {
        dir = MG_TEXT_DIR_TYPE_R2L;
    }
    alignMode = getAlignment();

    // calc the layout char number each time
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    static VfxS32 layoutCharCount = 0;
    if (!m_layoutTimer)
    {
        layoutCharCount = VCP_MIN_LAYOUT_CHARS;
    }
    else
    {
        layoutCharCount += 200;
        layoutCharCount = VFX_MIN(layoutCharCount, VCP_MAX_LAYOUT_CHARS);
    }

    // get line index to be insert after
    VfxS32 insertLineIndex = getLineIndex(start - 1);
    VfxS32 layoutedLineCount = 0;
    kal_get_time(&layoutTime2); 
    while (offsetIndex <= end)
    {
        VcpTextListLine* newLine;
        VfxS32 lineCount;
        VcpTextUtils tu(m_client);
        VfxS32 baseline;
        VfxBool isLastNewline = VFX_FALSE;

        // handle new line symbol at the end of text
        if (offsetIndex == end)
        {
            VcpTextListLine *pLastLine = getLine(m_lineCount - 1);
            if (FONT_TEST_NEW_LINE_CHAR((*(s + len - 1))) && (end == len) && (pLastLine->m_start != pLastLine->m_end))
            {
                isLastNewline = VFX_TRUE;
            }
            else
            {
                break;
            }
        }

        //create a new line info
        VFX_ALLOC_NEW(newLine, VcpTextListLine, m_client);

        // set the line bounds
        newLine->m_start = newLine->m_end = offsetIndex;
        newLine->m_rect.origin.x = m_layoutRect.getX();
        newLine->m_rect.origin.y = offsetY;

        // handle indent
        if (offsetIndex == 0)
        {
            layoutRect.origin = newLine->m_rect.origin;
        }

        // check if new line
        if (FONT_TEST_NEW_LINE_CHAR(*(s + offsetIndex)) || isLastNewline)
        {
            // set Newline symbol line width
            newLine->m_rect.size = VfxSize(VCP_TEXT_LINE_MIN_WIDTH, minHeight);
            newLine->m_baseLine= ascent;
            lineCount = 0;
        }
        else
        {
            tu.setText(s + offsetIndex);
            format = m_storage->getRichTextFormat(offsetIndex, end);

            // Get line metrics
            kal_uint32 time1,time2;
            kal_get_time(&time1); 
			VfxS32 adv_width = 0;
            newLine->m_rect.size = tu.getTextMetrics(
                0,
                -1,
                &m_font,
                m_layoutRect.getWidth(),
                &lineCount,
                &baseline,
                format,
                (VfxU8)m_wrapStyle,
                VFX_FALSE,
				&adv_width);

			// Because cursor will locate after adv_width. So if string width < layout rect with but adv_width >= layout rect width
			// the multiline visible rect may be scroll out in scrollViewForCursor
			// For example, input Chinese symbol ';' at the end of line, the line will scroll to left because of adjust cursor
			// So we need to reduce the character count of this line until the adv_width can fit this line.
			while (adv_width >= m_layoutRect.getWidth() && lineCount > 0)
			{
				newLine->m_rect.size = tu.getTextMetrics(
					0,
					lineCount - 1,
					&m_font,
					m_layoutRect.getWidth(),
					&lineCount,
					&baseline,
					format,
					(VfxU8)m_wrapStyle,
					VFX_FALSE,
					&adv_width);
			}

            kal_get_time(&time2); 
            VFX_LOG(VFX_INFO2, VCP_TEXT_LAYOUT_GET_TEXT_METRICS, time1, time2, kal_ticks_to_milli_secs(time2 - time1));

            // free format object memory
            m_storage->deleteRichTextFormat(format);
        
            if (lineCount == 0)
            {
                if (FONT_TEST_NEW_LINE_CHAR(*(s + offsetIndex)) || isLastNewline)
                {
                    // set Newline symbol line width
                    newLine->m_rect.size = VfxSize(VCP_TEXT_LINE_MIN_WIDTH, minHeight);
                    newLine->m_baseLine= ascent;
                }
                else //if (*(s + offsetIndex) != 0x0A)
                {
                    VFX_DELETE(newLine);

                    // break if the layout width is too small
                    break;
                }
            }
            else
            {
                newLine->m_baseLine= baseline;
            }
        }

        if (FONT_TEST_NEW_LINE_CHAR(*(s + offsetIndex + lineCount)))
        {
            // count newline symbol
            lineCount += app_ucs2_is_newline((VfxWChar *)(s + offsetIndex + lineCount));;
        }

        newLine->m_end += lineCount;
        offsetIndex += lineCount;

        VfxRect lineBounds = newLine->m_rect;

        // in some cases, the text size width may be 0, so we should use min line width
        lineBounds.size.width = VFX_MAX(VCP_TEXT_LINE_MIN_WIDTH, lineBounds.size.width);

        switch (alignMode)
        {
        case ALIGN_MODE_RIGHT:
            if (m_layoutRect.getWidth() >= lineBounds.size.width)
            {
                lineBounds.offsetWith(m_layoutRect.getWidth() - lineBounds.size.width, 0);
            }
            break;

        case ALIGN_MODE_CENTER:
            if (m_layoutRect.getWidth() >= lineBounds.size.width)
            {
                lineBounds.origin.x =  m_layoutRect.getMidX() - lineBounds.getWidth()/2;
            }
            break;
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        }

        newLine->m_rect = lineBounds;
        newLine->m_textHeight = VFX_MAX(minHeight, lineBounds.getHeight());

        if (lineBounds.getHeight() < minHeight)
        {
            VfxS32 diff = minHeight - lineBounds.getHeight();

            newLine->m_rect.size.height += diff;
            lineBounds.size.height += diff;
            newLine->m_baseLine= ascent;
			if (baseline > ascent)
            {
                // use string real baseline to avoid the special character cut on top like character with tone marker
                newLine->m_baseLine = baseline;
            }
        }

        if (lineBounds.getHeight() < m_minLineHeight)
        {
            // adjust the line height to the min line height
            newLine->m_rect.size.height += m_minLineHeight - lineBounds.getHeight();
            newLine->m_baseLine += (m_minLineHeight - lineBounds.getHeight());
        }

        offsetY += newLine->m_rect.getHeight() + m_lineGap;

        // Add to new line
        if (m_lines == NULL)
        {
            m_lines = newLine;
        }
        else
        {
            insertLine(newLine, insertLineIndex);
            if (newLine->m_start != 0)
            {
                insertLineIndex++;
            }
        }

        m_lineCount++;
        layoutedLineCount++;

        //update dirty range
        m_dirty.setStart(offsetIndex);

        if (isLastNewline)
        {
            offsetIndex++;
        }

        // all text has been updated
        if (offsetIndex > m_dirty.getEnd())
        {
            m_dirty.setRange(0, 0);
            VFX_OBJ_CLOSE(m_layoutTimer);
            break;
        }

       // if (layoutedLineCount >= VCP_MAX_LAYOUT_LINES)
        if ((offsetIndex - start) > layoutCharCount)
        {
            // start a timer to layout rest of lines
            if (!m_layoutTimer)
            {
                VFX_OBJ_CREATE(m_layoutTimer, VfxTimer, this);
                m_layoutTimer->setStartDelay(VCP_MAX_LAYOUT_TIMER);
                m_layoutTimer->m_signalTick.connect(this, &VcpTextDynamicLayout::layoutDirtyRange);
            }
            
            m_layoutTimer->start();

            break;
        }

        if ((m_maxLineNum > 0) && (m_lineCount >= m_maxLineNum))
        {
            m_dirty.setRange(offsetIndex, offsetIndex);
            m_signalMaxLineReached.postEmit(this);
            break;
        }
    }
    kal_get_time(&layoutTime3); 
    if (m_lineCount > 0)
    {
        if (m_verticalAlignMode > 0)
        {
            // if not top alignment, the whole line bounds need re-aligned
            start = 0;
        }
        VfxS32 firstLineIndex = getLineIndex(start);
        layoutRect.origin = getLine(firstLineIndex)->m_rect.origin;
        layoutRect.size.height = getLine(m_lineCount-1)->m_rect.getMaxY() - getLine(firstLineIndex)->m_rect.getMinY() + 1;
        layoutRect.size.width = m_layoutRect.getWidth();

        // vertical alignment
        VfxS32 realRect = m_layoutRect.getHeight() - 2 * m_lineGap;
        if (layoutRect.size.height < realRect)
        {
            VfxS32 heightDiff = 0;
            switch (m_verticalAlignMode)
            {
            case VERT_ALIGN_MODE_MID:
                heightDiff = (realRect - layoutRect.size.height) / 2;
                break;
            case VERT_ALIGN_MODE_BOTTOM:
                heightDiff = (realRect - layoutRect.size.height);
                break;
            default:
                break;
            }
            layoutRect.origin.y += heightDiff;
            for (VfxS32 i = 0; i < m_lineCount; i++)
            {
                VcpTextListLine *pLine = getLine(i);
                pLine->m_rect.origin.y += heightDiff;
            }
        }

        sendLayoutChangedNotification(layoutRect);
    }

    kal_get_time(&layoutTime4); 
    VFX_LOG(VFX_FUNC2, VCP_TEXT_LAYOUT_RANGE, start, offsetIndex, m_dirty.getStart(), m_dirty.getEnd());
    VFX_LOG(VFX_FUNC2, VCP_TEXT_LAYOUT_TIME, layoutTime1, layoutTime2, layoutTime3, layoutTime4);
    VFX_LOG(VFX_FUNC2, VCP_TEXT_LAYOUT_TIME_DETAIL,
        kal_ticks_to_milli_secs(layoutTime4 - layoutTime1),
        kal_ticks_to_milli_secs(layoutTime3 - layoutTime2),
        kal_ticks_to_milli_secs(layoutTime4 - layoutTime3));

    VFX_FREE_MEM(temp_String);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TL3", SA_stop);
#endif

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
#endif
}


void VcpTextDynamicLayout::sendLayoutChangedNotification(VfxRect rect, VfxBool isPost)
{
    if (m_batch)
    {
        if (m_batchRect.isEmpty())
        {
            m_batchRect = rect;
        }
        else
        {
            m_batchRect.unionWith(rect);
        }
    }
    else
    {
        if (isPost)
        {
            m_signalLayoutChanged.postEmit(rect);
        }
        else
        {
            m_signalLayoutChanged.emit(rect);
        }
    }
}


void VcpTextDynamicLayout::UpdateViewForCustomFrame()
{
    
}


void VcpTextDynamicLayout::setBatch(VfxBool is_batch)
{
    m_batch = is_batch;
    if (is_batch == VFX_FALSE)
    {
        if (!m_batchRect.isEmpty())
        {
            sendLayoutChangedNotification(m_batchRect);
            m_batchRect.setZero();
        }
    }
}


VcpTextListLine* VcpTextDynamicLayout::getLine(VfxS32 index)
{
    if (m_dirty.getLength() > 0)
    {
        m_cacheLineIndex = -1;
        m_cacheLine = NULL;
    }

    VfxS32 i = 0;
    VcpTextListLine* line = m_lines;
    // if cached line before, find from cached line
    if (m_cacheLineIndex != -1 && m_cacheLine)
    {
        if (index == m_cacheLineIndex)
        {
            return m_cacheLine;
        }
        else if (index > m_cacheLineIndex)
        {
            i = m_cacheLineIndex;
            line = m_cacheLine;
        }
    }

    if (index <= 0)
    {
        return line;
    }
    else if (index >= m_lineCount)
    {
        return line->getLast();
    }

    VcpTextListLine* lastLine = NULL;
    while (i++ < index)
    {
        if (line)
        {
            lastLine = line;
            line = line->getNext();
            if (line == NULL)
            {
                line = lastLine;
                break;
            }
        }
        else
        {
            // return last line
            line = lastLine;
            break;
        }
    }

    // save cache when layout already done
    if (m_dirty.getLength() == 0)
    {
        m_cacheLineIndex = index;
        m_cacheLine = line;
    }

    return line;
}


void VcpTextDynamicLayout::setLayoutRect(const VfxRect &rect)
{
    if (m_layoutRect != rect)
    {
        if (m_layoutRect.getWidth() != rect.getWidth())
        {
            m_dirty.setRange(0, m_storage->getTextLength());
            m_changedCharCount = 0;
            checkUpdate();
        }
        else
        {
            sendLayoutChangedNotification(VfxRect(0, 0, getWidth(), getHeight()));
        }
        m_layoutRect = rect;
    }
}


VfxS32 VcpTextDynamicLayout::getLineIndex(VfxS32 index)
{
    VfxS32 i = 0;
    VcpTextListLine* line = m_lines;

    // line check
    if ((m_storage->getTextLength() <= 0) || (index <= 0))
    {
        return 0;
    }
    else if (index > m_storage->getTextLength())
    {
        return m_lineCount - 1;
    }

    while (line)
    {
        if (line->m_start <= index && line->m_end > index ||
            line->m_start == index && line->m_end == index) // last character is newline case
        {
            return i;
        }

        VcpTextListLine* nextLine = line->getNext();
        if (nextLine && nextLine->m_start != line->m_end)
        {
            return i;
        }
        line = nextLine;
        i++;
    }

    return i - 1;
}


VfxS32 VcpTextDynamicLayout::getLineIndexByY(VfxS32 y)
{
    VcpTextListLine* line = m_lines;
    VfxS32 lineIndex = 0;
    if (line && y < line->m_rect.getMinY())
    {
        return 0;
    }

    while (line)
    {
        if (line->m_rect.contains(VfxPoint(line->m_rect.origin.x, y)))
        {
            return lineIndex;
        }
        line = line->getNext();
        lineIndex++;
    }

    return getLineCount();
}


VfxS32 VcpTextDynamicLayout::getLineIndexFromOrg(VfxS32 index)
{
    VfxS32 i = 0;
    VcpTextListLine* line = m_lines;

    // line check
    if ((m_storage->getTextLength() <= 0) || (index <= 0))
    {
        return 0;
    }

    while (line)
    {
        if (line->m_start <= index && line->m_end > index ||
            line->m_start == index && line->m_end == index) // last character is newline case
        {
            return i;
        }

        line = line->getNext();
        i++;
    }

    return i - 1;
}


const VfxWChar* VcpTextDynamicLayout::getLineText(VfxS32 lineIndex, VfxS32 *charCount)
{
    if (m_lines)
    {
        VcpTextListLine* line = getLine(lineIndex);
        *charCount = line->m_end - line->m_start;
        return m_storage->getText() + line->m_start;
    }
    else
    {
        *charCount = 0;
        return NULL;
    }
}


/***************************************************************************** 
 * Class VcpTextSingleLineLayout
 *****************************************************************************/
VcpTextSingleLineLayout::VcpTextSingleLineLayout(IVfxAllocatable* client)
{
    m_client = client;
    m_lineGap = 0;
    m_isUnderline = VFX_FALSE;
    m_batch = VFX_FALSE;
    m_verticalAlignMode = VERT_ALIGN_MODE_MID;
}


VcpTextSingleLineLayout::~VcpTextSingleLineLayout()
{

}


VfxS32 VcpTextSingleLineLayout::getLineStart(VfxS32 line)
{
    return 0;
}


VfxS32 VcpTextSingleLineLayout::getLineEnd(VfxS32 line)
{
    return m_lines.m_end;
}


const VfxRect& VcpTextSingleLineLayout::getLineBounds(VfxS32 line)
{
    return m_lines.m_rect;
}


VfxS32 VcpTextSingleLineLayout::getLineBaseLine(VfxS32 line)
{
    return m_lines.m_baseLine;
}


VfxS32 VcpTextSingleLineLayout::getLineTextHeight(VfxS32 line)
{
    return m_lines.m_textHeight;
}


void VcpTextSingleLineLayout::drawLine(VfxS32 line, VfxDrawContext &dc, const VfxRect &area, VfxPoint offsetToDC, VfxBool isDrawHilite)
{
    vrt_text_dir_type_enum dir = vrt_sys_get_text_dir();
    const VfxWChar* s = NULL;
    VfxS32 len = 0;
    VfxWChar *temp_String = NULL;
    VcpRichTextFormat *textFormat = NULL;

    VfxS32 count = m_lines.m_end - m_lines.m_start;

    // Get text from textstorage
    m_storage->getText(&s, &len);

    textFormat = m_storage->getRichTextFormat(m_lines.m_start, m_lines.m_end);

    if (m_lines.m_start >= 0 && m_lines.m_end >= 0)
    {
        if (m_isMask)
        {
            VFX_ALLOC_MEM(temp_String, (count + 1) * sizeof(VfxWChar), m_client);
            convertToMaskText(s, count, temp_String, count, m_marked);
            s = temp_String;
        }
    }

    VfxRect textRect = m_lines.m_rect;

    if (dir == MG_TEXT_DIR_TYPE_L2R)
    {
        textRect.origin.x += offsetToDC.x;
    }
    else
    {   
        textRect.origin.x += (m_lines.m_rect.size.width - 1 + offsetToDC.x);
    }
    textRect.origin.y += offsetToDC.y;
    drawLineText(dc, textRect, m_lines, s, count, textFormat, isDrawHilite);

    // free format object memory
    m_storage->deleteRichTextFormat(textFormat);
    VFX_FREE_MEM(temp_String);
}


void VcpTextSingleLineLayout::layout(VfxS32 start, VfxS32 end, VfxS32 changedCharCount)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TL1", SA_start);
#endif
    const VfxWChar* s = NULL;
    VfxS32 len = 0;
    VcpTextUtils tu(m_client);
    VfxRect layoutRect;
    VfxS32 lineCharCount = 0;
    VfxS32 retLineCharCount = 0;
    VcpTextUtils tuTemp(m_client);
    VfxS32 minHeight, ascent, descent;
    vrt_text_dir_type_enum dir = vrt_sys_get_text_dir();
    AlignModeEnum alignMode = m_alignMode;
    VcpTextLine newLine;
    VcpRichTextFormat *format;
    VfxWChar *temp_String = NULL;

  //  minHeight = tuTemp.getTextHeightOfCommonLang(&m_font, &ascent, &descent);
    tuTemp.getTextInfoOfSimpleLang(m_font.size, &minHeight, &ascent, &descent);

    // Single line
    start = 0;

    // Get text from textstorage
    m_storage->getText(&s, &len, &format);

    if (s == NULL)
    {
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TL1", SA_stop);
    #endif
        return;
    }

    // Empty string
    if (*s == 0)
    {
        m_lines.m_rect = VfxRect(0, m_lineGap, 1, VFX_MAX(minHeight, m_minLineHeight));
        if (m_minLineHeight > minHeight)
        {
             m_lines.m_baseLine= ascent + (m_minLineHeight - minHeight);
        }
        else
        {
             m_lines.m_baseLine= ascent;
        }
        m_lines.m_start = m_lines.m_end = 0;
        m_lines.m_textHeight = minHeight;

        // vertical alignment
        if (m_layoutRect.getHeight() > m_lines.m_rect.size.height)
        {
            VfxS32 heightDiff = 0;
            switch (m_verticalAlignMode)
            {
            case VERT_ALIGN_MODE_MID:
                {
                    if ((m_layoutRect.getHeight() - m_lines.m_rect.size.height) % 2)
                    {
                        heightDiff = (m_layoutRect.getHeight() - m_lines.m_rect.size.height) / 2;
                    }
                    else
                    {
                        heightDiff = (m_layoutRect.getHeight() - m_lines.m_rect.size.height) / 2 + 1;
                    }
                    break;
                }
            case VERT_ALIGN_MODE_BOTTOM:
                heightDiff = (m_layoutRect.getHeight() - m_lines.m_rect.size.height);
                break;
            default:
                break;
            }
            m_lines.m_rect.origin.y += heightDiff;
        }

        sendLayoutChangedNotification(m_lines.m_rect);
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TL1", SA_stop);
    #endif
        return;
    }

    if (m_isMask)
    {
        // handle mask character
        VfxS32 textLen = vfx_sys_wcslen(s);
        VFX_ALLOC_MEM(temp_String, (textLen + 1) * sizeof(VfxWChar), m_client);
        convertToMaskText(s, textLen, temp_String, textLen, m_marked);
        s = temp_String;
    }

    tu.setText(s);
    // TODO: new line symbol should be 0x0A or 0x0D or 0x0D0A
    lineCharCount = tu.indexOf(0x0A, 0, m_storage->getTextLength());
    if (lineCharCount == -1)
        lineCharCount = m_storage->getTextLength();

    // get text direction
    if (start == 0)
    {
        VcpTextUtils tuDir(m_client);
        tuDir.setText(s, NULL);
        m_direction = tuDir.getTextDirection();
    }

    if (m_direction == MG_TEXT_DIR_TYPE_R2L)
    {
        dir = MG_TEXT_DIR_TYPE_R2L;
    }
    alignMode = getAlignment();

    // set the line bounds
    newLine.m_start = 0;
    newLine.m_end = lineCharCount;
    newLine.m_rect.origin.x = m_layoutRect.getX();
    newLine.m_rect.origin.y = m_layoutRect.getY();

    layoutRect.origin = newLine.m_rect.origin;

    // Get line metrics
    VfxS32 baseline;
    newLine.m_rect.size = tu.getTextMetrics(
        0,
        -1,
        &m_font,
        -1,
        &retLineCharCount,
        &baseline,
        format,
        (VfxU8)m_wrapStyle,
        VFX_FALSE);

    newLine.m_end = retLineCharCount;

    VfxRect lineBounds = newLine.m_rect;

    switch (alignMode)
    {
    case ALIGN_MODE_RIGHT:
        if (m_layoutRect.getWidth() >= lineBounds.size.width)
        {
            lineBounds.offsetWith(m_layoutRect.getWidth() - lineBounds.size.width, 0);
        }
        break;

    case ALIGN_MODE_CENTER:
        if (m_layoutRect.getWidth() >= lineBounds.size.width)
        {
            lineBounds.origin.x =  m_layoutRect.getMidX() - lineBounds.getWidth()/2;
        }
        break;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    }

    newLine.m_rect = lineBounds;
    newLine.m_baseLine= baseline;
    newLine.m_textHeight = VFX_MAX(minHeight, lineBounds.getHeight());

    // Adjust line bounds by App set height height

    if (lineBounds.getHeight() < minHeight)
    {
        VfxS32 diff = minHeight - lineBounds.getHeight();

        newLine.m_rect.size.height += diff;
        lineBounds.size.height += diff;
        newLine.m_baseLine= VFX_MAX(ascent, baseline);
    }

    if (lineBounds.getHeight() < m_minLineHeight)
    {
        // adjust the line height to the min line height
        newLine.m_rect.size.height += m_minLineHeight - lineBounds.getHeight();
        newLine.m_baseLine += (m_minLineHeight - lineBounds.getHeight());
    }

    if ((m_truncateMode != TRUNCATE_MODE_NONE) && lineBounds.getWidth() > m_layoutRect.getWidth()
        && (m_layoutRect.getWidth() != 0)) /* In the case didn't set the bounds like list menu usage */
    {
        newLine.m_isTruncated = VFX_TRUE;
        newLine.m_rect.size.width = m_layoutRect.getWidth();
    }

    // Add to new line
    m_lines = newLine;

    layoutRect.size.height = m_lines.m_rect.getHeight(); //getMaxY() - layoutRect.getMinY();
    layoutRect.size.width = m_lines.m_rect.getWidth();   //getMaxX() - layoutRect.getMinX();
    
    // vertical alignment
    if (m_layoutRect.getHeight() > layoutRect.size.height)
    {
        VfxS32 heightDiff = 0;
        switch (m_verticalAlignMode)
        {
        case VERT_ALIGN_MODE_MID:
            {
                if ((m_layoutRect.getHeight() - layoutRect.size.height) % 2)
                {
                    heightDiff = (m_layoutRect.getHeight() - layoutRect.size.height) / 2;
                }
                else
                {
                    heightDiff = (m_layoutRect.getHeight() - layoutRect.size.height) / 2 + 1;
                }
            }
            break;
        case VERT_ALIGN_MODE_BOTTOM:
            heightDiff = (m_layoutRect.getHeight() - layoutRect.size.height);
            break;
        default:
            break;
        }
        layoutRect.origin.y += heightDiff;
        m_lines.m_rect.origin.y += heightDiff;
    }

    m_dirty.setRange(0, 0);
    sendLayoutChangedNotification(layoutRect);

    VFX_FREE_MEM(temp_String);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TL1", SA_stop);
#endif
}


void VcpTextSingleLineLayout::setLayoutRect(const VfxRect &rect)
{
    if (m_layoutRect != rect)
    {
        m_dirty.setRange(0, m_storage->getTextLength());
        m_changedCharCount = 0;
        m_layoutRect = rect;
        checkUpdate();
    }
}


VfxS32 VcpTextSingleLineLayout::getLineIndex(VfxS32 index)
{
    return 0;
}


const VfxWChar* VcpTextSingleLineLayout::getLineText(VfxS32 lineIndex, VfxS32 *charCount)
{
    *charCount = m_storage->getTextLength();
    return m_storage->getText();
}


void VcpTextSingleLineLayout::setBatch(VfxBool is_batch)
{
    m_batch = is_batch;
    if (is_batch == VFX_FALSE)
    {
        sendLayoutChangedNotification(m_batchRect);
        m_batchRect.setZero();
    }
}


void VcpTextSingleLineLayout::sendLayoutChangedNotification(VfxRect rect, VfxBool isPost)
{
    if (m_batch)
    {
        if (m_batchRect.isEmpty())
        {
            m_batchRect = rect;
        }
        else
        {
            m_batchRect.unionWith(rect);
        }
    }
    else
    {
       // if (!(rect.isEmpty()))
        {
            if (isPost)
            {
                m_signalLayoutChanged.postEmit(rect);
            }
            else
            {
                m_signalLayoutChanged.emit(rect);
            }
        }
    }
}


/***************************************************************************** 
 * Class VcpTextLine
 *****************************************************************************/

VcpTextLine::VcpTextLine()
{
    m_start = 0;
    m_end = 0;
    m_textHeight = 0;
    m_isTruncated = 0;
    m_baseLine = -1;
}


/***************************************************************************** 
 * Class VcpTextLineBlock
 *****************************************************************************/
VcpTextLineBlock::VcpTextLineBlock(IVfxAllocatable *client)
{
    VcpTextLine *lines;
    VFX_ALLOC_MEM(lines, sizeof(VcpTextLine) * VCP_MAX_TEXT_LINES, client);

    m_client = client;
    m_header = lines;
    m_next = NULL;
}


VcpTextLineBlock::~VcpTextLineBlock()
{
    if (m_header)
    {
        VFX_FREE_MEM(m_header);
        m_header = NULL;
    }
}

  
/***************************************************************************** 
 * Class VcpTextListLine
 *****************************************************************************/

VcpTextListLine::VcpTextListLine()
{
    m_next = NULL;
}
    

VcpTextListLine* VcpTextListLine::appendNext(VcpTextListLine* newLine)
{    
    if (m_next == NULL)
    {
        m_next = newLine;
    }
    else
    {
        VcpTextListLine *pNext = m_next;
        while (pNext->m_next != NULL)
        {
            pNext = pNext->m_next;
        }
        pNext->m_next = newLine;
    }
    return newLine;
}


VcpTextListLine* VcpTextListLine::clear()
{
    VcpTextListLine* next = m_next;
    
    m_start = m_end = 0;
    m_rect.setZero();
    m_next = NULL;

    return next;
}


VcpTextListLine* VcpTextListLine::getLast()
{
    VcpTextListLine* last = this;

    while (last && last->getNext() != NULL)
        last = last->getNext();

    return last;
}


VcpTextListLine* VcpTextListLine::getAfter(VfxS32 n)
{
    VcpTextListLine* line = this;

    while (n--)
    {
        line = line->getNext();
        if (line == NULL)
            return NULL;
    }

    return line;
}

