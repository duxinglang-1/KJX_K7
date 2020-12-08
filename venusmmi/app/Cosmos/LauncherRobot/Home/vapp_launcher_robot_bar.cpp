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
 *  vapp_launcher_robot_bar.cpp
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
#include "vapp_launcher_robot_bar.h"
#include "mmi_rp_vapp_launcher_robot_def.h"


/*****************************************************************************
 * Bar Class
 *****************************************************************************/

VappLauncherRobotBar::VappLauncherRobotBar() :
    m_isFolded(VFX_FALSE),
    m_timerFolding(NULL)
{
    // Do nothing.
}


void VappLauncherRobotBar::onInit()
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
    m_timerFolding->m_signalTick.connect(this, &VappLauncherRobotBar::onTimerFolded);
}


void VappLauncherRobotBar::onDeinit()
{
    VfxControl::onDeinit();
}


void VappLauncherRobotBar::onFold()
{
    // Do nothing.
}


void VappLauncherRobotBar::onUnfold()
{
    // Do nothing.
}


void VappLauncherRobotBar::fold(VfxBool isAnimatable)
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


void VappLauncherRobotBar::unfold(VfxBool isAnimatable)
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


VfxBool VappLauncherRobotBar::isFolded()
{
    return m_isFolded;
}


void VappLauncherRobotBar::prepareSignal(VfxBool isAnimatable)
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


void VappLauncherRobotBar::onTimerFolded(VfxTimer *timer)
{
    VFX_ASSERT(timer && timer == m_timerFolding);

    m_signalFoldingChanged.emit(this);
}


