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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_launcher_robot_widget_selector.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Widget Selector Page for Home Screen
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

#ifndef VAPP_LAUNCHER_ROBOT_WIDGET_SELECTOR_H
#define VAPP_LAUNCHER_ROBOT_WIDGET_SELECTOR_H

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_mc_include.h"
#include "vcp_page_grid.h"
#include "vapp_widget.h"
#include "vapp_widget_kit.h"
#include "vapp_launcher_robot_widget_selector.h"
#include "vcp_popup.h"


/*****************************************************************************
 * Page Grid Cell
 *****************************************************************************/

class VappLauncherRobotWidgetGridCell : public VcpPageGridCell
{
   VFX_DECLARE_CLASS(VappLauncherRobotWidgetGridCell);

// Constructor / Desctructor
public:
    // Default constructor.
    VappLauncherRobotWidgetGridCell();

// Override
public:
    // Please refer to VcpPageGridCell.
    virtual void onShowCell();

// Method
public:
    // This function sets the widget ID.
    void setWidgetId(
        const VappWidgetId &id      // [IN] Widget ID
    );

    // This function sets the opening animation on or off.
    void setAnimation(
        VfxBool isOn                // [IN] Animation on or off
    );

// Enum
private:
    enum
    {
        MAX_NAME_LEN = 40,
        MAX_NAME_SIZE = MAX_NAME_LEN + 1,

    #if defined(__MMI_MAINLCD_480X800__)
        ICON_OFFSET_X = 22,
        ICON_OFFSET_Y = 25,
        ICON_WIDTH = 72,
        ICON_HEIGHT = 72,
        TITLE_FONT_SIZE = 21,
        TITLE_OFFSET_X = 8,
        TITLE_OFFSET_Y = 115,
        TITLE_WIDTH = 104,
        TITLE_HEIGHT = 25,
        TITLE_ANI_OFFSET_Y = TITLE_OFFSET_Y + 10
    #elif defined(__MMI_MAINLCD_320X480__)
        ICON_OFFSET_X = 16,
        ICON_OFFSET_Y = 20,
        ICON_WIDTH = 48,
        ICON_HEIGHT = 48,
        TITLE_FONT_SIZE = 12,
        TITLE_OFFSET_X = 4,
        TITLE_OFFSET_Y = 73,
        TITLE_WIDTH = 72,
        TITLE_HEIGHT = 16,
        TITLE_ANI_OFFSET_Y = TITLE_OFFSET_Y + 6
    #elif defined(__MMI_MAINLCD_240X400__)
        ICON_OFFSET_X = 11,
        ICON_OFFSET_Y = 20,
        ICON_WIDTH = 38,
        ICON_HEIGHT = 38,
        TITLE_FONT_SIZE = 11,
        TITLE_OFFSET_X = 4,
        TITLE_OFFSET_Y = 60,
        TITLE_WIDTH = 52,
        TITLE_HEIGHT = 16,
        TITLE_ANI_OFFSET_Y = TITLE_OFFSET_Y + 4
    #else /* defined(__MMI_MAINLCD_240X320__) */
        ICON_OFFSET_X = 11,
        ICON_OFFSET_Y = 21,
        ICON_WIDTH = 38,
        ICON_HEIGHT = 38,
        TITLE_FONT_SIZE = 11,
        TITLE_OFFSET_X = 4,
        TITLE_OFFSET_Y = 61,
        TITLE_WIDTH = 52,
        TITLE_HEIGHT = 16,
        TITLE_ANI_OFFSET_Y = TITLE_OFFSET_Y + 4
    #endif /* defined(__MMI_MAINLCD_240X320__) */
    };

// Variable
private:
    // Widget ID.
    VappWidgetId m_id;

    // Opening animation on or off.
    VfxBool m_isAnimationOn;

    static const VfxFloat s_textAniStartOpacity;
};


/*****************************************************************************
 * Widget Selector
 *****************************************************************************/

class VappLauncherRobotWidgetSelector : public VfxPage
{
   VFX_DECLARE_CLASS(VappLauncherRobotWidgetSelector);

// Constructor / Destructor
public:
    // Default constructor
    VappLauncherRobotWidgetSelector();

    // Default destructor
    virtual ~VappLauncherRobotWidgetSelector();

// Methods
public:
    // This function shows the selector.
    void show();

