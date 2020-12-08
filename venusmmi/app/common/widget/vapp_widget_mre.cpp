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
 *  vapp_widget_mre.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the MRE widget.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_MRE__)

/*****************************************************************************
 * Configuration
 *****************************************************************************/

// This option turns on the unit test codes for interrupt handling.
//#define CFG_MRE_WIDGET_UNIT_TEST_INTERRUPT

// This option turns on the unit test codes for preload app.
//#define CFG_MRE_WIDGET_PRELOAD_UNIT_TEST


/*****************************************************************************
 * Include
 *****************************************************************************/

#include <ctype.h>

extern "C"
{
#include "MMIDataType.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "MREAppMgrSrvGprot.h"
#include "FileMgrSrvGprot.h"
#include "USBSrvGProt.h"
#include "mmi_rp_vapp_widget_mre_def.h"
}

#include "vfx_uc_include.h"
#include "vadp_asm.h"
#include "vpi_app_launcher.h"
#include "vapp_widget_kit.h"
#include "vapp_widget.h"
#include "vapp_widget_mre.h"

#if defined(CFG_MRE_WIDGET_UNIT_TEST_INTERRUPT)
#include "MMI_include.h"
#endif


/*****************************************************************************
 * MRE Widget Placard
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappWidgetMrePlacard", VappWidgetMrePlacard, VfxFrame);

const VfxFloat VappWidgetMrePlacard::s_iconSizeRatio = 0.75f;


VappWidgetMrePlacard::VappWidgetMrePlacard() :
    m_textFrame(NULL),
    m_icon(NULL)
{
    // Do nothing.
}


void VappWidgetMrePlacard::onInit()
{
    VfxFrame::onInit();

    VfxSize size = getParentFrame()->getSize(); // Parent's size.

    setSize(size);

    //
    // Background
    //
    setImgContent(VfxImageSrc(IMG_ID_VAPP_WIDGET_MRE_NOT_AVAILABLE_BG));
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
}


void VappWidgetMrePlacard::onDeinit()
{
    // Do nothing.

    VfxFrame::onDeinit();
}


void VappWidgetMrePlacard::setText(const VfxWString &string)
{
    //
    // Empty string. Close the text and directly return.
    //
    if (!string.getBuf() || !string.getLength())
    {
        VFX_OBJ_CLOSE(m_textFrame);
        return;
    }

    //
    // Lazy creation of the text.
    //
    if (!m_textFrame)
    {
        VfxSize size = getSize();

        VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);
        m_textFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(FONT_SIZE)));
        m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_textFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
        m_textFrame->setMargins(MARGIN, MARGIN_TOP, MARGIN, 0);
        m_textFrame->setAutoResized(VFX_FALSE);
        m_textFrame->setSize(size);
    }

    m_textFrame->setString(string);
}


void VappWidgetMrePlacard::setIcon(VfxResId imageId)
{
    //
    // NULL image ID. Close the icon and directly return.
    //
    if (imageId == VFX_RES_ID_NULL)
    {
        VFX_OBJ_CLOSE(m_icon);
        return;
    }

    //
    // Lazy creation of the icon.
    //
    if (!m_icon)
    {
        VfxSize size = getSize();

        VFX_OBJ_CREATE(m_icon, VfxImageFrame, this);
        m_icon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_icon->setAnchor(VfxFPoint(0.5f, 0.5f));
        m_icon->setPos(size.width / 2, size.height / 2);
    }

    m_icon->setResId(imageId);

    VfxSize originalSize = m_icon->getSize();
    VfxSize modifiedSize = originalSize;

    //
    // Make sure the icon size isn't too big.
    //
    VfxSize maxSize = getSize();

    maxSize.width = (VfxS32)(maxSize.width * s_iconSizeRatio + 0.5f);
    maxSize.height = (VfxS32)(maxSize.height * s_iconSizeRatio + 0.5f);

    if (modifiedSize.width > maxSize.width)
    {
        modifiedSize.width = maxSize.width;
    }

    if (modifiedSize.height > maxSize.height)
    {
        modifiedSize.height = maxSize.height;
    }

    //
    // Make sure the aspect ratio isn't changed.
    //
    VfxFloat sx = (VfxFloat)modifiedSize.width / originalSize.width;
    VfxFloat sy = (VfxFloat)modifiedSize.height / originalSize.height;
    VfxFloat resizeRatio = (sx < sy ? sx : sy);

    modifiedSize.width = (VfxS32)(originalSize.width * resizeRatio + 0.5f);
    modifiedSize.height = (VfxS32)(originalSize.height * resizeRatio + 0.5f);

    m_icon->setSize(modifiedSize);
}


/*****************************************************************************
 * MRE Widget Provider
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappWidgetMreProvider", VappWidgetMreProvider, VfxControl);


#define VAPP_WIDGET_MRE_ERR_NULL                    (0)
#define VAPP_WIDGET_MRE_ERR_FILE_NOT_FOUND          (0x01 << 0)
#define VAPP_WIDGET_MRE_ERR_VPI_FAIL                (0x01 << 1)
#define VAPP_WIDGET_MRE_ERR_MASS_STORAGE            (0x01 << 2)
#define VAPP_WIDGET_MRE_ERR_DRIVE_PLUG_OUT          (0x01 << 3)
#define VAPP_WIDGET_MRE_ERR_OUT_OF_MEM              (0x01 << 4)


VappWidgetMreProvider::VappWidgetMreProvider() :
    m_widget(NULL)
{
    // Do nothing.
}


void VappWidgetMreProvider::onInit()
{
    VfxControl::onInit();

    setAnchor(0.5f, 0.5f);
}


void VappWidgetMreProvider::onDeinit()
{
    // Do nothing.

    VfxControl::onDeinit();
}


void VappWidgetMreProvider::onObjectNotify(VfxId id, void *userData)
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


void VappWidgetMreProvider::createView()
{
    onCreateView();
}


void VappWidgetMreProvider::releaseView()
{
    onReleaseView();
}


void VappWidgetMreProvider::serializeView()
{
    onSerializeView();
}


void VappWidgetMreProvider::restoreView()
{
    onRestoreView();
}


VfxPoint VappWidgetMreProvider::getDeleteButtonOffset() const
{
    return onGetDeleteButtonOffset();
}


void VappWidgetMreProvider::onCreateView()
{
    // Do nothing.
}


void VappWidgetMreProvider::onReleaseView()
{
    // Do nothing.
}


void VappWidgetMreProvider::onSerializeView()
{
    // Do nothing.
}


void VappWidgetMreProvider::onRestoreView()
{
    // Do nothing.
}


VfxPoint VappWidgetMreProvider::onGetDeleteButtonOffset() const
{
    return VfxPoint(
            getSize().width - EDIT_BUTTON_OFFSET_X,
            EDIT_BUTTON_OFFSET_Y);
}


void VappWidgetMreProvider::handleParentFrameChanged(VfxFrame *origParentFrame)
{
    VappWidgetMre *parent;

    parent = VFX_OBJ_DYNAMIC_CAST(origParentFrame, VappWidgetMre);
    if (parent)
    {
        m_widget = NULL;
        parent->setMreProvider(NULL);
    }

    parent = VFX_OBJ_DYNAMIC_CAST(getParentFrame(), VappWidgetMre);
    if (parent)
    {
        m_widget = parent;
        parent->setMreProvider(this);
    }
}


/*****************************************************************************
 * MRE Widget
 *****************************************************************************/

