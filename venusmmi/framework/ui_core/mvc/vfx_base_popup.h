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
 *  vfx_base_popup.h
 *
 * Project:
 * --------
 *  Venus base popup
 *
 * Description:
 * ------------
 *  Venus Cube Component
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef __VFX_BASE_POPUP_H__
#define __VFX_BASE_POPUP_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxControl
#include "vfx_control.h"

// For VcpEffectType
#include "vcp_frame_effect_type.h"

#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vfx_frame.h"
#include "vfx_screen.h"
#include "vcp_frame_effect.h"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// Pre-defined class
class VcpFrameEffect;

// Popup state
enum VfxBasePopupStateEnum
{
    VFX_BASE_POPUP_STATE_UNKNOWN = 0,
    VFX_BASE_POPUP_BEFORE_START_ANIMATION,
    VFX_BASE_POPUP_AFTER_START_ANIMATION,
    VFX_BASE_POPUP_BEFORE_END_ANIMATION,
    VFX_BASE_POPUP_AFTER_END_ANIMATION,
    VFX_BASE_POPUP_END_OF_ENUM
};

#define VFX_TOP_LEVEL_Z_POPUP   5000

/*****************************************************************************
 * Class VfxBasePopup
 *****************************************************************************/

/*
 *  VcpBasePopup provide a basic popup mechansim. When user call show(), it will
 *  perform a popup animation. Calling hide(), it will be hide and play hide
 *  animation. if user calling exit, it will close itselft additionally.
 */
class VfxBasePopup : public VfxControl
{
    VFX_DECLARE_CLASS(VfxBasePopup);

// Constructor / Destructor
public:
    // Default constructor
    VfxBasePopup(); 

// Method
public:
    // Show the popup
    void show(
        VfxBool isAnim      // [IN] show animation or not
    );
    
    // Hide the popup
    void hide(
        VfxBool isAnim      // [IN] show animation or not
    );
    
    // Exit the popup, it will close itself
    void exit(
        VfxBool isAnim      // [IN] show animation or not
    );
    
    // Leave the popup, it will close itself depend on autoDestory
    void leave(
        VfxBool isAnim      // [IN] show animation or not
    );

    // Set custom frame effect
    void setFrameEffect(
        VcpEffectType effectType,           // [IN] the type of effect                          
        VfxMsec duration,                   // [IN] the durtion of the effect 
        VcpEffectTypeDirection direction,   // [IN] the direction of the effect
        void *data,                         // [IN] parameter to change some attribute
        VfxS32 dataSize                     // [IN] parameter size
    );

	void setStaticShelter(VfxBool isStatic)		
	{
		m_isStaticShelter = isStatic;
	}
	VfxBool getIsStaticShelter() const
	{
		  return m_isStaticShelter;
	}

    //use static background or not	
    
// Property
public:
    // Whatever destory the popup after popup leave by itself, 
    //  such like press key or time out. The default value is VFX_TRUE
    void setAutoDestory(
        VfxBool value       // [IN] autoDestory
    )
    {
        m_autoDestory = value;
    }

    // Return whatever destory the popup after popup leave by itself
    //
    // RETURNS: Whatever destory the popup after popup leave by itself
    VfxBool getAutoDestory() const
    {
        return m_autoDestory;
    }

    // If catch the focus when showing the popup. The default value is VFX_TRUE
    void setCatchFocus(
        VfxBool value       // [IN] autoDestory
    )
    {
        m_catchFocus = value;
    }

    // Return If catch the focus when showing the popup
    VfxBool getCatchFocus() const
    {
        return m_catchFocus;
    }

// Signal
public:
    // This singal is used to notify popup state
    // void YourClass::onPopupStateChanged(VfxBasePopup* popup, VfxBasePopupStateEnum state)
    VfxSignal2 <
        VfxBasePopup*,          // popup
        VfxBasePopupStateEnum   // state
    > m_signalPopupState;

// Framework method, internal used
public:
    // Enter this popup
    void processEnter(VfxBool isAnim, VfxBool isAnimBlocking);
    // Leave this popup
    void processExit(VfxBool isAnim, VfxBool isAnimBlocking);
    // Enter to a screen stack (after)
    void processEnterStack(VfxScreen *screen);
    // Leave from a screen stack (before)
    void processLeaveStack(VfxScreen *screen);

