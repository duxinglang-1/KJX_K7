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
 *  vcp_tool_bar.h
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Toolbar/Function bar component header
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
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_TOOL_BAR_H__
#define __VCP_TOOL_BAR_H__

#include "mmi_core\vfx_page_bar.h"
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_frame.h"
#include "vcp_button.h"
#include "vfx_signal.h"
#include "vfx_basic_type.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"

#if defined(__MMI_VUI_COSMOS_CP__)

/***************************************************************************** 
 * Include
 *****************************************************************************/


/***************************************************************************** 
 * Define
 *****************************************************************************/

// <group DOM_ToolBar_Macro&Enum_Macro>
// Maximum number of buttons on ToolBar.
#define VCP_TOOL_BAR_MAX_BUTTONS_COUNT              (7)

// <group DOM_ToolBar_Macro&Enum_Macro>
// Maximum number of buttons on a single row in portrait mode.
#define VCP_TOOL_BAR_MAX_ROW_BUTTONS                (4)

#define VCP_TOOL_BAR_MAX_SEGMENT_BUTTONS_COUNT      (3)
#define VCP_TOOL_BAR_FOLD_BUTTON_ID                 ('FOLD')
#define VCP_TOOL_BAR_SEGMENT_BUTTON_GAP             (8)
#define VCP_TOOL_BAR_INVALID_ID                     (0xFFFFFFFF)


#ifdef __MMI_MAINLCD_480X800__
    #define VCP_TOOL_BAR_SCREEN_WIDTH (480)
    #define VCP_TOOL_BAR_SCREEN_HEIGHT (800)
    
    #define VCP_TOOL_BAR_PORTRAIT_WIDTH  (VCP_TOOL_BAR_SCREEN_WIDTH)
    #define VCP_TOOL_BAR_LANDSCAPE_WIDTH  (VCP_TOOL_BAR_SCREEN_HEIGHT)
    #define VCP_TOOL_BAR_HEIGHT (85)
    #define VCP_TOOL_BAR_SEGMENT_BUTTON_PORTRAIT_WIDTH (VCP_TOOL_BAR_PORTRAIT_WIDTH/VCP_TOOL_BAR_MAX_ROW_BUTTONS)
    #define VCP_TOOL_BAR_SEGMENT_BUTTON_LANDSCAPE_WIDTH (VCP_TOOL_BAR_LANDSCAPE_WIDTH/VCP_TOOL_BAR_MAX_ROW_BUTTONS)
    
    #define VCP_TOOL_BAR_X      (0)
    #define VCP_TOOL_BAR_Y      (VCP_TOOL_BAR_SCREEN_HEIGHT - VCP_TOOL_BAR_HEIGHT - 1)

    #define VCP_TOOL_BAR_SHADOW_HEIGHT                  (4)

    #define VCP_TOOL_BAR_BUTTON_FONT_SIZE               (20)
    #define VCP_TOOL_BAR_BUTTON_FONT_MARGIN_UP          (7)
    #define VCP_TOOL_BAR_BUTTON_FONT_MARGIN_DOWN        (1)
    #define VCP_TOOL_BAR_BUTTON_FONT_MARGIN_LEFT        (1)
    #define VCP_TOOL_BAR_BUTTON_FONT_MARGIN_RIGHT       (1)
