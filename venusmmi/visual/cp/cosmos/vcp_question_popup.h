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
 *  vcp_question_popup.h
 *
 * Project:
 * --------
 *  Venus UI Component
 *
 * Description:
 * ------------
 *  Question popup
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
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCP_QUESTION_POPUP_H__
#define __VCP_QUESTION_POPUP_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vcp_frame_effect.h"
#include "vcp_button.h"
#include "vcp_text_editor.h"
#include "vcp_scrollable.h"
#include "vcp_popup_data_type.h"

#if defined(__MMI_VUI_COSMOS_CP__) 

// <group DOM_QuestionPopup_Macro&Enum_Macro>
// Maximum number of buttons on command popup.
#define VCP_QUESTION_POPUP_BUTTON_MAX_COUNT      (7)

#if defined(__MMI_MAINLCD_480X800__)
    #define VCP_QUESTION_POPUP_WIDTH_PORTRAIT               (446)
    #define VCP_QUESTION_POPUP_WIDTH_LANDSCAPE              (546)
    #define VCP_QUESTION_POPUP_UP_HEIGHT                    (45)
    #define VCP_QUESTION_POPUP_BOTTOM_HEIGHT                (30)
                         
    #define VCP_QUESTION_POPUP_TEXT_X                       (80)
    #define VCP_QUESTION_POPUP_TEXT_Y                       (37)
    #define VCP_QUESTION_POPUP_TEXT_WIDTH                   (346)
    #define VCP_QUESTION_POPUP_TEXT_WIDTH_LS                (446)
    #define VCP_QUESTION_POPUP_TEXT_SIZE                    (30)

    #define VCP_QUESTION_POPUP_ICON_X                       (42)
    #define VCP_QUESTION_POPUP_ICON_Y                       (62)
    #define VCP_QUESTION_POPUP_ICON_WIDTH                   (49)
    #define VCP_QUESTION_POPUP_ICON_HEIGHT                  (49)

    #define VCP_QUESTION_POPUP_BUTTON_Y_SHIFT               (10)
    #define VCP_QUESTION_POPUP_BUTTON_X                     (21)
    #define VCP_QUESTION_POPUP_BUTTON_Y                     (0)
    #define VCP_QUESTION_POPUP_BUTTON_GAP                   (10)
    #define VCP_QUESTION_POPUP_BUTTON_WIDTH_PORTRAIT        (404)
    #define VCP_QUESTION_POPUP_BUTTON_WIDTH_LANDSCAPE       (504)
    #define VCP_QUESTION_POPUP_BUTTON_HEIGHT                (70)
    
    #define VCP_QUESTION_POPUP_MAX_PANEL_HEIGHT_PORTRAIT    (547) 
    #define VCP_QUESTION_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE   (310)
#elif defined(__MMI_MAINLCD_320X480__)
    #define VCP_QUESTION_POPUP_WIDTH_PORTRAIT               (290)
    #define VCP_QUESTION_POPUP_WIDTH_LANDSCAPE              (340)
    #define VCP_QUESTION_POPUP_UP_HEIGHT                    (30)
    #define VCP_QUESTION_POPUP_BOTTOM_HEIGHT                (19)
                     
    #define VCP_QUESTION_POPUP_TEXT_X                       (69)
    #define VCP_QUESTION_POPUP_TEXT_Y                       (30)
    #define VCP_QUESTION_POPUP_TEXT_WIDTH                   (211)
    #define VCP_QUESTION_POPUP_TEXT_WIDTH_LS                (261)
    #define VCP_QUESTION_POPUP_TEXT_SIZE                    (18)

    #define VCP_QUESTION_POPUP_ICON_X                       (38)
    #define VCP_QUESTION_POPUP_ICON_Y                       (47)
    #define VCP_QUESTION_POPUP_ICON_WIDTH                   (33)
    #define VCP_QUESTION_POPUP_ICON_HEIGHT                  (33)

    #define VCP_QUESTION_POPUP_BUTTON_Y_SHIFT               (14)
    #define VCP_QUESTION_POPUP_BUTTON_X                     (11)
    #define VCP_QUESTION_POPUP_BUTTON_Y                     (0)
    #define VCP_QUESTION_POPUP_BUTTON_GAP                   (5)
    #define VCP_QUESTION_POPUP_BUTTON_WIDTH_PORTRAIT        (268)
    #define VCP_QUESTION_POPUP_BUTTON_WIDTH_LANDSCAPE       (318)
    #define VCP_QUESTION_POPUP_BUTTON_HEIGHT                (47)

    #define VCP_QUESTION_POPUP_MAX_PANEL_HEIGHT_PORTRAIT    (359)
    #define VCP_QUESTION_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE   (203)
