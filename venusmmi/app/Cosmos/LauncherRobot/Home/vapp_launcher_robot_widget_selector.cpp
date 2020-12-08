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
/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_launcher_robot_widget_selector.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_widget_factory.h"
#include "vcp_navi_title_bar.h"
#include "vapp_nmgr_gprot.h"
#include "GlobalResDef.h"
#include "vapp_launcher_robot_primitive.h"
#include "vapp_launcher_robot_widget_selector.h"
#include "mmi_rp_vapp_launcher_robot_def.h"
#include "mmi_rp_app_cosmos_global_def.h"

#if defined(__GADGET_SUPPORT__)
#include "WgtMgrSrvGprot.h"
#include "WgtMgrSrvIprot.h"
#endif /* defined(__GADGET_SUPPORT__) */

//
// Include C headers without extern "C" internally.
//
extern "C"
{
#include "USBSrvGprot.h"
}


/*****************************************************************************
 * Page Grid Cell
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherRobotWidgetGridCell", VappLauncherRobotWidgetGridCell, VcpPageGridCell);

const VfxFloat VappLauncherRobotWidgetGridCell::s_textAniStartOpacity = 0.6f;


VappLauncherRobotWidgetGridCell::VappLauncherRobotWidgetGridCell() :
    m_isAnimationOn(VFX_FALSE)
{
    // Do nothing.
}


void VappLauncherRobotWidgetGridCell::onShowCell()
{
    VappWidgetKit *widgetKit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);

    //
    // Create Icon.
    //
    VfxFrame *iconFrame = widgetKit->createIcon(m_id, this);
    iconFrame->setPos(ICON_OFFSET_X, ICON_OFFSET_Y);
    iconFrame->setSize(VfxSize(ICON_WIDTH, ICON_HEIGHT));
    iconFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    //
    // Get Widget Name.
    //
    VfxWChar nameBuf[MAX_NAME_SIZE];
    widgetKit->getName(m_id, nameBuf, MAX_NAME_LEN);

    //
    // Create Text.
    //
    VfxTextFrame *textFrame;

    VFX_OBJ_CREATE(textFrame, VfxTextFrame, this);
    textFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TITLE_FONT_SIZE)));
    textFrame->setFullLineHeightMode(VFX_TRUE);
    textFrame->setSize(TITLE_WIDTH, TITLE_HEIGHT);
    textFrame->setString((nameBuf));
    textFrame->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    textFrame->setAutoResized(VFX_FALSE);
    textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

    if (!m_isAnimationOn)
    {
        textFrame->setPos(TITLE_OFFSET_X, TITLE_OFFSET_Y);
    }
    else
    {
        textFrame->setPos(VfxPoint(TITLE_OFFSET_X, TITLE_ANI_OFFSET_Y));
        textFrame->setOpacity(s_textAniStartOpacity);
        textFrame->setAutoAnimate(VFX_TRUE);

        VfxAutoAnimate::initAnimateBegin();

        textFrame->setOpacity(1.0f);
        textFrame->setPos(VfxPoint(TITLE_OFFSET_X, TITLE_OFFSET_Y));

        VfxAutoAnimate::initAnimateEnd();
    }
}


void VappLauncherRobotWidgetGridCell::setWidgetId(const VappWidgetId &id)
{
    m_id = id;
}


void VappLauncherRobotWidgetGridCell::setAnimation(VfxBool isOn)
{
    m_isAnimationOn = isOn;
}


/*****************************************************************************
 * Widget Selector
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherRobotWidgetSelector", VappLauncherRobotWidgetSelector, VfxPage);


VappLauncherRobotWidgetSelector::VappLauncherRobotWidgetSelector():
    m_pageGrid(NULL),
    m_widgetIdList(NULL),
    m_widgetNum(0),
    m_blockedList(NULL),
    m_blockedNum(0),
    m_selectedWidget()
{
    // Do nothing.
}


VappLauncherRobotWidgetSelector::~VappLauncherRobotWidgetSelector()
{
    VappWidgetId::deleteArray(m_widgetIdList, m_widgetNum);
    VappWidgetId::deleteArray(m_blockedList, m_blockedNum);
}


void VappLauncherRobotWidgetSelector::onInit()
{
    VfxPage::onInit();

    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    createTitleBar();
}


void VappLauncherRobotWidgetSelector::onDeinit()
{
    // Do nothing.

    VfxPage::onDeinit();
}


void VappLauncherRobotWidgetSelector::show()
{
    createSeparateLine();

    createPageGrid();

    updatePageGrid();
}


void VappLauncherRobotWidgetSelector::setBlockedList(
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


void VappLauncherRobotWidgetSelector::createTitleBar()
{
    VcpTitleBar *bar;

    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle((STR_ID_VAPP_LAUNCHER_ROBOT_SELECT_WIDGET));

    setTopBar(bar);
}


void VappLauncherRobotWidgetSelector::createSeparateLine()
{
    vrt_size_struct screenSize;
    vrt_sys_get_main_screen_info(&screenSize, NULL);

    for (VfxS32 i = 0; i < ROW_NUM - 1; ++i)
    {
        VfxImageFrame *line;

        VFX_OBJ_CREATE(line, VfxImageFrame, this);
        line->setResId(IMG_COSMOS_SEPARATOR_LINE);
        line->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        line->setPos(0, CELL_START_Y + CELL_OFFSET_Y * (i + 1));
        line->setSize(screenSize.width, line->getSize().height);
    }
}


void VappLauncherRobotWidgetSelector::createPageGrid()
{
    VFX_ASSERT(m_pageGrid == NULL);

    vrt_size_struct screenSize;
    vrt_sys_get_main_screen_info(&screenSize, NULL);

    //
    // Create page grid.
    //
    VFX_OBJ_CREATE(m_pageGrid, VcpPageGrid, this);
    m_pageGrid->setSize(VfxSize(screenSize.width, screenSize.height));
    m_pageGrid->m_itemClicked.connect(this, &VappLauncherRobotWidgetSelector::onItemClicked);

    //
    // Layout the page grid.
    //
    VcpPageGridLayout layout;

    layout.rowCount     = ROW_NUM;
    layout.columnCount  = COLUMN_NUM;
    layout.cellStartX   = CELL_START_X;
    layout.cellStartY   = CELL_START_Y;
    layout.cellOffsetX  = CELL_OFFSET_X;
    layout.cellOffsetY  = CELL_OFFSET_Y;

    m_pageGrid->setLayout(layout);
}


void VappLauncherRobotWidgetSelector::updatePageGrid()
{
    //
    // Update the sorted white list.
    //
    VappWidgetId::deleteArray(m_widgetIdList, m_widgetNum);
    m_widgetIdList = NULL;
    m_widgetNum = 0;

    m_widgetIdList = createWhiteList(m_widgetNum);

    if (!m_widgetIdList || !m_widgetNum)
    {
        return;
    }

    sortList(m_widgetIdList, m_widgetNum);

    //
    // Reset and update the page grid.
    //
    VFX_ASSERT(m_pageGrid);

    m_pageGrid->resetCells();

    for (VfxS32 i = 0; i < m_widgetNum; i++)
    {
        VappLauncherRobotWidgetGridCell *cell;

        VFX_OBJ_CREATE(cell, VappLauncherRobotWidgetGridCell, this);
        cell->setWidgetId(*(m_widgetIdList[i]));
        cell->setAnimation(VFX_TRUE);

        m_pageGrid->appendCell(cell);
    }
}


void VappLauncherRobotWidgetSelector::onPostUpdate()
{
    updatePageGrid();
}


void VappLauncherRobotWidgetSelector::onItemClicked(VfxS32 itemIndex)
{
    m_selectedWidget = *m_widgetIdList[itemIndex];

#if defined(__GADGET_SUPPORT__)
    if (m_selectedWidget.getSource() == VAPP_WIDGET_SRC_GADGET)
    {
        if (!sanityCheckForGadget())
        {
            return;
        }
    }
#endif /* defined(__GADGET_SUPPORT__) */

    m_signalSelected.postEmit(this, m_selectedWidget);
}


