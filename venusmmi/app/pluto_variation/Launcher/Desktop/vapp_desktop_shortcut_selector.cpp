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
 *  vapp_desktop_shortcut_selector.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the shortcut selector.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_app_widget_kit.h"
#include "vapp_app_widget_archive.h"
#include "vapp_app_widget_primitive.h"
#include "vapp_desktop_def.h"
#include "vapp_desktop_primitive.h"
#include "vapp_desktop_popup_menu.h"
#include "vapp_desktop_shortcut_selector.h"
#include "mmi_rp_vapp_desktop_def.h"

//
// Include C headers without extern "C" internally.
//
extern "C"
{
#include "AppMgrSrvGprot.h"
#include "IdleGprot.h"
}


/*****************************************************************************
 * Shortcut Selector Page
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(
    "VappDesktopShortcutSelector",
    VappDesktopShortcutSelector,
    VappDesktopPopupMenu);


VappDesktopShortcutSelector::VappDesktopShortcutSelector() :
    m_menu(NULL),
    m_contentProvider(NULL)
{
    // Do nothing.
}


void VappDesktopShortcutSelector::onInit()
{
    VappDesktopPopupMenu::onInit();

    createContentProvider();

    createMenu();

    create2ndPassLoader();
}


VfxBool VappDesktopShortcutSelector::getTitleText(VfxWString &text)
{
    text.loadFromRes(STR_ID_VAPP_DESKTOP_SELECT_SHORTCUT);

    return VFX_TRUE;
}


void VappDesktopShortcutSelector::createContentProvider()
{
    VappAppWidgetKitControl kitControl(VFX_FALSE);
    kitControl.permit(VAPP_APP_WIDGET_SRC_SHORTCUT);

    VFX_OBJ_CREATE(m_contentProvider, VappDesktopContentProvider, this);
    m_contentProvider->setEmptyText(STR_ID_VAPP_DESKTOP_NO_SHORTCUT);
    m_contentProvider->setKitControl(kitControl);

    //
    // We don't allow users to select home screen or main menu as the shortcut.
    // In addition, for shortcuts that are already present on the desktop, we do
    // not allow the users to select them again.
    //
    VappAppWidgetArchiveIterator *iter;
    VfxS32 entryCount = 0;

    VFX_OBJ_CREATE(iter, VappAppWidgetArchiveIterator, this);

    if (!iter->readFirst(entryCount))
    {
        entryCount = 0; // On failed, entryCount is 0.
    }

    entryCount += 2;    // 2: for deskstop and drawer APP below.

    VappAppWidgetId **widgetId = VappAppWidgetId::newArray(entryCount, this);
    VfxS32 totalNum = 0;

    widgetId[totalNum++]->assignWith(
                            VAPP_APP_WIDGET_SRC_SHORTCUT,
                            "native.mtk.desktop");

    widgetId[totalNum++]->assignWith(
                            VAPP_APP_WIDGET_SRC_SHORTCUT,
                            "native.mtk.drawer");

    VfxPoint pos;

    for (VfxBool isSuccess = iter->readNext(*widgetId[totalNum], pos);
         isSuccess == VFX_TRUE;
         isSuccess = iter->readNext(*widgetId[totalNum], pos))
    {
        if (widgetId[totalNum]->getSource() == VAPP_APP_WIDGET_SRC_SHORTCUT)
        {
            VFX_ASSERT(totalNum < entryCount);
            totalNum++;
        }
    }

    m_contentProvider->setBlockedList(widgetId, totalNum);

    VappAppWidgetId::deleteArray(widgetId, entryCount);

    VFX_OBJ_CLOSE(iter);
}


void VappDesktopShortcutSelector::createMenu()
{
    //
    // Close the old list menu.
    //
    VFX_OBJ_CLOSE(m_menu);

    //
    // Update the content provider
    //
    m_contentProvider->updateContent();

    //
    // Create a new list menu.
    //
    VFX_OBJ_CREATE(m_menu, VcpListMenu, this);
    m_menu->setCacheLen(1);
    m_menu->setBgColor(VFX_COLOR_WHITE);
    m_menu->setRect(getContentBounds());
    m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_CUSTOM);
    m_menu->setItemHeight(ITEM_HEIGHT);
    m_menu->setContentProvider(m_contentProvider);
    m_menu->m_signalItemTapped.connect(this, &VappDesktopShortcutSelector::onItemTapped);

    m_menu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
}


void VappDesktopShortcutSelector::create2ndPassLoader()
{
    //
    // Create timer to handle the 2nd pass of APP's activation. The timer will
    // expire immediately, i.e., 1 msec, because we only want to accelerate the
    // rendering time of the first frame used in SSE.
    //
    VFX_OBJ_CREATE(m_timer2ndPassLoader, VfxTimer, this);
    m_timer2ndPassLoader->setStartDelay(1);
    m_timer2ndPassLoader->m_signalTick.connect(this, &VappDesktopShortcutSelector::on2ndPassLoader);

    //
    // Start timer.
    //
    m_timer2ndPassLoader->start();
}


void VappDesktopShortcutSelector::on2ndPassLoader(VfxTimer *timer)
{
    m_menu->setCacheLen(CACHE_LEN);
    m_menu->updateAllItems();
}


void VappDesktopShortcutSelector::onItemTapped(VcpListMenu *menu, VfxU32 index)
{
    VFX_ASSERT(m_contentProvider);

    const VappAppWidgetId *id = m_contentProvider->getId(index);

    if (m_callback)
    {
        m_callback(*id);
    }

    closeScreen();
}


/*****************************************************************************
 * Launch Function
 *****************************************************************************/

