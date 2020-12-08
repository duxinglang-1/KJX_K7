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
 *  vcp_tab_bar.h
 *
 * Project:
 * --------
 *  Venus UI Components
 *
 * Description:
 * ------------
 *  Tab bar component
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

#ifndef __VCP_TAB_BAR_H__
#define __VCP_TAB_BAR_H__

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
#include "vcp_button.h"

#if defined(__MMI_VUI_COSMOS_CP__)
#include "vcp_button_util.h"
#endif

#if !defined(__MMI_VUI_COSMOS_CP__)
#define MULTI_LAYOUT_SUPPORT
#endif

/***************************************************************************** 
* Define
*****************************************************************************/

#if defined(__MMI_VUI_COSMOS_CP__)
#define VCP_TAB_BAR_TEXT_COLOR VFX_COLOR_RES(VCP_COL_TAB_BAR_TEXT)
#else
#define VCP_TAB_BAR_TEXT_COLOR VFX_COLOR_WHITE
#define VCP_TAB_BAR_TEXT_COLOR_HGHLGHT VfxColor(255, 23, 23, 23)
#endif

// <group DOM_TabBar_Macro&Enum_Enum>
enum VcpTabBarLayoutEnum
{
    VCP_TABBAR_LAYOUT_TOP,          // display tab bar at the top of the screen

#if defined(MULTI_LAYOUT_SUPPORT)
    VCP_TABBAR_LAYOUT_BOTTOM,       // display tab bar at the bottom of the screen
    VCP_TABBAR_LAYOUT_LEFT,
    VCP_TABBAR_LAYOUT_RIGHT,
#endif /* #if defined(MULTI_LAYOUT_SUPPORT) */

    VCP_TABBAR_LAYOUT_END_OF_ENUM   
};

enum VcpTabBarDimensions
{
    VCP_TABBAR_LEFT_MARGIN = 3,
    VCP_TABBAR_RIGHT_MARGIN = 3
};



/***************************************************************************** 
* For XML support
*****************************************************************************/
struct VcpTabBarItem : public VfxBase
{
    VfxS32   id;
    VcpStateImage    imagelist;
    VfxWString text;
};

#if defined(__MMI_VUI_COSMOS_CP__)
/***************************************************************************** 
* Class VcpTabBarTab
*****************************************************************************/
class VcpTabBarTab : public VcpScrollingTextButton
{
public:
    // Constructor / Destructor
    // Default constructor.
    VcpTabBarTab();

public:    
    void setNotificationText(const VfxWString &text);    
    void setNotificationIcon(VfxImageSrc icon);    
    virtual void onUpdate();
private:
    VfxFrame *m_NIcon;
    VfxTextFrame *m_NTextFrm;
    VfxS32 m_notifTextMargin;    
    enum
    {
#if defined(__MMI_MAINLCD_480X800__)
        VCP_TABBAR_NOTIFICATION_POSITION_OFFSET = 8
#elif defined(__MMI_MAINLCD_320X480__)
        VCP_TABBAR_NOTIFICATION_POSITION_OFFSET = 5
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        VCP_TABBAR_NOTIFICATION_POSITION_OFFSET = 2
#else
        VCP_TABBAR_NOTIFICATION_POSITION_OFFSET = 5
#endif
    };
};
#endif  

/***************************************************************************** 
* Class VcpTabBar
*****************************************************************************/
class VcpTabBar : public VfxControl
{
    VFX_DECLARE_CLASS(VcpTabBar);

    // Constructor / Destructor
public:    
    // <group DOM_TabBar_VcpTabBar_Constructor/Destructor>
    // Default constructor.
    VcpTabBar();

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
        const VcpStateImage &imageList, // [IN] image
            VfxResId resId,         // [IN] text
            VfxId beforeId = INVALID_TAB_ID // [IN] where to insert the tab item, insert to the end by default
            );

    // <group DOM_TabBar_VcpTabBar_Method>
    // add one tab item
    virtual void addTab (
        VfxId id,                       // [IN] tab ID
        const VcpStateImage &imageList, // [IN] image
        const VfxWChar *mem,         // [IN] text
        VfxId beforeId = INVALID_TAB_ID // [IN] where to insert the tab item, insert to the end by default
        );

    // <group DOM_TabBar_VcpTabBar_Method>
    // add one tab item
    virtual void addTab (
        VfxId id,                       // [IN] tab ID
        const VcpStateImage &imageList, // [IN] image
        const VfxWString &text,         // [IN] text
        VfxId beforeId = INVALID_TAB_ID // [IN] where to insert the tab item, insert to the end by default
        );

    // For XML support
    void addTabFromXML(VcpTabBarItem *tabContent); 

    // <group DOM_TabBar_VcpTabBar_Method>
    // update one tab item 
    virtual void changeTab(VfxId id, const VcpStateImage &imageList);

    // <group DOM_TabBar_VcpTabBar_Method>
    // update one tab item 
    virtual void changeTab(VfxId id, VfxResId resId);

    // <group DOM_TabBar_VcpTabBar_Method>
    // update one tab item 
    virtual void changeTab(VfxId id, const VfxWChar *mem);

    // <group DOM_TabBar_VcpTabBar_Method>
    // update one tab item 
    virtual void changeTab(VfxId id, const VfxWString &text);

    
    // <group DOM_TabBar_VcpTabBar_Method>
    // update one tab item 
    virtual void changeTab(VfxId id, VfxResId resId, const VcpStateImage &imageList);

    // <group DOM_TabBar_VcpTabBar_Method>
    // update one tab item 
    virtual void changeTab(VfxId id, const VfxWChar *mem, const VcpStateImage &imageList);

    // <group DOM_TabBar_VcpTabBar_Method>
    // update one tab item 
    virtual void changeTab(VfxId id, const VfxWString &text, const VcpStateImage &imageList);

    // <group DOM_TabBar_VcpTabBar_Method>
    // remove one tab item
    virtual void removeTab (
        VfxId id                        // [IN] tab ID
        );

    // Removes all the tabs present
    // <group DOM_TabBar_VcpTabBar_Method>
    virtual void removeAllTabs ();    

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