    // This function sets the blocked list. The widgets in this list will not be
    // displayed in selector page. This function should be called before you
    // call 'show'.
    void setBlockedList(
        VappWidgetId **list,  // [IN] Blocked list
        VfxS32 num                  // [IN] Number of blocked widgets
    );

// Signal
public:
    // This signal is emitted when a widget is selected.
    VfxSignal2 <
        VfxPage *,                  // [IN] Page
        const VappWidgetId &        // [IN] The selected widget ID
    > m_signalSelected;

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

// Enum
private:
    enum
    {
        MAX_NAME_LEN = 40,
        MAX_NAME_SIZE = MAX_NAME_LEN + 1,

    #if defined(__MMI_MAINLCD_480X800__)
        ROW_NUM = 4,
        COLUMN_NUM = 4,
        CELL_START_X = 0,
        CELL_START_Y = 15,
        CELL_OFFSET_X = 120,
        CELL_OFFSET_Y = 178
    #elif defined(__MMI_MAINLCD_320X480__)
        ROW_NUM = 4,
        COLUMN_NUM = 4,
        CELL_START_X = 0,
        CELL_START_Y = 15,
        CELL_OFFSET_X = 80,
        CELL_OFFSET_Y = 103
    #elif defined(__MMI_MAINLCD_240X400__)
        ROW_NUM = 4,
        COLUMN_NUM = 4,
        CELL_START_X = 0,
        CELL_START_Y = 15,
        CELL_OFFSET_X = 60,
        CELL_OFFSET_Y = 85
    #else /* defined(__MMI_MAINLCD_240X320__) */
        ROW_NUM = 3,
        COLUMN_NUM = 4,
        CELL_START_X = 0,
        CELL_START_Y = 15,
        CELL_OFFSET_X = 60,
        CELL_OFFSET_Y = 87
    #endif /* defined(__MMI_MAINLCD_240X320__) */
    };

// Variable
private:
    // page grid for displaying widgets
    VcpPageGrid *m_pageGrid;

    // the widget id list
    VappWidgetId **m_widgetIdList;

    // number of widgets in widget id list
    VfxS32 m_widgetNum;

    // blocked list
    VappWidgetId **m_blockedList;

    // number of blocked widgets
    VfxS32 m_blockedNum;

    // the widget user selects
    VappWidgetId m_selectedWidget;

// Implementation
private:
    // This function creates the title bar.
    void createTitleBar();

    // This function creates the separate lines.
    void createSeparateLine();

    // This function creates the page grid.
    void createPageGrid();

    // This function creates the page grid.
    void updatePageGrid();

    // This function is used to post-update the content.
    void onPostUpdate();

    // This function handles the signal when a cell on the page grid is clicked.
    void onItemClicked(
        VfxS32 itemIndex    // [IN] Index of the cell
    );

    // This function checks if the specified widget is blocked.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isBlocked(
        const VappWidgetId &id      // [IN] Widget ID
    ) const;

    // This function creates a widget ID array, where each widget ID is not
    // blocked.
    // RETURNS: On success, return the array; otherwise, return NULL.
    VappWidgetId **createWhiteList(
        VfxS32 &whiteWidgetNum      // [OUT] Size of the array
    );

//
// This block implements the sorting function to sort the widgets on the page
// grid.
//

// Implementation
private:
    // This function sorts the widget ID list according to their names.
    void sortList(
        VappWidgetId **list,    // [IN] Widget ID
        VfxS32 size             // [IN] Size of the widget ID pointer array
    );

#if defined(__GADGET_SUPPORT__)
//
// This block implements the sanity check function for the gadget.
//

// Implementation
private:
    // This function does the sanity check.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool sanityCheckForGadget();

    // This function handles the popup clicked signal to remove the selected
    // gadget from the gadget manager.
    static void onPopupCorruptedClicked(
        VfxId id,           // [IN] Button ID
        void *userData      // [IN] User data
    );

    // This function handles the popup clicked signal to remove the selected
    // gadget from the gadget manager if the user confirms this operation.
    static void onPopupMemoryCardPlugOutClicked(
        VfxId id,           // [IN] Button ID
        void *userData      // [IN] User data
    );
#endif /* defined(__GADGET_SUPPORT__) */
};

#endif /* VAPP_LAUNCHER_ROBOT_WIDGET_SELECTOR_H */