    //
    VfxMsec getEffectDuration() const
    {
        return m_duration;
    }

    // Internal used, return the rotate type
    VfxScrRotateTypeEnum getRotateType() const
    {
        return m_rotateType;
    }
    // Internal used. 
    void processRotate(const VfxScreenRotateParam &param);

    // Internal used.
    void processLeavedPopup();

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

    virtual void processRegisterAccessKeyHandler(VfxKeyCodeEnum keyCode, VfxControl *target);
    virtual void processUnregisterAccessKeyHandler(VfxKeyCodeEnum keyCode, VfxControl *target);
    virtual void processUnregisterAllAccessKeyHandler(VfxControl *target);

    void onFocusChanged(VfxBool value);
    virtual void onObjectNotify(VfxId eventId, void *userData);

// Override
public:
    virtual VfxBool processFocusKey(VfxKeyEvent &event);

    virtual void setHidden(VfxBool value);

// Overridable
protected:
    friend class VfxTopLevel;
    friend class VfxScreen;

    // Get the target screen of the popup
    VfxScreen *getTargetScreen() const
    {
        return m_targetScreen;
    }

    // Internal used, cancel exist popup effect.
    void cancelEffect();

    // Override the virtual function to return whatever the popup 
    //  need to push to history. Most popup need to push to stack,
    //  but some popup, for example, waiting icon does not need.
    virtual VfxBool needPushHistory() const;

    // While entering the popup to be active
    virtual void onEnter();
    
    // While leaving the popup to be inactive
    virtual void onExit();

    // While leaving the popup to be inactive (after animaiton)
    virtual void onExited();
    
    // While push the popup into popup stack of the screen
    virtual void onEnterStack();

    // While pop the popup from popup stack of the screen
    virtual void onLeaveStack();

    // While the LCD screen has been rotate
    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    );

    // When user pen on Out side area, this function will be called.
    virtual void onPenInputOnOutside(VfxPenEvent &event);

    virtual void onPlayTone();
    
    virtual void onStopTone();

// Overridable, used for IME layout
public:
    // While IME becomes active, it notifies top level to adjust layout to fit input area
    virtual void setIMElayout(
        VfxRect &imeRect,       // [IN] IME area
        VfxFrame *imeOwner      // [IN] The owner who creates IME
    ){}

    // While IME becomes inactive, it notifies to reset the layout
    virtual void resetIMElayout(){}

// implementation
private:
    enum DestroyTypeEnum
    {
        DESTROY_TYPE_NONE = 0,
        DESTROY_TYPE_CLOSE,     // Always close
        DESTROY_TYPE_HIDE,      // Always hide
        DESTROY_TYPE_END_OF_ENUM
    };

	VfxBool m_isStaticShelter;
    VfxBasePopupStateEnum   m_state;
    
    VfxScreen              *m_targetScreen;
    
    // if AutoDestory is set, it will close itself when user finish his
    // command (ex. press outside area or press button)
    VfxBool                 m_autoDestory;

    DestroyTypeEnum         m_destoryType;

    // Frame property effect configure data    
    VcpFrameEffect         *m_frameEffect;
    VcpEffectType           m_effectType;
    VfxMsec                 m_duration;
    VcpEffectTypeDirection  m_direction;
    void                   *m_data;
    VfxS32                  m_dataSize;

    VfxBool                 m_catchFocus;
    VfxScrRotateTypeEnum    m_rotateType;

    // Access key manager.
    VfxAccessKeyMgr         *m_pAccessKeyMgr;

    VfxBool                 m_restoreAutoAnimate;

    void onFrameEffectFinished(VfxFrame *target, VfxBool isCompleted);
    void processAfterEnter();
    void processAfterExit();
    void closePopup();    
#ifdef __COSMOS_3D_V10__
    void afterEnterEffect();
#endif
};

#endif /* __VFX_BASE_POPUP_H__ */

