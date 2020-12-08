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
/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_desktop_widget_selector.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the widget selector.
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
#include "vapp_app_widget_primitive.h"
#include "vapp_app_widget_archive.h"
#include "vapp_desktop_def.h"
#include "vapp_desktop_primitive.h"
#include "vapp_desktop_popup_menu.h"
#include "vapp_desktop_widget_selector.h"
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
 * List Menu Custom Content Frame
 *****************************************************************************/

VappDesktopContentFrame::VappDesktopContentFrame(
    VappAppWidgetId widgetId) :
    m_widgetId(widgetId)
{
    m_style = VCP_LIST_MENU_CELL_STYLE_CUSTOM;
}


void VappDesktopContentFrame::onCreateElements()
{
    VappAppWidgetKit *kit = VFX_OBJ_GET_INSTANCE(VappAppWidgetKit);;


    VfxWChar temp[MAX_TEXT_SIZE];

    kit->getName(m_widgetId, temp, MAX_TEXT_SIZE);

    VFX_OBJ_CREATE(m_text, VfxTextFrame, this);
    m_text->setAnchor(VfxFPoint(0.0f, 0.5f));
    m_text->setString(VFX_WSTR_MEM(temp));
    m_text->setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);
    
    m_icon = kit->createIcon(m_widgetId, this);
    m_icon->setAnchor(VfxFPoint(0.0f, 0.5f));
    m_icon->setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);
}


void VappDesktopContentFrame::onCloseElements()
{
    VFX_OBJ_CLOSE(m_text);
    VFX_OBJ_CLOSE(m_icon);
}


void VappDesktopContentFrame::onLayoutElements()
{
    VcpListMenuCell *cell = getCell();

    if (!cell)
    {
        return;
    }

    VfxPoint pos(IMG_LEFT_GAPS, getSize().height / 2);
    VfxSize size(IMG_MAX_WIDTH, m_icon->getSize().height);

    m_icon->setPos(pos);
    m_icon->setSize(size);

    m_icon->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    pos.x = IMG_LEFT_GAPS + IMG_MAX_WIDTH + IMG_RIGHT_GAPS + TEXT_LEFT_GAPS;
    pos.y = getSize().height / 2;

    size.width = getSize().width - pos.x - TEXT_RIGHT_GAPS;
    size.height = m_text->getSize().height;

    //
    // Set-up properties.
    //
    m_text->setPos(pos);
    m_text->setSize(size);
    m_text->setColor(cell->getTextColor(VCP_LIST_MENU_TEXT_COLOR_NORMAL));
    m_text->setAutoResized(VFX_FALSE);
    m_text->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

    m_text->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
}


void VappDesktopContentFrame::onUpdateElements()
{
    // Do nothing.
}


