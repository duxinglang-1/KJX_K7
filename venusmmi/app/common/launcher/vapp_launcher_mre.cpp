/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  vapp_launcher_mre.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the MRE launcher and its content provider.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

#if defined(__MMI_VUI_LAUNCHER_MRE__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include <ctype.h>
#include <string.h>

#include "vapp_launcher_def.h"

extern "C"
{
#include "MMIDataType.h"
#include "MREAppMgrSrvGprot.h"
#include "FileMgrSrvGprot.h"
#include "USBSrvGProt.h"
#include "mmi_rp_vapp_launcher_mre_def.h"
#include "vmres.h"

#if defined(VAPP_LAUNCHER_UT_ENABLE_SWLA_LOG)
#include "SST_sla.h"
#endif
}

#include "vfx_uc_include.h"
#include "vadp_asm.h"
#include "vapp_theme_appicon_dlt.h"
#include "vpi_app_launcher.h"
#include "vapp_launcher_setting_provider.h"
#include "vapp_launcher.h"
#include "vapp_launcher_heap.h"
#include "vapp_launcher_mre.h"


/*****************************************************************************
 * Utility Class
 *****************************************************************************/

VappLauncherMreUtil::VappLauncherMreUtil()
{
    // Do nothing.
}


VfxU8 VappLauncherMreUtil::getDriveLetter(const VappLauncherId &id)
{
    WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1]; // 1: null terminated char
    MMI_BOOL ret;

    ret = srv_mre_appmgr_get_file_path(
            (mmi_app_package_char *)id.getStringType(),
            path);

    if (!ret)
    {
        return 0xFF; // Non-ASCII code, representing an invalid drive letter.
    }

    return (VfxU8)path[0];
}


VfxBool VappLauncherMreUtil::isDriveMatch(
    const VappLauncherId &id,
    const VfxU8 *target,
    VfxU32 count)
{
    return isDriveMatch(getDriveLetter(id), target, count);
}


VfxBool VappLauncherMreUtil::isDriveMatch(
    VfxU8 source,
    const VfxU8 *target,
    VfxU32 count)
{
    for (VfxU32 i = 0; i < count; i++)
    {
        if (toupper(target[i]) == toupper(source))
        {
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}


/*****************************************************************************
 * Error Mask
 *****************************************************************************/

VappLauncherMreErrorMask::VappLauncherMreErrorMask() :
    m_mask(NULL_STATE)
{
    // Do nothing.
}


VappLauncherMreErrorMask::VappLauncherMreErrorMask(ErrorMask error) :
    m_mask(error)
{
    // Do nothing.
}


void VappLauncherMreErrorMask::set(ErrorMask value)
{
    m_mask |= value;
}


void VappLauncherMreErrorMask::set(const VappLauncherMreErrorMask &error)
{
    m_mask |= error.m_mask;
}


void VappLauncherMreErrorMask::clear(ErrorMask value)
{
    m_mask &= ~value;
}


VfxBool VappLauncherMreErrorMask::has(ErrorMask value) const
{
    return ((m_mask & value) == value) ? VFX_TRUE : VFX_FALSE;
}


VfxBool VappLauncherMreErrorMask::isAnyError() const
{
    return m_mask != 0 ? VFX_TRUE : VFX_FALSE;
}


VfxBool VappLauncherMreErrorMask::isRecoverable() const
{
    if (has(FILE_NOT_FOUND) || has(VPI_FAIL) || has(OUT_OF_MEM))
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


void VappLauncherMreErrorMask::syncSystemState(VfxU8 driveLetter)
{
    //
    // If the drive letter is '@', VPP is a preloaded VPP, stored in the ROM. In
    // this case, we don't need to check USB mass storage mode or T-card state.
    //
    if (driveLetter == '@')
    {
        return;
    }

    //
    // In USB mass storage mode, the drvie will also be unaccessible. So, we
    // should first handle the USB mass storage, then the T-card plug-out.
    //

#if defined(__MMI_USB_SUPPORT__)
    if (srv_usb_is_in_mass_storage_mode())
    {
        set(MASS_STORAGE);
    }
    else
#endif /* defined(__MMI_USB_SUPPORT__) */
    if (!srv_fmgr_drv_is_accessible(driveLetter))
    {
        set(DRIVE_PLUG_OUT);
    }
}


VfxResId VappLauncherMreErrorMask::getPrompt() const
{
    if (has(DRIVE_PLUG_OUT))
    {
        return STR_GLOBAL_FILE_NOT_FOUND;
    }
    else if (has(MASS_STORAGE))
    {
        return STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE;
    }
    else if (has(FILE_NOT_FOUND))
    {
        return STR_GLOBAL_FILE_NOT_FOUND;
    }
    else if (has(OUT_OF_MEM))
    {
        return STR_ID_VAPP_LAUNCHER_MRE_NOT_ENOUGH_MEMORY;
    }
    else if (has(VPI_FAIL))
    {
        return STR_ID_VAPP_LAUNCHER_MRE_CANNOT_LOAD_LAUNCHER;
    }

    return VFX_RES_ID_NULL;
}


void VappLauncherMreErrorMask::reset()
{
    m_mask = NULL_STATE;
}


/*****************************************************************************
 * MRE Launcher Screenshot
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(
    "VappLauncherMreScreenshot",
    VappLauncherMreScreenshot,
    VfxFrame);


const VfxChar VappLauncherMreScreenshot::s_resId[] = "MRE.PREVIEW_0";


VappLauncherMreScreenshot::VappLauncherMreScreenshot() :
    m_driveLetter(0xFF),
    m_package(NULL),
    m_memPtr(NULL),
    m_prompt(NULL)
{
    // Do nothing.
}


void VappLauncherMreScreenshot::onInit()
{
    VfxFrame::onInit();

    setSize(SCREENSHOT_WIDTH, SCREENSHOT_HEIGHT);

    registerEvent();
}


void VappLauncherMreScreenshot::onDeinit()
{
    clear();

    VFX_FREE_MEM(m_package);

    deregisterEvent();

    VfxFrame::onDeinit();
}


void VappLauncherMreScreenshot::show(
    const VfxChar *package,
    VfxU8 driveLetter)
{
    VFX_ASSERT(package);

    //
    // Save package name.
    //
    if (m_package)
    {
        VFX_FREE_MEM(m_package);
    }

    VfxU32 size = vfx_sys_strlen(package) + 1; // 1 for NULL-terminated char.

    VFX_ALLOC_MEM(m_package, size * sizeof(VfxChar), this);

    strncpy(m_package, package, size - 1);
    m_package[size - 1] = '\0';

    //
    // Drive letter
    //
    m_driveLetter = driveLetter;

    //
    // Update View
    //
    updateView();
}


void VappLauncherMreScreenshot::registerEvent()
{
    mmi_frm_cb_reg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN,
        VappLauncherMreScreenshot::eventProc,
        getObjHandle());

    mmi_frm_cb_reg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,
        VappLauncherMreScreenshot::eventProc,
        getObjHandle());

#if defined(__MMI_USB_SUPPORT__)
    mmi_frm_cb_reg_event(
        EVT_ID_USB_ENTER_MS_MODE,
        VappLauncherMreScreenshot::eventProc,
        getObjHandle());

    mmi_frm_cb_reg_event(
        EVT_ID_USB_EXIT_MS_MODE,
        VappLauncherMreScreenshot::eventProc,
        getObjHandle());
#endif /* defined(__MMI_USB_SUPPORT__) */
}


void VappLauncherMreScreenshot::deregisterEvent()
{
    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN,
        VappLauncherMreScreenshot::eventProc,
        getObjHandle());

    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,
        VappLauncherMreScreenshot::eventProc,
        getObjHandle());

#if defined(__MMI_USB_SUPPORT__)
    mmi_frm_cb_dereg_event(
        EVT_ID_USB_ENTER_MS_MODE,
        VappLauncherMreScreenshot::eventProc,
        getObjHandle());

    mmi_frm_cb_dereg_event(
        EVT_ID_USB_EXIT_MS_MODE,
        VappLauncherMreScreenshot::eventProc,
        getObjHandle());
#endif /* defined(__MMI_USB_SUPPORT__) */
}