VAPP_WIDGET_IMPLEMENT_CLASS(VappWidgetMre, VappWidget);


VappWidgetMre::VappWidgetMre() :
    m_mreId(),
    m_launcher(NULL),
    m_createViewFailurePrompt(VFX_RES_ID_NULL),
    m_isSelfClose(VFX_FALSE),
    m_widgetProvider(NULL),
    m_placard(NULL),
    m_placardErrorMask(VAPP_WIDGET_MRE_ERR_NULL),
    m_errorMask(VAPP_WIDGET_MRE_ERR_NULL)
{
    // Do nothing.
}


VappWidgetMre::~VappWidgetMre()
{
    // Do nothing.
}


void VappWidgetMre::onInit()
{
    VappWidget::onInit();

    // Note that we add this MRE widget to the manager after its view is
    // created for performance consideration. This is because sometimes, the
    // MRE widget is created only to query its icon or name. In this case, no
    // need to add it to the manager.
    //
    // Please see onCreateView.
}


void VappWidgetMre::onDeinit()
{
    // Fail-safe. Always try to remove it from the manager when it's closed.
    VappWidgetMreManager::remove(this);

    VappWidget::onDeinit();
}


VfxU8 VappWidgetMre::getDriveLetter() const
{
    WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1]; // 1: null terminated char
    MMI_BOOL ret;

    ret = srv_mre_appmgr_get_file_path(
            (mmi_app_package_char *)m_mreId.getStringType(),
            path);

    if (!ret)
    {
        return 0xFF; // Non-ASCII code, representing an invalid drive letter.
    }

    return (VfxU8)path[0];
}


void VappWidgetMre::setMreProvider(VappWidgetMreProvider *widgetProvider)
{
    if (!widgetProvider)
    {
        m_widgetProvider = NULL;
    }
    else
    {
        m_widgetProvider = widgetProvider;

        // Centralize the plug-in control.
        centralizeProvider();
    }
}


void VappWidgetMre::setId(const VappWidgetId &id)
{
    m_mreId = id;
}


VappWidgetId VappWidgetMre::getId() const
{
    return m_mreId;
}


VfxS32 VappWidgetMre::getName(VfxWChar *string, VfxS32 size) const
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


VfxSize VappWidgetMre::getMaxSize() const
{
    return getSize();
}


VfxFrame *VappWidgetMre::createIcon(VfxObject *parentObj)
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
            icon->setImgContent(VfxImageSrc(imageSrc.data.image.image_ptr, imageSrc.data.image.image_len));
            break;

        default:
            break;
    }

    return icon;
}


VfxPoint VappWidgetMre::onGetEditButtonOffset()
{
    if (m_widgetProvider.isValid())
    {
        return m_widgetProvider->getDeleteButtonOffset();
    }

    return VfxPoint(
            getSize().width - EDIT_BUTTON_OFFSET_X,
            EDIT_BUTTON_OFFSET_Y);
}


