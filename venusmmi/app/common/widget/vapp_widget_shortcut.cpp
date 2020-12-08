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
 *  vapp_widget_shortcut.cpp
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

#if defined(__MMI_VUI_WIDGET_FACTORY__) && defined(__COSMOS_MMI_PACKAGE__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMIDataType.h"
#include "vapp_widget.h"
#include "vapp_widget_kit.h"
#include "vapp_widget_shortcut.h"
#include "vapp_launcher_cosmos_mm_builder.h"

//
// Include C headers without extern "C" internally.
//
extern "C"
{
#include "AppMgrSrvGprot.h"
#include "mmi_cb_mgr_gprot.h"
}


/*****************************************************************************
 * Shortcut Widget Content
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(
    "VappWidgetShortcutContent",
    VappWidgetShortcutContent,
    VfxControl);


VappWidgetShortcutContent::VappWidgetShortcutContent() :
    m_cell(NULL)
{
    // Do nothing.
}


void VappWidgetShortcutContent::onInit()
{
    VfxControl::onInit();
}


void VappWidgetShortcutContent::onDeinit()
{
    VfxControl::onDeinit();
}


VfxBool VappWidgetShortcutContent::onPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            m_signalHighlightChanged.emit(VFX_TRUE);
            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
            if (containPoint(event.getRelPos(this)))
            {
                m_signalHighlightChanged.emit(VFX_TRUE);
            }
            else
            {
                m_signalHighlightChanged.emit(VFX_FALSE);
            }
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            if (containPoint(event.getRelPos(this)))
            {
                m_signalTapped.emit();
            }

            VFX_OBJ_CREATE(m_timer, VfxTimer, this);
            m_timer->m_signalTick.connect(this, &VappWidgetShortcutContent::OnTimerOut);
            m_timer->setStartDelay(1);
            m_timer->start();
            break;

        case VFX_PEN_EVENT_TYPE_ABORT:
            m_signalHighlightChanged.emit(VFX_FALSE);
            break;

        default:
            break;
    }

    return VFX_TRUE;
}


void VappWidgetShortcutContent::createView(VappWidgetShortcut *shortcut)
{
    VFX_ASSERT(!m_cell && shortcut);

    // TODO: 'vappLauncherCosmosMmCreateCell' should change its first parameter type to
    // 'VfxChar *'.
    VfxChar temp[MMI_APP_NAME_MAX_LEN];
    mmi_ret ret = srv_appmgr_get_app_package_name_by_id((VfxU32)shortcut->getPackage(), temp);
    VFX_ASSERT(ret == MMI_RET_OK);

    m_cell = vappLauncherCosmosMmCreateCell(temp, this, shortcut->isPreInstalled());
    VFX_ASSERT(m_cell);

    m_cell->setOnShortcut(VFX_TRUE);
    m_cell->onCellDisplay();

    setSize(m_cell->getSize());
}


void VappWidgetShortcutContent::setCounterHidden(VfxBool isHidden)
{
    VFX_ASSERT(m_cell); // Should create view first.

    m_cell->setBadgeHidden(isHidden);
}


void VappWidgetShortcutContent::OnTimerOut(VfxTimer *timer)
{
    ASSERT(timer);
    timer->stop();
    VFX_OBJ_CLOSE(m_timer);

    m_signalHighlightChanged.emit(VFX_FALSE);
}


/*****************************************************************************
 * Shortcut Widget
 *****************************************************************************/

VAPP_WIDGET_IMPLEMENT_CLASS(VappWidgetShortcut, VappWidget);

const VfxFloat VappWidgetShortcut::s_opacityTapped = 0.5f;


VappWidgetShortcut::VappWidgetShortcut() :
    m_package(0),
    m_content(NULL)
{
    // Do nothing.
}


VappWidgetShortcut::~VappWidgetShortcut()
{
    clear();
}


void VappWidgetShortcut::setPackage(const VfxS32 package)
{
    VFX_ASSERT(package);

    clear();

    m_package = package;
}


const VfxS32 VappWidgetShortcut::getPackage()
{
    return m_package;
}


VfxBool VappWidgetShortcut::isPreInstalled() const
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
    VfxChar appName[MMI_APP_NAME_MAX_LEN];

    VFX_SYS_ALLOC_MEM(package, num * sizeof(mmi_app_package_name_struct));

    mmi_ret ret = srv_appmgr_get_app_package_list(
                    SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE,
                    package,
                    num);
    VFX_ASSERT(ret != MMI_RET_ERR);

    ret = srv_appmgr_get_app_package_name_by_id((VfxU32)m_package, appName);

    VFX_ASSERT(ret != MMI_RET_ERR);

    //
    // Check if this APP belongs to pre-installed APP.
    //
    VfxBool isFound = VFX_FALSE;

    for (VfxS32 i = 0; i < num; i++)
    {
        if (strcmp(appName, package[i]) == 0)
        {
            isFound = VFX_TRUE;
            break;
        }
    }

    VFX_SYS_FREE_MEM(package);

    return isFound;
}


