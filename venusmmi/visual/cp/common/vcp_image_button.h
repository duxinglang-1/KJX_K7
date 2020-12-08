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
 *  vcp_image_button.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Description
 *  Header file for image button class
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCP_IMG_BUTTON_H__
#define __VCP_IMG_BUTTON_H__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vcp_state_image.h"
#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vfx_basic_type.h"

/*****************************************************************************
 * Define
 *****************************************************************************/

enum VcpGlowVisualTypeEnum
{
    VCP_GLOW_VISUAL_TYPE_2D,
    VCP_GLOW_VISUAL_TYPE_3D,
    VCP_GLOW_VISUAL_TYPE_END
};

class VcpGlowEffectVisual;
class VcpGlowBaseFrame;

/*****************************************************************************
 * Typedef
 *****************************************************************************/

// <group DOM_ImageButton_Macro&Enum_Enum>
// image button state enum
enum VcpImageButtonStateEnum
{
    VCP_IMAGE_BUTTON_STATE_NORMAL,      // normal state
    VCP_IMAGE_BUTTON_STATE_PRESSED,     // pressed state
    VCP_IMAGE_BUTTON_STATE_DISABLED,    // disabled state
    VCP_IMAGE_BUTTON_STATE_END_OF_ENUM  // end of the enum
};


/*****************************************************************************
 * Class VcpImageButton
 *****************************************************************************/
class VcpImageButton: public VfxControl
{
    VFX_DECLARE_CLASS(VcpImageButton);

    // Constructor / Destructor
public:
    // <group DOM_ImageButton_VcpImageButton_Constructor/Destructor>
    VcpImageButton();

    // Method
public:
    // <group DOM_ImageButton_VcpImageButton_Method>
    // Switch to turn on/off highlight flag
    void setIsHighlight(VfxBool highlight);

    // Signal
public:
    // <group DOM_ImageButton_VcpImageButton_Event>
    // This signal is invoked when the image button state is changed
    VfxSignal2 <VcpImageButton*, VcpImageButtonStateEnum>  m_signalStateChanged;

    // <group DOM_ImageButton_VcpImageButton_Event>
    // This signal is invoked when the image button is clicked
    VfxSignal2 <VfxObject*, VfxId>  m_signalClicked;

    //Property
public:

    // <group DOM_ImageButton_VcpImageButton_Property>
    // Set image list for each state of the button
    void setImage (
        const VcpStateImage &imageList     // [IN] image list of the button
        );

    // <group DOM_ImageButton_VcpImageButton_Property>
    // set if the button image shall be stretched to fit button size
    void setIsStretchMode(
        VfxBool  isStretchMode
        );

    // <group DOM_ImageButton_VcpImageButton_Property>
    // set User Defined Button ID to identify the button when the click signal is invoked
    void setId(
        VfxId id                            // [IN] User defined ID
        );

    // <group DOM_ImageButton_VcpImageButton_Property>
    // get the image object
    // RETURNS: pointer of the image object
    const VcpStateImage &   getImage () const;

    // <group DOM_ImageButton_VcpImageButton_Property>
    // get is stretch mode
    VfxBool     getIsStretchMode() const;

    // <group DOM_ImageButton_VcpImageButton_Property>
    // get Button ID
    VfxId getId() const;

    // <group DOM_ImageButton_VcpImageButton_Property>
    void setState(VcpImageButtonStateEnum state);

    // <group DOM_ImageButton_VcpImageButton_Property>
    VcpImageButtonStateEnum getState() const;

    // <group DOM_ImageButton_VcpImageButton_Property>
    // Switch to turn on/off transition effect
    // Default value: VFX_FALSE
    void setIsEffect(
        VfxBool  isEffect       // [IN] Switch to turn on/off transition effect
        );

    // <group DOM_ImageButton_VcpImageButton_Property>
    // get is effect turned on
    VfxBool getIsEffect() const;

    // <group DOM_ImageButton_VcpImageButton_Property>
    // Control area for display transition effect
    // set the relative size of the effect frame
    // Default Value: 1.0f
    void setEffectRatio(
        VfxFloat  ratio         // [IN] Ratio of rectangle for transition effect frame (relatived to the control area).
        );

    // <group DOM_ImageButton_VcpImageButton_Property>
    // get effect ratio
    VfxFloat getEffectRatio() const;

    // <group DOM_ImageButton_VcpImageButton_Property>
    // set the absolute size of effect frame
    void setEffectSize(VfxSize size);

