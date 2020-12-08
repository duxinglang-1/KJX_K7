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
 *  vapp_hs_shortcut_panel.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file implements the shortcut panel.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vapp_hs_shortcut_mgr.h"
#include "vapp_hs_shortcut_panel.h"
#include "vadp_app_trc.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_system.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_primitive_frame.h"
#include "vapp_hs_cp.h"
#include "vfx_basic_type.h"
#include "vfx_signal.h"
#include "vfx_timer.h"
#include "vrt_datatype.h"
#include "vrt_system.h"
#include "vfx_frame.h"
#include "vfx_input_event.h"
#include "vfx_auto_animate.h"
#include "vfx_control.h"
#include "vfx_renderer.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "lcd_sw_inc.h"
#include "mmi_rp_app_venus_homescreen_def.h"

#ifdef __cplusplus
}
#endif


// transparent while dragging widget or shortcut
const VfxFloat VappHsShortcutPanel::s_moveOpacity = 0.65f;

// If shortcut pool is open, it is VFX_TRUE; otherwise, it is VFX_FALSE.
VfxBool VappHsShortcutPanel::s_isPoolOpened = VFX_FALSE;

// If the shortcut panel is hidden, it is VFX_TRUE; otherwise, it is VFX_FALSE.
VfxBool VappHsShortcutPanel::s_isHidden = VFX_FALSE;


/***************************************************************************** 
 * Venus home screen shortcut (base class)
 *****************************************************************************/

VappHsShortcutPanel::VappHsShortcutPanel() :
    m_bgImg(NULL),
    m_blackScreen(NULL),
    m_shortcutBar(NULL),
    m_shortcutPool(NULL),
    m_shortcutMgr(NULL),
    m_movingFrameS(NULL),
    m_movingFrameOriParent(NULL),
    m_timerAddShortcut(NULL)
{
}


void VappHsShortcutPanel::initShortcut()
{
    VappHsShortcut *ptr;
    
    // 
    // Set background image. For FTE's slim project, use 9-slice image.
    //
    VFX_OBJ_CREATE(m_bgImg, VfxImageFrame, this);
    m_bgImg->setResId(VAPP_HS_IMG_SC_BAR_BG);
    m_bgImg->setPos(VfxPoint(VappHsShortcutBar::X_POS, VappHsShortcutBar::Y_POS));
    m_bgImg->setIsCached(VFX_TRUE);

#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    m_bgImg->setIsOpaque(VFX_TRUE);
#endif

#if defined(__MMI_FTE_SUPPORT_SLIM__)
    VfxSize bgImgOriginalSize = m_bgImg->getSize();

    m_bgImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_bgImg->setSize(LCD_WIDTH, bgImgOriginalSize.height);
#endif /* defined(__MMI_FTE_SUPPORT_SLIM__) */

    // Create the shortcut bar.
    VFX_OBJ_CREATE(m_shortcutBar, VappHsShortcutBar, this);

    // Create the shortcut pool.
    VFX_OBJ_CREATE(m_shortcutPool, VappHsShortcutPool, this);

    // Create all shortcuts.
    VFX_OBJ_CREATE(m_shortcutMgr, VappHsShortcutMgr, this);
    m_shortcutMgr->load();
    m_shortcutMgr->bind(m_shortcutBar, m_shortcutPool);
    
    for (ptr = m_shortcutMgr->getFirst(); ptr; ptr = m_shortcutMgr->getNext())
    {
        ptr->m_signalDrag.connect(this, &VappHsShortcutPanel::onControlShortcutDrag);
        ptr->m_signalMove.connect(this, &VappHsShortcutPanel::onControlShortcutMove);
        ptr->m_signalDrop.connect(this, &VappHsShortcutPanel::onControlShortcutDrop);
    }

    // Set shortcut history.
    setHistoryShortcut();

    // Timer to add widget to the widget bar.
    VFX_OBJ_CREATE(m_timerAddShortcut, VfxTimer, this);
    m_timerAddShortcut->setStartDelay(DEFAULT_AUTO_ANIMATE_TIME);
    m_timerAddShortcut->m_signalTick.connect(this, &VappHsShortcutPanel::onTimerAddShortcut);
}