#if defined(__MMI_VUI_COSMOS_CP__)
    // <group DOM_TabBar_VcpTabBar_Property>
    void setIsHighlightedTextScrolling(VfxBool state);

    // <group DOM_TabBar_VcpTabBar_Property>
    VfxBool getIsHighlightedTextScrolling();

    
    void setTabNotification(VfxId tabId, VfxResId resId);
    void setTabNotification(VfxId tabId, const VfxWChar *mem);
    void setTabNotification(VfxId tabId, const VfxWString &text);
    
    void setTabNotification(VfxId tabId, VfxResId resId, VfxImageSrc icon);   
    void setTabNotification(VfxId tabId, const VfxWChar *mem, VfxImageSrc icon);
    void setTabNotification(VfxId tabId, const VfxWString &text, VfxImageSrc icon);

#endif

#if defined(__MMI_VUI_COSMOS_CP__)
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
#endif

    // Returns number of tabs in the bar 
    // <group DOM_TabBar_VcpTabBar_Property>
    virtual VfxS32 getTabCount()
    {
        return m_count;
    }    

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
    virtual void onDeinit()
    {
        VfxControl::onDeinit();
    }

    // <group DOM_TabBar_VcpTabBar_Override>
    // Update the title display
    virtual void onUpdate();
#if defined(__MMI_VUI_COSMOS_CP__)
    virtual void onDraw(VfxDrawContext &dc);
#endif

    // Implementation
private:
    // <group DOM_TabBar_VcpTabBar_Implementation>
    enum
    {
        INVALID_TAB_ID = 0xFFFFFFFF,
#if !defined(__MMI_VUI_COSMOS_CP__)
        LEFT_MARGIN = 0,
        RIGHT_MARGIN = 0,
#endif    
#if defined(__MMI_MAINLCD_320X480__)
        DEFAULT_THICKNESS = 50,
        FONT_SIZE = 13,
        VERT_TAB_HEIGHT = 62,

        HOR_TAB_GAP = 0,
        VERT_TAB_GAP = 0,

        STD_ICON_WIDTH = 18,
        STD_ICON_HEIGHT = 18,
#if defined(__MMI_VUI_COSMOS_CP__)
        LEFT_MARGIN = 3,
        RIGHT_MARGIN = 3,
#endif

        BUTTON_LEFT_MARGIN_HL = 4,
        BUTTON_TOP_MARGIN_HL = 4,
        BUTTON_RIGHT_MARGIN_HL = 4,        
        BUTTON_BOTTOM_MARGIN_HL = 2,
        
        BUTTON_LEFT_MARGIN_N = 8,
        BUTTON_TOP_MARGIN_N = 8,
        BUTTON_RIGHT_MARGIN_N = 8,
        BUTTON_BOTTOM_MARGIN_N = 4,

        EXTRA_WIDTH_TO_COVER_SEP_LINE = 8,        
        LINE_THICKNESS  = 5,

#elif defined(__MMI_MAINLCD_480X800__)
        DEFAULT_THICKNESS = 85,
        FONT_SIZE = 20,
        VERT_TAB_HEIGHT = 62,

        HOR_TAB_GAP = 0,
        VERT_TAB_GAP = 0,

#if defined(__MMI_VUI_COSMOS_CP__)
        LEFT_MARGIN = 1,
        RIGHT_MARGIN = 1,
#endif

        STD_ICON_WIDTH = 36,
        STD_ICON_HEIGHT = 36,

        BUTTON_LEFT_MARGIN_HL = 7,
        BUTTON_TOP_MARGIN_HL = 7,
        BUTTON_RIGHT_MARGIN_HL = 7,        
        BUTTON_BOTTOM_MARGIN_HL = 6,
        
        BUTTON_LEFT_MARGIN_N = 10,
        BUTTON_TOP_MARGIN_N = 10,
        BUTTON_RIGHT_MARGIN_N = 10,
        BUTTON_BOTTOM_MARGIN_N = 12,

        EXTRA_WIDTH_TO_COVER_SEP_LINE = 12,
        LINE_THICKNESS  = 9,
        VCP_TABBAR_NOTIFICATION_POSITION_OFFSET = 8,

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        DEFAULT_THICKNESS = 45, 
        FONT_SIZE = 12,
        VERT_TAB_HEIGHT = 62,
        
        HOR_TAB_GAP = 0,
        VERT_TAB_GAP = 0,

#if defined(__MMI_VUI_COSMOS_CP__)
        LEFT_MARGIN = 2,
        RIGHT_MARGIN = 2,
#endif

        STD_ICON_WIDTH = 16,
        STD_ICON_HEIGHT = 16,


        BUTTON_LEFT_MARGIN_HL = 4,
        BUTTON_TOP_MARGIN_HL = 4,
        BUTTON_RIGHT_MARGIN_HL = 4,        
        BUTTON_BOTTOM_MARGIN_HL = 1,
        
        BUTTON_LEFT_MARGIN_N = 7,
        BUTTON_TOP_MARGIN_N = 7,
        BUTTON_RIGHT_MARGIN_N = 7,
        BUTTON_BOTTOM_MARGIN_N = 4,

        EXTRA_WIDTH_TO_COVER_SEP_LINE = 12,
        LINE_THICKNESS  = 5,
        VCP_TABBAR_NOTIFICATION_POSITION_OFFSET = 2,
#else
        DEFAULT_THICKNESS = 50,
        FONT_SIZE = 13,
        VERT_TAB_HEIGHT = 62,

        HOR_TAB_GAP = 0,
        VERT_TAB_GAP = 0,

#if defined(__MMI_VUI_COSMOS_CP__)
        LEFT_MARGIN = 3,
        RIGHT_MARGIN = 3,
#endif

        STD_ICON_WIDTH = 18,
        STD_ICON_HEIGHT = 18,

        BUTTON_LEFT_MARGIN_HL = 4,
        BUTTON_TOP_MARGIN_HL = 4,
        BUTTON_RIGHT_MARGIN_HL = 4,        
        BUTTON_BOTTOM_MARGIN_HL = 1,
        
        BUTTON_LEFT_MARGIN_N = 7,
        BUTTON_TOP_MARGIN_N = 7,
        BUTTON_RIGHT_MARGIN_N = 7,
        BUTTON_BOTTOM_MARGIN_N = 4,

        EXTRA_WIDTH_TO_COVER_SEP_LINE = 8,
        LINE_THICKNESS  = 5,
        VCP_TABBAR_NOTIFICATION_POSITION_OFFSET = 5,
#endif
        ENUM_END
    };