#elif defined(__MMI_MAINLCD_320X480__)
    #define VCP_TOOL_BAR_SCREEN_WIDTH (320)
    #define VCP_TOOL_BAR_SCREEN_HEIGHT (480)
    
    #define VCP_TOOL_BAR_PORTRAIT_WIDTH  (VCP_TOOL_BAR_SCREEN_WIDTH)
    #define VCP_TOOL_BAR_LANDSCAPE_WIDTH  (VCP_TOOL_BAR_SCREEN_HEIGHT)
    #define VCP_TOOL_BAR_HEIGHT (50)
    #define VCP_TOOL_BAR_SEGMENT_BUTTON_PORTRAIT_WIDTH (VCP_TOOL_BAR_PORTRAIT_WIDTH/VCP_TOOL_BAR_MAX_ROW_BUTTONS)
    #define VCP_TOOL_BAR_SEGMENT_BUTTON_LANDSCAPE_WIDTH (VCP_TOOL_BAR_LANDSCAPE_WIDTH/VCP_TOOL_BAR_MAX_ROW_BUTTONS)
    
    #define VCP_TOOL_BAR_X      (0)
    #define VCP_TOOL_BAR_Y      (VCP_TOOL_BAR_SCREEN_HEIGHT - VCP_TOOL_BAR_HEIGHT - 1)

    #define VCP_TOOL_BAR_SHADOW_HEIGHT                  (2)

    #define VCP_TOOL_BAR_BUTTON_FONT_SIZE               (13)
    #define VCP_TOOL_BAR_BUTTON_FONT_MARGIN_UP          (5)
    #define VCP_TOOL_BAR_BUTTON_FONT_MARGIN_DOWN        (1)
    #define VCP_TOOL_BAR_BUTTON_FONT_MARGIN_LEFT        (1)
    #define VCP_TOOL_BAR_BUTTON_FONT_MARGIN_RIGHT       (1)
#elif defined(__MMI_MAINLCD_240X400__)
    #define VCP_TOOL_BAR_SCREEN_WIDTH (240)
    #define VCP_TOOL_BAR_SCREEN_HEIGHT (400)
    
    #define VCP_TOOL_BAR_PORTRAIT_WIDTH  (VCP_TOOL_BAR_SCREEN_WIDTH)
    #define VCP_TOOL_BAR_LANDSCAPE_WIDTH  (VCP_TOOL_BAR_SCREEN_HEIGHT)
    #define VCP_TOOL_BAR_HEIGHT (45)
    #define VCP_TOOL_BAR_SEGMENT_BUTTON_PORTRAIT_WIDTH (VCP_TOOL_BAR_PORTRAIT_WIDTH/VCP_TOOL_BAR_MAX_ROW_BUTTONS)
    #define VCP_TOOL_BAR_SEGMENT_BUTTON_LANDSCAPE_WIDTH (VCP_TOOL_BAR_LANDSCAPE_WIDTH/VCP_TOOL_BAR_MAX_ROW_BUTTONS)
    
    #define VCP_TOOL_BAR_X      (0)
    #define VCP_TOOL_BAR_Y      (VCP_TOOL_BAR_SCREEN_HEIGHT - VCP_TOOL_BAR_HEIGHT - 1)

    #define VCP_TOOL_BAR_SHADOW_HEIGHT                  (2)

    #define VCP_TOOL_BAR_BUTTON_FONT_SIZE               (12)
    #define VCP_TOOL_BAR_BUTTON_FONT_MARGIN_UP          (3)
    #define VCP_TOOL_BAR_BUTTON_FONT_MARGIN_DOWN        (1)
    #define VCP_TOOL_BAR_BUTTON_FONT_MARGIN_LEFT        (1)
    #define VCP_TOOL_BAR_BUTTON_FONT_MARGIN_RIGHT       (1)