#elif defined(__MMI_MAINLCD_240X400__)
    #define VCP_QUESTION_POPUP_WIDTH_PORTRAIT                (222)
    #define VCP_QUESTION_POPUP_WIDTH_LANDSCAPE               (242)
    #define VCP_QUESTION_POPUP_UP_HEIGHT                     (20)
    #define VCP_QUESTION_POPUP_BOTTOM_HEIGHT                 (13)
                     
    #define VCP_QUESTION_POPUP_TEXT_X                        (37)
    #define VCP_QUESTION_POPUP_TEXT_Y                        (17)
    #define VCP_QUESTION_POPUP_TEXT_WIDTH                    (177)
    #define VCP_QUESTION_POPUP_TEXT_WIDTH_LS                 (197)
    #define VCP_QUESTION_POPUP_TEXT_SIZE                     (16)

    #define VCP_QUESTION_POPUP_ICON_X                        (20)
    #define VCP_QUESTION_POPUP_ICON_Y                        (29)
    #define VCP_QUESTION_POPUP_ICON_WIDTH                    (24)
    #define VCP_QUESTION_POPUP_ICON_HEIGHT                   (24)

    #define VCP_QUESTION_POPUP_BUTTON_Y_SHIFT                (8)
    #define VCP_QUESTION_POPUP_BUTTON_X                      (8)
    #define VCP_QUESTION_POPUP_BUTTON_Y                      (0)
    #define VCP_QUESTION_POPUP_BUTTON_GAP                    (5)
    #define VCP_QUESTION_POPUP_BUTTON_WIDTH_PORTRAIT         (206)
    #define VCP_QUESTION_POPUP_BUTTON_WIDTH_LANDSCAPE        (226)
    #define VCP_QUESTION_POPUP_BUTTON_HEIGHT                 (40)

    #define VCP_QUESTION_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (310)
    #define VCP_QUESTION_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE    (175)
#elif defined        (__MMI_MAINLCD_240X320__)
    #define VCP_QUESTION_POPUP_WIDTH_PORTRAIT                (222)
    #define VCP_QUESTION_POPUP_WIDTH_LANDSCAPE               (242)
    #define VCP_QUESTION_POPUP_UP_HEIGHT                     (20)
    #define VCP_QUESTION_POPUP_BOTTOM_HEIGHT                 (13)
                         
    #define VCP_QUESTION_POPUP_TEXT_X                        (37)
    #define VCP_QUESTION_POPUP_TEXT_Y                        (17)
    #define VCP_QUESTION_POPUP_TEXT_WIDTH                    (177)
    #define VCP_QUESTION_POPUP_TEXT_WIDTH_LS                 (197)
    #define VCP_QUESTION_POPUP_TEXT_SIZE                     (16)

    #define VCP_QUESTION_POPUP_ICON_X                        (20)
    #define VCP_QUESTION_POPUP_ICON_Y                        (29)
    #define VCP_QUESTION_POPUP_ICON_WIDTH                    (24)
    #define VCP_QUESTION_POPUP_ICON_HEIGHT                   (24)

    #define VCP_QUESTION_POPUP_BUTTON_Y_SHIFT                (8)
    #define VCP_QUESTION_POPUP_BUTTON_X                      (8)
    #define VCP_QUESTION_POPUP_BUTTON_Y                      (0)
    #define VCP_QUESTION_POPUP_BUTTON_GAP                    (5)
    #define VCP_QUESTION_POPUP_BUTTON_WIDTH_PORTRAIT         (206)
    #define VCP_QUESTION_POPUP_BUTTON_WIDTH_LANDSCAPE        (226)
    #define VCP_QUESTION_POPUP_BUTTON_HEIGHT                 (40)
    
    #define VCP_QUESTION_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (220)
    #define VCP_QUESTION_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE    (175)
