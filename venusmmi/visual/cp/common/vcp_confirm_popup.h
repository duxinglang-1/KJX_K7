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
 *  vcp_confirm_popup.h
 *
 * Project:
 * --------
 *  Venus UI Component
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
See Email.

[Vaibhav, 05/08/2012]
Dear Jie,
Can u please help to check this issue. It is happening on LCD size FTE 320X240. For the confirm popup,we use the following background images:
Top image: \\mcu\plutommi\Customer\Images\FTE320x240\MainLCD\VUI\Shell\Components\Popup\Pop_BG_Top.9slice.png

Bottom Image:
\\mcu\plutommi\Customer\Images\FTE320x240\MainLCD\VUI\Shell\Components\Popup\Pop_BG_Bottom.9slice.png

Can u please specify the correct UI specs for this configuration. This is the new configuration and we are using default co-ordinate for this, which is creating issue.
So please help to provide correct co-ordinates.
In case of any issue, please let me know.
Thanks. 

[Sid, 05/04/2012] Dear Vaibhav,
Please help to check.
Thanks

[Herman 05/04]
Dear Siddhartha,
Could you please help to check the layout of confirm popup in FTE_LQVGA? Thank you!!



[Load Path][Load Path]\\mtksdd01.gslb.mediatek.inc\high_priority\sw_releases\W12.17\11B\official\CHAMPAGNE55N_V2_DEMO_GPRS(FTE_LQVGA)

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
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCP_CONFIRM_POPUP_H__
#define __VCP_CONFIRM_POPUP_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vcp_frame_effect.h"
#include "vcp_button.h"
//#include "vcp_waiting_icon.h"
//#include "cp\vcp_activity_indicator.h"
#include "vcp_text_editor.h"
//#include "vcp_textview.h"
//#include "vcp_scrollable.h"
#include "vcp_popup_data_type.h"
//#include "vcp_input_popup.h"

/////////////////////////////////// VcpConfirmPopup
#if defined(__MMI_MAINLCD_480X800__)
    #if defined(__MMI_VUI_COSMOS_CP__)
        #define VCP_CONFIRM_POPUP_SCREEN_WIDTH          (480)
        #define VCP_CONFIRM_POPUP_SCREEN_HEIGHT         (800)
        #define VCP_CONFIRM_POPUP_VERTICAL_ADJUSTMENT   (5)

        #define VCP_CONFIRM_POPUP_WIDTH                 (446)
        #define VCP_CONFIRM_POPUP_UP_HEIGHT             (37)
        #define VCP_CONFIRM_POPUP_BOTTOM_HEIGHT         (26)

        #define VCP_CONFIRM_POPUP_ICON_X                (42)
        #define VCP_CONFIRM_POPUP_ICON_Y                (62)
        #define VCP_CONFIRM_POPUP_ICON_WIDTH            (49)
        #define VCP_CONFIRM_POPUP_ICON_HEIGHT           (49)

        #define VCP_CONFIRM_POPUP_TEXT_X                (80)
        #define VCP_CONFIRM_POPUP_TEXT_Y                (37)
        #define VCP_CONFIRM_POPUP_TEXT_WIDTH            (349)
        #define VCP_CONFIRM_POPUP_TEXT_LEFT_MARGIN      (18)

        #define VCP_CONFIRM_POPUP_BUTTON_X              (21)
        #define VCP_CONFIRM_POPUP_BUTTON_Y              (20)
        #define VCP_CONFIRM_POPUP_BUTTON_GAP            (10)
        #define VCP_CONFIRM_POPUP_BUTTON_WIDTH          (404)
        #define VCP_CONFIRM_POPUP_BUTTON_HEIGHT         (70)
    #else
        #define VCP_CONFIRM_POPUP_SCREEN_WIDTH          (480)
        #define VCP_CONFIRM_POPUP_SCREEN_HEIGHT         (800)
        #define VCP_CONFIRM_POPUP_VERTICAL_ADJUSTMENT   (5)

        #define VCP_CONFIRM_POPUP_WIDTH                 (446)
        #define VCP_CONFIRM_POPUP_UP_HEIGHT             (37)
        #define VCP_CONFIRM_POPUP_BOTTOM_HEIGHT         (26)

        #define VCP_CONFIRM_POPUP_ICON_X                (42)
        #define VCP_CONFIRM_POPUP_ICON_Y                (62)
        #define VCP_CONFIRM_POPUP_ICON_WIDTH            (49)
        #define VCP_CONFIRM_POPUP_ICON_HEIGHT           (49)

        #define VCP_CONFIRM_POPUP_TEXT_X                (80)
        #define VCP_CONFIRM_POPUP_TEXT_Y                (37)
        #define VCP_CONFIRM_POPUP_TEXT_WIDTH            (349)
        #define VCP_CONFIRM_POPUP_TEXT_LEFT_MARGIN      (18)

        #define VCP_CONFIRM_POPUP_BUTTON_X              (21)
        #define VCP_CONFIRM_POPUP_BUTTON_Y              (20)
        #define VCP_CONFIRM_POPUP_BUTTON_GAP            (10)
        #define VCP_CONFIRM_POPUP_BUTTON_WIDTH          (404)
        #define VCP_CONFIRM_POPUP_BUTTON_HEIGHT         (70)
    #endif
