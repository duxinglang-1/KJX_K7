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
 *  vapp_launcher_setting_provider.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the setting provider of the launcher.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_launcher_def.h"
#include "vapp_launcher_native_factory.h"
#include "vapp_launcher_kit.h"
#include "vapp_launcher_setting_provider.h"

//
// C headers
//
extern "C"
{
#include "MMIDataType.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "AppMgrSrvGprot.h"
}


/*****************************************************************************
 * Setting Provider
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(
    "VappLauncherSettingProvider",
    VappLauncherSettingProvider,
    VfxObject);

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappLauncherSettingProvider);


VappLauncherSettingProvider::VappLauncherSettingProvider()
{
    for (VfxS32 i = 0; i < LAUNCHER_NUM; i++)
    {
        m_elem[i].isUsed = VFX_FALSE;
    }
}


void VappLauncherSettingProvider::onInit()
{
    VfxObject::onInit();

    initSys();

    //
    // Fail-safe. Check if default launcher is valid.
    //
    if (!isDefaultLauncherExisted())
    {
        setDefaultLauncher(getLauncherIfAny());
    }

#if defined(__MMI_VUI_LAUNCHER_MRE__)
    mmi_frm_cb_reg_event(
        EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE,
        VappLauncherSettingProvider::eventProc,
        getObjHandle());
#endif /* defined(__MMI_VUI_LAUNCHER_MRE__) */
}


void VappLauncherSettingProvider::onDeinit()
{
#if defined(__MMI_VUI_LAUNCHER_MRE__)
    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE,
        VappLauncherSettingProvider::eventProc,
        getObjHandle());
#endif /* defined(__MMI_VUI_LAUNCHER_MRE__) */

    VfxObject::onDeinit();
}


VappLauncherId VappLauncherSettingProvider::getDefaultLauncher()
{
    VappLauncherId id = getDefaultLauncherInt();

    if (id.getSource() == VAPP_LAUNCHER_SRC_INVALID)
    {
        id = getLauncherIfAny();
        setDefaultLauncher(id);
    }

    return id;
}


void VappLauncherSettingProvider::setDefaultLauncher(const VappLauncherId &id)
{
    if (id == getDefaultLauncherInt())
    {
        return; // Skip if there is no change.
    }

    //
    // Save it permanently.
    //
    removeInvalidItems(); // Fail-safe. Make sure all invalid items are removed.

    VfxS32 selectedIdx = find(id);

    for (VfxS32 i = 0; i < LAUNCHER_NUM; i++)
    {
        if (m_elem[i].isUsed)
        {
            m_elem[i].isDefault = (selectedIdx == i ? VFX_TRUE : VFX_FALSE);
        }
    }

    syncSys();

    //
    // Notify others.
    //
    m_signalDefaultLauncherChanged.postEmit();
}


void VappLauncherSettingProvider::updateDefaultLauncher(
    const VappLauncherId &id)
{
    if (id == getDefaultLauncherInt())
    {
        return; // Skip if there is no change.
    }

    setDefaultLauncher(id);

    m_signalLauncherUpdated.postEmit();
}


VappLauncherId VappLauncherSettingProvider::getLauncherIfAny() const
{
    VappLauncherNativeFactory *factory;
    VappLauncherId id;

    factory = VFX_OBJ_GET_INSTANCE(VappLauncherNativeFactory);

    VfxS32 totalNum = factory->getTotalNum();
    VFX_ASSERT(totalNum > 0);

    // The system global context is only used in this function. All memory
    // should be released before this function exits.
    VappLauncherId **allId;

    allId = VappLauncherId::newArray(totalNum, VFX_SYS_GLOBAL_CONTEXT);

    factory->getAllId(allId, totalNum);

    id.assignWith(*(allId[0]));

    VappLauncherId::deleteArray(allId, totalNum); // Release memory.

    return id;
}


VfxArchive *VappLauncherSettingProvider::createArchiveReader(
    SettingIdEnum settingId,
    VfxObject *parentObj)
{
    VappLauncherId id = getDefaultLauncher();

    VfxArchive *ar = createArchive(
                        getLid(settingId),
                        find(id) + 1,
                        getLidSize(settingId),
                        VappArchiveNvramSource::SOURCE_MODE_READ,
                        parentObj);

    if (!ar)
    {
        return NULL;
    }

    VfxU32 guardPattern = ar->readU32();

    if (guardPattern != GUARD_PATTERN)
    {
        VFX_OBJ_CLOSE(ar);
        return NULL;
    }

    return ar;
}


