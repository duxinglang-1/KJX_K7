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
 *  vcp_indicator_popup.h
 *
 * Project:
 * --------
 *  Venus UI Component
 *
 * Description:
 * ------------
 *  Indicator Popup
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCP_INDICATOR_POPUP_H__
#define __VCP_INDICATOR_POPUP_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vcp_frame_effect.h"
#include "vcp_button.h"
#include "vcp_activity_indicator.h"
#include "vcp_text_editor.h"
#include "vcp_popup_data_type.h"

#if defined(__MMI_VUI_COSMOS_CP__) 

//////////////////////////////// VcpIndicatorPopup
#if defined(__MMI_MAINLCD_480X800__)
    #define VCP_INDICATOR_POPUP_WIDTH                   (446)
    #define VCP_INDICATOR_POPUP_MIN_HEIGHT              (131)      

    #define VCP_INDICATOR_POPUP_ACT_LEFT_MARGIN         (32)
    #define VCP_INDICATOR_POPUP_ACT_RIGHT_MARGIN        (32)
    #define VCP_INDICATOR_POPUP_LEFT_MARGIN             (21)
    #define VCP_INDICATOR_POPUP_RIGHT_MARGIN            (21)    
    #define VCP_INDICATOR_POPUP_TOP_MARGIN              (37)
    #define VCP_INDICATOR_POPUP_BOTTOM_MARGIN           (30)
    #define VCP_INDICATOR_POPUP_VERT_GAP                (20)
    #define VCP_INDICATOR_POPUP_SIDE_GAP                (14)
    #define VCP_INDICATOR_POPUP_ACT_IND_SIZE            (52)   

    #define VCP_INDICATOR_POPUP_CONTENT_WIDTH           VCP_INDICATOR_POPUP_WIDTH - (VCP_INDICATOR_POPUP_LEFT_MARGIN + VCP_INDICATOR_POPUP_RIGHT_MARGIN)

    #define VCP_INDICATOR_POPUP_FONT_SIZE               (30)
    #define VCP_INDICATOR_POPUP_TEXT_HEIGHT             (45)
    #define VCP_INDICATOR_POPUP_FONT_COLOR              VfxColor(255, 15, 15 , 15)

    #define VCP_INDICATOR_POPUP_BUTTON_WIDTH            VCP_INDICATOR_POPUP_CONTENT_WIDTH
    #define VCP_INDICATOR_POPUP_BUTTON_HEIGHT           (70)
    #define VCP_INDICATOR_POPUP_BUTTON_TEXT_LEFT_MARGIN (18)
#elif defined(__MMI_MAINLCD_320X480__)
    #define VCP_INDICATOR_POPUP_WIDTH                   (290)
    #define VCP_INDICATOR_POPUP_MIN_HEIGHT              (80)      

    #define VCP_INDICATOR_POPUP_ACT_LEFT_MARGIN         (15)
    #define VCP_INDICATOR_POPUP_ACT_RIGHT_MARGIN        (15)
    #define VCP_INDICATOR_POPUP_LEFT_MARGIN             (11)
    #define VCP_INDICATOR_POPUP_RIGHT_MARGIN            (11)    
    #define VCP_INDICATOR_POPUP_TOP_MARGIN              (24)
    #define VCP_INDICATOR_POPUP_BOTTOM_MARGIN           (19)
    #define VCP_INDICATOR_POPUP_VERT_GAP                (14)
    #define VCP_INDICATOR_POPUP_SIDE_GAP                (8)
    #define VCP_INDICATOR_POPUP_ACT_IND_SIZE            (32)   

    #define VCP_INDICATOR_POPUP_CONTENT_WIDTH            VCP_INDICATOR_POPUP_WIDTH - (VCP_INDICATOR_POPUP_LEFT_MARGIN + VCP_INDICATOR_POPUP_RIGHT_MARGIN)

    #define VCP_INDICATOR_POPUP_FONT_SIZE               (18)
    #define VCP_INDICATOR_POPUP_TEXT_HEIGHT             (25)
    #define VCP_INDICATOR_POPUP_FONT_COLOR              VfxColor(255, 15, 15 , 15)

    #define VCP_INDICATOR_POPUP_BUTTON_WIDTH            VCP_INDICATOR_POPUP_CONTENT_WIDTH
    #define VCP_INDICATOR_POPUP_BUTTON_HEIGHT           (47)
    #define VCP_INDICATOR_POPUP_BUTTON_TEXT_LEFT_MARGIN (15)