#elif defined(__MMI_MAINLCD_320X480__)
    #if defined(__MMI_VUI_COSMOS_CP__)
        #define VCP_CONFIRM_POPUP_SCREEN_WIDTH          (320)
        #define VCP_CONFIRM_POPUP_SCREEN_HEIGHT         (480)
        #define VCP_CONFIRM_POPUP_VERTICAL_ADJUSTMENT   (5)

        #define VCP_CONFIRM_POPUP_WIDTH                 (290)
        #define VCP_CONFIRM_POPUP_UP_HEIGHT             (30)
        #define VCP_CONFIRM_POPUP_BOTTOM_HEIGHT         (19)
        
        #define VCP_CONFIRM_POPUP_ICON_X                (38)
        #define VCP_CONFIRM_POPUP_ICON_Y                (47)
        #define VCP_CONFIRM_POPUP_ICON_WIDTH            (33)
        #define VCP_CONFIRM_POPUP_ICON_HEIGHT           (33)
         
        #define VCP_CONFIRM_POPUP_TEXT_X                (69)
        #define VCP_CONFIRM_POPUP_TEXT_Y                (30)
        #define VCP_CONFIRM_POPUP_TEXT_WIDTH            (205)
        #define VCP_CONFIRM_POPUP_TEXT_LEFT_MARGIN      (15)
        
        #define VCP_CONFIRM_POPUP_BUTTON_X              (16)
        #define VCP_CONFIRM_POPUP_BUTTON_Y              (15)
        #define VCP_CONFIRM_POPUP_BUTTON_GAP            (5)
        #define VCP_CONFIRM_POPUP_BUTTON_WIDTH          (258)
        #define VCP_CONFIRM_POPUP_BUTTON_HEIGHT         (47)
    #else
        #define VCP_CONFIRM_POPUP_SCREEN_WIDTH          (320)
        #define VCP_CONFIRM_POPUP_SCREEN_HEIGHT         (480)
        #define VCP_CONFIRM_POPUP_VERTICAL_ADJUSTMENT   (5)

        #define VCP_CONFIRM_POPUP_WIDTH                 (278)
        #define VCP_CONFIRM_POPUP_UP_HEIGHT             (32)
        #define VCP_CONFIRM_POPUP_BOTTOM_HEIGHT         (22)
        
        #define VCP_CONFIRM_POPUP_ICON_X                (48)
        #define VCP_CONFIRM_POPUP_ICON_Y                (40)
        #define VCP_CONFIRM_POPUP_ICON_WIDTH            (41)
        #define VCP_CONFIRM_POPUP_ICON_HEIGHT           (41)
         
        #define VCP_CONFIRM_POPUP_TEXT_X                (82)
        #define VCP_CONFIRM_POPUP_TEXT_Y                (21)
        #define VCP_CONFIRM_POPUP_TEXT_WIDTH            (183)
        #define VCP_CONFIRM_POPUP_TEXT_LEFT_MARGIN      (10)
        
        #define VCP_CONFIRM_POPUP_BUTTON_X              (15)
        #define VCP_CONFIRM_POPUP_BUTTON_Y              (7)
        #define VCP_CONFIRM_POPUP_BUTTON_GAP            (4)
        #define VCP_CONFIRM_POPUP_BUTTON_WIDTH          (250)
        #define VCP_CONFIRM_POPUP_BUTTON_HEIGHT         (45)
    #endif