VfxBool VappLauncherRobotWidgetSelector::isBlocked(const VappWidgetId &id) const
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


VappWidgetId **VappLauncherRobotWidgetSelector::createWhiteList(VfxS32 &whiteWidgetNum)
{
    //
    // Prepare kit control to skip the widgets which belongs to shortcut type.
    //
    VappWidgetKitControl kitControl;

    kitControl.forbit(VAPP_WIDGET_SRC_SHORTCUT);

    //
    // Get widget kit. Check if we have any widgets.
    //
    VappWidgetKit *widgetKit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);

    VfxS32 totalNum = widgetKit->getTotalNum(&kitControl);
    if (totalNum <= 0)
    {
        whiteWidgetNum = 0;
        return NULL;
    }

    //
    // Get all widget ID from the widget kit.
    //
    VappWidgetId **fullList = VappWidgetId::newArray(totalNum, this);

    widgetKit->getAllId(fullList, totalNum, &kitControl);

    //
    // Calculate the number of widgets in the white list.
    //
    whiteWidgetNum = 0;

    for (VfxS32 i = 0; i < totalNum; i++)
    {
        if (!isBlocked(*(fullList[i])))
        {
            ++whiteWidgetNum;
        }
    }

    if (whiteWidgetNum <= 0)
    {
        VappWidgetId::deleteArray(fullList, totalNum);
        return NULL;
    }

    //
    // Prepare another array of pointers.
    //
    VappWidgetId **whiteList;

    VFX_ALLOC_MEM(whiteList, whiteWidgetNum * sizeof(VappWidgetId *), this);

    VfxS32 idx = 0;

    for (VfxS32 i = 0; i < totalNum; i++)
    {
        if (!isBlocked(*(fullList[i])))
        {
            whiteList[idx++] = fullList[i];
            fullList[i] = NULL;
        }
    }

    VFX_ASSERT(idx == whiteWidgetNum);

    VappWidgetId::deleteArray(fullList, totalNum);

    return whiteList;
}


