/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_launcher_cosmos_bar.cpp
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vapp_launcher_cosmos_bar.h"
#include "mmi_rp_vapp_launcher_cosmos_def.h"


/*****************************************************************************
 * Bar Class
 *****************************************************************************/

VappLauncherCosmosBar::VappLauncherCosmosBar() :
    m_isFolded(VFX_FALSE),
    m_timerFolding(NULL)
{
    // Do nothing.
}


void VappLauncherCosmosBar::onInit()
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
    m_timerFolding->m_signalTick.connect(this, &VappLauncherCosmosBar::onTimerFolded);
}


void VappLauncherCosmosBar::onDeinit()
{
    VfxControl::onDeinit();
}


void VappLauncherCosmosBar::onFold()
{
    // Do nothing.
}


void VappLauncherCosmosBar::onUnfold()
{
    // Do nothing.
}


void VappLauncherCosmosBar::fold(VfxBool isAnimatable)
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


void VappLauncherCosmosBar::unfold(VfxBool isAnimatable)
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


VfxBool VappLauncherCosmosBar::isFolded()
{
    return m_isFolded;
}


void VappLauncherCosmosBar::prepareSignal(VfxBool isAnimatable)
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


void VappLauncherCosmosBar::onTimerFolded(VfxTimer *timer)
{
    VFX_ASSERT(timer && timer == m_timerFolding);

    m_signalFoldingChanged.emit(this);
}