VfxSize VappHsShortcutPanel::getScreenSize()
{
    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

    return VfxSize(main_screen_size.width, main_screen_size.height);
}


void VappHsShortcutPanel::onInit()
{
    VfxFrame::onInit();

    // Init this
    setPos(VFX_POINT_ZERO);
    setBounds(VfxRect(VFX_POINT_ZERO, getScreenSize()));
    
    // init black screen
    VFX_OBJ_CREATE(m_blackScreen, VappHsBlackScreen, this);
    m_blackScreen->setHidden(VFX_TRUE);
    m_blackScreen->m_signalDown.connect(this, &VappHsShortcutPanel::onBlackScreenDown);

    // init shortcut
    initShortcut();

    if (s_isHidden)
    {
        hide(s_isHidden, VFX_TRUE);
    }
}


void VappHsShortcutPanel::onDeinit()
{
    // In case that the shortcut is on the dropping animation when the shortcut
    // panel is deleted, immediately emit the signal such that the shortcut is
    // put into the shortcut panel and the setting can be updated.
    if (m_timerAddShortcut->getIsEnabled())
    {
        onTimerAddShortcut(m_timerAddShortcut);
    }

    VfxFrame::onDeinit();
}


VfxBool VappHsShortcutPanel::onContainPoint(const VfxPoint &point) const
{
    if (m_shortcutBar->containPoint(convertPointTo(point, m_shortcutBar)) ||
        m_shortcutPool->containPoint(convertPointTo(point, m_shortcutPool)))
    {
        return VFX_TRUE;
    }

    if ((!m_blackScreen->getHidden()) &&
        (m_blackScreen->containPoint(convertPointTo(point, m_blackScreen))))
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


void VappHsShortcutPanel::onTimerAddShortcut(VfxTimer *timer)
{
    VFX_UNUSED(timer);

    if (m_movingFrameS) 
    {
        m_movingFrameS->removeFromParentFrame();
        
        m_movingFrameOriParent->restoreImage(
            m_movingFrameS, 
            VFX_FALSE,      // do not blink the image icon
            VFX_FALSE);     // do not re-arrange the widget bar
            
        m_movingFrameS = NULL;
    }

    m_shortcutMgr->serializeToNvram();
}


void VappHsShortcutPanel::previewDrop(
    VappHsInteractiveImageArray *dst, 
    VfxPenEvent &event,
    VfxPoint &currentPos, 
    VfxPoint &finalPos)
{
    currentPos = m_movingFrameS->getPos();
    
    dst->insertImage(m_movingFrameS, event);

    VfxRect bounds = m_movingFrameS->getBounds();
    VfxPoint midPoint = VfxPoint(bounds.getMidX(), bounds.getMidY());
    
    finalPos = m_movingFrameS->convertPointTo(midPoint, this);
    
    // Re-add the icon view to the APP category.
    dst->backupImage(m_movingFrameS);
    dst->removeImage(m_movingFrameS, VFX_FALSE);

    m_movingFrameOriParent = dst;
    
    addChildFrame(m_movingFrameS);
}


void VappHsShortcutPanel::previewDropExt(VfxPoint &currentPos, VfxPoint &finalPos)
{
    currentPos = m_movingFrameS->getPos();

    m_movingFrameOriParent->restoreImage(m_movingFrameS, VFX_FALSE);
    
    VfxRect bounds = m_movingFrameS->getBounds();
    VfxPoint midPoint = VfxPoint(bounds.getMidX(), bounds.getMidY());
    
    finalPos = m_movingFrameS->convertPointTo(midPoint, this);
    
    // Re-add the icon view to the APP category.
    m_movingFrameOriParent->backupImage(m_movingFrameS);
    m_movingFrameOriParent->removeImage(m_movingFrameS, VFX_FALSE);
    
    addChildFrame(m_movingFrameS);
}


void VappHsShortcutPanel::resetAnchor(VfxFrame *frame, VfxPoint &offset)
{
    VfxPoint pos = frame->getPos();
    pos.x -= offset.x;
    pos.y -= offset.y;
    
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    frame->setPos(pos);
    frame->setAnchor(VfxFPoint(0.5f, 0.5f));
    VfxAutoAnimate::commit();
}


void VappHsShortcutPanel::setAnchor(VfxFrame *frame, VfxPoint &offset)
{
    VfxRect rect = frame->getBounds();

    // TODO: getMidX and getMidY does not round to the nearest number. Plus 0.5
    // here by ourself.
    VfxFloat x = (VfxFloat)(offset.x + rect.getMidX() + 0.5f) / rect.getWidth();
    VfxFloat y = (VfxFloat)(offset.y + rect.getMidY() + 0.5f) / rect.getHeight();

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    frame->setAnchor(VfxFPoint(x, y));
    VfxAutoAnimate::commit();
}


void VappHsShortcutPanel::getOffset(
    VfxControl *frame,
    VfxPenEvent &event,
    VfxPoint &offset)
{
    VfxRect bounds = frame->getBounds();
    VfxPoint penPos = event.getRelPos(frame);
    
    offset.x = penPos.x - bounds.getMidX();
    offset.y = penPos.y - bounds.getMidY();
}


void VappHsShortcutPanel::foldShortcutPool(VfxBool isFold)
{
    if (isFold)
    {
        s_isPoolOpened = VFX_FALSE;
        m_blackScreen->setHidden(VFX_TRUE);
        m_shortcutPool->fold();
    }
    else
    {
        s_isPoolOpened = VFX_TRUE;
        m_blackScreen->setHidden(VFX_FALSE);
        m_shortcutPool->unfold();
    }

    m_signalFolded.emit(this);

    // If the shortcut pool is open, cache all shortcut images for DnD.
    VappHsShortcut *ptr;
    
    for (ptr = m_shortcutMgr->getFirst(); ptr; ptr = m_shortcutMgr->getNext())
    {
        if (isFold)
        {
            ptr->setIsCached(VFX_FALSE); /* close, no cache */
        }
        else
        {
            ptr->setIsCached(VFX_TRUE);  /* open, cache */
        }
    }
}


void VappHsShortcutPanel::executeShortcut(VappHsDndImage *image)
{
    VappHsShortcut *shortcut = (VappHsShortcut *)image;

    if (shortcut->getImageId() == VAPP_HS_IMG_SC_SETTING)
    {
        // Toggle the shortcut pool folding.
        foldShortcutPool(m_shortcutPool->isUnfold());
    }
    else
    {
        // Launch the application associated with this shortcut.
        shortcut->launch();
    }
}


void VappHsShortcutPanel::onControlShortcutDrag(
    VappHsDndImage *image,
    VfxPenEvent &event)
{
    // Save the parent frame. That is shortcut bar or shortcut pool.
    m_movingFrameOriParent = (VappHsInteractiveImageArray *)image->getParentFrame();
    
    // Get the icon pen offset (from middle point to the pen point).
    getOffset(image, event, m_penPointOffsetS);

    // Highlight the shortcut icon.
    m_movingFrameOriParent->highlightImage(image, VFX_TRUE);
}


void VappHsShortcutPanel::onControlShortcutMove(
    VappHsDndImage *image,
    VfxPenEvent &event)
{
    // If m_movingFrameS == NULL, it means the shortcut is not in DnD mode.
    
    if (!m_movingFrameS)
    {
        if (image->containPoint(event.getRelPos(image)))
        {
            m_movingFrameOriParent->highlightImage(image, VFX_TRUE);
        }
        else
        {
            m_movingFrameOriParent->highlightImage(image, VFX_FALSE);
        }
        
        // The shortcut will enter DnD mode if the following conditions are met
        // 
        //  1) the pen is moved out of the image.
        //  2) the shortcut pool is open
        if (!image->containPoint(event.getRelPos(image)) &&
            m_shortcutPool->isUnfold())
        {
            m_movingFrameS = image;

            // Backup original image info for restoring.
            m_movingFrameOriParent->backupImage(image);
            
            // Remove from the parent. (VFX_FALSE: don't arrange)
            m_movingFrameOriParent->removeImage(image, VFX_FALSE);

            // Initialization (disable auto. animation during initialization)
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);

            setAnchor(m_movingFrameS, m_penPointOffsetS);
            m_movingFrameS->setOpacity(1.0f);

            // TODO
            //m_movingFrameS->setPos(event.getRelPos(this));
            VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
            const VfxFrame *root = renderer->getRootFrame();
            VFX_ASSERT(root != NULL);
            m_movingFrameS->setPos(root->convertPointTo(event.pos, this));

            VfxAutoAnimate::commit();

            // Use auto animation for the opacity of the active item.
            m_movingFrameS->setOpacity(s_moveOpacity);

            // Add icon in the App category.
            addChildFrame(m_movingFrameS); 
        }
    }
    else
    {
        // Force the position to make the moving smooth and real-time.
        // TODO
        //m_movingFrameS->forcePos(event.getRelPos(this));
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        const VfxFrame *root = renderer->getRootFrame();
        VFX_ASSERT(root != NULL);
        m_movingFrameS->forcePos(root->convertPointTo(event.pos, this));
        
        // On lite-version, the animation on the shortcut pool is not
        // active (i.e., arrange and cross effects are disable).
        if (m_shortcutBar->containPoint(event.getRelPos(m_shortcutBar)))
        {   
            // inside shortcut bar
            m_shortcutBar->cross(event);
        #if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
            m_shortcutPool->arrange(-1);
        #endif
        }
        else if (m_shortcutPool->containPoint(event.getRelPos(m_shortcutPool)))
        {   
            // inside shortcut pool
            m_shortcutBar->arrange(-1);
        #if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
            m_shortcutPool->cross(event);
        #endif
        }
        else
        {    
            // invalid region, restore shortcut bar and pool
            m_shortcutBar->arrange(-1);
        #if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
            m_shortcutPool->arrange(-1);
        #endif
        }
    }
}


