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
 *  vcp_sel_box.cpp
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  Selection Box class (for input method)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C"
{
    #include "MMI_features.h"
}

#include "vcp_sel_box.h"

extern "C"
{
    #include "Word_engine.h"
}

#include "vfx_adp_device.h"
/***************************************************************************** 
 * Defination
 *****************************************************************************/

/* TODOIMEV3  change with artist size */
     #if defined(__MMI_MAINLCD_240X320__)
    #define VCP_SEL_BOX_FTE_EXPAND_BUTTON_WIDTH                     38
    #elif defined(__MMI_MAINLCD_240X400__)
    #define VCP_SEL_BOX_FTE_EXPAND_BUTTON_WIDTH                     40
    #elif defined(__MMI_MAINLCD_320X480__)
    #define VCP_SEL_BOX_FTE_EXPAND_BUTTON_WIDTH                     52
    #elif defined(__MMI_MAINLCD_320X240__)
    #define VCP_SEL_BOX_FTE_EXPAND_BUTTON_WIDTH                     52
    #elif defined(__MMI_MAINLCD_480X800__)
    #define VCP_SEL_BOX_FTE_EXPAND_BUTTON_WIDTH                     54
    #endif





#if defined(__MMI_IME_FTE_ENHANCE__)
    #if defined(__MMI_MAINLCD_240X320__)
    #define VCP_SEL_BOX_FTE_ARROW_WIDTH                     28
    #elif defined(__MMI_MAINLCD_240X400__)
    #define VCP_SEL_BOX_FTE_ARROW_WIDTH                     30
    #elif defined(__MMI_MAINLCD_320X480__)
    #define VCP_SEL_BOX_FTE_ARROW_WIDTH                     32
    #elif defined(__MMI_MAINLCD_320X240__)
    #define VCP_SEL_BOX_FTE_ARROW_WIDTH                     32
    #elif defined(__MMI_MAINLCD_480X800__)
    #define VCP_SEL_BOX_FTE_ARROW_WIDTH                     44
    #else
    #error "This resolution doesn't support FTE" 
    #endif
#else
    #if defined(__MMI_TOUCH_SCREEN__)
    #define VCP_SEL_BOX_NO_FTE_ARROW_WIDTH                  8
    #define VCP_SEL_BOX_NO_FTE_ARROW_HEIGHT                 14
    #else
    #define VCP_SEL_BOX_NO_FTE_ARROW_WIDTH                  3
    #define VCP_SEL_BOX_NO_FTE_ARROW_HEIGHT                 6
    #endif
    #define VCP_SEL_BOX_NO_FTE_ARROW_SPACING                2
#endif

#define VCP_SEL_BOX_STAR_SPACING                            1

#if defined(__MMI_IME_FTE_ENHANCE__)
#define VCP_SEL_BOX_FTE_SEPERATOR_WIDTH                     1
#endif

#define VCP_SEL_BOX_LABEL_SPACING                           1

#if defined(__MMI_IME_FTE_ENHANCE__)
    #if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__)
    #define VCP_SEL_BOX_CAND_SPACING                        10
    #elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)
    #define VCP_SEL_BOX_CAND_SPACING                        15
    #elif defined(__MMI_MAINLCD_320X240__) 
    #define VCP_SEL_BOX_CAND_SPACING                        15
    #else
    #error "This resolution doesn't support FTE" 
    #endif
#else
    #define VCP_SEL_BOX_CAND_SPACING                        1
#endif

#if defined(__MMI_MAINLCD_480X800__)
    #define VCP_SEL_BOX_HEIGHT_SPACING                      4
#else
    #define VCP_SEL_BOX_HEIGHT_SPACING                      2
#endif

#define VCP_SEL_BOX_BORDER_WIDTH                            1
#if defined(__MMI_IME_FTE_ENHANCE__)
#define VCP_SEL_BOX_FTE_EXTER_BORDER_WIDTH                  3
#endif

#if defined(__MMI_IME_FTE_ENHANCE__)
    #if defined(__MMI_MAINLCD_240X320__)
    #define VCP_SEL_BOX_FTE_HEIGHT_SMALL                    28
    #define VCP_SEL_BOX_FTE_HEIGHT_MEDIUM                   34
    #define VCP_SEL_BOX_FTE_HEIGHT_LARGE                    40
    #elif defined(__MMI_MAINLCD_240X400__)
    #define VCP_SEL_BOX_FTE_HEIGHT_SMALL                    32
    #define VCP_SEL_BOX_FTE_HEIGHT_MEDIUM                   38
    #define VCP_SEL_BOX_FTE_HEIGHT_LARGE                    46  
    #elif defined(__MMI_MAINLCD_320X480__)
    #define VCP_SEL_BOX_FTE_HEIGHT_SMALL                    32
    #define VCP_SEL_BOX_FTE_HEIGHT_MEDIUM                   38
    #define VCP_SEL_BOX_FTE_HEIGHT_LARGE                    46
    #elif defined(__MMI_MAINLCD_320X240__)
    #define VCP_SEL_BOX_FTE_HEIGHT_SMALL                    32
    #define VCP_SEL_BOX_FTE_HEIGHT_MEDIUM                   38
    #define VCP_SEL_BOX_FTE_HEIGHT_LARGE                    46
    #elif defined(__MMI_MAINLCD_480X800__)
    #define VCP_SEL_BOX_FTE_HEIGHT_SMALL                    48
    #define VCP_SEL_BOX_FTE_HEIGHT_MEDIUM                   63
    #define VCP_SEL_BOX_FTE_HEIGHT_LARGE                    73
    #else
        #error "This resolution doesn't support FTE" 
    #endif
#endif

#if defined(__MMI_IME_FTE_ENHANCE__)
    #if defined(__MMI_MAINLCD_240X320__)
    #define VCP_SEL_BOX_FTE_MIN_CAND_WIDTH                  28
    #elif defined(__MMI_MAINLCD_240X400__)
    #define VCP_SEL_BOX_FTE_MIN_CAND_WIDTH                  30
    #elif defined(__MMI_MAINLCD_320X480__)
    #define VCP_SEL_BOX_FTE_MIN_CAND_WIDTH                  32
    #elif defined(__MMI_MAINLCD_320X240__)
    #define VCP_SEL_BOX_FTE_MIN_CAND_WIDTH                  32
    #elif defined(__MMI_MAINLCD_480X800__)
    #define VCP_SEL_BOX_FTE_MIN_CAND_WIDTH                  31
    #else
        #error "This resolution doesn't support FTE" 
    #endif
#endif

#if !defined(__MMI_IME_FTE_ENHANCE__)
    #if defined(__MMI_TOUCH_SCREEN__)
    #define VCP_SEL_BOX_NO_FTE_CAND_GAP                     0
    #else
    #define VCP_SEL_BOX_NO_FTE_CAND_GAP                     1
    #endif
#endif

#if defined(__MMI_IME_USER_DATABASE__)
    #define VCP_SEL_BOX_USER_DATABASE_NEW_WORD              ((VfxWChar)(0xffff))
#endif

#if defined(__MMI_IME_FTE_ENHANCE__)
    #define VCP_RESIZABLE_COMPOSITION_BOX_SPACING                   8
    #define VCP_RESIZABLE_COMPOSITION_BOX_TOP_GAP                   1
    #if defined(__MMI_MAINLCD_240X320__)
        #define VCP_RESIZABLE_COMPOSITION_BOX_HEIGHT_SMALL          32
        #define VCP_RESIZABLE_COMPOSITION_BOX_HEIGHT_MEDIUM         38
        #define VCP_RESIZABLE_COMPOSITION_BOX_HEIGHT_LARGE          44
        #define VCP_RESIZABLE_COMPOSITION_BOX_TEXT_X_OFFSET          2 
    #elif defined(__MMI_MAINLCD_240X400__)
        #define VCP_RESIZABLE_COMPOSITION_BOX_HEIGHT_SMALL          36
        #define VCP_RESIZABLE_COMPOSITION_BOX_HEIGHT_MEDIUM         42
        #define VCP_RESIZABLE_COMPOSITION_BOX_HEIGHT_LARGE          50 
         #define VCP_RESIZABLE_COMPOSITION_BOX_TEXT_X_OFFSET         2
   #elif defined(__MMI_MAINLCD_320X240__)
        #define VCP_RESIZABLE_COMPOSITION_BOX_HEIGHT_SMALL          32
        #define VCP_RESIZABLE_COMPOSITION_BOX_HEIGHT_MEDIUM         38
        #define VCP_RESIZABLE_COMPOSITION_BOX_HEIGHT_LARGE          44
        #define VCP_RESIZABLE_COMPOSITION_BOX_TEXT_X_OFFSET          2 

    #elif defined(__MMI_MAINLCD_320X480__)
        #define VCP_RESIZABLE_COMPOSITION_BOX_HEIGHT_SMALL          36
        #define VCP_RESIZABLE_COMPOSITION_BOX_HEIGHT_MEDIUM         42
        #define VCP_RESIZABLE_COMPOSITION_BOX_HEIGHT_LARGE          50
         #define VCP_RESIZABLE_COMPOSITION_BOX_TEXT_X_OFFSET         2 
    #elif defined(__MMI_MAINLCD_480X800__)
        #define VCP_RESIZABLE_COMPOSITION_BOX_HEIGHT_SMALL          54
        #define VCP_RESIZABLE_COMPOSITION_BOX_HEIGHT_MEDIUM         70
        #define VCP_RESIZABLE_COMPOSITION_BOX_HEIGHT_LARGE          80
         #define VCP_RESIZABLE_COMPOSITION_BOX_TEXT_X_OFFSET         2 
    #else
        #error "This resolution doesn't support FTE" 
    #endif
#endif


/***************************************************************************** 
 * Class VcpSelBoxArrow
 *****************************************************************************/
void VcpSelBoxArrow::setState(VcpSelBoxArrowStateEnum state)
{
    m_state = state;
    invalidate();
}


void VcpSelBoxArrow::setTheme(const VcpSelBoxArrowThemeStruct &theme)
{
    m_theme = theme;
    invalidate();
}


void VcpSelBoxArrow::setDirection(VcpSelBoxArrowDirectionEnum direction)
{
    m_direction = direction;
    invalidate();
}


void VcpSelBoxArrow::onInit()
{
    VfxFrame::onInit();

#if defined(__MMI_IME_FTE_ENHANCE__)
    setSize(VCP_SEL_BOX_FTE_ARROW_WIDTH, 0);
#else
    setSize(VCP_SEL_BOX_NO_FTE_ARROW_WIDTH + 2 * VCP_SEL_BOX_NO_FTE_ARROW_SPACING, 0);
#endif

    setIsUnhittable(VFX_TRUE);
}


void VcpSelBoxArrow::onDraw(VfxDrawContext &dc)
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    drawArrowFromImage(dc);
#else
    drawArrow(dc);
#endif
}


void VcpSelBoxArrow::drawArrow(VfxDrawContext &dc)
{
#if !defined(__MMI_IME_FTE_ENHANCE__)
    VfxS32 width = getSize().width;
    VfxS32 height = getSize().height;
    // no space to draw
    if ((width <= 0) || (height <= 0))
    {
        return;
    }
    
    VfxS32 arrowWidth = VCP_SEL_BOX_NO_FTE_ARROW_WIDTH;
    VfxS32 arrowHeight = VCP_SEL_BOX_NO_FTE_ARROW_HEIGHT;

    VfxS32 x = (width - arrowWidth) / 2;
    VfxS32 y = (height - arrowHeight) / 2;

    // check the position is valid
    if ((x < 0) || (y < 0))
    {
        VFX_ASSERT(0);
    }

    // get the color base on current state
    VfxColor *color=NULL;
    switch (m_state)
    {
        case VCP_SEL_BOX_ARROW_STATE_NORMAL:
            color = &(m_theme.colorNormal);
            break;
            
        case VCP_SEL_BOX_ARROW_STATE_HILITE:
            color = &(m_theme.colorHilite);
            break;
            
        case VCP_SEL_BOX_ARROW_STATE_DISABLED:
            color = &(m_theme.colorDisabled);
            break;

        default:
            // invalid state
            VFX_ASSERT(0);
            break;
    }

    // check the color is valid
    if (color->isTransparnet() == VFX_TRUE)
    {
        VFX_ASSERT(0);
    }
    dc.setStrokeColor(*color);
    
    // move the place of arrow when it is in highlight state
    if (m_state == VCP_SEL_BOX_ARROW_STATE_HILITE)
    {
        if (m_direction == VCP_SEL_BOX_ARROW_DIRECTION_LEFT)
        {
            x--;
            y++;
        }
        else if (m_direction == VCP_SEL_BOX_ARROW_DIRECTION_RIGHT)
        {
            x++;
            y++;
        }
    }

    // draw arrow
    VfxFloat m;
    VfxFloat cx;
    if (!(arrowHeight & 1))
    {
        arrowHeight--;
        m = ((VfxFloat)(1.0) - (VfxFloat)(arrowWidth)) / ((VfxFloat)(arrowHeight) / (VfxFloat)(2.0));
    }    
    
    switch (m_direction)
    {
        case VCP_SEL_BOX_ARROW_DIRECTION_LEFT:
            cx = (VfxFloat)(x + arrowWidth - 1);
            cx += 0.5;

            for (VfxS32 dy = 0; dy <= (arrowHeight / 2); dy++)
            {
                dc.drawLine((VfxS32)cx, y + dy, x + arrowWidth - 1, y + dy);
                dc.drawLine((VfxS32)cx, y + arrowHeight - 1 - dy, x + arrowWidth - 1,  y + arrowHeight - 1 - dy);
                cx += m;
            }
            break;

        case VCP_SEL_BOX_ARROW_DIRECTION_RIGHT:
            m = -m;
            cx = (VfxFloat)x;
            cx += 0.5;
            
            for (VfxS32 dy = 0; dy <= (arrowHeight / 2); dy++)
            {
                dc.drawLine(x, y + dy, (VfxS32)cx, y + dy);
                dc.drawLine(x, y + arrowHeight - 1 - dy, (VfxS32)cx,  y + arrowHeight - 1 - dy);
                cx += m;
            }
            break;

        default:
            // the direction is invalid
            VFX_ASSERT(0);
            break;
    }
#endif /* __MMI_IME_FTE_ENHANCE__ */
}


