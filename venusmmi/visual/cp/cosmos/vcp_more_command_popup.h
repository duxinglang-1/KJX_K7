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
 *  vcp_more_command_popup.h
 *
 * Project:
 * --------
 *  Venus UI Component
 *
 * Description:
 * ------------
 *  
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef __VCP_MORE_COMMAND_POPUP_H__
#define __VCP_MORE_COMMAND_POPUP_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vcp_button.h"
#include "vfx_base_popup.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_image_src.h"
#include "vfx_text_frame.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vfx_timer.h"
#include "vfx_frame.h"
#include "vfx_object.h"
#include "vfx_signal.h"
#include "vcp_scrollable.h"
#include "vcp_popup_data_type.h"


// VcpMoreCommandPopup
#if defined(__MMI_MAINLCD_320X480__)
    
    // VcpMoreCommandPopup
    
    #define VCP_MORE_COMMAND_POPUP_WIDTH_PORTRAIT        (290)
    #define VCP_MORE_COMMAND_POPUP_WIDTH_LANDSCAPE       (340)
    #define VCP_MORE_COMMAND_POPUP_UP_HEIGHT             (25)
    #define VCP_MORE_COMMAND_POPUP_BOTTOM_HEIGHT         (15)
                     
    #define VCP_MORE_COMMAND_POPUP_TEXT_X                (145)
    #define VCP_MORE_COMMAND_POPUP_TEXT_Y                (13)
    #define VCP_MORE_COMMAND_POPUP_TEXT_WIDTH            (258)
    #define VCP_MORE_COMMAND_POPUP_TEXT_SIZE             (15)

    #define VCP_MORE_COMMAND_POPUP_BUTTON_Y_SHIFT        (14)
    #define VCP_MORE_COMMAND_POPUP_BUTTON_X              (11)
    #define VCP_MORE_COMMAND_POPUP_BUTTON_Y              (0)
    #define VCP_MORE_COMMAND_POPUP_BUTTON_GAP            (5)
    #define VCP_MORE_COMMAND_POPUP_BUTTON_WIDTH          (268)
    #define VCP_MORE_COMMAND_POPUP_BUTTON_HEIGHT         (47)

    #define VCP_MORE_COMMAND_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (359 + VCP_BUTTON_SHADOW_MARGIN_BOTTOM)
    #define VCP_MORE_COMMAND_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE     (255 + VCP_BUTTON_SHADOW_MARGIN_BOTTOM)

#elif defined(__MMI_MAINLCD_480X800__)

     // VcpMoreCommandPopup
     
    #define VCP_MORE_COMMAND_POPUP_WIDTH_PORTRAIT        (446)
    #define VCP_MORE_COMMAND_POPUP_WIDTH_LANDSCAPE       (546)
    #define VCP_MORE_COMMAND_POPUP_UP_HEIGHT             (45)
    #define VCP_MORE_COMMAND_POPUP_BOTTOM_HEIGHT         (30)
                     
    #define VCP_MORE_COMMAND_POPUP_TEXT_X                (223)
    #define VCP_MORE_COMMAND_POPUP_TEXT_Y                (22)
    #define VCP_MORE_COMMAND_POPUP_TEXT_WIDTH            (382)
    #define VCP_MORE_COMMAND_POPUP_TEXT_SIZE             (24)

    #define VCP_MORE_COMMAND_POPUP_BUTTON_Y_SHIFT        (10)
    #define VCP_MORE_COMMAND_POPUP_BUTTON_X              (21)
    #define VCP_MORE_COMMAND_POPUP_BUTTON_Y              (0)
    #define VCP_MORE_COMMAND_POPUP_BUTTON_GAP            (6)
    #define VCP_MORE_COMMAND_POPUP_BUTTON_WIDTH          (404)
    #define VCP_MORE_COMMAND_POPUP_BUTTON_HEIGHT         (73)

    #define VCP_MORE_COMMAND_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (547 + VCP_BUTTON_SHADOW_MARGIN_BOTTOM) 
    #define VCP_MORE_COMMAND_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE     (310 + VCP_BUTTON_SHADOW_MARGIN_BOTTOM)

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)

     // VcpMoreCommandPopup
     
    #define VCP_MORE_COMMAND_POPUP_WIDTH_PORTRAIT        (222)
    #define VCP_MORE_COMMAND_POPUP_WIDTH_LANDSCAPE       (242)
    #define VCP_MORE_COMMAND_POPUP_UP_HEIGHT             (20)
    #define VCP_MORE_COMMAND_POPUP_BOTTOM_HEIGHT         (13)
                     
    #define VCP_MORE_COMMAND_POPUP_TEXT_X                (111)
    #define VCP_MORE_COMMAND_POPUP_TEXT_Y                (10)
    #define VCP_MORE_COMMAND_POPUP_TEXT_WIDTH            (206)
    #define VCP_MORE_COMMAND_POPUP_TEXT_SIZE             (13)

    #define VCP_MORE_COMMAND_POPUP_BUTTON_Y_SHIFT        (8)
    #define VCP_MORE_COMMAND_POPUP_BUTTON_X              (8)
    #define VCP_MORE_COMMAND_POPUP_BUTTON_Y              (0)
    #define VCP_MORE_COMMAND_POPUP_BUTTON_GAP            (5)
    #define VCP_MORE_COMMAND_POPUP_BUTTON_WIDTH          (206)
    #define VCP_MORE_COMMAND_POPUP_BUTTON_HEIGHT         (40)

    #if defined(__MMI_MAINLCD_240X320__)
    #define VCP_MORE_COMMAND_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (265 + VCP_BUTTON_SHADOW_MARGIN_BOTTOM)
    #else
    #define VCP_MORE_COMMAND_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (310 + VCP_BUTTON_SHADOW_MARGIN_BOTTOM)
    #endif
    #define VCP_MORE_COMMAND_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE     (175 + VCP_BUTTON_SHADOW_MARGIN_BOTTOM)