#elif defined(__MMI_MAINLCD_240X400__)
    #if defined(__MMI_VUI_COSMOS_CP__)
        #define VCP_CONFIRM_POPUP_SCREEN_WIDTH          (240)
        #define VCP_CONFIRM_POPUP_SCREEN_HEIGHT         (400)
        #define VCP_CONFIRM_POPUP_VERTICAL_ADJUSTMENT   (5)

        #define VCP_CONFIRM_POPUP_WIDTH                 (222)
        #define VCP_CONFIRM_POPUP_UP_HEIGHT             (17) 
        #define VCP_CONFIRM_POPUP_BOTTOM_HEIGHT         (13)
        
        #define VCP_CONFIRM_POPUP_ICON_X                (20)
        #define VCP_CONFIRM_POPUP_ICON_Y                (29)
        #define VCP_CONFIRM_POPUP_ICON_WIDTH            (24)
        #define VCP_CONFIRM_POPUP_ICON_HEIGHT           (24)
         
        #define VCP_CONFIRM_POPUP_TEXT_X                (37)
        #define VCP_CONFIRM_POPUP_TEXT_Y                (17)
        #define VCP_CONFIRM_POPUP_TEXT_WIDTH            (177)
        #define VCP_CONFIRM_POPUP_TEXT_LEFT_MARGIN      (5)
        
        #define VCP_CONFIRM_POPUP_BUTTON_X              (8) 
        #define VCP_CONFIRM_POPUP_BUTTON_Y              (8) 
        #define VCP_CONFIRM_POPUP_BUTTON_GAP            (5) 
        #define VCP_CONFIRM_POPUP_BUTTON_WIDTH          (206)
        #define VCP_CONFIRM_POPUP_BUTTON_HEIGHT         (40)
    #else
        #define VCP_CONFIRM_POPUP_SCREEN_WIDTH          (240)
        #define VCP_CONFIRM_POPUP_SCREEN_HEIGHT         (400)
        #define VCP_CONFIRM_POPUP_VERTICAL_ADJUSTMENT   (5)

        #define VCP_CONFIRM_POPUP_WIDTH                 (230)
        #define VCP_CONFIRM_POPUP_UP_HEIGHT             (32) 
        #define VCP_CONFIRM_POPUP_BOTTOM_HEIGHT         (19)
        
        #define VCP_CONFIRM_POPUP_ICON_X                (40)
        #define VCP_CONFIRM_POPUP_ICON_Y                (38)
        #define VCP_CONFIRM_POPUP_ICON_WIDTH            (34)
        #define VCP_CONFIRM_POPUP_ICON_HEIGHT           (34)
         
        #define VCP_CONFIRM_POPUP_TEXT_X                (67)
        #define VCP_CONFIRM_POPUP_TEXT_Y                (21)
        #define VCP_CONFIRM_POPUP_TEXT_WIDTH            (139)
        #define VCP_CONFIRM_POPUP_TEXT_LEFT_MARGIN      (10)
        
        #define VCP_CONFIRM_POPUP_BUTTON_X              (15) 
        #define VCP_CONFIRM_POPUP_BUTTON_Y              (5) 
        #define VCP_CONFIRM_POPUP_BUTTON_GAP            (1) 
        #define VCP_CONFIRM_POPUP_BUTTON_WIDTH          (202)
        #define VCP_CONFIRM_POPUP_BUTTON_HEIGHT         (45)
    #endif    