#elif defined(__MMI_MAINLCD_240X320__)
    #define VCP_TOOL_BAR_SCREEN_WIDTH (240)
    #define VCP_TOOL_BAR_SCREEN_HEIGHT (320)
    
    #define VCP_TOOL_BAR_PORTRAIT_WIDTH  (VCP_TOOL_BAR_SCREEN_WIDTH)
    #define VCP_TOOL_BAR_LANDSCAPE_WIDTH  (VCP_TOOL_BAR_SCREEN_HEIGHT)
    #define VCP_TOOL_BAR_HEIGHT (45)
    #define VCP_TOOL_BAR_SEGMENT_BUTTON_PORTRAIT_WIDTH (VCP_TOOL_BAR_PORTRAIT_WIDTH/VCP_TOOL_BAR_MAX_ROW_BUTTONS)
    #define VCP_TOOL_BAR_SEGMENT_BUTTON_LANDSCAPE_WIDTH (VCP_TOOL_BAR_LANDSCAPE_WIDTH/VCP_TOOL_BAR_MAX_ROW_BUTTONS)
    
    #define VCP_TOOL_BAR_X      (0)
    #define VCP_TOOL_BAR_Y      (VCP_TOOL_BAR_SCREEN_HEIGHT - VCP_TOOL_BAR_HEIGHT - 1)

    #define VCP_TOOL_BAR_SHADOW_HEIGHT                  (2)

    #define VCP_TOOL_BAR_BUTTON_FONT_SIZE               (12)
    #define VCP_TOOL_BAR_BUTTON_FONT_MARGIN_UP          (3)
    #define VCP_TOOL_BAR_BUTTON_FONT_MARGIN_DOWN        (1)
    #define VCP_TOOL_BAR_BUTTON_FONT_MARGIN_LEFT        (1)
    #define VCP_TOOL_BAR_BUTTON_FONT_MARGIN_RIGHT       (1)
#else 
    #define VCP_TOOL_BAR_SCREEN_WIDTH (240)
    #define VCP_TOOL_BAR_SCREEN_HEIGHT (320)
    
    #define VCP_TOOL_BAR_PORTRAIT_WIDTH  (VCP_TOOL_BAR_SCREEN_WIDTH)
    #define VCP_TOOL_BAR_LANDSCAPE_WIDTH  (VCP_TOOL_BAR_SCREEN_HEIGHT)
    #define VCP_TOOL_BAR_HEIGHT (45)
    #define VCP_TOOL_BAR_SEGMENT_BUTTON_PORTRAIT_WIDTH (VCP_TOOL_BAR_PORTRAIT_WIDTH/VCP_TOOL_BAR_MAX_ROW_BUTTONS)
    #define VCP_TOOL_BAR_SEGMENT_BUTTON_LANDSCAPE_WIDTH (VCP_TOOL_BAR_LANDSCAPE_WIDTH/VCP_TOOL_BAR_MAX_ROW_BUTTONS)
    
    #define VCP_TOOL_BAR_X      (0)
    #define VCP_TOOL_BAR_Y      (VCP_TOOL_BAR_SCREEN_HEIGHT - VCP_TOOL_BAR_HEIGHT - 1)

    #define VCP_TOOL_BAR_SHADOW_HEIGHT                  (2)

    #define VCP_TOOL_BAR_BUTTON_FONT_SIZE               (12)
    #define VCP_TOOL_BAR_BUTTON_FONT_MARGIN_UP          (3)
    #define VCP_TOOL_BAR_BUTTON_FONT_MARGIN_DOWN        (1)
    #define VCP_TOOL_BAR_BUTTON_FONT_MARGIN_LEFT        (1)
    #define VCP_TOOL_BAR_BUTTON_FONT_MARGIN_RIGHT       (1)
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef enum
{
    VCP_TOOL_BAR_SEGMENT_BUTTON_COUNT_BASE = 2,
    VCP_TOOL_BAR_SEGMENT_BUTTON_COUNT_TWO = VCP_TOOL_BAR_SEGMENT_BUTTON_COUNT_BASE,
    VCP_TOOL_BAR_SEGMENT_BUTTON_COUNT_THREE = 3,
    VCP_TOOL_BAR_SEGMENT_BUTTON_COUNT_MAX = VCP_TOOL_BAR_SEGMENT_BUTTON_COUNT_THREE,
    VCP_TOOL_BAR_SEGMENT_BUTTON_COUNT_END,
}VcpToolBarSegmentButtonCountEnum;

typedef enum
{
    VCP_TOOL_BAR_ITEM_NOT_EXIST,
    VCP_TOOL_BAR_ITEM_DISABLED,
    VCP_TOOL_BAR_ITEM_ENABLED,
    VCP_TOOL_BAR_ITEM_TOTAL,
}VcpToolBarDisableEnum;


