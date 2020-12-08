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
*  vcp_segment_button.h
*
* Project:
* --------
*  Venus UI Components
*
* Description:
* ------------
*  Segment button component
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef __VCP_SEGMENT_BUTTON_H__
#define __VCP_SEGMENT_BUTTON_H__

/***************************************************************************** 
* Include
*****************************************************************************/
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vcp_state_image.h"
#include "vfx_string.h"
#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_signal.h"
#include "vfx_object_list.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"

/***************************************************************************** 
* Define
*****************************************************************************/

#if defined(__MMI_VUI_COSMOS_CP__)
#define VCP_SEG_BTN_TEXT_COLOR_NORMAL     VFX_COLOR_RES(VCP_COL_SEG_BTN_NRML_TEXT)
#define VCP_SEG_BTN_TEXT_COLOR_PRESSED    VFX_COLOR_RES(VCP_COL_SEG_BTN_PRSD_TEXT)
#else
#define VCP_SEG_BTN_TEXT_COLOR_NORMAL         VfxColor(255, 15, 15, 15)
#define VCP_SEG_BTN_TEXT_COLOR_PRESSED    VfxColor(255, 255, 255, 255)
#endif


// <group DOM_SegmentButton_Macro&Enum_Enum>
// Type of segment button
enum VcpSegmentButtonTypeEnum
{
    VCP_SEGMENT_BUTTON_TYPE_GROUP,          // each button is independently turned on or off
    VCP_SEGMENT_BUTTON_TYPE_RADIO,          // only one button is turned on at a time

    VCP_SEGMENT_BUTTON_TYPE_END_OF_ENUM     // end of the enum
};

#if defined(MULTI_LAYOUT_SEGBTN_SUPPORT)
// <group DOM_SegmentButton_Macro&Enum_Enum>
enum VcpSegmentButtonOrientationEnum
{
    VCP_SEGMENT_BUTTON_ORTN_VERTICAL,
    VCP_SEGMENT_BUTTON_ORTN_HORIZONTAL,

    VCP_SEGMENT_BUTTON_ORTN_END_OF_ENUM
};
#endif /* defined(MULTI_LAYOUT_SUPPORT) */

// <group DOM_SegmentButton_Macro&Enum_Enum>
// Display style of segment button
enum VcpSegmentButtonStyleEnum
{
    VCP_SEGMENT_BUTTON_STYLE_IMAGE_ONLY,    // only display image in the button, but display text as hint
    VCP_SEGMENT_BUTTON_STYLE_TEXT_ONLY,     // only display text in the button

    VCP_SEGMENT_BUTTON_STYLE_END_OF_ENUM    // end of the enum
};

/***************************************************************************** 
* for XML support
*****************************************************************************/    
struct VcpSegmentButtonItem : public VfxBase
{
    VfxS32   id;
    VcpStateImage image;
    VfxWString text;
};

/***************************************************************************** 
* Class VcpSegmentButton
*****************************************************************************/
class VcpSegmentButton : public VfxControl
{
    VFX_DECLARE_CLASS(VcpSegmentButton);

    // Constructor / Destructor
public:    
    // <group DOM_SegmentButton_VcpSegmentButton_Constructor/Destructor>
    // Default constructor.
    VcpSegmentButton();

    // Event
public:
    // <group DOM_SegmentButton_VcpSegmentButton_Event>
    // This signal is invoked when one button is clicked
    // void YourClass::onButtonClicked(VfxObject* sender, VfxId buttonId)
    VfxSignal2 <VfxObject*, VfxId> m_signalButtonClicked;

    // Method
public:
    // <group DOM_SegmentButton_VcpSegmentButton_Method>
    // add one button
    virtual void addButton2 (
        VfxId id,                           // [IN] button ID
        const VcpStateImage &imageList,     // [IN] image
        VfxResId resId,             // [IN] text
        VfxId beforeId = INVALID_BUTTON_ID  // [IN] where to insert the button, insert to the end by default
        );

    
    // <group DOM_SegmentButton_VcpSegmentButton_Method>
    // add one button
    virtual void addButton2 (
        VfxId id,                           // [IN] button ID
        const VcpStateImage &imageList,     // [IN] image
        const VfxWChar *mem,             // [IN] text
        VfxId beforeId = INVALID_BUTTON_ID  // [IN] where to insert the button, insert to the end by default
        );

    // <group DOM_SegmentButton_VcpSegmentButton_Method>
    // add one button
    virtual void addButton (
        VfxId id,                           // [IN] button ID
        const VcpStateImage &imageList,     // [IN] image
        const VfxWString &text,             // [IN] text
        VfxId beforeId = INVALID_BUTTON_ID  // [IN] where to insert the button, insert to the end by default
        );

    // <group DOM_SegmentButton_VcpSegmentButton_Method>
    // remove one button
    virtual void removeButton (
        VfxId id                        // [IN] button ID
        );

    // <group DOM_SegmentButton_VcpSegmentButton_Method>
    // remove all buttons
    virtual void removeAllButtons ();

    // <group DOM_SegmentButton_VcpSegmentButton_Method>
    // enable / disable one button
    virtual void setButtonIsDisabled (
        VfxId id,                       // [IN] button ID
        VfxBool isDisabled              // [IN] whether it is enabled
        );

    // <group DOM_SegmentButton_VcpSegmentButton_Method>
    // get whether one button is enabled
    // RETURNS: VfxBool
    virtual VfxBool getButtonIsDisabled (
        VfxId id                        // [IN] button ID
        ) const ;

    // <group DOM_SegmentButton_VcpSegmentButton_Method>
    // highlight / un-highlight one button
    virtual void setButtonIsHighlighted (
        VfxId id,                       // [IN] button ID
        VfxBool isHighlighted           // [IN] whether it is highlighted
        );