#elif defined(__MMI_MAINLCD_240X320__)
    #if defined(__MMI_VUI_COSMOS_CP__)
        #define VCP_CONFIRM_POPUP_SCREEN_WIDTH          (240)
        #define VCP_CONFIRM_POPUP_SCREEN_HEIGHT         (320)
        #define VCP_CONFIRM_POPUP_VERTICAL_ADJUSTMENT   (5)

        #define VCP_CONFIRM_POPUP_WIDTH                 (222)
        #define VCP_CONFIRM_POPUP_UP_HEIGHT             (17) 
        #define VCP_CONFIRM_POPUP_BOTTOM_HEIGHT         (13)

        #define VCP_CONFIRM_POPUP_ICON_X                (20)
        #define VCP_CONFIRM_POPUP_ICON_Y                (29)
        #define VCP_CONFIRM_POPUP_ICON_WIDTH            (24)
        #define VCP_CONFIRM_POPUP_ICON_HEIGHT           (24)

        #define VCP_CONFIRM_POPUP_TEXT_X                (37)
        #define VCP_CONFIRM_POPUP_TEXT_Y                (17)
        #define VCP_CONFIRM_POPUP_TEXT_WIDTH            (177)
        #define VCP_CONFIRM_POPUP_TEXT_LEFT_MARGIN      (5)

        #define VCP_CONFIRM_POPUP_BUTTON_X              (8) 
        #define VCP_CONFIRM_POPUP_BUTTON_Y              (8) 
        #define VCP_CONFIRM_POPUP_BUTTON_GAP            (5) 
        #define VCP_CONFIRM_POPUP_BUTTON_WIDTH          (206)
        #define VCP_CONFIRM_POPUP_BUTTON_HEIGHT         (40)
    #else
        #define VCP_CONFIRM_POPUP_SCREEN_WIDTH          (240)
        #define VCP_CONFIRM_POPUP_SCREEN_HEIGHT         (320)
        #define VCP_CONFIRM_POPUP_VERTICAL_ADJUSTMENT   (5)

        #define VCP_CONFIRM_POPUP_WIDTH                 (230)
        #define VCP_CONFIRM_POPUP_UP_HEIGHT             (32) 
        #define VCP_CONFIRM_POPUP_BOTTOM_HEIGHT         (19)
        
        #define VCP_CONFIRM_POPUP_ICON_X                (40)
        #define VCP_CONFIRM_POPUP_ICON_Y                (38)
        #define VCP_CONFIRM_POPUP_ICON_WIDTH            (34)
        #define VCP_CONFIRM_POPUP_ICON_HEIGHT           (34)
         
        #define VCP_CONFIRM_POPUP_TEXT_X                (67)
        #define VCP_CONFIRM_POPUP_TEXT_Y                (21)
        #define VCP_CONFIRM_POPUP_TEXT_WIDTH            (139)
        #define VCP_CONFIRM_POPUP_TEXT_LEFT_MARGIN      (10)
        
        #define VCP_CONFIRM_POPUP_BUTTON_X              (15) 
        #define VCP_CONFIRM_POPUP_BUTTON_Y              (5) 
        #define VCP_CONFIRM_POPUP_BUTTON_GAP            (1) 
        #define VCP_CONFIRM_POPUP_BUTTON_WIDTH          (202)
        #define VCP_CONFIRM_POPUP_BUTTON_HEIGHT         (45)
    #endif
#elif defined(__MMI_MAINLCD_320X240__)
	#if !defined(__MMI_VUI_COSMOS_CP__)
		#define VCP_CONFIRM_POPUP_SCREEN_WIDTH          (320)
        #define VCP_CONFIRM_POPUP_SCREEN_HEIGHT         (240)
        #define VCP_CONFIRM_POPUP_VERTICAL_ADJUSTMENT   (5)
        #define VCP_CONFIRM_POPUP_WIDTH                 (280)
        #define VCP_CONFIRM_POPUP_UP_HEIGHT             (25) 
        #define VCP_CONFIRM_POPUP_BOTTOM_HEIGHT         (13)
        #define VCP_CONFIRM_POPUP_ICON_X                (48)
        #define VCP_CONFIRM_POPUP_ICON_Y                (35)
        #define VCP_CONFIRM_POPUP_ICON_WIDTH            (34)
        #define VCP_CONFIRM_POPUP_ICON_HEIGHT           (34)
        #define VCP_CONFIRM_POPUP_TEXT_X                (82)
        #define VCP_CONFIRM_POPUP_TEXT_Y                (21)
        #define VCP_CONFIRM_POPUP_TEXT_WIDTH            (183)
        #define VCP_CONFIRM_POPUP_TEXT_LEFT_MARGIN      (10)
        #define VCP_CONFIRM_POPUP_BUTTON_X              (15) 
        #define VCP_CONFIRM_POPUP_BUTTON_Y              (5) 
        #define VCP_CONFIRM_POPUP_BUTTON_GAP            (1) 
        #define VCP_CONFIRM_POPUP_BUTTON_WIDTH          (250)
        #define VCP_CONFIRM_POPUP_BUTTON_HEIGHT         (43)
	#endif
