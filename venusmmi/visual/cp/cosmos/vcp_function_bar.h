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
 *  vcp_function_bar.h
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Function bar component header
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_FUNCTION_BAR_H__
#define __VCP_FUNCTION_BAR_H__

#include "mmi_features.h"

#if defined(__MMI_VUI_COSMOS_CP__)

#include "mmi_core\vfx_page_bar.h"

/***************************************************************************** 
 * Include
 *****************************************************************************/



/***************************************************************************** 
 * Define
 *****************************************************************************/

// <group DOM_FunctionBar_Macro&Enum_Macro>
// Maximum nuber of buttons.
#define VCP_FUNCTION_BAR_MAX_BUTTONS_COUNT              (4)

//#define VCP_FUNCTION_BAR_BUTTON_FONT_COLOR              (VfxColor(255, 21, 21, 21))
//#define VCP_FUNCTION_BAR_BUTTON_FONT_COLOR_SPECIAL      (VfxColor(255, 255, 255, 255))

// Coordinates
#ifdef __MMI_MAINLCD_480X800__
    #define VCP_FUNCTION_BAR_WIDTH                  (480)
    #define VCP_FUNCTION_BAR_WIDTH_LANDSCAPE        (800)
    #define VCP_FUNCTION_BAR_HEIGHT                 (70)
    #define VCP_FUNCTION_BAR_BUTTON_HEIGHT          (60)
    #define VCP_FUNCTION_BAR_BUTTON_FONT_SIZE       (26)
    #define VCP_FUNCTION_BAR_BUTTON_OFFSET          (10)
    #define VCP_FUNCTION_BAR_BUTTON_GAP             (4)
    #define VCP_FUNCTION_BAR_BUTTON_LEFT_MARGIN     (10)
    #define VCP_FUNCTION_BAR_BUTTON_RIGHT_MARGIN    (10)
#elif defined(__MMI_MAINLCD_320X480__)
    #define VCP_FUNCTION_BAR_WIDTH                  (320)
    #define VCP_FUNCTION_BAR_WIDTH_LANDSCAPE        (480)
    #define VCP_FUNCTION_BAR_HEIGHT                 (46)
    #define VCP_FUNCTION_BAR_BUTTON_HEIGHT          (40)
    #define VCP_FUNCTION_BAR_BUTTON_FONT_SIZE       (16)
    #define VCP_FUNCTION_BAR_BUTTON_OFFSET          (5)
    #define VCP_FUNCTION_BAR_BUTTON_GAP             (3)
    #define VCP_FUNCTION_BAR_BUTTON_LEFT_MARGIN     (6)
    #define VCP_FUNCTION_BAR_BUTTON_RIGHT_MARGIN    (6)
#elif defined(__MMI_MAINLCD_240X400__)
    #define VCP_FUNCTION_BAR_WIDTH                  (240)
    #define VCP_FUNCTION_BAR_WIDTH_LANDSCAPE        (400)
    #define VCP_FUNCTION_BAR_HEIGHT                 (42)
    #define VCP_FUNCTION_BAR_BUTTON_HEIGHT          (38)
    #define VCP_FUNCTION_BAR_BUTTON_FONT_SIZE       (13)
    #define VCP_FUNCTION_BAR_BUTTON_OFFSET          (4)
    #define VCP_FUNCTION_BAR_BUTTON_GAP             (2)
    #define VCP_FUNCTION_BAR_BUTTON_LEFT_MARGIN     (5)
    #define VCP_FUNCTION_BAR_BUTTON_RIGHT_MARGIN    (5)
#elif defined(__MMI_MAINLCD_240X320__)
    #define VCP_FUNCTION_BAR_WIDTH                  (240)
    #define VCP_FUNCTION_BAR_WIDTH_LANDSCAPE        (320)
    #define VCP_FUNCTION_BAR_HEIGHT                 (42)
    #define VCP_FUNCTION_BAR_BUTTON_HEIGHT          (38)
    #define VCP_FUNCTION_BAR_BUTTON_FONT_SIZE       (13)
    #define VCP_FUNCTION_BAR_BUTTON_OFFSET          (4)
    #define VCP_FUNCTION_BAR_BUTTON_GAP             (2)
    #define VCP_FUNCTION_BAR_BUTTON_LEFT_MARGIN     (5)
    #define VCP_FUNCTION_BAR_BUTTON_RIGHT_MARGIN    (5)