void VcpSelBoxArrow::drawArrowFromImage(VfxDrawContext &dc)
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    VfxS32 width = getSize().width;
    VfxS32 height = getSize().height;

    // no space to draw arrow
    if ((width <= 0) || (height <= 0))
    {
        return;
    }

    // get the image base on current state
    VfxImageSrc* image=NULL;
    switch (m_state)
    {
        case VCP_SEL_BOX_ARROW_STATE_NORMAL:
            switch (m_direction)
            {
                case VCP_SEL_BOX_ARROW_DIRECTION_LEFT:
                    image = &(m_theme.imgNormalLeft);
                    break;
                    
                case VCP_SEL_BOX_ARROW_DIRECTION_RIGHT:
                    image = &(m_theme.imgNormalRight);
                    break;

                default:
                    // invalid direction
                    VFX_ASSERT(0);
                    break;
            }
            break;
            
        case VCP_SEL_BOX_ARROW_STATE_HILITE:
            switch (m_direction)
            {
                case VCP_SEL_BOX_ARROW_DIRECTION_LEFT:
                    image = &(m_theme.imgHiliteLeft);
                    break;
                    
                case VCP_SEL_BOX_ARROW_DIRECTION_RIGHT:
                    image = &(m_theme.imgHiliteRight);
                    break;

                default:
                    // invalid direction
                    VFX_ASSERT(0);
                    break;
            }
            break;
            
        case VCP_SEL_BOX_ARROW_STATE_DISABLED:
            switch (m_direction)
            {
                case VCP_SEL_BOX_ARROW_DIRECTION_LEFT:
                    image = &(m_theme.imgDisabledLeft);
                    break;
                    
                case VCP_SEL_BOX_ARROW_DIRECTION_RIGHT:
                    image = &(m_theme.imgDisabledRight);
                    break;

                default:
                    // invalid direction
                    VFX_ASSERT(0);
                    break;
            }
            break;

        default:
            // invalid state
            VFX_ASSERT(0);
            break;
    }
    // check the image is valid
    if (image->isNull())
    {
        VFX_ASSERT(0);
    }

    // draw image
    // special case: -1, -1, width + 2, height + 2
    dc.drawResizedImage(VfxRect(-1, -1, width + 2, height + 2), *image);
#endif /* __MMI_IME_FTE_ENHANCE__ */
}


/***************************************************************************** 
 * Class VcpSelBoxStar
 *****************************************************************************/
void VcpSelBoxStar::setTheme(const VcpSelBoxStarThemeStruct &theme)
{
    m_theme = theme;
    setFont(m_theme.font);
    setColor(m_theme.color);
    setAutoResized(VFX_TRUE);
    forceUpdate();
    setAutoResized(VFX_FALSE);
    invalidate();
}


void VcpSelBoxStar::onInit()
{
    VfxTextFrame::onInit();

    setFont(m_theme.font);
    setColor(m_theme.color);

    setMargins(VCP_SEL_BOX_STAR_SPACING, 0, VCP_SEL_BOX_STAR_SPACING, 0);
    setString(VFX_WSTR("*"));
    setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER_WITHIN_MARGIN);
    setVerticalToCenter(VFX_TRUE);
    forceUpdate();
    setAutoResized(VFX_FALSE);
    setIsUnhittable(VFX_TRUE);
}


/***************************************************************************** 
 * Class VcpSelBoxSeperator
 *****************************************************************************/
void VcpSelBoxSeperator::setIsFocused(VfxBool isFocused)
{
    m_isFocused = isFocused;
    invalidate();
}


void VcpSelBoxSeperator::setTheme(const VcpSelBoxSeperatorThemeStruct &theme)
{
    m_theme = theme;
    
#if !defined(__MMI_IME_FTE_ENHANCE__)
    setSize(m_theme.width, 0);
#endif

    invalidate();
}


void VcpSelBoxSeperator::onInit()
{
    VfxFrame::onInit();

#if defined(__MMI_IME_FTE_ENHANCE__)
    setSize(VCP_SEL_BOX_FTE_SEPERATOR_WIDTH, 0);
#else
    setSize(m_theme.width, 0);
#endif
    
    setIsUnhittable(VFX_TRUE);
}


void VcpSelBoxSeperator::onDraw(VfxDrawContext &dc)
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    drawSeperatorFromImage(dc);
#else
    drawSeperator(dc);
#endif
}


void VcpSelBoxSeperator::drawSeperator(VfxDrawContext &dc)
{
#if !defined(__MMI_IME_FTE_ENHANCE__)
    VfxS32 width = getSize().width;
    VfxS32 height = getSize().height;

    // no space to draw
    if ((width <= 0) || (height <= 0))
    {
        return;
    }

    // get the color base on current state
    VfxColor *color;
    if (m_isFocused == VFX_TRUE)
    {
        color = &(m_theme.colorFocused);
    }
    else
    {
        color = &(m_theme.colorNormal);
    }
    dc.setFillColor(*color);

    //draw the seperator
    dc.fillRect(0, 0, width, height);
#endif /* __MMI_IME_FTE_ENHANCE__ */
}


void VcpSelBoxSeperator::drawSeperatorFromImage(VfxDrawContext &dc)
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    VfxS32 width = getSize().width;
    VfxS32 height = getSize().height;

    // no space to draw
    if ((width <= 0) || (height <= 0))
    {
        return;
    }

    // get the image base on current state
    VfxImageSrc *image;
    if (m_isFocused == VFX_TRUE)
    {
        image = &(m_theme.imageFocused);
    }
    else
    {
        image = &(m_theme.imageNormal);
    }
    // check the image is valid
    if (image->isNull())
    {
        VFX_ASSERT(0);
    }

    //draw the seperator
    // special case: the y = -1, height + 2
    dc.drawResizedImage(VfxRect(0, -1, width, height + 2), *image);
#endif /* __MMI_IME_FTE_ENHANCE__ */
}


/***************************************************************************** 
 * Class VcpSelBoxCandidate
 *****************************************************************************/
VcpSelBoxCandidate::VcpSelBoxCandidate(
    const VfxWString &text,
    const VcpSelBoxCandThemeStruct &theme,
    VfxS32 label,
    VcpSelBoxCandStateEnum state,
    VfxBool isR2L,
    VfxBool isAddingSpace,
    VfxBool isLabelShow
    ) :
    m_state(state),
    m_text(text),
    m_isR2L(isR2L),
    m_isAddingSpace(isAddingSpace),
    m_isFocused(VFX_FALSE),
    m_theme(theme),
    m_labelFrame(NULL),
    m_textFrame(NULL),
    m_isLabelShow(isLabelShow)
{
    if ((label == -1) || ((label >= 1) && (label <= 9)))
    {
        m_label = label;
    }
    else
    {
        m_label = -1;
    }
}


void VcpSelBoxCandidate::setState(VcpSelBoxCandStateEnum state)
{
    m_state = state;
    updateDisplay();
}


void VcpSelBoxCandidate::setIsFocused(VfxBool isFocused)
{
    m_isFocused = isFocused;
    updateDisplay();
}


void VcpSelBoxCandidate::setBounds(const VfxRect &value)
{
    VfxFrame::setBounds(value);
    updateLayout();
}


void VcpSelBoxCandidate::onInit()
{
    VfxFrame::onInit();

    if (m_text.isNull())
    {
        // no text
        VFX_ASSERT(0);
    }
    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);
    m_textFrame->setIsUnhittable(VFX_TRUE);

    if (m_label != -1)
    {
        VFX_OBJ_CREATE(m_labelFrame, VfxTextFrame, this);
        m_labelFrame->setIsUnhittable(VFX_TRUE);
    }
    
    initLayoutDisplay();
    
    setIsUnhittable(VFX_TRUE);
}


void VcpSelBoxCandidate::onDraw(VfxDrawContext &dc)
{
    // get the rectangle to draw background
    VfxRect bgRect = m_textFrame->getRect();
    
    switch (m_state)
    {
        case VCP_SEL_BOX_CAND_STATE_NORMAL:
            // background is transparent in normal state
            break;

        case VCP_SEL_BOX_CAND_STATE_HILITE:
        #if defined(__MMI_IME_FTE_ENHANCE__)
            // get the background image
            VfxImageSrc *image;
            if (::mmi_ime_word_is_redicals((UI_character_type)(m_text.getItem(0))))
            {
                if (m_isFocused == VFX_TRUE)
                {
                    image = &(m_theme.radicalHiliteBgImg);
                }
                else
                {
                    image = &(m_theme.radicalDullHiliteBgImg);
                }
            }
            else
            {
                if (m_isFocused == VFX_TRUE)
                {
                    image = &(m_theme.hiliteBgImg);
                }
                else
                {
                    image = &(m_theme.dullHiliteBgImg);
                }
            }
            // check the image is valid
            if (image->isNull())
            {
                VFX_ASSERT(0);
            }
            // special case: the y = -1, height + 2
            dc.drawResizedImage(VfxRect(bgRect.getX(), bgRect.getY() - 1, bgRect.getWidth(), bgRect.getHeight() + 2), *image);
        #else
            // get the background color
            VfxColor *color;
            if (::mmi_ime_word_is_redicals((UI_character_type)(m_text.getItem(0))))
            {
                if (m_isFocused == VFX_TRUE)
                {
                    color = &(m_theme.radicalHiliteBgColor);
                }
                else
                {
                    color = &(m_theme.radicalDullHiliteBgColor);
                }
            }
            else
            {
                if (m_isFocused == VFX_TRUE)
                {
                    color = &(m_theme.hiliteBgColor);
                }
                else
                {
                    color = &(m_theme.dullHiliteBgColor);
                }
            }
            dc.setFillColor(*color);
            dc.fillRect(bgRect);
        #endif
            break;

        default:
            // the state is invalid
            VFX_ASSERT(0);
            break;
    }
}


void VcpSelBoxCandidate::initLayoutDisplay()
{
    // set the frame to show text
    m_textFrame->setFont(m_theme.textFont);
    switch (m_state)
    {
        case VCP_SEL_BOX_CAND_STATE_NORMAL:
            if (::mmi_ime_word_is_redicals((UI_character_type)(m_text.getItem(0))))
            {
                m_textFrame->setColor(m_theme.radicalNormalTextColor);
            }
            else
            {
                m_textFrame->setColor(m_theme.normalTextColor);
            }
            break;

        case VCP_SEL_BOX_CAND_STATE_HILITE:
            if (::mmi_ime_word_is_redicals((UI_character_type)(m_text.getItem(0))))
            {
                m_textFrame->setColor(m_theme.radicalHiliteTextColor);
            }
            else
            {
                m_textFrame->setColor(m_theme.hiliteTextColor);
            }
            break;

        default:
            // the state is invalid
            VFX_ASSERT(0);
            break;      
    }
    
    if (m_isAddingSpace == VFX_TRUE)
    {
        // add a space after apostrophe for seperate spelling
        VfxU32 count = 0;
        for (VfxU32 i = 0; i < m_text.getLength(); i++)
        {
            if (m_text.getItem((VfxS32)i) == (VfxWChar)0x0027)
            {
                count++;
            }
        }

        if (count > 0)
        {
            VfxWChar *buffer;
            VFX_ALLOC_MEM(buffer, sizeof(VfxWChar) * (m_text.getLength() + count + 1), this);
            VFX_ASSERT(buffer != NULL);

            const VfxWChar *textBuffer = m_text.getBuf();

            VfxS32 i, j;
            for (i = 0, j = 0; i < (VfxS32)(m_text.getLength()); i++)
            {
                buffer[j] = textBuffer[i];
                if (textBuffer[i] == (VfxWChar)0x0027)
                {
                    buffer[++j] = (VfxWChar)0x0020;
                }
                j++;
            }
            buffer[j] = (VfxWChar)0x0;
            
            m_text = VFX_WSTR_MEM(buffer);
            VFX_FREE_MEM(buffer);
        }
    }
#if defined(__MMI_MULTITAP_BANGLA_SPEC__) && !defined(__MMI_VECTOR_FONT_SUPPORT__)
    VfxWChar newLabel[4];
	const VfxWChar *buf1 = (VfxWChar*)(m_text.getBuf() );
	VfxWString buf2;
    if(buf1[0] == 0x09b0 && buf1[1] == 0x09cd )
	{
		newLabel[0] = 0xeaab;
        newLabel[1] = 0x0000;
		buf2 = VFX_WSTR_MEM(newLabel);
		m_textFrame->setString(buf2);
	}
	else
#endif
	#if defined(__MMI_MULTITAP_BANGLA_SPEC__) && defined(__MMI_VECTOR_FONT_SUPPORT__)
    VfxWChar newLabel[4];
	const VfxWChar *buf1 = (VfxWChar*)(m_text.getBuf() );
	VfxWString buf2;
    if(buf1[0] == 0x09b0 && buf1[1] == 0x09cd )
	{
		newLabel[0] = 0xA42f;
        newLabel[1] = 0x0000;
		buf2 = VFX_WSTR_MEM(newLabel);
		m_textFrame->setString(buf2);
	}
	else if(buf1[0] == 0x09cd && buf1[1] == 0x09b0 )
	{
		newLabel[0] = 0xA431;
        newLabel[1] = 0x0000;
		buf2 = VFX_WSTR_MEM(newLabel);
		m_textFrame->setString(buf2);
	}
	 else if(buf1[0] == 0x09cd && buf1[1] == 0x09af )
	{
		newLabel[0] = 0xA430;
        newLabel[1] = 0x0000;
		buf2 = VFX_WSTR_MEM(newLabel);
		m_textFrame->setString(buf2);
	}
	else
#endif
    m_textFrame->setString(m_text);
    
    m_textFrame->setMargins(VCP_SEL_BOX_CAND_SPACING, 0, VCP_SEL_BOX_CAND_SPACING, 0);
    m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER_WITHIN_MARGIN);
    m_textFrame->setVerticalToCenter(VFX_TRUE);
    m_textFrame->setAutoResized(VFX_TRUE);
    VfxS32 textWidth = m_textFrame->getSize().width;
    VfxS32 textHeight = m_textFrame->getSize().height;

    m_textFrame->setAutoResized(VFX_FALSE);
    VfxS32 labelWidth = 0;
    VfxS32 labelHeight = 0;
    
    // set the frame to show label
    if (m_label != -1)
    {
        m_labelFrame->setFont(m_theme.labelFont);
        m_labelFrame->setColor(m_theme.labelColor);
        m_labelFrame->setString(VFX_WSTR("8"));
        m_labelFrame->setMargins(VCP_SEL_BOX_LABEL_SPACING, 0, VCP_SEL_BOX_LABEL_SPACING, 0);
        m_labelFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER_WITHIN_MARGIN);
        m_labelFrame->setVerticalToCenter(VFX_TRUE);
        m_labelFrame->setAutoResized(VFX_TRUE);
        labelWidth = m_labelFrame->getSize().width;
        labelHeight = m_labelFrame->getSize().height;

        m_labelFrame->setAutoResized(VFX_FALSE);
        VfxWString labelString;
        labelString.format("%d", m_label);
        m_labelFrame->setString(labelString);

        if ((m_isFocused == VFX_TRUE) && (m_isLabelShow == VFX_TRUE))
        {
            // show label when is focused
            m_labelFrame->setHidden(VFX_FALSE);
        }
        else
        {
            // hide label when is not focused
            m_labelFrame->setHidden(VFX_TRUE);
        }
    }

    // set the size of candidate
    VfxS32 width = labelWidth + textWidth;
    VfxS32 height;
    (labelHeight > textHeight) ? (height = labelHeight) : (height = textHeight);
    setSize(width, height);

    if (m_isR2L == VFX_FALSE)
    {
        if (m_label != -1)
        {
            // set the rectangle of frame of label
            m_labelFrame->setSize(labelWidth, height);
            m_labelFrame->setPos(0, 0);
        }

        // set the rectangle of frame of text
        m_textFrame->setSize(textWidth, height);
        m_textFrame->setPos(labelWidth, 0);
    }
    else
    {
        // set the rectangle of frame of text
        m_textFrame->setSize(textWidth, height);
        m_textFrame->setPos(0, 0);

        if (m_label != -1)
        {
            // set the rectangle of frame of label
            m_labelFrame->setSize(labelWidth, height);
            m_labelFrame->setPos(textWidth, 0);
        }
    }

    invalidate();
}