void VappWidgetMre::onCreateView()
{
    VappWidget::onCreateView();

    // Please see the 'onInit' function to understand why we add it to the
    // manager here.
    VappWidgetMreManager::add(this);

    VappWidgetMreManager *mgr = VappWidgetMreManager::getInstance();

    //
    // Get the properties of this widget.
    //
    VfxSize size;

    VfxBool isPropertyGot = mgr->getProperty(m_mreId, size);
    if (isPropertyGot)
    {
        setSize(size);
    }

    //
    // Start the VPI. If failed
    //
    VfxBool isVpiCreated = startVpi();

    if (isVpiCreated)
    {
        if (getSize() != size)
        {
            mgr->setProperty(m_mreId, getSize());
        }
    }
    else
    {
        if (isPropertyGot && isErrorRecoverable(m_errorMask))
        {
            // Do nothing because widget can be recovered automatically.
            //
            // Because the size is read from the manager, it is still ok for the
            // widget to display the error placard with proper size.
        }
        else
        {
            ErrorMask dummyMask;
            VfxResId dummyId, strId;

            getNextErrorPromptInfo(m_errorMask, dummyMask, dummyId, strId);

            // VPI isn't created and size is unknown. Cannot be displayed.
            m_createViewFailurePrompt = strId;

            clear();
        }
    }
}


VfxBool VappWidgetMre::getCreateViewFailure(VfxWString &errorString)
{
    if (m_createViewFailurePrompt == VFX_RES_ID_NULL)
    {
        return VFX_FALSE;
    }

    errorString = VFX_WSTR_RES(m_createViewFailurePrompt);

    return VFX_TRUE;
}


void VappWidgetMre::onReleaseView()
{
    clear();

    VappWidget::onReleaseView();
}


void VappWidgetMre::onSerializeView(VfxArchive *ar)
{
    VappWidget::onSerializeView(ar);

    if (m_widgetProvider.isValid())
    {
        m_widgetProvider->serializeView();
    }
}


void VappWidgetMre::onRestoreView(VfxArchive *ar)
{
    VappWidget::onRestoreView(ar);

    // It's possible that ASM requests us to free the memory such that the MRE
    // widget is released. Thus,
    //
    // Case 1) MRE widget isn't released, notify it to restore the view.
    // Case 2) MRE widget is released, schedule to re-start the VPI.

    if (m_widgetProvider.isValid())
    {
        m_widgetProvider->restoreView();
    }
    else
    {
        VappWidgetMreManager *mgr = VappWidgetMreManager::getInstance();
        mgr->submitJob(VfxCallback0(this, &VappWidgetMre::onDelayStartVpi));
    }
}


VfxBool VappWidgetMre::startVpi()
{
    clear();

    //
    // Check if there is any system errors such that we cannot load the widget.
    //
    syncSystemState();

    if (getAnyError(m_errorMask))
    {
        createPlacard();
        return VFX_FALSE;
    }

    //
    // Get the VPP file path.
    //
    WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1]; // 1: null terminated char
    MMI_BOOL isGetPath;

    isGetPath = srv_mre_appmgr_get_file_path(
                    (mmi_app_package_char *)m_mreId.getStringType(),
                    path);

    if (!isGetPath)
    {
        setErrorMask(m_errorMask, VAPP_WIDGET_MRE_ERR_FILE_NOT_FOUND);
        createPlacard();
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
    ErrorMask errorMask = preparePreloadAppInfo(
                            m_launcher,
                            path,
                            m_preloadInfo);

    if (errorMask != VAPP_WIDGET_MRE_ERR_NULL)
    {
        VFX_OBJ_CLOSE(m_launcher);
        setErrorMask(m_errorMask, errorMask);
        createPlacard();
        return VFX_FALSE;
    }

    //
    // Launch the VPP.
    //
    if (!m_launcher->launch(this, &m_preloadInfo) ||
        !m_widgetProvider.isValid())
    {
        releasePreloadAppInfo(m_launcher, m_preloadInfo);
        VFX_OBJ_CLOSE(m_launcher);
        setErrorMask(m_errorMask, VAPP_WIDGET_MRE_ERR_VPI_FAIL);
        createPlacard();
        return VFX_FALSE;
    }

    //
    // Create view.
    //
    m_launcher->m_signalQuitByInterrupt.connect(this, &VappWidgetMre::onQuitByInterrupt);

    m_widgetProvider->m_signalBoundsChanged.connect(this, &VappWidgetMre::onProviderBoundsChange);
    m_widgetProvider->createView();

    return VFX_TRUE;
}


void VappWidgetMre::shutdownVpi()
{
    //
    // Cancel the job for the fail-safe purpose.
    //
    VappWidgetMreManager *mgr = VappWidgetMreManager::getInstance();
    if (mgr)
    {
        mgr->cancelJob(VfxCallback0(this, &VappWidgetMre::onDelayStartVpi));
    }

    //
    // Release view.
    //
    if (m_widgetProvider.isValid())
    {
        m_widgetProvider->releaseView();
    }

    //
    // Close the VPP launcher.
    //
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
            m_launcher->m_signalDestroy.connect(this, &VappWidgetMre::onDestroy);
        }
        else
        {
            releasePreloadAppInfo(m_launcher, m_preloadInfo);
            VFX_OBJ_CLOSE(m_launcher);
        }
    }
}


void VappWidgetMre::onDestroy(VfxObject *obj)
{
    VFX_ASSERT(m_launcher == obj);
    VFX_OBJ_ASSERT_VALID(obj);

    releasePreloadAppInfo(m_launcher, m_preloadInfo);
    VFX_OBJ_CLOSE(m_launcher);
}