#else
    #define VCP_QUESTION_POPUP_WIDTH_PORTRAIT                (222)
    #define VCP_QUESTION_POPUP_WIDTH_LANDSCAPE               (242)
    #define VCP_QUESTION_POPUP_UP_HEIGHT                     (20)
    #define VCP_QUESTION_POPUP_BOTTOM_HEIGHT                 (13)
                         
    #define VCP_QUESTION_POPUP_TEXT_X                        (37)
    #define VCP_QUESTION_POPUP_TEXT_Y                        (17)
    #define VCP_QUESTION_POPUP_TEXT_WIDTH                    (117)
    #define VCP_QUESTION_POPUP_TEXT_WIDTH_LS                 (137)
    #define VCP_QUESTION_POPUP_TEXT_SIZE                     (16)

    #define VCP_QUESTION_POPUP_ICON_X                        (20)
    #define VCP_QUESTION_POPUP_ICON_Y                        (29)
    #define VCP_QUESTION_POPUP_ICON_WIDTH                    (24)
    #define VCP_QUESTION_POPUP_ICON_HEIGHT                   (24)

    #define VCP_QUESTION_POPUP_BUTTON_Y_SHIFT                (8)
    #define VCP_QUESTION_POPUP_BUTTON_X                      (8)
    #define VCP_QUESTION_POPUP_BUTTON_Y                      (0)
    #define VCP_QUESTION_POPUP_BUTTON_GAP                    (5)
    #define VCP_QUESTION_POPUP_BUTTON_WIDTH_PORTRAIT         (206)
    #define VCP_QUESTION_POPUP_BUTTON_WIDTH_LANDSCAPE        (226)
    #define VCP_QUESTION_POPUP_BUTTON_HEIGHT                 (40)
    
    #define VCP_QUESTION_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (265)
    #define VCP_QUESTION_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE    (175)
#endif    

/*****************************************************************************
 * Class VcpQuestionPopup
 *  VcpQuestionPopup show question popup. user can set its infoType to show different
 *  kinds of question popup. the infoType is the same as plutommi. it decide the 
 *  warning tone, image icon. User can also change those propertis by calling 
 *  correspond API. User can use addItem to add a new button.
 *
 * EXAMPLE
 * <code>
 *  VcpQuestionPopup *m_questionPopup;
 *  VFX_OBJ_CREATE(m_questionPopup, VcpQuestionPopup, this);
 *  m_questionPopup->setText(VFX_WSTR("You are FAIL!"));
 *  m_questionPopup->addItem('appl', VFX_WSTR("Apple"));
 *  m_questionPopup->addItem('bird', VFX_WSTR("Bird"));
 *  m_questionPopup->show(VFX_TRUE);
 * </code>
 *****************************************************************************/
class VcpQuestionPopup : public VfxBasePopup
{
// Constructor / Destructor
public:
    // <group DOM_QuestionPopup_VcpQuestionPopup_Constructor/Destructor>
    // Constructor block.    
    VcpQuestionPopup(); 

// Method
public:
    // <group DOM_QuestionPopup_VcpQuestionPopup_Method>
    // Sets popup text.
    void setText(
        const VfxWString &text          // [IN] text
        );

	/* vaib mem reduction*/
	// <group DOM_QuestionPopup_VcpQuestionPopup_Method>
    // Sets popup text.
    void setText(
        VfxResId text_id                  // [IN] text
        );

	/* vaib mem reduction*/
	// <group DOM_QuestionPopup_VcpQuestionPopup_Method>
    // Sets popup text.
    void setText(
        const VfxWChar* text_buf                  // [IN] text
        );
	
    // <group DOM_QuestionPopup_VcpQuestionPopup_Method>
    // To be removed.
    void setInfoType(
        VcpPopupTypeEnum type           // [IN] information type
        ){}
    
    // <group DOM_QuestionPopup_VcpQuestionPopup_Method>
    // Adds a new button. User can add 7 buttons at most.
    void addItem(
        VfxId id,                       // [IN] button id 
        const VfxWString &text,         // [IN] button text
        VcpPopupButtonTypeEnum type = VCP_POPUP_BUTTON_TYPE_NORMAL // [IN] button type
        );

	/* vaib mem reduction*/
	// <group DOM_QuestionPopup_VcpQuestionPopup_Method>
    // Adds a new button. User can add 7 buttons at most.
    void addItem(
        VfxId id,                       // [IN] button id 
        VfxResId text_id,         // [IN] button text
        VcpPopupButtonTypeEnum type = VCP_POPUP_BUTTON_TYPE_NORMAL // [IN] button type
        );

	/* vaib mem reduction*/
	// <group DOM_QuestionPopup_VcpQuestionPopup_Method>
    // Adds a new button. User can add 7 buttons at most.
    void addItem(
        VfxId id,                       // [IN] button id 
        const VfxWChar* text_buf,          // [IN] button text
        VcpPopupButtonTypeEnum type = VCP_POPUP_BUTTON_TYPE_NORMAL // [IN] button type
        );