#else 
    #define VCP_FUNCTION_BAR_WIDTH                  (240)
    #define VCP_FUNCTION_BAR_WIDTH_LANDSCAPE        (320)
    #define VCP_FUNCTION_BAR_HEIGHT                 (42)
    #define VCP_FUNCTION_BAR_BUTTON_HEIGHT          (38)
    #define VCP_FUNCTION_BAR_BUTTON_FONT_SIZE       (14)
    #define VCP_FUNCTION_BAR_BUTTON_OFFSET          (4)
    #define VCP_FUNCTION_BAR_BUTTON_GAP             (2)
    #define VCP_FUNCTION_BAR_BUTTON_LEFT_MARGIN     (5)
    #define VCP_FUNCTION_BAR_BUTTON_RIGHT_MARGIN    (5)
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef enum
{
    VCP_FUNCTION_BAR_LAYOUT_PORTRAIT,
    VCP_FUNCTION_BAR_LAYOUT_LANDSCAPE,
    VCP_FUNCTION_BAR_LAYOUT_TOTAL
}VcpFunctionBarLayoutEnum;


/*****************************************************************************
 * Class VcpFunctionBar
 *****************************************************************************/

/*
 * This bar has max 4 buttons.
 * FunctionBar displays above the VK.
 *
 * EXAMPLE:
 * <code>
 *   VFX_OBJ_CREATE(m_function_bar, VcpFunctionBar, this);
 *   m_function_bar->addItem(APP_BUTTON_CUT_ID, VFX_WSTR("Cut"));
 * </code>
 */
class VcpFunctionBar : public VfxFrame
{
    VFX_DECLARE_CLASS(VcpFunctionBar);
public:
    // <group DOM_FunctionBar_VcpFunctionBar_Constructor/Destructor>
    // Default constructor.
    VcpFunctionBar();

public:
    // <group DOM_FunctionBar_VcpFunctionBar_Method>
    // Adds a button with String.
    // RETURNS :
    // VFX_TRUE, if button was added. VFX_FALSE, if max buttons are added.
    VfxBool addItem(
        VfxId button_id,                        // [IN]  Unique ID of button 
        const VfxWString &button_string        // [IN] String to show on the button
    );

	/* vaib mem reduction */
	// Order of parameters are changed, otherwise it would have same signature as of  addItem(VfxId button_id, VfxResId button_icon)
	// <group DOM_FunctionBar_VcpFunctionBar_Method>
    // Adds a button with String.
    // RETURNS :
    // VFX_TRUE, if button was added. VFX_FALSE, if max buttons are added.
    VfxBool addItem(
        VfxResId button_string,        // [IN] String to show on the button
        VfxId button_id                        // [IN]  Unique ID of button 
    );

	/* vaib mem reduction */
	// <group DOM_FunctionBar_VcpFunctionBar_Method>
    // Adds a button with String.
    // RETURNS :
    // VFX_TRUE, if button was added. VFX_FALSE, if max buttons are added.
    VfxBool addItem(
        VfxId button_id,                        // [IN]  Unique ID of button 
        const VfxWChar* button_string        // [IN] String to show on the button
    );

    // <group DOM_FunctionBar_VcpFunctionBar_Method>
    // Adds a button with an Icon.
    // RETURNS :
    // VFX_TRUE, if button was added. VFX_FALSE, if max buttons are added.
    VfxBool addItem(
        VfxId button_id,                        // [IN]  Unique ID of button 
        VfxResId button_icon        // [IN] Image to show on the button
    );

    // <group DOM_FunctionBar_VcpFunctionBar_Method>
    // Changes a button's string.
    // RETURNS :
    // VFX_FALSE, if button ID not found. VFX_TRUE, if string changed successfully.
    VfxBool changeItem(
        VfxId buttonId,                     // [IN]  Unique ID of button 
        const VfxWString &buttonString      // [IN]  New string to show on the button 
    );