void VappWidgetMre::clear()
{
    shutdownVpi();

    closePlacard();
}


void VappWidgetMre::onQuitByInterrupt(
    VfxObject *obj,
    VpiAppLauncher::QuitByInterrupTypeEnum cause)
{
    m_isSelfClose = VFX_TRUE;

    switch (cause)
    {
        case VpiAppLauncher::QUIT_TYPE_PLUG_IN_USB:
        {
            notifyError(VAPP_WIDGET_MRE_ERR_MASS_STORAGE);
            break;
        }
        case VpiAppLauncher::QUIT_TYPE_PLUG_OUT_T_CARD:
        {
            notifyError(VAPP_WIDGET_MRE_ERR_DRIVE_PLUG_OUT);
            break;
        }
        default:
        {
            notifyError(VAPP_WIDGET_MRE_ERR_FILE_NOT_FOUND);
            break;
        }
    }

    m_isSelfClose = VFX_FALSE;
}


VappWidgetMre::ErrorMask VappWidgetMre::preparePreloadAppInfo(
    VpiAppLauncher *launcher,
    const WCHAR *path,
    vm_preload_app_info_t &info)
{
    VappWidgetMreManager *mgr = VappWidgetMreManager::getInstance();

	//
	// Read memory requirement information from the VPP file.
	//
	if (!launcher->getPreloadInfo(info))
    {
		return VAPP_WIDGET_MRE_ERR_VPI_FAIL;
	}

	//
	// Allocate memory for code and data.
	//
    if (info.loadSize > 0)
    {
        info.loadBufSize = info.loadSize;
        info.loadBase = mgr->malloc(info.loadBufSize);

        if (!info.loadBase)
        {
            return VAPP_WIDGET_MRE_ERR_OUT_OF_MEM;
        }
    }

    //
    // Allocate memory for heap.
    //
    if (info.heapSize > 0)
    {
        info.heapBufSize = info.heapSize;
        info.heapBase = mgr->malloc(info.heapBufSize);

        if (!info.heapBase)
        {
            mgr->free(info.loadBase);
            return VAPP_WIDGET_MRE_ERR_OUT_OF_MEM;
        }
    }

    //
    // Preload the VPP
    //
    if (!launcher->preLoad(info))
    {
        mgr->free(info.loadBase);
        mgr->free(info.heapBase);
        return VAPP_WIDGET_MRE_ERR_VPI_FAIL;
    }

    return VAPP_WIDGET_MRE_ERR_NULL;
}


void VappWidgetMre::releasePreloadAppInfo(
    VpiAppLauncher *launcher,
    vm_preload_app_info_t &info)
{
    // Backup the load and heap base because the 'unload' function will reset
    // the preload app info structure.
    void *heapBase = info.heapBase;
    void *loadBase = info.loadBase;

    launcher->unload(info);

    VappWidgetMreManager *mgr = VappWidgetMreManager::getInstance();

    if (heapBase)
    {
        mgr->free(heapBase);
    }

    if (loadBase)
    {
        mgr->free(loadBase);
    }
}


void VappWidgetMre::onProviderBoundsChange(
    VfxFrame *source,
    const VfxRect &oldBounds)
{
    // Make the widget's size the same as the widget provider. Need to disable
    // the auto. animation.
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    setSize(source->getBounds().size);

    VfxAutoAnimate::commit();

    // Centralize the widget provider.
    centralizeProvider();
}


void VappWidgetMre::notifyError(ErrorMask value)
{
    VfxBool hasErrorAlready = getAnyError(m_errorMask);

    setErrorMask(m_errorMask, value);

    if (isCreated())
    {
        // If no error before, create the error placard. Otherwise, keep the
        // current error placard.
        if (!hasErrorAlready)
        {
            createPlacard();
        }
    }
}


void VappWidgetMre::fixingError(ErrorMask value)
{
    VfxBool isErrorFixed = hasError(m_placardErrorMask, value);

    clearErrorMask(m_errorMask, value);

    if (isCreated())
    {
        if (getAnyError(m_errorMask))
        {
            // If the old error is fixed, refresh the error placard. Otherwise,
            // keep the current error placard.
            if (isErrorFixed)
            {
                createPlacard();
            }
        }
        else
        {
            // No error. Schedule to restart the VPI.
            VappWidgetMreManager *mgr = VappWidgetMreManager::getInstance();
            mgr->submitJob(VfxCallback0(this, &VappWidgetMre::onDelayStartVpi));
        }
    }
}


void VappWidgetMre::onDelayStartVpi()
{
    startVpi();
}


void VappWidgetMre::centralizeProvider()
{
    if (m_widgetProvider.isValid())
    {
        VfxSize size = getSize();
        m_widgetProvider->setPos(size.width / 2, size.height / 2);
    }
}


void VappWidgetMre::syncSystemState()
{
    VfxU8 driveLetter = getDriveLetter();

    //
    // If the drive letter is '@', VPP is a preloaded VPP, stored in the ROM. In
    // this case, we don't need to check USB mass storage mode or T-card state.
    //
    if (driveLetter == '@')
    {
        return;
    }

#if defined(__MMI_USB_SUPPORT__)
    if (srv_usb_is_in_mass_storage_mode_ext())
    {
        setErrorMask(m_errorMask, VAPP_WIDGET_MRE_ERR_MASS_STORAGE);
    }
    else
#endif /* defined(__MMI_USB_SUPPORT__) */
    if (!srv_fmgr_drv_is_accessible(driveLetter))
    {
        setErrorMask(m_errorMask, VAPP_WIDGET_MRE_ERR_DRIVE_PLUG_OUT);
    }
}


