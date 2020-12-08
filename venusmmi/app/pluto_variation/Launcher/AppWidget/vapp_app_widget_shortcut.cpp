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
 *  vapp_app_widget_shortcut.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the shortcut widget.
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

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMIDataType.h"
#include "vapp_app_widget.h"
#include "vapp_app_widget_kit.h"
#include "vapp_app_widget_shortcut.h"
#include "vapp_drawer_builder.h"

//
// Include C headers without extern "C" internally.
//
extern "C"
{
#include "AppMgrSrvGprot.h"
}


/*****************************************************************************
 * Shortcut Widget
 *****************************************************************************/

VAPP_APP_WIDGET_IMPLEMENT_CLASS(VappAppWidgetShortcut, VappAppWidget);


VappAppWidgetShortcut::VappAppWidgetShortcut() :
    m_package(NULL),
    m_cell(NULL)
{
    // Do nothing.
}


VappAppWidgetShortcut::~VappAppWidgetShortcut()
{
    clear();
}


VfxBool VappAppWidgetShortcut::onPenInput(VfxPenEvent &event)
{
    if (isDragged())
    {
        return VappAppWidget::onPenInput(event);
    }

    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            setHighlighted(VFX_TRUE);
            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
            if (containPoint(event.getRelPos(this)))
            {
                setHighlighted(VFX_TRUE);
            }
            else
            {
                setHighlighted(VFX_FALSE);
            }
            break;

        case VFX_PEN_EVENT_TYPE_UP:
        case VFX_PEN_EVENT_TYPE_ABORT:
            setHighlighted(VFX_FALSE);
            break;

        default:
            break;
    }

    return VappAppWidget::onPenInput(event);
}


void VappAppWidgetShortcut::onDrag(VfxPenEvent &event)
{
    setHighlighted(VFX_FALSE);
}


void VappAppWidgetShortcut::setPackage(const VfxChar *package)
{
    VFX_ASSERT(package);

    clear();

    VfxS32 len = strlen(package);

    VFX_ALLOC_MEM(m_package, sizeof(VfxChar) * (len + 1), this);

    strncpy(m_package, package, len);
    m_package[len] = '\0';
}


const VfxChar *VappAppWidgetShortcut::getPackage()
{
    return m_package;
}


VfxBool VappAppWidgetShortcut::isPreInstalled() const
{
    VfxS32 num = srv_appmgr_get_app_package_num(
                    SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE);
    if (num == 0)
    {
        return VFX_FALSE;
    }

    //
    // Get all pre-installed APP package name.
    //
    mmi_app_package_name_struct *package;

    VFX_SYS_ALLOC_MEM(package, num * sizeof(mmi_app_package_name_struct));

    mmi_ret ret = srv_appmgr_get_app_package_list(
                    SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE,
                    package,
                    num);
    VFX_ASSERT(ret != MMI_RET_ERR);

    //
    // Check if this APP belongs to pre-installed APP.
    //
    VfxBool isFound = VFX_FALSE;

    for (VfxS32 i = 0; i < num; i++)
    {
        if (strcmp(m_package, package[i]) == 0)
        {
            isFound = VFX_TRUE;
            break;
        }
    }

    VFX_SYS_FREE_MEM(package);

    return isFound;
}


VappAppWidgetId VappAppWidgetShortcut::getId() const
{
    VFX_ASSERT(m_package);

    return VappAppWidgetId(VAPP_APP_WIDGET_SRC_SHORTCUT, m_package);
}


VfxS32 VappAppWidgetShortcut::getName(VfxWChar *string, VfxS32 size) const
{
    WCHAR temp[MMI_APP_NAME_MAX_LEN];

    VFX_ASSERT(m_package);

    mmi_ret ret = srv_appmgr_get_app_package_name(m_package, temp);

    if (ret == MMI_RET_OK)
    {
        mmi_wcsncpy(string, temp, size - 1); // 1: null terminated
        return mmi_wcslen(string);;
    }

    return 0;
}


VfxSize VappAppWidgetShortcut::getMaxSize() const
{
    return getRoomSize(HORIZ_TILE_NUM, VERTI_TILE_NUM);
}


