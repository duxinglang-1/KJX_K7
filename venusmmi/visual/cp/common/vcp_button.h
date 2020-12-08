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
 *  vcp_button.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Button for Venus UI
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_BUTTON_H__
#define __VCP_BUTTON_H__

#ifndef __cplusplus
// If you don't allow C to include this file, remove following //
// #error "This header file can be used in C++ only."
#endif

/*****************************************************************************
 * Include
 *****************************************************************************/

// deprecated, for backward compatibility only, will be removed
#include "vcp_button_internal.h"

#include "vcp_state_image.h"
#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vcp_state_image.h"
#include "vfx_font_desc.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"
#include "vcp_marquee.h"
#include "vfx_string.h"
#include "mmi_rp_srv_venus_component_button_def.h"


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * Define
 *****************************************************************************/

#if defined(__MMI_VUI_COSMOS_CP__)
#define VCP_BTN_COLOR_TXT_DEFAULT_BRDR      VFX_COLOR_RES(VCP_COL_BTN_TXT_DEFAULT_BRDR)
#define VCP_BTN_COLOR_TXT_DEFAULT_NRML      VFX_COLOR_RES(VCP_COL_BTN_TXT_DEFAULT_NRML)
#define VCP_BTN_COLOR_TXT_DEFAULT_PRSD      VFX_COLOR_RES(VCP_COL_BTN_TXT_DEFAULT_PRSD)
#define VCP_BTN_COLOR_TXT_DEFAULT_DSBD      VFX_COLOR_RES(VCP_COL_BTN_TXT_DEFAULT_DSBD)
#define VCP_BTN_COLOR_TXT_DEFAULT_HLTD      VFX_COLOR_RES(VCP_COL_BTN_TXT_DEFAULT_HLTD)
#define VCP_BTN_COLOR_TXT_STYLE_DEFAULT_01  VFX_COLOR_RES(VCP_COL_BTN_TXT_STYLE_DEFAULT_01)
#define VCP_BTN_COLOR_TXT_STYLE_DEFAULT_02  VFX_COLOR_RES(VCP_COL_BTN_TXT_STYLE_DEFAULT_02)
#define VCP_BTN_COLOR_TXT_STYLE_RED         VFX_COLOR_RES(VCP_COL_BTN_TXT_STYLE_RED)
#define VCP_BTN_COLOR_TXT_STYLE_GREY        VFX_COLOR_RES(VCP_COL_BTN_TXT_STYLE_GREY)
#define VCP_BTN_COLOR_TXT_STYLE_SIM1        VFX_COLOR_RES(VCP_COL_BTN_TXT_STYLE_SIM1)
#define VCP_BTN_COLOR_TXT_STYLE_SIM2        VFX_COLOR_RES(VCP_COL_BTN_TXT_STYLE_SIM2)
#define VCP_BTN_COLOR_TXT_STYLE_NORMAL      VFX_COLOR_RES(VCP_COL_BTN_TXT_STYLE_NORMAL)
#else
#define VCP_BTN_COLOR_TXT_DEFAULT_BRDR       VFX_COLOR_BLACK
#define VCP_BTN_COLOR_TXT_DEFAULT_NRML       VfxColor(255, 226, 226, 226)
#define VCP_BTN_COLOR_TXT_DEFAULT_PRSD       VfxColor(255, 72, 49, 0)
#define VCP_BTN_COLOR_TXT_DEFAULT_DSBD       VfxColor(255, 87, 87, 87)
#define VCP_BTN_COLOR_TXT_DEFAULT_HLTD       VfxColor(255, 66, 66, 66)
#define VCP_BTN_COLOR_TXT_STYLE_DEFAULT_01   VFX_COLOR_BLACK
#define VCP_BTN_COLOR_TXT_STYLE_DEFAULT_02   VFX_COLOR_WHITE
#define VCP_BTN_COLOR_TXT_STYLE_RED          VFX_COLOR_WHITE
#define VCP_BTN_COLOR_TXT_STYLE_GREY         VFX_COLOR_WHITE
#define VCP_BTN_COLOR_TXT_STYLE_SIM1         VFX_COLOR_WHITE
#define VCP_BTN_COLOR_TXT_STYLE_SIM2         VFX_COLOR_WHITE
#define VCP_BTN_COLOR_TXT_STYLE_NORMAL       VFX_COLOR_WHITE
#endif