#elif defined(__MMI_MAINLCD_240X400__)
    #define VCP_INDICATOR_POPUP_WIDTH                   (222)
    #define VCP_INDICATOR_POPUP_MIN_HEIGHT              (67)   

    #define VCP_INDICATOR_POPUP_ACT_LEFT_MARGIN         (11)
    #define VCP_INDICATOR_POPUP_ACT_RIGHT_MARGIN        (11)
    #define VCP_INDICATOR_POPUP_LEFT_MARGIN             (3+8)   
    #define VCP_INDICATOR_POPUP_RIGHT_MARGIN            (3+8)   
    #define VCP_INDICATOR_POPUP_TOP_MARGIN              (17)
    #define VCP_INDICATOR_POPUP_BOTTOM_MARGIN           (7+13)  
    #define VCP_INDICATOR_POPUP_VERT_GAP                (8)
    #define VCP_INDICATOR_POPUP_SIDE_GAP                (5)
    #define VCP_INDICATOR_POPUP_ACT_IND_SIZE            (27)   

    #define VCP_INDICATOR_POPUP_CONTENT_WIDTH            VCP_INDICATOR_POPUP_WIDTH - (VCP_INDICATOR_POPUP_LEFT_MARGIN + VCP_INDICATOR_POPUP_RIGHT_MARGIN)

    #define VCP_INDICATOR_POPUP_FONT_SIZE               (16)
    #define VCP_INDICATOR_POPUP_TEXT_HEIGHT             (23)
    #define VCP_INDICATOR_POPUP_FONT_COLOR              VfxColor(255, 15, 15 , 15)

    #define VCP_INDICATOR_POPUP_BUTTON_WIDTH            VCP_INDICATOR_POPUP_CONTENT_WIDTH
    #define VCP_INDICATOR_POPUP_BUTTON_HEIGHT           (40)
    #define VCP_INDICATOR_POPUP_BUTTON_TEXT_LEFT_MARGIN (5)
#elif defined(__MMI_MAINLCD_240X320__)
    #define VCP_INDICATOR_POPUP_WIDTH                   (222)
    #define VCP_INDICATOR_POPUP_MIN_HEIGHT              (67)   

    #define VCP_INDICATOR_POPUP_ACT_LEFT_MARGIN         (11)
    #define VCP_INDICATOR_POPUP_ACT_RIGHT_MARGIN        (11)
    #define VCP_INDICATOR_POPUP_LEFT_MARGIN             (3+8)   
    #define VCP_INDICATOR_POPUP_RIGHT_MARGIN            (3+8)   
    #define VCP_INDICATOR_POPUP_TOP_MARGIN              (17)
    #define VCP_INDICATOR_POPUP_BOTTOM_MARGIN           (7+13)  
    #define VCP_INDICATOR_POPUP_VERT_GAP                (8)
    #define VCP_INDICATOR_POPUP_SIDE_GAP                (5)
    #define VCP_INDICATOR_POPUP_ACT_IND_SIZE            (27)   

    #define VCP_INDICATOR_POPUP_CONTENT_WIDTH            VCP_INDICATOR_POPUP_WIDTH - (VCP_INDICATOR_POPUP_LEFT_MARGIN + VCP_INDICATOR_POPUP_RIGHT_MARGIN)

    #define VCP_INDICATOR_POPUP_FONT_SIZE               (16)
    #define VCP_INDICATOR_POPUP_TEXT_HEIGHT             (23)
    #define VCP_INDICATOR_POPUP_FONT_COLOR              VfxColor(255, 15, 15 , 15)

    #define VCP_INDICATOR_POPUP_BUTTON_WIDTH            VCP_INDICATOR_POPUP_CONTENT_WIDTH
    #define VCP_INDICATOR_POPUP_BUTTON_HEIGHT           (40)
    #define VCP_INDICATOR_POPUP_BUTTON_TEXT_LEFT_MARGIN (5)