void VappHsShortcutPanel::onControlShortcutDrop(
    VappHsDndImage *image,
    VfxPenEvent &event)
{
    // If m_movingFrameS == NULL, it means the shortcut does not enter the DnD
    // mode. We can execute the action assocaited with this shortcut.

    if (!m_movingFrameS)
    {
        m_movingFrameOriParent->highlightImage(image, VFX_FALSE);

        if (image->containPoint(event.getRelPos(image)))
        {
            // TODO: async. launch has some problem if the user quickly 
            // clicks two shortcut icons. Should be fixed later.
            // (MAUI_01606012)
            //
            // vfxPostInvoke(this, &VappHsScr::executeShortcut, image);
            //
            executeShortcut(image);
        }
    }
    else
    {
        VfxPoint currentPos, finalPos;

        resetAnchor(m_movingFrameS, m_penPointOffsetS);
        
        m_movingFrameS->setOpacity(1.0f);

        if (m_shortcutBar->containPoint(event.getRelPos(m_shortcutBar)) &&
            m_shortcutBar->getImageNumber() < MAX_SHORTCUT_IN_BAR)
        {
            // THIS PART IS COMPLICATED. BE PATIENT.
            //
            // Scenario: 
            //  Drop on the shortcut bar. The shortcut bar still have spaces.
            //
            // Problem: 
            //  If we directly add the icon to the shortcut bar, the 
            //  icon might be cutted by the bounds of the shortcut bar.
            //
            // Solution:
            //  1) Preview the final position of the icon
            //  2) Add the icon back to the App category
            //  3) Animate the icon to its final position
            //  4) Start a timer to callback when the animation completes
            //  5) When timer fires, add the widget to the widget bar

            m_shortcutPool->arrange(-1);
            previewDrop(m_shortcutBar, event, currentPos, finalPos);
        }
        else if (m_shortcutPool->containPoint(event.getRelPos(m_shortcutPool)) &&
                 image->getImageId() != VAPP_HS_IMG_SC_SETTING)
        {
            // THIS PART IS COMPLICATED. BE PATIENT.
            //
            // Scenario: 
            //  Drop on the shortcut pool. The image is not setting icon.
            //
            // Problem and Solution: 
            //  Similar as the above one.

            m_shortcutBar->arrange(-1);
            previewDrop(m_shortcutPool, event, currentPos, finalPos);
        }
        else
        {
            // THIS PART IS COMPLICATED. BE PATIENT.
            //
            // Scenario: 
            //  Drop on the other region. Animate the icon to its
            //  previous position.
            //
            // Problem and Solution: 
            //  Similar as the above one.

            m_shortcutBar->arrange(-1);
            m_shortcutPool->arrange(-1);
            previewDropExt(currentPos, finalPos);
        }
        
        // Restore the icon to its previous position. Then, auto animate
        // to its final position.
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        m_movingFrameS->setPos(currentPos);
        VfxAutoAnimate::commit();
        
        m_movingFrameS->setPos(finalPos);
        
        m_timerAddShortcut->start();
    }
}


