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
*  vcp_tab_title_bar.h
*
* Project:
* --------
*  Venus UI Components
*
* Description:
* ------------
*  Title Tab bar component
*
* Author:
* -------
 * -------
*
*============================================================================
*****************************************************************************/

#ifndef __VCP_TAB_TITLE_BAR_H__
#define __VCP_TAB_TITLE_BAR_H__

/***************************************************************************** 
* Include
*****************************************************************************/
#include "vcp_tab_bar.h"
#include "vfx_page_bar.h"
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vcp_state_image.h"
#include "vfx_string.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_signal.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"

#if defined(__MMI_VUI_COSMOS_CP__)

/***************************************************************************** 
* Define
*****************************************************************************/

// Maximum tabs allowed
// <group DOM_TabTitleBar_Macro&Enum_Macro>
#define VCP_TTABBAR_MAX_TAB_LIMIT 4

/***************************************************************************** 
* For XML support
*****************************************************************************/

struct VcpTabTitleBarItem : public VfxBase
{
    VfxS32               id;
    VcpStateImage    imagelist;
    VfxWString         text;
};


/***************************************************************************** 
* Class VcpTabTitleBar
* Tab Title Bar is a page bar. It is placed as a top page bar.
* It provides the API to add/modify/remove tabs. 
* It will notify whenever user changes a tab. 
*****************************************************************************/
class VcpTabTitleBar : public VfxPageBar
{
    VFX_DECLARE_CLASS(VcpTabTitleBar);

    // Constructor / Destructor
public:        
    // Default constructor
    // <group DOM_TabTitleBar_VcpTabTitleBar_Constructor/Destructor>
    VcpTabTitleBar();



    // Implementation
private:
    // <group DOM_TabTitleBar_VcpTabTitleBar_Implementation>
    VcpTabBar  *m_bar;

public:
    // <group DOM_TabTitleBar_VcpTabTitleBar_Event>
    // This signal is invoked when the tab is switched    
    VfxSignal2 <
        VfxObject*, // Object pointer to tab title bar
        VfxId>         // Id of new selected tab
        m_signalTabSwitched;

    // Method
public:
    // <group DOM_TabTitleBar_VcpTabTitleBar_Method>
    // Add one tab item
        void addTab2 (
            VfxId id,                       // [IN] tab ID
            const VcpStateImage &imageList,     // [IN] Icon image list  (for normal, pressed, diabled and highlighted states)
            VfxResId resId,         // [IN] text
            VfxId beforeId = INVALID_TAB_ID // [IN] where to insert the tab item, insert to the end by default
            );

    // <group DOM_TabTitleBar_VcpTabTitleBar_Method>
    // Add one tab item
    void addTab2 (
        VfxId id,                       // [IN] tab ID
        const VcpStateImage &imageList,     // [IN] Icon image list  (for normal, pressed, diabled and highlighted states)
        const VfxWChar *mem,         // [IN] text
        VfxId beforeId = INVALID_TAB_ID // [IN] where to insert the tab item, insert to the end by default
        );

    // <group DOM_TabTitleBar_VcpTabTitleBar_Method>
    // Add one tab item
    void addTab (
        VfxId id,                       // [IN] tab ID
        const VcpStateImage &imageList,     // [IN] Icon image list  (for normal, pressed, diabled and highlighted states)
        const VfxWString &text,         // [IN] text
        VfxId beforeId = INVALID_TAB_ID // [IN] where to insert the tab item, insert to the end by default
        );

    // <group DOM_TabBar_VcpTabBar_Method>
    // Update one tab item 
    virtual void changeTab(VfxId id, const VcpStateImage &imageList);

    
    // <group DOM_TabBar_VcpTabBar_Method>
    // Update one tab item 
    virtual void changeTab(VfxId id, VfxResId resId);

    // <group DOM_TabBar_VcpTabBar_Method>
    // Update one tab item 
    virtual void changeTab(VfxId id, const VfxWChar *mem);

    // <group DOM_TabBar_VcpTabBar_Method>
    // Update one tab item 
    virtual void changeTab(VfxId id, const VfxWString &text);

    // <group DOM_TabBar_VcpTabBar_Method>
    // Update one tab item 
    virtual void changeTab(VfxId id, VfxResId resId, const VcpStateImage &imageList);