#if defined(MULTI_LAYOUT_SUPPORT)
public:
#else
private:
#endif
    // set layout
    // <group DOM_TabBar_VcpTabBar_Property>
    virtual void setLayout (
        VcpTabBarLayoutEnum layout      // [IN] tab bar layout
        );

    // get layout
    // RETURNS: VcpTabBarLayoutEnum
    // <group DOM_TabBar_VcpTabBar_Property>
    virtual VcpTabBarLayoutEnum getLayout () const
    {
        return m_layout;
    }
    // Implementation
private:
    // <group DOM_TabBar_VcpTabBar_Implementation>
    // list of item
    VfxObjList m_list;

#if defined(__MMI_VUI_COSMOS_CP__)    
    // <group DOM_TabBar_VcpTabBar_Implementation>
    // list of separators
    VfxObjList m_sepList;
    VfxObjList m_counterList;
#endif
    // <group DOM_TabBar_VcpTabBar_Implementation>
    // number of items
    VfxS32 m_count;

    // <group DOM_TabBar_VcpTabBar_Implementation>
    // tab bout layout
    VcpTabBarLayoutEnum m_layout;

#if defined(__MMI_VUI_COSMOS_CP__)    
    // <group DOM_TabBar_VcpTabBar_Implementation>
    // highlight line
    VfxFrame    *m_tabLine;
#endif

    // <group DOM_TabBar_VcpTabBar_Implementation>
    // highlighted tab ID
    VfxId m_highlightedId;

#if defined(__MMI_VUI_COSMOS_CP__)
    // <group DOM_TabBar_VcpTabBar_Implementation>
    // TRUE means the highlighted tab would have scrolling text. 
    // Other tabs would have truncated text.
    VfxBool m_isHighlightedTextScrolling;
#endif
    // <group DOM_TabBar_VcpTabBar_Implementation>
    // Margin width
    VfxS32 m_margin;

#if defined(__MMI_VUI_COSMOS_CP__)
    VfxFrame *m_iconOnTop;
#endif

    // <group DOM_TabBar_VcpTabBar_Implementation>
    // update button while bounds change
    void onBoundsChanged (VfxFrame *frame, const VfxRect &old) {checkUpdate();}

    // <group DOM_TabBar_VcpTabBar_Implementation>
    // on button clicked, emit tab switch event
    void onButtonClicked (VfxObject* sender, VfxId Id);

    // <group DOM_TabBar_VcpTabBar_Implementation>
    // on button pressed, change tab bar UI
    void onButtonStateChanged (VfxObject* sender, VfxId Id, VcpButtonStateEnum state);
};



#endif /* __VCP_TAB_BAR_H__ */

