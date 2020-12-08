/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_launcher_robot_shortcut_selector.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the shortcut selector.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_LAUNCHER_ROBOT_SHORTCUT_SELECTOR_H
#define VAPP_LAUNCHER_ROBOT_SHORTCUT_SELECTOR_H

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMIDataType.h"

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"
#include "vcp_list_menu.h"
#include "vapp_widget_primitive.h"


/*****************************************************************************
 * List Menu Custom Content Frame
 *****************************************************************************/

class VappLauncherRobotShortcutContentProvider;


class VappLauncherRobotShortcutContentFrame : public VcpListMenuCellClientBaseFrame
{
    VFX_DECLARE_CLASS(VappLauncherRobotShortcutContentFrame);

public:
    VappLauncherRobotShortcutContentFrame();

    VappLauncherRobotShortcutContentFrame(
        VfxS32 index,
        VappLauncherRobotShortcutContentProvider *contentProvider);

public:
    void setIndex(
        VfxS32 index
    );

    void bind(
        VappLauncherRobotShortcutContentProvider *contentProvider
    );

    void setAnimation(
        VfxBool isOn
    );

public:
    // Please refer to VcpListMenuCellClientBaseFrame.
    virtual void onCreateElements();

    // Please refer to VcpListMenuCellClientBaseFrame.
    virtual void onCloseElements();

    // Please refer to VcpListMenuCellClientBaseFrame.
    virtual void onLayoutElements();

    // Please refer to VcpListMenuCellClientBaseFrame.
    virtual void onUpdateElements();

private:
    enum
    {
        MAX_TEXT_LEN = MMI_APP_NAME_MAX_LEN,
        MAX_TEXT_SIZE = MAX_TEXT_LEN + 1
    };

    enum
    {
#if defined(__MMI_MAINLCD_480X800__)
        TEXT_LEFT_GAPS   = 0,
        TEXT_RIGHT_GAPS  = 14,
        TEXT_ANI_OFFSET_Y = 12
#elif defined(__MMI_MAINLCD_320X480__)
        TEXT_LEFT_GAPS   = 0,
        TEXT_RIGHT_GAPS  = 10,
        TEXT_ANI_OFFSET_Y = 8
#elif defined(__MMI_MAINLCD_240X400__)
        TEXT_LEFT_GAPS   = 0,
        TEXT_RIGHT_GAPS  = 5,
        TEXT_ANI_OFFSET_Y = 5
#else /* defined(__MMI_MAINLCD_240X320__) */
        TEXT_LEFT_GAPS   = 0,
        TEXT_RIGHT_GAPS  = 5,
        TEXT_ANI_OFFSET_Y = 5
#endif /* defined(__MMI_MAINLCD_240X320__) */
    };

private:
    VfxS32 m_index;
    VfxWeakPtr <VappLauncherRobotShortcutContentProvider> m_contentProvider;
    VfxTextFrame *m_text;
    VfxFrame *m_icon;
    VfxBool m_isAnimationOn;
    VfxBool m_isAnimated;

    static const VfxFloat s_textAniStartOpacity;

private:
    const VappWidgetId *getPackage() const;
};


/*****************************************************************************
 * List Menu Content Provider
 *****************************************************************************/

class VappLauncherRobotShortcutContentProvider :
    public VfxObject,
    public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappLauncherRobotShortcutContentProvider);

// Constructor / Destructor
public:
    // Default constructor
    VappLauncherRobotShortcutContentProvider();

    // Default destructor
    virtual ~VappLauncherRobotShortcutContentProvider();

// Method
public:
    // This function updates the content provider.
    void updateContent();

    // This function sets the blocked widget ID list.
    void setBlockedList(
        VappWidgetId **list,    // [IN] Widget ID list
        VfxS32 num              // [IN] Size of the list
    );

    // This function checks if the widget ID is blocked.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isBlocked(
        const VappWidgetId &id  // [IN] Widget ID
    ) const;

    // This function sets the opening animation on or off.
    void setAnimation(
        VfxBool isOn            // [IN] On or off
    );

    // This function gets the index-th widget ID in the white list. You can use
    // 'getCount' to get the total number of widget ID in the white list.
    // RETURNS: Widget ID
    //
    // SEE ALSO: getCount
    const VappWidgetId *getId(
        VfxS32 index            // [IN] Index
    ) const;