mmi_ret VappLauncherMreScreenshot::eventProc(mmi_event_struct *evt)
{
    VappLauncherMreScreenshot *_this;

    _this = (VappLauncherMreScreenshot *)handleToObject(evt->user_data);

    VFX_OBJ_ASSERT_VALID(_this);

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:  // Fall-through
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {
            srv_fmgr_notification_dev_plug_event_struct *p;

            p = (srv_fmgr_notification_dev_plug_event_struct *)evt;

            VfxBool isMatched = VappLauncherMreUtil::isDriveMatch(
                                    _this->m_driveLetter,
                                    p->drv_letters,
                                    p->count);

            if (isMatched)
            {
                _this->updateView();
            }

            break;
        }

#if defined(__MMI_USB_SUPPORT__)
        case EVT_ID_USB_ENTER_MS_MODE:      // Fall-through
        case EVT_ID_USB_EXIT_MS_MODE:
        {
            _this->updateView();
            break;
        }
#endif /* defined(__MMI_USB_SUPPORT__) */

        default:
        {
            break;
        }
    }

    return MMI_RET_OK;
}


void VappLauncherMreScreenshot::updateView()
{
    clear();

    VfxResId errorStr;
    VfxBool ret = createImageContent(errorStr);

    if (!ret)
    {
        createErrorPrompt(errorStr);
    }
}


VfxBool VappLauncherMreScreenshot::createImageContent(VfxResId &errorStr)
{
    //
    // Get the VSO file path.
    //
    WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1]; // 1: null terminated char
    MMI_BOOL isPathGot;

    isPathGot = srv_mre_appmgr_get_file_path(
                    (mmi_app_package_char *)m_package,
                    path);

    if (!isPathGot)
    {
        errorStr = STR_GLOBAL_FILE_NOT_FOUND;
        return VFX_FALSE;
    }

    //
    // Get image size
    //
    vm_res_read_hint_struct hint;
    VMBOOL isMemSizeGot;

    isMemSizeGot = vm_load_resource_use_outside_memory(
                    (VMWSTR)path,
                    (CHAR *)s_resId,
                    NULL,
                    0,
                    &hint);

    if (!isMemSizeGot)
    {
        errorStr = STR_GLOBAL_FILE_NOT_FOUND;
        return VFX_FALSE;
    }

    if (hint.res_size > VAPP_LAUNCHER_MRE_SCREENSHOT_SIZE)
    {
        errorStr = STR_GLOBAL_INSUFFICIENT_MEMORY;
        return VFX_FALSE;
    }

    //
    // Create a memory object. Let its parent be the screenshot such that once
    // the screenshot is closed, the memory will be freed.
    //
    VFX_ASSERT(!m_memPtr);

    VFX_ALLOC_MEM(m_memPtr, hint.res_size, this);

    if (!m_memPtr)
    {
        errorStr = STR_GLOBAL_INSUFFICIENT_MEMORY;
        return VFX_FALSE;
    }

    //
    // Get image content
    //
    VMBOOL isImageGot;

    isImageGot = vm_load_resource_use_outside_memory(
                    (VMWSTR)path,
                    (CHAR *)s_resId,
                    m_memPtr,
                    hint.res_size,
                    &hint);

    if (!isImageGot)
    {
        VFX_FREE_MEM(m_memPtr);
        errorStr = STR_GLOBAL_FILE_NOT_FOUND;
        return VFX_FALSE;
    }

    setImgContent(VfxImageSrc(m_memPtr));

    return VFX_TRUE;
}


void VappLauncherMreScreenshot::createErrorPrompt(const VfxResId &errorStr)
{
    VFX_ASSERT(!m_prompt);

    VFX_OBJ_CREATE(m_prompt, VfxTextFrame, this);
    m_prompt->setAnchor(0.5f, 0.5f);
    m_prompt->setPos(SCREENSHOT_WIDTH / 2, SCREENSHOT_HEIGHT / 2);
    m_prompt->setString(VFX_WSTR_RES(errorStr));
    m_prompt->setColor(VFX_COLOR_WHITE);
}


void VappLauncherMreScreenshot::clear()
{
    //
    // Error Prompt.
    //
    VFX_OBJ_CLOSE(m_prompt);

    //
    // Image Content.
    //
    // Note that if the image content comes from the memory buffer, we need to
    // suspend VRT until the next commit. Otherwise, VRT will continue to access
    // this invalid memory block.
    //
    VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();

    setImgContent(VfxImageSrc());
    VFX_FREE_MEM(m_memPtr);
}


/*****************************************************************************
 * MRE Launcher Provider
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(
    "VappLauncherMreProvider",
    VappLauncherMreProvider,
    VfxControl);


VappLauncherMreProvider::VappLauncherMreProvider() :
    m_launcher(NULL)
{
    // Do nothing.
}


void VappLauncherMreProvider::onInit()
{
    VfxControl::onInit();

    setAnchor(0.5f, 0.5f);
}


void VappLauncherMreProvider::onDeinit()
{
    // Do nothing.

    VfxControl::onDeinit();
}


void VappLauncherMreProvider::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_FRAME_NOTIFY_ID_PARENT_FRAME_CHANGED:
        {
            VfxControl::onObjectNotify(id, userData);
            handleParentFrameChanged((VfxFrame *)userData);
            break;
        }
        default:
        {
            VfxControl::onObjectNotify(id, userData);
            break;
        }
    }
}


void VappLauncherMreProvider::setStatusBarHidden(VfxBool isHidden)
{
    VfxPage *page = getPage();

    if (page)
    {
        page->setStatusBar(isHidden ? VFX_FALSE : VFX_TRUE);
    }
}


VfxBool VappLauncherMreProvider::isRestoreState() const
{
    if (m_launcher.isValid())
    {
        return m_launcher->isRestoreStatus();
    }

    return VFX_FALSE;
}


VfxBool VappLauncherMreProvider::isHomeKeyPressed() const
{
    if (m_launcher.isValid())
    {
        return m_launcher->isProcessHomeKey();
    }

    return VFX_FALSE;
}


void VappLauncherMreProvider::createView()
{
    setFocused(VFX_TRUE);

    onCreateView();
}


void VappLauncherMreProvider::releaseView()
{
    onReleaseView();

    setFocused(VFX_FALSE);
}


void VappLauncherMreProvider::enter()
{
    onEnter();
}


void VappLauncherMreProvider::exit()
{
    onExit();
}


void VappLauncherMreProvider::serializeView()
{
    onSerializeView();
}


void VappLauncherMreProvider::restoreView()
{
    onRestoreView();
}


VfxBool VappLauncherMreProvider::notifyEvent(
    VappLauncherProviderEventStruct *event)
{
    return onEvent(event);
}


void VappLauncherMreProvider::onCreateView()
{
    // Do nothing.
}


void VappLauncherMreProvider::onReleaseView()
{
    // Do nothing.
}


void VappLauncherMreProvider::onEnter()
{
    // Do nothing.
}


void VappLauncherMreProvider::onExit()
{
    // Do nothing.
}


void VappLauncherMreProvider::onSerializeView()
{
    // Do nothing.
}


void VappLauncherMreProvider::onRestoreView()
{
    // Do nothing.
}


VfxBool VappLauncherMreProvider::onEvent(
    VappLauncherProviderEventStruct *event)
{
    return VFX_FALSE;
}


void VappLauncherMreProvider::handleParentFrameChanged(
    VfxFrame *origParentFrame)
{
    VappLauncherMre *parent;

    parent = VFX_OBJ_DYNAMIC_CAST(origParentFrame, VappLauncherMre);
    if (parent)
    {
        m_launcher = NULL;
        parent->setMreProvider(NULL);
    }

    parent = VFX_OBJ_DYNAMIC_CAST(getParentFrame(), VappLauncherMre);
    if (parent)
    {
        m_launcher = parent;
        parent->setMreProvider(this);
    }
}


VfxPage *VappLauncherMreProvider::getPage()
{
    for (VfxFrame *frame = getParentFrame();
         frame != NULL;
         frame = frame->getParentFrame())
    {
        VfxPage *page = VFX_OBJ_DYNAMIC_CAST(frame, VfxPage);

        if (page)
        {
            return page;
        }
    }

    return NULL;
}


/*****************************************************************************
 * MRE Launcher
 *****************************************************************************/