	    // <group DOM_TabBar_VcpTabBar_Method>
    // Update one tab item 
    virtual void changeTab(VfxId id, const VfxWChar *mem, const VcpStateImage &imageList);

	    // <group DOM_TabBar_VcpTabBar_Method>
    // Update one tab item 
    virtual void changeTab(VfxId id, const VfxWString &text, const VcpStateImage &imageList);

    // <group DOM_TabTitleBar_VcpTabTitleBar_Method>
    // Remove one tab item
    void removeTab (
        VfxId id                        // [IN] tab ID
        );

    // <group DOM_TabTitleBar_VcpTabTitleBar_Method>
    // Remove all tab items
    virtual void removeAllTabs();

    // Returns the number of tabs currently present
    // <group DOM_TabTitleBar_VcpTabTitleBar_Method>
    VfxS32 getTabCount() const
    {
        return m_bar->getTabCount();
    }
    
    // Enable / disable one tab item
    // DEFAULT VALUE:
    // 	VFX_TRUE
    // <group DOM_TabTitleBar_VcpTabTitleBar_Property>
    void setTabEnabled (
        VfxId id,                       // [IN] tab ID
        VfxBool isEnabled              // [IN] whether it is enabled
        );

    // Get whether one tab is enabled
    // RETURNS: 
    // 	VfxBool
    // <group DOM_TabTitleBar_VcpTabTitleBar_Property>
    VfxBool getTabIsEnabled (
        VfxId id                        // [IN] tab ID
        )  ;


    // <group DOM_TabTitleBar_VcpTabTitleBar_Property>
    // Set highlighted item
    // DEFAULT VALUE:
    // 	First added tab
    void setHighlightedTab (
        VfxId id                        // [IN] tab ID
        );    

    // <group DOM_TabTitleBar_VcpTabTitleBar_Property>
    // Get which item to be highlighted
    // RETURNS: 
    // 	Id of currently highlighted Tab
    VfxId getHighlightedTab () const;

    // <group DOM_TabBar_VcpTabTitleBar_Property>
    void setIsHighlightedTextScrolling(VfxBool state);

    // <group DOM_TabBar_VcpTabTitleBar_Property>
    VfxBool getIsHighlightedTextScrolling();

    void setTabNotification(VfxId tabId, VfxResId resId);    
    void setTabNotification(VfxId tabId, const VfxWChar *mem);
    void setTabNotification(VfxId tabId, const VfxWString &text);
    
    void setTabNotification(VfxId tabId, VfxResId resId, VfxImageSrc icon);    
    void setTabNotification(VfxId tabId, const VfxWChar *mem, VfxImageSrc icon);
    void setTabNotification(VfxId tabId, const VfxWString &text, VfxImageSrc icon);

    // Override
protected:                           
    // <group DOM_TabTitleBar_VcpTabTitleBar_Override>
    // On init
    virtual void onInit();

    // <group DOM_TabTitleBar_VcpTabTitleBar_Override>
    // Update the title display
    virtual void onUpdate();


    // <group DOM_TabTitleBar_VcpTabTitleBar_Override>
    // Makes the bar translucent
    virtual void onSetTranslucent(VfxBool translucent);    

    // Implementation
private:
    // <group DOM_TabTitleBar_VcpTabTitleBar_Implementation>
    enum
    {
        INVALID_TAB_ID = 0xFFFFFFFF,
#if defined(__MMI_MAINLCD_320X480__)
        DEFAULT_HEIGHT = 50, 
#elif defined(__MMI_MAINLCD_480X800__)
        DEFAULT_HEIGHT = 85,
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        DEFAULT_HEIGHT = 45,
#else
        DEFAULT_HEIGHT = 50,
#endif
        GAP = 2
    };

    // Implementation
private:
    // <group DOM_TabTitleBar_VcpTabTitleBar_Implementation>
    // Update button while bounds change
    void onBoundsChanged (VfxFrame *frame, const VfxRect &old) {checkUpdate();}

    // <group DOM_TabTitleBar_VcpTabTitleBar_Implementation>
    // On button clicked, emits tab switch event
    void onTabPress(VfxObject* sender, VfxId Id);
};


#endif /* #if defined (__MMI_VUI_COSMOS_CP__)  */ 
#endif /* __VCP_TAB_TITLE_BAR_H__ */

