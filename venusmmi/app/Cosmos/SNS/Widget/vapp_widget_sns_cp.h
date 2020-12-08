/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_widget_sns.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the cp class for sns tabbar widget.
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_WIDGET_SNS_CP_H
#define VAPP_WIDGET_SNS_CP_H

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#if defined(__MMI_VUI_HOMESCREEN_SNS__)
#if defined(__MMI_VUI_WIDGET_SNS_TABBAR__)

#include "vcp_include.h"
#include "vapp_widget_def.h"
#include "vapp_widget.h"
#include "vapp_sns_base.h"

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
#define MAX_SELECTED_FRIENDS (5)

class VappSnsWidgetTabButtonCp : public VfxControl
{
    VFX_DECLARE_CLASS(VappSnsWidgetTabButtonCp);

    // Constructor / Destructor
public:

    enum
    {
        INVALID_TAB_ID = 0xFFFFFFFF,
#if defined(__MMI_MAINLCD_320X480__)
        BTN_HIGHLIGHT_WIDTH = 68,
        BTN_HIGHLIGHT_HEIGHT = 57,
        ICON_HIGHLIGHT_WIDTH = 64,
        ICON_HIGHLIGHT_HEIGHT = 53,
        BTN_WIDTH = 54,
        BTN_HEIGHT = 50,
        ICON_WIDTH = 50,
        ICON_HEIGHT = 46,
#elif defined(__MMI_MAINLCD_480X800__)
        BTN_HIGHLIGHT_WIDTH = 97,
        BTN_HIGHLIGHT_HEIGHT = 84,
        ICON_HIGHLIGHT_WIDTH = 91,
        ICON_HIGHLIGHT_HEIGHT = 81,
        BTN_WIDTH = 81,
        BTN_HEIGHT = 75,
        ICON_WIDTH = 75,
        ICON_HEIGHT = 71,
#else            
        BTN_HIGHLIGHT_WIDTH = 55,
        BTN_HIGHLIGHT_HEIGHT = 47,
        ICON_HIGHLIGHT_WIDTH = 51,
        ICON_HIGHLIGHT_HEIGHT = 45,
        BTN_WIDTH = 42,
        BTN_HEIGHT = 19,
        ICON_WIDTH = 38,
        ICON_HEIGHT = 37,
#endif
    };

    // <group DOM_Button_VcpButton_Constructor/Destructor>
    VappSnsWidgetTabButtonCp();

    // Signal
public:
    // <group DOM_Button_VcpButton_Event>
    // This signal is invoked when the button is clicked
    // ex: connect to void YourClass::onButtonClicked(VfxObject* sender, VfxId Id)
    VfxSignal2 <VfxObject*, VfxId> m_signalClicked;

    // Property
public:
    // <group DOM_Button_VcpButton_Property>
    // Set image list of the button
    void setImage(
        const VfxImageSrc &image      // [IN] image list of the button
    );

    // <group DOM_Button_VcpButton_Property>
    // Get current image of the button
    const VfxImageSrc &getImage() const;

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
    // set ID
    void setId(
        VfxId id                            // [IN] ID
    );

    // <group DOM_Button_VcpButton_Property>
    // get ID
    VfxId getId() const;

    // Method
public:

    // <group DOM_Button_VcpButton_Method>
    // set font border color for all types
    void setTextBorderColor(
        const VfxColor &color               // [IN] text border color
    );

    // <group DOM_Button_VcpButton_Method>
    // set back ground images list
    void setBgImageList (
        const VcpStateImage &imageList      // [IN] CP image list
    );

    // <group DOM_Button_VcpButton_Method>
    // force update all layout immediatelly
    void forceUpdate();

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

    // On Deinit
    virtual void onDeinit();

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
    // image frame
    VfxFrame *m_frameImage;

    VfxFrame *m_borderImage;
    // <group DOM_Button_VcpButton_Implementation>
    // Image size;
    VfxSize m_sizeImage;

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
    // ID
    VfxU32 m_id;

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
    // Resize button
   // void resizeButton();

    // <group DOM_Button_VcpButton_Implementation>
    // Layout button
    void layoutButton();

    // <group DOM_Button_VcpButton_Implementation>
    // Update button while bounds change
    void onBoundsChanged(VfxFrame *frame, const VfxRect &old);

    // <group DOM_Button_VcpButton_Implementation>
    // get client area
    VfxRect getClientArea() const;
    void onAfterClick();
};

class VappSnsWidgetTabBarCp : public VfxControl
{
    VFX_DECLARE_CLASS(VappSnsWidgetTabBarCp);

    // Constructor / Destructor
public:    
    // <group DOM_TabBar_VcpTabBar_Constructor/Destructor>
    // Default constructor.
    VappSnsWidgetTabBarCp();

    // Event
public:
    // <group DOM_TabBar_VcpTabBar_Event>
    // This signal is invoked when the tab is switched
    // void YourClass::onTabSwitched(VfxObject* sender, VfxId tabId)
    VfxSignal2 <VfxObject*, VfxId> m_signalTabSwitched;

    // Method
public:
    // <group DOM_TabBar_VcpTabBar_Method>
    // add one tab item
    virtual void addTab (
        VfxId id,                       // [IN] tab ID
        VfxId beforeId = INVALID_TAB_ID // [IN] where to insert the tab item, insert to the end by default
        );