void VappWidgetMre::createPlacard()
{
    clear();

    VFX_OBJ_CREATE(m_placard, VappWidgetMrePlacard, this);
    m_placard->setAnchor(0.5f, 0.5f);
    m_placard->setPos(getSize().width / 2, getSize().height / 2);
    m_placard->setSize(getSize());

    //
    // Decide the icon and text to be shown on the placard.
    //
    VfxResId iconId;
    VfxResId strId;

    getNextErrorPromptInfo(m_errorMask, m_placardErrorMask, iconId, strId);

    m_placard->setIcon(iconId);
}


void VappWidgetMre::closePlacard()
{
    m_placardErrorMask = VAPP_WIDGET_MRE_ERR_NULL;
    VFX_OBJ_CLOSE(m_placard);
}


void VappWidgetMre::getNextErrorPromptInfo(
    ErrorMask inValue,
    ErrorMask &outValue,
    VfxResId &imgId,
    VfxResId &strId) const
{
    outValue = VAPP_WIDGET_MRE_ERR_NULL;
    imgId = VFX_RES_ID_NULL;
    strId = VFX_RES_ID_NULL;

    if (hasError(inValue, VAPP_WIDGET_MRE_ERR_DRIVE_PLUG_OUT))
    {
        setErrorMask(outValue, VAPP_WIDGET_MRE_ERR_DRIVE_PLUG_OUT);
        imgId = IMG_ID_VAPP_WIDGET_MRE_MEMORY_CARD_PLUG_OUT;
        strId = STR_GLOBAL_FILE_NOT_FOUND;
    }
    else if (hasError(inValue, VAPP_WIDGET_MRE_ERR_MASS_STORAGE))
    {
        setErrorMask(outValue, VAPP_WIDGET_MRE_ERR_MASS_STORAGE);
        imgId = IMG_ID_VAPP_WIDGET_MRE_USB_MASS_STORAGE_MODE;
        strId = STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE;
    }
    else if (hasError(inValue, VAPP_WIDGET_MRE_ERR_FILE_NOT_FOUND))
    {
        setErrorMask(outValue, VAPP_WIDGET_MRE_ERR_FILE_NOT_FOUND);
        imgId = IMG_ID_VAPP_WIDGET_MRE_UNKNOWN_ERROR;
        strId = STR_GLOBAL_FILE_NOT_FOUND;
    }
    else if (hasError(inValue, VAPP_WIDGET_MRE_ERR_OUT_OF_MEM))
    {
        setErrorMask(outValue, VAPP_WIDGET_MRE_ERR_OUT_OF_MEM);
        imgId = IMG_ID_VAPP_WIDGET_MRE_UNKNOWN_ERROR;
        strId = STR_ID_VAPP_WIDGET_MRE_REMOVE_SOME_WIDGETS_FIRST;
    }
    else if (hasError(inValue, VAPP_WIDGET_MRE_ERR_VPI_FAIL))
    {
        setErrorMask(outValue, VAPP_WIDGET_MRE_ERR_VPI_FAIL);
        imgId = IMG_ID_VAPP_WIDGET_MRE_UNKNOWN_ERROR;
        strId = STR_ID_VAPP_WIDGET_MRE_CANNOT_LOAD_WIDGET;
    }
}