void VappHsShortcutPanel::onBlackScreenDown()
{
    if (m_shortcutPool->isUnfold())
    {
        foldShortcutPool(VFX_TRUE);
    }
}


void VappHsShortcutPanel::setHistoryShortcut()
{
    if (s_isPoolOpened)
    {
        foldShortcutPool(VFX_FALSE);
    }
    else
    {
        foldShortcutPool(VFX_TRUE);
    }
}


VfxBool VappHsShortcutPanel::isUnFold()
{
    return m_shortcutPool->isUnfold();
}


void VappHsShortcutPanel::fold()
{
    // If shortcut pool is unfold, fold the shortcut pool.
    if (m_shortcutPool->isUnfold())
    {
        // If some shortcut is during the dropping animation, drop it 
        // immediately. Or the shortcut might be animated to a weird position
        // because the shortcut pool is closed. (MAUI_01775646)
        if (m_timerAddShortcut->getIsEnabled())
        {
            VFX_LOG(VFX_FUNC, VAPP_HS_FOLD_ALL_MSG, 2);
            
            m_timerAddShortcut->m_signalTick.emit(m_timerAddShortcut);
            m_timerAddShortcut->stop();
        }

        foldShortcutPool(VFX_TRUE);
    }
}


void VappHsShortcutPanel::foldState()
{
    s_isPoolOpened = VFX_FALSE;
}