#if defined(__MMI_MAINLCD_480X800__)
static const VfxS32 VCP_BUTTON_SHADOW_MARGIN_RIGHT = 4;
static const VfxS32 VCP_BUTTON_SHADOW_MARGIN_BOTTOM = 4;
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
static const VfxS32 VCP_BUTTON_SHADOW_MARGIN_RIGHT = 2;
static const VfxS32 VCP_BUTTON_SHADOW_MARGIN_BOTTOM = 2;
#else // default 320X480
static const VfxS32 VCP_BUTTON_SHADOW_MARGIN_RIGHT = 2;
static const VfxS32 VCP_BUTTON_SHADOW_MARGIN_BOTTOM = 2;
#endif

/*****************************************************************************
 * Typedef
 *****************************************************************************/
class VfxTextFrame;
class VfxPenEvent;
class VfxWString;

/* DOM-NOT_FOR_SDK-END */

// <group DOM_Button_Macro&Enum_Enum>
// VcpButton image and text placement enum
enum VcpButtonPlacementEnum
{
    VCP_BUTTON_PLACEMENT_TEXT_ONLY,             // display the text only
    VCP_BUTTON_PLACEMENT_IMAGE_ONLY,            // display the image only
    VCP_BUTTON_PLACEMENT_IMAGE_LEFT,            // display the image at the left of the text
    VCP_BUTTON_PLACEMENT_IMAGE_RIGHT,           // display the image at the right of the text
    VCP_BUTTON_PLACEMENT_IMAGE_TOP,             // display the image at the top of the text
    VCP_BUTTON_PLACEMENT_IMAGE_BOTTOM,          // display the image at the bottom of the text
    VCP_BUTTON_PLACEMENT_OVERLAP,               // display the text over the image
    VCP_BUTTON_PLACEMENT_TEXT_ONLY_LEFT,        // display the text only, align left
    VCP_BUTTON_PLACEMENT_TEXT_LEFT_IMAGE_RIGHT, // display the text with left alignment, image with right alignment
    VCP_BUTTON_PLACEMENT_IMAGE_TEXT_CENTER, // display image, text on the center

    VCP_BUTTON_PLACEMENT_END_OF_ENUM            // end of the enum
};

// <group DOM_Button_Macro&Enum_Enum>
// VcpButton state enum
enum VcpButtonStyleEnum
{
    VCP_BUTTON_STYLE_DEFAULT,                               // default style -- changed to white color
    VCP_BUTTON_STYLE_DEFAULT_01 = VCP_BUTTON_STYLE_DEFAULT, // another name for the default style
    VCP_BUTTON_STYLE_DEFAULT_02,                            // second default style
    VCP_BUTTON_STYLE_RED,                                   // red style
    VCP_BUTTON_STYLE_GREY,                                  // grey style
    VCP_BUTTON_STYLE_SIM1,                                  // sim1 style
    VCP_BUTTON_STYLE_SIM2,                                  // sim2 style
    VCP_BUTTON_STYLE_NORMAL,                                // normal style -- deprecated

    VCP_BUTTON_STYLE_END_OF_ENUM                            // end of the enum
};

// <group DOM_Button_Macro&Enum_Enum>
// VcpButton state enum
enum VcpButtonStateEnum
{
    VCP_BUTTON_STATE_NORMAL,                    // normal state
    VCP_BUTTON_STATE_PRESSED,                   // pressed state

    VCP_BUTTON_STATE_END_OF_ENUM                // end of the enum
};


/*****************************************************************************
 * Class VcpButton
 *****************************************************************************/
class VcpButton : public VfxControl
{
    VFX_DECLARE_CLASS(VcpButton);

    // Constructor / Destructor
public:

    // <group DOM_Button_VcpButton_Constructor/Destructor>
    VcpButton();

    // Signal
public:
    // <group DOM_Button_VcpButton_Event>
    // This signal is invoked when the button is clicked
    // ex: connect to void YourClass::onButtonClicked(VfxObject* sender, VfxId Id)
    VfxSignal2 <VfxObject*, VfxId> m_signalClicked;

    // <group DOM_Button_VcpButton_Event>
    // This signal is invoked when the button state is changed
    // ex: connect to void YourClass::onButtonStateChanged(VfxObject* sender, VfxId Id, VcpButtonStateEnum state)
    VfxSignal3 <VfxObject*, VfxId, VcpButtonStateEnum> m_signalStateChanged;