#else
    #define VCP_INDICATOR_POPUP_WIDTH                   (222)
    #define VCP_INDICATOR_POPUP_MIN_HEIGHT              (67)   

    #define VCP_INDICATOR_POPUP_ACT_LEFT_MARGIN         (11)
    #define VCP_INDICATOR_POPUP_ACT_RIGHT_MARGIN        (11)
    #define VCP_INDICATOR_POPUP_LEFT_MARGIN             (3+8)   
    #define VCP_INDICATOR_POPUP_RIGHT_MARGIN            (3+8)   
    #define VCP_INDICATOR_POPUP_TOP_MARGIN              (17)
    #define VCP_INDICATOR_POPUP_BOTTOM_MARGIN           (7+13)  
    #define VCP_INDICATOR_POPUP_VERT_GAP                (8)
    #define VCP_INDICATOR_POPUP_SIDE_GAP                (5)
    #define VCP_INDICATOR_POPUP_ACT_IND_SIZE            (27)   

    #define VCP_INDICATOR_POPUP_CONTENT_WIDTH            VCP_INDICATOR_POPUP_WIDTH - (VCP_INDICATOR_POPUP_LEFT_MARGIN + VCP_INDICATOR_POPUP_RIGHT_MARGIN)

    #define VCP_INDICATOR_POPUP_FONT_SIZE               (16)
    #define VCP_INDICATOR_POPUP_TEXT_HEIGHT             (23)
    #define VCP_INDICATOR_POPUP_FONT_COLOR              VfxColor(255, 15, 15 , 15)

    #define VCP_INDICATOR_POPUP_BUTTON_WIDTH            VCP_INDICATOR_POPUP_CONTENT_WIDTH
    #define VCP_INDICATOR_POPUP_BUTTON_HEIGHT           (40)
    #define VCP_INDICATOR_POPUP_BUTTON_TEXT_LEFT_MARGIN (5)
#endif

// <group DOM_IndicatorPopup_Macro&Enum_Enum>
enum VcpIndicatorPopupStyleEnum
{
     VCP_INDICATOR_POPUP_STYLE_NONE,
     VCP_INDICATOR_POPUP_STYLE_TEXT,                            // Popup with text only
     VCP_INDICATOR_POPUP_STYLE_TEXT_WITH_CANCEL_BUTTON,         // Popup with text with Cancel Button
     VCP_INDICATOR_POPUP_STYLE_ACTIVITY,                        // Popup with activity indicator
     VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON,     // Popup with activity indicator with Cancel button
     VCP_INDICATOR_POPUP_STYLE_PROGRESS,                        // Popup with progress indicator
     VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON,     // Popup with progress indicator with Cancel button
     VCP_INDICATOR_POPUP_STYLE_TOTAL
};


/*****************************************************************************
 * Class VcpIndicatorPopup
 *  Use Indicator popup objects to show an ongoing activity.
 *  It can use activity indicator or progress indicator to show the ongoing activity. 
 *****************************************************************************/
class VcpIndicatorPopup : public VfxBasePopup
{
// Constructor / Destructor
public:
    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Constructor/Destructor>
    // Constructor block.
    VcpIndicatorPopup(); 
// Method
public:
    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Method>
    // Sets the Popup type.
    void setInfoType(
        VcpIndicatorPopupStyleEnum type //[IN] Popup type
        );

    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Method>
    // Get Popup type enum value.
    // RETURNS :
    // Info type enum value.
    VcpIndicatorPopupStyleEnum getInfoType(void) const;

    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Method>
    // Sets popup text.
    void setText(
        const VfxWString &text          // [IN] text
        );