/********************************************************
 * Structure to be used in XML
 * *******************************************************
 *   <Struct name="VcpToolBarItemStruct">
 *       <Member    name="id"             type="VfxId" />
 *       <Member    name="string"         type="VfxWString" />
 *       <Member    name="icon"           type="VfxResId" />
 *   </Struct>
 *********************************************************/
struct VcpToolBarItemStruct : public VfxBase
{
    VfxId id;            
    VfxWString string;            
    VfxResId icon;            
};

/********************************************************
 * Structure to be used in XML
 *   <Struct name="VcpToolBarDisableItemStruct">
 *       <Member    name="id"             type="VfxId" />
 *       <Member    name="is_disable"     type="VfxBool" />
 *   </Struct>
 * ********************************************************/
struct VcpToolBarDisableItemStruct : public VfxBase
{
    VfxId id;            
    VfxBool is_disable;            
};


/*****************************************************************************
 * Class VcpToolBar
 * ToolBar is a Page bar at the bottom of the app screen with related function buttons.
 *
 * EXAMPLE:
 * <code>
 *   VFX_OBJ_CREATE(m_tool_bar, VcpToolBar, this);
 *   m_tool_bar->addItem(APP_BUTTON_CUT_ID, VFX_WSTR("Cut"), VfxImageSrc(APP_ENUM_CUT_IMG));
 * </code>
 *****************************************************************************/
class VcpToolBar : public VfxPageBar
{
    VFX_DECLARE_CLASS(VcpToolBar);
public:
    // <group DOM_ToolBar_VcpToolBar_Constructor/Destructor>
    // Default constructor.
    VcpToolBar();

public:
    // <group DOM_ToolBar_VcpToolBar_Method>
    // Adds a button.
    // RETURNS :
    // VFX_FALSE, if max buttons are already added. VFX_TRUE, if successfully added.
    VfxBool addItem(
        VfxId buttonId,                                // [IN] Unique ID of button 
        const VfxWString &buttonString,                // [IN] String to show on the button
        VfxResId buttonIcon,                           // [IN] Button Icon to show over the string
        VfxId beforeId  = VCP_TOOL_BAR_INVALID_ID       // [IN] Positioning the new Button 
    );

	/* vaib mem reduction */
     // <group DOM_ToolBar_VcpToolBar_Method>
    // Adds a button.
    // RETURNS :
    // VFX_FALSE, if max buttons are already added. VFX_TRUE, if successfully added.
    VfxBool addItem(
        VfxId buttonId,                                // [IN] Unique ID of button 
        VfxResId  buttonString,                // [IN] String to show on the button
        VfxResId buttonIcon,                           // [IN] Button Icon to show over the string
        VfxId beforeId  = VCP_TOOL_BAR_INVALID_ID       // [IN] Positioning the new Button 
    );

	/* vaib mem reduction */
	// <group DOM_ToolBar_VcpToolBar_Method>
    // Adds a button .
    // RETURNS :
    // VFX_FALSE, if max buttons are already added. VFX_TRUE, if successfully added.
    VfxBool addItem(
        VfxId buttonId,                                // [IN] Unique ID of button 
        const VfxWChar* buttonString,                // [IN] String to show on the button
        VfxResId buttonIcon,                           // [IN] Button Icon to show over the string
        VfxId beforeId  = VCP_TOOL_BAR_INVALID_ID       // [IN] Positioning the new Button 
    );
	
    // <group DOM_ToolBar_VcpToolBar_Method>
    // Adds a button 
    // RETURNS :
    // VFX_FALSE, if button ID is not found. VFX_TRUE, if successfully changed.
    VfxBool changeItem(
        VfxId button_id,                        // [IN]  Unique ID of button 
        const VfxWString &button_string,        // [IN] String to show on the button
        VfxResId button_icon                    // [IN] Button Icon to show over the string
    );

