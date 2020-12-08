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
 *  vcp_vk.h
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  Virtual keyboard class header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_VK_H__
#define __VCP_VK_H__

/***************************************************************************** 
* Include
*****************************************************************************/
extern "C"
{
#include "MMI_features.h"
}
#if  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)

/*Do the common part here*/
#include "vfx_uc_include.h"
class VcpVKAllowedDisabledCharBtn : public VfxBase
{
public:
    VfxBool isDisabled;                     // whether is disabled buttons
    // VFX_TRUE: disabled buttons. VFX_FLASE: allowed buttons
    VfxWString string;                      // the character buttons which are disabled or allowed
};

#if  defined  __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
extern "C"
{
#include "gui_virtual_keyboard_language_type.h"
#include "wgui_virtual_keyboard.h"
}

//#include "vfx_uc_include.h"

/***************************************************************************** 
* Defination
*****************************************************************************/
// the string name of VcpVK
#define VCP_VK_CLASS_NAME             "VirtualKeyboard"

// the max number of function button which is disabled
#define VCP_VK_MAX_DISABLED_FUNC_BUTTON         20


/***************************************************************************** 
* Typedef
*****************************************************************************/
// <group DOM_VirtualKeyboard_Typedef>
// VK type/language
typedef gui_virtual_keyboard_language_enum VcpVKTypeEnum;

// <group DOM_VirtualKeyboard_Typedef>
// VK attribute
typedef VfxU32 VcpVKAttr;

// <group DOM_VirtualKeyboard_Typedef>
// The enum of function button in VK
typedef gui_virtual_keyboard_pen_enum VcpVKFuncBtnEnum;

// <group DOM_VirtualKeyboard_Typedef>
// The struct to record the layout of virtual keyboard
typedef wgui_virtual_keyboard_layout_struct VcpVKLayoutStruct;


/***************************************************************************** 
* Enum
*****************************************************************************/
// <group DOM_VirtualKeyboard_Enum>
// The type of button in virtual keyboard
enum VcpVKBtnTypeEnum
{
    VCP_VK_BUTTON_TYPE_CHAR = 0,        // the button is character button
    VCP_VK_BUTTON_TYPE_FUNC,            // the button is function button
    VCP_VK_BUTTON_TYPE_STRING, //the button is stering button
    VCP_VK_BUTTON_TYPE_MAX
};

// <group DOM_VirtualKeyboard_Enum>
// the state of button in virtual keyboard
enum VcpVKBtnStateEnum
{
    VCP_VK_BUTTON_STATE_NORMAL = 0,     // the button is in normal state
    VCP_VK_BUTTON_STATE_HILITE,         // the button is in highlight state
    VCP_VK_BUTTON_STATE_DISABLED,       // the button is in disable state
    VCP_VK_BUTTON_STATE_POPUP,          // the button is in popup state
    VCP_VK_BUTTON_STATE_MAX
};

// <group DOM_VirtualKeyboard_Enum>
// the image of button is foreground or background image
enum VcpVKBtnImgPosEnum
{
    VCP_VK_BUTTON_IMG_POS_FG = 0,       // the image of button is foreground image
    VCP_VK_BUTTON_IMG_POS_BG,           // the image of button is background image
    VCP_VK_BUTTON_IMG_POS_MAX
};



class VcpVKBtnInfo : public VfxBase
{
public:
    VfxU32 buttonContent;                   // the button to be set. 
    // Unicode code for character button or VcpVKFuncBtnEnum value for function button
    VcpVKBtnStateEnum state;                // the state of button to be set
    VcpVKBtnImgPosEnum pos;                 // the foreground or background image to be set
};



// <group DOM_VirtualKeyboard_Struct/Class>
// the buttons that are disabled or allowed


// <group DOM_VirtualKeyboard_Struct/Class>
// the node of linked list of button of virtual keyboard
class VcpVKBtn : public VfxBase
{
public:
    VfxRect rect;                           // the rectangle of button
    VfxU16 index;                           // the index of button in information array
    VfxBool isAllowed;                      // whether is allowed buttons
    // VFX_FALSE: disabled button. VFX_TRUE: allowed button
    VcpVKBtn *next;                         // the next node of linked list
};




/***************************************************************************** 
* Typedef
*****************************************************************************/

class VcpVkRenderer : public VfxBase
{

    // Constructor / Destructor   
public:
  VfxU32  m_fontsize;
  VfxU32 m_fontcolor;
  VfxU32 m_fontcolorAux;
  VfxU32 m_fontsizeAux;
   


    void renderButton( 
        VfxDrawContext &dc,
        VfxRect rect,
        VfxImageSrc bgImage,
        const VfxWString  label,
        VfxU32 fontcolor,
        VfxU32 fontsize,
        VfxRect fontloc,
		VfxS32 labelBaseLine);




    void renderButton( 
        VfxDrawContext &dc,
        VfxRect rect,
        VfxImageSrc bgImage,
        const VfxWString  label,
        VfxU32 fontcolor,
        VfxU32 fontsize,
        VfxRect fontloc,
        const VfxWString  labelAux,
        VfxU32 fontcolorAux,
        VfxU32 fontsizeAux,
        VfxRect fontlocAux,
		VfxS32 labelBaseLine,
		VfxS32 labelAuxBaseLine);
};

/***************************************************************************** 
* Class VcpVKLayoutAdp
*****************************************************************************/

/*
* DESCRIPTION
*  VcpVKLayoutAdp is an adaptor for VcpVK to get the information generated by the
*  tool of MCT
*/
class VcpVKLayoutAdp
{
    // Constructor / Destructor
public:

    // Method    
public:
    VfxBool setup(VfxU32 index);
    void setActiveRow(VfxU32 rowid);

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the image id of background of virtual keyboard
    // RETURNS: The image id of background of virtual keyboard
    VfxResId getBgImage();

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Check whether current virtual keyboard is alphanumeric
    // RETURNS: VFX_FALSE: current virtual keyboard is not alphanumeric
    //          VFX_TRUE: current virtual keyboard is alphanumeric
    VfxBool checkAlphanumeric();

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Setup the virtual keyboard according to the resolution, type and attribute
    // Return: VFX_TRUE: successful; VFX_FALSE: error
    VfxBool setup(
        VcpVKTypeEnum type,         // [IN] the type of virtual keyboard
        VcpVKAttr attr              // [IN] the attribute of virtual keyboard
        );

    VfxU32 getMarginWidth(VfxU32 index);
    VfxU32 getMarginHeight(VfxU32 index);

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the count of buttons in current virtual keyboard
    // RETURNS: The count of buttons in current virtual keyboard
    VfxU16 getButtonCount();

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the type of button in current virtual keyboard
    // RETURNS: VFX_TRUE: normal button; VFX_FALSE: popup or longtap hint button
    VfxBool checkButtonIsNormal(
        VfxU16 index                // [IN] the index of button
        );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the content of button in current virtual keyboard
    // RETURNS: the content of button in current virtual keyboard
    VfxU32 getButtonContent(
        VfxU16 index , // [IN] the index of button
        mmi_pen_event_type_enum pen_event
        );
     VfxU32 getButtonContentpointer(VfxU16 index  , mmi_pen_event_type_enum pen_event              // [IN] the index of button
        );
    VfxU32 getButtonContenttype(VfxU16 index , mmi_pen_event_type_enum pen_event);


	    VfxU32 getButtonContent(
        VfxU16 index  // [IN] the index of button
        );
    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the rectangle of button in current virtual keyboard
    void getButtonRect(
        VfxU16 index,               // [IN] the index of button
        VfxS32 *x,                  // [OUT] the x coordinate
        VfxS32 *y,                  // [OUT] the y coordinate
        VfxS32 *width,              // [OUT] the width
        VfxS32 *height  ,            // [OUT] the height
		VcpVKBtnStateEnum flag
        );