VAPP_LAUNCHER_IMPLEMENT_CLASS(VappLauncherMre, VappLauncher);


VappLauncherMre::VappLauncherMre() :
    m_mreId(),
    m_launcher(NULL),
    m_isSelfClose(VFX_FALSE),
    m_isAbnormalReset(VFX_FALSE),
    m_errorMask(),
    m_launcherProvider(NULL)
#if defined(__MMI_VUI_LAUNCHER_MRE_USE_ASM__)
    ,
    m_asmGid(GRP_ID_INVALID)
#endif /* defined(__MMI_VUI_LAUNCHER_MRE_USE_ASM__) */
{
    // Do nothing.
}


VappLauncherMre::~VappLauncherMre()
{
    // Do nothing.
}


void VappLauncherMre::onInit()
{
    VappLauncher::onInit();

    // Note that we add this MRE launcher to the manager after its view is
    // created for performance consideration. This is because sometimes, the
    // MRE launcher is created only to query its icon or name. In this case, no
    // need to add it to the manager.
    //
    // Please see onCreateView.
}


void VappLauncherMre::onDeinit()
{
    // Do nothing.

    VappLauncher::onDeinit();
}


VfxU8 VappLauncherMre::getDriveLetter() const
{
    return VappLauncherMreUtil::getDriveLetter(m_mreId);
}


void VappLauncherMre::setMreProvider(VappLauncherMreProvider *launcherProvider)
{
    if (!launcherProvider)
    {
        m_launcherProvider = NULL;
    }
    else
    {
        m_launcherProvider = launcherProvider;

        // Centralize the plug-in control.
        centralizeProvider();
    }
}


void VappLauncherMre::setId(const VappLauncherId &id)
{
    m_mreId = id;
}


VappLauncherId VappLauncherMre::getId() const
{
    return m_mreId;
}


VfxS32 VappLauncherMre::getName(VfxWChar *string, VfxS32 size) const
{
    WCHAR temp[MMI_APP_NAME_MAX_LEN + 1]; // 1: null terminated char
    mmi_ret ret;

    ret = srv_mre_appmgr_get_app_name(
            (mmi_app_package_char *)m_mreId.getStringType(),
            temp);

    if (ret != MMI_RET_OK)
    {
        string[0] = L'\0'; // If failed, set the name as empty string.
    }
    else
    {
        vfx_sys_wcsncpy(string, temp, size - 1);
    }

    return vfx_sys_wcslen(string);
}


VfxFrame *VappLauncherMre::createIcon(VfxObject *parentObj)
{
    //
    // Create icon.
    //
    VfxImageFrame *icon;
    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);

    //
    // Get icon resource.
    //
    mmi_image_src_struct imageSrc;
    mmi_ret ret;

    ret = srv_mre_appmgr_get_app_image(
            (mmi_app_package_char *)m_mreId.getStringType(),
            &imageSrc);


    if (ret != MMI_RET_OK)
    {
        return icon;
    }

    switch (imageSrc.type)
    {
        case MMI_IMAGE_SRC_TYPE_RES_ID:
            icon->setResId(imageSrc.data.res_id);
            break;

        case MMI_IMAGE_SRC_TYPE_PATH:
            icon->setPath(VFX_WSTR_MEM((const VfxWChar *)imageSrc.data.path));
            break;

        case MMI_IMAGE_SRC_TYPE_ROM_MEMORY:
            icon->setImgContent(
                VfxImageSrc(
                    imageSrc.data.image.image_ptr,
                    imageSrc.data.image.image_len));
            break;

        default:
            break;
    }

    return icon;
}


VfxS32 VappLauncherMre::getScreenshotNum() const
{
    return 1;
}


VfxFrame **VappLauncherMre::createScreenshot(VfxObject *parentObj) const
{
    //
    // New a screenshot array of size 1.
    //
    VfxFrame **screenshotArray;

    VFX_ALLOC_MEM(
        screenshotArray,
        getScreenshotNum() * sizeof(VfxFrame *),
        parentObj);

    //
    // Screenshot Object
    //
    VappLauncherMreScreenshot *screenshot;

    VFX_OBJ_CREATE(screenshot, VappLauncherMreScreenshot, parentObj);
    screenshot->show(m_mreId.getStringType(), getDriveLetter());

    screenshotArray[0] = screenshot; // Only 1 screenshot is supported.

    return screenshotArray;
}


VfxBool VappLauncherMre::checkAvailable(VfxWString &errorString)
{
    VappLauncherMreErrorMask errorMask;

    errorMask.syncSystemState(getDriveLetter());
    if (!errorMask.isAnyError())
    {
        return VFX_TRUE;
    }

    errorString = VFX_WSTR_RES(errorMask.getPrompt());

    return VFX_FALSE;
}


void VappLauncherMre::onCreateView()
{
    VappLauncher::onCreateView();

    //
    // Register to manager.
    //
    // Please see the 'onInit' function to understand why we add it to the
    // manager here.
    //
    VappLauncherMreManager *mgr = VFX_OBJ_GET_INSTANCE(VappLauncherMreManager);
    mgr->add(this);

    //
    // Memory.
    //
    universalInitMemory();

    //
    // Start VPI.
    //
    // If we fail to start the VPI, initialize a reviver to revive the MRE
    // launcher later when the following conditions are all meet.
    //
    // 1) MRE launcher is the default launcher after the mobile boots up.
    // 2) the error is recoverable.
    //
    VfxBool ret = startVpi();

    if (!ret)
    {
        if (isFirstInit() && m_errorMask.isRecoverable())
        {
            mgr->initReviver(m_mreId, m_errorMask);
        }
    }
}


VfxBool VappLauncherMre::getCreateViewFailure(VfxWString &errorString)
{
    if (!m_errorMask.isAnyError())
    {
        return VFX_FALSE;
    }

    errorString = VFX_WSTR_RES(m_errorMask.getPrompt());

    return VFX_TRUE;
}


void VappLauncherMre::onReleaseView()
{
    //
    // Shutdown VPI.
    //
    shutdownVpi();

    //
    // Memory.
    //
    universalDeinitMemory();

    //
    // Remove from the manager.
    //
    VappLauncherMreManager *mgr = VFX_OBJ_GET_INSTANCE(VappLauncherMreManager);
    mgr->remove(this);

    VappLauncher::onReleaseView();
}


void VappLauncherMre::onEnter()
{
    if (m_launcherProvider.isValid())
    {
        m_launcherProvider->enter();
    }
}