/*****************************************************************************
 * Toolbar Class
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherRobotToolbar", VappLauncherRobotToolbar, VappLauncherRobotBar);


const VappLauncherRobotToolbar::ButtonEntry VappLauncherRobotToolbar::s_buttonTbl[] =
{
    VappLauncherRobotToolbar::ButtonEntry(
        VappLauncherRobotToolbar::BUTTON_ADD_WIDGET,
        STR_ID_VAPP_LAUNCHER_ROBOT_ADD_WIDGET,
        IMG_ID_VAPP_LAUNCHER_ROBOT_TOOBAR_ADD_WIDGET)
    ,
    VappLauncherRobotToolbar::ButtonEntry(
        VappLauncherRobotToolbar::BUTTON_ADD_SHORTCUT,
        STR_ID_VAPP_LAUNCHER_ROBOT_ADD_SHORTCUT,
        IMG_ID_VAPP_LAUNCHER_ROBOT_TOOBAR_ADD_APP)
    ,
    VappLauncherRobotToolbar::ButtonEntry(
        VappLauncherRobotToolbar::BUTTON_SET_WALLPAPER,
        STR_ID_VAPP_LAUNCHER_ROBOT_SET_WALLPAPER,
        IMG_ID_VAPP_LAUNCHER_ROBOT_TOOBAR_WALLPAPER)
};


VappLauncherRobotToolbar::VappLauncherRobotToolbar():
    m_shortcutBg(NULL)
{
    for (VfxS32 i = 0; i < BUTTON_TOTAL; i++)
    {
        m_button[i] = NULL;
    }
}


void VappLauncherRobotToolbar::onInit()
{
    VappLauncherRobotBar::onInit();

    VfxSize parentSize = getParentFrame()->getSize();

    //
    // Background Image. Image is a 9-slices image. Set its size specifically.
    //
    VFX_OBJ_CREATE(m_shortcutBg, VfxImageFrame, this);
    m_shortcutBg->setResId(IMG_ID_VAPP_LAUNCHER_ROBOT_SHORTCUT_BG);
    m_shortcutBg->setSize(SHORCUT_BG_WIDTH, m_shortcutBg->getSize().height);
    m_shortcutBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_shortcutBg->setAutoAnimate(VFX_TRUE);

    //
    // This Frame
    //
    setAnchor(VfxFPoint(0.5f, 1.0f));
    setPos(getParentFrame()->getSize().width/2, parentSize.height);
    setSize(m_shortcutBg->getSize().width, m_shortcutBg->getSize().height);

    //
    // Button
    //
    for (VfxS32 i = 0; i < BUTTON_TOTAL; i++)
    {
        const ButtonEntry *entry = s_buttonTbl + i;
        VFX_OBJ_CREATE(m_button[entry->m_id], VcpImageButton, this);
        m_button[entry->m_id]->setAnchor(0.5,0.5);
        m_button[entry->m_id]->setImage(VcpStateImage(entry->m_icon));
        m_button[entry->m_id]->setSize(getImageResSize(entry->m_icon));
        m_button[entry->m_id]->setId(entry->m_id);
        m_button[entry->m_id]->m_signalClicked.connect(this, &VappLauncherRobotToolbar::onButtonClicked);
        m_button[entry->m_id]->setPos(getButtonPos(i));
        m_button[entry->m_id]->setIsEffect(VFX_TRUE);
        m_button[entry->m_id]->setEffectSize(VfxSize(HALO_WIDTH, HALO_HEIGHT));
    }
}


void VappLauncherRobotToolbar::onDeinit()
{
    VappLauncherRobotBar::onDeinit();
}


void VappLauncherRobotToolbar::onFold()
{
    VappLauncherRobotBar::onFold();

    VfxFPoint anchor = getAnchor();

    anchor.y = 0.0f;

    setAnchor(anchor);
    setOpacity(0.0f);
}


void VappLauncherRobotToolbar::onUnfold()
{
    VfxFPoint anchor = getAnchor();

    anchor.y = 1.0f;

    setAnchor(anchor);
    setOpacity(1.0f);

    VappLauncherRobotBar::onUnfold();
}


void VappLauncherRobotToolbar::onButtonClicked(VfxObject *obj, VfxId id)
{
    VFX_UNUSED(id);

    VcpImageButton *button = VFX_OBJ_DYNAMIC_CAST(obj, VcpImageButton);

    if (button)
    {
        ButtonEnum buttonId = (ButtonEnum)button->getId();

        m_signalExecute.emit(this, buttonId);
    }
}


VfxSize VappLauncherRobotToolbar::getSeparateLineSize()
{
    VfxImageSrc lineImage;
    VfxSize lineSize;

    lineImage.setResId(IMG_ID_VAPP_LAUNCHER_ROBOT_TOOBAR_SEPARATOR);
    lineSize = lineImage.getSize();

    return lineSize;
}


VfxRect VappLauncherRobotToolbar::getSeparateLineRect(
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


VfxSize VappLauncherRobotToolbar::getImageResSize(const VfxResId imageId) const
{
    VfxImageSrc image(imageId);

    return image.getSize();
}


VfxPoint VappLauncherRobotToolbar::getButtonPos(VfxS32 index)
{
    VFX_ASSERT(index >= 0 && index < BUTTON_TOTAL);

    VfxFPoint bgAnchor = m_shortcutBg->getAnchor();
    VfxS32 startX = m_shortcutBg->getPos().x - bgAnchor.x * m_shortcutBg->getSize().width;

    if (BUTTON_TOTAL == 1)
    {
        return VfxPoint(m_shortcutBg->getSize().width/2, m_shortcutBg->getSize().height/2);
    }
    
    //
    // Get remained width.
    //
    VfxSize buttonSize(m_shortcutBg->getSize().width / BUTTON_TOTAL, m_shortcutBg->getSize().height);

    //
    // Get position and size.
    //
    // If we have remained width, put the remained width on the last button.
    //
    VfxPoint pos;

    pos.y = (m_shortcutBg->getSize().height+7)/2;
    pos.x = buttonSize.width * index + buttonSize.width/2;

    return pos;
}


VfxRect VappLauncherRobotToolbar::getButtonRect(VfxS32 index, const VfxSize &parentSize)
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


/*****************************************************************************
 * Android Shortcut Bar Class
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherRobotShortcutBar", VappLauncherRobotShortcutBar, VappLauncherRobotBar);

const VappLauncherRobotShortcutBar::ButtonEntry VappLauncherRobotShortcutBar::s_buttonTbl[] =
{
    VappLauncherRobotShortcutBar::ButtonEntry(
        VappLauncherRobotShortcutBar::BUTTON_DIALER,
        IMG_ID_VAPP_LAUNCHER_ROBOT_CALL_N,
        IMG_ID_VAPP_LAUNCHER_ROBOT_CALL_H)
    ,
    VappLauncherRobotShortcutBar::ButtonEntry(
        VappLauncherRobotShortcutBar::BUTTON_MAINMENU,
        IMG_ID_VAPP_LAUNCHER_ROBOT_MAINMENU_N,
        IMG_ID_VAPP_LAUNCHER_ROBOT_MAINMENU_H)
    , 
#ifdef __MMI_GB_WINGUO__
    VappLauncherRobotShortcutBar::ButtonEntry(
        VappLauncherRobotShortcutBar::BUTTON_WINGUO,
        IMG_ID_VAPP_LAUNCHER_ROBOT_WINGUO_N,
        IMG_ID_VAPP_LAUNCHER_ROBOT_WINGUO_H)   
#else
    VappLauncherRobotShortcutBar::ButtonEntry(
        VappLauncherRobotShortcutBar::BUTTON_BROWSER,
        IMG_ID_VAPP_LAUNCHER_ROBOT_BROWSER_N,
        IMG_ID_VAPP_LAUNCHER_ROBOT_BROWSER_H)     
#endif
};

VappLauncherRobotShortcutBar::VappLauncherRobotShortcutBar() :
    m_shortcutBg(NULL),
    m_index(0),
    indicatorHitted(VFX_FALSE)
{
    for (VfxS32 i = 0; i < BUTTON_TOTAL; i++)
    {
        m_button[i] = NULL;
    }

    for (VfxS32 i = 0; i < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
    {
        m_dot[i] = NULL;
        m_halo[i] = NULL;
    }
}


void VappLauncherRobotShortcutBar::onInit()
{
    VappLauncherRobotBar::onInit();

    VfxSize parentSize = getParentFrame()->getSize();

    //
    // Background Image. Image is a 9-slices image. Set its size specifically.
    //
    VFX_OBJ_CREATE(m_shortcutBg, VfxImageFrame, this);
    m_shortcutBg->setResId(IMG_ID_VAPP_LAUNCHER_ROBOT_SHORTCUT_BG);
    m_shortcutBg->setAnchor(0.5,0);
    m_shortcutBg->setSize(SHORCUT_BG_WIDTH, m_shortcutBg->getSize().height);
    m_shortcutBg->setPos(getParentFrame()->getSize().width/2, 0);
    m_shortcutBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_shortcutBg->setAutoAnimate(VFX_TRUE);

    //
    // This Frame
    //
    setAnchor(VfxFPoint(0.0f, 1.0f));
    setPos(0, parentSize.height);
    setSize(getParentFrame()->getSize().width, m_shortcutBg->getSize().height);
    setCacheMode(VFX_CACHE_MODE_PREVENT);
    
    //
    // Button
    //

    for (VfxS32 i = 0; i < BUTTON_TOTAL; i++)
    {
        const ButtonEntry *entry = s_buttonTbl + i;

        VFX_OBJ_CREATE(m_button[entry->m_id], VcpImageButton, m_shortcutBg);
        m_button[entry->m_id]->setAnchor(0.5,0.5);
        m_button[entry->m_id]->setImage(VcpStateImage(entry->m_icon));
        m_button[entry->m_id]->setSize(getImageResSize(entry->m_icon));
        m_button[entry->m_id]->setId(entry->m_id);
        m_button[entry->m_id]->m_signalClicked.connect(this, &VappLauncherRobotShortcutBar::onButtonTapped);
        m_button[entry->m_id]->setPos(getButtonPos(i));
        m_button[entry->m_id]->setIsEffect(VFX_TRUE);
        m_button[entry->m_id]->setEffectSize(VfxSize(HALO_WIDTH, HALO_HEIGHT));
    }

    //
    //  Indicator
    //
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
    {
        VFX_OBJ_CREATE(m_dot[i], VfxImageFrame, this);
        m_dot[i]->setResId(IMG_ID_VAPP_LAUNCHER_ROBOT_INDICATOR_P);
        m_dot[i]->setAutoAnimate(VFX_TRUE);
        m_dot[i]->setAnchor(VfxFPoint(0.5f, 0.5f));
        m_dot[i]->setOpacity(1);
        
        VFX_OBJ_CREATE(m_halo[i], VfxImageFrame, this);
        m_halo[i]->setResId(IMG_ID_VAPP_LAUNCHER_ROBOT_INDICATOR_H);
        m_halo[i]->setAutoAnimate(VFX_TRUE);
        m_halo[i]->setAnchor(VfxFPoint(0.5f, 0.5f));
        m_halo[i]->setOpacity(0);
    }

    layoutIndicator();
}


void VappLauncherRobotShortcutBar::layoutIndicator() const
{
    //
    // Animate them.
    //
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    VfxS32 curIndex = 0;
    
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
    {
        if(i == m_index)
        {
            m_halo[i]->setOpacity(0);
            m_dot[i]->setOpacity(0);
            continue;
        }
        m_dot[i]->setOpacity(1);
        m_halo[i]->setPos(getDotPos(i, curIndex));
        m_dot[i]->setPos(getDotPos(i, curIndex));
        curIndex++;
    }    

    VfxAutoAnimate::commit();
}


VfxPoint VappLauncherRobotShortcutBar::getDotPos(VfxS32 indicatorIndex, VfxS32 sequenceIndex) const
{
    VfxS32 startX = 0;
    VfxPoint pos;
    
    if(indicatorIndex < m_index)
    {
        // left side
        startX = 0;
        pos.x = startX + getMidPosBySequenceIndex(
                            sequenceIndex, 
                            VfxSize(m_shortcutBg->getPos().x - m_shortcutBg->getSize().width/2 + 1, getSize().height),
                            VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM-1).x;
    }
    else
    {
        // right side
        startX = m_shortcutBg->getPos().x + m_shortcutBg->getSize().width/2;
        pos.x = startX + getMidPosBySequenceIndex(
                            sequenceIndex, 
                            VfxSize(getSize().width - (m_shortcutBg->getPos().x + m_shortcutBg->getSize().width/2) + 1, getSize().height), 
                            VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM-1).x;
    }

    pos.y = getSize().height/2;
    return pos;
    
}


VfxPoint VappLauncherRobotShortcutBar::getMidPosBySequenceIndex(VfxS32 index, VfxSize totalSize, VfxS32 totalNum) const
{
    VfxS32 marginWidth = 0.15 * totalSize.width;
        
    totalSize.width -= 2 * marginWidth;

    VfxPoint pos;
    pos.y = totalSize.height/2;

    VfxS32 cellWidth = totalSize.width/totalNum;
    pos.x = cellWidth/2 + index * cellWidth;

    pos.x += marginWidth;
    
    return pos;
}


VfxSize VappLauncherRobotShortcutBar::getImageResSize(const VfxResId imageId) const
{
    VfxImageSrc image(imageId);

    return image.getSize();
}


void VappLauncherRobotShortcutBar::onButtonTapped(VfxObject *button, VfxId id)
{
    m_signalExecute.emit((VappLauncherRobotShortcutBar::ButtonEnum)id);
}


void VappLauncherRobotShortcutBar::onDeinit()
{
    VappLauncherRobotBar::onDeinit();
}


void VappLauncherRobotShortcutBar::onDraw(VfxDrawContext &dc)
{
    VappLauncherRobotBar::onDraw(dc);
}


void VappLauncherRobotShortcutBar::onFold()
{
    VappLauncherRobotBar::onFold();

    m_shortcutBg->setPos(m_shortcutBg->getPos().x,getSize().height);
    m_shortcutBg->setOpacity(0.0f);
}


void VappLauncherRobotShortcutBar::onUnfold()
{
    m_shortcutBg->setPos(m_shortcutBg->getPos().x,0);
    m_shortcutBg->setOpacity(1.0f);

    VappLauncherRobotBar::onUnfold();
}


void VappLauncherRobotShortcutBar::hideIndicator(VfxBool isHide)
{
    //
    // Animate them.
    //
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDuration(100);

    for (VfxS32 i = 0; i < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
    {
        m_halo[i]->setHidden(isHide);
        m_dot[i]->setHidden(isHide);
    }

    VfxAutoAnimate::commit();
}


VfxPoint VappLauncherRobotShortcutBar::getButtonPos(VfxS32 index)
{
    VFX_ASSERT(index >= 0 && index < BUTTON_TOTAL);

    if (BUTTON_TOTAL == 1)
    {
        return VfxPoint(m_shortcutBg->getSize().width/2, m_shortcutBg->getSize().height/2);
    }
    
    //
    // Get remained width.
    //
    VfxSize buttonSize(m_shortcutBg->getSize().width / BUTTON_TOTAL, m_shortcutBg->getSize().height);

    //
    // Get position and size.
    //
    // If we have remained width, put the remained width on the last button.
    //
    VfxPoint pos;

    pos.y = (m_shortcutBg->getSize().height+7)/2;
    pos.x = buttonSize.width * index + buttonSize.width/2;

    return pos;
}


VfxBool VappLauncherRobotShortcutBar::onPenInput(VfxPenEvent &event)
{
	VfxS32 direction = 0;
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            if(isIndicatorHitted(event,direction))
            {
                indicatorHitted = VFX_TRUE;
                setIndicatorHighlight(VFX_TRUE, direction);
            }
            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
            if (isIndicatorHitted(event,direction) && 
                indicatorHitted == VFX_TRUE)
            {
                setIndicatorHighlight(VFX_TRUE, direction);
            }
            else
            {
                setIndicatorHighlight(VFX_FALSE, direction);
            }
            break;

        case VFX_PEN_EVENT_TYPE_LONG_TAP:
            if (isIndicatorHitted(event,direction) && 
                indicatorHitted == VFX_TRUE)
            {
                indicatorHitted = VFX_FALSE;
                m_signalIndicatorLongPressed.emit();
            }
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            setIndicatorHighlight(VFX_FALSE, direction);
            if (isIndicatorHitted(event,direction) && 
                indicatorHitted == VFX_TRUE)
            {
                indicatorHitted = VFX_FALSE;
                m_signalIndicatorClicked.emit(direction);
            }

            break;

        case VFX_PEN_EVENT_TYPE_ABORT:
            setIndicatorHighlight(VFX_FALSE, direction);
            break;

        default:
            break;
    }
	
    return VFX_TRUE;
}


void VappLauncherRobotShortcutBar::setIndex(VfxS32 idx)
{
    if (idx < 0 || idx >= VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM)
    {
        return;
    }

    m_index = idx;
    layoutIndicator();
}


VfxS32 VappLauncherRobotShortcutBar::getIndex(void) const
{
    return m_index;
}


VfxBool VappLauncherRobotShortcutBar::isIndicatorHitted(VfxPenEvent &event, VfxS32 &direction)
{
    if (getHidden())
    {
        return VFX_FALSE;
    }

    if( getBounds().contains(event.getRelPos(this)) )
    {
        VfxPoint pos = event.getRelPos(this);
        if(pos.x < m_shortcutBg->getPos().x - m_shortcutBg->getSize().width/2 )
        {
            // left side of indicator
            direction = -1;
            return VFX_TRUE;
        }
        else if(pos.x > m_shortcutBg->getPos().x + m_shortcutBg->getSize().width/2 )
        {
            // right side
            direction = 1;
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}


void VappLauncherRobotShortcutBar::setIndicatorHighlight(VfxBool on, VfxS32 direction)
{
    //
    // Animate them.
    //
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDuration(100);

    for (VfxS32 i = 0; i < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
    {
        if(on)
        {
            if( (i < m_index && direction < 0) || 
                (i > m_index && direction > 0))
            {
                m_halo[i]->setOpacity(1);
            }
            else
            {
                m_halo[i]->setOpacity(0);
            } 
        }
        else
        {
            m_halo[i]->setOpacity(0);
        }
    }

    VfxAutoAnimate::commit();
}


/*****************************************************************************
 * Trash Can Bar 
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherRobotTrashCanBar", VappLauncherRobotTrashCanBar, VappLauncherRobotBar);


VappLauncherRobotTrashCanBar::VappLauncherRobotTrashCanBar():
    m_trashCanBgN(NULL),
    m_trashCanBgH(NULL),
    m_trashIconN(NULL),
    m_trashIconH(NULL)
{
}


void VappLauncherRobotTrashCanBar::onInit()
{
    VappLauncherRobotBar::onInit();

    VfxSize parentSize = getParentFrame()->getSize();

    //
    // Background Image. Image is a 9-slices image. Set its size specifically.
    //
    VFX_OBJ_CREATE(m_trashCanBgN, VfxImageFrame, this);
    m_trashCanBgN->setResId(IMG_ID_VAPP_LAUNCHER_ROBOT_SHORTCUT_BG);
    m_trashCanBgN->setSize(BG_WIDTH, m_trashCanBgN->getSize().height);
    m_trashCanBgN->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_trashCanBgN->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_trashCanBgH, VfxImageFrame, this);
    m_trashCanBgH->setResId(IMG_ID_VAPP_LAUNCHER_ROBOT_TRASH_CAN_BAR_BG_H);
    m_trashCanBgH->setSize(BG_WIDTH, m_trashCanBgH->getSize().height);
    m_trashCanBgH->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_trashCanBgH->setOpacity(0.0);
    m_trashCanBgH->setAutoAnimate(VFX_TRUE);

    //
    // This Frame
    //
    setAnchor(VfxFPoint(0.5f, 1.0f));
    setPos(parentSize.width/2, parentSize.height);
    setSize(m_trashCanBgN->getSize());
    setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_trashIconN, VfxImageFrame, this);
    m_trashIconN->setResId(IMG_ID_VAPP_LAUNCHER_ROBOT_TRASH_CAN_ICON_N);
    m_trashIconN->setAnchor(0.5, 0.5);
    m_trashIconN->setPos(getSize().width/2, getSize().height/2);
    m_trashIconN->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_trashIconH, VfxImageFrame, this);
    m_trashIconH->setResId(IMG_ID_VAPP_LAUNCHER_ROBOT_TRASH_CAN_ICON_H);
    m_trashIconH->setAnchor(0.5, 0.5);
    m_trashIconH->setPos(getSize().width/2, getSize().height/2);
    m_trashIconH->setOpacity(0.0);
    m_trashIconN->setAutoAnimate(VFX_TRUE);
}


void VappLauncherRobotTrashCanBar::onDeinit()
{
    VappLauncherRobotBar::onDeinit();
}


void VappLauncherRobotTrashCanBar::onFold()
{
    VappLauncherRobotBar::onFold();

    VfxFPoint anchor = getAnchor();

    anchor.y = 0.0f;

    setAnchor(anchor);
    setOpacity(0.0f);
}


void VappLauncherRobotTrashCanBar::onUnfold()
{
    VfxFPoint anchor = getAnchor();

    anchor.y = 1.0f;

    setAnchor(anchor);
    setOpacity(1.0f);

    VappLauncherRobotBar::onUnfold();
}


void VappLauncherRobotTrashCanBar::setAlertDeleteWidget(VfxBool isAlert)
{
    if(isAlert)
    {
        m_trashCanBgN->setOpacity(0.0);
        m_trashIconN->setOpacity(0.0);
        m_trashCanBgH->setOpacity(1.0);
        m_trashIconH->setOpacity(1.0);
    }
    else
    {
        m_trashCanBgN->setOpacity(1.0);
        m_trashIconN->setOpacity(1.0);
        m_trashCanBgH->setOpacity(0.0);
        m_trashIconH->setOpacity(0.0);
    }
}