static VappDesktopShortcutSelector *s_vapp_desktop_shortcut_selector = NULL;


static void vapp_desktop_shortcut_selector_create(
    VappDesktopPopupMenu::CallbackFunc callback)
{
    VFX_ASSERT(s_vapp_desktop_shortcut_selector == NULL);

    set_small_screen();

    VfxAppCatScr::initalizeWithScrAsmSize(VAPP_DESKTOP_SHORTCUT_SELECTOR_MAX_CNTX_MEM_SIZE);

    VFX_OBJ_CREATE(
        s_vapp_desktop_shortcut_selector,
        VappDesktopShortcutSelector,
        VfxAppCatScr::getContext());

    s_vapp_desktop_shortcut_selector->registerCallback(callback);
}


static void vapp_desktop_shortcut_selector_release()
{
    VFX_OBJ_CLOSE(s_vapp_desktop_shortcut_selector);

    VfxAppCatScr::deinitalize();

    reset_small_screen();
}


static void vapp_desktop_shortcut_selector_enter(
    mmi_scrn_essential_struct *param)
{
    VappDesktopPopupMenu::CallbackFunc callback;
    MMI_BOOL ret;

    MMI_ASSERT(param);

    ret = mmi_frm_scrn_enter(
            param->group_id,
            param->scrn_id,
            NULL,
            NULL,
            MMI_FRM_FULL_SCRN);

    if (!ret)
    {
        return;
    }

    callback = (VappDesktopPopupMenu::CallbackFunc)param->user_data;

    vapp_desktop_shortcut_selector_create(callback);

    ExitCategoryFunction = vapp_desktop_shortcut_selector_release;
}


void vapp_desktop_launch_shortcut_selector(
    VappDesktopPopupMenu::CallbackFunc callback)
{
    mmi_frm_scrn_first_enter(
        mmi_idle_get_group_id(),
        SCR_ID_VAPP_DESKTOP_SHORTCUT_SELECTOR,
        (FuncPtr)vapp_desktop_shortcut_selector_enter,
        (void *)callback);
}

#endif /* defined(__MMI_VUI_LAUNCHER__) */