    // Property
public:
    // <group DOM_Button_VcpButton_Property>
    // Set image list of the button
    void setImage(
        const VcpStateImage &imageList      // [IN] image list of the button
    );

    // <group DOM_Button_VcpButton_Property>
    // Get current image of the button
    const VfxImageSrc &getImage() const;

    
    // <group DOM_Button_VcpButton_Property>
    // Set text of the button
    virtual void setText(
        VfxResId resId               // [IN] text of the button
    );

    
    // <group DOM_Button_VcpButton_Property>
    // Set text of the button
    virtual void setText(
        const VfxWChar *mem               // [IN] text of the button
    );

    // <group DOM_Button_VcpButton_Property>
    // Set text of the button
    virtual void setText(
        const VfxWString &str               // [IN] text of the button
    );

    // <group DOM_Button_VcpButton_Property>
    // Get text of the button
    VfxWString getText() const;

    // <group DOM_Button_VcpButton_Property>
    // Highlight button
    void setIsHighlighted(
        VfxBool isHighlighted               // [IN] is highlighted
    );

    // <group DOM_Button_VcpButton_Property>
    // Get whether the button is highlighted
    // RETURNS: VfxBool, is highlighted
    VfxBool getIsHighlighted() const;
    
    // <group DOM_Button_VcpButton_Property>
    // Set button state
    virtual void setState(VcpButtonStateEnum newState);   

    // <group DOM_Button_VcpButton_Property>
    // Return button state
    VcpButtonStateEnum getState() const;

    // <group DOM_Button_VcpButton_Property>
    // Set the placement of the button
    virtual void setPlacement(
        VcpButtonPlacementEnum placement    // [IN] placement enum
    );

    // <group DOM_Button_VcpButton_Property>
    // Get the placement of the button
    VcpButtonPlacementEnum getPlacement() const;

    // <group DOM_Button_VcpButton_Property>
    // set ID
    void setId(
        VfxId id                            // [IN] ID
    );

    // <group DOM_Button_VcpButton_Property>
    // get ID
    VfxId getId() const;

    // <group DOM_Button_VcpButton_Property>
    // set inner rect
    void setInnerRect(const VfxRect & rect);

    // <group DOM_Button_VcpButton_Property>
    // get inner rect
    VfxRect getInnerRect();

    // <group DOM_Button_VcpButton_Property>
    // set the gap between text and image content
    void setTextImageGap(VfxS32 gap);

    // <group DOM_Button_VcpButton_Property>
    // get the gap between text and image content
    VfxS32 getTextImageGap();

    // Enable/Disable haptic touch feedback
    // Default: VFX_FALSE
    // <group DOM_Button_VcpButton_Property>
    void setIsHapticTouchEnabled(VfxBool state);

    // Get haptic touch feedback status (Enabled or disabled)    
    // <group DOM_Button_VcpButton_Property>
    VfxBool getIsHapticTouchEnabled();

    // Method
public:
    // <group DOM_Button_VcpButton_Method>
    // Get state image of the button
    const VcpStateImage & getStateImage() const;

    // <group DOM_Button_VcpButton_Method>
    // Auto resize button
    void setIsAutoResized(
        VfxBool isAutoResized,              // [IN] is auto-resized
        VfxS32 minWidth = 75,               // [IN] minimum width, 0 means don't care
        VfxS32 maxWidth = 0                 // [IN] maximum width, 0 means don't care
    );

    // <group DOM_Button_VcpButton_Method>
    // Get whether the button is auto-resized
    VfxBool getIsAutoResized() const;

    // <group DOM_Button_VcpButton_Method>
    // set font
    virtual void setTextFont(
        const VfxFontDesc &font             // [IN] text font
    );

    // <group DOM_Button_VcpButton_Method>
    // get font
    VfxFontDesc getTextFont();

    // <group DOM_Button_VcpButton_Method>
    // set font color for all types
    virtual void setTextColor(
        const VfxColor &color               // [IN] text color
    );

    // <group DOM_Button_VcpButton_Method>
    // set font color
    void setTextColor(
        const VfxColor &colorNormal,        // [IN] normal text color
        const VfxColor &colorPressed,       // [IN] pressed text color
        const VfxColor &colorDisabled,      // [IN] disabled text color
        const VfxColor &colorHighlgiht      // [IN] highlight text color
    );