    // <group DOM_SegmentButton_VcpSegmentButton_Method>
    // get whether one button is highlighted
    // RETURNS: VfxBool
    virtual VfxBool getButtonIsHighlighted (
        VfxId id                        // [IN] button ID
        ) const ;

    // <group DOM_SegmentButton_VcpSegmentButton_Method>
    virtual void setButtonImage(
        VfxId id,                       // [IN] button ID
        const VcpStateImage &imageList  // [IN] image
        );

    // <group DOM_SegmentButton_VcpSegmentButton_Method>
    void setWidth(VfxS32 w);

    // <group DOM_SegmentButton_VcpSegmentButton_Method>
    VfxS32 getWidth() const;

    // <group DOM_SegmentButton_VcpSegmentButton_Method>
    void setFontSize(VfxS32 fontsize);
         
    // Property
#if defined(MULTI_LAYOUT_SEGBTN_SUPPORT)
    // <group DOM_SegmentButton_VcpSegmentButton_Property>
    // set orientation of segment button
    virtual void setOrientation (
        VcpSegmentButtonOrientationEnum ortn   // [IN] segment button type
        )
    {
        m_ortn = ortn;
        checkUpdate();
    }

    // <group DOM_SegmentButton_VcpSegmentButton_Property>
    // get orientation of segment button
    // RETURNS: VcpSegmentButtonOrientationEnum 
    virtual VcpSegmentButtonOrientationEnum getOrientation () const
    {
        return m_ortn;
    }
#endif /* defined(MULTI_LAYOUT_SEGBTN_SUPPORT) */
    // <group DOM_SegmentButton_VcpSegmentButton_Property>
    // set type of segment button
    virtual void setType (
        VcpSegmentButtonTypeEnum type   // [IN] segment button type
        )
    {
        m_type = type;
        checkUpdate();
    }

    // <group DOM_SegmentButton_VcpSegmentButton_Property>
    // get type of segment button
    // RETURNS: VcpSegmentButtonTypeEnum
    virtual VcpSegmentButtonTypeEnum getType () const
    {
        return m_type;
    }

    // <group DOM_SegmentButton_VcpSegmentButton_Property>
    // set display style of segment button
    virtual void setStyle (
        VcpSegmentButtonStyleEnum style // [IN] segment button style
        )
    {
        m_style = style;
        checkUpdate();
    }

    // <group DOM_SegmentButton_VcpSegmentButton_Property>
    // get style of segment button
    // RETURNS: VcpSegmentButtonStyleEnum
    virtual VcpSegmentButtonStyleEnum getStyle () const
    {
        return m_style;
    }

    // Override
protected:
    // <group DOM_SegmentButton_VcpSegmentButton_Override>
    // On init
    virtual void onInit();

    // <group DOM_SegmentButton_VcpSegmentButton_Override>
    // On deinit
    virtual void onDeinit();

    // <group DOM_SegmentButton_VcpSegmentButton_Override>
    // update the title display
    virtual void onUpdate();

    // Implementation
private:
    // <group DOM_SegmentButton_VcpSegmentButton_Implementation>
    enum
    {
        INVALID_BUTTON_ID = 0xFFFFFFFF,     
#if defined(__MMI_MAINLCD_320X480__)
        DEFAULT_HEIGHT = 39,
       MINIMUM_WIDTH = 153,               
       TEXT_FONT_SIZE = 16            
#elif defined(__MMI_MAINLCD_480X800__)
        DEFAULT_HEIGHT = 66,
       MINIMUM_WIDTH = 268,
       TEXT_FONT_SIZE = 30                   
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
       DEFAULT_HEIGHT = 35,
       MINIMUM_WIDTH = 128,               
       TEXT_FONT_SIZE = 16            
#else
       DEFAULT_HEIGHT = 39,
       MINIMUM_WIDTH = 128,               
       TEXT_FONT_SIZE = 16            
#endif
    };

    // Implementation
private:
    // <group DOM_SegmentButton_VcpSegmentButton_Implementation>
    // list of button
    VfxObjList m_list;

    // <group DOM_SegmentButton_VcpSegmentButton_Implementation>
    // number of buttons
    VfxS32 m_count;

#if defined(MULTI_LAYOUT_SEGBTN_SUPPORT)
    // <group DOM_SegmentButton_VcpSegmentButton_Implementation>
    //Orientation
    VcpSegmentButtonOrientationEnum m_ortn;
#endif /* defined(MULTI_LAYOUT_SEGBTN_SUPPORT) */

    // <group DOM_SegmentButton_VcpSegmentButton_Implementation>
    // type
    VcpSegmentButtonTypeEnum m_type;

    // <group DOM_SegmentButton_VcpSegmentButton_Implementation>
    // style
    VcpSegmentButtonStyleEnum m_style;

    // <group DOM_SegmentButton_VcpSegmentButton_Implementation>
    // highlighted button ID, only for VCP_SEGMENT_BUTTON_TYPE_RADIO
    VfxId m_highlightedId;

    // <group DOM_SegmentButton_VcpSegmentButton_Implementation>
    VfxS32 m_fontSize;
    
    // <group DOM_SegmentButton_VcpSegmentButton_Implementation>
    // update button while bounds change
    void onBoundsChanged (VfxFrame *frame, const VfxRect &old) {checkUpdate();}

    // <group DOM_SegmentButton_VcpSegmentButton_Implementation>
    // on button clicked, emit button clicked event
    void onButtonClicked (VfxObject* sender, VfxId Id);
};



#endif /* __VCP_SEGMENT_BUTTON_H__ */