void VappLauncherMre::onEntered()
{
    if (m_launcherProvider.isValid())
    {
        VappLauncherProviderEventStruct event;
        event.id = VAPP_LAUNCHER_PROVIDER_EVENT_ENTERED;
        event.userData = NULL;
        event.size = 0;

        m_launcherProvider->notifyEvent(&event);
    }
}


void VappLauncherMre::onExit()
{
    if (m_launcherProvider.isValid())
    {
        m_launcherProvider->exit();
    }
}


void VappLauncherMre::onSerializeView(VfxArchive *ar)
{
    VappLauncher::onSerializeView(ar);

    if (m_launcherProvider.isValid())
    {
        m_launcherProvider->serializeView();
    }
}


void VappLauncherMre::onRestoreView(VfxArchive *ar)
{
    VappLauncher::onRestoreView(ar);

    // It's possible that ASM requests us to free the memory such that the MRE
    // launcher is released. Thus,
    //
    // Case 1) MRE launcher isn't released, notify it to restore the view.
    // Case 2) MRE launcher is released, re-start the VPI.

    if (m_launcherProvider.isValid())
    {
        m_launcherProvider->restoreView();
    }
    else
    {
        VfxBool ret = startVpi();

        if (!ret)
        {
            if (m_errorMask.isRecoverable())
            {
                VappLauncherMreManager *mgr;

                mgr = VFX_OBJ_GET_INSTANCE(VappLauncherMreManager);
                mgr->initReviver(m_mreId, m_errorMask);
            }

            abnormalReset();
        }
    }
}


void VappLauncherMre::onWallpaperChanged()
{
    VappLauncher::onWallpaperChanged();

    if (m_launcherProvider.isValid())
    {
        VappLauncherProviderEventStruct event;
        event.id = VAPP_LAUNCHER_PROVIDER_EVENT_WALLPAPER_CHANGED;
        event.userData = NULL;
        event.size = 0;

        m_launcherProvider->notifyEvent(&event);
    }
}


void VappLauncherMre::onNotificationCenterEnter()
{
    VappLauncher::onNotificationCenterEnter();

    if (m_launcherProvider.isValid())
    {
        VappLauncherProviderEventStruct event;
        event.id = VAPP_LAUNCHER_PROVIDER_EVENT_NOTIFICATION_ENTER;
        event.userData = NULL;
        event.size = 0;

        m_launcherProvider->notifyEvent(&event);
    }
}


void VappLauncherMre::onNotificationCenterExited()
{
    VappLauncher::onNotificationCenterExited();

    if (m_launcherProvider.isValid())
    {
        VappLauncherProviderEventStruct event;
        event.id = VAPP_LAUNCHER_PROVIDER_EVENT_NOTIFICATION_EXITED;
        event.userData = NULL;
        event.size = 0;

        m_launcherProvider->notifyEvent(&event);
    }
}


VfxBool VappLauncherMre::startVpi()
{
    VFX_ASSERT(!m_launcher);

    //
    // Check if there is any system errors such that we cannot load the widget.
    //
    m_errorMask.reset();
    m_errorMask.syncSystemState(getDriveLetter());

    if (m_errorMask.isAnyError())
    {
        return VFX_FALSE;
    }

    //
    // Get the VPP file path.
    //
    WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1]; // 1: null terminated char
    MMI_BOOL isPathGot;

    VAPP_LAUNCHER_SLA(("DL1", SA_start));

    isPathGot = srv_mre_appmgr_get_file_path(
                    (mmi_app_package_char *)m_mreId.getStringType(),
                    path);

    VAPP_LAUNCHER_SLA(("DL1", SA_stop));

    if (!isPathGot)
    {
        m_errorMask.set(VappLauncherMreErrorMask::FILE_NOT_FOUND);
        return VFX_FALSE;
    }

    //
    // Create VPI launcher.
    //
    VFX_ASSERT(!m_launcher);

    VFX_OBJ_CREATE_EX(
        m_launcher,
        VpiAppLauncher,
        this,
        (VFX_WSTR_MEM((const VfxWChar *)path)));

    //
    // Get preload APP info.
    //
    VappLauncherMreErrorMask::ErrorMask err;

    VAPP_LAUNCHER_SLA(("DL2", SA_start));

    err = preparePreloadAppInfo(
            m_launcher,
            path,
            m_preloadInfo);

    VAPP_LAUNCHER_SLA(("DL2", SA_stop));

    if (err != VappLauncherMreErrorMask::NULL_STATE)
    {
        VFX_OBJ_CLOSE(m_launcher);
        m_errorMask.set(err);
        return VFX_FALSE;
    }

    //
    // Launch the VPP with platform context as the memory source of the plug-in
    // objects.
    //
    VappLauncherHeap *heap = VFX_OBJ_GET_INSTANCE(VappLauncherHeap);

    VAPP_LAUNCHER_SLA(("DL3", SA_start));
    VfxBool isLaunched = m_launcher->launch(heap->get(), this, &m_preloadInfo);
    VAPP_LAUNCHER_SLA(("DL3", SA_stop));

    if (!isLaunched || !m_launcherProvider.isValid())
    {
        releasePreloadAppInfo(m_launcher, m_preloadInfo);
        VFX_OBJ_CLOSE(m_launcher);
        m_errorMask.set(VappLauncherMreErrorMask::VPI_FAIL);
        return VFX_FALSE;
    }

    //
    // Create view.
    //
    m_launcher->m_signalQuitByInterrupt.connect(this, &VappLauncherMre::onQuitByInterrupt);

    m_launcherProvider->m_signalBoundsChanged.connect(this, &VappLauncherMre::onProviderBoundsChange);

    VAPP_LAUNCHER_SLA(("DL4", SA_start));
    m_launcherProvider->createView();
    VAPP_LAUNCHER_SLA(("DL4", SA_stop));

    return VFX_TRUE;
}


void VappLauncherMre::shutdownVpi()
{
    if (m_launcherProvider.isValid())
    {
        m_launcherProvider->releaseView();
    }

    if (m_launcher)
    {
        m_launcher->terminate();

        //
        // PLEASE READ ME.
        //
        // If VPP wants to close itself, we need to free the memory pool gently
        // because MRE engine could still use this memory pool. In this case, we
        // listen to the 'destroy' signal to free the memory pool until MRE
        // engine has completely destroy this VPP.
        //
        if (m_isSelfClose)
        {
            m_launcher->m_signalDestroy.connect(this, &VappLauncherMre::onVppLauncherDestroy);
        }
        else
        {
            releasePreloadAppInfo(m_launcher, m_preloadInfo);
            VFX_OBJ_CLOSE(m_launcher);
        }
    }
}


void VappLauncherMre::abnormalReset()
{
    // To avoid from the complication, don't allow to send this signal twice.
    if (!m_isAbnormalReset)
    {
        shutdownVpi();

        m_signalAbnormalReset.postEmit(this);

        m_isAbnormalReset = VFX_TRUE;
    }
}


void VappLauncherMre::onVppLauncherDestroy(VfxObject *obj)
{
    VFX_ASSERT(m_launcher == obj);
    VFX_OBJ_ASSERT_VALID(obj);

    releasePreloadAppInfo(m_launcher, m_preloadInfo);
    VFX_OBJ_CLOSE(m_launcher);
}


