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
 *  vcp_switch.h
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Switch component header
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_SWITCH_H__
#define __VCP_SWITCH_H__

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_signal.h"
#include "vfx_timer.h"

/* DOM-NOT_FOR_SDK-BEGIN */

class VfxPenEvent;
class VfxImageFrame;

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * Class VcpSwitch
 *
 * Switch is a ON/OFF button.
 *
 * EXAMPLE:
 * <code>
 *   VFX_OBJ_CREATE(m_switch, VcpSwitch, this);
 *   m_switch->SetChecked(VFX_TRUE);
 * </code>
 *****************************************************************************/
class VcpSwitch : public VfxControl
{
VFX_DECLARE_CLASS(VcpSwitch);

    // Constructor / Destructor
public:
    // <group DOM_Switch_VcpSwitch_Constructor/Destructor>
    VcpSwitch();


    // Property
public:
    // <group DOM_Switch_VcpSwitch_Property>
    // set the switch id
    void setId(VfxId id);

    // <group DOM_Switch_VcpSwitch_Property>
    // get the switch id
    VfxId getId();


    // Method
public:
    // <group DOM_Switch_VcpSwitch_Method>
    // Sets the switch state
    void setChecked(
        VfxBool checked,                // [IN]  checked flag
        VfxBool isAnimated = VFX_TRUE   // [IN] is animated
    );

    // <group DOM_Switch_VcpSwitch_Method>
    // Gets the switch state
    // RETURNS: VFX_TRUE if the switch is checked; otherwise, VFX_FALSE
    VfxBool getChecked()
    {
        return m_checked;
    }

    // <group DOM_Switch_VcpSwitch_Method>
    // set the background image in on/off state
    void setBgImage(VfxImageSrc onImage, VfxImageSrc offImage);

    // <group DOM_Switch_VcpSwitch_Method>
    // set slider image in on/off state
    void setSliderImage(VfxImageSrc onImage, VfxImageSrc offImage);

    // <group DOM_Switch_VcpSwitch_Method>
    // set the on/off icon
    void setIconImage(VfxImageSrc onImage, VfxImageSrc offImage);

    // <group DOM_Switch_VcpSwitch_Method>
    // set the slider position in on/off state
    void setBgPos(VfxPoint pos);

    // <group DOM_Switch_VcpSwitch_Method>
    // set the slider position in on/off state
    void setSliderPos(VfxPoint onPos, VfxPoint offPos);

    // <group DOM_Switch_VcpSwitch_Method>
    // set the position for the on/off icon
    void setIconPos(VfxPoint onIconPos, VfxPoint offIconPos);

    // Enable/Disable haptic touch feedback
    // Default: VFX_FALSE
    // <group DOM_Switch_VcpSwitch_Method>
    void setIsHapticTouchEnabled(VfxBool state);

    // Get haptic touch feedback status (Enabled or disabled)    
    // <group DOM_Switch_VcpSwitch_Method>
    VfxBool getIsHapticTouchEnabled();

    // <group DOM_Switch_VcpSwitch_Event>
    // switch state value change event
    VfxSignal2<VcpSwitch*, VfxBool> m_signalSwitchChanged;

    // <group DOM_Switch_VcpSwitch_Event>
    // This emits after the toggle animation is complete.
    // Use this instead of m_signalSwitchChanged, if your signal handler is doing heavy graphic work which may slow down toggle animation rendering.
    VfxSignal2<VcpSwitch*, VfxBool> m_signalToggleAnimationDone;


    // Override
public:
    // <group DOM_Switch_VcpSwitch_Override>
    virtual VfxBool onPenAbortAccepted(VfxControl *aborter, VfxPenAbortReasonEnum reason);

    void onSwitchAnimationComplete(VfxTimer *timer);

    // Override
protected:
    // <group DOM_Switch_VcpSwitch_Override>
    virtual void onInit();

    // <group DOM_Switch_VcpSwitch_Override>
    virtual void onDeinit();

    // <group DOM_Switch_VcpSwitch_Override>
    virtual VfxBool onPenInput(VfxPenEvent &event);

    // <group DOM_Switch_VcpSwitch_Override>
    virtual VfxBool onContainPoint(const VfxPoint &point) const;


    // Overridable
protected:
    // <group DOM_Switch_VcpSwitch_Overridable>
    // update state handler
    virtual void onUpdateState();


    // Implementation
private:
    // checked state
    VfxBool m_checked;
    VfxId m_id;
    VfxBool m_isHapticTouchEnabled;

    VfxTimer *m_animSyncTimer;

    // frames
    VfxImageFrame   *m_bgFrame;
    VfxImageFrame   *m_slider;
    VfxImageFrame   *m_onIcon;
    VfxImageFrame   *m_offIcon;

    // image source
    VfxImageSrc m_bgOnImage;
    VfxImageSrc m_bgOffImage;
    VfxImageSrc m_sliderOnImage;
    VfxImageSrc m_sliderOffImage;
    VfxImageSrc m_iconOnImage;
    VfxImageSrc m_iconOffImage;
    VfxPoint m_sliderOnPos;
    VfxPoint m_sliderOffPos;
};


#endif /* __VCP_SWITCH_H__ */

