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
 *  vcp_popup.cpp
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
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "vfx_base_popup.h"

// TODO: revise these include
#include "vcp_frame_effect.h"

#include "vfx_cpp_base.h"
#include "vcp_frame_effect_type.h"
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vfx_screen.h"
#include "vfx_transform.h"
#include "vfx_frame.h"
#include <string.h>


/*****************************************************************************
 * Class VfxBasePopup
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VfxBasePopup", VfxBasePopup, VfxControl);

VfxBasePopup::VfxBasePopup() :
    m_isStaticShelter(VFX_FALSE),
    m_state(VFX_BASE_POPUP_STATE_UNKNOWN),
    m_targetScreen(NULL),
    m_autoDestory(VFX_TRUE),
    m_destoryType(DESTROY_TYPE_NONE),
    m_frameEffect(NULL),
#if defined(__MMI_FTE_SUPPORT_SLIM__)
    m_effectType(VCP_EFFECT_FADE_IN),
#else
    m_effectType(VCP_EFFECT_POPUP),
#endif
    m_duration(300),
    m_direction(VCP_EFFECT_DIRECTION_FROM_NONE),
    m_data(NULL),
    m_dataSize(0),
    m_catchFocus(VFX_TRUE),
    m_rotateType(VFX_SCR_ROTATE_TYPE_NORMAL),
    m_pAccessKeyMgr(NULL),
    m_restoreAutoAnimate(VFX_FALSE)
{
}


void VfxBasePopup::onInit()
{
    VfxControl::onInit();

    // Find and save the target screen    
    m_targetScreen = findScreen();
    // NOTE: Can not find screen
    VFX_ASSERT(m_targetScreen != NULL);

    // Set defualt properties
    setAnchor(0.5f,0.5f);
    setBounds(0, 0, 200, 200);
    setHidden(VFX_TRUE);
    setIsCached(VFX_TRUE);

    setPosZ(VFX_TOP_LEVEL_Z_POPUP); // Sub-class can override the Z value if need

    VFX_OBJ_CREATE(m_pAccessKeyMgr, VfxAccessKeyMgr, this);
}


void VfxBasePopup::onDeinit()
{
    hide(VFX_FALSE);

    VFX_FREE_MEM(m_data);
    
    VfxControl::onDeinit();
}


VfxBool VfxBasePopup::onPenInput(VfxPenEvent &event)
{
    VFX_UNUSED(event);

    return VFX_TRUE;
}


VfxBool VfxBasePopup::onKeyInput(VfxKeyEvent &event)
{
    // Except end key, popup block all keys
    if ((event.keyCode != VFX_KEY_CODE_END) &&
        (event.keyCode != VFX_KEY_CODE_HOME) &&
        (event.keyCode != VFX_KEY_CODE_POWER) &&
        (event.keyCode != VFX_KEY_CODE_VOL_DOWN) &&
        (event.keyCode != VFX_KEY_CODE_VOL_UP))
    {
        return VFX_TRUE;
    }

    return VfxControl::onKeyInput(event);
}


void VfxBasePopup::processRegisterAccessKeyHandler(VfxKeyCodeEnum keyCode, VfxControl *target)
{
    VFX_DEV_ASSERT(m_pAccessKeyMgr != NULL);
    m_pAccessKeyMgr->registerHandler(keyCode, target);
}


void VfxBasePopup::processUnregisterAccessKeyHandler(VfxKeyCodeEnum keyCode, VfxControl *target)
{
    VFX_DEV_ASSERT(m_pAccessKeyMgr != NULL);
    m_pAccessKeyMgr->unregisterHandler(keyCode, target);
}


void VfxBasePopup::processUnregisterAllAccessKeyHandler(VfxControl *target)
{   
    VFX_DEV_ASSERT(m_pAccessKeyMgr != NULL);
    m_pAccessKeyMgr->unregisterAllHandler(target);
}


VfxBool VfxBasePopup::processFocusKey(VfxKeyEvent &event)
{
    VfxBool ret = VFX_FALSE;

    // If there is focused child, let it handle first
    if (getFocusChildFrame())
    {
        ret = getFocusChildFrame()->processFocusKey(event);
    }

    // If there is access key registered, process it
    if (!ret)
    {
        VFX_DEV_ASSERT(m_pAccessKeyMgr != NULL);
        ret = m_pAccessKeyMgr->processKeyInput(event);
    }

    // If there is no other one handle it, handle it by screen it self.
    if (!ret)
    {
        ret = onKeyInput(event);
    }
    return ret;
}


void VfxBasePopup::onFocusChanged(VfxBool value)
{
    VfxControl::onFocusChanged(value);

    if (value)
    {
        VfxKeypad* keypad = VFX_OBJ_GET_INSTANCE(VfxKeypad);
        keypad->registerTranslateKey();
    }        
}


void VfxBasePopup::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_FRAME_NOTIFY_ID_FOCUS_CHANGED:
        {
            onFocusChanged(*(VfxBool *)userData);
            return;
        }
        default:
        {
            VfxControl::onObjectNotify(id, userData);
            return;
        }
    }
}


void VfxBasePopup::processRotate(const VfxScreenRotateParam &param)
{
    m_rotateType = param.rotateTo;
    onRotate(param);
}


void VfxBasePopup::onRotate(const VfxScreenRotateParam &param)
{
    VFX_DEV_ASSERT(m_targetScreen != NULL);

    if (m_frameEffect && m_state == VFX_BASE_POPUP_BEFORE_START_ANIMATION)
    {
        m_frameEffect->restore();
    }

    // Backup auto-animation
    VfxBool autoAnimate = getAutoAnimate();

    // From
    setAutoAnimate(VFX_FALSE);
    setPos(m_targetScreen->getBounds().getMidPoint());
    VfxTransform t;
    t.data.affine.rz = VFX_DEG_TO_RAD(90.0f) * 
        (((VfxU32)param.rotateTo - (VfxU32)param.rotateFrom + 4) % 4);
    if (t.data.affine.rz > VFX_DEG_TO_RAD(180.0f))
    {
        t.data.affine.rz -= VFX_DEG_TO_RAD(360.0f);
    }
    setTransform(t);
    setQuality(VFX_RENDER_QUALITY_NORMAL);

    // To
    setAutoAnimate(VFX_TRUE);
    t.setIdentity();
    setTransform(t);

    // Restore auto-animation
    setAutoAnimate(autoAnimate);

    if (m_frameEffect && m_state == VFX_BASE_POPUP_BEFORE_START_ANIMATION)
    {
        m_frameEffect->applyEffect(this, m_effectType, m_duration, m_direction, VFX_FALSE, m_data, m_dataSize);
    }
}


void VfxBasePopup::onPenInputOnOutside(VfxPenEvent &event)
{
    VFX_UNUSED(event);
    // Do nothing
}


void VfxBasePopup::onPlayTone()
{
    // Empty for override
}


void VfxBasePopup::onStopTone()
{
    // Empty for override
}


void VfxBasePopup::setHidden(VfxBool value)
{
    VfxControl::setHidden(value);

    if (value)
    {
        // Disable auto animate when hidden
        m_restoreAutoAnimate = getAutoAnimate();
        setAutoAnimate(VFX_FALSE);
    }
    else
    {
        if (m_restoreAutoAnimate)
        {
            setAutoAnimate(VFX_TRUE);
        }
    }
}


void VfxBasePopup::show(VfxBool isAnim)
{
    VFX_ASSERT(m_targetScreen != NULL);

    // reset
    m_destoryType = DESTROY_TYPE_NONE;
    
    // Process all post update before showing the popup
    processUpdate();
    
    m_targetScreen->showPopup(this, isAnim);
}


void VfxBasePopup::hide(VfxBool isAnim)
{   
    VFX_ASSERT(m_targetScreen != NULL);
    
    m_destoryType = DESTROY_TYPE_HIDE;
    m_targetScreen->leavePopup(this, isAnim);
}


void VfxBasePopup::exit(VfxBool isAnim)
{
    VFX_ASSERT(m_targetScreen != NULL);
    
    m_destoryType = DESTROY_TYPE_CLOSE;
    m_targetScreen->leavePopup(this, isAnim);
}


void VfxBasePopup::leave(VfxBool isAnim)
{
    if (m_autoDestory)
        exit(isAnim);
    else
        hide(isAnim);
}


VfxBool VfxBasePopup::needPushHistory() const
{
    return VFX_TRUE;
}


void VfxBasePopup::onEnter()
{
    // Default set pos to screen center
    // Reset display properties
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    
    setPos(m_targetScreen->getBounds().getMidPoint());

    VfxAutoAnimate::commit();
}


void VfxBasePopup::onExit()
{
    // Do nothing
}


void VfxBasePopup::onExited()
{
    // Do nothing
}


void VfxBasePopup::onEnterStack()
{
    // Do nothing
}


void VfxBasePopup::onLeaveStack()
{
    // Do nothing
}


void VfxBasePopup::cancelEffect()
{
    if (m_state == VFX_BASE_POPUP_BEFORE_START_ANIMATION)
    {
        processAfterEnter();

        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->removeBlockAfterNextCommitCallback(VfxCallback0(this, &VfxBasePopup::processAfterEnter));
    }
    else if (m_state == VFX_BASE_POPUP_BEFORE_END_ANIMATION)
    {
        processAfterExit();

        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->removeBlockAfterNextCommitCallback(VfxCallback0(this, &VfxBasePopup::processAfterExit));
    }
    else
    {
        // Do nothing
    }
}


void VfxBasePopup::onFrameEffectFinished(VfxFrame *target, VfxBool isCompleted)
{
    VFX_UNUSED(target);

    if (!isCompleted)
    {
        return;
    }
    
    if (m_state == VFX_BASE_POPUP_BEFORE_START_ANIMATION)
    {
        processAfterEnter();
    }
    else if (m_state == VFX_BASE_POPUP_BEFORE_END_ANIMATION)
    {
        processAfterExit();
    }
    else
    {
        VFX_ASSERT(0);
    }
}


void VfxBasePopup::processEnter(VfxBool isAnim, VfxBool isAnimBlocking)
{
    VFX_DEV_ASSERT(m_targetScreen != NULL);

    // Cancel exist effect
    cancelEffect();

    setHidden(VFX_FALSE);

    // Emit signal
    m_state = VFX_BASE_POPUP_BEFORE_START_ANIMATION;
    m_signalPopupState.postEmit(this, m_state);

    // Callback
    onEnter();
    
    // Start effect if needed
    if (isAnim)
    {
        // Create frame effect
        VFX_DEV_ASSERT(m_frameEffect == NULL);
        VFX_OBJ_CREATE(m_frameEffect, VcpFrameEffect, this);
        if (!isAnimBlocking)
        {
            m_frameEffect->m_signalFinished.connect(this, &VfxBasePopup::onFrameEffectFinished);
        }
        m_frameEffect->applyEffect(this, m_effectType, m_duration, m_direction, VFX_FALSE, m_data, m_dataSize);

        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->mustShowTime(m_duration);
        if (isAnimBlocking)
        {
            renderer->blockAfterNextCommit(m_duration, VfxCallback0(this, &VfxBasePopup::processAfterEnter));
        }
        return;
    }

    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();
    renderer->blockAfterNextCommit(1, VfxCallback0(this, &VfxBasePopup::processAfterEnter));
}


void VfxBasePopup::processExit(VfxBool isAnim, VfxBool isAnimBlocking)
{
    // Cancel exist effect
    cancelEffect();

    VFX_OBJ_CLOSE(m_frameEffect);

    // Emit signal
    m_state = VFX_BASE_POPUP_BEFORE_END_ANIMATION;
    m_signalPopupState.postEmit(this, m_state);

    // Callback
    onExit();

    // Start effect if needed
    if (isAnim)
    {
        // Create frame effect
        VFX_DEV_ASSERT(m_frameEffect == NULL);
        VFX_OBJ_CREATE(m_frameEffect, VcpFrameEffect, this);
        if (!isAnimBlocking)
        {
            m_frameEffect->m_signalFinished.connect(this, &VfxBasePopup::onFrameEffectFinished);
        }
        m_frameEffect->applyEffect(this, m_effectType, m_duration, m_direction, VFX_TRUE, m_data, m_dataSize);

        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->mustShowTime(m_duration);
        if (isAnimBlocking)
        {
            renderer->blockAfterNextCommit(m_duration, VfxCallback0(this, &VfxBasePopup::processAfterExit));
        }
        return;
    }
    
    processAfterExit();
}


void VfxBasePopup::processAfterEnter()
{
    VFX_DEV_ASSERT(m_state == VFX_BASE_POPUP_BEFORE_START_ANIMATION);
    
    // restore frame effect
    VFX_OBJ_CLOSE(m_frameEffect);

#ifdef __COSMOS_3D_V10__
    VfxSimpleTimer::start(VfxCallback0(this, &VfxBasePopup::afterEnterEffect), 1);
#endif
    
    // Emit signal
    m_state = VFX_BASE_POPUP_AFTER_START_ANIMATION;
    m_signalPopupState.postEmit(this, m_state);
}


#ifdef __COSMOS_3D_V10__
void VfxBasePopup::afterEnterEffect()
{
    VFX_OBJ_CREATE(m_frameEffect, VcpFrameEffect, this);
    m_frameEffect->applyEffect(this, VCP_EFFECT_3D_BLING, 600, VCP_EFFECT_DIRECTION_FROM_LEFT, VFX_FALSE, NULL, 0);
}
#endif


void VfxBasePopup::processAfterExit()
{
    VFX_DEV_ASSERT(m_state == VFX_BASE_POPUP_BEFORE_END_ANIMATION);
    
    // restore frame effect
    VFX_OBJ_CLOSE(m_frameEffect);
    
    // Emit signal
    m_state = VFX_BASE_POPUP_AFTER_END_ANIMATION;
    m_signalPopupState.postEmit(this, m_state);

    // Callback
    onExited();

#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)
    // The ShellAPP UE defines a popup always closed when screen leaving
    vfxPostInvoke0(this, &VfxBasePopup::closePopup);
#else
    // Close or hide this popup
    if (m_destoryType == DESTROY_TYPE_CLOSE)
    {
        vfxPostInvoke0(this, &VfxBasePopup::closePopup);
    }
    else
    {
        setHidden(VFX_TRUE);
    }
#endif
}


void VfxBasePopup::processEnterStack(VfxScreen *screen)
{
    m_destoryType = DESTROY_TYPE_NONE;

    // Play tone on enter stack
    onPlayTone();

    // Callback
    onEnterStack();
}


void VfxBasePopup::processLeaveStack(VfxScreen *screen)
{
    // Stop tone on leave stack
    onStopTone();

    // Callback
    onLeaveStack();

    if (m_destoryType == DESTROY_TYPE_NONE && m_autoDestory)
    {
        m_destoryType = DESTROY_TYPE_CLOSE;
    }
}


void VfxBasePopup::closePopup()
{
    VFX_OBJ_ASSERT_VALID(this);
    
    VfxBasePopup *self = this;
    VFX_OBJ_CLOSE(self);
}


void VfxBasePopup::processLeavedPopup()
{
    if (m_state != VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {
        // This popup has not leaved yet
        return;
    }

    // close leaved popup
    if (m_destoryType == DESTROY_TYPE_CLOSE)
    {
        vfxPostInvoke0(this, &VfxBasePopup::closePopup);
    }
}


void VfxBasePopup::setFrameEffect(
    VcpEffectType effectType,                          
    VfxMsec duration,                   
    VcpEffectTypeDirection direction,   
    void *data,                         
    VfxS32 dataSize)
{
    VFX_FREE_MEM(m_data);

    m_effectType = effectType;
    m_duration = duration;
    m_direction = direction;
    m_dataSize = dataSize;
    if (m_dataSize > 0)
    {
        VFX_ALLOC_MEM(m_data, m_dataSize, this);
        memcpy(m_data, data, m_dataSize);
    }
}