void VcpSelBoxCandidate::updateLayout()
{
    VfxS32 width = getSize().width;
    VfxS32 height = getSize().height;
    VfxS32 labelWidth = 0;
    if (m_label != -1)
    {
        labelWidth = m_labelFrame->getSize().width;
    }

    m_textFrame->setAutoResized(VFX_TRUE);
    VfxS32 textWidth = m_textFrame->getSize().width;

    // adjust the frame of text
    if (textWidth > (width - labelWidth))
    {
        if (m_isR2L == VFX_FALSE)
        {
            m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
        }
        else
        {
            m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
        }
    }
    else
    {
        m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER_WITHIN_MARGIN);
    }
    m_textFrame->setAutoResized(VFX_FALSE);
    textWidth = width - labelWidth;

    // set the rectangle of frame of text and label
    if (m_isR2L == VFX_FALSE)
    {
        if (m_label != -1)
        {
            // set the rectangle of frame of label
            m_labelFrame->setSize(labelWidth, height);
            m_labelFrame->setPos(0, 0);
        }

        // set the rectangle of frame of text
        m_textFrame->setSize(textWidth, height);
        m_textFrame->setPos(labelWidth, 0);
    }
    else
    {
        // set the rectangle of frame of text
        m_textFrame->setSize(textWidth, height);
        m_textFrame->setPos(0, 0);

        if (m_label != -1)
        {
            // set the rectangle of frame of label
            m_labelFrame->setSize(labelWidth, height);
            m_labelFrame->setPos(textWidth, 0);
        }
    }
}


void VcpSelBoxCandidate::updateDisplay()
{
    // set the color of frame of text
    switch (m_state)
    {
        case VCP_SEL_BOX_CAND_STATE_NORMAL:
            if (::mmi_ime_word_is_redicals((UI_character_type)(m_text.getItem(0))))
            {
                m_textFrame->setColor(m_theme.radicalNormalTextColor);
            }
            else
            {
                m_textFrame->setColor(m_theme.normalTextColor);
            }
            break;

        case VCP_SEL_BOX_CAND_STATE_HILITE:
            if (::mmi_ime_word_is_redicals((UI_character_type)(m_text.getItem(0))))
            {
                m_textFrame->setColor(m_theme.radicalHiliteTextColor);
            }
            else
            {
                m_textFrame->setColor(m_theme.hiliteTextColor);
            }
            break;

        default:
            // the state is invalid
            VFX_ASSERT(0);
            break;      
    }

    // set the display of frame of label
    if (m_label != -1)
    {
        if ((m_isFocused == VFX_TRUE) && (m_isLabelShow == VFX_TRUE))
        {
            // show label when is focused
            m_labelFrame->setHidden(VFX_FALSE);
        }
        else
        {
            // hide label when is not focused
            m_labelFrame->setHidden(VFX_TRUE);
        }
    }

    // redraw the background
    invalidate();
}


/***************************************************************************** 
 * Class VcpSelBox
 *****************************************************************************/
VFX_IMPLEMENT_CLASS(VCP_SEL_BOX_CLASS_NAME, VcpSelBox, VfxControl);


VcpSelBox::VcpSelBox(VfxU32 style) :
    m_style(style),
    m_flag(0),
    m_preArrow(NULL),
    m_preSeperator(NULL),
    m_nextArrow(NULL),
    m_nextSeperator(NULL),
    m_star(NULL),
#if defined __MMI_IME_CANDIDATE_GRID__
    m_candExpand(NULL),
    m_expandSeperator(NULL),

#endif
    m_candCount(0),
    m_currHiliteCand(-1),
    m_fteSize(VCP_SEL_BOX_SIZE_NONE),
    m_outsideCandStr(NULL),
    m_outsideCandCount(0),
    m_isSeperatorShow(VFX_FALSE),
    m_inArrowState(VCP_SEL_BOX_ARROW_TYPE_NONE),
    m_inCandidateState(VFX_FALSE),
    m_isFocused(VFX_FALSE),
    m_penSelectionValid(VFX_TRUE)
{
    for (int i = 0; i < VCP_SEL_BOX_CANDIDATE_COUNT_MAX; i++)
    {
        m_candArray[i] = NULL;
    }

    for (int i = 0; i < VCP_SEL_BOX_CANDIDATE_COUNT_MAX - 1; i++)
    {
        m_seperatorArray[i] = NULL;
    }

    m_newWordStr = VFX_WSTR("New word");
}