void VappLauncherRobotWidgetSelector::sortList(VappWidgetId **list, VfxS32 size)
{
    VFX_ASSERT(list && size > 0);

    VappLauncherRobotSort *sort;

    VFX_OBJ_CREATE(sort, VappLauncherRobotSort, this);

    sort->sortByName(list, size);

    VFX_OBJ_CLOSE(sort);
}


#if defined(__GADGET_SUPPORT__)
VfxBool VappLauncherRobotWidgetSelector::sanityCheckForGadget()
{
    VfxS32 type;
    srv_wgtmgr_wgt_drive_enum drive;

    type = m_selectedWidget.getIntType();
    drive = srv_wgtmgr_get_downloaded_wgt_installed_drive(type);

#if defined(__USB_IN_NORMAL_MODE__)
    //
    // If widget isn't installed in the system drive and the mobile is in the
    // mass storage mode, we cannot put the widget on the home screen.
    //
    if(srv_usb_is_in_mass_storage_mode() && drive != SRV_WGTMGR_DRIVE_SYSTEM)
    {
        //
        // For MAUI_02993158, use global popup such that home screen could
        // become inactive. Then, if gadget is deleted, it will be detected
        // after home screen becomes active.
        //
        // TODO: Use VcpConfirmPopup after APP. manager supports events to let
        //       us know an APP is removed.
        //
        vapp_nmgr_global_popup_show_confirm_one_button_id(
            MMI_SCENARIO_ID_DEFAULT,
            VCP_POPUP_TYPE_FAILURE,
            STR_ID_VAPP_LAUNCHER_ROBOT_NOT_AVAILABLE_IN_USB_MODE,
            STR_GLOBAL_OK,
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            NULL,
            NULL);

        return VFX_FALSE;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */

    //
    // If the widget's state is not ok, e.g., not found, we further check the
    // following conditions:
    //
    //  1) It isn't installed on the memory card. Then, we remove it.
    //  2) Otherwise, we ask the user if they want to keep it.
    //
    if (srv_wgtmgr_check_downloaded_wgt(type) != SRV_WGTMGR_RET_OK)
    {
        if (drive != SRV_WGTMGR_DRIVE_MEMORY_CARD)
        {
            //
            // For MAUI_02993158, use global popup such that home screen could
            // become inactive. Then, if gadget is deleted, it will be detected
            // after home screen becomes active.
            //
            // TODO: Use VcpConfirmPopup after APP. manager supports events to
            //       let us know an APP is removed.
            //
            vapp_nmgr_global_popup_show_confirm_one_button_id(
                MMI_SCENARIO_ID_DEFAULT,
                VCP_POPUP_TYPE_FAILURE,
                STR_ID_VAPP_LAUNCHER_ROBOT_FILE_NOT_EXISTS_AND_WILL_BE_REMOVED,
                STR_GLOBAL_OK,
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                onPopupCorruptedClicked,
                getObjHandle());
        }
        else
        {
            //
            // For MAUI_02993158, use global popup such that home screen could
            // become inactive. Then, if gadget is deleted, it will be detected
            // after home screen becomes active.
            //
            // TODO: Use VcpConfirmPopup after APP. manager supports events to
            //       let us know an APP is removed.
            //
            vapp_nmgr_global_popup_show_confirm_two_button_id(
                MMI_SCENARIO_ID_DEFAULT,
                VCP_POPUP_TYPE_QUESTION,
                STR_ID_VAPP_LAUNCHER_ROBOT_FILE_NOT_EXISTS,
                STR_GLOBAL_DELETE,
                STR_ID_VAPP_LAUNCHER_ROBOT_KEEP_IT,
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                onPopupMemoryCardPlugOutClicked,
                getObjHandle());
        }

        return VFX_FALSE;
    }

    return VFX_TRUE;
}


void VappLauncherRobotWidgetSelector::onPopupCorruptedClicked(VfxId id, void *userData)
{
    VappLauncherRobotWidgetSelector *selector;

    selector = (VappLauncherRobotWidgetSelector *)handleToObject((VfxObjHandle)userData);

    if (selector)
    {
        srv_wgtmgr_delete_wgt(
            selector->m_selectedWidget.getIntType(),
            NULL,
            NULL);

        vfxPostInvoke0(selector, &VappLauncherRobotWidgetSelector::onPostUpdate);
    }
}


void VappLauncherRobotWidgetSelector::onPopupMemoryCardPlugOutClicked(
    VfxId id,
    void *userData)
{
    VappLauncherRobotWidgetSelector *selector;

    selector = (VappLauncherRobotWidgetSelector *)handleToObject((VfxObjHandle)userData);

    if (selector && id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        srv_wgtmgr_delete_wgt(
            selector->m_selectedWidget.getIntType(),
            NULL,
            NULL);

        vfxPostInvoke0(selector, &VappLauncherRobotWidgetSelector::onPostUpdate);
    }
}
#endif /* defined(__GADGET_SUPPORT__) */