// Override
public:
    // Please refer to IVcpListMenuContentProvider.
    virtual VfxU32 getCount() const;

    // Please refer to IVcpListMenuContentProvider.
    virtual VfxBool getMenuEmptyText(
        VfxWString &text,
        VcpListMenuTextColorEnum &color
    );

    // Please refer to IVcpListMenuContentProvider.
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,
        VfxFrame *parentFrame
    );

    // Please refer to IVcpListMenuContentProvider.
    virtual void closeItemCustomContentFrame(
        VfxU32 index,
        VcpListMenuCellClientBaseFrame *cell
    );

// Enum
private:
    enum
    {
        MAX_NAME_LEN = 40,
        MAX_NAME_SIZE = MAX_NAME_LEN + 1
    };

// Variable
private:
    // Shortcuts in the non-blocked list.
    VappWidgetId **m_list;

    // Number of shortcuts in the non-blocked list.
    VfxS32 m_num;

    // Shortcuts in the blocked list.
    VappWidgetId **m_blockedList;

    // Number of shortcuts in the blocked list.
    VfxS32 m_blockedNum;

    VfxBool m_isAnimationOn;

// Method
private:
    // This function sorts the list according to their names.
    void sortList(
        VappWidgetId **list,    // [IN] Widget ID list
        VfxS32 size             // [IN] Size of the list
    );

    // This function creates the white widget ID list.
    // RETURNS: the created list
    VappWidgetId **createWhiteList(
        VfxS32 &whiteWidgetNum  // [OUT] Number of the created list
    );
};


/*****************************************************************************
 * Shortcut Selector Page
 *****************************************************************************/

class VappLauncherRobotShortcutSelector : public VfxPage
{
    VFX_DECLARE_CLASS(VappLauncherRobotShortcutSelector);

// Constructor / Destructor
public:
    // Default constructor
    VappLauncherRobotShortcutSelector();

    // Default destructor
    virtual ~VappLauncherRobotShortcutSelector();

// Signal
public:
    // This signal is emitted when a shortcut is selected.
    VfxSignal2 <
        VfxPage *,              // [IN] Page
        const VappWidgetId &    // [IN] ID of the selected shortcut
    > m_signalSelected;

// Method
public:
    // This function shows the selector.
    void show();

    // This function sets the blocked shortcut of the selector.
    void setBlockedList(
        VappWidgetId **list,    // [IN] Widget ID array
        VfxS32 num              // [IN] Number of elements in the array
    );

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

    // Please refer to VfxFrame.
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event
    );

    // Please refer to VfxControl.
    virtual VfxBool onPreviewPenInput(
        VfxPenEvent &event
    );

// Enum
private:
    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        ITEM_HEIGHT = 106,
    #elif defined(__MMI_MAINLCD_320X480__)
        ITEM_HEIGHT = 67,
    #elif defined(__MMI_MAINLCD_240X400__)
        ITEM_HEIGHT = 52,
    #else /* defined(__MMI_MAINLCD_240X320__) */
        ITEM_HEIGHT = 52,
    #endif /* defined(__MMI_MAINLCD_240X320__) */

        CACHE_LEN = 32 * ITEM_HEIGHT
    };

// Variable
private:
    // List menu.
    VcpListMenu *m_menu;

    // Content provider.
    VappLauncherRobotShortcutContentProvider *m_contentProvider;

    // Timer for 2nd pass loder.
    VfxTimer *m_timer2ndPassLoader;

// Implementation
private:
    // This function creates the title bar.
    void createTitleBar();

    // This function update the menu.
    void updateMenu();

    // This function creates the objects for the 2nd pass loader.
    void create2ndPassLoader();

    // This function is the timeout function to load the 2nd pass components.
    void on2ndPassLoader(
        VfxTimer *timer         // [IN] Timer
    );

    // This function handles the signal when a cell of the list menu is tapped.
    void onItemTapped(
        VcpListMenu *menu,      // [IN] List menu
        VfxU32 index            // [IN] Index of the cell
    );
};


#endif /* VAPP_LAUNCHER_ROBOT_SHORTCUT_SELECTOR_H */