#else
    #define VCP_CONFIRM_POPUP_SCREEN_WIDTH          (240)
    #define VCP_CONFIRM_POPUP_SCREEN_HEIGHT         (320)
    #define VCP_CONFIRM_POPUP_VERTICAL_ADJUSTMENT   (5)

    #define VCP_CONFIRM_POPUP_WIDTH                 (222)
    #define VCP_CONFIRM_POPUP_UP_HEIGHT             (17) 
    #define VCP_CONFIRM_POPUP_BOTTOM_HEIGHT         (13)
    
    #define VCP_CONFIRM_POPUP_ICON_X                (20)
    #define VCP_CONFIRM_POPUP_ICON_Y                (29)
    #define VCP_CONFIRM_POPUP_ICON_WIDTH            (24)
    #define VCP_CONFIRM_POPUP_ICON_HEIGHT           (24)
    
    #define VCP_CONFIRM_POPUP_TEXT_X                (37)
    #define VCP_CONFIRM_POPUP_TEXT_Y                (17)
    #define VCP_CONFIRM_POPUP_TEXT_WIDTH            (177)
    #define VCP_CONFIRM_POPUP_TEXT_LEFT_MARGIN      (5)
    
    #define VCP_CONFIRM_POPUP_BUTTON_X              (8) 
    #define VCP_CONFIRM_POPUP_BUTTON_Y              (8) 
    #define VCP_CONFIRM_POPUP_BUTTON_GAP            (5) 
    #define VCP_CONFIRM_POPUP_BUTTON_WIDTH          (206)
    #define VCP_CONFIRM_POPUP_BUTTON_HEIGHT         (40)
#endif

#define VCP_CONFIRM_POPUP_BUTTON_MARGIN_SET 6, 5, 7, 7

#define VCP_CONFIRM_POPUP_CALC_HEIGHT_PORTRAIT \
    (VCP_CONFIRM_POPUP_SCREEN_HEIGHT \
                    - VCP_CONFIRM_POPUP_VERTICAL_ADJUSTMENT \
                    - VCP_CONFIRM_POPUP_UP_HEIGHT \
                    - VCP_CONFIRM_POPUP_BUTTON_Y \
                    - VCP_CONFIRM_POPUP_BUTTON_HEIGHT \
                    - VCP_CONFIRM_POPUP_BOTTOM_HEIGHT)

#define VCP_CONFIRM_POPUP_CALC_HEIGHT_LANDSCAPE \
    (VCP_CONFIRM_POPUP_SCREEN_WIDTH \
                    - VCP_CONFIRM_POPUP_VERTICAL_ADJUSTMENT \
                    - VCP_CONFIRM_POPUP_UP_HEIGHT \
                    - VCP_CONFIRM_POPUP_BUTTON_Y \
                    - VCP_CONFIRM_POPUP_BUTTON_HEIGHT \
                    - VCP_CONFIRM_POPUP_BOTTOM_HEIGHT)

#define     VCP_CONFIRM_POPUP_BUTTON_NONE       (0)

// <group DOM_ConfirmPopup_Macro&Enum_Macro>
// If button set used, is VCP_CONFIRM_BUTTON_SET_OK, popup emits this button ID when button is pressed.
#define     VCP_CONFIRM_POPUP_BUTTON_OK         ('OK')

// <group DOM_ConfirmPopup_Macro&Enum_Macro>
// If button set used, is VCP_CONFIRM_BUTTON_SET_CANCEL, popup emits this button ID when button is pressed.
#define     VCP_CONFIRM_POPUP_BUTTON_CANCEL     ('NoOK')

// <group DOM_ConfirmPopup_Macro&Enum_Macro>
// If button set used, is VCP_CONFIRM_BUTTON_SET_YES_NO, popup emits this button ID when "Yes" button is pressed. 
#define     VCP_CONFIRM_POPUP_BUTTON_YES        ('YES')

// <group DOM_ConfirmPopup_Macro&Enum_Macro>
// If button set used, is VCP_CONFIRM_BUTTON_SET_OK, popup emits this button ID when "No" button is pressed. 
#define     VCP_CONFIRM_POPUP_BUTTON_NO         ('NO')

// <group DOM_ConfirmPopup_Macro&Enum_Macro>
// If button set used, is VCP_CONFIRM_BUTTON_SET_USER_DEFINE, popup emits this button ID when first button is pressed. 
#define     VCP_CONFIRM_POPUP_BUTTON_USER_1     ('USR1')