VfxBool VappWidgetMre::isErrorRecoverable(ErrorMask mask) const
{
    if (hasError(mask, VAPP_WIDGET_MRE_ERR_FILE_NOT_FOUND) ||
        hasError(mask, VAPP_WIDGET_MRE_ERR_VPI_FAIL) ||
        hasError(mask, VAPP_WIDGET_MRE_ERR_OUT_OF_MEM))
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


void VappWidgetMre::setErrorMask(ErrorMask &mask, ErrorMask value) const
{
    mask |= value;
}


void VappWidgetMre::clearErrorMask(ErrorMask &mask, ErrorMask value) const
{
    mask &= ~value;
}


VfxBool VappWidgetMre::hasError(ErrorMask mask, ErrorMask value) const
{
    return ((mask & value) == value) ? VFX_TRUE : VFX_FALSE;
}


VfxBool VappWidgetMre::getAnyError(ErrorMask mask) const
{
    return mask != 0 ? VFX_TRUE : VFX_FALSE;
}


/*****************************************************************************
 * MRE Widget Manager
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappWidgetMreManager", VappWidgetMreManager, VfxObject);


VappWidgetMreManager *VappWidgetMreManager::s_mgr = NULL;


VappWidgetMreManager::VappWidgetMreManager() :
    m_timer(NULL),
    m_jobList(),
    m_widgetList(),
    m_asmGid(GRP_ID_INVALID),
    isPropertyInit(VFX_FALSE)
{
    for (VfxS32 i = 0; i < WIDGET_NUM; i++)
    {
        m_property[i].isUsed = VFX_FALSE;
    }
}


VappWidgetMreManager::~VappWidgetMreManager()
{
    // Do nothing.
}


void VappWidgetMreManager::onInit()
{
    VfxObject::onInit();

    initProperty();

    initMemory();

    registerEvent();
}


void VappWidgetMreManager::onDeinit()
{
    deregisterEvent();

    deinitMemory();

    VfxObject::onDeinit();
}


VappWidgetMreManager *VappWidgetMreManager::getInstance()
{
    VFX_ASSERT(s_mgr);

    return s_mgr;
}


void VappWidgetMreManager::add(VappWidgetMre *widget)
{
    //
    // Smart creation of the manager.
    //
    // TODO: please find a dedicated memory pool for the manager.
    //
    if (!s_mgr)
    {
        VFX_OBJ_CREATE(s_mgr, VappWidgetMreManager, widget->getParent());
    }

    if (!s_mgr->m_widgetList.contains(widget))
    {
        s_mgr->m_widgetList.append(widget);
    }
}


void VappWidgetMreManager::remove(VappWidgetMre *widget)
{
    if (!s_mgr)
    {
        return;
    }

    s_mgr->m_widgetList.removeOne(widget);

    //
    // Smart close of the manager.
    //
    if (s_mgr->m_widgetList.getEntryCount() == 0)
    {
        VFX_OBJ_CLOSE(s_mgr);
    }
}


void VappWidgetMreManager::submitJob(const VfxCallback0 &callback)
{
    //
    // CASE 1: the timer is running.
    //  It means a callback is invoked in recent TIMER_DURATION. In this case,
    //  the callback should be scheduled to be invoked one-by-one.
    //
    // CASE 2: the timer isn't running.
    //  It means no callback is invoked in recent TIMER_DURATION. Invoke the
    //  callback directly and start a scheduler timer.
    //
    if (m_timer)
    {
        appendJobObj(callback);
    }
    else
    {
        VfxCallback0 temp = callback;

        VFX_OBJ_CREATE(m_timer, VfxTimer, this);
        m_timer->setStartDelay(TIMER_DURATION);
        m_timer->setDuration(TIMER_DURATION);
        m_timer->m_signalTick.connect(this, &VappWidgetMreManager::onScheduleNextJob);
        m_timer->start();

        temp.invoke();
    }
}


void VappWidgetMreManager::cancelJob(const VfxCallback0 &callback)
{
    removeJobObj(callback);
}


void VappWidgetMreManager::appendJobObj(const VfxCallback0 &callback)
{
    if (isJobObjFound(callback))
    {
        return;
    }

    JobObj *job;

    VFX_ALLOC_NEW(job, JobObj, this);
    job->m_callback = callback;

    m_jobList.append(job);
}


void VappWidgetMreManager::removeJobObj(const VfxCallback0 &callback)
{
    for (VfxObjListEntry *entry = m_jobList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        JobObj *job = (JobObj *)entry->get();

        if (job && job->m_callback.equalTo(callback))
        {
            VFX_DELETE(job);
            m_jobList.removePos(entry);
            return;
        }
    }
}


VfxBool VappWidgetMreManager::isJobObjFound(const VfxCallback0 &callback) const
{
    for (VfxObjListEntry *entry = m_jobList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        JobObj *job = (JobObj *)entry->get();

        if (job && job->m_callback.equalTo(callback))
        {
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}


void VappWidgetMreManager::onScheduleNextJob(VfxTimer *timer)
{
    VFX_ASSERT(m_timer == timer);

    VfxObjListEntry *entry = m_jobList.getHead();

    if (!entry)
    {
        VFX_OBJ_CLOSE(m_timer);
    }
    else
    {
        // Callback could call "cancelJob" to delete the job which we are
        // just processing. It is dangerous. So, we backup the callback object
        // and call it in the end of this timer handler.

        VfxCallback0 temp;

        JobObj *job = (JobObj *)entry->get();
        if (job)
        {
            temp = job->m_callback;
            VFX_DELETE(job);
        }

        m_jobList.removePos(entry);

        temp.invoke();
    }
}


void VappWidgetMreManager::handleUninstall(const VfxChar *appName)
{
    //
    // Delete running MRE widgets.
    //
    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidgetMre *widget;

        widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidgetMre);
        VFX_ASSERT(widget);

        if (vfx_sys_strcmp(widget->getId().getStringType(), appName) == 0)
        {
            widget->m_signalDeselect.emit(widget);
        }
    }

    //
    // Update property.
    //
    VappWidgetId mreId(VAPP_WIDGET_SRC_MRE, appName);

    for (VfxS32 i = 0; i < WIDGET_NUM; i++)
    {
        if (m_property[i].isUsed && m_property[i].id == mreId)
        {
            m_property[i].isUsed = VFX_FALSE;
        }
    }

    saveProperty();
}


void VappWidgetMreManager::handleDrivePlugIn(
    const VfxU8 *driveLetter,
    VfxU32 count)
{
    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidgetMre *widget;

        widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidgetMre);
        VFX_ASSERT(widget);

        if (isDriveLetterMatch(widget, driveLetter, count))
        {
            widget->fixingError(VAPP_WIDGET_MRE_ERR_DRIVE_PLUG_OUT);
        }
    }
}


void VappWidgetMreManager::handleDrivePlugOut(
    const VfxU8 *driveLetter,
    VfxU32 count)
{
    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidgetMre *widget;

        widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidgetMre);
        VFX_ASSERT(widget);

        if (isDriveLetterMatch(widget, driveLetter, count))
        {
            widget->notifyError(VAPP_WIDGET_MRE_ERR_DRIVE_PLUG_OUT);
        }
    }
}


void VappWidgetMreManager::handleDriveFormat(VfxU8 driveLetter)
{
    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidgetMre *widget;

        widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidgetMre);
        VFX_ASSERT(widget);

        if (isDriveLetterMatch(widget, &driveLetter, 1))
        {
            widget->m_signalDeselect.emit(widget);
        }
    }
}


void VappWidgetMreManager::handleMassStorageMode(VfxBool isEnter)
{
    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidgetMre *widget;

        widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidgetMre);
        VFX_ASSERT(widget);

        if (isEnter)
        {
            widget->notifyError(VAPP_WIDGET_MRE_ERR_MASS_STORAGE);
        }
        else
        {
            widget->fixingError(VAPP_WIDGET_MRE_ERR_MASS_STORAGE);
        }
    }
}


void VappWidgetMreManager::registerEvent()
{
    mmi_frm_cb_reg_event(
        EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE,
        VappWidgetMreManager::eventProc,
        getObjHandle());

    mmi_frm_cb_reg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN,
        VappWidgetMreManager::eventProc,
        getObjHandle());

    mmi_frm_cb_reg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,
        VappWidgetMreManager::eventProc,
        getObjHandle());

    mmi_frm_cb_reg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT,
        VappWidgetMreManager::eventProc,
        getObjHandle());

#if defined(__MMI_USB_SUPPORT__)
    mmi_frm_cb_reg_event(
        EVT_ID_USB_ENTER_MS_MODE,
        VappWidgetMreManager::eventProc,
        getObjHandle());

    mmi_frm_cb_reg_event(
        EVT_ID_USB_EXIT_MS_MODE,
        VappWidgetMreManager::eventProc,
        getObjHandle());
#endif /* defined(__MMI_USB_SUPPORT__) */

#if defined(CFG_MRE_WIDGET_UNIT_TEST_INTERRUPT)
    mmi_frm_cb_reg_event(
        EVT_ID_PRE_KEY_EVT_ROUTING,
        VappWidgetMreManager::eventProc,
        getObjHandle());
#endif /* defined(CFG_MRE_WIDGET_UNIT_TEST_INTERRUPT) */
}