VappWidgetId VappWidgetShortcut::getId() const
{
    return VappWidgetId(VAPP_WIDGET_SRC_SHORTCUT, m_package);
}


VfxS32 VappWidgetShortcut::getName(VfxWChar *string, VfxS32 size) const
{
    VfxChar temp[MMI_APP_NAME_MAX_LEN];
    WCHAR appName[MMI_APP_NAME_MAX_LEN];

    mmi_ret ret;

    ret = srv_appmgr_get_app_package_name_by_id((VfxU32)m_package, temp);
    VFX_ASSERT(ret == MMI_RET_OK);

    ret = srv_appmgr_get_app_package_name(temp, appName);

    if (ret == MMI_RET_OK)
    {
        mmi_wcsncpy(string, (VfxWChar*)appName, size - 1); // 1: null terminated
        return mmi_wcslen(string);
    }

    return 0;
}


VfxSize VappWidgetShortcut::getMaxSize() const
{
    return VfxSize(MAX_SIZE_WIDTH, MAX_SIZE_HEIGHT);
}


VfxFrame *VappWidgetShortcut::createIcon(VfxObject *parentObj)
{
    VappLauncherCosmosMmCell *cell;

    // TODO: 'vappLauncherCosmosMmCreateCell' should change its first parameter type to
    // 'VfxChar *'.
    VfxChar temp[MMI_APP_NAME_MAX_LEN];
    mmi_ret ret = srv_appmgr_get_app_package_name_by_id((VfxU32)m_package, temp);
    VFX_ASSERT(ret == MMI_RET_OK);

    cell = vappLauncherCosmosMmCreateCell(temp, parentObj, isPreInstalled());
    cell->setOnShortcut(VFX_TRUE);
    cell->setTextFrameHidden(VFX_TRUE);
    cell->setBadgeHidden(VFX_TRUE);
    cell->onCellDisplay();

    return cell;
}


void VappWidgetShortcut::onCreateView()
{
    VappWidget::onCreateView();

    VappWidgetShortcutManager::add(this);

    VFX_ASSERT(!m_content);

    m_content = createContent(); // assert for memory leak.

    mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE,  &VappWidgetShortcut::eventHandler, (void *)getObjHandle());
}


void VappWidgetShortcut::onReleaseView()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE, &VappWidgetShortcut::eventHandler, (void *)getObjHandle());

    VFX_OBJ_CLOSE(m_content);

    VappWidgetShortcutManager::remove(this);

    VappWidget::onReleaseView();
}


void VappWidgetShortcut::onRestoreView(VfxArchive *ar)
{
    VFX_ASSERT(!m_content);

    VappWidgetShortcutManager::add(this);

    m_content = createContent(); // assert for memory leak.

    if(isInEditMode())
    {
        m_content->setCounterHidden(VFX_TRUE);
    }
}


void VappWidgetShortcut::onSerializeView(VfxArchive *ar)
{
    VFX_OBJ_CLOSE(m_content);

    VappWidgetShortcutManager::remove(this);
}