    // <group DOM_Button_VcpButton_Method>
    // set font border color for all types
    void setTextBorderColor(
        const VfxColor &color               // [IN] text border color
    );

    // <group DOM_Button_VcpButton_Method>
    // set font border color
    void setTextBorderColor(
        const VfxColor &colorNormal,        // [IN] normal text border color
        const VfxColor &colorPressed,       // [IN] pressed text border color
        const VfxColor &colorDisabled,      // [IN] disabled text border color
        const VfxColor &colorHighlgiht      // [IN] highlight text border color
    );

    // <group DOM_Button_VcpButton_Method>
    // set the button style
    void setStyle(
        VcpButtonStyleEnum style
    );

    // <group DOM_Button_VcpButton_Method>
    // set back ground images list
    void setBgImageList (
        const VcpStateImage &imageList      // [IN] CP image list
    );

    // <group DOM_Button_VcpButton_Method>
    // set margin
    void setMargin(
        VfxS32 left,                        // [IN] left margin
        VfxS32 top,                         // [IN] top margin
        VfxS32 right,                       // [IN] right margin
        VfxS32 bottom                       // [IN] bottom margin
    );

    // <group DOM_Button_VcpButton_Method>
    // get margin
    void getMargin(
        VfxS32 &left,                       // [OUT] left margin
        VfxS32 &top,                        // [OUT] top margin
        VfxS32 &right,                      // [OUT] right margin
        VfxS32 &bottom                      // [OUT] bottom margin
    );

    // <group DOM_Button_VcpButton_Method>
    // force update all layout immediatelly
    void forceUpdate();

    // <group DOM_Button_VcpButton_Method>
    // get button text frame
    VfxTextFrame * getButtonTextFrame() const;

    // <group DOM_Button_VcpButton_Method>
    // get button image frame
    VfxFrame * getButtonImageFrame() const;

    // Override
public:
    // <group DOM_Button_VcpButton_Override>
    // Disable button
    virtual void setIsDisabled(
        VfxBool isDisabled                  // [IN] is disabled
    );

    // Override
protected:

    // <group DOM_Button_VcpButton_Override>
    // On init
    virtual void onInit();

    // <group DOM_Button_VcpButton_Override>
    // On pen input
    virtual VfxBool onPenInput(
        VfxPenEvent &event                  // [IN] pen event
    );

    virtual VfxBool onContainPoint(const VfxPoint &point) const;

    // <group DOM_Button_VcpButton_Override>
    // update the button display, including image or text position, etc.
    virtual void onUpdate();

    // <group DOM_Button_VcpButton_Implementation>
    // Hide item
    virtual void updateItem();

    // <group DOM_Button_VcpButton_Method>
    // timer callback for stay of PRESSED State
    void OnPressedStateTimerOut(
        VfxTimer *timer
    );
	
    // <group DOM_Button_VcpButton_Implementation>
    // get client area
    VfxRect getClientArea() const;
	
    // <group DOM_Button_VcpButton_Implementation>
    // Resize button
    virtual void resizeButton();

    // <group DOM_Button_VcpButton_Implementation>
    // Layout button
    virtual void layoutButton();

    // Implementation
private:
    // <group DOM_Button_VcpButton_Implementation>
    enum ButtonType
    {
        TYPE_NORMAL,        // normal type
        TYPE_PRESSED,       // pressed type
        TYPE_DISABLED,      // disabled type
        TYPE_HIGHLIGHT,     // hgighlight type
        END_OF_TYPE         // end of type
    };

protected:
        // <group DOM_Button_VcpButton_Implementation>
    // Button state
    VcpButtonStateEnum m_state;

    // <group DOM_Button_VcpButton_Implementation>
    // Placement of the button content
    VcpButtonPlacementEnum m_placement;

    // <group DOM_Button_VcpButton_Implementation>
    // text frame
    VfxTextFrame *m_frameText;
    // <group DOM_Button_VcpButton_Implementation>
    // Font
    VfxFontDesc m_font;

    // Text color
    VfxColor m_colorText[END_OF_TYPE];


    // <group DOM_Button_VcpButton_Implementation>
    // image list
    VcpStateImage m_iconImageList;

