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
 *  vapp_launcher.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the launcher base class.
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

#if defined(__MMI_VUI_LAUNCHER_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_launcher.h"
#include "vapp_launcher_setting_provider.h"

extern "C"
{
#include "lcd_sw_inc.h"
}


/*****************************************************************************
 * Launcher Base Class
 *****************************************************************************/

VFX_IMPLEMENT_VIRTUAL_CLASS(
    "VappLauncher",
    VappLauncher,
    VfxControl);


VappLauncher::VappLauncher() :
    m_isFirstInit(VFX_FALSE),
    m_isCreated(VFX_FALSE),
    m_isEntered(VFX_FALSE),
    m_isRestoreStatus(VFX_FALSE),
    m_isProcessHomeKey(VFX_FALSE),
    m_isSerialized(VFX_FALSE),
    m_numOfChild(0),
    m_archiveSource(NULL)
{
    // Do nothing.
}


VappLauncher::~VappLauncher()
{
    // Do nothing.
}


void VappLauncher::onInit()
{
    VfxControl::onInit();

    setSize(LCD_WIDTH, LCD_HEIGHT);
}


void VappLauncher::onDeinit()
{
    // Fail-safe. If the view isn't released, release it automatically.
    if (isCreated())
    {
        releaseView();
    }

    VfxControl::onDeinit();
}


VfxS32 VappLauncher::getScreenshotNum() const
{
    return 0;
}


VfxFrame **VappLauncher::createScreenshot(VfxObject *parentObj) const
{
    return NULL;
}


VfxBool VappLauncher::isConfigurationSupported() const
{
    return onGetConfigurationSupported();
}


void VappLauncher::createConfiguration()
{
    onCreateConfiguration();
}


VfxBool VappLauncher::onGetConfigurationSupported() const
{
    return VFX_FALSE;
}


void VappLauncher::onCreateConfiguration()
{
    // Do nothing.
}


VfxBool VappLauncher::checkAvailable(VfxWString &errorString)
{
    return VFX_TRUE;
}


void VappLauncher::onCreateView()
{
    // Do nothing.
}


void VappLauncher::onReleaseView()
{
    // Do nothing.
}


VfxBool VappLauncher::getCreateViewFailure(VfxWString &errorString)
{
    return VFX_FALSE;
}


void VappLauncher::onEnter()
{
    // Do nothing.
}


void VappLauncher::onEntered()
{
    // Do nothing.
}


void VappLauncher::onExit()
{
    // Do nothing.
}


void VappLauncher::onSerializeView(VfxArchive *ar)
{
    VFX_UNUSED(ar);

    // Do nothing.
}


void VappLauncher::onRestoreView(VfxArchive *ar)
{
    VFX_UNUSED(ar);

    // Do nothing.
}


VfxResId VappLauncher::onGetStatusBarBg()
{
    return VFX_RES_ID_NULL;
}


VfxBool VappLauncher::onGetStatusBarTranslucent()
{
    return VFX_TRUE;
}


void VappLauncher::onWallpaperChanged()
{
    // Do nothing.
}


void VappLauncher::onNotificationCenterEnter()
{
    // Do nothing.
}


void VappLauncher::onNotificationCenterExited()
{
    // Do nothing.
}


void VappLauncher::createView()
{
    if (!m_isCreated)
    {
        // Used to check memory leak.
        m_numOfChild = getChildCount();

        // Set focus to receive key events.
        setFocused(VFX_TRUE);

        onCreateView();

        m_isCreated = VFX_TRUE;
    }
}


void VappLauncher::releaseView()
{
    if (m_isCreated)
    {
        // If the serialized memory archive source is present, close it.
        VFX_OBJ_CLOSE(m_archiveSource);
        m_isSerialized = VFX_FALSE;

        // Release this launcher's view.
        onReleaseView();

        VfxS32 numOfChild = getChildCount();
        VFX_ASSERT(m_numOfChild == numOfChild);

        m_isCreated = VFX_FALSE;
    }
}


void VappLauncher::enter()
{
    if (!m_isEntered)
    {
        onEnter();
        m_isEntered = VFX_TRUE;
    }
}


void VappLauncher::entered()
{
    if (m_isEntered)
    {
        onEntered();
    }
}


void VappLauncher::exit()
{
    if (m_isEntered)
    {
        onExit();
        m_isEntered = VFX_FALSE;
    }
}


void VappLauncher::serializeView()
{
    // Serialize & restore mechanism is only feasible when the view is created.
    VFX_ASSERT(m_isCreated);

    if (!m_isSerialized)
    {
        VfxArchive *archive;

        VFX_ASSERT(!m_archiveSource);
        VFX_OBJ_CREATE(m_archiveSource, VfxMemArchiveSource, this);

        VFX_OBJ_CREATE(archive, VfxArchive, this);

        archive->setSource(m_archiveSource);

        onSerializeView(archive);

        VFX_OBJ_CLOSE(archive);

        m_isSerialized = VFX_TRUE;
    }
}


void VappLauncher::restoreView()
{
    // Serialize & restore mechanism is only feasible when the view is created.
    VFX_ASSERT(m_isCreated);

    if (m_isSerialized)
    {
        VfxArchive *archive;
        VfxU8 *buf;
        VfxU32 size;

        VFX_ASSERT(m_archiveSource);

        // TODO:
        //
        // Archive source shall support to switch from write mode to read mode
        // directly.
        m_archiveSource->detachBuffer(&buf, &size);
        if (buf)
        {
            m_archiveSource->attachBuffer(buf, size);
        }

        VFX_OBJ_CREATE(archive, VfxArchive, this);

        archive->setSource(m_archiveSource);

        onRestoreView(archive);

        VFX_OBJ_CLOSE(archive);
        VFX_OBJ_CLOSE(m_archiveSource);

        m_isSerialized = VFX_FALSE;
    }
}


VfxResId VappLauncher::getStatusBarBg()
{
    return onGetStatusBarBg();
}


VfxBool VappLauncher::getStatusBarTranslucent()
{
    return onGetStatusBarTranslucent();
}


void VappLauncher::notifyWallpaperChanged()
{
    onWallpaperChanged();
}


void VappLauncher::notifyNotificationCenterEnter()
{
    onNotificationCenterEnter();
}


void VappLauncher::notifyNotificationCenterExited()
{
    onNotificationCenterExited();
}


void VappLauncher::setFirstInit(VfxBool isFirstInit)
{
    m_isFirstInit = isFirstInit;
}


void VappLauncher::setIsRestoreStatus(VfxBool isRestoreStatus)
{
    m_isRestoreStatus = isRestoreStatus;
}


void VappLauncher::setIsProcessHomeKey(VfxBool isProcessHomeKey)
{
    m_isProcessHomeKey = isProcessHomeKey;
}
#endif /* defined(__MMI_VUI_LAUNCHER_FACTORY__) */