mmi_ret VappWidgetShortcut::eventHandler(mmi_event_struct *event)
{
    VappWidgetShortcut *shortcut = (VappWidgetShortcut *)VfxObject::handleToObject((VfxObjHandle)event->user_data);

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


void VappWidgetShortcut::uninstallUpdate(const mmi_app_package_char *package)
{
    VfxChar temp[MMI_APP_NAME_MAX_LEN];
    mmi_ret ret;

    ret = srv_appmgr_get_app_package_name_by_id((VfxU32)m_package, temp);

    if (ret != MMI_RET_OK)
    {
        // If we cannot get the package name, represent the app doesn't exist.
        vfxPostInvoke(this, &VappWidgetShortcut::onPostDelete);
    }
    else
    {
        // If we can get the package name, dobule-check whether the package info
        // is really present because Java can always convert ID and package name
        // even if Java is uninstalled.
        //
        // TODO: Java should fix this problem.
        // SEE ALSO: MAUI_03215059.
        srv_app_info_struct info;

        if (srv_appmgr_get_app_package_info(temp, &info) != MMI_RET_OK)
        {
            vfxPostInvoke(this, &VappWidgetShortcut::onPostDelete);
        }
    }
}


void VappWidgetShortcut::onEnterEditMode()
{
    if (m_content)
    {
        m_content->setCounterHidden(VFX_TRUE);
    }
}


void VappWidgetShortcut::onExitEditMode()
{
    if (m_content)
    {
        m_content->setCounterHidden(VFX_FALSE);
    }
}


VfxPoint VappWidgetShortcut::onGetEditButtonOffset()
{
    VfxSize size = getSize();

    return VfxPoint(size.width - EDIT_BUTTON_OFFSET_X, EDIT_BUTTON_OFFSET_Y);
}


VfxBool VappWidgetShortcut::isNativeApp() const
{
    VfxChar temp[MMI_APP_NAME_MAX_LEN];

    mmi_ret ret = srv_appmgr_get_app_package_name_by_id((VfxU32)m_package, temp);

    if (strncmp(temp, "native.", sizeof("native.") - 1) == 0)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


VappWidgetShortcutContent *VappWidgetShortcut::createContent()
{
    VappWidgetShortcutContent *content;

    VFX_OBJ_CREATE(content, VappWidgetShortcutContent, this);
    content->createView(this);
    content->m_signalTapped.connect(this, &VappWidgetShortcut::onContentTapped);
    content->m_signalHighlightChanged.connect(this, &VappWidgetShortcut::onHighlightChanged);

    setSize(content->getSize());

    return content;
}


void VappWidgetShortcut::onContentTapped()
{
    vfxPostInvoke(this, &VappWidgetShortcut::onPostInvoke);
}


void VappWidgetShortcut::onHighlightChanged(VfxBool isHighlighted)
{
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    if (isHighlighted)
    {
        setOpacity(s_opacityTapped);
    }
    else
    {
        setOpacity(1.0f);
    }

    VfxAutoAnimate::commit();
}


void VappWidgetShortcut::onPostInvoke(void *userData)
{
    VFX_UNUSED(userData);

    VfxChar temp[MMI_APP_NAME_MAX_LEN];
    mmi_ret ret = srv_appmgr_get_app_package_name_by_id((VfxU32)m_package, temp);
    VFX_ASSERT(ret == MMI_RET_OK);

    srv_appmgr_launch(temp);
}


void VappWidgetShortcut::onPostDelete(void *userData)
{
    VFX_UNUSED(userData);

    m_signalDeselect.emit(this);
}


void VappWidgetShortcut::clear()
{
    // do nothing
}


void VappWidgetShortcut::updateContent()
{
    VFX_OBJ_CLOSE(m_content);

    m_content = createContent();
}


/*****************************************************************************
 * MRE Widget Manager
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappWidgetShortcutManager", VappWidgetShortcutManager, VfxObject);


VappWidgetShortcutManager *VappWidgetShortcutManager::s_mgr = NULL;

VappWidgetShortcutManager::VappWidgetShortcutManager()
{
}


VappWidgetShortcutManager::~VappWidgetShortcutManager()
{
}


void VappWidgetShortcutManager::onInit()
{
    VfxObject::onInit();

    mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE,  &VappWidgetShortcutManager::eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_INSTALL_PACKAGE,  &VappWidgetShortcutManager::eventHandler, this);
}


void VappWidgetShortcutManager::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE, &VappWidgetShortcutManager::eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_INSTALL_PACKAGE, &VappWidgetShortcutManager::eventHandler, this);

    VfxObject::onDeinit();
}


mmi_ret VappWidgetShortcutManager::eventHandler(mmi_event_struct *event)
{
    VappWidgetShortcutManager *ShortcutManager = (VappWidgetShortcutManager *)event->user_data;

    switch (event->evt_id)
    {
        case EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE:
        case EVT_ID_SRV_APPMGR_INSTALL_PACKAGE:
        {
            srv_app_info_struct info;
            VfxChar temp[MMI_APP_NAME_MAX_LEN];

            for (VfxObjListEntry *entry = ShortcutManager->m_shortcutList.getHead();
                 entry != NULL;
                 entry = entry->getNext())
            {
                VappWidgetShortcut *shortcut;
                shortcut = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidgetShortcut);
                VFX_ASSERT(shortcut);

                memset(temp, 0, MMI_APP_NAME_MAX_LEN);
                mmi_ret ret = srv_appmgr_get_app_package_name_by_id((VfxU32)shortcut->getPackage(), temp);

                if(MMI_RET_ERR == srv_appmgr_get_app_package_info(temp, &info))
                {
                    shortcut->m_signalDeselect.emit(shortcut);
                }
                else
                {
                    shortcut->updateContent();
                }
            }
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}


VappWidgetShortcutManager *VappWidgetShortcutManager::getInstance()
{
    VFX_ASSERT(s_mgr);

    return s_mgr;
}


void VappWidgetShortcutManager::add(VappWidgetShortcut *widget)
{
    //
    // Smart creation of the manager.
    //
    // TODO: please find a dedicated memory pool for the manager.
    //
    if (!s_mgr)
    {
        VFX_OBJ_CREATE(s_mgr, VappWidgetShortcutManager, widget->getParent());
    }

    if (!s_mgr->m_shortcutList.contains(widget))
    {
        s_mgr->m_shortcutList.append(widget);
    }
}


void VappWidgetShortcutManager::remove(VappWidgetShortcut *widget)
{
    if (!s_mgr)
    {
        return;
    }

    s_mgr->m_shortcutList.removeOne(widget);

    //
    // Smart close of the manager.
    //
    if (s_mgr->m_shortcutList.getEntryCount() == 0)
    {
        VFX_OBJ_CLOSE(s_mgr);
    }
}
#endif /* defined(__MMI_VUI_WIDGET_FACTORY__) && defined(__COSMOS_MMI_PACKAGE__) */

