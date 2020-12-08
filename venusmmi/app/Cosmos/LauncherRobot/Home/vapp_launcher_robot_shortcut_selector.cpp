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
 *  vapp_launcher_robot_shortcut_selector.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_navi_title_bar.h"
#include "vapp_widget_kit.h"
#include "vapp_widget_primitive.h"
#include "vapp_launcher_robot_primitive.h"
#include "vapp_launcher_robot_shortcut_selector.h"
#include "mmi_rp_vapp_launcher_robot_def.h"
#include "mmi_rp_app_cosmos_global_def.h"

//
// Include C headers without extern "C" internally.
//
extern "C"
{
#include "AppMgrSrvGprot.h"
}


/*****************************************************************************
 * List Menu Custom Content Frame
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(
    "VappLauncherRobotShortcutContentFrame",
    VappLauncherRobotShortcutContentFrame,
    VcpListMenuCellClientBaseFrame);

const VfxFloat VappLauncherRobotShortcutContentFrame::s_textAniStartOpacity = 0.6f;


VappLauncherRobotShortcutContentFrame::VappLauncherRobotShortcutContentFrame() :
    m_index(0),
    m_contentProvider(NULL),
    m_text(NULL),
    m_icon(NULL),
    m_isAnimationOn(VFX_FALSE),
    m_isAnimated(VFX_FALSE)
{
    m_style = VCP_LIST_MENU_CELL_STYLE_CUSTOM;
}


VappLauncherRobotShortcutContentFrame::VappLauncherRobotShortcutContentFrame(
    VfxS32 index,
    VappLauncherRobotShortcutContentProvider *contentProvider) :
    m_index(index),
    m_contentProvider(contentProvider),
    m_text(NULL),
    m_icon(NULL),
    m_isAnimationOn(VFX_FALSE),
    m_isAnimated(VFX_FALSE)
{
    m_style = VCP_LIST_MENU_CELL_STYLE_CUSTOM;
}


void VappLauncherRobotShortcutContentFrame::setIndex(VfxS32 index)
{
    VFX_ASSERT(index >= 0);

    m_index = index;
}


void VappLauncherRobotShortcutContentFrame::bind(
    VappLauncherRobotShortcutContentProvider *contentProvider)
{
    m_contentProvider = contentProvider;
}


void VappLauncherRobotShortcutContentFrame::setAnimation(VfxBool isOn)
{
    m_isAnimationOn = isOn;
}


void VappLauncherRobotShortcutContentFrame::onCreateElements()
{
    VFX_OBJ_CREATE(m_text, VfxTextFrame, this);
    m_text->setAnchor(VfxFPoint(0.0f, 0.5f));
    m_text->setAutoAnimate(VFX_TRUE);
}


void VappLauncherRobotShortcutContentFrame::onCloseElements()
{
    VFX_OBJ_CLOSE(m_text);
    VFX_OBJ_CLOSE(m_icon);
}


void VappLauncherRobotShortcutContentFrame::onLayoutElements()
{
    VcpListMenuCell *cell = getCell();
    
    if (!cell)
    {
        return;
    }

    if (m_icon)
    {
        VfxPoint pos(m_icon->getSize().width/2, m_icon->getSize().height/2);
        m_icon->setPos(pos);
        m_icon->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    if (m_text)
    {
        VfxPoint pos;
        pos.x = m_icon->getSize().width + TEXT_LEFT_GAPS;
        pos.y = m_icon->getSize().height / 2;

        VfxSize size;
        size.width = getSize().width - pos.x - TEXT_RIGHT_GAPS;
        size.height = m_text->getSize().height;

        //
        // Start an opening animation for the text.
        //
        if (!m_isAnimationOn || m_isAnimated)
        {
            m_text->setPos(pos);
        }
        else
        {
            m_isAnimated = VFX_TRUE;

            m_text->setPos(VfxPoint(pos.x, pos.y + TEXT_ANI_OFFSET_Y));
            m_text->setOpacity(s_textAniStartOpacity);

            VfxAutoAnimate::initAnimateBegin();

            m_text->setOpacity(1.0f);
            m_text->setPos(pos);

            VfxAutoAnimate::initAnimateEnd();
        }

        //
        // Set-up remained properties.
        //
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
}


void VappLauncherRobotShortcutContentFrame::onUpdateElements()
{
    const VappWidgetId *id = getPackage();

    VappWidgetKit *kit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);

    //
    // Icon
    //
    VFX_OBJ_CLOSE(m_icon);

    m_icon = kit->createIcon(*id, this);
    m_icon->setAnchor(VfxFPoint(0.5f, 0.5f));

    //
    // Text
    //
    VfxWChar temp[MAX_TEXT_SIZE];

    kit->getName(*id, temp, MAX_TEXT_SIZE);

    m_text->setString((temp));
}


const VappWidgetId *VappLauncherRobotShortcutContentFrame::getPackage() const
{
    if (m_contentProvider.isValid())
    {
        const VappWidgetId *id = m_contentProvider->getId(m_index);

        VFX_ASSERT(id->getSource() == VAPP_WIDGET_SRC_SHORTCUT &&
                   id->getTypeKind() == VappWidgetId::TYPE_KIND_INTEGER);

        return id;
    }

    return NULL;
}


/*****************************************************************************
 * List Menu Content Provider
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(
    "VappLauncherRobotShortcutContentProvider",
    VappLauncherRobotShortcutContentProvider,
    VfxObject);


VappLauncherRobotShortcutContentProvider::VappLauncherRobotShortcutContentProvider() :
    m_list(NULL),
    m_num(0),
    m_blockedList(NULL),
    m_blockedNum(0),
    m_isAnimationOn(VFX_TRUE)
{
    // Do nothing.
}


VappLauncherRobotShortcutContentProvider::~VappLauncherRobotShortcutContentProvider()
{
    VappWidgetId::deleteArray(m_list, m_num);
    VappWidgetId::deleteArray(m_blockedList, m_blockedNum);
}


VfxU32 VappLauncherRobotShortcutContentProvider::getCount() const
{
    return m_num;
}


VfxBool VappLauncherRobotShortcutContentProvider::getMenuEmptyText(
    VfxWString &text,
    VcpListMenuTextColorEnum &color)
{
    text.loadFromRes(STR_ID_VAPP_LAUNCHER_ROBOT_NO_SHORTCUT);

    return VFX_TRUE;
}


VcpListMenuCellClientBaseFrame *
VappLauncherRobotShortcutContentProvider::getItemCustomContentFrame(
    VfxU32 index,
    VfxFrame *parentFrame)
{
    VappLauncherRobotShortcutContentFrame *cell;

    VFX_OBJ_CREATE_EX(
        cell,
        VappLauncherRobotShortcutContentFrame,
        parentFrame,
        (index, this));

    cell->setAnimation(m_isAnimationOn);

    return cell;
}


void VappLauncherRobotShortcutContentProvider::closeItemCustomContentFrame(
    VfxU32 index,
    VcpListMenuCellClientBaseFrame *cell)
{
    VFX_OBJ_CLOSE(cell);
}


void VappLauncherRobotShortcutContentProvider::updateContent()
{
    VappWidgetId::deleteArray(m_list, m_num);
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
}


void VappLauncherRobotShortcutContentProvider::setBlockedList(
    VappWidgetId **list,
    VfxS32 num)
{
    VappWidgetId::deleteArray(m_blockedList, m_blockedNum);
    m_blockedList = NULL;
    m_blockedNum = 0;

    if (num > 0)
    {
        m_blockedList = VappWidgetId::newArray(num, this);
        m_blockedNum = num;

        for (VfxS32 i = 0; i < num; i++)
        {
            m_blockedList[i]->assignWith(*(list[i]));
        }
    }
}


VfxBool VappLauncherRobotShortcutContentProvider::isBlocked(const VappWidgetId &id) const
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


void VappLauncherRobotShortcutContentProvider::setAnimation(VfxBool isOn)
{
    m_isAnimationOn = isOn;
}


const VappWidgetId *VappLauncherRobotShortcutContentProvider::getId(VfxS32 index) const
{
    if (!m_list || index < 0 || index >= m_num)
    {
        return NULL;
    }

    return m_list[index];
}


void VappLauncherRobotShortcutContentProvider::sortList(VappWidgetId **list, VfxS32 size)
{
    VFX_ASSERT(list && size > 0);

    VappLauncherRobotSort *sort;

    VFX_OBJ_CREATE(sort, VappLauncherRobotSort, this);

    sort->sortByName(list, size);

    VFX_OBJ_CLOSE(sort);
}


VappWidgetId **VappLauncherRobotShortcutContentProvider::createWhiteList(VfxS32 &listNum)
{
    //
    // Prepare kit control to permit only the widgets of the shortcut type.
    //
    VappWidgetKitControl kitControl(VFX_FALSE);

    kitControl.permit(VAPP_WIDGET_SRC_SHORTCUT);

    //
    // Get widget kit. Check if we have any widget.
    //
    VappWidgetKit *widgetKit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);

    VfxS32 totalNum = widgetKit->getTotalNum(&kitControl);
    if (totalNum <= 0)
    {
        listNum = 0;
        return NULL;
    }

    //
    // Get all widget ID from the widget kit.
    //
#if defined(__MMI_VUI_HOME_SCREEN_SWITCH_EFFECT__)
    VappWidgetId **fullList = VappWidgetId::newArray(totalNum+1, this);

    widgetKit->getAllId(fullList, totalNum, &kitControl);

    // add barrel setting shortcut directly on Cosmos launcher
    fullList[totalNum]->assignWith(
                            VAPP_WIDGET_SRC_SHORTCUT,
                            srv_appmgr_get_id_by_app_package_name("native.mtk.launcher_robot_page_transition_setting"));
    totalNum++;
#else
    VappWidgetId **fullList = VappWidgetId::newArray(totalNum, this);

    widgetKit->getAllId(fullList, totalNum, &kitControl);
#endif

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
        VappWidgetId::deleteArray(fullList, totalNum);
        return NULL;
    }

    //
    // Prepare another array of pointers.
    //
    VappWidgetId **whiteList;

    VFX_ALLOC_MEM(whiteList, listNum * sizeof(VappWidgetId *), this);

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

    VappWidgetId::deleteArray(fullList, totalNum);

    return whiteList;
}


/*****************************************************************************
 * Shortcut Selector Page
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(
    "VappLauncherRobotShortcutSelector",
    VappLauncherRobotShortcutSelector,
    VfxPage);


VappLauncherRobotShortcutSelector::VappLauncherRobotShortcutSelector() :
    m_menu(NULL),
    m_contentProvider(NULL)
{
    // Do nothing.
}


VappLauncherRobotShortcutSelector::~VappLauncherRobotShortcutSelector()
{
    // Do nothing.
}


void VappLauncherRobotShortcutSelector::onInit()
{
    VfxPage::onInit();

    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    createTitleBar();

    VFX_OBJ_CREATE(m_contentProvider, VappLauncherRobotShortcutContentProvider, this);
}


void VappLauncherRobotShortcutSelector::onDeinit()
{
    VfxPage::onDeinit();
}


VfxBool VappLauncherRobotShortcutSelector::onKeyInput(VfxKeyEvent &event)
{
    if (m_contentProvider)
    {
        m_contentProvider->setAnimation(VFX_FALSE);
    }

    return VfxPage::onKeyInput(event);
}


VfxBool VappLauncherRobotShortcutSelector::onPreviewPenInput(VfxPenEvent &event)
{
    if (m_contentProvider)
    {
        m_contentProvider->setAnimation(VFX_FALSE);
    }

    return VfxPage::onPreviewPenInput(event);
}


void VappLauncherRobotShortcutSelector::show()
{
    updateMenu();

    create2ndPassLoader();
}


void VappLauncherRobotShortcutSelector::setBlockedList(VappWidgetId **list, VfxS32 num)
{
    VFX_ASSERT(m_contentProvider);
    m_contentProvider->setBlockedList(list, num);
}


void VappLauncherRobotShortcutSelector::createTitleBar()
{
    VcpTitleBar *bar;

    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle((STR_ID_VAPP_LAUNCHER_ROBOT_SELECT_SHORTCUT));

    setTopBar(bar);
}


void VappLauncherRobotShortcutSelector::updateMenu()
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
    m_menu->setSize(getSize());
    m_menu->setContentProvider(m_contentProvider);
    m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_CUSTOM);
    m_menu->setItemHeight(ITEM_HEIGHT);
    m_menu->m_signalItemTapped.connect(this, &VappLauncherRobotShortcutSelector::onItemTapped);

    m_menu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
}


void VappLauncherRobotShortcutSelector::create2ndPassLoader()
{
    //
    // Create timer to handle the 2nd pass of APP's activation. The timer will
    // expire immediately, i.e., 1 msec, because we only want to accelerate the
    // rendering time of the first frame used in SSE.
    //
    VFX_OBJ_CREATE(m_timer2ndPassLoader, VfxTimer, this);
    m_timer2ndPassLoader->setStartDelay(1);
    m_timer2ndPassLoader->m_signalTick.connect(this, &VappLauncherRobotShortcutSelector::on2ndPassLoader);

    //
    // Start timer.
    //
    m_timer2ndPassLoader->start();
}


void VappLauncherRobotShortcutSelector::on2ndPassLoader(VfxTimer *timer)
{
    m_menu->setCacheLen(CACHE_LEN);
    m_menu->updateAllItems();
}


void VappLauncherRobotShortcutSelector::onItemTapped(VcpListMenu *menu, VfxU32 index)
{
    VFX_ASSERT(m_contentProvider);

    const VappWidgetId *id = m_contentProvider->getId(index);

    m_signalSelected.emit(this, *id);
}

