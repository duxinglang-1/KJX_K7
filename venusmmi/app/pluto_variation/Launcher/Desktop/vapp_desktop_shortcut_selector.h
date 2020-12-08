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
 *  vapp_desktop_shortcut_selector.h
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

#ifndef VAPP_DESKTOP_SHORTCUT_SELECTOR_H
#define VAPP_DESKTOP_SHORTCUT_SELECTOR_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vcp_list_menu.h"
#include "vapp_app_widget_primitive.h"
#include "vapp_desktop_popup_menu.h"
#include "vapp_desktop_widget_selector.h"


/*****************************************************************************
 * Define
 *****************************************************************************/

/* Max. size of context memory which will be allocated from ASM. */
#define VAPP_DESKTOP_SHORTCUT_SELECTOR_MAX_CNTX_MEM_SIZE          (300 * 1024)

/*****************************************************************************
 * Shortcut Selector Page
 *****************************************************************************/

class VappDesktopShortcutSelector : public VappDesktopPopupMenu
{
    VFX_DECLARE_CLASS(VappDesktopShortcutSelector);

// Constructor / Destructor
public:
    // Default constructor
    VappDesktopShortcutSelector();

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

        CACHE_LEN = 25 * ITEM_HEIGHT
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
    // This function sets the blocked shortcut of the selector.
    void createContentProvider();

    // This function create the menu.
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
 *  vapp_desktop_launch_shortcut_selector
 * DESCRIPTION
 *  This function launches the shortcut selector.
 * PARAMETERS
 *  callback    [IN]    Callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void vapp_desktop_launch_shortcut_selector(
    VappDesktopPopupMenu::CallbackFunc callback);


#endif /* defined(__MMI_VUI_LAUNCHER__) */
#endif /* VAPP_DESKTOP_SHORTCUT_SELECTOR_H */

