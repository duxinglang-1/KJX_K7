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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_screen_lock_base.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the screen lock's base class
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
#include "vapp_screen_lock_base.h"
#include "vapp_screen_lock_setting_provider.h"


/*****************************************************************************
 * Screen Lock Base Class
 *****************************************************************************/

VFX_IMPLEMENT_VIRTUAL_CLASS("VappScreenLock", VappScreenLock, VfxControl);


VappScreenLock::VappScreenLock():
    m_isCreated(VFX_FALSE),
    m_isEntered(VFX_FALSE),
    m_numOfChild(0)
{
    // Do nothing.
}


VappScreenLock::~VappScreenLock()
{
    // Do nothing.
}


void VappScreenLock::onInit()
{
    VfxControl::onInit();

    // Do nothing.
}


void VappScreenLock::onDeinit()
{
    // Do nothing.

    VfxControl::onDeinit();
}


VfxS32 VappScreenLock::getScreenshotNum() const
{
    return 0;
}


VfxFrame **VappScreenLock::createScreenshot(VfxObject *parentObj) const
{
    return NULL;
}


VfxBool VappScreenLock::isConfigurationSupported() const
{
    return onGetConfigurationSupported();
}


void VappScreenLock::createConfiguration()
{
    onCreateConfiguration();
}


VfxBool VappScreenLock::onGetConfigurationSupported() const
{
    return VFX_FALSE;
}


void VappScreenLock::onCreateConfiguration()
{
    // Do nothing.
}


void VappScreenLock::createView()
{
    if (!m_isCreated)
    {
        // Used to check memory leak.
        m_numOfChild = getChildCount();

        // set focus to receive key event
        setFocused(VFX_TRUE);

        //
        // Create this screen lock's specific UI components.
        //
        onCreateView();

        m_isCreated = VFX_TRUE;
    }
}


void VappScreenLock::releaseView()
{
    if (m_isCreated)
    {
        // disable focus when leaving screen lock
        setFocused(VFX_FALSE);

        // Release this widget's specific UI components.
        onReleaseView();

        VfxS32 numOfChild = getChildCount();
        VFX_ASSERT(m_numOfChild == numOfChild);

        m_isCreated = VFX_FALSE;
    }
}


VfxBool VappScreenLock::checkAvailable(VfxWString &errorString)
{
    return VFX_TRUE;
}


void VappScreenLock::onCreateView()
{
    // Do nothing.
}


void VappScreenLock::onReleaseView()
{
    // Do nothing.
}


VfxBool VappScreenLock::getCreateViewFailure(VfxWString &errorString)
{
    return VFX_FALSE;
}


void VappScreenLock::processPageEnter()
{
    if (!m_isEntered)
    {
        onPageEnter();
        m_isEntered = VFX_TRUE;
    }
}


void VappScreenLock::processPageExit()
{
    if (m_isEntered)
    {
        onPageExit();
        m_isEntered = VFX_FALSE;
    }
}


void VappScreenLock::serializeView()
{
    // Serialize & restore mechanism is only feasible when the view is created.
    VFX_ASSERT(m_isCreated);

    if (!m_isSerialized)
    {
        onSerializeView();
        m_isSerialized = VFX_TRUE;
    }
}


void VappScreenLock::restoreView()
{
    // Serialize & restore mechanism is only feasible when the view is created.
    VFX_ASSERT(m_isCreated);

    if (m_isSerialized)
    {
        onRestoreView();
        m_isSerialized = VFX_FALSE;
    }
}


void VappScreenLock::onSerializeView()
{
    // Do nothing.
}


void VappScreenLock::onRestoreView()
{
    // Do nothing.
}


void VappScreenLock::notifyBacklightOff()
{
    onBacklightOff();
}


void VappScreenLock::notifyBacklightOn()
{
    onBacklightOn();
}


void VappScreenLock::onPageEnter()
{
    // Do nothing.
}


void VappScreenLock::onPageExit()
{
    // Do nothing.
}


void VappScreenLock::onBacklightOff()
{
    // Do nothing.
}


void VappScreenLock::onBacklightOn()
{
    // Do nothing.
}


VfxResId VappScreenLock::onGetStatusBarBg()
{
    return NULL;
}


VfxBool VappScreenLock::onGetStatusBarTranslucent()
{
    return VFX_TRUE;
}


VfxBool VappScreenLock::onKeyInput(VfxKeyEvent &event)
{
    //
    // Stop home key routing since it's been handled and keep the rest of key routing.
    //
    if (event.keyCode == VFX_KEY_CODE_HOME) 
    {
        return VFX_TRUE;
    }
    else
    {
        return VfxControl::onKeyInput(event);
    }
}


VfxResId VappScreenLock::getStatusBarBg()
{
    return onGetStatusBarBg();
}


VfxBool VappScreenLock::getStatusBarTranslucent()
{
    return onGetStatusBarTranslucent();
}
#endif /* defined(__MMI_VUI_SCREEN_LOCK_FACTORY__) */