// <group DOM_ConfirmPopup_Macro&Enum_Macro>
// If button set used, is VCP_CONFIRM_BUTTON_SET_USER_DEFINE, popup emits this button ID when second button is pressed. 
#define     VCP_CONFIRM_POPUP_BUTTON_USER_2     ('USR2')


// <group DOM_ConfirmPopup_Macro&Enum_Enum>
enum VcpConfirmPopupButtonSetEnum
{
    VCP_CONFIRM_BUTTON_SET_NONE,
    VCP_CONFIRM_BUTTON_SET_OK,              // One Button with "Ok" label.
    VCP_CONFIRM_BUTTON_SET_CANCEL,          // One Button with "Cancel" label.
    VCP_CONFIRM_BUTTON_SET_YES_NO,          // Two Buttons with "Yes" and "No" label.
    VCP_CONFIRM_BUTTON_SET_USER_DEFINE,     // Two Buttons with customised labels.
    VCP_CONFIRM_BUTTON_SET_END_OF_ENUM      
};


/*****************************************************************************
 * Class VcpConfirmPopup
 *  VcpConfirmPopup show confirm popup. user can set its infoType to show different
 *  kinds of confirm popup. the infoType is the same as plutommi. it decide the 
 *  warning tone, image icon. User can also change those propertis by calling 
 *  correspond API. User can use setButtonSet to create default confirm button 
 *  or use setCustomButton to create custom button.
 *
 * EXAMPLE
 * <code>
 *  VcpConfirmPopup *m_confirmPopup;
 *  VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
 *  m_confirmPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
 *  m_confirmPopup->setText(VFX_WSTR("You are FAIL!"));
 *  m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
 *  m_confirmPopup->show(VFX_TRUE);
 * </code>
 *****************************************************************************/
class VcpConfirmPopup : public VfxBasePopup
{
   VFX_DECLARE_CLASS(VcpConfirmPopup);
// Constructor / Destructor
public:
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Constructor/Destructor>
    // Constructor block.
    VcpConfirmPopup(); 

// Method
public:
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Method>
    // Sets popup text.
    void setText(
        const VfxWString &text                  // [IN] text
        );

	/* vaib mem reduction*/
	// <group DOM_ConfirmPopup_VcpConfirmPopup_Method>
    // Sets popup text.
    void setText(
        VfxResId text_id                  // [IN] text
        );

	/* vaib mem reduction*/
	// <group DOM_ConfirmPopup_VcpConfirmPopup_Method>
    // Sets popup text.
    void setText(
        const VfxWChar* text_buf                  // [IN] text
        );
	
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Method>
    // Sets font for popup text.
    void setTextFont(
        const VfxFontDesc &font // [IN] text font description
        );

    // <group DOM_ConfirmPopup_VcpConfirmPopup_Method>
    // Sets info type to choose waring tone.
    void setInfoType(
        VcpPopupTypeEnum type                   // [IN] information type
        );

    // <group DOM_ConfirmPopup_VcpConfirmPopup_Method>
    // Sets custom buttom, user can set at most 2 buttons.
    // Use button type enum to change the button appearence.
    void setCustomButton(
        const VfxWString &btnText1,                                // [IN] button 1 text
        const VfxWString &btnText2,                                 // [IN] button 2 text
        VcpPopupButtonTypeEnum type1 = VCP_POPUP_BUTTON_TYPE_NORMAL, // [IN] button type
        VcpPopupButtonTypeEnum type2 = VCP_POPUP_BUTTON_TYPE_NORMAL // [IN] button type
        );

	/* vaib mem reduction*/
	// <group DOM_ConfirmPopup_VcpConfirmPopup_Method>
    // Sets custom buttom, user can set at most 2 buttons.
    // Use button type enum to change the button appearence.
    void setCustomButton(
        VfxResId btnText1_id,                                // [IN] button 1 text
        VfxResId btnText2_id,                                 // [IN] button 2 text
        VcpPopupButtonTypeEnum type1 = VCP_POPUP_BUTTON_TYPE_NORMAL, // [IN] button type
        VcpPopupButtonTypeEnum type2 = VCP_POPUP_BUTTON_TYPE_NORMAL // [IN] button type
        );