    // <group DOM_TabBar_VcpTabBar_Method>
    // update one tab item 
    virtual void changeTab(VfxId id, const VfxImageSrc &image);

    // <group DOM_TabBar_VcpTabBar_Method>
    // enable / disable one tab item
    virtual void setTabIsDisabled (
        VfxId id,                       // [IN] tab ID
        VfxBool isDisabled              // [IN] whether it is enabled
        );

    // <group DOM_TabBar_VcpTabBar_Method>
    // get whether one tab is enabled
    // RETURNS: VfxBool
    virtual VfxBool getTabIsDisabled (
        VfxId id                        // [IN] tab ID
        ) const ;

    // Set highlighted item
    // <group DOM_TabBar_VcpTabBar_Property>
    virtual void setHighlightedTab (
        VfxId id                        // [IN] tab ID
        )
    {
        m_highlightedId = id;
        checkUpdate();
    }

    // Get which item to be highlighted
    // RETURNS: VfxId
    // <group DOM_TabBar_VcpTabBar_Property>
    virtual VfxId getHighlightedTab () const
    {
        return m_highlightedId;
    }

    // Override
protected:
    // <group DOM_TabBar_VcpTabBar_Override>
    // On init
    virtual void onInit();

    // <group DOM_TabBar_VcpTabBar_Override>
    // On Deinit
    virtual void onDeinit();

    // <group DOM_TabBar_VcpTabBar_Override>
    // Update the title display
    virtual void onUpdate();

    // Implementation
private:
    // <group DOM_TabBar_VcpTabBar_Implementation>
    enum
    {
        INVALID_TAB_ID = 0xFFFFFFFF,
        

        ICON_GAP = 1,
        TAB_GAP = 1,
        
#if defined(__MMI_VUI_SHELL_CP__)
        LEFT_MARGIN = 0,
        RIGHT_MARGIN = 0,
#else
        LEFT_MARGIN = 1,
        RIGHT_MARGIN = 1,
#endif

#if defined(__MMI_MAINLCD_320X480__)
        HEIGHT = 55,
        DEFAULT_THICKNESS = 50,
        FONT_SIZE = 13,
        VERT_TAB_HEIGHT = 62,

        HOR_TAB_GAP = 0,
        VERT_TAB_GAP = 0,

        STD_ICON_WIDTH = 18,
        STD_ICON_HEIGHT = 18,
        HIGHLIGHT_BTN_WIDTH = 68,
        HIGHLIGHT_BTN_HEIGHT = 57,
        HIGHLIGHT_ICON_WIDTH = 64,
        HIGHLIGHT_ICON_HEIGHT = 53,
        HIGHLIGHT_ICON_GAP = 3,
        BTN_WIDTH = 54,
        BTN_HEIGHT = 50,
        
        ICON_WIDTH = 50,
        ICON_HEIGHT = 48,

#elif defined(__MMI_MAINLCD_480X800__)
        HEIGHT = 84,
        DEFAULT_THICKNESS = 85,
        FONT_SIZE = 20,
        VERT_TAB_HEIGHT = 62,

        HOR_TAB_GAP = 0,
        VERT_TAB_GAP = 0,
        HIGHLIGHT_BTN_WIDTH = 97,
        HIGHLIGHT_BTN_HEIGHT = 84,
        HIGHLIGHT_ICON_WIDTH = 91,
        HIGHLIGHT_ICON_HEIGHT = 81,
        HIGHLIGHT_ICON_GAP = 3,
        BTN_WIDTH = 81,
        BTN_HEIGHT = 75,
        
        ICON_WIDTH = 77,
        ICON_HEIGHT = 73,

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        HEIGHT = 47,
        DEFAULT_THICKNESS = 45, 
        FONT_SIZE = 12,
        VERT_TAB_HEIGHT = 62,

        HOR_TAB_GAP = 0,
        VERT_TAB_GAP = 0,
        HIGHLIGHT_BTN_WIDTH = 55,
        HIGHLIGHT_BTN_HEIGHT = 47,
        HIGHLIGHT_ICON_WIDTH = 51,
        HIGHLIGHT_ICON_HEIGHT = 45,
        HIGHLIGHT_ICON_GAP = 3,
        BTN_WIDTH = 42,
        BTN_HEIGHT = 39,
        
        ICON_WIDTH = 38,
        ICON_HEIGHT = 37,
#else
        DEFAULT_THICKNESS = 50,
        FONT_SIZE = 13,
        VERT_TAB_HEIGHT = 62,

        HOR_TAB_GAP = 0,
        VERT_TAB_GAP = 0,
#endif
        BTN_Y = HEIGHT - BTN_HEIGHT,
        ENUM_END
    };

    // Implementation
private:

    VappSnsWidgetTabButtonCp *m_buttons[5];

    // <group DOM_TabBar_VcpTabBar_Implementation>
    // number of items
    VfxS32 m_count;

    // <group DOM_TabBar_VcpTabBar_Implementation>
    // highlighted tab ID
    VfxId m_highlightedId;

    // <group DOM_TabBar_VcpTabBar_Implementation>
    // Margin width
    VfxS32 m_margin;

    // <group DOM_TabBar_VcpTabBar_Implementation>
    // on button clicked, emit tab switch event
    void onButtonClicked (VfxObject* sender, VfxId Id);
};

#endif
#endif /* __MMI_VUI_HOMESCREEN_SNS__ */
#endif /* VAPP_WIDGET_SNS_CP_H */