	/* vaib mem reduction */
	// <group DOM_ToolBar_VcpToolBar_Method>
    // Adds a button 
    // RETURNS :
    // VFX_FALSE, if button ID is not found. VFX_TRUE, if successfully changed.
    VfxBool changeItem(
        VfxId button_id,                        // [IN]  Unique ID of button 
        VfxResId button_string,        // [IN] String to show on the button
        VfxResId button_icon                    // [IN] Button Icon to show over the string
    );

	/* vaib mem reduction */
	// <group DOM_ToolBar_VcpToolBar_Method>
    // Adds a button 
    // RETURNS :
    // VFX_FALSE, if button ID is not found. VFX_TRUE, if successfully changed.
    VfxBool changeItem(
        VfxId button_id,                        // [IN]  Unique ID of button 
        const VfxWChar* button_string,        // [IN] String to show on the button
        VfxResId button_icon                    // [IN] Button Icon to show over the string
    );

    // <group DOM_ToolBar_VcpToolBar_Method>
    // Adds a button with VfxImageSrc icon.
    // RETURNS :
    // VFX_FALSE, if max buttons are already added. VFX_TRUE, if successfully added.
    VfxBool addItem(
        VfxId buttonId, 
        const VfxWString &buttonString, 
        const VfxImageSrc &buttonIconSrc, 
        VfxId beforeId  = VCP_TOOL_BAR_INVALID_ID);

	/* vaib mem reduction */
	// <group DOM_ToolBar_VcpToolBar_Method>
    // Adds a button with VfxImageSrc icon.
    // RETURNS :
    // VFX_FALSE, if max buttons are already added. VFX_TRUE, if successfully added.
    VfxBool addItem(
        VfxId buttonId, 
        VfxResId buttonString, 
        const VfxImageSrc &buttonIconSrc, 
        VfxId beforeId  = VCP_TOOL_BAR_INVALID_ID);

	/* vaib mem reduction */
	// <group DOM_ToolBar_VcpToolBar_Method>
    // Adds a button with VfxImageSrc icon.
    // RETURNS :
    // VFX_FALSE, if max buttons are already added. VFX_TRUE, if successfully added.
    VfxBool addItem(
        VfxId buttonId, 
        const VfxWChar* buttonString, 
        const VfxImageSrc &buttonIconSrc, 
        VfxId beforeId  = VCP_TOOL_BAR_INVALID_ID);

    // <group DOM_ToolBar_VcpToolBar_Method>
    // Adds a button with VfxImageSrc icon.
    // RETURNS :
    // VFX_FALSE, if button ID is not found. VFX_TRUE, if successfully changed.
    VfxBool changeItem(
        VfxId button_id, 
        const VfxWString &button_string, 
        const VfxImageSrc &buttonIconSrc);

	/* vaib mem reduction */
	// <group DOM_ToolBar_VcpToolBar_Method>
    // Adds a button with VfxImageSrc icon.
    // RETURNS :
    // VFX_FALSE, if button ID is not found. VFX_TRUE, if successfully changed.
    VfxBool changeItem(
        VfxId button_id, 
        VfxResId button_string, 
        const VfxImageSrc &buttonIconSrc);

	/* vaib mem reduction */
	// <group DOM_ToolBar_VcpToolBar_Method>
    // Adds a button with VfxImageSrc icon.
    // RETURNS :
    // VFX_FALSE, if button ID is not found. VFX_TRUE, if successfully changed.
    VfxBool changeItem(
        VfxId button_id, 
        const VfxWChar* button_string, 
        const VfxImageSrc &buttonIconSrc);
	

    // <group DOM_ToolBar_VcpToolBar_Method>
    // Adds a button : XML support
    // RETURNS :
    // VFX_FALSE, if max buttons are already added. VFX_TRUE, if successfully added.
    VfxBool addItemStruct(
        const VcpToolBarItemStruct &item                // [IN]  Item info in Struct form 
    );

    // <group DOM_ToolBar_VcpToolBar_Method>
    // Adds a control frame for segment button.
    // RETURNS :
    // An object of VfxFrame where app can draw its segment button.
    VfxFrame* addControlFrame(
        VcpToolBarSegmentButtonCountEnum buttonCount      // [IN]  Number of buttons to accomodate in segment button (should be either 2 or 3) 
    );