	/* vaib mem reduction*/
	// <group DOM_IndicatorPopup_VcpIndicatorPopup_Method>
    // Sets popup text.
    void setText(
        VfxResId text_id          // [IN] text
        );

	/* vaib mem reduction*/
	// <group DOM_IndicatorPopup_VcpIndicatorPopup_Method>
    // Sets popup text.
    void setText(
        const VfxWChar* text_buf          // [IN] text
        );

    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Method>
    // Gets popup text.
    // RETURNS :
    // Popup text string.
    const VfxWString& getText() const;

    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Method>
    // Sets progress value for progress Indicator.
    // RETURNS :
    // VFX_TRUE, if supplied value is set as current value successfully.
    VfxBool setProgress(
        VfxFloat progress_value         // [IN] information type
        );

    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Method>
    // Gets progress indicator's value.
    // RETURNS :
    // Current progress value.
    VfxFloat getProgress(void) const;
    
    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Method>
    // Sets Maximum Indicator progress value.
    // RETURNS :
    // VFX_TRUE, if supplied value is set as max value successfully.
    VfxBool setMaxProgress(
        VfxFloat progress_value         // [IN] Max value for progress
        );

    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Method>
    // Gets Max Indicator Progress value.
    // RETURNS :
    // Max progress value.
    VfxFloat getMaxProgress(void) const;

    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Method>
    // Progress bar animation toggle.
    void setIsAnimate(
        VfxBool isAnim              // [IN]  Animation required while setting the progress
        );

    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Method>
    // Returns the Progress bar animation state.
    // RETURNS :
    // Animation flag.
    VfxBool getIsAnimate() const;

    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Method>
    // Stops Progress bar internal frame animation.
    void pauseProgress();

    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Method>
    // Starts Progress bar internal frame animation.
    void resumeProgress();

// Event
public:
    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Method>
    // Button click event listener.
    void onButtonClick(
       VfxObject* sender,               // [IN] Indicator object
       VfxId id                         // [IN] Current progress value
       );

// Override
protected:
    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Override>
    virtual void onInit();
    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Override>
    virtual void onUpdate();
    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Override>
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Override>
    virtual void onRotate(const VfxScreenRotateParam &param);
    
public:
    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Override>
    virtual void onEnter();
    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Override>
    virtual void onExit();
    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Override>
    virtual void onLeaveStack();

// Signal    
public :
    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Event>
    // Fired when cancel button is pressed.
    VfxSignal2 <VfxObject*, VfxFloat > m_signalCanceled;

    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Event>
    // This singal is invoked when button is clicked
    VfxSignal2 <VfxObject*, VfxId > m_signalButtonClicked;

// Variable
protected:

    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Implementation>
    // Background Top where all objects are placed.
    VfxFrame                        *m_backgroundTop;

    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Implementation>
    // Background bottom where indicator is placed.
    VfxFrame                        *m_backgroundBottom;

    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Implementation>
    // Background Image to increase performance.
    VfxFrame                        *m_backgroundBottomImage;

    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Implementation>
    // Text frame
    VfxTextFrame                    *m_textFrame;

    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Implementation>
    // Popup type Activity/Progress and with/without Cancel button.
    VcpIndicatorPopupStyleEnum      m_popupType; 

    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Implementation>
    // Cancel button.
    VcpButton                       *m_button;

    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Implementation>
    // The indicator object.
    VcpProgressIndicator            *m_progressInd;

    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Implementation>
    // The indicator object.
    VcpActivityIndicator            *m_actInd;

    // <group DOM_IndicatorPopup_VcpIndicatorPopup_Implementation>
    VfxBool                         m_buttonPressed;    
};

#endif /* #if defined (__MMI_VUI_COSMOS_CP__)  */ 
#endif /* __VCP_INDICATOR_POPUP_H__ */