    // <group DOM_Button_VcpButton_Implementation>
    // image frame
    VfxFrame *m_frameImage;
    // <group DOM_Button_VcpButton_Implementation>
    // Image size;
    VfxSize m_sizeImage;

    // <group DOM_Button_VcpButton_Implementation>
    // Text size;
    VfxSize m_sizeText;

    // <group DOM_Button_VcpButton_Implementation>
    // Flag for text frame dirty;
    VfxBool m_textFrameDirty;  // Internal used.
	
    // <group DOM_Button_VcpButton_Implementation>
    // gap between text, image
    VfxS32 m_textImageGap;


private:
    // <group DOM_Button_VcpButton_Implementation>
    // Whether haptic touch is enabled
    VfxBool m_isHapticTouchEnabled;

    // <group DOM_Button_VcpButton_Implementation>
    // Whether button is highlighted
    VfxBool m_isHighlighted;

    // <group DOM_Button_VcpButton_Implementation>
    // Whether button is AutoResized
    VfxBool m_isAutoResized;

    // <group DOM_Button_VcpButton_Implementation>
    // button style
    VcpButtonStyleEnum m_style;

    // <group DOM_Button_VcpButton_Implementation>
    // ID
    VfxU32 m_id;

    // Text border color
    VfxColor m_colorTextBorder[END_OF_TYPE];

    // <group DOM_Button_VcpButton_Implementation>
    // minimum width
    VfxS32 m_minWidth;

    // <group DOM_Button_VcpButton_Implementation>
    // maximum width
    VfxS32 m_maxWidth;

    // <group DOM_Button_VcpButton_Implementation>
    // image list for background image
    VcpStateImage m_bgImageList;

    // <group DOM_Button_VcpButton_Implementation>
    // boundary of client area
    VfxRect m_boundary;


    // Implementation
private:
    // <group DOM_Button_VcpButton_Implementation>
    // reset button state
    void resetButtonState();

    // <group DOM_Button_VcpButton_Implementation>
    // Update button while bounds change
    void onBoundsChanged(VfxFrame *frame, const VfxRect &old);

    void onAfterClick();

    VfxTimer *m_timer;

};



/*****************************************************************************
 * Class VcpScrollingTextButton
 * A button with text that can scroll
 *****************************************************************************/
class VcpScrollingTextButton : public VcpButton
{
public:
    // <group DOM_Button_VcpScrollingTextButton_Constructor/Destructor>
    VcpScrollingTextButton();

protected:
    VcpMarquee *m_scrollingText;
    VfxBool m_scrollOnHighlight;

protected:

    virtual void onInit();
        // <group DOM_Button_VcpButton_Implementation>
    // Hide item
    virtual void updateItem();

    // <group DOM_Button_VcpButton_Override>
    // update the button display, including image or text position, etc.
    virtual void onUpdate();

public:
    // <group DOM_Button_VcpScrollingTextButton_Property>
    // Set text of the button
    virtual void setText(
        VfxResId resId               // [IN] text of the button
    );

    
    // <group DOM_Button_VcpScrollingTextButton_Property>
    // Set text of the button
    virtual void setText(
        const VfxWChar *mem               // [IN] text of the button
    );

    // <group DOM_Button_VcpScrollingTextButton_Property>
    // Set text of the button
    virtual void setText(
        const VfxWString &str               // [IN] text of the button
    );

    // <group DOM_Button_VcpScrollingTextButton_Property>
    // Set the placement of the button
    virtual void setPlacement(
        VcpButtonPlacementEnum placement    // [IN] placement enum
    );

    // <group DOM_Button_VcpScrollingTextButton_Method>
    // set font
    virtual void setTextFont(
        const VfxFontDesc &font             // [IN] text font
    );

    // <group DOM_Button__VcpScrollingTextButton_Method>
    // set font color for all types
    virtual void setTextColor(
        const VfxColor &color               // [IN] text color
    );

    // <group DOM_Button__VcpScrollingTextButton_Method>
    // set font color
    virtual void setTextColor(
        const VfxColor &colorNormal,        // [IN] normal text color
        const VfxColor &colorPressed,       // [IN] pressed text color
        const VfxColor &colorDisabled,      // [IN] disabled text color
        const VfxColor &colorHighlgiht      // [IN] highlight text color
    );

    void setScrollOnHighlight(VfxBool state);

    VfxBool getScrollOnHighlight();

};


#endif /* __VCP_BUTTON_H__ */