VfxS32 VcpSelBox::update(const VfxWChar *candStr, VfxS32 count, VfxS32 hiliteIndex, VfxU32 flag)
{
    m_outsideCandStr = candStr;
    m_outsideCandCount = count;
    m_flag = flag;
    
    if ((m_flag & VCP_SEL_BOX_FLAG_FOCUS) != 0)
    {
        m_isFocused = VFX_TRUE;
    }
    else
    {
        m_isFocused = VFX_FALSE;
    }

    VfxS32 height = getSize().height;
    VfxS32 x, y;
    VfxS32 needWidth;

    // calculate the first inner frame position
#if defined(__MMI_IME_FTE_ENHANCE__)
    x = VCP_SEL_BOX_BORDER_WIDTH + VCP_SEL_BOX_FTE_EXTER_BORDER_WIDTH;
    y = VCP_SEL_BOX_BORDER_WIDTH + VCP_SEL_BOX_FTE_EXTER_BORDER_WIDTH;
    height = height - 2 * (VCP_SEL_BOX_BORDER_WIDTH + VCP_SEL_BOX_FTE_EXTER_BORDER_WIDTH);
    needWidth = VCP_SEL_BOX_BORDER_WIDTH + VCP_SEL_BOX_FTE_EXTER_BORDER_WIDTH;
#else
    if ((m_style & VCP_SEL_BOX_STYLE_BORDER) != 0)
    {
        x = VCP_SEL_BOX_BORDER_WIDTH;
        y = VCP_SEL_BOX_BORDER_WIDTH;
        height = height - 2 * VCP_SEL_BOX_BORDER_WIDTH;
        needWidth = VCP_SEL_BOX_BORDER_WIDTH;
    }
    else
    {
        x = 0;
        y = 0;
        needWidth = 0;
    }
#endif

    // set the previous arrow
    if (((m_style & VCP_SEL_BOX_STYLE_ARROW) != 0) &&
        ((m_flag & VCP_SEL_BOX_FLAG_SHOW_ARROW) != 0))
    {
        VfxS32 width = m_preArrow->getSize().width;
        m_preArrow->setRect(x, y, width, height);
        m_preArrow->setDirection(VCP_SEL_BOX_ARROW_DIRECTION_LEFT);
        m_preArrow->setHidden(VFX_FALSE);
        x += width;
        needWidth += width;
    }
    else if ((m_style & VCP_SEL_BOX_STYLE_ARROW) != 0)
    {
        m_preArrow->setHidden(VFX_TRUE);
    }

    // set seperator beside prevous arrow
    if (m_isSeperatorShow == VFX_TRUE)
    {
        VfxS32 width = m_preSeperator->getSize().width;
        m_preSeperator->setRect(x, y, width, height);
        m_preSeperator->setIsFocused(m_isFocused);
        m_preSeperator->setHidden(VFX_FALSE);
        x += width;
        needWidth += width;
    }

    // set star
    if (((m_style & VCP_SEL_BOX_STYLE_STAR) != 0 ) &&
        ((m_flag & VCP_SEL_BOX_FLAG_SHOW_STAR) != 0))
    {
        VfxS32 width = m_star->getSize().width;
        m_star->setRect(x, y, width, height);
        m_star->setHidden(VFX_FALSE);
        x += width;
        needWidth += width;
    }
    else if ((m_style & VCP_SEL_BOX_STYLE_STAR) != 0)
    {
        m_star->setHidden(VFX_TRUE);
    }

    // make prepare for next arrow and seperator
    VfxS32 temp_x;
    VfxS32 selboxWidth = getSize().width;

#if defined(__MMI_IME_FTE_ENHANCE__)
    temp_x = selboxWidth - VCP_SEL_BOX_BORDER_WIDTH - VCP_SEL_BOX_FTE_EXTER_BORDER_WIDTH;
    needWidth += (VCP_SEL_BOX_BORDER_WIDTH + VCP_SEL_BOX_FTE_EXTER_BORDER_WIDTH);
#else
    if ((m_style & VCP_SEL_BOX_STYLE_BORDER) != 0)
    {
        temp_x = selboxWidth - VCP_SEL_BOX_BORDER_WIDTH;
        needWidth += VCP_SEL_BOX_BORDER_WIDTH;
    }
    else
    {
        temp_x = selboxWidth;
    }
#endif

    // set the next arrow
    if (((m_style & VCP_SEL_BOX_STYLE_ARROW) != 0 ) &&
        ((m_flag & VCP_SEL_BOX_FLAG_SHOW_ARROW) != 0))
    {
        VfxS32 width = m_nextArrow->getSize().width;
        m_nextArrow->setRect(temp_x - width, y, width, height);
        m_nextArrow->setDirection(VCP_SEL_BOX_ARROW_DIRECTION_RIGHT);
        m_nextArrow->setHidden(VFX_FALSE);
        temp_x -= width;
        needWidth += width;
    }
    else if ((m_style & VCP_SEL_BOX_STYLE_ARROW) != 0)
    {
        m_nextArrow->setHidden(VFX_TRUE);
    }

    // set seperator beside next arrow
    if (m_isSeperatorShow == VFX_TRUE)
    {
        VfxS32 width = m_nextSeperator->getSize().width;
        m_nextSeperator->setRect(temp_x - width, y, width, height);
        m_nextSeperator->setIsFocused(m_isFocused);
        m_nextSeperator->setHidden(VFX_FALSE);
        temp_x -= width;
        needWidth += width;
    }
      //set expand button

    #if defined __MMI_IME_CANDIDATE_GRID__
      if (((m_style & VCP_SEL_BOX_STYLE_EXPAND_BUTTON) != 0 )&&
          ((m_flag &  VCP_SEL_BOX_FLAG_SHOW_EXPAND_BUTTON) !=0)) 
    
        {   
            
            VcpStateImage  imgBG,  imgFG;
            //buttons background
            imgBG.setImage(m_theme.gridCandBg,m_theme.gridCandBgHl,m_theme.gridCandBg ,m_theme.gridCandBg  ); 
            imgFG.setImage(m_theme.expandImg,m_theme.expandImg,m_theme.expandImg,m_theme.expandImg);
            m_candExpand->setImage(imgFG);
            m_candExpand->setAutoAnimate(VFX_FALSE);

            
            m_candExpand->setBgImageList(imgBG); 
            m_candExpand->setSize(VCP_SEL_BOX_FTE_EXPAND_BUTTON_WIDTH,height);
            VfxS32 width = m_candExpand->getSize().width;
            m_candExpand->setRect(temp_x - width, y, width, height);
            m_candExpand->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
            temp_x -= width;
            needWidth += width;

            m_candExpand->m_signalClicked.connect(this, &VcpSelBox::onGridExpandPress);
            m_candExpand->setHidden(VFX_FALSE);
       // set seperator beside expand button
            if (m_isSeperatorShow == VFX_TRUE)
            {
                VfxS32 width = m_expandSeperator->getSize().width;
                m_expandSeperator->setRect(temp_x - width, y, width, height);
                m_expandSeperator->setIsFocused(m_isFocused);
                m_expandSeperator->setHidden(VFX_FALSE);
                temp_x -= width;
                needWidth += width;
            }
      
        }
    else
    {
        if(m_candExpand)
        {
           m_candExpand->setHidden(VFX_TRUE);
        }
        if(m_expandSeperator)
        {
            m_expandSeperator->setHidden(VFX_TRUE);
        }

    }
#endif    

    // check there is space to place candidate
#if defined(__MMI_IME_FTE_ENHANCE__)
    VFX_ASSERT((needWidth + VCP_SEL_BOX_FTE_MIN_CAND_WIDTH) <= selboxWidth);
#else
    VFX_ASSERT(needWidth < selboxWidth);
#endif
    VfxS32 candAreaWidth = selboxWidth - needWidth;

    // clear previous candidate and seperator
    for (VfxS32 i = 0; i < m_candCount; i++)
    {
        if (m_candArray[i] != NULL)
        {
            VFX_OBJ_CLOSE(m_candArray[i]);
            m_candArray[i] = NULL;
        }

        if ((i < (m_candCount - 1)) && (m_seperatorArray[i] != NULL))
        {
            VFX_OBJ_CLOSE(m_seperatorArray[i]);
            m_seperatorArray[i] = NULL;
        }
    }
    m_candCount = 0;
    m_currHiliteCand = -1;

    // set candidate
    // prepare theme
    VcpSelBoxCandThemeStruct candTheme;
    buildCandidateTheme(candTheme);
    
    // check whether adding space after apostrophe
    VfxBool candIsAddingSpace;
    if ((m_style & VCP_SEL_BOX_STYLE_SPACE_AFTER_APOSTROPHE) != 0)
    {
        candIsAddingSpace = VFX_TRUE;
    }
    else
    {
        candIsAddingSpace = VFX_FALSE;
    }

    // check whether show the label when candidate is in focused state
    VfxBool candIsLabelShow;
    if ((m_flag & VCP_SEL_BOX_FLAG_DISABLE_LABEL) != 0)
    {
        candIsLabelShow = VFX_FALSE;
    }
    else
    {
        candIsLabelShow = VFX_TRUE;
    }

    // check whether the candidate is R2L
    VfxBool candIsR2L;
    if ((m_flag & VCP_SEL_BOX_FLAG_R2L) != 0)
    {
        candIsR2L = VFX_TRUE;
    }
    else
    {
        candIsR2L = VFX_FALSE;
    }

    VfxS32 maxCandWidth = 0;
    // build all the candidate and seperator
    for (VfxS32 i = 0; i < m_outsideCandCount; i++)
    {
        // prepare label
        VfxS32 candLabel;
        if ((m_style & VCP_SEL_BOX_STYLE_LABEL) != 0)
        {
            candLabel = i + 1;
            VFX_ASSERT(candLabel < 10);
        }
        else
        {
            candLabel = -1;
        }
        
        // prepare text
        VfxWString text;
    #if defined(__MMI_IME_USER_DATABASE__)
        if ((*candStr) == VCP_SEL_BOX_USER_DATABASE_NEW_WORD)
        {
            text = m_newWordStr;
        }
        else
    #endif
        {
            text = VFX_WSTR_MEM(candStr);
        }
    
        while((*candStr) != 0)
        {
            candStr++;
        }
        while((*candStr) == 0)
        {
            candStr++;
        }
        
        // create the candidate
        VFX_OBJ_CREATE_EX(
            m_candArray[i],
            VcpSelBoxCandidate,
            this,
            (text, candTheme, candLabel, VCP_SEL_BOX_CAND_STATE_NORMAL, candIsR2L, candIsAddingSpace, candIsLabelShow)
            );

        VfxS32 candidateWidth = m_candArray[i]->getSize().width;
    #if defined(__MMI_IME_FTE_ENHANCE__)
        if (candidateWidth < VCP_SEL_BOX_FTE_MIN_CAND_WIDTH)
        {
            candidateWidth = VCP_SEL_BOX_FTE_MIN_CAND_WIDTH;
        }
    #endif
        if (candidateWidth > maxCandWidth)
        {
            maxCandWidth = candidateWidth;
        }

        // check whether there is enough space to place candidate
        if (needWidth + candidateWidth > selboxWidth)
        {
            // do not has enough space to place this candidate
            if (i == 0)
            {
                // place the first candidate
                m_candArray[i]->setRect(x, y, selboxWidth - needWidth, height);
                m_candArray[i]->setIsFocused(m_isFocused);
                m_candCount = 1;
                needWidth = selboxWidth;
                break;
            }
            else
            {
                // delete the gap and seperator
            #if !defined(__MMI_IME_FTE_ENHANCE__)
                needWidth -= (2 * VCP_SEL_BOX_NO_FTE_CAND_GAP);
            #endif
                if ((m_flag & VCP_SEL_BOX_FLAG_SPACE) != 0)
                {
                    needWidth -= (m_theme.candGap);
                }
                    
                if (m_isSeperatorShow == VFX_TRUE)
                {
                    needWidth -= (m_seperatorArray[i - 1]->getSize().width);
                    VFX_OBJ_CLOSE(m_seperatorArray[i - 1]);
                }
                // destroy the non-frist candidate
                VFX_OBJ_CLOSE(m_candArray[i]);
                
                break;
            }
        }
        else
        {
            // has enough space to place this candidate
            m_candArray[i]->setRect(x, y, candidateWidth, height);
            m_candArray[i]->setIsFocused(m_isFocused);
            x += candidateWidth;
            needWidth += candidateWidth;
            m_candCount++;
        }

        // add the gap and seperator for all the candidate except the last one
        if (i < (m_outsideCandCount - 1))
        {
            // place the gap
        #if !defined(__MMI_IME_FTE_ENHANCE__)
            x += VCP_SEL_BOX_NO_FTE_CAND_GAP;
            needWidth += VCP_SEL_BOX_NO_FTE_CAND_GAP;
        #endif
            if ((m_flag & VCP_SEL_BOX_FLAG_SPACE) != 0)
            {
                x += ((m_theme.candGap / 2) + (m_theme.candGap % 2));
                needWidth += ((m_theme.candGap / 2) + (m_theme.candGap % 2));
            }
            
            // place the seperator
            VfxS32 seperatorWidth = 0;
            if (m_isSeperatorShow == VFX_TRUE)
            {
                VcpSelBoxSeperatorThemeStruct seperatorTheme;
                buildSeperatorTheme(seperatorTheme);
                VFX_OBJ_CREATE_EX(m_seperatorArray[i], VcpSelBoxSeperator, this, (seperatorTheme));
                seperatorWidth = m_seperatorArray[i]->getSize().width;
                m_seperatorArray[i]->setRect(x, y, seperatorWidth, height);
                m_seperatorArray[i]->setIsFocused(m_isFocused);
                x += seperatorWidth;
                needWidth += seperatorWidth;
            }

            // place the gap
        #if !defined(__MMI_IME_FTE_ENHANCE__)
            x += VCP_SEL_BOX_NO_FTE_CAND_GAP;
            needWidth += VCP_SEL_BOX_NO_FTE_CAND_GAP;
        #endif
            if ((m_flag & VCP_SEL_BOX_FLAG_SPACE) != 0)
            {
                x += (m_theme.candGap / 2);
                needWidth += (m_theme.candGap / 2);
            }

            // check whether there is enough space to place the gaps and seperator
            if (needWidth > selboxWidth)
            {
                // no space
            #if !defined(__MMI_IME_FTE_ENHANCE__)
                needWidth -= (2 * VCP_SEL_BOX_NO_FTE_CAND_GAP);
            #endif
                if ((m_flag & VCP_SEL_BOX_FLAG_SPACE) != 0)
                {
                    needWidth -= (m_theme.candGap);
                }
                
                if (m_isSeperatorShow == VFX_TRUE)
                {
                    needWidth -= seperatorWidth;
                    VFX_OBJ_CLOSE(m_seperatorArray[i]);
                }

                break;
            }
        }
    }

    // adjust the candidate and seperator when need
    if ((m_flag & VCP_SEL_BOX_FLAG_FIX_GRID) != 0)
    {
        if (m_candCount > 0)
        {
            VfxS32 extraEachWidth = 0;
        #if !defined(__MMI_IME_FTE_ENHANCE__)
            extraEachWidth += (2 *VCP_SEL_BOX_NO_FTE_CAND_GAP);
        #endif
            if ((m_flag & VCP_SEL_BOX_FLAG_SPACE) != 0)
            {
                extraEachWidth += m_theme.candGap;
            }

            VfxS32 eachWidth;
            VfxS32 extraAddCount;
            while(1)
            {
                eachWidth = (candAreaWidth - extraEachWidth * (m_candCount - 1)) / m_candCount;
                extraAddCount = (candAreaWidth - extraEachWidth * (m_candCount - 1)) % m_candCount;
                if (eachWidth < maxCandWidth)
                {
                    VFX_OBJ_CLOSE(m_candArray[m_candCount - 1]);
                    VFX_OBJ_CLOSE(m_seperatorArray[m_candCount - 2]);
                    m_candCount--;
                }
                else
                {
                    break;
                }
            }
            
            VfxS32 x = m_candArray[0]->getPos().x;
            for (VfxS32 i = 0; i < m_candCount; i++)
            {
                // set the candidate
                VfxS32 height = m_candArray[i]->getSize().height;
                if (i < extraAddCount)
                {
                    m_candArray[i]->setRect(x, m_candArray[i]->getPos().y, eachWidth + 1, height);
                    x += (eachWidth + 1);
                }
                else
                {
                    m_candArray[i]->setRect(x, m_candArray[i]->getPos().y, eachWidth, height);
                    x += eachWidth;
                }
                
                // skip the gap
            #if !defined(__MMI_IME_FTE_ENHANCE__)
                x += VCP_SEL_BOX_NO_FTE_CAND_GAP;
            #endif
                if ((m_flag & VCP_SEL_BOX_FLAG_SPACE) != 0)
                {
                    x += ((m_theme.candGap / 2) + (m_theme.candGap % 2));
                }

                // set the seperator
                if ((m_isSeperatorShow == VFX_TRUE) && (i < (m_candCount - 1)))
                {
                    m_seperatorArray[i]->setPos(x, m_seperatorArray[i]->getPos().y);
                    x += m_seperatorArray[i]->getSize().width;
                }

                // skip the gap
            #if !defined(__MMI_IME_FTE_ENHANCE__)
                x += VCP_SEL_BOX_NO_FTE_CAND_GAP;
            #endif
                if ((m_flag & VCP_SEL_BOX_FLAG_SPACE) != 0)
                {
                    x += (m_theme.candGap / 2);
                }
            }
        }
    }
    else if ((m_flag & VCP_SEL_BOX_FLAG_CENTER_INDEX) != 0)
    {
        VfxS32 candX, candY, seperatorX, seperatorY;
        VfxS32 adjustPixel = (selboxWidth - needWidth) / 2;
        for (int i = 0; i < m_candCount; i++)
        {
            candX = m_candArray[i]->getPos().x;
            candY = m_candArray[i]->getPos().y;
            candX += adjustPixel;
            m_candArray[i]->setPos(candX, candY);

            if ((m_isSeperatorShow == VFX_TRUE) && (i < (m_candCount - 1)))
            {
                seperatorX = m_seperatorArray[i]->getPos().x;
                seperatorY = m_seperatorArray[i]->getPos().y;
                seperatorX += adjustPixel;
                m_seperatorArray[i]->setPos(seperatorX, seperatorY);
            }
        }
    }
    else if ((((m_flag & VCP_SEL_BOX_FLAG_NEXT_PAGE) != 0) || (m_candCount < m_outsideCandCount)) &&
             ((m_flag & VCP_SEL_BOX_FLAG_LAST_PAGE) == 0))
    {
        if (m_candCount > 0)
        {
            VfxS32 addWidth = (selboxWidth - needWidth) / m_candCount;
            VfxS32 extraAddCount = (selboxWidth - needWidth) % m_candCount;
            VfxS32 x = m_candArray[0]->getPos().x;
            for (VfxS32 i = 0; i < m_candCount; i++)
            {
                // set the candidate
                VfxS32 width = m_candArray[i]->getSize().width;
                VfxS32 height = m_candArray[i]->getSize().height;
                width += addWidth;
                if (i < extraAddCount)
                {
                    width++;
                }
                m_candArray[i]->setRect(x, m_candArray[i]->getPos().y, width, height);
                x += width;
                
                // skip the gap
            #if !defined(__MMI_IME_FTE_ENHANCE__)
                x += VCP_SEL_BOX_NO_FTE_CAND_GAP;
            #endif
                if ((m_flag & VCP_SEL_BOX_FLAG_SPACE) != 0)
                {
                    x += ((m_theme.candGap / 2) + (m_theme.candGap % 2));
                }

                // set the seperator
                if ((m_isSeperatorShow == VFX_TRUE) && (i < (m_candCount - 1)))
                {
                    m_seperatorArray[i]->setPos(x, m_seperatorArray[i]->getPos().y);
                    x += m_seperatorArray[i]->getSize().width;
                }

                // skip the gap
            #if !defined(__MMI_IME_FTE_ENHANCE__)
                x += VCP_SEL_BOX_NO_FTE_CAND_GAP;
            #endif
                if ((m_flag & VCP_SEL_BOX_FLAG_SPACE) != 0)
                {
                    x += (m_theme.candGap / 2);
                }
            }
        }
    }

    // set for R2L
    if ((m_flag & VCP_SEL_BOX_FLAG_R2L) != 0)
    {
        // exchange the previous and next arrow
        if (((m_style & VCP_SEL_BOX_STYLE_ARROW) != 0) &&
            ((m_flag & VCP_SEL_BOX_FLAG_SHOW_ARROW) != 0))
        {
            VcpSelBoxArrow *temp = m_preArrow;
            m_preArrow = m_nextArrow;
            m_nextArrow = temp;
        }

        // exchange the previous and next seperator
        if (m_isSeperatorShow == VFX_TRUE)
        {
            VcpSelBoxSeperator *temp = m_preSeperator;
            m_preSeperator = m_nextSeperator;
            m_nextSeperator = temp;
        }

        // adjust the star
        if (((m_style & VCP_SEL_BOX_STYLE_STAR) != 0 ) &&
            ((m_flag & VCP_SEL_BOX_FLAG_SHOW_STAR) != 0))
        {
            VfxS32 x = m_star->getPos().x;
            VfxS32 y = m_star->getPos().y;
            VfxS32 width = m_star->getSize().width;

            m_star->setPos(selboxWidth - x - width, y);
        }

        // adjust the candidate and seperator
        for (VfxS32 i = 0 ; i < m_candCount; i++)
        {
            // adjust the candidate
            VfxS32 x = m_candArray[i]->getPos().x;
            VfxS32 y = m_candArray[i]->getPos().y;
            VfxS32 width = m_candArray[i]->getSize().width;
            m_candArray[i]->setPos(selboxWidth - x - width, y);

            // adjust the seperator
            if ((m_isSeperatorShow == VFX_TRUE) && (i < (m_candCount - 1)))
            {
                x = m_seperatorArray[i]->getPos().x;
                y = m_seperatorArray[i]->getPos().y;
                width = m_seperatorArray[i]->getSize().width;
                m_seperatorArray[i]->setPos(selboxWidth - x - width, y);
            }
        }

        //adjust expand button
#if defined __MMI_IME_CANDIDATE_GRID__
        VfxS32 x = m_candExpand->getPos().x;
        VfxS32 y = m_candExpand->getPos().y;
        VfxS32 width = m_candExpand->getSize().width;

        m_candExpand->setPos(selboxWidth - x - width, y);
            // adjust the seperator
        if (m_isSeperatorShow == VFX_TRUE)
        {
            VfxS32 x = m_expandSeperator->getPos().x;
            VfxS32 y = m_expandSeperator->getPos().y;
            VfxS32 width = m_expandSeperator->getSize().width;

            m_expandSeperator->setPos(selboxWidth - x - width, y);
        }

#endif
    }

    // set the highlight candidate
    setHiliteCandidate(hiliteIndex);

    // set the state of arrow
    setArrowState();
    
    // show the selection box
    setHidden(VFX_FALSE);
    invalidate();
    
    return m_candCount;
}