/*****************************************************************************
 * Page Indicator Class
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherCosmosPageIndicator", VappLauncherCosmosPageIndicator, VappLauncherCosmosBar);

const VfxSize VappLauncherCosmosPageIndicator::s_haloMinSize(HALO_MIN_WIDTH, HALO_MIN_HEIGHT);
const VfxSize VappLauncherCosmosPageIndicator::s_haloMaxSize(HALO_MAX_WIDTH, HALO_MAX_HEIGHT);


const VappLauncherCosmosPageIndicator::VappLauncherCosmosPageIndicatorHResIdStruct
VappLauncherCosmosPageIndicator::s_indicatorHResIdTbl[] =
{
        IMG_ID_VAPP_LAUNCHER_COSMOS_PAGE_INDICATOR_HIGHLIGHTED_1,
        IMG_ID_VAPP_LAUNCHER_COSMOS_PAGE_INDICATOR_HIGHLIGHTED_2,
        IMG_ID_VAPP_LAUNCHER_COSMOS_PAGE_INDICATOR_HIGHLIGHTED_3,
        IMG_ID_VAPP_LAUNCHER_COSMOS_PAGE_INDICATOR_HIGHLIGHTED_4,
        IMG_ID_VAPP_LAUNCHER_COSMOS_PAGE_INDICATOR_HIGHLIGHTED_5
};


VappLauncherCosmosPageIndicator::VappLauncherCosmosPageIndicator() :
    m_index(0),
    m_easeOutDot(NULL),
    m_selectedDot(NULL)
{
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM; i++)
    {
        m_dot[i] = NULL;
        m_halo[i] = NULL;
    }
}


void VappLauncherCosmosPageIndicator::onInit()
{
    VappLauncherCosmosBar::onInit();

    VfxSize parentSize = getParentFrame()->getSize();
    //
    // This Frame
    //

    VfxSize size;

    size.width = (getDotSize().width + GAP) * VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM +
                 LEFT_GAP + RIGHT_GAP - GAP;

    size.height = HEIGHT;

    setSize(size);

    //
    // Dot Images
    //
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM; i++)
    {
        VFX_OBJ_CREATE(m_halo[i], VfxImageFrame, this);
        m_halo[i]->setResId(IMG_ID_VAPP_LAUNCHER_COSMOS_PAGE_INDICATOR_HALO);
        m_halo[i]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_halo[i]->setAutoAnimate(VFX_TRUE);
        m_halo[i]->setAnchor(VfxFPoint(0.5f, 0.5f));
        m_halo[i]->setPos(getDotPos(i));
        m_halo[i]->setHidden(VFX_TRUE);

        VFX_OBJ_CREATE(m_dot[i], VfxImageFrame, this);
        m_dot[i]->setResId(IMG_ID_VAPP_LAUNCHER_COSMOS_PAGE_INDICATOR_NORMAL);
        m_dot[i]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_dot[i]->setAutoAnimate(VFX_TRUE);
        m_dot[i]->setAnchor(VfxFPoint(0.5f, 0.5f));
        m_dot[i]->setPos(getDotPos(i));
    }

    VFX_OBJ_CREATE(m_easeOutDot, VfxImageFrame, this);
    m_easeOutDot->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_easeOutDot->setAutoAnimate(VFX_TRUE);
    m_easeOutDot->setAnchor(VfxFPoint(0.5f, 0.5f));
    m_easeOutDot->setOpacity(0.0f);

    VFX_OBJ_CREATE(m_selectedDot, VfxImageFrame, this);
    m_selectedDot->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_selectedDot->setAnchor(VfxFPoint(0.5f, 0.5f));
    m_selectedDot->setOpacity(1.0f);

    //
    // Initialize the highlighted index.
    //
    setIndex(0);

    setAutoAnimate(VFX_TRUE);
}


void VappLauncherCosmosPageIndicator::onDeinit()
{
    VappLauncherCosmosBar::onDeinit();
}


VfxBool VappLauncherCosmosPageIndicator::onPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            setHaloEffect(VFX_TRUE);
            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
            if (containPoint(event.getRelPos(this)))
            {
                setHaloEffect(VFX_TRUE);
            }
            else
            {
                setHaloEffect(VFX_FALSE);
            }
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            setHaloEffect(VFX_FALSE);

            if (containPoint(event.getRelPos(this)))
            {
                m_signalClicked.emit(this);
            }

            break;

        case VFX_PEN_EVENT_TYPE_ABORT:
            setHaloEffect(VFX_FALSE);
            break;

        default:
            break;
    }

    return VFX_TRUE;
}


void VappLauncherCosmosPageIndicator::onFold()
{
    setOpacity(0.0f);

    VappLauncherCosmosBar::onFold();
}


void VappLauncherCosmosPageIndicator::onUnfold()
{
    setOpacity(1.0f);

    VappLauncherCosmosBar::onUnfold();
}


void VappLauncherCosmosPageIndicator::setIndex(VfxS32 idx)
{
    if (idx < 0 || idx >= VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM)
    {
        return;
    }

    VfxS32 old_index = m_index;
    m_index = idx;

    VfxTransform trans;

    getTransform(
        IMG_ID_VAPP_LAUNCHER_COSMOS_PAGE_INDICATOR_NORMAL,
        s_indicatorHResIdTbl[m_index].resId,
        trans);

    //
    // Animate them.
    //
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);

    m_dot[old_index]->setResId(IMG_ID_VAPP_LAUNCHER_COSMOS_PAGE_INDICATOR_NORMAL);
    m_dot[m_index]->setResId(s_indicatorHResIdTbl[m_index].resId);

    VfxAutoAnimate::commit();
}


VfxS32 VappLauncherCosmosPageIndicator::getIndex(void) const
{
    return m_index;
}


VfxBool VappLauncherCosmosPageIndicator::isHitted(VfxPenEvent &event)
{
    if (getHidden())
    {
        return VFX_FALSE;
    }

    VfxRect bounds = getBounds();

    bounds.size.height = HITTABLE_HEIGHT;

    return bounds.contains(event.getRelPos(this));
}


void VappLauncherCosmosPageIndicator::setHaloEffect(VfxBool isOn)
{
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM; i++)
    {
        if (isOn)
        {
            m_halo[i]->setHidden(VFX_FALSE);
            m_halo[i]->setSize(s_haloMaxSize);
        }
        else
        {
            VfxImageSrc haloImg(IMG_ID_VAPP_LAUNCHER_COSMOS_PAGE_INDICATOR_HALO);
            VfxSize haloSize = haloImg.getSize();

            m_halo[i]->setHidden(VFX_TRUE);
            m_halo[i]->setSize(haloSize); // reset.
        }
    }

    VfxAutoAnimate::commit();
}


VfxSize VappLauncherCosmosPageIndicator::getDotSize() const
{
    VfxImageSrc dot(IMG_ID_VAPP_LAUNCHER_COSMOS_PAGE_INDICATOR_NORMAL);

    return dot.getSize();
}


VfxPoint VappLauncherCosmosPageIndicator::getDotPos(VfxS32 idx) const
{
    VFX_ASSERT(idx >= 0 && idx < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM);

    // Get the dot's size.
    VfxSize dotSize = getDotSize();

    // Calculate the dot's position.
    VfxPoint pos;
    pos.x = LEFT_GAP + (dotSize.width / 2) + (dotSize.width + GAP) * idx;
    pos.y = HEIGHT / 2;

    return pos;
}


void VappLauncherCosmosPageIndicator::getTransform(
    VfxSize from,
    VfxSize to,
    VfxTransform &trans) const
{
    trans.init(VFX_TRANSFORM_TYPE_AFFINE);
    trans.data.affine.sx = (VfxFloat)to.width / from.width;
    trans.data.affine.sy = (VfxFloat)to.height / from.height;
}


void VappLauncherCosmosPageIndicator::getTransform(
    VfxResId from,
    VfxResId to,
    VfxTransform &trans) const
{
    VfxSize fromSize = VfxImageSrc(from).getSize();
    VfxSize toSize = VfxImageSrc(to).getSize();

    getTransform(fromSize, toSize, trans);
}


/*****************************************************************************
 * Shortcut Bar Class
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherCosmosShortcutBar", VappLauncherCosmosShortcutBar, VappLauncherCosmosBar);


VappLauncherCosmosShortcutBar::VappLauncherCosmosShortcutBar() :
    m_shortcut(NULL)
{
    // Do nothing.
}


void VappLauncherCosmosShortcutBar::onInit()
{
    VappLauncherCosmosBar::onInit();

    VfxSize parentSize = getParentFrame()->getSize();

    //
    // This Frame
    //
    setAnchor(VfxFPoint(0.0f, 1.0f));
    setPos(0, parentSize.height);
    setBounds(VfxRect(0, 0, parentSize.width, HEIGHT));

    //
    // Shortcut Bar
    //
    VFX_OBJ_CREATE(m_shortcut, VappLauncherCosmosMmShortcutBar, this);
    m_shortcut->m_mainmenuLaunched.connect(this, &VappLauncherCosmosShortcutBar::onMainMenuLaunched);
}


void VappLauncherCosmosShortcutBar::onMainMenuLaunched()
{
    m_signalMMLaunched.emit();
}


void VappLauncherCosmosShortcutBar::onDeinit()
{
    VappLauncherCosmosBar::onDeinit();
}


void VappLauncherCosmosShortcutBar::onDraw(VfxDrawContext &dc)
{
    VappLauncherCosmosBar::onDraw(dc);
}


void VappLauncherCosmosShortcutBar::onFold()
{
    VappLauncherCosmosBar::onFold();

    VfxFPoint anchor = getAnchor();

    anchor.y = 0.0f;

    setAnchor(anchor);
    setOpacity(0.0f);
}


void VappLauncherCosmosShortcutBar::onUnfold()
{
    VfxFPoint anchor = getAnchor();

    anchor.y = 1.0f;

    setAnchor(anchor);
    setOpacity(1.0f);

    VappLauncherCosmosBar::onUnfold();
}


void VappLauncherCosmosShortcutBar::serialize()
{
}


void VappLauncherCosmosShortcutBar::restore()
{
    VFX_ASSERT(m_shortcut);
    m_shortcut->reloadShortcutBar();
}


VfxPoint VappLauncherCosmosShortcutBar::getSeparatorPos(
    const VfxSize &size,
    VfxS32 idx) const
{
    VFX_ASSERT(idx >= 0 && idx < SHORTCUT_NUM);

    VfxPoint pos;

    pos.x = size.width * idx / SHORTCUT_NUM;
    pos.y = size.height >> 1;

    return pos;
}


/*****************************************************************************
 * Toolbar Class
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherCosmosToolbar", VappLauncherCosmosToolbar, VappLauncherCosmosBar);


const VappLauncherCosmosToolbar::ButtonEntry VappLauncherCosmosToolbar::s_buttonTbl[] =
{
    VappLauncherCosmosToolbar::ButtonEntry(
        VappLauncherCosmosToolbar::BUTTON_ADD_WIDGET,
        STR_ID_VAPP_LAUNCHER_COSMOS_ADD_WIDGET,
        IMG_ID_VAPP_LAUNCHER_COSMOS_TOOBAR_ADD_WIDGET)
    ,
    VappLauncherCosmosToolbar::ButtonEntry(
        VappLauncherCosmosToolbar::BUTTON_ADD_SHORTCUT,
        STR_ID_VAPP_LAUNCHER_COSMOS_ADD_SHORTCUT,
        IMG_ID_VAPP_LAUNCHER_COSMOS_TOOBAR_ADD_APP)
    ,
    VappLauncherCosmosToolbar::ButtonEntry(
        VappLauncherCosmosToolbar::BUTTON_SET_WALLPAPER,
        STR_ID_VAPP_LAUNCHER_COSMOS_SET_WALLPAPER,
        IMG_ID_VAPP_LAUNCHER_COSMOS_TOOBAR_WALLPAPER)
};


VappLauncherCosmosToolbar::VappLauncherCosmosToolbar()
{
    for (VfxS32 i = 0; i < BUTTON_TOTAL; i++)
    {
        m_button[i] = NULL;
    }
}


void VappLauncherCosmosToolbar::onInit()
{
    VappLauncherCosmosBar::onInit();

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
                IMG_ID_VAPP_LAUNCHER_COSMOS_TOOBAR_BG_NORMAL,
                IMG_ID_VAPP_LAUNCHER_COSMOS_TOOBAR_BG_PRESSED,
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
        m_button[entry->m_id]->setText((entry->m_text));
        m_button[entry->m_id]->setTextFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(FONT_SIZE)));
        m_button[entry->m_id]->setTextColor(VFX_COLOR_WHITE);
        m_button[entry->m_id]->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_TOP);
        m_button[entry->m_id]->setId(entry->m_id);
        m_button[entry->m_id]->m_signalClicked.connect(this, &VappLauncherCosmosToolbar::onButtonClicked);

        if (i < BUTTON_TOTAL - 1)
        {
            VfxImageFrame *lineFrame;

            VFX_OBJ_CREATE(lineFrame, VfxImageFrame, this);
            lineFrame->setRect(getSeparateLineRect(i, getSize()));
            lineFrame->setResId(IMG_ID_VAPP_LAUNCHER_COSMOS_TOOBAR_SEPARATOR);
        }
    }
}


void VappLauncherCosmosToolbar::onDeinit()
{
    VappLauncherCosmosBar::onDeinit();
}


void VappLauncherCosmosToolbar::onFold()
{
    VappLauncherCosmosBar::onFold();

    VfxFPoint anchor = getAnchor();

    anchor.y = 0.0f;

    setAnchor(anchor);
    setOpacity(0.0f);
}


void VappLauncherCosmosToolbar::onUnfold()
{
    VfxFPoint anchor = getAnchor();

    anchor.y = 1.0f;

    setAnchor(anchor);
    setOpacity(1.0f);

    VappLauncherCosmosBar::onUnfold();
}


void VappLauncherCosmosToolbar::onButtonClicked(VfxObject *obj, VfxId id)
{
    VFX_UNUSED(id);

    VcpButton *button = VFX_OBJ_DYNAMIC_CAST(obj, VcpButton);

    if (button)
    {
        ButtonEnum buttonId = (ButtonEnum)button->getId();

        m_signalExecute.emit(this, buttonId);
    }
}


VfxSize VappLauncherCosmosToolbar::getSeparateLineSize()
{
    VfxImageSrc lineImage;
    VfxSize lineSize;

    lineImage.setResId(IMG_ID_VAPP_LAUNCHER_COSMOS_TOOBAR_SEPARATOR);
    lineSize = lineImage.getSize();

    return lineSize;
}


VfxRect VappLauncherCosmosToolbar::getSeparateLineRect(
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


VfxRect VappLauncherCosmosToolbar::getButtonRect(VfxS32 index, const VfxSize &parentSize)
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