    // <group DOM_QuestionPopup_VcpQuestionPopup_Method>
    // Enables a button.
    void enableItem(
        VfxId id                        // [IN] button id 
        );

    // <group DOM_QuestionPopup_VcpQuestionPopup_Method>
    // Disables a button.
    void disableItem(
        VfxId id                        // [IN] button id 
        );

    // <group DOM_QuestionPopup_VcpQuestionPopup_Method>
    // Gets popup text.
    // RETURNS :
    // Popup text string.
    const VfxWString& getText() const
    {
        return m_textFrame->getString();
    }

// Override
protected:
    // <group DOM_QuestionPopup_VcpQuestionPopup_Override>
    virtual void onInit();
    // <group DOM_QuestionPopup_VcpQuestionPopup_Override>
    virtual void onUpdate();
    // <group DOM_QuestionPopup_VcpQuestionPopup_Override>
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    // <group DOM_QuestionPopup_VcpQuestionPopup_Override>
    virtual void onEnter();
    // <group DOM_QuestionPopup_VcpQuestionPopup_Override>
    virtual void onExit();
    // <group DOM_QuestionPopup_VcpQuestionPopup_Override>
    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    );

// Implenmention
private:
    // <group DOM_QuestionPopup_VcpQuestionPopup_Implementation>
    void resetButton();
    // <group DOM_QuestionPopup_VcpQuestionPopup_Implementation>
    void onButtonClick(VfxObject* sender, VfxId id);

// Signal
public:
    // <group DOM_QuestionPopup_VcpQuestionPopup_Event>
    // This singal is invoked when button is clicked.
    // void YourClass::onButtonClicked(VfxObject* sender, VfxId id)
    VfxSignal2 <
        VfxObject*,     // sender 
        VfxId           // id
    > m_signalButtonClicked;

// Variable    
protected:
    // <group DOM_QuestionPopup_VcpQuestionPopup_Implementation>
    VfxFrame                        *m_backgroundTop;
    // <group DOM_QuestionPopup_VcpQuestionPopup_Implementation>
    VfxFrame                        *m_backgroundBottom;
    // <group DOM_QuestionPopup_VcpQuestionPopup_Implementation>
    VfxFrame                        *m_backgroundBottomImage;
    // <group DOM_QuestionPopup_VcpQuestionPopup_Implementation>
    VcpScrollable                     *m_buttonPanel;
    // <group DOM_QuestionPopup_VcpQuestionPopup_Implementation>
    VfxFrame                        *m_icon;
    // <group DOM_QuestionPopup_VcpQuestionPopup_Implementation>
    VfxTextFrame                    *m_textFrame;
    // <group DOM_QuestionPopup_VcpQuestionPopup_Implementation>
    //VcpPopupTypeEnum                m_infoType;
    // <group DOM_QuestionPopup_VcpQuestionPopup_Implementation>
    VcpButton                       *m_button[VCP_QUESTION_POPUP_BUTTON_MAX_COUNT];
    // <group DOM_QuestionPopup_VcpQuestionPopup_Implementation>
    VfxS32                          m_buttonCount;
    // <group DOM_QuestionPopup_VcpQuestionPopup_Implementation>
    VfxS32                          m_buttonWidth;
    // <group DOM_QuestionPopup_VcpQuestionPopup_Implementation>
    //VfxBool                         m_hasTitle;
    // <group DOM_QuestionPopup_VcpQuestionPopup_Implementation>
    //VfxBool                         m_hasIcon;
    // <group DOM_QuestionPopup_VcpQuestionPopup_Implementation>
    VfxS32                          m_textHeight;
    // <group DOM_QuestionPopup_VcpQuestionPopup_Implementation>
    VfxS32                          m_panelHeight;
    // <group DOM_QuestionPopup_VcpQuestionPopup_Implementation>
    VfxS32                          m_upRegionHeight;
    // <group DOM_QuestionPopup_VcpQuestionPopup_Implementation>
    VfxS32                          m_bottomRegionHeight;
    // <group DOM_QuestionPopup_VcpQuestionPopup_Implementation>
    //VfxS32                         m_highlightIndex;
    // <group DOM_QuestionPopup_VcpQuestionPopup_Implementation>
    VfxS32                         m_cancelButtonIndex;
    // <group DOM_QuestionPopup_VcpQuestionPopup_Implementation>
    VfxBool                         m_buttonPressed;    
};

#endif /* defined(__MMI_VUI_COSMOS_CP__) */

#endif /* __VCP_QUESTION_POPUP_H__ */