    // <group DOM_ToolBar_VcpToolBar_Method>
    // Removes a button.
    // RETURNS :
    // VFX_FALSE, if button ID is not found. VFX_TRUE, if successfully removed.
    VfxBool removeItem(
        VfxId buttonId                // [IN]  Unique ID of button 
    );

    // <group DOM_ToolBar_VcpToolBar_Method>
    // Removes all buttons and control frame.
    void removeAllItems();

    // <group DOM_ToolBar_VcpToolBar_Method>
    // Removes the control frame for segment button.
    // RETURNS :
    // VFX_FALSE, if segment frame is not found. VFX_TRUE, if successfully removed.
    VfxBool removeControlFrame(void);

    // <group DOM_ToolBar_VcpToolBar_Method>
    // Enables/disables a button.
    // RETURNS :
    // VFX_FALSE, if button ID is not found. VFX_TRUE, if successfully removed.
    VfxBool setDisableItem(
        VfxId id,                   // [IN]  Unique ID of button
        VfxBool isEnable           // [IN]  Set disable/enable choice
    );

    // <group DOM_ToolBar_VcpToolBar_Method>
    // Searches a button by ID and check if it is disabled.
    // RETURNS :
    //    If found and disabled, VCP_TOOL_BAR_ITEM_DISABLED
    //    If found and enabled, VCP_TOOL_BAR_ITEM_ENABLED
    //    If not found, VCP_TOOL_BAR_ITEM_NOT_EXIST
    VcpToolBarDisableEnum getIsItemDisabled(
        VfxId buttonId
    );

    // <group DOM_ToolBar_VcpToolBar_Method>
    // Disables a button : XML support.
    // RETURNS :
    // VFX_FALSE, if button ID is not found. VFX_TRUE, if successfully disabled.
    VfxBool setDisableItemStruct(
        const VcpToolBarDisableItemStruct &item                // [IN]  Item info in Struct form 
    );

    // <group DOM_ToolBar_VcpToolBar_Method>
    // Disables/enables fold button.
    void setDisableFoldButton(
        VfxBool isDisabled          // [IN] Set disable/enable choice
    );
    // <group DOM_ToolBar_VcpToolBar_Method>
    // Check whether fold button is disabled or not.
    // RETURNS:
    //    If disabled, then returns true.
    //    If enabled, then returns false.  
    VfxBool getIsFoldButtonDisabled(
    );
    // <group DOM_ToolBar_VcpToolBar_Method>
    // Queries if the tool bar is folded in Portrait mode.
    // RETURNS :
    // Folding status.
    VfxBool isFolded(void) const;

    // <group DOM_ToolBar_VcpToolBar_Method>
    // Switch between Fold/Unfold mode. 
    void switchFoldMode(void);

    // <group DOM_ToolBar_VcpToolBar_Method>
    // Rotation support for screen layout : Portrait or Landscape. 
    void setLayout(
        VfxScrRotateTypeEnum rotate                          // [IN]  Rotation orientation
    );

// Method 
private:
    // <group DOM_ToolBar_VcpToolBar_Implementation>
    // Event handler, when any button is clicked.
    void onItemClick(VfxObject *obj, VfxId id);

    // <group DOM_ToolBar_VcpToolBar_Implementation>
    // Timer callback after toolbar folds.
    void onFoldedTimer(VfxTimer *timer);

    // <group DOM_ToolBar_VcpToolBar_Implementation>
    // Draws the toolbar, and buttons.
    void show(void);

    // <group DOM_ToolBar_VcpToolBar_Implementation>
    // Reposition and resize the toolbar.
    void resetLayout(void);

    // <group DOM_ToolBar_VcpToolBar_Implementation>
    // Event handler for fold/unfold button click.
    void onFoldButtonClick(VfxObject *obj, VfxId id);