void VappLauncherMre::onQuitByInterrupt(
    VfxObject *obj,
    VpiAppLauncher::QuitByInterrupTypeEnum cause)
{
    m_isSelfClose = VFX_TRUE;

    //
    // Init the reviver to revive the MRE launcher later.
    //
    VappLauncherMreErrorMask error;

    switch (cause)
    {
        case VpiAppLauncher::QUIT_TYPE_PLUG_IN_USB:
        {
            error.set(VappLauncherMreErrorMask::MASS_STORAGE);
            break;
        }
        case VpiAppLauncher::QUIT_TYPE_PLUG_OUT_T_CARD:
        {
            error.set(VappLauncherMreErrorMask::DRIVE_PLUG_OUT);
            break;
        }
        default:
        {
            error.set(VappLauncherMreErrorMask::FILE_NOT_FOUND);
            break;
        }
    }

    VappLauncherMreManager *mgr = VFX_OBJ_GET_INSTANCE(VappLauncherMreManager);
    mgr->initReviver(m_mreId, error);

    //
    // Request the launcher APP to reset itself.
    //
    abnormalReset();

    m_isSelfClose = VFX_FALSE;
}


VappLauncherMreErrorMask::ErrorMask VappLauncherMre::preparePreloadAppInfo(
    VpiAppLauncher *launcher,
    const WCHAR *path,
    vm_preload_app_info_t &info)
{
    //
    // Read memory requirement information from the VPP file.
    //
    if (!launcher->getPreloadInfo(info))
    {
        return VappLauncherMreErrorMask::VPI_FAIL;
    }

    //
    // Allocate memory for code and data.
    //
    if (info.loadSize > 0)
    {
        info.loadBufSize = info.loadSize;
        info.loadBase = universalMalloc(info.loadBufSize);

        if (!info.loadBase)
        {
            return VappLauncherMreErrorMask::OUT_OF_MEM;
        }
    }

    //
    // Allocate memory for heap.
    //
    if (info.heapSize > 0)
    {
        info.heapBufSize = info.heapSize;
        info.heapBase = universalMalloc(info.heapBufSize);

        if (!info.heapBase)
        {
            universalFree(info.loadBase);
            return VappLauncherMreErrorMask::OUT_OF_MEM;
        }
    }

    //
    // Preload the VPP
    //
    if (!launcher->preLoad(info))
    {
        universalFree(info.loadBase);
        universalFree(info.heapBase);
        return VappLauncherMreErrorMask::VPI_FAIL;
    }

    return VappLauncherMreErrorMask::NULL_STATE;
}


void VappLauncherMre::releasePreloadAppInfo(
    VpiAppLauncher *launcher,
    vm_preload_app_info_t &info)
{
    // Backup the load and heap base because the 'unload' function will reset
    // the preload app info structure.
    void *heapBase = info.heapBase;
    void *loadBase = info.loadBase;

    launcher->unload(info);

    if (heapBase)
    {
        universalFree(heapBase);
    }

    if (loadBase)
    {
        universalFree(loadBase);
    }
}


void VappLauncherMre::onProviderBoundsChange(
    VfxFrame *source,
    const VfxRect &oldBounds)
{
    // Make the launcher's size the same as the launcher provider. Need to
    // disable the auto. animation.
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    setSize(source->getBounds().size);

    VfxAutoAnimate::commit();

    // Centralize the launcher provider.
    centralizeProvider();
}


void VappLauncherMre::centralizeProvider()
{
    if (m_launcherProvider.isValid())
    {
        VfxSize size = getSize();
        m_launcherProvider->setPos(size.width / 2, size.height / 2);
    }
}


void VappLauncherMre::universalInitMemory()
{
#if defined(__MMI_VUI_LAUNCHER_MRE_USE_ASM__)
    initAsmMemory();
#endif
}


void VappLauncherMre::universalDeinitMemory()
{
#if defined(__MMI_VUI_LAUNCHER_MRE_USE_ASM__)
    deinitAsmMemory();
#endif
}


void *VappLauncherMre::universalMalloc(VfxU32 size)
{
#if defined(__MMI_VUI_LAUNCHER_MRE_USE_ASM__)
    return asmMalloc(size);
#else
    return globalMalloc(size);
#endif
}


void VappLauncherMre::universalFree(void *mem)
{
#if defined(__MMI_VUI_LAUNCHER_MRE_USE_ASM__)
    asmFree(mem);
#else
    globalFree(mem);
#endif
}


#if defined(__MMI_VUI_LAUNCHER_MRE_USE_ASM__)
void *VappLauncherMre::asmMalloc(VfxU32 size)
{
    VFX_ASSERT(m_asmGid != GRP_ID_INVALID);

    // Allow to return a NULL pointer if the memory pool is exhausted.

    return vadpAsmAlloc(m_asmGid, size);
}


void VappLauncherMre::asmFree(void *mem)
{
    VFX_ASSERT(m_asmGid != GRP_ID_INVALID);

    vadpAsmFree(m_asmGid, mem);
}


void VappLauncherMre::initAsmMemory()
{
    if (m_asmGid != GRP_ID_INVALID)
    {
        return; // already initialized.
    }

    VadpAsmProperty property;

    m_asmGid = mmi_frm_group_create(
                GRP_ID_ROOT,
                GRP_ID_VAPP_LAUNCHER_MRE_ASM,
                &onAsmGroupEvent,
                getObjHandle());

    VFX_ASSERT(m_asmGid != GRP_ID_INVALID);

    // Don't reserve the memory such that once OOM happens, we can release our
    // ASM pool and other APP can use these memory.
    //
    // And, hide this pool in OOM dialog since we always free it voluntarily.
    VadpAsm::getProperty(m_asmGid, property);
    property.f_prepare_w_reserve = 0;
    property.f_hide_in_oom       = 1;
    VadpAsm::setProperty(m_asmGid, property);
}


void VappLauncherMre::deinitAsmMemory()
{
    if (m_asmGid == GRP_ID_INVALID)
    {
        return; // already de-initialized.
    }

    mmi_frm_group_close(m_asmGid);
    m_asmGid = GRP_ID_INVALID;
}


void VappLauncherMre::handleAsmFreeReq()
{
    shutdownVpi();

    // Turn on the flag such that when MRE launcher is re-created later, it
    // knows it should restore the history.
    setIsRestoreStatus(VFX_TRUE);
}


mmi_ret VappLauncherMre::onAsmGroupEvent(mmi_event_struct *evt)
{
    VappLauncherMre *_this;

    _this = (VappLauncherMre *)handleToObject((VfxObjHandle)evt->user_data);
    VFX_OBJ_ASSERT_VALID(_this);

    mmi_ret ret = MMI_RET_OK;

    switch(evt->evt_id)
    {
        case EVT_ID_DELETE_DANGLE_GROUP_REQ:
        {
            // Keep dangle group.
            ret = MMI_RET_ERR;
            break;
        }
        case EVT_ID_ASM_FREE_REQ:           // volunteer free
        case EVT_ID_ASM_FREE_REQ_NO_WAIT:   // volunteer free
        case EVT_ID_ASM_FORCE_FREE:         // force free
        {
            _this->handleAsmFreeReq();
            ret = MMI_FRM_ASM_FREED;
            break;
        }
        default:
        {
            break;
        }
    }

    return ret;
}

#else /* defined(__MMI_VUI_LAUNCHER_MRE_USE_ASM__) */

const VfxU32 VappLauncherMre::m_size =
    ((VAPP_LAUNCHER_MRE_GLOBAL_SIZE + 3) & ~0x3);

VfxU32 VappLauncherMre::m_offset = 0;

#if defined(__MTK_TARGET__)
    #if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
        #pragma arm section zidata = "DYNAMICCACHEABLEZI_NC_MMIPOOL"
        __align(4) VfxU32 VappLauncherMre::m_pool[VappLauncherMre::m_size / 4];
        #pragma arm section zidata
    #else
        #pragma arm section zidata = "LARGEPOOL_ZI"
        __align(4) VfxU32 VappLauncherMre::m_pool[VappLauncherMre::m_size / 4];
        #pragma arm section zidata
    #endif /* defined(__DYNAMIC_SWITCH_CACHEABILITY__) */