/*****************************************************************************
 * List Menu Content Provider
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(
    "VappDesktopContentProvider",
    VappDesktopContentProvider,
    VfxObject);


VappDesktopContentProvider::VappDesktopContentProvider() :
    m_emptyMenuText(VFX_RES_ID_NULL),
    m_kitCtrl(),
    m_list(NULL),
    m_num(0),
    m_blockedList(NULL),
    m_blockedNum(0),
    m_cachedText(NULL),
    m_cachedIcon(NULL)
{
    // Do nothing.
}


VappDesktopContentProvider::~VappDesktopContentProvider()
{
    VappAppWidgetId::deleteArray(m_list, m_num);
    VappAppWidgetId::deleteArray(m_blockedList, m_blockedNum);
}


void VappDesktopContentProvider::onInit()
{
    VfxObject::onInit();

    // Do nothing.
}


void VappDesktopContentProvider::onDeinit()
{
    deleteCachedTextArray(m_cachedText, m_num);
    deleteCachedIconArray(m_cachedIcon, m_num);

    VfxObject::onDeinit();
}


VfxU32 VappDesktopContentProvider::getCount() const
{
    return m_num;
}


VfxBool VappDesktopContentProvider::getMenuEmptyText(
    VfxWString &text,
    VcpListMenuTextColorEnum &color)
{
    text.loadFromRes(m_emptyMenuText);

    return VFX_TRUE;
}


void VappDesktopContentProvider::setKitControl(
    VappAppWidgetKitControl &kitControl)
{
    m_kitCtrl = kitControl;
}


VcpListMenuCellClientBaseFrame *
VappDesktopContentProvider::getItemCustomContentFrame(
    VfxU32 index,
    VfxFrame *parentFrame)
{
    if (index >= m_num)
    {
        return NULL;
    }

    const VappAppWidgetId id = VappAppWidgetId(*getId(index));

    VappDesktopContentFrame *cell;

    VFX_OBJ_CREATE_EX(
        cell,
        VappDesktopContentFrame,
        parentFrame,
        (id));

    cell->setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);

    return cell;
}


void VappDesktopContentProvider::closeItemCustomContentFrame(
    VfxU32 index,
    VcpListMenuCellClientBaseFrame *cell)
{
    VFX_OBJ_CLOSE(cell);
}


void VappDesktopContentProvider::setEmptyText(VfxResId resId)
{
    m_emptyMenuText = resId;
}


void VappDesktopContentProvider::updateContent()
{
    VappAppWidgetId::deleteArray(m_list, m_num);
    m_list = NULL;
    m_num = 0;

    m_list = createWhiteList(m_num);

    //
    // It is possible that we do not have any shortcut in the white list. Sort
    // it only if it is feasible.
    //
    if (m_list && m_num > 1)
    {
        sortList(m_list, m_num);
    }

    //
    // Cached text and icon frames.
    //
    deleteCachedTextArray(m_cachedText, m_num);
    m_cachedText = newCachedTextArray(m_num);

    deleteCachedIconArray(m_cachedIcon, m_num);
    m_cachedIcon = newCachedIconArray(m_num);
}


void VappDesktopContentProvider::setBlockedList(
    VappAppWidgetId **list,
    VfxS32 num)
{
    VappAppWidgetId::deleteArray(m_blockedList, m_blockedNum);
    m_blockedList = NULL;
    m_blockedNum = 0;

    if (num > 0)
    {
        m_blockedList = VappAppWidgetId::newArray(num, this);
        m_blockedNum = num;

        for (VfxS32 i = 0; i < num; i++)
        {
            m_blockedList[i]->assignWith(*(list[i]));
        }
    }
}


VfxBool VappDesktopContentProvider::isBlocked(
    const VappAppWidgetId &id) const
{
    if (!m_blockedList)
    {
        return VFX_FALSE;
    }

    for (VfxS32 i = 0; i < m_blockedNum; i++)
    {
        if (m_blockedList[i]->compareWith(id))
        {
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}


const VappAppWidgetId *VappDesktopContentProvider::getId(
    VfxS32 index) const
{
    if (!m_list || index < 0 || index >= m_num)
    {
        return NULL;
    }

    return m_list[index];
}


void VappDesktopContentProvider::sortList(
    VappAppWidgetId **list,
    VfxS32 size)
{
    VFX_ASSERT(list && size > 0);

    VappDesktopSort *sort;

    VFX_OBJ_CREATE(sort, VappDesktopSort, this);

    sort->sortByName(list, size);

    VFX_OBJ_CLOSE(sort);
}


VappAppWidgetId **VappDesktopContentProvider::createWhiteList(
    VfxS32 &listNum)
{
    //
    // Get widget kit. Check if we have any widget.
    //
    VappAppWidgetKit *widgetKit = VFX_OBJ_GET_INSTANCE(VappAppWidgetKit);

    VfxS32 totalNum = widgetKit->getTotalNum(&m_kitCtrl);
    if (totalNum <= 0)
    {
        listNum = 0;
        return NULL;
    }

    //
    // Get all widget ID from the widget kit.
    //
    VappAppWidgetId **fullList = VappAppWidgetId::newArray(totalNum, this);

    widgetKit->getAllId(fullList, totalNum, &m_kitCtrl);

    //
    // Calculate the number of widgets in the white list.
    //
    listNum = 0;

    for (VfxS32 i = 0; i < totalNum; i++)
    {
        if (!isBlocked(*(fullList[i])))
        {
            ++listNum;
        }
    }

    if (listNum <= 0)
    {
        VappAppWidgetId::deleteArray(fullList, totalNum);
        return NULL;
    }

    //
    // Prepare another array of pointers.
    //
    VappAppWidgetId **whiteList;

    VFX_ALLOC_MEM(whiteList, listNum * sizeof(VappAppWidgetId *), this);

    VfxS32 idx = 0;

    for (VfxS32 i = 0; i < totalNum; i++)
    {
        if (!isBlocked(*(fullList[i])))
        {
            whiteList[idx++] = fullList[i];
            fullList[i] = NULL;
        }
    }

    VFX_ASSERT(idx == listNum);

    VappAppWidgetId::deleteArray(fullList, totalNum);

    return whiteList;
}


VfxTextFrame **VappDesktopContentProvider::newCachedTextArray(
    VfxS32 size)
{
    VfxTextFrame **array;

    VFX_ALLOC_MEM(array, size * sizeof(VfxTextFrame *), this);

    for (VfxS32 i = 0; i < size; i++)
    {
        array[i] = NULL;
    }

    return array;
}


void VappDesktopContentProvider::deleteCachedTextArray(
    VfxTextFrame **cachedText,
    VfxS32 size)
{
    if (cachedText)
    {
        for (VfxS32 i = 0; i < size; i++)
        {
            VFX_OBJ_CLOSE(cachedText[i]);
        }

        VFX_FREE_MEM(cachedText);
    }
}



VfxFrame **VappDesktopContentProvider::newCachedIconArray(VfxS32 size)
{
    VfxFrame **array;

    VFX_ALLOC_MEM(array, size * sizeof(VfxFrame *), this);

    for (VfxS32 i = 0; i < size; i++)
    {
        array[i] = NULL;
    }

    return array;
}


void VappDesktopContentProvider::deleteCachedIconArray(
    VfxFrame **cachedIcon,
    VfxS32 size)
{
    if (cachedIcon)
    {
        for (VfxS32 i = 0; i < size; i++)
        {
            VFX_OBJ_CLOSE(cachedIcon[i]);
        }

        VFX_FREE_MEM(cachedIcon);
    }
}


/*****************************************************************************
 * Widget Selector
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(
    "VappDesktopWidgetSelector",
    VappDesktopWidgetSelector,
    VappDesktopPopupMenu);


VappDesktopWidgetSelector::VappDesktopWidgetSelector():
    m_menu(NULL),
    m_contentProvider(NULL),
    m_timer2ndPassLoader(NULL)
{
    // Do nothing.
}


void VappDesktopWidgetSelector::onInit()
{
    VappDesktopPopupMenu::onInit();

    createContentProvider();

    createMenu();

    create2ndPassLoader();
}


VfxBool VappDesktopWidgetSelector::getTitleText(VfxWString &text)
{
    text.loadFromRes(STR_ID_VAPP_DESKTOP_SELECT_WIDGET);

    return VFX_TRUE;
}


void VappDesktopWidgetSelector::createContentProvider()
{
    VappAppWidgetKitControl kitControl(VFX_TRUE);
    kitControl.forbit(VAPP_APP_WIDGET_SRC_SHORTCUT);

    VFX_OBJ_CREATE(m_contentProvider, VappDesktopContentProvider, this);
    m_contentProvider->setEmptyText(STR_ID_VAPP_DESKTOP_NO_WIDGET);
    m_contentProvider->setKitControl(kitControl);

    //
    // We don't allow users to select home screen or main menu as the shortcut.
    // In addition, for shortcuts that are already present on the desktop, we do
    // not allow the users to select them again.
    //
    VappAppWidgetArchiveIterator *iter;
    VfxS32 entryCount = 0;

    VFX_OBJ_CREATE(iter, VappAppWidgetArchiveIterator, this);

    if (iter->readFirst(entryCount) && entryCount > 0)
    {
        VappAppWidgetId **widgetId = VappAppWidgetId::newArray(entryCount, this);
        VfxS32 totalNum = 0;
        VfxPoint pos;

        for (VfxBool isSuccess = iter->readNext(*widgetId[totalNum], pos);
             isSuccess == VFX_TRUE;
             isSuccess = iter->readNext(*widgetId[totalNum], pos))
        {
            if (widgetId[totalNum]->getSource() != VAPP_APP_WIDGET_SRC_SHORTCUT)
            {
                VFX_ASSERT(totalNum < entryCount);
                totalNum++;
            }
        }

        m_contentProvider->setBlockedList(widgetId, totalNum);

        VappAppWidgetId::deleteArray(widgetId, entryCount);
    }

    VFX_OBJ_CLOSE(iter);
}


void VappDesktopWidgetSelector::createMenu()
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
    m_menu->m_signalItemTapped.connect(this, &VappDesktopWidgetSelector::onItemTapped);

    m_menu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
}


void VappDesktopWidgetSelector::create2ndPassLoader()
{
    //
    // Create timer to handle the 2nd pass of APP's activation. The timer will
    // expire immediately, i.e., 1 msec, because we only want to accelerate the
    // rendering time of the first frame used in SSE.
    //
    VFX_OBJ_CREATE(m_timer2ndPassLoader, VfxTimer, this);
    m_timer2ndPassLoader->setStartDelay(1);
    m_timer2ndPassLoader->m_signalTick.connect(this, &VappDesktopWidgetSelector::on2ndPassLoader);

    //
    // Start timer.
    //
    m_timer2ndPassLoader->start();
}


void VappDesktopWidgetSelector::on2ndPassLoader(VfxTimer *timer)
{
    m_menu->setCacheLen(CACHE_LEN);
    m_menu->updateAllItems();
}


void VappDesktopWidgetSelector::onItemTapped(VcpListMenu *menu, VfxU32 index)
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

static VappDesktopWidgetSelector *s_vapp_desktop_widget_selector = NULL;


static void vapp_desktop_widget_selector_create(
    VappDesktopPopupMenu::CallbackFunc callback)
{
    VFX_ASSERT(s_vapp_desktop_widget_selector == NULL);

    set_small_screen();

    VfxAppCatScr::initalize();

    VFX_OBJ_CREATE(
        s_vapp_desktop_widget_selector,
        VappDesktopWidgetSelector,
        VfxAppCatScr::getContext());

    s_vapp_desktop_widget_selector->registerCallback(callback);
}


static void vapp_desktop_widget_selector_release()
{
    VFX_OBJ_CLOSE(s_vapp_desktop_widget_selector);

    VfxAppCatScr::deinitalize();

    reset_small_screen();
}


static void vapp_desktop_widget_selector_enter(mmi_scrn_essential_struct *param)
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

    vapp_desktop_widget_selector_create(callback);

    ExitCategoryFunction = vapp_desktop_widget_selector_release;
}


void vapp_desktop_launch_widget_selector(
    VappDesktopPopupMenu::CallbackFunc callback)
{
    mmi_frm_scrn_first_enter(
        mmi_idle_get_group_id(),
        SCR_ID_VAPP_DESKTOP_WIDGET_SELECTOR,
        (FuncPtr)vapp_desktop_widget_selector_enter,
        (void *)callback);
}

#endif /* defined(__MMI_VUI_LAUNCHER__) */