    VfxRect getButtonRect(VfxU16 index);
    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the size of current virtual keyboard
    void getSize(
        VfxS32 *width,              // [OUT] the width
        VfxS32 *height              // [OUT] the height
        );


    VfxBool isRotated();


    VfxBool isShiftEnable();



    VfxBool isCached();

    gui_virtual_keyboard_key_state_enum getButtonType(VcpVKBtnStateEnum type);


    VfxResId getButtonBgImage(VfxU16 index,VcpVKBtnStateEnum flag  );

    VfxRect getButtonLabelRect(VfxU16 index ,VcpVKBtnStateEnum flag  );
    VfxRect getButtonLabelRectAux(VfxU16 index,VcpVKBtnStateEnum flag );
	VfxS32 getLabelBaseline(void);
	VfxS32 getLabelAuxBaseline(void);
    VfxRect getButtonIconRect(VfxU16 index,VcpVKBtnStateEnum flag  );
    VfxRect getButtonIconRectAux(VfxU16 index,VcpVKBtnStateEnum flag  );
    VfxWString getButtonLabel(VfxU16 index,VcpVKBtnStateEnum flag  );
    VfxWString getButtonLabelAux(VfxU16 index,VcpVKBtnStateEnum flag  );

    VfxResId getButtonIcon(VfxU16 index,VcpVKBtnStateEnum flag );
    VfxU32 getButtonLabelColor(VfxU16 index,VcpVKBtnStateEnum flag  );
    VfxU32 getButtonIconColor(VfxU16 index,VcpVKBtnStateEnum flag  );
    VfxU32 getButtonLabelFontSize(VfxU16 index,VcpVKBtnStateEnum flag  );


    VfxResId getButtonIconAux(VfxU16 index,VcpVKBtnStateEnum flag );
    VfxU32 getButtonLabelColorAux(VfxU16 index,VcpVKBtnStateEnum flag  );
    VfxU32 getButtonIconColorAux(VfxU16 index,VcpVKBtnStateEnum flag  );
    VfxU32 getButtonLabelFontSizeAux(VfxU16 index,VcpVKBtnStateEnum flag  );
    void getPopupButtonRatio(VfxU16 index  , VfxU32* height , VfxU32* width );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // check whether the button has popup hint
    // RETURNS: VFX_FALSE, there is no popup hint; VFX_TRUE, there is popup hint
    VfxBool checkButtonPopupExist(
        VfxU16 index                // [IN] the index of button
        );
    VfxBool checkLongtapPopupExist( U32 index);


    // Variable
private:
    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Constructor/Destructor>
    // record the current virtual keyboard layout
	VfxS32 labelBaseLine ;
	VfxS32 labelAuxBaseLine ;
};

/***************************************************************************** 
* Class VcpVKHiliteFrame
*****************************************************************************/

/*
* DESCRIPTION
*  VcpVKHiliteFrame show the background and foreground images. 
*  It has only one member variable: m_fgFrame (is a VfxImageFrame).
*  This member variable is child (frame tree) of VcpVKHiliteFrame.
*  VcpVKHiliteFrame shows the background image by itself. The m_fgFrame shows the foreground image.
*  It is used to show the popup hint and highlight state of button.
*/
class VcpVKHiliteFrame : public VfxFrame
{
    // Method    
public:
   
    // Change the background and foreground frame to the last one of parent's child frame.
    void bringToFront();

    // Override
public:
    // <group DOM_VirtualKeyboard_VcpVKHiliteFrame_Override>
    virtual void setPos(const VfxPoint &value);

    // Only avoid the target build error
    void setPos(
        VfxS32 x,                   // [IN] The x coordinate to set
        VfxS32 y                    // [IN] The y coordinate to set
        )
    {
        setPos(VfxPoint(x, y));
    }

 
    void setcurrbutton(const VcpVKBtn* button)
    {
        m_currButton = button;
    }

    // <group DOM_VirtualKeyboard_VcpVKHiliteFrame_Override>
    virtual void setBounds(const VfxRect &value);

    // <group DOM_VirtualKeyboard_VcpVKHiliteFrame_Override>
    virtual void setHidden(VfxBool value);

    // <group DOM_VirtualKeyboard_VcpVKHiliteFrame_Override>
    virtual void setPosZ(VfxFloat value);

    // <group DOM_VirtualKeyboard_VcpVKHiliteFrame_Override>
    virtual void setOpacity(VfxFloat value);

protected:
    // <group DOM_VirtualKeyboard_VcpVKHiliteFrame_Override>
    virtual void onInit();

    // <group DOM_VirtualKeyboard_VcpVKHiliteFrame_Override>
    virtual void onDeinit();

    // Variable
protected:
   
    VcpVkRenderer m_renderer;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the adptor to get the information generated by MCT
    VcpVKLayoutAdp m_adaptor;

    const VcpVKBtn *m_currButton;


};


class VcpVKHilite :public VcpVKHiliteFrame
{
public :
    virtual void onDraw(VfxDrawContext &dc);
    void drawButton(VfxDrawContext &dc, const VcpVKBtn *button , VcpVKBtnStateEnum flag  );
};


class VcpVKPopup :public VcpVKHiliteFrame
{
public:
    virtual void onDraw(VfxDrawContext &dc);
    void drawButton(VfxDrawContext &dc, const VcpVKBtn *button , VcpVKBtnStateEnum flag  );
};

/***************************************************************************** 
* Class VcpVK
*****************************************************************************/

/*
* DESCRIPTION
*  VcpVK manages the show of Venus virtual keyboard and notify outside when one button is pressed,
*  up, long tape, abort and move to another button. VcpVK get the layout and other information of
*  VK generated by MCT internally.
*

*/
class VcpVKLongtapHintEvt : public VfxBase
{
public:
    VfxPenEventTypeEnum type;               // pen event type
    VfxPoint pos;                           // the position where pen event happened and bases on the coordinate of VcpVKLongtapHint
};



class VcpVK : public VfxControl
{
    VFX_DECLARE_CLASS(VcpVK);

    // Constructor / Destructor
public:
    // <group DOM_VirtualKeyboard_VcpVK_Constructor/Destructor>
    VcpVK();


    VcpVK(VcpVKTypeEnum type, VcpVKAttr attr) ;

    VfxU32   getCurrButtonIndex();

    void setActiveRow(VfxU32 rowid);


    // Method
public:

    VcpVKLongtapHintEvt m_eventformini ;


    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // set the type of virtual keyboard
    void setType(
        VcpVKTypeEnum type      // [IN] the type to be set
        );






    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // set the attribute of virtual keyboard
    void setAttr(
        VcpVKAttr attr          // [IN] the attribute to be set
        );

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // get the type of virtual keyboard
    VcpVKTypeEnum getType()
    {
        return m_type;
    }

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // get the attribute of virtual keyboard
    VcpVKAttr getAttr()
    {
        return m_attr;
    }

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // rotate the virtual keyboard
    void rotate();
    

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // Set the allowed character buttons in VK. All the missed character buttons are disabled.
    // Note: Take care of the relationship with setDisabledCharButtons(). Only one can be called.
    // Note: The setting won't be resetted by changing type/attribure of virtual keyboard and rotating virtual keyboard 
    void setAllowedCharButtons(
        const VfxWString &allowedButtons        // [IN] Allowed character buttons in VK
        );

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // Set the disabled character buttons in VK. All the missed character buttons are enabled.
    // Note: Take care of the relationship with setAllowedCharButtons(). Only one can be called.
    // Note: The setting won't be resetted by changing type/attribure of virtual keyboard and rotating virtual keyboard 
    void setDisabledCharButtons(
        const VfxWString &disabledButtons       // [IN] Disabled character buttons in VK
        );

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // Reset the character buttons to default state (all buttons are allowed)
    void resetCharButtons();

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // Set the disabled function buttons in VK. All the missed buttons are enabled.
    // Note: Default, all function buttons are enabled.
    // Note: The setting won't be resetted by changing type/attribure of virtual keyboard and rotating virtual keyboard 
    void setDisabledFuncButtons(
        const VcpVKFuncBtnEnum *disabledButtons // [IN] Disabled function buttons in VK. End by GUI_VKBD_PEN_NONE
        // Note: only the first VCP_VK_MAX_DISABLED_FUNC_BUTTON buttons are valid.
        );
    VfxPoint Calculatefontloc(const VcpVKBtn *button , VfxU32 loc_biasx, VfxU32 loc_bias_y );

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // Reset the function buttons to default state (all buttons are allowed)
    void resetFuncButtons();





