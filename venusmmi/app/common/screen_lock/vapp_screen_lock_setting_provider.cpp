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
 *  vapp_screen_lock_setting_provider.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the setting provider of the screen lock.
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

#if defined(__MMI_VUI_SCREEN_LOCK_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_screen_lock_def.h"
#include "vapp_screen_lock_native_factory.h"
#include "vapp_screen_lock_kit.h"
#include "vapp_screen_lock_setting_provider.h"

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
    "VappScreenLockSettingProvider",
    VappScreenLockSettingProvider,
    VfxObject);

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappScreenLockSettingProvider);


VappScreenLockSettingProvider::VappScreenLockSettingProvider()
{
    for (VfxS32 i = 0; i < CUSTOM_SCREEN_LOCK_MAX_NUM; i++)
    {
        m_elem[i].isUsed = VFX_FALSE;
    }
}


void VappScreenLockSettingProvider::onInit()
{
    VfxObject::onInit();

    initSys();

#if defined(__MMI_VUI_SCREEN_LOCK_MRE__)
        mmi_frm_cb_reg_event(
            EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE,
            VappScreenLockSettingProvider::eventProc,
            getObjHandle());
#endif /* defined(__MMI_VUI_SCREEN_LOCK_MRE__) */
}


void VappScreenLockSettingProvider::onDeinit()
{
#if defined(__MMI_VUI_SCREEN_LOCK_MRE__)
    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE,
        VappScreenLockSettingProvider::eventProc,
        getObjHandle());
#endif /* defined(__MMI_VUI_SCREEN_LOCK_MRE__) */

    VfxObject::onDeinit();
}


VappScreenLockId VappScreenLockSettingProvider::getDefaultScreenLock()
{
    VfxS32 foundIdx = -1; // -1 means not found.

    for (VfxS32 i = 0; i < SCREEN_LOCK_NUM; i++)
    {
        if (m_elem[i].isUsed && m_elem[i].isDefault)
        {
            foundIdx = i;
            break;
        }
    }

    VappScreenLockId id;

    if (foundIdx < 0)
    {
        id = getScreenLockIfAny();
        setDefaultScreenLock(id);
    }
    else
    {
        id = m_elem[foundIdx].id;

        // False-safe. Check if the default screen lock is valid.
        VappScreenLockKit *kit = VFX_OBJ_GET_INSTANCE(VappScreenLockKit);
        if (!kit->isIdValid(id))
        {
            id = getScreenLockIfAny();
            setDefaultScreenLock(id);
        }
    }

    return id;
}


void VappScreenLockSettingProvider::setDefaultScreenLock(
    const VappScreenLockId &id)
{
    VfxS32 selectedIdx = find(id);

    for (VfxS32 i = 0; i < SCREEN_LOCK_NUM; i++)
    {
        if (m_elem[i].isUsed)
        {
            m_elem[i].isDefault = (selectedIdx == i ? VFX_TRUE : VFX_FALSE);
        }
    }

    syncSys();

    m_signalDefaultScreenLockChanged.postEmit();
}


VappScreenLockId VappScreenLockSettingProvider::getScreenLockIfAny() const
{
    VappScreenLockId id;

#if defined(__COSMOS_3D_V10__) && defined(__MMI_VUI_SCREEN_LOCK_STEAM__)
    //
    // On 3D project, choose the steam screen lock by default.
    //
    id.assignWith(VAPP_SCREEN_LOCK_SRC_NATIVE, VAPP_SCREEN_LOCK_TYPE_STEAM);
#else
    //
    // Otherwise, choose the first native screen lock by default.
    //
    VappScreenLockNativeFactory *factory;

    factory = VFX_OBJ_GET_INSTANCE(VappScreenLockNativeFactory);

    VfxS32 totalNum = factory->getTotalNum();
    VFX_ASSERT(totalNum > 0);

    // The system global context is only used in this function. All memory
    // should be released before this function exits.
    VappScreenLockId **allId;

    allId = VappScreenLockId::newArray(totalNum, VFX_SYS_GLOBAL_CONTEXT);

    factory->getAllId(allId, totalNum);

    id.assignWith(*(allId[0]));

    VappScreenLockId::deleteArray(allId, totalNum); // Release memory.
#endif /* defined(__COSMOS_3D_V10__) && defined(__MMI_VUI_SCREEN_LOCK_STEAM__) */

    return id;
}