	/* vaib mem reduction */
	// Order of parameters are changed, otherwise it would have same signature as of  changeItem(VfxId buttonId, VfxResId buttonIcon)
     // <group DOM_FunctionBar_VcpFunctionBar_Method>
    // Changes a button's string.
    // RETURNS :
    // VFX_FALSE, if button ID not found. VFX_TRUE, if string changed successfully.
    VfxBool changeItem(
    	VfxResId buttonString,      // [IN]  New string to show on the button 
        VfxId buttonId                     // [IN]  Unique ID of button 
        
    );

	/* vaib mem reduction */
     // <group DOM_FunctionBar_VcpFunctionBar_Method>
    // Changes a button's string.
    // RETURNS :
    // VFX_FALSE, if button ID not found. VFX_TRUE, if string changed successfully.
    VfxBool changeItem(
        VfxId buttonId,                     // [IN]  Unique ID of button 
        const VfxWChar* buttonString      // [IN]  New string to show on the button 
    );

    // <group DOM_FunctionBar_VcpFunctionBar_Method>
    // Changes a button's image.
    // RETURNS :
    // VFX_FALSE, if button ID not found. VFX_TRUE, if icon changed successfully.
    VfxBool changeItem(
        VfxId buttonId,                     // [IN]  Unique ID of button 
        VfxResId buttonIcon                 // [IN]  New image to show on the button 
    );

    // <group DOM_FunctionBar_VcpFunctionBar_Method>
    // Removes a button.
    // RETURNS :
    // VFX_FALSE, if button ID not found. VFX_TRUE, if button was removed successfully.
    VfxBool removeItem(
        VfxId button_id                // [IN]  Unique ID of button 
    );

    // <group DOM_FunctionBar_VcpFunctionBar_Method>
    // Set the special button. 
    // RETURNS :
    // VFX_FALSE, if button ID not found. VFX_TRUE, if set successfully.
    VfxBool setItemSpecial(
        VfxId button_id                // [IN]  Unique ID of button 
    );

    // <group DOM_FunctionBar_VcpFunctionBar_Method>
    // Enables/disables a button.
    // RETURNS :
    // VFX_FALSE, if button ID not found. VFX_TRUE, if changed successfully.
    VfxBool setDisableItem(
        VfxId id,                   // [IN]  Unique ID of button
        VfxBool is_enable           // [IN]  Set disable/enable choice
    );

    // <group DOM_FunctionBar_VcpFunctionBar_Method>
    // Call this method when phone orientation is changed.
    void setLayout(
        VfxScrRotateTypeEnum rotate              // [IN]  Screen layout : Portrait or Landscape 
    );

private:
    // <group DOM_FunctionBar_VcpFunctionBar_Implementation>
    // Event handler, when any button is clicked.
    void onItemClick(VfxObject *obj, VfxId id);

    // <group DOM_FunctionBar_VcpFunctionBar_Implementation>
    // Draws the functionbar, and buttons.
    void show(void);

    // <group DOM_FunctionBar_VcpFunctionBar_Implementation>
    void onBoundsChanged(VfxFrame *frame, const VfxRect &old);

    // <group DOM_FunctionBar_VcpFunctionBar_Implementation>
    VfxBool addItemInt(VfxId button_id, const VfxWString &button_string, VfxResId button_icon);

    // <group DOM_FunctionBar_VcpFunctionBar_Implementation>
    VfxBool changeItemInt(VfxId buttonId, const VfxWString &buttonString, VfxResId buttonIcon);
    
//Signal
public:
    // <group DOM_FunctionBar_VcpFunctionBar_Event>
    // FunctionBar tap event.
    VfxSignal2 <VfxObject*, VfxId> m_signalButtonTap;


protected:
    // <group DOM_FunctionBar_VcpFunctionBar_Override>
    virtual void onInit();


//Variable
private:
    // <group DOM_FunctionBar_VcpFunctionBar_Implementation>
    // Specifies how many buttons have been added
    VfxU32 m_count;

    // <group DOM_FunctionBar_VcpFunctionBar_Implementation>
    // Special button is set or not?
    VfxBool m_isSpecialButtonSet;

    // <group DOM_FunctionBar_VcpFunctionBar_Implementation>
    // Button array
    VcpButton *m_buttonArray[VCP_FUNCTION_BAR_MAX_BUTTONS_COUNT];
};

#endif /* defined(__MMI_VUI_COSMOS_CP__) */

#endif /* __VCP_FUNCTION_BAR_H__ */