    // <group DOM_ImageButton_VcpImageButton_Property>
    // get effect size
    VfxSize getEffectSize();

    // <group DOM_ImageButton_VcpImageButton_Property>
    // set the offset of the effect frame
    // Default value: (0, 0)
    void setEffectOffset(VfxPoint offset);

    // <group DOM_ImageButton_VcpImageButton_Property>
    // get effect offset
    VfxPoint getEffectOffset();

    // <group DOM_ImageButton_VcpImageButton_Property>
    // set the glow effect type
    void setEffectGlowType(VcpGlowVisualTypeEnum type);

    // <group DOM_ImageButton_VcpImageButton_Property>
    // get glow effect type
    VcpGlowVisualTypeEnum getEffectGlowType();

    // Enable/Disable haptic touch feedback
    // Default: VFX_FALSE
    // <group DOM_Button_VcpButton_Property>
    void setIsHapticTouchEnabled(VfxBool state);

    // Get haptic touch feedback status (Enabled or disabled)    
    // <group DOM_Button_VcpButton_Property>
    VfxBool getIsHapticTouchEnabled();



    // Implementation
private:
    // <group DOM_ImageButton_VcpImageButton_Implementation>
    // Whether haptic touch is enabled
    VfxBool m_isHapticTouchEnabled;

    // <group DOM_ImageButton_VcpImageButton_Implementation>
    VcpImageButtonStateEnum     m_state;

    // <group DOM_ImageButton_VcpImageButton_Implementation>
    VfxBool                     m_isStretchMode;

    // <group DOM_ImageButton_VcpImageButton_Implementation>
    VfxBool                     m_isHighlight;

    // <group DOM_ImageButton_VcpImageButton_Implementation>
    // Image for each state
    VcpStateImage               m_imageList;

    // <group DOM_ImageButton_VcpImageButton_Implementation>
    VfxBool                     m_isEffect;

    // <group DOM_ImageButton_VcpImageButton_Implementation>
    // Ratio of effect area relative  to the control area
    VfxFloat                    m_effectRatio;   

    // <group DOM_ImageButton_VcpImageButton_Implementation>
    VfxSize                     m_effectSize;

    // <group DOM_ImageButton_VcpImageButton_Implementation>
    VfxPoint                    m_effectOffset;

    // <group DOM_ImageButton_VcpImageButton_Implementation>
    // User defined id for the button
    VfxId                       m_id;


    // Imported from visual
private:
    VfxRect             m_effectRect;
    VcpGlowBaseFrame *  m_effectFrame;
    VcpGlowVisualTypeEnum m_effectType;
    VfxTimer *m_timer;

    // Implementation
private:
    // <group DOM_ImageButton_VcpImageButton_Implementation>
    void setPressed(VfxBool isPressed);

    // <group DOM_ImageButton_VcpImageButton_Implementation>
    void visualLayout();


    void onAfterClick();
    // Override
protected:
    // <group DOM_ImageButton_VcpImageButton_Override>
    virtual VfxBool onPenInput(VfxPenEvent &event);

    // <group DOM_ImageButton_VcpImageButton_Override>
    virtual VfxBool onContainPoint(const VfxPoint &point) const;

    // <group DOM_ImageButton_VcpImageButton_Override>
    virtual void    onUpdate();

    // <group DOM_ImageButton_VcpImageButton_Override>
    virtual void    onInit();

    // <group DOM_ImageButton_VcpImageButton_Override>
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

    // <group DOM_ImageButton_VcpImageButton_Override>
    virtual void launchEffect();    
    // <group DOM_ImageButton_VcpImageButton_Override>
    virtual void stopEffect(VfxTimer *timer);
    // <group DOM_ImageButton_VcpImageButton_Implementation>
    VfxFrame* findBindingScreen();
    // <group DOM_ImageButton_VcpImageButton_Implementation>
    VfxFrame* findBindingParent();
    // <group DOM_ImageButton_VcpImageButton_Implementation>
    void  launchHideGlow();


    // Override
public:
    // <group DOM_ImageButton_VcpImageButton_Override>
    virtual void setIsDisabled(VfxBool isDisabled);

    // <group DOM_ImageButton_VcpImageButton_Override>
    virtual void setBounds(const VfxRect &value);

    // <group DOM_ImageButton_VcpImageButton_Override>
    void setBounds(VfxS32 x, VfxS32 y, VfxS32 width, VfxS32 height);
};

#endif /* __VCP_IMG_BUTTON_H__ */