    // <group DOM_ToolBar_VcpToolBar_Implementation>
    // Internal change Item API
    VfxBool changeItem(VfxId buttonId, const VfxWString &buttonString, const VfxImageSrc &buttonIconSrc, VfxResId buttonIcon);

    // <group DOM_ToolBar_VcpToolBar_Implementation>
    // Internal change Item API
    VfxBool addItem(VfxId buttonId, const VfxWString &buttonString, const VfxImageSrc &buttonIconSrc, VfxId beforeId, VfxResId buttonIcon);

    // <group DOM_ToolBar_VcpToolBar_Implementation>
    void addItemButtonInt(VfxU32 index, VfxFrame *barFrame);

    // <group DOM_ToolBar_VcpToolBar_Implementation>
    void addFoldButtonInt();

//Signal
public:
    // <group DOM_ToolBar_VcpToolBar_Event>
    // ToolBar tap event.
    VfxSignal2 <VfxObject*, VfxId> m_signalButtonTap;

    // <group DOM_ToolBar_VcpToolBar_Event>
    // Bar folding event.
    VfxSignal2 <VfxObject*, VfxBool> m_signalBarFolded;

// Overridable
protected:
    // <group DOM_ToolBar_VcpToolBar_Override>
    virtual void onInit();

    // <group DOM_ToolBar_VcpToolBar_Override>
    virtual void onUpdate();

    // <group DOM_ToolBar_VcpToolBar_Override>
    virtual void setBounds(const VfxRect &value);

    virtual void onSetRotate(
        VfxScrRotateTypeEnum rotate // [IN] new direction
    ) { setLayout(rotate); }

    // <group DOM_ToolBar_VcpToolBar_Override>
    virtual void onSetTranslucent(VfxBool translucent);

//Variable
private:
    // <group DOM_ToolBar_VcpToolBar_Implementation>
    // Specifies how many buttons have been added
    // (includes buttons added with addItem and requested in addControlFrame)
    VfxU32 m_count;

    // <group DOM_ToolBar_VcpToolBar_Implementation>
    // Frame area to draw segment button
    VfxFrame *m_segmentButtonBaseFrame;

    // <group DOM_ToolBar_VcpToolBar_Property>
    // Toolbar's height in folded mode
    VfxU32 m_rowHeight;            

    // <group DOM_ToolBar_VcpToolBar_Implementation>
    // Lower row frame.
    VfxFrame *m_lowerFrame;

    // <group DOM_ToolBar_VcpToolBar_Implementation>
    // Upper row frame.
    VfxFrame *m_upperFrame;

    // <group DOM_ToolBar_VcpToolBar_Implementation>
    // Button array
    VcpButton *m_buttonArray[VCP_TOOL_BAR_MAX_BUTTONS_COUNT];

    // <group DOM_ToolBar_VcpToolBar_Implementation>
    // Fold/Unfold buttton
    VcpButton *m_foldButton;

    // <group DOM_ToolBar_VcpToolBar_Implementation>
    // Normal button count
    VfxU32 m_normalButtonCount;

    // <group DOM_ToolBar_VcpToolBar_Implementation>
    // Count of segment button on the control frame
    VfxU32 m_segmentButtonCount;

    // <group DOM_ToolBar_VcpToolBar_Implementation>
    // Screen orientation
    VfxScrRotateTypeEnum m_layout;

    // <group DOM_ToolBar_VcpToolBar_Implementation>
    // Fold timer
    VfxTimer *m_foldTimer;

    // <group DOM_ToolBar_VcpToolBar_Implementation>
    // Folded/Unfolded mode
    VfxBool m_isFolded;

    // <group DOM_ToolBar_VcpToolBar_Implementation>
    // Translucent image
    VfxBool m_translucent;
    // <group DOM_ToolBar_VcpToolBar_Implementation>
    // Specifies whether fold button is enabled or disabled 
    VfxBool m_isFoldDisabled;
};

#endif /* #if defined (__MMI_VUI_COSMOS_CP__)  */ 
#endif /* __VCP_TOOL_BAR_H__ */