VfxArchive *VappLauncherSettingProvider::createArchiveWriter(
    SettingIdEnum settingId,
    VfxObject *parentObj)
{
    VappLauncherId id = getDefaultLauncher();

    VfxArchive *ar = createArchive(
                        getLid(settingId),
                        find(id) + 1,
                        getLidSize(settingId),
                        VappArchiveNvramSource::SOURCE_MODE_WRITE,
                        parentObj);

    if (!ar)
    {
        return NULL;
    }

    VfxU32 guardPattern = GUARD_PATTERN;
    ar->writeU32(guardPattern);

    return ar;
}


#if defined(__MMI_VUI_LAUNCHER_MRE__)
mmi_ret VappLauncherSettingProvider::eventProc(mmi_event_struct *evt)
{
    VappLauncherSettingProvider *provider;

    provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE:
        {
            srv_appmgr_update_event_struct *p;

            p = (srv_appmgr_update_event_struct *)evt;;

            provider->handleUninstall(p->app_name);

            break;
        }
        default:
        {
            break;
        }
    }

    return MMI_RET_OK;
}


void VappLauncherSettingProvider::handleUninstall(const VfxChar *appName)
{
    VappLauncherId id(VAPP_LAUNCHER_SRC_MRE, appName);

    for (VfxS32 i = 0; i < LAUNCHER_NUM; i++)
    {
        if (m_elem[i].isUsed && m_elem[i].id == id)
        {
            m_elem[i].isUsed = VFX_FALSE;
        }
    }

    //
    // If the default launche is uninstalled, we shall update the launcher.
    //
    if (isDefaultLauncherExisted())
    {
        syncSys();
    }
    else
    {
        updateDefaultLauncher(getLauncherIfAny());
    }
}
#endif /* defined(__MMI_VUI_LAUNCHER_MRE__) */


VappLauncherId VappLauncherSettingProvider::getDefaultLauncherInt() const
{
    for (VfxS32 i = 0; i < LAUNCHER_NUM; i++)
    {
        if (m_elem[i].isUsed && m_elem[i].isDefault)
        {
            return m_elem[i].id;
        }
    }

    return VappLauncherId(VAPP_LAUNCHER_SRC_INVALID, 0);
}


