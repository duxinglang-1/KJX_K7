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
 *  vcp_matrix_scr.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Internal UI componets of home screen application category
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VUI_MAINMENU__
#include "vfx_uc_include.h"
#include "vcp_matrix_item.h"

#include "vfx_cpp_base.h"
#include "vfx_control.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_primitive_frame.h"
#include "vfx_basic_type.h"
#include "vfx_text_frame.h"
#include "vfx_signal.h"
#include "vfx_frame.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vrt_datatype.h"
#include "vfx_font_desc.h"


/***************************************************************************** 
 * Global Function
 *****************************************************************************/
VcpSimpleMatrixIcon::VcpSimpleMatrixIcon():
    m_nRow(0),
    m_nColumn(0),
    m_isHighlighted(VFX_FALSE),
    m_text(NULL),
    m_image(NULL)
{
}


void VcpSimpleMatrixIcon::onInit()
{    
    VfxControl::onInit();
    
    VFX_OBJ_CREATE(m_image, VfxImageFrame, this);
    m_image->setAnchor(VfxFPoint(0.5F, 0.5F));
    VFX_OBJ_CREATE(m_text, VfxTextFrame, this);
    m_text->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_text->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_signalBoundsChanged.connect(this, &VcpSimpleMatrixIcon::onBoundsValueChange);
    
}


void VcpSimpleMatrixIcon::onBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds)
{
    //VFX_UNUSED(args);
    VFX_UNUSED(source);
    VFX_UNUSED(oldBounds);
    
    VfxRect rect = getBounds();

    if (m_isHighlighted == VFX_TRUE)
    {
        m_text->setPos(VfxPoint(MATRIX_ICON_HIGHLIGHT_X, rect.size.height - MATRIX_ICON_TEXT_HEIGHT - MATRIX_ICON_HIGHLIGHT_Y));
        m_text->setBounds(VfxRect(VFX_POINT_ZERO, VfxSize(rect.size.width - MATRIX_ICON_HIGHLIGHT_X * 2, MATRIX_ICON_TEXT_HEIGHT)));
        m_image->setPos(VfxPoint(rect.size.width / 2, rect.size.height / 2));
    }
    else
    {
        m_text->setPos(VfxPoint(0, rect.size.height - MATRIX_ICON_TEXT_HEIGHT));
        m_text->setBounds(VfxRect(VFX_POINT_ZERO, VfxSize(rect.size.width, MATRIX_ICON_TEXT_HEIGHT)));
        m_image->setPos(VfxPoint(rect.size.width / 2, rect.size.height / 2 - MATRIX_ICON_Y));
    }
}


void VcpSimpleMatrixIcon::onDeinit()
{       
    VfxControl::onDeinit();
}


void VcpSimpleMatrixIcon::updateString(const VfxWString &text)
{   
    m_text->setString(text);
    m_text->setColor(VFX_COLOR_WHITE);
    m_text->setBorderColor(VFX_COLOR_BLACK);
    m_text->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_SMALL));
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    VfxFontDesc font;
    font.size = 0x80|MEDIUM_FONT_SIZE;
    font.effect = VFX_FONT_DESC_EFFECT_BORDER;

    VfxSize size = font.measureStr(text.getBuf());
    VfxRect rect;
    if (m_isHighlighted)
    {
        rect.size.width = MATRIX_ICON_HIGHLIGHT_TEXT_WIDTH;
    }
    else
    {
        rect = getBounds();
    }
    while (rect.size.width < size.width)
    {
        font.size -= 1;
        if (font.size <= 0x80)
        {
             font.size = 0x80;
             break;
        }
        size = font.measureStr(text.getBuf());
    }
    m_text->setFont(font);

#endif
}

#endif
