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
 *  vfx_text_frame.cpp
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "vfx_draw_context.h"
#include "vfx_frame.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_font_desc.h"
#include "vfx_string.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_signal.h"
#include "vrt_system.h"
#include "vfx_system.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "vfx_text_frame.h"

/*
SWLA labels:
TF1   VfxTextFrame::forceUpdate
TF2   VfxTextFrame::updateMultiline
TF3   VfxAdpFontEngine::getStringWidthHeight
TF4   VfxAdpFontEngine::queryStringinfo
*/
#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

extern "C"
{
#ifdef __MMI_BIDI_ALG__
#include "BIDIGProt.h"
#endif
#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif
#include "App_str.h"
#include "PixcomFontEngine.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VFX_TEXTFRAME_NEWLINE_CHARACTER             0x0a
#define VFX_TEXTFRAME_MIN_FONT_SIZE                 13
#define VFX_TEXTFRAME_MAX_CHAR_IN_ONE_LINE          256
#define VFX_TEXTFRAME_MAX_LINE_COUNT                50 
#define VFX_TEXTFRAME_MAX_WIDTH                     1000

/***************************************************************************** 
 * Class VfxTextFrame
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(VFX_TEXT_FRAME_CLASS_NAME, VfxTextFrame, VfxFrame);

VfxTextFrame::VfxTextFrame() :
    m_font(VFX_FONT_DESC_MEDIUM),
    m_orgFont(VFX_FONT_DESC_MEDIUM),
    m_string(VFX_WSTR_NULL),
    m_color(VFX_COLOR_WHITE),
    m_borderColor(VFX_COLOR_BLACK),
    m_alignMode(ALIGN_MODE_LEFT),
    m_truncateMode(TRUNCATE_MODE_NONE),
    m_autoResized(VFX_TRUE),
    m_verticalCenter(VFX_FALSE),
    m_bestFitWidth(VFX_FALSE),
    m_leftMargin(0),
    m_rightMargin(0),
    m_topMargin(0),
    m_bottomMargin(0),
    m_indent(0),
    m_paragraphIndent(0),
    m_lineCountLimit(VFX_TEXTFRAME_MAX_LINE_COUNT),
    m_lineGap(0),
    m_minLineHeight(0),
    m_lineMode(LINE_MODE_SINGLE),
    m_autoFontSize(VFX_FALSE),
    m_lines(NULL),
    m_checkUpdate(VFX_FALSE),
    m_fullyHeight(VFX_TRUE),
    m_noAnimUpdate(VFX_FALSE)
{
}


const VfxWString &VfxTextFrame::getString() const
{
    return m_string;
}


const VfxColor &VfxTextFrame::getColor() const
{
    return m_color;
}


const VfxColor &VfxTextFrame::getBorderColor() const
{
    return m_borderColor;
}


VfxTextFrame::AlignModeEnum VfxTextFrame::getAlignMode() const
{
    return m_alignMode;
}


VfxTextFrame::TruncateModeEnum VfxTextFrame::getTruncateMode() const
{
    return m_truncateMode;
}


VfxBool VfxTextFrame::getAutoResized() const
{
    return m_autoResized;
}


VfxTextFrame::LineModeEnum VfxTextFrame::getLineMode() const
{
    return m_lineMode;
}


VfxS32 VfxTextFrame::getLineCount() const
{
    VfxTextFrame *self = const_cast<VfxTextFrame*>(this);
    self->forceUpdate();
    
    VfxS32 n = 0;
    VfxTextLine* line = m_lines;
    while(line)
    {
        n++;
        line = line->getNext();
    }

    return n;
}


VfxBool VfxTextFrame::getAutoFontResized() const
{
    return m_autoFontSize;
}


void VfxTextFrame::setString(VfxResId id)
{
    setString(VFX_WSTR_RES(id));
}


void VfxTextFrame::setString(const VfxWChar *value)
{
    setString(VFX_WSTR_MEM(value));
}


void VfxTextFrame::setString(const VfxWString &value)
{
    // if the string is from res, although the value is the same it still need checkUpdate
    // Case: change language
    if (m_string != value || (m_string.getResId() != VFX_RES_ID_NULL))
    {
        m_string = value;
        
        checkUpdate();
    }
}


void VfxTextFrame::setVerticalToCenter(VfxBool value)
{
    if (m_verticalCenter!= value)
    {
        m_verticalCenter = value;

        checkUpdate();
    }
}



void VfxTextFrame::setBestFitWidth(VfxBool value)
{
    if (m_bestFitWidth!= value)
    {
        m_bestFitWidth = value;

        checkUpdate();
    }
}


void VfxTextFrame::setColor(const VfxColor &value)
{
    if (m_color != value)
    {
        m_color = value;
        
        checkUpdate();
    }
}


void VfxTextFrame::setBorderColor(const VfxColor &value)
{
    if (m_borderColor != value)
    {
        m_borderColor = value;
        
        checkUpdate();
    }
}


void VfxTextFrame::setAlignMode(AlignModeEnum value)
{
    if (m_alignMode != value)
    {
        m_alignMode = value;
        
        checkUpdate();
    }
}


void VfxTextFrame::setTruncateMode(TruncateModeEnum value)
{
    if (m_truncateMode != value)
    {
        m_truncateMode = value;
        
        checkUpdate();
    }
}


void VfxTextFrame::setAutoResized(VfxBool value)
{
    if (m_autoResized != value)
    {
        m_autoResized = value;
        
        checkUpdate();
    }
}


void VfxTextFrame::setFont(const VfxFontDesc &fontDesc)
{
    if (m_font != fontDesc)
    {
        m_font = m_orgFont = fontDesc;
        
        checkUpdate();
    }
}


VfxRect VfxTextFrame::getMeasureBounds() const
{
    const VfxWChar *string = getString();
    VfxRect oldBounds = VfxFrame::getBounds();
    VfxRect newBounds = oldBounds;
    
    if (m_fullyHeight)
    {
        VfxS32 max_height, ascent, dscent;
        VfxAdpFontEngine adpFont;

        newBounds.size = m_font.measureStr(string);

        adpFont.getCharInfoForAllLang(m_font, &max_height, &ascent, &dscent);

        if (max_height >= newBounds.size.height)
            newBounds.size.height = max_height;
    }
    else
        newBounds.size = m_font.measureStr(string);

    // Keep bounds width if in truncate mode
    if (getTruncateMode() != TRUNCATE_MODE_NONE)
    {
        newBounds.size.width = oldBounds.size.width;
    }
    else
    {
        newBounds.size.width += m_leftMargin + m_rightMargin;
    }

    newBounds.size.height += m_topMargin + m_bottomMargin;
    return newBounds;
}


void VfxTextFrame::setLineMode(LineModeEnum value)
{
    if (m_lineMode != value)
    {
        m_lineMode = value;
        
        checkUpdate();
    }
}


void VfxTextFrame::setAutoFontSize(VfxBool value)
{
    if (m_autoFontSize != value
        || m_autoResized)
    {
        m_autoFontSize = value;
        
        // disable bounds auto resize
        if (m_autoFontSize)
        {
            m_autoResized = VFX_FALSE;
            m_verticalCenter = VFX_TRUE;
        }
        
        checkUpdate();
    }
}


void VfxTextFrame::setMargins(VfxS32 margin)
{
    if (m_leftMargin != margin ||
        m_rightMargin != margin ||
        m_topMargin != margin ||
        m_bottomMargin != margin)
    {
        m_leftMargin = m_rightMargin = m_topMargin = m_bottomMargin = margin;    
        checkUpdate();
    }    
}


void VfxTextFrame::setIndent(VfxS32 value)
{
    if (m_indent != value)
    {
        m_indent = value;
        
        checkUpdate();
    }
}


void VfxTextFrame::setMaxLines(VfxS32 value)
{
    if (m_lineCountLimit != value)
    {
        m_lineCountLimit = value;
        checkUpdate();
    }
}


void VfxTextFrame::setLineGap(VfxS32 value)
{
    if (m_lineGap != value)
    {
        m_lineGap = value;
        checkUpdate();
    }
}


void VfxTextFrame::setMinLineHeight(VfxS32 value)
{
    if (m_minLineHeight != value)
    {
        m_minLineHeight = value;
        checkUpdate();
    }
}


void VfxTextFrame::setFullLineHeightMode(const VfxBool value)
{
    if (m_fullyHeight != value)
    {
        m_fullyHeight = value;
        checkUpdate();
    }
}

void VfxTextFrame::setMargins(VfxS32 leftMargin, VfxS32 topMargin, VfxS32 rightMargin, VfxS32 bottomMargin)
{
    if (m_leftMargin != leftMargin ||
        m_rightMargin != rightMargin ||
        m_topMargin != topMargin ||
        m_bottomMargin != bottomMargin)
    {
        m_leftMargin = leftMargin;
        m_rightMargin = rightMargin;
        m_topMargin = topMargin;
        m_bottomMargin = bottomMargin;
    
        checkUpdate();
    }
}


void VfxTextFrame::setBounds(const VfxRect &value)
{
    if (VfxFrame::getBounds() != value)
    {
        VfxFrame::setBounds(value);

		if (m_autoFontSize)
		{
			// restore font to orginal(app set) when app change bounds
			m_font = m_orgFont;
		}
        
        checkUpdate();
    }
}


const VfxRect &VfxTextFrame::getBounds() const
{
    if (m_autoResized)
    {
        VfxTextFrame *self = const_cast<VfxTextFrame*>(this);
        self->forceUpdate();
    }

    return VfxFrame::getBounds();
}


void VfxTextFrame::onInit()
{
    VfxFrame::onInit();
}


void VfxTextFrame::onDeinit()
{
    resetLineInfo();
    
    VfxFrame::onDeinit();
}


void VfxTextFrame::onDraw(VfxDrawContext &dc)
{
    if (m_lines == NULL)
        return;

    VfxRect bounds = getBoundsWithMargin();

    dc.setClip(bounds);
    dc.setFont(m_font);
    dc.setFillColor(getColor());
    
    if (m_font.effect == VFX_FONT_DESC_EFFECT_BORDER)
    {
        dc.setStrokeColor(getBorderColor());
    }
        
    if (m_lineMode == LINE_MODE_SINGLE)
        drawSingleline(dc);
    else
        drawMultiline(dc);
}


void VfxTextFrame::drawSingleline(VfxDrawContext &dc)
{
    if (m_lines)
    {
        m_lines->draw(dc, getString());
    }
}


void VfxTextFrame::drawMultiline(VfxDrawContext &dc)
{
    if (m_lines == NULL)
        return;

    VfxTextLine* line = m_lines;
    
    while (line)
    {
        line->draw(dc, getString());

        if (line->m_isTruncated)
            break;
        
        line = line->getNext();
    }
}


VfxRect VfxTextFrame::getBoundsWithMargin() const
{
    VfxRect bounds = VfxFrame::getBounds();
    
    bounds.origin.x += m_leftMargin;
    bounds.origin.y += m_topMargin;
    bounds.size.width -= m_leftMargin + m_rightMargin;
    if (bounds.size.width < 0)
        bounds.size.width = 0;

    bounds.size.height -= m_topMargin + m_bottomMargin;
    if (bounds.size.height < 0)
        bounds.size.height = 0;
    return bounds;
}


void VfxTextFrame::checkUpdate()
{
    if (!m_checkUpdate)
    {
        m_checkUpdate = VFX_TRUE;
        vfxPostInvoke0(this, &VfxTextFrame::forceUpdate);
    }

    if (VfxAutoAnimate::getDisable())
    {
        m_noAnimUpdate = VFX_TRUE;
    }
}


void VfxTextFrame::forceUpdate()
{
    VfxBool noAnimation = m_noAnimUpdate;

    if (m_checkUpdate)
    {
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TF1", SA_start);
    #endif
        if (noAnimation)
        {
            m_noAnimUpdate = VFX_FALSE;

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
        }

        m_checkUpdate = VFX_FALSE;
       
        setBasePosInternal(m_basePos);
 
        updateSize();
        updateLayoutInfo();
        invalidate();

        if (noAnimation)
        {
            VfxAutoAnimate::commit();
        }
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TF1", SA_stop);
    #endif
    }
}


void VfxTextFrame::updateSize()
{
    // only for singline mode
    if (getLineMode() != LINE_MODE_SINGLE)
        return;
    
    if (getAutoResized())
    {
        VfxFrame::setBounds(getMeasureBounds());
    }
}


void VfxTextFrame::resetLineInfo()
{
    VfxTextLine* line;
        
    while (m_lines)
    {
        line = m_lines->getNext();
        VFX_DELETE(m_lines);
        m_lines = line;
    }
}


VfxTextFrame::AlignModeEnum VfxTextFrame::convertAlignMode()
{
    AlignModeEnum alignMode = (AlignModeEnum)getAlignMode();
    
    vrt_text_dir_type_enum dir = vrt_sys_get_text_dir();
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


void VfxTextFrame::updateLayoutInfo()
{
    // clear the line information
    resetLineInfo();

    const VfxWChar *string = getString();
    if (string == NULL)
    {
        return;
    }
    
    if (getLineMode() == LINE_MODE_SINGLE)
    {
        // layout singline
        updateSingleline();
    }
    else
    {
        // layout multiline
        updateMultiline();
    }

    if (m_lines == NULL)
        return;

    if (m_autoFontSize)
    {
        if (getLineMode() == LINE_MODE_SINGLE
            && m_lines
            && (m_lines->m_rect.getHeight() > getBounds().getHeight() 
                || m_lines->m_rect.getWidth() > getBounds().getWidth()))
        {
            // try to change font size
            if (decFontSize())
                updateLayoutInfo();
            else
                return;
        }
        else if (m_lines && m_lines->getLast()->m_isTruncated)
        {
            // try to change font size
            if (decFontSize())
                updateLayoutInfo();
            else
                return;
        }
    }
    else if (getAutoResized() && getLineMode() == LINE_MODE_MULTI)
    {
        VfxRect bounds = getBoundsWithMargin();
        VfxTextLine *line = NULL; 
        
        if (m_lineCountLimit > 0)
        {
            // seek the line to the max limitation
            line = m_lines->getAfter(m_lineCountLimit - 1);
        }

        if (line == NULL)
        {
            // line count < max limitation
            line = m_lines->getLast();
        }

        if (line->getNext() != NULL)
        {
            // set this line to truncate mode
            line->m_isTruncated = 1;
            line->m_rect.size.width --;
        }

        if (bounds.intersectWith(line->m_rect) == line->m_rect)
        {
            // try to contract frame
            bounds = getBoundsWithMargin();
            
            VfxS32 y1 = bounds.origin.y + bounds.size.height;
            VfxS32 y2 = line->m_rect.origin.y + line->m_rect.size.height;

            bounds.size.height -= y1 - y2;
        }
        else
        {
            // try to enlarge frame for multiline text
            bounds = getBoundsWithMargin();
            
            // enlarge height to whole text height
            bounds.unionWith(line->m_rect);
        }
        
        bounds.offsetWith(-m_leftMargin, -m_topMargin);
        if (m_bestFitWidth)
        {
            bounds.size.width = m_lines->getMaxWidth() < bounds.size.width ? m_lines->getMaxWidth() : bounds.size.width;
        }
        bounds.size.width += m_leftMargin + m_rightMargin;
        bounds.size.height += m_topMargin + m_bottomMargin;

        VfxFrame::setBounds(bounds);
    }
    else if (m_verticalCenter && getLineMode() == LINE_MODE_MULTI)
    {
        // verticial center align
        VfxS32 boundsHeight = getBoundsWithMargin().getHeight();    
        VfxS32 totalHeight = m_lines->getLast()->m_rect.getMaxY() - m_lines->m_rect.getMinY() + 1;
        if (boundsHeight > totalHeight)
        {
            VfxS32 hOffset = (boundsHeight - totalHeight) >> 1;
            VfxTextLine *line = m_lines;
            while (line)
            {
                line->m_rect.origin.y += hOffset;
                line = line->getNext();
            }
        }
    }
}


VfxBool VfxTextFrame::decFontSize()
{
    if (m_font.size & 0x80)
    {
        //vector font
        if ((m_font.size & 0x7F) <= VFX_TEXTFRAME_MIN_FONT_SIZE)
            return VFX_FALSE;
    }
    else
    {
        //bitmap font
        if (m_font.size <= VFX_FONT_DESC_SIZE_SMALL)
            return VFX_FALSE;
    }

    m_font.size--;
    return VFX_TRUE;
}

void VfxTextFrame::updateMultiline()
{
    const VfxWChar *string = getString();
    VfxS32 offsetIndex = 0, offsetY = 0;
    VfxS32 indent = 0;
    VfxAdpFontEngine adpFont;
    VfxBool endLoop = VFX_FALSE;
    VfxS32 max_height, ascent, dscent;
    
    if (*string == 0)
        return;
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TF2", SA_start);
#endif    
    // get base line height
    adpFont.getCharInfoForCommonLang(m_font, &max_height, &ascent, &dscent);

    // update the bounds by margin
    VfxRect bounds = getBoundsWithMargin();

    if (bounds.getWidth() <= 0)
    {
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TF2", SA_stop);
    #endif 
        return;
    }

    // get the line height
    VfxSize strSize = m_font.measureStr(string);
    vrt_text_dir_type_enum dir = vrt_sys_get_text_dir();
    AlignModeEnum alignMode = convertAlignMode();
    
    const VfxWChar *lineStart = string;

    // layouted line count
    VfxS32 layoutLineCnt = 0;

    while (offsetIndex < (VfxS32)getString().getLength()
        && !endLoop)
    {
        VfxTextLine* newLine;
        VfxU32 lineCount, maxCount = getString().getLength() - offsetIndex;
        VfxS32 width, height, lineAscent;
        
        //create a new line info
        VFX_ALLOC_NEW(newLine, VfxTextLine, this);

        // set the line bounds
        newLine->m_start = newLine->m_end = offsetIndex;
        newLine->m_rect = bounds;
        newLine->m_rect.origin.y += offsetY;
        newLine->m_rect.size.height = strSize.height;

        if (offsetIndex == 0)
            indent = m_indent;
        else
            indent = 0;

        VfxFont v_font;
        m_font.initVrtFont(v_font);
        adpFont.setFont(&v_font);
        mmi_fe_get_string_info_param_struct tempQuery;
        memset(&tempQuery, 0, sizeof(mmi_fe_get_string_info_param_struct));
        tempQuery.String = (VfxU8 *)lineStart;
        tempQuery.n = maxCount;
        tempQuery.enableTruncated = MMI_TRUE;
        tempQuery.checkCompleteWord = 1;
        tempQuery.checklinebreak = 1;
        tempQuery.targetWidth = newLine->m_rect.getWidth() - indent;
        lineCount = adpFont.queryStringinfo(&tempQuery);
        width = tempQuery.pWidth;
        height = tempQuery.pHeight;
        lineAscent = tempQuery.baseline;

        if (v_font.border && lineCount > 0)
        {
            width += 2;
            height += 2;
        }
        
        // after line break, should get the text width height again to get it's real width height after BIDI 
        // which is the same as display
#if defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__)
        if (bidi_is_need_bidi((U8 *)lineStart, lineCount))
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
            VfxS32 targetWidth = newLine->m_rect.getWidth() - indent;
            VfxS32 queryLen = lineCount;
            mmi_fe_get_string_info_param_struct query;
            memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
            do
            {
                query.String = (VfxU8 *)lineStart;
                query.n = queryLen;
                query.w = 0;
                query.enableTruncated = MMI_TRUE;
                query.targetWidth = targetWidth;
                adpFont.queryStringinfo(&query);

                counter++;
                if (query.pWidth > targetWidth)
                {
                    queryLen--;
                }
                else
                {
                    break;
                }

                // break in case of infinit loop
                if (counter > 5)
                {
                    break;
                }
            } while (1);
            lineCount = queryLen;
            width = query.pWidth;
            height = query.pHeight;
            lineAscent = query.baseline;
        }
#endif
        
        if (lineCount == 0)
        {
            VfxSize size = m_font.measureStr((const VfxWChar *)L"...");

            lineCount = 1;
            width = size.width;
        }
        else
        {
            if (FONT_TEST_NEW_LINE_CHAR(*(lineStart + lineCount)))
            {
                // count newline symbol
                lineCount += app_ucs2_is_newline((VfxWChar *)(lineStart + lineCount));;
            }
        }

        newLine->m_end += lineCount;
        offsetIndex += lineCount;

        VfxRect lineBounds = newLine->m_rect;
        lineBounds.origin.y += strSize.height - newLine->m_rect.size.height;
        lineBounds.size.width = width;
        lineBounds.size.height = height;

        switch (alignMode)
        {
        case ALIGN_MODE_LEFT:
           lineBounds.offsetWith(indent, 0);
           break;

        case ALIGN_MODE_RIGHT:
           lineBounds.offsetWith(newLine->m_rect.size.width - lineBounds.size.width, 0);
        
           if (dir == MG_TEXT_DIR_TYPE_R2L)
           {
                lineBounds.offsetWith(-indent, 0);
           }
           break;

        case ALIGN_MODE_CENTER:
           lineBounds.origin.x =  newLine->m_rect.getMidX() - lineBounds.getWidth()/2;
           break;

        case ALIGN_MODE_CENTER_WITHIN_MARGIN:
           lineBounds.origin.x =  newLine->m_rect.getMidX() - lineBounds.getWidth()/2;
           break;
        }

        newLine->m_rect = lineBounds;

        if (lineBounds.getHeight() < max_height)
        {
            VfxS32 diff = max_height - lineBounds.getHeight();

            // if line real descent > common language descent, should use line real descent to avoid cut from bottom
            if (max_height - ascent <  lineBounds.getHeight() - lineAscent)
            {
                newLine->m_baseLine = (lineAscent + diff);
            }
            else
            {
                if (ascent < lineAscent)
                    newLine->m_baseLine = lineAscent;
                else
                    newLine->m_baseLine = ascent;
            }
            newLine->m_rect.size.height += diff;
            lineBounds.size.height += diff;
        }

        if (lineBounds.getHeight() < m_minLineHeight)
        {
            // adjust the line height to the min line height
            newLine->m_offsetY += m_minLineHeight - lineBounds.getHeight();
            newLine->m_rect.size.height += m_minLineHeight - lineBounds.getHeight();
        }

        if (offsetIndex < (VfxS32)getString().getLength()
            && offsetY + 2 * newLine->m_rect.size.height > bounds.getHeight())
        {
            if (!getAutoResized())
            {
                // new line can't be display completedly. truncate this line
                newLine->m_isTruncated = 1;
               // newLine->m_end = getString().getLength();
                endLoop = VFX_TRUE;
            }
        }

        offsetY += newLine->m_rect.getHeight() + m_lineGap;
        lineStart = string + offsetIndex;

        if (m_lines == NULL)
            m_lines = newLine;
        else
            m_lines->appendNext(newLine);

        layoutLineCnt++;

        if (layoutLineCnt > m_lineCountLimit)
        {
            break;
        }
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TF2", SA_stop);
#endif 
}

void VfxTextFrame::updateSingleline()
{
    VfxAdpFontEngine adpFont;
    const VfxWChar *string = getString();

    //create a new line info
    VFX_ALLOC_NEW(m_lines, VfxTextLine, this);

    // for singline mode, all characters are to be shown
    m_lines->m_start = m_lines->m_end = -1;
    
    AlignModeEnum alignMode = convertAlignMode();
    vrt_text_dir_type_enum dir = vrt_sys_get_text_dir();
    TruncateModeEnum truncateMode = (TruncateModeEnum)getTruncateMode();
    
    VfxFont v_font;
    m_font.initVrtFont(v_font);
    mmi_fe_get_string_info_param_struct query;
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = (VfxU8 *)string;
    query.n = vfx_sys_wcslen(string);
    query.w = 0;
    query.enableTruncated = MMI_FALSE;
    query.targetWidth = -1;
    adpFont.setFont((const VfxFont *)&v_font);
    adpFont.queryStringinfo(&query);

    if (v_font.border && query.n > 0)
    {
        query.pWidth += 2;
        query.pHeight += 2;
        query.maxDescent++;
    }

    // Caculate the string size, tuncate the size if needed
    VfxSize strSize = VfxSize(query.pWidth, query.pHeight);
    
    // update the bounds by margin
    VfxRect bounds = getBoundsWithMargin();
    
    m_lines->m_rect = bounds;
    
    if (truncateMode != TRUNCATE_MODE_NONE)
    {
        if (strSize.width + m_indent > bounds.getWidth())
        {
            strSize.width = bounds.getWidth() - m_indent;
            m_lines->m_isTruncated = VFX_TRUE;
        }
    }

    if (m_fullyHeight)
    {
        VfxS32 max_height, ascent, dscent;
        
        adpFont.getCharInfoForAllLang(m_font, &max_height, &ascent, &dscent);

        if (max_height >= strSize.height)
        {
            strSize.height = max_height;
            m_lines->m_baseLine = ascent;

            if (query.baseline > ascent)
            {
                // use string real baseline to avoid the special character cut on top like character with tone marker
                m_lines->m_baseLine = query.baseline;
            }
            else if (query.maxDescent > dscent)
            {
                // use string real descent to calculate the baseline to avoid the special character cut on bottom like Malyalam chars
                m_lines->m_baseLine = max_height - query.maxDescent;
            }
        }
    }

    if (bounds.size.height < strSize.height)
        bounds.size.height = strSize.height;
    
    m_lines->m_rect.size.width = strSize.width;
     
    switch (alignMode)
    {
    case ALIGN_MODE_LEFT:
        m_lines->m_rect.offsetWith(m_indent, 0);
        break;
        
    case ALIGN_MODE_RIGHT:
        m_lines->m_rect.offsetWith(bounds.size.width - strSize.width, 0);
        
        if (dir == MG_TEXT_DIR_TYPE_R2L)
        {
            m_lines->m_rect.offsetWith(-m_indent, 0);
        }
        break;
        
    case ALIGN_MODE_CENTER:
        {
            VfxS32 center_x = VfxFrame::getBounds().getMidX();
            
            if (center_x < bounds.getMinX())
            {
                // center axis is hidden to the left margin
                m_lines->m_rect.origin.x = bounds.getMinX();
            }
            else if (center_x > bounds.getMaxX())
            {
                // center axis is hidden to the right margin
                m_lines->m_rect.offsetWith(bounds.size.width - strSize.width, 0);
            }
            else
            {
                VfxS32 left_side = center_x - bounds.getMinX();
                VfxS32 right_side = bounds.getMaxX() - center_x;
                
                if (strSize.width + m_indent > bounds.getWidth())
                {
                    if (left_side > right_side)
                    {
                        m_lines->m_rect.offsetWith(bounds.size.width - strSize.width, 0);
                    }
                }
                if ((strSize.width + m_indent)/2 <= VFX_MIN(left_side, right_side))
                {
                    // align to the center
                    m_lines->m_rect.origin.x = center_x - (strSize.width + m_indent)/2;
                }
                else if ((strSize.width + m_indent)/2 > left_side)
                {
                    // align to the left side
                    if (dir == MG_TEXT_DIR_TYPE_R2L)
                    {
                        m_lines->m_rect.offsetWith(m_indent, 0);
                    }
                }
                else if ((strSize.width + m_indent)/2 > right_side)
                {
                    // align to the right side
                    m_lines->m_rect.offsetWith(bounds.size.width - strSize.width, 0);
                    
                    if (dir == MG_TEXT_DIR_TYPE_R2L)
                    {
                        m_lines->m_rect.offsetWith(-m_indent, 0);
                    }
                }
            } 
        }
        break;
        
    case ALIGN_MODE_CENTER_WITHIN_MARGIN:
        m_lines->m_rect.origin.x =  bounds.getMidX() - m_lines->m_rect.getWidth()/2;
        break;
    }

    // adjust y to center
    if (m_verticalCenter && (bounds.size.height > strSize.height))
    {
        VfxS32 offset_y = (bounds.size.height - strSize.height) & 0x1;

        m_lines->m_rect.offsetWith(0, (bounds.size.height - strSize.height)/2 + offset_y);
    }
}


/***************************************************************************** 
 * Class VfxTextLine
 *****************************************************************************/

VfxTextLine::VfxTextLine() :
    m_start(0),
    m_end(0),
    m_rect(0, 0, 0, 0),
    m_offsetY(0),
    m_isTruncated(VFX_FALSE),
    m_baseLine(-1),
    m_next(NULL)
{
    
}
    

VfxTextLine* VfxTextLine::appendNext(VfxTextLine* newLine)
{    
    if (m_next == NULL)
    {
        m_next = newLine;
    }
    else
    {
        VfxTextLine *pNext = m_next;

        while (pNext->m_next != NULL)
        {
            pNext = pNext->m_next;
        }

        pNext->m_next = newLine;
    }

    return newLine;
}


VfxTextLine* VfxTextLine::clear()
{
    VfxTextLine* next = m_next;
    
    m_start = m_end = 0;
    m_rect.setZero();
    m_next = NULL;

    return next;
}


VfxTextLine* VfxTextLine::getLast() const
{
    VfxTextLine* last = const_cast<VfxTextLine*>(this);

    while (last->getNext() != NULL)
        last = last->getNext();

    return last;
}


VfxS32 VfxTextLine::getMaxWidth() const 
{
    VfxTextLine* last = const_cast<VfxTextLine*>(this);
    VfxS32 width = 0;

    while (last != NULL)
    {
        if (width < last->m_rect.size.width)
        {
            width = last->m_rect.size.width;
        }
        last = last->getNext();
    }

    return width;
}


VfxTextLine* VfxTextLine::getAfter(VfxS32 n)
{
    VfxTextLine* line = this;

    while (n--)
    {
        line = line->getNext();
        if (line == NULL)
            return NULL;
    }

    return line;
}


void VfxTextLine::draw(VfxDrawContext &dc, const VfxWChar *string)
{
    VfxS32 count;
    vrt_text_dir_type_enum dir = vrt_sys_get_text_dir();
    VfxWChar* s = (VfxWChar*)string;
    VfxWChar* temp_String = NULL;

    if (m_start >=0 && m_end >=0)
    {
        count = m_end - m_start;  
        s = (VfxWChar*)string + m_start;
    }
    else
        count = vfx_sys_wcslen(s);

    if (m_isTruncated && vfx_sys_wcslen(s) > VFX_TEXTFRAME_MAX_CHAR_IN_ONE_LINE)
    {
        VFX_SYS_ALLOC_MEM(temp_String, VFX_TEXTFRAME_MAX_CHAR_IN_ONE_LINE*sizeof(VfxWChar));

        memcpy(temp_String, s, (VFX_TEXTFRAME_MAX_CHAR_IN_ONE_LINE - 1)*sizeof(VfxWChar));
        temp_String[VFX_TEXTFRAME_MAX_CHAR_IN_ONE_LINE - 1] = 0;
        s = temp_String;
    }
    
    if (dir == MG_TEXT_DIR_TYPE_L2R)
    {
        if (m_isTruncated)
        {
            if (count > 1)
            {
                dc.setEllipsis(VFX_WSTR("...")); 
                if (m_baseLine >= 0)
                {
                    VfxRect textRect = m_rect;
                    textRect.origin.y += m_offsetY;
                    textRect.size.height -= m_offsetY;
                    dc.drawTextTruncatedBaseline(textRect, s, m_rect.getWidth() - 1, m_baseLine);
                }
                else
                {
                    dc.drawTextTruncated(m_rect.origin.x, m_rect.origin.y + m_offsetY, s, m_rect.getWidth() - 1);
                }
            }
            else
            {
                dc.drawText(m_rect.origin.x, m_rect.getMidY(), (const VfxWChar *)L"...");
            }
        }
        else
        {
            if (m_baseLine >= 0)
            {
                VfxRect textRect = m_rect;
                textRect.origin.y += m_offsetY;
                textRect.size.height -= m_offsetY;
                dc.drawTextBaseline(textRect, m_baseLine, s, count);
            }
            else
                dc.drawText(m_rect.origin.x, m_rect.origin.y + m_offsetY, s, count);
        }
    }
    else
    {
        VfxPoint point = m_rect.origin;
        
        point.x += m_rect.size.width - 1;
        point.y += m_offsetY;

        if (m_isTruncated)
        {
            if (count > 1)
            {
                dc.setEllipsis(VFX_WSTR("..."));
                if (m_baseLine >= 0)
                {
                    VfxRect textRect = m_rect;
                    textRect.origin = point;
                    textRect.size.height -= m_offsetY;
                    dc.drawTextTruncatedBaseline(textRect,s, m_rect.getWidth() - 1, m_baseLine);
                }
                else
                    dc.drawTextTruncated(point, s, m_rect.getWidth() - 1);
            }
            else
            {
                point.y += m_rect.getHeight()/2;
                dc.drawText(point, VFX_WSTR("..."));
            }
        }
        else
        {
            if (m_baseLine >= 0)
            {
                VfxRect textRect = m_rect;
                textRect.origin = point;
                textRect.size.height -= m_offsetY;
                dc.drawTextBaseline(textRect, m_baseLine, s, count);
            }
            else
                dc.drawText(point, s, count);
        }
    } 

    if (temp_String != NULL)
    {
        VFX_FREE_MEM(temp_String);
    }
}


void VfxAdpFontEngine::getCharInfoForAllLang(const VfxFontDesc &font, VfxS32 *pHeight, VfxS32 *pAscent, VfxS32 *pDescent)
{
    mmi_fe_get_string_info_param_struct query;

    static VfxS32 ascent = 0, dscent = 0, height = 0;
    static VfxFontDesc s_font;

//#if defined(__MMI_LANG_SM_CHINESE__)
    static const VfxWChar measureString[] = {0x0041, 0x0067, 0x0068, 0x5BB6, 0}; /* 'Agh' */
//#elif defined(__MMI_LANG_HK_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__)
    //static const VfxWChar measureString[] = {0x0041, 0x0067, 0x570B, 0}; /* 'Ag' */
//#else
    //static const VfxWChar measureString[] = {0x0041, 0x0067, 0}; /* 'Ag' */
//#endif

    if (s_font == font && height != 0)
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

    VfxFont v_font;
    font.initVrtFont(v_font);

    SetFont((*((stFontAttribute *)&v_font)), 0);
    mmi_fe_get_string_widthheight(&query);

    if (v_font.border)
    {
        query.pHeight += 2;
        query.maxDescent++;
    }

    s_font = font;
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


void VfxAdpFontEngine::getCharInfoForCommonLang(const VfxFontDesc &font, VfxS32 *pHeight, VfxS32 *pAscent, VfxS32 *pDescent)
{
    static VfxS32 ascent = 0, dscent = 0, height = 0;
    static VfxFontDesc s_font;

    // cache
    if (s_font == font && height != 0)
    {
        if (pAscent != NULL)
            *pAscent = ascent;

        if (pDescent != NULL)
            *pDescent = dscent;

        if (pHeight != NULL)
            *pHeight = height;

        return;
    }

    mmi_fe_get_char_info_of_common_lang(font.size, &height, &ascent, &dscent);

    VfxFont v_font;
    font.initVrtFont(v_font);
    if (v_font.border)
    {
        height += 2;
        dscent++;
    }

    s_font = font;

    if (pAscent != NULL)
        *pAscent = ascent;

    if (pDescent != NULL)
        *pDescent = dscent;

    if (pHeight != NULL)
        *pHeight = height;
}


void VfxTextFrame::setBasePos(const VfxPoint pos)
{
    m_basePos = pos;

    checkUpdate();
}


void VfxTextFrame::setBasePosInternal(const VfxPoint pos)
{
    if (pos.isZero())
        return;

    VfxS32 baseline = 0;
    VfxAdpFontEngine adpFont;
    if (m_lineMode == LINE_MODE_SINGLE)
    {
        setFullLineHeightMode(VFX_FALSE);
        const VfxWChar *string = getString();
        VfxFont v_font;
        m_font.initVrtFont(v_font);
        mmi_fe_get_string_info_param_struct query;
        memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
        query.String = (VfxU8 *)string;
        query.n = vfx_sys_wcslen(string);
        query.w = 0;
        query.enableTruncated = MMI_FALSE;
        query.targetWidth = -1;
        adpFont.setFont((const VfxFont *)&v_font);
        adpFont.queryStringinfo(&query);
        baseline = query.baseline;
    }
    else
    {
        VfxS32 max_height, dscent;
        adpFont.getCharInfoForCommonLang(m_font, &max_height, &baseline, &dscent);
    }

    setPos(pos.x, pos.y - baseline);
}