VfxFrame *VappAppWidgetShortcut::createIcon(VfxObject *parentObj)
{
    VappDrawerCell *cell;

    // TODO: 'createDrawerCell' should change its first parameter type to
    // 'VfxChar *'.
    VfxChar temp[MMI_APP_NAME_MAX_LEN];
    strncpy(temp, m_package, MMI_APP_NAME_MAX_LEN - 1);

    cell = createDrawerCell(temp, parentObj, isPreInstalled());
    cell->setTextFrameHidden(VFX_TRUE);
    cell->setBadgeHidden(VFX_TRUE);

    // it will return real cell's size, do not to tune it size again
    cell->onCellDisplay();

    return cell;
}


void VappAppWidgetShortcut::onCreateView()
{
    setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);

    VFX_ASSERT(!m_cell);

    m_cell = createCell();

    //
    // Sync the edit mode state.
    //
    if (isInEditMode())
    {
        m_cell->setBadgeHidden(VFX_TRUE);
    }

    //
    // Sync the size to be the same as the cell.
    //
    setSize(m_cell->getSize());

    //
    // Put the cell on the center of the shortcut widget.
    //
    m_cell->setAnchor(0.5f, 0.5f);
    m_cell->setPos(getSize().width / 2, getSize().height / 2);

    mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE,  &VappAppWidgetShortcut::eventHandler, (void *)getObjHandle());
}


void VappAppWidgetShortcut::onReleaseView()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE, &VappAppWidgetShortcut::eventHandler, (void *)getObjHandle());

    VFX_OBJ_CLOSE(m_cell);
}


mmi_ret VappAppWidgetShortcut::eventHandler(mmi_event_struct *event)
{
    VappAppWidgetShortcut *shortcut = (VappAppWidgetShortcut *)VfxObject::handleToObject((VfxObjHandle)event->user_data);

    srv_appmgr_update_event_struct *evt = (srv_appmgr_update_event_struct *)event;

    switch (event->evt_id)
    {
        case EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE:
            shortcut->uninstallUpdate(evt->app_name);
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}



void VappAppWidgetShortcut::uninstallUpdate(const mmi_app_package_char *package)
{
    //
    // If this is not a shortcut of native APP, it could become invalid.
    //
    if (!isNativeApp())
    {
        if (strcmp(m_package, package) == 0)
        {
            vfxPostInvoke(this, &VappAppWidgetShortcut::onPostDelete);
        }
    }
}


void VappAppWidgetShortcut::onPostDelete(void *userData)
{
    VFX_UNUSED(userData);

    m_signalDeselect.emit(this);
}


VfxBool VappAppWidgetShortcut::isNativeApp() const
{
    if (strncmp(m_package, "native.", sizeof("native.") - 1) == 0)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


void VappAppWidgetShortcut::onEnterEditMode()
{
    if (m_cell)
    {
        m_cell->setBadgeHidden(VFX_TRUE);
    }
}


void VappAppWidgetShortcut::onExitEditMode()
{
    if (m_cell)
    {
        m_cell->setBadgeHidden(VFX_FALSE);
    }
}


VfxPoint VappAppWidgetShortcut::onGetEditButtonOffset()
{
    VfxSize size = getSize();

    return VfxPoint(size.width - EDIT_BUTTON_OFFSET_X, EDIT_BUTTON_OFFSET_Y);
}


VappDrawerCell *VappAppWidgetShortcut::createCell()
{
    VappDrawerCell *cell;

    // TODO: 'createDrawerCell' should change its first parameter type to
    // 'VfxChar *'.
    VfxChar temp[MMI_APP_NAME_MAX_LEN];
    strncpy(temp, getPackage(), MMI_APP_NAME_MAX_LEN - 1);

    cell = createDrawerCell(temp, this, isPreInstalled());
    VFX_ASSERT(cell);

    cell->onCellDisplay();
    cell->setIsUnhittable(VFX_TRUE);
    cell->setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);

    return cell;
}


void VappAppWidgetShortcut::onTap(const VfxPoint &pos)
{
    VFX_UNUSED(pos);

    srv_appmgr_launch(m_package);
}


void VappAppWidgetShortcut::setHighlighted(VfxBool isOn)
{
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    if (isOn)
    {
        setOpacity(0.7f);
    }
    else
    {
        setOpacity(1.0f);
    }

    VfxAutoAnimate::commit();
}


void VappAppWidgetShortcut::clear()
{
    VFX_FREE_MEM(m_package);
}

#endif /* defined(__MMI_VUI_LAUNCHER__) */