	/* vaib mem reduction*/
	// <group DOM_ConfirmPopup_VcpConfirmPopup_Method>
    // Sets custom buttom, user can set at most 2 buttons.
    // Use button type enum to change the button appearence.
    void setCustomButton(
        const VfxWChar* btnText1_buf,                                // [IN] button 1 text
        const VfxWChar* btnText2_buf,                                 // [IN] button 2 text
        VcpPopupButtonTypeEnum type1 = VCP_POPUP_BUTTON_TYPE_NORMAL, // [IN] button type
        VcpPopupButtonTypeEnum type2 = VCP_POPUP_BUTTON_TYPE_NORMAL // [IN] button type
        );
	
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Method>
    // Sets default button set.
    void setButtonSet(
        VcpConfirmPopupButtonSetEnum buttonSet  // [IN] button set
        );

    // <group DOM_ConfirmPopup_VcpConfirmPopup_Method>
    // Gets popup text.
    // RETURNS :
    // Popup text string.
    const VfxWString& getText() const
    {
        return m_textFrame->getString();
    }

    // <group DOM_ConfirmPopup_VcpConfirmPopup_Method>
    // Gets text font.
    // RETURNS :
    // Popup text font.
    const VfxFontDesc &getTextFont()
    {
        return m_textFrame->getFont();
    }

    // <group DOM_ConfirmPopup_VcpConfirmPopup_Method>
    // Gets popup info type.
    // RETURNS :
    // Info type enum.
    VcpPopupTypeEnum getInfoType()
    {
        return m_infoType;
    }
    
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Method>
    // Sets icon image.
    void setImage(
        const VfxImageSrc &imgScr         // [IN] image
        );
    
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Method>
    // Sets text alignment mode.
    void setTextAlignMode(
        VfxTextFrame::AlignModeEnum value // [IN] text Alignment mode
        );

#if defined(__MMI_VUI_COSMOS_CP__)
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Method>
    // Enables/disables the tone play. Only used by global popup.
    void setIsPlayTone(
        VfxBool option                          // [IN] Whether to play the tone or not
        );
#endif

// override
protected:
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Override>
    // Initialize block.
    virtual void onInit();
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Override>
    // Update block.
    virtual void onUpdate();

    // <group DOM_ConfirmPopup_VcpConfirmPopup_Override>
    // Called from base popup when popup is entering.
    virtual void onEnter();
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Override>
    // Called from base popup when popup is exiting.
    virtual void onExit();
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Override>
    // Called from base popup when popup is popped from the popup stack.
    virtual void onLeaveStack();
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Override>
    // Override rotate event.
    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    );

	// <group DOM_ConfirmPopup_VcpConfirmPopup_Override>
    // Called from base popup when playing Tone starts.
    virtual void onPlayTone();
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Override>
    // Called from base popup when playing Tone stops.
    virtual void onStopTone();

	// <group DOM_ConfirmPopup_VcpConfirmPopup_Override>
    virtual void onPenInputOnOutside(VfxPenEvent &event);
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Override>
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

// Implenmention
private:
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Implementation>
    void resetButton();
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Implementation>
    void onButtonClick(VfxObject* sender, VfxId id);

// Signal
public:
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Event>
    // This singal is invoked when button is clicked.
    // void YourClass::onButtonClicked(VfxObject* sender, VfxId id)
    VfxSignal2 <
        VfxObject*,     // sender 
        VfxId           // id
    > m_signalButtonClicked;

// Variable
protected:
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Implementation>
    // Top frame for background.
    VfxFrame                        *m_backgroundTop;
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Implementation>
    // Bottom frame for background.
    VfxFrame                        *m_backgroundBottom;
#if defined(__MMI_VUI_COSMOS_CP__) 
    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    VfxFrame                        *m_backgroundBottomImage;
#endif
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Implementation>
    VfxFrame                        *m_icon;
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Implementation>
    VfxTextFrame                    *m_textFrame;
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Implementation>
    VcpPopupTypeEnum                m_infoType;
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Implementation>
    VcpConfirmPopupButtonSetEnum    m_buttonSet;
    VcpButton                       *m_button[2];
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Implementation>
    VfxS32                          m_textHeight;
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Implementation>
    VfxS32                          m_upRegionHeight;
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Implementation>
    VfxS32                          m_bottomRegionHeight;    
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Implementation>
    VfxS32                          m_cancelButtonIndex;
#if defined(__MMI_VUI_COSMOS_CP__)
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Implementation>
    VfxBool                         m_isPlayTone;
#endif
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Implementation>
    VfxBool                         m_buttonPressed;
};

#endif /* __VCP_CONFIRM_POPUP_H__ */