VfxBool VcpSelBox::setHiliteCandidate(VfxS32 hiliteIndex)
{
    // change the highlight candidate
    if (m_currHiliteCand != -1)
    {
        m_candArray[m_currHiliteCand]->setState(VCP_SEL_BOX_CAND_STATE_NORMAL);
    }
    
    if (hiliteIndex < 0 || hiliteIndex >= m_candCount)
    {
        m_currHiliteCand = -1;
        // set the state of arrow
        setArrowState();
        return VFX_FALSE;
    }

    m_candArray[hiliteIndex]->setState(VCP_SEL_BOX_CAND_STATE_HILITE);
    m_currHiliteCand = hiliteIndex;
    // set the state of arrow
    setArrowState();
    
    return VFX_TRUE;
}


VfxS32 VcpSelBox::getHiliteCandidate()
{
    return m_currHiliteCand;
}


VfxS32 VcpSelBox::setTheme(const VcpSelBoxThemeStruct &theme)
{
    m_theme = theme;
    
    // theme change the height of selection box
    VfxS32 width = getSize().width;
    VfxS32 height = getDefaultHeight();
    setSize(width, height);

    // theme change the theme of arrow
    if ((m_style & VCP_SEL_BOX_STYLE_ARROW) != 0)
    {
        VcpSelBoxArrowThemeStruct arrowTheme;
        buildArrowTheme(arrowTheme);
        m_preArrow->setTheme(arrowTheme);
        m_nextArrow->setTheme(arrowTheme);
    }

    // theme change the theme of star
    if ((m_style & VCP_SEL_BOX_STYLE_STAR) != 0)
    {
        VcpSelBoxStarThemeStruct starTheme;
        buildStarTheme(starTheme);
        m_star->setTheme(starTheme);
    }

    // check whether the seperator is showed
    if (((m_style & VCP_SEL_BOX_STYLE_SEPERATOR) != 0)
    #if !defined(__MMI_IME_FTE_ENHANCE__)
        && (m_theme.seperatorWidth > 0)
    #endif
        )
    {
        m_isSeperatorShow = VFX_TRUE;
    }
    else
    {
        m_isSeperatorShow = VFX_FALSE;
    }

    // theme change the theme of seperatator
    if (m_isSeperatorShow == VFX_TRUE)
    {
        VcpSelBoxSeperatorThemeStruct seperatorTheme;
        buildSeperatorTheme(seperatorTheme);
        if (m_preSeperator == NULL)
        {
            VFX_OBJ_CREATE_EX(m_preSeperator, VcpSelBoxSeperator, this, (seperatorTheme));
        }
        else
        {
            m_preSeperator->setTheme(seperatorTheme);
        }
        
        if (m_nextSeperator == NULL)
        {
            VFX_OBJ_CREATE_EX(m_nextSeperator, VcpSelBoxSeperator, this, (seperatorTheme));
        }
        else
        {
            m_nextSeperator->setTheme(seperatorTheme);
        }
#if defined __MMI_IME_CANDIDATE_GRID__

        if (m_expandSeperator == NULL)
        {
            VFX_OBJ_CREATE_EX(m_expandSeperator, VcpSelBoxSeperator, this, (seperatorTheme));
        }
        else
        {
            m_expandSeperator->setTheme(seperatorTheme);
        }
#endif
    }
    else
    {
        if (m_preSeperator != NULL)
        {
            VFX_OBJ_CLOSE(m_preSeperator);
        }
        
        if (m_nextSeperator != NULL)
        {
            VFX_OBJ_CLOSE(m_nextSeperator);
        }
    }

    setHidden(VFX_TRUE);
    
    if (m_outsideCandStr != NULL)
    {
        return update(m_outsideCandStr, m_outsideCandCount, m_currHiliteCand, m_flag);
    }
    else
    {
        return 0;
    }
}


const VcpSelBoxThemeStruct &VcpSelBox::getTheme()
{
    return m_theme;
}


void VcpSelBox::setIsFocused(VfxBool isFocused)
{
    if (m_isFocused == isFocused)
    {
        return;
    }

    m_isFocused = isFocused;

    // set the seperator
    if (m_isSeperatorShow == VFX_TRUE)
    {
        m_preSeperator->setIsFocused(m_isFocused);
        m_nextSeperator->setIsFocused(m_isFocused);
        for (VfxS32 i = 0; i < (m_candCount - 1); i++)
        {
            m_seperatorArray[i]->setIsFocused(m_isFocused);
        }
    }

    // set the candiate
    for (VfxS32 i = 0; i < m_candCount; i++)
    {
        m_candArray[i]->setIsFocused(m_isFocused);
    }

    // redraw the background
    invalidate();
}


void VcpSelBox::setNewWordString(const VfxWString &str)
{
    m_newWordStr = str;
}


void VcpSelBox::setIsPenSelectionValid(VfxBool isValid)
{
    m_penSelectionValid = isValid;
}


void VcpSelBox::onDraw(VfxDrawContext &dc)
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    VfxImageSrc *image=NULL;
    switch (m_fteSize)
    {
        case VCP_SEL_BOX_SIZE_SMALL:
            if (m_isFocused == VFX_TRUE)
            {
                image = &(m_theme.focusedBgImageSmall);
            }
            else
            {
                image = &(m_theme.bgImageSmall);
            }
            break;

        case VCP_SEL_BOX_SIZE_MEDIUM:
            if (m_isFocused == VFX_TRUE)
            {
                image = &(m_theme.focusedBgImageMedium);
            }
            else
            {
                image = &(m_theme.bgImageMedium);
            }
            break;

        case VCP_SEL_BOX_SIZE_LARGE:
            if (m_isFocused == VFX_TRUE)
            {
                image = &(m_theme.focusedBgImageLarge);
            }
            else
            {
                image = &(m_theme.bgImageLarge);
            }
            break;

        default:
            // the height is invalid
            VFX_ASSERT(0);
            break;
    }

    // check the image is valid
    if (image->isNull())
    {
        VFX_ASSERT(0);
    }

    // draw the image
    VfxS32 width = getSize().width;
    VfxS32 height = getSize().height;
    VfxRect rect(0 , 0, width, height);
    dc.drawResizedImage(rect, *image);
#else
    // draw the background
    VfxImageSrc *image;
    if (m_isFocused == VFX_TRUE)
    {
        image = &(m_theme.focusedBgImage);
    }
    else
    {
        image = &(m_theme.bgImage);
    }

    // check the image is valid
    if (image->isNull())
    {
        // using the color to draw
        VfxColor *color;
        if (m_isFocused == VFX_TRUE)
        {
            color = &(m_theme.focusedBgColor);
        }
        else
        {
            color = &(m_theme.bgColor);
        }

        dc.setFillColor(*color);
        VfxS32 width = getSize().width;
        VfxS32 height = getSize().height;
        dc.fillRect(0 , 0, width, height);
    }
    else
    {
        // using the image to draw
        dc.drawImage(0, 0, *image);
    }

    // draw the border
    VfxColor *color;
    if (m_isFocused == VFX_TRUE)
    {
        color = &(m_theme.focusedBorderColor);
    }
    else
    {
        color = &(m_theme.borderColor);
    }
    dc.setStrokeColor(*color);

    // draw the top border
    dc.drawLine(1, 0, getSize().width - 2, 0);
    // draw the left border
    dc.drawLine(0, 1, 0, getSize().height - 2);
    // draw the bottom border
    dc.drawLine(1, getSize().height - 1, getSize().width - 2, getSize().height - 1);
    // draw the right border
    dc.drawLine(getSize().width -1, 1, getSize().width - 1, getSize().height - 2);
#endif
}


void VcpSelBox::onInit()
{
    VfxControl::onInit();

    buildDefaultTheme();

    VfxS32 height = getDefaultHeight();
    setSize(0, height);

    // the arrow want to be showed
    if ((m_style & VCP_SEL_BOX_STYLE_ARROW) != 0)
    {
        VcpSelBoxArrowThemeStruct arrowTheme;
        buildArrowTheme(arrowTheme);
        
        VFX_OBJ_CREATE_EX(m_preArrow, VcpSelBoxArrow, this, (arrowTheme));
        VFX_OBJ_CREATE_EX(m_nextArrow, VcpSelBoxArrow, this, (arrowTheme));
    }

    // the star want to be showed
    if ((m_style & VCP_SEL_BOX_STYLE_STAR) != 0)
    {
        VcpSelBoxStarThemeStruct starTheme;
        buildStarTheme(starTheme);
        
        VFX_OBJ_CREATE_EX(m_star, VcpSelBoxStar, this, (starTheme));
    }

#if defined __MMI_IME_CANDIDATE_GRID__
    if ((m_style & VCP_SEL_BOX_STYLE_EXPAND_BUTTON) != 0 )        
   {   
       //check if we need a new theme 
        VFX_OBJ_CREATE(m_candExpand,VcpButton,this);
        m_candExpand->setHidden(VFX_TRUE);
   }
#endif
    // check whether the seperator is showed
    if (((m_style & VCP_SEL_BOX_STYLE_SEPERATOR) != 0)
    #if !defined(__MMI_IME_FTE_ENHANCE__)
        && (m_theme.seperatorWidth > 0)
    #endif
        )
    {
        m_isSeperatorShow = VFX_TRUE;
    }
    else
    {
        m_isSeperatorShow = VFX_FALSE;
    }

    // the seperator is showed
    if (m_isSeperatorShow == VFX_TRUE)
    {
        VcpSelBoxSeperatorThemeStruct seperatorTheme;
        buildSeperatorTheme(seperatorTheme);

        VFX_OBJ_CREATE_EX(m_preSeperator, VcpSelBoxSeperator, this, (seperatorTheme));
        VFX_OBJ_CREATE_EX(m_nextSeperator, VcpSelBoxSeperator, this, (seperatorTheme));
    }
    
    // do not show the selection box till the outside call update()
    setHidden(VFX_TRUE);
}


VfxBool VcpSelBox::onPenInput(VfxPenEvent &event)
{
    if (m_penSelectionValid == VFX_FALSE)
    {
        return VFX_TRUE;
    }
    
    VfxPoint pos = event.getRelPos(this);
    VcpSelBoxArrowTypeEnum arrowType;
    VfxS32 candIndex;
    
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            arrowType = checkIsInArrow(pos);
            if (arrowType != VCP_SEL_BOX_ARROW_TYPE_NONE)
            {
                // pen down in arrow
                  vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);
                switch (arrowType)
                {
                    case VCP_SEL_BOX_ARROW_TYPE_PREVIOUS:
                        m_preArrow->setState(VCP_SEL_BOX_ARROW_STATE_HILITE);
                        m_inArrowState = arrowType;
                        m_inCandidateState = VFX_FALSE;
                        break;

                    case VCP_SEL_BOX_ARROW_TYPE_NEXT:
                        m_nextArrow->setState(VCP_SEL_BOX_ARROW_STATE_HILITE);
                        m_inArrowState = arrowType;
                        m_inCandidateState = VFX_FALSE;
                        break;

                    default:
                        // invalid type
                        VFX_ASSERT(0);
                        break;
                }
            }
            else if ((candIndex = checkIsInCandidate(pos)) != -1)
            {
                // pen down in candidate
                setHiliteCandidate(candIndex);
                m_inCandidateState = VFX_TRUE;
                m_inArrowState = VCP_SEL_BOX_ARROW_TYPE_NONE;
                emitCandDownSignal(candIndex);
            }
            else
            {
                // pen down in others
                // ignore
            }
            break;

        case VFX_PEN_EVENT_TYPE_LONG_TAP:
            // ignore
            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
            if (m_inArrowState != VCP_SEL_BOX_ARROW_TYPE_NONE)
            {
                // the arrow is pressed
                // ignore
            }
            else if (m_inCandidateState == VFX_TRUE)
            {
                // the candidate is pressed
                candIndex = checkIsInCandidate(pos);
                if (candIndex != -1)
                {
                    if (candIndex == m_currHiliteCand)
                    {
                        // move in/into current highlight candidate
                        // ignore
                    }
                    else
                    {
                        // move into another candidate
                        setHiliteCandidate(candIndex);
                        emitCandMoveSignal(candIndex);
                    }
                }
                else
                {
                    // move into non-candidate
                    // ignore
                }
            }
            else
            {
                // both of candidate and arrow is not pressed
                // ignore
            }
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            if (m_inArrowState != VCP_SEL_BOX_ARROW_TYPE_NONE)
            {
                // the arrow is pressed
                arrowType = checkIsInArrow(pos);
                if (arrowType == m_inArrowState)
                {
                    // down and up in same arrow
                    switch (arrowType)
                    {
                        case VCP_SEL_BOX_ARROW_TYPE_PREVIOUS:
                            m_preArrow->setState(VCP_SEL_BOX_ARROW_STATE_NORMAL);
                            break;

                        case VCP_SEL_BOX_ARROW_TYPE_NEXT:
                            m_nextArrow->setState(VCP_SEL_BOX_ARROW_STATE_NORMAL);
                            break;

                        default:
                            // invalid type
                            VFX_ASSERT(0);
                            break;
                    }
                    m_inArrowState = VCP_SEL_BOX_ARROW_TYPE_NONE;
                    m_inCandidateState = VFX_FALSE;
                    emitArrowClickedSignal(arrowType);
                }
                else
                {
                    // down and up is not in same arrow
                    switch (m_inArrowState)
                    {
                        case VCP_SEL_BOX_ARROW_TYPE_PREVIOUS:
                            m_preArrow->setState(VCP_SEL_BOX_ARROW_STATE_NORMAL);
                            break;

                        case VCP_SEL_BOX_ARROW_TYPE_NEXT:
                            m_nextArrow->setState(VCP_SEL_BOX_ARROW_STATE_NORMAL);
                            break;

                        default:
                            // invalid type
                            VFX_ASSERT(0);
                            break;
                    }
                    m_inArrowState = VCP_SEL_BOX_ARROW_TYPE_NONE;
                    m_inCandidateState = VFX_FALSE;
                }
            }
            else if (m_inCandidateState == VFX_TRUE)
            {
                // the candidate is pressed
                candIndex = checkIsInCandidate(pos);
                
                if (candIndex == m_currHiliteCand)
                {
                    // down and up in same candidate
                    emitCandUpSignal(candIndex);
                    m_inCandidateState = VFX_FALSE;
                    m_inArrowState = VCP_SEL_BOX_ARROW_TYPE_NONE;
                }
                else
                {
                    // down and up not in same candidate
                    emitCandAbortSignal(m_currHiliteCand);
                    m_inCandidateState = VFX_FALSE;
                    m_inArrowState = VCP_SEL_BOX_ARROW_TYPE_NONE;
                }
            }
            else
            {
                // both of candidate and arrow is not pressed
                // ignore
            }
            break;

        case VFX_PEN_EVENT_TYPE_ABORT:
            if (m_inArrowState != VCP_SEL_BOX_ARROW_TYPE_NONE)
            {
                // the arrow is pressed
                switch (m_inArrowState)
                {
                    case VCP_SEL_BOX_ARROW_TYPE_PREVIOUS:
                        m_preArrow->setState(VCP_SEL_BOX_ARROW_STATE_NORMAL);
                        break;

                    case VCP_SEL_BOX_ARROW_TYPE_NEXT:
                        m_nextArrow->setState(VCP_SEL_BOX_ARROW_STATE_NORMAL);
                        break;

                    default:
                        // invalid type
                        VFX_ASSERT(0);
                        break;
                }
                m_inArrowState = VCP_SEL_BOX_ARROW_TYPE_NONE;
                m_inCandidateState = VFX_FALSE;
            }
            else if (m_inCandidateState == VFX_TRUE)
            {
                // the candidate is pressed
                emitCandAbortSignal(m_currHiliteCand);
                setHiliteCandidate(-1);
                m_inCandidateState = VFX_FALSE;
                m_inArrowState = VCP_SEL_BOX_ARROW_TYPE_NONE;
            }
            else
            {
                // both of candidate and arrow is not pressed
                // ignore
            }
            break;

        default:
            return VFX_FALSE;
    }
    return VFX_TRUE;
}


