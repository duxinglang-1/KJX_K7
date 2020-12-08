/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_desktop_bar.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the bars.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "mmi_rp_vapp_desktop_def.h"
#include "vapp_desktop_bar.h"


/*****************************************************************************
 * Bar Class
 *****************************************************************************/

VappDesktopBar::VappDesktopBar() :
    m_isFolded(VFX_FALSE),
    m_timerFolding(NULL)
{
    // Do nothing.
}


void VappDesktopBar::onInit()
{
    VfxControl::onInit();

    //
    // This frame
    //
    setAutoAnimate(VFX_TRUE);

    //
    // Timer to emit "folding changed" signal
    //
    VFX_OBJ_CREATE(m_timerFolding, VfxTimer, this);
    m_timerFolding->setStartDelay(AUTO_ANIMATE_TIME);
    m_timerFolding->m_signalTick.connect(this, &VappDesktopBar::onTimerFolded);
}


void VappDesktopBar::onDeinit()
{
    VfxControl::onDeinit();
}


void VappDesktopBar::onFold()
{
    // Do nothing.
}


void VappDesktopBar::onUnfold()
{
    // Do nothing.
}


void VappDesktopBar::fold(VfxBool isAnimatable)
{
    if (!m_isFolded)
    {
        VfxAutoAnimate::begin();

        if (isAnimatable)
        {
            VfxAutoAnimate::setDuration(AUTO_ANIMATE_TIME);
            VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        }
        else
        {
            VfxAutoAnimate::setDisable(VFX_TRUE);
        }

        onFold();

        m_isFolded = VFX_TRUE;

        prepareSignal(isAnimatable);

        VfxAutoAnimate::commit();
    }
}


void VappDesktopBar::unfold(VfxBool isAnimatable)
{
    if (m_isFolded)
    {
        VfxAutoAnimate::begin();

        if (isAnimatable)
        {
            VfxAutoAnimate::setDuration(AUTO_ANIMATE_TIME);
            VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        }
        else
        {
            VfxAutoAnimate::setDisable(VFX_TRUE);
        }

        onUnfold();

        m_isFolded = VFX_FALSE;

        prepareSignal(isAnimatable);

        VfxAutoAnimate::commit();
    }
}


VfxBool VappDesktopBar::isFolded()
{
    return m_isFolded;
}


void VappDesktopBar::prepareSignal(VfxBool isAnimatable)
{
    //
    // If auto animation is not disabled, start timer to emit the
    // "folding changed" signal later; otherwise, emit it right now.
    //
    if (isAnimatable)
    {
        m_timerFolding->start();
    }
    else
    {
        m_timerFolding->stop();
        m_signalFoldingChanged.emit(this);
    }
}


void VappDesktopBar::onTimerFolded(VfxTimer *timer)
{
    VFX_ASSERT(timer && timer == m_timerFolding);

    m_signalFoldingChanged.emit(this);
}