void VappHsShortcutPanel::hide(VfxBool isHidden, VfxBool isEnforced)
{
    if (!isEnforced && s_isHidden == isHidden)
    {
        return;
    }
    
    VfxS32 height = m_bgImg->getBounds().getHeight();
    
    if (isHidden)
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_FALSE);

        // hide shortcut bar background
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_bgImg->setPos(VfxPoint(0, VappHsShortcutBar::Y_POS + height));
        
        // hide shortcut bar
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_shortcutBar->setPos(VfxPoint(0, VappHsShortcutBar::Y_POS + height));

        VfxAutoAnimate::commit();
    }
    else
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_FALSE);

        // unhide shortcut bar background
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_bgImg->setPos(VfxPoint(0, VappHsShortcutBar::Y_POS));
  
        // unhide shortcut bar
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_shortcutBar->setPos(VfxPoint(0, VappHsShortcutBar::Y_POS));

        VfxAutoAnimate::commit();
    }

    s_isHidden = isHidden;
}


VfxBool VappHsShortcutPanel::isHidden()
{
    return s_isHidden;
}


VfxControl *VappHsShortcutPanel::getFirstShortcut()
{
    return m_shortcutMgr->getFirst();
}


VfxControl *VappHsShortcutPanel::getNextShortcut()
{
    return m_shortcutMgr->getNext();
}


VfxSize VappHsShortcutPanel::getBarSize()
{
    return m_bgImg->getBounds().size;
}


void VappHsShortcutPanel::cancelShortcutDrop()
{
    // If some shortcut is during the dropping animation, drop it immediately
    // such that the state of the shortcut DnD mechanism can be reset.
    if (m_timerAddShortcut->getIsEnabled())
    {
        m_timerAddShortcut->m_signalTick.emit(m_timerAddShortcut);
        m_timerAddShortcut->stop();
    }
}

#endif /* __MMI_VUI_HOMESCREEN__ */