void VcpSelBox::buildDefaultTheme()
{
    // TODO: get the system theme
}


VfxS32 VcpSelBox::getDefaultHeight()
{
    VfxS32 height = 0;
    VfxAdpFontEngine adp;
    
    // get the max height of font
    adp.getCharInfoForAllLang(m_theme.candFont, &height, NULL, NULL);
    
#if defined(__MMI_IME_FTE_ENHANCE__)
    height += (2 * (VCP_SEL_BOX_HEIGHT_SPACING + VCP_SEL_BOX_BORDER_WIDTH + VCP_SEL_BOX_FTE_EXTER_BORDER_WIDTH));

    if (height < VCP_SEL_BOX_FTE_HEIGHT_SMALL)
    {
        height = VCP_SEL_BOX_FTE_HEIGHT_SMALL;
        m_fteSize = VCP_SEL_BOX_SIZE_SMALL;
    }
    else if (height < VCP_SEL_BOX_FTE_HEIGHT_MEDIUM)
    {
        height = VCP_SEL_BOX_FTE_HEIGHT_MEDIUM;
        m_fteSize = VCP_SEL_BOX_SIZE_MEDIUM;
    }
    else if (height <= VCP_SEL_BOX_FTE_HEIGHT_LARGE)
    {
        height = VCP_SEL_BOX_FTE_HEIGHT_LARGE;
        m_fteSize = VCP_SEL_BOX_SIZE_LARGE;
    }
    else
    {
        // no proper height
        VFX_ASSERT(0);
    }
#else
    height += (2 * (VCP_SEL_BOX_HEIGHT_SPACING + VCP_SEL_BOX_BORDER_WIDTH));
#endif

    return height;
}


void VcpSelBox::buildArrowTheme(VcpSelBoxArrowThemeStruct &arrowTheme)
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    switch (m_fteSize)
    {
        case VCP_SEL_BOX_SIZE_SMALL:
            arrowTheme.imgNormalLeft = m_theme.leftArrowNormalImgSmall;
            arrowTheme.imgHiliteLeft = m_theme.leftArrowHiliteImgSmall;
            arrowTheme.imgDisabledLeft = m_theme.leftArrowDisabledImgSmall;
            arrowTheme.imgNormalRight = m_theme.rightArrowNormalImgSmall;
            arrowTheme.imgHiliteRight = m_theme.rightArrowHiliteImgSmall;
            arrowTheme.imgDisabledRight = m_theme.rightArrowDisabledImgSmall;
            break;

        case VCP_SEL_BOX_SIZE_MEDIUM:
            arrowTheme.imgNormalLeft = m_theme.leftArrowNormalImgMedium;
            arrowTheme.imgHiliteLeft = m_theme.leftArrowHiliteImgMedium;
            arrowTheme.imgDisabledLeft = m_theme.leftArrowDisabledImgMedium;
            arrowTheme.imgNormalRight = m_theme.rightArrowNormalImgMedium;
            arrowTheme.imgHiliteRight = m_theme.rightArrowHiliteImgMedium;
            arrowTheme.imgDisabledRight = m_theme.rightArrowDisabledImgMedium;
            break;

        case VCP_SEL_BOX_SIZE_LARGE:
            arrowTheme.imgNormalLeft = m_theme.leftArrowNormalImgLarge;
            arrowTheme.imgHiliteLeft = m_theme.leftArrowHiliteImgLarge;
            arrowTheme.imgDisabledLeft = m_theme.leftArrowDisabledImgLarge;
            arrowTheme.imgNormalRight = m_theme.rightArrowNormalImgLarge;
            arrowTheme.imgHiliteRight = m_theme.rightArrowHiliteImgLarge;
            arrowTheme.imgDisabledRight = m_theme.rightArrowDisabledImgLarge;
            break;

        default:
            // the height is invalid
            VFX_ASSERT(0);
            break;
    }
#else
        arrowTheme.colorNormal = m_theme.arrowNormalColor;
        arrowTheme.colorHilite = m_theme.arrowHiliteColor;
        arrowTheme.colorDisabled = m_theme.arrowDisabledColor;
#endif
}


void VcpSelBox::buildStarTheme(VcpSelBoxStarThemeStruct &starTheme)
{
    starTheme.font = m_theme.starFont;
    starTheme.color = m_theme.starColor;
}


void VcpSelBox::buildSeperatorTheme(VcpSelBoxSeperatorThemeStruct &seperatorTheme)
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    switch (m_fteSize)
    {
        case VCP_SEL_BOX_SIZE_SMALL:
            seperatorTheme.imageNormal = m_theme.seperatorNormalImgSmall;
            seperatorTheme.imageFocused = m_theme.seperatorFocusedImgSmall;
            break;

        case VCP_SEL_BOX_SIZE_MEDIUM:
            seperatorTheme.imageNormal = m_theme.seperatorNormalImgMedium;
            seperatorTheme.imageFocused = m_theme.seperatorFocusedImgMedium;
            break;

        case VCP_SEL_BOX_SIZE_LARGE:
            seperatorTheme.imageNormal = m_theme.seperatorNormalImgLarge;
            seperatorTheme.imageFocused = m_theme.seperatorFocusedImgLarge;
            break;

        default:
            // the height is invalid
            VFX_ASSERT(0);
            break;
    }
#else
    seperatorTheme.colorNormal = m_theme.seperatorNormalColor;
    seperatorTheme.colorFocused = m_theme.seperatorFocusedColor;
    seperatorTheme.width = m_theme.seperatorWidth;
#endif
}


void VcpSelBox::buildCandidateTheme(VcpSelBoxCandThemeStruct &candTheme)
{
    candTheme.labelColor = m_theme.labelColor;
    candTheme.labelFont = m_theme.labelFont;
    candTheme.textFont = m_theme.candFont;
    candTheme.normalTextColor = m_theme.candNormalColor;
    candTheme.radicalNormalTextColor = m_theme.candRadicalNormalColor;
    candTheme.hiliteTextColor = m_theme.candHiliteColor;
    candTheme.radicalHiliteTextColor = m_theme.candRadicalHiliteColor;
#if defined(__MMI_IME_FTE_ENHANCE__)
    switch (m_fteSize)
    {
        case VCP_SEL_BOX_SIZE_SMALL:
            candTheme.hiliteBgImg = m_theme.candHiliteBgImgSmall;
            candTheme.dullHiliteBgImg = m_theme.candDullHiliteBgImgSmall;
            candTheme.radicalHiliteBgImg = m_theme.candRadicalHiliteBgImgSmall;
            candTheme.radicalDullHiliteBgImg = m_theme.candRadicalDullHiliteBgImgSmall;
            break;

        case VCP_SEL_BOX_SIZE_MEDIUM:
            candTheme.hiliteBgImg = m_theme.candHiliteBgImgMedium;
            candTheme.dullHiliteBgImg = m_theme.candDullHiliteBgImgMedium;
            candTheme.radicalHiliteBgImg = m_theme.candRadicalHiliteBgImgMedium;
            candTheme.radicalDullHiliteBgImg = m_theme.candRadicalDullHiliteBgImgMedium;
            break;

        case VCP_SEL_BOX_SIZE_LARGE:
            candTheme.hiliteBgImg = m_theme.candHiliteBgImgLarge;
            candTheme.dullHiliteBgImg = m_theme.candDullHiliteBgImgLarge;
            candTheme.radicalHiliteBgImg = m_theme.candRadicalHiliteBgImgLarge;
            candTheme.radicalDullHiliteBgImg = m_theme.candRadicalDullHiliteBgImgLarge;
            break;

        default:
            // the height is invalid
            VFX_ASSERT(0);
            break;
    }
#else
    candTheme.hiliteBgColor = m_theme.candHiliteBgColor;
    candTheme.dullHiliteBgColor = m_theme.candDullHiliteBgColor;
    candTheme.radicalHiliteBgColor = m_theme.candRadicalHiliteBgColor;
    candTheme.radicalDullHiliteBgColor = m_theme.candRadicalDullHiliteBgColor;
#endif
}


VcpSelBoxArrowTypeEnum VcpSelBox::checkIsInArrow(const VfxPoint &pos)
{
    if ((m_preArrow != NULL) &&
        (m_preArrow->getState() != VCP_SEL_BOX_ARROW_STATE_DISABLED) &&
        (m_preArrow->getHidden() != VFX_TRUE))
    {
        if (m_preArrow->getRect().contains(pos) == VFX_TRUE)
        {
            return VCP_SEL_BOX_ARROW_TYPE_PREVIOUS;
        }
    }

    if ((m_nextArrow != NULL) &&
        (m_nextArrow->getState() != VCP_SEL_BOX_ARROW_STATE_DISABLED) &&
        (m_nextArrow->getHidden() != VFX_TRUE))
    {
        if (m_nextArrow->getRect().contains(pos) == VFX_TRUE)
        {
            return VCP_SEL_BOX_ARROW_TYPE_NEXT;
        }
    }

    return VCP_SEL_BOX_ARROW_TYPE_NONE;
}

    
VfxS32 VcpSelBox::checkIsInCandidate(const VfxPoint &pos)
{
    for (VfxS32 i = 0; i < m_candCount; i++)
    {
        if (m_candArray[i]->getRect().contains(pos) == VFX_TRUE)
        {
            return i;
        }
    }

    return -1;
}

#if defined __MMI_IME_CANDIDATE_GRID__

void VcpSelBox::onGridExpandPress(VfxObject *selBox, VfxId  index)
{
/* sending FF as a token to identify ; may change this later*/
    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);
    m_signalCandUp.postEmit(this, 0xFF);
}
#endif


void VcpSelBox::emitCandDownSignal(VfxS32 index)
{
    VFX_ASSERT((index >= 0) && (index < m_candCount));
    m_signalCandDown.postEmit(this, index);
}


void VcpSelBox::emitCandUpSignal(VfxS32 index)
{
    VFX_ASSERT((index >= 0) && (index < m_candCount));
    m_signalCandUp.postEmit(this, index);
}


void VcpSelBox::emitCandAbortSignal(VfxS32 index)
{
    VFX_ASSERT((index >= 0) && (index < m_candCount));
    m_signalCandAbort.postEmit(this, index);
}


void VcpSelBox::emitCandMoveSignal(VfxS32 index)
{
    VFX_ASSERT((index >= 0) && (index < m_candCount));
    m_signalCandMove.postEmit(this, index);
}


void VcpSelBox::emitArrowClickedSignal(VcpSelBoxArrowTypeEnum arrow)
{
    VFX_ASSERT((arrow == VCP_SEL_BOX_ARROW_TYPE_PREVIOUS) || (arrow == VCP_SEL_BOX_ARROW_TYPE_NEXT));
    if (arrow == VCP_SEL_BOX_ARROW_TYPE_PREVIOUS)
    {
        m_signalPreArrowClicked.postEmit(this);
    }
    else
    {
        m_signalNextArrowClicked.postEmit(this);
    }
}