    // Override
public:
    // <group DOM_VirtualKeyboard_VcpVK_Override>
    virtual void setPos(const VfxPoint &value);

    // <group DOM_VirtualKeyboard_VcpVK_Override>
    virtual void setPosZ(VfxFloat value);

    // Only avoid the target build error
    void setPos(
        VfxS32 x,                   // [IN] The x coordinate to set
        VfxS32 y                    // [IN] The y coordinate to set
        )
    {
        setPos(VfxPoint(x, y));
    }

    // Signal
public:
   
    // <group DOM_VirtualKeyboard_VcpVK_Signal>
    // notify that the pen is down on one button, and the parameter is the button
    // If the 2nd is VKBtnTypeChar, it represents the event happened in character button
    // and the 3rd parameter is the Unicode of character. If the 2nd parameter is VKBtnTypeFunc,
    // It represents the event happened in function button and the 3rd parameter is the enum value of
    // this function button (VcpVKFuncBtnEnum).
    VfxSignal3 <
        VfxObject*,                     // sender
        VcpVKBtnTypeEnum,               // the type of button
        VfxU32                          // Unicode of character button or the event of function button
    > m_signalButtonDown;



    VfxSignal3 <
        VfxObject*,                     // sender
        VcpVKBtnTypeEnum,               // the type of button
        VfxU32                          // Unicode of character button or the event of function button
    > m_signalButtonRepeat;


    // <group DOM_VirtualKeyboard_VcpVK_Signal>
    // notify that the pen is longtap on one button
    // the parameter is the button on which pen is longtap
    VfxSignal3 <
        VfxObject*,                     // sender
        VcpVKBtnTypeEnum,               // the type of button
        VfxU32//,                   // Unicode of character button or the event of function button
        //VfxU32
    > m_signalButtonLongtap;

    VfxSignal3 <
        VfxObject*,                     // sender
        VcpVKBtnTypeEnum,               // the type of button
        VfxU32                          // Unicode of character button or the event of function button
        >m_signalButtonLongtapTimeUp;

    VfxSignal3 <
        VfxObject*,                     // sender
        VcpVKBtnTypeEnum,               // the type of button
        VfxU32                          // Unicode of character button or the event of function button
        >m_signalButtonrepeatTimeUp;



    VfxSignal3 <
        VfxObject*,                     // sender
        VcpVKBtnTypeEnum,               // the type of button
        VfxU32 
    > m_signalButtonMove;

    // <group DOM_VirtualKeyboard_VcpVK_Signal>
    // notify that the pen is up on one button
    // the parameter is the button on which pen is up
    VfxSignal3 <
        VfxObject*,                     // sender
        VcpVKBtnTypeEnum,               // the type of button
        VfxU32                          // Unicode of character button or the event of function button
    > m_signalButtonUp;

    // <group DOM_VirtualKeyboard_VcpVK_Signal>
    // notify that the pen is abort
    // the parameters is the last button encountered
    VfxSignal3 <
        VfxObject*,                     // sender
        VcpVKBtnTypeEnum,               // the type of button
        VfxU32                          // Unicode of character button or the event of function button
    > m_signalButtonAbort;


VfxSignal2 <
        VfxObject*,                     // sender
        VcpVKLongtapHintEvt &               // the type of button
    > m_signalEventLongtap;

    // Override
protected:
    // <group DOM_VirtualKeyboard_VcpVK_Override>
    virtual void onInit();

    // <group DOM_VirtualKeyboard_VcpVK_Override>
    virtual void onDeinit();

    // <group DOM_VirtualKeyboard_VcpVK_Override>
    virtual void onDraw(
        VfxDrawContext &dc
        );

    // <group DOM_VirtualKeyboard_VcpVK_Override>

    // <group DOM_VirtualKeyboard_VcpVK_Override>
    virtual void onUpdate();