VfxArchive *VappScreenLockSettingProvider::createArchiveReader(
    SettingIdEnum settingId,
    VfxObject *parentObj)
{
    VappScreenLockId id = getDefaultScreenLock();

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


VfxArchive *VappScreenLockSettingProvider::createArchiveWriter(
    SettingIdEnum settingId,
    VfxObject *parentObj)
{
    VappScreenLockId id = getDefaultScreenLock();

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


#if defined(__MMI_VUI_SCREEN_LOCK_MRE__)
mmi_ret VappScreenLockSettingProvider::eventProc(mmi_event_struct *evt)
{
    VappScreenLockSettingProvider *provider;

    provider = VFX_OBJ_GET_INSTANCE(VappScreenLockSettingProvider);

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


void VappScreenLockSettingProvider::handleUninstall(const VfxChar *appName)
{
    VappScreenLockId id(VAPP_SCREEN_LOCK_SRC_MRE, appName);

    for (VfxS32 i = 0; i < SCREEN_LOCK_NUM; i++)
    {
        if (m_elem[i].isUsed && m_elem[i].id == id)
        {
            m_elem[i].isUsed = VFX_FALSE;
        }
    }

    syncSys();
}
#endif /* defined(__MMI_VUI_SCREEN_LOCK_MRE__) */


VfxArchive *VappScreenLockSettingProvider::createArchive(
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


VfxArchive *VappScreenLockSettingProvider::createSysArchive(
    VappArchiveNvramSource::SourceModeEnum mode,
    VfxObject *parentObj) const
{
    return createArchive(
            NVRAM_EF_VAPP_SCREEN_LOCK_SYS_SETTING_LID,
            1,
            NVRAM_EF_VAPP_SCREEN_LOCK_SYS_SETTING_SIZE,
            mode,
            parentObj);
}


nvram_lid_enum VappScreenLockSettingProvider::getLid(
    SettingIdEnum settingId) const
{
    nvram_lid_enum ret = 0;

    switch (settingId)
    {
        case SETTING_ID_WALLPAPER:
            ret = NVRAM_EF_VAPP_SCREEN_LOCK_WALLPAPER_SETTING_LID;
            break;

        default:
            VFX_ASSERT(0);
            break;
    }

    return ret;
}


VfxS32 VappScreenLockSettingProvider::getLidSize(SettingIdEnum settingId) const
{
    VfxS32 ret = 0;

    switch (settingId)
    {
        case SETTING_ID_WALLPAPER:
            ret = NVRAM_EF_VAPP_SCREEN_LOCK_WALLPAPER_SETTING_SIZE;
            break;

        default:
            VFX_ASSERT(0);
            break;
    }

    return ret;
}


VfxS32 VappScreenLockSettingProvider::find(const VappScreenLockId &id)
{
    VfxS32 freeIdx = -1;

    for (VfxS32 i = 0; i < SCREEN_LOCK_NUM; i++)
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

    VFX_ASSERT(freeIdx >= 0 && freeIdx < SCREEN_LOCK_NUM);

    m_elem[freeIdx].id = id;
    m_elem[freeIdx].isUsed = VFX_TRUE;
    m_elem[freeIdx].isDefault = VFX_FALSE;

    return freeIdx;
}


void VappScreenLockSettingProvider::initSys()
{
    // The system global context is only used in this function. All memory
    // should be released before this function exits.
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

    for (VfxS32 i = 0; i < SCREEN_LOCK_NUM; i++)
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


void VappScreenLockSettingProvider::syncSys()
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

    for (VfxS32 i = 0; i < SCREEN_LOCK_NUM; i++)
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

#endif /* defined(__MMI_VUI_SCREEN_LOCK_FACTORY__) */