void VcpSelBox::setArrowState()
{
    if (((m_style & VCP_SEL_BOX_STYLE_ARROW) != 0) &&
        ((m_flag & VCP_SEL_BOX_FLAG_SHOW_ARROW) != 0))
    {
        if (m_candCount == 0)
        {
            m_preArrow->setState(VCP_SEL_BOX_ARROW_STATE_DISABLED);
            m_nextArrow->setState(VCP_SEL_BOX_ARROW_STATE_DISABLED);
        }
        else if (m_candCount == 1)
        {
            if ((m_flag & VCP_SEL_BOX_FLAG_PRE_PAGE) != 0)
            {
                m_preArrow->setState(VCP_SEL_BOX_ARROW_STATE_NORMAL);
            }
            else
            {
                m_preArrow->setState(VCP_SEL_BOX_ARROW_STATE_DISABLED);
            }

            if ((m_flag & VCP_SEL_BOX_FLAG_LAST_PAGE) != 0)
            {
                m_nextArrow->setState(VCP_SEL_BOX_ARROW_STATE_DISABLED);
            }
            else if (m_candCount < m_outsideCandCount)
            {
                m_nextArrow->setState(VCP_SEL_BOX_ARROW_STATE_NORMAL);
            }
            else
            {
                if ((m_flag & VCP_SEL_BOX_FLAG_NEXT_PAGE) != 0)
                {
                    m_nextArrow->setState(VCP_SEL_BOX_ARROW_STATE_NORMAL);
                }
                else
                {
                    m_nextArrow->setState(VCP_SEL_BOX_ARROW_STATE_DISABLED);
                }
            }
        }
        else
        {
            if (m_currHiliteCand == -1)
            {
                if ((m_flag & VCP_SEL_BOX_FLAG_PRE_PAGE) != 0)
                {
                    m_preArrow->setState(VCP_SEL_BOX_ARROW_STATE_NORMAL);
                }
                else
                {
                    m_preArrow->setState(VCP_SEL_BOX_ARROW_STATE_DISABLED);
                }

                if ((m_flag & VCP_SEL_BOX_FLAG_LAST_PAGE) != 0)
                {
                    m_nextArrow->setState(VCP_SEL_BOX_ARROW_STATE_DISABLED);
                }
                else if (m_candCount < m_outsideCandCount)
                {
                    m_nextArrow->setState(VCP_SEL_BOX_ARROW_STATE_NORMAL);
                }
                else
                {
                    if ((m_flag & VCP_SEL_BOX_FLAG_NEXT_PAGE) != 0)
                    {
                        m_nextArrow->setState(VCP_SEL_BOX_ARROW_STATE_NORMAL);
                    }
                    else
                    {
                        m_nextArrow->setState(VCP_SEL_BOX_ARROW_STATE_DISABLED);
                    }
                }
            }
            else if (m_currHiliteCand == 0)
            {
                if ((m_flag & VCP_SEL_BOX_FLAG_PRE_PAGE) != 0)
                {
                    m_preArrow->setState(VCP_SEL_BOX_ARROW_STATE_NORMAL);
                }
                else
                {
                    m_preArrow->setState(VCP_SEL_BOX_ARROW_STATE_DISABLED);
                }

                m_nextArrow->setState(VCP_SEL_BOX_ARROW_STATE_NORMAL);
            }
            else if (m_currHiliteCand == (m_candCount - 1))
            {
                m_preArrow->setState(VCP_SEL_BOX_ARROW_STATE_NORMAL);

                if ((m_flag & VCP_SEL_BOX_FLAG_LAST_PAGE) != 0)
                {
                    m_nextArrow->setState(VCP_SEL_BOX_ARROW_STATE_DISABLED);
                }
                else if (m_candCount < m_outsideCandCount)
                {
                    m_nextArrow->setState(VCP_SEL_BOX_ARROW_STATE_NORMAL);
                }
                else
                {
                    if ((m_flag & VCP_SEL_BOX_FLAG_NEXT_PAGE) != 0)
                    {
                        m_nextArrow->setState(VCP_SEL_BOX_ARROW_STATE_NORMAL);
                    }
                    else
                    {
                        m_nextArrow->setState(VCP_SEL_BOX_ARROW_STATE_DISABLED);
                    }
                }
            }
            else
            {
                m_preArrow->setState(VCP_SEL_BOX_ARROW_STATE_NORMAL);
                m_nextArrow->setState(VCP_SEL_BOX_ARROW_STATE_NORMAL);
            }
        }
    }
}


#if defined(__MMI_IME_FTE_ENHANCE__)
/***************************************************************************** 
 * Class VcpResizableCompositionBox
 *****************************************************************************/
VFX_IMPLEMENT_CLASS(VCP_RESIZABLE_COMPOSITION_BOX, VcpResizableCompositionBox, VfxControl);


void VcpResizableCompositionBox::setText(const VfxWString &text)
{
    m_text = text;
    
    // set the text and calculate the size of box
    m_textFrame->setAutoResized(VFX_TRUE);
    m_textFrame->setString(m_text);
    VfxS32 textWidth = m_textFrame->getSize().width;
    VfxS32 textHeight = m_textFrame->getSize().height;
    VfxS32 height = getSize().height;
    if ((VfxU32)textWidth <= m_maxWidth)
    {
        // the width of box is same as text frame
        setSize(textWidth+2*VCP_RESIZABLE_COMPOSITION_BOX_TEXT_X_OFFSET, height);
    }
    else
    {
        // the width of box is the max width and text is right align
        m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
        m_textFrame->setAutoResized(VFX_FALSE);
        m_textFrame->setSize(m_maxWidth, textHeight);
        setSize(m_maxWidth, height);
    }

    // set the position of text frame
    VfxS32 x = 0;
    VfxS32 y = (height - m_coveredHeight - textHeight - VCP_RESIZABLE_COMPOSITION_BOX_TOP_GAP) / 2 + VCP_RESIZABLE_COMPOSITION_BOX_TOP_GAP;
    m_textFrame->setPos(x+VCP_RESIZABLE_COMPOSITION_BOX_TEXT_X_OFFSET, y);

    invalidate();
}


void VcpResizableCompositionBox::setTheme(const VcpResizableCompositionBoxThemeStruct &theme)
{
    m_theme = theme;
    
    VfxS32 height = getDefaultHeight();
    setSize(0, height);
    m_textFrame->setColor(m_theme.textColor);
    m_textFrame->setFont(m_theme.textFont);
    setText(m_text);

    invalidate();
}


void VcpResizableCompositionBox::onDraw(VfxDrawContext &dc)
{
    VfxImageSrc *image=NULL;
    switch (m_size)
    {
        case VCP_RESIZABLE_COMPOSITION_BOX_SIZE_SMALL:
            image = &(m_theme.bgImageSmall);
            break;

        case VCP_RESIZABLE_COMPOSITION_BOX_SIZE_MEDIUM:
            image = &(m_theme.bgImageMedium);
            break;

        case VCP_RESIZABLE_COMPOSITION_BOX_SIZE_LARGE:
            image = &(m_theme.bgImageLarge);
            break;

        default:
            // the height is invalid
            VFX_ASSERT(0);
            break;
    }

    // check the image is valid
    if (image->isNull())
    {
        VFX_ASSERT(0);
    }

    // draw the image
    VfxS32 width = getSize().width;
    VfxS32 height = getSize().height;
    VfxRect rect(0 , 0, width, height);
    dc.drawResizedImage(rect, *image);
}


void VcpResizableCompositionBox::onInit()
{
    VfxControl::onInit();

    buildDefaultTheme();

    VfxS32 height = getDefaultHeight();
    setSize(0, height);

    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);
    m_textFrame->setColor(m_theme.textColor);
    m_textFrame->setFont(m_theme.textFont);
    m_textFrame->setMargins(VCP_RESIZABLE_COMPOSITION_BOX_SPACING, 0, VCP_RESIZABLE_COMPOSITION_BOX_SPACING, 0);
}


VfxBool VcpResizableCompositionBox::onPenInput(VfxPenEvent &event)
{
    VfxPoint pos = event.getRelPos(this);
    VfxRect rect(0, 0, getSize().width, getSize().height);
    
    if ((event.type == VFX_PEN_EVENT_TYPE_UP) && (rect.contains(pos) == VFX_TRUE))
    {
        // up on box, emit signal
        m_signalClicked.postEmit(this);
    }

    return VFX_TRUE;
}


void VcpResizableCompositionBox::buildDefaultTheme()
{
    // TODO: get the system theme
}


VfxS32 VcpResizableCompositionBox::getDefaultHeight()
{
    VfxS32 height = 0;
    VfxAdpFontEngine adp;
    
    // get the max height of font
    adp.getCharInfoForAllLang(m_theme.textFont, &height, NULL, NULL);
    
    height = m_coveredHeight + height + VCP_RESIZABLE_COMPOSITION_BOX_TOP_GAP;

    if (height < VCP_RESIZABLE_COMPOSITION_BOX_HEIGHT_SMALL)
    {
        height = VCP_RESIZABLE_COMPOSITION_BOX_HEIGHT_SMALL;
        m_size = VCP_RESIZABLE_COMPOSITION_BOX_SIZE_SMALL;
    }
    else if (height < VCP_RESIZABLE_COMPOSITION_BOX_HEIGHT_MEDIUM)
    {
        height = VCP_RESIZABLE_COMPOSITION_BOX_HEIGHT_MEDIUM;
        m_size = VCP_RESIZABLE_COMPOSITION_BOX_SIZE_MEDIUM;
    }
    else if (height <= VCP_RESIZABLE_COMPOSITION_BOX_HEIGHT_LARGE)
    {
        height = VCP_RESIZABLE_COMPOSITION_BOX_HEIGHT_LARGE;
        m_size = VCP_RESIZABLE_COMPOSITION_BOX_SIZE_LARGE;
    }
    else
    {
        // no proper height
        VFX_ASSERT(0);
    }

    return height;
}

#endif /* __MMI_IME_FTE_ENHANCE__ */
#if defined __MMI_IME_SCROLLING_COMPOSITION__

#define NUM_IN_ROW 5
#define NUM_IN_COL   4
#define ROW_MARGIN   2
#define COL_MARGIN   2
#define MAX_BUTTONS 16

VcpScrollableSelBox::VcpScrollableSelBox() :
m_candCount(0)
{

}


VfxBool VcpScrollableSelBox::setHiliteCandidate(VfxS32 hiliteIndex)
{
    m_currHiliteCand = hiliteIndex ;
    return VFX_TRUE;
}



void VcpScrollableSelBox::onInit()
{
    VcpScrollable::onInit();

    setImgContent(VfxImageSrc(m_theme.bgImageSmall));

    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

}

VfxS32 VcpScrollableSelBox::getHiliteCandidate()
{
    return m_currHiliteCand;
}


/* this function will be updated once we get coordinates from artist */
VfxS32 VcpScrollableSelBox::update(const VfxWChar *candStr, VfxS32 count, VfxS32 hiliteIndex, VfxU32 flag)
{
    VfxU32 width_unit = this->getSize().width;
    VfxU32 height_unit = this->getSize().height/(NUM_IN_COL);//leave hide button

    //set bg

  
    setImgContent(VfxImageSrc(m_theme.scrollableboxBg));

    //set scrollable area

    // clear previous candidate and seperator
    for (VfxU32 i = 0; i < m_candCount; i++)
    {
        {
            VFX_OBJ_CLOSE(m_btnArray[i]);
        }
    }
    //clear blank buttons
    if((m_candCount)&&(m_candCount < NUM_IN_COL ))
    {

        for (VfxU32 i =  m_candCount; i !=NUM_IN_COL; i++)
        {
            {
                VFX_OBJ_CLOSE(m_btnArray[i]);
            }
        }
    }


    m_candCount = count ;
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(m_theme.labelFont.size);
    //create  new button objects

    VcpStateImage imgBG;
    imgBG.setImage(m_theme.scrollableboxCandBg,m_theme.scrollableboxCandBgHl,m_theme.scrollableboxCandBg ,m_theme.scrollableboxCandBg  ); //use theme
    VfxS32  i;
    for (i= 0 ; i < count ; i++)
    {

        VFX_OBJ_CREATE(m_btnArray[i],VcpScrollingTextButton,this);
        VfxWString text;
        text = VFX_WSTR_MEM(candStr);
        m_btnArray[i]->setBgImageList(imgBG);

        m_btnArray[i]->setIsHighlighted(VFX_TRUE);
        m_btnArray[i]->setScrollOnHighlight(VFX_TRUE);
        m_btnArray[i]->setPos(0,i*height_unit);
        m_btnArray[i]->setSize(width_unit,height_unit);
        m_btnArray[i]->setTextFont(m_theme.candFont);
        m_btnArray[i]->setTextColor(m_theme.candNormalColor);
        m_btnArray[i]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnArray[i]->setText(text);
        m_btnArray[i]->m_signalClicked.connect(this, &VcpScrollableSelBox::onButtonClick);
        m_btnArray[i]->setId(i);
        /* to advance for next button */
        while((*candStr) != 0)
        {
            candStr++;
        }
        while((*candStr) == 0)
        {
            candStr++;
        }
    }
    setViewRect(VfxRect(0, 0,width_unit, height_unit*4));
    setBounds(VfxRect(0, 0,width_unit,height_unit*4));
    setContentSize(VfxSize(width_unit,height_unit*m_candCount));
    setContentOffset(VfxPoint(0,0));

    if (count <NUM_IN_COL)
    {
        for (VfxU32 i=count ; i <(NUM_IN_COL); i++)
    {
        VFX_OBJ_CREATE(m_btnArray[i],VcpScrollingTextButton,this);
        m_btnArray[i]->setBgImageList(imgBG);

        m_btnArray[i]->setIsHighlighted(VFX_TRUE);
        m_btnArray[i]->setScrollOnHighlight(VFX_TRUE);

        m_btnArray[i]->setPos(0,( i)*height_unit);
        m_btnArray[i]->setSize(width_unit,height_unit);
        m_btnArray[i]->setIsUnhittable(VFX_TRUE);
    }
    }
    return m_candCount;
}

void VcpScrollableSelBox::onButtonClick(VfxObject *selBox, VfxId index)
{
    VFX_ASSERT(index < m_candCount);
    m_signalCandDown.postEmit(this, index);
    m_signalCandUp.postEmit(this, index);
    m_currHiliteCand = index;

}

void  VcpScrollableSelBox::setTheme(const VcpSelBoxThemeStruct &theme)
{
    m_theme = theme;
}


#endif

#if defined __MMI_IME_CANDIDATE_GRID__
VcpCandGrid::VcpCandGrid() :
m_repeatTimer(NULL),
m_candCount(0)
{
    //m_newWordStr = VFX_WSTR("New word");


}


void VcpCandGrid::setNewWordString(const VfxWString &str)
{
    m_newWordStr = str;
}


VfxBool VcpCandGrid::setHiliteCandidate(VfxS32 hiliteIndex)
{
    m_currHiliteCand = hiliteIndex ;
    return VFX_TRUE;
}