#else
    VfxU32 VappLauncherMre::m_pool[VappLauncherMre::m_size / 4];
#endif /* defined(__MTK_TARGET__) */


void *VappLauncherMre::globalMalloc(VfxU32 size)
{
    if (size == 0)
    {
        return NULL;
    }

    size = align4Bytes(size);

    if (size > m_size - m_offset)
    {
        return NULL;
    }

    void *ret = (void *)((VfxU32)m_pool + m_offset);

    m_offset += size;

    return ret;
}


void VappLauncherMre::globalFree(void *mem)
{
    m_offset = 0;
}


VfxU32 VappLauncherMre::align4Bytes(VfxU32 val) const
{
    return ((val + 3) & ~0x3);
}
#endif /* defined(__MMI_VUI_LAUNCHER_MRE_USE_ASM__) */


/*****************************************************************************
 * MRE Launcher Manager
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherMreManager", VappLauncherMreManager, VfxObject);

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappLauncherMreManager);


VappLauncherMreManager::VappLauncherMreManager() :
    m_launcher(NULL),
    m_isWaitForRevive(VFX_FALSE),
    m_driveLetter(0xFF),
    m_launcherId(),
    m_fallbackLauncherId(),
    m_remainedError()
{
    // Do nothing.
}


VappLauncherMreManager::~VappLauncherMreManager()
{
    // Do nothing.
}


void VappLauncherMreManager::onInit()
{
    VfxObject::onInit();

    registerEvent();
}


void VappLauncherMreManager::onDeinit()
{
    deregisterEvent();

    VfxObject::onDeinit();
}


void VappLauncherMreManager::add(VappLauncherMre *launcher)
{
    VFX_ASSERT(!m_launcher.isValid());

    m_launcher = launcher;
}


void VappLauncherMreManager::remove(VappLauncherMre *launcher)
{
    if (m_launcher.isValid())
    {
        VFX_ASSERT(m_launcher == launcher);

        m_launcher = NULL;
    }
}


void VappLauncherMreManager::initReviver(
    const VappLauncherId &id,
    const VappLauncherMreErrorMask &error)
{
    if (!error.isAnyError() || !error.isRecoverable())
    {
        return; // No error or error cannot be fixed.
    }

    m_remainedError.set(error);

    if (m_isWaitForRevive)
    {
        return; // have already been initialized.
    }

    m_isWaitForRevive = VFX_TRUE;
    m_driveLetter = VappLauncherMreUtil::getDriveLetter(id);
    m_launcherId = id;

    VappLauncherSettingProvider *provider;

    provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);
    provider->m_signalDefaultLauncherChanged.connect(this, &VappLauncherMreManager::onLauncherChanged);
}


void VappLauncherMreManager::deinitReviver()
{
    if (!m_isWaitForRevive)
    {
        return; // have not been initialized.
    }

    VappLauncherSettingProvider *provider;

    provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);
    provider->m_signalDefaultLauncherChanged.disconnect(this, &VappLauncherMreManager::onLauncherChanged);

    m_isWaitForRevive = VFX_FALSE;
    m_driveLetter = 0xFF;
    m_launcherId.assignWith(VAPP_LAUNCHER_SRC_INVALID, 0);
    m_fallbackLauncherId.assignWith(VAPP_LAUNCHER_SRC_INVALID, 0);

    m_remainedError.reset();
}


void VappLauncherMreManager::invokeReviver()
{
    if (!m_isWaitForRevive)
    {
        return; // have not been initialized.
    }

    VappLauncherSettingProvider *provider;

    provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);
    provider->updateDefaultLauncher(m_launcherId);

    deinitReviver();
}


void VappLauncherMreManager::onLauncherChanged()
{
    if (!m_isWaitForRevive)
    {
        return; // have not been initialized.
    }

    if (m_fallbackLauncherId.getSource() == VAPP_LAUNCHER_SRC_INVALID)
    {
        VappLauncherSettingProvider *provider;

        provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);
        m_fallbackLauncherId = provider->getDefaultLauncher();
    }
    else
    {
        deinitReviver();
    }
}


void VappLauncherMreManager::handleUninstall(const VfxChar *appName)
{
    if (!m_launcher.isValid())
    {
        return; // No need to reset the current launcher.
    }

    if (vfx_sys_strcmp(m_launcher->getId().getStringType(), appName) == 0)
    {
        m_launcher->abnormalReset();
    }
}


void VappLauncherMreManager::handleDrivePlugIn(
    const VfxU8 *driveLetter,
    VfxU32 count)
{
    if (!m_isWaitForRevive)
    {
        return; // No need to invoke the reviver.
    }

    VfxBool isMatched = VappLauncherMreUtil::isDriveMatch(
                            m_driveLetter,
                            driveLetter,
                            count);

    if (isMatched)
    {
        m_remainedError.clear(VappLauncherMreErrorMask::DRIVE_PLUG_OUT);

        if (!m_remainedError.isAnyError())
        {
            invokeReviver();
        }
    }
}


void VappLauncherMreManager::handleDrivePlugOut(
    const VfxU8 *driveLetter,
    VfxU32 count)
{
    //
    // Reset the current MRE launcher if it's existed.
    //
    if (m_launcher.isValid())
    {
        VfxBool isMatched = VappLauncherMreUtil::isDriveMatch(
                                m_launcher->getId(),
                                driveLetter,
                                count);

        if (isMatched)
        {
            m_launcher->abnormalReset();
        }
    }

    //
    // Initialize the reviver if the current launcher is MRE launcher.
    //
    VappLauncherSettingProvider *provider;
    provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);

    VappLauncherId id = provider->getDefaultLauncher();

    if (id.getSource() == VAPP_LAUNCHER_SRC_MRE &&
        VappLauncherMreUtil::isDriveMatch(id, driveLetter, count))
    {
        initReviver(id, VappLauncherMreErrorMask::DRIVE_PLUG_OUT);
    }
}


void VappLauncherMreManager::handleDriveFormat(VfxU8 driveLetter)
{
    if (!m_launcher.isValid())
    {
        return; // No need to reset the current launcher.
    }

    VfxBool isMatched = VappLauncherMreUtil::isDriveMatch(
                            m_launcher->getDriveLetter(),
                            &driveLetter,
                            1);

    if (isMatched)
    {
        m_launcher->abnormalReset();
    }
}


void VappLauncherMreManager::handleMassStorageMode(VfxBool isEnter)
{
    if (isEnter)
    {
        // Reset the current MRE launcher if it's existed.
        if (m_launcher.isValid())
        {
            m_launcher->abnormalReset();
        }

        // Initialize the reviver if the current launcher is MRE launcher.
        VappLauncherSettingProvider *provider;
        provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);

        VappLauncherId id = provider->getDefaultLauncher();

        if (id.getSource() == VAPP_LAUNCHER_SRC_MRE)
        {
            initReviver(id, VappLauncherMreErrorMask::MASS_STORAGE);
        }
    }
    else
    {
        if (m_isWaitForRevive)
        {
            m_remainedError.clear(VappLauncherMreErrorMask::MASS_STORAGE);

            if (!m_remainedError.isAnyError())
            {
                invokeReviver();
            }
        }
    }
}


void VappLauncherMreManager::registerEvent()
{
    mmi_frm_cb_reg_event(
        EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE,
        VappLauncherMreManager::eventProc,
        getObjHandle());

    mmi_frm_cb_reg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN,
        VappLauncherMreManager::eventProc,
        getObjHandle());

    mmi_frm_cb_reg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,
        VappLauncherMreManager::eventProc,
        getObjHandle());

    mmi_frm_cb_reg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT,
        VappLauncherMreManager::eventProc,
        getObjHandle());

#if defined(__MMI_USB_SUPPORT__)
    mmi_frm_cb_reg_event(
        EVT_ID_USB_ENTER_MS_MODE,
        VappLauncherMreManager::eventProc,
        getObjHandle());

    mmi_frm_cb_reg_event(
        EVT_ID_USB_EXIT_MS_MODE,
        VappLauncherMreManager::eventProc,
        getObjHandle());
#endif /* defined(__MMI_USB_SUPPORT__) */
}


