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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_desktop_widget_selector.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file defines the widget selector.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_DESKTOP_WIDGET_SELECTOR_H
#define VAPP_DESKTOP_WIDGET_SELECTOR_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vcp_list_menu.h"
#include "vapp_app_widget_kit.h"
#include "vapp_app_widget_primitive.h"
#include "vapp_desktop_popup_menu.h"


/*****************************************************************************
 * List Menu Custom Content Frame
 *****************************************************************************/

class VappDesktopContentProvider;


class VappDesktopContentFrame : public VcpListMenuCellClientBaseFrame
{
public:

    VappDesktopContentFrame(
        VappAppWidgetId widgetId
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
        MAX_TEXT_SIZE = MAX_TEXT_LEN + 1,

    #if defined(__MMI_MAINLCD_480X800__)
        TEXT_LEFT_GAPS   = 0,
        TEXT_RIGHT_GAPS  = 14,
        IMG_LEFT_GAPS    = 14,
        IMG_RIGHT_GAPS   = 14,
        IMG_MAX_WIDTH    = 120,
        TEXT_ANI_OFFSET_Y = 12
    #elif defined(__MMI_MAINLCD_320X480__)
        TEXT_LEFT_GAPS   = 0,
        TEXT_RIGHT_GAPS  = 10,
        IMG_LEFT_GAPS    = 10,
        IMG_RIGHT_GAPS   = 10,
        IMG_MAX_WIDTH    = 80,
        TEXT_ANI_OFFSET_Y = 8
    #elif defined(__MMI_MAINLCD_240X400__)
        TEXT_LEFT_GAPS   = 0,
        TEXT_RIGHT_GAPS  = 5,
        IMG_LEFT_GAPS    = 5,
        IMG_RIGHT_GAPS   = 5,
        IMG_MAX_WIDTH    = 60,
        TEXT_ANI_OFFSET_Y = 5
    #else /* defined(__MMI_MAINLCD_240X320__) */
        TEXT_LEFT_GAPS   = 0,
        TEXT_RIGHT_GAPS  = 5,
        IMG_LEFT_GAPS    = 5,
        IMG_RIGHT_GAPS   = 5,
        IMG_MAX_WIDTH    = 60,
        TEXT_ANI_OFFSET_Y = 5
    #endif /* defined(__MMI_MAINLCD_240X320__) */
    };

private:
    // app name
    VfxTextFrame *m_text;

    // app icon
    VfxFrame *m_icon;

    VappAppWidgetId m_widgetId;
};


/*****************************************************************************
 * List Menu Content Provider
 *****************************************************************************/

class VappDesktopContentProvider :
    public VfxObject,
    public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappDesktopContentProvider);

// Constructor / Destructor
public:
    // Default constructor
    VappDesktopContentProvider();

    // Default destructor
    ~VappDesktopContentProvider();

// Method
public:
    // This function sets the text for the empty menu.
    void setEmptyText(
        VfxResId resId          // [IN] Text resource ID
    );

    // This function sets the control for the widget kit.
    void setKitControl(
        VappAppWidgetKitControl &kitControl     // [IN] Kit control
    );

    // This function updates the content provider.
    void updateContent();

    // This function sets the blocked widget ID list.
    void setBlockedList(
        VappAppWidgetId **list, // [IN] Widget ID list
        VfxS32 num              // [IN] Size of the list
    );

    // This function checks if the widget ID is blocked.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isBlocked(
        const VappAppWidgetId &id  // [IN] Widget ID
    ) const;

    // This function gets the index-th widget ID in the white list. You can use
    // 'getCount' to get the total number of widget ID in the white list.
    // RETURNS: Widget ID
    //
    // SEE ALSO: getCount
    const VappAppWidgetId *getId(
        VfxS32 index            // [IN] Index
    ) const;

// Override
public:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

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

// Variable
private:
    // Text for empty menu.
    VfxResId m_emptyMenuText;

    // Control for widget kit.
    VappAppWidgetKitControl m_kitCtrl;

    // Widgets in the non-blocked list.
    VappAppWidgetId **m_list;

    // Number of widgets in the non-blocked list.
    VfxS32 m_num;

    // Widgets in the blocked list.
    VappAppWidgetId **m_blockedList;

    // Number of widgets in the blocked list.
    VfxS32 m_blockedNum;

    // Cached widget icon.
    VfxFrame **m_cachedIcon;

    // Cached widget text.
    VfxTextFrame **m_cachedText;

// Method
private:
    // This function sorts the list according to their names.
    void sortList(
        VappAppWidgetId **list,     // [IN] Widget ID list
        VfxS32 size                 // [IN] Size of the list
    );

    // This function creates the white widget ID list.
    // RETURNS: the created list
    VappAppWidgetId **createWhiteList(
        VfxS32 &whiteWidgetNum      // [OUT] Number of the created list
    );

    // This function creates the cached text array.
    // RETURNS: the cached text array.
    VfxTextFrame **newCachedTextArray(
        VfxS32 size                 // [IN] Size of the array
    );

    // This function deletes the cached text array.
    // RETURNS: the cached text array.
    void deleteCachedTextArray(
        VfxTextFrame **cachedText,  // [IN] Array
        VfxS32 size                 // [IN] Size of the array
    );

    // This function creates the cached icon array.
    // RETURNS: the cached icon array.
    VfxFrame **newCachedIconArray(
        VfxS32 size                 // [IN] Size of the array
    );

    // This function deletes the cached icon array.
    void deleteCachedIconArray(
        VfxFrame **cachedIcon,      // [IN] Array
        VfxS32 size                 // [IN] Size of the array
    );
};


/*****************************************************************************
 * Widget Selector
 *****************************************************************************/

class VappDesktopWidgetSelector : public VappDesktopPopupMenu
{
   VFX_DECLARE_CLASS(VappDesktopWidgetSelector);

// Constructor / Destructor
public:
    // Default constructor
    VappDesktopWidgetSelector();

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VappDesktopPopupMenu.
    virtual VfxBool getTitleText(
        VfxWString &text
    );

// Enum
private:
    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        ITEM_HEIGHT = 94,
    #elif defined(__MMI_MAINLCD_320X480__)
        ITEM_HEIGHT = 74,
    #elif defined(__MMI_MAINLCD_240X400__)
        ITEM_HEIGHT = 55,
    #else /* defined(__MMI_MAINLCD_240X320__) */
        ITEM_HEIGHT = 55,
    #endif /* defined(__MMI_MAINLCD_240X320__) */

        CACHE_LEN = 32 * ITEM_HEIGHT
    };

// Variable
private:
    // List menu.
    VcpListMenu *m_menu;

    // Content provider.
    VappDesktopContentProvider *m_contentProvider;

    // Timer for 2nd pass loder.
    VfxTimer *m_timer2ndPassLoader;

// Implementation
private:
    // This function creates the content provider.
    void createContentProvider();

    // This function creates the menu.
    void createMenu();

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


/*****************************************************************************
 * Launch Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vapp_desktop_launch_widget_selector
 * DESCRIPTION
 *  This function launch the widget selector.
 * PARAMETERS
 *  callback    [IN]    Callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void vapp_desktop_launch_widget_selector(
    VappDesktopPopupMenu::CallbackFunc callback);


#endif /* defined(__MMI_VUI_LAUNCHER__) */
#endif /* VAPP_DESKTOP_WIDGET_SELECTOR_H */