void VappWidgetMreManager::deregisterEvent()
{
    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE,
        VappWidgetMreManager::eventProc,
        getObjHandle());

    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN,
        VappWidgetMreManager::eventProc,
        getObjHandle());

    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,
        VappWidgetMreManager::eventProc,
        getObjHandle());

    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT,
        VappWidgetMreManager::eventProc,
        getObjHandle());

#if defined(__MMI_USB_SUPPORT__)
    mmi_frm_cb_dereg_event(
        EVT_ID_USB_ENTER_MS_MODE,
        VappWidgetMreManager::eventProc,
        getObjHandle());

    mmi_frm_cb_dereg_event(
        EVT_ID_USB_EXIT_MS_MODE,
        VappWidgetMreManager::eventProc,
        getObjHandle());
#endif /* defined(__MMI_USB_SUPPORT__) */

#if defined(CFG_MRE_WIDGET_UNIT_TEST_INTERRUPT)
    mmi_frm_cb_dereg_event(
        EVT_ID_PRE_KEY_EVT_ROUTING,
        VappWidgetMreManager::eventProc,
        getObjHandle());
#endif /* defined(CFG_MRE_WIDGET_UNIT_TEST_INTERRUPT) */
}


mmi_ret VappWidgetMreManager::eventProc(mmi_event_struct *evt)
{
    VappWidgetMreManager *mgr;

    mgr = (VappWidgetMreManager *)handleToObject((VfxObjHandle)evt->user_data);
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

    #if defined(CFG_MRE_WIDGET_UNIT_TEST_INTERRUPT)
        case EVT_ID_PRE_KEY_EVT_ROUTING:
        {
            mmi_frm_key_evt_struct *p;

            p = (mmi_frm_key_evt_struct *)evt;

            if (p->key_code == KEY_BACK && p->key_type == KEY_EVENT_DOWN)
            {
                mgr->handleMassStorageMode(VFX_TRUE);
            }
            else if (p->key_code == KEY_HOME && p->key_type == KEY_EVENT_DOWN)
            {
                mgr->handleMassStorageMode(VFX_FALSE);
            }

            break;
        }
    #endif /* defined(CFG_MRE_WIDGET_UNIT_TEST_INTERRUPT) */

        default:
        {
            break;
        }
    }

    return MMI_RET_OK;
}


void *VappWidgetMreManager::malloc(VfxS32 size)
{
    if (m_asmGid == GRP_ID_INVALID)
    {
        initMemory();
    }

    // Allow to return a NULL pointer if the memory pool is exhausted.

    return vadpAsmAlloc(m_asmGid, size);
}


void VappWidgetMreManager::free(void *mem)
{
    if (m_asmGid != GRP_ID_INVALID)
    {
        vadpAsmFree(m_asmGid, mem);
    }
}