void VappLauncherMreManager::deregisterEvent()
{
    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE,
        VappLauncherMreManager::eventProc,
        getObjHandle());

    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN,
        VappLauncherMreManager::eventProc,
        getObjHandle());

    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,
        VappLauncherMreManager::eventProc,
        getObjHandle());

    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT,
        VappLauncherMreManager::eventProc,
        getObjHandle());

#if defined(__MMI_USB_SUPPORT__)
    mmi_frm_cb_dereg_event(
        EVT_ID_USB_ENTER_MS_MODE,
        VappLauncherMreManager::eventProc,
        getObjHandle());

    mmi_frm_cb_dereg_event(
        EVT_ID_USB_EXIT_MS_MODE,
        VappLauncherMreManager::eventProc,
        getObjHandle());
#endif /* defined(__MMI_USB_SUPPORT__) */
}


mmi_ret VappLauncherMreManager::eventProc(mmi_event_struct *evt)
{
    VappLauncherMreManager *mgr;

    mgr = (VappLauncherMreManager *)handleToObject(evt->user_data);

    VFX_OBJ_ASSERT_VALID(mgr);

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE:
        {
            srv_appmgr_update_event_struct *p;

            p = (srv_appmgr_update_event_struct *)evt;;

            mgr->handleUninstall(p->app_name);

            break;
        }
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        {
            srv_fmgr_notification_dev_plug_event_struct *p;

            p = (srv_fmgr_notification_dev_plug_event_struct *)evt;

            mgr->handleDrivePlugIn(p->drv_letters, p->count);

            break;
        }
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {
            srv_fmgr_notification_dev_plug_event_struct *p;

            p = (srv_fmgr_notification_dev_plug_event_struct *)evt;

            mgr->handleDrivePlugOut(p->drv_letters, p->count);

            break;
        }
        case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
        {
            srv_fmgr_notification_format_event_struct *p;

            p = (srv_fmgr_notification_format_event_struct *)evt;

            if (p->state == SRV_FMGR_NOTIFICATION_STATE_AFTER && p->result == 0)
            {
                mgr->handleDriveFormat(p->drv_letter);
            }

            break;
        }

#if defined(__MMI_USB_SUPPORT__)
        case EVT_ID_USB_ENTER_MS_MODE:
        {
            mgr->handleMassStorageMode(VFX_TRUE);
            break;
        }
        case EVT_ID_USB_EXIT_MS_MODE:
        {
            mgr->handleMassStorageMode(VFX_FALSE);
            break;
        }
#endif /* defined(__MMI_USB_SUPPORT__) */

        default:
        {
            break;
        }
    }

    return MMI_RET_OK;
}


#if defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__)