    // Implementation
//private:
    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // check whether the button is allowed
    // RETURNS: VFX_TRUE, the button is allowed. VFX_FALSE, the button is disabled
    VfxBool checkButtonIsAllowed(
        VfxU32 content                  // [IN] the content of button to check
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // draw one button
    public:
    void drawButton(
        VfxDrawContext &dc,             // [IN] the object of VfxDrawContext for drawing
        const VcpVKBtn *button          // [IN] the button to draw
        );

    void drawButton(VfxDrawContext &dc, const VcpVKBtn *button , VcpVKBtnStateEnum flag);

protected:



    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // get the button in which the point is
    // RETURNS: If point is in active button, return the node in linked list of button; else, return NULL
    const VcpVKBtn *getButtonByPointStrict(
        const VfxPoint &point                   // [IN] the point
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // get the button in which the point is nearist
    // RETURNS: If point is in active button, return the node in linked list of button; else, return NULL
    const VcpVKBtn *getButtonByPoint(
        const VfxPoint &point                   // [IN] the point
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // emit the signal of down on button
    void emitDownSignal(
        const VcpVKBtn *button                  // [IN] the button where signal happened
        );

    void emitRepeatSignal(
        const VcpVKBtn *button                  // [IN] the button where signal happened
        );


void emitLongtapEventSignal(VcpVKLongtapHintEvt &event);

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // emit the signal of longtap on button
    void emitLongtapSignal(
        const VcpVKBtn *button                  // [IN] the button where signal happened
        );
    void emitLongtapTimeUpSignal(
        const VcpVKBtn *button                  // [IN] the button where signal happened
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // emit the signal of move on button
    void emitMoveSignal(
        const VcpVKBtn *button   //   ,VfxPenEvent& forMini            // [IN] the button where signal happened
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // emit the signal of up on button
    void emitUpSignal(
        const VcpVKBtn *button                  // [IN] the button where signal happened
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // emit the signal of abort on button
    void emitAbortSignal(
        const VcpVKBtn *button                  // [IN] the button where signal happened
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // the slot of the timer to check longtap
    void longtapTimeup(
        VfxTimer *timerFunc                     // [IN] the timer to check longtap
        );

    void repeatTimeup(
        VfxTimer *timerFunc                     // [IN] the timer to check longtap
        );


    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // set the highlight frame to be the button as parameter
    void setHiliteButton(
        const VcpVKBtn *button                  // [IN] the button to draw highlight state
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // set the popup hint frame of the button as parameter
    void setPopupHintFrame(
        const VcpVKBtn *button                  // [IN] the button to show popup hint
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // check whether the button has popup hint
    // RETURNS: VFX_TRUE, has popup hint. VFX_FALSE, has no popup hint
    VfxBool checkPopupExist(
        const VcpVKBtn *button                  // [IN] the button to check
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // check whether the button has longtap hint
    // RETURNS: VFX_TRUE, has longtap hint. VFX_FALSE, has no longtap hint
    VfxBool checklongtapExist(
        const VcpVKBtn *button                  // [IN] the button to check
        );

    /* performance check*/
       // <group DOM_VirtualKeyboard_VcpVK_Variable>
       // the type of virtual keyboard
       VcpVKTypeEnum m_type;
    
       // <group DOM_VirtualKeyboard_VcpVK_Variable>
       // the attribute of virtual keyboard
       VcpVKAttr m_attr;


    // Variable
//private:

    VfxBool m_inLongtapHintState;

   

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the character buttons which are disabled or allowed
    //VcpVKAllowedDisabledCharBtn m_disabledAllowedCharBtns;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the function buttons which are disabled
    VcpVKFuncBtnEnum m_disabledFuncBtn[VCP_VK_MAX_DISABLED_FUNC_BUTTON + 1];

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the buttons
    VcpVKBtn *m_buttonList;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the current selected button
    const VcpVKBtn *m_currButton;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the frame to show the highlight state of button
    VcpVKHilite* m_hiliteFrame;


    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the frame to show the popup hint of button
    VcpVKPopup* m_popupHintFrame;


    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the timer to check longtap
    VfxTimer *m_longtapTimer;

    VfxTimer *m_repeatTimer;


    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // whether current state is ready for entering longtap hint state
    VfxBool m_readyForLongtap;
    VcpVkRenderer m_renderer;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the adptor to get the information generated by MCT
    VcpVKLayoutAdp m_adaptor;
    // VcpVKButton   m_hilight_button;    
    // VcpVKButton   m_popup_button;

};

class VcpVKMini : public VcpVK
{
 public :
    void setCurrButtonIndex(VfxU32 index);
    virtual VfxBool onPenInput(VcpVKLongtapHintEvt &event);
    VfxBool checkPopupExist(const VcpVKBtn *button);
    VfxBool setDataSource();
    VfxU32   setCurrButtonIndex();
    virtual void onDraw(VfxDrawContext &dc);
    virtual void onUpdate();
    virtual void onInit();
	VfxPoint getCurrButtonRectMini(VfxU32 index);
private:
     VfxU32  m_currIndex;

};


class VcpVKMain : public VcpVK
{
     public :

    virtual VfxBool onPenInput(VfxPenEvent &event);
    VfxBool checkPopupExist(const VcpVKBtn *button);
    VfxBool setDataSource();
    virtual void onDraw(VfxDrawContext &dc);
    virtual void onUpdate();
	VfxRect getCurrButtonRectMain(void);

};




#elif defined  __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__


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
 *  vcp_vk.h
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  Virtual keyboard class header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/***************************************************************************** 
 * Include
 *****************************************************************************/

extern "C"
{
    #include "gui_virtual_keyboard_language_type.h"
    #include "wgui_virtual_keyboard.h"
}

//#include "vfx_uc_include.h"

/***************************************************************************** 
 * Defination
 *****************************************************************************/
// the string name of VcpVK
#define VCP_VK_CLASS_NAME             "VirtualKeyboard"

// the max number of function button which is disabled
#define VCP_VK_MAX_DISABLED_FUNC_BUTTON         20

// the max number of buttons in longtap hint
#define VCP_VK_LONGTAP_BUTTON_MAX               10


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
// <group DOM_VirtualKeyboard_Typedef>
// VK type/language
typedef gui_virtual_keyboard_language_enum VcpVKTypeEnum;

// <group DOM_VirtualKeyboard_Typedef>
// VK attribute
typedef VfxU32 VcpVKAttr;

// <group DOM_VirtualKeyboard_Typedef>
// The enum of function button in VK
typedef gui_virtual_keyboard_pen_enum VcpVKFuncBtnEnum;

// <group DOM_VirtualKeyboard_Typedef>
// The struct to record the layout of virtual keyboard
typedef wgui_virtual_keyboard_layout_struct VcpVKLayoutStruct;


/***************************************************************************** 
 * Enum
 *****************************************************************************/
// <group DOM_VirtualKeyboard_Enum>
// The type of button in virtual keyboard
enum VcpVKBtnTypeEnum
{
    VCP_VK_BUTTON_TYPE_CHAR = 0,        // the button is character button
    VCP_VK_BUTTON_TYPE_FUNC,            // the button is function button
    VCP_VK_BUTTON_TYPE_MAX
};

// <group DOM_VirtualKeyboard_Enum>
// the state of button in virtual keyboard
enum VcpVKBtnStateEnum
{
    VCP_VK_BUTTON_STATE_NORMAL = 0,     // the button is in normal state
    VCP_VK_BUTTON_STATE_HILITE,         // the button is in highlight state
    VCP_VK_BUTTON_STATE_DISABLED,       // the button is in disable state
    VCP_VK_BUTTON_STATE_POPUP,          // the button is in popup state
    VCP_VK_BUTTON_STATE_MAX
};

// <group DOM_VirtualKeyboard_Enum>
// the image of button is foreground or background image
enum VcpVKBtnImgPosEnum
{
    VCP_VK_BUTTON_IMG_POS_FG = 0,       // the image of button is foreground image
    VCP_VK_BUTTON_IMG_POS_BG,           // the image of button is background image
    VCP_VK_BUTTON_IMG_POS_MAX
};


/***************************************************************************** 
 * Struct / Class
 *****************************************************************************/
// <group DOM_VirtualKeyboard_Struct/Class>
// the button information used in longtap hint
class VcpVKLongtapHintBtn : public VfxBase
{
public:
    VfxU32 content;                         // the content of button
    VfxImageSrc fgImg;                      // the foreground image when button is in normal state
    VfxImageSrc fgHighlightImg;             // the foreground image when button is in highlight state
    VfxImageSrc bgImg;                      // the background image when button is in normal state
    VfxImageSrc bgHighlightImg;             // the background image when button is in highlight state
    VfxU16 width;                           // the width of button
    VfxU16 height;                          // the height of button
};

// <group DOM_VirtualKeyboard_Struct/Class>
// the struct used in constructor of VcpVKLongtapHint for buttons information
class VcpVKLongtapInfo : public VfxBase
{
public:
    VfxImageSrc bgImg;                                                      // the image of background of longtap hint
    VfxS32 maxWidth;                                                        // the max width of rectangle of the longtap hint
    VcpVKLongtapHintBtn buttonArray[VCP_VK_LONGTAP_BUTTON_MAX];             // the array of buttons that will show in longtap hint
    VfxU16 buttonCount;                                                     // the count of buttons that will show in longtap hint
    VfxBool isR2L;                                                          // whether the button is placed from right to left
                                                                            // VFX_TRUE: from right to left. VFX_FLASE: left to right
};

// <group DOM_VirtualKeyboard_Struct/Class>
// the struct used in processPenEvent() of VcpVKLongtapHint
class VcpVKLongtapHintEvt : public VfxBase
{
public:
    VfxPenEventTypeEnum type;               // pen event type
    VfxPoint pos;                           // the position where pen event happened and bases on the coordinate of VcpVKLongtapHint
};

// <group DOM_VirtualKeyboard_Struct/Class>
// the struct used in display callback function to get the information of virtual keyboard button
class VcpVKBtnInfo : public VfxBase
{
public:
    VfxU32 buttonContent;                   // the button to be set. 
                                            // Unicode code for character button or VcpVKFuncBtnEnum value for function button
    VcpVKBtnStateEnum state;                // the state of button to be set
    VcpVKBtnImgPosEnum pos;                 // the foreground or background image to be set
};


// <group DOM_VirtualKeyboard_Struct/Class>
// the struct is the parameter of display callback function
class VcpVKDisplayCbPara : public VfxBase
{
public:
    VcpVKBtnInfo buttonInfo;                // the information of button
    VfxImageSrc image;                      // the image got
};


// <group DOM_VirtualKeyboard_Struct/Class>
// the node of linked list of longtap hint button
class VcpVKLongTapBtn : public VfxBase
{
public:
    VfxRect rect;                           // the rectangle of button
    VfxU16 index;                           // the index of button in information array
    VcpVKLongTapBtn *next;                  // the next node of linked list
};


// <group DOM_VirtualKeyboard_Struct/Class>
// the buttons that are disabled or allowed


// <group DOM_VirtualKeyboard_Struct/Class>
// the node of linked list of button of virtual keyboard
class VcpVKBtn : public VfxBase
{
public:
    VfxRect rect;                           // the rectangle of button
    VfxU16 index;                           // the index of button in information array
    VfxBool isAllowed;                      // whether is allowed buttons
                                            // VFX_FALSE: disabled button. VFX_TRUE: allowed button
    VcpVKBtn *next;                         // the next node of linked list
};


// <group DOM_VirtualKeyboard_Struct/Class>
// the image information of one button
class VcpVKBtnImg : public VfxBase
{
public:
    VfxU32 content;                         // the content of button
    VfxImageSrc fgImg;                      // the foreground image when button is in normal state
    VfxImageSrc fgDisabledImg;              // the foreground image when button is in disabled state
    VfxImageSrc fgHighlightImg;             // the foreground image when button is in highlight state
    VfxImageSrc fgPopupImg;                 // the foreground image of popup of this button
    VfxImageSrc bgImg;                      // the background image when button is in normal state
    VfxImageSrc bgDisabledImg;              // the background image when button is in disabled state
    VfxImageSrc bgHighlightImg;             // the background image when button is in highlight state
    VfxImageSrc bgPopupImg;                 // the background image of popup of this button
};


// <group DOM_VirtualKeyboard_Struct/Class>
// the image information of one button in linked list
class VcpVKBtnImgNode : public VfxBase
{
public:
    VcpVKBtnImg imgInfo;              // the information of the image id of button
    VcpVKBtnImgNode *next;            // next node
};


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
// <group DOM_VirtualKeyboard_Typedef>
// the type for display callback function
typedef void (VfxObject::*VcpVKDisplayCB) (VcpVKDisplayCbPara&);

// <group DOM_VirtualKeyboard_Typedef>
// the type for multi-popup callback function
typedef VfxBool (VfxObject::*VcpVKMultiPopupCB) (VfxU32, VfxU32*);



/***************************************************************************** 
 * Class VcpVKLayoutAdp
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VcpVKLayoutAdp is an adaptor for VcpVK to get the information generated by the
 *  tool of MCT
 */
class VcpVKLayoutAdp
{
// Constructor / Destructor
public:
    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Constructor/Destructor>
    VcpVKLayoutAdp() :
        m_currVkLayout(NULL)
    {
    }

// Method    
public:
    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the image id of background of longtap hint for virtual keyboard
    // RETURNS: The image id of background of longtap hint
    VfxResId getLongtapBgImg();

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the image id of background of virtual keyboard
    // RETURNS: The image id of background of virtual keyboard
    VfxResId getBgImage();

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Check whether current virtual keyboard is alphanumeric
    // RETURNS: VFX_FALSE: current virtual keyboard is not alphanumeric
    //          VFX_TRUE: current virtual keyboard is alphanumeric
    VfxBool checkAlphanumeric();


    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Setup the virtual keyboard according to the resolution, type and attribute
    // Return: VFX_TRUE: successful; VFX_FALSE: error
    VfxBool setup(
        VfxS32 width,               // [IN] the width of resolution
        VfxS32 height,              // [IN] the height of resolution
        VcpVKTypeEnum type,         // [IN] the type of virtual keyboard
        VcpVKAttr attr              // [IN] the attribute of virtual keyboard
        );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the count of buttons in current virtual keyboard
    // RETURNS: The count of buttons in current virtual keyboard
    VfxU16 getButtonCount();

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the type of button in current virtual keyboard
    // RETURNS: VFX_TRUE: normal button; VFX_FALSE: popup or longtap hint button
    VfxBool checkButtonIsNormal(
        VfxU16 index                // [IN] the index of button
        );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the content of button in current virtual keyboard
    // RETURNS: the content of button in current virtual keyboard
    VfxU32 getButtonContent(
        VfxU16 index                // [IN] the index of button
        );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the rectangle of button in current virtual keyboard
    void getButtonRect(
        VfxU16 index,               // [IN] the index of button
        VfxS32 *x,                  // [OUT] the x coordinate
        VfxS32 *y,                  // [OUT] the y coordinate
        VfxS32 *width,              // [OUT] the width
        VfxS32 *height              // [OUT] the height
        );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the size of current virtual keyboard
    void getSize(
        VfxS32 *width,              // [OUT] the width
        VfxS32 *height              // [OUT] the height
        );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the background image id of button in normal state
    // RETURNS: The background image id of button in normal state
    VfxResId getButtonNormalBgImg(
        VfxU16 index                // [IN] the index of button
        );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the foreground image id of button in normal state
    // RETURNS: The foreground image id of button in normal state
    VfxResId getButtonNormalFgImg(
        VfxU16 index                // [IN] the index of button
        );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the background image id of button in highlight state
    // RETURNS: The background image id of button in highlight state
    VfxResId getButtonHiliteBgImg(
        VfxU16 index                // [IN] the index of button
        );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the foreground image id of button in highlight state
    // RETURNS: The foreground image id of button in highlight state
    VfxResId getButtonHiliteFgImg(
        VfxU16 index                // [IN] the index of button
        );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the background image id of button in disabled state
    // RETURNS: The background image id of button in disabled state
    VfxResId getButtonDisabledBgImg(
        VfxU16 index                // [IN] the index of button
        );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the foreground image id of button in disabled state
    // RETURNS: The foreground image id of button in disabled state
    VfxResId getButtonDisabledFgImg(
        VfxU16 index                // [IN] the index of button
        );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the background image id of button in popup state
    // RETURNS: The background image id of button in popup state
    VfxResId getButtonPopupBgImg(
        VfxU16 index                // [IN] the index of button
        );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the foreground image id of button in popup state
    // RETURNS: The foreground image id of button in popup state
    VfxResId getButtonPopupFgImg(
        VfxU16 index                // [IN] the index of button
        );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the number of buttons in longtap hint
    // RETURNS: The number of buttons in longtap hint
    VfxU16 getButtonLongtapBtnNum(
        VfxU16 index                // [IN] the index of button that should show longtap hint
        );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the content of button in longtap hint
    // RETURNS: The content of button in longtap hint
    VfxU32 getButtonLongtapContent(
        VfxU16 button_index,        // [IN] the index of button that should show longtap hint
        VfxU16 index                // [IN] the index of button in longtap hint
        );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the image id of button in longtap hint
    void getButtonLongtapImg(
        VfxU16 button_index,        // [IN] the index of button that should show longtap hint
        VfxU16 index,               // [IN] the index of button in longtap hint
        VfxResId *fgId,             // [OUT] the foreground image id in normal state
        VfxResId *bgId,             // [OUT] the background image id in normal state
        VfxResId *fgHighlightId,    // [OUT] the foreground image id in highlight state
        VfxResId *bgHighlightId     // [OUT] the background image id in highlight state
        );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the size of button in longtap hint
    void getButtonLongtapSize(
        VfxU16 button_index,        // [IN] the index of button that should show longtap hint
        VfxU16 index,               // [IN] the index of button in longtap hint
        VfxU16 *width,              // [OUT] the width of button in longtap hint
        VfxU16 *height              // [OUT] the height of button in longtap hint
        );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the size of popup hint of one button
    void getButtonPopupSize(
        VfxU16 index,               // [IN] the index of button
        VfxS32 *width,              // [OUT] the width of popup hint
        VfxS32 *height              // [OUT] the height of popup hint
        );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // check whether the button has popup hint
    // RETURNS: VFX_FALSE, there is no popup hint; VFX_TRUE, there is popup hint
    VfxBool checkButtonPopupExist(
        VfxU16 index                // [IN] the index of button
        );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // check whether the button has longtap hint
    // RETURNS: VFX_FALSE, there is no longtap hint; VFX_TRUE, there is longtap hint
    VfxBool checkButtonLongtapExist(
        VfxU16 index                // [IN] the index of button
        );

    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Method>
    // Get the image id of button in multi popup
    void getButtonMultiPopupImg(
        VfxU16 button_index,        // [IN] the index of button that should show multi popup
        VfxU16 index,               // [IN] the index of button in multi popup
        VfxResId *fgId,             // [OUT] the foreground image id
        VfxResId *bgId              // [OUT] the background image id
        );
    
// Variable
private:
    // <group DOM_VirtualKeyboard_VcpVKLayoutAdp_Constructor/Destructor>
    // record the current virtual keyboard layout
    VcpVKLayoutStruct *m_currVkLayout;
};

/***************************************************************************** 
 * Class VcpVKHiliteFrame
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VcpVKHiliteFrame show the background and foreground images. 
 *  It has only one member variable: m_fgFrame (is a VfxImageFrame).
 *  This member variable is child (frame tree) of VcpVKHiliteFrame.
 *  VcpVKHiliteFrame shows the background image by itself. The m_fgFrame shows the foreground image.
 *  It is used to show the popup hint and highlight state of button.
 */
class VcpVKHiliteFrame : public VfxFrame
{
// Constructor / Destructor
public:
    // <group DOM_VirtualKeyboard_VcpVKHiliteFrame_Constructor/Destructor>
    VcpVKHiliteFrame() :
        m_fgFrame(NULL)
    {
    }

// Method    
public:
    // <group DOM_VirtualKeyboard_VcpVKHiliteFrame_Method>
    // set the background image by image id
    void setBackgroundImg(
        const VfxImageSrc &image          // [IN] foreground image
        );
    
    // <group DOM_VirtualKeyboard_VcpVKHiliteFrame_Method>
    // set the foreground image by image id
    void setForegroundImg(
        const VfxImageSrc &image          // [IN] background image
        );

    // Change the background and foreground frame to the last one of parent's child frame.
    void bringToFront();

// Override
public:
    // <group DOM_VirtualKeyboard_VcpVKHiliteFrame_Override>
    virtual void setPos(const VfxPoint &value);
    
    // Only avoid the target build error
    void setPos(
        VfxS32 x,                   // [IN] The x coordinate to set
        VfxS32 y                    // [IN] The y coordinate to set
    )
    {
        setPos(VfxPoint(x, y));
    }
    
    // <group DOM_VirtualKeyboard_VcpVKHiliteFrame_Override>
    virtual void setBounds(const VfxRect &value);

    // <group DOM_VirtualKeyboard_VcpVKHiliteFrame_Override>
    virtual void setHidden(VfxBool value);

    // <group DOM_VirtualKeyboard_VcpVKHiliteFrame_Override>
    virtual void setPosZ(VfxFloat value);

    // <group DOM_VirtualKeyboard_VcpVKHiliteFrame_Override>
    virtual void setOpacity(VfxFloat value);

protected:
    // <group DOM_VirtualKeyboard_VcpVKHiliteFrame_Override>
    virtual void onInit();

    // <group DOM_VirtualKeyboard_VcpVKHiliteFrame_Override>
    virtual void onDeinit();

// Variable
private:
    // <group DOM_VirtualKeyboard_VcpVKHiliteFrame_Variable>
    // forground image frame
    VfxImageFrame *m_fgFrame;

    // <group DOM_VirtualKeyboard_VcpVKHiliteFrame_Variable>
    // Weak pointer to forground image frame
    VfxWeakPtr <VfxImageFrame> m_fgFrameWeakPtr;
};


/***************************************************************************** 
 * Class VcpVKLongtapHint
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VcpVKLongtapHint shows the longtap popup hint when one button is long pressed in VK.
 *  It is able to handle pen event (processPenEvent()). The object who use VcpVKLongtapHint
 *  can pass the pen event received to VcpVKLongtapHint by calling processPenEvent(). It emits
 *  corresponding signal.
 */
class VcpVKLongtapHint : public VfxFrame
{
// Constructor / Destructor
public:
    // <group DOM_VirtualKeyboard_VcpVKLongtapHint_Constructor/Destructor>
    VcpVKLongtapHint(
        const VcpVKLongtapInfo *info ,           // [IN] the information array of buttons that will show in longtap hint
                   VfxObject *object                             // Note: Do not destroy the parameter of info when this object is alive
        );

// Method    
public:
    // <group DOM_VirtualKeyboard_VcpVKLongtapHint_Method>
    // This function process the pen event passed from outside
    // RETURNS: If the event is handled, return VFX_TRUE; else, return VFX_FALSE
    VfxBool processPenEvent(
        const VcpVKLongtapHintEvt &event        // [IN] the information of pen event
        );

// Override
public:
    // <group DOM_VirtualKeyboard_VcpVKLongtapHint_Method>
    virtual void setPosZ(VfxFloat value);

// Signal
public:
    // <group DOM_VirtualKeyboard_VcpVKLongtapHint_Signal>
    // notify that the pen moves from one button to another, and the parameter is new button
    // If the 2nd parameter is VKBtnTypeChar, it represents the event happened in character button
    // and the 3rd parameter is the Unicode of character. If the 2nd is VKBtnTypeFunc,
    // It represents the event happened in function button and the 3rd parameter is the enum value of
    // this function button (VcpVKFuncBtnEnum).
    VfxSignal3 <
        VfxObject*,                     // sender
        VcpVKBtnTypeEnum,               // the type of button
        VfxU32                          // Unicode of character button or the event of function button
        > m_signalButtonMove;

    // <group DOM_VirtualKeyboard_VcpVKLongtapHint_Signal>
    // notify that the pen is up on one button
    // the parameter is the button on which pen is up
    VfxSignal3 <
        VfxObject*,                     // sender
        VcpVKBtnTypeEnum,               // the type of button
        VfxU32                          // Unicode of character button or the event of function button
        > m_signalButtonUp;

    // <group DOM_VirtualKeyboard_VcpVKLongtapHint_Signal>
    // notify that the pen is abort
    // the parameters is the last button encountered
    VfxSignal3 <
        VfxObject*,                     // sender
        VcpVKBtnTypeEnum,               // the type of button
        VfxU32                          // Unicode of character button or the event of function button
        > m_signalButtonAbort;

// Override
protected:
    // <group DOM_VirtualKeyboard_VcpVKLongtapHint_Override>
    virtual void onInit();
    
    // <group DOM_VirtualKeyboard_VcpVKLongtapHint_Override>
    virtual void onDeinit();
    
    // <group DOM_VirtualKeyboard_VcpVKLongtapHint_Override>
    virtual void onDraw(VfxDrawContext &dc);

// Implementation
private:
    // <group DOM_VirtualKeyboard_VcpVKLongtapHint_Implementation>
    // calculate the rectangle of buttons and longtap hint.
    // build the linked list of buttons (m_buttonList)
    void calculateRects();

    // <group DOM_VirtualKeyboard_VcpVKLongtapHint_Implementation>
    // draw one button
    void drawButton(
        VfxDrawContext &dc,                     // [IN] the object of VfxDrawContext for drawing
        const VcpVKLongTapBtn *button           // [IN] the button to draw
        );

    // <group DOM_VirtualKeyboard_VcpVKLongtapHint_Implementation>
    // set the highlight frame to be the button as parameter
    void setHiliteButton(
        const VcpVKLongTapBtn *button           // [IN] the button to draw highlight state
        );

    // <group DOM_VirtualKeyboard_VcpVKLongtapHint_Implementation>
    // get the button in which the point is
    // RETURNS: If point is in button, return the node in linked list of button; else, return NULL
    const VcpVKLongTapBtn *getButtonByPoint(
        const VfxPoint &point                   // [IN] the point
        );

    // <group DOM_VirtualKeyboard_VcpVKLongtapHint_Implementation>
    // emit the signal of move on button
    void emitMoveSignal(
        const VcpVKLongTapBtn *button           // [IN] the button where signal happened
        );

    // <group DOM_VirtualKeyboard_VcpVKLongtapHint_Implementation>
    // emit the signal of abort on button
    void emitAbortSignal(
        const VcpVKLongTapBtn *button           // [IN] the button where signal happened
        );

    // <group DOM_VirtualKeyboard_VcpVKLongtapHint_Implementation>
    // emit the signal of up on button
    void emitUpSignal(
        const VcpVKLongTapBtn *button           // [IN] the button where signal happened
        );
    
// Variable
private:
    // <group DOM_VirtualKeyboard_VcpVKLongtapHint_Variable>
    // the information about the buttons of long tap hint
    const VcpVKLongtapInfo *m_info;

    // <group DOM_VirtualKeyboard_VcpVKLongtapHint_Variable>
    // the frame to show the highlight state of button
    VcpVKHiliteFrame* m_hiliteFrame;

    // <group DOM_VirtualKeyboard_VcpVKLongtapHint_Variable>
    // the active buttons
    VcpVKLongTapBtn *m_buttonList;

    // <group DOM_VirtualKeyboard_VcpVKLongtapHint_Variable>
    // the current selected button
    const VcpVKLongTapBtn *m_currButton;
	VfxObject *m_parent ;
};


/***************************************************************************** 
 * Class VcpVK
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VcpVK manages the show of Venus virtual keyboard and notify outside when one button is pressed,
 *  up, long tape, abort and move to another button. VcpVK get the layout and other information of
 *  VK generated by MCT internally.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VcpVK : public VfxControl
{
    VFX_DECLARE_CLASS(VcpVK);
    
// Constructor / Destructor
public:
    // <group DOM_VirtualKeyboard_VcpVK_Constructor/Destructor>
    VcpVK(VfxObject *parent);
	VcpVK()
	{

	};

	   VfxObject *getOwner(void)
	   {
		   return m_VKparent ;
	   }
    // <group DOM_VirtualKeyboard_VcpVK_Constructor/Destructor>
    VcpVK(
        VcpVKTypeEnum type,     // [IN] the type to be set
        VcpVKAttr attr          // [IN] the attribute to be set
        );

// Method
public:
    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // set the type of virtual keyboard
    void setType(
        VcpVKTypeEnum type      // [IN] the type to be set
        );

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // set the attribute of virtual keyboard
    void setAttr(
        VcpVKAttr attr          // [IN] the attribute to be set
        );

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // get the type of virtual keyboard
    VcpVKTypeEnum getType()
    {
        return m_type;
    }

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // get the attribute of virtual keyboard
    VcpVKAttr getAttr()
    {
        return m_attr;
    }

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // rotate the virtual keyboard
    void rotate()
    {
        checkUpdate();
    }

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // Set the allowed character buttons in VK. All the missed character buttons are disabled.
    // Note: Take care of the relationship with setDisabledCharButtons(). Only one can be called.
    // Note: The setting won't be resetted by changing type/attribure of virtual keyboard and rotating virtual keyboard 
    void setAllowedCharButtons(
        const VfxWString &allowedButtons        // [IN] Allowed character buttons in VK
        );

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // Set the disabled character buttons in VK. All the missed character buttons are enabled.
    // Note: Take care of the relationship with setAllowedCharButtons(). Only one can be called.
    // Note: The setting won't be resetted by changing type/attribure of virtual keyboard and rotating virtual keyboard 
    void setDisabledCharButtons(
        const VfxWString &disabledButtons       // [IN] Disabled character buttons in VK
        );

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // Reset the character buttons to default state (all buttons are allowed)
    void resetCharButtons();

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // Set the disabled function buttons in VK. All the missed buttons are enabled.
    // Note: Default, all function buttons are enabled.
    // Note: The setting won't be resetted by changing type/attribure of virtual keyboard and rotating virtual keyboard 
    void setDisabledFuncButtons(
        const VcpVKFuncBtnEnum *disabledButtons // [IN] Disabled function buttons in VK. End by GUI_VKBD_PEN_NONE
                                                // Note: only the first VCP_VK_MAX_DISABLED_FUNC_BUTTON buttons are valid.
        );

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // Reset the function buttons to default state (all buttons are allowed)
    void resetFuncButtons();

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // Set the image id of specific button
    // Note: The setting won't be resetted by changing type/attribure of virtual keyboard and rotating virtual keyboard 
    void setButtonImage(
        const VcpVKBtnImg &imageInfo            // [IN] the image id information of button
        );

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // Clear all the image id saved
    void clearAllButtonImage();

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // Register the display callback for getting button image.
    // Note: The setting won't be resetted by changing type/attribure of virtual keyboard and rotating virtual keyboard 
    void registerDisplayCallback(
        VfxObject *obj,                         // [IN] the object of class that cbFunc belongs to
        const VcpVKDisplayCB cbFunc             // [IN] the callback function to be registered
        );

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // Register the multi popup callback for checking and getting the multi popup.
    // Note: The setting won't be resetted by changing type/attribure of virtual keyboard and rotating virtual keyboard 
    void registerMultiPopupCallback(
        VfxObject *obj,
        const VcpVKMultiPopupCB cbFunc
        );

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // Unregister the display callback for getting button image.
    void unregisterDisplayCallback();

    // <group DOM_VirtualKeyboard_VcpVK_Method>
    // Unregister the multi popup callback for checking and getting the multi popup.
    void unregisterMultiPopupCallback();

// Override
public:
    // <group DOM_VirtualKeyboard_VcpVK_Override>
    virtual void setPos(const VfxPoint &value);

    // <group DOM_VirtualKeyboard_VcpVK_Override>
    virtual void setPosZ(VfxFloat value);

    // Only avoid the target build error
    void setPos(
        VfxS32 x,                   // [IN] The x coordinate to set
        VfxS32 y                    // [IN] The y coordinate to set
    )
    {
        setPos(VfxPoint(x, y));
    }

// Signal
public:
    // <group DOM_VirtualKeyboard_VcpVK_Signal>
    // notify that the pen is down on one button, and the parameter is the button
    // If the 2nd is VKBtnTypeChar, it represents the event happened in character button
    // and the 3rd parameter is the Unicode of character. If the 2nd parameter is VKBtnTypeFunc,
    // It represents the event happened in function button and the 3rd parameter is the enum value of
    // this function button (VcpVKFuncBtnEnum).
    VfxSignal3 <
        VfxObject*,                     // sender
        VcpVKBtnTypeEnum,               // the type of button
        VfxU32                          // Unicode of character button or the event of function button
        > m_signalButtonDown;

    // <group DOM_VirtualKeyboard_VcpVK_Signal>
    // notify that the pen is longtap on one button
    // the parameter is the button on which pen is longtap
    VfxSignal3 <
        VfxObject*,                     // sender
        VcpVKBtnTypeEnum,               // the type of button
        VfxU32                          // Unicode of character button or the event of function button
        > m_signalButtonLongtap;


    // <group DOM_VirtualKeyboard_VcpVK_Signal>
    // notify that the pen moves from one button to another, and the parameter is new button
    VfxSignal3 <
        VfxObject*,                     // sender
        VcpVKBtnTypeEnum,               // the type of button
        VfxU32                          // Unicode of character button or the event of function button
        > m_signalButtonMove;

    // <group DOM_VirtualKeyboard_VcpVK_Signal>
    // notify that the pen is up on one button
    // the parameter is the button on which pen is up
    VfxSignal3 <
        VfxObject*,                     // sender
        VcpVKBtnTypeEnum,               // the type of button
        VfxU32                          // Unicode of character button or the event of function button
        > m_signalButtonUp;

    // <group DOM_VirtualKeyboard_VcpVK_Signal>
    // notify that the pen is abort
    // the parameters is the last button encountered
    VfxSignal3 <
        VfxObject*,                     // sender
        VcpVKBtnTypeEnum,               // the type of button
        VfxU32                          // Unicode of character button or the event of function button
        > m_signalButtonAbort;
    
// Override
protected:
    // <group DOM_VirtualKeyboard_VcpVK_Override>
    virtual void onInit();

    // <group DOM_VirtualKeyboard_VcpVK_Override>
    virtual void onDeinit();
    
    // <group DOM_VirtualKeyboard_VcpVK_Override>
    virtual void onDraw(
        VfxDrawContext &dc
        );

    // <group DOM_VirtualKeyboard_VcpVK_Override>
    virtual VfxBool onPenInput(
        VfxPenEvent &event
        );

    // <group DOM_VirtualKeyboard_VcpVK_Override>
    virtual void onUpdate();
    
// Implementation
private:
    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // check whether the button is allowed
    // RETURNS: VFX_TRUE, the button is allowed. VFX_FALSE, the button is disabled
    VfxBool checkButtonIsAllowed(
        VfxU32 content                  // [IN] the content of button to check
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // draw one button
    void drawButton(
        VfxDrawContext &dc,             // [IN] the object of VfxDrawContext for drawing
        const VcpVKBtn *button          // [IN] the button to draw
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // get the image of background and foreground image of button
    void getButtonImg(
        const VcpVKBtn *button,                 // [IN] the button to get image
        VcpVKBtnStateEnum state,                // [IN] the state of button to get image
        VfxImageSrc &bgImg,                     // [OUT] the background image got
        VfxImageSrc &fgImg                      // [OUT] the foreground image got
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // get the image id of background and foreground image of button of longtap hint
    void getLongtapButtonImg(
        const VcpVKBtn *button,                 // [IN] the button to show longtap hint
        VfxU16 index,                           // [IN] the index of button in longtap hint
        VfxImageSrc &bgImg,                     // [OUT] the background image got
        VfxImageSrc &fgImg,                     // [OUT] the foreground image got
        VfxImageSrc &bgHiliteImg,               // [OUT] the background image got when button is in highlight state
        VfxImageSrc &fgHiliteImg                // [OUT] the foreground image got when button is in highlight state
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // get the button in which the point is
    // RETURNS: If point is in active button, return the node in linked list of button; else, return NULL
    const VcpVKBtn *getButtonByPointStrict(
        const VfxPoint &point                   // [IN] the point
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // get the button in which the point is nearist
    // RETURNS: If point is in active button, return the node in linked list of button; else, return NULL
    const VcpVKBtn *getButtonByPoint(
        const VfxPoint &point                   // [IN] the point
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // emit the signal of down on button
    void emitDownSignal(
        const VcpVKBtn *button                  // [IN] the button where signal happened
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // emit the signal of longtap on button
    void emitLongtapSignal(
        const VcpVKBtn *button                  // [IN] the button where signal happened
        );
    
    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // emit the signal of move on button
    void emitMoveSignal(
        const VcpVKBtn *button                  // [IN] the button where signal happened
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // emit the signal of up on button
    void emitUpSignal(
        const VcpVKBtn *button                  // [IN] the button where signal happened
        );
    
    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // emit the signal of abort on button
    void emitAbortSignal(
        const VcpVKBtn *button                  // [IN] the button where signal happened
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // the slot of the timer to check longtap
    void longtapTimeup(
        VfxTimer *timerFunc                     // [IN] the timer to check longtap
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // the slot of the timer to hide popup
    void popupHideTimeup(
        VfxTimer *timerFunc                     // [IN] the timer to hide popup
        );
    
    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // set the highlight frame to be the button as parameter
    void setHiliteButton(
        const VcpVKBtn *button                  // [IN] the button to draw highlight state
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // set the popup hint frame of the button as parameter
    void setPopupHintFrame(
        const VcpVKBtn *button                  // [IN] the button to show popup hint
        );
    
    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // check whether the button has popup hint
    // RETURNS: VFX_TRUE, has popup hint. VFX_FALSE, has no popup hint
    VfxBool checkPopupExist(
        const VcpVKBtn *button                  // [IN] the button to check
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // check whether the button has longtap hint
    // RETURNS: VFX_TRUE, has longtap hint. VFX_FALSE, has no longtap hint
    VfxBool checklongtapExist(
        const VcpVKBtn *button                  // [IN] the button to check
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // the slot to handle the move signal from longtap hint
    void longtapHintMoveHandler(
        VfxObject *sender,              // [IN] the sender
        VcpVKBtnTypeEnum type,          // [IN] the type of button
        VfxU32 content                  // [IN] the content of button
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // the slot to handle the up signal from longtap hint
    void longtapHintUpHandler(
        VfxObject *sender,              // [IN] the sender
        VcpVKBtnTypeEnum type,          // [IN] the type of button
        VfxU32 content                  // [IN] the content of button
        );

    // <group DOM_VirtualKeyboard_VcpVK_Implementation>
    // the slot to handle the abort signal from longtap hint
    void longtapHintAbortHandler(
        VfxObject *sender,              // [IN] the sender
        VcpVKBtnTypeEnum type,          // [IN] the type of button
        VfxU32 content                  // [IN] the content of button
        );

// Variable
private:
    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the type of virtual keyboard
    VcpVKTypeEnum m_type;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the attribute of virtual keyboard
    VcpVKAttr m_attr;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the character buttons which are disabled or allowed
    //VcpVKAllowedDisabledCharBtn m_disabledAllowedCharBtns;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the function buttons which are disabled
    VcpVKFuncBtnEnum m_disabledFuncBtn[VCP_VK_MAX_DISABLED_FUNC_BUTTON + 1];

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the buttons
    VcpVKBtn *m_buttonList;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the current selected button
    const VcpVKBtn *m_currButton;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the frame to show the highlight state of button
    VcpVKHiliteFrame* m_hiliteFrame;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the frame to show the popup hint of button
    VcpVKHiliteFrame* m_popupHintFrame;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the information of image id of buttons in virtual keyboard 
    VcpVKBtnImgNode *m_btnImgInfo;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the object of class to which display callback function belongs
    VfxObjWeakPtr m_displayCbObj;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the function pointer of display callback function
    VcpVKDisplayCB m_displayCbFunc;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the object of class to which multi popup callback function belongs
    VfxObjWeakPtr m_multiPopupCbObj;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the function pointer of multi popup callback function
    VcpVKMultiPopupCB m_multiPopupCbFunc;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // whether current state is in longtap hint state
    VfxBool m_inLongtapHintState;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the timer to check longtap
    VfxTimer *m_longtapTimer;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the timer to hide the popup
    VfxTimer *m_popupHideTimer;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the longtap hint object
    VcpVKLongtapHint *m_longtapHint;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the button information of longtap hint
    VcpVKLongtapInfo m_longtapBtnInfo;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // whether current state is ready for entering longtap hint state
    VfxBool m_readyForLongtap;

    // <group DOM_VirtualKeyboard_VcpVK_Variable>
    // the adptor to get the information generated by MCT
    VcpVKLayoutAdp m_adaptor;
	VfxObject *m_VKparent ;
};

#endif /* __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__ */
#endif /* _3_ || _2_ */
#endif /* __VCP_VK_H__ */