void VappWidgetMreManager::initMemory()
{
    if (m_asmGid != GRP_ID_INVALID)
    {
        return; // already initialized.
    }

    VadpAsmProperty property;

    m_asmGid = mmi_frm_group_create(
                GRP_ID_ROOT,
                GRP_ID_VAPP_WIDGET_MRE_ASM,
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


void VappWidgetMreManager::deinitMemory()
{
    if (m_asmGid == GRP_ID_INVALID)
    {
        return; // already de-initialized.
    }

    mmi_frm_group_close(m_asmGid);
    m_asmGid = GRP_ID_INVALID;
}


void VappWidgetMreManager::handleAsmFreeReq()
{
    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidgetMre *widget;

        widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidgetMre);
        VFX_ASSERT(widget);

        widget->shutdownVpi();
    }
}


mmi_ret VappWidgetMreManager::onAsmGroupEvent(mmi_event_struct *evt)
{
    VappWidgetMreManager *mgr;

    mgr = (VappWidgetMreManager *)handleToObject((VfxObjHandle)evt->user_data);
    VFX_OBJ_ASSERT_VALID(mgr);

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
            mgr->handleAsmFreeReq();
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


VfxBool VappWidgetMreManager::setProperty(
    const VappWidgetId &id,
    const VfxSize &size)
{
    VfxS32 idx = find(id);
    if (idx < 0)
    {
        return VFX_FALSE;
    }

    m_property[idx].isValid = VFX_TRUE;
    m_property[idx].width   = size.width;
    m_property[idx].height  = size.height;

    saveProperty();

    return VFX_TRUE;
}


VfxBool VappWidgetMreManager::getProperty(const VappWidgetId &id, VfxSize &size)
{
    VfxS32 idx = find(id);

    if (idx < 0 || !m_property[idx].isValid)
    {
        return VFX_FALSE;
    }

    size.width  = m_property[idx].width;
    size.height = m_property[idx].height;

    return VFX_TRUE;
}


void VappWidgetMreManager::initProperty()
{
    if (isPropertyInit)
    {
        return; // already initialized.
    }

    isPropertyInit = VFX_TRUE;

    VfxArchive *ar = createPropertyArchive(
                        VappArchiveNvramSource::SOURCE_MODE_READ,
                        this);
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

    VappWidgetKit *kit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);

    for (VfxS32 i = 0; i < WIDGET_NUM; i++)
    {
        //
        // Decode
        //
        m_property[i].isUsed = (ar->readU8() == 0 ? VFX_FALSE : VFX_TRUE);
        if (!m_property[i].isUsed)
        {
            continue;
        }

        m_property[i].id.decodeFromArchive(ar);
        m_property[i].isValid = (ar->readU8() == 0 ? VFX_FALSE : VFX_TRUE);
        m_property[i].width = ar->readU16();
        m_property[i].height = ar->readU16();

        //
        // Sanity check.
        //
        if (!kit->isIdValid(m_property[i].id))
        {
            m_property[i].isUsed = VFX_FALSE;
        }
    }

    VFX_OBJ_CLOSE(ar);
}


void VappWidgetMreManager::saveProperty()
{
    VfxArchive *ar = createPropertyArchive(
                        VappArchiveNvramSource::SOURCE_MODE_WRITE,
                        this);
    if (!ar)
    {
        return;
    }

    VfxU32 guardPattern = GUARD_PATTERN;
    ar->writeU32(guardPattern);

    VappWidgetKit *kit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);

    for (VfxS32 i = 0; i < WIDGET_NUM; i++)
    {
        //
        // Encode
        //
        ar->writeU8(m_property[i].isUsed ? 0x01 : 0x00);
        if (!m_property[i].isUsed)
        {
            continue;
        }

        m_property[i].id.encodeToArchive(ar);
        ar->writeU8(m_property[i].isValid ? 0x01 : 0x00);
        ar->writeU16(m_property[i].width);
        ar->writeU16(m_property[i].height);
    }

    VFX_OBJ_CLOSE(ar);
}


VfxS32 VappWidgetMreManager::find(const VappWidgetId &id)
{
    VfxS32 freeIdx = -1;

    for (VfxS32 i = 0; i < WIDGET_NUM; i++)
    {
        if (!m_property[i].isUsed)
        {
            if (freeIdx < 0)
            {
                freeIdx = i;
            }

            continue;
        }

        if (m_property[i].id == id)
        {
            return i;
        }
    }

    if (freeIdx >= 0 && freeIdx < WIDGET_NUM)
    {
        m_property[freeIdx].id = id;
        m_property[freeIdx].isUsed = VFX_TRUE;
        m_property[freeIdx].isValid = VFX_FALSE;
    }

    return freeIdx;
}


VfxArchive *VappWidgetMreManager::createArchive(
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


VfxArchive *VappWidgetMreManager::createPropertyArchive(
    VappArchiveNvramSource::SourceModeEnum mode,
    VfxObject *parentObj) const
{
    return createArchive(
            NVRAM_EF_VAPP_WIDGET_MRE_SYS_SETTING_LID,
            1,
            NVRAM_EF_VAPP_WIDGET_MRE_SYS_SETTING_SIZE,
            mode,
            parentObj);
}


VfxBool VappWidgetMreManager::isDriveLetterMatch(
    const VappWidgetMre *widget,
    const VfxU8 *driveLetter,
    VfxU32 count) const
{
    for (VfxU32 i = 0; i < count; i++)
    {
        if (toupper(driveLetter[i]) == toupper(widget->getDriveLetter()))
        {
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}

#endif /* defined(__MMI_VUI_WIDGET_MRE__) */