VfxBool VappLauncherSettingProvider::isDefaultLauncherExisted() const
{
    if (getDefaultLauncherInt().getSource() != VAPP_LAUNCHER_SRC_INVALID)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


VfxArchive *VappLauncherSettingProvider::createArchive(
    nvram_lid_enum lid,
    VfxS32 lidIndex,
    VfxS32 lidSize,
    VappArchiveNvramSource::SourceModeEnum mode,
    VfxObject *parentObj) const
{
    VfxArchive *ar;
    VappArchiveNvramSource *arSource;

    VFX_OBJ_CREATE(ar, VfxArchive, parentObj);
    VFX_OBJ_CREATE(arSource, VappArchiveNvramSource, ar);

    VfxBool ret = arSource->open(lid, lidIndex, lidSize, mode);
    if (!ret)
    {
        VFX_OBJ_CLOSE(ar);
        return NULL;
    }

    ar->setSource(arSource);

    return ar;
}


VfxArchive *VappLauncherSettingProvider::createSysArchive(
    VappArchiveNvramSource::SourceModeEnum mode,
    VfxObject *parentObj) const
{
    return createArchive(
            NVRAM_EF_VAPP_LAUNCHER_SYS_SETTING_LID,
            1,
            NVRAM_EF_VAPP_LAUNCHER_SYS_SETTING_SIZE,
            mode,
            parentObj);
}


nvram_lid_enum VappLauncherSettingProvider::getLid(
    SettingIdEnum settingId) const
{
    nvram_lid_enum ret = 0;

    switch (settingId)
    {
        case SETTING_ID_WALLPAPER:
            ret = NVRAM_EF_VAPP_LAUNCHER_WALLPAPER_SETTING_LID;
            break;

    #if defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__)
        case SETTING_ID_APP_ICON:
            ret = NVRAM_EF_VAPP_LAUNCHER_APP_ICON_SETTING_LID;
            break;
    #endif /* defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__) */

        default:
            VFX_ASSERT(0);
            break;
    }

    return ret;
}


VfxS32 VappLauncherSettingProvider::getLidSize(SettingIdEnum settingId) const
{
    VfxS32 ret = 0;

    switch (settingId)
    {
        case SETTING_ID_WALLPAPER:
            ret = NVRAM_EF_VAPP_LAUNCHER_WALLPAPER_SETTING_SIZE;
            break;

    #if defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__)
        case SETTING_ID_APP_ICON:
            ret = NVRAM_EF_VAPP_LAUNCHER_APP_ICON_SETTING_SIZE;
            break;
    #endif /* defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__) */

        default:
            VFX_ASSERT(0);
            break;
    }

    return ret;
}


void VappLauncherSettingProvider::removeInvalidItems()
{
    VappLauncherKit *kit = VFX_OBJ_GET_INSTANCE(VappLauncherKit);

    for (VfxS32 i = 0; i < LAUNCHER_NUM; i++)
    {
        if (m_elem[i].isUsed && !kit->isIdValid(m_elem[i].id))
        {
            m_elem[i].isUsed = VFX_FALSE;
        }
    }
}


VfxS32 VappLauncherSettingProvider::find(const VappLauncherId &id)
{
    VfxS32 freeIdx = -1;

    for (VfxS32 i = 0; i < LAUNCHER_NUM; i++)
    {
        if (!m_elem[i].isUsed)
        {
            if (freeIdx < 0)
            {
                freeIdx = i;
            }

            continue;
        }

        if (m_elem[i].id == id)
        {
            return i;
        }
    }

    VFX_ASSERT(freeIdx >= 0 && freeIdx < LAUNCHER_NUM);

    m_elem[freeIdx].id = id;
    m_elem[freeIdx].isUsed = VFX_TRUE;
    m_elem[freeIdx].isDefault = VFX_FALSE;

    return freeIdx;
}


void VappLauncherSettingProvider::initSys()
{
    //
    // The system global context is only used in this function. All memory
    // should be released before this function exits.
    //
    VfxArchive *ar = createSysArchive(
                        VappArchiveNvramSource::SOURCE_MODE_READ,
                        VFX_SYS_GLOBAL_CONTEXT);
    if (!ar)
    {
        return;
    }

    VfxU32 guardPattern = ar->readU32();

    if (guardPattern != GUARD_PATTERN)
    {
        VFX_OBJ_CLOSE(ar);
        return;
    }

    for (VfxS32 i = 0; i < LAUNCHER_NUM; i++)
    {
        m_elem[i].isUsed = (ar->readU8() == 0 ? VFX_FALSE : VFX_TRUE);

        if (m_elem[i].isUsed)
        {
            m_elem[i].isDefault = (ar->readU8() == 0 ? VFX_FALSE : VFX_TRUE);
            m_elem[i].id.decodeFromArchive(ar);
        }
    }

    VFX_OBJ_CLOSE(ar);
}


void VappLauncherSettingProvider::syncSys()
{
    // The system global context is only used in this function. All memory
    // should be released before this function exits.
    VfxArchive *ar = createSysArchive(
                        VappArchiveNvramSource::SOURCE_MODE_WRITE,
                        VFX_SYS_GLOBAL_CONTEXT);
    if (!ar)
    {
        return;
    }

    VfxU32 guardPattern = GUARD_PATTERN;

    ar->writeU32(guardPattern);

    for (VfxS32 i = 0; i < LAUNCHER_NUM; i++)
    {
        ar->writeU8(m_elem[i].isUsed ? 0x01 : 0x00);

        if (m_elem[i].isUsed)
        {
            ar->writeU8(m_elem[i].isDefault ? 0x01 : 0x00);
            m_elem[i].id.encodeToArchive(ar);
        }
    }

    VFX_OBJ_CLOSE(ar);
}

#endif /* defined(__MMI_VUI_LAUNCHER_FACTORY__) */