#else

    // VcpMoreCommandPopup
    
    #define VCP_MORE_COMMAND_POPUP_WIDTH_PORTRAIT        (290)
    #define VCP_MORE_COMMAND_POPUP_WIDTH_LANDSCAPE       (340)
    #define VCP_MORE_COMMAND_POPUP_UP_HEIGHT             (25)
    #define VCP_MORE_COMMAND_POPUP_BOTTOM_HEIGHT         (19)
                     
    #define VCP_MORE_COMMAND_POPUP_TEXT_X                (145)
    #define VCP_MORE_COMMAND_POPUP_TEXT_Y                (13)
    #define VCP_MORE_COMMAND_POPUP_TEXT_WIDTH            (258)
    #define VCP_MORE_COMMAND_POPUP_TEXT_SIZE             (15)

    #define VCP_MORE_COMMAND_POPUP_BUTTON_Y_SHIFT        (15)
    #define VCP_MORE_COMMAND_POPUP_BUTTON_X              (16)
    #define VCP_MORE_COMMAND_POPUP_BUTTON_Y              (0)
    #define VCP_MORE_COMMAND_POPUP_BUTTON_GAP            (5)
    #define VCP_MORE_COMMAND_POPUP_BUTTON_WIDTH          (258)
    #define VCP_MORE_COMMAND_POPUP_BUTTON_HEIGHT         (47)

    #define VCP_MORE_COMMAND_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (359 + VCP_BUTTON_SHADOW_MARGIN_BOTTOM)
    #define VCP_MORE_COMMAND_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE     (255 + VCP_BUTTON_SHADOW_MARGIN_BOTTOM)

#endif    



/*****************************************************************************
 * Class VcpMoreCommandPopup
 *  VcpMoreCommandPopup is used to list more commands button for user to choose
 *  what command they will do. The tile of VcpMoreCommand is always string "More"
 *  . It can add at most 7 button in Cosmos project.
 * EXAMPLE
 * <code>
 *  VcpMoreCommandPopup *m_moreCommandPopup;
 *  VFX_OBJ_CREATE(m_moreCommandPopup, VcpMoreCommandPopup, this);
 *  m_moreCommandPopup->addItem('appl', VFX_WSTR("Apple"));
 *  m_moreCommandPopup->addItem('bird', VFX_WSTR("Bird"));
 *  m_moreCommandPopup->show(VFX_TRUE);
 * </code>
 *****************************************************************************/
class VcpMoreCommandPopup : public VfxBasePopup
{
// Constructor / Destructor
public:
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Constructor/Destructor>
    VcpMoreCommandPopup(); 

// Method
public:

    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Method>
    // add a new button. user can add 7 buttons at most.
    void addItem(
        VfxId id,                       // [IN] button id 
        const VfxWString &text,         // [IN] button text
        VcpPopupButtonTypeEnum type = VCP_POPUP_BUTTON_TYPE_NORMAL // [IN] button type
        );

	/* vaib mem reduction*/
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Method>
    // add a new button. user can add 7 buttons at most.
    void addItem(
        VfxId id,                       // [IN] button id 
        VfxResId text_id,         // [IN] button text
        VcpPopupButtonTypeEnum type = VCP_POPUP_BUTTON_TYPE_NORMAL // [IN] button type
        );

	/* vaib mem reduction*/
	// <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Method>
    // add a new button. user can add 7 buttons at most.
    void addItem(
        VfxId id,                       // [IN] button id 
        const VfxWChar* text_buf,         // [IN] button text
        VcpPopupButtonTypeEnum type = VCP_POPUP_BUTTON_TYPE_NORMAL // [IN] button type
        );
	
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Method>
    // disable a button item
    void disableItem(
        VfxId id                        // [IN] button id 
        );

// Override
protected:
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Override>
    virtual void onInit();
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Override>
    virtual void onUpdate();
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Override>
    virtual VfxBool onKeyInput(VfxKeyEvent & event);
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Override>
    virtual void onEnter();
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Override>
  //  virtual void onExit();
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Override>
    virtual void onLeaveStack();
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Override>
    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    );

// Implenmention
private:
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Implenmention>
   // void resetButton();
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Implenmention>
    void onButtonClick(VfxObject* sender, VfxId id);

// Event
public:
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Event>
    // This singal is invoked when button is clicked
    // void YourClass::onButtonClicked(VfxObject* sender, VfxId id)
    VfxSignal2 <
        VfxObject*,     // sender 
        VfxId           // id
    > m_signalButtonClicked;

// Variable    
protected:
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Variable>
    //VfxFrame                        *m_backgroundTop;
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Variable>
    VfxFrame                          *m_backgroundBottom;
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Variable>
    VfxFrame                        *m_backgroundBottomImage;
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Variable>
    VcpScrollable                     *m_buttonPanel;
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Variable>
   // VfxTextFrame                    *m_textFrame;
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Variable>
    //VcpPopupTypeEnum                m_infoType;
    VcpButton                       *m_button[7];
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Variable>
    VfxS32                          m_buttonCount;
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Variable>
   // VfxS32                          m_upRegionHeight;
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Variable>
   // VfxS32                          m_bottomRegionHeight;
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Variable>
  //  VfxS32                          m_panelHeight;
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Variable>
    VfxBool                         m_buttonPressed;  
    // <group DOM_MoreCommandPopup_VcpMoreCommandPopup_Variable>
    VfxS32                          m_cancelButtonIndex;   
};

#endif /* __VCP_POPUP_H__ */