/*****************************************************************************
 * MRE Launcher Manager
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(
    "VappLauncherMreDltAppIconMgr",
    VappLauncherMreDltAppIconMgr,
    VfxObject);

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappLauncherMreDltAppIconMgr);


const VfxChar VappLauncherMreDltAppIconMgr::s_resId[] = "MRE.DLT_APP_ICON.0";

const VfxChar VappLauncherMreDltAppIconMgr::s_basePath[] = "AppIcon";

const VfxChar VappLauncherMreDltAppIconMgr::s_fileExt[] = "aco";

const VfxChar VappLauncherMreDltAppIconMgr::s_defaultName[] = "System Default";


VappLauncherMreDltAppIconMgr::VappLauncherMreDltAppIconMgr()
{
    // Do nothing.
}


VappLauncherMreDltAppIconMgr::~VappLauncherMreDltAppIconMgr()
{
    // Do nothing.
}


void VappLauncherMreDltAppIconMgr::onInit()
{
    VfxObject::onInit();

    VappLauncherSettingProvider *provider;

    provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);
    provider->m_signalDefaultLauncherChanged.connectFront(this, &VappLauncherMreDltAppIconMgr::onLauncherChangedFront);
}


void VappLauncherMreDltAppIconMgr::onDeinit()
{
    VappLauncherSettingProvider *provider;

    provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);
    provider->m_signalDefaultLauncherChanged.disconnect(this, &VappLauncherMreDltAppIconMgr::onLauncherChangedFront);

    VfxObject::onDeinit();
}


void VappLauncherMreDltAppIconMgr::onLauncherChangedFront()
{
    VappLauncherSettingProvider *provider;
    provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);

    VappLauncherId id = provider->getDefaultLauncher();

    VfxBool isSuccess = VFX_FALSE;

    if (id.getSource() == VAPP_LAUNCHER_SRC_MRE)
    {
        isSuccess = activate(id);
    }

    if (!isSuccess)
    {
        clear(); // Clear previous DLT app icon file if any.
    }
}


VfxBool VappLauncherMreDltAppIconMgr::activate(const VappLauncherId &id)
{
    //
    // Check if this is a MRE launcher.
    //
    if (id.getSource() != VAPP_LAUNCHER_SRC_MRE)
    {
        return VFX_FALSE;
    }

    //
    // File Path.
    //
    WCHAR vppPath[SRV_FMGR_PATH_MAX_LEN + 1]; // 1: null terminated char
    MMI_BOOL isPathGot;

    isPathGot = srv_mre_appmgr_get_file_path(
                    (mmi_app_package_char *)id.getStringType(),
                    vppPath);

    if (!isPathGot)
    {
        return VFX_FALSE;
    }

    //
    // Get DLT app icon binary hint from MRE resource.
    //
    vm_res_read_hint_struct hint;
    VMBOOL isResHintGot;

    isResHintGot = vm_load_resource_use_outside_memory(
                    (VMWSTR)vppPath,
                    (CHAR *)s_resId,
                    NULL,
                    0,
                    &hint);

    if (!isResHintGot || hint.res_offset < 0 || hint.res_size <= 0)
    {
        return VFX_FALSE;
    }

    //
    // Extract the DLT app icon to the T-card.
    //
    VfxBool isExtracted;
    VfxWString dltAppIconPath;

    isExtracted = extractFile(
                    vppPath,
                    hint.res_offset,
                    hint.res_size,
                    dltAppIconPath);

    if (!isExtracted)
    {
        return VFX_FALSE;
    }

    //
    // Update the app icon setting.
    //
    VfxBool isUpdated = updateSetting(dltAppIconPath);
    if (!isUpdated)
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


void VappLauncherMreDltAppIconMgr::clear()
{
    vfxPostInvoke0(this, &VappLauncherMreDltAppIconMgr::onPostClear);
}


void VappLauncherMreDltAppIconMgr::onPostClear()
{
    VfxWString iconPath;
    getIconPath(iconPath);

    srv_fmgr_fs_delete((const WCHAR *)iconPath.getBuf());
}


VfxBool VappLauncherMreDltAppIconMgr::extractFile(
    const WCHAR *vppPath,
    VfxU32 fileOffset,
    VfxU32 fileSize,
    VfxWString &iconPath)
{
    //
    // PLEASE REVISE THIS WORK-AROUND CODES.
    //
    // Our file system has limitation that when the USB mass storage mode
    // just exits, we can only read the file, but cannot write the file.
    //
    // This function could be executed when the USB mass storage mode exits
    // and we want to restore to the MRE launcher. Consequently, if we don't
    // let MMI task sleep a while here, we will fail to write the extracted
    // ACO file to the disk. This problem could happen especially on
    // platforms with low disk access rate.
    //
    // To resolve this problem, file system needs to modify lot of codes.
    // Our customer cannot wait for this solution. Therefore, we decide to
    // work-around it using kal_sleep_task here.
    //
    kal_sleep_task(3 * KAL_TICKS_100_MSEC);

    //
    // Create the output folder.
    //
    getIconPath(iconPath);

    VfxBool isFolderExisted = createFolder(iconPath);
    if (!isFolderExisted)
    {
        return VFX_FALSE;
    }

    //
    // Deactivate the current app icon before we extract the new one. For
    // example, consider that the current and new launchers are all downloadable
    // launcher with the embedded app icons. The current downloadable launcher
    // could open the "System Default.aco" file right now. Consequently, if we
    // do not deactivate it in advance, we will fail to save the new app icon.
    //
    VappThemeDltAppIconCntx *cntx = VFX_OBJ_GET_INSTANCE(VappThemeDltAppIconCntx);
    cntx->deactive();

    //
    // If the drive letter is '@', VPP is a preloaded VPP, stored in the ROM. .
    //
    if ((VfxU8)vppPath[0] == '@')
    {
        return extractFileFromRom(vppPath, fileOffset, fileSize, iconPath);
    }
    else
    {
        return extractFileFromDisk(vppPath, fileOffset, fileSize, iconPath);
    }
}


VfxBool VappLauncherMreDltAppIconMgr::extractFileFromDisk(
    const WCHAR *vppPath,
    const VfxU32 fileOffset,
    const VfxU32 fileSize,
    const VfxWString &iconPath)
{
    //
    // Prepare input file handle.
    //
    FS_HANDLE in;

    in = FS_Open(vppPath, FS_READ_ONLY);
    if (in < 0)
    {
        return VFX_FALSE;
    }

    if (FS_Seek(in, fileOffset, FS_FILE_BEGIN) < 0)
    {
        FS_Close(in);
        return VFX_FALSE;
    }

    //
    // Prepare output file handle.
    //
    FS_HANDLE out;

    out = FS_Open(iconPath, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (out < 0)
    {
        FS_Close(in);
        return VFX_FALSE;
    }

    //
    // Extract DLT application icon.
    //
    VfxBool isSuccess = VFX_TRUE;
    VfxU32 total = 0;
    VfxU8 *buf;

    VFX_SYS_ALLOC_MEM(buf, sizeof(VfxU8) * FS_BUF_SIZE);

    while (total < fileSize)
    {
        // Determine the available size that we can read.
        VfxU32 availableSize = fileSize - total;

        if (availableSize > FS_BUF_SIZE)
        {
            availableSize = FS_BUF_SIZE;
        }

        // Read / Write Data.
        VfxU32 readSize;

        VfxS32 readRet = FS_Read(in, buf, availableSize, &readSize);

        if (readRet < 0)
        {
            isSuccess = VFX_FALSE;
            break;
        }
        else
        {
            VfxU32 writeSize;

            VfxS32 writeRet = FS_Write(out, buf, readSize, &writeSize);
            if (writeRet < 0 || writeSize != readSize)
            {
                isSuccess = VFX_FALSE;
                break;
            }

            total += writeSize;
        }
    }

    VFX_SYS_FREE_MEM(buf);
    FS_Close(out);
    FS_Close(in);

    if (!isSuccess)
    {
        srv_fmgr_fs_delete((const WCHAR *)iconPath.getBuf());
    }

    return isSuccess;
}


VfxBool VappLauncherMreDltAppIconMgr::extractFileFromRom(
    const WCHAR *vppPath,
    const VfxU32 fileOffset,
    const VfxU32 fileSize,
    const VfxWString &iconPath)
{
    //
    // Prepare input file handle.
    //
    VMUINT8 *in = vm_get_execrom_ptr((VMWSTR)vppPath);
    if (!in)
    {
        return VFX_FALSE;
    }

    in += fileOffset;

    //
    // Prepare output file handle.
    //
    FS_HANDLE out;

    out = FS_Open(iconPath, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (out < 0)
    {
        return VFX_FALSE;
    }

    //
    // Extract DLT application icon.
    //
    VfxBool isSuccess = VFX_TRUE;
    VfxU32 writeSize;

    VfxS32 writeRet = FS_Write(out, in, fileSize, &writeSize);
    if (writeRet < 0 || writeSize != fileSize)
    {
        isSuccess = VFX_FALSE;
    }

    FS_Close(out);

    if (!isSuccess)
    {
        srv_fmgr_fs_delete((const WCHAR *)iconPath.getBuf());
    }

    return isSuccess;
}


VfxBool VappLauncherMreDltAppIconMgr::updateSetting(
    const VfxWString &iconPath)
{
    VappLauncherSettingProvider *provider;

    provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);

    VfxArchive *ar = provider->createArchiveWriter(
                                VappLauncherSettingProvider::SETTING_ID_APP_ICON,
                                VFX_SYS_GLOBAL_CONTEXT);

    if (!ar)
    {
        return VFX_FALSE;
    }

    // TODO: fixing me. DLT_THEME_TAG
	ar->writeU8(0x38);
	ar->writeWString(iconPath);

    VFX_OBJ_CLOSE(ar);

    return VFX_TRUE;
}


void VappLauncherMreDltAppIconMgr::getIconPath(VfxWString &iconPath)
{
    // Make sure the buffer size is large enough by calculating the size of
    // the variable part and adding 64 for the remained chars.
    VfxS32 varLen = vfx_sys_strlen(s_basePath) +
                    vfx_sys_strlen(s_defaultName) +
                    vfx_sys_strlen(s_fileExt);
    VfxS32 size = varLen + 64;

    WCHAR *buf;
    VFX_SYS_ALLOC_MEM(buf, sizeof(WCHAR) * size);

    // e.g., "E:\AppIcon\"
    kal_wsprintf(buf, "%c:\\%s\\", SRV_FMGR_CARD_DRV, s_basePath);
    iconPath  = VFX_WSTR_MEM(buf);

    // e.g., "E:\AppIcon\System Default"
    kal_wsprintf(buf, "%s", s_defaultName);
    iconPath += VFX_WSTR_MEM(buf);

    // e.g., "E:\AppIcon\System Default.aco"
    kal_wsprintf(buf, ".%s", s_fileExt);
    iconPath += VFX_WSTR_MEM(buf);

    VFX_SYS_FREE_MEM(buf);
}


VfxBool VappLauncherMreDltAppIconMgr::createFolder(
    const VfxWString &path)
{
    VfxWString clone = path;    // Clone the string to modify it.

    WCHAR *folderPath = srv_fmgr_path_remove_filename((WCHAR *)clone.getBuf());

    if (srv_fmgr_fs_path_exist(folderPath) == 0) // 0: existed
    {
        return VFX_TRUE;
    }

    return srv_fmgr_fs_create_folder(folderPath) >= 0 ? VFX_TRUE : VFX_FALSE;
}


void vapp_launcher_mre_activate_dlt_app_icon_mgr()
{
    //
    // Create global DLT app icon manager.
    //
    VFX_OBJ_GET_INSTANCE(VappLauncherMreDltAppIconMgr);
}

#endif /* defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__) */

#endif /* defined(__MMI_VUI_LAUNCHER_MRE__) */