VfxS32 VcpCandGrid::getHiliteCandidate()
{
    return m_currHiliteCand;
}

#define VCP_CANDGRID_REPEAT_DELAY                     150
void VcpCandGrid::onInit()
{

    vrt_size_struct mainScreenSize;
    vrt_color_type_enum mainScreenColorFormat;
    vrt_sys_get_main_screen_info(&mainScreenSize, &mainScreenColorFormat);

    VfxU32 height_unit =( this->getSize().height- (NUM_IN_COL+1)*COL_MARGIN)/NUM_IN_COL;


    VfxControl::onInit();
    VcpStateImage imgBG;
    imgBG.setImage(m_theme.bgImageLarge,m_theme.candHiliteBgImgLarge,m_theme.candHiliteBgImgLarge ,m_theme.candHiliteBgImgLarge  ); //use theme
    VFX_OBJ_CREATE(m_repeatTimer, VfxTimer, this);
    m_repeatTimer->setStartDelay(VCP_CANDGRID_REPEAT_DELAY);
    m_repeatTimer->m_signalTick.connect(this, &VcpCandGrid::repeatTimeup);

    setImgContent(VfxImageSrc(m_theme.focusedBgImageSmall));

    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

       //create fixed buttons
        VFX_OBJ_CREATE(m_backspace,VcpButton,this);
        VFX_OBJ_CREATE(m_prePage,VcpButton,this);
        VFX_OBJ_CREATE(m_nextPage,VcpButton,this);
        VFX_OBJ_CREATE(m_back,VcpButton,this);
 
        for (VfxU32 i = 0; i < MAX_BUTTONS; i++)
        {
            VFX_OBJ_CREATE(m_candArray[i],VcpScrollingTextButton,this);
            m_candArray[i]->setIsHighlighted(VFX_TRUE);
            m_candArray[i]->setScrollOnHighlight(VFX_TRUE);
        }


}




void VcpCandGrid::onButtonDown(VfxObject *selBox, VfxId index,VcpButtonStateEnum state)
{
 
	
	if (state == VCP_BUTTON_STATE_PRESSED && (this->getHidden() == VFX_FALSE) )
	{
	//start timer for holding button
		m_repeatTimer->start();
	}


}

void VcpCandGrid::repeatTimeup(VfxTimer *timerFunc)
{
	//call deletion event or up down event 
    if  (this->getHidden() == VFX_FALSE)
    {
        //start timer for holding button
	m_signalGridClick.postEmit(this,VCP_CAND_GRID_BACKSPACE );
    }

	if  (this->getHidden() == VFX_FALSE)
	{
	//start timer for holding button
		m_repeatTimer->start();
	}
    
}



void VcpCandGrid::onButtonClick(VfxObject *selBox, VfxId index)
{
//stop holding event
     m_repeatTimer->stop();
    if  (this->getHidden() == VFX_FALSE)
    {
    if (index < VCP_CAND_GRID_CANDIDATE)
    {
       setHiliteCandidate( index);
    }
    else
    {
        vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);
    }
    m_signalGridClick.postEmit(this, index);
}
}


void VcpCandGrid:: layoutButtons()
{

    vrt_size_struct mainScreenSize;
    vrt_color_type_enum mainScreenColorFormat;
    vrt_sys_get_main_screen_info(&mainScreenSize, &mainScreenColorFormat);
    
    VfxU32 height_unit =( this->getSize().height- (NUM_IN_COL+1)*COL_MARGIN)/NUM_IN_COL;

    
    //set background
    setImgContent(VfxImageSrc(m_theme.gridBg));
    
    //set identification
    m_backspace->setId(VCP_CAND_GRID_BACKSPACE);
    m_prePage->setId(VCP_CAND_GRID_PREPAGE);
    m_nextPage->setId(VCP_CAND_GRID_NEXTPAGE);
    m_back->setId(VCP_CAND_GRID_BACK);

   
    m_backspace->setAutoAnimate(VFX_FALSE);
    m_prePage->setAutoAnimate(VFX_FALSE);
    m_nextPage->setAutoAnimate(VFX_FALSE);   
    m_back->setAutoAnimate(VFX_FALSE);

    //placement type
    m_backspace->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    m_prePage->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    m_nextPage->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    m_back->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);

    VcpStateImage imgBG,imgFgBackspace,imgFgBack,imgFgPrePage,imgFgNextImage;


    //buttons background

    imgBG.setImage(m_theme.gridFixedButtonBg,m_theme.gridFixedButtonBgHl,m_theme.gridFixedButtonBg ,m_theme.gridFixedButtonBg  ); 

    // bg images
     m_backspace->setBgImageList(imgBG);
     m_prePage->setBgImageList(imgBG);
     m_nextPage->setBgImageList(imgBG);
     m_back->setBgImageList(imgBG);

    //images for foreground fixed buttons
    
    imgFgBack.setImage(m_theme.backImg,m_theme.backImg,m_theme.backImg ,m_theme.backImg  );
    imgFgPrePage.setImage(m_theme.arrowUpImg,m_theme.arrowUpImg,m_theme.arrowUpDisableImg,m_theme.arrowUpImg); 
    imgFgNextImage.setImage(m_theme.arrowDownImg,m_theme.arrowDownImg,m_theme.arrowDownDisableImg,m_theme.arrowDownImg);
    imgFgBackspace.setImage(m_theme.deleteImg,m_theme.deleteImg,m_theme.deleteImg,m_theme.deleteImg); 


    //fg image
    m_back->setImage(imgFgBack);    
    m_prePage->setImage(imgFgPrePage);
    m_nextPage->setImage(imgFgNextImage);
    m_backspace->setImage(imgFgBackspace);


    //event handling on fixed buttons
    m_backspace->m_signalClicked.connect(this, &VcpCandGrid::onButtonClick);
    m_backspace->m_signalStateChanged.connect(this, &VcpCandGrid::onButtonDown);

    m_prePage->m_signalClicked.connect(this, &VcpCandGrid::onButtonClick);
    m_nextPage->m_signalClicked.connect(this, &VcpCandGrid::onButtonClick);
    m_back->m_signalClicked.connect(this, &VcpCandGrid::onButtonClick);

    imgBG.setImage(m_theme.gridCandBg,m_theme.gridCandBgHl,m_theme.gridCandBg ,m_theme.gridCandBg  ); 

    for(VfxU32 i = 0 ; i <MAX_BUTTONS ; i++)
    {
        m_candArray[i]->setAutoAnimate(VFX_FALSE);
        m_candArray[i]->setBgImageList(imgBG);
    }  


}

VfxS32 VcpCandGrid::update(const VfxWChar *candStr, VfxS32 count, VfxS32 hiliteIndex, VfxU32 flag)
{
     vrt_size_struct mainScreenSize;
    vrt_color_type_enum mainScreenColorFormat;
    vrt_sys_get_main_screen_info(&mainScreenSize, &mainScreenColorFormat);
    VfxS32 width_unit = (mainScreenSize.width - (NUM_IN_ROW+1)*ROW_MARGIN)/NUM_IN_ROW;
    VfxS32 height_unit =( this->getSize().height- (NUM_IN_COL+1)*COL_MARGIN)/NUM_IN_COL;
    

 //positions  of  fixed buttons
    m_backspace->setPos(width_unit*(NUM_IN_ROW - 1)+(NUM_IN_ROW)*ROW_MARGIN,height_unit*0+1*COL_MARGIN);
    m_prePage->setPos(width_unit*(NUM_IN_ROW - 1)+(NUM_IN_ROW)*ROW_MARGIN,height_unit*1+2*COL_MARGIN);
    m_nextPage->setPos(width_unit*(NUM_IN_ROW - 1)+(NUM_IN_ROW)*ROW_MARGIN ,height_unit*2+3*COL_MARGIN);
    m_back->setPos(width_unit*(NUM_IN_ROW - 1)+(NUM_IN_ROW)*ROW_MARGIN ,height_unit*3+4*COL_MARGIN);
    
    //size  of  fixed buttons
    m_backspace->setSize(width_unit, height_unit);
    m_prePage->setSize(width_unit, height_unit);
    m_nextPage->setSize(width_unit, height_unit);
    m_back->setSize(width_unit, height_unit);

    m_backspace->setAutoAnimate(VFX_FALSE);
    m_prePage->setAutoAnimate(VFX_FALSE);
    m_nextPage->setAutoAnimate(VFX_FALSE);
    m_back->setAutoAnimate(VFX_FALSE);




   //set state of these buttons based upon flags received

   
    m_candCount = 0;

 
//the resizable candiadtes 

    VfxS32 index =0;
    VfxS32 empty_buttons =0;
    VfxS32 consumed_blocks =0;
    VfxS32 row =0;
    VfxS32 j;
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(m_theme.labelFont.size);

    for(VfxU32 i = 0 ; i <MAX_BUTTONS ; i++)
    {
        m_candArray[i]->setHidden(VFX_TRUE);
    }

    //start adjusting row by row
    while ( row != NUM_IN_ROW)     
    {
        VfxWString text;

    if (count == 0)
        break;

#if defined(__MMI_IME_USER_DATABASE__)
        if ((*candStr) == VCP_SEL_BOX_USER_DATABASE_NEW_WORD)
        {
            text = m_newWordStr;
        }
        else
#endif
        {
        text = VFX_WSTR_MEM(candStr);
        }


        //update button for candidates soem part must move to init
        m_candCount++;
        m_candArray[index]->setId(index);
        m_candArray[index]->setSize(0,0);
        m_candArray[index]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_candArray[index]->setIsAutoResized(VFX_TRUE,width_unit,width_unit*NUM_IN_COL +(NUM_IN_COL -1)*COL_MARGIN );
        m_candArray[index]->setTextFont(m_theme.candFont);
        m_candArray[index]->setHidden(VFX_FALSE);//in case they were hidden


        if (::mmi_ime_word_is_redicals((UI_character_type)(text.getItem(0))))
        {
            m_candArray[index]->setTextColor(m_theme.candRadicalHiliteColor);
        }
        else
        {
            m_candArray[index]->setTextColor(m_theme.candNormalColor);
        }
        
        m_candArray[index]->setTextColor(m_theme.candNormalColor);
        m_candArray[index]->setText(text);
        m_candArray[index]->setIsUnhittable(VFX_FALSE);
        m_candArray[index]->setPos(width_unit*consumed_blocks+ (consumed_blocks +1)*COL_MARGIN ,row*height_unit+(row+1)*ROW_MARGIN);
        m_candArray[index]->m_signalClicked.connect(this, &VcpCandGrid::onButtonClick);
        m_candArray[index]->forceUpdate();
        
        //determine how many width units it needs
        for( j=1 ; j<4;j++)
        {
            if(m_candArray[index]->getSize().width>(width_unit*j))
                continue;
            else
                break;
    }
        m_candArray[index]->setIsAutoResized(VFX_FALSE);


        //can we provide?
        if( j > NUM_IN_COL - consumed_blocks)            //we cannot adjust t here      so move this button to next line
    {
            //make pevious block bigger emaining uncosumed blocks in the row
      
            
            VfxU32 prev_size = m_candArray[index-1]->getSize().width + width_unit*(NUM_IN_COL - consumed_blocks) + j*COL_MARGIN ;
            m_candArray[index-1]->setSize(prev_size ,height_unit);
                  
            row ++;
            consumed_blocks =0;
            if( row == NUM_IN_COL)
            {
                //this one is the last one and cant fit , so destroy it
                 m_candArray[index]->setHidden(VFX_TRUE);
                 m_candCount--;
            }
            else
            {
            m_candArray[index]->setPos(width_unit*consumed_blocks+ (consumed_blocks +1)*COL_MARGIN ,row*height_unit+(row+1)*ROW_MARGIN);
            consumed_blocks = j;
            }
        }
        else
        {
            consumed_blocks +=j;
            if (consumed_blocks == NUM_IN_COL)
            {
                consumed_blocks =0;
                row ++;
        }         
        }         
        m_candArray[index]->setSize(width_unit*(j) + (j-1)*COL_MARGIN, height_unit); // based upon length  

        index++;
        if ((index == MAX_BUTTONS) || (index ==count) ||(row >(NUM_IN_COL-1) ))
        break;

        /* to advance for next button */
        if((*candStr) == 0xFFFF)
            break;
        while((*candStr) != 0)
        {
            candStr++;
        }
        while((*candStr) == 0)
        {
            candStr++;
            if(  (*candStr) == 0)
            break;
        }
          if(  (*candStr) == 0)
              break;

    }
    VfxU32 cand_blocks = (row* NUM_IN_COL) + consumed_blocks;

    if (cand_blocks <MAX_BUTTONS)
    {
        //draw rest of blocks empty and get out 

        empty_buttons=MAX_BUTTONS- cand_blocks;
        VfxU32 pos = consumed_blocks;
        for ( VfxS32 k =0 ; k<empty_buttons; k++)
        {
            m_candArray[index]->setHidden(VFX_FALSE);//in case they were hidden
            m_candArray[index]->setPos(width_unit*pos +( pos+1)*COL_MARGIN ,row*height_unit+(row+1)*ROW_MARGIN);
            m_candArray[index]->setSize(width_unit*(1),height_unit); 
            m_candArray[index]->setIsUnhittable(VFX_TRUE);
            m_candArray[index]->setText(VFX_WSTR(""));            
            pos++;
            if(pos == NUM_IN_COL)
            {
                pos =0;
                row++;
            }
            index++;
        }
    }


    if ((flag & VCP_SEL_BOX_FLAG_PRE_PAGE) == 0)
    {
       m_prePage->setIsDisabled(VFX_TRUE);
    }
    else
    {
       m_prePage->setIsDisabled(VFX_FALSE);
    }



    if ((flag & VCP_SEL_BOX_FLAG_NEXT_PAGE) == 0)
    {
       m_nextPage->setIsDisabled(VFX_TRUE);
       if (m_candCount <count)
       {
             m_nextPage->setIsDisabled(VFX_FALSE);
       }
    }
    else
    {
       m_nextPage->setIsDisabled(VFX_FALSE);
    }



  
    
   // VFX_OBJ_GET_INSTANCE(VfxRenderer)->debugDump(); // Break here. After this line, check the modis command line.
     return m_candCount;
}


void  VcpCandGrid::setTheme(const VcpSelBoxThemeStruct &theme)
{

    m_theme = theme;

}

#endif