/*****************************************************************************
 * Page Indicator Class
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappDesktopPageIndicator", VappDesktopPageIndicator, VappDesktopBar);


VappDesktopPageIndicator::VappDesktopPageIndicator() :
    m_index(0)
{
    for (VfxS32 i = 0; i < VAPP_DESKTOP_MAX_PAGE_NUM; i++)
    {
        m_dot[i] = NULL;
    }
}


void VappDesktopPageIndicator::onInit()
{
    VappDesktopBar::onInit();

    VfxSize parentSize = getParentFrame()->getSize();

    //
    // This Frame
    //
    setAutoAnimate(VFX_FALSE);
    setAnchor(VfxFPoint(0.5f, 0.0f));
    setPos(parentSize.width / 2, 0);
    setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);

    VfxSize size;

    size.width = (getDotSize().width + GAP) * VAPP_DESKTOP_MAX_PAGE_NUM +
                 LEFT_GAP + RIGHT_GAP - GAP;

    size.height = HEIGHT;

    setSize(size);

    //
    // Dot Images
    //
    for (VfxS32 i = 0; i < VAPP_DESKTOP_MAX_PAGE_NUM; i++)
    {
        VFX_OBJ_CREATE(m_dot[i], VfxImageFrame, this);
        m_dot[i]->setResId(IMG_ID_VAPP_DESKTOP_PAGE_INDICATOR_NORMAL);
        m_dot[i]->setAnchor(VfxFPoint(0.5f, 0.5f));
        m_dot[i]->setPos(getDotPos(i));
        m_dot[i]->setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);
    }

    //
    // Initialize the highlighted index.
    //
    setIndex(0);
}


VfxBool VappDesktopPageIndicator::onPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            setHighlighted(VFX_TRUE);
            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
            if (containPoint(event.getRelPos(this)))
            {
                setHighlighted(VFX_TRUE);
            }
            else
            {
                setHighlighted(VFX_FALSE);
            }
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            setHighlighted(VFX_FALSE);

            if (containPoint(event.getRelPos(this)))
            {
                VfxRenderer *render = VFX_OBJ_GET_INSTANCE(VfxRenderer);

                render->suspendUntilCommit();

                m_signalClicked.emit(this);
            }

            break;

        case VFX_PEN_EVENT_TYPE_ABORT:
            setHighlighted(VFX_FALSE);
            break;

        default:
            break;
    }

    return VFX_TRUE;
}


void VappDesktopPageIndicator::onFold()
{
    VappDesktopBar::onFold();

    setHidden(VFX_TRUE);
}


void VappDesktopPageIndicator::onUnfold()
{
    setHidden(VFX_FALSE);

    VappDesktopBar::onUnfold();
}


void VappDesktopPageIndicator::setIndex(VfxS32 idx)
{
    if (idx < 0 || idx >= VAPP_DESKTOP_MAX_PAGE_NUM)
    {
        return;
    }

    m_dot[m_index]->setResId(IMG_ID_VAPP_DESKTOP_PAGE_INDICATOR_NORMAL);

    m_index = idx;
    m_dot[m_index]->setResId(IMG_ID_VAPP_DESKTOP_PAGE_INDICATOR_HIGHLIGHTED);
}


VfxS32 VappDesktopPageIndicator::getIndex(void) const
{
    return m_index;
}


VfxBool VappDesktopPageIndicator::isHitted(VfxPenEvent &event)
{
    if (getHidden())
    {
        return VFX_FALSE;
    }

    VfxRect bounds = getBounds();

    bounds.size.height = HITTABLE_HEIGHT;

    return bounds.contains(event.getRelPos(this));
}


VfxSize VappDesktopPageIndicator::getDotSize() const
{
    VfxImageSrc dot(IMG_ID_VAPP_DESKTOP_PAGE_INDICATOR_NORMAL);

    return dot.getSize();
}


VfxPoint VappDesktopPageIndicator::getDotPos(VfxS32 idx) const
{
    VFX_ASSERT(idx >= 0 && idx < VAPP_DESKTOP_MAX_PAGE_NUM);

    // Get the dot's size.
    VfxSize dotSize = getDotSize();

    // Calculate the dot's position.
    VfxPoint pos;
    pos.x = LEFT_GAP + (dotSize.width / 2) + (dotSize.width + GAP) * idx;
    pos.y = HEIGHT / 2;

    return pos;
}


void VappDesktopPageIndicator::setHighlighted(VfxBool isOn)
{
    if (isOn)
    {
        setOpacity(0.6f);
    }
    else
    {
        setOpacity(1.0f);
    }
}


/*****************************************************************************
 * Shortcut Bar Class
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappDesktopShortcutBar", VappDesktopShortcutBar, VappDesktopBar);


VappDesktopShortcutBar::VappDesktopShortcutBar() :
    m_bgImg(NULL),
    m_shortcut(NULL)
{
    // Do nothing.
}


void VappDesktopShortcutBar::onInit()
{
    VappDesktopBar::onInit();

    VfxSize parentSize = getParentFrame()->getSize();

    //
    // Background Image. Image is a 9-slices image. Set its size specifically.
    //
    VFX_OBJ_CREATE(m_bgImg, VfxImageFrame, this);
    m_bgImg->setResId(IMG_ID_VAPP_DESKTOP_SHORTCUT_BG);

    VfxSize bgImgSize = m_bgImg->getSize();
    bgImgSize.width = parentSize.width;

    m_bgImg->setSize(bgImgSize);
    m_bgImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    //
    // This Frame
    //
    setAnchor(VfxFPoint(0.0f, 1.0f));
    setPos(0, parentSize.height);
    setBounds(m_bgImg->getBounds());

    //
    // Shortcut Bar
    //
    VFX_OBJ_CREATE(m_shortcut, VappDrawerShortcutBar, this);
    m_shortcut->setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);
}


void VappDesktopShortcutBar::onDeinit()
{
    VappDesktopBar::onDeinit();
}


void VappDesktopShortcutBar::onFold()
{
    VappDesktopBar::onFold();

    VfxFPoint anchor = getAnchor();
    anchor.y = 0.0f;
    setAnchor(anchor);

    setHidden(VFX_TRUE);
}


void VappDesktopShortcutBar::onUnfold()
{
    setHidden(VFX_FALSE);

    VfxFPoint anchor = getAnchor();
    anchor.y = 1.0f;
    setAnchor(anchor);

    VappDesktopBar::onUnfold();
}


/*****************************************************************************
 * Toolbar Class
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappDesktopToolbar", VappDesktopToolbar, VappDesktopBar);


const VappDesktopToolbar::ButtonEntry VappDesktopToolbar::s_buttonTbl[] =
{
    VappDesktopToolbar::ButtonEntry(
        VappDesktopToolbar::BUTTON_ADD_WIDGET,
        STR_ID_VAPP_DESKTOP_ADD_WIDGET,
        IMG_ID_VAPP_DESKTOP_TOOBAR_ADD_WIDGET)
    ,
    VappDesktopToolbar::ButtonEntry(
        VappDesktopToolbar::BUTTON_ADD_SHORTCUT,
        STR_ID_VAPP_DESKTOP_ADD_SHORTCUT,
        IMG_ID_VAPP_DESKTOP_TOOBAR_ADD_APP)
};


VappDesktopToolbar::VappDesktopToolbar()
{
    for (VfxS32 i = 0; i < BUTTON_TOTAL; i++)
    {
        m_button[i] = NULL;
    }
}


void VappDesktopToolbar::onInit()
{
    VappDesktopBar::onInit();

    VfxSize parentSize = getParentFrame()->getSize();

    //
    // This Frame
    //
    setAnchor(VfxFPoint(0.0f, 1.0f));
    setPos(0, parentSize.height);
    setSize(parentSize.width, HEIGHT);

    //
    // Button and Separate line
    //
    VcpStateImage bgImgList;
    bgImgList.setImage(
                IMG_ID_VAPP_DESKTOP_TOOBAR_BG_NORMAL,
                IMG_ID_VAPP_DESKTOP_TOOBAR_BG_PRESSED,
                0,
                0);

    for (VfxS32 i = 0; i < BUTTON_TOTAL; i++)
    {
        const ButtonEntry *entry = s_buttonTbl + i;

        VFX_OBJ_CREATE(m_button[entry->m_id], VcpButton, this);
        m_button[entry->m_id]->setRect(getButtonRect(i, getSize()));
        m_button[entry->m_id]->setMargin(0, TOP_MARGIN, 0, BOTTOM_MARGIN);
        m_button[entry->m_id]->setImage(VcpStateImage(entry->m_icon));
        m_button[entry->m_id]->setBgImageList(bgImgList);
        m_button[entry->m_id]->setText(VFX_WSTR_RES(entry->m_text));
        m_button[entry->m_id]->setTextFont(VFX_FONT_DESC_SMALL);
        m_button[entry->m_id]->setTextColor(VFX_COLOR_WHITE);
        m_button[entry->m_id]->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_TOP);
        m_button[entry->m_id]->setId(entry->m_id);
        m_button[entry->m_id]->m_signalClicked.connect(this, &VappDesktopToolbar::onButtonClicked);

        if (i < BUTTON_TOTAL - 1)
        {
            VfxImageFrame *lineFrame;

            VFX_OBJ_CREATE(lineFrame, VfxImageFrame, this);
            lineFrame->setRect(getSeparateLineRect(i, getSize()));
            lineFrame->setResId(IMG_ID_VAPP_DESKTOP_TOOBAR_SEPARATOR);
        }
    }
}


void VappDesktopToolbar::onDeinit()
{
    VappDesktopBar::onDeinit();
}


void VappDesktopToolbar::onFold()
{
    VappDesktopBar::onFold();

    VfxFPoint anchor = getAnchor();
    anchor.y = 0.0f;
    setAnchor(anchor);

    setHidden(VFX_TRUE);
}


void VappDesktopToolbar::onUnfold()
{
    setHidden(VFX_FALSE);

    VfxFPoint anchor = getAnchor();
    anchor.y = 1.0f;
    setAnchor(anchor);

    VappDesktopBar::onUnfold();
}


void VappDesktopToolbar::onButtonClicked(VfxObject *obj, VfxId id)
{
    VFX_UNUSED(id);

    VcpButton *button = VFX_OBJ_DYNAMIC_CAST(obj, VcpButton);

    if (button)
    {
        ButtonEnum buttonId = (ButtonEnum)button->getId();

        vfxPostInvoke1(this, &VappDesktopToolbar::onPostExecute, buttonId);
    }
}


VfxSize VappDesktopToolbar::getSeparateLineSize()
{
    VfxImageSrc lineImage;
    VfxSize lineSize;

    lineImage.setResId(IMG_ID_VAPP_DESKTOP_TOOBAR_SEPARATOR);
    lineSize = lineImage.getSize();

    return lineSize;
}


VfxRect VappDesktopToolbar::getSeparateLineRect(
    VfxS32 index,
    const VfxSize &parentSize)
{
    VfxRect buttonRect = getButtonRect(index, parentSize);
    VfxSize lineSize = getSeparateLineSize();

    VfxPoint pos = buttonRect.origin;
    pos.x += buttonRect.size.width;
    pos.x -= lineSize.width / 2;

    return VfxRect(pos, getSeparateLineSize());
}


VfxRect VappDesktopToolbar::getButtonRect(VfxS32 index, const VfxSize &parentSize)
{
    VFX_ASSERT(index >= 0 && index < BUTTON_TOTAL);

    if (BUTTON_TOTAL == 1)
    {
        return VfxRect(VFX_POINT_ZERO, parentSize);
    }

    //
    // Get separate line width.
    //
    VfxSize lineSize = getSeparateLineSize();

    //
    // Get remained width.
    //
    VfxSize buttonSize(parentSize.width / BUTTON_TOTAL, parentSize.height);
    VfxS32 remainedWidth = parentSize.width % BUTTON_TOTAL;

    //
    // Get position and size.
    //
    // If we have remained width, put the remained width on the last button.
    //
    VfxPoint pos;

    pos.y = 0;
    pos.x = buttonSize.width * index;

    if (index == BUTTON_TOTAL - 1)
    {
        buttonSize.width += remainedWidth;
    }

    return VfxRect(pos, buttonSize);
}


void VappDesktopToolbar::onPostExecute(ButtonEnum buttonId)
{
    m_signalExecute.emit(this, buttonId);
}

#endif /* defined(__MMI_VUI_LAUNCHER__) */
